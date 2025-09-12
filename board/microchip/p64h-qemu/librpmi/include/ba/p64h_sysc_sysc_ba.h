/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ba_sysc_ba.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_BA_SYSC_BA_H
#define P64H_SYSC_BA_SYSC_BA_H

#include "p64h_sysc_intr_ba.h"
#include "p64h_sysc_board_ba.h"
#include "p64h_sysc_shared_periph_ba.h"
#include "p64h_sysc_shared_svc_ba.h"
#include "p64h_sysc_shared_wguard_ba.h"
#include "p64h_sysc_board_ba.h"
#include "p64h_sysc_svc_cfg_ba.h"
#include <types/p64h_sysc_trace_types.h>
#include <types/p64h_sysc_ddr_types.h>
#include <types/p64h_sysc_nvm_types.h>

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_ENET_SW_SIZE       (16384UL)   ///<  Maximum size of enet switch cfg
#define P64H_SYSC_KEYS_CFG_SIZE      1U * 1024UL ///<  Maximum size of keys cfg
#define P64H_SYSC_PQ_FW_CFG_SIZE     1U * 1024UL ///<  Maximum size of pq_fw cfg
#define P64H_SYSC_APPC_ZSBL_SIZE     1U * 1024UL ///<  Maximum size of zsbl binary
#define P64H_SYSC_APPC_RNMI_SIZE     1U * 1024UL ///<  Maximum size of rnmi binary
#define P64H_SYSC_MAX_FW_SCRIPT_CMDS 20U         ///< Maximum Number of supported FW SCRIPT COMMANDS

// ########################### Enumerations ##########################
/// Enumeration for OCR CTRL
typedef enum {
    P64H_SYSC_OCR_CTRL_APPC_0 = 0u, ///< OCR controller instance 0 (APP NoC peripheral)
    P64H_SYSC_OCR_CTRL_APPC_1,      ///< OCR controller instance 1 (APP NoC peripheral)
    P64H_SYSC_OCR_CTRL_SYSC,        ///< SYSC OCR Controller
    P64H_SYSC_OCR_CTRL_LAST         ///< invalid, used for error checking
} p64h_sysc_ocr_ctrl_t;

/// fw update script command
typedef enum {
    P64H_SYSC_FW_SCR_CMD_OTP_BOOT_CFG_TEST,
    P64H_SYSC_FW_SCR_CMD_OTP_BOOT_CFG_SET,
    P64H_SYSC_FW_SCR_CMD_OTP_BOOT_CFG_GET,
    P64H_SYSC_FW_SCR_CMD_BIN_ERASE,
    P64H_SYSC_FW_SCR_CMD_BIN_WR,
    P64H_SYSC_FW_SCR_CMD_BIN_RD,
    P64H_SYSC_FW_SCR_CMD_FS_FORMAT,
    P64H_SYSC_FW_SCR_CMD_FS_RM,
    P64H_SYSC_FW_SCR_CMD_FS_CP,
    P64H_SYSC_FW_SCR_CMD_FS_MV,
    P64H_SYSC_FW_SCR_CMD_ENTER_CRITICAL_SECTION,
    P64H_SYSC_FW_SCR_CMD_EXIT_CRITICAL_SECTION,
    P64H_SYSC_FW_SCR_CMD_REBOOT,
    P64H_SYSC_FW_SCR_CMD_SYSC_IMG_WR,
    P64H_SYSC_FW_SCR_CMD_SYSC_IMG_CFG1_WR
} p64h_sysc_fw_scr_cmd_t;

typedef struct {
    char fw_comp[P64H_SYSC_STRING_MAX];
} p64h_sysc_otp_boot_cfg_test_data_t;

typedef struct {
    char     fw_comp[P64H_SYSC_STRING_MAX];
    uint32_t length;
    uint32_t img_id;
    uint32_t offset;
} p64h_sysc_img_wr_data_t;

typedef struct {
    char     fw_comp[P64H_SYSC_STRING_MAX];
    uint32_t length;
} p64h_sysc_img_cfg1_wr_data_t;

typedef struct {
    char type[P64H_SYSC_STRING_MAX];
} p64h_sysc_reboot_cmd_data_t;

typedef union {
    p64h_sysc_otp_boot_cfg_test_data_t otp_boot_cfg_test_data;
    p64h_sysc_img_wr_data_t            sysc_img_wr_data;
    p64h_sysc_reboot_cmd_data_t        reboot_cmd_data;
    p64h_sysc_img_cfg1_wr_data_t       sysc_img_cfg1_wr_data;
} p64h_sysc_fw_script_cmd_data_t;

/**
 * @brief
 * This struct contains the enum of all fw script commands and data
 */
typedef struct {
    p64h_sysc_fw_scr_cmd_t         name; /// enum of fw script commands
    p64h_sysc_fw_script_cmd_data_t cmd_data;
} p64h_sysc_fw_cmd_t;

/**
 * @brief
 * This struct packs all firmware script commands into one struct
 */
typedef struct {
    uint32_t           num_cmd;                            ///< Number of commands in fw script
    p64h_sysc_fw_cmd_t cmds[P64H_SYSC_MAX_FW_SCRIPT_CMDS]; ///< List of Commands in fw script
} p64h_sysc_fw_script_t;

/// enet switch configuration
typedef struct {
    // TBD
    uint8_t enable; ///< enable for the switch
} p64h_sysc_enet_swr_cfg_t;

typedef struct {
    uint32_t                       offset;            ///< offset in image
    uint8_t                        partition_mask;    ///< appc bootmask
    uint8_t                        retry_cnt;         ///< retry count
    uint8_t                        fail_offset_entry; // 0..15
    p64h_sysc_appc_boot_next_act_t fail_act;          // STOP  // P64H_SYSC_BOOT_NEXT_ACT_APPC_BOOT_CFG, we use next_offset_entry //
                                                      // P64H_SYSC_BOOT_NEXT_ACT_OTP_NEXT_SYSC_BOOT_CFG, check policy into otp_boot_cfg,
    bool is_valid;                                    // true if this entry is valid, false otherwise
} p64h_sysc_acot_entry_t;

typedef struct {
    bool use_secc_keys; ///< when true, secure controller will be to verify signature and/or decrypt AppC Image (slow) ///< when false,
                        ///< sysc_blobs.keys is loaded in crypto service and user crypto is used (faster)
    bool encrypted;     ///< AppC images are encrypted.
    bool ec_signed;     ///< AppC images are EC signed.
    bool pq_signed;     ///< AppC images are PQ signed.
} p64h_sysc_crypto_cfg_t;

typedef struct {
    p64h_sysc_appc_boot_mode_t boot_mode;
    uint8_t boot_val;   ///< when boot_mode == P64H_SYSC_APPC_BOOT_MODE_FORCED, boot_val provides the selected Appc boot configuration    
    uint8_t is_compact; ///< whether or not the AppC boot cfg entries are in compact mode or not (in redundant mode if set to false)
    p64h_sysc_appc_boot_retry_act_t reboot_policy; // choices: [APPC_RST, SYSC_SOFT_RST, SYSC_SYSTEM_RST, SYSC_DEV_RST]
    p64h_sysc_nvm_noc_if_enc_t
        app_noc_if; ///< APP NOC interface (when it is P64H_SYSC_NVM_NOC_IF_LAST, it means there is no APPC image available)      
    p64h_sysc_crypto_cfg_t crypto_cfg;  ///< appc config cryptographic configuration
    p64h_sysc_acot_entry_t entries[16]; ///< acot entries
} p64h_sysc_acot_t;

/**
 * @brief
 * Defines the configuration of the DDR EDAC
 */

/// OCR memory protection / scrubbing configuration
/// for 2 APPC OCRs CTRL and SYSC OCR CTRL
typedef struct {
    bool scrub_en;      ///< Enable auto-scrub(patrol-scrub) through memory addresses every (auto_scrub_period+1) clock cycles to perform atomic
                        ///< read-no_modify_writes
    bool self_scrub_en; ///< Enable the detection and scrubbing of correctable errors during memory transactions to the affected address and perform
                        ///< atomic read-no_modify_writes
    uint32_t auto_scrub_period; ///< Auto-scrub period in aclk cycles
} p64h_sysc_ocr_cfg_t;

/**
 * @brief
 *   Mask for enabling other peripherals.
 */
typedef struct {
    uint32_t hpt      : 1; ///< Sysc Timer active
    uint32_t el_timer : 1; ///< Sysc EL Timer active
    uint32_t i2c      : 1; ///< Sysc I2C active
    uint32_t uart     : 1; ///< Sysc uart active
    uint32_t gpio     : 1; ///< Sysc gpio active
} p64h_sysc_periph_subordinate_inst_t;

/**
 * @brief
 *   Define channels used by system
 */
typedef struct {
    uint32_t gpio; ///< Sysc GPIO instance, support 32 channels
} p64h_sysc_periph_chnl_inst_t;

/**
 * @brief
 *   Define peripheral configuration for the peripheral
 */
typedef struct {
    p64h_sysc_periph_subordinate_inst_t periph_subordinate_enable;
    p64h_sysc_periph_chnl_inst_t        periph_chnl_enable;
} p64h_sysc_active_periph_cfg_t;

/**
 * @brief
 *   Define peripheral configuration for the sysc peripheral
 */
typedef struct {
    p64h_sysc_active_periph_cfg_t active_periph;
    p64h_sysc_i2c_cfg_t           i2c_cfg;   ///< i2c configuration
    p64h_sysc_gpio_cfg_t          gpio_cfg;  ///< gpio configuration
    p64h_sysc_hpt_cfg_t           timer_cfg; ///< high precision timer configuration
    p64h_sysc_uart_cfg_t          uart_cfg;  ///< uart configuration
} p64h_sysc_periph_cfg_t;

/**
 * @brief
 *   sysc SOC configuration
 */
typedef struct {
    uint8_t                     enable;                                ///< 1 : enable the configuration, 0 : disable the configuration
    p64h_sysc_bin_hdr_t         dev_cfg_version;                       ///< stores the versioning info for the dev_cfg tool
    p64h_sysc_board_cfg_t       board_cfg;                             ///<
    p64h_sysc_appc_periph_cfg_t appc_periph_cfg;                       ///< top level Peripheral configuration
    p64h_sysc_periph_cfg_t      sysc_periph_cfg;                       ///< sysc periph config
    p64h_sysc_appc_ddr_cfg_t    ddr_appc_cfg;                          ///< DDR configuration
    p64h_sysc_appc_wg_cfg_t     wg_cfg;                                ///< worldguard configuration
    p64h_sysc_int_agg_cfg_t     intr_cfg;                              ///< Interrupt configuration
    p64h_sysc_nvm_cpair_cfg_t   nvm_cfg[P64H_SYSC_NUM_CONNECTOR_PAIR]; ///< NVM configuration
    p64h_sysc_enet_swr_cfg_t    enet_swr_cfg;                          ///< Switch Configuration
    p64h_sysc_ddr_edac_cfg_t    ddr_edac_cfg[P64H_SYSC_DDR_EDAC_IF];   ///< DDR EDAC configuration
    p64h_sysc_spw_cfg_t         sysc_spw_cfg;                          ///< SPW Configuration
    p64h_sysc_ocr_cfg_t         ocr_cfg[P64H_SYSC_OCR_CTRL_LAST];      ///< OCR memory protection / scrubbing configuration
} p64h_sysc_soc_cfg_t;

/**
 * @brief CPER Structure placeholder until we define CPERLib
 */
typedef struct cper {
    ///< @brief Partition ID for the software partition that owns the faulty resource
    uint8_t  partition_id;
    uint32_t timestamp;
} p64h_sysc_cper_t;

/**
 * @brief
 * This struct store the actual sizes of each cfg1 blob binaries
 */
typedef struct __attribute__((packed)) {
    // TODO: do we want to keep these first four sizes for redundancy checks? They should always be equal to the sizeof(type), which is fixed for a
    // fsbl version
    uint32_t sysc_soc_cfg_size; ///> size of sysc_soc_cfg
    uint32_t ddr_cfg_size;      ///> size of ddr_cfg
    uint32_t sw_svc_cfg_size;   ///> size of sw_svc_cfg
    uint32_t acot_cfg_size;     ///> size of acot_cfg
    uint32_t enet_sw_size;      ///> size of enet_sw
    uint32_t keys_size;         ///> size of keys
    uint32_t pq_fw_size;        ///> size of keys
    uint32_t appc_zsbl_size;    ///> size of appc_zsbl
    uint32_t appc_rnmi_size;    ///> size of appc_rnmi
    uint32_t padding;           ///> 32-bit padding for 64-bit alignment
} p64h_sysc_cfg1_blobs_header_t;

#define P64H_SYSC_SOC_CFG_SIZE    sizeof(p64h_sysc_soc_cfg_t)    ///<  Maximum size of sysc_soc_cfg
#define P64H_SYSC_DDR_CFG_SIZE    sizeof(p64h_sysc_ddr_ss_cfg_t) ///<  Maximum size of ddr cfg
#define P64H_SYSC_SW_SVC_CFG_SIZE sizeof(p64h_sysc_svc_cfg_t)    ///<  Maximum size of sysc service cfg
#define P64H_SYSC_ACOT_CFG_SIZE   sizeof(p64h_sysc_acot_t)       ///<  Maximum size of acot cfg binary

/**
 * @brief
 * This struct packs all cfg1 binaries in a blob
 */
typedef struct __attribute__((packed)) {
    p64h_sysc_cfg1_blobs_header_t header;                                ///< header info with file sizes
    uint8_t                       sysc_soc_cfg[P64H_SYSC_SOC_CFG_SIZE];  ///< pointer to sysc_soc_cfg
    uint8_t                       ddr_cfg[P64H_SYSC_DDR_CFG_SIZE];       ///< pointer to ddr cfg
    uint8_t                       sw_svc_cfg[P64H_SYSC_SW_SVC_CFG_SIZE]; ///< pointer to sysc service cfg
    uint8_t                       acot_cfg[P64H_SYSC_ACOT_CFG_SIZE];     ///< pointer to acot cfg
    uint8_t                       enet_sw[P64H_SYSC_ENET_SW_SIZE];       ///< pointer to enet switch
    uint8_t                       keys[P64H_SYSC_KEYS_CFG_SIZE];         ///< pointer to keys cfg
    uint8_t                       pq_fw[P64H_SYSC_PQ_FW_CFG_SIZE];       ///< pointer to pq_fw cfg
    uint8_t                       appc_zsbl[P64H_SYSC_APPC_ZSBL_SIZE];   ///< pointer to appc zsbl
    uint8_t                       appc_rnmi[P64H_SYSC_APPC_RNMI_SIZE];   ///< pointer to appc rnmi
} p64h_sysc_blobs_layout_t;

#endif // P64H_SYSC_BA_SYSC_BA_H
/// @}
