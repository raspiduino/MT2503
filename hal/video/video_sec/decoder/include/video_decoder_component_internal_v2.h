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
 *   video_decoder_component_internal_v2.h
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
 *
 * removed!
 ****************************************************************************/
#ifndef VIDEO_DECODER_COMPONENT_INTERNAL_V2_H
#define VIDEO_DECODER_COMPONENT_INTERNAL_V2_H

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#include "kal_general_types.h"
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_codec_buffer_mgr_v2.h"
#include "video_codec_if_v2.h"
#include "video_codec_utility_v2.h"
#include "video_codec_mem_v2.h"
#include "video_codec_custom_setting_v2.h"
#include "video_codec_type_v2.h"
#include "kal_release.h"
#include "app_ltlcom.h"
#include "video_buffer_management_v2.h"
#include "kal_public_defs.h"

#ifdef __VE_KMV_SUPPORT__
#include "video_kmv_v2.h"
#endif



#ifdef __VE_SLIM_PROJECT__

#define VE_SLIM_LOG0(group, log) do{}while(0);
#define VE_SLIM_LOG1(group, log, arg1) do{}while(0);
#define VE_SLIM_LOG2(group, log, arg1, arg2) do{}while(0);
#define VE_SLIM_LOG4(group, log, arg1, arg2, arg3, arg4) do{}while(0);
#define VE_SLIM_LOG8(group, log, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) do{}while(0);

#else
#define VE_SLIM_LOG0(group, log) \
    do{   \
        drv_trace0(group, log); \
    }while(0);

#define VE_SLIM_LOG1(group, log, arg1) \
    do{   \
        drv_trace1(group, log, arg1); \
    }while(0);
#define VE_SLIM_LOG2(group, log, arg1, arg2) \
    do{   \
        drv_trace2(group, log, arg1, arg2); \
    }while(0);

#define VE_SLIM_LOG4(group, log, arg1, arg2, arg3, arg4) \
    do{   \
        drv_trace4(group, log, arg1, arg2, arg3, arg4); \
    }while(0);

#define VE_SLIM_LOG8(group, log, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    do{   \
        drv_trace8(group, log, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)); \
    }while(0);
  
#endif


/**************************************************************************************************
*   VIDEO_DECODER_BS_BUFFER_ATOM_T
*
*   An atom of ring buffer of returning bitstream
*   Decoder use this structure to manage asyncronous returning bistream
*
**************************************************************************************************/
typedef struct
{
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;    //Buffer header of a bitstream
    kal_bool    fgReturned;                     //True: codec has returned the bitstream;FALSE: otherwise
}VIDEO_DECODER_BS_BUFFER_ATOM_T;


/**************************************************************************************************
*   VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T
*
*   Record associated timestamp and frame buffer
*
**************************************************************************************************/
typedef struct
{
    kal_uint64  u8TimeStamp;
    kal_uint8*  pu1FrameBufferAddr;    
    kal_bool    fgUsed;
}VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T;

/**************************************************************************************************
*   VIDEO_DECODER_MEM_HANDLER_T
*
*   Record associated memory handler
*
**************************************************************************************************/
typedef struct
{
    VIDEO_EXTMEM_HANDLER_T *prExtMemHdr;
    VIDEO_INTMEM_HANDLER_T *prIntMemHdr;
}VIDEO_DECODER_MEM_HANDLER_T;

typedef struct
{  
    VIDEO_CORE_RING_BUFFER_MGR_T rOutputResendQueueMgr;
    VIDEO_BUFFERHEADER_TYPE_T arOutputResendQueue[VIDEO_DECODER_RESEND_Q_NUM];
    VIDEO_CORE_RING_BUFFER_MGR_T rInputResendQueueMgr;
    VIDEO_BUFFERHEADER_TYPE_T arInputResendQueue[VIDEO_DECODER_RESEND_Q_NUM];
    
    VIDEO_BUFFERHEADER_TYPE_T   arUnsentBufferHeader[VIDEO_DECODER_MAX_YUV_BUF_NUM];
    VA2_VIDEO_FRAME_T arUnsentPrivateData[VIDEO_DECODER_MAX_YUV_BUF_NUM];

#ifdef __VE_KMV_SUPPORT__
    kmv_meta_st arKMVMetaData[VIDEO_DECODER_MAX_YUV_BUF_NUM/2];
#endif

    //Ring buffer management for async. bitstream return
    VIDEO_CORE_RING_BUFFER_MGR_T rReturningBitstreamBufferMgr; 
    VIDEO_DECODER_BS_BUFFER_ATOM_T  arReturningBitstream[VIDEO_DECODER_RETURN_BS_BUFFER_Q_NUM];

#ifndef __VE_ROBUST_FLOW__
    VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T arTimeNFrameBuffer[VIDEO_DECODER_MAX_YUV_BUF_NUM];
#endif
}VIDEO_DECODER_INFO_SAVE_EXT_MEM;

typedef struct
{
    kal_uint32 u4FramesCodecDisplay;
    kal_uint32 u4FramesCodecGet;
    kal_uint32 u4FramesSchedulerReturn;
    kal_uint32 u4ItemsInInputQ;
    kal_uint32 u4ItemsInOutputQ;
    //kal_uint32 u4OneYUVBufferSize;

#ifndef __VE_SLIM_PROJECT__    
    kal_uint32 u4SchedulerTotalTime;
    kal_uint32 u4SchedulerCounter;

    kal_uint32 u4FileReaderTotalTime;
    kal_uint32 u4FileReaderCounter;

    kal_uint32 u4PreviousRcvTime;
    kal_uint32 u4TotalRcvTimeInMS;
    kal_uint32 u4TotalRcvFrameNum;

    kal_uint32 u4WaitOutputTotalTime;
    kal_uint32 u4WaitOutputCounter;
    kal_uint32 u4WaitOutputMaxTime;     

    kal_uint32 u4IdleDueToNoBitstream;
    kal_uint32 u4IdleDueToNoYUVBuffer;        
#endif 

    kal_uint32 u4AvailableYUVNumber;
    kal_uint32 u4DecoderCounter;

    //kal_uint32 u4FlushWriteIdx;
    kal_uint32 u4NeedToFlushNum;
#ifndef __VE_ROBUST_FLOW__    
    kal_uint32 u4TimeNFrameIndex;
#endif
    kal_uint32 u4MinLeftSize;    
    
//#if defined(__VE_ENABLE_FORCE_SLEEP__) || !defined(__VE_SLIM_PROJECT__)
    kal_uint32  u4ExecuteTicks;
    kal_uint32 u4DecoderTotalTime;
//#endif
    
#ifndef __VE_SLIM_PROJECT__ 
    kal_bool fgWaitBuffer;
#endif
    
    kal_bool fgInitBuffer;
    kal_bool fgClosingDecoder;
    kal_bool fgIsFlushCodecSyncFrm;
    
#ifndef __VE_SLIM_PROJECT__    
    kal_bool fgWaitInputLogging;
    kal_bool fgWaitOutputQLogging;
#endif
    
#ifdef __VE_ENABLE_FORCE_SLEEP__
    kal_bool    fgDecoderSleep;
    kal_uint8   u1ElapseTicks;
    kal_uint8   u1SleepTicks;
#endif

    kal_bool    fgCodecNotSupport;    
    kal_bool    fgDisplay2Send;
    kal_bool    fgBuffering;
    kal_bool    fgBitstreamQFull;
    kal_bool    fgFail2SetYUV;
#ifdef __VE_PRIRATE_3D_FORMAT__
    kal_bool    fgDecryptionMode;
#endif
        
    VIDEO_DECODER_FLUSH_STATE_T eFlushAllNonSyncFrmState;
    VA2_VIDEO_FRAME_T*  parLastUnsentPrivateData;
    kal_uint8*  pu1LastDisplayYUVAddr;    
    kal_uint64  u8TimeStampOfLastDecodedFrm;
    kal_uint64  u8CurrentPlayTime; 
    kal_uint64  u8Last2CodecFrameTime;    
    
    kal_bool    fg1stKeyFrameReady;
    
}VIDEO_DECODER_MGR_DZ_T;


typedef struct
{
    kal_bool fgStartWakeUpTimer;
    kal_bool fgCallbackIL;
    kal_bool fgUnsupportCallbackIL;
    kal_bool fgRetryCallbackIL;
    
#ifndef __VE_SLIM_PROJECT__     
    kal_uint32 u4WaitInputStartTime;
    kal_uint32 u4CoverWaitTime;    
    kal_uint32  u4HeaderRetryNs;       
    kal_uint32 u4WaitOutputStartTime;        
#endif
    
    kal_uint32 u4YUVBufferTotalSize; 
    kal_uint32  u4BitRateFrmFile;
    kal_uint32  u4FrameRateFrmFile;    

    kal_uint32 u4NumBytesMalloced;    
    kal_uint8  u1ReturnBitstremIndex;
    
    kal_timerid rTimerID;
    
    VIDEO_COMM_STATE_T rCommState;
    VIDEO_CODEC_T eCodec;
    VIDEO_DECODER_SCENARIO_T eScenario;
    VIDEO_DECODER_CODEC_API_T* prCodecAPI;
    KAL_ADM_ID rAdmId;
    kal_uint8* pu1YUVBufferStartAddr;
    kal_uint8* pu1CodecBufferStartAddr;
    VIDEO_BUFFERHEADER_TYPE_T rNewestInputBufferHeader;
    VIDEO_DECODER_MEM_HANDLER_T rMemHdler;
    VIDEO_CODEC_MEMORY_T rCodecMemorySize;
    VIDEO_DECODER_CUSTOM_SETTINGS_T rCustomSettings;    
    VIDEO_DECODER_INFO_SAVE_EXT_MEM* prInfoExtMem;  
     
    VIDEO_YUV_BUFFER_T  rYUVBufferMgr;
    VIDEO_DECODE_MODE_T rDecodeMode;

    kal_mutexid eCommonMutex;
    VIDEO_CONTAINER_INFO_T rContainerInfo;

#ifdef __VE_KMV_SUPPORT__

    KMV_FRAME_INFO rKMVFrameInfo;
    
    KMV_Class rKMVObj;
    kmv_meta_st rKMVMetaBuf;
    KMV_frame_buffer_ext rKMVFrameBuffer;

    kal_uint64  u8StartTime;

#ifdef __VE_KMV_PROFILE_ENABLE__
    kal_uint32 u4PPTotalTime;
    kal_uint32 u4PPCounter;

    kal_uint32 u4CopyFrmTotalTime;
    kal_uint32 u4CopyFrmCounter;
    
#endif
    
#endif    

 }VIDEO_DECODER_MGR_DNZ_T;


/**************************************************************************************************
*   VIDEO_DECODER_MGR_T
*
*   The management structure of video decoder component
*
**************************************************************************************************/
typedef struct
{
    VIDEO_DECODER_MGR_DZ_T      rVDMgrDZ;
    VIDEO_DECODER_MGR_DNZ_T     rVDMgrDNZ;    
}VIDEO_DECODER_MGR_T;

// To check whether memory allocation is sufficient or not
// If build error occurred here, please enlarge memory allocation of VIDEO_DECODER_MGR_LEN
typedef char VDMgrCheckSize[(VIDEO_DECODER_MGR_LEN > sizeof(VIDEO_DECODER_MGR_T)) ? 1 : -1];

// To check whether memory allocation is sufficient or not
// If build error occurred here, please enlarge memory allocation of INFO_MEM_SIZE
typedef char InfoExtMemCheckSize[(INFO_MEM_SIZE+VIDEO_DECODER_KMV_META_LEN >= sizeof(VIDEO_DECODER_INFO_SAVE_EXT_MEM)) ? 1 : -1];


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 u4Param1;    
    kal_uint32 u4Param2;  
}VIDEO_DECODER_IND_T;

void VideoDecoderMainNonDCM(ilm_struct *ilm_ptr);
VIDEO_DECODER_COMPONENT_TYPE_T GetVideoDecoderHandle(VIDEO_DECODER_HDLR_INFO_T* pVDHandleInfo);
VIDEO_ERROR_TYPE_T ReleaseVideoDecoderHandle(VIDEO_COMPONENT_TYPE_T *prHandle);
void VideoDecoderSetDebug(kal_uint8 *string);


// This macro works only when "x" is 2^n.
#define ROUND_UP_TO_POWER_OF_TWO(data,x)                                 \
    (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))

#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_DECODER_COMPONENT_INTERNAL_V2_H */ 

