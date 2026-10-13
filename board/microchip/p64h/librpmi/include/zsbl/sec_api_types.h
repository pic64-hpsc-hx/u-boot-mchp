/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines types common for SMB & JMB commands
 */
#ifndef SEC_API_TYPES_H
#define SEC_API_TYPES_H

#include "scratchreg.h"
#include "sec_crypto_types.h" // for ECDSA_SIG_SIZE_BYTES_DER

#define NUM_SW_LOCKS            64u   ///< number of SW locks
#define NUM_HW_LOCKS            8u    ///< number of HW locks
/// DSN length in words
#define DSN_DWORD_LEN           2u
#define SCAC_SIZE_WORDS         2239u    ///< Total word size to contain 3 SCACs

/// bit 7 in options field of the standard header in case of secc BITS component
#define SEC_FSBL_MASK                 (1u << 7u) ///< secc FSBL verify bit mask


/**
 * @brief
 *  Error codes returned after invoking the system service APIs that are common for SMB & JMB
 */ 
typedef enum sec_ret_code_e
{
    SEC_NO_ERROR = 0,           ///< Crypto service returned success
    SEC_MBOX_REQ_TIMEOUT_ERR,   ///< Service request timed out
    SEC_MBOX_SEND_ERROR,        ///< Mbox send command failed
    SEC_MBOX_RECV_ERROR,        ///< Mbox response reception failed due to time out
    SEC_MBOX_BUSY,              ///< Mbox is busy so can't R/W Mbox RAM
    SEC_MBOX_INVALID_RESP,      ///< Indicates that there is no valid response available
    SEC_MBOX_WRITE_FAIL,        ///< SecC attempted Mbox write beyond MBOX_MAX_BUFF_SIZE
    SEC_MBOX_READ_FAIL,         ///< SecC attempted Mbox read  beyond MBOX_MAX_BUFF_SIZE
    SEC_SMB_WRITE_FAIL,         ///< SysC attempted Mbox write beyond MBOX_MAX_BUFF_SIZE
    SEC_SMB_READ_FAIL,          ///< SysC attempted Mbox read beyond MBOX_MAX_BUFF_SIZE
    SEC_CMD_MISMATCH,           ///< command integrity failure
    SEC_CMD_UNSUPPORTED,        ///< unsupported command
    SEC_DATA_INTEGRITY_ERROR,   ///< Data mismatch
    SEC_CMD_ABORTED,            ///< Service command aborted
    SEC_CMD_ERROR,              ///< Used to abstract security failure reporting to user
    SEC_IMG_HEADER_XFER_FAILED, ///< Image Header transfer failed
	SEC_GET_LOG_FAIL,           ///< Failed to transfer the log buffer
    SEC_IMAGE_VERIFY_FAIL,      ///< Image verification failed
    SEC_OTP_BUSY_CMD_BLOCK_ERROR,  ///< otp_busy bit never cleared and command could not be executed
    SEC_OTP_BUSY_CMD_COMPLETION_ERROR, ///< otp_busy never cleared after executing the command
    SEC_OTP_ECC_ERROR,             ///< accessed location has ECC error (give it a second attempt)
    SEC_OTP_DISALLOWED_MODE_ERROR, ///< disallowed mode (give it a second attempt)
    SEC_OTP_DISALLOWED_ADDR_ERROR, ///< disallowed addr (give it a second attempt)
    SEC_OTP_INVALID_MODE_ERROR,    ///< invalid mode (give it a second attempt)
    SEC_OTP_RESULT_FAIL_ERROR,     ///< OTP_RESULT tripped and otp read/write interface is down
    SEC_OTP_ECC_WRITE_ERROR,       ///< OTP ECC Region address already written, cannot be written again
    SEC_OTP_TMR_WRITE_ERROR,       ///< OTP TMR Region, destination address contains a bit set to 1 that is requested setting to 0
    SEC_OTP_NO_ACTIVE_BOOTCFG_SEL,///< No valid Boot config vector present
    SEC_OTP_BOOTCFG_ENTRIES_FULL, ///< Boot config saturated
    SEC_OTP_BLANKCHECK_ERR,     ///< OTP contains partially programmed data
    SEC_OTP_BOOTCFG_STATS_ERROR,   ///< Boot config stats write failed or corrupted
    SEC_OTP_BOOTCFG_STATS_RD_ERROR,///< Error Fetching boot config stats from OTP
    SEC_OTP_BOOTCFG_DATA_ERROR,    ///< boot config DATA write failed or corrupted
    SEC_OTP_BOOTCFG_DATA_RD_ERROR, ///< Error reading boot config from OTP
    SEC_OTP_BOOTCFG_CMD_FAIL,      ///< Boot config command execution failed
    SEC_SIG_VERIFY_CMD_DMA_FAIL,   ///< Signature verification data transfer failed
    SEC_EC_HASHSET_VERIFY_FAIL,   ///< No matching EC keys hashes present
    SEC_PQ_HASHSET_VERIFY_FAIL,   ///< No matching PQ keys hashes present
    SEC_SIG_VERIFY_CMD_FAIL,   ///< Signature verification command failed
    SEC_MEM_SCRUB_FAIL,        ///< memory scrubbing operation failed
    SEC_SWITCH_BOOT_MODE_FAIL, ///< unable to switch boot mode
    SEC_BURNIN_KEY_INVALIDATION_FAILED, ///< Burn-in key invalidation failed
    SEC_BURNIN_KEY_DECRYPT_FAIL, ///< Burn-in key decrypt failed
    SEC_GET_TVS_MON_DATA_FAIL,    ///< Failed to transfer the log buffer
    SEC_CMD_PQ_BOOT_ENFORCED,     ///< PQ boot enforced,
    SEC_CMD_SYSC_IMAGE_SIGN_VERIFY_ENFORCED, ///< sysc image signature verification is enforced by image is not signed
    SEC_CMD_SYSC_IMAGE_ENCRYPTION_ENFORCED,  ///< sysc image encryption enforced but sysc image is not encrypted
    SEC_DECRYPTED_BLOCK_TRANSFER_FAIL, ///< Failed to transfer over decrypted block
    SEC_PUF_USR_PUF_DISTRIBUTION_FAILED, ///< User PUF distribution failed
    SEC_PUF_USER_PUF_AC_GEN_FAILED, ///< User PUF AC generation failed
    SEC_PUF_USER_PUF_AC_READ_FAILED, ///< User PUF AC read failed
    SEC_OTP_RESET_FAIL_ERROR, ///< Attempt to reset otp after OTP_RESULT fell to 0 failed.
    SEC_CMD_INVALID_BURNINKEY_STATE, ///< Command cannot be executed as invalid burnin key state
    SEC_OTP_BOOTCFG_INTEGRITY_ERR,///< Mismatched BootCfg provided in CMD_TEST/COMMIT_BOOTCFG
} sec_ret_code_e;

/**
 * @brief Combined Command List for Common Crypto Services, System MailBox, and Jtag MailBox
 *
 */
typedef enum sec_cmd_req_e
{
    // Common Crypto Services Command list for SMB & JMB
    SEC_CMD_CRYPTO_READY = 0,   ///< mbox handshake command
    SEC_CMD_CRYPTO_DWNLD_KEYS,  ///< Download plain text keys
    SEC_CMD_DOWNLOAD_COMPONENT, ///< Validate components
    SEC_CMD_DSN_GET,            ///< Get Serial Number of the device
    SEC_CMD_COMP_VERIFY,        ///< verify the component(BITS, KEYS, ..)
    SEC_CMD_GET_BOOTCFG,        ///< Retrieve Boot config params from OTP
    SEC_CMD_TEST_BOOTCFG,       ///< Test flash with temp boot configs
    SEC_CMD_COMMIT_BOOTCFG,     ///< Commit Temp boot cfg into OTP
    SEC_CMD_LOAD_CERT_CHAIN,    ///< Load MCHP HSM ECDSA & PQDSA certificate chains    
    SEC_CMD_VALIDATE_FW,        ///< Validate the firmware version    
    SEC_CMD_QUERY_SECURITY,     ///< User Security Policy attestation report
    SEC_CMD_GET_LOG,            ///< Transfer the log into SysCtrl memory/JMB
    SEC_CMD_DIAG_GET,           ///< Get SecC Diagnostics data
    SEC_CMD_DMA_SELF_TEST,      ///< SecC DMA Test
    SEC_CMD_GET_OTP_PE_DATA,    ///< Transfer the otp PE data into SysCtrl memory/JMB
    SEC_CMD_READ_SCAC_CERT,     ///< read SCAC certificate

    // System MailBox Command List
    SEC_CMD_ALIVE_MSG,            ///< sysc/secc health check
    SEC_CMD_ENTER_CRITICAL_PHASE, ///< Do not issue system reset when failures are detected in sysc/secc
    SEC_CMD_EXIT_CRITICAL_PHASE,  ///< Reset critical phase state
    SEC_CMD_MEMORY_SCRUB,         ///< Scrub Memory
    SEC_CMD_CLOCK_ADJUST,         ///< Adjust acsu clock parameters
    SEC_CMD_SIGNATURE_VERIFY,     ///< EC and/or PQ Signature verification
    SEC_CMD_FLASH_HDR_SIGNATURE_VERIFY, ///< Flash header signature verification
    SEC_CMD_GET_PERIPH_STATS,     ///< Transfer the peripheral status into SysCtrl memory
    SEC_CMD_GET_TVS_MON_DATA,     ///< reports the Temperature and Voltage readings of SecC 
    SEC_CMD_GENERATE_USER_ROOT_KEY_AC, ///< Generate the user root key activation key
    SEC_CMD_DISTRIBUTE_USER_ROOT_KEY, ///< Distribute the user root key to user crypto
    SEC_CMD_POWER_OFF_PUF,          ///< Power off the PUF after user crypto root key distribution
    SEC_CMD_M1_MISC_FEATURE_SET,     ///< Set the M1 misc scratch register.

    // Jtag MailBox Command List
    SEC_CMD_JTAG_REQ_VIRGIN_DEV_ACCESS,    ///< 1st stage FSL unlock access command
    SEC_CMD_JTAG_ENABLE_VIRGIN_DEV_ACCESS, ///< 2nd stage FSL unlock access command
    SEC_CMD_JTAG_REQ_FW_ACCESS,            ///< ROM override request
    SEC_CMD_JTAG_ENABLE_FW_ACCESS,         ///< 2nd stage of ROM override
    SEC_CMD_JTAG_FW_DWNLD_INIT,            ///< Download FW image header
    SEC_CMD_JTAG_FW_DWNLD_VERIFY,          ///< ROM override, FW download & verify
    SEC_CMD_JTAG_FACTORY_ENROLL,           ///< Factory provisioning command
    SEC_CMD_JTAG_INIT_FACTORY_ACCESS,      ///< Initializes the Factory One-Time Passcode protocol
    SEC_CMD_JTAG_REQ1_FACTORY_ACCESS,      ///< 1st stage One-Time Passcode protocol
    SEC_CMD_JTAG_REQ2_FACTORY_ACCESS,      ///< 2nd stage One-Time Passcode protocol
    SEC_CMD_JTAG_ENABLE_FACTORY_ACCESS,    ///< Unlock FPK(FSL/SEC_JTAG_LOCK are both controlled)
    SEC_CMD_JTAG_GEN_OTK,                  ///< Generates OTK, later used to decrypt FKEYS
    SEC_CMD_JTAG_NEXT_BOOT_MODE,           ///< Switch to the next boot mode
    SEC_CMD_JTAG_OTP_BLANK_CHECK,          ///< OTP blank check 

    LAST_SEC_CMD,                  ///< Final cmd for crypto service
} sec_cmd_req_e;

/// ROM firmware version
typedef struct fw_version_t
{
    uint8_t major_num:8; ///< Silicon Version e.g. A0, B0...
    uint8_t minor_num:8; ///< customer or big patches version
    uint8_t patch_num:8; ///< patch version
    uint8_t rsvd1:8;     ///< reserved
}fw_version_t;


/**
 * @brief
 *  FW attestation data returned by the device for VALIDATE_FW command
 *
 */
typedef struct {

    struct {
        uint8_t dsn[16];   ///< Device Serial Number
        uint8_t nuser[16]; ///< User nonce
        uint8_t nfpga[16]; ///< Device nonce
        uint8_t tfwver;    ///< FW tag version
        uint8_t rsvd0[3];  ///< dword(8-byte) alignment
        uint32_t patch_cnt; ///< total number patches present in OTP, max is 256
        fw_version_t fwver; ///< current ROM FW version
        uint32_t rsvd1;     ///< reserved for dword alignment
        fw_version_t patches_ver[256]; ///< Patch versions of each of the available patch
        uint8_t fwhash[48];  ///< FWHASH = SHA3-384(SEC_ROM || SYS_ROM || TOTAL_PATCHCT)
    } msg;

    uint8_t sigec[ECDSA_SIG_SIZE_BYTES_DER];
    uint8_t sigpq[PQS_MLDSA87_SIGN_SIZE_DER];

} cmd_validate_fw_out_t;

/**
 * @brief OTP blank check command structure
*/
typedef struct {
    uint32_t otp_start_offset; ///< offset in OTP
    uint32_t size_in_bytes;    ///< Number of bytes to check 
} sec_otp_blank_check_t;


/**
 * @brief Memory Scrub Target
*/
typedef enum {
    SCRUB_ICACHE   = 0x01U, ///< ITIM cache
    SCRUB_ITIM     = 0x02U, ///< SecC ITIM RAM (only supports demand scrubbing). ITIM ROM i.e. first 256 KiB of ITIM are not be scrubbed, offset will be from ITIM RAM base address)
    SCRUB_DTIM     = 0x03U, ///< SecC DTIM (supports demand and patrol scrubbing)
    SCRUB_SEC_OCR  = 0x04U, ///< SecC OCR (supports demand and patrol scrubbing)
    SCRUB_PQ_OCR   = 0x05U,  ///< PQ OCR (supports patrol scrubbing)
    SCRUB_PQ_RAM   = 0x06U,  ///< PQ RAM (supports patrol scrubbing)

} scrub_mem_type_t;

/**
 * @brief Memory Scrub cmd
*/
typedef enum {
    CACHE_SCRUB      = 0x01U,  /// scrub ICACHE based on scrub_mem_type_t
    DEMAND_SCRUB     = 0x02U,  ///< memory scrubbing is done by sw read/write calls to memory 
    PATROL_SCRUB_EN  = 0x03U,  ///< enable patrol scrubbing (scrubbing done periodically by hw scrubber)
    PATROL_SCRUB_DIS = 0x04U,  ///< disable patrol scrubbing
} scrub_cmd_t;

/**
 * @brief Memory Scrub cfg
*/
typedef struct {
                                   /// Demand scrubbing parameters
    uint32_t scrub_offset;         ///< perform memory access at this address offset in the target memory. Offset is in bytes. Offset must be word (8 bytes) aligned.
    uint32_t scrub_size;           ///< perform memory access of this size in memory, size is in bytes, size must be word (8 bytes) aligned.
                                   /// Patrol scrubbing parameters
    uint32_t patrol_scrub_period;  ///< Auto-scrub period in aclk cycles. 
                                   /// FOR DTIM, SEC_OCR and PQ_OCR, period is 28 bits. For PQ_RAM, period is 16 bits.
} scrub_cfg_t;

/**
 * @brief Memory Scrub payload
*/
typedef struct {
    scrub_mem_type_t mem_type; ///< memory type to scrub
    scrub_cmd_t      cmd;      ///< patrol scrub or demard scrub   
    scrub_cfg_t      cfg;      ///< memory scrub cfg parameters
} sec_mem_scrub_t;

/// beu stat
typedef struct {
    uint64_t cause;  ///< Cause of error event
    uint64_t value;  ///< Physical address of error event
} sec_beu_stat_t;

/**
 * @brief Type of access that generated the error for the entry in the Memory Error Logger FIFO.
 * 
 */
typedef enum {
    mel_fifo_entry_cmd_null  = 0x01U, ///< Not a valid command/entry
    mel_fifo_entry_cmd_write = 0x02U, ///< Write access generated from an AXI transaction to the memory.
    mel_fifo_entry_cmd_read  = 0x03U, ///< Read access generated from an AXI transaction to the memory.
    mel_fifo_entry_cmd_scrub = 0x04U, ///< Patrol or Self scrub access to the memory.
} mel_fifo_entry_cmd_t;

/**
 * @brief 
 *  Error type of the entry in the Memory Error Logger FIFO.
 */
typedef struct {
    uint32_t mel_entry_type_no_err:1;  ///< no error present
    uint32_t mel_entry_type_slverr:1;  ///<  Subordinate Error (SLVERR), it is generated due to the following reasons:
                                            //- The memory block accessed was unavailable/didn't exist at the time of the transaction.
                                            //- During a write burst, a beat accessed an unavailable address.
                                            //- There is an uncorrectable error and the data is corrupted.
                                            //- During an RMW read, an uncorrectable error was detected
    uint32_t mel_entry_type_c_ecc:1;   ///< There is a correctable error in the RAM, read data is corrected and the RAM address is scheduled for a scrub.
    uint32_t mel_entry_type_u_ecc:1;   ///< There is an uncorrectable error in the RAM, read data is invalid.
    uint32_t mel_entry_type_unav:1;    ///<  Unavailable Access Error 
    uint32_t padding:27;                 ///< unsued
} mel_entry_type_t;


/**
 * @brief Each group represents the N 32b group of the read word.
 *        Value decoding:
 *        1: No error detected.
 *        2 : Correctable error detected.
 *        3 : Uncorrectable error detected.
 * 
 */
typedef struct {    
    uint32_t mel_entry_ecc_0:2;  ///< ECC bits of group 0
    uint32_t mel_entry_ecc_1:2;  ///< ECC bits of group 1
    uint32_t mel_entry_ecc_2:2;  ///< ECC bits of group 2
    uint32_t mel_entry_ecc_3:2;  ///< ECC bits of group 3
    uint32_t mel_entry_ecc_4:2;  ///< ECC bits of group 4
    uint32_t mel_entry_ecc_5:2;  ///< ECC bits of group 5
    uint32_t mel_entry_ecc_6:2;  ///< ECC bits of group 6
    uint32_t mel_entry_ecc_7:2;  ///< ECC bits of group 7
    uint32_t padding:16;         ///< unsued
} mel_entry_ecc_t;

/**
 * @brief Memory Error Logger (MEL) Entry in FIFO
 * 
 */
typedef struct {
    uint32_t mel_fifo_entry_addr;  ///< Word address of the error in the Memory Error Logger FIFO entry.
    mel_entry_type_t mel_fifo_entry_type;  ///< Error type of the entry in the Memory Error Logger FIFO (see mel_fifo_entry_type_t)
    mel_fifo_entry_cmd_t mel_fifo_entry_cmd;  ///< Type of access that generated the error for the entry in the Memory Error Logger FIFO (see mel_fifo_entry_cmd_t)
    mel_entry_ecc_t mel_entry_ecc; ///< In case of a C_ECC and/or U_ECC, this mel_entry_ecc can be used to determine which 32b ECC protected data groups suffered correctable and/or uncorrectable errors (see mel_entry_ecc_t)
} mel_fifo_entry_t;


/**
 * @brief stat about OCR Memory Error Logger
 * 
 */
typedef struct {
    uint32_t mel_fill_level;         ///< Fill level of the memory error logger FIFO (fill level is reported after a FIFO read is done)
    uint32_t mes_fill_level;         ///< Fill level of the memory error scrubber FIFO.
    uint32_t mel_entry_valid;        ///< FIFO had a valid entry that has been read into mel_fifo_entry)
    mel_fifo_entry_t mel_fifo_entry; ///< Memory error logger entry read from top of FIFO
} ocr_mem_mel_t;


typedef struct {
    uint32_t mel_overflow_int:1;   ///< Interrupt trigger upon overflow of the memory error logger FIFO
    uint32_t mes_overflow_int:1;   ///< Interrupt trigger upon overflow of the memory error scrubber FIFO
    uint32_t r_xoff_int:1;         ///< Interrupt trigger upon read response buffer XOFF state change
    uint32_t r_xoff_val:1;         ///< Read response buffer XOFF status bit.
    uint32_t r_underflow_int:1;    ///< Interrupt trigger upon underflow of the read response buffer FIFO
    uint32_t r_overflow_int:1;     ///< Interrupt trigger upon overflow of the read response buffer FIFO
    uint32_t b_xoff_int:1;         ///< Interrupt trigger upon Write response buffer XOFF state change
    uint32_t b_xoff_val:1;         ///< Write response buffer XOFF status bit.
    uint32_t b_underflow_int:1;    ///< Interrupt trigger upon underflow of the write response buffer FIFO
    uint32_t b_overflow_int:1;     ///< Interrupt trigger upon overflow of the write response buffer FIFO
    uint32_t unavail_acc_int:1;    ///< Interrupt triggered upon memory access to a memory range marked as unavailable
    uint32_t ocr_mem_c_err_int_int:1; ///< OCR Memory correctable ECC error was detected on a read action
    uint32_t ocr_mem_u_err_int_int:1; ///< OCR Memory uncorrectable ECC error was detected on a read action
    uint32_t padding:19;              ///< unsued
} ocr_mem_int_t;

typedef struct {
    ocr_mem_mel_t ocr_mem_mel; ///< OCR Memory Error Logger stat 
    ocr_mem_int_t ocr_mem_int; ///< OCR Memory interrupts Value
} ocr_mem_stats_t;


// run puf_test: qk_test_puf()
typedef struct {
    uint32_t  puf_score;             /*!< [out] Pointer to byte that will hold the PUF score for the SRAM PUF. */
    uint32_t  bus_keeper_puf_score;  /*!< [out] Pointer to byte that will hold the PUF score for the Bus Keeper PUF. */
} sec_puf_stat_t;


// not sure yet if we want this
typedef struct {
    //uint8_t  self_test_status;      ///< self test status 
    uint32_t skc_intropts_done:1;    ///< SKC interrupt for transaction done
    uint32_t skc_intropts_bresp:1;   ///< SKC interrupt for write resp
    uint32_t skc_intropts_rresp:1;   ///< SKC interrupt read resp
    uint32_t padding:29;             ///< unsued
} sec_skc_stat_t;


typedef struct {
    uint32_t pqs_status;
} sec_pq_stat_t;

// OTP STATUS
typedef struct {
    uint32_t ecc_single_err:1; ///< ECC single bit error has occurred
    uint32_t ecc_double_err:1; ///< ECC double bit error has occurred
    uint32_t opt_error:1;      ///< This bit is sticky and stays 0 once OTP controller detects error.
    uint32_t otp_disallowed_mode:1; ///< The last command was not executed because it is disabled by the otp_disable_reread or otp_disable_test ports.
    uint32_t otp_disallowed_addr:1; ///< The last command was not executed because the attempted address is not allowed
                                    // due to settings of the otp_disable_burn, otp_disable_erase, otp_disable_jtag_read, or otp_disable_pcbi_read ports.     
    uint32_t padding:27;            ///< unsued                        
} sec_otp_stat_t;

typedef struct {
    uint32_t sec_m1_noc_t_timeout:1;        ///< Secure Controller registers in M1 target timeout status.
    uint32_t sec_acsu_noc_t_timeout:1;      ///< Secure Controller ACSU target timeout status.
    uint32_t dtim_ocr_noc_t_timeout:1;      ///< DTIM OCR configuration registers target timeout status.
    uint32_t wdog_noc_t_timeout:1;          ///< Wdog (NOC) target timeout status.
    uint32_t timers_noc_t_timeout:1;        ///< Timer (NOC) target timeout status.
    uint32_t sha3_noc_t_timeout:1;          ///< SHA3_KECCAK (NOC) target timeout status.
    uint32_t sec_reg_noc_t_timeout:1;       ///< SecReg (NOC) target timeout status.
    uint32_t sec_mbox_noc_t_timeout:1;      ///< Sec_Mbox (NOC) target timeout status.
    uint32_t sec_dma_ctrl_noc_t_timeout:1;  ///< Sec_DMA Controller (NOC) target timeout status.
    uint32_t pq_crypto_cfg_noc_t_timeout:1; ///< PQ Subordinator (NOC) target timeout status.
    uint32_t pqcs_csif_noc_t_timeout:1;     ///< PQ Manager (NOC) target timeout status.
    uint32_t otp_noc_t_timeout:1;           ///< OTP (NOC) target timeout status.
    uint32_t ocr_data_noc_t_timeout:1;      ///< OCR Data (NOC) target timeout status.
    uint32_t ocr_ctrl_noc_t_timeout:1;      ///< OCR Controller (NOC) target timeout status.
    uint32_t jtag_mbox_noc_t_timeout:1;     ///< JTAG Mbox (NOC) target timeout status.
    uint32_t skc_cs_noc_t_timeout:1;        ///< Crypto Engine Control & Status (NOC) target timeout status.
    uint32_t cpu_frnt_noc_t_timeout:1;      ///< CPU Front Port (NOC) target timeout status.
    uint32_t boot_noc_t_timeout:1;          ///< Boot ROM (NOC) target timeout status
    uint32_t sec_noc_config_t_timeout:1;    ///< SEC_NOC Configuration (NOC) target timeout status.
    uint32_t skc_sha_dma_noc_i_timeout:1;   ///< Crypto Engine SHA DMA (NOC) initiator timeout status.
    uint32_t skc_sha3_dma_noc_i_timeout:1;  ///< Crypto Engine SHA3 DMA (NOC) initiator timeout status.
    uint32_t skc_aes_dma_noc_i_timeout:1;   ///< Crypto Engine AES DMA (NOC) initiator timeout status.
    uint32_t sec_dma_data_noc_i_timeout:1;  ///< Sec_DMA Data (NOC) initiator timeout status.
    uint32_t cpu_sys_noc_i_timeout:1;       ///< CPU System Port (NOC) initiator timeout status.
    uint32_t noc_mainbistfail:1;            ///< NOC BIST fail status.
    uint32_t noc_mainlatentint:1;           ///< NOC latent interrupt line status (indicating BIST DONE).
    uint32_t noc_mainminor:1;               ///< NOC mission minor interrupt line status.
    uint32_t noc_mainmajor:1;               ///< NOC mission major interrupt line status.
    uint32_t noc_mainmissionint:1;          ///< NOC mission interrupt line status.
    uint32_t padding:3;                     ///< unsued
} sec_reg_noc_int_stat_t;


typedef struct {
    uint32_t clkmon_stat_level:6;     ///< Reports the present clock monitor level value.
    uint32_t clkmon_stat_level_err:6; ///< Reports the clock monitor level value that was present at the moment of
                                      ///  the error event that triggered entry to the failed state.
    uint32_t clkmon_stat_code:9;     ///< bit  Reports the present clock monitor delay line tap configuration code value.
    uint32_t padding:11;              ///< unsued
} sec_clock_monitor_stat_t;



typedef struct {
    uint32_t clkmon_stat_act_v:1;    ///< the clock monitor is enabled in normal mode and either failed to complete initial calibration/lock
    uint32_t clkmon_stat_adj_v:1;    ///< the clock monitor is enabled in normal mode, completed initial delay line calibration, and in the active monitoring locked state.
    uint32_t clkmon_stat_locked_v:1; ///<  the clock monitor is enabled in normal mode and is in the recalibration adjustment state.
    uint32_t clkmon_stat_fail_v:1;   ///< the clock monitor is enabled in normal mode, completed initial delay line calibration, and presently in either
                                       // the active monitoring locked state (CLKMON_STAT_LOCKED_V3=1) or the recalibration adjustment state (CLKMON_STAT_ADJ_V3=1)
    uint32_t padding:28;              ///< padding
} sec_clock_monitor_int_val_t;

typedef struct {
    uint32_t clkmon_stat_act_i:1;    ///< The clock monitor initialization error event interrupt.
    uint32_t clkmon_stat_adj_i:1;    ///< The clock monitor adjustment error event interrupt.
    uint32_t clkmon_stat_locked_i:1;   ///< The clock monitor error event interrupt.
    uint32_t clkmon_stat_fail_i:1;     ///< The clock monitor failed state entry event interrupt.
    uint32_t clkmon_stat_err_i:1;      ///< The clock monitor locked sub-state entry event interrupt.
    uint32_t clkmon_stat_err_adj_i:1;  ///< The clock monitor adjustment sub-state entry event interrupt.
    uint32_t clkmon_stat_err_init_i:1; ///< bit  The clock monitor active state entry event interrupt.
    uint32_t padding:25;             ///< unsued
} sec_clock_monitor_int_stat_t;


typedef struct {
    uint32_t sec_mesh_err_v:1;         ///< SEC_CTRL mesh mismatch is detected.
    uint32_t sec_mesh_ok_v:1;          ///< Indicates that SEC_CTRL mesh monitor is armed and detecting no errors
    uint32_t usr_mesh_err_v:1;         ///< USR_CRYPTO mesh mismatch is detected.
    uint32_t usr_mesh_ok_v:1;          ///< Indicates that USR_CRYPTO mesh monitor is armed and detecting no errors
    uint32_t usr_mesh_power_gated_v:1; ///< Indicates that USR_CRYPTO mesh is power gated so the mesh monitor is disabled.
    uint32_t ddr_mesh_err_v:1;         ///< DDR_ENCRYPTOR mesh mismatch is detected.
    uint32_t ddr_mesh_ok_v:1;          ///< Indicates that DDR_ENCRYPTOR mesh monitor is armed and detecting no errors
    uint32_t ddr_mesh_power_gated_v:1; ///< Indicates that DDR_ENCRYPTOR mesh is power gated so the mesh monitor is disabled.
    uint32_t ana_mesh_err_v:1;         ///< ANALOG_TOP and PUF mesh mismatch is detected.
    uint32_t ana_mesh_ok_v:1;          ///< Indicates that ANALOG_TOP and PUF mesh monitor is armed and detecting no errors
    uint32_t padding:22;             ///< unsued
} sec_reg_mesh_int_val_t;

typedef struct {
    uint32_t sec_mesh_err_i:1;         ///< SEC_CTRL mesh mismatch is detected.
    uint32_t sec_mesh_ok_i:1;          ///< Indicates that SEC_CTRL mesh monitor is armed and detecting no errors
    uint32_t usr_mesh_err_i:1;         ///< USR_CRYPTO mesh mismatch is detected.
    uint32_t usr_mesh_ok_i:1;          ///< Indicates that USR_CRYPTO mesh monitor is armed and detecting no errors
    uint32_t usr_mesh_power_gated_i:1; ///< Indicates that USR_CRYPTO mesh is power gated so the mesh monitor is disabled.
    uint32_t ddr_mesh_err_i:1;         ///< DDR_ENCRYPTOR mesh mismatch is detected.
    uint32_t ddr_mesh_ok_i:1;          ///< Indicates that DDR_ENCRYPTOR mesh monitor is armed and detecting no errors
    uint32_t ddr_mesh_power_gated_i:1; ///< Indicates that DDR_ENCRYPTOR mesh is power gated so the mesh monitor is disabled.
    uint32_t ana_mesh_err_i:1;         ///< ANALOG_TOP and PUF mesh mismatch is detected.
    uint32_t ana_mesh_ok_i:1;          ///< Indicates that ANALOG_TOP and PUF mesh monitor is armed and detecting no errors
    uint32_t padding_i:22;             ///< unsued
} sec_reg_mesh_int_stat_t;

typedef struct {
    uint32_t hw_lock_tamper_v;                               ///< Asserted briefly upon any illegal write action to a HW_LOCK register, or asserted and stays asserted
                                                                // if the LOCK or UNLOCK fields of a HW_LOCK register is not in one of the valid values.
                                                               // Each bit index N corresponds to a single HW_LOCK register as follows:
                                                               // N=0: production_test_enable,
                                                               // N=1: sysc_debug_enable,
                                                               // N=2: appc_debug_enable,
                                                               // N=3: secc_debug_enable,
                                                               // N=4: otp_jtag_enable
    uint32_t sw_lock_tamper_v:1;                             ///< Asserted briefly upon any illegal write action to any SW_LOCK register, or asserted and stays asserted
                                                              // if the LOCK or UNLOCK fields of any SW_LOCK register is not in one of the valid values.
    uint32_t vstart_tamper_v:1;                              ///< Asserted if the hardware sticky-on-trstb virgin-start-unlock enable state is ENABLED but the corresponding OTP vstart fields indicate this should not have been enabled
                                                                // This is an unnatural state indicating a tamper or failure
    uint32_t hw_sticky_en_mismatch_perm_lock_prod_test_v:1;  ///< Asserted if the hardware sticky-on-trstb enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED.
                                                               // This is an unnatural state indicating a tamper or failure.
    uint32_t hw_sticky_en_mismatch_perm_lock_sysc_debug_v:1; ///< Asserted if the hardware sticky-on-trstb enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED.
                                                               // This is an unnatural state indicating a tamper or failure
    uint32_t hw_sticky_en_mismatch_perm_lock_appc_debug_v:1; ///< Asserted if the hardware sticky-on-trstb enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED.
                                                               // This is an unnatural state indicating a tamper or failure
    uint32_t hw_sticky_en_mismatch_perm_lock_secc_debug_v:1; ///< Asserted if the hardware sticky-on-trstb enable state is ENABLED but the corresponding OTP permanent lock setting decodes to LOCKED.
                                                               // This is an unnatural state indicating a tamper or failure
    uint32_t hw_sticky_en_tamper_prod_test_v:1;              ///< Asserted if the hardware sticky-on-trstb enable state is FAILED. This may occur if an incorrect enable value sequence was written to HW_STICKY_EN_SEQ_PROD_TEST,
                                                                // or if a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state.
    uint32_t hw_sticky_en_tamper_sysc_debug_v:1;             ///< Asserted if the hardware sticky-on-trstb enable state is FAILED. This may occur if an incorrect enable value sequence was written to HW_STICKY_EN_SEQ_SYSC_DEBUG,
                                                                // or if a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state.
    uint32_t hw_sticky_en_tamper_appc_debug_v:1;             ///< Asserted if the hardware sticky-on-trstb enable state is FAILED. This may occur if an incorrect enable value sequence was written to HW_STICKY_EN_SEQ_APPC_DEBUG,
                                                               // or if a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state.
    uint32_t hw_sticky_en_tamper_secc_debug_v:1;             ///< Asserted if the hardware sticky-on-trstb enable state is FAILED. This may occur if an incorrect enable value sequence was written to HW_STICKY_EN_SEQ_SECC_DEBUG,
                                                               // or if a hardware tamper corrupted the sticky-on-trstb enable state to an invalid state.
    uint32_t padding:22;                                     ///< padding
} sec_reg_tamper_int_val_t;

typedef struct {
    uint32_t hw_lock_tamper_i;                               ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t sw_lock_tamper_i:1;                             ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t vstart_tamper_i:1;                              ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_mismatch_perm_lock_prod_test_i:1;  ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_mismatch_perm_lock_sysc_debug_i:1; ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_mismatch_perm_lock_appc_debug_i:1; ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_mismatch_perm_lock_secc_debug_i:1; ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_tamper_prod_test_i:1;              ///< AEvent asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_tamper_sysc_debug_i:1;             ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_tamper_appc_debug_i:1;             ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t hw_sticky_en_tamper_secc_debug_i:1;             ///< Event asserted on rising-edge of the associated interrupt value signal
    uint32_t padding:22;                                     ///< padding
} sec_reg_tamper_int_stat_t;


typedef struct {
    uint32_t sec_mbox_ecc_err_c:1;        ///< Secure Controller Mailbox RAM correctable ECC error event interrupt.
    uint32_t jtag_mbox_ecc_err_c:1;       ///< JTAG Mailbox RAM correctable ECC error event interrupt.
    uint32_t sec_dma_ch_fifo_ecc_err_c:2; ///< Secure Controller DMA controller channel FIFO correctable ECC error event interrupt. Bit N is for DMA controller channel (N+1).
    uint32_t boot_rom_ecc_err_c:1;        ///< System Controller image Boot ROM correctable ECC error event interrupt.
    uint32_t s7_trace_ecc_err_c:1;        ///< S7 Trace Memory correctable ECC error event interrupt.
    uint32_t pqcs_rom_ecc_err_c:1;        ///< Post-Quantum Crypto ROM correctable ECC error event interrupt.
    uint32_t pqcs_isram_ecc_err_c:1;      ///< Post-Quantum Crypto Instruction RAM correctable ECC error event interrupt.
    uint32_t pqcs_dsram_ecc_err_c:1;      ///< Post-Quantum Crypto Data RAM correctable ECC error event interrupt.
    uint32_t ecultra_ecc_err_c:1;         ///< Secure Key Crypto EC Ultra datapath RAM correctable ECC error event interrupt.
    uint32_t kgscrtr_ecc_err_c:1;         ///< Secure Key Crypto KeyGuard Scratch RAM correctable ECC error event interrupt.
    uint32_t key_rom_ecc_err_c:1;         ///< KEY ROM (DAK, FWK) correctable ECC error event interrupt.
    uint32_t padding:20;                 ///< unsued
} sec_ecc_err_c_int_stat_t;


typedef struct {
    uint32_t sec_mbox_ecc_err_u:1;         ///< Secure Controller Mailbox RAM uncorrectable ECC error event interrupt.
    uint32_t jtag_mbox_ecc_err_u:1;        ///< JTAG Mailbox RAM uncorrectable ECC error event interrupt.
    uint32_t sec_dma_ch_fifo_ecc_err_u:2;  ///< Secure Controller DMA controller channel FIFO uncorrectable ECC error event interrupt. Bit N is for DMA controller channel (N+1).
    uint32_t boot_rom_ecc_err_u:1;         ///< System Controller image Boot ROM uncorrectable ECC error event interrupt.
    uint32_t s7_trace_ecc_err_u:1;         ///< S7 Trace Memory uncorrectable ECC error event interrupt.
    uint32_t pqcs_rom_ecc_err_u:1;         ///< Post-Quantum Crypto ROM uncorrectable ECC error event interrupt.
    uint32_t pqcs_isram_ecc_err_u:1;       ///< Post-Quantum Crypto Instruction RAM uncorrectable ECC error event interrupt.
    uint32_t pqcs_dsram_ecc_err_u:1;       ///< Post-Quantum Crypto Data RAM uncorrectable ECC error event interrupt.
    uint32_t ecultra_ecc_err_u:1;          ///< Secure Key Crypto EC Ultra datapath RAM uncorrectable ECC error event interrupt.
    uint32_t kgscrtr_ecc_err_u:1;          ///< Secure Key Crypto KeyGuard Scratch RAM uncorrectable ECC error event interrupt.
    uint32_t key_rom_ecc_err_u:1;          ///< KEY ROM (DAK, FWK) correctable ECC error event interrupt.
    uint32_t padding:20;                   ///< unsued
} sec_ecc_err_u_int_stat_t;



typedef struct {
    uint32_t debug_ndreset_v:1;                  ///< current value of the reset signal driven by the debug logic of the chip
    uint32_t debug_dmactive_v:1;                 ///< This signal, 0 at reset, indicates that debug logic is active.
    uint32_t cease_from_tile_v:1;                ///< Indicates that CEASE has retired the S7 CPU core
    uint32_t halt_from_tile_v:1;                 ///< Indicates that an error was detected by the S7 CPU core (but mbox wouldn't work in this case?)
    uint32_t wfi_from_tile_v:1;                  ///< Indicates that the S7 CPU core is in WFI mode (but mbox wouldn't work in this case?)
    uint32_t debug_from_tile_v:1;                ///< Indicates that the S7 CPU core is in debug mode
    uint32_t sysc_in_reset_v:1;                  ///< Indicates that the System Controller S7 CPU core is in reset
    uint32_t sysc_cpu_debug_mode_v:1;            ///< Indicates that the System Controller S7 CPU core is in debug mode
    uint32_t otp_shadow_reg_load_busy_v:1;       ///< Indicates that a OTP reread operation is in progress
    uint32_t otp_shadow_reg_load_ecc_sb_err_v:1; ///< Indicates that a single bit error (ECC or TMR) was detected during the last OTP reread operation
    uint32_t otp_shadow_reg_load_ecc_db_err_v:1; ///< Indicates that a uncorrectable double bit ECC error was detected during the last OTP reread operation - as a result the OTP shadow register content may be corrupt.
    uint32_t padding:21;                   ///< unsued
} sec_reg_misc_int_val_t;

typedef struct {
    uint32_t soft_rst_done_i:1;                  ///< A requested software reset pulse action was completed
    uint32_t debug_ndreset_i:1;                  ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t debug_dmactive_i:1;                 ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t cease_from_tile_i:1;                ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t halt_from_tile_i:1;                 ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t wfi_from_tile_i:1;                  ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t debug_from_tile_i:1;                ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t sysc_in_reset_i:1;                  ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t sysc_cpu_debug_mode_i:1;            ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t otp_shadow_reg_load_busy_i:1;       ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t otp_shadow_reg_load_ecc_sb_err_i:1; ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t otp_shadow_reg_load_ecc_db_err_i:1; ///< set to 1 upon change of value of the assiciated misc_int monitored signal
    uint32_t padding:20;                         ///< unsued
} sec_reg_misc_int_stat_t;

typedef struct { 
    uint32_t sticky_read_disable_ecc0;   ///< Reports the state of sticky read-disable bits that can only be cleared by a Device Reset event for portions of the ECC protected OTP memory
    uint32_t sticky_read_disable_ecc1;   ///< Bit index B of register N controls read-disable for OTP DWORD addresses [((B+N*32)*256) to ((B+N*32)*256)+255]
    uint32_t sticky_read_disable_ecc2;   ///< which is BYTE addresses [((B+N*32)*1024) to ((B+N*32)*1024)+1023].
    uint32_t sticky_read_disable_tmr:16; ///< Reports the state of the sticky read-disable bits that can only be cleared by a Device Reset event for portions of the TMR protected OTP memory.
    uint32_t sticky_burn_disable_all:1;  ///<  Reports the state of the sticky burn-disable-all bit that can only be cleared by a Device Reset event.
    uint32_t padding:15;                 ///< unused
} sec_reg_otp_status_t;


typedef struct {
    uint32_t hw_sticky_en_state_prod_test:3;  ///< HW feature enable sticky-on-TRSTB state for production_test_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t hw_sticky_en_state_sysc_debug:3; ///< HW feature enable sticky-on-TRSTB state for sysc_debug_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t hw_sticky_en_state_appc_debug:3; ///< HW feature enable sticky-on-TRSTB state for appc_debug_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t hw_sticky_en_state_secc_debug:3; ///< HW feature enable sticky-on-TRSTB state for secc_debug_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t hw_sticky_en_state_vstart:3;     ///< HW feature enable sticky-on-TRSTB state for  virgin-start unlock 0x7 == enabled,  0x0 == disabled.
    uint32_t lock_write_enable:1;             ///< When read as 1 then writes are allowed to program LOCK and UNLOCK fields.
    uint32_t padding0:16;                     ///< unused
    uint32_t final_prod_test_unlock:3;       ///< Final UNLOCK control signal state for production_test_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_sysc_debug_unlock:3;      ///< Final UNLOCK control signal state for sysc_debug_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_appc_debug_unlock:3;      ///< Final UNLOCK control signal state for appc_debug_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_secc_debug_unlock:3;      ///< Final UNLOCK control signal state for secc_debug_enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_otp_jtag_unlock:3;        ///< Final UNLOCK control signal state for OTP JTAG access enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_spare5_unlock:3;          ///< Final UNLOCK control signal state for SPARE5 enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_spare6_unlock:3;          ///< Final UNLOCK control signal state for SPARE6 enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t final_spare7_unlock:3;          ///< Final UNLOCK control signal state for SPARE7 enable. 0x7 == enabled,  0x0 == disabled.
    uint32_t padding1:8;                     ///< unused
} sec_reg_lock_status_t;

// lock register value
typedef struct {
    uint32_t lock_out:3;
    uint32_t unused0:1;
    uint32_t lock:4;
    uint32_t unlock:4;
    uint32_t lock_state:3;
    uint32_t unused1:1;
    uint32_t unlock_state:3;
    uint32_t otp_perm_lock_state :11; ///< only valid for HW lock
    uint32_t write_enabled:1;
    uint32_t lock_tamper:1;
} lock_val_t;

typedef struct {
    uint32_t sec_reg_boot_config;  ///< boot_config
    uint32_t sec_reg_spare0;      ///< Connects to macro spare GPO pins to TOP-LEVEL.
    uint32_t sec_reg_spare1;      ///< Connects to macro spare GPI pins from TOP-LEVEL.
    uint32_t sec_reg_spare2;      ///< Connects to macro spare GPO pins to M1.
    uint32_t sec_reg_spare3;      ///< Connects to macro spare GPI pins from M1.
    uint32_t sec_reg_spare4;      ///< Connects to macro spare GPO pins to SYSC.
    uint32_t sec_reg_spare5;      ///< Connects to macro spare GPI pins from SYSC.
    uint32_t sec_hpt_fifo_overflow;  ///< High Precision Timer CDC FIFO overflow debug flag. Set to one upon overflow event.
    sec_reg_noc_int_stat_t sec_reg_noc_int_stat; // NOC timeout interrupts
    sec_clock_monitor_stat_t sec_clock_monitor_status; ///< clock monitor status
    sec_clock_monitor_int_val_t sec_clock_monitor_int_val; ///< current val of clkmon int
    sec_clock_monitor_int_stat_t sec_clock_monitor_int_stat; ///< clock monitor interrupt status
    sec_reg_mesh_int_val_t sec_reg_mesh_int_val; ///< current value of mesh tamper int 
    sec_reg_mesh_int_stat_t sec_reg_mesh_int_stat;  ///< MESH Tamper Interrupt stat
    sec_reg_tamper_int_val_t sec_reg_tamper_int_val;  ///< tamper event value
    sec_reg_tamper_int_stat_t sec_reg_tamper_int_stat;  ///< tamper event stat
    sec_ecc_err_c_int_stat_t sec_ecc_err_c_int; ///< correctable ECC error event interrupt.
    sec_ecc_err_u_int_stat_t sec_ecc_err_u_int_stat; ///< uncorrectable ECC error event interrupt.
    sec_reg_misc_int_val_t sec_reg_misc_int_val;  ///< current value of misc_int
    sec_reg_misc_int_stat_t sec_reg_misc_int_stat; ///< interrupt status of misc_int
    sec_reg_otp_status_t sec_reg_otp_status; ///< opt status
    sec_reg_lock_status_t sec_reg_lock_status; ///< lock status
    // lock register value
    lock_val_t sw_locks[NUM_SW_LOCKS]; ///< software lock 
    lock_val_t hw_locks[NUM_HW_LOCKS]; ///< hardware lock 
} sec_reg_stat_t;

typedef struct {
    uint32_t ana_vsup_ok_i:1;        ///< reflects the interrupt state of Voltage supply ok sensor interrupt status bit, indicates when the voltage suppy for both VDD and VDD18 has been reached for Analog Top
    uint32_t ana_vsup_bro_i:1;       ///< reflects the interrupt state of Voltage supply brownout sensor interrupt status bit, indicates when either voltage suppy (VDD and VDD18) has reached brownout for Analog Top
    uint32_t ana_vdd_0p7_out_i:1;    ///< reflects the interrupt state of 0.7V user detector interrupt status bit, indicates if the voltage is outside the expected threshold
    uint32_t ana_vdd_0p8_out_i:1;    ///< reflects the interrupt state of 0.8V user detector interrupt status bit, indicates if the voltage is outside the expected threshold
    uint32_t ana_vdd_0p9_out_i:1;    ///< reflects the interrupt state of 0.9V user detector interrupt status bit, indicates if the voltage is outside the expected threshold
    uint32_t ana_vdd18_out_i:1;      ///< reflects the interrupt state of 1.8V user detector interrupt status bit, indicates if the voltage is outside the expected threshold
    uint32_t ana_pgd_glitch_det_i:1; ///< reflects the interrupt state of Power glitch detector interrupt status bit, indicates if a voltage gltich occurred on the VDD supply
    uint32_t ana_opdet_out_i:1;      ///< reflects the interrupt state of Open package detector interrupt status bit, indicates if the device has been opened unexpectedly
    uint32_t secc_a2j_done_i:1;      ///< reflects the interrupt state of Secure Controller APB2JTAG sequence done status indicator.
    uint32_t secc_a2j_busy_i:1;      ///< reflects the interrupt state of Secure Controller APB2JTAG sequence busy status indicator.
    uint32_t secc_a2j_error_i:1;     ///< reflects the interrupt state of Secure Controller APB2JTAG sequence error status indicator.
    uint32_t padding:21;             ///< unsued
} sec_m1_sec_reg_int_stat_t;

typedef struct {
    uint32_t ana_vsup_ok_v:1;        ///< reflects the current state of Voltage supply ok sensor interrupt status bit. 
    uint32_t ana_vsup_bro_v:1;       ///< reflects the current state of Voltage supply brownout sensor interrupt status bit. 
    uint32_t ana_vdd_0p7_out_v:1;    ///< reflects the current state of 0.7V user detector interrupt status bit
    uint32_t ana_vdd_0p8_out_v:1;    ///< reflects the current state of 0.8V user detector interrupt status bit. 
    uint32_t ana_vdd_0p9_out_v:1;    ///< reflects the current state of 0.9V user detector interrupt status bit.
    uint32_t ana_vdd18_out_v:1;      ///< reflects the current state of 1.8V user detector interrupt status bit.
    uint32_t ana_pgd_glitch_det_v:1; ///< reflects the current state of Power glitch detector interrupt status bit
    uint32_t ana_opdet_out_v:1;      ///< reflects the current state of Open package detector interrupt status bit.
    uint32_t secc_a2j_done_v:1;      ///< reflects the current state of Secure Controller APB2JTAG sequence done status indicator.
    uint32_t secc_a2j_busy_v:1;      ///< reflects the current state of Secure Controller APB2JTAG sequence busy status indicator.
    uint32_t secc_a2j_error_v:1;     ///< reflects the current state of Secure Controller APB2JTAG sequence error status indicator.
    uint32_t padding:21;             ///< unsued
} sec_m1_sec_reg_int_val_t;

typedef struct {
    uint32_t vsup_vdd_bro:1;       ///< VDD Voltage Supply Brownout status flag
    uint32_t vsup_vdd18_bro:1;     ///< VDD18 Voltage Supply Brownout status flag
    uint32_t vsup_vdd_ok:1;        ///< VDD Voltage Supply Power-On-Reset status flag
    uint32_t vsup_vdd18_ok:1;      ///< VDD18 Voltage Supply Power-On-Reset status flag
    uint32_t ana_rcosc_valid:1;    ///< Analog Top RC Oscillator valid status flag
    uint32_t ana_pgd_glitch_det:4; ///< Analog Top Power Glitch Detector status flag
    uint32_t ana_opdet_out:1;      ///< Analog Open Package Detector status flag
    uint32_t padding:22;           ///< unsued
} sec_m1_ana_stat_t;


typedef struct {
    uint32_t vsup_ok:1;       ///< Analog Top Voltage Supply status flag.
    uint32_t otp_init:1;      ///< OTP initiation status flag.
    uint32_t otp_ok:1;        ///< OTP read complete status flag
    uint32_t rc_init:1;       ///< RC Oscillator startup enable status flag
    uint32_t rc_ok:1;         ///< RC Oscillator startup complete status flag
    uint32_t por_fsm_error:1; ///< Power-On-Reset State Machine error indicator status flag.
    uint32_t fsm2_init:1;     ///< Start State Machine initiation status flag. 
    uint32_t m1boot_ok:1;     ///< M1_SOK startup complete status flag
    uint32_t padding:24;      ///< unsued
} sec_m1_drv_stat_t;

/// nmi context 
  typedef struct {
    uint32_t autoreset_mode_state:1;                  ///< bit  0  r
    uint32_t autoreset_mode0_rst_en_s7_core_mirror:1; ///< bit  1  r
    uint32_t force_autoreset:1;                       ///< bit  2  r
    uint32_t autoreset_mode1_action_mirror:1;         ///< bit  3  r
    uint32_t sysc_reboot_req:1;                       ///< bit  4  r
    uint32_t sysc_system_rst_req:1;                   ///< bit  5  r
    uint32_t fill_6_7:2;                              ///< padding
    uint32_t wdt_swe_irq:1;                           ///< bit  8  r
    uint32_t wdt_reset_pend:1;                        ///< bit  9  r
    uint32_t wdt_reset_req:1;                         ///< bit  10 r
    uint32_t fill_11_31:21;                           ///< padding
  } sec_m1_stat_nmi_ctxt_t; 

/// reset reason 
  typedef struct {
    uint32_t soft_reset_en_s7_core:1; ///< soft reset
    uint32_t debug_reset:1;           ///< wdog reset
    uint32_t wdog_ar0:1;              ///< wdog autoreset=0
    uint32_t wdog_ar1:1;              ///< wdog autoreset=1
    uint32_t device_reset:1;          ///< device reset
    uint32_t po_reset:1;              ///< por
    uint32_t tamper_reset:1;          ///< tamper reset
    uint32_t sysc_reboot_req:1;       ///< sysc_reboot_req was raised by the System Controller - note that this is not
                                      //  directly a reset reason as theresponse to sysc_reboot_req is controlled by software
    uint32_t spare: 24;               ///< spare 
  } sec_m1_stat_reset_reason_t; 

typedef struct {
    sec_m1_sec_reg_int_stat_t sec_m1_sec_reg_int_stat; ///< reflects the interrupt state of the interrupt status bits.
    sec_m1_sec_reg_int_val_t sec_m1_sec_reg_int_val;  ///< reflects the current state of the interrupt status bits. 
    sec_m1_ana_stat_t sec_m1_ana_stat;   ///< Analoge TOP status flags
    sec_m1_drv_stat_t sec_m1_drv_stat;  ///< DRV_STAT flags
    uint32_t secc_gpo0; ///< 16 bit general output signal. Default to 0.
    uint32_t secc_gpo1; ///< 16 bit general output signal. Default to all 1's.
    uint32_t secc_gpi;  ///< 32 bit general input signal.
    uint32_t m1_secc_spare; ///< M1_SOK to Secure Controller spare signals.
    uint32_t secc_m1_spare; ///< Secure Controller to M1_SOK spare signals.    
    sec_m1_stat_reset_reason_t secc_reset_reason;        ///< Status for reset reason originating from the Secure Controller.
    scratchpad_exc_m0_t m0;   ///< Machine-level exception register 0    
    uint32_t mepc_low;        ///< Machine exception program counter (32 lower bits)
    uint32_t mtval_low;       ///< If the cause is a load/store fault, this register 
                            ///< has the value of the problematic address. 
                            ///< If it is an invalid instruction, it provides the instruction that the core tried to execute.     
    scratchpad_exc_m1_t m1;   ///< Machine-level exception register 1
    uint32_t mnbeu_value_low; ///< BEU - Physical address of error event
    uint32_t m1_boot_cnt;              ///< boot counter
    sec_m1_stat_nmi_ctxt_t m1_nim_cxt; ///< nmi context 
    secc_scratchreg_misc_t m1_misc;    ///< misc context 
} sec_m1_stat_t;

typedef struct {    
    uint32_t lock_i:1;           ///< indicates when the PLL locks
    uint32_t offsetcal_lock_i:1; ///< indicates when the PLL offsetcalibration achieves lock
    uint32_t lock_v:1;           ///< reflects the current state of the LOCK.
    uint32_t offsetcal_lock_v:1; ///< reflects the current state of the OFFSETCAL_LOCK
    uint32_t pll_bypass_en:1;    ///< state of pll bypass enable 
    uint32_t clk_bypass_en:1;    ///< state of clk bypass enable 
    uint32_t padding:26;         ///< unsued
} sec_acsu_stat_t;

typedef struct {
    uint32_t wdt_count0;             ///< Reports the Watchdog Timer count value - lower 32 bits.
    uint32_t wdt_count1;             ///< Watchdog Timer counter value - upper 8 bits.
    uint32_t state_in_fwin_closed:1; ///< returns logic 1 when the Watchdog Timer is in the first window stage closed phase
    uint32_t state_in_fwin:1;        ///< returns logic 1 when the Watchdog Timer is in the first window stage.
    uint32_t state_in_swin:1;        ///< returns logic 1 when the Watchdog Timer is in the second window stage
    uint32_t state_in_reset_pend:1;  ///< returns logic 1 when the Watchdog Timer is in the reset pending stage
    uint32_t state_in_reset_req:1;   ///< returns logic 1 when the Watchdog Timer is in the reset request stage
    uint32_t reset_pend_cause:1;     ///< When in the reset pending stage or the reset request stage, this field reports the cause of entry to the reset pending stage as follows:
                                     ///   0 - Reset pending stage was entered due to expiry of the second window, the watchdog counter incremented up to the second window expiry threshold without being restarted by a refresh action.
                                     ///   1 - Reset pending stage was entered due to a refresh action occuring during a closed first window stage phase.
                                     ///   The value of this bit has no meaning during the first window and second window stages.
    uint32_t paused:1;               ///<  indicate the Watchdog Timer is paused
    uint32_t debug_halt_active:1;    ///< Reports logic 1 when the Watchdog Timer is paused in response to a processor debug state active signal that was enabled by DEBUG_HALT_ALLOW
    uint32_t config_locked:1;        ///< indicates that further changes to the ACTV_* fields are prohibited 
    uint32_t fwe_i0:1;               ///< The watchdog counter has crossed the first window expiry threshold, and entered the second window stage.
    uint32_t swe_i1:1;               ///< The watchdog counter has entered the reset pending stage, either due to expiry of the second window or a refresh action being detected during a closed first window phase.
    uint32_t padding:21;             ///< unsued
} sec_wdog_stat_t;

typedef struct {
    uint64_t ch1_intstat:1;                    ///< Channel 1 Interrupt Status Bit.
    uint64_t ch2_intstat:1;                    ///< Channel 2 Interrupt Status Bit.
    uint64_t rsvd_dmac_intstatusreg_8to1:6;    ///< DMAC_INTSTATUSREG
    uint64_t rsvd_dmac_intstatusreg:8;           ///< DMAC Interrupt Status Register (bits 15to8) 
    uint64_t commonreg_intstat:1;              ///< Common Register Interrupt Status Bit.
    uint64_t rsvd_dmac_intstatusreg_63to17:47; ///< DMAC Interrupt Status Register (bits 63to17)
} sec_dmac_intstatusreg_t;


typedef struct {
    uint64_t slvif_commonreg_dec_err_intstat:1;          ///< Register Bus Interface Decode Error detected.
    uint64_t slvif_commonreg_wr2ro_err_intstat:1;        ///< Register Bus Interface Write to Read Only Error detected.
    uint64_t slvif_commonreg_rd2wo_err_intstat:1;        ///< Register Bus Interface Read to Write Only Error detected.
    uint64_t slvif_commonreg_wronhold_err_intstat:1;     ///< Register Bus Interface Common Register Write On Hold Error detected.
    uint64_t rsvd_dmac_commonreg_intstatusreg_5to4:2;    ///< DMAC Common Register Interrupt Status Register (bits 5to4) 
    uint64_t slvif_commonreg_addrparity_err_intstat:1;   ///< Common Register Space Address Parity Error detected
    uint64_t slvif_commonreg_wrparity_err_intstat:1;     ///< Common Register Space Write Parity Error detected.
    uint64_t slvif_undefinedreg_dec_err_intstat:1;       ///< Register Bus Interface Decode Error detected.
    uint64_t mxif1_rch0_prot_correrr_intstat:1;          ///< AXI Manager 1 Read Channel Data related Correctable Error detected.
    uint64_t mxif1_rch0_prot_uncorrerr_intstat:1;        ///< AXI Manager 1 Read Channel Data related Uncorrectable Error detected.
    uint64_t mxif1_rch1_prot_correrr_intstat:1;          ///< AXI Manager 1 Read Channel Control signals related Correctable Error detected.
    uint64_t mxif1_rch1_prot_uncorrerr_intstat:1;        ///< AXI Manager 1 Read Channel Control signals related Uncorrectable Error detected.
    uint64_t mxif1_bch_prot_correrr_intstat:1;           ///< AXI Manager 1 Write Response Channel Correctable Error detected.
    uint64_t mxif1_bch_prot_uncorrerr_intstat:1;         ///< AXI Manager 1 Write Response Channel Uncorrectable Error detected
    uint64_t mxif2_rch0_prot_correrr_intstat:1;          ///< AXI Manager 2 Read Channel Data related Correctable Error detected.
    uint64_t mxif2_rch0_prot_uncorrerr_intstat:1;        ///< AXI Manager 2 Read Channel Data related Uncorrectable Error detected.
    uint64_t mxif2_rch1_prot_correrr_intstat:1;          ///< AXI Manager 2 Read Channel Control signals related Correctable Error detected.
    uint64_t mxif2_rch1_prot_uncorrerr_intstat:1;        ///< AXI Manager 2 Read Channel Control signals related Uncorrectable Error detected.
    uint64_t mxif2_bch_prot_correrr_intstat:1;           ///< AXI Manager 2 Write Response Channel Correctable Error detected.
    uint64_t mxif2_bch_prot_uncorrerr_intstat:1;         ///< AXI Manager 2 Write Response Channel Uncorrectable Error detected
    uint64_t mxif1_arch_prot_arready_parerr_intstat:1;   ///< AXI Manager 1 Read Address Channel ARREADY Parity Error detected
    uint64_t mxif1_awch_prot_awready_parerr_intstat:1;   ///< AXI Manager 1 Write Address Channel AWREADY Parity Error detected.
    uint64_t mxif1_wch_prot_wready_parerr_intstat:1;     ///< AXI Manager 1 Write Data Channel WREADY Parity Error detected.
    uint64_t mxif1_rch_prot_rvalid_parerr_intstat:1;     ///< AXI Manager 1 Read Data Channel RVALID Parity Error detected.
    uint64_t mxif1_bch_prot_bvalid_parerr_intstat:1;     ///< AXI Manager 1 Write Response Channel BVALID Parity Error detected.
    uint64_t mxif2_arch_prot_arready_parerr_intstat:1;   ///< AXI Manager 1 Read Address Channel ARREADY Parity Error detected
    uint64_t mxif2_awch_prot_awready_parerr_intstat:1;   ///< AXI Manager 1 Write Address Channel AWREADY Parity Error detected.
    uint64_t mxif2_wch_prot_wready_parerr_intstat:1;     ///< AXI Manager 1 Write Data Channel WREADY Parity Error detected.
    uint64_t mxif2_rch_prot_rvalid_parerr_intstat:1;     ///< AXI Manager 1 Read Data Channel RVALID Parity Error detected.
    uint64_t mxif2_bch_prot_bvalid_parerr_intstat:1;     ///< AXI Manager 1 Write Response Channel BVALID Parity Error detected.
    uint64_t rsvd_dmac_commonreg_intstatusreg_63to31:33; ///< DMAC Common Register Interrupt Signal Enable Register (bits 63to31)
} sec_dmac_commonreg_intstatusreg_t;



typedef struct {
    uint64_t block_tfr_done_intstat:1;                 ///< Block Transfer completed.
    uint64_t dma_tfr_done_intstat:1;                   ///< DMA Transfer Completed
    uint64_t rsvd_dmac_chx_intstatusreg_2:1;           ///< DMAC Channelx Specific Interrupt Register
    uint64_t src_transcomp_intstat:1;                  ///< Source Transaction Completed.
    uint64_t dst_transcomp_intstat:1;                  ///< Destination Transaction Completed.
    uint64_t src_dec_err_intstat:1;                    ///< Source Decode Error detected.
    uint64_t dst_dec_err_intstat:1;                    ///< Destination Decode Error Detected
    uint64_t src_slv_err_intstat:1;                    ///< Source Subordinate Error Detected
    uint64_t dst_slv_err_intstat:1;                    ///< Destination Subordinate Errors Detected
    uint64_t lli_rd_dec_err_intstat:1;                 ///< LLI Read Decode Error detected
    uint64_t lli_wr_dec_err_intstat:1;                 ///< LLI write Decode Error detected.
    uint64_t lli_rd_slv_err_intstat:1;                 ///< LLI read Subordinate Error detected.
    uint64_t lli_wr_slv_err_intstat:1;                 ///< LLI Write SUBORDINATE Error detected.
    uint64_t shadowreg_or_lli_invalid_err_intstat:1;   ///< Shadow Register / LLI Invalid error detected.
    uint64_t slvif_multiblktype_err_intstat:1;         ///< Multi-block transfer type Error detected.
    uint64_t rsvd_dmac_chx_intstatusreg_15:1;          ///< DMAC Channelx Specific Interrupt Register 
    uint64_t slvif_dec_err_intstat:1;                  ///< Register Bus Interface Decode Error detected.
    uint64_t slvif_wr2ro_err_intstat:1;                ///< Register Bus Interface Write to Read Only Error detected.
    uint64_t slvif_rd2rwo_err_intstat:1;               ///< Register Bus Interface Read to Write Only Error detected.
    uint64_t slvif_wronchen_err_intstat:1;             ///< Register Bus Interface Write On Channel Enabled Error detected.
    uint64_t slvif_shadowreg_wron_valid_err_intstat:1; ///< Register Bus Interface Shadow Register Write On Valid Error detected.
    uint64_t slvif_wronhold_err_intstat:1;             ///< Register Bus Interface Write On Hold Error detected.
    uint64_t rsvd_dmac_chx_intstatusreg_22to23:2;      ///< DMAC Channelx Specific Interrupt Register
    uint64_t slvif_addrparity_err_intstat:1;           ///< Register Bus Interface Address Parity Error detected.
    uint64_t slvif_wrparity_err_intstat:1;             ///< Register Bus Interface Write Parity Error detected.
    uint64_t rsvd_dmac_chx_intstatusreg_26:1;          ///<  DMAC Channelx Specific Interrupt Register (bit 26) Reserved bit
    uint64_t ch_lock_cleared_intstat:1;                ///< Channel locking is cleared.
    uint64_t ch_src_suspended_intstat:1;               ///< Channel Source is suspended.
    uint64_t ch_suspended_intstat:1;                   ///< Channel is suspended.
    uint64_t ch_disabled_intstat:1;                    ///< Channel is disabled.
    uint64_t ch_aborted_intstat:1;                     ///< Channel is terminated
    uint64_t ecc_prot_chmem_correrr_intstat:1;         ///< Channel x FIFO Memory Interface correctable Error detected.
    uint64_t ecc_prot_chmem_uncorrerr_intstat:1;       ///< Channel x FIFO Memory Interface Uncorrectable Error detected.
    uint64_t ecc_prot_uidmem_correrr_intstat:1;        ///< Channel x UID Memory Interface correctable Error detected.
    uint64_t ecc_prot_uidmem_uncorrerr_intstat:1;      ///< Channel x UID Memory Interface Uncorrectable Error detected.
    uint64_t rsvd_dmac_chx_intstatusreg_36to63:28;     ///< DMAC Channelx Specific Interrupt Register (bits 36to63) Reserved bits
} sec_dma_ch_intstatus_t;

typedef struct {
    sec_dmac_intstatusreg_t sec_dmac_intstatusreg;
    sec_dmac_commonreg_intstatusreg_t sec_dmac_commonreg_intstatusreg;
    sec_dma_ch_intstatus_t sec_dma_ch1_intstatus;
    sec_dma_ch_intstatus_t sec_dma_ch2_intstatus;
} sec_dma_ctrl_stat_t;

/**
 * @brief Peripheral status struct
*/
typedef struct {
    sec_beu_stat_t      sec_beu_stat;      ///< Bus Error Unit status. 
    ocr_mem_stats_t     sec_ocr_mem_stat;  ///< SEC OCR MEM status
    sec_puf_stat_t      sec_puf_stat;      ///< PUF stat
    sec_skc_stat_t      sec_skc_stat;      ///< SKC stat
    sec_pq_stat_t       sec_pq_stat;       ///< PQ stat
    ocr_mem_stats_t     sec_pq_ocr_stat;   ///< PQ OCR stat
    ocr_mem_stats_t     sec_dtim_ocr_stat; ///< DTIM OCR stat
    sec_reg_stat_t      sec_reg_stat;      ///< Sec reg stat
    sec_wdog_stat_t     sec_wdog_stat;     ///< sec_wdog stat
    sec_m1_stat_t       sec_m1_stat;       ///< M1 reg stat
    sec_acsu_stat_t     sec_acsu_stat;     ///< ACSU stat
    uint32_t padding[2];                   ///< 64-bit aligned padding
    sec_dma_ctrl_stat_t sec_dma_ctrl_stat; ///< sec_dma_ctrl stat
    
} sec_periph_stats_t;


/**
 * @brief bitmask to get the perhiph stat of the peripheral that has 1 in the bit pos
*/
typedef enum {
    SEC_PERIPH_STAT_CMD_SEC_BEU_STAT      = 1<<0,   ///< get Bus Error Unit status. 
    SEC_PERIPH_STAT_CMD_SEC_OCR_MEM_STAT  = 1<<1,   ///< get SEC OCR MEM status
    SEC_PERIPH_STAT_CMD_SEC_PUF_STAT      = 1<<2,   ///< get PUF stat
    SEC_PERIPH_STAT_CMD_SEC_SKC_STAT      = 1<<3,   ///< get SKC stat
    SEC_PERIPH_STAT_CMD_SEC_PQ_STAT       = 1<<4,   ///< get PQ stat
    SEC_PERIPH_STAT_CMD_SEC_PQ_OCR_STAT   = 1<<5,   ///< get PQ OCR stat
    SEC_PERIPH_STAT_CMD_SEC_DTIM_OCR_STAT = 1<<6,   ///< get DTIM OCR stat
    SEC_PERIPH_STAT_CMD_SEC_REG_STAT      = 1<<7,   ///< get Sec reg stat
    SEC_PERIPH_STAT_CMD_SEC_WDOG_STAT     = 1<<8,   ///< get sec_wdog stat
    SEC_PERIPH_STAT_CMD_SEC_M1_STAT       = 1<<9,   ///< get M1 reg stat
    SEC_PERIPH_STAT_CMD_SEC_ACSU_STAT     = 1<<10,  ///< get ACSU stat
    SEC_PERIPH_STAT_CMD_SEC_DMA_CTRL_STAT = 1<<11,  ///< get sec_dma_ctrl stat
} sec_periph_stats_cmd_mask_t;

#endif /* SEC_API_TYPES_H */
