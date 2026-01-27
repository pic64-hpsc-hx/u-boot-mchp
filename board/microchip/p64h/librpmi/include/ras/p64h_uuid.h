/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_uuid.h
 * @brief
 *  UUID header
 * @addtogroup RASLIB
 * @{
 */
#ifndef P64H_UUID_H
#define P64H_UUID_H

#include <env/p64h_sysc_os_specific.h>

#define P64H_UUID_SIZE 16

typedef struct {
    uint8_t b[P64H_UUID_SIZE];
} p64h_guid_t;

typedef struct {
    uint8_t b[P64H_UUID_SIZE];
} p64h_uuid_t;

// clang-format off
#define P64H_GUID_INIT(a, b, c, d0, d1, d2, d3, d4, d5, d6, d7)                                                                                      \
    ((p64h_guid_t){                                                                                                                                  \
        {(a) & 0xff, ((a) >> 8) & 0xff, ((a) >> 16) & 0xff, ((a) >> 24) & 0xff, (b) & 0xff, ((b) >> 8) & 0xff, (c) & 0xff, ((c) >> 8) & 0xff, (d0), \
         (d1), (d2), (d3), (d4), (d5), (d6), (d7)} \
    })

#define P64H_UUID_INIT(a, b, c, d0, d1, d2, d3, d4, d5, d6, d7)                                                                                      \
    ((p64h_uuid_t){                                                                                                                                  \
        {((a) >> 24) & 0xff, ((a) >> 16) & 0xff, ((a) >> 8) & 0xff, (a) & 0xff, ((b) >> 8) & 0xff, (b) & 0xff, ((c) >> 8) & 0xff, (c) & 0xff, (d0), \
         (d1), (d2), (d3), (d4), (d5), (d6), (d7)} \
    })
// clang-format on

/*
 * The length of a UUID string ("aaaaaaaa-bbbb-cccc-dddd-eeeeeeeeeeee")
 * not including trailing NUL.
 */
#define P64H_UUID_STRING_LEN 36

static inline bool guid_equal(const p64h_guid_t* u1, const p64h_guid_t* u2)
{
    return memcmp(u1, u2, sizeof(p64h_guid_t)) == 0;
}

static inline void guid_copy(p64h_guid_t* dst, const p64h_guid_t* src)
{
    memcpy(dst, src, sizeof(p64h_guid_t));
}

static inline void import_guid(p64h_guid_t* dst, const uint8_t* src)
{
    memcpy(dst, src, sizeof(p64h_guid_t));
}

static inline void export_guid(uint8_t* dst, const p64h_guid_t* src)
{
    memcpy(dst, src, sizeof(p64h_guid_t));
}

static inline bool uuid_equal(const p64h_uuid_t* u1, const p64h_uuid_t* u2)
{
    return memcmp(u1, u2, sizeof(p64h_uuid_t)) == 0;
}

static inline void uuid_copy(p64h_uuid_t* dst, const p64h_uuid_t* src)
{
    memcpy(dst, src, sizeof(p64h_uuid_t));
}

static inline void import_uuid(p64h_uuid_t* dst, const uint8_t* src)
{
    memcpy(dst, src, sizeof(p64h_uuid_t));
}

static inline void export_uuid(uint8_t* dst, const p64h_uuid_t* src)
{
    memcpy(dst, src, sizeof(p64h_uuid_t));
}

#endif