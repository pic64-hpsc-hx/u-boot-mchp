/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */
/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

#include <rpmi/librpmi.h>
#include <rpmi/librpmi_mchp.h>
#include "p64h_sysc_math.h"

#undef DEBUG
#include <env/p64h_sysc_os_specific.h>

/* Private Defines ------------------------------------------------ */
#ifdef DEBUG
#define DPRINTF(msg...) rpmi_env_printf(msg)
#else
#define DPRINTF(msg...)
#endif

/* Private Structs and Enums -------------------------------------- */
/* Private Variables ---------------------------------------------- */
/* Prototypes ----------------------------------------------------- */
/* Private Function Definitions ----------------------------------- */
static inline rpmi_bool_t __rpmi_transport_is_empty(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    return trans->is_empty ? trans->is_empty(trans, qtype) : true;
}

static inline rpmi_bool_t __rpmi_transport_is_full(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    return trans->is_full ? trans->is_full(trans, qtype) : false;
}

/* Public Function Definitions ------------------------------------ */
rpmi_bool_t rpmi_transport_is_empty(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    rpmi_bool_t ret;

    if (!trans) {
        DPRINTF("%s: NULL transport pointer\n", __func__);
        return false;
    }

    if (qtype >= RPMI_QUEUE_MAX) {
        DPRINTF("%s: %s: invalid qtype %d\n", __func__, trans->name, qtype);
        return false;
    }

    rpmi_env_lock(trans->lock);
    ret = __rpmi_transport_is_empty(trans, qtype);
    rpmi_env_unlock(trans->lock);

    return ret;
}

/* Public Function Definitions ------------------------------------ */
rpmi_bool_t rpmi_transport_is_full(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    rpmi_bool_t ret;

    if (!trans) {
        DPRINTF("%s: NULL transport pointer\n", __func__);
        return true;
    }

    if (qtype >= RPMI_QUEUE_MAX) {
        DPRINTF("%s: %s: invalid qtype %d\n", __func__, trans->name, qtype);
        return true;
    }

    rpmi_env_lock(trans->lock);
    ret = __rpmi_transport_is_full(trans, qtype);
    rpmi_env_unlock(trans->lock);

    return ret;
}

enum rpmi_error rpmi_transport_enqueue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* msg)
{
    struct rpmi_message_header* mhdr;
    enum rpmi_error             rc;

    if (!trans || !msg) {
        DPRINTF("%s: NULL transport or message pointer\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }

    if (qtype >= RPMI_QUEUE_MAX) {
        DPRINTF("%s: %s: invalid qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_INVALID_PARAM;
    }

    if (!trans->is_p2a_channel && qtype >= RPMI_QUEUE_P2A_REQ) {
        DPRINTF("%s: %s: p2a channel not available, invalid qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_INVALID_PARAM;
    }

    if (!trans->enqueue) {
        DPRINTF("%s: %s: enqueue operation not supported for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_NOTSUPP;
    }

    /* Convert header fields to match transport endianness */
    mhdr                  = &msg->header;
    mhdr->servicegroup_id = rpmi_to_xe16(trans->is_be, mhdr->servicegroup_id);
    mhdr->datalen         = rpmi_to_xe16(trans->is_be, mhdr->datalen);
    mhdr->token           = rpmi_to_xe16(trans->is_be, mhdr->token);

    /* Enqueue the message */
    rpmi_env_lock(trans->lock);
    if (__rpmi_transport_is_full(trans, qtype)) {
        DPRINTF("%s: %s: qtype %d is full\n", __func__, trans->name, qtype);
        rpmi_env_unlock(trans->lock);
        return RPMI_ERR_IO;
    }

    rc = trans->enqueue(trans, qtype, msg);
    rpmi_env_unlock(trans->lock);

    /* Reverse the endian conversion of header fields */
    mhdr->servicegroup_id = rpmi_to_xe16(trans->is_be, mhdr->servicegroup_id);
    mhdr->datalen         = rpmi_to_xe16(trans->is_be, mhdr->datalen);
    mhdr->token           = rpmi_to_xe16(trans->is_be, mhdr->token);

    return rc;
}

enum rpmi_error rpmi_transport_dequeue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg)
{
    struct rpmi_message_header* mhdr;
    enum rpmi_error             rc;

    if (!trans || !out_msg) {
        DPRINTF("%s: NULL transport or message pointer\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }

    if (qtype >= RPMI_QUEUE_MAX) {
        DPRINTF("%s: %s: invalid qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_INVALID_PARAM;
    }

    if (!trans->is_p2a_channel && qtype >= RPMI_QUEUE_P2A_REQ) {
        DPRINTF("%s: %s: p2a channel not available, invalid qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_INVALID_PARAM;
    }

    if (!trans->dequeue) {
        DPRINTF("%s: %s: dequeue operation not supported for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_NOTSUPP;
    }

    rpmi_env_lock(trans->lock);

    /* Dequeue the message */
    if (__rpmi_transport_is_empty(trans, qtype)) {
        DPRINTF("%s: %s: qtype %d is empty\n", __func__, trans->name, qtype);
        rpmi_env_unlock(trans->lock);
        return RPMI_ERR_IO;
    }
    // UART to shmem
    rc = trans->dequeue(trans, qtype, out_msg);
    rpmi_env_unlock(trans->lock);

    /* Convert header fields to native endianness */
    if (!rc) {
        mhdr                  = &out_msg->header;
        mhdr->servicegroup_id = rpmi_to_xe16(trans->is_be, mhdr->servicegroup_id);
        mhdr->datalen         = rpmi_to_xe16(trans->is_be, mhdr->datalen);
        mhdr->token           = rpmi_to_xe16(trans->is_be, mhdr->token);
    }

    return rc;
}

bool p64h_sysc_rpmi_slot_size_validate(const rpmi_uint32_t slot_size, const rpmi_uint32_t align_require)
{
    if (0u == slot_size) {
        return false;
    }
    if (slot_size < RPMI_SLOT_SIZE_MIN) {
        return false;
    }
    if (ALIGN(slot_size, align_require) != slot_size) {
        return false;
    }
    return true;
}

bool p64h_sysc_rpmi_queue_sizes_validate(const p64h_sysc_rpmi_tr_cfg_t* tr_ptr, const struct rpmi_shmem* shmem_ptr)
{
    if (NULL == tr_ptr || NULL == shmem_ptr) {
        return false;
    }
    if (tr_ptr->p2a_queue_size > 0u) {
        if ((tr_ptr->a2p_queue_size & (tr_ptr->a2p_slot_size - 1u)) != 0u) {
            return false;
        }
        if ((tr_ptr->p2a_queue_size & (tr_ptr->p2a_slot_size - 1u)) != 0u) {
            return false;
        }
        if (tr_ptr->a2p_queue_size < LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SIZE(tr_ptr->a2p_slot_size)) {
            return false;
        }
        if (tr_ptr->p2a_queue_size < LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SIZE(tr_ptr->p2a_slot_size)) {
            return false;
        }
        if (rpmi_shmem_size(shmem_ptr) < (RPMI_QUEUE_MIN * (tr_ptr->a2p_queue_size + tr_ptr->p2a_queue_size))) {
            return false;
        }
    } else {
        if ((tr_ptr->a2p_queue_size & (tr_ptr->a2p_slot_size - 1u)) != 0u) {
            return false;
        }
        if (tr_ptr->a2p_queue_size < LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SIZE(tr_ptr->a2p_slot_size)) {
            return false;
        }
        if (rpmi_shmem_size(shmem_ptr) < (RPMI_QUEUE_MIN * (tr_ptr->a2p_queue_size))) {
            return false;
        }
    }
    return true;
}

bool p64h_sysc_rpmi_queues_init(struct rpmi_transport_common* common_ptr, const p64h_sysc_rpmi_tr_cfg_t* tr_ptr)
{
    struct rpmi_transport_shmem_queue* queue_ptr;
    if (NULL == common_ptr || NULL == tr_ptr) {
        return false;
    }
    for (uint8_t i = 0u; i < common_ptr->queue_count; i++) {
        queue_ptr             = &common_ptr->queues[i];
        queue_ptr->queue_type = i;
        queue_ptr->queue_size = 0u;
        if ((RPMI_QUEUE_A2P_REQ == i) || (RPMI_QUEUE_P2A_ACK == i)) {
            queue_ptr->queue_size = tr_ptr->a2p_queue_size;
            queue_ptr->data_slots = (tr_ptr->a2p_queue_size / tr_ptr->a2p_slot_size) - RPMI_SLOTS_RESERVED;
        } else if (tr_ptr->p2a_queue_size != 0u) {
            queue_ptr->queue_size = tr_ptr->p2a_queue_size;
            queue_ptr->data_slots = (tr_ptr->p2a_queue_size / tr_ptr->p2a_slot_size) - RPMI_SLOTS_RESERVED;
        }

        if (0u == i) {
            queue_ptr->queue_base = 0;
        } else {
            queue_ptr->queue_base  = common_ptr->queues[i - 1u].queue_base;
            queue_ptr->queue_base += common_ptr->queues[i - 1u].queue_size;
        }
    }
    return true;
}
