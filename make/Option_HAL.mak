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
# Common include file and output directory path
# *************************************************************************

ifndef AUDLIB
  ifeq ($(strip $(RVCT_VERSION)),V22)
    AUDLIB         =  hal\audio\lib\MTKRVCT22
  endif
  ifeq ($(strip $(RVCT_VERSION)),V31)
    AUDLIB         =  hal\audio\lib\MTKRVCT31
  endif
endif

ifndef RTOS
  RTOS = NUCLEUS
endif

ifndef RTOS_DEBUG
  RTOS_DEBUG = TRUE
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COMMINCDIRS   +=  nucleus\inc \
                    kal\include kal\common\include \
                    kal\nucleus\include \
                    kal\mlib\include
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  COMMINCDIRS   +=  nucleus_v2\inc \
                    kal\include kal\common\include \
                    kal\nucleus\include \
                    kal\mlib\include
endif

ifeq ($(strip $(RTOS)),THREADX)
  COMMINCDIRS   +=  threadx\inc \
                    kal\include kal\common\include \
                    kal\threadx\include \
                    kal\mlib\include
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COM_DEFS += KAL_ON_NUCLEUS
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  COM_DEFS += KAL_ON_NUCLEUS __NUCLEUS_VERSION_2__
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),THREADX)
  COM_DEFS += KAL_ON_THREADX
  COM_DEFS += TX_ENABLE_IRQ_NESTING TX_DISABLE_NOTIFY_CALLBACKS \
              TX_DISABLE_PREEMPTION_THRESHOLD TX_DISABLE_STACK_FILLING TX_REACTIVE_INLINE
  ifneq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += TX_DISABLE_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
  COMMINCDIRS   +=  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  COMMINCDIRS   +=  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
  COMMINCDIRS   +=  tst\database\unionTag \
                    meut\include
endif

ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
  COMMINCDIRS   +=  tst\database\unionTag
endif

ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
  COMMINCDIRS += ul1_hs\ul1d_ext
else
  COMMINCDIRS += ul1\ul1d_ext
endif

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  COMP_TRACE_DEFS += drv\include\drv_trc.h
endif

ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
  COMP_TRACE_DEFS += drv\include\drv_trc.h
endif

COMMINCDIRS   +=  hal\drv_def
COMMINCDIRS   +=  hal\display\lcd_power_manager\inc
COMMINCDIRS   +=  hal\graphics\jpeg\common\inc
COMMINCDIRS   +=  hal\lqt\include
COMMINCDIRS   +=  hal\video\mpl\inc
COMMINCDIRS   +=  hal\video\demuxer\mp4_parser\inc
COMMINCDIRS   +=  hal\video\common\include
COMMINCDIRS   +=  hal\video\renderer\include
COMMINCDIRS   +=  hal\video\video_sec\common\include
COMMINCDIRS   +=  hal\video\fluency\include
COMMINCDIRS   +=  hal\video\fluency_sec\include
COMMINCDIRS   +=  hal\video\custom
COMMINCDIRS   +=  hal\video_codec\interface\inc
COMMINCDIRS   +=  hal\video\demuxer\provider\inc
COMMINCDIRS   +=  hal\system\pmu\inc
COMMINCDIRS   +=  interface\bt
COMMINCDIRS   +=  interface\bcm
COMMINCDIRS   +=  interface\hal
COMMINCDIRS   +=  interface\hal\bluetooth\public
COMMINCDIRS   +=  interface\hal\connectivity\usb_driver
COMMINCDIRS   +=  interface\hal\display
COMMINCDIRS   +=  interface\hal\display\ddv1
COMMINCDIRS   +=  interface\hal\display\lcm_if
COMMINCDIRS   +=  interface\hal\display\common
COMMINCDIRS   +=  interface\hal\display\wfc
COMMINCDIRS   +=  interface\hal\audio
COMMINCDIRS   +=  interface\hal\video
COMMINCDIRS   +=  interface\hal\drv_sw_def
COMMINCDIRS   +=  interface\hal\storage\mc
COMMINCDIRS   +=  interface\hal\graphics
COMMINCDIRS   +=  interface\hal\drv_sw_def
COMMINCDIRS   +=  interface\hal\storage\sim
COMMINCDIRS   +=  interface\hal\peripheral
COMMINCDIRS   +=  interface\hal\cipher\include
COMMINCDIRS   +=  interface\meta
COMMINCDIRS   +=  interface\wifi
COMMINCDIRS   +=  interface\wmt
COMMINCDIRS   +=  $(strip $(PS_FOLDER))\l4\smu\include $(strip $(PS_FOLDER))\l4\rac\include
COMMINCDIRS   +=  $(strip $(PS_FOLDER))\interfaces\asn\rr\include
COMMINCDIRS   +=  custom\video\$(strip $(BOARD_VER))
COMMINCDIRS   +=  custom\video\default
COMMINCDIRS   +=  interface\hal\opengles\MALI400MP
COMMINCDIRS   +=  interface\hal\opengles\MALI400MP\khronos
COMMINCDIRS   +=  interface\hal\opengles\MALI400MP\khronos\EGL
COMMINCDIRS   +=  interface\hal\opengles\MALI400MP\khronos\GLES
COMMINCDIRS   +=  interface\hal\opengles\MALI400MP\khronos\GLES2
COMMINCDIRS   +=  interface\hal\opengles\MALI400MP\khronos\KHR
COMMINCDIRS   +=  interface\hal\opengles
COMMINCDIRS   +=  interface\hal\security
COMMINCDIRS   +=  interface\media\video

COMMINCDIRS +=  $(strip $(PS_FOLDER))\smslib\include

ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  ifeq ($(strip $(VENDOR)),NONE)
    CUS_REL_BASE_COMP += hal\graphics\bfc
    CUS_REL_BASE_COMP += interface\hal\graphics
  endif
else
  CUS_REL_BASE_COMP += hal\graphics\bfc
  CUS_REL_BASE_COMP += interface\hal\graphics
endif

COMP_TRACE_DEFS   += hal\video\common\include\vcodec_v2_trc.h

CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters.h
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters_FDD.ini
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters_TDD.ini
CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters_2G_FDD.ini
CUS_REL_FILES_LIST   +=  tst\database\TrcGen.lst
CUS_REL_FILES_LIST   +=  tst\database\Pc_Cnf

CUS_REL_FILES_LIST   +=  interface\hal\graphics\bfc_decode_api.h \
                         interface\hal\graphics\bfc_enum.h

CUS_REL_FILES_LIST   +=  $(strip $(PS_FOLDER))\interfaces\enum\mm_mmi_enums.h

ifeq ($(strip $(ISP_SUPPORT)),TRUE)
  COMPLIST += camera_sec
endif

COMPLIST += mtd system gfx_drv gfx_core16 gfx_core32 peripheral usb_driver
ifeq ($(strip $(GSM_PS_SUPPORT)),TRUE)
  COMPLIST += sim_driver
endif

# GEMINI
ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    ifneq ($(strip $(GEMINI)),2)
      ifneq ($(filter __LOWCOST_MERGE_TASK__,$(COM_DEFS)),)
            $(warning ERROR: __LOWCOST_MERGE_TASK__ cannot be defined when GEMINI_PLUS is larger than 2)
            DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    COMPLIST += rsva
    
    ifndef SENDKEY_MODE
      $(call DEP_ERR_ONA_OR_OFFB,SENDKEY_MODE,GEMINI)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef PLATFORM
      ifneq ($(filter MT6223%,$(PLATFORM)),)
        ifneq ($(strip $(PLATFORM)),MT6223P)
          ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
            $(call DEP_ERR_SETA_OR_OFFB,PLATFORM,MT6223P,GEMINI)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif

    COMP_TRACE_DEFS += l1_dm\common\l1a_trace.h

    COM_DEFS += __GEMINI__ __GEMINI_GSM__ __GSM_RAT__ DRV_MULTIPLE_SIM __CTA_DUAL_SIM_STANDARD__
    COM_DEFS += __L4C_ROOT__

    ifneq ($(strip $(GEMINI)),2)
      ifneq ($(strip $(SIM_PROVISIONING)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,GEMINI,FALSE or 2,SIM_PROVISIONING)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    # assign GEMINI to GEMINI_PLUS_GSM
    ifndef GEMINI_PLUS
      GEMINI_PLUS = $(strip $(GEMINI))
    endif
    ifndef GEMINI_PLUS_GSM
      GEMINI_PLUS_GSM = $(strip $(GEMINI))
    endif

    COM_DEFS    += GEMINI_PLUS=$(strip $(GEMINI))
    COM_DEFS    += GEMINI_PLUS_GSM=$(strip $(GEMINI_PLUS_GSM))
       
    COMPLIST += as_semaphore_utility

    ifneq ($(filter MT6223P,$(strip $(PLATFORM))),)
      ifdef TOUCH_PANEL_SUPPORT
        ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
          COM_DEFS     += __DRV_SIM_TP_SHARE_PIN__
        endif
      endif
    endif
  endif
endif

# MP4_ENCODE MP4_DECODE
MP4_CODEC_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B

ifndef MP4_ENCODE
  MP4_ENCODE = FALSE
endif

ifndef MP4_DECODE
  MP4_DECODE = FALSE
endif

ifeq ($(strip $(MP4_DECODE)),FALSE)
  ifneq ($(strip $(MP4_DECODE_PROFILE)),NONE)
      $(warning ERROR: MP4_DECODE_PROFILE must be NONE when MP4_DECODE = FALSE)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MP4_DECODE)),TRUE)
  ifeq ($(strip $(MP4_DECODE_PROFILE)),NONE)
      $(warning ERROR: MP4_DECODE_PROFILE cannot be NONE when MP4_DECODE = TRUE)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MP4_ENCODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_CODEC_NOT_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(MP4_ENCODE)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MP4_DECODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_CODEC_NOT_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(MP4_DECODE)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MP4_DECODE)),TRUE)
  SW_VIDEO_RESIZER_ADV_SUPPORT_PLATFORM = MT6235 MT6235B 
  ifneq ($(filter $(strip $(PLATFORM)),$(SW_VIDEO_RESIZER_ADV_SUPPORT_PLATFORM)),)
    COM_DEFS    += __SW_VIDEO_ADV_RESIZER_SUPPORT__
  endif
endif

ifeq ($(strip $(MP4_ENCODE)),TRUE)
  ifdef ISP_SUPPORT
    ifeq ($(strip $(ISP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,MP4_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(strip $(AMR_CODEC)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,MP4_ENCODE)
    DEPENDENCY_CONFLICT = TRUE
  endif       
endif

MP4_SW_CODEC_V1_PLATFORM = MT6225
MP4_HW_CODEC_V1_PLATFORM = MT6229 MT6238 MT6239
MP4_SW_CODEC_V2_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6253 MT6253T MT6253E MT6253L MT6256 MT6276 MT6252 MT6252H MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
MP4_HW_CODEC_V2_PLATFORM = MT6268 MT6268A MT6268T MT6268H

ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = FALSE

ifeq ($(strip $(MP4_DECODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V2_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V2__
    COM_DEFS    += __VDEC_SUPPORT__
    COM_DEFS    += MP4_DECODE
    COM_DEFS    += __MP4_DEC_SW_SUPPORT__
    COM_DEFS    += __MPEG4_DEC_SUPPORT__
    COM_DEFS    += __MPEG4_DEC_SW_SUPPORT__
  endif
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V1_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V1__
    COM_DEFS    += MP4_DECODE
    COM_DEFS    += __MP4_DEC_SW_SUPPORT__
    ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
  endif
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V2_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V2__
    COM_DEFS    += __VDEC_SUPPORT__
    COM_DEFS    += MP4_DECODE
    COM_DEFS    += __MP4_DEC_HW_SUPPORT__
    COM_DEFS    += __MPEG4_DEC_SUPPORT__
    COM_DEFS    += __MPEG4_DEC_HW_SUPPORT__
  endif
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V1_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V1__
    COM_DEFS    += MP4_DECODE
    COM_DEFS    += __MP4_DEC_HW_SUPPORT__
  endif
endif

ifeq ($(strip $(MP4_ENCODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V2_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V2__
    COM_DEFS    += __VENC_SUPPORT__
    COM_DEFS    += MP4_ENCODE
    COM_DEFS    += __MP4_ENC_SW_SUPPORT__
    COM_DEFS    += __MPEG4_ENC_SUPPORT__
    COM_DEFS    += __MPEG4_ENC_SW_SUPPORT__
  endif
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V1_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V1__
    COM_DEFS    += MP4_ENCODE
    COM_DEFS    += __MP4_ENC_SW_SUPPORT__
    ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
  endif
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V2_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V2__
    COM_DEFS    += __VENC_SUPPORT__
    COM_DEFS    += MP4_ENCODE
    COM_DEFS    += __MP4_ENC_HW_SUPPORT__
    COM_DEFS    += __MPEG4_ENC_SUPPORT__
    COM_DEFS    += __MPEG4_ENC_HW_SUPPORT__
  endif
  ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V1_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V1__
    COM_DEFS    += MP4_ENCODE
    COM_DEFS    += __MP4_ENC_HW_SUPPORT__
  endif
endif

ifdef VDOEDT_SUPPORT
  VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6227 MT6227D MT6226D
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
    ifneq ($(strip $(MP4_DECODE)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,MP4_DECODE,TRUE,VDOEDT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MP4_ENCODE)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,MP4_ENCODE,TRUE,VDOEDT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V1_PLATFORM)),)
      $(warning ERROR: VDOEDT_SUPPORT require MP4_HW which is not supported by PLATFORM=$(strip $(PLATFORM)))
      DEPENDENCY_CONFLICT = TRUE    
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support VDOEDT_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: VDOEDT_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
     COM_DEFS    += VDOEDT_SUPPORT
     COM_DEFS    += __VIDEO_EDITOR__
  endif
endif

NVRAM_REDUCTION_NOT_SUPPORT_PLATFORM = MT6236 MT6268
ifeq ($(filter $(strip $(PLATFORM)) ,$(NVRAM_REDUCTION_NOT_SUPPORT_PLATFORM)),)
   COM_DEFS    += __CAMERA_NVRAM_REDUCTION_ISP_SUPPORT__
   COM_DEFS    += __CAMERA_NVRAM_REDUCTION__
endif

ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = FALSE

ifdef MP4_DECODE
  ifeq ($(strip $(MP4_DECODE)),TRUE)
    ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
  endif
endif
ifdef MP4_ENCODE
  ifeq ($(strip $(MP4_ENCODE)),TRUE)
    ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
  endif
endif
ifdef H264_DECODE
  ifeq ($(strip $(H264_DECODE)),TRUE)
    ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
  endif
endif
ifeq ($(strip $(M4A_DECODE)),TRUE)
  ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
  ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
endif

ifdef STREAM_SERVER_SUPPORT
  ifeq ($(strip $(STREAM_SERVER_SUPPORT)),TRUE)
    ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = FALSE
  endif
endif

ifeq ($(strip $(ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION)),TRUE)
  ifneq ($(strip $(M3GPMP4_FILE_FORMAT_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,M3GPMP4_FILE_FORMAT_SUPPORT,MP4_DECODE & MP4_ENCODE & H264_DECODE & M4A_DECODE & PURE_AUDIO_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(M3GPMP4_FILE_FORMAT_SUPPORT)),TRUE)
  COM_DEFS    += __M3GPMP4_FILE_FORMAT_SUPPORT__
endif

# H264_ENCODE H264_DECODE
H264_SW_CODEC_V1_PLATFORM =
H264_HW_CODEC_V1_PLATFORM = MT6238 MT6239
H264_SW_CODEC_V2_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6253 MT6253E MT6253L MT6253T MT6256 MT6276 MT6252 MT6252H MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
H264_HW_CODEC_V2_PLATFORM = MT6268 MT6268A MT6268T MT6268H

ifdef H264_DECODE
  ifeq ($(strip $(H264_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_SW_CODEC_V2_PLATFORM)),)
      COM_DEFS    += __VIDEO_ARCHI_V2__
      COM_DEFS    += __VDEC_SUPPORT__
      COM_DEFS    += H264_DECODE
      COM_DEFS    += __H264_DEC_SW_SUPPORT__
      COM_DEFS    += __H264_DEC_SUPPORT__
    else
      ifneq ($(filter $(strip $(PLATFORM)),$(H264_SW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += H264_DECODE
        COM_DEFS    += __H264_DEC_SW_SUPPORT__
        ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(H264_HW_CODEC_V2_PLATFORM)),)
          COM_DEFS    += __VIDEO_ARCHI_V2__
          COM_DEFS    += __VDEC_SUPPORT__
          COM_DEFS    += H264_DECODE
          COM_DEFS    += __H264_DEC_HW_SUPPORT__
          COM_DEFS    += __H264_DEC_SUPPORT__
        else
          ifneq ($(filter $(strip $(PLATFORM)),$(H264_HW_CODEC_V1_PLATFORM)),)
            COM_DEFS    += __VIDEO_ARCHI_V1__
            COM_DEFS    += H264_DECODE
            COM_DEFS    += __H264_DEC_HW_SUPPORT__
          else
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support H264_DECODE = TRUE)
            DEPENDENCY_CONFLICT = TRUE 
          endif
        endif
      endif
    endif
  endif
endif

H264ENC_SW_CODEC_V2_PLATFORM = MT6276 MT6256 MT6255 MT6922 MT6260 MT6261 MT2501 MT2502
ifeq ($(strip $(H264_ENCODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(H264ENC_SW_CODEC_V2_PLATFORM)),)
    COM_DEFS    += __VIDEO_ARCHI_V2__
    COM_DEFS    += __VENC_SUPPORT__
    COM_DEFS    += H264_ENCODE
    COM_DEFS    += __H264_ENC_SUPPORT__
    COM_DEFS    += __H264_ENC_SW_SUPPORT__
  else
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support H264_ENCODE = TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(H264_ENCODE)),H264_SW)
  ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
endif

ifeq ($(strip $(ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS)),TRUE)
  COMP_TRACE_DEFS += media\vcodec\include\vcodec_trc.h
endif

# RM_DECODE
RV_SW_CODEC_V2_PLATFORM = MT6236 MT6236B MT6253 MT6253E MT6253L MT6253T MT6276 MT6252 MT6252H MT6921 MT6256 MT6235 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifeq ($(strip $(RM_DECODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(RV_SW_CODEC_V2_PLATFORM)),)
      COM_DEFS    += __VIDEO_ARCHI_V2__
      COM_DEFS    += __VDEC_SUPPORT__
      COM_DEFS    += __RM_DEC_SUPPORT__
      COM_DEFS    += __RV_DEC_SW_SUPPORT__
  else
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support RM_DECODE = TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

H264_SW_OPEN_API_PLATFORM = MT6236 MT6921 MT6255 MT6922
H264_HW_OPEN_API_PLATFORM = MT6238
ifdef H264_OPEN_API
  ifeq ($(strip $(H264_OPEN_API)),TRUE)
    ifneq ($(strip $(H264_DECODE)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,H264_DECODE,TRUE,H264_OPEN_API)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_SW_OPEN_API_PLATFORM)),)
      COM_DEFS    += __H264_SW_OPEN_API_SUPPORT__
    else
      ifneq ($(filter $(strip $(PLATFORM)),$(H264_HW_OPEN_API_PLATFORM)),)
        COM_DEFS    += __H264_HW_OPEN_API_SUPPORT__
      else
        $(warning ERROR: H264_OPEN_API is not supported by PLATFORM=$(strip $(PLATFORM)))
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    CUS_REL_FILES_LIST += media\video\h264\include\h264_open_api_video_if.h
  endif
endif

# SENSOR_TYPE
RAW_SENSOR_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B MT6225 MT6235 MT6235B MT6255 MT6256 MT6250 MT6260 MT6261 MT2501 MT2502
YUV_SENSOR_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B

ifdef SENSOR_TYPE
  ifneq ($(strip $(SENSOR_TYPE)),NONE)
    ifeq ($(strip $(PLATFORM)),MT6223P)
      ifneq ($(strip $(SENSOR_TYPE)),DIRECT)
        $(warning ERROR: MT6223P only supports SENSOR_TYPE=DIRECT, please change SENSOR_TYPE value)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(CMOS_SENSOR)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,SENSOR_TYPE)
         DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non RAW,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(RAW_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE)))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif

    ifeq ($(strip $(SENSOR_TYPE)),YUV)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non YUV,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(YUV_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE)))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif

    ifeq ($(strip $(SENSOR_TYPE)),JPEG)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non JPEG,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(YUV_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE)))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif

    ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
         $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,non DIRECT,ISP_SUPPORT)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(PLATFORM)),MT6223P)
         $(warning ERROR: Only MT6223P supports SENSOR_TYPE = DIRECT) 
         DEPENDENCY_CONFLICT = TRUE
      endif
      6223_SUPPORT_LCD_SIZE = 240X320 176X220 128X160 128X128 
      ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(6223_SUPPORT_LCD_SIZE)),)
        $(warning ERROR: $(strip $(MAIN_LCD_SIZE)) only supports $(6223_SUPPORT_LCD_SIZE) when CMOS_SENSOR is enabled)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

  else
    ifneq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,ISP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DIRECT_IF_V2_PLATFORM = NONE
SERIAL_IF_V1_PLATFORM = MT6253E MT6253L MT6252 MT6252H MT6256 MT6276 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502

ifdef SENSOR_TYPE
  ifneq ($(strip $(SENSOR_TYPE)),NONE)
    ifdef CMOS_SENSOR
      ifneq ($(strip $(CMOS_SENSOR)),NONE)
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COM_DEFS += RAW_MAIN_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COM_DEFS += YUV_MAIN_CAMERA
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif
        endif
        ifeq ($(strip $(SENSOR_TYPE)),JPEG)
          COM_DEFS += YUV_MAIN_CAMERA
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR)),)
          COM_DEFS += DIRECT_V2_MAIN_CAMERA
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR)),)
          COM_DEFS += SERIAL_V1_MAIN_CAMERA
        endif
      endif
    endif    
    ifdef CMOS_SENSOR_BAK1
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COM_DEFS += RAW_BAK1_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COM_DEFS += YUV_BAK1_CAMERA
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_BAK1)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_BAK1)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif
        endif
        ifeq ($(strip $(SENSOR_TYPE)),JPEG)
          COM_DEFS += YUV_BAK1_CAMERA
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_BAK1)),)
          COM_DEFS += DIRECT_V2_BAK1_CAMERA
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_BAK1)),)
          COM_DEFS += SERIAL_V1_BAK1_CAMERA
        endif
      endif
    endif
  endif
endif

ifdef SENSOR_TYPE_SUB
  ifneq ($(strip $(SENSOR_TYPE_SUB)),NONE)
    ifdef CMOS_SENSOR_SUB
      ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COM_DEFS += RAW_SUB_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COM_DEFS += YUV_SUB_CAMERA
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
          COM_DEFS += YUV_SUB_CAMERA
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB)),)
          COM_DEFS += DIRECT_V2_SUB_CAMERA
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB)),)
          COM_DEFS += SERIAL_V1_SUB_CAMERA
        endif
      endif
    endif 
    ifdef CMOS_SENSOR_SUB_BAK1 
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COM_DEFS += RAW_SUB_BAK1_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COM_DEFS += YUV_SUB_BAK1_CAMERA
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB_BAK1)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB_BAK1)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
          COM_DEFS += YUV_SUB_BAK1_CAMERA
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB_BAK1)),)
          COM_DEFS += DIRECT_V2_SUB_BAK1_CAMERA
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB_BAK1)),)
          COM_DEFS += SERIAL_V1_SUB_BAK1_CAMERA
        endif
      endif
    endif
  endif
endif

# GPS_SUPPORT
ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
    COMP_TRACE_DEFS += gps\inc\gps_trc.h
    COMP_TRACE_DEFS += gps\bee\inc\bee_trc.h
    COMP_TRACE_DEFS += gps\mnl\include\mnl_trc.h
  endif
endif

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
    COM_DEFS    += __GPS_SUPPORT__
    ifeq ($(strip $(GPS_ADAPTOR_SUPPORT)),TRUE)
      COM_DEFS += __GPS_AT_SUPPORT__
      COM_DEFS += __LONG_AT_CMD_SUPPORT__
      COM_DEFS += __GPS_ADAPTOR_SUPPORT__
      ifeq ($(strip $(XYSSL_SUPPORT)),TRUE)
        COM_DEFS += __GPS_SSL_SUPPORT__
        COMPOBJS += gps\ssl\lib\epo_xyssl.lib
        CUS_REL_OBJ_LIST += gps\ssl\lib\epo_xyssl.lib
      endif
    endif
    ifeq ($(strip $(GPS_UART_PORT)),UART3)        # GPS module is connected to UART3
      COM_DEFS    += __GPS_USE_UART3__
    else
      COM_DEFS    += __GPS_USE_UART2__
      COM_DEFS    += __ONLY_ONE_UART__
    endif
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)  
      COM_DEFS    += __FEATURE_PHONE_MODEM__
    endif
    COMPLIST    += gps gps_sec
    ifeq ($(strip $(GPS_SUPPORT)),MT3316)
      COM_DEFS    += __GPS_MT3316__
    endif
    
    ifeq ($(strip $(GPS_SUPPORT)),MT3326)
      COM_DEFS    += __GPS_MT3326__ __MNL_SUPPORT__
      COMPLIST    += mnl
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += gps\mnl\lib\MTKNav_rvct.lib
        CUS_REL_OBJ_LIST += gps\mnl\lib\MTKNav_rvct.lib
      else
        COMPOBJS    += gps\mnl\lib\MTKNav.lib
        CUS_REL_OBJ_LIST += gps\mnl\lib\MTKNav.lib
      endif
    endif

    ifeq ($(strip $(GPS_SUPPORT)),MT3336) # GPS MT3336
      COM_DEFS    += __GPS_MT3336__ __MNL_SUPPORT__
      COMPLIST    += mnl
      ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        CUS_REL_BASE_COMP += gps\mnl\lib_internal\MT3336
        CUS_REL_OBJ_LIST  += gps\mnl\lib\MT3336\MTKNav_WIN32.lib
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += gps\mnl\lib_internal\MT3336\MTKNav_rvct_internal.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib_internal\MT3336\MTKNav_rvct_internal.lib
        else
          COMPOBJS    += gps\mnl\lib_internal\MT3336\MTKNav_internal.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib_internal\MT3336\MTKNav_internal.lib
        endif
      else
        CUS_REL_BASE_COMP += gps\mnl\lib\MT3336
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += gps\mnl\lib\MT3336\MTKNav_rvct.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib\MT3336\MTKNav_rvct.lib
        else
          COMPOBJS    += gps\mnl\lib\MT3336\MTKNav.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib\MT3336\MTKNav.lib
        endif
      endif
    endif
   
    ifeq ($(strip $(GPS_SUPPORT)),MT3332) # GPS MT3332
      COM_DEFS    += __GPS_MT3332__ __MNL_SUPPORT__
      COM_DEFS    += __GLONASS_SUPPORT__ 
     # COM_DEFS   += __GALILEO_SUPPORT__ 
     # COM_DEFS   += __COMPASS_SUPPORT__  
      COMPLIST    += mnl
      ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        CUS_REL_BASE_COMP += gps\mnl\lib_internal\MT3332
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += gps\mnl\lib_internal\MT3332\MTKNav_rvct_internal.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib_internal\MT3332\MTKNav_rvct_internal.lib
        else
          COMPOBJS    += gps\mnl\lib_internal\MT3332\MTKNav_internal.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib_internal\MT3332\MTKNav_internal.lib
        endif
      else
        CUS_REL_BASE_COMP += gps\mnl\lib\MT3332
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += gps\mnl\lib\MT3332\MTKNav_rvct.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib\MT3332\MTKNav_rvct.lib
        else
          COMPOBJS    += gps\mnl\lib\MT3332\MTKNav.lib
          CUS_REL_OBJ_LIST += gps\mnl\lib\MT3332\MTKNav.lib
        endif
      endif
    endif

    ifeq ($(strip $(GPS_SUPPORT)),MT3333) # GPS MT3333
      COM_DEFS += __GPS_MT3333__ 
      COM_DEFS += __GPS_ALL_IN_ONE_AT_SUPPORT__
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COM_DEFS    += __GPS_EPO_DOWNLOAD__
      endif
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_BASE_COMP += gps\mnl make\mnl
    endif
  endif
endif
ifeq ($(strip $(GPS_HS_SUPPORT)),TRUE)
  ifneq ($(strip $(GPS_SUPPORT)),MT3326)
    ifneq ($(strip $(GPS_SUPPORT)),MT3336)
      ifneq ($(strip $(GPS_SUPPORT)),MT3332)
      $(call DEP_ERR_SETA_OR_OFFB,GPS_SUPPORT,MT3332,GPS_HS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  COM_DEFS    += __BEE_SUPPORT__
  COMPLIST    += bee
  ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += gps\bee\lib\MTK_HS_rvct.lib
      CUS_REL_OBJ_LIST += gps\bee\lib\MTK_HS_rvct.lib
  else
      COMPOBJS    += gps\bee\lib\MTK_HS.lib
      CUS_REL_OBJ_LIST += gps\bee\lib\MTK_HS.lib
  endif 
  CUS_REL_FILES_LIST += gps\bee\lib\MTK_HS_WIN32.lib
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COM_DEFS    +=  IDMA_DOWNLOAD
endif

ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),UDVT)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ifdef SMART_PHONE_CORE
    ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
      COMP_TRACE_DEFS += hal\audio\src\v1\inc\l1sp_trc.h
    endif
  else
    COMP_TRACE_DEFS += hal\audio\src\v1\inc\l1sp_trc.h
  endif
endif
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(filter __MAUI_BASIC__,$(COM_DEFS)),)
    ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
      ifdef SMART_PHONE_CORE
        ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
          COMP_TRACE_DEFS += hal\audio\src\v1\inc\l1audio_sph_trc.h
        endif
      else
        COMP_TRACE_DEFS += hal\audio\src\v1\inc\l1audio_sph_trc.h
      endif
    endif
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
    COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\cmux\include\cmux_trc.h
    COMMINCDIRS += $(strip $(PS_FOLDER))\cmux\include
  endif
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
    ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
      COMP_TRACE_DEFS   += $(strip $(PS_FOLDER))\dt\include\dt_trc.h
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  COMP_TRACE_DEFS   += $(strip $(PS_FOLDER))\ems\include\ems_trc.h
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    COMP_TRACE_DEFS   +=    $(strip $(PS_FOLDER))\rr2\mpal\include\mpal_trace.h
  else
    ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
      COMP_TRACE_DEFS   +=    $(strip $(PS_FOLDER))\rr\mpal\include\mpal_trace.h
      COMMINCDIRS += $(strip $(PS_FOLDER))\rr\mpal\include
    endif
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
      COMP_TRACE_DEFS   +=    $(strip $(PS_FOLDER))\rr\mpal\include\mpal_trace.h
      COMMINCDIRS += $(strip $(PS_FOLDER))\rr\mpal\include
    endif
  endif
endif

ifneq ($(filter TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
   COMP_TRACE_DEFS   +=    ll1\include\ll1_trc.h
endif

ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    L1_TMD_FILES   +=    l1_dm\common\l1D_EDGE_trace.tmd
  else
    L1_TMD_FILES   +=    l1\common\l1D_EDGE_trace.tmd
  endif
endif

L1_TMD_FILES  += hal\sleep_drv\common\DCXO_DIV_Trace1.tmd \
                 hal\sleep_drv\common\OSTD_Trace1.tmd \
                 hal\sleep_drv\common\SleepDrv_Trace1.tmd \
                 hal\sleep_drv\common\MD_TOPSM_Trace1.tmd

ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
  L1_TMD_FILES   +=   l1_dm\common\L1D3_Trace.tmd \
                      l1_dm\common\l1c3_Trace.tmd \
                      l1_dm\common\l1c4_Trace.tmd \
                      l1_dm\common\l1c5_Trace.tmd
  L1_TMD_FILES   +=   md_sm\common\l1sm\L1SM_Trace1.tmd
else
  ifeq ($(call Upper,$(strip $(L1_WCDMA))),TRUE)
    L1_TMD_FILES   +=   l1_dm\common\L1D3_Trace.tmd \
                        l1_dm\common\l1c3_Trace.tmd \
                        l1_dm\common\l1c4_Trace.tmd \
                        l1_dm\common\l1c5_Trace.tmd
    L1_TMD_FILES   +=   md_sm\common\l1sm\L1SM_Trace1.tmd
  else
    L1_TMD_FILES   +=   l1\common\L1D3_Trace.tmd \
                        l1\common\l1c3_Trace.tmd \
                        l1\common\l1c4_Trace.tmd \
                        l1\common\l1c5_Trace.tmd
  endif
endif

COMP_TRACE_DEFS += hal\dp_engine\dp_engine_trc.h


# ---------------------------------------------------------------
# The followings are global options from $(Customer)_$(Project).bld
# ---------------------------------------------------------------
# Platform Options
COM_DEFS_FOR_MT6208  = MT6208
COM_DEFS_FOR_MT6205  = MT6205 __HW_DIVIDER__
COM_DEFS_FOR_MT6205B = MT6205B __HW_DIVIDER__
COM_DEFS_FOR_FPGA    = FPGA
COM_DEFS_FOR_MT6218  = MT6218  __HW_DIVIDER__
COM_DEFS_FOR_MT6218B = MT6218B __HW_DIVIDER__ MT6218B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6217  = MT6217 __HW_DIVIDER__ MT6217_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6219  = MT6219 __HW_DIVIDER__ MT6219_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6228  = MT6228 __HW_DIVIDER__ MT6228_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6229  = MT6229 __HW_DIVIDER__ MT6229_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6235  = MT6235 __HW_DIVIDER__ MT6235_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6235B = MT6235B __HW_DIVIDER__ MT6235B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6236  = MT6236 __HW_DIVIDER__ MT6236_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6921  = MT6236 __HW_DIVIDER__ MT6236_$(strip $(CHIP_VER)) MT6921
COM_DEFS_FOR_MT6236B = MT6236B __HW_DIVIDER__ MT6236B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6256  = MT6256 __HW_DIVIDER__ MT6256_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6238  = MT6238 __HW_DIVIDER__ MT6238_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6239  = MT6239 __HW_DIVIDER__ MT6239_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6230  = MT6230 __HW_DIVIDER__ MT6230_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227  = MT6227 __HW_DIVIDER__ MT6227_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227D = MT6227D __HW_DIVIDER__ MT6227D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226  = MT6226 __HW_DIVIDER__ MT6226_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226D = MT6226D __HW_DIVIDER__ MT6226D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226M = MT6226M __HW_DIVIDER__ MT6226M_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6225  = MT6225 __HW_DIVIDER__ MT6225_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223  = MT6223 __HW_DIVIDER__ MT6223_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223P  = MT6223P __HW_DIVIDER__ MT6223P_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268T = MT6268T __HW_DIVIDER__ MT6268T_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268H = MT6268H __HW_DIVIDER__ MT6268H_$(strip $(CHIP_VER))
COM_DEFS_FOR_TK6516  = TK6516 __HW_DIVIDER__ TK6516_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6516  = MT6516 __HW_DIVIDER__ MT6516_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6516AP  = MT6516AP __HW_DIVIDER__ MT6516AP_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268A = MT6268A __HW_DIVIDER__ MT6268A_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268  = MT6268 __HW_DIVIDER__ MT6268_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6276  = MT6276 __HW_DIVIDER__ MT6276_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6270A  = MT6270A __HW_DIVIDER__ MT6270A_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253T = MT6253T __HW_DIVIDER__ MT6253T_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253 = MT6253 __HW_DIVIDER__ MT6253_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253E = MT6253E __HW_DIVIDER__ MT6253E_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253L = MT6253L __HW_DIVIDER__ MT6253L_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6251 = MT6251 __HW_DIVIDER__ MT6251_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6573  = MT6573 __HW_DIVIDER__ MT6573_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6252 = MT6252 __HW_DIVIDER__ MT6252_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6252H = MT6252H __HW_DIVIDER__ MT6252H_$(strip $(CHIP_VER))
COM_DEFS_FOR_ASTRO36V2_DEMO_AD6546    = AD6546_RF ASTRO36V2_DEMO_AD6546
COM_DEFS_FOR_MT6255  = MT6255 __HW_DIVIDER__ MT6255_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6922  = MT6255 __HW_DIVIDER__ MT6255_$(strip $(CHIP_VER)) MT6922
COM_DEFS_FOR_MT6250  = MT6250 __HW_DIVIDER__ MT6250_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6260  = MT6260 __HW_DIVIDER__ MT6260_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6261  = MT6261 MT6261_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT2501  = MT2501 MT2501_$(strip $(CHIP_VER)) 
COM_DEFS_FOR_MT2502  = MT2502 MT2502_$(strip $(CHIP_VER))

COM_DEFS_FOR_PLATFORM =  COM_DEFS_FOR_$(strip $(PLATFORM))
ifdef $(COM_DEFS_FOR_PLATFORM)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(PLATFORM)))
else
  $(warning ERROR: [COM_DEFS_FOR_$(strip $(PLATFORM))] was not defined)
  DEPENDENCY_CONFLICT = TRUE
endif

# RF Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_BRIGHT4                  = BRIGHT4_RF BRIGHT4_EVB
COM_DEFS_FOR_EUROPA                   = MT6129C_RF EUROPA_EVB
COM_DEFS_FOR_FOUNTAIN2                = MT6119C_RF FOUNTAIN2_EVB  FOUNTAIN2_RF
COM_DEFS_FOR_MT6129C                  = MT6129C_RF MT6129C_EVB
COM_DEFS_FOR_MT6129D                  = MT6129D_RF MT6129D_EVB
COM_DEFS_FOR_MT6139B                  = MT6139B_RF MT6139B_EVB
COM_DEFS_FOR_MT6139C                  = MT6139C_RF MT6139C_EVB
COM_DEFS_FOR_MT6139E                  = MT6139E_RF MT6139E_EVB
COM_DEFS_FOR_MT6140A                  = MT6140A_RF MT6140A_EVB
COM_DEFS_FOR_MT6140C                  = MT6140C_RF MT6140C_EVB
COM_DEFS_FOR_MT6140D                  = MT6140D_RF MT6140D_EVB
COM_DEFS_FOR_SKY74117                 = SKY74117_RF SKY74117_EVB
COM_DEFS_FOR_SKY74137                 = SKY74137_RF SKY74137_EVB
COM_DEFS_FOR_SKY74045                 = SKY74045_RF SKY74045_EVB
COM_DEFS_FOR_BRIGHT5P                 = BRIGHT5P_RF BRIGHT5P_EVB
COM_DEFS_FOR_AERO2                    = AERO2_RF   AERO2_EVB
COM_DEFS_FOR_SONY_CXA3359             = SONY_CXA3359_RF SONY_CXA3359_EVB
COM_DEFS_FOR_SMARTI3G                 = SMARTI3G_RF SMARTI3G_EVB
COM_DEFS_FOR_MTKSOC1                  = MTKSOC1_RF MTKSOC1_EVB
COM_DEFS_FOR_MT6253ELRF               = MT6253ELRF_RF MT6253ELRF_EVB
COM_DEFS_FOR_MT6250RF                 = MT6250RF_RF MT6250RF_EVB
COM_DEFS_FOR_MT6250RF_CUSTOM          = MT6250RF_RF MT6250RF_CUSTOM
COM_DEFS_FOR_MT6260RF                 = MT6260RF_RF MT6260RF_EVB
COM_DEFS_FOR_MT6260RF_CUSTOM          = MT6260RF_RF MT6260RF_CUSTOM
COM_DEFS_FOR_MT6261RF                 = MT6261RF_RF MT6261RF_EVB
COM_DEFS_FOR_MT6261RF_CUSTOM          = MT6261RF_RF MT6261RF_CUSTOM
COM_DEFS_FOR_MT2501RF                 = MT2501RF_RF MT2501RF_EVB
COM_DEFS_FOR_MT2501RF_CUSTOM          = MT2501RF_RF MT2501RF_CUSTOM
COM_DEFS_FOR_MT2502RF                 = MT2502RF_RF MT2502RF_EVB
COM_DEFS_FOR_MT2502RF_CUSTOM          = MT2502RF_RF MT2502RF_CUSTOM
COM_DEFS_FOR_MT6255RF                 = MT6255RF_RF MT6255RF_EVB
COM_DEFS_FOR_MT6255RF_CUSTOM          = MT6255RF_RF MT6255RF_CUSTOM
COM_DEFS_FOR_MT6922RF                 = MT6922RF_RF MT6922RF_EVB
COM_DEFS_FOR_MT6922RF_CUSTOM          = MT6922RF_RF MT6922RF_CUSTOM
COM_DEFS_FOR_MT6256RF                 = MT6256RF_RF MT6256RF_EVB
COM_DEFS_FOR_MT6256RF_CUSTOM          = MT6256RF_RF MT6256RF_CUSTOM
COM_DEFS_FOR_MT6251RF                 = MT6251RF_RF MT6251RF_EVB
COM_DEFS_FOR_MT6251RF_CUSTOM          = MT6251RF_RF MT6251RF_CUSTOM
COM_DEFS_FOR_SPARROW51_DEMO_MT6251RF  = MT6251RF_RF SPARROW51_DEMO_MT6251RF
COM_DEFS_FOR_SPARROW51V2_DEMO_MT6251RF  = MT6251RF_RF SPARROW51V2_DEMO_MT6251RF
COM_DEFS_FOR_MT6160                   = MT6160_RF MT6160_EVB
COM_DEFS_FOR_AD6546                   = AD6546_RF AD6546_EVB
COM_DEFS_FOR_TECHFAITH68_DEMO_MT6160  = MT6160_RF TECHFAITH68_DEMO_MT6160
COM_DEFS_FOR_TECHFAITH68_DEMO_AD6546  = AD6546_RF TECHFAITH68_DEMO_AD6546
COM_DEFS_FOR_MT6162                   = MT6162_RF MT6162_EVB
COM_DEFS_FOR_MT6163_2G                = MT6163_2G_RF MT6163_2G_EVB
COM_DEFS_FOR_NAMI70_DEMO_MT6162       = MT6162_RF NAMI70_DEMO_MT6162
COM_DEFS_FOR_LION52V2_NC_128X128_DEMO_MT6252RF  = MT6252RF_RF LION52V2_NC_128X128_DEMO_MT6252RF
COM_DEFS_FOR_LION52H_V2_6432_MT6252RF  = MT6252RF_RF LION52H_V2_6432_MT6252RF
COM_DEFS_FOR_LION52_V2_DEMO_MT6252RF  = MT6252RF_RF LION52_V2_DEMO_MT6252RF
COM_DEFS_FOR_LION52V2_NC_128X128_DEMO_MT6252RF  = MT6252RF_RF LION52V2_NC_128X128_DEMO_MT6252RF
COM_DEFS_FOR_LION52V2_NB_96X64_DEMO_MT6252RF  = MT6252RF_RF LION52V2_NB_96X64_DEMO_MT6252RF


# For Customer projects.
COM_DEFS_FOR_MT6140_CUSTOM = MT6140D_RF MT6140_CUSTOM
COM_DEFS_FOR_MT6139_CUSTOM = MT6139E_RF MT6139_CUSTOM
COM_DEFS_FOR_MT6129_CUSTOM = MT6129D_RF MT6129_CUSTOM
COM_DEFS_FOR_AD6548_CUSTOM = AD6548_RF AD6548_CUSTOM
COM_DEFS_FOR_AD6546_CUSTOM = AD6546_RF AD6546_CUSTOM
COM_DEFS_FOR_MT6162_CUSTOM = MT6162_RF MT6162_CUSTOM
COM_DEFS_FOR_MT6163_2G_CUSTOM = MT6163_2G_RF MT6163_2G_CUSTOM
COM_DEFS_FOR_SKY74137_CUSTOM = SKY74137_RF SKY74137_CUSTOM
COM_DEFS_FOR_UNICORN53_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V2_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V2_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V3_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V3_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V4_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V4_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V3_DEMO_GSM_MTKSOC1 = MTKSOC1_RF UNICORN53V3_DEMO_GSM_MTKSOC1
COM_DEFS_FOR_MT6161_AST = MT6161_RF

CUS_REL_BASE_COMP += custom\l1_rf\MT6140_CUSTOM custom\l1_rf\MT6139_CUSTOM \
                     custom\l1_rf\MT6129_CUSTOM custom\l1_rf\SKY74137_CUSTOM \
                     custom\l1_rf\AD6548_CUSTOM custom\l1_rf\AD6546_CUSTOM \
                     custom\l1_rf\MT6251RF_CUSTOM


COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(RF_MODULE))
ifdef $(COM_DEFS_FOR_RF_MODULE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(RF_MODULE)))
else
  $(warning ERROR: [COM_DEFS_FOR_$(strip $(RF_MODULE))] was not defined)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef UMTS_RF_MODULE
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))] was not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef UMTS_TDD128_RF_MODULE
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE))] was not defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# check AFC_VCXO_TYPE matches RF_MODULE
ifdef AFC_VCXO_TYPE
  ifdef RF_MODULE

    VCXO_PLATFORM = MT6139B MT6139C MT6139E
    ifneq ($(filter $(strip $(RF_MODULE)),$(VCXO_PLATFORM)),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifeq ($(filter MT6268A MT6268 MT6270A MT6276,$(strip $(PLATFORM))),)
          $(warning ERROR: MT6139 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    
    VCTCXO_RF_MODULE_LIST = MT6129D MT6129 MT6119 BRIGHT4 MT6140A SKY74117 SKY74045 BRIGHT5P FOUNTAIN
    ifneq ($(filter $(strip $(VCTCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE))),)
      VCTCXO_RF_MODULE = $(filter $(strip $(VCTCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE)))
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING $(VCTCXO_RF_MODULE) series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif

    VCXO_RF_MODULE_LIST = AERO MT6139
    ifneq ($(filter $(strip $(VCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE))),)
      VCXO_RF_MODULE = $(filter $(strip $(VCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE)))
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING $(VCXO_RF_MODULE) series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif

  endif
endif

# Board Options
ifneq ($(strip $(BOARD_VER)),)
  COM_DEFS    += $(BOARD_VER)
endif

# Board Subversion
ifneq ($(strip $(SUB_BOARD_VER)),)
  COM_DEFS    += $(SUB_BOARD_VER)
endif

# LCD Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_KLMLCM            = PCF8833 COLOR_LCD S6B1713 KLMLCM
COM_DEFS_FOR_MTKLCM_COLOR      = S1D15G00 COLOR_LCD MTKLCM_COLOR
COM_DEFS_FOR_NEPTUNE_LCM       = S6B33B1X COLOR_LCD NEPTUNE_LCM STN_MAINLCD
COM_DEFS_FOR_POWERTIP_LCM      = S6B33B1X COLOR_LCD POWERTIP_LCM STN_MAINLCD
COM_DEFS_FOR_SONY_LCM          = SONY_LCM TFT_MAINLCD
COM_DEFS_FOR_TOPPOLY_LCM       = TOPPOLY_LCM TFT_MAINLCD
COM_DEFS_FOR_RENESAS_LCM       = HD66781 COLOR_LCD HD66791 COLOR_SUBLCD DUAL_LCD RENESAS_LCM TFT_MAINLCD
COM_DEFS_FOR_TAURUS_LCM        = S6B33B2A COLOR_LCD S6B0756 TAURUS_LCM
COM_DEFS_FOR_PHOENIX29_LCM     = PHOENIX29_LCM TFT_MAINLCD
COM_DEFS_FOR_FIREFLY_LCM       = WSX6396A COLOR_LCD SSD1773 COLOR_SUBLCD FIREFLY_LCM TFT_MAINLCD STN_SUBLCD
COM_DEFS_FOR_MTK6225_LCM       = MTK6225_LCM TFT_MAINLCD
COM_DEFS_FOR_TOP_6227_LCM      = TOP_6227_LCM TFT_MAINLCD
COM_DEFS_FOR_LIBRA35_LCM       = LIBRA35_LCM TFT_MAINLCD
COM_DEFS_FOR_WISTRON_2P8_WQVGA_LCM = S6D0170 COLOR_LCD WISTRON_2P8_WQVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_AUO_VGA_LCM = SSD1961 COLOR_LCD AUO_VGA_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_HVGA_LCM = TA7601 COLOR_LCD TRULY_HVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_UNICORN53_DEMO_LCM = ILI9325DS COLOR_LCD UNICORN53_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_WISTRON_NHD_DEMO_LCM = ILI9640 COLOR_LCD  WISTRON_NHD_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_WISTRON_QCIF_DEMO_LCM = HX8340B COLOR_LCD WISTRON_QCIF_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_WVGA_DEMO_LCM = NT35582 COLOR_LCD TRULY_WVGA_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_WVGA_LCM = NT35582 COLOR_LCD TRULY_WVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_MT6252_R61529_LCM = TFT_MAINLCD COLOR_LCD MT6252_R61529_LCM
COM_DEFS_FOR_WISTRON_DUAL_DEMO_LCM = HX8340B COLOR_LCD WISTRON_DUAL_DEMO_LCM TFT_MAINLCD COLOR_SUBLCD DUAL_LCD
COM_DEFS_FOR_TRULY_HVGA_IPS320480_52_LCM = IPS320480_52 COLOR_LCD TRULY_HVGA_IPS320480_52_LCM TFT_MAINLCD
COM_DEFS_FOR_MT6250_ILI9486_HVGA_LCM = ILI9486 COLOR_LCD MT6250_ILI9486_HVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_KUBLAI50_V11_DEMO_LCM = ST7735 COLOR_LCD KUBLAI50_V11_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_QVGA_HX8347I_LCM = HX8347I COLOR_LCD TRULY_QVGA_HX8347I_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_HVGA_IPS320480_52_LCM_16BIT = IPS320480_52 COLOR_LCD TRULY_HVGA_IPS320480_52_LCM_16BIT TFT_MAINLCD
COM_DEFS_FOR_COMBO_LCM = COMBO_LCM COLOR_LCD TFT_MAINLCD


COM_DEFS_FOR_LCD_MODULE =  COM_DEFS_FOR_$(strip $(LCD_MODULE))
ifdef $(COM_DEFS_FOR_LCD_MODULE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(LCD_MODULE)))
else
  $(warning ERROR: No COM_DEFS for LCD_MODULE = $(strip $(LCD_MODULE))!)
  DEPENDENCY_CONFLICT = TRUE
endif


# BAND_SUPPORT Options
COM_DEFS_FOR_PGSM900   = __PGSM900__
COM_DEFS_FOR_EGSM900   = __EGSM900__
COM_DEFS_FOR_RGSM900   = __RGSM900__
COM_DEFS_FOR_DCS1800   = __DCS1800__
COM_DEFS_FOR_PCS1900   = __PCS1900__
COM_DEFS_FOR_GSM850    = __GSM850__
COM_DEFS_FOR_GSM450    = __GSM450__
COM_DEFS_FOR_DUAL900   = __EGSM900__ __DCS1800__
COM_DEFS_FOR_TRIPLE    = __EGSM900__ __DCS1800__ __PCS1900__
COM_DEFS_FOR_QUAD      = __EGSM900__ __DCS1800__ __PCS1900__  __GSM850__
COM_DEFS_FOR_DUAL850   = __GSM850__ __PCS1900__
COM_DEFS_FOR_TRIPLE850 = __GSM850__ __DCS1800__ __PCS1900__  TRIPLE850

COM_DEFS_FOR_BAND_SUPPORT =  COM_DEFS_FOR_$(strip $(BAND_SUPPORT))
ifdef $(COM_DEFS_FOR_BAND_SUPPORT)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(BAND_SUPPORT)))
else
  COM_DEFS += __EGSM900__ __DCS1800__   # the same as DUAL900
endif


# UMTS_BAND_SUPPORT Options
UMTS_SUPPORT_BAND =
ifdef UMTS_BAND_I
  ifeq ($(strip $(UMTS_BAND_I)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_I__
  endif
endif
ifdef UMTS_BAND_II
  ifeq ($(strip $(UMTS_BAND_II)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_II__
  endif
endif
ifdef UMTS_BAND_III
  ifeq ($(strip $(UMTS_BAND_III)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_III__
  endif
endif
ifdef UMTS_BAND_IV
  ifeq ($(strip $(UMTS_BAND_IV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_IV__
  endif
endif
ifdef UMTS_BAND_V
  ifeq ($(strip $(UMTS_BAND_V)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
  endif
endif
ifdef UMTS_BAND_VI
  ifeq ($(strip $(UMTS_BAND_VI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
  endif
endif
ifdef UMTS_BAND_VII
  ifeq ($(strip $(UMTS_BAND_VII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VII__
  endif
endif
ifdef UMTS_BAND_VIII
  ifeq ($(strip $(UMTS_BAND_VIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VIII__
  endif
endif
ifdef UMTS_BAND_IX
  ifeq ($(strip $(UMTS_BAND_IX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_IX__
  endif
endif
ifdef UMTS_BAND_X
  ifeq ($(strip $(UMTS_BAND_X)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_X__
  endif
endif
COM_DEFS    +=  $(strip $(UMTS_SUPPORT_BAND))
# Due to UAS RRC Specification (InterRATHandoverInfo message) limitation, UE at most supports 4 bands in band I~VII.
UMTS_SUPPORT_BAND_I_TO_VII_COUNT = $(words $(filter __UMTS_BAND_I__ __UMTS_BAND_II__ __UMTS_BAND_III__ __UMTS_BAND_IV__ __UMTS_BAND_V__ __UMTS_BAND_VI__ __UMTS_BAND_VII__,$(sort $(strip $(UMTS_SUPPORT_BAND)))))
ifeq ($(call gt,$(strip $(UMTS_SUPPORT_BAND_I_TO_VII_COUNT)),4),T)
  $(warning ERROR: UE at most supports 4 bands in band I~VII due to RRC Specification limitation (UE supports $(strip $(UMTS_SUPPORT_BAND))))
  DEPENDENCY_CONFLICT = TRUE
endif

# UMTS TDD128 BAND SUPPORT Options
ifdef UMTS_TDD128_BAND_A
  ifeq ($(strip $(UMTS_TDD128_BAND_A)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_A__
  endif
endif
ifdef UMTS_TDD128_BAND_B
  ifeq ($(strip $(UMTS_TDD128_BAND_B)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_B__
  endif
endif
ifdef UMTS_TDD128_BAND_C
  ifeq ($(strip $(UMTS_TDD128_BAND_C)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_C__
  endif
endif
ifdef UMTS_TDD128_BAND_D
  ifeq ($(strip $(UMTS_TDD128_BAND_D)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_D__
  endif
endif
ifdef UMTS_TDD128_BAND_E
  ifeq ($(strip $(UMTS_TDD128_BAND_E)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_E__
  endif
endif
ifdef UMTS_TDD128_BAND_F
  ifeq ($(strip $(UMTS_TDD128_BAND_F)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_F__
  endif
endif

# AFC_VCXO_TYPE Options
COM_DEFS_FOR_VCXO       = AFC_VCXO
COM_DEFS_FOR_VCXO_SC    = AFC_VCXO AFC_SC
COM_DEFS_FOR_VCXO_TC    = AFC_VCXO AFC_TC
COM_DEFS_FOR_VCXO_SC_TC = AFC_VCXO AFC_SC AFC_TC

COM_DEFS_FOR_AFC_VCXO_TYPE =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE)))
endif

DUMMY_SCATTER_ENABLE_PLATFORM = MT6252 MT6250 MT6260 MT6261 MT2501 MT2502
ifeq ($(filter $(strip $(PLATFORM)),$(DUMMY_SCATTER_ENABLE_PLATFORM)),)
  ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE can only be enabled when PLATFORM is $(DUMMY_SCATTER_ENABLE_PLATFORM))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when DEMO_PROJECT=TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when NAND_FLASH_BOOTING is not NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef ATV_I2S_PATH
  ifeq ($(strip $(ATV_I2S_PATH)),TRUE)
    ifneq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,I2S_INPUT_MODE_SUPPORT,ATV_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(ATV_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_I2S_SUPPORT__
  endif
endif

ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),FALSE)
    ifdef ATV_SUPPORT
      ifneq ($(strip $(ATV_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,ATV_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

REDUCE_TCM_SUPPORT_PLATFORM          = MT6225 MT6253T MT6253 MT6253E MT6253L MT6252H MT6252 MT6223 MT6223P MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268A MT6268 MT6270A MT6921
ARM9_DCACHEABLE_PLATFORM             = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268A MT6268 MT6270A MT6921
DYNAMIC_SWITCH_CACHEABILITY_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268A MT6268 MT6270A MT6921

ifneq ($(filter $(REDUCE_TCM_SUPPORT_PLATFORM),$(PLATFORM)),)
  COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifneq ($(filter $(ARM9_DCACHEABLE_PLATFORM),$(PLATFORM)),)
  COM_DEFS    += __ARM9_DCACHEABLE__
endif

ifneq ($(filter $(DYNAMIC_SWITCH_CACHEABILITY_PLATFORM),$(PLATFORM)),)
  COM_DEFS    += __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifdef PMIC_PRESENT
  ifeq ($(strip $(PMIC_PRESENT)),TRUE)
    COM_DEFS    += PMIC_PRESENT
  endif
endif

ifdef PMIC
  ifneq ($(strip $(PMIC)),NONE)
     COM_DEFS    += PMIC_PRESENT
  endif
  ifeq ($(strip $(PLATFORM)),MT6205)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6205 only supports MT6305 PMIC, and does not support $(strip $(PMIC)))
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205B)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6205B only supports MT6305 PMIC, and does not support $(strip $(PMIC)))
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205C)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6205C only supports MT6305 PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6235PMU)
    ifneq ($(strip $(PLATFORM)),MT6235)
      ifneq ($(strip $(PLATFORM)),MT6235B)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6235 & MT6235B series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    ifneq ($(strip $(PMIC)),MT6235PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6235 only supports MT6235PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    ifneq ($(strip $(PMIC)),MT6235PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6235B only supports MT6235PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6238PMU)
    ifneq ($(strip $(PLATFORM)),MT6238)
      ifneq ($(strip $(PLATFORM)),MT6239)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6238 & MT6239 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    ifneq ($(strip $(PMIC)),MT6238PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6238 only supports MT6238PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    ifneq ($(strip $(PMIC)),MT6238PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6239 only supports MT6238PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6223PMU)
    ifneq ($(strip $(PLATFORM)),MT6223)
      ifneq ($(strip $(PLATFORM)),MT6223P)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6223 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    ifneq ($(strip $(PMIC)),MT6223PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6223 only supports MT6223PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    ifneq ($(strip $(PMIC)),MT6223PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6223P only supports MT6223PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  PMIC_MT6326_SUPPORT_PLATFORM = MT6268A MT6268 MT6270A 
  ifeq ($(strip $(PMIC)),MT6326)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6326_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253PMU)
    ifneq ($(strip $(PLATFORM)),MT6253T)
      ifneq ($(strip $(PLATFORM)),MT6253)
         $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253 series chips support $(strip $(PMIC)) PMIC) 
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253ELPMU)
    ifneq ($(strip $(PLATFORM)),MT6253E)
      ifneq ($(strip $(PLATFORM)),MT6253L)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253EL series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6252PMU)
    ifneq ($(strip $(PLATFORM)),MT6252)
      ifneq ($(strip $(PLATFORM)),MT6252H)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6252/H series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6236PMU)
    ifneq ($(strip $(PLATFORM)),MT6236)
      ifneq ($(strip $(PLATFORM)),MT6236B)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6236 series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6921PMU)
    ifneq ($(strip $(PLATFORM)),MT6921)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6921 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6251PMU)
    ifneq ($(strip $(PLATFORM)),MT6251)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6251 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6276PMU)
    ifneq ($(strip $(PLATFORM)),MT6276)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6276 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6256PMU)
    ifneq ($(strip $(PLATFORM)),MT6256)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6256 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6255PMU)
    ifneq ($(strip $(PLATFORM)),MT6255)
      ifneq ($(strip $(PLATFORM)),MT6922)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6255 series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6250PMU)
    ifneq ($(strip $(PLATFORM)),MT6250)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6250 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6260PMU)
    ifneq ($(strip $(PLATFORM)),MT6260)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6260 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
  ifeq ($(strip $(PMIC)),MT6261PMU)
    ifeq ($(filter MT6261 MT2501 MT2502 ,$(strip $(PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6261 MT2501 MT2502 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

NEED_ADD_PMIC_COMPILE_LIST = MT6223PMU MT6238PMU MT6235PMU MT6236PMU MT6573PMU MT6305 MT6318 MT6326 MT6253PMU MT6253ELPMU MT6252PMU MT6326_CCCI MT6251PMU MT6276PMU MT6256PMU MT6921PMU MT6255PMU MT6922PMU MT6250PMU MT6260PMU MT6261PMU

ifneq ($(filter $(NEED_ADD_PMIC_COMPILE_LIST),$(PMIC)),)
  ifeq ($(strip $(PMIC)),MT6921PMU)
    COM_DEFS    += MT6236PMU
  else
    COM_DEFS    += $(PMIC)
  endif
endif

# Dependency check for PMIC/PMU which support custom tool configuration
# The PMIC/PMU list which support custom tool configuration
CUSTOM_TOOL_IF_SUPPORTED_PMIC = MT6236PMU MT6256PMU MT6276PMU MT6251PMU MT6921PMU MT6255PMU MT6922PMU MT6250PMU MT6260PMU MT6261PMU
ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
    ifneq ($(findstring $(strip $(PMIC)),$(strip $(CUSTOM_TOOL_IF_SUPPORTED_PMIC))),)
      COM_DEFS += __CUST_NEW_PMIC__
    endif
  endif
endif

DRV_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6253 MT6253E MT6253L MT6268 MT6236 MT6236B MT6270A MT6252 MT6252H MT6921
ifneq ($(filter $(call Upper,$(strip $(PLATFORM))) ,$(DRV_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    ifneq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
        $(warning ERROR: DRV_CUSTOM_TOOL_SUPPORT must be turned on when PLATFORM = $(strip $(PLATFORM))) 
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
     COM_DEFS    +=  __CUST_NEW__
  endif
endif

# Check 53 PMU API version
PMU53_API_V1_PLATFORM = MT6253_EVB% MT6253T_EVB% TIANYU6253T% UNICORN53%
ifeq ($(strip $(PMIC)),MT6253PMU)
   COM_DEFS    += MT6253PMU
   ifneq ($(filter $(strip $(PMU53_API_V1_PLATFORM)),$(strip $(BOARD_VER))),)
      COM_DEFS    += __DRV_PMU53_SPEC_V1__
   else
      COM_DEFS    += __DRV_PMU53_SPEC_V2__
   endif
endif

# Check if we support multi-level backlight or not
ifdef MULTI_LEVEL_BACKLIGHT_SUPPORT
  ifeq ($(strip $(MULTI_LEVEL_BACKLIGHT_SUPPORT)),TRUE)
    MULTI_LEVEL_BACKLIGHT_SUPPORT_PLATFORM = MT6236 MT6268 MT6256 MT6276 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MULTI_LEVEL_BACKLIGHT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support multi-level backlight(more than 5 levels))
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __MULTI_LEVEL_BACKLIGHT_SUPPORT__
    endif
  endif
endif

# Define backlight driver source
ifdef BACKLIGHT_POWER_SOURCE
  ifeq ($(strip $(BACKLIGHT_POWER_SOURCE)),INTERNAL_BL_DRIVER_SOURCE)
    COM_DEFS += __INTERNAL_BL_DRIVER_SOURCE__
  endif
  ifeq ($(strip $(BACKLIGHT_POWER_SOURCE)),EXTERNAL_BL_DRIVER_SOURCE)
    COM_DEFS += __EXTERNAL_BL_DRIVER_SOURCE__
  endif
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifneq ($(strip $(NAND_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FLASH_TEST_SELECT,non NAND_FLASH,NAND_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __NAND_FLASH_HARDWARE_TEST__
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
  COM_DEFS    += __NOR_FLASH_HARDWARE_TEST__
endif

ifdef NAND_SUPPORT
  ifdef SYSTEM_DRIVE_ON_NAND
    ifeq ($(strip $(NAND_SUPPORT)),FALSE)
      ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,SYSTEM_DRIVE_ON_NAND)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    COM_DEFS    += NAND_SUPPORT
  endif
endif

ifdef SPI_NAND_SUPPORT  
  ifeq ($(strip $(SPI_NAND_SUPPORT)),TRUE)
    COM_DEFS     += __SPI_NAND_SUPPORT__
    ifeq ($(strip $(NAND_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,SPI_NAND_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SYSTEM_DRIVE_ON_NAND,SPI_NAND_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,SERIAL_FLASH_SUPPORT,FALSE,SPI_NAND_SUPPORT)      
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif   
endif

ifdef NAND_SUPPORT
  ifdef SYSTEM_DRIVE_ON_NAND
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6217 MT6218B MT6219 MT6227 MT6226 MT6226M MT6225 MT6253T MT6253 MT6253E MT6253L MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6573 MT6252 MT6252H MT6921 MT6255 MT6922 MT6260 MT6261 MT2501 MT2502
      ifeq ($(filter $(strip $(PLATFORM)) ,$(SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SYSTEM_DRIVE_ON_NAND.) 
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(NAND_SUPPORT)),TRUE)
          COM_DEFS    += __FS_SYSDRV_ON_NAND__
        endif
      endif
    endif
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6205)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6208)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6223)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6223P)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COMPLIST    += sys_int
ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_SUPPORT_PLATFORM = MT6228 MT6229 MT6225 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A MT6256 MT6276 MT6573 MT6921 MT6255 MT6922 MT6260 MT6261 MT2501 MT2502
    NFB_ONDEMAND_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A MT6256 MT6276 MT6573 MT6921 MT6255 MT6922
    ifeq ($(strip $(SMART_PHONE_CORE)),AP)
      NAND_FLASH_BOOTING_SUPPORT_PLATFORM += MT6516 MT6573
      NFB_ONDEMAND_SUPPORT_PLATFORM += MT6516 MT6573
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(NAND_FLASH_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_SUPPORT
      ifeq ($(strip $(NAND_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
       DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += _NAND_FLASH_BOOTING_
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) should use NAND_FLASH_BOOTING = ONDEMAND / MIXED instead of ENFB) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = ONDEMAND) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = MIXED) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __DEMAND_PAGING__
    endif
  endif
  CUS_REL_BASE_COMP += hal\system\bootloader make\bootloader
  CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
  CUS_REL_FILES_LIST += sss\sss.lib sss\interface\src\SSS_interface.c \
                        interface\l1interface\l1_interface.c interface\l1interface\internal\l1_interface.h
endif

ifdef DEMAND_PAGING_LEVEL
  ifeq ($(strip $(DEMAND_PAGING_LEVEL)),DPV2)
    ifneq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      $(warning ERROR: Please set NAND_FLASH_BOOTING = ONDEMAND to enable DEMAND_PAGING_LEVEL = DPV2.)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __DEMAND_PAGING_V2__
    endif
  endif
endif

ifneq ($(strip $(USB_SUPPORT)),TRUE)
  ifneq ($(filter __CHARGER_USB_DETECT_WIHT_ONE_EINT__ ,$(CUSTOM_OPTION)),)
    $(warning ERROR: Please remove __CHARGER_USB_DETECT_WIHT_ONE_EINT__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter __USB_AND_UART_WITH_ONE_GPIO__ ,$(CUSTOM_OPTION)),)
    $(warning ERROR: Please remove __USB_AND_UART_WITH_ONE_GPIO__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  USB_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6227 MT6226 MT6226M MT6225 MT6252 MT6252H MT6253T MT6253 MT6253E MT6253L MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6516 MT6270A MT6256 MT6276 MT6573 MT6251 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB.) 
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      COM_DEFS    += __USB_ENABLE__  __NVRAM_IN_USB_MS__
      ifeq ($(strip $(BOARD_VER)),MT6228_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_MGM_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6230_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(PLATFORM)),MT6235) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6235B) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6236) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6236B) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6921) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6238)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6239)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6268A) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6268) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6270A) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6253T) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6253) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6253E)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6253L)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif      
      ifeq ($(strip $(PLATFORM)),MT6251) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6256) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6276) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6252)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6252H)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif 
    endif
  endif
endif

ifeq ($(strip $(IC_USB_SUPPORT)),TRUE)
  IC_USB_SUPPORT_PLATFORM = MT6276 MT6573
  ifeq ($(filter $(strip $(PLATFORM)),$(IC_USB_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support IC_USB_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    +=  __IC_USB_ENABLE__
  endif
endif

BROM_USB_DOWNLOAD_SUPPORT_PLATFORM = MT6251 MT6252H MT6252 MT6256 MT6250 MT6255 MT6260 MT6261 MT2501 MT2502
BROM_USB_DOWNLOAD_V2_PLATFORM = MT6250 MT6260 MT6261 MT2501 MT2502

ifneq ($(filter $(strip $(PLATFORM)) ,$(BROM_USB_DOWNLOAD_SUPPORT_PLATFORM)),)
  COM_DEFS    += __USBDL_IN_BOOTROM__
  ifdef USB_DOWNLOAD_IN_BL
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),NORMAL)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(BROM_USB_DOWNLOAD_V2_PLATFORM)),)
        $(warning WARNING: $(PLATFORM) already supports BootROM USBDL. USB_DOWNLOAD_IN_BL = NORMAL is unnecessary)
        #DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif
ifneq ($(filter $(strip $(PLATFORM)) ,$(BROM_USB_DOWNLOAD_V2_PLATFORM)),)
  COM_DEFS    += __BROM_USBDL_V2__
endif

ifdef USB_DOWNLOAD_IN_BL
  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD_IN_BL,non SECURE,SECURE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD_IN_BL,non SECURE,USB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      USB_DOWNLOAD_SUPPORT_PLATFORM = MT6227 MT6226 MT6226M MT6227D MT6226D MT6225 MT6253T MT6253 MT6253E MT6253L MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268A MT6268 MT6270A MT6256 MT6276 MT6573 MT6252 MT6252H MT6251 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
      ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_DOWNLOAD_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB_DOWNLOAD.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __USB_DOWNLOAD__
      COM_DEFS    += USBACM_TX_WITHOUT_DMA
      CUS_REL_BASE_COMP += hal\system\bootloader make\bootloader
      CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
      CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
      ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
        COM_DEFS  += __SECURE_USB_DOWNLOAD__
        CUS_REL_FILES_LIST += dp_engine\che\sha1.h
        CUS_REL_FILES_LIST += dp_engine\che\rc4.h
      endif
    endif
  endif
endif

AUDIO_COMPONENT_SUPPORT_CONDITION = FALSE

ifeq ($(strip $(PLATFORM)),MT6276)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif

ifeq ($(strip $(PLATFORM)),MT6256)
  ifeq ($(strip $(CHIP_VER)),S01)
    AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6255)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PLATFORM)),MT6922)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PLATFORM)),MT6250)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PLATFORM)),MT6260)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PLATFORM)),MT6261)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PLATFORM)),MT2501)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PLATFORM)),MT2502)
  AUDIO_COMPONENT_SUPPORT_CONDITION = TRUE
endif

ifdef AMRWB_DECODE
  ifeq ($(strip $(AMRWB_DECODE)),TRUE)
    AMRWB_DECODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6223 MT6223P MT6253E MT6253L MT6252 MT6252H MT6250 MT6260 MT6261 MT2501 MT2502
    ifneq ($(filter $(strip $(PLATFORM)),$(AMRWB_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) not support AMRWB_DECODE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += AMRWB_DECODE
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
       ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += $(strip $(AUDLIB))\awb_codec.a
          CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\awb_codec.a
       endif
    endif
  endif
endif

ifdef AMRWB_ENCODE
  ifeq ($(strip $(AMRWB_ENCODE)),TRUE)
    AMRWB_ENCODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6223 MT6223P MT6253E MT6253L MT6252 MT6252H MT6250 MT6260 MT6261 MT2501 MT2502
    ifneq ($(filter $(strip $(PLATFORM)),$(AMRWB_ENCODE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) not support AMRWB_ENCODE!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += AMRWB_ENCODE
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
       ifeq ($(strip $(AMRWB_DECODE)),FALSE)
          ifeq ($(strip $(COMPILER)),RVCT)
             COMPOBJS    += $(strip $(AUDLIB))\awb_codec.a
             CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\awb_codec.a
          endif
       endif
    endif
  endif
endif

ifdef AMR_CODEC
  ifeq ($(strip $(AMR_CODEC)),TRUE)
    COM_DEFS    += AMR_CODEC
    AMR_CODEC_SWIP_SUPPORT_PLATFORM = MT6276
    AMR_CODEC_BGSND_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
    ifneq ($(filter $(strip $(PLATFORM)),$(AMR_CODEC_SWIP_SUPPORT_PLATFORM)),)
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\amr_codec.a
        CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\amr_codec.a
      endif
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(AMR_CODEC_BGSND_SUPPORT_PLATFORM)),)
      ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += $(strip $(AUDLIB))\amr_codec.a
          CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\amr_codec.a
        endif
      endif
    endif
  else
    ifeq ($(strip $(DEDI_AMR_REC)),TRUE)   
      $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AMRWB_ENCODE)),TRUE)   
      $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,AMRWB_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AMRWB_DECODE)),TRUE)   
      $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,AMRWB_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef EES_ENABLE
  ifeq ($(strip $(EES_ENABLE)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support EES_ENABLE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += EES_ENABLE
  else
    ifneq ($(strip $(PLATFORM)),MT6205B)
      ifdef IC_TEST_TYPE
        ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
          $(warning ERROR: EES_ENABLE is a mandatory feature. Please turn on EES_ENABLE!)
          DEPENDENCY_CONFLICT = TRUE 
        endif
      endif
    endif
  endif
endif

ifdef AEC_ENABLE
  ifeq ($(strip $(AEC_ENABLE)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support AEC_ENABLE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += AEC_ENABLE
  else
    ifneq ($(strip $(PLATFORM)),MT6205B)
      ifdef IC_TEST_TYPE
        ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
          $(warning ERROR: AEC_ENABLE is a mandatory feature. Please turn on AEC_ENABLE!)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    COMPLIST     += btmt
  endif
endif

LCD_COLOR_ENGINE_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(strip $(PLATFORM)),$(LCD_COLOR_ENGINE_SUPPORT_PLATFORM)),)
  COM_DEFS    += __LCD_COLOR_ENGINE_SUPPORT__
endif

ifdef JPG_DECODE
  ifeq ($(strip $(JPG_DECODE)),TRUE)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(warning ERROR: Graphics features are not supported on EMPTY_MMI projects; please set JPG_DECODE = FALSE.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef JPG_DECODE_PROGRESSIVE_CAPABILITY
      ifeq ($(strip $(JPG_DECODE_PROGRESSIVE_CAPABILITY)),PROGRESSIVE_03M)
        COM_DEFS    += __JPG_DECODE_PROGRESSIVE_03M__
      endif
      ifeq ($(strip $(JPG_DECODE_PROGRESSIVE_CAPABILITY)),PROGRESSIVE_1M)
        COM_DEFS    += __JPG_DECODE_PROGRESSIVE_1M__
      endif
      ifeq ($(strip $(JPG_DECODE_PROGRESSIVE_CAPABILITY)),PROGRESSIVE_2M)
        COM_DEFS    += __JPG_DECODE_PROGRESSIVE_2M__
      endif
      ifeq ($(strip $(JPG_DECODE_PROGRESSIVE_CAPABILITY)),PROGRESSIVE_3M)
        COM_DEFS    += __JPG_DECODE_PROGRESSIVE_3M__
      endif
    endif
    COM_DEFS    += JPG_DECODE
  endif
endif

ifdef JPG_ENCODE
  ifeq ($(strip $(JPG_ENCODE)),TRUE)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(warning ERROR: Graphics features are not supported on EMPTY_MMI projects; please set JPG_ENCODE = FALSE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += JPG_ENCODE
  endif
endif

ifeq ($(strip $(G2D_SUPPORT)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    $(warning ERROR: Graphics features are not supported on EMPTY_MMI projects; please set G2D_SUPPORT = FALSE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += G2D_SUPPORT
endif
  
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  JPG_CODEC_HW_NOT_SUPPORT_PLATFORM = MT6251
  ifeq ($(strip $(JPG_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(JPG_CODEC_HW_NOT_SUPPORT_PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support JPG_DECODE=$(strip $(JPG_DECODE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(JPG_ENCODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(JPG_CODEC_HW_NOT_SUPPORT_PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support JPG_ENCODE=$(strip $(JPG_ENCODE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM = MT6217 MT6218B MT6225 MT6253T MT6253 MT6253E MT6253L MT6235 MT6235B MT6236 MT6236B MT6223P MT6252 MT6252H MT6276 MT6921 MT6256 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
  ifeq ($(strip $(PLATFORM)),MT6223P)
    ifneq ($(strip $(SENSOR_TYPE)),DIRECT)
      ifeq ($(strip $(MJPG_ENCODE)),TRUE)
        $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,DIRECT,MJPG_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef MJPG_ENCODE
  ifeq ($(strip $(MJPG_ENCODE)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6276)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef MJPG_DECODE
      ifneq ($(strip $(MJPG_DECODE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,MJPG_DECODE,MJPG_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,MJPG_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(CMOS_SENSOR)),PO4010K)
      $(warning ERROR: $(strip $(CMOS_SENSOR)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR)),SIA100A)
      $(warning ERROR: $(strip $(CMOS_SENSOR)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += MJPG_ENCODE
  endif
endif

MJPEG_SW_CODEC_V2_PLATFORM = MT6253 MT6253E MT6253L MT6253T MT6236 MT6235 MT6235B MT6276 MT6252 MT6252H MT6921 MT6256 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502

ifdef MJPG_ENCODE
  ifeq ($(strip $(MJPG_ENCODE)),TRUE)
    ifneq ($(strip $(JPG_ENCODE)),TRUE)
      $(warning ERROR: JPG_ENCODE must be TRUE when MJPG_ENCODE = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MJPEG_SW_CODEC_V2_PLATFORM)),)
      COM_DEFS    += __VIDEO_ARCHI_V2__
      COM_DEFS    += MJPG_ENCODE
      COM_DEFS    += __AVI_ENC_SUPPORT__
      COM_DEFS    += __MJPEG_ENC_SUPPORT__
      COM_DEFS    += __MJPEG_ENC_SW_SUPPORT__
    endif
  endif
endif

ifdef MJPG_DECODE
  ifeq ($(strip $(MJPG_DECODE)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif    
    ifneq ($(strip $(JPG_DECODE)),TRUE)
      $(warning ERROR: JPG_DECODE must be TRUE when MJPG_DECODE = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += MJPG_DECODE
    ifneq ($(filter $(strip $(PLATFORM)),$(MJPEG_SW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += __VDEC_SUPPORT__
        COM_DEFS    += __MJPEG_DEC_SW_SUPPORT__
        COM_DEFS    += __MJPEG_DEC_SUPPORT__
    endif
  endif
endif

ifdef MJPG_DECODE_MODE
  ifeq ($(strip $(MJPG_DECODE)),TRUE)
    ifeq ($(strip $(MJPG_DECODE_MODE)),SLIM)
      MJPG_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6276 MT6250 MT6260 MT6261 MT2501 MT2502
      ifeq ($(filter $(strip $(PLATFORM)),$(MJPG_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support MJPG_DECODE_MODE=$(strip $(MJPG_DECODE_MODE)))
      endif  
      COM_DEFS         += __MJPG_DEC_SW_SLIM__
    endif
  endif
endif

CAMCORDER_SUPPORT_PLATFORM = MT6238 MT6239 MT6268 MT6268A MT6268 MT6236 MT6236B MT6270A MT6276 MT6256 MT6921 MT6255 MT6922
CAMCORDER_LOW_END_SUPPORT_PLATFORM = MT6235 MT6235B MT6253 MT6253T MT6253E MT6253L MT6252 MT6252H MT6250 MT6260 MT6261 MT2501 MT2502
ifdef CAMCORDER_SUPPORT
  ifneq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_LOW_END_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support CAMCORDER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS += __CAMERA_CAPTURE_STANDARD_SET__
      endif
    else
      COM_DEFS += __CAMERA_CAPTURE_HIGHEND_SET__
    endif

    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(MP4_ENCODE)),TRUE)
      ifeq ($(strip $(MP4_DECODE)),TRUE)
        CAMCO_MP4_SUPPORT = TRUE
      else
        CAMCO_MP4_SUPPORT = FALSE
      endif
    else
      CAMCO_MP4_SUPPORT = FALSE
    endif
    
    ifeq ($(strip $(MJPG_ENCODE)),TRUE)
      ifeq ($(strip $(MJPG_DECODE)),TRUE)
        CAMCO_MJPG_SUPPORT = TRUE
      else
        CAMCO_MJPG_SUPPORT = FALSE
      endif
    else
      CAMCO_MJPG_SUPPORT = FALSE
    endif
        
    ifeq ($(strip $(H264_ENCODE)),TRUE)
      ifeq ($(strip $(H264_DECODE)),TRUE)
        CAMCO_H264_SUPPORT = TRUE
      else
        CAMCO_H264_SUPPORT = FALSE
      endif
    else
      CAMCO_H264_SUPPORT = FALSE
    endif
       
    CAMCO_CODEC_SUPPORT = FALSE 
    ifeq ($(strip $(CAMCO_MP4_SUPPORT)),TRUE)
      CAMCO_CODEC_SUPPORT = TRUE
    endif
    
    ifeq ($(strip $(CAMCO_MJPG_SUPPORT)),TRUE)
      CAMCO_CODEC_SUPPORT = TRUE
    endif
    
    ifeq ($(strip $(CAMCO_H264_SUPPORT)),TRUE)
      CAMCO_CODEC_SUPPORT = TRUE
    endif
    
    ifneq ($(strip $(CAMCO_CODEC_SUPPORT)),TRUE)
      $(warning ERROR: Please open one codec Encode/Decode at least.)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(CAMCORDER_VRT_MEM_CAPTURE)),TRUE)
        ifneq ($(strip $(YUVCAM_INTERPOLATION)),NONE)
            $(warning ERROR: YUVCAM_INTERPOLATION is not allowed when turn on CAMCORDER_VRT_MEM_CAPTURE)
            DEPENDENCY_CONFLICT = TRUE        
        else      
            COM_DEFS += __CAMERA_CAPTURE_USING_APP_MEMORY__
        endif    
    endif
        
    ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_LOW_END_SUPPORT_PLATFORM)),)
      ifneq ($(filter STANDARD FULL,$(CAMCORDER_SUPPORT)),)
        COM_DEFS += __CAMCORDER_SUPPORT__ __CAMCORDER_PACKAGE_$(strip $(CAMCORDER_SUPPORT))__
      else
        $(warning ERROR: Please set CAMCORDER_SUPPORT as STANDARD or FULL.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      COM_DEFS += __CAMCORDER_SUPPORT__ __CAMCORDER_PACKAGE_$(strip $(CAMCORDER_SUPPORT))__
    endif
  endif
endif

ifdef GIF_DECODE
  ifeq ($(strip $(GIF_DECODE)),TRUE)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(warning ERROR: Graphics features are not supported on EMPTY_MMI projects; please set GIF_DECODE = FALSE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    COM_DEFS    += GIF_DECODE
    COM_DEFS    += USE_SW_GIF_DECODER

    ifeq ($(strip $(PLATFORM)),MT6268A)
      COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      COM_DEFS    +=   USE_HW_GIF_DECODER
    endif
    ifeq ($(strip $(PLATFORM)),MT6268)
      COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      COM_DEFS    +=   USE_HW_GIF_DECODER
    endif
    ifeq ($(strip $(PLATFORM)),MT6270A)
      COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      COM_DEFS    +=   USE_HW_GIF_DECODER
    endif
    ifeq ($(strip $(PLATFORM)),MT6276)
      COM_DEFS    +=   USE_HW_GIF_DECODER_V4
      COM_DEFS    +=   USE_HW_GIF_DECODER
    endif

  endif
endif

ifdef PNG_DECODE
  ifeq ($(strip $(PNG_DECODE)), TRUE)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(warning ERROR: Graphics features are not supported on EMPTY_MMI projects; please set PNG_DECODE = FALSE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    COM_DEFS        += PNG_DECODE
    PNG_DECODE_HW_PLATFORM = MT6238 MT6239 MT6268A MT6268 MT6270A MT6276 
    ifneq ($(filter $(strip $(PLATFORM)) ,$(PNG_DECODE_HW_PLATFORM)),) 
      COM_DEFS    += USE_HW_PNG_DECODER
    else                     
      COM_DEFS    += USE_SW_PNG_DECODER
    endif
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    ifeq ($(strip $(SENSOR_TYPE)),JPEG)
      COM_DEFS += CMOS_SENSOR_MAIN $(strip $(CMOS_SENSOR))_YUV $(strip $(CMOS_SENSOR))_YUV_MAIN
    else
      COM_DEFS += CMOS_SENSOR_MAIN $(strip $(CMOS_SENSOR))_$(strip $(SENSOR_TYPE)) $(strip $(CMOS_SENSOR))_$(strip $(SENSOR_TYPE))_MAIN
    endif
  endif
  ifeq ($(strip $(CMOS_SENSOR)),NONE)
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(findstring _MIPI,$(CMOS_SENSOR)),)
    COM_DEFS += MIPI_SENSOR_SUPPORT
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    ifneq ($(strip $(ISP_SUPPORT)),FALSE)
      COMMINCDIRS    += custom\drv\Camera_common
    endif
    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      COMMINCDIRS    += custom\drv\image_sensor\$(strip $(CMOS_SENSOR))
    endif  
    ifeq ($(strip $(SENSOR_TYPE)),YUV)
      COMMINCDIRS    += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR))
      COM_DEFS += YUV_SENSOR_SUPPORT
    endif
    ifeq ($(strip $(SENSOR_TYPE)),JPEG)
      COMMINCDIRS    += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR))
      COM_DEFS += YUV_SENSOR_SUPPORT
    endif
    ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
      COMMINCDIRS    += drv\drv_sec\include \
                        media\camera\include
      COM_DEFS       += __DIRECT_SENSOR_SUPPORT__ __$(strip $(CMOS_SENSOR))__
    endif
    ifdef SENSOR_TYPE
      ifneq ($(strip $(SENSOR_TYPE)),NONE)    
        CUS_REL_BASE_COMP  += custom\drv\Image_sensor \
                              custom\drv\YUV_sensor \
                              custom\drv\Lens_module
      endif
    endif
  endif
endif

ifdef CMOS_SENSOR
  ifeq ($(strip $(CMOS_SENSOR)),NONE)
    ifdef ATV_SUPPORT
      ifneq ($(strip $(ATV_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,ATV_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef LENS_MODULE
  ifneq ($(strip $(LENS_MODULE)),NONE)
    ifndef AF_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AF_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMOS_SENSOR
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMMINCDIRS    += custom\drv\lens_module\$(strip $(LENS_MODULE))
    COM_DEFS += $(strip $(LENS_MODULE)) 
  endif
endif

ifdef LENS_MODULE_BAK1
  ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
    ifndef CMOS_SENSOR_BAK1
      $(warning ERROR: Please define CMOS_SENSOR_BAK1 when LENS_MODULE_BAK1 is defined) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1,LENS_MODULE_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMMINCDIRS    += custom\drv\lens_module\$(strip $(LENS_MODULE_BAK1))
    COM_DEFS += $(strip $(LENS_MODULE_BAK1)) 
  endif
endif

ifdef CMOS_SENSOR_SUB
  ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
    ifeq ($(strip $(DUAL_CAMERA_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,DUAL_CAMERA_SUPPORT,CMOS_SENSOR_SUB)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef SENSOR_TYPE_SUB
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SENSOR_TYPE_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB))
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COMMINCDIRS  += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
          COMMINCDIRS  += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
      endif
    endif
    ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
      COM_DEFS += CMOS_SENSOR_SUB $(strip $(CMOS_SENSOR_SUB))_YUV $(strip $(CMOS_SENSOR_SUB))_YUV_SUB
    else
      COM_DEFS += CMOS_SENSOR_SUB $(strip $(CMOS_SENSOR_SUB))_$(strip $(SENSOR_TYPE_SUB)) $(strip $(CMOS_SENSOR_SUB))_$(strip $(SENSOR_TYPE_SUB))_SUB
    endif
  endif
endif

ifdef CMOS_SENSOR_BAK1
  ifndef LENS_MODULE_BAK1
    $(warning ERROR: Please define LENS_MODULE_BAK1 when CMOS_SENSOR_BAK1 is defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
    ifndef BACKUP_SENSOR_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifndef SENSOR_TYPE
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SENSOR_TYPE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1))
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COMMINCDIRS  += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
        ifeq ($(strip $(SENSOR_TYPE)),JPEG)
          COMMINCDIRS  += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_BAK1))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
      endif
    endif
    COM_DEFS += CMOS_SENSOR_BAK1 $(strip $(CMOS_SENSOR_BAK1))_$(strip $(SENSOR_TYPE)) $(strip $(CMOS_SENSOR_BAK1))_$(strip $(SENSOR_TYPE))_BAK1
  endif
endif

ifdef CMOS_SENSOR_SUB_BAK1
  ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
    ifndef BACKUP_SENSOR_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifndef SENSOR_TYPE_SUB
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SENSOR_TYPE_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COMMINCDIRS  += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
          COMMINCDIRS  += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
      endif
    endif
    ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
      COM_DEFS += CMOS_SENSOR_SUB_BAK1 $(strip $(CMOS_SENSOR_SUB_BAK1))_YUV $(strip $(CMOS_SENSOR_SUB_BAK1))_YUV_SUB_BAK1
    else
      COM_DEFS += CMOS_SENSOR_SUB_BAK1 $(strip $(CMOS_SENSOR_SUB_BAK1))_$(strip $(SENSOR_TYPE_SUB)) $(strip $(CMOS_SENSOR_SUB_BAK1))_$(strip $(SENSOR_TYPE_SUB))_SUB_BAK1
    endif
  endif
endif

ifdef DUAL_CAMERA_SUPPORT
  ifeq ($(strip $(DUAL_CAMERA_SUPPORT)),TRUE)
    ifndef CMOS_SENSOR_SUB
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_SUB,DUAL_CAMERA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_SUB,DUAL_CAMERA_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS += DUAL_CAMERA_SUPPORT
  else
    ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,DUAL_CAMERA_SUPPORT,CMOS_SENSOR_SUB)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BACKUP_SENSOR_SUPPORT
  ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),TRUE)
    ifndef CMOS_SENSOR_BAK1
      ifndef CMOS_SENSOR_SUB_BAK1
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif      
    else
      ifeq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        ifndef CMOS_SENSOR_SUB_BAK1
          $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        else
          ifeq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
    COM_DEFS += BACKUP_SENSOR_SUPPORT
  else
    ifdef CMOS_SENSOR_BAK1
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef CMOS_SENSOR_SUB_BAK1
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef LENS_MODULE_BAK1
      ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,LENS_MODULE_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef WEBCAM_SUPPORT
  ifeq ($(strip $(WEBCAM_SUPPORT)),TRUE)
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMOS_SENSOR
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B
    ifneq ($(filter $(strip $(PLATFORM)),$(WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support WEBCAM_SUPPORT.) 
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS += WEBCAM_SUPPORT
      endif
    endif
  endif
  ifeq ($(strip $(VENDOR)),NONE)
    CUS_REL_BASE_COMP += media\camera\include
  endif
endif

ifdef SENSOR_ROTATE
  ifneq ($(strip $(SENSOR_ROTATE)),NONE)
    COM_DEFS    += $(strip $(SENSOR_ROTATE))
  endif
endif

ifdef SENSOR_SUB_ROTATE
  ifneq ($(strip $(SENSOR_SUB_ROTATE)),NONE)
    COM_DEFS    += SUB_$(strip $(SENSOR_SUB_ROTATE))
  endif
endif

ifdef SENSOR_LOCATION
  ifneq ($(strip $(SENSOR_LOCATION)),NONE)
    COM_DEFS    += $(strip $(SENSOR_LOCATION))
  endif
endif

ifdef MOTION_SENSOR_SUPPORT
  ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
    COM_DEFS    += $(strip $(MOTION_SENSOR_SUPPORT))
    COM_DEFS    += MOTION_SENSOR_SUPPORT
    COMMINCDIRS += custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
    CUS_REL_BASE_COMP += custom\drv\motion_sensor
    COMPOBJS +=         vendor\sensor\mcube\lib\mcube_algo.lib
    CUS_REL_OBJ_LIST += vendor\sensor\mcube\lib\mcube_algo.lib
    CUS_REL_BASE_COMP += vendor\sensor\mcube\inc
    ifeq ($(strip $(MOTION_SENSOR_SUPPORT)),MC3230_I2C)
      COM_DEFS += __MOTION_SENSOR_ADVANCED_GESTURE__
    endif
  endif
endif

ifdef AMR_LINK_SUPPORT
  ifeq ($(strip $(AMR_LINK_SUPPORT)),TRUE)
    COM_DEFS   += __AMR_SUPPORT__
  endif
endif

ifdef HAND_WRITING
  ifeq ($(strip $(HAND_WRITING)),NONE)
    COM_DEFS += __NO_HANDWRITING__
  endif
else
  COM_DEFS += __NO_HANDWRITING__
endif

TP_INTERNAL_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268 MT6268A MT6516 MT6252 MT6252H MT6253 MT6253E MT6253L MT6253T MT6270A MT6276 MT6256 MT6251 MT6573 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifdef TOUCH_PANEL_SUPPORT
  CUS_REL_FILES_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,touch_panel_custom.h)
  CUS_REL_FILES_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,touch_panel_spi.h)
  ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(warning ERROR: TOUCH_PANEL does not support NEPTUNE_MMI) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),TP_INTERNAL)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(TP_INTERNAL_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(PLATFORM) does not support TOUCH_PANEL_SUPPORT = TP_INTERNAL)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += TOUCH_PANEL_PRESSURE
    COM_DEFS    += TOUCH_PANEL_INTERNAL
    COM_DEFS    += __TOUCH_PANEL_RESISTANCE__
  endif
  ifneq ($(filter TP_INTERNAL_RTP_MULTIPLE%,$(TOUCH_PANEL_SUPPORT)),)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(TP_INTERNAL_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(PLATFORM) does not support TOUCH_PANEL_SUPPORT = TP_INTERNAL_RTP_MULTIPLE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += TOUCH_PANEL_PRESSURE
    COM_DEFS    += TOUCH_PANEL_INTERNAL
    COM_DEFS    += __TOUCH_PANEL_MULTITOUCH__
    COM_DEFS    += __TOUCH_PANEL_RESISTANCE__
  endif
  ifneq ($(filter CTP_%,$(TOUCH_PANEL_SUPPORT)),)
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += __TOUCH_PANEL_CAPACITY__
    COM_DEFS    += __$(strip $(TOUCH_PANEL_SUPPORT))__
  endif
  ifneq ($(filter RTP_%,$(TOUCH_PANEL_SUPPORT)),)
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += __TOUCH_PANEL_RESISTANCE__
    COM_DEFS    += __$(strip $(TOUCH_PANEL_SUPPORT))__
  endif
  ifneq ($(filter %_TRUE_MULTIPLE,$(TOUCH_PANEL_SUPPORT)),)
    COM_DEFS    += __TOUCH_PANEL_TRUE_MULTITOUCH__
  else
    ifneq ($(filter %_FAKE_MULTIPLE,$(TOUCH_PANEL_SUPPORT)),)
      COM_DEFS    += __TOUCH_PANEL_FAKE_MULTITOUCH__
    endif
  endif
endif

ifdef TOUCH_PANEL_SUPPORT
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),TP_INTERNAL_RTP_MULTIPLE)
   COMPLIST  += drv_tp
  endif
endif

ifdef TOUCH_PANEL_SUPPORT
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,TOUCH_PANEL_SHORTCUT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else 
    ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)
      COM_DEFS    += TOUCH_PANEL_SHORTCUT_SUPPORT
    endif
  endif
endif

ifdef TOUCH_PAD_SUPPORT
  ifeq ($(strip $(TOUCH_PAD_SUPPORT)),TRUE)
    ifneq ($(strip $(DEMO_PROJECT)),TRUE)
      $(warning ERROR: TOUCH_PAD_SUPPORT can be turned on only in the internal project) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += TOUCH_PAD_SUPPORT
  endif
endif

ifndef GPRS_MAX_PDP_SUPPORT
  GPRS_MAX_PDP_SUPPORT = 2
  ifdef LOW_COST_SUPPORT
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      GPRS_MAX_PDP_SUPPORT = 1
    endif
  endif
endif

# define GPRS_MAX_PDP_SUPPORT = 2~7
ifdef GPRS_MAX_PDP_SUPPORT
  COM_DEFS    += GPRS_MAX_PDP_SUPPORT=$(strip $(GPRS_MAX_PDP_SUPPORT))
endif

# currently, we define the same number of internal PDPs == GPRS_MAX_PDP_SUPPORT if the TCPIP is turned on (TCPIP_SUPPORT!=NONE)
# if there is no TCPIP, then we define MAX_INT_PDP_CONTEXT=0
ifdef TCPIP_SUPPORT
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    MAX_INT_PDP_CONTEXT=$(strip $(GPRS_MAX_PDP_SUPPORT))
  else
    MAX_INT_PDP_CONTEXT=0
  endif
endif
COM_DEFS    += MAX_INT_PDP_CONTEXT=$(strip $(MAX_INT_PDP_CONTEXT))

# if the MAX_INT_PDP_CONTEXT > 0, that means we support at least 1 internal PDP, so we define __INT_PDP_CONTEXT_ON__
ifeq ($(call gt,$(strip $(MAX_INT_PDP_CONTEXT)),0),T)
  COM_DEFS          += __INT_PDP_CONTEXT_ON__
endif

#  if the internal PDP support > 1 and GPRS_MAX_PDP_SUPPORT > 1,
#  that means we support at least 2 internal PDP
#  and the SM can activate at least 2 PDP context, 
#  in this situation, we can support internal secondary PDP context, so we define __INT_SECONDARY_PDP_FEASIBLE__
ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),1),T)
  ifeq ($(call gt,$(strip $(MAX_INT_PDP_CONTEXT)),1),T)
    COM_DEFS          += __INT_SECONDARY_PDP_FEASIBLE__
  endif
endif

# if do not define MAX_EXT_PDP_CONTEXT in make file,
# if IPv6 is supported, we will defaultly support 3X2 = 6 AT context ID
#  in low cost project we will defaultly support 1 GPRS AT context ID
#  otherwise, we will defaultly support 3 GPRS AT context ID

ifndef MAX_EXT_PDP_CONTEXT
  ifdef PPPV6_SUPPORT
    ifeq ($(strip $(PPPV6_SUPPORT)),TRUE)
      MAX_EXT_PDP_CONTEXT = 6
      COM_DEFS          += __MAX_EXT_PDP_CONTEXT_NUMBER_USE_IPV6_ON_DEFAULT_VALUE__
    else
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          #if COMMON low cost or ULC low cost
          MAX_EXT_PDP_CONTEXT = 1
          COM_DEFS          += __MAX_EXT_PDP_CONTEXT_NUMBER_USE_LOW_COST_DEFAULT_VALUE__
        else
          #if not low cost
          MAX_EXT_PDP_CONTEXT = 3
          COM_DEFS          += __MAX_EXT_PDP_CONTEXT_NUMBER_USE_NON_LOW_COST_DEFAULT_VALUE__
        endif
      else
        MAX_EXT_PDP_CONTEXT = 3
        COM_DEFS          += __MAX_EXT_PDP_CONTEXT_NUMBER_USE_NON_LOW_COST_DEFAULT_VALUE__
      endif
    endif
  else
    $(warning ERROR: PPPV6_SUPPORT is not defined, please define it as TRUE or FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# define MAX_EXT_PDP_CONTEXT = 0~7, depends on feature option setting from make file
COM_DEFS    += MAX_EXT_PDP_CONTEXT=$(strip $(MAX_EXT_PDP_CONTEXT))

# if MAX_INT_PDP_CONTEXT + MAX_EXT_PDP_CONTEXT < GPRS_MAX_PDP_SUPPORT
#   error and stop build (in tcm hedear file check)
# if the MAX_EXT_PDP_CONTEXT < 0, error and stop compile
# if the MAX_EXT_PDP_CONTEXT > 7, error and stop compile
# if the MAX_EXT_PDP_CONTEXT > 0, that means we support at least 1 GPRS AT context ID, so we define __EXT_PDP_CONTEXT_ON__
ifeq ($(call lt,$(strip $(MAX_EXT_PDP_CONTEXT)),0),T)
  $(warning ERROR: MAX_EXT_PDP_CONTEXT value ($(MAX_EXT_PDP_CONTEXT)) should not be less than 0)
  DEPENDENCY_CONFLICT = TRUE
endif
ifeq ($(call gt,$(strip $(MAX_EXT_PDP_CONTEXT)),7),T)
  $(warning ERROR: MAX_EXT_PDP_CONTEXT value ($(MAX_EXT_PDP_CONTEXT)) should not be greater than 7)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(call gt,$(strip $(MAX_EXT_PDP_CONTEXT)),0),T)
  COM_DEFS          += __EXT_PDP_CONTEXT_ON__
endif

# if the MAX_EXT_PDP_CONTEXT > 1 and GPRS_MAX_PDP_SUPPORT > 1,
#   that means we support at least 2 GPRS AT context ID,
#   and the SM can activate at least 2 PDP context,
#   in this situation, we can support AT triggered secondary PDP context, so we define __EXT_SECONDARY_PDP_FEASIBLE__
# if AT_COMMAND_SET is not SLIM, that means we can use AT+CGDSCONT and AT+CGTFT
#   so we can define __TURN_ON_EXTERNAL_SECONDARY_PDP__ and __TURN_ON_GENERAL_SECONDARY_PDP__

ifeq ($(call gt,$(strip $(MAX_EXT_PDP_CONTEXT)),1),T)
# TCM support >= 2 external PDP
  ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),1),T)
  # SM support >= 2 PDP
    COM_DEFS          += __EXT_SECONDARY_PDP_FEASIBLE__
    ifdef AT_COMMAND_SET
      ifeq ($(strip $(AT_COMMAND_SET)),SLIM)
        # SLIM AT, there are no AT+CGDSCONT and no AT+CGTFT
      else
        # FULL AT, so AT support AT+CGDSCONT and AT+CGTFT
        COM_DEFS          += __TURN_ON_EXTERNAL_SECONDARY_PDP__
        COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__      
      endif
    else
      # backward compatible, not define AT_COMMAND_SET, we assume using full at command set
      COM_DEFS          += __TURN_ON_EXTERNAL_SECONDARY_PDP__
      COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__  
    endif
  endif
endif

ifdef PPPV6_SUPPORT
  ifeq ($(strip $(PPPV6_SUPPORT)),TRUE)
    COM_DEFS          += __IPV6__
    COM_DEFS          += __IPV4V6__
    ifeq ($(strip $(AT_COMMAND_SET)),ULC)
      $(warning ERROR: Please set AT_COMMAND_SET to SLIM/FULL to support Dialup AT command set when PPPV6_SUPPORT = TRUE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(PPP_SUPPORT)),GPRS_PPP_SUPPORT)
    ifneq ($(strip $(PPP_SUPPORT)),FULL_SUPPORT)
      $(warning ERROR: Please set PPP_SUPPORT to GPRS_PPP_SUPPORT/FULL_SUPPORT to support PPP dialup when PPPV6_SUPPORT = TRUE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    endif
  endif
endif

ifdef UART3_SUPPORT
  ifeq ($(strip $(UART3_SUPPORT)),TRUE)
    UART3_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B MT6260
    ifneq ($(filter $(strip $(PLATFORM)),$(UART3_NOT_SUPPORT_PLATFORM)),)
       $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support UART3_SUPPORT.) 
       DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __UART3_SUPPORT__
    UART_PORT_FREE_COUNT = 1
  else
    UART_PORT_FREE_COUNT = 0
  endif
else
    UART_PORT_FREE_COUNT = 0
endif

BLUETOOTH_SUPPORT_UART_CHIP = BTMTK_MT6601 BTMTK_MT6611 BTMTK_MT6612 BTMTK_MT6616 BTMTK_MT6622 BTMTK_MT6626 BTMTK_MT6612_22_26
ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_UART_CHIP)),)
  BT_USE_UART = TRUE
else
  BT_USE_UART = FALSE
endif
ifeq ($(strip $(BT_USE_UART)), FALSE)
    ifdef TOUCH_PAD_SUPPORT
      ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
        UART_PORT_USED_COUNT = 1
      else
        UART_PORT_USED_COUNT = 0
      endif
    else
      UART_PORT_USED_COUNT = 0
    endif
else
    ifdef TOUCH_PAD_SUPPORT
      ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
        UART_PORT_USED_COUNT = 2
      else
        UART_PORT_USED_COUNT = 1
      endif
    else
      UART_PORT_USED_COUNT = 1
    endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),1)
  ifeq ($(strip $(UART_PORT_USED_COUNT)),2)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),0)
  ifneq ($(strip $(UART_PORT_USED_COUNT)),0)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
    ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,IPERF_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(IPERF_SUPPORT)),QUAD)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
     COM_DEFS    += __IPERF4__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),TRIPLE)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),DUAL)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),SINGLE)
     COM_DEFS    += __IPERF__
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
    COMP_TRACE_DEFS += inet_ps\iperf\include\iperf_trc.h
    COMMINCDIRS += inet_ps\iperf\include
  endif
endif

ifdef IPERF_WMM_PS_TEST_SUPPORT
  ifeq ($(strip $(IPERF_WMM_PS_TEST_SUPPORT)),TRUE)
    ifndef IPERF_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,IPERF_SUPPORT,IPERF_WMM_PS_TEST_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(IPERF_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,IPERF_SUPPORT,IPERF_WMM_PS_TEST_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,IPERF_WMM_PS_TEST_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __IPERF_WMM_PS_TEST__
  endif
endif

ARM11_FOTA_PLATFORM = MT6276 MT6256
ARM9_FOTA_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268 MT6270A MT6921 MT6255 MT6922
ARM7_FOTA_PLATFORM = MT6223 MT6223P MT6229 MT6228 MT6230 MT6225 MT6226 MT6226M MT6226D MT6227 MT6227D MT6253 MT6253E MT6253L MT6252 MT6252H
ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
      ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
        COM_DEFS += _DM_OMADL_VIA_DLAGENT_ __DM_FOTA_SUPPORT__
      endif
    endif
    COM_DEFS += __$(strip $(FOTA_ENABLE))__ __FOTA_ENABLE__
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
          $(call DEP_ERR_SETA_OR_OFFB,FOTA_ENABLE,non FOTA_DM,SYSTEM_DRIVE_ON_NAND)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifdef SW_BINDING_SUPPORT
        ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
          ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
            $(call DEP_ERR_SETA_OR_SETB,FOTA_ENABLE,non FOTA_DM,SW_BINDING_SUPPORT,non BIND_TO_CHIP_BASIC)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif    
      COMPLIST         += ssf
      CUS_REL_BASE_COMP += hal\system\bootloader make\bootloader ssf\inc vendor\hp_fota\UA
      CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
      CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
      CUS_REL_FILES_LIST += interface\hal\graphics\app_zlib.h sst\include\sst_fue_encrypt.h
      CUS_REL_FILES_LIST += dp_engine\che\sha1.h dp_engine\che\rsa.h dp_engine\che\bignum.h
    endif
    CUS_REL_FILES_LIST += init\src\emi.c
    CUS_REL_BASE_COMP += fota make\fota
  endif
endif

ifdef FOTA_UPDATE_PACKAGE_ON_NAND
  ifeq ($(strip $(FOTA_UPDATE_PACKAGE_ON_NAND)),TRUE)
    ifeq ($(strip $(FOTA_ENABLE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,FOTA_ENABLE,FOTA_UPDATE_PACKAGE_ON_NAND)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __UP_PKG_ON_NAND__
  endif
endif

ifeq ($(strip $(FOTA_UPDATE_PACKAGE_ON_NAND)),TRUE)
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: Please set NAND_FLASH_BOOTING to NONE ,when FOTA_UPDATE_PACKAGE_ON_NAND is TRUE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM = MT6205B MT6223 MT6223P MT6225 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6226 MT6226D MT6226M MT6227 MT6229 MT6230 MT6227D MT6235 MT6235B MT6253 MT6251 MT6253E MT6253L MT6236 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifdef ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT
  ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SYSTEM_DRIVE_ON_NAND)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SINGLE_BANK_NOR_FLASH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __SINGLE_BANK_NOR_FLASH_SUPPORT__
    endif
  endif
endif

ifdef SW_BINDING_SUPPORT
  ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
    ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
    BIND_TO_CHIP_BASIC_SUPPORT_PLATFORM = MT6223 MT6223P MT6225 MT6235 MT6235B MT6238 MT6239 MT6253 MT6268 MT6236 MT6921 MT6252
      ifeq ($(filter $(strip $(PLATFORM)) ,$(BIND_TO_CHIP_BASIC_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SW_BINDING_SUPPORT=BIND_TO_CHIP_BASIC.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __BIND_TO_CHIP_BASIC__
    endif
    ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP)
      COM_DEFS += __BIND_TO_CHIP__
    endif
    ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
      COM_DEFS += __BIND_TO_KEY__
    endif
    ifneq ($(filter BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
      COM_DEFS += __BIND_TO_CHIP__ 
    endif
  endif
else
  SW_BINDING_SUPPORT = NONE
endif

ifdef RES_PROT
  ifeq ($(strip $(RES_PROT)),TRUE)
    ifndef SW_BINDING_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SW_BINDING_SUPPORT,RES_PROT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SW_BINDING_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SW_BINDING_SUPPORT,RES_PROT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __RES_PROT__
  endif
endif

CARD_DOWNLOAD_NOT_SUPPORT_PLATFORM = MT6223 MT6223C MT6225
ifdef CARD_DOWNLOAD
  ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
    ifneq ($(filter $(strip $(PLATFORM)),$(CARD_DOWNLOAD_NOT_SUPPORT_PLATFORM)),)
      $(error $(strip $(PLATFORM)) does not support CARD_DOWNLOAD)
    endif
    COM_DEFS += __CARD_DOWNLOAD__
  endif
endif

ifdef EDGE_SUPPORT
  ifeq ($(strip $(EDGE_SUPPORT)),TRUE)
    EDGE_SUPPORT_PLATFORM = MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268 TK6516 MT6516 MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6573 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)) ,$(EDGE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EGPRS.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(warning ERROR: GSM project does not support EDGE_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,EDGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    COM_DEFS    += __EGPRS_MODE__

    L1_EPSK_TX_SUPPORT_RF_MODULE = MT6140D_RF AD6546_RF SKY74137_RF SKY74045_RF MT6256RF_RF MT6162_RF MT6163_2G_RF
    ifeq ($(filter $(L1_EPSK_TX_SUPPORT_RF_MODULE),$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
      COM_DEFS    += __EPSK_TX_SW_SWITCH_OFF__
    endif
    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      COM_DEFS    +=  __EPSK_TX__
    endif
  else
     ifdef L1_EPSK_TX
       ifeq ($(strip $(L1_EPSK_TX)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EPSK_TX)
         DEPENDENCY_CONFLICT = TRUE
       endif
     endif
   endif
endif

ifdef R99_SUPPORT
  ifeq ($(strip $(R99_SUPPORT)),TRUE)
    COM_DEFS    +=   __R99__
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(strip $(L1_GPRS)),TRUE)
        COM_DEFS    +=   __TBF_EST__
      endif
    endif
  endif
endif

ifdef R4_SUPPORT
  R4_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219
  ifeq ($(strip $(R4_SUPPORT)),TRUE)
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,R4_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non NEPTUNE_MMI,R4_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif    
    ifeq ($(filter $(strip $(PLATFORM)),$(R4_NOT_SUPPORT_PLATFORM)),)
      COM_DEFS    +=   __REL4__ __GERAN_R4__
    else
       $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support R4_SUPPORT.)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef R5_SUPPORT
  R5_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219
  ifeq ($(strip $(R5_SUPPORT)),TRUE)
    ifneq ($(strip $(R4_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,R5_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(R5_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support R5_SUPPORT.)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
      ifeq ($(filter ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
        $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,R5_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(PLATFORM)),MT6516)
      COM_DEFS    +=   __REL5__ __GERAN_R5__
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          #COM_DEFS    +=   __ACL_SUPPORT__
        endif
      endif
    else
      COM_DEFS    +=   __REL5__ __GERAN_R5__
    endif
  endif
endif

ifdef CHE_SUPPORT
  ifeq ($(strip $(PLATFORM)),MT6228)
    ifeq ($(strip $(CHE_SUPPORT)),TRUE)
       COM_DEFS    +=  __HW_CHE__
    endif
  endif
endif

ifdef TV_OUT_SUPPORT
  ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
      ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
        ifeq ($(strip $(LCM_ROTATE_SUPPORT)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,LCM_ROTATE_SUPPORT,HORIZONTAL_CAMERA/TV_OUT_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  TV_OUT_SUPPORT_PLATFORM = MT6228 MT6229 MT6268T MT6268H MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6230 MT6268A MT6268 MT6270A MT6921
  ifneq ($(filter $(strip $(PLATFORM)) ,$(TV_OUT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
      COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
endif

ifdef AF_SUPPORT
  ifneq ($(strip $(AF_SUPPORT)),FALSE)
    ifndef LENS_MODULE
      $(call DEP_ERR_ONA_OR_OFFB,LENS_MODULE,AF_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(LENS_MODULE)),NONE)
      ifeq ($(strip $(SENSOR_TYPE)),RAW)
        $(call DEP_ERR_ONA_OR_OFFB,LENS_MODULE,AF_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    +=  AF_SUPPORT
  endif
endif

ifeq ($(strip $(AF_AUXI_LED_SUPPORT)),TRUE)
  ifneq ($(strip $(AF_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,AF_AUXI_LED_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __AF_AUXI_LED_SUPPORT__
endif

ifdef OTG_SUPPORT
  ifeq ($(strip $(OTG_SUPPORT)),TRUE)
    OTG_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6268T MT6268H MT6268 MT6270A MT6276
    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
      $(warning ERROR: $(MMI_VERSION) does not support OTG_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(PLATFORM)),$(OTG_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support OTG_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_IN_NORMAL_MODE_SUPPORT,OTG_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(USB_SUPPORT)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,OTG_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        else
          COM_DEFS += __OTG_ENABLE__ __OTG_DETECT_IDPIN_WITH_EINT__
          ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
            COM_DEFS  += __OTG_ENABLE__
          endif
        endif
      endif
    endif
  endif
endif

ifdef USB_MULTI_CHARGE_CURRENT_SUPPORT
  ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTI_CHARGE_CURRENT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
        COM_DEFS +=  __USB_MULTI_CHARGE_CURRENT__
     endif
  endif
endif

ifdef YUV_SENSOR_SUPPORT
  ifneq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
    ifeq ($(strip $(ISP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,YUV_SENSOR_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += YUV_SENSOR_SUPPORT
    endif
  endif
endif

ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6225)
    ifdef ISP_SUPPORT
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
        ifdef YUV_SENSOR_SUPPORT
          ifeq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
            $(call DEP_ERR_ONA_OR_OFFB,YUV_SENSOR_SUPPORT,ISP_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifdef EXT_DAC_SUPPORT
  ifeq ($(strip $(EXT_DAC_SUPPORT)),TRUE)
     COM_DEFS    +=  EXT_DAC_SUPPORT
  endif
endif

ifdef EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION
  ifeq ($(strip $(EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION)),TRUE)
     COM_DEFS    +=  EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION
  endif
endif

ifdef DSPIRDBG
  ifeq ($(strip $(DSPIRDBG)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,DSPIRDBG)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __DSPIRDBG__
    COM_DEFS    += __USB_LOGGING__
  endif
endif

ifdef DSPIRDBG_SP
  ifeq ($(strip $(DSPIRDBG_SP)),TRUE)
    COM_DEFS    += __DSPIRDBG_SP__
  endif
endif

ifdef DISPLAY_TYPE
  COM_DEFS    += __MMI_DISPLAY_TYPE_$(call Upper,$(strip $(DISPLAY_TYPE)))__
  ifeq ($(strip $(DISPLAY_TYPE)),BW)
    ifdef SENSOR_TYPE
      ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
        $(warning ERROR: DISPLAY_TYPE = $(strip $(DISPLAY_TYPE)) does not support SENSOR_TYPE = $(strip $(SENSOR_TYPE))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

#6226C (S02), 6229E4, and 6225 and newer chip related project only.
SECURE_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6226M MT6227 MT6228 MT6229
SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM = MT6226 MT6226M MT6227 MT6229
SECURE_SUPPORT_NOT_SUPPORT_CHIPVER = S00 S01
# For 6226, 6226M, 6227, 6229: only 6226C (S02), 6226M (S02), 6227 (S02), 6229E4 (S02) and later chip version support SECURE PLATFORM

SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM = MT6226 MT6229 MT6225 MT6253T MT6253 MT6253E MT6253L MT6223 MT6227 MT6230 MT6226M MT6223P MT6252 MT6252H
SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM = MT6226 MT6229 MT6227 MT6226M
SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER = S00 S01 S02
# For 6229 (S00, S01, S02), 6226 (S00, S01, S02), 6227 (S00, S01, S02), 6226M (S00, S01, S02): do not support SECURE PLATFORM when NFB is on

ifdef SECURE_SUPPORT
  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)

    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    # Platforms which do not support secure platform
    ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_PLATFORM)),)
      ifneq ($(filter $(strip $(PLATFORM)), $(SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM)),)
        # Platforms which do not support secure platform
        ifneq ($(filter $(strip $(CHIP_VER)), $(SECURE_SUPPORT_NOT_SUPPORT_CHIPVER)),)
          $(warning ERROR: $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT.)
          DEPENDENCY_CONFLICT = TRUE
        # Platforms which partially support secure platform (new chip version)
        else
          ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
            ifneq ($(filter $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
              ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
                COM_DEFS    += __MTK_SECURE_PLATFORM__
              else
                $(warning ERROR: $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.)
                DEPENDENCY_CONFLICT = TRUE
              endif
            # new chip version of partial NFB support platform
            else
              COM_DEFS    += __MTK_SECURE_PLATFORM__
            endif
          endif
        endif
      # Platforms which do not support secure platform
      else
        $(warning ERROR: $(strip $(PLATFORM)) not support SECURE_SUPPORT.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    # Platforms which support secure platform
    else
      ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM)),)
        ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
          ifneq ($(filter $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
            ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
              COM_DEFS    += __MTK_SECURE_PLATFORM__
            else
              $(warning ERROR: $(strip $(PLATFORM)) $(strip $(CHIP_VER)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.)
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        #  NFB support platform
        else
          ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
            COM_DEFS    += __MTK_SECURE_PLATFORM__
          else
            $(warning ERROR: $(strip $(PLATFORM)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      # other support platforms
      else
        COM_DEFS    += __MTK_SECURE_PLATFORM__
      endif
    endif
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)      
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)
       COM_DEFS    += LED_FLASHLIGHT_SUPPORT 
    endif          
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(FLASHLIGHT_TYPE))) 
      DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(FLASHLIGHT_TYPE)))
      DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,FLASHLIGHT_TYPE,FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef CHIP_VERSION_CHECK
  ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
    COM_DEFS += __CHIP_VERSION_CHECK__
  endif
else
  $(warning ERROR: The feature CHIP_VERSION_CHECK should be defined as TRUE or FALSE)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
  ifneq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non RAW,NOR_SUPPORT_RAW_DISK)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
  ifneq ($(strip $(NANDFDM_MULTI_INSTANCE)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non FAT,NANDFDM_MULTI_INSTANCE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef OMA_ULP_SUPPORT
  ifeq ($(strip $(OMA_ULP_SUPPORT)), V1)
    COM_DEFS += __ULP_VER_1__
  endif
  ifeq ($(strip $(OMA_ULP_SUPPORT)), V1.5)
    COM_DEFS += __ULP_VER_1__
    COM_DEFS += __ULP_VER_1_5__
  endif
  ifeq ($(strip $(OMA_ULP_SUPPORT)), V2)
    COM_DEFS += __ULP_VER_1__
    COM_DEFS += __ULP_VER_1_5__
    COM_DEFS += __ULP_VER_2__
  endif
endif

ifeq ($(strip $(DISABLE_A5_2)),TRUE)
  COM_DEFS += __DISABLE_A5_2__
endif

ifeq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
  FACEDETECTION_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)) ,$(FACEDETECTION_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Face Detection)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __FACE_DETECTION_SUPPORT__
    ifeq ($(strip $(PLATFORM)),MT6235)
        COM_DEFS += __FD_NEED_SW_ROTATE__
    endif
  endif
endif

ifeq ($(strip $(CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT)),TRUE)
  SMILESHUTTER_NOSUPPORT_PLATFORM = MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)) ,$(SMILESHUTTER_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Smile Shutter)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_FACE_DETECTION_MODE_SUPPORT,CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(strip $(CAMCORDER_SUPPORT)),SLIM)
        $(warning ERROR: LOW_COST_SUPPORT = $(strip $(LOW_COST_SUPPORT)) and CAMCORDER_SUPPORT = $(strip $(CAMCORDER_SUPPORT)) does not support Smile Shutter)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    COM_DEFS += __SMILE_SHUTTER_SUPPORT__
  endif
endif

ifeq ($(strip $(TST_LOGACC_SUPPORT)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_LOGACC_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __LOGACC_ENABLE__
  endif
endif

ifdef MSHUTTER_SUPPORT
  ifneq ($(strip $(MSHUTTER_SUPPORT)),FALSE)
    ifndef CMOS_SENSOR
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,MSHUTTER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,MSHUTTER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  MSHUTTER_SUPPORT
  endif
endif

ifdef PMU_WITH_EXTERNL_CHARGER
  ifeq ($(strip $(PMU_WITH_EXTERNL_CHARGER)),TRUE)
    ifdef GENERAL_EXTERNAL_CHARGER
      ifneq ($(strip $(GENERAL_EXTERNAL_CHARGER)),NONE)
         $(call DEP_ERR_OFFA_OR_OFFB,GENERAL_EXTERNAL_CHARGER,PMU_WITH_EXTERNL_CHARGER)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef PMU_WITH_EXTERNL_CHARGER
  ifeq ($(strip $(PMU_WITH_EXTERNL_CHARGER)),TRUE)
    ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      COM_DEFS    +=  __PMU_WITH_EXTERNL_CHARGER__
    endif
  endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_MASS_STORAGE_ENABLE__
endif

ifeq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_COM_PORT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_COM_PORT_ENABLE__
endif

ifdef USB_HS_SUPPORT
  ifeq ($(strip $(USB_HS_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
       USB_HS_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6268H MT6253T MT6253 MT6516 MT6270A MT6256 MT6276 MT6573 MT6921 MT6255 MT6922
       ifeq ($(filter $(strip $(PLATFORM)),$(USB_HS_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB_HS_SUPPORT.)
         DEPENDENCY_CONFLICT = TRUE
       else
         COM_DEFS += __USB_HS_ENABLE__
       endif
     endif
   endif
endif

ifdef E_COMPASS_SENSOR_SUPPORT 
  ifneq ($(strip $(E_COMPASS_SENSOR_SUPPORT)),NONE) 
    COM_DEFS    += $(strip $(E_COMPASS_SENSOR_SUPPORT)) 
    COM_DEFS    += __E_COMPASS_SENSOR_SUPPORT__
    COMMINCDIRS += custom\drv\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT))
    COMMINCDIRS += vendor\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT)) 
    COMPLIST += ecompass
  endif 
endif

ifeq ($(strip $(JOGBALL_SUPPORT)),JOGBALL)
  COM_DEFS    += JOGBALL_SUPPORT
endif
ifeq ($(strip $(JOGBALL_SUPPORT)),OFN)
  COM_DEFS    += __OFN_SUPPORT__
endif

ifeq ($(strip $(3SET_F8F9_ENABLE)),TRUE)
  # can ONLY be turned on for 3G projects
  ifneq ($(strip $(L1_WCDMA)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,L1_WCDMA,3SET_F8F9_ENABLE)
    DEPENDENCY_CONFLICT = TRUE
  endif

  # NOT support 3G PLATFORMs
  3SET_F8F9_ENABLE_NOT_SUPPORT_3G_PLATFORM = MT6268A
  ifneq ($(filter $(strip $(PLATFORM)),$(strip $(3SET_F8F9_ENABLE_NOT_SUPPORT_3G_PLATFORM))),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support 3SET_F8F9_ENABLE)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS  += __CP_3SET_F8F9_HW_ENABLE__
endif

ifdef MP4_DECODE_MODE
  ifeq ($(strip $(MP4_DECODE)),TRUE)
    ifeq ($(strip $(MP4_DECODE_MODE)),SLIM)
      MP4_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6276 MT6255 MT6922 MT6256 MT6250 MT6260 MT6261 MT2501 MT2502
      ifeq ($(filter $(strip $(PLATFORM)),$(MP4_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MP4_DECODE_MODE=$(strip $(MP4_DECODE_MODE)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS         += __MP4_DEC_SW_SLIM__
    endif
  endif
endif

ifdef MP4_ENCODE_MODE
  ifeq ($(strip $(MP4_ENCODE)),TRUE)
    ifeq ($(strip $(MP4_ENCODE_MODE)),SLIM)
      MP4_ENCODE_MODE_SLIM_SUPPORT_PLATFORM = MT6276 MT6260 MT6261 MT2501 MT2502
      ifeq ($(filter $(strip $(PLATFORM)),$(MP4_ENCODE_MODE_SLIM_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MP4_ENCODE_MODE=$(strip $(MP4_ENCODE_MODE)))
        DEPENDENCY_CONFLICT = TRUE
      endif  
      COM_DEFS         += __MPEG4_ENC_SW_SLIM__
    endif
  endif
endif

ifdef H264_DECODE_MODE
  ifeq ($(strip $(H264_DECODE)),TRUE)
    ifeq ($(strip $(H264_DECODE_MODE)),SLIM)
      H264_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6276 MT6235 MT6235B MT6256 MT6250 MT6260 MT6261 MT2501 MT2502
      ifeq ($(filter $(strip $(PLATFORM)),$(H264_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support H264_DECODE_MODE=$(strip $(H264_DECODE_MODE)))
      endif
      COM_DEFS         += __H264_DEC_SW_SLIM__
    endif
  endif
endif

ifdef RM_DECODE_MODE
  ifeq ($(strip $(RM_DECODE)),TRUE)
    ifeq ($(strip $(RM_DECODE_MODE)),SLIM)
      RM_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H
      ifeq ($(filter $(strip $(PLATFORM)),$(RM_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support RM_DECODE_MODE=$(strip $(RM_DECODE_MODE)))
      endif  
      COM_DEFS         += __RM_DEC_SW_SLIM__
    endif
  endif
endif

ifeq ($(strip $(AMRWB_LINK_SUPPORT)),TRUE)
  AMRWB_LINK_SUPPORT_PLATFORM = MT6276 MT6573 MT6575
  ifeq ($(filter $(strip $(PLATFORM)) ,$(AMRWB_LINK_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AMRWB_LINK_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  +=  __AMRWB_LINK_SUPPORT__
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_SUPPORT_PLATFORM = MT6256 MT6276
    ifeq ($(filter $(strip $(PLATFORM)) ,$(EMMC_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EMMC_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_FLASH_BOOTING
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        $(warning ERROR: NAND_FLASH_BOOTING and EMMC_BOOTING could not turn on simutaneously. Please turn off one.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
    ifeq ($(strip $(NAND_SUPPORT)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when NAND_SUPPORT is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when SYSTEM_DRIVE_ON_NAND is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when COMBO_MEMORY_SUPPORT is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __EMMC_BOOTING__
    ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(EMMC_BOOTING_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EMMC_BOOTING = ONDEMAND)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(EMMC_BOOTING)),MIXED)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(EMMC_BOOTING_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EMMC_BOOTING = MIXED)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __DEMAND_PAGING__
    endif
  endif
  CUS_REL_BASE_COMP += bootloader make\bootloader
  CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
  CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c \
                        interface\l1interface\l1_interface.c interface\l1interface\internal\l1_interface.h
endif


# Determine if BOOTLOADER built required
NEED_BUILD_BOOTLOADER = FALSE
ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
else
  ifdef USB_DOWNLOAD_IN_BL
    ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif
  ifdef FOTA_ENABLE
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif

  ifdef SECURE_SUPPORT
    ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
      BOOTLOADER_SUPPORT_SECURE_NOR_PLATFORM = MT6253 MT6236% MT6252 MT6252H MT6921
      ifneq ($(filter $(strip $(BOOTLOADER_SUPPORT_SECURE_NOR_PLATFORM)),$(strip $(PLATFORM))),)
        NEED_BUILD_BOOTLOADER = TRUE
        BOOTLOADER_CHE = ON
      endif
    endif
  endif

  BOOTLOADER_SUPPORT_NOR_PLATFORM = MT6235% MT6236% MT6238 MT6239 MT6225 MT6253 MT6921 MT6250 MT6260 MT6261 MT2501 MT2502
  ifneq ($(filter $(strip $(BOOTLOADER_SUPPORT_NOR_PLATFORM)),$(strip $(PLATFORM))),)
    NEED_BUILD_BOOTLOADER = TRUE
    BOOTLOADER_CHE = ON
  endif
endif

ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

BOOTLOADER_MUST_PLATFORM = MT6268T MT6268H MT6268A MT6276 MT6256 MT6251 MT6255 MT6922
ifneq ($(filter $(strip $(BOOTLOADER_MUST_PLATFORM)),$(strip $(PLATFORM))),)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifdef NAND_FLASH_BOOTING
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_IS_NONE = TRUE
  endif
else
  NAND_FLASH_BOOTING_IS_NONE = TRUE
endif

ifdef EMMC_BOOTING
  ifeq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_IS_NONE = TRUE
  endif
else
  EMMC_BOOTING_IS_NONE = TRUE
endif

ifdef SMART_PHONE_CORE
  ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
    SMART_PHONE_CORE_IS_NONE = TRUE
  endif
else
  SMART_PHONE_CORE_IS_NONE = TRUE
endif

ifeq ($(strip $(NAND_FLASH_BOOTING_IS_NONE)),TRUE)
  ifeq ($(strip $(EMMC_BOOTING_IS_NONE)),TRUE)
    ifeq ($(strip $(SMART_PHONE_CORE_IS_NONE)),TRUE)
      COM_DEFS += __NOR_IDLE_SWEEP__
    endif
  endif
endif

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  CUS_REL_BASE_COMP += hal\system\bootloader make\bootloader
  CUS_REL_FILES_LIST += $(strip $(BL_SCATTERFILE))
endif

ifdef ACCDET_SUPPORT
  ifeq ($(strip $(ACCDET_SUPPORT)),TRUE)
    COM_DEFS    +=  __ACCDET_SUPPORT__
  endif
  ifeq ($(strip $(ACCDET_SUPPORT)),HYBRID)
    COM_DEFS    +=  __ACCDET_HYBRID_SOLUTION_SUPPORT__
  endif
  ifeq ($(strip $(ACCDET_SUPPORT)),DISABLE_AUX_ACCDET)
    COM_DEFS    +=  __AUX_DISABLE__
  endif
  ifeq ($(strip $(ACCDET_SUPPORT)),EINT_ACCDET)
    COM_DEFS    +=  __ACCDET_SUPPORT__
    COM_DEFS    +=  __ACCDET_EINT_SUPPORT__
  endif
endif

ifdef UMTS_MODE_SUPPORT
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: UMTS_MODE_SUPPORT can only be turned on when __UMTS_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS += __UMTS_FDD_MODE__
      COM_DEFS   += __3G_AUTO_BAND_MECHANISM__
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS += __UMTS_TDD128_MODE__ __R7_EHPLMN__ __ME_STORED_EHPLMN__
    endif
  else
    ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
      ifeq ($(strip $(PLATFORM)),MT6573)
        COM_DEFS +=  __SMARTPHONE_GPRS_ONLY__
      endif
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  ifdef TCPIP_SUPPORT
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      ifdef CSD_SUPPORT
        ifneq ($(strip $(CSD_SUPPORT)),NONE)
          COM_DEFS += __TCPIP_OVER_CSD__
        endif
      endif
    endif
  endif
endif

ifdef EXTERNAL_ACCESSORY_DETECTION
  ifneq ($(strip $(EXTERNAL_ACCESSORY_DETECTION)),NONE)
    COM_DEFS    +=  __DRV_EXT_ACCESSORY_DETECTION__
    COM_DEFS    +=  __EXT_ACCESSORY_DETECTION_$(strip $(EXTERNAL_ACCESSORY_DETECTION))__
    COMMINCDIRS += custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_ACCESSORY_DETECTION))
  endif
endif

ifdef SUPPORT_VIDEO_RECORD_ROTATE
  ifeq ($(strip $(SUPPORT_VIDEO_RECORD_ROTATE)),TRUE)
    COM_DEFS    += __SUPPORT_VIDEO_RECORD_ROTATE__
  endif
endif

ifdef USB_MULTIPLE_COMPORT_ENABLE
  ifeq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_COM_PORT_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),TRUE)
          $(call DEP_ERR_OFFA_OR_OFFB,USB_MULTI_CHARGE_CURRENT_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
          DEPENDENCY_CONFLICT = TRUE
        else
          COM_DEFS += __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__
          COM_DEFS += __USB_MULTIPLE_COMPORT_SUPPORT__
          COM_DEFS += __USB_COMPOSITE_DEVICE_SUPPORT__
        endif
      endif
    endif
  endif
endif

# Customer specific factory mode detection
ifdef CUSTOMER_SPECIFIC_FACTORY_DETECTION
  ifneq ($(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION)),NONE)
    COM_DEFS    +=  __CS_FAC_DET__
    COM_DEFS    +=  __$(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION))__
  endif
endif

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  COM_DEFS += __KAL_RECORD_BOOTUP_LOG__
endif

ifeq ($(strip $(NVRAM_AFE_DIGITAL_GAIN_SUPPORT)),TRUE)
  COM_DEFS  += __NVRAM_AFE_DIGITAL_GAIN_SUPPORT__
endif

ifeq ($(strip $(DUAL_MIC_SUPPORT)),TRUE)
  DUAL_MIC_SUPPORT_SUPPORT_PLATFORM = MT6256 MT6276 MT6573
  ifeq ($(filter $(strip $(PLATFORM)),$(DUAL_MIC_SUPPORT_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DUAL_MIC_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __DUAL_MIC_SUPPORT__
endif

ifdef ATV_RECORD_SUPPORT 
  ifeq ($(strip $(ATV_RECORD_SUPPORT)),TRUE)
    ifneq ($(strip $(ATV_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_RECORD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_RECORD_SUPPORT__ 
  endif
endif

ifeq ($(strip $(BATTERY_CHARGING_SUPPORT)),TRUE) 
  BATTERY_CHARGING_SUPPORT_PLATFORM = MT6236 MT6236B MT6276 MT6256 MT6921
  ifeq ($(filter $(strip $(PLATFORM)),$(BATTERY_CHARGING_SUPPORT_PLATFORM)),) 
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BATTERY_CHARGING_SUPPORT) 
    DEPENDENCY_CONFLICT = TRUE 
  endif
  ifeq ($(strip $(PLATFORM)), MT6236)
    ifeq ($(strip $(BOARD_VER)), JADE36_DEMO_BB)
      $(warning ERROR: MT6236E1 does not support BATTERY_CHARGING_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS +=  __USB_PHY_BC11_SUPPORT__ 
endif

CENTRALIZED_SLEEP_MANAGER_PLATFORM = MT6276 MT6573 MT6250 MT6260 MT6261 MT2501 MT2502
ifeq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),TRUE)
  ifneq ($(filter __NEW_OS_TICK__,$(COM_DEFS)),)
    $(warning ERROR:  __NEW_OS_TICK__ cannot be defined if CENTRALIZED_SLEEP_MANAGER is TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __CENTRALIZED_SLEEP_MANAGER__
  ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
    COM_DEFS += __EVENT_BASED_TIMER__
  endif
else
  ifneq ($(filter $(strip $(PLATFORM)),$(CENTRALIZED_SLEEP_MANAGER_PLATFORM)),)
    $(warning ERROR: CENTRALIZED_SLEEP_MANAGER must be TRUE on $(strip $(PLATFORM)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COM_DEFS += __DSP_FCORE4__ __ARM_MOVE_DATA__
endif

ifeq ($(strip $(USB_HIGH_SPEED_COM_PORT_SUPPORT)),TRUE)
  ifneq ($(strip $(USB_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HIGH_SPEED_COM_PORT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_COM_PORT_SUPPORT,USB_HIGH_SPEED_COM_PORT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS +=  __USB_HIGH_SPEED_COM_PORT_ENABLE__
endif

ifdef GPRS_CLASS_10
  ifeq ($(strip $(GPRS_CLASS_10)),TRUE)
    COM_DEFS    += __GPRS_MULTISLOT_CLASS_10__
  endif
endif

ifdef EDGE_CLASS_10 
  ifeq ($(strip $(EDGE_CLASS_10)),TRUE)
    COM_DEFS    += __EDGE_MULTISLOT_CLASS_10__
  endif
endif

ifeq ($(strip $(ATV_RECORD_SUPPORT)),TRUE)
  ifneq ($(strip $(ATV_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_SETB,ATV_SUPPORT,TRUE,ATV_RECORD_SUPPORT,FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ATV_RECORD_SUPPORT__ 
endif

ifeq ($(strip $(ATV_SUPPORT)),SLIM)
    COM_DEFS += __ATV_SLIM_VERSION__
endif

ifdef MCU_CLOCK
  # convert MCU_XXX_YYM to XXX.YY
  CLOCK_MHZ = $(subst _,.,$(subst M,,$(subst MCU_,,$(strip $(MCU_CLOCK)))))
  ifneq ($(CLOCK_MHZ),)
    COM_DEFS += CPU_CLOCK_MHZ=$(CLOCK_MHZ)
  endif
endif

# Proximity sensor
# Speficy PXS exclude platform
# Means the platform has PXS H/W on PCB, but because of mechanism issue, MMI can NOT use PXS function
# __PXS_APP_ENABLE__ is to indicate MMI can use PXS functionality
# __PXS_ENABLE__ means there is PXS H/W on PCB, driver need to init PXS to avoid power consumption issue
PXS_EXCLUDE_PLATFORM = LUFFY76%
ifdef PROXIMITY_SENSOR
  ifdef PXS_SQC_FORCE_PXS_APP_ENABLE
    # Skip exclude platform list check
    ifneq ($(strip $(PROXIMITY_SENSOR)),NONE)
      COM_DEFS    +=  __PXS_ENABLE__
      COM_DEFS    +=  __PXS_APP_ENABLE__
      COM_DEFS    +=  __PXS_$(strip $(PROXIMITY_SENSOR))__
    endif
  else
    ifneq ($(strip $(PROXIMITY_SENSOR)),NONE)
      COM_DEFS    +=  __PXS_ENABLE__
      COM_DEFS    +=  __PXS_$(strip $(PROXIMITY_SENSOR))__
      # Check exclude platform list to decide whether to enable PXS APP or NOT
      ifneq ($(filter $(strip $(PXS_EXCLUDE_PLATFORM)),$(strip $(BOARD_VER))),)
        # Do NOT define __PXS_APP_ENABLE__
      else
        # The platform is NOT in exclude platform list, MMI can use PXS functions without problem
        COM_DEFS    +=  __PXS_APP_ENABLE__
      endif
    endif
  endif
endif

#VIDEO CODEC library setting
VIDEO_CODEC_LIB_LIST =
VIDEO_CODEC_CUS_REL_LIB_LIST =
VIDEO_CODEC_CONFIG_EXT =
VIDEO_CODEC_CONFIG_NEGATIVE_EXT =

include make\video_codec\option_HAL_video_codec.mak
CUS_REL_FILES_LIST += make\video_codec\option_HAL_video_codec.mak

# Process COMPOBJS
VIDEO_CODEC_LIB_FILTER_OUT += $(foreach lib,$(VIDEO_CODEC_LIB_LIST), \
                                $(foreach ext,$(VIDEO_CODEC_CONFIG_EXT), \
                                  $(if \
                                    $(findstring $(ext),$(lib)),,$(lib)) \
                                  ))

VIDEO_CODEC_LIB_FILTER_OUT += $(foreach lib,$(VIDEO_CODEC_LIB_LIST), \
                                $(foreach ext,$(VIDEO_CODEC_CONFIG_NEGATIVE_EXT), \
                                  $(if \
                                    $(findstring $(ext),$(lib)),$(lib),) \
                                  ))

VIDEO_CODEC_LIB := $(filter-out $(VIDEO_CODEC_LIB_FILTER_OUT),$(VIDEO_CODEC_LIB_LIST))
COMPOBJS         += $(VIDEO_CODEC_LIB)

# process CUS_REL_OBJ_LIST - to support feature option OFF->ON, need to release all the libraries.
VIDEO_CODEC_CUS_REL_LIB_FILTER_OUT += $(foreach lib,$(VIDEO_CODEC_CUS_REL_LIB_LIST), \
                                        $(foreach ext,$(VIDEO_CODEC_CONFIG_EXT), \
                                          $(if \
                                            $(findstring $(ext),$(lib)),,$(lib)) \
                                          ))


VIDEO_CODEC_CUS_REL_LIB_FILTER_OUT += $(foreach lib,$(VIDEO_CODEC_CUS_REL_LIB_LIST), \
                                        $(foreach ext,$(VIDEO_CODEC_CONFIG_NEGATIVE_EXT), \
                                          $(if \
                                            $(findstring $(ext),$(lib)),$(lib),) \
                                          ))

VIDEO_CODEC_CUS_REL_LIB := $(filter-out $(VIDEO_CODEC_CUS_REL_LIB_FILTER_OUT),$(VIDEO_CODEC_CUS_REL_LIB_LIST))
CUS_REL_OBJ_LIST += $(VIDEO_CODEC_CUS_REL_LIB)

ifeq ($(strip $(FLV_FILE_FORMAT_SUPPORT)),TRUE)
  ifneq ($(strip $(MP4_DECODE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,FLV_FILE_FORMAT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __FLV_FILE_FORMAT_SUPPORT__
endif

ifdef SENDKEY_MODE
  ifeq ($(strip $(SENDKEY_MODE)),SENDKEY2_SUPPORT)
    COM_DEFS  += __SENDKEY2_SUPPORT__
  endif
endif

EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM = MT6268A MT6268 MT6270A MT6276 MT6573 MT6575
EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLAVOR_FLATFORM = MT6268A MT6268

ifeq ($(strip $(PS_HANDOVER)),TRUE)
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,PS_HANDOVER)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter __EGPRS_MODE__,$(COM_DEFS)),)
    ifeq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM)),)
      $(warning ERROR: PS_HANDOVER cannot be TRUE for PLATFORM $(strip $(PLATFORM)).)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLAVOR_FLATFORM)),)
      ifeq ($(filter $(strip $(COM_DEFS)),__FLAVOR_R5R6DEV_R5R6__ __FLAVOR_2GR5R6__),)
        $(warning ERROR: PS_HANDOVER cannot be TRUE for PLATFORM $(strip $(PLATFORM)) without FLAVOR R5R6DEV_R5R6/2GR5R6.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  COM_DEFS += __PS_HO__  __EXT_SEG_CTRL_BLK__
endif

ifeq ($(strip $(MULTIPLE_TBF)),TRUE)
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,MULTIPLE_TBF)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter __EGPRS_MODE__,$(COM_DEFS)),)
    ifeq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM)),)
      $(warning ERROR: MULTIPLE_TBF cannot be TRUE for PLATFORM $(strip $(PLATFORM)).)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLAVOR_FLATFORM)),)
      ifeq ($(filter $(strip $(COM_DEFS)),__FLAVOR_R5R6DEV_R5R6__ __FLAVOR_2GR5R6__),)
        $(warning ERROR: MULTIPLE_TBF cannot be TRUE for PLATFORM $(strip $(PLATFORM)) without FLAVOR R5R6DEV_R5R6/2GR5R6.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  COM_DEFS += __MTBF__
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
    CUS_REL_BASE_COMP += custom\drv\Drv_Tool
  endif
endif

ifdef RTSP_SUPPORT
  ifeq ($(strip $(RTSP_SUPPORT)),TRUE)
    ifneq ($(strip $(STREAM_SERVER_SUPPORT)),TRUE)
      ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,STREAM_SUPPORT,RTSP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,RTSP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST    += rtsp
    COM_DEFS    += __RTSP__
    COMP_TRACE_DEFS += inet_ps\rtsp\include\rtsp_trc.h
    COMMINCDIRS += inet_ps\rtsp\include
  endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6225)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    COM_DEFS    +=  MT6225_DMA_EMI_ISSUE
  endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6235)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    $(warning ERROR: CHIP_VER should be larger than S00 for MT6235)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6235B)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    $(warning ERROR: CHIP_VER should be larger than S00 for MT6235B)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

SMART_PHONE_PLATFORM = MT6516 MT6573 MT6575
ifeq ($(filter $(SMART_PHONE_PLATFORM),$(strip $(PLATFORM))),)
  ifeq ($(filter MED_NOT_PRESENT,$(CUSTOM_OPTION)),)
    COMPLIST       += media video mpl video_codec video_codec_sec video_sec fluency_sec fluency
    ifneq ($(filter MP4_DECODE MJPG_DECODE __M3GPMP4_FILE_FORMAT_SUPPORT__ MJPG_ENCODE __FLV_FILE_FORMAT_SUPPORT__ __MKV_FILE_FORMAT_SUPPORT__ __RM_DEC_SUPPORT__,$(strip $(COM_DEFS))),)
      COMPLIST += provider
    endif
  endif
else
  ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
    COM_DEFS += MED_NOT_PRESENT MED_V_NOT_PRESENT
  else
    ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
      COMPLIST += media
    endif
  endif
endif
COMPLIST += provider_sec

ifneq ($(filter __VIDEO_ARCHI_V1__,$(strip $(COM_DEFS))),)
    COMMINCDIRS += media\video\sw_video\include
endif

ifdef L1_GPRS
  ifneq ($(call Upper ,$(strip $(L1_GPRS))),TRUE)
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: __PS_SERVICE__ is not supported with L1_GPRS != TURE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(filter NONE GSM L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  COM_DEFS  += __MONITOR_PAGE_DURING_TRANSFER__  __SMART_PAGING__
endif

ifeq ($(strip $(GEMINI_VERSION)),V2)
  ifdef GEMINI
    ifneq ($(strip $(GEMINI)),FALSE)
      COM_DEFS  += __GEMINI_PREEMPT_PEER_SERVICE__ __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ __SMART_PAGING__ __SMART_PAGING_IN_IDLE__
      ifneq ($(filter UMTS HSPA TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
        COM_DEFS  += __MONITOR_PEER_PAGING_IN_CELL_PCH__
      endif
    endif
  endif
endif

ifneq ($(filter __SMART_PAGING_IN_IDLE__,$(COM_DEFS)),)
  ifeq ($(filter __SMART_PAGING__,$(COM_DEFS)),)
    $(warning ERROR: __SMART_PAGING_IN_IDLE__ can only be defined when __SMART_PAGING__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef COMPOSITE_WEBCAM_SUPPORT
  ifeq ($(strip $(COMPOSITE_WEBCAM_SUPPORT)),TRUE)
    COM_DEFS += __COMPOSITE_WEBCAM__
    COM_DEFS += __USB_COMPOSITE_DEVICE_SUPPORT__
  endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_CDROM_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_CDROM_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_MASS_STORAGE_SUPPORT,USB_MASS_STORAGE_CDROM_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_MASS_STORAGE_CDROM_ENABLE__
endif

MDP_VT_PREVIEW_UPSCALE_PLATFORM = MT6276 MT6268 MT6256 MT6236
ifneq ($(filter $(strip $(PLATFORM)),$(MDP_VT_PREVIEW_UPSCALE_PLATFORM)),)
  COM_DEFS    += __MDP_VT_PREVIEW_UPSCALE_SUPPORT__
endif

ifeq ($(strip $(HIGH_DYNAMIC_RANGE_SUPPORT)),TRUE)
  HIGH_DYNAMIC_RANGE_NOSUPPORT_PLATFORM =  MT6268 MT6235 MT6253 MT6253D MT6253T MT6252 MT6252H MT6253PMU MT6250 MT6260 MT6261 MT2501 MT2502
  ifneq ($(filter $(strip $(PLATFORM)) ,$(HIGH_DYNAMIC_RANGE_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support high dynamic range)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(CAMCORDER_SUPPORT)),FULL)
      $(call DEP_ERR_SETA_OR_OFFB,CAMCORDER_SUPPORT,FULL,HIGH_DYNAMIC_RANGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,HIGH_DYNAMIC_RANGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifneq ($(filter SLIM SLIM_EX,$(strip $(CAMCORDER_SUPPORT))),)
        $(warning ERROR: LOW_COST_SUPPORT = $(strip $(LOW_COST_SUPPORT)) and CAMCORDER_SUPPORT = $(strip $(CAMCORDER_SUPPORT)) does not support High Dynamic Range)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(EXIF_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,EXIF_SUPPORT,HIGH_DYNAMIC_RANGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS += __HIGH_DYNAMIC_RANGE_SUPPORT__
  endif
endif

ifneq ($(filter MT6251 MT6252 MT6253L,$(PLATFORM)),)
  COM_DEFS += __SERIAL_FLASH_EN__
endif

ifdef OPENGLES_SUPPORT
  ifeq ($(strip $(OPENGLES_SUPPORT)),TRUE)
    OPENGLES_HW_PLATFORM = MT6256
    ifneq ($(filter $(strip $(PLATFORM)) ,$(OPENGLES_HW_PLATFORM)),)
      COM_DEFS    += __OPENGLES_SUPPORT__
    else
      $(warning ERROR: $(strip $(PLATFORM)) is not support opengles.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST    += opengles
  endif
endif

ifeq ($(strip $(AUTOCAP_PANORAMA_SUPPORT)),TRUE)
  AUTOCAP_PANORAMA_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)) ,$(AUTOCAP_PANORAMA_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AutoCap Panorama)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,AUTOCAP_PANORAMA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(EXIF_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,EXIF_SUPPORT,AUTOCAP_PANORAMA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    COM_DEFS += __AUTOCAP_PANORAMA_SUPPORT__
    ifdef AUTOCAP_PANORAMA_MODE
      AUTOCAP_PANORAMA_SUPPORT_MODE = 3 4 5 6 7 8
      ifeq ($(filter $(strip $(AUTOCAP_PANORAMA_MODE)) ,$(AUTOCAP_PANORAMA_SUPPORT_MODE)),)
        $(warning ERROR: AUTOCAP_PANORAMA_MODE $(strip $(AUTOCAP_PANORAMA_MODE)) is not supported)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __AUTOCAP_PANORAMA_MODE_$(strip $(AUTOCAP_PANORAMA_MODE))__
    else
      COM_DEFS += __AUTOCAP_PANORAMA_MODE_8__
    endif
    ifeq ($(strip $(PLATFORM)),MT6235)
      ifeq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),FALSE)
        COM_DEFS += __FD_NEED_SW_ROTATE__
      endif
    endif
  endif
endif

ifeq ($(strip $(MULTIPLE_ANGLE_VIEW_SUPPORT)),TRUE)
  MAV_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H MT6235 MT6268 MT6236 MT6276
  ifneq ($(filter $(strip $(PLATFORM)) ,$(MAV_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Multiple Angle View)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,MULTIPLE_ANGLE_VIEW_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __MULTIPLE_ANGLE_VIEW_SUPPORT__
    ifeq ($(strip $(PLATFORM)),MT6250)
      ifeq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
        COM_DEFS += __CAMERA_GYRO_SUPPORT__
      endif
    endif
    ifeq ($(strip $(PLATFORM)),MT6260)
      ifeq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
        COM_DEFS += __CAMERA_GYRO_SUPPORT__
      endif
    endif	
  endif
endif

ifeq ($(strip $(3D_IMAGE_SUPPORT)),TRUE)
  3D_IMAGE_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H MT6235 MT6268 MT6236 MT6276
  ifneq ($(filter $(strip $(PLATFORM)) ,$(3D_IMAGE_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support 3D Image, please turn off 3D_IMAGE_SUPPORT .)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,3D_IMAGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __3D_IMAGE_SUPPORT__
  endif
endif

ifneq ($(filter __RF_DESENSE_TEST__,$(CUSTOM_OPTION)),)
  COMPLIST     += btmt
#  CUS_REL_MTK_COMP  +=  btmt
endif

ifeq ($(strip $(CAMCORDER_AUTO_SCENE_DETECT_SUPPORT)),TRUE)
  ASD_NOSUPPORT_PLATFORM = MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H MT6268 MT6235 MT6250 MT6260 MT6261 MT2501 MT2502
  ifneq ($(filter $(strip $(PLATFORM)) ,$(ASD_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Auto Scene Detect)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_FACE_DETECTION_MODE_SUPPORT,CAMCORDER_AUTO_SCENE_DETECT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(strip $(CAMCORDER_SUPPORT)),SLIM)
        $(warning ERROR: LOW_COST_SUPPORT = $(strip $(LOW_COST_SUPPORT)) and CAMCORDER_SUPPORT = $(strip $(CAMCORDER_SUPPORT)) does not support Auto Scene Detection.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    COM_DEFS += __AUTO_SCENE_DETECT_SUPPORT__
  endif
endif

ifeq ($(strip $(CAMCORDER_ZERO_SHUTTER_DELAY_SUPPORT)),TRUE)
  ZSD_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H MT6235 MT6268 MT6236 MT6250 MT6260 MT6261 MT2501 MT2502
  ifneq ($(filter $(strip $(PLATFORM)) ,$(ZSD_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Zero Shutter Delay)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_ZERO_SHUTTER_DELAY_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(strip $(CAMCORDER_SUPPORT)),SLIM)
        $(warning ERROR: CAMCORDER_SUPPORT = $(strip $(CAMCORDER_SUPPORT)) does not support Zero Shutter Delay)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    COM_DEFS += __ZERO_SHUTTER_DELAY_SUPPORT__
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    ifneq ($(strip $(PLATFORM)),MT6268)
      COM_DEFS    += __VT_MONA__
    endif
  endif
endif

COMMINCDIRS   +=  interface\nfc
ifdef NFC_SUPPORT
  ifneq ($(strip $(NFC_SUPPORT)),NONE)
    COM_DEFS    += __NFC_SUPPORT__
    COMPLIST    += nfc
    COMPLIST    += nfc_reader
    COMPLIST    += nfc_app
  endif
endif
ifeq ($(strip $(SUPPORT_JSR_257)),TRUE)
  ifndef NFC_SUPPORT
    COMPLIST    += nfc_custom
  else
    ifeq ($(strip $(NFC_SUPPORT)),NONE)
      COMPLIST    += nfc_custom
    endif
  endif
endif

ifeq ($(strip $(MP4_DECODE)),TRUE)
  ifeq ($(strip $(MP4_DECODE_PROFILE)),ASP)
    MP4_DECODE_PROFILE_SUPPORT_PLATFORM = MT6235 MT6236 MT6256 MT6276 MT6235B MT6255 MT6272 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MP4_DECODE_PROFILE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support MP4_DECODE_PROFILE = ASP)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter __MED_VIDEO_ULC__,$(COM_DEFS)),)
      $(warning ERROR: ULC does NOT support MP4_DECODE_PROFILE = ASP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  COM_DEFS    += __EMPTY_MMI__
endif

ifeq ($(strip $(AAC_DECODE)),TRUE)
   COMPOBJS         += $(strip $(AUDLIB))\aac_dec.a
   CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\aac_dec.a
endif

# BES_LIVE_SUPPORT/BES_TS_SUPPORT for 6228/6229/6230/6238 only
BES_LIVE_SUPPORT_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A MT6256 MT6276 MT6921 MT6252 MT6253 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifdef BES_LIVE_SUPPORT
  ifneq ($(strip $(BES_LIVE_SUPPORT)),FALSE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_LIVE_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BES_LIVE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(BES_LIVE_SUPPORT)),TRUE)
    COM_DEFS += __BES_LIVE_SUPPORT__
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += $(strip $(AUDLIB))\BesLive.a
    endif
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesLive.a

ifdef BES_TS_SUPPORT
  ifneq ($(strip $(BES_TS_SUPPORT)),FALSE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_LIVE_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BES_TS_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(BES_TS_SUPPORT)),TRUE)
    COM_DEFS += __BES_TS_SUPPORT__
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\BesTS.a
      endif
    endif
  endif
endif

ifdef VOICE_CHANGER_SUPPORT
  ifneq ($(strip $(VOICE_CHANGER_SUPPORT)),FALSE)
    VOICE_CHANGER_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)) ,$(VOICE_CHANGER_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support VOICE_CHANGER_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(VOICE_CHANGER_SUPPORT)),TRUE)
    COM_DEFS += __VOICE_CHANGER_SUPPORT__
    COM_DEFS += __CUSTOM_SPE_ENGINE__
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\BesTS.a
        COMPLIST    += dp_engine
      endif
    endif
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesTS.a

BES_SURROUND_SUPPORT_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6268 MT6268A MT6268 MT6270A MT6256 MT6276 MT6921 MT6252 MT6253 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
ifdef BES_SURROUND_SUPPORT
  ifneq ($(strip $(BES_SURROUND_SUPPORT)),NONE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_SURROUND_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(strip $(PLATFORM)) does not support BES_SURROUND_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(BES_SURROUND_SUPPORT)),MODE_LSPK)
      COM_DEFS += __BES_SURROUND_LSPK__
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\BesSurround.a
      endif
    endif
    ifeq ($(strip $(BES_SURROUND_SUPPORT)),MODE_EARP)
      COM_DEFS += __BES_SURROUND_EARP__
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\BesHeadphone.a
      endif
    endif
    ifeq ($(strip $(BES_SURROUND_SUPPORT)),MODE_BOTH)
      COM_DEFS += __BES_SURROUND_LSPK__ __BES_SURROUND_EARP__
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\BesSurround.a
        COMPOBJS    += $(strip $(AUDLIB))\BesHeadphone.a
      endif
    endif
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesSurround.a
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesHeadphone.a

ifdef BES_EQ_SUPPORT
  ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
    NON_SW_EQ_SUPPORT_PLATFORM = MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227D MT6227 MT6253 MT6253E MT6253L MT6251 MT6252 MT6252H
    ifneq ($(filter $(strip $(PLATFORM)),$(NON_SW_EQ_SUPPORT_PLATFORM)),)
      COM_DEFS += __NON_SW_EQ_SUPPORT__
    endif
    COM_DEFS += __BES_EQ_SUPPORT__
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE

    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += $(strip $(AUDLIB))\BesEQ.a
    endif
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesEQ.a

ifdef BES_LOUDNESS_SUPPORT
  BES_LOUDNESS_SUPPORT_SUPPORT_PLATFORM = MT6225 MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6268T MT6268H MT6268 MT6252 MT6252H MT6253T MT6253 MT6253E MT6253L MT6270A MT6256 MT6276 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(strip $(BES_LOUDNESS_SUPPORT)),TRUE)
    ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
      $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,BES_LOUDNESS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_LOUDNESS_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(strip $(PLATFORM)) does not support BES_LOUDNESS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPOBJS         += $(strip $(AUDLIB))\BesLoudness.a
    COM_DEFS += __BES_LOUDNESS_SUPPORT__
    COM_DEFS += __BES_LOUDNESS_ON_AUDIO__
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesLoudness.a

ifdef AUDIO_COMPENSATION_DSP_IIR_SUPPORT 
  AUDIO_COMPENSATION_DSP_IIR_SUPPORT_PLATFORM = MT6251 
  ifeq ($(strip $(AUDIO_COMPENSATION_DSP_IIR_SUPPORT)),TRUE)
    ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
      $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,AUDIO_COMPENSATION_DSP_IIR_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(AUDIO_COMPENSATION_DSP_IIR_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AUDIO_COMPENSATION_DSP_IIR_SUPPORT_PLATFORM.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __ACF_DSP_IIR_SUPPORT__
    COM_DEFS += __BES_LOUDNESS_SUPPORT__
  endif
endif

ifdef AUDIO_COMPENSATION_ENABLE
  BES_EQ_SUPPORT_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM = MT6223 MT6223P MT6225 MT6253 MT6252 MT6252H MT6251
  ACF_MCU_FIR_SUPPORT_PLATFORM = MT6276
  ACF_DSP_FIR_SUPPORT_PLATFORM = MT6251
  ACF_SW_FIR_SUPPORT_PLATFORM = MT6251 MT6276
  NON_HW_FIR_SUPPORT_PLATFORM = MT6261 MT2501 MT2502

  ifeq ($(strip $(AUDIO_COMPENSATION_ENABLE)),TRUE)
    ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
      $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,AUDIO_COMPENSATION_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(PLATFORM)),$(ACF_SW_FIR_SUPPORT_PLATFORM)),)
      ifneq ($(filter $(strip $(PLATFORM)),$(NON_HW_FIR_SUPPORT_PLATFORM)),)
        $(warning ERROR: AUDIO_COMPENSATION_ENABLE is not supported in $(PLATFORM). Please use BES_EQ_SUPPORT instead.)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS += AUDIO_COMPENSATION_ENABLE
        COM_DEFS += __ACF_HW_FIR_SUPPORT__
      endif
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ACF_MCU_FIR_SUPPORT_PLATFORM)),)
      COM_DEFS += __ACF_MCU_FIR_SUPPORT__
      COM_DEFS += __AUDIO_COMPENSATION_SW_VERSION__
      COM_DEFS += __BES_CF_SUPPORT__
      CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\BesCF.a
      endif
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ACF_DSP_FIR_SUPPORT_PLATFORM)),)
      COM_DEFS += __ACF_DSP_FIR_SUPPORT__
      COM_DEFS += __AUDIO_COMPENSATION_SW_VERSION__
    endif
    ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
      ifneq ($(filter $(strip $(PLATFORM)),$(BES_EQ_SUPPORT_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM)),)
        $(warning ERROR: BES_EQ_SUPPORT and AUDIO_COMPENSATION_ENABLE must be exclusive in $(PLATFORM)!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesCF.a

ifdef AUDIO_DSP_LOWPOWER
  ifneq ($(filter MT6256,$(strip $(call Upper,$(PLATFORM)))),)
    ifeq ($(strip $(AUDIO_DSP_LOWPOWER)),TRUE)
      ifneq ($(strip $(DAF_DECODE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,DAF_DECODE,AUDIO_DSP_LOWPOWER)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS   += __AUDIO_DSP_LOWPOWER__ 
      endif
    endif
  endif
endif

ifeq ($(strip $(BES_BASS_SUPPORT)),TRUE)
  BES_BASS_SUPPORT_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6268 MT6268A MT6268 MT6270A MT6276 MT6921 MT6255 MT6256 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_BASS_SUPPORT_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BES_BASS_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter MED_NOT_PRESENT,$(COM_DEFS)),)
    $(warning ERROR: Please turn off BES_BASS_SUPPORT when MED_NOT_PRESENT is defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
    $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,BES_BASS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS   += __BES_BASS_SUPPORT__
  CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
  ifeq ($(strip $(COMPILER)),RVCT)
    COMPOBJS   += $(strip $(AUDLIB))\BesBass.a
  endif
endif
CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BesBass.a

ifdef I2S_INPUT_MODE_SUPPORT 
  ifeq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
    ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
      BES_LOUDNESS_NON_SUPPORT_PLATFORM = MT6251 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_LOUDNESS_NON_SUPPORT_PLATFORM)),)
        COMPOBJS         += $(strip $(AUDLIB))\BesLoudness.a
        COM_DEFS += __BES_LOUDNESS_ON_I2S__
        CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
      else
        COM_DEFS += APPLY_HPF_ON_FM_I2S
      endif
    endif
  endif
endif

ifdef I2S_INPUT_MODE_SUPPORT
  ifeq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
    COM_DEFS += __I2S_INPUT_MODE_SUPPORT__
    I2S_INPUT_SUPPORT_PLATFORM = MT6225 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6256 MT6276 MT6251 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
    I2S_INPUT_WITHOUT_APM_SUPPORT_PLATFORM = MT6251
    ifeq ($(filter $(strip $(PLATFORM)) ,$(I2S_INPUT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support I2S_INPUT_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)) ,$(I2S_INPUT_WITHOUT_APM_SUPPORT_PLATFORM)),)
      COM_DEFS += __I2S_INPUT_MODE_WITHOUT_APM__
    endif
    ifdef DAF_ENCODE
      ifeq ($(strip $(DAF_ENCODE)),TRUE)
        COM_DEFS    += __I2S_DAF_RECORD__
      endif
    endif
    ifdef WAV_CODEC
      ifeq ($(strip $(WAV_CODEC)),TRUE)
        COM_DEFS    += __I2S_WAV_RECORD__
      endif
    endif
    ifdef DEDI_AMR_REC
      ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
        COM_DEFS    += __I2S_AMR_RECORD__
      endif
    endif
  endif
endif

ifeq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
  ifdef DEDI_AMR_REC
    ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
      ifeq ($(strip $(COMPILER)),RVCT)
        ifeq ($(filter __AUDIO_ULTRA_SLIM__,$(strip $(COM_DEFS))),)
          ifdef LOW_COST_SUPPORT
            ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
              COMPOBJS         += $(strip $(AUDLIB))\BLISRC.a
            else
              COMPOBJS         += $(strip $(AUDLIB))\SLIM\BLISRC.a
            endif
          else
            COMPOBJS         += $(strip $(AUDLIB))\BLISRC.a
            CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BLISRC.a
          endif
          CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BLISRC.a
          CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\BLISRC.a
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(CONDITION_COM_DEFS_BESSOUND_SUPPORT)),TRUE)
  COM_DEFS   += BESSOUND_SUPPORT
endif

BLISRC_SUPPORT_PLATFORM = MT6276 MT6256 MT6255 MT6250 MT6922 MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(strip $(PLATFORM)),$(BLISRC_SUPPORT_PLATFORM)),)
  ifeq ($(strip $(COMPILER)),RVCT)
    ifeq ($(filter __AUDIO_ULTRA_SLIM__,$(strip $(COM_DEFS))),)
      ifdef LOW_COST_SUPPORT
        ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COMPOBJS         += $(strip $(AUDLIB))\BLISRC.a
        else
          COMPOBJS         += $(strip $(AUDLIB))\SLIM\BLISRC.a
        endif
      else
        COMPOBJS         += $(strip $(AUDLIB))\BLISRC.a
        CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BLISRC.a
      endif
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BLISRC.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\BLISRC.a
    else
      COMPOBJS         += $(strip $(AUDLIB))\SLIM\resampler.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\resampler.a
    endif
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(BT_AUDIO_VIA_SCO)),TRUE)
      ifeq ($(strip $(COMPILER)),RVCT)
        ifeq ($(filter __AUDIO_ULTRA_SLIM__,$(strip $(COM_DEFS))),)
          ifdef LOW_COST_SUPPORT
            ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
              COMPOBJS         += $(strip $(AUDLIB))\BLISRC.a
              CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BLISRC.a
            else
              COMPOBJS         += $(strip $(AUDLIB))\SLIM\BLISRC.a
              CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\BLISRC.a
            endif
          else
            COMPOBJS         += $(strip $(AUDLIB))\BLISRC.a
            CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\BLISRC.a
          endif
        endif
      endif
    endif
  endif
endif

AUDIO_COMPONENT_SUPPORT_PLATFORM = MT6276
ifneq ($(filter $(strip $(PLATFORM)),$(AUDIO_COMPONENT_SUPPORT_PLATFORM)),)
  COM_DEFS += __AUD_SW_CODEC__
endif

# AUDIO_COMPONENT_SUPPORT_CONDITION  is defined in Option_HAL.mak
ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
  COM_DEFS += __AUD_SW_CODEC__
  COM_DEFS += __AUDIO_COMPONENT_SUPPORT__
endif


ifeq ($(strip $(PLATFORM)),MT6256)
  ifeq ($(strip $(CHIP_VER)),S01)
      COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6255)
    COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
endif
ifeq ($(strip $(PLATFORM)),MT6250)
    COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
endif
ifeq ($(strip $(PLATFORM)),MT6260)
    COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
endif
ifeq ($(strip $(PLATFORM)),MT6261)
    COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
endif
ifeq ($(strip $(PLATFORM)),MT2501)
    COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
endif
ifeq ($(strip $(PLATFORM)),MT2502)
    COM_DEFS    +=  __AUDIO_DSP_LOWPOWER_V2__
endif

ifdef OGG_VORBIS_DECODE
  ifeq ($(strip $(OGG_VORBIS_DECODE)),TRUE)
    VORBIS_CODEC_LITE = MT6253 MT6252 MT6252H 
    VORBIS_CODEC_NOT_SUPPORT_PLATFORM = MT6251
    ifneq ($(filter $(strip $(PLATFORM)),$(VORBIS_CODEC_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support OGG_VORBIS_DECODE and OGG_VORBIS_ENCODE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif    
    ifneq ($(filter $(strip $(PLATFORM)) ,$(VORBIS_CODEC_LITE)),)
       COMPOBJS         += $(strip $(AUDLIB))\vorbis_codec_slim.a
       CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\vorbis_codec_slim.a
       COM_DEFS += __VORBIS_DECODE_SLIM__
    else
       COMPOBJS         += $(strip $(AUDLIB))\vorbis_codec.a
       CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\vorbis_codec.a
    endif
    COM_DEFS += __VORBIS_DECODE__
    ifeq ($(strip $(OGG_VORBIS_ENCODE)),TRUE)  
      COM_DEFS += __VORBIS_ENCODE__
      ifeq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
         COM_DEFS += __I2S_VORBIS_RECORD__
      endif
    endif
  endif
endif

ifeq ($(strip $(AU_DECODE)),TRUE)
   AU_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(AU_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AU_DECODE.)
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += AU_DECODE
endif

ifeq ($(strip $(AIFF_DECODE)),TRUE)
   AIFF_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(AIFF_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AIFF_DECODE.)
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += AIFF_DECODE
endif

ifdef WAV_CODEC
  ifeq ($(strip $(WAV_CODEC)),TRUE)
    COM_DEFS    += WAV_CODEC
  else
    ifeq ($(strip $(AIFF_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,WAV_CODEC,AIFF_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AU_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,WAV_CODEC,AU_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq ($(filter AU_DECODE AIFF_DECODE,$(strip $(COM_DEFS))),)
        COMPOBJS         += $(strip $(AUDLIB))\SLIM\wav_codec.a
      else
        COMPOBJS         += $(strip $(AUDLIB))\wav_codec.a
      endif
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\wav_codec.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\wav_codec.a
    endif
    COM_DEFS         += __WAV_DECODE_SWIP__
  endif
endif

ifdef DEDI_AMR_REC
  DEDI_AMR_REC_NOT_SUPPORT_PLATFORM = MT6205B MT6223 MT6223P
  DEDI_AMR_REC_SWIP_NOT_SUPPORT_PLATFORM = MT6226 MT6226M MT6227 MT6226D MT6227D
  ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(DEDI_AMR_REC_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DEDI_AMR_REC=TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef AMR_CODEC
      $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifneq ($(strip $(AMR_CODEC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS += DEDI_AMR_REC
    ifeq ($(filter $(strip $(PLATFORM)),$(DEDI_AMR_REC_SWIP_NOT_SUPPORT_PLATFORM)),)
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += $(strip $(AUDLIB))\amr_codec.a
        CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\amr_codec.a
      endif
    endif
  endif
endif

ifeq ($(strip $(DAF_DECODE)),TRUE)
  DAF_DECODE_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6252 MT6252H MT6253T MT6253 MT6253E MT6253L MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6251 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(filter $(strip $(PLATFORM)) ,$(DAF_DECODE_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DAF_DECODE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(COMPILER)),RVCT)
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
      ifeq ($(strip $(MUSICAM_DECODE)),TRUE)
        COMPOBJS         += $(strip $(AUDLIB))\mp3_dec.a
      else
        COMPOBJS         += $(strip $(AUDLIB))\SLIM\mp3_dec.a
      endif
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\mp3_dec.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\mp3_dec.a
    endif
  endif  
  COM_DEFS += DAF_DECODE
endif

## MT6217, 6219, 6227_S00 and 6228_S00, 6228_S01 and 6229_S00, 6223 not support MUSICAM_DECODE
ifdef MUSICAM_DECODE
  MUSICAM_DECODE_NOT_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6223 MT6253E MT6253L MT6252 MT6252H
  ifeq ($(strip $(MUSICAM_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MUSICAM_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support MUSICAM_DECODE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6227)
      ifeq ($(strip $(CHIP_VER)),S00)
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)
        DEPENDENCY_CONFLICT = TRUE
      endif      
    endif
    ifeq ($(strip $(PLATFORM)),MT6228)
      ifeq ($(strip $(CHIP_VER)),S00)
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)
        DEPENDENCY_CONFLICT = TRUE
      endif      
      ifeq ($(strip $(CHIP_VER)),S01)
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(PLATFORM)),MT6229)
      ifeq ($(strip $(CHIP_VER)),S00)
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(DAF_DECODE)),TRUE)
      COM_DEFS    += MUSICAM_DECODE
    else
      $(call DEP_ERR_ONA_OR_OFFB,DAF_DECODE,MUSICAM_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef APE_DECODE
  ifeq ($(strip $(APE_DECODE)),TRUE)
    APE_DECODE_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6921 MT6255 MT6922
    ifeq ($(filter $(strip $(PLATFORM)) ,$(APE_DECODE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support APE_DECODE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS         += $(strip $(AUDLIB))\ape_dec.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\ape_dec.a
    endif  
    COM_DEFS += __APE_DECODE__
  endif
endif

ifdef COOK_DECODE
  ifeq ($(strip $(COOK_DECODE)),TRUE)
    COM_DEFS += __COOK_DECODE__
    COOK_DECODE_DSP_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6236 MT6236B MT6921
    ifeq ($(filter $(strip $(PLATFORM)) ,$(COOK_DECODE_DSP_PLATFORM)),)
       ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS         += $(strip $(AUDLIB))\cook_dec.a
          CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\cook_dec.a
       endif
    else
       COM_DEFS += __COOK_DECODE_DSP__
    endif
  endif
endif

ifdef DRA_DECODE
  ifeq ($(strip $(DRA_DECODE)),TRUE)
    DRA_DECODE_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6268A MT6268 MT6270A MT6276 MT6921 MT6256 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)),$(DRA_DECODE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DRA_DECODE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __DRA_DECODE_SUPPORT__
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += hal\audio\lib\VENDOR\dra\ArmDraDecLib_rvct.a
        CUS_REL_OBJ_LIST += hal\audio\lib\VENDOR\dra\ArmDraDecLib_rvct.a
      endif
    else
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += hal\audio\lib\VENDOR\dra\ArmDraDecLib_rvct_Trial.a
        CUS_REL_OBJ_LIST += hal\audio\lib\VENDOR\dra\ArmDraDecLib_rvct_Trial.a
      endif
    endif
  endif
endif

ifeq ($(strip $(AAC_DECODE)),TRUE)
  AAC_DECODE_SUPPORT_PLATFORM = MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6252 MT6252H MT6253T MT6253 MT6253E MT6253L MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6251 MT6921 MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_DECODE_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AAC_DECODE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS         += $(strip $(AUDLIB))\aac_dec.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\aac_dec.a
      COM_DEFS    += __AAC_DECODE_SWIP__
    endif
  endif
  COM_DEFS    += AAC_DECODE
endif

ifdef AAC_PLUS_DECODE
  ifeq ($(strip $(AAC_PLUS_DECODE)),TRUE)
    AAC_PLUS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6256 MT6276 MT6921 MT6255 MT6922
    ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_PLUS_DECODE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AAC_PLUS_DECODE.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
      ifeq ($(strip $(AAC_PLUS_PS_DECODE)),FALSE)
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS         += $(strip $(AUDLIB))\heaacv1_dec.a
          CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\heaacv1_dec.a
          COM_DEFS    += __HEAAC_V1_DECODE_SWIP__
        endif
      endif
    endif      
    COM_DEFS    +=  AAC_PLUS_DECODE
  endif
endif

ifdef AAC_PLUS_PS_DECODE
  ifeq ($(strip $(AAC_PLUS_PS_DECODE)),TRUE)
    AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6253E MT6253L MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A MT6256 MT6276 MT6252 MT6252H MT6921 MT6255 MT6922
    ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AAC_PLUS_PS_DECODE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AAC_PLUS_DECODE)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_PLUS_DECODE,AAC_PLUS_PS_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS         += $(strip $(AUDLIB))\heaacv2_dec.a
        CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\heaacv2_dec.a
        COM_DEFS    += __HEAAC_V2_DECODE_SWIP__
      endif
    endif 
    COM_DEFS += AAC_PLUS_PS_DECODE
  endif
endif

ifeq ($(strip $(M4A_DECODE)),TRUE)
  ifneq ($(strip $(AAC_DECODE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,M4A_DECODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += M4A_DECODE
endif

ifdef WMA_DECODE
  ifeq ($(strip $(WMA_DECODE)),TRUE)
    WMA_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6253T MT6253 MT6253E MT6253L MT6270A MT6252 MT6252H MT6921 MT6255 MT6256
    ifeq ($(filter $(strip $(PLATFORM)) ,$(WMA_DECODE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support WMA_DECODE.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
        COMPOBJS         += $(strip $(AUDLIB))\wma_dec.a
        CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\wma_dec.a
        COMPOBJS         += $(strip $(AUDLIB))\asf_parser.a
        CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\asf_parser.a
      endif
    endif
    COM_DEFS    += WMA_DECODE
  endif
endif

ifdef BT_SPEAKER_SUPPORT                    
  ifeq ($(strip $(BT_SPEAKER_SUPPORT)),TRUE)
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE) 
      COMPOBJS         += $(strip $(AUDLIB))\sbc_dec.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\sbc_dec.a
      COM_DEFS         += SBC_DECODE
    endif
  endif   
endif

ifdef BT_MAX_LINK_NUM
  ifeq ($(strip $(BT_MAX_LINK_NUM)),2)
    COM_DEFS += __BT_SERIAL_PLAYBACK_AUDIO_SYNC__
  endif
endif

ifeq ($(strip $(SPECTRUM_DISPLAY)),TRUE)
  COM_DEFS   +=  __SPECTRUM_DISPLAY_SUPPORT__
endif

ifeq ($(strip $(VM_CODEC)),TRUE)
  COM_DEFS   +=  __VM_CODEC_SUPPORT__
endif

ifeq ($(strip $(KEY_TONE_DETECTION)),TRUE)
  COM_DEFS   +=  __KEY_TONE_DETECTION__
endif

WT_ROM_V1_SUPPORT_PLATFORM = MT6253 MT6253T MT6253E MT6253L MT6252 MT6252H
WT_ROM_V2_SUPPORT_PLATFORM = MT6251
ifeq ($(strip $(WAVETABLE_VER)),WT_ROM_V1)
  ifeq ($(filter $(strip $(PLATFORM)),$(WT_ROM_V1_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support WAVETABLE_VER=WT_ROM_V1) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(WAVETABLE_VER)),WT_ROM_V2)
  ifeq ($(filter $(strip $(PLATFORM)),$(WT_ROM_V2_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support WAVETABLE_VER=WT_ROM_V2) 
    DEPENDENCY_CONFLICT = TRUE
  endif
else
  ifneq ($(filter $(strip $(PLATFORM)),$(WT_ROM_V2_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) must set WAVETABLE_VER=WT_ROM_V2)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef MELODY_VER
  ifeq ($(strip $(MELODY_VER)),NONE)
    MELODY_SWITCHOFF_MED_FLAVOR = MED_MODEM MED_BASIC
    ifeq ($(filter $(strip $(MELODY_SWITCHOFF_MED_FLAVOR)),$(MED_PROFILE)),)
      $(warning ERROR: Please do NOT set MELODY_VER to be NONE or set MED_PROFILE to be one of following value: $(MELODY_SWITCHOFF_MED_FLAVOR))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
  ifeq ($(strip $(PLATFORM)),MT6205B)
     $(warning ERROR: $(strip $(PLATFORM)) does not support MELODY_VER=$(strip $(MELODY_VER))) 
     DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += $(strip $(WAVETABLE_VER))
  ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
      COMPOBJS    += $(strip $(AUDLIB))\melody_par.a
    else
      COMPOBJS    += $(strip $(AUDLIB))\SLIM\melody_par.a
    endif
    COMPOBJS    += $(strip $(AUDLIB))\melody_syn.a
    CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\melody_syn.a
    CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\melody_par.a
    CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\SLIM\melody_par.a
  else
    COMPOBJS    += $(strip $(AUDLIB))\melody_cmi.a
    CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\melody_cmi.a
  endif
endif

ifeq ($(strip $(JTONE_SUPPORT)),TRUE)
   JTONE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(JTONE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support JTONE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += JTONE_SUPPORT
endif

BACKGROUND_SOUND_NOT_SUPPORT_PLATFORM = MT6226 MT6226M MT6227
ifdef BACKGROUND_SOUND
  ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(BACKGROUND_SOUND_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(strip $(PLATFORM)) does not support BACKGROUND_SOUND) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += BGSND_ENABLE
  endif
endif

ifdef CTM_SUPPORT
  ifneq ($(strip $(CTM_SUPPORT)),FALSE)
    COM_DEFS    +=  __CTM_SUPPORT__
    COMPLIST += dp_engine
  endif
endif

ifdef IP_COMMON_SUPPORT
  ifeq ($(strip $(IP_COMMON_SUPPORT)),TRUE)
    COM_DEFS += __IPS_SUPPORT__
    IP_COMMON_SUPPORT_PLATFORM = MT6236 MT6236B MT6276 MT6921 MT6256 MT6255 MT6922
    ifeq ($(filter $(strip $(PLATFORM)) ,$(IP_COMMON_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support IP_COMMON_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += $(strip $(AUDLIB))\ipcommon.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\ipcommon.a
    endif
  endif
endif

ifneq ($(strip $(IP_COMMON_SUPPORT)),TRUE)
  ifneq ($(filter MT6276%,$(PLATFORM)),)
    ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(warning ERROR: Please turn on IP_COMMON_SUPPORT when MELODY_VER=DSP_WT_SYN on 6276 projects.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(filter MT6256%,$(PLATFORM)),)
    ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(warning ERROR: Please turn on IP_COMMON_SUPPORT when MELODY_VER=DSP_WT_SYN on 6256 projects.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(filter MT6255%,$(PLATFORM)),)
    ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(warning ERROR: Please turn on IP_COMMON_SUPPORT when MELODY_VER=DSP_WT_SYN on 6255 projects.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(filter MT6922%,$(PLATFORM)),)
    ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(warning ERROR: Please turn on IP_COMMON_SUPPORT when MELODY_VER=DSP_WT_SYN on 6922 projects.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(filter MT6236% MT6921,$(PLATFORM)),)
    ifeq ($(strip $(APE_DECODE)),TRUE)
      $(warning ERROR: Please turn on IP_COMMON_SUPPORT when APE_DECODE=TRUE on 6236 projects.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(VIDEO_STANDALONE_MEMORY)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
      COM_DEFS += __VIDEO_STANDALONE_MEMORY__
    else
      $(warning ERROR: Please set DSP_SOLUTION = DUALMACDSP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    $(warning ERROR: Please set MMI_VERSION = COSMOS_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

COMMINCDIRS   +=  custom\common\hal_public
COMMINCDIRS   +=  custom\common\ps

COMMINCDIRS += custom\codegen\$(strip $(BOARD_VER))

VP8_DECODE_SUPPORT_PLATFORM = MT6250 MT6255 MT6256 MT6276 MT6260 MT6261 MT2501 MT2502
ifeq ($(strip $(VP8_DECODE)),TRUE)
  ifneq ($(strip $(MP4_DECODE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,VP8_DECODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter $(strip $(PLATFORM)),$(VP8_DECODE_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support VP8_DECODE = TRUE)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS += __VP8_DEC_SW_SUPPORT__
  endif
endif

ifdef SW_TYPE
  ifneq ($(strip $(SW_TYPE)),MODEM_PRODUCT)
    ifeq ($(filter __L1_STANDALONE__,$(COM_DEFS)),)
      ifeq ($(filter __MAUI_BASIC__,$(COM_DEFS)),)
        ifdef SMART_PHONE_CORE
          ifeq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
            COM_DEFS  += MULTI_MEDIA_EXIST
          endif
        else
          COM_DEFS  += MULTI_MEDIA_EXIST
        endif
      endif
    endif
  endif
else
  ifeq ($(filter __L1_STANDALONE__,$(COM_DEFS)),)
      ifeq ($(filter __MAUI_BASIC__,$(COM_DEFS)),)
        ifdef SMART_PHONE_CORE
          ifeq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
            COM_DEFS  += MULTI_MEDIA_EXIST
          endif
        else
          COM_DEFS  += MULTI_MEDIA_EXIST
        endif
      endif
    endif
endif

ifeq ($(strip $(VIDEO_SUBTITLE_SUPPORT)),TRUE)
  ifeq ($(strip $(MKV_FILE_FORMAT_SUPPORT)),TRUE)
    COM_DEFS += __VIDEO_SUBTITLE_SUPPORT__
  else
    $(call DEP_ERR_ONA_OR_OFFB,MKV_FILE_FORMAT_SUPPORT,VIDEO_SUBTITLE_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MKV_FILE_FORMAT_SUPPORT)),TRUE)
  COM_DEFS += __MKV_FILE_FORMAT_SUPPORT__
endif

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),BASIC)
    $(call DEP_ERR_SETA_OR_OFFB,NAND_FLASH_BOOTING,non BASIC,MULTIPLE_BINARY_FILES)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __MULTIPLE_BINARY_FILES__
  ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
    COM_DEFS    +=  __MBA_ON_DEMAND__
  endif
  ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
    COM_DEFS    +=  __MBA_ON_DEMAND__
  endif
  ifeq ($(strip $(MBA_DEFAULT_BINARY)),CUST_ONLY)
    COM_DEFS     +=  __MBA_CUST_ONLY__
  endif
  ifeq ($(strip $(MBA_DEFAULT_BINARY)),LANG_ONLY)
    COM_DEFS     +=  __MBA_LANG_ONLY__
  endif
  ifeq ($(strip $(MBA_DEFAULT_BINARY)),CUST_AND_LANG)
    COM_DEFS     +=  __MBA_CUST_ONLY__
    COM_DEFS     +=  __MBA_LANG_ONLY__
  endif
endif

MJPEG_DIRECT_COUPLE_PLATFORM = MT6256
ifdef CAMCORDER_MOTION_SENSOR_SUPPORT
  ifneq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),NONE)
  ifneq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
      ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
         ifeq ($(strip $(SENSOR_TYPE)),JPEG)
           ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),BOTH_BY_ENCODE)
               $(warning ERROR: Please set CAMCORDER_MOTION_SENSOR_SUPPORT as BOTH_BY_TAG or CAM_BY_TAG_REC_BY_ENCODE due to jpeg sensor.)
               DEPENDENCY_CONFLICT = TRUE
           else
             ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),CAM_BY_ENCODE_REC_BY_TAG)
               $(warning ERROR: Please set CAMCORDER_MOTION_SENSOR_SUPPORT as BOTH_BY_TAG or CAM_BY_TAG_REC_BY_ENCODE due to jpeg sensor.)
               DEPENDENCY_CONFLICT = TRUE
             endif
           endif
         endif
      
         ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),BOTH_BY_ENCODE)
           ifneq ($(filter $(strip $(PLATFORM)) ,$(MJPEG_DIRECT_COUPLE_PLATFORM)),)
             ifeq ($(strip $(MJPG_ENCODE)),TRUE)
               $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG encode rotation, please turn off MJPG_ENCODE)
               DEPENDENCY_CONFLICT = TRUE
              endif
            endif
           COM_DEFS += __CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__
           COM_DEFS += __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
         endif

         ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),BOTH_BY_TAG)
           COM_DEFS += __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
           COM_DEFS += __RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__
         endif

         ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),CAM_BY_TAG_REC_BY_ENCODE)
           ifneq ($(filter $(strip $(PLATFORM)) ,$(MJPEG_DIRECT_COUPLE_PLATFORM)),)
             ifeq ($(strip $(MJPG_ENCODE)),TRUE)
               $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG encode rotation, please turn off MJPG_ENCODE)
               DEPENDENCY_CONFLICT = TRUE
             endif
           endif
           COM_DEFS += __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
           COM_DEFS += __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
         endif

         ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),CAM_BY_ENCODE_REC_BY_TAG)
           COM_DEFS += __CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__
           COM_DEFS += __RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__
         endif
      else
         ifneq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),BOTH_BY_TAG)
             $(warning ERROR: Please set CAMCORDER_MOTION_SENSOR_SUPPORT as BOTH_BY_TAG or NONE)
            DEPENDENCY_CONFLICT = TRUE
         endif

         ifeq ($(strip $(CAMCORDER_MOTION_SENSOR_SUPPORT)),BOTH_BY_TAG)
           COM_DEFS += __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
           COM_DEFS += __RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__
         endif
         
      endif
    else
       $(call DEP_ERR_ONA_OR_OFFB,MOTION_SENSOR_SUPPORT,CAMCORDER_MOTION_SENSOR_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
     $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_SUPPORT,CAMCORDER_MOTION_SENSOR_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  endif
endif

ifeq ($(strip $(DRV_BATTERY_EXIST_DETECTION)),TRUE)
  COM_DEFS  += __DRV_BATTERY_EXIST_DETECTION__
endif

ifdef CHARGING_ALGORITHM
  ifeq ($(strip $(CHARGING_ALGORITHM)),PULSE_LI_CHARGING)
    COM_DEFS  += PULSE_LI_CHARGING
  endif
  ifeq ($(strip $(CHARGING_ALGORITHM)),PULSE_NIMH_CHARGING)
    COM_DEFS  += PULSE_NIMH_CHARGING
  endif
  ifeq ($(strip $(CHARGING_ALGORITHM)),LINEAR_LI_CHARGING)
    COM_DEFS  += LINEAR_LI_CHARGING
  endif
  ifeq ($(strip $(CHARGING_ALGORITHM)),LINEAR_NIMH_CHARGING)
    COM_DEFS  += LINEAR_NIMH_CHARGING
  endif
endif

ifdef DSP_COMPRESS
  ifneq ($(strip $(DSP_COMPRESS)),NONE)
    DSP_COMPRESS_SUPPORT_PLATFORM = MT6225 MT6253 MT6253D MT6253E MT6253L MT6252 MT6252H MT6250 MT6260 MT6261 MT2501 MT2502
    ifeq ($(strip $(DSP_COMPRESS)),ZIP)
      COM_DEFS += __DSP_COMPRESS__
    endif
    ifeq ($(strip $(DSP_COMPRESS)),7Z)
      COM_DEFS += __DSP_COMPRESS_7Z__
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(DSP_COMPRESS_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DSP_COMPRESS.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(filter BTMTK_MT6250 BTMTK_MT6260 BTMTK_MT6261 BTMTK_MT2501 BTMTK_MT2502, $(strip $(BLUETOOTH_SUPPORT))),)
    COM_DEFS    +=  __CVSD_CODEC_SUPPORT__
    COMPLIST    += dp_engine
    ifeq ($(strip $(COMPILER)),RVCT)
       COMPOBJS         += $(strip $(AUDLIB))\Audio_IIRHPF.a
       CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\Audio_IIRHPF.a
       COMPOBJS         += $(strip $(AUDLIB))\cvsd_codec.a
       CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\cvsd_codec.a
       COMPOBJS         += $(strip $(AUDLIB))\plc.a
       CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\plc.a
    endif
  endif
endif

ifneq ($(filter MT6261 MT2501 MT2502, $(strip $(PLATFORM))),)
  ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)), TRUE)
    ifneq ($(strip $(WIFI_INTERFACE_TYPE)), HIF_SDIO)
      $(warning ERROR: Please set WIFI_INTERFACE_TYPE = HIF_SDIO when turn on MT6261/MT2501/MT2502 WIFI)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef WIFI_INTERFACE_TYPE
  ifeq ($(strip $(WIFI_INTERFACE_TYPE)),NONE)
    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WIFI_INTERFACE_TYPE,WIFI_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

ifeq ($(strip $(WIFI_INTERFACE_TYPE)),EHPI_8BIT)
  COM_DEFS  += __WIFI_EHPI_8BIT__
endif
ifeq ($(strip $(WIFI_INTERFACE_TYPE)),EHPI_16BIT)
  COM_DEFS  += __WIFI_EHPI_16BIT__
endif
ifeq ($(strip $(WIFI_INTERFACE_TYPE)),HIF_SDIO)
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_SDIO)
    $(warning ERROR: please set MSDC_CARD_SUPPORT_TYPE as MSDC_SD_SDIO when WIFI_INTERFACE_TYPE = HIF_SDIO.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  += __WIFI_HIF_SDIO__
endif
endif

ifeq ($(strip $(VIDEO_PLAYER_RECORDER_W_DCM)),ENABLE)
  ifneq ($(strip $(DCM_COMPRESSION_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DCM_COMPRESSION_SUPPORT,VIDEO_PLAYER_RECORDER_W_DCM)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  += __DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__
endif

ifeq ($(strip $(FLAC_DECODE)),TRUE)
  FLAC_DECODE_SUPPORT_PLATFORM = MT6255 MT6256 MT6250 MT6260 MT6261 MT2501 MT2502
  ifeq ($(filter $(strip $(PLATFORM)),$(FLAC_DECODE_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support FLAC_DECODE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(COMPILER)),RVCT)
    ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
      COMPOBJS         += $(strip $(AUDLIB))\flac_dec.a
      CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\flac_dec.a
    endif
  endif
  COM_DEFS += __FLAC_DECODE__
endif

ifdef CUSTOM_WIFI_FEATURES_SWITCH
  ifeq ($(strip $(CUSTOM_WIFI_FEATURES_SWITCH)),TRUE)
    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      COM_DEFS += __CUSTOM_WIFI_FEATURES_SWITCH__
    else
      $(call DEP_ERR_SETA_OR_OFFB,WIFI_SUPPORT,MT5931,CUSTOM_WIFI_FEATURES_SWITCH)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(ECALL_SUPPORT)),TRUE)
  ifneq ($(strip $(R4_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,ECALL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ECALL_SUPPORT__
  COM_DEFS    += __ECALL_PSAP_SUPPORT__
  ifneq ($(strip $(ECALL_SOURCE_REL_SUPPORT)),TRUE)
    COMPLIST    += dp_engine
  endif
endif

ifneq ($(filter MT6276 MT6255 MT6250 MT6256 MT6260 MT6261 MT2501 MT2502,$(PLATFORM)),)
  ifeq ($(filter WT600K WT150K WT70K WT20K,$(WAVETABLE_VER)),)
    $(warning ERROR: WAVETABLE_VER only allows WT600K\WT150K\WT70K\WT20K,when PLATFORM = $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  COM_DEFS    += __ATCI_QUEUE_AT__
endif

ifeq ($(strip $(VIDEO_CLIPPER_SUPPORT)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    CLIPPER_SUPPORT = FALSE 
    ifeq ($(strip $(M3GPMP4_FILE_FORMAT_SUPPORT)),TRUE)
      CLIPPER_SUPPORT = TRUE
    endif
    ifeq ($(strip $(MJPG_DECODE)),TRUE)
      CLIPPER_SUPPORT = TRUE
    endif
    ifeq ($(strip $(CLIPPER_SUPPORT)),TRUE)
      COM_DEFS += __VIDEO_CLIPPER_SUPPORT__
    endif
  endif
endif

AUDIO_DC_CALIBRATION_PLATFORM = MT6251 MT6255 MT6256 MT6250 MT6922 MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(AUDIO_DC_CALIBRATION_PLATFORM),$(PLATFORM)),)
  COM_DEFS    += __AUDIO_DC_CALIBRATION_SUPPORT__
endif

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
  ifdef EMMC_BOOTING
    ifneq ($(strip $(EMMC_BOOTING)),NONE)
      $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set EMMC_BOOTING = NONE.)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifdef NAND_FLASH_BOOTING
        ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
          $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set NAND_FLASH_BOOTING = NONE.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifdef NAND_FLASH_BOOTING
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set NAND_FLASH_BOOTING = NONE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  COM_DEFS     += __SERIAL_FLASH_EN__
  COM_DEFS     += __SERIAL_FLASH_SUPPORT__
endif

ifeq ($(strip $(VIDEO_SUBTITLE_SUPPORT)),TRUE)
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
              $(call DEP_ERR_SETA_OR_SETB,FINGER_TOUCH_SUPPORT,FTE,VIDEO_SUBTITLE_SUPPORT,FALSE)
              DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

ifeq ($(strip $(VIDEO_SUBTITLE_SUPPORT)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(call DEP_ERR_SETA_OR_SETB,FINGER_TOUCH_SUPPORT,FTE,VIDEO_SUBTITLE_SUPPORT,FALSE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

JPEG_SENSOR_SUPPORT_PLATFORM = MT6256 MT6276 MT6255 MT6922
ifeq ($(strip $(SENSOR_TYPE)),JPEG)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(JPEG_SENSOR_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support JPEG SENSOR)
       DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __JPEG_SENSOR_SUPPORT__
    endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),ULC)
    ifdef MJPG_ENCODE_MODE
      ifeq ($(strip $(MJPG_ENCODE)),TRUE)
        ifndef MJPG_DECODE_MODE
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_ENCODE_MODE=$(strip $(MJPG_ENCODE_MODE)) without MJPG_DECODE_MODE define .)
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(MJPG_ENCODE_MODE)),NORMAL)
          ifeq ($(strip $(MJPG_DECODE_MODE)),SLIM)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_ENCODE_MODE=$(strip $(MJPG_ENCODE_MODE)) with MJPG_DECODE_MODE=$(strip $(MJPG_DECODE_MODE)) .)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
        ifeq ($(strip $(MJPG_ENCODE_MODE)),SLIM)
          MJPG_ENCODE_MODE_SLIM_SUPPORT_PLATFORM = MT6250 MT6260 MT6261 MT2501 MT2502
          ifeq ($(filter $(strip $(PLATFORM)) ,$(MJPG_ENCODE_MODE_SLIM_SUPPORT_PLATFORM)),)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_ENCODE_MODE=$(strip $(MJPG_ENCODE_MODE)) .)
            DEPENDENCY_CONFLICT = TRUE
          endif  
          COM_DEFS += __MJPEG_ENC_SW_SLIM__
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(DUAL_SERIAL_FLASH_SUPPORT)),TRUE)
  COM_DEFS += __DUAL_SERIAL_FLASH_SUPPORT__
  ifneq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
    $(warning ERROR: DUAL_SERIAL_FLASH_SUPPORT = TRUE only available when COMBO_MEMORY_SUPPORT = TRUE on MT6250/MT6260/MT6261/MT2501/MT2502.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter MT6250 MT6260 MT6261 MT2501 MT2502,$(PLATFORM)),)
    $(warning ERROR: DUAL_SERIAL_FLASH_SUPPORT = TRUE only available when COMBO_MEMORY_SUPPORT = TRUE on MT6250/MT6260/MT6261/MT2501/MT2502.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(AUDIO_COMPONENT_SUPPORT_CONDITION)),TRUE)
  COM_DEFS    += __MCU_DTMF_SUPPORT__
  ifeq ($(strip $(COMPILER)),RVCT)
    COMPOBJS    += $(strip $(AUDLIB))\dtmf_gen.a
    CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\dtmf_gen.a
  endif
endif

ifdef CLASSK_CHARGEPUMP_SUPPORT
  ifeq ($(strip $(CLASSK_CHARGEPUMP_SUPPORT)),TRUE)
    CLASSK_CHARGEPUMP_SUPPORT_PLATFORM = MT6260 MT6261 MT2501 MT2502
    ifeq ($(filter $(strip $(PLATFORM)),$(CLASSK_CHARGEPUMP_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support CLASSK_CHARGEPUMP.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __CLASSK_CP_SUPPORT__
  endif
endif

ifdef VERIFY_ALL_IMAGES
  ifeq ($(strip $(VERIFY_ALL_IMAGES)),TRUE)
    ifneq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ZIMAGE_SUPPORT,VERIFY_ALL_IMAGES)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ALICE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ALICE_SUPPORT,VERIFY_ALL_IMAGES)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef KARAOKE_SUPPORT
  ifeq ($(strip $(KARAOKE_SUPPORT)),TRUE)
    COM_DEFS     += __KARAOKE_SUPPORT__
    COM_DEFS     += __KARAOKE_NEED_KEEP_SRC_PATH__
  endif
  COMPOBJS         += $(strip $(AUDLIB))\aec.a
  CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\aec.a
endif

ifdef HEART_RATE_SENSOR
  ifneq ($(strip $(HEART_RATE_SENSOR)),NONE)
    COM_DEFS  +=  __HEART_RATE_ENABLE__
    COM_DEFS  +=  __HEART_RATE_$(strip $(HEART_RATE_SENSOR))__
  endif
endif

ifdef VAD_SUPPORT
  ifeq ($(strip $(VAD_SUPPORT)),TRUE)
    COMPOBJS         += $(strip $(AUDLIB))\vad.a
    CUS_REL_OBJ_LIST += $(strip $(AUDLIB))\vad.a
  endif
endif

# LCD option settings
# --------------------------
COM_DEFS  += __LCD_SUPPORT__
ifdef BT_PRODUCT_LINE
  ifeq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
    COM_DEFS := $(filter-out __LCD_SUPPORT__,$(COM_DEFS))
  endif
endif

ifdef MMI_VERSION
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    COM_DEFS := $(filter-out __LCD_SUPPORT__,$(COM_DEFS))
  endif
endif

LCD_ESD_RECOVERY_SUPPORT_PLATFORM := MT6261 MT2501 MT2502
ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifneq ($(filter __LCD_SUPPORT__,$(COM_DEFS)),)
      ifneq ($(filter $(PLATFORM),$(LCD_ESD_RECOVERY_SUPPORT_PLATFORM)),)
        COM_DEFS += __LCD_ESD_RECOVERY__
      endif
    endif
  endif
endif
# --------------------------

ifneq ($(filter __LCD_SUPPORT__,$(COM_DEFS)),)
  ifeq ($(strip $(PLATFORM)),MT2501)
    COM_DEFS    += __MT6261_PRODUCTION_IMPROVE__
  endif
endif