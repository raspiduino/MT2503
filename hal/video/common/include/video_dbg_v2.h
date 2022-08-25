/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   video_buffer_management_v2.h
 *
 * Project:
 * --------
 *	MTK
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 ****************************************************************************/
#ifndef VIDEO_DBG_V2_H
#define VIDEO_DBG_V2_H

#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__


/* The following files are newly added for RHR. */
// #include "video_types_v2.h"
// #include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#ifdef __VE_SLIM_PROJECT__
#define MAX_VIDEO_DBG_ENTRY            64
#define MAX_VIDEO_ERROR_LINE           0
#else
#define MAX_VIDEO_DBG_ENTRY            256
#define MAX_VIDEO_ERROR_LINE           8
#endif


#if defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#define VIDEO_START_LOGGING(sym)  VideoStartLogging(sym)
#define VIDEO_STOP_LOGGING(sym) VideoStopLogging(sym)
#define VIDEO_LABEL_LOGGING(sym) VideoLabelLogging(sym)
#define VIDEO_WARNING(eOwner)  video_warning(eOwner, __LINE__);

typedef enum
{
    VIDEO_DBG_OWNER_FILEREADER,
    VIDEO_DBG_OWNER_FILEWRITER,
    VIDEO_DBG_OWNER_DECODER,
    VIDEO_DBG_OWNER_ENCODER,
    VIDEO_DBG_OWNER_DECSCHEDULER,
    VIDEO_DBG_OWNER_ENCSRC,
    VIDEO_DBG_OWNER_CONTROL,
    VIDEO_DBG_OWNER_RMPROVIDER
}VIDEO_DBG_OWNER_T;

typedef enum
{
    VIDEO_DBG_MIN = 0,

    VIDEO_DBG_FILEREADER_GET_NEXT_UNIT,
    VIDEO_DBG_FILEREADER_2,
    VIDEO_DBG_FILEREADER_3,

    VIDEO_DBG_DECODER_SEND_BUFFER,
    VIDEO_DBG_DECODER_SEND_TIME,
    VIDEO_DBG_DECODER_RETURN_BUFFER,
    VIDEO_DBG_DECODER_RETURN_TIME,
    VIDEO_DBG_DECODER_MPEG4ADPT_VOP_TYPE,
    VIDEO_DBG_DECODER_MPEG4ADPT_EOF,
    VIDEO_DBG_DECODER_MPEG4HWADPT_VOP_TYPE,
    VIDEO_DBG_DECODER_MPEG4HWADPT_INTERRUPT,
    VIDEO_DBG_DECODER_MPEG4HWADPT_TIMEOUT,
    VIDEO_DBG_DECODER_MPEG4HWADPT_DEC,
    VIDEO_DBG_DECODER_MPEG4HWADPT_YUV_CHECK,
    VIDEO_DBG_DECODER_MPEG4HWADPT_RET_BTM,
    VIDEO_DBG_DECODER_MPEG4HWADPT_OPEN,
    VIDEO_DBG_DECODER_MPEG4HWADPT_CLOSE,
    VIDEO_DBG_DECODER_MPEG4HWADPT_START,
    VIDEO_DBG_DECODER_MPEG4HWADPT_PARSE_HDR,
    VIDEO_DBG_DECODER_MPEG4HWADPT_COMPLETE,
    VIDEO_DBG_DECODER_MPEG4HWADPT_NEXT_DISP,
    VIDEO_DBG_DECODER_MPEG4HWADPT_INIT,
    VIDEO_DBG_DECODER_MPEG4HWADPT_DEINIT,
    VIDEO_DBG_DECODER_MPEG4HWADPT_EOF,
    VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK,
    VIDEO_DBG_DECODER_MPEG4HWADPT_ERR_CCL,
    VIDEO_DBG_DECODER_MPEG4HWADPT_ECL_DMA_LEFT,
    VIDEO_DBG_DECODER_MPEG4HWADPT_VLC_LIMIT,
    VIDEO_DBG_DECODER_MPEG4HWADPT_WARNING,
    VIDEO_DBG_DECODER_MPEG4HWADPT_VOP_HDR_ERR,
    VIDEO_DBG_DECODER_MPEG4HWADPT_SHR_HDR_ERR,
    VIDEO_DBG_DECODER_MPEG4HWADPT_SETPARAM,
    VIDEO_DBG_DECODER_MPEG4HWADPT_FLUSH,
    VIDEO_DBG_DECODER_MPEG4HWADPT_DECODE,
    VIDEO_DBG_DECODER_MPEG4HWADPT_REFERENCE,

    VIDEO_DBG_HWENCV2_OPEN,
    VIDEO_DBG_HWENCV2_INIT,
    VIDEO_DBG_HWENCV2_GEN_VOS,
    VIDEO_DBG_HWENCV2_ENCODEONEUNIT,
    VIDEO_DBG_HWENCV2_ENCODE,
    VIDEO_DBG_HWENCV2_START_ENC,
    VIDEO_DBG_HWENCV2_GET_PARAM,
    VIDEO_DBG_HWENCV2_SET_PARAM,
    VIDEO_DBG_HWENCV2_CLOSE,
    VIDEO_DBG_HWENCV2_ISR,
    VIDEO_DBG_HWENCV2_ISR_ERROR,
    VIDEO_DBG_HWENCV2_ENC_DONE,
    VIDEO_DBG_HWENCV2_ENC_DMA,
    VIDEO_DBG_HWENCV2_ENC_DROP,
    VIDEO_DBG_HWENCV2_ENC_RESUM_CONTI,
    VIDEO_DBG_HWENCV2_ENC_RESUM_NOT_CONTI,
    VIDEO_DBG_HWENCV2_TOTAL_ENCODE,
    VIDEO_DBG_MPEG4HW_RESOURCE_GET,
    VIDEO_DBG_MPEG4HW_RESOURCE_FREE,

    VIDEO_DBG_DECSCHEDULER_STATE_SET,
    VIDEO_DBG_DECSCHEDULER_START,
    VIDEO_DBG_DECSCHEDULER_COMPLETE,
    VIDEO_DBG_DECSCHEDULER_ENABLE,
    VIDEO_DBG_DECSCHEDULER_EMPTY,
    VIDEO_DBG_DECSCHEDULER_SETDURATION,    
    VIDEO_DBG_DECSCHEDULER_LISR_TIMEOUT,
    VIDEO_DBG_DECSCHEDULER_SENDTORENDER,    
    VIDEO_DBG_DECSCHEDULER_RENDERRETURN,    
    VIDEO_DBG_DECSCHEDULER_RECOVER0,
    VIDEO_DBG_DECSCHEDULER_RECOVER1,    
    VIDEO_DBG_DECSCHEDULER_GET_JUMPTIME,        

    VIDEO_DBG_CONTROL_INIT,
    VIDEO_DBG_CONTROL_SEEK,
    VIDEO_DBG_CONTROL_PLAY,
    VIDEO_DBG_CONTROL_RECOVER,
    VIDEO_DBG_CONTROL_STOP,
    VIDEO_DBG_CONTROL_CLOSE,
    VIDEO_DBG_CONTROL_DECODER_WAITBUFFER,
    VIDEO_DBG_CONTROL_CLOCK_START,

    VIDEO_DBG_ENCSRC_IDP_GET_BUFFER,
    VIDEO_DBG_ENCSRC_IDP_RETURN_BUFFER,
    VIDEO_DBG_ENCSRC_ENCODER_GET_BUFFER,
    VIDEO_DBG_ENCSRC_ENCODER_RETURN_BUFFER,
    VIDEO_DBG_ENCSRC_SET_STATE,

    VIDEO_DBG_MP4PVDR_SET_PARAM,
    VIDEO_DBG_MP4PVDR_GET_PARAM,
    VIDEO_DBG_MP4PVDR_INIT,
    VIDEO_DBG_MP4PVDR_DEINIT,
    VIDEO_DBG_MP4PVDR_OPEN,
    VIDEO_DBG_MP4PVDR_CLOSE,
    VIDEO_DBG_MP4PVDR_GET_HANDLE,
    VIDEO_DBG_MP4PVDR_REL_HANDLE,

    VIDEO_DBG_FLVPVDR_OPEN,
    VIDEO_DBG_FLVPVDR_INIT,
    VIDEO_DBG_FLVPVDR_DEINIT,
    VIDEO_DBG_FLVPVDR_SET_PARAM,
    VIDEO_DBG_FLVPVDR_GET_PARAM,
    VIDEO_DBG_FLVPVDR_FAST_BREAK,

    VIDEO_DBG_RMPROVIDER_DELIVER_VIDEO,
    VIDEO_DBG_RMPROVIDER_DELIVER_AUDIO,
    VIDEO_DBG_RMPROVIDER_DELIVER_KEY_FRAME,
    VIDEO_DBG_RMPROVIDER_SET_VIDEO_SEEKTIME,
    VIDEO_DBG_RMPROVIDER_SET_AUDIO_SEEKTIME,
    VIDEO_DBG_RMPROVIDER_PARSE_VIDEO,
    VIDEO_DBG_RMPROVIDER_PARSE_AUDIO,
    VIDEO_DBG_RMPROVIDER_QUERYTIME,
    VIDEO_DBG_RMPROVIDER_KEYFRAMETIME,
    VIDEO_DBG_RMPROVIDER_VIDEOEOF,
    VIDEO_DBG_RMPROVIDER_AUDIOEOF,
    VIDEO_DBG_RMPROVIDER_ERROR_LINE,
    VIDEO_DBG_RMPROVIDER_ERROR_INFO,
    VIDEO_DBG_RMPROVIDER_ALLOCMEM_FAIL,
    VIDEO_DBG_RMPROVIDER_WAIT_REASOURCE,

    VIDEO_DBG_MKVPROVIDER_DELIVER_VIDEO,
    VIDEO_DBG_MKVPROVIDER_DELIVER_AUDIO,
    VIDEO_DBG_MKVPROVIDER_DELIVER_SUBTITLE,    
    VIDEO_DBG_MKVPROVIDER_PARSE_VIDEO,
    VIDEO_DBG_MKVPROVIDER_PARSE_AUDIO,
    VIDEO_DBG_MKVPROVIDER_PARSE_SUBTITLE,    
    VIDEO_DBG_MKVPROVIDER_ERROR_LINE,
    VIDEO_DBG_MKVPROVIDER_ERROR_INFO,
    VIDEO_DBG_MKVPROVIDER_WAIT_BITSTREAM,
    VIDEO_DBG_MKVPROVIDER_WAIT_BUFFERHEADER,    
    VIDEO_DBG_MKVPROVIDER_QUERYTIME,
    VIDEO_DBG_MKVPROVIDER_KEYFRAMETIME,
    VIDEO_DBG_MKVPROVIDER_SET_VIDEO_SEEKTIME,
    VIDEO_DBG_MKVPROVIDER_SET_AUDIO_SEEKTIME,
    VIDEO_DBG_MKVPROVIDER_SET_SUBTITLE_SEEKTIME,
    VIDEO_DBG_MKVPROVIDER_EOF,    
    VIDEO_DBG_MKVPROVIDER_MSG, 

    VIDEO_DBG_MKVPARSER_CLUSTERITEM_ADD,
    VIDEO_DBG_MKVPARSER_CLUSTERITEM_REMOVE,
    VIDEO_DBG_MKVPARSER_CLUSTERITEM_REMOVE1,
    VIDEO_DBG_MKVPARSER_CLUSTERITEM_BINGO,
    VIDEO_DBG_MKVPARSER_CLUSTERITEM_FLY,    
		
    VIDEO_DBG_MAX
}VIDEO_DBG_ID_T;

typedef struct
{
    VIDEO_DBG_ID_T eTag;
    kal_uint16 u2Index;
    kal_uint32 u4Param;
}VIDEO_DBG_DATA_T;

typedef struct
{
    VIDEO_DBG_DATA_T arDbgData[MAX_VIDEO_DBG_ENTRY];
    kal_uint32 u4DbgIndex;
}VIDEO_DBG_STRUCT_T;

typedef struct
{
#ifndef __VE_SLIM_PROJECT__
    VIDEO_DBG_STRUCT_T rCtrlFileDbg;
    VIDEO_DBG_STRUCT_T rCodecDbg;
#endif	
    VIDEO_DBG_STRUCT_T rSchClkSrcDbg;
    kal_uint16 u2Index;
}VIDEO_DBG_ARRAY_T;

#ifndef __VE_SLIM_PROJECT__
typedef struct
{
    kal_uint32 au4ErrorLine[MAX_VIDEO_ERROR_LINE];
    kal_uint32 u4ErrorIndex;
}VIDEO_ERROR_STRUCT_T;

typedef struct
{
    VIDEO_ERROR_STRUCT_T rFileError;
    VIDEO_ERROR_STRUCT_T rCodecError;
    VIDEO_ERROR_STRUCT_T rSchedulerError;
    VIDEO_ERROR_STRUCT_T rClockError;
    VIDEO_ERROR_STRUCT_T rEncSrcError;
    VIDEO_ERROR_STRUCT_T rControlError;
}VIDEO_ERROR_ARRAY_T;
#endif

#ifndef __VE_SLIM_PROJECT__
extern void video_warning(VIDEO_DBG_OWNER_T eOwner, kal_uint32 u4Line);
#endif

extern void video_dbg_trace(VIDEO_DBG_OWNER_T eOwner, VIDEO_DBG_ID_T eID, kal_uint32 u4Param);
extern void VideoStartLogging(kal_char *pcCustomJob);
extern void VideoStopLogging(kal_char *pcCustomJob);
extern void VideoLabelLogging(kal_char *pcCustomJob);

extern void VEBufferTrace(trace_class_enum eTrcClass, kal_uint32 u4MsgIdx, const char *pcArgType, kal_uint32 u4BuffSize, kal_uint8* pu1Buff);

#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_DBG_V2_H */

