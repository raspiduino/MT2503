/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   media_provider_mem_usage_internal.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_PROVIDER_MEM_USE_INTERNAL_H
#define _MEDIA_PROVIDER_MEM_USE_INTERNAL_H

#include "drv_features_video.h"
#include "hal_custom_provider_if.h"

// MP4 memory requirement calculation
#include "mpl_player.h"
#include "source_provider_if.h"
#include "mp4_parser.h"
#include "mp4_provider.h"
#include "cache_sw.h"

#if defined(__VE_SP_AVI__)
#include "avi_provider.h"
#endif

// FLV memory requirement calculation
#if defined(__VE_FLV_FILE_FORMAT_SUPPORT__)
#include "flv_parser.h"
#include "flv_provider.h"
#endif

#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)
#include "fsal.h"
#include "mkv_parser.h"
#include "mkv_provider.h"
#endif

#define ALIGN_X(VAL, SIZE) \
           ((((VAL)+(SIZE)-1)/(SIZE))*(SIZE))

#define SP_CPU_CACHE_LINE_SIZE (CPU_CACHE_LINE_SIZE)
#define SOURCE_PROVIDER_COMMAND_SIZE        (8)
#define SOURCE_PROVIDER_BUFFERHEADER_SIZE   (32)
#define SOURCE_PROVIDER_ADM_SIZE (512)

/****************
  Total core size of source
  1. source provider context,
  2. componet size,
  3. adm size for provider core memory management
  ****************/
// context size
#define SOURCE_PROVIDER_CONTEXT_SIZE (5120)

// component size
#define SOURCE_PROVIDER_CMD_Q_LEN (10)
#define SOURCE_PROVIDER_CMD_Q_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_CMD_Q_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

#define SOURCE_PROVIDER_INPUT_BUFFER_Q_1_LEN (0)
#define SOURCE_PROVIDER_INPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_INPUT_BUFFER_Q_1_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

#define SOURCE_PROVIDER_INPUT_BUFFER_Q_2_LEN (0)
#define SOURCE_PROVIDER_INPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_INPUT_BUFFER_Q_2_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_1_LEN (10)
#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_OUTPUT_BUFFER_Q_1_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_2_LEN (10)
#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_OUTPUT_BUFFER_Q_2_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

// for subtitle. Todo: use define to choice
#ifdef __VIDEO_SUBTITLE_SUPPORT__
#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_3_LEN (10)
#else
#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_3_LEN (0)
#endif
#define SOURCE_PROVIDER_OUTPUT_BUFFER_Q_3_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_OUTPUT_BUFFER_Q_3_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)


#define SOURCE_PROVIDER_COMPONENT_SIZE (SOURCE_PROVIDER_CMD_Q_SIZE_ALIGN_CACHE_LINE + \
                                                                                SOURCE_PROVIDER_INPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE + \
                                                                                SOURCE_PROVIDER_INPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE +\
                                                                                SOURCE_PROVIDER_OUTPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE + \
                                                                                SOURCE_PROVIDER_OUTPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE + \
                                                                                SOURCE_PROVIDER_OUTPUT_BUFFER_Q_3_SIZE_ALIGN_CACHE_LINE + \
                                                                                SOURCE_PROVIDER_ADM_SIZE)

// total size
#define SOURCE_PROVIDER_CORE_MEM (SOURCE_PROVIDER_CONTEXT_SIZE + \
                                                                SOURCE_PROVIDER_COMPONENT_SIZE +\
                                                                SOURCE_PROVIDER_ADM_SIZE)

/****************
  Total Audio size of source
  1. buffer header
  2. private data
  ****************/
// buffer size
#ifdef __VE_SP_PROFILE_A_MIN_BUFFER__
#define SOURCE_PROVIDER_A_BUF_HEADER_LEN (2)
#else
#define SOURCE_PROVIDER_A_BUF_HEADER_LEN (120)
#endif
#define SOURCE_PROVIDER_A_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE \
                    ALIGN_X((SOURCE_PROVIDER_A_BUF_HEADER_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

// private size
#define SOURCE_PROVIDER_A_PRIVATE_DATA_SIZE (0)

// total size
#define SOURCE_PROVIDER_AUDIO_MEM (SOURCE_PROVIDER_A_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE + \
                                                                      SOURCE_PROVIDER_A_PRIVATE_DATA_SIZE)


/****************
  Total video size of source
  1. buffer header
  2. private data
  ****************/
// buffer size
#ifdef __VE_SP_PROFILE_V_MIN_BUFFER__
#define SOURCE_PROVIDER_V_BUF_HEADER_LEN (2)
#else
#define SOURCE_PROVIDER_V_BUF_HEADER_LEN (60)
#endif
#define SOURCE_PROVIDER_V_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_V_BUF_HEADER_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

// private size
#ifdef __VE_KMV_SUPPORT__ 
#define SOURCE_PROVIDER_V_PRIVATE_DATA_SIZE (6*1024)
#else
#define SOURCE_PROVIDER_V_PRIVATE_DATA_SIZE (4*1024)
#endif

// total size
#define SOURCE_PROVIDER_VIDEO_MEM (SOURCE_PROVIDER_V_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE + \
                                                                  SOURCE_PROVIDER_V_PRIVATE_DATA_SIZE)


/****************
  Total subtitle size of source
  1. buffer header
  2. private data
  ****************/
// buffer size
#ifdef __VIDEO_SUBTITLE_SUPPORT__
#define SOURCE_PROVIDER_S_BUF_HEADER_LEN (60)
#else
#define SOURCE_PROVIDER_S_BUF_HEADER_LEN (0)
#endif
#define SOURCE_PROVIDER_S_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE \
                ALIGN_X((SOURCE_PROVIDER_S_BUF_HEADER_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)

// private size
#ifdef __VIDEO_SUBTITLE_SUPPORT__
#define SOURCE_PROVIDER_S_PRIVATE_DATA_SIZE (2*1024)
#else
#define SOURCE_PROVIDER_S_PRIVATE_DATA_SIZE (0)
#endif

// total size
#define SOURCE_PROVIDER_SUBTITLE_MEM (SOURCE_PROVIDER_S_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE + \
                                                                  SOURCE_PROVIDER_S_PRIVATE_DATA_SIZE)


/****************
 * MP4 provider *
 ****************/
#if defined(__VE_MP43GP_FILE_FORMAT_SUPPORT__)

/* Core memory calculation. Name: Size of cache line aligned (original)
     sizeof(MP4_PROVIDER_CTRL_T):                               1760 (1752)
     sizeof(MP4_PROVIDER_TRACK_BUF_POOL_AUD_T):  4096
     sizeof(MP4_PROVIDER_TRACK_BUF_POOL_VID_T):   4672
     sizeof(MP4_PROVIDER_COMMON_BUF_POOL_T):    24576 (24568)
     sizeof(MP4_PROVIDER_USER_DATA_T):                     1312 (1296)
     sizeof(PU_VID_PARAM_SET_T):                                   32
     sizeof(SPIF_VIDEO_STREAM_INFO_T):                           64 (40)
     sizeof(SPIF_AUDIO_STREAM_INFO_T):                           64 (56)
     prVideoParamSetData->u4ParamSetTotalSize:               #1
     sizeof(H264_DECODER_PAYLOAD_INFO_T)*Payload Number #2
     Total: 36576 + #1 + #2 */

#ifdef __VE_H264_DEC_SUPPORT__
#define _MP4_SP_CORE_ME_H264 PROVIDER_UTILITY_MAX_PARAMSET_NUM*2*ALIGN_X(sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T), SP_CPU_CACHE_LINE_SIZE)
#else
#define _MP4_SP_CORE_ME_H264 0
#endif

#ifdef __VE_KMV_SUPPORT__
#define _MP4_SP_CORE_ME_KMV (ALIGN_X(sizeof(SPIF_KMV_DECODER_PAYLOAD_INFO_T), SP_CPU_CACHE_LINE_SIZE)+ALIGN_X(sizeof(MP4_PROVIDER_TRACK_BUF_POOL_KMV_T), SP_CPU_CACHE_LINE_SIZE))
#else
#define _MP4_SP_CORE_ME_KMV 0
#endif

#define _MP4_SP_CORE_MEMORY_REQUIREMENT (\
             ALIGN_X(sizeof(MP4_PROVIDER_CTRL_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(MP4_PROVIDER_TRACK_BUF_POOL_AUD_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(MP4_PROVIDER_TRACK_BUF_POOL_VID_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(MP4_PROVIDER_COMMON_BUF_POOL_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(MP4_PROVIDER_USER_DATA_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(PU_VID_PARAM_SET_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(UDTAInfo), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(SPIF_VIDEO_STREAM_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(SPIF_AUDIO_STREAM_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MP4_PROVIDER_PARAMSET_LENGTH, SP_CPU_CACHE_LINE_SIZE) + \
             _MP4_SP_CORE_ME_KMV+ _MP4_SP_CORE_ME_H264)

/*Current status-> subtitle is not supported in MP4 Provider*/
#define _MP4_SP_CORE_MEM_PGDL (\
             (SOURCE_PROVIDER_PORT_MAX-1)*ALIGN_X(sizeof(MP4_PROVIDER_TRACK_BUF_POOL_PDL_T), SP_CPU_CACHE_LINE_SIZE))

// 1. min value
#define MP4_SP_AUDIO_MEM_SIZE_MIN   (8*1024)
#define MP4_SP_VIDEO_MEM_SIZE_MIN  (50*1024)
#define MP4_SP_SUBTITLE_MEM_SIZE_MIN  (0)

// 2. default value
#if defined(__VE_PGDL_SUPPORT__)
    #define MP4_SP_CORE_MEM_SIZE   (_MP4_SP_CORE_MEMORY_REQUIREMENT + _MP4_SP_CORE_MEM_PGDL)
#else
    #define MP4_SP_CORE_MEM_SIZE   (_MP4_SP_CORE_MEMORY_REQUIREMENT)
#endif

#if defined(__VE_MED_VIDEO_ULC__)
    #define MP4_SP_AUDIO_MEM_SIZE  (24*1024)
    #define MP4_SP_AUDIO_WORKING_MEM_SIZE (0)
    #define MP4_SP_VIDEO_MEM_SIZE (120*1024)
    #define MP4_SP_VIDEO_WORKING_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_WORKING_MEM_SIZE (0)
#elif defined(__CONCURRENCY_VIDEO_TEST__)
    #define MP4_SP_AUDIO_MEM_SIZE  (24*1024)
    #define MP4_SP_AUDIO_WORKING_MEM_SIZE (0)
    #define MP4_SP_VIDEO_MEM_SIZE (200*1024)
    #define MP4_SP_VIDEO_WORKING_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_WORKING_MEM_SIZE (0)
#elif defined(__VE_SP_SLIM__)
    #define MP4_SP_AUDIO_MEM_SIZE  (24*1024)
    #define MP4_SP_AUDIO_WORKING_MEM_SIZE (0)
    #define MP4_SP_VIDEO_MEM_SIZE (200*1024)
    #define MP4_SP_VIDEO_WORKING_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_WORKING_MEM_SIZE (0)
#else
    #define MP4_SP_AUDIO_MEM_SIZE   (64*1024)
    #define MP4_SP_AUDIO_WORKING_MEM_SIZE (0)
     #define MP4_SP_VIDEO_MEM_SIZE (620*1024)
    #define MP4_SP_VIDEO_WORKING_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_MEM_SIZE (0)
    #define MP4_SP_SUBTITLE_WORKING_MEM_SIZE (0)
#endif /* defined(__MP4_DEC_SW_SLIM__) || defined(__H264_DEC_SW_SLIM__) */

// 3. replace custom value
#ifdef MP4_BUFFER_CUSTOM_SETTING_ENABLE
    #ifdef MP4_CUSTOM_AUDIO_MEM_SIZE
        #undef MP4_SP_AUDIO_MEM_SIZE
        #define MP4_SP_AUDIO_MEM_SIZE (MP4_CUSTOM_AUDIO_MEM_SIZE)
    #endif
    #ifdef MP4_CUSTOM_VIDEO_MEM_SIZE
        #undef MP4_SP_VIDEO_MEM_SIZE
        #define MP4_SP_VIDEO_MEM_SIZE (MP4_CUSTOM_VIDEO_MEM_SIZE)
    #endif
#endif /* MP4_BUFFER_CUSTOM_SETTING_ENABLE */

// 4. checking
#if (MP4_SP_AUDIO_MEM_SIZE < MP4_SP_AUDIO_MEM_SIZE_MIN)
    #error "MP4 Error: MP4_SP_AUDIO_MEM_SIZE is smaller than MP4_SP_AUDIO_MEM_SIZE_MIN"
#endif
#if (MP4_SP_VIDEO_MEM_SIZE < MP4_SP_VIDEO_MEM_SIZE_MIN)
    #error "MP4 Error: MP4_SP_VIDEO_MEM_SIZE is smaller than MP4_SP_VIDEO_MEM_SIZE_MIN"
#endif
#if (MP4_SP_SUBTITLE_MEM_SIZE < MP4_SP_SUBTITLE_MEM_SIZE_MIN)
    #error "MP4 Error: MP4_SP_SUBTITLE_MEM_SIZE is smaller than MP4_SP_SUBTITLE_MEM_SIZE_MIN"
#endif

// 5. add source size
#define MP4_MP_CORE_MEM_SIZE_IF (MP4_SP_CORE_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define MP4_MP_AUDIO_MEM_SIZE_IF (MP4_SP_AUDIO_MEM_SIZE + MP4_SP_AUDIO_WORKING_MEM_SIZE + SOURCE_PROVIDER_AUDIO_MEM)
#define MP4_MP_VIDEO_MEM_SIZE_IF (MP4_SP_VIDEO_MEM_SIZE + MP4_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define MP4_MP_SUBTITLE_MEM_SIZE_IF (MP4_SP_SUBTITLE_MEM_SIZE + MP4_SP_SUBTITLE_WORKING_MEM_SIZE + SOURCE_PROVIDER_SUBTITLE_MEM)

// Preview
#define MP4_SP_CORE_PREVIEW_MEM_SIZE (MP4_SP_CORE_MEM_SIZE)
#define MP4_SP_AUDIO_PREVIEW_MEM_SIZE (0)
#define MP4_SP_VIDEO_PREVIEW_MEM_SIZE (MP4_SP_VIDEO_MEM_SIZE)
#define MP4_SP_SUBTITLE_PREVIEW_MEM_SIZE (0)

#define MP4_MP_CORE_PREVIEW_MEM_SIZE_IF  (MP4_SP_CORE_PREVIEW_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define MP4_MP_AUDIO_PREVIEW_MEM_SIZE_IF (MP4_SP_AUDIO_PREVIEW_MEM_SIZE)
#define MP4_MP_VIDEO_PREVIEW_MEM_SIZE_IF (MP4_SP_VIDEO_PREVIEW_MEM_SIZE + MP4_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define MP4_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF (MP4_SP_SUBTITLE_PREVIEW_MEM_SIZE)
#endif /* defined(__VE_MP43GP_FILE_FORMAT_SUPPORT__) */


/****************
 * AVI provider *
 ****************/
#if defined(__VE_SP_AVI__)
/* core common memory:
    1. context
    2. fsal work buffer (1024)
    3. fsal seek hint buffer (1023*8)
    4. temp buffer for parser (1024)
  */
#define AVI_SP_CORE_COMMON_SIZE (12*1024)
            //ALIGN_X(sizeof(AVI_SP_PROVIDER_CONTEXT_T), SP_CPU_CACHE_LINE_SIZE))// + \
            //ALIGN_X(AVI_SP_FASL_FILE_INFO_BUF, SP_CPU_CACHE_LINE_SIZE) + \
            //ALIGN_X((AVI_SP_FASL_SEEK_HINT_IDX * sizeof(FS_FileLocationHint)), SP_CPU_CACHE_LINE_SIZE) + \
            //ALIGN_X(AVI_SP_TEMP_BUF, SP_CPU_CACHE_LINE_SIZE))

/* core audio memory:
    1. fsal work buffer (1024)
    2. parser list buffer (60x16)
    3. Index buffer (8x1024)
  */
#define AVI_SP_CORE_AUDIO_SIZE (10*1024)
            //ALIGN_X(AVI_SP_FASL_INDEX_BUF, SP_CPU_CACHE_LINE_SIZE) + \
            //ALIGN_X((AVI_SP_AUDIO_LIST_ITEM_NUM*sizeof(AVI_SP_INDEX_T)), SP_CPU_CACHE_LINE_SIZE) + \
            //ALIGN_X((sizeof(AVI_SP_VBR_ENTRY_T)*AVI_SP_INDEX_MAX_ENTRIES), SP_CPU_CACHE_LINE_SIZE))

/* core video memory:
    1. fsal work buffer (1024)
    2. parser list buffer (60x16)
    3. Index buffer (8x1024)
  */
#define AVI_SP_CORE_VIDEO_SIZE (10*1024)
            //ALIGN_X(AVI_SP_FASL_INDEX_BUF, SP_CPU_CACHE_LINE_SIZE) + \
            //ALIGN_X((AVI_SP_VIDEO_LIST_ITEM_NUM*sizeof(AVI_SP_INDEX_T)), SP_CPU_CACHE_LINE_SIZE) + \
            //ALIGN_X((sizeof(AVI_SP_VBR_ENTRY_T)*AVI_SP_INDEX_MAX_ENTRIES), SP_CPU_CACHE_LINE_SIZE))

/* core subtitle memory:
  */
#define AVI_SP_CORE_SUBTITLE_SIZE (0)

// 1. min value
#define AVI_SP_CORE_MEM_SIZE_MIN   (10*1024)
#define AVI_SP_AUDIO_MEM_SIZE_MIN  (16*1024)
#define AVI_SP_VIDEO_MEM_SIZE_MIN  (50*1024)
#define AVI_SP_SUBTITLE_MEM_SIZE_MIN  (0)

// 2. default value
#define AVI_SP_CORE_MEM_SIZE   (AVI_SP_CORE_COMMON_SIZE)

#if defined(__VE_MED_VIDEO_ULC__)
    #define AVI_SP_AUDIO_MEM_SIZE  (24*1024)
    #define AVI_SP_AUDIO_WORKING_MEM_SIZE (AVI_SP_CORE_AUDIO_SIZE)
    #define AVI_SP_VIDEO_MEM_SIZE  (120*1024)
    #define AVI_SP_VIDEO_WORKING_MEM_SIZE (AVI_SP_CORE_VIDEO_SIZE)
    #define AVI_SP_SUBTITLE_MEM_SIZE (0)
    #define AVI_SP_SUBTITLE_WORKING_MEM_SIZE (AVI_SP_CORE_SUBTITLE_SIZE)
#elif defined(__CONCURRENCY_VIDEO_TEST__)
    #define AVI_SP_AUDIO_MEM_SIZE  (24*1024)
    #define AVI_SP_AUDIO_WORKING_MEM_SIZE (AVI_SP_CORE_AUDIO_SIZE)
    #define AVI_SP_VIDEO_MEM_SIZE (194*1024)
    #define AVI_SP_VIDEO_WORKING_MEM_SIZE (AVI_SP_CORE_VIDEO_SIZE)
    #define AVI_SP_SUBTITLE_MEM_SIZE (0)
    #define AVI_SP_SUBTITLE_WORKING_MEM_SIZE (AVI_SP_CORE_SUBTITLE_SIZE)
#elif defined(__VE_SP_SLIM__)
    #define AVI_SP_AUDIO_MEM_SIZE  (24*1024)
    #define AVI_SP_AUDIO_WORKING_MEM_SIZE (AVI_SP_CORE_AUDIO_SIZE)
    #define AVI_SP_VIDEO_MEM_SIZE (194*1024)
    #define AVI_SP_VIDEO_WORKING_MEM_SIZE (AVI_SP_CORE_VIDEO_SIZE)
    #define AVI_SP_SUBTITLE_MEM_SIZE (0)
    #define AVI_SP_SUBTITLE_WORKING_MEM_SIZE (AVI_SP_CORE_SUBTITLE_SIZE)
#else
    #define AVI_SP_AUDIO_MEM_SIZE  (64*1024)
    #define AVI_SP_AUDIO_WORKING_MEM_SIZE (AVI_SP_CORE_AUDIO_SIZE)
    #define AVI_SP_VIDEO_MEM_SIZE (634*1024)
    #define AVI_SP_VIDEO_WORKING_MEM_SIZE (AVI_SP_CORE_VIDEO_SIZE)
    #define AVI_SP_SUBTITLE_MEM_SIZE (0)
    #define AVI_SP_SUBTITLE_WORKING_MEM_SIZE (AVI_SP_CORE_SUBTITLE_SIZE)
#endif /* defined(__MP4_DEC_SW_SLIM__) || defined(__H264_DEC_SW_SLIM__) */


// 3. replace custom value
#ifdef AVI_BUFFER_CUSTOM_SETTING_ENABLE
    #ifdef AVI_CUSTOM_AUDIO_MEM_SIZE
        #undef AVI_SP_AUDIO_MEM_SIZE
        #define AVI_SP_AUDIO_MEM_SIZE (AVI_CUSTOM_AUDIO_MEM_SIZE)
    #endif
    #ifdef AVI_CUSTOM_VIDEO_MEM_SIZE
        #undef AVI_SP_VIDEO_MEM_SIZE
        #define AVI_SP_VIDEO_MEM_SIZE (AVI_CUSTOM_VIDEO_MEM_SIZE)
    #endif
#endif /* AVI_BUFFER_CUSTOM_SETTING_ENABLE */

// 4. checking
#if (AVI_SP_CORE_MEM_SIZE < AVI_SP_CORE_MEM_SIZE_MIN)
    #error "AVI Error: AVI_SP_CORE_MEM_SIZE is smaller than AVI_SP_CORE_MEM_SIZE_MIN"
#endif
#if (AVI_SP_AUDIO_MEM_SIZE < AVI_SP_AUDIO_MEM_SIZE_MIN)
    #error "AVI Error: AVI_SP_AUDIO_MEM_SIZE is smaller than AVI_SP_AUDIO_MEM_SIZE_MIN"
#endif
#if (AVI_SP_VIDEO_MEM_SIZE < AVI_SP_VIDEO_MEM_SIZE_MIN)
    #error "AVI Error: AVI_SP_VIDEO_MEM_SIZE is smaller than AVI_SP_VIDEO_MEM_SIZE_MIN"
#endif
#if (AVI_SP_SUBTITLE_MEM_SIZE < AVI_SP_SUBTITLE_MEM_SIZE_MIN)
    #error "AVI Error: AVI_SP_SUBTITLE_MEM_SIZE is smaller than AVI_SP_SUBTITLE_MEM_SIZE_MIN"
#endif


// 5. add source size
#define AVI_MP_CORE_MEM_SIZE_IF (AVI_SP_CORE_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define AVI_MP_AUDIO_MEM_SIZE_IF (AVI_SP_AUDIO_MEM_SIZE + AVI_SP_AUDIO_WORKING_MEM_SIZE + SOURCE_PROVIDER_AUDIO_MEM)
#define AVI_MP_VIDEO_MEM_SIZE_IF (AVI_SP_VIDEO_MEM_SIZE + AVI_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define AVI_MP_SUBTITLE_MEM_SIZE_IF (AVI_SP_SUBTITLE_MEM_SIZE + AVI_SP_SUBTITLE_WORKING_MEM_SIZE + SOURCE_PROVIDER_SUBTITLE_MEM)

// Preview
#define AVI_SP_CORE_PREVIEW_MEM_SIZE  (AVI_SP_CORE_MEM_SIZE)
#define AVI_SP_AUDIO_PREVIEW_MEM_SIZE (0)
#define AVI_SP_VIDEO_PREVIEW_MEM_SIZE (AVI_SP_VIDEO_MEM_SIZE)
#define AVI_SP_SUBTITLE_PREVIEW_MEM_SIZE (0)

#define AVI_MP_CORE_PREVIEW_MEM_SIZE_IF  (AVI_SP_CORE_PREVIEW_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define AVI_MP_AUDIO_PREVIEW_MEM_SIZE_IF (AVI_SP_AUDIO_PREVIEW_MEM_SIZE)
#define AVI_MP_VIDEO_PREVIEW_MEM_SIZE_IF (AVI_SP_VIDEO_PREVIEW_MEM_SIZE + AVI_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define AVI_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF (AVI_SP_SUBTITLE_PREVIEW_MEM_SIZE)
#endif /* defined(__VE_SP_AVI__) */


/****************
 * RM  provider *
 ****************/
#if defined(__VE_SP_RM__)
// 1. min value
#define RM_SP_CORE_MEM_SIZE_MIN   (60*1024)
#define RM_SP_AUDIO_MEM_SIZE_MIN (128*1024)
#define RM_SP_VIDEO_MEM_SIZE_MIN (256*1024)
#define RM_SP_SUBTITLE_MEM_SIZE_MIN (0)

// 2. default value
#if defined(__VE_SP_SLIM__)
    #define RM_SP_CORE_MEM_SIZE  ( 60 * 1024)
    #define RM_SP_AUDIO_MEM_SIZE (128 * 1024)
    #define RM_SP_AUDIO_WORKING_MEM_SIZE (0)
    #define RM_SP_VIDEO_MEM_SIZE (256 * 1024)
    #define RM_SP_VIDEO_WORKING_MEM_SIZE (0)
    #define RM_SP_SUBTITLE_MEM_SIZE (0)
    #define RM_SP_SUBTITLE_WORKING_MEM_SIZE (0)
#else
    #define RM_SP_CORE_MEM_SIZE  (424 * 1024)  //( 96 * 1024)
    #define RM_SP_AUDIO_MEM_SIZE (128 * 1024)  //(192 * 1024)
    #define RM_SP_AUDIO_WORKING_MEM_SIZE (0)
    #define RM_SP_VIDEO_MEM_SIZE (440 * 1024)  //(704 * 1024)
    #define RM_SP_VIDEO_WORKING_MEM_SIZE (0)
    #define RM_SP_SUBTITLE_MEM_SIZE (0)
    #define RM_SP_SUBTITLE_WORKING_MEM_SIZE (0)
#endif

// 3. replace custom value
#ifdef RM_BUFFER_CUSTOM_SETTING_ENABLE
    #ifdef RM_CUSTOM_AUDIO_MEM_SIZE
        #undef RM_SP_AUDIO_MEM_SIZE
        #define RM_SP_AUDIO_MEM_SIZE (RM_CUSTOM_AUDIO_MEM_SIZE)
    #endif
    #ifdef RM_CUSTOM_VIDEO_MEM_SIZE
        #undef RM_SP_VIDEO_MEM_SIZE
        #define RM_SP_VIDEO_MEM_SIZE (RM_CUSTOM_VIDEO_MEM_SIZE)
    #endif
#endif /* RM_BUFFER_CUSTOM_SETTING_ENABLE */

// 4. checking
#if (RM_SP_CORE_MEM_SIZE < RM_SP_CORE_MEM_SIZE_MIN)
    #error "RM Error: RM_SP_CORE_MEM_SIZE is smaller than RM_SP_CORE_MEM_SIZE_MIN"
#endif
#if (RM_SP_AUDIO_MEM_SIZE < RM_SP_AUDIO_MEM_SIZE_MIN)
    #error "RM Error: RM_SP_AUDIO_MEM_SIZE is smaller than RM_SP_AUDIO_MEM_SIZE_MIN"
#endif
#if (RM_SP_VIDEO_MEM_SIZE < RM_SP_VIDEO_MEM_SIZE_MIN)
    #error "RM Error: RM_SP_VIDEO_MEM_SIZE is smaller than RM_SP_VIDEO_MEM_SIZE_MIN"
#endif
#if (RM_SP_SUBTITLE_MEM_SIZE < RM_SP_SUBTITLE_MEM_SIZE_MIN)
    #error "RM Error: RM_SP_SUBTITLE_MEM_SIZE is smaller than RM_SP_SUBTITLE_MEM_SIZE_MIN"
#endif

// 5. add source size
#define RM_MP_CORE_MEM_SIZE_IF (RM_SP_CORE_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define RM_MP_AUDIO_MEM_SIZE_IF (RM_SP_AUDIO_MEM_SIZE + RM_SP_AUDIO_WORKING_MEM_SIZE + SOURCE_PROVIDER_AUDIO_MEM)
#define RM_MP_VIDEO_MEM_SIZE_IF (RM_SP_VIDEO_MEM_SIZE + RM_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define RM_MP_SUBTITLE_MEM_SIZE_IF (RM_SP_VIDEO_MEM_SIZE + RM_SP_SUBTITLE_WORKING_MEM_SIZE + SOURCE_PROVIDER_SUBTITLE_MEM)

// Preview
#define RM_SP_CORE_PREVIEW_MEM_SIZE  (RM_SP_CORE_MEM_SIZE)
#define RM_SP_AUDIO_PREVIEW_MEM_SIZE (0)
#define RM_SP_VIDEO_PREVIEW_MEM_SIZE (RM_SP_VIDEO_MEM_SIZE)
#define RM_SP_SUBTITLE_PREVIEW_MEM_SIZE (0)

#define RM_MP_CORE_PREVIEW_MEM_SIZE_IF  (RM_SP_CORE_PREVIEW_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define RM_MP_AUDIO_PREVIEW_MEM_SIZE_IF (RM_SP_AUDIO_PREVIEW_MEM_SIZE)
#define RM_MP_VIDEO_PREVIEW_MEM_SIZE_IF (RM_SP_VIDEO_PREVIEW_MEM_SIZE + RM_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define RM_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF (RM_SP_SUBTITLE_PREVIEW_MEM_SIZE)
#endif /* defined(__RM_DEC_SUPPORT__) */


/****************
 * FLV provider *
 ****************/
#if defined(__VE_FLV_FILE_FORMAT_SUPPORT__)

/* Core memory calculation. Name: Size of cache line aligned (original)
     sizeof(FLV_PROVIDER_CTRL_T):                                3328 (3320)
     sizeof(flv_mp_track_buf_pool_vid):                           1152
     sizeof(FLVMetaData):                                                4608 (4580)
     sizeof(flv_mp_common_buf_pool):                         17472 (17464)
     sizeof(PU_VID_PARAM_SET_T):                         32
     sizeof(FLVParser): Audio:                                              32 (24)
     sizeof(FLVParser): Video                                               32 (24)
     sizeof(SPIF_VIDEO_STREAM_INFO_T):                          64 (40)
     sizeof(SPIF_AUDIO_STREAM_INFO_T):                          64 (56)
     u4ParamSetTotalSize:                                                           #1
     sizeof(H264_DECODER_PAYLOAD_INFO_T)*Payload Number #2
     Total: 27936 + #1 + #2 */

#define _FLV_SP_CORE_MEMORY_REQUIREMENT (\
             ALIGN_X(sizeof(FLV_PROVIDER_CTRL_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(flv_mp_track_buf_pool_vid), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(FLVMetaData), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(flv_mp_common_buf_pool), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(FLVParser), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(SPIF_AUDIO_STREAM_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(SPIF_VIDEO_STREAM_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
             SOURCE_PROVIDER_ADM_SIZE \
             )

#define _FLV_SP_AUDIO_WORKING_MEMORY (\
         ALIGN_X(sizeof(flv_mp_track_buf_pool_aud), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(FLVParser), SP_CPU_CACHE_LINE_SIZE) \
         )

#define _FLV_SP_VIDEO_WORKING_MEMORY (\
        ALIGN_X(sizeof(PU_VID_PARAM_SET_T), SP_CPU_CACHE_LINE_SIZE) + \
        ALIGN_X(FLV_MP_PARAMSET_LENGTH, SP_CPU_CACHE_LINE_SIZE) + \
        ALIGN_X(PROVIDER_UTILITY_MAX_PARAMSET_NUM*2*sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T), SP_CPU_CACHE_LINE_SIZE) \
        )

// 1. min value
#define FLV_SP_AUDIO_MEM_SIZE_MIN   (8*1024)
#define FLV_SP_VIDEO_MEM_SIZE_MIN  (50*1024)
#define FLV_SP_SUBTITLE_MEM_SIZE_MIN  (0)

// 2. default value
#define FLV_SP_CORE_MEM_SIZE   _FLV_SP_CORE_MEMORY_REQUIREMENT
#define FLV_SP_AUDIO_MEM_SIZE   (40*1024)
#define FLV_SP_AUDIO_WORKING_MEM_SIZE _FLV_SP_AUDIO_WORKING_MEMORY
#define FLV_SP_VIDEO_MEM_SIZE (640*1024)
#define FLV_SP_VIDEO_WORKING_MEM_SIZE _FLV_SP_VIDEO_WORKING_MEMORY
#define FLV_SP_SUBTITLE_MEM_SIZE (0)
#define FLV_SP_SUBTITLE_WORKING_MEM_SIZE (0)

// 3. replace custom value
#if 0 //def FLV_BUFFER_CUSTOM_SETTING_ENABLE
    #ifdef FLV_CUSTOM_AUDIO_MEM_SIZE
/* under construction !*/
/* under construction !*/
    #endif
    #ifdef FLV_CUSTOM_VIDEO_MEM_SIZE
/* under construction !*/
/* under construction !*/
    #endif
#endif /* FLV_BUFFER_CUSTOM_SETTING_ENABLE */

// 4. checking
#if (FLV_SP_AUDIO_MEM_SIZE < FLV_SP_AUDIO_MEM_SIZE_MIN)
    #error "FLV Error: FLV_SP_AUDIO_MEM_SIZE is smaller than FLV_SP_AUDIO_MEM_SIZE_MIN"
#endif
#if (FLV_SP_VIDEO_MEM_SIZE < FLV_SP_VIDEO_MEM_SIZE_MIN)
    #error "FLV Error: FLV_SP_VIDEO_MEM_SIZE is smaller than FLV_SP_VIDEO_MEM_SIZE_MIN"
#endif
#if (FLV_SP_SUBTITLE_MEM_SIZE < FLV_SP_SUBTITLE_MEM_SIZE_MIN)
    #error "FLV Error: FLV_SP_SUBTITLE_MEM_SIZE is smaller than FLV_SP_SUBTITLE_MEM_SIZE_MIN"
#endif


// 5. add source size
#define FLV_MP_CORE_MEM_SIZE_IF (FLV_SP_CORE_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define FLV_MP_AUDIO_MEM_SIZE_IF (FLV_SP_AUDIO_MEM_SIZE + FLV_SP_AUDIO_WORKING_MEM_SIZE + SOURCE_PROVIDER_AUDIO_MEM)
#define FLV_MP_VIDEO_MEM_SIZE_IF (FLV_SP_VIDEO_MEM_SIZE + FLV_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define FLV_MP_SUBTITLE_MEM_SIZE_IF (FLV_SP_VIDEO_MEM_SIZE + FLV_SP_SUBTITLE_WORKING_MEM_SIZE + SOURCE_PROVIDER_SUBTITLE_MEM)

// Preview
#define FLV_SP_CORE_PREVIEW_MEM_SIZE  (FLV_SP_CORE_MEM_SIZE)
#define FLV_SP_AUDIO_PREVIEW_MEM_SIZE (0)
#define FLV_SP_VIDEO_PREVIEW_MEM_SIZE (FLV_SP_VIDEO_MEM_SIZE)
#define FLV_SP_SUBTITLE_PREVIEW_MEM_SIZE (0)

#define FLV_MP_CORE_PREVIEW_MEM_SIZE_IF  (FLV_SP_CORE_PREVIEW_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define FLV_MP_AUDIO_PREVIEW_MEM_SIZE_IF (FLV_SP_AUDIO_PREVIEW_MEM_SIZE)
#define FLV_MP_VIDEO_PREVIEW_MEM_SIZE_IF (FLV_SP_VIDEO_PREVIEW_MEM_SIZE + FLV_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define FLV_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF (FLV_SP_SUBTITLE_PREVIEW_MEM_SIZE)
#endif /* defined(__VE_FLV_FILE_FORMAT_SUPPORT__) */

/****************
 * MKV provider *
 ****************/
#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)

/* Core memory calculation. Name: Size of cache line aligned (original)
     sizeof(MKV_SP_PROVIDER_CONTEXT_T):                 224 (200)
     sizeof(SPIF_OPEN_INFO_T):                                     32 (32)
     sizeof(STFSAL)                                                        64 (64)
     MKV_CORE_FILE_BUFFER_SIZE                                2048 (2048)
     MKV_FILE_SEEK_HINT_SIZE * sizeof(FS_FileLocationHint)     8192 (8184)
     sizeof(mkv_parser)                                                 416 (408)
     SEEKHEAD_BUFFER_SIZE                                        256 (256)                                          1
     TRACKS_BUFFER_SIZE                                            10*1024 (10*1024)                            2
     MKV_SUPPORT_TRACK_NUM*sizeof(mkv_parser_track)     10*80 (10*80)                           
     MKV_SUPPORT_TRACK_NUM* MKV_TRACK_CODECID_MAXSIZE    10*32 (10*32)               
     MKV_SUPPORT_TRACK_NUM* MKV_TRACK_CODEC_PRIVATEDATA_MAXSIZE    10*2048 (10*2048) 
     MKV_SUPPORT_TRACK_NUM*sizeof(mkv_parser_track_video)     416 (10*20)         ;sizeof(mkv_parser_track_video)=20, sizeof(mkv_parser_track_audio)=16 
     SEGMENTINFO_BUFFER_SIZE                                   1024 (1024)                                       3
     sizeof(MKV_PROVIDER_INDEX_TABLE)                     4128 (4112)
     sizeof(MKV_PARSER_CLUSTERELEMENT_TABLE)        6176 (6160)
     MKV_SUPPORT_TRACK_NUM*sizeof(mkv_parser_track*)     64 (10*4)
     MKV_SUPPORT_TRACK_NUM*sizeof(SPIF_AUDIO_STREAM_INFO_T)  576(10*56)     ;sizeof(SPIF_VIDEO_STREAM_INFO_T)=40, sizeof(SPIF_AUDIO_STREAM_INFO_T)=56,  sizeof(SPIF_SUBTITLE_STREAM_INFO_T)=24  
     VIDEO: sizeof(SPIF_OPEN_INFO_T)                          32
     VIDEO: sizeof(STFSAL)                                           64
     MKV_VIDEO_FILE_BUFFER_SIZE                              8*1024 (8*1024)
     VIDEO: sizeof(mkv_parser_cluster)                          32
     sizeof(SPIF_PROVIDER_FRAME_INFO_T                     32     
     AUDIO: sizeof(SPIF_OPEN_INFO_T)                          32
     AUDIO: sizeof(STFSAL)                                           64
     MKV_AUDIO_FILE_BUFFER_SIZE                              5*1024 (5*1024)
     AUDIO: sizeof(mkv_parser_cluster)                          32     
     sizeof(SPIF_PROVIDER_FRAME_INFO_T                     32
     SUBTITLE: sizeof(SPIF_OPEN_INFO_T)                      32
     SUBTITLE: sizeof(STFSAL)                                        64
     MKV_SUBTITLE_FILE_BUFFER_SIZE                           5*1024 (5*1024)
     SUBTITLE: sizeof(mkv_parser_cluster)                      32     
     sizeof(SPIF_PROVIDER_FRAME_INFO_T)                    32
     VIDEO: sizeof(mkv_provider_codecinfo)                    32 (20)
     AUDIO: sizeof(mkv_provider_codecinfo)                    32 (20)     
     MKV_WORKING_MEMORY                                         1024

     Total: 27936 + #1 + #2 */

#define _MKV_SP_CORE_MEMORY_REQUIREMENT (\
             ALIGN_X(sizeof(MKV_SP_PROVIDER_CONTEXT_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(SPIF_OPEN_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(STFSAL), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_CORE_FILE_BUFFER_SIZE, SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_FILE_SEEK_HINT_SIZE * sizeof(FS_FileLocationHint), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(mkv_parser), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_SUPPORT_TRACK_NUM * sizeof(mkv_parser_track), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_SUPPORT_TRACK_NUM * MKV_TRACK_CODECID_MAXSIZE, SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_SUPPORT_TRACK_NUM * MKV_TRACK_CODEC_PRIVATEDATA_MAXSIZE, SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_SUPPORT_TRACK_NUM * sizeof(mkv_parser_track_video), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(MKV_PROVIDER_INDEX_TABLE), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(sizeof(MKV_PARSER_CLUSTERELEMENT_TABLE), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_SUPPORT_TRACK_NUM * sizeof(mkv_parser_track*), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_SUPPORT_TRACK_NUM * sizeof(SPIF_AUDIO_STREAM_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
             ALIGN_X(MKV_WORKING_MEMORY, SP_CPU_CACHE_LINE_SIZE) \
             )

#define _MKV_SP_VIDEO_WORKING_MEMORY (\
         ALIGN_X(sizeof(SPIF_OPEN_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(STFSAL), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(mkv_parser_cluster), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(MKV_VIDEO_FILE_BUFFER_SIZE, SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(SPIF_PROVIDER_FRAME_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(mkv_provider_codecinfo), SP_CPU_CACHE_LINE_SIZE) \
         )

#define _MKV_SP_AUDIO_WORKING_MEMORY (\
         ALIGN_X(sizeof(SPIF_OPEN_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(STFSAL), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(mkv_parser_cluster), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(MKV_AUDIO_FILE_BUFFER_SIZE, SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(SPIF_PROVIDER_FRAME_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(mkv_provider_codecinfo), SP_CPU_CACHE_LINE_SIZE) \
         )

#define _MKV_SP_SUBTITLE_WORKING_MEMORY (\
         ALIGN_X(sizeof(SPIF_OPEN_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(STFSAL), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(mkv_parser_cluster), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(MKV_SUBTITLE_FILE_BUFFER_SIZE, SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(SPIF_PROVIDER_FRAME_INFO_T), SP_CPU_CACHE_LINE_SIZE) + \
         ALIGN_X(sizeof(mkv_provider_codecinfo), SP_CPU_CACHE_LINE_SIZE) \
             )           

// 1. min value
#define MKV_SP_CORE_MEM_SIZE_MIN   (48*1024)
#define MKV_SP_AUDIO_MEM_SIZE_MIN  (16*1024)
#define MKV_SP_VIDEO_MEM_SIZE_MIN  (50*1024)
#ifdef __VIDEO_SUBTITLE_SUPPORT__
#define MKV_SP_SUBTITLE_MEM_SIZE_MIN  (8*1024)
#else
#define MKV_SP_SUBTITLE_MEM_SIZE_MIN  (0)
#endif

// 2. default value
#define MKV_SP_CORE_MEM_SIZE   _MKV_SP_CORE_MEMORY_REQUIREMENT
#define MKV_SP_VIDEO_WORKING_MEM_SIZE _MKV_SP_VIDEO_WORKING_MEMORY
#define MKV_SP_AUDIO_WORKING_MEM_SIZE _MKV_SP_AUDIO_WORKING_MEMORY
#define MKV_SP_SUBTITLE_WORKING_MEM_SIZE _MKV_SP_SUBTITLE_WORKING_MEMORY

#if defined(__CONCURRENCY_VIDEO_TEST__)
    #define MKV_SP_AUDIO_MEM_SIZE  (24*1024)
    #define MKV_SP_VIDEO_MEM_SIZE (194*1024)
    #ifdef __VIDEO_SUBTITLE_SUPPORT__
    #define MKV_SP_SUBTITLE_MEM_SIZE (8*1024)
    #else
    #define MKV_SP_SUBTITLE_MEM_SIZE (0)
    #endif
#elif defined(__VE_SP_SLIM__)
    #define MKV_SP_AUDIO_MEM_SIZE  (24*1024)
    #define MKV_SP_VIDEO_MEM_SIZE (194*1024)
    #ifdef __VIDEO_SUBTITLE_SUPPORT__
    #define MKV_SP_SUBTITLE_MEM_SIZE (8*1024)
    #else
    #define MKV_SP_SUBTITLE_MEM_SIZE (0)
    #endif
#else
    #define MKV_SP_AUDIO_MEM_SIZE  (64*1024)
    #define MKV_SP_VIDEO_MEM_SIZE (634*1024)
    #ifdef __VIDEO_SUBTITLE_SUPPORT__
    #define MKV_SP_SUBTITLE_MEM_SIZE (8*1024)
    #else
    #define MKV_SP_SUBTITLE_MEM_SIZE (0)
    #endif
#endif /* defined(__MP4_DEC_SW_SLIM__) || defined(__H264_DEC_SW_SLIM__) */


// 3. replace custom value
#ifdef MKV_BUFFER_CUSTOM_SETTING_ENABLE
    #ifdef MKV_CUSTOM_AUDIO_MEM_SIZE
        #undef MKV_SP_AUDIO_MEM_SIZE
        #define MKV_SP_AUDIO_MEM_SIZE (MKV_CUSTOM_AUDIO_MEM_SIZE)
    #endif
    #ifdef MKV_CUSTOM_VIDEO_MEM_SIZE
        #undef MKV_SP_VIDEO_MEM_SIZE
        #define MKV_SP_VIDEO_MEM_SIZE (MKV_CUSTOM_VIDEO_MEM_SIZE)
    #endif
#endif /* MKV_BUFFER_CUSTOM_SETTING_ENABLE */

// 4. checking
#if (MKV_SP_AUDIO_MEM_SIZE < MKV_SP_AUDIO_MEM_SIZE_MIN)
    #error "MKV Error: MKV_SP_AUDIO_MEM_SIZE is smaller than MKV_SP_AUDIO_MEM_SIZE_MIN"
#endif
#if (MKV_SP_VIDEO_MEM_SIZE < MKV_SP_VIDEO_MEM_SIZE_MIN)
    #error "MKV Error: MKV_SP_VIDEO_MEM_SIZE is smaller than MKV_SP_VIDEO_MEM_SIZE_MIN"
#endif
#if (MKV_SP_SUBTITLE_MEM_SIZE < MKV_SP_SUBTITLE_MEM_SIZE_MIN)
    #error "MKV Error: MKV_SP_SUBTITLE_MEM_SIZE is smaller than MKV_SP_SUBTITLE_MEM_SIZE_MIN"
#endif


// 5. add source size
#define MKV_MP_CORE_MEM_SIZE_IF (MKV_SP_CORE_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define MKV_MP_AUDIO_MEM_SIZE_IF (MKV_SP_AUDIO_MEM_SIZE + MKV_SP_AUDIO_WORKING_MEM_SIZE + SOURCE_PROVIDER_AUDIO_MEM)
#define MKV_MP_VIDEO_MEM_SIZE_IF (MKV_SP_VIDEO_MEM_SIZE + MKV_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define MKV_MP_SUBTITLE_MEM_SIZE_IF (MKV_SP_SUBTITLE_MEM_SIZE + MKV_SP_SUBTITLE_WORKING_MEM_SIZE + SOURCE_PROVIDER_SUBTITLE_MEM)

// Preview
#define MKV_SP_CORE_PREVIEW_MEM_SIZE  (MKV_SP_CORE_MEM_SIZE)
#define MKV_SP_AUDIO_PREVIEW_MEM_SIZE (0)
#define MKV_SP_VIDEO_PREVIEW_MEM_SIZE (MKV_SP_VIDEO_MEM_SIZE)
#define MKV_SP_SUBTITLE_PREVIEW_MEM_SIZE (0)

#define MKV_MP_CORE_PREVIEW_MEM_SIZE_IF  (MKV_SP_CORE_PREVIEW_MEM_SIZE + SOURCE_PROVIDER_CORE_MEM)
#define MKV_MP_AUDIO_PREVIEW_MEM_SIZE_IF (MKV_SP_AUDIO_PREVIEW_MEM_SIZE)
#define MKV_MP_VIDEO_PREVIEW_MEM_SIZE_IF (MKV_SP_VIDEO_PREVIEW_MEM_SIZE + MKV_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_VIDEO_MEM)
#define MKV_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF (MKV_SP_SUBTITLE_PREVIEW_MEM_SIZE)
#endif /* defined(__VE_MKV_FILE_FORMAT_SUPPORT__) */


/***********************
 * Streaming  provider *
 ***********************/
#if (defined(STREAM_SUPPORT) || defined(__MTV_SUPPORT__))
// component size   
#define SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_1_LEN (0)    
#define SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE \
                    ALIGN_X((SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_1_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)
    
#define SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_2_LEN (0)    
#define SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE \
                    ALIGN_X((SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_2_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)
    
#define SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_1_LEN (60)
#define SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE \
                    ALIGN_X((SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_1_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)
    
#define SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_2_LEN (60)
#define SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE \
                    ALIGN_X((SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_2_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)
    
        
#define SOURCE_PROVIDER_STREAMING_COMPONENT_SIZE (SOURCE_PROVIDER_CMD_Q_SIZE_ALIGN_CACHE_LINE + \
                                                                                                 SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE + \
                                                                                                 SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE +\
                                                                                                 SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_1_SIZE_ALIGN_CACHE_LINE + \
                                                                                                 SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_2_SIZE_ALIGN_CACHE_LINE + \
                                                                                                 SOURCE_PROVIDER_ADM_SIZE)
                                                                                    
// total size
#define SOURCE_PROVIDER_STREAMING_CORE_MEM (SOURCE_PROVIDER_CONTEXT_SIZE + \
                                                                                     SOURCE_PROVIDER_STREAMING_COMPONENT_SIZE +\
                                                                                     SOURCE_PROVIDER_ADM_SIZE)
                                                                    
/****************
  Total Audio size of source
  1. buffer header
  2. private data
  ****************/
// buffer size
#define SOURCE_PROVIDER_STREAMING_A_BUF_HEADER_LEN (768)
#define SOURCE_PROVIDER_STREAMING_A_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE \
                        ALIGN_X((SOURCE_PROVIDER_STREAMING_A_BUF_HEADER_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)
        
// private size
#define SOURCE_PROVIDER_STREAMING_A_PRIVATE_DATA_SIZE (0)
        
// total size
#define SOURCE_PROVIDER_STREAMING_AUDIO_MEM (SOURCE_PROVIDER_STREAMING_A_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE + \
                                                                                       SOURCE_PROVIDER_STREAMING_A_PRIVATE_DATA_SIZE)
    
    
/****************
  Total video size of source
  1. buffer header
  2. private data
  ****************/
// buffer size
#define SOURCE_PROVIDER_STREAMING_V_BUF_HEADER_LEN (384)
#define SOURCE_PROVIDER_STREAMING_V_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE \
                        ALIGN_X((SOURCE_PROVIDER_STREAMING_V_BUF_HEADER_LEN * SOURCE_PROVIDER_BUFFERHEADER_SIZE), SP_CPU_CACHE_LINE_SIZE)
    
// private size
#define SOURCE_PROVIDER_STREAMING_V_PRIVATE_DATA_SIZE (12*1024)
    
// total size
#define SOURCE_PROVIDER_STREAMING_VIDEO_MEM (SOURCE_PROVIDER_STREAMING_V_BUFFER_HEADER_SIZE_ALIGN_CACHE_LINE + \
                                                                                       SOURCE_PROVIDER_STREAMING_V_PRIVATE_DATA_SIZE)

/****************
  Total bitstream buffer  
  ****************/
// 1. min value
#define STREAMING_SP_CORE_MEM_SIZE_MIN   (0)
#define STREAMING_SP_AUDIO_MEM_SIZE_MIN  (96*1024)
#define STREAMING_SP_VIDEO_MEM_SIZE_MIN (464*1024)
#define STREAMING_SP_SUBTITLE_MEM_SIZE_MIN (0)

// 2. default value
#define STREAMING_SP_CORE_MEM_SIZE      ( 0)
#define STREAMING_SP_AUDIO_MEM_SIZE     (120 * 1024)
#define STREAMING_SP_AUDIO_WORKING_MEM_SIZE (0)
#define STREAMING_SP_VIDEO_MEM_SIZE     (678 * 1024)
#define STREAMING_SP_VIDEO_WORKING_MEM_SIZE (0)
#define STREAMING_SP_SUBTITLE_MEM_SIZE  (0)
#define STREAMING_SP_SUBTITLE_WORKING_MEM_SIZE (0)

// 3. replace custom value
#ifdef STREAMING_BUFFER_CUSTOM_SETTING_ENABLE
    #ifdef STREAMING_CUSTOM_AUDIO_MEM_SIZE
        #undef STREAMING_SP_AUDIO_MEM_SIZE
        #define STREAMING_SP_AUDIO_MEM_SIZE (STREAMING_CUSTOM_AUDIO_MEM_SIZE)
    #endif
    #ifdef STREAMING_CUSTOM_VIDEO_MEM_SIZE
        #undef STREAMING_SP_VIDEO_MEM_SIZE
        #define STREAMING_SP_VIDEO_MEM_SIZE (STREAMING_CUSTOM_VIDEO_MEM_SIZE)
    #endif
#endif /* STREAMING_BUFFER_CUSTOM_SETTING_ENABLE */

// 4. checking
#if (STREAMING_SP_CORE_MEM_SIZE < STREAMING_SP_CORE_MEM_SIZE_MIN)
    #error "STREAMING Error: STREAMING_SP_CORE_MEM_SIZE is smaller than STREAMING_SP_CORE_MEM_SIZE_MIN"
#endif
#if (STREAMING_SP_AUDIO_MEM_SIZE < STREAMING_SP_AUDIO_MEM_SIZE_MIN)
    #error "STREAMING Error: STREAMING_SP_AUDIO_MEM_SIZE is smaller than STREAMING_SP_AUDIO_MEM_SIZE_MIN"
#endif
#if (STREAMING_SP_VIDEO_MEM_SIZE < STREAMING_SP_VIDEO_MEM_SIZE_MIN)
    #error "STREAMING Error: STREAMING_SP_VIDEO_MEM_SIZE is smaller than STREAMING_SP_VIDEO_MEM_SIZE_MIN"
#endif
#if (STREAMING_SP_SUBTITLE_MEM_SIZE < STREAMING_SP_SUBTITLE_MEM_SIZE_MIN)
    #error "STREAMING Error: STREAMING_SP_SUBTITLE_MEM_SIZE is smaller than STREAMING_SP_SUBTITLE_MEM_SIZE_MIN"
#endif


// 5. add source size
#define STREAMING_MP_CORE_MEM_SIZE_IF (STREAMING_SP_CORE_MEM_SIZE + SOURCE_PROVIDER_STREAMING_CORE_MEM)
#define STREAMING_MP_AUDIO_MEM_SIZE_IF (STREAMING_SP_AUDIO_MEM_SIZE + STREAMING_SP_AUDIO_WORKING_MEM_SIZE + SOURCE_PROVIDER_STREAMING_AUDIO_MEM)
#define STREAMING_MP_VIDEO_MEM_SIZE_IF (STREAMING_SP_VIDEO_MEM_SIZE + STREAMING_SP_VIDEO_WORKING_MEM_SIZE + SOURCE_PROVIDER_STREAMING_VIDEO_MEM)
#define STREAMING_MP_SUBTITLE_MEM_SIZE_IF (STREAMING_SP_SUBTITLE_MEM_SIZE + STREAMING_SP_SUBTITLE_WORKING_MEM_SIZE)
#endif /* defined(__MED_STREAM_MOD__) */

#endif /* _MEDIA_PROVIDER_MEM_USE_INTERNAL_H */

