/*
 * Copyright (C) 2013 Gabor Juhos <juhosg@openwrt.org>
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef _MALTA_CONFIG_H
#define _MALTA_CONFIG_H

#include <asm/addrspace.h>
#include <asm/malta.h>

/*
 * System configuration
 */
#define CONFIG_MALTA

#define CONFIG_MEMSIZE_IN_BYTES

#define CONFIG_PCI
#define CONFIG_PCI_GT64120
#define CONFIG_PCI_MSC01
#define CONFIG_PCI_PNP
#define CONFIG_PCNET
#define CONFIG_PCNET_79C973
#define PCNET_HAS_PROM

#define CONFIG_MISC_INIT_R
#define CONFIG_RTC_MC146818
#define CONFIG_SYS_ISA_IO_BASE_ADDRESS	0

/*
 * CPU Configuration
 */
#define CONFIG_SYS_MHZ			250	/* arbitrary value */
#define CONFIG_SYS_MIPS_TIMER_FREQ	(CONFIG_SYS_MHZ * 1000000)

#define CONFIG_SWAP_IO_SPACE

/*
 * Memory map
 */
#define CONFIG_SYS_TEXT_BASE		0xbe000000 /* Rom version */
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE

#define CONFIG_SYS_SDRAM_BASE		0x80000000 /* Cached addr */
#define CONFIG_SYS_MEM_SIZE		(256 * 1024 * 1024)

#define CONFIG_SYS_INIT_SP_OFFSET	0x400000

#define CONFIG_SYS_LOAD_ADDR		0x81000000
#define CONFIG_SYS_MEMTEST_START	0x80100000
#define CONFIG_SYS_MEMTEST_END		0x80800000

#define CONFIG_SYS_MALLOC_LEN		(128 * 1024)
#define CONFIG_SYS_BOOTPARAMS_LEN	(128 * 1024)

/*
 * Console configuration
 */
#if defined(CONFIG_SYS_LITTLE_ENDIAN)
#define CONFIG_SYS_PROMPT		"maltael # "
#else
#define CONFIG_SYS_PROMPT		"malta # "
#endif

#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					 sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16

#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING

/*
 * Serial driver
 */
#define CONFIG_BAUDRATE			115200

#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	1
#define CONFIG_SYS_NS16550_CLK		115200
#define CONFIG_SYS_NS16550_COM1		CKSEG1ADDR(MALTA_GT_UART0_BASE)
#define CONFIG_SYS_NS16550_COM2		CKSEG1ADDR(MALTA_MSC01_UART0_BASE)
#define CONFIG_CONS_INDEX		1

/*
 * Flash configuration
 */
#define CONFIG_SYS_FLASH_BASE		(KSEG1 | MALTA_FLASH_BASE)
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_MAX_FLASH_SECT	128
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE

/*
 * Environment
 */
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_SECT_SIZE		0x20000
#define CONFIG_ENV_SIZE			CONFIG_ENV_SECT_SIZE
#define CONFIG_ENV_ADDR \
	(CONFIG_SYS_FLASH_BASE + (4 << 20) - CONFIG_ENV_SIZE)

/*
 * Commands
 */
#include <config_cmd_default.h>

#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_LOADB
#undef CONFIG_CMD_LOADS
#undef CONFIG_CMD_NFS

#define CONFIG_CMD_DATE
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PCI
#define CONFIG_CMD_PING

#define CONFIG_SYS_LONGHELP		/* verbose help, undef to save memory */

#endif /* _MALTA_CONFIG_H */
