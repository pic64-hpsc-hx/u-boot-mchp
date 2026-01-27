/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * RISC-V platform management (RPMI) library for the platform firmware.
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

#ifndef LIBRPMI_H
#define LIBRPMI_H

#include <p64h_sysc_env.h>
#include <rpmi/librpmi_p64h_types.h>

/****************************************************************************/

/**
 * \addtogroup LIBRPMI_COMMON_INTERFACE RPMI Common Library Interface
 * @brief Common defines and structures for the RPMI library.
 * @{
 */

/**
 * Simple cache-coherent shared memory operations which use environment functions.
 *
 * Note: These operations don't require any platform specific data.
 */
extern struct rpmi_shmem_platform_ops rpmi_shmem_simple_ops;

/**
 * @brief Get base address of a shared memory
 *
 * @param[in] shmem		pointer to shared memory instance
 * @return base address of shared memory
 */
rpmi_uint64_t rpmi_shmem_base(const struct rpmi_shmem* shmem);

/**
 * @brief Get size of a shared memory
 *
 * @param[in] shmem		pointer to shared memory instance
 * @return size of shared memory in bytes
 */
rpmi_uint32_t rpmi_shmem_size(const struct rpmi_shmem* shmem);

/**
 * @brief Read a buffer from shared memory
 *
 * @param[in] shmem		pointer to shared memory instance
 * @param[in] offset		source offset within shared memory
 * @param[in] in		destination buffer pointer
 * @param[in] len		number of bytes to read
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_shmem_read(struct rpmi_shmem* shmem, rpmi_uint64_t offset, void* in, rpmi_uint32_t len);

/**
 * @brief Write a buffer to shared memory
 *
 * @param[in] shmem		pointer to shared memory instance
 * @param[in] offset		destination offset within shared memory
 * @param[in] out		source buffer pointer
 * @param[in] len		number of bytes to write
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_shmem_write(struct rpmi_shmem* shmem, rpmi_uint64_t offset, const void* out, rpmi_uint32_t len);

/**
 * @brief Fill a part of shared memory with fixed character
 *
 * @param[in] shmem		pointer to shared memory instance
 * @param[in] offset		offset within shared memory
 * @param[in] ch		character value to fill
 * @param[in] len		number of characters to fill
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_shmem_fill(struct rpmi_shmem* shmem, rpmi_uint64_t offset, char ch, rpmi_uint32_t len);

/**
 * @brief Create a shared memory instance
 *
 * @param[in] name		name of the shared memory instance
 * @param[in] base		base address of the shared memory
 * @param[in] size		size of the shared memory
 * @param[in] ops		pointer to platform specific shared memory operations
 * @param[in] ops_priv		pointer to private data of platform operations
 * @return pointer to RPMI shared memory instance upon success and NULL upon
 * failure
 */
struct rpmi_shmem* rpmi_shmem_create(const char* name, rpmi_uint64_t base, rpmi_uint32_t size, const struct rpmi_shmem_platform_ops* ops,
                                     void* ops_priv);

/**
 * @brief Destroy (of free) a shared memory instance
 *
 * @param[in] shmem		pointer to shared memory instance
 */
void rpmi_shmem_destroy(struct rpmi_shmem* shmem);

/**
 * @brief Read a buffer from io
 *
 * @param[in] io		pointer to io instance
 * @param[in] in		destination buffer pointer
 * @param[in] len		number of bytes to read
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_io_read(struct rpmi_io* io, void* in, rpmi_uint32_t len);

/**
 * @brief Write a buffer to io
 *
 * @param[in] io    	pointer to io instance
 * @param[in] out		source buffer pointer
 * @param[in] len		number of bytes to write
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_io_write(struct rpmi_io* io, const void* out, rpmi_uint32_t len);

/**
 * @brief Poll an io to see if it is empty of data
 *
 * @param[in] io    	pointer to io instance
 * @return enum rpmi_error
 */
rpmi_bool_t rpmi_io_is_empty(struct rpmi_io* io);

/** @} */

/*****************************************************************************/

/**
 * \addtogroup LIBRPMI_TRANSPORT_INTERFACE RPMI Transport Library Interface
 * @brief Global functions and data structures implemented by the RPMI library
 * for managing RPMI transport.
 * @{
 */

/**
 * @brief Check if a specified RPMI queue type of a RPMI transport is empty
 *
 * @param[in] trans		pointer to RPMI transport instance
 * @param[in] qtype		type of the RPMI queue
 * @return true if empty and false if not empty
 */
rpmi_bool_t rpmi_transport_is_empty(struct rpmi_transport* trans, enum rpmi_queue_type qtype);

/**
 * @brief Check if a specified RPMI queue type of a RPMI transport is full
 *
 * @param[in] trans		pointer to RPMI transport instance
 * @param[in] qtype		type of the RPMI queue
 * @return true if full and false if not full
 */
rpmi_bool_t rpmi_transport_is_full(struct rpmi_transport* trans, enum rpmi_queue_type qtype);

/**
 * @brief Enqueue a RPMI message to a specified RPMI queue type of a RPMI transport
 *
 * @param[in] trans		pointer to RPMI transport instance
 * @param[in] qtype		type of the RPMI queue
 * @param[in] msg		pointer to the enqueued RPMI message
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_transport_enqueue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* msg);

/**
 * @brief Dequeue a RPMI message from a specified RPMI queue type of a RPMI transport
 *
 * @param[in] trans		pointer to RPMI transport instance
 * @param[in] qtype		type of the RPMI queue
 * @param[out] out_msg		pointer to the dequeued RPMI message
 * @return enum rpmi_error
 */
enum rpmi_error rpmi_transport_dequeue(struct rpmi_transport* trans, enum rpmi_queue_type qtype, struct rpmi_message* out_msg);

/**
 * @brief Create a shared memory transport instance
 *
 * @param[in] name		name of the shared memory transport instance
 * @param[in] slot_size		size of message slot for queues in shared memory
 * @param[in] a2p_req_queue_size	size of A2P request and P2A acknowledgement queues
 * @param[in] p2a_req_queue_size	size of P2A request and A2P acknowledgement queues
 * @param[in] shmem		pointer to a RPMI shared memory instance
 * @return pointer to RPMI transport upon success and NULL upon failure
 */
struct rpmi_transport* rpmi_transport_shmem_create(const char* name, rpmi_uint32_t slot_size, rpmi_uint32_t a2p_req_queue_size,
                                                   rpmi_uint32_t p2a_req_queue_size, struct rpmi_shmem* shmem);

/**
 * @brief Destroy (of free) a shared memory transport instance
 *
 * @param[in] trans		pointer to RPMI transport instance
 */
void rpmi_transport_shmem_destroy(struct rpmi_transport* trans);

/** @} */

#endif /* LIBRPMI_H */
