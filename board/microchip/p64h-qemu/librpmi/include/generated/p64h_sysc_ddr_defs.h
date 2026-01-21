/* (c) 2026 Microchip Technology Inc. */
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
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_1600     = 0x0,   ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 1.6 GHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_1200     = 0x1,   ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 1.2 GHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_800      = 0x2,   ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 800 MHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_600      = 0x3,   ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 600 MHz
    P64H_SYSC_DDR_PART_SNPRKCR5C                  = 0x4,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_HMAA2GS6CJR8N_XN           = 0x5,   ///< SO-DIMM - HMAA2GS6CJR8N-XN 16GB (Non-ECC, IT)
    P64H_SYSC_DDR_PART_D4ES03                     = 0x6,   ///< SO-DIMM - D4ES03-16G 16GB (Synology)
    P64H_SYSC_DDR_PART_SQR_SD4I32G3K2SEAB         = 0x7,   ///< SO-DIMM DDR0 - SQR-SD4I32G3K2SEAB (Advantech Dual-Rank 32G)
    P64H_SYSC_DDR_PART_HWEMU_MODEL_CAS_24         = 0x8,   ///< HW Emulation model - CAS 24
    P64H_SYSC_DDR_PART_LAST
} p64h_sysc_ddr_part_t;

/* Public Methods ------------------------------------------ */
char* p64h_sysc_ddr_part_name_get(p64h_sysc_ddr_part_t ddr_part);
char* p64h_sysc_ddr_part_desc_get(p64h_sysc_ddr_part_t ddr_part);

#endif /* P64H_SYSC_DEF_DDR */