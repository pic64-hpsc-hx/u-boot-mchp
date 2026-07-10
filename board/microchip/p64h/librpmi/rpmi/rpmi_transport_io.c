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
/* CRC-32 (IEEE 802.3) lookup table, polynomial 0xEDB88320 */
static const uint32_t crc32_table[256]
    = { 0x00000000U, 0x77073096U, 0xEE0E612CU, 0x990951BAU, 0x076DC419U, 0x706AF48FU, 0xE963A535U, 0x9E6495A3U, 0x0EDB8832U, 0x79DCB8A4U, 0xE0D5E91EU,
        0x97D2D988U, 0x09B64C2BU, 0x7EB17CBDU, 0xE7B82D07U, 0x90BF1D91U, 0x1DB71064U, 0x6AB020F2U, 0xF3B97148U, 0x84BE41DEU, 0x1ADAD47DU, 0x6DDDE4EBU,
        0xF4D4B551U, 0x83D385C7U, 0x136C9856U, 0x646BA8C0U, 0xFD62F97AU, 0x8A65C9ECU, 0x14015C4FU, 0x63066CD9U, 0xFA0F3D63U, 0x8D080DF5U, 0x3B6E20C8U,
        0x4C69105EU, 0xD56041E4U, 0xA2677172U, 0x3C03E4D1U, 0x4B04D447U, 0xD20D85FDU, 0xA50AB56BU, 0x35B5A8FAU, 0x42B2986CU, 0xDBBBC9D6U, 0xACBCF940U,
        0x32D86CE3U, 0x45DF5C75U, 0xDCD60DCFU, 0xABD13D59U, 0x26D930ACU, 0x51DE003AU, 0xC8D75180U, 0xBFD06116U, 0x21B4F4B5U, 0x56B3C423U, 0xCFBA9599U,
        0xB8BDA50FU, 0x2802B89EU, 0x5F058808U, 0xC60CD9B2U, 0xB10BE924U, 0x2F6F7C87U, 0x58684C11U, 0xC1611DABU, 0xB6662D3DU, 0x76DC4190U, 0x01DB7106U,
        0x98D220BCU, 0xEFD5102AU, 0x71B18589U, 0x06B6B51FU, 0x9FBFE4A5U, 0xE8B8D433U, 0x7807C9A2U, 0x0F00F934U, 0x9609A88EU, 0xE10E9818U, 0x7F6A0DBBU,
        0x086D3D2DU, 0x91646C97U, 0xE6635C01U, 0x6B6B51F4U, 0x1C6C6162U, 0x856530D8U, 0xF262004EU, 0x6C0695EDU, 0x1B01A57BU, 0x8208F4C1U, 0xF50FC457U,
        0x65B0D9C6U, 0x12B7E950U, 0x8BBEB8EAU, 0xFCB9887CU, 0x62DD1DDFU, 0x15DA2D49U, 0x8CD37CF3U, 0xFBD44C65U, 0x4DB26158U, 0x3AB551CEU, 0xA3BC0074U,
        0xD4BB30E2U, 0x4ADFA541U, 0x3DD895D7U, 0xA4D1C46DU, 0xD3D6F4FBU, 0x4369E96AU, 0x346ED9FCU, 0xAD678846U, 0xDA60B8D0U, 0x44042D73U, 0x33031DE5U,
        0xAA0A4C5FU, 0xDD0D7CC9U, 0x5005713CU, 0x270241AAU, 0xBE0B1010U, 0xC90C2086U, 0x5768B525U, 0x206F85B3U, 0xB966D409U, 0xCE61E49FU, 0x5EDEF90EU,
        0x29D9C998U, 0xB0D09822U, 0xC7D7A8B4U, 0x59B33D17U, 0x2EB40D81U, 0xB7BD5C3BU, 0xC0BA6CADU, 0xEDB88320U, 0x9ABFB3B6U, 0x03B6E20CU, 0x74B1D29AU,
        0xEAD54739U, 0x9DD277AFU, 0x04DB2615U, 0x73DC1683U, 0xE3630B12U, 0x94643B84U, 0x0D6D6A3EU, 0x7A6A5AA8U, 0xE40ECF0BU, 0x9309FF9DU, 0x0A00AE27U,
        0x7D079EB1U, 0xF00F9344U, 0x8708A3D2U, 0x1E01F268U, 0x6906C2FEU, 0xF762575DU, 0x806567CBU, 0x196C3671U, 0x6E6B06E7U, 0xFED41B76U, 0x89D32BE0U,
        0x10DA7A5AU, 0x67DD4ACCU, 0xF9B9DF6FU, 0x8EBEEFF9U, 0x17B7BE43U, 0x60B08ED5U, 0xD6D6A3E8U, 0xA1D1937EU, 0x38D8C2C4U, 0x4FDFF252U, 0xD1BB67F1U,
        0xA6BC5767U, 0x3FB506DDU, 0x48B2364BU, 0xD80D2BDAU, 0xAF0A1B4CU, 0x36034AF6U, 0x41047A60U, 0xDF60EFC3U, 0xA867DF55U, 0x316E8EEFU, 0x4669BE79U,
        0xCB61B38CU, 0xBC66831AU, 0x256FD2A0U, 0x5268E236U, 0xCC0C7795U, 0xBB0B4703U, 0x220216B9U, 0x5505262FU, 0xC5BA3BBEU, 0xB2BD0B28U, 0x2BB45A92U,
        0x5CB36A04U, 0xC2D7FFA7U, 0xB5D0CF31U, 0x2CD99E8BU, 0x5BDEAE1DU, 0x9B64C2B0U, 0xEC63F226U, 0x756AA39CU, 0x026D930AU, 0x9C0906A9U, 0xEB0E363FU,
        0x72076785U, 0x05005713U, 0x95BF4A82U, 0xE2B87A14U, 0x7BB12BAEU, 0x0CB61B38U, 0x92D28E9BU, 0xE5D5BE0DU, 0x7CDCEFB7U, 0x0BDBDF21U, 0x86D3D2D4U,
        0xF1D4E242U, 0x68DDB3F8U, 0x1FDA836EU, 0x81BE16CDU, 0xF6B9265BU, 0x6FB077E1U, 0x18B74777U, 0x88085AE6U, 0xFF0F6A70U, 0x66063BCAU, 0x11010B5CU,
        0x8F659EFFU, 0xF862AE69U, 0x616BFFD3U, 0x166CCF45U, 0xA00AE278U, 0xD70DD2EEU, 0x4E048354U, 0x3903B3C2U, 0xA7672661U, 0xD06016F7U, 0x4969474DU,
        0x3E6E77DBU, 0xAED16A4AU, 0xD9D65ADCU, 0x40DF0B66U, 0x37D83BF0U, 0xA9BCAE53U, 0xDEBB9EC5U, 0x47B2CF7FU, 0x30B5FFE9U, 0xBDBDF21CU, 0xCABAC28AU,
        0x53B39330U, 0x24B4A3A6U, 0xBAD03605U, 0xCDD70693U, 0x54DE5729U, 0x23D967BFU, 0xB3667A2EU, 0xC4614AB8U, 0x5D681B02U, 0x2A6F2B94U, 0xB40BBE37U,
        0xC30C8EA1U, 0x5A05DF1BU, 0x2D02EF8DU };
/* Prototypes ----------------------------------------------------- */
/* Private Function Definitions ----------------------------------- */
#if 0
/**
 * @brief Compute CRC-32 (IEEE / ZIP), bitwise implementation.
 *
 * @param[in] data   Input buffer
 * @param[in] length Buffer length in bytes
 *
 * @return CRC-32 value
 */
static uint32_t crc32_bitwise(const uint8_t *data, size_t length)
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
#endif

static inline bool __is_xfer_error(enum rpmi_error rc)
{
    return ((RPMI_P64H_ERR_TIMEOUT_DATA_DROPPED == rc) || (RPMI_P64H_ERR_CHECKSUM_MISMATCH == rc) || (RPMI_P64H_ERR_HEADER_CORRUPT == rc));
}

/**
 * @brief Fast CRC-32 (IEEE) calculation.
 * @param[in] data Input buffer
 * @param[in] length  Buffer length in bytes
 * @return CRC-32 value
 */
static uint32_t crc32_fast(const uint8_t* data, size_t length)
{
    uint32_t       crc = 0xFFFFFFFF;
    const uint8_t* p   = data;

    while (length > 0) {
        crc = (crc >> 8) ^ crc32_table[(crc ^ *p++) & 0xFFu];
        length--;
    }

    return ~crc;
}

/* Public Function Definitions ------------------------------------ */
/**
 * @brief Calculates the CRC32 checksum of the given data.
 *
 * @param data   Pointer to the input data.
 * @param length Length of the input data.
 * @return       The calculated CRC32 checksum.
 */
uint32_t rpmi_crc32(const uint8_t* data, const size_t length)
{
    return crc32_fast(data, length);
}

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
    // if the message is larger than the slot size, return an error don't just truncate and return as if nothing was wrong.
    if (write_len > rpmi_transport_slot_size(trans, qtype) - sizeof(rpmi_uint32_t)) {
        return RPMI_ERR_BAD_RANGE;
    }

    rc = rpmi_io_write(io, msg, write_len);
    if (rc) {
        DPRINTF("%s: %s: failed to write message for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_FAILED;
    }

    // send checksum
    calculated_checksum = rpmi_crc32((const uint8_t*)msg, write_len);
    rc                  = rpmi_io_write(io, (uint8_t*)&calculated_checksum, sizeof(calculated_checksum));
    if (rc) {
        DPRINTF("%s: %s: failed to write message checksum 0x%08x for qtype %d\n", __func__, trans->name, calculated_checksum, qtype);
        return RPMI_ERR_FAILED;
    }
    return RPMI_SUCCESS;
}

enum rpmi_error __attribute__((weak)) io_dequeue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg)
{
    struct rpmi_transport_io* iotrans = trans->priv;
    struct rpmi_io*           io      = iotrans->io;
    enum rpmi_error           rc;
    uint32_t                  received_checksum;
    uint32_t                  calculated_checksum;
    uint32_t                  attempt_count = 0;

    do {
        bool valid_header = false;
        // read just the header first
        rc = rpmi_io_read(io, out_msg, sizeof(struct rpmi_message_header));
        if (RPMI_SUCCESS != rc) {
            DPRINTF("%s: %s: failed to read message for qtype %d\n", __func__, trans->name, qtype);
        }

        if (RPMI_SUCCESS == rc) {
            if (out_msg->header.datalen > rpmi_transport_slot_size(trans, qtype) - sizeof(struct rpmi_message_header)) {
                rc = RPMI_P64H_ERR_HEADER_CORRUPT;
            } else {
                valid_header = true;
                rc           = rpmi_io_read(io, out_msg->data, out_msg->header.datalen);
                if (RPMI_SUCCESS != rc) {
                    DPRINTF("%s: %s: failed to read message for qtype %d\n", __func__, trans->name, qtype);
                }
            }
        }

        if (RPMI_SUCCESS == rc) {
            // validate checksum
            rc = rpmi_io_read(io, &received_checksum, sizeof(rpmi_uint32_t));
            if (RPMI_SUCCESS != rc) {
                DPRINTF("%s: %s: failed to read message checksum for qtype %d\n", __func__, trans->name, qtype);
            } else {
                calculated_checksum = rpmi_crc32((const uint8_t*)out_msg, sizeof(struct rpmi_message_header) + out_msg->header.datalen);
                if (calculated_checksum != received_checksum) {
                    DPRINTF("%s: %s: checksum mismatch received 0x%08x != calculated 0x%08x\n", __func__, trans->name, received_checksum,
                            calculated_checksum);
                    rc = RPMI_P64H_ERR_CHECKSUM_MISMATCH;
                }
            }
        }

        if (__is_xfer_error(rc)) {
            // If we timed out getting host data, send back a response with DATA_DROPPED and try again
            if ((RPMI_QUEUE_A2P_REQ == qtype) && (attempt_count < P64H_RPMI_RETRY_COUNT)) {
                {
                    rpmi_resp_message_t resp_msg;
                    resp_msg.header.flags          = (uint8_t)RPMI_MSG_ACKNOWLDGEMENT;
                    resp_msg.header.datalen        = (uint32_t)sizeof(rpmi_resp_metadata_t);
                    resp_msg.resp_metadata.rpmi_rc = rc;
                    resp_msg.resp_metadata.p64h_rc = P64H_ERR_OK;
                    if (valid_header) {
                        resp_msg.header.service_id      = out_msg->header.service_id;
                        resp_msg.header.servicegroup_id = out_msg->header.servicegroup_id;
                        resp_msg.header.token           = out_msg->header.token;
                    } else {
                        // TODO: not sure what we want to send here
                        resp_msg.header.service_id      = 0U;
                        resp_msg.header.servicegroup_id = 0U;
                        resp_msg.header.token           = 0U;
                    }
                    rc = rpmi_transport_enqueue(trans, RPMI_QUEUE_P2A_ACK, (rpmi_message_t*)&resp_msg);
                    if (RPMI_SUCCESS == rc) {
                        rc = rpmi_io_flush_rx(io);
                    }
                    if (RPMI_SUCCESS != rc) {
                        break;
                    } else {
                        DPRINTF("Trying to dequeue rpmi request again, attempt #%u", attempt_count);
                    }
                }
            } else {
                enum rpmi_error flush_rc = rpmi_io_flush_rx(io);
                if (RPMI_SUCCESS != flush_rc) {
                    DPRINTF("%s: Failed to flush io after after error\n", __func__);
                }
                break;
            }
        } else {
            break;
        }
    } while (attempt_count++ < P64H_RPMI_RETRY_COUNT);

    return rc;
}

enum rpmi_error __attribute__((weak)) tcp_io_enqueue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, const struct rpmi_message* msg)
{
    struct rpmi_transport_io* iotrans = trans->priv;
    struct rpmi_io*           io      = iotrans->io;
    int                       rc;
    rpmi_message_tcp_req_t    req_header;

    if (NULL == msg) {
        return RPMI_ERR_INVALID_PARAM;
    }

    rpmi_req_schema_t* schema_ptr = (rpmi_req_schema_t*)msg;
    req_header.servicegroup_id    = rpmi_to_xe16(true, schema_ptr->header.servicegroup_id);
    req_header.service_id         = schema_ptr->header.service_id;
    req_header.flags              = 0u;
    req_header.id0                = rpmi_to_xe32(true, schema_ptr->req_metadata.id0);
    req_header.id1                = rpmi_to_xe32(true, schema_ptr->req_metadata.id1);
    req_header.id2                = rpmi_to_xe32(true, schema_ptr->req_metadata.id2);
    req_header.req_size           = rpmi_to_xe32(true, schema_ptr->req_metadata.req_size);
    req_header.resp_size          = rpmi_to_xe32(true, schema_ptr->req_metadata.resp_size);

    rc                            = rpmi_io_write(io, &req_header, sizeof(req_header));
    if (rc) {
        DPRINTF("%s: %s: failed to write message for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_FAILED;
    }
    if (schema_ptr->req_metadata.req_size > 0) {
        size_t metadata_len = schema_ptr->req_metadata.metadata_len;
        size_t payload_len  = schema_ptr->req_metadata.req_size;

        // Write metadata if present
        if (metadata_len > 0u && schema_ptr->metadata_ptr != NULL) {
            rc = rpmi_io_write(io, schema_ptr->metadata_ptr, metadata_len);
            if (rc) {
                DPRINTF("%s: %s: failed to write metadata for qtype %d\n", __func__, trans->name, qtype);
                return RPMI_ERR_FAILED;
            }
            payload_len = payload_len > metadata_len ? payload_len - metadata_len : 0u;
        }

        // Write data payload (metadata-relative or full request)
        if (payload_len > 0u && schema_ptr->data_ptr != NULL) {
            rc = rpmi_io_write(io, schema_ptr->data_ptr, payload_len);
            if (rc) {
                DPRINTF("%s: %s: failed to write data for qtype %d\n", __func__, trans->name, qtype);
                return RPMI_ERR_FAILED;
            }
        }
    }

    return RPMI_SUCCESS;
}

enum rpmi_error __attribute__((weak)) tcp_io_dequeue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg)
{
    struct rpmi_transport_io* iotrans = trans->priv;
    struct rpmi_io*           io      = iotrans->io;
    rpmi_uint32_t             payload_len;
    int                       rc;
    rpmi_message_tcp_resp_t   resp_header;

    // read just the header first
    rc = rpmi_io_read(io, &resp_header, sizeof(resp_header));
    if (rc) {
        DPRINTF("%s: %s: failed to read message for qtype %d\n", __func__, trans->name, qtype);
        return RPMI_ERR_FAILED;
    }

    rpmi_resp_schema_t* schema_ptr    = (rpmi_resp_schema_t*)out_msg;
    schema_ptr->resp_metadata.rpmi_rc = rpmi_to_xe32(true, resp_header.status);
    payload_len                       = rpmi_to_xe32(true, resp_header.resp_size);
    if (schema_ptr->resp_metadata.rpmi_rc) {
        DPRINTF("%s: %s: message indicates error, rpmi_rc = %d, resp_size = %u\n", __func__, trans->name, schema_ptr->resp_metadata.rpmi_rc,
                payload_len);
        return RPMI_ERR_FAILED;
    } else {
        schema_ptr->resp_metadata.resp_size = payload_len;
    }

    if (payload_len > 0) {
        size_t metadata_len = schema_ptr->resp_metadata.metadata_len;

        // Read metadata if present
        if (metadata_len > 0u && schema_ptr->metadata_ptr != NULL) {
            rc = rpmi_io_read(io, schema_ptr->metadata_ptr, metadata_len);
            if (rc) {
                DPRINTF("%s: %s: failed to read metadata for qtype %d\n", __func__, trans->name, qtype);
                return RPMI_ERR_FAILED;
            }
            payload_len = payload_len > metadata_len ? payload_len - metadata_len : 0u;
        }

        // Read data payload (metadata-relative or full payload)
        if (payload_len > 0u && schema_ptr->data_ptr != NULL) {
            rc = rpmi_io_read(io, schema_ptr->data_ptr, payload_len);
            if (rc) {
                DPRINTF("%s: %s: failed to read data for qtype %d\n", __func__, trans->name, qtype);
                return RPMI_ERR_FAILED;
            }
        }
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
    bool                           is_tcp = RPMI_RPMI_IO_PORT_TYPE_TCP == handle_ptr->io.port.type;
    const p64h_sysc_rpmi_tr_cfg_t* tr_ptr = &handle_ptr->ctxt.tr;
    struct rpmi_transport*         transport_ptr;
    transport_ptr                 = &handle_ptr->trans_io.trans_common.trans;
    transport_ptr->name           = "P64H_SYSC_IO_TR_REMOTE";
    transport_ptr->is_be          = false;
    transport_ptr->a2p_slot_size  = tr_ptr->a2p_slot_size;
    transport_ptr->p2a_slot_size  = tr_ptr->p2a_slot_size;
    transport_ptr->is_p2a_channel = (tr_ptr->p2a_queue_size > 0u);
    transport_ptr->is_empty       = io_is_empty;
    transport_ptr->is_full        = io_is_full;
    transport_ptr->enqueue        = is_tcp ? tcp_io_enqueue : io_enqueue;
    transport_ptr->dequeue        = is_tcp ? tcp_io_dequeue : io_dequeue;
    transport_ptr->lock           = &handle_ptr->lock;
    transport_ptr->priv           = &handle_ptr->trans_io;
    return true;
}
