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

#define ONE_HOT(x)                  1u << x ///< one hot encoding for bit mask
#define NOC_NUM                     3u      ///< Define number of NoC's for statistics collection
#define NUM_APPC_TRACE_ENCODERS     4u      ///< Define the number of trace encoder in appc
#define SYS_TRACE_NUM_CROSS_TRIGGER 86u     ///< Number of cross trigger matrix instances

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
 * Trace encoder ID
 */
typedef enum {
    P64H_SYSC_TRACE_TE_APPC_HART0 = 0u,
    P64H_SYSC_TRACE_TE_APPC_HART1 = 1u,
    P64H_SYSC_TRACE_TE_APPC_HART2 = 2u,
    P64H_SYSC_TRACE_TE_APPC_HART3 = 3u,
    P64H_SYSC_TRACE_TE_APPC_HART4 = 4u,
    P64H_SYSC_TRACE_TE_APPC_HART5 = 5u,
    P64H_SYSC_TRACE_TE_APPC_HART6 = 6u,
    P64H_SYSC_TRACE_TE_APPC_HART7 = 7u,
    P64H_SYSC_TRACE_TE_SYSC       = 8u,
    P64H_SYSC_TRACE_TE_LAST       = 9u
} p64h_sysc_trace_te_id_t;

/// TE trace attributes
typedef struct {
    uint32_t TE_Active;          ///< Master enable for trace system
    uint32_t TE_Enable;          ///< Allows teTracing to turn all tracing on and off
    uint32_t TE_Tracing;         ///< 1=Trace is being generated
    uint32_t TE_Empty;           ///< Reads as 1 when all generated trace has been emitted
    uint32_t TE_StallOrOverflow; ///< 1=hardware generated an overflow message or requested a core stall (trace may be lost)
    uint32_t TE_SinkError;       ///< 1=hardware detected a trace sink transaction error
} p64h_sysc_trace_te_attr_t;

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

/// Enum for selecting the memory buffer mode of operation
typedef enum {
    P64H_SYSC_TRACE_MEM_STOP_ON_WRAP_MODE = 0, ///< When Trace RAM is full, the incoming trace stream is stalled.
    P64H_SYSC_TRACE_MEM_CIRCULAR_BUFFER_MODE
        = 1, ///< When the trace memory is full, incoming trace data continues to be overwritten into the trace memory.
} p64h_sysc_trace_mem_mode_t;

/// enumerate trace sink instances
typedef enum {
    P64H_SYSC_TRACE_SINK_ID_APPC_HART_0_3 = 0, ///< sink for APPC HART0..3
    P64H_SYSC_TRACE_SINK_ID_APPC_HART_4_7,     ///< sink for APPC HART4..7
    P64H_SYSC_TRACE_SINK_ID_SYSC,              ///< sink for SYSC hart
    P64H_SYSC_TRACE_SINK_ID_LAST
} p64h_sysc_trace_sink_id_t;

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

/// trace system memory configurations
typedef struct {
    p64h_sysc_trace_mem_mode_t trace_mem_mode;      ///< trace buffer mode of operation (FIFO or CB); see trace_mem_mode_t
    uint32_t                   trace_mem_addr_high; ///< the high 32-bits of the mem buffer addr
    uint32_t                   trace_mem_addr_low;  ///< the low 32-bits of the mem buffer addr
    uint32_t                   trace_mem_size;      ///< the size of the mem buffer
} p64h_sysc_trace_mem_cfg_t;

/**
 * trace data destination for sources of trace
 */
typedef enum {
    P64H_SYSC_TRACE_SRC_SINK_SRAM,          ///< Send trace data to local SRAM of source
    P64H_SYSC_TRACE_SRC_SINK_SYSTEM_MEMORY, ///< Send trace data to system memory directly from source sink
    P64H_SYSC_TRACE_SRC_SINK_ATB,           ///< Send trace data to ATB funnel and Trace SOK
} p64h_sysc_trace_source_sink_t;

/**
 * sink configuration for trace encoder
 */
typedef struct {
    p64h_sysc_trace_source_sink_t   sink;          ///< sink type
    p64h_sysc_trace_atb_sink_cfg_t  atb_sink_cfg;  ///< atb sink cfg
    p64h_sysc_trace_sram_sink_cfg_t sram_sink_cfg; ///< sram sink cfg
    p64h_sysc_trace_mem_cfg_t       sys_mem_cfg;   ///< sys mem sink cfg
} p64h_sysc_trace_sink_cfg_t;

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
 * Enum for TE cfg command
 */
typedef enum {
    P64H_SYSC_TRACE_TE_SET_SINK = ONE_HOT(0), ///< configure the sink for this source
    P64H_SYSC_TRACE_TE_SET_ITC  = ONE_HOT(1), ///< configure the ITC trace system for hart 0
    P64H_SYSC_TRACE_TE_SET_HTM  = ONE_HOT(2), ///< configure the BTM trace system for hart 0
} p64h_sysc_trace_te_cfg_cmd_t;

/**
 * Source level configuration for Trace Encoder
 */
typedef struct {
    p64h_sysc_trace_te_cfg_cmd_t cmd_msk; ///< command mask for which cfg to set
    p64h_sysc_trace_te_btm_cfg_t btm_cfg; ///< configuration for instruction trace
    p64h_sysc_trace_te_itc_cfg_t itc_cfg; ///< configuration for instrumentation trace
} p64h_sysc_trace_te_cfg_t;

/**
 * Struct to configure APPC Trace sources
 */
typedef struct {
    p64h_sysc_trace_te_cfg_t   core_te_cfgs[NUM_APPC_TRACE_ENCODERS]; ///< Core 0-3 trace encoder per cluster
    p64h_sysc_trace_sink_cfg_t sink_cfg;                              ///< sink cfg per cluster
} p64h_sysc_trace_appc_cfg_t;

/**
 * Struct to configure SYSC Trace sources
 */
typedef struct {
    p64h_sysc_trace_te_cfg_cmd_t cmd_msk;     ///< command mask for which cfg to set
    p64h_sysc_trace_te_cfg_t     core_te_cfg; ///< Core 0 trace encoder
    p64h_sysc_trace_sink_cfg_t   sink_cfg;    ///< sink cfg for sysc
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

/* ---------------------------------------------------------------*/
// ### Structs and Enums for NOC tracing configuration  ###
/* ---------------------------------------------------------------*/

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
    P64H_SYSC_TRACE_EVD_ID_AVAILABLE = 0, ///< trace available
    P64H_SYSC_TRACE_EVD_ID_LAST
} p64h_sysc_trace_evt_id_t;

/// trace event
typedef struct {
    p64h_sysc_trace_evt_id_t eid; ///< event identifier
} p64h_sysc_trace_evt_t;

/// enumerate system trace
typedef enum {
    P64H_SYSC_SYS_TRACE_APP_NOC = 0, ///< App NOC trace
    P64H_SYSC_SYS_TRACE_SYS_NOC,     ///< Syc NOC trace
    P64H_SYSC_SYS_TRACE_DDR_NOC,     ///< DDR NOC trace
    P64H_SYSC_SYS_TRACE_LAST
} p64h_sysc_sys_trace_id_t;

/// enumerate software trace
typedef enum {
    P64H_SYSC_SW_TRACE_SVC_EVT = 0, ///< runtime software service-event trace (reserved, not yet implemented)
    P64H_SYSC_SW_TRACE_BOOT,        ///< DTIM software boot-stage sw trace
    P64H_SYSC_SW_TRACE_LAST
} p64h_sysc_sw_trace_id_t;

/// trace sink attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for trace sink attributes
} p64h_sysc_trace_sink_attr_t;

/// system trace attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for system trace attributes
} p64h_sysc_sys_trace_attr_t;

/// system trace configuration
typedef struct {
    p64h_sysc_noc_cfg_type_t  noc_cfg_type;
    p64h_sysc_noc_trace_cfg_t noc_trace_cfg;
} p64h_sysc_sys_trace_cfg_t;

/// software trace attributes (read-only live state of a software-trace object).
/// For P64H_SYSC_SW_TRACE_BOOT these mirror the DTIM attributes, so
/// the host knows the GET_TRACE_DATA size and the mtime timebase.
typedef struct {
    uint32_t magic;      ///< ring magic (TRACE_SW_MAGIC once initialized, else 0)
    uint32_t wr_index;   ///< next write slot, in [0, count)
    uint32_t wrap_count; ///< number of times the ring has wrapped
    uint32_t count;      ///< number of slots (== TRACE_SW_NUM_ENTRIES)
    uint32_t entry_size; ///< bytes per tracepoint (sizeof(p64h_sysc_sw_tracepoint_t))
    uint32_t mtime_hz;   ///< timestamp counter frequency in Hz (TRACE_SW_MTIME_HZ)
    uint32_t buf_size;   ///< total ring size in bytes (sizeof(p64h_sysc_sw_trace_buffer_t))
} p64h_sysc_sw_trace_attr_t;

/// software-trace buffer fill mode (what happens when the ring fills).
typedef enum {
    P64H_SYSC_SW_TRACE_MODE_CIRCULAR_BUFFER = 0, ///< ring buffer: overwrite oldest entries on wrap (default)
    P64H_SYSC_SW_TRACE_MODE_STOP_ON_WRAP,        ///< stop recording once the ring is full (keep the first N entries)
} p64h_sysc_sw_trace_mode_t;

/// software trace configuration (control for a software-trace object).
typedef struct {
    uint32_t enable; ///< 1 = recording enabled, 0 = paused (gates new tracepoints)
    uint32_t clear;  ///< set-only: write 1 to reset/empty the ring (reads back 0)
    uint32_t mode;   ///< p64h_sysc_sw_trace_mode_t: WRAP (ring, default) or STOP_ON_WRAP
} p64h_sysc_sw_trace_cfg_t;

/// function pointer type for TRACE event notification
typedef void (*p64h_sysc_trace_evt_fct_t)(const p64h_sysc_trace_evt_t* trace_evt_ptr);

/* ---------------------------------------------------------------*/
//  ### Stuct and Enums for Device Level Trace configuration such as Trace Sok Funnel Destination ###
/* ---------------------------------------------------------------*/

/**
 * Enum for defining trace data source
 */

typedef enum {
    P64H_SYSC_TRACE_SRC_SYSC      = ONE_HOT(0), ///< Trace data is coming from System Controller ATB funnel
    P64H_SYSC_TRACE_SRC_APPC_0    = ONE_HOT(1), ///< Trace data is coming from app cluster 0 ATB funnel
    P64H_SYSC_TRACE_SRC_APPC_1    = ONE_HOT(2), ///< Trace data is coming from app cluster 1 ATB funnel
    P64H_SYSC_TRACE_SRC_SYS_NOC   = ONE_HOT(3), ///< Trace data is coming from SYS_NOC
    P64H_SYSC_TRACE_SRC_APP_NOC   = ONE_HOT(4), ///< Trace data is coming from APP_NOC
    P64H_SYSC_TRACE_SRC_DDR_NOC   = ONE_HOT(5), ///< Trace data is coming from DDR_NOC
    P64H_SYSC_TRACE_SRC_ALL_NOCS  = 0b111000,   ///< Trace data is coming from all NOC
    P64H_SYSC_TRACE_SRC_APPC      = 0b000110,   ///< Trace data is coming from both appc and sysc
    P64H_SYSC_TRACE_SRC_APPC_SYSC = 0b000111,   ///< Trace data is coming from both appc and sysc
    P64H_SYSC_TRACE_SRC_ALL       = 0b111111    ///< Trace data is coming from all available sources

} p64h_sysc_trace_src_t;

/**
 * Enum to define cross trigger matrix source 0
 */
typedef enum {
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_0                 = ONE_HOT(0),  ///< Cluster 0 Core 0
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_1                 = ONE_HOT(1),  ///< Cluster 0 Core 1
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_2                 = ONE_HOT(2),  ///< Cluster 0 Core 2
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_3                 = ONE_HOT(3),  ///< Cluster 0 Core 3
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_0                 = ONE_HOT(4),  ///< Cluster 1 Core 0
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_1                 = ONE_HOT(5),  ///< Cluster 1 Core 1
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_2                 = ONE_HOT(6),  ///< Cluster 1 Core 2
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_3                 = ONE_HOT(7),  ///< Cluster 1 Core 3
    P64H_SYSC_TRACE_XTRG_S7_SYS_CTRL_TRIG_0               = ONE_HOT(8),  ///< S7 Sys Ctrl
    P64H_SYSC_TRACE_XTRG_S7_SYS_CTRL_TRIG_1               = ONE_HOT(9),  ///< S7 Sys Ctrl
    P64H_SYSC_TRACE_XTRG_DDR_NOC_LATENCY_TRIG_0           = ONE_HOT(10), ///< DDR NOC Latency
    P64H_SYSC_TRACE_XTRG_DDR_NOC_LATENCY_TRIG_1           = ONE_HOT(11), ///< DDR NOC Latency
    P64H_SYSC_TRACE_XTRG_DDR_NOC_REQUEST_PACKET_0_TRIG_0  = ONE_HOT(12), ///< DDR NOC request Packet 0
    P64H_SYSC_TRACE_XTRG_DDR_NOC_REQUEST_PACKET_0_TRIG_1  = ONE_HOT(13), ///< DDR NOC request Packet 0
    P64H_SYSC_TRACE_XTRG_DDR_NOC_RESPONSE_PACKET_0_TRIG_0 = ONE_HOT(14), ///< DDR NOC response Packet 0
    P64H_SYSC_TRACE_XTRG_DDR_NOC_RESPONSE_PACKET_0_TRIG_1 = ONE_HOT(15), ///< DDR NOC response Packet 0
    P64H_SYSC_TRACE_XTRG_DDR_NOC_REQUEST_PACKET_1_TRIG_0  = ONE_HOT(16), ///< DDR NOC request Packet 1
    P64H_SYSC_TRACE_XTRG_DDR_NOC_REQUEST_PACKET_1_TRIG_1  = ONE_HOT(17), ///< DDR NOC request Packet 1
    P64H_SYSC_TRACE_XTRG_DDR_NOC_RESPONSE_PACKET_1_TRIG_0 = ONE_HOT(18), ///< DDR NOC response Packet 1
    P64H_SYSC_TRACE_XTRG_DDR_NOC_RESPONSE_PACKET_1_TRIG_1 = ONE_HOT(19), ///< DDR NOC response Packet 1
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_1_TRIG_0           = ONE_HOT(20), ///< SYS NOC Probe 1
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_1_TRIG_1           = ONE_HOT(21), ///< SYS NOC Probe 1
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_2_TRIG_0           = ONE_HOT(22), ///< SYS NOC Probe 2
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_2_TRIG_1           = ONE_HOT(23), ///< SYS NOC Probe 2
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_3_TRIG_0           = ONE_HOT(24), ///< SYS NOC Probe 3
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_3_TRIG_1           = ONE_HOT(25), ///< SYS NOC Probe 3
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_4_TRIG_0           = ONE_HOT(26), ///< SYS NOC Probe 4
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_4_TRIG_1           = ONE_HOT(27), ///< SYS NOC Probe 4
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_5_TRIG_0           = ONE_HOT(28), ///< SYS NOC Probe 5
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_5_TRIG_1           = ONE_HOT(29), ///< SYS NOC Probe 5
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_0_TRIG_0         = ONE_HOT(30), ///< APP NOC Pkt CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_0_TRIG_1         = ONE_HOT(31), ///< APP NOC Pkt CPU 0
} p64h_sysc_trace_cross_trigger_out_select_0_t;

/**
 * Enum to define cross trigger matrix source 1
 *
 *
 */
typedef enum {
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_1_TRIG_0         = ONE_HOT(0),  ///< APP NOC Pkt CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_1_TRIG_1         = ONE_HOT(1),  ///< APP NOC Pkt CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_DDR_ENCRYPT_TRIG_0   = ONE_HOT(2),  ///< APP NOC Pkt DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_DDR_ENCRYPT_TRIG_1   = ONE_HOT(3),  ///< APP NOC Pkt DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_EP_TRIG_0       = ONE_HOT(4),  ///< APP NOC Pkt ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_EP_TRIG_1       = ONE_HOT(5),  ///< APP NOC Pkt ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_SWR_TRIG_0      = ONE_HOT(6),  ///< APP NOC Pkt ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_SWR_TRIG_1      = ONE_HOT(7),  ///< APP NOC Pkt ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_IOMMU_TRIG_0         = ONE_HOT(8),  ///< APP NOC Pkt IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_IOMMU_TRIG_1         = ONE_HOT(9),  ///< APP NOC Pkt IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M2_TRIG_0            = ONE_HOT(10), ///< APP NOC Pkt M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M2_TRIG_1            = ONE_HOT(11), ///< APP NOC Pkt M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M3_TRIG_0            = ONE_HOT(12), ///< APP NOC Pkt M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M3_TRIG_1            = ONE_HOT(13), ///< APP NOC Pkt M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_NVM_TRIG_0           = ONE_HOT(14), ///< APP NOC Pkt NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_NVM_TRIG_1           = ONE_HOT(15), ///< APP NOC Pkt NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_0_TRIG_0        = ONE_HOT(16), ///< APP NOC Pkt PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_0_TRIG_1        = ONE_HOT(17), ///< APP NOC Pkt PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_1_TRIG_0        = ONE_HOT(18), ///< APP NOC Pkt PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_1_TRIG_1        = ONE_HOT(19), ///< APP NOC Pkt PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_SYS_NOC_TRIG_0       = ONE_HOT(20), ///< APP NOC Pkt SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_SYS_NOC_TRIG_1       = ONE_HOT(21), ///< APP NOC Pkt SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_USER_CRYPTO_TRIG_0   = ONE_HOT(22), ///< APP NOC Pkt USER CRYPTO
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_USER_CRYPTO_TRIG_1   = ONE_HOT(23), ///< APP NOC Pkt USER CRYPTO
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_0_TRIG_0       = ONE_HOT(24), ///< APP NOC Trans CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_0_TRIG_1       = ONE_HOT(25), ///< APP NOC Trans CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_1_TRIG_0       = ONE_HOT(26), ///< APP NOC Trans CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_1_TRIG_1       = ONE_HOT(27), ///< APP NOC Trans CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_DDR_ENCRYPT_TRIG_0 = ONE_HOT(28), ///< APP NOC Trans DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_DDR_ENCRYPT_TRIG_1 = ONE_HOT(29), ///< APP NOC Trans DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_EP_TRIG_0     = ONE_HOT(30), ///< APP NOC Trans ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_EP_TRIG_1     = ONE_HOT(31), ///< APP NOC Trans ENET EP
} p64h_sysc_trace_cross_trigger_out_select_1_t;

/**
 * Enum to define cross trigger matrix source 2
 */
typedef enum {
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_SWR_TRIG_0    = ONE_HOT(0),  ///< APP NOC Trans ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_SWR_TRIG_1    = ONE_HOT(1),  ///< APP NOC Trans ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_IOMMU_TRIG_0       = ONE_HOT(2),  ///< APP NOC Trans IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_IOMMU_TRIG_1       = ONE_HOT(3),  ///< APP NOC Trans IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M2_TRIG_0          = ONE_HOT(4),  ///< APP NOC Trans M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M2_TRIG_1          = ONE_HOT(5),  ///< APP NOC Trans M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M3_TRIG_0          = ONE_HOT(6),  ///< APP NOC Trans M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M3_TRIG_1          = ONE_HOT(7),  ///< APP NOC Trans M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_NVM_TRIG_0         = ONE_HOT(8),  ///< APP NOC Trans NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_NVM_TRIG_1         = ONE_HOT(9),  ///< APP NOC Trans NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_0_TRIG_0      = ONE_HOT(10), ///< APP NOC Trans PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_0_TRIG_1      = ONE_HOT(11), ///< APP NOC Trans PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_1_TRIG_0      = ONE_HOT(12), ///< APP NOC Trans PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_1_TRIG_1      = ONE_HOT(13), ///< APP NOC Trans PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_SYS_NOC_TRIG_0     = ONE_HOT(14), ///< APP NOC Trans SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_SYS_NOC_TRIG_1     = ONE_HOT(15), ///< APP NOC Trans SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_USER_CRYPTO_TRIG_0 = ONE_HOT(16), ///< APP NOC Trans USER CRYPTO
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_USER_CRYPTO_TRIG_1 = ONE_HOT(17), ///< APP NOC Trans USER CRYPTO
    P64H_SYSC_TRACE_XTRG_SYNCREQ_TRIG                     = ONE_HOT(18), ///< syncreq trigger
    P64H_SYSC_TRACE_XTRG_APP_NOC_SYNCREQ_TRIG             = ONE_HOT(19), ///< app_noc syncreq trigger
    P64H_SYSC_TRACE_XTRG_DDR_NOC_SYNCREQ_TRIG             = ONE_HOT(20), ///< ddr noc syncreq trigger
    P64H_SYSC_TRACE_XTRG_SYS_NOC_SYNCREQ_TRIG             = ONE_HOT(21), ///< sys noc syncreq trigger
} p64h_sysc_trace_cross_trigger_out_select_2_t;

/**
 * Enum for selecting the trace data path at system level
 */
typedef enum {
    P64H_SYSC_TRACE_DEST_NONE       = 0, ///< Do not configure the trace destination
    P64H_SYSC_TRACE_DEST_SERDES     = 1, ///< Trace data is directed to external trace debugger via SERDES
    P64H_SYSC_TRACE_DEST_SYSTEM_MEM = 2  ///< Trace data is directed to the AXI4 initiator Interface
} p64h_sysc_trace_dest_t;

/**
 *  bit mask for serdes configuration command
 */
typedef enum {
    P64H_SYSC_TRACE_SERDES_CFG_PWR_UP     = ONE_HOT(0),  ///< power cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_EN         = ONE_HOT(1),  ///< enable cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_TEST_MODE  = ONE_HOT(2),  ///< test mode cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_LAN_SEL    = ONE_HOT(3),  ///< lane sel cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_FRAME_SIZE = ONE_HOT(4),  ///< frame size cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_CRC_EN     = ONE_HOT(5),  ///< crc enable cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_TWP_CNT    = ONE_HOT(6),  ///< twp cnt cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_SYNC_COUNT = ONE_HOT(7),  ///< sync count cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_ALIGN_LEN  = ONE_HOT(8),  ///< align len cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_BOND_LEN   = ONE_HOT(9),  ///< bond len cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_VERIFY_LEN = ONE_HOT(10), ///< verify len cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_ALIGN_MUL  = ONE_HOT(11), ///< align cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_BOND_MUL   = ONE_HOT(12), ///< bond cfg set mask
    P64H_SYSC_TRACE_SERDES_CFG_VERIFY_MUL = ONE_HOT(13), ///< verify cfg set mask
} p64h_sysc_trace_serdes_cfg_cmd_t;

/**
 * trace serdes configurations (example, not complete)
 */
typedef struct {
    uint32_t cmd_mask;  ///< bit mask for cfg cmd; see p64h_sysc_trace_serdes_cfg_cmd_t
    uint32_t pwr_up;    ///< Power up the HTI hardware
    uint32_t enable;    ///< Power up and enable the HTI hardware
    uint32_t test_mode; ///< Put the HTI hardware in test mode, test_mode and enable are exclusive
    uint32_t lane_sel;  ///< Controls the number of active lanes used for transmitting trace data. 0: Lane 1 active. 1: Lanes 1 to 2 active.

    uint32_t frame_size; ///< Aurora Frame Size. TWP Sync packets must be disabled. 0: 2 TWP Frames 1: 4 TWP Frames 2: 8 TWP Frames 3: 16 TWP Frames
    uint32_t crc_en;     ///< Enable to include CRC in Aurora Frames
    uint8_t  twp_cnt;    ///< Number of Aurora frames sent before inserting 4 bytes of TWP sync

    ///< Control register for adjusting the period between clock compensation sequences.
    uint32_t sync_count; ///< The number of symbols transmitted between clock compensation sequences generated by the link layer.

    ///< Following cfg specifies the clock cycles used at the various stages of link initialization.
    uint32_t align_len; ///< The number of bytes of the Aurora alignment pattern that are sent by the TS. Number of bytes = align_mul*(align_len + 1).
    uint32_t bond_len;  ///< The number of bytes of the Aurora bonding pattern that are sent by the TS. Number of bytes = bond_mul*(bond_len + 1).
    uint32_t verify_len; ///< The number of bytes of the Aurora verification pattern that are sent by the TS. Number of bytes = verify_mul*(verify_len
                         ///< + 1).
    uint32_t align_mul;  ///< Defines the multiplier used in conjunction with align_len when performing link initialization
    uint32_t bond_mul;   ///< Defines the multiplier used in conjunction with bond_len when performing link initialization
    uint32_t verify_mul; ///< Defines the multiplier used in conjunction with verify_len when performing link initialization

} p64h_sysc_trace_serdes_cfg_t;

/**
 * trace etr axi configurations cmd mask
 */
typedef enum {
    P64H_SYSC_TRACE_ETR_AXI_CFG_OUTSTANDING_LIMIT = ONE_HOT(0), ///< outstanding limit set mask
    P64H_SYSC_TRACE_ETR_AXI_CFG_STOP_ON_ERROR     = ONE_HOT(1), ///< stop_on_error cfg set mask
} p64h_sysc_trace_etr_axi_cfg_cmd_t;

/**
 * trace etr axi configurations
 */
typedef struct {
    uint32_t cmd_mask;          ///< bit mask for cfg cmd; see p64h_sysc_trace_etr_axi_cfg_cmd_t
    uint32_t outstanding_limit; ///< outstanding_limit
    uint32_t stop_on_error;     ///< stop_on_error
} p64h_sysc_trace_etr_axi_cfg_t;

/**
 * trace destination configurations
 */
typedef struct {
    p64h_sysc_trace_dest_t        trace_dest_select; ///< select trace data path
    p64h_sysc_trace_mem_cfg_t     mem_cfg;           ///< if trace_dest_select == SYSTEM_MEM, set up trace buffer
    p64h_sysc_trace_etr_axi_cfg_t etr_axi_cfg;       ///< if trace_dest_select == SYSTEM_MEM, optional axi cfg
    p64h_sysc_trace_serdes_cfg_t  serdes_cfg;        ///< if trace_dest_select == SERDES, set up serdes
} p64h_sysc_trace_dest_cfg_t;

/**
 *  bit mask for twp formatter configuration command
 */
typedef enum {
    P64H_SYSC_TRACE_TWP_FMT_CFG_SYNC_COUNT   = ONE_HOT(0), ///< sync count cfg set mask
    P64H_SYSC_TRACE_TWP_FMT_CFG_FLUSH_NORMAL = ONE_HOT(1), ///< flush normal cfg set mask
    P64H_SYSC_TRACE_TWP_FMT_CFG_HOLD_TIME    = ONE_HOT(2), ///< hold time cfg set mask
} p64h_sysc_trace_twp_fmt_cfg_cmd_t;

/**
 * system level trace tracce port configuration
 */
typedef struct {
    uint32_t twp_fmt_cmd_mask;    ///< Cmd mask for twp formatter cfg; see p64h_sysc_trace_twp_fmt_cfg_cmd_t
    uint32_t atb_sync_count;      ///< 12-bit counter value to send periodic synchronization requests to the ATB initiator using syncreq.
                                  // It also indicates the number of complete frames between TWP synchronization packets.
                                  // If this field is programmed as 0x0, the synchronization counter is disabled.
                                  // If this field is programmed with 0x1-0x7 the programmed value is 0x8.
    uint32_t funnel_flush_normal; ///< This bit, when clear, allows target ports that are already flushed to
                                  // receive further data even if there are other ports that have not
                                  // completed flush. If set, a port that has completed flush is not be
                                  // allowed to receive further data until all ports have completed
                                  // flush.
    uint32_t funnel_hold_time;    ///< Hold time. Value sets the minimum hold time before switching trace
                                  // sources (funnel inputs) based on the ID. Value used is programmed
                                  // value + 1. 0x0 - 1 transaction hold time. 0x1 - 2 transactions hold
                                  // time. 0x2 - 3 transactions hold time. 0x3 - Reserved.

} p64h_sysc_trace_twp_fmt_cfg_t;

/**
 * CORE_N_ETR_groupA_t
 */
typedef struct {
    uint32_t xtrig_out_select_0; ///< mask for selecting out trig, each bit represents which of the 32  bits of TRIGGER_IN gets 'or'ed together for
                                 ///< TRIGGER_OUT
    uint32_t xtrig_out_select_1; ///< mask for selecting out trig, each bit represents which of the 32  bits of TRIGGER_IN gets 'or'ed together for
                                 ///< TRIGGER_OUT
    uint32_t xtrig_out_select_2; ///< mask for selecting out trig, each bit represents which of the 14  bits of TRIGGER_IN gets 'or'ed together for
                                 ///< TRIGGER_OUT
} p64h_sysc_cross_matrix_single_entry_t;

/**
 *  cross trigger matrix configuration
 *  There are 78 trig in -> trig out.
 *  Each trig out can be configured to activate to each trig in by setting that bit to one
 */
typedef struct {
    p64h_sysc_cross_matrix_single_entry_t xtrig_out[SYS_TRACE_NUM_CROSS_TRIGGER]; ///< CROSS_TRIGGER_OUT_SELECT_0
                                                                                  ///< CROSS_TRIGGER_OUT_SELECT_1
                                                                                  ///< CROSS_TRIGGER_OUT_SELECT_2
} p64h_sysc_trace_xtrig_matrix_cfg_t;

/**
 * @brief
 *   Specifies any information required to configure the tracing system of the device
 */
typedef struct {
    uint32_t                           enable;            ///< enable or disable the trace sok
    uint32_t                           trace_srcs_msk;    ///< bitmask for sources to activate, p64h_sysc_trace_src_t
    p64h_sysc_trace_twp_fmt_cfg_t      trace_twp_fmt_cfg; ///< twp formatter configurations
    p64h_sysc_trace_dest_cfg_t         trace_dest_cfg;    ///< trace data-path configuration
    p64h_sysc_trace_xtrig_matrix_cfg_t xtrig_cfg;         ///< cross trigger matrix configurations

} p64h_sysc_trace_dev_cfg_t;

/**Trace Memory Controller Status register** */
typedef struct {
    uint32_t trace_buffer_full;     ///< Trace buffer is full
    uint32_t trace_mem_ctrl_ready;  ///< Trace capture has stopped and flushed &
                                    // The TMC is not tracing because of the DrainBuffer bit of the FFCR being set & he AXI interface is not busy &
                                    // the AXI interface is not busy
    uint32_t trace_pipelines_empty; ///< This bit is set when trace capture has stopped, and all internal pipelines and buffers have drained.
    uint32_t trace_buffer_empty;    ///< If set, this bit indicates that the TMC does not contain any valid trace data
    uint32_t trace_mem_err;         ///<   This bit indicates that an error has occurred on the AXI master interface.
} p64h_sysc_trace_mem_ctrl_status_t;

/**
 * @brief Selects which trace data p64h_sysc_trace_data_get() returns.
 */
typedef enum {
    P64H_SYSC_TRACE_DATA_TYPE_SINK = 0, ///< Hardware trace-sink data
    P64H_SYSC_TRACE_DATA_TYPE_DTIM_SW,  ///< Software boot-trace ring in DTIM (HPSC-7775)
    P64H_SYSC_TRACE_DATA_TYPE_LAST      ///< marker / count
} p64h_sysc_trace_data_type_t;

/* ============================================================================
 *  Low-overhead boot-stage tracepoints captured into a ring buffer at a fixed
 *  address in the SysC core-internal DTIM. Firmware records points via
 *  p64h_sysc_trace_record(); the entire ring can be retrieved with p64h_sysc_trace_data_get()
 *  (type P64H_SYSC_TRACE_DATA_TYPE_DTIM_SW) and decoded by the host using the
 *  p64h_sysc_sw_trace_buffer_t / p64h_sysc_sw_tracepoint_t layout.
 * ==========================================================================*/

/** Ring-header magic ("SWTR"); distinguishes an initialized ring from zeroed DTIM. */
#define TRACE_SW_MAGIC 0x53575452UL
/** Number of tracepoint slots in the ring (12 B each; well within 64 KB DTIM). */
#define TRACE_SW_NUM_ENTRIES 256u
/** Frequency (Hz) of the CLINT mtime used for tracepoint timestamps (DTB
 *  timebase-frequency); lets the host convert tick deltas to time. */
#define TRACE_SW_MTIME_HZ 50000000u

/**
 * @brief Boot-stage discriminator for a software tracepoint.
 *
 * Per-partition stages carry the partition id (0..7) in sw_tracepoint_t.data.
 * BOOT_STAGE_SVC_SYSTEM_HEALTH_CHK and BOOT_STAGE_PSM_STATUS_SET are reserved
 * placeholders (not yet instrumented).
 */
typedef enum {
    P64H_SYSC_BOOT_STAGE_NULL = 0,                  ///< Null boot stage
    P64H_SYSC_BOOT_STAGE_BSP_START,                 ///< RTEMS BSP entry (bsp_start)
    P64H_SYSC_BOOT_STAGE_FW_START,                  ///< RTEMS Init() entry
    P64H_SYSC_BOOT_STAGE_SVC_SYSTEM_PHASE0,         ///< system service phase 0 complete
    P64H_SYSC_BOOT_STAGE_SVC_SYSTEM_PHASE1,         ///< system service phase 1 complete
    P64H_SYSC_BOOT_STAGE_SVC_SYSTEM_PHASE2,         ///< system service phase 2 complete
    P64H_SYSC_BOOT_STAGE_SVC_SYSTEM_DDR_TRAINING,   ///< DDR training/config
    P64H_SYSC_BOOT_STAGE_SVC_SYSTEM_HEALTH_CHK,     ///< reserved (not yet instrumented)
    P64H_SYSC_BOOT_STAGE_SVC_APPC_BS_APPC_STATIC,   ///< AppC static config
    P64H_SYSC_BOOT_STAGE_SVC_APPC_BS_APPC_CFG,      ///< AppC partition config   (data = partition id)
    P64H_SYSC_BOOT_STAGE_SVC_APPC_BS_APPC_BOOT,     ///< AppC partition boot     (data = partition id)
    P64H_SYSC_BOOT_STAGE_SVC_APPC_BS_APPC_CMD_LOAD, ///< AppC artifact load      (data = partition id)
    P64H_SYSC_BOOT_STAGE_PSM_STATUS_SET,            ///< reserved (PSM API out of scope)
    P64H_SYSC_BOOT_STAGE_LAST                       ///< marker / count
} p64h_sysc_boot_stage_t;

/** @brief A single software tracepoint record (12 bytes). */
typedef struct {
    uint32_t               mtime;      ///< hardware timestamp (CLINT mtime low word; ITC TBD)
    p64h_sysc_boot_stage_t boot_stage; ///< stage discriminator
    uint32_t               data;       ///< stage-specific payload (partition id, artifact size, rc, ...)
} p64h_sysc_sw_tracepoint_t;

/**
 * @brief DTIM software-trace region: ring header + tracepoint slots.
 *
 */
typedef struct {
    uint32_t                  magic;      ///< TRACE_SW_MAGIC once initialized
    uint32_t                  wr_index;   ///< next write slot, in [0, count)
    uint32_t                  wrap_count; ///< number of times the ring has wrapped
    uint32_t                  count;      ///< number of slots (== TRACE_SW_NUM_ENTRIES)
    p64h_sysc_sw_tracepoint_t entries[TRACE_SW_NUM_ENTRIES];
} p64h_sysc_sw_trace_buffer_t;

#endif // P64H_SYSC_TRACE_TYPES_H
