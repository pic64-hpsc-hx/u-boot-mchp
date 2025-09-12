/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines types used for component data
 */
#ifndef SEC_CRYPTO_TYPES_H
#define SEC_CRYPTO_TYPES_H

#include "sec_api_types.h"
#include "sec_otp_types.h"

/// Dilithium Signature Length returned in attestation report
//#define DILITHIUM_SIG_SIZE_BYTES                (4595u+32u)
#define PQS_MLDSA87_SIGN_SIZE  (4627u)

/// KEYS component UMASK bit definitions
#define KEYS_UDATA0_BIT_SHIFT   (0u)
#define KEYS_UDATA1_BIT_SHIFT   (1u)
#define KEYS_UDATA2_BIT_SHIFT   (2u)
#define KEYS_UDATA3_BIT_SHIFT   (3u)

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

/**
 * Keys component-specific header
 */
typedef struct keyshdr_t{

    uint8_t userdata[256];  // not used
    uint8_t iv[16];
    uint64_t hctr0[6];

} keyshdr_t;

/**
 * KEYS component header
 */
typedef struct keys_header_t{

    stdhdr_t stdhdr;   ///< standard header parameters
    keyshdr_t keyshdr; ///< KEYS component specific parameters

} keys_header_t;


/**
 * Structure of a KEYS component UDATA0 record
 */
typedef struct config_keys_udata0_t{

    uint64_t upk1[6];
    uint64_t dpk[6];
    uint64_t uk1[6];
    uint64_t uk2[6];
    sec_ec_pq_pubkey_t ubqec_pq;

} config_keys_udata0_t;


/**
 * Structure of a KEYS component UDATA1 record
 */
typedef struct config_keys_udata1_t{

    lockset_feature_t  lockset;                 /**< ULOCK[63:0] **/
    sec_ec_pq_pubkey_t ubq2ec_pq;
} config_keys_udata1_t;

/**
 * Structure of a KEYS component storing Key Hashes in UDATA2 record
 */
typedef struct {
    // hashset contains pre-loaded hash of "payload"
    // This pre-loaded hash will be compared with calculated hash & verified for integrity
    hashset_t hashset; ///< hashset entry to be written into OTP

    /// @note JMB data access width is 4 bytes, so sven if the payload_size is not a multiple
    // of 4 we still read data from mbox at word(4 byte) granularity.
    // payload_size must be at dword(8 byte) boundary because of sha3 requires buffer sizes in multiples of nwords64
    uint32_t payload_size; ///< Sizeof data present in payload_ptr

    // Data for which the hash needs to be calculated by FW. This calculated hash
    // will be compared & verified with the pre-calculated hash received in
    // hashset.hash before writing to OTP
    /// @note DILITHIUM_PUBLIC_KEY_SIZE_BYTES is the maximum Pubkey size possible
    // therefore declared payload to be of 2592 bytes
    uint64_t payload[DILITHIUM_PUBLIC_KEY_SIZE_BYTES/8u]; ///< keys/data for which hash need to be calculated & stored in OTP

} config_keys_udata2_t;

#ifdef SECC
static_assert(offsetof(config_keys_udata2_t, payload_size) == 52, "payload_size is not at offset of 52 bytes");
static_assert(offsetof(config_keys_udata2_t, payload) == 56, "payload[] is not at offset of 56 bytes");
#endif

/**
 * Structure of a KEYS component UDATA3 record
 */
typedef struct config_keys_udata3_t{
    uperm_feature_t uperm;
    uint32_t reserved;
} config_keys_udata3_t;

/**
 * Structure of a KEYS component UDATA4 record
 */
typedef struct config_keys_udata4_t{

    // hashset contains pre-loaded hash of "payload"
    // This pre-loaded hash will be compared with calculated hash & verified for integrity
    hashset_t hashset; ///< hashset entry that is expected to have matching entry in OTP

} config_keys_udata4_t;

/**
 * Structure of a KEYS component UDATA5 record
 */
typedef struct config_keys_udata5_t{

    lockset_secure_debug_enable_t enable;
} config_keys_udata5_t;

/**
 * Structure of a KEYS component
 * Note: the payload is ciphertext.
 *
 *       Payload
 * _____________________
 * |   UMASK [31:0]    | 
 * | RESERVED [127:32] |
 * |      UDATAx       |
 * |      UDATAy       |
 * |       ...         |
 * |      UPAD         |
 * ---------------------
 */
typedef struct keys_comp_t{

    keys_header_t hdr;
    // note: the first 4 bytes of the payload are the KEYMASK which specifies which UDATA blocks are part of the payload.
    //       the next 4 bytes are reserved
    uint64_t payload[9u*1024u/8u]; // the keys component is less than 9KB, therefore the remaining payload is padded with 0s
    uint64_t cnext[6];

} keys_comp_t;

#endif /* SEC_CRYPTO_TYPES_H */
