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

#  Define include path lists to XGEN_INC_DIR
#XGEN_INC_DIR = $(COMMINCDIRS)

ifeq ($(strip $(PPPV6_SUPPORT)),TRUE)
  PPP_FOLDER := ppp_v6
else
  PPP_FOLDER := ppp
endif

ifneq ($(strip $(L1_UMTS)),TRUE)
  XGEN_INC_DIR += $(strip $(PS_FOLDER))\rr2\common\include \
                    $(strip $(PS_FOLDER))\rr2\rrm\common\include \
                    $(strip $(PS_FOLDER))\rr2\rrm\rmc\include \
                    $(strip $(PS_FOLDER))\rr2\rrm\rcs\include \
                    $(strip $(PS_FOLDER))\rr2\lapdm\include \
                    $(strip $(PS_FOLDER))\rr2\mpal\include \
                    $(strip $(PS_FOLDER))\rr2\rlc\include \
                    $(strip $(PS_FOLDER))\rr2\mac\include \
                    $(strip $(PS_FOLDER))\rr2\rrm\rmp\include \
                    $(strip $(PS_FOLDER))\mm2\cmm\include \
                    $(strip $(PS_FOLDER))\mm2\common\include \
                    $(strip $(PS_FOLDER))\mm2\pmm\include \
                    $(strip $(PS_FOLDER))\ratcm\include \
                    $(strip $(PS_FOLDER))\ratdm\include \
                    $(strip $(PS_FOLDER))\scsi\gen\include \
                    $(strip $(PS_FOLDER))\scsi\include \
                    fsm\include
 ifdef GEMINI
    ifneq ($(strip $(GEMINI)),FALSE)
      XGEN_INC_DIR += rsva\rsvas\include \
                        rsva\interfaces\enum \
                        rsva\interfaces\local_inc \
                        rsva\interfaces\sap \
                        rsva\common\include

    endif
  endif
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA L1S,$(strip $(call Upper,$(PROJECT)))),)
    XGEN_INC_DIR += $(strip $(PS_FOLDER))\rr2\common\include \
                      $(strip $(PS_FOLDER))\rr2\rrm\common\include \
                      $(strip $(PS_FOLDER))\rr2\rrm\rmc\include \
                      $(strip $(PS_FOLDER))\rr2\rrm\rcs\include \
                      $(strip $(PS_FOLDER))\rr2\lapdm\include \
                      $(strip $(PS_FOLDER))\rr2\mpal\include \
                      $(strip $(PS_FOLDER))\rr2\rlc\include \
                      $(strip $(PS_FOLDER))\rr2\mac\include \
                      $(strip $(PS_FOLDER))\rr2\rrm\rmp\include \
                      $(strip $(PS_FOLDER))\mm2\cmm\include \
                      $(strip $(PS_FOLDER))\mm2\common\include \
                      $(strip $(PS_FOLDER))\mm2\pmm\include \
                      $(strip $(PS_FOLDER))\ratcm\include \
                      $(strip $(PS_FOLDER))\ratdm\include \
                      $(strip $(PS_FOLDER))\scsi\gen\include \
                      $(strip $(PS_FOLDER))\scsi\include \
                      $(strip $(UAS_FOLDER))\interfaces\include \
                      $(strip $(UAS_FOLDER))\asn1\gen\include \
                      $(strip $(UAS_FOLDER))\common\include \
                      $(strip $(UAS_FOLDER))\interfaces\enum \
                      $(strip $(UAS_FOLDER))\interfaces\local_inc \
                      $(strip $(UAS_FOLDER))\l2\common\include \
                      $(strip $(UAS_FOLDER))\l2\bmc\include \
                      $(strip $(UAS_FOLDER))\l2\csr\include \
                      $(strip $(UAS_FOLDER))\l2\pdcp\include \
                      $(strip $(UAS_FOLDER))\l2\rabm\include \
                      $(strip $(UAS_FOLDER))\l2\umac\include \
                      $(strip $(UAS_FOLDER))\l2\urlc\include \
                      $(strip $(UAS_FOLDER))\l2\seq\include \
                      $(strip $(UAS_FOLDER))\asn1\asn1_re\include \
                      $(strip $(UAS_FOLDER))\urr\common\include \
                      $(strip $(UAS_FOLDER))\urr\meme\include \
                      $(strip $(UAS_FOLDER))\urr\rrce\include \
                      $(strip $(UAS_FOLDER))\urr\slce\include \
                      $(strip $(UAS_FOLDER))\urr\dbme\include \
                      $(strip $(UAS_FOLDER))\urr\cise\include \
                      fsm\include 
    ifdef GEMINI            
      ifneq ($(strip $(GEMINI)),FALSE)
        XGEN_INC_DIR += rsva\rsvas\include \
                          rsva\interfaces\enum \
                          rsva\interfaces\local_inc \
                          rsva\interfaces\sap \
                          rsva\common\include \
                          rsva\rsvak\include \
                          rsva\rsvau\include \
                          rsva\rsvag\include  
      endif
    endif
    XGEN_INC_DIR += interface\uas
  endif
endif


ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
  XGEN_INC_DIR +=   $(strip $(PS_FOLDER))\sndcp\include \
                    $(strip $(PS_FOLDER))\sm\include \
                    $(strip $(PS_FOLDER))\llc\include

else
  ifeq ($(strip $(L1_UMTS)),TRUE)
    XGEN_INC_DIR += $(strip $(PS_FOLDER))\sndcp\include \
                      $(strip $(PS_FOLDER))\sm\include \
                      $(strip $(PS_FOLDER))\llc\include
  endif
endif

XGEN_INC_DIR    += $(strip $(PS_FOLDER))\config\include \
                   interface\external_mmi\wise \
                   $(strip $(PS_FOLDER))\cc-ss\cc\include \
                   $(strip $(PS_FOLDER))\sms\include \
                   $(strip $(PS_FOLDER))\$(strip $(PPP_FOLDER))\include \
                   $(strip $(PS_FOLDER))\data\include \
                   $(strip $(PS_FOLDER))\data\l2r\include \
                   $(strip $(PS_FOLDER))\data\rlp\include \
                   $(strip $(PS_FOLDER))\data\tdt\include \
                   $(strip $(PS_FOLDER))\data\t30\include \
                   $(strip $(PS_FOLDER))\data\fa\include \
                   $(strip $(PS_FOLDER))\mcd\include \
                   $(strip $(PS_FOLDER))\ircomm\include \
                   l1_dm\common 

ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
    XGEN_INC_DIR    += $(strip $(UAS_FOLDER))\l2\rfc2507\include
  endif
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
      XGEN_INC_DIR     += $(strip $(PS_FOLDER))\supl\include
      XGEN_INC_DIR     += $(strip $(PS_FOLDER))\rrlp\include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      XGEN_INC_DIR     += $(strip $(PS_FOLDER))\supl\include
      XGEN_INC_DIR     += $(strip $(PS_FOLDER))\rrlp\include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      XGEN_INC_DIR     += $(strip $(PS_FOLDER))\rrlp\include
    endif
  endif
endif


ifdef USB_TETHERING
  ifeq ($(strip $(USB_TETHERING)),TRUE)
    XGEN_INC_DIR   += $(strip $(PS_FOLDER))\ups\include
  endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    XGEN_INC_DIR  += $(strip $(PS_FOLDER))\ups\include
  endif
endif

ifneq ($(strip $(L1_UMTS)),TRUE)
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA L1S,$(strip $(call Upper,$(PROJECT)))),)
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
        XGEN_INC_DIR += ul1_hs\common
      endif
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
else
  ifeq ($(strip $(L1_UMTS)),TRUE)
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
        ifeq ($(strip $(L1_WCDMA)),TRUE)
          ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
            ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
              XGEN_INC_DIR += ul1_hs\common
            else
            endif
          endif
        endif
       endif
    endif
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
    XGEN_INC_DIR += $(strip $(PS_FOLDER))\flc2\include
  endif
endif


ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    XGEN_INC_DIR += $(strip $(PS_FOLDER))\common\as_semaphore_utility\include
  endif
endif

XGEN_INC_DIR +=  $(strip $(PS_FOLDER))\mcddll\include
XGEN_INC_DIR +=  $(strip $(PS_FOLDER))\dt\include
XGEN_INC_DIR +=  $(strip $(PS_FOLDER))\ems\include $(strip $(PS_FOLDER))\cc-ss\ss\include

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
    ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
      XGEN_INC_DIR       += $(strip $(PS_FOLDER))\dt\include
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  XGEN_INC_DIR += $(strip $(PS_FOLDER))\ems\include
endif


ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
  XGEN_INC_DIR   +=  tst\database_classb\gv \
                    tst\database_classb\unionTag
endif

XGEN_INC_DIR    +=  external_mmi\wise\bal\telephony\include \
                    $(strip $(PS_FOLDER))\tools\asn1lib\include \
                    l1_dm\common 

ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    XGEN_INC_DIR += $(strip $(PS_FOLDER))\rr2\mpal\include
  endif
endif

COMMINCDIRS += rsva\interfaces\sap 
#COMMINCDIRS += rsva\interfaces\enum

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
  XGEN_INC_DIR   +=  tst\database\gv
endif

ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  XGEN_INC_DIR   +=  tst\database\gv
endif

ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
  XGEN_INC_DIR   +=  tst\database\gv 
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
  XGEN_INC_DIR   +=  tst\database\gv
endif

ifeq ($(strip $(call Upper,$(PROJECT))),NONE)
  XGEN_INC_DIR   +=  tst\database\gv
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
else
  ifeq ($(strip $(L1_UMTS)),TRUE)
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
        ifeq ($(strip $(L1_WCDMA)),TRUE)
          ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
            ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
            else
              XGEN_INC_DIR += ul1\ul1d 
            endif
          endif
        else
          ifeq ($(strip $(L1_TDD128)),TRUE)
          else
            XGEN_INC_DIR += ul1\ul1d
          endif
        endif
      endif
    endif
  endif
endif
ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
else
  XGEN_INC_DIR += ul1\ul1d
endif

ifeq ($(strip $(L1_WCDMA)),TRUE)
  ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
      XGEN_INC_DIR += interface\ul1interface\internal
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
    XGEN_INC_DIR += interface\ul1interface\internal 
  endif
endif
ifneq ($(strip $(L1_UMTS)),TRUE)
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA L1S,$(strip $(call Upper,$(PROJECT)))),)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      XGEN_INC_DIR += interface\ul1interface\internal
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
else
  ifeq ($(strip $(L1_UMTS)),TRUE)
    ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
         XGEN_INC_DIR += interface\ul1interface\internal
      endif
    endif
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
        ifeq ($(strip $(L1_WCDMA)),TRUE)
          ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
            XGEN_INC_DIR += interface\ul1interface\internal 
          endif     
        endif
      endif
    endif
  endif
endif
ifdef AGPS_SUPPORT
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      XGEN_INC_DIR    +=  ulcs\common\include
      XGEN_INC_DIR    +=  ulcs\interfaces\local_inc
      XGEN_INC_DIR    +=  ulcs\uagps_up\include
      XGEN_INC_DIR    +=  ulcs\uagps_cp\include 
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      XGEN_INC_DIR    +=  ulcs\common\include
      XGEN_INC_DIR    +=  ulcs\interfaces\local_inc
      XGEN_INC_DIR    +=  ulcs\uagps_up\include
      XGEN_INC_DIR    +=  ulcs\uagps_cp\include 
    endif
endif

ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  XGEN_INC_DIR   +=  tst\database_classb_umts\gv \
                    tst\database_classb_umts\unionTag
endif

ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
  XGEN_INC_DIR += ul1_hs\ul1d 
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
else
  ifeq ($(strip $(L1_UMTS)),TRUE)
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
        ifeq ($(strip $(L1_WCDMA)),TRUE)
          ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
            ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
              XGEN_INC_DIR += ul1_hs\ul1d 
            endif
          endif
        endif
      endif
    endif
  endif
endif
ifeq ($(strip $(L2_HSDPA_COPRO)), TRUE)
  ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),6),T)
  else
    XGEN_INC_DIR     += $(strip $(UAS_FOLDER))\l2\seq\include
  endif
endif

ifeq ($(strip $(L2_HSUPA_COPRO)), TRUE)
  ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
  else
    XGEN_INC_DIR     += $(strip $(UAS_FOLDER))\l2\seq\include
  endif
endif


ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
else
  ifeq ($(strip $(L1_UMTS)),TRUE)
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
        ifeq ($(strip $(L1_WCDMA)),TRUE)
          ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
            ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
            else
              XGEN_INC_DIR += ul1\common 
            endif
          endif
        else
          ifeq ($(strip $(L1_TDD128)),TRUE)
          else
            XGEN_INC_DIR += ul1\common 
          endif
        endif
      endif
    endif
  endif
endif

XGEN_INC_DIR += dummyps\include\internal

ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
else
  XGEN_INC_DIR += ul1\ul1d
endif

ifneq ($(strip $(L1_UMTS)),TRUE)
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA L1S,$(strip $(call Upper,$(PROJECT)))),)
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
      else
        XGEN_INC_DIR += ul1\common
      endif
    endif
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
  XGEN_INC_DIR   +=  tst\database_classb\gv \
                    tst\database_classb\unionTag
endif

XGEN_INC_DIR += plutommi\service\browsersrv
XGEN_INC_DIR += tst\local_inc

XGEN_INC_DIR_TARGET := $(XGEN_INC_DIR)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  XGEN_INC_DIR += $(strip $(PS_FOLDER))\ratdm\include 
  ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
    XGEN_INC_DIR += ul1_hs\common
  else
    XGEN_INC_DIR += ul1\common
  endif
  XGEN_INC_DIR := tst\database_MoDIS\gv \
                  tst\database_MoDIS\unionTag \
                  $(XGEN_INC_DIR)
endif

