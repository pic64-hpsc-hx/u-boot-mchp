/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

#ifndef RAS_DATA_DEFS_H
#define RAS_DATA_DEFS_H

#include "generated/p64h_sysc_ras_error_sources.h"
#include "generated/p64h_sysc_errors.h"
#include "env/p64h_sysc_os_specific.h"

/* Public Structs and Enums ----------------------------------------- */

//////////////////////
// ID Types
//////////////////////
/**
 * @brief Extensible Cache Bank Indexes
 */
typedef enum {
    EXT_CACHE_BANK_EXT_CACHE_BANK_0 = 0, ///< extensible cache bank 0
    EXT_CACHE_BANK_EXT_CACHE_BANK_1 = 1, ///< extensible cache bank 1
    EXT_CACHE_BANK_EXT_CACHE_BANK_2 = 2, ///< extensible cache bank 2
    EXT_CACHE_BANK_EXT_CACHE_BANK_3 = 3, ///< extensible cache bank 3
    EXT_CACHE_BANK_ID_LAST ///< Last value for ID type ext_cache_bank
} p64h_sysc_ras_ext_cache_bank_id_t;


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
    SRAM_EDAC_ERR_INJ_STAGE_SECDED_DEC = 0, ///< SECDED decode error injection
    SRAM_EDAC_ERR_INJ_STAGE_BCH_DEC = 1, ///< BCH decode error injection
    SRAM_EDAC_ERR_INJ_STAGE_READ_CMD = 2, ///< Read command error injection
    SRAM_EDAC_ERR_INJ_STAGE_READ_CMD_ADDR = 3, ///< Read command address error injection
    SRAM_EDAC_ERR_INJ_STAGE_READ_DATA_CAPTURE = 4, ///< Read data capture error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_EGRESS = 5, ///< Write command error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_ADDR_EGRESS = 6, ///< Write command address error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_INGRESS = 7, ///< Write command ingress error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_CMD_ADDR_INGRESS = 8, ///< Write command address ingress error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_DATA_CAPTURE = 9, ///< Write data capture error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_DATA_GENERATION = 10, ///< Write data generation error injection
    SRAM_EDAC_ERR_INJ_STAGE_WRITE_DATA_RESPONSE = 11, ///< Write data response error injection
    SRAM_EDAC_ERR_INJ_STAGE_SECDED_ENC = 12, ///< SECDED encode error injection
    SRAM_EDAC_ERR_INJ_STAGE_BCH_ENC = 13, ///< BCH encode error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_NARROW_TRANSFER_MERGE_CURRENT = 14, ///< RMW narrow transfer merge current data error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_NARROW_TRANSFER_MERGE_NEW = 15, ///< RMW narrow transfer merge new data error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_READ = 16, ///< RMW read data error injection
    SRAM_EDAC_ERR_INJ_STAGE_RMW_WRITE = 17, ///< RMW write data error injection
    SRAM_EDAC_ERR_INJ_STAGE_ID_LAST ///< Last value for ID type sram_edac_err_inj_stage
} p64h_sysc_ras_sram_edac_err_inj_stage_id_t;


/**
 * @brief SRAM EDAC error injection instance
 */
typedef enum {
    SRAM_EDAC_INSTANT_EDAC_0 = 0, ///< Inject error in EDAC Instant 0
    SRAM_EDAC_INSTANT_EDAC_1 = 1, ///< Inject error in EDAC Instant 1
    SRAM_EDAC_INSTANT_ID_LAST ///< Last value for ID type sram_edac_instant
} p64h_sysc_ras_sram_edac_instant_id_t;


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
    NVM_EDAC_INSTANT_NVM_0 = 0, ///< Inject error in NVM Instant 0
    NVM_EDAC_INSTANT_NVM_1 = 1, ///< Inject error in NVM Instant 1
    NVM_EDAC_INSTANT_ID_LAST ///< Last value for ID type nvm_edac_instant
} p64h_sysc_ras_nvm_edac_instant_id_t;


/**
 * @brief DDR EDAC error injection stage
 */
typedef enum {
    DDR_EDAC_ERR_INJ_STAGE_READ_CMD = 0, ///< Read command error injection
    DDR_EDAC_ERR_INJ_STAGE_READ_GENERATION = 1, ///< Read generation error injection
    DDR_EDAC_ERR_INJ_STAGE_WRITE_CMD = 2, ///< Write command error injection
    DDR_EDAC_ERR_INJ_STAGE_WRITE_DATA_CAPTURE = 3, ///< Write data capture error injection
    DDR_EDAC_ERR_INJ_STAGE_WRITE_DATA_GENERATION = 4, ///< Write data generation error injection
    DDR_EDAC_ERR_INJ_STAGE_RMW_0 = 5, ///< RMW 0 error injection
    DDR_EDAC_ERR_INJ_STAGE_RMW_1 = 6, ///< RMW 1 error injection
    DDR_EDAC_ERR_INJ_STAGE_RMW_2 = 7, ///< RMW 2 error injection
    DDR_EDAC_ERR_INJ_STAGE_RMW_3 = 8, ///< RMW 3 error injection
    DDR_EDAC_ERR_INJ_STAGE_ID_LAST ///< Last value for ID type ddr_edac_err_inj_stage
} p64h_sysc_ras_ddr_edac_err_inj_stage_id_t;


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
 * @brief OCR ECC error data
 */
typedef struct __attribute__((packed)) {
    uint32_t word_addr; ///< Word address of the memory word where an error was detected
    uint16_t word_len; ///< Word length in bytes
    uint8_t grp_mask; ///< Mask of the 4 byte groups within the word where the error occurred
} p64h_sysc_ras_ocr_ecc_t;


/**
 * @brief OCR ECC error data
 */
typedef struct __attribute__((packed)) {
    uint32_t word_addr; ///< Word address of the memory word where an error was detected
    uint8_t grp_mask; ///< Mask of the 4 byte groups within the word where the error occurred
} p64h_sysc_ras_ocr_ecc_inj_t;


/**
 * @brief Extensible cache ECC error injection parameters
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_ras_ext_cache_bank_id_t bank_idx; ///< Extensible cache bank index
    uint16_t num_repeat; ///< Number of times to repeat the error injection
    uint16_t delay; ///< Delay between repeats
} p64h_sysc_ras_ext_cache_ecc_t;


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
 * @brief EMON error event data
 */
typedef struct __attribute__((packed)) {
    uint32_t emon_loc_cor_0; ///< Locations corrected LSB 0 - 31
    uint32_t emon_loc_cor_1; ///< Locations corrected MSB 32 - 63
    uint32_t emon_loc_uncor; ///< Decoders that have generated uncorrectable decodes
    uint32_t ram_corr; ///< Correctable Memory location addresses
    uint32_t ram_uncorr; ///< Uncorrectable Memory location addresses
} p64h_sysc_ras_sram_edac_emon_evt_t;


/**
 * @brief SRAM EDAC error injection parameters
 */
typedef struct __attribute__((packed)) {
    uint32_t cnt; ///< How many bits get flipped within the databeat
    uint32_t beat_offset; ///< The starting position within the databeat to start flipping
    uint32_t beats; ///< The number of databeats being injected with errors
    uint32_t burst_offset; ///< Allows some initial delay before injecting errors into the data stream
    uint32_t inj_mask; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs
    uint32_t inj_offset; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs
    p64h_sysc_ras_sram_edac_err_inj_stage_id_t stage; ///< Which stage of the edac to inject the error in
    p64h_sysc_ras_sram_edac_instant_id_t target_edac_inst; ///< Which instant(s) of the edac to inject the error into
} p64h_sysc_ras_sram_edac_params_t;


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
    p64h_sysc_ras_nvm_edac_instant_id_t target_edac_inst; ///< Which instant(s) of the edac to inject the error into
} p64h_sysc_ras_nvm_edac_params_t;


/**
 * @brief DDR EDAC error injection parameters
 */
typedef struct __attribute__((packed)) {
    uint32_t err_cnt; ///< How many bits get flipped within the databeat
    uint32_t err_offset; ///< The starting position within the databeat to start flipping
    uint32_t err_beats; ///< The number of databeats being injected with errors
    uint32_t err_burst_offset; ///< Allows some initial delay before injecting errors into the data stream
    uint32_t injection_mask; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs
    uint32_t injection_offset; ///< Determine the bits to flip for the r_XXXX_INJ_CFG[2] regs
    p64h_sysc_ras_ddr_edac_err_inj_stage_id_t injection_stage; ///< Which stage of the edac to inject the error in
} p64h_sysc_ras_ddr_edac_params_t;


/**
 * @brief Mask for the state of the cores within the x288
 */
typedef struct __attribute__((packed)) {
    uint8_t debug; ///< Mask of cores in debug state
    uint8_t wfi; ///< Mask of cores in wfi state
    uint8_t halt; ///< Mask of cores in halt state
    uint8_t cease; ///< Mask of cores in cease state
} p64h_sysc_ras_x288_cores_state_t;


//////////////////////
// Error Injection Structs
//////////////////////

/**
 * @brief Error Injection attributes types
 */
typedef enum {
    RAS_EINJ_OCR_ECC_INJ = 0, ///< Error injection attribute type p64h_sysc_ras_ocr_ecc_inj_t
    RAS_EINJ_SRAM_EDAC_PARAMS = 1, ///< Error injection attribute type p64h_sysc_ras_sram_edac_params_t
} p64h_sysc_ras_einj_attrs_t;


/**
 * @brief Error Injection custom parameters for different error types
 */
typedef union{
    p64h_sysc_ras_ocr_ecc_inj_t ocr_ecc_inj; ///< ocr_ecc_inj type
    p64h_sysc_ras_sram_edac_params_t sram_edac_params; ///< sram_edac_params type
} p64h_sysc_ras_einj_params_t;


/**
 * @brief Error Record Table Entry (ERTE) data
 */
typedef union{
    p64h_sysc_ras_ocr_ecc_t ocr_ecc; ///< ocr_ecc type
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
    p64h_sysc_ras_sram_edac_emon_evt_t sram_edac_emon_evt; ///< sram_edac_emon_evt type
    p64h_sysc_ras_vdd_thres_detect_id_t vdd_thres_detect; ///< vdd_thres_detect ID type
    p64h_sysc_ras_cmon_thres_evt_t cmon_thres_evt; ///< cmon_thres_evt type
    p64h_sysc_ras_mesh_block_id_t mesh_block; ///< mesh_block ID type
    p64h_sysc_ras_sec_noc_niu_id_t sec_noc_niu; ///< sec_noc_niu ID type
    p64h_sysc_ras_sec_mem_block_id_t sec_mem_block; ///< sec_mem_block ID type
    p64h_sysc_ras_tamper_hw_lock_id_t tamper_hw_lock; ///< tamper_hw_lock ID type
    p64h_sysc_ras_temp_evt_t temp_evt; ///< temp_evt type
    p64h_sysc_ras_fw_error_t fw_error; ///< fw_error type
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

