/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

#ifndef LIB_RPMI_MCHP_H
#define LIB_RPMI_MCHP_H

#include <rpmi/librpmi_p64h_types.h>
#include <ba/p64h_sysc_svc_cfg_ba.h>

#ifdef P64H_SYSC
#include "osal.h"
#else

/// semaphore lock
typedef uint32_t         osal_lock;

static inline osal_lock* osal_lock_create(void)
{
    return (osal_lock*)calloc(1, sizeof(osal_lock));
}
static inline bool osal_lock_destroy(osal_lock* lock_ptr)
{
    if (NULL == lock_ptr) {
        return false;
    }
    free(lock_ptr);
    return true;
}
static inline bool osal_lock_acquire(osal_lock* lock_ptr)
{
    if (NULL == lock_ptr) {
        return false;
    }
    while (__atomic_exchange_n(lock_ptr, 1U, __ATOMIC_SEQ_CST)) {
        __asm__ volatile("nop");
    }
    return true;
}

static inline bool osal_lock_release(osal_lock* lock_ptr)
{
    if (NULL == lock_ptr) {
        return false;
    }
    __atomic_store_n(lock_ptr, 0U, __ATOMIC_SEQ_CST);
    return true;
}

static inline bool osal_init_static_lock(osal_lock* lock_ptr)
{
    if (NULL == lock_ptr) {
        return false;
    }
    __atomic_store_n(lock_ptr, 0U, __ATOMIC_SEQ_CST);
    return true;
}

#endif

/// retrieve the cid for the handle_ptr
#define P64H_SYSC_RPMI_CID_GET(handle_ptr) ((handle_ptr)->ctxt.cid)

/// retrieve the cid of handle_ptr is for remote or not
#define P64H_SYSC_RPMI_REMOTE(handle_ptr) (P64H_SYSC_RPMI_CID_REMOTE == P64H_SYSC_RPMI_CID_GET(handle_ptr))

/// retrieve the offset of ctxt in shared memory
/* Notes: ctxt was stored in first slot with offset of headidx
 * +-------------------+-------------------+-------------------+-------------------+
 * |      Slot 0       |      Slot 1       |      Slot 2       |      Slot 3       |
 * +-------------------+-------------------+-------------------+-------------------+
 * | headidx | ctxt |..|      tailidx      |     data slot0    |     data slot1    |
 * +-------------------+-------------------+-------------------+-------------------+
 */
#define P64H_SYSC_HANDLE_SHMEM_CTXT_OFFSET (sizeof(rpmi_uint32_t))

typedef enum {
    P64H_SYSC_RPMI_CID_APPC_M_0 = 0, ///< RPMI Client identifier for AppC partition 0 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_1,     ///< RPMI Client identifier for AppC partition 1 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_2,     ///< RPMI Client identifier for AppC partition 2 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_3,     ///< RPMI Client identifier for AppC partition 3 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_4,     ///< RPMI Client identifier for AppC partition 4 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_5,     ///< RPMI Client identifier for AppC partition 5 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_6,     ///< RPMI Client identifier for AppC partition 6 (M mode)
    P64H_SYSC_RPMI_CID_APPC_M_7,     ///< RPMI Client identifier for AppC partition 7 (M mode)
    P64H_SYSC_RPMI_CID_APPC_S_0,     ///< RPMI Client identifier for AppC partition 0 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_1,     ///< RPMI Client identifier for AppC partition 1 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_2,     ///< RPMI Client identifier for AppC partition 2 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_3,     ///< RPMI Client identifier for AppC partition 3 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_4,     ///< RPMI Client identifier for AppC partition 4 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_5,     ///< RPMI Client identifier for AppC partition 5 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_6,     ///< RPMI Client identifier for AppC partition 6 (S mode)
    P64H_SYSC_RPMI_CID_APPC_S_7,     ///< RPMI Client identifier for AppC partition 7 (S mode)
    P64H_SYSC_RPMI_CID_REMOTE,       ///< RPMI Client identifier for remote access
    LAST_P64H_SYSC_RPMI_CID,         ///< last RPMI Client identifier
} p64h_sysc_rpmi_cid_t;

/// rmpi request state
typedef enum {
    P64H_SYSC_RPMI_REQ_STATE_NONE         = 0, ///< State none
    P64H_SYSC_RPMI_REQ_STATE_REQ_BUSY     = 1, ///< There is already an outstanding posted request
    P64H_SYSC_RPMI_REQ_STATE_RESP_PENDING = 2, ///< Response is not ready
    LAST_P64H_SYSC_RPMI_REQ_STATE              ///< last RPMI request state
} p64h_sysc_rpmi_req_state_t;

/// rmpi request informations
typedef struct {
    p64h_sysc_rpmi_req_state_t req_state;  ///< request state, see enum p64h_sysc_rpmi_req_state_t
    uint16_t                   svc_grp_id; ///< service group ID
    uint8_t                    svc_id;     ///< service ID
    uint32_t                   thread_id;  ///< thread ID
} rpmi_request_info_t;

/// sysc api rpmi shared memory configuration
typedef struct {
    uint64_t base_addr;
    uint32_t size;
} p64h_sysc_rpmi_mem_cfg_t;

/// sysc api rpmmi transport configuration
typedef struct {
    uint32_t slot_size;
    uint32_t a2p_queue_size;
    uint32_t p2a_queue_size;
} p64h_sysc_rpmi_tr_cfg_t;

/// The maximum size of IPC message
#define IPC_MESSAGE_MAX_SZ (64u)

/// IPC message buffer
typedef struct {
    uint8_t buf[IPC_MESSAGE_MAX_SZ]; ///< IPC message buffer
} p64h_ipc_msg_buf_t;

/// Platform specific IPC message operations
typedef struct {
    int (*ipc_msg_send)(const uint32_t chnl, uint8_t* msg, uint32_t msg_size); ///< IPC message send
    int (*ipc_msg_get)(const uint32_t chnl, uint8_t* msg, uint32_t* msg_size); ///< IPC message get
    void (*ipc_int_handler)(void* arg);                                        ///< IPC interrupt handler
} p64h_ipc_msg_platform_ops;

/// sysc RPMI shared memory configuration
typedef struct {
    p64h_sysc_rpmi_mem_cfg_t  mem; ///< shared memory configuration
    p64h_ipc_msg_platform_ops ops; ///< Pointer to platform specific operations
} p64h_sysc_rpmi_shmem_cfg_t;

/// sysc RPMI remote configuration
typedef struct {
    rpmi_io_port_t           io;  ///< peripheral type
    p64h_sysc_rpmi_mem_cfg_t mem; ///< shared memory configuration
    p64h_sysc_rpmi_tr_cfg_t  tr;  ///< transport configuration
} p64h_sysc_rpmi_remote_cfg_t;

/// Enum encapsulating the possible RPMI platform transport types
typedef enum {
    RPMI_TRANS_SHMEM = 0, ///< this is the share memory transport
    RPMI_TRANS_IO,        ///< this is the io transport
    LAST_RPMI_TRANS       ///< the number of transport in the enum
} rpmi_trans_type_t;

/// RPMI platform initialized and shared context
typedef struct {
    p64h_sysc_rpmi_cid_t         cid;                    ///< client identifier
    p64h_sysc_rpmi_tr_cfg_t      tr;                     ///< transport configuration
    rpmi_transport_shmem_queue_t queues[RPMI_QUEUE_MAX]; ///< queues
    p64h_sysc_rpmi_q_int_mode_t  p2a_queue_int_mode;     ///< P2A queue interrupt mode
    p64h_sysc_rpmi_q_int_mode_t  a2p_queue_int_mode;     ///< A2P queue interrupt mode
    uint32_t                     ipc_channel;            ///< IPC channel for RPMI queue
    p64h_ipc_msg_platform_ops    ops;                    ///< Pointer to platform specific operations
    bool req_posted; ///< default false, when true API send req, check resp and return a message when response is not available
} rpmi_p_ctxt_t;

/// sysc RPMI configuration
/*
 * Mandatory Fields Table for p64h_sysc_rpmi_cfg_t
 *
 * +--------+------+-----+-----+-----+-----+
 * |  Type  | role | cid | mem | io  | tr  |
 * +--------+------+-----+-----+-----+-----+
 * | shmem  |  P   |  x  |  x  |     |  x  |
 * | shmem  |  A   |     |  x  |     |     |
 * | io     |  P   |  x  |  x  |  x  |  x  |
 * | io     |  A   |  x  |  x* |  x  |  x  |
 * +--------+------+-----+-----+-----+-----+
 *
 * Notes:
 * - 'x' = Mandatory, ' ' = Not mandatory
 * - For 'mem', it is mandatory only if io on HWEMU platform (marked as x*)
 */
typedef struct {
    rpmi_role_t              role; ///< role state
    rpmi_trans_type_t        type; ///< transport type
    p64h_sysc_rpmi_cid_t     cid;  ///< client identifier(mandatory for Application role with IO transport)
    p64h_sysc_rpmi_mem_cfg_t mem;  ///< shared memory configuration
    rpmi_io_port_t           io;   ///< peripheral type
    p64h_sysc_rpmi_tr_cfg_t  tr;   ///< transport configuration
} p64h_sysc_rpmi_cfg_t;

/// RPMI client context
typedef struct {
    bool                   init;                           ///< client initialized state
    rpmi_role_t            role;                           ///< role state
    rpmi_p_ctxt_t          ctxt;                           ///< RPMI context initialized for platform
    rpmi_shmem_t           shmem;                          ///< shared memory
    rpmi_io_t              io;                             ///< io
    rpmi_transport_shmem_t trans_shmem;                    ///< shmem transport
    rpmi_transport_io_t    trans_io;                       ///< io transport
    osal_lock              lock;                           ///< transport lock
    uint32_t               access_control;                 ///< privilege level
    rpmi_event_callback_t  evt_cb[P64H_RPMI_SRVGRP_COUNT]; ///< RPMI event callback
    rpmi_request_info_t    req_info;                       ///< RPMI request informations
} rpmi_client_ctxt_t;

/**
 * @brief RPMI sysc handle descriptor
 */
typedef rpmi_client_ctxt_t p64h_sysc_handle_t;

/// P64H SYSC RPMI Library Interface
bool p64h_sysc_rpmi_slot_size_validate(const rpmi_uint32_t slot_size);
bool p64h_sysc_rpmi_queue_sizes_validate(const p64h_sysc_rpmi_tr_cfg_t* tr_ptr, const struct rpmi_shmem* shmem_ptr);
bool p64h_sysc_rpmi_queues_init(struct rpmi_transport_common* common_ptr, const p64h_sysc_rpmi_tr_cfg_t* tr_ptr);
bool p64h_sysc_rpmi_trans_io_init(p64h_sysc_handle_t* handle_ptr);
bool p64h_sysc_rpmi_shmem_transport_init(p64h_sysc_handle_t* handle_ptr);
bool p64h_sysc_rpmi_shmem_ctxt_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_cfg_t* cfg_ptr);
bool p64h_sysc_rpmi_handle_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_cfg_t* cfg_ptr);
bool p64h_sysc_rpmi_evt_enable(p64h_sysc_handle_t* handle_ptr, p64h_rpmi_service_group_id_t srvgrp, uint32_t evt_id, p64h_sysc_evt_fct_t cb);
bool p64h_sysc_rpmi_evt_disable(p64h_sysc_handle_t* handle_ptr, p64h_rpmi_service_group_id_t srvgrp, uint32_t evt_id);
void p64h_sysc_rpmi_intr_isr(void* param);
#endif // LIB_RPMI_MCHP_H
