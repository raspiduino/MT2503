# *************************************************************************
# Initialization
# *************************************************************************
MODIS_DIS_LIBS = 
MODIS_EN_LIBS = 
MODIS_MTK_LIBS = 
MODIS_EN_OBJS =
MODIS_DIS_INC_PATH = 
MODIS_EN_INC_PATH = 
MODIS_DIS_OPTION = 
MODIS_EN_OPTION = 

# *************************************************************************
# Folder Structure Config
# *************************************************************************
VSCommonDir := C:\Program Files\Microsoft Visual Studio 9.0\Common7
MSVCDir := C:\Program Files\Microsoft Visual Studio 9.0\VC
VcOsDir := WINNT
FrameworkDir := C:\WINDOWS\Microsoft.NET\Framework
WindowsSDKDir := C:\Program Files\\Microsoft SDKs\Windows\v6.0A

MODIS_SUFFIX :=
MODIS_UESIM := MoDIS

MODISDIR := MoDIS_VC9
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  MODISLOGDIR := $(strip $(MODISDIR))\_BUILD_LOG
  RULESDIR := $(strip $(MODISDIR))\_BUILD_DEP
  NEED_BUILD_BOOTLOADER := FALSE
  REDUCE_HEADER_DEPTH := FALSE
endif

# *************************************************************************
# MODULE Config
# *************************************************************************
MODIS_DIS_LIBS += ata bootloader bootloader_ext dp_engine dp_engine16 drv dsp_ram fdm fdm_bl fota
MODIS_DIS_LIBS += wndrv dummy_supc ll1
MODIS_DIS_LIBS += l1 l1_ext l1_2 l1_classb l1_classb_2 l1_g2 l1_classb_g2 l1_classb_umts l1audio l1audio_sp l1audio32 l1d_lp1 l1d_lp2 l1d_lp3 l1d_lp5 l1d_lp6 l1d_lp7 l1d_lp8
MODIS_DIS_LIBS += nucleus nucleus_critical_data nucleus_ctrl_code nucleus_debug
MODIS_DIS_LIBS += nucleus_v2 nucleus_v2_critical_data nucleus_v2_ctrl_code nucleus_v2_debug
MODIS_DIS_LIBS += nucleus_int nucleus_v2_int rompatch romsa usb
MODIS_DIS_LIBS += dhcp
MODIS_DIS_LIBS += drv_display drv_tp btmt ssf ft bmt fta ftc
MODIS_DIS_LIBS += l1audio_secure l1audio_fc
MODIS_DIS_LIBS += ast_l1_ast1001 ast_l1_ast2001 ast_l1_ast3001
MODIS_DIS_LIBS += audio audio32 mtd
MODIS_DIS_LIBS += sim_driver
MODIS_DIS_LIBS += peripheral
MODIS_DIS_LIBS += hostap mc usb_driver
MODIS_DIS_LIBS += mt5921 mt5921_wapi mt5931 mt5931_wapi
# setting for tiny system
MODIS_DIS_LIBS += $(TS_COMPLIST)

MODIS_EN_LIBS += comm drv_sim oscar lcd_c_model
MODIS_EN_LIBS += fs

MODIS_EN_LIBS += modis

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  MODIS_EN_LIBS += p2p_modis
endif

ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    ifeq ($(call Upper,$(strip $(LEVEL))),VENDOR)
      MODIS_MTK_LIBS += modis_lcd
    else
      MODIS_EN_LIBS += modis_lcd
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(LEVEL))),VENDOR)
  MODIS_MTK_LIBS += comm drv_sim lcd_c_model fs
else
  MODIS_EN_LIBS += comm drv_sim lcd_c_model fs
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  MODIS_EN_LIBS += oscar
else ifneq ($(findstring REL_SUB_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
  MODIS_EN_LIBS += oscar
else
  MODIS_MTK_LIBS += oscar
endif

ifneq ($(filter MT6236 MT6236B MT6276_S01 MT6255,$(strip $(COM_DEFS))),)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
    MODIS_EN_LIBS += gfx_hw_c_model
  else
    MODIS_MTK_LIBS += gfx_hw_c_model
  endif
endif

# MTE plugin
ifeq ($(strip $(MODIS_PLUGIN)),ENABLE)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
    MODIS_EN_LIBS += plugin
  else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    MODIS_EN_LIBS += plugin
  else
    MODIS_MTK_LIBS += plugin
  endif
  MODIS_EN_OPTION += __MODIS_PLUGIN__
  MODIS_COPY_DIR += $(strip $(MODISDIR))\plugin\dll,$(strip $(MODISDIR))\MoDIS\plugin
endif

ifdef J2ME_SUPPORT
  ifeq ($(strip $(J2ME_SUPPORT)),IJET)
    ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
      MODIS_EN_LIBS += j2me_11
    endif
    ifeq ($(strip $(J2ME_VM)),KVM)
      MODIS_MTK_LIBS += j2me_11
    endif
    ifeq ($(strip $(J2ME_VM)),KVM_KDWP_SOURCE)
      MODIS_EN_LIBS += j2me_11_kdwp
    endif
    ifeq ($(strip $(J2ME_VM)),KVM_KDWP)
      MODIS_MTK_LIBS += j2me_11_kdwp
    endif
    ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
      MODIS_DIS_LIBS += j2me_hi
      MODIS_EN_LIBS += j2me_hi_i386
    endif
    ifeq ($(strip $(J2ME_VM)),HI_VM)
      MODIS_DIS_LIBS += j2me_hi
      MODIS_MTK_LIBS += j2me_hi_i386
    endif
  else ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
    ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_FULL)
      MODIS_EN_LIBS += j2me_nemo j2me_nemo_cldc_i386 j2me_nemo_fdlibm_i386
    else ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_NORMAL)
      MODIS_EN_LIBS += j2me_nemo
      MODIS_MTK_LIBS += j2me_nemo_cldc_i386 j2me_nemo_fdlibm_i386
    else
      MODIS_MTK_LIBS += j2me_nemo j2me_nemo_cldc_i386 j2me_nemo_fdlibm_i386
    endif
  else ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
      MODIS_EN_OBJS += j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_win32_msvc.lib
      MODIS_EN_OBJS += j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.lib
      MODIS_EN_OBJS += j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.lib
  else ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
      MODIS_EN_OBJS += j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\ajsc_win32_msvc.lib
      MODIS_EN_OBJS += j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libmjb2.lib
      MODIS_EN_OBJS += j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.lib
  else ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
      #JAVA_DEF.mak
  else ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
      #JAVA_DEF.mak
  else ifeq ($(strip $(J2ME_SUPPORT)),NONE)
      #JAVA_DEF.mak
  endif
endif

# *************************************************************************
# INCLUDE PATH Config
# *************************************************************************
# auto_header.h
MODIS_EN_INC_PATH += $(strip $(MODISDIR))
MODIS_EN_INC_PATH += kal\oscar\include
MODIS_EN_INC_PATH += $(strip $(MODISDIR))\oscar\include
MODIS_EN_INC_PATH += tst\database_$(strip $(MODIS_UESIM))\pstrace_db

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  MODIS_EN_INC_PATH += $(strip $(MODISDIR))\p2p_modis
endif

MODIS_DIS_INC_PATH += c:\progra~1\arm\adsv1_2\include
MODIS_DIS_INC_PATH += nucleus\inc
MODIS_DIS_INC_PATH += kal\nucleus\include
MODIS_DIS_INC_PATH += nucleus_ma\inc
MODIS_DIS_INC_PATH += C:\Progra~1\ARM\RVCT\Data\2.1\328\include
MODIS_DIS_INC_PATH += tst\database\pstrace_db
MODIS_DIS_INC_PATH += tst\database_classb\pstrace_db
MODIS_DIS_INC_PATH += tst\database_classb_umts\pstrace_db

# *************************************************************************
# COMPILE OPTION Config
# *************************************************************************
MODIS_DIS_OPTION += __HW_CHE__ __HW_DIVIDER__ __MULTI_BOOT__ _DEBUG
MODIS_DIS_OPTION += __ROMSA_SUPPORT__ __USB_ENABLE__ __USB_LOGGING__ 
MODIS_DIS_OPTION += KAL_ON_NUCLEUS L1_CATCHER MTK_KAL_MNT __MTK_TARGET__ WEBCAM_SUPPORT
MODIS_DIS_OPTION += KAL_ON_THREADX
MODIS_DIS_OPTION += VRSI_ENABLE __NVRAM_IN_USB_MS__ _USB_VBUS_DETECT_WITH_NIRQ_ __ENABLE_USB_IN_META__ 
MODIS_DIS_OPTION += __USB_IN_NORMAL_MODE__
MODIS_DIS_OPTION += __MTK_SECURE_PLATFORM__ __SECURITY_OTP__
MODIS_DIS_OPTION += __USB_IN_NORMAL_MODE_IMPROVE__ __ENABLE_USB_IN_META__ __OTG_ENABLE__ __USB_MULTI_CHARGE_CURRENT__
MODIS_DIS_OPTION += __SECURE_RO_ENABLE__ _DM_OMADL_VIA_DLAGENT_ __ARM9_DCACHEABLE__
MODIS_DIS_OPTION += __DYNAMIC_SWITCH_CACHEABILITY__
MODIS_DIS_OPTION += __TST_LMU_LOGGING__ __TST_DCC_ENABLED__ __TST_DNT_LOGGING__
MODIS_DIS_OPTION += __LANDSCAPE_UI_ON_PORTRAIT_LCM__
MODIS_DIS_OPTION += __KEYPAD_DEBUG_TRACE__ __KAL_RECORD_BOOTUP_LOG__ __USB_COM_PORT_ENABLE__ MODULE_TRACE_OFF
MODIS_DIS_OPTION += __LCM_SCANLINE_ROTATION_SUPPORT__
MODIS_DIS_OPTION += __MAIN_LCM_SCANLINE_ROTATION_90__ __MAIN_LCM_SCANLINE_ROTATION_270__
MODIS_DIS_OPTION += __SUB_LCM_SCANLINE_ROTATION_90__ __SUB_LCM_SCANLINE_ROTATION_270__
MODIS_DIS_OPTION += DCM_MM_IMEHW_SUPPORT __MM_DCM_SUPPORT__ __IMEHW_DCM_SUPPORT__
MODIS_DIS_OPTION += __GPS_AT_SUPPORT__ __GPS_ADAPTOR_SUPPORT__ __LONG_AT_CMD_SUPPORT__

MODIS_EN_OPTION += DUMMYL1 L1_NOT_PRESENT KAL_ON_OSCAR UNIT_TEST 
MODIS_EN_OPTION += __OSCAR_ON_WIN32__ MAL1_NOT_PRESENT _WIN32_DCOM
MODIS_EN_OPTION += _MODIS_ON_VC9_

ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  MODIS_EN_OPTION += __CSMCC_UT__
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    MODIS_EN_OPTION += __TCM_UT__ __SM_UT__ __RATDM_UT__ __PPP_UT__ __RRCE_UT__
  endif
endif

# special for AST projects
ifeq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
  MODIS_EN_OPTION += __DUMMY_TL1__
endif

ifeq ($(strip $(MCARE_SUPPORT)),TRUE)
    #MODIS_EN_OBJS += vendor\mcare\engine\Win32\tencentmcarev31.lib
    #MODIS_MTK_OBJS += vendor\mcare\engine\Win32\tencentmcarev31.lib
    #MODIS_DIS_LIBS += tencentmcarev31adp
    MODIS_EN_OPTION += __MCARE_ON_MODIS__
    MODIS_DIS_OPTION += __MCAREV31__ __MCARE_COMMON__ __MCARE_QQBROWSER__
endif

# *************************************************************************
# Cleanroom library
# *************************************************************************
ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  ifeq ($(strip $(VENDOR)),NONE)
    MODIS_MODE_DEFAULT := Debug
  else
    MODIS_MODE_DEFAULT := Release
  endif
else
    MODIS_MODE_DEFAULT := Release
endif
ifndef MODIS_MODE
  MODIS_MODE := $(MODIS_MODE_DEFAULT)
endif

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  CUS_MODIS_LIB := MoDIS_LIB
else
  CUS_MODIS_LIB := $(subst MTK_LIB\,MoDIS_LIB\,$(strip $(call Upper,$(CUS_MTK_LIB))))
endif

ifeq ($(strip $(TTL_SUPPORT)),SOURCE)
else
  #ttl.lib is a must-be-linked library.
  MODIS_MTK_LIBS += ttl
endif

ifeq ($(strip $(DRM_SUPPORT)),BSCI)
  MODIS_MTK_LIBS += bsci
endif

# *************************************************************************
# Third party library
# *************************************************************************
ifdef INPUT_METHOD
  ifneq ($(strip $(INPUT_METHOD)),NONE)
  ifndef INPUT_METHOD_BASE
#   $(error INPUT_METHOD_BASE should be defined in Option.mak)
  endif
  endif
ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V1)
  MODIS_EN_OBJS += vendor\InputMethod\GUOBI\project\$(strip $(INPUT_METHOD_BASE))\v1_demo\lib\guobi.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2)
  MODIS_EN_OBJS += vendor\InputMethod\GUOBI\project\plutommi\v5_2_demo\lib\_libGBEngine_.lib
  CUS_REL_OBJ_LIST += vendor\InputMethod\GUOBI\project\plutommi\v5_2_demo\lib\_libGBEngine_.lib
endif

ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_SLIM)
  MODIS_EN_OBJS += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
  CUS_REL_OBJ_LIST += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_0K_SLIM)
  MODIS_EN_OBJS += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
  CUS_REL_OBJ_LIST += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_5K_SLIM)
  MODIS_EN_OBJS += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
  CUS_REL_OBJ_LIST += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_GUOBI_V5_2_10K_SLIM)
  MODIS_EN_OBJS += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
  CUS_REL_OBJ_LIST += vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\lib\_libGBEngine_.lib
endif

ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_FULL)
  MODIS_EN_OBJS += vendor\search_engine\GUOBI\winguo\project\full\lib\_SmartDial_.lib \
                   vendor\search_engine\GUOBI\winguo\project\full\lib\winguo_v4package.lib
endif

ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_SLIM)
  MODIS_EN_OBJS += vendor\search_engine\GUOBI\winguo\project\slim\lib\_SmartDial_.lib \
                   vendor\search_engine\GUOBI\winguo\project\slim\lib\winguo_v4package.lib
  CUS_REL_OBJ_LIST += vendor\search_engine\GUOBI\winguo\project\slim\lib\_SmartDial_.lib
  CUS_REL_OBJ_LIST += vendor\search_engine\GUOBI\winguo\project\slim\lib\winguo_v4package.lib
endif

ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_ULTRA_SLIM)
  MODIS_EN_OBJS +=    vendor\search_engine\GUOBI\winguo\project\ultra_slim\lib\winguo_v4package.lib
  CUS_REL_OBJ_LIST += vendor\search_engine\GUOBI\winguo\project\ultra_slim\lib\winguo_v4package.lib
endif

ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_SLIM_V2)
  MODIS_EN_OBJS += vendor\search_engine\GUOBI\winguo_v2\lib\_SmartDial_.lib \
                   vendor\search_engine\GUOBI\winguo_v2\lib\winguo_smd.lib
  CUS_REL_OBJ_LIST += vendor\search_engine\GUOBI\winguo_v2\lib\_SmartDial_.lib
  CUS_REL_OBJ_LIST += vendor\search_engine\GUOBI\winguo_v2\lib\winguo_smd.lib
endif

ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
  MODIS_EN_OBJS += vendor\InputMethod\zi\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib_modis.lib \
                   vendor\InputMethod\zi\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zishape_modis.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V6)
  MODIS_EN_OBJS += vendor\InputMethod\zi\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib_modis.lib \
                   vendor\InputMethod\zi\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8ARShape_modis.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
  MODIS_EN_OBJS += vendor\InputMethod\zi\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib_modis.lib \
                   vendor\InputMethod\zi\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zishape_modis.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
  ifeq ($(strip $(COMPILER)),RVCT)
    MODIS_EN_OBJS += vendor\InputMethod\t9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\T9RelVCChin_modis.obj
  else
    MODIS_EN_OBJS += vendor\InputMethod\t9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\T9RelVCChin_modis.obj
  endif
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_T9_ALPHA)
  ifeq ($(strip $(COMPILER)),RVCT)
    MODIS_EN_OBJS += vendor\InputMethod\t9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\T9RelVCAlpha_MoDIS.obj
  endif
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7_4)
  ifeq ($(strip $(COMPILER)),RVCT)
    MODIS_EN_OBJS += vendor\InputMethod\t9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\T9RelVCChin_modis.obj
  else
    MODIS_EN_OBJS += vendor\InputMethod\t9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\T9RelVCChin_modis.obj
  endif
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_XT9)
  MODIS_EN_OBJS += vendor\InputMethod\t9\project\$(strip $(INPUT_METHOD_BASE))\xt9\lib\xt9.obj
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_FULL)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\free_full\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_0K)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\free_slim_0K\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_5K)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\free_slim_5K\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_10K)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\free_slim_10K\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_SLIM1)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\v2_slim1\lib\kmxime_modis.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_SLIM2)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\v2_slim2\lib\kmxime_modis.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM1)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\eastern_euro_slim1\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM2)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\eastern_euro_slim2\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\v2_official\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
  MODIS_EN_OBJS += vendor\InputMethod\cstar\v2_demo\lib\kmxime_MoDIS.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_KOMOXO)
  MODIS_EN_OBJS += vendor\InputMethod\Komoxo\lib\kmxsip_input_Modis.lib
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_KOMOXO_DEMO)
  MODIS_EN_OBJS += vendor\InputMethod\Komoxo\lib_demo\kmxsip_input_Modis.lib
endif
endif

ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
  ifeq ($(strip $(COMPILER)),RVCT)
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.lib \
                     vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.lib \
                     vendor\handwriting\hanwang\v1_official\lib\thaihw.lib \
                     vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.lib
  else
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
        MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_official\lib\hw_sc.lib
      else
        MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_official\lib\hws.lib
      endif
    else
      MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_official\lib\hws.lib
    endif
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_official\lib\thaihw.lib
  endif
endif
ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO)
  ifeq ($(strip $(COMPILER)),RVCT)
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.lib
  else
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\thaihw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\arabichw.lib
  endif
endif
ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO_SLIM)
  ifeq ($(strip $(COMPILER)),RVCT)
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw_slim.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.lib
  else
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\thaihw.lib
    MODIS_EN_OBJS += vendor\handwriting\hanwang\v1_demo\lib\arabichw.lib
  endif
endif

ifeq ($(strip $(HAND_WRITING)),MMI_GUOBI_HW_SC_SLIM)
    MODIS_EN_OBJS += vendor\handwriting\guobi\v1\lib\guobi_hw.lib
endif
ifeq ($(strip $(HAND_WRITING)),MMI_GUOBI_HW_STANDARD)
    MODIS_EN_OBJS += vendor\handwriting\guobi\v1\lib\guobi_hw.lib
endif

ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
  MODIS_EN_OBJS += vendor\handwriting\penpower\v1_official\lib\MediaTek_Hwre.lib
  MODIS_EN_OBJS += vendor\handwriting\penpower\v1_official\lib\MTK_PPhrase_WIN.lib
endif
ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER_DEMO)
  ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    MODIS_EN_OBJS += vendor\handwriting\penpower\v1_demo\lib\MediaTek_Hwre_demo.lib
  endif
endif
ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
  ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    MODIS_EN_OBJS += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_MODIS.lib
    MODIS_EN_OBJS += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_MODIS.lib
    MODIS_EN_OBJS += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_MODIS.lib
  endif
endif

ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
  MODIS_EN_OBJS += vendor\game_engine\brogent\engine_v1\pc\mini_bgl.lib \
                   vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\pc\bgt_ggr2_optimize.lib \
                   vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\pc\bgt_hb2_utils.lib
endif

# not supported
ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
  # 3D game engine
  MODIS_EN_OBJS += vendor\game_engine\intergrafx\engine_v1\pc\$(strip $(MAIN_LCD_SIZE))\ignitem3g.lib \
                   vendor\game_engine\intergrafx\engine_v1\pc\$(strip $(MAIN_LCD_SIZE))\ignitemath.lib \
                   vendor\game_engine\intergrafx\engine_v1\pc\$(strip $(MAIN_LCD_SIZE))\libpng.lib
  # 3D game: petfish
  MODIS_EN_OBJS += vendor\game_engine\intergrafx\game\petfish\$(strip $(MAIN_LCD_SIZE))\modis\fish.obj \
                   vendor\game_engine\intergrafx\game\petfish\$(strip $(MAIN_LCD_SIZE))\modis\fishmenu.obj \
                   vendor\game_engine\intergrafx\game\petfish\$(strip $(MAIN_LCD_SIZE))\modis\gamemain.obj \
                   vendor\game_engine\intergrafx\game\petfish\$(strip $(MAIN_LCD_SIZE))\modis\ig_demogame.obj \
                   vendor\game_engine\intergrafx\game\petfish\$(strip $(MAIN_LCD_SIZE))\modis\logo.obj \
                   vendor\game_engine\intergrafx\game\petfish\$(strip $(MAIN_LCD_SIZE))\modis\utility.obj
  # 3D game: rollingball
  MODIS_EN_OBJS += vendor\game_engine\intergrafx\game\rollingball\$(strip $(MAIN_LCD_SIZE))\modis\ig_rollingball_$(strip $(MAIN_LCD_SIZE)).obj \
                   vendor\game_engine\intergrafx\game\rollingball\$(strip $(MAIN_LCD_SIZE))\modis\ig_rotation_$(strip $(MAIN_LCD_SIZE))_input.obj \
                   vendor\game_engine\intergrafx\game\rollingball\$(strip $(MAIN_LCD_SIZE))\modis\ig_rotation_main_$(strip $(MAIN_LCD_SIZE)).obj \
                   vendor\game_engine\intergrafx\game\rollingball\$(strip $(MAIN_LCD_SIZE))\modis\ig_rotation_title_$(strip $(MAIN_LCD_SIZE)).obj
endif

ifdef SW_FLASH
  ifneq ($(strip $(SW_FLASH)),NONE)
    ifneq ($(filter swflash,$(strip $(COMPLIST))),)
      MODIS_EN_OBJS += vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_WIN32_MTK.lib \
                       vendor\swflash\$(strip $(SW_FLASH))\v1_official\zdd2_1_lib.lib
    endif
  endif
endif

# NMC
ifeq ($(strip $(NMC_SUPPORT)),TRUE)
  MODIS_EN_OBJS += vendor\nmc\corelib\modis\nmccore.lib
endif

# Mobile Video
ifeq ($(strip $(MOBILE_VIDEO_SUPPORT)),WONDER)
  MODIS_EN_OBJS += vendor\mobilevideo\corelib\modis\MTK_CM_MobileVideo.lib
endif

# Language Learning feature
ifdef LANGLN_ENGINE
  ifneq ($(strip $(LANGLN_ENGINE)),NONE)
    MODIS_EN_OBJS += vendor\langlearn\digidea\engine_01\dzdpc.lib
  endif
endif

# Font Engine feature
ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    # txt file in MODIS_EN_OBJS will treat each line in it as an object
    MODIS_EN_OBJS += plutommi\Customer\ResGenerator\vf_modis_obj.txt
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
    MODIS_EN_OBJS += vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE_DEMO)
    MODIS_EN_OBJS += vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
    MODIS_EN_OBJS += vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
    MODIS_EN_OBJS += vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_KOMOXO)
    MODIS_EN_OBJS += vendor\vectorfont\komoxo\lib\scripteasy.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\komoxo\lib\scripteasy.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_KOMOXO_DEMO)
    MODIS_EN_OBJS += vendor\vectorfont\komoxo\lib_demo\scripteasy.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\komoxo\lib_demo\scripteasy.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_ETRUMP)
    MODIS_EN_OBJS += vendor\vectorfont\etrump\lib\win32\et_common.win32_mtk.lib
    MODIS_EN_OBJS += vendor\vectorfont\etrump\lib\win32\ft2_mini_noac.win32_mtk.lib
    MODIS_EN_OBJS += vendor\vectorfont\etrump\lib\win32\ottab.win32_mtk.lib
    MODIS_EN_OBJS += vendor\vectorfont\etrump\lib\win32\textlayout.win32_mtk.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\etrump\lib\win32\et_common.win32_mtk.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\etrump\lib\win32\ft2_mini_noac.win32_mtk.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\etrump\lib\win32\ottab.win32_mtk.lib
    CUS_REL_OBJ_LIST += vendor\vectorfont\etrump\lib\win32\textlayout.win32_mtk.lib
  endif
endif

# SVG features
ifneq ($(filter IKIVO_SVG,$(strip $(COM_DEFS))),)
  MODIS_EN_OBJS += vendor\svg\ikivo\engine_v1\ikivo_svglib_modis.lib
endif
ifneq ($(filter IKIVO_SVG_SCRIPT_ENGINE,$(strip $(COM_DEFS))),)
  MODIS_EN_OBJS += vendor\svg\ikivo\engine_v1\ikivo_script_engine_modis.lib
endif

# Opera features
ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
  MODIS_EN_OBJS += vendor\opera\browser\v1_official\lib\win32\opera.lib \
                   vendor\opera\browser\v1_official\lib\win32\ulldvrm.obj
endif
ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_TURBO)
  MODIS_EN_OBJS += vendor\opera\browser\v11_official\lib\win32\libfucus.lib
  MODIS_EN_OBJS += vendor\opera\browser\v11_official\lib\win32\libopera.lib
  MODIS_COPY_FILE += vendor\opera\browser\v11_official\lib\win32\libopera.dll,$(strip $(MODISDIR))\MoDIS\Debug\libopera.dll
  MODIS_COPY_FILE += vendor\opera\browser\v11_official\lib\win32\libopera.dll,$(strip $(MODISDIR))\MoDIS\Release\libopera.dll
  CUS_REL_FILES_LIST += vendor\opera\browser\v11_official\lib\win32\libfucus.lib
  CUS_REL_FILES_LIST += vendor\opera\browser\v11_official\lib\win32\libopera.lib
  CUS_REL_FILES_LIST += vendor\opera\browser\v11_official\lib\win32\libopera.dll
endif

# KURO_SUPPORT
ifdef KURO_SUPPORT
  ifneq ($(strip $(KURO_SUPPORT)),NONE)
    MODIS_EN_OBJS += vendor\player\ipeer\lib\MODIS\libkuro.lib \
                     vendor\player\ipeer\lib\MODIS\libkurodep.lib
  endif
endif

# SCALADO_SUPPORT
ifdef SCALADO_SUPPORT
  ifeq ($(strip $(SCALADO_SUPPORT)),TRUE)
    MODIS_EN_OBJS += vendor\scalado\lib\WIN32\baseapi.lib \
                     vendor\scalado\lib\WIN32\capseng.lib \
                     vendor\scalado\lib\WIN32\codecs.lib \
                     vendor\scalado\lib\WIN32\excodecs.lib \
                     vendor\scalado\lib\WIN32\fmexif.lib \
                     vendor\scalado\lib\WIN32\fmextencoder.lib \
                     vendor\scalado\lib\WIN32\fmphotoartclipart.lib \
                     vendor\scalado\lib\WIN32\fmphotoartpack1.lib \
                     vendor\scalado\lib\WIN32\fmphotoartscribble.lib \
                     vendor\scalado\lib\WIN32\fmspeedview.lib \
                     vendor\scalado\lib\WIN32\osljpeg_sw.lib
  endif
endif

# ALIPAY_SUPPORT
ifdef ALIPAY_SUPPORT
  ifeq ($(strip $(ALIPAY_SUPPORT)),TRUE)
    MODIS_EN_OBJS += vendor\alipay\lib\alixpay.lib
  endif
endif

# INTERGRAFX_SUPPORT
ifdef INTERGRAFX_SUPPORT
  ifneq ($(strip $(INTERGRAFX_SUPPORT)),NONE)
    ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Engine\IGV5Lib\Win32\Debug\IGV5.lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Engine\IGV5Lib\Win32\Debug\IGV5.lib
    else
      MODIS_EN_OBJS += vendor\intergrafx\Engine\IGV3Lib\Win32\Debug\IGV3.lib
      CUS_REL_FILES_LIST += vendor\intergrafx\Engine\IGV3Lib\Win32\Debug\IGV3.lib
    endif
  endif
  ifneq ($(filter $(FT_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).lib
      MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).obj
      CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_EN_$(strip $(MAIN_LCD_SIZE)).obj
    endif
  endif
  ifneq ($(filter $(FT_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).lib
      MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).obj
      CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\FlowerTower\IG_FT_CH_$(strip $(MAIN_LCD_SIZE)).obj
    endif
  endif
  ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
    ifneq ($(filter $(DA_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
      endif
    endif
    ifneq ($(filter $(DA_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
      endif
    endif
  else
    ifneq ($(filter $(DA_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).lib
        MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).obj
        CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_EN_$(strip $(MAIN_LCD_SIZE)).obj
      endif
    endif
    ifneq ($(filter $(DA_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
      ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
        MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
        CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).lib
        MODIS_EN_OBJS += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).obj
        CUS_REL_FILES_LIST += vendor\intergrafx\Game\Win32\DancingAngel\IG_DA_CH_$(strip $(MAIN_LCD_SIZE)).obj
      endif
    endif
  endif
  ifneq ($(filter $(JE_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\JumpEmperor\IG_JE_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\JumpEmperor\IG_JE_EN_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(JE_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\JumpEmperor\IG_JE_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\JumpEmperor\IG_JE_CH_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(CW_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\CubeWorld\IG_CW_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\CubeWorld\IG_CW_EN_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(CW_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\CubeWorld\IG_CW_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\CubeWorld\IG_CW_CH_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(TF_EN_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\TankFantasy\IG_TF_EN_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\TankFantasy\IG_TF_EN_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
  ifneq ($(filter $(TF_CH_SUPPORT_VALUE),$(INTERGRAFX_SUPPORT)),)
    ifneq ($(filter $(MAIN_LCD_SUPPORT_SIZE),$(MAIN_LCD_SIZE)),)
      MODIS_EN_OBJS += vendor\intergrafx_hw\Game\Win32\TankFantasy\IG_TF_CH_$(strip $(MAIN_LCD_SIZE)).lib
      CUS_REL_FILES_LIST += vendor\intergrafx_hw\Game\Win32\TankFantasy\IG_TF_CH_$(strip $(MAIN_LCD_SIZE)).lib
    endif
  endif
endif

# Audio Vedio Library
  MODIS_EN_OBJS += $(strip $(MODISDIR))\MoDIS\$(MODIS_MODE)\AVLib.lib

# CMMB_CAS_2GPP_VER
ifdef CMMB_CAS_2GPP_VER
  ifneq ($(strip $(CMMB_CAS_2GPP_VER)),NONE)
    MODIS_EN_OBJS += vendor\cmmb\iboi\lib\iboi_Win32.lib
  endif
endif

# **********************
# Copy Files or Folders
# **********************
ifdef OPENGLES_SUPPORT
  ifeq ($(strip $(OPENGLES_SUPPORT)),TRUE)
    GLES_EMULATOR_WIN32_LIB = libEGL.lib libGLESv2.lib
    GLES_EMULATOR_WIN32_LIB_LIST = $(addprefix vendor\opengles\lib\,$(GLES_EMULATOR_WIN32_LIB))
    MODIS_EN_OBJS    += $(GLES_EMULATOR_WIN32_LIB_LIST)
    CUS_REL_FILES_LIST += $(GLES_EMULATOR_WIN32_LIB_LIST)
    # Copy vendor\opengles\lib\libEGL.dll to MoDIS_VC9\MoDIS\Debug and MoDIS_VC9\MoDIS\Release
    # Copy vendor\opengles\lib\libGLESv2.dll to MoDIS_VC9\MoDIS\Debug and MoDIS_VC9\MoDIS\Release
    GLES_EMULATOR_WIN32_DLL_LIST := vendor\opengles\lib\libEGL.dll,$(strip $(MODISDIR))\MoDIS\Debug$(strip $(MODIS_SUFFIX))\libEGL.dll
    GLES_EMULATOR_WIN32_DLL_LIST += vendor\opengles\lib\libEGL.dll,$(strip $(MODISDIR))\MoDIS\Release$(strip $(MODIS_SUFFIX))\libEGL.dll
    GLES_EMULATOR_WIN32_DLL_LIST += vendor\opengles\lib\libGLESv2.dll,$(strip $(MODISDIR))\MoDIS\Debug$(strip $(MODIS_SUFFIX))\libGLESv2.dll
    GLES_EMULATOR_WIN32_DLL_LIST += vendor\opengles\lib\libGLESv2.dll,$(strip $(MODISDIR))\MoDIS\Release$(strip $(MODIS_SUFFIX))\libGLESv2.dll
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
      MODIS_COPY_FILE += $(GLES_EMULATOR_WIN32_DLL_LIST)
      CUS_REL_FILES_LIST += vendor\opengles\lib\libEGL.dll
      CUS_REL_FILES_LIST += vendor\opengles\lib\libGLESv2.dll
    else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
      MODIS_COPY_FILE += $(GLES_EMULATOR_WIN32_DLL_LIST)
      CUS_REL_FILES_LIST += vendor\opengles\lib\libEGL.dll
      CUS_REL_FILES_LIST += vendor\opengles\lib\libGLESv2.dll
    endif
  endif
endif

ifneq ($(filter __NFB_THIRD_ROM_SUPPORT__,$(strip $(COM_DEFS))),)
  ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
      MODIS_COPY_FILE += $(strip $(MMIDIR))\..\plutommi\Customer\CustResource\CustMMI3rdROM,$(strip $(MODISDIR))\MoDIS\CustMMI3rdROM
      CUS_REL_FILES_LIST += $(strip $(MODISDIR))\MoDIS\CustMMI3rdROM	
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      MODIS_COPY_FILE += $(strip $(MMIDIR))\..\plutommi\Customer\Resgenerator\ThemeXML\Temp\CustEnfbVenusThemeData,$(strip $(MODISDIR))\MoDIS\CustEnfbVenusThemeData
      MODIS_COPY_FILE += $(strip $(MMIDIR))\..\plutommi\Customer\Resgenerator\ThemeXML\Temp\CustEnfbVenusAppIconData,$(strip $(MODISDIR))\MoDIS\CustEnfbVenusAppIconData
      CUS_REL_FILES_LIST += $(strip $(MODISDIR))\MoDIS\CustEnfbVenusThemeData
      CUS_REL_FILES_LIST += $(strip $(MODISDIR))\MoDIS\CustEnfbVenusAppIconData
    endif
    ifneq ($(filter MMI_GUOBI_HW_SC_SLIM MMI_GUOBI_HW_STANDARD,$(strip $(HAND_WRITING))),)
      MODIS_COPY_FILE += $(strip $(MMIDIR))\..\plutommi\Customer\Resgenerator\hw_data.gbd,$(strip $(MODISDIR))\MoDIS\hw_data.gbd
      CUS_REL_FILES_LIST += $(strip $(MODISDIR))\MoDIS\hw_data.gbd
    endif
    ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_ETRUMP)  
      MODIS_COPY_FILE += $(strip $(MMIDIR))\..\plutommi\Customer\CustResource\CustENFBFontData,$(strip $(MODISDIR))\MoDIS\CustENFBFontData
      CUS_REL_FILES_LIST += $(strip $(MODISDIR))\MoDIS\CustENFBFontData
    endif
  endif
endif

# convert.exe is necessary in MoDIS MTE
ifneq ($(filter $(strip $(MMI_VERSION)),PLUTO_MMI COSMOS_MMI NEPTUNE_MMI),)
  MODIS_COPY_FILE += $(strip $(MMIDIR))\Customer\ResGenerator\convert.exe,$(strip $(MODISDIR))\MoDIS\Debug\convert.exe
  MODIS_COPY_FILE += $(strip $(MMIDIR))\Customer\ResGenerator\convert.exe,$(strip $(MODISDIR))\MoDIS\Release\convert.exe
endif

# Copy plutommi\Framework\MSLT\MSLTInc\MSLT_INFO to MoDIS_VC9\MoDIS\MSLT_INFO, generated by plutommi\Customer\ResGenerator\mslt_parse_info.pl
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
ifneq ($(filter $(strip $(MMI_VERSION)),PLUTO_MMI COSMOS_MMI),)
  MODIS_COPY_DIR += plutommi\Framework\MSLT\MSLTInc\MSLT_INFO,$(strip $(MODISDIR))\MoDIS\MSLT_INFO
endif
endif

MODIS_TOUCH_FILE += $(strip $(TSTDIR))\src\gvTbl_modis.c $(strip $(TSTDIR))\src\tst_querysimid_modis.c

# *************************************************************************
# MoDIS Config
# *************************************************************************
MODIS_MTK_LIBS := $(filter-out $(strip $(MODIS_DIS_LIBS)),$(MODIS_MTK_LIBS))
MODIS_EN_LIBS := $(filter-out $(strip $(MODIS_DIS_LIBS)) $(strip $(MODIS_MTK_LIBS)),$(MODIS_EN_LIBS))

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  COMPLIST += $(MODIS_EN_LIBS)
  COMPLIST := $(filter-out $(strip $(MODIS_DIS_LIBS)) $(strip $(MODIS_MTK_LIBS)),$(COMPLIST))
  CUS_REL_SRC_COMP := $(filter-out $(strip $(MODIS_DIS_LIBS)) $(strip $(MODIS_MTK_LIBS)),$(CUS_REL_SRC_COMP))
  CUS_REL_PAR_SRC_COMP := $(filter-out $(strip $(MODIS_DIS_LIBS)) $(strip $(MODIS_MTK_LIBS)),$(CUS_REL_PAR_SRC_COMP))
  CUS_REL_MTK_COMP := $(filter-out $(strip $(MODIS_DIS_LIBS)) $(strip $(MODIS_MTK_LIBS)),$(CUS_REL_MTK_COMP))
  COMMINCDIRS := $(MODIS_EN_INC_PATH) $(COMMINCDIRS)
  COMMINCDIRS := $(filter-out $(strip $(MODIS_DIS_INC_PATH)),$(COMMINCDIRS))
  XGEN_INC_DIR := $(MODIS_EN_INC_PATH) $(XGEN_INC_DIR)
  XGEN_INC_DIR := $(filter-out $(strip $(MODIS_DIS_INC_PATH)),$(XGEN_INC_DIR))
  COM_DEFS := $(MODIS_EN_OPTION) $(COM_DEFS)
  COM_DEFS := $(filter-out $(strip $(MODIS_DIS_OPTION)),$(COM_DEFS))
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  CC_MODIS := cl
  LIB_MODIS := lib
  LINK_MODIS := link
  export PATH := $(strip $(WindowsSDKDir))\bin;$(strip $(VSCommonDir))\IDE;$(strip $(MSVCDir))\BIN;$(strip $(MSVCDir))\vcpackages;$(strip $(VSCommonDir))\Tools\$(strip $(VcOsDir));$(strip $(FrameworkDir))\v3.5;$(strip $(FrameworkDir))\v2.0.50727;$(strip $(PATH))
  export INCLUDE := $(strip $(WindowsSDKDir))\Include;$(strip $(MSVCDir))\ATLMFC\INCLUDE;$(strip $(MSVCDir))\INCLUDE;$(strip $(INCLUDE))
  export LIB := $(strip $(WindowsSDKDir))\Lib;$(strip $(MSVCDir))\ATLMFC\LIB;$(strip $(MSVCDir))\LIB;$(strip $(LIB))
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
    ifdef VC2008_VERSION
      ifeq ($(strip $(VC2008_VERSION)),PROFESSIONAL)
        VC2008_VERSION := $(shell (devenv /? >NUL 2>NUL) & (if errorlevel 1 (echo EXPRESS) else (echo PROFESSIONAL)))
      else
        VC2008_VERSION := EXPRESS
      endif
    else
      VC2008_VERSION := EXPRESS
    endif
    ifeq ($(strip $(VC2008_VERSION)),PROFESSIONAL)
      MODIS_INCREDIBUILD := TRUE
    else
      MODIS_INCREDIBUILD := FALSE
    endif
  else
    MODIS_INCREDIBUILD := FALSE
  endif
endif
