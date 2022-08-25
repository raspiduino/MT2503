#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

# *************************************************************************
# Include GNU Make Standard Library (GMSL)
# *************************************************************************
include tools\GMSL\gmsl
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

AUTO_MERGE_FILE_CHECK = $(if $(shell dir $(1)\$(strip $(BOARD_VER))\$(2) /b 2>nul),$(1)\$(strip $(BOARD_VER))\$(2), \
                        $(if $(shell dir $(1)\_DEFAULT_BB\$(strip $(PLATFORM))\$(2) /b 2>nul), $(1)\_DEFAULT_BB\$(strip $(PLATFORM))\$(2),))
# *************************************************************************
# Set defaul value to Ckmake flag 
# *************************************************************************
DEPENDENCY_CONFLICT = FALSE
# *************************************************************************
# Dependency Check error message Interfaces
# *************************************************************************
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB)
#               $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB1/ValB2/.../ValBn)
#               $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,non ValB)
# Output:       PLEASE set OptA as ValA or set OptB as ValB
#               PLEASE set OptA as ValA or set OptB as ValB1/ValB2/.../ValBn
#               PLEASE set OptA as ValA or set OptB as non ValB
#
# Example:      $(call DEP_ERR_SETA_OR_SETB,BROWSER_SUPPORT,OBIGO_Q05A,UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT,non OBIGO_Q05A)
#               PLEASE set BROWSER_SUPPORT as OBIGO_Q05A or set UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT as non OBIGO_Q05A
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_SETB = $(warning ERROR: PLEASE set $1 as $2 or set $3 as $4)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB)
#               $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB$OptC&...&OptN)
# Output:       PLEASE turn on OptA or turn off OptB
#
# Example:      $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
#               PLEASE turn on NAND_SUPPORT or turn off NAND_FLASH_BOOTING
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_OFFB = $(warning ERROR: PLEASE turn on $1 or turn off $2)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_OFFB,OptA,ValA,OptB)
#               $(call DEP_ERR_SETA_OR_OFFB,OptA,ValA1/ValA2/.../ValAn,OptB)
#               $(call DEP_ERR_SETA_OR_OFFB,OptA,non ValA,OptB)
# Output:       PLEASE set OptA as ValA or turn off OptB
#               PLEASE set OptA as ValA1/ValA2/.../ValAn or turn off OptB
#               PLEASE set OptA as non ValA or turn off OptB
#
# Example:      $(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
#               PLEASE set MELODY_VER as DSP_WT_SYN or turn off J2ME_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_OFFB = $(warning ERROR: PLEASE set $1 as $2 or turn off $3)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_ONB,OptA,ValA,OptB)
#               $(call DEP_ERR_SETA_OR_ONB,OptA,ValA1/ValA2/.../ValAn,OptB)
#               $(call DEP_ERR_SETA_OR_ONB,OptA,non ValA,OptB)
# Output:       PLEASE set OptA as ValA or turn on OptB
#               PLEASE set OptA as ValA1/ValA2/.../ValAn or turn on OptB
#               PLEASE set OptA as non ValA or turn on OptB
#
# Example:      $(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_FOLDER)
#               PLEASE set MMS_SUPPORT as non OBIGO_Q05A or turn on UNIFIED_MESSAGE_FOLDER
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_ONB = $(warning ERROR: PLEASE set $1 as $2 or turn on $3)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_OFFA_OR_OFFB,OptA,OptB)
# Output:       PLEASE turn off OptA or turn off OptB
#
# Example:      $(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
#               PLEASE turn off CMUX_SUPPORT or turn off BLUETOOTH_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_OFFA_OR_OFFB = $(warning ERROR: PLEASE turn off $1 or turn off $2)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_ONA_OR_ONB,OptA,OptB)
# Output:       PLEASE turn on OptA or turn on OptB
#
# Example:      $(call DEP_ERR_ONA_OR_ONB,UCM_SUPPORT,VOIP_SUPPORT)
#               PLEASE turn on UCM_SUPPORT or turn on VOIP_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_ONB = $(warning ERROR: PLEASE turn on $1 or turn on $2)
# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW      = FALSE
RUN_RESGEN  = FALSE

# *************************************************************************
# Include temporary build script
# *************************************************************************
# Get $(PROJECT) Definition
-include make\~buildinfo.tmp

# Custom specific build script
-include make\Custom.bld         # Custom release build

ifndef CUSTOM_RELEASE
  CUSTOM_RELEASE = FALSE         # Default custom release
endif

ifndef MTK_SUBSIDIARY
  MTK_SUBSIDIARY = FALSE
endif

ifeq ($(strip $(call Upper,$(CUSTOMER))),MTK)

  ifneq ($(strip $(call Upper,$(APLAT))),NONE)
    include make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
    THE_MF = make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
  else
    include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
    THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
  endif

else
  include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
  THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
endif

ORIGINAL_THE_MF := $(strip $(THE_MF))
ifdef PROJECT_MAKEFILE_EXT
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),)
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),NONE)
    THE_MF = $(strip $(BUILDDIR))\$(strip $(CUSTOMER))\_$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
    ORIGINAL_THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
  endif
  endif
endif

ORIGINAL_CUSTOMER := $(strip $(CUSTOMER))
ifdef SPLIT_BINARY_SUPPORT
  ifneq ($(strip $(SPLIT_BINARY_SUPPORT)),NONE)
    ORIGINAL_CUSTOMER := $(subst _COMBINE,,$(subst _FACTORY,,$(subst _MAUIONLY,,$(call uc,$(CUSTOMER)))))
  endif
endif

ifeq ($(strip $(SPLIT_BINARY_SUPPORT)),FACTORY_ONLY)
  COM_DEFS   += __SPLIT_BINARY__ __FACTORY_BIN__
endif

ifeq ($(strip $(SPLIT_BINARY_SUPPORT)),MAUI_ONLY)
  COM_DEFS   += __SPLIT_BINARY__
endif

ifeq ($(strip $(SPLIT_BINARY_SUPPORT)),FACTORY_COMBINE)
  COM_DEFS   += __SPLIT_BINARY__
endif

-include make\USER_SPECIFIC.mak

ifndef DEBUG_MODULES
  DEBUG_MODULES =
endif

ifndef NON_DEBUG_MODULES
  NON_DEBUG_MODULES =
endif

ENABLE_PARTIAL_TRACE=FALSE
ifdef KAL_TRACE_OUTPUT
  ifdef PARTIAL_TRACE_LIB
    ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
      ifneq ($(strip $(PARTIAL_TRACE_LIB)),)
        ENABLE_PARTIAL_TRACE=TRUE
      endif
    endif
  endif
endif

INSIDE_MTK = 0
ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
    INSIDE_MTK = 1
endif

ifndef BLUETOOTH_SUPPORT_SWITCH
  BLUETOOTH_SUPPORT_SWITCH=NONE
endif

COMMINCDIRS    += $(CUSTOM_COMMINC)
COM_DEFS       += $(CUSTOM_OPTION)

# *************************************************************************
# Include checkvalue.mak to check invalid feature values.
# *************************************************************************
-include make\checkvalue.mak
-include make\OLD_FEATURES.mak

# *************************************************************************
# Include Option_HAL.mak for hareware-related checking
# *************************************************************************
include make\Option_HAL.mak

# *************************************************************************
# Environment and Tools
# *************************************************************************
ifndef COMPILE_MODE
  COMPILE_MODE = INST16                            # 16bits instruction set
endif

# default is ADS compiler
ifndef COMPILER
  VIA = -via
  MD = -MD
  COMPILER = ADS
  CGEN_DEF_FILE = Tgt_Cnf
else
  ifeq ($(strip $(COMPILER)),RVCT)
    VIA = --via
    MD = --md
    CGEN_DEF_FILE = Tgt_Cnf_RVCT
  else
    CGEN_DEF_FILE = Tgt_Cnf
  endif
  ifeq ($(strip $(COMPILER)),ADS)
    VIA = -via
    MD = -MD
  endif
endif

DIR_INT_569  =  $(DIR_ARM)\Programs\3.1\569_init

ifdef RVCT_VERSION
  ifneq ($(strip $(RVCT_VERSION)),NONE)
    ifneq ($(strip $(COMPILER)),RVCT)
      $(call DEP_ERR_SETA_OR_OFFB,COMPILER,RVCT,RVCT_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifeq ($(strip $(COMPILER)),RVCT)
  ifndef RVCT_VERSION
    $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)
    DEPENDENCY_CONFLICT = TRUE
  endif 
  ifeq ($(strip $(RVCT_VERSION)),NONE)
    $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)
    DEPENDENCY_CONFLICT = TRUE
  endif
  DIR_ARM  = C:\Progra~1\ARM\RVCT
  DIR_ARM := $(strip $(DIR_ARM))
  ifeq ($(strip $(RVCT_VERSION)),V22)
    DIR_TOOL       =  $(DIR_ARM)\Programs\2.2\349\win_32-pentium
    DIR_ARMLIB     =  $(DIR_ARM)\Data\2.2\349\lib
    DIR_ARMINC     =  $(DIR_ARM)\Data\2.2\349\include\windows
    ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
      ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
        DIR_TOOL       =  $(RVCT22BIN)
        DIR_ARMLIB     =  $(RVCT22LIB)
        DIR_ARMINC     =  $(RVCT22INC)
      endif
    endif
  endif
  ifeq ($(strip $(RVCT_VERSION)),V31)
    DIR_TOOL       =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium
    DIR_ARMLIB     =  $(DIR_ARM)\Data\3.1\569\lib
    DIR_ARMINC     =  $(DIR_ARM)\Data\3.1\569\include\windows

  ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
    ifeq ($(strip $(MTK_SUBSIDIARY)),FALSE)  
      include make\verifyCus.mak
    endif
  endif

  endif
  ifeq ($(strip $(PLATFORM)),MT6256)
    VFP_OPTION     =  --fpu=softvfp+vfpv2

    VFP_OPTION_SOFT=  --fpu=softvfp
  endif

  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium\armar.exe         # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool

  ifeq ($(strip $(COMPILE_MODE)),INST16)
    CC          =  $(DIR_TOOL)\armcc.exe --thumb $(VFP_OPTION_SOFT)     # Thumb Mode(16bits), use tcc
    CC32        =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)       # ARM Mode(32bits), use armcc
  else
    ifeq ($(strip $(COMPILE_MODE)),INST32)
      CC          =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)     # ARM Mode(32bits), use armcc
    else
      CC          =  $(DIR_TOOL)\armcc.exe --thumb $(VFP_OPTION_SOFT)   # Default tcc
      CC32        =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)     # ARM Mode(32bits), use armcc
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  DIR_ARM        =  c:\progra~1\arm\adsv1_2
  DIR_ARM       :=  $(strip $(DIR_ARM))
  DIR_TOOL       =  $(DIR_ARM)\bin
  DIR_ARMLIB     =  $(DIR_ARM)\lib
  DIR_ARMINC     =  $(DIR_ARM)\include

  DIR_TOOL      :=  $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_TOOL)\armar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool

  ifeq ($(strip $(COMPILE_MODE)),INST16)
    CC          =  $(DIR_TOOL)\tcc.exe               # Thumb Mode(16bits), use tcc
    CC32        =  $(DIR_TOOL)\armcc.exe             # ARM Mode(32bits), use armcc
    CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
    CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
  else
    ifeq ($(strip $(COMPILE_MODE)),INST32)
      CC          =  $(DIR_TOOL)\armcc.exe           # ARM Mode(32bits), use armcc
      CPPC        =  $(DIR_TOOL)\armcpp.exe          # ARM Mode(32bits), use armcc
    else
      CC          =  $(DIR_TOOL)\tcc.exe             # Default tcc
      CC32        =  $(DIR_TOOL)\armcc.exe           # ARM Mode(32bits), use armcc
      CPPC        =  $(DIR_TOOL)\tcpp.exe            # Thumb Mode(16bits), use tcc
      CPPC32      =  $(DIR_TOOL)\armcpp.exe          # ARM Mode(32bits), use armcc
    endif
  endif
endif

# *************************************************************************
# Build Options
# *************************************************************************

# -----------------------------
# CODEGEN option
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  CGENFLAG = -D__RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
  CGENFLAG =
endif

# -----------------------------
# Interwork option
# -----------------------------
APCSINT     =
ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
    APCSINT  +=  --apcs /inter/noswst
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
    APCSINT  +=  -apcs /interwork
  endif
endif

# -----------------------------
# C options COPTION16 for thumb mode and COPTION32 for arm mode
# -----------------------------
-include tools\RVCTBuildNo.tmp
ifeq ($(strip $(COMPILER)),RVCT)

armtoolinfo = $(shell $(CC) --vsn 2>&1)
armtoolver = $(shell perl tools\armversion.pl $(armtoolinfo))
ifeq ($(strip $(armtoolver)),GEQ794)
REMOVE_UNNEEDED_ENTITIES:=--remove_unneeded_entities -D__FILE__=__MODULE__
endif
ifeq ($(strip $(armtoolver)),LSS794)
  REMOVE_UNNEEDED_ENTITIES:=--remove_unneeded_entities
endif

  # CLEANROOM_CFLAGS is for CLEANROOM_COMP modules
  CLEANROOM_CFLAGS   := --cpu ARM9EJ-S

  CPLUSFLAGS = --cpp --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  CFLAGS     = --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__  -J$(DIR_ARMINC) --fpmode=ieee_fixed
  LNKOPT     = --cpu ARM7EJ-S
  ifeq ($(strip $(PLATFORM)),MT6218B)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6268T)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6268H)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6268A)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6268)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6256)
    CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM1176JZ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6276)
    CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed 
    LNKOPT   :=   --cpu ARM1176JZ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6270A)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6208)
    CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7TDMI
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
    CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7TDMI
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
    CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7TDMI
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6253T)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6253)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6253E)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6253L)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252H)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
  endif

  ifeq ($(strip $(PLATFORM)),MT6251)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   := --cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6250)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6260)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
  endif
   
  ifeq ($(strip $(PLATFORM)),MT6261)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
  endif
  ifeq ($(strip $(PLATFORM)),MT2501)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
  endif
  ifeq ($(strip $(PLATFORM)),MT2502)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6223P)
    CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6239)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6235)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6235B)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6236)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6236B)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6516)
    ifdef SMART_PHONE_CORE
      ifeq ($(strip $(SMART_PHONE_CORE)),AP)
        CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      else
        CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      endif
    else
      CFLAGS     :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    endif
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6573)
    ifdef SMART_PHONE_CORE
      CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      LNKOPT   :=   --cpu ARM1176JZ-S
    else      
      CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      LNKOPT   :=   --cpu ARM1176JZ-S
    endif
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6921)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6255)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6922)
    CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu ARM9EJ-S
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  CPLUSFLAGS = -cpp -cpu ARM7EJ-S -littleend -O2 -zo -Ono_peephole -fa
  CFLAGS     =   -cpu ARM7EJ-S -littleend -O2 -zo -Ono_peephole -fa

  ifeq ($(strip $(PLATFORM)),MT6218B)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268T)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268H)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268A)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6270A)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6208)
    CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
    CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
    CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253T)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6253E)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6253L)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252H)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  ifeq ($(strip $(PLATFORM)),MT6250)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6260)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  ifeq ($(strip $(PLATFORM)),MT2501)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  ifeq ($(strip $(PLATFORM)),MT2502)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6261)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6223P)
    CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6239)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6235)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6235B)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6236)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6236B)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    ifdef SMART_PHONE_CORE
      ifeq ($(strip $(SMART_PHONE_CORE)),AP)
        CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
      else
        CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
      endif
    else
      CFLAGS       :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
    endif
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6921)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
  ifeq ($(strip $(PLATFORM)),MT6255)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
  ifeq ($(strip $(PLATFORM)),MT6922)
    CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
endif

ifeq ($(strip $(COMPILER)),RVCT)
  CFLAGS += --split_sections 
  CFLAGS += --diag_suppress 1,1295,1296,2548
  ifeq ($(strip $(RVCT_DEBUG_FORMAT)),DWARF3)
    CFLAGS += --dwarf3
  else
    CFLAGS += --dwarf2
  endif
  CPLUSFLAGS := --cpp $(CFLAGS)
endif

ifeq ($(strip $(COMPILER)),ADS)
  CPLUSFLAGS := -cpp $(CFLAGS)
endif

CFLAGS     +=  $(CUSTOM_CFLAGS)
CPLUSFLAGS +=  $(CUSTOM_CFLAGS)

# -----------------------------
# assembly option AOPTION16 for Thumb mode and AOPTION32 for Arm mode
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  BL_AFLAGS  = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  AFLAGS     = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  ifeq ($(strip $(PLATFORM)),MT6218B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268T)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268H)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6256)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM1176JZ-S --fpu=softvfp+vfpv2 --no_unaligned_access --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM1176JZ-S --fpu=softvfp+vfpv2 --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6276)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM1176JZ-S --no_unaligned_access --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM1176JZ-S --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6270A)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253T)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253E)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253L)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6252)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6252H)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6251)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6250)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6260)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6261)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT2501)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT2502)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6236)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6236B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6573)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM1176JZ-S --no_unaligned_access --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM1176JZ-S --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6921)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6255)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6922)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  BL_AFLAGS  = -g -littleend -cpu ARM7TDMI
  AFLAGS     = -g -littleend -cpu ARM7TDMI
  ifeq ($(strip $(PLATFORM)),MT6218B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268T)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268H)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6270A)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253T)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253E)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253L)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6252H)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6252)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6250)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6260)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6261)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT2501)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT2502)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6236)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6236B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6921)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6255)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6922)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
endif

ifeq ($(strip $(COMPILE_MODE)),INST16)
  BL_AFLAGS += -16
  AFLAGS +=  -16
endif

# -----------------------------
# Library option LIBOPT for generating libraries
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  LIBOPT      =  --create
endif
ifeq ($(strip $(COMPILER)),ADS)
  LIBOPT      =  -create
endif

# -----------------------------
# Linker options
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    LNKOPT      +=  --map --info sizes,totals --symbols --feedback lnkfeedback.txt --xref --remove --pad 0x00 --datacompressor off --verbose
  else
    LNKOPT      +=  --map --info sizes,totals --symbols --feedback lnkfeedback.txt --xref --remove --pad 0x00 --datacompressor off
  endif
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      LNKOPT      +=  --first LARGEPOOL_FIRST_ZI
    endif
  endif
endif

ifeq ($(strip $(DCM_OPTION)),TRUE)
  LNKOPT      += --callgraph
endif

ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifeq ($(strip $(armtoolver)),GEQ794)
      LNKOPT += --max_veneer_passes=400
    endif
  endif
  LNKOPT += --verbose --trace p,v,t
endif

ifdef VENUS_MMI
  ifneq ($(strip $(VENUS_MMI)),NONE)
    COMMINCDIRS   += venusmmi\plugin\framework\interface
  endif
endif

ifdef VENUS_MMI
  ifneq ($(strip $(VENUS_MMI)),NONE)
    LNKOPT += --keep=*vpi*
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    LNKOPT      =  -map -info sizes,totals -symbols -xref -remove -verbose
  else
    LNKOPT      =  -map -info sizes,totals -symbols -xref -remove
  endif
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
        LNKOPT      +=  -first LARGEPOOL_FIRST_ZI
      endif
    endif
  endif
endif

ifeq ($(strip $(FLAVOR)),NON_DEBUG)
  LNKOPT = -remove -map
endif

# -----------------------------
# Binary tool options
# -----------------------------
BIN_FORMAT  =  -bin

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifneq ($(findstring TECH,$(strip $(subst _, ,$(OPTR_SPEC)))),)
      OPTR_SPEC  := $(strip $(subst _TECH, ,$(OPTR_SPEC)))
      OPTR_DEFS   +=  __OP_TECH_REL__
      OPTR_DEFS   +=  __$(strip $(OPTR_SPEC))_TECH__
      ifdef OPTR_CODE
        OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))_$(word 3,$(subst _, ,$(OPTR_SPEC))))_TECH__
      endif
    endif
    ifdef OPTR_CODE
      OPTR_DEFS   +=  __$(strip $(OPTR_CODE))__
      OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))__
      OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))_$(word 3,$(subst _, ,$(OPTR_SPEC))))__
    endif
  endif
endif

# -----------------------------
# custom release library path
# -----------------------------
SWITCH_FOLDER = $(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT)\)
CUS_MTK_LIB = mtk_lib

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    SWITCH_FOLDER   := $(join $(SWITCH_FOLDER),$(strip $(OPTR_SPEC))\)
  endif
  ifdef SWITCHABLE_FEATURE
    ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
      ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
        KAL_TRACE_LIB_FOLDER := $(shell dir $(CUS_MTK_LIB)\$(SWITCH_FOLDER)$(strip $(SWITCHABLE_FEATURE))\NONE /b 2>nul)
        ifneq ($(words $(strip $(KAL_TRACE_LIB_FOLDER))),0)
          SWITCH_FOLDER   := $(join $(SWITCH_FOLDER),$(strip $(SWITCHABLE_FEATURE))\NONE\)
        else
          SWITCH_FOLDER   := $(join $(SWITCH_FOLDER),$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\)
          SWITCH_FOLDER   := $(subst KAL_FULL,KAL_NONE,$(SWITCH_FOLDER))
        endif
      else
        SWITCH_FOLDER   := $(join $(SWITCH_FOLDER),$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\)
      endif
    endif
  endif
  ifdef SWITCHABLE_FEATURE_2ND
    ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
      SWITCH_FOLDER   := $(join $(SWITCH_FOLDER),$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\)
    endif
  endif
endif
SWITCH_FOLDER := $(patsubst %\,%, $(SWITCH_FOLDER))

ifneq ($(strip $(SWITCH_FOLDER)),)
  CUS_MTK_LIB := $(join $(CUS_MTK_LIB),\$(strip $(SWITCH_FOLDER)))
  ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
    ifneq ($(words $(strip $(KAL_TRACE_LIB_FOLDER))),0)
      CUS_MTK_LIB_TRACE := $(subst $(strip $(SWITCHABLE_FEATURE))\NONE,$(strip $(SWITCHABLE_FEATURE))\FULL,$(CUS_MTK_LIB))
    else
      CUS_MTK_LIB_TRACE := $(subst KAL_NONE,KAL_FULL,$(CUS_MTK_LIB))
    endif
  endif
endif

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COMMINCDIRS  += $(strip $(OPTR_PATH))
    OPERATOR_COMMON_PLUTO = $(shell dir operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\plutommi /b 2>nul)
    OPERATOR_COMMON_VENUS = $(shell dir operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\venusmmi /b 2>nul)
    ifneq ($(words $(strip $(OPERATOR_COMMON_PLUTO))),0)
      COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\plutommi
    endif
    ifneq ($(words $(strip $(OPERATOR_COMMON_VENUS))),0)
      COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\venusmmi
    endif
    COMMINCDIRS  += $(strip $(OPTR_PATH))\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))
    COMMINCDIRS  += $(strip $(OPTR_PATH))\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app
    COMMINCDIRS  += $(strip $(OPTR_PATH))\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\common
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6226)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6227,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226M)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226M,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226M,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6229)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6229,6230,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6229,6230,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6230)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6230,6229,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6230,6229,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223,6223P,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223,6223P,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223P)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223P,6223,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223P,6223,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6238)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6238,6239,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6238,6239,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6239)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6239,6238,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6239,6238,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6235)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6235,6235B,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6235,6235B,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6235B)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6235B,6235,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6235B,6235,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif

# *************************************************************************
# Common include file and output directory path
# *************************************************************************

CUS_REL_FILES_LIST   +=  interface\middleware\mtp_struct.h
CUS_REL_FILES_LIST   +=  usb\include\usbimage_drv.h \
                         usb\include\usbimage_mtp_state.h
CUS_REL_FILES_LIST   +=  usb\include\usbvideo_drv.h \
                         usb\include\usbvideo_state.h

COMMINCDIRS += interface\nvram
COMMINCDIRS   +=  custom\system\$(strip $(BOARD_VER))

ifeq ($(strip $(CUST_CODE)),TC01)
  COMMINCDIRS += custom\system\$(strip $(BOARD_VER))\ERS
endif

COMMINCDIRS   +=  interface\wap \
                  interface\browser \
                  interface\inet_ps \
                  interface\misc_ps \
                  interface\gps
                  

COMMINCDIRS   +=  wapadp\include \
                  drm\include

COMMINCDIRS   +=  drv\include

COMMINCDIRS   +=  inet_ps\email\inc \
                  inet_ps\email\pop3\inc \
                  inet_ps\email\smtp\inc \
                  inet_ps\email\imap\inc \
                  inet_ps\emlst\inc \
                  inet_ps\interfaces\local_inc

COMMINCDIRS   +=  applib\asn1\include

COMMINCDIRS   += plutommi\Framework\CommonScreens\CommonScreensInc
COMMINCDIRS   += plutommi\MMI\UnifiedMessage\UnifiedMessageInc
COMMINCDIRS   += plutommi\Service\Inc
COMMINCDIRS   += plutommi\Service\UmSrv
COMMINCDIRS   += plutommi\MtkApp\DLAgent\DLAgentInc
COMMINCDIRS   += plutommi\Service\DLAgentSrv
COMMINCDIRS   += plutommi\mtkapp\CentralConfigAgent\CentralConfigAgentInc
COMMINCDIRS   += venusmmi\framework\ui_core\base
COMMINCDIRS   += venusmmi\app\pluto_variation\adapter\ShellApp\panel\ImageViewer
COMMINCDIRS   += plutommi\MMI\Organizer\OrganizerInc

COMMINCDIRS   += custom\common\$(strip $(MMI_BASE))
CUS_REL_BASE_COMP += custom\common\$(strip $(MMI_BASE))

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COMMINCDIRS   +=  plutommi\Framework\CommonFiles\CommonInc \
                    plutommi\MMI\MiscFramework\MiscFrameworkInc \
                    plutommi\Framework\DebugLevels\DebugLevelInc \
                    plutommi\Framework\GUI\GUI_INC \
                    plutommi\MtkApp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
                    plutommi\MtkApp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
                    plutommi\MtkApp\FactoryMode\FactoryModeInc \
                    plutommi\Customer\CustomerInc
  CUS_REL_FILES_LIST += interface\hal\graphics\app_zlib.h
  CUS_REL_FILES_LIST += plutommi\Service\UcmSrv\UcmSrvResDef.h
  CUS_REL_BASE_COMP  += plutommi\Customer\Binary
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  COMMINCDIRS   +=  plutommi\Framework\CommonFiles\CommonInc \
                    plutommi\MMI\MiscFramework\MiscFrameworkInc \
                    plutommi\Framework\DebugLevels\DebugLevelInc \
                    plutommi\Framework\GUI\GUI_INC \
                    plutommi\MtkApp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
                    plutommi\MtkApp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
                    plutommi\MtkApp\FactoryMode\FactoryModeInc \
                    plutommi\Customer\CustomerInc
  CUS_REL_FILES_LIST += interface\hal\graphics\app_zlib.h
  CUS_REL_FILES_LIST += plutommi\Service\UcmSrv\UcmSrvResDef.h
  CUS_REL_BASE_COMP  += plutommi\Customer\Binary
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  COMMINCDIRS   +=  plutommi\MtkApp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
                    plutommi\MtkApp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
                    plutommi\MtkApp\FactoryMode\FactoryModeInc \
                    plutommi\Customer\CustomerInc
  CUS_REL_FILES_LIST += interface\hal\graphics\app_zlib.h
  CUS_REL_FILES_LIST += plutommi\Service\UcmSrv\UcmSrvResDef.h
  CUS_REL_BASE_COMP  += plutommi\Customer\Binary
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  COMMINCDIRS +=  lcmmi\mmi\Inc
  COMMINCDIRS += lcmmi\mmi\Inc\MenuID
else
  COMMINCDIRS   +=  plutommi\mmi\Inc plutommi\Framework\Interface
  COMMINCDIRS   +=  plutommi\MMI\Inc\MenuID
  COMMINCDIRS   +=  plutommi\Framework\CommonFiles\commoninc
  COMMINCDIRS   +=  plutommi\Framework\CommonFiles\commoninc\depreciation
  COMMINCDIRS   +=  applib\mem\include

  CUS_REL_FILES_LIST += plutommi\Customer\CustResource\VenusSysThemeCFG.xml \
                        plutommi\Customer\CustResource\VenusTheme1.xml \
                        plutommi\Customer\CustResource\VenusTheme2.xml \
                        plutommi\Customer\CustResource\VenusTheme3.xml \
                        plutommi\Customer\CustResource\VenusAppIcon1.xml \
                        plutommi\Customer\CustResource\VenusAppIcon2.xml

endif

ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
    COMPLIST       += fmt
  endif
endif

ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
  ifneq ($(filter fmt,$(COMPLIST)),)
    $(warning ERROR: Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when fmt module is defined in COMPLIST)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
    ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
        ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
          ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
            $(warning ERROR: Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when MSDC_CARD_SUPPORT_TYPE is set as MSDC_SD_MMC!)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifneq ($(filter MULTIPLE_BINARY_FILES,$(CUSTOM_OPTION)),)
  $(warning ERROR: Please remove invalid compile optoin MULTIPLE_BINARY_FILES from CUSTOM_OPTION and set feature option MULTIPLE_BINARY_FILES as TRUE!)
  DEPENDENCY_CONFLICT = TRUE
endif

# Global trace file definition
COMP_TRACE_DEFS += fs\common\include\fs_trc.h
COMP_TRACE_DEFS += hal\system\init\inc\system_trc.h

ISP_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B
ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(ISP_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support ISP)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += ISP_SUPPORT
  endif
endif
ifeq ($(strip $(ISP_SUPPORT)),TRUE)
  ifeq ($(strip $(JPG_DECODE)),FALSE)
    $(warning ERROR: Please set JPG_DECODE = TRUE when ISP_SUPPORT is enabled.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(JPG_ENCODE)),FALSE)
    $(warning ERROR: Please set JPG_ENCODE = TRUE when ISP_SUPPORT is enabled.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),INSIGNIA_DM)
    COMMINCDIRS  += vendor\dm\signia\adaptation\task\inc
    COMMINCDIRS  += vendor\dm\signia\adaptation\wrapper\inc
    COMP_TRACE_DEFS   += vendor\dm\signia\adaptation\task\inc\dm_trc.h
  endif
endif

ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
    COMP_TRACE_DEFS += security\seclib\include\seclib_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_os_adp_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_crypto_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_pki_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\pki\include\ossl_pki_adp_trc.h
endif

ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
    COMP_TRACE_DEFS += security\seclib\include\seclib_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_os_adp_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_crypto_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_pki_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\pki\include\ossl_pki_adp_trc.h
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COMMINCDIRS     +=  interface\security
    COMMINCDIRS     +=  applib\misc\include
    COMMINCDIRS     +=  security\certman\include
    COMMINCDIRS     +=  plutommi\mmi\CertificateManager\CertificateManagerMMIInc
    COMP_TRACE_DEFS += security\certman\include\certman_trc.h
  else 
    COMMINCDIRS     +=  interface\security
    COMMINCDIRS     +=  applib\misc\include
  endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
     COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_ssl_trc.h
     COMP_TRACE_DEFS += security\openssl\adaptation\ssl\include\ossl_ssladp_trc.h     
  endif

  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
     COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_ssl_trc.h
     COMP_TRACE_DEFS += security\openssl\adaptation\ssl\include\ossl_ssladp_trc.h     
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)), TRUE)
    COMMINCDIRS     += interface\security
    COMP_TRACE_DEFS += security\tls\include\tls_trc.h
  endif
endif

BROWSER_SUPPORT_Q03C_TYPES = OBIGO_Q03C OBIGO_Q03C_SLIM

ifeq ($(strip $(WAP_MMS_FEATURES)),FULL)
  $(warning ERROR: WAP_MMS_FEATURES = FULL is not currently supported, please choose another option)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
  ifeq ($(strip $(MMS_SUPPORT)),NONE)
    ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
      $(warning ERROR: Please turn ON BROWSER_SUPPORT / MMS_SUPPORT to use WAP_MMS_FEATURES or set WAP_MMS_FEATURES = NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef XYSSL_SUPPORT
  ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
    ifeq ($(strip $(XYSSL_SUPPORT)),TRUE)
      ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
#          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,XYSSL_SUPPORT)
#          DEPENDENCY_CONFLICT = TRUE
        endif
        ifneq ($(strip $(OBIGO_FEATURE)),WAP_SEC)
          ifneq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
            ifneq ($(strip $(OBIGO_FEATURE)),WAP2_SEC_HTTP_ONLY)
#             $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP_SEC/WAP2_SEC/WAP2_SEC_HTTP_ONLY,XYSSL_SUPPORT)
#             DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        endif
      endif
      COMMINCDIRS     += interface\security
      COMMINCDIRS     += security\xyssl\adaptation\system\include
      COM_DEFS    += __XYSSL_SUPPORT__
      COMPLIST    += xyssl xyssl_adp
      COMMINCDIRS     += security\xyssl\v1_official\ssl\include
  endif
  else
    ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM_SECURITY)
      COMMINCDIRS     += interface\security
      COMMINCDIRS     += security\xyssl\adaptation\system\include
      COM_DEFS    += __XYSSL_SUPPORT__
      COMPLIST    += xyssl xyssl_adp
      COMMINCDIRS     += security\xyssl\v1_official\ssl\include
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(RVCT_VERSION)),V22)
    AUDLIB         =  hal\audio\lib\MTKRVCT22
  endif
  ifeq ($(strip $(RVCT_VERSION)),V31)
    AUDLIB         =  hal\audio\lib\MTKRVCT31
  endif
endif
# *************************************************************************
# Component Compile Options
# *************************************************************************

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COM_DEFS    += $(OPTR_DEFS)
  endif
endif

ifndef FLAVOR
   COM_DEFS     += __FLAVOR_NOT_PRESENT__
endif

ifdef FLAVOR
  ifneq ($(strip $(FLAVOR)),NONE)
    COM_DEFS    += __FLAVOR_$(strip $(FLAVOR))__
  else
    COM_DEFS    += __FLAVOR_NOT_PRESENT__
  endif
endif

ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
  ifneq ($(strip $(KAL_DEBUG_LEVEL)), RELEASE_KAL)
    $(warning ERROR: Please set KAL_DEBUG_LEVEL=RELEASE_KAL when  IC_TEST_TYPE = IC_BURNIN_TEST ) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SLT_ENHANCE
  ifneq ($(strip $(SLT_ENHANCE)),NONE)
    ifneq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
      $(warning ERROR: Please set IC_TEST_TYPE = IC_MODULE_TEST when SLT_ENHANCE is not NONE. )
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef KAL_TRACE_OUTPUT
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),NONE)
    COM_DEFS += MODULE_TRACE_OFF
  endif
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
    COM_DEFS += MODULE_TRACE_OFF
  endif
endif

ifdef KAL_DEBUG_LEVEL
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),RICH_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_BUF3 DEBUG_ITC DEBUG_SWLA DEBUG_TIMER
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_BUF3 DEBUG_ITC DEBUG_SWLA DEBUG_TIMER
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),NORMAL_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_ITC
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_ITC
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),SLIM_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF1
    DEP_DEBUG_COMPILE_OPTION = DEBUG_KAL DEBUG_BUF1
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  # dependency rule for KAL,BUFFER & ITC debug compile options
  ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),)
    ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(sort $(strip $(DEP_DEBUG_COMPILE_OPTION))))
      DISABLED_DEBUG_COMPILE_OPTION = $(filter-out $(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(strip $(DEP_DEBUG_COMPILE_OPTION)))
      $(warning ERROR: PLEASE turn on $(DISABLED_DEBUG_COMPILE_OPTION) or turn off $(ENABLED_DEBUG_COMPILE_OPTION))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  # end
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),RELEASE_KAL)
    COM_DEFS += RELEASE_KAL
    DEP_DEBUG_COMPILE_OPTION =
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
endif

ifneq (,$(findstring ARM9EJ,$(strip $(CFLAGS))))
  COM_DEFS += __KAL_VM__
endif
ifneq (,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
  COM_DEFS += __KAL_VM__
endif

ifdef KAL_STACK_LAYOUT
  ifeq ($(strip $(KAL_STACK_LAYOUT)),ISOLATE)
    ifeq (,$(findstring ARM9EJ,$(strip $(CFLAGS))))
      ifeq (,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
        $(warning ERROR: Please set KAL_STACK_LAYOUT=SIMPLE on non-ARM9 or non-ARM11 platform)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS += __KAL_STACK_ISOLATION__
  endif
  ifeq ($(strip $(KAL_STACK_LAYOUT)),EXTENSIBLE)
    ifeq (,$(findstring ARM9EJ,$(strip $(CFLAGS))))
      ifeq (,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
        $(warning ERROR: Please set KAL_STACK_LAYOUT=SIMPLE on non-ARM9 or non-ARM11 platform)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS += __KAL_STACK_ISOLATION__ __KAL_STACK_EXTENSIBLE__
  endif
  ifeq ($(strip $(KAL_STACK_LAYOUT)),SHARING)
    COM_DEFS += __KAL_STACK_SHARING__
  endif
endif

COM_DEFS    += __BLIND_HANDOVER__

COM_DEFS    +=  IDLE_TASK _DEBUG MTK_KAL  __MTK_TARGET__

COM_DEFS    +=  SME_NOT_PRESENT SME_READER_NOT_PRESENT STDC_HEADERS TARGET_BUILD

COM_DEFS    += DEBUG_LEVEL=0

ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
  COM_DEFS    += __MSLT__
endif

ifeq ($(strip $(COMPILER)),RVCT)
  COM_DEFS += __RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
  COM_DEFS += __ADS__
endif

ifdef OPTR_SPEC
    ifeq ($(strip $(OPTR_SPEC)),NONE)
       COM_DEFS += __OPTR_NONE__
    endif
endif

ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    COM_DEFS   += MTK_INTERNAL_MMI_FEATURES
    COM_DEFS   += __MTK_INTERNAL__  
  endif
endif

ifneq ($(strip $(WIFI_SUPPORT)),NONE)
  COM_DEFS += WIFI_BLACKLIST
  COM_DEFS += WIFI_PORT_TIMER
endif

MMI_SWITCH = $(shell dir .\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch$(strip $(ORIGINAL_CUSTOMER)).h /b 2>nul)
MMI_FLAVOR_SWITCH = $(shell dir .\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch$(strip $(ORIGINAL_CUSTOMER))($(strip $(FLAVOR))).h /b 2>nul)
ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),FALSE)
        COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
      else
        ifdef FLAVOR
          ifneq ($(strip $(FLAVOR)),NONE)
            ifeq ($(words $(strip $(MMI_SWITCH))),0)
              ifeq ($(words $(strip $(MMI_FLAVOR_SWITCH))),0)
                ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
                  $(warning ERROR: .\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch$(strip $(ORIGINAL_CUSTOMER)).h or MMI_features_switch$(strip $(ORIGINAL_CUSTOMER))($(strip $(FLAVOR))).h shoule exist when MMI_FEATURES_SWITCH is TRUE)
                  DEPENDENCY_CONFLICT = TRUE
                endif
              endif
            endif
          else
            ifeq ($(words $(strip $(MMI_SWITCH))),0)
              ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
                $(warning ERROR: .\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch$(strip $(ORIGINAL_CUSTOMER)).h shoule exist when MMI_FEATURES_SWITCH is TRUE)
                DEPENDENCY_CONFLICT = TRUE
              endif
            endif
          endif
        endif
      endif
    else
      COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
    endif
  endif
endif

ifdef OBIGO_FEATURE
  ifneq ($(strip $(OBIGO_FEATURE)),NONE)
    COMMINCDIRS      += plutommi\Service\UPPSrv
  endif
endif

ifdef WAP_MMS_FEATURES
  ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
    COMMINCDIRS      += plutommi\Service\UPPSrv
  endif
endif

ifdef OBIGO_FEATURE
  ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
    ifneq ($(strip $(OBIGO_FEATURE)), NONE)
      ifneq ($(strip $(BROWSER_SUPPORT)), OBIGO_Q05A)
        COM_DEFS += Q03C_IND_MOD_ARCH_SUPPORT
        COM_DEFS += OBIGO_Q03C
        COMPLIST += obigo03cadp obigo03cfwadp obigo03cfwlib obigo03cstkadp obigo03cstklib
        COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
        COMP_TRACE_DEFS  += vendor\wap\obigo_Q03C\adaptation\integration\include\wap_trc.h
        
        ifdef LOW_COST_SUPPORT
          ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
            ifneq ($(strip $(LOW_COST_SUPPORT)),FALSE)
              COM_DEFS    +=  SLIM_WAP_MMS
            endif
          endif
        endif      
        
        ifdef TRANSCODING_PROXY_SUPPORT
          ifeq ($(strip $(TRANSCODING_PROXY_SUPPORT)),BAIDU)
            ifeq ($(filter $(strip $(BROWSER_SUPPORT)) ,$(BROWSER_SUPPORT_Q03C_TYPES)),)
              $(call DEP_ERR_SETA_OR_OFFB,BROWSER_SUPPORT,OBIGO_Q03C,TRANSCODING_PROXY_SUPPORT)
              DEPENDENCY_CONFLICT = TRUE
            endif
            ifneq ($(filter $(strip $(BROWSER_SUPPORT)) ,$(BROWSER_SUPPORT_Q03C_TYPES)),)
              COM_DEFS    +=  __BAIDU_TRANSCODING_SUPPORT__
            endif
          endif
        endif
      endif
    endif
  else
    ifdef TRANSCODING_PROXY_SUPPORT
      ifeq ($(strip $(TRANSCODING_PROXY_SUPPORT)),BAIDU)
        ifneq ($(filter $(strip $(BROWSER_SUPPORT)) ,$(BROWSER_SUPPORT_Q03C_TYPES)),)
          COM_DEFS    +=  __BAIDU_TRANSCODING_SUPPORT__
        endif
      endif
    endif

    COM_DEFS += Q03C_IND_MOD_ARCH_SUPPORT
    COM_DEFS += OBIGO_Q03C
    COMPLIST += obigo03cadp obigo03cfwadp obigo03cfwlib obigo03cstkadp obigo03cstklib
    COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
    COMP_TRACE_DEFS  += vendor\wap\obigo_Q03C\adaptation\integration\include\wap_trc.h  
    ifeq ($(strip $(WAP_MMS_FEATURES)),FULL)  
        COM_DEFS    += WAP_SUPPORT WAP2  WAP_SEC_SUPPORT  
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM_SECURITY)  
      COM_DEFS    +=  SLIM_WAP_MMS
      COM_DEFS    += WAP_SUPPORT WAP2 WAP_XYSSL_SUPPORT
      ifeq ($(strip $(MMS_SUPPORT)),NONE)
        COM_DEFS    += WAP2_HTTP
      endif       
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM)
        COM_DEFS    +=  SLIM_WAP_MMS
        COM_DEFS    += WAP_SUPPORT WAP2
    endif
  endif 
endif

ifdef RSAT_SUPPORT
  ifeq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,EMPTY_MMI,RSAT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __RSAT__
    endif
  endif
  ifeq ($(strip $(RSAT_SUPPORT)),MMI_WITH_RSAT)
    COM_DEFS    += __RSAT__
  endif
endif

ifdef UL1D_COSIM
  ifeq ($(strip $(UL1D_COSIM)),TRUE)
    ifeq ($(strip $(UL1D_LOOPBACK)),0)
      $(call DEP_ERR_SETA_OR_OFFB,UL1D_LOOPBACK,non 0,UL1D_COSIM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# *************************************************************************
# Include Java compile settings.
# *************************************************************************
-include make\JAVA_DEF.mak

# *************************************************************************
# Components
# *************************************************************************
# -----------------------------
# Common Components
# -----------------------------

AUTO_MERGE_FLR = custom\audio custom\drv\camera custom\drv\misc_drv custom\drv\mATV
AUTO_MERGE_PTH = $(foreach DIR,$(AUTO_MERGE_FLR),$(DIR)\$(strip $(BOARD_VER)) $(DIR)\_DEFAULT_BB\$(strip $(PLATFORM)))
COMMINCDIRS := $(AUTO_MERGE_PTH) $(COMMINCDIRS)

# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------

ifdef MMI_VERSION
  ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
    COMP_TRACE_DEFS += plutommi\Framework\Interface\mmi_fw_trc.h
    COMP_TRACE_DEFS += plutommi\Framework\Interface\pluto_fw_trc.h
    COMP_TRACE_DEFS += plutommi\Framework\GDI\GDIInc\gdi_trc.h
  endif
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
    COMP_TRACE_DEFS += plutommi\Framework\Interface\mmi_fw_trc.h
    COMP_TRACE_DEFS += plutommi\Framework\Interface\pluto_fw_trc.h
    COMP_TRACE_DEFS += plutommi\Framework\GDI\GDIInc\gdi_trc.h
  endif   
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_common_app_trc.h 
    COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_conn_app_trc.h
    COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_media_app_trc.h 
    COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_fw_trc.h 
  endif
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
    COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
    COMP_TRACE_DEFS += plutommi\Framework\Interface\mmi_fw_trc.h
    COMP_TRACE_DEFS += plutommi\Framework\Interface\pluto_fw_trc.h
    COMP_TRACE_DEFS += plutommi\Framework\GDI\GDIInc\gdi_trc.h
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
    COMP_TRACE_DEFS += inet_ps\email\inc\email_trace.h
    COMMINCDIRS += inet_ps\email\inc
    COMP_TRACE_DEFS += inet_ps\emlst\inc\emlst_trace.h
    COMMINCDIRS += inet_ps\emlst\inc
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    COMP_TRACE_DEFS += j2me\interface\j2me_trace.h
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      COMP_TRACE_DEFS += wifi\release\inc\wndrv_trc.h
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),MT5931)
      COMP_TRACE_DEFS += wifi\wndrv\MT5931\include\wndrv_trc.h
    endif
    COMP_TRACE_DEFS += wifi\supc\include\supc_trc.h
    COMP_TRACE_DEFS += inet_ps\dhcp\include\dhcp_trc.h
    COMMINCDIRS += inet_ps\dhcp\include
  endif
endif



ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    COMP_TRACE_DEFS += blueangel\btcore\btadp\inc\bluetooth_trc.h
    COMP_TRACE_DEFS += hal\bluetooth\common\include\btdrv_trc.h
    ifdef LOW_COST_SUPPORT
      ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
        ifneq ($(strip $(LOW_COST_SUPPORT)),FALSE)
          BT_SUPPORT_PROFILE_MAX_NUM = 10
        endif
      endif
    endif
    ifeq ($(origin BT_SUPPORT_PROFILE_MAX_NUM), undefined)
      BT_SUPPORT_PROFILE_MAX_NUM = 23
    endif
    COM_DEFS += BT_SUPPORT_PROFILE_MAX_NUM=$(strip $(BT_SUPPORT_PROFILE_MAX_NUM))
  endif
endif

ifdef BROWSER_SUPPORT
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
     COMP_TRACE_DEFS  += vendor\wap\obigo_q05a\adaptation\integration\include\wap_trc.h
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
     COMP_TRACE_DEFS  += vendor\opera\browser\adaptation\inc\opera_adp_trc.h
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_TURBO)
     COMP_TRACE_DEFS  += vendor\opera\browser\adaptation\inc\opera_adp_trc.h
  endif
endif

#
# Check the dependency of each options
#
ifeq ($(strip $(TINY_SYS)),TRUE)
  ifeq ($(filter __EVENT_BASED_TIMER__,$(COM_DEFS)),)
    $(warning ERROR: EVENT_BASED_TIMER must be enabled when TINY_SYS = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
  ifneq ($(strip $(OBIGO_FEATURE)),NONE)
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,OBIGO_FEATURE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
      ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),FALSE)
        $(call DEP_ERR_SETA_OR_ONB,BROWSER_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_FOLDER)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
else
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(warning ERROR: WAP and MMS require TCPIP, Turn ON TCPIP or Turn OFF WAP and MMS both.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      COM_DEFS   +=  __MIDI_DEVICE_CONTROL__
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,J2ME_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef PLATFORM
      ifeq ($(strip $(PLATFORM)),MT6223)
        ifneq ($(strip $(J2ME_SUPPORT)),NONE)
          $(warning ERROR: MT6223 does not support J2ME_SUPPORT yet)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,J2ME_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef J2ME_SUPPORT
  ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
    ifdef J2ME_MAX_LAUNCH_NUM
      ifeq ($(strip $(J2ME_MAX_LAUNCH_NUM)),0)
        $(warning ERROR: when J2ME_SUPPORT is set to MTK_DUMMY_MVM , J2ME_MAX_LAUNCH_NUM must not be 0.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(warning ERROR: when J2ME_SUPPORT is set to MTK_DUMMY_MVM , J2ME_MAX_LAUNCH_NUM must not be 0.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
    ifdef J2ME_MAX_LAUNCH_NUM
      ifeq ($(strip $(J2ME_MAX_LAUNCH_NUM)),0)
        $(warning ERROR: when J2ME_SUPPORT is set to NEMO , J2ME_MAX_LAUNCH_NUM must not be 0.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(warning ERROR: when J2ME_SUPPORT is set to NEMO , J2ME_MAX_LAUNCH_NUM must not be 0.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
    ifdef J2ME_MAX_LAUNCH_NUM
      ifeq ($(strip $(J2ME_MAX_LAUNCH_NUM)),0)
        $(warning ERROR: when J2ME_SUPPORT is set to JBLENDIA_MVM , J2ME_MAX_LAUNCH_NUM must not be 0.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(warning ERROR: when J2ME_SUPPORT is set to JBLENDIA_MVM , J2ME_MAX_LAUNCH_NUM must not be 0.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef IMPS_SUPPORT
  ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
    ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,IMPS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,IMPS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,IMPS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      $(warning ERROR: Please turn off IMPS_SUPPORT on COSMOS MMI Project!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifeq ($(filter WS NONE,$(strip $(DRM_SUPPORT))),)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)     
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,DRM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
     ifeq ($(filter FMT_NOT_PRESENT,$(COM_DEFS)),FMT_NOT_PRESENT)
        $(warning ERROR: Please turn off DRM_SUPPORT when FMT_NOT_PRESENT!) 
        DEPENDENCY_CONFLICT = TRUE
     endif              
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,TCP/UDP_TCP,EMAIL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
      $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,TCP/UDP_TCP,EMAIL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef SOCKET_SSL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SOCKET_SSL_SUPPORT,EMAIL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SOCKET_SSL_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,SOCKET_SSL_SUPPORT,EMAIL_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

# WIFI_BB_MODULE Options
COM_DEFS_FOR_MT5921       = WIFI_BB_MT5921
COM_DEFS_FOR_NONE         = WIFI_BB_NONE

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),MT5931)
    COM_DEFS_FOR_WIFI_BB_MODULE =  COM_DEFS_FOR_$(strip $(WIFI_SUPPORT))
    ifdef $(COM_DEFS_FOR_WIFI_BB_MODULE)
      COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(WIFI_SUPPORT)))
    else
      $(warning ERROR: WIFI_BB_MODULE = $(strip $(WIFI_SUPPORT)) is not defined!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# WIFI_RF_MODULE Options
COM_DEFS_FOR_AL2236      = WIFI_RF_AL2236
COM_DEFS_FOR_NONE        = WIFI_RF_NONE

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS   +=  $(COM_DEFS_FOR_NONE)
  endif
endif

ifdef STREAM_SUPPORT
  ifneq ($(strip $(STREAM_SUPPORT)),FALSE)
    ifeq ($(strip $(SDP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RTSP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,RTSP_SUPPORT,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AAC_DECODE)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MP4_DECODE)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,STREAM_SUPPORT)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
     COM_DEFS += STREAM_SUPPORT
     COMPLIST += media_rtp
  endif
endif

ifdef STREAM_SERVER_SUPPORT
  ifneq ($(strip $(STREAM_SERVER_SUPPORT)),FALSE)
    ifeq ($(strip $(SDP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,STREAM_SERVER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RTSP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,RTSP_SUPPORT,STREAM_SERVER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(STREAM_SERVER_SUPPORT)),TRUE)
    COM_DEFS += __STREAM_SERVER_SUPPORT__
    COMPLIST += media_rtp
  endif
endif

ifdef VAD_SUPPORT
  ifeq ($(strip $(VAD_SUPPORT)),TRUE)
    COM_DEFS += __VAD_SUPPORT__
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    COMPLIST        += 3g324m
    COMP_TRACE_DEFS += 3g324m\appl\inc\vt_trc.h
    COM_DEFS   += __MEDIA_VT__ __VIDEO_CALL_SUPPORT__
  endif
endif

ifdef SP_VIDEO_CALL_SUPPORT
  ifeq ($(strip $(SP_VIDEO_CALL_SUPPORT)),TRUE)
    ifdef 3G_VIDEO_CALL
      ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
        $(warning ERROR: 3G_VIDEO_CALL, SP_VIDEO_CALL_SUPPORT can not enable at the same time)
      endif
    endif
    COMPLIST        += 3g324m_tvt
    COMP_TRACE_DEFS += 3g324m\tvt\inc\TVT_trc.h
    COM_DEFS   += __VT_TRANSPORT_SUPPORT__ __VIDEO_CALL_SUPPORT__
  endif
endif

ifdef UUS_SUPPORT
  ifeq ($(strip $(UUS_SUPPORT)),TRUE)
     COM_DEFS    += __UUS_SUPPORT__
  endif   
endif

ifdef EMLPP_SUPPORT
  ifeq ($(strip $(EMLPP_SUPPORT)),TRUE)
     COM_DEFS    += __EMLPP_SUPPORT__
  endif   
endif

MTV_SUPPORT_ADD_MODULE_CONDITION = FALSE
MTV_SUPPORT_ADD_OPTION_CONDITION = FALSE

ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    MTV_SUPPORT_ADD_MODULE_CONDITION = TRUE
    MTV_SUPPORT_ADD_OPTION_CONDITION = TRUE
  endif
endif

ifdef ATV_SUPPORT
  ifneq ($(strip $(ATV_SUPPORT)),FALSE)
    ifndef ATV_CHIP
      $(warning ERROR: PLEASE set ATV_CHIP as VRE00 or VRE01 when ATV_SUPPORT = $(ATV_SUPPORT))
      DEPENDENCY_CONFLICT = TRUE
    endif
    MTV_SUPPORT_ADD_MODULE_CONDITION = TRUE
    MTV_SUPPORT_ADD_OPTION_CONDITION = TRUE
    COMPLIST         += matv_sec

    ATV_ISP_NOT_SUPPORT_PLATFORM = MT6223 MT6223P
    ifeq ($(filter $(strip $(PLATFORM)) ,$(ATV_ISP_NOT_SUPPORT_PLATFORM)),)
        COM_DEFS += YUV_SENSOR_SUPPORT
    endif
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      ifeq ($(strip $(ATV_SUPPORT)),TRUE)
      ifneq ($(strip $(ATV_RECORD_SUPPORT)), TRUE)
        $(warning ERROR: PLEASE set ATV_RECORD_SUPPORT as TRUE when ATV_SUPPORT = $(ATV_SUPPORT) and MMI_VERSION = $(MMI_VERSION) )
        DEPENDENCY_CONFLICT = TRUE
      endif
      endif
      ifneq ($(strip $(ATV_SMS_SUPPORT)), FALSE)
        $(warning ERROR: PLEASE set ATV_SMS_SUPPORT as FALSE when ATV_SUPPORT = $(ATV_SUPPORT) and MMI_VERSION = $(MMI_VERSION) )
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  else
    ifeq ($(strip $(ATV_SUPPORT)),FALSE)
      ifdef FM_RADIO_CHIP
        ifeq ($(strip $(FM_RADIO_CHIP)),MT5192FM)
          $(warning ERROR: PLEASE Not set FM_RADIO_CHIP to be MT5192FM when ATV_SUPPORT = $(ATV_SUPPORT))
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(FM_RADIO_CHIP)),MT5193FM)
          $(warning ERROR: PLEASE Not set FM_RADIO_CHIP to be MT5193FM when ATV_SUPPORT = $(ATV_SUPPORT))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(MTV_SUPPORT_ADD_MODULE_CONDITION)),TRUE)
  COMPLIST += mtv
  ifneq ($(strip $(ATV_SUPPORT)),FALSE)
    COM_DEFS += __ATV_SUPPORT__ __ATV_DRV_OPTIMIZE__
    COMMINCDIRS +=  plutommi\MtkApp\MobileTVPlayer\MobileTVPlayerInc
    COMMINCDIRS    += custom\drv\mATV\$(strip $(ATV_CHIP))
  else
    ifeq ($(strip $(MTV_SUPPORT_ADD_OPTION_CONDITION)),TRUE)
      COM_DEFS += __MTV_SUPPORT__
      CUS_REL_FILES_LIST += MoDIS_VC9\MoDIS\Debug\SDL.dll \
                            MoDIS_VC9\MoDIS\Release\SDL.dll \
                            media\mtv\src\cmmb_ca_mmc.h
    endif
  endif
endif

COMPLIST         += matv

ifeq ($(strip $(PLATFORM)),MT6260)
  ifdef MMI_VERSION
    ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
      COM_DEFS    += __CAMERA_MATV_ESD_RECOVERY_SUPPORT__
    endif
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6276)
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
   COM_DEFS    += __BK_LIGHT_20LEVEL_SUPPORT__
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  FLC_LIB_INCLUDE_CONDITION = FALSE
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifeq ($(strip $(FAX_SUPPORT)),TRUE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
    COMPLIST += flc2
    COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\flc2\include\flc_trc.h
    COM_DEFS += __FLC2__ __FLC_SUPPORT__
  endif
endif

ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  COM_DEFS    += __PHB_0x81_SUPPORT__
endif

ifdef SYNCML_DM_SUPPORT
  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
    ifeq ($(strip $(OPTR_SPEC)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef OPTR_SPEC
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifndef OBIGO_FEATURE
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_DM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifdef OBIGO_FEATURE
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_DM_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
  ifeq ($(strip $(DEMO_PROJECT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,DEMO_PROJECT,MMI_FEATURES_SWITCH)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(L1_CATCHER)),TRUE)
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COM_DEFS    += L1_CATCHER
  endif
endif

ifeq ($(strip $(MTK_DSP_DEBUG)),TRUE)
  COM_DEFS    += MTK_DSP_DEBUG
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in L1S projects.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in BASIC projects.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in UDVT projects.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FAX_SUPPORT)),FALSE)
  ifneq ($(strip $(BT_FAX_PROFILE)),FALSE)
    $(warning ERROR: Please turn off BT_FAX_PROFILE when FAX_SUPPORT = FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifeq ($(strip $(CSD_SUPPORT)),NONE)
    $(warning ERROR: Please turn off FAX_SUPPORT when CSD_SUPPORT = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
      $(warning ERROR: Please turn off CSD_SUPPORT in $(strip $(call Upper,$(PROJECT))) project) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    # Support CSD
    COM_DEFS    += CSD_SUPPORT 
    ifeq ($(strip $(CSD_SUPPORT)),T_NT)
      COM_DEFS    += __CSD_NT__ __CSD_T__ __CSD_NT_2400__
    else
      ifeq ($(strip $(CSD_SUPPORT)),NT_ONLY)
        COM_DEFS    += __CSD_NT__ 
      else
        $(warning ERROR: CSD_SUPPORT setting is wrong) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += __CSD_FAX__
    endif
  else
    # FAX only, Not support CSD
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
    endif
  endif
else
  # FAX only, Not support CSD
  ifeq ($(strip $(FAX_SUPPORT)),TRUE)
    COM_DEFS    += CSD_SUPPORT __CSD_FAX__
  endif
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += KAL_ENH_MUTEX
else
  ifneq ($(filter __CS_SERVICE__,$(COM_DEFS)),)
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      COM_DEFS    += KAL_ENH_MUTEX
    endif
  endif
endif

ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
  ifeq ($(strip $(OBIGO_FEATURE)),WAP)
    COM_DEFS    += WAP_SUPPORT
  endif
  
  ifeq ($(strip $(OBIGO_FEATURE)),WAP2)
    COM_DEFS    += WAP_SUPPORT WAP2
  endif

  ifeq ($(strip $(XYSSL_SUPPORT)),TRUE)
    ifeq ($(strip $(OBIGO_FEATURE)),WAP_SEC)
      COM_DEFS    += WAP_SUPPORT WAP_XYSSL_SUPPORT
    endif
    ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
      COM_DEFS    += WAP_SUPPORT WAP2 WAP_XYSSL_SUPPORT
    endif
    ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC_HTTP_ONLY)
      COM_DEFS    += WAP_SUPPORT WAP2 WAP_XYSSL_SUPPORT WAP2_HTTP
    endif
        else
          ifeq ($(strip $(OBIGO_FEATURE)),WAP_SEC)
            COM_DEFS    += WAP_SUPPORT WAP_SEC_SUPPORT
          endif
          ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
            COM_DEFS    += WAP_SUPPORT WAP2  WAP_SEC_SUPPORT
          endif
          ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC_HTTP_ONLY)
            COM_DEFS    += WAP_SUPPORT WAP2  WAP_SEC_SUPPORT WAP2_HTTP
    endif
        endif

  ifeq ($(strip $(OBIGO_FEATURE)),WAP2_HTTP_ONLY)
    COM_DEFS    += WAP_SUPPORT WAP2 WAP2_HTTP
  endif

  ifeq ($(strip $(OBIGO_FEATURE)),NONE)
    COM_DEFS    += WAP_NOT_PRESENT
  endif
endif

ifdef DRM_SUPPORT
  COMPLIST    += drm
  COMMINCDIRS     +=  applib\misc\include
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    COMP_TRACE_DEFS += drm\include\drm_trace.h
    ifneq ($(findstring BSCI,$(strip $(DRM_SUPPORT))),)
      BSCI_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6223 MT6223P MT6225 
      ifneq ($(filter $(strip $(PLATFORM)),$(BSCI_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: Please set DRM_SUPPORT=MTK and DRM_VESION=V01 for PLATFORM $(strip $(PLATFORM)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DRM_SUPPORT__ __DRM_BSCI__  __DRM_V01__ __DRM_V02__
      ifneq ($(strip $(PLATFORM)),MT6238)
        ifneq ($(strip $(PLATFORM)),MT6239)
          ifdef STREAM_SUPPORT
            ifdef PURE_AUDIO_SUPPORT
              ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
                $(warning ERROR: Please set PURE_AUDIO_SUPPORT as FALSE) 
                DEPENDENCY_CONFLICT = TRUE
              endif
            endif
            ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
              COM_DEFS   += __DRM_PDCF__
            endif
          endif
        endif
      endif
      ifeq ($(strip $(DRM_SUPPORT)),BSCI)
        COMPLIST    += drmadp_bsci
        COMPOBJS         += vendor\drm\bsci\bsci.lib
        CUS_REL_OBJ_LIST += vendor\drm\bsci\bsci.lib
        CUS_REL_BASE_COMP += vendor\drm\bsci\src\drmagent-v2\inc
        COMMINCDIRS   +=  vendor\drm\$(strip $(DRM_SUPPORT))\adp\include
      else
        ifeq ($(strip $(DRM_SUPPORT)),BSCI_SRC)
          COMPLIST    += bsci
          COMMINCDIRS   +=  vendor\drm\bsci\adp\include
        endif
      endif
    endif
    ifeq ($(strip $(DRM_SUPPORT)),MTK)
      COM_DEFS    += __DRM_SUPPORT__ __DRM_MTK__ __DRM_V01__
      COMPLIST    += drmadp_mtk
      COMMINCDIRS   +=  vendor\drm\MTK\adp\include
    endif
    ifeq ($(strip $(DRM_SUPPORT)),WS)
      COM_DEFS    += __DRM_SUPPORT__ __DRM_WS__ __DRM_V01__ __DRM_EXTERNAL__
      COMPLIST    += drmadp_ws
      COMMINCDIRS   +=  vendor\drm\WS\adp\include
    endif
  endif
endif

ifeq ($(strip $(DRM_VERSION)),V02)
 ifeq ($(strip $(DRM_SUPPORT)),MTK)
   $(warning ERROR: DRM_SUPPORT as MTK does not support DRM_VERSION as V02)
   DEPENDENCY_CONFLICT = TRUE
 endif
endif

ifeq ($(strip $(DRM_VERSION)),ALL)
 ifeq ($(strip $(DRM_SUPPORT)),MTK)
   $(warning ERROR: DRM_SUPPORT as MTK does not support DRM_VERSION as ALL)
   DEPENDENCY_CONFLICT = TRUE
 endif
endif

ifeq ($(strip $(FAST_UART)),TRUE)
  COM_DEFS    += __FAST_UART__
endif

ifeq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
   ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
      $(call DEP_ERR_OFFA_OR_OFFB,__TWO_KEY_DETECTION_SWITCHABLE__,__KBD_JOYSTICK_SUPPORT__)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BOOT_FAT_RESET
  ifeq ($(strip $(BOOT_FAT_RESET)),TRUE)
    COM_DEFS    += __BOOT_FAT_RESET__
  endif
endif

ifdef APP_STORAGE_IN_SYS_DRV
  ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),FALSE)
    ifdef MMS_SUPPORT
      COM_DEFS    += MMS_IN_LARGE_STORAGE
    endif
    ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
      COM_DEFS   += IMPS_IN_LARGE_STORAGE
    endif
  else
    COM_DEFS    += APP_STORAGE_IN_SYS_DRV
  endif
endif

ifdef FM_RADIO_CHIP
  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
    COM_DEFS  += $(FM_RADIO_CHIP)
    COM_DEFS  += FM_RADIO_ENABLE
    ifdef FM_RADIO_RECORD
      ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
        COM_DEFS  += FM_RADIO_RECORD
      endif
    endif
    COMPLIST         += fm_drv
    COMP_TRACE_DEFS += fmr\inc\fmr_trc.h
  endif
endif

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
    MSDC_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6251 MT6252 MT6252H MT6253E MT6253L MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MSDC_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support MSDC_CARD_SUPPORT_TYPE) 
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __FS_CARD_SUPPORT__
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_MMC)
        COM_DEFS += __MSDC_SD_MMC__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MS)
        COM_DEFS += __MSDC_MS__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MSPRO)
        COM_DEFS += __MSDC_MSPRO__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_SDIO)
        COM_DEFS += __MSDC_SD_MMC__ __MSDC_SD_SDIO__
      endif
    endif
  else
    ifeq ($(strip $(OTG_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,MSDC_CARD_SUPPORT_TYPE,OTG_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef TCPIP_SUPPORT
  ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
    COM_DEFS   += TCP_SUPPORT
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
    COM_DEFS   += UDP_SUPPORT
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
  endif
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    COM_DEFS   += __TCPIP__
    COMMINCDIRS   += inet_ps\tcpip\include
    ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),FALSE)
      COM_DEFS += __TCPIP_LOOP_BACK__
    endif
  endif
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      COMPLIST    += abm abm_custom soc tcpip tcpip_wifi applib_inet
    else
      COM_DEFS      += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
    endif
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      COMPLIST    += abm abm_custom soc tcpip tcpip_wifi applib_inet
    else
      COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
    endif
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      COMPLIST    += abm abm_custom soc tcpip tcpip_wifi applib_inet
    else
      COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT PPP_NOT_PRESENT
    endif
  endif 
  ifeq ($(strip $(call Upper,$(PROJECT))),NONE)
    COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT PPP_NOT_PRESENT
  endif
endif

ifndef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY = 256
endif

ifdef FS_SORT_SUPPORT
  ifeq ($(strip $(FS_SORT_SUPPORT)),TRUE)
    COM_DEFS   += __FS_SORT_SUPPORT__ FS_SORT_MAX_ENTRY=$(strip $(FS_SORT_MAX_ENTRY))
  endif
  ifeq ($(strip $(FS_SORT_SUPPORT)),FALSE)
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      $(warning ERROR: Please turn on FS_SORT_SUPPORT on COSMOS MMI Project!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef FS_OPEN_HINT_SUPPORT
  ifeq ($(strip $(FS_OPEN_HINT_SUPPORT)),TRUE)
     COM_DEFS   += __FS_OPEN_HINT__
  else
    ifdef FS_SORT_SUPPORT
      ifeq ($(strip $(FS_SORT_SUPPORT)),TRUE)
        ifdef FS_SORT_MAX_ENTRY
          ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),1000),T)
            $(warning ERROR: Please turn on FS_OPEN_HINT_SUPPORT for case FS_SORT_MAX_ENTRY > 1000)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifdef FS_DEDICATED_BUFFER
  ifeq ($(strip $(FS_DEDICATED_BUFFER)),TRUE)
     COM_DEFS   += __FS_DEDICATED_BUFFER__  
  endif
endif

ifdef FS_MAX_DISK_SIZE
  COM_DEFS   += FS_MAX_DISK_SIZE=$(strip $(FS_MAX_DISK_SIZE))
endif

ifdef FS_ASYNC_SUPPORT
  ifeq ($(strip $(FS_ASYNC_SUPPORT)),TRUE)
    COM_DEFS   += __FS_ASYNC_SUPPORT__
  endif
endif

ifdef FS_CHECKDRIVE_SUPPORT
  ifeq ($(strip $(FS_CHECKDRIVE_SUPPORT)),TRUE)
    COM_DEFS   += __FS_CHECKDRIVE_SUPPORT__
  endif
endif

ifdef FS_QM_SUPPORT
  ifeq ($(strip $(FS_QM_SUPPORT)),TRUE)
    COM_DEFS   += __FS_QM_SUPPORT__
  endif
endif

ifdef TST_SUPPORT
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      $(warning ERROR: TST_SUPPORT should be FALSE in BASIC project)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif



ifdef FS_TRACE_SUPPORT
  ifdef TST_SUPPORT
    ifeq ($(strip $(FS_TRACE_SUPPORT)),TRUE)
      ifeq ($(strip $(TST_SUPPORT)),TRUE)
        COM_DEFS   += __FS_TRACE_SUPPORT__
      else
        $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,FS_TRACE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COM_DEFS    += __EMAIL__  __EMAIL_AUTO_CHECK__ __POP3_LEAVE_COPY_ON_SERVER__
     COM_DEFS    += __EMAIL_DOWNLOAD_OPTION__  EMAIL_BCC  __EMAIL_USE_ASM_ADM__
     COM_DEFS    += __EMAIL_SORT_SUPPORT_SUBJECT__  __EMAIL_SORT_SUPPORT_SENDER__
     COM_DEFS    += __IMAP_REMOTE_FOLDER__  __EMAIL_APOP_SUPPORT__
     ifeq ($(strip $(EMAIL_SUPPORT)),SMTP_POP3)
        COM_DEFS    += __NO_IMAP__
     endif
  endif
endif

#BT_A2DP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_A2DP_PROFILE
  ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
    BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
    ifneq ($(filter $(strip $(PLATFORM)),$(BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support BT_A2DP_PROFILE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST += dp_engine
  endif
endif

#BT_AVRCP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_AVRCP_PROFILE
  ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
      ifneq ($(filter $(strip $(PLATFORM)),$(BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: Platform $(strip $(PLATFORM)) does not support BT_AVRCP_PROFILE!) 
          DEPENDENCY_CONFLICT = TRUE
      endif
  endif
endif

BLUETOOTH_SUPPORT_CHIP = BTMTK_MT6601 BTMTK_MT6611 BTMTK_MT6612 BTMTK_MT6236 BTMTK_MT6256 BTMTK_MT6276 BTMTK_MT6616 BTMTK_MT6622 BTMTK_MT6626 BTMTK_MT6612_22_26 BTMTK_MT6921 BTMTK_MT6612_22 BTMTK_MT6612_26 BTMTK_MT6622_26 BTMTK_MT6255 BTMTK_MT6922 BTMTK_MT6250 BTMTK_MT6260 BTMTK_MT6261 BTMTK_MT2501 BTMTK_MT2502
# NONE, BTMTK, BTMTK_MT6601, BTMTK_MT6611, BTMTK_MT6612, BTMTK_MT6236, BTMTK_MT6256, BTMTK_MT6276, BTMTK_MT6616 BTMTK_MT6612_22_26 BTMTK_MT6921 BTMTK_MT6255 BTMTK_MT6922 BTMTK_MT6250 BTMTK_MT6260 BTMTK_MT6261 BTMTK_MT2501 BTMTK_MT2502
BLUETOOTH_SUPPORT_SWITCH = BTMTK_MT6612 BTMTK_MT6622 BTMTK_MT6626
BT_LIB_SWITCH = FALSE
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_SWITCH)),)
      ifneq ($(strip $(DEMO_PROJECT)),TRUE)
        BT_LIB_SWITCH = TRUE
      endif
    endif
    COM_DEFS    +=  __BT_SUPPORT__
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      ifneq ($(strip $(PLATFORM)),MT6256)
        ifneq ($(strip $(PLATFORM)),MT6276)
          ifneq ($(strip $(PLATFORM)),MT6270A)
            $(call DEP_ERR_ONA_OR_OFFB,DMA_UART_VIRTUAL_FIFO,BLUETOOTH_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
    #ifneq ($(strip $(UART3_SUPPORT)),TRUE)
    #   $(call DEP_ERR_ONA_OR_OFFB,UART3_SUPPORT,BLUETOOTH_SUPPORT)
    #   DEPENDENCY_CONFLICT = TRUE
    #endif
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      ifneq ($(strip $(GEMINI)),FALSE)
        COM_DEFS    +=  __L4C_GEMINI_BT_HF__
      endif
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_RFMD3500__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6601__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6611__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__ __BTMODULE_MT6612_22_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6236)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6236__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6921)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6236__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6255)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6255__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6922)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6255__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6256)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6256__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6276)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6276__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6250)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6250__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6260)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6260__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6261)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6261__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT2501)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6261__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT2502)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6261__ __BRT_SUPPORT__ __BTMODULE_GSM_BT_SOC__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6616)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6616__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6622)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6622__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6626)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6626__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_22)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__ __BTMODULE_MT6622__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_26)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__ __BTMODULE_MT6626__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6622_26)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6622__ __BTMODULE_MT6626__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_22_26)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__ __BTMODULE_MT6622__ __BTMODULE_MT6626__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HFG_PROFILE__ __BT_SPK_VOL_CONTROL__
      ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
        COM_DEFS    +=  __HF_V15__
      endif
      ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
        COM_DEFS    +=  __HF_V15__
      endif
      BT_SUPPORT_PROFILE += BT_HFG_PROFILE  BT_HS_PROFILE
    endif
    ifeq ($(strip $(BT_HF_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HF_PROFILE__ __BT_SPK_VOL_CONTROL__
      BT_SUPPORT_PROFILE += BT_HF_PROFILE
    endif
    ifeq ($(strip $(BT_AUDIO_VIA_SCO)),TRUE)
      BT_AUDIO_VIA_SCO_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 MT6516 
      ifneq ($(filter $(strip $(PLATFORM)),$(BT_AUDIO_VIA_SCO_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BT_AUDIO_VIA_SCO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifdef FM_RADIO_CHIP
        ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
          ifneq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,BT_FM_RADIO_VIA_SCO,BT_AUDIO_VIA_SCO or FM_RADIO_CHIP)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
      COM_DEFS    +=  __BT_AUDIO_VIA_SCO__
      COM_DEFS    +=  __BT_INBAND_RING__
    endif
    ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
      ifdef FM_RADIO_CHIP
        ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
          COM_DEFS    +=  __BT_FM_VIA_SCO__
        endif
      endif
    endif
    ifeq ($(strip $(BT_GOEP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_GOEP_PROFILE__
      BT_SUPPORT_PROFILE += BT_GOEP_PROFILE
    endif
    ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
      ifneq ($(strip $(BT_GOEP_PROFILE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,BT_GOEP_PROFILE,BT_FTS_PROFILE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  __BT_FTS_PROFILE__
      BT_SUPPORT_PROFILE += BT_FTS_PROFILE
    endif
    ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
      ifneq ($(strip $(BT_GOEP_PROFILE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,BT_GOEP_PROFILE,BT_FTC_PROFILE)
        DEPENDENCY_CONFLICT = TRUE
      endif 
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_FTC_PROFILE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  __BT_FTC_PROFILE__
      BT_SUPPORT_PROFILE += BT_FTC_PROFILE
    endif
    ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
      ifneq ($(strip $(BT_GOEP_PROFILE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,BT_GOEP_PROFILE,BT_OPP_PROFILE)
        DEPENDENCY_CONFLICT = TRUE
      endif 
      COM_DEFS    +=  __BT_OPP_PROFILE__
      BT_SUPPORT_PROFILE += BT_OPP_PROFILE_CLIENT  BT_OPP_PROFILE_SERVER
    endif
    ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_DUN_PROFILE__
      BT_SUPPORT_PROFILE += BT_DUN_PROFILE
    endif

    ifeq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifneq ($(strip $(BT_SPP_SERVER)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_SUPPORT,BTMTK_MT6601/BTMTK_MT6611/BTMTK_MT6612/BTMTK_MT6236/BTMTK_MT6256/BTMTK_MT6276/BTMTK_MT6616/BTMTK_MT6622/BTMTK_MT6626/BTMTK_MT6612_22_26/BTMTK_MT6921/BTMTK_MT6255/BTMTK_MT6922/BTMTK_MT6250/BTMTK_MT6260/BTMTK_MT6261/BTMTK_MT2501/BTMTK_MT2502,BT_SPP_SERVER)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_SUPPORT,BTMTK_MT6601/BTMTK_MT6611/BTMTK_MT6612/BTMTK_MT6236/BTMTK_MT6256/BTMTK_MT6276/BTMTK_MT6616/BTMTK_MT6622/BTMTK_MT6626/BTMTK_MT6612_22_26/BTMTK_MT6921/BTMTK_MT6255/BTMTK_MT6922/BTMTK_MT6250/BTMTK_MT6260/BTMTK_MT6261/BTMTK_MT2501/BTMTK_MT2502,BT_SPP_CLIENT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifeq ($(strip $(BT_SPP_SERVER)),NONE)
        ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
          ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER & BT_SPP_CLIENT,BT_SPP_PROFILE)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
      ifneq ($(strip $(BT_SPP_SERVER)),NONE)
        ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_SPP_SERVER)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
        ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_SPP_CLIENT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif

    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
        COM_DEFS    +=  __BT_SPP_SRV_NO_SCO__
      endif
      ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_WITH_SCO)
        COM_DEFS    +=  __BT_SPP_SRV_WITH_SCO__
      endif
      ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_NO_SCO)
        COM_DEFS    +=  __BT_SPP_CLI_NO_SCO__
      endif
      ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_WITH_SCO)
        COM_DEFS    +=  __BT_SPP_CLI_WITH_SCO__
      endif
    endif

    ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_SPP_PROFILE__
      BT_SUPPORT_PROFILE += BT_SPP_PROFILE
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_A2DP_PROFILE__ __BT_A2DP_SUPPORT__
      BT_SUPPORT_PROFILE += BT_A2DP_PROFILE
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_AVRCP_PROFILE__
      BT_SUPPORT_PROFILE += BT_AVRCP_PROFILE  BT_AVRCP_PROFILE_TARGET
    endif
    ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_SIM_PROFILE__
      BT_SUPPORT_PROFILE += BT_SIM_PROFILE
    endif
    ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HIDD_PROFILE__
      BT_SUPPORT_PROFILE += BT_HIDD_PROFILE
    endif
    ifeq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
      COM_DEFS    +=  __BT_DIALER_SUPPORT__
      BT_SUPPORT_PROFILE += BT_DIALER_SUPPORT
    endif
    ifeq ($(strip $(BT_MAPC_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_MAPC_PROFILE__
      BT_SUPPORT_PROFILE += BT_MAPC_PROFILE
    endif
    ifeq ($(strip $(BT_PBAPC_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_PBAP_CLIENT__
      BT_SUPPORT_PROFILE += BT_PBAPC_PROFILE
    endif
    ifeq ($(strip $(BT_SPEAKER_SUPPORT)),TRUE)
      COM_DEFS    +=  __BT_SPEAKER_SUPPORT__
      ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
        ifdef BT_PRODUCT_LINE
          ifneq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
            COM_DEFS    +=  __BT_AVRCP_V13__
          endif
        endif
      endif
    endif
    ifeq ($(strip $(BT_DISABLE_SSP_SUPPORT)),TRUE)
      COM_DEFS    +=  __BT_DISABLE_SSP_SUPPORT__
    endif
  else #ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_HFG_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FTS_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FTC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_OPP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_DUN_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_A2DP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_AVRCP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(BT_SPP_SERVER)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_SERVER)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_CLIENT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FM_RADIO_VIA_SCO)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_HIDD_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SIM_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_DIALER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_DUN_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BT_SPP_SERVER)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER,BT_DUN_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif  
endif

ifeq ($(strip $(BT_FAX_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_FAX_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BT_SPP_SERVER)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER,BT_FAX_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif  
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(BLUETOOTH_VERSION)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_VERSION,BLUETOOTH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += BTMTK_ON_MAUI
  COM_DEFS += __ENABLE_SLEEP_MODE__
  COM_DEFS += __BT_USE_CUST_DATA__
endif

ifdef BLUETOOTH_VERSION
  ifneq ($(strip $(BLUETOOTH_VERSION)),NONE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BLUETOOTH_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_PRE21_SINGLE_LINK)
      COM_DEFS += __BT_VER_PRE21_SINGLE_LINK__
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_21)
      COM_DEFS += __BT_VER_21__
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_30)
      COM_DEFS += __BT_VER_30__
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_40)
      COM_DEFS += __BT_4_0_BLE__
    endif
  endif
endif

ifeq ($(strip $(BT_GATTS_PROFILE)),TRUE)
    ifneq ($(strip $(BLUETOOTH_VERSION)),BT_VER_40)
      $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_VERSION,BT_VER_40,BT_GATTS_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __BT_GATTS_PROFILE__
    BT_SUPPORT_PROFILE += BT_GATTS_PROFILE
endif

ifeq ($(strip $(BT_GATTC_PROFILE)),TRUE)
    ifneq ($(strip $(BLUETOOTH_VERSION)),BT_VER_40)
      $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_VERSION,BT_VER_40,BT_GATTC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS +=  __BT_GATTC_PROFILE__
    BT_SUPPORT_PROFILE += BT_GATTC_PROFILE
endif

ifdef BT_DIALER_SUPPORT
  ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    ifeq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
      ifneq ($(strip $(BCM_AT_SUPPORT)),TRUE)
        ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
            $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI/IOT_MMI,BT_DIALER_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
        COMPLIST  += btnotification_conn
      endif
    endif
  endif
endif

ifdef BT_MAPC_PROFILE
  ifeq ($(strip $(BT_MAPC_PROFILE)),TRUE)
    ifneq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_DIALER_SUPPORT,BT_MAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(BT_GOEP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_GOEP_PROFILE,BT_MAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif     
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_MAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif  
    ifeq ($(strip $(XML_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_MAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BT_PBAPC_PROFILE
  ifeq ($(strip $(BT_PBAPC_PROFILE)),TRUE)
    ifneq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_DIALER_SUPPORT,BT_PBAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(BT_GOEP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_GOEP_PROFILE,BT_PBAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_PBAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(XML_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_PBAPC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif  
  endif
endif

ifdef BT_SPEAKER_SUPPORT
  ifeq ($(strip $(BT_SPEAKER_SUPPORT)),TRUE)
    ifneq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_DIALER_SUPPORT,BT_SPEAKER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPEAKER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_A2DP_PROFILE,BT_SPEAKER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_AVRCP_PROFILE,BT_SPEAKER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BT_DISABLE_SSP_SUPPORT
  ifeq ($(strip $(BT_DISABLE_SSP_SUPPORT)),TRUE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_DISABLE_SSP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,BT_DISABLE_SSP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BT_PRODUCT_LINE
  ifeq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
    COM_DEFS     += __BT_BOX_SUPPORT__
    COM_DEFS     += __LED_SUPPORT__
    COM_DEFS     += __BT_JUST_WORK_SUPPORT__
    COM_DEFS     += __POPULATE_NO_IMAGE_DATA__
    COM_DEFS     += __POPULATE_NO_STRING_DATA__
  endif
  COM_DEFS  += __BT_PRODUCT_LINE_$(call Upper,$(strip $(BT_PRODUCT_LINE)))__
endif

ifdef BT_PRODUCT_LINE
  ifeq ($(strip $(BT_PRODUCT_LINE)), BT_DIALER_BTONLY)
    ifeq ($(strip $(BT_PBAP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_PRODUCT_LINE, BT_PBAP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS     += __MEGAPHONE_SUPPORT__
  endif
endif

ifdef BT_PRODUCT_LINE
  ifeq ($(strip $(BT_PRODUCT_LINE)), BT_DIALER_BTONLY)
    ifeq ($(strip $(BT_PBAP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_PRODUCT_LINE, BT_PBAP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef LINE_IN_SUPPORT
  ifeq ($(strip $(LINE_IN_SUPPORT)),TRUE)
    COM_DEFS     += __LINE_IN_SUPPORT__
 endif
endif

ifdef BT_NFC_TAG_SUPPORT
  ifeq ($(strip $(BT_NFC_TAG_SUPPORT)),TRUE)
    COM_DEFS     += __BT_NFC_TAG_SUPPORT__
 endif
endif

ifdef BTDIALER_CALL_RECORD
  ifeq ($(strip $(BTDIALER_CALL_RECORD)),TRUE)
    COM_DEFS     += __BTDIALER_CALL_RECORD__
  endif
endif

ifdef BT_MAX_LINK_NUM
  ifeq ($(strip $(BT_MAX_LINK_NUM)),1)
    COM_DEFS += BT_MAX_LINK_NUM=1
    COM_DEFS += __BT_MAX_LINK_NUM__=1
  else
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      COM_DEFS += BT_MAX_LINK_NUM=$(strip $(BT_MAX_LINK_NUM))
      COM_DEFS += __BT_MAX_LINK_NUM__=$(strip $(BT_MAX_LINK_NUM))
    else
      $(warning ERROR: BLUETOOTH_SUPPORT should not be NONE if BT_MAX_LINK_NUM is not set to 1)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BT_MAX_LE_LINK_NUM
  COM_DEFS += __BT_MAX_LE_LINK_NUM__=$(strip $(BT_MAX_LE_LINK_NUM))
endif

ifdef NORFLASH_NON_XIP_SUPPORT
  ifeq ($(strip $(NORFLASH_NON_XIP_SUPPORT)),TRUE)
    NORFLASH_NON_XIP_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(NORFLASH_NON_XIP_SUPPORT_PLATFORM)),$(PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support NORFLASH_NON_XIP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR:Please set NAND_FLASH_BOOTING as NONE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
      $(warning ERROR:Please set ZIMAGE_SUPPORT as TRUE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(ALICE_SUPPORT)),TRUE)
      $(warning ERROR:Please set ALICE_SUPPORT as FALSE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
      $(warning ERROR:Please set DCM_COMPRESSION_SUPPORT as FALSE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BOOT_ZIMAGE_SUPPORT)),TRUE)
      $(warning ERROR:Please set BOOT_ZIMAGE_SUPPORT as FALSE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
      $(warning ERROR:Please set MULTIPLE_BINARY_FILES as FALSE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      $(warning ERROR:Please set FOTA_ENABLE as NONE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
      $(warning ERROR:Please set CARD_DOWNLOAD as NONE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(warning ERROR:Please set SECURE_SUPPORT as FALSE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(warning ERROR:Please set SECURE_RO_ENABLE as FALSE when NORFLASH_NON_XIP_SUPPORT is $(strip $(NORFLASH_NON_XIP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE 
    endif
    COM_DEFS  +=  __NORFLASH_NON_XIP_SUPPORT__
    COM_DEFS  +=  __XIP_SHADOWING__
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    COMPLIST          += cmux
    COM_DEFS     += __CMUX_SUPPORT__
    COMMINCDIRS  += $(strip $(PS_FOLDER))\cmux\include
  endif
  endif
endif

ifdef CUST_KEYPAD_TONE_SUPPORT
  ifeq ($(strip $(CUST_KEYPAD_TONE_SUPPORT)),TRUE)
    COM_DEFS    +=  CUST_KEYPAD_TONE_SUPPORT
  endif
endif

HORIZONTAL_CAMERA_SUPPORT_SIZE = 128X128 128X160 176X220 240X320 240X400 320X480 360X640 480X800 240X240
ifdef HORIZONTAL_CAMERA
  ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(HORIZONTAL_CAMERA_SUPPORT_SIZE)),)
       $(warning ERROR: $(MAIN_LCD_SIZE) does not support HORIZONTAL_CAMERA. Please disable HORIZONTAL_CAMERA)
       DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += HORIZONTAL_CAMERA
    endif
  endif
endif

ifdef MED_PROFILE
  COM_DEFS    += $(strip $(MED_PROFILE))
  ifeq ($(strip $(MED_PROFILE)),MED_BASIC)
    COM_DEFS  += MED_LOW
  endif
endif

ifdef XML_SUPPORT
  ifeq ($(strip $(XML_SUPPORT)),TRUE)
    COM_DEFS   += __XML_SUPPORT__
    COMMINCDIRS   +=  xmlp\include
  endif
endif

ifdef IMPS_SUPPORT
  ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
     COM_DEFS    += __IMPS__ IMPS_WV13_ENHANCEMENT
  endif
endif

ifdef APP_SECONDARY_PDP_SUPPORT
  ifeq ($(strip $(APP_SECONDARY_PDP_SUPPORT)),TRUE)
     COM_DEFS    += __APP_SECONDARY_PDP_SUPPORT__
  endif
endif

# if APP_SECONDARY_PDP_SUPPORT is defined TRUE in compile option
#    but there is no enough internal PDP context, error and stop compile
# if APP_SECONDARY_PDP_SUPPORT is defined TRUE and there are enough internal PDP contexts
#    add a __TURN_ON_INTERNAL_SECONDARY_PDP__ option
#    add a __TURN_ON_GENERAL_SECONDARY_PDP__ option
ifdef APP_SECONDARY_PDP_SUPPORT
  ifeq ($(strip $(APP_SECONDARY_PDP_SUPPORT)),TRUE)
    ifeq ($(call lt,$(strip $(MAX_INT_PDP_CONTEXT)),2),T)
      $(warning ERROR: MAX_INT_PDP_CONTEXT is less than 2, it is impossible to define APP_SECONDARY_PDP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(GPRS_MAX_PDP_SUPPORT)),2),T)
      $(warning ERROR: GPRS_MAX_PDP_SUPPORT is less than 2, it is impossible to define APP_SECONDARY_PDP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    # here means MAX_INT_PDP_CONTEXT >= 2 and GPRS_MAX_PDP_SUPPORT >= 2 and APP_SECONDARY_PDP_SUPPORT == TRUE
    COM_DEFS          += __TURN_ON_INTERNAL_SECONDARY_PDP__
    COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__
  endif
endif

ifdef DMA_UART_VIRTUAL_FIFO
  VFIFO_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
  ifneq ($(filter $(strip $(PLATFORM)),$(VFIFO_NOT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) dose NOT support DMA_UART_VIRTUAL_FIFO.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      ifneq ($(strip $(PLATFORM)),MT6256)
      ifneq ($(strip $(PLATFORM)),MT6573)
      ifneq ($(strip $(PLATFORM)),MT6276)
        $(warning ERROR: DMA_UART_VIRTUAL_FIFO is a mandatory feature on PLATFORM $(strip $(PLATFORM)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      endif
      endif
    endif
  endif
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    COM_DEFS    += __DMA_UART_VIRTUAL_FIFO__
  endif
endif

ifdef DMA_UART_VIRTUAL_FIFO
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    ifeq ($(strip $(DMA_UART_VFIFO_TUNNEL_SUPPORT)),TRUE)
      ifneq ($(strip $(PLATFORM)),MT6235)
        $(warning ERROR: Please set DMA_UART_VFIFO_TUNNEL_SUPPORT = FALSE on $(strip $(PLATFORM)) platform.)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  __DMA_UART_VFIFO_SINGLE_TUNNEL__
    endif
  endif
endif


ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SDP__
     COMP_TRACE_DEFS  += inet_ps\sdp\include\sdp_trc.h
     COMMINCDIRS += inet_ps\sdp\include
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    COM_DEFS    +=  __WIFI_SUPPORT__
    COM_DEFS    +=  __WIFI_CHIP_VERIFY__
    COM_DEFS    += __WIFI_WIZARD_SUPPORT__
  endif
endif

ifndef PHB_SIM_ENTRY
  PHB_SIM_ENTRY = 250
endif

ifdef PHB_SIM_ENTRY
  COM_DEFS    += MAX_PHB_SIM_ENTRY=$(strip $(PHB_SIM_ENTRY))
endif

ifndef PHB_PHONE_ENTRY
  PHB_PHONE_ENTRY = 200
endif

ifdef PHB_PHONE_ENTRY
  COM_DEFS    += MAX_PHB_PHONE_ENTRY=$(strip $(PHB_PHONE_ENTRY))
endif

ifndef PHB_LN_ENTRY
  PHB_LN_ENTRY = 20
endif

ifdef PHB_LN_ENTRY
  COM_DEFS    += MAX_PHB_LN_ENTRY=$(strip $(PHB_LN_ENTRY))
endif

ifdef CLOG_SIM_SYNC_SUPPORT
  ifneq ($(strip $(CLOG_SIM_SYNC_SUPPORT)),FALSE)
    ifdef SIM_HOT_SWAP
      ifneq ($(strip $(SIM_HOT_SWAP)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,SIM_HOT_SWAP,NONE,CLOG_SIM_SYNC_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef SIM_RECOVERY_ENHANCEMENT
      ifneq ($(strip $(SIM_RECOVERY_ENHANCEMENT)),FALSE)
        $(call DEP_ERR_SETA_OR_OFFB,SIM_RECOVERY_ENHANCEMENT,FALSE,CLOG_SIM_SYNC_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(GEMINI)),3)
      $(warning ERROR: CLOG_SIM_SYNC_SUPPORT = $(strip $(CLOG_SIM_SYNC_SUPPORT)) does not support GEMINI = $(strip $(GEMINI)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(GEMINI)),4)
      $(warning ERROR: CLOG_SIM_SYNC_SUPPORT = $(strip $(CLOG_SIM_SYNC_SUPPORT)) does not support GEMINI = $(strip $(GEMINI)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      COM_DEFS += __PHB_ACCESS_SIM_LN__
    endif
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
      COM_DEFS += __PHB_ACCESS_SIM_LN__
    endif
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      COM_DEFS += __PHB_ACCESS_SIM_LN__
    endif
  endif
endif

ifndef PHONE_TYPE
  PHONE_TYPE = BAR
endif

ifdef PHONE_TYPE
  COM_DEFS    += __PHONE_$(strip $(PHONE_TYPE))__
  ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
    COM_DEFS  +=  CLAM_SUPPORT
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS    +=  LOW_COST_SUPPORT
    COM_DEFS    +=  __SAT_DISABLE_ICON_SUPPORT__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),ULC)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__ __LOW_COST_SUPPORT_ULC__
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COM_DEFS    +=  __MED_VIDEO_ULC__ __MED_CAMERA_ULC__ __ULC_VGA_PRETEND_CIF__
    endif
  endif
endif

ifndef MAX_MIDI_FILE_SIZE
  MAX_MIDI_FILE_SIZE = 2097152
endif

ifdef LARGE_MIDI_FILE_SUPPORT
  ifeq ($(strip $(LARGE_MIDI_FILE_SUPPORT)),TRUE)
    ifndef LOW_COST_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,LOW_COST_SUPPORT,LARGE_MIDI_FILE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,LOW_COST_SUPPORT,LARGE_MIDI_FILE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
        ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
          $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI/COSMOS_MMI/IOT_MMI,LARGE_MIDI_FILE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifdef DRM_SUPPORT
      ifneq ($(strip $(DRM_SUPPORT)),NONE)
        ifneq ($(filter MT6223%,$(PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) with DRM_SUPPORT does not support LARGE_MIDI_FILE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    COM_DEFS += MIDFILE_PLAY_SUPPORT
    COM_DEFS += MAX_MIDI_FILE_SIZE=$(strip $(MAX_MIDI_FILE_SIZE))
  endif
endif

ifdef EMS_SUPPORT
  ifeq ($(strip $(EMS_SUPPORT)),EMS_50)
    COM_DEFS    +=  __EMS_REL5__
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_40)
    # do nothing
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_SLIM)
    COM_DEFS    +=  __SLIM_EMS__
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_ULC_SLIM)
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
        ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
          $(warning ERROR: please set EMS_SUPPORT as EMS_NONE or close COMPOSER for UNIFIED_MESSAGE_ADVANCE_FEATURE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
      ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
        ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
          $(warning ERROR: please set EMS_SUPPORT as EMS_NONE or close COMPOSER for UNIFIED_MESSAGE_ADVANCE_FEATURE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    COM_DEFS    +=  __SLIM_EMS__ __ULC_SLIM_EMS__
  endif
endif

MULTI_LNA_MODE_CALIBRATION_SUPPORT_PLATFORM = MT6276 MT6573 MT6575
ifneq ($(filter $(MULTI_LNA_MODE_CALIBRATION_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __MULTI_LNA_MODE_CALIBRATION_SUPPORT__
endif

ifeq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
  COM_DEFS    += __2G_RF_CUSTOM_TOOL_SUPPORT__
  ifeq ($(strip $(PLATFORM)),MT6268)
    $(warning ERROR: 2G_RF_CUSTOM_TOOL_SUPPORT can NOT be TRUE when PLATFORM = MT6268)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FDD_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
  COM_DEFS    += __FDD_RF_CUSTOM_TOOL_SUPPORT__
  ifeq ($(strip $(PLATFORM)),MT6268)
    $(warning ERROR: FDD_RF_CUSTOM_TOOL_SUPPORT can NOT be TRUE when PLATFORM = MT6268)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,2G_RF_CUSTOM_TOOL_SUPPORT,FDD_RF_CUSTOM_TOOL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  COM_DEFS    +=   __USIM_SUPPORT__ __EF_NETPAR_SUPPORT__
  COM_DEFS    +=   __PHB_USIM_SUPPORT__

endif

ifndef MAIN_LCD_SIZE
  MAIN_LCD_SIZE = 0X0
endif

ifdef MAIN_LCD_SIZE
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),120X160)
    # spacial case for MTKLCM_COLOR in MT6208 EVB
    MAIN_LCD_SIZE := 128X160
  endif

  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
    ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(warning ERROR: MAIN_LCD_SIZE 128X128 does not support TOUCH_PANEL)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS    += __MMI_MAINLCD_$(call Upper,$(strip $(MAIN_LCD_SIZE)))__
endif

ifndef SUB_LCD_SIZE
  SUB_LCD_SIZE = NONE
endif

ifdef SUB_LCD_SIZE
  COM_DEFS += __MMI_SUBLCD_$(call Upper,$(strip $(SUB_LCD_SIZE)))__
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COM_DEFS    +=  __DT_SUPPORT__
     COMPLIST    +=  dt
  endif
endif

ifneq ($(strip $(J2ME_SUPPORT)),NONE)
  ifneq ($(strip $(JTONE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,JTONE_SUPPORT,J2ME_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

#ifdef BT_HFG_PROFILE
#  ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
#    COM_DEFS    +=  __BT_HFG_PROFILE__
#  else
#    COM_DEFS    += EXCLUDE_HFG_MODULE
#  endif
#endif

ifdef LCM_ROTATE_SUPPORT
  ifeq ($(strip $(LCM_ROTATE_SUPPORT)),TRUE)
    COM_DEFS += LCM_ROTATE_SUPPORT
  endif
endif

ifdef EXIF_SUPPORT
  ifeq ($(strip $(EXIF_SUPPORT)),TRUE)
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,EXIF_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
      COM_DEFS += EXIF_SUPPORT
  endif
endif

ifdef USB_IN_NORMAL_MODE_SUPPORT
  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
    ifeq ($(strip $(USB_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_IN_NORMAL_MODE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __USB_IN_NORMAL_MODE__
      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
        COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
      endif
    endif
  endif
endif

ifeq ($(filter MT6205B MT6208 MT6218B MT6217,$(strip $(PLATFORM))),)
  COM_DEFS +=  __USIM_DRV__
endif

ifneq ($(filter __DISABLE_SMS_CONTROLLED_BY_SIM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __SAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: Please define __SAT__ or do not define __DISABLE_SMS_CONTROLLED_BY_SIM__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef RC5_SUPPORT
  ifeq ($(strip $(RC5_SUPPORT)),TRUE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(findstring SEC,$(strip $(OBIGO_FEATURE))),SEC)
        COM_DEFS    += RC5_SUPPORT
      endif
    else
      ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM_SECURITY)
        COM_DEFS    += RC5_SUPPORT
      endif
      ifeq ($(strip $(WAP_MMS_FEATURES)),FULL)
        COM_DEFS    += RC5_SUPPORT
      endif     
    endif
  endif
endif

ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
      COM_DEFS +=  $(strip $(GAME_ENGINE))
  endif
endif

ifdef UNIFIED_MESSAGE_FOLDER
  ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
        ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
          $(warning ERROR: $(MMI_VERSION) does not support UNIFIED_MESSAGE_FOLDER)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifdef UNIFIED_MESSAGE_FOLDER
  ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifneq ($(strip $(OBIGO_FEATURE)),NONE)
        ifeq ($(findstring WAP,$(strip $(OBIGO_FEATURE))),)
          $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP,UNIFIED_MESSAGE_FOLDER)
          DEPENDENCY_CONFLICT = TRUE
        else
          ifeq ($(strip $(MMS_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_FOLDER)
            DEPENDENCY_CONFLICT = TRUE
          else
            COM_DEFS    +=  __UM_FOLDER__
          endif
        endif
      else
        $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP,UNIFIED_MESSAGE_FOLDER)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      ifeq ($(strip $(MMS_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_FOLDER)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS    +=  __UM_FOLDER__
      endif
    endif
  endif
endif

ifdef BROWSER_SUPPORT
  ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifdef OBIGO_FEATURE
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,BROWSER_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,BROWSER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
    ifdef WAP_MMS_FEATURES
      ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,WAP_MMS_FEATURES,NONE,BROWSER_SUPPORT,OBIGO_Q03C)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifneq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
        $(call DEP_ERR_SETA_OR_SETB,OBIGO_FEATURE,WAP2_SEC,BROWSER_SUPPORT,non OPERA_V10)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,BROWSER_SUPPORT,non OPERA_V10,SOCKET_SSL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_TURBO)
    ifdef WAP_MMS_FEATURES
      ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,WAP_MMS_FEATURES,NONE,BROWSER_SUPPORT,OBIGO_Q03C)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifneq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
        $(call DEP_ERR_SETA_OR_SETB,OBIGO_FEATURE,WAP2_SEC,BROWSER_SUPPORT,non OPERA_TURBO)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,BROWSER_SUPPORT,non OPERA_TURBO,SOCKET_SSL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,OPTR_SPEC,NONE,BROWSER_SUPPORT,non OPERA_TURBO)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    ifdef WAP_MMS_FEATURES
      ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,WAP_MMS_FEATURES,NONE,BROWSER_SUPPORT,OBIGO_Q03C)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(filter $(strip $(BROWSER_SUPPORT)) ,$(BROWSER_SUPPORT_Q03C_TYPES)),)
    COM_DEFS    +=   OBIGO_Q03C
    COM_DEFS    +=   OBIGO_Q03C_BROWSER
    ifdef WAP_MMS_FEATURES
      ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
        ifneq ($(strip $(WAP_MMS_FEATURES)),FULL)
          COM_DEFS    +=   OBIGO_Q03C_SLIM
        endif
      else
        ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q03C_SLIM)
          COM_DEFS    +=   OBIGO_Q03C_SLIM
        endif  
      endif
    endif
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    COM_DEFS    +=  OBIGO_Q05A
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
    COM_DEFS    +=  OBIGO_Q03C
    COM_DEFS    +=  OPERA_BROWSER
    COM_DEFS    +=  OPERA_V10_BROWSER
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_TURBO)
    COM_DEFS    +=  OBIGO_Q03C
    COM_DEFS    +=  OPERA_BROWSER
    COM_DEFS    +=  OPERA_V11_BROWSER
  endif
  ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
    COM_DEFS      +=  BROWSER_SUPPORT
  endif
endif
ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
  ifneq ($(findstring MMS,$(strip $(OBIGO_FEATURE))),)
    $(warning ERROR: $(strip $(OBIGO_FEATURE)) is not a valid option of OBIGO_FEATURE! Please modify it and set MMS_SUPPORT properly.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef MMI_VERSION
  ifeq ($(strip $(MMI_VERSION)), EMPTY_MMI)
    ifneq ($(strip $(OBIGO_FEATURE)), NONE)
      $(call DEP_ERR_SETA_OR_SETB, MMI_VERSION, PLUTO_MMI/COSMOS_MMI/IOT_MMI, OBIGO_FEATURE, NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
    ifdef MMS_SUPPORT
      ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
        ifneq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE)
          DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS    +=  __UNIFIED_COMPOSER_SUPPORT__
      endif
      ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
        ifeq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
          $(call DEP_ERR_ONA_OR_OFFB,COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE,MMS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif      
    endif
  endif
else
  ifdef MMS_SUPPORT
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifneq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_FOLDER,MMS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(findstring COMPOSER,$(UNIFIED_MESSAGE_ADVANCE_FEATURE)),)
        ifdef WAP_MMS_FEATURES
          ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)
            ifeq ($(strip $(WAP_MMS_FEATURES)),FULL)
              COM_DEFS    +=  __MMS_STANDALONE_COMPOSER_SUPPORT__
            endif
          else
            ifneq ($(strip $(MMS_FEATURES)),LOW_TIER_SLIM)
              COM_DEFS    +=  __MMS_STANDALONE_COMPOSER_SUPPORT__
            endif
          endif
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
  ifeq ($(strip $(OBIGO_FEATURE)),NONE)
    COM_DEFS    += WAP_NOT_PRESENT
    COM_DEFS    += WPS_NOT_PRESENT
  else
    ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
      COM_DEFS    += WAP_NOT_PRESENT
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT, $(strip $(call Upper,$(PROJECT)))),)
  COM_DEFS    += __MANUAL_MODE_NW_SEL__  __NORMAL_NW_SEARCH__
endif

ifdef CUST_PARA_SUPPORT
  ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,CUST_PARA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __CUST_PARA_SUPPORT__
  endif
endif

ifdef OTP_SUPPORT
  ifeq ($(strip $(OTP_SUPPORT)),TRUE)
    COM_DEFS    += __SECURITY_OTP__
  endif
endif

SV5_PLATFORM = MT6276 MT6256 MT6251 MT6573 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifdef SECURE_RO_ENABLE
  ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
   ifeq ($(filter $(strip $(PLATFORM)),$(strip $(SV5_PLATFORM))),)
    ifeq ($(strip $(SECURE_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,SECURE_RO_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    endif
   endif
   COM_DEFS    += __SECURE_RO_ENABLE__
  endif
endif

ifneq ($(strip $(PLATFORM)),MT6573)
  ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
    COM_DEFS += __SV5_ENABLED__
  endif
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
    ifeq ($(strip $(COMPILER)),RVCT)
      ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
        COMPOBJS         += sss\lib\sss_rvct_sv5.lib
        CUS_REL_OBJ_LIST += sss\lib\sss_rvct_sv5.lib
      else
        COMPOBJS         += sss\lib\sss_rvct_sv3.lib
        CUS_REL_OBJ_LIST += sss\lib\sss_rvct_sv3.lib
      endif
    else
      COMPOBJS         += sss\lib\sss.lib
      CUS_REL_OBJ_LIST += sss\lib\sss.lib
    endif
    CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
  endif
endif

ifdef DOWNLOADABLE_THEME
  ifeq ($(strip $(DOWNLOADABLE_THEME)),TRUE)
    ifdef XML_SUPPORT
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,DOWNLOADABLE_THEME)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,DOWNLOADABLE_THEME)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __DOWNLOADABLE_THEME__
  endif
endif

ifndef DLT_ALWAYS_LOAD_BUFFER_SIZE
  DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
endif

ifdef DLT_ALWAYS_LOAD_BUFFER_SIZE
  COM_DEFS    += __DLT_ALWAYS_LOAD_BUFFER_SIZE__=$(strip $(DLT_ALWAYS_LOAD_BUFFER_SIZE))
endif

ifndef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
  DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
endif

ifdef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
  COM_DEFS    += __DLT_LOAD_ON_DEMAND_BUFFER_SIZE__=$(strip $(DLT_LOAD_ON_DEMAND_BUFFER_SIZE))
endif

TEARING_REDUCTION_FB_PLATFORM = MT6227 MT6227D MT6226 MT6226M MT6226D 
ifneq ($(filter $(strip $(PLATFORM)),$(TEARING_REDUCTION_FB_PLATFORM)),)
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X240)
    COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
  endif
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320)
    COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
  endif
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X240)
    COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
  endif
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),400X240)
    COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
  endif
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),400X240)
    COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
  endif
endif

ifdef PGDL_SUPPORT
  ifeq ($(strip $(PGDL_SUPPORT)),TRUE)
    PGDL_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219 MT6223% MT6225 MT6226% MT6227% MT6228
    ifneq ($(filter $(strip $(PGDL_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support PGDL_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,PGDL_SUPPORT)      
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(HTTP_INTERFACE_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,PGDL_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += PGDL_SUPPORT
    ifeq ($(strip $(PGDL_SUPPORT_YOUTUBE)),TRUE)
      ifeq ($(strip $(GOOGLE_SEARCH_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,GOOGLE_SEARCH_SUPPORT,PGDL_SUPPORT_YOUTUBE)      
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += PGDL_SUPPORT_YOUTUBE
    endif
  endif
endif

ifeq ($(strip $(PGDL_SUPPORT_YOUTUBE)),TRUE)
  ifneq ($(strip $(PGDL_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_SETB,PGDL_SUPPORT,TRUE,PGDL_SUPPORT_YOUTUBE,FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non $(MMI_VERSION),TOUCH_PANEL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(BT_FAX_PROFILE)),TRUE)
  ifdef BT_SPP_CLIENT
    ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
      VIRTUAL_PORTS_NUM       = 5      # with FAX & SPP_CLIENT
    endif
    ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
      VIRTUAL_PORTS_NUM       = 4      # with FAX, without SPP_CLIENT
    endif       
  endif
  ifndef BT_SPP_CLIENT
    VIRTUAL_PORTS_NUM         = 4      # with FAX, without SPP_CLIENT
  endif
  BT_SUPPORT_PROFILE += BT_FAX_PROFILE
else
  ifdef BT_SPP_CLIENT
    ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
      VIRTUAL_PORTS_NUM       = 4      # without FAX, with SPP_CLIENT
    endif
    ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
      VIRTUAL_PORTS_NUM       = 3      # without FAX & SPP_CLIENT
    endif
  endif
  ifndef BT_SPP_CLIENT
    VIRTUAL_PORTS_NUM         = 3      # without FAX & SPP_CLIENT
  endif
endif

ifdef VIRTUAL_PORTS_NUM
  COM_DEFS    += VIRTUAL_PORTS_NUM=$(strip $(VIRTUAL_PORTS_NUM))
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),INSIGNIA_DM)
    COM_DEFS    += SYNCML_DM_SUPPORT
    COM_DEFS    += OMADM
    COMPLIST    += insignia_dm
    COMPLIST    += insignia_dmsdk
  endif
endif

ifeq ($(strip $(SPATIAL_DITHERING)),TRUE)
  COM_DEFS += __SPATIAL_DITHERING__
endif

ifeq ($(strip $(UNIFIED_MESSAGE_SIMBOX_SUPPORT)),TRUE)
  COM_DEFS += __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
endif

ifneq ($(strip $(OPTR_CODE)),OP12)
  COM_DEFS    += __IP_NUMBER__
endif

ifdef ISO_PRIORITY_MODE_SUPPORT
  ifeq ($(strip $(ISO_PRIORITY_MODE_SUPPORT)),TRUE)
    COM_DEFS    += ISO_PRIORITY_SUPPORT
  endif
endif

ifdef KEYPAD_TYPE
  ifeq ($(strip $(KEYPAD_TYPE)),NORMAL_KEYPAD)
    COM_DEFS    += NORMAL_KEYPAD
  endif       
  ifeq ($(strip $(KEYPAD_TYPE)),REDUCED_KEYPAD)
    COM_DEFS    += REDUCED_KEYPAD
  endif          
  ifeq ($(strip $(KEYPAD_TYPE)),QWERTY_KEYPAD)
    COM_DEFS    += QWERTY_KEYPAD
  endif
  ifeq ($(strip $(KEYPAD_TYPE)),EXTEND_QWERTY_KEYPAD)
    COM_DEFS    += QWERTY_KEYPAD
    COM_DEFS    += __EXTEND_QWERTY_KEYPAD__
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifneq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
      ifneq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__THREE_KEY_DETECTION_SWITCHABLE__)
        COM_DEFS += __THREE_KEY_DETECTION_SWITCHABLE__
      endif
    endif
  endif
endif

ifdef KEYPAD_TYPE
  ifeq ($(strip $(KEYPAD_TYPE)), REDUCED_KEYPAD)
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,KEYPAD_TYPE,non $(KEYPAD_TYPE),TOUCH_PANEL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), QWERTY_KEYPAD)
    ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
      COM_DEFS += __TWO_KEY_DETECTION_SWITCHABLE__
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), EXTEND_QWERTY_KEYPAD)
    ifeq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
    ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
      COM_DEFS += __TWO_KEY_DETECTION_SWITCHABLE__
      endif
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), EXTEND_QWERTY_KEYPAD)
    ifneq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,KEYPAD_TYPE,non EXTEND_QWERTY_KEYPAD,DRV_CUSTOM_TOOL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifneq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
      ifneq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__THREE_KEY_DETECTION_SWITCHABLE__)
        ifneq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
           COM_DEFS += __TWO_KEY_DETECTION_SWITCHABLE__
        endif
      endif
    endif
  endif
endif

ARM9_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A MT6921 MT6255 MT6922
ARM11_PLATFORM = MT6256 MT6276 MT6573
ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6238)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6236)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6236B)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6921)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6270A)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6253E)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6253L)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6256)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
    COM_DEFS    += __ARM_FPUV2__
  endif
  ifeq ($(strip $(PLATFORM)),MT6276)
    COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__ __ARM_DMA__
  endif
  ifeq ($(strip $(PLATFORM)),MT6573)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
  endif
  ifeq ($(strip $(PLATFORM)),MT6575)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
  endif
  ifeq ($(strip $(PLATFORM)),MT6252H)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6252)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6250)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6260)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6261)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT2501)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT2502)
    COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6255)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6922)
    COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
endif

ifdef TCPIP_SUPPORT
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(warning ERROR: $(MMI_VERSION) does not support TCPIP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    TCPIP_SUPPORT_ON_CONDITION = FALSE
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif  
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif
    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT_ON_CONDITION)),FALSE)
      $(warning ERROR: Please add __PS_SERVICE__ to CUSTOM_OPTION or turn on CSD_SUPPORT or turn on WIFI_SUPPORT when TCPIP_SUPPORT is turned on!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
ifdef TCPIP_SUPPORT
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    ifdef LOW_COST_SUPPORT
      ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
        COM_DEFS += __ABM_CBM_SLIM__ __SOC_SLIM__
      endif
    endif
  endif
endif

ifdef RRLP_VER_SUPPORT
  ifneq ($(strip $(RRLP_VER_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), NONE)
      $(call DEP_ERR_ONA_OR_OFFB,AGPS_SUPPORT,RRLP_VER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef AGPS_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,AGPS_SUPPORT,RRLP_VER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R99)
    COM_DEFS += __RRLP_REL_99__
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R5)
    COM_DEFS += __RRLP_REL_5__
  endif          
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,WIFI_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef WIFI_AUTHENTICATION_LEVEL
      ifneq ($(strip $(WIFI_AUTHENTICATION_LEVEL)), WIFI_AUTHENTICATION_PSK_ONLY)
        ifeq ($(strip $(SSL_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,WIFI_AUTHENTICATION_LEVEL)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    else
      ifeq ($(strip $(SSL_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,WIFI_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif
ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifdef WIFI_AUTHENTICATION_LEVEL
      ifeq ($(strip $(WIFI_AUTHENTICATION_LEVEL)),WIFI_AUTHENTICATION_PSK_ONLY)
        COM_DEFS += WIFI_AUTH_PSK_ONLY
        COM_DEFS += __WIFI_SLIM__
        ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
          COMPLIST += eap
        endif
      endif
      ifeq ($(strip $(WIFI_AUTHENTICATION_LEVEL)),WIFI_AUTHENTICATION_FULL_EAP)
        COM_DEFS += WPA_WPA2_ENTERPRISE EAP_MSCHAPv2 EAP_TLS EAP_GTC EAP_SIM EAP_AKA EAP_TTLS EAP_PEAP
        COM_DEFS += WIFI_AUTH_FULL_EAP
        ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
          COMPLIST += eap
        endif
      endif 
    else
      COM_DEFS += WPA_WPA2_ENTERPRISE EAP_MSCHAPv2 EAP_TLS EAP_GTC EAP_SIM EAP_AKA EAP_TTLS EAP_PEAP
      COM_DEFS += WIFI_AUTH_FULL_EAP
      ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
        COMPLIST += eap
      endif
    endif
  endif
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COM_DEFS            += __CERTMAN_SUPPORT__
    COMPLIST            += certman sec_store
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)), TRUE)
    COM_DEFS            += __SSL_SUPPORT__
    COMPLIST            += tls
  endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
    COMPLIST         += ossl_ssl ossl_ssladp
    COM_DEFS         += __OPENSSL__
  endif
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
    COMPLIST         += ossl_ssl ossl_ssladp
    COM_DEFS         += __OPENSSL__
    COM_DEFS         += __OPENSSL_CHE_PORTING__
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
    ifndef SSL_SUPPORT
     $(warning ERROR: Please define SSL_SUPPORT!)
     DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SOCKET_SSL_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef WIFI_SUPPORT
   ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      COM_DEFS += __WIFI_CHIP_DYM_POWERON__
   endif
endif

ifdef PURE_AUDIO_SUPPORT
  ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
    ifeq ($(strip $(AAC_DECODE)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,PURE_AUDIO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += PURE_AUDIO_SUPPORT
  endif
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
    COM_DEFS    +=  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
  COM_DEFS    +=  __GSM_RAT__ 
endif


ifdef WBXML_SUPPORT
  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
    COM_DEFS    += __WBXML_SUPPORT__
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      COMPLIST    += xmlp
    endif
  endif
endif 

# Check if BT is connected to UART2 or NOT
# When BT is connected to UART2, we will only allow one uart be configured in engineer mode
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)              # BT is supported
    ifdef BT_CONNECT_TO_UART2
      ifeq ($(strip $(BT_CONNECT_TO_UART2)),TRUE)         # BT module is connected to UART2
        COM_DEFS += __BT_USE_UART2__ __ONLY_ONE_UART__
      endif
    endif
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6238)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6239)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6235)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6235B)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6236)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6921)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6236B)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6253T)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6253)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),TK6516)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6516)
  COM_DEFS += __NFI_VERSION3__
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6268)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6270A)
  COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6256)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6276)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6573)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6255)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif
ifeq ($(strip $(PLATFORM)),MT6922)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6260)
  COM_DEFS += __SNAND_VERSION2__ __NAND_FDM_50__
endif
ifeq ($(strip $(PLATFORM)),MT6261)
  COM_DEFS += __SNAND_VERSION2__ __NAND_FDM_50__
endif
ifeq ($(strip $(PLATFORM)),MT2501)
  COM_DEFS += __SNAND_VERSION2__ __NAND_FDM_50__
endif
ifeq ($(strip $(PLATFORM)),MT2502)
  COM_DEFS += __SNAND_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COM_DEFS += __CPI_SUPPORT__ __SS_OPERATION_SUPPORT__
  COM_DEFS += __MED_IN_ASM__
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  COM_DEFS += __CPI_SUPPORT__ __SS_OPERATION_SUPPORT__
  COM_DEFS += __MED_IN_ASM__
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
   COM_DEFS += __CPI_SUPPORT__ __SS_OPERATION_SUPPORT__
   COM_DEFS += __MED_IN_ASM__
endif

ifdef NOR_SUPPORT_RAW_DISK
  ifeq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    COM_DEFS += __NOR_SUPPORT_RAW_DISK__       
    ifdef SYSDRV_BACKUP_DISK_SUPPORT
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_RAW__
      endif
    endif          
    ifdef LGE_SECURITY
      ifeq ($(strip $(LGE_SECURITY)),TRUE)
        COM_DEFS += __CUSTOMER_TC01_DISK__
      endif
    endif
  endif
endif

ifdef NANDFDM_MULTI_INSTANCE
  ifeq ($(strip $(NANDFDM_MULTI_INSTANCE)),TRUE)
    ifneq ($(strip $(CUST_CODE)),TC01)
      $(warning ERROR: Only CUST_CODE = TC01 supports NANDFDM_MULTI_INSTANCE=TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,NAND_FLASH_BOOTING,NANDFDM_MULTI_INSTANCE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __NANDFDM_MULTI_INSTANCE__
    ifdef  NAND_SUPPORT_RAW_DISK
      ifeq ($(strip $(NAND_SUPPORT_RAW_DISK)),TRUE)
        COM_DEFS += __NAND_SUPPORT_RAW_DISK__
        ifdef CUST_CODE
          ifeq ($(strip $(CUST_CODE)),TC01)
            COM_DEFS += __CUSTOMER_TC01_DISK__
          endif
        endif
      endif
    endif
    ifdef SYSDRV_BACKUP_DISK_SUPPORT
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_FAT__
      endif
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),TRUE)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_FAT__
      endif
    endif
    ifdef  NANDFDM_TOTAL_BBM
      ifeq ($(strip $(NANDFDM_TOTAL_BBM)),TRUE)
        COM_DEFS += __NANDFDM_TOTAL_BBM__       
      endif
    endif       
  endif
endif

SAIC_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 
ifeq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __SAIC__
endif

ifneq ($(filter __SAIC__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __SAIC__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

REPEATED_ACCH_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 MT6235 MT6235B MT6238 MT6239 MT6268T MT6268H
ifeq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __REPEATED_ACCH__
endif
ifneq ($(filter __REPEATED_ACCH__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __REPEATED_ACCH__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

VAMOS_NOT_SUPPORT_FLATFORM = MT6205 MT6205A MT6205B MT6208 MT6217 MT6218 MT6218A MT6218B MT6219 MT6236B MT6225 MT6226 MT6226D MT6226DS MT6226M MT6227 MT6227D MT6227DS MT6228 MT6229 MT6230 MT6268T MT6268H MT6223 MT6223P MT6235 MT6238 MT6235B MT6239 TK6516 MT6268A MT6268 MT6516 MT6253T MT6253 MT6252H MT6252 MT6253E MT6253L MT6236 MT6270A MT6276 MT6256 MT6255 MT6251 MT6573 MT6575 MT6921 MT6922
ifeq ($(strip $(VAMOS_SUPPORT)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support VAMOS_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __VAMOS_1__ __VAMOS_2__
endif

ifneq ($(filter __VAMOS_1__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __VAMOS_1__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __VAMOS_2__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __VAMOS_2__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(INTERNAL_ANTENNAL_SUPPORT)),TRUE)
  COM_DEFS    += INTERNAL_ANTENNAL_SUPPORT
endif

ifeq ($(strip $(TST_WRITE_TO_FILE)),TRUE)
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COM_DEFS    += __TST_WRITE_TO_FILE__
  endif
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifdef LOW_COST_SUPPORT
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      COM_DEFS += __GIS_INTERNAL__
    endif
  else
    COM_DEFS += __GIS_INTERNAL__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),AR1000)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non AR1000,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6616)
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6616)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6616,BLUETOOTH_SUPPORT=BTMTK_MT6616)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6616,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6626)
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6626)
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_26)
      ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6622_26)
        ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_22_26)
          $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6626,BLUETOOTH_SUPPORT as BTMTK_MT6626 or BTMTK_MT6612_26 or BTMTK_MT6622_26 or BTMTK_MT6612_22_26)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6626,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6626)
  ifneq ($(strip $(FM_RADIO_CHIP)),MT6626)
    $(warning ERROR: BLUETOOTH_SUPPORT and FM_RADIO_CHIP shall both indicate to MT6626 !)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6276FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6276FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6256FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6256FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6255FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6255FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6922FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6922FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6251FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6251FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
      COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6250FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6250FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
    COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6260FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6260FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
    COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6261FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6261FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
    COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT2501FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT2501FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
    COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT2502FM)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT2502FM,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  ifeq ($(strip $(FM_RADIO_RDS_SUPPORT)),TRUE)
    COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
  endif
endif

ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
    COMPLIST          += rfc2507
    COMP_TRACE_DEFS   += $(strip $(UAS_FOLDER))\l2\rfc2507\include\rfc2507_lib_trc.h
    COM_DEFS          += __RFC2507_SUPPORT__
  endif
endif

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(strip $(MODEM_CARD)),NONE)
      COM_DEFS += __USB_MODEM_CARD_SUPPORT__
      COM_DEFS += __USB_MASS_STORAGE_CDROM_ENABLE__
      ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
        ifneq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
          $(warning ERROR: please turn on USB_IN_NORMAL_MODE_SUPPORT , when USB_MASS_STORAGE_SUPPORT is set to TRUE .)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  ifneq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    $(call DEP_ERR_SETA_OR_OFFB,RSAT_SUPPORT,MODEM_WITH_RSAT,EMPTY_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  COM_DEFS    += __SIM_RESET_BY_SIM__
endif

ifdef AUD_RECORD
  ifneq ($(strip $(AUD_RECORD)),FALSE)
    COM_DEFS    += AUD_REC_ENABLE
  else
    ifdef DEDI_AMR_REC
      ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AUD_RECORD,DEDI_AMR_REC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef FM_RADIO_RECORD
      ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AUD_RECORD,FM_RADIO_RECORD)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
else
    COM_DEFS    += AUD_REC_ENABLE
endif

ifeq ($(strip $(CBM_CONNECTION_MANAGER_SUPPORT)),TRUE)
  ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI/COSMOS_MMI/IOT_MMI,CBM_CONNECTION_MANAGER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifndef TCPIP_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_CONNECTION_MANAGER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_CONNECTION_MANAGER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __CBM_CONNECTION_MANAGER__
  COM_DEFS    +=  __DIALUP_GPRS_COUNTER_SUPPORT__
endif

ifeq ($(strip $(BT_PBAP_PROFILE)),TRUE)  
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_PBAP_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __BT_PBAP_PROFILE__
  BT_SUPPORT_PROFILE += BT_PBAP_PROFILE
endif

ifneq ($(strip $(CHE_INPUT_FROM_FSAL)),FALSE)
  COM_DEFS    +=  __CHE_INPUT_FROM_FSAL__
endif

ifdef L1_GPS_REF_TIME_SUPPORT 
  ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
    COM_DEFS += __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__
  endif
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(GPS_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,GPS_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RRLP_VER_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,RRLP_VER_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef RRLP_VER_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,RRLP_VER_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
      ifeq ($(strip $(OMA_ULP_SUPPORT)), NONE)
          $(call DEP_ERR_ONA_OR_OFFB,OMA_ULP_SUPPORT,AGPS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
# mtk04096
#      ifeq ($(strip $(SSL_SUPPORT)), NONE)
#          $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,AGPS_SUPPORT)
#          DEPENDENCY_CONFLICT = TRUE
#      endif
#      ifeq ($(strip $(SOCKET_SSL_SUPPORT)), FALSE)
#          $(call DEP_ERR_ONA_OR_OFFB,SOCKET_SSL_SUPPORT,AGPS_SUPPORT)
#          DEPENDENCY_CONFLICT = TRUE
#      endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
      COM_DEFS += __AGPS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __NBR_CELL_INFO__
      COM_DEFS += __IOT_CUSTOMIZE__
      ifeq ($(strip $(XYSSL_SUPPORT)),TRUE)
        COM_DEFS += __SUPL_XYSSL__
      endif
      COMPLIST        += supl rrlp
      COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\supl\include\supl_trc.h
      COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\rrlp\include\rrlp_trc.h
      ifndef RRC_PAYLOAD_FOR_3G_UP_SUPPORT
        $(warning ERROR: Please define RRC_PAYLOAD_FOR_3G_UP_SUPPORT when AGPS_SUPPORT = $(strip $(AGPS_SUPPORT)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        $(warning ERROR: AGPS_SUPPORT=USER_PLANE can only be set when __PS_SERVICE__ is defined.)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
        ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMPLIST += ulcs
          COMP_TRACE_DEFS += ulcs\uagps_up\include\uagps_up_trc.h
          COMP_TRACE_DEFS += ulcs\common\include\uagps_trc.h
        endif
        ifeq ($(call Upper,$(strip $(PROJECT))),HSPA)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMPLIST += ulcs
          COMP_TRACE_DEFS += ulcs\uagps_up\include\uagps_up_trc.h
          COMP_TRACE_DEFS += ulcs\common\include\uagps_trc.h
        endif
      endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      COM_DEFS += __AGPS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__
      COMPLIST        += rrlp applib
      COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\rrlp\include\rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      ifdef AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT
        ifeq ($(strip $(AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT)), TRUE)
          COM_DEFS += __AGPS_UP_CP_CONFLICT_HANDLING__
        endif                
      endif
      ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS += ulcs\uagps_cp\include\uagps_cp_trc.h
        COMP_TRACE_DEFS += ulcs\common\include\uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT 
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif                
        endif
      endif
      ifeq ($(call Upper,$(strip $(PROJECT))),HSPA)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS += ulcs\uagps_cp\include\uagps_cp_trc.h
        COMP_TRACE_DEFS += ulcs\common\include\uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT 
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif                
        endif
      endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      COM_DEFS += __AGPS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __AGPS_CONTROL_PLANE__ __NBR_CELL_INFO__
      COMPLIST        += supl rrlp
      COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\supl\include\supl_trc.h
      COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\rrlp\include\rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      ifdef AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT
        ifeq ($(strip $(AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT)), TRUE)
          COM_DEFS += __AGPS_UP_CP_CONFLICT_HANDLING__
        endif                
      endif
      ifndef RRC_PAYLOAD_FOR_3G_UP_SUPPORT
        $(warning ERROR: Please define RRC_PAYLOAD_FOR_3G_UP_SUPPORT when AGPS_SUPPORT = $(strip $(AGPS_SUPPORT)))
        DEPENDENCY_CONFLICT = TRUE 
      endif
      ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        $(warning ERROR: AGPS_SUPPORT=BOTH can only be set when __PS_SERVICE__ is defined.)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS += ulcs\uagps_cp\include\uagps_cp_trc.h
        COMP_TRACE_DEFS += ulcs\common\include\uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT 
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
        endif
        ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
          ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
            COM_DEFS += __UAGPS_UP_SUPPORT__
            ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
            endif
            COMP_TRACE_DEFS += ulcs\uagps_up\include\uagps_up_trc.h
          endif
        endif
      endif
      ifeq ($(call Upper,$(strip $(PROJECT))),HSPA)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS += ulcs\uagps_cp\include\uagps_cp_trc.h
        COMP_TRACE_DEFS += ulcs\common\include\uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
        endif
        ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMP_TRACE_DEFS += ulcs\uagps_up\include\uagps_up_trc.h
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
  ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
    ifeq ($(strip $(OBIGO_FEATURE)), NONE)
#      $(warning ERROR: Please define OBIGO_FEATURE for WAP when AGPS user plan or SUPL is defined)
#      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
  ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
    ifeq ($(strip $(OBIGO_FEATURE)), NONE)
      $(warning ERROR: Please define OBIGO_FEATURE for WAP when AGPS user plan or SUPL is defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),TRUE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif  
  ifeq ($(strip $(NDIS_SUPPORT)),FALSE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),NDIS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __NDIS_SUPPORT__
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __NDIS_SUPPORT__ __UPS_SUPPORT__
    COMPLIST    += ups
    COMP_TRACE_DEFS  += $(strip $(PS_FOLDER))\ups\include\ups_trc.h
  endif
endif

ifneq ($(filter MT6223%,$(PLATFORM)),)
   COM_DEFS    += __DRV_SIM_CLK_DUTY_NOT_ENOUGH__
endif

ifeq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)),TRUE)
  COM_DEFS     += __UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__
endif

ifeq ($(strip $(MSG_SMS_EMAIL_SUPPORT)),TRUE)
  ifneq ($(strip $(OPTR_CODE)),OP11)
    $(warning ERROR: MSG_SMS_EMAIL_SUPPORT is not supported on NON-ORANGE project yet)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)),TRUE)   
    $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,MSG_SMS_EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
    $(call DEP_ERR_SETA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,non $(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE)),MSG_SMS_EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE 
  endif
  COM_DEFS  += __MSG_SMS_EMAIL_SUPPORT__
endif

ifdef CCBS_SUPPORT
  ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
     COM_DEFS    += __CCBS_SUPPORT__
  endif
endif

ifdef CNAP_SUPPORT
  ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
     COM_DEFS    += __CNAP_SUPPORT__
  endif
endif

ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
  ifdef L1_GPRS
    ifeq ($(strip $(L1_GPRS)),TRUE)
      $(warning ERROR: $(strip $(call Upper,$(PROJECT))) project does not support L1_GPRS. Please turn off L1_GPRS)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef L1_EPSK_TX
    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      $(warning ERROR: $(strip $(call Upper,$(PROJECT))) project does not support L1_EPSK_TX. Please turn off L1_EPSK_TX)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: $(strip $(call Upper,$(PROJECT))) project does not support __PS_SERVICE__ option )
      DEPENDENCY_CONFLICT = TRUE
   endif
endif

ifdef SWITCHABLE_FEATURE_2ND
  ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
    ifndef SWITCHABLE_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
  ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
    $(warning ERROR: Please turn off CCBS_SUPPORT in NEPTUNE project!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
    $(warning ERROR: Please turn off CNAP_SUPPORT in NEPTUNE project!)
    DEPENDENCY_CONFLICT = TRUE 
  endif
endif

ifdef MODEM_3G_LOGGING
  ifeq ($(strip $(MODEM_3G_LOGGING)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MODEM_3G_LOGGING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __MODEM_3G_LOGGING__
    COM_DEFS    += __USB_LOGGING__
  endif
endif

ifdef EXT_MODEM_SUPPORT
  ifeq ($(strip $(EXT_MODEM_SUPPORT)), TRUE)
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST          += ext_modem
    COMP_TRACE_DEFS   += $(strip $(PS_FOLDER))\ext_modem\include\ext_modem_trc.h
    COMMINCDIRS    += $(strip $(PS_FOLDER))\ext_modem\include
    COM_DEFS += __EXT_MODEM__
  endif
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,MMS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_PUSH_FEATURES,MMS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,MMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,MMS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_PUSH_FEATURES,MMS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,MMS_SUPPORT)
         DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += MMS_SUPPORT OBIGO_Q03C_MMS_V02
      COMP_TRACE_DEFS += vendor\mms\obigo_q03c\adaptation\integration\include\mms_trc.h
      COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
      COMPLIST    += obigo03cmmsadp obigo03cmmslib
      COMPLIST    += obigo03cfwlib obigo03cfwadp
    endif
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
      ifeq ($(filter MMS_SUPPORT,$(COM_DEFS)),)
        $(warning ERROR: MMS_SUPPORT must be added to COM_DEFS when SUPPORT_JSR_205 is TRUE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
        COM_DEFS    +=   __MMS_JSR_205_SUPPORT__
      endif
    endif
  endif
endif

ifdef J2ME_SUPPORT
  ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: J2ME_SUPPORT is JBLENDIA do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: J2ME_SUPPORT is JBLENDIA_MVM do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),JBED)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: J2ME_SUPPORT is JBED do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif 
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
      ifneq ($(filter __EMS_NON_STD_7BIT_CHAR__,$(COM_DEFS)),)
        $(warning ERROR: Please turn off BACKGROUND_SMS_SUPPORT when __EMS_NON_STD_7BIT_CHAR__ is defined! )
        DEPENDENCY_CONFLICT = TRUE
      endif
  endif
endif

ifdef LQT_SUPPORT
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
    COM_DEFS += LQT_SUPPORT
    COMPLIST += lqt
  endif
endif

ifeq ($(filter EMPTY_MMI,$ MMI_VERSION)),)
  ifeq ($(filter MT6223%,$(PLATFORM)),)
    ifneq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
      ifneq ($(strip $(LQT_SUPPORT)),TRUE)
        ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
          ifeq ($(filter MT65% MT6270A,$(strip $(PLATFORM))),)
            $(warning ERROR: LQT_SUPPORT is a mandatory feature. Please turn on LQT_SUPPORT.)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  else
    ifeq ($(strip $(LQT_SUPPORT)),TRUE)
      $(warning ERROR: MT6223 series did not support LQT_SUPPORT. Please turn off LQT_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE  
    endif
  endif
endif

LQT_NOT_SUPPORT_PLATFORM = MT6573 MT6270A
ifeq ($(strip $(LQT_SUPPORT)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(LQT_NOT_SUPPORT_PLATFORM)),)
    $(warning ERROR: $(strip $(PLATFORM)) series did not support LQT_SUPPORT. Please turn off LQT_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifndef SMS_PHONE_ENTRY
  $(warning ERROR: Please define SMS_PHONE_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifndef SMS_TOTAL_ENTRY
  $(warning ERROR: Please define SMS_TOTAL_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef SMS_PHONE_ENTRY
  COM_DEFS    += SMS_PHONE_ENTRY=$(strip $(SMS_PHONE_ENTRY))
endif

ifdef SMS_TOTAL_ENTRY
  COM_DEFS    += SMS_TOTAL_ENTRY=$(strip $(SMS_TOTAL_ENTRY))
endif

ifndef SMS_SIM_ENTRY
  $(warning ERROR: Please define SMS_SIM_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef SMS_SIM_ENTRY
  COM_DEFS    += SMS_SIM_ENTRY=$(strip $(SMS_SIM_ENTRY))
endif

ifdef SECURE_PORT_SUPPORT
  ifeq ($(strip $(SECURE_PORT_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_PORT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __SECURE_PORT_SUPPORT__
    endif
  endif
endif

ifdef BIP_SCWS_SUPPORT
  ifeq ($(strip $(BIP_SCWS_SUPPORT)),TRUE)
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_LOOP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter __SAT__,$(COM_DEFS)),)
        $(warning ERROR: __SAT__ must be defined when BIP_SCWS_SUPPORT is turned on.)
        DEPENDENCY_CONFLICT = TRUE
    endif   
    COM_DEFS    += __SATCE__
  endif
endif

ifdef IPSEC_SUPPORT
  ifneq ($(strip $(IPSEC_SUPPORT)),FALSE)
    ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,IPSEC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __IPSEC__
    COMP_TRACE_DEFS += security\ike\include\ike_trc.h
    COMMINCDIRS     +=  interface\security
    COMPLIST    += ipsec netkey ike
  endif
endif

ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    VECTORFONT_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6223 MT6223P MT6226 MT6227 MT6226M MT6226D
    ifneq ($(filter $(strip $(PLATFORM)),$(VECTORFONT_NOT_SUPPORT_PLATFORM)),)
       $(warning ERROR: Vector font (FONT_ENGINE) is not supported for PLATFORM $(strip $(PLATFORM)))
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),240X240 240X320 320X240 240X400 320X480 360X640 480X800),)
      $(warning ERROR: FONT_ENGINE only supports 240X240 240X320, 320X240, 240X400, 320X480 360X640 480X800 MAIN_LCD_SIZE)
      DEPENDENCY_CONFLICT = TRUE
    endif
     COM_DEFS += FONT_ENGINE_SUPPORT __MMI_VECTOR_FONT_SUPPORT__
     COM_DEFS += $(strip $(FONT_ENGINE))
  endif
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
        $(warning ERROR: For customer project, please set FONT_ENGINE = FONT_ENGINE_MONOTYPE_DEMO, not set FONT_ENGINE = FONT_ENGINE_MONOTYPE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
        $(warning ERROR: For customer project, please set FONT_ENGINE = FONT_ENGINE_FREETYPE_DEMO, not set FONT_ENGINE = FONT_ENGINE_FREETYPE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
        $(warning ERROR: For customer project, please set FONT_ENGINE = FONT_ENGINE_MONOTYPE_DEMO because there is no wtle demo resource)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef FONT_ENGINE
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
    COMPLIST    += vectorfont_monotype
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_v1\ads_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_v1\ads_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_v1\rvct_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_v1\rvct_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
    endif
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE_DEMO)
    COMPLIST    += vectorfont_monotype
    CUS_REL_BASE_COMP += vendor\vectorfont\monotype\adaptation \
                         vendor\vectorfont\monotype\demo
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS  += vendor\vectorfont\monotype\demo\engine_v1\ads_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\demo\engine_v1\ads_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS  += vendor\vectorfont\monotype\demo\engine_v1\rvct_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\demo\engine_v1\rvct_monotype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
    endif
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
    COMPLIST    += vectorfont_freetype  
    CUS_REL_BASE_COMP += vendor\vectorfont\freetype
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE_DEMO)
    COMPLIST    += vectorfont_freetype
    CUS_REL_BASE_COMP += vendor\vectorfont\freetype
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
    COMPLIST    += vectorfont_wtle
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\ads_itype_engine.a
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\ads_wtle_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\ads_itype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\ads_wtle_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\rvct_itype_engine.a
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\rvct_wtle_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\rvct_itype_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\rvct_wtle_engine.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
    endif
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_ETRUMP)
    COMPLIST    += vectorfont_etrump
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\vectorfont\etrump\lib\rvct31\arm79\libet_common.mtk_rvct31_arm79.a
      COMPOBJS    += vendor\vectorfont\etrump\lib\rvct31\arm79\libft2_mini_noac.mtk_rvct31_arm79.a
      COMPOBJS    += vendor\vectorfont\etrump\lib\rvct31\arm79\libottab.mtk_rvct31_arm79.a
      COMPOBJS    += vendor\vectorfont\etrump\lib\rvct31\arm79\libtextlayout.mtk_rvct31_arm79.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\etrump\lib\rvct31\arm79\libet_common.mtk_rvct31_arm79.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\etrump\lib\rvct31\arm79\libft2_mini_noac.mtk_rvct31_arm79.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\etrump\lib\rvct31\arm79\libottab.mtk_rvct31_arm79.a
      CUS_REL_OBJ_LIST  += vendor\vectorfont\etrump\lib\rvct31\arm79\libtextlayout.mtk_rvct31_arm79.a
    endif
  endif
endif

ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SQLITE3_SUPPORT,CMMB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(H264_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,H264_DECODE,CMMB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(DRA_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DRA_DECODE,CMMB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    COM_DEFS += __CMMB_SUPPORT__

  endif
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    COMPLIST += cmmb
    COM_DEFS += __$(strip $(CMMB_SUPPORT))__
    COMMINCDIRS += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\inc \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Demod\inc
  endif
  ifneq ($(filter SIANO_%,$(CMMB_SUPPORT)),)
    COMMINCDIRS += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\include \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\include_internal \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\include_internal\zlib \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\ADR \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\OSW\Header \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\SPIDriver\Header
    COMP_TRACE_DEFS += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\inc\siano_cmmb_trc.h
  endif
endif

ifdef SQLITE3_SUPPORT
  ifeq ($(strip $(SQLITE3_SUPPORT)),TRUE)
    COMPLIST    += applib_sqlite3
    COM_DEFS    += __SQLITE3_SUPPORT__
    COMP_TRACE_DEFS += applib\sqlite3\inc\sqlite3_trc.h
    CUS_REL_BASE_COMP += applib\sqlite3\inc
  endif
endif

ifdef MMI_BASE
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    COM_DEFS += __SAT_LOWCOST_UI_DISABLE__ __SAT_LOWCOST_NW_DISABLE__
  endif
endif

ifndef VENDOR
  VENDOR = NONE
endif

ifdef VENDOR
  ifneq ($(strip $(VENDOR)),NONE)
    COM_DEFS +=  DEVAPP_RESOURCE
  endif
  COM_DEFS += VENDOR_$(strip $(VENDOR))
endif

ifdef PRODUCTION_RELEASE
  ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
    COM_DEFS += L1A_DEVELOP_DEBUG
    ifeq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,DEMO_PROJECT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(EMPTY_RESOURCE)),FALSE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_OFFB,PRODUCTION_RELEASE,EMPTY_RESOURCE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        ifeq ($(filter REL_CR_OBJ_JAL_SRC% REL_CR_MMI_VOGINS% REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,MTK_SUBSIDIARY)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,DEMO_PROJECT,PRODUCTION_RELEASE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __SMS_DEPERSONALIZATION__,$(COM_DEFS)),)
  ifeq ($(filter __MOD_SMU__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMU__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MOD_SMS__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMS__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    COM_DEFS += __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__
  endif
endif

ifneq ($(filter NONE GSM,$(call Upper,$(PROJECT))),)
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    $(warning ERROR: PLEASE turn off GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO in $(PROJECT) project)
    DEPENDENCY_CONFLICT = TRUE    
  endif
endif

ifdef GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND 
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    COM_DEFS += __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__
  endif
endif

ifneq ($(filter NONE GSM,$(call Upper,$(PROJECT))),)
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    $(warning ERROR: PLEASE turn off GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND in $(PROJECT) project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifndef MAX_NUM_OF_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
    $(warning ERROR: please set MULTIPLE_PPP_DIALUP_SUPPORT as FALSE on custom\internal project,otherwise there will be errors like:non-numeric second argument to `wordlist' function.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef MULTIPLE_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
    ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),3),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than 3)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),2),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be less than 2)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS          += __MULTIPLE_PPP_DIALUP_SUPPORT__
    COM_DEFS          += __MAX_NUM_OF_PPP_DIALUP_SUPPORT__=$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT))
  endif
endif

MEDIA_PLAYER_VER_MAIN_LCD_SIZE = 128X160 176X220 240X240 240X320 240X400 320X480 320X240 360X640 480X800 
ifdef MEDIA_PLAYER_VER
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_DB_VF)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non INTEGRATED_DB_VF,SQLITE3_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(MEDIA_PLAYER_VER_MAIN_LCD_SIZE)),)
      $(warning ERROR: MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) is not supported when MEDIA_PLAYER_VER = INTEGRATED_DB_VF!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER_DB_VF__
  endif 
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED)
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(MEDIA_PLAYER_VER_MAIN_LCD_SIZE)),)
      $(warning ERROR: MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) is not supported when MEDIA_PLAYER_VER = INTEGRATED!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER__
  endif
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_FTE_DB)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB,SQLITE3_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(call DEP_ERR_SETA_OR_SETB,FINGER_TOUCH_SUPPORT,FTE,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6225)
      $(call DEP_ERR_SETA_OR_SETB,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB,PLATFORM,non MT6225)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER_FTE_DB__ __PLST_SERVICE_DB_SUPPORT__
  endif
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_DB)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB,SQLITE3_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER_DB__ __PLST_SERVICE_DB_SUPPORT__
  endif 
  ifeq ($(strip $(MEDIA_PLAYER_VER)),COSMOS_MUSIC_PLY)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non COSMOS_MUSIC_PLY,SQLITE3_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,COSMOS_MMI,MEDIA_PLAYER_VER,non COSMOS_MUSIC_PLY)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __COSMOS_MUSICPLY__ __PLST_SERVICE_DB_SUPPORT__
  endif
  ifeq ($(strip $(MEDIA_PLAYER_VER)),COSMOS_MUSICPLY_SLIM)
    ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,COSMOS_MMI,MEDIA_PLAYER_VER,non COSMOS_MUSIC_PLY)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __COSMOS_MUSICPLY_SLIM__ __PLAYLIST_SERVICE_SLIM__
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    ifdef DRM_SUPPORT_SCAN_DISK
      ifeq ($(strip $(DRM_SUPPORT_SCAN_DISK)),TRUE)
        ifeq ($(strip $(DRM_SUPPORT)),WS)
          $(warning ERROR: DRM_SUPPORT_SCAN_DISK can not be TRUE when DRM_SUPPORT equals to WS)
          DEPENDENCY_CONFLICT = TRUE
        endif 
        COM_DEFS += __DRM_SUPPORT_SCAN_DISK__
      endif
    endif
    ifdef DRM_SUPPORT_DB_SIZE
      ifeq ($(strip $(DRM_SUPPORT_DB_SIZE)),NONE)
        COM_DEFS   += MAX_DRM_DB_SIZE=(0)
      endif
      ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),NONE)
        ifeq ($(strip $(DRM_SUPPORT_DB_SIZE)),DEFAULT)
          ifeq ($(strip $(DRM_SUPPORT)),BSCI)
            COM_DEFS   += MAX_DRM_DB_SIZE=(64)
          else
            COM_DEFS   += MAX_DRM_DB_SIZE=(1024)
          endif
        else
          ifeq ($(strip $(DRM_SUPPORT)),BSCI)
            ifeq ($(call gt, $(strip $(DRM_SUPPORT_DB_SIZE)),64), T)
              $(warning ERROR: DRM_SUPPORT_DB_SIZE value is incorrect!)
              DEPENDENCY_CONFLICT = TRUE
            endif
            COM_DEFS   += MAX_DRM_DB_SIZE=(64)
          else
            ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),256)
              ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),512)
                ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),1024)
                  $(warning ERROR: DRM_SUPPORT_DB_SIZE value is incorrect!)
                  DEPENDENCY_CONFLICT = TRUE
                endif
              endif
            endif
            COM_DEFS   += MAX_DRM_DB_SIZE=($(strip $(DRM_SUPPORT_DB_SIZE)))
          endif
        endif
      endif
    endif
  endif
endif

ifdef BACKGROUND_CALL_SUPPORT
  ifeq ($(strip $(BACKGROUND_CALL_SUPPORT)),TRUE)
    ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
      $(warning ERROR: BACKGROUND_CALL_SUPPORT can not be TRUE when MMI_BASE is NEPTUNE_MMI)
      DEPENDENCY_CONFLICT = TRUE
    endif 
    COM_DEFS    +=  __BACKGROUND_CALL_SUPPORT__
  endif
endif

ifneq ($(strip $(MODEM_CARD)),NONE)
  COM_DEFS += __MODEM_CARD__
  COM_DEFS += __DISABLE_MODEM_AUTO_POWER_OFF__
  COM_DEFS += __MODEM_AUTO_STARTUP_TO_FLIGHT_MODE__
  COM_DEFS += __CSCB_ALL_LANGUAGE_ON__
  COM_DEFS += __AT_LINUX_DATA_PORT__
  COM_DEFS += __MOBILE_BROADBAND_PROVISION_CONTEXT__
  ifeq ($(strip $(MODEM_CARD)),CS_CALL_DISABLE)
    COM_DEFS += __DISABLE_CSCALL__
  endif
endif

ifdef MULTIPLE_NDIS_SUPPORT
  ifeq ($(strip $(MULTIPLE_NDIS_SUPPORT)),TRUE)
     ifndef NDIS_SUPPORT
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(NDIS_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
       $(call DEP_ERR_OFFA_OR_OFFB,MULTIPLE_NDIS_SUPPORT,MULTIPLE_PPP_DIALUP_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),6),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than 6)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),2),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be less than 2)
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS          += __MULTIPLE_NDIS_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_NDIS_SUPPORT__=$(strip $(MAX_NUM_OF_NDIS_SUPPORT))
  endif
endif

ifndef NVRAM_NOT_PRESENT
  ifdef NVRAM_PSEUDO_MERGE
    ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
      COM_DEFS +=  __NVRAM_PSEUDO_MERGE__
    endif
  endif
endif

ifdef NVRAM_PSEUDO_MERGE
  ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
    ifdef SDS_SUPPORT
      ifeq ($(strip $(SDS_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,NVRAM_PSEUDO_MERGE,SDS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef NVRAM_PSEUDO_MERGE
  ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
    ifdef SPI_NAND_SUPPORT
      ifeq ($(strip $(SPI_NAND_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,NVRAM_PSEUDO_MERGE,SPI_NAND_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef UDX_SUPPORT
  ifeq ($(strip $(UDX_SUPPORT)),TRUE)
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,UDX_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __UDX_SUPPORT__
    COMPLIST    += udx
  endif
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COM_DEFS    += __UCM_SUPPORT__
  COM_DEFS    += __AUTO_CALL_REJECTION__
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  COM_DEFS    += __UCM_SUPPORT__
  COM_DEFS    += __AUTO_CALL_REJECTION__
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  COM_DEFS    += __UCM_SUPPORT__
  COM_DEFS    += __AUTO_CALL_REJECTION__
endif

ifeq ($(strip $(SMS_R8_NATION_LANGUAGE)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    ifeq ($(strip $(EMS_SUPPORT)),EMS_NONE)
      $(call DEP_ERR_ONA_OR_OFFB,EMS_SUPPORT,EMS_R8_NATION_LANGUAGE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef EMS_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,EMS_SUPPORT,EMS_R8_NATION_LANGUAGE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __SMS_R8_NATION_LANGUAGE__
endif

ifdef UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE
  ifeq ($(strip $(UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)), TRUE)
    ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)), TRUE)
      ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
        $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
  endif
endif

ifneq ($(strip $(WAP_MMS_FEATURES)),NONE)   
# New method
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifneq ($(strip $(WAP_MMS_FEATURES)),FULL)
      ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
        $(warning ERROR: COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE must be OFF when WAP_MMS_FEATURES = ULTRA_SLIM/ULTRA_SLIM_SECURITY!)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __SLIM_MMS__
      COM_DEFS += __LOW_TIER_SLIM_MMS__
    endif
  endif
else     
# Old method
  ifdef MMS_FEATURES
    ifndef MMS_SUPPORT
      $(warning ERROR: Please define MMS_SUPPORT when MMS_FEATURES is defined!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMS_FEATURES)),NONE)
      ifneq ($(strip $(MMS_SUPPORT)),NONE)
        $(warning ERROR: MMS_FEATURES can NOT be NONE when MMS_SUPPORT != NONE!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(MMS_FEATURES)),NONE)
      ifeq ($(strip $(MMS_SUPPORT)),NONE)
        $(warning ERROR: MMS_FEATURES MUST be NONE when MMS_SUPPORT = NONE!)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(MMS_FEATURES)),SLIM)
        ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
          $(warning ERROR: COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE must be OFF when MMS_FEATURES = SLIM!)
          DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS += __SLIM_MMS__
      endif
      ifeq ($(strip $(MMS_FEATURES)),LOW_TIER_SLIM)
        ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
          $(warning ERROR: COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE must be OFF when MMS_FEATURES = LOW_TIER_SLIM!)
          DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS += __SLIM_MMS__
        COM_DEFS += __LOW_TIER_SLIM_MMS__
      endif
    endif
  endif
endif

ifdef SYNCML_DEVICE_SYNC_SUPPORT
  ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
    ifneq ($(strip $(SYNCML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SYNCML_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef BLUETOOTH_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __SYNCML_DEVICE_SYNC__
    COM_DEFS    += __SYNCML_TRANS_BT_SUPPORT__
    COM_DEFS    += __BT_SUPPORT_SYNCML__
    COM_DEFS    += __OBEX_ADAP_SUPPORT__
    ifneq ($(strip $(EMPTY_RESOURCE)),TRUE)
      COM_DEFS    += __SYNCML_DEVICE_SYNC_INTERNAL_TEST__
    endif
  endif
endif

ifdef SYNCML_PC_SYNC_SUPPORT
  ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
    ifneq ($(strip $(SYNCML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SYNCML_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef BLUETOOTH_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __SYNCML_PC_SYNC_SUPPORT__
    COM_DEFS    += __SYNCML_TRANS_BT_SUPPORT__
    COM_DEFS    += __BT_SUPPORT_SYNCML__
    COM_DEFS    += __OBEX_ADAP_SUPPORT__
  endif
endif

ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
  COMPLIST    += obex_stub
else
  ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
    COMPLIST    += obex_stub
  endif
endif

ifdef SMS_R8_TABLE_MECHANISM
  COM_DEFS += __$(strip $(SMS_R8_TABLE_MECHANISM))__
else
  COM_DEFS += __SMS_R8_DEFAULT__
endif

ifdef GENERAL_EXTERNAL_CHARGER
  ifneq ($(strip $(GENERAL_EXTERNAL_CHARGER)),NONE)
    COM_DEFS    +=  __GENERAL_EXTERNAL_CHARGER__
    COM_DEFS    +=  __EXT_CHARGER_$(strip $(GENERAL_EXTERNAL_CHARGER))__
  endif
endif

ifdef CMMB_CAS_FULL_CARD_SUPPORT
  ifeq ($(strip $(CMMB_CAS_FULL_CARD_SUPPORT)),TRUE)
    ifeq ($(strip $(CMMB_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_FULL_CARD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMMB_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_FULL_CARD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __CMMB_CAS_FULL_CARD_SUPPORT__
    ifeq ($(filter DRV_MSDC_CLK_SEARCH,$(COM_DEFS)),)
      COM_DEFS += DRV_MSDC_CLK_SEARCH
    endif
  endif
endif

ifdef SCALADO_SUPPORT
  ifeq ($(strip $(SCALADO_SUPPORT)), TRUE)
    COM_DEFS    += SCALADO_SUPPORT
    COM_DEFS    += __SCALADO_SUPPORT__

    # for integration testing only. Remove afterward.
    COM_DEFS    += SRV_IES_TESTBED_ENABLE

    SCALADO_ARM_LIB = baseapi.a capseng.a codecs.a excodecs.a fmexif.a fmextencoder.a fmphotoartclipart.a fmphotoartpack1.a fmphotoartscribble.a fmspeedview.a osljpeg_sw.a
    ifeq ($(strip $(PLATFORM)),MT6276)
      SCALADO_ARM_LIB_LIST = $(addprefix vendor\scalado\lib\ARM11\,$(SCALADO_ARM_LIB))
    else
      ifeq ($(strip $(PLATFORM)),MT6256)
        SCALADO_ARM_LIB_LIST = $(addprefix vendor\scalado\lib\ARM11\,$(SCALADO_ARM_LIB))
      else
        SCALADO_ARM_LIB_LIST = $(addprefix vendor\scalado\lib\ARM9\,$(SCALADO_ARM_LIB))
      endif
    endif
    SCALADO_WIN32_LIB = baseapi.lib capseng.lib codecs.lib excodecs.lib fmexif.lib fmextencoder.lib fmphotoartclipart.lib fmphotoartpack1.lib fmphotoartscribble.lib fmspeedview.lib oslansi.lib osljpeg_sw.lib
    SCALADO_WIN32_LIB_LIST = $(addprefix vendor\scalado\lib\WIN32\,$(SCALADO_WIN32_LIB))
    COMPLIST          += scalado
    COMPOBJS         += $(SCALADO_ARM_LIB_LIST)
    CUS_REL_OBJ_LIST += $(SCALADO_ARM_LIB_LIST) $(SCALADO_WIN32_LIB_LIST)
  endif
endif

ifndef MELODY_BUFFER_LEN
  ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
     MELODY_BUFFER_LEN = 512
  else
    ifeq ($(strip $(MED_PROFILE)),MED_LOW)
      MELODY_BUFFER_LEN = 1300
    else
      MELODY_BUFFER_LEN = 102400
    endif
  endif
endif 

ifdef OPTR_CODE
  ifeq ($(strip $(OPTR_CODE)),OP12)
    MELODY_BUFFER_LEN = 307200
  endif
endif

ifdef MELODY_BUFFER_LEN
  COM_DEFS += MAX_MELODY_BUF_LEN=$(strip $(MELODY_BUFFER_LEN))
endif

ifdef UNIFIED_MESSAGE_SORT_MESSAGE_LIST
  ifeq ($(strip $(UNIFIED_MESSAGE_SORT_MESSAGE_LIST)), TRUE)
    ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)), TRUE)
      ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
        $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)), TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    += __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__

    ifeq ($(filter __UNIFIED_MESSAGE_LIST_INDEX_DATA__,$(COM_DEFS)),)
      COM_DEFS    += __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    endif
  endif
endif

#ifeq ($(strip $(STREAM_REC_SUPPORT)),TRUE)
#  ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
#     $(call DEP_ERR_ONA_OR_OFFB,STREAM_SUPPORT,STREAM_REC_SUPPORT)
#     DEPENDENCY_CONFLICT = TRUE
#  endif
#  COM_DEFS += __STREAM_REC_SUPPORT__
#endif

ifdef SSL_SUPPORT
  ifeq ($(filter NONE OPENSSL OPENSSL_MTK,$(strip $(SSL_SUPPORT))),)
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,SSL_SUPPORT,OPENSSL or OPENSSL_MTK,WIFI_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
  COMPLIST            += seclib ossl_osadp ossl_crypto ossl_pki ossl_pkiadp
  COM_DEFS            += __SECLIB_SUPPORT__
endif
ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
  COMPLIST            += seclib ossl_osadp ossl_crypto ossl_pki ossl_pkiadp
  COM_DEFS            += __SECLIB_SUPPORT__
endif

ifndef MRE_PACKAGE
  ifdef MMI_VERSION
    ifneq ($(filter COSMOS_MMI PLUTO_MMI IOT_MMI,$(MMI_VERSION)),)
      $(warning ERROR: Please define MRE_PACKAGE in project makefile if MMI_VERSION = COSMOS_MMI or PLUTO_MMI or IOT_MMI.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
else
  ifneq ($(filter COSMOS_MMI PLUTO_MMI IOT_MMI,$(MMI_VERSION)),)
    COM_DEFS += MRE_VERSION=3100
    ifeq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(strip $(COM_DEFS))),)
      ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(strip $(COM_DEFS))),)
        COM_DEFS += __TWO_KEY_DETECTION_SWITCHABLE__
      endif
    endif
    COMP_TRACE_DEFS += plutommi\mmi\Inc\MMI_mre_app_info_trc.h
    COMP_TRACE_DEFS += plutommi\mmi\Inc\MMI_mre_trc.h

    COMPLIST    += mre_custom
    COMPLIST    += mre_engine

    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS += mre\lib\mrecorervct.lib
    else
      COMPOBJS += mre\lib\mrecore.lib
    endif

    CUS_REL_OBJ_LIST += mre\lib\mrecore.lib
    CUS_REL_OBJ_LIST += mre\lib\mrecorervct.lib
    CUS_REL_BASE_COMP += mre\vxp
    CUS_REL_BASE_COMP += mre\commoninc
    CUS_REL_BASE_COMP += mre\sdkinc
    CUS_REL_BASE_COMP += mre\sdkextinc
    COMMINCDIRS     += mre\commoninc
    COMMINCDIRS     += mre\sdkinc
    COMMINCDIRS     += mre\sdkextinc
    
    ifeq ($(strip $(MRE_PACKAGE)),FULL)
      COM_DEFS += __MRE_PACKAGE_FULL__
      COM_DEFS += __NBR_CELL_INFO__
      COM_DEFS += MRE_SYS_MEMORY_SIZE=1536
      COM_DEFS += __MRE_AM__

      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,MRE_PACKAGE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,MRE_PACKAGE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(MRE_PACKAGE)),NORMAL)
      COM_DEFS += __MRE_PACKAGE_NORMAL__
      COM_DEFS += __NBR_CELL_INFO__
      COM_DEFS += MRE_SYS_MEMORY_SIZE=1024
    endif

    ifeq ($(strip $(MRE_PACKAGE)),SLIM)
      COM_DEFS += __MRE_PACKAGE_SLIM__
      COM_DEFS += __NBR_CELL_INFO__
      COM_DEFS += MRE_SYS_MEMORY_SIZE=600
    endif
  endif
endif

ifeq ($(strip $(VM_CONCURRENCE)),CONCURRENT)
  COM_DEFS    += __VM_CONCURRENCE__
endif

ifdef IMAGE_VIEWER_VER
  ifneq ($(strip $(IMAGE_VIEWER_VER)),NONE)
    IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE = 176X220 240X240 240X320 240X400 320X480 320X240 360X640 480X800
    IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM = MT6223 MT6223C MT6219 MT6228 MT6229 MT6230 

    ifeq ($(strip $(IMAGE_VIEWER_VER)),SLIM)
      COM_DEFS += __IMAGE_VIEWER_SLIM__
    endif

    ifeq ($(strip $(IMAGE_VIEWER_VER)),STANDARD)
      COM_DEFS += __IMAGE_VIEWER_STANDARD__
    endif

    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX)
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(warning ERROR: MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(JPG_DECODE)),TRUE)
          $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX,JPG_DECODE)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __IMAGE_VIEWER_EX__
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COM_DEFS += __IMAGE_VIEWER_EX_MEM_SLIM__
        endif
      endif
    endif

    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX_SHARE_MEDMEM)
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(warning ERROR: MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(JPG_DECODE)),TRUE)
          $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_SHARE_MEDMEM,JPG_DECODE)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __IMAGE_VIEWER_EX__
      COM_DEFS += __IMAGE_VIEWER_EX_SHARE_MEDMEM__
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COM_DEFS += __IMAGE_VIEWER_EX_MEM_SLIM__
        endif
      endif
    endif

    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX_DB_SHARE_MEDMEM)
      ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB_SHARE_MEDMEM,SQLITE3_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(warning ERROR: MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      else
          ifneq ($(strip $(JPG_DECODE)),TRUE)
              $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB_SHARE_MEDMEM,JPG_DECODE)
              DEPENDENCY_CONFLICT = TRUE
          endif
      endif
      COM_DEFS += __IMAGE_VIEWER_EX_DB__
      COM_DEFS += __IMAGE_VIEWER_EX_SHARE_MEDMEM__
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COM_DEFS += __IMAGE_VIEWER_EX_MEM_SLIM__
        endif
      endif
    endif

    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX_DB)
      ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,SQLITE3_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(warning ERROR: MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      else
          ifneq ($(strip $(JPG_DECODE)),TRUE)
              $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,JPG_DECODE)
              DEPENDENCY_CONFLICT = TRUE
          endif
      endif
      COM_DEFS += __IMAGE_VIEWER_EX_DB__
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COM_DEFS += __IMAGE_VIEWER_EX_MEM_SLIM__
        endif
      endif
    endif
   endif
endif

ifeq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
  COM_DEFS    += __BITSTREAM_API_SUPPORT__
endif

#ifdef CMMB_CAS_SMD_SUPPORT
#  ifeq ($(strip $(CMMB_CAS_SMD_SUPPORT)),TRUE)
#    ifeq ($(strip $(CMMB_SUPPORT)),NONE)
#      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_SMD_SUPPORT)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
#    ifndef CMMB_SUPPORT
#      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_SMD_SUPPORT)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
#    COM_DEFS    += __CMMB_CAS_SMD_SUPPORT__
#    # CMMB Nagra KDA lib
#    COMPOBJS    += vendor\cmmb\nagra\lib\kda.a
#    CUS_REL_OBJ_LIST += vendor\cmmb\nagra\lib\kda.a
#    CUS_REL_FILES_LIST += vendor\cmmb\nagra\lib\kda.a
#  endif
#endif

ifdef GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP)),TRUE)
    COM_DEFS += __PPP_SPEED_UP_IPV4_GPRS_DIALUP__
  endif
endif

ifneq ($(strip $(VENUS_MMI)),NONE)
  ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI/COSMOS_MMI,VENUS_MMI)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS         += __VENUS_UI_ENGINE__ __FANCY_PLUTO_APP_ON_VENUS_UI__
  ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
    ifndef OPENGLES_SUPPORT
      $(call DEP_ERR_SETA_OR_OFFB,OPENGLES_SUPPORT,TRUE,VENUS_3D)
    else
      ifneq ($(strip $(OPENGLES_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_OFFB,OPENGLES_SUPPORT,TRUE,VENUS_3D)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS       += __VENUS_3D_UI_ENGINE__
  endif
  COMPLIST         += venusmmi venus_rt
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  ifneq ($(strip $(VENUS_MMI)),NONE)
    COMPLIST         += vrt vrt16 mmi_core vrt_adp gdi_g2d
    CUS_REL_BASE_COMP += venusmmi\vrt\adp
    CUS_REL_BASE_COMP += venusmmi\app \
                         venusmmi\app\pluto_variation \
                         venusmmi\framework \
                         venusmmi\app\pluto_variation\adapter \
                         venusmmi\app\common \
                         venusmmi\app\common\interface \
                         venusmmi\test \
                         venusmmi\visual \
                         venusmmi\vrt\interface \
                         venusmmi\framework\xml \
                         make\venusmmi
    COMP_TRACE_DEFS  += venusmmi\app\pluto_variation\adapter\interface\trc\vadp_sys_trc.h
    COMP_TRACE_DEFS  += venusmmi\app\pluto_variation\adapter\interface\trc\vadp_app_trc.h
    COMP_TRACE_DEFS  += venusmmi\vrt\interface\vrt_trc.h
  endif
  ifeq ($(strip $(VENUS_MMI)),NONE)
    COMPLIST         += mmi_core gdi_g2d
    CUS_REL_BASE_COMP += venusmmi\framework\xml
  endif
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  ifneq ($(strip $(VENUS_MMI)),NONE)
    COMPLIST         += vrt vrt16 mmi_core vrt_adp gdi_g2d
    CUS_REL_BASE_COMP += venusmmi\vrt\adp
    CUS_REL_BASE_COMP += venusmmi\app \
                         venusmmi\app\pluto_variation \
                         venusmmi\framework \
                         venusmmi\app\pluto_variation\adapter \
                         venusmmi\app\common \
                         venusmmi\app\common\interface \
                         venusmmi\test \
                         venusmmi\visual \
                         venusmmi\vrt\interface \
                         venusmmi\framework\xml \
                         make\venusmmi
    COMP_TRACE_DEFS  += venusmmi\app\pluto_variation\adapter\interface\trc\vadp_sys_trc.h
    COMP_TRACE_DEFS  += venusmmi\app\pluto_variation\adapter\interface\trc\vadp_app_trc.h
    COMP_TRACE_DEFS  += venusmmi\vrt\interface\vrt_trc.h
  endif
  ifeq ($(strip $(VENUS_MMI)),NONE)
    COMPLIST         += mmi_core
  endif
  ifeq ($(strip $(IOT_NO_MULTIMEDIA)), TRUE)
    COM_DEFS += __IOT_NO_MULTIMEDIA__  
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  COMPLIST         += vrt vrt16 mmi_service mmi_core gdi mmi_framework vrt_adp gdi_g2d
  CUS_REL_BASE_COMP += venusmmi\vrt\adp
  CUS_REL_BASE_COMP += venusmmi\app \
                       venusmmi\app\pluto_variation \
                       venusmmi\framework \
                       venusmmi\app\pluto_variation\adapter \
                       venusmmi\app\common \
                       venusmmi\app\common\interface \
                       venusmmi\test \
                       venusmmi\visual \
                       venusmmi\vrt\interface \
                       venusmmi\framework\xml \
                       make\venusmmi
  COMP_TRACE_DEFS  += venusmmi\app\pluto_variation\adapter\interface\trc\vadp_sys_trc.h
  COMP_TRACE_DEFS  += venusmmi\app\pluto_variation\adapter\interface\trc\vadp_app_trc.h
  COMP_TRACE_DEFS  += venusmmi\vrt\interface\vrt_trc.h
endif

COMMINCDIRS   += venusmmi\framework\ui_core\base

ifeq ($(strip $(WAP_MEM_DEBUG)),TRUE)
  COM_DEFS    +=   WAP_MEM_DEBUG
endif

COM_DEFS += __HO_IMPROVE__

ifdef QOS_PROFILE_SUPPORT
  ifneq ($(strip $(QOS_PROFILE_SUPPORT)),NONE)
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: Please add __PS_SERVICE__ to CUSTOM_OPTION or turn off QOS_PROFILE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(QOS_PROFILE_SUPPORT)), DYNAMIC)
      COM_DEFS    +=  __APP_DYNAMIC_QOS_PROFILE_SUPPORT__
    endif
    ifeq ($(strip $(QOS_PROFILE_SUPPORT)), STATIC)
      COM_DEFS    +=  __APP_STATIC_QOS_PROFILE_SUPPORT__
    endif
    ifeq ($(strip $(QOS_PROFILE_SUPPORT)), ALL)
      COM_DEFS    +=  __APP_DYNAMIC_QOS_PROFILE_SUPPORT__
      COM_DEFS    +=  __APP_STATIC_QOS_PROFILE_SUPPORT__
    endif
  endif
endif

ifdef DRV_DEBUG_MEMORY_TRACE_SUPPORT
  ifeq ($(strip $(DRV_DEBUG_MEMORY_TRACE_SUPPORT)),TRUE)
    COM_DEFS    +=  __DRV_DBG_MEMORY_TRACE_SUPPORT__
  endif
endif

ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __AT_EPBW_SUPPORT__
  endif
endif

ifndef PHB_NAME_LENGTH
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    PHB_NAME_LENGTH = 30
  else
    PHB_NAME_LENGTH = 40
  endif
endif

ifdef PHB_NAME_LENGTH
  ifeq ($(call gt,$(strip $(PHB_NAME_LENGTH)),80),T)
    $(warning ERROR: PHB_NAME_LENGTH value should not be larger than 80)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    COM_DEFS    += MAX_PHB_NAME_LENGTH=16
  else
    COM_DEFS    += MAX_PHB_NAME_LENGTH=$(strip $(PHB_NAME_LENGTH))
  endif
  COM_DEFS    += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
endif

COMMINCDIRS +=  fmr\inc

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
    COMPLIST         += fmr
    CUS_REL_BASE_COMP += fmr
  endif
endif

ifdef SYNCML_DM_VERSION
  ifneq ($(strip $(SYNCML_DM_VERSION)),NONE)
    ifeq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SYNCML_DM_SUPPORT,SYNCML_DM_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYNCML_DM_VERSION)),DM12)
      COM_DEFS += __SYNCML_DM12__
    endif
    ifeq ($(strip $(SYNCML_DM_VERSION)),DM12_SCTS)
      COM_DEFS += __SYNCML_DM12__
      COM_DEFS += __SCTS_TOOLS_TEST__
    endif
  endif
endif

MCD_DEFS  = __R99__
MCD_DEFS += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
ifdef MCD_CODESET_SHIFT_SUPPORT
  ifneq ($(strip $(MCD_CODESET_SHIFT_SUPPORT)),NONE)
    MCD_DEFS += __MCD_CODESET_SHIFT__
    MCD_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
    COM_DEFS += __MCD_CODESET_SHIFT__
    COM_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
  endif
endif

ifneq ($(filter __L4_MAX_NAME_60__,$(COM_DEFS)),)
  MCD_DEFS += __L4_MAX_NAME_60__
endif

ifeq ($(strip $(MAIN_MEDIA_LAYER_BITS_PER_PIXEL)),24)
  COM_DEFS    +=  MAIN_MEDIA_LAYER_BITS_PER_PIXEL=24
endif

ifeq ($(strip $(PLMN_LIST_PREF_SUPPORT)),ON)
  COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
endif

ifeq ($(strip $(WIFI_BT_SINGLE_ANTENNA_SUPPORT)),TRUE)
  BT_SINGLE_ANTENNA_SUPPORT_CHIP = BTMTK_MT6612 BTMTK_MT6616 BTMTK_MT6236 BTMTK_MT6276 BTMTK_MT6256 BTMTK_MT6255 BTMTK_MT6921 BTMTK_MT6922 BTMTK_MT6250 BTMTK_MT6260 BTMTK_MT6261 BTMTK_MT2501 BTMTK_MT2502
  ifeq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BT_SINGLE_ANTENNA_SUPPORT_CHIP)),)
    $(warning ERROR: BT $(strip $(BLUETOOTH_SUPPORT)) does not support WIFI_BT_SINGLE_ANTENNA_SUPPORT!)
    $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,WIFI_BT_SINGLE_ANTENNA_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(WIFI_SUPPORT)),MT5931)
    ifneq ($(strip $(WIFI_SUPPORT)),MT5921)
      $(warning ERROR: WIFI $(strip $(WIFI_SUPPORT)) does not support WIFI_BT_SINGLE_ANTENNA_SUPPORT!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS  +=  __WIFI_BT_SINGLE_ANTENNA_SUPPORT__
  ifeq ($(strip $(WIFI_BT_SINGLE_ANTENNA_DESIGN)),TDD)
    BT_NON_TDD_CHIP = BTMTK_MT6612 BTMTK_MT6616 BTMTK_MT6236 BTMTK_MT6276
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BT_NON_TDD_CHIP)),)
      $(warning ERROR: BT $(strip $(BLUETOOTH_SUPPORT)) does not support WIFI_BT_SINGLE_ANTENNA_DESIGN = TDD!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      $(warning ERROR: WIFI $(strip $(WIFI_SUPPORT)) does not support WIFI_BT_SINGLE_ANTENNA_DESIGN = TDD!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  +=  __WIFI_BT_SINGLE_ANTENNA_DESIGN_TDD__
  endif
endif

ifneq ($(filter __MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR: __MONITOR_PAGE_DURING_TRANSFER__ can only be defined when __PS_SERVICE__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __SMART_PAGING__,$(COM_DEFS)),)
  ifeq ($(filter __MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
    $(warning ERROR: __SMART_PAGING__ can only be defined when __MONITOR_PAGE_DURING_TRANSFER__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(filter FMT_NOT_PRESENT,$(COM_DEFS)),)
  COMP_TRACE_DEFS  += fmt\include\fmt_trc.h
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COM_DEFS += __SMS_STORAGE_BY_MMI__ __PHB_STORAGE_BY_MMI__ __CLOG_STORAGE_BY_MMI__
  COM_DEFS += __DIALUP_GPRS_COUNTER_SUPPORT__ __PHB_APPROVE_BY_MMI__
  COM_DEFS += __PHB_NO_CALL_LOG__ __PHB_ACCESS_SIM_LN__
  COMPLIST += smslib
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  COM_DEFS += __SMS_STORAGE_BY_MMI__ __PHB_STORAGE_BY_MMI__ __CLOG_STORAGE_BY_MMI__
  COM_DEFS += __DIALUP_GPRS_COUNTER_SUPPORT__ __PHB_APPROVE_BY_MMI__
  COM_DEFS += __PHB_NO_CALL_LOG__ __PHB_ACCESS_SIM_LN__
  COMPLIST += smslib
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  COM_DEFS    += __LANG_NOTIFY_RES_BY_MMI__
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  COM_DEFS += __SMS_STORAGE_BY_MMI__ __PHB_STORAGE_BY_MMI__ __CLOG_STORAGE_BY_MMI__
  COM_DEFS += __DIALUP_GPRS_COUNTER_SUPPORT__ __PHB_APPROVE_BY_MMI__
  COM_DEFS += __PHB_NO_CALL_LOG__ __PHB_ACCESS_SIM_LN__
  COMPLIST += smslib
endif


ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  COM_DEFS += __SMS_STORAGE_BY_MMI__
  COMPLIST += smslib
endif

ifdef UNIFIED_PUSH_FEATURES
  ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
#Old method
    ifneq ($(strip $(UNIFIED_PUSH_FEATURES)),NONE)
      ifndef OBIGO_FEATURE
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,UNIFIED_PUSH_FEATURES)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,UNIFIED_PUSH_FEATURES)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(OBIGO_FEATURE)),WAP2_HTTP_ONLY)
        $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP/WAP2/WAP2_SEC,UNIFIED_PUSH_FEATURES)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC_HTTP_ONLY)
        $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP/WAP2/WAP2_SEC,UNIFIED_PUSH_FEATURES)
        DEPENDENCY_CONFLICT = TRUE
      endif    
      ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,UNIFIED_PUSH_FEATURES)
         DEPENDENCY_CONFLICT = TRUE
      endif

      ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),FULL)
        COM_DEFS    += __FULL_PUSH_FEATURE_SUPPORT__
      endif
      ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),STANDARD)
        COM_DEFS    += __STANDARD_PUSH_FEATURE_SUPPORT__
      endif
      ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),SLIM)
        COM_DEFS    += __SLIM_PUSH_FEATURE_SUPPORT__
      endif
      ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),SERVICE_ONLY)
        COM_DEFS    += __SLIM_PUSH_FEATURE_SUPPORT__
        COM_DEFS    += __WAP_PUSH_SERVICE_ONLY_SUPPORT__
      endif    
  
      COM_DEFS    += __PROVISIONING_SERVICE_SUPPORT__
      COM_DEFS    += __CCA_SUPPORT__
      ifdef SIM_PROVISIONING
        ifneq ($(strip $(SIM_PROVISIONING)),NONE)
          ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
            $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,SIM_PROVISIONING)
            DEPENDENCY_CONFLICT = TRUE
          else
            COM_DEFS    += __SPA_SUPPORT__
            COM_DEFS    += __DTCNT_SIM_PROFILES_SUPPORT__
          endif
        endif
        ifeq ($(strip $(SIM_PROVISIONING)),MMSICP)
          COM_DEFS    += __MMSICP_SUPPORT__
        endif
      endif
      COMPLIST    += obigo03cpushadp obigo03cpushlib
      COM_DEFS    += __WAP_PUSH_SUPPORT__
      COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
    endif
  else
#New method 
#Only 2 cases when Push will be ON are: if MMS is ON or WAP_MMS_FEATURES = FULL
    ifeq ($(strip $(WAP_MMS_FEATURES)),FULL)
      ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
        COM_DEFS    += __WAP_PUSH_SUPPORT__
      endif
    endif
    ifneq ($(strip $(MMS_SUPPORT)),NONE) 
      COM_DEFS    += __WAP_PUSH_SUPPORT__
    endif

    ifneq ($(filter __WAP_PUSH_SUPPORT__,$(COM_DEFS)),)
      ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
        $(warning ERROR: WBXML_SUPPORT=TRUE is required for WAP_MMS_FEATURES=FULL or when MMS_SUPPORT != NONE.)
        DEPENDENCY_CONFLICT = TRUE
      endif   
      ifeq ($(strip $(WAP_MMS_FEATURES)),FULL)
        ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
          COM_DEFS    += __FULL_PUSH_FEATURE_SUPPORT__
        else
          COM_DEFS    += __SLIM_PUSH_FEATURE_SUPPORT__
          COM_DEFS    += __WAP_PUSH_SERVICE_ONLY_SUPPORT__
        endif
      endif
      ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM)
        COM_DEFS    += __SLIM_PUSH_FEATURE_SUPPORT__
        ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
          COM_DEFS    += __WAP_PUSH_SERVICE_ONLY_SUPPORT__
        endif
      endif
      ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM_SECURITY)
        COM_DEFS    += __SLIM_PUSH_FEATURE_SUPPORT__
        ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
          COM_DEFS    += __WAP_PUSH_SERVICE_ONLY_SUPPORT__
        endif
      endif
      
      COM_DEFS    += __PROVISIONING_SERVICE_SUPPORT__
      COM_DEFS    += __CCA_SUPPORT__  
    
      ifdef SIM_PROVISIONING
        ifneq ($(strip $(SIM_PROVISIONING)),NONE)
          ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
            $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,SIM_PROVISIONING)
            DEPENDENCY_CONFLICT = TRUE
          else
            COM_DEFS    += __SPA_SUPPORT__
            COM_DEFS    += __DTCNT_SIM_PROFILES_SUPPORT__
          endif
        endif
        ifeq ($(strip $(SIM_PROVISIONING)),MMSICP)
          COM_DEFS    += __MMSICP_SUPPORT__
        endif
      endif
      COMPLIST    += obigo03cpushadp obigo03cpushlib
      COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
    endif
  endif
endif

ifdef DM_MO_SUPPORT
  ifneq ($(strip $(DM_MO_SUPPORT)),NONE)
    ifeq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SYNCML_DM_SUPPORT,DM_MO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef OPTR_SPEC
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,DM_MO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(OPTR_SPEC)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,DM_MO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS   += __DM_MO_SUPPORT__

    ifeq ($(strip $(DM_MO_SUPPORT)),LAW)
      COM_DEFS   += __DM_LAWMO_SUPPORT__
    endif
    ifeq ($(strip $(DM_MO_SUPPORT)),SCO)
      ifndef J2ME_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(J2ME_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS   += __DM_SCOMO_SUPPORT__ _DM_OMADL_VIA_DLAGENT_
    endif
    ifeq ($(strip $(DM_MO_SUPPORT)),LAW_SCO)
      ifndef J2ME_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(J2ME_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif    
      COM_DEFS   += __DM_LAWMO_SUPPORT__ __DM_SCOMO_SUPPORT__ _DM_OMADL_VIA_DLAGENT_
    endif
  endif
endif

ifdef HTTP_INTERFACE_SUPPORT
  ifeq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
        ifndef OBIGO_FEATURE
          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,HTTP_INTERFACE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,HTTP_INTERFACE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    COM_DEFS    += __HTTP_INTERFACE__
  endif
endif

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifdef OPTR_COMP
      COMPLIST    += $(strip $(OPTR_COMP))        # OPTR_COMP defined in operator.mak
    endif
  endif
endif

ifdef OPTR_SPEC_MODEM
  ifeq ($(strip $(OPTR_SPEC_MODEM)), ATT_0402_ADAPT)
    ifeq ($(strip $(USIM_SUPPORT)), TRUE)
      COM_DEFS  += __U_CSP_SUPPORT__
    endif
    ifneq ($(filter PLUTO_MMI COSMOS_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
      COM_DEFS  += __SIM_FILE_CHANGE_WITH_MMI_ACK__
    endif
    COM_DEFS  += __GPRS_PDP_ALL_QOS_ARE_SUBSCRIBED__
    COM_DEFS  += __IOT_TEST__ 
    COM_DEFS  += __UMAC_HSUPA_DEBUG__
    COM_DEFS  += __ENS__
    COM_DEFS  += __ENS_RAT_BALANCING__ 
    COM_DEFS  += __ATT_FLIGHT_MODE_GPS_HANDLING__
    COM_DEFS  += __ATNT_HPPLMN_SEARCH__
    COM_DEFS  += __DISABLE_AUTO_RETURN_PRE_RPLMN__
    COM_DEFS  += __OPTIMAL_SIM_FILE_UPDATE__
    COM_DEFS  += __DISABLE_RPLMN_FROM_GLOCI__
    COM_DEFS  += __RESUME_GPRS_AFTER_LU_ABNORMAL__
    COM_DEFS  += __CSIM__
    COM_DEFS  += __ATCFUN_FLIGHTMODE_SUPPORT__
    COM_DEFS  += __NW_DETACH_SUPPORT__
    COM_DEFS  += __CLAC_SUPPORT__
    COM_DEFS  += __CGSMS_FULL_SUPPORT__
    COM_DEFS  += __UDH_MESSAGE_WAITING_HIGH_PRIORITY__
    COM_DEFS  += __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    COM_DEFS  += __SAT_NO_EVDL_IN_SESSION__
    COM_DEFS  += __IMEI_LOCK_SUPPORT__
    COM_DEFS  += __STAR_SHORT_STRING_AS_CALL__
    COM_DEFS  += __CUSTOMIZED_IDLE_STRING_AS_CALL__
    COM_DEFS  += __MM_DISABLE_RETRY_ABNORMAL_LAI__
  endif
endif

ifdef FINGER_TOUCH_SUPPORT
  ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),NONE)
    FINGER_TOUCH_SUPPORT_SUPPORT_LCD_SIZE = 240X240 240X400 240X320 320X240 320X480 480X800 
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(FINGER_TOUCH_SUPPORT_SUPPORT_LCD_SIZE)),)
      $(warning ERROR: MAIN_LCD_SIZE $(strip $(MAIN_LCD_SIZE)) does not support FINGER_TOUCH_SUPPORT=$(strip $(FINGER_TOUCH_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      ifneq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_FTE_DB)
        ifneq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_DB)
          ifneq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED)
            ifneq ($(strip $(MEDIA_PLAYER_VER)),COSMOS_MUSIC_PLY)
              ifneq ($(strip $(MEDIA_PLAYER_VER)),COSMOS_MUSICPLY_SLIM)
                ifneq ($(strip $(MEDIA_PLAYER_VER)),SEPARATED)
                  $(call DEP_ERR_SETA_OR_SETB,MEDIA_PLAYER_VER,INTEGRATED_FTE_DB or INTEGRATED or INTEGRATED_DB or COSMOS_MUSIC_PLY or SEPARATED, FINGER_TOUCH_SUPPORT, non FTE)
                  DEPENDENCY_CONFLICT = TRUE
                endif
              endif
            endif
          endif
        endif
      endif
    endif
    COM_DEFS += __MMI_FTE_SUPPORT__
  endif
endif

ifdef UART_CHARGER_THE_SAME_INTERFACE
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART1)
    COM_DEFS    += __UART1_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART2)
    COM_DEFS    += __UART2_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART3)
    COM_DEFS    += __UART3_WITH_CHARGER__
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS    +=  __SLIM_NWK_PROFILE__
  endif
endif

ifdef TWOMICNR_SUPPORT
  ifneq ($(strip $(TWOMICNR_SUPPORT)),NONE)
    COM_DEFS += __TWOMICNR_SUPPORT__
  endif
endif

ifdef WAPI_SUPPORT
  ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      COM_DEFS += __WAPI_SUPPORT__
      ifeq ($(strip $(MMI_HIDE_WAPI)),TRUE)
        COM_DEFS += __MMI_HIDE_WAPI__
      endif
    else
      ifeq ($(strip $(WIFI_SUPPORT)),MT5931)
        COM_DEFS += __WAPI_SUPPORT__
        ifeq ($(strip $(MMI_HIDE_WAPI)),TRUE)
          COM_DEFS += __MMI_HIDE_WAPI__
        endif
      else
        $(call DEP_ERR_SETA_OR_OFFB,WIFI_SUPPORT,MT5921,WAPI_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_HIDE_WAPI)),TRUE)
  ifneq ($(strip $(WAPI_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_OFFB,WAPI_SUPPORT,TRUE,MMI_HIDE_WAPI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(OCSP_SUPPORT)),TRUE)
  ifeq ($(findstring OPENSSL,$(SSL_SUPPORT)),)
    $(call DEP_ERR_SETA_OR_OFFB,SSL_SUPPORT,OPENSSL/OPENSSL_MTK,OCSP_SUPPORT) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,OCSP_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __OCSP_SUPPORT__
endif

ifdef SMS_OVER_PS_SUPPORT
  ifeq ($(strip $(SMS_OVER_PS_SUPPORT)),TRUE)
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: __PS_SERVICE__ must be defined when SMS_OVER_PS_SUPPORT is turned on.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __SMS_OVER_PS_SUPPORT__
  endif
endif

ifeq ($(strip $(TC01_VOICE_ENGINE)),TRUE)
  COMPOBJS         += hal\audio\lib\VENDOR\tc01\AkouoClarity13v_3GSM_RVCT22_616.a
  CUS_REL_OBJ_LIST += hal\audio\lib\VENDOR\tc01\AkouoClarity13v_3GSM_RVCT22_616.a
  COMPOBJS         += hal\audio\lib\VENDOR\tc01\VS_RVCT_lib.a
  CUS_REL_OBJ_LIST += hal\audio\lib\VENDOR\tc01\VS_RVCT_lib.a
  COM_DEFS += __TC01_VOICE_ENGINE__
endif

ifdef DAF_ENCODE
  ifeq ($(strip $(DAF_ENCODE)),TRUE)
    ifneq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,I2S_INPUT_MODE_SUPPORT,DAF_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(CUST_CODE)),TC01)
      $(warning ERROR: DAF_ENCODE  could be enabled in TC01 project onlyd)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS         += hal\audio\lib\VENDOR\tc01\EmMp3EncLib_rvct.a
      CUS_REL_OBJ_LIST += hal\audio\lib\VENDOR\tc01\EmMp3EncLib_rvct.a
    endif  
    COM_DEFS += __DAF_ENCODE__
  endif
endif

ifdef PPP_TYPE_PDP_DIALUP_SUPPORT
  ifeq ($(strip $(PPP_TYPE_PDP_DIALUP_SUPPORT)),TRUE)
    COM_DEFS  +=  __PPP_TYPE_PDP_DIALUP_SUPPORT__
  endif
endif

#############################################################################################
# Add PPP_SUPPORT feature rule here
# firstly, set/reset PS_DIALUP and TCPIP_OVER_CSD sub_feature_option
# then check rule of each option
#############################################################################################
# Add PPP_SUPPORT feature rule here
# firstly, set/reset PS_DIALUP and TCPIP_OVER_CSD sub_feature_option
# then check rule of each option
# last modify COMPLIST, if PPP_SUPPORT != NONE, then compile PPP
# this part should after PPP_DEPENDENCE_OPTION define to check valid or not
# if not define PPP_SUPPORT, we should keep option as what it is before wrapping action
#############################################################################################

ifdef PPP_SUPPORT
  ifeq ($(strip $(PPP_SUPPORT)),CSD_PPP_SUPPORT)
    PS_DIALUP = FALSE
    TCPIP_OVER_CSD = TRUE
  endif
  ifeq ($(strip $(PPP_SUPPORT)),GPRS_PPP_SUPPORT)
    PS_DIALUP = TRUE
    TCPIP_OVER_CSD = FALSE
  endif
  ifeq ($(strip $(PPP_SUPPORT)),FULL_SUPPORT)
    PS_DIALUP = TRUE
    TCPIP_OVER_CSD = TRUE
  endif
  
  ifeq ($(strip $(PS_DIALUP)),TRUE)
    COM_DEFS += __PS_DIALUP__
  else
    PS_DIALUP_DEPENDENCE_OPTION = __MULTIPLE_PPP_DIALUP_SUPPORT__
    ifneq ($(filter $(PS_DIALUP_DEPENDENCE_OPTION),$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB, MULTIPLE_PPP_DIALUP_SUPPORT, FALSE, PS_DIALUP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(TCPIP_OVER_CSD)),TRUE)
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      ifdef CSD_SUPPORT
        ifneq ($(strip $(CSD_SUPPORT)),NONE)
          COM_DEFS += __TCPIP_OVER_CSD__
        else
          $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(filter __TCPIP_OVER_CSD__,$(COM_DEFS)),)
      $(warning ERROR: When TCPIP_OVER_CSD is not support, some related option should be closed.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(EXT_MODEM_SUPPORT)),TRUE)
    ifeq ($(strip $(PPP_SUPPORT)),GPRS_PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_OFFB, PPP_SUPPORT, FULL_SUPPORT , EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PPP_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_OFFB, PPP_SUPPORT, CSD_PPP_SUPPORT , EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_OFFB, TCPIP_SUPPORT, non NONE , EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CSD_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_OFFB, CSD_SUPPORT, non NONE , EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(PPP_SUPPORT)),NONE)
    PPP_DEPENDENCE_OPTION =__MULTIPLE_PPP_DIALUP_SUPPORT__ __TCPIP_OVER_CSD__ __EXT_MODEM__
    ifneq ($(filter $(PPP_DEPENDENCE_OPTION),$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB, MULTIPLE_PPP_DIALUP_SUPPORT, FALSE, PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_ONB, EXT_MODEM_SUPPORT, FALSE, PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_ONB, CSD_SUPPORT, NONE, PPP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += PPP_NOT_PRESENT
  endif
else
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    PS_DIALUP = TRUE
  else
    PS_DIALUP = FALSE
  endif
  ifeq ($(strip $(PS_DIALUP)),TRUE)
    COM_DEFS += __PS_DIALUP__
  endif
endif

PPP_MODULE_BUILD=FALSE
ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
  PPP_MODULE_BUILD=TRUE
endif
ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  PPP_MODULE_BUILD=TRUE
endif
ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
  ifeq ($(call Upper,$(strip $(PROJECT))),GSM)
      PPP_MODULE_BUILD=TRUE
  endif
endif

ifeq ($(strip $(PPP_MODULE_BUILD)),TRUE)
  ifndef PPP_SUPPORT
    COMPLIST += ppp
    ifeq ($(strip $(EXT_MODEM_SUPPORT)),TRUE)
      $(warning ERROR: When support EXT_MODEM, PPP_SUPPORT should be defined and set to CSD_PPP_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE  
    endif
  else
     ifneq ($(strip $(PPP_SUPPORT)),NONE)
        COMPLIST += ppp
     endif
  endif
endif

#####################################################################
# End related rule of PPP_SUPPORT
#####################################################################

ifdef FM_RADIO_I2S_PATH
  ifeq ($(strip $(FM_RADIO_I2S_PATH)),TRUE)
    ifneq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,I2S_INPUT_MODE_SUPPORT,FM_RADIO_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef FM_RADIO_CHIP
      $(call DEP_ERR_ONA_OR_OFFB,FM_RADIO_CHIP,FM_RADIO_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FM_RADIO_CHIP)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,FM_RADIO_CHIP,FM_RADIO_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __FMRADIO_I2S_SUPPORT__ 
  endif
endif

ifneq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
  COM_DEFS    += __CATCHER_EVENT_INFO__
endif

ifeq ($(strip $(FM_INTERFACE_TYPE)),I2C)
  COM_DEFS  += FM_INTERFACE_I2C
endif
ifeq ($(strip $(FM_INTERFACE_TYPE)),HCI)
  ifneq ($(strip $(FM_RADIO_CHIP)),MT6616)
    $(call DEP_ERR_SETA_OR_OFFB,FM_RADIO_CHIP,MT6616,FM_INTERFACE_TYPE)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += FM_INTERFACE_HCI
  endif
endif

ifneq ($(strip $(YUVCAM_INTERPOLATION)),NONE)
  YUVCAM_INTERPOLATION_SUPPORT_PLATFORM = MT6235 MT6235B MT6253 MT6253E MT6253L MT6252 MT6252H MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(filter $(strip $(PLATFORM)) ,$(YUVCAM_INTERPOLATION_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support YUVCAM_INTERPOLATION)
    DEPENDENCY_CONFLICT = TRUE
  endif  
  ifeq ($(strip $(YUVCAM_INTERPOLATION)),HW)
      COM_DEFS    += __YUVCAM_INTERPOLATION_HW__
  endif
  ifeq ($(strip $(YUVCAM_INTERPOLATION)),SW)
      COM_DEFS    += __YUVCAM_INTERPOLATION_SW__
  endif
endif

ifeq ($(filter L1S BASIC UDVT, $(strip $(call Upper,$(PROJECT)))),)
  ifeq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
     COMPLIST += applib applib_asn1
  endif
endif

ifneq ($(filter PLUTO_MMI COSMOS_MMI, $(strip $(MMI_VERSION))),)
  COMPLIST += mcsv
endif

ifdef CAPTURE_SCENARIO
  ifeq ($(strip $(CAPTURE_SCENARIO)),ON_THE_FLY)
    COM_DEFS += CAM_OTF_CAPTURE
  endif
  ifeq ($(strip $(CAPTURE_SCENARIO)),OFFLINE)
    COM_DEFS += CAM_OFFLINE_CAPTURE
  endif
  ifeq ($(strip $(CAPTURE_SCENARIO)),STANDARD)
    COM_DEFS += CAM_STANDARD_CAPTURE
  endif
endif

ifeq ($(strip $(TC01_BT_SYSTEM_SUPPORT)),TRUE)
  ifneq ($(strip $(CUST_CODE)),TC01)
    $(call DEP_ERR_SETA_OR_OFFB,CUST_CODE,TC01,TC01_BT_SYSTEM_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += LGE_BT_SYSTEM
endif

ifeq ($(strip $(TC01_OAEP_SUPPORT)),TRUE)
  ifneq ($(strip $(CUST_CODE)),TC01)
    $(call DEP_ERR_SETA_OR_OFFB,CUST_CODE,TC01,TC01_OAEP_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef BES_SURROUND_SUPPORT
    ifneq ($(strip $(BES_SURROUND_SUPPORT)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_SURROUND_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef BES_LOUDNESS_SUPPORT
    ifneq ($(strip $(BES_LOUDNESS_SUPPORT)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_LOUDNESS_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(BES_LIVE_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_LIVE_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_EQ_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
  endif
  COMPOBJS         += hal\audio\lib\VENDOR\tc01\oaep.a
  CUS_REL_OBJ_LIST += hal\audio\lib\VENDOR\tc01\oaep.a
  COM_DEFS += __TC01_OAEP_SUPPORT__
endif

ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  COM_DEFS += __R6_OOS__
endif

ifeq ($(filter BASIC L1S UDVT,$(strip $(call Upper,$(PROJECT)))),)
  ifndef LOW_COST_SUPPORT
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
endif

ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
  COMPLIST       += scsi
else
  ifeq ($(filter BASIC L1S UDVT,$(strip $(call Upper,$(PROJECT)))),)
    ifndef LOW_COST_SUPPORT
      COMPLIST       += scsi
    endif
    ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
      COMPLIST       += scsi
    endif
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      COMPLIST       += scsi
    endif
  endif
endif

ifdef TST_SET_LOG_BUF_SIZ
  ifneq ($(strip $(TST_SET_LOG_BUF_SIZ)),NONE)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS += FORCE_TST_RING_BUFFER_SCALE=$(strip $(TST_SET_LOG_BUF_SIZ))
    else
      $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_SET_LOG_BUF_SIZ)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef AT_COMMAND_SET
  ifeq ($(strip $(AT_COMMAND_SET)),SLIM)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__
  endif

  ifeq ($(strip $(AT_COMMAND_SET)),ULC)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__ __ULC_AT__
  endif
endif

ifeq ($(filter MS TC01 MTK MAC,$(strip $(USB_COMPORT_PC_DRIVER_SUPPORT))),)
  $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT must be defined as MS/TC01/MTK/MAC!)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),TC01)
  ifeq ($(filter __TC01__,$(COM_DEFS)),)
    $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT can not be TC01 when __TC01__ not defined!)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
  COM_DEFS    += __USB_COMPORT_SUPPORT_TC01_DRIVER__
  COM_DEFS    += __USB_BOOT_NOT_CHECK_NVRAM_SETTING__
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MAC)
  COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
  COM_DEFS    += __USB_COMPORT_SUPPORT_MAC_DRIVER__
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MTK)
  COM_DEFS    += __USB_COMPORT_SUPPORT_MTK_DRIVER__
endif

ifeq ($(strip $(CUST_CODE)),TC01)
  COM_DEFS += __ACOUSTIC_LOOPBACK_SUPPORT__
  COM_DEFS += __LATCH_POWER_IN_BOOTLOADER__
  COM_DEFS += __LATCH_POWER_IN_BOOTLOADER_TC01__
endif

ifeq ($(strip $(KEYPAD_DEBUG_TRACE)),TRUE)
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    $(warning ERROR: Smart Phone does not support KEYPAD_DEBUG_TRACE!)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __KEYPAD_DEBUG_TRACE__
endif



ifeq ($(strip $(PHB_SYNC)),ON)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_SYNC)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_SYNC__
endif

ifdef KAL_ASSERT_LEVEL
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL4)
    COM_DEFS += __KAL_ASSERT_LEVEL4__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL3)
    COM_DEFS += __KAL_ASSERT_LEVEL3__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL2)
    COM_DEFS += __KAL_ASSERT_LEVEL2__ __KAL_ASSERT_SHRINKING__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL1)
    COM_DEFS += __KAL_ASSERT_LEVEL1__ __KAL_ASSERT_SHRINKING__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL0)
    COM_DEFS += __KAL_ASSERT_LEVEL0__ __KAL_ASSERT_SHRINKING__
  endif
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifneq ($(filter __FS_CARD_SUPPORT__,$(COM_DEFS)),)
        ifeq ($(filter __SLIM_MMS__,$(COM_DEFS)),)
          COM_DEFS += __MMS_MEMORY_CARD_STORAGE_SUPPORT__
        endif
      endif
    endif
  endif
endif

ifneq ($(strip $(MELODY_VER)),NONE)
  COM_DEFS    += $(MELODY_VER)
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += __NEW_TBF_ARCH__
  COM_DEFS += __REMOVE_FA__
endif

ifeq ($(strip $(GAIN_TABLE_SUPPORT)),TRUE)
  COM_DEFS += __GAIN_TABLE_SUPPORT__
endif

ifdef CMMB_CAS_MBBMS_SUPPORT
  ifeq ($(strip $(CMMB_CAS_MBBMS_SUPPORT)),TRUE)
    ifeq ($(strip $(CMMB_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_MBBMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMMB_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_MBBMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SDP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,CMMB_CAS_MBBMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FONT_ENGINE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,FONT_ENGINE,CMMB_CAS_MBBMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __CMMB_CAS_MBBMS_SUPPORT__
    ifeq ($(strip $(MBBMS_VERSION)),3.0)
      COM_DEFS    += __MBBMS_V30__
    endif
  endif
endif

ifeq ($(strip $(MDP_LCD_FW_UPDATE)),TRUE)
  COM_DEFS    += __MDP_LCD_FW_UPDATE__
endif

COM_DEFS +=  __SW_MP4_LOSSY_SUPPORT__
COM_DEFS +=  __SW_H264_LOSSY_SUPPORT__

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),1000),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of USIM projects should not be larger than 1000)
    DEPENDENCY_CONFLICT = TRUE
  endif
else
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),254),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of non USIM projects should not be larger than 254)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __L1_STANDALONE__,$(COM_DEFS)),)
    COM_DEFS  +=  DRV_LCD_NOT_EXIST 
endif

ifdef MMI_BASE
  ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    ifneq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
      COM_DEFS    += __RICH_AUDIO_PROFILE__
    endif
  endif
endif

ifeq ($(strip $(ECC_RETRY_ENHANCEMENT)),TRUE)
  ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __UMTS_RAT__ defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __GSM_RAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __GSM_RAT__ defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ECC_RETRY_ENHANCEMENT__
endif

ifeq ($(strip $(WIFI_PREFER_SUPPORT)),TRUE)
  ifndef WIFI_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_PREFER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_PREFER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
    COM_DEFS            += __WIFI_PREFER__
  endif
endif

ifneq ($(filter PLUTO_MMI NEPTUNE_MMI IOT_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
  ifneq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
      ifneq ($(strip $(PACKAGE_SEG)), 16_3_SEG)
        $(warning ERROR: Please turn on USIM_SUPPORT in $(strip $(PLATFORM)) projects) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(HW_PFC_SUPPORT)),TRUE)
  COM_DEFS += __HW_PFC_SUPPORT__
endif

ifeq ($(strip $(L1L2_TX_NEW_ARCH)),TRUE)
  COM_DEFS  += __TX_NEW_ARCHITECTURE__
endif

# Copro dependency check is valid only for FDD mode and non l1s project
ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
ifeq ($(strip $(L2_HSDPA_COPRO)), TRUE)
  ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),6),T)
    $(warning ERROR: GPRS_MAX_PDP_SUPPORT maximum value is 6 when HSDPA Copro exist due to hardware limitation, please reduce GPRS_MAX_PDP_SUPPORT value)
    DEPENDENCY_CONFLICT = TRUE 
  endif
    COM_DEFS        += __RLC_HSDPA_COPRO__ __MAC_HSDPA_COPRO__
    COMP_TRACE_DEFS += $(strip $(UAS_FOLDER))\l2\seq\include\seq_trc.h
else
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,L2_HSDPA_COPRO,HSDPA_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(L2_HSUPA_COPRO)), TRUE)
  ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,L2_HSDPA_COPRO,L2_HSUPA_COPRO)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(HSUPA_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,HSUPA_SUPPORT,L2_HSUPA_COPRO)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(HSDPA_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,HSDPA_SUPPORT,L2_HSUPA_COPRO)
    DEPENDENCY_CONFLICT = TRUE
  endif
    COM_DEFS        += __L2_HSUPA_COPRO__
    COMP_TRACE_DEFS += $(strip $(UAS_FOLDER))\l2\seq\include\seq_trc.h
else
  ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,L2_HSUPA_COPRO,HSUPA_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif
endif

ifeq ($(strip $(TST_DNT_LOGGING)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_DNT_LOGGING)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __TST_DNT_LOGGING__ __TST_LMU_LOGGING__ __TST_DCC_ENABLED__
  endif
endif

ifneq ($(filter MT6256 MT6276,$(strip $(PLATFORM))),) 
  COM_DEFS += MT6276_55_HQA
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V01)
      $(call DEP_ERR_SETA_OR_OFFB,MMS_SUPPORT,OBIGO_Q03C_MMS_V02,MMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter UNICORN53%,$(BOARD_VER)),)
  COM_DEFS    +=  __PHONE__
else
  ifneq ($(filter MT6921%,$(BOARD_VER)),)
     COM_DEFS    +=  __EVB__
  else
    ifneq ($(filter %_EVB,$(BOARD_VER)),)
      COM_DEFS    +=  __EVB__
    else  
      COM_DEFS    +=  __PHONE__
    endif
  endif
endif

ifeq ($(strip $(DA_MEMORY_CUT_SUPPORT)),TRUE)
  ifndef TCPIP_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,DA_MEMORY_CUT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,DA_MEMORY_CUT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __DA_MEMORY_CUT__
endif

ifeq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),ON)
  COM_DEFS += __GDI_SCREEN_SHOT_BUFFER__
endif

ifneq ($(filter __TC01__,$(COM_DEFS)),)
  ifneq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),ON) 
    $(warning ERROR: Please turn on GDI_SCREEN_SHOT_BUFFER when __TC01__  defined!)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __OP11_ATK__,$(OPTR_DEFS)),)
  ifneq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),ON) 
    $(warning ERROR: Please turn on GDI_SCREEN_SHOT_BUFFER when __OP11_ATK__  defined!)
    DEPENDENCY_CONFLICT = TRUE
  endif   
endif

#ifeq ($(strip $(NMC_SUPPORT)), TRUE)
#  COM_DEFS         += __NMC_SUPPORT__
#  COMP_TRACE_DEFS  += vendor\nmc\adaption\inc\nmc_trc.h
#  COMPOBJS         += vendor\nmc\corelib\target\nmccore.lib
#  COMPLIST         += nmc
#endif

ifdef AOC_SUPPORT
  ifeq ($(strip $(AOC_SUPPORT)),TRUE)
     COM_DEFS    += __AOC_SUPPORT__
  endif   
endif

ifeq ($(strip $(SML_SUPPORT)),TRUE)
  COM_DEFS += __SIM_ME_LOCK__
endif

ifdef VCARD_SUPPORT
  ifneq ($(strip $(VCARD_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non NEPTUNE_MMI,VCARD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(VCARD_SUPPORT)),SINGLE)
    COM_DEFS    += __VCARD_SUPPORT__
    COMPLIST    += vcard
    COMMINCDIRS += vcard\include
  endif
  ifeq ($(strip $(VCARD_SUPPORT)),MULTIPLE)
    COM_DEFS    += __VCARD_SUPPORT__ __MULTI_VCARD_SUPPORT__
    COMPLIST    += vcard udx
    COMMINCDIRS += vcard\include
  endif
endif 

ifeq ($(strip $(PHB_ADDITIONAL_SUPPORT)),TRUE)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_ADDITIONAL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_ADDITIONAL_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6573)
  COM_DEFS += __CSMCC_REJWAIT_CALL__
endif

ifdef ATV_SMS_SUPPORT
  ifeq ($(strip $(ATV_SMS_SUPPORT)),TRUE)
    ifneq ($(strip $(ATV_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_SMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_SMS_SUPPORT__
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    $(warning ERROR: BROWSER_SUPPORT = OBIGO_Q05A is not support when MMI_VERSION = COSMOS_MMI.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BT_AUTO_DETECT_SUPPORT
  ifeq ($(strip $(BT_AUTO_DETECT_SUPPORT)),TRUE)
    COM_DEFS    += __BT_AUTO_DETECT_SUPPORT__
  endif
endif

ifdef DUAL_MEMORY_CARD_SUPPORT
  ifneq ($(strip $(DUAL_MEMORY_CARD_SUPPORT)),NONE)
    ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,MSDC_CARD_SUPPORT_TYPE,DUAL_MEMORY_CARD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __FS_CARD2_SUPPORT__
      ifeq ($(strip $(DUAL_MEMORY_CARD_SUPPORT)),SWITCH)
        COM_DEFS += __MSDC_DUAL_CARD_SWITCH__
      endif
      ifeq ($(strip $(DUAL_MEMORY_CARD_SUPPORT)),DUAL_MSDC)
        COM_DEFS += __MSDC_DUAL_CARD_DUAL__
      endif
    endif
  endif
endif

#ifeq ($(filter __GEMINI_PREEMPT_PEER_SERVICE__ ,$(CUSTOM_OPTION)),)
#  ifdef GEMINI
#    ifneq ($(strip $(GEMINI)),FALSE)
#      ifneq ($(strip $(call Upper,$(PROJECT))),GSM)
#        ifneq ($(strip $(L1_WCDMA)),TRUE)
#          COM_DEFS  += __GEMINI_PREEMPT_PEER_SERVICE__
#        endif
#      endif
#    endif
#  endif
#else
#  ifeq ($(strip $(GEMINI)),FALSE)
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It isn't GEMINI project!)
#  endif
#  ifndef GEMINI
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It isn't GEMINI project!)
#  endif
#  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It's GSM project!)
#  endif
#  ifeq ($(strip $(L1_WCDMA)),TRUE)
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It's 3G project!)
#  endif
#endif

ifdef CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION
  ifeq ($(strip $(CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION)),TRUE)
    CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION_SUPPORT_PLATFORM = MT6253T MT6253
    ifeq ($(filter $(strip $(PLATFORM)),$(CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __CLASSAB_VOLUME_PROTECTION__
  endif
endif

IS_MT6276M_PROJECT = FALSE
ifeq ($(strip $(PLATFORM)),MT6276)
  ifdef MODEM_CARD
    ifneq ($(strip $(MODEM_CARD)),NONE)
      IS_MT6276M_PROJECT = TRUE
    endif
  endif
endif

ifdef MTK_SLEEP_ENABLE
  ifeq ($(strip $(MTK_SLEEP_ENABLE)),TRUE)
    COM_DEFS    += MTK_SLEEP_ENABLE
  else
    ifneq ($(strip $(DEMO_PROJECT)),TRUE)
      ifneq ($(strip $(IS_MT6276M_PROJECT)),TRUE)
        $(warning ERROR: MTK_SLEEP_ENABLE must be TRUE in all customer projects except MT6276M projects.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(AUDIO_CLIPPER_SUPPORT)),TRUE)
  COM_DEFS    += __AUDIO_TRIM_SUPPORT__
endif

ifneq ($(filter ARM7EJ-S, $(strip $(CFLAGS))),)
  COM_DEFS += __CPU_ARM7EJ_S__
endif
ifneq ($(filter ARM9EJ-S, $(strip $(CFLAGS))),)
  COM_DEFS += __CPU_ARM9EJ_S__
endif
ifneq ($(filter ARM7TDMI, $(strip $(CFLAGS))),)
  COM_DEFS += __CPU_ARM7TDMI__
endif
ifneq ($(filter ARM1176JZ-S, $(strip $(CFLAGS))),)
  COM_DEFS += __CPU_ARM1176JZ_S__
endif

ifdef GEMINI
  ifeq ($(strip $(GEMINI_VERSION)),V2)
    ifeq ($(strip $(GEMINI)),3)
      $(warning ERROR: Please set GEMINI_VERSION as V1 when GEMINI = 3!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(GEMINI)),4)
      $(warning ERROR: Please set GEMINI_VERSION as V1 when GEMINI = 4!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    ifeq ($(strip $(FAST_DORMANCY_SUPPORT)),TRUE)
      COM_DEFS     += __FAST_DORMANCY__
    endif
    ifeq ($(strip $(FAST_DORMANCY_SUPPORT)),FALSE)
      COM_DEFS     += __NO_PSDATA_SEND_SCRI__
    endif
  endif
endif

ifeq ($(strip $(MOBILE_VIDEO_SUPPORT)),WONDER)
  ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
    $(warning ERROR: Please turn on STREAM_SUPPORT when MOBILE_VIDEO_SUPPORT  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(RTSP_SUPPORT)),TRUE)
    $(warning ERROR: Please turn on RTSP_SUPPORT when MOBILE_VIDEO_SUPPORT  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(PGDL_SUPPORT)),TRUE)
    $(warning ERROR: Please turn on PGDL_SUPPORT when MOBILE_VIDEO_SUPPORT  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(findstring CMCC,$(strip $(OPTR_SPEC))),) 
    $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,MOBILE_VIDEO_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS         += __MOBILE_VIDEO_SUPPORT__
  COMMINCDIRS      += vendor\mobilevideo\adaption\mobilevideoinc
  COMPOBJS         += vendor\mobilevideo\corelib\target\dresden.lib
  COMPOBJS         += vendor\mobilevideo\corelib\target\rmeapp.lib
  COMPLIST         += mobilevideo
  CUS_REL_OBJ_LIST += vendor\mobilevideo\corelib\target\dresden.lib
  CUS_REL_OBJ_LIST += vendor\mobilevideo\corelib\target\rmeapp.lib
  CUS_REL_BASE_COMP   +=  vendor\mobilevideo
endif

ifdef LCM_SCANLINE_ROTATION_SUPPORT
  ifeq ($(strip $(LCM_SCANLINE_ROTATION_SUPPORT)),TRUE)
    ifeq ($(strip $(MAIN_LCM_SCANLINE_ROTATION)),TRUE)
      ifeq ($(strip $(MAIN_LCM_SCANLINE_ROTATION_CCW_ANGLE)),90)
        COM_DEFS += __MAIN_LCM_SCANLINE_ROTATION_90__
      endif
      ifeq ($(strip $(MAIN_LCM_SCANLINE_ROTATION_CCW_ANGLE)),270)
        COM_DEFS += __MAIN_LCM_SCANLINE_ROTATION_270__
      endif
      ifeq ($(strip $(MAIN_LCM_SCANLINE_ROTATION_CCW_ANGLE)),0)
        COM_DEFS += __MAIN_LCM_SCANLINE_ROTATION_0__
      endif
      ifeq ($(strip $(MAIN_LCM_SCANLINE_ROTATION_CCW_ANGLE)),180)
        COM_DEFS += __MAIN_LCM_SCANLINE_ROTATION_0__
      endif
    else
      COM_DEFS += __MAIN_LCM_SCANLINE_ROTATION_0__
    endif
    ifeq ($(strip $(SUB_LCM_SCANLINE_ROTATION)),TRUE)
      ifeq ($(strip $(SUB_LCM_SCANLINE_ROTATION_CCW_ANGLE)),90)
        COM_DEFS += __SUB_LCM_SCANLINE_ROTATION_90__
      endif
      ifeq ($(strip $(SUB_LCM_SCANLINE_ROTATION_CCW_ANGLE)),270)
        COM_DEFS += __SUB_LCM_SCANLINE_ROTATION_270__
      endif
      ifeq ($(strip $(SUB_LCM_SCANLINE_ROTATION_CCW_ANGLE)),0)
        COM_DEFS += __SUB_LCM_SCANLINE_ROTATION_0__
      endif
      ifeq ($(strip $(SUB_LCM_SCANLINE_ROTATION_CCW_ANGLE)),180)
        COM_DEFS += __SUB_LCM_SCANLINE_ROTATION_0__
      endif
    else
      COM_DEFS += __SUB_LCM_SCANLINE_ROTATION_0__
    endif
  else
    COM_DEFS += __MAIN_LCM_SCANLINE_ROTATION_0__
    COM_DEFS += __SUB_LCM_SCANLINE_ROTATION_0__
  endif
endif

ifdef LCM_SCANLINE_ROTATION_SUPPORT
  ifeq ($(strip $(LCM_SCANLINE_ROTATION_SUPPORT)),TRUE)
    ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
      $(warning ERROR: HORIZONTAL_CAMERA does not support LCM_SCANLINE_ROTATION_SUPPORT.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __LCM_SCANLINE_ROTATION_SUPPORT__
  endif
endif

ifeq ($(filter __TC02__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ can only be turned on for MOTO project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SML_SUPPORT
  ifneq ($(strip $(SML_SUPPORT)),TRUE)
    ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ need set SML_SUPPORT = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)  
    ifdef DRM_SECURE_CLOCK
      ifeq ($(strip $(DRM_SECURE_CLOCK)),TRUE)
       COM_DEFS += __DRM_SEC_CLK_NITZ__
      endif
    endif
  endif
endif

ifdef MAUI_SDK_TEST
  ifeq ($(strip $(MAUI_SDK_TEST)),TRUE)
    ifneq ($(strip $(DEMO_PROJECT)),TRUE)
      $(warning ERROR: MAUI_SDK_TEST can not be set to TRUE in customer project.)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __MAUI_SDK_TEST__
      COMPLIST         += sdk_test
    endif
  endif
endif

ifeq ($(strip $(HOTSPOT_SUPPORT)),TRUE)
  ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,HOTSPOT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif    
  ifndef WIFI_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,HOTSPOT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,HOTSPOT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(DHCPD_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DHCPD_SUPPORT,HOTSPOT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __HOTSPOT_SUPPORT__
  ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
    COMPLIST    += hostap
  endif
  COMP_TRACE_DEFS += wifi\hostap\inc\hostap_trc.h
endif

ifdef HOTSPOT_SUPPORT
  ifeq ($(strip $(HOTSPOT_SUPPORT)),TRUE)
    ifdef HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
      ifdef ($(strip $(HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,HOTSPOT_SUPPORT,HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(HOTSPOT_SUPPORT_PERFORMANCE_BENCHMARK)),TRUE)
  ifneq ($(strip $(HOTSPOT_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,HOTSPOT_SUPPORT,HOTSPOT_SUPPORT_PERFORMANCE_BENCHMARK)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __HOTSPOT_SUPPORT_PERFORMANCE_BENCHMARK__
endif

ifeq ($(strip $(DHCPD_SUPPORT)),TRUE)
  ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,HOTSPOT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __DHCP_SRV_SUPPORT__
  COMP_TRACE_DEFS += inet_ps\dhcpd\include\dhcpd_trc.h
  COMPLIST    += dhcpd
endif

ifdef USB_TETHERING
  ifeq ($(strip $(USB_TETHERING)),TRUE)
    ifneq ($(strip $(DHCPD_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DHCPD_SUPPORT,USB_TETHERING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(NDIS_SUPPORT)),UPS)
      $(call DEP_ERR_ONA_OR_OFFB,USB_TETHERING,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    ifeq ($(strip $(USB_HIGH_SPEED_COM_PORT_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_HIGH_SPEED_COM_PORT_SUPPORT,USB_TETHERING)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    += __USB_TETHERING__ __UPS_SUPPORT__
    COMPLIST    += ups
    COMP_TRACE_DEFS  += $(strip $(PS_FOLDER))\ups\include\rndis_trc.h
    COMP_TRACE_DEFS  += $(strip $(PS_FOLDER))\cmux\include\rndis_ctrl_trc.h
    ifeq ($(filter cmux,$(COMPLIST)),)
      COMPLIST    += cmux
    endif
  endif
endif

ifeq ($(strip $(SUBLCD_SYNC_LCM_METHOD)),HW)
  COM_DEFS    += __SUBLCD_SYNC_LCM_HW_SUPPORT__ __SUBLCD_SYNC_LCM_SUPPORT__
else
  ifeq ($(strip $(SUBLCD_SYNC_LCM_METHOD)),SW)
    COM_DEFS    += __SUBLCD_SYNC_LCM_SW_SUPPORT__ __SUBLCD_SYNC_LCM_SUPPORT__
  endif
endif

ifdef MODIS_FDM
  ifeq ($(strip $(MODIS_FDM)),ON)
    COM_DEFS   += __FS_MODIS_FDM__ 
  endif
endif

COM_DEFS += __MP4_DEC_ASP_PARTIAL_SUPPORT__

ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X480)
  ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    $(call DEP_ERR_SETA_OR_SETB,FINGER_TOUCH_SUPPORT,FTE,MAIN_LCD_SIZE,non 320X480)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
      COM_DEFS    +=  __BT_SLIM_ROM__
      COM_DEFS    +=  __BT_SLIM_RAM__
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifndef CAMCORDER_SUPPORT
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non COSMOS_MMI,CAMCORDER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non COSMOS_MMI,CAMCORDER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    $(warning ERROR: PLEASE set FINGER_TOUCH_SUPPORT = FTE when MMI_VERSION = COSMOS_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef COSMOS_3D_VERSION
  ifneq ($(strip $(COSMOS_3D_VERSION)),NONE)
    ifeq ($(filter __VENUS_3D_UI_ENGINE__,$(strip $(COM_DEFS))),)
      $(call DEP_ERR_SETA_OR_OFFB,VENUS_MMI,VENUS_3D,COSMOS_3D_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      ifeq ($(strip $(COSMOS_3D_VERSION)),V10)
        COM_DEFS += __COSMOS_3D_V10__
      endif
    endif
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifeq ($(strip $(COSMOS_3D_VERSION)),V10)
        COM_DEFS += __PLUTO_3D_V10__
      endif
    endif
  endif
endif

ifdef ZIMAGE_SUPPORT
  ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
    COM_DEFS   +=  __ZIMAGE_SUPPORT__
    COM_DEFS   +=  __VI_ENABLED__
  endif
endif

#ZIMAGE_SUPPORT must be enabled on MT6250 and MT6260 except NAND_FLASH_BOOTING and EMMC_BOOTING
ZIMAGE_MUST_ENABLE_PLATFORM = MT6250 MT6260 MT6261 MT2501 MT2502
ZIMAGE_MUST_ENABLE_EXCEPTION = FALSE
ifdef INSIDE_MTK
  ifeq ($(strip $(INSIDE_MTK)),1)
    ZIMAGE_MUST_ENABLE_EXCEPTION = TRUE
  endif
endif
ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ZIMAGE_MUST_ENABLE_EXCEPTION = TRUE
  endif
endif
ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    ZIMAGE_MUST_ENABLE_EXCEPTION = TRUE
  endif
endif

ifneq ($(filter MT6236% MT6252% MT6921 MT6256 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502,$(PLATFORM)),)
  COM_DEFS     +=  __BOOT_FOR_USBAT__
endif

ifneq ($(filter MT6252H MT6252,$(PLATFORM)),)
  COM_DEFS     +=  __A2DP_BLOCK_SPECTRUM__
endif

ifneq ($(filter __L4_INIT_MULTIUSB_COM__,$(COM_DEFS)),)
  ifeq ($(filter __USB_MULTIPLE_COMPORT_SUPPORT__,$(COM_DEFS)),)
    $(warning ERROR: __L4_INIT_MULTIUSB_COM__ can only be defined when __USB_MULTIPLE_COMPORT_SUPPORT__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifndef PHB_FDN_ENTRY
     PHB_FDN_ENTRY = 32
endif

ifdef PHB_FDN_ENTRY
     COM_DEFS    += MAX_PHB_FDN_ENTRY=$(strip $(PHB_FDN_ENTRY))
endif

ifdef COMBO_MEMORY_SUPPORT
  ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
    COM_DEFS    += __COMBO_MEMORY_SUPPORT__
  endif
endif

2G_TX_POWER_CONTROL_SUPPORT_PLATFORM = MT6276 MT6573 MT6575 MT6256
ifneq ($(filter $(2G_TX_POWER_CONTROL_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __2G_TX_POWER_CONTROL_SUPPORT__
endif

CACHE_BASED_DSP_SUPPORT_PLATFORM = MT6256
ifneq ($(filter $(CACHE_BASED_DSP_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  ifeq ($(strip $(PLATFORM)),MT6256)
    ifeq ($(strip $(CHIP_VER)),S00)
    else
      COM_DEFS    +=  __CACHED_BASE_DSP__
    endif
  else
    COM_DEFS    +=  __CACHED_BASE_DSP__
  endif
endif

ifdef INTERGRAFX_SUPPORT
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_EN_BASIC)
    COM_DEFS  += INTERGRAFX_ENGINE_BASIC INTERGRAFX_ENGINE_EN_BASIC
  endif
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_CH_BASIC)
    COM_DEFS  += INTERGRAFX_ENGINE_BASIC INTERGRAFX_ENGINE_CH_BASIC
  endif
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_EN_VALUED)
    COM_DEFS  += INTERGRAFX_ENGINE_VALUED INTERGRAFX_ENGINE_EN_VALUED
  endif
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_CH_VALUED)
    COM_DEFS  += INTERGRAFX_ENGINE_VALUED INTERGRAFX_ENGINE_CH_VALUED
  endif
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_EN_FULL)
    COM_DEFS  += INTERGRAFX_ENGINE_FULL INTERGRAFX_ENGINE_EN_FULL
  endif
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_CH_FULL)
    COM_DEFS  += INTERGRAFX_ENGINE_FULL INTERGRAFX_ENGINE_CH_FULL
  endif

  ifneq ($(strip $(INTERGRAFX_SUPPORT)),NONE)
    MAIN_LCD_SIZE_VALID_RANGE = 240X240 240X320 240X400 320X480 480X800
    ifeq ($(filter  $(MAIN_LCD_SIZE),$(MAIN_LCD_SIZE_VALID_RANGE)),)
      $(call DEP_ERR_SETA_OR_OFFB,MAIN_LCD_SIZE,$(MAIN_LCD_SIZE_VALID_RANGE),INTERGRAFX_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifneq ($(strip $(INTERGRAFX_SUPPORT)),NONE)
    ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
      COMPOBJS  += vendor\intergrafx_hw\Engine\IGV5Lib\RVCT\IGV5.a
      CUS_REL_OBJ_LIST += vendor\intergrafx_hw\Engine\IGV5Lib\RVCT\IGV5.a
      COMPLIST += intergrafx_hw
    else
      COMPOBJS  += vendor\intergrafx\Engine\IGV3Lib\RVCT\IGV3.a
      CUS_REL_OBJ_LIST += vendor\intergrafx\Engine\IGV3Lib\RVCT\IGV3.a
      COMPLIST += intergrafx_sw
    endif
  endif

  FT_EN_SUPPORT_VALUE = INTERGRAFX_ENGINE_EN_BASIC INTERGRAFX_ENGINE_EN_VALUED INTERGRAFX_ENGINE_EN_FULL
  DA_EN_SUPPORT_VALUE = INTERGRAFX_ENGINE_EN_VALUED INTERGRAFX_ENGINE_EN_FULL
  TF_EN_SUPPORT_VALUE = INTERGRAFX_ENGINE_EN_BASIC INTERGRAFX_ENGINE_EN_VALUED INTERGRAFX_ENGINE_EN_FULL
  JE_EN_SUPPORT_VALUE = INTERGRAFX_ENGINE_EN_BASIC INTERGRAFX_ENGINE_EN_VALUED INTERGRAFX_ENGINE_EN_FULL
  CW_EN_SUPPORT_VALUE = INTERGRAFX_ENGINE_EN_BASIC INTERGRAFX_ENGINE_EN_VALUED INTERGRAFX_ENGINE_EN_FULL

  FT_CH_SUPPORT_VALUE = INTERGRAFX_ENGINE_CH_BASIC INTERGRAFX_ENGINE_CH_VALUED INTERGRAFX_ENGINE_CH_FULL
  DA_CH_SUPPORT_VALUE = INTERGRAFX_ENGINE_CH_VALUED INTERGRAFX_ENGINE_CH_FULL
  TF_CH_SUPPORT_VALUE = INTERGRAFX_ENGINE_CH_BASIC INTERGRAFX_ENGINE_CH_VALUED INTERGRAFX_ENGINE_CH_FULL
  JE_CH_SUPPORT_VALUE = INTERGRAFX_ENGINE_CH_BASIC INTERGRAFX_ENGINE_CH_VALUED INTERGRAFX_ENGINE_CH_FULL
  CW_CH_SUPPORT_VALUE = INTERGRAFX_ENGINE_CH_BASIC INTERGRAFX_ENGINE_CH_VALUED INTERGRAFX_ENGINE_CH_FULL

  MAIN_LCD_SUPPORT_SIZE = 240X240 240X320 240X400 320X480 480X800

  ifneq ($(filter $(FT_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).lib
      COMPOBJS  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).obj
      CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).obj
    endif
  endif

  ifneq ($(filter $(FT_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).lib
      COMPOBJS  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).obj
      CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).obj
    endif
  endif

  ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
    ifneq ($(filter $(DA_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
      endif
    endif

    ifneq ($(filter $(DA_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
      endif
    endif
  else
    ifneq ($(filter $(DA_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        COMPOBJS  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
        COMPOBJS  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).obj
        CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).obj
      endif
    endif

    ifneq ($(filter $(DA_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        COMPOBJS  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
        COMPOBJS  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).obj
        CUS_REL_OBJ_LIST  += vendor\intergrafx\Game\RVCT\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).obj
      endif
    endif
  endif
  
  ifneq ($(filter $(JE_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\JumpEmperor\IG_JE_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\JumpEmperor\IG_JE_EN_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif

  ifneq ($(filter $(JE_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\JumpEmperor\IG_JE_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\JumpEmperor\IG_JE_CH_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif

  ifneq ($(filter $(CW_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\CubeWorld\IG_CW_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\CubeWorld\IG_CW_EN_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif

  ifneq ($(filter $(CW_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\CubeWorld\IG_CW_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\CubeWorld\IG_CW_CH_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(TF_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\TankFantasy\IG_TF_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\TankFantasy\IG_TF_EN_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(TF_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      COMPOBJS  += vendor\intergrafx_hw\Game\RVCT\TankFantasy\IG_TF_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_OBJ_LIST  += vendor\intergrafx_hw\Game\RVCT\TankFantasy\IG_TF_CH_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
endif

# EMI latency setting, MPLLDISABLED, MPLLXHALF, MPLLX1, MPLLX2, MPLLX3, MPLLX4
MPLL_SETTING_FOR_MT6205_EXT_13M_MCU_13M   = MPLLDISABLED

MPLL_SETTING_FOR_MT6205B_EXT_13M_MCU_13M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_13M  = MPLLXHALF
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_26M  = MPLLDISABLED

MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_52M   = MPLLX4

MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_26M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_52M   = MPLLX2

MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_122_88M = MPLLX4

MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_122_88M = MPLLX4

MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6921_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6921_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6921_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6921_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6921_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6921_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6921_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6921_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253E_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253E_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253E_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253L_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253L_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253L_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6252H_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6252H_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6252H_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6252_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6252_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6252_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR =  MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK))
ifdef $(MPLL_SETTING_FOR)
  MPLL_SETTING      =  $(MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK)))
else
  ifeq ($(strip $(PLATFORM)),MT6208)
    $(warning ERROR: MCU Clock and External Clock setting cannot be supported.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

COM_DEFS    += $(MCU_CLOCK) $(EXT_CLOCK) $(MPLL_SETTING)

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
   COM_DEFS    += DCM_ENABLE
endif

ifdef HAND_WRITING
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
        $(warning ERROR: For customer project, please set HAND_WRITING = MMI_HANWANG_DEMO, not set HAND_WRITING = MMI_HANWANG)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
        $(warning ERROR: For customer project, please set HAND_WRITING = MMI_PENPOWER_DEMO, not set HAND_WRITING = MMI_PENPOWER)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
        $(warning ERROR: For customer project, please set HAND_WRITING = MMI_DECUMA_DEMO, not set HAND_WRITING = MMI_DECUMA)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(strip $(HAND_WRITING)),NONE)
    ifndef TOUCH_PANEL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,HAND_WRITING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,HAND_WRITING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
    COM_DEFS    += __MMI_HANWANG__
    COMPLIST    += hanwang
    ifeq ($(strip $(COMPILER)),RVCT)
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw_slim.a
        else
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
        endif
      else      
        COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
      endif
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.lib
    else
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
          COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw_sc.a
        else
          COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
        endif
      else
        COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
      endif

      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a \
                     vendor\handwriting\hanwang\v1_official\lib\thaihw.a
                   
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.a \
                             vendor\handwriting\hanwang\v1_official\lib\hw.lib \
                             vendor\handwriting\hanwang\v1_official\lib\hw_sc.a \
                             vendor\handwriting\hanwang\v1_official\lib\hw_sc.lib \
                             vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a \
                             vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.lib \
                             vendor\handwriting\hanwang\v1_official\lib\thaihw.a \
                             vendor\handwriting\hanwang\v1_official\lib\thaihw.lib \
                             vendor\handwriting\hanwang\v1_official\lib\hws.lib
    endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.dll
    COMMINCDIRS  += vendor\handwriting\hanwang\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_SLIM)
    COM_DEFS    += __MMI_HANWANG__ __MMI_HANWANG_SLIM__
    COMPLIST    += hanwang
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw_slim.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.lib
    else
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
          COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw_sc.a
        else
          COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
        endif
      else
        COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
      endif

      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a \
                     vendor\handwriting\hanwang\v1_official\lib\thaihw.a
                   
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.a \
                             vendor\handwriting\hanwang\v1_official\lib\hw.lib \
                             vendor\handwriting\hanwang\v1_official\lib\hw_sc.a \
                             vendor\handwriting\hanwang\v1_official\lib\hw_sc.lib \
                             vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a \
                             vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.lib \
                             vendor\handwriting\hanwang\v1_official\lib\thaihw.a \
                             vendor\handwriting\hanwang\v1_official\lib\thaihw.lib \
                             vendor\handwriting\hanwang\v1_official\lib\hws.lib
    endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.dll
    COMMINCDIRS  += vendor\handwriting\hanwang\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO_SLIM)
    COM_DEFS    += __MMI_HANWANG__ __MMI_HANWANG_DEMO__ __MMI_HANWANG_SLIM__
    COMPLIST    += hanwang
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw_slim.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.lib
    else
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
    endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.dll
    COMMINCDIRS  += vendor\handwriting\hanwang\v1_demo\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO)
    COM_DEFS    += __MMI_HANWANG__ __MMI_HANWANG_DEMO__
    COMPLIST    += hanwang
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.lib
    else
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.lib
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
    endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.dll
    COMMINCDIRS  += vendor\handwriting\hanwang\v1_demo\inc
  endif
  ifneq ($(filter MMI_GUOBI_HW_%,$(HAND_WRITING)),)  
    ifndef GUOBI_WINGUO_SUPPORT
      $(warning ERROR: HAND_WRITING: MMI_GUOBI_HW_SC_SLIM\MMI_GUOBI_HW_STANDARD can only enable with Winguo search. Please change HAND_WRITING value or GUOBI_WINGUO_SUPPORT should not be NONE) 
      DEPENDENCY_CONFLICT = TRUE
    endif  
  endif  
  ifeq ($(strip $(HAND_WRITING)),MMI_GUOBI_HW_SC_SLIM)
    COM_DEFS    += __MMI_GUOBI_HW__ __MMI_GUOBI_HW_SC_SLIM__
    COMPLIST    += guobihw
    COMPOBJS    += vendor\handwriting\guobi\v1\lib\guobi_hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\guobi\v1\lib\guobi_hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\guobi\v1\lib\guobi_hw.lib
    CUS_REL_FILES_LIST  += vendor\handwriting\guobi\v1\inc\hw_edit_sc_slim.h
    COMMINCDIRS  += vendor\handwriting\guobi\v1\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_GUOBI_HW_STANDARD)
    COM_DEFS    += __MMI_GUOBI_HW__ __MMI_GUOBI_HW_STANDARD__
    COMPLIST    += guobihw
    COMPOBJS    += vendor\handwriting\guobi\v1\lib\guobi_hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\guobi\v1\lib\guobi_hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\guobi\v1\lib\guobi_hw.lib
    CUS_REL_FILES_LIST  += vendor\handwriting\guobi\v1\inc\hw_edit_sc_tc_full.h
    COMMINCDIRS  += vendor\handwriting\guobi\v1\inc
  endif
  
  ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
    COM_DEFS    += __MMI_PENPOWER__
    COMPLIST    += penpower

    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7, $(findstring ARM7, $(strip $(CFLAGS))))
        COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM7.a
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM7.a
      else
        ifeq (ARM9, $(findstring ARM9, $(strip $(CFLAGS))))
          COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM9.a
          CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM9.a
        endif
      endif
    else
      COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
      CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
    endif
    
    COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MediaTek_HWRE.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhrase_WIN.lib
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_data_big5gb2312_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_big5tw_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_gb2312_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_russian_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_thai_vc6.h
    COMMINCDIRS  += vendor\handwriting\penpower\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
    COM_DEFS    += __MMI_DECUMA__
    COMPLIST    += decuma
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ, $(findstring ARM7EJ, $(strip $(CFLAGS))))
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
        COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
        CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
      else 
        ifeq (ARM9EJ, $(findstring ARM9EJ, $(strip $(CFLAGS))))
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
          COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
          CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
        else
          ifeq (ARM1176JZ, $(findstring ARM1176JZ, $(strip $(CFLAGS))))
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm11.a
            COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm11.a
            CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm11.a
          endif
        endif
      endif
    else
      COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
      COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
      COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict.a
    endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_MODIS.lib
    COMMINCDIRS  += vendor\handwriting\Zi_decuma\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA_DEMO)
    COM_DEFS += __NO_HANDWRITING__
    CUS_REL_BASE_COMP += vendor\handwriting\Zi_decuma\adaptation
  endif
  ifdef TOUCH_PANEL_SUPPORT
    ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER_DEMO)
        COM_DEFS    += __MMI_PENPOWER__ __MMI_PENPOWER_DEMO__
        COMPLIST         += penpower
        ifeq ($(strip $(COMPILER)),RVCT)
          ifeq (ARM7EJ, $(findstring ARM7EJ, $(strip $(CFLAGS))))
            COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM7_evaluation.a
            CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM7_evaluation.a
          else
            ifeq (ARM9EJ, $(findstring ARM9EJ, $(strip $(CFLAGS))))
              COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM9_evaluation.a
              CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM9_evaluation.a
            else
              ifeq (ARM1176JZ, $(findstring ARM1176JZ, $(strip $(CFLAGS))))
                COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM11_evaluation.a
                CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM11_evaluation.a
              endif
            endif
          endif
        else
          COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
          CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
        endif
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\MediaTek_Hwre_demo.lib
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_data_big5gb2312_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_big5tw_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_gb2312_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_russian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_thai_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_portugese_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_italian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_hungarian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_finnish_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_dutch_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_danish_norwegian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_spanish_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_german_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_french_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_czech_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_croatian.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_romanian.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_slovak.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_slovene.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_swedish.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_bulgarian_vc6.h
        COMMINCDIRS  += vendor\handwriting\penpower\v1_demo\inc
      endif
    endif
  endif
endif

ifdef HAND_WRITING
  ifneq ($(strip $(HAND_WRITING)),NONE)
    CUS_REL_BASE_COMP += make\hanwang \
                         make\penpower \
                         make\decuma
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
        CUS_REL_BASE_COMP += vendor\handwriting\hanwang \
                             vendor\handwriting\penpower \
                             vendor\handwriting\zi_decuma
      endif
    endif
  endif
  # Release demo folder to customer always.
  CUS_REL_BASE_COMP += vendor\handwriting\hanwang\v1_demo \
                       vendor\handwriting\penpower\v1_demo
endif

ifneq ($(filter __MMS_STANDALONE_COMPOSER_SUPPORT__,$(COM_DEFS)),)
  COMMINCDIRS  +=  plutommi\MMI\UnifiedComposer\UnifiedComposerInc 
endif

ifdef SW_FLASH
  ifeq ($(strip $(COMPILER)),ADS)
    ifeq ($(strip $(SW_FLASH)),NEOMTEL)
      COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
      COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\zddlib_mtk-ADS.a
      COMMINCDIRS         += vendor\swflash\$(strip $(SW_FLASH))\adaptation\inc
      COM_DEFS         += SWFLASH_$(strip $(SW_FLASH))
      COMPLIST         += swflash
    endif
    # always release sw flash libraries to customers except vendors
    ifeq ($(strip $(call Upper,$(VENDOR))),NONE)
      ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
        CUS_REL_OBJ_LIST   += vendor\swflash\neomtel\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
        CUS_REL_OBJ_LIST   += vendor\swflash\neomtel\v1_official\VIS20_ARM12_MTK.a
        CUS_REL_OBJ_LIST   += vendor\swflash\neomtel\v1_official\VIS20_WIN32_MTK.lib
        CUS_REL_OBJ_LIST   += vendor\swflash\neomtel\v1_official\zddlib_mtk-ADS.a
        CUS_REL_OBJ_LIST   += vendor\swflash\neomtel\v1_official\zdd2_1_lib.lib
        CUS_REL_BASE_COMP  += vendor\swflash\neomtel\adaptation make\swflash
      endif
    endif
  endif
endif

COMPLIST += che sst_sec
ifdef FUNET_ENABLE
  ifneq ($(strip $(FUNET_ENABLE)),NONE)
    COMPLIST += fdm_bl gfx_core32 sys_sec
  endif
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COMPLIST += dsp_ram
endif

COMPLIST    += drv_display drv_sec drv_idp drv mc

ifneq ($(strip $(SSS_SUPPORT)),SSS_LIB)
  ifneq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
    $(warning ERROR: Please define SSS_SUPPORT as SSS_LIB or SSS_SOURCE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
     COMPLIST         += sss
  endif
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6616)
  COM_DEFS    +=  __WMT_SUPPORT__
  COMPLIST          += wmt
  COMP_TRACE_DEFS   += wmt\inc\wmt_trc.h
else
  ifeq ($(strip $(WIFI_BT_SINGLE_ANTENNA_SUPPORT)),TRUE)
    COM_DEFS    +=  __WMT_SUPPORT__
    COMPLIST          += wmt
    COMP_TRACE_DEFS   += wmt\inc\wmt_trc.h
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    COMPLIST += btdrv btdrv_common btadp btprofiles btstack
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
      COMPLIST += wndrv
      COMPLIST += dhcp
      COMPLIST += supc
    endif

    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      ifeq ($(strip $(MWL_SUPPORT)),SOURCE)
        ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
          COMPLIST += MT5921_wapi
        else
          COMPLIST += MT5921
        endif
      else
        ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
          COMPOBJS          += wifi\lib\MT5921\MT5921_wapi.lib
          CUS_REL_OBJ_LIST  += wifi\lib\MT5921\MT5921_wapi.lib
        else
          COMPOBJS          += wifi\lib\MT5921\MT5921.lib
          CUS_REL_OBJ_LIST  += wifi\lib\MT5921\MT5921.lib
        endif
      endif
    endif

  endif
endif

ifeq ($(strip $(WIFI_SUPPORT)),MT5931)
  COM_DEFS += MT5931
  ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
    COMPLIST += MT5931
#  CUS_REL_MTK_COMP += MT5931
    COMPOBJS         += wifi\lib\x\x.lib
    CUS_REL_OBJ_LIST += wifi\lib\x\x.lib
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R99_SUPPORT)
  R99_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(findstring $(strip $(PLATFORM)),$(R99_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ 
  else
    $(warning ERROR: Chip version $(strip $(PLATFORM)) not support R99_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R4_SUPPORT)
  R4_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(findstring $(strip $(PLATFORM)),$(R4_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ 
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) not support R4_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R5_SUPPORT)
  R5_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219
  ifeq ($(findstring $(strip $(PLATFORM)),$(R5_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __USIM_SUPPORT__
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          COM_DEFS    +=   __ACL_SUPPORT__
        endif
        ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
          COM_DEFS    +=   __ACL_SUPPORT__
        endif
      endif
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) not support R5_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
  R6_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(findstring $(strip $(PLATFORM)),$(R6_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __FDD_REDIRECTION__
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          COM_DEFS    +=   __ACL_SUPPORT__
        endif
        ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
          COM_DEFS    +=   __ACL_SUPPORT__
        endif
      endif
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) does not support R6_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R4_SUPPORT)
  COM_DEFS    +=   __UMTS_R4__ __REL4__
endif
ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __FDD_REDIRECTION__
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__
      COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS    +=   __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __UMTS_R7__  __REL7__ __FDD_REDIRECTION__
    ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
      
      ifeq ($(strip $(R7_HSDPA_PLUS_SUPPORT)),TRUE)
        COM_DEFS    +=   __R7_HSDPA_PLUS_SUPPORT__ __MAC_EHS_SUPPORT__ __ENHANCED_COMMON_STATE_SUPPORT__
      endif
      
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        COM_DEFS    +=   __HSUPA_SUPPORT__
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
        
        ifeq ($(strip $(R7_HSUPA_PLUS_SUPPORT)),TRUE)
          COM_DEFS    +=   __R7_HSUPA_PLUS_SUPPORT__ __CPC_SUPPORT__
        endif
    
        ifeq ($(call gt,$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),12),T)
          ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),15)
            ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),16)
              ifeq ($(strip $(HOM_DL64QAM_SUPPORT)),TRUE)
                COM_DEFS    +=   __HOM_DL64QAM_SUPPORT__
              endif
            endif
          endif
        endif
    
        ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),6),T)
          ifeq ($(strip $(HOM_UL16QAM_SUPPORT)),TRUE)
            COM_DEFS    +=   __HOM_UL16QAM_SUPPORT__
          endif
        endif
      endif
    endif
  endif
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    COM_DEFS    +=   __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __UMTS_R7__
    ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        COM_DEFS    +=   __HSUPA_SUPPORT__
        COM_DEFS    +=   TDD_EDCH_CATEGORY=$(strip $(TDD_EDCH_PHYSICAL_CATEGORY))
        ifeq ($(strip $(HSUPA_CAPABILITY_NOT_SUPPORT)),TRUE)
          COM_DEFS    +=   __HSUPA_CAPABILITY_NOT_SUPPORT__
        endif
      endif
    endif
  endif
endif

ifneq ($(filter __DYNAMIC_HSPA_PREFERENCE__,$(COM_DEFS)),)
  ifeq ($(filter __HSPA_PREFERENCE_SETTING__,$(strip $(COM_DEFS))),)
    $(error ERROR: PLEASE turn off __DYNAMIC_HSPA_PREFERENCE__ when __HSPA_PREFERENCE_SETTING__ is not defined.)
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ 
endif

ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
  ifeq ($(filter __UMTS_R6__,$(strip $(COM_DEFS))),)
    ifneq ($(filter __R6_NETWORK_SHARING__,$(strip $(COM_DEFS))),)
      $(error __R6_NETWORK_SHARING__ can only be turned on when __UMTS_R6__ defined)
    endif
    ifneq ($(filter __R6_DSAC__,$(strip $(COM_DEFS))),)
      $(error __R6_DSAC__ can only be turned on when __UMTS_R6__ defined)
    endif
  endif

  ifneq ($(filter __UMTS_R6__,$(strip $(COM_DEFS))),)
    ifeq ($(filter __R6_NETWORK_SHARING__,$(strip $(COM_DEFS))),)
      COM_DEFS += __R6_NETWORK_SHARING__
    endif
    ifeq ($(filter __R6_DSAC__,$(strip $(COM_DEFS))),)
      COM_DEFS += __R6_DSAC__
    endif
  endif
endif

ifeq ($(filter __CPHS__,$(COM_DEFS)),)
  ifeq ($(filter __REL4__,$(COM_DEFS)),)
    ifneq ($(filter __SS_CPHS_QUERY_CFU_ALWAYS__,$(strip $(COM_DEFS))),)
      $(error ERROR: PLEASE turn on __CPHS__ or __REL4__ when __SS_CPHS_QUERY_CFU_ALWAYS__ is on)
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
    COMPLIST += wise
    COMMINCDIRS += external_mmi\wise\main external_mmi\wise\bal\sys\include
  else
    COMPLIST += wise lgoem
    COMMINCDIRS += external_mmi\wise\main external_mmi\wise\bal\sys\include
  endif
endif

ifeq ($(strip $(TTL_SUPPORT)),SOURCE)
  COMPLIST         += ttl
else
  #ttl.lib is a must-be-linked library.
  COMPOBJS         += ttl\lib\ttl.lib
  CUS_REL_OBJ_LIST += ttl\lib\ttl.lib
endif

ifndef MMI_BASE
  MMI_BASE = PLUTO_MMI
  MMIDIR   = plutommi
else
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    MMIDIR         =  lcmmi
  else
    ifeq ($(strip $(MMI_BASE)), VENUS_MMI)
      MMIDIR         =  plutommi
    else
      MMIDIR         =  plutommi
    endif
  endif
endif

MMI_BASE_PRJ = $(strip $(subst _MMI,,$(MMI_BASE)))

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
  ifeq ($(strip $(call Upper,$(MAIN_LCD_SIZE))),128X128)
    CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_BASE_PRJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))_WITHOUT_ENHANCED
  endif
endif

ifeq ($(filter BASIC L1S UDVT,$(strip $(call Upper,$(PROJECT)))),)
  INPUT_METHOD_BASE = $(strip $(MMIDIR))
  ifeq ($(strip $(DEMO_PROJECT)),FALSE)
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
    endif
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
      INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
    endif
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
    endif  
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
    endif
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
    endif
  endif

  ifndef OP_CHECK_FORCE_ERROR
    OP_CHECK_FORCE_ERROR = 0
    ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
        OP_CHECK_FORCE_ERROR = 1
      endif
    endif
  endif

  ifdef FONT_RESOURCE
    BITMAP_FONT_EXCLUDE_LCD_SIZE = 480X800
    ifeq ($(strip $(FONT_RESOURCE)),OFFICIAL)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
          COMMINCDIRS += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        endif
        FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
          COMMINCDIRS += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        endif
        FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif

      CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))

      ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
        ifneq ($(strip $(MMIDIR)),lcmmi)
          COMMINCDIRS += vendor\font\inc
        else
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        endif
        CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(MMIDIR))
      endif

      ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
        ifneq ($(strip $(MMIDIR)),lcmmi)
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
            vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        else
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
            vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        endif
        CUS_REL_BASE_COMP += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))
      endif
      COM_DEFS  += __FONT_RESOURCE_OFFICIAL__
    endif

    ifeq ($(strip $(FONT_RESOURCE)),DEMO)
      ifeq ($(strip $(MMIDIR)),lcmmi)
        $(warning ERROR: DEMO font is only applied in PLUTOMMI project, please set FONT_RESOURCE=OFFICIAL)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128 128X160 176X220 240X240 240X320 320X240 240X400 320X480 480X800),)
        $(warning ERROR: DEMO font only supports 128X128, 128X160, 176X220, 240X240, 240X320, 320X240, 240X400, 320X480 and 480X800 MAIN_LCD_SIZE, for other MAIN_LCD_SIZE, please set FONT_RESOURCE=OFFICIAL)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(MMIDIR)),lcmmi)
        ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
          COMMINCDIRS += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          COMMINCDIRS += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        endif
        FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
          COMMINCDIRS += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          COMMINCDIRS += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        endif
        FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif

      CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))

      ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
        ifneq ($(strip $(MMIDIR)),lcmmi)
          COMMINCDIRS += vendor\font\inc
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        else
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
            COMMINCDIRS += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        endif
        CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(MMIDIR))
        CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))
      endif

      ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
        ifneq ($(strip $(MMIDIR)),lcmmi)
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        else
          ifneq ($(strip $(MAIN_LCD_SIZE)),$(BITMAP_FONT_EXCLUDE_LCD_SIZE))
            COMMINCDIRS += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
          endif
        endif
        CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))
      endif
      COM_DEFS  += __FONT_RESOURCE_DEMO__
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE)) \
                           vendor\font\MTK\official\project\$(strip $(MMIDIR)) \
                           vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) \
                           vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE)) \
                           vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE)) \
                           vendor\font\MTK\demo\project\$(strip $(MMIDIR)) \
                           vendor\font\Arphic\demo\project\$(strip $(MMIDIR)) \
                           vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))
    endif
  endif
endif

ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_KOMOXO)
    CUSTOM_COMMINC  +=  vendor\vectorfont\komoxo \
                        vendor\vectorfont\komoxo\font
    COMPLIST    += vectorfont_komoxo
    COM_DEFS    += __MMI_SCRIPT_EASY__
    COM_DEFS    += __MMI_SCRIPT_EASY_FONT_OPTION__
    ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      COM_DEFS    += __MMI_SCRIPT_EASY_FONT_SIZE_OPTION__
    endif
    COMPOBJS  += vendor\vectorfont\komoxo\lib\scripteasy.a
    CUS_REL_OBJ_LIST  += vendor\vectorfont\komoxo\lib\scripteasy.a
endif

ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_KOMOXO_DEMO)
    CUSTOM_COMMINC  +=  vendor\vectorfont\komoxo \
                        vendor\vectorfont\komoxo\font
    COMPLIST    += vectorfont_komoxo
    COM_DEFS    += __MMI_SCRIPT_EASY__
    COM_DEFS    += __MMI_SCRIPT_EASY_DEMO__
    COMPOBJS   += vendor\vectorfont\komoxo\lib_demo\scripteasy.a
    CUS_REL_OBJ_LIST   += vendor\vectorfont\komoxo\lib_demo\scripteasy.a
endif

ifdef INPUT_METHOD
  INPUT_METHOD_FREE_LIBRARIES = NONE MMI_CSTAR_V2_DEMO MMI_CSTAR_FREE_SLIM_0K MMI_CSTAR_FREE_SLIM_5K MMI_CSTAR_FREE_SLIM_10K MMI_CSTAR_FREE_FULL MMI_GUOBI_V5_2 MMI_GUOBI_V5_2_SLIM MMI_GUOBI_V5_2_0K_SLIM MMI_GUOBI_V5_2_5K_SLIM MMI_GUOBI_V5_2_10K_SLIM
  ifeq ($(filter $(INPUT_METHOD_FREE_LIBRARIES),$(strip $(INPUT_METHOD))),)
    ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
      ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
        $(warning ERROR: Please set INPUT_METHOD to NONE/MMI_CSTAR_V2_DEMO/MMI_CSTAR_FREE_SLIM_0K/MMI_CSTAR_FREE_SLIM_5K/MMI_CSTAR_FREE_SLIM_10K/MMI_CSTAR_FREE_FULL or MMI_GUOBI_V5_2/MMI_GUOBI_V5_2_SLIM/MMI_GUOBI_V5_2_0K_SLIM/MMI_GUOBI_V5_2_5K_SLIM/MMI_GUOBI_V5_2_10K_SLIM in customer projects.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V6)
    ifeq ($(strip $(COMPILER)),RVCT)
      COMMINCDIRS  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct
    else 
      COMMINCDIRS  +=  vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\inc
      COMPOBJS    += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
      CUS_REL_OBJ_LIST    += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official  
    endif
  endif
   ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
    ifeq ($(strip $(COMPILER)),RVCT)
      COMMINCDIRS  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct
    else
      COMMINCDIRS  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    endif
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
    ifeq ($(strip $(COMPILER)),RVCT)
      COMMINCDIRS  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct
    else
      COMMINCDIRS  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    endif
  endif

  # CSTAR free version with full database  .This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_FULL)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_full
  endif

  # CSTAR free version with slim database  10k words.This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_10K)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_slim_10k
  endif

  # CSTAR free version with slim database 5k words .This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_5K)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_slim_5k
  endif

  # CSTAR free version with slim database 0k words .This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_0K)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_slim_0k
  endif

  # CSTAR slim 1 for romanian , czech , polish and Hungarian slim database  .This one CANNOT  be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM1)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\eastern_euro_slim1
  endif

  # CSTAR slim 2 for romanian , czech , polish and Hungarian slim database  .This one CANNOT  be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\eastern_euro_slim2
  endif

  # CSTAR free version with full database  .This one can not be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_SLIM1)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_slim1
  endif
  
  # CSTAR free version with full database  .This one can nto be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_SLIM2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_slim2
  endif
  
  # CSTAR Official version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_official
  endif

# Release four free libraries to customers.
  CUS_REL_BASE_COMP += vendor\InputMethod\cstar\free_full \
                       vendor\InputMethod\cstar\free_slim_10k \
                       vendor\InputMethod\cstar\free_slim_5k \
                       vendor\InputMethod\cstar\free_slim_0k

  #block 1  can be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_FULL)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__

    # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_FULL__

    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

 # block 2 can be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_10K)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__

    # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_SLIM_10K__

    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 3 can be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_5K)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__

    # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_SLIM_5K__

    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 4 can be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_0K)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__

    # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_SLIM_0K__

    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 5 can not be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 5 can not be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_SLIM1)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2_SLIM1__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 5 can not be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_SLIM2)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2_SLIM2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 6 cannot release to customer
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM1)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_EASTERNEURO_SLIM2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # block 7  canot release to customer
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM2)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_EASTERNEURO_SLIM2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # CSTAR Demo version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_demo
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct_demo.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct_demo.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct_demo.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif 
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    COMMINCDIRS += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # KOMOXO Official version
  ifeq ($(strip $(INPUT_METHOD)),MMI_KOMOXO)
    CUS_INPUTMETHOD_BASE = vendor\InputMethod\Komoxo
    COMPLIST    += komoxo
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxsip_input_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxsip_input_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxsip_input_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxsip_input.a
    endif
    COM_DEFS    += __MMI_KOMOXO__
    COM_DEFS    += __MMI_CSTAR__
    COMMINCDIRS += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  # KOMOXO Demo version
  ifeq ($(strip $(INPUT_METHOD)),MMI_KOMOXO_DEMO)
    CUS_INPUTMETHOD_BASE = vendor\InputMethod\Komoxo
    COMPLIST    += komoxo
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib_demo\kmxsip_input_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib_demo\kmxsip_input_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib_demo\kmxsip_input_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib_demo\kmxsip_input.a
    endif
    COM_DEFS    += __MMI_KOMOXO__
    COM_DEFS    += __MMI_CSTAR__   
    COMMINCDIRS += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib_demo
  endif
  CUS_REL_BASE_COMP   += vendor\InputMethod\Komoxo

  ifneq ($(findstring MMI_ZI,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_ZI__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI_V7)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    COMPLIST    += zi
    ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
    else
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
        CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
      else
        CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a /b 2>nul)
      endif
    endif
    ifeq ($(words $(strip $(CUS_ZI))),1)
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      COMPOBJS  += $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      CUS_REL_OBJ_LIST  += $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      else
        ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
          COMPOBJS  += $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
          CUS_REL_OBJ_LIST  += $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
        else
          COMPOBJS  += $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
          CUS_REL_OBJ_LIST  += $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
        endif
      endif
    endif
  endif
  ifneq ($(findstring MMI_T9,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_T9__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9_V7_4)
          COM_DEFS    += __MMI_T9_V7_4__
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9_ALPHA)
          COM_DEFS    += __MMI_T9_V7_4__
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9)
          COM_DEFS    += __MMI_T9_V7_4__
    endif
    COMPLIST    += t9
  endif

  T9_PATH = $(shell dir vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
  ifeq ($(words $(strip $(T9_PATH))),0)
    INPUT_METHOD_BASE = plutommi
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_XT9)
    COMPLIST    += t9
    COM_DEFS    += __MMI_T9__
    COM_DEFS    += __MMI_XT9__
    COMMINCDIRS += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9\inc
    COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9\lib\xt9.o
    CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9\lib\xt9.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
    ifeq ($(strip $(COMPILER)),RVCT)
        COMMINCDIRS  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct
    else
        COMMINCDIRS  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official
    endif
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_ALPHA)
    CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\inc
    COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relAlphabetic_rvct.o
    CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relAlphabetic_rvct.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7_4)
    ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        COMMINCDIRS  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\inc
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct
    else
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        COMMINCDIRS  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\inc
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official
    endif 
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7)
    ifeq ($(strip $(COMPILER)),RVCT)
        COMMINCDIRS  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\t9relChinese_rvct.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\t9relChinese_rvct.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct
    else
        COMMINCDIRS  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    endif 
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V6)
    $(warning ERROR: INPUT_METHOD MMI_T9_V6 is phased out. Please change INPUT_METHOD value)
    DEPENDENCY_CONFLICT = TRUE
  endif
  
  GUOBI_PATH = $(shell dir vendor\InputMethod\GUOBI\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
  ifeq ($(words $(strip $(GUOBI_PATH))),0)
    INPUT_METHOD_BASE = plutommi
  endif
  
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V1)
    COMPLIST    += guobi
    COMMINCDIRS  += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo\inc
    COMPOBJS   +=   vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo\lib\_libGBEngine_.a
    CUS_REL_OBJ_LIST   += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo\lib\_libGBEngine_.a
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo
    COM_DEFS    += MMI_GUOBI
    COM_DEFS    += __MMI_GUOBI__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif
  ifneq ($(filter MMI_GUOBI_V5_2%,$(INPUT_METHOD)),)    
    ifndef GUOBI_WINGUO_SUPPORT
      $(warning ERROR: INPUT_METHOD: MMI_GUOBI_V5_2_0K_SLIM\MMI_GUOBI_V5_2_5K_SLIM\MMI_GUOBI_V5_2_10K_SLIM\MMI_GUOBI_V5_2_SLIM\MMI_GUOBI_V5_2 can only enable with Winguo search. Please change INPUT_METHOD value or GUOBI_WINGUO_SUPPORT should not be NONE) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2)
    COMPLIST    += guobi
    COMMINCDIRS  += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo\inc
    COMPOBJS   +=   vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo\lib\_libGBEngine_.a
    CUS_REL_OBJ_LIST   += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo\lib\_libGBEngine_.a
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_demo
    COM_DEFS    += __MMI_GUOBI__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_SLIM)
    COMPLIST    += guobi
    COMMINCDIRS  += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\inc
    COMPOBJS   +=   vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_REL_OBJ_LIST   += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim
    COM_DEFS    += __MMI_GUOBI__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_0K_SLIM)
    COMPLIST    += guobi
    COMMINCDIRS  += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\inc
    COMPOBJS   +=   vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_REL_OBJ_LIST   += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim
    COM_DEFS    += __MMI_GUOBI__
    COM_DEFS    += __MMI_GUOBI_0K__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_5K_SLIM)
    COMPLIST    += guobi
    COMMINCDIRS  += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\inc
    COMPOBJS   +=   vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_REL_OBJ_LIST   += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim
    COM_DEFS    += __MMI_GUOBI__
    COM_DEFS    += __MMI_GUOBI_5K__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_10K_SLIM)
    COMPLIST    += guobi
    COMMINCDIRS  += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\inc
    COMPOBJS   +=   vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_REL_OBJ_LIST   += vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim\lib\_libGBEngine_.a
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\GUOBI\project\$(INPUT_METHOD_BASE)\v5_2_slim
    COM_DEFS    += __MMI_GUOBI__
    COM_DEFS    += __MMI_GUOBI_10K__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif
  
  CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))
  CUS_REL_BASE_COMP   += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim \
                         vendor\InputMethod\GUOBI\project\plutommi\v5_2_demo \
                         vendor\InputMethod\GUOBI\project\$(strip $(INPUT_METHOD_BASE))\v1_demo

  ifneq ($(strip $(INPUT_METHOD_BASE)),plutommi)
    ifneq ($(strip $(INPUT_METHOD_BASE)),lcmmi)
      CUS_T9 = $(shell dir vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_T9))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) make\t9 vendor\InputMethod\T9\adaptation
      endif
      CUS_ZI = $(shell dir vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) make\zi vendor\InputMethod\ZI\adaptation
      endif
    endif
  endif
  
  ifneq ($(strip $(INPUT_METHOD)),NONE)
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      COMMINCDIRS += $(strip $(CUS_INPUTMETHOD_BASE))\inc
      CUS_REL_BASE_COMP += vendor\InputMethod\ZI\project\$(MMIDIR) \
                           vendor\InputMethod\T9\project\$(MMIDIR) \
                           vendor\InputMethod\cstar\v2_official \
                           vendor\InputMethod\cstar\v2_demo
    endif
  endif
  CUS_REL_BASE_COMP += vendor\InputMethod\ZI\adaptation make\zi \
                       vendor\InputMethod\T9\adaptation make\t9 \
                       vendor\InputMethod\cstar\adaptation make\cstar
endif

 #Winguo compiler option 
ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_NONE)
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_SLIM)
    $(warning ERROR: INPUT_METHOD MMI_GUOBI_V5_2_SLIM can only enable with Winguo search. Please change INPUT_METHOD value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2)
    $(warning ERROR: INPUT_METHOD MMI_GUOBI_V5_2 can only enable with Winguo search. Please change INPUT_METHOD value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_0K_SLIM)
    $(warning ERROR: INPUT_METHOD MMI_GUOBI_V5_2_0K_SLIM can only enable with Winguo search. Please change INPUT_METHOD value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_5K_SLIM)
    $(warning ERROR: INPUT_METHOD MMI_GUOBI_V5_2_5K_SLIM can only enable with Winguo search. Please change INPUT_METHOD value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_10K_SLIM)
    $(warning ERROR: INPUT_METHOD MMI_GUOBI_V5_2_10K_SLIM can only enable with Winguo search. Please change INPUT_METHOD value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_GUOBI_HW_STANDARD)
    $(warning ERROR: HAND_WRITING MMI_GUOBI_HW_STANDARD can only enable with Winguo search. Please change HAND_WRITING value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_GUOBI_HW_SC_SLIM)
    $(warning ERROR: HAND_WRITING MMI_GUOBI_HW_SC_SLIM can only enable with Winguo search. Please change HAND_WRITING value or GUOBI_WINGUO_SUPPORT should not be NONE) 
    DEPENDENCY_CONFLICT = TRUE
  endif
else                             
  COMPLIST      +=  winguo                                                
  ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_SLIM)
    COM_DEFS    += __GUOBI_WINGUO_SUPPORT__
    COMMINCDIRS += vendor\search_engine\GUOBI\winguo\adapter\winguo_inc \
                   vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_inc
    COMPOBJS    += vendor\search_engine\GUOBI\winguo\project\slim\lib\_SmartDial_.a
    COMPOBJS    += vendor\search_engine\GUOBI\winguo\project\slim\lib\winguo_v4package.a
                            
    CUS_REL_OBJ_LIST  += vendor\search_engine\GUOBI\winguo\project\slim\lib\_SmartDial_.a
    CUS_REL_OBJ_LIST  += vendor\search_engine\GUOBI\winguo\project\slim\lib\winguo_v4package.a
  endif
  ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_SLIM_V2)
    COMMINCDIRS += vendor\search_engine\guobi\winguo_v2\inc  \
                   vendor\search_engine\guobi\winguo_v2\src\view\inc
    COMPOBJS    += vendor\search_engine\GUOBI\winguo_v2\lib\_SmartDial_.a
    COMPOBJS    += vendor\search_engine\GUOBI\winguo_v2\lib\winguo_smd.a
                          
    CUS_REL_OBJ_LIST  += vendor\search_engine\GUOBI\winguo_v2\lib\_SmartDial_.a
    CUS_REL_OBJ_LIST  += vendor\search_engine\GUOBI\winguo_v2\lib\winguo_smd.a
    COM_DEFS    += __GUOBI_WINGUO_V2_SUPPORT__
  endif
  ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_ULTRA_SLIM)
    COM_DEFS    += __GUOBI_WINGUO_SUPPORT__
    COM_DEFS    += __GB_WINGUO_4_U__
    COMMINCDIRS += vendor\search_engine\GUOBI\winguo\adapter\winguo_inc \
                   vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_inc
    COMPOBJS    += vendor\search_engine\GUOBI\winguo\project\ultra_slim\lib\winguo_v4package.a
    CUS_REL_OBJ_LIST  += vendor\search_engine\GUOBI\winguo\project\ultra_slim\lib\winguo_v4package.a
  endif
  ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_FULL)
    $(warning ERROR: The Winguo full version is not QC and porting by MTK. Please check the porting doc in vendor\search_engine\GUOBI\winguo\project\full if you need this version. And please comment this error once you complete the porting.) 
    DEPENDENCY_CONFLICT = TRUE
    COMPOBJS       += vendor\search_engine\GUOBI\winguo\project\full\lib\_SmartDial_.a
    COMPOBJS       += vendor\search_engine\GUOBI\winguo\project\full\lib\winguo_v4package.a
  endif
endif

ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
    COMPLIST    += game_engine
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
    COMPOBJS    += vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
                   vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
                   vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib
    CUS_REL_OBJ_LIST += vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
                        vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
                        vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib \
                        vendor\game_engine\brogent\engine_v1\pc\mini_bgl.lib \
                        vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\pc\bgt_ggr2_optimize.lib \
                        vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\pc\bgt_hb2_utils.lib
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    #COMPOBJS += vendor\game_engine\brogent\engine_v1\arm\ur_engine.lib
  endif
endif

ifdef BROWSER_SUPPORT
  ifneq ($(filter $(strip $(BROWSER_SUPPORT)) ,$(BROWSER_SUPPORT_Q03C_TYPES)),)
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
    COMPLIST    += obigo03cstkadp obigo03cstklib
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    COMPLIST    += obigo05aadp obigo05alib
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
    COMPLIST    += opera10adp opera10opdev
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
    COMPLIST    += opera10int
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\opera\browser\v1_official\lib\rvct\opera_rvct.lib
      CUS_REL_OBJ_LIST += vendor\opera\browser\v1_official\lib\rvct\opera_rvct.lib
    else
      COMPOBJS    += vendor\opera\browser\v1_official\lib\arm\opera.lib
      CUS_REL_OBJ_LIST += vendor\opera\browser\v1_official\lib\arm\opera.lib
    endif    
    CUS_REL_BASE_COMP += vendor\opera\browser\v1_official\Resource
    CUS_REL_FILES_LIST += vendor\opera\browser\v1_official\lib\win32\opera.lib
    CUS_REL_FILES_LIST += vendor\opera\browser\v1_official\lib\win32\ulldvrm.obj

    ifneq ($(strip $(OPTR_SPEC)),NONE)
      COMMINCDIRS += vendor\opera\browser\v1_official\opdev\include
    endif
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_TURBO)
    COMPLIST    += opera10adp opera11opdev
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
    COMPLIST    += opera10int
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\opera\browser\v11_official\lib\rvct\opera_rvct.lib
      COMPOBJS    += vendor\opera\browser\v11_official\lib\rvct\fucus_rvct.lib
      CUS_REL_OBJ_LIST += vendor\opera\browser\v11_official\lib\rvct\opera_rvct.lib
      CUS_REL_OBJ_LIST += vendor\opera\browser\v11_official\lib\rvct\fucus_rvct.lib
    endif
    CUS_REL_BASE_COMP += vendor\opera\browser\v11_official\Resource
    CUS_REL_FILES_LIST += vendor\opera\browser\v11_official\lib\win32\libfucus.lib
    CUS_REL_FILES_LIST += vendor\opera\browser\v11_official\lib\win32\libopera.lib
    CUS_REL_FILES_LIST += vendor\opera\browser\v11_official\lib\win32\libopera.dll
    
    ifneq ($(strip $(OPTR_SPEC)),NONE)
      COMMINCDIRS += vendor\opera\browser\v11_official\opdev\include
    endif
  endif
endif

ifdef SYNCML_SUPPORT
  ifneq ($(strip $(SYNCML_SUPPORT)),FALSE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,SYNCML_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif  
  endif
  ifeq ($(strip $(SYNCML_SUPPORT)),TRUE)
    ifndef VCARD_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,VCARD_SUPPORT,SYNCML_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(VCARD_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,VCARD_SUPPORT,SYNCML_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __SYNCML_SUPPORT__
    COMPLIST    += syncml
    COMP_TRACE_DEFS += inet_ps\syncml\include\syncml_trc.h
  endif
  ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
    BT_SUPPORT_PROFILE += SYNCML_DEVICE_SYNC_PROFILE
  else
    ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
      BT_SUPPORT_PROFILE += SYNCML_DEVICE_SYNC_PROFILE
    endif
  endif
endif

ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
  CUS_REL_FILES_LIST += plutommi\Service\SmsSrv\SmsArchiveSrv.h
  ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
    COMMINCDIRS += plutommi\MMI\UnifiedComposer\UnifiedComposerInc
  endif
endif

CUS_REL_FILES_LIST += plutommi\Service\WgtMgrSrv\mem_widget_icon.png.hex
CUS_REL_FILES_LIST += plutommi\Service\WgtMgrSrv\mem_widget_icon_big.png.hex

ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifdef MMS_SUPPORT
    ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
      ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
        ifneq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE)
          DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS    +=  __UNIFIED_COMPOSER_SUPPORT__
      endif
    endif
  endif
endif

ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
  ifneq ($(findstring ARCHIVE,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
    COM_DEFS    +=  __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
  endif
endif

ifneq ($(filter __KTEST__,$(CUSTOM_OPTION)),)
  COMPLIST += ktest 
endif

CUS_REL_BASE_COMP += mtkdebug\ktest make\ktest

COMPLIST += cipher

SYNC_LCM_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205 MT6217 MT6218 MT6223 MT6223P MT6225 
SYNC_LCM_HW_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268 MT6253T MT6253 MT6516 MT6270A MT6256 MT6276 MT6253E MT6253L MT6252 MT6252H MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
SYNC_LCM_SUPPORT_DISABLE_OPTION = FALSE NONE 

ifdef SYNC_LCM_SUPPORT
  ifeq ($(filter $(strip $(SYNC_LCM_SUPPORT)) ,$(SYNC_LCM_SUPPORT_DISABLE_OPTION)),)
    ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_SUPPORT_NOT_SUPPORT_FLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SYNC_LCM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef SYNC_LCM_METHOD
      ifeq ($(strip $(SYNC_LCM_METHOD)),BY_CHIP)
        #legacy chip-dependent method
        ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_HW_SUPPORT_PLATFORM)),)
          COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_HW_SUPPORT__
        else    
          COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_SW_SUPPORT__
        endif
      else
        COM_DEFS    += __SYNC_LCM_SUPPORT__
        COM_DEFS    += __SYNC_LCM_$(strip $(SYNC_LCM_METHOD))_SUPPORT__
      endif
    else
      #legacy chip-dependent method
      ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_HW_SUPPORT_PLATFORM)),)
        COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_HW_SUPPORT__
      else    
        COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_SW_SUPPORT__
      endif
    endif
  endif
endif

ifneq ($(filter DUAL_LCD,$(COM_DEFS)),)
  ifeq ($(strip $(SUB_LCD_SIZE)),NONE)
    ifneq ($(strip $(PLATFORM)),TK6516)
      ifneq ($(strip $(PLATFORM)),MT6516)
        $(warning ERROR: Please set SUB_LCD_SIZE when DUAL LCD (LCD_MODULE=$(strip $(LCD_MODULE))) is used)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

L1CACHEABLE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6268T MT6268H TK6516 MT6225 MT6253T MT6253 MT6251
ifneq ($(filter $(strip $(PLATFORM)) ,$(L1CACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __MTK_L1CACHEABLE__
endif

L2CACHEABLE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6268T MT6268H MT6238 MT6239
ifneq ($(filter $(strip $(PLATFORM)) ,$(L2CACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __MTK_L2CACHEABLE__
endif

DCM_SUPPORT_PLATFORM = MT6223% MT6225 MT6235% MT6238 MT6239 MT6268% MT6253T MT6253 MT6236% MT6270A MT6921
ifneq ($(filter $(strip $(DCM_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
  COM_DEFS += __DYNAMIC_CODE_MANAGER__
endif

WTCACHEABLE_SUPPORT_PLATFORM = MT6253
ifneq ($(filter $(strip $(PLATFORM)) ,$(WTCACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __WRITE_THROUGH_CACHEABLE__
endif

CUS_REL_BASE_COMP += make\theme_rom

ifeq ($(filter dp_engine,$(COMPLIST)),dp_engine)
  ifeq ($(strip $(call Upper,$(PLATFORM))),MT6205B)
    $(warning ERROR: MT6205B does not support dp_engine)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

COMPLIST += mm_comm

ifeq ($(filter COSMOS_MMI PLUTO_MMI NEPTUNE_MMI IOT_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
  ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
     $(warning ERROR: Please turn off REDUCE_HEADER_DEPTH when MMI_VERSION is $(MMI_VERSION)!)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(L1_TDD128)),TRUE)
  COPY_MMI_INCLUDE_FILE = tools\copy_mmi_include_h_$(strip $(call Upper,$(MMI_VERSION)))_$(strip $(call Upper,$(RTOS)))_TDD.bat
else
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    COPY_MMI_INCLUDE_FILE = tools\copy_mmi_include_h_PLUTO_MMI_$(strip $(call Upper,$(RTOS))).bat
  else
    COPY_MMI_INCLUDE_FILE = tools\copy_mmi_include_h_$(strip $(call Upper,$(MMI_VERSION)))_$(strip $(call Upper,$(RTOS))).bat
  endif
endif

ifeq ($(strip $(ISP_SUPPORT)),TRUE)
  COMPLIST += camera
  COMPLIST += postproc postproc_sec
endif

ifdef CUST_CODE
  ifneq ($(strip $(CUST_CODE)),NONE)
    COM_DEFS += __$(strip $(CUST_CODE))__
  endif
  ifeq ($(strip $(CUST_CODE)),TC01)
    COM_DEFS += __RMMI_EXTEND_CUSTOM_CMD__ __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    COM_DEFS += __ATH_HANGUP_OTHER_SRC_CALL__
    ifneq ($(strip $(DRM_SUPPORT)),NONE)
      COM_DEFS += __LONG_AT_CMD_SUPPORT__
    endif
    ifdef TC01_ERS_LOCATION                         
      ifneq ($(strip $(TC01_ERS_LOCATION)),NONE)
        COM_DEFS += __TC01_ERS_SUPPORT__        
      endif                                     
    endif 
  endif
endif
    
ifdef TC01_ERS_LOCATION
  ifeq ($(strip $(TC01_ERS_LOCATION)),NVRAM)
    COM_DEFS += __TC01_ERS_NVRAM__
  endif
  ifeq ($(strip $(TC01_ERS_LOCATION)),BACKUP)
    ifndef SYSDRV_BACKUP_DISK_SUPPORT
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __TC01_ERS_BACKUP__
  endif
endif

ifneq ($(filter __ACL_SUPPORT__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR:  __ACL_SUPPORT__ cannot be defined if __PS_SERVICE__ not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SDS_SUPPORT
  ifeq ($(strip $(SDS_SUPPORT)),TRUE)
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      COM_DEFS += __SDS_DP_ENABLE__ __SECURE_DATA_STORAGE__ __SDS_NVRAM_SUPPORT__
    else    
      COM_DEFS += __SDS_DP_ENABLE__ __SECURE_DATA_STORAGE__ __NOR_FULL_DRIVER__ __SDS_NVRAM_SUPPORT__
    endif
  endif
endif

ifdef BOOT_CERT_SUPPORT
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V1)
    COM_DEFS += __BOOT_CERT__ __BOOT_CERT_V1__
  endif
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V2)
    COM_DEFS += __BOOT_CERT__ __BOOT_CERT_V2__
  endif
endif

ifdef BOOT_CERT_SUPPORT
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V2)
    ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(warning ERROR: BOOT_CERT_SUPPORT only can be enabled, when SECURE_SUPPORT = FALSE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
      $(warning ERROR: BOOT_CERT_SUPPORT only can be enabled, when CARD_DOWNLOAD = NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

MMA_MAX_NUM_VALUE = 2 3 4 5 6 7 8 9 10 11 12
ifdef MMA_MAX_NUM
  ifeq ($(filter $(strip $(MMA_MAX_NUM)),$(strip $(MMA_MAX_NUM_VALUE))),)
    $(warning ERROR: Please set MMA_MAX_NUM to 2-12.)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS += MMA_MAX_NUM=$(strip $(MMA_MAX_NUM))
  endif
else
  COM_DEFS += MMA_MAX_NUM=12
endif

ifdef ALIPAY_SUPPORT
  ifeq ($(strip $(ALIPAY_SUPPORT)),TRUE)
    COM_DEFS += __ALIPAY_SUPPORT__
    COM_DEFS += __CHE_RSA_GEN_KEY__
    COMPLIST += alipay
    COMPOBJS += vendor\alipay\lib\alixpay.a
  endif
endif

ifdef PACKAGE_SEG
  ifneq ($(strip $(PACKAGE_SEG)), NONE)
    COM_DEFS    +=  __$(strip $(PACKAGE_SEG))__
  endif
endif

ifeq ($(strip $(PACKAGE_SEG)),16_3_SEG)
  ifneq ($(strip $(PLATFORM)),MT6251)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when PLATFORM = MT6251)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when USB_DOWNLOAD_IN_BL = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(SECURE_SUPPORT)),FALSE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when SECURE_SUPPORT = FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when CARD_DOWNLOAD = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when SW_BINDING_SUPPORT = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when FOTA_ENABLE = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(SECURE_RO_ENABLE)),FALSE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when SECURE_RO_ENABLE = FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DATA_CARD_SPEECH)),TRUE)
  DATA_CARD_SUPPORT_PLATFORM = MT6276
  ifeq ($(filter $(strip $(PLATFORM)) ,$(DATA_CARD_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support DATA_CARD_SPEECH.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MODEM_CARD__,$(COM_DEFS)),)
    $(warning ERROR: only __MODEM_CARD__ project support DATA_CARD_SPEECH.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __DATA_CARD_SPEECH__
endif

ifeq ($(strip $(WPS_SUPPORT)), TRUE)
  COM_DEFS += __WPS_SUPPORT__
endif

ifeq ($(strip $(YAHOO_CONTENT_SUPPORT)),TRUE)
  COM_DEFS += __YAHOO_CONTENT_SUPPORT__
endif

ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  CUS_REL_BASE_COMP += external_mmi make\lgoem
endif

ifdef SIM_HOT_SWAP
  ifneq ($(strip $(SIM_HOT_SWAP)), NONE)
    COM_DEFS    +=  __SIM_HOT_SWAP_SUPPORT__
    ifneq ($(findstring SIM_SLOT_1,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_1_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_2,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_2_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_3,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_3_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_4,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_4_SUPPORT__
    endif
    ifneq ($(strip $(SIM_PROVISIONING)),NONE)
      $(call DEP_ERR_SETA_OR_OFFB,SIM_HOT_SWAP,NONE,SIM_PROVISIONING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef SIM_RECOVERY_ENHANCEMENT
  ifneq ($(strip $(SIM_RECOVERY_ENHANCEMENT)), FALSE)
    ifdef SIM_PROVISIONING
      ifneq ($(strip $(SIM_PROVISIONING)),NONE)
        $(call DEP_ERR_OFFA_OR_OFFB,SIM_RECOVERY_ENHANCEMENT,SIM_PROVISIONING)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(DA_SMART_SELECTION_SUPPORT)),TRUE)
  ifndef TCPIP_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,DA_SMART_SELECTION_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,DA_SMART_SELECTION_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __DA_SMART_SELECTION_SUPPORT__
endif

ifdef HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
  ifeq ($(strip $(HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)),TRUE)
    COM_DEFS += DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
  endif
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
  ifeq ($(strip $(DEMAND_PAGING_VERSION)),DPV2)
     COM_DEFS    += __DEMAND_PAGING_V2__
  endif
endif

# For NEPTUNE voice prompt release.
ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  CUS_REL_FILES_LIST += lcmmi\Customer\VoicePrompt\VPres\VP.zip
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  COM_DEFS += __SIM_RESET_BY_SIM__ 
endif

# For MoDIS AVLib release.
CUS_REL_FILES_LIST += MoDIS_VC9\MoDIS\w32_av_lib.cpp \
                      MoDIS_VC9\MoDIS\w32_av_lib.h \
                      MoDIS_VC9\MoDIS\w32_av_types.h \
                      MoDIS_VC9\MoDIS\AVLib\Player.h \
                      MoDIS_VC9\MoDIS\AVLib\RgbFormat.h \
                      MoDIS_VC9\MoDIS\AVLib\VideoSample.h

# For smart phone settings.
ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    include make\smart_phone_option.mak
  endif
endif

ifdef SMART_PHONE_CORE
  ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
    COM_DEFS += __CSCB_ALL_LANGUAGE_ON__
    ifeq ($(strip $(USIM_SUPPORT)),TRUE)
      COM_DEFS += __AT_EPBUM_SUPPORT__ __PHB_USIM_ADDITIONAL_SUPPORT__
    endif
  endif
endif

ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __ALLOW_SIM_REFRESH_RESET_WHEN_IN_CALL__
  endif
endif

# BASIC or UDVT projects do not need L1_TMD_FILES
ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  L1_TMD_FILES :=
endif
ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
  L1_TMD_FILES :=
endif

ifneq ($(filter PLUTO_MMI COSMOS_MMI IOT_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
  COMMINCDIRS   +=  plutommi\Framework\GUI\GUI_INC \
                    plutommi\Framework\CommonFiles\commoninc \
                    plutommi\Framework\EventHandling\eventsinc \
                    plutommi\Framework\History\historyinc \
                    plutommi\Framework\MemManager\memmanagerinc \
                    plutommi\Framework\NVRAMManager\nvrammanagerinc \
                    plutommi\Framework\Tasks\tasksinc \
                    plutommi\Framework\ThemeManager\thememanagerinc \
                    plutommi\Framework\GUI\oem_inc \
                    plutommi\mmi\miscframework\miscframeworkinc \
                    plutommi\Framework\InputMethod\Inc \
                    plutommi\Framework\GDI\gdiinc \
                    plutommi\service\mdi\mdiinc \
                    plutommi\mtkapp\mtkappinc \
                    plutommi\mmi\datetime\datetimeinc \
                    plutommi\Framework\DebugLevels\debuglevelinc
endif

ifdef PBCCH_SUPPORT
  ifeq ($(strip $(PBCCH_SUPPORT)),TRUE)
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
      $(warning ERROR: $(strip $(call Upper,$(PROJECT))) project does not support PBCCH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=    __RMP_PRESENT__
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS += _L1_DISABLE_TRACE_LEVEL_=2
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS += __SLIM_MODEM_EM_MODE__
  else
    COM_DEFS += __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__
  endif
else
  COM_DEFS += __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__
endif

ifeq ($(filter __EM_MODE__,$(CUSTOM_OPTION)),)
  COM_DEFS  := $(filter-out __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__,$(COM_DEFS))
endif

ifeq ($(strip $(PLATFORM)),MT6573)
  COM_DEFS    += __FORCE_RELEASE__
else
  ifneq ($(filter __UCM_SUPPORT__,$(COM_DEFS)),)
    COM_DEFS    += __FORCE_RELEASE__
  endif
endif

ifeq ($(strip $(TCPIP_RAW_SOCKET_SUPPORT)),TRUE)
  COM_DEFS   +=  __TCPIP_RAW_SOCKET_SUPPORT__
endif

ifeq ($(strip $(ATV_RECORD_SUPPORT)), TRUE)
  ifneq ($(strip $(MP4_ENCODE)),TRUE)
    $(warning ERROR: when ATV_RECORD_SUPPORT is set to TRUE , MP4_ENCODE must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)),TRUE)
  COM_DEFS += DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
endif

ifdef SIP_SERIAL_FLASH_SIZE
  ifneq ($(strip $(SIP_SERIAL_FLASH_SIZE)),NONE)
    ifneq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      $(warning COMBO_MEMORY_SUPPORT must be TRUE when SIP_SERIAL_FLASH_SIZE is not NONE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef SIP_SERIAL_FLASH_SIZE
  ifeq ($(strip $(SIP_SERIAL_FLASH_SIZE)),24M_BITS)
    ifeq ($(strip $(OTP_SUPPORT)),TRUE)
      $(warning OTP_SUPPORT must be FALSE when SIP_SERIAL_FLASH_SIZE is 24M_BITS.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef SIP_SERIAL_FLASH_SIZE
  ifeq ($(strip $(SIP_SERIAL_FLASH_SIZE)),8M_BITS)
    ifneq ($(strip $(NORFLASH_NON_XIP_SUPPORT)),TRUE)
      $(warning ERROR: NORFLASH_NON_XIP_SUPPORT must be TRUE when SIP_SERIAL_FLASH_SIZE is 8M_BITS.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COM_DEFS    += __CSMCC_CALLCONFIRM_TIMER__

ifdef VIBRATION_SPEAKER_SUPPORT 
  VIBRATION_SPEAKER_SUPPORT_PLATFORM = MT6252 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(strip $(VIBRATION_SPEAKER_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(VIBRATION_SPEAKER_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support VIBRATION_SPEAKER_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __VIBRATION_SPEAKER_SUPPORT__
    COMPLIST += dp_engine
  endif
endif

# define MT6306/MT6302/AW6314 switch controller
SLIM_PROJECT = FALSE
ifneq ($(filter 128_128_SEG 128_64_SEG 64_32_SEG 32_32_SEG 32_64_SEG 64_64_SEG,$(PACKAGE_SEG)),)
  SLIM_PROJECT = TRUE
endif

ifneq ($(filter TRUE,$(SIM_SWTICH_CONTROLLER_MT6306)),)
  COM_DEFS += __SIM_DRV_SWITCH_MT6306__
  COMPLIST += mt6306
endif

ifeq ($(strip $(SLIM_PROJECT)),FALSE)
  COM_DEFS += __SIM_DRV_SWITCH_MT6302__
else
  ifneq ($(filter TRUE,$(SIM_SWTICH_CONTROLLER_MT6302)),)
    COM_DEFS += __SIM_DRV_SWITCH_MT6302__
  endif
endif

# before custom release, for GEMINIPLUS project(GEMINI 3/4), 
# need to turn on SIM_SWTICH_CONTROLLER_MT6302 or SIM_SWTICH_CONTROLLER_MT6306
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(filter 3 4 ,$(GEMINI)),)
    ifeq ($(filter __SIM_DRV_SWITCH_MT6302__ __SIM_DRV_SWITCH_MT6306__,$(COM_DEFS)),)
      $(warning ERROR: please set SIM_SWTICH_CONTROLLER_MT6302 = TRUE or SIM_SWTICH_CONTROLLER_MT6306 = TRUE for GEMINIPLUS project .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

aw6314_OBJ = $(shell dir .\custom\drv\misc_drv\$(strip $(BOARD_VER))\aw6314.lib /b 2>nul)
ifeq ($(strip $(SLIM_PROJECT)),TRUE)
  aw6314_OBJ = custom\drv\common_drv\aw6314.lib
  CUS_REL_OBJ_LIST  += custom\drv\common_drv\aw6314.lib
else
  ifeq ($(words $(strip $(aw6314_OBJ))),0)
    aw6314_OBJ = custom\drv\common_drv\aw6314.lib
    CUS_REL_OBJ_LIST  += custom\drv\common_drv\aw6314.lib
  else
    aw6314_OBJ = custom\drv\misc_drv\$(strip $(BOARD_VER))\aw6314.lib
    CUS_REL_OBJ_LIST  += custom\drv\misc_drv\$(strip $(BOARD_VER))\aw6314.lib
  endif
endif
COMPOBJS += $(aw6314_OBJ)

#MT6306_6252_SUPPORT_PLATFORM = MT6252
#MT6306_6253_SUPPORT_PLATFORM = MT6253 MT6253D
#MT6306_6235_SUPPORT_PLATFORM = MT6235B
#MT6306_6236_SUPPORT_PLATFORM = MT6236
MT6306_6256_SUPPORT_PLATFORM = MT6256
MT6306_6255_SUPPORT_PLATFORM = MT6255

#MT6306_SUPPORT_PLATFORM  = $(MT6306_6252_SUPPORT_PLATFORM)
#MT6306_SUPPORT_PLATFORM += $(MT6306_6253_SUPPORT_PLATFORM)
#MT6306_SUPPORT_PLATFORM += $(MT6306_6235_SUPPORT_PLATFORM)
#MT6306_SUPPORT_PLATFORM += $(MT6306_6236_SUPPORT_PLATFORM)
MT6306_SUPPORT_PLATFORM = $(MT6306_6256_SUPPORT_PLATFORM)
MT6306_SUPPORT_PLATFORM += $(MT6306_6255_SUPPORT_PLATFORM)

ifneq ($(strip $(SLIM_PROJECT)),TRUE)
#  ifneq ($(filter $(strip $(MT6306_6252_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
#    MT63062_OBJ = hal\storage\sim\mt6306\MT6252\mt63062.lib
#    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6252\mt63062.lib
#  endif
#  ifneq ($(filter $(strip $(MT6306_6253_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
#    MT63062_OBJ = hal\storage\sim\mt6306\MT6253\mt63062.lib
#    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6253\mt63062.lib
#  endif
#  ifneq ($(filter $(strip $(MT6306_6235_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
#    MT63062_OBJ = hal\storage\sim\mt6306\MT6235\mt63062.lib
#    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6235\mt63062.lib
#  endif
#  ifneq ($(filter $(strip $(MT6306_6236_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
#    MT63062_OBJ = hal\storage\sim\mt6306\MT6236\mt63062.lib
#    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6236\mt63062.lib
#  endif
  ifneq ($(filter $(strip $(MT6306_6256_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
    MT63062_OBJ = hal\storage\sim\mt6306\MT6256\mt63062.lib
    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6256\mt63062.lib
  endif
  ifneq ($(filter $(strip $(MT6306_6255_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
    MT63062_OBJ = hal\storage\sim\mt6306\MT6255\mt63062.lib
    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6255\mt63062.lib
  endif
  COMPOBJS += $(MT63062_OBJ)
else
  ifneq ($(filter $(strip $(MT6306_6250_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
    MT63062_OBJ = hal\storage\sim\mt6306\MT6250\mt63062.lib
    CUS_REL_OBJ_LIST += hal\storage\sim\mt6306\MT6250\mt63062.lib
  endif
  COMPOBJS += $(MT63062_OBJ)
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifeq ($(strip $(PHB_ADDITIONAL_SUPPORT)),TRUE)
    $(warning ERROR: when MMI_VERSION is NEPTUNE_MMI, please set PHB_ADDITIONAL_SUPPORT as FALSE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      $(warning ERROR: when FOTA_ENABLE is enabled , DCM_COMPRESSION_SUPPORT cannot be enabled .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: when NAND_FLASH_BOOTING is enabled , DCM_COMPRESSION_SUPPORT cannot be enabled .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS    += __DCM_WITH_COMPRESSION__
  COM_DEFS   +=  __VI_ENABLED__
endif

ifeq ($(strip $(DCM_COMPRESSION_MAUI_INIT)),TRUE)
  ifeq ($(strip $(DCM_COMPRESSION_SUPPORT)),FALSE)
    $(warning ERROR: when DCM_COMPRESSION_SUPPORT = FALSE , DCM_COMPRESSION_MAUI_INIT cannot be enabled .)
      DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __DYNAMIC_SWITCH_CACHEABILITY__,$(strip $(COM_DEFS))),)
    $(warning ERROR: when DCM_COMPRESSION_MAUI_INIT = TRUE , __DYNAMIC_SWITCH_CACHEABILITY__ must be enabled .)
      DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(DCM_MULTITRUNK)),NONE)
    $(warning ERROR: when DCM_MULTITRUNK = NONE , DCM_COMPRESSION_MAUI_INIT cannot be enabled .)
      DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS   += __DCM_WITH_COMPRESSION_MAUI_INIT__
endif

ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
  ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
    $(warning ERROR: CARD_DOWNLOAD only can be enabled, when MSDC_CARD_SUPPORT_TYPE != NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    $(warning ERROR: CARD_DOWNLOAD only can be enabled, when EMMC_BOOTING = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(AT_COMMAND_SET)),ULC)
       $(warning ERROR: PLease set AT_COMMAND_SET to SLIM or set CSD_SUPPORT  to NONE)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
  ifdef WIFI_AUTHENTICATION_LEVEL
    ifneq ($(strip $(WIFI_AUTHENTICATION_LEVEL)),WIFI_AUTHENTICATION_FULL_EAP)
      $(call DEP_ERR_SETA_OR_OFFB,WIFI_AUTHENTICATION_LEVEL,WIFI_AUTHENTICATION_FULL_EAP,WAPI_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(GOOGLE_SEARCH_SUPPORT)),TRUE)
  ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
    $(warning ERROR: GOOGLE_SEARCH_SUPPORT only can be enabled when BROWSER_SUPPORT != NONE.)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COMPLIST   +=  google_app
  COM_DEFS   +=  __GOOGLE_SEARCH_SUPPORT__
endif

DSP_SOLUTION_SUPPORT_PLATFORM = MT6276 MT6573 MT6575
ifneq ($(filter $(strip $(PLATFORM)) ,$(DSP_SOLUTION_SUPPORT_PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: DSP_SOLUTION must be DUALMACDSP,when PLATFORM is $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(NTPD_SUPPORT)),TRUE)
  ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,NTPD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS     += __NTPD_SUPPORT__
  COMPLIST     += ntpd
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COMP_TRACE_DEFS  += inet_ps\ntpd\include\ntpd_trc.h
  endif
endif

ifneq ($(filter __CTP_SHIFT_FOR_HVGA_LCM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __CTP_SHIFT_FOR_HVGA_LCM__ is only available for VICTOR56V12 MTK internal project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FAST_LOGO_SUPPORT)),TRUE)
  COM_DEFS    += __FAST_LOGO__
  COM_DEFS    += __LATCH_POWER_IN_BOOTLOADER__
endif

ifeq ($(strip $(FACEBOOK_CONTENT_SUPPORT)),TRUE)
  COM_DEFS += __FACEBOOK_CONTENT_SUPPORT__
endif

ifeq ($(strip $(EMS_SUPPORT)),EMS_ULC_SLIM)
  ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
        $(warning ERROR: MMI_VERSION must be PLUTO_MMI\COSMOS_MMI\IOT_MMI,when EMS_SUPPORT is set to EMS_ULC_SLIM)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,NAND_FLASH_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef EMMC_BOOTING
    ifneq ($(strip $(EMMC_BOOTING)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,EMMC_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,FOTA_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MCU_DORMANT_MODE)),TRUE)
  COM_DEFS += __MCU_DORMANT_MODE__
endif

ifeq ($(strip $(3D_ANAGLYPH)),TRUE)
  ifneq ($(strip $(MP4_DECODE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,3D_ANAGLYPH)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __VIDEO_3D_ANAGLYPH__
endif

ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  $(warning ERROR: Please turn off J2ME_SUPPORT .)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(SIM_RECOVERY_ENHANCEMENT)),TRUE)
  COM_DEFS    +=  __SIM_RECOVERY_ENHANCEMENT__
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    $(call DEP_ERR_SETA_OR_SETB,MMI_BASE,NEPTUNE_MMI,MMI_VERSION,non NEPTUNE_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifneq ($(strip $(MMI_BASE)),VENUS_MMI)
    $(call DEP_ERR_SETA_OR_SETB,MMI_BASE,VENUS_MMI,MMI_VERSION,non COSMOS_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  ifneq ($(strip $(MMI_BASE)),PLUTO_MMI)
    $(call DEP_ERR_SETA_OR_SETB,MMI_BASE,PLUTO_MMI,MMI_VERSION,non PLUTO_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  ifneq ($(strip $(MMI_BASE)),PLUTO_MMI)
    $(call DEP_ERR_SETA_OR_SETB,MMI_BASE,PLUTO_MMI,MMI_VERSION,non IOT_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifneq ($(strip $(MMI_BASE)),PLUTO_MMI)
    $(call DEP_ERR_SETA_OR_SETB,MMI_BASE,PLUTO_MMI,MMI_VERSION,non EMPTY_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(CBM_BEARER_SWITCH_SUPPORT)),TRUE)
  ifndef TCPIP_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_BEARER_SWITCH_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_BEARER_SWITCH_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS        +=   __CBM_BEARER_SWITCH__
endif

ifeq ($(strip $(MCU_DORMANT_MODE)),TRUE)
  ifeq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,CENTRALIZED_SLEEP_MANAGER,MCU_DORMANT_MODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DEMAND_PAGING_AUTO_CONFIG)),TRUE)
  ifeq ($(strip $(EMMC_BOOTING)),NONE)
    ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: please set DEMAND_PAGING_AUTO_CONFIG = FALSE in NOR project .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
  ifeq ($(strip $(IPERF_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_OFFB,IPERF_SUPPORT,DUAL,WAPI_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_BOOTUP_TRACE)),TRUE)
  ifdef SMART_PHONE_CORE
    ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
      $(warning ERROR: Smart Phone does not support USB_BOOTUP_TRACE!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __USB_BOOTUP_TRACE__
endif

ifneq ($(strip $(DEMO_PROJECT)),TRUE)
ifeq ($(strip $(DEMAND_PAGING_AUTO_CONFIG)),TRUE)
  ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
    EMMC_OR_NAND_FLASH_BOOTING_SUPPORT = TRUE
  endif
  ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
    EMMC_OR_NAND_FLASH_BOOTING_SUPPORT = TRUE
  endif
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    FOTA_OR_MULTIPLE_BINARY_FILES_SUPPORT = TRUE
  endif
  ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
    FOTA_OR_MULTIPLE_BINARY_FILES_SUPPORT = TRUE
  endif
  
  ifeq ($(strip $(EMMC_OR_NAND_FLASH_BOOTING_SUPPORT)),TRUE)
    ifeq ($(strip $(FOTA_OR_MULTIPLE_BINARY_FILES_SUPPORT)),TRUE)
      $(warning ERROR: PLEASE set DEMAND_PAGING_AUTO_CONFIG as FALSE when (EMMC_BOOTING == ONDEMAND or NAND_FLASH_BOOTING == ONDEMAND) and (FOTA_ENABLE==FOTA_DM or MULTIPLE_BINARY_FILES==TRUE) !)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
endif

ifeq ($(strip $(SIM_RECOVERY_ENHANCEMENT)),TRUE)
  ifdef SIM_HOT_SWAP
    ifneq ($(strip $(SIM_HOT_SWAP)), NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,SIM_RECOVERY_ENHANCEMENT,SIM_HOT_SWAP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

MDP_MULTIPLE_DISPLAY_BUFFER_PLATFORM = MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H MT6235 MT6268 MT6236 MT6276 MT6256 MT6255 MT6250 MT6922 MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(strip $(PLATFORM)),$(MDP_MULTIPLE_DISPLAY_BUFFER_PLATFORM)),)
  COM_DEFS    += __MDP_MULTIPLE_DISPLAY_BUFFER_SUPPORT__
endif

ifeq ($(strip $(AGPS_SUPPORT)),BOTH)
#  ifdef SOCKET_SSL_SUPPORT
#    ifneq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
#      $(warning ERROR: AGPS_SUPPORT can be set to BOTH ,only when SOCKET_SSL_SUPPORT = TRUE.)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
#  endif
endif
ifeq ($(strip $(AGPS_SUPPORT)),USER_PLANE)
  ifdef SOCKET_SSL_SUPPORT
#    ifneq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
#      $(warning ERROR: AGPS_SUPPORT can be set to USER_PLANE,only when SOCKET_SSL_SUPPORT = TRUE.)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
  endif
endif

ifeq ($(strip $(SIDE_BY_SIDE_3D_VIDEO)),ENABLE)
  COM_DEFS  += __VIDEO_3D_SIDE_BY_SIDE__
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COM_DEFS    += __LANG_NOTIFY_RES_BY_MMI__
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  COM_DEFS    += __LANG_NOTIFY_RES_BY_MMI__
endif

32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM = MT6255 MT6250 MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    COM_DEFS    +=  __F32_XOSC_REMOVAL_SUPPORT__
endif

ifdef SIP_RAM_SIZE
  ifneq ($(strip $(SIP_RAM_SIZE)),NONE)
    COM_DEFS  += __SIP_RAM_SIZE__
    COM_DEFS  += __SIP_RAM_SIZE_$(call Upper,$(strip $(SIP_RAM_SIZE)))__
  endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __R7_EHPLMN__,$(strip $(COM_DEFS))),)
    COM_DEFS += __SEARCH_ALL_EHPLMN_TOGETHER__
  endif
endif

ifeq ($(strip $(NVRAM_BIND_TO_CHIP_CIPHER)),ENABLE)
  ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
    $(warning ERROR: please enable NVRAM_BIND_TO_CHIP_CIPHER only when IC_TEST_TYPE is not set as IC_MODULE_TEST.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __NVRAM_BIND_TO_CHIP_CIPHER__
endif

ifdef BES_EQ_SUPPORT
  ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
    EQ_FLEX_SUPPORT_PLATFORM = MT6268 MT6236 MT6276 MT6255 MT6256 MT6250 MT6260 MT6261 MT2501 MT2502
    ifneq ($(filter $(strip $(NON_SW_EQ_SUPPORT_PLATFORM)),$(EQ_FLEX_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support FLEXIBLE_EQ.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(EQ_FLEX_SUPPORT_PLATFORM)),)
      COM_DEFS += __BES_EQ_FLEXIBLE_SUPPORT__
    endif
  endif
endif

ifdef SOCIAL_NETWORK_SUPPORT
  ifneq ($(strip $(SOCIAL_NETWORK_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifneq ($(findstring SEC,$(strip $(OBIGO_FEATURE))),)
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (MMI_VERSION == PLUTO_MMI and FINGER_TOUCH_SUPPORT != FTE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
        ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
          ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (MMI_VERSION == IOT_MMI and FINGER_TOUCH_SUPPORT != FTE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
        ifneq ($(findstring OPERA,$(strip $(BROWSER_SUPPORT))),)
          ifeq ($(strip $(SSL_SUPPORT)),NONE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (BROWSER use OPERA and SSL_SUPPORT == NONE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
          ifeq ($(strip $(SOCKET_SSL_SUPPORT)),FALSE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (BROWSER use OPERA and SOCKET_SSL_SUPPORT == FALSE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      else
        $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (OBIGO_FEATURE without SEC) !)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      ifeq ($(strip $(WAP_MMS_FEATURES)),ULTRA_SLIM)
        $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (WAP_MMS_FEATURES is ULTRA_SLIM) !)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (MMI_VERSION == PLUTO_MMI and FINGER_TOUCH_SUPPORT != FTE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
        ifneq ($(findstring OPERA,$(strip $(BROWSER_SUPPORT))),)
          ifeq ($(strip $(SSL_SUPPORT)),NONE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (BROWSER use OPERA and SSL_SUPPORT == NONE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
          ifeq ($(strip $(SOCKET_SSL_SUPPORT)),FALSE)
            $(warning ERROR: PLEASE set SOCIAL_NETWORK_SUPPORT = NONE when (BROWSER use OPERA and SOCKET_SSL_SUPPORT == FALSE) !)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif     
      endif
    endif
    ifeq ($(strip $(TWITTER_SNS_SUPPORT)),TRUE)
      ifeq ($(strip $(CHE_SUPPORT)),FALSE)
        $(warning ERROR: PLEASE set TWITTER_SNS_SUPPORT = FALSE when (CHE_SUPPORT != TRUE) !)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(JPG_DECODE_PROGRESSIVE_CAPABILITY)),BASELINE)
      $(warning ERROR: PLEASE set JPG_DECODE_PROGRESSIVE_CAPABILITY = PROGRESSIVE_1M)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(JPG_DECODE_PROGRESSIVE_CAPABILITY)),PROGRESSIVE_03M)
      $(warning ERROR: PLEASE set JPG_DECODE_PROGRESSIVE_CAPABILITY = PROGRESSIVE_1M)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST  += sns snsapp
    COM_DEFS  += __SOCIAL_NETWORK_SUPPORT__
  endif
endif

ifeq ($(strip $(PNG_DECODE)),NONE)
  ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    ifeq ($(strip $(FACEBOOK_CONTENT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,PNG_DECODE,FACEBOOK_CONTENT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter MT6276 MT6573 MT6575,$(PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: please set DSP_SOLUTION = DUALMACDSP, when PLATFORM = $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter MT6276 MT6573 MT6575,$(PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: please set DSP_SOLUTION = DUALMACDSP, when PLATFORM = $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  COM_DEFS   += __FS_AUTO_CONFIG_SUPPORT__
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    COM_DEFS   += __FS_AUTO_CONFIG_SUPPORT__
  endif
endif

ifeq ($(filter __FS_ON__,$(COM_DEFS)),)
  ifeq ($(strip $(CHE_INPUT_FROM_FSAL)),TRUE)
    $(warning ERROR: Please define CHE_INPUT_FROM_FSAL = FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_DATA_CONNECTION_SUPPORT)),TRUE)
  COM_DEFS   += __USB_DATA_CONNECTION__
  COM_DEFS    += __USB_MASS_STORAGE_CDROM_ENABLE__
  ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
    $(warning ERROR: please set USB_COM_PORT_SUPPORT = TRUE, when USB_DATA_CONNECTION_SUPPORT = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
    $(warning ERROR: please set USB_MASS_STORAGE_SUPPORT = TRUE, when USB_DATA_CONNECTION_SUPPORT = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef MODEM_CARD
  ifneq ($(strip $(MODEM_CARD)),NONE)
    $(warning ERROR: please set MODEM_CARD = NONE, when USB_DATA_CONNECTION_SUPPORT = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  endif
endif

ifeq ($(strip $(WCDMA_PREFERRED)),TRUE)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS        += __WCDMA_PREFERRED__
    COM_DEFS        += __UMTS_FDD_PREFER__
  endif
endif

ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
  ifeq ($(strip $(LARGE_MIDI_FILE_SUPPORT)),TRUE)
    $(warning ERROR: please turn off LARGE_MIDI_FILE_SUPPORT when AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

COM_DEFS        += __UMTS_TDD128_SNIFFER__

ifeq ($(strip $(MMI_IME_V3_SUPPORT)),TRUE)
  COM_DEFS += MMI_IME_V3_SUPPORT
endif

ifeq ($(strip $(HD_RECORD_SUPPORT)),TRUE)
  COM_DEFS  +=  __HD_RECORD__
endif

ifeq ($(strip $(GAMELOFT_CONTENT_SUPPORT)),TRUE)
  COM_DEFS     +=  __GAMELOFT_CONTENT_SUPPORT__
endif

COMPLIST += sys_sec sleep_drv
COMMINCDIRS += mre\commoninc

ifeq ($(strip $(USB_TETHERING)),TRUE)
  ifdef USB_MULTIPLE_COMPORT_ENABLE
    ifneq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
      $(warning ERROR: please turn on USB_MULTIPLE_COMPORT_ENABLE when USB_TETHERING = TRUE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

FDD_RF_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6276 MT6573 MT6575 MT6577
ifeq ($(strip $(FDD_RF_CUSTOM_TOOL_SUPPORT)),FALSE)
  ifneq ($(filter $(strip $(PLATFORM)),$(FDD_RF_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    $(warning ERROR: FDD_RF_CUSTOM_TOOL_SUPPORT can NOT be FALSE when PLATFORM = $(strip $(PLATFORM)) .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
2G_RF_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6276 MT6573 MT6575 MT6577
ifeq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),FALSE)
  ifneq ($(filter $(strip $(PLATFORM)),$(2G_RF_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    $(warning ERROR: 2G_RF_CUSTOM_TOOL_SUPPORT can NOT be FALSE when PLATFORM = $(strip $(PLATFORM)) .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(NAND_SUPPORT)),TRUE)
  ifneq ($(filter __AST3001__,$(COM_DEFS)),)
    COM_DEFS  += __AST_L1_LOGGING_IN_LISR__
  endif
endif

ifeq ($(strip $(PNS_SUPPORT)),TRUE)
  COM_DEFS  += PNS_SUPPORT
  COMPLIST  += push_engine
  COMP_TRACE_DEFS  +=  vendor\push_notification_engine\HPNSTask\inc\pns_trc.h
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,PNS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  COM_DEFS += __CMCC_STD_FR__
endif

ifeq ($(strip $(TWITTER_CONTENT_SUPPORT)),TRUE)
  COM_DEFS     +=  __TWITTER_CONTENT_SUPPORT__
endif

ifdef ATV_SUPPORT
  ifneq ($(strip $(ATV_SUPPORT)),FALSE)
    ifdef CMMB_SUPPORT
      ifneq ($(strip $(CMMB_SUPPORT)),NONE)
        $(call DEP_ERR_OFFA_OR_OFFB,ATV_SUPPORT,CMMB_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(KEYPAD_TYPE)),NORMAL_KEYPAD)
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    ifeq ($(strip $(MAIN_LCD_SIZE)),480X800)
      $(warning ERROR:Normal Keypad cannot be support on WVGA+Cosmos projects .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DCM_ENABLE_SUPPORT_PLATFORM = MT6255 MT6250 MT6256
ifneq ($(strip $(MCU_DCM)),DCM_ENABLE)
  ifneq ($(filter $(DCM_ENABLE_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    $(warning ERROR: PLEASE set MCU_DCM as DCM_ENABLE on $(strip $(PLATFORM)) project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(EXT_BL_UPDATE_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    $(warning ERROR: USB_DOWNLOAD_IN_BL cannot be NONE when EXT_BL_UPDATE_SUPPORT = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
    COM_DEFS  += __EXT_BL_UPDATE__
endif

ifdef FACEBOOK_SNS_SUPPORT
  ifeq ($(strip $(FACEBOOK_SNS_SUPPORT)),TRUE)
    ifeq ($(strip $(SOCIAL_NETWORK_SUPPORT)),NONE)
      $(warning ERROR: PLEASE NOT set SOCIAL_NETWORK_SUPPORT = NONE when (FACEBOOK_SNS_SUPPORT = TRUE) !)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef TWITTER_SNS_SUPPORT
  ifeq ($(strip $(TWITTER_SNS_SUPPORT)),TRUE)
    ifeq ($(strip $(SOCIAL_NETWORK_SUPPORT)),NONE)
      $(warning ERROR: PLEASE NOT set SOCIAL_NETWORK_SUPPORT = NONE when (TWITTER_SNS_SUPPORT = TRUE) !)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(TWITTER_SNS_SUPPORT)),TRUE)
  COM_DEFS += __TWITTER_SNS_SUPPORT__
endif
ifeq ($(strip $(FACEBOOK_SNS_SUPPORT)),TRUE)
  COM_DEFS += __FACEBOOK_SNS_SUPPORT__
endif
ifeq ($(strip $(SOCIAL_NETWORK_SUPPORT)),LIB)
  COM_DEFS += __SNS_APPKEY_SUPPORT__
endif

ALICE_SUPPORT_PLATFORM = MT6250 MT6260 MT6261 MT2501 MT2502
ifndef ALICE_SUPPORT
  ALICE_SUPPORT = FALSE
  ifneq ($(filter $(ALICE_SUPPORT_PLATFORM), $(PLATFORM)),)
    ALICE_SUPPORT = TRUE
  endif
endif

ifeq ($(filter $(ALICE_SUPPORT_PLATFORM), $(PLATFORM)),)
  ifneq ($(strip $(ALICE_SUPPORT)),FALSE)
    $(warning ERROR: PLEASE turn off ALICE_SUPPORT on $(PLATFORM))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
  ifneq ($(strip $(INSIDE_MTK)),1)
    ifneq ($(strip $(MTK_INTERNAL)),TRUE)
      $(warning ERROR: PLEASE turn off DUMMY_SCATTER_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(ALICE_SUPPORT)),TRUE)
  COM_DEFS    +=  __ALICE_SUPPORT__
  COM_DEFS    += __VI_ENABLED__
  COMPOBJS          += hal\system\sys_lib\lib\sys_lib_a.lib
  CUS_REL_OBJ_LIST  += hal\system\sys_lib\lib\sys_lib_a.lib
endif


ifneq ($(strip $(PLATFORM)),MT6252)
  ifeq ($(strip $(ATV_CHIP)),VER00)
    $(warning ERROR: PLEASE set ATV_CHIP as VER01 when ATV_SUPPORT = $(ATV_SUPPORT) .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_TETHERING)),TRUE)
  ifeq ($(filter $(COM_DEFS),__PS_SERVICE__),)
    $(warning ERROR: USB tethering cannot be supported on GSM projects .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MCARE_SUPPORT)),TRUE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,MCARE_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COMPLIST += tencentmcarev31adp
  ifneq ($(filter __TENCENTMCAREV31_ONLY_QQ2010__,$(COM_DEFS)),)
    COMPOBJS += vendor\mcare\Engine\RVCT\tencentmcarev31_QQ2010.lib
  else
    ifneq ($(filter __TENCENTMCAREV31_QQ2010_SINGLE_INST__,$(COM_DEFS)),)
      COMPOBJS += vendor\mcare\Engine\RVCT\tencentmcarev31_SINGLE_INST.lib
    else
      COMPOBJS += vendor\mcare\Engine\RVCT\tencentmcarev31.lib
    endif
  endif
  CUS_REL_OBJ_LIST += vendor\mcare\Engine\RVCT\tencentmcarev31.lib
  CUS_REL_OBJ_LIST += vendor\mcare\Engine\RVCT\tencentmcarev31_QQ2010.lib  
  CUS_REL_OBJ_LIST += vendor\mcare\Engine\RVCT\tencentmcarev31_SINGLE_INST.lib  
  COM_DEFS   +=  __MCAREV31__ __MCARE_COMMON__
  COMMINCDIRS += vendor\mcare\adaption
  COMMINCDIRS += vendor\mcare\adaption\api
  COMMINCDIRS += vendor\mcare\adaption\api\inc
endif

ifndef MRE_CONTENT_NUMBER
  MRE_CONTENT_NUMBER = 40
endif
ifdef MRE_CONTENT_NUMBER
  COM_DEFS     += __MRE_CONTENT_NUMBER__=$(strip $(MRE_CONTENT_NUMBER))
endif

ifeq ($(strip $(MOT_SUPPORT)),TRUE)
  COM_DEFS += __MOT_SUPPORT__
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  COM_DEFS += __GSMCDMA_DUALSIM__
endif

ifeq ($(strip $(VCARD_CLOUD_SUPPORT)),TRUE)
  ifneq ($(strip $(CARDAV_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_OFFB,CARDAV_SUPPORT,TRUE,VCARD_CLOUD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(VCARD_SUPPORT)),MULTIPLE)
    $(warning ERROR:Please turn off VCARD_CLOUD_SUPPORT or set VCARD_SUPPORT = MULTIPLE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __VCARD_CLOUD_SUPPORT__
endif

ifeq ($(strip $(SMS_CLOUD_SUPPORT)),TRUE)
  ifneq ($(strip $(EMAIL_SUPPORT)),ALL)
    $(call DEP_ERR_SETA_OR_OFFB,EMAIL_SUPPORT,ALL,SMS_CLOUD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __SMS_CLOUD_SUPPORT__
endif

ifeq ($(strip $(CARDAV_SUPPORT)),TRUE)
  ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,CARDAV_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(CLOUD_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_OFFB,CLOUD_SUPPORT,SOURCE\LIB,CARDAV_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS    += __CARDAV_SUPPORT__
  COMP_TRACE_DEFS += inet_ps\cardav\include\cardav_trc.h
  COMPLIST    += cardav
endif


ifeq ($(strip $(CAT_IN_ZIMAGE)),TRUE)
  ifeq ($(strip $(CAT_SUPPORT)),NONE)
    $(warning ERROR: If CAT_IN_ZIMAGE is TRUE, then CAT_SUPPORT can not be NONE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
    $(warning ERROR: If CAT_IN_ZIMAGE is TRUE, then ZIMAGE_SUPPORT can not be FALSE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(NVRAM_BACKUP_PARTITION_ON_NOR)),ENABLE)
    ifeq ($(strip $(SDS_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,NVRAM_BACKUP_PARTITION_ON_NOR,SDS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),FALSE)
      $(warning ERROR: when SERIAL_FLASH_SUPPORT=FALSE NVRAM_BACKUP_PARTITION_ON_NOR must be FALSE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __NOR_SUPPORT_RAW_DISK__ __SYSDRV_BACKUP_DISK__ __SYSDRV_BACKUP_DISK_RAW__ __NVRAM_BACKUP_PARTITION__ __AT_BACKUP_DATA_SUPPORT__
endif

ifndef CAT_SUPPORT
  CAT_SUPPORT = NONE
else
  ifneq ($(strip $(CAT_SUPPORT)),NONE)
    COM_DEFS  += __CAT_SUPPORT__
    ifneq ($(filter --no_debug,$(LNKOPT)),)
      $(warning ERROR: Cannot define --no_debug link option when CAT_SUPPORT is $(strip $(CAT_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
      $(warning ERROR: Please set MULTIPLE_BINARY_FILES as FALSE when CAT_SUPPORT is $(strip $(CAT_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(warning ERROR: Please set SECURE_SUPPORT as FALSE when CAT_SUPPORT is $(strip $(CAT_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter FULL LIMITED_ONLINE_MODE,$(strip $(CAT_SUPPORT))),)
      ifneq ($(strip $(AT_COMMAND_SET)),SLIM)
        ifneq ($(strip $(AT_COMMAND_SET)),FULL)
          $(warning ERROR: Please set AT_COMMAND_SET as SLIM or FULL when CAT_SUPPORT is $(strip $(CAT_SUPPORT)))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(DT_SUPPORT)),TRUE)
        $(warning ERROR: Please set DT_SUPPORT as TRUE when CAT_SUPPORT is $(strip $(CAT_SUPPORT)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(CAT_SUPPORT)),FULL)
        ifneq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),ON)
          $(warning ERROR: Please set GDI_SCREEN_SHOT_BUFFER as ON when CAT_SUPPORT is $(strip $(CAT_SUPPORT)))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      COM_DEFS  += __CAT_ONLINE_MODE__
    endif
  endif
endif

ifeq ($(strip $(BOOT_ZIMAGE_SUPPORT)),TRUE)
    ifneq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ZIMAGE_SUPPORT,BOOT_ZIMAGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ALICE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ALICE_SUPPORT,BOOT_ZIMAGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(ZIMAGE_CONTENT_POLICY)),MUST_ONLY)
      $(call DEP_ERR_SETA_OR_OFFB,ZIMAGE_CONTENT_POLICY, not MUST_ONLY, BOOT_ZIMAGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    +=  __BOOT_ZIMAGE_SUPPORT__
    COM_DEFS    +=  __VI_ENABLED__
endif

ifdef CTM_SUPPORT
  ifeq ($(strip $(CTM_SUPPORT)), TRUE)
    ifeq ($(strip $(MMI_VERSION)), COSMOS_MMI)
      $(warning ERROR: Please set CTM_SUPPORT=FALSE for COSMOS!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef CMMB_CAS_2GPP_VER
  ifneq ($(strip $(CMMB_CAS_2GPP_VER)),NONE)
    ifeq ($(strip $(CMMB_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_2GPP_VER)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMMB_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_2GPP_VER)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMMB_CAS_2GPP_VER)),V10)
      COM_DEFS     += CMMB_CAS_2GPP_V10
#CMMB 2GPP Vendor IBOI lib
      COMPOBJS         += vendor\cmmb\iboi\lib\iboi.o
      CUS_REL_OBJ_LIST += vendor\cmmb\iboi\lib\iboi.o
      COMPOBJS         += vendor\cmmb\adp\lib\cmmb_authen.lib
      CUS_REL_OBJ_LIST += vendor\cmmb\adp\lib\cmmb_authen.lib
    endif
  endif
endif

ifeq ($(strip $(DCM_DEBUG_SUITE_ENABLE)),TRUE)
  COM_DEFS += __DCM_DEBUG_SUITE_ENABLE__
endif
##############rule_1
# ifeq ($(strip $(PLATFORM)),MT6276)
  # ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    # ifeq ($(filter MT6162_RF,$(strip $(COM_DEFS))),)
      # $(warning ERROR: please define MT6162_RF when PLATFORM = MT6276 & UMTS_MODE_SUPPORT = UMTS_FDD_MODE_SUPPORT.)
      # DEPENDENCY_CONFLICT = TRUE
    # endif
  # endif
# endif
##############rule_2
ifneq ($(filter MT6573 MT6575,$(PLATFORM)),)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    ifeq ($(filter MT6162_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define MT6162_RF when PLATFORM = MT6573\MT6575 & UMTS_MODE_SUPPORT = UMTS_FDD_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
      $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6573\MT6575 & UMTS_MODE_SUPPORT = UMTS_FDD_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
##############rule_3
ifeq ($(strip $(PLATFORM)),MT6573)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    ifeq ($(filter AD6546_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define AD6546_RF&MT6161_RF when PLATFORM = MT6573 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter MT6161_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define AD6546_RF&MT6161_RF when PLATFORM = MT6573 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
      $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6573 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
##############rule_4
ifeq ($(strip $(PLATFORM)),MT6575)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    ifeq ($(filter MT6140D_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define MT6140D_RF&MT6161_RF when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter MT6161_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define MT6140D_RF&MT6161_RF when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
      $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
##############rule_5
ifeq ($(strip $(PLATFORM)),MT6573)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifneq ($(filter MT6162_RF AD6548_RF AD6546_RF,$(strip $(COM_DEFS))),)
      ifneq ($(filter AD6548_RF AD6546_RF,$(strip $(COM_DEFS))),)
        ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
          $(warning ERROR: please set AFC_VCXO_TYPE as VCXO, when PLATFORM = MT6573 & UMTS_MODE_SUPPORT = NONE & AD6548_RF\AD6546_RF is defined.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
          $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6573 & UMTS_MODE_SUPPORT = NONE & MT6162_RF is defined.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    else
      $(warning ERROR: please define MT6162_RF\AD6548_RF\AD6546_RF, when PLATFORM = MT6573 & UMTS_MODE_SUPPORT = NONE .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
##############rule_6
ifeq ($(strip $(PLATFORM)),MT6575)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifneq ($(filter MT6162_RF AD6548_RF MT6140D_RF,$(strip $(COM_DEFS))),)
      ifneq ($(filter AD6548_RF MT6140D_RF,$(strip $(COM_DEFS))),)
        ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
          $(warning ERROR: please set AFC_VCXO_TYPE as VCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = NONE & AD6548_RF\MT6140D_RF is defined.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
          $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = NONE & MT6162_RF is defined.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    else
      $(warning ERROR: please define MT6162_RF\AD6548_RF\MT6140D_RF, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = NONE .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION )),PLUTO_MMI)
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    ifeq ($(strip $(SUPPORT_JSR_177)),TRUE)
       DEPENDENCY_CONFLICT = TRUE
       $(warning ERROR: SUPPORT_JSR_177 can not be turned on under FTE .)
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION )),IOT_MMI)
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    ifeq ($(strip $(SUPPORT_JSR_177)),TRUE)
       DEPENDENCY_CONFLICT = TRUE
       $(warning ERROR: SUPPORT_JSR_177 can not be turned on under FTE .)
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION )),PLUTO_MMI)
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    ifeq ($(strip $(SUPPORT_JSR_257)),TRUE)
       DEPENDENCY_CONFLICT = TRUE
       $(warning ERROR: SUPPORT_JSR_257 can not be turned on under FTE .)
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION )),IOT_MMI)
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    ifeq ($(strip $(SUPPORT_JSR_257)),TRUE)
       DEPENDENCY_CONFLICT = TRUE
       $(warning ERROR: SUPPORT_JSR_257 can not be turned on under FTE .)
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION )),PLUTO_MMI)
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    ifdef ($(NFC_SUPPORT))
      ifneq ($(strip $(NFC_SUPPORT)),NONE)
        DEPENDENCY_CONFLICT = TRUE
        $(warning ERROR: NFC_SUPPORT can not be turned on under FTE .)
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION )),IOT_MMI)
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    ifdef ($(NFC_SUPPORT))
      ifneq ($(strip $(NFC_SUPPORT)),NONE)
        DEPENDENCY_CONFLICT = TRUE
        $(warning ERROR: NFC_SUPPORT can not be turned on under FTE .)
      endif
    endif
  endif
endif

ifeq ($(strip $(DCM_COMPRESSION_AUDIO_BT)),TRUE)
  ifneq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DCM_COMPRESSION_SUPPORT,DCM_COMPRESSION_AUDIO_BT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(BT_A2DP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_A2DP_PROFILE,DCM_COMPRESSION_AUDIO_BT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS   += __DCM_WITH_COMPRESSION_AUDIO_BT__
endif

ifeq ($(strip $(DCM_COMPRESSION_AUDIO_CODEC)),TRUE)
  ifneq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DCM_COMPRESSION_SUPPORT,DCM_COMPRESSION_AUDIO_CODEC)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS   += __DCM_WITH_COMPRESSION_AUDIO_CODEC__
endif

ifeq ($(strip $(DCM_COMPRESSION_AUDIO_EFFECT)),TRUE)
  ifneq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DCM_COMPRESSION_SUPPORT,DCM_COMPRESSION_AUDIO_EFFECT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(BES_LOUDNESS_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BES_LOUDNESS_SUPPORT,DCM_COMPRESSION_AUDIO_EFFECT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS   += __DCM_WITH_COMPRESSION_AUDIO_EFFECT__
endif

# DCM_COMPRESSION_SUPPORT dependency rule check
ifdef DCM_COMPRESSION_SUPPORT
ifeq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
  DCM_COMPRESSION_DEP_CHECK_OK = FALSE

  ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
    ifeq ($(strip $(DCM_COMPRESSION_AUDIO_BT)),TRUE)
      DCM_COMPRESSION_DEP_CHECK_OK = TRUE
    endif
  endif

  ifeq ($(strip $(BES_LOUDNESS_SUPPORT)),TRUE)
    ifeq ($(strip $(DCM_COMPRESSION_AUDIO_EFFECT)),TRUE)
      DCM_COMPRESSION_DEP_CHECK_OK = TRUE
    endif
  endif

  ifeq ($(strip $(MP4_DECODE_PROFILE)),SP)
    DCM_COMPRESSION_DEP_CHECK_OK = TRUE
  endif

  ifeq ($(strip $(H264_DECODE)),TRUE)
    DCM_COMPRESSION_DEP_CHECK_OK = TRUE
  endif

  ifeq ($(strip $(MP4_ENCODE)),TRUE)
    DCM_COMPRESSION_DEP_CHECK_OK = TRUE
  endif

  ifeq ($(strip $(MP4_DECODE_PROFILE)),ASP)
    DCM_COMPRESSION_DEP_CHECK_OK = TRUE
  endif

  ifeq ($(strip $(VP8_DECODE)),TRUE)
    DCM_COMPRESSION_DEP_CHECK_OK = TRUE
  endif

  ifeq ($(strip $(VIDEO_PLAYER_RECORDER_W_DCM)),ENABLE)
    DCM_COMPRESSION_DEP_CHECK_OK = TRUE
  endif

  ifeq ($(strip $(DAF_DECODE)),TRUE)    
    ifeq ($(strip $(DCM_COMPRESSION_AUDIO_CODEC)),TRUE)
      ifeq ($(strip $(PLATFORM)),MT6250)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
      ifeq ($(strip $(PLATFORM)),MT6260)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
      ifeq ($(strip $(PLATFORM)),MT6261)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
      ifeq ($(strip $(PLATFORM)),MT2501)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
      ifeq ($(strip $(PLATFORM)),MT2502)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
    endif
  endif

  ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
    ifeq ($(strip $(DCM_COMPRESSION_AUDIO_CODEC)),TRUE)
      ifeq ($(strip $(PLATFORM)),MT6250)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
      ifeq ($(strip $(PLATFORM)),MT6260)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
      ifneq ($(filter MT6261 MT2501 MT2502, $(strip $(PLATFORM))),)
        DCM_COMPRESSION_DEP_CHECK_OK = TRUE
      endif
    endif
  endif

  ifeq ($(strip $(DCM_COMPRESSION_DEP_CHECK_OK)),FALSE)
    $(warning ERROR: PLEASE turn off DCM_COMPRESSION_SUPPORT or)
    $(warning ERROR:  1. PLEASE set BT_A2DP_PROFILE to TRUE and set DCM_COMPRESSION_AUDIO_BT to TRUE or)
    $(warning ERROR:  2. PLEASE set BES_LOUDNESS_SUPPORT to TRUE and set DCM_COMPRESSION_AUDIO_EFFECT to TRUE or)
    $(warning ERROR:  3. PLEASE set MP4_DECODE_PROFILE to SP or)
    $(warning ERROR:  4. PLEASE set H264_DECODE to TRUE or)
    $(warning ERROR:  5. PLEASE set MP4_ENCODE to TRUE or)
    $(warning ERROR:  6. PLEASE set MP4_DECODE_PROFILE to ASP or)
    $(warning ERROR:  7. PLEASE set VP8_DECODE to TRUE or)
    $(warning ERROR:  8. PLEASE set VIDEO_PLAYER_RECORDER_W_DCM to ENABLE or)
    $(warning ERROR:  9. PLEASE set DAF_DECODE to TRUE and set DCM_COMPRESSION_AUDIO_CODEC to TRUE and set PLATFORM to MT6250/MT6260/MT6261/MT2501/MT2502 or)
    $(warning ERROR: 10. PLEASE set MELODY_VER to DSP_WT_SYN and set DCM_COMPRESSION_AUDIO_CODEC to TRUE and set PLATFORM to MT6250/MT6260/MT6261/MT2501/MT2502)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif
# End DCM_COMPRESSION_SUPPORT dependency rule check

ifdef DCM_COMPRESSION_MMI_SUPPORT
ifneq ($(strip $(DCM_COMPRESSION_MMI_SUPPORT)),NONE)
  ifneq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DCM_COMPRESSION_SUPPORT,DCM_COMPRESSION_MMI_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter 32_32_SEG 24_32_SEG 16_32_SEG,$(PACKAGE_SEG)),)
    $(warning ERROR: PLEASE set DCM_COMPRESSION_MMI_SUPPORT to NONE, DCM_COMPRESSION_MMI_SUPPORT only can be turn on when PACKAGE_SEG = 32_32_SEG and below)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(DCM_COMPRESSION_MMI_SUPPORT)),DCM_AP_ONLY)
    COM_DEFS   += __DCM_WITH_COMPRESSION_MMI_AP__
  endif  
endif
endif

ifdef CLOUD_SUPPORT
  ifneq ($(strip $(CLOUD_SUPPORT)),NONE)
    ifneq ($(strip $(CLOUD_SUPPORT)),FALSE)
      ifeq ($(strip $(CLOUD_SUPPORT)),LIB)
        COMPLIST   += sso
      endif
      COM_DEFS     += __CLOUD_SUPPORT__
    endif
    ifeq ($(strip $(WAP_MMS_FEATURES)),NONE)
      ifdef OBIGO_FEATURE
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,CLOUD_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,CLOUD_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif  
  endif
endif

ifdef SMS_TCARD_ENTRY
  COM_DEFS    += SMS_TCARD_ENTRY=$(strip $(SMS_TCARD_ENTRY))
endif

ifdef PHB_TCARD_ENTRY
  COM_DEFS    += MAX_PHB_TCARD_ENTRY=$(strip $(PHB_TCARD_ENTRY))
endif

ifeq ($(strip $(BES_LOUDNESS_SUPPORT)),TRUE)
    COM_DEFS += __BES_LOUDNESS_V4_SUPPORT__
endif

ifeq ($(strip $(TIME_LAPSE_VIDEO_RECORDER)),ENABLE)
  ifeq ($(filter $(strip $(PLATFORM)), MT6250 MT6255 MT6260 MT6261 MT2501 MT2502),)
    $(warning ERROR: please disable TIME_LAPSE_VIDEO_RECORDER when PLATFORM is not MT6250 or MT6255 or MT6260 or MT6261 or MT2501 or MT2502)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(MMI_FEATURES_SWITCH)),FALSE)
      ifneq ($(strip $(CAMCORDER_SUPPORT)),NONE)
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
            $(warning ERROR: Only supported  FINGER_TOUCH_SUPPORT = FTE when TIME_LAPSE_VIDEO_RECORDER = ENABLE and MMI_VERSION = PLUTO_MMI)
            $(warning ERROR: MMI_VERSION = $(MMI_VERSION)  FINGER_TOUCH_SUPPORT = $(FINGER_TOUCH_SUPPORT))
            DEPENDENCY_CONFLICT = TRUE
          endif
        else
          ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
            $(warning ERROR: Only supported on COSOS_PLUTOMMI or PLUTO_MMI and FTE platform when TIME_LAPSE_VIDEO_RECORDER = ENABLE)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
        ifneq ($(strip $(MJPG_ENCODE)),TRUE)
          ifneq ($(strip $(MP4_ENCODE)),TRUE)
            ifneq ($(strip $(H264_ENCODE)),TRUE)
              $(warning ERROR: please set MJPG_ENCODE or MP4_ENCODE or H264_ENCODE as TRUE when TIME_LAPSE_VIDEO_RECORDER = ENABLE)
              DEPENDENCY_CONFLICT = TRUE
            endif
           endif
        endif
      endif
    endif
  endif
endif


ifeq ($(strip $(TIME_LAPSE_VIDEO_RECORDER)),ENABLE)
  COM_DEFS += __TIME_LAPSE_VIDEO_RECORDER__
endif
ifeq ($(strip $(PLATFORM)),MT6250)
  ifeq ($(strip $(SIP_RAM_SIZE)),32M_BITS)
    COM_DEFS += __32M_RAM__
  endif
  ifeq ($(strip $(SIP_SERIAL_FLASH_SIZE)),32M_BITS)
    COM_DEFS += __32M_ROM__
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6260)
  ifeq ($(strip $(SIP_RAM_SIZE)),32M_BITS)
    COM_DEFS += __32M_RAM__
  endif
  ifeq ($(strip $(SIP_SERIAL_FLASH_SIZE)),32M_BITS)
    COM_DEFS += __32M_ROM__
  endif
endif
ifneq ($(filter MT6261 MT2501 MT2502,$(strip $(PLATFORM))),)
  ifeq ($(strip $(SIP_RAM_SIZE)),32M_BITS)
    COM_DEFS += __32M_RAM__
  endif
  ifeq ($(strip $(SIP_SERIAL_FLASH_SIZE)),32M_BITS)
    COM_DEFS += __32M_ROM__
  endif
endif
ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X480)
   ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
           COM_DEFS += __COSMOS_SLIM_ASM3X_PROFILE__
      endif
   endif
endif

ifdef FONT_ENGINE
  ifeq ($(strip $(FONT_ENGINE)),NONE)
    ifeq ($(strip $(MMI_IME_V3_SUPPORT)),TRUE)
      ifneq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320)
        ifneq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X240)
          ifneq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X400)
            $(warning ERROR: Please turn off MMI_IME_V3_SUPPORT when FONT_ENGINE is NONE!)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifdef CAMCORDER_SUPPORT
ifneq ($(strip $(CAMCORDER_SUPPORT)),NONE)
  ifeq ($(strip $(HORIZONTAL_CAMERA)),FALSE)
    ifneq ($(filter __CAMCO_QUICK_VIEW_ROTATE_SHRAE_APP_MEM__,$(COM_DEFS)),)
      $(warning ERROR: PLEASE disable __CAMCO_QUICK_VIEW_ROTATE_SHRAE_APP_MEM__ on project makefile when HORIZONTAL_CAMERA = FALSE & CAMCORDER_SUPPORT is enabled .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
endif

ifeq ($(strip $(MRE_BG_CONC_LAUNCHER)),TRUE)
  COM_DEFS += __MRE_BG_CONC_LAUNCHER__
endif

ifeq ($(strip $(FS_CACHE_SUPPORT)),TRUE)
  ifneq ($(strip $(FS_DEDICATED_BUFFER)),TRUE)
    $(warning ERROR: Please set FS_DEDICATED_BUFFER = TRUE when FS_CACHE_SUPPORT is enabled.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  += __FS_CACHE_SUPPORT__
endif

ifeq ($(strip $(MMI_IME_V3_SUPPORT)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: PLEASE set MMI_IME_V3_SUPPORT = FALSE when (MMI_VERSION == PLUTO_MMI and FINGER_TOUCH_SUPPORT != FTE) !)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MMI_IME_V3_SUPPORT)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: PLEASE set MMI_IME_V3_SUPPORT = FALSE when (MMI_VERSION == IOT_MMI and FINGER_TOUCH_SUPPORT != FTE) !)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

GAS_SUPPORT_SUPPORT = MT6250 MT6260 MT6261 MT2501 MT2502
ifeq ($(strip $(GAS_SUPPORT)),TRUE)
  ifeq ($(filter $(strip $(PLATFORM)), $(strip $(GAS_SUPPORT_SUPPORT))),)
      $(warning ERROR: GAS_SUPPORT can be only supported on $(GAS_SUPPORT_SUPPORT))
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GAS_SUPPORT)),TRUE)
  COM_DEFS  += __GAS_SUPPORT__ 
endif

# FORCE_MEMORY_DUMP forces memory dump in production release to prevent from silent reboot
ifdef FORCE_MEMORY_DUMP
  ifeq ($(strip $(FORCE_MEMORY_DUMP)),TRUE)
    ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
      COM_DEFS += __FORCE_MEMORY_DUMP__
    else
      $(warning ERROR: FORCE_MEMORY_DUMP only can be enabled, when PRODUCTION_RELEASE = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
endif

# FORCE_WATCHDOG_MUTE forces watchdog mute in production release for convenient JTAG usage
ifdef FORCE_WATCHDOG_MUTE
  ifeq ($(strip $(FORCE_WATCHDOG_MUTE)),TRUE)
    ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
      COM_DEFS += __FORCE_WATCHDOG_MUTE__
    else
      $(warning ERROR: FORCE_WATCHDOG_MUTE only can be enabled, when PRODUCTION_RELEASE = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
endif

ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
  CUSTOM_OPTION += IC_MODULE_TEST
  CUSTOM_OPTION += DEVDRV_TEST
  COMMINCDIRS += btmt\include
endif

ifdef CB_SUPPORT
  ifeq ($(strip $(CB_SUPPORT)),TRUE)
    COM_DEFS += __CB__
  endif
endif

ifdef ATA_SUPPORT
  ifeq ($(strip $(ATA_SUPPORT)),TRUE)
    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      ifneq ($(strip $(GAS_SUPPORT)),TRUE)
        $(warning ERROR: GAS_SUPPORT must be TRUE when ATA_SUPPORT = TRUE and WIFI_SUPPORT != NONE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      ifneq ($(strip $(GAS_SUPPORT)),TRUE)
        $(warning ERROR: GAS_SUPPORT must be TRUE when ATA_SUPPORT = TRUE and BLUETOOTH_SUPPORT != NONE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COMPLIST   += ata
    COM_DEFS   += __ATA_SUPPORT__ __GAS_SUPPORT__ __DISABLE_SELDOM_USED_PROPRIETARY_CMD__
  endif
endif

DCM_MM_IMEHW_SUPPORT_PLATFORM = MT6250 MT6260 MT6261 MT2501 MT2502
ifdef DCM_MM_IMEHW_SUPPORT
  ifneq ($(filter $(strip $(PLATFORM)),$(DCM_MM_IMEHW_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(DCM_MM_IMEHW_SUPPORT)),TRUE)
      COM_DEFS  += DCM_MM_IMEHW_SUPPORT
      COM_DEFS  += __MM_DCM_SUPPORT__
      ifdef INPUT_METHOD
        ifneq ($(strip $(INPUT_METHOD)),NONE)
          COM_DEFS  += __IMEHW_DCM_SUPPORT__
        else 
          ifeq ($$(strip $$(MMI_VERSION)),COSMOS_MMI)
            $(warning ERROR: INPUT_MEHTOD must not be set as NONE when DCM_MM_IMEHW_SUPPORT = TRUE and MMI_VERSION = COSMOS_MMI.)
            DEPENDENCY_CONFLICT = TRUE
          endif        
        endif
      endif
    endif
  endif
endif

ifdef KINGMOVIE_FILE_FORMAT_SUPPORT
  ifeq ($(strip $(KINGMOVIE_FILE_FORMAT_SUPPORT)),TRUE)
    KINGMOVIE_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)) ,$(KINGMOVIE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support KINGMOVIE_FILE_FORMAT_SUPPORT = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(H264_DECODE)),TRUE)
      ifneq ($(strip $(MP4_DECODE)),TRUE)
        $(warning ERROR: please set H264_DECODE or MP4_DECODE as TRUE when KINGMOVIE_FILE_FORMAT_SUPPORT = TRUE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(KINGMOVIE_FILE_FORMAT_SUPPORT)),TRUE)
    ifeq ($(strip $(MOT_SUPPORT)),TRUE)
      COM_DEFS  += __KMV_SUPPORT__
    else
      ifeq ($(strip $(MOT_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,MOT_SUPPORT,KINGMOVIE_FILE_FORMAT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef VERIFY_ALL_IMAGES
  ifeq ($(strip $(VERIFY_ALL_IMAGES)),TRUE)
    ifndef SECURE_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,VERIFY_ALL_IMAGES)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SECURE_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,VERIFY_ALL_IMAGES)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __VERIFY_ALL_IMAGES__
  endif
endif

ifdef DCM_MULTITRUNK
  ifneq ($(strip $(DCM_MULTITRUNK)),NONE)
    DCM_COMPRESSION_PARTIAL_LOADING_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)),$(strip $(DCM_COMPRESSION_PARTIAL_LOADING_SUPPORT_PLATFORM))),)
      $(warning ERROR: Please set DCM_MULTITRUNK = NONE when platform is not $(DCM_COMPRESSION_PARTIAL_LOADING_SUPPORT_PLATFORM).)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += __DCM_MULTITRUNK__
  endif
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  ifdef HTTPSRV_SUPPORT
    ifeq ($(strip $(HTTPSRV_SUPPORT)),TRUE)
      COMPLIST += httpsrv
      COM_DEFS += __INET_HTTPD__
      COMP_TRACE_DEFS += inet_ps\httpd\include\httpd_trc.h
      ifeq ($(strip $(XYSSL_SUPPORT)),TRUE)
        COM_DEFS += __INET_HTTPS__
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  COMPLIST += inet_adaption
  COM_DEFS += __INET_PROTOCOL_PORTING_LAYER__
  COMP_TRACE_DEFS += inet_ps\adaption\include\inet_trc.h
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
 ifeq ($(strip $(HOTSPOT_SUPPORT)),TRUE)
   COM_DEFS += __WIFI_AP_MODE_SUPPORT__
 endif
endif

define DCM_COMPRESSION_MMI_POOL_CHECK
ifeq ($$(strip $$($(1))),TRUE)
  ifneq ($$(strip $$(DCM_COMPRESSION_SUPPORT)),TRUE)
    $$(call DEP_ERR_ONA_OR_OFFB,DCM_COMPRESSION_SUPPORT,$(1))
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($$(strip $$(MMI_VERSION)),COSMOS_MMI)
    $$(warning ERROR: Please do NOT set $(1)=TRUE for non-COSMOS!)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += $(2)
endif
endef

$(eval $(call DCM_COMPRESSION_MMI_POOL_CHECK,DCM_COMPRESSION_MMI_POOL_A,__DCM_WITH_COMPRESSION_MMI_POOL_A__))
$(eval $(call DCM_COMPRESSION_MMI_POOL_CHECK,DCM_COMPRESSION_MMI_POOL_B,__DCM_WITH_COMPRESSION_MMI_POOL_B__))
$(eval $(call DCM_COMPRESSION_MMI_POOL_CHECK,DCM_COMPRESSION_MMI_POOL_C,__DCM_WITH_COMPRESSION_MMI_POOL_C__))

ifdef FACTORY_BOOT_MODE_SUPPORT
  ifeq ($(strip $(FACTORY_BOOT_MODE_SUPPORT)),TRUE)
    COM_DEFS     += __FACTORY_BOOT_MODE_SUPPORT__
  endif
endif

ifeq ($(strip $(LOW_LEVEL_BRIDGE_SUPPORT)),TRUE)
  COM_DEFS    += __LOW_LEVEL_BRIDGE_SUPPORT__
endif

ifdef WIFI_SUPPORT_SNIFFER_MODE
  ifeq ($(strip $(WIFI_SUPPORT_SNIFFER_MODE)),TRUE)
    COM_DEFS +=  __WIFI_SNIFFER_SUPPORT__
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_SUPPORT_SNIFFER_MODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  ifdef DNSSRV_SUPPORT
    ifeq ($(strip $(DNSSRV_SUPPORT)), TRUE)
      COMPLIST += dnssrv
      COM_DEFS += __INET_DNSD__
      COMP_TRACE_DEFS  += inet_ps\dnsd\include\dnssrvf_trc.h
      COMP_TRACE_DEFS  += inet_ps\dnsd\include\dnssrvq_trc.h
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  ifdef RTSP_SUPPORT
    ifeq ($(strip $(RTSP_SUPPORT)),TRUE)
      COM_DEFS += __INET_RTSPD__
    endif
  endif
  ifdef FTPSRV_SUPPORT
    ifeq ($(strip $(FTPSRV_SUPPORT)), TRUE)
      COMPLIST += ftpsrv
      COM_DEFS += __INET_FTPD__
      COMP_TRACE_DEFS  += inet_ps\ftpd\include\ftpsrv_trc.h
    endif
  endif
endif

ifdef FUNET_ENABLE
  ifneq ($(strip $(FUNET_ENABLE)),NONE)
    ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,FUNET_ENABLE,CARD_DOWNLOAD)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
  ifeq ($(strip $(FUNET_ENABLE)),FULL_IMAGE_UPDATE)
    COM_DEFS += __FUNET_ENABLE__
    COM_DEFS +=  __NOR_FDM_IN_BL__
  endif
endif

ifdef WIFI_SUPPORT_APSTA_CONCURRENCY
  ifeq ($(strip $(WIFI_SUPPORT_APSTA_CONCURRENCY)),TRUE)
    COM_DEFS +=  __WIFI_AP_STA_CONCURRENCY__
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_SUPPORT_APSTA_CONCURRENCY)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef MMI_VERSION
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  __SKIP_EX_DISPLAY_LCD__
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(BCM_AT_SUPPORT)),TRUE)
      COMPLIST += bcm
      COM_DEFS    += __BCM_AT_CMD__
      COMP_TRACE_DEFS += bcm\bcm_trc.h
      ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
        COM_DEFS    +=  __BCM_SUPPORT__
      else
        $(warning ERROR: BCM_AT_SUPPORT is only support on modem project)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(BT_PBAP_PROFILE)),TRUE)
        COM_DEFS    +=  __BCM_PBAP_SERVER__
      endif
      ifeq ($(strip $(BT_HF_PROFILE)),TRUE)
        ifneq ($(strip $(BT_DIALER_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_DIALER_SUPPORT,BT_HF_PROFILE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(TCPIP_AT_SUPPORT)),PS)
  ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    $(call DEP_ERR_SETA_OR_SETB,TCPIP_SUPPORT,UDP_TCP,TCPIP_AT_SUPPORT,NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif

  ifeq ($(call Upper,$(strip $(PROJECT))),GSM)
    $(warning ERROR: TCPIP_AT_SUPPORT = PS should be set in PS support project)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS += __GPRS_TCPIP_AT_SUPPORT__
  COM_DEFS += __LONG_AT_CMD_SUPPORT__
  COM_DEFS += M2M_MTHL_TASK_HANDLE

  COMPLIST    += mthl
endif

ifeq ($(strip $(TCPIP_AT_SUPPORT)),WIFI)
  ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
    $(call DEP_ERR_SETA_OR_SETB,TCPIP_SUPPORT,UDP_TCP,TCPIP_AT_SUPPORT,NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif

  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,TCPIP_AT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS += __WIFI_TCPIP_AT_SUPPORT__
  COM_DEFS += __LONG_AT_CMD_SUPPORT__
  COM_DEFS += M2M_MTHL_TASK_HANDLE
  
  COMPLIST    += mthl
endif

ifdef SWLA_RESERVE_SPACE
  ifeq ($(strip $(SWLA_RESERVE_SPACE)),YES_WO_ADDON)
    COM_DEFS += __SWLA_RESERVE_SPACE_WO_ADDON__
  endif
endif

ifdef DCS_TX_NOTCH_SWITCH_SUPPORT
  ifeq ($(strip $(DCS_TX_NOTCH_SWITCH_SUPPORT)),TRUE)
    COM_DEFS += __DCS_TX_NOTCH_SWITCH_SUPPORT__
  endif
endif

ifdef KEEP_LCD_ENGINE_ON
  ifeq ($(strip $(KEEP_LCD_ENGINE_ON)),TRUE)
    COM_DEFS += __KEEP_LCD_ENGINE_ON__
  endif
endif

ifdef INIT_LCM_IN_BOOTLOADER
  ifeq ($(strip $(INIT_LCM_IN_BOOTLOADER)),TRUE)
    COM_DEFS += __INIT_LCM_IN_BOOTLOADER__
  endif
endif

ifdef NORMAL_MODE_CAPID_CAL_SUPPORT
  ifeq ($(strip $(NORMAL_MODE_CAPID_CAL_SUPPORT)),TRUE)
    COM_DEFS += __NORMAL_MODE_CAPID_CAL_SUPPORT__
    ifeq ($(strip $(L1_GPS_CO_CLOCK_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,NORMAL_MODE_CAPID_CAL_SUPPORT,L1_GPS_CO_CLOCK_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef RX_G2_HIGH_GAIN_MODE_DE_FEATURE_SAWLESS
  ifeq ($(strip $(RX_G2_HIGH_GAIN_MODE_DE_FEATURE_SAWLESS)),TRUE)
    COM_DEFS += __RX_G2_HIGH_GAIN_MODE_DE_FEATURE_SAWLESS__
  endif
endif

ifdef DSSS_SUPPORT
  ifneq ($(strip $(DSSS_SUPPORT)),FALSE)
    COM_DEFS += __SIM_HOT_SWAP_SUPPORT__
    COM_DEFS += __SIM_HOT_SWAP_SLOT_1_SUPPORT__
    COM_DEFS += __ESSIM_SUPPORT__
  endif
endif

ifneq ($(filter __FS_IN_BL__,$(COM_DEFS)),)
  COMPLIST += fdm_bl
  COM_DEFS += __NOR_FDM_IN_BL__
endif

#####
# COMMON SECTION used by gsm2.mak and custom_release.mak
#####

DEFAULT_CUSTOMER = MTK MTK_RF PLUTO
ifneq ($(filter $(call Upper,$(strip $(CUSTOMER))),$(strip $(DEFAULT_CUSTOMER))),)
  VERNOFILE =  make\Verno.bld

  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
    else
      SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
    endif
  else
    SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
  endif
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_L1S.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_BASIC.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_UDVT.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
    VERNOFILE := make\Verno_ClassB.bld
  endif
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
    VERNOFILE := make\Verno_ClassB_UMTS.bld
  endif
else
  VERNOFILE = make\Verno_$(strip $(CUSTOMER)).bld

  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_FOTA.txt
    else
      SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
    endif
  else
    SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
  endif

  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_L1S.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_BASIC.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
    SCATTERFILE := custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_UDVT.txt
  endif
endif

BL_SCATTERFILE   = custom\system\$(strip $(BOARD_VER))\scatBL_$(strip $(PLATFORM)).txt
BL_EXT_SCATTERFILE   = custom\system\$(strip $(BOARD_VER))\scatBL_$(strip $(PLATFORM))_ext.txt
FOTA_SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scatFOTA_$(strip $(PLATFORM)).txt

SCATTERFILE_FLASHTOOL := $(subst .txt,_flashtool.txt,$(strip $(SCATTERFILE)))
SCATTERFILE_FLASHTOOL_NAME := $(filter %.txt,$(subst \, ,$(SCATTERFILE_FLASHTOOL)))

include $(strip $(VERNOFILE))
SLIM_BRANCH := $(call Upper,$(strip $(BRANCH)))
BRANCH   +=   $(call Upper,$(strip $(CUSTOMER)))

# *************************************************************************
# Include extra dependency check.
# *************************************************************************
-include make\Extra_dep.mak

# *************************************************************************
# Build path, directories
# *************************************************************************
FIXPATH        =  .
TARGNAME       =  $(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
PLATLIBROOT    =  $(strip $(FIXPATH))\lib\$(strip $(PLATFORM))
TSTDIR         =  $(strip $(FIXPATH))\tst
TST_DB         =  $(strip $(TSTDIR))\database
ifeq ($(call Upper,$(PROJECT)),GPRS)
  TST_DB         :=  $(strip $(TSTDIR))\database_classb
endif
ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  TST_DB         :=  $(strip $(TSTDIR))\database_classb_umts
endif
BUILDDIR       =  $(strip $(FIXPATH))\build
TARGDIR        =  $(strip $(BUILDDIR))\$(strip $(CUSTOMER))
PROJDIR        =  $(strip $(TARGDIR))\$(PROJECT)
BPLGUINFOCUSTOMPREFIX = BPLGUInfoCustomApp_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
DBG_INFO_VERNO = $(subst .,_,$(VERNO))

OBJSDIR        =  $(strip $(PROJDIR))\$(strip $(PLATFORM))o
RULESDIR       =  $(strip $(PROJDIR))\$(strip $(PLATFORM))r
COMPLIBDIR     =  $(strip $(OBJSDIR))\lib

# Component's log file
COMPLOGDIR     =  $(strip $(TARGDIR))\log

HEADER_TEMP    =  header_temp
CUSTPACKDIR    =  $(strip $(FIXPATH))\custpack

NOT_REMOVAL_DIR_FILE = make\NotRemovalCodeDir.def

# Get the network path
-include ~net_path.tmp

#  Settings for emigen
BB_FOLDER_PATH    = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))
FLASH_OPTIONS_HDR = $(strip $(FIXPATH))\custom\common\hal\flash_opt.h
CUSTOM_EMI_H      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.h
CUSTOM_EMI_RELEASE_H = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI_release.h
CUSTOM_EMI_C      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.c
CUSTOM_FLASH_C    = $(strip $(FIXPATH))\custom\common\hal\custom_flash.c
CUSTOM_FLASH_NORFDM5_C = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_flash_norfdm5.c
MEMORY_DEVICE_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_MemoryDevice.h

EMI_GENERATOR  = $(strip $(FIXPATH))\tools\emigenMD.pl

FLASHFILE = $(strip $(FIXPATH))\~flash_cfg_tmp.c
MEMORY_CFG = $(strip $(CUSTOM_EMI_H))

KEYFILE_PATH = tools\sw_binding_key.ini

# Settings for MSC
NETSIM       = $(strip $(FIXPATH))\MoDIS_VC9\NetSim\NetSim.exe
MSCWORKSPACE = $(strip $(FIXPATH))\mtk_tools\AutoTest\MSC_TestCase\target.msc
CUSTMENUTREE = $(strip $(FIXPATH))\$(strip $(MMIDIR))\Customer\CustResource\CustMenuTree_Out.c
CUS_REL_FILES_LIST += $(strip $(TST_DB))\MCDDLL.dll

# Generate CUS_REL_SRC_COMP/REL_MTK_COMP
CUS_REL_SRC_COMP += $(filter $(REL_SRC_COMP),$(COMPLIST))

ifneq ($(filter bootloader,$(REL_SRC_COMP)),)
  CUS_REL_SRC_COMP += bootloader
endif

ifneq ($(filter bootloader_ext,$(REL_SRC_COMP)),)
  CUS_REL_SRC_COMP += bootloader_ext
endif

ifneq ($(filter fota,$(REL_SRC_COMP)),)
  CUS_REL_SRC_COMP += fota
endif

CUS_REL_MTK_COMP += $(filter $(REL_MTK_COMP),$(COMPLIST))
#

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  include make\REL_CR_VENDOR.mak
endif

ifdef RELEASE_TYPE 
  ifeq ($(call Upper ,$(strip $(RELEASE_TYPE))),INTERNAL)
    include make\INT_PKG.mak
  endif
endif
#------------------------------------------------------------
#   ELL   库支持
#   动态加载ELF 
#   还在调试中，未经允许不要改动代码 !
#------------------------------------------------------------
	COM_DEFS    += MTK_ELL
	COMPLIST    += ELL
	CUS_REL_SRC_COMP += ELL

#------------------------------------------------------------
# Define 8-bit encryption platform for update_img.exe
8_BIT_ENCRYPTION_PLATFORM = MT6268 MT6516 MT6253 MT6253E MT6253L MT6236 MT6252 MT6252H MT6921

# make sure AST_L1_TMD_FILES are located at the end of all L1_TMD_FILES
ifdef AST_SUPPORT
  ifneq ($(strip $(AST_SUPPORT)),NONE)
    AST_L1_TMD_FILES = CuStOm_StArT_AST \
                       ast_l1\l1trace\ast_l1_trace_isr_level_1.tmd \
                       ast_l1\l1trace\ast_l1_trace_isr_level_2.tmd \
                       ast_l1\l1trace\ast_l1_trace_isr_level_3.tmd \
                       ast_l1\l1trace\ast_l1_trace_isr_level_4.tmd \
                       ast_l1\l1trace\ast_l1_trace_task_level_1.tmd \
                       ast_l1\l1trace\ast_l1_trace_task_level_2.tmd \
                       ast_l1\l1trace\ast_l1_trace_task_level_3.tmd \
                       ast_l1\l1trace\ast_l1_trace_task_level_4.tmd \
                       CuStOm_EnD_AST

    L1_TMD_FILES += $(AST_L1_TMD_FILES)
    CUS_REL_FILES_LIST += $(strip $(UAS_FOLDER))\common\include\uas_pdu_data_common.h
  endif
endif

-include make\DSP.mak
#######################################################################
#COMPLIST Setting for bootloader
#######################################################################
BL_COMPLIST = che sst_sec

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  BL_COMPLIST += ssf
endif
  
ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
  ifeq ($(strip $(COMPILER)),RVCT)
    ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
      BL_COMPLIST += sss_rvct_sv5
    else
      BL_COMPLIST += sss_rvct_sv3
    endif
  else
    BL_COMPLIST += sss
  endif
endif

ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
  ifeq ($(strip $(COMPILER)),RVCT)
    ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
      BL_COMPOBJS += sss\lib\sss_rvct_sv5.lib
    else
      BL_COMPOBJS += sss\lib\sss_rvct_sv3.lib
    endif
  else
    BL_COMPOBJS += sss\lib\sss.lib
  endif
endif

ifdef FUNET_ENABLE
  ifneq ($(strip $(FUNET_ENABLE)),NONE)
    BL_COMPLIST += fdm_bl gfx_core32 sys_sec
  endif
endif

ifneq ($(filter __FS_IN_BL__,$(COM_DEFS)),)
  BL_COMPLIST += fdm_bl
endif

#########################################################
# Include ts_Option.mak & Settings for tiny system
#########################################################
ifeq ($(strip $(TINY_SYS)),TRUE)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    NEED_BUILD_TINY_SYSTEM = TRUE
include tiny_system\make\ts_Option.mak
  endif
endif 


#########################################################
# Replace alias modules. (for build flow)
#########################################################
include make\ALIAS.mak
ifdef COMPLIST
  COMPLIST_TEMP = $(foreach mod,$(call Upper,$(COMPLIST)), \
                  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
COMPLIST := $(strip $(COMPLIST_TEMP))
#########################################################
# End of replacing alias modules.
#########################################################

#########################################################
# Replace alias modules. (for custom release flow)
#########################################################
ifdef CUS_REL_SRC_COMP
CUS_REL_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_SRC_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_SRC_COMP := $(CUS_REL_SRC_COMP_TEMP)

ifdef CUS_REL_PAR_SRC_COMP
CUS_REL_PAR_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_PAR_SRC_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_PAR_SRC_COMP := $(CUS_REL_PAR_SRC_COMP_TEMP)

ifdef CUS_REL_MTK_COMP
CUS_REL_MTK_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_MTK_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_MTK_COMP := $(CUS_REL_MTK_COMP_TEMP)

#########################################################
# End of replacing alias modules.
#########################################################


# Remove the REMOVE_CUSTOM_OPTION specified in project makefile from COM_DEFS
COM_DEFS  := $(filter-out $(REMOVE_CUSTOM_OPTION),$(COM_DEFS))

CLEANROOM_COMP = j2me_11 j2me_hi j2me_nemo_cldc_slim j2me_nemo j2me_nemo_fdlibm j2me_nemo_cldc bsci sslplus j2me_nemo_cldc_i386 j2me_nemo_fdlibm_i386 drv_tp
# consistency check for COMPLIST & CUS_REL_XXX_COMP
# check each comp in $(COMPLIST) if it has been put in $(CUS_REL_XXX_COMP)
COMPLIST_NO_REL_TYPE_COMP = $(filter-out $(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
COMPLIST_NO_REL_TYPE_COMP := $(filter-out $(CLEANROOM_COMP),$(COMPLIST_NO_REL_TYPE_COMP))
ifneq ($(words $(COMPLIST_NO_REL_TYPE_COMP)),0)
  $(warning ERROR: $(foreach comp,$(COMPLIST_NO_REL_TYPE_COMP),"$(comp)") in COMPLIST but NOT in CUS_REL_XXX_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# check each comp in $(CUS_REL_XXX_COMP) if it has been put in $(COMPLIST)
CREL_COMP_NOT_COMPLIST = $(filter-out $(COMPLIST),$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP))
CREL_COMP_NOT_COMPLIST := $(filter-out bootloader bootloader_ext,$(CREL_COMP_NOT_COMPLIST))
CREL_COMP_NOT_COMPLIST := $(filter-out fota,$(CREL_COMP_NOT_COMPLIST))
CREL_COMP_NOT_COMPLIST := $(filter-out $(TS_COMPLIST),$(CREL_COMP_NOT_COMPLIST))
ifneq ($(words $(CREL_COMP_NOT_COMPLIST)),0)
  $(warning ERROR: $(foreach comp,$(CREL_COMP_NOT_COMPLIST),"$(comp)") in CUS_REL_XXX_COMP but NOT in COMPLIST)
  DEPENDENCY_CONFLICT = TRUE
endif

# check no module define in $(CUS_REL_SRC_COMP) and $(CUS_REL_MTK_COMP) both
COMP_BOTH_IN_SRC_MTK = $(filter $(CUS_REL_SRC_COMP),$(CUS_REL_MTK_COMP))
ifneq ($(words $(COMP_BOTH_IN_SRC_MTK)),0)
  $(warning ERROR: $(foreach comp,$(COMP_BOTH_IN_SRC_MTK),"$(comp)") in CUS_REL_SRC_COMP but also in CUS_REL_MTK_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# COMPLIST(during CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMPLIST =     $(strip $(CUS_REL_SRC_COMP))
  COMPLIST +=    $(strip $(CUS_REL_PAR_SRC_COMP))
  COMPLIST := $(filter-out bootloader bootloader_ext,$(COMPLIST))
  COMPLIST := $(filter-out fota,$(COMPLIST))
  COMPLIST := $(filter-out $(TS_COMPLIST),$(COMPLIST))

  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COMPLIST :=  $(filter-out plutommi,$(COMPLIST))
      COMPLIST :=  $(filter-out mmiresource,$(COMPLIST))
      COMPLIST :=  $(subst lc ,lcmmiresource ,$(COMPLIST))
      COMPLIST :=  $(filter-out mtkapp,$(COMPLIST))
      COMPLIST :=  $(subst lc ,lcmtkapp ,$(COMPLIST))
    else
      ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
        COMPLIST :=  $(filter-out plutommi,$(COMPLIST))
        COMPLIST :=  $(filter-out mmiresource,$(COMPLIST))
        COMPLIST :=  $(subst lc ,lcmmiresource ,$(COMPLIST))
        COMPLIST :=  $(filter-out mtkapp,$(COMPLIST))
        COMPLIST :=  $(subst lc ,lcmtkapp ,$(COMPLIST))
      else
        COMPLIST :=  $(filter-out lcmmi,$(COMPLIST))
        COMPLIST :=  $(filter-out lcmmiresource,$(COMPLIST))
        COMPLIST :=  $(filter-out lcmtkapp,$(COMPLIST))
      endif
    endif
  endif
endif

ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
  ifdef OPTR_SPEC
    ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
      ifneq ($(strip $(OPTR_SPEC)),NONE)
        CUS_REL_BASE_COMP += $(strip $(OPTR_PATH))
        CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common
        ifneq ($(findstring TD0200,$(strip $(OPTR_SPEC))),)
          CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\vendor
        endif
        THE_OP_CUSTOM_LIS = $(strip $(OPTR_PATH))\op_custom.lis
        OPTR_MMI = $(strip $(OPTR_PATH))
      endif
    else
      CUS_REL_BASE_COMP += operator
      THE_OP_CUSTOM_LIS = $(strip $(OPTR_PATH))\op_custom.lis
      OPTR_MMI = $(strip $(OPTR_PATH))
    endif
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    BT_SUPPORT_PROFILE_NUM = $(words $(strip $(BT_SUPPORT_PROFILE)))
    COM_DEFS += BT_SUPPORT_PROFILE_NUM=$(strip $(BT_SUPPORT_PROFILE_NUM))
  endif
endif

# check the COM_DEFS value
COM_DEFS_INVALID_LIST := TRUE FALSE ENABLE DISABLE FULL SLIM NONE
ifdef COM_DEFS
  COM_DEFS_INVALID_VALUE := $(filter $(strip $(COM_DEFS)),$(COM_DEFS_INVALID_LIST))
  ifneq ($(COM_DEFS_INVALID_VALUE),)
    $(warning ERROR: COM_DEFS value ($(strip $(COM_DEFS_INVALID_VALUE))) is NOT allowable, please do Not assign COM_DEFS value as : ($(strip $(COM_DEFS_INVALID_LIST)))) 
    DEPENDENCY_CONFLICT = TRUE 
  endif
endif

ifdef DEPENDENCY_CONFLICT
  ifeq ($(strip $(DEPENDENCY_CONFLICT)),TRUE)
    $(error PLEASE check above dependency errors!)
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  RELEASE_LEVEL = NONE_RELEASE
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    RELEASE_LEVEL = SUB_RELEASE
  endif
endif

#------------------------------------------------------------
# The following is a custom
#------------------------------------------------------------
	COMPLIST += track
  	COM_DEFS += __$(strip $(PROJECT_SUPPORT_TRACK))__
  	COM_DEFS +=__GPS_TRACK__
  	COM_DEFS +=__TRACK_FOTA_UPDATE__
	COMPLIST += track_nvram
#------------------------------------------------------------
# Drive configuration
#------------------------------------------------------------
ifdef TRACK_SENSOR_SUPPORT
  ifeq ($(strip $(TRACK_SENSOR_SUPPORT)),TRUE)
  
	COM_DEFS   += __TRACK_SENSOR__
	
        #BMA250
       COM_DEFS   += __BOSCH_SENSOR__
       COM_DEFS   += __BOSCH_BMA250__
        #BMA250E (兼容BMA250)
       COM_DEFS   += __BOSCH_BMA250E__
      # COM_DEFS   +=  __BOSCH_BMA250F__#在使用250f SENSOR的时候需要将这个宏打开，其他的均不变
       COMMINCDIRS += custom\drv\track_sensor\BMA250

        #sensor IIC 通信驱动
        #理论上未来增加其它Sensor 可以摆脱无厂家代码的限制
        #完全自定义实现功能
        COMMINCDIRS += custom\drv\track_sensor\track_sensor_iic

       #KXTJ3-1057 newName 1058
	COM_DEFS   += __KIONIX_KXTJ31057__
	COMMINCDIRS += custom\drv\track_sensor\KXTJ31057

       #SC7A20
	COM_DEFS   += __SILAN_SC7A20__
	COMMINCDIRS += custom\drv\track_sensor\SC7A20

	#DA213
	COM_DEFS   += __MIRA_DA213__
	COMMINCDIRS += custom\drv\track_sensor\DA213	

  endif
endif


#RF_MODULE_CUSTOM
ifdef RF_MODULE_CUSTOM
    ifneq ($(strip $(RF_MODULE_CUSTOM)),NONE)
        COM_DEFS += __$(strip $(RF_MODULE_CUSTOM))__
    else
        $(warning ERROR: RF_MODULE_CUSTOM is(not error) $(RF_MODULE_CUSTOM))
    endif
endif

ifneq ($(strip $(TRACK_CUST_GPS_SUPPORT)),NONE)
	COM_DEFS	+= __GPS_UART__
	
	ifeq ($(strip $(TRACK_CUST_GPS_SUPPORT)),AT6558)
		COM_DEFS	+= __BD_AT6558__
	endif

	ifeq ($(strip $(TRACK_CUST_GPS_SUPPORT)),G3333)
		COM_DEFS	+= __GPS_G3333__
	endif

endif

ifeq ($(strip $(GPS_SUPPORT)),MT3333) # GPS MT3333
      COM_DEFS += __GPS_MT3333__ 
      COM_DEFS += __GPS_ALL_IN_ONE_AT_SUPPORT__
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COM_DEFS    += __GPS_EPO_DOWNLOAD__
      endif
endif

#WATDOG
ifdef WATDOG
    ifneq ($(strip $(WATDOG)),NONE)
      COM_DEFS += __WATCH_DOG__
      
      ifeq ($(strip $(WATDOG)),PULSE)
        	COM_DEFS += __WDT_PLUSE__
      else
		ifeq ($(strip $(WATDOG)),IIC)
			COM_DEFS += __WDT_USE_I2C__
		else
			$(warning ERROR: WATDOG not support $(WATDOG))
		endif
       endif
  endif
endif

#TRACK_GPS_TYPE
ifdef TRACK_GPS_TYPE
    ifneq ($(strip $(TRACK_GPS_TYPE)),NONE)

        ifeq ($(strip $(TRACK_GPS_TYPE)),GPS_BEIDOU)
        	COM_DEFS += __TRACK_TYPE_GPS_BEIDOU__
        else
        	ifeq ($(strip $(TRACK_GPS_TYPE)),GPS_GLONASS)
			COM_DEFS += __TRACK_TYPE_GPS_GLONASS__
		else
			$(warning ERROR: TRACK_GPS_TYPE not support $(TRACK_GPS_TYPE))
		endif
        endif
    endif
endif

#------------------------------------------------------------
# /*入网认证、RF调试功能宏       --    chengjun  2017-07-10*/
#------------------------------------------------------------ 	

  	#入网许可认证
	#COM_DEFS +=__NETWORK_LICENSE__
	
#------------------------------------------------------------
# /*通用功能宏       --    chengjun  2017-07-10*/
#------------------------------------------------------------ 	

	#将NVRAM值部分存入DISK1
	COM_DEFS += __TRACK_DISK_NVRAM__
	
  	#基站信息
	COM_DEFS +=__LBS_DATA__

	#modem Keypad 
	COM_DEFS +=__KEYPAD_MOD__

	#hardware test
	COM_DEFS +=__TEST_PCBA__     

	#AT指令及相关功能如SMS/Call
	COM_DEFS +=__AT_CA__

	#二级静态过滤
	COM_DEFS +=__GPRS_SEND_FILTER__

	#GPS秒定功能
	COM_DEFS +=__SECOND_SET__   

	#删除日志写文件的功能 chengj
	COM_DEFS +=__REMOVE_LOG_TO_FILE__  

	#短信电话走l4C接口
	COM_DEFS +=__L4C_API__
	
	#重新找个4K保存重要参数
	COM_DEFS += __IMPORTANT_PARA_4K__

#------------------------------------------------------------
# /*可选配置功能宏       --    chengjun  2017-07-10*/
#------------------------------------------------------------ 

######### 硬件配置 ######### 

	#高低温回充功能宏
	#TEMP_RECHARGE_SUPPORT

	#支持wif MT5931
	#COM_DEFS	+= __WIFI__

	#禁止ACC
	#COM_DEFS	+= __NO_ACC__

	#无MIC
	#COM_DEFS	+= __NO_MIC__

	#支持开关键
	#COM_DEFS += __KEY_POWER_ON__

	#机械震动检测传感器
	#COM_DEFS +=__MECH_SENSOR__

	#OLED显示屏
	#COM_DEFS += __OLED__

	#音频
	#COM_DEFS +=__AUDIO_RC__
	
	#录音功能
	#COM_DEFS +=__LUYING__
	
	#ADC4开启检测
	#COM_DEFS +=__EXT_VBAT_ADC__	

	#电池支持温度检测
	#COM_DEFS +=__BAT_WITH_TEMPUTER__

	#使用硬件充电方案
	#COM_DEFS +=__CHARGE_NOT_MTK__	

	#按键开机
	#COM_DEFS += __KEY_POWER_ON__

	#RS485/RS232-使用UART1转RS485/RS232-注意切换串口用于AT测试
	#COM_DEFS	+= __CUST_UART1_MUX__

	# BT CSR1012
	#COM_DEFS	+= __CUST_BT__

	#电池温度上报AMS
	#COM_DEFS	+= __BAT_TEMP_TO_AMS__
	
	#单片机升级
	#COM_DEFS +=__MCU_SW_UPDATE__
	
	#RS485-使用UART3转RS485半双工通信
	#COM_DEFS	+= __CUST_RS485__
	
######### 报警配置 ######### 

	#电子围栏
	#COM_DEFS += __GFENCE__
	#COM_DEFS += __FENCE__

	#多围栏
	#COM_DEFS += __MORE_FENCE__

	#SOS报警
	#COM_DEFS +=__ALM_SOS__

	#跌倒报警
	#COM_DEFS +=__DROP_ALM__
	
	#开机报警
	#COM_DEFS +=__ALM_BOOT__

	
######### 奇葩配置 ######### 

	#主备用域名
	#COM_DEFS +=__BACKUP_SERVER__
	
	#飞行模式
	#COM_DEFS	+= __FLY_MODE__

	#GPS数据中含ACC状态
	#COM_DEFS	+= __PACKAGE_WITH_ACC__

	#单片机升级
	#COM_DEFS +=__MCU_SW_UPDATE__
	
	#9404同步服务器
	#COM_DEFS +=__PARAM_CHANGE_UPDATE_SERVER__

	#最早的GT02协议
	#COM_DEFS += __SAME_GT02__

	#GPSDUP功能
	#COM_DEFS += __NOFIX_GPSDUP__

	#防伪基站功能及报警
	#COM_DEFS += __CUST_FAKECELL__

	#日志保存
	#COM_DEFS+=__AMS_LOG__
	


######### 参数配置 ######### 

	#外贸版=TRUE / 中文版=FALSE
	#TRACK_IS_WM_VERSION = FALSE 

	#手持定位器= TRUE/车载定位器=FALSE
	#支持acc、断油电,长期接外电的为车载定位器
	#其他为手持设备 TRACK_IS_DEVICE_TYPE_HAND = TRUE 
	
#------------------------------------------------------------
# /*项目宏       --    chengjun  2017-07-10*/
#------------------------------------------------------------ 

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),MT200)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE

	COM_DEFS +=__L4C_API__
	COM_DEFS +=__MECH_SENSOR__
	COM_DEFS +=__EXT_VBAT_ADC__	
	#没有麦克风无需接听电话宏
	COM_DEFS	+= __NO_MIC__
	COM_DEFS	+= __FENCE__
	#飞行模式
	COM_DEFS	+= __FLY_MODE__
	#主备用域名
	#ACC切换报警
	COM_DEFS +=__ACC_ALARM__
	
	#/*gpsdev.tracksolid.com*/
	#COM_DEFS	+= __SERVER_TRACKSOLID__ 
	#/*gpsdev.jimicloud.com*/
	COM_DEFS	+= __SERVER_JIMICLOUD__ 
endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NT31)
	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  

	COM_DEFS +=__L4C_API__
	#机械震动
	COM_DEFS +=__NT32__
	COM_DEFS +=__MECH_SENSOR__
	COM_DEFS +=__SERVER_TUQIANG__
	# COM_DEFS +=__SERVER_COOACCESS__
	#短信电话走l4C接口GT530无RF功能
##NT32与nt32s的分界线
#NT32

	COM_DEFS +=__FENCE__
	COM_DEFS +=__ALM_SOS__
##NT32与nt32s的分界线
#NT32S
	#COM_DEFS += __SAME_GT02__
	#COM_DEFS +=__GUMI_GENERAL__
	#锁域名
	#COM_DEFS +=__GUMI__
     #   COM_DEFS	+= __SERVER_TUQIANG__
	#COM_DEFS +=__NO_DEFENSE__
	#COM_DEFS +=__SYS_VERSION__
	#COM_DEFS += __NO_ACC__
	#COM_DEFS +=__NO_SENSOR__
endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NT13V)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	COM_DEFS	+= __EXT_VBAT_ADC__

	COM_DEFS	+= __BACKUP_SERVER__

	#ACC切换报警
	COM_DEFS 	+=__ACC_ALARM__
	
	COM_DEFS	+= __BLE_GATT__
	#COM_DEFS	+= __BLE_GB__

	#QB200的物联锁蓝牙协议
	#COM_DEFS	+= __BLE_QB__	

	#GPSDUP功能
	COM_DEFS 	+= __NOFIX_GPSDUP__
       COM_DEFS 	+= __BLE_DEBUG_LOG__

	#COM_DEFS += __AMS_HEX_LOG__

	COM_DEFS	+= __WIFI__

	#防伪基站功能及报警
	COM_DEFS 	+= __CUST_FAKECELL__

	#联通语音卡拨号
	#COM_DEFS	+= __PACKET_SHA__
	#COM_DEFS	+= __SIM_CU_CALL__

	#飞行模式
	COM_DEFS	+= __FLY_MODE__
	
	#9404
	COM_DEFS +=__PARAM_CHANGE_UPDATE_SERVER__

	COM_DEFS += __FENCE__

	#音频
	COM_DEFS +=__AUDIO_RC__
	
	#录音功能
	COM_DEFS +=__LUYING__

	#MCU  NT13V项目（2503D芯片与BJ8M601A通讯协议）_20170829.docx
	COM_DEFS +=__MCU_BJ8M601A_NT13V__

	#MCU控制外电
	COM_DEFS +=__MCU_CTL_EXBAT__
endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NT17)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	COM_DEFS	+= __EXT_VBAT_ADC__

	COM_DEFS	+= __BACKUP_SERVER__

	#ACC切换报警
	COM_DEFS 	+=__ACC_ALARM__
	
	COM_DEFS	+= __BLE_GATT__

	#GPSDUP功能
	COM_DEFS 	+= __NOFIX_GPSDUP__
       COM_DEFS 	+= __BLE_DEBUG_LOG__
	#COM_DEFS += __AMS_HEX_LOG__

	#COM_DEFS	+= __WIFI__

	#防伪基站功能及报警
	COM_DEFS 	+= __CUST_FAKECELL__

	#联通语音卡拨号
	#COM_DEFS	+= __PACKET_SHA__
	#COM_DEFS	+= __SIM_CU_CALL__

	#9404
	COM_DEFS +=__PARAM_CHANGE_UPDATE_SERVER__

	COM_DEFS += __FENCE__

	#音频
	COM_DEFS +=__AUDIO_RC__
	
	#录音功能
	COM_DEFS +=__LUYING__

	#MCU  NT13V项目（2503D芯片与BJ8M601A通讯协议）_20170829.docx
	COM_DEFS +=__MCU_BJ8M601A_NT13V__

	#MCU控制外电
	COM_DEFS +=__MCU_CTL_EXBAT__

	#QB200的物联锁蓝牙协议
	#COM_DEFS	+= __BLE_QB__

endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),EL100)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	COM_DEFS	+= __EXT_VBAT_ADC__
	#没有麦克风无需接听电话宏
	COM_DEFS	+= __NO_MIC__

	COM_DEFS	+= __BACKUP_SERVER__

	COM_DEFS	+= __BLE_GATT__

	COM_DEFS     += __SMT_BMS__
	#GPSDUP功能
	COM_DEFS += __NOFIX_GPSDUP__

	COM_DEFS += __AMS_HEX_LOG__

	#COM_DEFS +=__AUDIO_RC__
	
	COM_DEFS	+= __BLE_DEBUG_LOG__

	#使用硬件充电方案
	#COM_DEFS +=__CHARGE_NOT_MTK__
	COM_DEFS	+= __BLE_GB__

       #联通语音卡拨号
	#COM_DEFS	+= __PACKET_SHA__
	#COM_DEFS	+= __SIM_CU_CALL__

	#FTP服务器的连接
	COM_DEFS	+= __NET_FTP__

	#HTTP的连接，以及BMS的升级
	COM_DEFS	+= __BMS_UPDATE__
endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),ET310)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	COM_DEFS	+= __EXT_VBAT_ADC__
	#外电低电电压保护
	COM_DEFS	+= __EXT_VBAT_Protection__
	#没有麦克风无需接听电话宏
	COM_DEFS	+= __NO_MIC__

	COM_DEFS	+= __FENCE__
	COM_DEFS	+= __FLY_MODE__
	COM_DEFS	+= __BACKUP_SERVER__

	#BLE服务
	COM_DEFS	+= __BLE_GATT__
	COM_DEFS +=__AUDIO_RC__
	#调试BLE日志
	COM_DEFS	+= __BLE_DEBUG_LOG__
	
  ifeq ($(strip $(TRACK_IS_WM_VERSION)),TRUE)
	#外贸版，旧协议
	COM_DEFS	+= __WM_OLD06__
	COM_DEFS	+= __ACC_ALARM__
	COM_DEFS	+= __PACKAGE_WITH_ACC__
  endif	
	#COM_DEFS	+= __SERVER_COOACCESS__
	COM_DEFS	+= __SERVER_TUQIANG__
	#COM_DEFS	+= __SERVER_GPSLUCKLY__
	
	#联通语音卡拨号
	#COM_DEFS	+= __PACKET_SHA__
	#COM_DEFS	+= __SIM_CU_CALL__

	#伴车安
endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NT36)
	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  

	COM_DEFS	+= __L4C_API__
	COM_DEFS	+= __MECH_SENSOR__

	COM_DEFS	+= __FENCE__
	COM_DEFS 	+= __ALM_SOS__
	COM_DEFS 	+=__PACKAGE_WITH_ACC__
	
	#外贸部GT06F软件定制需求，客户需要在ACC状态发生改变时，触发ACC报警包,并上传给平台
	COM_DEFS +=__ACC_ALARM__	
	#外贸定制版本限制五个MCC使用，分别为404/405（印度）、639（肯尼亚）、722（阿根廷）、724（巴西）、744（巴拉圭）
	#COM_DEFS += __BLOCK_SALES_AREA_INDIA_ET__	
	#外贸定制版本限制三个MCC使用，分别为722（阿根廷）、724（巴西）、744（巴拉圭）
	COM_DEFS += __BLOCK_SALES_AREA_ARENTINA_ET__		
	#德国定制版
	#COM_DEFS += __GERMANY__
	#墨西哥定制版
	#COM_DEFS += __MEX__	
	#西班牙定制版
	#COM_DEFS += __SPANISH__	
endif


ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NT55)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	#GPSDUP功能
	COM_DEFS 	+= __NOFIX_GPSDUP__

	COM_DEFS	+= __L4C_API__
	#COM_DEFS	+= __EXT_VBAT_ADC__
	#外电低电电压保护
	#COM_DEFS	+= __EXT_VBAT_Protection__

	COM_DEFS	+= __BACKUP_SERVER__

	#BLE服务
	COM_DEFS	+= __BLE_GATT__
	#调试BLE日志
	COM_DEFS	+= __BLE_DEBUG_LOG__

	#使用硬件充电方案
	COM_DEFS +=__CHARGE_NOT_MTK__

	#电子围栏
	COM_DEFS += __FENCE__

	#9404
	COM_DEFS +=__PARAM_CHANGE_UPDATE_SERVER__

	#OBD外设
	COM_DEFS += __OBD__
	COM_DEFS	+=__OBD_SRD__
	#ATECH OBD 模块
	COM_DEFS	+=__ATECH__
	
	#录音
	COM_DEFS +=__AUDIO_RC__
	#录音功能
	COM_DEFS +=__LUYING__

	#星恒BMS电池协议
	#COM_DEFS += __BMS_PHYLION__

endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),QB200)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	
	COM_DEFS	+= __BLE_GATT__
	#调试BLE日志
	COM_DEFS	+= __BLE_DEBUG_LOG__

	#QB200的物联锁蓝牙协议
	#COM_DEFS	+= __BLE_QB__

	#GB100的蓝牙协议
	COM_DEFS	+= __BLE_GB__
	
	COM_DEFS	+= __WIFI__
	
endif

ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NF2319)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	COM_DEFS +=__EXT_VBAT_ADC__
	
	#支持wif MT5931
	COM_DEFS	+= __WIFI__

	#BLE服务
	COM_DEFS	+= __BLE_GATT__
	#调试BLE日志
	COM_DEFS	+= __BLE_DEBUG_LOG__
	
	#NF2319工厂测试指令
	#COM_DEFS	+= __NF2319_TEST__	
	#蜜蜂出行蓝牙协议
	COM_DEFS	+= __BLE_MF__	

	#禁止ACC
	COM_DEFS	+= __NO_ACC__

	#无MIC
	COM_DEFS	+= __NO_MIC__

	COM_DEFS +=__AUDIO_RC__

	#轮动信号检测
	#COM_DEFS +=__WHEEL_CHECK__
endif
ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),NF2318)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=FALSE
	
	COM_DEFS	+= __L4C_API__
	COM_DEFS +=__EXT_VBAT_ADC__
	
	#支持wif MT5931
	COM_DEFS	+= __WIFI__

	#BLE服务
	COM_DEFS	+= __BLE_GATT__
	#调试BLE日志
	#COM_DEFS	+= __BLE_DEBUG_LOG__
	
	#NF2319工厂测试指令
	#COM_DEFS	+= __NF2319_TEST__	
	#蜜蜂出行蓝牙协议
	COM_DEFS	+= __BLE_N07__	

	#禁止ACC
	#COM_DEFS	+= __NO_ACC__

	#无MIC
	COM_DEFS	+= __NO_MIC__

	COM_DEFS +=__AUDIO_RC__

	#轮动信号检测
	COM_DEFS +=__WHEEL_CHECK__

	#电池bms协议
	COM_DEFS += __BMS_PHYLION__

	#行运兔宏开关. 行运兔与松果七号单车是同一硬件不同客户.当打开时表示行运兔客户,否则为松果客户
	COM_DEFS += __EL100_XYT__
	
endif
ifeq ($(strip $(PROJECT_SUPPORT_TRACK)),JM10)

	#是否是外贸版本  TRUE/FALSE
	TRACK_IS_WM_VERSION = FALSE  
	
	#是否是手持设备  TRUE/FALSE
	TRACK_IS_DEVICE_TYPE_HAND=TRUE
	
	COM_DEFS	+= __L4C_API__

	#BLE服务
	COM_DEFS	+= __BLE_GATT__
	#调试BLE日志
	COM_DEFS	+= __BLE_DEBUG_LOG__

	#禁止ACC
	COM_DEFS	+= __NO_ACC__

	#无MIC
	COM_DEFS	+= __NO_MIC__	

	COM_DEFS	+= __EXT_VBAT_ADC__
endif

#------------------------------------------------------------
# /*参数配置宏 必须在文件最后      --    chengjun  2017-07-10*/
#------------------------------------------------------------ 

#语言版本
ifeq ($(strip $(TRACK_IS_WM_VERSION)),TRUE)
	#默认语言为英文，通常为外贸版本软件 与 __LIMIT_SALES_AREA__  互斥
	COM_DEFS +=__LANG_ENGLISH__
	
else 
     ifeq ($(strip $(TRACK_IS_WM_VERSION)),FALSE)
	#限制仅可在国内销售与__LANG_ENGLISH__  互斥
	COM_DEFS +=__LIMIT_SALES_AREA__
	
     else
	 $(warning ERROR: TRACK_IS_WM_VERSION is not defined!) 

     endif
endif


#设备类型
ifeq ($(strip $(TRACK_IS_DEVICE_TYPE_HAND)),TRUE)
	#手持设备
	COM_DEFS +=__TRACK_HAND_DEVICE__
	
else
     ifeq ($(strip $(TRACK_IS_DEVICE_TYPE_HAND)),FALSE)
	#车载设备，car容易辨识
	COM_DEFS +=__TRACK_CAR_DEVICE__	

     else
	$(warning ERROR: TRACK_IS_DEVICE_TYPE_HAND is not defined!) 

     endif
endif


