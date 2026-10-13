/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  rpmi_sysc.c
 * @brief RPMI SysC API implementation
 * @addtogroup RPMI_SYSC_API
 * @ingroup rpmi_sysc
 * @{
 */
#include <env/p64h_sysc_os_specific.h>

#include <generated/p64h_sysc_rpmi_defs.h>
#include <rpmi/librpmi.h>
#include <rpmi/librpmi_sysc.h>

/* Private Defines ------------------------------------------------ */
/**
 * @brief Transmission timeout duration.
 *
 * This macro defines the timeout duration for transmission operations in microseconds.
 *
 * @note Value set to 1 second
 */
#define TX_TIMEOUT    (uint32_t)(10000000u)


#define FW_UPGRADE_APPLY_RX_RETRY_COUNT (300u) //< timeout for fw upgrade apply response

#define LONG_LO_MASK  (0x00000000FFFFFFFFULL) ///< Mask for LSB of 64bit value
#define LONG_HI_MASK  (0xFFFFFFFF00000000ULL) ///< Mask for MSB of 64bit value
#define LONG_HI_SHIFT (32UL)                  ///< Shift for MSB of 64bit value

/// Defined optnone to be portable across compilers.
#if defined(__clang__)
#define OPTNONE __attribute__((optnone))
#elif defined(__GNUC__)
#define OPTNONE __attribute__((optimize("O0")))
#else
#define OPTNONE
#endif

/* Private Variables ---------------------------------------------- */
uint8_t req_buf[RPMI_MAX_SLOT_SIZE];  ///< RPMI request buffer
uint8_t resp_buf[RPMI_MAX_SLOT_SIZE]; ///< RPMI response buffer

/* Prototypes ----------------------------------------------------- */
static rpmi_req_message_t* rpmi_common_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                const uint32_t id0, const uint32_t id1, const uint32_t id2, const size_t data_len);
static rpmi_req_message_t* rpmi_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                         const uint32_t id1, const uint32_t id2, const void* data_ptr, const size_t data_size);
static rpmi_data_pull_req_message_t* rpmi_data_pull_req_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id,
                                                                 const uint8_t svc_id, const uint32_t id0, const uint32_t id1, const uint32_t id2,
                                                                 const void* req_ptr, size_t req_size, const size_t remaining_buf_size,
                                                                 const size_t data_offset, bool shmem_xfer, void* shmem_ptr);
static rpmi_data_push_req_message_t* rpmi_data_push_req_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id,
                                                                 const uint8_t svc_id, const uint32_t id0, const uint32_t id1, const uint32_t id2,
                                                                 const void* req_ptr, size_t req_size, const void* data_ptr, const size_t data_size,
                                                                 const size_t data_offset, const size_t remaining, bool shmem_xfer);
static p64h_err_t                    rpmi_shmem_send(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr);
static p64h_err_t                    rpmi_remote_send(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr);
static rpmi_error_t                  rpmi_shmem_recv(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr);
static rpmi_error_t                  rpmi_remote_recv(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr);
static inline p64h_err_t rpmi_check_ids(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                        const uint32_t id1, const uint32_t id2);
static inline p64h_err_t rpmi_req_state_check(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id);
static inline p64h_err_t rpmi_req_info_clean(const p64h_sysc_handle_t* handle_ptr);
static inline p64h_err_t rpmi_req_resp_internal(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                const uint32_t id0, const uint32_t id1, const uint32_t id2, const void* req_data_ptr,
                                                const size_t req_size, void* resp_data_ptr, const size_t resp_size);

/* Private Function Definitions ----------------------------------- */

/**
 * @brief Converts an RPMI error code to a P64H system controller error code.
 *
 * This function takes an error code from the RPMI (Remote Power Management Interface)
 * and maps it to the corresponding error code used by the P64H system controller.
 *
 * @param rpmi_err The error code from the RPMI.
 * @return The corresponding P64H system controller error code.
 */
static inline p64h_err_t rpmi_to_p64h_sysc_err(int rpmi_err)
{
    switch (rpmi_err) {
        case RPMI_SUCCESS:
            return P64H_ERR_OK;
        case RPMI_ERR_INVALID_PARAM:
            return P64H_ERR_LIB_API_INVALID_PARAM;
        case RPMI_ERR_BAD_RANGE:
            return P64H_ERR_LIB_API_BAD_RANGE;
        case RPMI_ERR_INVALID_STATE:
            return P64H_ERR_LIB_API_INVALID_STATE;
        case RPMI_ERR_DENIED:
            return P64H_ERR_LIB_API_DENIED;
        case RPMI_ERR_INVALID_ADDR:
            return P64H_ERR_LIB_API_INVALID_PARAM;
        case RPMI_ERR_HW_FAULT:
            return P64H_ERR_LIB_API_HW_FAULT;
        case RPMI_ERR_ALREADY:
            return P64H_ERR_LIB_API_ALREADY;
        case RPMI_ERR_BUSY:
            return P64H_ERR_LIB_API_BUSY;
        case RPMI_ERR_TIMEOUT:
            return P64H_ERR_LIB_API_TIMEOUT;
        case RPMI_ERR_IO:
            return P64H_ERR_LIB_API_IO;
        case RPMI_ERR_FAILED:
            return P64H_ERR_LIB_API_FAILED;
        case RPMI_ERR_NOTSUPP:
            return P64H_ERR_LIB_API_NOT_SUPPORTED;
        case RPMI_ERR_NO_DATA:
            return P64H_ERR_LIB_API_NO_DATA;
        case RPMI_ERR_EXTENSION:
            return P64H_ERR_LIB_API_EXTENSION;
        case RPMI_P64H_ERR_CHECKSUM_MISMATCH:
            return P64H_ERR_LIB_API_CHECKSUM_MISMATCH;
        case RPMI_P64H_ERR_HEADER_CORRUPT:
            return P64H_ERR_LIB_API_HEADER_CORRUPT;
        case RPMI_P64H_ERR_TIMEOUT_DATA_DROPPED:
            return P64H_ERR_LIB_API_TIMEOUT_DATA_DROPPED;
        default:
            return P64H_ERR_LIB_API_NOT_SUPPORTED;
    }
}

/**
 * Retrieve lower 32 bits of 64 bit long value
 * @param[in] value The 64 bit word
 *
 * @return Lower 32 bits of input value
 */
static inline uint32_t __long_lo(uint64_t value)
{
    return (uint32_t)(value & LONG_LO_MASK);
}

/**
 * Retrieve higher 32 bits of 64 bit long value
 * @param[in] value The 64 bit word
 *
 * @return higher 32 bits of input value
 */
static inline uint32_t __long_hi(uint64_t value)
{
    return (uint32_t)((value >> LONG_HI_SHIFT) & LONG_LO_MASK);
}

/**
 * Reconstruct 64bit long from MSB and LSB
 * @param[in] msb MSB of value
 * @param[in] lsb LSB of value
 *
 * @return Reconstructed 64 bit long value
 */
static inline uint64_t __long_construct(uint32_t msb, uint32_t lsb)
{
    return (uint64_t)((((uint64_t)msb << LONG_HI_SHIFT) & LONG_HI_MASK) | (((uint64_t)lsb) & LONG_LO_MASK));
}

static inline bool __is_xfer_error(p64h_err_t rc)
{
    return ((P64H_ERR_LIB_API_TIMEOUT_DATA_DROPPED == rc) || (P64H_ERR_LIB_API_CHECKSUM_MISMATCH == rc) || (P64H_ERR_LIB_API_HEADER_CORRUPT == rc));
}

/**
 * @brief Packing function for fields that are common to all RPMI request messages.
 *
 * This function packs data common to all RPMI request messages returning a pointer to the packed message.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] data_len Length of data being packed
 *
 * @return Pointer to the packed RPMI request message
 */
static rpmi_req_message_t* rpmi_common_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                const uint32_t id0, const uint32_t id1, const uint32_t id2, const size_t data_len)
{

    rpmi_req_message_t* msg_ptr;
    msg_ptr                         = (rpmi_req_message_t*)req_buf;
    msg_ptr->header.servicegroup_id = svc_grp_id;
    msg_ptr->header.service_id      = svc_id;
    msg_ptr->header.flags           = 0x0u;
    msg_ptr->header.datalen         = (rpmi_uint16_t)data_len;
    msg_ptr->header.token           = 0x0u;
    msg_ptr->req_metadata.id0       = id0;
    msg_ptr->req_metadata.id1       = id1;
    msg_ptr->req_metadata.id2       = id2;

    return msg_ptr;
}

/**
 * @brief Packing function for outgoing RPMI messages
 *
 * This function packs outgoing RPMI messages returning a pointer to the packed message.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] data_ptr Pointer for data to be put in payload of RPMI message
 * @param[in] data_size Length of data being packed
 *
 * @return Pointer to the packed RPMI request message
 */
static rpmi_req_message_t* rpmi_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                         const uint32_t id1, const uint32_t id2, const void* data_ptr, const size_t data_size)
{

    size_t              msg_total_size;
    size_t              data_len = sizeof(rpmi_req_metadata_t) + data_size;
    rpmi_req_message_t* msg_ptr;
    msg_total_size = sizeof(rpmi_message_header_t) + data_len;
    if (msg_total_size > sizeof(req_buf)) {
        return NULL;
    }
    msg_ptr = rpmi_common_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, data_len);
    if (!msg_ptr) {
        return NULL;
    }
    if ((NULL != data_ptr) && (data_size > 0u)) {
        memcpy(&msg_ptr->data, data_ptr, data_size);
    }
    return msg_ptr;
}

/**
 * @brief Packing function for log request messages.
 *
 * This function packs outgoing RPMI messages with an incoming log.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] req_start_off Requested start offset for data entries in log
 * @param[in] max_num_entries Maximum number of entries to return for transaction
 *
 * @return Pointer to the packed RPMI Response With Data request message
 */
static rpmi_log_req_message_t* rpmi_log_req_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                     const uint32_t id0, const uint32_t id1, const uint32_t id2, uint64_t req_start_off,
                                                     uint32_t max_num_entries)
{

    size_t                  msg_total_size;
    size_t                  data_len = sizeof(rpmi_log_req_metadata_t);
    rpmi_log_req_message_t* msg_ptr;
    msg_total_size = sizeof(rpmi_log_req_message_t) + data_len;
    if (msg_total_size > sizeof(req_buf)) {
        return NULL;
    }
    msg_ptr = (rpmi_log_req_message_t*)rpmi_common_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, data_len);
    if (!msg_ptr) {
        return NULL;
    }
    msg_ptr->log_metadata.req_start_off_lo = __long_lo(req_start_off);
    msg_ptr->log_metadata.req_start_off_hi = __long_hi(req_start_off);
    msg_ptr->log_metadata.max_num_entries  = max_num_entries;

    return msg_ptr;
}

/**
 * @brief Packing function for request messages with an incoming data buffer.
 *
 * This function packs outgoing RPMI messages with an incoming data buffer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] req_ptr Pointer to requested data buffer
 * @param[in] req_size Size of requested data buffer
 * @param[in] remaining_buf_size Number of remaining buffer entries
 * @param[in] data_offset Offset for current fragment of data
 * @param[in] shmem_xfer false: the data will be transferred thru RPMI channel
                         true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 * @param[in] shmem_ptr Pointer to shmem buffer for response data (only used if shmem_xfer is true)
 *
 * @return Pointer to the packed RPMI Response With Data request message
 */
static rpmi_data_pull_req_message_t* rpmi_data_pull_req_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id,
                                                                 const uint8_t svc_id, const uint32_t id0, const uint32_t id1, const uint32_t id2,
                                                                 const void* req_ptr, size_t req_size, const size_t remaining_buf_size,
                                                                 const size_t data_offset, bool shmem_xfer, void* shmem_ptr)
{
    size_t msg_total_size;
    size_t data_len;
    if (shmem_xfer) {
        data_len = sizeof(rpmi_data_pull_req_metadata_t) + req_size + sizeof(uintptr_t);
    } else {
        data_len = sizeof(rpmi_data_pull_req_metadata_t) + req_size;
    }

    rpmi_data_pull_req_message_t* msg_ptr;
    msg_total_size = sizeof(rpmi_data_pull_req_message_t) + req_size;
    if (msg_total_size > sizeof(req_buf)) {
        return NULL;
    }
    msg_ptr = (rpmi_data_pull_req_message_t*)rpmi_common_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, data_len);
    if (!msg_ptr) {
        return NULL;
    }
    msg_ptr->metadata.offset     = (rpmi_uint32_t)data_offset;
    msg_ptr->metadata.remaining  = remaining_buf_size;
    msg_ptr->metadata.shmem_xfer = shmem_xfer;
    if ((NULL != req_ptr) && (req_size > 0u)) {
        memcpy(&msg_ptr->data, req_ptr, req_size);
    }

    if (shmem_xfer) {
        if (NULL == shmem_ptr) {
            return NULL;
        }
        *(uintptr_t*)((uint64_t)(msg_ptr->data) + req_size) = (uintptr_t)shmem_ptr;
    }

    return msg_ptr;
}

/**
 * @brief Packing function for request messages with an outgoing data buffer.
 *
 * This function packs outgoing RPMI messages with an outgoing data buffer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] req_ptr Pointer to requested data buffer
 * @param[in] req_size Size of requested data buffer
 * @param[in] data_ptr Pointer to data in payload of RPMI message
 * @param[in] data_size Size of data in payload of RPMI message
 * @param[in] data_offset Offset for current fragment of data
 * @param[in] remaining Number of remaining fragments
 * @param[in] shmem_xfer false: the data will be transferred thru RPMI channel
                         true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 *
 * @return Pointer to the packed RPMI Response With Data request message
 */
static rpmi_data_push_req_message_t* rpmi_data_push_req_msg_pack(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id,
                                                                 const uint8_t svc_id, const uint32_t id0, const uint32_t id1, const uint32_t id2,
                                                                 const void* req_ptr, size_t req_size, const void* data_ptr, const size_t data_size,
                                                                 const size_t data_offset, const size_t remaining, bool shmem_xfer)
{
    size_t msg_total_size;
    size_t data_len;
    if (shmem_xfer) {
        data_len       = sizeof(rpmi_data_push_req_metadata_t) + req_size + sizeof(uintptr_t);
        msg_total_size = sizeof(rpmi_data_push_req_message_t) + req_size + sizeof(uintptr_t);
    } else {
        data_len       = sizeof(rpmi_data_push_req_metadata_t) + req_size + data_size;
        msg_total_size = sizeof(rpmi_data_push_req_message_t) + req_size + data_size;
    }

    rpmi_data_push_req_message_t* msg_ptr;
    if (msg_total_size > sizeof(req_buf)) {
        printf("handle_ptr->trans_io.trans_common.trans.a2p_slot_size %zu p2a_slot_size %zu", handle_ptr->trans_io.trans_common.trans.a2p_slot_size,
               handle_ptr->trans_io.trans_common.trans.p2a_slot_size);
        printf("trying to send %zu bytes in buffer of size %zu\n", msg_total_size, sizeof(req_buf));
        return NULL;
    }
    msg_ptr = (rpmi_data_push_req_message_t*)rpmi_common_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, data_len);
    if (!msg_ptr) {
        return NULL;
    }
    msg_ptr->metadata.offset     = (rpmi_uint32_t)data_offset;
    msg_ptr->metadata.sent       = (rpmi_uint32_t)data_size;
    msg_ptr->metadata.remaining  = (rpmi_uint32_t)remaining;
    msg_ptr->metadata.shmem_xfer = shmem_xfer;
    if ((NULL != req_ptr) && (req_size > 0u)) {
        memcpy(msg_ptr->data, req_ptr, req_size);
    }
    if (shmem_xfer) {
        *(uintptr_t*)((uintptr_t)(msg_ptr->data) + req_size) = (uintptr_t)data_ptr;
    } else {
        if ((NULL != data_ptr) && (data_size > 0u)) {
            memcpy((void*)((uint64_t)(msg_ptr->data) + req_size), data_ptr, data_size);
        }
    }

    return msg_ptr;
}

/**
 * @brief Function for sending an RPMI message across a shared memory region.
 *
 * This function sends an RPMI message across a shared memory region.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] msg_ptr Pointer to RPMI message to send across shared memory
 *
 * @return p64h_err_t mapped from rpmi_error. P64H_ERR_OK on success, error otherwise
 */
static p64h_err_t rpmi_shmem_send(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr)
{
    enum rpmi_error rpmi_err;
    if (NULL == msg_ptr) {
        printf("%s: %u\n", __FILE__, __LINE__);
        return P64H_ERR_LIB_API_NULL_POINTER;
    }
    if (false == handle_ptr->init) {
        return P64H_ERR_LIB_API_RPMI_CLIENT_NOT_INITIALIZED;
    }
    rpmi_err = rpmi_transport_enqueue((struct rpmi_transport*)&handle_ptr->trans_shmem.trans_common.trans, RPMI_QUEUE_A2P_REQ, msg_ptr);
    if (RPMI_SUCCESS == rpmi_err) {
        if (handle_ptr->ctxt.a2p_queue_int_mode == P64H_SYSC_RPMI_Q_INT_MODE_REQ_ONLY
            || handle_ptr->ctxt.a2p_queue_int_mode == P64H_SYSC_RPMI_Q_INT_MODE_BOTH) {
            p64h_ipc_msg_buf_t ipc_msg;
            ipc_msg.buf[0] = handle_ptr->ctxt.cid;
            ipc_msg.buf[1] = RPMI_QUEUE_A2P_REQ;
            if (handle_ptr->ipc_ops.ipc_msg_send) {
                int ret = handle_ptr->ipc_ops.ipc_msg_send((const uint32_t)handle_ptr->ctxt.ipc_channel, ipc_msg.buf, 2);
                if (0 != ret) {
                    rpmi_err = RPMI_ERR_FAILED;
                }
            } else {
                rpmi_err = RPMI_ERR_FAILED;
            }
        }
    }
    return rpmi_to_p64h_sysc_err(rpmi_err);
}

/**
 * @brief Function for receiving an RPMI message across a shared memory region.
 *
 * This function receives an RPMI message across a shared memory region.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] msg_ptr Pointer to read RPMI message into.
 *
 * @return rpmi_error_t RPMI_SUCCESS on success, error otherwise
 */
rpmi_error_t rpmi_shmem_recv(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr)
{
    rpmi_error_t rpmi_err = RPMI_SUCCESS;
    if (false == handle_ptr->init) {
        return RPMI_ERR_FAILED;
    } else {
        bool p2a_resp_int_enable = (handle_ptr->ctxt.p2a_queue_int_mode == P64H_SYSC_RPMI_Q_INT_MODE_BOTH);
        if (p2a_resp_int_enable) {
            p64h_ipc_msg_buf_t ipc_msg   = { 0 };
            uint32_t           recv_size = 0;
            // check if a received IPC message
            if (handle_ptr->ipc_ops.ipc_msg_get) {
                int ret = handle_ptr->ipc_ops.ipc_msg_get((const uint32_t)handle_ptr->ctxt.ipc_channel, ipc_msg.buf, &recv_size);
                if (0 == ret) {
                    if (0 < recv_size) {
                        rpmi_err = rpmi_transport_dequeue((struct rpmi_transport*)&handle_ptr->trans_shmem.trans_common.trans, RPMI_QUEUE_P2A_ACK,
                                                          msg_ptr);
                    } else if (0 == recv_size) {
                        rpmi_err = RPMI_ERR_IO;
                    }
                } else {
                    rpmi_err = RPMI_ERR_FAILED;
                }
            } else {
                rpmi_err = RPMI_ERR_FAILED;
            }
        } else {
            rpmi_err = rpmi_transport_dequeue((struct rpmi_transport*)&handle_ptr->trans_shmem.trans_common.trans, RPMI_QUEUE_P2A_ACK, msg_ptr);
        }
    }
    return rpmi_err;
}

/**
 * @brief Function for sending an RPMI message to a remote host.
 *
 * This function sends an RPMI message to a remote host
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] msg_ptr Pointer to RPMI message to send to remote host.
 *
 * @return p64h_err_t mapped from rpmi_error. P64H_ERR_OK on success, error otherwise
 */
static p64h_err_t rpmi_remote_send(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr)
{
    enum rpmi_error rpmi_err;
    if (NULL == msg_ptr) {
        printf("%s: %u\n", __FILE__, __LINE__);
        return P64H_ERR_LIB_API_NULL_POINTER;
    }
    if (false == handle_ptr->init) {
        return P64H_ERR_LIB_API_RPMI_CLIENT_NOT_INITIALIZED;
    }
    rpmi_err = rpmi_transport_enqueue((struct rpmi_transport*)&handle_ptr->trans_io.trans_common.trans, RPMI_QUEUE_A2P_REQ, msg_ptr);
    return rpmi_to_p64h_sysc_err(rpmi_err);
}

/**
 * @brief Function for receiving an RPMI message from a remote host.
 *
 * This function receives an RPMI message from a remote host.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] msg_ptr Pointer to read RPMI message into.
 *
 * @return rpmi_error_t RPMI_SUCCESS on success, error otherwise
 */
rpmi_error_t rpmi_remote_recv(const p64h_sysc_handle_t* handle_ptr, rpmi_message_t* msg_ptr)
{
    rpmi_error_t rpmi_err = RPMI_SUCCESS;
    if (false == handle_ptr->init) {
        return RPMI_ERR_FAILED;
    } else {
        rpmi_err = rpmi_transport_dequeue((struct rpmi_transport*)&handle_ptr->trans_io.trans_common.trans, RPMI_QUEUE_P2A_ACK, msg_ptr);
    }

    return rpmi_err;
}

/**
 * @brief General function for sending an RPMI message.
 *
 * This function sends an RPMI message based on the RPMI context ID.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] msg_ptr Pointer to RPMI message to send.
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_req_internal(const p64h_sysc_handle_t* handle_ptr, const rpmi_req_message_t* msg_ptr)
{
    p64h_err_t rc  = P64H_ERR_OK;
    uint32_t   itr = 0u;

    if (NULL == msg_ptr) {
        printf("%s: %u\n", __FILE__, __LINE__);
        return P64H_ERR_LIB_API_NULL_POINTER;
    }

    // send request
    for (itr = 0u; itr < TX_TIMEOUT; itr++) {
        if (P64H_SYSC_RPMI_REMOTE(handle_ptr)) {
            rc = rpmi_remote_send(handle_ptr, (rpmi_message_t*)msg_ptr);
        } else {
            rc = rpmi_shmem_send(handle_ptr, (rpmi_message_t*)msg_ptr);
        }

        if (rc == P64H_ERR_OK) {
            break;
        }
        // sleep(1);
    }
    if (itr >= TX_TIMEOUT) {
        return P64H_ERR_LIB_API_TIMEOUT;
    }
    return rc;
}

/**
 * @brief General function for receiving an RPMI message.
 *
 * This function receives a response from an RPMI message based on the RPMI context ID.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] polling_supported true: support polling mode; false: not support
 * @param[out] rpmi_resp_msg Pointer to read RPMI message into.
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_resp_internal(const p64h_sysc_handle_t* handle_ptr, bool polling_supported, rpmi_resp_message_t* rpmi_resp_msg)
{
    rpmi_error_t rpmi_err = RPMI_SUCCESS;
    p64h_err_t   rc       = P64H_ERR_OK;
    uint32_t     itr      = 0u;
    uint32_t     time_out = (polling_supported && handle_ptr->ctxt.req_posted) ? 1u : TX_TIMEOUT;

    for (itr = 0u; itr < time_out; itr++) {
        if (P64H_SYSC_RPMI_REMOTE(handle_ptr)) {
            rpmi_err = rpmi_remote_recv(handle_ptr, (rpmi_message_t*)rpmi_resp_msg);
        } else {
            rpmi_err = rpmi_shmem_recv(handle_ptr, (rpmi_message_t*)rpmi_resp_msg);
        }
        rc = rpmi_to_p64h_sysc_err(rpmi_err);
        if (rc == P64H_ERR_OK) {
            break;
        }
        if (rc != P64H_ERR_LIB_API_IO) {
            return rc;
        }
        // sleep(1); // Sleep has different behavior on different targeted OS/platform
    }

    if (itr >= time_out) {
        return P64H_ERR_LIB_API_TIMEOUT;
    }

    rpmi_error_t resp_rpmi_err = (rpmi_error_t)rpmi_resp_msg->resp_metadata.rpmi_rc;
    if (resp_rpmi_err != RPMI_SUCCESS) {
        rc = rpmi_to_p64h_sysc_err(resp_rpmi_err);
    } else {
        rc = (p64h_err_t)rpmi_resp_msg->resp_metadata.p64h_rc;
    }

    return rc;
}

/**
 * @brief Function for sending RPMI messages using an outgoing data buffer as payloads.
 *
 * This function sends and receives a response from an RPMI message carrying a fragment of an output buffer.
 * Once the outgoing data buffer is empty, it stops transmitting RPMI messages.
 *
 * @note An ACK is expected and checked for each message sent.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] req_data_ptr Pointer to a requested data payload
 * @param[in] req_size Size of a request data payload
 * @param[in] buf_ptr Pointer to output buffer
 * @param[in] entry_size Size of entry in output buffer
 * @param[in] buf_size Size of output buffer
 * @param[in] shmem_xfer false: the data will be transferred thru RPMI channel
                         true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_req_with_data_internal(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                     const uint32_t id0, const uint32_t id1, const uint32_t id2, const void* req_data_ptr,
                                                     const size_t req_size, const void* buf_ptr, size_t entry_size, size_t buf_size, bool shmem_xfer)
{
    p64h_err_t rc                = P64H_ERR_OK;
    size_t     tot_bytes_to_send = (buf_size * entry_size);

    if (RPMI_RPMI_IO_PORT_TYPE_TCP == handle_ptr->io.port.type) {
        return P64H_ERR_LIB_API_NOT_YET_IMPLEMENTED;
    } else {
        rpmi_req_message_t*  req_msg_ptr     = NULL;
        rpmi_resp_message_t* resp_msg_ptr    = NULL;
        bool                 tx_complete     = false;
        size_t               curr_bytes_sent = 0UL;
        size_t               max_data_size;
        if (P64H_SYSC_RPMI_REMOTE(handle_ptr)) {
            max_data_size = (sizeof(req_buf) - sizeof(rpmi_data_push_req_message_t) - req_size);
        } else {
            max_data_size = (sizeof(req_buf) - sizeof(rpmi_data_push_req_message_t) - req_size);
        }
        size_t  max_num_entries    = max_data_size / entry_size;
        uint8_t send_attempt_count = 0;
        while (!tx_complete) {
            size_t      next_tx_size       = 0;
            const void* curr_buf_data_ptr  = buf_ptr + curr_bytes_sent;
            size_t      data_offset        = curr_bytes_sent / entry_size; // In number of entries
            size_t      bytes_left_to_send = tot_bytes_to_send - curr_bytes_sent;
            size_t      curr_pkg_bytes_left;
            if (shmem_xfer || bytes_left_to_send <= max_data_size) {
                next_tx_size = bytes_left_to_send;
            } else {
                next_tx_size = (max_num_entries * entry_size);
            }
            curr_pkg_bytes_left = bytes_left_to_send - next_tx_size;
            req_msg_ptr
                = (rpmi_req_message_t*)rpmi_data_push_req_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, req_data_ptr, req_size,
                                                                   curr_buf_data_ptr, next_tx_size, data_offset, curr_pkg_bytes_left, shmem_xfer);
            rc = rpmi_req_internal(handle_ptr, req_msg_ptr);
            if (P64H_ERR_OK != rc) {
                break;
            }
            resp_msg_ptr = (rpmi_resp_message_t*)&resp_buf[0];
            rc           = rpmi_resp_internal(handle_ptr, false, resp_msg_ptr);
            if (__is_xfer_error(rc)) {
                if (send_attempt_count++ > P64H_RPMI_RETRY_COUNT) {
                    printf("%s: Failed to send request after %u tries\n", __FUNCTION__, P64H_RPMI_RETRY_COUNT);
                    break;
                } else {
                    printf("\nFailed to get rpmi resp from sysc for data offset %zu, trying again, attempt #%u\n", data_offset, send_attempt_count);
                    continue;
                }
            }
            if (P64H_ERR_OK == rc) {
                send_attempt_count  = 0;
                curr_bytes_sent    += next_tx_size;
                if (curr_bytes_sent == tot_bytes_to_send) {
                    tx_complete = true;
                }
            } else {
                break;
            }
        }
    }
    // convert resp->status;
    return rc;
}

/**
 * @brief Function for receiving RPMI messages that fill up an incoming data buffer.
 *
 * This function receives multiple RPMI messages carrying fragments of data for an input buffer.
 * Once the buffer is full or all remaining fragments have been recieved, it stops receiving RPMI messages.
 *
 *  @note An ACK is sent for each message received successfully.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] req_data_ptr Pointer to a requested data payload
 * @param[in] req_size Size of a request data payload
 * @param[in] buf_ptr Pointer to input buffer to read payload data
 * @param[in] entry_size Size of entry in input buffer
 * @param[in] buf_size Size of input buffer
 * @param[in] shmem_xfer false: the data will be transferred thru RPMI channel
                         true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_resp_with_data_internal(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                      const uint32_t id0, const uint32_t id1, const uint32_t id2, const void* req_data_ptr,
                                                      const size_t req_size, void* buf_ptr, size_t entry_size, size_t buf_size, bool shmem_xfer)
{
    p64h_err_t rc            = P64H_ERR_OK;
    size_t     buf_byte_size = (buf_size * entry_size);

    if (RPMI_RPMI_IO_PORT_TYPE_TCP == handle_ptr->io.port.type) {
        return P64H_ERR_LIB_API_NOT_YET_IMPLEMENTED;
    } else {
        bool    rx_complete        = false;
        size_t  curr_buf_fill      = 0UL;
        void*   curr_buf_data_ptr  = buf_ptr;
        size_t  mem_tx_size        = 0UL;
        uint8_t send_attempt_count = 0;

        while (!rx_complete) {
            uint32_t                      data_offset        = (uint32_t)(curr_buf_fill / entry_size);
            uint32_t                      remaining_buf_size = (uint32_t)(buf_byte_size - curr_buf_fill) / entry_size;
            rpmi_data_pull_req_message_t* rpmi_req_msg       = rpmi_data_pull_req_msg_pack(
                handle_ptr, svc_grp_id, svc_id, id0, id1, id2, req_data_ptr, req_size, remaining_buf_size, data_offset, shmem_xfer,
                curr_buf_data_ptr); // TODO: verify sysc doesn't have an internal state, and only depends on these paremeters
            rc = rpmi_req_internal(handle_ptr, (rpmi_req_message_t*)rpmi_req_msg);
            if (P64H_ERR_OK != rc) {
                break;
            }

            rpmi_data_pull_resp_message_t* rpmi_resp_msg = (rpmi_data_pull_resp_message_t*)&resp_buf[0];
            rc                                           = rpmi_resp_internal(handle_ptr, false, (rpmi_resp_message_t*)rpmi_resp_msg);

            if (__is_xfer_error(rc)) {
                // buf_byte_left += next_tx_size; why does it hang with this? should just send the same thing over and over...
                if (send_attempt_count++ > P64H_RPMI_RETRY_COUNT) {
                    printf("%s: Failed to send request after %u tries\n", __FUNCTION__, P64H_RPMI_RETRY_COUNT);
                    break;
                } else {
                    printf("\nFailed to get rpmi resp from sysc, trying again, attemp #%u\n", send_attempt_count);
                    continue;
                }
            }

            if (P64H_ERR_OK != rc) {
                break;
            }

            send_attempt_count = 0U;
            // unpack fragment
            rx_complete = rpmi_resp_msg->metadata.remaining == 0UL ? true : false;
            if ((0UL != buf_size) && ((curr_buf_fill + (entry_size * rpmi_resp_msg->metadata.returned)) >= buf_byte_size)) {
                rx_complete = true;
                mem_tx_size = (buf_byte_size - curr_buf_fill);
            } else {
                mem_tx_size = (entry_size * rpmi_resp_msg->metadata.returned);
            }

            if (!shmem_xfer) {
                memcpy(curr_buf_data_ptr, rpmi_resp_msg->data, mem_tx_size);
            }
            curr_buf_fill     += mem_tx_size;
            curr_buf_data_ptr  = (void*)((uint64_t)(curr_buf_data_ptr) + mem_tx_size);
        }
    }

    // convert resp->status;
    return rc;
}

/**
 * @brief Function for receiving a fixed-size list response through RPMI.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0.
 * @param[in] id1 Request ID 1.
 * @param[in] id2 Request ID 2.
 * @param[out] list_ptr Pointer to response list buffer.
 * @param[in] list_num Number of list entries expected.
 * @param[in] entry_size Size of each entry in bytes.
 * @param[in] shmem_xfer Shared-memory transfer mode for non-TCP transport.
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise.
 */
static inline p64h_err_t rpmi_resp_list_internal(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                 const uint32_t id0, const uint32_t id1, const uint32_t id2, void* list_ptr, uint32_t list_num,
                                                 size_t entry_size, bool shmem_xfer)
{
    p64h_err_t rc = P64H_ERR_OK;

    if (RPMI_RPMI_IO_PORT_TYPE_TCP == handle_ptr->io.port.type) {
        return P64H_ERR_LIB_API_NOT_YET_IMPLEMENTED;
    } else {
        rc = rpmi_resp_with_data_internal(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, NULL, 0x0UL, list_ptr, entry_size, list_num, shmem_xfer);
    }

    return rc;
}

/**
 * @brief Function for sending and receiving a single RPMI message.
 *
 * This function sends an RPMI message and receives one in the case the sending was successful.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 * @param[in] req_data_ptr Pointer to request data to be sent
 * @param[in] req_size Size of request data to be sent
 * @param[in] resp_data_ptr Pointer to response data
 * @param[in] resp_size Size of response data
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_req_resp_internal(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                const uint32_t id0, const uint32_t id1, const uint32_t id2, const void* req_data_ptr,
                                                const size_t req_size, void* resp_data_ptr, const size_t resp_size)
{
    p64h_err_t           rc = P64H_ERR_OK;
    rpmi_resp_message_t* msg_ptr;
    rpmi_req_message_t*  rpmi_req_msg       = rpmi_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, req_data_ptr, req_size);
    uint8_t              send_attempt_count = 0;
    bool                 rx_complete        = false;

    if (handle_ptr->ctxt.req_posted) {
        rc = rpmi_req_state_check(handle_ptr, svc_grp_id, svc_id);
    }

    if (RPMI_RPMI_IO_PORT_TYPE_TCP == handle_ptr->io.port.type) {
        return P64H_ERR_LIB_API_NOT_YET_IMPLEMENTED;
    } else {
        rpmi_req_msg = rpmi_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, req_data_ptr, req_size);
    }

    if (P64H_ERR_OK == rc) {
        do {
            rc = rpmi_req_internal(handle_ptr, rpmi_req_msg);

            if (P64H_ERR_OK == rc || (handle_ptr->ctxt.req_posted && (P64H_ERR_LIB_API_RESP_PENDING == rc))) {
                msg_ptr = (rpmi_resp_message_t*)&resp_buf[0];
                rc      = rpmi_resp_internal(handle_ptr, true, msg_ptr);
                if (P64H_ERR_LIB_API_TIMEOUT == rc && !handle_ptr->ctxt.req_posted && P64H_RPMI_SRVGRP_SYSTEM == svc_grp_id
                    && P64H_SYS_FW_PKG_UPGRADE_APPLY == svc_id) {
                    for (uint32_t retry_count = 0; retry_count < FW_UPGRADE_APPLY_RX_RETRY_COUNT && P64H_ERR_LIB_API_TIMEOUT == rc; retry_count++) {
                        rc = rpmi_resp_internal(handle_ptr, true, msg_ptr);
                    }
                }
                if (P64H_ERR_LIB_API_TIMEOUT == rc) {
                    if (handle_ptr->ctxt.req_posted) {
                        rc = P64H_ERR_LIB_API_RESP_PENDING;
                    }
                }

                if (P64H_ERR_OK == rc) {
                    if (msg_ptr->header.datalen != sizeof(rpmi_resp_metadata_t) + resp_size) {
                        rc = P64H_ERR_LIB_API_BAD_SIZE;
                    } else {
                        // unpack response
                        if (0x0u != resp_size) {
                            memcpy(resp_data_ptr, &msg_ptr->data, resp_size);
                        }
                        rx_complete = true;
                    }
                }
            }

            if (__is_xfer_error(rc)) {
                if (send_attempt_count++ < P64H_RPMI_RETRY_COUNT) {
                    printf("\nFailed to get rpmi resp from sysc, trying again, attemp #%u\n", send_attempt_count);
                } else {
                    printf("%s: Failed to send request after %u tries\n", __FUNCTION__, P64H_RPMI_RETRY_COUNT);
                    break;
                }
            } else {
                break;
            }
        } while (!rx_complete);
    }

    if (handle_ptr->ctxt.req_posted) {
        if ((P64H_ERR_OK == rc) || (P64H_ERR_OK != rc && P64H_ERR_LIB_API_RESP_PENDING != rc && P64H_ERR_LIB_API_REQ_BUSY != rc)) {
            rpmi_req_info_clean(handle_ptr);
        }
    }

    // convert resp->status;
    return rc;
}

/**
 * @brief Function for fetching a log stucture through RPMI
 *
 * This function is responsible for fetching a log for a specific service
 * group and service ID.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param svc_grp_id The service group identifier.
 * @param svc_id The service identifier.
 * @param id0 The first identifier for the request.
 * @param id1 The second identifier for the request.
 * @param id2 The third identifier for the request.
 * @param log_cfg_ptr Pointer to the configuration of the log being fetched.
 * @param resp_start_off Pointer to store the start offset of entries returned.
 * @param num_returned Number of entries returned.
 * @param entries_left Number of entries left to pull.
 *
 * @return A status code indicating the result of the logging operation.
 */
static p64h_err_t OPTNONE rpmi_req_log_internal(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                                const uint32_t id0, const uint32_t id1, const uint32_t id2, p64h_sysc_log_cfg_t* log_cfg_ptr,
                                                uint64_t* resp_start_off, uint32_t* num_returned, uint64_t* entries_left)
{
    p64h_err_t rc = P64H_ERR_OK;

    if (RPMI_RPMI_IO_PORT_TYPE_TCP == handle_ptr->io.port.type) {
        return P64H_ERR_LIB_API_NOT_YET_IMPLEMENTED;
    } else {
        bool     rx_complete        = false;
        uint32_t buf_fill_left      = log_cfg_ptr->num_entries;
        void*    curr_buf_data_ptr  = log_cfg_ptr->log_ptr;
        uint32_t local_num_returned = 0U;
        uint64_t curr_req_start_off = log_cfg_ptr->req_start_off;
        uint64_t local_entries_left = 0U;
        uint8_t  send_attempt_count = 0U;

        while (!rx_complete) {
            if (buf_fill_left > 0U) {
                rpmi_log_req_message_t* rpmi_req_msg
                    = rpmi_log_req_msg_pack(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, curr_req_start_off, buf_fill_left);
                rc = rpmi_req_internal(handle_ptr, (rpmi_req_message_t*)rpmi_req_msg);
                if (P64H_ERR_OK == rc) {
                    rpmi_log_resp_message_t* rpmi_resp_msg = (rpmi_log_resp_message_t*)&resp_buf[0];
                    rc                                     = rpmi_resp_internal(handle_ptr, false, (rpmi_resp_message_t*)rpmi_resp_msg);
                    if (P64H_ERR_OK == rc) {
                        send_attempt_count = 0U;
                        // unpack fragment
                        uint64_t resp_returned = rpmi_resp_msg->log_metadata.returned;
                        local_entries_left
                            = __long_construct(rpmi_resp_msg->log_metadata.entries_left_hi, rpmi_resp_msg->log_metadata.entries_left_lo);
                        if (0UL != resp_returned) {
                            if (buf_fill_left < resp_returned) {
                                rc          = P64H_ERR_LIB_API_TOO_MANY_ENTRIES_RETURNED;
                                rx_complete = true;
                            } else {
                                size_t mem_tx_size = (log_cfg_ptr->entry_size * resp_returned);
                                if (mem_tx_size > (buf_fill_left * log_cfg_ptr->entry_size)) {
                                    rc          = P64H_ERR_LIB_API_INVALID_ENTRIES_RETURNED;
                                    rx_complete = true;
                                } else {
                                    memcpy(curr_buf_data_ptr, rpmi_resp_msg->data, mem_tx_size);
                                    curr_buf_data_ptr   = (void*)((uint64_t)(curr_buf_data_ptr) + mem_tx_size);
                                    local_num_returned += resp_returned;
                                    buf_fill_left      -= resp_returned;
                                    curr_req_start_off  = __long_construct(rpmi_resp_msg->log_metadata.resp_start_off_hi,
                                                                           rpmi_resp_msg->log_metadata.resp_start_off_lo)
                                                         + resp_returned;
                                }
                            }
                        }
                        if (0UL == local_entries_left) {
                            rx_complete = true;
                        }
                    } else if (__is_xfer_error(rc) && (send_attempt_count++ < P64H_RPMI_RETRY_COUNT)) {
                        printf("\nFailed to get rpmi resp from sysc, trying again, attemp #%u\n", send_attempt_count);
                    } else {
                        rx_complete = true;
                    }
                } else {
                    rx_complete = true;
                }
            } else {
                rx_complete = true;
            }
        }
        if (P64H_ERR_OK == rc) {
            *resp_start_off = curr_req_start_off - local_num_returned;
            *num_returned   = local_num_returned;
            *entries_left   = local_entries_left;
        }
    }

    // convert resp->status;
    return rc;
}

/**
 * @brief Function for checking the validity of IDs to be sent
 *
 * This function validates that the request IDs are valid for a given service group and service.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 * @param[in] id0 Request ID 0
 * @param[in] id1 Request ID 1
 * @param[in] id2 Request ID 2
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_check_ids(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                        const uint32_t id1, const uint32_t id2)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_NULL_HANDLE);
    P64H_SYSC_ASSERT(handle_ptr->init, P64H_ERR_LIB_API_NOT_INITIALIZED);
    P64H_SYSC_ASSERT(handle_ptr->ctxt.cid >= P64H_SYSC_RPMI_CID_APPC_M_0 && handle_ptr->ctxt.cid < LAST_P64H_SYSC_RPMI_CID,
                     P64H_ERR_LIB_API_NOT_INITIALIZED);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);

    // to be implemented
    (void)svc_grp_id;
    (void)svc_id;
    (void)id0;
    (void)id1;
    (void)id2;

    return P64H_ERR_OK;
}

/**
 * @brief Function for checking the request state
 *
 * This function check if there is already an outstanding posted request.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] svc_grp_id ID to the service group on the P64H System Controller.
 * @param[in] svc_id ID of the service to be used for the respective group.
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_req_state_check(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    p64h_err_t           rc                = P64H_ERR_OK;
    rpmi_request_info_t* rpmi_req_info_ptr = (rpmi_request_info_t*)&handle_ptr->req_info;

    rpmi_env_lock((void*)&handle_ptr->lock);
    switch (rpmi_req_info_ptr->req_state) {
        case P64H_SYSC_RPMI_REQ_STATE_NONE:
            rpmi_req_info_ptr->svc_grp_id = svc_grp_id;
            rpmi_req_info_ptr->svc_id     = svc_id;
            rpmi_req_info_ptr->thread_id  = rpmi_env_task_id_get();
            rpmi_req_info_ptr->req_state  = P64H_SYSC_RPMI_REQ_STATE_REQ_BUSY;
            break;
        case P64H_SYSC_RPMI_REQ_STATE_REQ_BUSY:
        case P64H_SYSC_RPMI_REQ_STATE_RESP_PENDING:
            if ((rpmi_req_info_ptr->svc_grp_id == svc_grp_id) && (rpmi_req_info_ptr->svc_id == svc_id)
                && (rpmi_req_info_ptr->thread_id == rpmi_env_task_id_get())) {
                rpmi_req_info_ptr->req_state = P64H_SYSC_RPMI_REQ_STATE_RESP_PENDING;
                rc                           = P64H_ERR_LIB_API_RESP_PENDING;
            } else {
                rc = P64H_ERR_LIB_API_REQ_BUSY;
            }
            break;
        default:
            rc = P64H_ERR_LIB_API_INVALID_REQ_STATE;
            break;
    }
    rpmi_env_unlock((void*)&handle_ptr->lock);
    return rc;
}

/**
 * @brief Function for cleaning the request informations
 *
 * This function cleans the request information.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 *
 * @return p64h_err_t. P64H_ERR_OK on success, error otherwise
 */
static inline p64h_err_t rpmi_req_info_clean(const p64h_sysc_handle_t* handle_ptr)
{
    rpmi_request_info_t* rpmi_req_info_ptr = (rpmi_request_info_t*)&handle_ptr->req_info;

    rpmi_env_lock((void*)&handle_ptr->lock);
    rpmi_req_info_ptr->svc_grp_id = 0;
    rpmi_req_info_ptr->svc_id     = 0;
    rpmi_req_info_ptr->thread_id  = 0;
    rpmi_req_info_ptr->req_state  = P64H_SYSC_RPMI_REQ_STATE_NONE;
    rpmi_env_unlock((void*)&handle_ptr->lock);

    return P64H_ERR_OK;
}
/* Public Function Definitions ------------------------------------ */

/**
 * @brief Sends a request and receives a response for a given service.
 *
 * This function sends a request to a specified service group and service ID,
 * and waits for a response. The request and response data are passed as pointers,
 * along with their respective sizes.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param svc_grp_id The ID of the service group to which the request is sent.
 * @param svc_id The ID of the specific service within the service group.
 * @param id0 Request ID 0
 * @param id1 Request ID 1
 * @param id2 Request ID 2
 * @param req_data_ptr Pointer to the request data. If req_data_ptr is set to NULL and req_size is set to 0, it means there is no request
 * parameter.
 * @param req_size Size of the request data.
 * @param resp_data_ptr Pointer to the buffer where the response data will be stored. If resp_data_ptr is set to NULL and resp_size is set 0, it
 * means there is no response data to be returned.
 * @param resp_size Size of the response data buffer.
 *
 * @return p64h_err_t Error code indicating the result of the request-response operation.
 */
p64h_err_t p64h_sysc_rpmi_req_resp(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                   const uint32_t id1, const uint32_t id2, const void* req_data_ptr, const size_t req_size, void* resp_data_ptr,
                                   const size_t resp_size)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    if ((req_data_ptr == NULL && req_size != 0) || (req_data_ptr != NULL && req_size == 0) || (resp_data_ptr == NULL && resp_size != 0)
        || (resp_data_ptr != NULL && resp_size == 0)) {
        return P64H_ERR_LIB_API_INVALID_PARAM;
    }
    p64h_err_t rc = rpmi_check_ids(handle_ptr, svc_grp_id, svc_id, id0, id1, id2);
    if (P64H_ERR_OK == rc) {
        rc = rpmi_req_resp_internal(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, req_data_ptr, req_size, resp_data_ptr, resp_size);
    }
    return rc;
}

/**
 * @brief Processes a list of IDs and performs a system call with the given parameters.
 *
 * This function checks the validity of the provided IDs and, if valid, performs an internal buffer operation
 * using the specified system call parameters. It returns an error code indicating the success or failure of the operation.
 *
 * @param handle_ptr Pointer to the system call handle.
 * @param svc_grp_id Service group identifier.
 * @param svc_id Service identifier.
 * @param id0 First ID to be processed.
 * @param id1 Second ID to be processed.
 * @param id2 Third ID to be processed.
 * @param list_ptr Pointer to the list where results will be stored.
 * @param list_num Number of entries in the list.
 * @param entry_size Size of each entry in the list.
 * @param shmem_xfer false: the data will be transferred thru RPMI channel
                         true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 *
 * @return p64h_err_t Error code indicating the result of the operation.
 *         - P64H_ERR_OK: Operation was successful.
 *         - Other error codes indicate specific failure conditions.
 */
p64h_err_t p64h_sysc_rpmi_resp_list(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                    const uint32_t id1, const uint32_t id2, void* list_ptr, uint32_t list_num, size_t entry_size, bool shmem_xfer)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(list_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(list_num > 0, P64H_ERR_LIB_API_INVALID_PARAM);
    P64H_SYSC_ASSERT(entry_size > 0, P64H_ERR_LIB_API_BAD_SIZE);
    p64h_err_t rc = rpmi_check_ids(handle_ptr, svc_grp_id, svc_id, id0, id1, id2);
    if (P64H_ERR_OK == rc) {
        rc = rpmi_resp_list_internal(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, list_ptr, list_num, entry_size, shmem_xfer);
    }
    return rc;
}

/**
 * @brief Sends a request with an output buffer to the RPMI service.
 *
 * This function checks the validity of the buffer pointer and size, then verifies the service group
 * and service IDs using the RPMI system. If the IDs are valid, it proceeds to send the request data
 * along with the output buffer to the RPMI service.
 *
 * @param handle_ptr Pointer to the RPMI system handle.
 * @param svc_grp_id Service group ID to be used in the request.
 * @param svc_id Service ID to be used in the request.
 * @param req_data_ptr Pointer to the request data.
 * @param req_size Size of the request data.
 * @param buf_ptr Pointer to the output buffer.
 * @param buf_size Size of the output buffer.
 * @param shmem_xfer false: the data will be transferred thru RPMI channel
                         true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 *
 * @return p64h_err_t Error code indicating the result of the operation.
 *         P64H_ERR_OK if the operation was successful, otherwise an error code.
 */
p64h_err_t p64h_sysc_rpmi_req_with_data(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                        const void* req_data_ptr, const size_t req_size, const void* buf_ptr, const size_t buf_size, bool shmem_xfer)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(buf_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(buf_size > 0, P64H_ERR_LIB_API_BAD_SIZE);
    if ((req_data_ptr == NULL && req_size != 0) || (req_data_ptr != NULL && req_size == 0)) {
        return P64H_ERR_LIB_API_INVALID_PARAM;
    }
    p64h_err_t rc = rpmi_check_ids(handle_ptr, svc_grp_id, svc_id, 0x0u, 0x0u, 0x0u);
    if (P64H_ERR_OK == rc) {
        rc = rpmi_req_with_data_internal(handle_ptr, svc_grp_id, svc_id, 0x0u, 0x0u, 0x0u, req_data_ptr, req_size, buf_ptr, sizeof(uint8_t), buf_size,
                                         shmem_xfer);
    }
    return rc;
}

/**
 * @brief Processes a request and response buffer for RPMI service.
 *
 * This function checks the validity of the service group ID and service ID,
 * and if valid, processes the request data into the provided buffer.
 *
 * @param handle_ptr Pointer to the system control handle.
 * @param svc_grp_id Service group identifier.
 * @param svc_id Service identifier.
 * @param id0 First ID to be processed.
 * @param id1 Second ID to be processed.
 * @param id2 Third ID to be processed.
 * @param req_data_ptr Pointer to the request data. If req_data_ptr is set to NULL, it means there is no request parameter.
 * @param req_size Size of the request data.
 * @param buf_ptr Pointer to the buffer where the response will be stored.
 * @param buf_size Size of the response buffer.
 * @param shmem_xfer false: the data will be transferred thru RPMI channel
                     true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 *
 * @return p64h_err_t Error code indicating the result of the operation.
 *         P64H_ERR_OK if successful, or an error code if the operation fails.
 */
p64h_err_t p64h_sysc_rpmi_resp_with_data(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                         const uint32_t id1, const uint32_t id2, const void* req_data_ptr, const size_t req_size, void* buf_ptr,
                                         size_t buf_size, bool shmem_xfer)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(buf_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(buf_size > 0, P64H_ERR_LIB_API_BAD_SIZE);

    if ((req_data_ptr == NULL && req_size != 0) || (req_data_ptr != NULL && req_size == 0)) {
        return P64H_ERR_LIB_API_INVALID_PARAM;
    }
    p64h_err_t rc = rpmi_check_ids(handle_ptr, svc_grp_id, svc_id, id0, id1, id2);
    if (P64H_ERR_OK == rc) {
        rc = rpmi_resp_with_data_internal(handle_ptr, svc_grp_id, svc_id, id0, id1, id2, req_data_ptr, req_size, buf_ptr, sizeof(uint8_t), buf_size,
                                          shmem_xfer);
    }
    return rc;
}

/**
 * Logs RPMI system call information based on the provided configuration.
 *
 * This function checks the validity of the service group and service IDs,
 * and if valid, logs the RPMI system call information using the specified
 * logging configuration.
 *
 * @param handle_ptr Pointer to the system call handle.
 * @param svc_grp_id Service group identifier.
 * @param svc_id Service identifier.
 * @param log_cfg_ptr Pointer to the logging configuration structure.
 * @param resp_start_off Pointer to store the response start offset.
 * @param num_returned Pointer to store the number of entries returned.
 * @param entries_left Pointer to store the number of entries left to pull from the buffer
 *
 * @return Returns a p64h_err_t error code indicating the success or failure
 *         of the operation.
 */
p64h_err_t p64h_sysc_rpmi_log(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, p64h_sysc_log_cfg_t* log_cfg_ptr,
                              uint64_t* resp_start_off, uint32_t* num_returned, uint64_t* entries_left)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT((log_cfg_ptr != NULL) && (resp_start_off != NULL) && (num_returned != NULL) && (entries_left != NULL),
                     P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(log_cfg_ptr->log_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(log_cfg_ptr->num_entries > 0, P64H_ERR_LIB_API_BAD_SIZE);
    p64h_err_t rc = P64H_ERR_OK;

    if (P64H_ERR_OK == rc) {
        rc = rpmi_check_ids(handle_ptr, svc_grp_id, svc_id, 0, 0, 0);
    }

    if (P64H_ERR_OK == rc) {
        rc = rpmi_req_log_internal(handle_ptr, svc_grp_id, svc_id, 0, 0, 0, log_cfg_ptr, resp_start_off, num_returned, entries_left);
    }
    return rc;
}

/**
 * Logs an ID using the RPMI system call interface.
 *
 * This function checks the validity of the provided IDs and, if valid,
 * requests logging of the specified ID using the RPMI system call interface.
 *
 * @param handle_ptr Pointer to the system call handle.
 * @param svc_grp_id Service group ID.
 * @param svc_id Service ID.
 * @param id0 The ID to be logged.
 * @param log_cfg_ptr Pointer to the log configuration structure.
 * @param resp_start_off Pointer to store the response start offset.
 * @param num_returned Pointer to store the number of entries returned.
 * @param entries_left Pointer to store the number of entries left to pull from the buffer
 *
 * @return Returns a p64h_err_t error code indicating the success or failure of the operation.
 *         P64H_ERR_OK indicates success, while other values indicate specific errors.
 */
p64h_err_t p64h_sysc_rpmi_log_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                 p64h_sysc_log_cfg_t* log_cfg_ptr, uint64_t* resp_start_off, uint32_t* num_returned, uint64_t* entries_left)
{
    P64H_SYSC_ASSERT(handle_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT((log_cfg_ptr != NULL) && (resp_start_off != NULL) && (num_returned != NULL) && (entries_left != NULL),
                     P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(log_cfg_ptr->log_ptr != NULL, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(log_cfg_ptr->num_entries > 0, P64H_ERR_LIB_API_BAD_SIZE);
    p64h_err_t rc = P64H_ERR_OK;

    if (P64H_ERR_OK == rc) {
        rc = rpmi_check_ids(handle_ptr, svc_grp_id, svc_id, id0, 0, 0);
    }

    if (P64H_ERR_OK == rc) {
        rc = rpmi_req_log_internal(handle_ptr, svc_grp_id, svc_id, id0, 0, 0, log_cfg_ptr, resp_start_off, num_returned, entries_left);
    }
    return rc;
}
/// @}