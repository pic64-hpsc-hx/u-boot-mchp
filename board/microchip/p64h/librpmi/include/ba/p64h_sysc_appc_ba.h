/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines boot configuration
 */
#ifndef P64H_SYSC_APPC_BA_H
#define P64H_SYSC_APPC_BA_H

#include "p64h_sysc_intr_ba.h"
#include "p64h_sysc_shared_periph_ba.h"
#include "p64h_sysc_shared_svc_ba.h"
#include "p64h_sysc_shared_wguard_ba.h"

#define P64H_SYSC_MAX_BOOT_CMDS                72u ///< Current Maximum Number of supported Boot Commands
#define P64H_SYSC_APPC_CFG_PARTITION_MAX       8u  ///< define the maximum number of appc partition
#define P64H_SYSC_APP_NOC_QOS_GEN_MAX          35u ///< Number of QoS generators inside the App NoC
#define P64H_SYSC_DDR_NOC_QOS_GEN_MAX          4u  ///< Number of QoS generators inside the DDR NoC
#define P64H_SYSC_APP_NOC_QOS_RATE_ADAPT_MAX   24u ///< Number of QoS rate adapters inside the APP NoC
#define P64H_SYSC_MAX_APPC_STATIC_BINARIES     3u  ///< Maximum number of static binaries
#define P64H_SYSC_MAX_APPC_PARTITIONS          8u  ///< Maximum number of partitions
#define P64H_SYSC_MAX_APPC_PARTITIONS_BINARIES 2u  ///< Maximum number of partition binaries
#define P64H_SYSC_NUM_APPC_HW_PROF             8u  ///< Number of appc HW profiles // TODO: should be 16 because of A/B sides?
#define P64H_SYSC_MAX_APPC_BINARIES            30u ///< number of max appc image binaries (maybe more need to update)
#define P64H_SYSC_APPC_METADATA_COPIES         3u  ///< number of metadata copies in appc image binary
#define P64H_SYSC_APPC_COMPACT_MAGIC_NUMBER    (0x0123456789abcdefULL)
#define P64H_SYSC_APPC_REDUNDANT_MAGIC_NUMBER  (0xfedcba9876543210ULL)

// Forward declarations to get the size
struct p64h_sysc_appc_boot_script_t;
struct p64h_sysc_appc_static_cfg_t;
#define P64H_SYSC_SIZE_APPC_BOOTSCRIPT    sizeof(p64h_sysc_appc_boot_script_t) ///< Size of appc bootscript artifact
#define P64H_SYSC_SIZE_APPC_STATIC_CFG    sizeof(p64h_sysc_appc_static_cfg_t)  ///< Size of appc static config artifact
#define P64H_SYSC_SIZE_APPC_SW_SVC_CFG    sizeof(p64h_sysc_soc_svc_cfg_t)      ///< Size of boot config software service config artifact
#define P64H_SYSC_SIZE_PARTITION_APPC_CFG sizeof(p64h_sysc_appc_cfg_t)         ///< Size of appc partition config
#define P64H_SYSC_SIZE_PARTITION_APPC_DTB (30 * 1024) ///< Minimum size allocated for an appc partition dtb TODO: need to review what this should be
#define P64H_SYSC_SIZE_APPC_EXE                                                                                                                      \
    (100 * 1024) ///< Minimum size allocated for an appc baremetal or rtems executable TODO: need to review what this should be

/**
 * @brief
 * Defines the possible commands to be used in generating the bootscript
 */
typedef enum {
    P64H_SYSC_BOOT_CMD_LOAD = 0,      ///< Boot command to Load
    P64H_SYSC_BOOT_CMD_CONFIG_STATIC, ///< Boot command for static config
    P64H_SYSC_BOOT_CMD_CONFIG_APPC,   ///< Boot command for appc config
    P64H_SYSC_BOOT_CMD_RESET_APPC,    ///< Boot command to reset appc
    P64H_SYSC_BOOT_CMD_BOOT_APPC,     ///< Boot command to boot appc
    P64H_SYSC_BOOT_CMD_LAST           ///< number of commands
} p64h_sysc_boot_cmd_name_t;

/**
 * @brief
 * Defines the possible interfaces to be used in generating the bootscript
 */
typedef enum {
    P64H_SYSC_BOOT_INTF_LOCAL = 0, ///< local
    P64H_SYSC_BOOT_INTF_TFTP,      ///< tftp
    P64H_SYSC_BOOT_INTF_SEMIHOST,  ///< semihost
    P64H_SYSC_BOOT_INTF_USB        ///< usb
} p64h_sysc_boot_intf_t;

/**
 * @brief
 * Defines the possible tags to be used when generating the bootscript
 */
typedef enum {
    P64H_SYSC_BOOT_CMD_EXE = 0,   ///< metal elf exe
    P64H_SYSC_BOOT_CMD_ZSBL,      ///< zsbl
    P64H_SYSC_BOOT_CMD_KERNEL,    ///< kernel
    P64H_SYSC_BOOT_CMD_ROOTFS,    ///< rootfs
    P64H_SYSC_BOOT_CMD_OPENSBI,   ///< opensbi
    P64H_SYSC_BOOT_CMD_CORE,      ///< core
    P64H_SYSC_BOOT_CMD_DOMU_CORE, ///< xen DomU dtb
    P64H_SYSC_BOOT_CMD_TAG_LAST   ///< number of command tags
} p64h_sysc_boot_cmd_tag_t;

/**
 * @brief
 * This struct contains the necessary information for a singular bootscript command
 */
typedef struct {
    p64h_sysc_boot_cmd_name_t name;         ///< Name of the command
    p64h_sysc_boot_cmd_tag_t  tag;          ///< Tag Name
    p64h_sysc_boot_intf_t     intf;         ///< Interface Name // TODO: what is this?
    uint64_t                  addr;         ///< Command Address
    uint8_t                   cluster_id;   ///< Cluster ID
    uint8_t                   partition_id; ///< appc partition ID
    uint8_t                   appc_index;   ///< appc index
} p64h_sysc_boot_cmd_t;

/**
 * @brief
 * This struct packs all bootscript commands into one struct
 */
typedef struct {
    // dev_cfg_hdr_t hdr;
    uint32_t             num_cmd;                       ///< Number of commands in Bootscript
    p64h_sysc_boot_cmd_t cmds[P64H_SYSC_MAX_BOOT_CMDS]; ///< List of Commands in Bootscript
} p64h_sysc_appc_boot_script_t;

/**
 * @brief
 *   Defines boot action of a bootscript execution specified by p64h_sysc_psm_command_t
 */
typedef enum {
    P64H_SYSC_PSM_ACTION_START,     ///< Start an Appc Config
    P64H_SYSC_PSM_ACTION_STOP,      ///< Stop an Appc Config
    P64H_SYSC_PSM_ACTION_SUSPEND,   ///< Suspend an Appc Config
    P64H_SYSC_PSM_ACTION_STATUS_GET ///< Get status
    // TODO: add more actions (status_get, etc.)
} p64h_sysc_psm_action_t;

/**
 * @brief
 *   Defines the boot execution
 *   This is the message of P64H_EVT_SVC_APPC_BOOTSCRIPT_EXEC event
 */
typedef struct {
    p64h_sysc_psm_action_t action;            ///< determine how the bootscript is executed
    uint8_t                partition_id_mask; ///< a bit mask specifying on which appc partition we apply the action to
} p64h_sysc_psm_command_t;

/**
 * @brief
 *   Defines the configuration state of either appc statuc configruation an appc partiton
 */
typedef enum {
    P64H_SYSC_APPC_CFG_STATE_RESET = 0, ///< reset state, applicable to static appc cfg and appc partition
    P64H_SYSC_APPC_CFG_STATE_CFG,       ///< cfg state, applicable to static appc cfg and appc partition
    P64H_SYSC_APPC_CFG_STATE_BOOT       ///< state boot, only applicable to appc partition
} p64h_sysc_appc_cfg_state_t;

/**
 * @brief
 *   Defines the load state of either appc static configruation an appc partiton
 */
typedef enum {
    P64H_SYSC_CTXT_CLEARED = 0, ///< reset state, applicable to static appc cfg and appc partition
    P64H_SYSC_CTXT_LOADED       ///< state boot, only applicable to appc partition
} p64h_sysc_appc_load_state_t;

/**
 * @brief
 *   Defines the both the boot and load status of the static_cfg or appc_cfg
 */
typedef struct {
    p64h_sysc_appc_cfg_state_t  boot;
    p64h_sysc_appc_load_state_t load;
} p64h_sysc_appc_component_status_t;

/**
 * @brief
 *   Defines the current load status of the appc_ctxt BLOBs
 */
typedef struct {
    p64h_sysc_appc_component_status_t static_cfg;                                 ///< state of appc static cfg
    p64h_sysc_appc_component_status_t appc_cfg[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< state of appc cfg partition
} p64h_sysc_appc_ctxt_status_t;

/**
 * @brief
 *   a appc complex configuration
 */
typedef struct {
    uint64_t reset_addr;         ///< boot address
    uint64_t nmi_intr_addr;      ///< none-maskable interrupt address
    uint64_t nmi_excp_addr;      ///< none-maskable exception address
    uint32_t cluster_id;         ///< cluster id
    uint32_t cluster_mask;       ///< cluster mask
    uint32_t core_mask;          ///< core mask
    uint32_t dcls_mask;          ///< dcls mask
    uint64_t dcls_timeout;       ///< dcls timeout(in nanoseconds)
    uint32_t trace_en;           ///< enable tracing
    uint32_t debug_en;           ///< enable debugging
    bool     zsbl_boot_from_dls; ///< when set to true appc boot from DLS, when set to False appc boot from ITIM
} p64h_sysc_appc_core_complex_cfg_t;

/**
 * @brief
 *   the appc status
 */
typedef struct {
    uint8_t core_valid_mask; ///< which core are valid in reported status
    uint8_t cease;           ///< cease status per core
    uint8_t wfi;             ///< wait for interrupt (wfi) status per core
    uint8_t halt;            ///< halt status per core
    uint8_t debug;           ///< debug status per core
} p64h_sysc_appc_status_t;

/**
 * @brief
 *   Defines the different boot modes possible
 */
typedef enum {
    P64H_SYSC_BOOT_MODE_OPENSBI = 0, ///< Linux
    P64H_SYSC_BOOT_MODE_METAL,       ///< Bare Metal
    P64H_SYSC_BOOT_MODE_RTEMS,       ///< RTEMS
    P64H_SYSC_BOOT_MODE_LAST         ///< Last sysc boot mode
} p64h_sysc_appc_fsbl_boot_mode_t;

/**
 * @brief
 *   Specifies the boot parameter config
 */
typedef struct {
    p64h_sysc_appc_fsbl_boot_mode_t mode;                ///< bootup mode
    uint32_t                        boot_hart;           ///< boot hart
    uint64_t                        kernel_addr;         ///< kernel address (linux, rtems, uboot, vxworks...)
    uint64_t                        dtb_addr;            ///< dtb address
    uint64_t                        opensbi_addr;        ///< opensbi address
    uint32_t                        opensbi_option;      ///< opensbi option (verbosity, ...)
    uint32_t                        opensbi_next_mode_s; ///< opensbi next_mode (ex: supervisor for linux, vxwork, machine mode for uboot)
} p64h_sysc_appc_boot_params_cfg_t;

/**
 * @brief
 *   Defines the different coarse stride modes possible
 */
typedef enum {
    P64H_SYSC_APPC_COARSE_STRIDE_128MB = 0, ///< 128 MB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_256MB,     ///< 256 MB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_512MB,     ///< 512 MB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_1GB,       ///< 1GB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_2GB,       ///< 2GB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_4GB,       ///< 4GB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_8GB,       ///< 8GB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_16GB,      ///< 16GB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_32GB,      ///< 32GB stripes
    P64H_SYSC_APPC_COARSE_STRIDE_64GB,      ///< 64GB stripes
} p64h_sysc_appc_coarse_stride_mode_t;

/**
 * @brief
 *   NoC types
 */
typedef enum {
    P64H_SYSC_APP_NOC_QOS_TYPE,   ///< APP NoC type
    P64H_SYSC_DDR_NOC_QOS_TYPE,   ///< DDR NoC type
    P64H_SYSC_UNUSED_NOC_QOS_TYPE ///< Unused NOC type
} p64h_sysc_noc_qos_type_t;

/**
 * @brief
 *   NoC QoS generator types
 */
typedef enum {
    P64H_SYSC_NOC_QOS_GEN_MODE_FIXED,    ///< Fixed generator mode
    P64H_SYSC_NOC_QOS_GEN_MODE_LIMITER,  ///< Limiter generator mode
    P64H_SYSC_NOC_QOS_GEN_MODE_BYPASS,   ///< Bypass generator mode
    P64H_SYSC_NOC_QOS_GEN_MODE_REGULATOR ///< Regulator generator mode
} p64h_sysc_noc_qos_gen_mode_t;

/**
 * @brief
 *   a appc cluster configuration
 */
typedef struct {
    uint32_t                            fine_mode;   ///< find mode for Extensible Cache
    uint8_t                             ts_offset;   ///< Timestamp Offset for the ghrt_ctrl register.
    p64h_sysc_appc_coarse_stride_mode_t stride_mode; ///< coarse stride mode for Extensible Cache
} p64h_sysc_appc_cluster_cfg_t;

/// APP NoC QoS generators
typedef enum {
    APP_NOC_CPU_CLSTR0_MEM_PORT_QOS_GEN = 0u,   ///< Cluster 0 memory port QOS generator
    APP_NOC_CPU_CLSTR0_SYSC_PORT_QOS_GEN,       ///< Cluster 0 system port QOS generator
    APP_NOC_CPU_CLSTR1_MEM_PORT_QOS_GEN,        ///< Cluster 1 memory port QOS generator
    APP_NOC_CPU_CLSTR1_SYSC_PORT_QOS_GEN,       ///< Cluster 1 system port QOS generator
    APP_NOC_DDR_ENCRYPT_QOS_GEN,                ///< DDR encryption QOS generator
    APP_NOC_ENET_EP0_QOS_GEN,                   ///< ENET endpoint 0 QOS generator
    APP_NOC_ENET_EP1_QOS_GEN,                   ///< ENET endpoint 1 QOS generator
    APP_NOC_ENET_EP2_QOS_GEN,                   ///< ENET endpoint 2 QOS generator
    APP_NOC_ENET_EP3_QOS_GEN,                   ///< ENET endpoint 3 QOS generator
    APP_NOC_ENET_SWR_RDMA1_PIE_HIGHBW_QOS_GEN,  ///< ENET SWITCH RDMA 1 PIE high bandwidth QOS generator
    APP_NOC_ENET_SWR_RDMA1_ROCE_HIGHBW_QOS_GEN, ///< ENET Switch RDMA 1 ROCE high bandwidth QOS generator
    APP_NOC_ENET_SWR_RDMA1_ROCE_LOWBW_QOS_GEN,  ///< ENET Switch RDMA1 ROCE low bandwidth QOS generator
    APP_NOC_ENET_SWR_RDMA2_PIE_HIGHBW_QOS_GEN,  ///< ENET Switch RDMA2 PIE high bandwidth QOS generator
    APP_NOC_ENET_SWR_RDMA2_ROCE_HIGHBW_QOS_GEN, ///< ENET Switch RDMA2 ROCE high bandwidth QOS generator
    APP_NOC_ENET_SWR_RDMA2_ROCE_LOWBW_QOS_GEN,  ///< ENET Switch RDMA2 ROCE low bandwidth QOS generator
    APP_NOC_IOMMMU0_QOS_GEN,                    ///< IOMMU 0 QOS generator
    APP_NOC_IOMMU1_QOS_GEN,                     ///< IOMMU 1 QOS generator
    APP_NOC_SPW0_QOS_GEN,                       ///< SPW0 QOS generator
    APP_NOC_SPW1_QOS_GEN,                       ///< SPW1 QOS generator
    APP_NOC_USB0_QOS_GEN,                       ///< USB0 QOS generator
    APP_NOC_USB1_QOS_GEN,                       ///< USB1 QOS generator
    APP_NOC_APPDMA0_QOS_GEN,                    ///< APPDMA0 QOS generator
    APP_NOC_APPDMA1_QOS_GEN,                    ///< APPDMA1 QOS generator
    APP_NOC_TRACE_SOK_QOS_GEN,                  ///< TRACE SOK QOS generator
    APP_NOC_NVM_DMA0_QOS_GEN,                   ///< NVM DMA0 QOS generator
    APP_NOC_NVM_DMA1_QOS_GEN,                   ///< NVM DMA1 QOS generator
    APP_NOC_NVM_SD_DMA0_QOS_GEN,                ///< NVM SD DMA0 QOS generator
    APP_NOC_NVM_SD_DMA1_QOS_GEN,                ///< NVM SD DMA1 QOS generator
    APP_NOC_PCIE0_CTL0_QOS_GEN,                 ///< PCIE0 Controller 0 QOS generator
    APP_NOC_PCIE0_CTL1_QOS_GEN,                 ///< PCIE0 Controller 1 QOS generator
    APP_NOC_PCIE1_CTL0_QOS_GEN,                 ///< PCIE1 Controller 0 QOS generator
    APP_NOC_PCIE1_CTL1_QOS_GEN,                 ///< PCIE1 Controller 1 QOS generator
    APP_NOC_SVC_NOC_QOS_GEN,                    ///< SVC NOC QOS generator
    APP_NOC_SYSC_NOC_QOS_GEN,                   ///< SYSC NOC QOS generator
    APP_NOC_USER_CRYPTO_QOS_GEN,                ///< User crypto QOS generator
    LAST_APP_NOC_QOS_GEN                        ///< invalid, used for error checking
} p64h_sysc_app_noc_qos_gen_t;

/// APP NoC rate adapters
typedef enum {
    APP_NOC_ENET_EP_CDC_2_RATE_ADAPTER = 0u, ///< rate adapter
    APP_NOC_CDC1_RATE_ADAPTER,               ///< rate adapter
    APP_NOC_CDC2_RATE_ADAPTER,               ///< rate adapter
    APP_NOC_CDC_RATE_ADAPTER,                ///< rate adapter
    APP_NOC_CDC_2_RATE_ADAPTER,              ///< rate adapter
    APP_NOC_REQ_CDC_CPU0_3_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_REQ_CDC_CPU0_4_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_REQ_CDC_CPU1_3_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_REQ_CDC_CPU1_4_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_REQ_CDC_DDR_ENC_2_RATE_ADAPTER,  ///< rate adapter
    APP_NOC_REQ_CDC_PCIE0_2_RATE_ADAPTER,    ///< rate adapter
    APP_NOC_REQ_CDC_PCIE1_2_RATE_ADAPTER,    ///< rate adapter
    APP_NOC_RSP_CDC_CPU0_7_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_RSP_CDC_CPU0_8_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_RSP_CDC_CPU1_7_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_RSP_CDC_CPU1_8_RATE_ADAPTER,     ///< rate adapter
    APP_NOC_RSP_CDC_DDR_ENC_5_RATE_ADAPTER,  ///< rate adapter
    APP_NOC_RSP_CDC_DDR_ENC_6_RATE_ADAPTER,  ///< rate adapter
    APP_NOC_RSP_CDC_PCIE0_5_RATE_ADAPTER,    ///< rate adapter
    APP_NOC_RSP_CDC_PCIE0_6_RATE_ADAPTER,    ///< rate adapter
    APP_NOC_RSP_CDC_PCIE1_5_RATE_ADAPTER,    ///< rate adapter
    APP_NOC_RSP_CDC_PCIE1_6_RATE_ADAPTER,    ///< rate adapter
    APP_NOC_TRANS_CDC_1RESP002_RATE_ADAPTER, ///< rate adapter
    APP_TRANS_CDC_2RESP001_RATE_ADAPTER,     ///< rate adapter
    LAST_APP_NOC_RATE_ADAPTER                ///< invalid, used for error checking
} p64h_sysc_app_noc_rate_adapt_t;

typedef enum {
    DDR_NOC_A0_QOS_GEN = 0u, ///< A0 port QOS generator
    DDR_NOC_A1_QOS_GEN,      ///< A1 port QOS generator
    DDR_NOC_B0_QOS_GEN,      ///< B0 port QOS generator
    DDR_NOC_B1_QOS_GEN,      ///< B1 port QOS generator
    LAST_DDR_NOC_QOS_GEN     ///< invalid, used for error checking
} p64h_sysc_ddr_noc_qos_gen_t;
/**
 * @brief
 *   NoC QoS generator configuration
 */
typedef struct {
    bool                         activate;         ///< true - configure generator ; false - do not configure generator
    uint32_t                     priority_p0;      ///< priority P0
    uint32_t                     priority_p1;      ///< Priority P1
    p64h_sysc_noc_qos_gen_mode_t gen_mode;         ///< QoS generator mode
    uint32_t                     bandwidth_thresh; ///< Bandwidth threshold
    uint32_t                     saturation;       ///< Saturation level
    bool socket_qos_en; ///< True - Socket QoS signals priority if qos_mode = P64H_SYSC_NOC_QOS_GEN_MODE_BYPASS or max priority between Qos generator
                        ///< priority and Socket QoS signals , False - Priority levels from QoS generator or Socket QoS signals (if qos_mode =
                        ///< P64H_SYSC_NOC_QOS_GEN_MODE_BYPASS)
} p64h_sysc_noc_qos_gen_cfg_t;

/**
 * @brief
 *   NoC QoS rate adapters configuration
 */
typedef struct {
    bool     activate;   ///< true - configure rate adapter ; false - do not configure rate adapter
    uint32_t rate_ratio; ///< Pre-computed Throughput ratio in multiples of 1/256.
    bool     bypass;     ///< true - enable rate adaptation, false - disable rate adaptation
} p64h_sysc_noc_qos_rate_adapt_cfg_t;

/**
 * @brief
 *   a appc static configuration
 */
typedef struct {
    uint32_t                           unified_mode;    ///< unified mode
    uint32_t                           ddr_interleaved; ///< ddr interleaved
    p64h_sysc_bin_hdr_t                dev_cfg_version; ///< stores the versioning info for the dev_cfg tool
    p64h_sysc_appc_cluster_cfg_t       ss_cfg[2];       ///< cluster configurations(Extensible Cache etc.)

    p64h_sysc_appc_wg_cfg_t            wg_cfg;                                                ///< worldguard configuration
    p64h_sysc_appc_ddr_cfg_t           ddr_cfg;                                               ///< ddr configuration
    p64h_sysc_appc_wg_core_cfg_t       core_cfg[APPC_CORE_NUM];                               ///< core complex configuration
    p64h_sysc_appc_wg_cluster_cfg_t    cluster_cfg[APPC_CLUSTER_NUM];                         ///< cluster configuration
    p64h_sysc_noc_qos_gen_cfg_t        app_noc_qos_gen_cfg[LAST_APP_NOC_QOS_GEN];             //< APP NoC QoS generator configuration
    p64h_sysc_noc_qos_gen_cfg_t        ddr_noc_qos_gen_cfg[LAST_DDR_NOC_QOS_GEN];             /// DDR NoC QoS generator configuration
    p64h_sysc_noc_qos_rate_adapt_cfg_t app_noc_qos_rate_adapt_cfg[LAST_APP_NOC_RATE_ADAPTER]; ///< APP NoC QoS rate adaptation configuration
    p64h_sysc_appc_int_agg_cfg_t       intr_cfg;                                              ///< Interrupt configuration
} p64h_sysc_appc_static_cfg_t;

/**
 * @brief
 *   appc configuration
 */
typedef struct {
    uint8_t                           enable;           ///< 1 : enable the configuration, 0 : disable the configuration
    p64h_sysc_appc_core_complex_cfg_t core_complex_cfg; ///< core complex configuration
    p64h_sysc_bin_hdr_t               dev_cfg_version;  ///< stores the versioning info for the dev_cfg tool
    p64h_sysc_appc_boot_params_cfg_t  boot_cfg;         ///< boot config details
    p64h_sysc_appc_periph_cfg_t       periph_cfg;       ///< top level Peripheral configuration
} p64h_sysc_appc_cfg_t;

/**
 * @brief
 *   Appc Partition Configuration. This struct is used to pass arguments of the static cfg
 *   to the appc_cfg in order to configure some worldguard core configurations
 */
typedef struct p64h_sysc_appc_partition_t {
    p64h_sysc_appc_static_cfg_t* appc_static_cfg; /// pointer to the appc static configuration
    p64h_sysc_appc_cfg_t*        appc_cfg;        /// pointer to the appc configuration
} p64h_sysc_appc_partition_t;

/**
 * @brief
 *   Section descriptor struct
 */
typedef struct {
    uint64_t offset; ///< offset of the binary
    uint64_t size;   ///< size of the binary
} p64h_sysc_section_desc_t;

/**
 * @brief
 *   AppC binary section descriptor struct
 */
typedef struct {
    uint64_t offset;   ///< offset of the binary
    uint64_t size;     ///< size of the binary
    uint64_t max_size; ///< maximum size of the binary allocated to allow overwrites. note: should be set equal to .size if moved to update section
                       ///< when doing a fw update
} p64h_sysc_appc_bin_desc_t;

/**
 * @brief
 *   Appc hardware profile map. Contains static and partition binaries.
 */
typedef struct {
    p64h_sysc_section_desc_t
        static_cfg[P64H_SYSC_MAX_APPC_STATIC_BINARIES]; ///< static cfg's -> appc_bootscript.bin, appc_static_cfg.bin and sw_svc_cfg.bin
    p64h_sysc_section_desc_t
        partition_cfg[P64H_SYSC_MAX_APPC_PARTITIONS]
                     [P64H_SYSC_MAX_APPC_PARTITIONS_BINARIES]; ///< partition binaries p0-p7 and each have 2 binaries-> appc_cfg_gen.bin and core.dtb
    uint64_t section_desc_valid; ///< Bit mask specifying which section descriptor structs are valid. The least-significant bit applies to the first
                                 ///< section description of static_cfg and so on. Only the first (P64H_SYSC_MAX_APPC_STATIC_BINARIES +
                                 ///< P64H_SYSC_MAX_APPC_PARTITIONS*P64H_SYSC_MAX_APPC_PARTITIONS_BINARIES) bits are used
} p64h_sysc_appc_hw_prof_desc_t;

/**
 * @brief
 *  Update section of appc image binary
 */
typedef struct {
    uint64_t start_addr;      ///< start address of update section
    uint64_t top_update_addr; ///< address of the top of update section, where we would place the next update. Initially set to start_addr and will
                              ///< change as we add binaries
    uint64_t remaining_size;  ///< remaining size of update section
} p64h_sysc_update_desc_t;

/**
 * @brief
 * Metadata for Appc image binary
 */
typedef struct {
    uint64_t                      magic_number; //<< Magic number to check if appc cfg is valid (only until we have proper checksums)
    p64h_sysc_appc_hw_prof_desc_t appc_hw_prof; //<< Appc hardware profile
    p64h_sysc_appc_bin_desc_t     appc_section[P64H_SYSC_MAX_APPC_BINARIES]; ///< Shared Appc binaries blob
    p64h_sysc_update_desc_t       update_desc;                               ///< update section
    uint32_t appc_section_valid; ///< Bit mask specifying which appc binary section descriptor structs are valid. The least-significant bit applies to
                                 ///< the first appc binary and so on. Only the first P64H_SYSC_MAX_APPC_BINARIES bits are used
    bool has_side_AB;            ///< Indicates if A/B side is present
} p64h_sysc_appc_cfg_metadata_redundant_t;

/**
 * @brief
 * Metadata for Appc image binary
 */
typedef struct {
    uint64_t                      magic_number; //<< Magic number to check if appc cfg is valid (only until we have proper checksums)
    p64h_sysc_appc_hw_prof_desc_t appc_hw_prof[P64H_SYSC_NUM_APPC_HW_PROF];  //<< Appc hardware profile
    p64h_sysc_appc_bin_desc_t     appc_section[P64H_SYSC_MAX_APPC_BINARIES]; ///< Shared Appc binaries blob
    p64h_sysc_update_desc_t       update_desc;                               ///< update section
    uint32_t appc_section_valid; ///< Bit mask specifying which appc binary section descriptor structs are valid. The least-significant bit applies to
                                 ///< the first appc binary and so on. Only the first P64H_SYSC_MAX_APPC_BINARIES bits are used
    uint8_t num_appc_hw_prof;    ///< Number of Appc hardware profiles
} p64h_sysc_appc_cfg_metadata_compact_t;

#endif // P64H_SYSC_APPC_BA_H
