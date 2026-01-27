/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_system.c
 * @brief System API implementation
 * @addtogroup SYSTEM_API
 * @ingroup p64h_sysc_api
 * @{
 */
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
    rpmi_enable_notification_t enable_notification = { 0x0u, 0x0u };
    enable_notification.eid                        = (uint32_t)eid;
    enable_notification.req_state                  = (uint32_t)0x1u; // 1 = enable

    if (p64h_sysc_rpmi_evt_enable(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, eid, (p64h_sysc_evt_fct_t)sys_evt_fct) == false) {
        return P64H_ERR_SVC_EM_UNEXPECTED_EVENT;
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
    rpmi_enable_notification_t enable_notification = { 0x0u, 0x0u };
    enable_notification.eid                        = (uint32_t)eid;
    enable_notification.req_state                  = (uint32_t)0x0u; // 0 = disable

    if (p64h_sysc_rpmi_evt_disable(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, eid) == false) {
        return P64H_ERR_SVC_EM_UNEXPECTED_EVENT;
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
 * @param[out] enabled_ptr false : Notification is disabled, true: Notification is enabled.
 * @return p64h_err_t Returns P64H_ERR_OK if the operation is successful.
 */
p64h_err_t p64h_sysc_sys_evt_state_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid, bool* enabled_ptr)
{
    rpmi_enable_notification_t enable_notification = { 0x0u, 0x0u };
    enable_notification.eid                        = (uint32_t)eid;
    enable_notification.req_state                  = (uint32_t)0x2u;
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_ENABLE_NOTIFICATION, P64H_SYSC_RPMI_CID_GET(handle_ptr), 0x0u, 0x0u,
                                   &enable_notification, sizeof(enable_notification), enabled_ptr, sizeof(*enabled_ptr));
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_INFO, 0x0u, 0x0u, 0x0u, NULL, 0x0u, sys_info_ptr,
                                   sizeof(*sys_info_ptr));
}

/**
 * @brief Retrieves system attributes.
 *
 * This function is responsible for obtaining the system attributes and
 * storing them in the provided pointer to a p64h_sysc_sys_attr_t structure.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] sys_attr_ptr Pointer to a p64h_sysc_sys_attr_t structure where the
 *                     system attributes will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_attr_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sys_attr_t* sys_attr_ptr)
{
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_ATTRIBUTES, 0x0u, 0x0u, 0x0u, NULL, 0x0u, sys_attr_ptr,
                                   sizeof(*sys_attr_ptr));
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_LOG_INFO, 0x0u, 0x0u, 0x0u, NULL, 0x0u, log_info_ptr,
                                   sizeof(*log_info_ptr));
}

/**
 * @brief Sets the system log configuration for a given log ID.
 *
 * This function configures the system log settings based on the provided log ID and configuration pointer.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] lid The log ID for which the configuration is to be set.
 * @param[in] cfg_ptr Pointer to the configuration settings to be applied.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_log_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_log_id_t lid, const p64h_sysc_sys_log_cfg_t* cfg_ptr)
{
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
        *current_write_offset_ptr = *resp_offset_ptr + *bytes_read_ptr + entries_left;
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_APPC_BOOT_CFG, 0x0u, 0x0u, 0x0u, NULL, 0x0u, cfg_ptr,
                                   sizeof(*cfg_ptr));
}

/**
 * @brief Retrieves the boot status of the specified application configuration.
 *
 * This function fetches the boot status for a given boot configuration ID (bid) and stores
 * the result in the provided status pointer (status_ptr).
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] bid The boot configuration ID for which the status is to be retrieved.
 * @param[out] status_ptr Pointer to a variable where the boot status will be stored.
 *
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_sys_appc_boot_status_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_boot_cfg_id_t bid,
                                              p64h_sysc_appc_boot_cfg_status_t* status_ptr)
{
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_APPC_BOOT_STATUS, (uint32_t)bid, 0x0u, 0x0u, NULL, 0x0u,
                                   status_ptr, sizeof(*status_ptr));
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_APPC_BOOT_CFG, 0x0u, 0x0u, 0x0u, &bid, sizeof(bid), NULL, 0x0u);
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
 */
p64h_err_t p64h_sysc_sys_pwr_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pwr_cfg_t* cfg_ptr)
{
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_DEV_TRACE_CONFIG, 0x0u, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr),
                                   NULL, 0x0u);
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
p64h_err_t p64h_sysc_sys_fw_download(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_fw_dump_cfg_t* cfg_ptr, void* data_ptr, size_t size,
                                     bool shmem_xfer)
{
    return p64h_sysc_rpmi_resp_with_data(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_FW_DOWNLOAD, 0x0u, 0x0u, 0x0u, cfg_ptr, sizeof(*cfg_ptr),
                                         data_ptr, size, shmem_xfer);
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
 */
p64h_err_t p64h_sysc_sys_time_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_time_t* time_ptr)
{
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_TIME, 0x0u, 0x0u, 0x0u, NULL, 0x0u, time_ptr, sizeof(*time_ptr));
}

/**
 * @brief Sets the system programmer clock configuration.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] clk_id Clock ID of which to set the configuration of.
 * @param[in] cfg_ptr Pointer to the programmer clock configuration structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_pgmrclk_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pgmrclk_id_t clk_id, const p64h_pgmrclk_cfg_t* cfg_ptr)
{
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_CFM_MEAS_CNT, (uint32_t)cfm_inst, 0x0u, 0x0u, NULL, 0x0u,
                                   count_ptr, sizeof(*count_ptr));
}

/**
 * @brief Set FW PLL support measurement configuration.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] fw_pll_cfg_ptr Points to FW PLL configuration structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_fw_pll_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pll_cfg_t* fw_pll_cfg_ptr)
{
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_SET_FW_PLL_CFG, 0x0u, 0x0u, 0x0u, fw_pll_cfg_ptr,
                                   sizeof(*fw_pll_cfg_ptr), NULL, 0x0u);
}

/**
 * @brief Get FW PLL support measurement timestamps.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[out] timestamp_ptr Points to FW PLL timestamp structure.
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_sys_fw_pll_timestamp_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_fw_pll_timestamp_t* timestamp_ptr)
{
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_GET_FW_PLL_TIMESTAMP, 0x0u, 0x0u, 0x0u, NULL, 0x0u, timestamp_ptr,
                                   sizeof(*timestamp_ptr));
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
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_APPC_DTB_FIXUP, 0x0u, 0x0u, 0x0u, &dtb_addr, sizeof(dtb_addr), NULL,
                                   0x0u);
}

/**
 * @brief Fetch the contents of the M1 scratchregisters for SysC.
 *
 * @param[in] handle_ptr Pointer to the RPMI system controller context.
 * @param[in] m1_dump_ptr Pointer to the M1 content
 * @return p64h_err_t Error code indicating the result of the operation.
 */
p64h_err_t p64h_sysc_m1_dump(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_m1_dump_t* m1_dump_ptr)
{
    return p64h_sysc_rpmi_req_resp(handle_ptr, P64H_RPMI_SRVGRP_SYSTEM, P64H_SYS_M1_DUMP, 0x0u, 0x0u, 0x0u, NULL, 0x0, m1_dump_ptr,
                                   sizeof(p64h_sysc_m1_dump_t));
}
/// @}
