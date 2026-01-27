/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_nvm_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_NVM_TYPE_H
#define P64H_SYSC_NVM_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_errors.h>

/* Public Structs and Enums --------------------------------------- */

#define P64H_SYSC_EDAC_INST_NUM               2u ///< define the number of EDAC instance in SRAM EDAC
#define P64H_SYSC_SRAM_FEC_ADDR_MAP_NUM_SLOTS 8u ///< define the maximum number of slots for SRAM FEC address map
#define P64H_SYSC_EDAC_LARGE_SKIP_SLOTS       2u ///< define the maximum number of slots for SRAM patrol srubbing large skip range
#define P64H_SYSC_EDAC_SMALL_SKIP_SLOTS       8u ///< define the maximum number of slots for SRAM patrol srubbing small skip range
#define P64H_SYSC_NUM_CONNECTOR_PAIR          2u ///< define the maximum number of connector pair
#define P64H_SYSC_NUM_CONNECTOR_PER_PAIR      2u ///< define the number of connector per pair
#define P64H_SYSC_NUM_SRAM_EDAC_PER_PAIR      2u ///< define the maximum number of SRAM EDAC per pair
#define P64H_SYSC_NUM_NVM_CTRL_PER_PAIR       2u ///< define the number of NVM CTRL per pair
#define P64H_SYSC_NVM_NOC_IF_SRAM_EDAC        0u ///< define a SRAM EDAC interface
#define P64H_SYSC_NVM_NOC_IF_NVM_EDAC         1u ///< define a NVM EDAC interface
#define PFLASH_CTRL_DEVICE_MAX                8u ///< Number of external drives behind each PFLASH Controller.
#define PFLASH_CFG_CS_PAGE_RANGE_INDICES      2u ///< Number of upper and lower set of address in cs_page_range

#define P64H_SYSC_NVM_XSPI_DIAG_TEST_INITIAL                                                                                                         \
    0x00000001u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to enable the initial test
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_WRITE_READ_PAGE                                                                                                 \
    0x00000002u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to enable the write read page test
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_SECTOR_ERASE                                                                                                    \
    0x00000004u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to enable the sector erase test
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_BLOCK_LOCK                                                                                                      \
    0x00000008u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to enable the block lock test
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_0                                                                                                            \
    0x00000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 0
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_1                                                                                                            \
    0x08000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 1
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_2                                                                                                            \
    0x10000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 2
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_3                                                                                                            \
    0x18000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 3
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_4                                                                                                            \
    0x20000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 4
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_5                                                                                                            \
    0x28000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 5
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_6                                                                                                            \
    0x30000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 6
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_CS_7                                                                                                            \
    0x38000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to run tests on chip select 7
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_ERASE_BTW                                                                                                       \
    0x40000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to erase blocks between tests
#define P64H_SYSC_NVM_XSPI_DIAG_TEST_VERBOSE                                                                                                         \
    0x80000000u ///< define used in conjuction with the p64h_sysc_spi_flash_diag_xspi_cfg_struct_t to add more print messages.
#define P64H_SYSC_NVM_XSPI_DIAG_NUM_TESTS         4u ///< Total number of tests that can be run in a single RPMI call

#define P64H_SYSC_NVM_XSPI_STIG_INIT_CMD_ARR_SIZE 8 ///< Max size of the stig commands
#define P64H_SYSC_NVM_XSPI_SUBSECTOR_ARR_SIZE     4 ///< Max size of the subsector array

/* Public Structs and Enums --------------------------------------- */

/// NVM interface
typedef enum {
    P64H_SYSC_NVM_IF_ID_SRAM_EDAC_0_0 = 0u, ///< SRAM_EDAC 0, inst=0, connector=0
    P64H_SYSC_NVM_IF_ID_SRAM_EDAC_0_1,      ///< SRAM_EDAC 0, inst=1, connector=1
    P64H_SYSC_NVM_IF_ID_SRAM_EDAC_1_0,      ///< SRAM_EDAC 1, inst=0, connector=0
    P64H_SYSC_NVM_IF_ID_SRAM_EDAC_1_1,      ///< SRAM_EDAC 1, inst=1, connector=1
    P64H_SYSC_NVM_IF_ID_SRAM_EDAC_2_0,      ///< SRAM_EDAC 2, inst=0, connector=2
    P64H_SYSC_NVM_IF_ID_SRAM_EDAC_2_1,      ///< SRAM_EDAC 2, inst=1, connector=3
    P64H_SYSC_NVM_IF_ID_NVM_EDAC_0_0,       ///< NVM_EDAC 0, inst=0, connector=0
    P64H_SYSC_NVM_IF_ID_NVM_EDAC_0_1,       ///< NVM_EDAC 0, inst=1, connector=1
    P64H_SYSC_NVM_IF_ID_NVM_EDAC_1_0,       ///< NVM_EDAC 1, inst=0, connector=2
    P64H_SYSC_NVM_IF_ID_NVM_EDAC_1_1,       ///< NVM_EDAC 1, inst=1, connector=3
    P64H_SYSC_NVM_IF_ID_SD_0,               ///< SD interface 0
    P64H_SYSC_NVM_IF_ID_SD_1,               ///< SD interface 1
    P64H_SYSC_NVM_IF_LAST                   ///< invalid, used for error checking
} p64h_sysc_nvm_if_id_t;

/// enumerate  Bose–Chaudhuri–Hocquenghem (BCH) type
typedef enum {
    P64H_SYSC_BCH_TYPE_T4  = 4u,  ///< T=4 , ECC_SIZE = 6
    P64H_SYSC_BCH_TYPE_T10 = 10u, ///< T=10 , ECC_SIZE = 14
    P64H_SYSC_BCH_TYPE_T18 = 18u, ///< T=18, ECC_SIZE = 25
    P64H_SYSC_BCH_TYPE_T24 = 24u  ///< T=24 , ECC_SIZE = 33
} p64h_sysc_bch_type_t;

/**
 * @brief
 *  Enumeration of NVM CTRL for APPc boot
 */
typedef enum {
    P64H_SYSC_NVM_CTRL_PARALLEL = 0u, ///< Parallel CTRL
    P64H_SYSC_NVM_CTRL_XSPI,          ///< xSPI CTRL
    P64H_SYSC_NVM_CTRL_SD_EMMC,       ///< SD/eMMC CTRL
    P64H_SYSC_NVM_CTRL_NAND,          ///< NAND CTRL
    P64H_SYSC_LAST_NVM_CTRL           ///< invalid used for error checking
} p64h_sysc_nvm_ctrl_type_t;

/**
 * @brief
 *  Enumeration of mode of operation for connector
 *  The value of the enum encode mux configuration
 */
typedef enum {
    P64H_SYSC_NVM_CONNECTOR_NOT_CFG = 0x0u, ///< Connector not used
    P64H_SYSC_NVM_CONNECTOR_01_MODE_0,      ///< 16b Parallel 50/xSPI 21
    P64H_SYSC_NVM_CONNECTOR_01_MODE_1,      ///< 16b Parallel 53/xSPI 17
    P64H_SYSC_NVM_CONNECTOR_01_MODE_2,      ///< 16b Parallel 55/xSPI 16
    P64H_SYSC_NVM_CONNECTOR_01_MODE_3,      ///< NAND 38/xSPI 33
    P64H_SYSC_NVM_CONNECTOR_01_MODE_4,      ///< 32b Parallel 71 (only valid for PIC64-HPSC)
    P64H_SYSC_NVM_CONNECTOR_01_MODE_5,      ///< 16b Parallel 53/eMMC/SD 18 (only valid for PIC64-HX)
    P64H_SYSC_NVM_CONNECTOR_01_MODE_6,      ///< NAND38/xSPI21/eMMC/SD 18 (only valid for PIC64-HX)
    P64H_SYSC_NVM_CONNECTOR_01_RSVD_0,      ///< connector 0/1 reserved 0
    P64H_SYSC_NVM_CONNECTOR_01_RSVD_1,      ///< connector 0/1 reserved 1
    P64H_SYSC_NVM_CONNECTOR_23_MODE_0,      ///< sysc: 16b Parallel 55
    P64H_SYSC_NVM_CONNECTOR_23_MODE_1,      ///< appnoc: 16b Parallel 53/xSPI 17
    P64H_SYSC_NVM_CONNECTOR_23_MODE_2,      ///< NAND 22/xSPI 33
    P64H_SYSC_NVM_CONNECTOR_23_MODE_3,      ///< NAND 30/xSPI 21
    P64H_SYSC_NVM_CONNECTOR_23_MODE_4,      ///< NAND 38/xSPI 15
    P64H_SYSC_NVM_CONNECTOR_23_RSVD_0,      ///< connector 2/3 reserved 0
    P64H_SYSC_NVM_CONNECTOR_23_RSVD_1,      ///< connector 2/3 reserved 1
    P64H_SYSC_LAST_NVM_CONNECTOR_MODE       ///< invalid used for error checking
} p64h_sysc_nvm_cmode_t;

/**
 * @brief Enumeration of NVM NOC interface encoded with p64h_sysc_nvm_noc_if_enc_t
 */
typedef enum {
    P64H_SYSC_NVM_NOC_IF_SRAM_EDAC_0_0 = 0x0000u,     ///< SRAM_EDAC 0, inst=0, connector=0
    P64H_SYSC_NVM_NOC_IF_SRAM_EDAC_0_1 = 0x0101u,     ///< SRAM_EDAC 0, inst=1, connector=1
    P64H_SYSC_NVM_NOC_IF_SRAM_EDAC_1_0 = 0x0010u,     ///< SRAM_EDAC 1, inst=0, connector=0
    P64H_SYSC_NVM_NOC_IF_SRAM_EDAC_1_1 = 0x0111u,     ///< SRAM_EDAC 1, inst=1, connector=1
    P64H_SYSC_NVM_NOC_IF_SRAM_EDAC_2_0 = 0x0022u,     ///< SRAM_EDAC 2, inst=0, connector=2
    P64H_SYSC_NVM_NOC_IF_SRAM_EDAC_2_1 = 0x0123u,     ///< SRAM_EDAC 2, inst=1, connector=3
    P64H_SYSC_NVM_NOC_IF_NVM_EDAC_0_0  = 0x1000u,     ///< NVM_EDAC 0, inst=0, connector=0
    P64H_SYSC_NVM_NOC_IF_NVM_EDAC_0_1  = 0x1101u,     ///< NVM_EDAC 0, inst=1, connector=1
    P64H_SYSC_NVM_NOC_IF_NVM_EDAC_1_0  = 0x1012u,     ///< NVM_EDAC 1, inst=0, connector=2
    P64H_SYSC_NVM_NOC_IF_NVM_EDAC_1_1  = 0x1113u,     ///< NVM_EDAC 1, inst=1, connector=3
    P64H_SYSC_NVM_NOC_IF_SYS_IF_0      = 0x01110000u, ///< SYSTEM controller SPI interface 0
    P64H_SYSC_NVM_NOC_IF_SYS_IF_1      = 0x11110000u, ///< SYSTEM controller SPI interface 1
    P64H_SYSC_NVM_NOC_IF_LAST                         ///< used for error checking and to show when there is no interface to be used
} p64h_sysc_nvm_noc_if_t;

/// NVM CTRL clock selection
typedef enum {
    TOP_NVM0_ACSU_CLK_OUT_0 = 0u, ///< 20 MHz , NVM0 ACSU CLK_OUT[0]
    TOP_NVM0_ACSU_CLK_OUT_1,      ///< 40 MHz , NVM0 ACSU CLK_OUT[1]
    TOP_NVM0_ACSU_CLK_OUT_2,      ///< 80 MHz , NVM0 ACSU CLK_OUT[2]
    TOP_NVM0_ACSU_CLK_OUT_3,      ///< 100 MHz , NVM0 ACSU CLK_OUT[3]
    TOP_NVM0_ACSU_CLK_OUT_4,      ///< 200 MHz , NVM0 ACSU CLK_OUT[4]
    TOP_NVM0_ACSU_CLK_OUT_5,      ///< 300 MHz , NVM0 ACSU CLK_OUT[5]
    TOP_NVM0_ACSU_CLK_OUT_6,      ///< 400 MHz , NVM0 ACSU CLK_OUT[6]
    TOP_NVM0_ACSU_CLK_OUT_7,      ///< 600 MHz , NVM0 ACSU CLK_OUT[7]
    TOP_NVM1_ACSU_CLK_OUT_0,      ///< 57.143 MHz , NVM1 ACSU CLK_OUT[0]
    TOP_NVM1_ACSU_CLK_OUT_1,      ///< 66.667 MHz , NVM1 ACSU CLK_OUT[1]
    TOP_NVM1_ACSU_CLK_OUT_2,      ///< 133.333 MHz , NVM1 ACSU CLK_OUT[2]
    TOP_NVM1_ACSU_CLK_OUT_3,      ///< 266.667 MHz , NVM1 ACSU CLK_OUT[3]
    TOP_NVM1_ACSU_CLK_OUT_4,      ///< 533.333 MHz , NVM1 ACSU CLK_OUT[4]
    TOP_NVM2_ACSU_CLK_OUT_0,      ///< 166.667 MHz , NVM2 ACSU CLK_OUT[0]
    TOP_NVM2_ACSU_CLK_OUT_1,      ///<  333.333 MHz , NVM2 ACSU CLK_OUT[1]
    TOP_NVM2_ACSU_CLK_OUT_2,      ///< spare , NVM2 ACSU CLK_OUT[2]
    TOP_NVM2_ACSU_CLK_OUT_3,      ///< spare , NVM2 ACSU CLK_OUT[3]
    LAST_TOP_NVM_ACSU_CLK_OUT     ///< invalid, used for error checking
} p64h_sysc_top_nvm_acsu_ctrl_clk_out_t;

/**
 * @brief P64H LSIO Pin location struct
 */
typedef union {
    p64h_sysc_nvm_noc_if_t e; ///< access enum value
    struct {
        uint8_t  connector    : 4;  //< connector (0,1,2,3)
        uint8_t  edac_id      : 4;  //< edac identifier (0,1,2)
        uint8_t  edac_inst_id : 4;  //< EDAC instance idenfier (0,1)
        uint8_t  edac_type    : 4;  //< 0 = SRAM, 1 = NVM
        uint32_t padding      : 16; //< padding
    } b;                            ///< bit fields
} p64h_sysc_nvm_noc_if_enc_t;

/// NVM interface attributes
typedef struct {
    uint32_t placeholder; ///< placeholder
} p64h_sysc_nvm_if_attr_t;

/// NVM interface configuration
typedef struct {
    uint32_t placeholder; ///< placeholder
} p64h_sysc_nvm_if_cfg_t;

/**
 * @brief
 *  Enumeration of SPI flash AXI source interface
 */
typedef enum {
    P64H_SYSC_SPI_FLASH_AXI_SRC_X_SPI,    ///< AXI4 connection via xSPI CTRL
    P64H_SYSC_SPI_FLASH_AXI_SRC_SD_E_MMC, ///< AXI4 connection via SD/eMMC Ctrl
    P64H_SYSC_SPI_FLASH_AXI_SRC_LAST      ///< invalid used for error checking
} p64h_sysc_spi_flash_axi_src_t;

/**
 * @brief
 *  Struct for the possible XSPI diagnostic tests that can
 *  be run.
 */
typedef union {
    struct {
        // enables for the various tests.
        unsigned en_initial_test         : 1; ///< single byte write/read test
        unsigned en_write_read_page_test : 1; ///< single page write/read test
        unsigned en_sector_erase_test    : 1; ///< sector erase test
        unsigned en_block_lock_test      : 1; ///< block lock protection test

        unsigned reserved                : 23; ///< bits 4-26 reserved for future use

        // Options to change how the run is done
        unsigned chip_select         : 3; ///< which chip select to use for the testing
        unsigned erase_between_tests : 1; ///< perform sector erases between tests, can be enabled whenever, but the en_sector_erase_test passing is
                                          ///< suggested, since it checks to see if the sector erase actually works. Also clears block locks between
                                          ///< all tests.
        unsigned verbose : 1;             ///< Increase output to aid debugging.

    } bits;        ///< individual bits represnting tests to run
    uint32_t mask; ///< Mask for the above bits

} p64h_sysc_spi_flash_diag_xspi_cfg_struct_t;

/**
 * @brief
 *  This struct packages a test info struct containing what tests should be run with an
 *  array of test results from the test that were run
 */
typedef struct {
    p64h_sysc_spi_flash_diag_xspi_cfg_struct_t test_info; ///< struct containing what tests should be run and other controls
    p64h_err_t                                 test_errs[P64H_SYSC_NVM_XSPI_DIAG_NUM_TESTS]; ///< array of test results
} p64h_sysc_nvm_diag_test_t;

/**
 * @brief
 *  This enum defines the possible io widths for xspi
 */
typedef enum {
    P64H_SYSC_SPI_MODE_IOS_1 = 0u, ///< Single SPI
    P64H_SYSC_SPI_MODE_IOS_2 = 1u, ///< Dual SPI
    P64H_SYSC_SPI_MODE_IOS_4 = 2u, ///< Quad SPI
    P64H_SYSC_SPI_MODE_IOS_8 = 3u, ///< Octal SPI
    LAST_P64H_SYSC_SPI_MODE        ///< invalid, used for error checking
} p64h_sysc_spi_flash_xspi_mode_t;

/**
 * @brief
 *  This enum defines the data rates for xspi
 */
typedef enum {
    P64H_SYSC_SPI_DATA_RATE_SDR = 0u, ///< Single data rate
    P64H_SYSC_SPI_DATA_RATE_DDR = 1u, ///< Double data rate
    LAST_P64H_SYSC_SPI_DATA_RATE      ///< invalid, used for error checking
} p64h_sysc_spi_flash_xspi_data_rate_t;

/**
 * @brief
 *  xspi_profile
 */
typedef enum {
    P64H_SYSC_SPI_PROFILE1 = 0u,       ///< Use profile 1.0 sequences (Legacy SPI and xSPI devices)
    P64H_SYSC_SPI_PROFILE2_HYPERFLASH, ///< Use profile 2.0 sequences (HyperFlash)
    P64H_SYSC_SPI_PROFILE2_HYPERRAM,   ///< Use profile 2.0 sequences (HyperRAM)
    P64H_SYSC_SPI_PROFILE_SPI_NAND,    ///< Use profile 1.0 sequences (SPI NAND)
    P64H_SYSC_SPI_PROFILE_LAST         ///< invalid, used for error checking
} p64h_sysc_spi_flash_xspi_profile_t;

/**
 * @brief
 *  xspi page size
 */
typedef enum {
    P64H_SYSC_XSPI_PAGE_SIZE_1B = 0U,         ///< 1B page size
    P64H_SYSC_XSPI_PAGE_SIZE_2B,              ///< 2B page size
    P64H_SYSC_XSPI_PAGE_SIZE_4B,              ///< 4B page size
    P64H_SYSC_XSPI_PAGE_SIZE_8B,              ///< 8B page size
    P64H_SYSC_XSPI_PAGE_SIZE_16B,             ///< 16B page size
    P64H_SYSC_XSPI_PAGE_SIZE_32B,             ///< 32B page size
    P64H_SYSC_XSPI_PAGE_SIZE_64B,             ///< 64B page size
    P64H_SYSC_XSPI_PAGE_SIZE_128B,            ///< 128B page size
    P64H_SYSC_XSPI_PAGE_SIZE_256B,            ///< 256B page size
    P64H_SYSC_XSPI_PAGE_SIZE_512B,            ///< 512B page size
    P64H_SYSC_XSPI_PAGE_SIZE_1024B,           ///< 1024B page size
    P64H_SYSC_XSPI_PAGE_SIZE_2048B,           ///< 2048B page size
    P64H_SYSC_XSPI_PAGE_SIZE_4096B,           ///< 4096B page size
    P64H_SYSC_XSPI_PAGE_SIZE_UNLIMITED = 0xFU // THis is only valid for the read, can we just reuse the same enum?
} p64h_sysc_spi_flash_xspi_page_size_t;

/**
 * @brief
 *  subsector struct
 */
typedef struct {
    uint32_t sector_size;       ///< in B
    uint8_t  erase_cmd;         ///< Command to erase this sector size.
    uint32_t erase_cmd_timeout; ///< Command timeout in ms
} p64h_sysc_spi_flash_xspi_sector_t;

/**
 * @brief
 *  XSPI word size
 */
typedef enum {
    P64H_SYSC_XSPI_STATUS_WORD_SIZE_8_BIT  = 0u, ///< 8 bits status word size
    P64H_SYSC_XSPI_STATUS_WORD_SIZE_16_BIT = 1u, ///< 16 bits status word size
    P64H_SYSC_XSPI_STATUS_WORD_SIZE_LAST         ///< invalid used for error checking
} p64h_sysc_spi_flash_xspi_word_size_t;

/**
 * @brief
 *  XSPI status polarity
 */
typedef enum {
    P64H_SYSC_XSPI_STATUS_POLARITY_0 = 0u, ///< 0 value of polarity
    P64H_SYSC_XSPI_STATUS_POLARITY_1 = 1u, ///< 1 value of polarity
    P64H_SYSC_XSPI_STATUS_POLARITY_LAST    ///< invalid used for error checking
} p64h_sysc_spi_flash_xspi_stat_polarity_t;

/**
 * @brief
 *  XSPI crc chunk size.
 */
typedef enum {
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_4B   = 0U, ///< 4B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_8B   = 1U, ///< 8B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_16B  = 2U, ///< 16B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_32B  = 3U, ///< 32B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_64B  = 4U, ///< 64B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_128B = 5U, ///< 128B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_256B = 6U, ///< 256B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_512B = 7U, ///< 512B chunk size
    P64H_SYSC_XSPI_CRC_CHUNK_SIZE_LAST       ///< invalid used for error checking
} p64h_sysc_spi_flash_xspi_crc_chunk_size_t;

/**
 * @brief
 *  Data bytes per Flash Memory address
 */
typedef enum {
    P64H_SYSC_XSPI_XSPI_DATA_PER_ADDRESS_1B = 0U, ///< 1B per address
    P64H_SYSC_XSPI_XSPI_DATA_PER_ADDRESS_2B = 1U, ///< 2B per address
    P64H_SYSC_XSPI_XSPI_DATA_PER_ADDRESS_LAST     ///< invalid used for error checking
} p64h_sysc_spi_flash_xspi_data_per_address_t;

/**
 * @brief
 *  XSPI crc chunk variant.
 */
typedef enum {
    P64H_SYSC_XSPI_CRC_VARIANT_CALC_ADDR_PHASE
        = 0U, ///< CRC is calculated for all bytes of address transfer phase only and put on the bus after address transfer phase
    P64H_SYSC_XSPI_CRC_VARIANT_CALC_ALL_PHASES = 1U, ///< CRC is calculated for all bytes in sequence and put on the bus after all bytes in sequence
    P64H_SYSC_XSPI_CRC_VARIANT_CALC_LAST             ///< invalid used for error checking

} p64h_sysc_spi_flash_xspi_crc_chunk_variant_t;

/**
 * @brief
 *  XSPI crc chunk variant.
 */
typedef enum {
    P64H_SYSC_XSPI_STAT_SEQ_ADDR_COUNT_1_ADDR_BYTE  = 0U, ///< 1B addr
    P64H_SYSC_XSPI_STAT_SEQ_ADDR_COUNT_2_ADDR_BYTES = 1U, ///< 2B addr
    P64H_SYSC_XSPI_STAT_SEQ_ADDR_COUNT_3_ADDR_BYTES = 2U, ///< 3B addr
    P64H_SYSC_XSPI_STAT_SEQ_ADDR_COUNT_4_ADDR_BYTES = 3U, ///< 4B addr
    P64H_SYSC_XSPI_STAT_SEQ_ADDR_COUNT_LAST               ///< invalid used for error checking
} p64h_sysc_spi_flash_xspi_stat_seq_addr_cnt_t;

/**
 * @brief
 *  Struct holds failure info for setting up the xspi controller.
 */
typedef struct {
    uint8_t                                  cmd;          ///< command for fail status
    uint32_t                                 addr;         ///< address phase for fail status
    uint8_t                                  addr_cnt;     ///< address beats for fail status
    bool                                     addr_enable;  ///< address enable for fail status
    uint8_t                                  cmd_ext;      ///< command extension for fail status
    uint8_t                                  dummy_cnt;    ///< dummy counts for the fail status
    p64h_sysc_spi_flash_xspi_stat_polarity_t polarity_val; ///< polarity for the fail bit
    bool                                     enable;       ///< enable for the fail check
    uint8_t                                  index;        ///< index of the fail bit
    p64h_sysc_spi_flash_xspi_word_size_t     word_size;    ///< word size for the command
} p64h_sysc_spi_flash_xspi_fail_cfg_t;

/**
 * @brief
 *  Program information for the xspi controller.
 */
typedef struct {
    uint8_t                              cmd;            ///< Command for page program
    uint8_t                              cmd_ext;        ///< Command extension for page program
    bool                                 cmd_ext_enable; ///< Command extension enable for page program
    uint8_t                              addr_cnt;       ///< Address byte count for the page program
    p64h_sysc_spi_flash_xspi_mode_t      cmd_ios;        ///< Command io count for page program
    p64h_sysc_spi_flash_xspi_mode_t      addr_ios;       ///< Address io count for page program
    p64h_sysc_spi_flash_xspi_mode_t      data_ios;       ///< Data io count for page program
    p64h_sysc_spi_flash_xspi_data_rate_t cmd_edge_mode;  ///< Command data rate
    p64h_sysc_spi_flash_xspi_data_rate_t addr_edge_mode; ///< Address data rate
    p64h_sysc_spi_flash_xspi_data_rate_t data_edge_mode; ///< Data edge rate
} p64h_sysc_spi_flash_xspi_program_seq_cfg_t;

/**
 * @brief
 *  Status information for the xspi controller.
 */
typedef struct {
    p64h_sysc_spi_flash_xspi_mode_t      cmd_ios;        ///< Command IO count for status
    p64h_sysc_spi_flash_xspi_mode_t      addr_ios;       ///< Address IO count for status
    p64h_sysc_spi_flash_xspi_mode_t      data_ios;       ///< Data IO count for status
    p64h_sysc_spi_flash_xspi_data_rate_t cmd_edge_mode;  ///< Command edge rate
    p64h_sysc_spi_flash_xspi_data_rate_t addr_edge_mode; ///< Address edge rate
    p64h_sysc_spi_flash_xspi_data_rate_t data_edge_mode; ///< Data edge rate
} p64h_sysc_spi_flash_xspi_status_seq_cfg_t;

/**
 * @brief
 *  Read information for the xspi controller.
 */
typedef struct {
    uint8_t                              cmd;                ///< Read sequence command
    uint8_t                              cmd_ext;            ///< Read sequence command extension
    bool                                 cmd_ext_enable;     ///< Read sequence command extension enable
    uint8_t                              addr_cnt;           ///< Read address count
    p64h_sysc_spi_flash_xspi_mode_t      cmd_ios;            ///< Command IO count for reads
    p64h_sysc_spi_flash_xspi_mode_t      addr_ios;           ///< Address IO count for reads
    p64h_sysc_spi_flash_xspi_mode_t      data_ios;           ///< Data IO count for reads
    p64h_sysc_spi_flash_xspi_data_rate_t cmd_edge_mode;      ///< Command edge rate
    p64h_sysc_spi_flash_xspi_data_rate_t addr_edge_mode;     ///< Address edge rate
    p64h_sysc_spi_flash_xspi_data_rate_t data_edge_mode;     ///< Data edge rate
    uint8_t                              dummy_cycles;       ///< Number of dummy cycles
    bool                                 read_seq_mb_enable; ///< If set to 1, mode bits are sent following the address bytes
    uint8_t read_seq_mb_dummy_cnt; ///< Number of dummy cycles (if 0 - disabled). Used when sending mode bits is enabled in ACMD or Direct work modes
    bool
        cache_random_read_enable; ///< This bit changes behavior of the Read sequence to utilize the Read Page Cache Random/Read Page Cache Random
                                  ///< Last commands. (not used in DIRECT mode) (Since R003) (in R004 applicable only for FULL/FULL_ASF configuration)
} p64h_sysc_spi_flash_xspi_read_seq_cfg_t;

/**
 * @brief
 *  Read information for the xspi controller.
 */
typedef struct {
    p64h_sysc_spi_flash_xspi_profile_t device_profile;    ///< Profile of external xspi device
    bool                               data_swap;         ///< Swap data bytes
    bool                               crc_ual_chunk_chk; ///< Enables checking correctness of CRC unaligned chunk from Flash device.
    bool crc_ual_chunk_enable; ///< Enables taking into consideration the command address to determine after how many bytes CRC data slice expected to
                               ///< be returned from device
    p64h_sysc_spi_flash_xspi_crc_chunk_size_t crc_chunk_size; ///< Number of bytes after which CRC occurs
    bool crc_toogle_data; ///< If set, the controller expects the xSPI device to toggle CRC data on both SPI clock edges in CRC->CRC# sequence
    p64h_sysc_spi_flash_xspi_crc_chunk_variant_t crc_variant; ///< Selecting of CRC variant (in R004 field applicable only for FULL/FULL_ASF
                                                              ///< configuration, in IOT_NODLL this feature is enabled in STIG work mode only
    bool                                        crc_dynamic_calc_enable; ///< If set, dynamic CRC calculation is enabled
    p64h_sysc_spi_flash_xspi_data_per_address_t data_per_address; ///< Indicates how many bytes of data is assigned to the single Flash Memory address
    p64h_sysc_spi_flash_xspi_page_size_t        program_page_size; ///< Determines page size of device being used for PROGRAM
    p64h_sysc_spi_flash_xspi_page_size_t        read_page_size;    ///< Determines page size of device being used for READ
} p64h_sysc_spi_flash_xspi_global_param_cfg_t;

/**
 * @brief
 *  Status sequence information for the xspi controller.
 */
typedef struct {
    p64h_sysc_spi_flash_xspi_mode_t              cmd_ios;          ///< Command IO count for reads
    p64h_sysc_spi_flash_xspi_mode_t              addr_ios;         ///< Address IO count for reads
    p64h_sysc_spi_flash_xspi_mode_t              data_ios;         ///< Data IO count for reads
    bool                                         cmd_ext_enable;   ///< status sequence comand extension
    p64h_sysc_spi_flash_xspi_data_rate_t         cmd_edge_mode;    ///< Command edge mode
    p64h_sysc_spi_flash_xspi_data_rate_t         addr_edge_mode;   ///< Address edge mode
    p64h_sysc_spi_flash_xspi_data_rate_t         data_edge_mode;   ///< Data edge mode
    p64h_sysc_spi_flash_xspi_fail_cfg_t          prog_fail_cfg;    ///< configuration for program fail
    p64h_sysc_spi_flash_xspi_fail_cfg_t          dev_rdy_fail_cfg; ///< Device Ready fail config
    p64h_sysc_spi_flash_xspi_fail_cfg_t          erase_fail_cfg;   ///< Erase Fail configuration
    p64h_sysc_spi_flash_xspi_stat_seq_addr_cnt_t addr_cnt;         ///< Address count
} p64h_sysc_spi_flash_xspi_stat_seq_cfg_t;

/**
 * @brief
 *  Direct mode config information for the xspi controller.
 */
typedef struct {
    uint32_t dac_addr_mask; ///< This mask is used for anding bits [44:32] of the system address for read/write transfers in Legacy Hyperflash and
                            ///< xSPI Profile 2.0 mode
    bool disable_auto_poll; ///< If set, disable auto-polling of memory device
    bool disable_auto_wel_instr; ///< If set, disable automatic issuing of WEL instruction before write operation (involves profile 1.0 sequence type)
    bool dis_xip_mb;             ///< Disable XIP with modebits
    bool en_xip_mb;              ///< Enable XIP with modebits
    bool remap_addr_en; ///< Enables Slave Data interface address rempping. When set to 1, the incoming Slave Data Interface address will be adopted
                        ///< and sent to the Flash device
} p64h_sysc_spi_flash_xspi_direct_mode_cfg_t;

/**
 * @brief
 *  Direct mode config information for the xspi controller.
 */
typedef struct {
    uint8_t                              wel_cmd;            ///< write enable command
    bool                                 wel_cmd_enable;     ///< write enable command enable
    uint8_t                              wel_cmd_ext;        ///< write enable command extension
    bool                                 wel_cmd_ext_enable; ///< write enable command extension enable
    p64h_sysc_spi_flash_xspi_mode_t      cmd_ios;            ///< command number of lanes
    p64h_sysc_spi_flash_xspi_data_rate_t cmd_edge_mode;      ///< command edge mode
} p64h_sysc_spi_flash_xspi_wel_seq_cfg_t;

/**
 * @brief
 *  STIG instruction types avaialble in the controller.
 */

typedef enum {
    P64H_SYSC_XSPI_STIG_P1_READ_ARRAY               = 0U,  ///< Read Array
    P64H_SYSC_XSPI_STIG_P1_READ_ARRAY_XIP           = 1U,  ///< Read Array XIP
    P64H_SYSC_XSPI_STIG_P1_WRITE_ARRAY              = 2U,  ///< Write array
    P64H_SYSC_XSPI_STIG_P1_WRITE_ENABLE_LATCH       = 3U,  ///< Write Enable Latch
    P64H_SYSC_XSPI_STIG_P1_WRITE_DISABLE_LATCH      = 4U,  ///< Write Disable Latch
    P64H_SYSC_XSPI_STIG_P1_ERASE_SECTOR             = 5U,  ///< Erase Sector
    P64H_SYSC_XSPI_STIG_P1_CHIP_ERASE               = 6U,  ///< Chip Erase
    P64H_SYSC_XSPI_STIG_P1_PROGRAM_ERASE_SUSPEND    = 7U,  ///< Program/Erase Suspend
    P64H_SYSC_XSPI_STIG_P1_PROGRAM_ERASE_RESUME     = 8U,  ///< Program/Erase Resume
    P64H_SYSC_XSPI_STIG_P1_READ_MEMORY_REGISTER     = 9U,  ///< Read Memory Register
    P64H_SYSC_XSPI_STIG_P1_WRITE_MEMORY_REGISTER    = 10U, ///< Write Memory Register
    P64H_SYSC_XSPI_STIG_P1_SETUP_READ_BURST         = 11U, ///< Setup Read Burst
    P64H_SYSC_XSPI_STIG_P1_CLEAR_FLAG_REGISTER      = 12U, ///< Clear Flag Register
    P64H_SYSC_XSPI_STIG_P1_ENTER_DEEP_POWER_DOWN    = 13U, ///< Enter Deep Power Down
    P64H_SYSC_XSPI_STIG_P1_EXIT_DEEP_POWER_DOWN     = 14U, ///< Exit Deep Power Down
    P64H_SYSC_XSPI_STIG_P1_RESET_ENABLE             = 15U, ///< Reset Enable
    P64H_SYSC_XSPI_STIG_P1_SOFT_RESET               = 16U, ///< Soft Reset
    P64H_SYSC_XSPI_STIG_P1_READ_JEDEC_ID            = 17U, ///< Read JEDEC ID
    P64H_SYSC_XSPI_STIG_P1_READ_SFDP                = 18U, ///< Read SFDP
    P64H_SYSC_XSPI_STIG_P1_ENTER_DEF_PROT_MODE      = 19U, ///< Enter default protocol mode
    P64H_SYSC_XSPI_STIG_P1_ENABLE_SDR_OCTAL_MODE    = 20U, ///< Enable SDR Octal Mode
    P64H_SYSC_XSPI_STIG_P1_GLOBAL_PROTECTION        = 21U, ///< Global Protection
    P64H_SYSC_XSPI_STIG_P1_GLOBAL_UNPROTECTION      = 22U, ///< Global unprotection
    P64H_SYSC_XSPI_STIG_P1_PROTECT_SECTOR           = 23U, ///< Protect Sector
    P64H_SYSC_XSPI_STIG_P1_UNPROTECT_SECTOR         = 24U, ///< Unprotect Sector
    P64H_SYSC_XSPI_STIG_P1_ENTER_4BYTE_ADDR_MODE    = 25U, ///< Enter 4 byte address mode
    P64H_SYSC_XSPI_STIG_P1_EXIT_4BYTE_ADDR_MODE     = 26U, ///< Exit 4 byte address mode
    P64H_SYSC_XSPI_STIG_P1_SNA_READ_PAGE            = 27U, ///< Read Page
    P64H_SYSC_XSPI_STIG_P1_SNA_READ_CACHE           = 28U, ///< Read from cache
    P64H_SYSC_XSPI_STIG_P1_SNA_RAND_READ_PAGE_CACHE = 29U, ///< Read Page Cache Random
    P64H_SYSC_XSPI_STIG_P1_SNA_LAST_READ_PAGE_CACHE = 30U, ///< Read page cache last
    P64H_SYSC_XSPI_STIG_P1_SNA_PROGRAM_LOAD         = 31U, ///< Program load
    P64H_SYSC_XSPI_STIG_P1_SNA_RAND_PROGRAM_LOAD    = 32U, ///< Program load random
    P64H_SYSC_XSPI_STIG_P1_SNA_PROGRAM_EXEC         = 33U, ///< Program execute
    P64H_SYSC_XSPI_STIG_P1_SNA_SET_FEATURES         = 34U, ///< Set features
    P64H_SYSC_XSPI_STIG_P1_SNA_GET_FEATURES         = 35U, ///< Get Features
    P64H_SYSC_XSPI_STIG_P1_SNA_READ_ID              = 36U, ///< Read ID
    P64H_SYSC_XSPI_STIG_P1_LAST                            ///< Last invalid type
} p64h_sysc_spi_flash_xspi_profile1_stig_instr_type_t;

/**
 * @brief
 *  STIG initialization instruction for external memory.
 *  Note this currently doesn't support glueing instructions
 *  and only supports profile 1 instructions.
 */
typedef struct {
    p64h_sysc_spi_flash_xspi_profile1_stig_instr_type_t profile1_instr_type;  ///< STIG instruction type
    uint8_t                                             data_number_of_bytes; ///< Number of data bytes 0,1,2 are the options
    uint8_t                                             data_byte_0;          ///< The first data byte
    uint8_t                                             data_byte_1;          ///< The second data byte
    uint8_t                                             cmd;                  ///< Value to use in the cmd phase.
    uint8_t                                             cmd_ext;              ///< command extension value.
    bool                                                cmd_ext_enable;       ///< command extension enable.
    uint8_t                                             addr_cnt;             ///< number of address cycles
    p64h_sysc_spi_flash_xspi_mode_t                     cmd_ios;              ///< command ios
    p64h_sysc_spi_flash_xspi_mode_t                     addr_ios;             ///< address ios
    p64h_sysc_spi_flash_xspi_data_rate_t                cmd_edge_mode;        ///< command edge mode
    p64h_sysc_spi_flash_xspi_data_rate_t                addr_edge_mode;       ///< address edge mode
    uint32_t                                            addr;                 ///< address value
} p64h_sysc_spi_flash_xspi_stig_init_instr_t;

/**
 * @brief
 * Contains the information for the block protection for the xspi device
 */
typedef struct {
    uint8_t  bp_cmd;            ///< Register command for the block protect bits
    uint32_t bp_addr;           ///< address for the block protect command
    uint8_t  bp_addr_cnt;       ///< address count for the block protect command
    uint8_t  bp_data_num_bytes; ///< Number of data bytes 1,2 are the options
    uint32_t bp_min_size;       ///< Smallest block protect size in Bytes
    uint16_t bp_mask;           ///< The location of the bp bits.
    uint8_t  tb_cmd;            ///< Register command for the top/bottom select bit
    uint32_t tb_addr;           ///< address for the top/bottom select command
    uint8_t  tb_addr_cnt;       ///< address coutn for the top/bottom select command
    uint8_t  tb_data_num_bytes; ///< Number of data bytes 0,1,2 are the options
    uint8_t  tb_index;          ///< The index of the top/bottom select bit in the register
    uint8_t  bottom_select;     ///< Value for selecting bottom in the register
    uint32_t top_address;       ///< The last address in the memory array
} p64h_sysc_spi_flash_xspi_block_lock_t;

/**
 * @brief
 * Configures the device relative delays
 */
typedef struct {
    uint8_t csda_min_delay; ///< CSDA_MIN  Minimum Chip Select de-assertion timing
    uint8_t cseot_delay;    ///< CSEOT  Chip Select End Of Transfer. It allows to improve last active clock edge to CS de-assertion device timing
    uint8_t cssot_delay;    ///< Chip Select Start Of Transfer. It allows to improve CS de-assertion device timing to first active clock edge
} p64h_sysc_spi_flash_xspi_dev_rel_dly_t;

/**
 * @brief
 * Configures the commands for the reset
 */
typedef struct {
    uint8_t cmd;        ///< reset command
    uint8_t enable_cmd; ///< reset enamble command
} p64h_sysc_spi_flash_xspi_reset_cmd_t;

/**
 * @brief
 * Configures the command and timeout for chip erase
 */
typedef struct {
    uint8_t  cmd;     ///< chip erase command
    uint32_t timeout; ///< chip erase timeout in ms
} p64h_sysc_spi_flash_xspi_chip_erase_t;

/**
 * @brief
 * Configuration struct for the xspi phy
 */
typedef struct {
    uint32_t boot_cfg;                ///< initial xspi boot config
    uint32_t xspi_init_rb_valid_time; ///< Initial value of the rb valid time register
    uint32_t phy_dq_timing;           ///< Initial value of the dq timing register
    uint32_t phy_dqs_timing;          ///< Initial value of the dqs timing register
    uint32_t phy_gate_lpbk_ctrl;      ///< Initial value of the gate loopback control register
    uint32_t phy_dll_master_ctrl;     ///< Initial value of the dll master control register
    uint32_t phy_dll_slave_ctrl;      ///< Initial value of the phy dll slave control register
    uint32_t xspi_discovery;          ///< Initial value of the xspi discover register

} p64h_sysc_spi_flash_xspi_phy_cfg_t;

/**
 * @brief
 *  Defines xSPI block configuration inside SPI_CTRL
 */
typedef struct {
    uint32_t                                    num_reset;         ///< number of resets
    p64h_sysc_top_nvm_acsu_ctrl_clk_out_t       ctrl_clk;          ///< Controller
    p64h_sysc_spi_flash_xspi_program_seq_cfg_t  program_seq_cfg;   ///< information for the program sequence
    p64h_sysc_spi_flash_xspi_read_seq_cfg_t     read_seq_cfg;      ///< information for the read sequence
    p64h_sysc_spi_flash_xspi_global_param_cfg_t global_param_cfg;  ///< information for the global pramaters config
    p64h_sysc_spi_flash_xspi_reset_cmd_t        reset_cmd_cfg;     ///< Information for the reset command config
    p64h_sysc_spi_flash_xspi_block_lock_t       block_protect_cfg; ///< information for the block protection scheme for the device.
    p64h_sysc_spi_flash_xspi_dev_rel_dly_t      dev_rel_dly_cfg;   ///< information for the device relative delay config
    p64h_sysc_spi_flash_xspi_wel_seq_cfg_t      wel_seq_cfg;       ///< information for the write enable config
    p64h_sysc_spi_flash_xspi_chip_erase_t       chip_erase_cfg;    ///< information for the chip erase config
    p64h_sysc_spi_flash_xspi_sector_t
             subsector_data_arr[P64H_SYSC_NVM_XSPI_SUBSECTOR_ARR_SIZE]; ///< contians subsector information maximum of 4 entries
    uint32_t subsector_data_arr_len;                                    ///< length of subsector info
    p64h_sysc_spi_flash_xspi_sector_t          sector_data;             ///< contians sector information
    p64h_sysc_spi_flash_xspi_stat_seq_cfg_t    stat_seq_cfg;            ///< status sequence config
    p64h_sysc_spi_flash_xspi_direct_mode_cfg_t direct_mode_cfg;         ///< direct mode config

    // instructions for the setup of the external memory
    p64h_sysc_spi_flash_xspi_stig_init_instr_t
             stig_init_cmd_arr[P64H_SYSC_NVM_XSPI_STIG_INIT_CMD_ARR_SIZE]; ///< STIG initialization commands maximum of 8 entries
    uint32_t stig_init_cmd_arr_len;                                        ///< length of STIG initializaiton commands
    p64h_sysc_spi_flash_xspi_phy_cfg_t initial_phy_config;                 ///< Phy config at bringup
} p64h_sysc_spi_flash_xspi_cfg_t;

/// PFlash controller width options
typedef enum {
    P64H_SYSC_PFLASH_DATA_WIDTH_8B  = 8u,  ///< Parallel flash 8b data width
    P64H_SYSC_PFLASH_DATA_WIDTH_16B = 16u, ///< Parallel flash 16b data width
    P64H_SYSC_PFLASH_DATA_WIDTH_32B = 32u, ///< Parallel flash 32b data width
    P64H_SYSC_LAST_PFLASH_DATA_WIDTH,      ///< Out of range value.
} p64h_sysc_pflash_data_width_t;

/// NVM NAND controller boot configuration
typedef struct {
    bool     write_protect_en; ///< enable write protect
    bool     pslc_mode_en;     ///< seudo-Single Level Cell support
    bool     parity_en;        ///< enable parity
    bool     crc_en;           ///< enable CRC
    uint16_t sec_size;         ///< ECC sector size if ECC is enabled
    uint8_t  ecc_corr_str;     ///< correction strength (0 - 4 range)
    bool     ecc_en;           ///< enable ECC
    bool     boot_en;          ///< enable automatic boot process
} p64h_sysc_nand_boot_cfg_t;

/// Device discovery configuration for NAND controller
typedef struct {
    bool     enable;            ///< Enable device discovery feature
    uint16_t pages_per_block;   ///< Pages per block
    uint16_t page_size;         ///< Page size
    uint8_t  lun;               ///< LUN (logical unit number)
    bool     data_width_16b_en; ///< enable support for 16b data width
    uint8_t  addr_width;        ///< address width
} p64h_sysc_nand_dd_cfg_t;

/// SECDED configuration for NAND controller
typedef struct {
    bool    enable;               ///< Enable SECDED
    bool    m_en_bypass;          ///< Bypass generation and checking of SECDED on Manager AXI Bus
    bool    s_en_bypass;          ///< Bypass generation and checking of SECDED on Subordinate  AXI Bus
    bool    timeout_en;           ///< Enable timeout feature
    uint8_t timeout_clock_cycles; ///< number of clock-cycles for a timeout to occur (<= 34)
} p64h_sysc_nand_secded_cfg_t;

/// NAND parameters
typedef struct {
    bool                                  ddr_support; ///< TRUE - DDR support
    uint8_t                               bit_width;   ///< data bus width
    p64h_sysc_top_nvm_acsu_ctrl_clk_out_t ctrl_clk;    ///< NVM controller clock
} p64h_sysc_nand_params_t;

/// Defines NVM_CTRL configuration for NAND
typedef struct {
    p64h_sysc_nand_params_t     params;     ///< see p64h_sysc_nand_params_t
    p64h_sysc_nand_boot_cfg_t   boot_cfg;   ///< see p64h_sysc_nand_boot_cfg_t
    p64h_sysc_nand_dd_cfg_t     dd_cfg;     ///< see p64h_sysc_nand_dd_cfg_t
    p64h_sysc_nand_secded_cfg_t secded_cfg; ///< see p64h_sysc_nand_secded_cfg_t
} p64h_sysc_nand_flash_cfg_t;

/// Structure presenting some of the dynamic PFlash parameters extracted from FDT as per the device's data sheet.
typedef struct {
    bool                          write_protect; ///< true write protection is enabled, else not
    p64h_sysc_pflash_data_width_t data_width;    ///< Data width. 8b, 16b, or 32b
    uint32_t                      address_width; ///< Address width TODO: why?
    uint32_t                      page_mask;     ///< 32-bit page page mask defines which bsts of the parallel flash address access pages of memory.
    uint8_t cs_en; ///< Bit mask indicating which of the 8 flash devices are enabled. 0xFF all 8, 0x3 devices 1 and 2 only for example.
    bool    ico;   ///< If set then limits device commands to initial command operations only.
} p64h_sysc_pflash_cfg_interface_port_t;

/// Structure set per device regarding the page/address range associated with the device that is then AXI accessible
typedef struct {
    bool     valid;                                           ///< Flag indicating set of cs_page_range values are valid.
    uint64_t cs_page_range[PFLASH_CFG_CS_PAGE_RANGE_INDICES]; ///< Indices of upper and lower address. Lower address is 0 (inclusive) and upper is 1
                                                              ///< (exclusive)
} p64h_sysc_pflash_cfg_cs_page_map_t;

/// Defines a set of values which switch sideband interface polarities
typedef struct {
    bool cef;  ///< Sets the polarity of pflash_cen signal for he various cs_en devices. Polarity is the same for all devices and thus only
               ///< one value is required. If high then pflash_cen is active high. Defaults to active low.
    bool oef;  ///< Applies to polarity of output enable signal.  1 polarity is active high, 0 low. Defaults to active low.
    bool wef;  ///< Sets polarity of write enable. Defaults active low.
    bool rdyf; ///< Sets the polarity of pflash_ready. Defaults to active high and can be set here to be active low.
} p64h_sysc_pflash_cfg_interface_polarity_t;

/// Defines a set of values which switch the enables of the device ready checks and chip-select address mapping checks done by the PFlash Controller
typedef struct {
    bool ready_write_check;  ///< Enables status checks of pflash_ready in all writes with the exception of TWWHDX and during EEPROM buffer
                             ///< writes. Applies to cfg_check_ready_write
    bool ready_read_check;   ///< Enables whether pflash_ready status is checked for all read states. If set, 1, generates SLVERR if read
                             ///< operation is invoked when pflash_ready is not ready. Applies to cfg_check_ready_read
    bool ready_twwhdx_check; ///< Enable checking pflash_ready status during TWWHDX state. Generates a slave error to AXI bus if enable
                             ///< and device is not ready. falsde check is not performed. Applies to cfg_check_ready_twwhdx
    bool ignore_ready;       ///< If set, true, then pflash_ready is always assumed to be asserted. false normal pflash_ready operation.
                             ///< Applies to cfg_ignore_ready
    bool override_cs_check;  ///< When set high, overrides any chip-select address mapping checks
} p64h_sysc_pflash_cfg_interface_check_t;

/// Defines pflash configuration interface.
typedef struct {
    bool en_byte_cmd;        ///< Word Addressing Override. When set HIGH, uses byte-addressing mode for sending transactions to the memory
                             ///< which are smaller than memory width.
    bool en_byte_write;      ///< 8b Write Command Enable. Allows writes of 8b to device if HIGH. Throws a cfg_write_width_event otherwise.
    bool en_half_word_write; ///< 16b Write Command Enable. Allows writes of 16b to device if HIGH. Throws a cfg_write_width_event otherwise.
    bool en_word_write;      ///< 32b Write Command Enable. Allows writes of 32b to device if HIGH. Throws a cfg_write_width_event otherwise.
} p64h_sysc_pflash_cfg_intf_addr_mode_t;

/// Defines a set of values that set delays, clk cycles, to be applied to read and write operations.
typedef struct {
    p64h_sysc_top_nvm_acsu_ctrl_clk_out_t ctrl_clk; ///< Controller clock
    uint8_t travel;  ///< Number of mhclk cycles controlling address valid to chip delay during an initial read; Range: 0-255
    uint8_t trelgl;  ///< Number of mhclk cycles to control chip enable to output enable during initial read. Range: 0-255
    uint8_t trglqv;  ///< Number of mhclk cycles to control output enable to read data during initial read. Range: 2-253
    uint8_t trqvqv;  ///< Number of mhclk cycles to control address to data valid delay during a subsequent read. Range: 2-253
    uint8_t trqvpqv; ///< Number of mhclk cycles to control address to data valid delay during a page read. Range: 0-255
    uint8_t twavel;  ///< Number of mhclk cycles to control address valid to chip enable delay during an initial read. Range: 0-255
    uint8_t tweldv;  ///< Number of mhclk cycles to control the chip enable to data valid delay during an intiial write. Range: 1-254
    uint8_t twdvwl;  ///< Number of mhclk cycles to control the data valid to write enable delay during an write. Range: 1-254
    uint8_t twwlwh;  ///< Number of mhclk cycles to control the write enable to write disable delay during a write. Range: 1-254
    uint8_t twwhdx;  ///< Number of mhclk cycles to control the write disable to data invalid delay during a write. Range: 1-254
} p64h_sysc_pflash_cfg_interface_delay_t;

/// There are two possible driver instances and so group all the data in two element array. Currently storing all the set data locally which
/// should also be reflected in associated registers.
typedef struct {
    p64h_sysc_pflash_cfg_interface_port_t     intf_port;                           ///< Structure of interface related settings.
    p64h_sysc_pflash_cfg_cs_page_map_t        cs_page_map[PFLASH_CTRL_DEVICE_MAX]; ///< CS page or CS address mapping.
    p64h_sysc_pflash_cfg_interface_polarity_t intf_polarity;                       ///< Settings related to sideband interface polarities.
    p64h_sysc_pflash_cfg_interface_check_t    intf_check;                          ///< Settings related to user specified ready checks.
    p64h_sysc_pflash_cfg_intf_addr_mode_t     intf_addr_mode;                      ///< PFlash controller addressing mode.
    p64h_sysc_pflash_cfg_interface_delay_t    intf_delay;                          ///< Delay settings for commands.
} p64h_sysc_pflash_cfg_t;

/// S29GL01GS ID-CFI Address Space Overlay (ASO), word-addressed (x16), offsets relative to sector address
typedef struct {
    /// ID (Autoselect) Address Map
    uint16_t manufacturer_id;       ///< (SA) + 0x0000
    uint16_t device_id_start;       ///< (SA) + 0x0001
    uint16_t sect_protect_verif;    ///< (SA) + 0x0002
    uint16_t indicator_bits;        ///< (SA) + 0x0003
    uint16_t reserved_0004_000B[8]; ///< (SA) + 0x0004–0x000B
    uint16_t lower_software_bits;   ///< (SA) + 0x000C
    uint16_t upper_software_bits;   ///< (SA) + 0x000D
    uint16_t device_id_density;     ///< (SA) + 0x000E
    uint16_t device_id_end;         ///< (SA) + 0x000F
    /// CFI Query Identification String
    uint16_t qry[3];                   ///< (SA) + 0x0010-0x0012
    uint16_t prim_oem_cmd_set[2];      ///< (SA) + 0x0013-0x0014
    uint16_t prim_oem_ext_tbl_addr[2]; ///< (SA) + 0x0015-0x0016
    uint16_t alt_oem_cmd_set[2];       ///< (SA) + 0x0017-0x0018
    uint16_t alt_oem_ext_tbl_addr[2];  ///< (SA) + 0x0019-0x001A
    /// CFI System Interface String
    uint16_t vcc_min;                 ///< (SA) + 0x001B
    uint16_t vcc_max;                 ///< (SA) + 0x001C
    uint16_t vpp_min;                 ///< (SA) + 0x001D
    uint16_t vpp_max;                 ///< (SA) + 0x001E
    uint16_t word_prog_time_typ;      ///< (SA) + 0x001F
    uint16_t buf_prog_time_typ;       ///< (SA) + 0x0020
    uint16_t sect_erase_time_typ;     ///< (SA) + 0x0021
    uint16_t chip_erase_time_typ;     ///< (SA) + 0x0022
    uint16_t word_prog_time_max_mul;  ///< (SA) + 0x0023
    uint16_t buf_prog_time_max_mul;   ///< (SA) + 0x0024
    uint16_t sect_erase_time_max_mul; ///< (SA) + 0x0025
    uint16_t chip_erase_time_max_mul; ///< (SA) + 0x0026
    /// CFI Device Geometry Definition
    uint16_t device_size;             ///< (SA) + 0x0027
    uint16_t device_intf_desc[2];     ///< (SA) + 0x0028-0x0029
    uint16_t buf_prog_bytes_max[2];   ///< (SA) + 0x002A-0x002B
    uint16_t erase_block_regions_num; ///< (SA) + 0x002C
    uint16_t erase_block_region1[4];  ///< (SA) + 0x002D–0x0030
    uint16_t erase_block_region2[4];  ///< (SA) + 0x0031–0x0034
    uint16_t erase_block_region3[4];  ///< (SA) + 0x0035–0x0038
    uint16_t erase_block_region4[4];  ///< (SA) + 0x0039–0x003C
    uint16_t reserved_003D_003F[3];   ///< (SA) + 0x003D–0x003F
    /// CFI Primary (PRI) Vendor-Specific Extended Query
    uint16_t pri[3];                       ///< (SA) + 0x0040-0x0042
    uint16_t pri_major_version_num;        ///< (SA) + 0x0043
    uint16_t pri_minor_version_num;        ///< (SA) + 0x0044
    uint16_t asu_proc_tech_bits;           ///< (SA) + 0x0045
    uint16_t erase_suspend_support;        ///< (SA) + 0x0046
    uint16_t sect_protect_support;         ///< (SA) + 0x0047
    uint16_t temp_sect_unprotect_support;  ///< (SA) + 0x0048
    uint16_t sect_protect_scheme;          ///< (SA) + 0x0049
    uint16_t simultaneous_op_support;      ///< (SA) + 0x004A
    uint16_t burst_mode_type_support;      ///< (SA) + 0x004B
    uint16_t page_mode_type_support;       ///< (SA) + 0x004C
    uint16_t acc_supply_min_support;       ///< (SA) + 0x004D
    uint16_t acc_supply_max_support;       ///< (SA) + 0x004E
    uint16_t wp_support;                   ///< (SA) + 0x004F
    uint16_t prog_suspend_support;         ///< (SA) + 0x0050
    uint16_t unlock_bypass_support;        ///< (SA) + 0x0051
    uint16_t sss_size;                     ///< (SA) + 0x0052
    uint16_t sw_features;                  ///< (SA) + 0x0053
    uint16_t page_size;                    ///< (SA) + 0x0054
    uint16_t erase_suspend_time_max;       ///< (SA) + 0x0055
    uint16_t prog_suspend_time_max;        ///< (SA) + 0x0056
    uint16_t reserved_0057_0077[33];       ///< (SA) + 0x0057–0x0077
    uint16_t embedded_hw_rst_time_max;     ///< (SA) + 0x0078
    uint16_t non_embedded_hw_rst_time_max; ///< (SA) + 0x0079
} p64h_sysc_pflash_id_cfi_aso_map_t;

/**
 * @brief
 *  Defines the set of memory controller configurable by system controller
 */
typedef struct {
    p64h_sysc_pflash_cfg_t         pflash_cfg; ///< PFLASH memory controller settings
    p64h_sysc_spi_flash_xspi_cfg_t xspi_cfg;   ///< xSPI CTRL configuration
    p64h_sysc_nand_flash_cfg_t     nand_cfg;   ///< NAND configuration
} p64h_sysc_nvm_ctrl_cfg_t;

/// SRAM Dual Modular Redundancy (DMR) configuration
typedef struct {
    bool enable;               ///< enable DMR
    bool data_single_mode_ovr; ///< RRESP override: changes SLVERR to OKAY. Condition: data mismatches, and one subordinate returns uncorrectable data
    bool data_err_compare_ovr; ///< RRESP override: changes SLVERR to OKAY. Condition: both subordinates returned corrected data
    bool data_mm_ovr;          ///< RRESP override: changes SLVERR to OKAY. Condition: Data mismatches
    bool rid_mm_ovr; ///< RRESP override: changes SLVERR to OKAY. Condition: one subordinate returns uncorrectable data and the other returns OKAY
    bool slverr_ovr; ///< RRESP override: changes SLVERR to OKAY. Condition: one subordinate returns uncorrectable data and the other returns OKAY
    uint8_t dmr_default_s; ///<  In the instance that the data incoming is not identical and the voting logic cannot make decision, then the default
                           ///<  configuration is selected.
    // DMR counter configuration
    bool sub1_chosen_cnt_en; ///< Enable counter for occurrences which subordinate 1 was chosen
    bool sub0_chosen_cnt_en; ///< Enable counter for occurrences which subordinate 0 was chosen
    bool mm_cnt_en; ///< Enable counter for number of occurrences when data has mismatched but the more correct value was chosen. Accumulated since
                    ///< counter has been last cleared.
    bool mm_uncorr_err_cnt_en; ///< Enable counter for number of occurrences when both subordinates are uncorrectable. Accumulated since counter has
                               ///< been last cleared.
    bool mm_data_err_cnt_en;   ///< Enable counter for number of mismatches when mismatch data have no errors reported from ECC decoding. Accumulated
                               ///< since counter has been last cleared.
} p64h_sysc_sram_dmr_cfg_t;

/// NVM Dual Modular Redundancy (DMR) configuration
typedef struct {
    bool    enable;       ///< enable DMR
    bool    retry_enable; ///< Set this bit to limit the number of retires to the DMR interface.
    uint8_t retry_count;  ///< The number of DMR interface requests before declaring the other NDC has timed out
} p64h_sysc_nvm_dmr_cfg_t;

/// SRAM FEC addr range
typedef struct {
    p64h_sysc_mem_fec_mode_t fec_mode; ///< FEC mode associated to the range (BYPASS, SECDED or BCH)
    uint32_t start_addr_map; ///< Start address for the configured ECC mapping address range. The configured value is a 30 bits value shifted by 3 to
                             ///< give the 33 bits address. The addresses configured are inclusive. BCH Start Addresses should be block aligned
                             ///< values. Addresses are base on pre-ECC memory ranges. start_addr = {start_addr_map, 3b000}
    uint32_t end_addr_map; ///< End address for the configured ECC mapping address range. The configured value is a 30 bits value shifted by 3 to give
                           ///< the 33 bits address.  The addresses configured are inclusive. end_addr = {end_addr_map , 3b111};
} p64h_sysc_sram_fec_addr_range_t;

/// @brief SRAM EDAC parameters
typedef struct {
    bool rd_wr_arb_en;              ///< when enabled, SRAM EDAC alternates Read and write transactions on the egress interface.
    bool wdgen_uncor_wstrb_zero_en; ///< when enabled, the write strobes are cleared when an uncorrectable error is detected.
                                    ///< Otherwise, the write is allowed to proceed with the potentially corrupted strobes or wlast. Also, if set
                                    ///< Paritial writes will be dropped on uncorrectable reads. If the external memory is not initialized and
                                    ///< paritial writes occur this will prevent proper initialization. To prevent this set this low. Once memory is
                                    ///< initialized this can be set again.
    bool wstrb_sparse_det_en;       ///< when enabled, wstrb sparse detection for RMW operations.
                                    ///< If the AXI wstrb is not set to all ones on incoming data, with this enabled, a RMW operation will occur.
    bool     encode_bus_secded_bypass; ///< bypass axi bus secded checking in the encoder
    bool     bus_secded_bypass;        ///< bypass AXI Bus secded checking
    bool     addr_chk_en;              ///< Enables address checking on decoding.
    uint16_t emon_uncor_buf_limit; ///< 9 bit field. Maximum number of entries before creating a threshold interrupt Nx_EMON_UNCOR_BUF_HIGH_THRHLD_Ix
    uint16_t emon_cor_buf_limit;   ///< 9 bit field. Maximum number of entries before creating a threshold interrupt Nx_EMON_COR_BUF_HIGH_THRHLD_Ix
} p64h_sysc_sram_edac_inst_param_t;

/// @brief NVM EDAC parameters
typedef struct {
    uint8_t iommu_sel;         ///< IOMMU selection for the NDC IO bridge. 0 and 1 are valid value
    bool    ndc_enabled;       ///< Enable using at least one thread in NDC
    bool    ram_in_use;        ///< Enable usage of NDC RAM
    bool    ram_timeout_en;    ///< Enables the RAM timeout.
    bool    ram_force_drop;    ///< Enables force dropping all transactions for the NDC RAM.
    uint8_t ram_timeout_cfg;   ///< 5 bits field. The NDC RAM timeout timer will assert if the AXI interfaces ready valid handshake is waiting on the
                               ///< AXI RAM subordinate. Enable this timeout timer with AF_Nx_RAM_TIMEOUT_EN. Timer Duration = clock period *
                               ///< 2^(ram_timeout_cfg +1) + clock period Maximum value: 34
    uint8_t timeout_timer_cfg; ///< Timeout timer configuration, assert timeout_timer_en to enable timer.
                               ///< Timer Duration = clock period * 2^(timeout_timer_cfg +1) + clock period
                               ///< Maximum value: 30 (600MHz Clock is ~3.5s )
                               ///< Minimum value: The timeout should not be configured lower than the longest expected transaction time. The longest
                               ///< transaction will be the data transfer of the pages during a double buffer operation between the NAND buffer and
                               ///< HOST memory. This will depend on bus utilization and memory type used. This means that the timeout should be much
                               ///< larger than worst case estimates.

    bool timeout_timer_en; ///< Enable register for the NDC timeout timer. The NDC is an AXI initiator, on transaction requests, if responses are not
                           ///< received before this timeout timer expires a timeout error is generated.

    uint8_t
        poll_timer_cfg; ///< To reduce the number of polling NOC transactions a timer is used to delay the NDC when all threads are in a wait state.
                        ///< The duration of the wait is:
                        ///< Wait time = clock period * 2^( poll_timer_cfg +1) + clock period
                        ///< Maximum value: 16
    uint16_t emon_uncor_buf_limit; ///< 9 bit field. Maximum number of entries before creating a threshold interrupt Nx_EMON_UNCOR_BUF_HIGH_THRHLD_Ix
    uint16_t emon_cor_buf_limit;   ///< 9 bit field. Maximum number of entries before creating a threshold interrupt Nx_EMON_COR_BUF_HIGH_THRHLD_Ix
} p64h_sysc_nvm_edac_inst_param_t;

/// SRAM EDAC Fec configuration
typedef struct {
    // FEC configuration
    p64h_sysc_mem_fec_mode_t fec_mode;       ///< BYPASS, SECDED or BCH
    p64h_sysc_bch_type_t     bch_type;       ///< BCH type
    uint8_t                  fec_block_size; ///< In BCH mode, it configures the transaction length of BCH ECC sector which includes: address, data,
                                             ///< and parity. valid values are:
                                             ///<   T4: 8, 24, 56, 120, 248
                                             ///<   T10: 16, 48, 112, 240
                                             ///<   T18: 37, 101, 229
                                             ///<   T24: 93
    ///< The SRAM EDAC has a data width of 64bits; these configurations result in a DATA+ECC sectors or 128, 256, 512,1024,
    ///< 2048, 4096 Bytes.
    ///< For SECDED Mode, this register doubles as the patrol scrubber length request. Allowed values are 0
    ///< -127 for patrol scrubbing in SECDED mode. Results in a egress read request of 2 x LEN.
    uint8_t addr_map_msk_en; ///< Enables fec mode address mapping. Each bit is one slot. FEC addr mapping is specified in fec_addr_map.
                             ///< If any slots are asserted then address mapping is enabled. If address is out of slots range,
                             ///< default settings will be used defined in this register will be used.
    p64h_sysc_sram_fec_addr_range_t fec_addr_map[P64H_SYSC_SRAM_FEC_ADDR_MAP_NUM_SLOTS]; ///< Up to 8 regions can be configured for one EDAC.
    bool                            always_rmw_en; ///< If a full SECDED/BCH block is detected, still invoke a RMW operation.
    bool rcmd_drop_hold_en; ///< This enables the EDAC to drop all transactions after a command or address uncorrectable bus secded error.
    bool wcmd_drop_hold_en; ///< Some uncorrectable bus ecc command errors can cause corruption to propagate to other transactions.
                            ///< This bit enables the edac to drop all transactions after a command or address uncorrectable bus error.
                            ///< Deassert this bit to disable the function.
} p64h_sysc_sram_edac_fec_cfg_t;

/// NVM EDAC Fec configuration
typedef struct {
    // FEC configuration
    p64h_sysc_mem_fec_mode_t fec_mode; ///< BYPASS, SECDED or BCH
    p64h_sysc_bch_type_t     bch_type; ///< BCH type
    bool nfc_fec_mode_en; ///< This enables NAND Flash controller (NFC) FEC mode, where the nand controllers BCH ECC is used instead of the NDCs.
                          ///< False: disabled, True: enabled
    uint8_t num_trans;    ///< This is the number of NOC  transactions that make up one page.
                          ///< 0: One transaction per page.
                          ///< 1: Two transactions per page.
                          ///< …
                          ///< 255: 256 transactions per page.

    uint8_t fec_block_size;  ///< This register is the NOC transaction length for num_trans that make up the page in host memory.
                             ///< Host memory page size = (fec_block_size+1)*64bits*num_trans
                             ///< Depending on the fec_mode, ECC will be added to the host memory on each transaction.
                             ///< In BCH mode, bcp_type register configures the ECC_SIZE where,
                             ///< NAND memory page size = (fec_block_size+ECC_SIZE+2)*64bits*num_trans.
                             ///< For a bcp_type of 24 the maximum fec_block_size is 221 giving 255 beats of 64bits as the maximum transaction length.
                             ///< For other BCH modes the the maximum follows this equation: Maximum fec_block_size = 256-ECC_SIZE-2 In SECDED mode,
                             ///< the fec block size doubles, NAND memory page size = ((fec_block_size+1)*2)*64bits*num_trans. The maximum
                             ///< fec_block_size in SECDED mode is 127. The minimum fec_block_size is 1.
    bool    dec_addr_chk_en; ///< Enables Address checking in the SECDED or BCH decoder.
    bool    sram_mode;       ///< Enables SRAM mode.
    bool    bus_secded_bypass; ///< Disables bus secded checking, False: Bus SECDED checking is enabled. True: Bus SECDED checking is disabled.
    uint8_t bank_msk_en;       ///< Enables the banks available for the patrol scrubber. The patrol scrubber scrubs each bank sequentially.
                               ///< 0000_0001: Enables bank 0
                               ///< 0000_0011: Enables bank 0 and 1.
                               ///< …
                               ///< 1111_1111: Enables all banks.

    bool ram_uncor_wstrb_zero_en; ///< On Bus SECDED uncorrectable errors checked on the ingress write data channel to the NDC RAM, the wstrbs are set
                                  ///< to zero.

} p64h_sysc_nvm_edac_fec_cfg_t;

/// SRAM EDAC instance configuraton
typedef struct {
    bool                             enable;           ///< true when this EDAC instance is enabled
    p64h_sysc_sram_edac_fec_cfg_t    fec_cfg;          ///< see p64h_sysc_sram_edac_fec_cfg_t
    p64h_sysc_demand_scrub_cfg_t     demand_scrub_cfg; ///< see p64h_sysc_demand_scrub_cfg_t
    p64h_sysc_patrol_scrub_cfg_t     patrol_scrub_cfg; ///< see p64h_sysc_patrol_scrub_cfg_t
    p64h_sysc_sram_edac_inst_param_t params;           ///< see p64h_sysc_sram_edac_inst_param_t
    p64h_sysc_nvm_ctrl_type_t        nvm_ctrl;         ///< define the NVM controller type
} p64h_sysc_sram_edac_inst_cfg_t;

/// NVM EDAC instance configuraton
typedef struct {
    bool                            enable;           ///< true when this EDAC instance is enabled
    p64h_sysc_nvm_edac_fec_cfg_t    fec_cfg;          ///< see p64h_sysc_sram_nvm_fec_cfg_t
    p64h_sysc_demand_scrub_cfg_t    demand_scrub_cfg; ///< see p64h_sysc_demand_scrub_cfg_t
    p64h_sysc_patrol_scrub_cfg_t    patrol_scrub_cfg; ///< see p64h_sysc_patrol_scrub_cfg_t
    p64h_sysc_nvm_edac_inst_param_t params;           ///< p64h_sysc_nvm_edac_inst_param_t
    p64h_sysc_nvm_ctrl_type_t       nvm_ctrl;         ///< define the NVM controller type
} p64h_sysc_nvm_edac_inst_cfg_t;

/// SRAM EDAC configuration
typedef struct {
    p64h_sysc_sram_dmr_cfg_t       dmr;                           ///< DMR configuration
    p64h_sysc_sram_edac_inst_cfg_t inst[P64H_SYSC_EDAC_INST_NUM]; ///< EDAC instances
} p64h_sysc_sram_edac_cfg_t;

/// NVM EDAC configuration
typedef struct {
    p64h_sysc_nvm_dmr_cfg_t       dmr;                           ///< DMR configuration
    p64h_sysc_nvm_edac_inst_cfg_t inst[P64H_SYSC_EDAC_INST_NUM]; ///< EDAC instances
} p64h_sysc_nvm_edac_cfg_t;

/// NVM connector pair configuration (configuration is paired 0/1 and 2/3 to enable DMR configuration)
typedef struct {
    p64h_sysc_nvm_cmode_t     cmode[P64H_SYSC_NUM_CONNECTOR_PER_PAIR];         ///< mode for connector 0 and 1, it shall be the same if DMR is used
    p64h_sysc_nvm_edac_cfg_t  nvm_edac_cfg;                                    ///< NVM EDAC configuration
    p64h_sysc_sram_edac_cfg_t sram_edac_cfg[P64H_SYSC_NUM_SRAM_EDAC_PER_PAIR]; ///< SRAM EDAC configurations
    p64h_sysc_nvm_ctrl_cfg_t  nvm_ctrl_cfg[P64H_SYSC_NUM_CONNECTOR_PER_PAIR];  ///< NVM ctrl configuration, it shall be the same if DMR is used
    bool                      sd_enable[P64H_SYSC_NUM_CONNECTOR_PER_PAIR];     ///< SD enable
} p64h_sysc_nvm_cpair_cfg_t;

#endif // P64H_SYSC_NVM_TYPE_H
/// @}
