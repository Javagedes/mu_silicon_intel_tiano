/** @file
  The definition for VTD register.
  It is defined in "Intel VT for Direct IO Architecture Specification".

  Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __VTD_REG_H__
#define __VTD_REG_H__

#pragma pack(1)

//
// Translation Structure Formats
//
#define VTD_ROOT_ENTRY_NUMBER     256
#define VTD_CONTEXT_ENTRY_NUMBER  256

typedef union {
  struct {
    UINT32    Present               : 1;
    UINT32    Reserved_1            : 11;
    UINT32    ContextTablePointerLo : 20;
    UINT32    ContextTablePointerHi : 32;

    UINT64    Reserved_64;
  } Bits;
  struct {
    UINT64    Uint64Lo;
    UINT64    Uint64Hi;
  } Uint128;
} VTD_ROOT_ENTRY;

typedef union {
  struct {
    UINT32    LowerPresent               : 1;
    UINT32    Reserved_1                 : 11;
    UINT32    LowerContextTablePointerLo : 20;
    UINT32    LowerContextTablePointerHi : 32;

    UINT32    UpperPresent               : 1;
    UINT32    Reserved_65                : 11;
    UINT32    UpperContextTablePointerLo : 20;
    UINT32    UpperContextTablePointerHi : 32;
  } Bits;
  struct {
    UINT64    Uint64Lo;
    UINT64    Uint64Hi;
  } Uint128;
} VTD_EXT_ROOT_ENTRY;

typedef union {
  struct {
    UINT32    Present                             : 1;
    UINT32    FaultProcessingDisable              : 1;
    UINT32    TranslationType                     : 2;
    UINT32    Reserved_4                          : 8;
    UINT32    SecondLevelPageTranslationPointerLo : 20;
    UINT32    SecondLevelPageTranslationPointerHi : 32;

    UINT32    AddressWidth                        : 3;
    UINT32    Ignored_67                          : 4;
    UINT32    Reserved_71                         : 1;
    UINT32    DomainIdentifier                    : 16;
    UINT32    Reserved_88                         : 8;
    UINT32    Reserved_96                         : 32;
  } Bits;
  struct {
    UINT64    Uint64Lo;
    UINT64    Uint64Hi;
  } Uint128;
} VTD_CONTEXT_ENTRY;

typedef union {
  struct {
    UINT32    Present                             : 1;
    UINT32    FaultProcessingDisable              : 1;
    UINT32    TranslationType                     : 3;
    UINT32    ExtendedMemoryType                  : 3;
    UINT32    DeferredInvalidateEnable            : 1;
    UINT32    PageRequestEnable                   : 1;
    UINT32    NestedTranslationEnable             : 1;
    UINT32    PASIDEnable                         : 1;
    UINT32    SecondLevelPageTranslationPointerLo : 20;
    UINT32    SecondLevelPageTranslationPointerHi : 32;

    UINT32    AddressWidth                        : 3;
    UINT32    PageGlobalEnable                    : 1;
    UINT32    NoExecuteEnable                     : 1;
    UINT32    WriteProtectEnable                  : 1;
    UINT32    CacheDisable                        : 1;
    UINT32    ExtendedMemoryTypeEnable            : 1;
    UINT32    DomainIdentifier                    : 16;
    UINT32    SupervisorModeExecuteProtection     : 1;
    UINT32    ExtendedAccessedFlagEnable          : 1;
    UINT32    ExecuteRequestsEnable               : 1;
    UINT32    SecondLevelExecuteEnable            : 1;
    UINT32    Reserved_92                         : 4;
    UINT32    PageAttributeTable0                 : 3;
    UINT32    Reserved_Pat0                       : 1;
    UINT32    PageAttributeTable1                 : 3;
    UINT32    Reserved_Pat1                       : 1;
    UINT32    PageAttributeTable2                 : 3;
    UINT32    Reserved_Pat2                       : 1;
    UINT32    PageAttributeTable3                 : 3;
    UINT32    Reserved_Pat3                       : 1;
    UINT32    PageAttributeTable4                 : 3;
    UINT32    Reserved_Pat4                       : 1;
    UINT32    PageAttributeTable5                 : 3;
    UINT32    Reserved_Pat5                       : 1;
    UINT32    PageAttributeTable6                 : 3;
    UINT32    Reserved_Pat6                       : 1;
    UINT32    PageAttributeTable7                 : 3;
    UINT32    Reserved_Pat7                       : 1;

    UINT32    PASIDTableSize                      : 4;
    UINT32    Reserved_132                        : 8;
    UINT32    PASIDTablePointerLo                 : 20;
    UINT32    PASIDTablePointerHi                 : 32;

    UINT32    Reserved_192                        : 12;
    UINT32    PASIDStateTablePointerLo            : 20;
    UINT32    PASIDStateTablePointerHi            : 32;
  } Bits;
  struct {
    UINT64    Uint64_1;
    UINT64    Uint64_2;
    UINT64    Uint64_3;
    UINT64    Uint64_4;
  } Uint256;
} VTD_EXT_CONTEXT_ENTRY;

typedef union {
  struct {
    UINT32    Present                            : 1;
    UINT32    Reserved_1                         : 2;
    UINT32    PageLevelCacheDisable              : 1;
    UINT32    PageLevelWriteThrough              : 1;
    UINT32    Reserved_5                         : 6;
    UINT32    SupervisorRequestsEnable           : 1;
    UINT32    FirstLevelPageTranslationPointerLo : 20;
    UINT32    FirstLevelPageTranslationPointerHi : 32;
  } Bits;
  UINT64    Uint64;
} VTD_PASID_ENTRY;

typedef union {
  struct {
    UINT32    Reserved_0           : 32;
    UINT32    ActiveReferenceCount : 16;
    UINT32    Reserved_48          : 15;
    UINT32    DeferredInvalidate   : 1;
  } Bits;
  UINT64    Uint64;
} VTD_PASID_STATE_ENTRY;

typedef union {
  struct {
    UINT32    Present               : 1;
    UINT32    ReadWrite             : 1;
    UINT32    UserSupervisor        : 1;
    UINT32    PageLevelWriteThrough : 1;
    UINT32    PageLevelCacheDisable : 1;
    UINT32    Accessed              : 1;
    UINT32    Dirty                 : 1;
    UINT32    PageSize              : 1; // It is PageAttribute:1 for 4K page entry
    UINT32    Global                : 1;
    UINT32    Ignored_9             : 1;
    UINT32    ExtendedAccessed      : 1;
    UINT32    Ignored_11            : 1;
    // NOTE: There is PageAttribute:1 as bit12 for 1G page entry and 2M page entry
    UINT32    AddressLo             : 20;
    UINT32    AddressHi             : 20;
    UINT32    Ignored_52            : 11;
    UINT32    ExecuteDisable        : 1;
  } Bits;
  UINT64    Uint64;
} VTD_FIRST_LEVEL_PAGING_ENTRY;

typedef union {
  struct {
    UINT32    Read               : 1;
    UINT32    Write              : 1;
    UINT32    Execute            : 1;
    UINT32    ExtendedMemoryType : 3;
    UINT32    IgnorePAT          : 1;
    UINT32    PageSize           : 1;
    UINT32    Ignored_8          : 3;
    UINT32    Snoop              : 1;
    UINT32    AddressLo          : 20;
    UINT32    AddressHi          : 20;
    UINT32    Ignored_52         : 10;
    UINT32    TransientMapping   : 1;
    UINT32    Ignored_63         : 1;
  } Bits;
  UINT64    Uint64;
} VTD_SECOND_LEVEL_PAGING_ENTRY;

//
// Register Descriptions
//
#define R_VER_REG                 0x00
#define R_CAP_REG                 0x08
#define   B_CAP_REG_RWBF          BIT4
#define R_ECAP_REG                0x10
#define R_GCMD_REG                0x18
#define   B_GMCD_REG_QIE          BIT26
#define   B_GMCD_REG_WBF          BIT27
#define   B_GMCD_REG_SRTP         BIT30
#define   B_GMCD_REG_TE           BIT31
#define R_GSTS_REG                0x1C
#define   B_GSTS_REG_QIES         BIT26
#define   B_GSTS_REG_WBF          BIT27
#define   B_GSTS_REG_RTPS         BIT30
#define   B_GSTS_REG_TE           BIT31
#define R_RTADDR_REG              0x20
#define   V_RTADDR_REG_TTM_ADM    (BIT11|BIT10)
#define R_CCMD_REG                0x28
#define   B_CCMD_REG_CIRG_MASK    (BIT62|BIT61)
#define   V_CCMD_REG_CIRG_GLOBAL  BIT61
#define   V_CCMD_REG_CIRG_DOMAIN  BIT62
#define   V_CCMD_REG_CIRG_DEVICE  (BIT62|BIT61)
#define   B_CCMD_REG_ICC          BIT63
#define R_FSTS_REG                0x34
#define   B_FSTS_REG_IQE          BIT4
#define   B_FSTS_REG_ICE          BIT5
#define   B_FSTS_REG_ITE          BIT6
#define R_FECTL_REG               0x38
#define R_FEDATA_REG              0x3C
#define R_FEADDR_REG              0x40
#define R_FEUADDR_REG             0x44
#define R_AFLOG_REG               0x58

#define R_IVA_REG                  0x00// + IRO
#define   B_IVA_REG_AM_MASK        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
#define   B_IVA_REG_AM_4K          0 // 1 page
#define   B_IVA_REG_AM_2M          9 // 2M page
#define   B_IVA_REG_IH             BIT6
#define R_IOTLB_REG                0x08// + IRO
#define   B_IOTLB_REG_IIRG_MASK    (BIT61|BIT60)
#define   V_IOTLB_REG_IIRG_GLOBAL  BIT60
#define   V_IOTLB_REG_IIRG_DOMAIN  BIT61
#define   V_IOTLB_REG_IIRG_PAGE    (BIT61|BIT60)
#define   B_IOTLB_REG_IVT          BIT63

#define R_FRCD_REG  0x00      // + FRO

#define R_PMEN_ENABLE_REG       0x64
#define R_PMEN_LOW_BASE_REG     0x68
#define R_PMEN_LOW_LIMITE_REG   0x6C
#define R_PMEN_HIGH_BASE_REG    0x70
#define R_PMEN_HIGH_LIMITE_REG  0x78

#define R_IQH_REG        0x80
#define R_IQT_REG        0x88
#define   DMAR_IQ_SHIFT  4   /* Invalidation queue head/tail shift */

#define R_IQA_REG  0x90

#define VTD_PAGE_SHIFT  (12)
#define VTD_PAGE_SIZE   (1UL << VTD_PAGE_SHIFT)
#define VTD_PAGE_MASK   (((UINT64)-1) << VTD_PAGE_SHIFT)

#define QI_CC_TYPE      0x1
#define QI_IOTLB_TYPE   0x2
#define QI_DIOTLB_TYPE  0x3
#define QI_IEC_TYPE     0x4
#define QI_IWD_TYPE     0x5

#define QI_CC_FM(fm)      (((UINT64)fm) << 48)
#define QI_CC_SID(sid)    (((UINT64)sid) << 32)
#define QI_CC_DID(did)    (((UINT64)did) << 16)
#define QI_CC_GRAN(gran)  (((UINT64)gran) << 4)

#define QI_IOTLB_DID(did)    (((UINT64)did) << 16)
#define QI_IOTLB_DR(dr)      (((UINT64)dr) << 7)
#define QI_IOTLB_DW(dw)      (((UINT64)dw) << 6)
#define QI_IOTLB_GRAN(gran)  (((UINT64)gran) << 4)
#define QI_IOTLB_ADDR(addr)  (((UINT64)addr) & VTD_PAGE_MASK)
#define QI_IOTLB_IH(ih)      (((UINT64)ih) << 6)
#define QI_IOTLB_AM(am)      (((UINT8)am))

#define CAP_READ_DRAIN(c)   (((c) >> 55) & 1)
#define CAP_WRITE_DRAIN(c)  (((c) >> 54) & 1)

#define QI_IWD_STATUS_DATA(d)  (((UINT64)d) << 32)
#define QI_IWD_STATUS_WRITE  (((UINT64)1) << 5)

//
// This is the queued invalidate descriptor.
//
typedef struct {
  UINT64    Low;
  UINT64    High;
} QI_DESC;

typedef union {
  struct {
    UINT8     Minor : 4;
    UINT8     Major : 4;
    UINT32    Rsvd  : 24;
  } Bits;
  UINT32    Uint32;
} VTD_VER_REG;

typedef union {
  struct {
    UINT8     ND      : 3; // Number of domains supported
    UINT8     AFL     : 1; // Advanced Fault Logging
    UINT8     RWBF    : 1; // Required Write-Buffer Flushing
    UINT8     PLMR    : 1; // Protected Low-Memory Region
    UINT8     PHMR    : 1; // Protected High-Memory Region
    UINT8     CM      : 1; // Caching Mode

    UINT8     SAGAW   : 5; // Supported Adjusted Guest Address Widths
    UINT8     Rsvd_13 : 3;

    UINT8     MGAW    : 6; // Maximum Guest Address Width
    UINT8     ZLR     : 1; // Zero Length Read
    UINT8     Rsvd_23 : 1;

    UINT16    FRO     : 10; // Fault-recording Register offset
    UINT16    SLLPS   : 4;  // Second Level Large Page Support
    UINT16    Rsvd_38 : 1;
    UINT16    PSI     : 1; // Page Selective Invalidation

    UINT8     NFR     : 8; // Number of Fault-recording Registers

    UINT8     MAMV    : 6; // Maximum Address Mask Value
    UINT8     DWD     : 1; // Write Draining
    UINT8     DRD     : 1; // Read Draining

    UINT8     FL1GP   : 1; // First Level 1-GByte Page Support
    UINT8     Rsvd_57 : 2;
    UINT8     PI      : 1; // Posted Interrupts Support
    UINT8     FL5LP   : 1; // First Level 5-level Paging Support
    UINT8     Rsvd_61 : 1;
    UINT8     ESIRTPS : 1;  // Enhanced Set Interrupt Remap Table Pointer Support
    UINT8     ESRTPS  : 1;  // Enhanced Set Root Table Pointer Support
  } Bits;
  UINT64    Uint64;
} VTD_CAP_REG;

typedef union {
  struct {
    UINT8     C       : 1; // Page-walk Coherency
    UINT8     QI      : 1; // Queued Invalidation support
    UINT8     DT      : 1; // Device-TLB support
    UINT8     IR      : 1; // Interrupt Remapping support
    UINT8     EIM     : 1; // Extended Interrupt Mode
    UINT8     DEP_5   : 1;
    UINT8     PT      : 1; // Pass Through
    UINT8     SC      : 1; // Snoop Control

    UINT16    IRO     : 10; // IOTLB Register Offset
    UINT16    Rsvd_18 : 2;
    UINT16    MHMV    : 4; // Maximum Handle Mask Value

    UINT8     DEP_24  : 1;
    UINT8     MTS     : 1; // Memory Type Support
    UINT8     NEST    : 1; // Nested Translation Support
    UINT8     Rsvd_27 : 1;
    UINT8     DEP_28  : 1;
    UINT8     PRS     : 1; // Page Request Support
    UINT8     ERS     : 1; // Execute Request Support
    UINT8     SRS     : 1; // Supervisor Request Support

    UINT32    Rsvd_32 : 1;
    UINT32    NWFS    : 1; // No Write Flag Support
    UINT32    EAFS    : 1; // Extended Accessed Flag Support
    UINT32    PSS     : 5; // PASID Size Supported
    UINT32    PASID   : 1; // Process Address Space ID Support
    UINT32    DIT     : 1; // Device-TLB Invalidation Throttle
    UINT32    PDS     : 1; // Page-request Drain Support
    UINT32    SMTS    : 1; // Scalable Mode Translation Support
    UINT32    VCS     : 1; // Virtual Command Support
    UINT32    SLADS   : 1; // Second-Level Accessed Dirty Support
    UINT32    SLTS    : 1; // Second-level Translation Support
    UINT32    FLTS    : 1; // First-level Translation Support
    UINT32    SMPWCS  : 1; // Scalable-Mode Page-walk Coherency Support
    UINT32    RPS     : 1; // RID-PASID Support
    UINT32    Rsvd_50 : 2;
    UINT32    ADMS    : 1; // Abort DMA Mode Support
    UINT32    RPRIVS  : 1; // RID_PRIV Support
    UINT32    Rsvd_54 : 10;
  } Bits;
  UINT64    Uint64;
} VTD_ECAP_REG;

typedef union {
  struct {
    UINT32    Rsvd_0  : 12;
    UINT32    FILo    : 20; // FaultInfo
    UINT32    FIHi    : 32; // FaultInfo

    UINT32    SID     : 16; // Source Identifier
    UINT32    Rsvd_80 : 12;
    UINT32    T2      : 1; // Type bit2 (0: Write/Read, 1: Page/AtomicOp)
    UINT32    PRIV    : 1; // Privilege Mode Requested
    UINT32    EXE     : 1; // Execute Permission Requested
    UINT32    PP      : 1; // PASID Present

    UINT32    FR      : 8;  // Fault Reason
    UINT32    PV      : 20; // PASID Value
    UINT32    AT      : 2;  // Address Type
    UINT32    T1      : 1;  // Type bit1 (0: Write/Page, 1: Read/AtomicOp)
    UINT32    F       : 1;  // Fault
  } Bits;
  UINT64    Uint64[2];
} VTD_FRCD_REG;

typedef union {
  struct {
    UINT8    Function : 3;
    UINT8    Device   : 5;
    UINT8    Bus;
  } Bits;
  struct {
    UINT8    ContextIndex;
    UINT8    RootIndex;
  } Index;
  UINT16    Uint16;
} VTD_SOURCE_ID;

#pragma pack()

#endif
