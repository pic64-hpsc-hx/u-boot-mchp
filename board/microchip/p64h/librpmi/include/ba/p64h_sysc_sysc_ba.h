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
#define P64H_SYSC_SYSC_CFG_MAX_SIZE          0x400000
#define P64H_SYSC_CFG0_MIN_ALLOCATED_SIZE    3000
#define P64H_SYSC_CFG2_MIN_ALLOCATED_SIZE    3000
#define P64H_SYSC_SECC_FW_MIN_ALLOCATED_SIZE 30000

#define P64H_SYSC_SYSC_BOOT_CFG_MAX          8U            ///<  Maximum number of SysC boot cfg
#define P64H_SYSC_ENET_SW_SIZE               (2U * 1024UL) ///<  Maximum size of enet switch cfg
#define P64H_SYSC_KEYS_CFG_SIZE              (1U * 1024UL) ///<  Maximum size of keys cfg
#define P64H_SYSC_PQ_FW_CFG_SIZE             (1U * 1024UL) ///<  Maximum size of pq_fw cfg
#define P64H_SYSC_APPC_ZSBL_SIZE             (1U * 1024UL) ///<  Maximum size of zsbl binary
#define P64H_SYSC_APPC_RNMI_SIZE             (1U * 1024UL) ///<  Maximum size of rnmi binary
#define P64H_SYSC_MAX_FW_SCRIPT_CMDS         20U           ///< Maximum Number of supported FW SCRIPT COMMANDS

// ########################### Enumerations ##########################
/// Enumeration for OCR CTRL
typedef enum {
    P64H_SYSC_OCR_CTRL_APPC_0 = 0u, ///< OCR controller instance 0 (APP NoC peripheral)
    P64H_SYSC_OCR_CTRL_APPC_1,      ///< OCR controller instance 1 (APP NoC peripheral)
    P64H_SYSC_OCR_CTRL_SYSC,        ///< SYSC OCR Controller
    P64H_SYSC_OCR_CTRL_SECC_OCR,    ///< SECC OCR Controller
    P64H_SYSC_OCR_CTRL_PQ_OCR,      ///< PQ OCR Controller
    P64H_SYSC_OCR_CTRL_PQ_RAM,      ///< PQ RAM Controller
    P64H_SYSC_OCR_CTRL_LAST         ///< invalid, used for error checking
} p64h_sysc_ocr_ctrl_t;

/// Appc boot mode
typedef enum {
    P64H_SYSC_BOOT_MODE_BOOT_CFG_PIN = 0x0u, ///< system service boot appc based on boot_cfg pin
    P64H_SYSC_BOOT_MODE_NONE,                ///< system service do not boot appc
    P64H_SYSC_BOOT_MODE_FORCED,              ///< system service boot appc based on specified value
} p64h_sysc_appc_boot_mode_t;

/// Appc boot mode retry action in case of failure
typedef enum {
    P64H_SYSC_BOOT_RETRY_ACT_APPC_RST = 0x0u, ///< reset APPC boot configuration
    P64H_SYSC_BOOT_RETRY_ACT_SYSC_SOFT_RST,   ///< sysc soft reset
    P64H_SYSC_BOOT_RETRY_ACT_SYSC_SYS_RST,    ///< sysc system reset
    P64H_SYSC_BOOT_RETRY_ACT_SYSC_DEV_RST,    ///< sysc device reset
} p64h_sysc_appc_boot_retry_act_t;

/// Appc boot mode next action in case of failure
typedef enum {
    P64H_SYSC_BOOT_NEXT_ACT_STOP = 0x0u,            ///< stop execution
    P64H_SYSC_BOOT_NEXT_ACT_APPC_BOOT_CFG,          ///< next specified appc boot cfg
    P64H_SYSC_BOOT_NEXT_ACT_OTP_NEXT_SYSC_BOOT_CFG, ///< system service boot appc based on specified value
} p64h_sysc_appc_boot_next_act_t;

// fw update type enum
typedef enum {
    P64H_SYSC_SYSC_IMG_UPGRADE = 0,
    P64H_SYSC_APPC_IMG_UPGRADE,
    P64H_SYSC_OTP_BOOT_CFG_IMG_UPGRADE
} p64h_sysc_pkg_type_t;

// sysc overwrite options enum
typedef enum {
    P64H_SYSC_OVERWRITE_SYSC_IMG = 0,           ///< Complete Sysc Image
    P64H_SYSC_OVERWRITE_SYSC_FSBL,              ///< SysC FSBL
    P64H_SYSC_OVERWRITE_SYSC_CFG0,              ///< SysC cfg0
    P64H_SYSC_OVERWRITE_SYSC_CFG1_SYSC_SOC_CFG, ///< System-on-Chip configuration
    P64H_SYSC_OVERWRITE_SYSC_CFG1_DDR_CFG,      ///< DDR configuration
    P64H_SYSC_OVERWRITE_SYSC_CFG1_SW_SVC_CFG,   ///< Software service configuration
    P64H_SYSC_OVERWRITE_SYSC_CFG1_ACOT,         ///< AppC Images Offset Table
    P64H_SYSC_OVERWRITE_SYSC_CFG1_ENET_SW_CFG,  ///< Ethernet switch configuration
    P64H_SYSC_OVERWRITE_SYSC_CFG1_KEYS_CFG,     ///< Keys config
    P64H_SYSC_OVERWRITE_SYSC_CFG1_PQ_FW,        ///< PQ firmware
    P64H_SYSC_OVERWRITE_SYSC_CFG1_APPC_ZSBL,    ///< AppC ZSBL
    P64H_SYSC_OVERWRITE_SYSC_CFG1_APPC_RNMI,    ///< AppC RNMI
    P64H_SYSC_OVERWRITE_SYSC_CFG2,              ///< SysC cfg2
    P64H_SYSC_OVERWRITE_SYSC_SECC_FW,           ///< SecC fw
    P64H_SYSC_OVERWRITE_LAST
} p64h_sysc_sysc_overwrite_t;

// appc upgrade (overwrite or update) options enum
typedef enum {
    P64H_SYSC_UPGRADE_APPC_IMG_APPC_CFG = 0,               ///< full Appc Image
    P64H_SYSC_UPGRADE_APPC_IMG_ACOT,                       ///< Acot config (for full cfg upgrade)
    P64H_SYSC_UPGRADE_APPC_IMG_BOOTCFG_APPC_BOOTSCRIPT,    ///< Appc bootscript
    P64H_SYSC_UPGRADE_APPC_IMG_BOOTCFG_APPC_STATIC_CFG,    ///< Appc static config
    P64H_SYSC_UPGRADE_APPC_IMG_BOOTCFG_SW_SV_CFG,          ///< Appc bootcfg software service configuration
    P64H_SYSC_UPGRADE_APPC_IMG_BOOTCFG_PARTITION_APPC_CFG, ///< AppC partition config
    P64H_SYSC_UPGRADE_APPC_IMG_BOOTCFG_PARTITION_APPC_DTB, ///< AppC partition dtb
    P64H_SYSC_UPGRADE_APPC_IMG_APPC_BIN,                   ///< AppC boot artifact
    P64H_SYSC_UPGRADE_APPC_IMG_HW_PROF,                    ///< Whole hw profile (only valid for normal mode partial overwrite)
    P64H_SYSC_UPGRADE_APPC_IMG_ACOT_ENTRY,                 ///< Single ACOT entry (for hw_profile upgrade)
    P64H_SYSC_UPGRADE_APPC_IMG_LAST
} p64h_sysc_appc_upgrade_t;

typedef struct {
    uint8_t img_id;
    uint8_t side_img_id;
    bool    has_side_img;
} p64h_sysc_sysc_img_upgrade_info_t;

typedef struct {
    uint8_t img_id;
    bool    upgrade_b_side;
    bool    is_overwrite;
} p64h_sysc_appc_img_upgrade_info_t;

typedef union {
    p64h_sysc_sysc_img_upgrade_info_t sysc_img_upgrade_info;
    p64h_sysc_appc_img_upgrade_info_t appc_img_upgrade_info;
    // p64h_sysc_otp_boot_cfg_img_upgrade_info_t sysc_img_upgrade_info;
} p64h_sysc_pkg_type_info_t;

typedef enum {
    P64H_SYSC_FW_PKG_REBOOT_ACT_NONE,
    P64H_SYSC_FW_PKG_REBOOT_ACT_APPC_RST,
    P64H_SYSC_FW_PKG_REBOOT_ACT_SYSC_SOFT_RST,
    P64H_SYSC_FW_PKG_REBOOT_ACT_SYSC_SYS_RST,
    P64H_SYSC_FW_PKG_REBOOT_ACT_SYSC_DEV_RST,
    P64H_SYSC_FW_PKG_REBOOT_ACT_LAST
} p64h_sysc_fw_pkg_reboot_act_t;

typedef enum {
    P64H_SYSC_FW_PKG_ERASE_TYPE_CHIP_ERASE,
    P64H_SYSC_FW_PKG_ERASE_TYPE_SECTOR_ERASE,
    P64H_SYSC_FW_PKG_ERASE_TYPE_NO_ERASE,
    P64H_SYSC_FW_PKG_ERASE_TYPE_LAST
} p64h_sysc_fw_pkg_erase_type_t;

typedef struct {
    p64h_sysc_pkg_type_info_t     pkg_info;
    p64h_sysc_pkg_type_t          pkg_type;
    p64h_sysc_fw_pkg_reboot_act_t reboot_act;
    p64h_sysc_fw_pkg_erase_type_t erase_type;
} p64h_sysc_fw_pkg_info_t;

// typedef struct {
//     char fw_comp[P64H_SYSC_STRING_MAX];
// } p64h_sysc_otp_boot_cfg_test_data_t;

typedef enum {
    P64H_SYSC_SPLIT_UPGRADE_REQ_NONE = 0,
    P64H_SYSC_SPLIT_UPGRADE_REQ_SPLIT,
    P64H_SYSC_SPLIT_UPGRADE_REQ_SPLIT_FINISHED,
    P64H_SYSC_SPLIT_UPGRADE_REQ_LAST,
} p64h_sysc_split_upgrade_req_t;

typedef struct {
    uint64_t offset;               ///< gives the offset in artifact_data
    uint64_t total_size;           ///< total size of object being upgraded
    uint64_t split_size;           ///< size of current upgrade chunk (only valid if split_upgrade_req != BAAL_SPLIT_UPGRADE_REQ_NONE)
    uint64_t split_upgrade_offset; ///< offset in object data of current chunk (only valid if split_upgrade_req != BAAL_SPLIT_UPGRADE_REQ_NONE)
    uint64_t checksum;
    p64h_sysc_split_upgrade_req_t split_upgrade_req; ///< information on the split upgrade state of this command
} p64h_sysc_upgrade_cmd_data_t;

typedef struct {
    p64h_sysc_upgrade_cmd_data_t upgrade_cmd_data;
    p64h_sysc_sysc_overwrite_t   sysc_overwrite_type;
} p64h_sysc_sysc_img_wr_data_t;

typedef struct {
    p64h_sysc_upgrade_cmd_data_t upgrade_cmd_data;
    uint64_t                     acot_offset; ///< gives the offset in artifact_data for the acot. Only used for appc cfg overwrite
    uint8_t                      appc_cfg_id;
    uint8_t                      hw_prof_id;
    uint8_t                      partition_id; ///< Only used if upgrading partition artifact
    uint8_t                      appc_bin_id;
    p64h_sysc_appc_upgrade_t     appc_upgrade_type;
} p64h_sysc_appc_img_wr_data_t;

typedef union {
    // p64h_sysc_otp_boot_cfg_test_data_t otp_boot_cfg_test_data;
    p64h_sysc_sysc_img_wr_data_t sysc_img_wr_data;
    p64h_sysc_appc_img_wr_data_t appc_img_wr_data;
} p64h_sysc_fw_cmd_t;

/**
 * @brief
 * This struct packs all firmware script commands into one struct
 */
typedef struct {
    uint32_t           num_cmd;                            ///< Number of commands in fw script
    p64h_sysc_fw_cmd_t cmds[P64H_SYSC_MAX_FW_SCRIPT_CMDS]; ///< List of Commands in fw script
} p64h_sysc_fw_script_t;

/**
 * @brief
 * This struct contains a whole firmware upgrade package
 */
typedef struct {
    p64h_sysc_fw_pkg_info_t pkg_info;           ///< Package information
    p64h_sysc_fw_script_t   fw_script;          ///< Firmware script
    uint64_t                artifact_data_size; ///< Size in bytes of binary data section. TODO: maybe not needed
    uint8_t                 artifact_data[0];   ///< Artifact data section.
} p64h_sysc_fw_pkg_t;

/// enet switch configuration
typedef struct {
    uint8_t enabled; ///< whether the enet switch is enabled or not
    // add others config such as mapping GPIO mapping to switch features, etc. as needed
} p64h_sysc_enet_swr_cfg_t;

typedef struct {
    uint64_t                       cfg_size;          ///< appc cfg size
    uint64_t                       offset;            ///< offset in image
    uint8_t                        cs;                ///< the chip select where the entry will start
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
    uint8_t is_compact; ///< whether or not the AppC boot cfg entries are in compact mode or not (in normal mode if set to false)
    p64h_sysc_appc_boot_retry_act_t reboot_policy; // choices: [APPC_RST, SYSC_SOFT_RST, SYSC_SYSTEM_RST, SYSC_DEV_RST]
    p64h_sysc_nvm_noc_if_enc_t
        app_noc_if; ///< APP NOC interface (when it is P64H_SYSC_NVM_NOC_IF_LAST, it means there is no APPC image available)      
    p64h_sysc_crypto_cfg_t crypto_cfg;                           ///< appc config cryptographic configuration
    p64h_sysc_acot_entry_t entries[P64H_SYSC_APPC_BOOT_CFG_MAX]; ///< acot entries
} p64h_sysc_acot_t;

/**
 * @brief
 * Defines the configuration of the DDR EDAC
 */

/**
 * @brief
 *   OCR memory protection / scrubbing configuration
 *   Scrub event is configured in microseconds, and the controller will convert it to clock cycles based on the current frequency.
 */
/// OCR memory protection / scrubbing configuration
/// for 2 APPC OCRs CTRL and SYSC OCR CTRL
typedef struct {
    bool scrub_en;      ///< Enable auto-scrub(patrol-scrub) through memory addresses every (auto_scrub_period+1) clock cycles to perform atomic
                        ///< read-no_modify_writes
    bool self_scrub_en; ///< Enable the detection and scrubbing of correctable errors during memory transactions to the affected address and perform
                        ///< atomic read-no_modify_writes
    uint32_t auto_scrub_period_us; ///< Auto-scrub period in microseconds.
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

#define P64H_SYSC_TSN_NUM_DOMAINS 3U ///< Maximum number of TSN timing domains supported

/// TSN timing-domain operating mode
typedef enum {
    P64H_SYSC_TSN_DOMAIN_MODE_GRANDMASTER = 0u, ///< Domain drives the time reference onto the network
    P64H_SYSC_TSN_DOMAIN_MODE_SLAVE,            ///< Domain recovers the time reference from the network
    P64H_SYSC_TSN_DOMAIN_MODE_LAST              ///< Invalid, used for error checking
} p64h_sysc_tsn_domain_mode_t;

/// Grandmaster-mode time-source selector for a TSN timing domain
typedef enum {
    P64H_SYSC_TSN_GM_TIME_SOURCE_TOD = 0u, ///< Time-of-Day reference sourced inside the SoC (e.g. SoC Elapsed Timer)
    P64H_SYSC_TSN_GM_TIME_SOURCE_GPS,      ///< Time reference delivered by an external GPS / GNSS receiver over UART
    P64H_SYSC_TSN_GM_TIME_SOURCE_LAST      ///< Invalid, used for error checking
} p64h_sysc_tsn_grandmaster_time_source_t;

/// Slave-mode time-input port type for a TSN timing domain
typedef enum {
    P64H_SYSC_TSN_SLAVE_SOURCE_ENET_EP = 0u, ///< Slave input is an Ethernet endpoint timeReceiver port
    P64H_SYSC_TSN_SLAVE_SOURCE_SWITCH,       ///< Slave input is an Ethernet switch  timeReceiver port
    P64H_SYSC_TSN_SLAVE_SOURCE_LAST          ///< Invalid, used for error checking
} p64h_sysc_tsn_slave_source_t;

/**
 * @brief
 *   Grandmaster-mode configuration of a TSN timing domain.
 *   Fields are only interpreted when the owning domain has mode ==
 *   P64H_SYSC_TSN_DOMAIN_MODE_GRANDMASTER.
 */
typedef struct {
    p64h_sysc_tsn_grandmaster_time_source_t time_source;      ///< Source used to drive the grandmaster domain time
    p64h_sysc_uart_inst_id_t                gps_uart_port_id; ///< UART instance wired to the GPS receiver, used when time_source == GPS
} p64h_sysc_tsn_grandmaster_cfg_t;

/**
 * @brief
 *   Slave-mode configuration of a TSN timing domain.
 *   Fields are only interpreted when the owning domain has mode ==
 *   P64H_SYSC_TSN_DOMAIN_MODE_SLAVE.
 */
typedef struct {
    p64h_sysc_tsn_slave_source_t source;  ///< Type of port providing the slave time input
    uint8_t                      port_id; ///< Port index within the selected source (0..3 for ENET_EP, 0..15 for SWITCH)
} p64h_sysc_tsn_slave_cfg_t;

/**
 * @brief
 *   Per-domain TSN timing configuration.
 *   grandmaster_cfg or slave_cfg is interpreted based on the value of mode.
 */
typedef struct {
    bool                            enable;          ///< when true, the domain is active
    p64h_sysc_tsn_domain_mode_t     mode;            ///< domain role (GRANDMASTER or SLAVE)
    p64h_sysc_tsn_grandmaster_cfg_t grandmaster_cfg; ///< grandmaster-mode settings, valid when mode == GRANDMASTER
    p64h_sysc_tsn_slave_cfg_t       slave_cfg;       ///< slave-mode settings, valid when mode == SLAVE
} p64h_sysc_tsn_domain_cfg_t;

/**
 * @brief
 *   TSN timing configuration (IEEE 802.1AS / 802.1ASed).
 *   Covers the top-level enable, the active domain count, redundancy mode,
 *   and one p64h_sysc_tsn_domain_cfg_t per domain slot.
 */
typedef struct {
    bool                       enable;                             ///< when true, TSN timing is active
    uint8_t                    num_domains;                        ///< number of active domains, 1..P64H_SYSC_TSN_NUM_DOMAINS
    bool                       redundant_mode;                     ///< when true, domains form a fault-tolerant time set (802.1ASed FTT)
    p64h_sysc_tsn_domain_cfg_t domains[P64H_SYSC_TSN_NUM_DOMAINS]; ///< per-domain configuration
} p64h_sysc_tsn_timing_cfg_t;

/**
 * @brief
 *   Top-level Time-Sensitive Networking (TSN) configuration.
 */
typedef struct {
    p64h_sysc_tsn_timing_cfg_t timing_cfg; ///< TSN timing (gPTP) configuration
} p64h_sysc_tsn_cfg_t;

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
    p64h_sysc_enet_swr_cfg_t    enet_sw_cfg;                           ///< Switch Configuration
    p64h_sysc_ddr_edac_cfg_t    ddr_edac_cfg[P64H_SYSC_DDR_EDAC_IF];   ///< DDR EDAC configuration
    p64h_sysc_spw_cfg_t         sysc_spw_cfg;                          ///< SPW Configuration
    p64h_sysc_ocr_cfg_t         ocr_cfg[P64H_SYSC_OCR_CTRL_LAST];      ///< OCR memory protection / scrubbing configuration
    p64h_sysc_tsn_cfg_t         tsn_cfg;                               ///< TSN (Time-Sensitive Networking) configuration
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
    uint32_t sysc_soc_cfg_offset;   ///> offset of sysc_soc_cfg
    uint32_t sysc_soc_cfg_size;     ///> size of sysc_soc_cfg
    uint64_t sysc_soc_cfg_checksum; ///> checksum of sysc_soc_cfg, only valid if checksum is included in the blob
    uint32_t ddr_cfg_offset;        ///> offset of ddr_cfg
    uint32_t ddr_cfg_size;          ///> size of ddr_cfg
    uint64_t ddr_cfg_checksum;      ///> checksum of ddr_cfg, only valid if checksum is included in the blob
    uint32_t sw_svc_cfg_offset;     ///> offset of sw_svc_cfg
    uint32_t sw_svc_cfg_size;       ///> size of sw_svc_cfg
    uint64_t sw_svc_cfg_checksum;   ///> checksum of sw_svc_cfg, only valid if checksum is included in the blob
    uint32_t acot_cfg_offset;       ///> offset of acot_cfg
    uint32_t acot_cfg_size;         ///> size of acot_cfg
    uint64_t acot_cfg_checksum;     ///> checksum of acot_cfg, only valid if checksum is included in the blob
    uint32_t enet_sw_offset;        ///> offset of enet_sw
    uint32_t enet_sw_size;          ///> size of enet_sw
    uint64_t enet_sw_checksum;      ///> checksum of enet_sw, only valid if checksum is included in the blob
    uint32_t keys_offset;           ///> offset of keys
    uint32_t keys_size;             ///> size of keys
    uint64_t keys_checksum;         ///> checksum of keys, only valid if checksum is included in the blob
    uint32_t pq_fw_offset;          ///> offset of keys
    uint32_t pq_fw_size;            ///> size of keys
    uint64_t pq_fw_checksum;        ///> checksum of keys, only valid if checksum is included in the blob
    uint32_t appc_zsbl_offset;      ///> offset of appc_zsbl
    uint32_t appc_zsbl_size;        ///> size of appc_zsbl
    uint64_t appc_zsbl_checksum;    ///> checksum of appc_zsbl, only valid if checksum is included in the blob
    uint32_t appc_rnmi_offset;      ///> offset of appc_rnmi
    uint32_t appc_rnmi_size;        ///> size of appc_rnmi
    uint64_t appc_rnmi_checksum;    ///> checksum of appc_rnmi, only valid if checksum is included in the blob
    uint32_t padding;               ///> 32-bit padding for 64-bit alignment
} p64h_sysc_cfg1_blobs_header_t;

#define P64H_SYSC_SOC_CFG_SIZE    sizeof(p64h_sysc_soc_cfg_t)    ///<  Maximum size of sysc_soc_cfg
#define P64H_SYSC_DDR_CFG_SIZE    sizeof(p64h_sysc_ddr_ss_cfg_t) ///<  Maximum size of ddr cfg
#define P64H_SYSC_SW_SVC_CFG_SIZE sizeof(p64h_sysc_svc_cfg_t)    ///<  Maximum size of sysc service cfg
#define P64H_SYSC_ACOT_CFG_SIZE   sizeof(p64h_sysc_acot_t)       ///<  Maximum size of acot cfg binary

/**
 * @brief
 * This struct packs all cfg1 binaries in a blob
 */
typedef struct {
    p64h_sysc_cfg1_blobs_header_t header; ///< header info with file sizes
} p64h_sysc_blobs_layout_t;

#endif // P64H_SYSC_BA_SYSC_BA_H
/// @}
