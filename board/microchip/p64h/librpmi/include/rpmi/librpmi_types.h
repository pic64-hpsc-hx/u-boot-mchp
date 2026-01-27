/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

#ifndef LIBRPMI_TYPES_H
#define LIBRPMI_TYPES_H

#ifndef __SIZEOF_LONG__
#define __SIZEOF_LONG__ 8
#endif

#include <ba/p64h_sysc_shared_periph_ba.h>

/******************************************************************************/

/**
 * \defgroup BASIC_TYPES_DEFINES Basic Data Types & Defines
 * @brief Basic data types and defines.
 * @{
 */
typedef char           rpmi_int8_t;
typedef unsigned char  rpmi_uint8_t;

typedef short          rpmi_int16_t;
typedef unsigned short rpmi_uint16_t;

typedef int            rpmi_int32_t;
typedef unsigned int   rpmi_uint32_t;

#if __SIZEOF_LONG__ == 8
typedef long          rpmi_int64_t;
typedef unsigned long rpmi_uint64_t;
#elif __SIZEOF_LONG__ == 4
typedef long long          rpmi_int64_t;
typedef unsigned long long rpmi_uint64_t;
#else
#error "Unexpected __SIZEOF_LONG__"
#endif

typedef int           rpmi_bool_t;
typedef unsigned long rpmi_uintptr_t;
typedef unsigned long rpmi_size_t;
typedef long          rpmi_ssize_t;

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#ifndef NULL
#define NULL ((void*)0)
#endif

/** @} */

/**
 * \defgroup RPMI_MSG_PROTOCOL RPMI Messaging Protocol Structures and Defines.
 * @brief Structures and defines for the RPMI messaging protocol.
 * @{
 */

/** RPMI specification version */
#define RPMI_SPEC_VERSION_MAJOR 1U
#define RPMI_SPEC_VERSION_MINOR 0U

/*
 * 31                                            0
 * +---------------------+-----------------------+
 * | FLAGS | SERVICE_ID  |   SERVICEGROUP_ID     |
 * +---------------------+-----------------------+
 * |        TOKEN        |     DATA LENGTH       |
 * +---------------------+-----------------------+
 * |                 DATA/PAYLOAD                |
 * +---------------------------------------------+
 */

/** Message Header byte offset */
#define RPMI_MSG_HDR_OFFSET (0x0U)
/** Message Header Size in bytes */
#define RPMI_MSG_HDR_SIZE (8U)

/** ServiceGroup ID field byte offset */
#define RPMI_MSG_SERVICEGROUP_ID_OFFSET (0x0U)
/** ServiceGroup ID field size in bytes */
#define RPMI_MSG_SERVICEGROUP_ID_SIZE (2U)

/** Service ID field byte offset */
#define RPMI_MSG_SERVICE_ID_OFFSET (0x2U)
/** Service ID field size in bytes */
#define RPMI_MSG_SERVICE_ID_SIZE (1U)

/** Flags field byte offset */
#define RPMI_MSG_FLAGS_OFFSET (0x3U)
/** Flags field size in bytes */
#define RPMI_MSG_FLAGS_SIZE          (1U)

#define RPMI_MSG_FLAGS_TYPE_POS      (0U)
#define RPMI_MSG_FLAGS_TYPE_MASK     0x7U
#define RPMI_MSG_FLAGS_TYPE          ((0x7U) << RPMI_MSG_FLAGS_TYPE_POS)

#define RPMI_MSG_FLAGS_DOORBELL_POS  (3U)
#define RPMI_MSG_FLAGS_DOORBELL_MASK 0x1U
#define RPMI_MSG_FLAGS_DOORBELL      ((0x1U) << RPMI_MSG_FLAGS_DOORBELL_POS)

/** Data length field byte offset */
#define RPMI_MSG_DATALEN_OFFSET (0x4)
/** Data length field size in bytes */
#define RPMI_MSG_DATALEN_SIZE (2)

/** Token field byte offset */
#define RPMI_MSG_TOKEN_OFFSET (0x6)
/** Token field size in bytes */
#define RPMI_MSG_TOKEN_SIZE (2)

/** Data field byte offset */
#define RPMI_MSG_DATA_OFFSET (RPMI_MSG_HDR_SIZE)
/** Data field size in bytes */
#define RPMI_MSG_DATA_SIZE(__slot_size) ((__slot_size)-RPMI_MSG_HDR_SIZE)

/** Minimum slot size in bytes */
#define RPMI_SLOT_SIZE_MIN (64)

/** RPMI Messages Types */
enum rpmi_message_type {
    /* Normal request backed with ack */
    RPMI_MSG_NORMAL_REQUEST = 0x0,
    /* Request without any ack */
    RPMI_MSG_POSTED_REQUEST = 0x1,
    /* Acknowledgment for normal request message */
    RPMI_MSG_ACKNOWLDGEMENT = 0x2,
    /* Notification message */
    RPMI_MSG_NOTIFICATION = 0x3,
};

/** RPMI Message Header */
struct rpmi_message_header {
    rpmi_uint16_t servicegroup_id;
    rpmi_uint8_t  service_id;
    rpmi_uint8_t  flags;
    rpmi_uint16_t datalen;
    rpmi_uint16_t token;
};

/** RPMI Message */
struct rpmi_message {
    struct rpmi_message_header header;
    rpmi_uint8_t               data[0];
};

/** RPMI Error Types */
enum rpmi_error {
    /* Success */
    RPMI_SUCCESS = 0,
    /* General failure  */
    RPMI_ERR_FAILED = -1,
    /* Service or feature not supported */
    RPMI_ERR_NOTSUPP = -2,
    /* Invalid Parameter  */
    RPMI_ERR_INVALID_PARAM = -3,
    /*
     * Denied to insufficient permissions
     * or due to unmet prerequisite
     */
    RPMI_ERR_DENIED = -4,
    /* Invalid address or offset */
    RPMI_ERR_INVALID_ADDR = -5,
    /*
     * Operation failed as it was already in
     * progress or the state has changed already
     * for which the operation was carried out.
     */
    RPMI_ERR_ALREADY = -6,
    /*
     * Error in implementation which violates
     * the specification version
     */
    RPMI_ERR_EXTENSION = -7,
    /* Operation failed due to hardware issues */
    RPMI_ERR_HW_FAULT = -8,
    /* System, device or resource is busy */
    RPMI_ERR_BUSY = -9,
    /* System or device or resource in invalid state */
    RPMI_ERR_INVALID_STATE = -10,
    /* Index, offset or address is out of range */
    RPMI_ERR_BAD_RANGE = -11,
    /* Operation timed out */
    RPMI_ERR_TIMEOUT = -12,
    /*
     * Error in input or output or
     * error in sending or receiving data
     * through communication medium
     */
    RPMI_ERR_IO = -13,
    /* No data available */
    RPMI_ERR_NO_DATA        = -14,
    RPMI_ERR_RESERVED_START = -15,
    RPMI_ERR_RESERVED_END   = -127,
    RPMI_ERR_VENDOR_START   = -128,
    // P64H Specific Error Codes
    RPMI_P64H_ERR_NOT_IMPLEMENTED = -65536,
    RPMI_P64H_ERR_CHECKSUM_MISMATCH
};

/** RPMI Queue Types */
enum rpmi_queue_type {
    RPMI_QUEUE_A2P_REQ = 0,
    RPMI_QUEUE_P2A_ACK,
    RPMI_QUEUE_P2A_REQ,
    RPMI_QUEUE_A2P_ACK,
    RPMI_QUEUE_MAX,
};

/** RPMI ServiceGroups IDs */
enum rpmi_servicegroup_id {
    RPMI_SRVGRP_ID_MIN         = 0,
    RPMI_SRVGRP_BASE           = 0x00001,
    RPMI_SRVGRP_SYSTEM_RESET   = 0x00002,
    RPMI_SRVGRP_SYSTEM_SUSPEND = 0x00003,
    RPMI_SRVGRP_HSM            = 0x00004,
    RPMI_SRVGRP_CPPC           = 0x00005,
    RPMI_SRVGRP_CLOCK          = 0x00007,
    RPMI_SRVGRP_ID_MAX_COUNT,
};

/** RPMI Base ServiceGroup Service IDs */
enum rpmi_base_service_id {
    RPMI_BASE_SRV_ENABLE_NOTIFICATION        = 0x01,
    RPMI_BASE_SRV_GET_IMPLEMENTATION_VERSION = 0x02,
    RPMI_BASE_SRV_GET_IMPLEMENTATION_IDN     = 0x03,
    RPMI_BASE_SRV_GET_SPEC_VERSION           = 0x04,
    RPMI_BASE_SRV_GET_HW_INFO                = 0x05,
    RPMI_BASE_SRV_PROBE_SERVICE_GROUP        = 0x06,
    RPMI_BASE_SRV_GET_ATTRIBUTES             = 0x07,
    RPMI_BASE_SRV_SET_MSI                    = 0x08,
    RPMI_BASE_SRV_MAX                        = 0x09,
};

#define RPMI_BASE_VERSION_MINOR_POS  0U
#define RPMI_BASE_VERSION_MINOR_MASK 0xffffU

#define RPMI_BASE_VERSION_MAJOR_POS  16U
#define RPMI_BASE_VERSION_MAJOR_MASK 0xffffU

#define RPMI_BASE_VERSION(__major, __minor)                                                                                                          \
    ((((__major) & RPMI_BASE_VERSION_MAJOR_MASK) << RPMI_BASE_VERSION_MAJOR_POS)                                                                     \
     | (((__minor) & RPMI_BASE_VERSION_MINOR_MASK) << RPMI_BASE_VERSION_MINOR_POS))

#define RPMI_BASE_VENDOR_ID(__id, __subid) ((((__subid) & 0xffffU) << 16U) | ((__id) & 0xffffU))

#define RPMI_BASE_FLAGS_F0_EV_NOTIFY       (1UL << 31U)
#define RPMI_BASE_FLAGS_F0_MSI_EN          (1UL << 30U)

/** RPMI System Reset ServiceGroup Service IDs */
enum rpmi_sysreset_service_id {
    RPMI_SYSRST_SRV_ENABLE_NOTIFICATION         = 0x01,
    RPMI_SYSRST_SRV_GET_SYSTEM_RESET_ATTRIBUTES = 0x02,
    RPMI_SYSRST_SRV_SYSTEM_RESET                = 0x03,
    RPMI_SYSRST_SRV_MAX                         = 0x04,
};

#define RPMI_SYSRST_TYPE_SHUTDOWN              0U
#define RPMI_SYSRST_TYPE_COLD_REBOOT           1U
#define RPMI_SYSRST_TYPE_WARM_REBOOT           2U

#define RPMI_SYSRST_ATTRIBUTES_FLAGS_SUPPORTED (1UL << 31U)

/** RPMI System Suspend ServiceGroup Service IDs */
enum rpmi_system_suspend_service_id {
    RPMI_SYSSUSP_SRV_ENABLE_NOTIFICATION           = 0x01,
    RPMI_SYSSUSP_SRV_GET_SYSTEM_SUSPEND_ATTRIBUTES = 0x02,
    RPMI_SYSSUSP_SRV_SYSTEM_SUSPEND                = 0x03,
    RPMI_SYSSUSP_SRV_MAX                           = 0x04,
};

#define RPMI_SYSSUSP_TYPE_SUSPEND_TO_RAM            0U

#define RPMI_SYSSUSP_ATTRIBUTES_FLAGS_CUSTOM_RESUME (1UL << 31)
#define RPMI_SYSSUSP_ATTRIBUTES_FLAGS_SUPPORTED     (1UL << 30)

/** RPMI Hart State Management (HSM) ServiceGroup Service IDs */
enum rpmi_hsm_service_id {
    RPMI_HSM_SRV_ENABLE_NOTIFICATION = 0x01,
    RPMI_HSM_SRV_HART_START          = 0x02,
    RPMI_HSM_SRV_HART_STOP           = 0x03,
    RPMI_HSM_SRV_HART_SUSPEND        = 0x04,
    RPMI_HSM_SRV_GET_HART_STATUS     = 0x05,
    RPMI_HSM_SRV_GET_HART_LIST       = 0x06,
    RPMI_HSM_SRV_GET_SUSPEND_TYPES   = 0x07,
    RPMI_HSM_SRV_GET_SUSPEND_INFO    = 0x08,
    RPMI_HSM_SRV_ID_MAX              = 0x09,
};

/** RPMI Clock (CLK) ServiceGroup Service IDs */
enum rpmi_clock_service_id {
    RPMI_CLK_SRV_ENABLE_NOTIFICATION = 0x01,
    RPMI_CLK_SRV_GET_NUM_CLOCKS      = 0x02,
    RPMI_CLK_SRV_GET_ATTRIBUTES      = 0x03,
    RPMI_CLK_SRV_GET_SUPPORTED_RATES = 0x04,
    RPMI_CLK_SRV_SET_CONFIG          = 0x05,
    RPMI_CLK_SRV_GET_CONFIG          = 0x06,
    RPMI_CLK_SRV_SET_RATE            = 0x07,
    RPMI_CLK_SRV_GET_RATE            = 0x08,
    RPMI_CLK_SRV_ID_MAX,
};

enum rpmi_cppc_service_id {
    RPMI_CPPC_SRV_ENABLE_NOTIFICATION     = 0x01,
    RPMI_CPPC_SRV_PROBE_REG               = 0x02,
    RPMI_CPPC_SRV_READ_REG                = 0x03,
    RPMI_CPPC_SRV_WRITE_REG               = 0x04,
    RPMI_CPPC_SRV_GET_FAST_CHANNEL_REGION = 0x05,
    RPMI_CPPC_SRV_GET_FAST_CHANNEL_OFFSET = 0x06,
    RPMI_CPPC_SRV_GET_HART_LIST           = 0x07,
    RPMI_CPPC_SRV_ID_MAX,
};

/** @} */

/****************************************************************************/

/**
 * \defgroup LIBRPMI_TRANSPORT_INTERFACE RPMI Transport Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for managing RPMI transport.
 * @{
 */

/**
 * RPMI transport instance
 *
 * @brief Structure representing a RPMI transport between the platform firmware
 * and application processors.
 */
struct rpmi_transport {
    /** Name of the transport */
    const char* name;

    /** Endianness of the messages transferred through this transport */
    rpmi_bool_t is_be;

    /**
     * Is P2A channel available (in case of shmem based transport
     * is p2a req and a2p ack queues)
     */
    rpmi_bool_t is_p2a_channel;

    /** Slot (or max message) size in transport queues */
    rpmi_size_t slot_size;

    /**
     * Callback to check if a RPMI queue type is empty
     *
     * Note: This function must be called with transport lock held.
     */
    rpmi_bool_t (*is_empty)(struct rpmi_transport* trans, enum rpmi_queue_type qtype);

    /**
     * Callback to check if a RPMI queue type is full
     *
     * Note: This function must be called with transport lock held.
     */
    rpmi_bool_t (*is_full)(struct rpmi_transport* trans, enum rpmi_queue_type qtype);

    /**
     * Callback to enqueue a RPMI message to a specified RPMI queue type
     *
     * Note: This function must be called with transport lock held.
     */
    enum rpmi_error (*enqueue)(struct rpmi_transport* trans, enum rpmi_queue_type qtype, const struct rpmi_message* msg);

    /**
     * Callback to dequeue a RPMI message from a specified RPMI queue type
     *
     * Note: This function must be called with transport lock held.
     */
    enum rpmi_error (*dequeue)(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg);

    /** Lock to synchronize transport access (optional) */
    void* lock;

    /** Private data of the transport implementation */
    void* priv;
};

/** @} */

/**
 * \defgroup LIBRPMI_COMMON_INTERFACE RPMI Common Library Interface
 * @brief Common defines and structures for the RPMI library.
 * @{
 */

#define LIBRPMI_IMPL_ID                                     0

#define LIBRPMI_IMPL_VERSION_MAJOR                          0
#define LIBRPMI_IMPL_VERSION_MINOR                          1

#define LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SLOTS             4
#define LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SIZE(__slot_size) ((__slot_size) * LIBRPMI_TRANSPORT_SHMEM_QUEUE_MIN_SLOTS)

#define LIBRPMI_EVENT_MAX_NUM                               16

/** Platform specific shared memory operations */
struct rpmi_shmem_platform_ops {
    /** Read from a physical address range (mandatory) */
    enum rpmi_error (*read)(void* priv, rpmi_uint64_t addr, void* in, rpmi_uint32_t len);

    /** Write to a physical address range (mandatory) */
    enum rpmi_error (*write)(void* priv, rpmi_uint64_t addr, const void* out, rpmi_uint32_t len);

    /** Fill a physical address range (mandatory) */
    enum rpmi_error (*fill)(void* priv, rpmi_uint64_t addr, char ch, rpmi_uint32_t len);
};

/** Platform specific IO operations */
struct rpmi_io_platform_ops {
    /** Read from a peripheral (mandatory) */
    enum rpmi_error (*read)(void* priv, void* in, rpmi_uint32_t len);

    /** Write to a peripheral (mandatory) */
    enum rpmi_error (*write)(void* priv, const void* out, rpmi_uint32_t len);

    /** Poll peripheral to see if it is empty of data (mandatory) */
    rpmi_bool_t (*is_empty)(void* priv);
};

/** RPMI shared memory structure to access a platform shared memory */
struct rpmi_shmem {
    /** Name of the shared memory */
    const char* name;

    /** Base address of the shared memory */
    rpmi_uint64_t base;

    /** Size of the shared memory */
    rpmi_uint32_t size;

    /** Pointer to platform specific operations */
    const struct rpmi_shmem_platform_ops* ops;

    /** Private data of the platform specific operations */
    void* ops_priv;
};

struct rpmi_io_port {
    /** Name of the IO port memory */
    const char* port;

    /** Port type */
    rpmi_uint32_t type;

    /** Enable flag */
    rpmi_bool_t enable;

    /** Private data of the platform specific peripheral */
    void* io_priv;
};

/** RPMI IO structure */
struct rpmi_io {
    /** Name of the IO */
    const char* name;

    /** Shmem instance used by the IO*/
    struct rpmi_shmem* shmem;

    /** IO port type */
    const struct rpmi_io_port* port;

    /** Pointer to platform specific operations */
    const struct rpmi_io_platform_ops* ops;

    /** Private data of the platform specific operations */
    void* ops_priv;
};

/** RPMI shared memory transport queue */
struct rpmi_transport_shmem_queue {
    enum rpmi_queue_type queue_type;
    rpmi_uint32_t        queue_size;
    rpmi_uint64_t        queue_base;
    rpmi_uint32_t        data_slots;
};

/** RPMI common transport data */
struct rpmi_transport_common {
    rpmi_uint32_t                      queue_count;
    struct rpmi_transport_shmem_queue* queues;
    struct rpmi_transport              trans;
};

/** RPMI shared memory transport */
struct rpmi_transport_shmem {
    struct rpmi_shmem*           shmem;
    struct rpmi_transport_common trans_common;
};

/** RPMI IO transport */
struct rpmi_transport_io {
    struct rpmi_io*              io;
    struct rpmi_transport_common trans_common;
};

/** Definition of event callback */
typedef void (*p64h_sysc_evt_fct_t)(void* evt_ptr);

/** RPMI Event callback function */
struct rpmi_event_callback {
    p64h_sysc_evt_fct_t evt_func[LIBRPMI_EVENT_MAX_NUM];
};

/** @} */

/**
 * \defgroup LIBRPMI_HSM_INTERFACE RPMI Hart State Management Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for RPMI hart state management. This is shared by multiple RPMI service
 * groups.
 * @{
 */

/** Hart ID considered invalid by RPMI library */
#define LIBRPMI_HSM_INVALID_HART_ID (-1U)

/** Hart index considered invalid by RPMI library */
#define LIBRPMI_HSM_INVALID_HART_INDEX (-1U)

/** RPMI HSM hart states (based on SBI specification) */
enum rpmi_hsm_hart_state {
    RPMI_HSM_HART_STATE_STARTED         = 0x0,
    RPMI_HSM_HART_STATE_STOPPED         = 0x1,
    RPMI_HSM_HART_STATE_START_PENDING   = 0x2,
    RPMI_HSM_HART_STATE_STOP_PENDING    = 0x3,
    RPMI_HSM_HART_STATE_SUSPENDED       = 0x4,
    RPMI_HSM_HART_STATE_SUSPEND_PENDING = 0x5,
    RPMI_HSM_HART_STATE_RESUME_PENDING  = 0x6,
};

/** RPMI HW hart states */
enum rpmi_hart_hw_state {
    /** Hart is stopped or inactive (i.e. not executing instructions) */
    RPMI_HART_HW_STATE_STOPPED = 0x0,
    /** Hart is started or active (i.e. executing instructions) */
    RPMI_HART_HW_STATE_STARTED = 0x1,
    /** Hart is suspended or idle (i.e. WFI or equivalent state) */
    RPMI_HART_HW_STATE_SUSPENDED = 0x2,
};

/** RPMI HSM suspend type */
struct rpmi_hsm_suspend_type {
    rpmi_uint32_t type;
    struct {
        rpmi_uint32_t flags;
#define RPMI_HSM_SUSPEND_INFO_FLAGS_TIMER_STOP (1U << 31)
        rpmi_uint32_t entry_latency_us;
        rpmi_uint32_t exit_latency_us;
        rpmi_uint32_t wakeup_latency_us;
        rpmi_uint32_t min_residency_us;
    } info;
};

/** RPMI hart state management (HSM) structure to manage a set of RISC-V harts.*/
struct rpmi_hsm;

/** Platform specific RPMI hart state management (HSM) operations */
struct rpmi_hsm_platform_ops {
    /** Get hart HW state (mandatory) */
    enum rpmi_hart_hw_state (*hart_get_hw_state)(void* priv, rpmi_uint32_t hart_index);

    /** Prepare a hart to start (optional) */
    enum rpmi_error (*hart_start_prepare)(void* priv, rpmi_uint32_t hart_index, rpmi_uint64_t start_addr);

    /** Finalize hart stop (optional) */
    void (*hart_start_finalize)(void* priv, rpmi_uint32_t hart_index, rpmi_uint64_t start_addr);

    /** Prepare a hart to stop (optional) */
    enum rpmi_error (*hart_stop_prepare)(void* priv, rpmi_uint32_t hart_index);

    /** Finalize hart stop (optional) */
    void (*hart_stop_finalize)(void* priv, rpmi_uint32_t hart_index);

    /** Prepare a hart to suspend (optional) */
    enum rpmi_error (*hart_suspend_prepare)(void* priv, rpmi_uint32_t hart_index, const struct rpmi_hsm_suspend_type* suspend_type,
                                            rpmi_uint64_t resume_addr);

    /** Finalize hart suspend (optional) */
    void (*hart_suspend_finalize)(void* priv, rpmi_uint32_t hart_index, const struct rpmi_hsm_suspend_type* suspend_type, rpmi_uint64_t resume_addr);
};

/** @} */

/**
 * \defgroup LIBRPMI_SYSRESETSRVGRP_INTERFACE RPMI System Reset Service Group Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for RPMI system reset service group.
 * @{
 */

/** Platform specific system reset operations */
struct rpmi_sysreset_platform_ops {
    /**
     * Do system reset
     * Note: this function is not expected to return
     */
    void (*do_system_reset)(void* priv, rpmi_uint32_t sysreset_type);
};

/** @} */

/**
 * \defgroup LIBRPMI_SYSSUSPENDSRVGRP_INTERFACE RPMI System Suspend Service Group Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for RPMI system suspend service group.
 * @{
 */

/** RPMI system suspend type */
struct rpmi_system_suspend_type {
    rpmi_uint32_t type;
    rpmi_uint32_t attr;
};

/** Platform specific system suspend operations */
struct rpmi_syssusp_platform_ops {
    /** Prepare for system suspend */
    enum rpmi_error (*system_suspend_prepare)(void* priv, rpmi_uint32_t hart_index, const struct rpmi_system_suspend_type* syssusp_type,
                                              rpmi_uint64_t resume_addr);
    /** Check if the system is ready to suspend */
    rpmi_bool_t (*system_suspend_ready)(void* priv, rpmi_uint32_t hart_index);
    /** Finalize system suspend */
    void (*system_suspend_finalize)(void* priv, rpmi_uint32_t hart_index, const struct rpmi_system_suspend_type* syssusp_type,
                                    rpmi_uint64_t resume_addr);
    /** Check if the system is ready to resume */
    rpmi_bool_t (*system_suspend_can_resume)(void* priv, rpmi_uint32_t hart_index);
    /** Resume from system suspend */
    enum rpmi_error (*system_suspend_resume)(void* priv, rpmi_uint32_t hart_index, const struct rpmi_system_suspend_type* syssusp_type,
                                             rpmi_uint64_t resume_addr);
};

/** @} */

/**
 * \defgroup LIBRPMI_CLOCKSRVGRP_INTERFACE RPMI Clock Service Group Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for RPMI clock service group.
 * @{
 */

/** Clock rate match mode */
enum rpmi_clock_rate_match {
    RPMI_CLK_RATE_MATCH_INVALID    = -1,
    RPMI_CLK_RATE_MATCH_PLATFORM   = 0,
    RPMI_CLK_RATE_MATCH_ROUND_DOWN = 1,
    RPMI_CLK_RATE_MATCH_ROUND_UP   = 2,
    RPMI_CLK_RATE_MATCH_MAX_IDX,
};

/** Supported clock states */
enum rpmi_clock_state {
    RPMI_CLK_STATE_INVALID  = -1,
    RPMI_CLK_STATE_DISABLED = 0,
    RPMI_CLK_STATE_ENABLED  = 1,
    RPMI_CLK_STATE_MAX_IDX,
};

/** Clock type based on rate format */
enum rpmi_clock_type {
    RPMI_CLK_TYPE_INVALID  = -1,
    RPMI_CLK_TYPE_DISCRETE = 0,
    RPMI_CLK_TYPE_LINEAR   = 1,
    RPMI_CLK_TYPE_MAX_IDX,
};

/** A clock rate representation in RPMI */
struct rpmi_clock_rate {
    rpmi_uint32_t lo;
    rpmi_uint32_t hi;
};

/**
 * Clock Data and Tree details
 *
 * This structure represents the static
 * clock data which platform has to maintain
 * and pass to create the clock service group.
 */
struct rpmi_clock_data {
    /* Parent clock ID */
    rpmi_uint32_t parent_id;
    /* Clock transition latency(milli-seconds) */
    rpmi_uint32_t transition_latency_ms;
    /* Number of rates supported as per the clock format type */
    rpmi_uint32_t rate_count;
    /* Clock rate format type */
    enum rpmi_clock_type clock_type;
    /* Clock name */
    const char* name;
    /* Clock rate array */
    const rpmi_uint64_t* clock_rate_array;
};

/** Clock Attributes */
struct rpmi_clock_attrs {
    /** clock transition latency in milli-seconds */
    rpmi_uint32_t transition_latency;
    /** clock rate format type */
    enum rpmi_clock_type type;
    /** number of supported rates */
    rpmi_uint32_t rate_count;
    /** array of supported rates */
    const rpmi_uint64_t* rate_array;
    /* Clock name */
    const char* name;
};

/** Platform specific clock operations(synchronous) */
struct rpmi_clock_platform_ops {
    /** Set the clock state enable/disable/others */
    enum rpmi_error (*set_state)(void* priv, rpmi_uint32_t clock_id, enum rpmi_clock_state state);

    /**
     * Get state and rate together
     **/
    enum rpmi_error (*get_state_and_rate)(void* priv, rpmi_uint32_t clock_id, enum rpmi_clock_state* state, rpmi_uint64_t* rate);

    /**
     * Check if the requested rate is not in the allowed margin(Hz)
     * which require change in clock rate.
     **/
    rpmi_bool_t (*rate_change_match)(void* priv, rpmi_uint32_t clock_id, rpmi_uint64_t rate);

    /**
     * Set clock rate.
     * Also based on the rate match mode and PLL lock frequency
     * the actual frequency set may have +-margin with requested rate.
     * Return the set rate in new_rate buffer
     * */
    enum rpmi_error (*set_rate)(void* priv, rpmi_uint32_t clock_id, enum rpmi_clock_rate_match match, rpmi_uint64_t rate, rpmi_uint64_t* new_rate);

    /**
     * Recalculate and set rate.
     * Recalculate and set the clock rate based on the new input(parent)
     * clock and return the new rate in buffer.
     */
    enum rpmi_error (*set_rate_recalc)(void* priv, rpmi_uint32_t clock_id, rpmi_uint64_t parent_rate, rpmi_uint64_t* new_rate);
};

/** @} */

/**
 * \defgroup LIBRPMI_CPPCSRVGRP_INTERFACE RPMI CPPC Service Group Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for RPMI cppc service group.
 * @{
 */

/**
 * ACPI CPPC Register IDs as per
 * the SBI CPPC extension.
 */
enum rpmi_cppc_reg_id {
    RPMI_CPPC_HIGHEST_PERF                = 0x00000000,
    RPMI_CPPC_NOMINAL_PERF                = 0x00000001,
    RPMI_CPPC_LOWEST_NON_LINEAR_PERF      = 0x00000002,
    RPMI_CPPC_LOWEST_PERF                 = 0x00000003,
    RPMI_CPPC_GUARANTEED_PERF             = 0x00000004,
    RPMI_CPPC_DESIRED_PERF                = 0x00000005,
    RPMI_CPPC_MIN_PERF                    = 0x00000006,
    RPMI_CPPC_MAX_PERF                    = 0x00000007,
    RPMI_CPPC_PERF_REDUCTION_TOLERANCE    = 0x00000008,
    RPMI_CPPC_TIME_WINDOW                 = 0x00000009,
    RPMI_CPPC_COUNTER_WRAPAROUND_TIME     = 0x0000000A,
    RPMI_CPPC_REFERENCE_PERF_COUNTER      = 0x0000000B,
    RPMI_CPPC_DELIVERED_PERF_COUNTER      = 0x0000000C,
    RPMI_CPPC_PERF_LIMITED                = 0x0000000D,
    RPMI_CPPC_CPPC_ENABLE                 = 0x0000000E,
    RPMI_CPPC_AUTONOMOUS_SELECTION_ENABLE = 0x0000000F,
    RPMI_CPPC_AUTONOMOUS_ACTIVITY_WINDOW  = 0x00000010,
    RPMI_CPPC_ENERGY_PERF_PREFERENCE      = 0x00000011,
    RPMI_CPPC_REFERENCE_PERF              = 0x00000012,
    RPMI_CPPC_LOWEST_FREQ                 = 0x00000013,
    RPMI_CPPC_NOMINAL_FREQ                = 0x00000014,
    RPMI_CPPC_ACPI_REG_MAX_IDX, /* End of the ACPI CPPC registers */
    RPMI_CPPC_TRANSITION_LATENCY = 0x80000000,
    RPMI_CPPC_NON_ACPI_REG_MAX_IDX, /* End of the register namespace */
};

/**
 * CPPC Mode of Operation.
 */
enum rpmi_cppc_mode {
    /**
     * Default CPPC mode in which supervisor software
     * uses Desired Performance Register to request
     * for performance control.
     */
    RPMI_CPPC_PASSIVE_MODE,

    /**
     * CPPC2 mode also called Autonomous mode, which
     * uses Minimum Performance, Maximum Performance
     * and Energy Performance Preference Register to
     * for performance control
     */
    RPMI_CPPC_AUTO_MODE,
};

/**
 * ACPI CPPC Registers
 */
struct rpmi_cppc_regs {
    /* highest performance (r) */
    rpmi_uint32_t highest_perf;
    /* nominal performance (r)*/
    rpmi_uint32_t nominal_perf;
    /* lowest nonlinear performance (r) */
    rpmi_uint32_t lowest_nonlinear_perf;
    /* lowest performance (r) */
    rpmi_uint32_t lowest_perf;
    /* guaranteed performance register (r) */
    rpmi_uint32_t guaranteed_perf;
    /* desired performance regiser (rw) */
    rpmi_uint32_t desired_perf;
    /* minimum performance regiser (rw) */
    rpmi_uint32_t min_perf;
    /* maximun performance regiser (rw) */
    rpmi_uint32_t max_perf;
    /* performance reduction tolerance register (rw) */
    rpmi_uint32_t perf_reduction_tolerence;
    /* time window register (rw) */
    rpmi_uint32_t time_window;
    /* counter wrap around time (r) */
    rpmi_uint64_t counter_wraparound_time;
    /* reference performance counter (r) */
    rpmi_uint64_t reference_perf_counter;
    /* delivered performance counter (r) */
    rpmi_uint64_t delivered_perf_counter;
    /* performance limited register (rw) */
    rpmi_uint32_t perf_limited;
    /* cppc enable register (rw) */
    rpmi_uint32_t cppc_enable;
    /* autonomous selection enable register (rw) */
    rpmi_uint32_t autonomous_selection_enable;
    /* autonomous activity window register (rw) */
    rpmi_uint32_t autonomous_activity_window;
    /* energy performance preference register (rw) */
    rpmi_uint32_t energy_perf_preference;
    /* reference performance (r) */
    rpmi_uint32_t reference_perf;
    /* lowest frequency (r) */
    rpmi_uint32_t lowest_freq;
    /* nominal frequency (r) */
    rpmi_uint32_t nominal_freq;
    /* transition latency */
    rpmi_uint32_t transition_latency;
};

struct rpmi_cppc_platform_ops {
    /**
     * cppc get register value for a hart.
     */
    enum rpmi_error (*cppc_get_reg)(void* priv, rpmi_uint32_t reg_id, rpmi_uint32_t hart_index, rpmi_uint64_t* val);

    /**
     * cppc set register value for a hart.
     */
    enum rpmi_error (*cppc_set_reg)(void* priv, rpmi_uint32_t reg_id, rpmi_uint32_t hart_index, rpmi_uint64_t val);
    /**
     * cppc update performance level for a hart
     */
    enum rpmi_error (*cppc_update_perf)(void* priv, rpmi_uint32_t desired_perf, rpmi_uint32_t hart_index);
};

/** @} */

#endif // LIBRPMI_TYPES_H
