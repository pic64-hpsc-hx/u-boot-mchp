/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  librpmi_p64h_types.h
 * @brief RPMI type extensions and custom types related to p64h specific service groups/services
 * @addtogroup RPMI
 * @{
 */

#ifndef LIB_RPMI_P64H_TYPES_H
#define LIB_RPMI_P64H_TYPES_H

#include <env/p64h_sysc_os_specific.h>
#include <rpmi/librpmi_types.h>
#include <generated/p64h_sysc_errors.h>
#include <generated/p64h_sysc_rpmi_defs.h>

/**
 * The following Macros are used to verify that the size of the defect structs are word
 * aligned at compile time.
 */
/**
 * @brief
 * Create a char with a size of -1 if the expr FAILS
 * @param[in] expr - expression to verify and assert on if false
 * @param[in] msg - msg to concatenate to the typedef (LINE number used now)
 *
 */
#define CVERIFY(expr, msg) typedef char compiler_verify_##msg[(expr) ? (+1) : (-1)]

/**
 * @brief
 *   generate an assert indicating the alignment of the field within the structure
 *
 * e.g. if the field is FIELD is 1 byte aligned the structure STRUCT then then assert message
 *  contains the string FIELD_is_1_byte_aligned_in_STRUCT_so_add_1_padding_byte
 *  and therefore you need to add 1 padding bytes.
 *
 * this might cause it to be only 2 byte aligned and you need to recompile and get the next error which might say
 * please add 2 more bytes.
 */
#define P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(type, field)                                                                                      \
    CVERIFY(offsetof(type, field) % 2 != 1, field##_is_1_byte_aligned_in_##type##_so_add_1_padding_byte);                                            \
    CVERIFY(offsetof(type, field) % 4 != 2, field##_is_2_byte_aligned_in_##type##_so_add_2_padding_bytes);                                           \
    CVERIFY(offsetof(type, field) % 8 != 4, field##_is_4_byte_aligned_in_##type##_so_add_4_padding_bytes);

/**
 * @brief
 *   generate an assert indicating if the size of the structure is not a multiple of 8
 */
#define P64H_STATIC_ASSERT_SIZE_IS_MULTIPLE_OF_8(type)                                                                                               \
    CVERIFY(sizeof(type) % 8 != 1, type##_size_is_1_byte_aligned_so_add_7_padding_bytes);                                                            \
    CVERIFY(sizeof(type) % 8 != 2, type##_size_is_2_byte_aligned_so_add_6_padding_bytes);                                                            \
    CVERIFY(sizeof(type) % 8 != 3, type##_size_is_3_byte_aligned_so_add_5_padding_bytes);                                                            \
    CVERIFY(sizeof(type) % 8 != 4, type##_size_is_1_byte_aligned_so_add_4_padding_bytes);                                                            \
    CVERIFY(sizeof(type) % 8 != 5, type##_size_is_2_byte_aligned_so_add_3_padding_bytes);                                                            \
    CVERIFY(sizeof(type) % 8 != 6, type##_size_is_2_byte_aligned_so_add_2_padding_bytes);                                                            \
    CVERIFY(sizeof(type) % 8 != 7, type##_size_is_3_byte_aligned_so_add_1_padding_byte)

/// Maximum size of an RPMI slot buffer
// reserving 4 bytes for checksum to ensure data integrity(e.g., CRC32).
#define RPMI_MAX_SLOT_SIZE                ((32U * 1024U) - 4U)
#define P64H_RPMI_SRVGRP_ID_BASE          (0xA000)
#define P64H_RPMI_SRVGRP_TO_INDEX(srvgrp) ((uint32_t)(((uint32_t)(srvgrp) - (uint32_t)P64H_RPMI_SRVGRP_ID_BASE) - 1u))
#define P64H_RPMI_SRVGRP_COUNT            P64H_RPMI_SRVGRP_TO_INDEX(P64H_RPMI_SRVGRP_MAX)
#define P64H_RPMI_RETRY_COUNT             10

/// Enum encapsulating the possible RPMI roles
typedef enum {
    RPMI_ROLE_P = 0, ///< this is the Platform microcontroller role. (system_controller)
    RPMI_ROLE_A,     ///< this is the Application role. (AppC or Remote)
    RPMI_NUM_ROLES   ///< the number of Roles in the enum
} rpmi_role_t;

typedef enum rpmi_error                   rpmi_error_t;
typedef enum rpmi_periph                  rpmi_periph_t;
typedef struct rpmi_service_group         rpmi_service_group_t;
typedef struct rpmi_service               rpmi_service_t;
typedef struct rpmi_transport             rpmi_transport_t;
typedef struct rpmi_message               rpmi_message_t;
typedef struct rpmi_message_header        rpmi_message_header_t;
typedef struct rpmi_shmem                 rpmi_shmem_t;
typedef struct rpmi_io                    rpmi_io_t;
typedef struct rpmi_io_port               rpmi_io_port_t;
typedef struct rpmi_transport_shmem       rpmi_transport_shmem_t;
typedef struct rpmi_transport_io          rpmi_transport_io_t;
typedef struct rpmi_transport_shmem_queue rpmi_transport_shmem_queue_t;
typedef struct rpmi_event_callback        rpmi_event_callback_t;

#ifndef SWIG
static_assert(sizeof(rpmi_error_t) == 4, "rpmi_error_t should be 4 bytes");
#endif

/// RPMI Generic Response Header
typedef struct {
    rpmi_error_t rpmi_rc; ///< This is an rpmi_error_t that should always be 4 bytes.
    p64h_err_t   p64h_rc; ///< p64h error code
} rpmi_resp_metadata_t;

/// RPMI Generic Request Header
typedef struct __attribute__((aligned(8))) {
    uint32_t id0; ///< generic identifier 0
    uint32_t id1; ///< generic identifier 1
    uint32_t id2; ///< generic identifier 2
} rpmi_req_metadata_t;

/// RPMI Generic Response type
typedef struct {
    rpmi_message_header_t header; ///< Header
    rpmi_resp_metadata_t  resp_metadata;
    uint8_t               data[0]; ///< The payload of the response.
} rpmi_resp_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_resp_message_t, resp_metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_resp_message_t, data);

/// RPMI Generic request type
typedef struct {
    rpmi_message_header_t header;       ///< header message
    rpmi_req_metadata_t   req_metadata; ///< header message
    uint8_t               data[0];      ///< The payload of the request.
} rpmi_req_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_req_message_t, req_metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_req_message_t, data);

/// RPMI Response With Data request metadata type
typedef struct __attribute__((aligned(8))) {
    rpmi_req_metadata_t req_metadata; ///< rpmi request metadata
    uint32_t            offset;       ///< Offset for next fragment data
    uint32_t            remaining;    ///< Remaining size the requestor expects to receive, 0 if requestor doesn't specify size to receive
    bool                shmem_xfer;   ///< false: the buffer will transfer thru RPMI channel
                                      ///< true: the data_ptr shall be available to the system controller
} rpmi_data_pull_req_metadata_t;

/// RPMI Response With Data response metadata type
typedef struct __attribute__((aligned(8))) {
    rpmi_resp_metadata_t resp_metadata; ///< rpmi response metadata
    uint32_t             remaining;     ///< Number of buffer elements remaining to transfer
    uint32_t             returned;      ///< Number of buffer elements returned
} rpmi_data_pull_resp_metadata_t;

/// RPMI Response With Data response type
typedef struct {
    rpmi_message_header_t          header;   ///< header
    rpmi_data_pull_resp_metadata_t metadata; ///< metadata
    uint8_t                        data[0];  ///< The payload of the response.
} rpmi_data_pull_resp_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_data_pull_resp_message_t, metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_data_pull_resp_message_t, data);

/// RPMI Response With Data request type
typedef struct {
    rpmi_message_header_t         header;   ///< header message
    rpmi_data_pull_req_metadata_t metadata; ///< metadata
    uint8_t                       data[0];  ///< The payload of the request.
} rpmi_data_pull_req_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_data_pull_req_message_t, metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_data_pull_req_message_t, data);

/// RPMI log response metadata type
typedef struct __attribute__((aligned(8))) {
    rpmi_resp_metadata_t resp_metadata;     ///< rpmi response metadata
    uint32_t             resp_start_off_lo; ///< Actual log offset from which data was returned (LSB)
    uint32_t             resp_start_off_hi; ///< Actual log offset from which data was returned (MSB)
    uint32_t             entries_left_lo;   ///< Number of entries left to pull (LSB)
    uint32_t             entries_left_hi;   ///< Number of entries left to pull (MSB)
    uint32_t             returned;          ///< Number of log entries returned
} rpmi_log_resp_metadata_t;

/// RPMI log request metadata type
typedef struct __attribute__((aligned(8))) {
    rpmi_req_metadata_t req_metadata;     ///< rpmi request metadata
    uint32_t            req_start_off_lo; ///< Desired log offset at which to start fetching data entries
    uint32_t            req_start_off_hi; ///< Desired log offset at which to start fetching data entries
    uint32_t            max_num_entries;  ///< Maximum number of entries to return
} rpmi_log_req_metadata_t;

/// RPMI log response message type
typedef struct {
    rpmi_message_header_t    header;       ///< header
    rpmi_log_resp_metadata_t log_metadata; ///< log metadata
    uint8_t                  data[0];      ///< The payload of the response.
} rpmi_log_resp_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_log_resp_message_t, log_metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_log_resp_message_t, data);

/// RPMI log request message type
typedef struct {
    rpmi_message_header_t   header;       ///< header message
    rpmi_log_req_metadata_t log_metadata; ///< log metadata
    uint8_t                 data[0];      ///< The payload of the request.
} rpmi_log_req_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_log_req_message_t, log_metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_log_req_message_t, data);

typedef struct __attribute__((aligned(8))) {
    rpmi_req_metadata_t req_metadata; ///< rpmi request header
    uint32_t            remaining;    ///< Number of buffer elements remaining to send
    uint32_t            offset;       ///< Offset of data being sent
    uint32_t            sent;         ///< Number of buffer elements sent in this transaction
    bool                shmem_xfer;   ///< false: the buffer will transfer thru RPMI channel
                                      ///< true: the data_ptr shall be available to the system controller
} rpmi_data_push_req_metadata_t;

typedef struct {
    rpmi_message_header_t         header;   ///< header
    rpmi_data_push_req_metadata_t metadata; ///< metadata
    uint8_t                       data[0];  ///< The payload of the response.
} rpmi_data_push_req_message_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_data_push_req_message_t, metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_data_push_req_message_t, data);

/// RPMI Request Header for TCP
typedef struct __attribute__((aligned(8))) {
    rpmi_uint16_t servicegroup_id;
    rpmi_uint8_t  service_id;
    rpmi_uint8_t  flags;
    rpmi_uint32_t id0;
    rpmi_uint32_t id1;
    rpmi_uint32_t id2;
    rpmi_uint32_t req_size;
    rpmi_uint32_t resp_size;
} rpmi_message_tcp_req_t;

/// RPMI Response Header for TCP
typedef struct __attribute__((aligned(8))) {
    rpmi_uint32_t status;
    rpmi_uint32_t resp_size;
} rpmi_message_tcp_resp_t;

/// RPMI TCP request metadata
typedef struct __attribute__((aligned(8))) {
    rpmi_uint32_t id0;
    rpmi_uint32_t id1;
    rpmi_uint32_t id2;
    rpmi_uint32_t req_size;
    rpmi_uint32_t resp_size;
    rpmi_uint32_t metadata_len; ///< Size of the typed metadata payload (bytes); 0 if unused
} rpmi_metadata_req_t;

/// RPMI TCP response metadata — mirrors rpmi_resp_metadata_t, adds metadata_len
typedef struct __attribute__((aligned(8))) {
    rpmi_error_t rpmi_rc;      ///< RPMI error code (same layout as rpmi_resp_metadata_t)
    p64h_err_t   p64h_rc;      ///< p64h error code
    uint32_t     metadata_len; ///< Size of the typed metadata payload (bytes); 0 if unused
    uint32_t     resp_size;    ///< Size of the response payload (bytes) returned; 0 if unused
} rpmi_metadata_resp_t;

/// TCP-specific log request payload metadata (4 × uint32 = 16 bytes)
typedef struct __attribute__((aligned(8))) {
    uint32_t req_start_off_lo; ///< Desired log offset (LSB)
    uint32_t req_start_off_hi; ///< Desired log offset (MSB)
    uint32_t num_entries;      ///< Maximum entries to return
    uint32_t entry_size;       ///< Size of each log entry in bytes
} rpmi_metadata_log_req_t;

/// TCP-specific log response payload metadata (5 × uint32 = 20 bytes)
typedef struct __attribute__((aligned(8))) {
    uint32_t resp_start_off_lo; ///< Actual start offset (LSB)
    uint32_t resp_start_off_hi; ///< Actual start offset (MSB)
    uint32_t entries_left_lo;   ///< Entries remaining (LSB)
    uint32_t entries_left_hi;   ///< Entries remaining (MSB)
    uint32_t returned;          ///< Number of entries returned
} rpmi_metadata_log_resp_t;

/// TCP-specific list request payload metadata (2 × uint32 = 8 bytes)
typedef struct __attribute__((aligned(8))) {
    uint32_t list_num;   ///< Number of list entries requested
    uint32_t entry_size; ///< Size of each list entry in bytes
} rpmi_metadata_list_req_t;

/// TCP request schema: header + TCP metadata (with metadata_len) + separate payload pointers
typedef struct {
    rpmi_message_header_t header;       ///< RPMI message header
    rpmi_metadata_req_t   req_metadata; ///< TCP request metadata (ids, req_size, resp_size, metadata_len)
    uint8_t*              metadata_ptr; ///< Pointer to typed metadata payload
    uint8_t*              data_ptr;     ///< Pointer to bulk data payload (NULL if none)
} rpmi_req_schema_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_req_schema_t, req_metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_req_schema_t, metadata_ptr);

/// TCP response schema: header + TCP metadata (with metadata_len) + separate payload pointers
typedef struct {
    rpmi_message_header_t header;        ///< RPMI message header
    rpmi_metadata_resp_t  resp_metadata; ///< TCP response metadata (rc, p64h_rc, metadata_len)
    uint8_t*              metadata_ptr;  ///< Pointer to typed metadata payload
    uint8_t*              data_ptr;      ///< Pointer to bulk data payload (NULL if none)
} rpmi_resp_schema_t;
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_resp_schema_t, resp_metadata);
P64H_STATIC_ASSERT_FIELD_IS_8_BYTE_ALIGNED(rpmi_resp_schema_t, metadata_ptr);

/// RPMI Event Notification Request States
typedef enum {
    P64H_RPMI_NOTIFICATION_DISABLE   = 0u, ///< Notifications are Disabled
    P64H_RPMI_NOTIFICATION_ENABLE    = 1u, ///< Notifications are Enabled
    P64H_RPMI_NOTIFICATION_STATE_GET = 2u, ///< Access Notification State
} p64h_rpmi_notification_req_t;

/// RPMI generic event request
typedef struct {
    uint32_t                     eid;       ///< event identifier
    p64h_rpmi_notification_req_t req_state; ///< 0: Disable, 1: Enable, 2: Return current state
} rpmi_enable_notification_t;

/// RPMI Service Access Controls
typedef enum {
    P64H_RPMI_SVC_UNSUPPORTED = 0u, ///< Service is unsupported
    P64H_RPMI_SVC_SUPPORTED   = 1u, ///< Service is supported
    P64H_RPMI_SVC_RESTRICTED  = 2u, ///< Service is supported but is restricted
    P64H_RPMI_SVC_CHALLENGE   = 3u  ///< Service is supported but need key
} p64h_rpmi_service_access_control_t;

/*
 * Service-group, service-ID and notification-event ID enums (e.g.
 * p64h_rpmi_service_group_id_t, p64h_rpmi_<group>_service_id_t,
 * p64h_rpmi_<group>_service_notification_event_t) are now generated and
 * provided by <generated/p64h_sysc_rpmi_defs.h>, included above.
 *
 * To change a service-group ID, service ID or notification-event ID, edit
 * tools/etc/gen_data/remote.yaml (reference_enums block) and re-run the
 * gen_system_remote_api CMake target.
 */

/**@} */

#endif // LIB_RPMI_P64H_TYPES_H
