/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file sysc_shared_periph_ba.h
 * @brief
 * SYSC shared peripheral types
 * @addtogroup Sysc_Peripherals
 * @{
 */

/* Public Defines ------------------------------------------------- */

#ifndef P64H_SYSC_SHARED_PERIPH_BA_H
#define P64H_SYSC_SHARED_PERIPH_BA_H

#include "p64h_sysc_shared_ba.h"
#include <generated/p64h_sysc_ddr_defs.h>

/// number of IPC instance
#define APPC_PERIPH_IPC_INST_NUM 2u
/// number of channels for IPC
#define APPC_PERIPH_IPC_NUM_CHNL 32u
/// number of links for a single PCIe/CXL subsystem instance
#define APPC_PERIPH_PCIE_NUM_LINKS 2u
/// number of PCIe/CXL subsystem instance
#define APPC_PERIPH_PCIE_INST_NUM 2u
/// number of channels for PIE
#define APPC_PERIPH_PIE_NUM_CHNL 32u
/// number of channels for RDMA
#define APPC_PERIPH_RDMA_NUM_CHNL 32u
/// number of PIE inst
#define APPC_PERIPH_PIE_INST_NUM 2u
/// number of RDMA inst
#define APPC_PERIPH_RDMA_INST_NUM 2u
/// number of channels for DMA
#define APPC_PERIPH_DMA_NUM_CHNL 8u
/// number of ENET end-point instance
#define APPC_PERIPH_ENET_EP_INST_NUM 4u
/// number of GPIO blocks
#define APPC_PERIPH_GPIO_BLOCK_NUM 2u
/// number of channels for GPIO
#define APPC_PERIPH_GPIO_NUM_CHNL 32u
/// number of high performance timers
#define APPC_PERIPH_HPT_INST_NUM 8u
/// number of watchdog timers
#define APPC_PERIPH_WDT_INST_NUM 8u
/// number of NMRA instance
#define APPC_PERIPH_NMRA_INST_NUM 2u
/// number of comparator of each NMRA instance
#define APPC_PERIPH_NMRA_COMPARATOR_NUM 4u
/// number of replica per comparator
#define APPC_PERIPH_NMRA_REPLICA_NUM 5u
/// number of spacewire instances
#define APPC_PERIPH_SPW_INST_NUM 7u
/// number of i2c instances
#define APPC_PERIPH_I2C_INST_NUM 4u
/// number of uart instances
#define APPC_PERIPH_UART_INST_NUM 4u
/// number of mdio instances
#define APPC_PERIPH_MDIO_INST_NUM 2u
/// number of usb instances
#define APPC_PERIPH_USB_INST_NUM 2u
/// number of spi instances
#define APPC_PERIPH_SPI_INST_NUM 2u
/// number of APPDMA instances
#define APPC_PERIPH_APP_DMA_INST_NUM 2u
/// number of IOMMU instances
#define APPC_PERIPH_IOMMU_INST_NUM 2u
/// number of OCR instances
#define APPC_PERIPH_OCR_INST_NUM 2u

/// number of NVM controller instances
#define APPC_PERIPH_NVM_CTRL_INST_NUM 4u
/// number of NVM EDAC instances
#define APPC_PERIPH_NVM_EDAC_INST_NUM 2u
/// number of NVM IOB instances
#define APPC_PERIPH_NVM_IOB_INST_NUM 4u
/// number of spacewire iobridge instances
#define APPC_PERIPH_SPW_IOB_INST_NUM 2u
/// Number of SpW router logical addresses
#define APP_PERIPH_SPW_ROUTER_TABLE_MAX 223u
/// Total number of 32 bit PMP addr There is a total of 8 supported PMP addrs Each PMP addr consists of 32 bit LSB and MSB.
#define IOBRIDGE_PMP_ADDR_NUM 16u
/// Number of SerDes interfaces
#define SHI_NUM 11u
/// Number of SHI instances
#define SERDES_LANE_NUM 4u
/// Number of GPIO_OUT_MUX instances
#define APPC_PERIPH_GPIO_OUT_MUX_INST_NUM 64u
/// Number of GPIO_IN_MUX instances
#define APPC_PERIPH_GPIO_IN_MUX_INST_NUM 32u

/* Public Structs and Enums --------------------------------------- */

/// DDR configuration
typedef struct {
    bool enabled;     ///< true - DDR is required; false - DDR is not required
    bool interleaved; ///< true - Interleave mode is enabled; false - Interleave mode is disabled
    bool shared;      ///< true - Share mode is enabled; false - Share mode is disabled
    bool swapped;     ///< true - Swap mode is enabled; false - Swap mode is disabled
} p64h_sysc_appc_ddr_cfg_t;

/// Mask for enabling peripherals. Also used for defining DDR and FP Access Peripherals listed below are initiators on the appnoc
typedef struct {
    uint64_t pcie         : 2;  ///< PCIE Instances
    uint64_t enet_ep      : 4;  ///< ENET_EP Instances
    uint64_t enet_rdma_qp : 2;  ///< RDMA_QP Instances
    uint64_t enet_pie     : 2;  ///< PIE Instances
    uint64_t appdma       : 2;  ///< DMA Instances
    uint64_t user_crypto  : 2;  ///< USER_CRYPTO Instances
    uint64_t nand         : 2;  ///< NAND Instances
    uint64_t nor          : 2;  ///< NOR Instances
    uint64_t iommu        : 2;  ///< IOMMU Instances
    uint64_t spw          : 1;  ///< SPW instances
    uint64_t usb          : 2;  ///< USB instances
    uint64_t fill_30_64   : 35; ///< Padding
} p64h_sysc_appc_periph_initiator_inst_t;

///  Mask for enabling other peripherals.
typedef struct {
    uint64_t wdog       : 8;  ///< WDOG instances
    uint64_t timer      : 8;  ///< TIMER instances
    uint64_t uart       : 4;  ///< UART instances
    uint64_t i2c        : 4;  ///< I2C instances
    uint64_t gpio       : 3;  ///< GPIO instances
    uint64_t mdio       : 2;  ///< MDIO instances
    uint64_t enet_sw    : 1;  ///< ENET_SW instance
    uint64_t spi        : 2;  ///< SPI instances
    uint64_t ocr        : 2;  ///< OCR instances
    uint64_t ddr        : 2;  ///< DDR instances
    uint64_t nvm        : 4;  ///< NVM instances
    uint64_t ipc        : 2;  ///< IPC instances
    uint64_t jtag_host  : 1;  ///< JTAG_HOST instance
    uint64_t nmra       : 2;  ///< NMRA instances
    uint64_t boot_stat  : 8;  ///< Boot stat instances
    uint64_t trace      : 1;  ///< Boot stat instances
    uint64_t fill_52_64 : 12; ///< Padding
} p64h_sysc_appc_periph_subordinate_inst_t;

/// Define channels used by an application
typedef struct {
    uint64_t ipc_0;          ///< IPC instance 0, support 32 channels
    uint64_t ipc_1;          ///< IPC instance 1, support 32 channels
    uint32_t enet_rdma_qp_0; ///< RDMA instance 0, support 128 queue pairs (to be reviewed)
    uint32_t enet_rdma_qp_1; ///< RDMA instance 1, support 128 queue pairs (to be reviewed)
    uint32_t enet_pie_0;     ///< Packet Insert/Extract RDMA instance 0, support 32 channels
    uint32_t enet_pie_1;     ///< Packet Insert/Extract RDMA instance 1, support 32 channels
    uint32_t appdma_0;       ///< App DMA instance 0, support 8 channel
    uint32_t appdma_1;       ///< App DMA instance 1, support 8 channel
    uint32_t spw_0;          ///< SPW instance 1, support 7 channel
    uint32_t nmra_comp_0;    ///< NMRA instance 0 comparator, support 4 channel
    uint32_t nmra_comp_1;    ///< NMRA instance 1 comparator, support 4 channel
    uint64_t nmra_replica_0; ///< NMRA instance 0 replica, support 4*5 channel
    uint64_t nmra_replica_1; ///< NMRA instance 1 replica, support 4*5 channel
    uint32_t gpio_0;         ///< APPC GPIO instance 0, supports 32 channels
    uint32_t gpio_1;         ///< APPC GPIO instance 1, supports 32 channels
    uint32_t timer_0;        ///< APPC timer instance 0, supports 8 channels
    uint32_t timer_1;        ///< APPC timer instance 1, supports 8 channels
    uint32_t timer_2;        ///< APPC timer instance 2, supports 8 channels
    uint32_t timer_3;        ///< APPC timer instance 3, supports 8 channels
    uint32_t timer_4;        ///< APPC timer instance 4, supports 8 channels
    uint32_t timer_5;        ///< APPC timer instance 5, supports 8 channels
    uint32_t timer_6;        ///< APPC timer instance 6, supports 8 channels
    uint32_t timer_7;        ///< APPC timer instance 7, supports 8 channels
} p64h_sysc_appc_periph_chnl_t;

/// Define peripheral configuration for the peripheral
typedef struct {
    p64h_sysc_appc_periph_initiator_inst_t   periph_initiator_enable; ///< which peripheral instances are enabled by the application
    p64h_sysc_appc_periph_initiator_inst_t   periph_ddr_access;       ///< Specify ddr access for associated peripheral. 0: DDR0 1:DDR1
    p64h_sysc_appc_periph_initiator_inst_t   periph_fp_access;        ///< Specify fp access for associated peripheral. 0:FP0 1:FP1
    p64h_sysc_appc_periph_subordinate_inst_t periph_subordinate_inst; ///< which other peripheral instances are enabled by the application
    p64h_sysc_appc_periph_chnl_t periph_chnl_enable; ///< If channelized peripheral is enabled, active channels are specified in this struct
} p64h_sysc_appc_active_periphs_t;

///  ENUM for IO Bridge block state
typedef enum {
    P64H_SYSC_IOBRIDGE_INST_STATE_DISABLED = 0u, ///<  IO bridge disabled state
    P64H_SYSC_IOBRIDGE_INST_STATE_ENABLED,       ///< IO bridge enabled state
    P64H_SYSC_LAST_IOBRIDGE_INST_STATE           ///< Invalid, use for error checking
} p64h_sysc_iobridge_inst_state_t;

/// ENUM for IOB Operational Modes
typedef enum {
    P64H_SYSC_IOBRIDGE_OP_MODE_SEND_TO_IOMMU_CACHE_EVERYTHING = 0u,   ///< Send everything to IOMMU and cache everything
    P64H_SYSC_IOBRIDGE_OP_MODE_SEND_TO_IOMMU_CACHE_NOTHING,           ///< Send everything to IOMMU and cache nothing
    P64H_SYSC_IOBRIDGE_OP_MODE_SEND_NOTHING_TO_IOMMU_CACHE_NOTHING,   ///< Bypass mode; Send nothing to IOMMU, cache nothing
    P64H_SYSC_IOBRIDGE_OP_MODE_SEND_NONTRANS_TO_IOMMU_CACHE_NONTRANS, ///< Send non-translated address to IOMMU and cache these; if translated addr
                                                                      ///< then bypass IOMMU and don't cache
    P64H_SYSC_IOBRIDGE_OP_MODE_SEND_TO_IOMMU_CACHE_NONTRANS,          ///< Send always to IOMMU, but only cache for non translated addr
    P64H_SYSC_IOBRIDGE_OP_MODE_SEND_NON_SELECTED_DID_TO_IOMMU, ///< When per-DID IOMMU bypass is selected, bypass IOMMU and don’t cache for selected
                                                               ///< DIDs. For non-selected DIDs, send to IOMMU and cache these
    P64H_SYSC_LAST_IOBRIDGE_OP_MODE                            ///< Invalid or out of range value.
} p64h_sysc_iobridge_op_mode_t;

/// Struct that represents the configuration of a single iobridge
typedef struct {
    p64h_sysc_iobridge_inst_state_t state;             ///< State of iobridge, enable or disable
    p64h_sysc_iobridge_op_mode_t    op_mode;           ///< operation mode of iobridge
    uint32_t                        per_did_bypass[8]; ///< per DID bypass setting of iobridge only applicable when op_mode ==
                                                       ///< P64H_SYSC_IOBRIDGE_OP_MODE_SEND_NON_SELECTED_DID_TO_IOMMU
    uint32_t did_base;                                 ///< DID base setting of iobridge
    uint32_t did_length;                               ///< DID length setting of iobridge
    uint32_t iommu_did_base;                           ///< IOMMU DID base
    uint32_t pmp_addr[IOBRIDGE_PMP_ADDR_NUM];          ///< 16 * 32-bit PMP addr; Each PMP addr consists of 32 bit LSB and 32 bit MSB.
} p64h_sysc_iobridge_cfg_t;

/// define enet rate
typedef enum {
    P64H_SYSC_APPC_ENET_RATE_MII_10M = 0u,  ///< MII interface for 10M
    P64H_SYSC_APPC_ENET_RATE_MII_100M,      ///< MII interface for 100M
    P64H_SYSC_APPC_ENET_RATE_RGMII_10M,     ///< RGMII interface for 10M
    P64H_SYSC_APPC_ENET_RATE_RGMII_100M,    ///< RGMII interface for 100M
    P64H_SYSC_APPC_ENET_RATE_RGMII_1G,      ///< RGMII interface for 1G
    P64H_SYSC_APPC_ENET_RATE_SGMII_10M,     ///< SGMII interface for 10M
    P64H_SYSC_APPC_ENET_RATE_SGMII_100M,    ///< SGMII interface for 100M
    P64H_SYSC_APPC_ENET_RATE_SGMII_1G,      ///< SGMII interface for 1G
    P64H_SYSC_APPC_ENET_RATE_SGMII_2_5G,    ///< SGMII interface for 2.5G
    P64H_SYSC_APPC_ENET_RATE_BASE_KX_1000M, ///< serial interface for 1000BASE-KX
    P64H_SYSC_APPC_ENET_RATE_BASE_KX_2_5G,  ///< serial interface for 2.5GBASE-KX
    P64H_SYSC_APPC_ENET_RATE_XSXGMII_5G,    ///< serial 5G-USXGMII interface with 5G MAC data
    P64H_SYSC_APPC_ENET_RATE_BASE_R_5G,     ///< 5GBASE-R interface
    P64H_SYSC_APPC_ENET_RATE_BASE_KR_5G,    ///< 5GBASE-KR interface
    P64H_SYSC_APPC_ENET_RATE_XSXGMII_10G,   ///< 10G-USXGMII interface with a single 10G MAC client
    P64H_SYSC_APPC_ENET_RATE_BASE_R_10G,    ///< 10GBASE-R interface
    P64H_SYSC_APPC_ENET_RATE_BASE_KR_10G,   ///< 10GBASE-KR interface
    P64H_SYSC_LAST_APPC_ENET_RATE           ///< Used for error checking
} p64h_sysc_appc_enet_rate_t;

/// enet clock rate
typedef enum {
    P64H_SYSC_APPC_ENET_CLOCK_MII_10M     = 0u,  ///< 10M MII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_MII_100M    = 1u,  ///< 100M MII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_RGMII_10M   = 2u,  ///< 10M RGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_RGMII_100M  = 3u,  ///< 100M RGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_RGMII_1G    = 4u,  ///< 1G RGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_SGMII_10M   = 5u,  ///< 10M SGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_SGMII_100M  = 6u,  ///< 100M SGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_SGMII_1G    = 7u,  ///< 1G SGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_SGMII_2_5G  = 8u,  ///< 2.5G SGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_XSXGMII_5G  = 9u,  ///< 5G USXGMII interface clock
    P64H_SYSC_APPC_ENET_CLOCK_XSXGMII_10G = 10u, ///< 10G USXGMII interface clock
    P64H_SYSC_LAST_APPC_ENET_CLOCK               ///< Used for error checking
} p64h_sysc_appc_enet_clock_t;

/// enet EP configuration
typedef struct {
    p64h_sysc_appc_enet_rate_t rate;            ///< the rate of the end-point
    uint32_t                   enable_ptp;      ///< do we enable PTP
    uint32_t                   enable_loopback; ///< Enable for MII-mode/RGMII-mode Rx to Tx loopback path logic of an Ethernet Endpoint
    // Each initiator should have their own iobridge config inside their
    // configuration struct, TODO for appdma, rdma, etc.
    p64h_sysc_iobridge_cfg_t iobridge_cfg; ///< iobridge inside the end-point
} p64h_sysc_appc_enet_ep_cfg_t;

/// enum for appdma instance numbers (0-indexed)
typedef enum {
    P64H_SYSC_APPDMA_INST_0 = 0u, ///< APPDMA instance 0
    P64H_SYSC_APPDMA_INST_1,      ///< APPDMA instance 1
    P64H_SYSC_LAST_APPDMA_INST    ///< last element for error checking
} p64h_sysc_appc_appdma_inst_id_t;

/// Struct that represents the configuration of a single appdma peripheral
typedef struct {
    p64h_sysc_appc_appdma_inst_id_t inst;    ///< appdma instance number
    p64h_sysc_iobridge_cfg_t        iob_cfg; ///< configuration for this appdma's iobridge
} p64h_sysc_appc_appdma_cfg_t;

/// enum for iommu instance numbers (0-indexed)
typedef enum {
    P64H_SYSC_IOMMU_INST_0 = 0u, ///< IOMMU instance 0
    P64H_SYSC_IOMMU_INST_1,      ///< IOMMU instance 1
    P64H_SYSC_LAST_IOMMU_INST    ///< last element for error checking; can be used as total number of iommu inst
} p64h_sysc_appc_iommu_inst_id_t;

/// Struct that represents the configuration of a single iommu peripheral
typedef struct {
    p64h_sysc_appc_iommu_inst_id_t inst;        ///< instance number of iommu
    uint32_t                       client_mask; ///< mask of enabled DTMUX ports
} p64h_sysc_appc_iommu_cfg_t;

/// enum for pcie/cxl subsystem instance numbers (0-indexed)
typedef enum {
    P64H_SYSC_PCIE_CXL_INST_0 = 0u, ///< PCIE instance 0
    P64H_SYSC_PCIE_CXL_INST_1,      ///< PCIE instance 1
    P64H_SYSC_LAST_PCIE_CXL_INST    ///< last element for error checking
} p64h_sysc_appc_pcie_cxl_inst_id_t;

/// pcie link bifurcation configuration
typedef enum {
    P64H_SYSC_PCIE_CXL_LINK_CFG_NON_BIFURCATED = 0u, ///< NON BIFURCATED LINK
    P64H_SYSC_PCIE_CXL_LINK_CFG_BIFURCATED,          ///< BIFURCATED link
    P64H_SYSC_LAST_PCIE_CXL_LINK_CFG                 ///< invalid, used for error checking
} p64h_sysc_appc_pcie_cxl_bifurcation_cfg_t;

/// pcie state. Subsystem can either be active or inactive
typedef enum {
    P64H_SYSC_PCIE_CXL_STATE_DISABLED = 0u, ///< Disabled state
    P64H_SYSC_PCIE_CXL_STATE_ENABLED,       ///< Enabled state
    P64H_SYSC_LAST_PCIE_CXL_STATE           ///< Invalid, used for error checking
} p64h_sysc_appc_pcie_cxl_state_t;

/// pcie/cxl link width setting, x1/x2/x4 when bifurcated, x8 otherwise
typedef enum {
    P64H_SYSC_PCIE_CXL_LINK_X1 = 0x1u, ///< x1 link
    P64H_SYSC_PCIE_CXL_LINK_X2 = 0x2u, ///< x2 link
    P64H_SYSC_PCIE_CXL_LINK_X4 = 0x4u, ///< x4 link
    P64H_SYSC_PCIE_CXL_LINK_X8 = 0x8u, ///< x8 link
    P64H_SYSC_LAST_PCIE_CXL_LINK_WIDTH ///< Invalid, used for error checking
} p64h_sysc_pcie_cxl_link_width_t;

/// pcie/cxl link speed setting, supporting up to PCIe Gen 3 (8.0 GT/s)
typedef enum {
    P64H_SYSC_PCIE_CXL_LINK_SPEED_2_5GT = 0x1u, ///< PCIe Gen 1 speed
    P64H_SYSC_PCIE_CXL_LINK_SPEED_5_0GT = 0x2u, ///< PCIe Gen 2 speed
    P64H_SYSC_PCIE_CXL_LINK_SPEED_8_0GT = 0x3u, ///< PCIe Gen 3 speed
    P64H_SYSC_LAST_PCIE_CXL_LINK_SPEED          ///< Invalid, used for error checking
} p64h_sysc_pcie_cxl_link_speed_t;

/// Struct that represent the configuration of a single pcie/cxl link
/// A pcie/cxl sybsystem can have up to two links (bifurcation)
typedef struct {
    p64h_sysc_pcie_cxl_link_width_t link_width; ///< number of lanes used in this link
    p64h_sysc_pcie_cxl_link_speed_t link_speed; ///< speed of the link
} p64h_sysc_pcie_link_cfg_t;

/// Struct that represents the configuration of a single pcie/cxl subsystem instance
typedef struct {
    p64h_sysc_appc_pcie_cxl_inst_id_t         inst;                 ///< instance number of pcie
    p64h_sysc_appc_pcie_cxl_state_t           state;                ///< state of the subsystem instance
    p64h_sysc_appc_pcie_cxl_bifurcation_cfg_t bifurcation;          ///< bifurcation configuration of the subsystem instance
    p64h_sysc_pcie_link_cfg_t link_cfg[APPC_PERIPH_PCIE_NUM_LINKS]; ///< configuration for each link (2nd link is only active when bifurcated)
    p64h_sysc_iobridge_cfg_t
        iobridge_cfg[APPC_PERIPH_PCIE_NUM_LINKS]; ///< iobridge configurations of the subsystem instance (2nd instance only enable when bifurcated)
} p64h_sysc_pcie_cfg_t;

/// Example structure for the template driver
typedef struct {
    uint32_t ex_var1; ///< example variable #1
    uint32_t ex_var2; ///< example variable #2
} p64h_sysc_tplt_drv_cfg_t;

/// GPIO id instance
typedef enum {
    P64H_SYSC_GPIO = 0u,     ////< Represents ID of the sysc GPIO port
    P64H_SYSC_APPC_GPIO_0,   ///< Represents ID of the first GPIO port
    P64H_SYSC_APPC_GPIO_1,   ///< Represents ID of the second GPIO port
    P64H_SYSC_LAST_GPIO_INST ///< Invalid, used for error checking
} p64h_sysc_gpio_inst_id_t;

/**
 * @brief
 *   UART id instance
 */
typedef enum {
    P64H_SYSC_UART = 0u,     ///< Represents ID of the sysc UART port
    P64H_SYSC_APPC_UART_0,   ///< Represents ID of the first appc UART port
    P64H_SYSC_APPC_UART_1,   ///< Represents ID of the second appc UART port
    P64H_SYSC_APPC_UART_2,   ///< Represents ID of the third appc UART port
    P64H_SYSC_APPC_UART_3,   ///< Represents ID of the fourth appc UART port
    P64H_SYSC_LAST_UART_INST ///< Invalid, used for error checking
} p64h_sysc_uart_inst_id_t;

/// NMRA id instance
typedef enum {
    P64H_SYSC_NMRA_0 = 0u, ///< Represents ID of the first NMRA port
    P64H_SYSC_NMRA_1,      ///< Represents ID of the second NMRA port
    P64H_SYSC_LAST_NMRA    ///< Invalid, used for error checking
} p64h_sysc_nmra_inst_id_t;

/// I2C id instance
typedef enum {
    P64H_SYSC_I2C = 0u, ///< Represents ID of the sysc I2C port
    P64H_SYSC_I2C_0,    ///< Represents ID of the first I2C port
    P64H_SYSC_I2C_1,    ///< Represents ID of the second I2C port
    P64H_SYSC_I2C_2,    ///< Represents ID of the third I2C port
    P64H_SYSC_I2C_3,    ///< Represents ID of the fourth I2C port
    P64H_SYSC_LAST_I2C  ///< Invalid, used for error checking
} p64h_sysc_i2c_inst_id_t;

/// HPT id instance
typedef enum {
    P64H_SYSC_HPT = 0u, ///< Represents ID of the sysc HPT instance
    P64H_SYSC_HPT_0,    ///< Represents ID of the first HPT instance
    P64H_SYSC_HPT_1,    ///< Represents ID of the second HPT instance
    P64H_SYSC_HPT_2,    ///< Represents ID of the third HPT instance
    P64H_SYSC_HPT_3,    ///< Represents ID of the fourth HPT instance
    P64H_SYSC_HPT_4,    ///< Represents ID of the fifth HPT instance
    P64H_SYSC_HPT_5,    ///< Represents ID of the sixth HPT instance
    P64H_SYSC_HPT_6,    ///< Represents ID of the seventh HPT instance
    P64H_SYSC_HPT_7,    ///< Represents ID of the eighth HPT instance
    P64H_SYSC_LAST_HPT  ///< Invalid, used for error checking
} p64h_sysc_hpt_inst_id_t;

/// SPI id instance
typedef enum {
    P64H_SYSC_APPC_SPI_0 = 0u, ///< Represents ID of the first SPI port
    P64H_SYSC_APPC_SPI_1,      ///< Represents ID of the second SPI port
    P64H_SYSC_LAST_SPI         ///< Unused
} p64h_sysc_spi_inst_id_t;

/// MDIO id instance
typedef enum {
    P64H_SYSC_APPC_MDIO_0 = 0u, ///< Represents ID of the first MDIO port
    P64H_SYSC_APPC_MDIO_1,      ///< Represents ID of the second MDIO port
    P64H_SYSC_LAST_MDIO         ///< Invalid, could be used for error checking
} p64h_sysc_mdio_inst_id_t;

/// SPW id instance
typedef enum {
    P64H_SYSC_APPC_SPW_0 = 0u, ///< Represents ID of the first SPW instance
    P64H_SYSC_APPC_SPW_1,      ///< Represents ID of the second SPW instance
    P64H_SYSC_APPC_SPW_2,      ///< Represents ID of the third SPW instance
    P64H_SYSC_APPC_SPW_3,      ///< Represents ID of the fourth SPW instance
    P64H_SYSC_APPC_SPW_4,      ///< Represents ID of the fifth SPW instance
    P64H_SYSC_APPC_SPW_5,      ///< Represents ID of the sixth SPW instance
    P64H_SYSC_APPC_SPW_6,      ///< Represents ID of the seventh SPW instance
    P64H_SYSC_LAST_SPW         ///< Invalid, could be used for error checking
} p64h_sysc_spw_link_id_t;

/// Watchdog timer id instance
typedef enum p64h_sysc_wdt_inst_id {
    P64H_SYSC_WDT = 0u, ///< Represents ID of the sysc WDT instance
    P64H_SYSC_WDT_0,    ///< Represents ID of the first WDT instance
    P64H_SYSC_WDT_1,    ///< Represents ID of the second WDT instance
    P64H_SYSC_WDT_2,    ///< Represents ID of the third WDT instance
    P64H_SYSC_WDT_3,    ///< Represents ID of the fourth WDT instance
    P64H_SYSC_WDT_4,    ///< Represents ID of the fifth WDT instance
    P64H_SYSC_WDT_5,    ///< Represents ID of the sixth WDT instance
    P64H_SYSC_WDT_6,    ///< Represents ID of the seventh WDT instance
    P64H_SYSC_WDT_7,    ///< Represents ID of the eighth WDT instance
    P64H_SYSC_LAST_WDT  ///< invalid, used for error checking
} p64h_sysc_wdt_inst_id_t;

/// USB id instance
typedef enum {
    P64H_SYSC_APPC_USB_0 = 0u, ///< Represents ID of the first USB port
    P64H_SYSC_APPC_USB_1,      ///< Represents ID of the second USB port
    P64H_SYSC_USB_NONE
} p64h_sysc_usb_inst_id_t;

/// IPC id instance
typedef enum {
    P64H_SYSC_IPC_0 = 0u, ///< Represents ID of the first IPC instance
    P64H_SYSC_IPC_1,      ///< Represents ID of the second IPC instance
    P64H_SYSC_LAST_IPC    ///< Invalid, used for error checking
} p64h_sysc_ipc_inst_id_t;

/// ENET EP id instance
typedef enum {
    P64H_SYSC_ENET_EP_0 = 0u, ///< Represents ID of the first ENET EP instance
    P64H_SYSC_ENET_EP_1,      ///< Represents ID of the second ENET EP instance
    P64H_SYSC_ENET_EP_2,      ///< Represents ID of the third ENET EP instance
    P64H_SYSC_ENET_EP_3,      ///< Represents ID of the fouth ENET EP instance
    P64H_SYSC_LAST_ENET_EP    ///< Invalid, used for error checking
} p64h_sysc_enet_ep_inst_id_t;

/// GPIO configuration
typedef struct {
    p64h_sysc_gpio_inst_id_t inst;    ///< Instance of the ID enumeration
    uint8_t                  pin_cfg; ///< Pin Mux configuration
} p64h_sysc_gpio_cfg_t;

/// GPIO MUX configuration
typedef struct {
    uint32_t gpio_out_mux[APPC_PERIPH_GPIO_OUT_MUX_INST_NUM];        ///< GPIO_OUTPUT_MUX select pin to perform gpio output muxing
    uint32_t gpio_in_mux_to_appc0[APPC_PERIPH_GPIO_IN_MUX_INST_NUM]; ///< GPIO_INPUT_MIX select pin to perform muxing on appc0
    uint32_t gpio_in_mux_to_appc1[APPC_PERIPH_GPIO_IN_MUX_INST_NUM]; ///< GPIO_INPUT_MIX select pin to perform muxing on appc1
    uint32_t gpio_in_mux_to_sys[APPC_PERIPH_GPIO_IN_MUX_INST_NUM];   ///< GPIO_INPUT_MIX select pin to perform muxing on sysc
} p64h_sysc_gpio_mux_cfg_t;
/**
 * @brief
 *   UART configuration
 */
typedef struct {
    p64h_sysc_uart_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_uart_cfg_t;

/// NMRA configuration
typedef struct {
    p64h_sysc_nmra_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_nmra_cfg_t;

/// I2C configuration
typedef struct {
    p64h_sysc_i2c_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_i2c_cfg_t;

/// HPT configuration
typedef struct {
    p64h_sysc_hpt_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_hpt_cfg_t;

/// SPI configuration
typedef struct {
    p64h_sysc_spi_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_spi_cfg_t;

/// MDIO configuration
typedef struct {
    p64h_sysc_mdio_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_mdio_cfg_t;

/// SPW configuration
typedef struct {
    p64h_sysc_spw_link_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_appc_spw_cfg_t;

/// Watchdog configuration
typedef struct {
    p64h_sysc_wdt_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_wdt_cfg_t;

/// USB configuration
typedef struct {
    p64h_sysc_usb_inst_id_t  inst;         ///< Instance of the ID enumeration
    p64h_sysc_iobridge_cfg_t iobridge_cfg; ///< iobridge inside the USB
} p64h_sysc_usb_cfg_t;

/// JTAG HOST configuration
typedef struct {
} p64h_sysc_jtag_host_cfg_t;

/// IPC configuration
typedef struct {
    p64h_sysc_ipc_inst_id_t inst; ///< Instance of the ID enumeration
} p64h_sysc_ipc_cfg_t;

/// NVM configuration
typedef struct {
    p64h_sysc_iobridge_cfg_t iob_cfg_sd[APPC_PERIPH_NVM_IOB_INST_NUM];   ///< iobridge inside the SD
    p64h_sysc_iobridge_cfg_t iob_cfg_edac[APPC_PERIPH_NVM_IOB_INST_NUM]; ///< iobridge inside the EDAC
    p64h_sysc_iobridge_cfg_t iob_cfg_nand[APPC_PERIPH_NVM_IOB_INST_NUM]; ///< iobridge inside the NAND
} p64h_sysc_appc_nvm_cfg_t;

/// USER CRYPTO configuration
typedef struct {
    p64h_sysc_iobridge_cfg_t iobridge_cfg; ///< iobridge inside the User Crypto
} p64h_sysc_user_crypto_cfg_t;

/// SPW Router configuration
typedef struct {
    bool    enabled;                                       ///< true - SPW Router is required; false - SPW Router is not required
    bool    enable_logical_addressing;                     ///< Logical Addressing enabled
    bool    enable_fallback;                               ///< Use Fallback Addressing
    bool    disable_timeout;                               ///< Timeout Disabled
    uint8_t router_table[APP_PERIPH_SPW_ROUTER_TABLE_MAX]; ///< Router Table logical address entries
} p64h_sysc_spw_router_cfg_t;

/// SPW configuration
typedef struct {
    p64h_sysc_iobridge_cfg_t   iobridge_cfg; ///< iobridge inside the end-point
    p64h_sysc_spw_router_cfg_t router_cfg;   ///< router configuration
} p64h_sysc_spw_cfg_t;

/// Define peripheral configuration for the peripheral
typedef struct {
    p64h_sysc_appc_active_periphs_t active_periph;                             ///< active peripheral configuration
    p64h_sysc_nmra_cfg_t            nmra_cfg[APPC_PERIPH_NMRA_INST_NUM];       ///< nmra configuration
    p64h_sysc_i2c_cfg_t             i2c_cfg[APPC_PERIPH_I2C_INST_NUM];         ///< i2c configuration
    p64h_sysc_gpio_cfg_t            gpio_cfg[APPC_PERIPH_GPIO_BLOCK_NUM];      ///< gpio configuration
    p64h_sysc_gpio_mux_cfg_t        gpio_mux_cfg;                              ///< gpio mux configuration
    p64h_sysc_spi_cfg_t             spi_cfg[APPC_PERIPH_SPI_INST_NUM];         ///< spi configuration
    p64h_sysc_mdio_cfg_t            mdio_cfg[APPC_PERIPH_MDIO_INST_NUM];       ///< mdio configuration
    p64h_sysc_appc_spw_cfg_t        spw_cfg[APPC_PERIPH_SPW_INST_NUM];         ///< spw configuration
    p64h_sysc_appc_enet_ep_cfg_t    enet_ep_cfg[APPC_PERIPH_ENET_EP_INST_NUM]; ///< ENET EP configuration
    p64h_sysc_hpt_cfg_t             hpt_cfg[APPC_PERIPH_HPT_INST_NUM];         ///< hpt configuration
    p64h_sysc_pcie_cfg_t            pcie_cfg[APPC_PERIPH_PCIE_INST_NUM];       ///< PCIE configuration
    p64h_sysc_appc_iommu_cfg_t      iommu_cfg[APPC_PERIPH_IOMMU_INST_NUM];     ///< IOMMU SS configuration
    p64h_sysc_appc_appdma_cfg_t     appdma_cfg[APPC_PERIPH_APP_DMA_INST_NUM];  ///< AppDMA SS configuration
    p64h_sysc_wdt_cfg_t             wdt_cfg[APPC_PERIPH_WDT_INST_NUM];         ///< wdt configuration
    p64h_sysc_usb_cfg_t             usb_cfg[APPC_PERIPH_USB_INST_NUM];         ///< usb configuration
    p64h_sysc_ipc_cfg_t             ipc_cfg[APPC_PERIPH_IPC_INST_NUM];         ///< ipc configuration
    p64h_sysc_uart_cfg_t            uart_cfg[APPC_PERIPH_UART_INST_NUM];       ///< uart configuration
    p64h_sysc_appc_nvm_cfg_t        nvm;                                       ///< nvm configuration
    p64h_sysc_jtag_host_cfg_t       jtag_host_cfg;                             ///< jtag host configuration
    p64h_sysc_user_crypto_cfg_t     user_crypto_cfg;                           ///< user crypto configuration
} p64h_sysc_appc_periph_cfg_t;

#endif // P64H_SYSC_SHARED_PERIPH_BA_H

/** @} */