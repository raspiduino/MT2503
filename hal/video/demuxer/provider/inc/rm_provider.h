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
 *   rm_provider.c
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _RM_PROVIDER_H
#define _RM_PROVIDER_H

#include "drv_features_video.h"

#if defined(__VE_SP_RM__)

#include "source_provider_if.h"

#include "rm_parse.h"
#include "ra_depack.h"
#include "rv_depack.h"

//#define __RMP_SWLA__

#define RM_FASL_FILE_INFO_BUF (32)

#define RMFF_HEADER_TEST_LEN 16

#define RMMP_CORE_MIN_RESERVE_SIZE (248* 1024)
#define RMMP_CORE_FILE_BUFFER_SIZE (4 * 1024)
#define RMMP_VIDEO_FILE_BUFFER_SIZE (32 * 1024)
#define RMMP_AUDIO_FILE_BUFFER_SIZE (8 * 1024)
#define RMMP_FILE_SEEK_HINT_SIZE (2047)

#define RM_STREAM_INVALID_IDX        0xFFFF

#define GECKO_VERSION               ((1L<<24)|(0L<<16)|(0L<<8)|(3L))
#define GECKO_MC1_VERSION           ((2L<<24)|(0L<<16)|(0L<<8)|(0L))

typedef struct RMFF_PROP_T
{
    kal_uint32 num_packets;
    kal_uint32 duration;
    kal_uint16 num_streams;
}RMFF_PROP_T;

typedef struct
{
    /* from OpaqueData */
    kal_uint32 ulMajorBitstreamVersion;
    kal_uint32 ulMinorBitstreamVersion;

    kal_uint32 prp_size;
    kal_uint8* prp_data;

    void*      pCodecInitInfo;

} rv_dec_config_t;

typedef struct
{
    /* for ra8lbr(cook) only */
    kal_int32 nSamples;
    kal_int32 nRegions;
    kal_int32 delay;
    kal_int32 cplStart;
    kal_int32 cplQBits;

    void*      pCodecInitInfo;

} ra_dec_config_t;

typedef struct RMFF_MDPR_VIDEO_T
{
    SPIF_VIDEO_STREAM_INFO_T* video_stream_info;
    rv_format_info* video_opaque;
    rv_dec_config_t* dec_config;
    kal_bool fgSendHeader;
} RMFF_MDPR_VIDEO_T;

typedef struct RMFF_MDPR_AUDIO_T
{
    SPIF_AUDIO_STREAM_INFO_T* audio_stream_info;
    ra_format_info* audio_opaque;
    ra_dec_config_t* dec_config;
} RMFF_MDPR_AUDIO_T;

typedef struct SPIF_PROVIDER_FRAME_INFO_NODE_T
{
    SPIF_PROVIDER_FRAME_INFO_T* frame_info;  // video frame
    void* next;
}SPIF_PROVIDER_FRAME_INFO_NODE_T;

typedef void* (*PFN_RM_MEM_ALLOC_T) (kal_uint32 size);
typedef void (*PFN_RM_MEM_FREE_T) (void** mem_p);


typedef struct RM_SP_PROVIDER_CONTEXT_T
{
    PROVIDER_API_T* rRMProviderAPI;
    void * pvSourceHandle;
    SP_API_T* prSourceAPI;
    SP_TRACK_T eOpenTrack; 
    med_mode_enum eOpenType;

    kal_uint16 video_stream_count;
    kal_uint16 audio_stream_count;

    SPIF_OPEN_INFO_T* rm_file_handle;

    kal_bool fgTerminate;
    kal_bool fgAbort[SOURCE_PROVIDER_PORT_MAX];

    /* header */
    rm_parser* parser;
    RMFF_PROP_T* prProp;
    rm_stream_header** pprMdpr;

    RMFF_MDPR_VIDEO_T* video_info;
    RMFF_MDPR_AUDIO_T* audio_info;
    kal_mutexid rm_sdk_mutex;

    /* video */
    kal_uint16 video_stream_idx;        // stream index for media session (not stream number in MDPR)
    kal_uint16 video_stream_number;
    kal_uint32 video_start_time;  // millisecond
    kal_uint64 video_stop_time;
    SPIF_OPEN_INFO_T* rv_file_handle;
    rm_parser* video_parser;
    rv_depack* video_depack;
    rm_packet* video_packet;  // current video packet
    kal_uint32 u4VideoTimestamp;
    kal_bool fgvideoEOF;
    kal_uint32 u4NextVideoFrameLen;

    void* video_frame_q_start;
    void* video_frame_q_tail;
    kal_uint32 video_frame_q_count;



    /* audio */
    kal_uint16 audio_stream_idx;        // stream index for media session (not stream number in MDPR)
    kal_uint16 audio_stream_number;
    kal_uint32 audio_start_time;  // millisecond
    kal_uint64 audio_stop_time;
    SPIF_OPEN_INFO_T* ra_file_handle;
    rm_parser* audio_parser;
    ra_depack* audio_depack;
    rm_packet* audio_packet;  // current audio packet
    kal_uint32 u4AudioTimestamp;
    kal_bool fgaudioEOF;
    kal_uint32 u4NextAudioFrameLen;	

    void* audio_frame_q_start;
    void* audio_frame_q_tail;
    kal_uint32 audio_frame_q_count;

    /* debug */
    kal_uint32 video_packet_get;
    kal_uint32 audio_packet_get;
    kal_uint32 video_frame_deliver;
    kal_uint32 audio_frame_deliver;

    /* temp use for RM_GetContentDescInfo_EX*/
    PFN_RM_MEM_ALLOC_T ext_mem_alloc;
    PFN_RM_MEM_FREE_T ext_mem_free;

}RM_SP_PROVIDER_CONTEXT_T;

extern PROVIDER_ERROR_T RMProviderGetHandle(void *pvSrcHandle, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr);
extern PROVIDER_ERROR_T RMProviderReleaseHandle(void* pvHandle);
extern kal_bool RMProviderCheckIntegrity(kal_uint8* pBuf, kal_uint32 ulSize);


#ifdef __RMP_SWLA__
#define RMP_START_LOGGING(sym)  VIDEO_START_LOGGING(sym)
#define RMP_STOP_LOGGING(sym) VIDEO_STOP_LOGGING(sym)
#define RMP_LABEL_LOGGING(sym) VIDEO_LABEL_LOGGING(sym)
#else
#define RMP_START_LOGGING(sym)  do{}while(0);
#define RMP_STOP_LOGGING(sym) do{}while(0);
#define RMP_LABEL_LOGGING(sym) do{}while(0);
#endif

#endif //#if defined(__VE_SP_RM__)

#endif /* _RM_PROVIDER_H */
