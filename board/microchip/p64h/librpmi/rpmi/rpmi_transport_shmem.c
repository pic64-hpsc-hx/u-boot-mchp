/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

#include <rpmi/librpmi.h>

/* Private Defines ------------------------------------------------ */
#undef DEBUG

#ifdef DEBUG
#define DPRINTF(msg...) rpmi_env_printf(msg)
#else
#define DPRINTF(msg...)
#endif

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

/* Private Structs and Enums -------------------------------------- */
/* Private Variables ---------------------------------------------- */
const char* rpmi_transport_shmem_names[]
    = { "P64H_SYSC_SHMEM_TR_M_0", "P64H_SYSC_SHMEM_TR_M_1",   "P64H_SYSC_SHMEM_TR_M_2", "P64H_SYSC_SHMEM_TR_M_3", "P64H_SYSC_SHMEM_TR_M_4",
        "P64H_SYSC_SHMEM_TR_M_5", "P64H_SYSC_SHMEM_TR_M_6",   "P64H_SYSC_SHMEM_TR_M_7", "P64H_SYSC_SHMEM_TR_S_0", "P64H_SYSC_SHMEM_TR_S_1",
        "P64H_SYSC_SHMEM_TR_S_2", "P64H_SYSC_SHMEM_TR_S_3",   "P64H_SYSC_SHMEM_TR_S_4", "P64H_SYSC_SHMEM_TR_S_5", "P64H_SYSC_SHMEM_TR_S_6",
        "P64H_SYSC_SHMEM_TR_S_7", "P64H_SYSC_SHMEM_TR_REMOTE" };

/* Prototypes ----------------------------------------------------- */
/* Private Function Definitions ----------------------------------- */
static rpmi_bool_t shmem_is_empty(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    struct rpmi_transport_shmem* shtrans    = trans->priv;
    struct rpmi_shmem*           shmem      = shtrans->shmem;
    rpmi_uint64_t                queue_base = shtrans->trans_common.queues[qtype].queue_base;
    rpmi_uint32_t                headidx, tailidx;
    int                          rc;

    rc = rpmi_shmem_read(shmem, queue_base, &headidx, sizeof(headidx));
    if (rc) {
        DPRINTF("%s: %s: failed to read head index of qtype %d\n", __func__, trans->name, qtype);
        return false;
    }
    headidx = rpmi_to_le32(headidx);

    rc      = rpmi_shmem_read(shmem, queue_base + trans->slot_size, &tailidx, sizeof(tailidx));
    if (rc) {
        DPRINTF("%s: %s: failed to read tail index of qtype %d\n", __func__, trans->name, qtype);
        return false;
    }
    tailidx = rpmi_to_le32(tailidx);

    return (headidx == tailidx) ? true : false;
}

static rpmi_bool_t shmem_is_full(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    struct rpmi_transport_shmem* shtrans    = trans->priv;
    rpmi_uint64_t                queue_base = shtrans->trans_common.queues[qtype].queue_base;
    rpmi_uint32_t                data_slots = shtrans->trans_common.queues[qtype].data_slots - 2;
    struct rpmi_shmem*           shmem      = shtrans->shmem;
    rpmi_uint32_t                headidx, tailidx;
    int                          rc;

    rc = rpmi_shmem_read(shmem, queue_base, &headidx, sizeof(headidx));
    if (rc) {
        DPRINTF("%s: %s: failed to read head index of qtype %d\n", __func__, trans->name, qtype);
        return false;
    }
    headidx = rpmi_to_le32(headidx);

    rc      = rpmi_shmem_read(shmem, queue_base + trans->slot_size, &tailidx, sizeof(tailidx));
    if (rc) {
        DPRINTF("%s: %s: failed to read tail index of qtype %d\n", __func__, trans->name, qtype);
        return false;
    }
    tailidx = rpmi_to_le32(tailidx);

    return (rpmi_env_mod32(tailidx + 1, data_slots) == headidx) ? true : false;
}

static enum rpmi_error shmem_enqueue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, const struct rpmi_message* msg)
{
    struct rpmi_transport_shmem* shtrans    = trans->priv;
    rpmi_uint64_t                queue_base = shtrans->trans_common.queues[qtype].queue_base;
    rpmi_uint32_t                data_slots = shtrans->trans_common.queues[qtype].data_slots;
    struct rpmi_shmem*           shmem      = shtrans->shmem;
    rpmi_uint32_t                tailidx;
    uint32_t                     write_len;
    int                          rc;

    if (NULL == msg) {
        return RPMI_ERR_INVALID_PARAM;
    }

    rc = rpmi_shmem_read(shmem, queue_base + trans->slot_size, &tailidx, sizeof(tailidx));
    if (rc) {
        DPRINTF("%s: %s: failed to read tail index of qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_FAILED;
    }
    tailidx = rpmi_to_le32(tailidx);

    // We should only be writing the actual data of the message not slot_size bytes as the input may be less than a full slot_size and
    // in this case we will either write 'garbage' or in a worst case scenario could trigger a segfault if the read from the msg pointer
    // spills out of the segment boundary.
    write_len = msg->header.datalen + sizeof(struct rpmi_message_header);
    // if the message is larger than the slot_size, return an error don't just truncate and return as if nothing was wrong.
    if (write_len > trans->slot_size) {
        return RPMI_ERR_BAD_RANGE;
    }

    rc = rpmi_shmem_write(shmem, queue_base + ((tailidx + 2) * trans->slot_size), msg, write_len);
    if (rc) {
        DPRINTF("%s: %s: failed to write message at tailidx %d for qtype %d\n", __func__, trans->name, tailidx, qtype);
        return RPMI_ERR_FAILED;
    }

    tailidx = rpmi_to_le32(rpmi_env_mod32(tailidx + 1, data_slots));
    rc      = rpmi_shmem_write(shmem, queue_base + trans->slot_size, &tailidx, sizeof(tailidx));
    if (rc) {
        DPRINTF("%s: %s: failed to write tail index for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_FAILED;
    }

    return 0;
}

static enum rpmi_error shmem_dequeue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg)
{
    struct rpmi_transport_shmem* shtrans    = trans->priv;
    rpmi_uint64_t                queue_base = shtrans->trans_common.queues[qtype].queue_base;
    rpmi_uint32_t                data_slots = shtrans->trans_common.queues[qtype].data_slots;
    struct rpmi_shmem*           shmem      = shtrans->shmem;
    rpmi_uint32_t                headidx;
    rpmi_uint32_t                payload_len;
    int                          rc;

    rc = rpmi_shmem_read(shmem, queue_base, &headidx, sizeof(headidx));
    if (rc) {
        DPRINTF("%s: %s: failed to read head index of qtype %d\n", __func__, trans->name, qtype);
        return false;
    }
    headidx = rpmi_to_le32(headidx);

    // read just the header first
    rc = rpmi_shmem_read(shmem, queue_base + ((headidx + 2) * trans->slot_size), out_msg, sizeof(struct rpmi_message_header));
    if (rc) {
        DPRINTF("%s: %s: failed to read message at headidx %d for qtype %d\n", __func__, trans->name, headidx, qtype);
        return RPMI_ERR_FAILED;
    }
    // Capture the payload size from the header and read only the datalen amount of data from the slot incase the storage passed is not the full
    // slot_size. If the datalen indicates more than the slot_size, which should only be possible if memory is corrupted, then truncate and return
    // only slot_size bytes into out_msg. Throwing an error here doesn't help much as that will not remove the problematic message from the queue and
    // there is no chance for recovery. if the caller detects truncation, they can flush the queue which at least has a chance to recover from such a
    // case.
    payload_len = (rpmi_uint32_t)(MIN(out_msg->header.datalen, trans->slot_size - sizeof(struct rpmi_message_header)));
    rc = rpmi_shmem_read(shmem, queue_base + ((headidx + 2) * trans->slot_size + sizeof(struct rpmi_message_header)), out_msg->data, payload_len);
    if (rc) {
        DPRINTF("%s: %s: failed to read message at headidx %d for qtype %d\n", __func__, trans->name, headidx, qtype);
        return RPMI_ERR_FAILED;
    }

    headidx = rpmi_to_le32(rpmi_env_mod32(headidx + 1, data_slots));
    rc      = rpmi_shmem_write(shmem, queue_base, &headidx, sizeof(headidx));
    if (rc) {
        DPRINTF("%s: %s: failed to write head index for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_FAILED;
    }

    return 0;
}

static bool p64h_sysc_rpmi_trans_shmem_init(p64h_sysc_handle_t* handle_ptr)
{
    if (!osal_init_static_lock(&handle_ptr->lock)) {
        return false;
    }

    const p64h_sysc_rpmi_tr_cfg_t* tr_ptr = &handle_ptr->ctxt.tr;
    struct rpmi_transport*         transport_ptr;
    transport_ptr                 = &handle_ptr->trans_shmem.trans_common.trans;
    transport_ptr->name           = rpmi_transport_shmem_names[P64H_SYSC_RPMI_CID_GET(handle_ptr)];
    transport_ptr->is_be          = false;
    transport_ptr->slot_size      = tr_ptr->slot_size;
    transport_ptr->is_p2a_channel = (tr_ptr->p2a_queue_size > 0u);
    transport_ptr->is_empty       = shmem_is_empty;
    transport_ptr->is_full        = shmem_is_full;
    transport_ptr->enqueue        = shmem_enqueue;
    transport_ptr->dequeue        = shmem_dequeue;
    transport_ptr->lock           = &handle_ptr->lock;
    transport_ptr->priv           = &handle_ptr->trans_shmem;
    return true;
}

/* Public Function Definitions ------------------------------------ */
bool p64h_sysc_rpmi_shmem_transport_init(p64h_sysc_handle_t* handle_ptr)
{
    if (NULL == handle_ptr || P64H_SYSC_RPMI_CID_GET(handle_ptr) >= LAST_P64H_SYSC_RPMI_CID) {
        return false;
    }

    enum rpmi_error                    retcode;
    struct rpmi_shmem*                 shmem_ptr       = &handle_ptr->shmem;
    struct rpmi_transport_shmem*       trans_shmem_ptr = &handle_ptr->trans_shmem;
    struct rpmi_transport_shmem_queue* queue_ptr       = &handle_ptr->ctxt.queues[0];
    const p64h_sysc_rpmi_tr_cfg_t*     tr_ptr          = &handle_ptr->ctxt.tr;

    rpmi_env_memset(trans_shmem_ptr, 0, sizeof(struct rpmi_transport_shmem));
    rpmi_env_memset(&handle_ptr->lock, 0, sizeof(osal_lock));
    if (!p64h_sysc_rpmi_slot_size_validate(tr_ptr->slot_size)) {
        return false;
    }

    if (!p64h_sysc_rpmi_queue_sizes_validate(tr_ptr, shmem_ptr)) {
        return false;
    }
    trans_shmem_ptr->shmem                    = shmem_ptr;
    trans_shmem_ptr->trans_common.queue_count = (tr_ptr->p2a_queue_size != 0u) ? RPMI_QUEUE_MAX : 2u;
    trans_shmem_ptr->trans_common.queues      = &queue_ptr[0];

    /* Fill the shared memory with zeros */
    if (P64H_SYSC_HANDLE_SHMEM_CTXT_OFFSET + sizeof(handle_ptr->ctxt) > (size_t)(tr_ptr->slot_size / LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SLOTS)) {
        return false;
    }
    if (RPMI_ROLE_P == handle_ptr->role) {
        rpmi_env_memcpy((void*)&handle_ptr->ctxt.tr, tr_ptr, sizeof(*tr_ptr));
        rpmi_env_memset(queue_ptr, 0, sizeof(struct rpmi_transport_shmem_queue) * RPMI_QUEUE_MAX);
        if (!p64h_sysc_rpmi_queues_init(&trans_shmem_ptr->trans_common, tr_ptr)) {
            return false;
        }
        retcode = rpmi_shmem_fill(shmem_ptr, 0, 0, rpmi_shmem_size(shmem_ptr));
        if (retcode != RPMI_SUCCESS) {
            return false;
        }
        retcode = rpmi_shmem_write(shmem_ptr, P64H_SYSC_HANDLE_SHMEM_CTXT_OFFSET, &handle_ptr->ctxt, sizeof(handle_ptr->ctxt));
        if (retcode != RPMI_SUCCESS) {
            return false;
        }
    } else {
        // No need for an Application role, as it reads the context from shared memory
    }

    if (!p64h_sysc_rpmi_trans_shmem_init(handle_ptr)) {
        return false;
    }
    return true;
}