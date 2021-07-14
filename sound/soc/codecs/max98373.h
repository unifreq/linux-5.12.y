/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2017 Maxim Integrated */

#ifndef _MAX98373_H
#define _MAX98373_H

#define MAX98373_R2000_SW_RESET 0x2000
#define MAX98373_R2001_INT_RAW1 0x2001
#define MAX98373_R2002_INT_RAW2 0x2002
#define MAX98373_R2003_INT_RAW3 0x2003
#define MAX98373_R2004_INT_STATE1 0x2004
#define MAX98373_R2005_INT_STATE2 0x2005
#define MAX98373_R2006_INT_STATE3 0x2006
#define MAX98373_R2007_INT_FLAG1 0x2007
#define MAX98373_R2008_INT_FLAG2 0x2008
#define MAX98373_R2009_INT_FLAG3 0x2009
#define MAX98373_R200A_INT_EN1 0x200A
#define MAX98373_R200B_INT_EN2 0x200B
#define MAX98373_R200C_INT_EN3 0x200C
#define MAX98373_R200D_INT_FLAG_CLR1 0x200D
#define MAX98373_R200E_INT_FLAG_CLR2 0x200E
#define MAX98373_R200F_INT_FLAG_CLR3 0x200F
#define MAX98373_R2010_IRQ_CTRL 0x2010
#define MAX98373_R2014_THERM_WARN_THRESH 0x2014
#define MAX98373_R2015_THERM_SHDN_THRESH 0x2015
#define MAX98373_R2016_THERM_HYSTERESIS 0x2016
#define MAX98373_R2017_THERM_FOLDBACK_SET 0x2017
#define MAX98373_R2018_THERM_FOLDBACK_EN 0x2018
#define MAX98373_R201E_PIN_DRIVE_STRENGTH 0x201E
#define MAX98373_R2020_PCM_TX_HIZ_EN_1 0x2020
#define MAX98373_R2021_PCM_TX_HIZ_EN_2 0x2021
#define MAX98373_R2022_PCM_TX_SRC_1 0x2022
#define MAX98373_R2023_PCM_TX_SRC_2 0x2023
#define MAX98373_R2024_PCM_DATA_FMT_CFG	0x2024
#define MAX98373_R2025_AUDIO_IF_MODE 0x2025
#define MAX98373_R2026_PCM_CLOCK_RATIO 0x2026
#define MAX98373_R2027_PCM_SR_SETUP_1 0x2027
#define MAX98373_R2028_PCM_SR_SETUP_2 0x2028
#define MAX98373_R2029_PCM_TO_SPK_MONO_MIX_1 0x2029
#define MAX98373_R202A_PCM_TO_SPK_MONO_MIX_2 0x202A
#define MAX98373_R202B_PCM_RX_EN 0x202B
#define MAX98373_R202C_PCM_TX_EN 0x202C
#define MAX98373_R202E_ICC_RX_CH_EN_1 0x202E
#define MAX98373_R202F_ICC_RX_CH_EN_2 0x202F
#define MAX98373_R2030_ICC_TX_HIZ_EN_1 0x2030
#define MAX98373_R2031_ICC_TX_HIZ_EN_2 0x2031
#define MAX98373_R2032_ICC_LINK_EN_CFG 0x2032
#define MAX98373_R2034_ICC_TX_CNTL 0x2034
#define MAX98373_R2035_ICC_TX_EN 0x2035
#define MAX98373_R2036_SOUNDWIRE_CTRL 0x2036
#define MAX98373_R203D_AMP_DIG_VOL_CTRL 0x203D
#define MAX98373_R203E_AMP_PATH_GAIN 0x203E
#define MAX98373_R203F_AMP_DSP_CFG 0x203F
#define MAX98373_R2040_TONE_GEN_CFG 0x2040
#define MAX98373_R2041_AMP_CFG 0x2041
#define MAX98373_R2042_AMP_EDGE_RATE_CFG 0x2042
#define MAX98373_R2043_AMP_EN 0x2043
#define MAX98373_R2046_IV_SENSE_ADC_DSP_CFG 0x2046
#define MAX98373_R2047_IV_SENSE_ADC_EN 0x2047
#define MAX98373_R2051_MEAS_ADC_SAMPLING_RATE 0x2051
#define MAX98373_R2052_MEAS_ADC_PVDD_FLT_CFG 0x2052
#define MAX98373_R2053_MEAS_ADC_THERM_FLT_CFG 0x2053
#define MAX98373_R2054_MEAS_ADC_PVDD_CH_READBACK 0x2054
#define MAX98373_R2055_MEAS_ADC_THERM_CH_READBACK 0x2055
#define MAX98373_R2056_MEAS_ADC_PVDD_CH_EN 0x2056
#define MAX98373_R2090_BDE_LVL_HOLD 0x2090
#define MAX98373_R2091_BDE_GAIN_ATK_REL_RATE 0x2091
#define MAX98373_R2092_BDE_CLIPPER_MODE 0x2092
#define MAX98373_R2097_BDE_L1_THRESH 0x2097
#define MAX98373_R2098_BDE_L2_THRESH 0x2098
#define MAX98373_R2099_BDE_L3_THRESH 0x2099
#define MAX98373_R209A_BDE_L4_THRESH 0x209A
#define MAX98373_R209B_BDE_THRESH_HYST 0x209B
#define MAX98373_R20A8_BDE_L1_CFG_1 0x20A8
#define MAX98373_R20A9_BDE_L1_CFG_2 0x20A9
#define MAX98373_R20AA_BDE_L1_CFG_3 0x20AA
#define MAX98373_R20AB_BDE_L2_CFG_1 0x20AB
#define MAX98373_R20AC_BDE_L2_CFG_2 0x20AC
#define MAX98373_R20AD_BDE_L2_CFG_3 0x20AD
#define MAX98373_R20AE_BDE_L3_CFG_1 0x20AE
#define MAX98373_R20AF_BDE_L3_CFG_2 0x20AF
#define MAX98373_R20B0_BDE_L3_CFG_3 0x20B0
#define MAX98373_R20B1_BDE_L4_CFG_1 0x20B1
#define MAX98373_R20B2_BDE_L4_CFG_2 0x20B2
#define MAX98373_R20B3_BDE_L4_CFG_3 0x20B3
#define MAX98373_R20B4_BDE_INFINITE_HOLD_RELEASE 0x20B4
#define MAX98373_R20B5_BDE_EN 0x20B5
#define MAX98373_R20B6_BDE_CUR_STATE_READBACK 0x20B6
#define MAX98373_R20D1_DHT_CFG 0x20D1
#define MAX98373_R20D2_DHT_ATTACK_CFG 0x20D2
#define MAX98373_R20D3_DHT_RELEASE_CFG 0x20D3
#define MAX98373_R20D4_DHT_EN 0x20D4
#define MAX98373_R20E0_LIMITER_THRESH_CFG 0x20E0
#define MAX98373_R20E1_LIMITER_ATK_REL_RATES 0x20E1
#define MAX98373_R20E2_LIMITER_EN 0x20E2
#define MAX98373_R20FE_DEVICE_AUTO_RESTART_CFG 0x20FE
#define MAX98373_R20FF_GLOBAL_SHDN 0x20FF
#define MAX98373_R21FF_REV_ID 0x21FF

/* MAX98373_R2022_PCM_TX_SRC_1 */
#define MAX98373_PCM_TX_CH_SRC_A_V_SHIFT (0)
#define MAX98373_PCM_TX_CH_SRC_A_I_SHIFT (4)

/* MAX98373_R2024_PCM_DATA_FMT_CFG */
#define MAX98373_PCM_MODE_CFG_FORMAT_MASK (0x7 << 3)
#define MAX98373_PCM_MODE_CFG_FORMAT_SHIFT (3)
#define MAX98373_PCM_TX_CH_INTERLEAVE_MASK (0x1 << 2)
#define MAX98373_PCM_FORMAT_I2S (0x0 << 0)
#define MAX98373_PCM_FORMAT_LJ (0x1 << 0)
#define MAX98373_PCM_FORMAT_TDM_MODE0 (0x3 << 0)
#define MAX98373_PCM_FORMAT_TDM_MODE1 (0x4 << 0)
#define MAX98373_PCM_FORMAT_TDM_MODE2 (0x5 << 0)
#define MAX98373_PCM_MODE_CFG_CHANSZ_MASK (0x3 << 6)
#define MAX98373_PCM_MODE_CFG_CHANSZ_16 (0x1 << 6)
#define MAX98373_PCM_MODE_CFG_CHANSZ_24 (0x2 << 6)
#define MAX98373_PCM_MODE_CFG_CHANSZ_32 (0x3 << 6)

/* MAX98373_R2026_PCM_CLOCK_RATIO */
#define MAX98373_PCM_MODE_CFG_PCM_BCLKEDGE (0x1 << 4)
#define MAX98373_PCM_CLK_SETUP_BSEL_MASK (0xF << 0)

/* MAX98373_R2027_PCM_SR_SETUP_1 */
#define MAX98373_PCM_SR_SET1_SR_MASK (0xF << 0)
#define MAX98373_PCM_SR_SET1_SR_8000 (0x0 << 0)
#define MAX98373_PCM_SR_SET1_SR_11025 (0x1 << 0)
#define MAX98373_PCM_SR_SET1_SR_12000 (0x2 << 0)
#define MAX98373_PCM_SR_SET1_SR_16000 (0x3 << 0)
#define MAX98373_PCM_SR_SET1_SR_22050 (0x4 << 0)
#define MAX98373_PCM_SR_SET1_SR_24000 (0x5 << 0)
#define MAX98373_PCM_SR_SET1_SR_32000 (0x6 << 0)
#define MAX98373_PCM_SR_SET1_SR_44100 (0x7 << 0)
#define MAX98373_PCM_SR_SET1_SR_48000 (0x8 << 0)
#define MAX98373_PCM_SR_SET1_SR_88200 (0x9 << 0)
#define MAX98373_PCM_SR_SET1_SR_96000 (0xA << 0)

/* MAX98373_R2028_PCM_SR_SETUP_2 */
#define MAX98373_PCM_SR_SET2_SR_MASK (0xF << 4)
#define MAX98373_PCM_SR_SET2_SR_SHIFT (4)
#define MAX98373_PCM_SR_SET2_IVADC_SR_MASK (0xF << 0)

/* MAX98373_R2029_PCM_TO_SPK_MONO_MIX_1 */
#define MAX98373_PCM_TO_SPK_MONOMIX_CFG_MASK (0x3 << 6)
#define MAX98373_PCM_TO_SPK_MONOMIX_CFG_SHIFT (6)
#define MAX98373_PCM_TO_SPK_CH0_SRC_MASK (0xF << 0)

/* MAX98373_R203E_AMP_PATH_GAIN */
#define MAX98373_SPK_DIGI_GAIN_MASK (0xF << 4)
#define MAX98373_SPK_DIGI_GAIN_SHIFT (4)
#define MAX98373_FS_GAIN_MAX_MASK (0xF << 0)
#define MAX98373_FS_GAIN_MAX_SHIFT (0)

/* MAX98373_R203F_AMP_DSP_CFG */
#define MAX98373_AMP_DSP_CFG_DCBLK_SHIFT (0)
#define MAX98373_AMP_DSP_CFG_DITH_SHIFT (1)
#define MAX98373_AMP_DSP_CFG_RMP_UP_SHIFT (2)
#define MAX98373_AMP_DSP_CFG_RMP_DN_SHIFT (3)
#define MAX98373_AMP_DSP_CFG_DAC_INV_SHIFT (5)
#define MAX98373_AMP_VOL_SEL_SHIFT (7)

/* MAX98373_R2043_AMP_EN */
#define MAX98373_SPKFB_EN_MASK (0x1 << 1)
#define MAX98373_SPK_EN_MASK (0x1 << 0)
#define MAX98373_SPKFB_EN_SHIFT (1)

/*MAX98373_R2052_MEAS_ADC_PVDD_FLT_CFG */
#define MAX98373_FLT_EN_SHIFT (4)

/* MAX98373_R20B2_BDE_L4_CFG_2 */
#define MAX98373_LVL4_MUTE_EN_SHIFT (7)
#define MAX98373_LVL4_HOLD_EN_SHIFT (6)

/* MAX98373_R20B5_BDE_EN */
#define MAX98373_BDE_EN_SHIFT (0)

/* MAX98373_R20D1_DHT_CFG */
#define MAX98373_DHT_SPK_GAIN_MIN_SHIFT	(4)
#define MAX98373_DHT_ROT_PNT_SHIFT	(0)

/* MAX98373_R20D2_DHT_ATTACK_CFG */
#define MAX98373_DHT_ATTACK_STEP_SHIFT (3)
#define MAX98373_DHT_ATTACK_RATE_SHIFT (0)

/* MAX98373_R20D3_DHT_RELEASE_CFG */
#define MAX98373_DHT_RELEASE_STEP_SHIFT (3)
#define MAX98373_DHT_RELEASE_RATE_SHIFT (0)

/* MAX98373_R20D4_DHT_EN */
#define MAX98373_DHT_EN_SHIFT (0)

/* MAX98373_R20E0_LIMITER_THRESH_CFG */
#define MAX98373_LIMITER_THRESH_SHIFT (2)
#define MAX98373_LIMITER_THRESH_SRC_SHIFT (0)

/* MAX98373_R20E2_LIMITER_EN */
#define MAX98373_LIMITER_EN_SHIFT (0)

/* MAX98373_R20FE_DEVICE_AUTO_RESTART_CFG */
#define MAX98373_CLOCK_MON_SHIFT (0)

/* MAX98373_R20FF_GLOBAL_SHDN */
#define MAX98373_GLOBAL_EN_MASK (0x1 << 0)

/* MAX98373_R2000_SW_RESET */
#define MAX98373_SOFT_RESET (0x1 << 0)

struct max98373_cache {
	u32 reg;
	u32 val;
};

struct max98373_priv {
	struct regmap *regmap;
	int reset_gpio;
	unsigned int v_slot;
	unsigned int i_slot;
	unsigned int spkfb_slot;
	bool interleave_mode;
	unsigned int ch_size;
	bool tdm_mode;
	/* cache for reading a valid fake feedback value */
	struct max98373_cache *cache;
	int cache_num;
	/* variables to support soundwire */
	struct sdw_slave *slave;
	bool hw_init;
	bool first_hw_init;
	int slot;
	unsigned int rx_mask;
};

extern const struct snd_soc_component_driver soc_codec_dev_max98373;
extern const struct snd_soc_component_driver soc_codec_dev_max98373_sdw;

void max98373_reset(struct max98373_priv *max98373, struct device *dev);
void max98373_slot_config(struct device *dev,
			  struct max98373_priv *max98373);
#endif
