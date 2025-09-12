/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */
/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

/**
 * @file  p64h_sysc_env.h
 * @brief ENV API
 * @{
 */

#ifndef P64H_SYSC_ENV_H
#define P64H_SYSC_ENV_H

#include <env/p64h_sysc_os_specific.h>
#include <rpmi/librpmi_p64h_types.h>
#include <rpmi/librpmi_mchp.h>

/**
 * @brief compare memory from one place to another
 *
 * @param[in] s1	pointer to src1
 * @param[in] s2	pointer to src2
 * @param[in] n		number of bytes to compare
 * @return void *	Pointer to destination
 */
int rpmi_env_memcmp(void* s1, void* s2, rpmi_size_t n);

/**
 * @brief Copy memory from one place to another
 *
 * @param[in] dest 	pointer to destination
 * @param[in] src 	pointer to destination
 * @param[in] n 	number of bytes to copy
 * @return void *	Pointer to destination
 */
void* rpmi_env_memcpy(void* dest, const void* src, rpmi_size_t n);

/**
 * @brief Write or fill a memory range with a character
 *
 * @param[in] dest 	pointer to destination
 * @param[in] c 	character to write of fill
 * @param[in] n 	number of bytes to write
 * @return void *	Pointer to destination
 */
void* rpmi_env_memset(void* dest, char c, rpmi_size_t n);

/**
 * @brief Get length of a fixed size string
 *
 * @param[in] dest	pointer to string buffer
 * @param[in] count	number of max chars to count
 * @return rpmi_size_t  number of chars in string limited by count
 */
rpmi_size_t rpmi_env_strnlen(const char* str, rpmi_size_t count);

/**
 * @brief Copy string limited by count
 *
 * @param[in] dest	pointer to string destination buffer
 * @param[in] src	pointer to string source buffer
 * @param[in] count	number of max chars to count
 * @return char *	pointer to string destination buffer
 */
char* rpmi_env_strncpy(char* dest, const char* src, rpmi_size_t count);

/** @} */

/******************************************************************************/

/**
 * \defgroup CACHE_ENV Cache Maintenance Functions
 * @brief Cache maintenance functions used by library which must be provided by the
 * platform firmware.
 * @{
 */

/**
 * @brief Invalidate cache lines based on virtual address range
 *
 * @param[in] base	pointer to base virtual address
 * @param[in] len	number of bytes to invalidate
 */
void rpmi_env_cache_invalidate(void* base, rpmi_size_t len);

/**
 * @brief Clean cache lines based on virtual address range
 *
 * @param[in] base	pointer to base virtual address
 * @param[in] len	number of bytes to clean
 */
void rpmi_env_cache_clean(void* base, rpmi_size_t len);

/** @} */

/******************************************************************************/

/**
 * \defgroup HEAP_ENV Heap Environment Functions
 * @brief Memory allocation functions used by library which must be provided by the
 * platform firmware.
 * @{
 */

/**
 * @brief Dynamically allocate zero initialized memory of specified size
 *
 * @param[in] size 	Size(bytes) of the memory block to be allocated
 * @return void *	Pointer to the allocated memory block
 */
void* rpmi_env_zalloc(rpmi_size_t size);

/**
 * @brief Dynamically free the memory pointer to by ptr
 *
 * @param[in] ptr 	Pointer to memory
 */
void rpmi_env_free(void* ptr);

/** @} */

/******************************************************************************/

/**
 * \defgroup LOCKING_ENV Locking Environment Functions
 * @brief Locking functions used by library which must be provided by the platform firmware.
 * @{
 */

/**
 * @brief Dynamically allocate a lock for synchronization
 *
 * Note: If locking is not supported then this function will always return NULL.
 *
 * @return void *	Pointer to the allocated lock
 */
void* rpmi_env_alloc_lock(void);

/**
 * @brief Dynamically free a lock
 *
 * Note: This function does nothing if lock pointer is NULL.
 *
 * @param[in] lptr 	Pointer to lock
 */
void rpmi_env_free_lock(void* lptr);

/**
 * @brief Acquire a lock
 *
 * Note: This function does nothing if lock pointer is NULL.
 *
 * @param[in] lptr 	Pointer to lock
 */
void rpmi_env_lock(void* lptr);

/**
 * @brief Release a lock
 *
 * Note: This function does nothing if lock pointer is NULL.
 *
 * @param[in] lptr 	Pointer to lock
 */
void rpmi_env_unlock(void* lptr);

/** @} */

/******************************************************************************/

/**
 * \defgroup MATH_ENV Integer Math Environment Functions
 * @brief Basic math functions for 32/64 bit integers to be implemented by the
 * platform firmware.
 * @{
 */

/**
 * @brief 32-bit Division Operation
 *
 * @param[in] dividend
 * @param[in] divisor
 * @return rpmi_uint32_t
 */
rpmi_uint32_t rpmi_env_div32(rpmi_uint32_t dividend, rpmi_uint32_t divisor);

/**
 * @brief 32-bit Modulo Operation
 *
 * @param[in] dividend
 * @param[in] divisor
 * @return rpmi_uint32_t
 */
rpmi_uint32_t rpmi_env_mod32(rpmi_uint32_t dividend, rpmi_uint32_t divisor);

/** @} */

/******************************************************************************/

/**
 * \defgroup ENDIAN_ENV Endian Conversion Environment Functions
 * @brief Basic math functions for 32/64 bit integers to be implemented by the
 * platform firmware.
 * @{
 */

#define BSWAP16(x) ((((x) & 0x00ff) << 8) | (((x) & 0xff00) >> 8))
#define BSWAP32(x) ((((x) & 0x000000ff) << 24) | (((x) & 0x0000ff00) << 8) | (((x) & 0x00ff0000) >> 8) | (((x) & 0xff000000) >> 24))

rpmi_uint16_t rpmi_to_le16(rpmi_uint16_t val);
rpmi_uint32_t rpmi_to_le32(rpmi_uint32_t val);
rpmi_uint16_t rpmi_to_be16(rpmi_uint16_t val);
rpmi_uint32_t rpmi_to_be32(rpmi_uint32_t val);

/**
 * @brief Convert endianness of 16-bit integer based on parameter
 *
 * @param[in] is_be	Target endianness (true: Big-endian, false: Little-endian)
 * @param[in] val	16-bit integer value
 * @return rpmi_uint16_t Endian converted value
 */
rpmi_uint16_t rpmi_to_xe16(rpmi_bool_t is_be, rpmi_uint16_t val);

/**
 * @brief Convert endianness of 32-bit integer based on parameter
 *
 * @param[in] is_be	Target endianness (true: Big-endian, false: Little-endian)
 * @param[in] val	32-bit integer value
 * @return rpmi_uint32_t Endian converted value
 */
rpmi_uint32_t rpmi_to_xe32(rpmi_bool_t is_be, rpmi_uint32_t val);

/** @} */

/******************************************************************************/

/**
 * \defgroup MMIO_ENV MMIO Read/Write Environment Functions
 * @brief System-wide memory mapped input/output (MMIO) read/write functions
 * to be implemented by the platform firmware.
 * @{
 */

/**
 * @brief Write 4-bytes to address in little-endian byte-order
 *
 * @param[in] addr	64-bit address
 * @param[in] val	4-byte data to write
 */
void rpmi_env_writel(rpmi_uint64_t addr, rpmi_uint32_t val);

/** @} */

/******************************************************************************/

/**
 * \defgroup CONSOLE_ENV Console Environment Functions
 * @brief Console functions for logging purpose to be implemented by the platform firmware.
 * @{
 */
#ifndef __printf
#define __printf(a, b) __attribute__((format(printf, a, b)))
#endif

/**
 * @brief Print a formatted string on console
 *
 * @param[in] format	Formatted stdio string
 * @return 0 upon success and negative error (< 0) upon failure
 */
int __printf(1, 2) rpmi_env_printf(const char* format, ...);

/** @} */

/**
 * \defgroup Platform-Specific Communication Functions
 * @brief Communication functions used by QEMU to interact with SYSC through RPMI
 * @{
 */

/**
 * @brief Read from io
 *
 * @param[in] priv     Descriptor reference
 * @param[in] in       Buffer where read data is stored
 * @param[in] len      Message length to read
 * @return RPMI_SUCCESS upon success
 */
rpmi_error_t rpmi_env_io_read(void* priv, void* in, rpmi_uint32_t len);

/**
 * @brief Write to io
 *
 * @param[in] priv     Descriptor reference
 * @param[in] out      Buffer from which to write data
 * @param[in] len      Message length to write
 * @return RPMI_SUCCESS upon success
 */
rpmi_error_t rpmi_env_io_write(void* priv, const void* out, rpmi_uint32_t len);

/**
 * @brief Poll the IO to see if it is empty
 *
 * @param[in] priv     Descriptor reference
 * @return True if empty, false otherwise
 */
rpmi_bool_t rpmi_env_io_is_empty(void* priv);

/**
 * @brief Initialise IO
 *
 * @param[in] cid      The RPMI context id
 * @param[in] port_ptr Reference to the rpmi io port
 * @return false upon failure, true upon success
 */
rpmi_bool_t rpmi_env_io_init(const uint32_t cid, const rpmi_io_port_t* port_ptr);

/** @} */

/**
 * \defgroup Context allocation Functions
 * @brief Context allocation functions used by library
 * @{
 */

/**
 * @brief Allocate the memory of context
 *
 * @return rpmi_client_ctxt_t *	Pointer to the context
 */
rpmi_client_ctxt_t* rpmi_ctxt_malloc(void);

/**
 * @brief Environment implementation of microseconds sleep
 *
 * @param[in] msec Number of microseconds to sleep
 * @return false upon failure, true upon success
 */
rpmi_bool_t rpmi_env_msec_sleep(const uint32_t msec);

/** @} */

/**
 * \defgroup Task Information Functions
 * @brief Task information functions used by library
 * @{
 */

/**
 * @brief Get task ID
 *
 * @return uint32_t	task ID
 */
uint32_t rpmi_env_task_id_get(void);
/** @} */
#endif /* P64H_SYSC_ENV_H */
