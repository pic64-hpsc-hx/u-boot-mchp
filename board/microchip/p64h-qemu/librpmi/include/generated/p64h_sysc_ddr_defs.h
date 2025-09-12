/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef P64H_SYSC_DEF_DDR
#define P64H_SYSC_DEF_DDR

/* Public Defines ------------------------------------------ */

/* Public Structs and Enums -------------------------------- */
/**
 * @brief P64H DDR part type
 *
 */
typedef enum  {
    P64H_SYSC_DDR_PART_HWEMU_MODEL           = 0x0,   ///< HW Emulation model
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E     = 0x1,   ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 1.6 GHz 13.75 ns 96-FBGA (7.5x13)
    P64H_SYSC_DDR_PART_LAST
} p64h_sysc_ddr_part_t;

/* Public Methods ------------------------------------------ */
char* p64h_sysc_ddr_part_name_get(p64h_sysc_ddr_part_t ddr_part);
char* p64h_sysc_ddr_part_desc_get(p64h_sysc_ddr_part_t ddr_part);

#endif /* P64H_SYSC_DEF_DDR */