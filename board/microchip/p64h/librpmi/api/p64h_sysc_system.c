/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

// GENERATION START
/**
 * @file  p64h_sysc_system.c
 * @brief System API implementation
 * @addtogroup SYSTEM_API
 * @ingroup p64h_sysc_api
 * @{
 */
// GENERATION END
#include "p64h_sysc_system.h"

/**
 * @brief Enable a system event.
 *
 * This function enables a system event specified by the event ID (eid) and associates it with a
 * system event function (sys_evt_fct). The function returns a status code indicating the success
 * or failure of the operation.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] eid The event ID of the system event to be enabled.
 * @param[in] sys_evt_fct The function to be associated with the system event.
 * @return p64h_err_t Status code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_evt_enable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid, const p64h_sysc_sys_evt_fct_t sys_evt_fct)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(P64H_SYSC_SYS_EVT_ID_LOG <= eid && eid <= P64H_SYSC_SYS_EVT_ID_FW_UPDATE, P64H_ERR_LIB_API_INVALID_PARAM);
    rpmi_enable_notification_t enable_notification;
    enable_notification.eid       = (uint32_t)eid;
    enable_notification.req_state = P64H_RPMI_NOTIFICATION_ENABLE; // 1 = enable

    if (p64h_sysc_rpmi_evt_enable(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, eid, (p64h_sysc_evt_fct_t)sys_evt_fct) == false) {
        return P64H_ERR_LIB_API_INVALID_PARAM;
    }

    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_ENABLE_NOTIFICATION, P64H_SYSC_RPMI_CID_GET(handle_ptr), 0x0u, 0x0u,
                                   &enable_notification, sizeof(enable_notification), NULL, 0x0u);
}

/**
 * @brief Disables a system event.
 *
 * This function disables the specified system event identified by the event ID (eid).
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] eid The ID of the system event to disable.
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_evt_disable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(P64H_SYSC_SYS_EVT_ID_LOG <= eid && eid <= P64H_SYSC_SYS_EVT_ID_FW_UPDATE, P64H_ERR_LIB_API_INVALID_PARAM);
    rpmi_enable_notification_t enable_notification;
    enable_notification.eid       = (uint32_t)eid;
    enable_notification.req_state = P64H_RPMI_NOTIFICATION_DISABLE; // 0 = disable

    if (p64h_sysc_rpmi_evt_disable(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, eid) == false) {
        return P64H_ERR_LIB_API_INVALID_PARAM;
    }

    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_ENABLE_NOTIFICATION, P64H_SYSC_RPMI_CID_GET(handle_ptr), 0x0u, 0x0u,
                                   &enable_notification, sizeof(enable_notification), NULL, 0x0u);
}

/**
 * @brief Get the state of a system event.
 *
 * This function retrieves the current state of the specified system event.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] eid The ID of the system event whose state is to be retrieved.
 * @param[out] state_ptr false : Notification is disabled, true: Notification is enabled.
 * @return p64h_err_t Returns P64H_ERR_OK if the operation is successful.
 */
p64h_err_t p64h_sysc_sys_evt_state_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid,
                                       p64h_sysc_evt_notification_state_t* state_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != state_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(P64H_SYSC_SYS_EVT_ID_LOG <= eid && eid <= P64H_SYSC_SYS_EVT_ID_FW_UPDATE, P64H_ERR_LIB_API_INVALID_PARAM);
    rpmi_enable_notification_t enable_notification;
    enable_notification.eid       = (uint32_t)eid;
    enable_notification.req_state = P64H_RPMI_NOTIFICATION_STATE_GET;

    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_ENABLE_NOTIFICATION, P64H_SYSC_RPMI_CID_GET(handle_ptr), 0x0u, 0x0u,
                                   &enable_notification, sizeof(enable_notification), state_ptr, sizeof(p64h_sysc_evt_notification_state_t));
}

/**
 * @brief Retrieves system information.
 *
 * This function populates the provided sys_info_ptr structure with
 * the current system information.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] sys_info_ptr Pointer to a p64h_sysc_sys_info_t structure
 *                     where the system information will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_info_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sys_info_t* sys_info_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != sys_info_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_INFO, 0x0u, 0x0u, 0x0u, NULL, 0x0u, sys_info_ptr,
                                   sizeof(*sys_info_ptr));
}

/**
 * @brief Retrieve system log information.
 *
 * This function is responsible for obtaining the current number of system logs.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] log_info_ptr Pointer to a structure where the log information will be stored.
 *
 * @return p64h_err_t Error code indicating the status of the operation.
 *         - P64H_ERR_OK: Operation completed successfully.
 */
p64h_err_t p64h_sysc_sys_log_info_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sys_log_info_t* log_info_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != log_info_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_LOG_INFO, 0x0u, 0x0u, 0x0u, NULL, 0x0u, log_info_ptr,
                                   sizeof(*log_info_ptr));
}

/**
 * @brief Sets the system log configuration for a given log ID.
 *
 * This function configures the system log settings based on the provided log ID and configuration pointer.
 * @note Passing P64H_SYSC_LOG_ID_LAST as the log ID is treated as a special
 *   case and applies the configuration to **all supported log IDs**.
 *   This allows system software to configure all log sources in a single
 *   operation instead of configuring each log ID individually.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] lid The log ID for which the configuration is to be set.
 * @param[in] cfg_ptr Pointer to the configuration settings to be applied.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_log_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_log_id_t lid, const p64h_sysc_sys_log_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(P64H_SYSC_LOG_ID_SVC_SYSTEM <= lid && lid <= P64H_SYSC_LOG_ID_LAST, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_LOG_CONFIG, (uint32_t)lid, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr),
                                   NULL, 0x0u);
}

/**
 * @brief Retrieves the system log configuration for a given log ID and destination.
 *
 * This function fetches the system log configuration associated with the specified log ID and destination
 * and stores it in the provided configuration pointer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] lid The log ID for which the system log configuration is to be retrieved.
 * @param[in] did The log destination for which the system log configuration is to be retrieved.
 * @param[out] cfg_ptr Pointer to a structure where the retrieved system log configuration will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_log_cfg_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_log_id_t lid, const p64h_sysc_log_destination_t did,
                                     p64h_sysc_sys_log_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT((P64H_SYSC_LOG_ID_SVC_SYSTEM <= lid && lid < P64H_SYSC_LOG_ID_LAST)
                         && (P64H_SYSC_LOG_TO_STDOUT <= did && did <= P64H_SYSC_LOG_TO_BUFFER),
                     P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_LOG_CONFIG, (uint32_t)lid, (uint32_t)did, 0x0u, NULL, 0x0u,
                                   cfg_ptr, sizeof(*cfg_ptr));
}

/**
 * @brief Retrieves system log data.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] requested_read_offset where to start reading bytes from the buffer.
 * @param[in] data_buffer log buffer bytes (client local variable)
 * @param[in] data_buffer_size size of data_buffer (client side)
 * @param[out] bytes_read_ptr number of bytes returned (<= data_buffer_size).
 * @param[out] resp_offset_ptr actual offset of the first byte in data_buffer (not the same as requested_read_offset if the circular buffer has
 overrun).
 * @param[in] current_write_offset_ptr current write offset.
 * @return p64h_err_t Error code indicating the success or failure of the operation.
 */
p64h_err_t p64h_sysc_sys_log_data_get(const p64h_sysc_handle_t* handle_ptr, uint64_t requested_read_offset, void* data_buffer,
                                      uint64_t data_buffer_size, uint64_t* resp_offset_ptr, uint32_t* bytes_read_ptr,
                                      uint64_t* current_write_offset_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != data_buffer && NULL != resp_offset_ptr && NULL != bytes_read_ptr && NULL != current_write_offset_ptr,
                     P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(0 != data_buffer_size, P64H_ERR_LIB_API_INVALID_PARAM);
    p64h_sysc_log_cfg_t log_cfg_ptr;
    uint64_t            entries_left = 0U;

    log_cfg_ptr.log_ptr              = data_buffer;
    log_cfg_ptr.num_entries          = data_buffer_size;
    log_cfg_ptr.entry_size           = sizeof(char);
    log_cfg_ptr.req_start_off        = requested_read_offset;

    /* currently no api to retrieve a header structure plus variable response buffer,
       so temporarily creating a contiguous response buffer and doing an extra copy. */
    p64h_err_t result = p64h_sysc_rpmi_log(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_LOG_DATA, &log_cfg_ptr, resp_offset_ptr, bytes_read_ptr,
                                           &entries_left);

    if (result == P64H_ERR_OK) {
        if (current_write_offset_ptr) {
            *current_write_offset_ptr = *resp_offset_ptr + *bytes_read_ptr + entries_left;
        } else {
            result = P64H_ERR_LIB_API_NULL_POINTER;
        }
    }
    return result;
}

/**
 * @brief Retrieves the AppC boot configuration.
 *
 * This function is responsible for obtaining the boot configurations
 * available in the system. The result is stored in the provided pointer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] cfg_ptr    Pointer to a structure that will be filled with the boot configuration.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_appc_boot_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_acot_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_APPC_BOOT_CFG, 0x0u, 0x0u, 0x0u, NULL, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr));
}

/**
 * @brief Retrieves the boot status of the specified application configuration.
 *
 * This function fetches the boot status and stores the result in
 * the provided status pointer (status_ptr).
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] status_ptr Pointer to a variable where the boot status will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_appc_boot_status_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_appc_boot_cfg_status_t* status_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != status_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_APPC_BOOT_STATUS, 0x0u, 0x0u, 0x0u, NULL, 0x0u, status_ptr,
                                   sizeof(*status_ptr));
}

/**
 * @brief Set the boot configuration for the specified boot configuration ID.
 *
 * This function sets the boot configuration for the system application controller
 * based on the provided boot configuration ID.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] bid The boot configuration ID to set.
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_appc_boot_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_boot_cfg_id_t bid)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(P64H_SYSC_APPC_BOOT_CFG_15 >= bid && bid >= P64H_SYSC_APPC_BOOT_CFG_0, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_APPC_BOOT_CFG, bid, 0x0u, 0x0u, NULL, 0x0u, NULL, 0x0u);
}

/**
 * @brief Set the system power mode configuration.
 *
 * This function configures the system power mode based on the provided
 * configuration structure. The configuration structure should contain
 * all necessary parameters to set the desired power mode.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfg_ptr Pointer to the power mode configuration structure.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success, or an appropriate error code on failure.
 *
 * @note only p64h_sysc_pwr_freq_mode_t is configurable for now. Change power mode Will reboot FW!
 */
p64h_err_t p64h_sysc_sys_pwr_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pwr_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_PWR_CONFIG, 0x0u, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr), NULL,
                                   0x0u);
}

/**
 * @brief Retrieves the current power mode configuration.
 *
 * This function fetches the current power mode configuration and stores it
 * in the provided configuration pointer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] cfg_ptr Pointer to a p64h_sysc_pwr_mode_cfg_t structure where the
 *                current power mode configuration will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_pwr_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_pwr_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_PWR_CONFIG, 0x0u, 0x0u, 0x0u, NULL, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr));
}

/**
 * @brief Triggers a system power wakeup event via the RPMI service group.
 *
 * This function sends a request to the RPMI service group for the system to trigger a power wakeup event.
 *
 * @param handle_ptr Pointer to the system controller handle.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_pwr_wakeup_trigger(const p64h_sysc_handle_t* handle_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_PWR_WAKEUP_TRIGGER, 0x0u, 0x0u, 0x0u, NULL, 0x0u, NULL, 0x0u);
}

/**
 * @brief Retrieves the system device trace attributes.
 *
 * This function is responsible for obtaining the trace attributes of a system device.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] attr_ptr Pointer to a structure where the trace attributes will be stored.
 * @return p64h_err_t Error code indicating the success or failure of the operation.
 */
p64h_err_t p64h_sysc_sys_trace_dev_attr_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_trace_dev_attr_t* attr_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != attr_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_DEV_TRACE_ATTRIBUTE, 0x0u, 0x0u, 0x0u, NULL, 0x0u, attr_ptr,
                                   sizeof(*attr_ptr));
}

/**
 * @brief Retrieves the system device trace configuration.
 *
 * This function is responsible for obtaining the current configuration
 * of the system device trace and storing it in the provided configuration
 * structure pointer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] cfg_ptr Pointer to a structure where the trace configuration
 *                    will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_trace_dev_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_trace_dev_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_DEV_TRACE_CONFIG, 0x0u, 0x0u, 0x0u, NULL, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr));
}

/**
 * @brief Set the system device trace configuration.
 *
 * This function sets the trace configuration for the system device.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfg_ptr Pointer to the trace configuration structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_trace_dev_cfg_set(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_trace_dev_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_DEV_TRACE_CONFIG, 0x0u, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr),
                                   NULL, 0x0u);
}

/**
 * @brief Trigger a manual SYNCREQ pulse on the device trace funnel.
 *
 * Forces the funnel TWP formatter to emit a SYNCREQ packet so downstream
 * decoders re-align on a known boundary in the merged stream. The SysC
 * writes bit 0 of the ETR's SYNCREQ_TRIGGER register and polls bit 1
 * (SYNCREQ_TRIGGER_ACK) for a bounded number of iterations before
 * returning. Useful for marking a known boundary in the captured TWP
 * stream without waiting for the next periodic SYNCREQ.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @return p64h_err_t P64H_ERR_OK on ACK; P64H_ERR_SVC_TRACE_SYNCREQ_ACK_TIMEOUT
 *         if the SysC poll window expired without HW asserting ACK.
 */
p64h_err_t p64h_sysc_sys_trace_syncreq_send(const p64h_sysc_handle_t* handle_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_TRACE_SYNCREQ_SEND, 0x0u, 0x0u, 0x0u, NULL, 0x0u, NULL, 0x0u);
}

/**
 * @brief Uploads firmware to the system.
 *
 * This function uploads firmware to the system using the provided configuration and data.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfg_ptr Pointer to the firmware upgrade configuration structure.
 * @param[out] data_ptr Pointer to the firmware upgrade package.
 * @param[in] size Size of the firmware upgrade package.
 * @param[in] shmem_xfer false: the data will be transferred thru RPMI channel
 *                       true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_fw_pkg_upgrade_upload(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pkg_cfg_t* cfg_ptr, const void* data_ptr,
                                               size_t size, bool shmem_xfer)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr && NULL != data_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(size > 0u, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_with_data(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_FW_PKG_UPGRADE_UPLOAD, cfg_ptr, sizeof(*cfg_ptr), data_ptr,
                                        size, shmem_xfer);
}

/**
 * @brief Applies firmware upgrade to the system.
 *
 * This function applies a previously uploaded firmware upgrade to the system using the provided configuration and data.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfg_ptr Pointer to the firmware upgrade configuration structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_fw_pkg_upgrade_apply(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pkg_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_FW_PKG_UPGRADE_APPLY, 0x0u, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr),
                                   NULL, 0x0u);
}

/**
 * @brief Initiate a firmware dump.
 *
 * This function initiates the firmware dump process using the provided configuration.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfg_ptr Pointer to the firmware dump configuration structure.
 *
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_fw_dump(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_dump_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_FW_DUMP, 0x0u, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr), NULL, 0x0u);
}

/**
 * @brief Perform a firmware download
 *
 * This function downloads a firmware dump from the system. A dump needs to have been initiated and completed before this is called.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] data_ptr Pointer where the dump will be stored.
 * @param[in] size Size of the dump to receive.
 * @param[in] shmem_xfer false: the data will be transferred thru RPMI channel
 *                       true: data stored at given ptr will be directly accessed by sysc (this pointer needs to be accessible by the sysc)
 * @return p64h_err_t Error code indicating the result of the firmware update operation.
 *         - P64H_ERR_OK: Firmware update was successful.
 */
p64h_err_t p64h_sysc_sys_fw_download(const p64h_sysc_handle_t* handle_ptr, void* data_ptr, size_t size, bool shmem_xfer)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != data_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(size > 0u, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_resp_with_data(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_FW_DOWNLOAD, 0x0u, 0x0u, 0x0u, NULL, 0x0u, data_ptr, size,
                                         shmem_xfer);
}

/**
 * @brief Get firmware dump status
 *
 * This function gets the firmware dump status.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] status_ptr Pointer to the firmware dump status configuration structure.
 *
 * @return p64h_err_t Error code indicating the result of the firmware update operation.
 *         - P64H_ERR_OK: Firmware update was successful.
 */
p64h_err_t p64h_sysc_sys_fw_dump_status_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_fw_dump_status_t* status_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != status_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_FW_DUMP_STATUS, 0x0u, 0x0u, 0x0u, NULL, 0x0u, status_ptr,
                                   sizeof(*status_ptr));
}

/**
 * @brief Set system time
 *
 * This function sets the firmware time.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] time_ptr  pointer to p64h_sysc_time_t structure.
 *
 * @return p64h_err_t Error code indicating the result of the set operation.
 *         - P64H_ERR_OK: Time updated successfully.
 *         - P64H_ERR_INVALID_INPUT: invalid time to set.
 *
 * @note The valid time range for system Time of Day (TOD) is:
 *       - After 1988-01-01 00:00:00 (inclusive).
 *       - Before 2100-01-01 00:00:00 (exclusive).
 *       system will reject any time outside this range with P64H_ERR_INVALID_INPUT.
 *       The time must also be a valid calendar date and time (e.g., month 1-12,
 *       day 1-31, hour 0-23, minute 0-59, second 0-59).
 *
 * @note Side Effects:
 *       - Calling this initializes the system Time Manager; until set,
 *         time-getting functions will return P64H_ERR_NOT_SET.
 *       - Setting the time forward may unblock higher-priority tasks waiting
 *         on timers, potentially causing immediate task preemption.
 */
p64h_err_t p64h_sysc_sys_time_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_time_t* time_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != time_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_TIME, 0x0u, 0x0u, 0x0u, time_ptr, sizeof(*time_ptr), NULL, 0x0u);
}

/**
 * @brief Get system time
 *
 * This function gets the firmware time.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] time_ptr  pointer to p64h_sysc_time_t structure.
 *
 * @return p64h_err_t Error code indicating the result of the set operation.
 *         - P64H_ERR_OK: Get operation was successful.
 */
p64h_err_t p64h_sysc_sys_time_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_time_t* time_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != time_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_TIME, 0x0u, 0x0u, 0x0u, NULL, 0x0u, time_ptr, sizeof(*time_ptr));
}

/**
 * @brief Set PTP Time-of-Day to be latched on the next 1PPS event.
 *
 * Configures the device ToD counters with the provided value. The ToD is
 * latched into the HW counters on the next rising edge of the 1PPSI input.
 * The caller is expected to have set the ToD sync method to the
 * software-configured path beforehand.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] tod_ptr    Pointer to the desired PTP ToD (see p64h_sysc_tod_t).
 *
 * @return P64H_ERR_OK on success, or a non-zero error code on failure.
 */
p64h_err_t p64h_sysc_ptp_tod_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_tod_t* tod_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr && NULL != tod_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_PTP_TOD_SET, 0x0u, 0x0u, 0x0u, tod_ptr, sizeof(*tod_ptr), NULL,
                                   0x0u);
}

/**
 * @brief Get PTP Time-of-Day captured at the last 1PPS event.
 *
 * Returns the ToD captured in HW when the last rising edge of the 1PPSI
 * input signal was detected.
 *
 * @param[in]  handle_ptr Pointer to the RPMI system controller context.
 * @param[out] tod_ptr    Pointer to the PTP ToD output buffer.
 *
 * @return P64H_ERR_OK on success, or a non-zero error code on failure.
 */
p64h_err_t p64h_sysc_ptp_tod_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_tod_t* tod_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr && NULL != tod_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_PTP_TOD_GET, 0x0u, 0x0u, 0x0u, NULL, 0x0u, tod_ptr,
                                   sizeof(*tod_ptr));
}

/**
 * @brief Sets the system programmer clock configuration.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] clk_id Clock ID of which to set the configuration of.
 * @param[in] cfg_ptr Pointer to the programmer clock configuration structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 *
 * @note The value P64H_SYSC_PGMRCLK_SEL_DISABLED for cfg_ptr->clk_sel is provided as a special option to explicitly disable
 *       the clock settings for the specified clock ID. The function will not configure or modify the clock, effectively disabling
 *       any changes to the clock configuration for that instance.
 */
p64h_err_t p64h_sysc_sys_pgmrclk_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pgmrclk_id_t clk_id, const p64h_pgmrclk_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(P64H_SYSC_PGMRCLK_ID_PIN_0 <= clk_id && clk_id < P64H_SYSC_PGMRCLK_ID_LAST, P64H_ERR_DRV_PGMRCLK_INVALID_CLOCK_ID);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_PGMRCLK_CFG, (uint32_t)clk_id, 0x0u, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr), NULL, 0x0u);
}

/**
 * @brief Gets the system programmer clock configuration.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] clk_id   Identifier of the system programmer clock to configure.
 * @param[out] cfg_ptr Pointer to the structure to store the programmer clock configuration.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_pgmrclk_cfg_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pgmrclk_id_t clk_id, p64h_pgmrclk_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(P64H_SYSC_PGMRCLK_ID_PIN_0 <= clk_id && clk_id < P64H_SYSC_PGMRCLK_ID_LAST, P64H_ERR_DRV_PGMRCLK_INVALID_CLOCK_ID);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_PGMRCLK_CFG, (uint32_t)clk_id, 0x0u, 0x0u, NULL, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr));
}

/**
 * @brief Sets the configuration for CFM measurement.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfm_inst CFM instance.
 * @param[in] cfg_ptr Pointer to the CFM configuration structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_cfm_meas_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_cfm_inst_t cfm_inst,
                                          const p64h_sysc_cfm_cfg_t* cfg_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(P64H_SYSC_CFM_INST_GENERIC <= cfm_inst && cfm_inst < P64H_SYSC_CFM_INST_LAST, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_CFM_MEAS_CFG, (uint32_t)cfm_inst, 0x0u, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr), NULL, 0x0u);
}

/**
 * @brief Gets CFM measurement count.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] cfm_inst   CFM instance.
 * @param[out] count_ptr Pointer to CFM measurement count.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_cfm_meas_count_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_cfm_inst_t cfm_inst,
                                            p64h_sysc_cfm_meas_count_t* count_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(NULL != count_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(P64H_SYSC_CFM_INST_GENERIC <= cfm_inst && cfm_inst < P64H_SYSC_CFM_INST_LAST, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_CFM_MEAS_CNT, (uint32_t)cfm_inst, 0x0u, 0x0u, NULL, 0x0u,
                                   count_ptr, sizeof(*count_ptr));
}

/**
 * @brief Take FW PLL support measurement.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] fw_pll_cfg_ptr Points to FW PLL configuration structure.
 * @param[out] timestamp_ptr Points to FW PLL timestamp structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_fw_pll_measure(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pll_cfg_t* fw_pll_cfg_ptr,
                                        p64h_sysc_fw_pll_timestamp_t* timestamp_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_FW_PLL_MEASURE, 0x0u, 0x0u, 0x0u, fw_pll_cfg_ptr,
                                   sizeof(*fw_pll_cfg_ptr), timestamp_ptr, sizeof(*timestamp_ptr));
}

/**
 * @brief Fixes up the device tree blob (DTB) for the system controller.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] dtb_addr Address of the device tree blob.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_dtb_fixup(const p64h_sysc_handle_t* handle_ptr, const uint64_t dtb_addr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_APPC_DTB_FIXUP, 0x0u, 0x0u, 0x0u, &dtb_addr, sizeof(dtb_addr), NULL,
                                   0x0u);
}

/**
 * @brief Force reboot the System Controller to a specific SysC cfg image.
 *
 * Sets the M1 FSBL boot-request fields in the scratchpad and triggers a
 * SysC soft reset so ZSBL boots from the specified image on the next startup.
 * The firmware validates that the OTP image table entry for sysc_boot_cfg_id
 * is programmed before accepting the request.
 *
 * @param[in] handle_ptr       Pointer to the RPMI system controller context.
 * @param[in] sysc_boot_cfg_id SysC cfg image ID to boot (0-7, must exist in OTP).
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success (function does not return
 *                    on a successful reboot). Returns an error code if the
 *                    image ID is out of range or the OTP entry is unprogrammed.
 */
p64h_err_t p64h_sysc_system_reboot(const p64h_sysc_handle_t* handle_ptr, const uint32_t sysc_boot_cfg_id)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(sysc_boot_cfg_id < P64H_SYSC_SYSC_BOOT_CFG_MAX, P64H_ERR_LIB_API_INVALID_PARAM);
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SYSC_REBOOT, sysc_boot_cfg_id, 0x0u, 0x0u, NULL, 0x0u, NULL, 0x0u);
}

/**
 * @brief Set the threshold value for the Temperature and Voltage Monitor (TMON).
 *
 * Sets the threshold level fields in the TMON register space (in Kelvin) for
 * temperature measurement.
 *
 * The firmware briefly aborts the measurement process and disables the temperature
 * channel to avoid situations where the threshold is triggered while being set.
 * This also serves to remove an active trigger status if it was triggered before
 * the method was called.
 * The temperature channel is then re-enabled and the measurement is resumed.
 *
 * @param[in] handle_ptr    Pointer to the RPMI system controller context.
 * @param[in] tmon_inst     The top-level TMON instance.
 * @param[in] threshold_ptr Points to TMON threshold structure.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success. Returns an error code if
 *                    the handle is invalid or the TMON instance is out of range.
 */
p64h_err_t p64h_sysc_sys_tmon_threshold_set(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_tmon_inst_t tmon_inst,
                                            p64h_sysc_tmon_threshold_t* threshold_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(tmon_inst < P64H_SYSC_TMON_INST_LAST, P64H_ERR_LIB_API_INVALID_PARAM);
    P64H_SYSC_ASSERT(NULL != threshold_ptr, P64H_ERR_LIB_API_NULL_POINTER);

    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_TMON_THRESHOLD, (uint32_t)tmon_inst, 0x0u, 0x0u, threshold_ptr,
                                   sizeof(*threshold_ptr), NULL, 0x0u);
}

/**
 * @brief Retrieve the channel values from the Temperature and Voltage Monitor (TMON).
 *
 * @param[in] handle_ptr   Pointer to the RPMI system controller context.
 * @param[in] tmon_inst    The top-level TMON instance.
 * @param[out] channel_ptr Points to TMON channel structure.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success. Returns an error code if
 *                    the handle is invalid or the TMON instance is out of range.
 */
p64h_err_t p64h_sysc_sys_tmon_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_tmon_inst_t tmon_inst, top_tvs_mon_stat_t* channel_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(p64h_sysc_rpmi_handle_valid(handle_ptr), P64H_ERR_INVALID_HANDLE);
    P64H_SYSC_ASSERT(tmon_inst < P64H_SYSC_TMON_INST_LAST, P64H_ERR_LIB_API_INVALID_PARAM);
    P64H_SYSC_ASSERT(NULL != channel_ptr, P64H_ERR_LIB_API_NULL_POINTER);

    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_TMON, (uint32_t)tmon_inst, 0x0u, 0x0u, NULL, 0x0u, channel_ptr,
                                   sizeof(*channel_ptr));
}
/// @}
