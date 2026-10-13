/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

#include <rpmi/librpmi_mchp.h>
#include <rpmi/librpmi_types.h>
#include <rpmi/librpmi.h>
#include <p64h_sysc_env.h>

/* Private Defines ------------------------------------------------ */
/// calculate the checksum for the handle_ptr
#define P64H_SYSC_RPMI_HANDLE_CKSUM_GET(handle_ptr) rpmi_crc32((const uint8_t*)(handle_ptr), offsetof(p64h_sysc_handle_t, checksum))

/* Private Structs and Enums -------------------------------------- */
/* Private Variables ---------------------------------------------- */
/** RPMI shared memory instance */
const char* rpmi_shmem_names[]
    = { "P64H_SYSC_SHMEM_M_0", "P64H_SYSC_SHMEM_M_1", "P64H_SYSC_SHMEM_M_2", "P64H_SYSC_SHMEM_M_3", "P64H_SYSC_SHMEM_M_4",   "P64H_SYSC_SHMEM_M_5",
        "P64H_SYSC_SHMEM_M_6", "P64H_SYSC_SHMEM_M_7", "P64H_SYSC_SHMEM_S_0", "P64H_SYSC_SHMEM_S_1", "P64H_SYSC_SHMEM_S_2",   "P64H_SYSC_SHMEM_S_3",
        "P64H_SYSC_SHMEM_S_4", "P64H_SYSC_SHMEM_S_5", "P64H_SYSC_SHMEM_S_6", "P64H_SYSC_SHMEM_S_7", "P64H_SYSC_SHMEM_REMOTE" };

/* Prototypes ----------------------------------------------------- */
static enum rpmi_error         shmem_env_memcpy_read(void* priv, rpmi_uint64_t addr, void* in, rpmi_uint32_t len);
static enum rpmi_error         shmem_env_memcpy_write(void* priv, rpmi_uint64_t addr, const void* out, rpmi_uint32_t len);
static enum rpmi_error         shmem_env_memset_fill(void* priv, rpmi_uint64_t addr, char ch, rpmi_uint32_t len);
static enum rpmi_error         io_read(void* priv, void* in, rpmi_uint32_t len);
static enum rpmi_error         io_write(void* priv, const void* out, rpmi_uint32_t len);
static enum rpmi_error         io_flush_rx(void* priv);
static rpmi_bool_t             is_empty(void* priv);

struct rpmi_shmem_platform_ops rpmi_shmem_simple_ops = {
    .read  = shmem_env_memcpy_read,
    .write = shmem_env_memcpy_write,
    .fill  = shmem_env_memset_fill,
};

struct rpmi_io_platform_ops rpmi_io_simple_ops = { .read = io_read, .write = io_write, .is_empty = is_empty, .flush_rx = io_flush_rx };

/* Private Function Definitions ----------------------------------- */
static enum rpmi_error shmem_env_memcpy_read(void* priv, rpmi_uint64_t addr, void* in, rpmi_uint32_t len)
{
    void* ptr = NULL;
    ptr       = rpmi_env_memcpy(in, (const void*)(uintptr_t)addr, len);
    return (NULL != ptr) ? RPMI_SUCCESS : RPMI_ERR_FAILED;
}

static enum rpmi_error shmem_env_memcpy_write(void* priv, rpmi_uint64_t addr, const void* out, rpmi_uint32_t len)
{
    void* ptr = NULL;
    ptr       = rpmi_env_memcpy((void*)(uintptr_t)addr, out, len);
    return (NULL != ptr) ? RPMI_SUCCESS : RPMI_ERR_FAILED;
}

static enum rpmi_error shmem_env_memset_fill(void* priv, rpmi_uint64_t addr, char ch, rpmi_uint32_t len)
{
    rpmi_env_memset((void*)(uintptr_t)addr, ch, len);
    return RPMI_SUCCESS;
}

static enum rpmi_error io_read(void* priv, void* in, rpmi_uint32_t len)
{
    return rpmi_env_io_read(priv, in, len);
}

static enum rpmi_error io_write(void* priv, const void* out, rpmi_uint32_t len)
{
    return rpmi_env_io_write(priv, out, len);
}

static enum rpmi_error io_flush_rx(void* priv)
{
    return rpmi_env_io_flush_rx(priv);
}

static rpmi_bool_t is_empty(void* priv)
{
    return rpmi_env_io_is_empty(priv);
}

/* Public Function Definitions ------------------------------------ */
bool __attribute__((weak)) rpmi_shmem_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_mem_cfg_t* shmem_cfg_ptr)
{
    if (!handle_ptr || !shmem_cfg_ptr || P64H_SYSC_RPMI_CID_GET(handle_ptr) >= LAST_P64H_SYSC_RPMI_CID) {
        return false;
    }
    rpmi_shmem_t* shmem_ptr = &handle_ptr->shmem;
    rpmi_env_memset(shmem_ptr, 0, sizeof(rpmi_shmem_t));
    shmem_ptr->name     = rpmi_shmem_names[P64H_SYSC_RPMI_CID_GET(handle_ptr)];
    shmem_ptr->base     = shmem_cfg_ptr->base_addr;
    shmem_ptr->size     = shmem_cfg_ptr->size;
    shmem_ptr->ops      = &rpmi_shmem_simple_ops;
    shmem_ptr->ops_priv = NULL;
    return true;
}

bool __attribute__((weak)) rpmi_io_init(p64h_sysc_handle_t* handle_ptr, const rpmi_io_port_t* port_ptr)
{
    if (!handle_ptr || !port_ptr) {
        return false;
    }
    rpmi_io_t* io_ptr = &handle_ptr->io;
    rpmi_env_memset(io_ptr, 0, sizeof(rpmi_io_t));
    io_ptr->name  = "P64H_SYSC_IO_SYSC_REMOTE";
    io_ptr->shmem = &handle_ptr->shmem;
    rpmi_env_memcpy(&io_ptr->port, port_ptr, sizeof(*port_ptr));
    io_ptr->ops      = &rpmi_io_simple_ops;
    io_ptr->ops_priv = port_ptr->io_priv;

    return true;
}

bool p64h_sysc_rpmi_shmem_ctxt_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_cfg_t* cfg_ptr)
{
    if (!handle_ptr || !cfg_ptr) {
        return false;
    }
    handle_ptr->init = rpmi_shmem_init(handle_ptr, &cfg_ptr->mem);
    if (true == handle_ptr->init) {
        handle_ptr->init = p64h_sysc_rpmi_shmem_transport_init(handle_ptr);
    }
    return handle_ptr->init;
}

bool __attribute__((weak)) p64h_sysc_rpmi_io_transport_init(p64h_sysc_handle_t* handle_ptr)
{
    if (NULL == handle_ptr) {
        return false;
    }
    struct rpmi_io*                    io_ptr       = &handle_ptr->io;
    struct rpmi_transport_io*          trans_io_ptr = &handle_ptr->trans_io;
    struct rpmi_transport_shmem_queue* queue_ptr    = &handle_ptr->ctxt.queues[0];
    const p64h_sysc_rpmi_tr_cfg_t*     tr_ptr       = &handle_ptr->ctxt.tr;

    rpmi_env_memset(trans_io_ptr, 0, sizeof(struct rpmi_transport_io));
    rpmi_env_memset(queue_ptr, 0, sizeof(struct rpmi_transport_shmem_queue) * RPMI_QUEUE_MAX);
    rpmi_env_memset(&handle_ptr->lock, 0, sizeof(osal_lock));
    if (!p64h_sysc_rpmi_slot_size_validate(tr_ptr->a2p_slot_size, RPMI_A2P_SLOT_SIZE_ALIGNED)) {
        return false;
    }
    if (!p64h_sysc_rpmi_slot_size_validate(tr_ptr->p2a_slot_size, RPMI_P2A_SLOT_SIZE_ALIGNED)) {
        return false;
    }

    trans_io_ptr->io                       = io_ptr;
    trans_io_ptr->trans_common.queue_count = (tr_ptr->p2a_queue_size != 0u) ? RPMI_QUEUE_MAX : RPMI_QUEUE_MIN;
    trans_io_ptr->trans_common.queues      = &queue_ptr[0];
    if (!p64h_sysc_rpmi_trans_io_init(handle_ptr)) {
        return false;
    }
    return true;
}

bool __attribute__((weak)) p64h_sysc_rpmi_remote_ctxt_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_cfg_t* cfg_ptr)
{
    if (!handle_ptr || !cfg_ptr) {
        return false;
    }

    handle_ptr->init = rpmi_env_io_init(P64H_SYSC_RPMI_CID_GET(handle_ptr), &cfg_ptr->io);
    if (false == handle_ptr->init) {
        return false;
    }

    handle_ptr->init = rpmi_io_init(handle_ptr, &cfg_ptr->io);
    if (false == handle_ptr->init) {
        return false;
    }
    handle_ptr->init = p64h_sysc_rpmi_io_transport_init(handle_ptr);
    return handle_ptr->init;
}

bool p64h_sysc_rpmi_handle_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_cfg_t* cfg_ptr)
{
    enum rpmi_error rpmi_rc = RPMI_SUCCESS;
    void*           ptr     = NULL;
    if (!handle_ptr || !cfg_ptr || handle_ptr->role >= RPMI_NUM_ROLES) {
        return false;
    }

    handle_ptr->role = cfg_ptr->role;
    if (RPMI_TRANS_SHMEM == cfg_ptr->type) {
        if (RPMI_ROLE_A == handle_ptr->role) {
            rpmi_rc = shmem_env_memcpy_read(NULL, cfg_ptr->mem.base_addr + P64H_SYSC_HANDLE_SHMEM_CTXT_OFFSET, &handle_ptr->ctxt,
                                            sizeof(handle_ptr->ctxt));
            if (RPMI_SUCCESS != rpmi_rc) {
                return false;
            }
        } else {
            handle_ptr->ctxt.cid = cfg_ptr->cid;
            ptr                  = rpmi_env_memcpy((void*)&handle_ptr->ctxt.tr, &cfg_ptr->tr, sizeof(cfg_ptr->tr));
            if (NULL == ptr) {
                return false;
            }
        }
    } else if (RPMI_TRANS_IO == cfg_ptr->type) {
        handle_ptr->ctxt.cid = cfg_ptr->cid;
        ptr                  = rpmi_env_memcpy((void*)&handle_ptr->ctxt.tr, &cfg_ptr->tr, sizeof(cfg_ptr->tr));
        if (NULL == ptr) {
            return false;
        }
    } else {
        return false;
    }

    if (P64H_SYSC_RPMI_REMOTE(handle_ptr)) {
        handle_ptr->init = p64h_sysc_rpmi_remote_ctxt_init(handle_ptr, cfg_ptr);
    } else {
        handle_ptr->init = p64h_sysc_rpmi_shmem_ctxt_init(handle_ptr, cfg_ptr);
    }

    if (handle_ptr->init) {
        handle_ptr->checksum = P64H_SYSC_RPMI_HANDLE_CKSUM_GET(handle_ptr);
    }

    return handle_ptr->init;
}

void p64h_sysc_rpmi_handle_uninit(p64h_sysc_handle_t* handle_ptr)
{
    if (p64h_sysc_rpmi_handle_valid(handle_ptr)) {
        handle_ptr->init     = false;
        handle_ptr->checksum = 0;
    }
}

bool p64h_sysc_rpmi_evt_enable(p64h_sysc_handle_t* handle_ptr, p64h_rpmi_service_group_id_t srvgrp, uint32_t evt_id, p64h_sysc_evt_fct_t cb)
{
    uint32_t gid = P64H_RPMI_SRVGRP_TO_INDEX(srvgrp);

    // check parameters
    if (!p64h_sysc_rpmi_handle_valid(handle_ptr)) {
        return false;
    }
    if (gid >= P64H_RPMI_SRVGRP_COUNT || evt_id >= LIBRPMI_EVENT_MAX_NUM) {
        return false;
    }

    handle_ptr->evt_cb[gid].evt_func[evt_id] = cb;
    return true;
}

bool p64h_sysc_rpmi_evt_disable(p64h_sysc_handle_t* handle_ptr, p64h_rpmi_service_group_id_t srvgrp, uint32_t evt_id)
{
    if (!p64h_sysc_rpmi_handle_valid(handle_ptr)) {
        return false;
    }
    uint32_t gid = P64H_RPMI_SRVGRP_TO_INDEX(srvgrp);
    if (gid >= P64H_RPMI_SRVGRP_COUNT || evt_id >= LIBRPMI_EVENT_MAX_NUM) {
        return false;
    }

    handle_ptr->evt_cb[gid].evt_func[evt_id] = NULL;
    return true;
}

static bool p64h_sysc_rpmi_intr_isr(void* param)
{
    p64h_sysc_handle_t* handle_ptr                       = (p64h_sysc_handle_t*)param;
    rpmi_error_t        rpmi_rc                          = RPMI_SUCCESS;
    static uint8_t      msg_buf[RPMI_MAX_SLOT_SIZE + 12] = { 0 };
    rpmi_message_t*     msg_ptr                          = (rpmi_message_t*)msg_buf;
    uint32_t            gid                              = 0;
    uint32_t            evt_id                           = 0;
    p64h_sysc_evt_fct_t evt_func                         = NULL;
    bool                rc                               = false;

    if (p64h_sysc_rpmi_handle_valid(handle_ptr)) {
        do {
            rpmi_rc = rpmi_transport_dequeue((struct rpmi_transport*)&handle_ptr->trans_shmem.trans_common.trans, RPMI_QUEUE_P2A_REQ, msg_ptr);

            if (RPMI_SUCCESS == rpmi_rc && msg_ptr->header.datalen > 0) {
                gid    = P64H_RPMI_SRVGRP_TO_INDEX(msg_ptr->header.servicegroup_id);
                evt_id = msg_ptr->data[0];
                if (gid < P64H_RPMI_SRVGRP_COUNT && evt_id < LIBRPMI_EVENT_MAX_NUM) {
                    evt_func = handle_ptr->evt_cb[gid].evt_func[evt_id];
                }
                if (evt_func != NULL) {
                    evt_func(msg_ptr->data);
                }
                rc = true;
            } else if (RPMI_ERR_IO == rpmi_rc) {
                // No message in queue, not an error, just return
                rc = true;
            }
        } while (RPMI_SUCCESS == rpmi_rc);
    }

    return rc;
}

bool p64h_sysc_rpmi_ipc_init(p64h_sysc_handle_t* handle_ptr, const p64h_ipc_msg_ops* cfg_ptr)
{
    if (!p64h_sysc_rpmi_handle_valid(handle_ptr) || !cfg_ptr) {
        return false;
    }
    // IPC message callback function
    handle_ptr->ipc_ops.ipc_msg_send    = cfg_ptr->ipc_msg_send;
    handle_ptr->ipc_ops.ipc_msg_get     = cfg_ptr->ipc_msg_get;
    handle_ptr->ipc_ops.ipc_int_handler = p64h_sysc_rpmi_intr_isr;
    return true;
}

bool p64h_sysc_rpmi_handle_valid(const p64h_sysc_handle_t* handle_ptr)
{
    if (!handle_ptr || !handle_ptr->init) {
        return false;
    }
    if (handle_ptr->ctxt.cid < P64H_SYSC_RPMI_CID_APPC_M_0 || handle_ptr->ctxt.cid >= LAST_P64H_SYSC_RPMI_CID) {
        return false;
    }
    uint32_t checksum = P64H_SYSC_RPMI_HANDLE_CKSUM_GET(handle_ptr);
    if (checksum != handle_ptr->checksum) {
        return false;
    }
    return true;
}

p64h_sysc_rpmi_cid_t p64h_sysc_rpmi_cid_get(const p64h_sysc_handle_t* handle_ptr)
{
    if (!handle_ptr) {
        return LAST_P64H_SYSC_RPMI_CID;
    }
    return handle_ptr->ctxt.cid;
}

bool p64h_sysc_rpmi_notification_check(const p64h_sysc_handle_t* handle_ptr)
{
    return p64h_sysc_rpmi_intr_isr((void*)handle_ptr);
}
