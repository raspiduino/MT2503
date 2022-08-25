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
#
#
# *************************************************************************
#
#   		MediaTek Inc GSM/GPRS Wireless Communicatin Project
#					Build/Make Development Tools
#
#			Author			Date			Description
#			Sherman Wang 	2004/04/29		Create version 1.0
#
# *************************************************************************
# COMP.MAK  - Component build script
#
#  DISCUSSION:
#
#     This file is build script for component modules, and contains C source
#  files (.c), and Assembly source files(.s).
#
#  USAGE:
#
#  IMPORTANT NOTES:
#
# *************************************************************************
#
# $Revision:$
# $Modtime:$
# $Log:$
#
# 04 26 2014 ray.lin-wang
# [MAUI_03495169] [BuildEnvironment][TinySystem] refine the build flow for tiny system
# 	11CW1418MP tiny
#
# 04 03 2014 ray.lin-wang
# [MAUI_03486390] [Tiny System] call for check in
# .
#
# 04 02 2014 ray.lin-wang
# [MAUI_03486390] [Tiny System] call for check in
# .
#
# 02 27 2014 ray.lin-wang
# [MAUI_03486390] [Tiny System] call for check in
# .
#
# 02 27 2014 ray.lin-wang
# [MAUI_03486390] [Tiny System] call for check in
# 	.
#
# 09 04 2013 ray.lin-wang
# [MAUI_03456012] [MakeFile] [Patchback: Feature Option] NORFLASH_NON_XIP_SUPPORT
# .
#
# 12 26 2012 ray.lin-wang
# [MAUI_03300135] [MakeFile] [Modify: Others]turn off __KAL_VM__ in NAND Flash Booting Project on ARM7
# .
#
# 12 20 2012 ray.lin-wang
# [MAUI_03290354] [MakeFile] [Remove: Feature Option] GADGET_SUPPORT
# <saved by Perforce>
#
# 12 20 2012 ray.lin-wang
# [MAUI_03290354] [MakeFile] [Remove: Feature Option] GADGET_SUPPORT
# phase-out gadget_adp gadget_lib gadget_ports
#
# 12 19 2012 ray.lin-wang
# [MAUI_03290354] [MakeFile] [Remove: Feature Option] GADGET_SUPPORT
# .
#
# 12 18 2012 amber.su
# [MAUI_03294051] [Taregt Build] delete intermedate .d file for bootarm.s
# .
#
# 12 18 2012 amber.su
# [MAUI_03294051] [Taregt Build] delete intermedate .d file for bootarm.s
# .
#
# 12 14 2012 xenia.tsou
# [MAUI_03282588] [Target] enhance the PCIBT mechanism and fix PCIBT error
# .
#
# 11 08 2012 ray.lin-wang
# [MAUI_03259573] [MakeFile] [Modify: Others] add __TST_WRITE_TO_FILE__ in comp.mak
# .
# 
# 09 19 2012 ray.lin-wang
# [MAUI_03235205] [MakeFile] [Add/Modify: Feature Option] KAL_ASSERT_LEVEL
# .
# 
# 09 07 2012 ray.lin-wang
# [MAUI_03232490] [MakeFile] [Modify: Others] add __KAL_VM__ compile option for assembly file in comp.mak
# .
# *************************************************************************
# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))
Lower = $(subst Z,z,$(subst Y,y,$(subst X,x,$(subst W,w,$(subst V,v,$(subst U,u,$(subst T,t,$(subst S,s,$(subst R,r,$(subst Q,q,$(subst P,p,$(subst O,o,$(subst N,n,$(subst M,m,$(subst L,l,$(subst K,k,$(subst J,j,$(subst I,i,$(subst H,h,$(subst G,g,$(subst F,f,$(subst E,e,$(subst D,d,$(subst C,c,$(subst B,b,$(subst A,a,$(1)))))))))))))))))))))))))))

AUTO_MERGE_FILE_CHECK = $(if $(shell dir $(1)\$(strip $(BOARD_VER))\$(2) /b 2>nul),$(1)\$(strip $(BOARD_VER))\$(2), \
                        $(if $(shell dir $(1)\_DEFAULT_BB\$(strip $(PLATFORM))\$(2) /b 2>nul), $(1)\_DEFAULT_BB\$(strip $(PLATFORM))\$(2),))
# *************************************************************************
# Project Variables
# *************************************************************************
-include tools\GMSL\gmsl
-include make\Custom.bld             # Custom release build
include make\~compbld.tmp            # Temporary build script created by gsm2.mak
include make\ALIAS.mak
-include $(strip $(TARGDIR))\MMI_DRV_DEFS.mak
-include make\app_cfg.mak
include $(strip $(THE_MF))

ifndef MODIS_CONFIG
  MODIS_CONFIG := FALSE
endif
ifndef MODIS_UESIM
  MODIS_UESIM := MoDIS
endif

ifeq ($(strip $(RVCT_VERSION)),V31)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  #include make\compiler_cfg.mak for internal only
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
    include make\compiler_cfg.mak
  else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    include make\compiler_cfg.mak
  endif
endif
endif

MODULE_DEFS := $(DEFINES) $(MMI_DEFS) $(DRV_DEFS) $(OPTR_DEFS)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  MODULE_DEFS := $(filter-out __MTK_TARGET__,$(MODULE_DEFS))
endif

######################################
#Add the component makefile path for tiny system.
######################################
ifeq ($(filter $(strip $(COMPONENT)),$(TS_COMPLIST)), $(strip $(COMPONENT)))
  MODULE_MAKEFILE := tiny_system\make\$(strip $(COMPONENT))\$(strip $(COMPONENT)).mak
else 
  ifdef $($(COMPONENT))
    MODULE_MAKEFILE := make\$(strip $($(COMPONENT)))\$(strip $(COMPONENT))\$(strip $(COMPONENT)).mak
  else
    MODULE_MAKEFILE := make\$(strip $(COMPONENT))\$(strip $(COMPONENT)).mak
  endif
endif
include $(MODULE_MAKEFILE)

NEED_CHECK_DEPEND_LIST := $(THE_MF) make\Option.mak make\Option_HAL.mak make\MODEM.mak make\JAVA_DEF.mak
NEED_CHECK_DEPEND_LIST += $(MODULE_MAKEFILE)

ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
  ifneq ($(filter $(PARTIAL_TRACE_LIB),$(COMPONENT)),)
    DEFINES := $(filter-out MODULE_TRACE_OFF,$(DEFINES))
  endif
endif
# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .obj .c .s .cpp .arm .ltp .det

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : update_lib update_dep


# *************************************************************************
# Set Shell
# *************************************************************************
#SHELL = $(ComSpec)

# *************************************************************************
# Construct $(COMPONENT) specific varible
# *************************************************************************
TARGLIB       =  $(subst \,/,$(OBJSDIR))/lib/$(strip $(COMPONENT)).lib

COMPOBJS_DIR  =  $(subst \,/,$(OBJSDIR))/$(strip $(COMPONENT))
OBJ_ARCHIVE   =  $(OBJSDIR)\$(COMPONENT)\$(strip $(COMPONENT)).via
OBJ_ARCHIVE_SORT  =  $(OBJSDIR)\$(COMPONENT)\$(strip $(COMPONENT))_sort.via

TARGDEP       =  $(subst \,/,$(RULESDIR))/$(strip $(COMPONENT)).dep
COMPDETS_DIR  =  $(subst \,/,$(RULESDIR))/$(strip $(COMPONENT))_dep

ifdef $($(COMPONENT))
  COMPBUILD_DIR =  $(FIXPATH)\make\$(strip $($(COMPONENT)))\$(strip $(COMPONENT))
  COMPPARENT_DIR = $(FIXPATH)\make\$(strip $($(COMPONENT)))
else
  COMPBUILD_DIR =  $(FIXPATH)\make\$(strip $(COMPONENT))
endif

ifdef DUAL_MODE_SUPPORT
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),MASTER)
    ifeq ($(strip $(MASTER)), TRUE)
      COMPBUILD_DIR =  $(FIXPATH)\make\$(strip $(COMPONENT))\master
    endif
  endif
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),SLAVE)
    ifeq ($(strip $(SLAVE)), TRUE)
      COMPBUILD_DIR =  $(FIXPATH)\make\$(strip $(COMPONENT))\slave
    endif
  endif
endif

MODULE_FOLDER = $(TARGDIR)\module
ifdef $($(COMPONENT))
COMPONENT_FOLDER = $(MODULE_FOLDER)\$(strip $($(COMPONENT)))\$(strip $(COMPONENT))
else
COMPONENT_FOLDER = $(MODULE_FOLDER)\$(strip $(COMPONENT))
endif
COMPONENT_LOG = $(COMPONENT_FOLDER)\$(strip $(COMPONENT))

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  MODULE_FOLDER = $(TARGDIR)\module\$(strip $(MODIS_UESIM))
  ifdef $($(COMPONENT))
    COMPONENT_FOLDER = $(strip $(MODULE_FOLDER))\$(strip $($(COMPONENT)))\$(strip $(COMPONENT))
  else
    COMPONENT_FOLDER = $(strip $(MODULE_FOLDER))\$(strip $(COMPONENT))
  endif
  COMPONENT_LOG = $(strip $(COMPONENT_FOLDER))\$(strip $(COMPONENT))
endif

# *************************************************************************
# Configure debug symbol compiler arguments
# *************************************************************************
ifndef DEBUG_MODULES
  DEBUG_MODULES =
endif

ifndef NON_DEBUG_MODULES
  NON_DEBUG_MODULES =
endif

ifdef CLEANROOM_CFLAGS
  ifneq ($(filter $(COMPONENT), $(CLEANROOM_COMP)),)
    CFLAGS += $(CLEANROOM_CFLAGS)
  endif
endif

ifneq ($(filter ALL,$(call Upper,$(DEBUG_MODULES))),)
  ifeq ($(strip $(COMPILER)),RVCT)
    CFLAGS += --debug --no_debug_macros
    CPLUSFLAGS += --debug --no_debug_macros
  endif
  ifeq ($(strip $(COMPILER)),ADS)
    CFLAGS += -g -gtp
    CPLUSFLAGS += -g -gtp
  endif
else
  ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(DEBUG_MODULES))),)
    ifeq ($(strip $(COMPILER)),RVCT)
      CFLAGS += --debug --no_debug_macros
      CPLUSFLAGS += --debug --no_debug_macros
    endif
    ifeq ($(strip $(COMPILER)),ADS)
      CFLAGS += -g -gtp
      CPLUSFLAGS += -g -gtp
    endif
  endif
endif

ifneq ($(filter ALL,$(call Upper,$(NON_DEBUG_MODULES))),)
  CFLAGS := $(filter-out -g -gtp --debug --no_debug_macros,$(strip $(CFLAGS)))
  CPLUSFLAGS := $(filter-out -g -gtp --debug --no_debug_macros,$(strip $(CPLUSFLAGS)))
else ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(NON_DEBUG_MODULES))),)
  CFLAGS := $(filter-out -g -gtp --debug --no_debug_macros,$(strip $(CFLAGS)))
  CPLUSFLAGS := $(filter-out -g -gtp --debug --no_debug_macros,$(strip $(CPLUSFLAGS)))
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    ifneq ($(filter --debug,$(strip $(CFLAGS))),)
      CFLAGS := $(filter-out --remove_unneeded_entities,$(strip $(CFLAGS)))
    endif
    ifneq ($(filter --debug,$(strip $(CPLUSFLAGS))),)
      CPLUSFLAGS := $(filter-out --remove_unneeded_entities,$(strip $(CPLUSFLAGS)))
    endif
  endif
endif

ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(NON_DEBUG_MODULES))),)
  $(info Module $(COMPONENT) is in NON_DEBUG mode)
else ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(DEBUG_MODULES))),)
  $(info Module $(COMPONENT) is in DEBUG mode)
else
  $(info Module $(COMPONENT) is in DEFALUT mode)
endif

# *************************************************************************
# Construct the list of object dependencies
# *************************************************************************
SRC_LIST := $(sort $(SRC_LIST))

ifdef SRC_RULE_FLAG32
  # SRC_RULE_FLAG32 means the asm file should be compiled by armasm using -32 flag
  SRCLIST1 := $(foreach file,$(SRC_LIST),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_FLAG32))),$(file),))
  SRCLIST0 := $(foreach file,$(SRC_LIST),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_FLAG32))),,$(file)))
else
  SRCLIST0 := $(SRC_LIST)
endif
ifdef SRC_RULE_PREPROCESS
  # SRC_RULE_PREPROCESS means the asm file needs to be preprocessed by armcc -E and then armasm
  SRCLIST2 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_PREPROCESS))),$(file),))
  SRCLIST0 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_PREPROCESS))),,$(file)))
endif

SRCLIST := $(subst .S,.s,$(subst .C,.c,$(SRC_LIST)))
CSRCS   := $(filter %.c, $(subst .C,.c,$(SRCLIST0)))
CPPSRCS := $(filter %.cpp, $(SRCLIST0))
ASRCS   := $(filter %.s, $(subst .S,.s,$(SRCLIST0)))
ASRCS1  := $(filter %.s, $(subst .S,.s,$(SRCLIST1)))
ASRCS2  := $(filter %.s, $(subst .S,.s,$(SRCLIST2)))
ARMSRCS := $(filter %.arm, $(SRCLIST0))

######################################
#clear the global include path for  tiny system.
######################################
ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
  ifeq ($(filter $(strip $(COMPONENT)),$(TS_COMPLIST)), $(strip $(COMPONENT)))
    INCDIRS := $(TS_INCDIRS)
  endif
endif
INCDIRS += $(INC_DIR)
INCDIRS := $(call uniq,$(INCDIRS))

ifeq ($(strip $(COMPONENT)),lgoem)
#INCDIRS += $(shell type make\wise\wise.inc)
endif

#COMP_DEFS is from $module.mak
DEFINES += $(COMP_DEFS)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifdef MODIS_DIS_OPTION
    DEFINES := $(filter-out $(MODIS_DIS_OPTION),$(DEFINES))
  endif
endif

ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
ifeq ($(strip $(COMPONENT)),wise)
WISE_INCDIRS = $(subst external_mmi\wise\wise_headers\$(strip $(BOARD_VER))\App,..\App,$(INCDIRS))
WISE_INCDIRS_APPS = $(subst external_mmi\wise\wise_headers\$(strip $(BOARD_VER))\apps,..\apps,$(WISE_INCDIRS))
CINCDIRS 	=  $(foreach inc, $(subst \,/,$(WISE_INCDIRS_APPS)),-I$(inc))
else
CINCDIRS 	=  $(foreach inc, $(subst \,/,$(INCDIRS)),-I$(inc))
endif
else
CINCDIRS 	=  $(foreach inc, $(subst \,/,$(INCDIRS)),-I$(inc))
endif

CDEFS 		=  $(foreach def, $(DEFINES),-D$(def))
A_CDEFS   = $(foreach def, $(strip $(COM_DEFS_FOR_$(strip $(PLATFORM)))),-D$(def)=$(def)) 

# if LCMMI is applied
ifeq ($(MMIDIR),lcmmi)
   INCDIRS  :=  $(subst PLUTOMMI,lcmmi,$(call Upper,$(INCDIRS)))
#   $(warning Include paths of $(COMPONENT) are $(INCDIRS))
endif

ifndef RVCT_MULTI_FILE
   RVCT_MULTI_FILE = NONE
endif
#*************************************************************************
# folder path check
#*************************************************************************

ifneq ($(strip $(NO_PCIBT)),TRUE)
 ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
   ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifeq ($(filter REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
     ifeq ($(strip $(VENDOR)),NONE)
-include make\~sub_compbld.tmp
 -include make\folderlist.bld
     ifneq ($(words $(FOLDERLIST)),0)
       ifeq ($(strip $(MODIS_CONFIG)),TRUE)
         CUSTOM_RELEASE_ORG := $(CUSTOM_RELEASE)
         CUSTOM_RELEASE := TRUE
         include make\modisConfig.mak
         CUSTOM_RELEASE := $(CUSTOM_RELEASE_ORG)
         CHECKLIST := $(CUS_REL_SRC_COMP) $(MODIS_EN_LIBS)
       else
         CHECKLIST := $(CUS_REL_SRC_COMP)
       endif
       COMP_TEMP := $(patsubst %\,%,$(dir $(subst /,\,$(SRC_LIST))))
       CHECKLIST_TMP := $(filter-out $(call Lower,$(CLEANROOM_COMP)),$(call Lower,$(CHECKLIST)))
       ifneq ($(filter $(call Lower,$(COMPONENT)),$(call Lower,$(CHECKLIST_TMP))),)
         COMP_TEMP += $(INC_DIR)
         TEMP1 := $(filter-out $(call Lower,$(FOLDERLIST)),$(call Lower,$(COMP_TEMP)))
         TEMP2 := $(filter-out $(call Lower,custom\\%),$(call Lower,$(TEMP1)))
         ifneq ($(strip $(TEMP2)),)
            PERMISSON_ERROR_PATH := $(foreach DIR,$(call Upper,$(TEMP2)),$(wildcard $(DIR)))
            NOT_EXISTED_PATH := $(filter-out $(call Upper,$(PERMISSON_ERROR_PATH)),$(call Upper,$(TEMP2)))
            ifneq ($(strip $(PERMISSON_ERROR_PATH)),)
              $(info Error: The following module include path violate PCIBT rules: $(PERMISSON_ERROR_PATH))
              $(info It may let subsidiary get build errors, please follow the SOP below to solve PCIBT error.)
              $(info ******************************************************************)
              $(info Please confirm the folders are existed and have at least one file(not include sub folder) under them first.)
              $(info 1.If NOT, please remove them from the INC_DIR/SRC_LIST in the makefile.)
              $(info 2.If YES and these folders could be opened to subsidiaries.)
              $(info - If you need to adjust the p4 permission , please contact the p4 admin.)
              $(info - If those folders were already opened to subsidiaries, please request BM to re-gen the make/folderlist.bld.)
              $(info - If you are working on an official release load locally, please add the new folder paths to make/folderlist.bld manually,)
              $(info   and the PCIBT errors would not happen again in the local codebase.)
              $(info 3.If these folders could NOT be opened to subsidiaries, please:)
              $(info - Do not use them in INC_DIR/SRC_LIST or move files under them to an opened folder.)
              $(info ******************************************************************)
            endif
            
            ifneq ($(strip $(NOT_EXISTED_PATH)),)
              $(info Error: The following module include path don't exist in perforce: $(NOT_EXISTED_PATH))
              $(info Please do not use them in INC_DIR/SRC_LIST.)
            endif
            ifneq ($(strip $(PCIBT_NO_STOP)),TRUE)
              $(error )
            endif
         endif
       endif
     endif
     endif
    endif
   endif
  endif
endif

# *************************************************************************
# Set View Path
# *************************************************************************
vpath
vpath %.obj $(COMPOBJS_DIR)
vpath %.det $(COMPDETS_DIR)

# XXX!!! To use predefine for assembler is a little difficult and
# usually can be replaced with C sources.
#ifeq ($(filter wise ijet_adp custom,$(COMPONENT)),)
ifeq ($(filter wise ijet_adp, $(COMPONENT)),)
ADEFS       = $(foreach def, $(COMP_DEFS),-pd "$(def) SETL {TRUE}")
else
ADEFS       = 
endif

ADEFS += $(foreach def, $(strip $(COM_DEFS_FOR_$(strip $(PLATFORM)))),-pd "$(def) SETL {TRUE}")

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  ADEFS += -pd "__KAL_RECORD_BOOTUP_LOG__ SETL {TRUE}"
endif

ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
  ADEFS += -pd "__BIND_TO_CHIP_BASIC__ SETL {TRUE}"
endif

ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
  ADEFS += -pd "__BIND_TO_KEY__ SETL {TRUE}"
endif

ifneq ($(filter BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
  ADEFS += -pd "__BIND_TO_CHIP__ SETL {TRUE}"
endif

ifneq ($(call Upper,$(strip $(PLATFORM))),MT6573)
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  ADEFS += -pd "__SV5_ENABLED__ SETL {TRUE}"
endif
endif


ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ifeq ($(call Upper,$(strip $(PLATFORM))),MT6276)
  ADEFS += -pd "DSP_BOOT_SEC SETL {TRUE}"
  endif
  ifeq ($(call Upper,$(strip $(PLATFORM))),MT6573)
  ADEFS += -pd "DSP_BOOT_SEC SETL {TRUE}"
  endif
endif

ifdef CARD_DOWNLOAD
  ifneq ($(filter bootloader bootloader_ext,$(strip $(COMPONENT))),)
    ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
      ADEFS += -pd "__CARD_DOWNLOAD__ SETL {TRUE}"
      CFLAGS += -D__CARD_DOWNLOAD__
      ifeq ($(strip $(CARD_DOWNLOAD)),FILESYSTEM_ON_CARD)
        ADEFS += -pd "__FS_CARD_DOWNLOAD__ SETL {TRUE}"
        CFLAGS += -D__FS_CARD_DOWNLOAD__
      endif
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        ADEFS += -pd "__UBL_NAND_FULL_DRIVER__ SETL {TRUE}"
        CFLAGS += -D__UBL_NAND_FULL_DRIVER__
      else
        ADEFS += -pd "__UBL_NOR_FULL_DRIVER__ SETL {TRUE}"
        CFLAGS += -D__UBL_NOR_FULL_DRIVER__ -D__NOR_FULL_DRIVER__
      endif
    endif
  endif
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
  ADEFS += -pd "__DEMAND_PAGING__ SETL {TRUE}"
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
  ADEFS += -pd "__DEMAND_PAGING__ SETL {TRUE}"
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
  ifeq ($(findstring __CPU_ARM7EJ_S__,$(strip $(DEFINES))),)
    ADEFS += -pd "__KAL_VM__ SETL {TRUE}"
  endif  
endif

ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
  ADEFS += -pd "__DEMAND_PAGING__ SETL {TRUE}"
endif

ifeq ($(strip $(EMMC_BOOTING)),MIXED)
  ADEFS += -pd "__DEMAND_PAGING__ SETL {TRUE}"
endif

ifeq ($(filter __NOR_FLASH_BOOTING__,$(strip $(DEFINES))),)
  ifdef NEED_BUILD_BOOTLOADER
    ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
      ifeq ($(strip $(COMPONENT)),init)
        ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        ifeq ($(strip $(EMMC_BOOTING)),NONE)
          CFLAGS += -D__BL_ENABLE__
          CFLAGS += -DREMAPPING
          ADEFS += -pd "__BL_ENABLE__ SETL {TRUE}"
          ADEFS += -pd "REMAPPING SETL {TRUE}"
        endif  
        endif
      endif
      ifeq ($(strip $(COMPONENT)),custom)
        ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
          CFLAGS += -D__BL_ENABLE__
          CFLAGS += -DREMAPPING
          ADEFS += -pd "__BL_ENABLE__ SETL {TRUE}"
          ADEFS += -pd "REMAPPING SETL {TRUE}"
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
   ADEFS += -pd "__KAL_RECORD_BOOTUP_LOG__ SETL {TRUE}"
endif

ifneq ($(filter __KAL_STACK_ISOLATION__,$(strip $(DEFINES))),)
  ADEFS += -pd "__KAL_STACK_ISOLATION__ SETL {TRUE}"
endif

ifneq ($(filter __KAL_STACK_EXTENSIBLE__,$(strip $(DEFINES))),)
  ADEFS += -pd "__KAL_STACK_EXTENSIBLE__ SETL {TRUE}"
endif

ifneq ($(filter __EVENT_BASED_TIMER__,$(strip $(DEFINES))),)
  ADEFS += -pd "__EVENT_BASED_TIMER__ SETL {TRUE}"
endif

ifeq ($(strip $(COMPONENT)),nucleus_ctrl_code)
  ADEFS       += -pd "$(strip $(PLATFORM)) SETL {TRUE}"
endif

ifeq ($(strip $(COMPONENT)),nucleus_v2_ctrl_code)
  ADEFS       += -pd "$(strip $(PLATFORM)) SETL {TRUE}"
endif
   
ifeq ($(DEBUG_SAVE_CUR_THREAD),TRUE)
  ADEFS       +=  -pd "__DEBUG_SAVE_CUR_THREAD__ SETL {TRUE}"
endif

ifeq ($(PRODUCTION_RELEASE),TRUE)
  ADEFS       +=  -pd "__PRODUCTION_RELEASE__ SETL {TRUE}"
endif

ifeq ($(strip $(L1_GPRS)),TRUE)
  ifeq ($(strip $(L1_WCDMA)),TRUE)
    ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
       ifeq ($(findstring nucleus_ctrl_code,$(strip $(COMPONENT))),nucleus_ctrl_code) 
          ADEFS       += -pd "__MA_L1__ SETL {TRUE}"
       endif
       ifeq ($(findstring nucleus_ctrl_code_ma,$(strip $(COMPONENT))),nucleus_ctrl_code_ma) 
          ADEFS       += -pd "__MA_L1__ SETL {TRUE}"
       endif
    endif
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  ADEFS       +=  -pd "KAL_ON_NUCLEUS SETL {TRUE}"
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  ADEFS       +=  -pd "KAL_ON_NUCLEUS SETL {TRUE}"
  ADEFS       +=  -pd "__NUCLEUS_VERSION_2__ SETL {TRUE}"
endif

ifeq ($(strip $(RTOS)),THREADX)
  ADEFS       +=  -pd "KAL_ON_THREADX SETL {TRUE}"
endif

ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
   ADEFS += -pd "__CHIP_VERSION_CHECK__ SETL {TRUE}"
endif

ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
   ADEFS += -pd "__MEUT__ SETL {TRUE}"
   ADEFS += -pd "__UDVT__ SETL {TRUE}"
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifeq ($(strip $(COMPONENT)),nucleus_ctrl_code)
    ADEFS       += -pd "__WATCHDOG_RESTART_DISABLE__ SETL {TRUE}"
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
  ifeq ($(strip $(COMPONENT)),nucleus_v2_ctrl_code)
    ADEFS       += -pd "__WATCHDOG_RESTART_DISABLE__ SETL {TRUE}"
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
  ifeq ($(strip $(COMPONENT)),nucleus_ctrl_code)
    ADEFS       += -pd "__WATCHDOG_RESTART_DISABLE__ SETL {TRUE}"
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
  ifeq ($(strip $(COMPONENT)),nucleus_v2_ctrl_code)
    ADEFS       += -pd "__WATCHDOG_RESTART_DISABLE__ SETL {TRUE}"
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
endif

ifeq ($(strip $(KEYPAD_DEBUG_TRACE)),TRUE)
  ADEFS += -pd "__KEYPAD_DEBUG_TRACE__ SETL {TRUE}"
endif

ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
  ADEFS += -pd "__ZIMAGE_SUPPORT__ SETL {TRUE}"
endif

ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_PLATFORM)),)
  ADEFS       += -pd "ARM9_MMU SETL {TRUE}"
endif

ifneq ($(filter $(strip $(PLATFORM)),$(ARM11_PLATFORM)),)
  ADEFS       += -pd "$(strip $(PLATFORM)) SETL {TRUE}"
  ADEFS       += -pd "ARM11_MMU SETL {TRUE}"
  ADEFS       += -pd "__ARM1176__ SETL {TRUE}"
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
  endif
endif

ifneq ($(filter MT6251 MT6252 MT6253L,$(PLATFORM)),)
  ADEFS += -pd "__SERIAL_FLASH_EN__ SETL {TRUE}"
endif

ifeq ($(strip $(PLATFORM)),MT6256)
  ADEFS       += -pd "ESAL_AR_STK_FPU_SUPPORT SETL {TRUE}"
  ADEFS       += -pd "__ARM_FPUV2__ SETL {TRUE}"
else
  ADEFS       += -pd "ESAL_AR_STK_FPU_SUPPORT SETL {FALSE}"
  ADEFS       += -pd "__ARM_FPUV2__ SETL {FALSE}"
endif

ifeq ($(strip $(USB_BOOTUP_TRACE)),TRUE)
  ADEFS += -pd "__USB_BOOTUP_TRACE__ SETL {TRUE}"
endif

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
  ADEFS += -pd "__SERIAL_FLASH_EN__ SETL {TRUE}"
  CFLAGS += -D__SERIAL_FLASH_EN__
  ADEFS += -pd "__SERIAL_FLASH_SUPPORT__ SETL {TRUE}"
  CFLAGS += -D__SERIAL_FLASH_SUPPORT__
endif

ifdef KAL_ASSERT_LEVEL
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL4)
    ADEFS += -pd "__KAL_ASSERT_LEVEL4__ SETL {TRUE}"
  endif
endif

ifeq ($(strip $(TST_WRITE_TO_FILE)),TRUE)
   ADEFS += -pd "__TST_WRITE_TO_FILE__ SETL {TRUE}"
endif

ifeq ($(strip $(NORFLASH_NON_XIP_SUPPORT)),TRUE)
  ADEFS += -pd "__NORFLASH_NON_XIP_SUPPORT__ SETL {TRUE}"
endif
## end of ADEFS

######################################
#set the compile option for tiny system.
######################################
ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
  ifeq ($(filter $(strip $(COMPONENT)),$(TS_COMPLIST)), $(strip $(COMPONENT)))
    ADEFS += -pd "__TINY_SYS_TS__ SETL {TRUE}"
    CFLAGS += -D__TINY_SYS_TS__
  else
    ADEFS += -pd "__TINY_SYS_AP__ SETL {TRUE}"
    CFLAGS += -D__TINY_SYS_AP__
  endif
endif

# if any component needs to interwork with other ARM mode components, it should
# add "APCS_INTWORK" into its .def
ifneq ($(filter -DAPCS_INTWORK,$(CDEFS)),)
  CINTWORK    =  $(APCSINT)
  AINTWORK    =  $(APCSINT)
else
  CINTWORK    =
  AINTWORK    =
endif

# Compiler settings for specific components
#the following will be removed after *.def are updated
CMPLR       = $(CC)

ifneq ($(filter __HSUPA_SUPPORT__, $(MODULE_DEFS)),)
  ifeq ($(strip $(COMPONENT)),kal)
    CMPLR       := $(CC32)
    CINTWORK    =  $(APCSINT)
    AINTWORK    =  $(APCSINT)
  endif
  ifneq ($(filter nucleus_v2%, $(COMPONENT)),)
    CMPLR       := $(CC32)
    CINTWORK    =  $(APCSINT)
    AINTWORK    =  $(APCSINT)
    CFLAGS += -Otime
  endif
endif #  __HSUPA_SUPPORT__

ifeq ($(strip $(COMPONENT)),kal_ma)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(strip $(COMPONENT)),l1audio32)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(strip $(COMPONENT)),fota)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(strip $(COMPONENT)),l1audio)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(strip $(COMPONENT)),dp_engine)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime -Ono_autoinline
endif
ifeq ($(strip $(COMPONENT)),opengl)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime 
endif
ifeq ($(strip $(COMPONENT)),opengl16)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime 
endif
ifeq ($(strip $(COMPONENT)),rompatch)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime
endif
ifneq ($(filter bootloader bootloader_ext,$(strip $(COMPONENT))),)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(strip $(COMPONENT)),gdi_arm)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime
endif

ifeq ($(strip $(COMPONENT)),postproc_sec)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime
endif

ifeq ($(strip $(COMPONENT)),media_sec32)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime -O2 
endif

ifeq ($(strip $(COMPONENT)),gfx_core32)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime
endif

ifeq ($(strip $(COMPONENT)),vrt)
   CMPLR       := $(CC32)
   CFLAGS      += -Otime
endif

ifeq ($(strip $(COMPONENT)),lgoem)
  CFLAGS      := --cpu ARM9EJ-S   --apcs /noswst/interwork -O3 -Ospace --dwarf2
  CFLAGS      += --thumb  --no_data_reorder  --pointer_alignment=4  --no_dollar
  CFLAGS      += --no_multibyte_chars  --alternative_tokens --loose_implicit_cast
  CFLAGS      += --diag_suppress  1,9,47,66,174,177,550,940,2874
endif

ifeq ($(strip $(COMPILER)),RVCT)
   CFLAGS += --bss_threshold=0
   CPLUSFLAGS += --bss_threshold=0
endif

ifeq ($(strip $(COMPILER)),ADS)
   CPP_CMPLR = $(CPPC)
   CPLUSFLAGS = $(CFLAGS)
#   MD = -MD
   depend=-depend
else
   CPP_CMPLR = $(CMPLR)
#   MD = --md
   depend=--depend
endif   

ifeq ($(COMPONENT),j2me_nemo_cldc)
    CMPLR       := $(CC)
    CINTWORK    =  $(APCSINT)
    ADEFS       = 
    AINTWORK    =  $(APCSINT)
    ifeq ($(strip $(COMPILER)),ADS)
        CFLAGS      +=  -Ecf -W
        AFLAGS      = -g -littleend -cpu ARM9EJ-S -32
        ADEFS       = -pd "THREAD_STACK_SWITCH SETL {TRUE}"
    else
        CFLAGS      +=  -W --diag_suppress 3011,1608,1658
        AFLAGS      = --debug --littleend --cpu ARM9EJ-S --32
        ADEFS       = --pd "THREAD_STACK_SWITCH SETL {TRUE}"
    endif
endif

ifeq ($(COMPONENT),j2me_nemo_fdlibm)
    CMPLR       := $(CC)
    CINTWORK    =  $(APCSINT)
    ifeq ($(strip $(COMPILER)),ADS)
        CFLAGS      +=  -Ecf -W
    else
        CFLAGS      :=  --cpu ARM9EJ-S --littleend -O0 -W --diag_suppress 3011,1608,1658 --remove_unneeded_entities -D__RVCT__
    endif
endif

ifeq ($(strip $(COMPONENT)),video_codec)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime -O2 
endif

ifeq ($(strip $(COMPONENT)),video_codec_sec)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime -O2 
endif

# Generate module information
ifeq ($(strip $(GEN_MODULE_INFO)),TRUE)

COMP_TEMP:=$(shell if not exist $(strip $(MODULE_FOLDER)) md $(strip $(MODULE_FOLDER)))
COMP_TEMP:=$(shell if exist $(strip $(COMPONENT_FOLDER)) rmdir /S /Q $(strip $(COMPONENT_FOLDER)))
COMP_TEMP:=$(shell if not exist $(strip $(COMPONENT_FOLDER)) md $(strip $(COMPONENT_FOLDER)))

ifneq ($(words $(SRCLIST)),0)
  ifeq ($(call lte,$(call strlen,$(SRCLIST)),32000),T)
    COMP_TEMP:=$(shell perl tools\echoLongString4.pl $(COMPONENT_LOG).lis $(SRCLIST))
    COMP_TEMP:=$(shell perl tools\lnitem.pl $(COMPONENT_LOG).lis)
  else
    COMP_TEMP:=$(foreach com,$(SRCLIST),$(shell echo $(com)>>$(COMPONENT_LOG).lis))
  endif
else
  COMP_TEMP:=$(shell echo. >$(COMPONENT_LOG).lis)
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(words $(INCDIRS)),0)
    ifeq ($(call lte,$(call strlen,$(INCDIRS)),32000),T)
      COMP_TEMP:=$(shell tools\strcmpex.exe abc abc e $(COMPONENT_LOG).inc $(INCDIRS))
      COMP_TEMP:=$(shell perl tools\lnitem.pl $(COMPONENT_LOG).inc)
    else
      COMP_TEMP:=$(foreach com,$(INCDIRS),$(shell echo $(com) >>$(COMPONENT_LOG).inc))
    endif
  else
    COMP_TEMP:=$(shell echo. >$(COMPONENT_LOG).inc)
  endif
else
  ifneq ($(words $(INC_DIR)),0)
    ifeq ($(call lte,$(call strlen,$(INC_DIR)),32000),T)
      COMP_TEMP:=$(shell tools\strcmpex.exe abc abc e $(COMPONENT_LOG).inc $(INC_DIR))
      COMP_TEMP:=$(shell perl tools\lnitem.pl $(COMPONENT_LOG).inc)
    else
      COMP_TEMP:=$(foreach com,$(INC_DIR),$(shell echo $(com) >>$(COMPONENT_LOG).inc))
    endif
  else
    COMP_TEMP:=$(shell echo. >$(COMPONENT_LOG).inc)
  endif
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(words $(DEFINES)),0)
    ifeq ($(call lte,$(call strlen,$(DEFINES)),32000),T)
      COMP_TEMP:=$(shell perl tools\echoLongString4.pl $(COMPONENT_LOG).def $(DEFINES))
      COMP_TEMP:=$(shell perl tools\lnitem.pl $(COMPONENT_LOG).def)
    else
      COMP_TEMP:=$(foreach def,$(DEFINES),$(shell echo $(def) >>$(COMPONENT_LOG).def))
    endif
  else
    COMP_TEMP:=$(shell echo. >$(COMPONENT_LOG).def)
  endif
else
  ifneq ($(words $(COMP_DEFS)),0)
    COMP_TEMP:=$(shell perl tools\echoLongString4.pl $(COMPONENT_LOG).def $(COMP_DEFS))
    COMP_TEMP:=$(shell perl tools\lnitem.pl $(COMPONENT_LOG).def)
  else
    COMP_TEMP:=$(shell echo. >$(COMPONENT_LOG).def)
  endif
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  COMP_TEMP:=$(shell perl tools\echoLongString5.pl $(COMPONENT_LOG).ade ADEFS $(ADEFS))
endif

else ifeq ($(filter $(MAKECMDGOALS),setup_env),)
  SRC_LIST_TMP := $(foreach file,$(sort $(call Lower,$(SRC_LIST))),$(if $(filter $(basename $(notdir $(file))),$(basename $(notdir $(filter-out $(file),$(call Lower,$(SRC_LIST)))))),$(file),))
  ifneq ($(strip $(SRC_LIST_TMP)),)
    $(info The following files are conflicted in SRC_LIST from $(strip $(COMPONENT)).mak:)
    $(info $(strip $(SRC_LIST_TMP)))
    $(error SRC_LIST)
  endif
endif
# end

# *************************************************************************
# Library Targets
# *************************************************************************
update_lib: $(TARGLIB)
	@if exist $(RULESDIR)\$(strip $(COMPONENT))_dep rd /s /q $(RULESDIR)\$(strip $(COMPONENT))_dep


ifeq ($(strip $(RVCT_MULTI_FILE)),NONE)

$(TARGLIB) :

   # If library for customer release exists.
   # Copy and update it or create a new one
   # mbis time probe
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (@perl -e "print 'T_S,$@,L,'. time . \"\n\"";>>$(TARGDIR)\log\mbis\$(strip $(COMPONENT))\$(*F)".mbis")
	@if exist $(OBJ_ARCHIVE) \
		(del /f /q $(OBJ_ARCHIVE))
	@if exist $(OBJ_ARCHIVE_SORT) \
		(del /f /q $(OBJ_ARCHIVE_SORT))

ifneq ($(words $(CFLAGS)),0)
	@echo CFLAGS = $(strip $(CFLAGS))
endif
ifneq ($(words $(CPLUSFLAGS)),0)
	@echo CPLUSFLAGS = $(strip $(CPLUSFLAGS))
endif
ifneq ($(words $(AFLAGS)),0)
	@echo AFLAGS = $(strip $(AFLAGS))
endif
ifneq ($(words $(ADEFS)),0)
	@echo ADEFS = $(strip $(ADEFS))
endif

	@for %%i in ($(COMPOBJS_DIR)/*.obj) do \
		echo $(COMPOBJS_DIR)/%%i>>$(OBJ_ARCHIVE)
	@perl .\tools\sortobj.pl $(OBJ_ARCHIVE) $(OBJ_ARCHIVE_SORT)

ifneq ($(filter $(PARTIAL_TRACE_LIB),$(COMPONENT)),)
	@if exist $(FIXPATH)\$(CUS_MTK_LIB_TRACE)\$(strip $(COMPONENT)).lib \
		(copy /z $(FIXPATH)\$(CUS_MTK_LIB_TRACE)\$(strip $(COMPONENT)).lib $(subst /,\,$(TARGLIB)))
else
	@if exist $(FIXPATH)\$(CUS_MTK_LIB)\$(strip $(COMPONENT)).lib \
		(copy /z $(FIXPATH)\$(CUS_MTK_LIB)\$(strip $(COMPONENT)).lib $(subst /,\,$(TARGLIB)))
endif

	$(strip $(LIB)) -create $(TARGLIB) $(VIA) $(OBJ_ARCHIVE_SORT)

	@echo $(TARGLIB) is updated

	@if exist $(OBJ_ARCHIVE) \
		(del /f /q $(OBJ_ARCHIVE))
	@if exist $(OBJ_ARCHIVE_SORT) \
		(del /f /q $(OBJ_ARCHIVE_SORT))

ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
  ifneq ($(ACTION),remake)
    # delete $module.dep, otherwise there will be duplicated info appended, becasue *.det are already extracted from $module.dep
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep del /q $(RULESDIR)\$(strip $(COMPONENT)).dep
  endif
endif
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det type $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det >> $(RULESDIR)\$(strip $(COMPONENT)).dep
	@if not $(ACTION)==remake if not exist $(RULESDIR)\$(strip $(COMPONENT)).dep if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det type $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det > $(RULESDIR)\$(strip $(COMPONENT)).dep
ifneq ($(ACTION),remake)
  # generate r\comp_dep\$module.det to be included by Gsm2.mak, in order to check $module.lib with all source/header files in that module
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep (perl tools\pack_dep_gen.pl $(RULESDIR)\comp_dep\$(strip $(COMPONENT)).det $(strip $(COMPONENT)).lib $(RULESDIR)\$(strip $(COMPONENT))_dep \w+\.det) else (if exist $(RULESDIR)\comp_dep\$(strip $(COMPONENT)).det del $(RULESDIR)\comp_dep\$(strip $(COMPONENT)).det)
endif
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det del /f /q $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det
	@if exist $(RULESDIR)\$(strip $(COMPONENT))_dep rd /s /q $(RULESDIR)\$(strip $(COMPONENT))_dep
ifeq ($(findstring j2me,$(strip $(COMPONENT))),j2me)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),jblendia)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),ijet_adp)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),nemo_adp)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (@perl -e "print 'T_E,$@,L,'. time . \"\n\"";>>$(TARGDIR)\log\mbis\$(strip $(COMPONENT))\$(*F)".mbis")
endif


ifeq ($(strip $(RVCT_MULTI_FILE)),MULTI_FILE)
ifeq ($(strip $(COMPILER)),RVCT)

$(TARGLIB):
   # mbis time probe
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (@perl -e "print 'T_S,$@,L,'. time . \"\n\"";>>$(TARGDIR)\log\mbis\$(strip $(COMPONENT))\$(*F)".mbis")
	@echo Compiling $< ...
	@tools\strcmpex.exe $(ACTION) remake e $(*F).via  $(CINTWORK) -c $(CFLAGS) $(CDEFS) $(CINCDIRS) --multifile -o $(COMPOBJS_DIR)/$(strip $(COMPONENT)).obj $(CPPSRCS) $(CSRCS) $<
	@tools\strcmpex.exe $(ACTION) remake n $(*F).via  $(CINTWORK) -c $(CFLAGS) $(CDEFS) $(CINCDIRS) --multifile -o $(COMPOBJS_DIR)/$(strip $(COMPONENT)).obj $(CPPSRCS) $(CSRCS) $<
	@if exist $(*F).via tools\warp.exe $(*F).via
	@if exist $(*F).via $(CMPLR) -via $(*F).via

	@if exist $(OBJ_ARCHIVE) \
		(del /f /q $(OBJ_ARCHIVE))
	@if exist $(OBJ_ARCHIVE_SORT) \
		(del /f /q $(OBJ_ARCHIVE_SORT))

ifneq ($(words $(CFLAGS)),0)
	@echo CFLAGS = $(strip $(CFLAGS))
endif
ifneq ($(words $(CPLUSFLAGS)),0)
	@echo CPLUSFLAGS = $(strip $(CPLUSFLAGS))
endif
ifneq ($(words $(AFLAGS)),0)
	@echo AFLAGS = $(strip $(AFLAGS))
endif
ifneq ($(words $(ADEFS)),0)
	@echo ADEFS = $(strip $(ADEFS))
endif

	@for %%i in ($(COMPOBJS_DIR)/*.obj) do \
		echo $(COMPOBJS_DIR)/%%i>>$(OBJ_ARCHIVE)
	@perl .\tools\sortobj.pl $(OBJ_ARCHIVE) $(OBJ_ARCHIVE_SORT)

ifneq ($(filter $(PARTIAL_TRACE_LIB),$(COMPONENT)),)
	@if exist $(FIXPATH)\$(CUS_MTK_LIB_TRACE)\$(strip $(COMPONENT)).lib \
		(copy /z $(FIXPATH)\$(CUS_MTK_LIB_TRACE)\$(strip $(COMPONENT)).lib $(subst /,\,$(TARGLIB)))
else
	@if exist $(FIXPATH)\$(CUS_MTK_LIB)\$(strip $(COMPONENT)).lib \
		(copy /z $(FIXPATH)\$(CUS_MTK_LIB)\$(strip $(COMPONENT)).lib $(subst /,\,$(TARGLIB)))
endif

	$(strip $(LIB)) -create $(TARGLIB) $(VIA) $(OBJ_ARCHIVE_SORT)

	@echo $(TARGLIB) is updated

	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det type $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det >> $(RULESDIR)\$(strip $(COMPONENT)).dep
	@if not $(ACTION)==remake if not exist $(RULESDIR)\$(strip $(COMPONENT)).dep if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det type $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det > $(RULESDIR)\$(strip $(COMPONENT)).dep
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det del /f /q $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det
	@if exist $(RULESDIR)\$(strip $(COMPONENT))_dep rd /s /q $(RULESDIR)\$(strip $(COMPONENT))_dep
ifeq ($(findstring j2me,$(strip $(COMPONENT))),j2me)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),jblendia)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),ijet_adp)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),nemo_adp)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
endif
endif
   # mbis time probe   
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (@perl -e "print 'T_E,$@,L,'. time . \"\n\"";>>$(TARGDIR)\log\mbis\$(strip $(COMPONENT))\$(*F)".mbis")

setup_env:
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(strip $(GEN_MODULE_INFO)),TRUE)
	-@if not exist $(TARGDIR)\via md $(TARGDIR)\via
	@tools\strcmpex.exe abc abc e $(TARGDIR)\via\$(strip $(COMPONENT)).via $(CINTWORK) $(CDEFS)
	@tools\strcmpex.exe abc abc e $(TARGDIR)\via\$(strip $(COMPONENT))_inc.via $(CINCDIRS)
#workaround for *.via file didn't created when variable is empty.
ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
	@if not exist $(TARGDIR)\via\$(strip $(COMPONENT)).via (@echo off > $(TARGDIR)\via\$(strip $(COMPONENT)).via)
	@if not exist $(TARGDIR)\via\$(strip $(COMPONENT))_inc.via (@echo off > $(TARGDIR)\via\$(strip $(COMPONENT))_inc.via)
endif
	@tools\warp.exe $(TARGDIR)\via\$(strip $(COMPONENT)).via
	@tools\warp.exe $(TARGDIR)\via\$(strip $(COMPONENT))_inc.via
	-@if not exist $(TARGDIR)\log\$(strip $(COMPONENT)) md $(TARGDIR)\log\$(strip $(COMPONENT))
	-@if not exist $(TARGDIR)\dep\$(strip $(COMPONENT)) md $(TARGDIR)\dep\$(strip $(COMPONENT))
  else
	@echo Generating $(COMPONENT) information is done.
  endif
else
	@echo $(COMPONENT) MoDIS module setup is done.
endif

# *************************************************************************
# Dependency Targets
# *************************************************************************
update_dep : $(TARGDEP)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (@perl -e "print 'T_S,$@,D,'. time . \"\n\"";>>$(TARGDIR)\log\mbis\$(strip $(COMPONENT))\$@".mbis")
	@if exist $(TARGDIR)\dep rd /s /q $(TARGDIR)\dep

$(TARGDEP) :
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det type $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det >> $(RULESDIR)\$(strip $(COMPONENT)).dep
	-@if not exist $(RULESDIR)\$(strip $(COMPONENT)).dep if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det type $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det > $(RULESDIR)\$(strip $(COMPONENT)).dep
	@if exist $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det del /f /q $(RULESDIR)\$(strip $(COMPONENT))_dep\*.det
	@if exist $(RULESDIR)\$(strip $(COMPONENT))_dep rd /s /q $(RULESDIR)\$(strip $(COMPONENT))_dep
ifeq ($(findstring j2me,$(strip $(COMPONENT))),j2me)
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),jblendia)
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),ijet_adp)
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
ifeq ($(strip $(COMPONENT)),nemo_adp)
	@if exist $(RULESDIR)\$(strip $(COMPONENT)).dep copy /y $(RULESDIR)\$(strip $(COMPONENT)).dep make\$(strip $(COMPONENT))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (@perl -e "print 'T_E,$@,D,'. time . \"\n\"";>>$(TARGDIR)\log\mbis\$(strip $(COMPONENT))\$@".mbis")

# *************************************************************************
# Component Targets
# *************************************************************************

define target_compile_c_obj
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if $$(ACTION)== remake $$(CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT)).via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -c $$(CFLAGS) -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake $$(CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT)).via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -c $$(CFLAGS) $$(depend) $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if not $$(ACTION)==remake if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_scan_c_det
$(2): $(1)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Pre-compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT)).via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -M $$< >$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_compile_cpp_obj
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if $$(ACTION)== remake $$(CPP_CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT)).via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -c $$(CPLUSFLAGS) -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake $$(CPP_CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT)).via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -c $$(CPLUSFLAGS) $$(depend) $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if not $$(ACTION)==remake if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_scan_cpp_det
$(2): $(1)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Pre-compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(CPP_CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT)).via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -M $$< >$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_compile_asm_obj
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if $$(ACTION)==remake $$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$< -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake $$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$< $$(depend) $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if not $$(ACTION)==remake if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_scan_asm_det
$(2): $(1)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Pre-compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -M $$< >$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_compile1_asm_obj
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(ASM) $$(AINTWORK) $$(AFLAGS) -32 $$< -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_scan1_asm_det
$(2): $(1)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Pre-compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -M $$< >$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d 2>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat> $$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_compile2_asm_obj
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d
	@echo Pre-compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@tools\strcmpex.exe abc abc e $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via $$(A_CDEFS) -D$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))=$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))
	@if exist $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via tools\warp.exe $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via
	@$$(CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via -E $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake $$(CMPLR) -M $$(VIA) $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via $$(VIA) $$(strip $$(TARGDIR))\via\$$(strip $$(COMPONENT))_inc.via $$< >>$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@echo Compiling $$< ... >>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if $$(ACTION)==remake $$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if not $$(ACTION)==remake $$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s $$(depend) $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d type $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d | find /V "$$(basename $$(notdir $$@)).s" >>$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d
	@if exist $$(strip $$(OBJSDIR))\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).s (del /q $$(strip $$(OBJSDIR))\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).s)
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat >$$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if exist $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via del /f /q $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via   
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef

define target_scan2_asm_det
$(2): $(1)
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_S,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
	@echo Pre-compiling $$< ... >$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@tools\strcmpex.exe abc abc e $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via $$(A_CDEFS) -D$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))=$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER)) $$(CINCDIRS)
	@if exist $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via tools\warp.exe $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via
	@$$(CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via -E $$< -o $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).s >>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(CMPLR) $$(VIA) $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via -M $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).obj >$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d 2>>$$(strip $$(TARGDIR))\log\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).log
	@$$(ASM) $$(VIA) $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via $$(AFLAGS) $$(ADEFS) -M $$(AINTWORK) $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).s >$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d type $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\~$$(basename $$(notdir $$@)).d | find /V "$$(basename $$(notdir $$@)).s" >>$$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).s del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).s >nul
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d perl .\tools\pack_dep.pl $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d tools\copy_mmi_include_h.bat >$$(RULESDIR)\$$(strip $$(COMPONENT))_dep\$$(basename $$(notdir $$@)).det
	@if exist $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d del /f /q $$(strip $$(TARGDIR))\dep\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@)).d > nul
	@if exist $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via del /f /q $$(strip $$(TARGDIR))\via\$$(basename $$(notdir $$@))_det.via
   # mbis time probe
	@if /I "$$(strip $$(MBIS_EN_OBJ_LOG))" EQU "TRUE" (@perl -e "print 'T_E,$$(@F),O,'. time . \"\n\"";>>$$(strip $$(TARGDIR))\log\mbis\$$(strip $$(COMPONENT))\$$(basename $$(notdir $$@))".mbis")
endef


$(foreach argu,$(CSRCS), \
  $(eval COBJ := $(patsubst %.c,%.obj, $(notdir $(subst \,/,$(argu))))) \
  $(eval CDET := $(patsubst %.c,%.det, $(notdir $(subst \,/,$(argu))))) \
  $(eval $(call target_compile_c_obj,$(argu),$(COBJ))) \
  $(eval $(call target_scan_c_det,$(argu),$(CDET))) \
  $(eval $(TARGLIB): $(COBJ)) \
  $(eval $(TARGDEP): $(CDET)) \
)

$(foreach argu,$(CPPSRCS), \
  $(eval CPPOBJ := $(patsubst %.cpp,%.obj, $(notdir $(subst \,/,$(argu))))) \
  $(eval CPPDET := $(patsubst %.cpp,%.det, $(notdir $(subst \,/,$(argu))))) \
  $(eval $(call target_compile_cpp_obj,$(argu),$(CPPOBJ))) \
  $(eval $(call target_scan_cpp_det,$(argu),$(CPPDET))) \
  $(eval $(TARGLIB): $(CPPOBJ)) \
  $(eval $(TARGDEP): $(CPPDET)) \
)

$(foreach argu,$(ASRCS), \
  $(eval AOBJ := $(patsubst %.s,%.obj, $(notdir $(subst \,/,$(argu))))) \
  $(eval ADET := $(patsubst %.s,%.det, $(notdir $(subst \,/,$(argu))))) \
  $(eval $(call target_compile_asm_obj,$(argu),$(AOBJ))) \
  $(eval $(call target_scan_asm_det,$(argu),$(ADET))) \
  $(eval $(TARGLIB): $(AOBJ)) \
  $(eval $(TARGDEP): $(ADET)) \
)

$(foreach argu,$(ARMSRCS), \
  $(eval ARMOBJ := $(patsubst %.arm,%.obj, $(notdir $(subst \,/,$(argu))))) \
  $(eval ARMDET := $(patsubst %.arm,%.det, $(notdir $(subst \,/,$(argu))))) \
  $(eval $(call target_compile_asm_obj,$(argu),$(ARMOBJ))) \
  $(eval $(call target_scan_asm_det,$(argu),$(ARMDET))) \
  $(eval $(TARGLIB): $(ARMOBJ)) \
  $(eval $(TARGDEP): $(ARMDET)) \
)

$(foreach argu,$(ASRCS1), \
  $(eval AOBJ1 := $(patsubst %.s,%.obj, $(notdir $(subst \,/,$(argu))))) \
  $(eval ADET1 := $(patsubst %.s,%.det, $(notdir $(subst \,/,$(argu))))) \
  $(eval $(call target_compile1_asm_obj,$(argu),$(AOBJ1))) \
  $(eval $(call target_scan1_asm_det,$(argu),$(ADET1))) \
  $(eval $(TARGLIB): $(AOBJ1)) \
  $(eval $(TARGDEP): $(ADET1)) \
)

$(foreach argu,$(ASRCS2), \
  $(eval AOBJ2 := $(patsubst %.s,%.obj, $(notdir $(subst \,/,$(argu))))) \
  $(eval ADET2 := $(patsubst %.s,%.det, $(notdir $(subst \,/,$(argu))))) \
  $(eval $(call target_compile2_asm_obj,$(argu),$(AOBJ2))) \
  $(eval $(call target_scan2_asm_det,$(argu),$(ADET2))) \
  $(eval $(TARGLIB): $(AOBJ2)) \
  $(eval $(TARGDEP): $(ADET2)) \
)

# *************************************************************************
# Include dependencies for this component (updated by ScanDeps)
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
ifneq ($(filter remake,$(strip $(ACTION))),)
-include $(RULESDIR)\$(strip $(COMPONENT)).dep
else ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
-include $(RULESDIR)\$(strip $(COMPONENT)).dep
endif
endif

