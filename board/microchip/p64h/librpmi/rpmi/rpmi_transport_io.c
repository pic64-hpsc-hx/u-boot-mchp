/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */
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
/* Prototypes ----------------------------------------------------- */
/* Private Function Definitions ----------------------------------- */

/**
 * @brief Calculates the CRC32 checksum of the given data.
 *
 * @param data   Pointer to the input data.
 * @param length Length of the input data.
 * @return       The calculated CRC32 checksum.
 */
static uint32_t rpmi_crc32(const uint8_t* data, const size_t length)
{
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
    }
    return ~crc;
}

/* Public Function Definitions ------------------------------------ */
rpmi_bool_t __attribute__((weak)) io_is_empty(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    (void)qtype;
    struct rpmi_transport_io* iotrans = trans->priv;
    struct rpmi_io*           io      = iotrans->io;

    return rpmi_io_is_empty(io);
}

rpmi_bool_t __attribute__((weak)) io_is_full(struct rpmi_transport* trans, enum rpmi_queue_type qtype)
{
    (void)trans;
    (void)qtype;
    return false;
}

enum rpmi_error __attribute__((weak)) io_enqueue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, const struct rpmi_message* msg)
{
    struct rpmi_transport_io* iotrans = trans->priv;
    struct rpmi_io*           io      = iotrans->io;
    uint32_t                  write_len;
    int                       rc;
    uint32_t                  calculated_checksum;

    if (NULL == msg) {
        return RPMI_ERR_INVALID_PARAM;
    }

    // We should only be writing the actual data of the message not slot_size bytes as the input may be less than a full slot_size and
    // in this case we will either write 'garbage' or in a worst case scenario could trigger a segfault if the read from the msg pointer
    // spills out of the segment boundary.
    write_len = msg->header.datalen + sizeof(struct rpmi_message_header);
    // if the message is larger than the slot_size, return an error don't just truncate and return as if nothing was wrong.
    if (write_len > trans->slot_size - sizeof(rpmi_uint32_t)) {
        return RPMI_ERR_BAD_RANGE;
    }

    rc = rpmi_io_write(io, msg, write_len);
    if (rc) {
        DPRINTF("%s: %s: failed to write message at tailidx %d for qtype %d\n", __func__, trans->name, tailidx, qtype);
        return RPMI_ERR_FAILED;
    }

    // send checksum
    calculated_checksum = rpmi_crc32((const uint8_t*)msg, write_len);
    rc                  = rpmi_io_write(io, (uint8_t*)&calculated_checksum, sizeof(calculated_checksum));
    if (rc) {
        DPRINTF("%s: %s: failed to write message checksum 0x%08x\n", __func__, trans->name, calculated_checksum);
        return RPMI_ERR_FAILED;
    }
    return RPMI_SUCCESS;
}

enum rpmi_error __attribute__((weak)) io_dequeue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg)
{
    struct rpmi_transport_io* iotrans = trans->priv;
    struct rpmi_io*           io      = iotrans->io;
    rpmi_uint32_t             payload_len;
    int                       rc;
    uint32_t                  received_checksum;
    uint32_t                  calculated_checksum;

    // read just the header first
    rc = rpmi_io_read(io, out_msg, sizeof(struct rpmi_message_header));
    if (rc) {
        DPRINTF("%s: %s: failed to read message at headidx %d for qtype %d\n", __func__, trans->name, headidx, qtype);
        return RPMI_ERR_FAILED;
    }

    // Capture the payload size from the header and read only the datalen amount of data from the slot incase the storage passed is not the full
    // slot_size. If the datalen indicates more than the slot_size, which should only be possible if memory is corrupted, then truncate and return
    // only slot_size bytes into out_msg. Throwing an error here doesn't help much as that will not remove the problematic message from the queue and
    // there is no chance for recovery. if the caller detects truncation, they can flush the queue which at least has a chance to recover from such a
    // case.
    payload_len = MIN(out_msg->header.datalen, trans->slot_size - sizeof(struct rpmi_message_header));

    rc          = rpmi_io_read(io, out_msg->data, payload_len);
    if (rc) {
        DPRINTF("%s: %s: failed to read message at headidx %d for qtype %d\n", __func__, trans->name, headidx, qtype);
        return RPMI_ERR_FAILED;
    }
    // validate checksum
    rc = rpmi_io_read(io, &received_checksum, sizeof(rpmi_uint32_t));
    if (rc) {
        DPRINTF("%s: %s: failed to read message checksum at headidx %d for qtype %d\n", __func__, trans->name, headidx, qtype);
        return RPMI_ERR_FAILED;
    }
    calculated_checksum = rpmi_crc32((const uint8_t*)out_msg, sizeof(struct rpmi_message_header) + payload_len);
    if (calculated_checksum != received_checksum) {
        DPRINTF("%s: %s: checksum mismatch received 0x%08x != calculated 0x%08x\n", __func__, trans->name, received_checksum, calculated_checksum);
        return RPMI_P64H_ERR_CHECKSUM_MISMATCH;
    }
    return RPMI_SUCCESS;
}

bool p64h_sysc_rpmi_trans_io_init(p64h_sysc_handle_t* handle_ptr)
{
    if (NULL == handle_ptr) {
        return false;
    }
    if (!osal_init_static_lock(&handle_ptr->lock)) {
        return false;
    }
    const p64h_sysc_rpmi_tr_cfg_t* tr_ptr = &handle_ptr->ctxt.tr;
    struct rpmi_transport*         transport_ptr;
    transport_ptr                 = &handle_ptr->trans_io.trans_common.trans;
    transport_ptr->name           = "P64H_SYSC_IO_TR_REMOTE";
    transport_ptr->is_be          = false;
    transport_ptr->slot_size      = tr_ptr->slot_size;
    transport_ptr->is_p2a_channel = (tr_ptr->p2a_queue_size > 0u);
    transport_ptr->is_empty       = io_is_empty;
    transport_ptr->is_full        = io_is_full;
    transport_ptr->enqueue        = io_enqueue;
    transport_ptr->dequeue        = io_dequeue;
    transport_ptr->lock           = &handle_ptr->lock;
    transport_ptr->priv           = &handle_ptr->trans_io;
    return true;
}
