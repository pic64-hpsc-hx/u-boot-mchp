/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * memory locations used by linker script and in C code.
 * This is the memory map of the SYSC processor.
 * 
 * this file must only be #define's otherwise it will confuse the linker script.
 * 
 * ALSO, the file must have only C style comments C++ // comments also confuse the linker.
 */
#ifndef SYSC_MEM_H
#define SYSC_MEM_H

/* SysC doesn't have jtag, however this is added for testing jtag mbox in QEMU */
#define SYSC_MEM_JTAG_MBOX_START_QEMU 0xF0009000UL

/** SecC System mbox RAM + register space as viewed from system controller */
#define SYSC_MEM_SEC_MBOX_START        0x40800000UL

/** SecC JTAG mbox RAM + register space as viewed from system controller */
#define SYSC_MEM_SEC_JTAG_MBOX_START   0x40900000UL

/* location of OCR memory as viewed from the system controller */
#define SYSC_MEM_OCR_MEMORY_START 0x80400000UL

/* location of rtems dtb as viewed from the system controller */
#define SYSC_MEM_OCR_RTEMS_DTB_LOCATION 0x805FC000UL

#endif /* SYSC_MEM_H */
