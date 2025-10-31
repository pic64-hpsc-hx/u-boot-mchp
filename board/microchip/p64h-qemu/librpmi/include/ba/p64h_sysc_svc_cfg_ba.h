/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file sysc_svc_cfg_ba.h
 * @brief Defines service configuration types
 */

#ifndef P64H_SYSC_SVC_CFG_BA_H
#define P64H_SYSC_SVC_CFG_BA_H

#include "p64h_sysc_appc_ba.h"
#include <generated/p64h_sysc_components.h>

#define P64H_SYSC_APPC_BOOT_CFG_PIN_MAP_MAX 8u    ///< maximun number of AppC boot configuration mappable to boot_cfg pins
#define P64H_SYSC_APPC_BOOT_CFG_MAX         16u   ///< maximun number of AppC boot configuration
#define P64H_SYSC_NUM_METADATA_MAX          3u    ///< maximun number of metadata
#define P64H_SYSC_APPC_BOOT_CFG_STRING_MAX  256UL ///< maximun string size for appc boot cfg name

/// Sysc power frequency mode
typedef enum {
    P64H_SYSC_PWR_FREQ_MODE_PMM = 0x0u, ///< performance mode MAX
    P64H_SYSC_PWR_FREQ_MODE_PM1,        ///< performance mode mode 1
    P64H_SYSC_PWR_FREQ_MODE_PM2,        ///< performance mode mode 2
    P64H_SYSC_PWR_FREQ_MODE_PM3,        ///< performance mode mode 3
    P64H_SYSC_PWR_FREQ_MODE_PM4,        ///< performance mode mode 4
    P64H_SYSC_PWR_FREQ_MODE_SLEEP       ///< sleep mode
} p64h_sysc_pwr_freq_mode_t;

/// Sysc health check mode
typedef enum {
    P64H_SYSC_HEALTH_CHK_DISABLE = 0x0u, ///< health check disable
    P64H_SYSC_HEALTH_CHK_CHECK_NO_FIXUP, ///< health check enable but no attempt to fixup
    P64H_SYSC_HEALTH_CHK_CHECK_FIXUP     ///< health check enable, sysc will try to fixup
} p64h_sysc_health_chk_mode_t;

/// sysc RAS notification type
typedef enum {
    RAS_NOTIF_TYPE_NONE = 0,  ///< notification disabled
    RAS_NOTIF_TYPE_POLLING,   ///< polling
    RAS_NOTIF_TYPE_INTERRUPT, ///< interrupt driven
} p64h_sysc_ras_notif_type_t;

/// RPMI queue interrupt mode
typedef enum {
    P64H_SYSC_RPMI_Q_INT_MODE_NONE = 0x0u, ///< interrupt are not used, polling shall be used to access
    P64H_SYSC_RPMI_Q_INT_MODE_REQ_ONLY,    ///< interrupt are used in request direction only, polling is used for get response
    P64H_SYSC_RPMI_Q_INT_MODE_BOTH         ///< interrupts are used on request and response side
} p64h_sysc_rpmi_q_int_mode_t;

/// RPMI access_control enum list
typedef enum {
    P64H_SYSC_ACCESS_NONE            = 0u, ///< No access
    P64H_SYSC_ACCESS_USER            = 1u, ///< Very limited access such as sysc version
    P64H_SYSC_ACCESS_PARTITION_OWNER = 2u, ///< have view on his own partition:
                                           ///<   - RAS, TRACE, LOG
    P64H_SYSC_ACCESS_SYSTEM_OWNER = 3u,    ///< have view and control on his own partition
                                           ///<   - can transition boot_cfg
                                           ///<   - can do firmware upgrades
                                           ///<   - can do power management
    P64H_SYSC_ACCESS_SUPER_OWNER = 4u,     ///< On top of system owner:
                                           ///<   - can program OTP
    LAST_P64H_SYSC_ACCESS                  ///< range check
} p64h_sysc_rpmi_access_control_t;

/// power per cluster sleep mode
typedef enum {
    P64H_SYSC_CLUSTER_SLEEP_MODE_POWER = 0u, ///< cluster power gated in sleep mode
    P64H_SYSC_CLUSTER_SLEEP_MODE_RESET = 1u, ///< cluster cores in reset in sleep mode
    P64H_SYSC_CLUSTER_SLEEP_MODE_WFI   = 2u, ///< cluster cores in WFI in sleep mode
    LAST_P64H_SYSC_CLUSTER_SLEEP_MODE        ///< range check
} p64h_sysc_cluster_sleep_mode_t;

/// operation mode
typedef enum {
    P64H_SYSC_OPERATION_NORMAL      = 0u, ///< The system boot service normal
    P64H_SYSC_OPERATION_SWITCH_ONLY = 1u, ///< The system boot service with switch only
    P64H_SYSC_OPERATION_SAFE_MODE   = 2u, ///< The system boot service with safe mode
    LAST_P64H_SYSC_OPERATION_MODE         ///< range check
} p64h_sysc_op_mode_t;

/// system service buffer configuration
typedef struct {
    uint32_t base_addr_lo; ///< base_addr
    uint32_t base_addr_hi; ///< base_addr
    uint32_t buf_size;     ///< buf_size
} p64h_sysc_svc_buf_desc_t;

/// system service rpmi client configuration
typedef struct p64h_sysc_svc_rpmi_client_t {
    bool                            enable;             ///< enable
    p64h_sysc_svc_buf_desc_t        memory_region;      ///< memory_region
    uint32_t                        slot_size;          ///< slot size
    uint32_t                        p2a_queue_size;     ///< Platform 2 app queue size
    uint32_t                        a2p_queue_size;     ///< App 2 platform queue size
    uint32_t                        io_type;            ///< rpmi peripheral type
    p64h_sysc_rpmi_q_int_mode_t     p2a_queue_int_mode; ///< P2A queue interrupt mode
    p64h_sysc_rpmi_q_int_mode_t     a2p_queue_int_mode; ///< A2P queue interrupt mode
    p64h_sysc_rpmi_access_control_t access_control;     ///< access control level
    bool req_posted; ///< default false, when true API send req, check resp and return a message when response is not available
} p64h_sysc_svc_rpmi_client_t;

/// system service enable
typedef struct {
    p64h_sysc_op_mode_t op_mode;       ///< operation mode
    bool                crypto_enable; ///< Enable the Cryptographic Engine.
                                       ///< Required to support secure and to provide cryptographic service to AppC.
                                       ///< Only valid when op_mode is NORMAL
} p64h_sysc_op_cfg_t;

/// sysc power cluster configuration
typedef struct {
    uint8_t pipeline_utilization;              ///< pipeline utilization = (1-value/16)
                                               ///< 0 : 100%
                                               ///< ...
                                               ///< 15 : 6.25%
    p64h_sysc_cluster_sleep_mode_t sleep_mode; ///< cluster sleep mode
} p64h_sysc_pwr_cluster_cfg_t;

/// power wakeup type
typedef enum {
    P64H_SYSC_PWR_WAKEUP_TYPE_TIMER = 0u,
    P64H_SYSC_PWR_WAKEUP_TYPE_GPIO  = 1u,
    P64H_SYSC_PWR_WAKEUP_TYPE_API   = 2u,
    P64H_SYSC_PWR_WAKEUP_TYPE_RAS   = 3u,
    LAST_P64H_SYSC_PWR_WAKEUP_TYPE
} p64h_sysc_pwr_wakeup_type_t;

/// sysc power wakeup configuration
typedef struct {
    bool     enable[LAST_P64H_SYSC_PWR_WAKEUP_TYPE]; ///< determine which wakeup is enabled
    uint64_t timer_interval;                         ///< timer interval, 0 means is disabled
    uint8_t  gpio_id;                                ///< gpio identifier
    uint8_t  ras_profile_id;                         ///< ras profile identifier
} p64h_sysc_pwr_wakeup_cfg_t;

/// sysc power configuration
typedef struct {
    p64h_sysc_pwr_freq_mode_t   freq_mode;            ///< power mode
    bool                        sleep_mode_ddr_alive; ///< true: DDR is maintained in sleep mode and scrubbing is enabled, false: DDR is power down
    bool                        sleep_mode_sw_alive;  ///< true: switch is maintained in sleep mode, false: switch is power down
    p64h_sysc_pwr_cluster_cfg_t cluster_cfg[APPC_CLUSTER_NUM]; ///< power cluster configuration
    p64h_sysc_pwr_wakeup_cfg_t  wakeup_cfg;                    ///< wakeup configuration
} p64h_sysc_pwr_cfg_t;

///< sysc wguard configuration
typedef struct {
    uint8_t spw;    ///< wid for sys Spacewire
    uint8_t sysdma; ///< wid for System Controller DMA
    uint8_t secdma; ///< wid for Secure Controller DMA
    uint8_t sys;    ///< wid for S7 System port initiator
} p64h_sysc_wg_cfg_t;

///< firmware update configuration
typedef struct {
    p64h_sysc_svc_buf_desc_t memory_region; ///< memory_region
    uint32_t                 max_pkg_size;  ///< max firmware update package size
} p64h_sysc_svc_fw_update_cfg_t;

/// system service configuration
typedef struct {
    p64h_sysc_op_cfg_t            op_cfg;          ///< sysc operation configuration
    p64h_sysc_svc_fw_update_cfg_t fw_update;       ///< firmware update configuration
    p64h_sysc_health_chk_mode_t   health_chk_mode; ///< health check configuration
    p64h_sysc_wg_cfg_t            wg;              ///< wguard configuration
    p64h_sysc_pwr_cfg_t           power;           ///< power configuration
} p64h_sysc_svc_system_cfg_t;

/// com service configuration
typedef struct {
    p64h_sysc_svc_rpmi_client_t rpmi_client;       ///< rpmi_client
    bool                        serial_com_enable; ///< enable serial communication
    p64h_sysc_uart_inst_id_t    uart_id;           ///< UART identifier
    uint32_t                    ipc1_chnl_mask;    ///< IPC1 channels' mask
} p64h_sysc_svc_com_cfg_t;

/// system trace service configuration
typedef struct {
    p64h_sysc_svc_buf_desc_t buf; ///< buf
} p64h_sysc_svc_trace_cfg_t;

/// @brief IO port type used by EM service to serialize errors
typedef enum {
    RAS_EM_IO_PORT_NONE = 0, ///< UART io port
    RAS_EM_IO_PORT_UART,     ///< UART io port
    RAS_EM_IO_PORT_ENET_EP,  ///< ENET EP io port
} p64h_sysc_ras_em_io_port_type_t;

/// @brief IO port ID used by EM service to serialize errors
typedef union {
    p64h_sysc_enet_ep_inst_id_t uart_id;    ///< ENET EP ID
    p64h_sysc_uart_inst_id_t    enet_ep_id; ///< UART ID
} p64h_sysc_ras_em_io_port_id_t;

/// @brief IO port cfg for EM service
typedef struct {
    p64h_sysc_ras_em_io_port_type_t type; ///< IO port type
    p64h_sysc_ras_em_io_port_id_t   id;   ///< IO port ID
} p64h_sysc_ras_em_io_port_cfg_t;

/// @brief Persistent storage file management policy
typedef enum {
    RAS_EM_PERSIST_FILE_MNG_NONE     = 0, ///< No policy
    RAS_EM_PERSIST_FILE_MNG_CIRC_TBL = 0, ///< Circular table policy
    RAS_EM_PERSIST_FILE_MNG_B_TBL,        ///< Bounded table policy
    RAS_EM_PERSIST_FILE_MNG_UB_TBL,       ///< Unbounded table policy
} p64h_sysc_ras_em_persist_file_mng_t;

/// @brief Persistent storage for EM service
typedef struct {
    bool                                enable;     ///< Persistent memory storage enable
    p64h_sysc_ras_em_persist_file_mng_t mng_policy; ///< IO port ID
} p64h_sysc_ras_em_persist_cfg_t;

/// system error monitor RAS service configuration
typedef struct {
    p64h_sysc_ras_em_io_port_cfg_t io_port;            ///< IO port configuration
    p64h_sysc_ras_em_persist_cfg_t persistent_storage; ///< Persistent storage
    uint32_t                       init_profile_id;    ///< Initial error monitoring profile ID for the SysC
    p64h_sysc_svc_buf_desc_t       ras_priv;           ///< RAS private buffer
} p64h_sysc_svc_em_ras_cfg_t;

/// system error response RAS service configuration
typedef struct {
    p64h_sysc_ras_em_persist_cfg_t persistent_storage; ///< Persistent storage
    uint32_t                       init_profile_id;    ///< Initial error response profile ID for the SysC
} p64h_sysc_svc_er_ras_cfg_t;

/// @brief SysC WDOG FSBL initialization configuration
typedef struct {
    uint32_t first_window_lo;  ///< First window expiry configuration (lower bits)
    uint32_t first_window_hi;  ///< First window expiry configuration (higher bits)
    uint32_t second_window_lo; ///< Second window expiry configuration (lower bits)
    uint32_t second_window_hi; ///< Second window expiry configuration (higher bits)
} p64h_sysc_sysc_wdog_cfg_t;

/// @brief Scrubber base configuration fields
typedef struct {
    bool                     auto_scrubbing_en;   ///< auto scrubbing enabled (periodic)
    uint32_t                 scrubbing_period_lo; ///< Scrubbing period (lower bits)
    uint32_t                 scrubbing_period_hi; ///< Scrubbing period (higher bits)
    p64h_sysc_svc_buf_desc_t range;               ///< Scrubbing range
    p64h_sysc_svc_buf_desc_t excl_range[5];       ///< Exclusion regions within range (up to 5)
} p64h_sysc_scrubber_base_cfg_t;

/// @brief SW scrubber configuration
typedef struct {
    p64h_sysc_scrubber_base_cfg_t scrubber_base_cfg; ///< Base configuration
} p64h_sysc_sw_scrubber_cfg_t;

/// @brief HW scrubber configuration
typedef struct {
    p64h_sysc_scrubber_base_cfg_t scrubber_base_cfg;    ///< Base configuration
    uint32_t                      priority;             ///< Scrubber priority over transaction
    uint32_t                      correction_threshold; ///< Correction threshold
    uint32_t                      correction_mask;      ///< Correction mask
} p64h_sysc_hw_scrubber_cfg_t;

/// @brief Scrubbers defaults
typedef struct {
    p64h_sysc_sw_scrubber_cfg_t itim;              ///< ITIM scrubber type default configuration
    p64h_sysc_sw_scrubber_cfg_t dls;               ///< DLS scrubber type default configuration
    p64h_sysc_sw_scrubber_cfg_t l1i;               ///< L1I scrubber type default configuration
    p64h_sysc_sw_scrubber_cfg_t l1d;               ///< L1D scrubber type default configuration
    p64h_sysc_sw_scrubber_cfg_t pl2;               ///< PL2 scrubber type default configuration
    p64h_sysc_sw_scrubber_cfg_t ec3;               ///< EC3 scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t nvm_sram;          ///< NVM_SRAM scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t ddr;               ///< DDR scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t appc_ocr;          ///< APPC_OCR scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t sysc_ocr;          ///< SYSC_OCR scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t secc_ocr;          ///< SECC_OCR scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t secc_pqcrypto_mem; ///< SECC_PQCRYPTO_MEM scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t appdma_fifo;       ///< APPDMA_FIFO scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t enet_tcam;         ///< ENET_TCAM scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t secc_pqcrypto;     ///< SECC_PQCRYPTO scrubber type default configuration
    p64h_sysc_hw_scrubber_cfg_t secc_mbox;         ///< SECC_MBOX scrubber type default configuration
} p64h_sysc_def_scrubber_cfg_t;

/// system health RAS service configuration
typedef struct {
    uint32_t                     init_profile_id;   ///< Initial error response profile ID for the SysC
    p64h_sysc_sysc_wdog_cfg_t    wdog;              ///< WDOG configuration
    bool                         boot_hc_enable;    ///< Execute boot health check sequence;
    p64h_sysc_def_scrubber_cfg_t def_scrubbers_cfg; ///< Default configuration for scrubber types
} p64h_sysc_svc_health_ras_cfg_t;

/// system controller service configurations
typedef struct {
    bool                           svc_enabled[P64H_SYSC_NUM_SVC_COMP]; ///< enabled services
    p64h_sysc_svc_system_cfg_t     system;                              ///< system service configuration
    p64h_sysc_svc_com_cfg_t        com;                                 ///< com service configuration
    p64h_sysc_svc_trace_cfg_t      trace;                               ///< system trace service configuration
    p64h_sysc_svc_em_ras_cfg_t     em_ras;                              ///< system em_ras service configuration
    p64h_sysc_svc_er_ras_cfg_t     er_ras;                              ///< system er_ras service configuration
    p64h_sysc_svc_health_ras_cfg_t health_ras;                          ///< system health_ras service configuration
} p64h_sysc_svc_cfg_t;

typedef struct {
    p64h_sysc_svc_buf_desc_t log; ///< log
} p64h_sysc_soc_svc_system_cfg_t;

/// trace service partition configuration
typedef struct {
    uint32_t cfg0; ///< cfg0
} p64h_sysc_svc_part_trace_cfg_t;

/// appc trace service configuration
typedef struct {
    p64h_sysc_svc_buf_desc_t       buf;                                             ///< Trace buffer
    p64h_sysc_svc_part_trace_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration
} p64h_sysc_soc_svc_trace_cfg_t;

/// appc error monitor RAS service configuration
typedef struct {
    bool                       agent_active;    ///< Partition RAS agent supports error reporting
    p64h_sysc_ras_notif_type_t notif;           ///< Notification method
    p64h_sysc_svc_buf_desc_t   appc_em;         ///< Buffer region to configure if agent_active
    uint32_t                   init_profile_id; ///< Initial error monitoring profile ID for the partition
} p64h_sysc_svc_part_em_ras_cfg_t;

/// appc error monitor RAS service configuration
typedef struct {
    p64h_sysc_svc_buf_desc_t        mon_buf;
    p64h_sysc_svc_part_em_ras_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration
} p64h_sysc_soc_svc_em_ras_cfg_t;

/// error response RAS service partition configuration
typedef struct {
    bool                       agent_active;    ///< Partition RAS agent supports error response reporting
    p64h_sysc_ras_notif_type_t notif;           ///< Notification method
    p64h_sysc_svc_buf_desc_t   appc_er;         ///< Buffer region to configure if agent_active
    uint32_t                   init_profile_id; ///< Initial error monitoring profile ID for the partition
} p64h_sysc_svc_part_er_ras_cfg_t;

/// error response RAS service configuration
typedef struct {
    p64h_sysc_svc_part_er_ras_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration
} p64h_sysc_soc_svc_er_ras_cfg_t;

/// health RAS service partition configuration
typedef struct {
    uint32_t init_profile_id; ///< Initial error monitoring profile ID for the partition
} p64h_sysc_svc_part_health_ras_cfg_t;

/// health RAS service configuration
typedef struct {
    p64h_sysc_svc_part_health_ras_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration
} p64h_sysc_soc_svc_health_ras_cfg_t;

/// com service partition configuration
typedef struct {
    p64h_sysc_svc_rpmi_client_t rpmi_client_s; ///< rpmi_client
    p64h_sysc_svc_rpmi_client_t rpmi_client_m; ///< rpmi_client
} p64h_sysc_svc_part_com_cfg_t;

/// com service configuration
typedef struct {
    p64h_sysc_svc_rpmi_client_t  sys_buf;                                         ///< system com buffer
    p64h_sysc_svc_part_com_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration
} p64h_sysc_soc_svc_com_cfg_t;

/// Transfer parameters for each service with a SoC svc cfg
typedef struct {
    size_t cfg_offset; ///< Offset of the service's config within the global struct
    size_t cfg_size;   ///< Size of the config in bytes
} p64h_sysc_soc_svc_trans_params_t;

typedef struct {
    p64h_sysc_soc_svc_trans_params_t   trans_params[P64H_SYSC_NUM_SVC_COMP]; ///< Transfer parameters to direct the configs to the right services
    p64h_sysc_soc_svc_system_cfg_t     system;                               ///< system service configuration
    p64h_sysc_soc_svc_com_cfg_t        com;                                  ///< com service configuration
    p64h_sysc_soc_svc_trace_cfg_t      trace;                                ///< appc partition trace service configuration
    p64h_sysc_soc_svc_em_ras_cfg_t     em_ras;                               ///< appc partition em_ras service configuration
    p64h_sysc_soc_svc_er_ras_cfg_t     er_ras;                               ///< appc partition er_ras service configuration ENABLE WHEN READY
    p64h_sysc_soc_svc_health_ras_cfg_t health_ras;                           ///< appc partition health_ras service configuration
} p64h_sysc_soc_svc_cfg_t;

#endif // P64H_SYSC_SVC_CFG_BA_H