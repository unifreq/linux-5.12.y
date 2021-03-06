// SPDX-License-Identifier: GPL-2.0-only
/*
 * OF helpers for network devices.
 *
 * Initially copied out of arch/powerpc/kernel/prom_parse.c
 */
#include <linux/etherdevice.h>
#include <linux/kernel.h>
#include <linux/of_net.h>
#include <linux/of_platform.h>
#include <linux/phy.h>
#include <linux/export.h>
#include <linux/device.h>
#include <linux/mtd/mtd.h>

/**
 * of_get_phy_mode - Get phy mode for given device_node
 * @np:	Pointer to the given device_node
 * @interface: Pointer to the result
 *
 * The function gets phy interface string from property 'phy-mode' or
 * 'phy-connection-type'. The index in phy_modes table is set in
 * interface and 0 returned. In case of error interface is set to
 * PHY_INTERFACE_MODE_NA and an errno is returned, e.g. -ENODEV.
 */
int of_get_phy_mode(struct device_node *np, phy_interface_t *interface)
{
	const char *pm;
	int err, i;

	*interface = PHY_INTERFACE_MODE_NA;

	err = of_property_read_string(np, "phy-mode", &pm);
	if (err < 0)
		err = of_property_read_string(np, "phy-connection-type", &pm);
	if (err < 0)
		return err;

	for (i = 0; i < PHY_INTERFACE_MODE_MAX; i++)
		if (!strcasecmp(pm, phy_modes(i))) {
			*interface = i;
			return 0;
		}

	return -ENODEV;
}
EXPORT_SYMBOL_GPL(of_get_phy_mode);

static void *of_get_mac_addr(struct device_node *np, const char *name)
{
	struct property *pp = of_find_property(np, name, NULL);

	if (pp && pp->length == ETH_ALEN && is_valid_ether_addr(pp->value))
		return pp->value;
	return NULL;
}

static void *of_get_mac_addr_nvmem(struct device_node *np, int *err)
{
	int ret;
	void *mac;
	u8 nvmem_mac[ETH_ALEN];
	struct platform_device *pdev = of_find_device_by_node(np);

	if (!pdev) {
		*err = -ENODEV;
		return NULL;
	}

	ret = nvmem_get_mac_address(&pdev->dev, &nvmem_mac);
	if (ret) {
		put_device(&pdev->dev);
		*err = ret;
		return NULL;
	}

	mac = devm_kmemdup(&pdev->dev, nvmem_mac, ETH_ALEN, GFP_KERNEL);
	put_device(&pdev->dev);
	if (!mac) {
		*err = -ENOMEM;
		return NULL;
	}

	return mac;
}

static void *of_get_mac_address_mtd(struct device_node *np)
{
#ifdef CONFIG_MTD
	struct device_node *mtd_np = NULL;
	struct property *prop;
	size_t retlen;
	int size, ret;
	struct mtd_info *mtd;
	const char *part;
	const __be32 *list;
	phandle phandle;
	u8 mac[ETH_ALEN];
	void *addr;

	list = of_get_property(np, "mtd-mac-address", &size);
	if (!list || (size != (2 * sizeof(*list))))
		return NULL;

	phandle = be32_to_cpup(list++);
	if (phandle)
		mtd_np = of_find_node_by_phandle(phandle);

	if (!mtd_np)
		return NULL;

	part = of_get_property(mtd_np, "label", NULL);
	if (!part)
		part = mtd_np->name;

	mtd = get_mtd_device_nm(part);
	if (IS_ERR(mtd))
		return NULL;

	ret = mtd_read(mtd, be32_to_cpup(list), 6, &retlen, mac);
	put_mtd_device(mtd);

	if (!is_valid_ether_addr(mac))
		return NULL;

	addr = of_get_mac_addr(np, "mac-address");
	if (addr) {
		memcpy(addr, mac, ETH_ALEN);
		return addr;
	}

	prop = kzalloc(sizeof(*prop), GFP_KERNEL);
	if (!prop)
		return NULL;

	prop->name = "mac-address";
	prop->length = ETH_ALEN;
	prop->value = kmemdup(mac, ETH_ALEN, GFP_KERNEL);
	if (!prop->value || of_add_property(np, prop))
		goto free;

	return prop->value;
free:
	kfree(prop->value);
	kfree(prop);
#endif
	return NULL;
}


/**
 * Search the device tree for the best MAC address to use.  'mac-address' is
 * checked first, because that is supposed to contain to "most recent" MAC
 * address. If that isn't set, then 'local-mac-address' is checked next,
 * because that is the default address. If that isn't set, then the obsolete
 * 'address' is checked, just in case we're using an old device tree. If any
 * of the above isn't set, then try to get MAC address from nvmem cell named
 * 'mac-address'.
 *
 * Note that the 'address' property is supposed to contain a virtual address of
 * the register set, but some DTS files have redefined that property to be the
 * MAC address.
 *
 * All-zero MAC addresses are rejected, because those could be properties that
 * exist in the device tree, but were not set by U-Boot.  For example, the
 * DTS could define 'mac-address' and 'local-mac-address', with zero MAC
 * addresses.  Some older U-Boots only initialized 'local-mac-address'.  In
 * this case, the real MAC is in 'local-mac-address', and 'mac-address' exists
 * but is all zeros.
 *
 *
 * If a mtd-mac-address property exists, try to fetch the MAC address from the
 * specified mtd device, and store it as a 'mac-address' property
 *
 * DT can tell the system to increment the mac-address after is extracted by
 * using:
 * - mac-address-increment-byte to decide what byte to increase
 *   (if not defined is increased the last byte)
 * - mac-address-increment to decide how much to increase. The value will
 *   not overflow to other bytes if the increment is over 255.
 *   (example 00:01:02:03:04:ff + 1 == 00:01:02:03:04:00)
 *
 * Return: Will be a valid pointer on success and ERR_PTR in case of error.
*/
const void *of_get_mac_address(struct device_node *np)
{
	u32 inc_idx, mac_inc;
	int ret = 0;
	u8 *addr;

	/* Check first if the increment byte is present and valid.
	 * If not set assume to increment the last byte if found.
	 */
	if (of_property_read_u32(np, "mac-address-increment-byte", &inc_idx))
		inc_idx = 5;
	if (inc_idx < 3 || inc_idx > 5)
		return ERR_PTR(-EINVAL);

	addr = of_get_mac_addr(np, "mac-address");
	if (addr)
		goto found;

	addr = of_get_mac_addr(np, "local-mac-address");
	if (addr)
		goto found;

	addr = of_get_mac_addr(np, "address");
	if (addr)
		goto found;

	addr = of_get_mac_address_mtd(np);
	if (addr)
		goto found;

	addr = of_get_mac_addr_nvmem(np, &ret);
	if (ret)
		return ERR_PTR(ret);

found:
	if (!of_property_read_u32(np, "mac-address-increment", &mac_inc))
		addr[inc_idx] += mac_inc;

	return addr;
}
EXPORT_SYMBOL(of_get_mac_address);
