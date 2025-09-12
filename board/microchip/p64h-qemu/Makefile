# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2025 Microchip Technology Inc.
# Romain Caritey <romain.caritey@microchip.com>
#

obj-y	+= p64h-board.o
obj-y   += p64h-cmd-fwu.o
obj-y   += librpmi/
obj-y   += librpmi-env/

ccflags-y += -I$(srctree)/board/microchip/p64h-qemu/include
ccflags-y += -I$(srctree)/board/microchip/p64h-qemu/librpmi/include