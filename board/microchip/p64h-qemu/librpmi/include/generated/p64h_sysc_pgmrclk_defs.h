/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef P64H_SYSC_DEF_PGMRCLK
#define P64H_SYSC_DEF_PGMRCLK

#include <generated/p64h_sysc_components.h>

/* Public Defines ------------------------------------------ */

/* Public Structs and Enums -------------------------------- */

/**
 * @brief P64H PGMRCLK Clock Select Setting type
 *
 */
typedef enum p64h_sysc_pgmrclk_sel_t {
    P64H_SYSC_PGMRCLK_SEL_EP_CORE_RX_CLK_0          = 0x0,    ///< RX Side Enet Endpoint Parallel Clock 0
    P64H_SYSC_PGMRCLK_SEL_EP_CORE_RX_CLK_1          = 0x1,    ///< RX Side Enet Endpoint Parallel Clock 1
    P64H_SYSC_PGMRCLK_SEL_EP_CORE_RX_CLK_2          = 0x2,    ///< RX Side Enet Endpoint Parallel Clock 2
    P64H_SYSC_PGMRCLK_SEL_EP_CORE_RX_CLK_3          = 0x3,    ///< RX Side Enet Endpoint Parallel Clock 3
    P64H_SYSC_PGMRCLK_SEL_EP_SHI_TX_CLK_0           = 0x4,    ///< TX Side Enet Endpoint Parallel Clock 0
    P64H_SYSC_PGMRCLK_SEL_EP_SHI_TX_CLK_1           = 0x5,    ///< TX Side Enet Endpoint Parallel Clock 1
    P64H_SYSC_PGMRCLK_SEL_EP_SHI_TX_CLK_2           = 0x6,    ///< TX Side Enet Endpoint Parallel Clock 2
    P64H_SYSC_PGMRCLK_SEL_EP_SHI_TX_CLK_3           = 0x7,    ///< TX Side Enet Endpoint Parallel Clock 3
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_0         = 0x8,    ///< RX Side Enet Switch Parallel Clock 0
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_1         = 0x9,    ///< RX Side Enet Switch Parallel Clock 1
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_2         = 0xa,    ///< RX Side Enet Switch Parallel Clock 2
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_3         = 0xb,    ///< RX Side Enet Switch Parallel Clock 3
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_4         = 0xc,    ///< RX Side Enet Switch Parallel Clock 4
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_5         = 0xd,    ///< RX Side Enet Switch Parallel Clock 5
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_6         = 0xe,    ///< RX Side Enet Switch Parallel Clock 6
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_7         = 0xf,    ///< RX Side Enet Switch Parallel Clock 7
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_8         = 0x10,   ///< RX Side Enet Switch Parallel Clock 8
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_9         = 0x11,   ///< RX Side Enet Switch Parallel Clock 9
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_10        = 0x12,   ///< RX Side Enet Switch Parallel Clock 10
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_11        = 0x13,   ///< RX Side Enet Switch Parallel Clock 11
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_12        = 0x14,   ///< RX Side Enet Switch Parallel Clock 12
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_13        = 0x15,   ///< RX Side Enet Switch Parallel Clock 13
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_14        = 0x16,   ///< RX Side Enet Switch Parallel Clock 14
    P64H_SYSC_PGMRCLK_SEL_SWR_CORE_RX_CLK_15        = 0x17,   ///< RX Side Enet Switch Parallel Clock 15
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_0          = 0x18,   ///< TX Side Enet Switch Parallel Clock 0
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_1          = 0x19,   ///< TX Side Enet Switch Parallel Clock 1
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_2          = 0x1a,   ///< TX Side Enet Switch Parallel Clock 2
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_3          = 0x1b,   ///< TX Side Enet Switch Parallel Clock 3
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_4          = 0x1c,   ///< TX Side Enet Switch Parallel Clock 4
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_5          = 0x1d,   ///< TX Side Enet Switch Parallel Clock 5
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_6          = 0x1e,   ///< TX Side Enet Switch Parallel Clock 6
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_7          = 0x1f,   ///< TX Side Enet Switch Parallel Clock 7
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_8          = 0x20,   ///< TX Side Enet Switch Parallel Clock 8
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_9          = 0x21,   ///< TX Side Enet Switch Parallel Clock 9
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_10         = 0x22,   ///< TX Side Enet Switch Parallel Clock 10
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_11         = 0x23,   ///< TX Side Enet Switch Parallel Clock 11
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_12         = 0x24,   ///< TX Side Enet Switch Parallel Clock 12
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_13         = 0x25,   ///< TX Side Enet Switch Parallel Clock 13
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_14         = 0x26,   ///< TX Side Enet Switch Parallel Clock 14
    P64H_SYSC_PGMRCLK_SEL_SWR_SHI_TX_CLK_15         = 0x27,   ///< TX Side Enet Switch Parallel Clock 15
    P64H_SYSC_PGMRCLK_SEL_SHI_HT_TXCLK_0            = 0x28,   ///< TX Side Highspeed Trace Parallel Clock 0
    P64H_SYSC_PGMRCLK_SEL_SHI_HT_TXCLK_1            = 0x29,   ///< TX Side Highspeed Trace Parallel Clock 1
    P64H_SYSC_PGMRCLK_SEL_M1_PGMRCLK_FB             = 0x2a,   ///< PGMRCLK Feedback Clock
    P64H_SYSC_PGMRCLK_SEL_SHI_S2_REFCLK             = 0x2b,   ///< Refclk output from SHI_S2 (Device Refclk)
    P64H_SYSC_PGMRCLK_SEL_SHI_E1_REFCLK_WDOG        = 0x2c,   ///< Refclk output from SHI_E1 (Watchdog Refclk)
    P64H_SYSC_PGMRCLK_SEL_CORE_PCIE_REFCLK          = 0x2d,   ///< Refclk output from SHI_P2 (PCIE/HT Refclk)
    P64H_SYSC_PGMRCLK_SEL_M1_POR_CLK                = 0x2e,   ///< M1 Power on Reset Clock
    P64H_SYSC_PGMRCLK_SEL_M1_RC_CLK                 = 0x2f,   ///< M1 RC Clock Input from Analog Top
    P64H_SYSC_PGMRCLK_SEL_IOB_DI_TCK                = 0x30,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SVC_CLK                   = 0x31,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_SYS_TX_CLK             = 0x32,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_USX_RX_CLK                = 0x33,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SYSC_CLK                  = 0x34,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_AXI_SPW_USB_CLK           = 0x35,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_USB_REF_CLK               = 0x36,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_PTP_CLK                   = 0x37,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_D_CLK                  = 0x38,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_CLK                   = 0x39,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_CPU_CLK                   = 0x3a,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_APP_NOC_CLK               = 0x3b,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SEC_CLK                   = 0x3c,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SWR_SYS_CLK               = 0x3d,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_0        = 0x3e,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_1        = 0x3f,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_2        = 0x40,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_3        = 0x41,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_4        = 0x42,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_5        = 0x43,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_6        = 0x44,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM0_MUX_CLK_OUT_7        = 0x45,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM1_MUX_CLK_OUT_0        = 0x46,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM1_MUX_CLK_OUT_1        = 0x47,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM1_MUX_CLK_OUT_2        = 0x48,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM1_MUX_CLK_OUT_3        = 0x49,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM2_MUX_CLK_OUT_0        = 0x4a,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM2_MUX_CLK_OUT_1        = 0x4b,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM2_MUX_CLK_OUT_2        = 0x4c,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM2_MUX_CLK_OUT_3        = 0x4d,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_NVM2_MUX_CLK_OUT_4        = 0x4e,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_DDR_EDAC_CLK              = 0x4f,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_DDR_CRYPTO_CORE_CLK       = 0x50,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_USER_CRYPTO_CORE_CLK      = 0x51,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SYS0_ACSU_LBIST_CLK       = 0x52,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_USB0_PIPE_PCLK            = 0x53,   ///< USB 0 Pipe Clock
    P64H_SYSC_PGMRCLK_SEL_USB1_PIPE_PCLK            = 0x54,   ///< USB 1 Pipe Clock
    P64H_SYSC_PGMRCLK_SEL_PCIE_1_P_PCLK_OUT_1       = 0x55,   ///< PCIE Controller 1 Link 1 Pipe Clock
    P64H_SYSC_PGMRCLK_SEL_PCIE_1_P_PCLK_OUT_0       = 0x56,   ///< PCIE Controller 1 Link 0 Pipe Clock
    P64H_SYSC_PGMRCLK_SEL_PCIE_0_P_PCLK_OUT_1       = 0x57,   ///< PCIE Controller 0 Link 1 Pipe Clock
    P64H_SYSC_PGMRCLK_SEL_PCIE_0_P_PCLK_OUT_0       = 0x58,   ///< PCIE Controller 0 Link 0 Pipe Clock
    P64H_SYSC_PGMRCLK_SEL_IOB_USB1_ULPI_CLK         = 0x59,   ///< USB0 ULPI Clock
    P64H_SYSC_PGMRCLK_SEL_IOB_USB0_ULPI_CLK         = 0x5a,   ///< USB1 ULPI Clock
    P64H_SYSC_PGMRCLK_SEL_RESERVED_91               = 0x5b,   ///< Bit 91 Reserved
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_0     = 0x5c,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_1     = 0x5d,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_2     = 0x5e,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_3     = 0x5f,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_4     = 0x60,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_5     = 0x61,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_6     = 0x62,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_RX_STGN_DBG_CLK_7     = 0x63,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_0     = 0x64,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_1     = 0x65,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_2     = 0x66,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_3     = 0x67,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_4     = 0x68,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_5     = 0x69,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_6     = 0x6a,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SPW_TX_STG0_DBG_CLK_7     = 0x6b,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_RX_CLK_0           = 0x6c,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_RX_CLK_1           = 0x6d,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_RX_CLK_2           = 0x6e,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_RX_CLK_3           = 0x6f,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_IN_CLK_0        = 0x70,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_IN_CLK_1        = 0x71,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_IN_CLK_2        = 0x72,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_IN_CLK_3        = 0x73,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_OUT_CLK_0       = 0x74,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_OUT_CLK_1       = 0x75,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_OUT_CLK_2       = 0x76,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_EP_PHY_TX_OUT_CLK_3       = 0x77,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_IOB_DI_SYS_SPI0_CLK       = 0x78,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_IOB_DI_SYS_SPI1_CLK       = 0x79,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_IOB_DO_APP_SPI0_CLK       = 0x7a,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_IOB_DO_APP_SPI1_CLK       = 0x7b,   ///< TODO add better description
    P64H_SYSC_PGMRCLK_SEL_SHI_HT_DTEST_OUT_0        = 0x7c,   ///< SHI_HT Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_HT_DTEST_OUT_1        = 0x7d,   ///< SHI_HT Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_P0_DTEST_OUT_0        = 0x7e,   ///< SHI_P0 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_P0_DTEST_OUT_1        = 0x7f,   ///< SHI_P0 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_P1_DTEST_OUT_0        = 0x80,   ///< SHI_P1 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_P1_DTEST_OUT_1        = 0x81,   ///< SHI_P1 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_P2_DTEST_OUT_0        = 0x82,   ///< SHI_P2 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_P2_DTEST_OUT_1        = 0x83,   ///< SHI_P2 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_P3_DTEST_OUT_0        = 0x84,   ///< SHI_P3 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_P3_DTEST_OUT_1        = 0x85,   ///< SHI_P3 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_S0_DTEST_OUT_0        = 0x86,   ///< SHI_S0 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_S0_DTEST_OUT_1        = 0x87,   ///< SHI_S0 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_S1_DTEST_OUT_0        = 0x88,   ///< SHI_S1 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_S1_DTEST_OUT_1        = 0x89,   ///< SHI_S1 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_S2_DTEST_OUT_0        = 0x8a,   ///< SHI_S2 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_S2_DTEST_OUT_1        = 0x8b,   ///< SHI_S2 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_S3_DTEST_OUT_0        = 0x8c,   ///< SHI_S3 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_S3_DTEST_OUT_1        = 0x8d,   ///< SHI_S3 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_E0_DTEST_OUT_0        = 0x8e,   ///< SHI_E0 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_E0_DTEST_OUT_1        = 0x8f,   ///< SHI_E0 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_SHI_E1_DTEST_OUT_0        = 0x90,   ///< SHI_E1 Digital Test Output 0
    P64H_SYSC_PGMRCLK_SEL_SHI_E1_DTEST_OUT_1        = 0x91,   ///< SHI_E1 Digital Test Output 1
    P64H_SYSC_PGMRCLK_SEL_APP_ACSU_LOCK             = 0x92,   ///< APP ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_EDAC_ACSU_LOCK            = 0x93,   ///< EDAC ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_NVM2_ACSU_LOCK            = 0x94,   ///< NVM2 ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_NVM1_ACSU_LOCK            = 0x95,   ///< NVM1 ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_NVM0_ACSU_LOCK            = 0x96,   ///< NVM0 ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_ENET_ACSU_LOCK            = 0x97,   ///< ENET ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_SEC_ACSU_LOCK             = 0x98,   ///< SEC ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_CPU_ACSU_LOCK             = 0x99,   ///< CPU ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_SYS1_ACSU_LOCK            = 0x9a,   ///< SYS1 ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_SYS0_ACSU_LOCK            = 0x9b,   ///< SYS0 ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_SYSC_ACSU_LOCK            = 0x9c,   ///< SYSC ACSU Lock Value
    P64H_SYSC_PGMRCLK_SEL_HSIO1_PLL_OUT_CLK_0       = 0x9d,   ///< HSIO1 PLL Lock 0 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO1_PLL_OUT_CLK_1       = 0x9e,   ///< HSIO1 PLL Lock 1 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO1_PLL_OUT_CLK_2       = 0x9f,   ///< HSIO1 PLL Lock 2 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO1_PLL_OUT_CLK_3       = 0xa0,   ///< HSIO1 PLL Lock 3 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO1_PLL_OUT_CLK_4       = 0xa1,   ///< HSIO1 PLL Lock 4 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO3_PLL_OUT_CLK_0       = 0xa2,   ///< HSIO3 PLL Lock 0 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO3_PLL_OUT_CLK_1       = 0xa3,   ///< HSIO3 PLL Lock 1 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO3_PLL_OUT_CLK_2       = 0xa4,   ///< HSIO3 PLL Lock 2 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO3_PLL_OUT_CLK_3       = 0xa5,   ///< HSIO3 PLL Lock 3 Value
    P64H_SYSC_PGMRCLK_SEL_HSIO3_PLL_OUT_CLK_4       = 0xa6,   ///< HSIO3 PLL Lock 4 Value
    P64H_SYSC_PGMRCLK_SEL_SEC_ACSU_LBIST_CLK        = 0xa7,   ///< SecC LBIST ACSU Clock
    P64H_SYSC_PGMRCLK_SEL_RESERVED_168              = 0xa8,   ///< Bit 168 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_169              = 0xa9,   ///< Bit 169 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_170              = 0xaa,   ///< Bit 170 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_171              = 0xab,   ///< Bit 171 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_172              = 0xac,   ///< Bit 172 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_173              = 0xad,   ///< Bit 173 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_174              = 0xae,   ///< Bit 174 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_175              = 0xaf,   ///< Bit 175 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_176              = 0xb0,   ///< Bit 176 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_177              = 0xb1,   ///< Bit 177 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_178              = 0xb2,   ///< Bit 178 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_179              = 0xb3,   ///< Bit 179 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_180              = 0xb4,   ///< Bit 180 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_181              = 0xb5,   ///< Bit 181 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_182              = 0xb6,   ///< Bit 182 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_183              = 0xb7,   ///< Bit 183 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_184              = 0xb8,   ///< Bit 184 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_185              = 0xb9,   ///< Bit 185 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_186              = 0xba,   ///< Bit 186 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_187              = 0xbb,   ///< Bit 187 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_188              = 0xbc,   ///< Bit 188 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_189              = 0xbd,   ///< Bit 189 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_190              = 0xbe,   ///< Bit 190 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_191              = 0xbf,   ///< Bit 191 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_192              = 0xc0,   ///< Bit 192 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_193              = 0xc1,   ///< Bit 193 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_194              = 0xc2,   ///< Bit 194 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_195              = 0xc3,   ///< Bit 195 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_196              = 0xc4,   ///< Bit 196 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_197              = 0xc5,   ///< Bit 197 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_198              = 0xc6,   ///< Bit 198 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_199              = 0xc7,   ///< Bit 199 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_200              = 0xc8,   ///< Bit 200 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_201              = 0xc9,   ///< Bit 201 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_202              = 0xca,   ///< Bit 202 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_203              = 0xcb,   ///< Bit 203 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_204              = 0xcc,   ///< Bit 204 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_205              = 0xcd,   ///< Bit 205 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_206              = 0xce,   ///< Bit 206 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_207              = 0xcf,   ///< Bit 207 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_208              = 0xd0,   ///< Bit 208 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_209              = 0xd1,   ///< Bit 209 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_210              = 0xd2,   ///< Bit 210 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_211              = 0xd3,   ///< Bit 211 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_212              = 0xd4,   ///< Bit 212 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_213              = 0xd5,   ///< Bit 213 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_214              = 0xd6,   ///< Bit 214 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_215              = 0xd7,   ///< Bit 215 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_216              = 0xd8,   ///< Bit 216 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_217              = 0xd9,   ///< Bit 217 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_218              = 0xda,   ///< Bit 218 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_219              = 0xdb,   ///< Bit 219 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_220              = 0xdc,   ///< Bit 220 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_221              = 0xdd,   ///< Bit 221 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_222              = 0xde,   ///< Bit 222 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_223              = 0xdf,   ///< Bit 223 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_224              = 0xe0,   ///< Bit 224 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_225              = 0xe1,   ///< Bit 225 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_226              = 0xe2,   ///< Bit 226 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_227              = 0xe3,   ///< Bit 227 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_228              = 0xe4,   ///< Bit 228 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_229              = 0xe5,   ///< Bit 229 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_230              = 0xe6,   ///< Bit 230 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_231              = 0xe7,   ///< Bit 231 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_232              = 0xe8,   ///< Bit 232 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_233              = 0xe9,   ///< Bit 233 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_234              = 0xea,   ///< Bit 234 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_235              = 0xeb,   ///< Bit 235 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_236              = 0xec,   ///< Bit 236 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_237              = 0xed,   ///< Bit 237 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_238              = 0xee,   ///< Bit 238 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_239              = 0xef,   ///< Bit 239 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_240              = 0xf0,   ///< Bit 240 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_241              = 0xf1,   ///< Bit 241 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_242              = 0xf2,   ///< Bit 242 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_243              = 0xf3,   ///< Bit 243 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_244              = 0xf4,   ///< Bit 244 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_245              = 0xf5,   ///< Bit 245 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_246              = 0xf6,   ///< Bit 246 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_247              = 0xf7,   ///< Bit 247 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_248              = 0xf8,   ///< Bit 248 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_249              = 0xf9,   ///< Bit 249 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_250              = 0xfa,   ///< Bit 250 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_251              = 0xfb,   ///< Bit 251 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_252              = 0xfc,   ///< Bit 252 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_253              = 0xfd,   ///< Bit 253 Reserved
    P64H_SYSC_PGMRCLK_SEL_RESERVED_254              = 0xfe,   ///< Bit 254 Reserved
    P64H_SYSC_PGMRCLK_SEL_RC_CLK_OUT                = 0xff,   ///< RC Clock Out (after RC Selection Mux)
    P64H_SYSC_PGMRCLK_SEL_LAST
} p64h_sysc_pgmrclk_sel_t;

/**
 * @brief P64H PGMRCLK Clock identifier type
 *
 */
typedef enum  {
    P64H_SYSC_PGMRCLK_ID_PIN_0     = 0x0,   ///< identifier for device output pin PGMRCLK[0]
    P64H_SYSC_PGMRCLK_ID_PIN_1     = 0x1,   ///< identifier for device output pin PGMRCLK[1]
    P64H_SYSC_PGMRCLK_ID_PIN_2     = 0x2,   ///< identifier for device output pin PGMRCLK[2]
    P64H_SYSC_PGMRCLK_ID_PIN_3     = 0x3,   ///< identifier for device output pin PGMRCLK[3]
    P64H_SYSC_PGMRCLK_ID_LAST
} p64h_sysc_pgmrclk_id_t;

/**
 * @brief P64H Calibration Frequency Meter Reference Clock Select Setting type
 *
 */
typedef enum  {
    P64H_SYSC_CFM_REF_SEL_REFCLK           = 0x0,   ///< Device Reference Clock
    P64H_SYSC_CFM_REF_SEL_TCK              = 0x1,   ///< JTAG Test Clock
    P64H_SYSC_CFM_REF_SEL_REF_WDOG_CLK     = 0x2,   ///< Reference Clock Watchdog Clock (only valid for ACSU CFM instances)
    P64H_SYSC_CFM_REF_SEL_LAST
} p64h_sysc_cfm_ref_sel_t;

///< PGMRCLK Output 3 (only valid on Generic CFM instance)
#define P64H_SYSC_CFM_REF_SEL_PGMRCLK_OUT3 P64H_SYSC_CFM_REF_SEL_REF_WDOG_CLK

/**
 * @brief P64H Calibration Frequency Meter Measurement Clock Generic Select Setting type
 *
 */
typedef enum  {
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_PGMRCLK_OUT0     = 0x0,   ///< PGMRCLK Output 0 Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_PGMRCLK_OUT1     = 0x1,   ///< PGMRCLK Output 1 Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_PGMRCLK_OUT2     = 0x2,   ///< PGMRCLK Output 2 Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_PGMRCLK_OUT3     = 0x3,   ///< PGMRCLK Output 3 Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_POR_CLK          = 0x4,   ///< Power on Reset Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_RC_CLK           = 0x5,   ///< RC Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_REF_WDOG_CLK     = 0x6,   ///< Reference Watchdog Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_PCIE_CLK         = 0x7,   ///< PCIE Reference Clock
    P64H_SYSC_CFM_MEAS_SEL_GENERIC_LAST
} p64h_sysc_cfm_meas_sel_generic_t;

/**
 * @brief P64H Calibration Frequency Meter Measurement Clock ACSU0 Select Setting type
 *
 */
typedef enum  {
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_SYS0_ACSU_CLK     = 0x0,   ///< SYS0 ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_SECC_ACSU_CLK     = 0x1,   ///< SECC ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_SYS1_ACSU_CLK     = 0x2,   ///< SYS1 ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_CPU_ACSU_CLK      = 0x3,   ///< CPU  ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_APP_ACSU_CLK      = 0x4,   ///< APP  ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_SYSC_ACSU_CLK     = 0x5,   ///< SYSC ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_ENET_ACSU_CLK     = 0x6,   ///< ENET ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_EDAC_ACSU_CLK     = 0x7,   ///< EDAC ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU0_LAST
} p64h_sysc_cfm_meas_sel_acsu0_t;

/**
 * @brief P64H Calibration Frequency Meter Measurement Clock ACSU1 Select Setting type
 *
 */
typedef enum  {
    P64H_SYSC_CFM_MEAS_SEL_ACSU1_NVM0_ACSU_CLK      = 0x0,   ///< NVM0 ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU1_NVM1_ACSU_CLK      = 0x1,   ///< NVM1 ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU1_NVM2_ACSU_CLK      = 0x2,   ///< NVM2 ACSU Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU1_HSIO_ACSU0_CLK     = 0x3,   ///< HSIO ACSU0 Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU1_HSIO_ACSU1_CLK     = 0x4,   ///< HSIO ACSU1 Clock
    P64H_SYSC_CFM_MEAS_SEL_ACSU1_LAST
} p64h_sysc_cfm_meas_sel_acsu1_t;

/**
 * @brief P64H Calibration Frequency Meter Instances type
 *
 */
typedef enum  {
    P64H_SYSC_CFM_INST_GENERIC     = 0x0,   ///< General-purpose CFM Instance
    P64H_SYSC_CFM_INST_ACSU_0      = 0x1,   ///< ACSU 0 CFM Instance
    P64H_SYSC_CFM_INST_ACSU_1      = 0x2,   ///< ACSU 1 CFM Instance
    P64H_SYSC_CFM_INST_LAST
} p64h_sysc_cfm_inst_t;

/**
 * @brief P64H Calibration Frequency Meter measurement modes type
 *
 */
typedef enum  {
    P64H_SYSC_CFM_MEAS_MODE_DISABLED     = 0x0,   ///< CFM measurement disabled
    P64H_SYSC_CFM_MEAS_MODE_FREQ         = 0x1,   ///< Frequency Mode
    P64H_SYSC_CFM_MEAS_MODE_TIME         = 0x2,   ///< Time Mode
    P64H_SYSC_CFM_MEAS_MODE_LAST
} p64h_sysc_cfm_meas_mode_t;

/* Public Methods ------------------------------------------ */

#endif /* P64H_SYSC_DEF_PGMRCLK */