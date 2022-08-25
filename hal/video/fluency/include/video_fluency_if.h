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
 *   video_fluency_if.h
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
 ****************************************************************************/
#ifndef VIDEO_FLUENCY_IF_H
#define VIDEO_FLUENCY_IF_H

#include "drv_features_video.h"
#include "kal_general_types.h"
#include "video_types_v2.h"

#include "mpl_omx_core.h"
#include "video_codec_utility_v2.h"
#include "video_codec_mem_v2.h"
#include "SwDecodeFrameHeader.h"
#include "mpl_common.h"


#ifndef __VE_VFC_FULL_LOG__

#define VFC_SLIM_LOG0(group, log) do{}while(0);
#define VFC_SLIM_LOG1(group, log, arg1) do{}while(0);
#define VFC_SLIM_LOG2(group, log, arg1, arg2) do{}while(0);
#define VFC_SLIM_LOG4(group, log, arg1, arg2, arg3, arg4) do{}while(0);
#define VFC_SLIM_LOG8(group, log, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) do{}while(0);

#define VFC_SLIM_DEV_LOG1(group, log, arg1) do{}while(0);
#define VFC_SLIM_DEV_LOG2(group, log, arg1, arg2) do{}while(0);
#define VFC_SLIM_DEV_LOG4(group, log, arg1, arg2, arg3, arg4) do{}while(0);

#else

#define VFC_SLIM_LOG0(group, log) \
    do{   \
        drv_trace0(group, log); \
    }while(0);

#define VFC_SLIM_LOG1(group, log, arg1) \
    do{   \
        drv_trace1(group, log, arg1); \
    }while(0);
#define VFC_SLIM_LOG2(group, log, arg1, arg2) \
    do{   \
        drv_trace2(group, log, arg1, arg2); \
    }while(0);

#define VFC_SLIM_LOG4(group, log, arg1, arg2, arg3, arg4) \
    do{   \
        drv_trace4(group, log, arg1, arg2, arg3, arg4); \
    }while(0);

#define VFC_SLIM_LOG8(group, log, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    do{   \
        drv_trace8(group, log, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)); \
    }while(0);

#define VFC_SLIM_DEV_LOG1(group, log, arg1) \
    do{   \
        kal_dev_trace(group, log, arg1); \
    }while(0); 

#define VFC_SLIM_DEV_LOG2(group, log, arg1, arg2) \
    do{   \
        drv_trace2(group, log, arg1, arg2); \
    }while(0);
    
#define VFC_SLIM_DEV_LOG4(group, log, arg1, arg2, arg3, arg4) \
    do{   \
        kal_dev_trace(group, log, arg1, arg2, arg3, arg4); \
    }while(0);    
  
#endif


typedef enum
{
    // MPL relatede
    VFC_OP_MPL_BEGIN = 0,
    VFC_OP_MPL_SET_SCENARIO,
    VFC_OP_MPL_SET_CONTAINER_FRAMERATE,
    VFC_OP_MPL_SET_CONTAINER_BITRATE,
    VFC_OP_MPL_SET_JUMP_TO_I_THRE,
    VFC_OP_MPL_SET_STOP_AUDIO_THRE,
    VFC_OP_MPL_SET_JUMP_RANGE,
    VFC_OP_MPL_SET_VIDEO_DURATION,
    VFC_OP_MPL_NOTIFY_JUMP_I,
    VFC_OP_MPL_INIT_VFC,
    VFC_OP_MPL_DEINIT_VFC,
    VFC_OP_MPL_SET_MAX_AV_TOLERANCE,
    
    // Source related
    VFC_OP_SRC_BEGIN = 30,
    VFC_OP_SRC_FRAME_ADDED,
    VFC_OP_SRC_FRAME_REMOVED,
    VFC_OP_SRC_BITSTREAM_FLUSHED,
    VFC_OP_SRC_SET_VIDEO_CODEC_TYPE,
    
    // Decoder related
    VFC_OP_VD_BEGIN = 60,
    VFC_OP_VD_UPDATE_DECODER_STAT, // Decoding Window
    VFC_OP_VD_CHECK_BITSTREAM_RECEIPT,
    VFC_OP_VD_CHECK_IF_TRIGGER_DECODE,
    VFC_OP_VD_CHECK_IF_SEND_TO_DISPLAY,
    VFC_OP_VD_FRAME_REMOVED,
    VFC_OP_VD_LASTEST_FRAME_TIME,
    VFC_OP_VD_TOTAL_YUV_NUM,
    VFC_OP_VD_NOT_DISPLAY_DONE_NUM,
    VFC_OP_VD_JUMP_PENALTY,

    // Scheduler related
    VFC_OP_SCH_BEGIN = 90,
    VFC_OP_SCH_CHECK_RCV_FRAME,  
    VFC_OP_SCH_UPDATE_AV_SYNC_TIME,
    VFC_OP_SCH_CHECK_AV_SYNC_STAT,
    VFC_OP_SCH_SET_START_TIME,
    VFC_OP_SCH_SET_KEY_FRAME_TIME,
    VFC_OP_SCH_CHECK_DISPLAY_DURATION,

    // Renderer related
    VFC_OP_VR_BEGIN = 120,
    VFC_OP_VR_CHECK_DISPLAY_OR_DROP,

    VFC_OP_END = 128
}VIDEO_FLUENCY_OP_CODE_ENUM;


#define VFC_VR_OCCUPIED_FRAME_NUM 1

/****************************************************************************
 ****************************************************************************
 *
 *  Decoder related enum
 *
 ****************************************************************************
 ****************************************************************************/

typedef struct
{
    VIDEO_BUFFERFLAG_TYPE_T         eBufferFlag;
    kal_uint32                      u4DecodeTime;    // milli-second
    kal_uint32                      u4DecodeTotalTime;     // milli-second
    kal_uint32                      u4DecodeCount;
    VIDEO_BUFFERHEADER_TYPE_T*      pBufferHeader;        
    
}VFC_OP_DATA_DECODE_TIME_WND_T;


typedef struct
{
    VIDEO_BUFFERHEADER_TYPE_T*    pBufferHeader;
    kal_uint8                     u1DataNumInInputQ;
    
}VFC_OP_DATA_BITSTREAM_RECEIPT_T;

typedef struct
{
    kal_bool                      fgNeed2TriggerDecode;
    kal_uint64                    u8CurrentPlayTime;
    
}VFC_OP_DATA_DECODER_INFO_T;


/****************************************************************************
 ****************************************************************************
 *
 *  Scheduler related enum
 *
 ****************************************************************************
 ****************************************************************************/

typedef struct
{
    kal_uint64 u8CurrTime;          // micro-second
    kal_uint64 u8LatestTimeStamp;   // micro-second

}VFC_OP_DATA_PLAYBACK_STAT_T;

typedef struct
{
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader;
    kal_uint64 u8CurrTime;       // micro-second    
}VFC_OP_DATA_CHECK_FLUENCY_T;

typedef enum
{
    VFC_RECOVER_JUMP = 0,
    VFC_RECOVER_STOP_AUDIO = 1,
    VFC_RECOVER_MAX = 2
}VFC_RECOVER_TYPE_ENUM;

typedef struct
{
    kal_bool afgCheckResult[VFC_RECOVER_MAX];
    kal_uint64  u8TimeDiff;
    kal_uint64  u8JumpEndTime; // For finding the key frame before the specified time. In unit of micro-second
}VFC_OP_DATA_CHECK_RECOVER_RESULT_T;

typedef struct
{
    // Scheduler uses this value to decide callback for jump or not
    kal_uint64  u8ToJumpKeyframeTime;   // Micro-second second
    kal_uint32  u4TotalYUVNum;
    kal_uint32  u4Wait2DisplayNum;
    kal_uint64  u8JumpPenaltyTime;      // Micro-second 
    kal_bool    fgNeed2Jump;  
}VFC_OP_DATA_JUMP_EVENT_T;

typedef struct
{
    kal_uint32 u4CodecDisplayNum;
    kal_uint32 u4SchedulerReturnedNum;
}VFC_OP_DATA_YUV_INFO;

/****************************************************************************
 ****************************************************************************
 *
 *  Renderer related enum
 *
 ****************************************************************************
 ****************************************************************************/

typedef enum
{
    VFC_VR_PROCESS_NEW_FRAME,
    VFC_VR_PROCESS_REFRESH,
    VFC_VR_PROCESS_MAX
}VFC_RENDERER_PROCESS_TYPE_ENUM;

typedef struct
{
    VFC_RENDERER_PROCESS_TYPE_ENUM  eProcessType;
    VIDEO_BUFFERHEADER_TYPE_T*      pBufferHeader;
    kal_uint32                      u4ProcessTime; // The time for renderering a new frame. (In unit of milli-second)

}VFC_OP_DATA_RENDERER_STAT_T;

#define VFC_ONE_SECOND              1000000  // unit: micro-second

/****************************************************************************
 ****************************************************************************
 *
 *  MPL related enum
 *
 ****************************************************************************
 ****************************************************************************/

typedef struct
{
    kal_uint64  u8KeyframeTime;         // Micro-second
    kal_bool    fgSuccess;              // Set as KAL_TRUE when getting Keyframe time successfully.
    kal_bool    fgEnableDurationMode;   // Inform CCU that the Duration Mode is enabled or not.
}VFC_GET_KEYFRAME_TIME_T;

/****************************************************************************
 ****************************************************************************
 *
 *  Source related enum
 *
 ****************************************************************************
 ****************************************************************************/

#define VFC_MAX_FRAME_RECORD_NUM 15 // temp value

typedef struct
{
    kal_uint64  u8TimeStamp;
}VFC_SCD_RECORD_ENTITY_T;

typedef struct
{
    VIDEO_CORE_RING_BUFFER_MGR_T    rSCDRecordBufferMgr;
    VFC_SCD_RECORD_ENTITY_T         arSCDRecord[VFC_MAX_FRAME_RECORD_NUM];

    kal_uint64 u8MaxTime; //ms
    kal_uint64 u8MinTime; //ms

    kal_bool fgInited;
}VFC_SCD_RECORD_T;

typedef enum
{
    VFC_ADD_SCD_INFO,
    VFC_REMOVE_SCD_INFO,
    VFC_RESET_SCD_INFO,
}VFC_SCD_OPERATION_ENUM;

typedef struct
{
    VFC_SCD_RECORD_T*       pSCDRecord;
    VFC_SCD_RECORD_ENTITY_T rSCDData;
    
}VFC_SCD_RECORD_OP_DATA_T;


/****************************************************************************
 ****************************************************************************
 *
 *  Decoder related enum
 *
 ****************************************************************************
 ****************************************************************************/
#define DECODE_TIME_WND_SIZE 15
typedef struct
{
    // Window data for InterFrame
    kal_uint64 ru8WndInterFrameDecodeTime[DECODE_TIME_WND_SIZE];  // micro-second
    kal_uint32 u4WndInterFrameDecodeCount;
    kal_uint64 u8AvgWndInterFrameDecodeTime;                      // micro-second

    // Window data for IntraFrame
    kal_uint64 ru8WndIntraFrameDecodeTime[DECODE_TIME_WND_SIZE];  // micro-second
    kal_uint32 u4WndIntraFrameDecodeCount;
    kal_uint64 u8AvgWndIntraFrameDecodeTime;                      // micro-second

    
    kal_uint64 u8DecoderTotalTime4I;                    // micro-second
    kal_uint64 u4DecoderCounter4I;
    
    kal_uint64 u8DecoderTotalTime4P;                    // micro-second
    kal_uint32 u4DecoderCounter4P;

    // Total data
    kal_uint64 u8DecoderTotalTime;                      // micro-second
    kal_uint32 u4DecoderTotalCount;

    // Action
    kal_uint32 u4DecodeQualityMode;                     // Codec decode mode  

    kal_uint32 u4ExcludedCount;
}VIDEO_FLUENCY_CONTROL_DECODE_STAT_T;


/****************************************************************************
 ****************************************************************************
 *
 *  Common definition
 *
 ****************************************************************************
 ****************************************************************************/

// This struct will be carried by VA2_VIDEO_FRAME_T
typedef struct
{
    kal_uint64 u8CurrentPlayTime;           // Current audio time (unit: micro-second)
    kal_uint64 u8LatestTimeStamp;           // Lastest Timestamp to Renderer (unit: micro-second)        
    kal_uint32 u4ContainerFrameRate;        // FrameRate from container(unit: fps*100)
    kal_uint32 u4ContainerBitRate;          // BitRate from container(unit: bytes)    
    kal_uint32 u4JumpToICount;              // The count of Jump-to-I had performed.
    kal_uint32 u4StopAudioCount;            // The count of Stop-Audio had performed.
} VFC_CONTROL_PLAYBACK_INFO_T;

typedef enum
{
    VFC_JUMP_NORMAL = 0,
    VFC_JUMP_OUT_OF_SYNC,
    VFC_JUMP_CHECKING,
    VFC_JUMP_WAITING,
    VFC_JUMP_MAX
}VFC_JUMP_STATE_ENUM;

typedef enum
{
    VFC_SCD_NOT_FOUND = 0,    
    VFC_SCD_FOUND = 1,            
    VFC_SCD_DISABLED,
    VFC_SCD_ENABLED,    
    VFC_SCD_MAX_TOLERANCE,
    VFC_SCD_MAX
}VFC_SCD_STATE_ENUM;


typedef VCODEC_DEC_FRAME_HDR_ERROR_T (*PFN_FRAME_HEADER_PARSER)(IN VCODEC_DEC_FRAME_HDR_INPUT_T *prInput , OUT VCODEC_DEC_FRAME_HDR_INFO_T *prOutput);

typedef struct
{   
    // Misc Value
    kal_uint64 u8LatestPoppedFrameTime;      // Lastest popped time (not decoded yet)    
    kal_bool fgInit;
    kal_uint64 u8Time4PreQueryKeyFrameStart;
    kal_uint64 u8Time4PreQueryKeyFrameDone;
    kal_uint64 u8PreviousJumpTime;
    kal_uint64 u8PreviousStopAudioTime;
    kal_uint64 u8VideoStartTime;
    kal_bool   fgSCDOpened;
    kal_bool   fgSCDFound;
    kal_bool   fgEnableDurationMode;

    // Threshould
    kal_uint64 u8Jump2IThre;
    kal_uint64 u8StopAudioThre;

    // Misc
    kal_uint64 u8MAXAVSyncTolerance;        // micro-second
    kal_uint64 u8JumpRange;                 // micro-second
    kal_uint64 u8VideoDuration;             // micro-second 
    kal_uint64 u8ToJumpKeyFrameTime;        // micro-second 
    kal_uint64 u8SeekTime;                  // micro-second    
    kal_uint64 u8FoundSCDTime;              // micro-second    
    kal_uint64 u8PreviousFrameUpdateTime;   // micro-second   
    
    kal_uint32  u4VDTotalYUVNum;
    kal_uint32  u4Wait2DisplayNum;
    kal_uint64  u8JumpPenaltyTime;          // micro-second
    kal_uint32  u4JumpPenaltyNum;           // Wait to output num
    kal_uint32  u4PendJumpCounter;          // For Profile
    
    VFC_JUMP_STATE_ENUM eJumpState;
    media_codec_type_t  eCodecType;
    
    VIDEO_FLUENCY_CONTROL_DECODE_STAT_T rVFCDecodeTimeStat;
    VFC_CONTROL_PLAYBACK_INFO_T         rVFCPlaybackInfo;    
    VFC_SCD_RECORD_T                    rVFCSCDRecord;
        
    PFN_FRAME_HEADER_PARSER pFrameHeaderParser;
    VFC_SCD_STATE_ENUM      eSCDCheckResult;
        
}VIDEO_FLUENCY_CONTROL_T;


extern kal_bool VFC_IOCtrl(VIDEO_FLUENCY_OP_CODE_ENUM eOPCode, void* pInData, void* pOutData, void* pExtra);
extern kal_bool VFC_Init(VIDEO_FLUENCY_CONTROL_T* prVFC);
extern kal_bool VFC_Deinit(VIDEO_FLUENCY_CONTROL_T* prVFC);
extern void VFC_VD_CHECK_IF_TRIGGER_DECODE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SCH_SET_START_TIME(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SCH_SET_KEY_FRAME_TIME(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_VD_SET_LASTEST_FRAME_TIME(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_JUMP_RANGE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_MAX_AV_TOLERANCE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_VIDEO_DURATION(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_JUMP_TO_I_THRE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_STOP_AUDIO_THRE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_SCENARIO(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_FRAME_REMOVED(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SRC_FRAME_ADDED(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_VD_UPDATE_DECODER_STAT(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SCH_CHECK_AV_SYNC_STAT(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SCH_UPDATE_AV_SYNC_TIME(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_NOTIFY_JUMP_I(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_CONTAINER_FRAMERATE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_MPL_SET_CONTAINER_BITRATE(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SCH_CHECK_RCV_FRAME(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFCSCDRecordInit(VFC_SCD_RECORD_T *pMgr, kal_uint8 *pu1Buffer, kal_uint32 u4MaxNumberofAtoms, kal_uint32 u4UnitSize);
extern void VFCSCDRecordDeinit(VFC_SCD_RECORD_T *pMgr);
extern void VFCSCDRecordReset(VFC_SCD_RECORD_T *pRecord);
extern void VFC_CheckSCDStatus(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_SCH_CHECK_DISPLAY_DURATION(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_VD_NOTIFY_TOTAL_YUV_NUM(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_VD_NOTIFY_JUMP_PENALTY(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);
extern void VFC_VD_NOTIFY_NOT_DISPLAY_DONE_NUM(VIDEO_FLUENCY_CONTROL_T* prVFC, void* pInData, void* pOutData, void* pExtra);

// To check whether memory allocation is sufficient or not
// If build error occurred here, please enlarge memory allocation of VIDEO_FLUENCY_CONTROL_T

#if defined(__VE_VIDEO_ARCHI_V2__)
typedef char VFCCheckSize[(VIDEO_FLUENCY_MGR_LEN > sizeof(VIDEO_FLUENCY_CONTROL_T)) ? 1 : -1];
#endif


#endif /* VIDEO_FLUENCY_IF_H */ 

