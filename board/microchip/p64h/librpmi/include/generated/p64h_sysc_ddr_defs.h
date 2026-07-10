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
typedef enum p64h_sysc_ddr_part_t {
    P64H_SYSC_DDR_PART_MT40A1G16TD_062E_1600                                       = 0x0,    ///< SDRAM - DDR4 Memory IC 16Gbit Parallel 1.6 GHz
    P64H_SYSC_DDR_PART_MT40A1G16TD_062E_1200                                       = 0x1,    ///< SDRAM - DDR4 Memory IC 16Gbit Parallel 1.2 GHz
    P64H_SYSC_DDR_PART_MT40A1G16TD_062E_1067                                       = 0x2,    ///< SDRAM - DDR4 Memory IC 16Gbit Parallel 1066.67 MHz
    P64H_SYSC_DDR_PART_MT40A1G16TD_062E_800                                        = 0x3,    ///< SDRAM - DDR4 Memory IC 16Gbit Parallel 800 MHz
    P64H_SYSC_DDR_PART_MT40A1G16TD_062E_600                                        = 0x4,    ///< SDRAM - DDR4 Memory IC 16Gbit Parallel 600 MHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_1600                                      = 0x5,    ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 1.6 GHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_1200                                      = 0x6,    ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 1.2 GHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_1067                                      = 0x7,    ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 1066.67 MHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_800                                       = 0x8,    ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 800 MHz
    P64H_SYSC_DDR_PART_MT40A2G16TBB_062E_600                                       = 0x9,    ///< SDRAM - DDR4 Memory IC 32Gbit Parallel 600 MHz
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AA_BL8_CL12_MDPS800_CS2_16GB_DQ72      = 0xa,    ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AC_BL8_CL12_MDPS800_CS2_16GB_DQ72      = 0xb,    ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AA_BL8_CL12_MDPS1067_CS2_16GB_DQ72     = 0xc,    ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AC_BL8_CL12_MDPS1067_CS2_16GB_DQ72     = 0xd,    ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AA_BL8_CL12_MDPS1200_CS2_16GB_DQ72     = 0xe,    ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AC_BL8_CL12_MDPS1200_CS2_16GB_DQ72     = 0xf,    ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AA_BL8_CL12_MDPS800_CS2_8GB_DQ72       = 0x10,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AC_BL8_CL12_MDPS800_CS2_8GB_DQ72       = 0x11,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AA_BL8_CL12_MDPS1067_CS2_8GB_DQ72      = 0x12,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AC_BL8_CL12_MDPS1067_CS2_8GB_DQ72      = 0x13,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AA_BL8_CL12_MDPS1200_CS2_8GB_DQ72      = 0x14,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_JEDEC_DDR4_8G_X8_3200AC_BL8_CL12_MDPS1200_CS2_8GB_DQ72      = 0x15,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_SNPRKCR5C                                                   = 0x16,   ///< SO-DIMM - SNPRKCR5C/16G (Dell)
    P64H_SYSC_DDR_PART_DDR4_16G_X16_1600J                                          = 0x17,   ///< JEDEC DDR4_16G_X16_1600J
    P64H_SYSC_DDR_PART_DDR4_16G_X16_1600K                                          = 0x18,   ///< JEDEC DDR4_16G_X16_1600K
    P64H_SYSC_DDR_PART_DDR4_16G_X16_1600L                                          = 0x19,   ///< JEDEC DDR4_16G_X16_1600L
    P64H_SYSC_DDR_PART_DDR4_16G_X16_1866L                                          = 0x1a,   ///< JEDEC DDR4_16G_X16_1866L
    P64H_SYSC_DDR_PART_DDR4_16G_X16_1866M                                          = 0x1b,   ///< JEDEC DDR4_16G_X16_1866M
    P64H_SYSC_DDR_PART_DDR4_16G_X16_1866N                                          = 0x1c,   ///< JEDEC DDR4_16G_X16_1866N
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2133N                                          = 0x1d,   ///< JEDEC DDR4_16G_X16_2133N
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2133P                                          = 0x1e,   ///< JEDEC DDR4_16G_X16_2133P
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2133R                                          = 0x1f,   ///< JEDEC DDR4_16G_X16_2133R
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2400P                                          = 0x20,   ///< JEDEC DDR4_16G_X16_2400P
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2400R                                          = 0x21,   ///< JEDEC DDR4_16G_X16_2400R
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2400T                                          = 0x22,   ///< JEDEC DDR4_16G_X16_2400T
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2400U                                          = 0x23,   ///< JEDEC DDR4_16G_X16_2400U
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2666T                                          = 0x24,   ///< JEDEC DDR4_16G_X16_2666T
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2666U                                          = 0x25,   ///< JEDEC DDR4_16G_X16_2666U
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2666V                                          = 0x26,   ///< JEDEC DDR4_16G_X16_2666V
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2666W                                          = 0x27,   ///< JEDEC DDR4_16G_X16_2666W
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2933AA                                         = 0x28,   ///< JEDEC DDR4_16G_X16_2933AA
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2933V                                          = 0x29,   ///< JEDEC DDR4_16G_X16_2933V
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2933W                                          = 0x2a,   ///< JEDEC DDR4_16G_X16_2933W
    P64H_SYSC_DDR_PART_DDR4_16G_X16_2933Y                                          = 0x2b,   ///< JEDEC DDR4_16G_X16_2933Y
    P64H_SYSC_DDR_PART_DDR4_16G_X16_3200AA                                         = 0x2c,   ///< JEDEC DDR4_16G_X16_3200AA
    P64H_SYSC_DDR_PART_DDR4_16G_X16_3200AC                                         = 0x2d,   ///< JEDEC DDR4_16G_X16_3200AC
    P64H_SYSC_DDR_PART_DDR4_16G_X16_3200W                                          = 0x2e,   ///< JEDEC DDR4_16G_X16_3200W
    P64H_SYSC_DDR_PART_DDR4_16G_X8_1600J                                           = 0x2f,   ///< JEDEC DDR4_16G_X8_1600J
    P64H_SYSC_DDR_PART_DDR4_16G_X8_1600K                                           = 0x30,   ///< JEDEC DDR4_16G_X8_1600K
    P64H_SYSC_DDR_PART_DDR4_16G_X8_1600L                                           = 0x31,   ///< JEDEC DDR4_16G_X8_1600L
    P64H_SYSC_DDR_PART_DDR4_16G_X8_1866L                                           = 0x32,   ///< JEDEC DDR4_16G_X8_1866L
    P64H_SYSC_DDR_PART_DDR4_16G_X8_1866M                                           = 0x33,   ///< JEDEC DDR4_16G_X8_1866M
    P64H_SYSC_DDR_PART_DDR4_16G_X8_1866N                                           = 0x34,   ///< JEDEC DDR4_16G_X8_1866N
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2133N                                           = 0x35,   ///< JEDEC DDR4_16G_X8_2133N
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2133P                                           = 0x36,   ///< JEDEC DDR4_16G_X8_2133P
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2133R                                           = 0x37,   ///< JEDEC DDR4_16G_X8_2133R
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2400P                                           = 0x38,   ///< JEDEC DDR4_16G_X8_2400P
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2400R                                           = 0x39,   ///< JEDEC DDR4_16G_X8_2400R
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2400T                                           = 0x3a,   ///< JEDEC DDR4_16G_X8_2400T
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2400U                                           = 0x3b,   ///< JEDEC DDR4_16G_X8_2400U
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2666T                                           = 0x3c,   ///< JEDEC DDR4_16G_X8_2666T
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2666U                                           = 0x3d,   ///< JEDEC DDR4_16G_X8_2666U
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2666V                                           = 0x3e,   ///< JEDEC DDR4_16G_X8_2666V
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2666W                                           = 0x3f,   ///< JEDEC DDR4_16G_X8_2666W
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2933AA                                          = 0x40,   ///< JEDEC DDR4_16G_X8_2933AA
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2933V                                           = 0x41,   ///< JEDEC DDR4_16G_X8_2933V
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2933W                                           = 0x42,   ///< JEDEC DDR4_16G_X8_2933W
    P64H_SYSC_DDR_PART_DDR4_16G_X8_2933Y                                           = 0x43,   ///< JEDEC DDR4_16G_X8_2933Y
    P64H_SYSC_DDR_PART_DDR4_16G_X8_3200AA                                          = 0x44,   ///< JEDEC DDR4_16G_X8_3200AA
    P64H_SYSC_DDR_PART_DDR4_16G_X8_3200W                                           = 0x45,   ///< JEDEC DDR4_16G_X8_3200W
    P64H_SYSC_DDR_PART_HWEMU_MODEL_CAS_24                                          = 0x46,   ///< HW Emulation model - CAS 24
    P64H_SYSC_DDR_PART_LAST
} p64h_sysc_ddr_part_t;

/* Public Methods ------------------------------------------ */
char* p64h_sysc_ddr_part_name_get(p64h_sysc_ddr_part_t ddr_part);
char* p64h_sysc_ddr_part_desc_get(p64h_sysc_ddr_part_t ddr_part);

#endif /* P64H_SYSC_DEF_DDR */