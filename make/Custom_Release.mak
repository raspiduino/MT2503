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
# *************************************************************************
# Common macro definitions
# *************************************************************************

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .ptr .h

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : custom_release base hdr_comp src_comp par_src_comp mtk_comp files_list obj_list filter_out done ckcr devapp_res ck3rdptylic non_rel_files_list non_rel_dirs_list partial_copy gen_custom_dep codegen_rel nvramautogen_rel ck_dep_files gen_dbinfo resgen_rel check_obj

# *************************************************************************
# MediaTek is the default CUSTOMER.
# *************************************************************************

# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
# Global Variable for custom release process
# *************************************************************************
CUSREL_PROCESS = TRUE

# -----------------------------
#  Include scripts
# -----------------------------
# Build option definitons
include make\option.mak

CUSTOM_RELEASE_ORG := $(CUSTOM_RELEASE)
CUSTOM_RELEASE := TRUE
include make\modisConfig.mak
CUSTOM_RELEASE := $(CUSTOM_RELEASE_ORG)

ifndef MBIS_PC_TIME_TMP
  MBIS_PC_TIME_TMP = tmp
endif

# Partial Copy Initial Comp
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
  # path assign with absolute path
  RELEASE_DIR_O = $(strip $(PC_FOLDER))
  RELEASE_DIR = $(strip $(PC_FOLDER))
  FIXPATH = $(strip $(FS_FOLDER))
  # CUS_REL_SRC_COMP from RD cp_cfg.ini
  $(shell tools\strcmpex.exe trcdef trcdef e make\~org_src_comp.bak $(foreach comp,$(CUS_REL_SRC_COMP),$(comp)))
  $(shell mtk_tools\PartialCopy\comp_cleanup.pl -s $(PC_FOLDER) make\~curcomp.tmp $(PC_SRC_COMP))
  CUS_REL_SRC_COMP =  $(shell type $(RELEASE_DIR)\make\~result_src_comp.tmp)

  # CUS_REL_BASE_COMP is from $(CUS_REL_BASE_COMP) and comp_cleanup.pl
  ifeq ($(strip $(MODIS_EN)),TRUE)
    ifeq ($(strip $(MODIS_ON_VC9)),TRUE)
      $(shell mtk_tools\PartialCopy\comp_cleanup.pl -b TRUE TRUE $(PC_FOLDER) $(CUS_REL_BASE_COMP))
      $(shell mtk_tools\PartialCopy\comp_cleanup.pl -f TRUE TRUE $(PC_FOLDER) $(CUS_REL_FILES_LIST))
    else
      $(shell mtk_tools\PartialCopy\comp_cleanup.pl -b TRUE FALSE $(PC_FOLDER) $(CUS_REL_BASE_COMP))
      $(shell mtk_tools\PartialCopy\comp_cleanup.pl -f TRUE FALSE $(PC_FOLDER) $(CUS_REL_FILES_LIST))
    endif
  else
      $(shell mtk_tools\PartialCopy\comp_cleanup.pl -b FALSE TRUE $(PC_FOLDER) $(CUS_REL_BASE_COMP))
      $(shell mtk_tools\PartialCopy\comp_cleanup.pl -f FALSE TRUE $(PC_FOLDER) $(CUS_REL_FILES_LIST))
  endif  
  CUS_REL_BASE_COMP =  $(strip $(shell type $(RELEASE_DIR)\make\~result_base_comp.tmp))
  CUS_REL_FILES_LIST = $(strip $(shell type $(RELEASE_DIR)\make\~result_file_comp.tmp))

  # CUS_REL_SRC_COMP is $(COMPLIST) - $(CUS_REL_SRC_COMP)
  CUS_REL_MTK_COMP = $(filter-out $(CUS_REL_SRC_COMP),$(COMPLIST))

  # Partial Copy do not support CUS_REL_PAR_SRC_COMP
  CUS_REL_PAR_SRC_COMP = 
  
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
  
  NEED_TRANS_UMTS = FALSE
  ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
    NEED_TRANS_UMTS = TRUE
  endif

  # Do component module name parsing according to different project combination
  # For example, in classb solution, l1 -> l1_classb instead l1,
  # but l1_classb should be accepted, too.
  ifeq ($(NEED_TRANS_CLASSB),TRUE)
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l1,$(comp)),$(comp),l1_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out rr,$(comp)),$(comp),rr_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out mm,$(comp)),$(comp),mm_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l4,$(comp)),$(comp),l4_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out peer,$(comp)),$(comp),peer_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out interface,$(comp)),$(comp),interface_classb))
    ifneq ($(strip $(L1_WCDMA)),TRUE)
      CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l1_classb,$(comp)),$(comp),l1_classb_g2))
      CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out rr_classb,$(comp)),$(comp),rr_classb2))
      CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out mm_classb,$(comp)),$(comp),mm_classb2))
    endif
  else
    ifeq ($(NEED_TRANS_UMTS),FALSE)
      ifneq ($(strip $(L1_WCDMA)),TRUE)
        CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l1,$(comp)),$(comp),l1_g2))
        CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out rr,$(comp)),$(comp),rr2))
        CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out mm,$(comp)),$(comp),mm2))
      endif
    endif
  endif
  
  ifeq ($(NEED_TRANS_UMTS),TRUE)
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l1,$(comp)),$(comp),l1_classb_umts))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out rr,$(comp)),$(comp),rr_classb_umts))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out mm,$(comp)),$(comp),mm_classb_umts))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l1_classb,$(comp)),$(comp),l1_classb_umts))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out rr_classb,$(comp)),$(comp),rr_classb_umts))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out mm_classb,$(comp)),$(comp),mm_classb_umts))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out l4,$(comp)),$(comp),l4_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out peer,$(comp)),$(comp),peer_classb))
    CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out interface,$(comp)),$(comp),interface_classb))
  endif
  
  ifdef SIM_NEW_ARCH
    ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
      CUS_REL_SRC_COMP := $(foreach comp,$(CUS_REL_SRC_COMP),$(if $(filter-out sim,$(comp)),$(comp),sim2))
    endif
  endif

  WORK_DIR = $(strip $(PC_FOLDER))
else
  WORK_DIR = $(strip $(FIXPATH))
endif

# Partial Copy do not need to check 
ifneq ($(strip $(PARTIAL_COPY)),TRUE)
# Change relative paths to positive paths.
$(shell if not exist $(strip $(RELEASE_DIR_O)) (md "$(strip $(RELEASE_DIR_O))" > nul ))
$(shell if not exist $(strip $(RELEASE_DIR_O))\flag.tmp (copy /y nul "$(strip $(RELEASE_DIR_O))"\flag.tmp > nul ))
REL_DIR = $(shell dir $(strip $(RELEASE_DIR_O))\flag.tmp /b)

ifneq ($(words $(REL_DIR)),1)
  $(error $(RELEASE_DIR_O) does NOT exist)
endif

ifdef DSP_SOLUTION
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    ifeq ($(words $(DSP_DB_FILE)),0)
      $(error DSP database file $(DSP_DB_FILE_PREFIX)* does NOT exist)
    endif
  endif
endif

CODEBASE = $(shell cd)
RELEASE_DIR := $(CODEBASE)\$(RELEASE_DIR_O)
REL_DIR_2 = $(shell dir $(strip $(RELEASE_DIR))\flag.tmp /b)
ifneq ($(words $(REL_DIR_2)),1)
RELEASE_DIR := $(RELEASE_DIR_O)
endif
$(shell if exist $(strip $(RELEASE_DIR_O))\flag.tmp (del /Q $(strip $(RELEASE_DIR_O))\flag.tmp > nul ))
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    ifeq ($(strip $(VENDOR)),NONE) # Ignore release package setting check for VENDOR SDK projects
      ifeq ($(findstring REL_CR,$(strip $(RELEASE_PACKAGE))),)
        $(error Please use REL_CR_XXXXXX makefile, not use REL_SUB_XXXXXX one in customer projects)
      endif
    endif
  endif
endif

#ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
include make\Custom_Release_ext.mak
#endif

ifndef EMPTY_RESOURCE
EMPTY_RESOURCE = FALSE
MMI_FEATURES_SWITCH = FALSE       # TRUE or FALSE   It's for the internal usage only.
endif

ifndef SWITCHABLE_FEATURE
SWITCHABLE_FEATURE = NONE
endif

ifndef SWITCHABLE_FEATURE_2ND
SWITCHABLE_FEATURE_2ND = NONE
endif

# ensure J2ME_SUPPORT <> MTK_J2ME
ifdef J2ME_SUPPORT
  ifneq ($(strip $(RELEASE_PACKAGE)),REL_CR_OBJ_JAL_SRC_GPRS)
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
      ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
        $(error to prevent \mcu\j2me being released as source code, J2ME_VM cannot be set to KVM_SOURCE when J2ME_SUPPORT is IJET)
      endif
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
      ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
        $(error to prevent \mcu\j2me being released as source code, J2ME_VM cannot be set to HI_VM_SOURCE when J2ME_SUPPORT is IJET)
      endif
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
      ifneq ($(filter NEMO_VM_SOURCE_NORMAL NEMO_VM_SOURCE_FULL,$(strip $(call Upper,$(J2ME_VM)))),)
        $(error to prevent \mcu\j2me being released as source code, J2ME_VM cannot be set to NEMO_VM_SOURCE_NORMAL or NEMO_VM_SOURCE_FULL when J2ME_SUPPORT is NEMO)
      endif
    endif    
  endif
endif

EN_DEF_FILE = make\$(strip $(CUSTOMER))_$(PROJECT)_en.def
DIS_DEF_FILE = make\$(strip $(CUSTOMER))_$(PROJECT)_dis.def
INFOMAKELOG  = make\info_custom_release.log
CODE_REMOVAL_DIR_FILE = make\SpecifyRemovalCodeDir.def

RELPKG_LOG = ckrelpkg.log

# Auto Remove Code
ifneq ($(strip $(PARTIAL_COPY)),TRUE)
$(shell tools\strcmpex.exe abc abc e make\~com_def.tmp $(strip $(COM_DEFS)))

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  $(shell echo _SST_FUNCTION_ENABLE_ >> make\~com_def.tmp)
endif

$(shell if exist $(strip $(DIS_DEF_FILE)) (del /Q $(strip $(DIS_DEF_FILE))))
$(shell if exist $(strip $(EN_DEF_FILE)) (del /Q $(strip $(EN_DEF_FILE))))

AUTO_REMOVE_CODE = $(shell dir mtk_tools\Auto_RemovingCode.pl /b 2>nul)

ifeq ($(words $(AUTO_REMOVE_CODE)),1)
  $(shell if exist $(strip $(DIS_DEF_FILE)) (del /Q $(strip $(DIS_DEF_FILE))))
  $(shell if not exist $(strip $(DIS_DEF_FILE)) (perl mtk_tools\Auto_RemovingCode.pl $(strip $(CUSTOMER)) $(PROJECT) "$(strip $(CC))" $(MTK_SUBSIDIARY) $(THE_MF)))
else
  $(shell if not exist $(strip $(DIS_DEF_FILE)) (copy /y nul $(strip $(DIS_DEF_FILE)) > nul ))
endif

ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  $(shell type make\SUPERSET_CUSTOM_en.def > $(strip $(EN_DEF_FILE)) )
endif

$(shell del $(WORK_DIR)\make\~com_def.tmp)
# end of Auto Remove Code

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifneq ($(findstring __OP_TECH_REL__,$(strip $(COM_DEFS))),)
      ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        $(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
        $(shell if exist mtk_tools\genOPTREnDef.pl (perl mtk_tools\genOPTREnDef.pl $(EN_DEF_FILE) make\SUPERSET_CUSTOM_OPERATOR_TECH_en.def))
      else
        $(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
      endif
    else
      $(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
    endif
  else
    $(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
  endif
else
  $(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
endif

$(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
$(shell if not exist $(strip $(CODE_REMOVAL_DIR_FILE)) (copy /y nul $(strip $(CODE_REMOVAL_DIR_FILE)) > nul ))

DIS_DEF_CNT = $(shell dir $(WORK_DIR)\$(strip $(DIS_DEF_FILE)) /b 2>nul)

ifneq ($(words $(DIS_DEF_CNT)),1)
   $(error $(DIS_DEF_FILE) does NOT exist)
endif
endif

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),KVM)
      COMPLIST :=  	$(filter-out ijet_adp,$(COMPLIST))
      CUS_REL_SRC_COMP :=  	$(filter-out ijet_adp,$(CUS_REL_SRC_COMP))
      CUS_REL_MTK_COMP :=  	$(filter-out ijet_adp,$(CUS_REL_MTK_COMP))
      CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\IJET\j2me_11.lib,$(CUS_REL_OBJ_LIST))
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),HI_VM)
      COMPLIST :=  	$(filter-out ijet_adp,$(COMPLIST))
      CUS_REL_SRC_COMP :=  	$(filter-out ijet_adp,$(CUS_REL_SRC_COMP))
      CUS_REL_MTK_COMP :=  	$(filter-out ijet_adp,$(CUS_REL_MTK_COMP))
      CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\IJET\j2me_hi.lib,$(CUS_REL_OBJ_LIST))
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
   COMPLIST :=  	$(filter-out jblendia,$(COMPLIST))
   CUS_REL_SRC_COMP :=  	$(filter-out jblendia,$(CUS_REL_SRC_COMP))
   CUS_REL_MTK_COMP :=  	$(filter-out jblendia,$(CUS_REL_MTK_COMP))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\JBlendia\lib\ajsc_arm_ads.a,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\JBlendia\lib\ajsc_custom_arm_ads.a,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\JBlendia\lib\libmjb2.a,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\JBlendia\lib\libz.a,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\jblendia\lib\ajsc_win32_msvc.lib,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\jblendia\lib\libmjb2.lib,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(filter-out j2me\vm\jblendia\lib\zlib_win32_msvc.lib,$(CUS_REL_OBJ_LIST))
endif
endif

# Release single module
ifdef MODULE
ifneq ($(strip $(call Upper,$(MODULE))),MULTICUSTOMRELEASE)
COMPLIST := $(MODULE)
ifneq ($(filter $(strip $(MODULE)),$(CUS_REL_SRC_COMP)),)
CUS_REL_SRC_COMP :=  $(MODULE)
else
CUS_REL_SRC_COMP :=
endif
ifneq ($(filter $(strip $(MODULE)),$(CUS_REL_MTK_COMP)),)
CUS_REL_MTK_COMP :=  $(MODULE)
else
CUS_REL_MTK_COMP :=
endif
ifneq ($(filter $(strip $(MODULE)),$(CUS_REL_PAR_SRC_COMP)),)
CUS_REL_PAR_SRC_COMP :=  $(MODULE)
else
CUS_REL_PAR_SRC_COMP :=
endif
endif
endif

# check comp should not in $(CUS_REL_SRC_COMP) or $(CUS_REL_BASE_COMP)
# Partial Comp without FORBIDDEN_COMP
ifneq ($(strip $(PARTIAL_COPY)),TRUE) 
ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifeq ($(strip $(VENDOR)),NONE)
FORBIDDEN_COMP = dp_engine opengl opengl16 fdm sst btadp btprofiles btstack supc wndrv ecompass external_mmi 
  else
FORBIDDEN_COMP = dp_engine opengl opengl16 fdm sst btstack supc wndrv external_mmi 
  endif
else
FORBIDDEN_COMP = dp_engine opengl opengl16 fdm sst btstack supc wndrv external_mmi 
endif

COMPLIST_NOT_CREL_COMP = $(filter $(FORBIDDEN_COMP),$(CUS_REL_SRC_COMP) (CUS_REL_BASE_COMP))
ifneq ($(words $(COMPLIST_NOT_CREL_COMP)),0)
   $(error $(foreach comp,$(COMPLIST_NOT_CREL_COMP),"$(comp)") should NOT in CUS_REL_SRC_COMP $(foreach comp,$(CUS_REL_SRC_COMP),"$(comp)") or CUS_REL_BASE_COMP $(foreach comp,$(CUS_REL_BASE_COMP),"$(comp)"))
endif

# put all CUS_REL_XXX_PAR_SRC_LIST together
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
   ALL_CUS_REL_PAR_SRC_LIST = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),[build\$(CUSTOMER)\module\~$(comp).lis]$(CUS_REL_$(comp)_PAR_SRC_LIST))
endif
endif
# move consistency check for COMPLIST & CUS_REL_XXX_COMP to Option.mak to make build process can also use it

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),KVM)
      CUS_REL_BASE_COMP += make\ijet_adp make\j2me_11
      CUS_REL_SRC_COMP +=  	jdummy
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),HI_VM)
      CUS_REL_BASE_COMP += make\ijet_adp make\j2me_hi make\j2me_hi_i386
      CUS_REL_SRC_COMP +=  	jdummy
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
   CUS_REL_BASE_COMP += make\jblendia
   CUS_REL_SRC_COMP +=  	jdummy
endif
endif

ifdef BTSTACK_SUPPORT
  ifneq ($(strip $(BTSTACK_SUPPORT)),LIB)
    $(error Please set BTSTACK_SUPPORT to be LIB in custom release)
  endif
endif

ifdef WNDRV_SUPPORT
  ifneq ($(strip $(WNDRV_SUPPORT)),LIB)
    $(error Please set WNDRV_SUPPORT to be LIB in custom release)
  endif
endif

ifdef SUPC_SUPPORT
  ifneq ($(strip $(SUPC_SUPPORT)),LIB)
    $(error Please set SUPC_SUPPORT to be LIB in custom release)
  endif
endif

# *************************************************************************
#  Target Definitions
# *************************************************************************

MMI_PROJ = $(strip $(subst _MMI,,$(MMI_VERSION)))
ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  MMI_PROJ := PLUTO
endif

ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
  ifneq ($(filter IOT_MMI PLUTO_MMI ,$(strip $(MMI_VERSION))),)
    ifdef EMPTY_RESOURCE
      ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
        MP_NOT_IN_MTK = TRUE
      else
        MP_NOT_IN_MTK = INTERNAL
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    ifdef EMPTY_RESOURCE
      ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
        MP_NOT_IN_MTK = TRUE
      else
        MP_NOT_IN_MTK = INTERNAL
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    ifdef EMPTY_RESOURCE
      ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
        MP_NOT_IN_MTK = TRUE
      else
        MP_NOT_IN_MTK = INTERNAL
      endif
    endif
  endif
endif


BPLGUINFOCUSTOM = $(shell dir $(FIXPATH)\$(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMPREFIX))* /b)

ifdef CUS_REL_SRC_COMP
SRC_LIS_FILE = $(foreach mod,$(CUS_REL_SRC_COMP), \
    $(strip $($(mod)))\$(mod)\$(mod).lis)
CUS_REL_SRC_COMP_DEP = $(foreach comp,$(CUS_REL_SRC_COMP),$(comp).dep)
endif

ifdef CUS_REL_MTK_COMP
MTK_LIS_FILE = $(foreach mod,$(CUS_REL_MTK_COMP), \
    $(FIXPATH)\build\$(CUSTOMER)\module\$(strip $($(mod)))\$(mod)\$(mod).lis)
CUS_REL_MTK_COMP_DEP = $(foreach comp,$(CUS_REL_MTK_COMP),$(comp).dep)
endif

ifdef CUS_REL_PAR_SRC_COMP
CUS_REL_PAR_SRC_COMP_DEP = $(foreach comp,$(CUS_REL_PAR_SRC_COMP),$(comp).dep)
endif

# *************************************************************************
# Custom Release
# *************************************************************************
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
custom_release: ck_dep_files gen_dbinfo base hdr_comp src_comp codegen_rel nvramautogen_rel resgen_rel par_src_comp mtk_comp devapp_res files_list obj_list non_rel_dirs_list non_rel_files_list gen_trace check_obj filter_out done
	@echo vendor_release is done!!!
else
ifeq ($(strip $(MTK_SUBSIDIARY)),FALSE)
custom_release: ck_dep_files gen_dbinfo sec_policy_sst base hdr_comp src_comp codegen_rel nvramautogen_rel resgen_rel par_src_comp mtk_comp files_list obj_list non_rel_dirs_list non_rel_files_list level_rel sec_policy gen_trace switch29_30 common_2726M26 clean_temp check_obj filter_out done
	@echo custom_release is done!!!
endif
endif

else

ifdef MODULE
ifeq ($(strip $(call Upper,$(MODULE))),MULTICUSTOMRELEASE)
custom_release: ck_dep_files gen_dbinfo sec_policy_sst base hdr_comp src_comp codegen_rel nvramautogen_rel resgen_rel par_src_comp mtk_comp files_list obj_list non_rel_dirs_list non_rel_files_list level_rel sec_policy gen_trace switch29_30 common_2726M26 gen_custom_dep clean_temp check_obj done
	@echo custom_release is done!!!
else
custom_release: ck_dep_files gen_dbinfo src_comp par_src_comp mtk_comp check_obj filter_out done
	@echo $(MODULE) release is done!!!
endif
else
  ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
custom_release: ck_dep_files gen_dbinfo base hdr_comp src_comp codegen_rel nvramautogen_rel resgen_rel par_src_comp mtk_comp devapp_res files_list obj_list non_rel_dirs_list non_rel_files_list gen_trace check_obj filter_out done
	@echo vendor_release is done!!!
  else
custom_release: ck_dep_files gen_dbinfo sec_policy_sst base hdr_comp src_comp codegen_rel nvramautogen_rel resgen_rel par_src_comp mtk_comp files_list obj_list non_rel_dirs_list non_rel_files_list level_rel sec_policy gen_trace switch29_30 common_2726M26 gen_custom_dep clean_temp check_obj filter_out done
	@echo custom_release is done!!!
endif
endif
endif
# *************************************************************************
# Partial Copy
# *************************************************************************
partial_copy: ck_dep_files gen_dbinfo base src_comp par_src_comp mtk_comp files_list obj_list level_rel gen_trace done
	@echo Partial Copy Done!

ck_dep_files:
	@tools\make.exe -fmake\gsm2.mak -k -r -R CHECK_SCAN=TRUE COMP_DEP_LIST=$(CUS_REL_SRC_COMP_DEP) scan
	@tools\make.exe -fmake\gsm2.mak -k -r -R CHECK_SCAN=TRUE COMP_DEP_LIST=$(CUS_REL_PAR_SRC_COMP_DEP) scan

gen_dbinfo:
ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
	@tools\make.exe -fmake\gsm2.mak -k -r -R CHECK_SCAN=TRUE COMP_DEP_LIST=$(CUS_REL_MTK_COMP_DEP) scan
	@echo Generate a table for module ID and library...
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@tools\ModLibTbl.exe -log-$(strip $(COMPLOGDIR)) -dep-$(strip $(RULESDIR)) -out-$(strip $(TST_DB))\custom_databaseinfo.csv
else
	@tools\ModLibTbl.exe -log-$(strip $(COMPLOGDIR)) -dep-$(strip $(RULESDIR)) -out-$(strip $(TST_DB))\MTK_databaseinfo.csv
endif
endif

base:
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
	@perl -e "print 'T_E,MAKEFILE_PREPROC,PC_P,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP)
	@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP)
	@perl -e "print 'FIXPATH = $(FIXPATH)' . \"\n\"";>>$(MBIS_PC_TIME_TMP)
	@perl -e "print 'RELEASE_DIR = $(RELEASE_DIR)' . \"\n\"";>>$(MBIS_PC_TIME_TMP)
	@echo CUS_REL_SRC_COMP = $(CUS_REL_SRC_COMP) >>$(MBIS_PC_TIME_TMP)
	@echo CUS_REL_MTK_COMP = $(CUS_REL_MTK_COMP) >>$(MBIS_PC_TIME_TMP)
	@echo CUS_REL_BASE_COMP = $(CUS_REL_BASE_COMP) >>$(MBIS_PC_TIME_TMP)
endif

	@if $(words $(strip $(BPLGUINFOCUSTOM))) NEQ 1 @echo More than two $(strip $(BPLGUINFOCUSTOM)). Please check.
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
	@echo Partial Copy $(strip $(PROJECT)) for $(strip $(CUSTOMER)):
else
	@echo Customer Release $(strip $(PROJECT)) for $(strip $(CUSTOMER)):
endif
	@if not exist "$(RELEASE_DIR)"  \
		md "$(RELEASE_DIR)"

   # -----------------------------
   # generate 3 party release log info
   # -----------------------------
	@if exist "$(RELEASE_DIR)"\*.txt \
		(del "$(RELEASE_DIR)"\*.txt)

	echo. > "$(RELEASE_DIR)"\$(strip $(VERNO)).txt

ifdef FOTA_ENABLE
ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
	echo. > "$(RELEASE_DIR)"\REDBEND-FOTA.txt
endif
endif

ifdef L1_WCDMA
ifeq ($(strip $(L1_WCDMA)),TRUE)
	echo. > "$(RELEASE_DIR)"\WCDMA.txt
endif
endif

ifdef VR_ENGINE
ifeq ($(strip $(VR_ENGINE)),VR_CYBERON)
	echo. > "$(RELEASE_DIR)"\Cyberon-VR.txt
endif
ifeq ($(strip $(VR_ENGINE)),VR_ITRI)
	echo. > "$(RELEASE_DIR)"\ITRI-VR.txt
endif
endif

ifdef J2ME_SUPPORT
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
	echo. > "$(RELEASE_DIR)"\III-J2ME.txt
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	echo. > "$(RELEASE_DIR)"\APLIX-J2ME.txt
endif
endif

ifdef OBIGO_FEATURE
ifeq ($(strip $(OBIGO_FEATURE)),WAP)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(OBIGO_FEATURE)),WAP2)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(OBIGO_FEATURE)),WAP_MMS)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(OBIGO_FEATURE)),WAP2_MMS)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC_MMS)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
endif

ifneq ($(filter nucleus,$(strip $(COMPLIST))),)
	echo. > "$(RELEASE_DIR)"\MG-RTOS.txt
endif

ifdef HAND_WRITING
ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
	echo. > "$(RELEASE_DIR)"\HW-HW.txt
endif
ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
	echo. > "$(RELEASE_DIR)"\PP-HW.txt
endif
endif

ifdef WMA_DECODE
ifeq ($(strip $(WMA_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\MS-WMA.txt
endif
endif

ifdef INPUT_METHOD
ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
	echo. > "$(RELEASE_DIR)"\T9-IMD.txt
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
	echo. > "$(RELEASE_DIR)"\Zi-IMD.txt
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
	echo. > "$(RELEASE_DIR)"\Cstar-IMD.txt
endif
endif

ifdef DICT_SUPPORT
ifeq ($(strip $(DICT_SUPPORT)),MMI_GV)
	echo. > "$(RELEASE_DIR)"\GV-DICT.txt
endif
ifeq ($(strip $(DICT_SUPPORT)),MMI_MOTECH)
	echo. > "$(RELEASE_DIR)"\MOTECH-DICT.txt
endif
ifeq ($(strip $(DICT_SUPPORT)),MMI_TRILOGY)
	echo. > "$(RELEASE_DIR)"\TRILOGY-DICT.txt
endif
endif

ifdef DRM_SUPPORT
ifeq ($(strip $(DRM_SUPPORT)),BSCI)
	echo. > "$(RELEASE_DIR)"\BS-DRM.txt
endif
endif

ifdef GAME_ENGINE
ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
	echo. > "$(RELEASE_DIR)"\Brogent-3DGAME.txt
endif
endif

ifdef AAC_DECODE
ifeq ($(strip $(AAC_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\CT-AAC.txt
endif
endif

ifdef AAC_PLUS_DECODE
ifeq ($(strip $(AAC_PLUS_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\CT-AACPLUS.txt
endif
endif

ifdef AAC_PLUS_PS_DECODE
ifeq ($(strip $(AAC_PLUS_PS_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\CT-AACPLUSV2.txt
endif
endif

ifdef SYNCML_DM_SUPPORT
ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
	echo. > "$(RELEASE_DIR)"\Bitfone-DM.txt
endif
endif

ifdef BROWSER_SUPPORT
ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS05A.txt
endif
endif

ifdef TTS
ifeq ($(strip $(TTS)),CYBERON_DIC_TTS)
	echo. > "$(RELEASE_DIR)"\Cyberon-TTS.txt
endif
endif

ifdef SW_FLASH
ifeq ($(strip $(SW_FLASH)),NEOMTEL)
	echo. > "$(RELEASE_DIR)"\NEOMTEL-SW_FLASH.txt
endif
endif

	@if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB) \
		md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)

	@if not exist "$(RELEASE_DIR)"\make \
		md "$(RELEASE_DIR)"\make

	@if not exist "$(RELEASE_DIR)"\tools \
		md "$(RELEASE_DIR)"\tools

	@if not exist "$(RELEASE_DIR)"\tools\GLBOptionSwtichRef \
		md "$(RELEASE_DIR)"\tools\GLBOptionSwtichRef

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	@if not exist "$(RELEASE_DIR)"\mtk_tools \
		md "$(RELEASE_DIR)"\mtk_tools
		
	@if exist $(FIXPATH)\mtk_tools\PartialCopy \
		if not exist "$(RELEASE_DIR)"\mtk_tools\PartialCopy \
			md "$(RELEASE_DIR)"\mtk_tools\PartialCopy
endif

	@if not exist "$(RELEASE_DIR)"\Fast_DL \
		md "$(RELEASE_DIR)"\Fast_DL

	@if not exist "$(RELEASE_DIR)"\custom\system\$(BOARD_VER) \
		md "$(RELEASE_DIR)"\custom\system\$(BOARD_VER)


   # -----------------------------
   # Duplicate base files
   # -----------------------------
	copy /z $(FIXPATH)\make.bat "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\m.bat "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\make2.pl "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\BuildMMAA.pl "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\m_cp2lsf.pl "$(RELEASE_DIR)"\.
ifeq ($(strip $(RTOS)),THREADX)
	copy /z $(FIXPATH)\THREADX*.* "$(RELEASE_DIR)"\.
else
	copy /z $(FIXPATH)\nuc*.* "$(RELEASE_DIR)"\.
endif
	copy /z $(FIXPATH)\make\GSM2.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Comp.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Option.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Option_HAL.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\JAVA_DEF.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\ALIAS.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\$(NOT_REMOVAL_DIR_FILE) "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\checkvalue.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\standalone_action.mak "$(RELEASE_DIR)"\make\.
	-copy /z $(FIXPATH)\make\OLD_FEATURES.mak "$(RELEASE_DIR)"\make\.
	-copy /z $(FIXPATH)\make\MODEM.mak "$(RELEASE_DIR)"\make\.
	-copy /z $(FIXPATH)\make\intermed.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\REL_CR_VENDOR.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\REL_COMMON.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\modisConfig.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\modisBuild.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Codegen.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Resgen.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\custpack.mak "$(RELEASE_DIR)"\make\.
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	copy /z $(FIXPATH)\make\Custom_Release.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\USER_SPECIFIC.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\mtk_tools\traversedir.pl "$(RELEASE_DIR)"\tools\.
	copy /z $(FIXPATH)\mtk_tools\traversedir_modis.pl "$(RELEASE_DIR)"\tools\.
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	copy /z $(FIXPATH)\make\Custom_Release_ext.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\compiler_cfg.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\SUPERSET_CUSTOM_dis.def "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\SUPERSET_CUSTOM_en.def "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\SUPERSET_CUSTOM_OPERATOR_TECH_en.def "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\SUPERSET_INTERNAL_dis.def "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\internal_action.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\mtk_tools\clone.pl "$(RELEASE_DIR)"\mtk_tools\.
	copy /z $(FIXPATH)\mtk_tools\operator_empty_res_release.bat "$(RELEASE_DIR)"\mtk_tools\.
	copy /z $(FIXPATH)\mtk_tools\Auto_RemovingCode.pl "$(RELEASE_DIR)"\mtk_tools\.
	copy /z $(FIXPATH)\mtk_tools\disable_3rd_feature.bat "$(RELEASE_DIR)"\mtk_tools\.
ifneq ($(strip $(PARTIAL_COPY)),TRUE)
	@if exist $(FIXPATH)\mtk_tools\PartialCopy \
		copy /z $(FIXPATH)\mtk_tools\PartialCopy\*.* "$(RELEASE_DIR)"\mtk_tools\PartialCopy\.
endif
endif
ifdef SMART_PHONE_CORE
ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
	copy /z $(FIXPATH)\make\smart_phone_option.mak "$(RELEASE_DIR)"\make\.
endif
endif
endif

ifdef DSP_SOLUTION
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
		copy /z $(FIXPATH)\make\DSP.mak "$(RELEASE_DIR)"\make\.
  endif
endif

ifdef NEED_DSP_FD_BIN
  ifeq ($(strip $(NEED_DSP_FD_BIN)),TRUE)
		copy /z $(FIXPATH)\make\DSP.mak "$(RELEASE_DIR)"\make\.
  endif
endif

	copy /z $(FIXPATH)\make\$(strip $(CUSTOMER))_$(PROJECT).mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\$(strip $(CUSTOMER))_$(PROJECT).mak "$(RELEASE_DIR)"\tools\GLBOptionSwtichRef\.

ifdef PROJECT_MAKEFILE_EXT
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),)
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),NONE)
	@if exist $(FIXPATH)\make\custom_config \
		if not exist "$(RELEASE_DIR)"\make\custom_config \
			md "$(RELEASE_DIR)"\make\custom_config & \
			copy /z $(FIXPATH)\make\custom_config\$(strip $(PROJECT_MAKEFILE_EXT)).mak "$(RELEASE_DIR)"\make\custom_config\.
  endif
  endif
endif

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\$(strip $(CUSTOMER))_$(PROJECT).mak';$$f = join(\"\",<F>);$$f=~s/(J2ME_SUPPORT\s*=\s*)J2ME_LIB/$$1 MTK_DUMMYVM/g;seek(F,0,0);print F $$f;close F;"
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\option.mak';$$f = join(\"\",<F>);$$f=~s/(COM_DEFS\s*\+=\s*__MTK_DUMMY_VM__)/$$1 CLDC11/g;seek(F,0,0);print F $$f;close F;"
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),HI_VM)
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\$(strip $(CUSTOMER))_$(PROJECT).mak';$$f = join(\"\",<F>);$$f=~s/(J2ME_JSR184_SUPPORT\s*=\s*)\S+/$$1 NONE/g;$$f=~s/(J2ME_SUPPORT\s*=\s*)J2MEHI_LIB/$$1 MTK_DUMMYVM/g;seek(F,0,0);print F $$f;close F;"
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\option.mak';$$f = join(\"\",<F>);$$f=~s/(COM_DEFS\s*\+=\s*__MTK_DUMMY_VM__)/$$1 CLDCHI/g;seek(F,0,0);print F $$f;close F;"
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	perl -e "open F,'+<"$(RELEASE_DIR)"\make\$(strip $(CUSTOMER))_$(PROJECT).mak';$$f = join(\"\",<F>);$$f=~s/(J2ME_SUPPORT\s*=\s*)JBLENDIA/$$1 MTK_DUMMYVM/g;seek(F,0,0);print F $$f;close F;"
	perl -e "open F,'+<"$(RELEASE_DIR)"\make\option.mak';$$f = join(\"\",<F>);$$f=~s/(COM_DEFS\s*\+=\s*__MTK_DUMMY_VM__)/COMMINCDIRS	\+= j2me\vm\JBlendia\include\ksi\\n$$1/g;seek(F,0,0);print F $$f;close F;"
endif
endif

	copy /z $(FIXPATH)\$(VERNOFILE) "$(RELEASE_DIR)"\$(VERNOFILE)
ifdef RELEASE_PACKAGE
	copy /z $(FIXPATH)\make\$(strip $(RELEASE_PACKAGE)).mak "$(RELEASE_DIR)"\make\.
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
      ifneq ($(call Upper ,$(strip $(PROJECT))),BASIC)
        ifneq ($(call Upper ,$(strip $(PROJECT))),UDVT)
					@if exist $(FIXPATH)\make\REL_CR_MMI_$(PROJECT).mak \
						(copy /z /y $(FIXPATH)\make\REL_CR_MMI_$(PROJECT).mak "$(RELEASE_DIR)"\make\.)
        endif
      endif
  else
    ifeq ($(call Upper ,$(strip $(LEVEL))),VENDOR)
					@if exist $(FIXPATH)\make\REL_CR_MMI_$(PROJECT).mak \
						(copy /z /y $(FIXPATH)\make\REL_CR_MMI_$(PROJECT).mak "$(RELEASE_DIR)"\make\.)
    endif
  endif
endif

	copy /z $(FIXPATH)\$(SCATTERFILE) "$(RELEASE_DIR)"\$(SCATTERFILE)

ifeq ($(filter bootloader, $(strip $(CUS_REL_SRC_COMP))),bootloader)
	@if exist $(FIXPATH)\$(BL_SCATTERFILE) \
		(copy /z $(FIXPATH)\$(BL_SCATTERFILE) "$(RELEASE_DIR)"\$(BL_SCATTERFILE))
endif

ifeq ($(filter fota, $(strip $(CUS_REL_SRC_COMP))),fota)
	@if exist $(FIXPATH)\$(FOTA_SCATTERFILE) \
		(copy /z $(FIXPATH)\$(FOTA_SCATTERFILE) "$(RELEASE_DIR)"\$(FOTA_SCATTERFILE))
endif

ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
# Partial Copy do not need to remove line
	@if exist $(FIXPATH)\$(strip $(CUSTOMER))_*_$(PROJECT)_*_MTK_only.cmm \
		(copy /z $(FIXPATH)\$(strip $(CUSTOMER))_*_$(PROJECT)_*_MTK_only.cmm "$(RELEASE_DIR)"\.) \
	else \
		(if exist $(FIXPATH)\MTK_*_$(PROJECT)_*_MTK_only.cmm \
			(copy /z $(FIXPATH)\MTK_*_$(PROJECT)_*_MTK_only.cmm "$(RELEASE_DIR)"\.) \
		)
else
	@if exist $(FIXPATH)\$(strip $(CUSTOMER))_*_$(PROJECT)_*_MTK_only.cmm \
		(copy /z $(FIXPATH)\$(strip $(CUSTOMER))_*_$(PROJECT)_*_MTK_only.cmm "$(RELEASE_DIR)"\.) & \
		(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_MTK_only.cmm "menu.reprogram gprs") \
	else \
		(if exist $(FIXPATH)\MTK_*_$(PROJECT)_*_MTK_only.cmm \
			(copy /z $(FIXPATH)\MTK_*_$(PROJECT)_*_MTK_only.cmm "$(RELEASE_DIR)"\.) & \
			(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\MTK_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_MTK_only.cmm "menu.reprogram gprs") \
		)
endif
	@if exist $(FIXPATH)\BasicAnalysis.cmm \
		(copy /z $(FIXPATH)\BasicAnalysis.cmm "$(RELEASE_DIR)"\.)
endif
endif

	@if exist $(FIXPATH)\mcu_debugging_notice.cmm \
		(copy /z $(FIXPATH)\mcu_debugging_notice.cmm "$(RELEASE_DIR)"\.)
	@if exist $(FIXPATH)\InTargetReset.men \
		(copy /z $(FIXPATH)\InTargetReset.men "$(RELEASE_DIR)"\.)
	@if exist $(FIXPATH)\In_target_reset.cmm \
		(copy /z $(FIXPATH)\In_target_reset.cmm "$(RELEASE_DIR)"\.)
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifneq ($(strip $(PARTIAL_COPY)),TRUE)		
# Partial Copy do not need to remove line
		@if exist "$(RELEASE_DIR)"\$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm \
			(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm "menu.reprogram gprs") \
		else \
			(if exist "$(RELEASE_DIR)"\MTK_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm \
				(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\MTK_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm "menu.reprogram gprs") \
			)
endif
endif

	@if exist $(FIXPATH)\Fast_DL\$(TARGNAME).cmm \
		(copy /z $(FIXPATH)\Fast_DL\$(TARGNAME).cmm "$(RELEASE_DIR)"\Fast_DL\.)

	@if exist $(FIXPATH)\$(strip $(TST_DB)) \
		(xcopy /y /h "$(FIXPATH)\$(strip $(TST_DB))\"*$(BPLGUINFOCUSTOMPREFIX)_* "$(RELEASE_DIR)"\$(strip $(TST_DB))\)

ifneq ($(strip $(SWITCH_FOLDER)),)
	@(xcopy /y /h "$(FIXPATH)\$(strip $(TST_DB))\"*$(BPLGUINFOCUSTOMPREFIX)_* "$(RELEASE_DIR)"\$(strip $(TST_DB))\$(strip $(SWITCH_FOLDER))\)
endif

   # -----------------------------
   # Duplicate base directories
   # -----------------------------
#	for /d %%i in ($(strip $(CUS_REL_BASE_COMP))) do \
#		xcopy /e /y  $(FIXPATH)\%%i "$(RELEASE_DIR)"\%%i\*.*
	$(shell del /q $(WORK_DIR)\make\~base.tmp)
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@echo Duplicate base directories... >>$(MBIS_PC_TIME_TMP)) 
	$(foreach base_comp,$(strip $(CUS_REL_BASE_COMP)),$(shell echo $(base_comp)>>make\~base.tmp))
#	@perl tools\copyDirs.pl $(FIXPATH) "$(RELEASE_DIR)" $(strip $(CUS_REL_BASE_COMP))
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
	@perl mtk_tools\PartialCopy\copyDirs_PC.pl $(FIXPATH) "$(RELEASE_DIR)" make\~base.tmp "$(RELEASE_DIR)"
else
	@perl tools\copyDirs.pl $(FIXPATH) "$(RELEASE_DIR)" make\~base.tmp $(call Upper ,$(strip $(LEVEL)))
endif
   # -----------------------------
   # copy \$(strip $(MMIDIR))\Customer\CustResource\$(strip $(CUSTOMER))_MMI\*.* @if /I "$(NEED_COPY_MMIFEATURE)" EQU "TRUE"
   # -----------------------------
# copy \$(strip $(MMIDIR))\Customer\CustResource\$(strip $(CUSTOMER))_MMI\mmi_featureXXX.h & CustMiscDataXXX.c @if /I "$(NEED_COPY_MMIFEATURE)" EQU "TRUE"
# copy \$(strip $(MMIDIR))\Customer\CustResource\$(strip $(CUSTOMER))_MMI\*.* @if /I "$(NEED_COPY_MMIFEATURE)" EQU "TRUE"

ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
	@if exist $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\$(strip $(BOARD_VER)).cfg \
		copy /y /z $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\$(strip $(BOARD_VER)).cfg "$(RELEASE_DIR)"\custom\system\$(strip $(BOARD_VER))\.
endif

	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@echo copy buildloader... >>$(MBIS_PC_TIME_TMP)) 	
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
# Partial Copy need bootloader for linking
	@if exist $(strip $(TARGDIR))\$(strip $(CUSTOMER))_BOOTLOADER_*.bin \
		(if not exist $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR)))  (md $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR))))) & \
		(copy /z $(strip $(TARGDIR))\$(strip $(CUSTOMER))_BOOTLOADER_*.bin  $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR))))
	@if exist $(strip $(TARGDIR))\EXT_BOOTLOADER \
		(if not exist $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR)))	(md $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR))))) & \
		(copy /z $(strip $(TARGDIR))\EXT_BOOTLOADER $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR))))
# for remake_dep/update_dep
	@if exist $(RULESDIR) \
			(if not exist $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(RULESDIR)))  (md $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(RULESDIR))))) & \
				(xcopy /y $(strip $(RULESDIR))\*.dep  $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(RULESDIR))))
	@if exist $(TARGDIR)\log \
			(if not exist $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR)\log))  (md $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR)\log)))) & \
				(xcopy /y $(strip $(TARGDIR)\log)\infomake.log  $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR)\log)))
endif

ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifeq ($(filter fota, $(strip $(CUS_REL_SRC_COMP))),)
      ifeq ($(strip $(PARTIAL_COPY)),TRUE)
      # Partial Copy need bootloader for linking      
				@if exist $(strip $(TARGDIR))\$(strip $(CUSTOMER))_FOTA_*.bin \
					(if not exist $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR)))  (md $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR))))) & \
					(copy /z $(strip $(TARGDIR))\$(strip $(CUSTOMER))_FOTA_*.bin  $(subst $(FIXPATH),"$(RELEASE_DIR)",$(strip $(TARGDIR))))
      else
				@if exist $(strip $(TARGDIR))\$(strip $(CUSTOMER))_FOTA_*.bin \
					(if not exist "$(RELEASE_DIR)"\$(strip $(TARGDIR))	(md "$(RELEASE_DIR)"\$(strip $(TARGDIR)))) & \
					(copy /z $(strip $(TARGDIR))\$(strip $(CUSTOMER))_FOTA_*.bin "$(RELEASE_DIR)"\$(strip $(TARGDIR)))
      endif
    endif
  endif
endif
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
hdr_comp:
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
   # -----------------------------
   # Duplicate release header file components
   # -----------------------------
ifneq ($(strip $(CUS_REL_HDR_COMP)),)
	@echo Duplicate release header file components ...
	for /d %%i in ($(strip $(CUS_REL_HDR_COMP))) do \
		(@echo header file component: %%i) & \
		(for /f "skip=2" %%j in ('find /I ".h" $(strip $(FIXPATH))\build\$(CUSTOMER)\module\%%i\%%i.lis') do \
			(@echo copying file %%j) & \
			(if not exist "$(RELEASE_DIR)"\%%j \
				(md "$(RELEASE_DIR)"\%%j) & \
				(rd "$(RELEASE_DIR)"\%%j) & \
				(copy /y $(FIXPATH)\%%j "$(RELEASE_DIR)"\%%j) \
			) \
		) & \
		(copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)
endif
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
src_comp:
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))	
   # -----------------------------
   # Duplicate release source components
   # -----------------------------
ifneq ($(strip $(CUS_REL_SRC_COMP)),)
	@if not exist "$(RELEASE_DIR)"  \
		md "$(RELEASE_DIR)"
	@if not exist "$(RELEASE_DIR)"\make \
		md "$(RELEASE_DIR)"\make
	@echo Duplicate release source components ...
	tools\strcmpex.exe trcdef trcdef e make\~trcdef.tmp $(foreach file,$(COMP_TRACE_DEFS),$(file))
	@echo. > make\~srccomprh.tmp

   # copy all files listed in .lis
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@echo copy all files listed in .lis... >>$(MBIS_PC_TIME_TMP)) 	   
	tools\strcmpex.exe srcfile srcfile e make\~srcfile.tmp $(foreach file,$(SRC_LIS_FILE),$(FIXPATH)\build\$(CUSTOMER)\module\$(file))
	@perl tools\copySrcFile.pl $(FIXPATH) "$(RELEASE_DIR)" make\~srcfile.tmp > nul
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
# Partial Copy use absolute path
	(for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
		(perl mtk_tools\PartialCopy\copySrcComp_PC.pl %%i $(RULESDIR) make "$(RELEASE_DIR)" $(FIXPATH)) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp))
else
	(for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
		(perl tools\copySrcComp.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i $(RULESDIR) make "$(RELEASE_DIR)") & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp))
endif

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
	(for /d %%i in (ijet_adp) do \
		(perl tools\req_hdr.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i\%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
	(for /d %%i in (j2me_11) do \
		(perl tools\req_hdr.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i\%%i.lis $(FIXPATH)\make\%%i\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),HI_VM)
	(for /d %%i in (ijet_adp) do \
		(perl tools\req_hdr.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i\%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
	(for /d %%i in (j2me_hi) do \
		(perl tools\req_hdr.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i\%%i.lis $(FIXPATH)\make\%%i\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	(for /d %%i in (jblendia) do \
		(perl tools\req_hdr.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i\%%i.lis $(FIXPATH)\make\%%i\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
endif
endif
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@echo copy .lis, .def, .pth, .inc... >>$(MBIS_PC_TIME_TMP))
   # copy .lis, .def, .pth, .inc
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
# Partial Copy use absolute path
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
		for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
			(perl mtk_tools\PartialCopy\copyLIS_PC.pl %%i "$(RELEASE_DIR)" $(MMIDIR) PLUTO_MMI $(FIXPATH) \
			)
    else
		for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
			(perl mtk_tools\PartialCopy\copyLIS_PC.pl %%i "$(RELEASE_DIR)" $(MMIDIR) $(MMI_VERSION) $(FIXPATH) \
			)
  endif
else
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
		for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
			(perl tools\copyLIS.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i "$(RELEASE_DIR)" $(MMIDIR) PLUTO_MMI \
			)
    else
		for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
			(perl tools\copyLIS.pl $(FIXPATH)\build\$(CUSTOMER)\module\%%i "$(RELEASE_DIR)" $(MMIDIR) $(MMI_VERSION) \
			)
  endif
endif

# For GEMINI switch in PROTOCOL release
ifneq ($(strip $(SWITCH_FOLDER)),)
  ifneq ($(filter tst ,$(strip $(CUS_REL_SRC_COMP))),)
		@if not exist "$(RELEASE_DIR)"\tst\src  \
			md "$(RELEASE_DIR)"\tst\src
		@if not exist "$(RELEASE_DIR)"\tst\include  \
			md "$(RELEASE_DIR)"\tst\include

  	@(xcopy /y tst\src\TrcMod.c "$(RELEASE_DIR)"\tst\src\$(strip $(SWITCH_FOLDER))\)
  	@(xcopy /y tst\include\TrcMod.h "$(RELEASE_DIR)"\tst\include\$(strip $(SWITCH_FOLDER))\)

  endif
endif

endif
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
par_src_comp:
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
   # -----------------------------
   # Duplicate partial release source components
   # -----------------------------
	tools\strcmpex.exe crpsrcl crpsrcl e make\~crpsrcl.tmp $(ALL_CUS_REL_PAR_SRC_LIST)
ifneq ($(strip $(CUS_REL_PAR_SRC_COMP)),)
	@if not exist "$(RELEASE_DIR)"  \
		md "$(RELEASE_DIR)"
	@if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB) \
		md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)
	@if not exist "$(RELEASE_DIR)"\make \
		md "$(RELEASE_DIR)"\make
	(@echo Duplicate release partial source components ...) & \
	(perl tools\lst2file.pl make\~crpsrcl.tmp)

   # copy all files listed in .lis

	for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
		(@echo partial source component: %%i) & \
		(perl tools\lnitem.pl build\$(CUSTOMER)\module\~%%i.lis) & \
		(for /f %%j in ($(FIXPATH)\build\$(CUSTOMER)\module\~%%i.lis) do \
			(@echo copying file %%j) & \
			(if not exist "$(RELEASE_DIR)"\%%j \
				(md "$(RELEASE_DIR)"\%%j) & \
				(rd "$(RELEASE_DIR)"\%%j) & \
				(copy /y $(FIXPATH)\%%j "$(RELEASE_DIR)"\%%j) \
			) \
		)

   # use .lis and .dep to find out the required header files then copy them
	-for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
		(perl tools\req_hdr.pl $(FIXPATH)\build\$(CUSTOMER)\module\~%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		)

   # copy .lis, .def, .pth, .inc, .$(CUS_MTK_LIB)\*.lib
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
			for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
			(if /I "%%i" EQU "$(strip $(MMIDIR))" \
				(if not exist "$(RELEASE_DIR)"\make\%%i \
					(md "$(RELEASE_DIR)"\make\%%i) \
				) & \
				(copy /z $(FIXPATH)\make\%%i\%%i.* "$(RELEASE_DIR)"\make\%%i\.) & \
				(copy /z build\$(CUSTOMER)\module\~%%i.lis "$(RELEASE_DIR)"\build\$(CUSTOMER)\module\%%i\%%i.lis) & \
				(xcopy /e /y $(FIXPATH)\make\%%i\PLUTO_MMI "$(RELEASE_DIR)"\make\%%i\PLUTO_MMI\*.*) & \
				(copy /z build\$(CUSTOMER)\module\~%%i.lis "$(RELEASE_DIR)"\build\$(CUSTOMER)\module\%%i\PLUTO_MMI\%%i.lis) \
			else \
				(xcopy /e /y $(FIXPATH)\make\%%i "$(RELEASE_DIR)"\make\%%i\*.*) & \
				(copy /z build\$(CUSTOMER)\module\~%%i.lis "$(RELEASE_DIR)"\build\$(CUSTOMER)\module\%%i\%%i.lis) \
			) & \
			(copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)
    else
		for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
			(if /I "%%i" EQU "$(strip $(MMIDIR))" \
				(if not exist "$(RELEASE_DIR)"\make\%%i \
					(md "$(RELEASE_DIR)"\make\%%i) \
				) & \
				(copy /z $(FIXPATH)\make\%%i\%%i.* "$(RELEASE_DIR)"\make\%%i\.) & \
				(copy /z build\$(CUSTOMER)\module\~%%i.lis "$(RELEASE_DIR)"\build\$(CUSTOMER)\module\%%i\%%i.lis) & \
				(xcopy /e /y $(FIXPATH)\make\%%i\$(MMI_VERSION) "$(RELEASE_DIR)"\make\%%i\$(strip $(MMI_VERSION))\*.*) & \
				(copy /z build\$(CUSTOMER)\module\~%%i.lis "$(RELEASE_DIR)"\build\$(CUSTOMER)\module\%%i\$(strip $(MMI_VERSION))\%%i.lis) \
			else \
				(xcopy /e /y $(FIXPATH)\make\%%i "$(RELEASE_DIR)"\make\%%i\*.*) & \
				(copy /z build\$(CUSTOMER)\module\~%%i.lis "$(RELEASE_DIR)"\build\$(CUSTOMER)\module\%%i\%%i.lis) \
			) & \
			(copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)
  endif
endif

	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
mtk_comp:
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
	@if not exist "$(RELEASE_DIR)"  \
		md "$(RELEASE_DIR)"
	@if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB) \
		md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)
	@if not exist "$(RELEASE_DIR)"\make \
		md "$(RELEASE_DIR)"\make
   # -----------------------------
   # Duplicate MTK library only
   # -----------------------------
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifneq ($(strip $(PARTIAL_COPY)),TRUE)
  ifneq ($(strip $(CUS_REL_MTK_COMP)),)
	for /d %%i in ($(strip $(CUS_REL_MTK_COMP))) do \
		((copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib) & \
		(if ERRORLEVEL 1 \
			(echo $(COMPLIBDIR)\%%i.lib does not exist & \
			exit 1)))
  endif
else
		@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@echo copy all lib to mtk lib folder.. >>$(MBIS_PC_TIME_TMP))
    # copy all lib (exclude source component lib) to mtk lib folder 
		for /d %%i in ($(strip $(filter-out $(CUS_REL_SRC_COMP),$(COMPLIST)))) do \
			((copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib) & \
			(if ERRORLEVEL 1 \
				(echo $(COMPLIBDIR)\%%i.lib does not exist & \
				exit 1)))	
		if not exist $(subst $(FIXPATH),"$(RELEASE_DIR)",$(COMPLIBDIR)) \
			md $(subst $(FIXPATH),"$(RELEASE_DIR)",$(COMPLIBDIR))	
    # copy release source component lib	
		@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@echo copy release source component lib	.. >>$(MBIS_PC_TIME_TMP))
		for /d %%i in ($(strip $(CUS_REL_SRC_COMP))) do \
			((copy /z $(COMPLIBDIR)\%%i.lib $(subst $(FIXPATH),"$(RELEASE_DIR)",$(COMPLIBDIR))\%%i.lib) & \
			(if ERRORLEVEL 1 \
				(echo $(COMPLIBDIR)\%%i.lib does not exist & \
				exit 1)))
endif    
else
#	xcopy /z /e /y $(CUS_MTK_LIB) "$(RELEASE_DIR)"\$(CUS_MTK_LIB)
	copy /z $(CUS_MTK_LIB)\*.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\.

  ifneq ($(strip $(CUS_REL_MTK_COMP)),)
	-for /d %%i in ($(strip $(CUS_REL_MTK_COMP))) do \
		(copy /z /y $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)
  endif

endif
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
devapp_res:
   # -----------------------------
   # rebuild vendorapp for resource used in vendor development, ONLY available in Vendor Release process
   # -----------------------------
ifneq ($(filter PLUTO_MMI COSMOS_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
  ifneq ($(filter vendorapp,$(CUS_REL_MTK_COMP)),)
    # ------------------------------------
    # backup original library & .dep file
    # ------------------------------------
		if not exist $(COMPLIBDIR)\vendorappBAK.lib \
			(copy /z /y $(COMPLIBDIR)\vendorapp.lib $(COMPLIBDIR)\vendorappBAK.lib)
		if not exist $(RULESDIR)\vendorappBAK.dep \
			(copy /z /y $(RULESDIR)\vendorapp.dep $(RULESDIR)\vendorappBAK.dep)
    # ------------------------------------
    # backup original definition file & configure new definition file
    # ------------------------------------
		if not exist make\vendorapp\vendorappMAK.mak \
			(copy /z /y make\vendorapp\vendorapp.mak make\vendorapp\vendorappBAK.mak) & \
			(echo COMP_DEFS += __DEVAPP_RESOURCE_OUTPUT__>>make\vendorapp\vendorapp.mak)
		@if exist $(strip $(TARGDIR))\module\vendorapp_backup \
			(rd /S /Q $(strip $(TARGDIR))\module\vendorapp_backup)
		@if exist $(strip $(TARGDIR))\module\vendorapp\*.* \
			(move $(strip $(TARGDIR))\module\vendorapp $(strip $(TARGDIR))\module\vendorapp_backup)
    # ------------------------------------
    # rebuild vendorapp.lib
    # ------------------------------------
		@del /s /q $(COMPLIBDIR)\vendorapp.lib
		@del /s /q $(RULESDIR)\vendorapp.dep
		@tools\make.exe -fmake\gsm2.mak -r -R CMD_ARGU=-j$(NUMBER_OF_PROCESSORS) CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) ACTION=cr gencompbld vendorapp.lib
		@if exist $(OBJSDIR)\vendorapp \
		  (rd /s/q $(OBJSDIR)\vendorapp)
    # ------------------------------------
  	# release the library vendor used & recover the original library ,.dep file & definition file
    # ------------------------------------
		(copy /z /y $(COMPLIBDIR)\vendorapp.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\.) & \
		(copy /z /y $(COMPLIBDIR)\vendorappBAK.lib $(COMPLIBDIR)\vendorapp.lib) & \
		(del $(COMPLIBDIR)\vendorappBAK.lib) & \
		(copy /z /y $(RULESDIR)\vendorappBAK.dep $(RULESDIR)\vendorapp.dep) & \
		(del $(RULESDIR)\vendorappBAK.dep) & \
		(copy /z /y make\vendorapp\vendorappBAK.mak make\vendorapp\vendorapp.mak) & \
		(del make\vendorapp\vendorappBAK.mak)
		@if exist $(strip $(TARGDIR))\module\vendorapp_backup ( \
			(if exist $(strip $(TARGDIR))\module\vendorapp rd /S /Q $(strip $(TARGDIR))\module\vendorapp) & \
			(move $(strip $(TARGDIR))\module\vendorapp_backup $(strip $(TARGDIR))\module\vendorapp) \
		)
  endif
endif

files_list:
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
   # -----------------------------
   # Duplicate custom dedicate files
   # -----------------------------
   # because the length of $(CUS_REL_FILES_LIST) may exceeds the DOS command limit,
   # use strcmpex.exe & lnitem.pl to dump $(CUS_REL_FILES_LIST)
	tools\strcmpex.exe crfl crfl e make\~crfl.tmp $(foreach file,$(CUS_REL_FILES_LIST),$(file))
	if exist $(WORK_DIR)\make\~crfl.tmp \
		(perl tools\lnitem.pl make\~crfl.tmp) & \
		(for /f %%i in (make\~crfl.tmp) do \
			(@echo copying file %%i) & \
			(if not exist "$(RELEASE_DIR)"\%%i \
				(md "$(RELEASE_DIR)"\%%i) & \
				(rd "$(RELEASE_DIR)"\%%i) & \
				(copy /y $(FIXPATH)\%%i "$(RELEASE_DIR)"\%%i) \
			) \
		)
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))

obj_list:
  # -----------------------------
  # Duplicate custom dedicate obj
  # -----------------------------
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))  
	tools\strcmpex.exe crol crol e make\~crol.tmp $(foreach obj,$(CUS_REL_OBJ_LIST),$(obj))
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
	perl mtk_tools\PartialCopy\copyFiles_PC.pl $(FIXPATH) "$(RELEASE_DIR)" "$(RELEASE_DIR)" $(strip $(CUS_REL_OBJ_LIST))
else
	perl tools\copyFiles.pl $(FIXPATH) "$(RELEASE_DIR)" $(strip $(CUS_REL_OBJ_LIST))
endif

ifdef WIFI_SUPPORT
ifneq ($(strip $(WIFI_SUPPORT)),NONE)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(FIXPATH)\wifi\lib\supc\supc_custom.lib \
		(if not exist "$(RELEASE_DIR)"\wifi\lib\supc \
		md "$(RELEASE_DIR)"\wifi\lib\supc) & \
		(copy /y $(FIXPATH)\wifi\lib\supc\supc_custom.lib "$(RELEASE_DIR)"\wifi\lib\supc\supc.lib )
	@if exist $(FIXPATH)\wifi\lib\supc\supc_wapi_custom.lib \
		(if not exist "$(RELEASE_DIR)"\wifi\lib\supc \
		md "$(RELEASE_DIR)"\wifi\lib\supc) & \
		(copy /y $(FIXPATH)\wifi\lib\supc\supc_wapi_custom.lib "$(RELEASE_DIR)"\wifi\lib\supc\supc_wapi.lib )

	@if exist $(FIXPATH)\wifi\lib\MT5921\MT5921_custom.lib \
		(if not exist "$(RELEASE_DIR)"\wifi\lib\MT5921 \
		md "$(RELEASE_DIR)"\wifi\lib\MT5921) & \
		(copy /y $(FIXPATH)\wifi\lib\MT5921\MT5921_custom.lib "$(RELEASE_DIR)"\wifi\lib\MT5921\MT5921.lib )
	@if exist $(FIXPATH)\wifi\lib\MT5921\MT5921_wapi_custom.lib \
		(if not exist "$(RELEASE_DIR)"\wifi\lib\MT5921 \
		md "$(RELEASE_DIR)"\wifi\lib\MT5921) & \
		(copy /y $(FIXPATH)\wifi\lib\MT5921\MT5921_wapi_custom.lib "$(RELEASE_DIR)"\wifi\lib\MT5921\MT5921_wapi.lib )
endif
endif
endif

filter_out:
ifeq ($(call Upper ,$(strip $(LEVEL))),VENDOR)

	echo .> ~customRemovalDir.tmp
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	  perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) TRUE TRUE ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE)
  else
	  if exist tools\traverseDir.pl perl tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) TRUE TRUE ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE)
	  if not exist tools\traverseDir.pl perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) TRUE TRUE ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE)
  endif
	del ~customRemovalDir.tmp  

else

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) $(CODE_REMOVAL_DIR_FILE) $(NOT_REMOVAL_DIR_FILE) TRUE
else
	echo .> ~customRemovalDir.tmp
  ifneq ($(strip $(DEMO_PROJECT)),TRUE)
		perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE)
  else
		perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE) TRUE
  endif
	del ~customRemovalDir.tmp
endif
else
ifeq ($(strip $(MTK_SUBSIDIARY)),FALSE)   
	echo .> ~customRemovalDir.tmp
  ifneq ($(strip $(DEMO_PROJECT)),TRUE)
		if exist tools\traverseDir.pl perl tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE)
		if not exist tools\traverseDir.pl perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE)
  else
		if exist tools\traverseDir.pl perl tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE) TRUE
		if not exist tools\traverseDir.pl perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp $(NOT_REMOVAL_DIR_FILE) TRUE
  endif
	del ~customRemovalDir.tmp
endif
endif

endif

gen_custom_dep:
# To get dependency file list for customer's source codes.
# Get source release components.
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB) \
		md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)
	@echo [BASE_CFG]>mtk_tools\hTogetherProcessor\htogether_file_collect_cfg.ini
	@echo PROJECT_FOLDER=.>>mtk_tools\hTogetherProcessor\htogether_file_collect_cfg.ini
	@echo MODULE=$(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def)))>>mtk_tools\hTogetherProcessor\htogether_file_collect_cfg.ini
	@echo REMOVE_H=verno.h bn_lcl.h>>mtk_tools\hTogetherProcessor\htogether_file_collect_cfg.ini
	@if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\tools md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\tools
	@perl mtk_tools\hTogetherProcessor\htogether_file_collect.pl mtk_tools\hTogetherProcessor\htogether_file_collect_cfg.ini $(RULESDIR) $(strip $(MAIN_LCD_SIZE)) "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\tools\copy_mmi_include_h.bat
endif

non_rel_files_list:

   # -----------------------------
   # Delete non-released files
   # -----------------------------
ifneq ($(strip $(NON_REL_FILES_LIST)),)
	tools\strcmpex.exe nrfl nrfl e make\~nrfl.tmp $(NON_REL_FILES_LIST)
	if exist $(FIXPATH)\make\~nrfl.tmp \
		(perl tools\lnitem.pl make\~nrfl.tmp) & \
		(for /f %%i in (make\~nrfl.tmp) do \
			(@echo deleting file %%i) & \
			(if exist "$(RELEASE_DIR)"\%%i \
				(del /Q $(strip "$(RELEASE_DIR)")\%%i) \
			) \
		)
endif

non_rel_dirs_list:

   # -----------------------------
   # Remove non-released folders
   # -----------------------------
ifneq ($(strip $(NON_REL_DIRS_LIST)),)
	tools\strcmpex.exe nrdl nrdl e make\~nrdl.tmp $(NON_REL_DIRS_LIST)
	if exist $(FIXPATH)\make\~nrdl.tmp \
		(perl tools\lnitem.pl make\~nrdl.tmp) & \
		(for /f %%i in (make\~nrdl.tmp) do \
			(@echo removing dir %%i) & \
			(if exist "$(RELEASE_DIR)"\%%i \
				(rd /S /Q $(strip "$(RELEASE_DIR)")\%%i) \
			) \
		)
endif

codegen_rel:
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
		@echo Release the header files of codegen
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
		tools\strcmpex.exe crfl_1 crfl_1 e make\~crfl_1.lis .\tst\database\msglog_db\custom_parse_db.c .\tst\database\msglog_db\app_parse_db.c
  else
		tools\strcmpex.exe crfl_1 crfl_1 e make\~crfl_1.lis .\tst\database\msglog_db\custom_parse_db.c
  endif
else
	tools\strcmpex.exe crfl_1 crfl_1 e make\~crfl_1.lis .\tst\database\msglog_db\custom_parse_db.c
endif
		perl tools\lnitem.pl make\~crfl_1.lis
		perl tools\req_hdr.pl make\~crfl_1.lis $(RULESDIR)\codegen.dep > make\~crfl_1.tmp
		(for /f %%k in (make\~crfl_1.tmp) do \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(@echo copying file %%k) & \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		)
		@echo release all the header files of codegen done!
  else
		@echo skip codegen header files Release for LIS !
  endif
else
	@echo skip codegen header files Release for BASIC !
endif

nvramautogen_rel:
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
	@echo Release the header files of nvram auto gen
	tools\strcmpex.exe crnvramautogen crnvramautogen e make\~crnvramautogen.lis $(CUS_REL_NVRAM_AUTO_GEN_PAR_SRC_LIST)
	perl tools\lnitem.pl make\~crnvramautogen.lis
	perl tools\req_hdr.pl make\~crnvramautogen.lis $(RULESDIR)\nvram_auto_gen.dep > make\~crnvramautogen.tmp
	(for /f %%k in (make\~crnvramautogen.tmp) do \
		(if not exist "$(RELEASE_DIR)"\%%k \
			(@echo copying file %%k) & \
			(md "$(RELEASE_DIR)"\%%k) & \
			(rd "$(RELEASE_DIR)"\%%k) & \
			(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
		) \
	)
	@echo release all the header files of nvram auto gen done!
else
	@echo skip nvram auto gen header files Release for UDVT !
endif
else
	@echo skip nvram auto gen header files Release for BASIC !
endif

resgen_rel:
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
	@echo Release the header files of resgen
	if exist $(RULESDIR)\resgen.dep \
	perl tools\copyDepFile.pl $(RULESDIR)\resgen.dep make "$(RELEASE_DIR)"
	@echo release all the header files of resgen done!
else
  ifneq ($(filter PLUTO_MMI COSMOS_MMI IOT_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
	@if not exist "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\obj md "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\obj
	@for %%i in (ResBytestream.o FontRes.o) do \
		(copy /y /z $(FIXPATH)\plutommi\Customer\ResGenerator\Debug\obj\mtk_resgenerator_core\%%i "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\obj\ >NUL)
	@if exist $(FIXPATH)\plutommi\Customer\debug\UCS2.o \
		(copy /y /z $(FIXPATH)\plutommi\Customer\debug\UCS2.o "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\obj\ >NUL)
	@if not exist "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\Inc md "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\Inc
	@copy /y /z $(FIXPATH)\plutommi\Customer\ResGenerator\Inc\ResgenDataType.h "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\Inc\ >NUL
	@copy /y /z $(FIXPATH)\plutommi\Customer\ResGenerator\resgen_xml_handle.py "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\ >nul
	@copy /y /z $(FIXPATH)\plutommi\Customer\ResGenerator\resgen_xml_copy.py "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\ >nul
	@copy /y /z $(FIXPATH)\plutommi\Customer\ResGenerator\resgen_xml_check.py "$(RELEASE_DIR)"\plutommi\VendorApp\ResGenerator\ >nul
  endif
endif

done:
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
   # -----------------------------
   # Generate custom.bld for use in custom release
   # -----------------------------
	@echo CUSTOM_RELEASE = TRUE > "$(RELEASE_DIR)"\make\Custom.bld
	@echo LEVEL = $(call Upper,$(LEVEL)) >> "$(RELEASE_DIR)"\make\Custom.bld
	perl .\tools\append2.pl $(strip $(FLASHFILE)) $(strip $(MEMORY_CFG)) $(strip $(THE_MF))>> "$(RELEASE_DIR)"\make\Custom.bld
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
	@echo CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def)))>> "$(RELEASE_DIR)"\make\Custom.bld
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def)))>> "$(RELEASE_DIR)"\make\Custom.bld
	@echo COMPLIST = $(CUS_REL_SRC_COMP) >> "$(RELEASE_DIR)"\make\Custom.bld
	@echo PARTIAL_COPY = TRUE >> "$(RELEASE_DIR)"\make\Custom.bld
endif


#	@echo COMP_TRACE_DEFS = $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def))) > $(INFOMAKELOG)
	@if exist $(INFOMAKELOG) del /Q $(WORK_DIR)\$(INFOMAKELOG)
	@perl tools\echoLongString3.pl $(INFOMAKELOG) COMP_TRACE_DEFS make\~trcdef.tmp
	@echo COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)
	@echo COMPOBJS = $(call sort, $(foreach def,$(COMPOBJS),$(def))) >> $(INFOMAKELOG)
#	@echo CUS_REL_BASE_COMP = $(call sort, $(foreach def,$(CUS_REL_BASE_COMP),$(def))) >> $(INFOMAKELOG)
	@perl tools\echoLongString3.pl $(INFOMAKELOG) CUS_REL_BASE_COMP make\~base.tmp
	@echo CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_PAR_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def))) >> $(INFOMAKELOG)
#	@echo CUS_REL_FILES_LIST = $(call sort, $(foreach def,$(CUS_REL_FILES_LIST),$(def))) >> $(INFOMAKELOG)
	@perl tools\echoLongString3.pl $(INFOMAKELOG) CUS_REL_FILES_LIST make\~crfl.tmp
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
	@tools\strcmpex.exe def def e make\~remove.tmp ALL_CUS_REL_PAR_SRC_COMP = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),$(CUS_REL_$(comp)_PAR_SRC_LIST))
	@type make\~remove.tmp >> $(INFOMAKELOG)
endif

	@if exist $(WORK_DIR)\make\~remove.tmp del /Q $(WORK_DIR)\make\~remove.tmp
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)
	@echo MODIS_DIS_LIBS = $(call sort, $(foreach def,$(MODIS_DIS_LIBS),$(def))) >> $(INFOMAKELOG)
	@echo MODIS_EN_LIBS = $(call sort, $(foreach def,$(MODIS_EN_LIBS),$(def))) >> $(INFOMAKELOG)
	@echo MODIS_MTK_LIBS = $(call sort, $(foreach def,$(MODIS_MTK_LIBS),$(def))) >> $(INFOMAKELOG)
	@echo MODIS_EN_OBJS = $(strip $(MODIS_EN_OBJS)) >> $(INFOMAKELOG)
	@echo MODIS_MODE = $(strip $(MODIS_MODE)) >> $(INFOMAKELOG)
	@perl tools\echoLongString3.pl $(INFOMAKELOG) CUS_REL_OBJ_LIST make\~crol.tmp
	@perl tools\echoLongString3.pl $(INFOMAKELOG) NON_REL_FILES_LIST make\~nrfl.tmp
	@perl tools\echoLongString3.pl $(INFOMAKELOG) NON_REL_DIRS_LIST make\~nrdl.tmp
	@echo LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@echo VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@echo CUS_REL_OPTION_FILTER = $(strip $(CUS_REL_OPTION_FILTER)) >> $(INFOMAKELOG)
	@echo CUS_REL_HISTORY_FILTER = $(strip $(CUS_REL_HISTORY_FILTER)) >> $(INFOMAKELOG)
	@echo EN_DEF_FILE = $(strip $(EN_DEF_FILE)) >> $(INFOMAKELOG)
	@echo DIS_DEF_FILE = $(strip $(DIS_DEF_FILE)) >> $(INFOMAKELOG)
#	@echo RELEASE_DIR = $(strip "$(RELEASE_DIR)") >> $(INFOMAKELOG)
ifeq ($(strip $(PARTIAL_COPY)),TRUE)
	@echo RELEASE_DIR = $(strip "$(RELEASE_DIR)") >> $(INFOMAKELOG)
else
	@perl tools\getRelDir.pl $(strip "$(RELEASE_DIR)") >> $(INFOMAKELOG)
endif
	@echo CUS_MTK_LIB = $(strip $(CUS_MTK_LIB)) >> $(INFOMAKELOG)
ifeq ($(strip $(DUMMYVM)),TRUE)
	@echo DUMMYVM = $(strip $(DUMMYVM)) >> $(INFOMAKELOG)
endif
	@echo CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@echo MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)
ifdef MODULE
ifneq ($(strip $(call Upper,$(MODULE))),MULTICUSTOMRELEASE)
	@echo SINGLEMODULE = $(strip $(MODULE))>> $(INFOMAKELOG)
endif
endif
ifneq ($(strip $(SWITCH_FOLDER)),)
	@echo SWITCH_FOLDER = $(strip $(SWITCH_FOLDER))>> $(INFOMAKELOG)
endif
   # -----------------------------
   # Clean third party files
   # -----------------------------
ifneq ($(strip $(PARTIAL_COPY)),TRUE)     
	@if exist "$(RELEASE_DIR)"\tools\make.exe (del "$(RELEASE_DIR)"\tools\make.exe)
	@if exist "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\7za.exe \
		(del "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\7za.exe)
	@if exist "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\7za.exe \
		(del "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\7za.exe)
	@if exist "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\convert.exe \
		(del "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\convert.exe)
	@if exist "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\convert.exe \
		(del "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\convert.exe)
	@if exist "$(RELEASE_DIR)"\tools\MSYS (rd /s /q "$(RELEASE_DIR)"\tools\MSYS)
	@if exist "$(RELEASE_DIR)"\tools\MinGW (rd /s /q "$(RELEASE_DIR)"\tools\MinGW)
endif

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),HI_VM)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h)
endif
endif

   # -----------------------------
   # Clean temporary files in make directory
   # -----------------------------
	@echo Cleaning make\~*.tmp files ...
	@if exist make\~existtrc.tmp \
		(copy make\~existtrc.tmp make\~existtrc.multi)
	@if exist $(WORK_DIR)\make\~*.tmp \
		(del /q "$(WORK_DIR)"\make\~*.tmp)
	@if exist $(WORK_DIR)\~*.tmp \
		(del /q "$(WORK_DIR)"\~*.tmp)

	@echo Cleaning build\$(CUSTOMER)\module\~*.lis files ...
	@if exist $(WORK_DIR)\build\$(CUSTOMER)\module\~*.lis \
		(del /q "$(WORK_DIR)"\build\$(CUSTOMER)\module\~*.lis)

	@echo Done.
	@if /I "$(strip $(PARTIAL_COPY))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_PC_TIME_TMP))
ckcr: ck3rdptylic
	@echo Checking Custom release script ...
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo RELEASE_PACKAGE=$(RELEASE_PACKAGE)>$(RELPKG_LOG)
	@echo CUS_REL_SRC_COMP=$(CUS_REL_SRC_COMP)>>$(RELPKG_LOG)
	@echo CUS_REL_PAR_SRC_COMP=$(CUS_REL_PAR_SRC_COMP)>>$(RELPKG_LOG)
	@echo CUS_REL_MTK_COMP=$(CUS_REL_MTK_COMP)>>$(RELPKG_LOG)
endif
	@echo Custom release script was checked.


ck3rdptylic:
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
		@if exist tools\Feat2Mod.ini \
			(@perl tools\3rdPartiesLicChk.pl $(strip $(THE_MF)) "" tools\Feat2Mod.ini "$(strip $(CUS_REL_SRC_COMP))" "$(strip $(CUS_REL_PAR_SRC_COMP))" "$(strip $(CUS_REL_MTK_COMP))") \
		else \
			(@echo warning:  tools\Feat2Mod.ini does NOT exist, skip 3rd party feature's srouce release level license check!!!) & \
			(@perl tools\3rdPartiesLicChk.pl $(strip $(THE_MF)) "")
  else
		@echo Skip 3rd party feature license check for internal demo projects!!!
  endif
else
	@echo Skip 3rd party feature license check for custom release projects!!!
endif

check_obj:
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifneq ($(strip $(PARTIAL_COPY)),TRUE)
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
  ifneq ($(strip $(CUS_REL_MTK_COMP)),)
    ifdef MODULE
      ifneq ($(strip $(call Upper,$(MODULE))),MULTICUSTOMRELEASE)
      else
        # Check if source path is under the must-be-released folders.
				tools\strcmpex.exe objfile objfile e make\~objfile.tmp $(foreach file,$(MTK_LIS_FILE),$(file))
				@perl tools\checkObjFilePath.pl $(FIXPATH) "$(RELEASE_DIR)" make\~objfile.tmp make\~base.tmp "$(strip $(CUS_REL_SRC_COMP))" "$(strip $(CUS_REL_PAR_SRC_COMP))" make\OBJ_CHECK_EXCLUDE_FILE.def $(strip $(RELEASE_PACKAGE))
      endif
    else
      # Check if source path is under the must-be-released folders.
			tools\strcmpex.exe objfile objfile e make\~objfile.tmp $(foreach file,$(MTK_LIS_FILE),$(file))
			@perl tools\checkObjFilePath.pl $(FIXPATH) "$(RELEASE_DIR)" make\~objfile.tmp make\~base.tmp "$(strip $(CUS_REL_SRC_COMP))" "$(strip $(CUS_REL_PAR_SRC_COMP))" make\OBJ_CHECK_EXCLUDE_FILE.def $(strip $(RELEASE_PACKAGE))
    endif
  endif
endif
endif
endif

clean_temp:
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
ifeq ($(call Upper,$(strip $(LEVEL))),LEVEL2_SRC)
	if exist "$(RELEASE_DIR)"\verno (rd /s /q "$(RELEASE_DIR)"\verno)
	if exist "$(RELEASE_DIR)"\make\custom ( \
		move "$(RELEASE_DIR)"\make\custom\custom.mak "$(RELEASE_DIR)"\make\custom.mak.tmp && \
		del /Q "$(RELEASE_DIR)"\make\custom\*.* && \
		move "$(RELEASE_DIR)"\make\custom.mak.tmp "$(RELEASE_DIR)"\make\custom\custom.mak \
	)
	if exist "$(RELEASE_DIR)"\plutommi\Customer\Audio\PLUTO\audio.zip ( \
		move "$(RELEASE_DIR)"\plutommi\Customer\Audio\PLUTO\audio.zip "$(RELEASE_DIR)"\plutommi\Customer\Audio\audio.zip.tmp && \
		rd /S /Q "$(RELEASE_DIR)"\plutommi\Customer\Audio\PLUTO && \
		md "$(RELEASE_DIR)"\plutommi\Customer\Audio\PLUTO && \
		move "$(RELEASE_DIR)"\plutommi\Customer\Audio\audio.zip.tmp "$(RELEASE_DIR)"\plutommi\Customer\Audio\PLUTO\audio.zip \
	)
endif
endif
