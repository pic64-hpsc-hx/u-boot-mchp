/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_cper.h
 * @brief
 *  CPER header
 * @addtogroup RASLIB
 * @{
 */

#ifndef P64H_CPER_H
#define P64H_CPER_H

#include "p64h_uuid.h"

/* CPER record signature and the size */
#define P64H_CPER_SIG_RECORD "CPER"
#define P64H_CPER_SIG_SIZE   4
/* Used in signature_end field in typedef struct p64h_cper_record_header */
#define P64H_CPER_SIG_END 0xffffffff

/*
 * CPER record header revision, used in revision field in struct
 * cper_record_header
 */
#define P64H_CPER_RECORD_REV 0x0100

/*
 * CPER record length contains the CPER fields which are relevant for further
 * handling of a memory error in userspace (we don't carry all the fields
 * defined in the UEFI spec because some of them don't make any sense.)
 * Currently, a length of 256 should be more than enough.
 */
#define P64H_CPER_REC_LEN 256
/*
 * Severity definition for severity in typedef struct p64h_cper_record_header
 * and section_severity in typedef struct p64h_cper_section_descriptor
 */
enum {
    P64H_CPER_SEV_RECOVERABLE,
    P64H_CPER_SEV_FATAL,
    P64H_CPER_SEV_CORRECTED,
    P64H_CPER_SEV_INFORMATIONAL,
};

/*
 * Validation bits definition for validation_bits in struct
 * cper_record_header. If set, corresponding fields in struct
 * cper_record_header contain valid information.
 */
#define P64H_CPER_VALID_PLATFORM_ID  0x0001
#define P64H_CPER_VALID_TIMESTAMP    0x0002
#define P64H_CPER_VALID_PARTITION_ID 0x0004

/*
 * Notification type used to generate error record, used in
 * notification_type in typedef struct p64h_cper_record_header.  These UUIDs are defined
 * in the UEFI spec v2.7, sec N.2.1.
 */

/* Corrected Machine Check */
#define P64H_CPER_NOTIFY_CMC P64H_GUID_INIT(0x2DCE8BB1, 0xBDD7, 0x450e, 0xB9, 0xAD, 0x9C, 0xF4, 0xEB, 0xD4, 0xF8, 0x90)
/* Corrected Platform Error */
#define P64H_CPER_NOTIFY_CPE P64H_GUID_INIT(0x4E292F96, 0xD843, 0x4a55, 0xA8, 0xC2, 0xD4, 0x81, 0xF2, 0x7E, 0xBE, 0xEE)
/* Machine Check Exception */
#define P64H_CPER_NOTIFY_MCE P64H_GUID_INIT(0xE8F56FFE, 0x919C, 0x4cc5, 0xBA, 0x88, 0x65, 0xAB, 0xE1, 0x49, 0x13, 0xBB)
/* PCI Express Error */
#define P64H_CPER_NOTIFY_PCIE P64H_GUID_INIT(0xCF93C01F, 0x1A16, 0x4dfc, 0xB8, 0xBC, 0x9C, 0x4D, 0xAF, 0x67, 0xC1, 0x04)
/* INIT Record (for IPF) */
#define P64H_CPER_NOTIFY_INIT P64H_GUID_INIT(0xCC5263E8, 0x9308, 0x454a, 0x89, 0xD0, 0x34, 0x0B, 0xD3, 0x9B, 0xC9, 0x8E)
/* Non-Maskable Interrupt */
#define P64H_CPER_NOTIFY_NMI P64H_GUID_INIT(0x5BAD89FF, 0xB7E6, 0x42c9, 0x81, 0x4A, 0xCF, 0x24, 0x85, 0xD6, 0xE9, 0x8A)
/* BOOT Error Record */
#define P64H_CPER_NOTIFY_BOOT P64H_GUID_INIT(0x3D61A466, 0xAB40, 0x409a, 0xA6, 0x98, 0xF3, 0x62, 0xD4, 0x64, 0xB3, 0x8F)
/* DMA Remapping Error */
#define P64H_CPER_NOTIFY_DMAR P64H_GUID_INIT(0x667DD791, 0xC6B3, 0x4c27, 0x8A, 0x6B, 0x0F, 0x8E, 0x72, 0x2D, 0xEB, 0x41)

/*
 * Flags bits definitions for flags in typedef struct p64h_cper_record_header
 * If set, the error has been recovered
 */
#define P64H_CPER_HW_ERROR_FLAGS_RECOVERED 0x1
/* If set, the error is for previous boot */
#define P64H_CPER_HW_ERROR_FLAGS_PREVERR 0x2
/* If set, the error is injected for testing */
#define P64H_CPER_HW_ERROR_FLAGS_SIMULATED 0x4

/*
 * CPER section header revision, used in revision field in struct
 * cper_section_descriptor
 */
#define P64H_CPER_SEC_REV 0x0100

/*
 * Validation bits definition for validation_bits in struct
 * cper_section_descriptor. If set, corresponding fields in struct
 * cper_section_descriptor contain valid information.
 */
#define P64H_CPER_SEC_VALID_FRU_ID   0x1
#define P64H_CPER_SEC_VALID_FRU_TEXT 0x2

/*
 * Flags bits definitions for flags in typedef struct p64h_cper_section_descriptor
 *
 * If set, the section is associated with the error condition
 * directly, and should be focused on
 */
#define P64H_CPER_SEC_PRIMARY 0x0001
/*
 * If set, the error was not contained within the processor or memory
 * hierarchy and the error may have propagated to persistent storage
 * or network
 */
#define P64H_CPER_SEC_CONTAINMENT_WARNING 0x0002
/* If set, the component must be re-initialized or re-enabled prior to use */
#define P64H_CPER_SEC_RESET 0x0004
/* If set, Linux may choose to discontinue use of the resource */
#define P64H_CPER_SEC_ERROR_THRESHOLD_EXCEEDED 0x0008
/*
 * If set, resource could not be queried for error information due to
 * conflicts with other system software or resources. Some fields of
 * the section will be invalid
 */
#define P64H_CPER_SEC_RESOURCE_NOT_ACCESSIBLE 0x0010
/*
 * If set, action has been taken to ensure error containment (such as
 * poisoning data), but the error has not been fully corrected and the
 * data has not been consumed. Linux may choose to take further
 * corrective action before the data is consumed
 */
#define P64H_CPER_SEC_LATENT_ERROR 0x0020

/*
 * Section type definitions, used in section_type field in struct
 * cper_section_descriptor.  These UUIDs are defined in the UEFI spec
 * v2.7, sec N.2.2.
 */

/* Processor Generic */
#define P64H_CPER_SEC_PROC_GENERIC P64H_GUID_INIT(0x9876CCAD, 0x47B4, 0x4bdb, 0xB6, 0x5E, 0x16, 0xF1, 0x93, 0xC4, 0xF3, 0xDB)
/* Processor Specific: X86/X86_64 */
#define P64H_CPER_SEC_PROC_IA P64H_GUID_INIT(0xDC3EA0B0, 0xA144, 0x4797, 0xB9, 0x5B, 0x53, 0xFA, 0x24, 0x2B, 0x6E, 0x1D)
/* Processor Specific: IA64 */
#define P64H_CPER_SEC_PROC_IPF P64H_GUID_INIT(0xE429FAF1, 0x3CB7, 0x11D4, 0x0B, 0xCA, 0x07, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81)
/* Processor Specific: ARM */
#define P64H_CPER_SEC_PROC_ARM P64H_GUID_INIT(0xE19E3D16, 0xBC11, 0x11E4, 0x9C, 0xAA, 0xC2, 0x05, 0x1D, 0x5D, 0x46, 0xB0)
/* Platform Memory */
#define P64H_CPER_SEC_PLATFORM_MEM P64H_UUID_INIT(0xA5BC1114, 0x6F64, 0x4EDE, 0xB8, 0x63, 0x3E, 0x83, 0xED, 0x7C, 0x83, 0xB1)
#define P64H_CPER_SEC_PCIE         P64H_GUID_INIT(0xD995E954, 0xBBC1, 0x430F, 0xAD, 0x91, 0xB4, 0x4D, 0xCB, 0x3C, 0x6F, 0x35)
/* Firmware Error Record Reference */
#define P64H_CPER_SEC_FW_ERR_REC_REF P64H_UUID_INIT(0x81212A96, 0x09ED, 0x4996, 0x94, 0x71, 0x8D, 0x72, 0x9C, 0x8E, 0x69, 0xED)
/* PCI/PCI-X Bus */
#define P64H_CPER_SEC_PCI_X_BUS P64H_GUID_INIT(0xC5753963, 0x3B84, 0x4095, 0xBF, 0x78, 0xED, 0xDA, 0xD3, 0xF9, 0xC9, 0xDD)
/* PCI Component/Device */
#define P64H_CPER_SEC_PCI_DEV      P64H_GUID_INIT(0xEB5E4685, 0xCA66, 0x4769, 0xB6, 0xA2, 0x26, 0x06, 0x8B, 0x00, 0x13, 0x26)
#define P64H_CPER_SEC_DMAR_GENERIC P64H_GUID_INIT(0x5B51FEF7, 0xC79D, 0x4434, 0x8F, 0x1B, 0xAA, 0x62, 0xDE, 0x3E, 0x2C, 0x64)
/* Intel VT for Directed I/O specific DMAr */
#define P64H_CPER_SEC_DMAR_VT P64H_GUID_INIT(0x71761D37, 0x32B2, 0x45cd, 0xA7, 0xD0, 0xB0, 0xFE, 0xDD, 0x93, 0xE8, 0xCF)
/* IOMMU specific DMAr */
#define P64H_CPER_SEC_DMAR_IOMMU                     P64H_GUID_INIT(0x036F84E1, 0x7F37, 0x428c, 0xA7, 0x9E, 0x57, 0x5F, 0xDF, 0xAA, 0x84, 0xEC)

#define P64H_CPER_PROC_VALID_TYPE                    0x0001
#define P64H_CPER_PROC_VALID_ISA                     0x0002
#define P64H_CPER_PROC_VALID_ERROR_TYPE              0x0004
#define P64H_CPER_PROC_VALID_OPERATION               0x0008
#define P64H_CPER_PROC_VALID_FLAGS                   0x0010
#define P64H_CPER_PROC_VALID_LEVEL                   0x0020
#define P64H_CPER_PROC_VALID_VERSION                 0x0040
#define P64H_CPER_PROC_VALID_BRAND_INFO              0x0080
#define P64H_CPER_PROC_VALID_ID                      0x0100
#define P64H_CPER_PROC_VALID_TARGET_ADDRESS          0x0200
#define P64H_CPER_PROC_VALID_REQUESTOR_ID            0x0400
#define P64H_CPER_PROC_VALID_RESPONDER_ID            0x0800
#define P64H_CPER_PROC_VALID_IP                      0x1000

#define P64H_CPER_MEM_VALID_ERROR_STATUS             0x0001
#define P64H_CPER_MEM_VALID_PA                       0x0002
#define P64H_CPER_MEM_VALID_PA_MASK                  0x0004
#define P64H_CPER_MEM_VALID_NODE                     0x0008
#define P64H_CPER_MEM_VALID_CARD                     0x0010
#define P64H_CPER_MEM_VALID_MODULE                   0x0020
#define P64H_CPER_MEM_VALID_BANK                     0x0040
#define P64H_CPER_MEM_VALID_DEVICE                   0x0080
#define P64H_CPER_MEM_VALID_ROW                      0x0100
#define P64H_CPER_MEM_VALID_COLUMN                   0x0200
#define P64H_CPER_MEM_VALID_BIT_POSITION             0x0400
#define P64H_CPER_MEM_VALID_REQUESTOR_ID             0x0800
#define P64H_CPER_MEM_VALID_RESPONDER_ID             0x1000
#define P64H_CPER_MEM_VALID_TARGET_ID                0x2000
#define P64H_CPER_MEM_VALID_ERROR_TYPE               0x4000
#define P64H_CPER_MEM_VALID_RANK_NUMBER              0x8000
#define P64H_CPER_MEM_VALID_CARD_HANDLE              0x10000
#define P64H_CPER_MEM_VALID_MODULE_HANDLE            0x20000
#define P64H_CPER_MEM_VALID_ROW_EXT                  0x40000
#define P64H_CPER_MEM_VALID_BANK_GROUP               0x80000
#define P64H_CPER_MEM_VALID_BANK_ADDRESS             0x100000
#define P64H_CPER_MEM_VALID_CHIP_ID                  0x200000

#define P64H_CPER_MEM_EXT_ROW_MASK                   0x3
#define P64H_CPER_MEM_EXT_ROW_SHIFT                  16

#define P64H_CPER_MEM_BANK_ADDRESS_MASK              0xff
#define P64H_CPER_MEM_BANK_GROUP_SHIFT               8

#define P64H_CPER_MEM_CHIP_ID_SHIFT                  5

#define P64H_CPER_PCIE_VALID_PORT_TYPE               0x0001
#define P64H_CPER_PCIE_VALID_VERSION                 0x0002
#define P64H_CPER_PCIE_VALID_COMMAND_STATUS          0x0004
#define P64H_CPER_PCIE_VALID_DEVICE_ID               0x0008
#define P64H_CPER_PCIE_VALID_SERIAL_NUMBER           0x0010
#define P64H_CPER_PCIE_VALID_BRIDGE_CONTROL_STATUS   0x0020
#define P64H_CPER_PCIE_VALID_CAPABILITY              0x0040
#define P64H_CPER_PCIE_VALID_AER_INFO                0x0080

#define P64H_CPER_PCIE_SLOT_SHIFT                    3

#define P64H_CPER_ARM_VALID_MPIDR                    BIT(0)
#define P64H_CPER_ARM_VALID_AFFINITY_LEVEL           BIT(1)
#define P64H_CPER_ARM_VALID_RUNNING_STATE            BIT(2)
#define P64H_CPER_ARM_VALID_VENDOR_INFO              BIT(3)

#define P64H_CPER_ARM_INFO_VALID_MULTI_ERR           BIT(0)
#define P64H_CPER_ARM_INFO_VALID_FLAGS               BIT(1)
#define P64H_CPER_ARM_INFO_VALID_ERR_INFO            BIT(2)
#define P64H_CPER_ARM_INFO_VALID_VIRT_ADDR           BIT(3)
#define P64H_CPER_ARM_INFO_VALID_PHYSICAL_ADDR       BIT(4)

#define P64H_CPER_ARM_INFO_FLAGS_FIRST               BIT(0)
#define P64H_CPER_ARM_INFO_FLAGS_LAST                BIT(1)
#define P64H_CPER_ARM_INFO_FLAGS_PROPAGATED          BIT(2)
#define P64H_CPER_ARM_INFO_FLAGS_OVERFLOW            BIT(3)

#define P64H_CPER_ARM_CACHE_ERROR                    0
#define P64H_CPER_ARM_TLB_ERROR                      1
#define P64H_CPER_ARM_BUS_ERROR                      2
#define P64H_CPER_ARM_VENDOR_ERROR                   3
#define P64H_CPER_ARM_MAX_TYPE                       P64H_CPER_ARM_VENDOR_ERROR

#define P64H_CPER_ARM_ERR_VALID_TRANSACTION_TYPE     BIT(0)
#define P64H_CPER_ARM_ERR_VALID_OPERATION_TYPE       BIT(1)
#define P64H_CPER_ARM_ERR_VALID_LEVEL                BIT(2)
#define P64H_CPER_ARM_ERR_VALID_PROC_CONTEXT_CORRUPT BIT(3)
#define P64H_CPER_ARM_ERR_VALID_CORRECTED            BIT(4)
#define P64H_CPER_ARM_ERR_VALID_PRECISE_PC           BIT(5)
#define P64H_CPER_ARM_ERR_VALID_RESTARTABLE_PC       BIT(6)
#define P64H_CPER_ARM_ERR_VALID_PARTICIPATION_TYPE   BIT(7)
#define P64H_CPER_ARM_ERR_VALID_TIME_OUT             BIT(8)
#define P64H_CPER_ARM_ERR_VALID_ADDRESS_SPACE        BIT(9)
#define P64H_CPER_ARM_ERR_VALID_MEM_ATTRIBUTES       BIT(10)
#define P64H_CPER_ARM_ERR_VALID_ACCESS_MODE          BIT(11)

#define P64H_CPER_ARM_ERR_TRANSACTION_SHIFT          16
#define P64H_CPER_ARM_ERR_TRANSACTION_MASK           GENMASK(1, 0)
#define P64H_CPER_ARM_ERR_OPERATION_SHIFT            18
#define P64H_CPER_ARM_ERR_OPERATION_MASK             GENMASK(3, 0)
#define P64H_CPER_ARM_ERR_LEVEL_SHIFT                22
#define P64H_CPER_ARM_ERR_LEVEL_MASK                 GENMASK(2, 0)
#define P64H_CPER_ARM_ERR_PC_CORRUPT_SHIFT           25
#define P64H_CPER_ARM_ERR_PC_CORRUPT_MASK            GENMASK(0, 0)
#define P64H_CPER_ARM_ERR_CORRECTED_SHIFT            26
#define P64H_CPER_ARM_ERR_CORRECTED_MASK             GENMASK(0, 0)
#define P64H_CPER_ARM_ERR_PRECISE_PC_SHIFT           27
#define P64H_CPER_ARM_ERR_PRECISE_PC_MASK            GENMASK(0, 0)
#define P64H_CPER_ARM_ERR_RESTARTABLE_PC_SHIFT       28
#define P64H_CPER_ARM_ERR_RESTARTABLE_PC_MASK        GENMASK(0, 0)
#define P64H_CPER_ARM_ERR_PARTICIPATION_TYPE_SHIFT   29
#define P64H_CPER_ARM_ERR_PARTICIPATION_TYPE_MASK    GENMASK(1, 0)
#define P64H_CPER_ARM_ERR_TIME_OUT_SHIFT             31
#define P64H_CPER_ARM_ERR_TIME_OUT_MASK              GENMASK(0, 0)
#define P64H_CPER_ARM_ERR_ADDRESS_SPACE_SHIFT        32
#define P64H_CPER_ARM_ERR_ADDRESS_SPACE_MASK         GENMASK(1, 0)
#define P64H_CPER_ARM_ERR_MEM_ATTRIBUTES_SHIFT       34
#define P64H_CPER_ARM_ERR_MEM_ATTRIBUTES_MASK        GENMASK(8, 0)
#define P64H_CPER_ARM_ERR_ACCESS_MODE_SHIFT          43
#define P64H_CPER_ARM_ERR_ACCESS_MODE_MASK           GENMASK(0, 0)

/*
 * All tables and structs must be byte-packed to match CPER
 * specification, since the tables are provided by the system BIOS
 */
/* Record Header, UEFI v2.7 sec N.2.1 */
typedef struct p64h_cper_record_header {
    char        signature[P64H_CPER_SIG_SIZE]; /* must be P64H_CPER_SIG_RECORD */
    uint16_t    revision;                      /* must be P64H_CPER_RECORD_REV */
    uint32_t    signature_end;                 /* must be P64H_CPER_SIG_END */
    uint16_t    section_count;
    uint32_t    severity;
    uint32_t    validation_bits;
    uint32_t    record_length;
    uint64_t    timestamp;
    p64h_uuid_t platform_id;
    p64h_uuid_t partition_id;
    p64h_uuid_t creator_id;
    p64h_uuid_t notification_type;
    uint64_t    record_id;
    uint32_t    flags;
    uint64_t    persistence_information;
    uint8_t     reserved[12]; /* must be zero */
} p64h_cper_record_header_t;

/* Section Descriptor, UEFI v2.7 sec N.2.2 */
typedef struct p64h_cper_section_descriptor {
    uint32_t section_offset; /* Offset in bytes of the
                              *  section body from the base
                              *  of the record header */
    uint32_t    section_length;
    uint16_t    revision; /* must be P64H_CPER_RECORD_REV */
    uint8_t     validation_bits;
    uint8_t     reserved; /* must be zero */
    uint32_t    flags;
    p64h_uuid_t section_type;
    p64h_uuid_t fru_id;
    uint32_t    section_severity;
    uint8_t     fru_text[20];
} p64h_cper_section_descriptor_t;

/* Generic Processor Error Section, UEFI v2.7 sec N.2.4.1 */
typedef struct p64h_cper_sec_proc_generic {
    uint64_t validation_bits;
    uint8_t  proc_type;
    uint8_t  proc_isa;
    uint8_t  proc_error_type;
    uint8_t  operation;
    uint8_t  flags;
    uint8_t  level;
    uint16_t reserved;
    uint64_t cpu_version;
    char     cpu_brand[128];
    uint64_t proc_id;
    uint64_t target_addr;
    uint64_t requestor_id;
    uint64_t responder_id;
    uint64_t ip;
} p64h_cper_sec_proc_generic_t;

/* IA32/X64 Processor Error Section, UEFI v2.7 sec N.2.4.2 */
typedef struct p64h_cper_sec_proc_ia {
    uint64_t validation_bits;
    uint64_t lapic_id;
    uint8_t  cpuid[48];
} p64h_cper_sec_proc_ia_t;

/* IA32/X64 Processor Error Information Structure, UEFI v2.7 sec N.2.4.2.1 */
typedef struct p64h_cper_ia_err_info {
    p64h_uuid_t err_type;
    uint64_t    validation_bits;
    uint64_t    check_info;
    uint64_t    target_id;
    uint64_t    requestor_id;
    uint64_t    responder_id;
    uint64_t    ip;
} p64h_cper_ia_err_info_t;

/* IA32/X64 Processor Context Information Structure, UEFI v2.7 sec N.2.4.2.2 */
typedef struct p64h_cper_ia_proc_ctx {
    uint16_t reg_ctx_type;
    uint16_t reg_arr_size;
    uint32_t msr_addr;
    uint64_t mm_reg_addr;
} p64h_cper_ia_proc_ctx_t;

/* ARM Processor Error Section, UEFI v2.7 sec N.2.4.4 */
typedef struct p64h_cper_sec_proc_arm {
    uint32_t validation_bits;
    uint16_t err_info_num;     /* Number of Processor Error Info */
    uint16_t context_info_num; /* Number of Processor Context Info Records*/
    uint32_t section_length;
    uint8_t  affinity_level;
    uint8_t  reserved[3]; /* must be zero */
    uint64_t mpidr;
    uint64_t midr;
    uint32_t running_state; /* Bit 0 set - Processor running. PSCI = 0 */
    uint32_t psci_state;
} p64h_cper_sec_proc_arm_t;

/* ARM Processor Error Information Structure, UEFI v2.7 sec N.2.4.4.1 */
typedef struct p64h_cper_arm_err_info {
    uint8_t  version;
    uint8_t  length;
    uint16_t validation_bits;
    uint8_t  type;
    uint16_t multiple_error;
    uint8_t  flags;
    uint64_t error_info;
    uint64_t virt_fault_addr;
    uint64_t physical_fault_addr;
} p64h_cper_arm_err_info_t;

/* ARM Processor Context Information Structure, UEFI v2.7 sec N.2.4.4.2 */
typedef struct p64h_cper_arm_ctx_info {
    uint16_t version;
    uint16_t type;
    uint32_t size;
} p64h_cper_arm_ctx_info_t;

/* Old Memory Error Section, UEFI v2.1, v2.2 */
typedef struct p64h_cper_sec_mem_err_old {
    uint64_t validation_bits;
    uint64_t error_status;
    uint64_t physical_addr;
    uint64_t physical_addr_mask;
    uint16_t node;
    uint16_t card;
    uint16_t module;
    uint16_t bank;
    uint16_t device;
    uint16_t row;
    uint16_t column;
    uint16_t bit_pos;
    uint64_t requestor_id;
    uint64_t responder_id;
    uint64_t target_id;
    uint8_t  error_type;
} p64h_cper_sec_mem_err_old_t;

/* Memory Error Section (UEFI >= v2.3), UEFI v2.8 sec N.2.5 */
typedef struct p64h_cper_sec_mem_err {
    uint64_t validation_bits;
    uint64_t error_status;
    uint64_t physical_addr;
    uint64_t physical_addr_mask;
    uint16_t node;
    uint16_t card;
    uint16_t module;
    uint16_t bank;
    uint16_t device;
    uint16_t row;
    uint16_t column;
    uint16_t bit_pos;
    uint64_t requestor_id;
    uint64_t responder_id;
    uint64_t target_id;
    uint8_t  error_type;
    uint8_t  extended;
    uint16_t rank;
    uint16_t mem_array_handle; /* "card handle" in UEFI 2.4 */
    uint16_t mem_dev_handle;   /* "module handle" in UEFI 2.4 */
} p64h_cper_sec_mem_err_t;

typedef struct p64h_cper_mem_err_compact {
    uint64_t validation_bits;
    uint16_t node;
    uint16_t card;
    uint16_t module;
    uint16_t bank;
    uint16_t device;
    uint16_t row;
    uint16_t column;
    uint16_t bit_pos;
    uint64_t requestor_id;
    uint64_t responder_id;
    uint64_t target_id;
    uint16_t rank;
    uint16_t mem_array_handle;
    uint16_t mem_dev_handle;
    uint8_t  extended;
} p64h_cper_mem_err_compact_t;

static inline uint32_t p64h_cper_get_mem_extension(uint64_t mem_valid, uint8_t mem_extended)
{
    if (!(mem_valid & P64H_CPER_MEM_VALID_ROW_EXT)) {
        return 0;
    }
    return (mem_extended & P64H_CPER_MEM_EXT_ROW_MASK) << P64H_CPER_MEM_EXT_ROW_SHIFT;
}

/* PCI Express Error Section, UEFI v2.7 sec N.2.7 */
typedef struct p64h_cper_sec_pcie {
    uint64_t validation_bits;
    uint32_t port_type;
    struct {
        uint8_t minor;
        uint8_t major;
        uint8_t reserved[2];
    } version;
    uint16_t command;
    uint16_t status;
    uint32_t reserved;
    struct {
        uint16_t vendor_id;
        uint16_t device_id;
        uint8_t  class_code[3];
        uint8_t  function;
        uint8_t  device;
        uint16_t segment;
        uint8_t  bus;
        uint8_t  secondary_bus;
        uint16_t slot;
        uint8_t  reserved;
    } device_id;
    struct {
        uint32_t lower;
        uint32_t upper;
    } serial_number;
    struct {
        uint16_t secondary_status;
        uint16_t control;
    } bridge;
    uint8_t capability[60];
    uint8_t aer_info[96];
} p64h_cper_sec_pcie_t;

/* Firmware Error Record Reference, UEFI v2.7 sec N.2.10  */
typedef struct {
    uint8_t     record_type;
    uint8_t     revision;
    uint8_t     reserved[6];
    uint64_t    record_identifier;
    p64h_uuid_t record_identifier_guid;
} cper_sec_fw_err_rec_ref_t;

#endif