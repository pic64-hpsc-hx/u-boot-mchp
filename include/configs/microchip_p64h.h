/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2025 Microchip Technology Inc.
 * Romain Caritey <romain.caritey@microchip.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define RISCV_MMODE_TIMERBASE		0x2000000
#define RISCV_MMODE_TIMEROFF		0xbff8
#define RISCV_MMODE_TIMER_FREQ		1000000
#define RISCV_SMODE_TIMER_FREQ		1000000

#define __io

#define CFG_SYS_BAUDRATE_TABLE  \
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, \
		230400, 460800, 921600 }

#endif /* __CONFIG_H */
