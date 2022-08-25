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
# *************************************************************************
# GSM2.MAK  - GSM phase 2 master project build script
#
#  DISCUSSION:
#     CUSTOMER = MTK, PLUTO ...
#     PROJECT = L1S, GSM, GPRS
#
#  USAGE:
#     tools\make.exe -f[make file] [build_flag] <CUSTOMER> <PROJECT> <ACTION>
#
#     Example:
#     tools\make.exe -fmake\gsm2.mak -r -R CUSTOMER=mtk PROJECT=gprs new
#
#  IMPORTANT NOTES:
#
# *************************************************************************

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .ltp .lis

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : new cleanall emigen cmmgen asngen nvram_auto_gen codegen asnregen update genlog cleanbin genverno gencustominfo gencustomlists cksysdrv cksysdrv_slim cksysdrv_clean resgen scan remake libs code_generate cleancodegen cleanmod done gen_bl_verno startbuildlibs bootloader fota gen_infolog mmi_feature_check operator_check mcp_check ckmake ckscatter ckscatter2 mmi_obj_check dummy_data_check removecode genremoveinfo copylintlog genlintstatlog xgc_all_libs echo_lib_lists echo_che_sss_lib_in_list echo_che_lib_in_list xgc_all_libs_2 echo_che_ssf_sss_lib_in_list echo_che_ssf_lib_in_list ck3rdptylic gendoc cci clean_codegen slim_codegen slim_mcddll slim_update crip ss_lcs_gen check_db ckmemcons backup findpad mtegen elfpatch gendsp cfggen xml_parser codegen_check gen_modlibtbl ximgen FORCE nvram_edit_h_gen zimage_check gen_gfh_cfg gen_sfini obj_sys_auto_gen tiny_system iotgen ts_new

# *************************************************************************
# MediaTek is the default CUSTOMER.
# *************************************************************************

# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# -----------------------------
#  Include scripts
# -----------------------------
include make\option.mak            # Build option definitons
-include make\app_cfg.mak
-include make\internal_action.mak
-include make\standalone_action.mak
-include tools\NVRAMStatistic\nvram_edit_gen.mak

NEED_TRANS_CLASSB = FALSE
ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
  ifeq ($(strip $(L1_GPRS)),TRUE)
      NEED_TRANS_CLASSB = TRUE
  endif
else
  ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
      NEED_TRANS_CLASSB = TRUE
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
  NO_PCIBT = TRUE
endif

NEED_TRANS_UMTS = FALSE
ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
   NEED_TRANS_UMTS = TRUE
endif
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
   ifeq ($(strip $(L1_WCDMA)),TRUE)
      NEED_TRANS_UMTS = TRUE
   endif
endif

-include make\~cleanmod.tmp      # Define clean modules
ifndef DO_CLEAN_MODULE
   # Default clean all
  DO_CLEAN_MODULE   =  FALSE
  CLEAN_MODS        =
else

  ifneq ($(filter L1,$(call Upper,$(CLEAN_MODS))),)
    NEED_CLEAN_CGENLST = TRUE
  else
    NEED_CLEAN_CGENLST = FALSE
  endif
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(filter L1 L1_CLASSB L1_CLASSB_UMTS L1_CLASSB_G2,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) l1_ext
  endif
  ifneq ($(filter UL1,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) ul1_ext
  endif
  ifneq ($(filter UL1_HS,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) ul1_ext
  endif
  endif
   # Do component module name parsing according to different project combination
   # For example, in classb solution, l1 -> l1_classb instead l1,
   # but l1_classb should be accepted, too.

  ifeq ($(NEED_TRANS_CLASSB),TRUE)
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
    ifneq ($(strip $(L1_WCDMA)),TRUE)
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1_classb,$(comp)),$(comp),l1_classb_g2))
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr_classb,$(comp)),$(comp),rr_classb2))
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm_classb,$(comp)),$(comp),mm_classb2))
    endif
  else
    ifeq ($(NEED_TRANS_UMTS),FALSE)
      ifneq ($(strip $(L1_WCDMA)),TRUE)
        CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_g2))
        CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),$(comp)2))
        CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),$(comp)2))
      endif
    endif
  endif

  ifeq ($(NEED_TRANS_UMTS),TRUE)
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),l1_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),rr_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),mm_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1_classb,$(comp)),$(comp),l1_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr_classb,$(comp)),$(comp),rr_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm_classb,$(comp)),$(comp),mm_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l4,$(comp)),$(comp),l4_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out peer,$(comp)),$(comp),peer_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out interface,$(comp)),$(comp),interface_classb))
  endif

  ifdef SIM_NEW_ARCH
    ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out sim,$(comp)),$(comp),$(comp)2))
    endif
  endif

endif

ifneq ($(filter PLUTO_MMI COSMOS_MMI NEPTUNE_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
  RUN_RESGEN_NEW := TRUE
else
  RUN_RESGEN_NEW := FALSE
endif
ifneq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  RUN_RESGEN_NEW := FALSE
endif
ifeq ($(strip $(call Upper,$(RELEASE_PACKAGE))),REL_SUB_UAS_UMTS)
  RUN_RESGEN_NEW := FALSE
  REDUCE_HEADER_DEPTH  := FALSE
endif
ifneq ($(findstring MODEM,$(CUSTOMER)),)
  RUN_RESGEN_NEW := FALSE
endif

-include make\~updatemod.tmp     # Define update modules
ifndef DO_UPDATE_MODULE
   # Default update all
  DO_UPDATE_MODULE  =  FALSE
  UPDATE_MODS       =
  RUN_RESGEN = $(RUN_RESGEN_NEW)
else
  RUN_RESGEN = FALSE
  ifneq ($(filter MMIRESOURCE LCMMIRESOURCE,$(call Upper,$(UPDATE_MODS))),)
    RUN_RESGEN = $(RUN_RESGEN_NEW)
  endif
endif

-include make\~remakemod.tmp     # Define remake modules
ifndef DO_REMAKE_MODULE
   # Default remake all
  DO_REMAKE_MODULE  =  FALSE
  REMAKE_MODS       =
endif

-include make\~scanmod.tmp     # Define scan modules
ifndef DO_SCAN_MODULE
   # Default scan all
  DO_SCAN_MODULE  =  FALSE
  SCAN_MODS       =
endif

-include make\~gendocmod.tmp     # Define gendoc modules
ifndef DO_GENDOC_MODULE
   # Default gendoc all
  DO_GENDOC_MODULE  =  FALSE
  GENDOC_MODS       =
endif

-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
   # Default custom release
  CUSTOM_RELEASE  =  FALSE
endif

ifndef EXT_CAM_MODULE
  EXT_CAM_MODULE = NONE
endif

ifndef CMOS_SENSOR
  CMOS_SENSOR = NONE
endif

ifdef COMPILER
   ifeq ($(strip $(COMPILER)),RVCT)
      VIA = --via
      DEPEND = --depend
   endif
   ifeq ($(strip $(COMPILER)),ADS)
      VIA = -via
      DEPEND = -depend
   endif
endif

# default is ADS compiler
ifndef COMPILER
   COMPILER = ADS
   VIA = -via
endif

# default mbis tempfile
ifndef MBIS_BUILD_TIME_TMP
   MBIS_BUILD_TIME_TMP = tmp
endif
ifndef MBIS_BUILD_INFO_LOG
   MBIS_BUILD_INFO_LOG = tmp
endif

ifndef FLAVOR
   FLAVOR = NONE
endif

ifndef DUMMY_LIS
   DUMMY_LIS = FALSE
endif

ifndef OBJ_SYS_AUTO_GEN
   OBJ_SYS_AUTO_GEN = FALSE
endif

ifneq ($(strip $(FLAVOR)),NONE)
   FULL_PRJ_NAME = $(strip $(CUSTOMER))($(strip $(FLAVOR)))_$(strip $(PROJECT))
else
   FULL_PRJ_NAME = $(strip $(CUSTOMER))_$(strip $(PROJECT))
endif

ifndef MODIS_CONFIG
  MODIS_CONFIG := FALSE
endif

#########################################################
# Replace alias modules. (for update/remake/scan/clean)
#########################################################
ifdef UPDATE_MODS
UPDATE_MODS_TEMP = $(foreach mod,$(call Upper,$(UPDATE_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
UPDATE_MODS := $(strip $(UPDATE_MODS_TEMP))

ifdef REMAKE_MODS
REMAKE_MODS_TEMP = $(foreach mod,$(call Upper,$(REMAKE_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
REMAKE_MODS := $(REMAKE_MODS_TEMP)

ifdef SCAN_MODS
SCAN_MODS_TEMP = $(foreach mod,$(call Upper,$(SCAN_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
SCAN_MODS := $(SCAN_MODS_TEMP)

ifdef CLEAN_MODS
CLEAN_MODS_TEMP = $(foreach mod,$(call Upper,$(CLEAN_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CLEAN_MODS := $(CLEAN_MODS_TEMP)
####################################################################
# End of alias build settings.
####################################################################

include make\xgen\xgen.mak
COM_DEFS_TARGET := $(COM_DEFS)
COMMINCDIRS_TARGET := $(COMMINCDIRS)
RULESDIR_TARGET := $(RULESDIR)
XGEN_INC_DIR_ORI := $(XGEN_INC_DIR)
XGEN_INC_DIR_TARGET ?= $(XGEN_INC_DIR)

#################
# MoDIS setting #
#################
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  include make\modisConfig.mak
endif

# *************************************************************************
#  Remove Repeated Common Include Path
# *************************************************************************
XGEN_INC_DIR += $(COMMINCDIRS)
XGEN_INC_DIR_TARGET += $(COMMINCDIRS_TARGET)
ifneq ($(call uc,$(strip $(ACTION))),CRIP)
  COMMINCDIRS := $(call uniq,$(COMMINCDIRS))
  XGEN_INC_DIR := $(call uniq,$(XGEN_INC_DIR))
  COMMINCDIRS_TARGET := $(call uniq,$(COMMINCDIRS_TARGET))
  XGEN_INC_DIR_TARGET := $(call uniq,$(XGEN_INC_DIR_TARGET))
endif

# *************************************************************************
# Build path, directories
# *************************************************************************
# Do not support new mmi feature file architecture
OPTR_WARNING_DEF = $(strip $(FIXPATH))\$(strip $(OPTR_PATH))\operator_checklist.txt
PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(CUSTOMER))).,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO))))))
FOTA_PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(CUSTOMER))).,, $(subst MAUI.,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO)))))))
NEWTARGNAME    =  $(strip $(TARGNAME)).$(strip $(PURE_VERNO))
MMI_FEATURES_FILE = $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features.h
MMI_FEATURES_SWITCH_FILE = $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h
PLATFORM_LIB   =

COM_SCANDEFS   = $(foreach def, $(COM_DEFS),-define $(def))
COM_SCANDEFS_NEW  = $(foreach def, $(COM_DEFS),-D$(def))

# L1 database
L1_DB_COMM     =  $(strip $(FIXPATH))\l1\common

# .log
LOGDIR         =  $(strip $(TARGDIR))

# version no dir
VERNODIR       =  $(strip $(FIXPATH))\verno

# summary log
LOG            =  $(strip $(LOGDIR))\$(strip $(PLATFORM)).log
BOOTLOADER_LOG =  $(strip $(LOGDIR))\bootloader.log
BOOTLOADER_EXT_LOG =  $(strip $(LOGDIR))\bootloader_ext.log
FOTA_LOG       =  $(strip $(LOGDIR))\fota.log
LNKERRORLOG    =  $(strip $(LOGDIR))\$(strip $(PLATFORM))_error.log

# bin folder for FACTORY mode
FACTORY_BIN_FOLDER = $(strip $(FIXPATH))\build\factory_bin

# Component's log file
COMPLOGDIR     =  $(strip $(TARGDIR))\log
COMPLINTLOGDIR     =  $(strip $(TARGDIR))\lint_log
MMI_FEATURES_LOG   =  $(strip $(COMPLOGDIR))\MMI_features.log
DB_CHECK_LOG   =  $(strip $(COMPLOGDIR))\db_check.log

INFOLOG := $(strip $(COMPLOGDIR))\info.log
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  INFOMAKELOG = $(strip $(COMPLOGDIR))\infomake.log
  MCDDLL_INFOLOG = $(strip $(COMPLOGDIR))\mcddll_info.log
  MCDDLL_UPDATE_LOG = $(strip $(COMPLOGDIR))\mcddll_update.log
  INFOLOG_$(strip $(BLUETOOTH_SUPPORT)) = $(strip $(COMPLOGDIR_BT))\info_$(strip $(BLUETOOTH_SUPPORT)).log
else
  INFOLOG_MODIS = $(strip $(COMPLOGDIR))\info_$(strip $(MODIS_UESIM)).log
  INFOMAKELOG = $(strip $(COMPLOGDIR))\infomake_$(strip $(MODIS_UESIM)).log
  MCDDLL_INFOLOG = $(strip $(COMPLOGDIR))\mcddll_info_$(strip $(MODIS_UESIM)).log
  MCDDLL_UPDATE_LOG = $(strip $(MODISDIR))\_BUILD_LOG\mcddll_update$(strip $(MODIS_SUFFIX)).log
  INFOLOG_$(strip $(BLUETOOTH_SUPPORT)) = $(strip $(COMPLOGDIR_BT))\info_$(strip $(BLUETOOTH_SUPPORT))_$(strip $(MODIS_UESIM)).log
endif

# CAT
CATDB  =  $(strip $(TARGDIR))\CAT_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO)).CATDB

# -----------------------------
# Macros definition
# -----------------------------
PURELNKOPT     = $(strip $(LNKOPT))

ifeq ($(strip $(COMPILER)),RVCT)
  LNKOPT += --largeregions --scatter $(SCATTERFILE) --output $(strip $(TARGDIR))\$(TARGNAME).elf \
            --symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
            --list $(strip $(TARGDIR))\$(TARGNAME).lis \
            --libpath $(DIR_ARMLIB)
  LNKOPT += --keep EMI_INFO_2
  LNKOPT += --keep CUST_MEM_INFO

  LNKOPT += --keep g_bl_maui_paired_ver

  LNKOPT += --keep DL_CTRL_BIN \
            --keep g_boot_cert_sig

  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
    LNKOPT += --keep g_DummyKeep_Data
  endif

  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    LNKOPT += --keep g_secinfo_tail \
              --keep g_SEC_RO \
              --keep g_FlashToolCfg \
              --keep g_SecureMAC_Size \
              --keep g_SecureMAC \
              --keep g_secinfo
  endif

  ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
    LNKOPT += --keep g_SEC_RO
  endif

  ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
    BTLD_LNKOPT += --keep gfh_bl_anticlone
    BTLD_LNKOPT += --keep gfh_bl_brom_sec_cfg
  endif

  ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
    LNKOPT       += --keep g_CustParaCfg \
                    --keep g_CustParaCfg_Tail
  endif

  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    LNKOPT       += --keep g_enfb_3rdrom_header
  endif

  ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
    LNKOPT += --keep IMG_FOTA_INFO
    LNKOPT += --keep MBAInfo
  endif

  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    BTLD_LNKOPT += --keep g_BlSecInfo \
                   --keep g_BlSecureMAC \
                   --keep g_BlSecureMAC_Size
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
      BTLD_LNKOPT += --keep g_BlFunc_Table
    endif
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      LNKOPT += --keep g_DummyKeep_Data
      FOTA_LNKOPT += --keep g_fota_secinfo
    endif
    BTLD_LNKOPT += --keep gfh_bl_brom_sec_cfg
    BTLD_LNKOPT += --keep gfh_bl_sec_key
  endif

  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    LNKOPT += --keep IMG_FOTA_INFO
    FOTA_LNKOPT += --keep IMG_UA_HEAD_INFO
  endif

  BTLD_LNKOPT += --keep IMG_BL_INFO
  BTLD_LNKOPT += --keep g_ExtBootloaderInfo
  
  LNKOPT += $(NVRAM_LNK_OPT)
  ifeq ($(strip $(DCM_DEBUG_SUITE_ENABLE)),TRUE)
    LNKOPT += $(strip $(COMPLIBDIR))\system.lib(dcm_intercept_c.obj)
    LNKOPT += $(strip $(COMPLIBDIR))\system.lib(dcm_intercept_a.obj)
  endif

endif #ifeq ($(strip $(COMPILER)),RVCT)

ifeq ($(strip $(COMPILER)),ADS)
  LNKOPT += -scatter $(SCATTERFILE) -output $(strip $(TARGDIR))\$(TARGNAME).elf \
            -symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
            -list $(strip $(TARGDIR))\$(TARGNAME).lis \
            -libpath $(DIR_ARMLIB)
  LNKOPT += -keep EMI_INFO_2
  LNKOPT += -keep CUST_MEM_INFO

  LNKOPT += -keep g_bl_maui_paired_ver

ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
  LNKOPT += -keep g_DummyKeep_Data
endif

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  LNKOPT  += -keep g_secinfo_tail \
             -keep g_SEC_RO \
             -keep g_FlashToolCfg \
             -keep g_SecureMAC_Size \
             -keep g_SecureMAC \
             -keep g_secinfo

  LNKOPT += -keep DL_CTRL_BIN \
            -keep g_boot_cert_sig

endif

ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
  LNKOPT += -keep g_SEC_RO
endif
ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
  BTLD_LNKOPT += -keep gfh_bl_anticlone
endif

ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
  LNKOPT       += -keep g_CustParaCfg \
                  -keep g_CustParaCfg_Tail
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  LNKOPT       += -keep g_enfb_3rdrom_header
endif

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  BTLD_LNKOPT += -keep g_BlSecInfo \
                 -keep g_BlSecureMAC \
                 -keep g_BlSecureMAC_Size
  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
    BTLD_LNKOPT += -keep g_BlFunc_Table
  endif
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    LNKOPT += -keep g_DummyKeep_Data
    FOTA_LNKOPT += -keep g_fota_secinfo
  endif
  BTLD_LNKOPT += -keep gfh_bl_brom_sec_cfg
  BTLD_LNKOPT += -keep gfh_bl_sec_key
endif

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  LNKOPT += -keep IMG_FOTA_INFO
  BTLD_LNKOPT += -keep IMG_BL_INFO
  FOTA_LNKOPT += -keep IMG_UA_HEAD_INFO
endif

endif


# *************************************************************************
#  Target Definitions
# *************************************************************************
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)

  ifneq ($(filter system,$(COMPLIST)),)
    INITLIB        =  $(strip $(COMPLIBDIR))\system.lib
  else
    INITLIB        =  $(CUS_MTK_LIB)\system.lib
  endif

ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
  MTK_LIBS =  $(foreach COMP,$(filter-out $(PARTIAL_TRACE_LIB),$(CUS_REL_HDR_COMP)),$(CUS_MTK_LIB)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(filter-out $(PARTIAL_TRACE_LIB),$(CUS_REL_MTK_COMP)),$(CUS_MTK_LIB)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(filter $(PARTIAL_TRACE_LIB),$(CUS_REL_HDR_COMP)),$(CUS_MTK_LIB_TRACE)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(filter $(PARTIAL_TRACE_LIB),$(CUS_REL_MTK_COMP)),$(CUS_MTK_LIB_TRACE)\$(COMP).lib)
else
  MTK_LIBS =  $(foreach COMP,$(CUS_REL_HDR_COMP),$(CUS_MTK_LIB)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(CUS_REL_MTK_COMP),$(CUS_MTK_LIB)\$(COMP).lib)
endif

else

  ifneq ($(filter system,$(COMPLIST)),)
    INITLIB        =  $(strip $(COMPLIBDIR))\system.lib
  endif

  MTK_LIBS       =

endif


ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(filter l1 l1_classb l1_classb_umts l1_classb_g2,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) l1_ext
  endif
  ifneq ($(filter ul1,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) ul1_ext
  endif
  ifneq ($(filter ul1_hs,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) ul1_hs_ext
  endif
  ifeq ($(filter verno,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) verno
  endif
  endif
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(filter verno,$(UPDATE_MODS)),)
      UPDATE_MODS := $(UPDATE_MODS) oriverno
    endif
  endif
  COMPLIBLIST = $(foreach comp,$(UPDATE_MODS),$(comp).lib)
else
  ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifneq ($(filter l1 l1_classb l1_classb_umts l1_classb_g2,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) l1_ext
    endif
    ifneq ($(filter ul1,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) ul1_ext
    endif
    ifneq ($(filter ul1_hs,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) ul1_hs_ext
    endif
    ifeq ($(filter verno,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) verno
    endif
    endif
    ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
      ifneq ($(filter verno,$(REMAKE_MODS)),)
        REMAKE_MODS := $(REMAKE_MODS) oriverno
      endif
    endif
    COMPLIBLIST = $(foreach comp,$(REMAKE_MODS),$(comp).lib)
  else
    COMPLIBLIST = $(call sort,$(foreach comp,$(COMPLIST),$(comp).lib))
  endif
endif

ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
  COMPSCANLIST = $(UPDATE_MODS)
else
  ifeq ($(strip $(DO_SCAN_MODULE)),TRUE)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifneq ($(filter l1 l1_classb l1_classb_umts l1_classb_g2,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) l1_ext
    endif
    ifneq ($(filter ul1,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) ul1_ext
    endif
    ifneq ($(filter ul1_hs,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) ul1_hs_ext
    endif
    endif
    COMPSCANLIST = $(SCAN_MODS)
  else
   COMPSCANLIST = $(COMPLIST)
  endif
endif

# either drmadp.lib or custom.lib will run custominfo.pl
# but some project may not have to compile drmadp.lib, so put drmadp.lib first
ifneq ($(filter drmadp.lib,$(COMPLIBLIST)),)
  CUSTOM_EXIST   =  TRUE
else
  CUSTOM_EXIST   =  FALSE
endif

ifneq ($(filter custom.lib,$(COMPLIBLIST)),)
  CUSTOM_EXIST   =  TRUE
else
  ifneq ($(filter ecompass.lib image_sensor_sec.lib obigo03cpushadp.lib obigo03cpushlib.lib lgoem.lib wise.lib,$(COMPLIBLIST)),)
    CUSTOM_EXIST   =  TRUE
  else
    CUSTOM_EXIST   =  FALSE
  endif
endif

# Do component module name parsing according to different project combination
# For example, in classb solution, l1 -> l1_classb instead l1,
# but l1_classb should be accepted, too.
ifeq ($(NEED_TRANS_CLASSB),TRUE)
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l4.lib,$(comp)),$(comp),l4_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out peer.lib,$(comp)),$(comp),peer_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out interface.lib,$(comp)),$(comp),interface_classb.lib))
  ifneq ($(strip $(L1_WCDMA)),TRUE)
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1_classb.lib,$(comp)),$(comp),l1_classb_g2.lib))
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr_classb.lib,$(comp)),$(comp),rr_classb2.lib))
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm_classb.lib,$(comp)),$(comp),mm_classb2.lib))
  endif
else
  ifeq ($(NEED_TRANS_UMTS),FALSE)
    ifneq ($(strip $(L1_WCDMA)),TRUE)
      COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_g2.lib))
      COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr2.lib))
      COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm2.lib))
    endif
  endif
endif

ifeq ($(NEED_TRANS_UMTS),TRUE)
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1_classb.lib,$(comp)),$(comp),l1_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr_classb.lib,$(comp)),$(comp),rr_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm_classb.lib,$(comp)),$(comp),mm_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l4.lib,$(comp)),$(comp),l4_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out peer.lib,$(comp)),$(comp),peer_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out interface.lib,$(comp)),$(comp),interface_classb.lib))
endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out sim.lib,$(comp)),$(comp),sim2.lib))
  endif
endif

LINT_COMP_LIST =  $(subst .lib,.ltp,$(COMPLIBLIST))


ifneq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
ifneq ($(strip $(call Upper,$(REMAKE_MODS))),FOTA)
   CHK_COMPLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp).lib),$(call lc,$(COMPLIBLIST)))
   ifneq ($(words $(CHK_COMPLIST)),0)
      ifneq ($(strip $(LINT)),TRUE)
         ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
            ifeq ($(strip $(PARTIAL_COPY)),TRUE)
               $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in PC_SRC_COMP of pc_cfg.ini when Partial Copy)
            else
               $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in CUS_REL_SRC_COMP or NOT in CUS_REL_PAR_SRC_COMP)
            endif
         else
            $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in COMPLIST)
         endif
      else
         REMOVELINTCOMP = $(subst .lib,.ltp,$(CHK_COMPLIST))
         LINT_COMP_LIST := $(filter-out $(REMOVELINTCOMP),$(LINT_COMP_LIST))
      endif
   endif
endif
endif

LINTLOGFILE=$(subst .ltp,.log,$(LINT_COMP_LIST))

ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  MODULELIS := $(foreach comp,$(sort $(COMPLIST)),$(comp).lis)
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    MODULELIS += bootloader.lis bootloader_ext.lis
  endif
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    MODULELIS += fota.lis
  endif
else
  ifndef MODULELIS
    MODULELIS := $(foreach comp,$(call lc,$(COMPLIBLIST)),$(subst .lib,.lis,$(comp)))
  endif
endif

# Do component module name parsing according to different project combination
# For example, in classb solution, l1 -> l1_classb instead l1,
# but l1_classb should be accepted, too.
ifeq ($(NEED_TRANS_CLASSB),TRUE)
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
endif
ifeq ($(NEED_TRANS_UMTS),TRUE)
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb_umts))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb_umts))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb_umts))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1_classb,$(comp)),$(comp),$(comp)_umts))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr_classb,$(comp)),$(comp),$(comp)_umts))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm_classb,$(comp)),$(comp),$(comp)_umts))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
  COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out sim,$(comp)),$(comp),$(comp)2))
  endif
endif

CHK_SCANLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp)),$(COMPSCANLIST))
ifneq ($(words $(CHK_SCANLIST)),0)
  $(error $(CHK_SCANLIST) NOT in COMPLIST)
endif

COMP_DEP_LIST = $(foreach comp,$(sort $(COMPSCANLIST)),$(comp).dep)

ifeq ($(strip $(MODIS_CONFIG)),FALSE)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifndef RUN_HTOGETHER
    RUN_HTOGETHER = FALSE
  endif
else
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
    ifndef RUN_HTOGETHER
      RUN_HTOGETHER = TRUE
    endif
  endif
endif
else
  RUN_HTOGETHER = FALSE
endif

# *************************************************************************
# Search Paths
# *************************************************************************
vpath
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
vpath %.dep $(subst \,/,$(strip $(RULESDIR)))
vpath %.lib $(strip $(OBJSDIR))\lib
vpath %.ltp $(strip $(COMPLINTLOGDIR))
vpath %.bin $(strip $(TARGDIR))
endif

# *************************************************************************
#  Implicit Rules and Compiler Options
# *************************************************************************
BIN_FILE       =  $(strip $(NEWTARGNAME)).bin
LIS_FILE       =  $(strip $(TARGNAME)).lis
IMG_FILE       =  $(strip $(TARGNAME)).elf
ROM_IMG_FILE   =  rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
# *************************************************************************
#  Settings for BOOTLOADER
# *************************************************************************
BTLDVERNODIR   =  $(strip $(FIXPATH))\hal\system\bootloader\src
BTLD_PREFIX    =  $(strip $(CUSTOMER))_BOOTLOADER_$(strip $(BTLD_VERNO))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO))
BTLD_EXT_PREFIX = $(strip $(BTLD_PREFIX))_ext
BTLD_BIN_FILE  =  $(strip $(BTLD_PREFIX)).bin
BTLD_EXT_BIN_FILE  =  $(strip $(BTLD_EXT_PREFIX)).bin
BTLDLNKOPT     = $(strip $(LNKOPT)) $(strip $(BTLD_LNKOPT)) -scatter $(BL_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(BTLD_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(BTLD_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(BTLD_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)
BTLDEXTLNKOPT     = $(strip $(LNKOPT)) $(strip $(BTLD_LNKOPT)) -scatter $(BL_EXT_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)
-include $(BTLDVERNODIR)\verno_bootloader.bld
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  BL_LINKLIST := $(filter $(BL_COMPLIST),$(CUS_REL_MTK_COMP))
  BL_COMPLIBLIST := $(filter-out $(BL_LINKLIST),$(BL_COMPLIST))
else
  BL_COMPLIBLIST := $(BL_COMPLIST)
  BL_LINKLIST := 
endif

ifneq ($(strip $(BL_COMPLIBLIST)),)
  BL_COMPLIBLIST := $(call sort,$(foreach comp,$(BL_COMPLIBLIST),$(comp).lib))
endif
ifneq ($(strip $(BL_LINKLIST)),)
  BL_LINKLIST := $(call sort,$(foreach comp,$(BL_LINKLIST),$(comp).lib))
endif
# *************************************************************************
#  Settings for FOTA
# *************************************************************************
# FOTA bin file name (cannot contain MAUI in FOTA bin file name)
FOTA_PREFIX    =  $(strip $(CUSTOMER))_FOTA_$(strip $(PLATFORM))_$(strip $(FOTA_PURE_VERNO))
FOTA_BIN_FILE  =  $(strip $(FOTA_PREFIX)).bin
CUSTOM_FOTA_H = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_fota.h

FOTALNKOPT     = $(strip $(LNKOPT)) $(strip $(FOTA_LNKOPT)) -scatter $(FOTA_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(FOTA_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(FOTA_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(FOTA_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)


# *************************************************************************
#  Debug
# *************************************************************************
# USER_SPECIFIC.mak is included in Option.mak

ifneq ($(filter ALL,$(call Upper,$(DEBUG_MODULES))),)
  DEBUG_MODULES := $(call Upper,$(COMPLIST))
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    DEBUG_MODULES += $(call Upper,bootloader bootloader_ext)
  endif
else
  DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(DEBUG_MODULES)))
endif
ifneq ($(filter ALL,$(call Upper,$(NON_DEBUG_MODULES))),)
  NON_DEBUG_MODULES := $(call Upper,$(COMPLIST))
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    NON_DEBUG_MODULES += $(call Upper,bootloader bootloader_ext)
  endif  
else
  NON_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(NON_DEBUG_MODULES)))
endif

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(strip $(CUSTOM_NON_DEBUG_MODULES)$(CUSTOM_DEBUG_MODULES)),)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(MAKELEVEL),0)
      $(info WARNING: Ignore CUSTOM_DEBUG_MODULES CUSTOM_NON_DEBUG_MODULES before CUSTOM_RELEASE)
    endif
    endif
  endif
  DEBUG_TEMP := $(filter $(NON_DEBUG_MODULES),$(DEBUG_MODULES))
  ifneq ($(words $(DEBUG_TEMP)),0)
    DEBUG_MODULES := $(filter-out $(DEBUG_TEMP),$(DEBUG_MODULES))
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(MAKELEVEL),0)
      $(info WARNING: Ignore DEBUG_MODULES = $(DEBUG_TEMP))
    endif
    endif
  endif
else
  ifndef CUSTOM_DEBUG_MODULES
    CUSTOM_DEBUG_MODULES :=
  else
    ifneq ($(filter ALL,$(call Upper,$(CUSTOM_DEBUG_MODULES))),)
      CUSTOM_DEBUG_MODULES := $(call Upper,$(COMPLIST))
    else
      CUSTOM_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(CUSTOM_DEBUG_MODULES)))
    endif
  endif
  ifndef CUSTOM_NON_DEBUG_MODULES
    CUSTOM_NON_DEBUG_MODULES :=
  else
    ifneq ($(filter ALL,$(call Upper,$(CUSTOM_NON_DEBUG_MODULES))),)
      CUSTOM_NON_DEBUG_MODULES := $(call Upper,$(COMPLIST))
    else
      CUSTOM_NON_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(CUSTOM_NON_DEBUG_MODULES)))
    endif
  endif

  DEBUG_MODULES := $(filter-out $(CUSTOM_DEBUG_MODULES),$(DEBUG_MODULES))
  NON_DEBUG_MODULES := $(filter-out $(CUSTOM_NON_DEBUG_MODULES),$(NON_DEBUG_MODULES))

  DEBUG_TEMP := $(filter $(CUSTOM_NON_DEBUG_MODULES) $(NON_DEBUG_MODULES),$(DEBUG_MODULES))
  ifneq ($(words $(DEBUG_TEMP)),0)
    DEBUG_MODULES := $(filter-out $(DEBUG_TEMP),$(DEBUG_MODULES))
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(MAKELEVEL),0)
      $(info WARNING: Ignore DEBUG_MODULES = $(DEBUG_TEMP))
    endif
    endif
  endif
  DEBUG_TEMP := $(filter $(CUSTOM_DEBUG_MODULES),$(NON_DEBUG_MODULES))
  ifneq ($(words $(DEBUG_TEMP)),0)
    NON_DEBUG_MODULES := $(filter-out $(DEBUG_TEMP),$(NON_DEBUG_MODULES))
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(MAKELEVEL),0)
      $(info WARNING: Ignore NON_DEBUG_MODULES = $(DEBUG_TEMP))
    endif
    endif
  endif
  DEBUG_TEMP := $(filter $(CUSTOM_NON_DEBUG_MODULES),$(CUSTOM_DEBUG_MODULES))
  ifneq ($(words $(DEBUG_TEMP)),0)
    CUSTOM_DEBUG_MODULES := $(filter-out $(DEBUG_TEMP),$(CUSTOM_DEBUG_MODULES))
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(MAKELEVEL),0)
      $(info WARNING: Ignore CUSTOM_DEBUG_MODULES = $(DEBUG_TEMP))
    endif
    endif
  endif

  DEBUG_MODULES := $(sort $(CUSTOM_DEBUG_MODULES) $(DEBUG_MODULES))
  NON_DEBUG_MODULES := $(sort $(CUSTOM_NON_DEBUG_MODULES) $(NON_DEBUG_MODULES))
endif

ifeq ($(strip $(DEBUG_MODULES)),)
  DEBUG_MODULES := NONE
endif

ifeq ($(strip $(NON_DEBUG_MODULES)),)
  NON_DEBUG_MODULES := NONE
endif

ifndef RUN_FLAVOR_CONF
  RUN_FLAVOR_CONF := FALSE
endif
ifndef RUN_FLAVOR_CONF_PL
  RUN_FLAVOR_CONF_PL := FALSE
endif
ifeq ($(strip $(RUN_FLAVOR_CONF)),AUTO)
# determine the condition of running flavor_conf.pl due to feature option
# RUN_FLAVOR_CONF=AUTO is from command line, override it to make effect
  ifeq ($(MAKELEVEL),0)
  #ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  #ifeq ($(filter REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
  ifdef FLAVOR
  ifneq ($(strip $(FLAVOR)),NONE)
    ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
        RUN_FLAVOR_CONF_PL := TRUE
    else
      ifneq ($(strip $(LEVEL)),VENDOR)
      ifneq ($(strip $(wildcard make\flavor_conf.pl)),)
        RUN_FLAVOR_CONF_PL := TRUE
      endif
      endif
    endif
  endif
  endif
  #endif
  #endif
  endif
endif


#************************************************************************
# Dependency check
#************************************************************************
# default AUTO_CHECK_DEPEND value depends on the build action, if it is not passed by make command from make2.pl
ifndef AUTO_CHECK_DEPEND
  AUTO_CHECK_DEPEND := FALSE
endif
ifneq ($(filter $(MAKECMDGOALS),remake cgen),)
  AUTO_CHECK_CGEN := TRUE
else
  AUTO_CHECK_CGEN := $(AUTO_CHECK_DEPEND)
endif

# CheckNeedCopy
# input: file list to find, priority from low to high
# output: the file that really exists and is needed
CheckNeedCopy = $(lastword $(foreach file,$(1),$(wildcard $(file))))

# CheckNeedCopyDir
# function: find which file need to be copied in different folders, but have same filename
# argument 1: input folder list where to find files, priority from low to high
# argument 2: input file extention name to find
# output: file list that really need copy
CheckNeedCopyDir = $(strip $(subst /,\,$(foreach basefile,$(sort $(foreach file,$(foreach dir,$(subst \,/,$(1)),$(wildcard $(dir)/*$(strip $(2)))),$(notdir $(file)))),$(lastword $(foreach dir,$(subst \,/,$(1)),$(wildcard $(dir)/$(basefile)))))))

# NEED_CHECK_DEPEND_LIST: the common files that affect all actions
NEED_CHECK_DEPEND_LIST := $(THE_MF) make\Option.mak make\Option_HAL.mak make\MODEM.mak
ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    NEED_CHECK_DEPEND_LIST += make\JAVA_DEF.mak
  endif
endif
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  NEED_CHECK_DEPEND_LIST += make\modisConfig.mak
endif
NEED_CHECK_CODEGEN_LIST := make\Codegen.mak
NEED_CHECK_RESGEN_LIST := make\Resgen.mak
NEED_CHECK_MODIS_LIST := make\modisBuild.mak
NEED_CHECK_COMP_LIST := make\Comp.mak

# AUTO_CHECK_DEBUG = TRUE will not delete temp file for gen dep
AUTO_CHECK_DEBUG := FALSE

# CheckNeedDepend
# function: generate makefile command for dependency check
# argument 1: action name, it is used to name the dependency file
# argument 2: folder that the dependency file exists
define CheckNeedDepend
  ifneq ($$(strip $$(AUTO_CHECK_DEPEND)),TRUE)
$$(strip $$(RULESDIR))\$(2)\$(1).det: FORCE
  else
-include $$(strip $$(RULESDIR))\$(2)\.\$(1).det
  endif
$(1): $$(strip $$(RULESDIR))\$(2)\$(1).det
$$(strip $$(RULESDIR))\$(2)\$(1).det: $$(NEED_CHECK_DEPEND_LIST)
endef

define CheckNeedDependTarget
  ifneq ($$(strip $$(AUTO_CHECK_DEPEND)),TRUE)
$$(strip $$(RULESDIR_TARGET))\$(2)\$(1).det: FORCE
  else
-include $$(strip $$(RULESDIR_TARGET))\$(2)\.\$(1).det
  endif
$(1): $$(strip $$(RULESDIR_TARGET))\$(2)\$(1).det
$$(strip $$(RULESDIR_TARGET))\$(2)\$(1).det: $$(NEED_CHECK_DEPEND_LIST)
endef

#*************************************************************************
# PCIBT check
#*************************************************************************
TEMP3 := $(patsubst %\,%,$(dir $(subst /,\,$(COMPOBJS))))
TEMP3 :=  $(call uniq,$(TEMP3))
TEMP4 := $(TEMP3) $(COMMINCDIRS) $(TS_COMMINCDIRS)

ifneq ($(strip $(NO_PCIBT)),TRUE)
 ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
   ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifeq ($(filter REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
     ifeq ($(strip $(VENDOR)),NONE)
 -include make\folderlist.bld
     ifneq ($(words $(FOLDERLIST)),0)
       TEMP1 := $(filter-out $(call Upper,$(FOLDERLIST)),$(call Upper,$(TEMP4)))
       TEMP2 := $(filter-out $(call Upper,custom\\%),$(call Upper,$(TEMP1)))
       ifneq ($(strip $(TEMP2)),)
         PERMISSON_ERROR_PATH := $(foreach DIR,$(call Upper,$(TEMP2)),$(wildcard $(DIR)))
         NOT_EXISTED_PATH := $(filter-out $(call Upper,$(PERMISSON_ERROR_PATH)),$(call Upper,$(TEMP2)))
         
         $(shell perl -e "print \"\" ";> $(strip $(TARGDIR))\GlobalIncCheck.log)
         ifneq ($(strip $(PERMISSON_ERROR_PATH)),)
           $(shell perl -e "print \"Error: The following global include path violate PCIBT rules:\".'$(PERMISSON_ERROR_PATH)'.\"\n\";">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"It may let subsidiary get build errors, please follow the SOP below to solve PCIBT error.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"******************************************************************\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"Please confirm the folders are existed and have at least one file(not include sub folder) under them first.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)       
           $(shell perl -e "print \"1.If NOT, please remove them from the COMMINCDIRS/COMPOBJS/TS_COMMINCDIRS in the makefile.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"2.If YES and these folders could be opened to subsidiaries. \".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"- If you need to adjust the p4 permission , please contact the p4 admin.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"- If those folders were already opened to subsidiaries, please request BM to re-gen the make/folderlist.bld.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"- If you are working on an official release load locally, please add the new folder paths to make/folderlist.bld manually,\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"  and the PCIBT errors would not happen again in the local codebase.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"3.If these folders could NOT be opened to subsidiaries, please:\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"- Do not use them in COMMINCDIRS/COMPOBJS or move files under them to an opened folder.\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
           $(shell perl -e "print \"******************************************************************\".\"\n\" ;">> $(strip $(TARGDIR))/GlobalIncCheck.log)
         endif
         
         ifneq ($(strip $(NOT_EXISTED_PATH)),)
           $(shell perl -e "print \"Error: The following global include paths don't exist in perforce:\".'$(NOT_EXISTED_PATH)'.\"\n\"";>> $(strip $(TARGDIR))\GlobalIncCheck.log)
           $(shell perl -e "print \"Please do not use them in COMMINCDIRS/COMPOBJS\".\"\n\" ";>> $(strip $(TARGDIR))\GlobalIncCheck.log)
         endif
         
         ifneq ($(strip $(PCIBT_NO_STOP)),TRUE)
          $(error Please check $(strip $(TARGDIR))\GlobalIncCheck.log for global include path permission check in build time (PCIBT))
         endif
       else
         $(shell perl -e "print \" \"";> $(strip $(TARGDIR))\GlobalIncCheck.log)
       endif
       endif
     endif
    endif
   endif
  endif
else
  $(shell perl -e "print \" \"";> $(strip $(TARGDIR))\GlobalIncCheck.log)
endif


# *************************************************************************
# New Build
# *************************************************************************
ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    ifeq ($(filter bootloader, $(strip $(CUS_REL_SRC_COMP))),bootloader)
      ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
      
# add for daily build, add "codegen_check" after "code_gen"
new : backup cleanall genlog cleancodegen asngen umts_gen ss_lcs_gen codegen codegen_check asnregen cleanbin mcddll_update resgen nvram_auto_gen bootloader remake
      else
new : backup cleanall genlog cleancodegen asngen codegen codegen_check asnregen cleanbin mcddll_update resgen nvram_auto_gen bootloader remake
      endif    
    else
      ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
new : backup cleanall genlog cleancodegen asngen umts_gen ss_lcs_gen codegen codegen_check asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
      else
new : backup cleanall genlog cleancodegen asngen codegen codegen_check asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
      endif    
    endif
  else
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
new : backup cleanall genlog cleancodegen asngen umts_gen ss_lcs_gen codegen codegen_check asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
    else
new : backup cleanall genlog cleancodegen asngen codegen codegen_check asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
    endif  
  endif
else
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
new : backup cleanall genlog sysgen cleancodegen asngen umts_gen ss_lcs_gen codegen codegen_check asnregen resgen bootloader update
    else
new : backup cleanall genlog sysgen cleancodegen asngen codegen codegen_check asnregen resgen bootloader update  
    endif
  else
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
new : backup cleanall genlog sysgen cleancodegen asngen umts_gen ss_lcs_gen codegen codegen_check asnregen update
    else
new : backup cleanall genlog sysgen cleancodegen asngen codegen codegen_check asnregen update
    endif
  endif
endif

# *************************************************************************
#  Update Build
# *************************************************************************
#update : genlog cleanbin codegen mcddll_update resgen cksysdrv_slim remake

ifeq ($(strip $(ACTION)),slim_update)

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(CUSTOM)),MONZA29)
update : backup genlog codegen remake
  else
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen codegen cksysdrv_slim resgen remake
    else
update : backup genlog cleanbin codegen cksysdrv_slim resgen remake
    endif
  endif
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen codegen resgen mmi_obj_check cksysdrv_slim remake
  else
update : backup genlog cleanbin codegen resgen mmi_obj_check cksysdrv_slim remake
  endif
endif

else  
## update

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(CUSTOM)),MONZA29)
update : backup genlog codegen remake
  else
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen ss_lcs_gen codegen mcddll_update cksysdrv_slim resgen remake
    else
update : backup genlog cleanbin codegen mcddll_update cksysdrv_slim resgen remake
    endif
  endif
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen ss_lcs_gen codegen mcddll_update resgen mmi_obj_check cksysdrv_slim remake
  else
update : backup genlog cleanbin codegen mcddll_update resgen mmi_obj_check cksysdrv_slim remake
  endif
endif

endif

# *************************************************************************
#  Remake Build
# *************************************************************************
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
ifneq ($(strip $(LINT)),TRUE)
ifeq ($(strip $(LEVEL)),VENDOR)
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifeq ($(filter fota, $(strip $(CUS_REL_SRC_COMP))),fota)
remake : backup mcp_check genlog cleanbin genverno genoriverno libs $(FOTA_BIN_FILE) $(BIN_FILE) cmmgen cfggen catgen done
    else
remake : backup mcp_check genlog cleanbin genverno genoriverno libs $(BIN_FILE) cmmgen cfggen catgen done
    endif
  else
remake : backup mcp_check genlog cleanbin genverno genoriverno libs $(BIN_FILE) cmmgen cfggen catgen done
  endif
else
  ifeq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
remake : backup bootloader done
  else
    ifeq ($(strip $(call Upper,$(REMAKE_MODS))),FOTA)
remake : backup $(FOTA_BIN_FILE) done
    else
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
remake : backup mcp_check genlog cleanbin genverno genoriverno libs $(FOTA_BIN_FILE) $(BIN_FILE) cmmgen cfggen catgen done
        else
remake : backup mcp_check genlog cleanbin genverno genoriverno libs $(BIN_FILE) cmmgen cfggen catgen done
        endif
      else
remake : backup mcp_check genlog cleanbin genverno genoriverno libs $(BIN_FILE) cmmgen cfggen catgen done
      endif
    endif
  endif
endif
else
remake : backup libs copylintlog genlintstatlog done 
endif
else # MODIS_CONFIG == TRUE
remake : mcp_check genlog cleanbin genverno genoriverno
endif #ifeq ($(strip $(MODIS_CONFIG)),FALSE)

backup: postgen

include make\Codegen.mak
include make\Resgen.mak
include make\custpack.mak
# *************************************************************************
# Include ts_Gsm2.mak for tiny system
# *************************************************************************
ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
include tiny_system\make\ts_Gsm2.mak
endif

# *************************************************************************
#  Executable Targets
# *************************************************************************
LINK_BIN_FILE:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
	@echo Checking DSP bin files exist or not...
	@if not exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" \
		(if not exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" \
		   (echo Error: "dsp_bin\$(strip $(DUALMACDSP_BIN)).bin" does NOT exist. Please make sure "$(strip $(DUALMACDSP_BIN)).bin" exists under dsp_bin folder. > $(LOG) & \
		   echo Error: "dsp_bin\$(strip $(DUALMACDSP_BL_BIN)).bin" does NOT exist. Please make sure "$(strip $(DUALMACDSP_BL_BIN)).bin" exists under dsp_bin folder. >> $(LOG) & \
		   echo Error: DSP bin files do NOT exist. Please check $(LOG) & exit 1)\
		else \
				(echo Error: "dsp_bin\$(strip $(DUALMACDSP_BIN)).bin" does NOT exist. Please make sure "$(strip $(DUALMACDSP_BIN)).bin" exists under dsp_bin folder. > $(LOG) & \
				echo Error: DSP bin file does NOT exist. Please check $(LOG) & exit 1)) \
	else \
		(@if not exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" \
			(echo Error: "dsp_bin\$(strip $(DUALMACDSP_BL_BIN)).bin" does NOT exist. Please make sure "$(strip $(DUALMACDSP_BL_BIN)).bin" exists under dsp_bin folder.> $(LOG) & \
			echo Error: DSP bin file does NOT exist. Please check $(LOG) & exit 1))
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
		@if exist mtk_tools\checkDSP.pl \
			perl mtk_tools\checkDSP.pl "$(FIXPATH)\dsp_bin\$(strip $(DUALMACDSP_BL_BIN)).bin" "$(FIXPATH)\dsp_bin\$(strip $(DUALMACDSP_BIN)).bin" $(strip $(SUPPORT_FOR_SMARTPHONE_GPRS)) $(strip $(PLATFORM)) $(strip $(VERNO))>$(strip $(COMPLOGDIR))\checkdsp.log 2>&1 & \
			(if ERRORLEVEL 1 (echo Error: check dsp bin failed. Please check $(strip $(COMPLOGDIR))\checkdsp.log & exit 1))
  endif
endif

	@tools\strcmpex.exe def def e make\~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~customIncDef.tmp
	@tools\strcmpex.exe inc inc e make\~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~customInc.tmp >> make\~customIncDef.tmp

	@if exist $(strip $(TARGDIR))\module\custom \
		(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.def) do \
			(echo -D%%i >> make\~customIncDef.tmp)) & \
		(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.inc) do \
			(echo -I%%i >> make\~customIncDef.tmp))

	@if exist tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c \
		$(CC) $(VIA) make\~customIncDef.tmp -E tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c > ~flash_cfg_tmp.c

	@echo Linking $(strip $(NEWTARGNAME)) ...
	@perl tools\time.pl -n
  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(filter init,$(COMPLIST)),)
			@echo $(LNKOPT) $(INITLIB)(bootarm.obj) $(strip $(COMPLIBDIR))\init.lib(l6478e.obj)> make\~libs.tmp
    else
			@echo $(LNKOPT) $(INITLIB)(bootarm.obj) $(CUS_MTK_LIB)\init.lib(l6478e.obj)> make\~libs.tmp
    endif
  else
		@echo $(LNKOPT) $(INITLIB)(bootarm.obj) $(strip $(COMPLIBDIR))\init.lib(l6478e.obj)> make\~libs.tmp
  endif
	@echo $(NVRAM_OBJ_LIST) >> make\~libs.tmp

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
	@echo $(strip $(COMPLIBDIR))\custom.lib(maui_MBA_info.obj) >> make\~libs.tmp  
endif

	@for /d %%i in ($(COMPLIST)) do \
		@if /I "%%i" NEQ "rompatch" \
			(echo $(COMPLIBDIR)\%%i.lib >> make\~libs.tmp)

ifeq ($(call Upper,$(strip $(MAUI_IN_ROM))),TRUE)
  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@echo $(CUS_MTK_LIB)\rompatch.lib(*) >> make\~libs.tmp
  else
	@echo $(COMPLIBDIR)\rompatch.lib(*) >> make\~libs.tmp
  endif
	@echo $(ROM_IMG_FILE) >> make\~libs.tmp
endif

ifneq ($(strip $(MTK_LIBS)),)
	@tools\strcmpex.exe abc abc e make\~libs_2.tmp $(MTK_LIBS)
	@perl tools\lnitem.pl make\~libs_2.tmp
	@type make\~libs_2.tmp >> make\~libs.tmp
	@if exist make\~libs_2.tmp del make\~libs_2.tmp
endif

ifneq ($(strip $(COMPOBJS)),)
	@perl tools\echoLongString4.pl make\~libs.tmp $(COMPOBJS)
endif

ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    ifeq ($(strip $(RUN_RESGEN_NEW)),TRUE)
	@type plutommi\Customer\ResGenerator\vf_obj.txt >> make\~libs.tmp
    endif
  endif
endif

ifneq ($(filter __VI_ENABLED__,$(strip $(COM_DEFS))),)
	@perl tools\vivaPrelink.pl $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) $(strip $(COMPLIBDIR)) $(strip $(OBJSDIR)) $(strip $(THE_MF)) make\~viva_libs.tmp >$(strip $(TARGDIR))\log\vivaPrelink.log & \
		(if ERRORLEVEL 1 (echo Error in vivaPrelink.pl. Please check $(strip $(TARGDIR))\log\vivaPrelink.log & exit 1))
	@if exist make\~viva_libs.tmp (type make\~viva_libs.tmp >> make\~libs.tmp)
endif

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if exist make\~sortedLibs.tmp (copy /y make\~sortedLibs.tmp $(strip $(COMPLOGDIR))\link_option.log >nul)
	@if exist $(LOG) del /q $(LOG)
	@if exist $(strip $(COMPLOGDIR))\ckImgSize.log del /q $(strip $(COMPLOGDIR))\ckImgSize.log
	@if exist $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log del /q $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log

ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe TARGET $(strip $(LINK)) $(strip $(LOG)) $(strip $(LNKERRORLOG)) $(strip $(VIA)) $(strip $(HEADER_TEMP)) $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(strip $(IMG_FILE)) $(strip $(BIN_FORMAT)) $(strip $(BIN_FILE)) $(strip $(TST_DB)) $(TARGNAME).lis $(strip $(BTLD_BIN_FILE)) $(strip $(RVCT_PARTIAL_LINK)) $(strip $(LIB)) $(strip $(COMPLIBDIR)) $(strip $(CUS_MTK_LIB))
else
  ifdef RVCT_PARTIAL_LINK
    ifeq ($(strip $(RVCT_PARTIAL_LINK)),FALSE)
			$(LINK) --show_cmdline -vsn>$(LOG) 2>&1
			($(LINK) $(VIA) make\~sortedLibs.tmp >> $(LOG) 2>&1) & \
			(if ERRORLEVEL 1 \
				(if exist $(strip $(HEADER_TEMP)) (rd /S /Q $(strip $(HEADER_TEMP)))))
    else
			if exist pl_exclusion.txt del /q pl_exclusion.txt
      ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
				@for %%i in ($(CUS_REL_PAR_SRC_COMP)) do echo %%i.lib * >>pl_exclusion.txt
      endif
			perl tools\partialLink.pl --armlink=$(LINK) --armar=$(LIB) --lib-dir=$(COMPLIBDIR)	--lib-dir=$(CUS_MTK_LIB) --no-update --scatter-file=$(SCATTERFILE) --link-option-file=$(FIXPATH)\make\~sortedLibs.tmp --readelf=$(FIXPATH)\tools\MinGW\bin\arm-none-eabi-readelf.exe --nm=$(FIXPATH)\tools\MinGW\bin\arm-none-eabi-nm.exe --link-err-file=$(LOG) --strip=$(FIXPATH)\tools\MinGW\bin\arm-none-eabi-strip.exe & \
			(if ERRORLEVEL 1 \
				(echo link error) & \
				(if exist $(strip $(TARGDIR))\$(IMG_FILE) (del /q $(strip $(TARGDIR))\$(IMG_FILE))))
    endif
  else
    $(error RVCT_PARTIAL_LINK not defined!)
  endif
endif
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

LINK_BIN_FILE_CHECK POSTBUILD_CHECK:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@perl tools\auto_adjust_mem.pl 1 -maui $(strip $(THE_MF)) $(LOG) $(strip $(COMPLOGDIR))\ckImgSize.log $(strip $(COMPLOGDIR))\ckSysDrv.log $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) ~flash_cfg_tmp.c ~fs_quota_usage.log ~nvram_lid_size.log $(strip $(FEATURE_OVERLOAD)) $(strip $(SYSTEM_DRIVE_ON_NAND)) $(strip $(NVRAM_PSEUDO_MERGE)) $(strip $(CUSTOMER))>> $(strip $(COMPLOGDIR))\auto_adjust_mem.log & \
		(if ERRORLEVEL 1 \
		(tools\make.exe -fmake\gsm2.mak -r -R update_memconfig) & \
		(if ERRORLEVEL 1 (exit 1)))

  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

LINK_BL_CHECK:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@perl tools\auto_adjust_mem.pl 1 -bl $(strip $(THE_MF)) $(BOOTLOADER_LOG) $(BOOTLOADER_EXT_LOG) > $(strip $(COMPLOGDIR))\auto_adjust_mem.log & \
		(if ERRORLEVEL 1 \
		(tools\make.exe -fmake\gsm2.mak -r -R update_memconfig) & \
		(if ERRORLEVEL 1 (exit 1)))

  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

FROMELF_BIN_FILE:

 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if not exist $(strip $(TARGDIR))\$(IMG_FILE) (echo $(strip $(TARGDIR))\$(IMG_FILE) is not existed! Please check link error. & exit 1)

   # -----------------------------
   # The size of the binary image depends on the available memory on the target
   # platform.
   # -----------------------------
	@echo Creating binary file $(BIN_FILE)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  ifneq ($(strip $(VENDOR)),NONE) 
	$(strip $(DIR_INT_569))\win_32-pentium\fromelf.exe $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
  else
	$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
  endif 
else
	$(strip $(DIR_INT_569))\win_32-pentium\fromelf.exe $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
endif
else
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
  else
    ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
		$(strip $(DIR_INT_569))\win_32-pentium\fromelf.exe $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
    else
		$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
    endif
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(findstring JRD,$(call Upper,$(strip $(CUSTOMER)))),)
	$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) -m32 -output $(strip $(TARGDIR))\$(patsubst %.bin,%.m32,$(strip $(BIN_FILE)))
endif
endif

ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\*_GFH \
		(perl tools\get_gfh_files.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE)) GFH make\~gfh_files.tmp)
endif

ifneq ($(filter __VI_ENABLED__,$(strip $(COM_DEFS))),)
	@perl tools\vivaProcess.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(THE_MF)) >$(strip $(TARGDIR))\log\vivaProcess.log 2>&1 & \
		(if ERRORLEVEL 1 (echo Error in vivaProcess.pl. Please check $(strip $(TARGDIR))\log\vivaProcess.log & exit 1))
	@if not exist $(strip $(RULESDIR_TARGET))\postgen_dep (md $(strip $(RULESDIR_TARGET))\postgen_dep)
	@perl tools\pack_dep_gen.pl $(strip $(RULESDIR_TARGET))\postgen_dep\vivaProcess.det $(strip $(RULESDIR_TARGET))\postgen_dep\vivaProcess.det $(strip $(COMPLOGDIR)) vivaProcess.log
endif

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)   
	@perl tools\MBACompProcess.pl $(strip $(TARGDIR))\$(strip $(LIS_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) >$(strip $(TARGDIR))\log\MBACompProcess.log 2>&1 & \
		(if ERRORLEVEL 1 (echo Error in MBACompProcess.pl. Please check $(strip $(TARGDIR))\log\MBACompProcess.log & exit 1))	 
endif

	@if exist tools\parse_lis.pl \
		(perl tools\parse_lis.pl $(strip $(TARGDIR))\$(TARGNAME).lis ~lis_temp)

  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

zimage_check:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl tools\ckImgSize.pl $(strip $(THE_MF)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(TARGDIR))\$(TARGNAME).lis ~flash_cfg_tmp.c $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\custom_FeatureConfig.h >$(strip $(TARGDIR))\log\ckImgSize.log 2>&1 & \
		(if ERRORLEVEL 1 (echo Error in tools\ckImgSize.pl. Please check $(strip $(TARGDIR))\log\ckImgSize.log & exit 1))
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
$(BIN_FILE): tiny_system
endif
$(BIN_FILE): LINK POSTBUILD_CHECK
LINK: LINK_BIN_FILE LINK_BIN_FILE_CHECK FROMELF_BIN_FILE
POSTBUILD_CHECK: POSTBUILD

POSTBUILD:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'LINKING START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
	@perl tools\chkCSCI.pl $(strip $(TARGDIR))\$(LIS_FILE) $(strip $(TARGDIR))\$(TS_PREFIX).lis > $(strip $(COMPLOGDIR))\chkCSCI.log 2>&1 & \
		(if ERRORLEVEL 1 (echo Error in tools\chkCSCI.pl. Please check $(strip $(COMPLOGDIR))\chkCSCI.log & exit 1))
endif

	@perl tools\ckImgSize.pl $(strip $(THE_MF)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(TARGDIR))\$(TARGNAME).lis ~flash_cfg_tmp.c $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\custom_FeatureConfig.h>$(strip $(TARGDIR))\log\ckImgSize.log 2>&1 & \
		(if ERRORLEVEL 1 \
			(tools\make.exe -fmake\gsm2.mak -r -R cleanbin LINK_BIN_FILE_CHECK FROMELF_BIN_FILE zimage_check) & \
			(if ERRORLEVEL 1 \
				(tools\make.exe -fmake\gsm2.mak -r -R cleanbin) & \
				(if exist $(strip $(TARGDIR))\log\ckImgSize.log (type $(strip $(TARGDIR))\log\ckImgSize.log > $(strip $(TARGDIR))\log\ckImgSize_postbuild.log)) & \
				 (exit 1)))
	@if not exist $(strip $(RULESDIR_TARGET))\postgen_dep (md $(strip $(RULESDIR_TARGET))\postgen_dep)
	@perl tools\pack_dep_gen.pl $(strip $(RULESDIR_TARGET))\postgen_dep\ckImgSize.det $(strip $(RULESDIR_TARGET))\postgen_dep\ckImgSize.det $(strip $(COMPLOGDIR)) ckImgSize.log

# Process DSP BIN
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_ROM >NUL)& \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_BL >NUL) \
		else \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" $(strip $(TARGDIR))\DSP_ROM >NUL) & \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" $(strip $(TARGDIR))\DSP_BL >NUL)
else
  ifeq ($(strip $(NEED_DSP_FD_BIN)),TRUE)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(FIXPATH)\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_ROM) \
  else \
			(copy /y $(FIXPATH)\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin $(strip $(TARGDIR))\DSP_ROM)
  endif
endif

ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin.sig" $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_ROM.sig >NUL)& \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin.sig" $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_BL.sig >NUL) \
		else \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin.sig" $(strip $(TARGDIR))\DSP_ROM.sig >NUL) & \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin.sig" $(strip $(TARGDIR))\DSP_BL.sig >NUL)
else
  ifeq ($(strip $(NEED_DSP_FD_BIN)),TRUE)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(FIXPATH)\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin.sig $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_ROM.sig) \
  else \
			(copy /y $(FIXPATH)\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin.sig $(strip $(TARGDIR))\DSP_ROM.sig)
  endif
endif
endif

ifeq ($(strip $(SPLIT_BINARY_SUPPORT)),FACTORY_COMBINE)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(strip $(FACTORY_BIN_FOLDER))\*.* $(strip $(TARGDIR))\$(strip $(BIN_FILE))\*.* >NUL) \
		else \
			(copy /y $(strip $(FACTORY_BIN_FOLDER))\*.* $(strip $(TARGDIR))\*.* >NUL)
endif

ifneq ($(filter $(strip $(PLATFORM)),$(8_BIT_ENCRYPTION_PLATFORM)),)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM ) & \
		(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -keyini $(strip $(KEYFILE_PATH)) ) & \
		(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_KEY"   .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -keyini $(strip $(KEYFILE_PATH)) ) & \
		(if ERRORLEVEL 1 \
			(echo Error: Failed in update_img.exe) & (exit 1))
else
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM) & \
		(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -keyini $(strip $(KEYFILE_PATH)) ) & \
		(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_KEY"   .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -keyini $(strip $(KEYFILE_PATH)) ) & \
		(if ERRORLEVEL 1 \
			(echo Error: Failed in update_img.exe) & (exit 1))
endif

	@if exist .\tools\NFBPack3rdROM.pl \
	(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM  \
		(perl .\tools\NFBPack3rdROM.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ $(strip $(THE_MF))))

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG) $(strip $(SCATTERFILE)) $(strip $(PROJECT)) "$(strip $(BUILD_DATE_TIME))" $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) >> $(LOG) \
		else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(EMI_INFO) $(strip $(SCATTERFILE)) $(strip $(PROJECT)) "$(strip $(BUILD_DATE_TIME))" $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) >> $(LOG) \
		)

ifneq ($(filter $(strip $(PLATFORM)),$(8_BIT_ENCRYPTION_PLATFORM)),)
	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) ) & \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -keyini $(strip $(KEYFILE_PATH)) ) & \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_KEY"   .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -keyini $(strip $(KEYFILE_PATH)) ) & \
	(if ERRORLEVEL 1 \
		(echo Error: Failed in update_img.exe) & \
		(exit 1)) & \
		(if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG) $(strip $(SCATTERFILE)) $(strip $(PROJECT)) "$(strip $(BUILD_DATE_TIME))" $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) >> $(LOG) \
		else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(EMI_INFO) $(strip $(SCATTERFILE)) $(strip $(PROJECT)) "$(strip $(BUILD_DATE_TIME))" $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) >> $(LOG) \
		)
else
	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
	(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)) & \
	(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -keyini $(strip $(KEYFILE_PATH))) & \
	(if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_KEY"   .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -keyini $(strip $(KEYFILE_PATH)) ) & \
	(if ERRORLEVEL 1 \
		(echo Error: Failed in update_img.exe) & \
		(exit 1)) & \
		(if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG) $(strip $(SCATTERFILE)) $(strip $(PROJECT)) "$(strip $(BUILD_DATE_TIME))" $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) >> $(LOG) \
		else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(EMI_INFO) $(strip $(SCATTERFILE)) $(strip $(PROJECT)) "$(strip $(BUILD_DATE_TIME))" $(FIXPATH)\custom\system\$(strip $(BOARD_VER))) >> $(LOG) \
		)
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
  ifeq ($(strip $(PLATFORM)),MT6260)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM \
			(copy /y $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM_2)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM_2 \
			(echo $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM_2 >> make\~gfh_files.tmp) && \
			(perl tools\ThirdROM_process.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM > $(strip $(COMPLOGDIR))\ThirdROM_process.log 2>&1) & \
			(if ERRORLEVEL 1 (echo Error: Failed in ThirdROM_process.pl. Please check $(strip $(COMPLOGDIR))\ThirdROM_process.log & exit 1))
 endif  
endif

	@if not exist make\~gfh_cfg.tmp (tools\make.exe -fmake\gsm2.mak -r -R gen_gfh_cfg)
# make\~gfh_cfg_flash.tmp will be generated by append2.pl 
	@if exist make\~gfh_cfg_flash.tmp (type make\~gfh_cfg_flash.tmp >> make\~gfh_cfg.tmp)

ifneq ($(strip $(PLATFORM)),MT6573)
ifneq ($(strip $(PLATFORM)),MT6575)
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(echo $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > make\~gfh_files.tmp) & \
		(perl tools\gfh_process.pl make\~gfh_files.tmp make\~gfh_cfg.tmp $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\gfh_process.log 2>&1) & \
		(if ERRORLEVEL 1 (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))\gfh_process.log & exit 1)) \
	else \
			(@if exist make\~gfh_files.tmp \
				(perl tools\gfh_process.pl make\~gfh_files.tmp make\~gfh_cfg.tmp $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\gfh_process.log 2>&1) & \
				(if ERRORLEVEL 1 (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))\gfh_process.log & exit 1)))
endif
endif
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(perl .\tools\CheckBinaryBlockUsage.pl ~flash_cfg_tmp.c $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(NEED_BUILD_BOOTLOADER)) $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(THE_MF)) $(strip $(FOTA_ENABLE)) $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE))  > $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log 2>&1) & \
		(if ERRORLEVEL 1 (echo Error: CheckBinaryBlockUsage Failed!! Please check $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log for more details.) && (exit 1))
endif
endif

# Check if memory expiration.
	@if exist $(FIXPATH)\tools\ckScatter.pl \
		(if exist ~lis_temp \
			(perl $(FIXPATH)\tools\ckScatter.pl 2 TRUE $(SCATTERFILE) ~lis_temp ~flash_cfg_tmp.c $(strip $(THE_MF)) $(strip $(BB_FOLDER_PATH)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\ckscatter2.log) & \
				(if ERRORLEVEL 1 (@echo Error: ckScatter Error. Please refer to log\ckScatter2.log for more details.) & (exit 1)))

# To support GPS_SUPPORT
ifdef GPS_SUPPORT
ifneq ($(filter $(strip $(GPS_SUPPORT)),MT3316 MT3318),)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		((@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS (md $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS)) & \
		@if exist gps\core\mt3318_gps_core.bin (copy /Y gps\core\mt3318_gps_core.bin $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS)) \
	else \
		((@if not exist $(strip $(TARGDIR))\GPS (md $(strip $(TARGDIR))\GPS)) & \
		@if exist gps\core\mt3318_gps_core.bin (copy /Y gps\core\mt3318_gps_core.bin $(strip $(TARGDIR))\GPS))
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(@if exist tools\gps_config2.pl \
			(perl tools\gps_config2.pl $(strip $(FIXPATH))\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS\gps.ini)) \
	else \
		(@if exist tools\gps_config2.pl \
			(perl tools\gps_config2.pl $(strip $(FIXPATH))\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c $(strip $(TARGDIR))\GPS\gps.ini))
else
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(@if exist tools\gps_config.pl \
			(perl tools\gps_config.pl $(strip $(FIXPATH))\custom\drv\gps\$(strip $(BOARD_VER))\gpsmtk_config.c $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS\gps.ini)) \
	else \
		(@if exist tools\gps_config.pl \
			(perl tools\gps_config.pl $(strip $(FIXPATH))\custom\drv\gps\$(strip $(BOARD_VER))\gpsmtk_config.c $(strip $(TARGDIR))\GPS\gps.ini))
endif
endif
endif

   # -----------------------------
   # Nothing related binary directly
   # -----------------------------
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\__* (del /q $(strip $(TARGDIR))\$(strip $(BIN_FILE))\__*)
	@if exist $(strip $(TARGDIR))\__* (del /q $(strip $(TARGDIR))\__*)

ifneq ($(strip $(PARTIAL_SOURCE)),TRUE)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		((@copy /y $(SCATTERFILE_FLASHTOOL) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul) & \
			(if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) \
				(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
				(copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul)) & \
			(if exist $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) \
				(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(FOTA_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(FOTA_BIN_FILE))) & \
				(copy /Y $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul)) \
		) \
	else \
		(copy /y $(SCATTERFILE_FLASHTOOL) $(strip $(TARGDIR)) > nul)
else
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) \
			(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
				(copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)).* $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul)) & \
			(if exist $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) \
				(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(FOTA_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(FOTA_BIN_FILE))) & \
				(copy /Y $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)).* $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul))
endif


	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist $(strip $(TARGDIR))\EXT_BOOTLOADER \
			copy /Y $(strip $(TARGDIR))\EXT_BOOTLOADER $(strip $(TARGDIR))\$(strip $(BIN_FILE))\EXT_BOOTLOADER >NUL)
			
ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM1 \
			copy /y $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM1 $(strip $(TARGDIR))\$(strip $(BIN_FILE))\TS_ROM1 >NUL) & \
		(if exist $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM2 \
			copy /y $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM2 $(strip $(TARGDIR))\$(strip $(BIN_FILE))\TS_ROM2 >NUL) \
	else \
		(if exist $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM1 \
			copy /y $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM1 $(strip $(TARGDIR))\TS_ROM1 >NUL) & \
		(if exist $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM2 \
			copy /y $(strip $(TARGDIR))\$(strip $(TS_BIN_FILE))\TS_ROM2 $(strip $(TARGDIR))\TS_ROM2 >NUL)
endif

ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe TARGETs $(strip $(LINK)) $(strip $(LOG)) $(strip $(LNKERRORLOG)) $(strip $(VIA)) $(strip $(HEADER_TEMP)) $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(strip $(IMG_FILE)) $(strip $(BIN_FORMAT)) $(strip $(BIN_FILE)) $(strip $(TST_DB)) $(TARGNAME).lis  $(strip $(BTLD_BIN_FILE))
endif

#ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist gps\core\custom_core\MT3333.bin \
			copy /y gps\core\custom_core\MT3333.bin $(strip $(TARGDIR))\$(strip $(BIN_FILE))\MT3333.bin >NUL) \
	else \
		(if exist gps\core\custom_core\MT3333.bin \
			copy /y gps\core\custom_core\MT3333.bin $(strip $(TARGDIR))\MT3333.bin >NUL)
#endif

	@if exist $(strip $(MMI_FEATURES_FILE)) (copy /y $(strip $(MMI_FEATURES_FILE)) $(strip $(TARGDIR)) > nul)
	@if exist $(strip $(MMI_FEATURES_SWITCH_FILE)) (copy /y $(strip $(MMI_FEATURES_SWITCH_FILE)) $(strip $(TARGDIR)) > nul)
	@if exist $(strip $(ORIGINAL_THE_MF)) (copy /y $(strip $(ORIGINAL_THE_MF)) $(strip $(TARGDIR)) > nul)

# To support DBG Info Gen.
	@if exist make\~DbgInfoGen.cfg del /Q make\~DbgInfoGen.cfg
	@perl tools\echoLongString4.pl make\~DbgInfoGen.cfg ELF=$(strip $(TARGDIR))\$(TARGNAME).elf HW=$(strip $(PLATFORM))_$(strip $(CHIP_VER)) SW=$(strip $(VERNO))
	@perl tools\lnitem.pl make\~DbgInfoGen.cfg
	@echo PRJ=$(strip $(BRANCH)) >> make\~DbgInfoGen.cfg
	@echo TIME=$(strip $(BUILD_DATE_TIME)) >> make\~DbgInfoGen.cfg
  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
		@echo DB="$(strip $(NET_PATH))"\$(strip $(TST_DB))\DbgInfo_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))  >> make\~DbgInfoGen.cfg
		@echo SIGN=TRUE  >> make\~DbgInfoGen.cfg
  else
		@echo DB=$(strip $(TST_DB))\DbgInfo_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))  >> make\~DbgInfoGen.cfg
  endif
	@perl tools\echoLongString4.pl make\~DbgInfoGen.cfg LNKOPT="$(strip $(LNKOPT))"
	@if exist $(strip $(TARGDIR))\DbgInfo_* del /Q /F $(strip $(TARGDIR))\DbgInfo_*
	@echo Generating DbgInfo Database...
	@tools\DbgInfoGen.exe -CFG-"make\~DbgInfoGen.cfg" 2>$(strip $(COMPLOGDIR))\DbgInfoGen.log & \
	(if ERRORLEVEL 1 (echo DbgInfoGen Error. Please check $(strip $(COMPLOGDIR))\DbgInfoGen.log & exit 1))

	@if exist $(strip $(TST_DB))\DbgInfo_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME)).* \
		copy /Y $(strip $(TST_DB))\DbgInfo_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME)).* $(strip $(TARGDIR)) >NUL

	@if exist $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\$(strip $(BOARD_VER)).cfg \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\$(strip $(BOARD_VER)).cfg $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BOARD_VER)).cfg >NUL) \
		else \
			(copy /y $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\$(strip $(BOARD_VER)).cfg $(strip $(TARGDIR))\$(strip $(BOARD_VER)).cfg >NUL))

ifeq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
	@echo Copy BTConfig Tools files...
	@(perl $(FIXPATH)\tools\cp_btconfig.pl $(strip $(TARGDIR)) $(strip $(BOARD_VER))>$(strip $(COMPLOGDIR))\cp_btconfig.log 2>&1) & \
		(if ERRORLEVEL 1 echo Error: cp_btconfig.pl Failed. Please check $(strip $(COMPLOGDIR))\cp_btconfig.log & exit 1)
endif

ifneq ($(strip $(PARTIAL_SOURCE)),TRUE)
	@tools\make.exe -fmake\gsm2.mak -r -R gen_sfini
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
		@if exist $(CODEGEN_DATABASE_OUT) ($(CGEN) -sf $(CODEGEN_DATABASE_OUT) $(strip $(TSTDIR))\database\sf.ini)
  else
		@if exist $(CODEGEN_DATABASE_OUT) ($(CGEN) -sfcm $(CODEGEN_DATABASE_OUT) $(strip $(TSTDIR))\database\sf.ini)
  endif
endif

	@perl -e "print 'LINKING END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ckbinblockusage_check:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(perl .\tools\CheckBinaryBlockUsage.pl ~flash_cfg_tmp.c $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(NEED_BUILD_BOOTLOADER)) $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(THE_MF)) $(strip $(FOTA_ENABLE)) $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE))  > $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log 2>&1) & \
		(if ERRORLEVEL 1 (echo Error: CheckBinaryBlockUsage Failed!! Please check $(strip $(COMPLOGDIR))\CheckBinaryBlockUsage.log for more details.) && (exit 1))
endif
endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
#  FOTA Targets
# *************************************************************************
fota: $(FOTA_BIN_FILE) done

echo_che_ssf_sss_lib_in_list:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(COMPILER)),RVCT)
  ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss_rvct_sv5.lib lqt.lib > make\complib.txt
  else
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss_rvct_sv3.lib lqt.lib > make\complib.txt
  endif
else
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss.lib lqt.lib > make\complib.txt
  else
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss.lib > make\complib.txt
  endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	

echo_che_ssf_lib_in_list:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(LQT_SUPPORT)),TRUE)
	@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib lqt.lib > make\complib.txt
else
	@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib > make\complib.txt
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

del_fota:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(FOTA_ENABLE)),NONE)
	@-if not exist $(TARGDIR) (md $(TARGDIR))            	\
	else                                                 	\
		(@if exist $(strip $(TARGDIR))\$(FOTA_BIN_FILE) (del $(strip $(TARGDIR))\$(FOTA_BIN_FILE))) &  	\
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).elf (del $(strip $(TARGDIR))\$(FOTA_PREFIX).elf)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).lis (del $(strip $(TARGDIR))\$(FOTA_PREFIX).lis)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).sym (del $(strip $(TARGDIR))\$(FOTA_PREFIX).sym)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).htm (del $(strip $(TARGDIR))\$(FOTA_PREFIX).htm)) & \
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)

ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
$(FOTA_BIN_FILE): gencompbld echo_che_ssf_sss_lib_in_list xgc_all_libs del_fota
  else
    ifeq ($(strip $(COMPILER)),RVCT)
      ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss_rvct_sv5.lib lqt.lib del_fota
      else
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss_rvct_sv3.lib lqt.lib del_fota
      endif
    else
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss.lib lqt.lib del_fota
      else
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss.lib del_fota
      endif
    endif
  endif
else
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
$(FOTA_BIN_FILE): gencompbld echo_che_ssf_lib_in_list xgc_all_libs del_fota
  else
    ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib lqt.lib del_fota
    else
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib del_fota
    endif
  endif
endif

else
$(FOTA_BIN_FILE): gencompbld del_fota
endif

else

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib lqt.lib del_fota
    else
$(FOTA_BIN_FILE): gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib del_fota
    endif
  else
$(FOTA_BIN_FILE): gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib del_fota
  endif
else
$(FOTA_BIN_FILE): gencompbld del_fota
endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(FOTA_ENABLE)),NONE)

	@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR)) \
	else (@if exist $(strip $(COMPLOGDIR))\fota.log (del /q $(strip $(COMPLOGDIR))\fota.log))

	@if not exist $(PROJDIR) (md $(PROJDIR))
	@if not exist $(OBJSDIR) (md $(OBJSDIR))

	@echo Generate FOTA CMM file ...
	@if not exist make\~customIncDef.tmp tools\make.exe -fmake\gsm2.mak -r -R make\~customIncDef.tmp
	@if exist tools\CMMAutoGen.pl  \
	(perl tools\CMMAutoGen.pl 4 $(FIXPATH)\FOTA_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(strip $(THE_MF)) $(strip $(BIN_FILE)) ~lis_temp "$(CC)" "$(VIA)" make\~customIncDef.tmp $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\cmmgen_fotanocode.log) & \
	(if ERRORLEVEL 1 echo Error: generate FOTA CMM file Failed. Please check $(strip $(COMPLOGDIR))\cmmgen_fotanocode.log & exit 1)

	@if not exist $(strip $(OBJSDIR))\fota	(md $(strip $(OBJSDIR))\fota) \
	else	(if exist $(strip $(OBJSDIR))\fota\*.obj (del /q $(strip $(OBJSDIR))\fota\*.obj))

	@if not exist $(strip $(COMPLIBDIR))	(md $(COMPLIBDIR)) \
	else	(if exist $(strip $(COMPLIBDIR))\fota.lib (del $(strip $(COMPLIBDIR))\fota.lib))

	@if not exist $(RULESDIR) (md $(RULESDIR)) \
	else	(if exist $(strip $(RULESDIR))\fota.dep (del $(strip $(RULESDIR))\fota.dep))

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if exist $(TARGDIR)\module\fota\~fota.lis \
		(copy /y $(TARGDIR)\module\fota\~fota.lis $(TARGDIR)\module\fota\fota.lis >NUL)
	@if exist $(TARGDIR)\module\fota\fota.lis \
		(copy /y $(TARGDIR)\module\fota\fota.lis $(TARGDIR)\module\fota\~fota.lis >NUL)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\uem_gpio.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\custom_equipment.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\custom_hw_default.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\gpio_drv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pwmdrv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\alerterdrv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_fota.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_img_config.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\common\hal\custom_flash.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_blconfig.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmic_custom.c>> $(TARGDIR)\module\fota\fota.lis
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c>> $(TARGDIR)\module\fota\fota.lis
  ifeq ($(strip $(PLATFORM)),MT6226)
		@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\uem_drv.c>> $(TARGDIR)\module\fota\fota.lis
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
		@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\uem_drv.c>> $(TARGDIR)\module\fota\fota.lis
  endif
else
  ifeq ($(strip $(PLATFORM)),MT6226)
		@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\custom_equipment.c>> $(TARGDIR)\module\fota\fota.lis
  endif
endif
ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
	@echo vendor\hp_fota\UA\uaheapsettings.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uamain.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawdebug.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawdevice.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawflash.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawpackage.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_env_api.c>> $(TARGDIR)\module\fota\fota.lis
	@echo sss\interface\src\SSS_interface.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_dbg_print.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_dbg_print.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_uart_drv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_cache.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_adm.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nor_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nor_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nand_lae_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_backup_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nand_update_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_mem_heap.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\dma.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\flash_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\flash_mtd.amd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\flash_mtd.intel.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_partial_fota.c>> $(TARGDIR)\module\fota\fota.lis
	@echo init\src\mmu.c>> $(TARGDIR)\module\fota\fota.lis
	@echo init\src\cache.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\common_drv\pwic_cust.c >> $(TARGDIR)\module\fota\fota.lis
	@echo init\src\init_memory_stack.c >> $(TARGDIR)\module\fota\fota.lis

ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
	@echo sss\interface\src\crypto_drv_interface.c >> $(TARGDIR)\module\fota\fota.lis
	@echo init\GFH\public\br_GFH_parser.c >> $(TARGDIR)\module\fota\fota.lis
	@echo init\GFH\public\br_GFH_file_info.c >> $(TARGDIR)\module\fota\fota.lis
endif

ifeq ($(call Upper,$(strip $(PMIC))),MT6238PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6235PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6223PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6253PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu6253.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6236PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu6236.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6318)
	@echo drv\src\i2c_dual.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmic6318.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6326)
	@echo drv\src\i2c_dual.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmic6326.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifneq ($(strip $(NAND_FLASH_BOOTING)), NONE)
	@echo fota\src\fue_nand_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DAL.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD_FDM50.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DevConfig.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nand_lae_if.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifneq ($(strip $(FOTA_UPDATE_PACKAGE_ON_NAND)), FALSE)
	@echo fota\src\fue_nand_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DAL.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD_FDM50.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DevConfig.c>> $(TARGDIR)\module\fota\fota.lis
endif
endif
endif

	@tools\make.exe -fmake\gsm2.mak -r -R $(strip $(CMD_ARGU)) XGC_AND_NOT_BOOTLOADER=FALSE CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) fota.lib

	@echo Linking $(strip $(FOTA_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(FOTALNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\fota.lib(*) >> make\~libs.tmp

ifdef FOTA_ENABLE
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
   ifeq ($(strip $(COMPILER)),ADS)
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_FOTA_PLATFORM)),)
			@echo vendor\hp_fota\lib\libmprove610_MTKarm9_tcc.a>> make\~libs.tmp
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM7_FOTA_PLATFORM)),)
			@echo vendor\hp_fota\lib\libmprove610_MTKarm7_tcc.a>> make\~libs.tmp
    endif
   endif
   ifeq ($(strip $(COMPILER)),RVCT)
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM11_FOTA_PLATFORM)),)
			@echo vendor\redbend_fota\MTK_FPP_FW_rvct31_arm11.lib>> make\~libs.tmp
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_FOTA_PLATFORM)),)
			@echo vendor\redbend_fota\MTK_FPP_FW_rvct31_arm9.lib>> make\~libs.tmp
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM7_FOTA_PLATFORM)),)
			@echo vendor\redbend_fota\MTK_FPP_FW_rvct31_arm7.lib>> make\~libs.tmp
    endif
   endif
    ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
			@echo $(strip $(COMPLIBDIR))\che.lib >> make\~libs.tmp
			@echo $(strip $(COMPLIBDIR))\ssf.lib >> make\~libs.tmp
			@echo $(strip $(COMPLIBDIR))\sst_sec.lib >> make\~libs.tmp
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
			@echo $(strip $(COMPLIBDIR))\lqt.lib >> make\~libs.tmp
      endif
    else
			@echo $(strip $(CUS_MTK_LIB))\che.lib >> make\~libs.tmp
			@echo $(strip $(CUS_MTK_LIB))\ssf.lib >> make\~libs.tmp
			@echo $(strip $(CUS_MTK_LIB))\sst_sec.lib >> make\~libs.tmp
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
        ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
					@echo $(strip $(COMPLIBDIR))\lqt.lib >> make\~libs.tmp
        else
					@echo $(strip $(CUS_MTK_LIB))\lqt.lib >> make\~libs.tmp
        endif
      endif
    endif

    ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
      ifeq ($(strip $(COMPILER)),RVCT)
        ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
				@echo $(strip $(COMPLIBDIR))\sss_rvct_sv5.lib >> make\~libs.tmp
        else
				@echo $(strip $(COMPLIBDIR))\sss_rvct_sv3.lib >> make\~libs.tmp
        endif
      else
				@echo $(strip $(COMPLIBDIR))\sss.lib >> make\~libs.tmp
      endif
    endif
    ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
      ifeq ($(strip $(COMPILER)),RVCT)
        ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
				@echo sss\lib\sss_rvct_sv5.lib >> make\~libs.tmp
        else
				@echo sss\lib\sss_rvct_sv3.lib >> make\~libs.tmp
        endif
      else
				@echo sss\lib\sss.lib >> make\~libs.tmp
      endif
    endif

  endif
endif

	@echo $(LINK) $(VIA) make\~libs.tmp
	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if exist make\~sortedLibs.tmp (copy /y make\~sortedLibs.tmp $(strip $(COMPLOGDIR))\link_option_fota.log >nul)
ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe FOTA $(strip $(LINK)) $(strip $(FOTA_LOG)) NONE $(strip $(VIA)) NONE $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(FOTA_PREFIX).elf $(strip $(BIN_FORMAT)) $(strip $(FOTA_BIN_FILE)) $(strip $(TST_DB)) $(FOTA_PREFIX).lis
else
	@$(LINK) $(VIA) make\~sortedLibs.tmp >> $(FOTA_LOG) 2>&1
	@echo Creating binary file $(FOTA_BIN_FILE)
	@echo $(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(FOTA_BIN_FILE)
	@$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(FOTA_BIN_FILE)
endif

	perl .\tools\fota_append.pl $(strip $(TARGDIR))\$(strip $(FOTA_PREFIX)).sym $(call Upper,$(strip $(BIN_FILE))) $(strip $(VERNO)) $(strip $(THE_MF)) $(strip $(FOTA_SCATTERFILE)) $(strip $(TARGDIR))\$(FOTA_BIN_FILE)

ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
	@if not exist make\~gfh_cfg.tmp (tools\make.exe -fmake\gsm2.mak -r -R gen_gfh_cfg)
	@if exist $(strip $(TARGDIR))\$(FOTA_BIN_FILE) \
		(echo $(strip $(TARGDIR))\$(FOTA_BIN_FILE) > make\~gfh_files.tmp) & \
		(perl tools\gfh_process.pl make\~gfh_files.tmp make\~gfh_cfg.tmp $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\gfh_process_fota.log 2>&1) & \
		(if ERRORLEVEL 1 (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))\gfh_process_fota.log & exit 1))
endif

ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe FOTAs $(strip $(LINK)) $(strip $(FOTA_LOG)) NONE $(strip $(VIA)) NONE $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(FOTA_PREFIX).elf $(strip $(BIN_FORMAT)) $(strip $(FOTA_BIN_FILE)) $(strip $(TST_DB)) $(FOTA_PREFIX).lis
endif

endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  BOOTLOADER Targets
# *************************************************************************
ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
    ifeq ($(strip $(ACTION)),bootloader)
bootloader: gen_bl_verno gencompbld bl_preflow LINK_BL BL_POSTBUILD done
    else
bootloader: gen_bl_verno gencompbld bl_preflow LINK_BL LINK_BL_CHECK BL_POSTBUILD
    endif
  else
bootloader:
  endif
else
bootloader:
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
bl_preflow: 
else
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
bl_preflow: xgc_all_libs
  else
bl_preflow: $(BL_COMPLIBLIST)
  endif
endif
#$(eval $(call CheckNeedDependTarget,bl_preflow,postgen_dep))
#$(strip $(RULESDIR_TARGET))\postgen_dep\bl_preflow.det:
#ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).* (del /q $(strip $(TARGDIR))\$(BTLD_PREFIX).*)
	@if exist $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).* (del /q $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).*)
	@if exist $(BOOTLOADER_LOG) (del /q $(BOOTLOADER_LOG))
	@if exist $(BOOTLOADER_LOG) (del /q $(BOOTLOADER_EXT_LOG))
	@if exist $(strip $(COMPLOGDIR))\bootloader.log (del /q $(strip $(COMPLOGDIR))\bootloader.log)
	@if exist $(strip $(COMPLOGDIR))\bootloader_ext.log (del /q $(strip $(COMPLOGDIR))\bootloader_ext.log)
ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@if exist $(strip $(OBJSDIR))\bootloader (del /q $(strip $(OBJSDIR))\bootloader\*.*)
	@if exist $(strip $(OBJSDIR))\bootloader_ext (del /q $(strip $(OBJSDIR))\bootloader_ext\*.*)
	@if exist $(strip $(RULESDIR))\bootloader.dep (del $(strip $(RULESDIR))\bootloader.dep)
	@if exist $(strip $(RULESDIR))\bootloader_ext.dep (del $(strip $(RULESDIR))\bootloader_ext.dep)
endif
	@if exist $(strip $(COMPLIBDIR))\bootloader.lib (del $(strip $(COMPLIBDIR))\bootloader.lib)
	@if exist $(strip $(COMPLIBDIR))\bootloader_ext.lib (del $(strip $(COMPLIBDIR))\bootloader_ext.lib)
#endif
	@if not exist $(PROJDIR) (md $(PROJDIR))
	@if not exist $(TARGDIR) (md $(TARGDIR))
	@if not exist $(COMPLOGDIR) (md $(COMPLOGDIR))
	@if exist make\~bllibs.tmp (del /f /q make\~bllibs.tmp)

ifneq ($(strip $(BL_LINKLIST)),)
	@tools\strcmpex.exe def def e make\~bllklibs.tmp $(foreach comp,$(BL_LINKLIST), '$(CUS_MTK_LIB)\$(comp)')
	@perl tools\lnitem.pl make\~bllklibs.tmp
	@if exist make\~bllklibs.tmp (type make\~bllklibs.tmp >> make\~bllibs.tmp)
endif

ifneq ($(strip $(BL_COMPLIBLIST)),)
	@tools\strcmpex.exe def def e make\~blcplibs.tmp $(foreach comp,$(BL_COMPLIBLIST), '$(COMPLIBDIR)\$(comp)')
	@perl tools\lnitem.pl make\~blcplibs.tmp
	@if exist make\~blcplibs.tmp (type make\~blcplibs.tmp >> make\~bllibs.tmp)
endif

ifneq ($(strip $(BL_COMPOBJS)),)
	@if exist make\~libs.tmp (del /f /q make\~libs.tmp)
	@perl tools\echoLongString4.pl make\~libs.tmp $(BL_COMPOBJS)
	@if exist make\~libs.tmp (type make\~libs.tmp >> make\~bllibs.tmp)
endif

# *************************************************************************
#  Executable Bootloader Targets
# *************************************************************************
LINK_BL: LINK_BL_BIN_FILE LINK_BLEXT_BIN_FILE
BL_POSTBUILD: BLFILE_POSTBUILD BLEXTFILE_POSTBUILD

#ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
#$(BTLD_BIN_FILE): FORCE
#else
#-include $(strip $(RULESDIR_TARGET))\postgen_dep\.\bootloader.det
#endif
#$(BTLD_BIN_FILE): $(strip $(RULESDIR_TARGET))\postgen_dep\bl_preflow.det $(strip $(RULESDIR_TARGET))\postgen_dep\gen_bl_verno.det

LINK_BL_BIN_FILE:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\make.exe -fmake\gsm2.mak -k -r -R XGC_AND_NOT_BOOTLOADER=FALSE CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) bootloader.lib

	@echo Linking $(strip $(BTLD_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(BTLDLNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\bootloader.lib(*) >> make\~libs.tmp
	@if exist make\~bllibs.tmp (type make\~bllibs.tmp >> make\~libs.tmp)
	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if exist make\~sortedLibs.tmp (copy /y make\~sortedLibs.tmp $(strip $(COMPLOGDIR))\link_option_bl.log >nul)
  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe BOOTLOADER $(strip $(LINK)) $(strip $(BOOTLOADER_LOG)) NONE $(strip $(VIA)) NONE $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(BTLD_PREFIX).elf $(strip $(BIN_FORMAT)) $(strip $(BTLD_BIN_FILE)) $(strip $(TST_DB)) $(BTLD_PREFIX).lis
  else
	@($(LINK) $(VIA) make\~sortedLibs.tmp >> $(BOOTLOADER_LOG) 2>&1) & \
	(if ERRORLEVEL 1 \
				(echo Error: link failed! Please check $(BOOTLOADER_LOG)) & \
				(if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).elf (del /q $(strip $(TARGDIR))\$(BTLD_PREFIX).elf)))
  endif
 
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

BLFILE_POSTBUILD:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(strip $(TARGDIR))\$(BTLD_PREFIX).elf \
		(echo Error: $(strip $(TARGDIR))\$(BTLD_PREFIX).elf does not exist! Please check link error for bootloader. & exit 1)
	$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(BTLD_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BTLD_BIN_FILE)
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH))) & \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_KEY"   .\tools\update_img.exe -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH))) & \
	@if not exist make\~gfh_cfg.tmp (tools\make.exe -fmake\gsm2.mak -r -R gen_gfh_cfg)
	@echo $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))> make\~gfh_files.tmp
	@perl tools\gfh_process.pl make\~gfh_files.tmp make\~gfh_cfg.tmp $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\gfh_process_bl.log 2>&1 & \
	(if ERRORLEVEL 1 (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))\gfh_process_bl.log & exit 1))
#	@echo [Dependency] tools\update_img.exe $(KEYFILE_PATH) tools\gfh_process.pl >$(RULESDIR)\postgen_dep\bootloader.log
else
	@if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))\READ_ONLY \
		copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))\READ_ONLY $(strip $(TARGDIR))\READ_ONLY & \
		rmdir /S /Q $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) & \
		move /Y $(strip $(TARGDIR))\READ_ONLY $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))

	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH))) & \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_KEY"   .\tools\update_img.exe -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH))) & \

	@perl .\tools\bl_append.pl $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(BTLDVERNODIR))\bl_verno.c $(strip $(BL_SCATTERFILE)) $(strip $(THE_MF)) $(strip $(TARGDIR))\$(BTLD_PREFIX).sym $(call Upper,$(strip $(BIN_FILE))) $(strip $(VERNO))
#	@echo [Dependency] tools\update_img.exe $(KEYFILE_PATH) tools\bl_append.pl >$(RULESDIR)\postgen_dep\bootloader.log
endif

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) \
			del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
		copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul

  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe BOOTLOADERs $(strip $(LINK)) $(strip $(LOG)) $(strip $(LNKERRORLOG)) $(strip $(VIA)) $(strip $(HEADER_TEMP)) $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(strip $(IMG_FILE)) $(strip $(BIN_FORMAT)) $(strip $(BTLD_BIN_FILE)) $(strip $(TST_DB)) $(TARGNAME).lis
  endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  Executable ExtBootloader Targets
# *************************************************************************
#ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
#$(BTLD_EXT_BIN_FILE): FORCE
#else
#-include $(strip $(RULESDIR))\postgen_dep\.\bootloader_ext.det
#endif
#$(BTLD_EXT_BIN_FILE): $(strip $(RULESDIR))\postgen_dep\bl_preflow.det $(strip $(RULESDIR))\postgen_dep\gen_bl_verno.det
LINK_BLEXT_BIN_FILE:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	
	@tools\make.exe -fmake\gsm2.mak -k -r -R XGC_AND_NOT_BOOTLOADER=FALSE CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) bootloader_ext.lib
	@echo Linking $(strip $(BTLD_EXT_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(BTLDEXTLNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\bootloader_ext.lib(*) >> make\~libs.tmp
	@if exist make\~bllibs.tmp (type make\~bllibs.tmp >> make\~libs.tmp)
	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if exist make\~sortedLibs.tmp (copy /y make\~sortedLibs.tmp $(strip $(COMPLOGDIR))\link_option_blext.log >nul)
ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe BOOTLOADER $(strip $(LINK)) $(strip $(BOOTLOADER_EXT_LOG)) NONE $(strip $(VIA)) NONE $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(BTLD_EXT_PREFIX).elf $(strip $(BIN_FORMAT)) $(strip $(BTLD_EXT_BIN_FILE)) $(strip $(TST_DB)) $(BTLD_EXT_PREFIX).lis
else
	@$(LINK) $(VIA) make\~sortedLibs.tmp >> $(BOOTLOADER_EXT_LOG) 2>&1 & \
		(if ERRORLEVEL 1 \
				(echo Error: link failed! Please check $(BOOTLOADER_EXT_LOG)) & \
				(if exist $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf (del /q $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf)))
endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

BLEXTFILE_POSTBUILD:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf \
		(echo Error: $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf does not exist! Please check link error for ext_bootloader. & exit 1)
	$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BTLD_EXT_BIN_FILE)
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
	@if not exist make\~gfh_cfg.tmp (tools\make.exe -fmake\gsm2.mak -r -R gen_gfh_cfg)
	@echo $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE))> make\~gfh_files.tmp
	@perl tools\gfh_process.pl make\~gfh_files.tmp make\~gfh_cfg.tmp $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\gfh_process_extbl.log 2>&1 & \
	(if ERRORLEVEL 1 (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))\gfh_process_extbl.log & exit 1))
#	@echo [Dependency] tools\gfh_process.pl >$(RULESDIR)\postgen_dep\bootloader_ext.log
else
	@perl .\tools\bl_append.pl $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE)) $(strip $(BTLDVERNODIR))\bl_verno.c $(strip $(BL_EXT_SCATTERFILE)) $(strip $(THE_MF)) $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).sym $(call Upper,$(strip $(BIN_FILE))) $(strip $(VERNO))
#	@echo [Dependency] tools\bl_append.pl >$(RULESDIR)\postgen_dep\bootloader_ext.log
endif

	@if exist $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE))\
		copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE)) $(strip $(TARGDIR))\EXT_BOOTLOADER

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		copy /Y $(strip $(TARGDIR))\EXT_BOOTLOADER $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul

ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	tools\Linker.exe BOOTLOADERs $(strip $(LINK)) $(strip $(LOG)) $(strip $(LNKERRORLOG)) $(strip $(VIA)) $(strip $(HEADER_TEMP)) $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(strip $(IMG_FILE)) $(strip $(BIN_FORMAT)) $(strip $(BTLD_EXT_BIN_FILE)) $(strip $(TST_DB)) $(TARGNAME).lis
endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
# Generate Bootloader VersionNo
# *************************************************************************
gen_bl_verno: make\~customIncDef.tmp
#$(eval $(call CheckNeedDependTarget,gen_bl_verno,postgen_dep))
#$(strip $(RULESDIR_TARGET))\postgen_dep\gen_bl_verno.det:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'gen_bl_verno START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@echo Generate BOOTLOADER CMM file ...
#	@echo [Dependency] tools\CMMAutoGen.pl >$(basename $@).log
	@if exist tools\CMMAutoGen.pl  \
	((perl tools\CMMAutoGen.pl 2 $(FIXPATH)\BOOTLOADER_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm $(strip $(TARGDIR))\$(BTLD_PREFIX).elf $(strip $(THE_MF)) $(strip $(BIN_FILE)) ~lis_temp "$(CC)" "$(VIA)" make\~customIncDef.tmp $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\cmmgen_blnocode.log) & \
		(if ERRORLEVEL 1 echo Error: generate BOOTLOADER CMM file Failed. Please check $(strip $(COMPLOGDIR))\cmmgen_blnocode.log & exit 1) & \
		(perl tools\CMMAutoGen.pl 3 $(FIXPATH)\EXT_BOOTLOADER_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf $(strip $(THE_MF)) $(strip $(BIN_FILE)) ~lis_temp "$(CC)" "$(VIA)" make\~customIncDef.tmp $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\cmmgen_extblnocode.log) & \
		(if ERRORLEVEL 1 echo Error: generate EXT_BOOTLOADER CMM file Failed. Please check $(strip $(COMPLOGDIR))\cmmgen_extblnocode.log & exit 1))


	@echo Generate BOOTLOADER version number ...
	@if not exist $(strip $(BTLDVERNODIR)) exit 0

	@if exist $(strip $(BTLDVERNODIR))\bl_verno.c (del $(strip $(BTLDVERNODIR))\bl_verno.c)

	@echo #include "kal_release.h" > $(strip $(BTLDVERNODIR))\bl_verno.c
	@echo const kal_uint32 CHECKSUM_SEED = $(strip $(BTLD_CHECKSUM_SEED)); >> $(strip $(BTLDVERNODIR))\bl_verno.c
	@echo const kal_int8 BootLDVerno[5] = "$(strip $(BTLD_VERNO))"; >> $(strip $(BTLDVERNODIR))\bl_verno.c

ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@echo COMPLIBLIST=$(BL_COMPLIBLIST) > make\complib.txt
endif

	@perl -e "print 'gen_bl_verno END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
# Generate VersionNo
# *************************************************************************
genverno:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'genverno START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	@echo Generate version number ... >> $(LOG)

	@if not exist $(VERNODIR) \
		md $(VERNODIR)

	@if exist $(strip $(VERNODIR))\verno.c (del $(strip $(VERNODIR))\verno.c)

	@echo #include "kal_release.h" > $(strip $(VERNODIR))\verno.c
	@echo kal_char* release_verno(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char verno_str[] = "$(strip $(VERNO))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return verno_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_hal_verno(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char hal_verno_str[] = "$(strip $(HAL_VERNO))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return hal_verno_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_hw_ver(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
ifeq ($(call Upper,$(strip $(CUSTOMER))),TIANYU28_DEMO)
ifeq ($(call Upper,$(strip $(FLAVOR))),TP_Q05A_LANDSCAPE)
	@echo    static kal_char hw_ver_str[] = "TIANYU28_TP_DEMO_HW"; >> $(strip $(VERNODIR))\verno.c
else
	@echo    static kal_char hw_ver_str[] = "$(strip $(HW_VER))"; >> $(strip $(VERNODIR))\verno.c
endif
else
	@echo    static kal_char hw_ver_str[] = "$(strip $(HW_VER))"; >> $(strip $(VERNODIR))\verno.c
endif
	@echo    return hw_ver_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* build_date_time(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_date_time_str[] = "$(strip $(BUILD_DATE_TIME))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_date_time_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_build(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_str[] = "$(strip $(BUILD))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_branch(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_branch_str[] = "$(strip $(BRANCH))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_branch_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_flavor(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_flavor_str[] = "$(strip $(FLAVOR))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_flavor_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_platform(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char release_platform_str[] = "$(strip $(PLATFORM))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return release_platform_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_mmi_base(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char release_mmi_base_str[] = "$(strip $(MMI_BASE))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return release_mmi_base_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_mmi_ver(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char release_mmi_ver_str[] = "$(strip $(MMI_VERSION))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return release_mmi_ver_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo #define VERNO_STR "$(strip $(VERNO))" > $(strip $(VERNODIR))\verno.h

	@echo #define HW_VER_STR "$(strip $(HW_VER))" >> $(strip $(VERNODIR))\verno.h
	@echo #define BUILD_DATE_TIME_STR "$(strip $(BUILD_DATE_TIME))" >> $(strip $(VERNODIR))\verno.h
	@echo #define BUILD_STR "$(strip $(BUILD))" >> $(strip $(VERNODIR))\verno.h
	@echo #define BUILD_BRANCH_STR "$(strip $(BRANCH))" >> $(strip $(VERNODIR))\verno.h
	@echo #define PLATFORM "$(strip $(PLATFORM))" >> $(strip $(VERNODIR))\verno.h
	@echo #define MMI_BASE "$(strip $(MMI_BASE))" >> $(strip $(VERNODIR))\verno.h
	@echo #define MMI_VERSION "$(strip $(MMI_VERSION))" >> $(strip $(VERNODIR))\verno.h

	@perl -e "print 'genverno END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate Original VersionNo
# *************************************************************************
genoriverno:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if not exist $(VERNODIR) md $(VERNODIR)
	@if exist $(strip $(VERNODIR))\origin_verno.c (del $(strip $(VERNODIR))\origin_verno.c)
	
	@echo #include "kal_release.h" > $(strip $(VERNODIR))\origin_verno.c
	@echo kal_char* customer_name(void) >> $(strip $(VERNODIR))\origin_verno.c
	@echo { >> $(strip $(VERNODIR))\origin_verno.c
	@echo    static kal_char customer_name[] = "$(strip $(FULL_PRJ_NAME))"; >> $(strip $(VERNODIR))\origin_verno.c
	@echo    return customer_name; >> $(strip $(VERNODIR))\origin_verno.c
	@echo } >> $(strip $(VERNODIR))\origin_verno.c
	
	@echo kal_char* origin_release_verno(void) >> $(strip $(VERNODIR))\origin_verno.c
	@echo { >> $(strip $(VERNODIR))\origin_verno.c
	@echo    static kal_char origin_release_verno[] = "$(strip $(BRANCH))"; >> $(strip $(VERNODIR))\origin_verno.c
	@echo    return origin_release_verno; >> $(strip $(VERNODIR))\origin_verno.c
	@echo } >> $(strip $(VERNODIR))\origin_verno.c
endif	
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check MMI Feature Files
# *************************************************************************
mmi_feature_check: flavor_conf gencustominfo gen_infolog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'mmi_feature_check START TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
	@if exist $(strip $(TARGDIR))\log\mmi_check.log \
		(del /q /f $(strip $(TARGDIR))\log\mmi_check.log)
	@if exist $(strip $(TARGDIR))\MMI_DRV_DEFS.mak \
		(del /q /f $(strip $(TARGDIR))\MMI_DRV_DEFS.mak)
ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
    ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
      ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\mmi_feature_check.pl \
		(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\MMI_features.h plutommi\mmi\inc\MMI_features_switch.h TRUE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak MMI 2>>$(strip $(TARGDIR))\log\mmi_check.log)
      endif
    else
      ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\mmi_feature_check.pl \
		(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) lcmmi\mmi\inc\MMI_features.h lcmmi\mmi\inc\MMI_features_switch.h TRUE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak MMI 2>>$(strip $(TARGDIR))\log\mmi_check.log)
      endif
    endif
	@if exist tools\mmi_feature_check.pl \
		(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) hal\drv_def\drv_features.h hal\drv_def\drv_features_option.h FALSE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak DRV 2>>$(strip $(TARGDIR))\log\mmi_check.log)
  endif
  endif
else
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist tools\mmi_feature_check.pl \
		(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\MMI_features.h plutommi\mmi\inc\MMI_features_switch.h TRUE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak MMI 2>>$(strip $(TARGDIR))\log\mmi_check.log)
	@if exist tools\mmi_feature_check.pl \
		(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) hal\drv_def\drv_features.h hal\drv_def\drv_features_option.h FALSE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak DRV 2>>$(strip $(TARGDIR))\log\mmi_check.log)
  endif
endif

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
	@if exist tools\mmi_feature_check.pl \
		(@if exist $(strip $(OPTR_PATH))\operator_mmi.h \
			(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\mmi_features.h $(strip $(OPTR_PATH))\operator_mmi.h TRUE $(strip $(OP_CHECK_FORCE_ERROR)) $(strip $(TARGDIR))\MMI_DRV_DEFS.mak OPTR) \
		else \
			(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\mmi_features.h $(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\operator_mmi.h TRUE $(strip $(OP_CHECK_FORCE_ERROR)) $(strip $(TARGDIR))\MMI_DRV_DEFS.mak OPTR) \
		)
  endif
endif

	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'mmi_feature_check END TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


flavor_conf:
ifeq ($(strip $(RUN_FLAVOR_CONF_PL)),TRUE)
$(eval $(call CheckNeedDependTarget,flavor_conf,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\emigen.det: $(strip $(RULESDIR_TARGET))\pregen_dep\flavor_conf.det
$(strip $(RULESDIR_TARGET))\pregen_dep\gencustominfo.det: $(strip $(RULESDIR_TARGET))\pregen_dep\flavor_conf.det
$(strip $(RULESDIR_TARGET))\pregen_dep\flavor_conf.det:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if not exist $(patsubst %\,%,$(dir $@)) mkdir $(patsubst %\,%,$(dir $@))
	perl make\flavor_conf.pl $(CUSTOMER) $(FLAVOR) $(PROJECT)
	@perl tools\pack_dep_gen.pl $@ $@ $(COMPLOGDIR) $(basename $(notdir $@))\.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


dummy_data_check:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist tools\ROParser.pl \
		(perl tools\ROParser.pl $(strip $(TARGDIR))\$(strip $(LIS_FILE)) $(strip $(PROJDIR))\ $(strip $(FIXPATH))\ $(strip $(SLIM_BRANCH)))
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# To remove codes from the specified file
# *************************************************************************
genremoveinfo:
	@tools\strcmpex.exe abc abc e make\~com_def.tmp $(strip $(COM_DEFS))
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	@echo _SST_FUNCTION_ENABLE_ >> make\~com_def.tmp
endif
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
	@if not exist make\$(strip $(CUSTOMER))_$(PROJECT)_en.def \
		(type make\SUPERSET_CUSTOM_en.def > make\$(strip $(CUSTOMER))_$(PROJECT)_en.def)
endif
	@if not exist make\$(strip $(CUSTOMER))_$(PROJECT)_en.def \
		(copy /y nul make\$(strip $(CUSTOMER))_$(PROJECT)_en.def > nul)
	@if not exist make\$(strip $(CUSTOMER))_$(PROJECT)_dis.def \
		(perl mtk_tools\Auto_RemovingCode.pl $(strip $(CUSTOMER)) $(PROJECT) "$(CC)" $(MTK_SUBSIDIARY) $(THE_MF))
removecode: genremoveinfo
	@echo .> ~customRemovalDir.tmp
	@if exist mtk_tools\traversedir.pl \
		(perl mtk_tools\traverseDir.pl "$(REMOVE_DIR)" make\$(strip $(CUSTOMER))_$(PROJECT)_en.def make\$(strip $(CUSTOMER))_$(PROJECT)_dis.def TRUE TRUE ~customRemovalDir.tmp $(strip $(NOT_REMOVAL_DIR_FILE)))
	@if exist make\~com_def.tmp del make\~com_def.tmp

# *************************************************************************
# Check operator setting Files (An independent target)
# *************************************************************************
operator_check: gencustominfo gen_infolog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'operator_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
	@if exist tools\operator_check.pl \
		(perl tools\operator_check.pl $(strip $(CUSTOMER)) $(strip $(call Upper,$(PROJECT))) $(strip $(OPTR_WARNING_DEF)) $(firstword $(strip $(CC))) $(strip $(VIA)))

	@if exist tools\mmi_feature_check.pl \
		(@if exist $(strip $(OPTR_PATH))\operator_mmi.h \
			(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\mmi_features.h $(strip $(OPTR_PATH))\operator_mmi.h TRUE $(strip $(OP_CHECK_FORCE_ERROR)) $(strip $(TARGDIR))\MMI_DRV_DEFS.mak OPTR) \
		else \
			(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\mmi_features.h $(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\operator_mmi.h TRUE $(strip $(OP_CHECK_FORCE_ERROR)) $(strip $(TARGDIR))\MMI_DRV_DEFS.mak OPTR) \
		)
  endif
endif

	@perl -e "print 'operator_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check if system drive space is enough or not
# *************************************************************************
$(strip $(COMPLOGDIR))\ckSysDrv.log : custom\app\$(strip $(BOARD_VER))\nvram_user_config.c custom\common\fs_quota.c tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c custom\system\$(strip $(BOARD_VER))\custom_MemoryDevice.h custom\common\hal\flash_opt.h
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
ifeq ($(strip $(CUSTOM_EXIST)),TRUE)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cksysdrv START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # If building for basic, l1s, don't run cksysdrv.pl
   # If module "custom" is released to customer with .lib only, don't run cksysdrv.pl
   # If NAND_FLASH_BOOTING is TRUE, don't run cksysdrv.pl

	@echo checking system drive space ...
	@tools\strcmpex.exe def def e make\~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~customIncDef.tmp
	@tools\strcmpex.exe inc inc e make\~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))

	@if exist custom\app\$(strip $(BOARD_VER))\nvram_user_config.c \
		(@if exist custom\common\fs_quota.c \
			(type make\~customInc.tmp >> make\~customIncDef.tmp) & \
			(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.def) do \
				(echo -D%%i >> make\~customIncDef.tmp) \
			) & \
			(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.inc) do \
				(echo -I%%i >> make\~customIncDef.tmp) \
			) & \
			($(CC) $(VIA) make\~customIncDef.tmp -E tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c > ~flash_cfg_tmp.c) \
		)
	@perl tools\ckSysDrv.pl ~flash_cfg_tmp.c ~fs_quota_usage.log ~nvram_lid_size.log $(strip $(FEATURE_OVERLOAD)) $(strip $(SYSTEM_DRIVE_ON_NAND)) $(strip $(NVRAM_PSEUDO_MERGE))> $(strip $(COMPLOGDIR))\ckSysDrv.log & \
	(if ERRORLEVEL 1 echo ckSysDrv error. Please check $(strip $(COMPLOGDIR))\ckSysDrv.log)

	@perl -e "print 'cksysdrv END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
endif
endif
endif

ifeq ($(MODIS_CONFIG),FALSE)
cksysdrv_slim: $(strip $(COMPLOGDIR))\ckSysDrv.log
	@echo cksysdrv was done.
else
cksysdrv_slim:
endif

cksysdrv: cksysdrv_clean nvram_auto_gen $(strip $(COMPLOGDIR))\ckSysDrv.log
	@echo cksysdrv was done.

cksysdrv_clean:
	@if exist $(strip $(COMPLOGDIR))\cksysdrv.log \
		del /q /f $(strip $(COMPLOGDIR))\cksysdrv.log

# *************************************************************************
# check scatter file and memory device consistency
# *************************************************************************
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
ckscatter:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'ckscatter START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if exist $(FIXPATH)\tools\ckScatter.pl \
		(perl $(FIXPATH)\tools\ckScatter.pl 1 TRUE $(SCATTERFILE) ~lis_temp ~flash_cfg_tmp.c $(strip $(THE_MF)) $(strip $(BB_FOLDER_PATH)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\ckscatter1.log)

	@perl -e "print 'ckscatter END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ckscatter2:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'ckscatter2 START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if exist $(FIXPATH)\tools\ckScatter.pl \
		(if exist ~lis_temp \
		   (perl $(FIXPATH)\tools\ckScatter.pl 2 TRUE $(SCATTERFILE) ~lis_temp ~flash_cfg_tmp.c $(strip $(THE_MF)) $(strip $(BB_FOLDER_PATH)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\ckscatter2.log))

	@perl -e "print 'ckscatter2 END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif

# *************************************************************************
# Generate cmm files for different SUB_BOARD_VER
# *************************************************************************
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  RUN_CMMGEN_HQ = TRUE
else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  RUN_CMMGEN_HQ = TRUE
else
  RUN_CMMGEN_HQ = FALSE
endif

cmmgen: make\~customIncDef.tmp
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cmmgen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		((echo $(strip $(TARGDIR))\$(strip $(BIN_FILE)) does not exist. Please check it.) & (exit 2)) \
	else (if not exist ~lis_temp \
		(perl tools\parse_lis.pl $(strip $(TARGDIR))\$(TARGNAME).lis ~lis_temp))

	@echo Generate cmm files
ifneq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
	@if exist tools\CMMAutoGen.pl  \
	(perl tools\CMMAutoGen.pl 0 $(FIXPATH)\$(strip $(TARGNAME))_nocode.cmm $(strip $(TARGDIR))\$(TARGNAME).elf $(strip $(THE_MF)) $(strip $(BIN_FILE)) ~lis_temp "$(CC)" "$(VIA)" make\~customIncDef.tmp $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\cmmgen_nocode.log) & \
	(if ERRORLEVEL 1 echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))\cmmgen_nocode.log & exit 1)
else
	@if exist tools\CMMAutoGen.pl  \
	(perl tools\CMMAutoGen.pl 0 $(FIXPATH)\$(strip $(TARGNAME))_nocode.cmm $(strip $(TARGDIR))\$(TARGNAME).elf $(strip $(THE_MF)) $(strip $(BIN_FILE)) ~lis_temp "$(CC)" "$(VIA)"  make\~customIncDef.tmp $(strip $(INSIDE_MTK)) $(strip $(TARGDIR))\$(TS_PREFIX).elf > $(strip $(COMPLOGDIR))\cmmgen_nocode.log) & \
	(if ERRORLEVEL 1 echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))\cmmgen_nocode.log & exit 1)
endif
ifeq ($(strip $(RUN_CMMGEN_HQ)),TRUE)
	@if exist tools\CMMAutoGen.pl  \
	(perl tools\CMMAutoGen.pl 1 $(FIXPATH)\$(strip $(TARGNAME))_HQ_Only.cmm $(strip $(TARGDIR))\$(TARGNAME).elf $(strip $(THE_MF)) $(strip $(BIN_FILE)) ~lis_temp "$(CC)" "$(VIA)" make\~customIncDef.tmp $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\cmmgen_hqonly.log) & \
	(if ERRORLEVEL 1 echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))\cmmgen_hqonly.log & exit 1)
endif
	@perl -e "print 'cmmgen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cfggen:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
	@echo Generate CFG file for flash tool
	@if not exist make\~customIncDef.tmp tools\make.exe -fmake\gsm2.mak -r -R make\~customIncDef.tmp
  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
			(perl $(FIXPATH)\tools\cfgGen.pl 1 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) $(strip $(FOTA_BIN_FILE)) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE) "$(CC)" "$(VIA)" make\~customIncDef.tmp "$(strip $(NET_PATH))" -sign> $(strip $(COMPLOGDIR))\cfggen.log)
  else
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
			(perl $(FIXPATH)\tools\cfgGen.pl 1 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) $(strip $(FOTA_BIN_FILE)) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE) "$(CC)" "$(VIA)" make\~customIncDef.tmp "$(strip $(NET_PATH))" > $(strip $(COMPLOGDIR))\cfggen.log)
  endif
endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

make\~customIncDef.tmp:
	@tools\strcmpex.exe def def e make\~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~customIncDef.tmp
	@tools\strcmpex.exe inc inc e make\~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~customInc.tmp >> make\~customIncDef.tmp

	@if not exist $(TARGDIR)\module\custom tools\make.exe -fmake\gsm2.mak -r -R MODULELIS=custom.lis genmoduleinfo
	@if exist $(strip $(TARGDIR))\module\custom \
		(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.def) do \
			(echo -D%%i >> make\~customIncDef.tmp)) & \
		(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.inc) do \
			(echo -I%%i >> make\~customIncDef.tmp))

# *************************************************************************
# Library Targets
# *************************************************************************
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
ifneq ($(filter $(MAKECMDGOALS),remake),)
ifneq ($(strip $(REMAKE_WITH_CGEN)),FALSE)
libs: cgen
endif
endif
endif

ifneq ($(strip $(LINT)),TRUE)
ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
libs: cleanlib startbuildlibs $(COMPLIBLIST)
else 
libs : echo_lib_lists cleanlib startbuildlibs xgc_all_libs_2
endif 
else
libs: $(LINT_COMP_LIST)
endif

echo_lib_lists:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo COMPLIBLIST=$(COMPLIBLIST) > make\complib.txt
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  startbuildlibs: gencompbld
else
  startbuildlibs:
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Start to build $(COMPLIBLIST)
# Copy plutommi header files to a temp folder to improve compiler performance.

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@perl -e "print 'hTogether START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if exist $(COPY_MMI_INCLUDE_FILE) (copy /Y $(COPY_MMI_INCLUDE_FILE) tools\copy_mmi_include_h.bat >NUL)

ifeq ($(strip $(RUN_HTOGETHER)),TRUE)
	@if exist $(CUS_MTK_LIB)\tools\copy_mmi_include_h.bat (copy $(CUS_MTK_LIB)\tools\copy_mmi_include_h.bat tools\copy_mmi_include_h.bat  >NUL)
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    ifeq ($(strip $(RTOS)),NUCLEUS)
		@copy /Y tools\copy_mmi_include_h_nucleus_neptune.bat tools\copy_mmi_include_h.bat >NUL
    endif
  endif
endif
	@echo Copying header files ......
	@if exist $(strip $(HEADER_TEMP))\*.* del /q /f $(strip $(HEADER_TEMP))\*.*
	@if exist tools\mmi_include.dep (del /q /f tools\mmi_include.dep)
	@if not exist $(strip $(HEADER_TEMP)) (md $(strip $(HEADER_TEMP)))
	-@if exist tools\copy_mmi_include_h.bat (tools\copy_mmi_include_h.bat $(strip $(HEADER_TEMP)) 1>nul)

	@perl -e "print 'hTogether END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

endif

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cleanlib:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cleanlib START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

   # can be moved to genlog
	@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).elf)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).lis)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).sym)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).htm)

ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)

ifneq ($(strip $(LINT)),TRUE)
	@echo Clean $(COMPLIBLIST) under $(strip $(COMPLIBDIR))
	@for /d %%i in ($(COMPLIBLIST)) do \
		(if exist $(strip $(COMPLIBDIR))\%%i if not exist $(strip $(OBJSDIR))\%%~ni md $(strip $(OBJSDIR))\%%~ni)
	@for /d %%i in ($(COMPLIBLIST)) do \
		(if exist $(strip $(COMPLIBDIR))\%%i if not exist $(strip $(OBJSDIR))\%%~ni\*.obj (copy /y $(strip $(COMPLIBDIR))\%%i $(strip $(OBJSDIR))\%%~ni\%%i_bak >NUL))
endif

ifneq ($(strip $(LINT)),TRUE)
ifdef BOOTLOADER_CHE
  ifeq ($(strip $(call Upper,$(BOOTLOADER_CHE))),ON)
    ifneq ($(strip $(DO_UPDATE_MODULE)),TRUE)
      ifneq ($(strip $(DO_REMAKE_MODULE)),TRUE)
			@for /d %%i in ($(COMPLIBLIST)) do \
				(if exist $(strip $(COMPLIBDIR))\%%i \
					(if "%%i" NEQ "che.lib" \
						(if "%%i" NEQ "sst_sec.lib" \
							(if "%%i" NEQ "fdm_bl.lib" \
							(if "%%i" NEQ "gfx_core32.lib" \
							(if "%%i" NEQ "sys_sec.lib" \
							(if "%%i" NEQ "ssf.lib" (del $(strip $(COMPLIBDIR))\%%i))))))))
      else
			@for /d %%i in ($(COMPLIBLIST)) do \
				(if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
      endif
    else
			@for /d %%i in ($(COMPLIBLIST)) do \
				(if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
    endif
  else
	@for /d %%i in ($(COMPLIBLIST)) do \
		(if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
  endif
else
	@for /d %%i in ($(COMPLIBLIST)) do \
		(if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
endif
endif

endif

	@perl -e "print 'cleanlib END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
ifneq ($(strip $(LINT)),TRUE)
ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
# in r\comp_dep\$module.det, $module.lib will depend on all source/header files used by all objects in that module
# so if the source/header are not changed, no need to call comp.mak and waste time to archive again
-include $(wildcard $(subst \,/,$(strip $(RULESDIR_TARGET)))/comp_dep/*.det)
%.lib: $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_COMP_LIST)
endif
%.lib:
else
xgc_all_libs xgc_all_libs_2:
endif
else
%.ltp: gencompbld
endif
   # mbis time probe
ifneq ($(strip $(XGC)),TRUE)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$(@F),L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))" EQU "TRUE" \
		(if not exist $(TARGDIR)\log\mbis\$* (md $(TARGDIR)\log\mbis\$*) &\
		if exist $(TARGDIR)\log\mbis\$*\*.mbis (del /q /f $(TARGDIR)\log\mbis\$*\*.mbis))
else
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif

	@if exist $(strip $(COMPLIBDIR))\$*.lib (del /q $(strip $(COMPLIBDIR))\$*.lib)
	@if not exist $(strip $(COMPLIBDIR)) (md $(COMPLIBDIR))

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@if $*==fota \
		(@echo Beginning $* component build process ... > $(FOTA_LOG)) \
	else \
		@if $*==bootloader \
			(@echo Beginning $* component build process ... > $(BOOTLOADER_LOG)) \
		else \
			@if $*==bootloader_ext \
				(@echo Beginning $* component build process ... > $(BOOTLOADER_EXT_LOG)) \
			else \
				(@echo Beginning $* component build process ... >> $(LOG))

	@perl tools\time.pl
	@echo Building $*
	@echo                     LOG: $(strip $(COMPLOGDIR))\$*.log

	@if not exist $(strip $(OBJSDIR))\$* (md $(strip $(OBJSDIR))\$*)
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if not $(ACTION)==remake if not exist $(strip $(RULESDIR))\$*_dep md $(strip $(RULESDIR))\$*_dep
  ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
  else
    # extract all *.det from $module.dep, otherwise, the det of unchanged files will lose
	@if not $(ACTION)==remake if exist $(strip $(RULESDIR))\$*.dep (perl tools\pack_dep_gen.pl --extract $(strip $(RULESDIR))\$*.dep NULL $(strip $(RULESDIR))\$*_dep NULL)
  endif
	@if exist *.via del /f /q *.via
	@if exist *.d del /f /q *.d
endif
   # -----------------------------
   # invoke component build script
   # -----------------------------
# Start to extract obj
ifneq ($(strip $(LINT)),TRUE)
  ifneq ($(strip $(XGC)),TRUE)
    ifneq ($(strip $(RVCT_PARTIAL_LINK)),TRUE)
			@if exist $(strip $(OBJSDIR))\$*\$*.lib_bak if not exist $(subst /,\,$(OBJSDIR))\$*\*.obj  perl tools\extract_obj_from_lib.pl  $(subst /,\,$(OBJSDIR))\$*\$*.lib_bak  $(subst /,\,$(OBJSDIR))\$* $(subst /,\,$(LIB)) $(TARGDIR)\module\$*\$*.lis
    endif
  endif
endif
# End of extract obj

	@perl -e "print '$* START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(LINT)),TRUE)
#@echo tools\make.exe -fmake\comp.mak -r -R COMPONENT=$* ... $(strip $(COMPLOGDIR))\$*.log
ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) --no-print-directory COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))\$*_setEnv.log 2>&1

  ifeq ($(strip $(call Upper,$(BM_NEW))),TRUE)
			@if not exist $(strip $(COMPLOGDIR))\$* md $(strip $(COMPLOGDIR))\$*
			@(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1) & \
			(if ERRORLEVEL 1 \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) & \
			  (exit 1) \
			else \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) \
			)
  else
			@if not exist $(strip $(COMPLOGDIR))\$* md $(strip $(COMPLOGDIR))\$*
			@(tools\make.exe -fmake\comp.mak -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1) & \
			(if ERRORLEVEL 1 \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) & \
			  (exit 1) \
			else \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) \
		)
  endif

else
#XGC

  ifeq ($(strip $(call Upper,$(BM_NEW))),TRUE)
			@XGConsole /command="tools\make.exe  -fmake\intermed.mak -k -r -R $(strip $(CMD_ARGU))  " /NOLOGO /profile="tools\XGConsole.xml"
  else
			@XGConsole /command="tools\make.exe  -fmake\intermed.mak -r -R $(strip $(CMD_ARGU))   " /NOLOGO /profile="tools\XGConsole.xml"
  endif
endif

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@if $*==fota \
		(@type $(strip $(COMPLOGDIR))\$*.log >> $(FOTA_LOG)) \
	else \
		@if $*==bootloader \
			(@type $(strip $(COMPLOGDIR))\$*.log >> $(BOOTLOADER_LOG)) \
		else \
			@if $*==bootloader_ext \
				(@type $(strip $(COMPLOGDIR))\$*.log >> $(BOOTLOADER_EXT_LOG)) \
			else \
				(@type $(strip $(COMPLOGDIR))\$*.log >> $(LOG))

	@perl .\tools\chk_lib_err_warn.pl $(strip $(COMPLOGDIR))\$*.log
endif

else
#LINT
	@if not exist $(COMPLINTLOGDIR)	(md $(COMPLINTLOGDIR))
	@if exist $(strip $(COMPLINTLOGDIR))\targetl.end del /F /Q $(strip $(COMPLINTLOGDIR))\targetl.end
	@if exist $(strip $(COMPLINTLOGDIR))\$*_build.log del /F /Q $(strip $(COMPLINTLOGDIR))\$*_build.log
	@if exist $(strip $(COMPLINTLOGDIR))\$*.log del /F /Q $(strip $(COMPLINTLOGDIR))\$*.log
	@tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib> $(strip $(COMPLINTLOGDIR))\$*_build.log 2>&1 
endif
	@perl -e "print '$* END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
ifneq ($(strip $(XGC)),TRUE)
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (if exist $(TARGDIR)\log\mbis\$*\*.mbis (perl tools\mbis.pl -o $(TARGDIR)\log\mbis\$*)) 
	@if exist $(TARGDIR)\log\mbis\$*\*.mbis ((del /q /f $(TARGDIR)\log\mbis\$*\*.mbis) & (rmdir /S /Q $(TARGDIR)\log\mbis\$*))
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$(@F),L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
else
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
endif #ifneq ($(strip $(MODIS_CONFIG)),TRUE)

# *************************************************************************
# Scan Target For Scanning Header Dependencies
# *************************************************************************
ifeq ($(strip $(CHECK_SCAN)),TRUE)
scan: $(COMP_DEP_LIST)
else
scan: cleandep $(COMP_DEP_LIST)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Scanning Header Dependencies finished.

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@if exist $(strip $(HEADER_TEMP)) (rd /S /Q $(strip $(HEADER_TEMP)))
endif

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cleandep:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@for /d %%i in ($(COMPSCANLIST)) do \
		(echo clean %%i.dep) & \
		(if exist $(strip $(RULESDIR))\%%i.dep (del $(strip $(RULESDIR))\%%i.dep))
# Copy plutommi header files to a temp folder to improve compiler performance.

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@if exist $(COPY_MMI_INCLUDE_FILE) (copy /Y $(COPY_MMI_INCLUDE_FILE) tools\copy_mmi_include_h.bat >NUL)
	@if exist $(strip $(HEADER_TEMP)) (del /q /f $(strip $(HEADER_TEMP))\*.*)
	@if not exist $(strip $(HEADER_TEMP)) (md $(strip $(HEADER_TEMP)))
	-@if exist tools\copy_mmi_include_h.bat (tools\copy_mmi_include_h.bat $(strip $(HEADER_TEMP)) 1>nul)
endif

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
%.dep: gencompbld
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,D,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo scan $* dependency. >> $(LOG)
	@echo scan $* dependency ...
	@if exist *.d (del /f /q *.d)
	@if exist *.via (del /f /q *.via)
	@if not exist $(strip $(RULESDIR))\$@ \
		(if not exist $(strip $(RULESDIR))\$*_dep (md $(strip $(RULESDIR))\$*_dep)) && \
		(if not exist $(strip $(COMPLOGDIR))\$*_dep md $(strip $(COMPLOGDIR))\$*_dep) && \
		(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) --no-print-directory COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))\$*_setEnv.log 2>&1) && \
		(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_dep > $(strip $(COMPLOGDIR))\$*_dep.log 2>&1) && \
		(if exist $(strip $(COMPLOGDIR))\$*_dep rd /S /Q $(strip $(COMPLOGDIR))\$*_dep) && \
		(if exist $(strip $(COMPLOGDIR))\$* rd /S /Q $(strip $(COMPLOGDIR))\$*) && \
		(if exist $(strip $(COMPLOGDIR))\$*_dep.log del /q $(strip $(COMPLOGDIR))\$*_dep.log)

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,D,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif

# *************************************************************************
# Standard "cleanall" Target
# *************************************************************************
cleanall:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cleanall START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(CUSTOMER)
   #     +-$(PROJECT)
   #        +-$(PLATFORM)r    - Dependency directory
   #        +-$(PLATFORM)o    - Object directory
   #           +-$(COMPLIST)  - Component object directory
   #           +-lib          - Component libraries directory
   # -----------------------------
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@if not exist $(BUILDDIR)  \
		md $(BUILDDIR)

	-@if not exist $(TARGDIR) \
		(md $(TARGDIR)) \
	else \
		(if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin\NUL (rd /S /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & \
		(if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(TARGNAME).elf)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(TARGNAME).lis)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(TARGNAME).sym)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(TARGNAME).htm)) & \
		(if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))

	@if exist $(strip $(COMPLOGDIR))\cksysdrv.log \
		attrib +r $(strip $(COMPLOGDIR))\cksysdrv.log

	@if not exist $(COMPLOGDIR) \
		(md $(COMPLOGDIR)) \
	else \
		(if exist $(strip $(COMPLOGDIR))\*.log (del /q $(strip $(COMPLOGDIR))\*.log))

	@if exist $(strip $(COMPLOGDIR))\cksysdrv.log \
		attrib -r $(strip $(COMPLOGDIR))\cksysdrv.log

ifeq ($(strip $(LINT)),TRUE)
	@if not exist $(COMPLINTLOGDIR) (md $(COMPLINTLOGDIR))
endif

	@if exist make\~romizing.log (copy /Y make\~romizing.log $(strip $(COMPLOGDIR))\romizing.log >NUL)
endif #ifneq ($(strip $(MODIS_CONFIG)),TRUE)

ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
   # -----------------------------
   # Remove TST database files
   # -----------------------------
	@if exist $(CODE_GEN_LST) \
		(copy /y $(CODE_GEN_LST) make\~codegenlis.tmp >NUL) & \
		(for /f %%i in ($(CODE_GEN_LST)) do \
			(if exist %%i (del %%i)) \
		) & \
		(if exist $(CODE_GEN_LST) (del $(CODE_GEN_LST)))

	@echo Cleaning directories under $(RULESDIR)
	@if exist $(strip $(RULESDIR))\*.dep del /q $(strip $(RULESDIR))\*.dep
	@if exist $(strip $(RULESDIR))\codegen_dep\*.* del /q $(strip $(RULESDIR))\codegen_dep\*.*

  # workaround for pre_gen and AAPMC
  ifneq ($(filter $(MAKECMDGOALS),new),)
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifeq ($(filter REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
    ifdef FLAVOR
    ifneq ($(strip $(FLAVOR)),NONE)
      ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(strip $(RULESDIR))\pregen_dep\flavor_conf.det attrib +r $(strip $(RULESDIR))\pregen_dep\flavor_conf.det
      else
        ifneq ($(strip $(LEVEL)),VENDOR)
        ifneq ($(strip $(wildcard make\flavor_conf.pl)),)
	@if exist $(strip $(RULESDIR))\pregen_dep\flavor_conf.det attrib +r $(strip $(RULESDIR))\pregen_dep\flavor_conf.det
        endif
        endif
      endif
    endif
    endif
    endif
    endif
  endif
	@if exist $(strip $(RULESDIR))\pregen_dep\*.* del /q $(strip $(RULESDIR))\pregen_dep\*.*
	@if exist $(strip $(RULESDIR))\pregen_dep\flavor_conf.det attrib -r $(strip $(RULESDIR))\pregen_dep\flavor_conf.det
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@if exist $(strip $(RULESDIR))\comp_dep\*.* del /q $(strip $(RULESDIR))\comp_dep\*.*
	@for /d %%i in ($(COMPLIST)) do (if exist $(strip $(OBJSDIR))\%%i \
		( \
			(echo Cleaning object files under %%i) && \
			(if exist $(strip $(OBJSDIR))\%%i\*.obj del /q $(strip $(OBJSDIR))\%%i\*.obj) && \
			(if exist $(strip $(OBJSDIR))\%%i\%%i.lib_bak del $(strip $(OBJSDIR))\%%i\%%i.lib_bak) \
		))
	@echo Cleaning lib files under $(COMPLIBDIR)
	@if exist $(strip $(COMPLIBDIR))\*.lib (del /q $(strip $(COMPLIBDIR))\*.lib)
  endif
else
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    # if $module.det does not exist, delete $module.lib to force to enter comp.mak and generate $module.det again, otherwise dependency check will not work
	@for %%i in ($(COMPLIST)) do (if not exist $(strip $(RULESDIR))\comp_dep\%%i.det if exist $(strip $(COMPLIBDIR))\%%i.lib del /q $(strip $(COMPLIBDIR))\%%i.lib)
    # if $module.dep does not exist, delete $module\*.obj to force to generate $module.dep again, otherwise dependency check will not work
	@for %%i in ($(COMPLIST)) do (if not exist $(strip $(RULESDIR))\%%i.dep if exist $(strip $(OBJSDIR))\%%i\*.obj del /q $(strip $(OBJSDIR))\%%i\*.obj)
  endif
endif
   # -----------------------------
   # Check component directories
   # -----------------------------
	@if not exist $(PROJDIR) (md $(PROJDIR))
	@if not exist $(RULESDIR) (md $(RULESDIR))
	@if not exist $(strip $(RULESDIR))\codegen_dep (md $(strip $(RULESDIR))\codegen_dep)
	@if not exist $(strip $(RULESDIR))\pregen_dep (md $(strip $(RULESDIR))\pregen_dep)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@if not exist $(OBJSDIR) (md $(OBJSDIR))
	@if not exist $(strip $(COMPLIBDIR)) (md $(COMPLIBDIR))
	@if not exist $(strip $(RULESDIR))\comp_dep (md $(strip $(RULESDIR))\comp_dep)
	@for /d %%i in ($(COMPLIST)) do \
		(if not exist $(strip $(OBJSDIR))\%%i md $(strip $(OBJSDIR))\%%i)
endif
	@perl -e "print 'cleanall END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cleanbin:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cleanbin START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\NUL (rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) (del /q $(strip $(TARGDIR))\$(strip $(BIN_FILE))))
else
	@if exist $(strip $(MODISDIR))\MoDIS\$(MODIS_MODE)$(strip $(MODIS_SUFFIX))\MoDIS.exe del $(strip $(MODISDIR))\MoDIS\$(MODIS_MODE)$(strip $(MODIS_SUFFIX))\MoDIS.exe
	@if exist $(strip $(MODISDIR))\MoDIS\$(MODIS_MODE)$(strip $(MODIS_SUFFIX))\MoDIS.exe exit 2
endif
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@if exist $(strip $(CGEN_CFG_FILE)) del /Q /F $(strip $(CGEN_CFG_FILE))
endif

	@perl -e "print 'cleanbin END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
# Standard "genlog" Target
# *************************************************************************
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(filter $(MAKECMDGOALS),new),)
    genlog: gen_infolog mmi_feature_check
  endif
  genlog: gen_infolog_modis gen_infomakelog
else
  genlog: gen_infolog gen_infomakelog mmi_feature_check
endif

genlog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'genlog START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	@if exist make\~romizing.log (copy /Y make\~romizing.log $(strip $(COMPLOGDIR))\romizing.log >NUL)
	@perl -e "print 'genlog END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Standard "cleanmod" Target
# *************************************************************************
cleanmod:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(CUSTOMER)
   #     +-$(PROJECT)
   #        +-$(PLATFORM)r    - Dependency directory
   #        +-$(PLATFORM)o    - Object directory
   #           +-$(COMPLIST)  - Component object directory
   #           +-lib          - Component libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@if not exist $(BUILDDIR) md $(BUILDDIR)

	@if not exist $(TARGDIR) \
		(md $(TARGDIR)) \
	else \
		(if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin\NUL (rd /S /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & \
		(if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(TARGNAME).elf)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(TARGNAME).lis)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(TARGNAME).sym)) & \
		(if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(TARGNAME).htm)) & \
		(if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))

	@if not exist $(COMPLOGDIR) \
		(md $(COMPLOGDIR)) \
	else \
		(for /d %%i in ($(CLEAN_MODS)) do \
			(if exist $(strip $(COMPLOGDIR))\%%i.log (del /q $(strip $(COMPLOGDIR))\%%i.log)) \
		)

	@if not exist $(PROJDIR) (md $(PROJDIR))
	@if not exist $(OBJSDIR) (md $(OBJSDIR))

   # -----------------------------
   # Check component directories
   # -----------------------------
	@for /d %%i in ($(CLEAN_MODS)) do \
		(@if not exist $(strip $(OBJSDIR))\%%i \
			(md $(strip $(OBJSDIR))\%%i) \
		else \
			(@echo Cleaning object files under %%i) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.obj (del $(strip $(OBJSDIR))\%%i\*.obj)) & \
			(@if exist $(strip $(OBJSDIR))\%%i\%%i.lib_bak (del $(strip $(OBJSDIR))\%%i\%%i.lib_bak)))


	@if not exist $(strip $(COMPLIBDIR)) \
		(md $(COMPLIBDIR)) \
	else \
		(echo Cleaning library files $(CLEAN_MODS) under $(COMPLIBDIR)) & \
		(for /d %%i in ($(CLEAN_MODS)) do \
			(if exist $(strip $(COMPLIBDIR))\%%i.lib (del /q $(strip $(COMPLIBDIR))\%%i.lib)) \
		)

ifeq ($(NEED_CLEAN_CGENLST),TRUE)
		@echo Cleaning code gen files
		@if exist $(CODE_GEN_LST) \
				(for /f %%j in ($(CODE_GEN_LST)) do \
					(if exist %%j (del %%j)) \
		)
		@if exist $(CODE_GEN_LST) (copy /y $(CODE_GEN_LST) make\~codegenlis.tmp >NUL) & (del $(CODE_GEN_LST))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

##############################################################
gen_infolog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print '$@ START TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

	@if not exist $(COMPLOGDIR) (md $(COMPLOGDIR))
	@tools\strcmpex.exe def def e make\~def.tmp $(foreach def,$(sort $(COM_DEFS_TARGET)),$(def))
	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS_TARGET),$(inc))
	@perl tools\lnitem.pl make\~def.tmp
	@perl tools\lnitem.pl make\~inc.tmp

	@(echo [ COMMON OPTION ]> $(INFOLOG)) && \
		(type make\~def.tmp >> $(INFOLOG))
	@(echo [ COMMON INCLUDE PATH ] >> $(INFOLOG)) && \
		(type make\~inc.tmp >> $(INFOLOG))

	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print '$@ END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

##############################################################
gen_infomakelog:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'gen_infomakelog START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@tools\strcmpex.exe def def e $(INFOMAKELOG) COM_DEFS = $(call sort, $(foreach def,$(COM_DEFS),$(def)))
	@tools\strcmpex.exe def def e make\~remove.tmp COMMINCDIRS = $(foreach inc,$(COMMINCDIRS),$(inc))
	@type make\~remove.tmp >> $(INFOMAKELOG)
	@perl tools\echoLongString.pl $(INFOMAKELOG) COMP_TRACE_DEFS $(COMP_TRACE_DEFS)
	@echo COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@perl tools\echoLongString.pl $(INFOMAKELOG) COMPOBJS $(COMPOBJS)
	@perl tools\echoLongString.pl $(INFOMAKELOG) CUS_REL_BASE_COMP $(CUS_REL_BASE_COMP)
	@perl tools\echoLongString5.pl $(INFOMAKELOG) XGEN_INC_DIR_ORI $(strip $(XGEN_INC_DIR_ORI))
endif
	@echo CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_PAR_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@perl tools\echoLongString5.pl $(INFOMAKELOG) XGEN_INC_DIR_ORI $(strip $(XGEN_INC_DIR_ORI))
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
	@tools\strcmpex.exe def def e make\~remove.tmp ALL_CUS_REL_PAR_SRC_COMP = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),$(CUS_REL_$(comp)_PAR_SRC_LIST))
	@type make\~remove.tmp >> $(INFOMAKELOG)
endif
	@if exist make\~remove.tmp del make\~remove.tmp
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)

ifneq ($(strip $(SWITCH_FOLDER)),)
	@echo SWITCH_FOLDER = $(strip $(SWITCH_FOLDER))>> $(INFOMAKELOG)
endif
	@echo TST_DB = $(strip $(TST_DB))>> $(INFOMAKELOG)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@perl tools\echoLongString.pl $(INFOMAKELOG) CUS_REL_OBJ_LIST $(CUS_REL_OBJ_LIST)
endif
	@perl tools\echoLongString.pl $(INFOMAKELOG) NON_REL_DIRS_LIST $(NON_REL_DIRS_LIST)
	@perl tools\echoLongString.pl $(INFOMAKELOG) NON_REL_FILES_LIST $(NON_REL_FILES_LIST)
	@echo LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@echo CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@echo VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@echo MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)
#	@echo HEADER_TEMP = $(strip $(HEADER_TEMP)) >> $(INFOMAKELOG)
#	@echo JBLENDIA_LIB = $(strip $(JBLENDIA_LIB)) >> $(INFOMAKELOG)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@echo DEBUG_MODULES = $(strip $(DEBUG_MODULES))>> $(INFOMAKELOG)
	@echo NON_DEBUG_MODULES = $(strip $(NON_DEBUG_MODULES))>> $(INFOMAKELOG)
else
	@echo MMI_VERSION = $(strip $(MMI_VERSION)) >>$(INFOMAKELOG)
	@echo MODIS_EN_LIBS = $(strip $(MODIS_EN_LIBS)) >> $(INFOMAKELOG)
	@echo MODIS_DIS_LIBS = $(strip $(MODIS_DIS_LIBS)) >> $(INFOMAKELOG)
	@echo MODIS_MTK_LIBS = $(strip $(MODIS_MTK_LIBS)) >> $(INFOMAKELOG)
	@echo MODIS_EN_OBJS = $(strip $(MODIS_EN_OBJS)) >> $(INFOMAKELOG)
	@echo CUS_MODIS_LIB = $(strip $(CUS_MODIS_LIB)) >> $(INFOMAKELOG)
	@echo MODIS_MODE = $(strip $(MODIS_MODE)) >> $(INFOMAKELOG)
	@echo MODIS_MODE_DEFAULT = $(strip $(MODIS_MODE_DEFAULT)) >> $(INFOMAKELOG)
	@echo MODIS_INCREDIBUILD = $(strip $(MODIS_INCREDIBUILD)) >> $(INFOMAKELOG)
	@echo MODIS_UESIM = $(strip $(MODIS_UESIM)) >> $(INFOMAKELOG)
	@echo MODIS_SUFFIX = $(strip $(MODIS_SUFFIX)) >> $(INFOMAKELOG)
endif

ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)
	@echo NEED_BUILD_TINY_SYSTEM = $(strip $(NEED_BUILD_TINY_SYSTEM)) >>$(INFOMAKELOG)
	@echo TS_COMPLIST = $(strip $(TS_COMPLIST)) >>$(INFOMAKELOG)
endif

	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gen_infomakelog END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

gendoc:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))

	@if exist tools\gen_doc.pl\
	   (perl tools\gen_doc.pl $(GENDOC_MODS))> $(strip $(COMPLOGDIR))\gendoc_dom.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifeq ($(strip $(ACTION)),new)
  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
done: gen_modlibtbl end send
  else
done: end send
  endif
else
done: end send
endif

end:
# -----------------------------
# Clean temporary files in make directory
# -----------------------------
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(PARTIAL_SOURCE)),TRUE)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\*.cfg (del /f /q $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(SCATTERFILE_FLASHTOOL_NAME))) \
	else \
		(if exist $(strip $(TARGDIR))\*.cfg (del /f /q $(strip $(TARGDIR))\$(SCATTERFILE_FLASHTOOL_NAME)))
else
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\*.cfg (del /f /q $(strip $(TARGDIR))\$(SCATTERFILE_FLASHTOOL_NAME)*.*)) \
	else \
		(if exist $(strip $(TARGDIR))\*.cfg (del /f /q $(strip $(TARGDIR))\$(SCATTERFILE_FLASHTOOL_NAME)*.*))
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
ifneq ($(strip $(FEATURE_OVERLOAD)),TRUE)
	@echo check system drive ....
	@if exist $(strip $(COMPLOGDIR))\ckSysDrv.log \
		(@perl -e "open F,'<$(strip $(COMPLOGDIR))\ckSysDrv.log';my $$backup=$$/;undef $$/;my $$reading=<F>;close F;if($$reading =~ /Shortage/i){print 'cksysdrv has errors. Delete the binary file.'.\"\n\";system('del /S /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE))');exit 1;};")
endif
endif
endif
endif
endif
ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
	@if not exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) \
		(echo $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) does not exist. Please check it. & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\NUL \
		(rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(del /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		exit 1)
	@if not exist $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE)) \
		(echo $(strip $(TARGDIR))\$(strip $(BTLD_EXT_BIN_FILE)) does not exist. Please check it. & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\NUL \
		(rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(del /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		exit 1)
endif
ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
	@if not exist $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) \
		(echo $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) does not exist. Please check it. & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\NUL \
		(rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(del /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		exit 1)
  endif
endif
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if exist $(strip $(TARGDIR))\~$(strip $(BIN_FILE)) \
		del /Q /F $(strip $(TARGDIR))\~$(strip $(BIN_FILE))
	@echo Check if any error happened during the build process .....
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		@perl tools\parse_comp_err.pl $(strip $(CUSTOMER)) $(MODIS_CONFIG)
	@if exist $(strip $(FIXPATH))\comp_err.txt \
		if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
			(@perl -e "open F,'<$(strip $(FIXPATH))\comp_err.txt';my $$backup=$$/;undef $$/;my $$reading=<F>;close F;if($$reading =~ /might be failed/i){print 'Some error happened during the build process. Delete the binary file.'.\"\n\";system('move /Y $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(TARGDIR))\~$(strip $(BIN_FILE))');exit 1;};")
endif

# Clean all debug and original dsp bin files 
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
	@if exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" \
		rename $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" "$(strip $(DUALMACDSP_BIN)).bin.bak"
	@if exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" \
		rename $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" "$(strip $(DUALMACDSP_BL_BIN)).bin.bak"
	@if exist $(FIXPATH)\dsp_bin\*DBG*.bin (del $(FIXPATH)\dsp_bin\*DBG*.bin)
	@if exist $(FIXPATH)\dsp_bin\*ORG*.bin (del $(FIXPATH)\dsp_bin\*ORG*.bin)
	@if exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin.bak" \
		rename $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin.bak" "$(strip $(DUALMACDSP_BIN)).bin"	
	@if exist $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin.bak" \
		rename $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin.bak" "$(strip $(DUALMACDSP_BL_BIN)).bin"	
endif

# -----------------------------
# remove dep and via folders under build folder
# -----------------------------
	@if exist $(strip $(TARGDIR))\dep (rd /S /Q $(strip $(TARGDIR))\dep)
	@if exist $(strip $(TARGDIR))\via (rd /S /Q $(strip $(TARGDIR))\via)

	@echo Cleaning make\~*.tmp files ...
	@if exist make\~*.tmp \
		del make\~*.tmp
	@if exist $(strip $(HEADER_TEMP)) (rmdir /S /Q $(strip $(HEADER_TEMP)))
	@echo Done.
	@perl tools\time.pl -n
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

send:
ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	-perl tools\packbin.pl $(strip $(TARGDIR)) $(strip $(TST_DB))
  ifeq ($(strip $(SEND_FILE)),TRUE)
    ifeq ($(strip $(FLAVOR)),NONE)
			@echo tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))"
			@tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))"
    else
			@echo tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))($(strip $(FLAVOR)))"
			@tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))($(strip $(FLAVOR)))"
    endif
  else
    ifneq ($(strip $(NOT_SEND_FILE_BY_DEFAULT)),TRUE)
      ifeq ($(strip $(FLAVOR)),NONE)
				@echo tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))"
				@tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))"
      else
				@echo tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))($(strip $(FLAVOR)))"
				@tools\sender.exe -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(CUSTOMER))_$(strip $(PROJECT))($(strip $(FLAVOR)))"
      endif
    endif
  endif
endif

ckmake: ckfactorybin ckswitchfeature
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ckmake START TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
	perl tools\chk_verno.pl $(VERNO)
	@if not exist $(strip $(COMPLOGDIR)) (md $(strip $(COMPLOGDIR)))
	@perl tools\chk_feature_option.pl $(strip $(THE_MF)) $(strip $(CUSTOMER)) > $(strip $(COMPLOGDIR))\chk_feature_option.log
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
		perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -internal $(CUSTOMER)
  else
		perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -customer $(CUSTOMER)
  endif
else
	perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -internal $(CUSTOMER)
endif

#	perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -build
	@echo makefile check is done

	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ckmake END TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ckswitchfeature:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist tools\GLBOptionSwtichRef\$(subst make\,,$(strip $(THE_MF))) \
		(@perl tools\SpecialDepChk.pl $(strip $(THE_MF)) tools\GLBOptionSwtichRef\$(subst make\,,$(strip $(THE_MF))) tools\GLBOptionSwtichRef\ChkSpecialFeatures.lis) & \
		(if ERRORLEVEL 1 echo Error: some feature options can NOT be switched in custom release code base!!!) \
	else \
		(@echo warning: tools\GLBOptionSwtichRef\$(subst make\,,$(strip $(THE_MF))) does NOT exist, skip off special dependency check!!!)
endif
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ckfactorybin:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(SPLIT_BINARY_SUPPORT)),FACTORY_COMBINE)
	@echo Checking FACTORY bin files exist or not...
	@perl tools\ckFactoryBin.pl $(CUSTOMER) $(strip $(FACTORY_BIN_FOLDER))> $(strip $(COMPLOGDIR))\ckfactorybin.log
endif
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ck3rdptylic:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ck3rdptylic START TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
    ifeq ($(strip $(call Upper,$(PARTIAL_SOURCE))),TRUE)
			@echo Skip 3rd party feature license check for RD3 ODB!!!
    else
			@if exist tools\Feat2Mod.ini \
				(@perl tools\3rdPartiesLicChk.pl $(strip $(THE_MF)) "" tools\Feat2Mod.ini "$(strip $(CUS_REL_SRC_COMP))" "$(strip $(CUS_REL_PAR_SRC_COMP))" "$(strip $(CUS_REL_MTK_COMP))") \
			else \
				(@echo warning:  tools\Feat2Mod.ini does NOT exist, skip 3rd party feature's srouce release level license check!!!) & \
				(@perl tools\3rdPartiesLicChk.pl $(strip $(THE_MF)) "")
    endif
  else
		@echo Skip 3rd party feature license check for internal demo projects!!!
  endif
else
	@echo Skip 3rd party feature license check for custom release projects!!!
endif

	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ck3rdptylic END TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

copylintlog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(LINT)),TRUE)      
	@copy /y $(COMPLINTLOGDIR)\*.log mtk_tools\lint_cfg >NUL
	@if exist mtk_tools\lint_cfg\*_build.log del /F /Q  mtk_tools\lint_cfg\*_build.log
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

genlintstatlog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(LINT)),TRUE)      
	@$(foreach alintlog,$(LINTLOGFILE),$(shell  cd mtk_tools\lint_cfg & perl lint_stats_by_team.pl  $(alintlog)  & cd ..\.. ))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

## check_repeated_include_path
#################### begin to check repeated common include path ############
crip : 
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl tools\check_repeated.pl $(COMMINCDIRS)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
###################### end ##############

ckmemcons:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist tools\GetMemCons.pl \
		(perl tools\GetMemCons.pl $(strip $(TARGDIR))\$(strip $(LIS_FILE)) tools\prebuild_backup\$(basename $(strip $(LIS_FILE)))_bak.lis $(strip $(COMPLOGDIR))\mem_cons.log $(strip $(COMPILER)))
	@echo Check memory consumption done!
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
backup : getoptions
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist tools\prebuild_backup \
		md tools\prebuild_backup
	@if exist $(strip $(TARGDIR))\$(strip $(LIS_FILE)) \
	   (copy /y $(strip $(TARGDIR))\$(strip $(LIS_FILE)) tools\prebuild_backup\$(basename $(strip $(LIS_FILE)))_bak.lis > nul)
	@if exist $(strip $(COMPLOGDIR))\auto_adjust_mem.log (del /Q /F $(strip $(COMPLOGDIR))\auto_adjust_mem.log)
	@if exist $(strip $(COMPLOGDIR))\aapmc_info.log (del /Q /F $(strip $(COMPLOGDIR))\aapmc_info.log)
	@if exist $(strip $(COMPLOGDIR))\ckImgSize_postbuild.log (del /Q /F $(strip $(COMPLOGDIR))\ckImgSize_postbuild.log)
	@if exist $(strip $(TARGDIR))\VIVA_DEBUG (rd /S /Q $(strip $(TARGDIR))\VIVA_DEBUG)
	@if exist $(strip $(TARGDIR))\DEMAND_PAGING_DEBUG (rd /S /Q $(strip $(TARGDIR))\DEMAND_PAGING_DEBUG)
	@if exist $(strip $(TARGDIR))\FILE_SYSTEM_DEBUG (rd /S /Q $(strip $(TARGDIR))\FILE_SYSTEM_DEBUG)
	@if exist $(strip $(TARGDIR))\BOOTLOADER_DEBUG (rd /S /Q $(strip $(TARGDIR))\BOOTLOADER_DEBUG)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
else
backup:
endif

getoptions:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" \
		(@perl -e "print 'CFLAGS,$(CFLAGS)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG) &\
		@perl -e "print 'CPLUSFLAGS,$(CPLUSFLAGS)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG)  &\
		@perl -e "print 'LIBOPT,$(LIBOPT)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG)  &\
		@perl -e "print 'LNKOPT,$(LNKOPT)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG))

	@tools\strcmpex.exe def def e make\~mbis_def.tmp $(foreach def,$(COM_DEFS),$(def))

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" \
		(@perl -e "print 'COM_DEFS,'";>>$(MBIS_BUILD_INFO_LOG) &\
		@type make\~mbis_def.tmp >>$(MBIS_BUILD_INFO_LOG))

	@if exist make\~mbis_def.tmp del /Q /F make\~mbis_def.tmp

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

elfpatch:
	@echo $(strip $(TARGDIR))\$(IMG_FILE)!!
	@if exist $(strip $(TARGDIR))\$(IMG_FILE) \
	(@echo elfpatcher start....) &\
	(@tools\elfpatcher.exe $(strip $(TARGDIR))\$(IMG_FILE)) &\
	(@echo elfpatcher done!) \
	else \
	(@echo $(strip $(TARGDIR))\$(IMG_FILE) is not existed!Please build firstly!)

gencompbld: gen_gfh_cfg
   # -----------------------------
   # Write required script variables to config file
   # -----------------------------
	@echo CUS_REL_SRC_COMP = $(strip $(CUS_REL_SRC_COMP)) > make\~sub_compbld.tmp
	@echo FIXPATH 	= $(strip $(FIXPATH))>  make\~compbld.tmp
	@echo OBJSDIR  = $(strip $(OBJSDIR))>> make\~compbld.tmp
	@echo RULESDIR	= $(strip $(RULESDIR))>> make\~compbld.tmp
	@echo TARGDIR 	= $(strip $(TARGDIR))>> make\~compbld.tmp
	@echo PROJDIR 	= $(strip $(PROJDIR))>> make\~compbld.tmp
   # mbis time probe for enable msib time probe in comp.mak
ifneq ($(strip $(XGC)),TRUE)
	@echo MBIS_EN_OBJ_LOG 	= $(strip $(MBIS_EN_OBJ_LOG))>>  make\~compbld.tmp
else
	@echo MBIS_EN_OBJ_LOG 	= FALSE>>  make\~compbld.tmp
endif

ifeq ($(strip $(LINT)),TRUE)
	@echo COMPLINTLOGDIR	= $(strip $(COMPLINTLOGDIR))>> make\~compbld.tmp
endif
	@echo PLATFORM = $(strip $(call Upper,$(PLATFORM)))>> make\~compbld.tmp
	@echo BOARD_VER = $(strip $(call Upper,$(BOARD_VER)))>> make\~compbld.tmp
	@echo CHIP_VER = $(strip $(call Upper,$(CHIP_VER)))>> make\~compbld.tmp
	@echo MCU_DCM = $(strip $(call Upper,$(MCU_DCM)))>> make\~compbld.tmp
	@echo DEBUG_SAVE_CUR_THREAD	= $(strip $(DEBUG_SAVE_CUR_THREAD))>> make\~compbld.tmp
	@echo PRODUCTION_RELEASE   	= $(strip $(PRODUCTION_RELEASE))>> make\~compbld.tmp
	@echo APCSINT 	= $(strip $(APCSINT))>> make\~compbld.tmp
	@echo ASM = $(strip $(ASM))>> make\~compbld.tmp
	@echo LIB     	= $(strip $(LIB))>> make\~compbld.tmp
	@echo CC	    	= $(strip $(CC))>> make\~compbld.tmp
	@echo CC32	 	= $(strip $(CC32))>> make\~compbld.tmp
	@echo CPPC	    	= $(strip $(CPPC))>> make\~compbld.tmp
	@echo CPPC32	 	= $(strip $(CPPC32))>> make\~compbld.tmp
	@echo CFLAGS 	= $(strip $(CFLAGS))>> make\~compbld.tmp
	@echo CPLUSFLAGS = $(strip $(CPLUSFLAGS))>> make\~compbld.tmp
	@echo VIA = $(strip $(VIA))>> make\~compbld.tmp
	@echo SW_BINDING_SUPPORT    = $(strip $(SW_BINDING_SUPPORT))>> make\~compbld.tmp
	@echo RTOS    = $(strip $(RTOS))>> make\~compbld.tmp
	@echo CUS_MTK_LIB    = $(strip $(CUS_MTK_LIB))>> make\~compbld.tmp
	@echo FOTA_ENABLE    = $(strip $(FOTA_ENABLE))>> make\~compbld.tmp
	@echo LCD_MODULE    = $(strip $(LCD_MODULE))>> make\~compbld.tmp
	@echo JPG_DECODE = $(strip $(JPG_DECODE))>> make\~compbld.tmp
	@echo JPG_ENCODE = $(strip $(JPG_ENCODE))>> make\~compbld.tmp
	@echo CHIP_VERSION_CHECK = $(strip $(CHIP_VERSION_CHECK))>> make\~compbld.tmp
	@echo KEYPAD_DEBUG_TRACE = $(strip $(KEYPAD_DEBUG_TRACE))>> make\~compbld.tmp
	@echo NEED_BUILD_BOOTLOADER = $(strip $(NEED_BUILD_BOOTLOADER))>> make\~compbld.tmp
	@echo FLASH_TEST_SELECT = $(strip $(FLASH_TEST_SELECT))>> make\~compbld.tmp
	@echo FLAVOR = $(strip $(FLAVOR))>> make\~compbld.tmp
	@echo MMI_VERSION = $(strip $(MMI_VERSION))>> make\~compbld.tmp
	@echo ZIMAGE_SUPPORT = $(strip $(ZIMAGE_SUPPORT))>> make\~compbld.tmp

	@echo CARD_DOWNLOAD_SUPPORT_PLATFORM = $(strip $(CARD_DOWNLOAD_SUPPORT_PLATFORM))>> make\~compbld.tmp
	@echo CARD_DOWNLOAD = $(strip $(CARD_DOWNLOAD))>> make\~compbld.tmp
	@echo L1_TDD128 = $(strip $(L1_TDD128))>> make\~compbld.tmp
	@echo ENABLE_PARTIAL_TRACE = $(strip $(ENABLE_PARTIAL_TRACE))>> make\~compbld.tmp
	@echo PARTIAL_TRACE_LIB = $(strip $(PARTIAL_TRACE_LIB))>> make\~compbld.tmp
	@echo CUS_MTK_LIB_TRACE = $(strip $(CUS_MTK_LIB_TRACE))>> make\~compbld.tmp
	@echo VFP_OPTION = $(strip $(VFP_OPTION))>> make\~compbld.tmp
	@echo VFP_OPTION_SOFT = $(strip $(VFP_OPTION_SOFT))>> make\~compbld.tmp
	@echo COM_DEFS_FOR_$(strip $(PLATFORM)) = $(strip $(COM_DEFS_FOR_$(strip $(PLATFORM))))>> make\~compbld.tmp
	@echo CLEANROOM_COMP = $(strip $(CLEANROOM_COMP))>> make\~compbld.tmp
	@echo CLEANROOM_CFLAGS = $(strip $(CLEANROOM_CFLAGS))>> make\~compbld.tmp

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) >> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
	else \
		(echo AFLAGS	= $(strip $(AFLAGS)) >> make\~compbld.tmp)

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_LPSDRAM_MCP"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp))))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "LPSDRAM"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_LPSDRAM_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_LPSDRAM_ SETL {TRUE}">> make\~compbld.tmp))))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_RAM_MCP"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_NOR_RAM_MCP_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_RAM_MCP_ SETL {TRUE}">> make\~compbld.tmp))))
else
	@echo AFLAGS = $(strip $(AFLAGS))>> make\~compbld.tmp

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_LPSDRAM_MCP"   \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp)))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "LPSDRAM"   \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_LPSDRAM_ SETL {TRUE}">> make\~compbld.tmp)))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_RAM_MCP"   \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_RAM_MCP_ SETL {TRUE}">> make\~compbld.tmp)))
endif

	@echo SWDBG_SUPPORT = $(strip $(SWDBG_SUPPORT))>> make\~compbld.tmp
	@echo NAND_FLASH_BOOTING = $(strip $(NAND_FLASH_BOOTING))>> make\~compbld.tmp
	@echo EMMC_BOOTING = $(strip $(EMMC_BOOTING))>> make\~compbld.tmp
	@echo SECURE_SUPPORT = $(strip $(SECURE_SUPPORT))>> make\~compbld.tmp
	@echo ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = $(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT))>> make\~compbld.tmp
	@echo USB_DOWNLOAD_IN_BL   = $(strip $(USB_DOWNLOAD_IN_BL))>> make\~compbld.tmp
	@echo L1_WCDMA = $(strip $(L1_WCDMA))>> make\~compbld.tmp
	@echo L1_3GSOLUTION = $(strip $(L1_3GSOLUTION))>> make\~compbld.tmp
	@echo BM_NEW = $(strip $(BM_NEW))>> make\~compbld.tmp
	@echo DSP_SOLUTION = $(strip $(DSP_SOLUTION))>> make\~compbld.tmp
	@echo SV5_PLATFORM = $(strip $(SV5_PLATFORM))>> make\~compbld.tmp
	@echo SW_BINDING_SUPPORT = $(strip $(SW_BINDING_SUPPORT))>> make\~compbld.tmp
	@echo KAL_RECORD_BOOTUP_LOG = $(strip $(KAL_RECORD_BOOTUP_LOG))>> make\~compbld.tmp

ifeq ($(strip $(LINT)),TRUE)
	@if not exist $(COMPLINTLOGDIR) (md $(COMPLINTLOGDIR))
	@if exist $(strip $(COMPLINTLOGDIR))\lint.cfg del /F /Q $(strip $(COMPLINTLOGDIR))\lint.cfg
	@perl tools\SetLintEnv.pl $(strip $(COMPLINTLOGDIR))\lint.cfg $(COMPLINTLOGDIR) $*
endif

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  INCDIRS  = $(strip $(HEADER_TEMP)) $(strip $(COMMINCDIRS))
else
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  INCDIRS  = $(strip $(COMMINCDIRS))
endif

	@type make\~compbld_2.tmp >> make\~compbld.tmp
	@if exist make\~compbld_2.tmp del  make\~compbld_2.tmp
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  DEFINES  = $(strip $(COM_DEFS))
	@type make\~compbld_2.tmp >> make\~compbld.tmp
	@if exist make\~compbld_2.tmp del  make\~compbld_2.tmp
	@echo MMIDIR   = $(strip $(MMIDIR))>> make\~compbld.tmp
	@echo MMI_BASE   = $(strip $(MMI_BASE))>> make\~compbld.tmp
	@echo RF_MODULE   = $(strip $(RF_MODULE))>> make\~compbld.tmp
	@echo PROJECT   = $(strip $(PROJECT))>> make\~compbld.tmp
	@echo THE_MF   = $(strip $(THE_MF))>> make\~compbld.tmp
	@echo ARM9_PLATFORM   = $(strip $(ARM9_PLATFORM))>> make\~compbld.tmp
	@echo ARM11_PLATFORM   = $(strip $(ARM11_PLATFORM))>> make\~compbld.tmp
	@if not %0$(COMPILER)==%0 echo COMPILER = $(COMPILER)>> make\~compbld.tmp
	@if not %0$(RVCT_MULTI_FILE)==%0 echo RVCT_MULTI_FILE = $(RVCT_MULTI_FILE)>> make\~compbld.tmp
	@if not %0$(HEADER_TEMP)==%0 echo HEADER_TEMP = $(strip $(HEADER_TEMP)) >> make\~compbld.tmp
	@echo AUTO_MERGE_PTH = $(AUTO_MERGE_PTH)>> make\~compbld.tmp

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@if exist $(FIXPATH)\make\$*\master echo MASTER = TRUE>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\master echo MASTER = TRUE
	@if exist $(FIXPATH)\make\$*\slave echo SLAVE = TRUE>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\slave echo SLAVE = TRUE
endif

ifdef DUAL_MODE_SUPPORT
	@echo DUAL_MODE_SUPPORT = $(strip $(DUAL_MODE_SUPPORT))>> make\~compbld.tmp
endif

ifdef SMART_PHONE_CORE
ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
	@echo SMART_PHONE_CORE = $(strip $(SMART_PHONE_CORE))>> make\~compbld.tmp
endif
endif
	@echo ACTION = $(strip $(ACTION))>> make\~compbld.tmp
	@echo COMPLOGDIR = $(strip $(COMPLOGDIR))>> make\~compbld.tmp
	@echo DEBUG_MODULES = $(strip $(DEBUG_MODULES)) >> make\~compbld.tmp
	@echo NON_DEBUG_MODULES = $(strip $(NON_DEBUG_MODULES)) >> make\~compbld.tmp
	@echo CUS_REL_PAR_SRC_COMP = $(strip $(CUS_REL_PAR_SRC_COMP)) >> make\~compbld.tmp

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@echo MODIS_CONFIG = $(strip $(MODIS_CONFIG))>> make\~compbld.tmp
	@echo MODIS_DIS_OPTION = $(strip $(MODIS_DIS_OPTION)) >> make\~compbld.tmp
	@echo MODIS_UESIM = $(strip $(MODIS_UESIM)) >> make\~compbld.tmp
	@echo MODIS_SUFFIX = $(strip $(MODIS_SUFFIX)) >> make\~compbld.tmp
endif
	@echo AUTO_CHECK_DEPEND = $(strip $(AUTO_CHECK_DEPEND)) >>make\~compbld.tmp

ifdef NO_PCIBT
  ifeq ($(strip $(NO_PCIBT)),TRUE)
		@echo NO_PCIBT = TRUE>> make\~compbld.tmp
  endif
endif

ifeq ($(strip $(NEED_BUILD_TINY_SYSTEM)),TRUE)	
	@echo NEED_BUILD_TINY_SYSTEM= $(strip $(NEED_BUILD_TINY_SYSTEM))>> make\~compbld.tmp
	@echo TS_COMPLIST = $(strip $(TS_COMPLIST))>> make\~compbld.tmp	
	@echo TS_INCDIRS = $(strip $(TS_COMMINCDIRS))>> make\~compbld.tmp
endif

# *************************************************************************
#  ximgen for CardDownload
# *************************************************************************
ximgen:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Start to execute ximgen
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(perl $(FIXPATH)\tools\cfgGen.pl 2 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) $(strip $(FOTA_BIN_FILE)) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE) "$(CC)" "$(VIA)" make\~customIncDef.tmp "$(strip $(NET_PATH))" > $(strip $(COMPLOGDIR))\ximgen_1.log)

	@if exist $(strip $(FIXPATH))\tools\CardDownload\ximgen.bat \
	($(strip $(FIXPATH))\tools\CardDownload\ximgen.bat $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\IM_Maker.ini $(strip $(TARGDIR)) $(strip $(CUSTOMER))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO)) $(strip $(EMPTY_RESOURCE)) > $(strip $(COMPLOGDIR))\ximgen.log) & \
	(if ERRORLEVEL 1 \
		(@echo ximgen ERROR!! Please check $(strip $(COMPLOGDIR))\ximgen.log) & \
	(exit 1) \
	else \
		(@echo ximgen is done) )
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  iotgen for IOT FOTA
# *************************************************************************
iotgen:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Start to execute iotgen

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(perl $(FIXPATH)\tools\cfgGen.pl 2 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) $(strip $(FOTA_BIN_FILE)) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE) "$(CC)" "$(VIA)" make\~customIncDef.tmp "$(strip $(NET_PATH))" > $(strip $(COMPLOGDIR))\$@_1.log) & \
		(if ERRORLEVEL 1 (echo Error: Failed in cfgGen.pl at $@. Please check $(strip $(COMPLOGDIR))\$@_1.log & exit 1))

	@if exist $(strip $(FIXPATH))\tools\IOTFota\iot_image_gen.bat \
		($(strip $(FIXPATH))\tools\IOTFota\iot_image_gen.bat $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\IM_Maker.ini $(strip $(TARGDIR)) $(strip $(CUSTOMER))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO)) $(strip $(EMPTY_RESOURCE)) > $(strip $(COMPLOGDIR))\$@.log) & \
		(if ERRORLEVEL 1 \
			(echo Error: Failed in iot_image_gen.bat at $@. Please check $(strip $(COMPLOGDIR))\$@.log & exit 1) \
		else \
			(@echo $@ is done) )
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  gen module ID and library table for databse trace information
# *************************************************************************
gen_modlibtbl:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(ACTION)),new)
	@tools\make.exe -fmake\gsm2.mak -r -R CHECK_SCAN=TRUE scan
endif
	@echo Generate a table for module ID and library...
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@(tools\ModLibTbl.exe -log-$(strip $(COMPLOGDIR)) -dep-$(strip $(RULESDIR)) -out-$(strip $(TST_DB))\custom_databaseinfo.csv  > $(strip $(COMPLOGDIR))\gen_modlibtbl.log 2>&1)& \
	(if ERRORLEVEL 1 (@echo gen_modlibtbl ERROR!! Please check $(strip $(COMPLOGDIR))\gen_modlibtbl.log & exit 1))
else
	@(tools\ModLibTbl.exe -log-$(strip $(COMPLOGDIR)) -dep-$(strip $(RULESDIR)) -out-$(strip $(TST_DB))\MTK_databaseinfo.csv  > $(strip $(COMPLOGDIR))\gen_modlibtbl.log 2>&1)& \
	(if ERRORLEVEL 1 (@echo gen_modlibtbl ERROR!! Please check $(strip $(COMPLOGDIR))\gen_modlibtbl.log & exit 1))
endif
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

gen_gfh_cfg:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo PROJECT_NAME = $(strip $(CUSTOMER))>make\~gfh_cfg.tmp
	@echo PLATFORM_ID = $(strip $(BIN_FILE))>>make\~gfh_cfg.tmp
	@echo PROJECT_ID = $(strip $(VERNO))>>make\~gfh_cfg.tmp
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# *****************************************************************************************************
# TARGET: gen_concatenate_proj
# concatenate the project makefiles
# Notice: the PROJECT_MAKEFILE should be the original project makefile in make folder. ext: make/XXX.mak
# *****************************************************************************************************
CONCATENATE_PROJ_MAK := $(strip $(TARGDIR))\_$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
ORIGINAL_PROJ_MAK    := make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak

gen_concatenate_proj:  $(strip $(CONCATENATE_PROJ_MAK))

# *****************************************************************************************************
# TARGET: $(CONCATENATE_PROJ_MAK)
# concatenate the project makefiles and the result is placed on build/$project/$flavor/bin
# Notice: the PROJECT_MAKEFILE should be the original project makefile in make folder. ext: make/XXX.mak
# *****************************************************************************************************
$(CONCATENATE_PROJ_MAK): $(strip $(ORIGINAL_PROJ_MAK)) tools\cat_proj_mak.pl
ifdef PROJECT_MAKEFILE_EXT
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),)
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),NONE)
$(CONCATENATE_PROJ_MAK): make/custom_config/$(strip $(PROJECT_MAKEFILE_EXT)).mak
  endif
  endif
endif

# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(TARGDIR) md $(TARGDIR)
	@perl tools\cat_proj_mak.pl "$(strip $(ORIGINAL_PROJ_MAK))" "$(strip $(CONCATENATE_PROJ_MAK))" > $(strip $(COMPLOGDIR))\gen_concatenate_proj.log 2>&1 & \
		(if ERRORLEVEL 1 \
			(if exist $(strip $(CONCATENATE_PROJ_MAK)) (del /q $(strip $(CONCATENATE_PROJ_MAK)))) && \
			(echo Error: concatenate project makefiles failed. Please check $(strip $(COMPLOGDIR))\gen_concatenate_proj.log) & \
		(exit 1))

# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

###############################
# Begin of MoDIS only actions #
###############################
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
include make\modisBuild.mak
endif #ifeq ($(strip $(MODIS_CONFIG)),TRUE)
#############################
# End of MoDIS only actions #
#############################

# FORCE is a phony target, any target depending on it will run forcely
FORCE:

