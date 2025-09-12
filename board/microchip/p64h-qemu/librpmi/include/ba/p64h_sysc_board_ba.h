/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_sysc_board_ba.h
 * @brief
 *   Defines board platform configuration
 * @addtogroup p64h_sysc_types
 * @{
 */

#ifndef P64H_SYSC_BOARD_BA_H
#define P64H_SYSC_BOARD_BA_H
#include <generated/p64h_sysc_lsio_defs.h>
#include <types/p64h_sysc_serdes_types.h>
#include <types/p64h_sysc_ddr_types.h>
#include <types/p64h_sysc_nvm_types.h>

/// Number of NVM SRAM cards
#define NVM_SRAM_CARD_NUM 4u

/// Number of memory interfaces per NVM SRAM card
#define NVM_MEM_INTF 3u

/// Number of NVM connectors
#define NVM_CONNECTORS_NUM 4u

/// Number of chip-selects
#define CS_NUM 8u

/// Number of Serdes Groups
#define MAX_SERDES_GRPS 27u

/// Number of MII Configs
#define MAX_MII_CFGS 4u

/// Reference clock type
typedef enum {
    P64H_SYSC_REF_CLK_TYPE_DDR_0 = 0u, ///< DDR 0 interface reference clock type
    P64H_SYSC_REF_CLK_TYPE_DDR_1,      ///< DDR 1 interface reference clock type
    LAST_P64H_SYSC_REF_CLK_TYPE        ///< invalid, used for error checking
} p64h_sysc_ref_clk_type_t;

/// DDR configuration
typedef struct {
    bool     part_present; ///< TRUE - part is present, FALSE - part not present
    uint64_t size;         ///< DDR memory size
} p64h_sysc_ddr_board_cfg_t;

/// System Clock configuration
typedef struct {
    p64h_sysc_ref_clk_type_t clk_type;        ///< DDR reference clock configuration
    double                   clock_frequency; ///< clock frequency
} p64h_sysc_ddr_ref_clk_t;

/// NVM supported devices
typedef enum {
    NVM_DEVICE_SPI_SRAM = 0u,   ///< SPI SRAM device
    NVM_DEVICE_SPI_EEPROM,      ///< SPI EEPROM device
    NVM_DEVICE_SPI_MRAM,        ///< SPI MRAM device
    NVM_DEVICE_SPI_NOR,         ///< SPI NOR device
    NVM_DEVICE_SPI_NAND,        ///< SPI Nand Flash
    NVM_DEVICE_QSPI_SRAM,       ///< QSPI SRAM device
    NVM_DEVICE_QSPI_EEPROM,     ///< QSPI EEPROM device
    NVM_DEVICE_QSPI_MRAM,       ///< QSPI MRAM device
    NVM_DEVICE_QSPI_NOR,        ///< QSPI NOR device
    NVM_DEVICE_QSPI_NAND,       ///< QSPI Nand Flash
    NVM_DEVICE_OSPI_SRAM,       ///< OSPI SRAM device
    NVM_DEVICE_OSPI_EEPROM,     ///< OSPI EEPROM device
    NVM_DEVICE_OSPI_MRAM,       ///< OSPI MRAM device
    NVM_DEVICE_OSPI_NOR,        ///< OSPI NOR device
    NVM_DEVICE_OSPI_NAND,       ///< OSPI Nand Flash
    NVM_DEVICE_XSPI_SRAM,       ///< xSPI SRAM device
    NVM_DEVICE_XSPI_EEPROM,     ///< xSPI EEPROM device
    NVM_DEVICE_XSPI_MRAM,       ///< xSPI MRAM device
    NVM_DEVICE_XSPI_NOR,        ///< xSPI NOR device
    NVM_DEVICE_XSPI_NAND,       ///< xSPI Nand Flash
    NVM_DEVICE_PFLASH_SRAM,     ///< Parallel SRAM device
    NVM_DEVICE_PFLASH_EEPROM,   ///< Parallel EEPROM device
    NVM_DEVICE_PFLASH_MRAM,     ///< Parallel MRAM device
    NVM_DEVICE_PFLASH_NOR,      ///< Parallel NOR device
    NVM_DEVICE_NAND_ONFI_1_X,   ///< NAND ONFI 1.x device
    NVM_DEVICE_NAND_ONFI_2_X,   ///< NAND ONFI 2.x device
    NVM_DEVICE_NAND_ONFI_3_X,   ///< NAND ONFI 3.x device
    NVM_DEVICE_NAND_ONFI_4_0,   ///< NAND ONFI 4.0 device
    NVM_DEVICE_NAND_TOGGLE_1_0, ///< NAND Toggle 1.0 device
    NVM_DEVICE_NAND_TOGGLE_2_0, ///< NAND Toggle 2.0 device
    NVM_DEVICE_NAND_LEGACY,     ///< NAND Legacy device
    LAS_NVM_DEVICE              ///< invalid, used for error checking
} p64h_sysc_nvm_device_t;

/// MII Rate Configuration
typedef enum p64h_sysc_mii_rate_t {
    P64H_SYSC_MII_RATE_NOT_CFG = 0u, ///< Rate not specified
    P64H_SYSC_MII_RATE_10_M,         ///< 10M MII Rate
    P64H_SYSC_MII_RATE_100_M,        ///< 100M MII Rate
    P64H_SYSC_MII_RATE_10_M_RG,      ///< 10M RGMII Rate
    P64H_SYSC_MII_RATE_100_M_RG,     ///< 100M RGMII Rate
    P64H_SYSC_MII_RATE_1_G_RG,       ///< 1G RGMII Rate
    LAST_P64H_SYSC_MII_RATE          ///< Invalid, used for error checking
} p64h_sysc_mii_rate_t;

/// Mii Configuration
typedef struct {
    bool enable;               ///< TRUE - MII in use for enet_ep
                               ///< FALSE - MII not in use for enet_ep
    p64h_sysc_mii_rate_t rate; ///< Specified MII/RGMII rate
} p64h_sysc_mii_cfg_t;

/// NVM's connector configuration
typedef struct {
    uint64_t               chip_select_msk; ///< chip-select memory
    p64h_sysc_nvm_device_t nvm_device;      ///< NVM device
    uint32_t               reset_msk;       ///< chip-select memory
    uint64_t               sector_size;     ///< sector memory size
    uint64_t               size;            ///< memory size
} p64h_sysc_nvm_cfg_t;

/// Board platform configuration
typedef struct {
    p64h_sysc_lsio_cfg_t       lsio_cfg;                                   ///< LSIO configuration
    p64h_sysc_ddr_board_cfg_t  ddr_cfg[P64H_SYSC_DDR_INSTANCE_NUM];        ///< DDR configuration
    p64h_sysc_mii_cfg_t        mii_cfg[MAX_MII_CFGS];                      ///< MII Configuration
    p64h_sysc_serdes_grp_cfg_t serdes_grps_cfg[MAX_SERDES_GRPS];           ///< Serdes Group Config Implementation
    p64h_sysc_nvm_cfg_t        nvm_cfg[NVM_CONNECTORS_NUM * NVM_MEM_INTF]; ///< NVM interfaces configuration
    p64h_sysc_ddr_ref_clk_t    ddr_clock_cfg;                              ///< System clock configuration
    p64h_sysc_ddr_phy_cfg_t    ddr_phy_cfg[P64H_SYSC_DDR_INSTANCE_NUM];    ///< DDR PHY configuration
} p64h_sysc_board_cfg_t;

#endif // P64H_SYSC_BOARD_BA_H

/// @}