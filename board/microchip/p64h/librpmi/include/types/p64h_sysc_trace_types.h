/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines trace types used by API, dev_cfg tool and sysc firmware
 */

#ifndef P64H_SYSC_TRACE_TYPES_H
#define P64H_SYSC_TRACE_TYPES_H

#include "p64h_sysc_common_types.h"
#include <ba/p64h_sysc_shared_ba.h>

/// Define number of NoC's for statistics collection
#define NOC_NUM 3u
/// Define the number of trace encoder in appc
#define NUM_APPC_TRACE_ENCODERS 4u

/// Macro for defining a packet route of interest
#define NOC_ROUTE(initiator_id_probe_index, target_id) ((target_id << 24) | initiator_id_probe_index)

/// Macro for defining enumerated value based on the counter number, action (response/request) , initiator ID and probe index
#define NOC_INITIATOR_ID_PROBE_INDEX(counter_max, action, initiator_id, probe_index)                                                                 \
    ((counter_max << 15) | (action << 14) | (probe_index << 8) | initiator_id)

/// Macro for defining hw description of the NoC for transaction profiling features
#define NOC_TRANS_PROFILE(external_event_num, trans_probe_index, trans_filter_index, observed_port, bins_max, counters_max)                          \
    ((external_event_num << 26) | (trans_probe_index << 21) | (trans_filter_index << 15) | (observed_port << 12) | (bins_max << 7) | (counters_max))

/* ---------------------------------------------------------------*/
// ### Structs and Enums for individual source level tracing configuration such as APPC_0 Core 0 Trace Encoder ###
/* ---------------------------------------------------------------*/

/**
 * trace data destination for sources of trace
 */
typedef enum {
    P64H_SYSC_TRACE_SRC_SINK_SRAM,          ///< Send trace data to local SRAM of source
    P64H_SYSC_TRACE_SRC_SINK_SYSTEM_MEMORY, ///< Send trace data to system memory directly from source sink
    P64H_SYSC_TRACE_SRC_SINK_ATB,           ///< Send trace data to ATB funnel and Trace SOK
} p64h_sysc_trace_source_sink_t;

/**
 * @brief
 * Trace encoder instruction message type
 **/
typedef enum {
    P64H_SYSC_TRACE_INSTRUCTION_GEN_DISABLED                      = 0, ///< Disable TE instruction message generation
    P64H_SYSC_TRACE_INSTRUCTION_GEN_EVENT_MODE                    = 1, ///< Event-based message generation
    P64H_SYSC_TRACE_INSTRUCTION_GEN_HTM_SYNC_WITHOUT_OPTIMIZATION = 6, ///< HTM (History branch message) and Sync message generation without
                                                                       ///< optimization such as repeat branch or return-address stack optimizations
    P64H_SYSC_TRACE_INSTRUCTION_GEN_HTM_SYNC_WITH_OPTIMIZATION = 7     ///< HTM (History branch message) and Sync message generation with optimization
                                                                       ///< such as repeat branch or return-address stack optimizations
} p64h_sysc_trace_te_btm_generation_type_t;

/**
 * @brief
 * Add timestamp field to branch messages if tsEnable=1
 **/
typedef enum {
    P64H_SYSC_TRACE_TS_BRANCH_DISABLE                       = 0x0, ///< No timestamp added to any branch trace messages
    P64H_SYSC_TRACE_TS_BRANCH_INDIRECT_JUMPS_AND_EXCEPTIONS = 0x1, ///< Timestamp added to indirect jumps and exceptions
    P64H_SYSC_TRACE_TS_BRANCH_ALL                           = 0x3  ///< Timestamp added to all branch trace messages
} p64h_sysc_trace_te_btm_timestamp_t;

/**
 * @brief
 * Maximum number of BTMs between periodic Sync messages. A Sync emitted for another reason will reset this timer.
 **/
typedef enum {
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_5     = 0x0, ///< Generate Sync after 2^5 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_6     = 0x1, ///< Generate Sync after 2^6 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_7     = 0x2, ///< Generate Sync after 2^7 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_8     = 0x3, ///< Generate Sync after 2^8 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_9     = 0x4, ///< Generate Sync after 2^9 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_10    = 0x5, ///< Generate Sync after 2^10 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_11    = 0x6, ///< Generate Sync after 2^11 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_12    = 0x7, ///< Generate Sync after 2^12 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_13    = 0x8, ///< Generate Sync after 2^13 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_14    = 0x9, ///< Generate Sync after 2^14 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_15    = 0xA, ///< Generate Sync after 2^15 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_2_16    = 0xB, ///< Generate Sync after 2^16 BTMs
    P64H_SYSC_TRACE_TESYNCMAXBTM_DISABLE = 0xF  ///< Do not generate Sync due to BTM count
} p64h_sysc_trace_te_syncMaxBTM_t;

/**
 * @brief
 * Maximum I-CNT between BTMs. A BTM emitted for another reason will reset this timer.
 **/
typedef enum {
    P64H_SYSC_TRACE_TESYNCMAXINST_2_5     = 0x0, ///< Generate Sync after 2^5 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_6     = 0x1, ///< Generate Sync after 2^6 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_7     = 0x2, ///< Generate Sync after 2^7 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_8     = 0x3, ///< Generate Sync after 2^8 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_9     = 0x4, ///< Generate Sync after 2^9 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_10    = 0x5, ///< Generate Sync after 2^10 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_11    = 0x6, ///< Generate Sync after 2^11 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_12    = 0x7, ///< Generate Sync after 2^12 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_13    = 0x8, ///< Generate Sync after 2^13 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_14    = 0x9, ///< Generate Sync after 2^14 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_2_15    = 0xA, ///< Generate Sync after 2^15 instruction halfwords
    P64H_SYSC_TRACE_TESYNCMAXINST_DISABLE = 0xF  ///< Do not generate Sync due to instruction count
} p64h_sysc_trace_te_syncMaxInst_t;

/**
 * @brief
 * Enumeration of Instrumentation messages type.
 **/
typedef enum {
    P64H_SYSC_TRACE_ITC_MSG_DQM_ONLY          = 1, ///< Only Data Acquisition Messages can be generated.
    P64H_SYSC_TRACE_ITC_MSG_OWNERSHIP_ONLY    = 2, ///< Only Ownership message can be generated on itcStimulus 15 to 31. Disable other ITC trace.
    P64H_SYSC_TRACE_ITC_MSG_OWNERSHIP_AND_DQM = 3, ///< DQM and Ownership messages can be generated. itcStimulus 15 to 31 will be reserved to
                                                   ///< ownership messages and remaining itcStimulus would be reserved to DQM messages.
    P64H_SYSC_TRACE_NO_ITC_MSG = 0,                ///< ITC messages generation disabled
} p64h_sysc_trace_te_itc_msg_type_t;

/**
 * @brief
 * Add timestamp field to branch messages if tsEnable=1
 **/
typedef enum {
    P64H_SYSC_TRACE_TS_INSTRUMENTATION_DISABLE = 0x0,  ///< No timestamp added to any instrumentation trace messages
    P64H_SYSC_TRACE_TS_INSTRUMENTATION_ITC_ONLY,       ///< Timestamp added to ITC messages
    P64H_SYSC_TRACE_TS_INSTRUMENTATION_OWNERSHIP_ONLY, ///< Timestamp added to ownership messages
    P64H_SYSC_TRACE_TS_INSTRUMENTATION_ALL             ///< Timestamp added to all instrumentation messages
} p64h_sysc_trace_te_itc_timestamp_t;
/**
 * ATB sink configuration for trace encoder
 */
typedef struct {
    uint32_t atb_id; ///< ATB ID
} p64h_sysc_trace_atb_sink_cfg_t;

/**
 * sram sink configuration for trace encoder
 */
typedef struct {
    p64h_sysc_trace_mem_mode_t mem_buff_mode; ///< memory buffer mode, circular buffer or stop on wrap
} p64h_sysc_trace_sram_sink_cfg_t;

/**
 * sink configuration for trace encoder
 */
typedef struct {
    p64h_sysc_trace_source_sink_t   sink;          ///< sink type
    p64h_sysc_trace_atb_sink_cfg_t  atb_sink_cfg;  ///< atb sink cfg
    p64h_sysc_trace_sram_sink_cfg_t sram_sink_cfg; ///< sram sink cfg
    p64h_sysc_trace_mem_cfg_t       sys_mem_cfg;   ///< sys mem sink cfg
} p64h_sysc_trace_te_sink_cfg_t;

/**
 * configuration for trace encoder instruction trace
 */
typedef struct {
    p64h_sysc_trace_te_btm_generation_type_t generation_type; ///< Type of HTM message, see p64h_sysc_trace_te_btm_generation_type_t
    p64h_sysc_trace_te_syncMaxBTM_t          sync_max_btm;    ///< Maximum number of BTMs between periodic Sync messages.
    p64h_sysc_trace_te_syncMaxInst_t         sync_max_inst;   ///< Maximum I-CNT between BTMs
    p64h_sysc_trace_te_btm_timestamp_t       timestamp;       ///< type of branch messages to add timestamp to Branch trace message
} p64h_sysc_trace_te_btm_cfg_t;

/**
 * configuration for trace encoder instrumentation trace
 */
typedef struct {
    uint32_t                           stimulus_channel_enable_mask; ///< Mask of ITC stimulus channels to enable.
    p64h_sysc_trace_te_itc_msg_type_t  itc_msg_type;                 ///< ITC messages or ownership message.  see p64h_sysc_trace_te_itc_msg_type_t
    p64h_sysc_trace_te_itc_timestamp_t timestamp; ///< message types in which timestamp will be included. see p64h_sysc_trace_te_itc_timestamp_t
} p64h_sysc_trace_te_itc_cfg_t;

/**
 * Source level configuration for Trace Encoder
 */
typedef struct {
    p64h_sysc_trace_te_btm_cfg_t btm_cfg; ///< configuration for instruction trace
    p64h_sysc_trace_te_itc_cfg_t itc_cfg; ///< configuration for instrumentation trace
} p64h_sysc_trace_te_cfg_t;

/**
 * Enum for TE cfg command
 */
typedef enum {
    P64H_SYSC_TRACE_TE_SET_SINK      = ONE_HOT(0), ///< configure the sink for this source
    P64H_SYSC_TRACE_TE_HART0_SET_ITC = ONE_HOT(1), ///< configure the ITC trace system for hart 0
    P64H_SYSC_TRACE_TE_HART0_SET_HTM = ONE_HOT(2), ///< configure the BTM trace system for hart 0
    P64H_SYSC_TRACE_TE_HART1_SET_ITC = ONE_HOT(3), ///< configure the ITC trace system for hart 1 (if available)
    P64H_SYSC_TRACE_TE_HART1_SET_HTM = ONE_HOT(4), ///< configure the BTM trace system for hart 1 (if available)
    P64H_SYSC_TRACE_TE_HART2_SET_ITC = ONE_HOT(5), ///< configure the ITC trace system for hart 2 (if available)
    P64H_SYSC_TRACE_TE_HART2_SET_HTM = ONE_HOT(6), ///< configure the BTM trace system for hart 2 (if available)
    P64H_SYSC_TRACE_TE_HART3_SET_ITC = ONE_HOT(7), ///< configure the ITC trace system for hart 3 (if available)
    P64H_SYSC_TRACE_TE_HART3_SET_HTM = ONE_HOT(8)  ///< configure the BTM trace system for hart 3 (if available)
} p64h_sysc_trace_te_cfg_cmd_t;

/**
 * Struct to configure APPC Trace sources
 */
typedef struct {
    p64h_sysc_trace_te_cfg_cmd_t  cmd_msk;                               ///< command mask for which cfg to set
    p64h_sysc_trace_te_cfg_t      core_te_cfgs[NUM_APPC_TRACE_ENCODERS]; ///< Core 0-3 trace encoder per cluster
    p64h_sysc_trace_te_sink_cfg_t sink_cfg;                              ///< sink cfg per cluster
} p64h_sysc_trace_appc_cfg_t;

/**
 * Struct to configure SYSC Trace sources
 */
typedef struct {
    p64h_sysc_trace_te_cfg_cmd_t  cmd_msk;     ///< command mask for which cfg to set
    p64h_sysc_trace_te_cfg_t      core_te_cfg; ///< Core 0 trace encoder
    p64h_sysc_trace_te_sink_cfg_t sink_cfg;    ///< sink cfg for sysc
} p64h_sysc_trace_sysc_cfg_t;

// NoC Statistics enumerations , structures and APIs
/**
 * @brief
 *  NoC type
 **/
typedef enum {
    APP_NOC_STATS, ///< APP NoC type statistics
    SYS_NOC_STATS, ///< SYS NoC type statistics
    DDR_NOC_STATS  ///< DDR NoC statistics
} p64h_sysc_noc_type_t;

/**
 * NoC statistics collection types
 */
typedef enum {
    P64H_SYSC_TRACE_NOC_STAT_TYPE_PACKETS,     ///< used for packet flow related features such as bandwidth measurement
    P64H_SYSC_TRACE_NOC_STAT_TYPE_TRANSACTIONS ///< used for transaction profiling features
} p64h_sysc_noc_stat_type_t;

/**
 * Struct containing NOC configuration for enabling tracing
 */
typedef struct {
    p64h_sysc_noc_type_t      noc_type;      ///< Target NoC
    p64h_sysc_noc_stat_type_t noc_stat_type; ///< NoC statistics type
    uint32_t port_id;      ///< initiator id (P64H_SYSC_TRACE_NOC_STAT_TYPE_PACKETS) or observed port id (P64H_SYSC_TRACE_NOC_STAT_TYPE_TRANSACTIONS)
    uint32_t async_period; ///< controls the period in observer clock cycles, between transmision of
                           /// STPV2 sychronization sequences
                           /// valid values 0 - 31
                           //  note: 0 means no sync sequence
                           // values 1-11 would be equivalent to a period of 2^(asyncperiod)
                           // values 23 -31 would be equivalent to a period of 2^23
    uint32_t atb_id;       ///< Unique ATB output ID of the NoC (used only if tracing_en = TRUE)
} p64h_sysc_noc_obs_cfg_t;

/**
 * @brief
 *   Specifies any information required to configure the tracing system of the device  (TO BE MADE OBSELETE)
 */
typedef struct {
    uint32_t                   sysc_trace_srcs;        ///< bitmask for individual sources to configure, see p64h_sysc_trace_src_t
    p64h_sysc_trace_appc_cfg_t appc_trace_cfg[2];      ///< configuration of 4 TE and 1 TF for each cluster
    p64h_sysc_trace_sysc_cfg_t sysc_trace_cfg;         ///< configuration for TE of sysc
    p64h_sysc_noc_obs_cfg_t    noc_trace_cfg[NOC_NUM]; ///< configuration for ddr noc trace system (APP_NOC - 0, SYSC_NOC - 1, DDR_NOC - 2)
} p64h_sysc_trace_sources_cfg_t;

/**
 * @brief
 *  Packet initiator points of interest used for performance monitoring through
 *   the APP NoC
 *
 * @note
 */
typedef enum {
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_MEM_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x0, 0), ///< CPU Cluster 0 Memory Port Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x1, 0), ///< CPU Cluster 0 System Port Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_MEM_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x0, 13), ///< CPU Cluster 0 Memory Port Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x1, 13), ///< CPU Cluster 0 System Port Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_MEM_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x2, 1), ///< CPU Cluster 1 Memory Port Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x3, 1), ///< CPU Cluster 1 System Port Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_MEM_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x2, 14), ///< CPU Cluster 1 Memory Port Initiator  response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x3, 14), ///< CPU Cluster 1 System Port Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_DDR_ENCRYPT_REQ = NOC_INITIATOR_ID_PROBE_INDEX(6, 0, 0x4, 2),   ///< DDR Encryption Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_DDR_ENCRYPT_RSP = NOC_INITIATOR_ID_PROBE_INDEX(6, 1, 0x4, 15),  ///< DDR Encryption Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_REQ   = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x5, 3),  ///< Ethernet Endpoint 0 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_REQ   = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x6, 3),  ///< Ethernet Endpoint 1 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_REQ   = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x7, 3),  ///< Ethernet Endpoint 2 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_REQ   = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x8, 3),  ///< Ethernet Endpoint 3 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_RSP   = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x5, 16), ///< Ethernet Endpoint 0 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_RSP   = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x6, 16), ///< Ethernet Endpoint 1 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_RSP   = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x7, 16), ///< Ethernet Endpoint 2 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_RSP   = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x8, 16), ///< Ethernet Endpoint 3 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA1_PIE_HIGH_BW_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x9, 4), ///< ENET Switch RDMA1 PIE high bandwith Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA1_ROCE_HIGH_BW_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0xA, 4), ///< ENET Switch RDMA1 ROCE high bandwith Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA1_ROCE_LOW_BW_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0xB, 4), ///< ENET Switch RDMA1 ROCE low bandwith Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA2_PIE_HIGH_BW_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0xC, 4), ///< ENET Switch RDMA2 PIE high bandwith Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA2_ROCE_HIGH_BW_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0xD, 4), ///< ENET Switch RDMA2 ROCE high bandwith Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA2_ROCE_LOW_BW_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0xE, 4), ///< ENET Switch RDMA2 ROCE low bandwith Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA1_PIE_HIGH_BW_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x9, 4), ///< ENET Switch RDMA1 PIE high bandwith Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA1_ROCE_HIGH_BW_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0xA, 17), ///< ENET Switch RDMA1 ROCE high bandwith Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA1_ROCE_LOW_BW_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0xB, 17), ///< ENET Switch RDMA1 ROCE low bandwith Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA2_PIE_HIGH_BW_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0xC, 17), ///< ENET Switch RDMA2 PIE high bandwith Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA2_ROCE_HIGH_BW_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0xD, 17), ///< ENET Switch RDMA2 ROCE high bandwith Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_SWR_RDMA2_ROCE_LOW_BW_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0xE, 17), ///< ENET Switch RDMA2 ROCE low bandwith Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_IOMMU0_REQ  = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0xF, 5),   ///< IOMMU0 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_IOMMU1_REQ  = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0x10, 5),  ///< IOMMU1 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_IOMMU0_RSP  = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0xF, 18),  ///< IOMMU0 Initiator respone path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_IOMMU1_RSP  = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0x10, 18), ///< IOMMU1 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SPW0_REQ    = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x11, 6),  ///< SPW0 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SPW1_REQ    = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x12, 6),  ///< SPW1 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_USB0_REQ    = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x13, 6),  ///< USB0 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_USB1_REQ    = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x14, 6),  ///< USB1 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SPW0_RSP    = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x11, 19), ///< SPW0 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SPW1_RSP    = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x12, 19), ///< SPW1 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_USB0_RSP    = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x13, 19), ///< USB0 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_USB1_RSP    = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x14, 19), ///< USB1 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_REQ = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x15, 7),  ///<  APP DMA 0  Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_REQ = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x16, 7),  ///< APP DMA 1 Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_TRACE_SOK_REQ
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 0, 0x17, 7), ///< TRACE SOK request and response APP NoC stats collection
    P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_RSP = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x15, 20), ///<  APP DMA 0  Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_RSP = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x16, 20), ///< APP DMA 1 Initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_TRACE_SOK_RSP
        = NOC_INITIATOR_ID_PROBE_INDEX(32, 1, 0x17, 20), ///< TRACE SOK request and response APP NoC stats collection
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_DMA0_REQ     = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x18, 8),  ///< NVM DMA0 request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_DMA1_REQ     = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x19, 8),  ///< NVM DMA1 request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_SD_DMA0_REQ  = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x1A, 8),  ///< NVM SD DMA0 request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_SD_DMA1_REQ  = NOC_INITIATOR_ID_PROBE_INDEX(24, 0, 0x1B, 8),  ///< NVM SD DMA1 request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_DMA0_RSP     = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x18, 21), ///< NVM DMA0 response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_DMA1_RSP     = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x19, 21), ///< NVM DMA1 response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_SD_DMA0_RSP  = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x1A, 21), ///< NVM SD DMA0 response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_NVM_SD_DMA1_RSP  = NOC_INITIATOR_ID_PROBE_INDEX(24, 1, 0x1B, 21), ///< NVM SD DMA1 response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_REQ = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0x1C, 9),  ///< PCIe0 CTRL0 initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_RSP = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0x1C, 22), ///< PCIe0 CTRL0 initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_REQ = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0x1D, 9),  ///< PCIe0 CTRL1 initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_RSP = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0x1D, 22), ///< PCIe0 CTRL1 initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_REQ = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0x1E, 10), ///< PCIe1 CTRL0 initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_RSP = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0x1E, 23), ///< PCIe1 CTRL0 initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_REQ = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0x1F, 10), ///< PCIe1 CTRL1 initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_RSP = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0x1F, 23), ///< PCIe1 CTR10 initiator response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SVC_NOC_REQ      = NOC_INITIATOR_ID_PROBE_INDEX(12, 0, 0x20, 10), ///< Service NoC request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SVC_NOC_RSP      = NOC_INITIATOR_ID_PROBE_INDEX(12, 1, 0x20, 23), ///< Service NoC response path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SYS_NOC_REQ      = NOC_INITIATOR_ID_PROBE_INDEX(6, 0, 0x21, 11),  ///<  SYS NOC Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_SYS_NOC_RSP      = NOC_INITIATOR_ID_PROBE_INDEX(6, 1, 0x21, 24),  ///<  SYS NOC Initiator request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_USER_CRYPTO_REQ  = NOC_INITIATOR_ID_PROBE_INDEX(6, 0, 0x22, 12),  ///< User Crypto request path
    P64H_SYSC_APP_NOC_STATS_INITIATOR_USER_CRYPTO_RSP  = NOC_INITIATOR_ID_PROBE_INDEX(6, 1, 0x22, 25),  ///< User Crypto response path

} p64h_sysc_app_noc_stats_initator_t;
/**
 * @brief
 *   Packet target points of interest used for measuring the total number of bytes through
 *   the APP NoC
 *
 * @note
 *   The enums below must follow the order set in the Arteris structure for the given pa_release
 */
typedef enum {
    P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT = 0x0, ///< CPU Cluster 0 Front Port Target
    // ...
    P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT = 0x2, ///< CPU Cluster 1 Front Port Target
    // ...
    P64H_SYSC_APP_NOC_STATS_TARGET_DDR_A_0 = 0x4, ///< DDR A0 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_DDR_A_1 = 0x5, ///< DDR A1 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0 = 0x6, ///< DDR B0 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1 = 0x7, ///< DDR B1 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_DDR_CFG = 0x8, ///< DDR CFG Target
    // .....
    P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL0 = 0x2C, ///< PCIe0 CTRL0 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL1 = 0x2D, ///< PCIe0 CTRL1 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL0 = 0x2F, ///< PCIe1 CTRL0 Target
    P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL1 = 0x30  ///< PCIe1 CTRL1 Target

    // The list will be expanded
} p64h_sysc_app_noc_stats_target_t;

/**
 * @brief
 *   Packet routes through the APP NoC
 *
 */
typedef enum {
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_MEM_PORT_0_TO_DDR_A_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_MEM_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_A_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_MEM_PORT_0_TO_DDR_A_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_MEM_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_A_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_MEM_PORT_0_FROM_DDR_A_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_MEM_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_A_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_MEM_PORT_0_FROM_DDR_A_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_MEM_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_A_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_TO_PCIE_0_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_TO_PCIE_0_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_TO_PCIE_1_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_TO_PCIE_1_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_TO_PCIE_0_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_TO_PCIE_0_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_TO_PCIE_1_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_TO_PCIE_1_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_FROM_PCIE_0_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_FROM_PCIE_0_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_FROM_PCIE_1_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_0_FROM_PCIE_1_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR0_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_FROM_PCIE_0_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_FROM_PCIE_0_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_0_CTRL1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_FROM_PCIE_1_CTRL0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_X280_SYS_PORT_1_FROM_PCIE_1_CTRL1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_CPU_CLSTR1_SYS_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_PCIE_1_CTRL1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_SYS_NOC_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_SYS_NOC_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_SYS_NOC_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_SYS_NOC_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_SYS_NOC_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_SYS_NOC_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_SYS_NOC_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_SYS_NOC_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_TO_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_TO_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_TO_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_TO_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_FROM_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_FROM_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_FROM_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_FROM_DDR_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_TO_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_TO_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_TO_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_TO_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_0_FROM_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_1_FROM_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_2_FROM_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_2_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_EP_3_FROM_DDR_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_ENET_EP_3_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_TO_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_TO_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_TO_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_TO_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_FROM_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_0_FROM_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_FROM_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_APPDMA_1_FROM_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_APPDMA1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_TO_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_TO_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_FROM_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_FROM_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL0_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_TO_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_TO_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_FROM_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_FROM_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_0_CTRL1_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_0_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_TO_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_TO_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_FROM_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_FROM_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL0_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL0_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_TO_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_TO_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_TO_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_TO_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_REQ, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1),

    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_FROM_CPU_CLSTR0_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR0_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_FROM_CPU_CLSTR1_FRONT
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_CPU_CLSTR1_FRONT),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_FROM_DDR_B_0
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_0),
    P64H_SYSC_APP_NOC_PKT_STATS_ROUTE_PCIE_1_CTRL1_FROM_DDR_B_1
        = NOC_ROUTE(P64H_SYSC_APP_NOC_STATS_INITIATOR_PCIE_1_CTRL1_RSP, P64H_SYSC_APP_NOC_STATS_TARGET_DDR_B_1)

    // ............
} app_noc_pkt_stats_route_t;

/**
 * @brief
 *  Initiator points of interest used for performance monitoring through
 *   the DDR NoC
 *
 * @note
 */
typedef enum {
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_TO_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x0, 0), ///< A0 Port Initiator for request packet flow towards DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_TO_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x1, 0), ///< A1 Port Initiator for request packet flow towards DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_TO_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x2, 0), ///< B0 Port Initiator for request packet flow towards DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_TO_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x3, 0), ///< B1 Port Initiator for request packet flow towards DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_FROM_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x0, 2), ///< A0 Port Initiator for response packet flow from DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_FROM_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x1, 2), ///< A1 Port Initiator for response packet flow from DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_FROM_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x2, 2), ///< B0 Port Initiator for response packet flow from DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_FROM_DDR_0
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x3, 2), ///< B1 Port Initiator for response packet flow from DDR 0
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_TO_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x0, 1), ///< A0 Port Initiator for request packet flow towards DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_TO_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x1, 1), ///< A1 Port Initiator for request packet flow towards DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_TO_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x2, 1), ///< B0 Port Initiator for request packet flow towards DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_TO_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 0, 0x3, 1), ///< B1 Port Initiator for request packet flow towards DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_FROM_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x0, 3), ///< A0 Port Initiator for response packet flow from DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_FROM_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x1, 3), ///< A1 Port Initiator for response packet flow from DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_FROM_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x2, 3), ///< B0 Port Initiator for response packet flow from DDR 1
    P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_FROM_DDR_1
        = NOC_INITIATOR_ID_PROBE_INDEX(8, 1, 0x3, 3) ///< B1 Port Initiator for response packet flow from DDR 1
} p64h_sysc_ddr_noc_stats_initator_t;

/**
 * @brief
 *   Packet target points of interest used for measuring the total number of bytes through
 *   the DDR NoC
 *
 * @note
 *   The enums below must follow the order set in the Arteris structure for the given pa_release
 */
typedef enum {
    P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0, ///< DDR 0 Target
    P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1  ///< DDR 1 Target
} p64h_sysc_ddr_noc_stats_target_t;

/**
 * @brief
 *   Packet routes through the DDR NoC
 *
 */
typedef enum {
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_0_TO_DDR_0 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_TO_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_1_TO_DDR_0 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_TO_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_0_TO_DDR_0 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_TO_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_1_TO_DDR_0 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_TO_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_0_FROM_DDR_0
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_FROM_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_1_FROM_DDR_0
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_FROM_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_0_FROM_DDR_0
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_FROM_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_1_FROM_DDR_0
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_FROM_DDR_0, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_0),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_0_TO_DDR_1 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_TO_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_1_TO_DDR_1 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_TO_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_0_TO_DDR_1 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_TO_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_1_TO_DDR_1 = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_TO_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_0_FROM_DDR_1
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_0_FROM_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_A_1_FROM_DDR_1
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_A_1_FROM_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_0_FROM_DDR_1
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_0_FROM_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1),
    P64H_SYSC_DDR_NOC_PKT_STATS_ROUTE_B_1_FROM_DDR_1
        = NOC_ROUTE(P64H_SYSC_DDR_NOC_STATS_INITIATOR_B_1_FROM_DDR_1, P64H_SYSC_DDR_NOC_STATS_TARGET_DDR_1)
} p64h_sysc_ddr_noc_pkt_stats_route_t;

/**
 * @brief
 *   Event types for the counters used for statistic
 *   collection inside NoCs for monitoring
 *   packet flow events
 *
 */
typedef enum {
    P64H_SYSC_NOC_STATS_EVENT_CYCLE = 1, ///< Probe clock cycles
    P64H_SYSC_NOC_STATS_EVENT_IDLE,      ///< Idle cycles (cycles during which no packet data is observed)
    P64H_SYSC_NOC_STATS_EVENT_XFER,      ///< Transfer cycles (cycles during which packet data is transferred)
    P64H_SYSC_NOC_STATS_EVENT_BUSY,      ///< Busy cycles (cycles during which the packet data is made available by the transmitting agent but the
                                         ///< receiving agent is not ready to receive it)
    P64H_SYSC_NOC_STATS_EVENT_WAIT, ///< Wait cycles (cycles during a packet in which the transmitting agent suspends the transfer of packet data)
    P64H_SYSC_NOC_STATS_EVENT_PKT,  ///< Packets
    P64H_SYSC_NOC_STATS_EVENT_LUT,  ///< Packets selected by the LUT
    P64H_SYSC_NOC_STATS_EVENT_BYTE, //< Total number of payload bytes
    P64H_SYSC_NOC_STATS_EVENT_BYTE_PRESS_0, ///< Clock cycles with pressure level > 0
    P64H_SYSC_NOC_STATS_EVENT_BYTE_PRESS_1, ///< Clock cycles with pressure level > 1
    P64H_SYSC_NOC_STATS_EVENT_BYTE_PRESS_2, ///< Clock cycles with pressure level > 2
    P64H_SYSC_NOC_STATS_EVENT_FILT_0,       ///< Packets selected by Filter 0
    P64H_SYSC_NOC_STATS_EVENT_FILT_1,       ///< Packets selected by Filter 1
    P64H_SYSC_NOC_STATS_EVENT_FILT_2,       ///< Packets selected by Filter 2
    P64H_SYSC_NOC_STATS_EVENT_FILT_3,       ///< Packets selected by Filter 3
    P64H_SYSC_NOC_STATS_EVENT_CHAIN,        ///< Carry from counter 2M to counter 2M+1
    P64H_SYSC_NOC_STATS_EVENT_LUT_BYTE_EN,  ///< Enabled bytes in the packet selected by the LUT
    P64H_SYSC_NOC_STATS_EVENT_LUT_BYTE,     ///< Total number of payload bytes in the packet selected by the LUT
    P64H_SYSC_NOC_STATS_EVENT_FILT_BYTE_EN, ///< Enabled bytes in the packet selected by the filters
    P64H_SYSC_NOC_STATS_EVENT_FILT_BYTE,    ///< Total number of payload bytes in the packet selected by the filters
    P64H_SYSC_NOC_STATS_EVENT_EXT_EVENT     ///< Transaction flow count event
} p64h_sysc_noc_stats_event_t;

/**
 * @brief
 *   Action request for the NoC to start/stop statistics collection of data
 *
 */
typedef enum {
    P64H_SYSC_NOC_STATS_ACTION_START, ///< Start collecting statistics data
    P64H_SYSC_NOC_STATS_ACTION_STOP   ///< Stop collecting statistics data
} noc_stats_action_t;

/**
 * @brief
 *   Transaction profiling options for
 *   statistic collection
 */
typedef enum {
    P64H_SYSC_NOC_PM_TRANS_MODE_LATENCY_DELAY,     ///< Delay transaction latency mode
    P64H_SYSC_NOC_PM_TRANS_MODE_LATENCY_HANDSHAKE, ///< Delay transaction handshake mode
    P64H_SYSC_NOC_PM_TRANS_MODE_PENDING_TRANS,     ///< Pending transactions mode
    P64H_SYSC_NOC_PM_TRANS_MODE_INVALID            ///< Invalid Transactions mode
} p64h_sysc_noc_pm_trans_mode_t;

/**
 * @brief
 *   Write/read monitoring options for transaction
 *   profiling
 */
typedef enum {
    P64H_SYSC_NOC_PM_OPCODE_MODE_WR_RD,   ///< Write and read transaction Opcode mode
    P64H_SYSC_NOC_PM_OPCODE_MODE_WR_ONLY, ///< Write only transaction Opcode mode
    P64H_SYSC_NOC_PM_OPCODE_MODE_RD_ONLY, ///<  Read only transaction Opcode mode
    P64H_SYSC_NOC_PM_OPCODE_MODE_INVALID  ///< Invalid transaction Opcode mode
} p64h_sysc_noc_pm_opcode_mode_t;

/**
 * @brief
 *   NoC statistics alarm mode
 */
typedef enum {
    P64H_SYSC_NOC_STAT_ALARM_MODE_OFF,    ///< Alarm feature is disabled
    P64H_SYSC_NOC_STAT_ALARM_MODE_MIN,    ///< when the counter value is less that the StatAlarmMin register, the StatAlarmStatus is set
    P64H_SYSC_NOC_STAT_ALARM_MODE_MAX,    ///< when the counter value is greater that the StatAlarmMax register, the StatAlarmStatus is set
    P64H_SYSC_NOC_STAT_ALARM_MODE_MIN_MAX ///< when the counter value is less that the StatAlarmMin register,
                                          ///< or when counter value is greater that the StatAlarmMax register, the StatAlarmStatus is set
} p64h_sysc_noc_stat_alarm_mode_t;

/**
 * @brief
 *   List of APP NoC observed ports
 */
typedef enum {
    P64H_SYSC_APP_NOC_OBSERVED_PORT_CPU_CLST_0_MEM = NOC_TRANS_PROFILE(0, 0, 0, 0, 16, 32),  ///< CPU Cluster 0 Memory Port port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_CPU_CLST_0_SYS = NOC_TRANS_PROFILE(0, 0, 1, 1, 16, 32),  ///< CPU Cluster 0 System Port port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_CPU_CLST_1_MEM = NOC_TRANS_PROFILE(0, 1, 2, 0, 16, 32),  ///< CPU Cluster 1 Memory Port port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_CPU_CLST_1_SYS = NOC_TRANS_PROFILE(0, 1, 3, 1, 16, 32),  ///< CPU Cluster 1 System Port port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_ENET_EP_0      = NOC_TRANS_PROFILE(0, 3, 5, 0, 4, 24),   ///< ENET EP 0 port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_ENET_EP_1      = NOC_TRANS_PROFILE(0, 3, 6, 1, 4, 24),   ///< ENET EP 1 port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_ENET_EP_2      = NOC_TRANS_PROFILE(0, 3, 7, 2, 4, 24),   ///< ENET EP 2 port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_ENET_EP_3      = NOC_TRANS_PROFILE(0, 3, 8, 3, 4, 24),   ///< ENET EP 3 port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_APPDMA_0       = NOC_TRANS_PROFILE(0, 7, 21, 0, 16, 32), ///< APPDMA 0 port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_APPDMA_1       = NOC_TRANS_PROFILE(0, 7, 22, 1, 16, 32), ///< APPDMA 1 port
    P64H_SYSC_APP_NOC_OBSERVED_PORT_SYS_NOC        = NOC_TRANS_PROFILE(0, 11, 32, 0, 4, 6)   ///< SYSC NoC port
} p64h_sysc_app_noc_observed_port_t;

/**
 * @brief
 *   List of DDR NoC observed ports
 */
typedef enum {
    P64H_SYSC_DDR_NOC_OBSERVED_PORT_A_0 = NOC_TRANS_PROFILE(0, 0, 0, 0, 4, 32), ///< A0 port
    P64H_SYSC_DDR_NOC_OBSERVED_PORT_A_1 = NOC_TRANS_PROFILE(0, 0, 1, 1, 4, 32), ///< A1 port
    P64H_SYSC_DDR_NOC_OBSERVED_PORT_B_0 = NOC_TRANS_PROFILE(0, 0, 2, 2, 4, 32), ///< B0 port
    P64H_SYSC_DDR_NOC_OBSERVED_PORT_B_1 = NOC_TRANS_PROFILE(0, 0, 3, 3, 4, 32)  ///< B1 port
} p64h_sysc_ddr_noc_observed_port_t;

/**
 * @brief
 *   NoC configuration for statistics
 *   alarm
 *
 * @note
 *   Only applicable when dumping the data
 *   to the observer
 */
typedef struct {
    p64h_sysc_noc_stat_alarm_mode_t alarm_mode; ///< Statistics alarm mode
    uint32_t alarm_min_low; ///< [31:0] bits of the lower counter value that would trigger the alarm (applicable for P64H_SYSC_NOC_STAT_ALARM_MODE_MIN
                            ///< and P64H_SYSC_NOC_STAT_ALARM_MODE_MIN_MAX only)
    uint32_t alarm_min_high; ///< [63:32] bits of the lower counter value that would trigger the alarm (applicable for
                             ///< P64H_SYSC_NOC_STAT_ALARM_MODE_MIN and P64H_SYSC_NOC_STAT_ALARM_MODE_MIN_MAX only)
    uint32_t alarm_max_low; ///< [31:0] bits of the upper counter value that would trigger the alarm (applicable for P64H_SYSC_NOC_STAT_ALARM_MODE_MAX
                            ///< and P64H_SYSC_NOC_STAT_ALARM_MODE_MIN_MAX only)
    uint32_t alarm_max_high; ///< [63:32] bits of the upper counter value that would trigger the alarm (applicable for
                             ///< P64H_SYSC_NOC_STAT_ALARM_MODE_MAX and P64H_SYSC_NOC_STAT_ALARM_MODE_MIN_MAX only)
} p64h_sysc_noc_stat_alarm_cfg_t;

/**
 * @brief
 *   Configuration of the NoC for capturing statistics data for performance monitoring
 */
typedef struct {
    p64h_sysc_noc_type_t noc_type; ///< Noc type
    bool     filters_configured;   ///< true - filters used in the statistics collection; false - filters not used in the statistics collection
    uint32_t filter_id;            ///< Filter ID (not used if filters_configured = false)
    uint32_t filtered_route;       ///< Filtered route (not used if filters_configured = false)
    uint32_t initiator_id;         ///< Initiator ID
    uint32_t counter_id;           ///< Counter ID
    uint32_t stat_period; ///< set a period, within a range of 2 cycles to 2 gigacycles, during which statistics are collected before being dumped
                          ///< automatically. the period is calculated with the formula: N_Cycle = 2**stat_period where stat_period is in the range of
                          ///< [1, 31] when it is set to its default value of 0, automatic dump mode is disabled, and manual dump mode is activated.
    p64h_sysc_noc_stats_event_t    noc_stats_event;    ///< Event to be monitored for statistics collection
    p64h_sysc_noc_stat_alarm_cfg_t noc_stat_alarm_cfg; ///< NoC stat alarm configuration
} p64h_sysc_noc_stats_cfg_t;

/**
 * @brief
 *   Configuration of the Noc for start/stop execution for collection the statistics data
 *
 */
typedef struct {
    p64h_sysc_noc_type_t noc_type;         ///< NoC type for statistics collection
    uint32_t             initiator_id;     ///< Initiator ID
    noc_stats_action_t   noc_stats_action; ///< Action request for the NoC
} p64h_sysc_noc_stats_action_t;

/**
 * @brief
 *   Configuration of the NoC for transaction profiling feature for performance monitoring
 */
typedef struct {
    p64h_sysc_noc_type_t noc_type;         ///< Noc type
    uint32_t             observed_port_id; ///< Observed port ID
    uint32_t             counter_id;       ///< Counter ID
    uint32_t stat_period; ///< set a period, within a range of 2 cycles to 2 gigacycles, during which statistics are collected before being dumped
                          ///< automatically. the period is calculated with the formula: N_Cycle = 2**stat_period where stat_period is in the range of
                          ///< [1, 31] when it is set to its default value of 0, automatic dump mode is disabled, and manual dump mode is activated.
    uint32_t                       bin_index;          ///< histogram bin index
    uint32_t                       tenure_lines;       ///< number of tenure lines
    uint32_t                       threshold;          ///< upper boundary threshold for the bin
    p64h_sysc_noc_stat_alarm_cfg_t noc_stat_alarm_cfg; ///< NoC stat alarm configuration
} p64h_sysc_noc_trans_prof_cfg_t;

/**
 * @brief
 *   Configuration of the Noc for start/stop execution for collection of the statistics data
 *   for transaction profiling feature
 *
 */
typedef struct {
    p64h_sysc_noc_type_t           noc_type;         ///< NoC type for statistics collection
    uint32_t                       observed_port_id; ///< Observed port ID
    noc_stats_action_t             noc_stats_action; ///< Action request for the NoC
    p64h_sysc_noc_pm_trans_mode_t  trans_mode;       ///< transaction profiling modes
    p64h_sysc_noc_pm_opcode_mode_t opcode_mode;      ///< opcode modes
} p64h_sysc_noc_trans_prof_action_t;

/**
 * @brief
 *   Configuration for the Noc port of interest
 *
 */
typedef struct {
    p64h_sysc_noc_type_t      noc_type;      ///< NoC type for statistics collection
    p64h_sysc_noc_stat_type_t noc_stat_type; ///< NoC statistics type
    uint32_t port_id; ///< initiator id (P64H_SYSC_TRACE_NOC_STAT_TYPE_PACKETS) or observed port id (P64H_SYSC_TRACE_NOC_STAT_TYPE_TRANSACTIONS)
} p64h_sysc_noc_stats_port_cfg_t;

/**
 * @brief
 *   Type of NoC statistics configuration
 *
 */
typedef enum {
    P64H_SYSC_NOC_OBS_CFG,         ///< cfg and api call are for noc obs
    P64H_SYSC_NOC_STATS_CFG,       ///< cfg and api call are for noc stats
    P64H_SYSC_NOC_STATS_ALARM_CFG, ///< cfg and api calls are for noc alarm
    P64H_SYSC_NOC_TRANS_PROF_CFG,  ///< cfg and api calls are for transaction profiling
} p64h_sysc_noc_cfg_type_t;

/**
 * @brief
 *  union to combime NOC tracing cfg
 */
typedef union {
    p64h_sysc_noc_obs_cfg_t           noc_obs_cfg;               ///< NoC observer configuration
    p64h_sysc_noc_stats_cfg_t         noc_stats_cfg;             ///< NoC statistics configuration
    p64h_sysc_noc_stats_action_t      noc_stats_action_cfg;      ///< NoC statistics action request
    p64h_sysc_noc_trans_prof_cfg_t    noc_trans_prof_cfg;        ///< NoC transaction profiling configuration
    p64h_sysc_noc_trans_prof_action_t noc_trans_prof_action_cfg; ///< NoC transaction profiling feature action request
    p64h_sysc_noc_stats_port_cfg_t    noc_stats_port_cfg;        ///< NoC statistics port configuration
} p64h_sysc_noc_trace_cfg_t;

/// trace event identifier
typedef enum {
    P64H_SYSC_TRACE_EVD_ID_AVAILABLE = 1 ///< trace available
} p64h_sysc_trace_evt_id_t;

/// trace event
typedef struct {
    p64h_sysc_trace_evt_id_t eid; ///< event identifier
} p64h_sysc_trace_evt_t;

/// enumerate trace sink
typedef enum {
    P64H_SYSC_TRACE_SINK_ID_LOCAL_SRAM = 0, ///< SRAM trace sink
    P64H_SYSC_TRACE_SINK_ID_MEM,            ///< Memory trace sink
    P64H_SYSC_TRACE_SINK_ID_HSIO            ///< High-Speed IO sink
} p64h_sysc_trace_sink_id_t;

/// enumerate system trace
typedef enum {
    P64H_SYSC_SYS_TRACE_APP_NOC = 0, ///< App NOC trace
    P64H_SYSC_SYS_TRACE_SYS_NOC,     ///< Syc NOC trace
    P64H_SYSC_SYS_TRACE_DDR_NOC,     ///< DDR NOC trace
} p64h_sysc_sys_trace_id_t;

/// enumerate software trace
typedef enum {
    P64H_SYSC_SW_TRACE_SVC_EVT = 0 ///< software service event trace
} p64h_sysc_sw_trace_id_t;

/// enumerate RISCV trace-encoder trace
typedef enum {
    P64H_SYSC_TE_TRACE_INST = 0 ///< instruction tracing
} p64h_sysc_te_trace_id_t;

/// trace sink attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for trace sink attributes
} p64h_sysc_trace_sink_attr_t;

/// trace sink configuration
typedef struct {
    uint32_t placeholder; ///< placeholder for trace sink configuration
} p64h_sysc_trace_sink_cfg_t;

/// system trace attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for system trace attributes
} p64h_sysc_sys_trace_attr_t;

/// system trace configuration
typedef struct {
    p64h_sysc_noc_cfg_type_t  noc_cfg_type;
    p64h_sysc_noc_trace_cfg_t noc_trace_cfg;
} p64h_sysc_sys_trace_cfg_t;

/// software trace attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for software trace attributes
} p64h_sysc_sw_trace_attr_t;

/// software trace configuration
typedef struct {
    uint32_t placeholder; ///< placeholder for software trace configuration
} p64h_sysc_sw_trace_cfg_t;

/// TE trace attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for TE trace attributes
} p64h_sysc_te_trace_attr_t;

/// TE trace configuration
typedef struct {
    uint32_t placeholder; ///< placeholder for TE trace configuration
} p64h_sysc_te_trace_cfg_t;

/// function pointer type for TRACE event notification
typedef void (*p64h_sysc_trace_evt_fct_t)(const p64h_sysc_trace_evt_t* trace_evt_ptr);

#endif // P64H_SYSC_TRACE_TYPES_H
