/* (c) 2026 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef CPER_SECTIONS_H
#define CPER_SECTIONS_H

#include <ras/p64h_uuid.h>
#include <ras/p64h_cper.h>

/* Autofilled Macros for decoding Error ID Enum ------------------------- */

#define CSU_GUID P64H_UUID_INIT(0xe80f28c9,0xdbec,0x492a,0x96,0x44,0x1b,0x7b,0x50,0xdc,0xc8,0x1f)
#define OCR_GUID P64H_UUID_INIT(0x13c5ad5d,0xdb95,0x41c7,0xad,0x68,0xb1,0x7,0x11,0xf3,0x72,0x10)
#define PQS_GUID P64H_UUID_INIT(0xc3976e68,0x6e87,0x4613,0x88,0x86,0x7b,0xf1,0x3d,0x10,0xe0,0xd3)
#define SEC_NOC_GUID P64H_UUID_INIT(0x917b81c0,0xf1d2,0x4e0a,0xbc,0x3e,0x47,0x5c,0x55,0x6f,0xce,0x60)
#define CMON_GUID P64H_UUID_INIT(0xea5f21a6,0xee6a,0x4f82,0xa5,0x4,0x72,0xd5,0x5e,0xc,0xe6,0x9b)
#define TAMPER_MON_GUID P64H_UUID_INIT(0x1d887da9,0x3a04,0x4cd8,0xbb,0x2e,0x42,0x77,0x76,0x5c,0xf4,0x8d)
#define MESH_GUID P64H_UUID_INIT(0x982f4189,0x6ce5,0x4532,0x86,0x4f,0xde,0xd6,0x1f,0x87,0x66,0x62)
#define PROC_GUID P64H_UUID_INIT(0xd631a848,0xdf88,0x40fe,0x8f,0xc2,0x17,0x11,0xde,0x14,0xf8,0x42)
#define WDOG_GUID P64H_UUID_INIT(0xe14d4ff5,0x3e57,0x403d,0xa8,0xa1,0x3c,0x14,0x2,0x64,0xa5,0x5e)
#define ANA_MON_GUID P64H_UUID_INIT(0x17dcbc1,0x1eb9,0x432c,0x81,0x39,0x10,0xe1,0xa8,0x2,0xa0,0xb1)
#define BOOT_ITR_GUID P64H_UUID_INIT(0x5384df54,0xa2ea,0x4bcd,0x8d,0xba,0x1d,0xa1,0xd3,0x1a,0x85,0x7b)
#define DMA_GUID P64H_UUID_INIT(0xb275af54,0x706d,0x44fc,0x99,0xd7,0x86,0x4a,0xde,0x61,0x66,0xc2)
#define TVS_MON_GUID P64H_UUID_INIT(0x350a0974,0xf450,0x424f,0x87,0x8e,0x3,0x71,0xa6,0xce,0x55,0xa1)
#define RISCV_PROC_GUID P64H_UUID_INIT(0x4b016bd2,0xeda5,0x4042,0x81,0x45,0x4b,0xd6,0x69,0x8c,0x20,0xfb)
#define APP_NOC_GUID P64H_UUID_INIT(0x80495ddc,0xc0f3,0x4189,0x93,0xaa,0xe8,0x8f,0x49,0xcd,0x47,0x9)
#define APP_WDOG_GUID P64H_UUID_INIT(0xe37fed01,0xc09c,0x41e6,0xbf,0x7b,0x6b,0x8e,0x11,0xe,0xa8,0x92)
#define SRAM_EDAC_GUID P64H_UUID_INIT(0xddb8a8b2,0x2914,0x47d3,0x81,0x71,0x47,0x94,0xf6,0x25,0x14,0x83)
#define NVM_EDAC_GUID P64H_UUID_INIT(0x14d3e022,0xf665,0x44eb,0xb7,0x3a,0x4f,0xda,0x6d,0x13,0xa9,0xa1)
#define FW_ERR_GUID P64H_UUID_INIT(0x9a522ab2,0xc256,0x43c1,0xa5,0xbf,0x5c,0xec,0xef,0x5a,0xbc,0x83)
#define INTR_STORM_GUID P64H_UUID_INIT(0x725fa5d3,0x1c3d,0x443f,0x93,0x21,0x44,0x17,0x61,0x57,0x81,0xf6)
#define ENET_SW_GUID P64H_UUID_INIT(0xc80543b2,0xeafe,0x4bbf,0x88,0xf0,0xef,0x3e,0x2,0xcb,0x90,0xee)
#define PFLASH_CTRL_GUID P64H_UUID_INIT(0xd7638d80,0xe961,0x46c5,0x87,0xf9,0x5,0xd,0x96,0x33,0xd0,0xf4)
#define DDR_EDAC_GUID P64H_UUID_INIT(0x3d798239,0xec96,0x4e76,0x8f,0x7e,0x29,0x9f,0xb6,0x69,0xc7,0x4)
#define SPI_CTRL_GUID P64H_UUID_INIT(0x38d66588,0x4d7c,0x498e,0xa4,0x36,0x57,0xa0,0x90,0x1c,0xfa,0x9e)
#define NAND_CTRL_GUID P64H_UUID_INIT(0x4b9f98cd,0x2b66,0x4005,0xb2,0xf,0xcb,0xeb,0x11,0x2d,0x7f,0x47)
#define DDR_CTRL_GUID P64H_UUID_INIT(0xe7f522ea,0xfa2e,0x4eb5,0x96,0xeb,0x3b,0xda,0xa5,0x9a,0x1b,0x6a)
#define DDR_PHY_GUID P64H_UUID_INIT(0xffa2b457,0xeb28,0x4408,0xb4,0x4e,0xc7,0x5c,0xba,0x3b,0xc1,0x5e)
#define DDR_HSIO_GUID P64H_UUID_INIT(0x5b5f6dfa,0xef8c,0x462e,0x83,0xe0,0xd9,0x21,0x8e,0x5b,0x55,0x8f)
#define SPW_CTRL_GUID P64H_UUID_INIT(0xc6e2fb48,0x46fb,0x43a3,0x83,0x89,0xb9,0x43,0x80,0x53,0x54,0x82)
#define SYS_DBG_GUID P64H_UUID_INIT(0xd92727e2,0x8ca0,0x4427,0x99,0x21,0x0,0x15,0x32,0x65,0x93,0x5c)
#define ENET_EP_SB_GUID P64H_UUID_INIT(0xcabf0d35,0xfb90,0x40f8,0xa4,0xb1,0x76,0xfd,0x5c,0x38,0x96,0x4a)
#define ENET_EP_CORE_GUID P64H_UUID_INIT(0x6531de2b,0xefc1,0x41fc,0xaa,0x95,0xf6,0x69,0xc7,0x4f,0x15,0x34)
#define ENET_EP_FRER_TX_GUID P64H_UUID_INIT(0x2fc34bb0,0x8a2,0x4a7d,0xa3,0x54,0x1c,0xee,0x36,0x51,0xa4,0x5a)
#define ENET_EP_FRER_RX_GUID P64H_UUID_INIT(0x710284dc,0x3dac,0x4216,0x9d,0x9a,0x95,0x36,0x6b,0x45,0x1e,0xb6)
#define SYS_NOC_FA_GUID P64H_UUID_INIT(0xe7eee5b1,0x62f4,0x4830,0xa3,0x5,0x74,0xc6,0x9,0xbf,0xaa,0xa2)
#define NOC_OBS_GUID P64H_UUID_INIT(0xd6cdb1eb,0x71de,0x438a,0xa8,0xf,0x8c,0xb,0x52,0x70,0xd6,0x8c)
#define DDR_NOC_GUID P64H_UUID_INIT(0xa670cbc3,0x830e,0x47c0,0x91,0x9c,0x27,0x7,0x2b,0x45,0x8b,0x18)
#define HPT_GUID P64H_UUID_INIT(0x384b7b57,0x2d81,0x40b0,0xa1,0x1e,0x94,0x4d,0xa7,0x15,0x20,0x1c)
#define APP_NOC_FA_GUID P64H_UUID_INIT(0x6ecb792c,0x5286,0x41ca,0x8b,0x53,0x16,0x8b,0x70,0x69,0xfa,0x7e)
#define SVC_NOC_GUID P64H_UUID_INIT(0xe0109c71,0xea2b,0x479f,0x96,0xa1,0xa6,0x75,0x98,0xa3,0x9c,0x76)
#define PCXL_CTRL_GUID P64H_UUID_INIT(0x6ab38634,0x3ac5,0x4e03,0x9d,0x97,0xc,0x87,0x8e,0xf7,0x74,0x6c)
#define PCXL_LINK_GUID P64H_UUID_INIT(0x5b7fe571,0x7e50,0x4267,0xa1,0xc5,0xb2,0x13,0xef,0xd8,0x19,0xbf)

/* Public Structs and Enums - populated from Yaml files ----------------- */
typedef struct {
    p64h_cper_sec_mem_err_t mem;
} memory_section_t;

typedef struct cper_pcie_plat_err {
    p64h_cper_sec_pcie_t pcie;
} pcie_section_t;

/*********************************************
* CSU CPER Section
********************************************/

#define CSU_LOCK_TYPE_PLL 0UL ///< PLL Lock
#define CSU_LOCK_TYPE_OFF_CAL 1UL ///< Offset Calibration Lock
#define CSU_LOCK_STATE_ACQUIRED 0UL ///< Lock is acquired
#define CSU_LOCK_STATE_NOT_ACQUIRED 1UL ///< Lock is not-acquired
#define CSU_EVENT_DETECTION_MECHANISM_POLLING 0UL ///< Polling
#define CSU_EVENT_DETECTION_MECHANISM_INTERRUPT 1UL ///< Interrupt

/**
 * @brief csu CPER section data description
 */
typedef struct {
    uint32_t lock_type; ///< Lock type
    uint32_t lock_state; ///< State of the lock
    uint32_t event_detection_mechanism; ///< Event detection mechanism
} csu_section_t;

/*********************************************
* OCR CPER Section
********************************************/

#define OCR_EVENT_NO_EVENT 0UL ///< No Event
#define OCR_EVENT_MEMORY_ACCESS 1UL ///< Memory access
#define OCR_EVENT_FIFO_OVERFLOW 2UL ///< FIFO Overflow
#define OCR_EVENT_FIFO_UNDERFLOW 3UL ///< FIFO Underflow
#define OCR_EVENT_FIFO_BACK_PRESSURE 4UL ///< FIFO Back-pressure Threshold Reached
#define OCR_EVENT_FIFO_ACCESS 5UL ///< FIFO Access
#define OCR_MEM_ACC_DESC_CAUSE_NO_ERR 0UL ///< No error
#define OCR_MEM_ACC_DESC_CAUSE_WRITE 1UL ///< Write commmand memory access
#define OCR_MEM_ACC_DESC_CAUSE_READ 2UL ///< Read commmand memory access
#define OCR_MEM_ACC_DESC_CAUSE_SCRUBBER 3UL ///< Scrubber commmand memory access
#define OCR_FIFO_ID_NA 0UL ///< Not available
#define OCR_FIFO_ID_MEM_ERR_LOG 1UL ///< Memory error logger
#define OCR_FIFO_ID_SELF_SCRUBBER_SEQ 2UL ///< Self-scrubber sequencer
#define OCR_FIFO_ID_AXI_READ_RESP_BUF 3UL ///< AXI read response buffer
#define OCR_FIFO_ID_AXI_WRITE_RESP_BUF 4UL ///< AXI write response buffer

/**
 * @brief OCR_MEM_ACC_DESC bitfields access descriptor
 */
typedef struct {
    uint32_t cause:4; ///< Type of access that generated the error for the entry in the Memory Error Logger FIFO.
    uint32_t type:5; ///< Error type of the entry in the Memory Error Logger FIFO. There can be more than 1 bit asserted at any entry.
    uint32_t address:23; ///< Memory address at which the fault has been detected
} ocr_mem_acc_desc_bits_t;

/**
 * @brief OCR_MEM_ACC_DESC bit access and word access wrapper union
 */
typedef union {
    ocr_mem_acc_desc_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} ocr_mem_acc_desc_t;

/**
 * @brief OCR_MEM_ACC_ECC bitfields access descriptor
 */
typedef struct {
    uint32_t ecc_0:2; ///< ECC bits of group 0. Each group represents the N 32b group of the read word.
    uint32_t ecc_1:2; ///< ECC bits of group 1. Each group represents the N 32b group of the read word.
    uint32_t ecc_2:2; ///< ECC bits of group 2. Each group represents the N 32b group of the read word.
    uint32_t ecc_3:2; ///< ECC bits of group 3. Each group represents the N 32b group of the read word.
    uint32_t ecc_4:2; ///< ECC bits of group 4. Each group represents the N 32b group of the read word.
    uint32_t ecc_5:2; ///< ECC bits of group 5. Each group represents the N 32b group of the read word.
    uint32_t ecc_6:2; ///< ECC bits of group 6. Each group represents the N 32b group of the read word.
    uint32_t ecc_7:2; ///< ECC bits of group 7. Each group represents the N 32b group of the read word.
    uint32_t pad:16; ///< padding bits
} ocr_mem_acc_ecc_bits_t;

/**
 * @brief OCR_MEM_ACC_ECC bit access and word access wrapper union
 */
typedef union {
    ocr_mem_acc_ecc_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} ocr_mem_acc_ecc_t;

/**
 * @brief ocr CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    ocr_mem_acc_desc_t mem_acc_desc; ///< Memory access failure description
    ocr_mem_acc_ecc_t mem_acc_ecc; ///< Memory access ECC values status
    uint32_t fifo_id; ///< FIFO identifier
} ocr_section_t;

/*********************************************
* PQS CPER Section
********************************************/

#define PQS_STATUS_NO_ERR 0UL ///< No error
#define PQS_STATUS_VERIFICATION_FAILED 1UL ///< Verification failed
#define PQS_STATUS_SERVICE_NOT_SUPPORTED_ERROR 2UL ///< Service not supported error
#define PQS_STATUS_SERVICE_NOT_FOUND_ERROR 3UL ///< Service not found error
#define PQS_STATUS_EXCEPTION_OCCURRED_RESETTING_ERROR 4UL ///< Exception occurred resetting error
#define PQS_STATUS_MEMORY_CORRUPTION_ERROR 5UL ///< Memory corruption error
#define PQS_STATUS_RESET_NEEDED_ERROR 6UL ///< Reset needed error
#define PQS_STATUS_DOWNLOAD_NOT_ALLOWED_ERROR 7UL ///< Download not allowed error
#define PQS_STATUS_DATA_COMM_RECEIVE_ERROR 8UL ///< Data comm receive error
#define PQS_STATUS_DATA_COMM_SEND_ERROR 9UL ///< Data comm send error
#define PQS_STATUS_NOT_READY_ERROR 10UL ///< Not ready error
#define PQS_STATUS_INTERNAL_ERROR 11UL ///< Internal error
#define PQS_STATUS_SELF_TEST_FAILED_ERROR 12UL ///< Self test failed error
#define PQS_STATUS_ZEROISATION_TRIGGERED_ERROR 13UL ///< Zeroisation triggered error
#define PQS_STATUS_BUSY_WITH_OTHER_APPLICATION_ERROR 14UL ///< Busy with other application error
#define PQS_STATUS_NO_APPLICATION_RUNNING_ERROR 15UL ///< No application running error
#define PQS_STATUS_INSUFFICIENT_KEY_MEM_ERROR 16UL ///< Insufficient key mem error
#define PQS_STATUS_INSUFFICIENT_CONTEXT_MEM_ERROR 17UL ///< Insufficient context mem error
#define PQS_STATUS_INSUFFICIENT_IO_MEM_ERROR 18UL ///< Insufficient io mem error
#define PQS_STATUS_INCOMPATIBLE_BINARY_ERROR 19UL ///< Incompatible binary error
#define PQS_STATUS_INCOMPATIBLE_KEY_ERROR 20UL ///< Incompatible key error
#define PQS_STATUS_INVALID_CONTEXT_ERROR 21UL ///< Invalid context error
#define PQS_STATUS_INVALID_KEY_ERROR 22UL ///< Invalid key error
#define PQS_STATUS_OUTPUT_BUFFER SMALL ERROR 23UL ///< Output buffer small error
#define PQS_STATUS_UNSUPPORTED_ALGO_ERROR 24UL ///< Unsupported algo error
#define PQS_STATUS_UNSUPPORTED_ALGO_PARAM_ERROR 25UL ///< Unsupported algo param error
#define PQS_STATUS_UNSUPPORTED_KEY_TYPE_ERROR 26UL ///< Unsupported key type error
#define PQS_STATUS_UNSUPPORTED_FORMAT_ERROR 27UL ///< Unsupported format error
#define PQS_STATUS_UNSUPPORTED_DATA_INTERFACE_ERROR 28UL ///< Unsupported data interface error
#define PQS_STATUS_UNSUPPORTED_DRBG_SECURITY_STRENGTH_ERROR 29UL ///< Unsupported DRBG security strength error
#define PQS_STATUS_WRONG_PARAMETER_VALUE_ERROR 30UL ///< Wrong parameter value error
#define PQS_STATUS_WRONG_ENTROPY_INTERFACE_USED_ERROR 31UL ///< Wrong entropy interface used error
#define PQS_STATUS_WRONG_DIGEST_SIZE_ERROR 32UL ///< Wrong digest size error
#define PQS_STATUS_API_PREREQUISITE_NOT_MET_ERROR 33UL ///< API prerequisite not met error
#define PQS_STATUS_DRBG_REQUIRE_RESEED_ERROR 34UL ///< DRBG require reseed error
#define PQS_STATUS_WRAPQ_PUBLIC_KEY_ABSENT_ERROR 35UL ///< WRAPQ public key absent error
#define PQS_STATUS_KEY_ENCRYPTION_KEY_NOT_SET_ERROR 36UL ///< Key encryption key not set error
#define PQS_STATUS_NOT_SUPPORTED_YET_ERROR 37UL ///< Not supported yet error

/**
 * @brief pqs CPER section data description
 */
typedef struct {
    uint32_t status; ///< Status of PQShield hardware block
} pqs_section_t;

/*********************************************
* SEC_NOC CPER Section
********************************************/

#define SEC_NOC_STATUS_NO_ERR 0UL ///< No error
#define SEC_NOC_STATUS_NIU_TIMEOUT 1UL ///< NIU timeout
#define SEC_NOC_STATUS_BIST_FAILURE 2UL ///< BIST failure

/**
 * @brief SEC_NOC_NIU_MASK bitfields access descriptor
 */
typedef struct {
    uint32_t m1:1; ///< Secure Controller registers in M1 target
    uint32_t acsu:1; ///< Secure Controller ACSU target
    uint32_t dtim:1; ///< DTIM OCR configuration registers target
    uint32_t wdog:1; ///< Wdog (NOC) target
    uint32_t timer:1; ///< Timer (NOC) target
    uint32_t sha3_keccal:1; ///< SHA3_KECCAK (NOC) target
    uint32_t secreg:1; ///< SecReg (NOC) target
    uint32_t sec_mbox:1; ///< Sec_Mbox (NOC) target
    uint32_t dma:1; ///< Sec_DMA Controller (NOC) target
    uint32_t pqs:1; ///< PQ Subordinator (NOC) target
    uint32_t pqm:1; ///< PQ Manager (NOC) target
    uint32_t otp:1; ///< OTP (NOC) target
    uint32_t ocr_mem:1; ///< OCR Data (NOC) target
    uint32_t ocr_ctrl:1; ///< OCR Controller (NOC) target
    uint32_t jtag_mbox:1; ///< JTAG Mbox (NOC) target
    uint32_t crypto:1; ///< Crypto Engine Control & Status (NOC) target
    uint32_t cpu_fp:1; ///< CPU Front Port (NOC) target
    uint32_t boot_rom:1; ///< Boot ROM (NOC) target
    uint32_t sec_noc:1; ///< SEC_NOC Configuration (NOC) target
    uint32_t crypto_sha_dma:1; ///< Crypto Engine SHA DMA (NOC) initiator
    uint32_t crypto_sha3_dma:1; ///< Crypto Engine SHA3 DMA (NOC) initiator
    uint32_t crypto_aes_dma:1; ///< Crypto Engine AES DMA (NOC) initiator
    uint32_t sec_dma:1; ///< Sec_DMA Data (NOC) initiator
    uint32_t cpu_sys:1; ///< CPU System Port (NOC) initiator
    uint32_t pad:8; ///< padding bits
} sec_noc_niu_mask_bits_t;

/**
 * @brief SEC_NOC_NIU_MASK bit access and word access wrapper union
 */
typedef union {
    sec_noc_niu_mask_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} sec_noc_niu_mask_t;

/**
 * @brief sec_noc CPER section data description
 */
typedef struct {
    uint32_t status; ///< Secure Controller NoC error status
    sec_noc_niu_mask_t niu_mask; ///< Bitmask of NIUs in timeout
} sec_noc_section_t;

/*********************************************
* CMON CPER Section
********************************************/

#define CMON_ERROR_NO_ERR 0UL ///< No error
#define CMON_ERROR_INITIAL_LOCK_FAILED 1UL ///< Failed to complete initial calibration/lock to the monitored clock
#define CMON_ERROR_RELOCK_FAILED 2UL ///< Failed to complete a recalibration adjustment to re-lock to the monitored clock
#define CMON_ERROR_OUT_OF_RANGE_FREQ 3UL ///< Detected the level outside the allowed range defined by CLKMON_CFG_ERR while in active state

/**
 * @brief CMON_LEVEL_STATUS bitfields access descriptor
 */
typedef struct {
    uint32_t curr_level:6; ///< Current clock monitor level value
    uint32_t err_level:6; ///< Clock monitor level value that was present at the moment of the error event that triggered entry to the failed state
    uint32_t tap_cfg_code:9; ///< Current clock monitor delay line tap configuration code value
    uint32_t pad:11; ///< padding bits
} cmon_level_status_bits_t;

/**
 * @brief CMON_LEVEL_STATUS bit access and word access wrapper union
 */
typedef union {
    cmon_level_status_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} cmon_level_status_t;

/**
 * @brief cmon CPER section data description
 */
typedef struct {
    uint32_t error; ///< Error state of the clock monitor
    cmon_level_status_t level_status; ///< Description of the level that caused the error
} cmon_section_t;

/*********************************************
* TAMPER_MON CPER Section
********************************************/

#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_PROD_TEST_DETECTED 0UL ///< No mismatch detected
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_PROD_TEST_NOT_DETECTED 1UL ///< Hardware sticky-on-trstb enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_SYSC_DEBUG_DETECTED 0UL ///< No mismatch detected
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_SYSC_DEBUG_NOT_DETECTED 1UL ///< Hardware sticky-on-trstb sysc_debug enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_APPC_DEBUG_NOT_DETECTED 0UL ///< No mismatch detected
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_APPC_DEBUG_DETECTED 1UL ///< Hardware sticky-on-trstb appc_debug enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_SECC_DEBUG_NOT_DETECTED 0UL ///< No mismatch detected
#define TAMPER_MON_TARGET_MISMATCH_PERM_LOCK_SECC_DEBUG_DETECTED 1UL ///< Hardware sticky-on-trstb secc_debug enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED
#define TAMPER_MON_TARGET_TAMPER_PROD_TEST_NOT_DETECTED 0UL ///< No tamper detected
#define TAMPER_MON_TARGET_TAMPER_PROD_TEST_DETECTED 1UL ///< Incorrect enable value sequence was written to HW_STICKY_EN_SEQ_PROD_TEST, or a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state
#define TAMPER_MON_TARGET_TAMPER_SYSC_DEBUG_NOT_DETECTED 0UL ///< No tamper detected
#define TAMPER_MON_TARGET_TAMPER_SYSC_DEBUG_DETECTED 1UL ///< Incorrect enable value sequence was written to HW_STICKY_EN_SEQ_SYSC_DEBUG, or a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state
#define TAMPER_MON_TARGET_TAMPER_APPC_DEBUG_NOT_DETECTED 0UL ///< No tamper detected
#define TAMPER_MON_TARGET_TAMPER_APPC_DEBUG_DETECTED 1UL ///< Incorrect enable value sequence was written to HW_STICKY_EN_SEQ_APPC_DEBUG, or a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state
#define TAMPER_MON_TARGET_TAMPER_SECC_DEBUG_NOT_DETECTED 0UL ///< No tamper detected
#define TAMPER_MON_TARGET_TAMPER_SECC_DEBUG_DETECTED 1UL ///< Incorrect enable value sequence was written to HW_STICKY_EN_SEQ_SECC_DEBUG, or a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state

/**
 * @brief TAMPER_MON_TARGET bitfields access descriptor
 */
typedef struct {
    uint32_t hw_lock:8; ///< Illegal write action to a HW_LOCK register, or the LOCK or UNLOCK fields of a HW_LOCK register is not in one of the valid values
    uint32_t sw_lock:1; ///< Illegal write action to any SW_LOCK register, or the LOCK or UNLOCK fields of any SW_LOCK register is not in one of the valid values
    uint32_t vstart:1; ///< Vstart tamper detected
    uint32_t mismatch_perm_lock_prod_test:1; ///< Production test configuration mismatch
    uint32_t mismatch_perm_lock_sysc_debug:1; ///< Sysc Debug configuration mismatch
    uint32_t mismatch_perm_lock_appc_debug:1; ///< Appc Debug configuration mismatch
    uint32_t mismatch_perm_lock_secc_debug:1; ///< Secc Debug configuration mismatch
    uint32_t tamper_prod_test:1; ///< Production test tamper
    uint32_t tamper_sysc_debug:1; ///< Sysc Debug tamper
    uint32_t tamper_appc_debug:1; ///< Appc Debug tamper
    uint32_t tamper_secc_debug:1; ///< Secc Debug tamper
    uint32_t pad:14; ///< padding bits
} tamper_mon_target_bits_t;

/**
 * @brief TAMPER_MON_TARGET bit access and word access wrapper union
 */
typedef union {
    tamper_mon_target_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} tamper_mon_target_t;

/**
 * @brief tamper_mon CPER section data description
 */
typedef struct {
    tamper_mon_target_t target; ///< Target on which a tamper event was detected
} tamper_mon_section_t;

/*********************************************
* MESH CPER Section
********************************************/

#define MESH_ERROR_SRC_SEC_NO_MISTMATCH_DETECTED 0UL ///< No mismatch detected
#define MESH_ERROR_SRC_SEC_MISTATCH_DETECTED 1UL ///< Mismatch detected
#define MESH_ERROR_SRC_USR_CRYPTO_NO_MISTMATCH_DETECTED 0UL ///< No mismatch detected
#define MESH_ERROR_SRC_USR_CRYPTO_MISTATCH_DETECTED 1UL ///< Mismatch detected
#define MESH_ERROR_SRC_DDR_ENCRYPT_NO_MISTMATCH_DETECTED 0UL ///< No mismatch detected
#define MESH_ERROR_SRC_DDR_ENCRYPT_MISTATCH_DETECTED 1UL ///< Mismatch detected
#define MESH_ERROR_SRC_ANA_NO_MISTMATCH_DETECTED 0UL ///< No mismatch detected
#define MESH_ERROR_SRC_ANA_MISTATCH_DETECTED 1UL ///< Mismatch detected

/**
 * @brief MESH_ERROR_SRC bitfields access descriptor
 */
typedef struct {
    uint32_t sec:1; ///< Secure controller mesh block
    uint32_t usr_crypto:1; ///< User crypto mesh block
    uint32_t ddr_encrypt:1; ///< DDR encryptor mesh block
    uint32_t ana:1; ///< Analog top and PUF mesh block
    uint32_t pad:28; ///< padding bits
} mesh_error_src_bits_t;

/**
 * @brief MESH_ERROR_SRC bit access and word access wrapper union
 */
typedef union {
    mesh_error_src_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} mesh_error_src_t;

/**
 * @brief mesh CPER section data description
 */
typedef struct {
    mesh_error_src_t error_src; ///< Mesh blocks onto which a mismatch was detected
} mesh_section_t;

/*********************************************
* PROC CPER Section
********************************************/

#define PROC_STATE_DEBUG_NDRESET_DEBUG_NDRESET_DEASSERTED 0UL ///< Debug NDreset deasserted
#define PROC_STATE_DEBUG_NDRESET_DEBUG_NDRESET_ASSERTED 1UL ///< Debug NDreset asserted
#define PROC_STATE_DEBUG_DMACTIVE_NOT_ACTIVE 0UL ///< Debug DMA not active
#define PROC_STATE_DEBUG_DMACTIVE_ACTIVE 1UL ///< Debug DMA active
#define PROC_STATE_CEASE_NOT_ACTIVE 0UL ///< Processor in CEASE state
#define PROC_STATE_CEASE_ACTIVE 1UL ///< Processor not in CEASE state
#define PROC_STATE_HALT_NOT_ACTIVE 0UL ///< Processor in HALT state
#define PROC_STATE_HALT_ACTIVE 1UL ///< Processor not in HALT state
#define PROC_STATE_WFI_NOT_ACTIVE 0UL ///< Processor in WFI state
#define PROC_STATE_WFI_ACTIVE 1UL ///< Processor not in WFI state
#define PROC_STATE_DEBUG_NOT_ACTIVE 0UL ///< Processor in DEBUG state
#define PROC_STATE_DEBUG_ACTIVE 1UL ///< Processor not in DEBUG state
#define PROC_TIMER_FIFO_OVERFLOW_NOT_DETECTED 0UL ///< No overflow detected
#define PROC_TIMER_FIFO_OVERFLOW_DETECTED 1UL ///< FIFO overflow detected
#define PROC_JTAG_NO_ERR 0UL ///< No error
#define PROC_JTAG_APB2JTAG_SEQ_ERR 1UL ///< SecC APB2JTAG sequence error detected

/**
 * @brief PROC_STATE bitfields access descriptor
 */
typedef struct {
    uint32_t debug_ndreset:1; ///< Debug NDreset state
    uint32_t debug_dmactive:1; ///< Debug DMA state
    uint32_t cease:1; ///< RISCV processor CEASE state
    uint32_t halt:1; ///< RISCV processor HALT state
    uint32_t wfi:1; ///< RISCV processor WFI state
    uint32_t debug:1; ///< RISCV processor DEBUG state
    uint32_t pad:26; ///< padding bits
} proc_state_bits_t;

/**
 * @brief PROC_STATE bit access and word access wrapper union
 */
typedef union {
    proc_state_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} proc_state_t;

/**
 * @brief PROC_MEM bitfields access descriptor
 */
typedef struct {
    uint32_t otp:2; ///< OTP
    uint32_t sec_mbox:2; ///< Secure Mailbox
    uint32_t jtag_mbox:2; ///< JTAG Mailbox
    uint32_t dma_ch:2; ///< Secure DMA channel FIFO
    uint32_t boot_rom:2; ///< Boot ROM
    uint32_t s7_trace:2; ///< S7 Trace
    uint32_t pqcs_rom:2; ///< PQCS ROM
    uint32_t pqcs_isram:2; ///< PQCS ISRAM
    uint32_t pqcs_dsram:2; ///< PQCS DSRAM
    uint32_t ecultra:2; ///< ECULTRA
    uint32_t kgscrtr:2; ///< KGSCRTR
    uint32_t key_rom:2; ///< Key ROM
    uint32_t pad:8; ///< padding bits
} proc_mem_bits_t;

/**
 * @brief PROC_MEM bit access and word access wrapper union
 */
typedef union {
    proc_mem_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} proc_mem_t;

/**
 * @brief PROC_TIMER bitfields access descriptor
 */
typedef struct {
    uint32_t fifo_overflow:1; ///< CDC FIFO overflow detection
    uint32_t pad:31; ///< padding bits
} proc_timer_bits_t;

/**
 * @brief PROC_TIMER bit access and word access wrapper union
 */
typedef union {
    proc_timer_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} proc_timer_t;

/**
 * @brief proc CPER section data description
 */
typedef struct {
    proc_state_t state; ///< SecC processor state
    proc_mem_t mem; ///< RAM resource map for ECC reports
    proc_timer_t timer; ///< High Precision Timer Status
    uint32_t jtag; ///< JTAG event
} proc_section_t;

/*********************************************
* WDOG CPER Section
********************************************/

#define WDOG_EVENT_RESET_PEND_CAUSE_SECOND_WINDOW_EXPIRY 0UL ///< Reset pending stage was entered due to expiry of the second window
#define WDOG_EVENT_RESET_PEND_CAUSE_EARLY_REFRESH 1UL ///< Reset pending stage was entered due to a refresh action occuring during a closed first window stage phase
#define WDOG_EVENT_COUNT_VALID_COUNT_INVALID 0UL ///< Count is invalid
#define WDOG_EVENT_COUNT_VALID_COUNT_VALID 1UL ///< Count is valid

/**
 * @brief WDOG_EVENT bitfields access descriptor
 */
typedef struct {
    uint32_t curr_act_win:3; ///< Currently active window
    uint32_t reset_pend_cause:1; ///< Cause of entry to the reset pending stage. Only valid when the WDOG is in the reset pending stage or the reset request stage
    uint32_t count_valid:1; ///< Informs if the count value provided is valid
    uint32_t pad:27; ///< padding bits
} wdog_event_bits_t;

/**
 * @brief WDOG_EVENT bit access and word access wrapper union
 */
typedef union {
    wdog_event_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} wdog_event_t;

/**
 * @brief wdog CPER section data description
 */
typedef struct {
    wdog_event_t event; ///< WDOG event
    uint32_t curr_count_lo; ///< Current value of the WDOG counter (lower bits)
    uint32_t curr_count_hi; ///< Current value of the WDOG counter (higher bits)
} wdog_section_t;

/*********************************************
* ANA_MON CPER Section
********************************************/

#define ANA_MON_EVENT_NO_EVENT 0UL ///< No events reported
#define ANA_MON_EVENT_VSUPP_OUT_OF_RANGE 1UL ///< Voltage supply crossed threshold
#define ANA_MON_EVENT_VDD_BROWNOUT 2UL ///< VDD Brownout detected
#define ANA_MON_EVENT_VDD_1_8_BROWNOUT 3UL ///< VDD 1.8 Brownout detected
#define ANA_MON_EVENT_OPEN_PACKAGE 4UL ///< Open package detected
#define ANA_MON_EVENT_VDD_POWER_GLITCH 5UL ///< Power glitch detected on the VDD supply
#define ANA_MON_VDD_XTHRES_NONE 0UL ///< No threshold was violated
#define ANA_MON_VDD_XTHRES_VDD_1_8 1UL ///< 1.8 VDD
#define ANA_MON_VDD_XTHRES_VDD_0_9 2UL ///< 0.9 VDD
#define ANA_MON_VDD_XTHRES_VDD_0_8 3UL ///< 0.8 VDD
#define ANA_MON_VDD_XTHRES_VDD_0_7 4UL ///< 0.7 VDD

/**
 * @brief ana_mon CPER section data description
 */
typedef struct {
    uint32_t event; ///< Analog monitor event type
    uint32_t vdd_xthres; ///< Value of the voltage for which the monitoring threshold has been crossed
} ana_mon_section_t;

/*********************************************
* BOOT_ITR CPER Section
********************************************/

#define BOOT_ITR_SYSC_BOOT_MODE_POR_POR 0UL ///< POR
#define BOOT_ITR_SYSC_BOOT_MODE_POR_NOT_POR 1UL ///< Not POR
#define BOOT_ITR_SYSC_BOOT_MODE_EARLY_SYS_ZSBL_ACTIVE_EARLY_ZSBL_ACTIVE 0UL ///< Early ZSBL active
#define BOOT_ITR_SYSC_BOOT_MODE_EARLY_SYS_ZSBL_ACTIVE_EARLY_ZSBL_INACTIVE 1UL ///< Early ZSBL inactive
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_ZSBL_ACTIVE_ZSBL_ACTIVE 0UL ///< ZSBL active
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_ZSBL_ACTIVE_ZSBL_INACTIVE 1UL ///< ZSBL inactive
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_FSBL_ACTIVE_FSBL_ACTIVE 0UL ///< FSBL active
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_FSBL_ACTIVE_FSBL_INACTIVE 1UL ///< FSBL inactive
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_FSBL_FAIL_MODE_FSBL_POLICY 0UL ///< follow policy in image_table_entry
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_FSBL_FAIL_MODE_IMG_TBL_ENTRY_POLICY 1UL ///< follow fsbl defined policy
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_FSBL_POLICY_REQ_EMERGENCY_MODE 0UL ///< request emergency mode
#define BOOT_ITR_SYSC_BOOT_MODE_SYS_FSBL_POLICY_FSBL_POLICY_IMG 1UL ///< use sys_fsbl_policy_image
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_PERIPH_INIT_SYS_ZSBL_PERIPH_NOT_INIT 0UL ///< SYSC ZSBL peripheral not initalized
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_PERIPH_INIT_SYS_ZSBL_PERIPH_INIT 1UL ///< SYSC ZSBL peripheral initalized
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_NVM_READ_AUTH_SYS_ZSBL_NVM_READ_NOT_AUTH 0UL ///< SYS ZSBL NVM read not authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_NVM_READ_AUTH_SYS_ZSBL_NVM_READ_AUTH 1UL ///< SYS ZSBL NVM read authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_FLASH_HDR_AUTH_SYS_ZSBL_FLASH_HDR_NOT_AUTH 0UL ///< SYS ZSBL flash header not authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_FLASH_HDR_AUTH_SYS_ZSBL_FLASH_HDR_AUTH 1UL ///< SYS ZSBL flash header authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_DTB_AUTH_SYS_ZSBL_DTB_NOT_AUTH 0UL ///< SYS ZSBL DTB not authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_DTB_AUTH_SYS_ZSBL_DTB_AUTH 1UL ///< SYS ZSBL DTB authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_OCR_FW_AUTH_SYS_ZSBL_OCR_FW_NOT_AUTH 0UL ///< SYS_ZSBL OCR firmware not authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_OCR_FW_AUTH_SYS_ZSBL_OCR_FW_AUTH 1UL ///< SYS_ZSBL OCR firmware authenticated
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_FSBL_JUMP_SYS_ZSBL_FSBL_JUMP_NOT_DONE 0UL ///< SYS ZSBL FSBL jump not done
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_ZSBL_FSBL_JUMP_SYS_ZSBL_FSBL_JUMP_DONE 1UL ///< SYS ZSBL FSBL jump done
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_FSBL_MAIN_START_SYS_FSBL_MAIN_NOT_STARTED 0UL ///< SYS FSBL main not started
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_FSBL_MAIN_START_SYS_FSBL_MAIN_STARTED 1UL ///< SYS FSBL main started
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_FSBL_MON_ACTIVE_SYS_FSBL_MON_NOT_ACTIVE 0UL ///< SYS FSBL monitor not active
#define BOOT_ITR_SYSC_BOOT_CTXT_SYS_FSBL_MON_ACTIVE_SYS_FSBL_MON_ACTIVE 1UL ///< SYS FSBL monitor active
#define BOOT_ITR_SYSC_RESET_REASON_IN_RESET 0UL ///< sysc_reset_reason_in_reset
#define BOOT_ITR_SYSC_RESET_REASON_SUBSYSTEM_RESET 1UL ///< sysc_reset_reason_subsystem_reset
#define BOOT_ITR_SYSC_RESET_REASON_WDOG_RESET 2UL ///< sysc_reset_reason_wdog_reset
#define BOOT_ITR_SYSC_RESET_REASON_SOFT_RESET 3UL ///< sysc_reset_reason_soft_reset
#define BOOT_ITR_SYSC_RESET_REASON_DEBUG_RESET 4UL ///< sysc_reset_reason_debug_reset
#define BOOT_ITR_SYSC_RESET_REASON_DEVICE_RESET 5UL ///< sysc_reset_reason_device_reset
#define BOOT_ITR_SYSC_RESET_REASON_SYSTEM_RESET 6UL ///< sysc_reset_reason_system_reset
#define BOOT_ITR_SECC_RESET_REASON_POR_RESET 0UL ///< secc_reset_reason_por_reset
#define BOOT_ITR_SECC_RESET_REASON_SOFT_RESET_EN_S7_CORE 1UL ///< secc_reset_reason_soft_reset_en_s7_core
#define BOOT_ITR_SECC_RESET_REASON_DEBUG_RESET 2UL ///< secc_reset_reason_debug_reset
#define BOOT_ITR_SECC_RESET_REASON_WDOG_AR0 3UL ///< secc_reset_reason_wdog_ar0
#define BOOT_ITR_SECC_RESET_REASON_WDOG_AR1 4UL ///< secc_reset_reason_wdog_ar1
#define BOOT_ITR_SECC_RESET_REASON_DEVICE_RESET 5UL ///< secc_reset_reason_device_reset
#define BOOT_ITR_SECC_RESET_REASON_TAMPER_RESET 6UL ///< secc_reset_reason_tamper_reset

/**
 * @brief BOOT_ITR_SYSC_BOOT_MODE bitfields access descriptor
 */
typedef struct {
    uint32_t por:1; ///< Indicates power-on reset; Assumption is that it is cleared on POR
    uint32_t early_sys_zsbl_active:1; ///< indicates if ZSBL is active; tracks this iteration of code execution prior to plan_iteration() analyzing prior iteration data.
    uint32_t sys_zsbl_active:1; ///< indicates if ZSBL is active
    uint32_t sys_fsbl_active:1; ///< indicates if FSBL is active
    uint32_t image_id:3; ///< image_id being processed for sysc FSBL boot procedure
    uint32_t sysc_boot_sticky:6; ///< Sticky bits for SysC ZSBL to transfer to BOOT_STAT on execution startup
    uint32_t sys_fsbl_boot_req:2; ///< FSBL boot request command see sysc_fsbl_boot_req_t
    uint32_t sys_fsbl_boot_image_id:3; ///< FSBL requested image_id for SysC ZSBL to attempt boot
    uint32_t sys_fsbl_fail_mode:1; ///< FSBL force image boot fails
    uint32_t sys_fsbl_policy:1; ///< on failure of FSBL forced image boot
    uint32_t sys_fsbl_policy_image:3; ///< FSBL force image boot, failure rollback next image ID
    uint32_t pad:9; ///< padding bits
} boot_itr_sysc_boot_mode_bits_t;

/**
 * @brief BOOT_ITR_SYSC_BOOT_MODE bit access and word access wrapper union
 */
typedef union {
    boot_itr_sysc_boot_mode_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} boot_itr_sysc_boot_mode_t;

/**
 * @brief BOOT_ITR_SYSC_BOOT_CTXT bitfields access descriptor
 */
typedef struct {
    uint32_t sys_zsbl_periph_init:1; ///< Enter ZSBL Reset Init Periph section, this iteration
    uint32_t sys_zsbl_nvm_read_auth:1; ///< Enter ZSBL NVM Read and Auth section, this iteration
    uint32_t sys_zsbl_flash_hdr_auth:1; ///< Completed successful Flash Header Authentication, this iteration
    uint32_t sys_zsbl_dtb_auth:1; ///< Completed successful FSBL DTB Authentication, this iteration
    uint32_t sys_zsbl_ocr_fw_auth:1; ///< Completed successful FSBL FW Binary Authentication, this iteration
    uint32_t sys_zsbl_fsbl_jump:1; ///< Calling Jump to FSBL program, this iteration
    uint32_t sys_fsbl_main_start:1; ///< Enter FSBL main function, this iteration
    uint32_t sys_fsbl_mon_active:1; ///< Completed FSBL initial appc boot and in monitor mode, this iteration
    uint32_t sys_zsbl_img_fail_cnt:2; ///< Count ZSBL failed before FSBL Jump, this image attempt
    uint32_t sys_fsbl_img_fail_cnt:2; ///< Count FSBL failed before FSBL entered monitoring state
    uint32_t sys_img_fail_limit:2; ///< Limit FSBL and ZSBL can fail before entering monitoring phase, this image attempt
    uint32_t sys_zsbl_otp_itn_fail_cnt:6; ///< Count ZSBL failed for an iteration of n images in OTP image attempt execution
    uint32_t sys_zsbl_no_plan_fail_cnt:6; ///< Count ZSBL failed prior to planning an image boot or to enter emergency mode
    uint32_t sys_fsbl_mon_fail_cnt:6; ///< Count FSBL failed in monitoring phase since POR
} boot_itr_sysc_boot_ctxt_bits_t;

/**
 * @brief BOOT_ITR_SYSC_BOOT_CTXT bit access and word access wrapper union
 */
typedef union {
    boot_itr_sysc_boot_ctxt_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} boot_itr_sysc_boot_ctxt_t;

/**
 * @brief boot_itr CPER section data description
 */
typedef struct {
    boot_itr_sysc_boot_mode_t sysc_boot_mode; ///< Current value of the boot counter for the zero stage ROM bootloader
    boot_itr_sysc_boot_ctxt_t sysc_boot_ctxt; ///< Boot context for the SysC
    uint32_t sysc_boot_cnt; ///< Number of times the System Controller has been rebooted from POR
    uint32_t sysc_reset_reason; ///< Reason for previous reset
    uint32_t secc_boot_cnt; ///< Number of times the Secure Controller has been rebooted from POR
    uint32_t secc_reset_reason; ///< Reason for previous reset
} boot_itr_section_t;

/*********************************************
* DMA CPER Section
********************************************/

#define DMA_EVT_SOURCE_COMMON_REGISTERS 0UL ///< Common registers
#define DMA_EVT_SOURCE_CHANNEL_1 1UL ///< Channel 1
#define DMA_EVT_SOURCE_CHANNEL_2 2UL ///< Channel 2
#define DMA_EVT_SOURCE_CHANNEL_3 3UL ///< Channel 3
#define DMA_EVT_SOURCE_CHANNEL_4 4UL ///< Channel 4
#define DMA_EVT_SOURCE_CHANNEL_5 5UL ///< Channel 5
#define DMA_EVT_SOURCE_CHANNEL_6 6UL ///< Channel 6
#define DMA_EVT_SOURCE_CHANNEL_7 7UL ///< Channel 7
#define DMA_EVT_SOURCE_CHANNEL_8 8UL ///< Channel 8
#define DMA_EVT_SOURCE_NO_EVENT 9UL ///< No event
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Decode Errors
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_DEC_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Decode Error detected
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_WR2RO_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Write to Read Only Errors
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_WR2RO_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Write to Read Only Error detected
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_RD2WO_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Read to Write Only Errors
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_RD2WO_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Read to Write Only Error detected
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_WRONHOLD_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Common Register Write On Hold Errors
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_WRONHOLD_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Common Register Write On Hold Error detected
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_ADDRPARITY_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Common Register Space Address Parity Error
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_ADDRPARITY_ERR_INTSTAT_DETECTED 1UL ///< Common Register Space Address Parity Error detected.
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_WRPARITY_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Common Register Space Write Parity Error
#define DMA_COMMON_REG_EVT_SLVIF_COMMONREG_WRPARITY_ERR_INTSTAT_DETECTED 1UL ///< Common Register Space Write Parity Error detected
#define DMA_COMMON_REG_EVT_SLVIF_UNDEFINEDREG_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Decode Errors
#define DMA_COMMON_REG_EVT_SLVIF_UNDEFINEDREG_DEC_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Decode Error detected
#define DMA_COMMON_REG_EVT_MXIF1_RCH0_PROT_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Read Channel Data related Correctable Error
#define DMA_COMMON_REG_EVT_MXIF1_RCH0_PROT_CORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Read Channel Data related Correctable Error detected
#define DMA_COMMON_REG_EVT_MXIF1_RCH0_PROT_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Read Channel Data related Uncorrectable Error
#define DMA_COMMON_REG_EVT_MXIF1_RCH0_PROT_UNCORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Read Channel Data related Uncorrectable Error detected
#define DMA_COMMON_REG_EVT_MXIF1_RCH1_PROT_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Read Channel Control signals related Correctable Error
#define DMA_COMMON_REG_EVT_MXIF1_RCH1_PROT_CORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Read Channel Control signals related Correctable Error detected
#define DMA_COMMON_REG_EVT_MXIF1_RCH1_PROT_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Read Channel Control signals related Uncorrectable Error
#define DMA_COMMON_REG_EVT_MXIF1_RCH1_PROT_UNCORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Read Channel Control signals related Uncorrectable Error detected
#define DMA_COMMON_REG_EVT_MXIF1_BCH_PROT_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Write Response Channel Correctable Error
#define DMA_COMMON_REG_EVT_MXIF1_BCH_PROT_CORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Write Response Channel Correctable Error detected
#define DMA_COMMON_REG_EVT_MXIF1_BCH_PROT_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Write Response Channel Uncorrectable Error.
#define DMA_COMMON_REG_EVT_MXIF1_BCH_PROT_UNCORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Write Response Channel Uncorrectable Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_RCH0_PROT_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Read Channel Data related Correctable Error.
#define DMA_COMMON_REG_EVT_MXIF2_RCH0_PROT_CORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Read Channel Data related Correctable Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_RCH0_PROT_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Read Channel Data related Uncorrectable Error.
#define DMA_COMMON_REG_EVT_MXIF2_RCH0_PROT_UNCORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Read Channel Data related Uncorrectable Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_RCH1_PROT_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Read Channel Control signals related Correctable Error.
#define DMA_COMMON_REG_EVT_MXIF2_RCH1_PROT_CORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Read Channel Control signals related Correctable Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_RCH1_PROT_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Read Channel Control signals related Uncorrectable Error.
#define DMA_COMMON_REG_EVT_MXIF2_RCH1_PROT_UNCORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Read Channel Control signals related Uncorrectable Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_BCH_PROT_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Write Response Channel Correctable Error.
#define DMA_COMMON_REG_EVT_MXIF2_BCH_PROT_CORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Write Response Channel Correctable Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_BCH_PROT_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Write Response Channel Uncorrectable Error.
#define DMA_COMMON_REG_EVT_MXIF2_BCH_PROT_UNCORRERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Write Response Channel Uncorrectable Error detected.
#define DMA_COMMON_REG_EVT_MXIF1_ARCH_PROT_ARREADY_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Read Address Channel ARREADY Parity Error.
#define DMA_COMMON_REG_EVT_MXIF1_ARCH_PROT_ARREADY_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Read Address Channel ARREADY Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF1_AWCH_PROT_AWREADY_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Write Address Channel AWREADY Parity Error.
#define DMA_COMMON_REG_EVT_MXIF1_AWCH_PROT_AWREADY_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Write Address Channel AWREADY Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF1_WCH_PROT_WREADY_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Write Data Channel WREADY Parity Error.
#define DMA_COMMON_REG_EVT_MXIF1_WCH_PROT_WREADY_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Write Data Channel WREADY Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF1_RCH_PROT_RVALID_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Read Data Channel RVALID Parity Error.
#define DMA_COMMON_REG_EVT_MXIF1_RCH_PROT_RVALID_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Read Data Channel RVALID Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF1_BCH_PROT_BVALID_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 1 Write Response Channel BVALID Parity Error.
#define DMA_COMMON_REG_EVT_MXIF1_BCH_PROT_BVALID_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 1 Write Response Channel BVALID Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_ARCH_PROT_ARREADY_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Read Address Channel ARREADY Parity Error.
#define DMA_COMMON_REG_EVT_MXIF2_ARCH_PROT_ARREADY_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Read Address Channel ARREADY Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_AWCH_PROT_AWREADY_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Write Address Channel AWREADY Parity Error.
#define DMA_COMMON_REG_EVT_MXIF2_AWCH_PROT_AWREADY_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Write Address Channel AWREADY Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_WCH_PROT_WREADY_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Write Data Channel WREADY Parity Error.
#define DMA_COMMON_REG_EVT_MXIF2_WCH_PROT_WREADY_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Write Data Channel WREADY Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_RCH_PROT_RVALID_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Read Data Channel RVALID Parity Error.
#define DMA_COMMON_REG_EVT_MXIF2_RCH_PROT_RVALID_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Read Data Channel RVALID Parity Error detected.
#define DMA_COMMON_REG_EVT_MXIF2_BCH_PROT_BVALID_PARERR_INTSTAT_NOT_DETECTED 0UL ///< No AXI Manager 2 Write Response Channel BVALID Parity Error.
#define DMA_COMMON_REG_EVT_MXIF2_BCH_PROT_BVALID_PARERR_INTSTAT_DETECTED 1UL ///< AXI Manager 2 Write Response Channel BVALID Parity Error detected.
#define DMA_CHANNEL_EVT_SRC_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Source Decode Errors.
#define DMA_CHANNEL_EVT_SRC_DEC_ERR_INTSTAT_DETECTED 1UL ///< Source Decode Error detected.
#define DMA_CHANNEL_EVT_DST_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< No destination Decode Errors.
#define DMA_CHANNEL_EVT_DST_DEC_ERR_INTSTAT_DETECTED 1UL ///< Destination Decode Error Detected
#define DMA_CHANNEL_EVT_SRC_SLV_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Source Subordinate Errors
#define DMA_CHANNEL_EVT_SRC_SLV_ERR_INTSTAT_DETECTED 1UL ///< Source Subordinate Error Detected
#define DMA_CHANNEL_EVT_DST_SLV_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Destination Subordinate Errors
#define DMA_CHANNEL_EVT_DST_SLV_ERR_INTSTAT_DETECTED 1UL ///< Destination Subordinate Errors Detected
#define DMA_CHANNEL_EVT_LLI_RD_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< NO LLI Read Decode Errors.
#define DMA_CHANNEL_EVT_LLI_RD_DEC_ERR_INTSTAT_DETECTED 1UL ///< LLI Read Decode Error detected
#define DMA_CHANNEL_EVT_LLI_WR_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< NO LLI Write Decode Errors.
#define DMA_CHANNEL_EVT_LLI_WR_DEC_ERR_INTSTAT_DETECTED 1UL ///< LLI write Decode Error detected.
#define DMA_CHANNEL_EVT_LLI_RD_SLV_ERR_INTSTAT_NOT_DETECTED 0UL ///< No LLI Read Subordinate Errors.
#define DMA_CHANNEL_EVT_LLI_RD_SLV_ERR_INTSTAT_DETECTED 1UL ///< LLI read Subordinate Error detected.
#define DMA_CHANNEL_EVT_LLI_WR_SLV_ERR_INTSTAT_NOT_DETECTED 0UL ///< No LLI write Subordinate Errors.
#define DMA_CHANNEL_EVT_LLI_WR_SLV_ERR_INTSTAT_DETECTED 1UL ///< LLI Write SUBORDINATE Error detected.
#define DMA_CHANNEL_EVT_SHADOWREG_OR_LLI_INVALID_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Shadow Register / LLI Invalid errors.
#define DMA_CHANNEL_EVT_SHADOWREG_OR_LLI_INVALID_ERR_INTSTAT_DETECTED 1UL ///< Shadow Register / LLI Invalid error detected.
#define DMA_CHANNEL_EVT_SLVIF_MULTIBLKTYPE_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Multi-block transfer type Errors.
#define DMA_CHANNEL_EVT_SLVIF_MULTIBLKTYPE_ERR_INTSTAT_DETECTED 1UL ///< Multi-block transfer type Error detected.
#define DMA_CHANNEL_EVT_SLVIF_DEC_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Decode errors.
#define DMA_CHANNEL_EVT_SLVIF_DEC_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Decode Error detected.
#define DMA_CHANNEL_EVT_SLVIF_WR2RO_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Write to Read Only Errors.
#define DMA_CHANNEL_EVT_SLVIF_WR2RO_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Write to Read Only Error detected.
#define DMA_CHANNEL_EVT_SLVIF_RD2RWO_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Read to Write Only Errors.
#define DMA_CHANNEL_EVT_SLVIF_RD2RWO_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Read to Write Only Error detected.
#define DMA_CHANNEL_EVT_SLVIF_WRONCHEN_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Write On Channel Enabled Errors.
#define DMA_CHANNEL_EVT_SLVIF_WRONCHEN_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Write On Channel Enabled Error detected.
#define DMA_CHANNEL_EVT_SLVIF_SHADOWREG_WRON_VALID_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Shadow Register Write On Valid Errors.
#define DMA_CHANNEL_EVT_SLVIF_SHADOWREG_WRON_VALID_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Shadow Register Write On Valid Error detected.
#define DMA_CHANNEL_EVT_SLVIF_WRONHOLD_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Write On Hold Errors.
#define DMA_CHANNEL_EVT_SLVIF_WRONHOLD_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Write On Hold Error detected.
#define DMA_CHANNEL_EVT_SLVIF_ADDRPARITY_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Address Parity Errors.
#define DMA_CHANNEL_EVT_SLVIF_ADDRPARITY_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Address Parity Error detected.
#define DMA_CHANNEL_EVT_SLVIF_WRPARITY_ERR_INTSTAT_NOT_DETECTED 0UL ///< No Register Bus Interface Write Parity Errors.
#define DMA_CHANNEL_EVT_SLVIF_WRPARITY_ERR_INTSTAT_DETECTED 1UL ///< Register Bus Interface Write Parity Error detected.
#define DMA_CHANNEL_EVT_ECC_PROT_CHMEM_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No Channel x FIFO Memory Interface correctable Error.
#define DMA_CHANNEL_EVT_ECC_PROT_CHMEM_CORRERR_INTSTAT_DETECTED 1UL ///< Channel x FIFO Memory Interface correctable Error detected.
#define DMA_CHANNEL_EVT_ECC_PROT_CHMEM_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No Channel x FIFO Memory Interface Uncorrectable Error.
#define DMA_CHANNEL_EVT_ECC_PROT_CHMEM_UNCORRERR_INTSTAT_DETECTED 1UL ///< Channel x FIFO Memory Interface Uncorrectable Error detected.
#define DMA_CHANNEL_EVT_ECC_PROT_UIDMEM_CORRERR_INTSTAT_NOT_DETECTED 0UL ///< No Channel x UID Memory Interface correctable Error.
#define DMA_CHANNEL_EVT_ECC_PROT_UIDMEM_CORRERR_INTSTAT_DETECTED 1UL ///< Channel x UID Memory Interface correctable Error detected.
#define DMA_CHANNEL_EVT_ECC_PROT_UIDMEM_UNCORRERR_INTSTAT_NOT_DETECTED 0UL ///< No Channel x UID Memory Interface Uncorrectable Error.
#define DMA_CHANNEL_EVT_ECC_PROT_UIDMEM_UNCORRERR_INTSTAT_DETECTED 1UL ///< Channel x UID Memory Interface Uncorrectable Error detected.
#define DMA_CHANNEL_EVT_CHAN_TX_SRC_VALID_UNSET 0UL ///< Data in the chan_tx_src field is not valid
#define DMA_CHANNEL_EVT_CHAN_TX_SRC_VALID_SET 1UL ///< Data in the chan_tx_src field is valid
#define DMA_CHANNEL_EVT_CHAN_TX_DST_VALID_UNSET 0UL ///< Data in the chan_tx_dst field is not valid
#define DMA_CHANNEL_EVT_CHAN_TX_DST_VALID_SET 1UL ///< Data in the chan_tx_dst field is valid
#define DMA_CHANNEL_EVT_CHAN_TX_DATA_VALID_UNSET 0UL ///< Data in the chan_tx_data field is not valid
#define DMA_CHANNEL_EVT_CHAN_TX_DATA_VALID_SET 1UL ///< Data in the chan_tx_data field is valid
#define DMA_CHAN_TX_DATA_DATA_LENGTH_8_BITS 0UL ///< Source Transfer Width is 8 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_16_BITS 1UL ///< Source Transfer Width is 16 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_32_BITS 2UL ///< Source Transfer Width is 32 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_64_BITS 3UL ///< Source Transfer Width is 64 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_128_BITS 4UL ///< Source Transfer Width is 128 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_256_BITS 5UL ///< Source Transfer Width is 256 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_512_BITS 6UL ///< Source Transfer Width is 512 bits
#define DMA_CHAN_TX_DATA_DATA_LENGTH_1024_BITS 7UL ///< Source Transfer Width is 1024 bits

/**
 * @brief DMA_COMMON_REG_EVT bitfields access descriptor
 */
typedef struct {
    uint32_t slvif_commonreg_dec_err_intstat:1; ///< Decode Error generated by DW_axi_dmac during register access. This error occurs if the register access is to an invalid address in the common register space
    uint32_t slvif_commonreg_wr2ro_err_intstat:1; ///< Register Bus Interface Common Register Write to Read Only Error Interrupt Status bit
    uint32_t slvif_commonreg_rd2wo_err_intstat:1; ///< Register Bus Interface Common Register Read to Write only Error Interrupt Status bit
    uint32_t slvif_commonreg_wronhold_err_intstat:1; ///< Register Bus Interface Common Register Write On Hold Error Interrupt Status Bit. This error occurs if an illegal write operation is performed on a common register; this happens if a write operation is performed on a common register except DMAC_RESETREG with DMAC_RST field set to 1 when DW_axi_dmac is in Hold mode
    uint32_t slvif_commonreg_addrparity_err_intstat:1; ///< Register Bus Interface Common Register Address Parity Error Interrupt Status Bit. This error occurs if address is used to do write/read operation to a register in the common register space, but the locally computed parity bits not matching the received parity bits.
    uint32_t slvif_commonreg_wrparity_err_intstat:1; ///< Register Bus Interface Common Register Write Parity Error Interrupt Status Bit. This error occurs if write operation with data and parity is performed to a register in the common register space, but the locally computed parity bits not matching the received parity bits.
    uint32_t slvif_undefinedreg_dec_err_intstat:1; ///< Register Bus Interface Undefined register Decode Error Interrupt Signal Enable Bit. Decode Error generated by DW_axi_dmac during register access. This error occurs if the register access is to undefined address range (>0x8FF if 8 channels are configured, >0x4FF if 4 channels are configured etc.) resulting in error response by DW_axi_dmac register bus interface
    uint32_t mxif1_rch0_prot_correrr_intstat:1; ///< AXI Manager Interface 1 Read Channel (Data) ECC Protection Correctable Error Interrupt Status bit. This error occurs if ECC Correctable error is detected on the AXI Channel Read Data payload.
    uint32_t mxif1_rch0_prot_uncorrerr_intstat:1; ///< AXI Manager Interface 1 Read Channel (Data) Parity/ECC Protection Uncorrectable Error Interrupt Status bit. This error occurs if Parity/ECC Uncorrectable error is detected on the AXI Channel Read Data payload.
    uint32_t mxif1_rch1_prot_correrr_intstat:1; ///< AXI Manager Interface 1 Read Channel (Other Control signals) ECC Protection Correctable Error Interrupt Status bit. This error occurs if ECC Correctable error is detected on the AXI Channel Read Control payload.
    uint32_t mxif1_rch1_prot_uncorrerr_intstat:1; ///< AXI Manager Interface 1 Read Channel (Other Control signals) Parity/ECC Protection Uncorrectable Error Interrupt Status bit. This error occurs if Parity/ECC Uncorrectable error is detected on the AXI Channel Read Control payload.
    uint32_t mxif1_bch_prot_correrr_intstat:1; ///< AXI Manager Interface 1 Write Response Channel ECC Protection Correctable Error Interrupt Status bit. This error occurs if ECC Correctable error is detected on the AXI Channel Write Response payload.
    uint32_t mxif1_bch_prot_uncorrerr_intstat:1; ///< AXI Manager Interface 2 Write Response Channel Parity/ECC Protection Uncorrectable Error Interrupt Status bit. This error occurs if Parity/ECC Uncorrectable error is detected on the AXI Channel Write Response payload.
    uint32_t mxif2_rch0_prot_correrr_intstat:1; ///< AXI Manager Interface 2 Read Channel (Data) ECC Protection Correctable Error Interrupt Status bit. This error occurs if ECC Correctable error is detected on the AXI Channel Read Data payload.
    uint32_t mxif2_rch0_prot_uncorrerr_intstat:1; ///< AXI Manager Interface 2 Read Channel (Data) Parity/ECC Protection Uncorrectable Error Interrupt Status bit. This error occurs if Parity/ECC Uncorrectable error is detected on the AXI Channel Read Data payload.
    uint32_t mxif2_rch1_prot_correrr_intstat:1; ///< AXI Manager Interface 2 Read Channel (Other Control signals) ECC Protection Correctable Error Interrupt Status bit. This error occurs if ECC Correctable error is detected on the AXI Channel Read Control payload.
    uint32_t mxif2_rch1_prot_uncorrerr_intstat:1; ///< AXI Manager Interface 1 Read Channel (Other Control signals) Parity/ECC Protection Uncorrectable Error Interrupt Status bit. This error occurs if Parity/ECC Uncorrectable error is detected on the AXI Channel Read Control payload.
    uint32_t mxif2_bch_prot_correrr_intstat:1; ///< AXI Manager Interface 2 Write Response Channel ECC Protection Correctable Error Interrupt Status bit. This error occurs if ECC Correctable error is detected on the AXI Channel Write Response payload.
    uint32_t mxif2_bch_prot_uncorrerr_intstat:1; ///< AXI Manager Interface 2 Write Response Channel Parity/ECC Protection Uncorrectable Error Interrupt Status bit. This error occurs if Parity/ECC Uncorrectable error is detected on the AXI Channel Write Response payload.
    uint32_t mxif1_arch_prot_arready_parerr_intstat:1; ///< AXI Manager Interface 1 Read Address Channel ARREADY Parity Protection Error Interrupt Status bit. This error occurs if ARREADY Parity error is detected on the Read Address AXI Channel.
    uint32_t mxif1_awch_prot_awready_parerr_intstat:1; ///< AXI Manager Interface 1 Write Address Channel AWREADY Parity Protection Error Interrupt Status bit. This error occurs if AWREADY Parity error is detected on the Write Address AXI Channel.
    uint32_t mxif1_wch_prot_wready_parerr_intstat:1; ///< AXI Manager Interface 1 Write Data Channel WREADY Parity Protection Error Interrupt Status bit. This error occurs if WREADY Parity error is detected on the Write Data AXI Channel.
    uint32_t mxif1_rch_prot_rvalid_parerr_intstat:1; ///< AXI Manager Interface 1 Read Data Channel RVALID Parity Protection Error Interrupt Status bit. This error occurs if RVALID Parity error is detected on the Read Data AXI Channel.
    uint32_t mxif1_bch_prot_bvalid_parerr_intstat:1; ///< AXI Manager Interface 1 Write Response Channel BVALID Parity Protection Error Interrupt Status bit. This error occurs if BVALID Parity error is detected on the Write Response AXI Channel.
    uint32_t mxif2_arch_prot_arready_parerr_intstat:1; ///< AXI Manager Interface 2 Read Address Channel ARREADY Parity Protection Error Interrupt Status bit. This error occurs if ARREADY Parity error is detected on the Read Address AXI Channel.
    uint32_t mxif2_awch_prot_awready_parerr_intstat:1; ///< AXI Manager Interface 2 Write Address Channel AWREADY Parity Protection Error Interrupt Status bit. This error occurs if AWREADY Parity error is detected on the Write Address AXI Channel.
    uint32_t mxif2_wch_prot_wready_parerr_intstat:1; ///< AXI Manager Interface 2 Write Data Channel WREADY Parity Protection Error Interrupt Status bit. This error occurs if WREADY Parity error is detected on the Write Data AXI Channel.
    uint32_t mxif2_rch_prot_rvalid_parerr_intstat:1; ///< AXI Manager Interface 2 Read Data Channel RVALID Parity Protection Error Interrupt Status bit. This error occurs if RVALID Parity error is detected on the Read Data AXI Channel.
    uint32_t mxif2_bch_prot_bvalid_parerr_intstat:1; ///< AXI Manager Interface 2 Write Response Channel BVALID Parity Protection Error Interrupt Status bit. This error occurs if BVALID Parity error is detected on the Write Response AXI Channel.
    uint32_t pad:3; ///< padding bits
} dma_common_reg_evt_bits_t;

/**
 * @brief DMA_COMMON_REG_EVT bit access and word access wrapper union
 */
typedef union {
    dma_common_reg_evt_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} dma_common_reg_evt_t;

/**
 * @brief DMA_CHANNEL_EVT bitfields access descriptor
 */
typedef struct {
    uint32_t src_dec_err_intstat:1; ///< Source Decode Error. Decode Error detected by Manager Interface during source data transfer. This error occurs if the access is to invalid address and a Decode Error is returned from interconnect/subordinate. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN bit corresponding to the channel which received the error is set to 0.
    uint32_t dst_dec_err_intstat:1; ///< Destination Decode Error. Decode Error detected by Manager Interface during destination data transfer. This error occurs if the access is to invalid address and a Decode Error is returned from interconnect/subordinate. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN bit corresponding to the channel which received the error is set to 0.
    uint32_t src_slv_err_intstat:1; ///< Source Subordinate Error. Subordinate Error detected by Manager Interface during source data transfer. This error occurs if the register bus interface from which the data is read issues a Subordinate Error. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN bit corresponding to the channel which received the error is set to 0.
    uint32_t dst_slv_err_intstat:1; ///< Destination Subordinate Error. Subordinate Error detected by Manager Interface during destination data transfer. This error occurs if the register bus interface to which the data is written issues a Subordinate Error. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN bit corresponding to the channel which received the error is set to 0.
    uint32_t lli_rd_dec_err_intstat:1; ///< LLI Read Decode Error. Decode Error detected by Manager Interface during LLI read operation. This error occurs if the access is to invalid address and a Decode Error is returned from interconnect/subordinate. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN1 bit which received the error is set to 0.
    uint32_t lli_wr_dec_err_intstat:1; ///< LLI WRITE Decode Error. Decode Error detected by Manager Interface during LLI write-back operation. This error occurs if the access is to invalid address and a Decode Error is returned from interconnect/subordinate. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN1 bit which received the error is set to 0.
    uint32_t lli_rd_slv_err_intstat:1; ///< LLI Read Subordinate Error. Subordinate Error detected by Manager Interface during LLI read operation. This error occurs if the register bus interface on which LLI resides issues a Subordinate Error. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN1 bit which received the error is set to 0.
    uint32_t lli_wr_slv_err_intstat:1; ///< LLI WRITE Subordinate Error. Subordinate Error detected by Manager Interface during LLI write-back operation. This error occurs if the register bus interface on which LLI resides issues a Subordinate Error. This error condition causes the DW_axi_dmac to disable the corresponding channel gracefully; the DMAC_ChEnReg.CH_EN1 bit which received the error is set to 0.
    uint32_t shadowreg_or_lli_invalid_err_intstat:1; ///< Shadow register or LLI Invalid Error.This error occurs if CHx_CTL.ShadowReg_Or_LLI_Valid bit is seen to be 0 during DW_axi_dmac Shadow Register / LLI fetch phase.
    uint32_t slvif_multiblktype_err_intstat:1; ///< Register Bus Interface Multi Block type Error. This error occurs if multi-block transfer type programmed in CHx_CFG register (SRC_MLTBLK_TYPE and DST_MLTBLK_TYPE) is invalid.
    uint32_t slvif_dec_err_intstat:1; ///< Register Bus Interface Decode Error. Decode Error generated by DW_axi_dmac during register access. This error occurs if the register access is to invalid address in Channelx register space resulting in error response by DW_axi_dmac register bus interface.
    uint32_t slvif_wr2ro_err_intstat:1; ///< Register Bus Interface Write to Read Only Error. This error occurs if write operation is performed to a Read Only register.
    uint32_t slvif_rd2rwo_err_intstat:1; ///< Register Bus Interface Read to write Only Error. This error occurs if read operation is performed to a Write Only register.
    uint32_t slvif_wronchen_err_intstat:1; ///< Register Bus Interface Write On Channel Enabled Error. This error occurs if an illegal write operation is performed on a register; this happens if a write operation is performed on a register when the channel is enabled and if it is not allowed for the corresponding register as per the DW_axi_dmac specification.
    uint32_t slvif_shadowreg_wron_valid_err_intstat:1; ///< Shadow Register Write On Valid Error. This error occurs if shadow register based multi-block transfer is enabled and software tries to write to the shadow register when CHx_CTL.ShadowReg_Or_LLI_Valid bit is 1.
    uint32_t slvif_wronhold_err_intstat:1; ///< Register Bus Interface Write On Hold Error. This error occurs if an illegal write operation is performed on a register; this happens if a write operation is performed on a channel register when DW_axi_dmac is in Hold mode.
    uint32_t slvif_addrparity_err_intstat:1; ///< Register Bus Interface Address Parity Error. This error occurs if address is used to do write/read operation on a channel register; But the Address fails the even/odd parity check.
    uint32_t slvif_wrparity_err_intstat:1; ///< Register Bus Interface Write Parity Error. This error occurs if a Write operation is performed on a channel register; But the Write data fails the even/odd parity check.
    uint32_t ecc_prot_chmem_correrr_intstat:1; ///< Channel x FIFO Memory Interface ECC Protection related Correctable Error Interrupt Status bit. This error occurs if ECC correctable error is detected on the FIFO Memory Interface data.
    uint32_t ecc_prot_chmem_uncorrerr_intstat:1; ///< Channel x FIFO Memory Interface ECC Protection related Uncorrectable Error Interrupt Status bit. This error occurs if ECC Uncorrectable error is detected on the FIFO Memory Interface data.
    uint32_t ecc_prot_uidmem_correrr_intstat:1; ///< Channel x UID Memory Interface ECC Protection related Correctable Error Interrupt Status bit. This error occurs if ECC correctable error is detected on the UID Memory Interface data.
    uint32_t ecc_prot_uidmem_uncorrerr_intstat:1; ///< Channel x UID Memory Interface ECC Protection related Uncorrectable Error Interrupt Status bit. This error occurs if ECC Uncorrectable error is detected on the UID Memory Interface data.
    uint32_t chan_tx_src_valid:1; ///< chan_tx_src field data valid
    uint32_t chan_tx_dst_valid:1; ///< chan_tx_dst field data valid
    uint32_t chan_tx_data_valid:1; ///< chan_tx_data field data valid
    uint32_t pad:7; ///< padding bits
} dma_channel_evt_bits_t;

/**
 * @brief DMA_CHANNEL_EVT bit access and word access wrapper union
 */
typedef union {
    dma_channel_evt_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} dma_channel_evt_t;

/**
 * @brief DMA_CHAN_TX_DATA bitfields access descriptor
 */
typedef struct {
    uint32_t data_left_in_fifo:14; ///< The data left in the FIFO status indicates the total number of data left in the channel FIFO after an AXI Transfer Error response (SLVERR or DECERR) reception or a Channel Terminate
    uint32_t data_length:3; ///< Width of data per transfer
    uint32_t pad:15; ///< padding bits
} dma_chan_tx_data_bits_t;

/**
 * @brief DMA_CHAN_TX_DATA bit access and word access wrapper union
 */
typedef union {
    dma_chan_tx_data_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} dma_chan_tx_data_t;

/**
 * @brief dma CPER section data description
 */
typedef struct {
    uint32_t evt_source; ///< Source of the DMA event
    dma_common_reg_evt_t common_reg_evt; ///< Common registers event data
    dma_channel_evt_t channel_evt; ///< Channel event data
    uint32_t chan_tx_src_lo; ///< Source address of the transfer (lower bits)
    uint32_t chan_tx_src_hi; ///< Source address of the transfer (higher bits)
    uint32_t chan_tx_dst_lo; ///< Destination address of the transfer (lower bits)
    uint32_t chan_tx_dst_hi; ///< Destination address of the transfer (higher bits)
    dma_chan_tx_data_t chan_tx_data; ///< Transfer status
} dma_section_t;

/*********************************************
* TVS_MON CPER Section
********************************************/

#define TVS_MON_EVENT_NO_EVENT 0UL ///< No event
#define TVS_MON_EVENT_TEMP_ABOVE_THRES 1UL ///< Temperature reading above maximum threshold

/**
 * @brief tvs_mon CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event reported by the temperature monitor
    uint16_t tvs_val_vdd; ///< Current converted VDD value extracted by the monitor
    uint16_t tvs_val_vdd18; ///< Current converted VDD 1.8 value extracted by the monitor
    uint16_t tvs_val_adc; ///< Current converted ADC value extracted by the monitor
    uint16_t tvs_val_temp; ///< Current converted temperature value extracted by the monitor
} tvs_mon_section_t;

/*********************************************
* RISCV_PROC CPER Section
********************************************/

#define RISCV_PROC_CACHE_ERR_SOURCE_IDENTIFIER_CORRECTED 0UL ///< Corrected
#define RISCV_PROC_CACHE_ERR_SOURCE_IDENTIFIER_UNCORRECTED 1UL ///< Uncorrected
#define RISCV_PROC_CACHE_ERR_SOURCE_IDENTIFIER_PRODUCED_CORRUPT 2UL ///< Produced corrupt
#define RISCV_PROC_CACHE_ERR_SOURCE_IDENTIFIER_TLB_CORRECTED 3UL ///< TLB corrected
#define RISCV_PROC_CACHE_ERR_SOURCE_IDENTIFIER_NO_RECORDS 4UL ///< No records
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LEVEL_NA 0UL ///< Not applicable
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LEVEL_1 1UL ///< Level 1
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LEVEL_2 2UL ///< Level 2
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LEVEL_3 3UL ///< Level 3
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_TYPE_NA 0UL ///< Not applicable
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_TYPE_INSTRUCTION_CACHE 1UL ///< Instruction cache
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_TYPE_DATA_CACHE 2UL ///< Data cache
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LINE_COMP_NOT_AVAILABLE 0UL ///< Not available
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LINE_COMP_TAG 1UL ///< Tag
#define RISCV_PROC_CACHE_ERR_SOURCE_CACHE_LINE_COMP_DATA 2UL ///< Data
#define RISCV_PROC_CACHE_ERR_SOURCE_SUPP_DATA_TYPE_NONE 0UL ///< None
#define RISCV_PROC_CACHE_ERR_SOURCE_SUPP_DATA_TYPE_SYSTEM_ADDRESS 1UL ///< System Address associated with the error event
#define RISCV_PROC_CACHE_ERR_SOURCE_SUPP_DATA_TYPE_SYSTEM_ADDRESS_CACHE_TARGET 2UL ///< [63:14] - System Address[57:6] (e.g., Cache line address) associated with the error event
#define RISCV_PROC_CACHE_ERR_SOURCE_SUPP_DATA_TYPE_CACHE_SET 3UL ///< Cache Set[31:8]/Way[40:32]/Bank[63:48]
#define RISCV_PROC_BUS_ERROR_SOURCE_REPORTER_NOT_AVAILABLE 0UL ///< Not available
#define RISCV_PROC_BUS_ERROR_SOURCE_REPORTER_TILELINK_BUS 1UL ///< Tilelink bus
#define RISCV_PROC_BUS_ERROR_SOURCE_REPORTER_CXL_CPI_MEM_INTERFACE 2UL ///< CXL CPI mem interface
#define RISCV_PROC_BUS_ERROR_SOURCE_REPORTER_CXL_CPI_CACHE_INTERFACE 3UL ///< CXL CPI cache interface
#define RISCV_PROC_BUS_ERROR_SOURCE_REPORTER_WORLDGUARD_CHECKER 4UL ///< Worldguard checker
#define RISCV_PROC_BUS_ERROR_SOURCE_REPORTER_BEU 5UL ///< Bus Error Unit
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_PRODUCED_CORRUPT 0UL ///< Produced corrupt
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_CORRUPT_DETECTION 1UL ///< Corrupt detection
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_ACCESS_DENIED 2UL ///< Access denied
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_BUFFER_CORRECTED 3UL ///< Buffer corrected
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_READ_ERROR 4UL ///< Read error
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_WRITE_ERROR 5UL ///< Write error
#define RISCV_PROC_BUS_ERROR_SOURCE_TYPE_LOAD_STORE_ERR 6UL ///< Load/store error
#define RISCV_PROC_BUS_ERROR_SOURCE_TX_ORIGINATOR_NOT_AVAILABLE 0UL ///< Not available
#define RISCV_PROC_BUS_ERROR_SOURCE_TX_ORIGINATOR_L1_I_CACHE 1UL ///< L1 I-cache
#define RISCV_PROC_BUS_ERROR_SOURCE_TX_ORIGINATOR_L1_D_CACHE 2UL ///< L1 D-cache
#define RISCV_PROC_BUS_ERROR_SOURCE_TX_ORIGINATOR_L2_CACHE 3UL ///< L2 cache
#define RISCV_PROC_BUS_ERROR_SOURCE_TX_ORIGINATOR_L3_CACHE 4UL ///< L3 cache
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_NONE 0UL ///< None
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_SLICE_WGCHECKER_0 1UL ///< Extensible Cache Slice wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_0 2UL ///< Extensible Cache
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_SLICE_WGCHECKER_1 3UL ///< Extensible Cache Slice wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_1 4UL ///< Extensible Cache
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_SLICE_WGCHECKER_2 5UL ///< Extensible Cache Slice wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_2 6UL ///< Extensible Cache
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_SLICE_WGCHECKER_3 7UL ///< Extensible Cache Slice wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_EXTENSIBLE_CACHE_3 8UL ///< Extensible Cache
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TL2C_TO_CXL_MEM_BRIDGE_WGCHECKER 9UL ///< TL2c to CXL.mem Bridge wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TL2C_TO_CXL_CACHE_BRIDGE_WGCHECKER 10UL ///< TL2c to CXL.cache Bridge wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_CXL_CACHE_TO_TL2C_BRIDGE_WGCHECKER 11UL ///< CXL.cache to TL2c Bridge wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_SMC_WGCHECKER 12UL ///< SMC wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_ROOT_ERROR_MAPPING_WGCHECKER 13UL ///< Root Error Mapping wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_APLIC_WGCHECKER 21UL ///< APLIC wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_CLINT_WGCHECKER 22UL ///< CLINT wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_M_MODE_0_WGCHECKER 23UL ///< IMSIC M-Mode 0 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_S_MODE_0_WGCHECKER 24UL ///< IMSIC S-Mode 0 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_M_MODE_1_WGCHECKER 25UL ///< IMSIC M-Mode 1 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_S_MODE_1_WGCHECKER 26UL ///< IMSIC S-Mode 1 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_M_MODE_2_WGCHECKER 27UL ///< IMSIC M-Mode 2 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_S_MODE_2_WGCHECKER 28UL ///< IMSIC S-Mode 2 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_M_MODE_3_WGCHECKER 29UL ///< IMSIC M-Mode 3 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_IMSIC_S_MODE_3_WGCHECKER 30UL ///< IMSIC S-Mode 3 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TMC_0_WGCHECKER 31UL ///< TMC 0 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TILE_0_WGCHECKER 32UL ///< Tile 0 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TMC_1_WGCHECKER 33UL ///< TMC 1 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TILE_1_WGCHECKER 34UL ///< Tile 1 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TMC_2_WGCHECKER 35UL ///< TMC 2 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TILE_2_WGCHECKER 36UL ///< Tile 2 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TMC_3_WGCHECKER 37UL ///< TMC 3 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TILE_3_WGCHECKER 38UL ///< Tile 3 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_MEM_DEINTERLEAVER_EB_WGCHECKER 39UL ///< Mem Deinterleaver Error Bank wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_SYS_DEINTERLEAVER_EB_WGCHECKER 40UL ///< Sys Deinterleaver Error Bank wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_WRITE_COMB_BUF_WGCHECKER 41UL ///< Write Combining Buffer wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_CXL_MEM_TO_CPI_WGCHECKER 42UL ///< CXL.mem to CPI wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_CXL_CACHE_TO_CPI_WGCHECKER 43UL ///< CXL.cache to CPI wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_FRONT_PORT_CACHE_WGCHECKER 44UL ///< Front Port Cache wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_WRITE_COMBINING_BUFFER_WGCHECKER 45UL ///< Write Combining Buffer wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_FRONT_PORT_CACHE 46UL ///< Front Port Cache
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_CXL_MEM_FROM_CPI_WGCHECKER 47UL ///< CXL.mem from CPI wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_CXL_CACHE_FROM_CPI_WGCHECKER 48UL ///< CXL.cache from CPI wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TRACE_ENCODER_0_WGCHECKER 49UL ///< Trace Encoder 0 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TRACE_ENCODER_1_WGCHECKER 50UL ///< Trace Encoder 1 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TRACE_ENCODER_2_WGCHECKER 51UL ///< Trace Encoder 2 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TRACE_ENCODER_3_WGCHECKER 52UL ///< Trace Encoder 3 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TRACE_FUNNEL_0_WGCHECKER 53UL ///< Trace Funnel 0 wgChecker
#define RISCV_PROC_BUS_ERROR_WGC_ERR_WGC_ID_TEST_INDICATOR_WGCHECKER 54UL ///< Test Indicator wgChecker
#define RISCV_PROC_MAS_ERROR_SOURCE_ERR_TYPE_DATA_CORRECTED 0UL ///< Data corrected
#define RISCV_PROC_MAS_ERROR_SOURCE_ERR_TYPE_DATA_UNCORRECTED 1UL ///< Data uncorrected
#define RISCV_PROC_MAS_ERROR_SOURCE_ACCESS_NOT_AVAILABLE 0UL ///< Not available
#define RISCV_PROC_MAS_ERROR_SOURCE_ACCESS_READ 1UL ///< Read
#define RISCV_PROC_MAS_ERROR_SOURCE_ACCESS_WRITE 2UL ///< Write
#define RISCV_PROC_MAS_ERROR_SOURCE_SUPP_DATA_TYPE_NONE 0UL ///< None
#define RISCV_PROC_MAS_ERROR_SOURCE_SUPP_DATA_TYPE_SYSTEM_ADDRESS 1UL ///< System address causing the error
#define RISCV_PROC_MAS_ERROR_SOURCE_SUPP_DATA_TYPE_AXI_RESP_ID 2UL ///< [16:8] - The ResponseID of the transaction that encountered the error
#define RISCV_PROC_MAS_ERROR_RESOURCE_ID_GHRT 0UL ///< GHRT
#define RISCV_PROC_MAS_ERROR_RESOURCE_ID_DATA_LOCAL_STORE 1UL ///< Data local store
#define RISCV_PROC_MAS_ERROR_RESOURCE_ID_AXI_DEINTERLEAVER 2UL ///< AXI deinterleaver
#define RISCV_PROC_MAS_ERROR_RESOURCE_ID_DTIM 3UL ///< Data Tightly Integrated Memory
#define RISCV_PROC_MAS_ERROR_RESOURCE_ID_ITIM 4UL ///< Instruction Tightly Integrated Memory
#define RISCV_PROC_IOMMU_SOURCE_SEQUENCE_NOT_APPLICABLE 0UL ///< Not applicable
#define RISCV_PROC_IOMMU_SOURCE_SEQUENCE_TLB_SEARCH 1UL ///< TLB search
#define RISCV_PROC_IOMMU_SOURCE_SEQUENCE_PAGE_TABLE_WALK 2UL ///< Page table walk
#define RISCV_PROC_IOMMU_SOURCE_ERROR_TYPE_CORRECTED 0UL ///< Corrected
#define RISCV_PROC_IOMMU_SOURCE_ERROR_TYPE_UNCORRECTED 1UL ///< Uncorrected
#define RISCV_PROC_IOMMU_SOURCE_SUPP_DATA_TYPE_NONE 0UL ///< None
#define RISCV_PROC_IOMMU_SOURCE_SUPP_DATA_TYPE_IOMMU_ERR_SRC 1UL ///< [31:12] - Process ID, if any. [32] - PV When set, the transaction carries a valid ProcessID. [33] PRIV Privilege of the transaction (1 if Supervisor). [39:34] TTYP Reports the inbound transaction type which encountered the error. If TTYP==0, the error happened on the execution of the command. [63:40] - DID The DeviceID of the transaction
#define RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP_UNEXPECTED_INTERRUPT_NO_UNEXCPT_INTR_RCV 0UL ///< No unexpected interrupt received
#define RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP_UNEXPECTED_INTERRUPT_UNEXCPT_INTR_RCV 1UL ///< Unexpected interrupt received
#define RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP_SOURCE_INTERRUPT 0UL ///< Interrupt
#define RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP_SOURCE_MACHINE_TRAP 1UL ///< Machine Trap
#define RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP_SOURCE_RNMI_TRAP 2UL ///< RNMI Trap
#define RISCV_PROC_PROC_ISA_RISCV_RV32 0UL ///< RISCV RV32
#define RISCV_PROC_PROC_ISA_RISCV_RV64 1UL ///< RISCV RV64
#define RISCV_PROC_ERROR_TYPE_CACHE 0UL ///< Cache error
#define RISCV_PROC_ERROR_TYPE_BUS 1UL ///< Bus error
#define RISCV_PROC_ERROR_TYPE_MICRO_ARCHITECTURE_SPECIFIC 2UL ///< Micro-architecture specific error
#define RISCV_PROC_ERROR_TYPE_PROCESSOR_STATE_EVENT 3UL ///< Processor state event
#define RISCV_PROC_ERROR_TYPE_LOCKSTEP 4UL ///< Lockstep error
#define RISCV_PROC_ERROR_TYPE_IOMMU 5UL ///< IOMMU error
#define RISCV_PROC_ERROR_TYPE_INSTRUCTION_EXCEPTION 6UL ///< Instruction exceptions

/**
 * @brief RISCV_PROC_LOCKSTEP_ERR data description
 */
typedef struct {
    uint32_t mismatch_ls_mask; ///< Bitmask of locksteps for which a comparator mismatch event has been reported
    uint32_t error_ls_mask; ///< Bitmask of locksteps for which a comparator error event has been reported
} riscv_proc_lockstep_err_t;

/**
 * @brief RISCV_PROC_STATE data description
 */
typedef struct {
    uint32_t cease_hart_mask_lo; ///< Lower bitmask of harts for which the CEASE state event has been reported
    uint32_t cease_hart_mask_hi; ///< Higher bitmask of harts for which the CEASE state event has been reported
    uint32_t halt_hart_mask_lo; ///< Lower bitmask of harts for which the HALT state event has been reported
    uint32_t halt_hart_mask_hi; ///< Higher bitmask of harts for which the HALT state event has been reported
    uint32_t wfi_hart_mask_lo; ///< Lower bitmask of harts for which the WFI state event has been reported
    uint32_t wfi_hart_mask_hi; ///< Higher bitmask of harts for which the WFI state event has been reported
    uint32_t debug_hart_mask_lo; ///< Lower bitmask of harts for which the DEBUG state event has been reported
    uint32_t debug_hart_mask_hi; ///< Higher bitmask of harts for which the DEBUG state event has been reported
} riscv_proc_state_t;

/**
 * @brief RISCV_PROC_CACHE_ERR_SOURCE bitfields access descriptor
 */
typedef struct {
    uint32_t identifier:2; ///< Identifier to specify type of error
    uint32_t cache_level:2; ///< Cache level
    uint32_t cache_type:2; ///< Cache type
    uint32_t cache_line_comp:2; ///< Component of the cache line at the source of the error
    uint32_t supp_data_type:2; ///< Supplementary error data available
    uint32_t pad:22; ///< padding bits
} riscv_proc_cache_err_source_bits_t;

/**
 * @brief RISCV_PROC_CACHE_ERR_SOURCE bit access and word access wrapper union
 */
typedef union {
    riscv_proc_cache_err_source_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} riscv_proc_cache_err_source_t;

/**
 * @brief RISCV_PROC_CACHE_ERR data description
 */
typedef struct {
    riscv_proc_cache_err_source_t source; ///< Cache error source information
    uint32_t supplementary_lo; ///< Supplementary data lower bits
    uint32_t supplementary_hi; ///< Supplementary data higher bits
} riscv_proc_cache_err_t;

/**
 * @brief RISCV_PROC_BUS_ERROR_SOURCE bitfields access descriptor
 */
typedef struct {
    uint32_t reporter:8; ///< Bus resource reporting the error
    uint32_t type:8; ///< Bus error type
    uint32_t tx_originator:16; ///< Processor block which originated the transaction
} riscv_proc_bus_error_source_bits_t;

/**
 * @brief RISCV_PROC_BUS_ERROR_SOURCE bit access and word access wrapper union
 */
typedef union {
    riscv_proc_bus_error_source_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} riscv_proc_bus_error_source_t;

/**
 * @brief RISCV_PROC_BUS_ERROR_WGC_ERR bitfields access descriptor
 */
typedef struct {
    uint32_t wgc_id:6; ///< WGC identifier
    uint32_t wid_value:5; ///< WID of the transaction at fault
    uint32_t pad:21; ///< padding bits
} riscv_proc_bus_error_wgc_err_bits_t;

/**
 * @brief RISCV_PROC_BUS_ERROR_WGC_ERR bit access and word access wrapper union
 */
typedef union {
    riscv_proc_bus_error_wgc_err_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} riscv_proc_bus_error_wgc_err_t;

/**
 * @brief RISCV_PROC_BUS_ERROR data description
 */
typedef struct {
    riscv_proc_bus_error_source_t source; ///< Bus error source information
    riscv_proc_bus_error_wgc_err_t wgc_err; ///< WGC error data
    uint32_t tx_target_addr_lo; ///< Lower bits of transaction target address causing fault
    uint32_t tx_target_addr_hi; ///< Higher bits of transaction target address causing fault
} riscv_proc_bus_error_t;

/**
 * @brief RISCV_PROC_MAS_ERROR_SOURCE bitfields access descriptor
 */
typedef struct {
    uint32_t err_type:16; ///< Error type
    uint32_t access:8; ///< Access type
    uint32_t supp_data_type:8; ///< Supplementary error data available
} riscv_proc_mas_error_source_bits_t;

/**
 * @brief RISCV_PROC_MAS_ERROR_SOURCE bit access and word access wrapper union
 */
typedef union {
    riscv_proc_mas_error_source_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} riscv_proc_mas_error_source_t;

/**
 * @brief RISCV_PROC_MAS_ERROR data description
 */
typedef struct {
    riscv_proc_mas_error_source_t source; ///< Micro-Architecture hardware source information
    uint32_t resource_id; ///< Identifier of the resource accessed
    uint32_t supplementary_lo; ///< Supplementary data lower bits
    uint32_t supplementary_hi; ///< Supplementary data higher bits
} riscv_proc_mas_error_t;

/**
 * @brief RISCV_PROC_IOMMU_SOURCE bitfields access descriptor
 */
typedef struct {
    uint32_t sequence:2; ///< IOMMU action sequence causing fault
    uint32_t error_type:1; ///< Type of error encountered during IOMMU action sequence
    uint32_t supp_data_type:1; ///< Supplementary error data available
    uint32_t pad:28; ///< padding bits
} riscv_proc_iommu_source_bits_t;

/**
 * @brief RISCV_PROC_IOMMU_SOURCE bit access and word access wrapper union
 */
typedef union {
    riscv_proc_iommu_source_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} riscv_proc_iommu_source_t;

/**
 * @brief RISCV_PROC_IOMMU data description
 */
typedef struct {
    riscv_proc_iommu_source_t source; ///< IOMMU error source information
    uint32_t supplementary_lo; ///< Supplementary data lower bits
    uint32_t supplementary_hi; ///< Supplementary data higher bits
} riscv_proc_iommu_t;

/**
 * @brief RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP bitfields access descriptor
 */
typedef struct {
    uint32_t unexpected_interrupt:1; ///< Indicator for an unexpected interrupt received
    uint32_t source:2; ///< Source of the exception trap
    uint32_t pad:29; ///< padding bits
} riscv_proc_instruction_exception_trap_bits_t;

/**
 * @brief RISCV_PROC_INSTRUCTION_EXCEPTION_TRAP bit access and word access wrapper union
 */
typedef union {
    riscv_proc_instruction_exception_trap_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} riscv_proc_instruction_exception_trap_t;

/**
 * @brief RISCV_PROC_INSTRUCTION_EXCEPTION data description
 */
typedef struct {
    riscv_proc_instruction_exception_trap_t trap; ///< Information about trap
    uint32_t cause_lo; ///< Value of lower bits of MCAUSE register for machine trap and MNCAUSE for RNMI trap
    uint32_t cause_hi; ///< Value of higher bits of MCAUSE register for machine trap and MNCAUSE for RNMI trap
    uint32_t mtval_lo; ///< Lower bits of problematic address if mcause is a store/load fault
    uint32_t mtval_hi; ///< Higher bits of problematic address if mcause is a store/load fault
    uint32_t mepc_lo; ///< Lower bits of program counter where exception occurred
    uint32_t mepc_hi; ///< Higher bits of program counter where exception occurred
} riscv_proc_instruction_exception_t;

/**
 * @brief RISCV_PROC payload data
 */
typedef union {
    riscv_proc_lockstep_err_t lockstep_err; ///< Lockstep error event information
    riscv_proc_state_t state; ///< RISCV processor state
    riscv_proc_cache_err_t cache_err; ///< Cache error event information
    riscv_proc_bus_error_t bus_error; ///< Processor internal bus error
    riscv_proc_mas_error_t mas_error; ///< Error related to the access of a resource within the processor micro-architecture
    riscv_proc_iommu_t iommu; ///< IOMMU error data
    riscv_proc_instruction_exception_t instruction_exception; ///< Exception trap caused by an instruction
} riscv_proc_payload_t;

/**
 * @brief riscv_proc CPER section data description
 */
typedef struct {
    uint32_t harts; ///< Number of harts in the processor
    uint32_t arch_id_lo; ///< Lower bits of machine architecture ID value
    uint32_t arch_id_hi; ///< Higher bits of machine architecture ID value
    uint16_t proc_isa; ///< Processor ISA
    uint16_t error_type; ///< Operation causing fault
    riscv_proc_payload_t payload; ///< Data payload
} riscv_proc_section_t;

/*********************************************
* APP_NOC CPER Section
********************************************/

#define APP_NOC_EVENT_NO_EVENT 0UL ///< No event
#define APP_NOC_EVENT_WORLDGUARD_ERROR_EVENT 1UL ///< Worldguard error event
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_EP_CFG 0UL ///< enet ep cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_SWR_RDMA1_MCHP_CFG 1UL ///< enet swr rdma1 mchp cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_SWR_RDMA1_ROCE_COMMAND 2UL ///< enet swr rdma1 roce command WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_SWR_RDMA2_MCHP_CFG 3UL ///< enet swr rdma2 mchp cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_SWR_RDMA2_ROCE_COMMAND 4UL ///< enet swr rdma2 roce command WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_SWR_SWITCH_CFG 5UL ///< enet swr switch cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_ENET_SWR_TOP_CFG 6UL ///< enet swr top cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_DDR_CFG 7UL ///< ddr cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M2_HP_SPW_CSR 8UL ///< m2 hp spw csr WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M2_JTAG_SPI 9UL ///< m2 jtag spi WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M2_OTHER_0 10UL ///< m2 other 0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M2_OTHER_1 11UL ///< m2 other 1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_APPDMA0_HP_CSR 12UL ///< m3 appdma0 hp csr WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_APPDMA1_HP_CSR 13UL ///< m3 appdma1 hp csr WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_NMRA0_T 14UL ///< m3 nmra0 t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_NMRA1_T 15UL ///< m3 nmra1 t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_OCR0_MEM 16UL ///< m3 ocr0 mem WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_OCR1_MEM 17UL ///< m3 ocr1 mem WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_OTHER 18UL ///< m3 other WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_IPC_0 19UL ///< m3 ipc 0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_M3_IPC_1 20UL ///< m3 ipc 1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_DDR_ENCRYPT_HP_CSR 21UL ///< ddr encrypt hp csr WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_DDR_ENCRYPT_T 22UL ///< ddr encrypt t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_USER_CRYPTO_CFG 23UL ///< user crypto cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_USER_CRYPTO_T 24UL ///< user crypto t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_EDAC0 25UL ///< nvm edac0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_EDAC1 26UL ///< nvm edac1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SRAM_EDAC0_0 27UL ///< nvm sram edac0 0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SRAM_EDAC0_1 28UL ///< nvm sram edac0 1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SRAM_EDAC1_0 29UL ///< nvm sram edac1 0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SRAM_EDAC1_1 30UL ///< nvm sram edac1 1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SRAM_EDAC2_0 31UL ///< nvm sram edac2 0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SRAM_EDAC2_1 32UL ///< nvm sram edac2 1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_NVM_SS_CFG 33UL ///< nvm ss cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_IOMMU_0_CFG 34UL ///< iommu 0 cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_IOMMU_1_CFG 35UL ///< iommu 1 cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_IOMMU_SS_CFG 36UL ///< iommu ss cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_PCIE0_CFG 37UL ///< pcie0 cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_PCIE0_CTL0_T 38UL ///< pcie0 ctl0 t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_PCIE0_CTL1_T 39UL ///< pcie0 ctl1 t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_PCIE1_CFG 40UL ///< pcie1 cfg WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_PCIE1_CTL0_T 41UL ///< pcie1 ctl0 t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_PCIE1_CTL1_T 42UL ///< pcie1 ctl1 t WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_WG_ERR_0 43UL ///< wg err 0 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_WG_ERR_1 44UL ///< wg err 1 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_WG_ERR_2 45UL ///< wg err 2 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_WG_ERR_3 46UL ///< wg err 3 WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_WG_WID_DED 47UL ///< wg wid ded WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_WG_WID_SEC 48UL ///< wg wid sec WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_SVC_NOC_EDAC 49UL ///< svc noc edac WGC
#define APP_NOC_WG_ERR_INFO_WGC_ID_INT_AGG 55UL ///< Interrupt Aggregator wgChecker
#define APP_NOC_WG_ERR_INFO_ACCESS_TYPE_READ ACCESS 0UL ///< Read access
#define APP_NOC_WG_ERR_INFO_ACCESS_TYPE_WRITE ACCESS 1UL ///< Write access

/**
 * @brief APP_NOC_WG_ERR_INFO bitfields access descriptor
 */
typedef struct {
    uint32_t wgc_id:6; ///< WGC identifier
    uint32_t wid_value:5; ///< WID of the transaction at fault
    uint32_t access_type:1; ///< WGC access type causing fault
    uint32_t pad:20; ///< padding bits
} app_noc_wg_err_info_bits_t;

/**
 * @brief APP_NOC_WG_ERR_INFO bit access and word access wrapper union
 */
typedef union {
    app_noc_wg_err_info_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} app_noc_wg_err_info_t;

/**
 * @brief app_noc CPER section data description
 */
typedef struct {
    uint32_t event; ///< AppNoC event type
    app_noc_wg_err_info_t wg_err_info; ///< WGC error data
    uint32_t wg_err_addr_lo; ///< Lower bits of target address of the transaction causing fault in a slot
    uint32_t wg_err_addr_hi; ///< Higher bits of target address of the transaction causing fault in a slot
} app_noc_section_t;

/*********************************************
* APP_WDOG CPER Section
********************************************/

#define APP_WDOG_RESET_TYPE_RESET_PENDING 0UL ///< reset pending
#define APP_WDOG_RESET_TYPE_RESET_REQUEST 1UL ///< reset request

/**
 * @brief app_wdog CPER section data description
 */
typedef struct {
    uint8_t reset_type; ///< appc watch dog reset type, pending or request
    uint8_t index; ///< index, 0-7
} app_wdog_section_t;

/*********************************************
* SRAM_EDAC CPER Section
********************************************/

#define SRAM_EDAC_EVENT_NO_EVENT 0UL ///< No Event
#define SRAM_EDAC_EVENT_DMR_CORR 1UL ///< DMR correctable error
#define SRAM_EDAC_EVENT_DMR_UNCORR 2UL ///< DMR uncorrectable error
#define SRAM_EDAC_EVENT_RD_TIMEOUT 3UL ///< Read command or data channel timeout
#define SRAM_EDAC_EVENT_WR_TIMEOUT 4UL ///< Write command or data channel timeout
#define SRAM_EDAC_EVENT_TRANS_DROP 5UL ///< Transaction dropped due to uncorrectable error
#define SRAM_EDAC_EVENT_FAULT_CORR 6UL ///< SECDEC AXI bus protection correctable error
#define SRAM_EDAC_EVENT_FAULT 7UL ///< EDAC fault occurred
#define SRAM_EDAC_EVENT_RAM_CORR 8UL ///< RAM correctable error
#define SRAM_EDAC_EVENT_RAM_UNCORR 9UL ///< RAM uncorrectable error
#define SRAM_EDAC_EVENT_EMON_CORR 10UL ///< EMON correctable error
#define SRAM_EDAC_EVENT_EMON_UNCORR 11UL ///< EMON uncorrectable error
#define SRAM_EDAC_EVENT_APP 12UL ///< Errors with AXI BIST or Patrol Scrub completion
#define SRAM_EDAC_SRAM_EDAC_IDX_INST_0 0UL ///< NVM SRAM EDAC INST 0
#define SRAM_EDAC_SRAM_EDAC_IDX_INST_1 1UL ///< NVM SRAM EDAC INST 1
#define SRAM_EDAC_SRAM_EDAC_IDX_INST_2 2UL ///< NVM SRAM EDAC INST 2
#define SRAM_EDAC_SRAM_EDAC_IDX_INST_3 3UL ///< SYSC SRAM EDAC INST 0
#define SRAM_EDAC_EDAC_IDX_INST_0 0UL ///< EDAC INST 0
#define SRAM_EDAC_EDAC_IDX_INST_1 1UL ///< EDAC INST 1
#define SRAM_EDAC_EDAC_IDX_NO_INST 2UL ///< No EDAC INST

/**
 * @brief sram_edac CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t sram_edac_idx; ///< SRAM EDAC instance identifier
    uint8_t edac_idx; ///< EDAC instance identifier
    uint32_t emon_loc_cor_0; ///< Locations corrected LSB 0 - 31
    uint32_t emon_loc_cor_1; ///< Locations corrected MSB 32 - 63
    uint32_t emon_loc_uncor; ///< Decoders that have generated uncorrectable decodes
    uint32_t ram_corr; ///< Correctable Memory location addresses
    uint32_t ram_uncorr; ///< Uncorrectable Memory location addresses
} sram_edac_section_t;

/*********************************************
* NVM_EDAC CPER Section
********************************************/

#define NVM_EDAC_EVENT_NO_EVENT 0UL ///< No Event
#define NVM_EDAC_EVENT_DMR_CORR 1UL ///< DMR correctable error
#define NVM_EDAC_EVENT_DMR_UNCORR 2UL ///< DMR uncorrectable error
#define NVM_EDAC_EVENT_RD_TIMEOUT 3UL ///< Read command or data channel timeout
#define NVM_EDAC_EVENT_WR_TIMEOUT 4UL ///< Write command or data channel timeout
#define NVM_EDAC_EVENT_TRANS_DROP 5UL ///< Transaction dropped due to uncorrectable error
#define NVM_EDAC_EVENT_FAULT_CORR 6UL ///< SECDEC AXI bus protection correctable error
#define NVM_EDAC_EVENT_FAULT 7UL ///< EDAC fault occurred
#define NVM_EDAC_EVENT_RAM_CORR 8UL ///< RAM correctable error
#define NVM_EDAC_EVENT_RAM_UNCORR 9UL ///< RAM uncorrectable error
#define NVM_EDAC_EVENT_EMON_CORR 10UL ///< EMON correctable error
#define NVM_EDAC_EVENT_EMON_UNCORR 11UL ///< EMON uncorrectable error
#define NVM_EDAC_EVENT_APP 12UL ///< Errors with AXI BIST or Patrol Scrub completion
#define NVM_EDAC_EVENT_ECC_CORR 13UL ///< Correctable ECC Error
#define NVM_EDAC_EVENT_ECC_UNCORR 14UL ///< Uncorrectable ECC Error
#define NVM_EDAC_EVENT_BUS_ECC_CORR 15UL ///< Bus Correctable ECC Error
#define NVM_EDAC_EVENT_BUS_ECC_UNCORR 16UL ///< Bus Uncorrectable ECC Error
#define NVM_EDAC_NVM_EDAC_IDX_INST_0 0UL ///< NVM EDAC INST 0
#define NVM_EDAC_NVM_EDAC_IDX_INST_1 1UL ///< NVM EDAC INST 1
#define NVM_EDAC_EDAC_IDX_INST_0 0UL ///< EDAC INST 0
#define NVM_EDAC_EDAC_IDX_INST_1 1UL ///< EDAC INST 1
#define NVM_EDAC_EDAC_IDX_NO_INST 2UL ///< No EDAC INST

/**
 * @brief nvm_edac CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t nvm_edac_idx; ///< NVM EDAC instance identifier
    uint8_t edac_idx; ///< EDAC instance identifier
    uint32_t emon_loc_cor_0; ///< Locations corrected LSB 0 - 31
    uint32_t emon_loc_cor_1; ///< Locations corrected MSB 32 - 63
    uint32_t emon_loc_uncor; ///< Decoders that have generated uncorrectable decodes
    uint32_t ram_corr; ///< Correctable Memory location addresses
    uint32_t ram_uncorr; ///< Uncorrectable Memory location addresses
} nvm_edac_section_t;

/*********************************************
* FW_ERR CPER Section
********************************************/



/**
 * @brief fw_err CPER section data description
 */
typedef struct {
    uint32_t id; ///< Unique ID of the error encountered during execution. Represented by the p64h_err_t type
    uint32_t svc_comp; ///< Service which encountered the error. Represented by the p64h_comp_t type
} fw_err_section_t;

/*********************************************
* INTR_STORM CPER Section
********************************************/

#define INTR_STORM_INTR_CTRL_LIC 0UL ///< SYSC Local interrupt controller
#define INTR_STORM_INTR_CTRL_PLIC 1UL ///< SYSC Platform-level interrupt controller

/**
 * @brief intr_storm CPER section data description
 */
typedef struct {
    uint32_t intr_ctrl; ///< Interrupt controller where an interrupt storm was detected
    uint32_t intr_num; ///< Interrupt number which generated the interrupt storm
} intr_storm_section_t;

/*********************************************
* ENET_SW CPER Section
********************************************/



/**
 * @brief ENET_SW_RAM_IDX bitfields access descriptor
 */
typedef struct {
    uint32_t X:8; ///< X index
    uint32_t Y:8; ///< Y index
    uint32_t Z:8; ///< Z index
    uint32_t pad:8; ///< padding bits
} enet_sw_ram_idx_bits_t;

/**
 * @brief ENET_SW_RAM_IDX bit access and word access wrapper union
 */
typedef union {
    enet_sw_ram_idx_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} enet_sw_ram_idx_t;

/**
 * @brief enet_sw CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    enet_sw_ram_idx_t ram_idx; ///< RAM location index for ENET Switch Errors
} enet_sw_section_t;

/*********************************************
* PFLASH_CTRL CPER Section
********************************************/

#define PFLASH_CTRL_EVENT_NO_EVENT 0UL ///< No Event
#define PFLASH_CTRL_EVENT_TRANS_DROP 1UL ///< Transaction dropped due to uncorrectable error or timeout
#define PFLASH_CTRL_EVENT_BUS_ECC_CORR 2UL ///< Bus Correctable ECC Error
#define PFLASH_CTRL_EVENT_BUS_ECC_UNCORR 3UL ///< Bus Uncorrectable ECC Error
#define PFLASH_CTRL_PFLASH_CTRL_IDX_INST_0 0UL ///< PFLASH CTRL INST 0
#define PFLASH_CTRL_PFLASH_CTRL_IDX_INST_1 1UL ///< PFLASH CTRL INST 1
#define PFLASH_CTRL_PFLASH_CTRL_IDX_INST_2 2UL ///< PFLASH CTRL INST 2
#define PFLASH_CTRL_PFLASH_CTRL_IDX_INST_3 3UL ///< PFLASH CTRL INST 3

/**
 * @brief pflash_ctrl CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t pflash_ctrl_idx; ///< PFLASH CTRL instance identifier
} pflash_ctrl_section_t;

/*********************************************
* DDR_EDAC CPER Section
********************************************/

#define DDR_EDAC_EVENT_NO_EVENT 0UL ///< No Event
#define DDR_EDAC_EVENT_RD_TIMEOUT 1UL ///< Read command or data channel timeout
#define DDR_EDAC_EVENT_WR_TIMEOUT 2UL ///< Write command or data channel timeout
#define DDR_EDAC_EVENT_TRANS_DROP 3UL ///< Transaction dropped due to uncorrectable error
#define DDR_EDAC_EVENT_FAULT_CORR 4UL ///< SECDEC AXI bus protection correctable error
#define DDR_EDAC_EVENT_FAULT 5UL ///< EDAC fault occurred
#define DDR_EDAC_EVENT_RAM_CORR 6UL ///< RAM correctable error
#define DDR_EDAC_EVENT_RAM_UNCORR 7UL ///< RAM uncorrectable error
#define DDR_EDAC_EVENT_EMON_CORR 8UL ///< EMON correctable error
#define DDR_EDAC_EVENT_EMON_UNCORR 9UL ///< EMON uncorrectable error
#define DDR_EDAC_EVENT_APP 10UL ///< Errors with AXI BIST or Patrol Scrub completion
#define DDR_EDAC_EDAC_ID_INST_0 0UL ///< EDAC INST 0
#define DDR_EDAC_EDAC_ID_INST_1 1UL ///< EDAC INST 1
#define DDR_EDAC_EDAC_ID_NO_INST 2UL ///< No EDAC INST

/**
 * @brief ddr_edac CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t edac_id; ///< EDAC instance identifier
    uint32_t emon_loc_cor_0; ///< Locations corrected LSB 0 - 31
    uint32_t emon_loc_cor_1; ///< Locations corrected bit 32 - 63
    uint32_t emon_loc_cor_2; ///< Locations corrected MSB 64 - 80
    uint32_t emon_loc_uncor; ///< Decoders that have generated uncorrectable decodes
} ddr_edac_section_t;

/*********************************************
* SPI_CTRL CPER Section
********************************************/

#define SPI_CTRL_EVENT_NO_EVENT 0UL ///< No Event
#define SPI_CTRL_EVENT_TRANS_DROP 1UL ///< Transaction dropped due to uncorrectable error or timeout
#define SPI_CTRL_EVENT_BUS_ECC_CORR 2UL ///< Bus Correctable ECC Error
#define SPI_CTRL_EVENT_BUS_ECC_UNCORR 3UL ///< Bus Uncorrectable ECC Error
#define SPI_CTRL_EVENT_XSPI_RAM_CORR 4UL ///< XSPI RAM correctable error
#define SPI_CTRL_EVENT_XSPI_RAM_UNCORR 5UL ///< XSPI RAM uncorrectable error
#define SPI_CTRL_EVENT_SD_RAM_CORR 6UL ///< SD RAM correctable error
#define SPI_CTRL_EVENT_SD_RAM_UNCORR 7UL ///< SD RAM uncorrectable error
#define SPI_CTRL_EVENT_DEVICE_ERR 8UL ///< Device fail detected when status of the last program operation was checked
#define SPI_CTRL_EVENT_CMD_ERR 9UL ///< Invalid command sequence error detected
#define SPI_CTRL_EVENT_CMD_IGNORED 10UL ///< The controller detected that a command that was sent by the host when system was busy and ignored it
#define SPI_CTRL_EVENT_DEVICE_ECC_CORR 11UL ///< Attached memory device returned uncorrectable ECC error during read operation
#define SPI_CTRL_EVENT_DQS_ERR 12UL ///< DQS underrun or overflow error detected
#define SPI_CTRL_EVENT_CRC_ERR 13UL ///< CRC error detected
#define SPI_CTRL_EVENT_BUS_ERR_S 14UL ///< Unsupported transaction to Slave Interface
#define SPI_CTRL_EVENT_BUS_ERR_M 15UL ///< AXI error response is returned on RRESP or BRESP
#define SPI_CTRL_EVENT_THREAD_ERR 16UL ///< Thread error
#define SPI_CTRL_SPI_CTRL_IDX_INST_0 0UL ///< SPI CTRL INST 0
#define SPI_CTRL_SPI_CTRL_IDX_INST_1 1UL ///< SPI CTRL INST 1
#define SPI_CTRL_SPI_CTRL_IDX_INST_2 2UL ///< SPI CTRL INST 2
#define SPI_CTRL_SPI_CTRL_IDX_INST_3 3UL ///< SPI CTRL INST 3
#define SPI_CTRL_SPI_CTRL_IDX_INST_4 4UL ///< Sysc XSPI CTRL INST 0
#define SPI_CTRL_SPI_CTRL_IDX_INST_5 5UL ///< Sysc XSPI CTRL INST 1

/**
 * @brief spi_ctrl CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t spi_ctrl_idx; ///< SPI CTRL instance identifier
} spi_ctrl_section_t;

/*********************************************
* NAND_CTRL CPER Section
********************************************/

#define NAND_CTRL_EVENT_NO_EVENT 0UL ///< No Event
#define NAND_CTRL_EVENT_TRANS_DROP 1UL ///< Transaction dropped due to uncorrectable error or timeout
#define NAND_CTRL_EVENT_S_BUS_ECC_CORR 2UL ///< AXI subordinate Bus Correctable ECC Error
#define NAND_CTRL_EVENT_S_BUS_ECC_UNCORR 3UL ///< AXI subordinate Bus Uncorrectable ECC Error
#define NAND_CTRL_EVENT_M_BUS_ECC_CORR 4UL ///< AXI manager Bus Correctable ECC Error
#define NAND_CTRL_EVENT_M_BUS_ECC_UNCORR 5UL ///< AXI manager Bus Uncorrectable ECC Error
#define NAND_CTRL_EVENT_M_RESP_UNCORR 6UL ///< AXI manager Response Uncorrectable Error
#define NAND_CTRL_EVENT_RAM_CORR 7UL ///< RAM correctable error
#define NAND_CTRL_EVENT_RAM_UNCORR 8UL ///< RAM uncorrectable error
#define NAND_CTRL_NAND_CTRL_IDX_INST_0 0UL ///< NAND CTRL INST 0
#define NAND_CTRL_NAND_CTRL_IDX_INST_1 1UL ///< NAND CTRL INST 1
#define NAND_CTRL_NAND_CTRL_IDX_INST_2 2UL ///< NAND CTRL INST 2
#define NAND_CTRL_NAND_CTRL_IDX_INST_3 3UL ///< NAND CTRL INST 3

/**
 * @brief nand_ctrl CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t nand_ctrl_idx; ///< NAND CTRL instance identifier
} nand_ctrl_section_t;

/*********************************************
* DDR_CTRL CPER Section
********************************************/

#define DDR_CTRL_EVENT_NO_EVENT 0UL ///< No Event
#define DDR_CTRL_EVENT_MISC 1UL ///< error detected in the DDR controller
#define DDR_CTRL_EVENT_RAM_CORR 2UL ///< RAM ECC correctable error
#define DDR_CTRL_EVENT_RAM_UNCORR 3UL ///< RAM ECC uncorrectable error
#define DDR_CTRL_CTRL_ID_INST_0 0UL ///< CTRL INST 0
#define DDR_CTRL_CTRL_ID_INST_1 1UL ///< CTRL INST 1
#define DDR_CTRL_CTRL_ID_NO_INST 2UL ///< No CTRL INST
#define DDR_CTRL_MISC_INT_INFO_NO_INT_INFO 0UL ///< No Interrupt Info.
#define DDR_CTRL_MISC_INT_INFO_BIST_COMPLETED 1UL ///< The BIST operation has been completed.
#define DDR_CTRL_MISC_INT_INFO_DFI_INIT_TIMEOUT 2UL ///< The DFItinit-complete value has timed out.
#define DDR_CTRL_MISC_INT_INFO_DFI_DLL_RESYNC_DONE 3UL ///< The user-initiated DLL resynchronization has completed.
#define DDR_CTRL_MISC_INT_INFO_DFI_INIT_STATE_CHANGE 4UL ///< A state change has been detected after initialization.
#define DDR_CTRL_MISC_INT_INFO_DFI_PHY_MASTER_ERROR 5UL ///< A DFI PHY Master Interface error has occurred.
#define DDR_CTRL_MISC_INT_INFO_DFI_PHY_BUS_ERROR 6UL ///< Error received from the PHY on the DFI bus.
#define DDR_CTRL_MISC_INT_INFO_DFI_UPDATE_ERROR 7UL ///< A DFI update error has occurred.
#define DDR_CTRL_MISC_INT_INFO_FREQ_SW_COMPLETED 8UL ///< A DFS operation initiated by software completed.
#define DDR_CTRL_MISC_INT_INFO_FREQ_SW_TIMEOUT 9UL ///< The DFS operation initiated by the software interface has timed out.
#define DDR_CTRL_MISC_INT_INFO_FREQ_SW_IGNORED 10UL ///< The DFS request from software was ignored.
#define DDR_CTRL_MISC_INT_INFO_FREQ_HW_COMPLETED 11UL ///< A DFS operation initiated by the hardware interface completed.
#define DDR_CTRL_MISC_INT_INFO_FREQ_HW_TIMEOUT 12UL ///< The DFS operation initiated by the hardware interface has timed out.
#define DDR_CTRL_MISC_INT_INFO_FREQ_HW_IGNORED 13UL ///< The DFS request from the hardware interface was ignored.
#define DDR_CTRL_MISC_INT_INFO_INIT_MC_COMPLETED 14UL ///< The MC initialization has been completed.
#define DDR_CTRL_MISC_INT_INFO_INIT_MEM_RESET_VALID 15UL ///< The memory reset is valid on the DFI bus.
#define DDR_CTRL_MISC_INT_INFO_LP_TIMEOUT_ERROR 16UL ///< A Low Power Interface timeout error has occurred.
#define DDR_CTRL_MISC_INT_INFO_LP_COMPLETED 17UL ///< The low power operation has been completed.
#define DDR_CTRL_MISC_INT_INFO_MISC_SW_REFRESH_STATUS_SET 18UL ///< The sw requested refresh operation has resulted in a status bit being set.
#define DDR_CTRL_MISC_INT_INFO_MISC_REFRESH_STATUS_SET 19UL ///< The refresh operation has resulted in a status bit being set.
#define DDR_CTRL_MISC_INT_INFO_MISC_SW_MODE_ENTERED 20UL ///< The controller has entered the software-requested mode.
#define DDR_CTRL_MISC_INT_INFO_MISC_INHIBIT_DRAM_CMD 21UL ///< The assertion of the inhibit_dram_cmd parameter has successfully inhibited the command queue.
#define DDR_CTRL_MISC_INT_INFO_MODE_MRW_COMPLETED 22UL ///< The register interface-initiated mode register write has completed and another mode register write may be issued.
#define DDR_CTRL_MISC_INT_INFO_MODE_MPR_READ_DONE 23UL ///< MPR read command, initiated with a software MPR_READ request, is complete.
#define DDR_CTRL_MISC_INT_INFO_PARITY_ADDR_CTRL_ERROR 24UL ///< A parity error has been detected on the address/control bus on a registered DIMM.
#define DDR_CTRL_MISC_INT_INFO_PARITY_WR_DATA_OVERLAP 25UL ///< An overlapping write data parity error has been detected at the memory controller boundary.
#define DDR_CTRL_MISC_INT_INFO_PARITY_WR_DATA_ERROR 26UL ///< A write data parity error has been detected.
#define DDR_CTRL_MISC_INT_INFO_TIMEOUT_AUTO_REFRESH_MAX_DEFICIT 27UL ///< The auto-refresh max deficit timeout has expired.
#define DDR_CTRL_MISC_INT_INFO_TIMEOUT_LP_WAKEUP 28UL ///< The low power interface wakeup timeout has expired.
#define DDR_CTRL_MISC_INT_INFO_TIMEOUT_DFI_UPDATE_FM 29UL ///< The DFI update FM timeout has expired.
#define DDR_CTRL_MISC_INT_INFO_TIMEOUT_ZQ_CAL_FM 30UL ///< The ZQ cal init, cs, cl, or reset FM timeout has expired.
#define DDR_CTRL_MISC_INT_INFO_TRAINING_ZQ_CAL_STATUS_SET 31UL ///< The ZQ calibration operation has resulted in a status bit being set.
#define DDR_CTRL_MISC_INT_INFO_UI_INVALID_CORE_WORDS 32UL ///< The user has programmed an invalid setting associated with core words per burst.
#define DDR_CTRL_MISC_INT_INFO_UI_WRAP_CYCLE_CROSS_PAGE 33UL ///< A wrap cycle crossing a DRAM page has been detected.
#define DDR_CTRL_MISC_INT_INFO_UI_PORT_CMD_ERROR 34UL ///< An error occurred on the port command channel.
#define DDR_CTRL_MISC_INT_INFO_UI_MULTI_PHYS_MEM_ACCESS 35UL ///< Multiple accesses outside the defined PHYSICAL memory space have occurred.
#define DDR_CTRL_MISC_INT_INFO_UI_PHYS_MEM_ACCESS 36UL ///< A memory access outside the defined PHYSICAL memory space has occurred.

/**
 * @brief DDR_CTRL_FIFO_FULL bitfields access descriptor
 */
typedef struct {
    uint8_t port:4; ///< port fifo is full.
    uint8_t core:3; ///< core fifo is full.
    uint8_t pad:1; ///< padding bits
} ddr_ctrl_fifo_full_bits_t;

/**
 * @brief DDR_CTRL_FIFO_FULL bit access and word access wrapper union
 */
typedef union {
    ddr_ctrl_fifo_full_bits_t b; ///< Bitfields accessor
    uint8_t w; ///< Word accessor
} ddr_ctrl_fifo_full_t;

/**
 * @brief ddr_ctrl CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t ctrl_id; ///< CTRL instance identifier
    ddr_ctrl_fifo_full_t fifo_full; ///< fifo is full
    uint8_t misc_int_info; ///< Controller Misc Interrupt Info
} ddr_ctrl_section_t;

/*********************************************
* DDR_PHY CPER Section
********************************************/

#define DDR_PHY_EVENT_NO_EVENT 0UL ///< No Event
#define DDR_PHY_EVENT_DFI_RDDATA 1UL ///< DFI read data valid for each data slice
#define DDR_PHY_PHY_ID_INST_0 0UL ///< PHY instance 0
#define DDR_PHY_PHY_ID_INST_1 1UL ///< PHY instance 1
#define DDR_PHY_PHY_ID_NO_INST 2UL ///< No PHY instance

/**
 * @brief ddr_phy CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t phy_id; ///< PHY instance identifier
    uint16_t dfi_rddata_valid_err; ///< DFI rddata valid error
    uint16_t dfi_rddata_valid_fifo_full; ///< DFI rddata valid fifo full
} ddr_phy_section_t;

/*********************************************
* DDR_HSIO CPER Section
********************************************/

#define DDR_HSIO_EVENT_NO_EVENT 0UL ///< No Event
#define DDR_HSIO_EVENT_PAB 1UL ///< PAB DLL lock and unlock
#define DDR_HSIO_HSIO_ID_INST_0 0UL ///< PHY HSIO 0
#define DDR_HSIO_HSIO_ID_INST_1 1UL ///< PHY HSIO 1
#define DDR_HSIO_HSIO_ID_INST_2 2UL ///< PHY HSIO 2
#define DDR_HSIO_HSIO_ID_INST_3 3UL ///< PHY HSIO 3
#define DDR_HSIO_HSIO_ID_INST_4 4UL ///< PHY HSIO 4
#define DDR_HSIO_HSIO_ID_NO_INST 5UL ///< No HSIO

/**
 * @brief ddr_hsio CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t hsio_id; ///< PHY HSIO identifier
} ddr_hsio_section_t;

/*********************************************
* SPW_CTRL CPER Section
********************************************/

#define SPW_CTRL_EVENT_NO_EVENT 0UL ///< No Event
#define SPW_CTRL_EVENT_TX_RAM_CORR 1UL ///< Tx RAM correctable error
#define SPW_CTRL_EVENT_TX_RAM_UNCORR 2UL ///< Tx RAM uncorrectable error
#define SPW_CTRL_EVENT_RX_RAM_CORR 3UL ///< Rx RAM correctable error
#define SPW_CTRL_EVENT_RX_RAM_UNCORR 4UL ///< Rx RAM uncorrectable error
#define SPW_CTRL_EVENT_RMAP_RAM_CORR 5UL ///< RMAP RAM correctable error
#define SPW_CTRL_EVENT_RMAP_RAM_UNCORR 6UL ///< RMAP RAM uncorrectable error
#define SPW_CTRL_EVENT_LINK_STATE_ERR 7UL ///< SPW link state error
#define SPW_CTRL_EVENT_PKT_DISCARD 8UL ///< Packet discarded
#define SPW_CTRL_EVENT_EEP_RECEIVED 9UL ///< EEP received
#define SPW_CTRL_EVENT_EEP_SENT 10UL ///< EEP sent
#define SPW_CTRL_EVENT_TIME_CODE_ERR 11UL ///< Time code error
#define SPW_CTRL_EVENT_PAR_ERR 12UL ///< Parity error
#define SPW_CTRL_EVENT_ESC_ERR 13UL ///< ESC error
#define SPW_CTRL_SPW_CTRL_IDX_INST_0 0UL ///< SYSC SPW CTRL INST

/**
 * @brief SPW_CTRL_EDAC_STS data description
 */
typedef struct {
    uint8_t corr_count; ///< Number of EDAC corrections made. Saturates at max (255).
    uint8_t uncorrected; ///< Whether an uncorrected error has occurred since last clear.
} spw_ctrl_edac_sts_t;

/**
 * @brief SPW_CTRL payload data
 */
typedef union {
    spw_ctrl_edac_sts_t edac_sts; ///< EDAC status for SPW controller errors
} spw_ctrl_payload_t;

/**
 * @brief spw_ctrl CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t spw_ctrl_idx; ///< SPW CTRL instance identifier
    spw_ctrl_payload_t payload; ///< Data payload
} spw_ctrl_section_t;

/*********************************************
* SYS_DBG CPER Section
********************************************/

#define SYS_DBG_EVENT_NO_EVENT 0UL ///< No Event
#define SYS_DBG_EVENT_S7_TRACE_RAM_CORR 1UL ///< S7 Trace RAM correctable error
#define SYS_DBG_EVENT_S7_TRACE_RAM_UNCORR 2UL ///< S7 Trace RAM uncorrectable error
#define SYS_DBG_EVENT_INTERRUPT_LOG_TIMESTAMP_FIFO_CORR 3UL ///< Interrupt log timestamp FIFO correctable error
#define SYS_DBG_EVENT_INTERRUPT_LOG_TIMESTAMP_FIFO_UNCORR 4UL ///< Interrupt log timestamp FIFO uncorrectable error
#define SYS_DBG_EVENT_INTERRUPT_LOG_TIMESTAMP_FIFO_OVERFLOW 5UL ///< Interrupt log timestamp FIFO overflow error
#define SYS_DBG_EVENT_APPC_INTERRUPT_LOG_TIMESTAMP_FIFO_CORR 6UL ///< APPC error interrupt log timestamp FIFO correctable error
#define SYS_DBG_EVENT_APPC_INTERRUPT_LOG_TIMESTAMP_FIFO_UNCORR 7UL ///< APPC error interrupt log timestamp FIFO uncorrectable error
#define SYS_DBG_EVENT_APPC_INTERRUPT_LOG_TIMESTAMP_FIFO_OVERFLOW 8UL ///< APPC error interrupt log timestamp FIFO overflow error

/**
 * @brief sys_dbg CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
} sys_dbg_section_t;

/*********************************************
* ENET_EP_SB CPER Section
********************************************/

#define ENET_EP_SB_EVENT_NO_EVENT 0UL ///< No Event
#define ENET_EP_SB_EVENT_FATAL 1UL ///< Service Bus Fatal Error interrupt (Mainly, but not limited to, multi-bit ECC errors)
#define ENET_EP_SB_EVENT_ERROR 2UL ///< Service Bus Non-Fatal Error interrupt (Mainly, but not limited to, single-bit ECC errors)
#define ENET_EP_SB_SB_ID_INST_0 0UL ///< Service Bus INST 0

/**
 * @brief ENET_EP_SB_AXI_PARITY_ERR bitfields access descriptor
 */
typedef struct {
    uint16_t ep0:3; ///< ep0 axi parity error
    uint16_t ep1:3; ///< ep1 axi parity error
    uint16_t ep2:3; ///< ep2 axi parity error
    uint16_t ep3:3; ///< ep3 axi parity error
    uint16_t pad:4; ///< padding bits
} enet_ep_sb_axi_parity_err_bits_t;

/**
 * @brief ENET_EP_SB_AXI_PARITY_ERR bit access and word access wrapper union
 */
typedef union {
    enet_ep_sb_axi_parity_err_bits_t b; ///< Bitfields accessor
    uint16_t w; ///< Word accessor
} enet_ep_sb_axi_parity_err_t;

/**
 * @brief enet_ep_sb CPER section data description
 */
typedef struct {
    uint32_t event; ///< ENET EP Service Bus event type
    uint8_t sb_id; ///< Service Bus instance identifier
    enet_ep_sb_axi_parity_err_t axi_parity_err; ///< axi parity error
} enet_ep_sb_section_t;

/*********************************************
* ENET_EP_CORE CPER Section
********************************************/

#define ENET_EP_CORE_EVENT_NO_EVENT 0UL ///< No Event
#define ENET_EP_CORE_EVENT_ASF 1UL ///< Automotic Safety Feature (ASF) fatal interrupt
#define ENET_EP_CORE_EVENT_IOB 2UL ///< IO Bridge Error interrupt
#define ENET_EP_CORE_EVENT_MMSL 3UL ///< MAC merge sublayer Error Interrupt
#define ENET_EP_CORE_CORE_ID_INST_0 0UL ///< ENET_EP Core INST 0
#define ENET_EP_CORE_CORE_ID_INST_1 1UL ///< ENET_EP Core INST 1
#define ENET_EP_CORE_CORE_ID_INST_2 2UL ///< ENET_EP Core INST 2
#define ENET_EP_CORE_CORE_ID_INST_3 3UL ///< ENET_EP Core INST 3

/**
 * @brief ENET_EP_CORE_ASF_SRAM_UNCORR_FAULT bitfields access descriptor
 */
typedef struct {
    uint32_t addr:24; ///< ASF SRAM uncorrectable fault address
    uint32_t inst:8; ///< ASF SRAM uncorrectable fault instance
} enet_ep_core_asf_sram_uncorr_fault_bits_t;

/**
 * @brief ENET_EP_CORE_ASF_SRAM_UNCORR_FAULT bit access and word access wrapper union
 */
typedef union {
    enet_ep_core_asf_sram_uncorr_fault_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} enet_ep_core_asf_sram_uncorr_fault_t;

/**
 * @brief ENET_EP_CORE_ASF_SRAM_CORR_FAULT bitfields access descriptor
 */
typedef struct {
    uint32_t addr:24; ///< ASF SRAM correctable fault address
    uint32_t inst:8; ///< ASF SRAM correctable fault instance
} enet_ep_core_asf_sram_corr_fault_bits_t;

/**
 * @brief ENET_EP_CORE_ASF_SRAM_CORR_FAULT bit access and word access wrapper union
 */
typedef union {
    enet_ep_core_asf_sram_corr_fault_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} enet_ep_core_asf_sram_corr_fault_t;

/**
 * @brief ENET_EP_CORE_ASF_PROTO_FAULT bitfields access descriptor
 */
typedef struct {
    uint32_t rx_crc_err_status:1; ///< Status bit for RX packet with bad CRC.
    uint32_t rx_short_err_status:1; ///< Status bit for RX packet too short.
    uint32_t rx_long_err_status:1; ///< Status bit for RX packet too long.
    uint32_t rx_symbol_err_status:1; ///< Status bit for RX packet with symbol errors.
    uint32_t rx_length_err_status:1; ///< Status bit for RX packet with length field error.
    uint32_t rx_ip_ck_err_status:1; ///< Status bit for RX packet IP checksum error.
    uint32_t rx_tcp_ck_err_status:1; ///< Status bit for RX packet TCP checksum error.
    uint32_t rx_udp_ck_err_status:1; ///< Status bit for RX packet UDP checksum error.
    uint32_t tx_too_many_retries_status:1; ///< Status bit for too many retry attempts after collision error (half duplex only).
    uint32_t reserved_15_9:7; ///< Reserved, read as 0, ignored on write.
    uint32_t tx_underrun_status:1; ///< Status bit for Transmit DMA underrun occurred.
    uint32_t tx_buff_ex_mid_status:1; ///< Status bit for Transmit buffers exhausted before end of packet.
    uint32_t tx_hresp_err_status:1; ///< Status bit for DMA hresp error (AHB only).
    uint32_t rx_hresp_err_status:1; ///< Status bit for DMA hresp error (AHB only).
    uint32_t rx_overflow_status:1; ///< Status bit for DMA buffer overflow and packet was dropped.
    uint32_t rx_dma_pkt_flush_status:1; ///< Status bit for RX packet was flushed from the DMA.
    uint32_t pad:10; ///< padding bits
} enet_ep_core_asf_proto_fault_bits_t;

/**
 * @brief ENET_EP_CORE_ASF_PROTO_FAULT bit access and word access wrapper union
 */
typedef union {
    enet_ep_core_asf_proto_fault_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} enet_ep_core_asf_proto_fault_t;

/**
 * @brief ENET_EP_CORE_ASF_TRANS_FAULT bitfields access descriptor
 */
typedef struct {
    uint32_t mac_tx_to_status:1; ///< Status bit for MAC TX lockup detection.
    uint32_t mac_rx_to_status:1; ///< Status bit for MAC RX lockup detection.
    uint32_t dma_tx_to_status:1; ///< Status bit for DMA TX lockup detection.
    uint32_t dma_rx_to_status:1; ///< Status bit for DMA RX lockup detection.
    uint32_t host_trans_to_status:1; ///< Status bit for AMBA host transaction timeouts.
    uint32_t pad:27; ///< padding bits
} enet_ep_core_asf_trans_fault_bits_t;

/**
 * @brief ENET_EP_CORE_ASF_TRANS_FAULT bit access and word access wrapper union
 */
typedef union {
    enet_ep_core_asf_trans_fault_bits_t b; ///< Bitfields accessor
    uint32_t w; ///< Word accessor
} enet_ep_core_asf_trans_fault_t;

/**
 * @brief enet_ep_core CPER section data description
 */
typedef struct {
    uint32_t event; ///< ENET EP Core event type
    uint8_t core_id; ///< ENET EP Core instance identifier
    enet_ep_core_asf_sram_uncorr_fault_t asf_sram_uncorr_fault; ///< ASF SRAM uncorrectable fault
    enet_ep_core_asf_sram_corr_fault_t asf_sram_corr_fault; ///< ASF SRAM correctable fault
    enet_ep_core_asf_proto_fault_t asf_proto_fault; ///< Bitmask of ASF protocol fault interrupt status
    enet_ep_core_asf_trans_fault_t asf_trans_fault; ///< Bitmask of ASF transaction fault interrupt status
} enet_ep_core_section_t;

/*********************************************
* ENET_EP_FRER_TX CPER Section
********************************************/

#define ENET_EP_FRER_TX_EVENT_NO_EVENT 0UL ///< No Event
#define ENET_EP_FRER_TX_EVENT_GROUP 1UL ///< FRER TX Group Error interrupt
#define ENET_EP_FRER_TX_FRER_TX_ID_INST_0 0UL ///< FRER_TX INST 0
#define ENET_EP_FRER_TX_FRER_TX_ID_INST_1 1UL ///< FRER_TX INST 1

/**
 * @brief enet_ep_frer_tx CPER section data description
 */
typedef struct {
    uint32_t event; ///< ENET FRER TX event type
    uint8_t frer_tx_id; ///< FRER TX instance identifier
} enet_ep_frer_tx_section_t;

/*********************************************
* ENET_EP_FRER_RX CPER Section
********************************************/

#define ENET_EP_FRER_RX_EVENT_NO_EVENT 0UL ///< No Event
#define ENET_EP_FRER_RX_EVENT_GROUP 1UL ///< FRER RX Group Error interrupt
#define ENET_EP_FRER_RX_FRER_RX_ID_INST_0 0UL ///< FRER_RX INST 0
#define ENET_EP_FRER_RX_FRER_RX_ID_INST_1 1UL ///< FRER_RX INST 1

/**
 * @brief enet_ep_frer_rx CPER section data description
 */
typedef struct {
    uint32_t event; ///< ENET FRER RX event type
    uint8_t frer_rx_id; ///< FRER RX instance identifier
} enet_ep_frer_rx_section_t;

/*********************************************
* SYS_NOC_FA CPER Section
********************************************/

#define SYS_NOC_FA_EVENT_NO_EVENT 0UL ///< No event
#define SYS_NOC_FA_EVENT_FLT_SECDED_CORR_EVENT 1UL ///< FLT SECDED correctable error event
#define SYS_NOC_FA_EVENT_FLT_SECDED_UNCORR_EVENT 2UL ///< FLT SECDED uncorrectable error event
#define SYS_NOC_FA_EVENT_PKT_VALID_FAULT_EVENT 3UL ///< packet validity fault event
#define SYS_NOC_FA_EVENT_CTRL_REG_PAR_EVENT 4UL ///< control register parity error event
#define SYS_NOC_FA_EVENT_TIMEOUT_EVENT 5UL ///< Initiator NIU timeout event
#define SYS_NOC_FA_EVENT_FSM_ERROR_EVENT 6UL ///< Internal FSM error event
#define SYS_NOC_FA_EVENT_LN_DTP_FLT_FAULT_EVENT 7UL ///< FLT SECDED error event of datapath link block
#define SYS_NOC_FA_EVENT_FAULT_FROM_AGG_BOTTOM_EVENT 8UL ///< fault detected from bottom aggregator
#define SYS_NOC_FA_FAULT_SOURCE_IDX_CPU_PERIPH_I_NIU 0UL ///< CPU Peripheral Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_CPU_SYS_I_NIU 1UL ///< CPU sys Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_DMA_MASTER_I_NIU 2UL ///< DMA Master Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SEC_DMA_MASTER_I_NIU 3UL ///< SEC DMA Master Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SPW_RMAP_I_NIU 4UL ///< SPW RMAP Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SPW_RX_I_NIU 5UL ///< SPW RX Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SPW_TX_I_NIU 6UL ///< SPW TX Initiator NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_APP_NOC_T_NIU 7UL ///< APP NoC Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_CPU_FRONT_T_NIU 8UL ///< CPU Front Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_DMA_CTRL_T_NIU 9UL ///< DMA Control Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_EDAC_CTRL_T_NIU 10UL ///< EDAC Control Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_ELAPSED_TIMER_T_NIU 11UL ///< Elapsed Timer Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_FLASH0_DATA_T_NIU 12UL ///< FLASH0 Data Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_FLASH1_DATA_T_NIU 13UL ///< FLASH1 Data Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_GPIO_T_NIU 14UL ///< GPIO Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_I2C_T_NIU 15UL ///< I2C Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_NOC_CONFIG_T_NIU 16UL ///< noc_config Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_OCR_CTRL_T_NIU 17UL ///< OCR Control Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_OCR_DATA_T_NIU 18UL ///< OCR Data Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_QSPI0_CTRL_T_NIU 19UL ///< qspi0 control Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_QSPI1_CTRL_T_NIU 20UL ///< qspi1 control Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SEC_MBOX_T_NIU 21UL ///< sec mbox Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SPW_CTRL_T_NIU 22UL ///< spw control Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SVC_NOC_CONFIG_T_NIU 23UL ///< svc_noc_config Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_SYSREG_T_NIU 24UL ///< sysreg Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_TIMERS_T_NIU 25UL ///< timers Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_UART_T_NIU 26UL ///< uart Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_WDT_T_NIU 27UL ///< wdt Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_WG_CHECKER_T_NIU 28UL ///< wgchecker Target NIU
#define SYS_NOC_FA_FAULT_SOURCE_IDX_TOP_AGG_APP 29UL ///< APP Top fault aggregator
#define SYS_NOC_FA_FAULT_SOURCE_IDX_TOP_AGG_SYS_HA 30UL ///< SYS HA Top fault aggregator
#define SYS_NOC_FA_FAULT_SOURCE_IDX_TOP_AGG_SVC 31UL ///< SVC Top fault aggregator
#define SYS_NOC_FA_FAULT_SOURCE_IDX_TOP_AGG_SYS 32UL ///< SYS Top fault aggregator

/**
 * @brief sys_noc_fa CPER section data description
 */
typedef struct {
    uint32_t event; ///< SysNoC fault aggregator event type
    uint8_t fault_source_idx; ///< Error source instance identifier
} sys_noc_fa_section_t;

/*********************************************
* NOC_OBS CPER Section
********************************************/

#define NOC_OBS_EVENT_NO_EVENT 0UL ///< No event
#define NOC_OBS_EVENT_SLV_ERR_EVENT 1UL ///< Target error detected event
#define NOC_OBS_EVENT_DEC_ERR_EVENT 2UL ///< Address decode error event
#define NOC_OBS_EVENT_UNS_ERR_EVENT 3UL ///< Unsupported request type error event
#define NOC_OBS_EVENT_DISC_ERR_EVENT 4UL ///< Disconnected target or domain event
#define NOC_OBS_EVENT_SEC_ERR_EVENT 5UL ///< Security violation event
#define NOC_OBS_EVENT_HIDE_ERR_EVENT 6UL ///< Hidden security violation event
#define NOC_OBS_EVENT_TMO_ERR_EVENT 7UL ///< target NIU timeout error event
#define NOC_OBS_ERROR_LOGGER_IDX_APP_CPU_TARG0 0UL ///< APP NOC CPU_TARG0 observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_CPU_TARG1 1UL ///< APP NOC CPU_TARG1 observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_DDR_TARG0 2UL ///< APP NOC DDR_TARG0 observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_DDR_TARG1 3UL ///< APP NOC DDR_TARG1 observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_DDRCFG_TARG 4UL ///< APP NOC DDRCFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_DDRENC_TARG 5UL ///< APP NOC DDRENC_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_ENETEPCFG_TARG 6UL ///< APP NOC ENETEPCFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_ENETSWR_TARG 7UL ///< APP NOC ENETSWR_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_ENETSWRCFG_TARG 8UL ///< APP NOC ENETSWRCFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_IOMMUCFG_TARG 9UL ///< APP NOC IOMMUCFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_M2_TARG 10UL ///< APP NOC M2_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_M2CFG_TARG 11UL ///< APP NOC M2CFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_M3_TARG 12UL ///< APP NOC M3_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_M3CFG_TARG 13UL ///< APP NOC M3CFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_NVM_TARG 14UL ///< APP NOC NVM_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_NVMCFG_TARG 15UL ///< APP NOC NVMCFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_PCIE0_TARG 16UL ///< APP NOC PCIE0_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_PCIE0CFG_TARG 17UL ///< APP NOC PCIE0CFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_PCIE1_TARG 18UL ///< APP NOC PCIE1_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_PCIE1CFG_TARG 19UL ///< APP NOC PCIE1CFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_SYSCTLINTSTATUS 20UL ///< APP NOC SYSCTLINTSTATUS observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_USRCRYPTO_TARG 21UL ///< APP NOC USRCRYPTO_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_APP_USRCRYPTOCFG_TARG 22UL ///< APP NOC USRCRYPTOCFG_TARG observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_DDR_MAIN 23UL ///< DDR NOC observer error logger instance
#define NOC_OBS_ERROR_LOGGER_IDX_SYS_MAIN 24UL ///< SYS NOC observer error logger instance

/**
 * @brief noc_obs CPER section data description
 */
typedef struct {
    uint32_t event; ///< NoC observer error packet event type
    uint8_t lock; ///< lock field of the logged packet header. When the Lock (Lck) bit is set, arbitration will not take place at the end of the packet.
    uint8_t opc; ///< opc field indicates the transaction type.
    uint16_t initFlow; ///< The initiator of the transaction.
    uint16_t targFlow; ///< The target of the transaction.
    uint16_t targSubRange; ///< Target subrange.
    uint16_t seqId; ///< SequenceId of the transaction.
    uint32_t targ_addr_lsb; ///< Address LSB field of the logged packet header.Addr indicates the start address of the transaction, expressed in bytes, in the target address space.Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t targ_addr_msb; ///< Address MSB field of the logged packet header.Addr indicates the start address of the transaction, expressed in bytes, in the target address space.Only valid when error is of type UNS, DISC, SEC or DEC and it has been generated within the NoC transport.
    uint32_t userFlags; ///< User field of the logged packet header
    uint8_t error_logger_idx; ///< NoC observer error logger instance identifier
} noc_obs_section_t;

/*********************************************
* DDR_NOC CPER Section
********************************************/

#define DDR_NOC_EVENT_NO_EVENT 0UL ///< No event
#define DDR_NOC_EVENT_FLT_SECDED_CORR_EVENT 1UL ///< FLT SECDED correctable error event
#define DDR_NOC_EVENT_FLT_SECDED_UNCORR_EVENT 2UL ///< FLT SECDED uncorrectable error event
#define DDR_NOC_EVENT_PKT_VALID_FAULT_EVENT 3UL ///< packet validity fault event
#define DDR_NOC_EVENT_CTRL_REG_PAR_EVENT 4UL ///< control register parity error event
#define DDR_NOC_EVENT_TIMEOUT_EVENT 5UL ///< Initiator NIU timeout event
#define DDR_NOC_EVENT_FSM_ERROR_EVENT 6UL ///< Internal FSM error event
#define DDR_NOC_EVENT_COMPARATOR_TREE_FAULT_EVENT 7UL ///< comparator tree fault
#define DDR_NOC_EVENT_RGC_CORR_FAULT_EVENT 8UL ///< redunancy generator and checker correctable error event
#define DDR_NOC_EVENT_RGC_UNCORR_FAULT_EVENT 9UL ///< redunancy generator and checker uncorrectable error event
#define DDR_NOC_EVENT_FAULT_FROM_AGG_BOTTOM_EVENT 10UL ///< fault detected from bottom aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_APP_A0_I_NIU 0UL ///< APP A0 Initiator NIU
#define DDR_NOC_FAULT_SOURCE_IDX_APP_A1_I_NIU 1UL ///< APP A1 Initiator NIU
#define DDR_NOC_FAULT_SOURCE_IDX_APP_B0_I_NIU 2UL ///< APP B0 Initiator NIU
#define DDR_NOC_FAULT_SOURCE_IDX_APP_B1_I_NIU 3UL ///< APP B1 Initiator NIU
#define DDR_NOC_FAULT_SOURCE_IDX_SVC_I_NIU 4UL ///< SVC Initiator NIU
#define DDR_NOC_FAULT_SOURCE_IDX_EDAC0_T_NIU 5UL ///< EDAC0 Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_EDAC1_T_NIU 6UL ///< EDAC1 Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_ISVC_T_NIU 7UL ///< ISVC Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_WG_0_T_NIU 8UL ///< WG_0 Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_WG_1_T_NIU 9UL ///< WG_1 Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_WG_2_T_NIU 10UL ///< WG_2 Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_WG_3_T_NIU 11UL ///< WG_3 Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_PCBI_T_NIU 12UL ///< PCBI Target NIU
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_A0_PWR 13UL ///< APP A0 Top fault aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_A1_PWR 14UL ///< APP A1 Top fault aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_B0_PWR 15UL ///< APP B0 Top fault aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_B1_PWR 16UL ///< APP B1 Top fault aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_SVC_PWR 17UL ///< SVC Top fault aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_EDAC0_PWR 18UL ///< EDAC0 Top fault aggregator
#define DDR_NOC_FAULT_SOURCE_IDX_TOP_AGG_EDAC1_PWR 19UL ///< EDAC1 Top fault aggregator

/**
 * @brief ddr_noc CPER section data description
 */
typedef struct {
    uint32_t event; ///< DDR NoC fault aggregator event type
    uint8_t fault_source_idx; ///< Error source instance identifier
} ddr_noc_section_t;

/*********************************************
* HPT CPER Section
********************************************/

#define HPT_EVENT_NO_EVENT 0UL ///< No Event
#define HPT_EVENT_ELT_CNT_UNCORR 1UL ///< HPT input ELT counter uncorrectable error
#define HPT_HPT_IDX_SYSC_HPT_INST 0UL ///< SYSC HPT INST

/**
 * @brief hpt CPER section data description
 */
typedef struct {
    uint32_t event; ///< Event type identifier
    uint8_t hpt_idx; ///< HPT instance identifier
} hpt_section_t;

/*********************************************
* APP_NOC_FA CPER Section
********************************************/

#define APP_NOC_FA_EVENT_NO_EVENT 0UL ///< No event
#define APP_NOC_FA_EVENT_FLT_SECDED_CORR_EVENT 1UL ///< FLT SECDED correctable error event
#define APP_NOC_FA_EVENT_FLT_SECDED_UNCORR_EVENT 2UL ///< FLT SECDED uncorrectable error event
#define APP_NOC_FA_EVENT_PKT_VALID_FAULT_EVENT 3UL ///< packet validity fault event
#define APP_NOC_FA_EVENT_CTRL_REG_PAR_EVENT 4UL ///< control register parity error event
#define APP_NOC_FA_EVENT_TIMEOUT_EVENT 5UL ///< Initiator NIU timeout event
#define APP_NOC_FA_EVENT_FSM_ERROR_EVENT 6UL ///< Internal FSM error event
#define APP_NOC_FA_EVENT_COMPARATOR_TREE_FAULT_EVENT 7UL ///< comparator tree fault
#define APP_NOC_FA_EVENT_RGC_CORR_FAULT_EVENT 8UL ///< redunancy generator and checker correctable error event
#define APP_NOC_FA_EVENT_RGC_UNCORR_FAULT_EVENT 9UL ///< redunancy generator and checker uncorrectable error event
#define APP_NOC_FA_EVENT_FAULT_FROM_AGG_BOTTOM_EVENT 10UL ///< fault detected from bottom aggregator
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_CPU0 0UL ///< CPU0 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_CPU1 1UL ///< CPU1 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_CPU_TARG0 2UL ///< CPU targ0 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_CPU_TARG1 3UL ///< CPU targ1 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_DDR_ENCRYPT 4UL ///< ddr_encrypt NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_DDR_ENCRYPT_TARG 5UL ///< ddr_encrypt_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_DDR_TARG0 6UL ///< ddr_targ0 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_DDR_TARG1 7UL ///< ddr_targ1 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_DDR_TARG_CFG 8UL ///< ddr_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_ENET_EP 9UL ///< enet_ep NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_ENET_EP_TARG_CFG 10UL ///< enet_ep_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_ENET_SWR 11UL ///< enet_swr NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_ENET_SWR_TARG 12UL ///< enet_swr_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_ENET_SWR_TARG_CFG 13UL ///< enet_swr_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_IOMMU 14UL ///< iommu NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_IOMMU_TARG_CFG 15UL ///< iommu_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_M2 16UL ///< m2 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_M2_TARG 17UL ///< m2_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_M2_TARG_CFG 18UL ///< m2_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_M3 19UL ///< m3 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_M3_TARG 20UL ///< m3_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_M3_TARG_CFG 21UL ///< m3_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_NVM 22UL ///< nvm NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_NVM_TARG 23UL ///< nvm_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_NVM_TARG_CFG 24UL ///< nvm_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_PCIE_0 25UL ///< pcie_0 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_PCIE_0_TARG 26UL ///< pcie_0_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_PCIE_0_TARG_CFG 27UL ///< pcie_0_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_PCIE_1 28UL ///< pcie_1 NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_PCIE_1_TARG 29UL ///< pcie_1_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_PCIE_1_TARG_CFG 30UL ///< pcie_1_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_USER_CRYPTO 31UL ///< user_crypto NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_USER_CRYPTO_TARG 32UL ///< user_crypto_targ NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_NIU_USER_CRYPTO_TARG_CFG 33UL ///< user_crypto_targ_cfg NIU
#define APP_NOC_FA_FAULT_SOURCE_IDX_CFG_TRANSPORT 34UL ///< cfg_transport
#define APP_NOC_FA_FAULT_SOURCE_IDX_SVC 35UL ///< svc
#define APP_NOC_FA_FAULT_SOURCE_IDX_TRANSPORT_HIGH0 36UL ///< transport_high0
#define APP_NOC_FA_FAULT_SOURCE_IDX_TRANSPORT_HIGH1 37UL ///< transport_high1
#define APP_NOC_FA_FAULT_SOURCE_IDX_TRANSPORT_MAIN 38UL ///< transport_main
#define APP_NOC_FA_FAULT_SOURCE_IDX_TRANSPORT_SMF_EAST 39UL ///< transport_smf_east
#define APP_NOC_FA_FAULT_SOURCE_IDX_TRANSPORT_SMF_WEST 40UL ///< transport_smf_west
#define APP_NOC_FA_FAULT_SOURCE_IDX_TRANSPORT_SMF_WEST_TARG 41UL ///< transport_smf_west_targ

/**
 * @brief app_noc_fa CPER section data description
 */
typedef struct {
    uint32_t event; ///< AppC NoC fault aggregator event type
    uint8_t fault_source_idx; ///< Error source instance identifier
} app_noc_fa_section_t;

/*********************************************
* SVC_NOC CPER Section
********************************************/

#define SVC_NOC_EVENT_NO_EVENT 0UL ///< No event
#define SVC_NOC_EVENT_FLT_SECDED_CORR_EVENT 1UL ///< FLT SECDED correctable error event
#define SVC_NOC_EVENT_FLT_SECDED_UNCORR_EVENT 2UL ///< FLT SECDED uncorrectable error event
#define SVC_NOC_EVENT_PKT_VALID_FAULT_EVENT 3UL ///< packet validity fault event
#define SVC_NOC_EVENT_CTRL_REG_PAR_EVENT 4UL ///< control register parity error event
#define SVC_NOC_EVENT_TIMEOUT_EVENT 5UL ///< Initiator NIU timeout event
#define SVC_NOC_EVENT_FSM_ERROR_EVENT 6UL ///< Internal FSM error event
#define SVC_NOC_FAULT_SOURCE_IDX_SYS_CTRL_I_NIU 0UL ///< sys_ctrl Initiator NIU
#define SVC_NOC_FAULT_SOURCE_IDX_ACSU_GRP0_T_NIU 1UL ///< acsu_grp0 Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_ACSU_GRP1_T_NIU 2UL ///< acsu_grp1 Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_APP_GRP_T_NIU 3UL ///< app_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_APP_NOC_SERVICE_T_NIU 4UL ///< app_noc_service Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_CRYPTO_GRP_T_NIU 5UL ///< crypto_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_DDR_GRP_T_NIU 6UL ///< ddr_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_EDGE_B_T_NIU 7UL ///< edge_b Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_ENC_GRP_T_NIU 8UL ///< enc_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_EP_GRP_T_NIU 9UL ///< ep_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_M1_GRP_T_NIU 10UL ///< m1_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_M3_T_NIU 11UL ///< m3 Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_NVM_GRP_T_NIU 12UL ///< nvm_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_PCIE_CXL0_T_NIU 13UL ///< pcie_cxl0 Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_PCIE_CXL1_T_NIU 14UL ///< pcie_cxl1 Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_PCIE_GRP_T_NIU 15UL ///< pcie_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_SVC_NOC_SERVICE_T_NIU 16UL ///< svc_noc_service Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_SWR_GRP_T_NIU 17UL ///< swr_grp Target NIU
#define SVC_NOC_FAULT_SOURCE_IDX_TOP_AGG_POWER_MAIN 18UL ///< power_main Top fault aggregator

/**
 * @brief svc_noc CPER section data description
 */
typedef struct {
    uint32_t event; ///< SVC NoC fault aggregator event type
    uint8_t fault_source_idx; ///< Error source instance identifier
} svc_noc_section_t;

/*********************************************
* PCXL_CTRL CPER Section
********************************************/

#define PCXL_CTRL_EVENT_NO_EVENT 0UL ///< No event
#define PCXL_CTRL_EVENT_ECC_CORR 1UL ///< ECC correctable error event
#define PCXL_CTRL_EVENT_ECC_UNCORR 2UL ///< ECC uncorrectable error event
#define PCXL_CTRL_CTRL_ID_INST_0 0UL ///< Controller instance 0
#define PCXL_CTRL_CTRL_ID_INST_1 1UL ///< Controller instance 1
#define PCXL_CTRL_CTRL_ID_NO_INST 2UL ///< No controller instance

/**
 * @brief pcxl_ctrl CPER section data description
 */
typedef struct {
    uint32_t event; ///< PCIE CXL controller event type
    uint8_t ctrl_id; ///< Error source instance identifier
} pcxl_ctrl_section_t;

/*********************************************
* PCXL_LINK CPER Section
********************************************/

#define PCXL_LINK_EVENT_NO_EVENT 0UL ///< No event
#define PCXL_LINK_EVENT_FATAL 1UL ///< Fatal event
#define PCXL_LINK_EVENT_NON_FATAL 2UL ///< Non-fatal event
#define PCXL_LINK_LINK_ID_SLICE_0_INST_0 0UL ///< Slice 0 Link instance 0
#define PCXL_LINK_LINK_ID_SLICE_0_INST_1 1UL ///< Slice 0 Link instance 1
#define PCXL_LINK_LINK_ID_SLICE_1_INST_0 2UL ///< Slice 1 Link instance 0
#define PCXL_LINK_LINK_ID_SLICE_1_INST_1 3UL ///< Slice 1 Link instance 1
#define PCXL_LINK_LINK_ID_NO_INST 4UL ///< No link instance

/**
 * @brief pcxl_link CPER section data description
 */
typedef struct {
    uint32_t event; ///< PCIE CXL link event type
    uint8_t link_id; ///< Error source instance identifier
} pcxl_link_section_t;

/**
 * @brief CPER section data union
 */
typedef union {
    memory_section_t mem_section; ///<  mem_err CPER section type
    pcie_section_t pcie_section; ///<  pcie CPER section type
    csu_section_t csu_section; ///< csu CPER section type
    ocr_section_t ocr_section; ///< ocr CPER section type
    pqs_section_t pqs_section; ///< pqs CPER section type
    sec_noc_section_t sec_noc_section; ///< sec_noc CPER section type
    cmon_section_t cmon_section; ///< cmon CPER section type
    tamper_mon_section_t tamper_mon_section; ///< tamper_mon CPER section type
    mesh_section_t mesh_section; ///< mesh CPER section type
    proc_section_t proc_section; ///< proc CPER section type
    wdog_section_t wdog_section; ///< wdog CPER section type
    ana_mon_section_t ana_mon_section; ///< ana_mon CPER section type
    boot_itr_section_t boot_itr_section; ///< boot_itr CPER section type
    dma_section_t dma_section; ///< dma CPER section type
    tvs_mon_section_t tvs_mon_section; ///< tvs_mon CPER section type
    riscv_proc_section_t riscv_proc_section; ///< riscv_proc CPER section type
    app_noc_section_t app_noc_section; ///< app_noc CPER section type
    app_wdog_section_t app_wdog_section; ///< app_wdog CPER section type
    sram_edac_section_t sram_edac_section; ///< sram_edac CPER section type
    nvm_edac_section_t nvm_edac_section; ///< nvm_edac CPER section type
    fw_err_section_t fw_err_section; ///< fw_err CPER section type
    intr_storm_section_t intr_storm_section; ///< intr_storm CPER section type
    enet_sw_section_t enet_sw_section; ///< enet_sw CPER section type
    pflash_ctrl_section_t pflash_ctrl_section; ///< pflash_ctrl CPER section type
    ddr_edac_section_t ddr_edac_section; ///< ddr_edac CPER section type
    spi_ctrl_section_t spi_ctrl_section; ///< spi_ctrl CPER section type
    nand_ctrl_section_t nand_ctrl_section; ///< nand_ctrl CPER section type
    ddr_ctrl_section_t ddr_ctrl_section; ///< ddr_ctrl CPER section type
    ddr_phy_section_t ddr_phy_section; ///< ddr_phy CPER section type
    ddr_hsio_section_t ddr_hsio_section; ///< ddr_hsio CPER section type
    spw_ctrl_section_t spw_ctrl_section; ///< spw_ctrl CPER section type
    sys_dbg_section_t sys_dbg_section; ///< sys_dbg CPER section type
    enet_ep_sb_section_t enet_ep_sb_section; ///< enet_ep_sb CPER section type
    enet_ep_core_section_t enet_ep_core_section; ///< enet_ep_core CPER section type
    enet_ep_frer_tx_section_t enet_ep_frer_tx_section; ///< enet_ep_frer_tx CPER section type
    enet_ep_frer_rx_section_t enet_ep_frer_rx_section; ///< enet_ep_frer_rx CPER section type
    sys_noc_fa_section_t sys_noc_fa_section; ///< sys_noc_fa CPER section type
    noc_obs_section_t noc_obs_section; ///< noc_obs CPER section type
    ddr_noc_section_t ddr_noc_section; ///< ddr_noc CPER section type
    hpt_section_t hpt_section; ///< hpt CPER section type
    app_noc_fa_section_t app_noc_fa_section; ///< app_noc_fa CPER section type
    svc_noc_section_t svc_noc_section; ///< svc_noc CPER section type
    pcxl_ctrl_section_t pcxl_ctrl_section; ///< pcxl_ctrl CPER section type
    pcxl_link_section_t pcxl_link_section; ///< pcxl_link CPER section type
} p64h_cper_section_t;


/* Public Structs and Enums - static ------------------------------------ */

#endif /* CPER_SECTIONS_H */