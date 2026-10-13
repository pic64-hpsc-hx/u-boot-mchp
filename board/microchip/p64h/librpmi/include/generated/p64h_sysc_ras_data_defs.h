/* (c) 2026 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

#ifndef RAS_DATA_DEFS_H
#define RAS_DATA_DEFS_H

#include "generated/p64h_sysc_ras_error_sources.h"
#include "generated/p64h_sysc_errors.h"
#include "ba/p64h_sysc_intr_ba.h"
// #include <assert.h>

/* Public Structs and Enums ----------------------------------------- */

//////////////////////
// ID Types
//////////////////////
/**
 * @brief Extensible cache slice indexes
 */
typedef enum {
    EXT_CACHE_SLICE_EXT_CACHE_SLICE_0 = 0, ///< extensible cache slice 0
    EXT_CACHE_SLICE_EXT_CACHE_SLICE_1 = 1, ///< extensible cache slice 1
    EXT_CACHE_SLICE_EXT_CACHE_SLICE_2 = 2, ///< extensible cache slice 2
    EXT_CACHE_SLICE_EXT_CACHE_SLICE_3 = 3, ///< extensible cache slice 3
    EXT_CACHE_SLICE_ID_LAST ///< Last value for ID type ext_cache_slice
} p64h_sysc_ras_ext_cache_slice_id_t;


/**
 * @brief Extensible cache bank indexes within slices
 */
typedef enum {
    EXT_CACHE_BANK_EXT_CACHE_SLICE_BANK_0 = 0, ///< extensible cache bank 0
    EXT_CACHE_BANK_EXT_CACHE_SLICE_BANK_1 = 1, ///< extensible cache bank 1
    EXT_CACHE_BANK_EXT_CACHE_SLICE_BANK_2 = 2, ///< extensible cache bank 2
    EXT_CACHE_BANK_EXT_CACHE_SLICE_BANK_3 = 3, ///< extensible cache bank 3
    EXT_CACHE_BANK_ID_LAST ///< Last value for ID type ext_cache_bank
} p64h_sysc_ras_ext_cache_bank_id_t;


/**
 * @brief instance of PL2 cache within a cluster
 */
typedef enum {
    PL2_INST_PL2_0 = 0, ///< pl2 0
    PL2_INST_PL2_1 = 1, ///< pl2 1
    PL2_INST_PL2_2 = 2, ///< pl2 2
    PL2_INST_PL2_3 = 3, ///< pl2 3
    PL2_INST_ID_LAST ///< Last value for ID type pl2_inst
} p64h_sysc_ras_pl2_inst_id_t;


/**
 * @brief ID of SEC NoC NIU
 */
typedef enum {
    SEC_NOC_NIU_M1 = 0, ///< Secure Controller registers in M1 target
    SEC_NOC_NIU_ACSU = 1, ///< Secure Controller ACSU target
    SEC_NOC_NIU_DTIM = 2, ///< DTIM OCR configuration registers target
    SEC_NOC_NIU_WDOG = 3, ///< Wdog (NOC) target
    SEC_NOC_NIU_Timer = 4, ///< Timer (NOC) target
    SEC_NOC_NIU_SHA3_KECCAK = 5, ///< SHA3_KECCAK (NOC) target
    SEC_NOC_NIU_SECREG = 6, ///< SecReg (NOC) target
    SEC_NOC_NIU_SEC_MBOX = 7, ///< Sec_Mbox (NOC) target
    SEC_NOC_NIU_DMA_CTRL = 8, ///< Sec_DMA Controller (NOC) target
    SEC_NOC_NIU_PQ_SUB = 9, ///< PQ Subordinator (NOC) target
    SEC_NOC_NIU_PQ_MNG = 10, ///< PQ Manager (NOC) target
    SEC_NOC_NIU_OTP = 11, ///< OTP (NOC) target
    SEC_NOC_NIU_OCR_MEM = 12, ///< OCR Data (NOC) target
    SEC_NOC_NIU_OCR_CTRL = 13, ///< OCR Controller (NOC) target
    SEC_NOC_NIU_JTAG_MBOX = 14, ///< JTAG Mbox (NOC) target
    SEC_NOC_NIU_CRYPTO_CTRL = 15, ///< Crypto Engine Control & Status (NOC) target
    SEC_NOC_NIU_CPU_FP = 16, ///< CPU Front Port (NOC) target
    SEC_NOC_NIU_BOOT_ROM = 17, ///< Boot ROM (NOC) target
    SEC_NOC_NIU_SEC_NOC_SVC = 18, ///< SEC_NOC Configuration (NOC) target
    SEC_NOC_NIU_CRYPTO_SHA_DMA = 19, ///< Crypto Engine SHA DMA (NOC) initiator
    SEC_NOC_NIU_CRYPTO_SHA3_DMA = 20, ///< Crypto Engine SHA3 DMA (NOC) initiator
    SEC_NOC_NIU_CRYPTO_AES_DMA = 21, ///< Crypto Engine AES DMA (NOC) initiator
    SEC_NOC_NIU_DMA_DATA = 22, ///< Sec_DMA Data (NOC) initiator
    SEC_NOC_NIU_CPU_SYS = 23, ///< CPU System Port (NOC) initiator
    SEC_NOC_NIU_ID_LAST ///< Last value for ID type sec_noc_niu
} p64h_sysc_ras_sec_noc_niu_id_t;


/**
 * @brief ID of HW lock monitored by the tamper monitor
 */
typedef enum {
    TAMPER_HW_LOCK_PRODUCTION_TEST = 0, ///< production_test_enable HW lock
    TAMPER_HW_LOCK_SYSC_DEBUG = 1, ///< sysc_debug_enable HW lock
    TAMPER_HW_LOCK_APPC_DEBUG = 2, ///< appc_debug_enable HW lock
    TAMPER_HW_LOCK_SECC_DEBUG = 3, ///< secc_debug_enable HW lock
    TAMPER_HW_LOCK_OTP_JTAG = 4, ///< otp_jtag_enable HW lock
    TAMPER_HW_LOCK_ID_LAST ///< Last value for ID type tamper_hw_lock
} p64h_sysc_ras_tamper_hw_lock_id_t;


/**
 * @brief ID of mesh block in Secure domain
 */
typedef enum {
    MESH_BLOCK_SEC = 0, ///< Secure controller mesh block
    MESH_BLOCK_USR_CRYPTO = 1, ///< User crypto mesh block
    MESH_BLOCK_DDR_ENCRYPT = 2, ///< DDR encryptor mesh block
    MESH_BLOCK_ANA = 3, ///< Analog top and PUF mesh block
    MESH_BLOCK_ID_LAST ///< Last value for ID type mesh_block
} p64h_sysc_ras_mesh_block_id_t;


/**
 * @brief ID of memory blocks in Secure domain
 */
typedef enum {
    SEC_MEM_BLOCK_SEC_MBOX = 0, ///< Secure Mailbox RAM block
    SEC_MEM_BLOCK_JTAG_MBOX = 1, ///< JTAG Mailbox RAM block
    SEC_MEM_BLOCK_DMA_CH_FIFO = 2, ///< Secure DMA channel FIFO RAM block
    SEC_MEM_BLOCK_BOOT_ROM = 3, ///< Boot ROM RAM block
    SEC_MEM_BLOCK_S7_TRACE = 4, ///< S7 Trace RAM block
    SEC_MEM_BLOCK_PQCS_ROM = 5, ///< PQCS ROM block
    SEC_MEM_BLOCK_PQCS_ISRAM = 6, ///< PQCS ISRAM block
    SEC_MEM_BLOCK_PQCS_DSRAM = 7, ///< PQCS DSRAM block
    SEC_MEM_BLOCK_ECULTRA = 8, ///< ECULTRA block
    SEC_MEM_BLOCK_KGSCRTR = 9, ///< KGSCRTR block
    SEC_MEM_BLOCK_KEY_ROM = 10, ///< Key ROM block
    SEC_MEM_BLOCK_ID_LAST ///< Last value for ID type sec_mem_block
} p64h_sysc_ras_sec_mem_block_id_t;


/**
 * @brief ID of voltage threshold detector
 */
typedef enum {
    VDD_THRES_DETECT_VDD_1_8 = 1, ///< 1.8 VDD
    VDD_THRES_DETECT_VDD_0_9 = 2, ///< 0.9 VDD
    VDD_THRES_DETECT_VDD_0_8 = 3, ///< 0.8 VDD
    VDD_THRES_DETECT_VDD_0_7 = 4, ///< 0.7 VDD
    VDD_THRES_DETECT_ID_LAST ///< Last value for ID type vdd_thres_detect
} p64h_sysc_ras_vdd_thres_detect_id_t;


#define P64H_SYSC_RAS_WGC_SHARED_OFFSET (uint32_t)(0x0U) ///< Enum offset for shared type of wgc
#define P64H_SYSC_RAS_WGC_SYSC_OFFSET (uint32_t)(0x1000U) ///< Enum offset for sysc type of wgc
#define P64H_SYSC_RAS_WGC_APPC_OFFSET (uint32_t)(0x2000U) ///< Enum offset for appc type of wgc

/**
 * @brief ID of Worldguard checkers across the device
 */
typedef enum {
    WGC_ENET_EP_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 0, ///< enet ep cfg WGC
    WGC_ENET_SWR_RDMA1_MCHP_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 1, ///< enet swr rdma1 mchp cfg WGC
    WGC_ENET_SWR_RDMA1_ROCE_COMMAND = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 2, ///< enet swr rdma1 roce command WGC
    WGC_ENET_SWR_RDMA2_MCHP_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 3, ///< enet swr rdma2 mchp cfg WGC
    WGC_ENET_SWR_RDMA2_ROCE_COMMAND = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 4, ///< enet swr rdma2 roce command WGC
    WGC_ENET_SWR_SWITCH_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 5, ///< enet swr switch cfg WGC
    WGC_ENET_SWR_TOP_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 6, ///< enet swr top cfg WGC
    WGC_DDR_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 7, ///< ddr cfg WGC
    WGC_M2_HP_SPW_CSR = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 8, ///< m2 hp spw csr WGC
    WGC_M2_JTAG_SPI = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 9, ///< m2 jtag spi WGC
    WGC_M2_OTHER_0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 10, ///< m2 other 0 WGC
    WGC_M2_OTHER_1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 11, ///< m2 other 1 WGC
    WGC_M3_APPDMA0_HP_CSR = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 12, ///< m3 appdma0 hp csr WGC
    WGC_M3_APPDMA1_HP_CSR = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 13, ///< m3 appdma1 hp csr WGC
    WGC_M3_NMRA0_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 14, ///< m3 nmra0 t WGC
    WGC_M3_NMRA1_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 15, ///< m3 nmra1 t WGC
    WGC_M3_OCR0_MEM = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 16, ///< m3 ocr0 mem WGC
    WGC_M3_OCR1_MEM = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 17, ///< m3 ocr1 mem WGC
    WGC_M3_OTHER = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 18, ///< m3 other WGC
    WGC_M3_IPC_0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 19, ///< m3 ipc 0 WGC
    WGC_M3_IPC_1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 20, ///< m3 ipc 1 WGC
    WGC_DDR_ENCRYPT_HP_CSR = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 21, ///< ddr encrypt hp csr WGC
    WGC_DDR_ENCRYPT_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 22, ///< ddr encrypt t WGC
    WGC_USER_CRYPTO_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 23, ///< user crypto cfg WGC
    WGC_USER_CRYPTO_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 24, ///< user crypto t WGC
    WGC_NVM_EDAC0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 25, ///< nvm edac0 WGC
    WGC_NVM_EDAC1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 26, ///< nvm edac1 WGC
    WGC_NVM_SRAM_EDAC0_0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 27, ///< nvm sram edac0 0 WGC
    WGC_NVM_SRAM_EDAC0_1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 28, ///< nvm sram edac0 1 WGC
    WGC_NVM_SRAM_EDAC1_0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 29, ///< nvm sram edac1 0 WGC
    WGC_NVM_SRAM_EDAC1_1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 30, ///< nvm sram edac1 1 WGC
    WGC_NVM_SRAM_EDAC2_0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 31, ///< nvm sram edac2 0 WGC
    WGC_NVM_SRAM_EDAC2_1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 32, ///< nvm sram edac2 1 WGC
    WGC_NVM_SS_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 33, ///< nvm ss cfg WGC
    WGC_IOMMU_0_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 34, ///< iommu 0 cfg WGC
    WGC_IOMMU_1_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 35, ///< iommu 1 cfg WGC
    WGC_IOMMU_SS_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 36, ///< iommu ss cfg WGC
    WGC_PCIE0_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 37, ///< pcie0 cfg WGC
    WGC_PCIE0_CTL0_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 38, ///< pcie0 ctl0 t WGC
    WGC_PCIE0_CTL1_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 39, ///< pcie0 ctl1 t WGC
    WGC_PCIE1_CFG = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 40, ///< pcie1 cfg WGC
    WGC_PCIE1_CTL0_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 41, ///< pcie1 ctl0 t WGC
    WGC_PCIE1_CTL1_T = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 42, ///< pcie1 ctl1 t WGC
    WGC_WG_ERR_0 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 43, ///< wg err 0 WGC
    WGC_WG_ERR_1 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 44, ///< wg err 1 WGC
    WGC_WG_ERR_2 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 45, ///< wg err 2 WGC
    WGC_WG_ERR_3 = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 46, ///< wg err 3 WGC
    WGC_WG_WID_DED = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 47, ///< wg wid ded WGC
    WGC_WG_WID_SEC = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 48, ///< wg wid sec WGC
    WGC_SVC_NOC_EDAC = P64H_SYSC_RAS_WGC_SHARED_OFFSET + 49, ///< svc noc edac WGC
    WGC_INT_AGG = P64H_SYSC_RAS_WGC_SYSC_OFFSET + 0, ///< Interrupt Aggregator wgChecker
    WGC_EXTENSIBLE_CACHE_SLICE_WGCHECKER_0 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 0, ///< Extensible Cache Slice wgChecker
    WGC_EXTENSIBLE_CACHE_0 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 1, ///< Extensible Cache
    WGC_EXTENSIBLE_CACHE_SLICE_WGCHECKER_1 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 2, ///< Extensible Cache Slice wgChecker
    WGC_EXTENSIBLE_CACHE_1 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 3, ///< Extensible Cache
    WGC_EXTENSIBLE_CACHE_SLICE_WGCHECKER_2 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 4, ///< Extensible Cache Slice wgChecker
    WGC_EXTENSIBLE_CACHE_2 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 5, ///< Extensible Cache
    WGC_EXTENSIBLE_CACHE_SLICE_WGCHECKER_3 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 6, ///< Extensible Cache Slice wgChecker
    WGC_EXTENSIBLE_CACHE_3 = P64H_SYSC_RAS_WGC_APPC_OFFSET + 7, ///< Extensible Cache
    WGC_TL2C_TO_CXL_MEM_BRIDGE_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 8, ///< TL2c to CXL.mem Bridge wgChecker
    WGC_TL2C_TO_CXL_CACHE_BRIDGE_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 9, ///< TL2c to CXL.cache Bridge wgChecker
    WGC_CXL_CACHE_TO_TL2C_BRIDGE_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 10, ///< CXL.cache to TL2c Bridge wgChecker
    WGC_SMC_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 11, ///< SMC wgChecker
    WGC_ROOT_ERROR_MAPPING_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 12, ///< Root Error Mapping wgChecker
    WGC_APLIC_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 13, ///< APLIC wgChecker
    WGC_CLINT_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 14, ///< CLINT wgChecker
    WGC_IMSIC_M_MODE_0_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 15, ///< IMSIC M-Mode 0 wgChecker
    WGC_IMSIC_S_MODE_0_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 16, ///< IMSIC S-Mode 0 wgChecker
    WGC_IMSIC_M_MODE_1_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 17, ///< IMSIC M-Mode 1 wgChecker
    WGC_IMSIC_S_MODE_1_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 18, ///< IMSIC S-Mode 1 wgChecker
    WGC_IMSIC_M_MODE_2_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 19, ///< IMSIC M-Mode 2 wgChecker
    WGC_IMSIC_S_MODE_2_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 20, ///< IMSIC S-Mode 2 wgChecker
    WGC_IMSIC_M_MODE_3_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 21, ///< IMSIC M-Mode 3 wgChecker
    WGC_IMSIC_S_MODE_3_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 22, ///< IMSIC S-Mode 3 wgChecker
    WGC_TMC_0_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 23, ///< TMC 0 wgChecker
    WGC_TILE_0_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 24, ///< Tile 0 wgChecker
    WGC_TMC_1_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 25, ///< TMC 1 wgChecker
    WGC_TILE_1_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 26, ///< Tile 1 wgChecker
    WGC_TMC_2_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 27, ///< TMC 2 wgChecker
    WGC_TILE_2_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 28, ///< Tile 2 wgChecker
    WGC_TMC_3_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 29, ///< TMC 3 wgChecker
    WGC_TILE_3_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 30, ///< Tile 3 wgChecker
    WGC_MEM_DEINTERLEAVER_EB_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 31, ///< Mem Deinterleaver Error Bank wgChecker
    WGC_SYS_DEINTERLEAVER_EB_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 32, ///< Sys Deinterleaver Error Bank wgChecker
    WGC_WRITE_COMB_BUF_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 33, ///< Write Combining Buffer wgChecker
    WGC_CXL_MEM_TO_CPI_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 34, ///< CXL.mem to CPI wgChecker
    WGC_CXL_CACHE_TO_CPI_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 35, ///< CXL.cache to CPI wgChecker
    WGC_FRONT_PORT_CACHE_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 36, ///< Front Port Cache wgChecker
    WGC_WRITE_COMBINING_BUFFER_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 37, ///< Write Combining Buffer wgChecker
    WGC_FRONT_PORT_CACHE = P64H_SYSC_RAS_WGC_APPC_OFFSET + 38, ///< Front Port Cache
    WGC_CXL_MEM_FROM_CPI_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 39, ///< CXL.mem from CPI wgChecker
    WGC_CXL_CACHE_FROM_CPI_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 40, ///< CXL.cache from CPI wgChecker
    WGC_TRACE_ENCODER_0_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 41, ///< Trace Encoder 0 wgChecker
    WGC_TRACE_ENCODER_1_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 42, ///< Trace Encoder 1 wgChecker
    WGC_TRACE_ENCODER_2_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 43, ///< Trace Encoder 2 wgChecker
    WGC_TRACE_ENCODER_3_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 44, ///< Trace Encoder 3 wgChecker
    WGC_TRACE_FUNNEL_0_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 45, ///< Trace Funnel 0 wgChecker
    WGC_TEST_INDICATOR_WGCHECKER = P64H_SYSC_RAS_WGC_APPC_OFFSET + 46, ///< Test Indicator wgChecker
    WGC_ID_LAST ///< Last value for ID type wgc
} p64h_sysc_ras_wgc_id_t;


/**
 * @brief Lockstep error injection module type
 */
typedef enum {
    LS_EINJ_MOD_TYPE_BROADCAST = 0, ///< Lockstep broadcast module
    LS_EINJ_MOD_TYPE_CHECK = 1, ///< Lockstep check module
    LS_EINJ_MOD_TYPE_ID_LAST ///< Last value for ID type ls_einj_mod_type
} p64h_sysc_ras_ls_einj_mod_type_id_t;


/**
 * @brief Lockstep check module ID
 */
typedef enum {
    LS_CHK_MOD_TILE_TL2_C_CLIENT = 0, ///< TILE_TL2cCLIENT Uses first-width-min-32-bits error injection algorithm
    LS_CHK_MOD_TILE_TLSLAVE = 1, ///< TileLink Slave Port outputs
    LS_CHK_MOD_HALT_OUTPUTS = 2, ///< Core Halt indication
    LS_CHK_MOD_WFI_OUTPUTS = 3, ///< Core WFI indication
    LS_CHK_MOD_CEASE_OUTPUTS = 4, ///< Indication of a CEASE instruction
    LS_CHK_MOD_DEBUG_OUTPUTS = 5, ///< Debug interface outputs
    LS_CHK_MOD_TILE_OUT_OF_RESET_OUTPUTS = 7, ///< TILE_OUT_OF_RESET_OUTPUTS
    LS_CHK_MOD_TMC_OUTPUTS = 8, ///< Output to TMC for power management
    LS_CHK_MOD_CLOCK_GATE_DISABLE_OUTPUTS = 9, ///< Clock gate disable indication
    LS_CHK_MOD_DEBUG_AVAIL_OUTPUTS = 10, ///< Debug availability status
    LS_CHK_MOD_CLOCK_GATE_NODE = 11, ///< CLOCK_GATE_NODE
    LS_CHK_MOD_TRACE_OUTPUTS = 12, ///< Trace outputs
    LS_CHK_MOD_IMSIC_CSR_IO = 13, ///< CSR Outputs to MSI Controller
    LS_CHK_MOD_BPWATCH_OUTPUTS = 14, ///< Breakpoint/Watch point outputs
    LS_CHK_MOD_GHRT_IO = 15, ///< Global High-Resolution Timestamp outputs
    LS_CHK_MOD_GHRT_TILERESET_IO = 16, ///< Global High-Resolution Timestamp tile reset
    LS_CHK_MOD_RAS_IO = 20, ///< Error Bank outputs
    LS_CHK_MOD_CEASE_FROM_CSR_OUTPUTS = 21, ///< CEASE CSR output
    LS_CHK_MOD_HGEIE_OUTPUTS = 24, ///< HGEIE_OUTPUTS
    LS_CHK_MOD_L1_DCACHE_DATA = 25, ///< L1 Data Cache data request
    LS_CHK_MOD_L1_DCACHE_TAG = 26, ///< L1 Data Cache tag request
    LS_CHK_MOD_L1_ICACHE_DATA = 27, ///< L1 Instruction Cache data request
    LS_CHK_MOD_L1_ICACHE_TAG = 28, ///< L1 Instruction Cache tag request
    LS_CHK_MOD_ITIM = 29, ///< Instruction Tightly Integrated Memory request
    LS_CHK_MOD_DATA_LOCAL_STORE = 30, ///< L1 scratchpad memory request
    LS_CHK_MOD_ID_LAST ///< Last value for ID type ls_chk_mod
} p64h_sysc_ras_ls_chk_mod_id_t;


/**
 * @brief Lockstep broadcast module ID
 */
typedef enum {
    LS_BROADCAST_MOD_TILE_TL2cCLIENT_OPCODE = 0, ///< Tilelinke to client opcode module. Uses first-width-min-32-bits error injection algorithm
    LS_BROADCAST_MOD_TILE_TLSLAVE_OPCODE = 1, ///< TileLink Slave Port opcode field. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_DEBUG_INPUTS = 2, ///< Tile debug interrupts. Uses first-to-all error injection algorithm.
    LS_BROADCAST_MOD_CLINT_INPUTS = 3, ///< Core local interrupts. Uses first-to-all error injection algorithm.
    LS_BROADCAST_MOD_PLIC_INPUTS = 4, ///< Interrupts from PLIC. Uses first-to-all error injection algorithm.
    LS_BROADCAST_MOD_IMSIC_INPUTS = 5, ///< Interrupts from MSI Controller. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_LOCAL_INTERRUPT_INPUTS = 6, ///< Local interrupts. Uses first-to-all error injection algorithm.
    LS_BROADCAST_MOD_NMI_INPUTS = 7, ///< Non-maskable interrupts. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_IMSIC_CSR_IO = 10, ///< CSR inputs from MSI Controller. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_CLOCK_GATE_NODE = 11, ///< Uses first-width-min-32-bits error injection algorithm
    LS_BROADCAST_MOD_TRACE_AUX_INPUTS = 13, ///< Trace. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_GHRT_IO_0 = 15, ///< Global High-Resolution Timestamp inputs. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_DEBUG_TRAP_INPUTS = 17, ///< Debug mode breakpoint traps vector address. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_RESET_WG_INPUTS = 18, ///< WorldGuard reset. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_RAS_IO = 20, ///< Error Bank inputs. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_DLS_STRAP_INPUTS = 24, ///< Data Local Store base address strap. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_L1_DCACHE_DATA = 25, ///< L1 Data Cache data response data. Uses first-2-bits error injection algorithm.
    LS_BROADCAST_MOD_L1_DCACHE_TAG = 26, ///< L1 Data Cache tag response data. Uses first-2-bits error injection algorithm.
    LS_BROADCAST_MOD_L1_ICACHE_DATA = 27, ///< L1 Instruction Cache data response data. Uses first-2-bits error injection algorithm.
    LS_BROADCAST_MOD_L1_ICACHE_TAG = 28, ///< L1 Instruction Cache tag response data. Uses first-2-bits error injection algorithm.
    LS_BROADCAST_MOD_ITIM = 29, ///< Instruction Tightly Integrated Memory response data. Uses first-2-bits error injection algorithm.
    LS_BROADCAST_MOD_DATA_LOCAL_STORE = 30, ///< L1 scratchpad memory response data. Uses first-2-bits error injection algorithm
    LS_BROADCAST_MOD_TILE_TL2cCLIENT_DATA = 31, ///< Uses first-width-min-32-bits error injection algorithm
    LS_BROADCAST_MOD_TILE_TLSLAVE_ADDRESS = 32, ///< TileLink Slave Port address field. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_TILE_TLSLAVE_DATA = 33, ///< TileLink Slave Port data field. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_HART_ID_INPUTS = 40, ///< Hart ID input. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_GHRT_IO_1 = 41, ///< Global High-Resolution Timestamp inputs. Uses first-to-all error injection algorithm.
    LS_BROADCAST_MOD_GHRT_RTC_IO = 42, ///< Global High-Resolution Timestamp RTC inputs. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_RESET_VECTOR_INPUTS = 43, ///< Reset vector address. Uses first-width-min-32-bits error injection algorithm.
    LS_BROADCAST_MOD_TILE_LOW_POWER_INIT_INPUT = 100, ///< Tile low power init input. Uses first-width-min-32-bits error injection algorithm
    LS_BROADCAST_MOD_ID_LAST ///< Last value for ID type ls_broadcast_mod
} p64h_sysc_ras_ls_broadcast_mod_id_t;


/**
 * @brief Denial types as result of a request to the Tilelink from an L3 cache
 */
typedef enum {
    TL_REQ_DENIED_TYPE_CMO_PROBE = 0, ///< CMO-Probe
    TL_REQ_DENIED_TYPE_EVICT = 1, ///< Evict
    TL_REQ_DENIED_TYPE_ID_LAST ///< Last value for ID type tl_req_denied_type
} p64h_sysc_ras_tl_req_denied_type_id_t;


/**
 * @brief SRAM EDAC error injection stage
 */
typedef enum {
    SRAM_EDAC_ERR_INJ_STAGE_READ_CMD = 0, ///< Read command error injection
    SRAM_EDAC_ERR_INJ_STAGE_READ_CMD_ADDR = 1, ///< Read command address error injection
    SRAM_EDAC_ERR_INJ_STAGE_READ_DATA_CAPTURE = 2, ///< Read data capture error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_EGRESS = 3, ///< Write command error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_ADDR_EGRESS = 4, ///< Write command address error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_INGRESS = 5, ///< Write command ingress error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_ADDR_INGRESS = 6, ///< Write command address ingress error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_DATA_CAPTURE = 7, ///< Write data capture error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_DATA_GENERATION = 8, ///< Write data generation error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_DATA_RESPONSE = 9, ///< Write data response error injection
    SRAM_EDAC_ERR_INJ_STAGE_SECDED_ENC = 10, ///< SECDED encode error injection
    SRAM_EDAC_ERR_INJ_STAGE_BCH_ENC = 11, ///< BCH encode error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_NARROW_TRANSFER_MERGE_CURRENT = 12, ///< RMW narrow transfer merge current data error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_NARROW_TRANSFER_MERGE_NEW = 13, ///< RMW narrow transfer merge new data error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_READ = 14, ///< RMW read data error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_WRITE = 15, ///< RMW write data error injection
    SRAM_EDAC_ERR_INJ_STAGE_ID_LAST ///< Last value for ID type sram_edac_err_inj_stage
} p64h_sysc_ras_sram_edac_err_inj_stage_id_t;


/**
 * @brief SRAM EDAC error injection instance
 */
typedef enum {
    SRAM_EDAC_INST_EDAC_0 = 0, ///< Inject error in EDAC Instance 0
    SRAM_EDAC_INST_EDAC_1 = 1, ///< Inject error in EDAC Instance 1
    SRAM_EDAC_INST_ID_LAST ///< Last value for ID type sram_edac_inst
} p64h_sysc_ras_sram_edac_inst_id_t;


/**
 * @brief NVM EDAC error injection stage
 */
typedef enum {
    NVM_EDAC_ERR_INJ_STAGE_SECDED_DEC = 0, ///< SECDED decode error injection
    NVM_EDAC_ERR_INJ_STAGE_BCH_DEC = 1, ///< BCH decode error injection
    NVM_EDAC_ERR_INJ_STAGE_RDGEN = 2, ///< Read generation error injection
    NVM_EDAC_ERR_INJ_STAGE_RDCAP_R = 3, ///< Read capture error injection
    NVM_EDAC_ERR_INJ_STAGE_WDRESP = 4, ///< Write data response error injection
    NVM_EDAC_ERR_INJ_STAGE_SECDED_ENC = 5, ///< SECDED encode error injection
    NVM_EDAC_ERR_INJ_STAGE_BCH_ENC = 6, ///< BCH encode error injection
    NVM_EDAC_ERR_INJ_STAGE_AW_C = 7, ///< ECC checking on the NDC0 RAM target
    NVM_EDAC_ERR_INJ_STAGE_AW_A = 8, ///< AW_A
    NVM_EDAC_ERR_INJ_STAGE_W = 9, ///< W
    NVM_EDAC_ERR_INJ_STAGE_WDATA = 10, ///< WDATA
    NVM_EDAC_ERR_INJ_STAGE_AR_C = 11, ///< AR_C
    NVM_EDAC_ERR_INJ_STAGE_AR_A = 12, ///< AR_A
    NVM_EDAC_ERR_INJ_STAGE_ID_LAST ///< Last value for ID type nvm_edac_err_inj_stage
} p64h_sysc_ras_nvm_edac_err_inj_stage_id_t;


/**
 * @brief NVM EDAC error injection instance
 */
typedef enum {
    NVM_EDAC_INST_NVM_0 = 0, ///< Inject error in NVM Instance 0
    NVM_EDAC_INST_NVM_1 = 1, ///< Inject error in NVM Instant 1
    NVM_EDAC_INST_ID_LAST ///< Last value for ID type nvm_edac_inst
} p64h_sysc_ras_nvm_edac_inst_id_t;


/**
 * @brief NVM EDAC FEC mode
 */
typedef enum {
    NVM_EDAC_MODE_BYPASS = 0, ///< No FEC enabled
    NVM_EDAC_MODE_SECDED = 1, ///< SECDED FEC enabled
    NVM_EDAC_MODE_BCH = 3, ///< BCH FEC enabled
    NVM_EDAC_MODE_ID_LAST ///< Last value for ID type nvm_edac_mode
} p64h_sysc_ras_nvm_edac_mode_id_t;


/**
 * @brief DDR EDAC FEC mode
 */
typedef enum {
    DDR_EDAC_MODE_BYPASS = 0, ///< No FEC enabled
    DDR_EDAC_MODE_SECDED = 1, ///< SECDED FEC enabled
    DDR_EDAC_MODE_DEECE = 3, ///< DEECE FEC enabled
    DDR_EDAC_MODE_ID_LAST ///< Last value for ID type ddr_edac_mode
} p64h_sysc_ras_ddr_edac_mode_id_t;


/**
 * @brief DDR EDAC RS encoder error selection mode
 */
typedef enum {
    DDR_EDAC_ERR_SEL_NO_ERR_INJ = 0, ///< No error injection
    DDR_EDAC_ERR_SEL_ONE_TIME_ERR_INJ = 1, ///< One-time error injection
    DDR_EDAC_ERR_SEL_CONTINUOUS_ERR_INJ = 3, ///< Continuous error injection
    DDR_EDAC_ERR_SEL_ID_LAST ///< Last value for ID type ddr_edac_err_sel
} p64h_sysc_ras_ddr_edac_err_sel_id_t;


/**
 * @brief DDR EDAC RS decoder DI fault selection mode
 */
typedef enum {
    DDR_EDAC_DI_FAULT_SEL_NO_INSERT = 0, ///< No fault insertion
    DDR_EDAC_DI_FAULT_SEL_INSERT_MODE_0 = 1, ///< Insert DI fault at input of DI generator (bit location [0:255])
    DDR_EDAC_DI_FAULT_SEL_INSERT_MODE_1 = 2, ///< Insert DI fault at output of DI generator (bit location [0:17])
    DDR_EDAC_DI_FAULT_SEL_INSERT_MODE_2 = 3, ///< Insert DI fault at input of redundant DI generator (bit location [0:255])
    DDR_EDAC_DI_FAULT_SEL_INSERT_MODE_3 = 4, ///< Insert DI fault at output of redundant DI generator (bit location [0:17])
    DDR_EDAC_DI_FAULT_SEL_INSERT_MODE_4 = 5, ///< Insert DI fault at OR'ed syndrome zero calculation
    DDR_EDAC_DI_FAULT_SEL_ID_LAST ///< Last value for ID type ddr_edac_di_fault_sel
} p64h_sysc_ras_ddr_edac_di_fault_sel_id_t;


/**
 * @brief ENET End-Point Diagnostic Instance enum encoding (ID:max_bit:min_bit:double_err_support)
 */
typedef enum {
    ENET_EP_DIAG_INST_CLEAR = 0, ///< NULL diagnostic instance used to clear error injection
    ENET_EP_DIAG_INST_AXI_RD_TIMEOUT_LOCKUP = 2382692352, ///< AXI read transaction timeout lockup detection (valid range = [5:0])
    ENET_EP_DIAG_INST_TX_DMA_LOCKUP_START_TO_STORED = 2399797248, ///< Transmit DMA Datapath Lockup Detection - Start to Stored (valid range = [10:0])
    ENET_EP_DIAG_INST_TX_DMA_LOCKUP_PACKET_CNT = 2416574464, ///< Transmit DMA Datapath Lockup Detection - Packet count (valid range = [10:0])
    ENET_EP_DIAG_INST_RX_DMA_LOCKUP = 2433351680, ///< Receive DMA Datapath Lockup Detection (valid range = [10:0])
    ENET_EP_DIAG_INST_RX_MAC_DATAPATH_LOCKUP = 2635005952, ///< RX MAC Datapath Lockup Detection (valid range = [15:0])
    ENET_EP_DIAG_INST_TX_MAC_DATAPATH_LOCKUP = 2651455488, ///< TX MAC Datapath Lockup Detection (valid range = [10:0])
    ENET_EP_DIAG_INST_ID_LAST ///< Last value for ID type enet_ep_diag_inst
} p64h_sysc_ras_enet_ep_diag_inst_id_t;


/**
 * @brief NOC packet opcode ID encoding
 */
typedef enum {
    NOC_PKT_OPC_RD = 0, ///< Read. Data is read by an initiator from a target with incrementing addressing.
    NOC_PKT_OPC_RDW = 1, ///< Wrapped read. Data is read by an initiator from a target with wrapping addressing.
    NOC_PKT_OPC_RDL = 2, ///< Linked Read. This read allocates a monitor in the Target with incrementing addressing.
    NOC_PKT_OPC_RDX = 3, ///< Exclusive Read with incrementing addressing.
    NOC_PKT_OPC_WR = 4, ///< Write. Data is written by an initiator to a target with incrementing addressing.
    NOC_PKT_OPC_WRW = 5, ///< Wrapped Write. Data is written by an initiator to a target with wrapping addressing.
    NOC_PKT_OPC_WRC = 6, ///< Conditional Write. This write is only executed if there is a matching monitor in the target.
    NOC_PKT_OPC_RESERVED_7 = 7, ///< Reserved opcode value
    NOC_PKT_OPC_PRE_RD = 8, ///< Preamble Packet followed by a Read packet of a Linked Sequence.
    NOC_PKT_OPC_PRE_WR = 9, ///< Preamble Packet followed by a Write packet of a Linked Sequence.
    NOC_PKT_OPC_URG = 10, ///< Urgency Packet. Used for pressure and urgency management.
    NOC_PKT_OPC_ID_LAST ///< Last value for ID type noc_pkt_opc
} p64h_sysc_ras_noc_pkt_opc_id_t;


/**
 * @brief Sys noc pkt init flow encoding
 */
typedef enum {
    SYS_NOC_INIT_cpu_periph = 0, ///< cpu_periph initiator
    SYS_NOC_INIT_cpu_sys = 1, ///< cpu_sys initiator
    SYS_NOC_INIT_dma_master = 2, ///< dma_master initiator
    SYS_NOC_INIT_sec_dma_master = 3, ///< sec_dma_master initiator
    SYS_NOC_INIT_spw_rmap = 4, ///< spw_rmap initiator
    SYS_NOC_INIT_spw_rx = 5, ///< spw_rx initiator
    SYS_NOC_INIT_spw_tx = 6, ///< spw_tx initiator
    SYS_NOC_INIT_ID_LAST ///< Last value for ID type sys_noc_init
} p64h_sysc_ras_sys_noc_init_id_t;


/**
 * @brief Sys noc pkt target flow encoding
 */
typedef enum {
    SYS_NOC_TARG_app_noc = 0, ///< app_noc target
    SYS_NOC_TARG_cpu_front = 1, ///< cpu_front target
    SYS_NOC_TARG_dma_ctrl = 2, ///< dma_ctrl target
    SYS_NOC_TARG_edac_ctrl = 3, ///< edac_ctrl target
    SYS_NOC_TARG_elapsed_timer = 4, ///< elapsed_timer target
    SYS_NOC_TARG_flash0_data = 5, ///< flash0_data target
    SYS_NOC_TARG_flash1_data = 6, ///< flash1_data target
    SYS_NOC_TARG_gpio = 7, ///< gpio target
    SYS_NOC_TARG_i2c = 8, ///< i2c target
    SYS_NOC_TARG_noc_config = 9, ///< noc_config target
    SYS_NOC_TARG_ocr_ctrl = 10, ///< ocr_ctrl target
    SYS_NOC_TARG_ocr_data = 11, ///< ocr_data target
    SYS_NOC_TARG_qspi0_ctrl = 12, ///< qspi0_ctrl target
    SYS_NOC_TARG_qspi1_ctrl = 13, ///< qspi1_ctrl target
    SYS_NOC_TARG_sec_mbox = 14, ///< sec_mbox target
    SYS_NOC_TARG_spw_ctrl = 15, ///< spw_ctrl target
    SYS_NOC_TARG_svc_noc_config = 16, ///< svc_noc_config target
    SYS_NOC_TARG_sysreg = 17, ///< sysreg target
    SYS_NOC_TARG_timers = 18, ///< timers target
    SYS_NOC_TARG_uart = 19, ///< uart target
    SYS_NOC_TARG_wdog = 20, ///< wdog target
    SYS_NOC_TARG_wgchecker = 21, ///< wgchecker target
    SYS_NOC_TARG_ID_LAST ///< Last value for ID type sys_noc_targ
} p64h_sysc_ras_sys_noc_targ_id_t;


/**
 * @brief App noc pkt init flow encoding
 */
typedef enum {
    APP_NOC_INIT_cpu_clstr0_mem = 0, ///< apnoc_cpu_clstr0_mem initiator
    APP_NOC_INIT_cpu_clstr0_sys = 1, ///< apnoc_cpu_clstr0_sys initiator
    APP_NOC_INIT_cpu_clstr1_mem = 2, ///< apnoc_cpu_clstr1_mem initiator
    APP_NOC_INIT_cpu_clstr1_sys = 3, ///< apnoc_cpu_clstr1_sys initiator
    APP_NOC_INIT_ddr_encrypt_i = 4, ///< apnoc_ddr_encrypt_i initiator
    APP_NOC_INIT_enet_ep_0 = 5, ///< apnoc_enet_ep_0 initiator
    APP_NOC_INIT_enet_ep_1 = 6, ///< apnoc_enet_ep_1 initiator
    APP_NOC_INIT_enet_ep_2 = 7, ///< apnoc_enet_ep_2 initiator
    APP_NOC_INIT_enet_ep_3 = 8, ///< apnoc_enet_ep_3 initiator
    APP_NOC_INIT_enet_swr_rdma1_pie_highbw = 9, ///< apnoc_enet_swr_rdma1_pie_highbw initiator
    APP_NOC_INIT_enet_swr_rdma1_roce_highbw = 10, ///< apnoc_enet_swr_rdma1_roce_highbw initiator
    APP_NOC_INIT_enet_swr_rdma1_roce_lowbw = 11, ///< apnoc_enet_swr_rdma1_roce_lowbw initiator
    APP_NOC_INIT_enet_swr_rdma2_pie_highbw = 12, ///< apnoc_enet_swr_rdma2_pie_highbw initiator
    APP_NOC_INIT_enet_swr_rdma2_roce_highbw = 13, ///< apnoc_enet_swr_rdma2_roce_highbw initiator
    APP_NOC_INIT_enet_swr_rdma2_roce_lowbw = 14, ///< apnoc_enet_swr_rdma2_roce_lowbw initiator
    APP_NOC_INIT_iommu_0_pds = 15, ///< apnoc_iommu_0_pds initiator
    APP_NOC_INIT_iommu_1_pds = 16, ///< apnoc_iommu_1_pds initiator
    APP_NOC_INIT_m2_spw0 = 17, ///< apnoc_m2_spw0 initiator
    APP_NOC_INIT_m2_spw1 = 18, ///< apnoc_m2_spw1 initiator
    APP_NOC_INIT_m2_usb0 = 19, ///< apnoc_m2_usb0 initiator
    APP_NOC_INIT_m2_usb1 = 20, ///< apnoc_m2_usb1 initiator
    APP_NOC_INIT_m3_appdma0 = 21, ///< apnoc_m3_appdma0 initiator
    APP_NOC_INIT_m3_appdma1 = 22, ///< apnoc_m3_appdma1 initiator
    APP_NOC_INIT_m3_trace_sok = 23, ///< apnoc_m3_trace_sok initiator
    APP_NOC_INIT_nvm_dma0 = 24, ///< apnoc_nvm_dma0 initiator
    APP_NOC_INIT_nvm_dma1 = 25, ///< apnoc_nvm_dma1 initiator
    APP_NOC_INIT_nvm_sd_dma0 = 26, ///< apnoc_nvm_sd_dma0 initiator
    APP_NOC_INIT_nvm_sd_dma1 = 27, ///< apnoc_nvm_sd_dma1 initiator
    APP_NOC_INIT_pcie_0_ctl0_i = 28, ///< apnoc_pcie_0_ctl0_i initiator
    APP_NOC_INIT_pcie_0_ctl1_i = 29, ///< apnoc_pcie_0_ctl1_i initiator
    APP_NOC_INIT_pcie_1_ctl0_i = 30, ///< apnoc_pcie_1_ctl0_i initiator
    APP_NOC_INIT_pcie_1_ctl1_i = 31, ///< apnoc_pcie_1_ctl1_i initiator
    APP_NOC_INIT_service_noc_initiator = 32, ///< apnoc_service_noc_initiator initiator
    APP_NOC_INIT_sys_noc = 33, ///< apnoc_sys_noc initiator
    APP_NOC_INIT_user_crypto_i = 34, ///< apnoc_user_crypto_i initiator
    APP_NOC_INIT_ID_LAST ///< Last value for ID type app_noc_init
} p64h_sysc_ras_app_noc_init_id_t;


/**
 * @brief App noc pkt target flow encoding
 */
typedef enum {
    APP_NOC_TARG_cpu_clstr0_front = 0, ///< apnoc_cpu_clstr0_front target
    APP_NOC_TARG_cpu_clstr0_pmc = 1, ///< apnoc_cpu_clstr0_pmc target
    APP_NOC_TARG_cpu_clstr1_front = 2, ///< apnoc_cpu_clstr1_front target
    APP_NOC_TARG_cpu_clstr1_pmc = 3, ///< apnoc_cpu_clstr1_pmc target
    APP_NOC_TARG_ddr_a_0 = 4, ///< apnoc_ddr_a_0 target
    APP_NOC_TARG_ddr_a_1 = 5, ///< apnoc_ddr_a_1 target
    APP_NOC_TARG_ddr_b_0 = 6, ///< apnoc_ddr_b_0 target
    APP_NOC_TARG_ddr_b_1 = 7, ///< apnoc_ddr_b_1 target
    APP_NOC_TARG_ddr_cfg = 8, ///< apnoc_ddr_cfg target
    APP_NOC_TARG_ddr_encrypt_hp_csr = 9, ///< apnoc_ddr_encrypt_hp_csr target
    APP_NOC_TARG_ddr_encrypt_t = 10, ///< apnoc_ddr_encrypt_t target
    APP_NOC_TARG_enet_ep_cfg = 11, ///< apnoc_enet_ep_cfg target
    APP_NOC_TARG_enet_swr_rdma1_mchp_cfg = 12, ///< apnoc_enet_swr_rdma1_mchp_cfg target
    APP_NOC_TARG_enet_swr_rdma1_roce_command = 13, ///< apnoc_enet_swr_rdma1_roce_command target
    APP_NOC_TARG_enet_swr_rdma2_mchp_cfg = 14, ///< apnoc_enet_swr_rdma2_mchp_cfg target
    APP_NOC_TARG_enet_swr_rdma2_roce_command = 15, ///< apnoc_enet_swr_rdma2_roce_command target
    APP_NOC_TARG_enet_swr_switch_cfg = 16, ///< apnoc_enet_swr_switch_cfg target
    APP_NOC_TARG_enet_swr_top_cfg = 17, ///< apnoc_enet_swr_top_cfg target
    APP_NOC_TARG_iommu_0_cfg = 18, ///< apnoc_iommu_0_cfg target
    APP_NOC_TARG_iommu_1_cfg = 19, ///< apnoc_iommu_1_cfg target
    APP_NOC_TARG_iommu_ss_cfg = 20, ///< apnoc_iommu_ss_cfg target
    APP_NOC_TARG_m2_hp_spw_csr = 21, ///< apnoc_m2_hp_spw_csr target
    APP_NOC_TARG_m2_jtag_spi = 22, ///< apnoc_m2_jtag_spi target
    APP_NOC_TARG_m2_other_0 = 23, ///< apnoc_m2_other_0 target
    APP_NOC_TARG_m2_other_1 = 24, ///< apnoc_m2_other_1 target
    APP_NOC_TARG_m3_appdma0_hp_csr = 25, ///< apnoc_m3_appdma0_hp_csr target
    APP_NOC_TARG_m3_appdma1_hp_csr = 26, ///< apnoc_m3_appdma1_hp_csr target
    APP_NOC_TARG_m3_ipc_0 = 27, ///< apnoc_m3_ipc_0 target
    APP_NOC_TARG_m3_ipc_1 = 28, ///< apnoc_m3_ipc_1 target
    APP_NOC_TARG_m3_nmra0_t = 29, ///< apnoc_m3_nmra0_t target
    APP_NOC_TARG_m3_nmra1_t = 30, ///< apnoc_m3_nmra1_t target
    APP_NOC_TARG_m3_ocr0_mem = 31, ///< apnoc_m3_ocr0_mem target
    APP_NOC_TARG_m3_ocr1_mem = 32, ///< apnoc_m3_ocr1_mem target
    APP_NOC_TARG_m3_other = 33, ///< apnoc_m3_other target
    APP_NOC_TARG_nvm_edac0 = 34, ///< apnoc_nvm_edac0 target
    APP_NOC_TARG_nvm_edac1 = 35, ///< apnoc_nvm_edac1 target
    APP_NOC_TARG_nvm_sram_edac0_0 = 36, ///< apnoc_nvm_sram_edac0_0 target
    APP_NOC_TARG_nvm_sram_edac0_1 = 37, ///< apnoc_nvm_sram_edac0_1 target
    APP_NOC_TARG_nvm_sram_edac1_0 = 38, ///< apnoc_nvm_sram_edac1_0 target
    APP_NOC_TARG_nvm_sram_edac1_1 = 39, ///< apnoc_nvm_sram_edac1_1 target
    APP_NOC_TARG_nvm_sram_edac2_0 = 40, ///< apnoc_nvm_sram_edac2_0 target
    APP_NOC_TARG_nvm_sram_edac2_1 = 41, ///< apnoc_nvm_sram_edac2_1 target
    APP_NOC_TARG_nvm_ss_cfg = 42, ///< apnoc_nvm_ss_cfg target
    APP_NOC_TARG_pcie_0_cfg = 43, ///< apnoc_pcie_0_cfg target
    APP_NOC_TARG_pcie_0_ctl0_t = 44, ///< apnoc_pcie_0_ctl0_t target
    APP_NOC_TARG_pcie_0_ctl1_t = 45, ///< apnoc_pcie_0_ctl1_t target
    APP_NOC_TARG_pcie_1_cfg = 46, ///< apnoc_pcie_1_cfg target
    APP_NOC_TARG_pcie_1_ctl0_t = 47, ///< apnoc_pcie_1_ctl0_t target
    APP_NOC_TARG_pcie_1_ctl1_t = 48, ///< apnoc_pcie_1_ctl1_t target
    APP_NOC_TARG_service_bus_service = 49, ///< apnoc_service_bus_service target
    APP_NOC_TARG_sys_ctl_int_status = 50, ///< apnoc_sys_ctl_int_status target
    APP_NOC_TARG_user_crypto_cfg = 51, ///< apnoc_user_crypto_cfg target
    APP_NOC_TARG_user_crypto = 52, ///< apnoc_user_crypto_t target
    APP_NOC_TARG_ID_LAST ///< Last value for ID type app_noc_targ
} p64h_sysc_ras_app_noc_targ_id_t;


/**
 * @brief DDR noc pkt init flow encoding
 */
typedef enum {
    DDR_NOC_INIT_a_0 = 0, ///< a_0 initiator
    DDR_NOC_INIT_a_1 = 1, ///< a_1 initiator
    DDR_NOC_INIT_b_0 = 2, ///< b_0 initiator
    DDR_NOC_INIT_b_1 = 3, ///< b_1 initiator
    DDR_NOC_INIT_svc = 4, ///< svc initiator
    DDR_NOC_INIT_ID_LAST ///< Last value for ID type ddr_noc_init
} p64h_sysc_ras_ddr_noc_init_id_t;


/**
 * @brief DDR noc pkt target flow encoding
 */
typedef enum {
    DDR_NOC_TARG_edac_0 = 0, ///< edac_0 target
    DDR_NOC_TARG_edac_1 = 1, ///< edac_1 target
    DDR_NOC_TARG_isvc = 2, ///< isvc target
    DDR_NOC_TARG_pcbi = 3, ///< pcbi target
    DDR_NOC_TARG_wg_0 = 4, ///< wg_0 target
    DDR_NOC_TARG_wg_1 = 5, ///< wg_1 target
    DDR_NOC_TARG_wg_2 = 6, ///< wg_2 target
    DDR_NOC_TARG_wg_3 = 7, ///< wg_3 target
    DDR_NOC_TARG_ID_LAST ///< Last value for ID type ddr_noc_targ
} p64h_sysc_ras_ddr_noc_targ_id_t;


//////////////////////
// Error Data Structs
//////////////////////
/**
 * @brief Error injection target address
 */
typedef struct __attribute__((packed)) {
    uint32_t addr_lo; ///< LSB of address targeted for error injection
    uint32_t addr_hi; ///< MSB of address targeted for error injection
} p64h_sysc_ras_target_address_t;


/**
 * @brief Address offset from the target resource base address
 */
typedef struct __attribute__((packed)) {
    uint32_t value; ///< Address offset value
} p64h_sysc_ras_address_offset_t;


/**
 * @brief OCR ECC error data
 */
typedef struct __attribute__((packed)) {
    uint32_t word_addr; ///< Word address of the memory word where an error was detected
    uint16_t word_len; ///< Word length in bytes
    uint8_t affected_grp_map; ///< Bitmap of which ECC group within a memory word have been affected by an ECC error. Each word is made up of a number of 32bits data and 7bits of ECC.
} p64h_sysc_ras_ocr_ecc_t;


/**
 * @brief Lockstep error injection parameters
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ls_einj_mod_type_id_t module_type; ///< Lockstep wrapper component type
    uint32_t module_number; ///< Lockstep wrapper module number. Can be either ls_chk_mod or ls_broadcast_mod values.
    uint32_t error_pattern; ///< Bit pattern to be injected as error. Each bit represents a data bit within the selected lockstep module data path.
    bool trigger_on_level; ///< When set to true, error injection is triggered on level. When set to false, error injection is triggered on edge.
} p64h_sysc_ras_ls_einj_params_t;


/**
 * @brief Extensible cache ECC error injection parameters
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ext_cache_slice_id_t slice_idx; ///< Extensible cache slice index
    p64h_sysc_ras_ext_cache_bank_id_t bank_idx; ///< Extensible cache bank index within the slice
    uint16_t num_repeat; ///< Number of times to repeat the error injection
    uint16_t delay; ///< Delay between repeats
} p64h_sysc_ras_ecache_einj_params_t;


/**
 * @brief PL2 cache error injection parameters
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_pl2_inst_id_t pl2_inst; ///< PL2 instance index
    bool on_write; ///< When set to true, error is injected on write access. When set to false, error is injected on read access (no data corruption).
    uint8_t bit_index; ///< Bit index within the cache data or tag to inject the ECC error
} p64h_sysc_ras_pl2_einj_params_t;


/**
 * @brief Temperature and voltage sensor monitor temperature event data
 */
typedef struct __attribute__((packed)) {
    uint16_t tvs_val_vdd; ///< Converted VDD value extracted by the monitor at the time of the event
    uint16_t tvs_val_vdd18; ///< Converted VDD 1.8 value extracted by the monitor at the time of the event
    uint16_t tvs_val_adc; ///< Converted ADC value extracted by the monitor at the time of the event
    uint16_t tvs_val_temp; ///< Converted temperature value extracted by the monitorat the time of the event
} p64h_sysc_ras_temp_evt_t;


/**
 * @brief Clock frequency outside threshold event data from the clock monitor block
 */
typedef struct __attribute__((packed)) {
    uint8_t curr_level; ///< Current clock monitor level value
    uint8_t err_level; ///< Clock monitor level value that was present at the moment of the error event that triggered entry to the failed state
    uint16_t tap_cfg_code; ///< Current clock monitor delay line tap configuration code value
} p64h_sysc_ras_cmon_thres_evt_t;


/**
 * @brief Worldguard checker error data
 */
typedef struct __attribute__((packed)) {
    uint32_t wg_err_addr_lo; ///< Lower bits of target address of the transaction causing fault in a slot
    uint32_t wg_err_addr_hi; ///< Higher bits of target address of the transaction causing fault in a slot
    uint16_t wid_value; ///< WID of the transaction at fault
} p64h_sysc_ras_wgc_error_t;


/**
 * @brief Firmware error data
 */
typedef struct __attribute__((packed)) {
    p64h_err_t id; ///< Unique ID of the error encountered during execution
    p64h_comp_t svc_comp; ///< Service which encountered the error
} p64h_sysc_ras_fw_error_t;


/**
 * @brief X288 cache error set, way and bank information
 */
typedef struct __attribute__((packed)) {
    uint32_t set; ///< Set/Row number of the cache
    uint16_t way; ///< Way/Column number of the cache
    uint16_t bank; ///< Bank number of the cache
} p64h_sysc_ras_x288_setwaybank_t;


/**
 * @brief Error data retrieved from a lockstep error within the x288
 */
typedef struct __attribute__((packed)) {
    uint32_t check_id; ///< ID of check module which generated a lockstep error
    uint32_t syndrome_lo; ///< LSB of bits in error according to the lockstep comparator
    uint32_t syndrome_hi; ///< MSB of bits in error according to the lockstep comparator
} p64h_sysc_ras_x288_ls_error_t;


/**
 * @brief Error data related to an L3 cache tag error in the x288
 */
typedef struct __attribute__((packed)) {
    uint32_t addr_lo; ///< LSB of address at which error occurred within the cache
    uint32_t addr_hi; ///< MSB of address at which error occurred within the cache
    uint32_t way; ///< Cache way associated with the error
} p64h_sysc_ras_x288_l3_tag_err_t;


/**
 * @brief Error data related to an L3 cache data error in the x288
 */
typedef struct __attribute__((packed)) {
    uint32_t addr_lo; ///< LSB of address at which error occurred within the cache
    uint32_t addr_hi; ///< MSB of address at which error occurred within the cache
    uint16_t data_buffer_id; ///< Cache data buffer ID
    uint8_t data_bank_id; ///< Cache data bank ID
    uint8_t tag_bank_id; ///< Cache tag bank ID
} p64h_sysc_ras_x288_l3_data_err_t;


/**
 * @brief Error data related to a L3 cache data line that produced a corrupted data
 */
typedef struct __attribute__((packed)) {
    uint32_t addr_lo; ///< LSB of address at which error occurred within the cache
    uint32_t addr_hi; ///< MSB of address at which error occurred within the cache
    uint32_t set; ///< Set/Row number of the cache
    uint16_t way; ///< Way/Column number of the cache
    uint16_t bank; ///< Bank number of the cache
} p64h_sysc_ras_x288_l3_data_corrupt_t;


/**
 * @brief Error data related
 */
typedef struct __attribute__((packed)) {
    uint32_t addr_lo; ///< LSB of address at which error occurred within the cache
    uint32_t addr_hi; ///< MSB of address at which error occurred within the cache
    uint32_t req_type; ///< ID of Tilelink request denial. Possible values defined in p64h_sysc_ras_tl_req_denied_type_id_t
} p64h_sysc_ras_x288_l3_tl_denied_t;


/**
 * @brief Error data reported when a de-interleaver error is detected within the x288
 */
typedef struct __attribute__((packed)) {
    uint32_t resp_ch; ///< ResponseID of the AXI transaction that encountered an error
} p64h_sysc_ras_x288_deint_err_t;


/**
 * @brief Error data reported when an IOMMU error is encountered
 */
typedef struct __attribute__((packed)) {
    uint32_t pid; ///< Process ID
    uint8_t pv; ///< When set to 1, process ID is valid. When set to 0, the process ID is not valid.
    uint8_t priv; ///< When set to 1, transaction was in supervisor mode, otherwise transaction not from supervisor mode.
    uint16_t ttyp; ///< Inbound transaction type when the error was encountered
    uint32_t did; ///< Device ID of the transaction
} p64h_sysc_ras_iommu_err_t;


/**
 * @brief NVM subsystem edac error event data
 */
typedef struct __attribute__((packed)) {
    uint32_t edac_idx; ///< Internal edac instance index
    p64h_sysc_ras_nvm_edac_mode_id_t mode; ///< EDAC mode (SECDED or BCH)
    uint16_t bch_type; ///< BCH type if the mode is BCH, otherwise 0
    uint16_t bch_block_size; ///< BCH block size if the mode is BCH, otherwise 0
    uint32_t pre_ecc_addr_lo; ///< Base address (pre-FEC encoding) LSB of the FEC block in which the error event was detected.
    uint32_t pre_ecc_addr_hi; ///< Base address (pre-FEC encoding) MSB of the FEC block in which the error event was detected.
    uint32_t post_ecc_addr_lo; ///< Base address (post-FEC encoding) LSB of the FEC block in which the error event was detected.
    uint32_t post_ecc_addr_hi; ///< Base address (post-FEC encoding) MSB of the FEC block in which the error event was detected.
    uint32_t num_corr_errs; ///< Number of correctable errors that have been recorded for the address since the last time it was read
    uint32_t cor_bitmask_lo; ///< Bitmask of bits that have been corrected within the 64bit word at the specified address. In SECDED mode, the data beat and parity beat corrected bits are OR'ed together. IN BCH mode, the corrected bits of all words within a FEC data block are OR'ed together.
    uint32_t cor_bitmask_hi; ///< Bitmask of bits that have been corrected within the 64bit word at the specified address. In SECDED mode, the data beat and parity beat corrected bits are OR'ed together. IN BCH mode, the corrected bits of all words within a FEC data block are OR'ed together.
} p64h_sysc_ras_nvm_sram_edac_mon_cor_evt_t;


/**
 * @brief NVM subsystem edac error event data
 */
typedef struct __attribute__((packed)) {
    uint32_t edac_idx; ///< Internal edac instance index
    p64h_sysc_ras_nvm_edac_mode_id_t mode; ///< EDAC mode (SECDED or BCH)
    uint16_t bch_type; ///< BCH type if the mode is BCH, otherwise 0
    uint16_t bch_block_size; ///< BCH block size if the mode is BCH, otherwise 0
    uint32_t pre_ecc_addr_lo; ///< Base address (pre-FEC encoding) LSB of the FEC block in which the error event was detected.
    uint32_t pre_ecc_addr_hi; ///< Base address (pre-FEC encoding) MSB of the FEC block in which the error event was detected.
    uint32_t post_ecc_addr_lo; ///< Base address (post-FEC encoding) LSB of the FEC block in which the error event was detected.
    uint32_t post_ecc_addr_hi; ///< Base address (post-FEC encoding) MSB of the FEC block in which the error event was detected.
    uint8_t failed_decodes_mask; ///< Bitmask of all the decoders that detected an uncorrectable error for the address. There are 8 parallel decoders that can detect uncorrectable errors.
} p64h_sysc_ras_nvm_sram_edac_mon_uncor_evt_t;


/**
 * @brief SRAM EDAC error injection parameters for bus SECDED errors
 */
typedef struct __attribute__((packed)) {
    uint32_t cnt; ///< How many bits get flipped within the databeat
    uint32_t beat_offset; ///< The starting position within the databeat to start flipping
    uint32_t beats; ///< The number of databeats being injected with errors
    uint32_t burst_offset; ///< Allows some initial delay before injecting errors into the data stream
    p64h_sysc_ras_sram_edac_inst_id_t target_edac_inst; ///< Which instant(s) of the edac to inject the error into
} p64h_sysc_ras_sram_edac_dec_einj_t;


/**
 * @brief SRAM EDAC error injection parameters for bus SECDED errors
 */
typedef struct __attribute__((packed)) {
    uint32_t inj_offset; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs. This parameter is only used for uncorrectable errors (TRANS_DROP errors). Correctable errors use a fixed offset (FAULT_CORRECTED errors).
    p64h_sysc_ras_sram_edac_inst_id_t target_edac_inst; ///< Which instant(s) of the edac to inject the error into
} p64h_sysc_ras_sram_edac_bus_secded_einj_t;


/**
 * @brief NVM EDAC error injection parameters
 */
typedef struct __attribute__((packed)) {
    uint32_t err_cnt; ///< How many bits get flipped within the databeat
    uint32_t err_offset; ///< The starting position within the databeat to start flipping
    uint32_t err_beats; ///< The number of databeats being injected with errors
    uint32_t err_burst_offset; ///< Allows some initial delay before injecting errors into the data stream
    uint32_t injection_mask; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs
    uint32_t injection_offset; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs
    p64h_sysc_ras_nvm_edac_err_inj_stage_id_t injection_stage; ///< Which stage of the edac to inject the error in
    p64h_sysc_ras_nvm_edac_inst_id_t target_edac_inst; ///< Which instant(s) of the edac to inject the error into
} p64h_sysc_ras_nvm_edac_params_t;


/**
 * @brief Information on the expected data extracted from the NVM EMON and the actual data extracted.
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_nvm_edac_mode_id_t fec_mode; ///< EMON FEC mode at the time of the event
    bool is_correctable; ///< Whether the error is correctable or not
    uint32_t expct_num_entries; ///< The expected number of entries in the EMON data RAMs for the EDAC error that was detected, based on the FEC mode and whether the error is correctable or uncorrectable.
    uint32_t act_num_entries; ///< The actual number of entries in the EMON data RAMs for the EDAC error that was detected, based on the FEC mode and whether the error is correctable or uncorrectable.
} p64h_sysc_ras_nvm_emon_ext_err_t;


/**
 * @brief Information on the expected data extracted from the DDR EMON and the actual data extracted.
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ddr_edac_mode_id_t fec_mode; ///< EMON FEC mode at the time of the event
    bool is_correctable; ///< Whether the error is correctable or not
    uint32_t expct_num_entries; ///< The expected number of entries in the EMON data RAMs for the EDAC error that was detected, based on the FEC mode and whether the error is correctable or uncorrectable.
    uint32_t act_num_entries; ///< The actual number of entries in the EMON data RAMs for the EDAC error that was detected, based on the FEC mode and whether the error is correctable or uncorrectable.
} p64h_sysc_ras_ddr_emon_ext_err_t;


/**
 * @brief DDR EDAC error event parameters that are used to determine the expected data in the EMON for validation
 */
typedef struct __attribute__((packed)) {
    bool is_enc_inj; ///< If true, the error will be injected during the encoding stage according to the encoder injection parameters (enc_addr_in, enc_err_sel, enc_poison_meta, enc_addr_filt, enc_err_mask). If false, the error will be injected during the decoding stage according to the decoder injection parameters (dec_insert_cycle, dec_insert_bit_loc, dec_insert_mode, dec_insert_enable).
    uint64_t enc_addr_in; ///< Address in, 40 bits in use
    p64h_sysc_ras_ddr_edac_err_sel_id_t enc_err_sel; ///< RS encoder error selection mode
    uint8_t enc_poison_meta; ///< 3-bit mask for inserting errors in meta and poison, bits [2:1] is for meta and [0] is for poison
    uint8_t enc_addr_filt; ///< Errors will be inserted to the packets matching with address_in or not, 0 (disabled) or 1 (enabled)
    unsigned char enc_err_loc[13]; ///< Array of error locations within the FEC block (64bytes) into which errors will be injected (valid range [0,63]). Up to 13 possible locations can be specified at the same time. To inject an uncorrectable error, more than 8 bytes of error bits must be injected.
    unsigned char enc_err_mask[13]; ///< Array of error masks for each error location specified through the enc_err_loc array. Each error location corresponds to a byte in the FEC block, therefore the mask is a byte mask that specifies which bits at the byte location into which an error will be injected.
    uint8_t dec_insert_cycle; ///< DI fault inserter cycle, 0 (cycle 0) or 1 (cycle 1)
    uint8_t dec_insert_bit_loc; ///< DI fault inserter bit location, valid for modes 0, 1, 2, and 3. For modes 0 and 2, the valid range is [0, 255], for modes 1 and 3, the valid range is [0, 17].
    uint8_t dec_insert_enable; ///< DI fault inserter enable, 0 (disabled) or 1 (enabled).
    p64h_sysc_ras_ddr_edac_di_fault_sel_id_t dec_insert_mode; ///< DI fault inserter mode
} p64h_sysc_ras_ddr_edac_emon_evt_einj_t;


/**
 * @brief DDR EDAC error injection parameters for an internal encoder BUS error
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ddr_edac_err_sel_id_t rs_enc_err_sel; ///< RS encoder error selection mode
} p64h_sysc_ras_ddr_edac_enc_int_einj_t;


/**
 * @brief ENET EP error injection parameters
 */
typedef struct __attribute__((packed)) {
    bool isolated; ///< Configuration for a isolating diagnostics before beginning fault injection. When high diagnostics are isolated from surrounding logic to prevent unpredicatble dependency during fault injection. When low, checkers depend on the state of surrounding functional logic during fault injection supporting a functional mode test.
    bool continuous; ///< Configuration for a continuous fault injection. When fault injection is started, it will inject a fault continuously if this bit is high, otherwise it will inject a one clock cycle fault into the diagnostic
    bool double_inj; ///< Configuration for a double fault injection. When fault injection is started, it will inject a double fault if this bit is high, otherwise it will inject a single fault
    p64h_sysc_ras_enet_ep_diag_inst_id_t diag_inst; ///< Instance index. Each diagnostic instance has a unique number or ID. The number of instances is configuration dependent.
    uint16_t first_bit; ///< Defines the index of the first bit to inject on
    uint16_t second_bit; ///< Defines the index of the second bit to inject on
} p64h_sysc_ras_enet_dp_err_params_t;


/**
 * @brief EMON cor error event data
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ddr_edac_mode_id_t fec_mode; ///< EMON FEC mode at the time of the event
    uint32_t data_size; ///< Size of the data in a block of FEC according to the FEC mode.
    uint32_t data_addr_lo; ///< Base address LSB of the data in which a correctable error was detected. The error detection is associated with the block of data of the configured size for the FEC mode, starting from this address.
    uint32_t data_addr_hi; ///< Base address MSB of the data in which a correctable error was detected. The error detection is associated with the block of data of the configured size for the FEC mode, starting from this address.
    uint32_t num_cor_errs; ///< Number of correctable errors that have been recorded for the block address since the last time it was read
    uint32_t cor_bitmask_lo; ///< Bitmask LSB indicating which bits within the FEC block have been corrected. This field is only valid for SECDED FEC mode and there should only be one bit set. If more than one bit is set, some data about another corrected bit error was lost. In DEECE mode, we provide only the number of correctable errors and not the bitmask of which bits were corrected within the full FEC block.
    uint32_t cor_bitmask_hi; ///< Bitmask MSB indicating which bits within the FEC block have been corrected. This field is only valid for SECDED FEC mode and there should only be one bit set. If more than one bit is set, some data about another corrected bit error was lost. In DEECE mode, we provide only the number of correctable errors and not the bitmask of which bits were corrected within the full FEC block.
} p64h_sysc_ras_ddr_edac_cor_mon_evt_t;


/**
 * @brief EMON uncor error event data
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ddr_edac_mode_id_t fec_mode; ///< EMON FEC mode at the time of the event
    uint32_t data_size; ///< Size of the data in a block of FEC according to the FEC mode.
    uint32_t data_addr_lo; ///< Base address LSB of the data in which an uncorrectable error was detected. The error detection is associated with the block of data of the configured size for the FEC mode, starting from this address.
    uint32_t data_addr_hi; ///< Base address MSB of the data in which an uncorrectable error was detected. The error detection is associated with the block of data of the configured size for the FEC mode, starting from this address.
    uint16_t failed_decodes_mask; ///< Bitmask of all the decoders that detected an uncorrectable error for the FEC block. In SECDED mode, there can be up to 8 decoders that can detect uncorrectable errors, and thus the valid range of this bitmask is [0, 0x7F]. In DEECE mode, there can be up to 16 decoders that can fail to decode a lane in the FEC block, and thus the valid range of this bitmask is [0, 0xFFFF].
} p64h_sysc_ras_ddr_edac_uncor_mon_evt_t;


/**
 * @brief Performance monitor error event data
 */
typedef struct __attribute__((packed)) {
    uint8_t misc_int_info; ///< Controller Misc Interrupt Info
    uint8_t core_fifo_fill; ///< Core fifo fill
    uint8_t port_fifo_fill; ///< Port fifo fill
} p64h_sysc_ras_ddr_ctrl_pmon_evt_t;


/**
 * @brief DDR PHY error event data
 */
typedef struct __attribute__((packed)) {
    uint16_t dfi_rddata_valid_err; ///< valid error
    uint16_t dfi_rddata_valid_fifo_full; ///< valid fifo fill
} p64h_sysc_ras_ddr_phy_evt_t;


/**
 * @brief Mask for the state of the cores within the x288
 */
typedef struct __attribute__((packed)) {
    uint8_t debug; ///< Mask of cores in debug state
    uint8_t wfi; ///< Mask of cores in wfi state
    uint8_t halt; ///< Mask of cores in halt state
    uint8_t cease; ///< Mask of cores in cease state
} p64h_sysc_ras_x288_cores_state_t;


/**
 * @brief RAM location index for ENET Switch Errors
 */
typedef struct __attribute__((packed)) {
    uint8_t X; ///< X index
    uint8_t Y; ///< Y index
    uint8_t Z; ///< Z index
} p64h_sysc_ras_enet_swr_ram_idx_t;


/**
 * @brief Data provided to characterize an interrupt storm. Once an interrupt storm is detected, the interrupt controller pin is squelched.
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_intr_ctrl_type_t intr_ctrl; ///< Interrupt controller on which the interrupt storm was detected
    uint32_t intr_num; ///< Interrupt pin within the interrupt controller on which the interrupt storm was detected
} p64h_sysc_ras_intr_storm_src_t;


/**
 * @brief Spacewire EDAC error status information
 */
typedef struct __attribute__((packed)) {
    uint8_t corr_count; ///< Number of EDAC corrections made. Saturates at max (255).
    bool uncorrected; ///< Whether an uncorrected error has occurred since last clear.
} p64h_sysc_ras_spw_edac_sts_t;


/**
 * @brief DMA error information
 */
typedef struct __attribute__((packed)) {
    uint8_t ch_id; ///< DMA channel ID associated with the error
} p64h_sysc_ras_dma_error_params_t;


/**
 * @brief Enet EP Service Bus error event data
 */
typedef struct __attribute__((packed)) {
    uint8_t ep0_axi_parity_err; ///< ep0 axi parity error
    uint8_t ep1_axi_parity_err; ///< ep1 axi parity error
    uint8_t ep2_axi_parity_err; ///< ep2 axi parity error
    uint8_t ep3_axi_parity_err; ///< ep3 axi parity error
} p64h_sysc_ras_enet_ep_sb_evt_t;


/**
 * @brief Enet EP Core error event data
 */
typedef struct __attribute__((packed)) {
    uint32_t asf_trans_fault; ///< ASF transaction fault
    uint32_t asf_proto_fault; ///< ASF protocol fault
    uint32_t asf_sram_uncorr_fault_addr; ///< ASF SRAM uncorrectable fault address
    uint8_t asf_sram_uncorr_fault_inst; ///< ASF SRAM uncorrectable fault instance
    uint32_t asf_sram_corr_fault_addr; ///< ASF SRAM correctable fault address
    uint8_t asf_sram_corr_fault_inst; ///< ASF SRAM correctable fault instance
} p64h_sysc_ras_enet_ep_core_evt_t;


/**
 * @brief Sys NoC error packet header information
 */
typedef struct __attribute__((packed)) {
    bool lock; ///< lock field in the error packet header. When the Lock (Lck) bit is set, arbitration will not take place at the end of the packet.
    p64h_sysc_ras_noc_pkt_opc_id_t opc; ///< opc field indicates the transaction type.
    p64h_sysc_ras_sys_noc_init_id_t initFlow; ///< The initiator of the transaction.
    p64h_sysc_ras_sys_noc_targ_id_t targFlow; ///< The target of the transaction.
    uint8_t targSubRange; ///< Target subrange.
    uint8_t seqId; ///< SequenceId of the transaction.
    uint32_t targ_addr_lsb; ///< Address LSB field of the logged packet header.Addr indicates the start address of the transaction, expressed in bytes, in the target address space.Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t targ_addr_msb; ///< Address MSB field of the logged packet header.Addr indicates the start address of the transaction, expressed in bytes, in the target address space.Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t userFlags; ///< User field of the logged packet header
} p64h_sysc_ras_sys_noc_err_pkt_hdr_t;


/**
 * @brief DDR NoC error packet header information
 */
typedef struct __attribute__((packed)) {
    bool lock; ///< lock field in the error packet header. When the Lock (Lck) bit is set, arbitration will not take place at the end of the packet.
    p64h_sysc_ras_noc_pkt_opc_id_t opc; ///< opc field indicates the transaction type.
    p64h_sysc_ras_ddr_noc_init_id_t initFlow; ///< The initiator of the transaction.
    p64h_sysc_ras_ddr_noc_targ_id_t targFlow; ///< The target of the transaction.
    uint16_t targSubRange; ///< Target subrange.
    uint16_t seqId; ///< SequenceId of the transaction.
    uint32_t targ_addr_lsb; ///< Address LSB field of the logged packet header. Addr indicates the start address of the transaction, expressed in bytes, in the target address space. Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t targ_addr_msb; ///< Address MSB field of the logged packet header. Addr indicates the start address of the transaction, expressed in bytes, in the target address space. Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t userFlags; ///< User field of the logged packet header. User information transported as-is from initiator to target, as specified by user flags.
} p64h_sysc_ras_ddr_noc_err_pkt_hdr_t;


/**
 * @brief APP NoC error packet header information
 */
typedef struct __attribute__((packed)) {
    bool lock; ///< lock field in the error packet header. When the Lock (Lck) bit is set, arbitration will not take place at the end of the packet.
    p64h_sysc_ras_noc_pkt_opc_id_t opc; ///< opc field indicates the transaction type.
    p64h_sysc_ras_app_noc_init_id_t initFlow; ///< The initiator of the transaction.
    p64h_sysc_ras_app_noc_targ_id_t targFlow; ///< The target of the transaction.
    uint8_t targSubRange; ///< Target subrange.
    uint16_t seqId; ///< SequenceId of the transaction.
    uint32_t targ_addr_lsb; ///< Address LSB field of the logged packet header.Addr indicates the start address of the transaction, expressed in bytes, in the target address space.Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t targ_addr_msb; ///< Address MSB field of the logged packet header.Addr indicates the start address of the transaction, expressed in bytes, in the target address space.Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t userFlags; ///< User field of the logged packet header
} p64h_sysc_ras_app_noc_err_pkt_hdr_t;


/**
 * @brief fault aggregator fault index to identify the source of the error within the fault aggregator.
 */
typedef struct __attribute__((packed)) {
    uint32_t fault_idx; ///< Fault index
} p64h_sysc_ras_agg_fault_t;


/**
 * @brief ENET Switch TCAM ECC error injection parameters
 */
typedef struct __attribute__((packed)) {
    uint8_t vcap_super_blk_idx; ///< VCAP_SUPER block index (0-4); used for TCAM_VCAP_SUPER_BK_X events only
    uint32_t depth_mask; ///< Bitmask of TCAM depth positions to inject error (bit N = depth index N)
    uint32_t width_mask; ///< Bitmask of TCAM width positions to inject error (bit N = width index N)
} p64h_sysc_ras_enet_swr_tcam_einj_params_t;


/**
 * @brief NVM ctrl error injection parameters for AXI bus SECDED errors
 */
typedef struct __attribute__((packed)) {
    bool enable; ///< When set to true, error injection is enabled. When set to false, error injection is disabled.
    uint32_t inj_offset; ///< Determine the bits to flip for the SECDED_INJ regs.
} p64h_sysc_ras_nvm_ctrl_bus_secded_einj_t;


//////////////////////
// Error Injection Structs
//////////////////////

/**
 * @brief Error Injection attributes types
 */
typedef enum {
    RAS_EINJ_NO_PARAMS = 0, ///< No error injection parameters needed to inject
    RAS_EINJ_ADDRESS_OFFSET = 1, ///< Error injection attribute type p64h_sysc_ras_address_offset_t
    RAS_EINJ_PL2_EINJ_PARAMS = 2, ///< Error injection attribute type p64h_sysc_ras_pl2_einj_params_t
    RAS_EINJ_ECACHE_EINJ_PARAMS = 3, ///< Error injection attribute type p64h_sysc_ras_ecache_einj_params_t
    RAS_EINJ_LS_EINJ_PARAMS = 4, ///< Error injection attribute type p64h_sysc_ras_ls_einj_params_t
    RAS_EINJ_DDR_EDAC_EMON_EVT_EINJ = 5, ///< Error injection attribute type p64h_sysc_ras_ddr_edac_emon_evt_einj_t
    RAS_EINJ_DDR_EDAC_ENC_INT_EINJ = 6, ///< Error injection attribute type p64h_sysc_ras_ddr_edac_enc_int_einj_t
    RAS_EINJ_ENET_SWR_TCAM_EINJ_PARAMS = 7, ///< Error injection attribute type p64h_sysc_ras_enet_swr_tcam_einj_params_t
    RAS_EINJ_ENET_DP_ERR_PARAMS = 8, ///< Error injection attribute type p64h_sysc_ras_enet_dp_err_params_t
    RAS_EINJ_NVM_CTRL_BUS_SECDED_EINJ = 9, ///< Error injection attribute type p64h_sysc_ras_nvm_ctrl_bus_secded_einj_t
    RAS_EINJ_SRAM_EDAC_DEC_EINJ = 10, ///< Error injection attribute type p64h_sysc_ras_sram_edac_dec_einj_t
    RAS_EINJ_SRAM_EDAC_BUS_SECDED_EINJ = 11, ///< Error injection attribute type p64h_sysc_ras_sram_edac_bus_secded_einj_t
} p64h_sysc_ras_einj_attrs_t;


/**
 * @brief Error Injection custom parameters for different error types
 */
typedef union{
    p64h_sysc_ras_address_offset_t address_offset; ///< address_offset type
    p64h_sysc_ras_pl2_einj_params_t pl2_einj_params; ///< pl2_einj_params type
    p64h_sysc_ras_ecache_einj_params_t ecache_einj_params; ///< ecache_einj_params type
    p64h_sysc_ras_ls_einj_params_t ls_einj_params; ///< ls_einj_params type
    p64h_sysc_ras_ddr_edac_emon_evt_einj_t ddr_edac_emon_evt_einj; ///< ddr_edac_emon_evt_einj type
    p64h_sysc_ras_ddr_edac_enc_int_einj_t ddr_edac_enc_int_einj; ///< ddr_edac_enc_int_einj type
    p64h_sysc_ras_enet_swr_tcam_einj_params_t enet_swr_tcam_einj_params; ///< enet_swr_tcam_einj_params type
    p64h_sysc_ras_enet_dp_err_params_t enet_dp_err_params; ///< enet_dp_err_params type
    p64h_sysc_ras_nvm_ctrl_bus_secded_einj_t nvm_ctrl_bus_secded_einj; ///< nvm_ctrl_bus_secded_einj type
    p64h_sysc_ras_sram_edac_dec_einj_t sram_edac_dec_einj; ///< sram_edac_dec_einj type
    p64h_sysc_ras_sram_edac_bus_secded_einj_t sram_edac_bus_secded_einj; ///< sram_edac_bus_secded_einj type
} p64h_sysc_ras_einj_params_t;


/**
 * @brief Error Record Table Entry (ERTE) data
 */
typedef union{
    p64h_sysc_ras_ocr_ecc_t ocr_ecc; ///< ocr_ecc type
    p64h_sysc_ras_app_noc_err_pkt_hdr_t app_noc_err_pkt_hdr; ///< app_noc_err_pkt_hdr type
    p64h_sysc_ras_agg_fault_t agg_fault; ///< agg_fault type
    p64h_sysc_ras_wgc_error_t wgc_error; ///< wgc_error type
    p64h_sysc_ras_x288_deint_err_t x288_deint_err; ///< x288_deint_err type
    p64h_sysc_ras_target_address_t target_address; ///< target_address type
    p64h_sysc_ras_x288_setwaybank_t x288_setwaybank; ///< x288_setwaybank type
    p64h_sysc_ras_x288_l3_data_err_t x288_l3_data_err; ///< x288_l3_data_err type
    p64h_sysc_ras_x288_l3_data_corrupt_t x288_l3_data_corrupt; ///< x288_l3_data_corrupt type
    p64h_sysc_ras_x288_l3_tag_err_t x288_l3_tag_err; ///< x288_l3_tag_err type
    p64h_sysc_ras_x288_l3_tl_denied_t x288_l3_tl_denied; ///< x288_l3_tl_denied type
    p64h_sysc_ras_iommu_err_t iommu_err; ///< iommu_err type
    p64h_sysc_ras_x288_ls_error_t x288_ls_error; ///< x288_ls_error type
    p64h_sysc_ras_x288_cores_state_t x288_cores_state; ///< x288_cores_state type
    p64h_sysc_ras_ddr_ctrl_pmon_evt_t ddr_ctrl_pmon_evt; ///< ddr_ctrl_pmon_evt type
    p64h_sysc_ras_ddr_edac_cor_mon_evt_t ddr_edac_cor_mon_evt; ///< ddr_edac_cor_mon_evt type
    p64h_sysc_ras_ddr_emon_ext_err_t ddr_emon_ext_err; ///< ddr_emon_ext_err type
    p64h_sysc_ras_ddr_edac_uncor_mon_evt_t ddr_edac_uncor_mon_evt; ///< ddr_edac_uncor_mon_evt type
    p64h_sysc_ras_ddr_phy_evt_t ddr_phy_evt; ///< ddr_phy_evt type
    p64h_sysc_ras_ddr_noc_err_pkt_hdr_t ddr_noc_err_pkt_hdr; ///< ddr_noc_err_pkt_hdr type
    p64h_sysc_ras_enet_swr_ram_idx_t enet_swr_ram_idx; ///< enet_swr_ram_idx type
    p64h_sysc_ras_enet_ep_core_evt_t enet_ep_core_evt; ///< enet_ep_core_evt type
    p64h_sysc_ras_enet_ep_sb_evt_t enet_ep_sb_evt; ///< enet_ep_sb_evt type
    p64h_sysc_ras_nvm_sram_edac_mon_cor_evt_t nvm_sram_edac_mon_cor_evt; ///< nvm_sram_edac_mon_cor_evt type
    p64h_sysc_ras_nvm_sram_edac_mon_uncor_evt_t nvm_sram_edac_mon_uncor_evt; ///< nvm_sram_edac_mon_uncor_evt type
    p64h_sysc_ras_nvm_emon_ext_err_t nvm_emon_ext_err; ///< nvm_emon_ext_err type
    p64h_sysc_ras_vdd_thres_detect_id_t vdd_thres_detect; ///< vdd_thres_detect ID type
    p64h_sysc_ras_cmon_thres_evt_t cmon_thres_evt; ///< cmon_thres_evt type
    p64h_sysc_ras_mesh_block_id_t mesh_block; ///< mesh_block ID type
    p64h_sysc_ras_sec_noc_niu_id_t sec_noc_niu; ///< sec_noc_niu ID type
    p64h_sysc_ras_sec_mem_block_id_t sec_mem_block; ///< sec_mem_block ID type
    p64h_sysc_ras_tamper_hw_lock_id_t tamper_hw_lock; ///< tamper_hw_lock ID type
    p64h_sysc_ras_temp_evt_t temp_evt; ///< temp_evt type
    p64h_sysc_ras_dma_error_params_t dma_error_params; ///< dma_error_params type
    p64h_sysc_ras_fw_error_t fw_error; ///< fw_error type
    p64h_sysc_ras_intr_storm_src_t intr_storm_src; ///< intr_storm_src type
    p64h_sysc_ras_spw_edac_sts_t spw_edac_sts; ///< spw_edac_sts type
    p64h_sysc_ras_sys_noc_err_pkt_hdr_t sys_noc_err_pkt_hdr; ///< sys_noc_err_pkt_hdr type
} p64h_sysc_ras_err_data_t;


/**
 * @brief Error Record Table Entry (ERTE) structure
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_error_code_t            err_evt;          ///< Error event identifier encoding
    uint32_t                              timestamp_lo;     ///< LSB of 64-bit timestamp
    uint32_t                              timestamp_hi;     ///< MSB of 64-bit timestamp
    uint32_t                              partition_id;     ///< Resource owner partition
    p64h_sysc_ras_err_data_t              err_data;         ///< Error data specific to the error event
} p64h_sysc_ras_erte_t;
// static_assert(sizeof(p64h_sysc_ras_erte_t) <= 36, "p64h_ras_erte_t bigger than 36 bytes");
#endif // RAS_DATA_DEFS_H

