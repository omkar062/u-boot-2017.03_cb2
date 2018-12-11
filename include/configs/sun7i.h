/*
 * (C) Copyright 2012-2013 Henrik Nordstrom <henrik@henriknordstrom.net>
 * (C) Copyright 2013 Luke Kenneth Casson Leighton <lkcl@lkcl.net>
 *
 * Configuration settings for the Allwinner A20 (sun7i) CPU
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * A20 specific configuration
 */

#ifdef CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_SUNXI
#endif

#define CONFIG_SUNXI_USB_PHYS	3

#define CONFIG_ARMV7_SECURE_BASE	SUNXI_SRAM_B_BASE
#define CONFIG_ARMV7_SECURE_MAX_SIZE	(64 * 1024) /* 64 KB */

/*
 * Include common sunxi configuration where most the settings are
 */
#include <configs/sunxi-common.h>

#define CONFIG_MACH_TYPE	(4283 | ((CONFIG_MACH_TYPE_COMPAT_REV) << 28))
#ifdef CONFIG_NAND_SUNXI
#define CONFIG_MTD
#define CONFIG_CMD_NAND
#define CONFIG_MTD_DEVICE
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_PARTITIONS
#define MTDIDS_DEFAULT		"nand0=sun7i_nand.0"
#define MTDPARTS_DEFAULT                "mtdparts=sun7i_nand.0:" \
					"2048k(SPL)," \
					"2m(UBOOT)," \
					"2m(UBOOT_ENV)," \
					"2m(DTB)," \
					"10m(KERNEL)," \
					"1g(ROOTFS)," \
					"-(NAND.reserved)"
#if 0
//#define CONFIG_LZO
//#define CONFIG_RBTREE
//#define CONFIG_CMD_UBIFS
#endif
#endif
#endif /* __CONFIG_H */
