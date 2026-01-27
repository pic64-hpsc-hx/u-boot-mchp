/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines types used for component header(stdhdr & bitshdr)
 */
#ifndef SEC_COMP_TYPES_H
#define SEC_COMP_TYPES_H

#include <stdint.h>
#include "sec_crypto_types.h" // for sec_signature_t

/**
 *  key mode used for BITS/KEYS component
 */
#define KM_DEFAULT_KLK      2u
#define KM_DEFAULT_FLK      6u
#define KM_USER_KEY1        3u
#define KM_USER_KEY2        4u

/**
 * Standard fields for all component types
 */
typedef struct stdhdr_t {

    uint64_t validator[4];             // use 64b to force alignment
    uint64_t msgid[2];                // 128b message id
    uint16_t bsver;
    uint8_t  ctype;
    uint8_t  keymode;
    uint8_t  options;
    uint8_t  reserved;
    uint16_t nframes;                  // not used in all component types
    uint64_t dsn[2];

} stdhdr_t;

/**
 * BITS component-specific fields
 */
typedef struct bitshdr_t{

    uint8_t  userdata[256];
    uint16_t deviceid;
    uint16_t devicemask;
    uint32_t devcap;
    uint8_t  designid[32];
    uint16_t designver;
    uint16_t swver;
    uint8_t  bsdigest[48];
    uint8_t  unused[4];
    uint8_t  iv[16];
    uint64_t hctr0[6];
    uint64_t hash[6];
    
    sec_signature_t signature;

} bitshdr_t;

/**
 * BITS component header
 */
typedef struct bits_header_t{
    stdhdr_t stdhdr;    ///< standard header parameters
    bitshdr_t bitshdr;  ///< BITS component specific parameters
} bits_header_t;

#endif /* SEC_COMP_TYPES_H */
