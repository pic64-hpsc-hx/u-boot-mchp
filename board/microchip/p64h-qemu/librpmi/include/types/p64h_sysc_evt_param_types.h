/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Structs for event parameters that are also used by Python remote_api
 */

#ifndef SYSC_EVT_PARAM_TYPES_H
#define SYSC_EVT_PARAM_TYPES_H

#include <zsbl/sec_api_types.h>
#include <zsbl/boot_cfg_helper.h>
#include <zsbl/sec_otp_types.h>

/// Size of the array passed as parameter for validate_fw request
#define SMB_VALIDATE_FW_NONCE_SIZE 2u
/// Size of the array to store the activation code after SEC_CMD_GENERATE_USER_ROOT_KEY_AC request
#define SMB_GENERATE_USER_ROOT_KEY_AC_BUFFER_SIZE 361u
/// Size of the array to stoer the SEC_CMD_DISTRIBUTE_USER_ROOT_KEY
#define DISTRIBUTE_USER_ROOT_KEY_SCORE_SIZE 2u
/// Size of the array to store the certificate SCAC
#define SCAC_ARRAY_SIZE ((SCAC_SIZE_WORDS - 1) / 2)
/// Size of the array to store the Secc log transferred to SysCtrl
#define LOG_ARRAY_SIZE 1024

// Allowed operating modes for secC
typedef enum {
    P64H_SYSC_REDUCED_MODE = 0, ///< Reduced/Sleep mode
    P64H_SYSC_BYPASS_MODE,      ///< Bypass Full Operating
    P64H_SYSC_PERF_MODE,        ///< PLL Full Operating (Performance)
    P64H_SYSC_MODE_LAST,
} p64h_sysc_secc_clock_operating_mode_t;

typedef struct {
    uint64_t nonce_hsm[SMB_VALIDATE_FW_NONCE_SIZE];
    uint16_t cmd_args;
    void*    resp_write_addr; // "Address for sec_mbox service to write into if it can't fit the resonse data within a response event
} p64h_sysc_sec_validate_fw_params_t;

typedef struct {
    uint64_t src_addr;
    uint16_t cmd_args;
} p64h_sysc_sec_flash_hdr_signature_verify_params_t;

typedef struct {
    uint64_t addr;
    uint16_t cmd_args;
    uint64_t dest_addr;
} p64h_sysc_sec_download_component_params_t;

typedef struct {
    uint32_t m1_misc_feature_val;
    uint32_t m1_misc_feature_mask;
} p64h_sysc_sec_m1_misc_feature_params_t;

typedef struct {
    sec_sig_ec_pq_verify_t sec_sig_ec_pq_verify;
    uint16_t               cmd_args;
    uint8_t                payload[1024];
} p64h_sysc_sec_sig_ec_pq_verify_params_t;

// Request parameter for svc_mbox request event
typedef union {
    bootcfg_otp_t                                     otp_boot_cfg;
    uint64_t                                          addr;
    sec_mem_scrub_t                                   mem_scrub;
    p64h_sysc_secc_clock_operating_mode_t             clock_mode;
    uint16_t                                          cmd_args;
    p64h_sysc_sec_validate_fw_params_t                sec_validate_fw_params;
    p64h_sysc_sec_flash_hdr_signature_verify_params_t sec_flash_hdr_signature_verify_params;
    void* resp_write_addr; // Address for sec_mbox service to write into if it can't fit the resonse data within a response event
    p64h_sysc_sec_download_component_params_t sec_download_component_params;
    p64h_sysc_sec_m1_misc_feature_params_t    sec_m1_misc_feature_params;
    p64h_sysc_sec_sig_ec_pq_verify_params_t   sec_sig_ec_pq_verify_params;
} p64h_sysc_sec_cmd_req_params_t;

// Data received by svc_mbox from secC, to be sent to calling service
typedef union {
    bootcfg_otp_t      get_bootcfg_out;
    uint64_t           dsn_get_out[DSN_DWORD_LEN];
    otp_pe_data_t      get_otp_pe_data_out;
    sec_periph_stats_t get_periph_stats_out;
    tvs_mon_stat_t     get_tvs_mon_data_out;
    uint64_t           generate_user_root_key_out[SMB_GENERATE_USER_ROOT_KEY_AC_BUFFER_SIZE];
    uint8_t            distribute_user_root_key_out[DISTRIBUTE_USER_ROOT_KEY_SCORE_SIZE];
    uint64_t           cert_scac_out[SCAC_ARRAY_SIZE];
    uint64_t           get_log_out[LOG_ARRAY_SIZE];
} p64h_sysc_secc_mbox_out_t;

typedef enum {
    P64H_SYSC_RAS_EINJ_RESPONSE_OK = 0,
    P64H_SYSC_RAS_EINJ_RESPONSE_ERR,
    P64H_SYSC_RAS_EINJ_RESPONSE_LAST,
} p64h_sysc_ras_einj_response_t;

#endif // SYSC_EVT_PARAM_TYPES_H
