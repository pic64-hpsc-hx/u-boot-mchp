/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef RAS_ERR_SRC_H
#define RAS_ERR_SRC_H

#include <env/p64h_sysc_os_specific.h>

/* Autofilled Macros for decoding Error ID Enum -------------------------------- */
///< @brief Bit-size of the GHES ID field
#define RAS_ERR_PACK_SRC_ID_LEN (uint32_t)5U
///< @brief Bit-size of the GHES structure ID field
#define RAS_ERR_PACK_STRUCT_ID_LEN (uint32_t)6U
///< @brief Bit-size of the GHES structure instance field
#define RAS_ERR_PACK_STRUCT_INST_ID_LEN (uint32_t)7U
///< @brief Bit-size of the error serverity ID field
#define RAS_ERR_PACK_SEV_ID_LEN (uint32_t)3U
///< @brief Bit-size of the error event ID field
#define RAS_ERR_PACK_EVT_ID_LEN (uint32_t)11U

///< @brief Bit position of the RAS GHES
#define RAS_ERR_PACK_SRC_ID_POS (uint32_t)(RAS_ERR_PACK_STRUCT_ID_POS + RAS_ERR_PACK_STRUCT_ID_LEN)
///< @brief Bit position of the GHES structure
#define RAS_ERR_PACK_STRUCT_ID_POS (uint32_t)(RAS_ERR_PACK_STRUCT_INST_ID_POS + RAS_ERR_PACK_STRUCT_INST_ID_LEN)
///< @brief Bit position of the instance of the GHES structure
#define RAS_ERR_PACK_STRUCT_INST_ID_POS (uint32_t)(RAS_ERR_PACK_SEV_ID_POS + RAS_ERR_PACK_SEV_ID_LEN)
///< @brief Bit position of the error event severity
#define RAS_ERR_PACK_SEV_ID_POS (uint32_t)(RAS_ERR_PACK_EVT_ID_POS + RAS_ERR_PACK_EVT_ID_LEN)
///< @brief Bit position of the error event related to the GHES structure
#define RAS_ERR_PACK_EVT_ID_POS (uint32_t)0U

///< @brief Bitmask for the GHES ID field
#define RAS_ERR_PACK_SRC_ID_MASK ((uint32_t)((1U << RAS_ERR_PACK_SRC_ID_LEN) - (uint32_t)1U) << RAS_ERR_PACK_SRC_ID_POS)
///< @brief Bitmask for the GHES structure ID field
#define RAS_ERR_PACK_STRUCT_ID_MASK ((uint32_t)((1U << RAS_ERR_PACK_STRUCT_ID_LEN) - (uint32_t)1U) << RAS_ERR_PACK_STRUCT_ID_POS)
///< @brief Bitmask for the GHES structure instance field
#define RAS_ERR_PACK_STRUCT_INST_ID_MASK ((uint32_t)((1U << RAS_ERR_PACK_STRUCT_INST_ID_LEN) - (uint32_t)1U) << RAS_ERR_PACK_STRUCT_INST_ID_POS)
///< @brief Bitmask for the error severity ID field
#define RAS_ERR_PACK_SEV_ID_MASK ((uint32_t)((1U << RAS_ERR_PACK_SEV_ID_LEN) - (uint32_t)1U) << RAS_ERR_PACK_SEV_ID_POS)
///< @brief Bitmask for the error event ID field
#define RAS_ERR_PACK_EVT_ID_MASK ((uint32_t)((1U << RAS_ERR_PACK_EVT_ID_LEN) - (uint32_t)1U) << RAS_ERR_PACK_EVT_ID_POS)

///< @brief Bit-size of the GHES Signature field
#define RAS_ERR_SIGN_LEN (uint32_t)4U
///< @brief Bit-size of the GHES ID field
#define RAS_ERR_SRC_ID_LEN (uint32_t)5U
///< @brief Bit-size of the GHES structure ID field
#define RAS_ERR_STRUCT_ID_LEN (uint32_t)6U
///< @brief Bit-size of the error event ID field
#define RAS_ERR_EVT_ID_LEN (uint32_t)11U

///< @brief RAS GHES signature
#define RAS_ERR_SIGN 0xAU
///< @brief Bit position of the RAS GHES signature
#define RAS_ERR_SIGN_POS (uint32_t)(RAS_ERR_SRC_ID_POS + RAS_ERR_SRC_ID_LEN)
///< @brief Bit position of the RAS GHES
#define RAS_ERR_SRC_ID_POS (uint32_t)(RAS_ERR_STRUCT_ID_POS + RAS_ERR_STRUCT_ID_LEN)
///< @brief Bit position of the GHES structure
#define RAS_ERR_STRUCT_ID_POS (uint32_t)(RAS_ERR_EVT_ID_POS + RAS_ERR_EVT_ID_LEN)
///< @brief Bit position of the error event related to the GHES structure
#define RAS_ERR_EVT_ID_POS (uint32_t)(0U)

///< @brief Bitmask for the GHES Signature field
#define RAS_ERR_SIGN_MASK ((uint32_t)((1U << RAS_ERR_SIGN_LEN) - (uint32_t)1U) << RAS_ERR_SIGN_POS)
///< @brief Bitmask for the GHES ID field
#define RAS_ERR_SRC_ID_MASK ((uint32_t)((1U << RAS_ERR_SRC_ID_LEN) - (uint32_t)1U) << RAS_ERR_SRC_ID_POS)
///< @brief Bitmask for the GHES structure ID field
#define RAS_ERR_STRUCT_ID_MASK ((uint32_t)((1U << RAS_ERR_STRUCT_ID_LEN) - (uint32_t)1U) << RAS_ERR_STRUCT_ID_POS)
///< @brief Bitmask for the error event ID field
#define RAS_ERR_EVT_ID_MASK ((uint32_t)((1U << RAS_ERR_EVT_ID_LEN) - (uint32_t)1U) << RAS_ERR_EVT_ID_POS)

///< @brief Value used to define a portion of the RAS error encoding as Not-Available
#define RAS_NA 0U

///< @brief Encoding rule for the RAS errors
#define RAS_ERROR_PACK(_source, _structure, _structure_id, _severity, _error) (((_source << RAS_ERR_PACK_SRC_ID_POS) & RAS_ERR_PACK_SRC_ID_MASK) | ((_structure << RAS_ERR_PACK_STRUCT_ID_POS) & RAS_ERR_PACK_STRUCT_ID_MASK) | ((_structure_id << RAS_ERR_PACK_STRUCT_INST_ID_POS) & RAS_ERR_PACK_STRUCT_INST_ID_MASK) | ((_severity << RAS_ERR_PACK_SEV_ID_POS) & RAS_ERR_PACK_SEV_ID_MASK) | ((_error << RAS_ERR_PACK_EVT_ID_POS) & RAS_ERR_PACK_EVT_ID_MASK)) 
///< @brief Decoding rule to obtain the GHES ID from the complete RAS error encoding
#define RAS_ERROR_UNPACK_SOURCE(_error) ((_error & RAS_ERR_PACK_SRC_ID_MASK) >> RAS_ERR_PACK_SRC_ID_POS)
///< @brief Decoding rule to obtain the GHES structure ID from the complete RAS error encoding
#define RAS_ERROR_UNPACK_STRUCTURE(_error) ((_error & RAS_ERR_PACK_STRUCT_ID_MASK) >> RAS_ERR_PACK_STRUCT_ID_POS)
///< @brief Decoding rule to obtain the GHES structure instance from the complete RAS error encoding
#define RAS_ERROR_UNPACK_STRUCTURE_ID(_error) ((_error & RAS_ERR_PACK_STRUCT_INST_ID_MASK) >> RAS_ERR_PACK_STRUCT_INST_ID_POS)
///< @brief Decoding rule to obtain the error severity ID from the complete RAS error encoding
#define RAS_ERROR_UNPACK_SEVERITY(_error) ((_error & RAS_ERR_PACK_SEV_ID_MASK) >> RAS_ERR_PACK_SEV_ID_POS)
///< @brief Decoding rule to obtain the error event ID from the complete RAS error encoding
#define RAS_ERROR_UNPACK_ERROR(_error) ((_error & RAS_ERR_PACK_EVT_ID_MASK) >> RAS_ERR_PACK_EVT_ID_POS)

///< @brief Encoding rule for the RAS errors
#define RAS_ERROR_ENCODE(_source, _structure, _error) (((RAS_ERR_SIGN << RAS_ERR_SIGN_POS) & RAS_ERR_SIGN_MASK) | ((_source << RAS_ERR_SRC_ID_POS) & RAS_ERR_SRC_ID_MASK) | ((_structure << RAS_ERR_STRUCT_ID_POS) & RAS_ERR_STRUCT_ID_MASK) | ((_error << RAS_ERR_EVT_ID_POS) & RAS_ERR_EVT_ID_MASK)) 
///< @brief Decoding rule to obtain the GHES ID from the complete RAS error encoding
#define RAS_ERROR_DECODE_SOURCE(_error) ((_error & RAS_ERR_SRC_ID_MASK) >> RAS_ERR_SRC_ID_POS)
///< @brief Decoding rule to obtain the GHES structure ID from the complete RAS error encoding
#define RAS_ERROR_DECODE_STRUCTURE(_error) ((_error & RAS_ERR_STRUCT_ID_MASK) >> RAS_ERR_STRUCT_ID_POS)
///< @brief Decoding rule to obtain the error event ID from the complete RAS error encoding
#define RAS_ERROR_DECODE_ERROR(_error) ((_error & RAS_ERR_EVT_ID_MASK) >> RAS_ERR_EVT_ID_POS)


/* Public Structs and Enums - populated from Yaml files -------------------------------- */
/// @brief Struct to pack the values to uniquely identify an error of the system

/**
 * @brief Definitions of all identifiers for the RAS Generic Hardware Error Sources (GHES)
 */
typedef enum p64h_ghes_id {
    APP_MEM = 0, ///< APP_MEM generic hardware error source
    APP_NOC = 1, ///< APP_NOC generic hardware error source
    APP_X288 = 2, ///< APP_X288 generic hardware error source
    CLOCK = 3, ///< CLOCK generic hardware error source
    NVM = 4, ///< NVM generic hardware error source
    SEC = 5, ///< SEC generic hardware error source
    SYS = 6, ///< SYS generic hardware error source
    GHES_TYPES_MAX ///< Maximum value of p64h_ghes_id_t enum
} p64h_ghes_id_t;

/**
 * @brief Definitions of all structures within the APP_MEM GHES
 */
typedef enum {
    APP_MEM_STRUCT_OCR = 0, ///< OCR structure ID from the APP_MEM
     APP_MEM_STRUCT_LAST ///< Last value for possible structure within the app_mem GHE
} p64h_ras_app_mem_struc_t;

/**
 * @brief Definitions of all structures within the APP_NOC GHES
 */
typedef enum {
    APP_NOC_STRUCT_WGC = 0, ///< WGC structure ID from the APP_NOC
     APP_NOC_STRUCT_LAST ///< Last value for possible structure within the app_noc GHE
} p64h_ras_app_noc_struc_t;

/**
 * @brief Definitions of all structures within the APP_X288 GHES
 */
typedef enum {
    APP_X288_STRUCT_TILE = 0, ///< TILE structure ID from the APP_X288
     APP_X288_STRUCT_FABRIC = 1, ///< FABRIC structure ID from the APP_X288
     APP_X288_STRUCT_IOMMU = 2, ///< IOMMU structure ID from the APP_X288
     APP_X288_STRUCT_LOCKSTEP = 3, ///< LOCKSTEP structure ID from the APP_X288
     APP_X288_STRUCT_WGC = 4, ///< WGC structure ID from the APP_X288
     APP_X288_STRUCT_LAST ///< Last value for possible structure within the app_x288 GHE
} p64h_ras_app_x288_struc_t;

/**
 * @brief Definitions of all structures within the CLOCK GHES
 */
typedef enum {
    CLOCK_STRUCT_CSU = 0, ///< CSU structure ID from the CLOCK
     CLOCK_STRUCT_LAST ///< Last value for possible structure within the clock GHE
} p64h_ras_clock_struc_t;

/**
 * @brief Definitions of all structures within the NVM GHES
 */
typedef enum {
    NVM_STRUCT_SRAM_EDAC = 0, ///< SRAM_EDAC structure ID from the NVM
     NVM_STRUCT_NVM_EDAC = 1, ///< NVM_EDAC structure ID from the NVM
     NVM_STRUCT_LAST ///< Last value for possible structure within the nvm GHE
} p64h_ras_nvm_struc_t;

/**
 * @brief Definitions of all structures within the SEC GHES
 */
typedef enum {
    SEC_STRUCT_OCR = 0, ///< OCR structure ID from the SEC
     SEC_STRUCT_CSU = 1, ///< CSU structure ID from the SEC
     SEC_STRUCT_PQS = 2, ///< PQS structure ID from the SEC
     SEC_STRUCT_NOC = 3, ///< NOC structure ID from the SEC
     SEC_STRUCT_CMON = 4, ///< CMON structure ID from the SEC
     SEC_STRUCT_TAMPER_MON = 5, ///< TAMPER_MON structure ID from the SEC
     SEC_STRUCT_S7 = 6, ///< S7 structure ID from the SEC
     SEC_STRUCT_RAM = 7, ///< RAM structure ID from the SEC
     SEC_STRUCT_TIMER = 8, ///< TIMER structure ID from the SEC
     SEC_STRUCT_APB2JTAG = 9, ///< APB2JTAG structure ID from the SEC
     SEC_STRUCT_WDOG = 10, ///< WDOG structure ID from the SEC
     SEC_STRUCT_ANA_MON = 11, ///< ANA_MON structure ID from the SEC
     SEC_STRUCT_DMA = 12, ///< DMA structure ID from the SEC
     SEC_STRUCT_TVS_MON = 13, ///< TVS_MON structure ID from the SEC
     SEC_STRUCT_MESH = 14, ///< MESH structure ID from the SEC
     SEC_STRUCT_LAST ///< Last value for possible structure within the sec GHE
} p64h_ras_sec_struc_t;

/**
 * @brief Definitions of all structures within the SYS GHES
 */
typedef enum {
    SYS_STRUCT_OCR = 0, ///< OCR structure ID from the SYS
     SYS_STRUCT_S7 = 1, ///< S7 structure ID from the SYS
     SYS_STRUCT_LAST ///< Last value for possible structure within the sys GHE
} p64h_ras_sys_struc_t;

/**
 * @brief Generic GHES structure ID container
 */
typedef union {
    uint32_t w; ///< Word access
    p64h_ras_app_mem_struc_t app_mem_struc; ///< app_mem structure IDs
    p64h_ras_app_noc_struc_t app_noc_struc; ///< app_noc structure IDs
    p64h_ras_app_x288_struc_t app_x288_struc; ///< app_x288 structure IDs
    p64h_ras_clock_struc_t clock_struc; ///< clock structure IDs
    p64h_ras_nvm_struc_t nvm_struc; ///< nvm structure IDs
    p64h_ras_sec_struc_t sec_struc; ///< sec structure IDs
    p64h_ras_sys_struc_t sys_struc; ///< sys structure IDs
} p64h_ras_generic_struc_id_t;

/**
 * @brief Definitions of all errors within a structure of the APP_MEM GHES
 */
typedef enum {
    APP_MEM_OCR_0 = 0, ///< Instance 0 of strucutre ocr
    APP_MEM_OCR_1, ///< Instance 1 of strucutre ocr
    APP_MEM_OCR_INST_LAST, ///< Number of possible instances within the OCR structure of the APP_MEM GH
} p64h_ras_app_mem_ocr_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_NOC GHES
 */
typedef enum {
    APP_NOC_WGC_DDR_CFG_WG_ERR = 0, ///< Instance ddr_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_DDR_ENCRYPT_HP_CSR_WG_ERR, ///< Instance ddr_encrypt_hp_csr_wg_err of strucutre wgc
    APP_NOC_WGC_DDR_ENCRYPT_T_WG_ERR, ///< Instance ddr_encrypt_t_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_EP_CFG_WG_ERR, ///< Instance enet_ep_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_SWR_RDMA1_MCHP_CFG_WG_ERR, ///< Instance enet_swr_rdma1_mchp_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_SWR_RDMA1_ROCE_COMMAND_WG_ERR, ///< Instance enet_swr_rdma1_roce_command_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_SWR_RDMA2_MCHP_CFG_WG_ERR, ///< Instance enet_swr_rdma2_mchp_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_SWR_RDMA2_ROCE_COMMAND_WG_ERR, ///< Instance enet_swr_rdma2_roce_command_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_SWR_SWITCH_CFG_WG_ERR, ///< Instance enet_swr_switch_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_ENET_SWR_TOP_CFG_WG_ERR, ///< Instance enet_swr_top_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_IOMMU_0_CFG_WG_ERR, ///< Instance iommu_0_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_IOMMU_1_CFG_WG_ERR, ///< Instance iommu_1_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_IOMMU_SS_CFG_WG_ERR, ///< Instance iommu_ss_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_M2_HP_SPW_CSR_WG_ERR, ///< Instance m2_hp_spw_csr_wg_err of strucutre wgc
    APP_NOC_WGC_M2_JTAG_SPI_WG_ERR, ///< Instance m2_jtag_spi_wg_err of strucutre wgc
    APP_NOC_WGC_M2_OTHER_0_WG_ERR, ///< Instance m2_other_0_wg_err of strucutre wgc
    APP_NOC_WGC_M2_OTHER_1_WG_ERR, ///< Instance m2_other_1_wg_err of strucutre wgc
    APP_NOC_WGC_M3_APPDMA0_HP_CSR_WG_ERR, ///< Instance m3_appdma0_hp_csr_wg_err of strucutre wgc
    APP_NOC_WGC_M3_APPDMA1_HP_CSR_WG_ERR, ///< Instance m3_appdma1_hp_csr_wg_err of strucutre wgc
    APP_NOC_WGC_M3_IPC_0_WG_ERR, ///< Instance m3_ipc_0_wg_err of strucutre wgc
    APP_NOC_WGC_M3_IPC_1_WG_ERR, ///< Instance m3_ipc_1_wg_err of strucutre wgc
    APP_NOC_WGC_M3_NMRA0_T_WG_ERR, ///< Instance m3_nmra0_t_wg_err of strucutre wgc
    APP_NOC_WGC_M3_NMRA1_T_WG_ERR, ///< Instance m3_nmra1_t_wg_err of strucutre wgc
    APP_NOC_WGC_M3_OCR0_MEM_WG_ERR, ///< Instance m3_ocr0_mem_wg_err of strucutre wgc
    APP_NOC_WGC_M3_OCR1_MEM_WG_ERR, ///< Instance m3_ocr1_mem_wg_err of strucutre wgc
    APP_NOC_WGC_M3_OTHER_WG_ERR, ///< Instance m3_other_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_EDAC0_WG_ERR, ///< Instance nvm_edac0_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_EDAC1_WG_ERR, ///< Instance nvm_edac1_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SRAM_EDAC0_0_WG_ERR, ///< Instance nvm_sram_edac0_0_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SRAM_EDAC0_1_WG_ERR, ///< Instance nvm_sram_edac0_1_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SRAM_EDAC1_0_WG_ERR, ///< Instance nvm_sram_edac1_0_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SRAM_EDAC1_1_WG_ERR, ///< Instance nvm_sram_edac1_1_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SRAM_EDAC2_0_WG_ERR, ///< Instance nvm_sram_edac2_0_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SRAM_EDAC2_1_WG_ERR, ///< Instance nvm_sram_edac2_1_wg_err of strucutre wgc
    APP_NOC_WGC_NVM_SS_CFG_WG_ERR, ///< Instance nvm_ss_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_PCIE0_CFG_WG_ERR, ///< Instance pcie0_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_PCIE0_CTL0_T_WG_ERR, ///< Instance pcie0_ctl0_t_wg_err of strucutre wgc
    APP_NOC_WGC_PCIE0_CTL1_T_WG_ERR, ///< Instance pcie0_ctl1_t_wg_err of strucutre wgc
    APP_NOC_WGC_PCIE1_CFG_WG_ERR, ///< Instance pcie1_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_PCIE1_CTL0_T_WG_ERR, ///< Instance pcie1_ctl0_t_wg_err of strucutre wgc
    APP_NOC_WGC_PCIE1_CTL1_T_WG_ERR, ///< Instance pcie1_ctl1_t_wg_err of strucutre wgc
    APP_NOC_WGC_SVC_NOC_EDAC_WG_ERR, ///< Instance svc_noc_edac_wg_err of strucutre wgc
    APP_NOC_WGC_USER_CRYPTO_CFG_WG_ERR, ///< Instance user_crypto_cfg_wg_err of strucutre wgc
    APP_NOC_WGC_USER_CRYPTO_T_WG_ERR, ///< Instance user_crypto_t_wg_err of strucutre wgc
    APP_NOC_WGC_WG_ERR_0, ///< Instance wg_err_0 of strucutre wgc
    APP_NOC_WGC_WG_ERR_1, ///< Instance wg_err_1 of strucutre wgc
    APP_NOC_WGC_WG_ERR_2, ///< Instance wg_err_2 of strucutre wgc
    APP_NOC_WGC_WG_ERR_3, ///< Instance wg_err_3 of strucutre wgc
    APP_NOC_WGC_WG_WID_DED, ///< Instance wg_wid_ded of strucutre wgc
    APP_NOC_WGC_WG_WID_SEC, ///< Instance wg_wid_sec of strucutre wgc
    APP_NOC_WGC_INST_LAST, ///< Number of possible instances within the WGC structure of the APP_NOC GH
} p64h_ras_app_noc_wgc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_FABRIC_0 = 0, ///< Instance 0 of strucutre fabric
    APP_X288_FABRIC_1, ///< Instance 1 of strucutre fabric
    APP_X288_FABRIC_INST_LAST, ///< Number of possible instances within the FABRIC structure of the APP_X288 GH
} p64h_ras_app_x288_fabric_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_IOMMU_IOMMU_0 = 0, ///< Instance iommu_0 of strucutre iommu
    APP_X288_IOMMU_IOMMU_1, ///< Instance iommu_1 of strucutre iommu
    APP_X288_IOMMU_INST_LAST, ///< Number of possible instances within the IOMMU structure of the APP_X288 GH
} p64h_ras_app_x288_iommu_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_LOCKSTEP_0 = 0, ///< Instance 0 of strucutre lockstep
    APP_X288_LOCKSTEP_1, ///< Instance 1 of strucutre lockstep
    APP_X288_LOCKSTEP_2, ///< Instance 2 of strucutre lockstep
    APP_X288_LOCKSTEP_3, ///< Instance 3 of strucutre lockstep
    APP_X288_LOCKSTEP_INST_LAST, ///< Number of possible instances within the LOCKSTEP structure of the APP_X288 GH
} p64h_ras_app_x288_lockstep_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_TILE_0 = 0, ///< Instance 0 of strucutre tile
    APP_X288_TILE_1, ///< Instance 1 of strucutre tile
    APP_X288_TILE_2, ///< Instance 2 of strucutre tile
    APP_X288_TILE_3, ///< Instance 3 of strucutre tile
    APP_X288_TILE_4, ///< Instance 4 of strucutre tile
    APP_X288_TILE_5, ///< Instance 5 of strucutre tile
    APP_X288_TILE_6, ///< Instance 6 of strucutre tile
    APP_X288_TILE_7, ///< Instance 7 of strucutre tile
    APP_X288_TILE_INST_LAST, ///< Number of possible instances within the TILE structure of the APP_X288 GH
} p64h_ras_app_x288_tile_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_WGC_APLIC_C0 = 0, ///< Instance aplic_c0 of strucutre wgc
    APP_X288_WGC_APLIC_C1, ///< Instance aplic_c1 of strucutre wgc
    APP_X288_WGC_CLINT_C0, ///< Instance clint_c0 of strucutre wgc
    APP_X288_WGC_CLINT_C1, ///< Instance clint_c1 of strucutre wgc
    APP_X288_WGC_CXL_CACHE_CPI_C0, ///< Instance cxl_cache_cpi_c0 of strucutre wgc
    APP_X288_WGC_CXL_CACHE_CPI_C1, ///< Instance cxl_cache_cpi_c1 of strucutre wgc
    APP_X288_WGC_CXL_CACHE_TL2C_BRIDGE_C0, ///< Instance cxl_cache_tl2c_bridge_c0 of strucutre wgc
    APP_X288_WGC_CXL_CACHE_TL2C_BRIDGE_C1, ///< Instance cxl_cache_tl2c_bridge_c1 of strucutre wgc
    APP_X288_WGC_CXL_MEM_CPI_0_C0, ///< Instance cxl_mem_cpi_0_c0 of strucutre wgc
    APP_X288_WGC_CXL_MEM_CPI_0_C1, ///< Instance cxl_mem_cpi_0_c1 of strucutre wgc
    APP_X288_WGC_CXL_MEM_CPI_1_C0, ///< Instance cxl_mem_cpi_1_c0 of strucutre wgc
    APP_X288_WGC_CXL_MEM_CPI_1_C1, ///< Instance cxl_mem_cpi_1_c1 of strucutre wgc
    APP_X288_WGC_CXL_MEM_CPI_C0, ///< Instance cxl_mem_cpi_c0 of strucutre wgc
    APP_X288_WGC_CXL_MEM_CPI_C1, ///< Instance cxl_mem_cpi_c1 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_0_C0, ///< Instance ext_cache_slice_0_c0 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_0_C1, ///< Instance ext_cache_slice_0_c1 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_1_C0, ///< Instance ext_cache_slice_1_c0 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_1_C1, ///< Instance ext_cache_slice_1_c1 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_2_C0, ///< Instance ext_cache_slice_2_c0 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_2_C1, ///< Instance ext_cache_slice_2_c1 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_3_C0, ///< Instance ext_cache_slice_3_c0 of strucutre wgc
    APP_X288_WGC_EXT_CACHE_SLICE_3_C1, ///< Instance ext_cache_slice_3_c1 of strucutre wgc
    APP_X288_WGC_FP_CACHE_C0, ///< Instance fp_cache_c0 of strucutre wgc
    APP_X288_WGC_FP_CACHE_C1, ///< Instance fp_cache_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_M_0_C0, ///< Instance imsic_m_0_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_M_0_C1, ///< Instance imsic_m_0_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_M_1_C0, ///< Instance imsic_m_1_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_M_1_C1, ///< Instance imsic_m_1_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_M_2_C0, ///< Instance imsic_m_2_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_M_2_C1, ///< Instance imsic_m_2_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_M_3_C0, ///< Instance imsic_m_3_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_M_3_C1, ///< Instance imsic_m_3_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_S_0_C0, ///< Instance imsic_s_0_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_S_0_C1, ///< Instance imsic_s_0_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_S_1_C0, ///< Instance imsic_s_1_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_S_1_C1, ///< Instance imsic_s_1_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_S_2_C0, ///< Instance imsic_s_2_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_S_2_C1, ///< Instance imsic_s_2_c1 of strucutre wgc
    APP_X288_WGC_IMSIC_S_3_C0, ///< Instance imsic_s_3_c0 of strucutre wgc
    APP_X288_WGC_IMSIC_S_3_C1, ///< Instance imsic_s_3_c1 of strucutre wgc
    APP_X288_WGC_MEM_DEINTER_ERROR_BANK_C0, ///< Instance mem_deinter_error_bank_c0 of strucutre wgc
    APP_X288_WGC_MEM_DEINTER_ERROR_BANK_C1, ///< Instance mem_deinter_error_bank_c1 of strucutre wgc
    APP_X288_WGC_ROOT_ERROR_MAP_C0, ///< Instance root_error_map_c0 of strucutre wgc
    APP_X288_WGC_ROOT_ERROR_MAP_C1, ///< Instance root_error_map_c1 of strucutre wgc
    APP_X288_WGC_SMC_C0, ///< Instance smc_c0 of strucutre wgc
    APP_X288_WGC_SMC_C1, ///< Instance smc_c1 of strucutre wgc
    APP_X288_WGC_SYS_DEINTER_ERROR_BANK_C0, ///< Instance sys_deinter_error_bank_c0 of strucutre wgc
    APP_X288_WGC_SYS_DEINTER_ERROR_BANK_C1, ///< Instance sys_deinter_error_bank_c1 of strucutre wgc
    APP_X288_WGC_TEST_INDICATOR_C0, ///< Instance test_indicator_c0 of strucutre wgc
    APP_X288_WGC_TEST_INDICATOR_C1, ///< Instance test_indicator_c1 of strucutre wgc
    APP_X288_WGC_TILE_0_C0, ///< Instance tile_0_c0 of strucutre wgc
    APP_X288_WGC_TILE_0_C1, ///< Instance tile_0_c1 of strucutre wgc
    APP_X288_WGC_TILE_1_C0, ///< Instance tile_1_c0 of strucutre wgc
    APP_X288_WGC_TILE_1_C1, ///< Instance tile_1_c1 of strucutre wgc
    APP_X288_WGC_TILE_2_C0, ///< Instance tile_2_c0 of strucutre wgc
    APP_X288_WGC_TILE_2_C1, ///< Instance tile_2_c1 of strucutre wgc
    APP_X288_WGC_TILE_3_C0, ///< Instance tile_3_c0 of strucutre wgc
    APP_X288_WGC_TILE_3_C1, ///< Instance tile_3_c1 of strucutre wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_0_C0, ///< Instance tl2c_cxl_mem_bridge_0_c0 of strucutre wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_0_C1, ///< Instance tl2c_cxl_mem_bridge_0_c1 of strucutre wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_1_C0, ///< Instance tl2c_cxl_mem_bridge_1_c0 of strucutre wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_1_C1, ///< Instance tl2c_cxl_mem_bridge_1_c1 of strucutre wgc
    APP_X288_WGC_TMC_0_C0, ///< Instance tmc_0_c0 of strucutre wgc
    APP_X288_WGC_TMC_0_C1, ///< Instance tmc_0_c1 of strucutre wgc
    APP_X288_WGC_TMC_1_C0, ///< Instance tmc_1_c0 of strucutre wgc
    APP_X288_WGC_TMC_1_C1, ///< Instance tmc_1_c1 of strucutre wgc
    APP_X288_WGC_TMC_2_C0, ///< Instance tmc_2_c0 of strucutre wgc
    APP_X288_WGC_TMC_2_C1, ///< Instance tmc_2_c1 of strucutre wgc
    APP_X288_WGC_TMC_3_C0, ///< Instance tmc_3_c0 of strucutre wgc
    APP_X288_WGC_TMC_3_C1, ///< Instance tmc_3_c1 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_0_C0, ///< Instance trace_encoder_0_c0 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_0_C1, ///< Instance trace_encoder_0_c1 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_1_C0, ///< Instance trace_encoder_1_c0 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_1_C1, ///< Instance trace_encoder_1_c1 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_2_C0, ///< Instance trace_encoder_2_c0 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_2_C1, ///< Instance trace_encoder_2_c1 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_3_C0, ///< Instance trace_encoder_3_c0 of strucutre wgc
    APP_X288_WGC_TRACE_ENCODER_3_C1, ///< Instance trace_encoder_3_c1 of strucutre wgc
    APP_X288_WGC_TRACE_FUNNEL_0_C0, ///< Instance trace_funnel_0_c0 of strucutre wgc
    APP_X288_WGC_TRACE_FUNNEL_0_C1, ///< Instance trace_funnel_0_c1 of strucutre wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_0_C0, ///< Instance write_comb_buffer_0_c0 of strucutre wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_0_C1, ///< Instance write_comb_buffer_0_c1 of strucutre wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_1_C0, ///< Instance write_comb_buffer_1_c0 of strucutre wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_1_C1, ///< Instance write_comb_buffer_1_c1 of strucutre wgc
    APP_X288_WGC_INST_LAST, ///< Number of possible instances within the WGC structure of the APP_X288 GH
} p64h_ras_app_x288_wgc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the CLOCK GHES
 */
typedef enum {
    CLOCK_CSU_APP = 0, ///< Instance app of strucutre csu
    CLOCK_CSU_CPU, ///< Instance cpu of strucutre csu
    CLOCK_CSU_EDAC, ///< Instance edac of strucutre csu
    CLOCK_CSU_ENET, ///< Instance enet of strucutre csu
    CLOCK_CSU_NVM0, ///< Instance nvm0 of strucutre csu
    CLOCK_CSU_NVM1, ///< Instance nvm1 of strucutre csu
    CLOCK_CSU_SYS0, ///< Instance sys0 of strucutre csu
    CLOCK_CSU_SYS1, ///< Instance sys1 of strucutre csu
    CLOCK_CSU_SYSC, ///< Instance sysc of strucutre csu
    CLOCK_CSU_INST_LAST, ///< Number of possible instances within the CSU structure of the CLOCK GH
} p64h_ras_clock_csu_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_NVM_EDAC_0 = 0, ///< Instance 0 of strucutre nvm_edac
    NVM_NVM_EDAC_1, ///< Instance 1 of strucutre nvm_edac
    NVM_NVM_EDAC_INST_LAST, ///< Number of possible instances within the NVM_EDAC structure of the NVM GH
} p64h_ras_nvm_nvm_edac_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_SRAM_EDAC_0 = 0, ///< Instance 0 of strucutre sram_edac
    NVM_SRAM_EDAC_1, ///< Instance 1 of strucutre sram_edac
    NVM_SRAM_EDAC_2, ///< Instance 2 of strucutre sram_edac
    NVM_SRAM_EDAC_INST_LAST, ///< Number of possible instances within the SRAM_EDAC structure of the NVM GH
} p64h_ras_nvm_sram_edac_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_ANA_MON_0 = 0, ///< Instance 0 of strucutre ana_mon
    SEC_ANA_MON_INST_LAST, ///< Number of possible instances within the ANA_MON structure of the SEC GH
} p64h_ras_sec_ana_mon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_APB2JTAG_0 = 0, ///< Instance 0 of strucutre apb2jtag
    SEC_APB2JTAG_INST_LAST, ///< Number of possible instances within the APB2JTAG structure of the SEC GH
} p64h_ras_sec_apb2jtag_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_CMON_0 = 0, ///< Instance 0 of strucutre cmon
    SEC_CMON_INST_LAST, ///< Number of possible instances within the CMON structure of the SEC GH
} p64h_ras_sec_cmon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_CSU_APP = 0, ///< Instance app of strucutre csu
    SEC_CSU_INST_LAST, ///< Number of possible instances within the CSU structure of the SEC GH
} p64h_ras_sec_csu_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_DMA_0 = 0, ///< Instance 0 of strucutre dma
    SEC_DMA_INST_LAST, ///< Number of possible instances within the DMA structure of the SEC GH
} p64h_ras_sec_dma_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_MESH_ANA = 0, ///< Instance ana of strucutre mesh
    SEC_MESH_DDR_ENCRYPT, ///< Instance ddr_encrypt of strucutre mesh
    SEC_MESH_SEC, ///< Instance sec of strucutre mesh
    SEC_MESH_USR_CRYPTO, ///< Instance usr_crypto of strucutre mesh
    SEC_MESH_INST_LAST, ///< Number of possible instances within the MESH structure of the SEC GH
} p64h_ras_sec_mesh_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_NOC_0 = 0, ///< Instance 0 of strucutre noc
    SEC_NOC_INST_LAST, ///< Number of possible instances within the NOC structure of the SEC GH
} p64h_ras_sec_noc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_OCR_0 = 0, ///< Instance 0 of strucutre ocr
    SEC_OCR_1, ///< Instance 1 of strucutre ocr
    SEC_OCR_2, ///< Instance 2 of strucutre ocr
    SEC_OCR_INST_LAST, ///< Number of possible instances within the OCR structure of the SEC GH
} p64h_ras_sec_ocr_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_PQS_0 = 0, ///< Instance 0 of strucutre pqs
    SEC_PQS_INST_LAST, ///< Number of possible instances within the PQS structure of the SEC GH
} p64h_ras_sec_pqs_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_RAM_BOOT_ROM = 0, ///< Instance boot_rom of strucutre ram
    SEC_RAM_DMA_CH, ///< Instance dma_ch of strucutre ram
    SEC_RAM_ECULTRA, ///< Instance ecultra of strucutre ram
    SEC_RAM_JTAG_MBOX, ///< Instance jtag_mbox of strucutre ram
    SEC_RAM_KEY_ROM, ///< Instance key_rom of strucutre ram
    SEC_RAM_KGSCRTR, ///< Instance kgscrtr of strucutre ram
    SEC_RAM_OTP, ///< Instance otp of strucutre ram
    SEC_RAM_PQCS_DSRAM, ///< Instance pqcs_dsram of strucutre ram
    SEC_RAM_PQCS_ISRAM, ///< Instance pqcs_isram of strucutre ram
    SEC_RAM_PQCS_ROM, ///< Instance pqcs_rom of strucutre ram
    SEC_RAM_S7_TRACE, ///< Instance s7_trace of strucutre ram
    SEC_RAM_SEC_MBOX, ///< Instance sec_mbox of strucutre ram
    SEC_RAM_INST_LAST, ///< Number of possible instances within the RAM structure of the SEC GH
} p64h_ras_sec_ram_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_S7_0 = 0, ///< Instance 0 of strucutre s7
    SEC_S7_INST_LAST, ///< Number of possible instances within the S7 structure of the SEC GH
} p64h_ras_sec_s7_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TAMPER_MON_0 = 0, ///< Instance 0 of strucutre tamper_mon
    SEC_TAMPER_MON_INST_LAST, ///< Number of possible instances within the TAMPER_MON structure of the SEC GH
} p64h_ras_sec_tamper_mon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TIMER_0 = 0, ///< Instance 0 of strucutre timer
    SEC_TIMER_INST_LAST, ///< Number of possible instances within the TIMER structure of the SEC GH
} p64h_ras_sec_timer_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TVS_MON_0 = 0, ///< Instance 0 of strucutre tvs_mon
    SEC_TVS_MON_INST_LAST, ///< Number of possible instances within the TVS_MON structure of the SEC GH
} p64h_ras_sec_tvs_mon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_WDOG_0 = 0, ///< Instance 0 of strucutre wdog
    SEC_WDOG_INST_LAST, ///< Number of possible instances within the WDOG structure of the SEC GH
} p64h_ras_sec_wdog_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SYS GHES
 */
typedef enum {
    SYS_OCR_0 = 0, ///< Instance 0 of strucutre ocr
    SYS_OCR_INST_LAST, ///< Number of possible instances within the OCR structure of the SYS GH
} p64h_ras_sys_ocr_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SYS GHES
 */
typedef enum {
    SYS_S7_0 = 0, ///< Instance 0 of strucutre s7
    SYS_S7_INST_LAST, ///< Number of possible instances within the S7 structure of the SYS GH
} p64h_ras_sys_s7_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_MEM GHES
 */
typedef enum {
    APP_MEM_OCR_BACK_PRESSURE_THRESHOLD_REACHED = 0, ///< Value back_pressure:threshold_reached for instance ocr of structure from APP_MEM
   APP_MEM_OCR_CORRECTED_READ, ///< Value corrected:read for instance ocr of structure from APP_MEM
   APP_MEM_OCR_CORRECTED_WRITE, ///< Value corrected:write for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_ACCESS_READ_FAILURE, ///< Value fifo_access:read_failure for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_OVERFLOW_AXI_READ, ///< Value fifo_overflow:axi_read for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_OVERFLOW_AXI_WRITE, ///< Value fifo_overflow:axi_write for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_OVERFLOW_MEL, ///< Value fifo_overflow:mel for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_OVERFLOW_SELF_SCRUB, ///< Value fifo_overflow:self_scrub for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_UNDERFLOW_AXI_READ, ///< Value fifo_underflow:axi_read for instance ocr of structure from APP_MEM
   APP_MEM_OCR_FIFO_UNDERFLOW_AXI_WRITE, ///< Value fifo_underflow:axi_write for instance ocr of structure from APP_MEM
   APP_MEM_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS, ///< Value invalid_access:unavailable_access for instance ocr of structure from APP_MEM
   APP_MEM_OCR_UNCORRECTED_READ, ///< Value uncorrected:read for instance ocr of structure from APP_MEM
   APP_MEM_OCR_UNCORRECTED_WRITE, ///< Value uncorrected:write for instance ocr of structure from APP_MEM
   APP_MEM_OCR_ERROR_LAST, ///< Last value of possible error within the APP_MEM GHES OCR structu
} p64h_ras_app_mem_ocr_err_t;

/**
 * @brief Definitions of all errors within a structure of the APP_NOC GHES
 */
typedef enum {
    APP_NOC_WGC_PERMISSION_DENIED_READ = 0, ///< Value permission_denied:read for instance wgc of structure from APP_NOC
   APP_NOC_WGC_PERMISSION_DENIED_WRITE, ///< Value permission_denied:write for instance wgc of structure from APP_NOC
   APP_NOC_WGC_ERROR_LAST, ///< Last value of possible error within the APP_NOC GHES WGC structu
} p64h_ras_app_noc_wgc_err_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_FABRIC_AXI4_DEINTERLEAVER_CORRECTED = 0, ///< Value axi4_deinterleaver:corrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_AXI4_DEINTERLEAVER_UNCORRECTED, ///< Value axi4_deinterleaver:uncorrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_CXL_CACHE_BRIDGE_CORRECTED, ///< Value cxl_cache_bridge:corrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_CXL_CACHE_BRIDGE_PRODUCE_CORRUPT, ///< Value cxl_cache_bridge:produce_corrupt for instance fabric of structure from APP_X288
   APP_X288_FABRIC_CXL_CACHE_BRIDGE_RECEIVE_CORRUPT, ///< Value cxl_cache_bridge:receive_corrupt for instance fabric of structure from APP_X288
   APP_X288_FABRIC_CXL_MEM_BRIDGE_CORRECTED, ///< Value cxl_mem_bridge:corrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_CXL_MEM_BRIDGE_PRODUCE_CORRUPT, ///< Value cxl_mem_bridge:produce_corrupt for instance fabric of structure from APP_X288
   APP_X288_FABRIC_CXL_MEM_BRIDGE_RECEIVE_CORRUPT, ///< Value cxl_mem_bridge:receive_corrupt for instance fabric of structure from APP_X288
   APP_X288_FABRIC_DLS_CORRECTED, ///< Value dls:corrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_DLS_UNCORRECTED, ///< Value dls:uncorrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L2_CACHE_CORRECTED_DATA, ///< Value l2_cache:corrected_data for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L2_CACHE_CORRECTED_TAG, ///< Value l2_cache:corrected_tag for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L2_CACHE_PRODUCE_CORRUPT, ///< Value l2_cache:produce_corrupt for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L2_CACHE_UNCORRECTED, ///< Value l2_cache:uncorrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L3_CACHE_DATA_CORRECTED, ///< Value l3_cache_data:corrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L3_CACHE_DATA_PRODUCE_CORRUPT, ///< Value l3_cache_data:produce_corrupt for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L3_CACHE_TAG_CORRECTED, ///< Value l3_cache_tag:corrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L3_CACHE_TAG_UNCORRECTED, ///< Value l3_cache_tag:uncorrected for instance fabric of structure from APP_X288
   APP_X288_FABRIC_L3_CACHE_TILELINK_DENIED, ///< Value l3_cache_tilelink:denied for instance fabric of structure from APP_X288
   APP_X288_FABRIC_ERROR_LAST, ///< Last value of possible error within the APP_X288 GHES FABRIC structu
} p64h_ras_app_x288_fabric_err_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_IOMMU_IOMMU_22_PTW_CORRECTED = 0, ///< Value iommu_22_ptw:corrected for instance iommu of structure from APP_X288
   APP_X288_IOMMU_IOMMU_L2_TLB_CORRECTED, ///< Value iommu_l2_tlb:corrected for instance iommu of structure from APP_X288
   APP_X288_IOMMU_ERROR_LAST, ///< Last value of possible error within the APP_X288 GHES IOMMU structu
} p64h_ras_app_x288_iommu_err_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_LOCKSTEP_TILE_LS_COMPARE_DIFF = 0, ///< Value tile_ls:compare_diff for instance lockstep of structure from APP_X288
   APP_X288_LOCKSTEP_TILE_LS_CONTAIN, ///< Value tile_ls:contain for instance lockstep of structure from APP_X288
   APP_X288_LOCKSTEP_TILE_LS_DIFF, ///< Value tile_ls:diff for instance lockstep of structure from APP_X288
   APP_X288_LOCKSTEP_ERROR_LAST, ///< Last value of possible error within the APP_X288 GHES LOCKSTEP structu
} p64h_ras_app_x288_lockstep_err_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_TILE_CORE_STATE_CEASE = 0, ///< Value core_state:cease for instance tile of structure from APP_X288
   APP_X288_TILE_CORE_STATE_DEBUG, ///< Value core_state:debug for instance tile of structure from APP_X288
   APP_X288_TILE_CORE_STATE_HALT, ///< Value core_state:halt for instance tile of structure from APP_X288
   APP_X288_TILE_CORE_STATE_WFI, ///< Value core_state:wfi for instance tile of structure from APP_X288
   APP_X288_TILE_GHRT_UNCORRECTED, ///< Value ghrt:uncorrected for instance tile of structure from APP_X288
   APP_X288_TILE_L1_DCACHE_CORRECTED, ///< Value l1_dcache:corrected for instance tile of structure from APP_X288
   APP_X288_TILE_L1_DCACHE_PRODUCE_CORRUPT, ///< Value l1_dcache:produce_corrupt for instance tile of structure from APP_X288
   APP_X288_TILE_L1_DCACHE_UNCORRECTED, ///< Value l1_dcache:uncorrected for instance tile of structure from APP_X288
   APP_X288_TILE_L1_DCACHE_TILELINK_CORRUPT, ///< Value l1_dcache_tilelink:corrupt for instance tile of structure from APP_X288
   APP_X288_TILE_L1_DCACHE_TILELINK_DENIED, ///< Value l1_dcache_tilelink:denied for instance tile of structure from APP_X288
   APP_X288_TILE_L1_ICACHE_CORRECTED, ///< Value l1_icache:corrected for instance tile of structure from APP_X288
   APP_X288_TILE_L1_ICACHE_NO_RECORD, ///< Value l1_icache:no_record for instance tile of structure from APP_X288
   APP_X288_TILE_L1_ICACHE_UNCORRECTED, ///< Value l1_icache:uncorrected for instance tile of structure from APP_X288
   APP_X288_TILE_L1_ICACHE_TILELINK_CORRUPT, ///< Value l1_icache_tilelink:corrupt for instance tile of structure from APP_X288
   APP_X288_TILE_L1_ICACHE_TILELINK_DENIED, ///< Value l1_icache_tilelink:denied for instance tile of structure from APP_X288
   APP_X288_TILE_L2_TLB_CORRECTED, ///< Value l2_tlb:corrected for instance tile of structure from APP_X288
   APP_X288_TILE_ERROR_LAST, ///< Last value of possible error within the APP_X288 GHES TILE structu
} p64h_ras_app_x288_tile_err_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_WGC_PERMISSION_DENIED_READ = 0, ///< Value permission_denied:read for instance wgc of structure from APP_X288
   APP_X288_WGC_PERMISSION_DENIED_WRITE, ///< Value permission_denied:write for instance wgc of structure from APP_X288
   APP_X288_WGC_ERROR_LAST, ///< Last value of possible error within the APP_X288 GHES WGC structu
} p64h_ras_app_x288_wgc_err_t;

/**
 * @brief Definitions of all errors within a structure of the CLOCK GHES
 */
typedef enum {
    CLOCK_CSU_LOCK_LOCK = 0, ///< Value lock:lock for instance csu of structure from CLOCK
   CLOCK_CSU_LOCK_LOCK_LOSS, ///< Value lock:lock_loss for instance csu of structure from CLOCK
   CLOCK_CSU_OFFSETCAL_LOCK_LOCK, ///< Value offsetcal_lock:lock for instance csu of structure from CLOCK
   CLOCK_CSU_OFFSETCAL_LOCK_LOCK_LOSS, ///< Value offsetcal_lock:lock_loss for instance csu of structure from CLOCK
   CLOCK_CSU_ERROR_LAST, ///< Last value of possible error within the CLOCK GHES CSU structu
} p64h_ras_clock_csu_err_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_NVM_EDAC_BUS_ECC_CORRECTED_BCH_ENC_BUS_ECC_COR = 0, ///< Value bus_ecc_corrected:bch_enc_bus_ecc_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AR_A, ///< Value bus_ecc_corrected:nvm_ctrl_s_0_cor_ar_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AR_C, ///< Value bus_ecc_corrected:nvm_ctrl_s_0_cor_ar_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AW_A, ///< Value bus_ecc_corrected:nvm_ctrl_s_0_cor_aw_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AW_C, ///< Value bus_ecc_corrected:nvm_ctrl_s_0_cor_aw_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_B, ///< Value bus_ecc_corrected:nvm_ctrl_s_0_cor_b for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_R, ///< Value bus_ecc_corrected:nvm_ctrl_s_0_cor_r for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AR_A_PAR, ///< Value bus_ecc_corrected:ram_cor_err_ar_a_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AR_C_PAR, ///< Value bus_ecc_corrected:ram_cor_err_ar_c_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AW_A_PAR, ///< Value bus_ecc_corrected:ram_cor_err_aw_a_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AW_C_PAR, ///< Value bus_ecc_corrected:ram_cor_err_aw_c_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_W_PAR, ///< Value bus_ecc_corrected:ram_cor_err_w_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_WDATA_PAR, ///< Value bus_ecc_corrected:ram_cor_err_wdata_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RDCAP_BUS_ECC_COR, ///< Value bus_ecc_corrected:rdcap_bus_ecc_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_RDGEN_BUS_ECC_COR, ///< Value bus_ecc_corrected:rdgen_bus_ecc_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_SECDED_ENC_BUS_ECC_COR, ///< Value bus_ecc_corrected:secded_enc_bus_ecc_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_CORRECTED_WDRESP_BUS_ECC_COR, ///< Value bus_ecc_corrected:wdresp_bus_ecc_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_BCH_ENC_BUS_ECC_UNCOR, ///< Value bus_ecc_uncorrected:bch_enc_bus_ecc_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AR_A, ///< Value bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_ar_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AR_C, ///< Value bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_ar_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AW_A, ///< Value bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_aw_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AW_C, ///< Value bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_aw_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_B, ///< Value bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_b for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_R, ///< Value bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_r for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AR_A_PAR, ///< Value bus_ecc_uncorrected:ram_uncor_err_ar_a_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AR_C_PAR, ///< Value bus_ecc_uncorrected:ram_uncor_err_ar_c_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AW_A_PAR, ///< Value bus_ecc_uncorrected:ram_uncor_err_aw_a_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AW_C_PAR, ///< Value bus_ecc_uncorrected:ram_uncor_err_aw_c_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_W_PAR, ///< Value bus_ecc_uncorrected:ram_uncor_err_w_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_WDATA_PAR, ///< Value bus_ecc_uncorrected:ram_uncor_err_wdata_par for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RDCAP_BUS_ECC_UNCOR, ///< Value bus_ecc_uncorrected:rdcap_bus_ecc_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RDGEN_BUS_ECC_UNCOR, ///< Value bus_ecc_uncorrected:rdgen_bus_ecc_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_SECDED_ENC_BUS_ECC_UNCOR, ///< Value bus_ecc_uncorrected:secded_enc_bus_ecc_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_WDRESP_BUS_ECC_UNCOR, ///< Value bus_ecc_uncorrected:wdresp_bus_ecc_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_M_COR_AR_A, ///< Value dmr_corrected:app_noc_m_cor_ar_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_M_COR_AW_A, ///< Value dmr_corrected:app_noc_m_cor_aw_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AR_A, ///< Value dmr_corrected:app_noc_s_cor_ar_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AR_C, ///< Value dmr_corrected:app_noc_s_cor_ar_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AW_A, ///< Value dmr_corrected:app_noc_s_cor_aw_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AW_C, ///< Value dmr_corrected:app_noc_s_cor_aw_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_B, ///< Value dmr_corrected:app_noc_s_cor_b for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_R, ///< Value dmr_corrected:app_noc_s_cor_r for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_DMR_N0_COR, ///< Value dmr_corrected:dmr_n0_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_CORRECTED_DMR_N1_COR, ///< Value dmr_corrected:dmr_n1_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_M_UNCOR_AR_A, ///< Value dmr_uncorrected:app_noc_m_uncor_ar_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_M_UNCOR_AW_A, ///< Value dmr_uncorrected:app_noc_m_uncor_aw_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AR_A, ///< Value dmr_uncorrected:app_noc_s_uncor_ar_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AR_C, ///< Value dmr_uncorrected:app_noc_s_uncor_ar_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AW_A, ///< Value dmr_uncorrected:app_noc_s_uncor_aw_a for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AW_C, ///< Value dmr_uncorrected:app_noc_s_uncor_aw_c for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_B, ///< Value dmr_uncorrected:app_noc_s_uncor_b for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_R, ///< Value dmr_uncorrected:app_noc_s_uncor_r for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_N0_UNCOR, ///< Value dmr_uncorrected:dmr_n0_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_N1_UNCOR, ///< Value dmr_uncorrected:dmr_n1_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_NDCS_UNCOR, ///< Value dmr_uncorrected:dmr_ndcs_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD0_COR, ///< Value ecc_corrected:thrd0_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD1_COR, ///< Value ecc_corrected:thrd1_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD2_COR, ///< Value ecc_corrected:thrd2_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD3_COR, ///< Value ecc_corrected:thrd3_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD4_COR, ///< Value ecc_corrected:thrd4_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD5_COR, ///< Value ecc_corrected:thrd5_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD6_COR, ///< Value ecc_corrected:thrd6_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_CORRECTED_THRD7_COR, ///< Value ecc_corrected:thrd7_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD0_UNCOR, ///< Value ecc_uncorrected:thrd0_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD1_UNCOR, ///< Value ecc_uncorrected:thrd1_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD2_UNCOR, ///< Value ecc_uncorrected:thrd2_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD3_UNCOR, ///< Value ecc_uncorrected:thrd3_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD4_UNCOR, ///< Value ecc_uncorrected:thrd4_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD5_UNCOR, ///< Value ecc_uncorrected:thrd5_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD6_UNCOR, ///< Value ecc_uncorrected:thrd6_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ECC_UNCORRECTED_THRD7_UNCOR, ///< Value ecc_uncorrected:thrd7_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR, ///< Value emon_corrected:emon_cor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL, ///< Value emon_corrected:emon_cor_buf_full for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THRHLD, ///< Value emon_corrected:emon_cor_buf_high_thrhld for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW, ///< Value emon_corrected:emon_cor_buf_ovrflw for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_FSM_ERR, ///< Value emon_corrected:emon_fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL, ///< Value emon_corrected:emon_stat_buf_full for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW, ///< Value emon_corrected:emon_stat_buf_ovrflw for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL, ///< Value emon_corrected:emon_uncor_buf_full for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THRHLD, ///< Value emon_corrected:emon_uncor_buf_high_thrhld for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW, ///< Value emon_corrected:emon_uncor_buf_ovrflw for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_PATROL_SCRUB_COMPLETE, ///< Value emon_corrected:patrol_scrub_complete for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_CORRECTED_SCRUB_DONE, ///< Value emon_corrected:scrub_done for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_UNCORRECTED_EMON_ADDR_ERR, ///< Value emon_uncorrected:emon_addr_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_EMON_UNCORRECTED_EMON_UNCOR, ///< Value emon_uncorrected:emon_uncor for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_BUF_FSM_ERR, ///< Value fault:buf_fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_DEMAND_READ_RAM_DSCR_ERR, ///< Value fault:demand_read_ram_dscr_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_ENC_ADDR_PARITY_ERR, ///< Value fault:enc_addr_parity_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_ENC_DATA_PARITY_ERR, ///< Value fault:enc_data_parity_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_ENC_FSM_ERR, ///< Value fault:enc_fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_FSM_ERR, ///< Value fault:fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_IOB_ERR, ///< Value fault:iob_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_PAR_FSM_ERR, ///< Value fault:par_fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_PATROL_SCRUB_FSM_ERR, ///< Value fault:patrol_scrub_fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_POLL_HOST_SYNC_ERR, ///< Value fault:poll_host_sync_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_RAM_ADDR_ERR, ///< Value fault:ram_addr_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_RAM_FSM_ERR, ///< Value fault:ram_fsm_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_RAM_SIZE_ERR, ///< Value fault:ram_size_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_RAM_UNALIGN_ERR, ///< Value fault:ram_unalign_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_RAM_WSTRB_ERR, ///< Value fault:ram_wstrb_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_RD_HOST_DSCR_ERR, ///< Value fault:rd_host_dscr_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_READ_RAM_DSCR_ERR, ///< Value fault:read_ram_dscr_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_TIMEOUT_ERR, ///< Value fault:timeout_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_TRANS_BUF_CMD_ERR, ///< Value fault:trans_buf_cmd_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_TRANS_BUF_ERR, ///< Value fault:trans_buf_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_WR_DSCR_TO_HOST_ERR, ///< Value fault:wr_dscr_to_host_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_WR_DSCR_TO_RAM_ERR, ///< Value fault:wr_dscr_to_ram_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_FAULT_WRITE_RAM_SYNC_ERR, ///< Value fault:write_ram_sync_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_BUF_0_COR_ECC_ERR, ///< Value ram_corrected:buf_0_cor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_BUF_1_COR_ECC_ERR, ///< Value ram_corrected:buf_1_cor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_DEC_DATA_RAM_COR_ERR, ///< Value ram_corrected:dec_data_ram_cor_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_ECC_COR_ERR, ///< Value ram_corrected:ecc_cor_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_EMON_COR_RAM_COR_ECC_ERR, ///< Value ram_corrected:emon_cor_ram_cor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_EMON_STAT_RAM_COR_ECC_ERR, ///< Value ram_corrected:emon_stat_ram_cor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_EMON_UNCOR_RAM_COR_ECC_ERR, ///< Value ram_corrected:emon_uncor_ram_cor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_CORRECTED_ENC_DATA_RAM_COR_ECC_ERR, ///< Value ram_corrected:enc_data_ram_cor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_BUF_0_UNCOR_ECC_ERR, ///< Value ram_uncorrected:buf_0_uncor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_BUF_1_UNCOR_ECC_ERR, ///< Value ram_uncorrected:buf_1_uncor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCOR_ERR, ///< Value ram_uncorrected:dec_data_ram_uncor_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_ECC_UNCOR_ERR, ///< Value ram_uncorrected:ecc_uncor_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_COR_RAM_UNCOR_ECC_ERR, ///< Value ram_uncorrected:emon_cor_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_STAT_RAM_UNCOR_ECC_ERR, ///< Value ram_uncorrected:emon_stat_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_UNCOR_RAM_UNCOR_ECC_ERR, ///< Value ram_uncorrected:emon_uncor_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_RAM_UNCORRECTED_ENC_DATA_RAM_UNCOR_ECC_ERR, ///< Value ram_uncorrected:enc_data_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_READ_TIMEOUT_RAM_DROP_READ_TRANS, ///< Value read_timeout:ram_drop_read_trans for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_READ_TIMEOUT_RAM_RDATA_TIMEOUT, ///< Value read_timeout:ram_rdata_timeout for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_BRESP_TIMEOUT, ///< Value write_timeout:ram_bresp_timeout for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_DROP_WRITE_TRANS, ///< Value write_timeout:ram_drop_write_trans for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_NULL_WRITE_TRANS, ///< Value write_timeout:ram_null_write_trans for instance nvm_edac of structure from NVM
   NVM_NVM_EDAC_ERROR_LAST, ///< Last value of possible error within the NVM GHES NVM_EDAC structu
} p64h_ras_nvm_nvm_edac_err_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_SRAM_EDAC_APP_BIST_DATA_ERROR = 0, ///< Value app:bist_data_error for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_FINISHED, ///< Value app:bist_finished for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_PARITY_ERROR, ///< Value app:bist_parity_error for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_TBL_0_CORRECTABLE, ///< Value app:bist_tbl_0_correctable for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_TBL_0_UNCORRECTABLE, ///< Value app:bist_tbl_0_uncorrectable for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_TBL_1_CORRECTABLE, ///< Value app:bist_tbl_1_correctable for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_TBL_1_UNCORRECTABLE, ///< Value app:bist_tbl_1_uncorrectable for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_TBL_2_CORRECTABLE, ///< Value app:bist_tbl_2_correctable for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_BIST_TBL_2_UNCORRECTABLE, ///< Value app:bist_tbl_2_uncorrectable for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_APP_PATROL_SCRUB_COMPLETE, ///< Value app:patrol_scrub_complete for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_BRESP_SEL, ///< Value dmr_corrected:dmr_s0_bresp_sel for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_CORR, ///< Value dmr_corrected:dmr_s0_corr for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_DROP_BRESP, ///< Value dmr_corrected:dmr_s0_drop_bresp for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_DROP_R, ///< Value dmr_corrected:dmr_s0_drop_r for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_RDATA_SEL, ///< Value dmr_corrected:dmr_s0_rdata_sel for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_BRESP_SEL, ///< Value dmr_corrected:dmr_s1_bresp_sel for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_CORR, ///< Value dmr_corrected:dmr_s1_corr for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_DROP_BRESP, ///< Value dmr_corrected:dmr_s1_drop_bresp for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_DROP_R, ///< Value dmr_corrected:dmr_s1_drop_r for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_RDATA_SEL, ///< Value dmr_corrected:dmr_s1_rdata_sel for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S_RPARITY, ///< Value dmr_corrected:dmr_s_rparity for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_CORRECTED_DMR_SUBS_MM_STATUS, ///< Value dmr_corrected:dmr_subs_mm_status for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_BID, ///< Value dmr_uncorrected:dmr_mm_bid for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_BRESP, ///< Value dmr_uncorrected:dmr_mm_bresp for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_EXOKAY, ///< Value dmr_uncorrected:dmr_mm_exokay for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RDATA, ///< Value dmr_uncorrected:dmr_mm_rdata for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RID, ///< Value dmr_uncorrected:dmr_mm_rid for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RRESP, ///< Value dmr_uncorrected:dmr_mm_rresp for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S0_STUCK, ///< Value dmr_uncorrected:dmr_s0_stuck for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S0_UNCORR, ///< Value dmr_uncorrected:dmr_s0_uncorr for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S1_STUCK, ///< Value dmr_uncorrected:dmr_s1_stuck for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S1_UNCORR, ///< Value dmr_uncorrected:dmr_s1_uncorr for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_SUBS_UNCORR, ///< Value dmr_uncorrected:dmr_subs_uncorr for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR, ///< Value emon_corrected:emon_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL, ///< Value emon_corrected:emon_cor_buf_full for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THLD, ///< Value emon_corrected:emon_cor_buf_high_thld for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW, ///< Value emon_corrected:emon_cor_buf_ovrflw for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_FSM_ERR, ///< Value emon_corrected:emon_fsm_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL, ///< Value emon_corrected:emon_stat_buf_full for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW, ///< Value emon_corrected:emon_stat_buf_ovrflw for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL, ///< Value emon_corrected:emon_uncor_buf_full for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THLD, ///< Value emon_corrected:emon_uncor_buf_high_thld for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW, ///< Value emon_corrected:emon_uncor_buf_ovrflw for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_UNCORRECTED_EMON_ADDR_ERR, ///< Value emon_uncorrected:emon_addr_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_EMON_UNCORRECTED_EMON_UNCOR, ///< Value emon_uncorrected:emon_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_ENC_ADDR_PARITY_ERR, ///< Value fault:enc_addr_parity_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_ENC_DATA_PARITY_ERR, ///< Value fault:enc_data_parity_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_ENC_FSM_ERR, ///< Value fault:enc_fsm_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_ERR_REMOVE_READ_COH, ///< Value fault:err_remove_read_coh for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_ERR_REMOVE_WRITE_COH, ///< Value fault:err_remove_write_coh for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_PATROL_SCRUB_FSM_ERR, ///< Value fault:patrol_scrub_fsm_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RARB_ERR, ///< Value fault:rarb_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RDCAP_CTX_OVERFLOW, ///< Value fault:rdcap_ctx_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RDCAP_CTX_UNDERFLOW, ///< Value fault:rdcap_ctx_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RDGEN_CTX_OVERFLOW, ///< Value fault:rdgen_ctx_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RDGEN_CTX_UNDERFLOW, ///< Value fault:rdgen_ctx_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RMW_CTX_OVERFLOW, ///< Value fault:rmw_ctx_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RMW_CTX_UNDERFLOW, ///< Value fault:rmw_ctx_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RMW_RDCAP_OVERFLOW, ///< Value fault:rmw_rdcap_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_RMW_RDCAP_UNDERFLOW, ///< Value fault:rmw_rdcap_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WARB_ERR, ///< Value fault:warb_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDCAP_CTX_OVERFLOW, ///< Value fault:wdcap_ctx_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDCAP_CTX_UNDERFLOW, ///< Value fault:wdcap_ctx_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDCAP_OVERFLOW, ///< Value fault:wdcap_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDCAP_UNDERFLOW, ///< Value fault:wdcap_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDGEN_CTX_OVERFLOW, ///< Value fault:wdgen_ctx_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDGEN_CTX_UNDERFLOW, ///< Value fault:wdgen_ctx_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDRESP_CTX_OVERFLOW, ///< Value fault:wdresp_ctx_overflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_WDRESP_CTX_UNDERFLOW, ///< Value fault:wdresp_ctx_underflow for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_BCH_ENC_BUS_ECC_COR, ///< Value fault_corrected:bch_enc_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_RCMD_BUS_ECC_COR, ///< Value fault_corrected:rcmd_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_RDCAP_BUS_ECC_COR, ///< Value fault_corrected:rdcap_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_SECDED_ENC_BUS_ECC_COR, ///< Value fault_corrected:secded_enc_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_WCMD_CAP_BUS_ECC_COR, ///< Value fault_corrected:wcmd_cap_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_WCMD_GEN_BUS_ECC_COR, ///< Value fault_corrected:wcmd_gen_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_WDCAP_BUS_ECC_COR, ///< Value fault_corrected:wdcap_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_WDGEN_BUS_ECC_COR, ///< Value fault_corrected:wdgen_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_FAULT_CORRECTED_WDRESP_BUS_ECC_COR, ///< Value fault_corrected:wdresp_bus_ecc_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_DEC_DATA_RAM_COR_ERR, ///< Value ram_corrected:dec_data_ram_cor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_EMON_COR_RAM_COR, ///< Value ram_corrected:emon_cor_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_EMON_STAT_RAM_COR, ///< Value ram_corrected:emon_stat_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_EMON_UNCOR_RAM_COR, ///< Value ram_corrected:emon_uncor_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_ENC_DATA_RAM_COR_ERR, ///< Value ram_corrected:enc_data_ram_cor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_RDCAP_CTX_RAM_COR, ///< Value ram_corrected:rdcap_ctx_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_RMW_CTX_RAM_COR, ///< Value ram_corrected:rmw_ctx_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_RMW_DATA_RAM_COR, ///< Value ram_corrected:rmw_data_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_WDCAP_CTX_RAM_COR, ///< Value ram_corrected:wdcap_ctx_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_WDGEN_CTX_RAM_COR, ///< Value ram_corrected:wdgen_ctx_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_CORRECTED_WDRESP_CTX_RAM_COR, ///< Value ram_corrected:wdresp_ctx_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCOR_ERR, ///< Value ram_uncorrected:dec_data_ram_uncor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_COR_RAM_UNCOR_ERR, ///< Value ram_uncorrected:emon_cor_ram_uncor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_STAT_RAM_UNCOR_ERR, ///< Value ram_uncorrected:emon_stat_ram_uncor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_UNCOR_RAM_UNCOR_ERR, ///< Value ram_uncorrected:emon_uncor_ram_uncor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_ENC_DATA_RAM_UNCOR_ERR, ///< Value ram_uncorrected:enc_data_ram_uncor_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_RDCAP_CTX_RAM_UNCOR, ///< Value ram_uncorrected:rdcap_ctx_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_RDGEN_CTX_RAM_COR, ///< Value ram_uncorrected:rdgen_ctx_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_RDGEN_CTX_RAM_UNCOR, ///< Value ram_uncorrected:rdgen_ctx_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_RMW_CTX_RAM_UNCOR, ///< Value ram_uncorrected:rmw_ctx_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_RMW_DATA_RAM_UNCOR, ///< Value ram_uncorrected:rmw_data_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_CTX_RAM_UNCOR, ///< Value ram_uncorrected:wdcap_ctx_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_DATA_RAM_COR, ///< Value ram_uncorrected:wdcap_data_ram_cor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_DATA_RAM_UNCOR, ///< Value ram_uncorrected:wdcap_data_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_WDGEN_CTX_RAM_UNCOR, ///< Value ram_uncorrected:wdgen_ctx_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_RAM_UNCORRECTED_WDRESP_CTX_RAM_UNCOR, ///< Value ram_uncorrected:wdresp_ctx_ram_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_READ_TIMEOUT_RCMD_TIMEOUT, ///< Value read_timeout:rcmd_timeout for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_READ_TIMEOUT_RDCAP_TIMEOUT, ///< Value read_timeout:rdcap_timeout for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_BCH_ENC_BUS_ECC_UNCOR, ///< Value trans_drop:bch_enc_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_RCMD_BUS_ECC_UNCOR, ///< Value trans_drop:rcmd_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_RCMD_DROP_TRANS, ///< Value trans_drop:rcmd_drop_trans for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_RDCAP_BUS_ECC_UNCOR, ///< Value trans_drop:rdcap_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_RDCAP_DROP_TRANS, ///< Value trans_drop:rdcap_drop_trans for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_RMW_CMD_CTX_ERR, ///< Value trans_drop:rmw_cmd_ctx_err for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_SECDED_ENC_BUS_ECC_UNCOR, ///< Value trans_drop:secded_enc_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WCMD_CAP_BUS_ECC_UNCOR, ///< Value trans_drop:wcmd_cap_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WCMD_DROP_TRANS, ///< Value trans_drop:wcmd_drop_trans for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WCMD_GEN_BUS_ECC_UNCOR, ///< Value trans_drop:wcmd_gen_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WDCAP_BUS_ECC_UNCOR, ///< Value trans_drop:wdcap_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WDCAP_SPARSE_WRITE, ///< Value trans_drop:wdcap_sparse_write for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WDGEN_BUS_ECC_UNCOR, ///< Value trans_drop:wdgen_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WDGEN_DROP_TRANS, ///< Value trans_drop:wdgen_drop_trans for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WDRESP_BUS_ECC_UNCOR, ///< Value trans_drop:wdresp_bus_ecc_uncor for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_TRANS_DROP_WDRESP_DROP_TRANS, ///< Value trans_drop:wdresp_drop_trans for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_WRITE_TIMEOUT_WCMD_TIMEOUT, ///< Value write_timeout:wcmd_timeout for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_WRITE_TIMEOUT_WDGEN_TIMEOUT, ///< Value write_timeout:wdgen_timeout for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_WRITE_TIMEOUT_WDRESP_TIMEOUT, ///< Value write_timeout:wdresp_timeout for instance sram_edac of structure from NVM
   NVM_SRAM_EDAC_ERROR_LAST, ///< Last value of possible error within the NVM GHES SRAM_EDAC structu
} p64h_ras_nvm_sram_edac_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_ANA_MON_MONITOR_ERROR_OPEN_PACKAGE = 0, ///< Value monitor_error:open_package for instance ana_mon of structure from SEC
   SEC_ANA_MON_MONITOR_ERROR_POWER_GLITCH, ///< Value monitor_error:power_glitch for instance ana_mon of structure from SEC
   SEC_ANA_MON_MONITOR_ERROR_VDD1P8_BROWNOUT, ///< Value monitor_error:vdd1p8_brownout for instance ana_mon of structure from SEC
   SEC_ANA_MON_MONITOR_ERROR_VDD_BROWNOUT, ///< Value monitor_error:vdd_brownout for instance ana_mon of structure from SEC
   SEC_ANA_MON_MONITOR_ERROR_VOLTAGE_OUT_OF_RANGE, ///< Value monitor_error:voltage_out_of_range for instance ana_mon of structure from SEC
   SEC_ANA_MON_ERROR_LAST, ///< Last value of possible error within the SEC GHES ANA_MON structu
} p64h_ras_sec_ana_mon_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_APB2JTAG_COM_SEQUENCE_ERROR = 0, ///< Value com_sequence:error for instance apb2jtag of structure from SEC
   SEC_APB2JTAG_ERROR_LAST, ///< Last value of possible error within the SEC GHES APB2JTAG structu
} p64h_ras_sec_apb2jtag_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_CMON_INITIALIZATION_CALIBRATION_FAILED = 0, ///< Value initialization:calibration_failed for instance cmon of structure from SEC
   SEC_CMON_MONITOR_ERROR_FREQ_OUT_OF_RANGE, ///< Value monitor_error:freq_out_of_range for instance cmon of structure from SEC
   SEC_CMON_RECALIBRATION_FAILURE, ///< Value recalibration:failure for instance cmon of structure from SEC
   SEC_CMON_ERROR_LAST, ///< Last value of possible error within the SEC GHES CMON structu
} p64h_ras_sec_cmon_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_CSU_LOCK_LOCK = 0, ///< Value lock:lock for instance csu of structure from SEC
   SEC_CSU_LOCK_LOCK_LOSS, ///< Value lock:lock_loss for instance csu of structure from SEC
   SEC_CSU_OFFSETCAL_LOCK_LOCK, ///< Value offsetcal_lock:lock for instance csu of structure from SEC
   SEC_CSU_OFFSETCAL_LOCK_LOCK_LOSS, ///< Value offsetcal_lock:lock_loss for instance csu of structure from SEC
   SEC_CSU_ERROR_LAST, ///< Last value of possible error within the SEC GHES CSU structu
} p64h_ras_sec_csu_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_DMA_CORRECTED_ECC_PROT_CHMEM = 0, ///< Value corrected:ecc_prot_chmem for instance dma of structure from SEC
   SEC_DMA_CORRECTED_ECC_PROT_UIDMEM, ///< Value corrected:ecc_prot_uidmem for instance dma of structure from SEC
   SEC_DMA_CORRECTED_MXIF1_BCH_PROT, ///< Value corrected:mxif1_bch_prot for instance dma of structure from SEC
   SEC_DMA_CORRECTED_MXIF1_RCH0_PROT, ///< Value corrected:mxif1_rch0_prot for instance dma of structure from SEC
   SEC_DMA_CORRECTED_MXIF1_RCH1_PROT, ///< Value corrected:mxif1_rch1_prot for instance dma of structure from SEC
   SEC_DMA_CORRECTED_MXIF2_BCH_PROT, ///< Value corrected:mxif2_bch_prot for instance dma of structure from SEC
   SEC_DMA_CORRECTED_MXIF2_RCH0_PROT, ///< Value corrected:mxif2_rch0_prot for instance dma of structure from SEC
   SEC_DMA_CORRECTED_MXIF2_RCH1_PROT, ///< Value corrected:mxif2_rch1_prot for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_DST_DEC_ERR, ///< Value invalid_access:dst_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_DST_SLV_ERR, ///< Value invalid_access:dst_slv_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_LLI_RD_DEC_ERR, ///< Value invalid_access:lli_rd_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_LLI_WR_DEC_ERR, ///< Value invalid_access:lli_wr_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SHADOWREG_OR_LLI_INVALID_ERR, ///< Value invalid_access:shadowreg_or_lli_invalid_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_DEC_ERR, ///< Value invalid_access:slvif_commonreg_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_RD2WO_ERR, ///< Value invalid_access:slvif_commonreg_rd2wo_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_WR2RO_ERR, ///< Value invalid_access:slvif_commonreg_wr2ro_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_WRONHOLD_ERR, ///< Value invalid_access:slvif_commonreg_wronhold_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_DEC_ERR, ///< Value invalid_access:slvif_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_MULTIBLKTYPE_ERR, ///< Value invalid_access:slvif_multiblktype_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_RD2RWO_ERR, ///< Value invalid_access:slvif_rd2rwo_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_SHADOWREG_WRON_VALID_ERR, ///< Value invalid_access:slvif_shadowreg_wron_valid_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_UNDEFINEDREG_DEC_ERR, ///< Value invalid_access:slvif_undefinedreg_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_WR2RO_ERR, ///< Value invalid_access:slvif_wr2ro_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_WRONCHEN_ERR, ///< Value invalid_access:slvif_wronchen_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SLVIF_WRONHOLD_ERR, ///< Value invalid_access:slvif_wronhold_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SRC_DEC_ERR, ///< Value invalid_access:src_dec_err for instance dma of structure from SEC
   SEC_DMA_INVALID_ACCESS_SRC_SLV_ERR, ///< Value invalid_access:src_slv_err for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF1_ARCH_PROT_ARREADY, ///< Value parity_error:mxif1_arch_prot_arready for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF1_AWCH_PROT_AWREADY, ///< Value parity_error:mxif1_awch_prot_awready for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF1_BCH_PROT_BVALID, ///< Value parity_error:mxif1_bch_prot_bvalid for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF1_RCH_PROT_RVALID, ///< Value parity_error:mxif1_rch_prot_rvalid for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF1_WCH_PROT_WREADY, ///< Value parity_error:mxif1_wch_prot_wready for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF2_ARCH_PROT_ARREADY, ///< Value parity_error:mxif2_arch_prot_arready for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF2_AWCH_PROT_AWREADY, ///< Value parity_error:mxif2_awch_prot_awready for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF2_BCH_PROT_BVALID, ///< Value parity_error:mxif2_bch_prot_bvalid for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF2_RCH_PROT_RVALID, ///< Value parity_error:mxif2_rch_prot_rvalid for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_MXIF2_WCH_PROT_WREADY, ///< Value parity_error:mxif2_wch_prot_wready for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_SLVIF_ADDRPARITY_ERR, ///< Value parity_error:slvif_addrparity_err for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_SLVIF_COMMONREG_ADDRPARITY, ///< Value parity_error:slvif_commonreg_addrparity for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_SLVIF_COMMONREG_WRPARITY, ///< Value parity_error:slvif_commonreg_wrparity for instance dma of structure from SEC
   SEC_DMA_PARITY_ERROR_SLVIF_WRPARITY_ERR, ///< Value parity_error:slvif_wrparity_err for instance dma of structure from SEC
   SEC_DMA_STATE_CH_ABORTED, ///< Value state:ch_aborted for instance dma of structure from SEC
   SEC_DMA_STATE_CH_DISABLED, ///< Value state:ch_disabled for instance dma of structure from SEC
   SEC_DMA_STATE_CH_LOCK_CLEARED, ///< Value state:ch_lock_cleared for instance dma of structure from SEC
   SEC_DMA_STATE_CH_SRC_SUSPENDED, ///< Value state:ch_src_suspended for instance dma of structure from SEC
   SEC_DMA_STATE_CH_SUSPENDED, ///< Value state:ch_suspended for instance dma of structure from SEC
   SEC_DMA_SUBORDINATE_ERROR_LLI_RD_SLV_ERR, ///< Value subordinate_error:lli_rd_slv_err for instance dma of structure from SEC
   SEC_DMA_SUBORDINATE_ERROR_LLI_WR_SLV_ERR, ///< Value subordinate_error:lli_wr_slv_err for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_ECC_PROT_CHMEM, ///< Value uncorrected:ecc_prot_chmem for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_ECC_PROT_UIDMEM, ///< Value uncorrected:ecc_prot_uidmem for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_MXIF1_BCH_PROT, ///< Value uncorrected:mxif1_bch_prot for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_MXIF1_RCH0_PROT, ///< Value uncorrected:mxif1_rch0_prot for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_MXIF1_RCH1_PROT, ///< Value uncorrected:mxif1_rch1_prot for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_MXIF2_BCH_PROT, ///< Value uncorrected:mxif2_bch_prot for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_MXIF2_RCH0_PROT, ///< Value uncorrected:mxif2_rch0_prot for instance dma of structure from SEC
   SEC_DMA_UNCORRECTED_MXIF2_RCH1_PROT, ///< Value uncorrected:mxif2_rch1_prot for instance dma of structure from SEC
   SEC_DMA_ERROR_LAST, ///< Last value of possible error within the SEC GHES DMA structu
} p64h_ras_sec_dma_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_MESH_TAMPER_DETECTION_MESH_MISMATCH = 0, ///< Value tamper_detection:mesh_mismatch for instance mesh of structure from SEC
   SEC_MESH_ERROR_LAST, ///< Last value of possible error within the SEC GHES MESH structu
} p64h_ras_sec_mesh_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_NOC_BIST_FAILURE = 0, ///< Value bist:failure for instance noc of structure from SEC
   SEC_NOC_TRANSACTION_TIMEOUT, ///< Value transaction:timeout for instance noc of structure from SEC
   SEC_NOC_ERROR_LAST, ///< Last value of possible error within the SEC GHES NOC structu
} p64h_ras_sec_noc_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_OCR_BACK_PRESSURE_THRESHOLD_REACHED = 0, ///< Value back_pressure:threshold_reached for instance ocr of structure from SEC
   SEC_OCR_CORRECTED_READ, ///< Value corrected:read for instance ocr of structure from SEC
   SEC_OCR_CORRECTED_WRITE, ///< Value corrected:write for instance ocr of structure from SEC
   SEC_OCR_FIFO_ACCESS_READ_FAILURE, ///< Value fifo_access:read_failure for instance ocr of structure from SEC
   SEC_OCR_FIFO_OVERFLOW_AXI_READ, ///< Value fifo_overflow:axi_read for instance ocr of structure from SEC
   SEC_OCR_FIFO_OVERFLOW_AXI_WRITE, ///< Value fifo_overflow:axi_write for instance ocr of structure from SEC
   SEC_OCR_FIFO_OVERFLOW_MEL, ///< Value fifo_overflow:mel for instance ocr of structure from SEC
   SEC_OCR_FIFO_OVERFLOW_SELF_SCRUB, ///< Value fifo_overflow:self_scrub for instance ocr of structure from SEC
   SEC_OCR_FIFO_UNDERFLOW_AXI_READ, ///< Value fifo_underflow:axi_read for instance ocr of structure from SEC
   SEC_OCR_FIFO_UNDERFLOW_AXI_WRITE, ///< Value fifo_underflow:axi_write for instance ocr of structure from SEC
   SEC_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS, ///< Value invalid_access:unavailable_access for instance ocr of structure from SEC
   SEC_OCR_UNCORRECTED_READ, ///< Value uncorrected:read for instance ocr of structure from SEC
   SEC_OCR_UNCORRECTED_WRITE, ///< Value uncorrected:write for instance ocr of structure from SEC
   SEC_OCR_ERROR_LAST, ///< Last value of possible error within the SEC GHES OCR structu
} p64h_ras_sec_ocr_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_PQS_SECURITY_API_PREREQUISITE_NOT_MET = 0, ///< Value security:api_prerequisite_not_met for instance pqs of structure from SEC
   SEC_PQS_SECURITY_BUSY_WITH_OTHER_APPLICATION, ///< Value security:busy_with_other_application for instance pqs of structure from SEC
   SEC_PQS_SECURITY_DATA_COMM_RECEIVE, ///< Value security:data_comm_receive for instance pqs of structure from SEC
   SEC_PQS_SECURITY_DATA_COMM_SEND, ///< Value security:data_comm_send for instance pqs of structure from SEC
   SEC_PQS_SECURITY_DOWNLOAD_NOT_ALLOWED, ///< Value security:download_not_allowed for instance pqs of structure from SEC
   SEC_PQS_SECURITY_DRBG_REQUIRE_RESEED, ///< Value security:drbg_require_reseed for instance pqs of structure from SEC
   SEC_PQS_SECURITY_EXCEPTION_OCCURRED_RESETTING, ///< Value security:exception_occurred_resetting for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INCOMPATIBLE_BINARY, ///< Value security:incompatible_binary for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INCOMPATIBLE_KEY, ///< Value security:incompatible_key for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INSUFFICIENT_CONTEXT_MEM, ///< Value security:insufficient_context_mem for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INSUFFICIENT_IO_MEM, ///< Value security:insufficient_io_mem for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INSUFFICIENT_KEY_MEM, ///< Value security:insufficient_key_mem for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INTERNAL_ERROR, ///< Value security:internal_error for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INVALID_CONTEXT, ///< Value security:invalid_context for instance pqs of structure from SEC
   SEC_PQS_SECURITY_INVALID_KEY, ///< Value security:invalid_key for instance pqs of structure from SEC
   SEC_PQS_SECURITY_KEY_ENCRYPTION_KEY_NOT_SET, ///< Value security:key_encryption_key_not_set for instance pqs of structure from SEC
   SEC_PQS_SECURITY_MEMORY_CORRUPTION, ///< Value security:memory_corruption for instance pqs of structure from SEC
   SEC_PQS_SECURITY_NO_APPLICATION_RUNNING, ///< Value security:no_application_running for instance pqs of structure from SEC
   SEC_PQS_SECURITY_NOT_READY_ERROR, ///< Value security:not_ready_error for instance pqs of structure from SEC
   SEC_PQS_SECURITY_NOT_SUPPORTED_YET, ///< Value security:not_supported_yet for instance pqs of structure from SEC
   SEC_PQS_SECURITY_OUTPUT_BUFFER_SMALL, ///< Value security:output_buffer_small for instance pqs of structure from SEC
   SEC_PQS_SECURITY_RESET_NEEDED, ///< Value security:reset_needed for instance pqs of structure from SEC
   SEC_PQS_SECURITY_SELF_TEST_FAILED, ///< Value security:self_test_failed for instance pqs of structure from SEC
   SEC_PQS_SECURITY_SERVICE_NOT_FOUND, ///< Value security:service_not_found for instance pqs of structure from SEC
   SEC_PQS_SECURITY_SERVICE_NOT_SUPPORTED, ///< Value security:service_not_supported for instance pqs of structure from SEC
   SEC_PQS_SECURITY_UNSUPPORTED_ALGO, ///< Value security:unsupported_algo for instance pqs of structure from SEC
   SEC_PQS_SECURITY_UNSUPPORTED_ALGO_PARAM, ///< Value security:unsupported_algo_param for instance pqs of structure from SEC
   SEC_PQS_SECURITY_UNSUPPORTED_DATA_INTERFACE, ///< Value security:unsupported_data_interface for instance pqs of structure from SEC
   SEC_PQS_SECURITY_UNSUPPORTED_DRBG_SECURITY_STRENGTH, ///< Value security:unsupported_drbg_security_strength for instance pqs of structure from SEC
   SEC_PQS_SECURITY_UNSUPPORTED_FORMAT, ///< Value security:unsupported_format for instance pqs of structure from SEC
   SEC_PQS_SECURITY_UNSUPPORTED_KEY_TYPE, ///< Value security:unsupported_key_type for instance pqs of structure from SEC
   SEC_PQS_SECURITY_VERIFICATION_FAILED, ///< Value security:verification_failed for instance pqs of structure from SEC
   SEC_PQS_SECURITY_WRAPQ_PUBLIC_KEY_ABSENT, ///< Value security:wrapq_public_key_absent for instance pqs of structure from SEC
   SEC_PQS_SECURITY_WRONG_DIGEST_SIZE, ///< Value security:wrong_digest_size for instance pqs of structure from SEC
   SEC_PQS_SECURITY_WRONG_ENTROPY_INTERFACE_USED, ///< Value security:wrong_entropy_interface_used for instance pqs of structure from SEC
   SEC_PQS_SECURITY_WRONG_PARAMETER_VALUE, ///< Value security:wrong_parameter_value for instance pqs of structure from SEC
   SEC_PQS_SECURITY_ZEROISATION_TRIGGERED, ///< Value security:zeroisation_triggered for instance pqs of structure from SEC
   SEC_PQS_ERROR_LAST, ///< Last value of possible error within the SEC GHES PQS structu
} p64h_ras_sec_pqs_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_RAM_CORRECTED_RAM_ECC = 0, ///< Value corrected:ram_ecc for instance ram of structure from SEC
   SEC_RAM_UNCORRECTED_RAM_ECC, ///< Value uncorrected:ram_ecc for instance ram of structure from SEC
   SEC_RAM_ERROR_LAST, ///< Last value of possible error within the SEC GHES RAM structu
} p64h_ras_sec_ram_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_S7_D_CACHE_CORRECTABLE = 0, ///< Value d_cache:correctable for instance s7 of structure from SEC
   SEC_S7_D_CACHE_UNCORRECTABLE, ///< Value d_cache:uncorrectable for instance s7 of structure from SEC
   SEC_S7_DTIM_CORRECTABLE, ///< Value dtim:correctable for instance s7 of structure from SEC
   SEC_S7_DTIM_UNCORRECTABLE, ///< Value dtim:uncorrectable for instance s7 of structure from SEC
   SEC_S7_I_CACHE_BUS_ERROR, ///< Value i_cache:bus_error for instance s7 of structure from SEC
   SEC_S7_I_CACHE_CORRECTABLE, ///< Value i_cache:correctable for instance s7 of structure from SEC
   SEC_S7_I_CACHE_UNCORRECTABLE, ///< Value i_cache:uncorrectable for instance s7 of structure from SEC
   SEC_S7_ITIM_UNCORRECTABLE, ///< Value itim:uncorrectable for instance s7 of structure from SEC
   SEC_S7_TX_BUS_ERROR_LOAD_STORE_PTW, ///< Value tx_bus_error:load_store_ptw for instance s7 of structure from SEC
   SEC_S7_ERROR_LAST, ///< Last value of possible error within the SEC GHES S7 structu
} p64h_ras_sec_s7_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TAMPER_MON_TAMPER_DETECTION_HW_LOCK = 0, ///< Value tamper_detection:hw_lock for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_APPC_DEBUG, ///< Value tamper_detection:mismatch_perm_lock_appc_debug for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_PROD_TEST, ///< Value tamper_detection:mismatch_perm_lock_prod_test for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_SECC_DEBUG, ///< Value tamper_detection:mismatch_perm_lock_secc_debug for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_SYSC_DEBUG, ///< Value tamper_detection:mismatch_perm_lock_sysc_debug for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_SW_LOCK, ///< Value tamper_detection:sw_lock for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_APPC_DEBUG, ///< Value tamper_detection:tamper_appc_debug for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_PROD_TEST, ///< Value tamper_detection:tamper_prod_test for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_SECC_DEBUG, ///< Value tamper_detection:tamper_secc_debug for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_SYSC_DEBUG, ///< Value tamper_detection:tamper_sysc_debug for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_TAMPER_DETECTION_VSTART, ///< Value tamper_detection:vstart for instance tamper_mon of structure from SEC
   SEC_TAMPER_MON_ERROR_LAST, ///< Last value of possible error within the SEC GHES TAMPER_MON structu
} p64h_ras_sec_tamper_mon_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TIMER_FIFO_OVERFLOW_CDC_BUFFER = 0, ///< Value fifo_overflow:cdc_buffer for instance timer of structure from SEC
   SEC_TIMER_ERROR_LAST, ///< Last value of possible error within the SEC GHES TIMER structu
} p64h_ras_sec_timer_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TVS_MON_MONITOR_ERROR_HIGH_TEMP = 0, ///< Value monitor_error:high_temp for instance tvs_mon of structure from SEC
   SEC_TVS_MON_MONITOR_ERROR_LOW_TEMP, ///< Value monitor_error:low_temp for instance tvs_mon of structure from SEC
   SEC_TVS_MON_ERROR_LAST, ///< Last value of possible error within the SEC GHES TVS_MON structu
} p64h_ras_sec_tvs_mon_err_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_WDOG_STATE_FIRST_WINDOW = 0, ///< Value state:first_window for instance wdog of structure from SEC
   SEC_WDOG_STATE_FIRST_WINDOW_CLOSED, ///< Value state:first_window_closed for instance wdog of structure from SEC
   SEC_WDOG_STATE_RESET_PENDING, ///< Value state:reset_pending for instance wdog of structure from SEC
   SEC_WDOG_STATE_RESET_REQUESTED, ///< Value state:reset_requested for instance wdog of structure from SEC
   SEC_WDOG_STATE_SECOND_WINDOW, ///< Value state:second_window for instance wdog of structure from SEC
   SEC_WDOG_ERROR_LAST, ///< Last value of possible error within the SEC GHES WDOG structu
} p64h_ras_sec_wdog_err_t;

/**
 * @brief Definitions of all errors within a structure of the SYS GHES
 */
typedef enum {
    SYS_OCR_BACK_PRESSURE_THRESHOLD_REACHED = 0, ///< Value back_pressure:threshold_reached for instance ocr of structure from SYS
   SYS_OCR_CORRECTED_READ, ///< Value corrected:read for instance ocr of structure from SYS
   SYS_OCR_CORRECTED_WRITE, ///< Value corrected:write for instance ocr of structure from SYS
   SYS_OCR_FIFO_ACCESS_READ_FAILURE, ///< Value fifo_access:read_failure for instance ocr of structure from SYS
   SYS_OCR_FIFO_OVERFLOW_AXI_READ, ///< Value fifo_overflow:axi_read for instance ocr of structure from SYS
   SYS_OCR_FIFO_OVERFLOW_AXI_WRITE, ///< Value fifo_overflow:axi_write for instance ocr of structure from SYS
   SYS_OCR_FIFO_OVERFLOW_MEL, ///< Value fifo_overflow:mel for instance ocr of structure from SYS
   SYS_OCR_FIFO_OVERFLOW_SELF_SCRUB, ///< Value fifo_overflow:self_scrub for instance ocr of structure from SYS
   SYS_OCR_FIFO_UNDERFLOW_AXI_READ, ///< Value fifo_underflow:axi_read for instance ocr of structure from SYS
   SYS_OCR_FIFO_UNDERFLOW_AXI_WRITE, ///< Value fifo_underflow:axi_write for instance ocr of structure from SYS
   SYS_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS, ///< Value invalid_access:unavailable_access for instance ocr of structure from SYS
   SYS_OCR_UNCORRECTED_READ, ///< Value uncorrected:read for instance ocr of structure from SYS
   SYS_OCR_UNCORRECTED_WRITE, ///< Value uncorrected:write for instance ocr of structure from SYS
   SYS_OCR_ERROR_LAST, ///< Last value of possible error within the SYS GHES OCR structu
} p64h_ras_sys_ocr_err_t;

/**
 * @brief Definitions of all errors within a structure of the SYS GHES
 */
typedef enum {
    SYS_S7_D_CACHE_CORRECTABLE = 0, ///< Value d_cache:correctable for instance s7 of structure from SYS
   SYS_S7_D_CACHE_UNCORRECTABLE, ///< Value d_cache:uncorrectable for instance s7 of structure from SYS
   SYS_S7_DTIM_CORRECTABLE, ///< Value dtim:correctable for instance s7 of structure from SYS
   SYS_S7_DTIM_UNCORRECTABLE, ///< Value dtim:uncorrectable for instance s7 of structure from SYS
   SYS_S7_FW_EXEC, ///< Value fw:exec for instance s7 of structure from SYS
   SYS_S7_I_CACHE_BUS_ERROR, ///< Value i_cache:bus_error for instance s7 of structure from SYS
   SYS_S7_I_CACHE_CORRECTABLE, ///< Value i_cache:correctable for instance s7 of structure from SYS
   SYS_S7_ITIM_CORRECTABLE, ///< Value itim:correctable for instance s7 of structure from SYS
   SYS_S7_ITIM_UNCORRECTABLE, ///< Value itim:uncorrectable for instance s7 of structure from SYS
   SYS_S7_TX_BUS_ERROR_LOAD_STORE_PTW, ///< Value tx_bus_error:load_store_ptw for instance s7 of structure from SYS
   SYS_S7_ERROR_LAST, ///< Last value of possible error within the SYS GHES S7 structu
} p64h_ras_sys_s7_err_t;

/**
 * @brief Definitions of all uniquely encoded identifiers for the structures of all GHESs
 */
typedef enum {
    RAS_GHES_STRUCT_NA = 0, ///< Used to convey no associated structure and source
    RAS_GHES_APP_MEM_STRUCT_OCR = RAS_ERROR_PACK(APP_MEM, APP_MEM_STRUCT_OCR, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded OCR structure ID from the APP_MEM
    RAS_GHES_APP_NOC_STRUCT_WGC = RAS_ERROR_PACK(APP_NOC, APP_NOC_STRUCT_WGC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded WGC structure ID from the APP_NOC
    RAS_GHES_APP_X288_STRUCT_TILE = RAS_ERROR_PACK(APP_X288, APP_X288_STRUCT_TILE, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded TILE structure ID from the APP_X288
    RAS_GHES_APP_X288_STRUCT_FABRIC = RAS_ERROR_PACK(APP_X288, APP_X288_STRUCT_FABRIC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded FABRIC structure ID from the APP_X288
    RAS_GHES_APP_X288_STRUCT_IOMMU = RAS_ERROR_PACK(APP_X288, APP_X288_STRUCT_IOMMU, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded IOMMU structure ID from the APP_X288
    RAS_GHES_APP_X288_STRUCT_LOCKSTEP = RAS_ERROR_PACK(APP_X288, APP_X288_STRUCT_LOCKSTEP, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded LOCKSTEP structure ID from the APP_X288
    RAS_GHES_APP_X288_STRUCT_WGC = RAS_ERROR_PACK(APP_X288, APP_X288_STRUCT_WGC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded WGC structure ID from the APP_X288
    RAS_GHES_CLOCK_STRUCT_CSU = RAS_ERROR_PACK(CLOCK, CLOCK_STRUCT_CSU, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded CSU structure ID from the CLOCK
    RAS_GHES_NVM_STRUCT_SRAM_EDAC = RAS_ERROR_PACK(NVM, NVM_STRUCT_SRAM_EDAC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded SRAM_EDAC structure ID from the NVM
    RAS_GHES_NVM_STRUCT_NVM_EDAC = RAS_ERROR_PACK(NVM, NVM_STRUCT_NVM_EDAC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded NVM_EDAC structure ID from the NVM
    RAS_GHES_SEC_STRUCT_OCR = RAS_ERROR_PACK(SEC, SEC_STRUCT_OCR, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded OCR structure ID from the SEC
    RAS_GHES_SEC_STRUCT_CSU = RAS_ERROR_PACK(SEC, SEC_STRUCT_CSU, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded CSU structure ID from the SEC
    RAS_GHES_SEC_STRUCT_PQS = RAS_ERROR_PACK(SEC, SEC_STRUCT_PQS, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded PQS structure ID from the SEC
    RAS_GHES_SEC_STRUCT_NOC = RAS_ERROR_PACK(SEC, SEC_STRUCT_NOC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded NOC structure ID from the SEC
    RAS_GHES_SEC_STRUCT_CMON = RAS_ERROR_PACK(SEC, SEC_STRUCT_CMON, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded CMON structure ID from the SEC
    RAS_GHES_SEC_STRUCT_TAMPER_MON = RAS_ERROR_PACK(SEC, SEC_STRUCT_TAMPER_MON, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded TAMPER_MON structure ID from the SEC
    RAS_GHES_SEC_STRUCT_S7 = RAS_ERROR_PACK(SEC, SEC_STRUCT_S7, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded S7 structure ID from the SEC
    RAS_GHES_SEC_STRUCT_RAM = RAS_ERROR_PACK(SEC, SEC_STRUCT_RAM, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded RAM structure ID from the SEC
    RAS_GHES_SEC_STRUCT_TIMER = RAS_ERROR_PACK(SEC, SEC_STRUCT_TIMER, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded TIMER structure ID from the SEC
    RAS_GHES_SEC_STRUCT_APB2JTAG = RAS_ERROR_PACK(SEC, SEC_STRUCT_APB2JTAG, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded APB2JTAG structure ID from the SEC
    RAS_GHES_SEC_STRUCT_WDOG = RAS_ERROR_PACK(SEC, SEC_STRUCT_WDOG, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded WDOG structure ID from the SEC
    RAS_GHES_SEC_STRUCT_ANA_MON = RAS_ERROR_PACK(SEC, SEC_STRUCT_ANA_MON, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded ANA_MON structure ID from the SEC
    RAS_GHES_SEC_STRUCT_DMA = RAS_ERROR_PACK(SEC, SEC_STRUCT_DMA, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded DMA structure ID from the SEC
    RAS_GHES_SEC_STRUCT_TVS_MON = RAS_ERROR_PACK(SEC, SEC_STRUCT_TVS_MON, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded TVS_MON structure ID from the SEC
    RAS_GHES_SEC_STRUCT_MESH = RAS_ERROR_PACK(SEC, SEC_STRUCT_MESH, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded MESH structure ID from the SEC
    RAS_GHES_SYS_STRUCT_OCR = RAS_ERROR_PACK(SYS, SYS_STRUCT_OCR, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded OCR structure ID from the SYS
    RAS_GHES_SYS_STRUCT_S7 = RAS_ERROR_PACK(SYS, SYS_STRUCT_S7, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded S7 structure ID from the SYS
    RAS_GHES_STRUC_MAX ///< Maximum value of p64h_ras_ghes_struc_t enum
} p64h_ras_ghes_struc_t;

typedef enum { INFORMATIONAL, CORRECTED, UNCORRECTED, RECOVERABLE, FATAL, UNDEFINED_SEV } p64h_ras_err_sev_t;

/**
 * @brief Definitions of all uniquely encoded errors for each GHES, structures and structure instances
 */
typedef enum {
    RAS_ERR_ID_APP_MEM_OCR_BACK_PRESSURE_THRESHOLD_REACHED = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_BACK_PRESSURE_THRESHOLD_REACHED), ///< back_pressure:threshold_reached for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_CORRECTED_READ = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_CORRECTED_READ), ///< corrected:read for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_CORRECTED_WRITE = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_CORRECTED_WRITE), ///< corrected:write for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_ACCESS_READ_FAILURE = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_ACCESS_READ_FAILURE), ///< fifo_access:read_failure for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_OVERFLOW_AXI_READ = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_OVERFLOW_AXI_READ), ///< fifo_overflow:axi_read for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_OVERFLOW_AXI_WRITE = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_OVERFLOW_AXI_WRITE), ///< fifo_overflow:axi_write for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_OVERFLOW_MEL = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_OVERFLOW_MEL), ///< fifo_overflow:mel for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_OVERFLOW_SELF_SCRUB = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_OVERFLOW_SELF_SCRUB), ///< fifo_overflow:self_scrub for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_UNDERFLOW_AXI_READ = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_UNDERFLOW_AXI_READ), ///< fifo_underflow:axi_read for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_FIFO_UNDERFLOW_AXI_WRITE = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_FIFO_UNDERFLOW_AXI_WRITE), ///< fifo_underflow:axi_write for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS), ///< invalid_access:unavailable_access for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_UNCORRECTED_READ = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_UNCORRECTED_READ), ///< uncorrected:read for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_MEM_OCR_UNCORRECTED_WRITE = RAS_ERROR_ENCODE(APP_MEM, APP_MEM_STRUCT_OCR, APP_MEM_OCR_UNCORRECTED_WRITE), ///< uncorrected:write for instance ocr of structure from APP_MEM
    RAS_ERR_ID_APP_NOC_WGC_PERMISSION_DENIED_READ = RAS_ERROR_ENCODE(APP_NOC, APP_NOC_STRUCT_WGC, APP_NOC_WGC_PERMISSION_DENIED_READ), ///< permission_denied:read for instance wgc of structure from APP_NOC
    RAS_ERR_ID_APP_NOC_WGC_PERMISSION_DENIED_WRITE = RAS_ERROR_ENCODE(APP_NOC, APP_NOC_STRUCT_WGC, APP_NOC_WGC_PERMISSION_DENIED_WRITE), ///< permission_denied:write for instance wgc of structure from APP_NOC
    RAS_ERR_ID_APP_X288_FABRIC_AXI4_DEINTERLEAVER_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_AXI4_DEINTERLEAVER_CORRECTED), ///< axi4_deinterleaver:corrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_AXI4_DEINTERLEAVER_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_AXI4_DEINTERLEAVER_UNCORRECTED), ///< axi4_deinterleaver:uncorrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_CXL_CACHE_BRIDGE_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_CXL_CACHE_BRIDGE_CORRECTED), ///< cxl_cache_bridge:corrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_CXL_CACHE_BRIDGE_PRODUCE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_CXL_CACHE_BRIDGE_PRODUCE_CORRUPT), ///< cxl_cache_bridge:produce_corrupt for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_CXL_CACHE_BRIDGE_RECEIVE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_CXL_CACHE_BRIDGE_RECEIVE_CORRUPT), ///< cxl_cache_bridge:receive_corrupt for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_CXL_MEM_BRIDGE_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_CXL_MEM_BRIDGE_CORRECTED), ///< cxl_mem_bridge:corrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_CXL_MEM_BRIDGE_PRODUCE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_CXL_MEM_BRIDGE_PRODUCE_CORRUPT), ///< cxl_mem_bridge:produce_corrupt for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_CXL_MEM_BRIDGE_RECEIVE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_CXL_MEM_BRIDGE_RECEIVE_CORRUPT), ///< cxl_mem_bridge:receive_corrupt for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_DLS_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_DLS_CORRECTED), ///< dls:corrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_DLS_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_DLS_UNCORRECTED), ///< dls:uncorrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L2_CACHE_CORRECTED_DATA = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L2_CACHE_CORRECTED_DATA), ///< l2_cache:corrected_data for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L2_CACHE_CORRECTED_TAG = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L2_CACHE_CORRECTED_TAG), ///< l2_cache:corrected_tag for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L2_CACHE_PRODUCE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L2_CACHE_PRODUCE_CORRUPT), ///< l2_cache:produce_corrupt for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L2_CACHE_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L2_CACHE_UNCORRECTED), ///< l2_cache:uncorrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L3_CACHE_DATA_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L3_CACHE_DATA_CORRECTED), ///< l3_cache_data:corrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L3_CACHE_DATA_PRODUCE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L3_CACHE_DATA_PRODUCE_CORRUPT), ///< l3_cache_data:produce_corrupt for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L3_CACHE_TAG_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L3_CACHE_TAG_CORRECTED), ///< l3_cache_tag:corrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L3_CACHE_TAG_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L3_CACHE_TAG_UNCORRECTED), ///< l3_cache_tag:uncorrected for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_FABRIC_L3_CACHE_TILELINK_DENIED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_FABRIC, APP_X288_FABRIC_L3_CACHE_TILELINK_DENIED), ///< l3_cache_tilelink:denied for instance fabric of structure from APP_X288
    RAS_ERR_ID_APP_X288_IOMMU_IOMMU_22_PTW_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_IOMMU, APP_X288_IOMMU_IOMMU_22_PTW_CORRECTED), ///< iommu_22_ptw:corrected for instance iommu of structure from APP_X288
    RAS_ERR_ID_APP_X288_IOMMU_IOMMU_L2_TLB_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_IOMMU, APP_X288_IOMMU_IOMMU_L2_TLB_CORRECTED), ///< iommu_l2_tlb:corrected for instance iommu of structure from APP_X288
    RAS_ERR_ID_APP_X288_LOCKSTEP_TILE_LS_COMPARE_DIFF = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_LOCKSTEP, APP_X288_LOCKSTEP_TILE_LS_COMPARE_DIFF), ///< tile_ls:compare_diff for instance lockstep of structure from APP_X288
    RAS_ERR_ID_APP_X288_LOCKSTEP_TILE_LS_CONTAIN = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_LOCKSTEP, APP_X288_LOCKSTEP_TILE_LS_CONTAIN), ///< tile_ls:contain for instance lockstep of structure from APP_X288
    RAS_ERR_ID_APP_X288_LOCKSTEP_TILE_LS_DIFF = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_LOCKSTEP, APP_X288_LOCKSTEP_TILE_LS_DIFF), ///< tile_ls:diff for instance lockstep of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_CORE_STATE_CEASE = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_CORE_STATE_CEASE), ///< core_state:cease for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_CORE_STATE_DEBUG = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_CORE_STATE_DEBUG), ///< core_state:debug for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_CORE_STATE_HALT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_CORE_STATE_HALT), ///< core_state:halt for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_CORE_STATE_WFI = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_CORE_STATE_WFI), ///< core_state:wfi for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_GHRT_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_GHRT_UNCORRECTED), ///< ghrt:uncorrected for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_DCACHE_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_DCACHE_CORRECTED), ///< l1_dcache:corrected for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_DCACHE_PRODUCE_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_DCACHE_PRODUCE_CORRUPT), ///< l1_dcache:produce_corrupt for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_DCACHE_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_DCACHE_UNCORRECTED), ///< l1_dcache:uncorrected for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_DCACHE_TILELINK_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_DCACHE_TILELINK_CORRUPT), ///< l1_dcache_tilelink:corrupt for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_DCACHE_TILELINK_DENIED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_DCACHE_TILELINK_DENIED), ///< l1_dcache_tilelink:denied for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_ICACHE_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_ICACHE_CORRECTED), ///< l1_icache:corrected for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_ICACHE_NO_RECORD = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_ICACHE_NO_RECORD), ///< l1_icache:no_record for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_ICACHE_UNCORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_ICACHE_UNCORRECTED), ///< l1_icache:uncorrected for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_ICACHE_TILELINK_CORRUPT = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_ICACHE_TILELINK_CORRUPT), ///< l1_icache_tilelink:corrupt for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L1_ICACHE_TILELINK_DENIED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L1_ICACHE_TILELINK_DENIED), ///< l1_icache_tilelink:denied for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_TILE_L2_TLB_CORRECTED = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_TILE, APP_X288_TILE_L2_TLB_CORRECTED), ///< l2_tlb:corrected for instance tile of structure from APP_X288
    RAS_ERR_ID_APP_X288_WGC_PERMISSION_DENIED_READ = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_WGC, APP_X288_WGC_PERMISSION_DENIED_READ), ///< permission_denied:read for instance wgc of structure from APP_X288
    RAS_ERR_ID_APP_X288_WGC_PERMISSION_DENIED_WRITE = RAS_ERROR_ENCODE(APP_X288, APP_X288_STRUCT_WGC, APP_X288_WGC_PERMISSION_DENIED_WRITE), ///< permission_denied:write for instance wgc of structure from APP_X288
    RAS_ERR_ID_CLOCK_CSU_LOCK_LOCK = RAS_ERROR_ENCODE(CLOCK, CLOCK_STRUCT_CSU, CLOCK_CSU_LOCK_LOCK), ///< lock:lock for instance csu of structure from CLOCK
    RAS_ERR_ID_CLOCK_CSU_LOCK_LOCK_LOSS = RAS_ERROR_ENCODE(CLOCK, CLOCK_STRUCT_CSU, CLOCK_CSU_LOCK_LOCK_LOSS), ///< lock:lock_loss for instance csu of structure from CLOCK
    RAS_ERR_ID_CLOCK_CSU_OFFSETCAL_LOCK_LOCK = RAS_ERROR_ENCODE(CLOCK, CLOCK_STRUCT_CSU, CLOCK_CSU_OFFSETCAL_LOCK_LOCK), ///< offsetcal_lock:lock for instance csu of structure from CLOCK
    RAS_ERR_ID_CLOCK_CSU_OFFSETCAL_LOCK_LOCK_LOSS = RAS_ERROR_ENCODE(CLOCK, CLOCK_STRUCT_CSU, CLOCK_CSU_OFFSETCAL_LOCK_LOCK_LOSS), ///< offsetcal_lock:lock_loss for instance csu of structure from CLOCK
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_BCH_ENC_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_BCH_ENC_BUS_ECC_COR), ///< bus_ecc_corrected:bch_enc_bus_ecc_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AR_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AR_A), ///< bus_ecc_corrected:nvm_ctrl_s_0_cor_ar_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AR_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AR_C), ///< bus_ecc_corrected:nvm_ctrl_s_0_cor_ar_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AW_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AW_A), ///< bus_ecc_corrected:nvm_ctrl_s_0_cor_aw_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AW_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_AW_C), ///< bus_ecc_corrected:nvm_ctrl_s_0_cor_aw_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_B = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_B), ///< bus_ecc_corrected:nvm_ctrl_s_0_cor_b for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_R = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_NVM_CTRL_S_0_COR_R), ///< bus_ecc_corrected:nvm_ctrl_s_0_cor_r for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AR_A_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AR_A_PAR), ///< bus_ecc_corrected:ram_cor_err_ar_a_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AR_C_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AR_C_PAR), ///< bus_ecc_corrected:ram_cor_err_ar_c_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AW_A_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AW_A_PAR), ///< bus_ecc_corrected:ram_cor_err_aw_a_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AW_C_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_AW_C_PAR), ///< bus_ecc_corrected:ram_cor_err_aw_c_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_W_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_W_PAR), ///< bus_ecc_corrected:ram_cor_err_w_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_WDATA_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RAM_COR_ERR_WDATA_PAR), ///< bus_ecc_corrected:ram_cor_err_wdata_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RDCAP_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RDCAP_BUS_ECC_COR), ///< bus_ecc_corrected:rdcap_bus_ecc_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_RDGEN_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_RDGEN_BUS_ECC_COR), ///< bus_ecc_corrected:rdgen_bus_ecc_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_SECDED_ENC_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_SECDED_ENC_BUS_ECC_COR), ///< bus_ecc_corrected:secded_enc_bus_ecc_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_CORRECTED_WDRESP_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_CORRECTED_WDRESP_BUS_ECC_COR), ///< bus_ecc_corrected:wdresp_bus_ecc_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_BCH_ENC_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_BCH_ENC_BUS_ECC_UNCOR), ///< bus_ecc_uncorrected:bch_enc_bus_ecc_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AR_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AR_A), ///< bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_ar_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AR_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AR_C), ///< bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_ar_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AW_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AW_A), ///< bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_aw_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AW_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_AW_C), ///< bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_aw_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_B = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_B), ///< bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_b for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_R = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_NVM_CTRL_S_0_UNCOR_R), ///< bus_ecc_uncorrected:nvm_ctrl_s_0_uncor_r for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AR_A_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AR_A_PAR), ///< bus_ecc_uncorrected:ram_uncor_err_ar_a_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AR_C_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AR_C_PAR), ///< bus_ecc_uncorrected:ram_uncor_err_ar_c_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AW_A_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AW_A_PAR), ///< bus_ecc_uncorrected:ram_uncor_err_aw_a_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AW_C_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_AW_C_PAR), ///< bus_ecc_uncorrected:ram_uncor_err_aw_c_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_W_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_W_PAR), ///< bus_ecc_uncorrected:ram_uncor_err_w_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_WDATA_PAR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RAM_UNCOR_ERR_WDATA_PAR), ///< bus_ecc_uncorrected:ram_uncor_err_wdata_par for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RDCAP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RDCAP_BUS_ECC_UNCOR), ///< bus_ecc_uncorrected:rdcap_bus_ecc_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RDGEN_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_RDGEN_BUS_ECC_UNCOR), ///< bus_ecc_uncorrected:rdgen_bus_ecc_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_SECDED_ENC_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_SECDED_ENC_BUS_ECC_UNCOR), ///< bus_ecc_uncorrected:secded_enc_bus_ecc_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_WDRESP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_BUS_ECC_UNCORRECTED_WDRESP_BUS_ECC_UNCOR), ///< bus_ecc_uncorrected:wdresp_bus_ecc_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_M_COR_AR_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_M_COR_AR_A), ///< dmr_corrected:app_noc_m_cor_ar_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_M_COR_AW_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_M_COR_AW_A), ///< dmr_corrected:app_noc_m_cor_aw_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AR_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AR_A), ///< dmr_corrected:app_noc_s_cor_ar_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AR_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AR_C), ///< dmr_corrected:app_noc_s_cor_ar_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AW_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AW_A), ///< dmr_corrected:app_noc_s_cor_aw_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AW_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_AW_C), ///< dmr_corrected:app_noc_s_cor_aw_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_B = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_B), ///< dmr_corrected:app_noc_s_cor_b for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_R = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_APP_NOC_S_COR_R), ///< dmr_corrected:app_noc_s_cor_r for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_DMR_N0_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_DMR_N0_COR), ///< dmr_corrected:dmr_n0_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_CORRECTED_DMR_N1_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_CORRECTED_DMR_N1_COR), ///< dmr_corrected:dmr_n1_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_M_UNCOR_AR_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_M_UNCOR_AR_A), ///< dmr_uncorrected:app_noc_m_uncor_ar_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_M_UNCOR_AW_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_M_UNCOR_AW_A), ///< dmr_uncorrected:app_noc_m_uncor_aw_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AR_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AR_A), ///< dmr_uncorrected:app_noc_s_uncor_ar_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AR_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AR_C), ///< dmr_uncorrected:app_noc_s_uncor_ar_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AW_A = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AW_A), ///< dmr_uncorrected:app_noc_s_uncor_aw_a for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AW_C = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_AW_C), ///< dmr_uncorrected:app_noc_s_uncor_aw_c for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_B = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_B), ///< dmr_uncorrected:app_noc_s_uncor_b for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_R = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_APP_NOC_S_UNCOR_R), ///< dmr_uncorrected:app_noc_s_uncor_r for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_N0_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_N0_UNCOR), ///< dmr_uncorrected:dmr_n0_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_N1_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_N1_UNCOR), ///< dmr_uncorrected:dmr_n1_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_NDCS_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_DMR_UNCORRECTED_DMR_NDCS_UNCOR), ///< dmr_uncorrected:dmr_ndcs_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD0_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD0_COR), ///< ecc_corrected:thrd0_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD1_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD1_COR), ///< ecc_corrected:thrd1_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD2_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD2_COR), ///< ecc_corrected:thrd2_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD3_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD3_COR), ///< ecc_corrected:thrd3_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD4_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD4_COR), ///< ecc_corrected:thrd4_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD5_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD5_COR), ///< ecc_corrected:thrd5_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD6_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD6_COR), ///< ecc_corrected:thrd6_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_CORRECTED_THRD7_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_CORRECTED_THRD7_COR), ///< ecc_corrected:thrd7_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD0_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD0_UNCOR), ///< ecc_uncorrected:thrd0_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD1_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD1_UNCOR), ///< ecc_uncorrected:thrd1_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD2_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD2_UNCOR), ///< ecc_uncorrected:thrd2_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD3_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD3_UNCOR), ///< ecc_uncorrected:thrd3_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD4_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD4_UNCOR), ///< ecc_uncorrected:thrd4_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD5_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD5_UNCOR), ///< ecc_uncorrected:thrd5_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD6_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD6_UNCOR), ///< ecc_uncorrected:thrd6_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_ECC_UNCORRECTED_THRD7_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_ECC_UNCORRECTED_THRD7_UNCOR), ///< ecc_uncorrected:thrd7_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR), ///< emon_corrected:emon_cor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL), ///< emon_corrected:emon_cor_buf_full for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THRHLD = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THRHLD), ///< emon_corrected:emon_cor_buf_high_thrhld for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW), ///< emon_corrected:emon_cor_buf_ovrflw for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_FSM_ERR), ///< emon_corrected:emon_fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL), ///< emon_corrected:emon_stat_buf_full for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW), ///< emon_corrected:emon_stat_buf_ovrflw for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL), ///< emon_corrected:emon_uncor_buf_full for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THRHLD = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THRHLD), ///< emon_corrected:emon_uncor_buf_high_thrhld for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW), ///< emon_corrected:emon_uncor_buf_ovrflw for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_PATROL_SCRUB_COMPLETE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_PATROL_SCRUB_COMPLETE), ///< emon_corrected:patrol_scrub_complete for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_SCRUB_DONE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_SCRUB_DONE), ///< emon_corrected:scrub_done for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_UNCORRECTED_EMON_ADDR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_UNCORRECTED_EMON_ADDR_ERR), ///< emon_uncorrected:emon_addr_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_UNCORRECTED_EMON_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_UNCORRECTED_EMON_UNCOR), ///< emon_uncorrected:emon_uncor for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_BUF_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_BUF_FSM_ERR), ///< fault:buf_fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_DEMAND_READ_RAM_DSCR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_DEMAND_READ_RAM_DSCR_ERR), ///< fault:demand_read_ram_dscr_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_ENC_ADDR_PARITY_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_ENC_ADDR_PARITY_ERR), ///< fault:enc_addr_parity_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_ENC_DATA_PARITY_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_ENC_DATA_PARITY_ERR), ///< fault:enc_data_parity_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_ENC_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_ENC_FSM_ERR), ///< fault:enc_fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_FSM_ERR), ///< fault:fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_IOB_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_IOB_ERR), ///< fault:iob_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_PAR_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_PAR_FSM_ERR), ///< fault:par_fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_PATROL_SCRUB_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_PATROL_SCRUB_FSM_ERR), ///< fault:patrol_scrub_fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_POLL_HOST_SYNC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_POLL_HOST_SYNC_ERR), ///< fault:poll_host_sync_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_RAM_ADDR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_RAM_ADDR_ERR), ///< fault:ram_addr_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_RAM_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_RAM_FSM_ERR), ///< fault:ram_fsm_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_RAM_SIZE_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_RAM_SIZE_ERR), ///< fault:ram_size_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_RAM_UNALIGN_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_RAM_UNALIGN_ERR), ///< fault:ram_unalign_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_RAM_WSTRB_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_RAM_WSTRB_ERR), ///< fault:ram_wstrb_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_RD_HOST_DSCR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_RD_HOST_DSCR_ERR), ///< fault:rd_host_dscr_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_READ_RAM_DSCR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_READ_RAM_DSCR_ERR), ///< fault:read_ram_dscr_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_TIMEOUT_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_TIMEOUT_ERR), ///< fault:timeout_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_TRANS_BUF_CMD_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_TRANS_BUF_CMD_ERR), ///< fault:trans_buf_cmd_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_TRANS_BUF_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_TRANS_BUF_ERR), ///< fault:trans_buf_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_WR_DSCR_TO_HOST_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_WR_DSCR_TO_HOST_ERR), ///< fault:wr_dscr_to_host_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_WR_DSCR_TO_RAM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_WR_DSCR_TO_RAM_ERR), ///< fault:wr_dscr_to_ram_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_FAULT_WRITE_RAM_SYNC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_FAULT_WRITE_RAM_SYNC_ERR), ///< fault:write_ram_sync_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_BUF_0_COR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_BUF_0_COR_ECC_ERR), ///< ram_corrected:buf_0_cor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_BUF_1_COR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_BUF_1_COR_ECC_ERR), ///< ram_corrected:buf_1_cor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_DEC_DATA_RAM_COR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_DEC_DATA_RAM_COR_ERR), ///< ram_corrected:dec_data_ram_cor_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_ECC_COR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_ECC_COR_ERR), ///< ram_corrected:ecc_cor_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_EMON_COR_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_EMON_COR_RAM_COR_ECC_ERR), ///< ram_corrected:emon_cor_ram_cor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_EMON_STAT_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_EMON_STAT_RAM_COR_ECC_ERR), ///< ram_corrected:emon_stat_ram_cor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_EMON_UNCOR_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_EMON_UNCOR_RAM_COR_ECC_ERR), ///< ram_corrected:emon_uncor_ram_cor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_CORRECTED_ENC_DATA_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_CORRECTED_ENC_DATA_RAM_COR_ECC_ERR), ///< ram_corrected:enc_data_ram_cor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_BUF_0_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_BUF_0_UNCOR_ECC_ERR), ///< ram_uncorrected:buf_0_uncor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_BUF_1_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_BUF_1_UNCOR_ECC_ERR), ///< ram_uncorrected:buf_1_uncor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCOR_ERR), ///< ram_uncorrected:dec_data_ram_uncor_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_ECC_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_ECC_UNCOR_ERR), ///< ram_uncorrected:ecc_uncor_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_COR_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_COR_RAM_UNCOR_ECC_ERR), ///< ram_uncorrected:emon_cor_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_STAT_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_STAT_RAM_UNCOR_ECC_ERR), ///< ram_uncorrected:emon_stat_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_UNCOR_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_EMON_UNCOR_RAM_UNCOR_ECC_ERR), ///< ram_uncorrected:emon_uncor_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_RAM_UNCORRECTED_ENC_DATA_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_RAM_UNCORRECTED_ENC_DATA_RAM_UNCOR_ECC_ERR), ///< ram_uncorrected:enc_data_ram_uncor_ecc_err for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_READ_TIMEOUT_RAM_DROP_READ_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_READ_TIMEOUT_RAM_DROP_READ_TRANS), ///< read_timeout:ram_drop_read_trans for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_READ_TIMEOUT_RAM_RDATA_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_READ_TIMEOUT_RAM_RDATA_TIMEOUT), ///< read_timeout:ram_rdata_timeout for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_BRESP_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_BRESP_TIMEOUT), ///< write_timeout:ram_bresp_timeout for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_DROP_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_DROP_WRITE_TRANS), ///< write_timeout:ram_drop_write_trans for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_NULL_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_WRITE_TIMEOUT_RAM_NULL_WRITE_TRANS), ///< write_timeout:ram_null_write_trans for instance nvm_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_DATA_ERROR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_DATA_ERROR), ///< app:bist_data_error for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_FINISHED = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_FINISHED), ///< app:bist_finished for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_PARITY_ERROR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_PARITY_ERROR), ///< app:bist_parity_error for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_TBL_0_CORRECTABLE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_TBL_0_CORRECTABLE), ///< app:bist_tbl_0_correctable for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_TBL_0_UNCORRECTABLE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_TBL_0_UNCORRECTABLE), ///< app:bist_tbl_0_uncorrectable for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_TBL_1_CORRECTABLE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_TBL_1_CORRECTABLE), ///< app:bist_tbl_1_correctable for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_TBL_1_UNCORRECTABLE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_TBL_1_UNCORRECTABLE), ///< app:bist_tbl_1_uncorrectable for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_TBL_2_CORRECTABLE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_TBL_2_CORRECTABLE), ///< app:bist_tbl_2_correctable for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_BIST_TBL_2_UNCORRECTABLE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_BIST_TBL_2_UNCORRECTABLE), ///< app:bist_tbl_2_uncorrectable for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_APP_PATROL_SCRUB_COMPLETE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_APP_PATROL_SCRUB_COMPLETE), ///< app:patrol_scrub_complete for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_BRESP_SEL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_BRESP_SEL), ///< dmr_corrected:dmr_s0_bresp_sel for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_CORR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_CORR), ///< dmr_corrected:dmr_s0_corr for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_DROP_BRESP = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_DROP_BRESP), ///< dmr_corrected:dmr_s0_drop_bresp for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_DROP_R = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_DROP_R), ///< dmr_corrected:dmr_s0_drop_r for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_RDATA_SEL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S0_RDATA_SEL), ///< dmr_corrected:dmr_s0_rdata_sel for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_BRESP_SEL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_BRESP_SEL), ///< dmr_corrected:dmr_s1_bresp_sel for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_CORR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_CORR), ///< dmr_corrected:dmr_s1_corr for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_DROP_BRESP = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_DROP_BRESP), ///< dmr_corrected:dmr_s1_drop_bresp for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_DROP_R = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_DROP_R), ///< dmr_corrected:dmr_s1_drop_r for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_RDATA_SEL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S1_RDATA_SEL), ///< dmr_corrected:dmr_s1_rdata_sel for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S_RPARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_S_RPARITY), ///< dmr_corrected:dmr_s_rparity for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_CORRECTED_DMR_SUBS_MM_STATUS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_CORRECTED_DMR_SUBS_MM_STATUS), ///< dmr_corrected:dmr_subs_mm_status for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_BID = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_BID), ///< dmr_uncorrected:dmr_mm_bid for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_BRESP = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_BRESP), ///< dmr_uncorrected:dmr_mm_bresp for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_EXOKAY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_EXOKAY), ///< dmr_uncorrected:dmr_mm_exokay for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RDATA = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RDATA), ///< dmr_uncorrected:dmr_mm_rdata for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RID = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RID), ///< dmr_uncorrected:dmr_mm_rid for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RRESP = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_MM_RRESP), ///< dmr_uncorrected:dmr_mm_rresp for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S0_STUCK = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S0_STUCK), ///< dmr_uncorrected:dmr_s0_stuck for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S0_UNCORR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S0_UNCORR), ///< dmr_uncorrected:dmr_s0_uncorr for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S1_STUCK = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S1_STUCK), ///< dmr_uncorrected:dmr_s1_stuck for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S1_UNCORR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_S1_UNCORR), ///< dmr_uncorrected:dmr_s1_uncorr for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_SUBS_UNCORR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_DMR_UNCORRECTED_DMR_SUBS_UNCORR), ///< dmr_uncorrected:dmr_subs_uncorr for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR), ///< emon_corrected:emon_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL), ///< emon_corrected:emon_cor_buf_full for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THLD = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THLD), ///< emon_corrected:emon_cor_buf_high_thld for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW), ///< emon_corrected:emon_cor_buf_ovrflw for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_FSM_ERR), ///< emon_corrected:emon_fsm_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL), ///< emon_corrected:emon_stat_buf_full for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW), ///< emon_corrected:emon_stat_buf_ovrflw for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL), ///< emon_corrected:emon_uncor_buf_full for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THLD = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THLD), ///< emon_corrected:emon_uncor_buf_high_thld for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW), ///< emon_corrected:emon_uncor_buf_ovrflw for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_UNCORRECTED_EMON_ADDR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_UNCORRECTED_EMON_ADDR_ERR), ///< emon_uncorrected:emon_addr_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_EMON_UNCORRECTED_EMON_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_EMON_UNCORRECTED_EMON_UNCOR), ///< emon_uncorrected:emon_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_ENC_ADDR_PARITY_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_ENC_ADDR_PARITY_ERR), ///< fault:enc_addr_parity_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_ENC_DATA_PARITY_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_ENC_DATA_PARITY_ERR), ///< fault:enc_data_parity_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_ENC_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_ENC_FSM_ERR), ///< fault:enc_fsm_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_ERR_REMOVE_READ_COH = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_ERR_REMOVE_READ_COH), ///< fault:err_remove_read_coh for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_ERR_REMOVE_WRITE_COH = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_ERR_REMOVE_WRITE_COH), ///< fault:err_remove_write_coh for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_PATROL_SCRUB_FSM_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_PATROL_SCRUB_FSM_ERR), ///< fault:patrol_scrub_fsm_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RARB_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RARB_ERR), ///< fault:rarb_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RDCAP_CTX_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RDCAP_CTX_OVERFLOW), ///< fault:rdcap_ctx_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RDCAP_CTX_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RDCAP_CTX_UNDERFLOW), ///< fault:rdcap_ctx_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RDGEN_CTX_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RDGEN_CTX_OVERFLOW), ///< fault:rdgen_ctx_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RDGEN_CTX_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RDGEN_CTX_UNDERFLOW), ///< fault:rdgen_ctx_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RMW_CTX_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RMW_CTX_OVERFLOW), ///< fault:rmw_ctx_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RMW_CTX_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RMW_CTX_UNDERFLOW), ///< fault:rmw_ctx_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RMW_RDCAP_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RMW_RDCAP_OVERFLOW), ///< fault:rmw_rdcap_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_RMW_RDCAP_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_RMW_RDCAP_UNDERFLOW), ///< fault:rmw_rdcap_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WARB_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WARB_ERR), ///< fault:warb_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDCAP_CTX_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDCAP_CTX_OVERFLOW), ///< fault:wdcap_ctx_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDCAP_CTX_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDCAP_CTX_UNDERFLOW), ///< fault:wdcap_ctx_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDCAP_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDCAP_OVERFLOW), ///< fault:wdcap_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDCAP_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDCAP_UNDERFLOW), ///< fault:wdcap_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDGEN_CTX_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDGEN_CTX_OVERFLOW), ///< fault:wdgen_ctx_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDGEN_CTX_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDGEN_CTX_UNDERFLOW), ///< fault:wdgen_ctx_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDRESP_CTX_OVERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDRESP_CTX_OVERFLOW), ///< fault:wdresp_ctx_overflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_WDRESP_CTX_UNDERFLOW = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_WDRESP_CTX_UNDERFLOW), ///< fault:wdresp_ctx_underflow for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_BCH_ENC_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_BCH_ENC_BUS_ECC_COR), ///< fault_corrected:bch_enc_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_RCMD_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_RCMD_BUS_ECC_COR), ///< fault_corrected:rcmd_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_RDCAP_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_RDCAP_BUS_ECC_COR), ///< fault_corrected:rdcap_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_SECDED_ENC_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_SECDED_ENC_BUS_ECC_COR), ///< fault_corrected:secded_enc_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_WCMD_CAP_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_WCMD_CAP_BUS_ECC_COR), ///< fault_corrected:wcmd_cap_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_WCMD_GEN_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_WCMD_GEN_BUS_ECC_COR), ///< fault_corrected:wcmd_gen_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_WDCAP_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_WDCAP_BUS_ECC_COR), ///< fault_corrected:wdcap_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_WDGEN_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_WDGEN_BUS_ECC_COR), ///< fault_corrected:wdgen_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_FAULT_CORRECTED_WDRESP_BUS_ECC_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_FAULT_CORRECTED_WDRESP_BUS_ECC_COR), ///< fault_corrected:wdresp_bus_ecc_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_DEC_DATA_RAM_COR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_DEC_DATA_RAM_COR_ERR), ///< ram_corrected:dec_data_ram_cor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_EMON_COR_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_EMON_COR_RAM_COR), ///< ram_corrected:emon_cor_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_EMON_STAT_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_EMON_STAT_RAM_COR), ///< ram_corrected:emon_stat_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_EMON_UNCOR_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_EMON_UNCOR_RAM_COR), ///< ram_corrected:emon_uncor_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_ENC_DATA_RAM_COR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_ENC_DATA_RAM_COR_ERR), ///< ram_corrected:enc_data_ram_cor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_RDCAP_CTX_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_RDCAP_CTX_RAM_COR), ///< ram_corrected:rdcap_ctx_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_RMW_CTX_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_RMW_CTX_RAM_COR), ///< ram_corrected:rmw_ctx_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_RMW_DATA_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_RMW_DATA_RAM_COR), ///< ram_corrected:rmw_data_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_WDCAP_CTX_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_WDCAP_CTX_RAM_COR), ///< ram_corrected:wdcap_ctx_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_WDGEN_CTX_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_WDGEN_CTX_RAM_COR), ///< ram_corrected:wdgen_ctx_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_CORRECTED_WDRESP_CTX_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_CORRECTED_WDRESP_CTX_RAM_COR), ///< ram_corrected:wdresp_ctx_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCOR_ERR), ///< ram_uncorrected:dec_data_ram_uncor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_COR_RAM_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_COR_RAM_UNCOR_ERR), ///< ram_uncorrected:emon_cor_ram_uncor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_STAT_RAM_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_STAT_RAM_UNCOR_ERR), ///< ram_uncorrected:emon_stat_ram_uncor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_UNCOR_RAM_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_EMON_UNCOR_RAM_UNCOR_ERR), ///< ram_uncorrected:emon_uncor_ram_uncor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_ENC_DATA_RAM_UNCOR_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_ENC_DATA_RAM_UNCOR_ERR), ///< ram_uncorrected:enc_data_ram_uncor_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_RDCAP_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_RDCAP_CTX_RAM_UNCOR), ///< ram_uncorrected:rdcap_ctx_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_RDGEN_CTX_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_RDGEN_CTX_RAM_COR), ///< ram_uncorrected:rdgen_ctx_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_RDGEN_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_RDGEN_CTX_RAM_UNCOR), ///< ram_uncorrected:rdgen_ctx_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_RMW_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_RMW_CTX_RAM_UNCOR), ///< ram_uncorrected:rmw_ctx_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_RMW_DATA_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_RMW_DATA_RAM_UNCOR), ///< ram_uncorrected:rmw_data_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_CTX_RAM_UNCOR), ///< ram_uncorrected:wdcap_ctx_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_DATA_RAM_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_DATA_RAM_COR), ///< ram_uncorrected:wdcap_data_ram_cor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_DATA_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_WDCAP_DATA_RAM_UNCOR), ///< ram_uncorrected:wdcap_data_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_WDGEN_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_WDGEN_CTX_RAM_UNCOR), ///< ram_uncorrected:wdgen_ctx_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_RAM_UNCORRECTED_WDRESP_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_RAM_UNCORRECTED_WDRESP_CTX_RAM_UNCOR), ///< ram_uncorrected:wdresp_ctx_ram_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_READ_TIMEOUT_RCMD_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_READ_TIMEOUT_RCMD_TIMEOUT), ///< read_timeout:rcmd_timeout for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_READ_TIMEOUT_RDCAP_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_READ_TIMEOUT_RDCAP_TIMEOUT), ///< read_timeout:rdcap_timeout for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_BCH_ENC_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_BCH_ENC_BUS_ECC_UNCOR), ///< trans_drop:bch_enc_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_RCMD_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_RCMD_BUS_ECC_UNCOR), ///< trans_drop:rcmd_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_RCMD_DROP_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_RCMD_DROP_TRANS), ///< trans_drop:rcmd_drop_trans for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_RDCAP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_RDCAP_BUS_ECC_UNCOR), ///< trans_drop:rdcap_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_RDCAP_DROP_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_RDCAP_DROP_TRANS), ///< trans_drop:rdcap_drop_trans for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_RMW_CMD_CTX_ERR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_RMW_CMD_CTX_ERR), ///< trans_drop:rmw_cmd_ctx_err for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_SECDED_ENC_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_SECDED_ENC_BUS_ECC_UNCOR), ///< trans_drop:secded_enc_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WCMD_CAP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WCMD_CAP_BUS_ECC_UNCOR), ///< trans_drop:wcmd_cap_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WCMD_DROP_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WCMD_DROP_TRANS), ///< trans_drop:wcmd_drop_trans for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WCMD_GEN_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WCMD_GEN_BUS_ECC_UNCOR), ///< trans_drop:wcmd_gen_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WDCAP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WDCAP_BUS_ECC_UNCOR), ///< trans_drop:wdcap_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WDCAP_SPARSE_WRITE = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WDCAP_SPARSE_WRITE), ///< trans_drop:wdcap_sparse_write for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WDGEN_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WDGEN_BUS_ECC_UNCOR), ///< trans_drop:wdgen_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WDGEN_DROP_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WDGEN_DROP_TRANS), ///< trans_drop:wdgen_drop_trans for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WDRESP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WDRESP_BUS_ECC_UNCOR), ///< trans_drop:wdresp_bus_ecc_uncor for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_TRANS_DROP_WDRESP_DROP_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_TRANS_DROP_WDRESP_DROP_TRANS), ///< trans_drop:wdresp_drop_trans for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_WRITE_TIMEOUT_WCMD_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_WRITE_TIMEOUT_WCMD_TIMEOUT), ///< write_timeout:wcmd_timeout for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_WRITE_TIMEOUT_WDGEN_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_WRITE_TIMEOUT_WDGEN_TIMEOUT), ///< write_timeout:wdgen_timeout for instance sram_edac of structure from NVM
    RAS_ERR_ID_NVM_SRAM_EDAC_WRITE_TIMEOUT_WDRESP_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SRAM_EDAC, NVM_SRAM_EDAC_WRITE_TIMEOUT_WDRESP_TIMEOUT), ///< write_timeout:wdresp_timeout for instance sram_edac of structure from NVM
    RAS_ERR_ID_SEC_ANA_MON_MONITOR_ERROR_OPEN_PACKAGE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_ANA_MON, SEC_ANA_MON_MONITOR_ERROR_OPEN_PACKAGE), ///< monitor_error:open_package for instance ana_mon of structure from SEC
    RAS_ERR_ID_SEC_ANA_MON_MONITOR_ERROR_POWER_GLITCH = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_ANA_MON, SEC_ANA_MON_MONITOR_ERROR_POWER_GLITCH), ///< monitor_error:power_glitch for instance ana_mon of structure from SEC
    RAS_ERR_ID_SEC_ANA_MON_MONITOR_ERROR_VDD1P8_BROWNOUT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_ANA_MON, SEC_ANA_MON_MONITOR_ERROR_VDD1P8_BROWNOUT), ///< monitor_error:vdd1p8_brownout for instance ana_mon of structure from SEC
    RAS_ERR_ID_SEC_ANA_MON_MONITOR_ERROR_VDD_BROWNOUT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_ANA_MON, SEC_ANA_MON_MONITOR_ERROR_VDD_BROWNOUT), ///< monitor_error:vdd_brownout for instance ana_mon of structure from SEC
    RAS_ERR_ID_SEC_ANA_MON_MONITOR_ERROR_VOLTAGE_OUT_OF_RANGE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_ANA_MON, SEC_ANA_MON_MONITOR_ERROR_VOLTAGE_OUT_OF_RANGE), ///< monitor_error:voltage_out_of_range for instance ana_mon of structure from SEC
    RAS_ERR_ID_SEC_APB2JTAG_COM_SEQUENCE_ERROR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_APB2JTAG, SEC_APB2JTAG_COM_SEQUENCE_ERROR), ///< com_sequence:error for instance apb2jtag of structure from SEC
    RAS_ERR_ID_SEC_CMON_INITIALIZATION_CALIBRATION_FAILED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CMON, SEC_CMON_INITIALIZATION_CALIBRATION_FAILED), ///< initialization:calibration_failed for instance cmon of structure from SEC
    RAS_ERR_ID_SEC_CMON_MONITOR_ERROR_FREQ_OUT_OF_RANGE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CMON, SEC_CMON_MONITOR_ERROR_FREQ_OUT_OF_RANGE), ///< monitor_error:freq_out_of_range for instance cmon of structure from SEC
    RAS_ERR_ID_SEC_CMON_RECALIBRATION_FAILURE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CMON, SEC_CMON_RECALIBRATION_FAILURE), ///< recalibration:failure for instance cmon of structure from SEC
    RAS_ERR_ID_SEC_CSU_LOCK_LOCK = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CSU, SEC_CSU_LOCK_LOCK), ///< lock:lock for instance csu of structure from SEC
    RAS_ERR_ID_SEC_CSU_LOCK_LOCK_LOSS = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CSU, SEC_CSU_LOCK_LOCK_LOSS), ///< lock:lock_loss for instance csu of structure from SEC
    RAS_ERR_ID_SEC_CSU_OFFSETCAL_LOCK_LOCK = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CSU, SEC_CSU_OFFSETCAL_LOCK_LOCK), ///< offsetcal_lock:lock for instance csu of structure from SEC
    RAS_ERR_ID_SEC_CSU_OFFSETCAL_LOCK_LOCK_LOSS = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_CSU, SEC_CSU_OFFSETCAL_LOCK_LOCK_LOSS), ///< offsetcal_lock:lock_loss for instance csu of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_ECC_PROT_CHMEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_ECC_PROT_CHMEM), ///< corrected:ecc_prot_chmem for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_ECC_PROT_UIDMEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_ECC_PROT_UIDMEM), ///< corrected:ecc_prot_uidmem for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_MXIF1_BCH_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_MXIF1_BCH_PROT), ///< corrected:mxif1_bch_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_MXIF1_RCH0_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_MXIF1_RCH0_PROT), ///< corrected:mxif1_rch0_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_MXIF1_RCH1_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_MXIF1_RCH1_PROT), ///< corrected:mxif1_rch1_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_MXIF2_BCH_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_MXIF2_BCH_PROT), ///< corrected:mxif2_bch_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_MXIF2_RCH0_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_MXIF2_RCH0_PROT), ///< corrected:mxif2_rch0_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_CORRECTED_MXIF2_RCH1_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_CORRECTED_MXIF2_RCH1_PROT), ///< corrected:mxif2_rch1_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_DST_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_DST_DEC_ERR), ///< invalid_access:dst_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_DST_SLV_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_DST_SLV_ERR), ///< invalid_access:dst_slv_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_LLI_RD_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_LLI_RD_DEC_ERR), ///< invalid_access:lli_rd_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_LLI_WR_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_LLI_WR_DEC_ERR), ///< invalid_access:lli_wr_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SHADOWREG_OR_LLI_INVALID_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SHADOWREG_OR_LLI_INVALID_ERR), ///< invalid_access:shadowreg_or_lli_invalid_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_DEC_ERR), ///< invalid_access:slvif_commonreg_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_RD2WO_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_RD2WO_ERR), ///< invalid_access:slvif_commonreg_rd2wo_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_WR2RO_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_WR2RO_ERR), ///< invalid_access:slvif_commonreg_wr2ro_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_WRONHOLD_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_COMMONREG_WRONHOLD_ERR), ///< invalid_access:slvif_commonreg_wronhold_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_DEC_ERR), ///< invalid_access:slvif_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_MULTIBLKTYPE_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_MULTIBLKTYPE_ERR), ///< invalid_access:slvif_multiblktype_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_RD2RWO_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_RD2RWO_ERR), ///< invalid_access:slvif_rd2rwo_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_SHADOWREG_WRON_VALID_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_SHADOWREG_WRON_VALID_ERR), ///< invalid_access:slvif_shadowreg_wron_valid_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_UNDEFINEDREG_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_UNDEFINEDREG_DEC_ERR), ///< invalid_access:slvif_undefinedreg_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_WR2RO_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_WR2RO_ERR), ///< invalid_access:slvif_wr2ro_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_WRONCHEN_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_WRONCHEN_ERR), ///< invalid_access:slvif_wronchen_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SLVIF_WRONHOLD_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SLVIF_WRONHOLD_ERR), ///< invalid_access:slvif_wronhold_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SRC_DEC_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SRC_DEC_ERR), ///< invalid_access:src_dec_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_INVALID_ACCESS_SRC_SLV_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_INVALID_ACCESS_SRC_SLV_ERR), ///< invalid_access:src_slv_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF1_ARCH_PROT_ARREADY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF1_ARCH_PROT_ARREADY), ///< parity_error:mxif1_arch_prot_arready for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF1_AWCH_PROT_AWREADY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF1_AWCH_PROT_AWREADY), ///< parity_error:mxif1_awch_prot_awready for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF1_BCH_PROT_BVALID = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF1_BCH_PROT_BVALID), ///< parity_error:mxif1_bch_prot_bvalid for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF1_RCH_PROT_RVALID = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF1_RCH_PROT_RVALID), ///< parity_error:mxif1_rch_prot_rvalid for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF1_WCH_PROT_WREADY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF1_WCH_PROT_WREADY), ///< parity_error:mxif1_wch_prot_wready for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF2_ARCH_PROT_ARREADY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF2_ARCH_PROT_ARREADY), ///< parity_error:mxif2_arch_prot_arready for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF2_AWCH_PROT_AWREADY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF2_AWCH_PROT_AWREADY), ///< parity_error:mxif2_awch_prot_awready for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF2_BCH_PROT_BVALID = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF2_BCH_PROT_BVALID), ///< parity_error:mxif2_bch_prot_bvalid for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF2_RCH_PROT_RVALID = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF2_RCH_PROT_RVALID), ///< parity_error:mxif2_rch_prot_rvalid for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_MXIF2_WCH_PROT_WREADY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_MXIF2_WCH_PROT_WREADY), ///< parity_error:mxif2_wch_prot_wready for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_SLVIF_ADDRPARITY_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_SLVIF_ADDRPARITY_ERR), ///< parity_error:slvif_addrparity_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_SLVIF_COMMONREG_ADDRPARITY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_SLVIF_COMMONREG_ADDRPARITY), ///< parity_error:slvif_commonreg_addrparity for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_SLVIF_COMMONREG_WRPARITY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_SLVIF_COMMONREG_WRPARITY), ///< parity_error:slvif_commonreg_wrparity for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_PARITY_ERROR_SLVIF_WRPARITY_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_PARITY_ERROR_SLVIF_WRPARITY_ERR), ///< parity_error:slvif_wrparity_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_STATE_CH_ABORTED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_STATE_CH_ABORTED), ///< state:ch_aborted for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_STATE_CH_DISABLED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_STATE_CH_DISABLED), ///< state:ch_disabled for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_STATE_CH_LOCK_CLEARED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_STATE_CH_LOCK_CLEARED), ///< state:ch_lock_cleared for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_STATE_CH_SRC_SUSPENDED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_STATE_CH_SRC_SUSPENDED), ///< state:ch_src_suspended for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_STATE_CH_SUSPENDED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_STATE_CH_SUSPENDED), ///< state:ch_suspended for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_SUBORDINATE_ERROR_LLI_RD_SLV_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_SUBORDINATE_ERROR_LLI_RD_SLV_ERR), ///< subordinate_error:lli_rd_slv_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_SUBORDINATE_ERROR_LLI_WR_SLV_ERR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_SUBORDINATE_ERROR_LLI_WR_SLV_ERR), ///< subordinate_error:lli_wr_slv_err for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_ECC_PROT_CHMEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_ECC_PROT_CHMEM), ///< uncorrected:ecc_prot_chmem for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_ECC_PROT_UIDMEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_ECC_PROT_UIDMEM), ///< uncorrected:ecc_prot_uidmem for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_MXIF1_BCH_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_MXIF1_BCH_PROT), ///< uncorrected:mxif1_bch_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_MXIF1_RCH0_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_MXIF1_RCH0_PROT), ///< uncorrected:mxif1_rch0_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_MXIF1_RCH1_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_MXIF1_RCH1_PROT), ///< uncorrected:mxif1_rch1_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_MXIF2_BCH_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_MXIF2_BCH_PROT), ///< uncorrected:mxif2_bch_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_MXIF2_RCH0_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_MXIF2_RCH0_PROT), ///< uncorrected:mxif2_rch0_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_DMA_UNCORRECTED_MXIF2_RCH1_PROT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_DMA, SEC_DMA_UNCORRECTED_MXIF2_RCH1_PROT), ///< uncorrected:mxif2_rch1_prot for instance dma of structure from SEC
    RAS_ERR_ID_SEC_MESH_TAMPER_DETECTION_MESH_MISMATCH = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_MESH, SEC_MESH_TAMPER_DETECTION_MESH_MISMATCH), ///< tamper_detection:mesh_mismatch for instance mesh of structure from SEC
    RAS_ERR_ID_SEC_NOC_BIST_FAILURE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_NOC, SEC_NOC_BIST_FAILURE), ///< bist:failure for instance noc of structure from SEC
    RAS_ERR_ID_SEC_NOC_TRANSACTION_TIMEOUT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_NOC, SEC_NOC_TRANSACTION_TIMEOUT), ///< transaction:timeout for instance noc of structure from SEC
    RAS_ERR_ID_SEC_OCR_BACK_PRESSURE_THRESHOLD_REACHED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_BACK_PRESSURE_THRESHOLD_REACHED), ///< back_pressure:threshold_reached for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_CORRECTED_READ = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_CORRECTED_READ), ///< corrected:read for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_CORRECTED_WRITE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_CORRECTED_WRITE), ///< corrected:write for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_ACCESS_READ_FAILURE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_ACCESS_READ_FAILURE), ///< fifo_access:read_failure for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_OVERFLOW_AXI_READ = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_OVERFLOW_AXI_READ), ///< fifo_overflow:axi_read for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_OVERFLOW_AXI_WRITE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_OVERFLOW_AXI_WRITE), ///< fifo_overflow:axi_write for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_OVERFLOW_MEL = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_OVERFLOW_MEL), ///< fifo_overflow:mel for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_OVERFLOW_SELF_SCRUB = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_OVERFLOW_SELF_SCRUB), ///< fifo_overflow:self_scrub for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_UNDERFLOW_AXI_READ = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_UNDERFLOW_AXI_READ), ///< fifo_underflow:axi_read for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_FIFO_UNDERFLOW_AXI_WRITE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_FIFO_UNDERFLOW_AXI_WRITE), ///< fifo_underflow:axi_write for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS), ///< invalid_access:unavailable_access for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_UNCORRECTED_READ = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_UNCORRECTED_READ), ///< uncorrected:read for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_OCR_UNCORRECTED_WRITE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_OCR, SEC_OCR_UNCORRECTED_WRITE), ///< uncorrected:write for instance ocr of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_API_PREREQUISITE_NOT_MET = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_API_PREREQUISITE_NOT_MET), ///< security:api_prerequisite_not_met for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_BUSY_WITH_OTHER_APPLICATION = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_BUSY_WITH_OTHER_APPLICATION), ///< security:busy_with_other_application for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_DATA_COMM_RECEIVE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_DATA_COMM_RECEIVE), ///< security:data_comm_receive for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_DATA_COMM_SEND = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_DATA_COMM_SEND), ///< security:data_comm_send for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_DOWNLOAD_NOT_ALLOWED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_DOWNLOAD_NOT_ALLOWED), ///< security:download_not_allowed for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_DRBG_REQUIRE_RESEED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_DRBG_REQUIRE_RESEED), ///< security:drbg_require_reseed for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_EXCEPTION_OCCURRED_RESETTING = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_EXCEPTION_OCCURRED_RESETTING), ///< security:exception_occurred_resetting for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INCOMPATIBLE_BINARY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INCOMPATIBLE_BINARY), ///< security:incompatible_binary for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INCOMPATIBLE_KEY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INCOMPATIBLE_KEY), ///< security:incompatible_key for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INSUFFICIENT_CONTEXT_MEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INSUFFICIENT_CONTEXT_MEM), ///< security:insufficient_context_mem for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INSUFFICIENT_IO_MEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INSUFFICIENT_IO_MEM), ///< security:insufficient_io_mem for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INSUFFICIENT_KEY_MEM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INSUFFICIENT_KEY_MEM), ///< security:insufficient_key_mem for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INTERNAL_ERROR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INTERNAL_ERROR), ///< security:internal_error for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INVALID_CONTEXT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INVALID_CONTEXT), ///< security:invalid_context for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_INVALID_KEY = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_INVALID_KEY), ///< security:invalid_key for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_KEY_ENCRYPTION_KEY_NOT_SET = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_KEY_ENCRYPTION_KEY_NOT_SET), ///< security:key_encryption_key_not_set for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_MEMORY_CORRUPTION = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_MEMORY_CORRUPTION), ///< security:memory_corruption for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_NO_APPLICATION_RUNNING = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_NO_APPLICATION_RUNNING), ///< security:no_application_running for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_NOT_READY_ERROR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_NOT_READY_ERROR), ///< security:not_ready_error for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_NOT_SUPPORTED_YET = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_NOT_SUPPORTED_YET), ///< security:not_supported_yet for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_OUTPUT_BUFFER_SMALL = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_OUTPUT_BUFFER_SMALL), ///< security:output_buffer_small for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_RESET_NEEDED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_RESET_NEEDED), ///< security:reset_needed for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_SELF_TEST_FAILED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_SELF_TEST_FAILED), ///< security:self_test_failed for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_SERVICE_NOT_FOUND = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_SERVICE_NOT_FOUND), ///< security:service_not_found for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_SERVICE_NOT_SUPPORTED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_SERVICE_NOT_SUPPORTED), ///< security:service_not_supported for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_UNSUPPORTED_ALGO = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_UNSUPPORTED_ALGO), ///< security:unsupported_algo for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_UNSUPPORTED_ALGO_PARAM = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_UNSUPPORTED_ALGO_PARAM), ///< security:unsupported_algo_param for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_UNSUPPORTED_DATA_INTERFACE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_UNSUPPORTED_DATA_INTERFACE), ///< security:unsupported_data_interface for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_UNSUPPORTED_DRBG_SECURITY_STRENGTH = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_UNSUPPORTED_DRBG_SECURITY_STRENGTH), ///< security:unsupported_drbg_security_strength for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_UNSUPPORTED_FORMAT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_UNSUPPORTED_FORMAT), ///< security:unsupported_format for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_UNSUPPORTED_KEY_TYPE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_UNSUPPORTED_KEY_TYPE), ///< security:unsupported_key_type for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_VERIFICATION_FAILED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_VERIFICATION_FAILED), ///< security:verification_failed for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_WRAPQ_PUBLIC_KEY_ABSENT = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_WRAPQ_PUBLIC_KEY_ABSENT), ///< security:wrapq_public_key_absent for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_WRONG_DIGEST_SIZE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_WRONG_DIGEST_SIZE), ///< security:wrong_digest_size for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_WRONG_ENTROPY_INTERFACE_USED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_WRONG_ENTROPY_INTERFACE_USED), ///< security:wrong_entropy_interface_used for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_WRONG_PARAMETER_VALUE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_WRONG_PARAMETER_VALUE), ///< security:wrong_parameter_value for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_PQS_SECURITY_ZEROISATION_TRIGGERED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_PQS, SEC_PQS_SECURITY_ZEROISATION_TRIGGERED), ///< security:zeroisation_triggered for instance pqs of structure from SEC
    RAS_ERR_ID_SEC_RAM_CORRECTED_RAM_ECC = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_RAM, SEC_RAM_CORRECTED_RAM_ECC), ///< corrected:ram_ecc for instance ram of structure from SEC
    RAS_ERR_ID_SEC_RAM_UNCORRECTED_RAM_ECC = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_RAM, SEC_RAM_UNCORRECTED_RAM_ECC), ///< uncorrected:ram_ecc for instance ram of structure from SEC
    RAS_ERR_ID_SEC_S7_D_CACHE_CORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_D_CACHE_CORRECTABLE), ///< d_cache:correctable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_D_CACHE_UNCORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_D_CACHE_UNCORRECTABLE), ///< d_cache:uncorrectable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_DTIM_CORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_DTIM_CORRECTABLE), ///< dtim:correctable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_DTIM_UNCORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_DTIM_UNCORRECTABLE), ///< dtim:uncorrectable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_I_CACHE_BUS_ERROR = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_I_CACHE_BUS_ERROR), ///< i_cache:bus_error for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_I_CACHE_CORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_I_CACHE_CORRECTABLE), ///< i_cache:correctable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_I_CACHE_UNCORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_I_CACHE_UNCORRECTABLE), ///< i_cache:uncorrectable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_ITIM_UNCORRECTABLE = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_ITIM_UNCORRECTABLE), ///< itim:uncorrectable for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_S7_TX_BUS_ERROR_LOAD_STORE_PTW = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_S7, SEC_S7_TX_BUS_ERROR_LOAD_STORE_PTW), ///< tx_bus_error:load_store_ptw for instance s7 of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_HW_LOCK = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_HW_LOCK), ///< tamper_detection:hw_lock for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_APPC_DEBUG = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_APPC_DEBUG), ///< tamper_detection:mismatch_perm_lock_appc_debug for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_PROD_TEST = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_PROD_TEST), ///< tamper_detection:mismatch_perm_lock_prod_test for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_SECC_DEBUG = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_SECC_DEBUG), ///< tamper_detection:mismatch_perm_lock_secc_debug for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_SYSC_DEBUG = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_MISMATCH_PERM_LOCK_SYSC_DEBUG), ///< tamper_detection:mismatch_perm_lock_sysc_debug for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_SW_LOCK = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_SW_LOCK), ///< tamper_detection:sw_lock for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_APPC_DEBUG = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_APPC_DEBUG), ///< tamper_detection:tamper_appc_debug for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_PROD_TEST = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_PROD_TEST), ///< tamper_detection:tamper_prod_test for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_SECC_DEBUG = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_SECC_DEBUG), ///< tamper_detection:tamper_secc_debug for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_SYSC_DEBUG = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_TAMPER_SYSC_DEBUG), ///< tamper_detection:tamper_sysc_debug for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TAMPER_MON_TAMPER_DETECTION_VSTART = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TAMPER_MON, SEC_TAMPER_MON_TAMPER_DETECTION_VSTART), ///< tamper_detection:vstart for instance tamper_mon of structure from SEC
    RAS_ERR_ID_SEC_TIMER_FIFO_OVERFLOW_CDC_BUFFER = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TIMER, SEC_TIMER_FIFO_OVERFLOW_CDC_BUFFER), ///< fifo_overflow:cdc_buffer for instance timer of structure from SEC
    RAS_ERR_ID_SEC_TVS_MON_MONITOR_ERROR_HIGH_TEMP = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TVS_MON, SEC_TVS_MON_MONITOR_ERROR_HIGH_TEMP), ///< monitor_error:high_temp for instance tvs_mon of structure from SEC
    RAS_ERR_ID_SEC_TVS_MON_MONITOR_ERROR_LOW_TEMP = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_TVS_MON, SEC_TVS_MON_MONITOR_ERROR_LOW_TEMP), ///< monitor_error:low_temp for instance tvs_mon of structure from SEC
    RAS_ERR_ID_SEC_WDOG_STATE_FIRST_WINDOW = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_WDOG, SEC_WDOG_STATE_FIRST_WINDOW), ///< state:first_window for instance wdog of structure from SEC
    RAS_ERR_ID_SEC_WDOG_STATE_FIRST_WINDOW_CLOSED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_WDOG, SEC_WDOG_STATE_FIRST_WINDOW_CLOSED), ///< state:first_window_closed for instance wdog of structure from SEC
    RAS_ERR_ID_SEC_WDOG_STATE_RESET_PENDING = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_WDOG, SEC_WDOG_STATE_RESET_PENDING), ///< state:reset_pending for instance wdog of structure from SEC
    RAS_ERR_ID_SEC_WDOG_STATE_RESET_REQUESTED = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_WDOG, SEC_WDOG_STATE_RESET_REQUESTED), ///< state:reset_requested for instance wdog of structure from SEC
    RAS_ERR_ID_SEC_WDOG_STATE_SECOND_WINDOW = RAS_ERROR_ENCODE(SEC, SEC_STRUCT_WDOG, SEC_WDOG_STATE_SECOND_WINDOW), ///< state:second_window for instance wdog of structure from SEC
    RAS_ERR_ID_SYS_OCR_BACK_PRESSURE_THRESHOLD_REACHED = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_BACK_PRESSURE_THRESHOLD_REACHED), ///< back_pressure:threshold_reached for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_CORRECTED_READ = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_CORRECTED_READ), ///< corrected:read for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_CORRECTED_WRITE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_CORRECTED_WRITE), ///< corrected:write for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_ACCESS_READ_FAILURE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_ACCESS_READ_FAILURE), ///< fifo_access:read_failure for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_OVERFLOW_AXI_READ = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_OVERFLOW_AXI_READ), ///< fifo_overflow:axi_read for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_OVERFLOW_AXI_WRITE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_OVERFLOW_AXI_WRITE), ///< fifo_overflow:axi_write for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_OVERFLOW_MEL = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_OVERFLOW_MEL), ///< fifo_overflow:mel for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_OVERFLOW_SELF_SCRUB = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_OVERFLOW_SELF_SCRUB), ///< fifo_overflow:self_scrub for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_UNDERFLOW_AXI_READ = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_UNDERFLOW_AXI_READ), ///< fifo_underflow:axi_read for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_FIFO_UNDERFLOW_AXI_WRITE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_FIFO_UNDERFLOW_AXI_WRITE), ///< fifo_underflow:axi_write for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_INVALID_ACCESS_UNAVAILABLE_ACCESS), ///< invalid_access:unavailable_access for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_UNCORRECTED_READ = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_UNCORRECTED_READ), ///< uncorrected:read for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_OCR_UNCORRECTED_WRITE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_OCR, SYS_OCR_UNCORRECTED_WRITE), ///< uncorrected:write for instance ocr of structure from SYS
    RAS_ERR_ID_SYS_S7_D_CACHE_CORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_D_CACHE_CORRECTABLE), ///< d_cache:correctable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_D_CACHE_UNCORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_D_CACHE_UNCORRECTABLE), ///< d_cache:uncorrectable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_DTIM_CORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_DTIM_CORRECTABLE), ///< dtim:correctable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_DTIM_UNCORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_DTIM_UNCORRECTABLE), ///< dtim:uncorrectable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_FW_EXEC = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_FW_EXEC), ///< fw:exec for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_I_CACHE_BUS_ERROR = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_I_CACHE_BUS_ERROR), ///< i_cache:bus_error for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_I_CACHE_CORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_I_CACHE_CORRECTABLE), ///< i_cache:correctable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_ITIM_CORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_ITIM_CORRECTABLE), ///< itim:correctable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_ITIM_UNCORRECTABLE = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_ITIM_UNCORRECTABLE), ///< itim:uncorrectable for instance s7 of structure from SYS
    RAS_ERR_ID_SYS_S7_TX_BUS_ERROR_LOAD_STORE_PTW = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_TX_BUS_ERROR_LOAD_STORE_PTW), ///< tx_bus_error:load_store_ptw for instance s7 of structure from SYS
    RAS_ERR_ID_LAST
} p64h_ras_err_id_t;

typedef struct __attribute__((packed)) {
    uint32_t err_evt:RAS_ERR_PACK_EVT_ID_LEN; ///< Error event ID
    uint32_t sev:RAS_ERR_PACK_SEV_ID_LEN; ///< Severity
    uint32_t struc_inst:RAS_ERR_PACK_STRUCT_INST_ID_LEN; ///< Structure instance
    uint32_t struc:RAS_ERR_PACK_STRUCT_ID_LEN; ///< Structure ID
    uint32_t src:RAS_ERR_PACK_SRC_ID_LEN; ///< Error source ID
} p64h_sysc_ras_error_pack_t;
static_assert(sizeof(p64h_sysc_ras_error_pack_t) == 4, "p64h_sysc_ras_error_pack_t != 4 bytes");

/// @brief Union to faciliate reading a unique RAS error code
typedef union {
    uint32_t w; ///< Word access
    p64h_sysc_ras_error_pack_t b; ///< Bitfield access
} p64h_sysc_ras_error_code_t;

#endif /* RAS_ERR_SRC_H */
