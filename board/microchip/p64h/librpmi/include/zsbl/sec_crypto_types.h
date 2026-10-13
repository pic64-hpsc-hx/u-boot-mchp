/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines crypto types for signature & pubkey
 */
#ifndef SEC_CRYPTO_TYPES_H
#define SEC_CRYPTO_TYPES_H


/// ECDSA Signature Length returned in attestation report
#define ECDSA_SIG_SIZE_BYTES                    96u
/// ECDSA Signature Length in DER format
#define ECDSA_SIG_SIZE_BYTES_DER                (ECDSA_SIG_SIZE_BYTES + 8u)
/// Dilithium Signature Length returned in attestation report
#define DILITHIUM_SIG_SIZE_BYTES                (4595u+32u)
/// Dilithium Signature in DER format
#define DILITHIUM_SIG_SIZE_BYTES_DER            (DILITHIUM_SIG_SIZE_BYTES + 5u)
/// ECDSA Public key size
#define ECDSA_PUBLIC_KEY_SIZE_BYTES             96u
/// Dilithum Public key size
#define DILITHIUM_PUBLIC_KEY_SIZE_BYTES         2592u

#define PQS_MLKEM_1024_CT_SIZE 1568u
#define PQS_MLDSA87_SIGN_SIZE  (4627u)
#define PQS_MLDSA87_SIGN_SIZE_DER  (PQS_MLDSA87_SIGN_SIZE + 5u)

/**
 * @brief
 *  Bit map definitions to be used for cmd_args field in sec_mbox_cmd_req_msg_t for sign verify cmds
 *
 */
typedef enum {
    SEC_EC_SIGN_VERIFY_MASK              = (1u << 0),  ///< EC signature verify bit mask
    SEC_PQ_SIGN_VERIFY_MASK              = (1u << 1),  ///< PQ signature verify bit mask
    SEC_SYSC_IMAGE_ENCRYPTED_VERIFY_MASK = (1UL << 9), ///< Sysc image encryption mask
} sec_signature_verify_cmd_mask;


/**
 * An EC P-384 public key.
 */
typedef struct {

    uint32_t x[12]; ///< EC Pub Key x co-ordinate
    uint32_t y[12]; ///< EC Pub Key y co-ordinate

} sec_ec_pubkey_t;

/**
 * PQ public key struct
 */
typedef struct {

    uint8_t pub[DILITHIUM_PUBLIC_KEY_SIZE_BYTES];      ///< FIX: temporary container of the correct size

} sec_dilithium5_pubkey_t;

/** 
 * @brief
 *  Define EC & PQ signatures structure for the image header
 *  The hashes of the keys used here are to be put into HASHSET entry in OTP as part of factory provisioning using KEYS component
 */
typedef struct signature_ec_pq_t
{
  sec_ec_pubkey_t ecpubkey;                          ///< EC public key
  sec_dilithium5_pubkey_t pqpubkey;                  ///< PQ public key
  uint8_t ecsignature[ECDSA_SIG_SIZE_BYTES];         ///< signature array for NIST P-384
  uint8_t pqsignature[PQS_MLDSA87_SIGN_SIZE];     ///< signature array for Dilithium5
  uint8_t pad[5];                                    ///< padding for 64-bit alignment
} signature_ec_pq_t;

typedef struct sec_ec_pq_pubkey_t{

    sec_ec_pubkey_t ecpubkey;           ///< EC public key
    sec_dilithium5_pubkey_t pqpubkey;   ///< PQ public key

} sec_ec_pq_pubkey_t;


/**
 * EC & PQ signature data struct
 */
typedef struct sec_signature_t {
        sec_ec_pq_pubkey_t sig_keys; ///< EC & PQ public keys
        uint8_t ecsig0[48];          ///< ECDSA signature r component
        uint8_t ecsig1[48];          ///< ECDSA signature s component
        uint8_t pqsig[PQS_MLDSA87_SIGN_SIZE]; ///< PQ Dilithium5 signature
        uint8_t reserved[13];        ///< padding
} sec_signature_t;
#endif /* SEC_CRYPTO_TYPES_H */
