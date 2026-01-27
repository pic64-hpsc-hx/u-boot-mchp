/* (c) 2026 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef RAS_ERR_SRC_H
#define RAS_ERR_SRC_H

#include <assert.h>

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
    DDR = 4, ///< DDR generic hardware error source
    DDR_NOC = 5, ///< DDR_NOC generic hardware error source
    ENET = 6, ///< ENET generic hardware error source
    NVM = 7, ///< NVM generic hardware error source
    SEC = 8, ///< SEC generic hardware error source
    SYS = 9, ///< SYS generic hardware error source
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
 * @brief Definitions of all structures within the DDR GHES
 */
typedef enum {
    DDR_STRUCT_EDAC = 0, ///< EDAC structure ID from the DDR
     DDR_STRUCT_CTRL = 1, ///< CTRL structure ID from the DDR
     DDR_STRUCT_LAST ///< Last value for possible structure within the ddr GHE
} p64h_ras_ddr_struc_t;

/**
 * @brief Definitions of all structures within the DDR_NOC GHES
 */
typedef enum {
    DDR_NOC_STRUCT_INITIATORS = 0, ///< INITIATORS structure ID from the DDR_NOC
     DDR_NOC_STRUCT_TARGETS = 1, ///< TARGETS structure ID from the DDR_NOC
     DDR_NOC_STRUCT_LAST ///< Last value for possible structure within the ddr_noc GHE
} p64h_ras_ddr_noc_struc_t;

/**
 * @brief Definitions of all structures within the ENET GHES
 */
typedef enum {
    ENET_STRUCT_ASM = 0, ///< ASM structure ID from the ENET
     ENET_STRUCT_ANA_AC_EACL_REW_WRAP = 1, ///< ANA_AC_EACL_REW_WRAP structure ID from the ENET
     ENET_STRUCT_SQS = 2, ///< SQS structure ID from the ENET
     ENET_STRUCT_EACL = 3, ///< EACL structure ID from the ENET
     ENET_STRUCT_DSM = 4, ///< DSM structure ID from the ENET
     ENET_STRUCT_VCAP_SUPER = 5, ///< VCAP_SUPER structure ID from the ENET
     ENET_STRUCT_PIER_RDMA = 6, ///< PIER_RDMA structure ID from the ENET
     ENET_STRUCT_PIER_RDMA_MISC = 7, ///< PIER_RDMA_MISC structure ID from the ENET
     ENET_STRUCT_ANACL32OAM = 8, ///< ANACL32OAM structure ID from the ENET
     ENET_STRUCT_MISC = 9, ///< MISC structure ID from the ENET
     ENET_STRUCT_LAST ///< Last value for possible structure within the enet GHE
} p64h_ras_enet_struc_t;

/**
 * @brief Definitions of all structures within the NVM GHES
 */
typedef enum {
    NVM_STRUCT_SRAM_EDAC = 0, ///< SRAM_EDAC structure ID from the NVM
     NVM_STRUCT_NVM_EDAC = 1, ///< NVM_EDAC structure ID from the NVM
     NVM_STRUCT_PFLASH_CTRL = 2, ///< PFLASH_CTRL structure ID from the NVM
     NVM_STRUCT_SPI_CTRL = 3, ///< SPI_CTRL structure ID from the NVM
     NVM_STRUCT_NAND_CTRL = 4, ///< NAND_CTRL structure ID from the NVM
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
    p64h_ras_ddr_struc_t ddr_struc; ///< ddr structure IDs
    p64h_ras_ddr_noc_struc_t ddr_noc_struc; ///< ddr_noc structure IDs
    p64h_ras_enet_struc_t enet_struc; ///< enet structure IDs
    p64h_ras_nvm_struc_t nvm_struc; ///< nvm structure IDs
    p64h_ras_sec_struc_t sec_struc; ///< sec structure IDs
    p64h_ras_sys_struc_t sys_struc; ///< sys structure IDs
} p64h_ras_generic_struc_id_t;

/**
 * @brief Definitions of all errors within a structure of the APP_MEM GHES
 */
typedef enum {
    APP_MEM_OCR_0 = 0, ///< Instance 0 of structure ocr
    APP_MEM_OCR_1, ///< Instance 1 of structure ocr
    APP_MEM_OCR_INST_LAST, ///< Number of possible instances within the OCR structure of the APP_MEM GH
} p64h_ras_app_mem_ocr_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_NOC GHES
 */
typedef enum {
    APP_NOC_WGC_DDR_CFG_WG_ERR = 0, ///< Instance ddr_cfg_wg_err of structure wgc
    APP_NOC_WGC_DDR_ENCRYPT_HP_CSR_WG_ERR, ///< Instance ddr_encrypt_hp_csr_wg_err of structure wgc
    APP_NOC_WGC_DDR_ENCRYPT_T_WG_ERR, ///< Instance ddr_encrypt_t_wg_err of structure wgc
    APP_NOC_WGC_ENET_EP_CFG_WG_ERR, ///< Instance enet_ep_cfg_wg_err of structure wgc
    APP_NOC_WGC_ENET_SWR_RDMA1_MCHP_CFG_WG_ERR, ///< Instance enet_swr_rdma1_mchp_cfg_wg_err of structure wgc
    APP_NOC_WGC_ENET_SWR_RDMA1_ROCE_COMMAND_WG_ERR, ///< Instance enet_swr_rdma1_roce_command_wg_err of structure wgc
    APP_NOC_WGC_ENET_SWR_RDMA2_MCHP_CFG_WG_ERR, ///< Instance enet_swr_rdma2_mchp_cfg_wg_err of structure wgc
    APP_NOC_WGC_ENET_SWR_RDMA2_ROCE_COMMAND_WG_ERR, ///< Instance enet_swr_rdma2_roce_command_wg_err of structure wgc
    APP_NOC_WGC_ENET_SWR_SWITCH_CFG_WG_ERR, ///< Instance enet_swr_switch_cfg_wg_err of structure wgc
    APP_NOC_WGC_ENET_SWR_TOP_CFG_WG_ERR, ///< Instance enet_swr_top_cfg_wg_err of structure wgc
    APP_NOC_WGC_IOMMU_0_CFG_WG_ERR, ///< Instance iommu_0_cfg_wg_err of structure wgc
    APP_NOC_WGC_IOMMU_1_CFG_WG_ERR, ///< Instance iommu_1_cfg_wg_err of structure wgc
    APP_NOC_WGC_IOMMU_SS_CFG_WG_ERR, ///< Instance iommu_ss_cfg_wg_err of structure wgc
    APP_NOC_WGC_M2_HP_SPW_CSR_WG_ERR, ///< Instance m2_hp_spw_csr_wg_err of structure wgc
    APP_NOC_WGC_M2_JTAG_SPI_WG_ERR, ///< Instance m2_jtag_spi_wg_err of structure wgc
    APP_NOC_WGC_M2_OTHER_0_WG_ERR, ///< Instance m2_other_0_wg_err of structure wgc
    APP_NOC_WGC_M2_OTHER_1_WG_ERR, ///< Instance m2_other_1_wg_err of structure wgc
    APP_NOC_WGC_M3_APPDMA0_HP_CSR_WG_ERR, ///< Instance m3_appdma0_hp_csr_wg_err of structure wgc
    APP_NOC_WGC_M3_APPDMA1_HP_CSR_WG_ERR, ///< Instance m3_appdma1_hp_csr_wg_err of structure wgc
    APP_NOC_WGC_M3_IPC_0_WG_ERR, ///< Instance m3_ipc_0_wg_err of structure wgc
    APP_NOC_WGC_M3_IPC_1_WG_ERR, ///< Instance m3_ipc_1_wg_err of structure wgc
    APP_NOC_WGC_M3_NMRA0_T_WG_ERR, ///< Instance m3_nmra0_t_wg_err of structure wgc
    APP_NOC_WGC_M3_NMRA1_T_WG_ERR, ///< Instance m3_nmra1_t_wg_err of structure wgc
    APP_NOC_WGC_M3_OCR0_MEM_WG_ERR, ///< Instance m3_ocr0_mem_wg_err of structure wgc
    APP_NOC_WGC_M3_OCR1_MEM_WG_ERR, ///< Instance m3_ocr1_mem_wg_err of structure wgc
    APP_NOC_WGC_M3_OTHER_WG_ERR, ///< Instance m3_other_wg_err of structure wgc
    APP_NOC_WGC_NVM_EDAC0_WG_ERR, ///< Instance nvm_edac0_wg_err of structure wgc
    APP_NOC_WGC_NVM_EDAC1_WG_ERR, ///< Instance nvm_edac1_wg_err of structure wgc
    APP_NOC_WGC_NVM_SRAM_EDAC0_0_WG_ERR, ///< Instance nvm_sram_edac0_0_wg_err of structure wgc
    APP_NOC_WGC_NVM_SRAM_EDAC0_1_WG_ERR, ///< Instance nvm_sram_edac0_1_wg_err of structure wgc
    APP_NOC_WGC_NVM_SRAM_EDAC1_0_WG_ERR, ///< Instance nvm_sram_edac1_0_wg_err of structure wgc
    APP_NOC_WGC_NVM_SRAM_EDAC1_1_WG_ERR, ///< Instance nvm_sram_edac1_1_wg_err of structure wgc
    APP_NOC_WGC_NVM_SRAM_EDAC2_0_WG_ERR, ///< Instance nvm_sram_edac2_0_wg_err of structure wgc
    APP_NOC_WGC_NVM_SRAM_EDAC2_1_WG_ERR, ///< Instance nvm_sram_edac2_1_wg_err of structure wgc
    APP_NOC_WGC_NVM_SS_CFG_WG_ERR, ///< Instance nvm_ss_cfg_wg_err of structure wgc
    APP_NOC_WGC_PCIE0_CFG_WG_ERR, ///< Instance pcie0_cfg_wg_err of structure wgc
    APP_NOC_WGC_PCIE0_CTL0_T_WG_ERR, ///< Instance pcie0_ctl0_t_wg_err of structure wgc
    APP_NOC_WGC_PCIE0_CTL1_T_WG_ERR, ///< Instance pcie0_ctl1_t_wg_err of structure wgc
    APP_NOC_WGC_PCIE1_CFG_WG_ERR, ///< Instance pcie1_cfg_wg_err of structure wgc
    APP_NOC_WGC_PCIE1_CTL0_T_WG_ERR, ///< Instance pcie1_ctl0_t_wg_err of structure wgc
    APP_NOC_WGC_PCIE1_CTL1_T_WG_ERR, ///< Instance pcie1_ctl1_t_wg_err of structure wgc
    APP_NOC_WGC_SVC_NOC_EDAC_WG_ERR, ///< Instance svc_noc_edac_wg_err of structure wgc
    APP_NOC_WGC_USER_CRYPTO_CFG_WG_ERR, ///< Instance user_crypto_cfg_wg_err of structure wgc
    APP_NOC_WGC_USER_CRYPTO_T_WG_ERR, ///< Instance user_crypto_t_wg_err of structure wgc
    APP_NOC_WGC_WG_ERR_0, ///< Instance wg_err_0 of structure wgc
    APP_NOC_WGC_WG_ERR_1, ///< Instance wg_err_1 of structure wgc
    APP_NOC_WGC_WG_ERR_2, ///< Instance wg_err_2 of structure wgc
    APP_NOC_WGC_WG_ERR_3, ///< Instance wg_err_3 of structure wgc
    APP_NOC_WGC_WG_WID_DED, ///< Instance wg_wid_ded of structure wgc
    APP_NOC_WGC_WG_WID_SEC, ///< Instance wg_wid_sec of structure wgc
    APP_NOC_WGC_INST_LAST, ///< Number of possible instances within the WGC structure of the APP_NOC GH
} p64h_ras_app_noc_wgc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_FABRIC_0 = 0, ///< Instance 0 of structure fabric
    APP_X288_FABRIC_1, ///< Instance 1 of structure fabric
    APP_X288_FABRIC_INST_LAST, ///< Number of possible instances within the FABRIC structure of the APP_X288 GH
} p64h_ras_app_x288_fabric_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_IOMMU_IOMMU_0 = 0, ///< Instance iommu_0 of structure iommu
    APP_X288_IOMMU_IOMMU_1, ///< Instance iommu_1 of structure iommu
    APP_X288_IOMMU_INST_LAST, ///< Number of possible instances within the IOMMU structure of the APP_X288 GH
} p64h_ras_app_x288_iommu_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_LOCKSTEP_0 = 0, ///< Instance 0 of structure lockstep
    APP_X288_LOCKSTEP_1, ///< Instance 1 of structure lockstep
    APP_X288_LOCKSTEP_2, ///< Instance 2 of structure lockstep
    APP_X288_LOCKSTEP_3, ///< Instance 3 of structure lockstep
    APP_X288_LOCKSTEP_INST_LAST, ///< Number of possible instances within the LOCKSTEP structure of the APP_X288 GH
} p64h_ras_app_x288_lockstep_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_TILE_0 = 0, ///< Instance 0 of structure tile
    APP_X288_TILE_1, ///< Instance 1 of structure tile
    APP_X288_TILE_2, ///< Instance 2 of structure tile
    APP_X288_TILE_3, ///< Instance 3 of structure tile
    APP_X288_TILE_4, ///< Instance 4 of structure tile
    APP_X288_TILE_5, ///< Instance 5 of structure tile
    APP_X288_TILE_6, ///< Instance 6 of structure tile
    APP_X288_TILE_7, ///< Instance 7 of structure tile
    APP_X288_TILE_INST_LAST, ///< Number of possible instances within the TILE structure of the APP_X288 GH
} p64h_ras_app_x288_tile_inst_t;

/**
 * @brief Definitions of all errors within a structure of the APP_X288 GHES
 */
typedef enum {
    APP_X288_WGC_APLIC_C0 = 0, ///< Instance aplic_c0 of structure wgc
    APP_X288_WGC_APLIC_C1, ///< Instance aplic_c1 of structure wgc
    APP_X288_WGC_CLINT_C0, ///< Instance clint_c0 of structure wgc
    APP_X288_WGC_CLINT_C1, ///< Instance clint_c1 of structure wgc
    APP_X288_WGC_CXL_CACHE_CPI_C0, ///< Instance cxl_cache_cpi_c0 of structure wgc
    APP_X288_WGC_CXL_CACHE_CPI_C1, ///< Instance cxl_cache_cpi_c1 of structure wgc
    APP_X288_WGC_CXL_CACHE_TL2C_BRIDGE_C0, ///< Instance cxl_cache_tl2c_bridge_c0 of structure wgc
    APP_X288_WGC_CXL_CACHE_TL2C_BRIDGE_C1, ///< Instance cxl_cache_tl2c_bridge_c1 of structure wgc
    APP_X288_WGC_CXL_MEM_CPI_0_C0, ///< Instance cxl_mem_cpi_0_c0 of structure wgc
    APP_X288_WGC_CXL_MEM_CPI_0_C1, ///< Instance cxl_mem_cpi_0_c1 of structure wgc
    APP_X288_WGC_CXL_MEM_CPI_1_C0, ///< Instance cxl_mem_cpi_1_c0 of structure wgc
    APP_X288_WGC_CXL_MEM_CPI_1_C1, ///< Instance cxl_mem_cpi_1_c1 of structure wgc
    APP_X288_WGC_CXL_MEM_CPI_C0, ///< Instance cxl_mem_cpi_c0 of structure wgc
    APP_X288_WGC_CXL_MEM_CPI_C1, ///< Instance cxl_mem_cpi_c1 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_0_C0, ///< Instance ext_cache_slice_0_c0 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_0_C1, ///< Instance ext_cache_slice_0_c1 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_1_C0, ///< Instance ext_cache_slice_1_c0 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_1_C1, ///< Instance ext_cache_slice_1_c1 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_2_C0, ///< Instance ext_cache_slice_2_c0 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_2_C1, ///< Instance ext_cache_slice_2_c1 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_3_C0, ///< Instance ext_cache_slice_3_c0 of structure wgc
    APP_X288_WGC_EXT_CACHE_SLICE_3_C1, ///< Instance ext_cache_slice_3_c1 of structure wgc
    APP_X288_WGC_FP_CACHE_C0, ///< Instance fp_cache_c0 of structure wgc
    APP_X288_WGC_FP_CACHE_C1, ///< Instance fp_cache_c1 of structure wgc
    APP_X288_WGC_IMSIC_M_0_C0, ///< Instance imsic_m_0_c0 of structure wgc
    APP_X288_WGC_IMSIC_M_0_C1, ///< Instance imsic_m_0_c1 of structure wgc
    APP_X288_WGC_IMSIC_M_1_C0, ///< Instance imsic_m_1_c0 of structure wgc
    APP_X288_WGC_IMSIC_M_1_C1, ///< Instance imsic_m_1_c1 of structure wgc
    APP_X288_WGC_IMSIC_M_2_C0, ///< Instance imsic_m_2_c0 of structure wgc
    APP_X288_WGC_IMSIC_M_2_C1, ///< Instance imsic_m_2_c1 of structure wgc
    APP_X288_WGC_IMSIC_M_3_C0, ///< Instance imsic_m_3_c0 of structure wgc
    APP_X288_WGC_IMSIC_M_3_C1, ///< Instance imsic_m_3_c1 of structure wgc
    APP_X288_WGC_IMSIC_S_0_C0, ///< Instance imsic_s_0_c0 of structure wgc
    APP_X288_WGC_IMSIC_S_0_C1, ///< Instance imsic_s_0_c1 of structure wgc
    APP_X288_WGC_IMSIC_S_1_C0, ///< Instance imsic_s_1_c0 of structure wgc
    APP_X288_WGC_IMSIC_S_1_C1, ///< Instance imsic_s_1_c1 of structure wgc
    APP_X288_WGC_IMSIC_S_2_C0, ///< Instance imsic_s_2_c0 of structure wgc
    APP_X288_WGC_IMSIC_S_2_C1, ///< Instance imsic_s_2_c1 of structure wgc
    APP_X288_WGC_IMSIC_S_3_C0, ///< Instance imsic_s_3_c0 of structure wgc
    APP_X288_WGC_IMSIC_S_3_C1, ///< Instance imsic_s_3_c1 of structure wgc
    APP_X288_WGC_MEM_DEINTER_ERROR_BANK_C0, ///< Instance mem_deinter_error_bank_c0 of structure wgc
    APP_X288_WGC_MEM_DEINTER_ERROR_BANK_C1, ///< Instance mem_deinter_error_bank_c1 of structure wgc
    APP_X288_WGC_ROOT_ERROR_MAP_C0, ///< Instance root_error_map_c0 of structure wgc
    APP_X288_WGC_ROOT_ERROR_MAP_C1, ///< Instance root_error_map_c1 of structure wgc
    APP_X288_WGC_SMC_C0, ///< Instance smc_c0 of structure wgc
    APP_X288_WGC_SMC_C1, ///< Instance smc_c1 of structure wgc
    APP_X288_WGC_SYS_DEINTER_ERROR_BANK_C0, ///< Instance sys_deinter_error_bank_c0 of structure wgc
    APP_X288_WGC_SYS_DEINTER_ERROR_BANK_C1, ///< Instance sys_deinter_error_bank_c1 of structure wgc
    APP_X288_WGC_TEST_INDICATOR_C0, ///< Instance test_indicator_c0 of structure wgc
    APP_X288_WGC_TEST_INDICATOR_C1, ///< Instance test_indicator_c1 of structure wgc
    APP_X288_WGC_TILE_0_C0, ///< Instance tile_0_c0 of structure wgc
    APP_X288_WGC_TILE_0_C1, ///< Instance tile_0_c1 of structure wgc
    APP_X288_WGC_TILE_1_C0, ///< Instance tile_1_c0 of structure wgc
    APP_X288_WGC_TILE_1_C1, ///< Instance tile_1_c1 of structure wgc
    APP_X288_WGC_TILE_2_C0, ///< Instance tile_2_c0 of structure wgc
    APP_X288_WGC_TILE_2_C1, ///< Instance tile_2_c1 of structure wgc
    APP_X288_WGC_TILE_3_C0, ///< Instance tile_3_c0 of structure wgc
    APP_X288_WGC_TILE_3_C1, ///< Instance tile_3_c1 of structure wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_0_C0, ///< Instance tl2c_cxl_mem_bridge_0_c0 of structure wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_0_C1, ///< Instance tl2c_cxl_mem_bridge_0_c1 of structure wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_1_C0, ///< Instance tl2c_cxl_mem_bridge_1_c0 of structure wgc
    APP_X288_WGC_TL2C_CXL_MEM_BRIDGE_1_C1, ///< Instance tl2c_cxl_mem_bridge_1_c1 of structure wgc
    APP_X288_WGC_TMC_0_C0, ///< Instance tmc_0_c0 of structure wgc
    APP_X288_WGC_TMC_0_C1, ///< Instance tmc_0_c1 of structure wgc
    APP_X288_WGC_TMC_1_C0, ///< Instance tmc_1_c0 of structure wgc
    APP_X288_WGC_TMC_1_C1, ///< Instance tmc_1_c1 of structure wgc
    APP_X288_WGC_TMC_2_C0, ///< Instance tmc_2_c0 of structure wgc
    APP_X288_WGC_TMC_2_C1, ///< Instance tmc_2_c1 of structure wgc
    APP_X288_WGC_TMC_3_C0, ///< Instance tmc_3_c0 of structure wgc
    APP_X288_WGC_TMC_3_C1, ///< Instance tmc_3_c1 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_0_C0, ///< Instance trace_encoder_0_c0 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_0_C1, ///< Instance trace_encoder_0_c1 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_1_C0, ///< Instance trace_encoder_1_c0 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_1_C1, ///< Instance trace_encoder_1_c1 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_2_C0, ///< Instance trace_encoder_2_c0 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_2_C1, ///< Instance trace_encoder_2_c1 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_3_C0, ///< Instance trace_encoder_3_c0 of structure wgc
    APP_X288_WGC_TRACE_ENCODER_3_C1, ///< Instance trace_encoder_3_c1 of structure wgc
    APP_X288_WGC_TRACE_FUNNEL_0_C0, ///< Instance trace_funnel_0_c0 of structure wgc
    APP_X288_WGC_TRACE_FUNNEL_0_C1, ///< Instance trace_funnel_0_c1 of structure wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_0_C0, ///< Instance write_comb_buffer_0_c0 of structure wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_0_C1, ///< Instance write_comb_buffer_0_c1 of structure wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_1_C0, ///< Instance write_comb_buffer_1_c0 of structure wgc
    APP_X288_WGC_WRITE_COMB_BUFFER_1_C1, ///< Instance write_comb_buffer_1_c1 of structure wgc
    APP_X288_WGC_INST_LAST, ///< Number of possible instances within the WGC structure of the APP_X288 GH
} p64h_ras_app_x288_wgc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the CLOCK GHES
 */
typedef enum {
    CLOCK_CSU_APP = 0, ///< Instance app of structure csu
    CLOCK_CSU_CPU, ///< Instance cpu of structure csu
    CLOCK_CSU_EDAC, ///< Instance edac of structure csu
    CLOCK_CSU_ENET, ///< Instance enet of structure csu
    CLOCK_CSU_NVM0, ///< Instance nvm0 of structure csu
    CLOCK_CSU_NVM1, ///< Instance nvm1 of structure csu
    CLOCK_CSU_NVM2, ///< Instance nvm2 of structure csu
    CLOCK_CSU_SYS0, ///< Instance sys0 of structure csu
    CLOCK_CSU_SYS1, ///< Instance sys1 of structure csu
    CLOCK_CSU_SYSC, ///< Instance sysc of structure csu
    CLOCK_CSU_INST_LAST, ///< Number of possible instances within the CSU structure of the CLOCK GH
} p64h_ras_clock_csu_inst_t;

/**
 * @brief Definitions of all errors within a structure of the DDR GHES
 */
typedef enum {
    DDR_CTRL_0 = 0, ///< Instance 0 of structure ctrl
    DDR_CTRL_1, ///< Instance 1 of structure ctrl
    DDR_CTRL_INST_LAST, ///< Number of possible instances within the CTRL structure of the DDR GH
} p64h_ras_ddr_ctrl_inst_t;

/**
 * @brief Definitions of all errors within a structure of the DDR GHES
 */
typedef enum {
    DDR_EDAC_0 = 0, ///< Instance 0 of structure edac
    DDR_EDAC_1, ///< Instance 1 of structure edac
    DDR_EDAC_INST_LAST, ///< Number of possible instances within the EDAC structure of the DDR GH
} p64h_ras_ddr_edac_inst_t;

/**
 * @brief Definitions of all errors within a structure of the DDR_NOC GHES
 */
typedef enum {
    DDR_NOC_INITIATORS_0 = 0, ///< Instance 0 of structure initiators
    DDR_NOC_INITIATORS_1, ///< Instance 1 of structure initiators
    DDR_NOC_INITIATORS_2, ///< Instance 2 of structure initiators
    DDR_NOC_INITIATORS_3, ///< Instance 3 of structure initiators
    DDR_NOC_INITIATORS_4, ///< Instance 4 of structure initiators
    DDR_NOC_INITIATORS_INST_LAST, ///< Number of possible instances within the INITIATORS structure of the DDR_NOC GH
} p64h_ras_ddr_noc_initiators_inst_t;

/**
 * @brief Definitions of all errors within a structure of the DDR_NOC GHES
 */
typedef enum {
    DDR_NOC_TARGETS_0 = 0, ///< Instance 0 of structure targets
    DDR_NOC_TARGETS_1, ///< Instance 1 of structure targets
    DDR_NOC_TARGETS_INST_LAST, ///< Number of possible instances within the TARGETS structure of the DDR_NOC GH
} p64h_ras_ddr_noc_targets_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_ANA_AC_EACL_REW_WRAP_0 = 0, ///< Instance 0 of structure ana_ac_eacl_rew_wrap
    ENET_ANA_AC_EACL_REW_WRAP_INST_LAST, ///< Number of possible instances within the ANA_AC_EACL_REW_WRAP structure of the ENET GH
} p64h_ras_enet_ana_ac_eacl_rew_wrap_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_ANACL32OAM_0 = 0, ///< Instance 0 of structure anacl32oam
    ENET_ANACL32OAM_INST_LAST, ///< Number of possible instances within the ANACL32OAM structure of the ENET GH
} p64h_ras_enet_anacl32oam_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_ASM_0 = 0, ///< Instance 0 of structure asm
    ENET_ASM_INST_LAST, ///< Number of possible instances within the ASM structure of the ENET GH
} p64h_ras_enet_asm_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_DSM_0 = 0, ///< Instance 0 of structure dsm
    ENET_DSM_INST_LAST, ///< Number of possible instances within the DSM structure of the ENET GH
} p64h_ras_enet_dsm_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_EACL_0 = 0, ///< Instance 0 of structure eacl
    ENET_EACL_INST_LAST, ///< Number of possible instances within the EACL structure of the ENET GH
} p64h_ras_enet_eacl_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_MISC_0 = 0, ///< Instance 0 of structure misc
    ENET_MISC_INST_LAST, ///< Number of possible instances within the MISC structure of the ENET GH
} p64h_ras_enet_misc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_PIER_RDMA_0 = 0, ///< Instance 0 of structure pier_rdma
    ENET_PIER_RDMA_INST_LAST, ///< Number of possible instances within the PIER_RDMA structure of the ENET GH
} p64h_ras_enet_pier_rdma_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_PIER_RDMA_MISC_0 = 0, ///< Instance 0 of structure pier_rdma_misc
    ENET_PIER_RDMA_MISC_INST_LAST, ///< Number of possible instances within the PIER_RDMA_MISC structure of the ENET GH
} p64h_ras_enet_pier_rdma_misc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_SQS_0 = 0, ///< Instance 0 of structure sqs
    ENET_SQS_INST_LAST, ///< Number of possible instances within the SQS structure of the ENET GH
} p64h_ras_enet_sqs_inst_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_VCAP_SUPER_0 = 0, ///< Instance 0 of structure vcap_super
    ENET_VCAP_SUPER_INST_LAST, ///< Number of possible instances within the VCAP_SUPER structure of the ENET GH
} p64h_ras_enet_vcap_super_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_NAND_CTRL_0 = 0, ///< Instance 0 of structure nand_ctrl
    NVM_NAND_CTRL_1, ///< Instance 1 of structure nand_ctrl
    NVM_NAND_CTRL_2, ///< Instance 2 of structure nand_ctrl
    NVM_NAND_CTRL_3, ///< Instance 3 of structure nand_ctrl
    NVM_NAND_CTRL_INST_LAST, ///< Number of possible instances within the NAND_CTRL structure of the NVM GH
} p64h_ras_nvm_nand_ctrl_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_NVM_EDAC_0 = 0, ///< Instance 0 of structure nvm_edac
    NVM_NVM_EDAC_1, ///< Instance 1 of structure nvm_edac
    NVM_NVM_EDAC_INST_LAST, ///< Number of possible instances within the NVM_EDAC structure of the NVM GH
} p64h_ras_nvm_nvm_edac_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_PFLASH_CTRL_0 = 0, ///< Instance 0 of structure pflash_ctrl
    NVM_PFLASH_CTRL_1, ///< Instance 1 of structure pflash_ctrl
    NVM_PFLASH_CTRL_2, ///< Instance 2 of structure pflash_ctrl
    NVM_PFLASH_CTRL_3, ///< Instance 3 of structure pflash_ctrl
    NVM_PFLASH_CTRL_INST_LAST, ///< Number of possible instances within the PFLASH_CTRL structure of the NVM GH
} p64h_ras_nvm_pflash_ctrl_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_SPI_CTRL_0 = 0, ///< Instance 0 of structure spi_ctrl
    NVM_SPI_CTRL_1, ///< Instance 1 of structure spi_ctrl
    NVM_SPI_CTRL_2, ///< Instance 2 of structure spi_ctrl
    NVM_SPI_CTRL_3, ///< Instance 3 of structure spi_ctrl
    NVM_SPI_CTRL_INST_LAST, ///< Number of possible instances within the SPI_CTRL structure of the NVM GH
} p64h_ras_nvm_spi_ctrl_inst_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_SRAM_EDAC_0 = 0, ///< Instance 0 of structure sram_edac
    NVM_SRAM_EDAC_1, ///< Instance 1 of structure sram_edac
    NVM_SRAM_EDAC_2, ///< Instance 2 of structure sram_edac
    NVM_SRAM_EDAC_INST_LAST, ///< Number of possible instances within the SRAM_EDAC structure of the NVM GH
} p64h_ras_nvm_sram_edac_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_ANA_MON_0 = 0, ///< Instance 0 of structure ana_mon
    SEC_ANA_MON_INST_LAST, ///< Number of possible instances within the ANA_MON structure of the SEC GH
} p64h_ras_sec_ana_mon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_APB2JTAG_0 = 0, ///< Instance 0 of structure apb2jtag
    SEC_APB2JTAG_INST_LAST, ///< Number of possible instances within the APB2JTAG structure of the SEC GH
} p64h_ras_sec_apb2jtag_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_CMON_0 = 0, ///< Instance 0 of structure cmon
    SEC_CMON_INST_LAST, ///< Number of possible instances within the CMON structure of the SEC GH
} p64h_ras_sec_cmon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_CSU_APP = 0, ///< Instance app of structure csu
    SEC_CSU_INST_LAST, ///< Number of possible instances within the CSU structure of the SEC GH
} p64h_ras_sec_csu_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_DMA_0 = 0, ///< Instance 0 of structure dma
    SEC_DMA_INST_LAST, ///< Number of possible instances within the DMA structure of the SEC GH
} p64h_ras_sec_dma_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_MESH_ANA = 0, ///< Instance ana of structure mesh
    SEC_MESH_DDR_ENCRYPT, ///< Instance ddr_encrypt of structure mesh
    SEC_MESH_SEC, ///< Instance sec of structure mesh
    SEC_MESH_USR_CRYPTO, ///< Instance usr_crypto of structure mesh
    SEC_MESH_INST_LAST, ///< Number of possible instances within the MESH structure of the SEC GH
} p64h_ras_sec_mesh_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_NOC_0 = 0, ///< Instance 0 of structure noc
    SEC_NOC_INST_LAST, ///< Number of possible instances within the NOC structure of the SEC GH
} p64h_ras_sec_noc_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_OCR_0 = 0, ///< Instance 0 of structure ocr
    SEC_OCR_1, ///< Instance 1 of structure ocr
    SEC_OCR_2, ///< Instance 2 of structure ocr
    SEC_OCR_INST_LAST, ///< Number of possible instances within the OCR structure of the SEC GH
} p64h_ras_sec_ocr_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_PQS_0 = 0, ///< Instance 0 of structure pqs
    SEC_PQS_INST_LAST, ///< Number of possible instances within the PQS structure of the SEC GH
} p64h_ras_sec_pqs_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_RAM_BOOT_ROM = 0, ///< Instance boot_rom of structure ram
    SEC_RAM_DMA_CH, ///< Instance dma_ch of structure ram
    SEC_RAM_ECULTRA, ///< Instance ecultra of structure ram
    SEC_RAM_JTAG_MBOX, ///< Instance jtag_mbox of structure ram
    SEC_RAM_KEY_ROM, ///< Instance key_rom of structure ram
    SEC_RAM_KGSCRTR, ///< Instance kgscrtr of structure ram
    SEC_RAM_OTP, ///< Instance otp of structure ram
    SEC_RAM_PQCS_DSRAM, ///< Instance pqcs_dsram of structure ram
    SEC_RAM_PQCS_ISRAM, ///< Instance pqcs_isram of structure ram
    SEC_RAM_PQCS_ROM, ///< Instance pqcs_rom of structure ram
    SEC_RAM_S7_TRACE, ///< Instance s7_trace of structure ram
    SEC_RAM_SEC_MBOX, ///< Instance sec_mbox of structure ram
    SEC_RAM_INST_LAST, ///< Number of possible instances within the RAM structure of the SEC GH
} p64h_ras_sec_ram_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_S7_0 = 0, ///< Instance 0 of structure s7
    SEC_S7_INST_LAST, ///< Number of possible instances within the S7 structure of the SEC GH
} p64h_ras_sec_s7_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TAMPER_MON_0 = 0, ///< Instance 0 of structure tamper_mon
    SEC_TAMPER_MON_INST_LAST, ///< Number of possible instances within the TAMPER_MON structure of the SEC GH
} p64h_ras_sec_tamper_mon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TIMER_0 = 0, ///< Instance 0 of structure timer
    SEC_TIMER_INST_LAST, ///< Number of possible instances within the TIMER structure of the SEC GH
} p64h_ras_sec_timer_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_TVS_MON_0 = 0, ///< Instance 0 of structure tvs_mon
    SEC_TVS_MON_INST_LAST, ///< Number of possible instances within the TVS_MON structure of the SEC GH
} p64h_ras_sec_tvs_mon_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SEC GHES
 */
typedef enum {
    SEC_WDOG_0 = 0, ///< Instance 0 of structure wdog
    SEC_WDOG_INST_LAST, ///< Number of possible instances within the WDOG structure of the SEC GH
} p64h_ras_sec_wdog_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SYS GHES
 */
typedef enum {
    SYS_OCR_0 = 0, ///< Instance 0 of structure ocr
    SYS_OCR_INST_LAST, ///< Number of possible instances within the OCR structure of the SYS GH
} p64h_ras_sys_ocr_inst_t;

/**
 * @brief Definitions of all errors within a structure of the SYS GHES
 */
typedef enum {
    SYS_S7_0 = 0, ///< Instance 0 of structure s7
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
 * @brief Definitions of all errors within a structure of the DDR GHES
 */
typedef enum {
    DDR_CTRL_MISC_CONTROLLER_INT = 0, ///< Value misc:controller_int for instance ctrl of structure from DDR
   DDR_CTRL_MISC_PERF_MON_CORE_FIFO_FULL, ///< Value misc:perf_mon_core_fifo_full for instance ctrl of structure from DDR
   DDR_CTRL_MISC_PERF_MON_PORT_FIFO_FULL, ///< Value misc:perf_mon_port_fifo_full for instance ctrl of structure from DDR
   DDR_CTRL_MISC_Q_ALMOST_FULL, ///< Value misc:q_almost_full for instance ctrl of structure from DDR
   DDR_CTRL_RAM_CORRECTED_CTRL_CORR_ECC_ERR, ///< Value ram_corrected:ctrl_corr_ecc_err for instance ctrl of structure from DDR
   DDR_CTRL_RAM_UNCORRECTED_CTRL_UNCORR_ECC_ERR, ///< Value ram_uncorrected:ctrl_uncorr_ecc_err for instance ctrl of structure from DDR
   DDR_CTRL_ERROR_LAST, ///< Last value of possible error within the DDR GHES CTRL structu
} p64h_ras_ddr_ctrl_err_t;

/**
 * @brief Definitions of all errors within a structure of the DDR GHES
 */
typedef enum {
    DDR_EDAC_APP_DEC_BCFP = 0, ///< Value app:dec_bcfp for instance edac of structure from DDR
   DDR_EDAC_APP_DEC_POISON_DET, ///< Value app:dec_poison_det for instance edac of structure from DDR
   DDR_EDAC_APP_MEM_INIT_DONE_INT, ///< Value app:mem_init_done_int for instance edac of structure from DDR
   DDR_EDAC_APP_PATROL_SCRUB_COMPLETE, ///< Value app:patrol_scrub_complete for instance edac of structure from DDR
   DDR_EDAC_APP_RD_COH_BLOCK, ///< Value app:rd_coh_block for instance edac of structure from DDR
   DDR_EDAC_APP_WDCAP_SPARSE_WRITE, ///< Value app:wdcap_sparse_write for instance edac of structure from DDR
   DDR_EDAC_APP_WR_COH_BLOCK, ///< Value app:wr_coh_block for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL, ///< Value emon_corrected:emon_cor_buf_full for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THLD, ///< Value emon_corrected:emon_cor_buf_high_thld for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW, ///< Value emon_corrected:emon_cor_buf_ovrflw for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_FSM_ERR, ///< Value emon_corrected:emon_fsm_err for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL, ///< Value emon_corrected:emon_stat_buf_full for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW, ///< Value emon_corrected:emon_stat_buf_ovrflw for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL, ///< Value emon_corrected:emon_uncor_buf_full for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THLD, ///< Value emon_corrected:emon_uncor_buf_high_thld for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW, ///< Value emon_corrected:emon_uncor_buf_ovrflw for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_COR, ///< Value emon_corrected:err_mon_cor for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_COR_RAM_COR_ECC_ERR, ///< Value emon_corrected:err_mon_cor_ram_cor_ecc_err for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_COR_RAM_UNCOR_ECC_ERR, ///< Value emon_corrected:err_mon_cor_ram_uncor_ecc_err for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_STAT_RAM_COR_ECC_ERR, ///< Value emon_corrected:err_mon_stat_ram_cor_ecc_err for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_STAT_RAM_UNCOR_ECC_ERR, ///< Value emon_corrected:err_mon_stat_ram_uncor_ecc_err for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_UNCOR_RAM_COR_ECC_ERR, ///< Value emon_corrected:err_mon_uncor_ram_cor_ecc_err for instance edac of structure from DDR
   DDR_EDAC_EMON_CORRECTED_ERR_MON_UNCOR_RAM_UNCOR_ECC_ERR, ///< Value emon_corrected:err_mon_uncor_ram_uncor_ecc_err for instance edac of structure from DDR
   DDR_EDAC_EMON_UNCORRECTED_ERR_MON_ADDR_ERR, ///< Value emon_uncorrected:err_mon_addr_err for instance edac of structure from DDR
   DDR_EDAC_EMON_UNCORRECTED_ERR_MON_UNCOR, ///< Value emon_uncorrected:err_mon_uncor for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_BID_PARITY, ///< Value fault:err_bid_parity for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_BPARITY, ///< Value fault:err_bparity for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_RCTRL_PARITY, ///< Value fault:err_rctrl_parity for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_RDATA_PARITY, ///< Value fault:err_rdata_parity for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_READ_CTXT, ///< Value fault:err_read_ctxt for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_REMOVE_READ_COH, ///< Value fault:err_remove_read_coh for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_REMOVE_WRITE_COH, ///< Value fault:err_remove_write_coh for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_RID_PARITY, ///< Value fault:err_rid_parity for instance edac of structure from DDR
   DDR_EDAC_FAULT_ERR_WRITE_CTX, ///< Value fault:err_write_ctx for instance edac of structure from DDR
   DDR_EDAC_FAULT_PSCRUB_FSM_ERR, ///< Value fault:pscrub_fsm_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RAM_CRPT_FSM_ERR, ///< Value fault:ram_crpt_fsm_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RARB_ERR, ///< Value fault:rarb_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RDCAP_BYP_OVERFLOW, ///< Value fault:rdcap_byp_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RDCAP_BYP_UNDERFLOW, ///< Value fault:rdcap_byp_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RDCAP_BYPASS_CTX_OVERFLOW, ///< Value fault:rdcap_bypass_ctx_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RDCAP_BYPASS_CTX_UNDERFLOW, ///< Value fault:rdcap_bypass_ctx_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RDCAP_CTX_OVERFLOW, ///< Value fault:rdcap_ctx_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RDCAP_CTX_UNDERFLOW, ///< Value fault:rdcap_ctx_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_CAM_RMV_ERR, ///< Value fault:rmw_cam_rmv_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_CAM_SENT_ERR, ///< Value fault:rmw_cam_sent_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_CTX_OVERFLOW, ///< Value fault:rmw_ctx_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_CTX_UNDERFLOW, ///< Value fault:rmw_ctx_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_ID_OVERFLOW, ///< Value fault:rmw_id_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_ID_UNDERFLOW, ///< Value fault:rmw_id_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_MERGE_INFO_ERR, ///< Value fault:rmw_merge_info_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_RDCAP_OVERFLOW, ///< Value fault:rmw_rdcap_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_RDCAP_UNDERFLOW, ///< Value fault:rmw_rdcap_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_SCRUB_CTX_ERR, ///< Value fault:rmw_scrub_ctx_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_TRANS0_ERR, ///< Value fault:rmw_trans0_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RMW_TRANS1_ERR, ///< Value fault:rmw_trans1_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_RS_DEC_CFP_ENABLED, ///< Value fault:rs_dec_cfp_enabled for instance edac of structure from DDR
   DDR_EDAC_FAULT_WARB_ERR, ///< Value fault:warb_err for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDCAP_CTX_OVERFLOW, ///< Value fault:wdcap_ctx_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDCAP_CTX_UNDERFLOW, ///< Value fault:wdcap_ctx_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDCAP_STAGE2_OVERFLOW, ///< Value fault:wdcap_stage2_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDCAP_STAGE2_RMW_OVERFLOW, ///< Value fault:wdcap_stage2_rmw_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDCAP_STAGE2_RMW_UNDERFLOW, ///< Value fault:wdcap_stage2_rmw_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDCAP_STAGE2_UNDERFLOW, ///< Value fault:wdcap_stage2_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDRESP_CTX_OVERFLOW, ///< Value fault:wdresp_ctx_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDRESP_CTX_UNDERFLOW, ///< Value fault:wdresp_ctx_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDRESP_OVERFLOW, ///< Value fault:wdresp_overflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_WDRESP_UNDERFLOW, ///< Value fault:wdresp_underflow for instance edac of structure from DDR
   DDR_EDAC_FAULT_CORRECTED_RCMD_BUS_ECC_COR, ///< Value fault_corrected:rcmd_bus_ecc_cor for instance edac of structure from DDR
   DDR_EDAC_FAULT_CORRECTED_RDGEN_BUS_ECC_COR, ///< Value fault_corrected:rdgen_bus_ecc_cor for instance edac of structure from DDR
   DDR_EDAC_FAULT_CORRECTED_WCMD_BUS_ECC_COR, ///< Value fault_corrected:wcmd_bus_ecc_cor for instance edac of structure from DDR
   DDR_EDAC_FAULT_CORRECTED_WDCAP_BUS_ECC_COR, ///< Value fault_corrected:wdcap_bus_ecc_cor for instance edac of structure from DDR
   DDR_EDAC_FAULT_CORRECTED_WDGEN_BUS_ECC_COR, ///< Value fault_corrected:wdgen_bus_ecc_cor for instance edac of structure from DDR
   DDR_EDAC_FAULT_CORRECTED_WDGEN_RS_ENC_COR, ///< Value fault_corrected:wdgen_rs_enc_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_DEC_DATA_RAM_CORR_ECC_ERR, ///< Value ram_corrected:dec_data_ram_corr_ecc_err for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_DEC_ERR_RAM_CORR_ECC_ERR, ///< Value ram_corrected:dec_err_ram_corr_ecc_err for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_DEC_SYNBQS_RAM_CORR_ECC_ERR, ///< Value ram_corrected:dec_synbqs_ram_corr_ecc_err for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_RDCAP_BYPASS_CTX_RAM_COR, ///< Value ram_corrected:rdcap_bypass_ctx_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_RDCAP_BYPASS_RAM_COR, ///< Value ram_corrected:rdcap_bypass_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_RDCAP_CTX_RAM_COR, ///< Value ram_corrected:rdcap_ctx_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_RMW_CTX_RAM_COR, ///< Value ram_corrected:rmw_ctx_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_RMW_DATA_RAM_COR, ///< Value ram_corrected:rmw_data_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_WDCAP_CTX_RAM_COR, ///< Value ram_corrected:wdcap_ctx_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_WDCAP_STAGE2_RAM_COR, ///< Value ram_corrected:wdcap_stage2_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_CORRECTED_WDRESP_CTX_RAM_COR, ///< Value ram_corrected:wdresp_ctx_ram_cor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCORR_ECC_ERR, ///< Value ram_uncorrected:dec_data_ram_uncorr_ecc_err for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_DEC_ERR_RAM_UNCORR_ECC_ERR, ///< Value ram_uncorrected:dec_err_ram_uncorr_ecc_err for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_DEC_SYNBQS_RAM_UNCORR_ECC_ERR, ///< Value ram_uncorrected:dec_synbqs_ram_uncorr_ecc_err for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_RDCAP_BYPASS_CTX_RAM_UNCOR, ///< Value ram_uncorrected:rdcap_bypass_ctx_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_RDCAP_BYPASS_RAM_UNCOR, ///< Value ram_uncorrected:rdcap_bypass_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_RDCAP_CTX_RAM_UNCOR, ///< Value ram_uncorrected:rdcap_ctx_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_RMW_CTX_RAM_UNCOR, ///< Value ram_uncorrected:rmw_ctx_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_RMW_DATA_RAM_UNCOR, ///< Value ram_uncorrected:rmw_data_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_WDCAP_CTX_RAM_UNCOR, ///< Value ram_uncorrected:wdcap_ctx_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_WDCAP_STAGE2_RAM_UNCOR, ///< Value ram_uncorrected:wdcap_stage2_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_RAM_UNCORRECTED_WDRESP_CTX_RAM_UNCOR, ///< Value ram_uncorrected:wdresp_ctx_ram_uncor for instance edac of structure from DDR
   DDR_EDAC_READ_TIMEOUT_RCMD_TIMEOUT, ///< Value read_timeout:rcmd_timeout for instance edac of structure from DDR
   DDR_EDAC_READ_TIMEOUT_RDCAP_TIMEOUT, ///< Value read_timeout:rdcap_timeout for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RCMD_BUS_ECC_UNCOR, ///< Value trans_drop:rcmd_bus_ecc_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RCMD_DROP_TRANS, ///< Value trans_drop:rcmd_drop_trans for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RDCAP_DROP_TRANS, ///< Value trans_drop:rdcap_drop_trans for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RDGEN_BUS_ECC_UNCOR, ///< Value trans_drop:rdgen_bus_ecc_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_READ_TRANS_ERR, ///< Value trans_drop:read_trans_err for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_0_COR, ///< Value trans_drop:rmw_bus_ecc_0_cor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_0_UNCOR, ///< Value trans_drop:rmw_bus_ecc_0_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_1_COR, ///< Value trans_drop:rmw_bus_ecc_1_cor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_1_UNCOR, ///< Value trans_drop:rmw_bus_ecc_1_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_2_COR, ///< Value trans_drop:rmw_bus_ecc_2_cor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_2_UNCOR, ///< Value trans_drop:rmw_bus_ecc_2_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_3_COR, ///< Value trans_drop:rmw_bus_ecc_3_cor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_3_UNCOR, ///< Value trans_drop:rmw_bus_ecc_3_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_UNKN_RD_RESP, ///< Value trans_drop:unkn_rd_resp for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WCMD_BUS_ECC_UNCOR, ///< Value trans_drop:wcmd_bus_ecc_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WCMD_DROP_TRANS, ///< Value trans_drop:wcmd_drop_trans for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WDCAP_BUS_ECC_UNCOR, ///< Value trans_drop:wdcap_bus_ecc_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WDGEN_BUS_ECC_UNCOR, ///< Value trans_drop:wdgen_bus_ecc_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WDGEN_DROP_TRANS, ///< Value trans_drop:wdgen_drop_trans for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WDGEN_RS_ENC_UNCOR, ///< Value trans_drop:wdgen_rs_enc_uncor for instance edac of structure from DDR
   DDR_EDAC_TRANS_DROP_WDRESP_DROP_TRANS, ///< Value trans_drop:wdresp_drop_trans for instance edac of structure from DDR
   DDR_EDAC_WRITE_TIMEOUT_WCMD_TIMEOUT, ///< Value write_timeout:wcmd_timeout for instance edac of structure from DDR
   DDR_EDAC_WRITE_TIMEOUT_WDGEN_TIMEOUT, ///< Value write_timeout:wdgen_timeout for instance edac of structure from DDR
   DDR_EDAC_WRITE_TIMEOUT_WDRESP_TIMEOUT, ///< Value write_timeout:wdresp_timeout for instance edac of structure from DDR
   DDR_EDAC_ERROR_LAST, ///< Last value of possible error within the DDR GHES EDAC structu
} p64h_ras_ddr_edac_err_t;

/**
 * @brief Definitions of all errors within a structure of the DDR_NOC GHES
 */
typedef enum {
    DDR_NOC_INITIATORS_CRITICAL_CRITICAL_COMPARATOR_TREE = 0, ///< Value critical:critical_comparator_tree for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_FLT_SECDED_CORR, ///< Value critical:flt_secded_corr for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_FLT_SECDED_UNCORR, ///< Value critical:flt_secded_uncorr for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_HANDSHAKE_RETRACTION, ///< Value critical:handshake_retraction for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_INTERNAL_FSM, ///< Value critical:internal_fsm for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_JUMPER_PARITY, ///< Value critical:jumper_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_LATENT_COMPARATOR_TREE, ///< Value critical:latent_comparator_tree for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_LATENT_TIMEOUT, ///< Value critical:latent_timeout for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_MAJOR_TIMEOUT, ///< Value critical:major_timeout for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_PACKET_FRAMING, ///< Value critical:packet_framing for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_PACKET_WORDNUMBER, ///< Value critical:packet_wordnumber for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_PACKET_WRONGPATH, ///< Value critical:packet_wrongpath for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_POWER_DISCONNECT_ERROR, ///< Value critical:power_disconnect_error for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_POWER_MAIN_FAULT_CONTROL_PARITY, ///< Value critical:power_main_fault_control_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_CRITICAL_QOS_GENERATOR_PARITY, ///< Value critical:qos_generator_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_CRITICAL_COMPARATOR_TREE, ///< Value major:critical_comparator_tree for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_FLT_SECDED_CORR, ///< Value major:flt_secded_corr for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_FLT_SECDED_UNCORR, ///< Value major:flt_secded_uncorr for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_HANDSHAKE_RETRACTION, ///< Value major:handshake_retraction for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_INTERNAL_FSM, ///< Value major:internal_fsm for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_JUMPER_PARITY, ///< Value major:jumper_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_LATENT_COMPARATOR_TREE, ///< Value major:latent_comparator_tree for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_LATENT_TIMEOUT, ///< Value major:latent_timeout for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_MAJOR_TIMEOUT, ///< Value major:major_timeout for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_PACKET_FRAMING, ///< Value major:packet_framing for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_PACKET_WORDNUMBER, ///< Value major:packet_wordnumber for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_PACKET_WRONGPATH, ///< Value major:packet_wrongpath for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_POWER_DISCONNECT_ERROR, ///< Value major:power_disconnect_error for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_POWER_MAIN_FAULT_CONTROL_PARITY, ///< Value major:power_main_fault_control_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MAJOR_QOS_GENERATOR_PARITY, ///< Value major:qos_generator_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_CRITICAL_COMPARATOR_TREE, ///< Value minor:critical_comparator_tree for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_FLT_SECDED_CORR, ///< Value minor:flt_secded_corr for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_FLT_SECDED_UNCORR, ///< Value minor:flt_secded_uncorr for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_HANDSHAKE_RETRACTION, ///< Value minor:handshake_retraction for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_INTERNAL_FSM, ///< Value minor:internal_fsm for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_JUMPER_PARITY, ///< Value minor:jumper_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_LATENT_COMPARATOR_TREE, ///< Value minor:latent_comparator_tree for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_LATENT_TIMEOUT, ///< Value minor:latent_timeout for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_MAJOR_TIMEOUT, ///< Value minor:major_timeout for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_PACKET_FRAMING, ///< Value minor:packet_framing for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_PACKET_WORDNUMBER, ///< Value minor:packet_wordnumber for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_PACKET_WRONGPATH, ///< Value minor:packet_wrongpath for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_POWER_DISCONNECT_ERROR, ///< Value minor:power_disconnect_error for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_POWER_MAIN_FAULT_CONTROL_PARITY, ///< Value minor:power_main_fault_control_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_MINOR_QOS_GENERATOR_PARITY, ///< Value minor:qos_generator_parity for instance initiators of structure from DDR_NOC
   DDR_NOC_INITIATORS_ERROR_LAST, ///< Last value of possible error within the DDR_NOC GHES INITIATORS structu
} p64h_ras_ddr_noc_initiators_err_t;

/**
 * @brief Definitions of all errors within a structure of the DDR_NOC GHES
 */
typedef enum {
    DDR_NOC_TARGETS_CRITICAL_AXI_RDATA_SECDED_CORR = 0, ///< Value critical:axi_rdata_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_AXI_RDATA_SECDED_UNCORR, ///< Value critical:axi_rdata_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_AXI_WRESP_SECDED_CORR, ///< Value critical:axi_wresp_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_AXI_WRESP_SECDED_UNCORR, ///< Value critical:axi_wresp_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_CRITICAL_COMPARATOR_TREE, ///< Value critical:critical_comparator_tree for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_FLT_SECDED_CORR, ///< Value critical:flt_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_FLT_SECDED_UNCORR, ///< Value critical:flt_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_HANDSHAKE_RETRACTION, ///< Value critical:handshake_retraction for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_INTERNAL_FSM, ///< Value critical:internal_fsm for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_JUMPER_PARITY, ///< Value critical:jumper_parity for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_LATENT_COMPARATOR_TREE, ///< Value critical:latent_comparator_tree for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_PACKET_FRAMING, ///< Value critical:packet_framing for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_PACKET_WORDNUMBER, ///< Value critical:packet_wordnumber for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_PACKET_WRONGPATH, ///< Value critical:packet_wrongpath for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_CRITICAL_POWER_MAIN_FAULT_CONTROL_PARITY, ///< Value critical:power_main_fault_control_parity for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_AXI_RDATA_SECDED_CORR, ///< Value major:axi_rdata_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_AXI_RDATA_SECDED_UNCORR, ///< Value major:axi_rdata_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_AXI_WRESP_SECDED_CORR, ///< Value major:axi_wresp_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_AXI_WRESP_SECDED_UNCORR, ///< Value major:axi_wresp_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_CRITICAL_COMPARATOR_TREE, ///< Value major:critical_comparator_tree for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_FLT_SECDED_CORR, ///< Value major:flt_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_FLT_SECDED_UNCORR, ///< Value major:flt_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_HANDSHAKE_RETRACTION, ///< Value major:handshake_retraction for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_INTERNAL_FSM, ///< Value major:internal_fsm for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_JUMPER_PARITY, ///< Value major:jumper_parity for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_LATENT_COMPARATOR_TREE, ///< Value major:latent_comparator_tree for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_PACKET_FRAMING, ///< Value major:packet_framing for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_PACKET_WORDNUMBER, ///< Value major:packet_wordnumber for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_PACKET_WRONGPATH, ///< Value major:packet_wrongpath for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MAJOR_POWER_MAIN_FAULT_CONTROL_PARITY, ///< Value major:power_main_fault_control_parity for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_AXI_RDATA_SECDED_CORR, ///< Value minor:axi_rdata_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_AXI_RDATA_SECDED_UNCORR, ///< Value minor:axi_rdata_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_AXI_WRESP_SECDED_CORR, ///< Value minor:axi_wresp_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_AXI_WRESP_SECDED_UNCORR, ///< Value minor:axi_wresp_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_CRITICAL_COMPARATOR_TREE, ///< Value minor:critical_comparator_tree for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_FLT_SECDED_CORR, ///< Value minor:flt_secded_corr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_FLT_SECDED_UNCORR, ///< Value minor:flt_secded_uncorr for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_HANDSHAKE_RETRACTION, ///< Value minor:handshake_retraction for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_INTERNAL_FSM, ///< Value minor:internal_fsm for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_JUMPER_PARITY, ///< Value minor:jumper_parity for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_LATENT_COMPARATOR_TREE, ///< Value minor:latent_comparator_tree for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_PACKET_FRAMING, ///< Value minor:packet_framing for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_PACKET_WORDNUMBER, ///< Value minor:packet_wordnumber for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_PACKET_WRONGPATH, ///< Value minor:packet_wrongpath for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_MINOR_POWER_MAIN_FAULT_CONTROL_PARITY, ///< Value minor:power_main_fault_control_parity for instance targets of structure from DDR_NOC
   DDR_NOC_TARGETS_ERROR_LAST, ///< Last value of possible error within the DDR_NOC GHES TARGETS structu
} p64h_ras_ddr_noc_targets_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_FRER_GEN_CFG = 0, ///< Value ram_corrected:ana_ac_frer_gen_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_FRER_GEN_STA, ///< Value ram_corrected:ana_ac_frer_gen_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_AGGR, ///< Value ram_corrected:ana_ac_logic_aggr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_CSD, ///< Value ram_corrected:ana_ac_logic_csd for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_LAG_RST, ///< Value ram_corrected:ana_ac_logic_lag_rst for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_PGID, ///< Value ram_corrected:ana_ac_logic_pgid for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_SRC, ///< Value ram_corrected:ana_ac_logic_src for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_PDU_MOD_CONT, ///< Value ram_corrected:ana_ac_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_VOE_PORT_LM_CNT, ///< Value ram_corrected:ana_ac_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_VOE_SRV_LM_CNT, ///< Value ram_corrected:ana_ac_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_BDLB, ///< Value ram_corrected:ana_ac_pol_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_BUM_SLB, ///< Value ram_corrected:ana_ac_pol_bum_slb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_CTRL_CONTEXT, ///< Value ram_corrected:ana_ac_pol_ctrl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_CTRL_POL_PORT_CTRL, ///< Value ram_corrected:ana_ac_pol_ctrl_pol_port_ctrl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_PORT_POL_CFG, ///< Value ram_corrected:ana_ac_pol_port_pol_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_PORT_POL_LB, ///< Value ram_corrected:ana_ac_pol_port_pol_lb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_INH_TOKENS, ///< Value ram_corrected:ana_ac_pol_sdlb_inh_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LB_CLOSED, ///< Value ram_corrected:ana_ac_pol_sdlb_lb_closed for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LB_TOKENS, ///< Value ram_corrected:ana_ac_pol_sdlb_lb_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LBSET_TBL, ///< Value ram_corrected:ana_ac_pol_sdlb_lbset_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ACL, ///< Value ram_corrected:ana_ac_stat_acl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_BDLB, ///< Value ram_corrected:ana_ac_stat_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_BUM, ///< Value ram_corrected:ana_ac_stat_bum for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ERLEG, ///< Value ram_corrected:ana_ac_stat_erleg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_IRLEG, ///< Value ram_corrected:ana_ac_stat_irleg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ISDX, ///< Value ram_corrected:ana_ac_stat_isdx for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_PORT_CR_CFG, ///< Value ram_corrected:ana_ac_stat_port_cr_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_PORT_IR_CFG, ///< Value ram_corrected:ana_ac_stat_port_ir_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_QUEUE, ///< Value ram_corrected:ana_ac_stat_queue for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STREAM_GATES, ///< Value ram_corrected:ana_ac_stream_gates for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_TSN_SF_CFG, ///< Value ram_corrected:ana_ac_tsn_sf_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_TSN_SF_STA, ///< Value ram_corrected:ana_ac_tsn_sf_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CELL_INFO, ///< Value ram_corrected:eacl_cell_info for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CNT_TBL, ///< Value ram_corrected:eacl_cnt_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CONTEXT, ///< Value ram_corrected:eacl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_DEF_AR_X, ///< Value ram_corrected:eacl_def_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_DEF_CNTR, ///< Value ram_corrected:eacl_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_ECC_PAR_RAM, ///< Value ram_corrected:eacl_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CCFG, ///< Value ram_corrected:eacl_frer_ccfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CCNT, ///< Value ram_corrected:eacl_frer_ccnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CSTA, ///< Value ram_corrected:eacl_frer_csta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MAP, ///< Value ram_corrected:eacl_frer_map for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MCFG, ///< Value ram_corrected:eacl_frer_mcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MCNT, ///< Value ram_corrected:eacl_frer_mcnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MSTA, ///< Value ram_corrected:eacl_frer_msta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_IF_MAP, ///< Value ram_corrected:eacl_if_map for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_KEY_SEL_PROF, ///< Value ram_corrected:eacl_key_sel_prof for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_SL_0_AR_X, ///< Value ram_corrected:eacl_sl_0_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_SL_0_CNTR, ///< Value ram_corrected:eacl_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_STAT_EACL, ///< Value ram_corrected:eacl_stat_eacl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_ENCAP, ///< Value ram_corrected:rew_encap for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_ISDX_TBL, ///< Value ram_corrected:rew_isdx_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAC_TBL, ///< Value ram_corrected:rew_mac_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAP_RES_A, ///< Value ram_corrected:rew_map_res_a for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAP_RES_B, ///< Value ram_corrected:rew_map_res_b for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MIP_TBL, ///< Value ram_corrected:rew_mip_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_PDU_MOD_CONT, ///< Value ram_corrected:rew_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_VOE_PORT_LM_CNT, ///< Value ram_corrected:rew_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_VOE_SRV_LM_CNT, ///< Value ram_corrected:rew_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_PORTCFG, ///< Value ram_corrected:rew_portcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_PTP_SEQ, ///< Value ram_corrected:rew_ptp_seq for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_DEF_AR, ///< Value ram_corrected:rew_vcap_es0_def_ar for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_DEF_CNTR, ///< Value ram_corrected:rew_vcap_es0_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_ECC_PAR_RAM, ///< Value ram_corrected:rew_vcap_es0_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_SL_0_AR_0, ///< Value ram_corrected:rew_vcap_es0_sl_0_ar_0 for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_SL_0_CNTR, ///< Value ram_corrected:rew_vcap_es0_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VMID, ///< Value ram_corrected:rew_vmid for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_FRER_GEN_CFG, ///< Value ram_uncorrected:ana_ac_frer_gen_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_FRER_GEN_STA, ///< Value ram_uncorrected:ana_ac_frer_gen_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_AGGR, ///< Value ram_uncorrected:ana_ac_logic_aggr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_CSD, ///< Value ram_uncorrected:ana_ac_logic_csd for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_LAG_RST, ///< Value ram_uncorrected:ana_ac_logic_lag_rst for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_PGID, ///< Value ram_uncorrected:ana_ac_logic_pgid for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_SRC, ///< Value ram_uncorrected:ana_ac_logic_src for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_PDU_MOD_CONT, ///< Value ram_uncorrected:ana_ac_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_VOE_PORT_LM_CNT, ///< Value ram_uncorrected:ana_ac_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_VOE_SRV_LM_CNT, ///< Value ram_uncorrected:ana_ac_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_BDLB, ///< Value ram_uncorrected:ana_ac_pol_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_BUM_SLB, ///< Value ram_uncorrected:ana_ac_pol_bum_slb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_CTRL_CONTEXT, ///< Value ram_uncorrected:ana_ac_pol_ctrl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_CTRL_POL_PORT_CTRL, ///< Value ram_uncorrected:ana_ac_pol_ctrl_pol_port_ctrl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_PORT_POL_CFG, ///< Value ram_uncorrected:ana_ac_pol_port_pol_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_PORT_POL_LB, ///< Value ram_uncorrected:ana_ac_pol_port_pol_lb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_INH_TOKENS, ///< Value ram_uncorrected:ana_ac_pol_sdlb_inh_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LB_CLOSED, ///< Value ram_uncorrected:ana_ac_pol_sdlb_lb_closed for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LB_TOKENS, ///< Value ram_uncorrected:ana_ac_pol_sdlb_lb_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LBSET_TBL, ///< Value ram_uncorrected:ana_ac_pol_sdlb_lbset_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ACL, ///< Value ram_uncorrected:ana_ac_stat_acl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_BDLB, ///< Value ram_uncorrected:ana_ac_stat_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_BUM, ///< Value ram_uncorrected:ana_ac_stat_bum for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ERLEG, ///< Value ram_uncorrected:ana_ac_stat_erleg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_IRLEG, ///< Value ram_uncorrected:ana_ac_stat_irleg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ISDX, ///< Value ram_uncorrected:ana_ac_stat_isdx for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_PORT_CR_CFG, ///< Value ram_uncorrected:ana_ac_stat_port_cr_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_PORT_IR_CFG, ///< Value ram_uncorrected:ana_ac_stat_port_ir_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_QUEUE, ///< Value ram_uncorrected:ana_ac_stat_queue for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STREAM_GATES, ///< Value ram_uncorrected:ana_ac_stream_gates for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_TSN_SF_CFG, ///< Value ram_uncorrected:ana_ac_tsn_sf_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_TSN_SF_STA, ///< Value ram_uncorrected:ana_ac_tsn_sf_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CELL_INFO, ///< Value ram_uncorrected:eacl_cell_info for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CNT_TBL, ///< Value ram_uncorrected:eacl_cnt_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CONTEXT, ///< Value ram_uncorrected:eacl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_DEF_AR_X, ///< Value ram_uncorrected:eacl_def_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_DEF_CNTR, ///< Value ram_uncorrected:eacl_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_ECC_PAR_RAM, ///< Value ram_uncorrected:eacl_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CCFG, ///< Value ram_uncorrected:eacl_frer_ccfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CCNT, ///< Value ram_uncorrected:eacl_frer_ccnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CSTA, ///< Value ram_uncorrected:eacl_frer_csta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MAP, ///< Value ram_uncorrected:eacl_frer_map for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MCFG, ///< Value ram_uncorrected:eacl_frer_mcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MCNT, ///< Value ram_uncorrected:eacl_frer_mcnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MSTA, ///< Value ram_uncorrected:eacl_frer_msta for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_IF_MAP, ///< Value ram_uncorrected:eacl_if_map for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_KEY_SEL_PROF, ///< Value ram_uncorrected:eacl_key_sel_prof for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_SL_0_AR_X, ///< Value ram_uncorrected:eacl_sl_0_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_SL_0_CNTR, ///< Value ram_uncorrected:eacl_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_STAT_EACL, ///< Value ram_uncorrected:eacl_stat_eacl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_ENCAP, ///< Value ram_uncorrected:rew_encap for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_ISDX_TBL, ///< Value ram_uncorrected:rew_isdx_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAC_TBL, ///< Value ram_uncorrected:rew_mac_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAP_RES_A, ///< Value ram_uncorrected:rew_map_res_a for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAP_RES_B, ///< Value ram_uncorrected:rew_map_res_b for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MIP_TBL, ///< Value ram_uncorrected:rew_mip_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_PDU_MOD_CONT, ///< Value ram_uncorrected:rew_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_VOE_PORT_LM_CNT, ///< Value ram_uncorrected:rew_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_VOE_SRV_LM_CNT, ///< Value ram_uncorrected:rew_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_PORTCFG, ///< Value ram_uncorrected:rew_portcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_PTP_SEQ, ///< Value ram_uncorrected:rew_ptp_seq for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_DEF_AR, ///< Value ram_uncorrected:rew_vcap_es0_def_ar for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_DEF_CNTR, ///< Value ram_uncorrected:rew_vcap_es0_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_ECC_PAR_RAM, ///< Value ram_uncorrected:rew_vcap_es0_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_SL_0_AR_0, ///< Value ram_uncorrected:rew_vcap_es0_sl_0_ar_0 for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_SL_0_CNTR, ///< Value ram_uncorrected:rew_vcap_es0_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VMID, ///< Value ram_uncorrected:rew_vmid for instance ana_ac_eacl_rew_wrap of structure from ENET
   ENET_ANA_AC_EACL_REW_WRAP_ERROR_LAST, ///< Last value of possible error within the ENET GHES ANA_AC_EACL_REW_WRAP structu
} p64h_ras_enet_ana_ac_eacl_rew_wrap_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_ACL_VOP_DELAY = 0, ///< Value ram_corrected:ana_acl_acl_vop_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CL_ACL_DELAY, ///< Value ram_corrected:ana_acl_cl_acl_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CNT_A, ///< Value ram_corrected:ana_acl_cnt_a for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CNT_B, ///< Value ram_corrected:ana_acl_cnt_b for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_VOP_AC_DELAY, ///< Value ram_corrected:ana_acl_vop_ac_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_VOP_PDU_MOD_DELAY, ///< Value ram_corrected:ana_acl_vop_pdu_mod_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_ARM_PTR_REMAP_TBL, ///< Value ram_corrected:ana_cl_arm_ptr_remap_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_ARP_TBL, ///< Value ram_corrected:ana_cl_arp_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_CHECKSUM_CONTEXT, ///< Value ram_corrected:ana_cl_checksum_context for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_CSC, ///< Value ram_corrected:ana_cl_csc for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_IPT, ///< Value ram_corrected:ana_cl_ipt for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_L2CP_TBL, ///< Value ram_corrected:ana_cl_l2cp_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_L3MC_TBL, ///< Value ram_corrected:ana_cl_l3mc_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MAP_TBL, ///< Value ram_corrected:ana_cl_map_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MIP_TBL, ///< Value ram_corrected:ana_cl_mip_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MSTP_TBL, ///< Value ram_corrected:ana_cl_mstp_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_PORT_CFG, ///< Value ram_corrected:ana_cl_port_cfg for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VLAN_TBL, ///< Value ram_corrected:ana_cl_vlan_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VMID, ///< Value ram_corrected:ana_cl_vmid for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VMID_TBL, ///< Value ram_corrected:ana_cl_vmid_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_AGE, ///< Value ram_corrected:ana_l2_logic_age for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_ISDX, ///< Value ram_corrected:ana_l2_logic_isdx for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_ISDX_LIMIT, ///< Value ram_corrected:ana_l2_logic_isdx_limit for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_LRN_LIMIT, ///< Value ram_corrected:ana_l2_logic_lrn_limit for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_MAC, ///< Value ram_corrected:ana_l2_logic_mac for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_PMAC, ///< Value ram_corrected:ana_l2_logic_pmac for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_PORT_LIMIT, ///< Value ram_corrected:ana_l2_logic_port_limit for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LRN_IGR_LRN, ///< Value ram_corrected:ana_l2_lrn_igr_lrn for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_ANA_COSID_MAP_CONF, ///< Value ram_corrected:oam_mep_ana_cosid_map_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_CCM_LM, ///< Value ram_corrected:oam_mep_ccm_lm for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_PORT_COSID_MAP_CONF, ///< Value ram_corrected:oam_mep_port_cosid_map_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_REW_COSID_MAP_CONF, ///< Value ram_corrected:oam_mep_rew_cosid_map_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_SAM_COSID_SEQ_CNT, ///< Value ram_corrected:oam_mep_sam_cosid_seq_cnt for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONF, ///< Value ram_corrected:oam_mep_voe_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONTEXT_ANA, ///< Value ram_corrected:oam_mep_voe_context_ana for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONTEXT_REW, ///< Value ram_corrected:oam_mep_voe_context_rew for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CRC_ERR, ///< Value ram_corrected:oam_mep_voe_crc_err for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_STAT, ///< Value ram_corrected:oam_mep_voe_stat for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_ECC_PAR_RAM, ///< Value ram_corrected:vcap_ip6pfx_ecc_par_ram for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_SL_0_AR_X, ///< Value ram_corrected:vcap_ip6pfx_sl_0_ar_x for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_SL_0_CNTR, ///< Value ram_corrected:vcap_ip6pfx_sl_0_cntr for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_ACL_VOP_DELAY, ///< Value ram_uncorrected:ana_acl_acl_vop_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CL_ACL_DELAY, ///< Value ram_uncorrected:ana_acl_cl_acl_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CNT_A, ///< Value ram_uncorrected:ana_acl_cnt_a for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CNT_B, ///< Value ram_uncorrected:ana_acl_cnt_b for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_VOP_AC_DELAY, ///< Value ram_uncorrected:ana_acl_vop_ac_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_VOP_PDU_MOD_DELAY, ///< Value ram_uncorrected:ana_acl_vop_pdu_mod_delay for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_ARM_PTR_REMAP_TBL, ///< Value ram_uncorrected:ana_cl_arm_ptr_remap_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_ARP_TBL, ///< Value ram_uncorrected:ana_cl_arp_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_CHECKSUM_CONTEXT, ///< Value ram_uncorrected:ana_cl_checksum_context for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_CSC, ///< Value ram_uncorrected:ana_cl_csc for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_IPT, ///< Value ram_uncorrected:ana_cl_ipt for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_L2CP_TBL, ///< Value ram_uncorrected:ana_cl_l2cp_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_L3MC_TBL, ///< Value ram_uncorrected:ana_cl_l3mc_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MAP_TBL, ///< Value ram_uncorrected:ana_cl_map_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MIP_TBL, ///< Value ram_uncorrected:ana_cl_mip_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MSTP_TBL, ///< Value ram_uncorrected:ana_cl_mstp_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_PORT_CFG, ///< Value ram_uncorrected:ana_cl_port_cfg for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VLAN_TBL, ///< Value ram_uncorrected:ana_cl_vlan_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VMID, ///< Value ram_uncorrected:ana_cl_vmid for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VMID_TBL, ///< Value ram_uncorrected:ana_cl_vmid_tbl for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_AGE, ///< Value ram_uncorrected:ana_l2_logic_age for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_ISDX, ///< Value ram_uncorrected:ana_l2_logic_isdx for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_ISDX_LIMIT, ///< Value ram_uncorrected:ana_l2_logic_isdx_limit for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_LRN_LIMIT, ///< Value ram_uncorrected:ana_l2_logic_lrn_limit for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_MAC, ///< Value ram_uncorrected:ana_l2_logic_mac for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_PMAC, ///< Value ram_uncorrected:ana_l2_logic_pmac for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_PORT_LIMIT, ///< Value ram_uncorrected:ana_l2_logic_port_limit for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LRN_IGR_LRN, ///< Value ram_uncorrected:ana_l2_lrn_igr_lrn for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_ANA_COSID_MAP_CONF, ///< Value ram_uncorrected:oam_mep_ana_cosid_map_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_CCM_LM, ///< Value ram_uncorrected:oam_mep_ccm_lm for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_PORT_COSID_MAP_CONF, ///< Value ram_uncorrected:oam_mep_port_cosid_map_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_REW_COSID_MAP_CONF, ///< Value ram_uncorrected:oam_mep_rew_cosid_map_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_SAM_COSID_SEQ_CNT, ///< Value ram_uncorrected:oam_mep_sam_cosid_seq_cnt for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONF, ///< Value ram_uncorrected:oam_mep_voe_conf for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONTEXT_ANA, ///< Value ram_uncorrected:oam_mep_voe_context_ana for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONTEXT_REW, ///< Value ram_uncorrected:oam_mep_voe_context_rew for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CRC_ERR, ///< Value ram_uncorrected:oam_mep_voe_crc_err for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_STAT, ///< Value ram_uncorrected:oam_mep_voe_stat for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_ECC_PAR_RAM, ///< Value ram_uncorrected:vcap_ip6pfx_ecc_par_ram for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_SL_0_AR_X, ///< Value ram_uncorrected:vcap_ip6pfx_sl_0_ar_x for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_SL_0_CNTR, ///< Value ram_uncorrected:vcap_ip6pfx_sl_0_cntr for instance anacl32oam of structure from ENET
   ENET_ANACL32OAM_ERROR_LAST, ///< Last value of possible error within the ENET GHES ANACL32OAM structu
} p64h_ras_enet_anacl32oam_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_ASM_RAM_CORRECTED_ASM_CSC = 0, ///< Value ram_corrected:asm_csc for instance asm of structure from ENET
   ENET_ASM_RAM_CORRECTED_ASM_LBK_CELL_FIFO, ///< Value ram_corrected:asm_lbk_cell_fifo for instance asm of structure from ENET
   ENET_ASM_RAM_CORRECTED_ASM_LBK_VD2_FIFO, ///< Value ram_corrected:asm_lbk_vd2_fifo for instance asm of structure from ENET
   ENET_ASM_RAM_CORRECTED_ASM_PFC_PRIOFC, ///< Value ram_corrected:asm_pfc_priofc for instance asm of structure from ENET
   ENET_ASM_RAM_CORRECTED_ASM_TAXIX_SF_BANKY_SBIT, ///< Value ram_corrected:asm_taxiX_sf_bankY_sbit for instance asm of structure from ENET
   ENET_ASM_RAM_UNCORRECTED_ASM_CSC, ///< Value ram_uncorrected:asm_csc for instance asm of structure from ENET
   ENET_ASM_RAM_UNCORRECTED_ASM_LBK_CELL_FIFO, ///< Value ram_uncorrected:asm_lbk_cell_fifo for instance asm of structure from ENET
   ENET_ASM_RAM_UNCORRECTED_ASM_LBK_VD2_FIFO, ///< Value ram_uncorrected:asm_lbk_vd2_fifo for instance asm of structure from ENET
   ENET_ASM_RAM_UNCORRECTED_ASM_PFC_PRIOFC, ///< Value ram_uncorrected:asm_pfc_priofc for instance asm of structure from ENET
   ENET_ASM_RAM_UNCORRECTED_ASM_TAXIX_SF_BANKY_MBIT, ///< Value ram_uncorrected:asm_taxiX_sf_bankY_mbit for instance asm of structure from ENET
   ENET_ASM_ERROR_LAST, ///< Last value of possible error within the ENET GHES ASM structu
} p64h_ras_enet_asm_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_DSM_RAM_CORRECTED_DSM_TAXIX_CBUF_RAMY_Z_SBIT = 0, ///< Value ram_corrected:dsm_taxiX_cbuf_ramY_Z_sbit for instance dsm of structure from ENET
   ENET_DSM_RAM_UNCORRECTED_DSM_TAXIX_CBUF_RAMY_Z_MBIT, ///< Value ram_uncorrected:dsm_taxiX_cbuf_ramY_Z_mbit for instance dsm of structure from ENET
   ENET_DSM_ERROR_LAST, ///< Last value of possible error within the ENET GHES DSM structu
} p64h_ras_enet_dsm_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_EACL_MISC_ERROR_INVLD_SOF_PTR_DISCARD = 0, ///< Value misc_error:invld_sof_ptr_discard for instance eacl of structure from ENET
   ENET_EACL_ERROR_LAST, ///< Last value of possible error within the ENET GHES EACL structu
} p64h_ras_enet_eacl_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_MISC_RAM_CORRECTED_DEVCPU_PTP_TS_FIFO = 0, ///< Value ram_corrected:devcpu_ptp_ts_fifo for instance misc of structure from ENET
   ENET_MISC_RAM_UNCORRECTED_DEVCPU_PTP_TS_FIFO, ///< Value ram_uncorrected:devcpu_ptp_ts_fifo for instance misc of structure from ENET
   ENET_MISC_ERROR_LAST, ///< Last value of possible error within the ENET GHES MISC structu
} p64h_ras_enet_misc_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RDAT_RET_MM2S_SBIT = 0, ///< Value ram_corrected:pierX_dma_rdat_ret_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RSTS_PRE_MM2S_SBIT, ///< Value ram_corrected:pierX_dma_rsts_pre_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RSTS_S2MM_SBIT, ///< Value ram_corrected:pierX_dma_rsts_s2mm_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WCMD_MM2S_SBIT, ///< Value ram_corrected:pierX_dma_wcmd_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WCMD_S2MM_SBIT, ///< Value ram_corrected:pierX_dma_wcmd_s2mm_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WSTS_MM2S_SBIT, ///< Value ram_corrected:pierX_dma_wsts_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WSTS_S2MM_SBIT, ///< Value ram_corrected:pierX_dma_wsts_s2mm_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_DW_CTL_SBIT, ///< Value ram_corrected:pierX_dmac_dw_ctl_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_DW_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_dw_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RCMD_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_rcmd_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RCPL_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_rcpl_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RDAT_CTL_SBIT, ///< Value ram_corrected:pierX_dmac_rdat_ctl_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RDAT_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_rdat_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RSTS_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_rsts_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WCMD_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_wcmd_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WCPL_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_wcpl_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WDAT_CTL_SBIT, ///< Value ram_corrected:pierX_dmac_wdat_ctl_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WDAT_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_wdat_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WSTS_FIFO_SBIT, ///< Value ram_corrected:pierX_dmac_wsts_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_DMTA_SBIT, ///< Value ram_corrected:pierX_mem_isdx_dmta_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_DMTB_SBIT, ///< Value ram_corrected:pierX_mem_isdx_dmtb_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_SATA_SBIT, ///< Value ram_corrected:pierX_mem_isdx_sata_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_SATB_SBIT, ///< Value ram_corrected:pierX_mem_isdx_satb_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_STX_INS_LUTA_SBIT, ///< Value ram_corrected:pierX_mem_stx_ins_luta_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_STX_INS_LUTB_SBIT, ///< Value ram_corrected:pierX_mem_stx_ins_lutb_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_AXI_ERR_PMON_X_SBIT, ///< Value ram_corrected:pierX_pe_axi_err_pmon_x_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_DATA_PMON_X_SBIT, ///< Value ram_corrected:pierX_pe_data_pmon_x_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_DESC_DCFC_SBIT, ///< Value ram_corrected:pierX_pe_desc_dcfc_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PI_DESC_DCFC_SBIT, ///< Value ram_corrected:pierX_pi_desc_dcfc_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PI_DESC_DROP_X_SBIT, ///< Value ram_corrected:pierX_pi_desc_drop_x_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PIE_DMA_RDFIFO_SBIT, ///< Value ram_corrected:pierX_pie_dma_rdfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PIE_DMA_TDFIFO_SBIT, ///< Value ram_corrected:pierX_pie_dma_tdfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_0_SBIT, ///< Value ram_corrected:pierX_spare_0_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_1_SBIT, ///< Value ram_corrected:pierX_spare_1_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_2_SBIT, ///< Value ram_corrected:pierX_spare_2_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SRX_CFC_FIFO_SBIT, ///< Value ram_corrected:pierX_srx_cfc_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SRX_DFIFO_SBIT, ///< Value ram_corrected:pierX_srx_dfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_CFIFO_SBIT, ///< Value ram_corrected:pierX_stx_cfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_CHK_SM_DFIFO_SBIT, ///< Value ram_corrected:pierX_stx_chk_sm_dfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_DFIFO_SBIT, ///< Value ram_corrected:pierX_stx_dfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_PMON_PIE_X_SBIT, ///< Value ram_corrected:pierX_stx_pmon_pie_x_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_PMON_ROC_X_SBIT, ///< Value ram_corrected:pierX_stx_pmon_roc_x_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_CQ_SBIT, ///< Value ram_corrected:rdmaX_cmd_cq_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_MR_SBIT, ///< Value ram_corrected:rdmaX_cmd_mr_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_RX_SBIT, ///< Value ram_corrected:rdmaX_cmd_rx_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_TX_SBIT, ///< Value ram_corrected:rdmaX_cmd_tx_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_DMA_C2H_PLD_SBIT, ///< Value ram_corrected:rdmaX_cq_dma_c2h_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_REQ_PLD_SBIT, ///< Value ram_corrected:rdmaX_cq_req_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_SBIT, ///< Value ram_corrected:rdmaX_cq_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_MM2S_DFIFO_SBIT, ///< Value ram_corrected:rdmaX_dma_mm2s_dfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RDAT_RET_MM2S_SBIT, ///< Value ram_corrected:rdmaX_dma_rdat_ret_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RSTS_PRE_MM2S_SBIT, ///< Value ram_corrected:rdmaX_dma_rsts_pre_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RSTS_S2MM_SBIT, ///< Value ram_corrected:rdmaX_dma_rsts_s2mm_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_S2MM_DFIFO_SBIT, ///< Value ram_corrected:rdmaX_dma_s2mm_dfifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WCMD_MM2S_SBIT, ///< Value ram_corrected:rdmaX_dma_wcmd_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WCMD_S2MM_SBIT, ///< Value ram_corrected:rdmaX_dma_wcmd_s2mm_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WSTS_MM2S_SBIT, ///< Value ram_corrected:rdmaX_dma_wsts_mm2s_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WSTS_S2MM_SBIT, ///< Value ram_corrected:rdmaX_dma_wsts_s2mm_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_DW_CTL_SBIT, ///< Value ram_corrected:rdmaX_dmac_dw_ctl_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_DW_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_dw_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RCMD_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_rcmd_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RCPL_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_rcpl_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RDAT_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_rdat_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RSTS_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_rsts_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WCMD_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_wcmd_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WCPL_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_wcpl_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WDAT_CTL_SBIT, ///< Value ram_corrected:rdmaX_dmac_wdat_ctl_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WDAT_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_wdat_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WSTS_FIFO_SBIT, ///< Value ram_corrected:rdmaX_dmac_wsts_fifo_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DROP_PKT_SBIT, ///< Value ram_corrected:rdmaX_drop_pkt_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_HDR_RX_REQ_PLD_SBIT, ///< Value ram_corrected:rdmaX_hdr_rx_req_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_MM2S_INT_DATA_SBIT, ///< Value ram_corrected:rdmaX_mm2s_int_data_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_MR_LUT_SBIT, ///< Value ram_corrected:rdmaX_mr_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX2TX_INFO_SBIT, ///< Value ram_corrected:rdmaX_rx2tx_info_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_DBG_MON_LUT_SBIT, ///< Value ram_corrected:rdmaX_rx_dbg_mon_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_MCAST_GROUPS_SBIT, ///< Value ram_corrected:rdmaX_rx_mcast_groups_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_MULTICAST_PLD_SBIT, ///< Value ram_corrected:rdmaX_rx_multicast_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_QP1_VIRT_LUT_SBIT, ///< Value ram_corrected:rdmaX_rx_qp1_virt_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_QP_LUT_SBIT, ///< Value ram_corrected:rdmaX_rx_qp_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_REQ_PLD_SBIT, ///< Value ram_corrected:rdmaX_rx_req_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQ_LUT_SBIT, ///< Value ram_corrected:rdmaX_rx_rq_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQ_WR_MOV_CMD_SBIT, ///< Value ram_corrected:rdmaX_rx_rq_wr_mov_cmd_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQE_SBIT, ///< Value ram_corrected:rdmaX_rx_rqe_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RR_LUT_SBIT, ///< Value ram_corrected:rdmaX_rx_rr_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RSP_PLD_SBIT, ///< Value ram_corrected:rdmaX_rx_rsp_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_TX_RSP_SBIT, ///< Value ram_corrected:rdmaX_rx_tx_rsp_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_S2MM_PLD_SBIT, ///< Value ram_corrected:rdmaX_s2mm_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_0_SBIT, ///< Value ram_corrected:rdmaX_spare_0_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_1_SBIT, ///< Value ram_corrected:rdmaX_spare_1_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_2_SBIT, ///< Value ram_corrected:rdmaX_spare_2_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_CNP_SBIT, ///< Value ram_corrected:rdmaX_tm_cnp_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_RETRY_SBIT, ///< Value ram_corrected:rdmaX_tm_retry_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_RNR_SBIT, ///< Value ram_corrected:rdmaX_tm_rnr_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX2RX_INFO_SBIT, ///< Value ram_corrected:rdmaX_tx2rx_info_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_DBG_MON_LUT_SBIT, ///< Value ram_corrected:rdmaX_tx_dbg_mon_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_MR_DESCR_SBIT, ///< Value ram_corrected:rdmaX_tx_mr_descr_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_PLD_INL_SBIT, ///< Value ram_corrected:rdmaX_tx_pld_inl_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_PLD_SBIT, ///< Value ram_corrected:rdmaX_tx_pld_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_CMP_PRF_CMD_SBIT, ///< Value ram_corrected:rdmaX_tx_sq_cmp_prf_cmd_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_CMP_PRF_RSP_SBIT, ///< Value ram_corrected:rdmaX_tx_sq_cmp_prf_rsp_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_WR_MOV_CMD_SBIT, ///< Value ram_corrected:rdmaX_tx_sq_wr_mov_cmd_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQE_SBIT, ///< Value ram_corrected:rdmaX_tx_sqe_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_QP_LUT_SBIT, ///< Value ram_corrected:rdmaX_tx_tx_qp_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_REQ_CTX_SBIT, ///< Value ram_corrected:rdmaX_tx_tx_req_ctx_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_RR_LUT_SBIT, ///< Value ram_corrected:rdmaX_tx_tx_rr_lut_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_UC_UD_CMP_SBIT, ///< Value ram_corrected:rdmaX_tx_uc_ud_cmp_sbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RDAT_RET_MM2S_MBIT, ///< Value ram_uncorrected:pierX_dma_rdat_ret_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RSTS_PRE_MM2S_MBIT, ///< Value ram_uncorrected:pierX_dma_rsts_pre_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RSTS_S2MM_MBIT, ///< Value ram_uncorrected:pierX_dma_rsts_s2mm_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WCMD_MM2S_MBIT, ///< Value ram_uncorrected:pierX_dma_wcmd_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WCMD_S2MM_MBIT, ///< Value ram_uncorrected:pierX_dma_wcmd_s2mm_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WSTS_MM2S_MBIT, ///< Value ram_uncorrected:pierX_dma_wsts_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WSTS_S2MM_MBIT, ///< Value ram_uncorrected:pierX_dma_wsts_s2mm_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_DW_CTL_MBIT, ///< Value ram_uncorrected:pierX_dmac_dw_ctl_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_DW_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_dw_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RCMD_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_rcmd_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RCPL_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_rcpl_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RDAT_CTL_MBIT, ///< Value ram_uncorrected:pierX_dmac_rdat_ctl_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RDAT_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_rdat_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RSTS_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_rsts_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WCMD_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_wcmd_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WCPL_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_wcpl_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WDAT_CTL_MBIT, ///< Value ram_uncorrected:pierX_dmac_wdat_ctl_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WDAT_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_wdat_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WSTS_FIFO_MBIT, ///< Value ram_uncorrected:pierX_dmac_wsts_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_DMTA_MBIT, ///< Value ram_uncorrected:pierX_mem_isdx_dmta_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_DMTB_MBIT, ///< Value ram_uncorrected:pierX_mem_isdx_dmtb_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_SATA_MBIT, ///< Value ram_uncorrected:pierX_mem_isdx_sata_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_SATB_MBIT, ///< Value ram_uncorrected:pierX_mem_isdx_satb_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_STX_INS_LUTA_MBIT, ///< Value ram_uncorrected:pierX_mem_stx_ins_luta_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_STX_INS_LUTB_MBIT, ///< Value ram_uncorrected:pierX_mem_stx_ins_lutb_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_AXI_ERR_PMON_X_MBIT, ///< Value ram_uncorrected:pierX_pe_axi_err_pmon_x_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_DATA_PMON_X_MBIT, ///< Value ram_uncorrected:pierX_pe_data_pmon_x_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_DESC_DCFC_MBIT, ///< Value ram_uncorrected:pierX_pe_desc_dcfc_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PI_DESC_DCFC_MBIT, ///< Value ram_uncorrected:pierX_pi_desc_dcfc_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PI_DESC_DROP_X_MBIT, ///< Value ram_uncorrected:pierX_pi_desc_drop_x_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PIE_DMA_RDFIFO_MBIT, ///< Value ram_uncorrected:pierX_pie_dma_rdfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PIE_DMA_TDFIFO_MBIT, ///< Value ram_uncorrected:pierX_pie_dma_tdfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_0_MBIT, ///< Value ram_uncorrected:pierX_spare_0_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_1_MBIT, ///< Value ram_uncorrected:pierX_spare_1_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_2_MBIT, ///< Value ram_uncorrected:pierX_spare_2_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SRX_CFC_FIFO_MBIT, ///< Value ram_uncorrected:pierX_srx_cfc_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SRX_DFIFO_MBIT, ///< Value ram_uncorrected:pierX_srx_dfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_CFIFO_MBIT, ///< Value ram_uncorrected:pierX_stx_cfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_CHK_SM_DFIFO_MBIT, ///< Value ram_uncorrected:pierX_stx_chk_sm_dfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_DFIFO_MBIT, ///< Value ram_uncorrected:pierX_stx_dfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_PMON_PIE_X_MBIT, ///< Value ram_uncorrected:pierX_stx_pmon_pie_x_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_PMON_ROC_X_MBIT, ///< Value ram_uncorrected:pierX_stx_pmon_roc_x_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_CQ_MBIT, ///< Value ram_uncorrected:rdmaX_cmd_cq_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_MR_MBIT, ///< Value ram_uncorrected:rdmaX_cmd_mr_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_RX_MBIT, ///< Value ram_uncorrected:rdmaX_cmd_rx_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_TX_MBIT, ///< Value ram_uncorrected:rdmaX_cmd_tx_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_DMA_C2H_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_cq_dma_c2h_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_MBIT, ///< Value ram_uncorrected:rdmaX_cq_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_REQ_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_cq_req_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_MM2S_DFIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dma_mm2s_dfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RDAT_RET_MM2S_MBIT, ///< Value ram_uncorrected:rdmaX_dma_rdat_ret_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RSTS_PRE_MM2S_MBIT, ///< Value ram_uncorrected:rdmaX_dma_rsts_pre_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RSTS_S2MM_MBIT, ///< Value ram_uncorrected:rdmaX_dma_rsts_s2mm_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_S2MM_DFIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dma_s2mm_dfifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WCMD_MM2S_MBIT, ///< Value ram_uncorrected:rdmaX_dma_wcmd_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WCMD_S2MM_MBIT, ///< Value ram_uncorrected:rdmaX_dma_wcmd_s2mm_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WSTS_MM2S_MBIT, ///< Value ram_uncorrected:rdmaX_dma_wsts_mm2s_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WSTS_S2MM_MBIT, ///< Value ram_uncorrected:rdmaX_dma_wsts_s2mm_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_DW_CTL_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_dw_ctl_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_DW_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_dw_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RCMD_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_rcmd_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RCPL_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_rcpl_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RDAT_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_rdat_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RSTS_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_rsts_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WCMD_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_wcmd_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WCPL_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_wcpl_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WDAT_CTL_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_wdat_ctl_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WDAT_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_wdat_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WSTS_FIFO_MBIT, ///< Value ram_uncorrected:rdmaX_dmac_wsts_fifo_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DROP_PKT_MBIT, ///< Value ram_uncorrected:rdmaX_drop_pkt_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_HDR_RX_REQ_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_hdr_rx_req_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_MM2S_INT_DATA_MBIT, ///< Value ram_uncorrected:rdmaX_mm2s_int_data_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_MR_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_mr_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX2TX_INFO_MBIT, ///< Value ram_uncorrected:rdmaX_rx2tx_info_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_DBG_MON_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_rx_dbg_mon_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_MCAST_GROUPS_MBIT, ///< Value ram_uncorrected:rdmaX_rx_mcast_groups_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_MULTICAST_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_rx_multicast_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_QP1_VIRT_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_rx_qp1_virt_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_QP_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_rx_qp_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_REQ_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_rx_req_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQ_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_rx_rq_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQ_WR_MOV_CMD_MBIT, ///< Value ram_uncorrected:rdmaX_rx_rq_wr_mov_cmd_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQE_MBIT, ///< Value ram_uncorrected:rdmaX_rx_rqe_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RR_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_rx_rr_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RSP_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_rx_rsp_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_TX_RSP_MBIT, ///< Value ram_uncorrected:rdmaX_rx_tx_rsp_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_S2MM_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_s2mm_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_0_MBIT, ///< Value ram_uncorrected:rdmaX_spare_0_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_1_MBIT, ///< Value ram_uncorrected:rdmaX_spare_1_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_2_MBIT, ///< Value ram_uncorrected:rdmaX_spare_2_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_CNP_MBIT, ///< Value ram_uncorrected:rdmaX_tm_cnp_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_RETRY_MBIT, ///< Value ram_uncorrected:rdmaX_tm_retry_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_RNR_MBIT, ///< Value ram_uncorrected:rdmaX_tm_rnr_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX2RX_INFO_MBIT, ///< Value ram_uncorrected:rdmaX_tx2rx_info_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_DBG_MON_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_tx_dbg_mon_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_MR_DESCR_MBIT, ///< Value ram_uncorrected:rdmaX_tx_mr_descr_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_PLD_INL_MBIT, ///< Value ram_uncorrected:rdmaX_tx_pld_inl_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_PLD_MBIT, ///< Value ram_uncorrected:rdmaX_tx_pld_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_CMP_PRF_CMD_MBIT, ///< Value ram_uncorrected:rdmaX_tx_sq_cmp_prf_cmd_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_CMP_PRF_RSP_MBIT, ///< Value ram_uncorrected:rdmaX_tx_sq_cmp_prf_rsp_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_WR_MOV_CMD_MBIT, ///< Value ram_uncorrected:rdmaX_tx_sq_wr_mov_cmd_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQE_MBIT, ///< Value ram_uncorrected:rdmaX_tx_sqe_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_QP_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_tx_tx_qp_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_REQ_CTX_MBIT, ///< Value ram_uncorrected:rdmaX_tx_tx_req_ctx_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_RR_LUT_MBIT, ///< Value ram_uncorrected:rdmaX_tx_tx_rr_lut_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_UC_UD_CMP_MBIT, ///< Value ram_uncorrected:rdmaX_tx_uc_ud_cmp_mbit for instance pier_rdma of structure from ENET
   ENET_PIER_RDMA_ERROR_LAST, ///< Last value of possible error within the ENET GHES PIER_RDMA structu
} p64h_ras_enet_pier_rdma_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_1_FATAL = 0, ///< Value misc_fatal:pierX_spare_1_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_2_FATAL, ///< Value misc_fatal:pierX_spare_2_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_3_FATAL, ///< Value misc_fatal:pierX_spare_3_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_4_FATAL, ///< Value misc_fatal:pierX_spare_4_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_5_FATAL, ///< Value misc_fatal:pierX_spare_5_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_6_FATAL, ///< Value misc_fatal:pierX_spare_6_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_7_FATAL, ///< Value misc_fatal:pierX_spare_7_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SRX_ARB_LOCKUP_PIE, ///< Value misc_fatal:pierX_srx_arb_lockup_pie for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SRX_ARB_LOCKUP_ROC, ///< Value misc_fatal:pierX_srx_arb_lockup_roc for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_ARB_LOCKUP_PIE, ///< Value misc_fatal:pierX_stx_arb_lockup_pie for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_ARB_LOCKUP_ROC, ///< Value misc_fatal:pierX_stx_arb_lockup_roc for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_SOF_MISALIGN, ///< Value misc_fatal:pierX_stx_sof_misalign for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_0_FATAL, ///< Value misc_fatal:rdmaX_spare_0_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_1_FATAL, ///< Value misc_fatal:rdmaX_spare_1_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_2_FATAL, ///< Value misc_fatal:rdmaX_spare_2_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_3_FATAL, ///< Value misc_fatal:rdmaX_spare_3_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_4_FATAL, ///< Value misc_fatal:rdmaX_spare_4_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_5_FATAL, ///< Value misc_fatal:rdmaX_spare_5_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_6_FATAL, ///< Value misc_fatal:rdmaX_spare_6_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_7_FATAL, ///< Value misc_fatal:rdmaX_spare_7_fatal for instance pier_rdma_misc of structure from ENET
   ENET_PIER_RDMA_MISC_ERROR_LAST, ///< Last value of possible error within the ENET GHES PIER_RDMA_MISC structu
} p64h_ras_enet_pier_rdma_misc_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_CBC_SBIT = 0, ///< Value ram_corrected:qsys_mqs_iqs_cbc_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_FWR_STATE_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_iqs_fwr_state_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_IQC_DSCR_SBIT, ///< Value ram_corrected:qsys_mqs_iqs_iqc_dscr_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_IQC_LNK_SBIT, ///< Value ram_corrected:qsys_mqs_iqs_iqc_lnk_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_RESALL_RESCTRL_X_RES_SBIT, ///< Value ram_corrected:qsys_mqs_iqs_resall_resctrl_X_res_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_SOFPOOL_SBIT, ///< Value ram_corrected:qsys_mqs_iqs_sofpool_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_DTI_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_afi_dti_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_FRM_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_afi_frm_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_PORT_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_afi_port_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_TTI_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_afi_tti_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_EQ_DSCR_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_eqc_eq_dscr_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_LNK_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_eqc_lnk_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_QH_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_eqc_qh_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_QT_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_eqc_qt_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L0_CFG_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_l0_cfg_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L1_CFG_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_l1_cfg_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L1W_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_l1w_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L2W_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_l2w_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_ALLOC_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_qshp_alloc_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_CFG_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_qshp_cfg_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_DS_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_qshp_ds_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_STAT_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_qshp_stat_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_ENTRIES_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tas_entries_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_GATES_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tas_gates_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_LIST_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tas_list_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_DS_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tbl_X_ds_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_QS_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tbl_X_qs_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_CFG_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tbl_X_se_cfg_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_DWRR_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tbl_X_se_dwrr_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_STAT_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tbl_X_se_stat_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_TAS_GATES_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_hsch_tbl_X_tas_gates_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_MMGT_FRP_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_mmgt_frp_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_MMGT_PLNK_SBIT, ///< Value ram_corrected:qsys_mqs_oqs_mmgt_plnk_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_qlim_qlim_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SE_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_qlim_qlim_se_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_USECNT_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_qlim_usecnt_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_QOS_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_qmap_qos_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_SE_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_qmap_se_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_VPORT_TBL_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_qmap_vport_tbl_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_STAT_X_PORT_STAT_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_stat_X_port_stat_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_STAT_X_SRV_STAT_SBIT, ///< Value ram_corrected:qsys_mqs_xqs_stat_X_srv_stat_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_CORRECTED_QSYS_PMEM_PKTMEMX_SBIT, ///< Value ram_corrected:qsys_pmem_pktmemX_sbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_CBC_MBIT, ///< Value ram_uncorrected:qsys_mqs_iqs_cbc_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_FWR_STATE_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_iqs_fwr_state_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_IQC_DSCR_MBIT, ///< Value ram_uncorrected:qsys_mqs_iqs_iqc_dscr_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_IQC_LNK_MBIT, ///< Value ram_uncorrected:qsys_mqs_iqs_iqc_lnk_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_RESALL_RESCTRL_X_RES_MBIT, ///< Value ram_uncorrected:qsys_mqs_iqs_resall_resctrl_X_res_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_SOFPOOL_MBIT, ///< Value ram_uncorrected:qsys_mqs_iqs_sofpool_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_DTI_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_afi_dti_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_FRM_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_afi_frm_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_PORT_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_afi_port_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_TTI_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_afi_tti_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_EQ_DSCR_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_eqc_eq_dscr_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_LNK_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_eqc_lnk_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_QH_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_eqc_qh_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_QT_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_eqc_qt_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L0_CFG_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_l0_cfg_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L1_CFG_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_l1_cfg_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L1W_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_l1w_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L2W_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_l2w_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_ALLOC_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_qshp_alloc_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_CFG_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_qshp_cfg_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_DS_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_qshp_ds_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_STAT_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_qshp_stat_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_ENTRIES_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tas_entries_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_GATES_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tas_gates_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_LIST_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tas_list_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_DS_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_ds_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_QS_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_qs_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_CFG_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_se_cfg_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_DWRR_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_se_dwrr_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_STAT_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_se_stat_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_TAS_GATES_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_tas_gates_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_MMGT_FRP_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_mmgt_frp_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_MMGT_PLNK_MBIT, ///< Value ram_uncorrected:qsys_mqs_oqs_mmgt_plnk_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_QLIM_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_qlim_qlim_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SE_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_qlim_qlim_se_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_USECNT_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_qlim_usecnt_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_QOS_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_qmap_qos_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_SE_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_qmap_se_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_VPORT_TBL_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_qmap_vport_tbl_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_STAT_X_PORT_STAT_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_stat_X_port_stat_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_STAT_X_SRV_STAT_MBIT, ///< Value ram_uncorrected:qsys_mqs_xqs_stat_X_srv_stat_mbit for instance sqs of structure from ENET
   ENET_SQS_RAM_UNCORRECTED_QSYS_PMEM_PKTMEMX_MBIT, ///< Value ram_uncorrected:qsys_pmem_pktmemX_mbit for instance sqs of structure from ENET
   ENET_SQS_ERROR_LAST, ///< Last value of possible error within the ENET GHES SQS structu
} p64h_ras_enet_sqs_err_t;

/**
 * @brief Definitions of all errors within a structure of the ENET GHES
 */
typedef enum {
    ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XA_AR_Y = 0, ///< Value ram_corrected:vcap_super_def_Xa_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XA_CNTR, ///< Value ram_corrected:vcap_super_def_Xa_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XB_AR_Y, ///< Value ram_corrected:vcap_super_def_Xb_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XB_CNTR, ///< Value ram_corrected:vcap_super_def_Xb_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XC_AR_Y, ///< Value ram_corrected:vcap_super_def_Xc_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XC_CNTR, ///< Value ram_corrected:vcap_super_def_Xc_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_ECC_PAR_RAM, ///< Value ram_corrected:vcap_super_ecc_par_ram for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_SL_X_AR_Y, ///< Value ram_corrected:vcap_super_sl_X_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_SL_X_CNTR, ///< Value ram_corrected:vcap_super_sl_X_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XA_AR_Y, ///< Value ram_uncorrected:vcap_super_def_Xa_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XA_CNTR, ///< Value ram_uncorrected:vcap_super_def_Xa_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XB_AR_Y, ///< Value ram_uncorrected:vcap_super_def_Xb_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XB_CNTR, ///< Value ram_uncorrected:vcap_super_def_Xb_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XC_AR_Y, ///< Value ram_uncorrected:vcap_super_def_Xc_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XC_CNTR, ///< Value ram_uncorrected:vcap_super_def_Xc_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_ECC_PAR_RAM, ///< Value ram_uncorrected:vcap_super_ecc_par_ram for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_SL_X_AR_Y, ///< Value ram_uncorrected:vcap_super_sl_X_AR_Y for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_SL_X_CNTR, ///< Value ram_uncorrected:vcap_super_sl_X_cntr for instance vcap_super of structure from ENET
   ENET_VCAP_SUPER_ERROR_LAST, ///< Last value of possible error within the ENET GHES VCAP_SUPER structu
} p64h_ras_enet_vcap_super_err_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_B_PARITY = 0, ///< Value bus_ecc_corrected:nand_m_cor_err_b_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_R_PARITY, ///< Value bus_ecc_corrected:nand_m_cor_err_r_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_RDATA_PARITY, ///< Value bus_ecc_corrected:nand_m_cor_err_rdata_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AR_A_PARITY, ///< Value bus_ecc_corrected:nand_s_cor_err_ar_a_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AR_C_PARITY, ///< Value bus_ecc_corrected:nand_s_cor_err_ar_c_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AW_A_PARITY, ///< Value bus_ecc_corrected:nand_s_cor_err_aw_a_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AW_C_PARITY, ///< Value bus_ecc_corrected:nand_s_cor_err_aw_c_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_W_PARITY, ///< Value bus_ecc_corrected:nand_s_cor_err_w_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_WDATA_PARITY, ///< Value bus_ecc_corrected:nand_s_cor_err_wdata_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_B_PARITY, ///< Value bus_ecc_uncorrected:nand_m_uncor_err_b_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_R_PARITY, ///< Value bus_ecc_uncorrected:nand_m_uncor_err_r_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_RDATA_PARITY, ///< Value bus_ecc_uncorrected:nand_m_uncor_err_rdata_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AR_A_PARITY, ///< Value bus_ecc_uncorrected:nand_s_uncor_err_ar_a_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AR_C_PARITY, ///< Value bus_ecc_uncorrected:nand_s_uncor_err_ar_c_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AW_A_PARITY, ///< Value bus_ecc_uncorrected:nand_s_uncor_err_aw_a_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AW_C_PARITY, ///< Value bus_ecc_uncorrected:nand_s_uncor_err_aw_c_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_W_PARITY, ///< Value bus_ecc_uncorrected:nand_s_uncor_err_w_parity for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_WDATA_PARIT, ///< Value bus_ecc_uncorrected:nand_s_uncor_err_wdata_parit for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_CORRECTED_DESC_CTXT_MEM_ERR_COR, ///< Value ram_corrected:desc_ctxt_mem_err_cor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_CORRECTED_ECC_BUF_0_ERR_COR, ///< Value ram_corrected:ecc_buf_0_err_cor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_CORRECTED_ECC_BUF_1_ERR_COR, ///< Value ram_corrected:ecc_buf_1_err_cor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_CORRECTED_REMAP_BUF_ERR_COR, ///< Value ram_corrected:remap_buf_err_cor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_CORRECTED_TX_FIFO_ERR_COR, ///< Value ram_corrected:tx_fifo_err_cor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_UNCORRECTED_DESC_CTXT_MEM_ERR_UNCOR, ///< Value ram_uncorrected:desc_ctxt_mem_err_uncor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_UNCORRECTED_ECC_BUF_0_ERR_UNCOR, ///< Value ram_uncorrected:ecc_buf_0_err_uncor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_UNCORRECTED_ECC_BUF_1_ERR_UNCOR, ///< Value ram_uncorrected:ecc_buf_1_err_uncor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_UNCORRECTED_REMAP_BUF_ERR_UNCOR, ///< Value ram_uncorrected:remap_buf_err_uncor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RAM_UNCORRECTED_TX_FIFO_ERR_UNCOR, ///< Value ram_uncorrected:tx_fifo_err_uncor for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RESPONSE_UNCORRECTED_NAND_M_SLVERR_READ_TRANS, ///< Value response_uncorrected:nand_m_slverr_read_trans for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_RESPONSE_UNCORRECTED_NAND_M_SLVERR_WRITE_TRANS, ///< Value response_uncorrected:nand_m_slverr_write_trans for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_TRANS_DROP_NAND_S_BRESP_TIMEOUT, ///< Value trans_drop:nand_s_bresp_timeout for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_TRANS_DROP_NAND_S_DROP_READ_TRANS, ///< Value trans_drop:nand_s_drop_read_trans for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_TRANS_DROP_NAND_S_DROP_WRITE_TRANS, ///< Value trans_drop:nand_s_drop_write_trans for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_TRANS_DROP_NAND_S_NULL_WRITE_TRANS, ///< Value trans_drop:nand_s_null_write_trans for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_TRANS_DROP_NAND_S_RDATA_TIMEOUT, ///< Value trans_drop:nand_s_rdata_timeout for instance nand_ctrl of structure from NVM
   NVM_NAND_CTRL_ERROR_LAST, ///< Last value of possible error within the NVM GHES NAND_CTRL structu
} p64h_ras_nvm_nand_ctrl_err_t;

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
   NVM_NVM_EDAC_EMON_CORRECTED_SCRUB_REQ, ///< Value emon_corrected:scrub_req for instance nvm_edac of structure from NVM
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
    NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_A_PARITY = 0, ///< Value bus_ecc_corrected:cor_err_ar_a_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_C_PARITY, ///< Value bus_ecc_corrected:cor_err_ar_c_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_A_PARITY, ///< Value bus_ecc_corrected:cor_err_aw_a_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_C_PARITY, ///< Value bus_ecc_corrected:cor_err_aw_c_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_W_PARITY, ///< Value bus_ecc_corrected:cor_err_w_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_WDATA_PARITY, ///< Value bus_ecc_corrected:cor_err_wdata_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_A_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_ar_a_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_C_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_ar_c_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_A_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_aw_a_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_C_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_aw_c_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_W_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_w_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_WDATA_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_wdata_parity for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_TRANS_DROP_BRESP_TIMEOUT, ///< Value trans_drop:bresp_timeout for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_TRANS_DROP_DROP_READ_TRANS, ///< Value trans_drop:drop_read_trans for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_TRANS_DROP_DROP_WRITE_TRANS, ///< Value trans_drop:drop_write_trans for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_TRANS_DROP_NULL_WRITE_TRANS, ///< Value trans_drop:null_write_trans for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_TRANS_DROP_RDATA_TIMEOUT, ///< Value trans_drop:rdata_timeout for instance pflash_ctrl of structure from NVM
   NVM_PFLASH_CTRL_ERROR_LAST, ///< Last value of possible error within the NVM GHES PFLASH_CTRL structu
} p64h_ras_nvm_pflash_ctrl_err_t;

/**
 * @brief Definitions of all errors within a structure of the NVM GHES
 */
typedef enum {
    NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_A_PARITY = 0, ///< Value bus_ecc_corrected:cor_err_ar_a_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_C_PARITY, ///< Value bus_ecc_corrected:cor_err_ar_c_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_A_PARITY, ///< Value bus_ecc_corrected:cor_err_aw_a_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_C_PARITY, ///< Value bus_ecc_corrected:cor_err_aw_c_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_W_PARITY, ///< Value bus_ecc_corrected:cor_err_w_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_WDATA_PARITY, ///< Value bus_ecc_corrected:cor_err_wdata_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_A_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_ar_a_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_C_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_ar_c_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_A_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_aw_a_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_C_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_aw_c_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_W_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_w_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_WDATA_PARITY, ///< Value bus_ecc_uncorrected:uncor_err_wdata_parity for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_BIU0_ERR_COR, ///< Value ram_corrected:sd_data_mem_biu0_err_cor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_BIU1_ERR_COR, ///< Value ram_corrected:sd_data_mem_biu1_err_cor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_CIU0_ERR_COR, ///< Value ram_corrected:sd_data_mem_ciu0_err_cor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_CIU1_ERR_COR, ///< Value ram_corrected:sd_data_mem_ciu1_err_cor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_CORRECTED_XSPI_CONTEXT_MEM_ERR_COR, ///< Value ram_corrected:xspi_context_mem_err_cor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_CORRECTED_XSPI_DATA_MEM_ERR_COR, ///< Value ram_corrected:xspi_data_mem_err_cor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_BIU0_ERR_UNCOR, ///< Value ram_uncorrected:sd_data_mem_biu0_err_uncor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_BIU1_ERR_UNCOR, ///< Value ram_uncorrected:sd_data_mem_biu1_err_uncor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_CIU0_ERR_UNCOR, ///< Value ram_uncorrected:sd_data_mem_ciu0_err_uncor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_CIU1_ERR_UNCOR, ///< Value ram_uncorrected:sd_data_mem_ciu1_err_uncor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_UNCORRECTED_XSPI_CONTEXT_MEM_ERR_UNCOR, ///< Value ram_uncorrected:xspi_context_mem_err_uncor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_RAM_UNCORRECTED_XSPI_DATA_MEM_ERR_UNCOR, ///< Value ram_uncorrected:xspi_data_mem_err_uncor for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_TRANS_DROP_BRESP_TIMEOUT, ///< Value trans_drop:bresp_timeout for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_TRANS_DROP_DROP_READ_TRANS, ///< Value trans_drop:drop_read_trans for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_TRANS_DROP_DROP_WRITE_TRANS, ///< Value trans_drop:drop_write_trans for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_TRANS_DROP_NULL_WRITE_TRANS, ///< Value trans_drop:null_write_trans for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_TRANS_DROP_RDATA_TIMEOUT, ///< Value trans_drop:rdata_timeout for instance spi_ctrl of structure from NVM
   NVM_SPI_CTRL_ERROR_LAST, ///< Last value of possible error within the NVM GHES SPI_CTRL structu
} p64h_ras_nvm_spi_ctrl_err_t;

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
   SYS_S7_INTERRUPT_STORM, ///< Value interrupt:storm for instance s7 of structure from SYS
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
    RAS_GHES_DDR_STRUCT_EDAC = RAS_ERROR_PACK(DDR, DDR_STRUCT_EDAC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded EDAC structure ID from the DDR
    RAS_GHES_DDR_STRUCT_CTRL = RAS_ERROR_PACK(DDR, DDR_STRUCT_CTRL, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded CTRL structure ID from the DDR
    RAS_GHES_DDR_NOC_STRUCT_INITIATORS = RAS_ERROR_PACK(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded INITIATORS structure ID from the DDR_NOC
    RAS_GHES_DDR_NOC_STRUCT_TARGETS = RAS_ERROR_PACK(DDR_NOC, DDR_NOC_STRUCT_TARGETS, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded TARGETS structure ID from the DDR_NOC
    RAS_GHES_ENET_STRUCT_ASM = RAS_ERROR_PACK(ENET, ENET_STRUCT_ASM, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded ASM structure ID from the ENET
    RAS_GHES_ENET_STRUCT_ANA_AC_EACL_REW_WRAP = RAS_ERROR_PACK(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded ANA_AC_EACL_REW_WRAP structure ID from the ENET
    RAS_GHES_ENET_STRUCT_SQS = RAS_ERROR_PACK(ENET, ENET_STRUCT_SQS, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded SQS structure ID from the ENET
    RAS_GHES_ENET_STRUCT_EACL = RAS_ERROR_PACK(ENET, ENET_STRUCT_EACL, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded EACL structure ID from the ENET
    RAS_GHES_ENET_STRUCT_DSM = RAS_ERROR_PACK(ENET, ENET_STRUCT_DSM, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded DSM structure ID from the ENET
    RAS_GHES_ENET_STRUCT_VCAP_SUPER = RAS_ERROR_PACK(ENET, ENET_STRUCT_VCAP_SUPER, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded VCAP_SUPER structure ID from the ENET
    RAS_GHES_ENET_STRUCT_PIER_RDMA = RAS_ERROR_PACK(ENET, ENET_STRUCT_PIER_RDMA, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded PIER_RDMA structure ID from the ENET
    RAS_GHES_ENET_STRUCT_PIER_RDMA_MISC = RAS_ERROR_PACK(ENET, ENET_STRUCT_PIER_RDMA_MISC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded PIER_RDMA_MISC structure ID from the ENET
    RAS_GHES_ENET_STRUCT_ANACL32OAM = RAS_ERROR_PACK(ENET, ENET_STRUCT_ANACL32OAM, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded ANACL32OAM structure ID from the ENET
    RAS_GHES_ENET_STRUCT_MISC = RAS_ERROR_PACK(ENET, ENET_STRUCT_MISC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded MISC structure ID from the ENET
    RAS_GHES_NVM_STRUCT_SRAM_EDAC = RAS_ERROR_PACK(NVM, NVM_STRUCT_SRAM_EDAC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded SRAM_EDAC structure ID from the NVM
    RAS_GHES_NVM_STRUCT_NVM_EDAC = RAS_ERROR_PACK(NVM, NVM_STRUCT_NVM_EDAC, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded NVM_EDAC structure ID from the NVM
    RAS_GHES_NVM_STRUCT_PFLASH_CTRL = RAS_ERROR_PACK(NVM, NVM_STRUCT_PFLASH_CTRL, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded PFLASH_CTRL structure ID from the NVM
    RAS_GHES_NVM_STRUCT_SPI_CTRL = RAS_ERROR_PACK(NVM, NVM_STRUCT_SPI_CTRL, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded SPI_CTRL structure ID from the NVM
    RAS_GHES_NVM_STRUCT_NAND_CTRL = RAS_ERROR_PACK(NVM, NVM_STRUCT_NAND_CTRL, RAS_NA, RAS_NA, RAS_NA), ///< Uniquely encoded NAND_CTRL structure ID from the NVM
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
    RAS_ERR_ID_DDR_CTRL_MISC_CONTROLLER_INT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_CTRL, DDR_CTRL_MISC_CONTROLLER_INT), ///< misc:controller_int for instance ctrl of structure from DDR
    RAS_ERR_ID_DDR_CTRL_MISC_PERF_MON_CORE_FIFO_FULL = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_CTRL, DDR_CTRL_MISC_PERF_MON_CORE_FIFO_FULL), ///< misc:perf_mon_core_fifo_full for instance ctrl of structure from DDR
    RAS_ERR_ID_DDR_CTRL_MISC_PERF_MON_PORT_FIFO_FULL = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_CTRL, DDR_CTRL_MISC_PERF_MON_PORT_FIFO_FULL), ///< misc:perf_mon_port_fifo_full for instance ctrl of structure from DDR
    RAS_ERR_ID_DDR_CTRL_MISC_Q_ALMOST_FULL = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_CTRL, DDR_CTRL_MISC_Q_ALMOST_FULL), ///< misc:q_almost_full for instance ctrl of structure from DDR
    RAS_ERR_ID_DDR_CTRL_RAM_CORRECTED_CTRL_CORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_CTRL, DDR_CTRL_RAM_CORRECTED_CTRL_CORR_ECC_ERR), ///< ram_corrected:ctrl_corr_ecc_err for instance ctrl of structure from DDR
    RAS_ERR_ID_DDR_CTRL_RAM_UNCORRECTED_CTRL_UNCORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_CTRL, DDR_CTRL_RAM_UNCORRECTED_CTRL_UNCORR_ECC_ERR), ///< ram_uncorrected:ctrl_uncorr_ecc_err for instance ctrl of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_DEC_BCFP = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_DEC_BCFP), ///< app:dec_bcfp for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_DEC_POISON_DET = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_DEC_POISON_DET), ///< app:dec_poison_det for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_MEM_INIT_DONE_INT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_MEM_INIT_DONE_INT), ///< app:mem_init_done_int for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_PATROL_SCRUB_COMPLETE = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_PATROL_SCRUB_COMPLETE), ///< app:patrol_scrub_complete for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_RD_COH_BLOCK = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_RD_COH_BLOCK), ///< app:rd_coh_block for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_WDCAP_SPARSE_WRITE = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_WDCAP_SPARSE_WRITE), ///< app:wdcap_sparse_write for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_APP_WR_COH_BLOCK = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_APP_WR_COH_BLOCK), ///< app:wr_coh_block for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_FULL), ///< emon_corrected:emon_cor_buf_full for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THLD = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_HIGH_THLD), ///< emon_corrected:emon_cor_buf_high_thld for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_COR_BUF_OVRFLW), ///< emon_corrected:emon_cor_buf_ovrflw for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_FSM_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_FSM_ERR), ///< emon_corrected:emon_fsm_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_STAT_BUF_FULL), ///< emon_corrected:emon_stat_buf_full for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_STAT_BUF_OVRFLW), ///< emon_corrected:emon_stat_buf_ovrflw for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_FULL), ///< emon_corrected:emon_uncor_buf_full for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THLD = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_HIGH_THLD), ///< emon_corrected:emon_uncor_buf_high_thld for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_EMON_UNCOR_BUF_OVRFLW), ///< emon_corrected:emon_uncor_buf_ovrflw for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_COR), ///< emon_corrected:err_mon_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_COR_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_COR_RAM_COR_ECC_ERR), ///< emon_corrected:err_mon_cor_ram_cor_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_COR_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_COR_RAM_UNCOR_ECC_ERR), ///< emon_corrected:err_mon_cor_ram_uncor_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_STAT_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_STAT_RAM_COR_ECC_ERR), ///< emon_corrected:err_mon_stat_ram_cor_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_STAT_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_STAT_RAM_UNCOR_ECC_ERR), ///< emon_corrected:err_mon_stat_ram_uncor_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_UNCOR_RAM_COR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_UNCOR_RAM_COR_ECC_ERR), ///< emon_corrected:err_mon_uncor_ram_cor_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_CORRECTED_ERR_MON_UNCOR_RAM_UNCOR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_CORRECTED_ERR_MON_UNCOR_RAM_UNCOR_ECC_ERR), ///< emon_corrected:err_mon_uncor_ram_uncor_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_UNCORRECTED_ERR_MON_ADDR_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_UNCORRECTED_ERR_MON_ADDR_ERR), ///< emon_uncorrected:err_mon_addr_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_EMON_UNCORRECTED_ERR_MON_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_EMON_UNCORRECTED_ERR_MON_UNCOR), ///< emon_uncorrected:err_mon_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_BID_PARITY = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_BID_PARITY), ///< fault:err_bid_parity for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_BPARITY = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_BPARITY), ///< fault:err_bparity for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_RCTRL_PARITY = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_RCTRL_PARITY), ///< fault:err_rctrl_parity for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_RDATA_PARITY = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_RDATA_PARITY), ///< fault:err_rdata_parity for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_READ_CTXT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_READ_CTXT), ///< fault:err_read_ctxt for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_REMOVE_READ_COH = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_REMOVE_READ_COH), ///< fault:err_remove_read_coh for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_REMOVE_WRITE_COH = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_REMOVE_WRITE_COH), ///< fault:err_remove_write_coh for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_RID_PARITY = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_RID_PARITY), ///< fault:err_rid_parity for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_ERR_WRITE_CTX = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_ERR_WRITE_CTX), ///< fault:err_write_ctx for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_PSCRUB_FSM_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_PSCRUB_FSM_ERR), ///< fault:pscrub_fsm_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RAM_CRPT_FSM_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RAM_CRPT_FSM_ERR), ///< fault:ram_crpt_fsm_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RARB_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RARB_ERR), ///< fault:rarb_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RDCAP_BYP_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RDCAP_BYP_OVERFLOW), ///< fault:rdcap_byp_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RDCAP_BYP_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RDCAP_BYP_UNDERFLOW), ///< fault:rdcap_byp_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RDCAP_BYPASS_CTX_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RDCAP_BYPASS_CTX_OVERFLOW), ///< fault:rdcap_bypass_ctx_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RDCAP_BYPASS_CTX_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RDCAP_BYPASS_CTX_UNDERFLOW), ///< fault:rdcap_bypass_ctx_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RDCAP_CTX_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RDCAP_CTX_OVERFLOW), ///< fault:rdcap_ctx_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RDCAP_CTX_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RDCAP_CTX_UNDERFLOW), ///< fault:rdcap_ctx_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_CAM_RMV_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_CAM_RMV_ERR), ///< fault:rmw_cam_rmv_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_CAM_SENT_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_CAM_SENT_ERR), ///< fault:rmw_cam_sent_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_CTX_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_CTX_OVERFLOW), ///< fault:rmw_ctx_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_CTX_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_CTX_UNDERFLOW), ///< fault:rmw_ctx_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_ID_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_ID_OVERFLOW), ///< fault:rmw_id_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_ID_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_ID_UNDERFLOW), ///< fault:rmw_id_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_MERGE_INFO_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_MERGE_INFO_ERR), ///< fault:rmw_merge_info_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_RDCAP_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_RDCAP_OVERFLOW), ///< fault:rmw_rdcap_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_RDCAP_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_RDCAP_UNDERFLOW), ///< fault:rmw_rdcap_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_SCRUB_CTX_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_SCRUB_CTX_ERR), ///< fault:rmw_scrub_ctx_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_TRANS0_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_TRANS0_ERR), ///< fault:rmw_trans0_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RMW_TRANS1_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RMW_TRANS1_ERR), ///< fault:rmw_trans1_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_RS_DEC_CFP_ENABLED = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_RS_DEC_CFP_ENABLED), ///< fault:rs_dec_cfp_enabled for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WARB_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WARB_ERR), ///< fault:warb_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDCAP_CTX_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDCAP_CTX_OVERFLOW), ///< fault:wdcap_ctx_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDCAP_CTX_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDCAP_CTX_UNDERFLOW), ///< fault:wdcap_ctx_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDCAP_STAGE2_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDCAP_STAGE2_OVERFLOW), ///< fault:wdcap_stage2_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDCAP_STAGE2_RMW_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDCAP_STAGE2_RMW_OVERFLOW), ///< fault:wdcap_stage2_rmw_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDCAP_STAGE2_RMW_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDCAP_STAGE2_RMW_UNDERFLOW), ///< fault:wdcap_stage2_rmw_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDCAP_STAGE2_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDCAP_STAGE2_UNDERFLOW), ///< fault:wdcap_stage2_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDRESP_CTX_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDRESP_CTX_OVERFLOW), ///< fault:wdresp_ctx_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDRESP_CTX_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDRESP_CTX_UNDERFLOW), ///< fault:wdresp_ctx_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDRESP_OVERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDRESP_OVERFLOW), ///< fault:wdresp_overflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_WDRESP_UNDERFLOW = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_WDRESP_UNDERFLOW), ///< fault:wdresp_underflow for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_CORRECTED_RCMD_BUS_ECC_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_CORRECTED_RCMD_BUS_ECC_COR), ///< fault_corrected:rcmd_bus_ecc_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_CORRECTED_RDGEN_BUS_ECC_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_CORRECTED_RDGEN_BUS_ECC_COR), ///< fault_corrected:rdgen_bus_ecc_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_CORRECTED_WCMD_BUS_ECC_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_CORRECTED_WCMD_BUS_ECC_COR), ///< fault_corrected:wcmd_bus_ecc_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_CORRECTED_WDCAP_BUS_ECC_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_CORRECTED_WDCAP_BUS_ECC_COR), ///< fault_corrected:wdcap_bus_ecc_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_CORRECTED_WDGEN_BUS_ECC_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_CORRECTED_WDGEN_BUS_ECC_COR), ///< fault_corrected:wdgen_bus_ecc_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_FAULT_CORRECTED_WDGEN_RS_ENC_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_FAULT_CORRECTED_WDGEN_RS_ENC_COR), ///< fault_corrected:wdgen_rs_enc_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_DEC_DATA_RAM_CORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_DEC_DATA_RAM_CORR_ECC_ERR), ///< ram_corrected:dec_data_ram_corr_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_DEC_ERR_RAM_CORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_DEC_ERR_RAM_CORR_ECC_ERR), ///< ram_corrected:dec_err_ram_corr_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_DEC_SYNBQS_RAM_CORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_DEC_SYNBQS_RAM_CORR_ECC_ERR), ///< ram_corrected:dec_synbqs_ram_corr_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_RDCAP_BYPASS_CTX_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_RDCAP_BYPASS_CTX_RAM_COR), ///< ram_corrected:rdcap_bypass_ctx_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_RDCAP_BYPASS_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_RDCAP_BYPASS_RAM_COR), ///< ram_corrected:rdcap_bypass_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_RDCAP_CTX_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_RDCAP_CTX_RAM_COR), ///< ram_corrected:rdcap_ctx_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_RMW_CTX_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_RMW_CTX_RAM_COR), ///< ram_corrected:rmw_ctx_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_RMW_DATA_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_RMW_DATA_RAM_COR), ///< ram_corrected:rmw_data_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_WDCAP_CTX_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_WDCAP_CTX_RAM_COR), ///< ram_corrected:wdcap_ctx_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_WDCAP_STAGE2_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_WDCAP_STAGE2_RAM_COR), ///< ram_corrected:wdcap_stage2_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_CORRECTED_WDRESP_CTX_RAM_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_CORRECTED_WDRESP_CTX_RAM_COR), ///< ram_corrected:wdresp_ctx_ram_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_DEC_DATA_RAM_UNCORR_ECC_ERR), ///< ram_uncorrected:dec_data_ram_uncorr_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_DEC_ERR_RAM_UNCORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_DEC_ERR_RAM_UNCORR_ECC_ERR), ///< ram_uncorrected:dec_err_ram_uncorr_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_DEC_SYNBQS_RAM_UNCORR_ECC_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_DEC_SYNBQS_RAM_UNCORR_ECC_ERR), ///< ram_uncorrected:dec_synbqs_ram_uncorr_ecc_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_RDCAP_BYPASS_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_RDCAP_BYPASS_CTX_RAM_UNCOR), ///< ram_uncorrected:rdcap_bypass_ctx_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_RDCAP_BYPASS_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_RDCAP_BYPASS_RAM_UNCOR), ///< ram_uncorrected:rdcap_bypass_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_RDCAP_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_RDCAP_CTX_RAM_UNCOR), ///< ram_uncorrected:rdcap_ctx_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_RMW_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_RMW_CTX_RAM_UNCOR), ///< ram_uncorrected:rmw_ctx_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_RMW_DATA_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_RMW_DATA_RAM_UNCOR), ///< ram_uncorrected:rmw_data_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_WDCAP_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_WDCAP_CTX_RAM_UNCOR), ///< ram_uncorrected:wdcap_ctx_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_WDCAP_STAGE2_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_WDCAP_STAGE2_RAM_UNCOR), ///< ram_uncorrected:wdcap_stage2_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_RAM_UNCORRECTED_WDRESP_CTX_RAM_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_RAM_UNCORRECTED_WDRESP_CTX_RAM_UNCOR), ///< ram_uncorrected:wdresp_ctx_ram_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_READ_TIMEOUT_RCMD_TIMEOUT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_READ_TIMEOUT_RCMD_TIMEOUT), ///< read_timeout:rcmd_timeout for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_READ_TIMEOUT_RDCAP_TIMEOUT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_READ_TIMEOUT_RDCAP_TIMEOUT), ///< read_timeout:rdcap_timeout for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RCMD_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RCMD_BUS_ECC_UNCOR), ///< trans_drop:rcmd_bus_ecc_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RCMD_DROP_TRANS = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RCMD_DROP_TRANS), ///< trans_drop:rcmd_drop_trans for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RDCAP_DROP_TRANS = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RDCAP_DROP_TRANS), ///< trans_drop:rdcap_drop_trans for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RDGEN_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RDGEN_BUS_ECC_UNCOR), ///< trans_drop:rdgen_bus_ecc_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_READ_TRANS_ERR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_READ_TRANS_ERR), ///< trans_drop:read_trans_err for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_0_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_0_COR), ///< trans_drop:rmw_bus_ecc_0_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_0_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_0_UNCOR), ///< trans_drop:rmw_bus_ecc_0_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_1_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_1_COR), ///< trans_drop:rmw_bus_ecc_1_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_1_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_1_UNCOR), ///< trans_drop:rmw_bus_ecc_1_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_2_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_2_COR), ///< trans_drop:rmw_bus_ecc_2_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_2_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_2_UNCOR), ///< trans_drop:rmw_bus_ecc_2_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_3_COR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_3_COR), ///< trans_drop:rmw_bus_ecc_3_cor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_3_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_RMW_BUS_ECC_3_UNCOR), ///< trans_drop:rmw_bus_ecc_3_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_UNKN_RD_RESP = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_UNKN_RD_RESP), ///< trans_drop:unkn_rd_resp for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WCMD_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WCMD_BUS_ECC_UNCOR), ///< trans_drop:wcmd_bus_ecc_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WCMD_DROP_TRANS = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WCMD_DROP_TRANS), ///< trans_drop:wcmd_drop_trans for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WDCAP_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WDCAP_BUS_ECC_UNCOR), ///< trans_drop:wdcap_bus_ecc_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WDGEN_BUS_ECC_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WDGEN_BUS_ECC_UNCOR), ///< trans_drop:wdgen_bus_ecc_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WDGEN_DROP_TRANS = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WDGEN_DROP_TRANS), ///< trans_drop:wdgen_drop_trans for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WDGEN_RS_ENC_UNCOR = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WDGEN_RS_ENC_UNCOR), ///< trans_drop:wdgen_rs_enc_uncor for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_TRANS_DROP_WDRESP_DROP_TRANS = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_TRANS_DROP_WDRESP_DROP_TRANS), ///< trans_drop:wdresp_drop_trans for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_WRITE_TIMEOUT_WCMD_TIMEOUT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_WRITE_TIMEOUT_WCMD_TIMEOUT), ///< write_timeout:wcmd_timeout for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_WRITE_TIMEOUT_WDGEN_TIMEOUT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_WRITE_TIMEOUT_WDGEN_TIMEOUT), ///< write_timeout:wdgen_timeout for instance edac of structure from DDR
    RAS_ERR_ID_DDR_EDAC_WRITE_TIMEOUT_WDRESP_TIMEOUT = RAS_ERROR_ENCODE(DDR, DDR_STRUCT_EDAC, DDR_EDAC_WRITE_TIMEOUT_WDRESP_TIMEOUT), ///< write_timeout:wdresp_timeout for instance edac of structure from DDR
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_CRITICAL_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_CRITICAL_COMPARATOR_TREE), ///< critical:critical_comparator_tree for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_FLT_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_FLT_SECDED_CORR), ///< critical:flt_secded_corr for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_FLT_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_FLT_SECDED_UNCORR), ///< critical:flt_secded_uncorr for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_HANDSHAKE_RETRACTION = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_HANDSHAKE_RETRACTION), ///< critical:handshake_retraction for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_INTERNAL_FSM = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_INTERNAL_FSM), ///< critical:internal_fsm for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_JUMPER_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_JUMPER_PARITY), ///< critical:jumper_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_LATENT_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_LATENT_COMPARATOR_TREE), ///< critical:latent_comparator_tree for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_LATENT_TIMEOUT = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_LATENT_TIMEOUT), ///< critical:latent_timeout for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_MAJOR_TIMEOUT = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_MAJOR_TIMEOUT), ///< critical:major_timeout for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_PACKET_FRAMING = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_PACKET_FRAMING), ///< critical:packet_framing for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_PACKET_WORDNUMBER = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_PACKET_WORDNUMBER), ///< critical:packet_wordnumber for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_PACKET_WRONGPATH = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_PACKET_WRONGPATH), ///< critical:packet_wrongpath for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_POWER_DISCONNECT_ERROR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_POWER_DISCONNECT_ERROR), ///< critical:power_disconnect_error for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_POWER_MAIN_FAULT_CONTROL_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_POWER_MAIN_FAULT_CONTROL_PARITY), ///< critical:power_main_fault_control_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_CRITICAL_QOS_GENERATOR_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_CRITICAL_QOS_GENERATOR_PARITY), ///< critical:qos_generator_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_CRITICAL_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_CRITICAL_COMPARATOR_TREE), ///< major:critical_comparator_tree for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_FLT_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_FLT_SECDED_CORR), ///< major:flt_secded_corr for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_FLT_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_FLT_SECDED_UNCORR), ///< major:flt_secded_uncorr for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_HANDSHAKE_RETRACTION = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_HANDSHAKE_RETRACTION), ///< major:handshake_retraction for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_INTERNAL_FSM = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_INTERNAL_FSM), ///< major:internal_fsm for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_JUMPER_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_JUMPER_PARITY), ///< major:jumper_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_LATENT_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_LATENT_COMPARATOR_TREE), ///< major:latent_comparator_tree for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_LATENT_TIMEOUT = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_LATENT_TIMEOUT), ///< major:latent_timeout for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_MAJOR_TIMEOUT = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_MAJOR_TIMEOUT), ///< major:major_timeout for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_PACKET_FRAMING = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_PACKET_FRAMING), ///< major:packet_framing for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_PACKET_WORDNUMBER = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_PACKET_WORDNUMBER), ///< major:packet_wordnumber for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_PACKET_WRONGPATH = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_PACKET_WRONGPATH), ///< major:packet_wrongpath for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_POWER_DISCONNECT_ERROR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_POWER_DISCONNECT_ERROR), ///< major:power_disconnect_error for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_POWER_MAIN_FAULT_CONTROL_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_POWER_MAIN_FAULT_CONTROL_PARITY), ///< major:power_main_fault_control_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MAJOR_QOS_GENERATOR_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MAJOR_QOS_GENERATOR_PARITY), ///< major:qos_generator_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_CRITICAL_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_CRITICAL_COMPARATOR_TREE), ///< minor:critical_comparator_tree for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_FLT_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_FLT_SECDED_CORR), ///< minor:flt_secded_corr for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_FLT_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_FLT_SECDED_UNCORR), ///< minor:flt_secded_uncorr for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_HANDSHAKE_RETRACTION = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_HANDSHAKE_RETRACTION), ///< minor:handshake_retraction for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_INTERNAL_FSM = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_INTERNAL_FSM), ///< minor:internal_fsm for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_JUMPER_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_JUMPER_PARITY), ///< minor:jumper_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_LATENT_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_LATENT_COMPARATOR_TREE), ///< minor:latent_comparator_tree for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_LATENT_TIMEOUT = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_LATENT_TIMEOUT), ///< minor:latent_timeout for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_MAJOR_TIMEOUT = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_MAJOR_TIMEOUT), ///< minor:major_timeout for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_PACKET_FRAMING = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_PACKET_FRAMING), ///< minor:packet_framing for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_PACKET_WORDNUMBER = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_PACKET_WORDNUMBER), ///< minor:packet_wordnumber for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_PACKET_WRONGPATH = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_PACKET_WRONGPATH), ///< minor:packet_wrongpath for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_POWER_DISCONNECT_ERROR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_POWER_DISCONNECT_ERROR), ///< minor:power_disconnect_error for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_POWER_MAIN_FAULT_CONTROL_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_POWER_MAIN_FAULT_CONTROL_PARITY), ///< minor:power_main_fault_control_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_INITIATORS_MINOR_QOS_GENERATOR_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_INITIATORS, DDR_NOC_INITIATORS_MINOR_QOS_GENERATOR_PARITY), ///< minor:qos_generator_parity for instance initiators of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_AXI_RDATA_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_AXI_RDATA_SECDED_CORR), ///< critical:axi_rdata_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_AXI_RDATA_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_AXI_RDATA_SECDED_UNCORR), ///< critical:axi_rdata_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_AXI_WRESP_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_AXI_WRESP_SECDED_CORR), ///< critical:axi_wresp_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_AXI_WRESP_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_AXI_WRESP_SECDED_UNCORR), ///< critical:axi_wresp_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_CRITICAL_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_CRITICAL_COMPARATOR_TREE), ///< critical:critical_comparator_tree for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_FLT_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_FLT_SECDED_CORR), ///< critical:flt_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_FLT_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_FLT_SECDED_UNCORR), ///< critical:flt_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_HANDSHAKE_RETRACTION = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_HANDSHAKE_RETRACTION), ///< critical:handshake_retraction for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_INTERNAL_FSM = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_INTERNAL_FSM), ///< critical:internal_fsm for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_JUMPER_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_JUMPER_PARITY), ///< critical:jumper_parity for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_LATENT_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_LATENT_COMPARATOR_TREE), ///< critical:latent_comparator_tree for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_PACKET_FRAMING = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_PACKET_FRAMING), ///< critical:packet_framing for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_PACKET_WORDNUMBER = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_PACKET_WORDNUMBER), ///< critical:packet_wordnumber for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_PACKET_WRONGPATH = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_PACKET_WRONGPATH), ///< critical:packet_wrongpath for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_CRITICAL_POWER_MAIN_FAULT_CONTROL_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_CRITICAL_POWER_MAIN_FAULT_CONTROL_PARITY), ///< critical:power_main_fault_control_parity for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_AXI_RDATA_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_AXI_RDATA_SECDED_CORR), ///< major:axi_rdata_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_AXI_RDATA_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_AXI_RDATA_SECDED_UNCORR), ///< major:axi_rdata_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_AXI_WRESP_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_AXI_WRESP_SECDED_CORR), ///< major:axi_wresp_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_AXI_WRESP_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_AXI_WRESP_SECDED_UNCORR), ///< major:axi_wresp_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_CRITICAL_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_CRITICAL_COMPARATOR_TREE), ///< major:critical_comparator_tree for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_FLT_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_FLT_SECDED_CORR), ///< major:flt_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_FLT_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_FLT_SECDED_UNCORR), ///< major:flt_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_HANDSHAKE_RETRACTION = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_HANDSHAKE_RETRACTION), ///< major:handshake_retraction for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_INTERNAL_FSM = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_INTERNAL_FSM), ///< major:internal_fsm for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_JUMPER_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_JUMPER_PARITY), ///< major:jumper_parity for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_LATENT_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_LATENT_COMPARATOR_TREE), ///< major:latent_comparator_tree for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_PACKET_FRAMING = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_PACKET_FRAMING), ///< major:packet_framing for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_PACKET_WORDNUMBER = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_PACKET_WORDNUMBER), ///< major:packet_wordnumber for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_PACKET_WRONGPATH = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_PACKET_WRONGPATH), ///< major:packet_wrongpath for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MAJOR_POWER_MAIN_FAULT_CONTROL_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MAJOR_POWER_MAIN_FAULT_CONTROL_PARITY), ///< major:power_main_fault_control_parity for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_AXI_RDATA_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_AXI_RDATA_SECDED_CORR), ///< minor:axi_rdata_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_AXI_RDATA_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_AXI_RDATA_SECDED_UNCORR), ///< minor:axi_rdata_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_AXI_WRESP_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_AXI_WRESP_SECDED_CORR), ///< minor:axi_wresp_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_AXI_WRESP_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_AXI_WRESP_SECDED_UNCORR), ///< minor:axi_wresp_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_CRITICAL_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_CRITICAL_COMPARATOR_TREE), ///< minor:critical_comparator_tree for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_FLT_SECDED_CORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_FLT_SECDED_CORR), ///< minor:flt_secded_corr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_FLT_SECDED_UNCORR = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_FLT_SECDED_UNCORR), ///< minor:flt_secded_uncorr for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_HANDSHAKE_RETRACTION = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_HANDSHAKE_RETRACTION), ///< minor:handshake_retraction for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_INTERNAL_FSM = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_INTERNAL_FSM), ///< minor:internal_fsm for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_JUMPER_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_JUMPER_PARITY), ///< minor:jumper_parity for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_LATENT_COMPARATOR_TREE = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_LATENT_COMPARATOR_TREE), ///< minor:latent_comparator_tree for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_PACKET_FRAMING = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_PACKET_FRAMING), ///< minor:packet_framing for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_PACKET_WORDNUMBER = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_PACKET_WORDNUMBER), ///< minor:packet_wordnumber for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_PACKET_WRONGPATH = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_PACKET_WRONGPATH), ///< minor:packet_wrongpath for instance targets of structure from DDR_NOC
    RAS_ERR_ID_DDR_NOC_TARGETS_MINOR_POWER_MAIN_FAULT_CONTROL_PARITY = RAS_ERROR_ENCODE(DDR_NOC, DDR_NOC_STRUCT_TARGETS, DDR_NOC_TARGETS_MINOR_POWER_MAIN_FAULT_CONTROL_PARITY), ///< minor:power_main_fault_control_parity for instance targets of structure from DDR_NOC
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_FRER_GEN_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_FRER_GEN_CFG), ///< ram_corrected:ana_ac_frer_gen_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_FRER_GEN_STA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_FRER_GEN_STA), ///< ram_corrected:ana_ac_frer_gen_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_AGGR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_AGGR), ///< ram_corrected:ana_ac_logic_aggr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_CSD = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_CSD), ///< ram_corrected:ana_ac_logic_csd for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_LAG_RST = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_LAG_RST), ///< ram_corrected:ana_ac_logic_lag_rst for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_PGID = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_PGID), ///< ram_corrected:ana_ac_logic_pgid for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_SRC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_LOGIC_SRC), ///< ram_corrected:ana_ac_logic_src for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_PDU_MOD_CONT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_PDU_MOD_CONT), ///< ram_corrected:ana_ac_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_VOE_PORT_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_VOE_PORT_LM_CNT), ///< ram_corrected:ana_ac_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_VOE_SRV_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_OAM_VOE_SRV_LM_CNT), ///< ram_corrected:ana_ac_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_BDLB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_BDLB), ///< ram_corrected:ana_ac_pol_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_BUM_SLB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_BUM_SLB), ///< ram_corrected:ana_ac_pol_bum_slb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_CTRL_CONTEXT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_CTRL_CONTEXT), ///< ram_corrected:ana_ac_pol_ctrl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_CTRL_POL_PORT_CTRL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_CTRL_POL_PORT_CTRL), ///< ram_corrected:ana_ac_pol_ctrl_pol_port_ctrl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_PORT_POL_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_PORT_POL_CFG), ///< ram_corrected:ana_ac_pol_port_pol_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_PORT_POL_LB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_PORT_POL_LB), ///< ram_corrected:ana_ac_pol_port_pol_lb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_INH_TOKENS = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_INH_TOKENS), ///< ram_corrected:ana_ac_pol_sdlb_inh_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LB_CLOSED = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LB_CLOSED), ///< ram_corrected:ana_ac_pol_sdlb_lb_closed for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LB_TOKENS = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LB_TOKENS), ///< ram_corrected:ana_ac_pol_sdlb_lb_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LBSET_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_POL_SDLB_LBSET_TBL), ///< ram_corrected:ana_ac_pol_sdlb_lbset_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ACL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ACL), ///< ram_corrected:ana_ac_stat_acl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_BDLB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_BDLB), ///< ram_corrected:ana_ac_stat_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_BUM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_BUM), ///< ram_corrected:ana_ac_stat_bum for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ERLEG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ERLEG), ///< ram_corrected:ana_ac_stat_erleg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_IRLEG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_IRLEG), ///< ram_corrected:ana_ac_stat_irleg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ISDX = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_ISDX), ///< ram_corrected:ana_ac_stat_isdx for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_PORT_CR_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_PORT_CR_CFG), ///< ram_corrected:ana_ac_stat_port_cr_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_PORT_IR_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_PORT_IR_CFG), ///< ram_corrected:ana_ac_stat_port_ir_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_QUEUE = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STAT_QUEUE), ///< ram_corrected:ana_ac_stat_queue for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STREAM_GATES = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_STREAM_GATES), ///< ram_corrected:ana_ac_stream_gates for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_TSN_SF_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_TSN_SF_CFG), ///< ram_corrected:ana_ac_tsn_sf_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_TSN_SF_STA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_ANA_AC_TSN_SF_STA), ///< ram_corrected:ana_ac_tsn_sf_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CELL_INFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CELL_INFO), ///< ram_corrected:eacl_cell_info for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CNT_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CNT_TBL), ///< ram_corrected:eacl_cnt_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CONTEXT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_CONTEXT), ///< ram_corrected:eacl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_DEF_AR_X = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_DEF_AR_X), ///< ram_corrected:eacl_def_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_DEF_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_DEF_CNTR), ///< ram_corrected:eacl_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_ECC_PAR_RAM), ///< ram_corrected:eacl_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CCFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CCFG), ///< ram_corrected:eacl_frer_ccfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CCNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CCNT), ///< ram_corrected:eacl_frer_ccnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CSTA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_CSTA), ///< ram_corrected:eacl_frer_csta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MAP = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MAP), ///< ram_corrected:eacl_frer_map for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MCFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MCFG), ///< ram_corrected:eacl_frer_mcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MCNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MCNT), ///< ram_corrected:eacl_frer_mcnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MSTA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_FRER_MSTA), ///< ram_corrected:eacl_frer_msta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_IF_MAP = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_IF_MAP), ///< ram_corrected:eacl_if_map for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_KEY_SEL_PROF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_KEY_SEL_PROF), ///< ram_corrected:eacl_key_sel_prof for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_SL_0_AR_X = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_SL_0_AR_X), ///< ram_corrected:eacl_sl_0_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_SL_0_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_SL_0_CNTR), ///< ram_corrected:eacl_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_STAT_EACL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_EACL_STAT_EACL), ///< ram_corrected:eacl_stat_eacl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_ENCAP = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_ENCAP), ///< ram_corrected:rew_encap for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_ISDX_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_ISDX_TBL), ///< ram_corrected:rew_isdx_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAC_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAC_TBL), ///< ram_corrected:rew_mac_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAP_RES_A = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAP_RES_A), ///< ram_corrected:rew_map_res_a for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAP_RES_B = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MAP_RES_B), ///< ram_corrected:rew_map_res_b for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MIP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_MIP_TBL), ///< ram_corrected:rew_mip_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_PDU_MOD_CONT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_PDU_MOD_CONT), ///< ram_corrected:rew_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_VOE_PORT_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_VOE_PORT_LM_CNT), ///< ram_corrected:rew_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_VOE_SRV_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_OAM_VOE_SRV_LM_CNT), ///< ram_corrected:rew_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_PORTCFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_PORTCFG), ///< ram_corrected:rew_portcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_PTP_SEQ = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_PTP_SEQ), ///< ram_corrected:rew_ptp_seq for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_DEF_AR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_DEF_AR), ///< ram_corrected:rew_vcap_es0_def_ar for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_DEF_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_DEF_CNTR), ///< ram_corrected:rew_vcap_es0_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_ECC_PAR_RAM), ///< ram_corrected:rew_vcap_es0_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_SL_0_AR_0 = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_SL_0_AR_0), ///< ram_corrected:rew_vcap_es0_sl_0_ar_0 for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_SL_0_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VCAP_ES0_SL_0_CNTR), ///< ram_corrected:rew_vcap_es0_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VMID = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_CORRECTED_REW_VMID), ///< ram_corrected:rew_vmid for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_FRER_GEN_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_FRER_GEN_CFG), ///< ram_uncorrected:ana_ac_frer_gen_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_FRER_GEN_STA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_FRER_GEN_STA), ///< ram_uncorrected:ana_ac_frer_gen_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_AGGR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_AGGR), ///< ram_uncorrected:ana_ac_logic_aggr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_CSD = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_CSD), ///< ram_uncorrected:ana_ac_logic_csd for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_LAG_RST = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_LAG_RST), ///< ram_uncorrected:ana_ac_logic_lag_rst for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_PGID = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_PGID), ///< ram_uncorrected:ana_ac_logic_pgid for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_SRC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_LOGIC_SRC), ///< ram_uncorrected:ana_ac_logic_src for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_PDU_MOD_CONT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_PDU_MOD_CONT), ///< ram_uncorrected:ana_ac_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_VOE_PORT_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_VOE_PORT_LM_CNT), ///< ram_uncorrected:ana_ac_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_VOE_SRV_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_OAM_VOE_SRV_LM_CNT), ///< ram_uncorrected:ana_ac_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_BDLB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_BDLB), ///< ram_uncorrected:ana_ac_pol_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_BUM_SLB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_BUM_SLB), ///< ram_uncorrected:ana_ac_pol_bum_slb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_CTRL_CONTEXT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_CTRL_CONTEXT), ///< ram_uncorrected:ana_ac_pol_ctrl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_CTRL_POL_PORT_CTRL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_CTRL_POL_PORT_CTRL), ///< ram_uncorrected:ana_ac_pol_ctrl_pol_port_ctrl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_PORT_POL_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_PORT_POL_CFG), ///< ram_uncorrected:ana_ac_pol_port_pol_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_PORT_POL_LB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_PORT_POL_LB), ///< ram_uncorrected:ana_ac_pol_port_pol_lb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_INH_TOKENS = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_INH_TOKENS), ///< ram_uncorrected:ana_ac_pol_sdlb_inh_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LB_CLOSED = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LB_CLOSED), ///< ram_uncorrected:ana_ac_pol_sdlb_lb_closed for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LB_TOKENS = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LB_TOKENS), ///< ram_uncorrected:ana_ac_pol_sdlb_lb_tokens for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LBSET_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_POL_SDLB_LBSET_TBL), ///< ram_uncorrected:ana_ac_pol_sdlb_lbset_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ACL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ACL), ///< ram_uncorrected:ana_ac_stat_acl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_BDLB = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_BDLB), ///< ram_uncorrected:ana_ac_stat_bdlb for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_BUM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_BUM), ///< ram_uncorrected:ana_ac_stat_bum for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ERLEG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ERLEG), ///< ram_uncorrected:ana_ac_stat_erleg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_IRLEG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_IRLEG), ///< ram_uncorrected:ana_ac_stat_irleg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ISDX = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_ISDX), ///< ram_uncorrected:ana_ac_stat_isdx for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_PORT_CR_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_PORT_CR_CFG), ///< ram_uncorrected:ana_ac_stat_port_cr_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_PORT_IR_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_PORT_IR_CFG), ///< ram_uncorrected:ana_ac_stat_port_ir_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_QUEUE = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STAT_QUEUE), ///< ram_uncorrected:ana_ac_stat_queue for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STREAM_GATES = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_STREAM_GATES), ///< ram_uncorrected:ana_ac_stream_gates for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_TSN_SF_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_TSN_SF_CFG), ///< ram_uncorrected:ana_ac_tsn_sf_cfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_TSN_SF_STA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_ANA_AC_TSN_SF_STA), ///< ram_uncorrected:ana_ac_tsn_sf_sta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CELL_INFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CELL_INFO), ///< ram_uncorrected:eacl_cell_info for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CNT_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CNT_TBL), ///< ram_uncorrected:eacl_cnt_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CONTEXT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_CONTEXT), ///< ram_uncorrected:eacl_context for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_DEF_AR_X = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_DEF_AR_X), ///< ram_uncorrected:eacl_def_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_DEF_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_DEF_CNTR), ///< ram_uncorrected:eacl_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_ECC_PAR_RAM), ///< ram_uncorrected:eacl_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CCFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CCFG), ///< ram_uncorrected:eacl_frer_ccfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CCNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CCNT), ///< ram_uncorrected:eacl_frer_ccnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CSTA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_CSTA), ///< ram_uncorrected:eacl_frer_csta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MAP = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MAP), ///< ram_uncorrected:eacl_frer_map for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MCFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MCFG), ///< ram_uncorrected:eacl_frer_mcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MCNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MCNT), ///< ram_uncorrected:eacl_frer_mcnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MSTA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_FRER_MSTA), ///< ram_uncorrected:eacl_frer_msta for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_IF_MAP = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_IF_MAP), ///< ram_uncorrected:eacl_if_map for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_KEY_SEL_PROF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_KEY_SEL_PROF), ///< ram_uncorrected:eacl_key_sel_prof for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_SL_0_AR_X = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_SL_0_AR_X), ///< ram_uncorrected:eacl_sl_0_ar_X for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_SL_0_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_SL_0_CNTR), ///< ram_uncorrected:eacl_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_STAT_EACL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_EACL_STAT_EACL), ///< ram_uncorrected:eacl_stat_eacl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_ENCAP = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_ENCAP), ///< ram_uncorrected:rew_encap for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_ISDX_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_ISDX_TBL), ///< ram_uncorrected:rew_isdx_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAC_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAC_TBL), ///< ram_uncorrected:rew_mac_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAP_RES_A = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAP_RES_A), ///< ram_uncorrected:rew_map_res_a for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAP_RES_B = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MAP_RES_B), ///< ram_uncorrected:rew_map_res_b for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MIP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_MIP_TBL), ///< ram_uncorrected:rew_mip_tbl for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_PDU_MOD_CONT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_PDU_MOD_CONT), ///< ram_uncorrected:rew_oam_pdu_mod_cont for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_VOE_PORT_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_VOE_PORT_LM_CNT), ///< ram_uncorrected:rew_oam_voe_port_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_VOE_SRV_LM_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_OAM_VOE_SRV_LM_CNT), ///< ram_uncorrected:rew_oam_voe_srv_lm_cnt for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_PORTCFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_PORTCFG), ///< ram_uncorrected:rew_portcfg for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_PTP_SEQ = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_PTP_SEQ), ///< ram_uncorrected:rew_ptp_seq for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_DEF_AR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_DEF_AR), ///< ram_uncorrected:rew_vcap_es0_def_ar for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_DEF_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_DEF_CNTR), ///< ram_uncorrected:rew_vcap_es0_def_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_ECC_PAR_RAM), ///< ram_uncorrected:rew_vcap_es0_ecc_par_ram for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_SL_0_AR_0 = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_SL_0_AR_0), ///< ram_uncorrected:rew_vcap_es0_sl_0_ar_0 for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_SL_0_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VCAP_ES0_SL_0_CNTR), ///< ram_uncorrected:rew_vcap_es0_sl_0_cntr for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VMID = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANA_AC_EACL_REW_WRAP, ENET_ANA_AC_EACL_REW_WRAP_RAM_UNCORRECTED_REW_VMID), ///< ram_uncorrected:rew_vmid for instance ana_ac_eacl_rew_wrap of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_ACL_VOP_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_ACL_VOP_DELAY), ///< ram_corrected:ana_acl_acl_vop_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CL_ACL_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CL_ACL_DELAY), ///< ram_corrected:ana_acl_cl_acl_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CNT_A = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CNT_A), ///< ram_corrected:ana_acl_cnt_a for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CNT_B = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_CNT_B), ///< ram_corrected:ana_acl_cnt_b for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_VOP_AC_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_VOP_AC_DELAY), ///< ram_corrected:ana_acl_vop_ac_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_VOP_PDU_MOD_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_ACL_VOP_PDU_MOD_DELAY), ///< ram_corrected:ana_acl_vop_pdu_mod_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_ARM_PTR_REMAP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_ARM_PTR_REMAP_TBL), ///< ram_corrected:ana_cl_arm_ptr_remap_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_ARP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_ARP_TBL), ///< ram_corrected:ana_cl_arp_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_CHECKSUM_CONTEXT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_CHECKSUM_CONTEXT), ///< ram_corrected:ana_cl_checksum_context for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_CSC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_CSC), ///< ram_corrected:ana_cl_csc for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_IPT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_IPT), ///< ram_corrected:ana_cl_ipt for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_L2CP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_L2CP_TBL), ///< ram_corrected:ana_cl_l2cp_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_L3MC_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_L3MC_TBL), ///< ram_corrected:ana_cl_l3mc_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MAP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MAP_TBL), ///< ram_corrected:ana_cl_map_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MIP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MIP_TBL), ///< ram_corrected:ana_cl_mip_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MSTP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_MSTP_TBL), ///< ram_corrected:ana_cl_mstp_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_PORT_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_PORT_CFG), ///< ram_corrected:ana_cl_port_cfg for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VLAN_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VLAN_TBL), ///< ram_corrected:ana_cl_vlan_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VMID = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VMID), ///< ram_corrected:ana_cl_vmid for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VMID_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_CL_VMID_TBL), ///< ram_corrected:ana_cl_vmid_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_AGE = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_AGE), ///< ram_corrected:ana_l2_logic_age for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_ISDX = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_ISDX), ///< ram_corrected:ana_l2_logic_isdx for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_ISDX_LIMIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_ISDX_LIMIT), ///< ram_corrected:ana_l2_logic_isdx_limit for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_LRN_LIMIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_LRN_LIMIT), ///< ram_corrected:ana_l2_logic_lrn_limit for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_MAC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_MAC), ///< ram_corrected:ana_l2_logic_mac for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_PMAC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_PMAC), ///< ram_corrected:ana_l2_logic_pmac for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_PORT_LIMIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LOGIC_PORT_LIMIT), ///< ram_corrected:ana_l2_logic_port_limit for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LRN_IGR_LRN = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_ANA_L2_LRN_IGR_LRN), ///< ram_corrected:ana_l2_lrn_igr_lrn for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_ANA_COSID_MAP_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_ANA_COSID_MAP_CONF), ///< ram_corrected:oam_mep_ana_cosid_map_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_CCM_LM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_CCM_LM), ///< ram_corrected:oam_mep_ccm_lm for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_PORT_COSID_MAP_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_PORT_COSID_MAP_CONF), ///< ram_corrected:oam_mep_port_cosid_map_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_REW_COSID_MAP_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_REW_COSID_MAP_CONF), ///< ram_corrected:oam_mep_rew_cosid_map_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_SAM_COSID_SEQ_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_SAM_COSID_SEQ_CNT), ///< ram_corrected:oam_mep_sam_cosid_seq_cnt for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONF), ///< ram_corrected:oam_mep_voe_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONTEXT_ANA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONTEXT_ANA), ///< ram_corrected:oam_mep_voe_context_ana for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONTEXT_REW = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CONTEXT_REW), ///< ram_corrected:oam_mep_voe_context_rew for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CRC_ERR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_CRC_ERR), ///< ram_corrected:oam_mep_voe_crc_err for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_STAT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_OAM_MEP_VOE_STAT), ///< ram_corrected:oam_mep_voe_stat for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_ECC_PAR_RAM), ///< ram_corrected:vcap_ip6pfx_ecc_par_ram for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_SL_0_AR_X = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_SL_0_AR_X), ///< ram_corrected:vcap_ip6pfx_sl_0_ar_x for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_SL_0_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_CORRECTED_VCAP_IP6PFX_SL_0_CNTR), ///< ram_corrected:vcap_ip6pfx_sl_0_cntr for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_ACL_VOP_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_ACL_VOP_DELAY), ///< ram_uncorrected:ana_acl_acl_vop_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CL_ACL_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CL_ACL_DELAY), ///< ram_uncorrected:ana_acl_cl_acl_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CNT_A = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CNT_A), ///< ram_uncorrected:ana_acl_cnt_a for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CNT_B = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_CNT_B), ///< ram_uncorrected:ana_acl_cnt_b for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_VOP_AC_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_VOP_AC_DELAY), ///< ram_uncorrected:ana_acl_vop_ac_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_VOP_PDU_MOD_DELAY = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_ACL_VOP_PDU_MOD_DELAY), ///< ram_uncorrected:ana_acl_vop_pdu_mod_delay for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_ARM_PTR_REMAP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_ARM_PTR_REMAP_TBL), ///< ram_uncorrected:ana_cl_arm_ptr_remap_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_ARP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_ARP_TBL), ///< ram_uncorrected:ana_cl_arp_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_CHECKSUM_CONTEXT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_CHECKSUM_CONTEXT), ///< ram_uncorrected:ana_cl_checksum_context for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_CSC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_CSC), ///< ram_uncorrected:ana_cl_csc for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_IPT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_IPT), ///< ram_uncorrected:ana_cl_ipt for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_L2CP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_L2CP_TBL), ///< ram_uncorrected:ana_cl_l2cp_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_L3MC_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_L3MC_TBL), ///< ram_uncorrected:ana_cl_l3mc_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MAP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MAP_TBL), ///< ram_uncorrected:ana_cl_map_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MIP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MIP_TBL), ///< ram_uncorrected:ana_cl_mip_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MSTP_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_MSTP_TBL), ///< ram_uncorrected:ana_cl_mstp_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_PORT_CFG = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_PORT_CFG), ///< ram_uncorrected:ana_cl_port_cfg for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VLAN_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VLAN_TBL), ///< ram_uncorrected:ana_cl_vlan_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VMID = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VMID), ///< ram_uncorrected:ana_cl_vmid for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VMID_TBL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_CL_VMID_TBL), ///< ram_uncorrected:ana_cl_vmid_tbl for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_AGE = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_AGE), ///< ram_uncorrected:ana_l2_logic_age for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_ISDX = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_ISDX), ///< ram_uncorrected:ana_l2_logic_isdx for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_ISDX_LIMIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_ISDX_LIMIT), ///< ram_uncorrected:ana_l2_logic_isdx_limit for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_LRN_LIMIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_LRN_LIMIT), ///< ram_uncorrected:ana_l2_logic_lrn_limit for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_MAC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_MAC), ///< ram_uncorrected:ana_l2_logic_mac for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_PMAC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_PMAC), ///< ram_uncorrected:ana_l2_logic_pmac for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_PORT_LIMIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LOGIC_PORT_LIMIT), ///< ram_uncorrected:ana_l2_logic_port_limit for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LRN_IGR_LRN = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_ANA_L2_LRN_IGR_LRN), ///< ram_uncorrected:ana_l2_lrn_igr_lrn for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_ANA_COSID_MAP_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_ANA_COSID_MAP_CONF), ///< ram_uncorrected:oam_mep_ana_cosid_map_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_CCM_LM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_CCM_LM), ///< ram_uncorrected:oam_mep_ccm_lm for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_PORT_COSID_MAP_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_PORT_COSID_MAP_CONF), ///< ram_uncorrected:oam_mep_port_cosid_map_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_REW_COSID_MAP_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_REW_COSID_MAP_CONF), ///< ram_uncorrected:oam_mep_rew_cosid_map_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_SAM_COSID_SEQ_CNT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_SAM_COSID_SEQ_CNT), ///< ram_uncorrected:oam_mep_sam_cosid_seq_cnt for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONF = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONF), ///< ram_uncorrected:oam_mep_voe_conf for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONTEXT_ANA = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONTEXT_ANA), ///< ram_uncorrected:oam_mep_voe_context_ana for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONTEXT_REW = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CONTEXT_REW), ///< ram_uncorrected:oam_mep_voe_context_rew for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CRC_ERR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_CRC_ERR), ///< ram_uncorrected:oam_mep_voe_crc_err for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_STAT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_OAM_MEP_VOE_STAT), ///< ram_uncorrected:oam_mep_voe_stat for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_ECC_PAR_RAM), ///< ram_uncorrected:vcap_ip6pfx_ecc_par_ram for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_SL_0_AR_X = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_SL_0_AR_X), ///< ram_uncorrected:vcap_ip6pfx_sl_0_ar_x for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_SL_0_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ANACL32OAM, ENET_ANACL32OAM_RAM_UNCORRECTED_VCAP_IP6PFX_SL_0_CNTR), ///< ram_uncorrected:vcap_ip6pfx_sl_0_cntr for instance anacl32oam of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_CORRECTED_ASM_CSC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_CORRECTED_ASM_CSC), ///< ram_corrected:asm_csc for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_CORRECTED_ASM_LBK_CELL_FIFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_CORRECTED_ASM_LBK_CELL_FIFO), ///< ram_corrected:asm_lbk_cell_fifo for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_CORRECTED_ASM_LBK_VD2_FIFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_CORRECTED_ASM_LBK_VD2_FIFO), ///< ram_corrected:asm_lbk_vd2_fifo for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_CORRECTED_ASM_PFC_PRIOFC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_CORRECTED_ASM_PFC_PRIOFC), ///< ram_corrected:asm_pfc_priofc for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_CORRECTED_ASM_TAXIX_SF_BANKY_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_CORRECTED_ASM_TAXIX_SF_BANKY_SBIT), ///< ram_corrected:asm_taxiX_sf_bankY_sbit for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_UNCORRECTED_ASM_CSC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_UNCORRECTED_ASM_CSC), ///< ram_uncorrected:asm_csc for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_UNCORRECTED_ASM_LBK_CELL_FIFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_UNCORRECTED_ASM_LBK_CELL_FIFO), ///< ram_uncorrected:asm_lbk_cell_fifo for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_UNCORRECTED_ASM_LBK_VD2_FIFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_UNCORRECTED_ASM_LBK_VD2_FIFO), ///< ram_uncorrected:asm_lbk_vd2_fifo for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_UNCORRECTED_ASM_PFC_PRIOFC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_UNCORRECTED_ASM_PFC_PRIOFC), ///< ram_uncorrected:asm_pfc_priofc for instance asm of structure from ENET
    RAS_ERR_ID_ENET_ASM_RAM_UNCORRECTED_ASM_TAXIX_SF_BANKY_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_ASM, ENET_ASM_RAM_UNCORRECTED_ASM_TAXIX_SF_BANKY_MBIT), ///< ram_uncorrected:asm_taxiX_sf_bankY_mbit for instance asm of structure from ENET
    RAS_ERR_ID_ENET_DSM_RAM_CORRECTED_DSM_TAXIX_CBUF_RAMY_Z_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_DSM, ENET_DSM_RAM_CORRECTED_DSM_TAXIX_CBUF_RAMY_Z_SBIT), ///< ram_corrected:dsm_taxiX_cbuf_ramY_Z_sbit for instance dsm of structure from ENET
    RAS_ERR_ID_ENET_DSM_RAM_UNCORRECTED_DSM_TAXIX_CBUF_RAMY_Z_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_DSM, ENET_DSM_RAM_UNCORRECTED_DSM_TAXIX_CBUF_RAMY_Z_MBIT), ///< ram_uncorrected:dsm_taxiX_cbuf_ramY_Z_mbit for instance dsm of structure from ENET
    RAS_ERR_ID_ENET_EACL_MISC_ERROR_INVLD_SOF_PTR_DISCARD = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_EACL, ENET_EACL_MISC_ERROR_INVLD_SOF_PTR_DISCARD), ///< misc_error:invld_sof_ptr_discard for instance eacl of structure from ENET
    RAS_ERR_ID_ENET_MISC_RAM_CORRECTED_DEVCPU_PTP_TS_FIFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_MISC, ENET_MISC_RAM_CORRECTED_DEVCPU_PTP_TS_FIFO), ///< ram_corrected:devcpu_ptp_ts_fifo for instance misc of structure from ENET
    RAS_ERR_ID_ENET_MISC_RAM_UNCORRECTED_DEVCPU_PTP_TS_FIFO = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_MISC, ENET_MISC_RAM_UNCORRECTED_DEVCPU_PTP_TS_FIFO), ///< ram_uncorrected:devcpu_ptp_ts_fifo for instance misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RDAT_RET_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RDAT_RET_MM2S_SBIT), ///< ram_corrected:pierX_dma_rdat_ret_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RSTS_PRE_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RSTS_PRE_MM2S_SBIT), ///< ram_corrected:pierX_dma_rsts_pre_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RSTS_S2MM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_RSTS_S2MM_SBIT), ///< ram_corrected:pierX_dma_rsts_s2mm_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WCMD_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WCMD_MM2S_SBIT), ///< ram_corrected:pierX_dma_wcmd_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WCMD_S2MM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WCMD_S2MM_SBIT), ///< ram_corrected:pierX_dma_wcmd_s2mm_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WSTS_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WSTS_MM2S_SBIT), ///< ram_corrected:pierX_dma_wsts_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WSTS_S2MM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMA_WSTS_S2MM_SBIT), ///< ram_corrected:pierX_dma_wsts_s2mm_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_DW_CTL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_DW_CTL_SBIT), ///< ram_corrected:pierX_dmac_dw_ctl_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_DW_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_DW_FIFO_SBIT), ///< ram_corrected:pierX_dmac_dw_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RCMD_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RCMD_FIFO_SBIT), ///< ram_corrected:pierX_dmac_rcmd_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RCPL_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RCPL_FIFO_SBIT), ///< ram_corrected:pierX_dmac_rcpl_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RDAT_CTL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RDAT_CTL_SBIT), ///< ram_corrected:pierX_dmac_rdat_ctl_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RDAT_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RDAT_FIFO_SBIT), ///< ram_corrected:pierX_dmac_rdat_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RSTS_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_RSTS_FIFO_SBIT), ///< ram_corrected:pierX_dmac_rsts_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WCMD_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WCMD_FIFO_SBIT), ///< ram_corrected:pierX_dmac_wcmd_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WCPL_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WCPL_FIFO_SBIT), ///< ram_corrected:pierX_dmac_wcpl_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WDAT_CTL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WDAT_CTL_SBIT), ///< ram_corrected:pierX_dmac_wdat_ctl_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WDAT_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WDAT_FIFO_SBIT), ///< ram_corrected:pierX_dmac_wdat_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WSTS_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_DMAC_WSTS_FIFO_SBIT), ///< ram_corrected:pierX_dmac_wsts_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_DMTA_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_DMTA_SBIT), ///< ram_corrected:pierX_mem_isdx_dmta_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_DMTB_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_DMTB_SBIT), ///< ram_corrected:pierX_mem_isdx_dmtb_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_SATA_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_SATA_SBIT), ///< ram_corrected:pierX_mem_isdx_sata_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_SATB_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_ISDX_SATB_SBIT), ///< ram_corrected:pierX_mem_isdx_satb_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_STX_INS_LUTA_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_STX_INS_LUTA_SBIT), ///< ram_corrected:pierX_mem_stx_ins_luta_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_STX_INS_LUTB_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_MEM_STX_INS_LUTB_SBIT), ///< ram_corrected:pierX_mem_stx_ins_lutb_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_AXI_ERR_PMON_X_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_AXI_ERR_PMON_X_SBIT), ///< ram_corrected:pierX_pe_axi_err_pmon_x_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_DATA_PMON_X_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_DATA_PMON_X_SBIT), ///< ram_corrected:pierX_pe_data_pmon_x_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_DESC_DCFC_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PE_DESC_DCFC_SBIT), ///< ram_corrected:pierX_pe_desc_dcfc_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PI_DESC_DCFC_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PI_DESC_DCFC_SBIT), ///< ram_corrected:pierX_pi_desc_dcfc_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PI_DESC_DROP_X_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PI_DESC_DROP_X_SBIT), ///< ram_corrected:pierX_pi_desc_drop_x_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PIE_DMA_RDFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PIE_DMA_RDFIFO_SBIT), ///< ram_corrected:pierX_pie_dma_rdfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PIE_DMA_TDFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_PIE_DMA_TDFIFO_SBIT), ///< ram_corrected:pierX_pie_dma_tdfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_0_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_0_SBIT), ///< ram_corrected:pierX_spare_0_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_1_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_1_SBIT), ///< ram_corrected:pierX_spare_1_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_2_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SPARE_2_SBIT), ///< ram_corrected:pierX_spare_2_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SRX_CFC_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SRX_CFC_FIFO_SBIT), ///< ram_corrected:pierX_srx_cfc_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SRX_DFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_SRX_DFIFO_SBIT), ///< ram_corrected:pierX_srx_dfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_CFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_CFIFO_SBIT), ///< ram_corrected:pierX_stx_cfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_CHK_SM_DFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_CHK_SM_DFIFO_SBIT), ///< ram_corrected:pierX_stx_chk_sm_dfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_DFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_DFIFO_SBIT), ///< ram_corrected:pierX_stx_dfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_PMON_PIE_X_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_PMON_PIE_X_SBIT), ///< ram_corrected:pierX_stx_pmon_pie_x_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_PMON_ROC_X_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_PIERX_STX_PMON_ROC_X_SBIT), ///< ram_corrected:pierX_stx_pmon_roc_x_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_CQ_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_CQ_SBIT), ///< ram_corrected:rdmaX_cmd_cq_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_MR_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_MR_SBIT), ///< ram_corrected:rdmaX_cmd_mr_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_RX_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_RX_SBIT), ///< ram_corrected:rdmaX_cmd_rx_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_TX_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CMD_TX_SBIT), ///< ram_corrected:rdmaX_cmd_tx_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_DMA_C2H_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_DMA_C2H_PLD_SBIT), ///< ram_corrected:rdmaX_cq_dma_c2h_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_REQ_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_REQ_PLD_SBIT), ///< ram_corrected:rdmaX_cq_req_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_CQ_SBIT), ///< ram_corrected:rdmaX_cq_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_MM2S_DFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_MM2S_DFIFO_SBIT), ///< ram_corrected:rdmaX_dma_mm2s_dfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RDAT_RET_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RDAT_RET_MM2S_SBIT), ///< ram_corrected:rdmaX_dma_rdat_ret_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RSTS_PRE_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RSTS_PRE_MM2S_SBIT), ///< ram_corrected:rdmaX_dma_rsts_pre_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RSTS_S2MM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_RSTS_S2MM_SBIT), ///< ram_corrected:rdmaX_dma_rsts_s2mm_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_S2MM_DFIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_S2MM_DFIFO_SBIT), ///< ram_corrected:rdmaX_dma_s2mm_dfifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WCMD_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WCMD_MM2S_SBIT), ///< ram_corrected:rdmaX_dma_wcmd_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WCMD_S2MM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WCMD_S2MM_SBIT), ///< ram_corrected:rdmaX_dma_wcmd_s2mm_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WSTS_MM2S_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WSTS_MM2S_SBIT), ///< ram_corrected:rdmaX_dma_wsts_mm2s_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WSTS_S2MM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMA_WSTS_S2MM_SBIT), ///< ram_corrected:rdmaX_dma_wsts_s2mm_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_DW_CTL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_DW_CTL_SBIT), ///< ram_corrected:rdmaX_dmac_dw_ctl_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_DW_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_DW_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_dw_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RCMD_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RCMD_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_rcmd_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RCPL_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RCPL_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_rcpl_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RDAT_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RDAT_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_rdat_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RSTS_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_RSTS_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_rsts_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WCMD_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WCMD_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_wcmd_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WCPL_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WCPL_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_wcpl_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WDAT_CTL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WDAT_CTL_SBIT), ///< ram_corrected:rdmaX_dmac_wdat_ctl_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WDAT_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WDAT_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_wdat_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WSTS_FIFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DMAC_WSTS_FIFO_SBIT), ///< ram_corrected:rdmaX_dmac_wsts_fifo_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DROP_PKT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_DROP_PKT_SBIT), ///< ram_corrected:rdmaX_drop_pkt_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_HDR_RX_REQ_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_HDR_RX_REQ_PLD_SBIT), ///< ram_corrected:rdmaX_hdr_rx_req_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_MM2S_INT_DATA_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_MM2S_INT_DATA_SBIT), ///< ram_corrected:rdmaX_mm2s_int_data_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_MR_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_MR_LUT_SBIT), ///< ram_corrected:rdmaX_mr_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX2TX_INFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX2TX_INFO_SBIT), ///< ram_corrected:rdmaX_rx2tx_info_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_DBG_MON_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_DBG_MON_LUT_SBIT), ///< ram_corrected:rdmaX_rx_dbg_mon_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_MCAST_GROUPS_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_MCAST_GROUPS_SBIT), ///< ram_corrected:rdmaX_rx_mcast_groups_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_MULTICAST_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_MULTICAST_PLD_SBIT), ///< ram_corrected:rdmaX_rx_multicast_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_QP1_VIRT_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_QP1_VIRT_LUT_SBIT), ///< ram_corrected:rdmaX_rx_qp1_virt_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_QP_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_QP_LUT_SBIT), ///< ram_corrected:rdmaX_rx_qp_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_REQ_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_REQ_PLD_SBIT), ///< ram_corrected:rdmaX_rx_req_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQ_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQ_LUT_SBIT), ///< ram_corrected:rdmaX_rx_rq_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQ_WR_MOV_CMD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQ_WR_MOV_CMD_SBIT), ///< ram_corrected:rdmaX_rx_rq_wr_mov_cmd_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQE_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RQE_SBIT), ///< ram_corrected:rdmaX_rx_rqe_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RR_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RR_LUT_SBIT), ///< ram_corrected:rdmaX_rx_rr_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RSP_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_RSP_PLD_SBIT), ///< ram_corrected:rdmaX_rx_rsp_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_TX_RSP_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_RX_TX_RSP_SBIT), ///< ram_corrected:rdmaX_rx_tx_rsp_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_S2MM_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_S2MM_PLD_SBIT), ///< ram_corrected:rdmaX_s2mm_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_0_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_0_SBIT), ///< ram_corrected:rdmaX_spare_0_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_1_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_1_SBIT), ///< ram_corrected:rdmaX_spare_1_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_2_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_SPARE_2_SBIT), ///< ram_corrected:rdmaX_spare_2_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_CNP_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_CNP_SBIT), ///< ram_corrected:rdmaX_tm_cnp_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_RETRY_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_RETRY_SBIT), ///< ram_corrected:rdmaX_tm_retry_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_RNR_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TM_RNR_SBIT), ///< ram_corrected:rdmaX_tm_rnr_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX2RX_INFO_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX2RX_INFO_SBIT), ///< ram_corrected:rdmaX_tx2rx_info_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_DBG_MON_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_DBG_MON_LUT_SBIT), ///< ram_corrected:rdmaX_tx_dbg_mon_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_MR_DESCR_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_MR_DESCR_SBIT), ///< ram_corrected:rdmaX_tx_mr_descr_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_PLD_INL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_PLD_INL_SBIT), ///< ram_corrected:rdmaX_tx_pld_inl_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_PLD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_PLD_SBIT), ///< ram_corrected:rdmaX_tx_pld_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_CMP_PRF_CMD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_CMP_PRF_CMD_SBIT), ///< ram_corrected:rdmaX_tx_sq_cmp_prf_cmd_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_CMP_PRF_RSP_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_CMP_PRF_RSP_SBIT), ///< ram_corrected:rdmaX_tx_sq_cmp_prf_rsp_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_WR_MOV_CMD_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQ_WR_MOV_CMD_SBIT), ///< ram_corrected:rdmaX_tx_sq_wr_mov_cmd_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQE_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_SQE_SBIT), ///< ram_corrected:rdmaX_tx_sqe_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_QP_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_QP_LUT_SBIT), ///< ram_corrected:rdmaX_tx_tx_qp_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_REQ_CTX_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_REQ_CTX_SBIT), ///< ram_corrected:rdmaX_tx_tx_req_ctx_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_RR_LUT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_TX_RR_LUT_SBIT), ///< ram_corrected:rdmaX_tx_tx_rr_lut_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_UC_UD_CMP_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_CORRECTED_RDMAX_TX_UC_UD_CMP_SBIT), ///< ram_corrected:rdmaX_tx_uc_ud_cmp_sbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RDAT_RET_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RDAT_RET_MM2S_MBIT), ///< ram_uncorrected:pierX_dma_rdat_ret_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RSTS_PRE_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RSTS_PRE_MM2S_MBIT), ///< ram_uncorrected:pierX_dma_rsts_pre_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RSTS_S2MM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_RSTS_S2MM_MBIT), ///< ram_uncorrected:pierX_dma_rsts_s2mm_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WCMD_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WCMD_MM2S_MBIT), ///< ram_uncorrected:pierX_dma_wcmd_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WCMD_S2MM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WCMD_S2MM_MBIT), ///< ram_uncorrected:pierX_dma_wcmd_s2mm_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WSTS_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WSTS_MM2S_MBIT), ///< ram_uncorrected:pierX_dma_wsts_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WSTS_S2MM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMA_WSTS_S2MM_MBIT), ///< ram_uncorrected:pierX_dma_wsts_s2mm_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_DW_CTL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_DW_CTL_MBIT), ///< ram_uncorrected:pierX_dmac_dw_ctl_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_DW_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_DW_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_dw_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RCMD_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RCMD_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_rcmd_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RCPL_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RCPL_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_rcpl_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RDAT_CTL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RDAT_CTL_MBIT), ///< ram_uncorrected:pierX_dmac_rdat_ctl_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RDAT_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RDAT_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_rdat_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RSTS_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_RSTS_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_rsts_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WCMD_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WCMD_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_wcmd_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WCPL_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WCPL_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_wcpl_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WDAT_CTL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WDAT_CTL_MBIT), ///< ram_uncorrected:pierX_dmac_wdat_ctl_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WDAT_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WDAT_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_wdat_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WSTS_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_DMAC_WSTS_FIFO_MBIT), ///< ram_uncorrected:pierX_dmac_wsts_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_DMTA_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_DMTA_MBIT), ///< ram_uncorrected:pierX_mem_isdx_dmta_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_DMTB_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_DMTB_MBIT), ///< ram_uncorrected:pierX_mem_isdx_dmtb_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_SATA_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_SATA_MBIT), ///< ram_uncorrected:pierX_mem_isdx_sata_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_SATB_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_ISDX_SATB_MBIT), ///< ram_uncorrected:pierX_mem_isdx_satb_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_STX_INS_LUTA_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_STX_INS_LUTA_MBIT), ///< ram_uncorrected:pierX_mem_stx_ins_luta_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_STX_INS_LUTB_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_MEM_STX_INS_LUTB_MBIT), ///< ram_uncorrected:pierX_mem_stx_ins_lutb_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_AXI_ERR_PMON_X_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_AXI_ERR_PMON_X_MBIT), ///< ram_uncorrected:pierX_pe_axi_err_pmon_x_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_DATA_PMON_X_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_DATA_PMON_X_MBIT), ///< ram_uncorrected:pierX_pe_data_pmon_x_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_DESC_DCFC_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PE_DESC_DCFC_MBIT), ///< ram_uncorrected:pierX_pe_desc_dcfc_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PI_DESC_DCFC_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PI_DESC_DCFC_MBIT), ///< ram_uncorrected:pierX_pi_desc_dcfc_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PI_DESC_DROP_X_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PI_DESC_DROP_X_MBIT), ///< ram_uncorrected:pierX_pi_desc_drop_x_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PIE_DMA_RDFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PIE_DMA_RDFIFO_MBIT), ///< ram_uncorrected:pierX_pie_dma_rdfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PIE_DMA_TDFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_PIE_DMA_TDFIFO_MBIT), ///< ram_uncorrected:pierX_pie_dma_tdfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_0_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_0_MBIT), ///< ram_uncorrected:pierX_spare_0_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_1_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_1_MBIT), ///< ram_uncorrected:pierX_spare_1_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_2_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SPARE_2_MBIT), ///< ram_uncorrected:pierX_spare_2_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SRX_CFC_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SRX_CFC_FIFO_MBIT), ///< ram_uncorrected:pierX_srx_cfc_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SRX_DFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_SRX_DFIFO_MBIT), ///< ram_uncorrected:pierX_srx_dfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_CFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_CFIFO_MBIT), ///< ram_uncorrected:pierX_stx_cfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_CHK_SM_DFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_CHK_SM_DFIFO_MBIT), ///< ram_uncorrected:pierX_stx_chk_sm_dfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_DFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_DFIFO_MBIT), ///< ram_uncorrected:pierX_stx_dfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_PMON_PIE_X_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_PMON_PIE_X_MBIT), ///< ram_uncorrected:pierX_stx_pmon_pie_x_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_PMON_ROC_X_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_PIERX_STX_PMON_ROC_X_MBIT), ///< ram_uncorrected:pierX_stx_pmon_roc_x_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_CQ_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_CQ_MBIT), ///< ram_uncorrected:rdmaX_cmd_cq_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_MR_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_MR_MBIT), ///< ram_uncorrected:rdmaX_cmd_mr_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_RX_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_RX_MBIT), ///< ram_uncorrected:rdmaX_cmd_rx_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_TX_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CMD_TX_MBIT), ///< ram_uncorrected:rdmaX_cmd_tx_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_DMA_C2H_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_DMA_C2H_PLD_MBIT), ///< ram_uncorrected:rdmaX_cq_dma_c2h_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_MBIT), ///< ram_uncorrected:rdmaX_cq_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_REQ_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_CQ_REQ_PLD_MBIT), ///< ram_uncorrected:rdmaX_cq_req_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_MM2S_DFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_MM2S_DFIFO_MBIT), ///< ram_uncorrected:rdmaX_dma_mm2s_dfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RDAT_RET_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RDAT_RET_MM2S_MBIT), ///< ram_uncorrected:rdmaX_dma_rdat_ret_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RSTS_PRE_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RSTS_PRE_MM2S_MBIT), ///< ram_uncorrected:rdmaX_dma_rsts_pre_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RSTS_S2MM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_RSTS_S2MM_MBIT), ///< ram_uncorrected:rdmaX_dma_rsts_s2mm_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_S2MM_DFIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_S2MM_DFIFO_MBIT), ///< ram_uncorrected:rdmaX_dma_s2mm_dfifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WCMD_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WCMD_MM2S_MBIT), ///< ram_uncorrected:rdmaX_dma_wcmd_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WCMD_S2MM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WCMD_S2MM_MBIT), ///< ram_uncorrected:rdmaX_dma_wcmd_s2mm_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WSTS_MM2S_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WSTS_MM2S_MBIT), ///< ram_uncorrected:rdmaX_dma_wsts_mm2s_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WSTS_S2MM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMA_WSTS_S2MM_MBIT), ///< ram_uncorrected:rdmaX_dma_wsts_s2mm_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_DW_CTL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_DW_CTL_MBIT), ///< ram_uncorrected:rdmaX_dmac_dw_ctl_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_DW_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_DW_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_dw_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RCMD_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RCMD_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_rcmd_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RCPL_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RCPL_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_rcpl_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RDAT_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RDAT_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_rdat_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RSTS_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_RSTS_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_rsts_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WCMD_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WCMD_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_wcmd_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WCPL_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WCPL_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_wcpl_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WDAT_CTL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WDAT_CTL_MBIT), ///< ram_uncorrected:rdmaX_dmac_wdat_ctl_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WDAT_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WDAT_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_wdat_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WSTS_FIFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DMAC_WSTS_FIFO_MBIT), ///< ram_uncorrected:rdmaX_dmac_wsts_fifo_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DROP_PKT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_DROP_PKT_MBIT), ///< ram_uncorrected:rdmaX_drop_pkt_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_HDR_RX_REQ_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_HDR_RX_REQ_PLD_MBIT), ///< ram_uncorrected:rdmaX_hdr_rx_req_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_MM2S_INT_DATA_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_MM2S_INT_DATA_MBIT), ///< ram_uncorrected:rdmaX_mm2s_int_data_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_MR_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_MR_LUT_MBIT), ///< ram_uncorrected:rdmaX_mr_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX2TX_INFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX2TX_INFO_MBIT), ///< ram_uncorrected:rdmaX_rx2tx_info_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_DBG_MON_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_DBG_MON_LUT_MBIT), ///< ram_uncorrected:rdmaX_rx_dbg_mon_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_MCAST_GROUPS_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_MCAST_GROUPS_MBIT), ///< ram_uncorrected:rdmaX_rx_mcast_groups_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_MULTICAST_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_MULTICAST_PLD_MBIT), ///< ram_uncorrected:rdmaX_rx_multicast_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_QP1_VIRT_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_QP1_VIRT_LUT_MBIT), ///< ram_uncorrected:rdmaX_rx_qp1_virt_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_QP_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_QP_LUT_MBIT), ///< ram_uncorrected:rdmaX_rx_qp_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_REQ_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_REQ_PLD_MBIT), ///< ram_uncorrected:rdmaX_rx_req_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQ_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQ_LUT_MBIT), ///< ram_uncorrected:rdmaX_rx_rq_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQ_WR_MOV_CMD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQ_WR_MOV_CMD_MBIT), ///< ram_uncorrected:rdmaX_rx_rq_wr_mov_cmd_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQE_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RQE_MBIT), ///< ram_uncorrected:rdmaX_rx_rqe_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RR_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RR_LUT_MBIT), ///< ram_uncorrected:rdmaX_rx_rr_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RSP_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_RSP_PLD_MBIT), ///< ram_uncorrected:rdmaX_rx_rsp_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_TX_RSP_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_RX_TX_RSP_MBIT), ///< ram_uncorrected:rdmaX_rx_tx_rsp_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_S2MM_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_S2MM_PLD_MBIT), ///< ram_uncorrected:rdmaX_s2mm_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_0_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_0_MBIT), ///< ram_uncorrected:rdmaX_spare_0_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_1_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_1_MBIT), ///< ram_uncorrected:rdmaX_spare_1_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_2_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_SPARE_2_MBIT), ///< ram_uncorrected:rdmaX_spare_2_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_CNP_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_CNP_MBIT), ///< ram_uncorrected:rdmaX_tm_cnp_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_RETRY_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_RETRY_MBIT), ///< ram_uncorrected:rdmaX_tm_retry_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_RNR_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TM_RNR_MBIT), ///< ram_uncorrected:rdmaX_tm_rnr_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX2RX_INFO_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX2RX_INFO_MBIT), ///< ram_uncorrected:rdmaX_tx2rx_info_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_DBG_MON_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_DBG_MON_LUT_MBIT), ///< ram_uncorrected:rdmaX_tx_dbg_mon_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_MR_DESCR_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_MR_DESCR_MBIT), ///< ram_uncorrected:rdmaX_tx_mr_descr_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_PLD_INL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_PLD_INL_MBIT), ///< ram_uncorrected:rdmaX_tx_pld_inl_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_PLD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_PLD_MBIT), ///< ram_uncorrected:rdmaX_tx_pld_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_CMP_PRF_CMD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_CMP_PRF_CMD_MBIT), ///< ram_uncorrected:rdmaX_tx_sq_cmp_prf_cmd_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_CMP_PRF_RSP_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_CMP_PRF_RSP_MBIT), ///< ram_uncorrected:rdmaX_tx_sq_cmp_prf_rsp_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_WR_MOV_CMD_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQ_WR_MOV_CMD_MBIT), ///< ram_uncorrected:rdmaX_tx_sq_wr_mov_cmd_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQE_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_SQE_MBIT), ///< ram_uncorrected:rdmaX_tx_sqe_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_QP_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_QP_LUT_MBIT), ///< ram_uncorrected:rdmaX_tx_tx_qp_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_REQ_CTX_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_REQ_CTX_MBIT), ///< ram_uncorrected:rdmaX_tx_tx_req_ctx_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_RR_LUT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_TX_RR_LUT_MBIT), ///< ram_uncorrected:rdmaX_tx_tx_rr_lut_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_UC_UD_CMP_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA, ENET_PIER_RDMA_RAM_UNCORRECTED_RDMAX_TX_UC_UD_CMP_MBIT), ///< ram_uncorrected:rdmaX_tx_uc_ud_cmp_mbit for instance pier_rdma of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_1_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_1_FATAL), ///< misc_fatal:pierX_spare_1_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_2_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_2_FATAL), ///< misc_fatal:pierX_spare_2_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_3_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_3_FATAL), ///< misc_fatal:pierX_spare_3_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_4_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_4_FATAL), ///< misc_fatal:pierX_spare_4_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_5_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_5_FATAL), ///< misc_fatal:pierX_spare_5_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_6_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_6_FATAL), ///< misc_fatal:pierX_spare_6_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_7_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SPARE_7_FATAL), ///< misc_fatal:pierX_spare_7_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SRX_ARB_LOCKUP_PIE = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SRX_ARB_LOCKUP_PIE), ///< misc_fatal:pierX_srx_arb_lockup_pie for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SRX_ARB_LOCKUP_ROC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_SRX_ARB_LOCKUP_ROC), ///< misc_fatal:pierX_srx_arb_lockup_roc for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_ARB_LOCKUP_PIE = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_ARB_LOCKUP_PIE), ///< misc_fatal:pierX_stx_arb_lockup_pie for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_ARB_LOCKUP_ROC = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_ARB_LOCKUP_ROC), ///< misc_fatal:pierX_stx_arb_lockup_roc for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_SOF_MISALIGN = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_PIERX_STX_SOF_MISALIGN), ///< misc_fatal:pierX_stx_sof_misalign for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_0_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_0_FATAL), ///< misc_fatal:rdmaX_spare_0_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_1_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_1_FATAL), ///< misc_fatal:rdmaX_spare_1_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_2_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_2_FATAL), ///< misc_fatal:rdmaX_spare_2_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_3_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_3_FATAL), ///< misc_fatal:rdmaX_spare_3_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_4_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_4_FATAL), ///< misc_fatal:rdmaX_spare_4_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_5_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_5_FATAL), ///< misc_fatal:rdmaX_spare_5_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_6_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_6_FATAL), ///< misc_fatal:rdmaX_spare_6_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_7_FATAL = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_PIER_RDMA_MISC, ENET_PIER_RDMA_MISC_MISC_FATAL_RDMAX_SPARE_7_FATAL), ///< misc_fatal:rdmaX_spare_7_fatal for instance pier_rdma_misc of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_CBC_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_CBC_SBIT), ///< ram_corrected:qsys_mqs_iqs_cbc_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_FWR_STATE_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_FWR_STATE_TBL_SBIT), ///< ram_corrected:qsys_mqs_iqs_fwr_state_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_IQC_DSCR_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_IQC_DSCR_SBIT), ///< ram_corrected:qsys_mqs_iqs_iqc_dscr_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_IQC_LNK_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_IQC_LNK_SBIT), ///< ram_corrected:qsys_mqs_iqs_iqc_lnk_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_RESALL_RESCTRL_X_RES_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_RESALL_RESCTRL_X_RES_SBIT), ///< ram_corrected:qsys_mqs_iqs_resall_resctrl_X_res_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_SOFPOOL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_IQS_SOFPOOL_SBIT), ///< ram_corrected:qsys_mqs_iqs_sofpool_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_DTI_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_DTI_TBL_SBIT), ///< ram_corrected:qsys_mqs_oqs_afi_dti_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_FRM_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_FRM_TBL_SBIT), ///< ram_corrected:qsys_mqs_oqs_afi_frm_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_PORT_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_PORT_TBL_SBIT), ///< ram_corrected:qsys_mqs_oqs_afi_port_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_TTI_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_AFI_TTI_TBL_SBIT), ///< ram_corrected:qsys_mqs_oqs_afi_tti_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_EQ_DSCR_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_EQ_DSCR_SBIT), ///< ram_corrected:qsys_mqs_oqs_eqc_eq_dscr_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_LNK_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_LNK_SBIT), ///< ram_corrected:qsys_mqs_oqs_eqc_lnk_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_QH_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_QH_SBIT), ///< ram_corrected:qsys_mqs_oqs_eqc_qh_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_QT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_EQC_QT_SBIT), ///< ram_corrected:qsys_mqs_oqs_eqc_qt_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L0_CFG_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L0_CFG_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_l0_cfg_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L1_CFG_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L1_CFG_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_l1_cfg_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L1W_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L1W_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_l1w_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L2W_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_L2W_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_l2w_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_ALLOC_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_ALLOC_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_qshp_alloc_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_CFG_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_CFG_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_qshp_cfg_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_DS_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_DS_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_qshp_ds_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_STAT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_QSHP_STAT_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_qshp_stat_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_ENTRIES_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_ENTRIES_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tas_entries_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_GATES_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_GATES_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tas_gates_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_LIST_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TAS_LIST_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tas_list_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_DS_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_DS_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tbl_X_ds_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_QS_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_QS_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tbl_X_qs_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_CFG_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_CFG_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tbl_X_se_cfg_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_DWRR_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_DWRR_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tbl_X_se_dwrr_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_STAT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_STAT_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tbl_X_se_stat_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_TAS_GATES_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_TAS_GATES_SBIT), ///< ram_corrected:qsys_mqs_oqs_hsch_tbl_X_tas_gates_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_MMGT_FRP_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_MMGT_FRP_SBIT), ///< ram_corrected:qsys_mqs_oqs_mmgt_frp_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_MMGT_PLNK_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_OQS_MMGT_PLNK_SBIT), ///< ram_corrected:qsys_mqs_oqs_mmgt_plnk_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SBIT), ///< ram_corrected:qsys_mqs_xqs_qlim_qlim_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SE_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SE_SBIT), ///< ram_corrected:qsys_mqs_xqs_qlim_qlim_se_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_USECNT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QLIM_USECNT_SBIT), ///< ram_corrected:qsys_mqs_xqs_qlim_usecnt_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_QOS_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_QOS_TBL_SBIT), ///< ram_corrected:qsys_mqs_xqs_qmap_qos_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_SE_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_SE_TBL_SBIT), ///< ram_corrected:qsys_mqs_xqs_qmap_se_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_VPORT_TBL_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_QMAP_VPORT_TBL_SBIT), ///< ram_corrected:qsys_mqs_xqs_qmap_vport_tbl_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_STAT_X_PORT_STAT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_STAT_X_PORT_STAT_SBIT), ///< ram_corrected:qsys_mqs_xqs_stat_X_port_stat_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_STAT_X_SRV_STAT_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_MQS_XQS_STAT_X_SRV_STAT_SBIT), ///< ram_corrected:qsys_mqs_xqs_stat_X_srv_stat_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_CORRECTED_QSYS_PMEM_PKTMEMX_SBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_CORRECTED_QSYS_PMEM_PKTMEMX_SBIT), ///< ram_corrected:qsys_pmem_pktmemX_sbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_CBC_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_CBC_MBIT), ///< ram_uncorrected:qsys_mqs_iqs_cbc_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_FWR_STATE_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_FWR_STATE_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_iqs_fwr_state_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_IQC_DSCR_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_IQC_DSCR_MBIT), ///< ram_uncorrected:qsys_mqs_iqs_iqc_dscr_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_IQC_LNK_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_IQC_LNK_MBIT), ///< ram_uncorrected:qsys_mqs_iqs_iqc_lnk_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_RESALL_RESCTRL_X_RES_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_RESALL_RESCTRL_X_RES_MBIT), ///< ram_uncorrected:qsys_mqs_iqs_resall_resctrl_X_res_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_SOFPOOL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_IQS_SOFPOOL_MBIT), ///< ram_uncorrected:qsys_mqs_iqs_sofpool_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_DTI_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_DTI_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_afi_dti_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_FRM_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_FRM_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_afi_frm_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_PORT_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_PORT_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_afi_port_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_TTI_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_AFI_TTI_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_afi_tti_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_EQ_DSCR_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_EQ_DSCR_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_eqc_eq_dscr_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_LNK_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_LNK_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_eqc_lnk_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_QH_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_QH_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_eqc_qh_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_QT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_EQC_QT_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_eqc_qt_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L0_CFG_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L0_CFG_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_l0_cfg_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L1_CFG_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L1_CFG_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_l1_cfg_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L1W_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L1W_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_l1w_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L2W_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_L2W_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_l2w_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_ALLOC_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_ALLOC_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_qshp_alloc_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_CFG_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_CFG_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_qshp_cfg_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_DS_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_DS_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_qshp_ds_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_STAT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_QSHP_STAT_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_qshp_stat_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_ENTRIES_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_ENTRIES_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tas_entries_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_GATES_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_GATES_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tas_gates_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_LIST_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TAS_LIST_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tas_list_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_DS_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_DS_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_ds_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_QS_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_QS_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_qs_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_CFG_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_CFG_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_se_cfg_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_DWRR_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_DWRR_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_se_dwrr_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_STAT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_SE_STAT_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_se_stat_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_TAS_GATES_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_HSCH_TBL_X_TAS_GATES_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_hsch_tbl_X_tas_gates_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_MMGT_FRP_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_MMGT_FRP_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_mmgt_frp_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_MMGT_PLNK_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_OQS_MMGT_PLNK_MBIT), ///< ram_uncorrected:qsys_mqs_oqs_mmgt_plnk_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_QLIM_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_QLIM_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_qlim_qlim_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SE_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_QLIM_SE_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_qlim_qlim_se_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_USECNT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QLIM_USECNT_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_qlim_usecnt_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_QOS_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_QOS_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_qmap_qos_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_SE_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_SE_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_qmap_se_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_VPORT_TBL_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_QMAP_VPORT_TBL_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_qmap_vport_tbl_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_STAT_X_PORT_STAT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_STAT_X_PORT_STAT_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_stat_X_port_stat_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_STAT_X_SRV_STAT_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_MQS_XQS_STAT_X_SRV_STAT_MBIT), ///< ram_uncorrected:qsys_mqs_xqs_stat_X_srv_stat_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_SQS_RAM_UNCORRECTED_QSYS_PMEM_PKTMEMX_MBIT = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_SQS, ENET_SQS_RAM_UNCORRECTED_QSYS_PMEM_PKTMEMX_MBIT), ///< ram_uncorrected:qsys_pmem_pktmemX_mbit for instance sqs of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XA_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XA_AR_Y), ///< ram_corrected:vcap_super_def_Xa_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XA_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XA_CNTR), ///< ram_corrected:vcap_super_def_Xa_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XB_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XB_AR_Y), ///< ram_corrected:vcap_super_def_Xb_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XB_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XB_CNTR), ///< ram_corrected:vcap_super_def_Xb_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XC_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XC_AR_Y), ///< ram_corrected:vcap_super_def_Xc_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XC_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_DEF_XC_CNTR), ///< ram_corrected:vcap_super_def_Xc_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_ECC_PAR_RAM), ///< ram_corrected:vcap_super_ecc_par_ram for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_SL_X_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_SL_X_AR_Y), ///< ram_corrected:vcap_super_sl_X_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_SL_X_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_CORRECTED_VCAP_SUPER_SL_X_CNTR), ///< ram_corrected:vcap_super_sl_X_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XA_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XA_AR_Y), ///< ram_uncorrected:vcap_super_def_Xa_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XA_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XA_CNTR), ///< ram_uncorrected:vcap_super_def_Xa_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XB_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XB_AR_Y), ///< ram_uncorrected:vcap_super_def_Xb_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XB_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XB_CNTR), ///< ram_uncorrected:vcap_super_def_Xb_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XC_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XC_AR_Y), ///< ram_uncorrected:vcap_super_def_Xc_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XC_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_DEF_XC_CNTR), ///< ram_uncorrected:vcap_super_def_Xc_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_ECC_PAR_RAM = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_ECC_PAR_RAM), ///< ram_uncorrected:vcap_super_ecc_par_ram for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_SL_X_AR_Y = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_SL_X_AR_Y), ///< ram_uncorrected:vcap_super_sl_X_AR_Y for instance vcap_super of structure from ENET
    RAS_ERR_ID_ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_SL_X_CNTR = RAS_ERROR_ENCODE(ENET, ENET_STRUCT_VCAP_SUPER, ENET_VCAP_SUPER_RAM_UNCORRECTED_VCAP_SUPER_SL_X_CNTR), ///< ram_uncorrected:vcap_super_sl_X_cntr for instance vcap_super of structure from ENET
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_B_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_B_PARITY), ///< bus_ecc_corrected:nand_m_cor_err_b_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_R_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_R_PARITY), ///< bus_ecc_corrected:nand_m_cor_err_r_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_RDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_M_COR_ERR_RDATA_PARITY), ///< bus_ecc_corrected:nand_m_cor_err_rdata_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AR_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AR_A_PARITY), ///< bus_ecc_corrected:nand_s_cor_err_ar_a_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AR_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AR_C_PARITY), ///< bus_ecc_corrected:nand_s_cor_err_ar_c_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AW_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AW_A_PARITY), ///< bus_ecc_corrected:nand_s_cor_err_aw_a_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AW_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_AW_C_PARITY), ///< bus_ecc_corrected:nand_s_cor_err_aw_c_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_W_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_W_PARITY), ///< bus_ecc_corrected:nand_s_cor_err_w_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_WDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_CORRECTED_NAND_S_COR_ERR_WDATA_PARITY), ///< bus_ecc_corrected:nand_s_cor_err_wdata_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_B_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_B_PARITY), ///< bus_ecc_uncorrected:nand_m_uncor_err_b_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_R_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_R_PARITY), ///< bus_ecc_uncorrected:nand_m_uncor_err_r_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_RDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_M_UNCOR_ERR_RDATA_PARITY), ///< bus_ecc_uncorrected:nand_m_uncor_err_rdata_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AR_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AR_A_PARITY), ///< bus_ecc_uncorrected:nand_s_uncor_err_ar_a_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AR_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AR_C_PARITY), ///< bus_ecc_uncorrected:nand_s_uncor_err_ar_c_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AW_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AW_A_PARITY), ///< bus_ecc_uncorrected:nand_s_uncor_err_aw_a_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AW_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_AW_C_PARITY), ///< bus_ecc_uncorrected:nand_s_uncor_err_aw_c_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_W_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_W_PARITY), ///< bus_ecc_uncorrected:nand_s_uncor_err_w_parity for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_WDATA_PARIT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_BUS_ECC_UNCORRECTED_NAND_S_UNCOR_ERR_WDATA_PARIT), ///< bus_ecc_uncorrected:nand_s_uncor_err_wdata_parit for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_CORRECTED_DESC_CTXT_MEM_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_CORRECTED_DESC_CTXT_MEM_ERR_COR), ///< ram_corrected:desc_ctxt_mem_err_cor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_CORRECTED_ECC_BUF_0_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_CORRECTED_ECC_BUF_0_ERR_COR), ///< ram_corrected:ecc_buf_0_err_cor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_CORRECTED_ECC_BUF_1_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_CORRECTED_ECC_BUF_1_ERR_COR), ///< ram_corrected:ecc_buf_1_err_cor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_CORRECTED_REMAP_BUF_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_CORRECTED_REMAP_BUF_ERR_COR), ///< ram_corrected:remap_buf_err_cor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_CORRECTED_TX_FIFO_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_CORRECTED_TX_FIFO_ERR_COR), ///< ram_corrected:tx_fifo_err_cor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_UNCORRECTED_DESC_CTXT_MEM_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_UNCORRECTED_DESC_CTXT_MEM_ERR_UNCOR), ///< ram_uncorrected:desc_ctxt_mem_err_uncor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_UNCORRECTED_ECC_BUF_0_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_UNCORRECTED_ECC_BUF_0_ERR_UNCOR), ///< ram_uncorrected:ecc_buf_0_err_uncor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_UNCORRECTED_ECC_BUF_1_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_UNCORRECTED_ECC_BUF_1_ERR_UNCOR), ///< ram_uncorrected:ecc_buf_1_err_uncor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_UNCORRECTED_REMAP_BUF_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_UNCORRECTED_REMAP_BUF_ERR_UNCOR), ///< ram_uncorrected:remap_buf_err_uncor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RAM_UNCORRECTED_TX_FIFO_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RAM_UNCORRECTED_TX_FIFO_ERR_UNCOR), ///< ram_uncorrected:tx_fifo_err_uncor for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RESPONSE_UNCORRECTED_NAND_M_SLVERR_READ_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RESPONSE_UNCORRECTED_NAND_M_SLVERR_READ_TRANS), ///< response_uncorrected:nand_m_slverr_read_trans for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_RESPONSE_UNCORRECTED_NAND_M_SLVERR_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_RESPONSE_UNCORRECTED_NAND_M_SLVERR_WRITE_TRANS), ///< response_uncorrected:nand_m_slverr_write_trans for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_TRANS_DROP_NAND_S_BRESP_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_TRANS_DROP_NAND_S_BRESP_TIMEOUT), ///< trans_drop:nand_s_bresp_timeout for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_TRANS_DROP_NAND_S_DROP_READ_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_TRANS_DROP_NAND_S_DROP_READ_TRANS), ///< trans_drop:nand_s_drop_read_trans for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_TRANS_DROP_NAND_S_DROP_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_TRANS_DROP_NAND_S_DROP_WRITE_TRANS), ///< trans_drop:nand_s_drop_write_trans for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_TRANS_DROP_NAND_S_NULL_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_TRANS_DROP_NAND_S_NULL_WRITE_TRANS), ///< trans_drop:nand_s_null_write_trans for instance nand_ctrl of structure from NVM
    RAS_ERR_ID_NVM_NAND_CTRL_TRANS_DROP_NAND_S_RDATA_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NAND_CTRL, NVM_NAND_CTRL_TRANS_DROP_NAND_S_RDATA_TIMEOUT), ///< trans_drop:nand_s_rdata_timeout for instance nand_ctrl of structure from NVM
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
    RAS_ERR_ID_NVM_NVM_EDAC_EMON_CORRECTED_SCRUB_REQ = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_NVM_EDAC, NVM_NVM_EDAC_EMON_CORRECTED_SCRUB_REQ), ///< emon_corrected:scrub_req for instance nvm_edac of structure from NVM
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
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_A_PARITY), ///< bus_ecc_corrected:cor_err_ar_a_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_C_PARITY), ///< bus_ecc_corrected:cor_err_ar_c_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_A_PARITY), ///< bus_ecc_corrected:cor_err_aw_a_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_C_PARITY), ///< bus_ecc_corrected:cor_err_aw_c_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_W_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_W_PARITY), ///< bus_ecc_corrected:cor_err_w_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_WDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_CORRECTED_COR_ERR_WDATA_PARITY), ///< bus_ecc_corrected:cor_err_wdata_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_A_PARITY), ///< bus_ecc_uncorrected:uncor_err_ar_a_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_C_PARITY), ///< bus_ecc_uncorrected:uncor_err_ar_c_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_A_PARITY), ///< bus_ecc_uncorrected:uncor_err_aw_a_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_C_PARITY), ///< bus_ecc_uncorrected:uncor_err_aw_c_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_W_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_W_PARITY), ///< bus_ecc_uncorrected:uncor_err_w_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_WDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_WDATA_PARITY), ///< bus_ecc_uncorrected:uncor_err_wdata_parity for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_TRANS_DROP_BRESP_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_TRANS_DROP_BRESP_TIMEOUT), ///< trans_drop:bresp_timeout for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_TRANS_DROP_DROP_READ_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_TRANS_DROP_DROP_READ_TRANS), ///< trans_drop:drop_read_trans for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_TRANS_DROP_DROP_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_TRANS_DROP_DROP_WRITE_TRANS), ///< trans_drop:drop_write_trans for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_TRANS_DROP_NULL_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_TRANS_DROP_NULL_WRITE_TRANS), ///< trans_drop:null_write_trans for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_PFLASH_CTRL_TRANS_DROP_RDATA_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_PFLASH_CTRL, NVM_PFLASH_CTRL_TRANS_DROP_RDATA_TIMEOUT), ///< trans_drop:rdata_timeout for instance pflash_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_A_PARITY), ///< bus_ecc_corrected:cor_err_ar_a_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AR_C_PARITY), ///< bus_ecc_corrected:cor_err_ar_c_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_A_PARITY), ///< bus_ecc_corrected:cor_err_aw_a_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_AW_C_PARITY), ///< bus_ecc_corrected:cor_err_aw_c_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_W_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_W_PARITY), ///< bus_ecc_corrected:cor_err_w_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_WDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_CORRECTED_COR_ERR_WDATA_PARITY), ///< bus_ecc_corrected:cor_err_wdata_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_A_PARITY), ///< bus_ecc_uncorrected:uncor_err_ar_a_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AR_C_PARITY), ///< bus_ecc_uncorrected:uncor_err_ar_c_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_A_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_A_PARITY), ///< bus_ecc_uncorrected:uncor_err_aw_a_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_C_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_AW_C_PARITY), ///< bus_ecc_uncorrected:uncor_err_aw_c_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_W_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_W_PARITY), ///< bus_ecc_uncorrected:uncor_err_w_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_WDATA_PARITY = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_BUS_ECC_UNCORRECTED_UNCOR_ERR_WDATA_PARITY), ///< bus_ecc_uncorrected:uncor_err_wdata_parity for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_BIU0_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_BIU0_ERR_COR), ///< ram_corrected:sd_data_mem_biu0_err_cor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_BIU1_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_BIU1_ERR_COR), ///< ram_corrected:sd_data_mem_biu1_err_cor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_CIU0_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_CIU0_ERR_COR), ///< ram_corrected:sd_data_mem_ciu0_err_cor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_CIU1_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_CORRECTED_SD_DATA_MEM_CIU1_ERR_COR), ///< ram_corrected:sd_data_mem_ciu1_err_cor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_CORRECTED_XSPI_CONTEXT_MEM_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_CORRECTED_XSPI_CONTEXT_MEM_ERR_COR), ///< ram_corrected:xspi_context_mem_err_cor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_CORRECTED_XSPI_DATA_MEM_ERR_COR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_CORRECTED_XSPI_DATA_MEM_ERR_COR), ///< ram_corrected:xspi_data_mem_err_cor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_BIU0_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_BIU0_ERR_UNCOR), ///< ram_uncorrected:sd_data_mem_biu0_err_uncor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_BIU1_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_BIU1_ERR_UNCOR), ///< ram_uncorrected:sd_data_mem_biu1_err_uncor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_CIU0_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_CIU0_ERR_UNCOR), ///< ram_uncorrected:sd_data_mem_ciu0_err_uncor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_CIU1_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_UNCORRECTED_SD_DATA_MEM_CIU1_ERR_UNCOR), ///< ram_uncorrected:sd_data_mem_ciu1_err_uncor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_UNCORRECTED_XSPI_CONTEXT_MEM_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_UNCORRECTED_XSPI_CONTEXT_MEM_ERR_UNCOR), ///< ram_uncorrected:xspi_context_mem_err_uncor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_RAM_UNCORRECTED_XSPI_DATA_MEM_ERR_UNCOR = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_RAM_UNCORRECTED_XSPI_DATA_MEM_ERR_UNCOR), ///< ram_uncorrected:xspi_data_mem_err_uncor for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_TRANS_DROP_BRESP_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_TRANS_DROP_BRESP_TIMEOUT), ///< trans_drop:bresp_timeout for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_TRANS_DROP_DROP_READ_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_TRANS_DROP_DROP_READ_TRANS), ///< trans_drop:drop_read_trans for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_TRANS_DROP_DROP_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_TRANS_DROP_DROP_WRITE_TRANS), ///< trans_drop:drop_write_trans for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_TRANS_DROP_NULL_WRITE_TRANS = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_TRANS_DROP_NULL_WRITE_TRANS), ///< trans_drop:null_write_trans for instance spi_ctrl of structure from NVM
    RAS_ERR_ID_NVM_SPI_CTRL_TRANS_DROP_RDATA_TIMEOUT = RAS_ERROR_ENCODE(NVM, NVM_STRUCT_SPI_CTRL, NVM_SPI_CTRL_TRANS_DROP_RDATA_TIMEOUT), ///< trans_drop:rdata_timeout for instance spi_ctrl of structure from NVM
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
    RAS_ERR_ID_SYS_S7_INTERRUPT_STORM = RAS_ERROR_ENCODE(SYS, SYS_STRUCT_S7, SYS_S7_INTERRUPT_STORM), ///< interrupt:storm for instance s7 of structure from SYS
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

/// @brief Union to faciliate reading a unique RAS error code
typedef union {
    uint32_t w; ///< Word access
    p64h_sysc_ras_error_pack_t b; ///< Bitfield access
} p64h_sysc_ras_error_code_t;

#endif /* RAS_ERR_SRC_H */