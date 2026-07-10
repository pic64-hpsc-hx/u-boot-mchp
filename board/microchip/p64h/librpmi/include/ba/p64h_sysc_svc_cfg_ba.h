/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file sysc_svc_cfg_ba.h
 * @brief Defines service configuration types
 */

#ifndef P64H_SYSC_SVC_CFG_BA_H
#define P64H_SYSC_SVC_CFG_BA_H

#include "p64h_sysc_appc_ba.h"
#include "types/p64h_sysc_ras_em_types.h"
#include <generated/p64h_sysc_components.h>
#include "types/p64h_sysc_trace_types.h"

#define P64H_SYSC_APPC_BOOT_CFG_PIN_MAP_MAX 8u    ///< maximum number of AppC boot configuration mappable to boot_cfg pins
#define P64H_SYSC_APPC_BOOT_CFG_MAX         16u   ///< maximum number of AppC boot configuration
#define P64H_SYSC_NUM_METADATA_MAX          3u    ///< maximum number of metadata
#define P64H_SYSC_APPC_BOOT_CFG_STRING_MAX  256UL ///< maximum string size for appc boot cfg name
#define P64H_SYSC_NUM_NOC_TRACE_CFG         32U   ///< maximum number of noc trace datapath that can be set up during boot

/// maximum content length (excluding NUL terminator) of the master passphrase
/// used to gate p64h_sysc_psm_perms_set. Storage buffers must be sized
/// P64H_PSM_PASSPHRASE_MAX_LEN + 1 to hold the content plus a trailing NUL.
#define P64H_PSM_PASSPHRASE_MAX_LEN 64u

/// Core clock frequency (Hz)
#define P64H_CORE_CLK_FREQ_NA     0U          ///< Core clock frequency is not available.
#define P64H_CORE_CLK_FREQ_25MHZ  25000000U   ///< Core clock frequency set to 25 MHz.
#define P64H_CORE_CLK_FREQ_100MHZ 100000000U  ///< Core clock frequency set to 100 MHz.
#define P64H_CORE_CLK_FREQ_500MHZ 500000000U  ///< Core clock frequency set to 500 MHz.
#define P64H_CORE_CLK_FREQ_900MHZ 900000000U  ///< Core clock frequency set to 900 MHz.
#define P64H_CORE_CLK_FREQ_1GHZ   1000000000U ///< Core clock frequency set to 1 GHz.

/* psm_types.h transitively pulls in sysc_ba.h, which uses P64H_SYSC_APPC_BOOT_CFG_MAX
 * from this file — keep this include below the macro definitions above. */
#include "types/p64h_sysc_psm_types.h"

/// Sysc power frequency mode
typedef enum {
    P64H_SYSC_PWR_FREQ_MODE_PMM = 0x0u, ///< performance mode MAX
    P64H_SYSC_PWR_FREQ_MODE_PM1,        ///< performance mode mode 1
    P64H_SYSC_PWR_FREQ_MODE_PM2,        ///< performance mode mode 2
    P64H_SYSC_PWR_FREQ_MODE_PM3,        ///< performance mode mode 3
    P64H_SYSC_PWR_FREQ_MODE_PM4,        ///< performance mode mode 4
    P64H_SYSC_PWR_FREQ_MODE_SLEEP,      ///< sleep mode
    LAST_P64H_SYSC_PWR_FREQ_MODE,       ///< range check
} p64h_sysc_pwr_freq_mode_t;

/// Sysc health check mode
typedef enum {
    P64H_SYSC_HEALTH_CHK_DISABLE = 0x0u, ///< health check disable
    P64H_SYSC_HEALTH_CHK_CHECK_NO_FIXUP, ///< health check enable but no attempt to fixup
    P64H_SYSC_HEALTH_CHK_CHECK_FIXUP     ///< health check enable, sysc will try to fixup
} p64h_sysc_health_chk_mode_t;

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
    uint32_t                        a2p_slot_size;      ///< A2P slot size
    uint32_t                        p2a_slot_size;      ///< P2A slot size
    uint32_t                        p2a_queue_size;     ///< Platform 2 app queue size
    uint32_t                        a2p_queue_size;     ///< App 2 platform queue size
    uint32_t                        io_type;            ///< rpmi peripheral type
    p64h_sysc_rpmi_q_int_mode_t     p2a_queue_int_mode; ///< P2A queue interrupt mode
    p64h_sysc_rpmi_q_int_mode_t     a2p_queue_int_mode; ///< A2P queue interrupt mode
    p64h_sysc_rpmi_access_control_t access_control;     ///< access control level
    bool     req_posted;  ///< default false, when true API send req, check resp and return a message when response is not available
    uint32_t ipc_channel; ///< IPC channel ID
} p64h_sysc_svc_rpmi_client_t;

/// system service enable
typedef struct {
    p64h_sysc_op_mode_t op_mode;       ///< operation mode
    bool                crypto_enable; ///< Enable the Cryptographic Engine.
                                       ///< Required to support secure and to provide cryptographic service to AppC.
                                       ///< Only valid when op_mode is NORMAL
    bool debug_mode;                   ///< debug mode
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

/// Individual wakeup configuration
typedef struct {
    bool enable; ///< Whether this wakeup type is enabled
    union {
        struct {
            uint64_t interval; ///< Timer interval, 0 means disabled
            uint8_t  id;       ///< Timer identifier
        } timer;
        struct {
            uint8_t id;         ///< GPIO identifier
            uint8_t level_high; ///< GPIO level high triggers wakeup
        } gpio;
        struct {
            // API-specific fields can be added here
        } api;
        struct {
            uint8_t profile_id; ///< RAS profile identifier
        } ras;
    } cfg;
} p64h_sysc_pwr_wakeup_entry_t;

/// sysc power wakeup configuration
typedef struct {
    p64h_sysc_pwr_wakeup_entry_t entry[LAST_P64H_SYSC_PWR_WAKEUP_TYPE]; ///< entries of wakeup types
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
} p64h_sysc_svc_fw_update_cfg_t;

///< appc boot dma config
typedef struct {
    p64h_sysc_svc_buf_desc_t memory_region; ///< memory_region
} p64h_sysc_appc_boot_dma_cfg_t;

///< enet switch dma config
typedef struct {
    p64h_sysc_svc_buf_desc_t memory_region; ///< memory_region
} p64h_sysc_enet_switch_cfg_t;

/// system service configuration
typedef struct {
    p64h_sysc_op_cfg_t            op_cfg;            ///< sysc operation configuration
    p64h_sysc_svc_fw_update_cfg_t fw_update;         ///< firmware update configuration
    p64h_sysc_appc_boot_dma_cfg_t appc_boot_dma_cfg; ///< appc boot dma configuration
    p64h_sysc_health_chk_mode_t   health_chk_mode;   ///< health check configuration
    p64h_sysc_wg_cfg_t            wg;                ///< wguard configuration
    p64h_sysc_pwr_cfg_t           power;             ///< power configuration
} p64h_sysc_svc_system_cfg_t;

/// com service configuration
typedef struct {
    p64h_sysc_svc_rpmi_client_t rpmi_client;                                  ///< rpmi_client
    bool                        serial_com_enable;                            ///< enable serial communication
    p64h_sysc_uart_inst_id_t    uart_id;                                      ///< UART identifier
    uint32_t                    baudrate;                                     ///< UART baudrate
    char                        passphrase[P64H_PSM_PASSPHRASE_MAX_LEN + 1u]; ///< master passphrase gating PSM access level changes;
                                                                              ///< storage is MAX_LEN content chars + 1 NUL byte;
                                                                              ///< empty string disables elevation (deny-by-default)
} p64h_sysc_svc_com_cfg_t;

/// system trace service configuration
typedef struct {
    bool                      trace_enable;                               /// configure the device trace funnel
    p64h_sysc_trace_dev_cfg_t trace_dev_cfg;                              ///< device trace configuration
    p64h_sysc_noc_trace_cfg_t noc_trace_cfg[P64H_SYSC_NUM_NOC_TRACE_CFG]; ///< set up noc trace for up to NUM_NOC_TRACE_CFG datapath
} p64h_sysc_svc_trace_cfg_t;

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
    p64h_sysc_ras_em_persist_cfg_t persistent_storage;                  ///< Persistent storage
    uint32_t                       init_profile_id;                     ///< Initial error monitoring profile ID for the SysC
    p64h_sysc_svc_buf_desc_t       ras_priv;                            ///< RAS private buffer
    p64h_sysc_ras_em_prof_t        profiles[P64H_SYSC_RAS_EM_PROF_MAX]; ///< EM profiles
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

/// @brief configuration of a specifc scrubber instance (specified in microsecond)
typedef struct {
    bool     enable;    ///< Enable or disable the scrubber
    uint64_t period_us; ///< Scrubbing event period in microseconds.
} p64h_sysc_mem_scrubber_inst_cfg_t;

/// @brief configuration of a specifc scrubber instance (DDR/NVM EDAC)
typedef struct {
    bool     enable; ///< Enable or disable the scrubber
    uint64_t period; ///< Scrubbing event period defined by:
                     ///<   scrubing read period = EDAC_CLK_PERIOD * 2^(period+1) + EDAC_CLK_PERIOD
                     ///< where EDAC_CLK_PERIOD is clock of the EDAC (DDR=900Mhz, NVM = depend on memory ctrl configuration)
                     ///< Valid value for period is 0 to 35 where 0 is as fast as possible
                     ///< Examples for DDR:
                     ///< period | scrubbing period
                     ///<   0    | 3.33  ns
                     ///<   13   | 18.20 ps
                     ///<   24   | 37.28 ms
                     ///<   35   | 76.35 seconds
} p64h_sysc_mem_scrubber_edac_inst_cfg_t;

/// @brief Scrubbers defaults
typedef struct {
    /// secure controller scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_itim; ///< secure controller ITIM scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_l1i;  ///< secure controller L1 instruction cache scrubber
    /// system controller
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_itim; ///< system controller ITIM scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_dtim; ///< system controller DTIM scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_l1i;  ///< system controller L1 instruction cache scrubber
    /// application complex
    p64h_sysc_mem_scrubber_inst_cfg_t appc_itim; ///< application complex ITIM scrubber type default configuration
    p64h_sysc_mem_scrubber_inst_cfg_t appc_dls;  ///< application complex DLS scrubber type default configuration
    p64h_sysc_mem_scrubber_inst_cfg_t appc_l1i;  ///< application complex L1 instruction cache scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_l1d;  ///< application complex L1 data cache scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_pl2;  ///< application complex L2 cache scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_ec3;  ///< application complex L3 cache scrubber
} p64h_sysc_def_scrubber_cfg_t;

/// system health RAS service configuration
typedef struct {
    uint32_t                     init_profile_id;             ///< Initial error response profile ID for the SysC
    p64h_sysc_sysc_wdog_cfg_t    wdog;                        ///< WDOG configuration
    bool                         boot_hc_enable;              ///< Execute boot health check sequence;
    p64h_sysc_def_scrubber_cfg_t def_scrubbers_cfg;           ///< Default configuration for scrubber types
    uint64_t                     sysc_heart_beat_interval_us; ///< toggle sysc heartbeat BOOT_STAT;
    uint64_t                     secc_heart_beat_interval_us; ///< send 'alive' message to secure controller
    uint64_t                     secc_heart_beat_timeout_us;  ///< ask secure controller to reboot if 'alive' message not seen
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
    p64h_sysc_enet_switch_cfg_t    enet_switch;                         ///< enet switch dma configuration
} p64h_sysc_svc_cfg_t;

typedef struct {
    p64h_sysc_svc_buf_desc_t log; ///< log
} p64h_sysc_soc_svc_system_cfg_t;

/// trace service partition configuration
typedef struct {
    bool                       trace_enable;                           ///< partition-level master switch; if false, partition opts out of tracing
    uint16_t                   auto_start_te_mask;                     ///< TEs to enable at boot (bits outside owned set are ignored)
    p64h_sysc_trace_te_cfg_t   te_cfg[P64H_SYSC_TRACE_TE_LAST];        ///< per-TE config (only owned TEs are consumed)
    p64h_sysc_trace_sink_cfg_t sink_cfg[P64H_SYSC_TRACE_SINK_ID_LAST]; ///< per-sink config (first qualifying partition wins on shared sinks)
} p64h_sysc_svc_part_trace_cfg_t;

/// appc trace service configuration
typedef struct {
    p64h_sysc_svc_part_trace_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration (APPC PSMs)
    p64h_sysc_svc_part_trace_cfg_t sysc_cfg;                                        ///< SYSC PSM trace defaults
} p64h_sysc_soc_svc_trace_cfg_t;

/// appc error monitor RAS service configuration
typedef struct {
    bool                     agent_active;    ///< Partition RAS agent supports error reporting
    p64h_sysc_svc_buf_desc_t appc_em;         ///< Buffer region to configure if agent_active
    uint32_t                 init_profile_id; ///< Initial error monitoring profile ID for the partition
} p64h_sysc_svc_part_em_ras_cfg_t;

/// appc error monitor RAS service configuration
typedef struct {
    p64h_sysc_svc_buf_desc_t        mon_buf;
    p64h_sysc_svc_part_em_ras_cfg_t partition_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< Per-partition configuration
} p64h_sysc_soc_svc_em_ras_cfg_t;

/// error response RAS service partition configuration
typedef struct {
    bool                     agent_active;    ///< Partition RAS agent supports error response reporting
    p64h_sysc_svc_buf_desc_t appc_er;         ///< Buffer region to configure if agent_active
    uint32_t                 init_profile_id; ///< Initial error monitoring profile ID for the partition
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