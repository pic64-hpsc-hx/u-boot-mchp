/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_sysc_serdes_types.h
 * @brief
 *   Defines types required for serdes configuration
 * @addtogroup p64h_sysc_types
 * @{
 */
#ifndef P64H_SYSC_SERDES_TYPES_H
#define P64H_SYSC_SERDES_TYPES_H

#include "p64h_sysc_anlt_types.h"

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_SERDES_MAX_NUM_AN_RATES    5u  // Maximum possible number of rates in consideration during AN
#define P64H_SYSC_SERDES_MAX_NUM_GRP_LANES   8u  // Maximum possible number of lanes in a single SerDes Group (8 for PCIe PHY Bonded case)
#define P64H_SYSC_SERDES_RX_CALIB_CODE_LEN   16u // Rx calibration sequence is at most 16 codes long
#define P64H_SYSC_SERDES_LANES_PER_BANK      4u  // Number of physical lanes per serdes bank
#define P64H_SYSC_SERDES_GRP_MASK_LANE0      0b00000001U
#define P64H_SYSC_SERDES_GRP_MASK_LANE1      0b00000010U
#define P64H_SYSC_SERDES_GRP_MASK_LANE2      0b00000100U
#define P64H_SYSC_SERDES_GRP_MASK_LANE3      0b00001000U
#define P64H_SYSC_SERDES_GRP_MASK_LANE4      0b00010000U
#define P64H_SYSC_SERDES_GRP_MASK_LANE5      0b00100000U
#define P64H_SYSC_SERDES_GRP_MASK_LANE6      0b01000000U
#define P64H_SYSC_SERDES_GRP_MASK_LANE7      0b10000000U
#define P64H_SYSC_SERDES_GRP_MASK_ALL_LANES  0b11111111U

#define P64H_SYSC_SERDES_RATE_TYPE_MASK      0xC0000000U ///< serdes rate type mask in port rate word
#define P64H_SYSC_SERDES_RATE_TYPE_OFFSET    30u         ///< serdes rate type offset in port rate word
#define P64H_SYSC_SERDES_FVCO_MASK           0x30000000U ///< serdes fvco mask in port rate word
#define P64H_SYSC_SERDES_FVCO_OFFSET         28u         ///< serdes fvco offset in port rate word
#define P64H_SYSC_SERDES_RXPLL_REFDIV_MASK   0x0F000000U ///< serdes rxpll_refdiv mask in port rate word
#define P64H_SYSC_SERDES_RXPLL_REFDIV_OFFSET 24u         ///< serdes rxpll_refdiv offset in port rate word
#define P64H_SYSC_SERDES_RXPLL_FBDIV_MASK    0x00FF0000U ///< serdes rxpll_fbdiv mask in port rate word
#define P64H_SYSC_SERDES_RXPLL_FBDIV_OFFSET  16u         ///< serdes rxpll_fbdiv offset in port rate word
#define P64H_SYSC_SERDES_TXPLL_FBDIV_MASK    0x0000FF00U ///< serdes txpll_fbdiv mask in port rate word
#define P64H_SYSC_SERDES_TXPLL_FBDIV_OFFSET  8u          ///< serdes txpll_fbdiv offset in port rate word
#define P64H_SYSC_SERDES_BW_MASK             0x000000E0U ///< serdes buswidth mask in port rate word
#define P64H_SYSC_SERDES_BW_OFFSET           5u          ///< serdes buswidth offset in port rate word
#define P64H_SYSC_SERDES_RXPLL_RANGE_MASK    0x0000001CU ///< serdes rxpll_range mask in port rate word
#define P64H_SYSC_SERDES_RXPLL_RANGE_OFFSET  2u          ///< serdes rxpll_range offset in port rate word
#define P64H_SYSC_SERDES_TX_POSTDIV_MASK     0x00000003U ///< serdes tx_postdiv mask in port rate word
#define P64H_SYSC_SERDES_TX_POSTDIV_OFFSET   0u          ///< serdes tx_postdiv offset in port rate word

#define P64H_SYSC_SERDES_RATE_TYPE_GET(rate)                                                                                                         \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_RATE_TYPE_MASK) >> P64H_SYSC_SERDES_RATE_TYPE_OFFSET)) ///< Extract serdes rate type
#define P64H_SYSC_SERDES_FVCO_GET(rate)                                                                                                              \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_FVCO_MASK) >> P64H_SYSC_SERDES_FVCO_OFFSET)) ///< Extract serdes fvco
#define P64H_SYSC_SERDES_RXPLL_REFDIV_GET(rate)                                                                                                      \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_RXPLL_REFDIV_MASK) >> P64H_SYSC_SERDES_RXPLL_REFDIV_OFFSET)) ///< Extract serdes rxpll_refdiv
#define P64H_SYSC_SERDES_RXPLL_FBDIV_GET(rate)                                                                                                       \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_RXPLL_FBDIV_MASK) >> P64H_SYSC_SERDES_RXPLL_FBDIV_OFFSET)) ///< Extract serdes rxpll_fbdiv
#define P64H_SYSC_SERDES_TXPLL_FBDIV_GET(rate)                                                                                                       \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_TXPLL_FBDIV_MASK) >> P64H_SYSC_SERDES_TXPLL_FBDIV_OFFSET)) ///< Extract serdes txpll_fbdiv
#define P64H_SYSC_SERDES_BW_GET(rate)                                                                                                                \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_BW_MASK) >> P64H_SYSC_SERDES_BW_OFFSET)) ///< Extract parallel buswidth
#define P64H_SYSC_SERDES_RXPLL_RANGE_GET(rate)                                                                                                       \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_RXPLL_RANGE_MASK) >> P64H_SYSC_SERDES_RXPLL_RANGE_OFFSET)) ///< Extract serdes rxpll_range
#define P64H_SYSC_SERDES_TX_POSTDIV_GET(rate)                                                                                                        \
    ((uint8_t)(((uint32_t)rate & P64H_SYSC_SERDES_TX_POSTDIV_MASK) >> P64H_SYSC_SERDES_TX_POSTDIV_OFFSET)) ///< Extract serdes tx postdivider setting

/// Bitmask Defines for Runtime Configuration Parameters
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_DP_SRC         0x00000001U ///< Bitmask for TX_DP_SRC
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_PATTGEN_CFG    0x00000002U ///< Bitmask for TX_PATTGEN_CFG
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_PATTGEN_EN     0x00000004U ///< Bitmask for TX_PATTGEN_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_ERR_INJ_CFG    0x00000008U ///< Bitmask for TX_ERR_INJ_CFG
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_ERR_INJ_EN     0x00000010U ///< Bitmask for TX_ERR_INJ_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_SQUELCH_PATT   0x00000020U ///< Bitmask for TX_SQUELCH_PATT
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_SQUELCH_EN     0x00000040U ///< Bitmask for TX_SQUELCH_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_HW_SQUELCH_EN  0x00000080U ///< Bitmask for TX_HW_SQUELCH_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_TRANSCOND_EN   0x00000100U ///< Bitmask for TX_TRANSCOND_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_INVERT_EN      0x00000200U ///< Bitmask for TX_INVERT_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_DP_SRC         0x00000400U ///< Bitmask for RX_DP_SRC
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_CALIB_CODE_SEQ 0x00000800U ///< Bitmask for RX_CALIB_CODE_SEQ
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_CALIB_RUN      0x00001000U ///< Bitmask for RX_CALIB_RUN
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_PATTMON_CFG    0x00002000U ///< Bitmask for RX_PATTMON_CFG
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_PATTMON_EN     0x00004000U ///< Bitmask for RX_PATTMON_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_ERR_INJ_CFG    0x00008000U ///< Bitmask for RX_ERR_INJ_CFG
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_ERR_INJ_EN     0x00010000U ///< Bitmask for RX_ERR_INJ_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_SQUELCH_PATT   0x00020000U ///< Bitmask for RX_SQUELCH_PATT
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_SQUELCH_EN     0x00040000U ///< Bitmask for RX_SQUELCH_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_FSD_CONTINUOUS 0x00080000U ///< Bitmask for RX_FSD_CONTINUOUS
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_FSD_EN         0x00100000U ///< Bitmask for RX_FSD_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_RX_INVERT_EN      0x00200000U ///< Bitmask for RX_INVERT_EN
#define P64H_SYSC_SERDES_RT_CFG_MASK_REFCLK            0x00400000U ///< Bitmask for REFCLK
#define P64H_SYSC_SERDES_RT_CFG_MASK_DLOS              0x00800000U ///< Bitmask for DLOS
#define P64H_SYSC_SERDES_RT_CFG_MASK_LPBK              0x01000000U ///< Bitmask for LPBK
#define P64H_SYSC_SERDES_RT_CFG_MASK_TX_DRVR           0x02000000U ///< Bitmask for TX DRIVER
#define P64H_SYSC_SERDES_RT_CFG_MASK_DTEST             0x04000000U ///< Bitmask for DTEST
#define P64H_SYSC_SERDES_RT_CFG_MASK_RXRTRIM           0x08000000U ///< Bitmask for RXRTRIM
#define P64H_SYSC_SERDES_RT_CFG_MASK_ALL_FIELDS        0x0FFFFFFFU ///< Bitmask for ALL_FIELDS

/// Some recommended RX calibration sequences preprocessed into uint64_t's
#define P64H_SYSC_SERDES_RX_FULLCALIB 0x00000004BD876521U ///< Full calibration sequence, should be run once on initial SerDes bringup
#define P64H_SYSC_SERDES_RX_RECALIB                                                                                                                  \
    0x000000004BD96521U                                     ///< Recalibration sequence, should be run if Full calibration has
                                                            ///< been run and we need to re-calibrate for whatever reason
#define P64H_SYSC_SERDES_RX_FASTCALIB   0x0000000000046521U ///< Fast calibration sequence for use in non-noisy environments
#define P64H_SYSC_SERDES_RX_EM_FOM_CALC 0x000000000000043DU ///< Sequence to trigger a single Eye Area measurment

#define PATTMON_USR_PAT_NUM_BYTES       10u ///< Pattern Monitor supports user pattern 80 bits
#define PATTGEN_USR_PAT_NUM_BYTES       40u ///< Pattern Generator supports user pattern 320 bits
#define ERR_INJ_MODE_NUM_BYTES          10u ///< Error injection mode 80 bits
#define SQUELCH_NUM_BYTES               10u ///< Squelch 80 bits
/// Bitmask for SerDes Diagnostic Fields
#define P64H_SYSC_SERDES_DIAG_MASK_RATE       0b0000001U ///< Bitmask for RATE
#define P64H_SYSC_SERDES_DIAG_MASK_TXPLL_LOCK 0b0000010U ///< Bitmask for TXPLL_LOCK
#define P64H_SYSC_SERDES_DIAG_MASK_TRANSCOND  0b0000100U ///< Bitmask for TRANSCOND
#define P64H_SYSC_SERDES_DIAG_MASK_DLOS       0b0001000U ///< Bitmask for DLOS
#define P64H_SYSC_SERDES_DIAG_MASK_PATTMON    0b0010000U ///< Bitmask for PATTMON
#define P64H_SYSC_SERDES_DIAG_MASK_RX_CALIB   0b0100000U ///< Bitmask for RX_CALIB
#define P64H_SYSC_SERDES_DIAG_MASK_WINDOW     0b1000000U ///< Bitmask for RX_CALIB
#define P64H_SYSC_SERDES_DIAG_MASK_ALL_FIELDS 0b1111111U ///< Bitmask for ALL_FIELDS

#define P64H_SYSC_SERDES_NUM_PKDETOUT_VALS    8u    /// Peak detector output is a 7 bit thermo-coded value, meaning there are 8 possible values
#define P64H_SYSC_SERDES_DIAG_WINDOW_MAX      5000u /// Maximum number of samples to take for a windowed diagnostic measurement
/* Public Structs and Enums --------------------------------------- */

/// enumerate serdes groups
typedef enum {
    P64H_SYSC_SERDES_GRP_ID_ENET_EP_0 = 0, ///< SerDes group identifier ENET Endpoint lane 0
    P64H_SYSC_SERDES_GRP_ID_ENET_EP_1,     ///< SerDes group identifier ENET Endpoint lane 1
    P64H_SYSC_SERDES_GRP_ID_ENET_EP_2,     ///< SerDes group identifier ENET Endpoint lane 2
    P64H_SYSC_SERDES_GRP_ID_ENET_EP_3,     ///< SerDes group identifier ENET Endpoint lane 3
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_0,    ///< SerDes group identifier ENET Switch lane 0
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_1,    ///< SerDes group identifier ENET Switch lane 1
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_2,    ///< SerDes group identifier ENET Switch lane 2
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_3,    ///< SerDes group identifier ENET Switch lane 3
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_4,    ///< SerDes group identifier ENET Switch lane 4
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_5,    ///< SerDes group identifier ENET Switch lane 5
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_6,    ///< SerDes group identifier ENET Switch lane 6
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_7,    ///< SerDes group identifier ENET Switch lane 7
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_8,    ///< SerDes group identifier ENET Switch lane 8
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_9,    ///< SerDes group identifier ENET Switch lane 9
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_10,   ///< SerDes group identifier ENET Switch lane 10
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_11,   ///< SerDes group identifier ENET Switch lane 11
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_12,   ///< SerDes group identifier ENET Switch lane 12
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_13,   ///< SerDes group identifier ENET Switch lane 13
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_14,   ///< SerDes group identifier ENET Switch lane 14
    P64H_SYSC_SERDES_GRP_ID_ENET_SWR_15,   ///< SerDes group identifier ENET Switch lane 15
    P64H_SYSC_SERDES_GRP_ID_PCIE0_0,       ///< SerDes group identifier PCIe0 link 0
    P64H_SYSC_SERDES_GRP_ID_PCIE0_1,       ///< SerDes group identifier PCIe0 link 1
    P64H_SYSC_SERDES_GRP_ID_PCIE1_0,       ///< SerDes group identifier PCIe1 link 0
    P64H_SYSC_SERDES_GRP_ID_PCIE1_1,       ///< SerDes group identifier PCIe1 link 1
    P64H_SYSC_SERDES_GRP_ID_TRACE,         ///< SerDes group identifier Trace (May use either 1 or two lanes)
    P64H_SYSC_SERDES_GRP_ID_USB_0,         ///< SerDes group identifier USB 0
    P64H_SYSC_SERDES_GRP_ID_USB_1,         ///< SerDes group identifier USB 1
    P64H_SYSC_SERDES_GRP_ID_LAST,          ///< invalid, used for error checking
} p64h_sysc_serdes_grp_id_t;

/// Enum used to define SerDes Bank as specified by SYS Controller Memory Map
typedef enum {
    P64H_SYSC_SERDES_BANK_E1 = 0u, ///< SerDes Bank Ethernet Endpoint bank 1
    P64H_SYSC_SERDES_BANK_E0,      ///< SerDes Bank Ethernet Endpoint bank 0
    P64H_SYSC_SERDES_BANK_S3,      ///< SerDes Bank Ethernet Switch bank 3
    P64H_SYSC_SERDES_BANK_S2,      ///< SerDes Bank Ethernet Switch bank 2
    P64H_SYSC_SERDES_BANK_S1,      ///< SerDes Bank Ethernet Switch bank 1
    P64H_SYSC_SERDES_BANK_S0,      ///< SerDes Bank Ethernet Switch bank 0
    P64H_SYSC_SERDES_BANK_P3,      ///< SerDes Bank PCIE 1, bank 1
    P64H_SYSC_SERDES_BANK_P2,      ///< SerDes Bank PCIE 1, bank 0
    P64H_SYSC_SERDES_BANK_P1,      ///< SerDes Bank PCIE 0, bank 1
    P64H_SYSC_SERDES_BANK_P0,      ///< SerDes Bank PCIE 0, bank 0
    P64H_SYSC_SERDES_BANK_HT,      ///< SerDes Bank Highspeed Trace
    P64H_SYSC_SERDES_BANK_LAST     ///< invalid, used for error checking
} p64h_sysc_serdes_bank_t;

/// Bit encoded enum for SerDes Lane selection
typedef enum p64h_sysc_serdes_if_t {
    P64H_SYSC_SERDES_IF_NULL        = 0u,  ///< invalid, used for error checking
    P64H_SYSC_SERDES_IF_ENET_EP_3   = 1u,  ///< SerDes ENET Endpoint lane 3
    P64H_SYSC_SERDES_IF_ENET_EP_2   = 2u,  ///< SerDes ENET Endpoint lane 2
    P64H_SYSC_SERDES_IF_ENET_EP_1   = 3u,  ///< SerDes ENET Endpoint lane 1
    P64H_SYSC_SERDES_IF_ENET_EP_0   = 4u,  ///< SerDes ENET Endpoint lane 0
    P64H_SYSC_SERDES_IF_ENET_SWR_15 = 5u,  ///< SerDes ENET Switch lane 15
    P64H_SYSC_SERDES_IF_ENET_SWR_14 = 6u,  ///< SerDes ENET Switch lane 14
    P64H_SYSC_SERDES_IF_ENET_SWR_13 = 7u,  ///< SerDes ENET Switch lane 13
    P64H_SYSC_SERDES_IF_ENET_SWR_12 = 8u,  ///< SerDes ENET Switch lane 12
    P64H_SYSC_SERDES_IF_ENET_SWR_11 = 9u,  ///< SerDes ENET Switch lane 11
    P64H_SYSC_SERDES_IF_ENET_SWR_10 = 10u, ///< SerDes ENET Switch lane 10
    P64H_SYSC_SERDES_IF_ENET_SWR_9  = 11u, ///< SerDes ENET Switch lane 9
    P64H_SYSC_SERDES_IF_ENET_SWR_8  = 12u, ///< SerDes ENET Switch lane 8
    P64H_SYSC_SERDES_IF_ENET_SWR_7  = 13u, ///< SerDes ENET Switch lane 7
    P64H_SYSC_SERDES_IF_ENET_SWR_6  = 14u, ///< SerDes ENET Switch lane 6
    P64H_SYSC_SERDES_IF_ENET_SWR_5  = 15u, ///< SerDes ENET Switch lane 5
    P64H_SYSC_SERDES_IF_ENET_SWR_4  = 16u, ///< SerDes ENET Switch lane 4
    P64H_SYSC_SERDES_IF_ENET_SWR_3  = 17u, ///< SerDes ENET Switch lane 3
    P64H_SYSC_SERDES_IF_ENET_SWR_2  = 18u, ///< SerDes ENET Switch lane 2
    P64H_SYSC_SERDES_IF_ENET_SWR_1  = 19u, ///< SerDes ENET Switch lane 1
    P64H_SYSC_SERDES_IF_ENET_SWR_0  = 20u, ///< SerDes ENET Switch lane 0
    P64H_SYSC_SERDES_IF_PCIE1_1_3   = 21u, ///< SerDes PCIe1 lane 7
    P64H_SYSC_SERDES_IF_PCIE1_1_2   = 22u, ///< SerDes PCIe1 lane 6
    P64H_SYSC_SERDES_IF_PCIE1_1_1   = 23u, ///< SerDes PCIe1 lane 5
    P64H_SYSC_SERDES_IF_PCIE1_1_0   = 24u, ///< SerDes PCIe1 lane 4
    P64H_SYSC_SERDES_IF_PCIE1_0_3   = 25u, ///< SerDes PCIe1 lane 3
    P64H_SYSC_SERDES_IF_PCIE1_0_2   = 26u, ///< SerDes PCIe1 lane 2
    P64H_SYSC_SERDES_IF_PCIE1_0_1   = 27u, ///< SerDes PCIe1 lane 1
    P64H_SYSC_SERDES_IF_PCIE1_0_0   = 28u, ///< SerDes PCIe1 lane 0
    P64H_SYSC_SERDES_IF_PCIE0_1_3   = 29u, ///< SerDes PCIe0 lane 7
    P64H_SYSC_SERDES_IF_PCIE0_1_2   = 30u, ///< SerDes PCIe0 lane 6
    P64H_SYSC_SERDES_IF_PCIE0_1_1   = 31u, ///< SerDes PCIe0 lane 5
    P64H_SYSC_SERDES_IF_PCIE0_1_0   = 32u, ///< SerDes PCIe0 lane 4
    P64H_SYSC_SERDES_IF_PCIE0_0_3   = 33u, ///< SerDes PCIe0 lane 3
    P64H_SYSC_SERDES_IF_PCIE0_0_2   = 34u, ///< SerDes PCIe0 lane 2
    P64H_SYSC_SERDES_IF_PCIE0_0_1   = 35u, ///< SerDes PCIe0 lane 1
    P64H_SYSC_SERDES_IF_PCIE0_0_0   = 36u, ///< SerDes PCIe0 lane 0
    P64H_SYSC_SERDES_IF_TRACE_1     = 37u, ///< SerDes High-speed Trace lane 1
    P64H_SYSC_SERDES_IF_TRACE_0     = 38u, ///< SerDes High-speed Trace lane 0
    P64H_SYSC_SERDES_IF_USB_0       = 8u,  ///< SerDes USB0
    P64H_SYSC_SERDES_IF_USB_1       = 2u,  ///< SerDes USB1
    P64H_SYSC_SERDES_IF_LAST        = 39u, ///< invalid, user for error checking
} p64h_sysc_serdes_if_t;

#define P64H_SYSC_SERDES_GRP_NUM_EP_GRPS()    ((uint8_t)(P64H_SYSC_SERDES_GRP_ID_ENET_EP_3 - P64H_SYSC_SERDES_GRP_ID_ENET_EP_0) + 1u)
#define P64H_SYSC_SERDES_GRP_NUM_SW_GRPS()    ((uint8_t)(P64H_SYSC_SERDES_GRP_ID_ENET_SWR_15 - P64H_SYSC_SERDES_GRP_ID_ENET_SWR_0) + 1u)
#define P64H_SYSC_SERDES_GRP_NUM_PCIE_GRPS()  ((uint8_t)(P64H_SYSC_SERDES_GRP_ID_PCIE_1_1 - P64H_SYSC_SERDES_GRP_ID_PCIE0_0) + 1u)
#define P64H_SYSC_SERDES_GRP_NUM_TRACE_GRPS() ((uint8_t)(P64H_SYSC_SERDES_GRP_ID_TRACE - P64H_SYSC_SERDES_GRP_ID_TRACE) + 1u)
#define P64H_SYSC_SERDES_GRP_NUM_USB_GRPS()   ((uint8_t)(P64H_SYSC_SERDES_GRP_ID_USB_0 - P64H_SYSC_SERDES_GRP_ID_USB_1) + 1u)
#define P64H_SYSC_SERDES_GRP_EP_OFFSET        P64H_SYSC_SERDES_GRP_ID_ENET_EP_0
#define P64H_SYSC_SERDES_GRP_SW_OFFSET        P64H_SYSC_SERDES_GRP_ID_ENET_SWR_0
#define P64H_SYSC_SERDES_GRP_PCIE_OFFSET      P64H_SYSC_SERDES_GRP_ID_PCIE0_0
#define P64H_SYSC_SERDES_GRP_TRACE_OFFSET     P64H_SYSC_SERDES_GRP_ID_TRACE
#define P64H_SYSC_SERDES_GRP_USB_OFFSET       P64H_SYSC_SERDES_GRP_ID_USB_0

/// SerDes interface rates currently encode information about the divider settings required to run at that
/// rate and also several other nice to have fields as outlined in this table
/**
 *   Macro that computes port rate value based on following format:
 *
 *   -------------------------------------------------------------------------------------------------
 *   |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
 *   |-----------------------------------------------------------------------------------------------|
 *   | Typ |Fvco | RX_REFDIV | RXPLL_FBDIV           | TXPLL_FBDIV           | BW     | RR     | PDiv|
 *   |-----------------------------------------------------------------------------------------------|
 *   | 2b  | 2b  | 4b        | 8b                    | 8b                    | 3b     |    3b  |  2b |
 *   -------------------------------------------------------------------------------------------------
 *
 *  Fields description:
 *  rate_type:   The rate type, either Native, PCIE, USB, or Trace
 *  fvco:        An enumerated type indicating the Fvco that the TXPLL is provisioned to, only matters in Native usecases
 *  rx_refdiv:   The value for the reference divider on the RX path, used for coarse clock frequency adjustment
 *  rx_fbdiv:    The value for the feedback divider on the RX path, used for fine clock frequency adjustment
 *  txpll_fbdiv: The vaule for the feedback divider at the TXPLL, used for fine clock frequency adjustment (note txpll_refdiv is mandated to be 1 on
 *               Sockeye for clock stability)
 *  buswidth:    The parallel buswidth associated with the rate, hardcoded per usecase for Sockeye
 *  rxpll_range: Rough indication of RXPLL speed, the lower the value the higher the speed
 *  tx_postdiv:  The value for the perlane postdivider associated with the rate.
 * NOTE: the value here is actually log_2(real_postdiv)
 */

typedef enum p64h_sysc_serdes_fvco_t {
    P64H_SYSC_SERDES_FVCO_OTHER = 0u, ///< Fvco is DONT_CARE (used for non-Native usecases)
    P64H_SYSC_SERDES_FVCO_5G,         ///< Fvco is 5GHz
    P64H_SYSC_SERDES_FVCO_6_25G,      ///< Fvco is 6.25GHz
    P64H_SYSC_SERDES_FVCO_5_15625G,   ///< Fvco is 5.15625GHz
    LAST_P64H_SYSC_SERDES_FVCO        ///< invalid, used for error checking
} p64h_sysc_serdes_fvco_t;

typedef enum p64h_sysc_serdes_rate_type_t {
    P64H_SYSC_SERDES_NATIVE = 0u,   ///< Native (Ethernet/AN) Rate
    P64H_SYSC_SERDES_PCIE,          ///< PCIE Rate
    P64H_SYSC_SERDES_USB,           ///< USB Rate
    P64H_SYSC_SERDES_TRACE,         ///< TRACE Rate
    P64H_SYSC_SERDES_RATE_TYPE_LAST ///< invalid, used for error checking
} p64h_sysc_serdes_rate_type_t;

/// TODO-LR: Update these to be constructed, for now values are hard calculated in Excel
typedef enum p64h_sysc_serdes_rate_t {
    P64H_SYSC_SERDES_RATE_NOT_CFG     = 0x00000000U, ///< Rate not specified
    P64H_SYSC_SERDES_RATE_1_25_ETH    = 0x1410202FU, ///< 1.25 Gbps Ethernet rate
    P64H_SYSC_SERDES_RATE_3_125_ETH   = 0x2214282AU, ///< 3.125 Gbps Ethernet rate
    P64H_SYSC_SERDES_RATE_5_ETH       = 0x11102065U, ///< 5 Gbps Ethernet rate
    P64H_SYSC_SERDES_RATE_5_15625_ETH = 0x322121C1U, ///< 5.15625 Gbps Ethernet rate
    P64H_SYSC_SERDES_RATE_10_3125_ETH = 0x312121C0U, ///< 10.3125 Gbps Ethernet rate
    P64H_SYSC_SERDES_RATE_5_AN        = 0x11102045U, ///< 5 Gbps AutoNegotiation rate
    P64H_SYSC_SERDES_RATE_6_25_AN     = 0x21142845U, ///< 6.25 Gbps AutoNegotiation rate
    P64H_SYSC_SERDES_RATE_10_3125_AN  = 0x31212180U, ///< 10.3125 Gbps AutoNegotiation rate
    P64H_SYSC_SERDES_RATE_PCIE_GEN1   = 0x421932AAU, ///< 2.5 Gbps PCIE Gen1 rate
    P64H_SYSC_SERDES_RATE_PCIE_GEN2   = 0x411932A5U, ///< 5.0 Gbps PCIE Gen2 rate
    P64H_SYSC_SERDES_RATE_PCIE_GEN3   = 0x41282880U, ///< 8.0 Gbps PCIE Gen3 rate
    P64H_SYSC_SERDES_RATE_USB3        = 0x811020A5U, ///< 5.0 Gbps USB rate
    P64H_SYSC_SERDES_RATE_12_TRACE    = 0xC13C3CA0U, ///< 12 Gbps TRACE NRZ rate
    P64H_SYSC_SERDES_RATE_16_TRACE    = 0xC15050A0U, ///< 16 Gbps TRACE NRZ rate
    P64H_SYSC_SERDES_RATE_16_80_TRACE = 0xC15050E0U, ///< 16 Gbps TRACE NRZ rate, 80 BW
    P64H_SYSC_SERDES_RATE_20_TRACE    = 0xC16464A0U, ///< 20 Gbps TRACE NRZ rate
    P64H_SYSC_SERDES_RATE_24_TRACE    = 0xC17878E0U, ///< 24 Gbps TRACE NRZ rate
    P64H_SYSC_SERDES_RATE_LAST        = 0xFFFFFFFFU  ///< invalid, used for error checking
} p64h_sysc_serdes_rate_t;

/// Enum used for decoding buswidth settings
typedef enum {
    P64H_SYSC_SERDES_BW_8 = 0u, ///< Parallel Buswidth of  8
    P64H_SYSC_SERDES_BW_10,     ///< Parallel Buswidth of 10
    P64H_SYSC_SERDES_BW_16,     ///< Parallel Buswidth of 16
    P64H_SYSC_SERDES_BW_20,     ///< Parallel Buswidth of 20
    P64H_SYSC_SERDES_BW_32,     ///< Parallel Buswidth of 32
    P64H_SYSC_SERDES_BW_40,     ///< Parallel Buswidth of 40
    P64H_SYSC_SERDES_BW_64,     ///< Parallel Buswidth of 64
    P64H_SYSC_SERDES_BW_80,     ///< Parallel Buswidth of 80
    P64H_SYSC_SERDES_BW_LAST    ///< invalid, used for error checking
} p64h_sysc_serdes_bw_t;

/// SerDes Loopback points, listed from closest to Tranceiver pins to closest to Core Logic
typedef enum p64h_sysc_serdes_lpbk_t {
    P64H_SYSC_SERDES_LPBK_DISABLED = 0u,     ///< Loopback disabled
    P64H_SYSC_SERDES_LPBK_FACILITY_SERIAL,   ///< Serial domain RX-TX loopback
    P64H_SYSC_SERDES_LPBK_FACILITY_PARALLEL, ///< Parallel domain RX-TX loopback
    P64H_SYSC_SERDES_LPBK_DIAGNOSTIC_TGATE,  ///< Transmission Gate TX-RX loopback
    P64H_SYSC_SERDES_LPBK_DIAGNOSTIC_SERIAL, ///< Serial domain TX-RX loopback
    P64H_SYSC_SERDES_LPBK_DIAGNOSTIC_WRAP,   ///< Parallel domain TX-RX loopback
    P64H_SYSC_SERDES_LPBK_LAST               ///< invalid, used for error checking
} p64h_sysc_serdes_lpbk_t;

/// TXDRV configuration
typedef struct {
    uint32_t txodrv     : 2;
    uint32_t txitrim    : 2;
    uint32_t txdrv      : 3;
    uint32_t txdrvtrim  : 24;

    uint16_t txdel      : 16;

    uint32_t txdata_inv : 8;
    uint32_t txrtrim    : 3;
} p64h_sysc_serdes_if_tx_drvr_t;

/// Both SHI and serdes_x4 have dtest bus, the following 0 - 171 are inside serdes_x4 for both dtest bus 1 and dtest bus 2, 172 - 175 are inside SHI
/// for dtestin0 bus, 176 - 182 are inside SHI for dtestin1 bus SHI clock signals can be selected from SHI dtest bus and set serdes_x4 dtest bus sel
/// to 28 or 29 serdes_x4 internal dtest mux selection for DTEST_OUT0/1, note that DTEST_IN0 is tied to 28, and DTEST_IN0 is tied to 29
typedef enum {
    P64H_SYSC_SERDES_DONE_AREA_COMPUTEA            = 0u,
    P64H_SYSC_SERDES_DONE_AREA_COMPUTEB            = 1u,
    P64H_SYSC_SERDES_DONE_AREA_COMPUTEC            = 2u,
    P64H_SYSC_SERDES_DONE_AREA_COMPUTED            = 3u,
    P64H_SYSC_SERDES_DONE_CHANNEL_ALIGNA           = 4u,
    P64H_SYSC_SERDES_DONE_CHANNEL_ALIGNB           = 5u,
    P64H_SYSC_SERDES_DONE_CHANNEL_ALIGNC           = 6u,
    P64H_SYSC_SERDES_DONE_CHANNEL_ALIGND           = 7u,
    P64H_SYSC_SERDES_DONE_CTLE_OFFSET_CALA         = 8u,
    P64H_SYSC_SERDES_DONE_CTLE_OFFSET_CALB         = 9u,
    P64H_SYSC_SERDES_DONE_CTLE_OFFSET_CALC         = 10u,
    P64H_SYSC_SERDES_DONE_CTLE_OFFSET_CALD         = 11u,
    P64H_SYSC_SERDES_DONE_DFECALA                  = 12u,
    P64H_SYSC_SERDES_DONE_DFECALB                  = 13u,
    P64H_SYSC_SERDES_DONE_DFECALC                  = 14u,
    P64H_SYSC_SERDES_DONE_DFECALD                  = 15u,
    P64H_SYSC_SERDES_DONE_FEDFE_CALA               = 16u,
    P64H_SYSC_SERDES_DONE_FEDFE_CALB               = 17u,
    P64H_SYSC_SERDES_DONE_FEDFE_CALC               = 18u,
    P64H_SYSC_SERDES_DONE_FEDFE_CALD               = 19u,
    P64H_SYSC_SERDES_DONE_FE_CALIBRATIONA          = 20u,
    P64H_SYSC_SERDES_DONE_FE_CALIBRATIONB          = 21u,
    P64H_SYSC_SERDES_DONE_FE_CALIBRATIONC          = 22u,
    P64H_SYSC_SERDES_DONE_FE_CALIBRATIOND          = 23u,
    P64H_SYSC_SERDES_DONE_FULL_CALA                = 24u,
    P64H_SYSC_SERDES_DONE_FULL_CALB                = 25u,
    P64H_SYSC_SERDES_DONE_FULL_CALC                = 26u,
    P64H_SYSC_SERDES_DONE_FULL_CALD                = 27u,
    P64H_SYSC_SERDES_DTEST_IN0                     = 28u, /// This is the serdes_x4 dtest input port
    P64H_SYSC_SERDES_DTEST_IN1                     = 29u, /// This is the serdes_x4 dtest input port
    P64H_SYSC_SERDES_PRBSERROR_DETA                = 30u,
    P64H_SYSC_SERDES_PRBSERROR_DETB                = 31u,
    P64H_SYSC_SERDES_PRBSERROR_DETC                = 32u,
    P64H_SYSC_SERDES_PRBSERROR_DETD                = 33u,
    P64H_SYSC_SERDES_RUN_AREA_COMPUTE_USERA        = 34u,
    P64H_SYSC_SERDES_RUN_AREA_COMPUTE_USERB        = 35u,
    P64H_SYSC_SERDES_RUN_AREA_COMPUTE_USERC        = 36u,
    P64H_SYSC_SERDES_RUN_AREA_COMPUTE_USERD        = 37u,
    P64H_SYSC_SERDES_RUN_CHANNEL_ALIGN_USERA       = 38u,
    P64H_SYSC_SERDES_RUN_CHANNEL_ALIGN_USERB       = 39u,
    P64H_SYSC_SERDES_RUN_CHANNEL_ALIGN_USERC       = 40u,
    P64H_SYSC_SERDES_RUN_CHANNEL_ALIGN_USERD       = 41u,
    P64H_SYSC_SERDES_RUN_FEDFE_CAL_USERA           = 42u,
    P64H_SYSC_SERDES_RUN_FEDFE_CAL_USERB           = 43u,
    P64H_SYSC_SERDES_RUN_FEDFE_CAL_USERC           = 44u,
    P64H_SYSC_SERDES_RUN_FEDFE_CAL_USERD           = 45u,
    P64H_SYSC_SERDES_RUN_FULL_CAL_USERA            = 46u,
    P64H_SYSC_SERDES_RUN_FULL_CAL_USERB            = 47u,
    P64H_SYSC_SERDES_RUN_FULL_CAL_USERC            = 48u,
    P64H_SYSC_SERDES_RUN_FULL_CAL_USERD            = 49u,
    P64H_SYSC_SERDES_RXCDRCLKA_TO_RTL              = 50u,
    P64H_SYSC_SERDES_RXCDRCLKB_TO_RTL              = 51u,
    P64H_SYSC_SERDES_RXCDRCLKC_TO_RTL              = 52u,
    P64H_SYSC_SERDES_RXCDRCLKD_TO_RTL              = 53u,
    P64H_SYSC_SERDES_RXCDRCLK_DIV2A_TO_RTL         = 54u,
    P64H_SYSC_SERDES_RXCDRCLK_DIV2B_TO_RTL         = 55u,
    P64H_SYSC_SERDES_RXCDRCLK_DIV2C_TO_RTL         = 56u,
    P64H_SYSC_SERDES_RXCDRCLK_DIV2D_TO_RTL         = 57u,
    P64H_SYSC_SERDES_RXCLK_TO_COREA_TO_RTL         = 58u,
    P64H_SYSC_SERDES_RXCLK_TO_COREB_TO_RTL         = 59u,
    P64H_SYSC_SERDES_RXCLK_TO_COREC_TO_RTL         = 60u,
    P64H_SYSC_SERDES_RXCLK_TO_CORED_TO_RTL         = 61u,
    P64H_SYSC_SERDES_RXDETOUTA                     = 62u,
    P64H_SYSC_SERDES_RXDETOUTB                     = 63u,
    P64H_SYSC_SERDES_RXDETOUTC                     = 64u,
    P64H_SYSC_SERDES_RXDETOUTD                     = 65u,
    P64H_SYSC_SERDES_RXDFECLKA_TO_RTL              = 66u,
    P64H_SYSC_SERDES_RXDFECLKB_TO_RTL              = 67u,
    P64H_SYSC_SERDES_RXDFECLKC_TO_RTL              = 68u,
    P64H_SYSC_SERDES_RXDFECLKD_TO_RTL              = 69u,
    P64H_SYSC_SERDES_RXDFECLK_DIV2A_TO_RTL         = 70u,
    P64H_SYSC_SERDES_RXDFECLK_DIV2B_TO_RTL         = 71u,
    P64H_SYSC_SERDES_RXDFECLK_DIV2C_TO_RTL         = 72u,
    P64H_SYSC_SERDES_RXDFECLK_DIV2D_TO_RTL         = 73u,
    P64H_SYSC_SERDES_RXEMCLKA_TO_RTL               = 74u,
    P64H_SYSC_SERDES_RXEMCLKB_TO_RTL               = 75u,
    P64H_SYSC_SERDES_RXEMCLKC_TO_RTL               = 76u,
    P64H_SYSC_SERDES_RXEMCLKD_TO_RTL               = 77u,
    P64H_SYSC_SERDES_RXEMCLK_DIV2A_TO_RTL          = 78u,
    P64H_SYSC_SERDES_RXEMCLK_DIV2B_TO_RTL          = 79u,
    P64H_SYSC_SERDES_RXEMCLK_DIV2C_TO_RTL          = 80u,
    P64H_SYSC_SERDES_RXEMCLK_DIV2D_TO_RTL          = 81u,
    P64H_SYSC_SERDES_RXPKDETOUTA_0                 = 82u,
    P64H_SYSC_SERDES_RXPKDETOUTA_1                 = 83u,
    P64H_SYSC_SERDES_RXPKDETOUTA_2                 = 84u,
    P64H_SYSC_SERDES_RXPKDETOUTA_3                 = 85u,
    P64H_SYSC_SERDES_RXPKDETOUTA_4                 = 86u,
    P64H_SYSC_SERDES_RXPKDETOUTA_5                 = 87u,
    P64H_SYSC_SERDES_RXPKDETOUTA_6                 = 88u,
    P64H_SYSC_SERDES_RXPKDETOUTB_0                 = 89u,
    P64H_SYSC_SERDES_RXPKDETOUTB_1                 = 90u,
    P64H_SYSC_SERDES_RXPKDETOUTB_2                 = 91u,
    P64H_SYSC_SERDES_RXPKDETOUTB_3                 = 92u,
    P64H_SYSC_SERDES_RXPKDETOUTB_4                 = 93u,
    P64H_SYSC_SERDES_RXPKDETOUTB_5                 = 94u,
    P64H_SYSC_SERDES_RXPKDETOUTB_6                 = 95u,
    P64H_SYSC_SERDES_RXPKDETOUTC_0                 = 96u,
    P64H_SYSC_SERDES_RXPKDETOUTC_1                 = 97u,
    P64H_SYSC_SERDES_RXPKDETOUTC_2                 = 98u,
    P64H_SYSC_SERDES_RXPKDETOUTC_3                 = 99u,
    P64H_SYSC_SERDES_RXPKDETOUTC_4                 = 100u,
    P64H_SYSC_SERDES_RXPKDETOUTC_5                 = 101u,
    P64H_SYSC_SERDES_RXPKDETOUTC_6                 = 102u,
    P64H_SYSC_SERDES_RXPKDETOUTD_0                 = 103u,
    P64H_SYSC_SERDES_RXPKDETOUTD_1                 = 104u,
    P64H_SYSC_SERDES_RXPKDETOUTD_2                 = 105u,
    P64H_SYSC_SERDES_RXPKDETOUTD_3                 = 106u,
    P64H_SYSC_SERDES_RXPKDETOUTD_4                 = 107u,
    P64H_SYSC_SERDES_RXPKDETOUTD_5                 = 108u,
    P64H_SYSC_SERDES_RXPKDETOUTD_6                 = 109u,
    P64H_SYSC_SERDES_RXPLL_CDRMODEA                = 110u,
    P64H_SYSC_SERDES_RXPLL_CDRMODEB                = 111u,
    P64H_SYSC_SERDES_RXPLL_CDRMODEC                = 112u,
    P64H_SYSC_SERDES_RXPLL_CDRMODED                = 113u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKDIVA_TO_RTL       = 114u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKDIVB_TO_RTL       = 115u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKDIVC_TO_RTL       = 116u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKDIVD_TO_RTL       = 117u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKREFA_TO_RTL       = 118u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKREFB_TO_RTL       = 119u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKREFC_TO_RTL       = 120u,
    P64H_SYSC_SERDES_RXPLL_CKLOCKREFD_TO_RTL       = 121u,
    P64H_SYSC_SERDES_RXPLL_FLOCKA                  = 122u,
    P64H_SYSC_SERDES_RXPLL_FLOCKB                  = 123u,
    P64H_SYSC_SERDES_RXPLL_FLOCKC                  = 124u,
    P64H_SYSC_SERDES_RXPLL_FLOCKD                  = 125u,
    P64H_SYSC_SERDES_RXPLL_LOCKA                   = 126u,
    P64H_SYSC_SERDES_RXPLL_LOCKB                   = 127u,
    P64H_SYSC_SERDES_RXPLL_LOCKC                   = 128u,
    P64H_SYSC_SERDES_RXPLL_LOCKD                   = 129u,
    P64H_SYSC_SERDES_RXPLL_REFCLK_TO_SERDESA       = 130u,
    P64H_SYSC_SERDES_RXPLL_REFCLK_TO_SERDESB       = 131u,
    P64H_SYSC_SERDES_RXPLL_REFCLK_TO_SERDESC       = 132u,
    P64H_SYSC_SERDES_RXPLL_REFCLK_TO_SERDESD       = 133u,
    P64H_SYSC_SERDES_RXSEOUTA                      = 134u,
    P64H_SYSC_SERDES_RXSEOUTB                      = 135u,
    P64H_SYSC_SERDES_RXSEOUTC                      = 136u,
    P64H_SYSC_SERDES_RXSEOUTD                      = 137u,
    P64H_SYSC_SERDES_RXSEOUT_DIVA                  = 138u,
    P64H_SYSC_SERDES_RXSEOUT_DIVB                  = 139u,
    P64H_SYSC_SERDES_RXSEOUT_DIVC                  = 140u,
    P64H_SYSC_SERDES_RXSEOUT_DIVD                  = 141u,
    P64H_SYSC_SERDES_SD_CLKA_TO_RTL                = 142u,
    P64H_SYSC_SERDES_SD_CLKB_TO_RTL                = 143u,
    P64H_SYSC_SERDES_SD_CLKC_TO_RTL                = 144u,
    P64H_SYSC_SERDES_SD_CLKD_TO_RTL                = 145u,
    P64H_SYSC_SERDES_SD_DONEA                      = 146u,
    P64H_SYSC_SERDES_SD_DONEB                      = 147u,
    P64H_SYSC_SERDES_SD_DONEC                      = 148u,
    P64H_SYSC_SERDES_SD_DONED                      = 149u,
    P64H_SYSC_SERDES_SD_RX_IDLEA                   = 150u,
    P64H_SYSC_SERDES_SD_RX_IDLEB                   = 151u,
    P64H_SYSC_SERDES_SD_RX_IDLEC                   = 152u,
    P64H_SYSC_SERDES_SD_RX_IDLED                   = 153u,
    P64H_SYSC_SERDES_TXCLK10A_TO_RTL               = 154u,
    P64H_SYSC_SERDES_TXCLK10B_TO_RTL               = 155u,
    P64H_SYSC_SERDES_TXCLK10C_TO_RTL               = 156u,
    P64H_SYSC_SERDES_TXCLK10D_TO_RTL               = 157u,
    P64H_SYSC_SERDES_TXCLK20A_TO_RTL               = 158u,
    P64H_SYSC_SERDES_TXCLK20B_TO_RTL               = 159u,
    P64H_SYSC_SERDES_TXCLK20C_TO_RTL               = 160u,
    P64H_SYSC_SERDES_TXCLK20D_TO_RTL               = 161u,
    P64H_SYSC_SERDES_TXCLKA_TO_RTL                 = 162u,
    P64H_SYSC_SERDES_TXCLKB_TO_RTL                 = 163u,
    P64H_SYSC_SERDES_TXCLKC_TO_RTL                 = 164u,
    P64H_SYSC_SERDES_TXCLKD_TO_RTL                 = 165u,
    P64H_SYSC_SERDES_TXPLL_CLKSSCG_TO_RTL          = 166u,
    P64H_SYSC_SERDES_TXPLL_FOUTAUXDIV1_TO_RTL      = 167u,
    P64H_SYSC_SERDES_TXPLL_FOUTAUXDIV2_TO_RTL      = 168u,
    P64H_SYSC_SERDES_TXPLL_FREF_CML_TO_CORE_TO_RTL = 169u,
    P64H_SYSC_SERDES_TXPLL_LOCK                    = 170u,
    P64H_SYSC_SERDES_TXPLL_REFCLK_TO_SERDES        = 171u, /// ----------- The below is from dtest bus inside SHI -----------
    P64H_SYSC_SERDES_TXCLK_MUX0
        = 172u, /// -------------- dtest_in0_shi ------------------ lane 0 ---> lane A, so TXCLK_MUX0 is the TXCLK_MUX for lane A
    P64H_SYSC_SERDES_TXCLK_MUX1    = 173u,
    P64H_SYSC_SERDES_TXCLK_MUX2    = 174u,
    P64H_SYSC_SERDES_TXCLK_MUX3    = 175u, /// -------------- dtest_in0_shi ----------------------
    P64H_SYSC_SERDES_PRE_LP_RXCLK0 = 176u, /// -------------- dtest_in1_shi ----------------------
    P64H_SYSC_SERDES_PRE_LP_RXCLK1 = 177u,
    P64H_SYSC_SERDES_PRE_LP_RXCLK2 = 178u,
    P64H_SYSC_SERDES_PRE_LP_RXCLK3 = 179u,
    P64H_SYSC_SERDES_PIPE_CLK_EXT  = 180u,
    P64H_SYSC_SERDES_DTEST_IN0_SHI = 181u, /// This is the SHI_SOK input port
    P64H_SYSC_SERDES_DTEST_IN1_SHI = 182u  /// This is the SHI_SOK input port
} p64h_sysc_serdes_dtest_sel_t;

/// RX Calibration sequence options
typedef enum {
    P64H_SYSC_SERDES_RXCALIB_END_OF_SEQ = 0u,     ///< 0x0: End of sequence - termination code
    P64H_SYSC_SERDES_RXCALIB_DCOS_CAL,            ///< 0x1: DC-offset Calibration
    P64H_SYSC_SERDES_RXCALIB_CH_ALIGN,            ///< 0x2: Channel Alignment
    P64H_SYSC_SERDES_RXCALIB_SINGLE_EYE_FOM,      ///< 0x3: Single Eye FOM
    P64H_SYSC_SERDES_RXCALIB_DFE_EM_RECENTER,     ///< 0x4: DFE and EM path re-centering
    P64H_SYSC_SERDES_RXCALIB_CTLE_CAL,            ///< 0x5: CTLE calibration
    P64H_SYSC_SERDES_RXCALIB_H1_FINE_TUNE,        ///< 0x6: H1 fine tuning
    P64H_SYSC_SERDES_RXCALIB_H2_H4_ISI,           ///< 0x7: H2-4 ISI pre-set
    P64H_SYSC_SERDES_RXCALIB_H1_H11_REFLECT,      ///< 0x8: H5-11 reflections search
    P64H_SYSC_SERDES_RXCALIB_H1_H11_1_BY_1,       ///< 0x9: H2-11 one-by-one pre-set
    P64H_SYSC_SERDES_RXCALIB_DFE_MANUAL,          ///< 0xA: DFE manual pre-set run
    P64H_SYSC_SERDES_RXCALIB_DFE_FINE_TUNE,       ///< 0xB: DFE fine-tuning (gradient descent algorithm)
    P64H_SYSC_SERDES_RXCALIB_DFE_BACKGROUND,      ///< 0xC: DFE background calibration
    P64H_SYSC_SERDES_RXCALIB_SWITCH_EYE_FOM_FULL, ///< 0xD: Eye FOM switch to full area
    P64H_SYSC_SERDES_RXCALIB_LAST                 ///< invalid, used for error checking
} p64h_sysc_serdes_rx_calib_code_t;

/// SerDes TX Datapath Sources
typedef enum {
    P64H_SYSC_SERDES_TX_DP_SRC_DP = 0u, ///< 0b00: Tx Datapath
    P64H_SYSC_SERDES_TX_DP_SRC_SQL,     ///< 0b01: Static Squelch Registers
    P64H_SYSC_SERDES_TX_DP_SRC_PATTGEN, ///< 0b10: Pattern Generator
    P64H_SYSC_SERDES_TX_DP_SRC_ANLT,    ///< 0b11: ANLT Submodule
    P64H_SYSC_SERDES_TX_DP_SRC_LAST     ///< invalid, used for error checking
} p64h_sysc_serdes_tx_dp_src_t;

/// SerDes RX Datapath Sources
typedef enum {
    P64H_SYSC_SERDES_RX_DP_SRC_CDR = 0u, ///< 0b00: RX Clock and Data Recovery path (used for <=5Gbps)
    P64H_SYSC_SERDES_RX_DP_SRC_DFE,      ///< 0b01: RX Decision Feedback Equalizer path (used for > 5Gbps)
    P64H_SYSC_SERDES_RX_DP_SRC_EM,       ///< 0b10: RX Eye Monitor path (only used for debugging EM operation)
    P64H_SYSC_SERDES_RX_DP_SRC_LAST      ///< invalid, used for error checking
} p64h_sysc_serdes_rx_dp_src_t;

/// Select for what source to use for TXPLL Reference Clock
typedef enum {
    P64H_SYSC_SERDES_REFCLK_SEL_TXPLL_FREF_FROM_CORE = 0u, ///< 0b000: Coreside Reference Clock
    P64H_SYSC_SERDES_REFCLK_SEL_CLKBUF_IOA_DI_P,           ///< 0b001: Clock Receiver Pad, Positive terminal
    P64H_SYSC_SERDES_REFCLK_SEL_CLKBUF_IOA_DI_N,           ///< 0b010: Clock Receiver Pad, Negative terminal
    P64H_SYSC_SERDES_REFCLK_SEL_RXPLL_REFCLKA,             ///< 0b011: RXPLL Reference Clock for Lane A
    P64H_SYSC_SERDES_REFCLK_SEL_RXPLL_REFCLK_TO_SERDES_A,  ///< 0b100: RXPLL Reference Clock, after RXPLL muxing, for Lane A
    P64H_SYSC_SERDES_REFCLK_SEL_LAST                       ///< invalid, used for error checking
} p64h_sysc_serdes_txrefclk_sel_t;

/// Select for what should be presented on the Reference Clock Mux Logic outputs of the SerDes
typedef enum {
    P64H_SYSC_SERDES_REFCMLOUT_SEL_TXREFCLK_CORE = 0u, ///< 0b000: TXPLL Reference Clock, as presented to coreside logic
    P64H_SYSC_SERDES_REFCMLOUT_SEL_RESERVED1,          ///< 0b001: Reserved
    P64H_SYSC_SERDES_REFCMLOUT_SEL_CLKBUF_IOA_DIA_P,   ///< 0b010: Clock Receiver Pad, Positive terminal
    P64H_SYSC_SERDES_REFCMLOUT_SEL_CLKBUF_IOA_DIA_N,   ///< 0b011: Clock Receiver Pad, Negative terminal
    P64H_SYSC_SERDES_REFCMLOUT_SEL_REFCMLIN_R,         ///< 0b100: Rightside Reference Clock Mux Logic Input
    P64H_SYSC_SERDES_REFCMLOUT_SEL_RESERVED5,          ///< 0b101: Reserved
    P64H_SYSC_SERDES_REFCMLOUT_SEL_RESERVED6,          ///< 0b110: Reserved
    P64H_SYSC_SERDES_REFCMLOUT_SEL_REFCMLIN_L,         ///< 0b111: Leftside Reference Clock Mux Logic Input
    P64H_SYSC_SERDES_REFCMLOUT_SEL_LAST                ///< invalid, used for error checking
} p64h_sysc_serdes_refcmlout_sel_t;

/// The three different accepted Trim Resistor settings that PE will have calibrated for
typedef enum {
    P64H_SYSC_SERDES_RTRIM_85_OHM = 0u, ///< 85  Ohm Setting
    P64H_SYSC_SERDES_RTRIM_100_OHM,     ///< 100 Ohm Setting
    P64H_SYSC_SERDES_RTRIM_150_OHM,     ///< 150 Ohm Setting
    P64H_SYSC_SERDES_RTRIM_LAST,        ///< invalid, used for error checking
} p64h_sysc_serdes_rtrim_t;

/// Pattern Generator/Monitor Mode of Operation
typedef enum {
    P64H_SYSC_SERDES_PATTMODE_PRBS5 = 0u, ///< PRBS5
    P64H_SYSC_SERDES_PATTMODE_PRBS7,      ///< PRBS7
    P64H_SYSC_SERDES_PATTMODE_PRBS11,     ///< PRBS11
    P64H_SYSC_SERDES_PATTMODE_PRBS15,     ///< PRBS15
    P64H_SYSC_SERDES_PATTMODE_PRBS20,     ///< PRBS20
    P64H_SYSC_SERDES_PATTMODE_PRBS23,     ///< PRBS23
    P64H_SYSC_SERDES_PATTMODE_PRBS31,     ///< PRBS31
    P64H_SYSC_SERDES_PATTMODE_PRBS9,      ///< PRBS9
    P64H_SYSC_SERDES_PATTMODE_CJPAT,      ///< CJPAT
    P64H_SYSC_SERDES_PATTMODE_CJTPAT,     ///< CJTPAT
    P64H_SYSC_SERDES_PATTMODE_UNUSED10,   ///< UNUSED10
    P64H_SYSC_SERDES_PATTMODE_UNUSED11,   ///< UNUSED11
    P64H_SYSC_SERDES_PATTMODE_UNUSED12,   ///< UNUSED12
    P64H_SYSC_SERDES_PATTMODE_UNUSED13,   ///< UNUSED13
    P64H_SYSC_SERDES_PATTMODE_UNUSED14,   ///< UNUSED14
    P64H_SYSC_SERDES_PATTMODE_USER,       ///< User Specified Pattern
    P64H_SYSC_SERDES_PATTMODE_LAST        ///< invalid, used for error checking
} p64h_sysc_serdes_pattgenmon_mode_t;

/// Configuration values for PRBS generator/monitor housed within the PMA macro
typedef enum {
    P64H_SYSC_SERDES_PMA_PRBS7 = 0u, ///< PRBS 7
    P64H_SYSC_SERDES_PMA_PRBS9,      ///< PRBS 9
    P64H_SYSC_SERDES_PMA_PRBS15,     ///< PRBS 15
    P64H_SYSC_SERDES_PMA_PRBS23,     ///< PRBS 23
    P64H_SYSC_SERDES_PMA_PRBS31,     ///< PRBS 31
    P64H_SYSC_SERDES_PMA_PRBS_LAST   ///< invalid, used for error checking
} p64h_sysc_serdes_pma_prbs_poly_t;

/// Error Injection Mode of Operation
typedef enum {
    P64H_SYSC_SERDES_ERR_INJ_SINGLE = 0u, ///< Single-Shot error for one parallel word
    P64H_SYSC_SERDES_ERR_INJ_CONT,        ///< Continuous error injection mode, will inject until turned off
    P64H_SYSC_SERDES_ERR_INJ_LAST         ///< invalid, used for error checking
} p64h_sysc_serdes_err_inj_mode_t;

/**  @brief Refclk Resistor Termination Target Select
 *   @note RTT_NCOMP will be 0 when Termination Resistor is < Target and 1 when > Target
 */
typedef enum {
    P64H_SYSC_SERDES_RTT_DISABLE = 0u, ///< 0b00: Resistor Termination Disabled
    P64H_SYSC_SERDES_RTT_85_OHM,       ///< 0b01: Target is 85 Ohms
    P64H_SYSC_SERDES_RTT_100_OHM,      ///< 0b10: Target is 100 Ohms
    P64H_SYSC_SERDES_RTT_150_OHM,      ///< 0b11: Target is 150 Ohms
    P64H_SYSC_SERDES_RTT_LAST          ///< invalid, used for error checking
} p64h_sysc_serdes_rtt_prog_t;

/// Transition Conditioner Status
typedef enum {
    P64H_SYSC_SERDES_TRANSCOND_NOT_CFG = 0, ///< Transition Conditioner is not currently configured/enabled
    P64H_SYSC_SERDES_TRANSCOND_NORMAL,      ///< Databus is not all stuck at one value
    P64H_SYSC_SERDES_TRANSCOND_STUCK_AT_0,  ///< Databus is stuck at all 0's
    P64H_SYSC_SERDES_TRANSCOND_STUCK_AT_1,  ///< Databus is stuck at all 1's
    P64H_SYSC_SERDES_TRANSCOND_LAST,        ///< invalid, used for error checking
} p64h_sysc_serdes_transcond_stat_t;

/// serdes group attributes
typedef struct {
    p64h_sysc_serdes_grp_id_t name;                                           ///< SerDes group name
    uint8_t                   num_lanes;                                      ///< Number of lanes in group
    p64h_sysc_serdes_if_t   serdes_lanes[P64H_SYSC_SERDES_MAX_NUM_GRP_LANES]; ///< SerDes group lane(s) (should match naming of p64h_sysc_serdes_if_t)
    p64h_sysc_serdes_rate_t rate;                                             ///< SerDes group Configured Rate (either user specified or AN'd to)
    p64h_sysc_serdes_rate_t an_rates[P64H_SYSC_SERDES_MAX_NUM_AN_RATES];      ///< SerDes group AutoNegotiation Rates
} p64h_sysc_serdes_grp_attr_t;

// TODO-LR update the following structs as AN/LT driver is written
/// serdes group AN/LT configuration (only relevant for single lane links)
typedef struct {
    bool                    an_enabled;                                        ///< Whether or not a lane is AN enabled
    bool                    lt_enabled;                                        ///< Whether or not a lane is LT enabled
    p64h_sysc_serdes_rate_t possible_rates[P64H_SYSC_SERDES_MAX_NUM_AN_RATES]; ///< The list of rates we can AN to
} p64h_sysc_serdes_grp_anlt_cfg_t;

/// serdes group AN/LT diagnostic status (only relevant for single lane links)
typedef struct {
    bool                    an_running;      ///< Whether Auto Negotiation is currently running
    bool                    lt_running;      ///< Whether Link Training is currently running
    bool                    an_complete;     ///< Whether Auto Negotiation has completed
    bool                    lt_complete;     ///< Whether Link Trainiing has completed
    p64h_sysc_serdes_rate_t negotiated_rate; ///< The rate ultimately determined via AN
} p64h_sysc_serdes_grp_anlt_diag_t;

typedef struct {
    p64h_sysc_serdes_bank_t bank;
    uint32_t                lane;
} p64h_sysc_serdes_if_info_t;

/// SerDes interface configuration
typedef struct {
    p64h_sysc_serdes_if_t   serdes_if;                                   ///< SerDes interface
    p64h_sysc_serdes_rate_t rate;                                        ///< SerDes rate
    bool                    an_enabled;                                  ///< Flag for if we can run AN
    p64h_sysc_serdes_rate_t an_rates[P64H_SYSC_SERDES_MAX_NUM_AN_RATES]; ///< Possible rates that may be AN'd to
} p64h_sysc_serdes_if_cfg_t;

/// serdes group configuration
typedef struct {                                                        // num_lanes = 0 means not active
    uint8_t                   num_lanes;                                ///< Number of lanes in the group, must be 1,2,4, or 8
    p64h_sysc_serdes_if_cfg_t lane[P64H_SYSC_SERDES_MAX_NUM_GRP_LANES]; ///< Configuration objects for each lane in the group
} p64h_sysc_serdes_grp_cfg_t;

typedef struct __attribute__((packed)) {
    uint32_t postdiv      : 2;          ///< LogBase2(TX Perlane Postdivider setting)
    uint32_t rxpll_range  : 3;          ///< RXPLL Range (internal RXPLL parameter) setting
    uint32_t buswidth     : 3;          ///< Parallel buswidth encoding
    uint32_t txpll_fbdiv  : 8;          ///< TXPLL Feedback Divider setting (note txpll_refdiv is always 1)
    uint32_t rxpll_fbdiv  : 8;          ///< RXPLL Feedback Divider setting
    uint32_t rxpll_refdiv : 4;          ///< RXPLL Reference Divider setting
    uint32_t fvco         : 2;          ///< FVco encoding
    uint32_t rate_type    : 2;          ///< serdes rate type, NATIVE, PCIE, USB, or TRACE
} p64h_sysc_serdes_rate_info_decoded_t; ///< bit encoded fields of rate enum

/// SerDes Rate info struct that we can populate by decoding the enum
typedef union __attribute__((packed)) {
    uint32_t                             w; ///< whole rate enum
    p64h_sysc_serdes_rate_info_decoded_t b; ///< bit encoded fields of rate enum
} p64h_sysc_serdes_rate_info_t;

/// Bit packed struct that contains all fields relevant for dLOS
typedef union {
    uint32_t w; ///< access 32 bit register
    struct {
        uint32_t txpll_lock         : 1; ///< Bit 0
        uint32_t rxpll_lock         : 1; ///< Bit 1
        uint32_t rxpll_flock        : 1; ///< Bit 2
        uint32_t fsd                : 1; ///< Bit 3
        uint32_t rx_calib_status    : 1; ///< Bit 4
        uint32_t chalign_success    : 1; ///< Bit 5
        uint32_t chalign_fail       : 1; ///< Bit 6
        uint32_t ctle               : 1; ///< Bit 7
        uint32_t dfe                : 1; ///< Bit 8
        uint32_t cdr_lock           : 1; ///< Bit 9
        uint32_t rfd                : 1; ///< Bit 10
        uint32_t rfd_lock           : 1; ///< Bit 11
        uint32_t loss_detect        : 1; ///< Bit 12
        uint32_t rx_bg_calib_status : 1; ///< Bit 13
        uint32_t pad14_31           : 18;
    } b; ///< access bit fields
} p64h_sysc_serdes_dlos_cond_t;

/// serdes pattgen configuration
typedef struct {
    p64h_sysc_serdes_pattgenmon_mode_t mode;                                      ///< Pattgen Mode
    uint8_t                            user_pattbytes[PATTGEN_USR_PAT_NUM_BYTES]; ///< User Pattern
} p64h_sysc_serdes_pattgen_cfg_t;

/// serdes pattmon configuration
typedef struct {
    p64h_sysc_serdes_pattgenmon_mode_t mode;                                      ///< Pattmon Mode
    uint8_t                            user_pattbytes[PATTMON_USR_PAT_NUM_BYTES]; ///< User Pattern
    uint32_t                           upper_bound;                               ///< Upper Bound on errors to be considered a success
    uint32_t                           lower_bound;                               ///< Lower Bound on errors to be considered a success
} p64h_sysc_serdes_pattmon_cfg_t;

/// serdes group pattmon synchronization status
typedef struct {
    bool    chk_limit_pass; ///< Whether we are within the bounds of a pass
    int32_t err_cnt;        ///< Error count, which also encodes some failure conditions
                            ///< -1: Checker not enabled
                            ///< -2: Checker waiting for pattern lock
} p64h_sysc_serdes_pattmon_sync_t;

/// serdes group error injection configuration
typedef struct {
    p64h_sysc_serdes_err_inj_mode_t mode;                         ///< Error injection mode
    uint8_t                         mask[ERR_INJ_MODE_NUM_BYTES]; ///< 80-bit Error injection mask
} p64h_sysc_serdes_err_inj_cfg_t;

/// serdes group squelch configuration
typedef struct {
    uint8_t pattbytes[SQUELCH_NUM_BYTES]; ///< 80-bit squelch pattern
} p64h_sysc_serdes_squelch_patt_t;

/// serdes group dlos configuration
typedef struct {
    bool                         sql_en; ///< DLOS Squelch Enable
    bool                         inv;    ///< DLOS inversion setting
    p64h_sysc_serdes_dlos_cond_t en;     ///< Contributor Enables for each dlos
    p64h_sysc_serdes_dlos_cond_t byp;    ///< Contributor Bypass for sticky bit logic
    p64h_sysc_serdes_dlos_cond_t clr;    ///< Sticky-Bit clear for each contributor
} p64h_sysc_serdes_dlos_cfg_t;

/// serdes rx calibration status
typedef struct {
    uint64_t cal_time_us;  ///< calibration time in microseconds
    bool     cal_complete; ///< calibration completion status
    bool     align_failed; ///< whether we succeeded in aligning EM and DFE paths
    uint32_t eye_area;     ///< eye area at end of calibration
                           ///< Nonzero value: Calibration successful
                           ///< 0: Eye Closed Calibration failed
    /// Add more status that may be useful for debug
    uint32_t offset_cdr;           ///< DC Calibration offset for the CDR CTLE
    uint32_t eye_center_vertical;  ///< Vertical (DC-offset) center of the Eye openning
    uint32_t eye_cener_horizontal; ///< Horizontal (Phase) center of the Eye openning.
    uint32_t choice_dfeem; ///< Look-up table index for the CDR CTLE setting chosen by FE Calibration. The DFE/EM CTLE settings are selected by the
                           ///< combination of frequency (set by user) and by choice_dfeem (Chosen by FE Calibration)
    uint32_t choice_cdr;   ///< Look-up table index for the CDR CTLE setting chosen by FE Calibration. The CDR CTLE settings are selected by the
                           ///< combination of frequency (set by user) and by choice_cdr (Chosen by FE Calibration)

    uint32_t offset_dfe; ///< DC Calibration offset for the DFE CTLE

    uint32_t phase_dfe; ///< Phase of the sampling clock in the DFE receiver
    uint32_t offset_em; ///< DC Calibration offset for the EM CTLE

    uint32_t phase_em; ///< Phase of the sampling clock in the DFE receiver

    uint32_t cdr_h0; ///< Actual H0 position for CDR path

} p64h_sysc_serdes_rx_calib_stat_t;

/// serdes diagnostic values that may want to be measured over some window interval
typedef struct {
    uint32_t window_width;   ///< Number of samples to take for diagnostic. If left at zero, P64H_SERDES_DIAG_WINDOW_MAX samples will be taken
    uint32_t txpll_lock_cnt; ///< Count over diagnostic window where TXPLL was locked
    uint32_t rxpll_lock_cnt; ///< Count over diagnostic window where RXPLL was locked
    uint32_t dlos_cnt;       ///< Count over diagnostic window where DLOS was asserted
    uint32_t pkdetout_tot;   ///< Total value of the Peak Detector (input to Signal Detector) over all samples over the window
    uint32_t pkdetout_hist[P64H_SYSC_SERDES_NUM_PKDETOUT_VALS]; ///< Histogram of recoreded Peak Detector Outputs over the window
} p64h_sysc_serdes_diag_window_t;

/// Reference Clock Mux Logic Select Configuration
typedef struct {
    p64h_sysc_serdes_refcmlout_sel_t out_sel; ///< Source for REFCML Output
    bool                             out_en;  ///< Output Enable
    bool                             in_en;   ///< Input Enable
} p64h_sysc_serdes_refcml_cfg_t;

/// Reference Clock Configuration Object
typedef struct {
    p64h_sysc_serdes_txrefclk_sel_t txrefclk_sel;     ///< Clock select for TXPLL Refclk
    p64h_sysc_serdes_refcml_cfg_t   refcml_r;         ///< Rightside Reference Clock Mux Logic config
    p64h_sysc_serdes_refcml_cfg_t   refcml_l;         ///< Leftside Reference Clock Mux Logic config
    p64h_sysc_serdes_rtt_prog_t     rtt_current_prog; ///< Reference Clock Resistor Termination Target Select
    uint8_t                         rtt_cal_term;     ///< Resistor Termination Calibration Resistance Selection
} p64h_sysc_serdes_refclk_cfg_t;

/// serdes perlane runtime configuration
typedef struct {
    uint32_t                     mask; ///< One-hot Mask for what fields to configure

    p64h_sysc_serdes_tx_dp_src_t tx_dp_src;           ///< TX Datapath Source, valid options are
                                                      ///< 0b00: TX Datapath
                                                      ///< 0b01: Static Squelch
                                                      ///< 0b10: Pattern Generator
                                                      ///< 0b11: ANLT Submodule
    p64h_sysc_serdes_pattgen_cfg_t  tx_pattgen_cfg;   ///< Pattern Generation Configuration
    bool                            tx_pattgen_en;    ///< Pattern Generation Enable
    p64h_sysc_serdes_err_inj_cfg_t  tx_err_inj_cfg;   ///< Error Injection Configruation
    bool                            tx_err_inj_en;    ///< Error Injection Enable
    p64h_sysc_serdes_squelch_patt_t tx_squelch_patt;  ///< Squelch Pattern
    bool                            tx_squelch_en;    ///< Squelch Enable
    bool                            tx_hw_squelch_en; ///< TX HW Squelch Enable (requires Pattgen to be configured)
    bool                            tx_transcond_en;  ///< Transmission Condition (stuck at value) Checker Enable
    bool                            tx_invert_en;     ///< Invert Enable for Datapath

    p64h_sysc_serdes_rx_dp_src_t    rx_dp_src;         ///< RX Datapath Source, normally dictated by rate but can be
                                                       ///< overridden by user if required. Valid options are
                                                       ///< 0b00: Clock and Data Recovery (CDR) path (=<5Gbps)
                                                       ///< 0b01: Decision Feedback Equalizer (DFE) path (>5Gbps)
                                                       ///< 0b10: Eye Monitor (only used for debugging eye measurements)
    uint64_t                        rx_calib_code_seq; ///< Current Receiver Calibration Code
    bool                            rx_calib_run;      ///< Calibration Run, self clearing, set to 1 to trigger manual calibration
    p64h_sysc_serdes_pattmon_cfg_t  rx_pattmon_cfg;    ///< Pattern Monitor Configuration
    bool                            rx_pattmon_en;     ///< Pattern Monitor Enable
    p64h_sysc_serdes_err_inj_cfg_t  rx_err_inj_cfg;    ///< Error Injection Configuration
    bool                            rx_err_inj_en;     ///< Error Injection Enable
    p64h_sysc_serdes_squelch_patt_t rx_squelch_patt;   ///< Squelch Pattern
    bool                            rx_squelch_en;     ///< Squelch Enable
    bool                            rx_fsd_continuous; ///< Fast Signal Detect Configuration set to
                                                       ///< 0: One time measurement
                                                       ///< 1: Continuous measurement (required for DLOS)
    bool                          rx_fsd_en;           ///< Fast Signal Detect Enable
    bool                          rx_invert_en;        ///< Invert Enable
    bool                          refclk_en;           ///< TXPLL refclk receiver enable for the lane

    p64h_sysc_serdes_dlos_cfg_t   dlos; ///< DLOS configuration for the lane

    p64h_sysc_serdes_lpbk_t       lpbk; ///< Loopback point (if specified) for the lane

    p64h_sysc_serdes_if_tx_drvr_t tx_drvr; ///< TX driver configuration for the lane

    p64h_sysc_serdes_dtest_sel_t  dtest_sel; ///< dtest_sel for DTEST bus for the lane

    uint8_t                       rxrtrim; ///< Trim resistance value to set for the RX path
} p64h_sysc_serdes_if_rt_cfg_t;

/// serdes grp peripheral configuration
typedef struct {
    uint8_t                      mask;                                     ///< One-hot Mask for which lanes to consider
    uint8_t                      num_lanes;                                ///< Number of lanes in the Group
    p64h_sysc_serdes_if_rt_cfg_t lane[P64H_SYSC_SERDES_MAX_NUM_GRP_LANES]; ///< Peripheral configuration for each lane in the group
} p64h_sysc_serdes_grp_runtim_cfg_t;

/// serdes perlane diagnostics
typedef struct {
    uint8_t                           mask;       ///< One-hot mask for what fields to return
    p64h_sysc_serdes_rate_t           rate;       ///< Current Rate SerDes is Configured to
    bool                              txpll_lock; ///< Current TXPLL lock status
    p64h_sysc_serdes_transcond_stat_t transcond;  ///< Current Transition Conditioner Status possible values are
                                                  ///< NOT_CFG: Transition Conditioner is not configured on current lane
                                                  ///< NORMAL: Databus is not stuck at a value
                                                  ///< STUCK_AT_0: Databus is stuck at zero
                                                  ///< STUCK_AT_1: Databus is stuck at 1
    bool                             dlos;        ///< Current status of DLOS for the lane
    p64h_sysc_serdes_pattmon_sync_t  pattmon;     ///< Current Pattern Monitor status for the lane
    p64h_sysc_serdes_rx_calib_stat_t rx_calib;    ///< Current Rx Calibration status for the lane
    p64h_sysc_serdes_diag_window_t   window;
} p64h_sysc_serdes_if_diag_t;

/// serdes group diagnostic
typedef struct {
    p64h_sysc_serdes_grp_id_t  name;                                     ///< SerDes group name
    uint8_t                    mask;                                     ///< One-hot Mask for which lanes to consider
    uint8_t                    num_lanes;                                ///< Number of lanes in the group, must be 1,2,4, or 8
    p64h_sysc_serdes_if_diag_t lane[P64H_SYSC_SERDES_MAX_NUM_GRP_LANES]; ///< Status for each lane in the group
} p64h_sysc_serdes_grp_diag_t;

/// Combine 3 refclk config regsiters into one
typedef struct {
    uint32_t refclk_cfg_70_64;
    uint32_t refclk_cfg_64_32;
    uint32_t refclk_cfg_31_0;
} p64h_sysc_serdes_refclk_t;

#endif // P64H_SYSC_SERDES_TYPES_H

/// @}
