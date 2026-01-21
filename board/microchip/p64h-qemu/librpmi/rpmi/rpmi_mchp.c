/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

#include <rpmi/librpmi_mchp.h>
#include <rpmi/librpmi_types.h>
#include <rpmi/librpmi.h>
#include <p64h_sysc_env.h>

/* Private Defines ------------------------------------------------ */
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
static rpmi_bool_t             is_empty(void* priv);

struct rpmi_shmem_platform_ops rpmi_shmem_simple_ops = {
    .read  = shmem_env_memcpy_read,
    .write = shmem_env_memcpy_write,
    .fill  = shmem_env_memset_fill,
};

struct rpmi_io_platform_ops rpmi_io_simple_ops = {
    .read     = io_read,
    .write    = io_write,
    .is_empty = is_empty,
};

/* Private Function Definitions ----------------------------------- */
static enum rpmi_error shmem_env_memcpy_read(void* priv, rpmi_uint64_t addr, void* in, rpmi_uint32_t len)
{
    rpmi_env_memcpy(in, (const void*)(uintptr_t)addr, len);
    return RPMI_SUCCESS;
}

static enum rpmi_error shmem_env_memcpy_write(void* priv, rpmi_uint64_t addr, const void* out, rpmi_uint32_t len)
{
    rpmi_env_memcpy((void*)(uintptr_t)addr, out, len);
    return RPMI_SUCCESS;
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

static rpmi_bool_t is_empty(void* priv)
{
    return rpmi_env_io_is_empty(priv);
}

/* Public Function Definitions ------------------------------------ */
bool __attribute__((weak)) rpmi_shmem_init(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_rpmi_mem_cfg_t* shmem_cfg_ptr)
{
    if (!handle_ptr || !shmem_cfg_ptr || P64H_SYSC_RPMI_CID_GET(handle_ptr) >= sizeof(rpmi_shmem_names)) {
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
    io_ptr->name     = "P64H_SYSC_IO_SYSC_REMOTE";
    io_ptr->shmem    = &handle_ptr->shmem;
    io_ptr->port     = port_ptr;
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
    if (!p64h_sysc_rpmi_slot_size_validate(tr_ptr->slot_size)) {
        return false;
    }

    trans_io_ptr->io                       = io_ptr;
    trans_io_ptr->trans_common.queue_count = (tr_ptr->p2a_queue_size != 0u) ? RPMI_QUEUE_MAX : 2u;
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
    if (!handle_ptr || !cfg_ptr || handle_ptr->role >= RPMI_NUM_ROLES) {
        return false;
    }

    handle_ptr->role = cfg_ptr->role;
    if (RPMI_TRANS_SHMEM == cfg_ptr->type) {
        if (RPMI_ROLE_A == handle_ptr->role) {
            shmem_env_memcpy_read(NULL, cfg_ptr->mem.base_addr + P64H_SYSC_HANDLE_SHMEM_CTXT_OFFSET, &handle_ptr->ctxt, sizeof(handle_ptr->ctxt));
        } else {
            handle_ptr->ctxt.cid = cfg_ptr->cid;
            rpmi_env_memcpy((void*)&handle_ptr->ctxt.tr, &cfg_ptr->tr, sizeof(cfg_ptr->tr));
        }
    } else if (RPMI_TRANS_IO == cfg_ptr->type) {
        handle_ptr->ctxt.cid = cfg_ptr->cid;
        rpmi_env_memcpy((void*)&handle_ptr->ctxt.tr, &cfg_ptr->tr, sizeof(cfg_ptr->tr));
    } else {
        return false;
    }

    if (P64H_SYSC_RPMI_REMOTE(handle_ptr)) {
        handle_ptr->init = p64h_sysc_rpmi_remote_ctxt_init(handle_ptr, cfg_ptr);
    } else {
        handle_ptr->init = p64h_sysc_rpmi_shmem_ctxt_init(handle_ptr, cfg_ptr);
    }

    return handle_ptr->init;
}

bool p64h_sysc_rpmi_evt_enable(p64h_sysc_handle_t* handle_ptr, p64h_rpmi_service_group_id_t srvgrp, uint32_t evt_id, p64h_sysc_evt_fct_t cb)
{
    // check parameters
    if (handle_ptr == NULL || evt_id >= LIBRPMI_EVENT_MAX_NUM) {
        return false;
    }

    handle_ptr->evt_cb[srvgrp].evt_func[evt_id] = cb;
    return true;
}

bool p64h_sysc_rpmi_evt_disable(p64h_sysc_handle_t* handle_ptr, p64h_rpmi_service_group_id_t srvgrp, uint32_t evt_id)
{
    if (handle_ptr == NULL || evt_id >= LIBRPMI_EVENT_MAX_NUM) {
        return false;
    }

    handle_ptr->evt_cb[srvgrp].evt_func[evt_id] = NULL;

    return true;
}

void p64h_sysc_rpmi_intr_isr(void* param)
{
    p64h_sysc_handle_t* handle_ptr = (p64h_sysc_handle_t*)param;
    rpmi_error_t        rpmi_err   = RPMI_SUCCESS;
    rpmi_message_t      msg        = { 0 };
    rpmi_uint16_t       srvgrp     = 0;
    uint32_t            evt_id     = 0;

    rpmi_err = rpmi_transport_dequeue((struct rpmi_transport*)&handle_ptr->trans_shmem.trans_common.trans, RPMI_QUEUE_P2A_REQ, &msg);
    if (RPMI_SUCCESS == rpmi_err && msg.header.datalen > 0) {
        srvgrp                       = msg.header.servicegroup_id;
        evt_id                       = msg.data[0];
        p64h_sysc_evt_fct_t evt_func = handle_ptr->evt_cb[srvgrp].evt_func[evt_id];
        if (evt_func != NULL) {
            evt_func(param);
        }
    }
}