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
# Custom Release Component Configuration
# *************************************************************************
# Be sure the following:
#    1. COMPLIST(for CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
#    2. CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP + CUS_REL_MTK_COMP = COMPLIST(CUSTOM_RELEASE = False)

CUS_REL_OPTION_FILTER   = TRUE
CUS_REL_HISTORY_FILTER  = TRUE

CUS_REL_BASE_COMP       =
CUS_REL_HDR_COMP        =
CUS_REL_FILES_LIST      =
CUS_REL_OBJ_LIST        =
NON_REL_FILES_LIST      =
NON_REL_DIRS_LIST       =

# Forbidden feature
ifdef CHIP_VERSION_CHECK
  ifneq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
    $(error Please set CHIP_VERSION_CHECK as TRUE !!)
  endif
endif

# Different Release Levels for plutommi/lcmmi related components
# LEVEL1:      Customer can change ~50% image files and view on PC simulator
# LEVEL2_OBJ:  Customer can change some resources and use PC simulator and Network simulator
# LEVEL2_SRC:  Customer will have the source code of PC simulator and Network simulator

ifndef LEVEL
  LEVEL = LEVEL2_SRC
endif

include make\REL_COMP_CR_MMI.mak
CUS_REL_FILES_LIST += make\REL_COMP_CR_MMI.mak

ifndef MMI_BASE
  MMI_BASE = PLUTO_MMI
  MMIDIR         =  plutommi
else
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    MMIDIR         =  lcmmi
  else
    MMIDIR         =  plutommi
  endif
endif

MMI_PROJ = $(strip $(subst _MMI,,$(MMI_VERSION)))
ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  MMI_PROJ := PLUTO
endif

ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL1)
   ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
     CUS_REL_BASE_COMP   +=
   else
     CUS_REL_BASE_COMP   += plutommi\WIN32FS
   endif
else
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
    CUS_REL_BASE_COMP  += plutommi\WIN32FS
  else
    ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
      ifdef SUB_LCD_SIZE
        ifneq ($(strip $(SUB_LCD_SIZE)),NONE)
          ifeq ($(strip $(call Upper,$(EMPTY_RESOURCE))),FALSE)
            ifeq ($(findstring BW,$(strip $(SUB_LCD_SIZE))),BW)
              SUB_MMI_PRJ := SubLCDBW$(strip $(subst BW,,$($(SUB_LCD_SIZE))))
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(SUB_MMI_PRJ))
            else
              SUB_MMI_PRJ := SubLCD$(strip $(SUB_LCD_SIZE))
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(SUB_MMI_PRJ))
            endif
          endif
        endif
      endif

      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
        CUS_REL_BASE_COMP   += $(strip $(MMIDIR))\mmi $(strip $(MMIDIR))\mtkapp $(strip $(MMIDIR))\tool $(MMIDIR)\WIN32FS
        CUS_REL_BASE_COMP   += $(strip $(MMIDIR))\Customer\CustomerInc \
                               $(strip $(MMIDIR))\Customer\Customize \
                               $(strip $(MMIDIR))\Customer\CustResource\$(strip $(MMI_VERSION)) \
                               $(strip $(MMIDIR))\Customer\debug \
                               $(strip $(MMIDIR))\Customer\Images\GameImages \
                               $(strip $(MMIDIR))\Customer\Images\decoder \
                               $(strip $(MMIDIR))\Customer\Res_MMI \
                               $(strip $(MMIDIR))\Customer\ResGenerator \
                               $(strip $(MMIDIR))\Customer\ResourceDLL \
                               $(strip $(MMIDIR))\Customer\Resources \
                               $(strip $(MMIDIR))\Customer\Audio
      endif
      ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
        CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\CustResource\PLUTO_MMI
      endif
      ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
        CUS_REL_BASE_COMP   += $(strip $(MMIDIR))\Customer\CustResource\PLUTO_MMI
      endif

      ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
        ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
          ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
            CUS_REL_BASE_COMP    += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))
          endif
        endif
      else
        ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
          ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
            ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Framework $(strip $(MMIDIR))\CUI $(strip $(MMIDIR))\Service
              IMAGE_FOLDER = $(shell dir $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE)) /b 2>nul)
              ifeq ($(words $(IMAGE_FOLDER)),0)
                CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))
              else
                CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE))
              endif
              ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
                CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))
              endif
              ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
                CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\FTE$(strip $(MAIN_LCD_SIZE))
              endif
            endif
          endif
        else
          ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
            IMAGE_FOLDER = $(shell dir $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE)) /b 2>nul)
            ifeq ($(words $(IMAGE_FOLDER)),0)
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))
            else
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE))
            endif
            ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))
            endif
            ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\FTE$(strip $(MAIN_LCD_SIZE))
            endif
          endif
        endif
      endif
    endif
  endif
endif

include make\REL_COMMON.mak

ifdef RELEASE_BASE_COMP
  CUS_REL_BASE_COMP += $(RELEASE_BASE_COMP)
endif

ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  CUS_REL_BASE_COMP += external_mmi
endif

CUS_REL_BASE_COMP += tools
CUS_REL_BASE_COMP += MoDIS_VC9\filesystem
CUS_REL_BASE_COMP += interface\hwdrv

ifndef CUSTOM_OPTION
  $(error Please define CUSTOM_OPTION before include release package make file in project make file )
endif

ifdef TCPIP_SUPPORT
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
     CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\interfaces\local_inc\tcpip2abm_struct.h \
                           $(strip $(PS_FOLDER))\interfaces\local_inc\soc2mmi_struct.h \
                           $(strip $(PS_FOLDER))\interfaces\local_inc\soc2tcpip_struct.h \
                           inet_ps\soc\include\soc_feature.h \
                           inet_ps\soc\include\soc_defs.h \
                           inet_ps\soc\include\soc_enum.h \
                           inet_ps\soc\include\soc_dns.h \
                           inet_ps\soc\include\soc_struct.h \
                           inet_ps\soc\include\soc_abm.h \
                           inet_ps\soc\include\soc_app.h
  endif
endif

ifdef GAME_ENGINE
  ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
    CUS_REL_BASE_COMP += vendor\game_engine\brogent
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    CUS_REL_BASE_COMP += vendor\game_engine\intergrafx
  endif
endif

CUS_REL_FILES_LIST      +=  $(strip $(PS_FOLDER))\interfaces\local_inc\wap_ps_struct.h \
                            media\audio\include\aud_dec_imdct_s.dat \
                            media\audio\include\aud_dec_qc_table.dat \
                            media\audio\include\aud_dec_rq_table.dat \
                            media\audio\include\aud_dec_sf_table.dat \
                            media\audio\include\aud_id3_genre.dat

CUS_REL_FILES_LIST   += media\audio\include\aud_mad_tagger.h 

CUS_REL_BASE_COMP += MoDIS_VC9\NetSim
CUS_REL_FILES_LIST += MoDIS_VC9\NetSimScript.msc
CUS_REL_FILES_LIST += interface\ps\abm_api.h
CUS_REL_FILES_LIST += inet_ps\abm\include\abm_main.h
CUS_REL_FILES_LIST += inet_ps\abm\include\abm_util.h
CUS_REL_FILES_LIST += $(strip $(PS_FOLDER))\interfaces\enum\mmi_sm_enums.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\abm2soc_struct.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\soc2abm_struct.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\l4c2abm_struct.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\abm2l4c_struct.h \
                      interface\ps\cbm_api.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\mmi2abm_struct.h \
                      inet_ps\abm\include\abm_def.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\app2cbm_struct.h \
                      $(strip $(PS_FOLDER))\interfaces\enum\dhcp_abm_enums.h \
                      $(strip $(PS_FOLDER))\interfaces\local_inc\dhcp2abm_struct.h \
                      drv\idp\include\legacy\img_comm.h \
                      interface\inet_ps\dhcp_consts.h \
                      interface\wifi\wndrv_supc_types.h \
                      interface\wifi\wndrv_api.h \
                      interface\wifi\supc_abm_msgs.h
                      
ifneq ($(filter PLUTO_MMI VENUS_MMI,$(strip $(MMI_BASE))),)
  CUS_REL_FILES_LIST += plutommi\Framework\MTE\MTEInc\mteGprot.h \
                        plutommi\Framework\MTE\MTEInc\mte.h \
                        plutommi\Framework\MTE\MTEInc\mte_data.h \
                        plutommi\Customer\CustResource\mte_img_resource.h
endif

CUS_REL_FILES_LIST += tst\database\msglog_db\custom_parse_db.c

########################################################################################
# Custimization part
########################################################################################
ifeq ($(findstring MMI_ZI,$(RELEASE_INPUT_METHODS_SRC)),MMI_ZI)
  CUS_REL_BASE_COMP    += vendor\InputMethod\ZI\adaptation make\zi
endif

ifeq ($(findstring MMI_T9,$(RELEASE_INPUT_METHODS_SRC)),MMI_T9)
  CUS_REL_BASE_COMP    += vendor\InputMethod\T9\adaptation make\t9
endif

ifeq ($(findstring MMI_KA,$(RELEASE_INPUT_METHODS_SRC)),MMI_KA)
  CUS_REL_BASE_COMP    += vendor\InputMethod\KA\adaptation make\ka
endif

ifeq ($(findstring MMI_ITAP,$(RELEASE_INPUT_METHODS_SRC)),MMI_ITAP)
  CUS_REL_BASE_COMP    += vendor\InputMethod\ITAP\adaptation make\itap
endif

ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
    CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_11.lib
  endif
  ifeq ($(strip $(J2ME_VM)),HI_VM)
    CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_hi.lib
  endif
endif

