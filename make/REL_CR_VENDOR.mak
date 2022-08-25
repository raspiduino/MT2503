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
# VENDOR Release Component Configuration 
# base on Custom Release Component Configuration
# *************************************************************************

CUS_REL_OPTION_FILTER   = TRUE
CUS_REL_HISTORY_FILTER  = TRUE

# Forbidden feature
ifdef CHIP_VERSION_CHECK
  ifneq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
    $(error Please set CHIP_VERSION_CHECK as TRUE !!)
  endif
endif

ifdef SW_FLASH
  ifneq ($(strip $(SW_FLASH)),NONE)
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      $(error PLEASE turn off SW_FLASH for vendor project)
    endif
  endif
endif

ifneq ($(strip $(MMIDIR)),plutommi)
  $(error vendor release not support lcmmi)
endif

# pre-processing for REL_COMP_XXX.mak - do NOT filter-out from CUS_REL_FILES_LIST
CUS_REL_FILES_LIST_MUST_RELEASE  := $(filter make\REL_COMP_%,$(CUS_REL_FILES_LIST))

#Release make\video_codec\option_HAL_video_codec.mak
CUS_REL_FILES_LIST_MUST_RELEASE += make\video_codec\option_HAL_video_codec.mak

ifeq ($(strip $(MMIDIR)),plutommi)
###########################################################################
# Common release Section
###########################################################################
  CUS_REL_BASE_COMP       :=
  CUS_REL_SRC_COMP        :=
  CUS_REL_PAR_SRC_COMP    :=
  CUS_REL_HDR_COMP        :=
  CUS_REL_MTK_COMP        :=
  CUS_REL_FILES_LIST      :=

  # add REL_COMP_XXX.mak to CUS_REL_FILES_LIST
  CUS_REL_FILES_LIST      += $(CUS_REL_FILES_LIST_MUST_RELEASE)

  CUS_REL_BASE_COMP += tools plutommi\VendorApp
  
  CUS_REL_BASE_COMP += plutommi\Customer\Binary
  
  CUS_REL_MTK_COMP := $(filter-out vendorapp,$(COMPLIST))
  CUS_REL_MTK_COMP := $(filter-out plutommi,$(CUS_REL_MTK_COMP))
  CUS_REL_MTK_COMP := $(filter-out custom,$(CUS_REL_MTK_COMP))
  CUS_REL_MTK_COMP := $(filter-out verno,$(CUS_REL_MTK_COMP))
  CUS_REL_SRC_COMP += vendorapp custom verno

  MMI_SRC_VENDOR = MIGO
  ifneq ($(filter $(MMI_SRC_VENDOR),$(strip $(call Upper,$(VENDOR)))),)
    ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
      CUS_REL_SRC_COMP += venus #plutommi # conn_app inet_app media_app mmi_app mmi_framework
    else
      CUS_REL_SRC_COMP += plutommi # conn_app inet_app media_app mmi_app mmi_framework
    endif
  else
    ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
      CUS_REL_MTK_COMP += venus #plutommi # conn_app inet_app media_app mmi_app mmi_framework
    else
      CUS_REL_MTK_COMP += plutommi # conn_app inet_app media_app mmi_app mmi_framework
    endif
  endif

  CUS_REL_FILES_LIST += $(strip $(MEMORY_DEVICE_HDR)) $(strip $(CUSTOM_EMI_H)) $(strip $(FLASHFILE))
  CUS_REL_FILES_LIST += plutommi\MMI\Resource\readres.c
  CUS_REL_FILES_LIST += make\REL_CR_MMI_$(strip $(PROJECT)).mak
  CUS_REL_FILES_LIST += $(strip $(MMIDIR))\MMI\Inc\PixtelDataTypes.h
  CUS_REL_FILES_LIST += custom\common\$(strip $(MMI_BASE))\nvram_mmi_cache_defs.h
  CUS_REL_FILES_LIST += custom\common\hal\nvram\custom_nvram_cat.h

  # For MoDIS AVLib release.
  CUS_REL_FILES_LIST += MoDIS_VC9\MoDIS\w32_av_lib.cpp \
                        MoDIS_VC9\MoDIS\w32_av_lib.h \
                        MoDIS_VC9\MoDIS\w32_av_types.h \
                        MoDIS_VC9\MoDIS\AVLib\Player.h \
                        MoDIS_VC9\MoDIS\AVLib\RgbFormat.h \
                        MoDIS_VC9\MoDIS\AVLib\VideoSample.h
  CUS_REL_FILES_LIST += interface\hwdrv\lcd_if.h \
                        interface\hwdrv\lcd_if_hw.h \
                        interface\hwdrv\lcd_if_6235_series_hw.h \
                        interface\hwdrv\lcd_if_6238_series_hw.h \
                        interface\hwdrv\lcd_if_6228_series_hw.h

  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
    CUS_REL_BASE_COMP += vendor\inputmethod\CStar\v2_demo\lib
  endif
  ifdef CUSTOM_RELEASE
    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
      ifdef J2ME_SUPPORT
        ifneq ($(strip $(J2ME_SUPPORT)),NONE)
          CUS_REL_BASE_COMP += j2me custom\j2me
        endif
      endif
    endif
  endif
  ifneq ($(strip $(CUS_INPUTMETHOD_BASE)),)
    CUS_REL_BASE_COMP += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif

  MMI_FEATURE_LOG = $(TARGDIR)\log\MMI_features.log
  ifeq ($(strip $(word 3,$(shell find /C "[D] __MMI_RESOURCE_ENFB_SUPPORT__" $(strip $(MMI_FEATURE_LOG))))),1)
    CUS_REL_FILES_LIST += plutommi\Customer\CustResource\CustENFBImgData
    CUS_REL_FILES_LIST += plutommi\Customer\CustResource\CustENFBStrData
  endif

  ifdef FONT_ENGINE
    ifneq ($(strip $(FONT_ENGINE)),NONE)
      CUS_REL_FILES_LIST += plutommi\Customer\ResGenerator\vf_obj.txt \
                            plutommi\Customer\ResGenerator\vf_modis_obj.txt
      CUS_REL_OBJ_LIST += $(shell type plutommi\Customer\ResGenerator\vf_obj.txt) \
                          $(shell type plutommi\Customer\ResGenerator\vf_modis_obj.txt)
    endif
    ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
      CUS_REL_MTK_COMP := $(filter-out vectorfont_freetype,$(CUS_REL_MTK_COMP))
      CUS_REL_SRC_COMP += vectorfont_freetype
      CUS_REL_BASE_COMP += vendor\vectorfont\freetype
      CUS_REL_FILES_LIST += kal\common\include\kal_adm.h
    endif
    ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE_DEMO)
      CUS_REL_MTK_COMP := $(filter-out vectorfont_freetype,$(CUS_REL_MTK_COMP))
      CUS_REL_SRC_COMP += vectorfont_freetype
      CUS_REL_BASE_COMP += vendor\vectorfont\freetype
      CUS_REL_FILES_LIST += kal\common\include\kal_adm.h
    endif
  endif
  
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
        CUS_REL_FILES_LIST += dsp_bin\$(strip $(DUALMACDSP_BIN)).bin
        CUS_REL_FILES_LIST += dsp_bin\$(strip $(DUALMACDSP_BL_BIN)).bin
  endif

ifeq ($(strip $(FONT_RESOURCE)),OFFICIAL)
  NON_REL_DIRS_LIST += vendor\font\FontData\DemoFont
  CUS_REL_BASE_COMP += vendor\font\FontData\OfficialFont\MTK_Proprietary
  CUS_REL_FILES_LIST += vendor\font\FontData\OfficialFont\Latin\pluto_small.bdf \
                        vendor\font\FontData\OfficialFont\Latin\pluto_medium.bdf \
                        vendor\font\FontData\OfficialFont\Latin\pluto_large.bdf \
                        vendor\font\FontData\OfficialFont\Latin\L_MTK_En_Medium_20.bdf \
                        vendor\font\FontData\OfficialFont\Latin\L_MTK_En_Large_22.bdf \
                        vendor\font\FontData\OfficialFont\Latin\MTK_En_large_24.bdf \
                        vendor\font\FontData\OfficialFont\Dialing\L_MTK_DiallingFont_27.bdf \
                        vendor\font\FontData\OfficialFont\Dialing\Dialing.bdf \
                        vendor\font\FontData\OfficialFont\Dialing\number_12.bdf \
                        vendor\font\FontData\OfficialFont\VK\Latin_10.bdf \
                        vendor\font\FontData\OfficialFont\VK\vk_latin_14.bdf \
                        vendor\font\FontData\OfficialFont\VK\vk_latin_20.bdf \
                        vendor\font\FontData\OfficialFont\VK\vk_latin_30.bdf
else
  ifeq ($(strip $(FONT_RESOURCE)),DEMO)
    NON_REL_DIRS_LIST += vendor\font\FontData\OfficialFont
    CUS_REL_BASE_COMP += vendor\font\FontData\DemoFont
  endif
endif

ifeq ($(strip $(INTERGRAFX_SUPPORT)),NONE)
  NON_REL_DIRS_LIST += vendor\intergrafx\LW
else
  CUS_REL_BASE_COMP += vendor\intergrafx\Engine
  ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_BASIC)
    CUS_REL_BASE_COMP += vendor\intergrafx\LW\WPLib
    CUS_REL_BASE_COMP += vendor\intergrafx\LW\Daydream
    CUS_REL_BASE_COMP += vendor\intergrafx\LW\Girl
    CUS_REL_BASE_COMP += vendor\intergrafx\LW\Puppy
    CUS_REL_BASE_COMP += vendor\intergrafx\LW\Transformer

    NON_REL_DIRS_LIST += vendor\intergrafx\LW\Clock
    NON_REL_DIRS_LIST += vendor\intergrafx\LW\Fish
    NON_REL_DIRS_LIST += vendor\intergrafx\LW\Horse
    NON_REL_DIRS_LIST += vendor\intergrafx\LW\Lighthouse
    NON_REL_DIRS_LIST += vendor\intergrafx\LW\Mimosa
    NON_REL_DIRS_LIST += vendor\intergrafx\LW\Solar
  else
    ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_VALUED)
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\WPLib
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Daydream
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Girl
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Puppy
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Transformer
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Clock
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Horse
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Lighthouse
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Mimosa
      CUS_REL_BASE_COMP += vendor\intergrafx\LW\Solar

      NON_REL_DIRS_LIST += vendor\intergrafx\LW\Fish
    else
      ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE_FULL)
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\WPLib
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Daydream
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Girl
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Puppy
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Transformer
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Clock
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Horse
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Lighthouse
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Mimosa
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Solar
        CUS_REL_BASE_COMP += vendor\intergrafx\LW\Fish
      endif
    endif
  endif
endif

  ifdef OPTR_SPEC
    ifneq ($(OPTR_SPEC),NONE)
      CUS_REL_FILES_LIST += $(OPTR_PATH)\operator.mak
      CUS_REL_FILES_LIST += $(OPTR_PATH)\operator_checklist.txt
    endif
  endif

CUS_REL_BASE_COMP += Doc
NON_REL_DIRS_LIST += Doc\DOM

CUS_REL_BASE_COMP += custom\system\$(strip $(BOARD_VER))

#release setting for xgen.mak
CUS_REL_BASE_COMP += make\xgen

CUS_REL_BASE_COMP += custom\system\Template

ifeq ($(strip $(GPS_SUPPORT)),MT3336) # GPS MT3336
  CUS_REL_BASE_COMP += gps\mnl\lib\MT3336
endif

ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    CUS_REL_BASE_COMP += plutommi\Customer\Fonts\Android \
                         plutommi\Customer\Fonts\MTK \
                         plutommi\Customer\Fonts\Arphic_demo \
                         plutommi\Customer\Fonts\Monotype_demo \
                         plutommi\Customer\Fonts\Etrump
  endif
endif

###########################################################################
# Customization release Section
###########################################################################
  
  #------------------------------------------------------------------------
  # NMC
  #------------------------------------------------------------------------
  ifneq ($(filter NMC,$(strip $(call Upper,$(VENDOR)))),)
    ifdef NMC_SUPPORT
      ifeq ($(strip $(NMC_SUPPORT)),TRUE)
        CUS_REL_MTK_COMP := $(filter-out nmc,$(CUS_REL_MTK_COMP))
        CUS_REL_BASE_COMP+=  vendor\nmc 
        CUS_REL_OBJ_LIST += vendor\nmc\corelib\target\nmccore.lib
        CUS_REL_OBJ_LIST += vendor\nmc\corelib\modis\nmccore.lib
        CUS_REL_SRC_COMP += nmc
      endif
    endif
  endif

  #------------------------------------------------------------------------
  # QQMOVIE
  #------------------------------------------------------------------------
  ifneq ($(filter QQMOVIE,$(strip $(call Upper,$(VENDOR)))),)
    ifdef QQMOVIE_SUPPORT
      ifeq ($(strip $(QQMOVIE_SUPPORT)),TRUE)
        CUS_REL_MTK_COMP := $(filter-out qqmovie,$(CUS_REL_MTK_COMP))
        CUS_REL_SRC_COMP += qqmovie
        CUS_REL_OBJ_LIST += vendor\streaming\qqmovie\lib\qqmovie_lib_ui.a
        CUS_REL_OBJ_LIST += vendor\streaming\qqmovie\lib\qqmovie_lib_browser.a
      endif
    endif
  endif

  #------------------------------------------------------------------------
  # OPERA
  #------------------------------------------------------------------------
  ifneq ($(filter OPERA,$(strip $(call Upper,$(VENDOR)))),)
    ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
      CUS_REL_MTK_COMP := $(filter-out opera10adp,$(CUS_REL_MTK_COMP))
      CUS_REL_MTK_COMP := $(filter-out opera10opdev,$(CUS_REL_MTK_COMP))
      CUS_REL_BASE_COMP += vendor\opera
      CUS_REL_SRC_COMP += opera10adp opera10opdev
      CUS_REL_FILES_LIST += interface\hwdrv\mmsys_pwrmgr.h \
                            interface\hwdrv\mmsys_pwrmgr_def.h \
                            drm\include\drm_gprot.h \
                            interface\security\certman_api.h \
                            interface\security\certman_defs.h \
                            interface\security\certman_struct.h \
                            interface\wap\das_struct.h \
                            plutommi\MMI\CertificateManager\CertificateManagerMMIInc\CertManMMIGprots.h \
                            plutommi\MMI\Inc\PixtelDataTypes.h \
                            plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc\EngineerModeInetAppGprot.h \
                            plutommi\mtkapp\MDI\MDIInc\mdi_motion.h \
                            plutommi\mtkapp\URIAgent\URIAgentInc\URIAgentGProt.h \
                            plutommi\mmi\connectmanagement\connectmanagementinc\ConnectManageGProt.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jni.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jni_md.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jri.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jri_md.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jritypes.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npapi.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npplg_av_include.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npruntime.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\nptypes.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npupp.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npn_mtk.h \
                            custom\common\custpack_certs.h \
                            drv\graphics\g2d\inc\g2d_enum.h \
                            plutommi\Framework\GDI\gdiinc\gdi_2d_engine.h \
                            plutommi\MtkApp\DLAgent\DLAgentInc\DLAgentDef.h \
                            plutommi\MtkApp\DLAgent\DLAgentInc\DLAgentGProt.h
    endif
    ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_TURBO)
      CUS_REL_MTK_COMP := $(filter-out opera10adp,$(CUS_REL_MTK_COMP))
      CUS_REL_MTK_COMP := $(filter-out opera11opdev,$(CUS_REL_MTK_COMP))
      CUS_REL_BASE_COMP += vendor\opera
      CUS_REL_SRC_COMP += opera10adp opera11opdev
      CUS_REL_FILES_LIST += interface\hwdrv\mmsys_pwrmgr.h \
                            interface\hwdrv\mmsys_pwrmgr_def.h \
                            drm\include\drm_gprot.h \
                            interface\security\certman_api.h \
                            interface\security\certman_defs.h \
                            interface\security\certman_struct.h \
                            interface\wap\das_struct.h \
                            plutommi\MMI\CertificateManager\CertificateManagerMMIInc\CertManMMIGprots.h \
                            plutommi\MMI\Inc\PixtelDataTypes.h \
                            plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc\EngineerModeInetAppGprot.h \
                            plutommi\mtkapp\MDI\MDIInc\mdi_motion.h \
                            plutommi\mtkapp\URIAgent\URIAgentInc\URIAgentGProt.h \
                            plutommi\mmi\connectmanagement\connectmanagementinc\ConnectManageGProt.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jni.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jni_md.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jri.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jri_md.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\jritypes.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npapi.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npplg_av_include.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npruntime.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\nptypes.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npupp.h \
                            plutommi\mtkapp\NPPlg\NPPlgInc\npn_mtk.h \
                            custom\common\custpack_certs.h \
                            drv\graphics\g2d\inc\g2d_enum.h \
                            plutommi\Framework\GDI\gdiinc\gdi_2d_engine.h \
                            plutommi\MtkApp\DLAgent\DLAgentInc\DLAgentDef.h \
                            plutommi\MtkApp\DLAgent\DLAgentInc\DLAgentGProt.h
    endif
  endif
  
  #------------------------------------------------------------------------
  # INFRAWARE
  #------------------------------------------------------------------------

  #------------------------------------------------------------------------
  # Alipay
  #------------------------------------------------------------------------
  ifneq ($(filter ALIPAY,$(strip $(call Upper,$(VENDOR)))),)
    ifdef ALIPAY_SUPPORT
      ifeq ($(strip $(ALIPAY_SUPPORT)), TRUE)
        CUS_REL_MTK_COMP := $(filter-out alipay,$(CUS_REL_MTK_COMP))
        CUS_REL_SRC_COMP += alipay
        CUS_REL_BASE_COMP+= vendor\alipay
        CUS_REL_OBJ_LIST += vendor\alipay\lib\alixpay.a
        CUS_REL_OBJ_LIST += vendor\alipay\lib\alixpay.lib
      endif
    endif
  endif  



  
###########################################################################
# Special modules release type setting samples
# if required , please add the corresponding segement into specified
# VENDOR section and remove the comment
###########################################################################

## *************************************************************************
## set init module for partial source release
## *************************************************************************
#  CUS_REL_MTK_COMP := $(filter-out init,$(CUS_REL_MTK_COMP))
#  CUS_REL_PAR_SRC_COMP += init
#  CUS_REL_INIT_PAR_SRC_LIST = init\src\init.c

## *************************************************************************
## set bootloader module for source release
## *************************************************************************
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    CUS_REL_SRC_COMP += bootloader
    CUS_REL_SRC_COMP += bootloader_ext
    CUS_REL_BASE_COMP += hal\system\bootloader
    CUS_REL_BASE_COMP += make\bootloader
    CUS_REL_BASE_COMP += make\bootloader_ext
  endif

## *************************************************************************
## set fota module for source release
## *************************************************************************
#  ifdef FOTA_ENABLE
#    ifneq ($(strip $(FOTA_ENABLE)),NONE)
#      CUS_REL_SRC_COMP += fota
#      CUS_REL_BASE_COMP += fota make\fota lqt
#      CUS_REL_FILES_LIST += custom\drv\LCD\$(strip $(LCD_MODULE))\lcd.c \
#                            custom\drv\misc_drv\$(strip $(BOARD_VER))\pmic_custom.c
#      ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
#        CUS_REL_BASE_COMP += vendor\hp_fota\lib
#      endif
#    endif
#  endif

endif

#----------------------------- Add to support nvram auto gen dep release ------------------------------
CUS_REL_NVRAM_AUTO_GEN_PAR_SRC_LIST = custom\app\$(strip $(PROJECT_BB))\custom_mmi_cache_config.c \
                                      custom\app\$(strip $(PROJECT_BB))\nvram_user_config.c \
                                      tools\NVRAMStatistic\src\nvram_auto_gen.c \
                                      tools\NVRAMStatistic\src\nvram_gen_util.c \
                                      tools\NVRAMStatistic\src\nvram_gen_mmi_cache.c \
                                      tools\NVRAMStatistic\src\nvram_compress.c

#----------------------------- Add to support codegen for vendor release ------------------------------
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters.h
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters_FDD.ini
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters_TDD.ini
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters_2G_FDD.ini
CUS_REL_FILES_LIST += tst\database\msglog_db\custom_parse_db.c
CUS_REL_FILES_LIST += custom\common\custom_nvram_restore.h
CUS_REL_FILES_LIST += tst\database\TrcGen.lst
CUS_REL_BASE_COMP += $(strip $(TST_DB))\gv
CUS_REL_BASE_COMP += $(strip $(TST_DB))\unionTag
CUS_REL_BASE_COMP += $(strip $(TST_DB))\pstrace_db
CUS_REL_FILES_LIST += $(strip $(TST_DB))\MCDDLL.dll
CUS_REL_BASE_COMP += tst\include
#----------------------------- Add to support resgen for vendor release ------------------------------
CUS_REL_FILES_LIST += venusmmi\framework\xml\vfx_xml_conv.pl
CUS_REL_FILES_LIST += venusmmi\framework\xml\vfx_xml_export.xml

#release folder for support TOUCH_PANEL_SUPPORT switch(CTP_* <--> TP_*)
CUS_REL_BASE_COMP += custom\drv\CTP_module\common \
                     custom\drv\CTP_module\CTP_CYPRESS_TMA340_TRUE_MULTIPLE \
                     custom\drv\CTP_module\CTP_FOCALTEK_FT5206_TRUE_MULTIPLE \
                     custom\drv\CTP_module\CTP_ITE_7250AFN_FAKE_MULTIPLE \
                     custom\drv\CTP_module\CTP_NOVATEK_NT11001_FAKE_MULTIPLE \
                     custom\drv\CTP_module\CTP_SITRONIX_ST1232_FAKE_MULTIPLE