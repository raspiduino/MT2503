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
# Custom Release Common Configuration
# *************************************************************************


# bootloader
NON_REL_FILES_LIST += hal\system\bootloader\inc\bootrom.h \
                      hal\system\bootloader\src\bl_FactoryConn.c

# SST
NON_REL_FILES_LIST += SST\include\SST_internal.h
NON_REL_FILES_LIST += SST\include\SST_state_compare.h

# init
NON_REL_FILES_LIST += init\include\bus_monitor.h \
                      init\include\emi_bus_monitor.h

# bt stack
NON_REL_FILES_LIST += btstacka\inc\X_file.h

# ArmDraDecLib rvct
ifneq ($(strip $(EMPTY_RESOURCE)),FALSE)
NON_REL_FILES_LIST += l1audio\obj\ArmDraDecLib.a \
                      l1audio\obj\ArmDraDecLib_rvct.a
endif

# external mmi
ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
NON_REL_DIRS_LIST += external_mmi
endif

# venus mmi
ifneq ($(strip $(RELEASE_VRT)),SRC)
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  NON_REL_DIRS_LIST += venusmmi\vrt\base \
                       venusmmi\vrt\canvas \
                       venusmmi\vrt\core
endif
endif
                     
# btstack
NON_REL_DIRS_LIST += btstacka\hcitrans\uart \
                     btstacka\hcitrans\modinit \
                     btstacka\stack

ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  NON_REL_DIRS_LIST += Fast_DL
  NON_REL_DIRS_LIST += vendor\hp_fota\Lib
  NON_REL_DIRS_LIST += $(strip $(MMIDIR))\Customer\CustResource\PLUTO_MMI\ref_list
endif

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  CUS_REL_FILES_LIST += vendor\redbend_fota\MTK_FPP_FW_rvct31_arm11.lib \
                        vendor\redbend_fota\MTK_FPP_FW_rvct31_arm7.lib \
                        vendor\redbend_fota\MTK_FPP_FW_rvct31_arm9.lib
endif

ifneq ($(strip $(DEMO_PROJECT)),TRUE)
  NON_REL_FILES_LIST += $(strip $(MMIDIR))\MMI\Inc\MMI_features_demo_proj_comm_switch.h \
                        $(strip $(MMIDIR))\MMI\Inc\MMI_features_undef_all_lang.h
endif

ifneq ($(strip $(EMPTY_RESOURCE)),FALSE)
# NOT release ipeer internal files
  NON_REL_DIRS_LIST += vendor\player\ipeer\lib\mtk_internal

# NOT release DOM internal files
  DOM_INTERNAL_FILES = $(shell dir Doc\DOM\Config\*_internal.* /b 2>nul)
  ifneq ($(words $(DOM_INTERNAL_FILES)),0)
    NON_REL_FILES_LIST += $(foreach file,$(DOM_INTERNAL_FILES),Doc\DOM\Config\$(file))
  endif

  NON_REL_FILES_LIST += Doc\DOM\Config\Template6.0.dox
endif

# NOT release global option switchalbe reference file
#ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
#  GLB_OPT_SWTCH_REF_FILE = $(shell dir tools\GLBOptionSwtichRef\Global_option_Switchable_in_custom_release*.xls /b 2>nul)
#  ifneq ($(words $(GLB_OPT_SWTCH_REF_FILE)),0)
#    NON_REL_FILES_LIST += $(foreach file,$(GLB_OPT_SWTCH_REF_FILE),tools\GLBOptionSwtichRef\$(file))
#  endif
#endif

# Only release chm files under DOC folder
CUS_REL_BASE_COMP += Doc
NON_REL_DIRS_LIST += Doc\DOM

# LAST_S_C.bat
NON_REL_FILES_LIST += LAST_S_C.bat

# EmptyImages are not needed in SLIM branches.
# Release all images to customers in SLIM branches.
ifneq ($(filter PLUTO_MMI COSMOS_MMI,$(strip $(MMI_VERSION))),)
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
    CUS_REL_BASE_COMP += plutommi\Customer\Images
    NON_REL_DIRS_LIST += plutommi\Customer\Images\swtr
  endif
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
    CUS_REL_BASE_COMP += lcmmi\Customer\Images
  endif
endif

ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  CUS_REL_BASE_COMP += plutommi\VendorApp
endif

#Not release DwarfUtility for Customer
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  NON_REL_DIRS_LIST += tools\DwarfUtility
endif

#Not release MemoryDeviceList_*Internal.xls for Customer
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifeq ($(call Upper ,$(strip $(VENDOR))),NONE)
    MEMORY_INTERNAL_FILE = $(shell dir tools\MemoryDeviceList\MemoryDeviceList_*Internal.xls /b 2>nul)
    ifneq ($(words $(MEMORY_INTERNAL_FILE)),0)
      NON_REL_FILES_LIST += $(foreach file,$(MEMORY_INTERNAL_FILE),tools\MemoryDeviceList\$(file))
    endif
  endif
endif

# MAUI_02602762
NON_REL_FILES_LIST += dsp_bin\Viti_Issue_Owner_Guide.pptx \
                      dsp_bin\VitiFileOwner.txt \
                      dsp_bin\VitiTaskDirOwner.xlsx

# MAUI_02838590
CUS_REL_BASE_COMP += tools\DebuggingSuite

# MAUI_02619934
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  CUS_REL_FILES_LIST += mtk_tools\notify_err.pl
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  CUS_REL_FILES_LIST += mtk_tools\NocodeCMMAutoGen.pl
endif
# MAUI_02634406
CUS_REL_BASE_COMP += MCT_TOOL

# mtk_tools
ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  ifndef VENDOR
    CUS_REL_FILES_LIST += mtk_tools\PsTrcInfo.exe
  else
    ifeq ($(strip $(VENDOR)),NONE)
      CUS_REL_FILES_LIST += mtk_tools\PsTrcInfo.exe
    endif
  endif
endif

ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
  CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\FontResgen
endif

CUS_REL_NVRAM_AUTO_GEN_PAR_SRC_LIST = nvram\src\nvram_factory_config.c \
                                      custom\common\$(strip $(MMI_FOLDER))\nvram_common_config.c \
                                      custom\common\$(strip $(MMI_FOLDER))\common_mmi_cache_config.c \
                                      custom\common\$(strip $(MMI_FOLDER))\nvram_cust_pack.c \
                                      custom\common\hal\nvram\custom_nvram_sec.c \
                                      custom\common\hal\nvram\custom_nvram_cat.c \
                                      custom\app\$(strip $(PROJECT_BB))\custom_mmi_cache_config.c \
                                      custom\app\$(strip $(PROJECT_BB))\nvram_user_config.c \
                                      tools\NVRAMStatistic\src\nvram_auto_gen.c \
                                      tools\NVRAMStatistic\src\nvram_gen_util.c \
                                      tools\NVRAMStatistic\src\nvram_gen_mmi_cache.c \
                                      tools\NVRAMStatistic\src\nvram_compress.c \
                                      custom\common\nvram_data_items.c \
                                      tools\NVRAMStatistic\src\fs_quota_entry_dump.c

#MAUI_02871341                                      
CUS_REL_FILES_LIST += l1assertbypass.men

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
  CUS_REL_BASE_COMP += custom\j2me\NEMO\_DEFAULT_BB
endif
endif

ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  DATABSE_FILE = $(shell dir $(TST_DB))\MTK_databaseinfo.csv /b 2>nul)
  ifneq ($(words $(DATABSE_FILE)),0)
    CUS_REL_FILES_LIST += $(TST_DB)\MTK_databaseinfo.csv
  endif
endif

ifeq ($(strip $(FONT_RESOURCE)),OFFICIAL)
  NON_REL_DIRS_LIST += vendor\font\FontData\DemoFont
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    CUS_REL_BASE_COMP += vendor\font\FontData\OfficialFont
  else
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
  endif
else
  ifeq ($(strip $(FONT_RESOURCE)),DEMO)
    NON_REL_DIRS_LIST += vendor\font\FontData\OfficialFont
    CUS_REL_BASE_COMP += vendor\font\FontData\DemoFont
  endif
endif

#release IG src to all customer
CUS_REL_BASE_COMP += vendor\intergrafx
CUS_REL_BASE_COMP += vendor\intergrafx_hw
CUS_REL_BASE_COMP += make\intergrafx_hw \
                     make\intergrafx_sw

#MAUI_02901930
CUS_REL_BASE_COMP += custom\system\$(strip $(BOARD_VER))

CUS_REL_BASE_COMP += custom\drv\misc_drv\_Default_BB\$(strip $(PLATFORM)) \
                     custom\drv\misc_drv\$(strip $(BOARD_VER))

#mre
CUS_REL_BASE_COMP += mre\custom\romapp

ifdef YAHOO_CONTENT_SUPPORT
  ifeq ($(strip $(YAHOO_CONTENT_SUPPORT)),TRUE)
    ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
      NON_REL_DIRS_LIST += mre\custom\romapp\yahoo
    endif
  else
    NON_REL_DIRS_LIST += mre\custom\romapp\yahoo
    NON_REL_DIRS_LIST += vendor\widget\google\gadgets\yahoo
  endif
else
  NON_REL_DIRS_LIST += mre\custom\romapp\yahoo
  NON_REL_DIRS_LIST += vendor\widget\google\gadgets\yahoo
endif

ifdef FACEBOOK_CONTENT_SUPPORT
  ifeq ($(strip $(FACEBOOK_CONTENT_SUPPORT)),TRUE)
    ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
      NON_REL_DIRS_LIST += mre\custom\romapp\facebook
    endif
  else
    NON_REL_DIRS_LIST += mre\custom\romapp\facebook
    NON_REL_DIRS_LIST += vendor\widget\google\gadgets\facebook
  endif
else
  NON_REL_DIRS_LIST += mre\custom\romapp\facebook
  NON_REL_DIRS_LIST += vendor\widget\google\gadgets\facebook
endif

#Release header file for COMBO_MEMORY_SUPPORT switch
CUS_REL_FILES_LIST += hal\storage\flash\mtd\inc\combo_flash_defs.h
CUS_REL_BASE_COMP += hal\system\GFH\public

#Release files for WEBCAM_SUPPORT switch
CUS_REL_BASE_COMP += media\webcam \
                     plutommi\MtkApp\Connectivity \
                     venusmmi\app\Cosmos\Webcam
                     
ifneq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  NON_REL_DIRS_LIST += vendor\redbend_fota\include
endif

#Release files for BACKGROUND_SOUND switch
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  CUS_REL_BASE_COMP += media\audio
endif

#Release header file for ZIMAGE_SUPPORT switch
CUS_REL_FILES_LIST += interface\hal\graphics\lzmadec.h
CUS_REL_FILES_LIST += interface\hal\graphics\lzmatypes.h
CUS_REL_FILES_LIST += hal\graphics\gfx_core\compress\lzma\src\lzmadec.c

CUS_REL_BASE_COMP += hal\peripheral

CUS_REL_BASE_COMP += custom\drv\camera_common

ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
  ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
    CUS_REL_BASE_COMP += plutommi\Framework
    CUS_REL_BASE_COMP += plutommi\CUI
    CUS_REL_BASE_COMP += plutommi\Service
    CUS_REL_BASE_COMP += venusmmi\app\Cosmos
  endif
endif

#release setting for xgen.mak
CUS_REL_BASE_COMP += make\xgen

#Release header file for PANORAMA_VIEW_SUPPORT switch
CUS_REL_BASE_COMP += hal\graphics\jpeg\common\inc \
                     hal\graphics\jpeg\jaia\inc \
                     hal\graphics\gfx_core\jpeg\jaia\inc

#Release files for WEBCAM_SUPPORT switch
CUS_REL_BASE_COMP +=  plutommi\Service\MDI\MDIInc \
                      plutommi\Service\MDI\MDISrc \
                      hal\connectivity\usb_driver\inc

#temp release for sysgen error
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  CUS_REL_BASE_COMP += kal\oscar\include
  CUS_REL_BASE_COMP += MoDIS_VC9\oscar\include
endif

#release files for support TOUCH_PANEL_SHORTCUT_SUPPORT switch(from FALSE to TRUE)
CUS_REL_FILES_LIST += custom\common\touch_panel_shortcut_custom.h.tmp \
                      custom\common\touch_panel_shortcut_custom.c.tmp

ifdef ALIPAY_SUPPORT
  ifeq ($(strip $(ALIPAY_SUPPORT)),TRUE)
    CUS_REL_OBJ_LIST += vendor\alipay\lib\alixpay.a
    CUS_REL_OBJ_LIST += vendor\alipay\lib\alixpay.lib
  endif
endif

#Release file for MODIS_FDM
CUS_REL_FILES_LIST += MoDIS_VC9\drv_sim\src\w32_file_disk.c

CUS_REL_BASE_COMP += hal\video
CUS_REL_BASE_COMP += interface\media
CUS_REL_BASE_COMP += custom\video
CUS_REL_BASE_COMP += hal\video_codec\interface
CUS_REL_BASE_COMP += interface\hal\video
CUS_REL_BASE_COMP += hal\mdp\include
CUS_REL_BASE_COMP += plutommi\CUI\VdoRecCui
NON_REL_DIRS_LIST += hal\video\demuxer\provider_sec

ifneq ($(strip $(CLOUD_SUPPORT)),SOURCE)
  NON_REL_FILES_LIST += plutommi\Service\SsoSrv\SsoSrvMain.c
  NON_REL_FILES_LIST += plutommi\Service\SsoSrv\plugin\yahoo\YAHOO_vpp.c
  NON_REL_FILES_LIST += plutommi\Service\CloudSrv\BackupRestoreSrvApi.c
  NON_REL_FILES_LIST += plutommi\Service\CloudSrv\BackupRestoreSrvCard.c
  NON_REL_FILES_LIST += plutommi\Service\CloudSrv\BackupRestoreSrvSms.c
  NON_REL_FILES_LIST += plutommi\Service\CloudSrv\BackupRestoreSrvScheduler.c
  NON_REL_FILES_LIST += plutommi\Service\EmailSrv\EmailSrvSso.c
endif

ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  NON_REL_DIRS_LIST += hal\video\fluency_sec
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  CUS_REL_BASE_COMP += hal\video_codec\lib
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\tools\Ini.pm
  CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\tools\mcd.ini
  CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\tools\mcdparser.pl
  CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\tools\mcd_l4.ini
  CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\tools\pre_mcdparser.pl
  CUS_REL_BASE_COMP += $(strip $(PS_FOLDER))\interfaces\asn
endif

CUS_REL_BASE_COMP += plutommi\CUI\InlineCui

CUS_REL_BASE_COMP += custom\system\Template

#suppor __MMI_CLOG_CALL_TIME__ & __MMI_NITZ__ to be switchable
CUS_REL_BASE_COMP += plutommi\Service\CallLogSrv
CUS_REL_BASE_COMP += plutommi\Service\NITZSrv

CUS_REL_BASE_COMP += interface\nfc

CUS_REL_FILES_LIST += mtk_tools\CMMAutoGen.pl
CUS_REL_FILES_LIST += Debug.men
# release hal\system\regbase\inc folder for CMMAutoGen.pl
CUS_REL_BASE_COMP += hal\system\regbase\inc

#for FM radio chip switchable
CUS_REL_BASE_COMP += fm_drv

ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  NON_REL_DIRS_LIST += gps\mnl\internal_lib
endif

ifdef GAMELOFT_CONTENT_SUPPORT
  ifeq ($(strip $(GAMELOFT_CONTENT_SUPPORT)),TRUE)
    ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
      NON_REL_DIRS_LIST += mre\custom\romapp\gameloft
    endif
  else
    NON_REL_DIRS_LIST += mre\custom\romapp\gameloft
  endif
else
  NON_REL_DIRS_LIST += mre\custom\romapp\gameloft
endif

NON_REL_DIRS_LIST += Doc\MMI_CONFIG_GUIDE\Source

ifdef TWITTER_CONTENT_SUPPORT
  ifeq ($(strip $(TWITTER_CONTENT_SUPPORT)),TRUE)
    ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
      NON_REL_DIRS_LIST += mre\custom\romapp\twitter
    endif
  else
    NON_REL_DIRS_LIST += mre\custom\romapp\twitter
  endif
else
  NON_REL_DIRS_LIST += mre\custom\romapp\twitter
endif

ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifdef SOCIAL_NETWORK_SUPPORT
    ifneq ($(strip $(SOCIAL_NETWORK_SUPPORT)),NONE)
      ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
        CUS_REL_BASE_COMP += plutommi\Service\SnsSrv\plugin
        ifdef FACEBOOK_SNS_SUPPORT
          ifeq ($(strip $(FACEBOOK_SNS_SUPPORT)),FALSE)
            NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\plugin\facebook
          endif
        else
          NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\plugin\facebook
        endif
        ifdef TWITTER_SNS_SUPPORT
          ifeq ($(strip $(TWITTER_SNS_SUPPORT)),FALSE)
            NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\plugin\twitter
          endif
        else
          NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\plugin\twitter
        endif
      endif
    else
      NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\plugin
    endif
  else
    NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\plugin
  endif
  NON_REL_DIRS_LIST += plutommi\Service\SnsSrv\src

  ifneq ($(strip $(SOCIAL_NETWORK_SUPPORT)),APP_SOURCE)
    NON_REL_DIRS_LIST += venusmmi\app\Cosmos\SNS\src
    NON_REL_DIRS_LIST += venusmmi\app\Cosmos\SNS\Widget\src
    NON_REL_DIRS_LIST += plutommi\mmi\sns\snssrc
    NON_REL_DIRS_LIST += plutommi\cui\SnsCui
    NON_REL_FILES_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_sns.c
    NON_REL_FILES_LIST += plutommi\mmi\phonebook\phonebooksrc\phonebookSns.c
    NON_REL_FILES_LIST += venusmmi\app\pluto_variation\LauncherKey\Widget\SNS\vapp_widget_sns.cpp	
    NON_REL_FILES_LIST += venusmmi\app\pluto_variation\LauncherKey\Widget\SNS\vapp_widget_key_sns.cpp
  endif
endif

CUS_REL_BASE_COMP += media\bitstream

#release folder for support TOUCH_PANEL_SUPPORT switch
CUS_REL_BASE_COMP += custom\drv\Motion_sensor \
                     custom\drv\Proximity_Sensor \
                     custom\drv\CTP_module

#release for MCARE switch
CUS_REL_BASE_COMP += make\tencentmcarev31adp \
                     vendor\mcare

#release for VKV3 switch
CUS_REL_BASE_COMP += plutommi\Customer\VKResourece

# release for switch ability
CUS_REL_BASE_COMP += make\guobihw
CUS_REL_BASE_COMP += make\winguo
CUS_REL_BASE_COMP += vendor\search_engine\GUOBI

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
    CUS_REL_FILES_LIST += interface\security\tls_api.h
  endif
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)),NONE)
    CUS_REL_FILES_LIST += interface\hal\cipher\include\ssl_api.h
  endif
endif

#MAUI_03231497
CUS_REL_FILES_LIST += inet_ps\interfaces\local_inc\mmi2abm_struct.h
CUS_REL_FILES_LIST += inet_ps\interfaces\local_inc\abm2soc_struct.h
CUS_REL_FILES_LIST += interface\inet_ps\abm_api.h
CUS_REL_FILES_LIST += interface\wifi\hostap_abm_msgs.h

CUS_REL_FILES_LIST += gps\core\custom_core\MT3333.bin

# release handwriting guobi folder for switchability
CUS_REL_BASE_COMP += vendor\handwriting\guobi
# release vendor database to customer
CUS_REL_BASE_COMP += vendor\InputMethod\GUOBI\MemoryCard

CUS_REL_BASE_COMP += interface\security
CUS_REL_BASE_COMP += interface\hal\cipher\include

CUS_REL_BASE_COMP += interface\hal\opengles

# MAUI_03354743
# To avoid customer getting too many patch files,
# add this relese rule in REL_COMMON.mak not Option.mak on MP branch
ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  CUS_REL_FILES_LIST += plutommi\Customer\CustResource\PlutoAppIcon1.xml
endif

#release the bootloader_bin folder to customer
CUS_REL_BASE_COMP += bootloader_bin

# add non-release for btnotification_conn module
NON_REL_FILES_LIST += plutommi\Service\BTNotificationConn\BTNotiSrvDisp.c
NON_REL_FILES_LIST += plutommi\Service\BTNotificationConn\BTNotiSrvRecv.c

# release bam to customer
BROWSER_SUPPORT_Q03C_TYPES = OBIGO_Q03C OBIGO_Q03C_SLIM
ifdef BROWSER_SUPPORT
  ifneq ($(filter $(strip $(BROWSER_SUPPORT)) ,$(BROWSER_SUPPORT_Q03C_TYPES)),)
    CUS_REL_BASE_COMP += vendor\wap\obigo_Q03C\adaptation\modules\bam\include
  endif
endif

# release Etrump folder for switch ability
CUS_REL_BASE_COMP += make\vectorfont_etrump
CUS_REL_BASE_COMP += vendor\vectorfont\etrump
CUS_REL_BASE_COMP += plutommi\Customer\Fonts\Android \
                     plutommi\Customer\Fonts\MTK \
                     plutommi\Customer\Fonts\Arphic_demo \
                     plutommi\Customer\Fonts\Monotype_demo \
                     plutommi\Customer\Fonts\Etrump

# release tmp file for BT Box resgen
ifdef BT_PRODUCT_LINE
  ifeq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
    CUS_REL_FILES_LIST += custom\common\nvram_input_event_cfg.h.tmp
    CUS_REL_FILES_LIST += custom\common\nvram_input_event_cfg_desc.tmp
  endif
endif

# setting for tiny system
ifeq ($(strip $(TINY_SYS)),TRUE)
  CUS_REL_FILES_LIST += tiny_system\Check_ELF.men
  CUS_REL_FILES_LIST += tiny_system\Turn_off_auto_check_elf.cmm
  CUS_REL_FILES_LIST += tiny_system\Turn_on_auto_check_elf.cmm
  CUS_REL_FILES_LIST += tiny_system\make\ts_Gsm2.mak
  CUS_REL_FILES_LIST += tiny_system\make\ts_Option.mak
endif
