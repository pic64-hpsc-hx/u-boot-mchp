/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_crypto_types.h
 * @brief Crypto type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_CRYPTO_TYPE_H
#define P64H_SYSC_CRYPTO_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_errors.h>
#include <zsbl/sysc_flash_helper.h>

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_CRYPTO_SHA_BYTE_SIZE_MAX      64   ///< maximum number of bytes for hash
#define P64H_SYSC_CRYPTO_EC_SIG_R_BYTE_SIZE_MAX 48   ///< Raw EC(r) signature length
#define P64H_SYSC_CRYPTO_EC_SIG_S_BYTE_SIZE_MAX 48   ///< Raw EC(s) signature length
#define P64H_SYSC_CRYPTO_EC_SIG_BYTE_SIZE_MAX   96   ///< Raw EC signature length(r + s)
#define P64H_SYSC_CRYPTO_PQ_SIG_BYTE_SIZE_MAX   4627 ///< Raw PQ signature length
#define P64H_SYSC_CRYPTO_PQ_PUB_KEY_SIZE_MAX    2592 ///< Raw PQ signature length

/* Public Structs and Enums --------------------------------------- */

/// crypto event identifier
typedef enum {
    P64H_SYSC_CRYPTO_EVT_ID_OP = 1, ///< operaton completed event
} p64h_sysc_crypto_evt_id_t;

/// crypto Advanced Encryption Standard (AES) mode
typedef enum {
    P64H_SYSC_CRYPTO_AES_MODE_ECB = 0, ///< Electronic Codebook (ECB)
    P64H_SYSC_CRYPTO_AES_MODE_CBC,     ///< Cipher block chaining (CBC)
    P64H_SYSC_CRYPTO_AES_MODE_CTR,     ///< Counter (CTR)
    P64H_SYSC_CRYPTO_AES_MODE_OFB,     ///< Output Feedback (OFB)
    P64H_SYSC_CRYPTO_AES_MODE_CFB,     ///< Cipher Feedback (CFB)
    P64H_SYSC_CRYPTO_AES_MODE_GCM,     ///< Galois/Counter Mode (GCM)
    P64H_SYSC_CRYPTO_AES_MODE_CMAC,    ///< Cipher-based Message Authentication Code (CMAC)
    P64H_SYSC_CRYPTO_AES_MODE_LAST
} p64h_sysc_crypto_aes_mode_t;

typedef enum {
    P64H_SYSC_CRYPTO_KEY_ID_HMAC = 0, ///< HMAC key
    P64H_SYSC_CRYPTO_KEY_ID_KMAC,     ///< KMAC key
    P64H_SYSC_CRYPTO_KEY_ID_ECHC,     ///< ECHC key
    P64H_SYSC_CRYPTO_KEY_ID_ECDSAD,   ///< ECDSAD
    P64H_SYSC_CRYPTO_KEY_ID_ECDSAK,   ///< ECDSAK
    P64H_SYSC_CRYPTO_KEY_ID_LAST
} p64h_sysc_crypto_key_id_t;

/// Crypto operation type
typedef enum {
    P64H_SYSC_CRYPTO_OP_AES = 0, ///< Advanced Encryption Standard (AES)
    P64H_SYSC_CRYPTO_OP_SHA,     ///< Hash operation
    P64H_SYSC_CRYPTO_OP_SIGN,    ///< signature/verify operation
    P64H_SYSC_CRYPTO_OP_LAST
} p64h_sysc_crypto_op_type_t;

/// crypto SHA mode
typedef enum {
    P64H_SYSC_CRYPTO_SHA_MODE_SHA2_224,          ///< SHA2-224
    P64H_SYSC_CRYPTO_SHA_MODE_SHA2_256,          ///< SHA2-256
    P64H_SYSC_CRYPTO_SHA_MODE_SHA2_384,          ///< SHA2-384
    P64H_SYSC_CRYPTO_SHA_MODE_SHA2_512,          ///< SHA2-512
    P64H_SYSC_CRYPTO_SHA_MODE_SHA2_512_224,      ///< SHA2-512/224
    P64H_SYSC_CRYPTO_SHA_MODE_SHA2_512_256,      ///< SHA2-512/256
    P64H_SYSC_CRYPTO_SHA_MODE_HMAC_SHA2_224,     ///< HMAC SHA2-224
    P64H_SYSC_CRYPTO_SHA_MODE_HMAC_SHA2_256,     ///< HMAC SHA2-256
    P64H_SYSC_CRYPTO_SHA_MODE_HMAC_SHA2_384,     ///< HMAC SHA2-384
    P64H_SYSC_CRYPTO_SHA_MODE_HMAC_SHA2_512,     ///< HMAC SHA2-512
    P64H_SYSC_CRYPTO_SHA_MODE_HMAC_SHA2_512_224, ///< HMAC SHA2-512/224
    P64H_SYSC_CRYPTO_SHA_MODE_HMAC_SHA2_512_256, ///< HMAC SHA2-512/256
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_224,          ///< SHA3-224
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_256,          ///< SHA3-256
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_384,          ///< SHA3-384
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_512,          ///< SHA3-512
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_SHAKE128,     ///< SHA3-SHAKE-128
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_SHAKE256,     ///< SHA3-SHAKE-256
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_KMAC128,      ///< SHA3-KMAC-128
    P64H_SYSC_CRYPTO_SHA_MODE_SHA3_KMAC256,      ///< SHA3-KMAC-256
    P64H_SYSC_CRYPTO_SHA_MODE_LAST
} p64h_sysc_crypto_sha_mode_t;

/// crypto signature operation
typedef enum {
    P64H_SYSC_CRYPTO_SIGN_MODE_ECDSA = 0, ///< Elliptic Curve Digital Signature Algorithms (ECDSA)
    P64H_SYSC_CRYPTO_SIGN_MODE_PQMLDSA,   ///< digital signature: Crystals-dilithium lattice
    P64H_SYSC_CRYPTO_SIGN_MODE_DUAL,      ///< dual ECDSA/PQMLDSA signature
    P64H_SYSC_CRYPTO_SIGN_MODE_LAST
} p64h_sysc_crypto_sign_mode_t;

/// crypto buffer descriptor
typedef struct {
    uint64_t addr; ///< addr of the buffer
    uint64_t size; ///< size of the buffer
} p64h_sysc_crypto_buf_desc_t;

/**
 * An EC P-384 signature output structure.
 **/

typedef struct {
    uint64_t r[P64H_SYSC_CRYPTO_EC_SIG_R_BYTE_SIZE_MAX / sizeof(uint64_t)];
    uint64_t s[P64H_SYSC_CRYPTO_EC_SIG_S_BYTE_SIZE_MAX / sizeof(uint64_t)];
} ec_sig_t;

typedef struct {
    uint8_t pub[P64H_SYSC_CRYPTO_PQ_PUB_KEY_SIZE_MAX];
} mldsa_pubkey_t;

typedef struct {
    uint8_t pq_sig[P64H_SYSC_CRYPTO_PQ_SIG_BYTE_SIZE_MAX];
} pq_sig_t;

/// crypto sig verify
typedef struct {
    uint8_t*        msg;       ///< addr of the buffer
    uint64_t        msg_len;   ///< size of the buffer
    ec_sig_t        ec_sig;    ///< signature of the buffer
    sec_ec_pubkey_t ec_pubkey; ///< EC Public key
    pq_sig_t        pq_sig;    ///< PQ signature of the buffer
    mldsa_pubkey_t  pq_pubkey; ///< PQ Public key
} p64h_sysc_crypto_sig_verify_t;

/// crypto signature operation
typedef struct {
    p64h_sysc_crypto_sign_mode_t mode; ///< see p64h_sysc_crypto_sign_mode_t
    bool                         sign; ///< true=sign, false=verify
    p64h_sysc_crypto_buf_desc_t  buf;  ///< buffer descriptor
} p64h_sysc_crypto_sign_op_t;

/// crypto key configuration
typedef struct {
    uint32_t place_holder; ///< key config
} p64h_sysc_crypto_key_cfg_t;

/// crypto sha operation
typedef struct {
    p64h_sysc_crypto_sha_mode_t sha_mode; ///< sha mode
    p64h_sysc_crypto_buf_desc_t buffer;   ///< buffer descriptor
} p64h_sysc_crypto_sha_op_t;

///< crypto AES operation
typedef struct {
    p64h_sysc_crypto_aes_mode_t mode;    ///< some required to have a key loaded
    bool                        encrypt; ///< true: encrypt, false: decrypt
    p64h_sysc_crypto_buf_desc_t buf;     ///< buffer descriptor
} p64h_sysc_crypto_aes_op_t;

///< secure hash algorithm (SHA buffer
typedef struct {
    uint8_t hash[P64H_SYSC_CRYPTO_SHA_BYTE_SIZE_MAX]; ///< the sha buffer
    uint8_t size;                                     ///< the size of the hash in byte
} p64h_sysc_crypto_hash_t;

///< EC/PQ dual signature
typedef struct {
    ec_sig_t ec_sig;                                        ///< EC signature
    uint64_t ec_sig_size;                                   ///< EC signature length
    uint8_t  pq_sig[P64H_SYSC_CRYPTO_PQ_SIG_BYTE_SIZE_MAX]; ///< PQ MLDSA-87 signature
    uint64_t pq_sig_size;                                   ///< PQ signature length
} p64h_sysc_crypto_sign_t;

///< union of crypto operations
typedef union {
    p64h_sysc_crypto_sha_op_t  sha;  ///< sha operation
    p64h_sysc_crypto_aes_op_t  aes;  ///< aes operation
    p64h_sysc_crypto_sign_op_t sign; ///< sign operation
} p64h_sysc_crypto_op_t;

///< crypto event
typedef struct {
    p64h_sysc_crypto_op_type_t op_type; ///< type of operation
    p64h_sysc_crypto_op_t      op;      ///< operation
} p64h_sysc_crypto_evt_t;

/// function pointer type for CRYPTO event notification
typedef void (*p64h_sysc_crypto_evt_fct_t)(const p64h_sysc_crypto_evt_t* evt_ptr);

#endif // P64H_SYSC_CRYPTO_TYPE_H

/// @}
