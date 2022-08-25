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
 *   video_encoder_component_v2.h
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
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 ****************************************************************************/
#ifndef VIDEO_ENCODER_COMPONENT_V2_H
#define VIDEO_ENCODER_COMPONENT_V2_H

#include "drv_features_video.h"

#include "video_encoder_component_if_v2.h"
#include "video_codec_if_v2.h"
#include "video_codec_type_v2.h"
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_codec_custom_setting_v2.h"
#include "kal_release.h"
#include "video_buffer_management_v2.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "video_codec_utility_v2.h"

//Debug
//#define __SELF_TEST__

typedef struct
{
    kal_uint32 u4BufferSize;                // Current memory size to be (or has been) allocated
    kal_uint8 *pu1BufferStart;
    kal_uint8  *pau1Buff[VIDEO_ENCODER_MAX_YUV_BUF_NUM];
    kal_uint32 u4FrameMemSize;              // Memory size of a frame (with alignment overhead)
    kal_uint32 u4TotalNum;
} VIDEO_ENCODER_YUV_BUFFER_T;

#if defined(__VE_H264_ENC_SW_SUPPORT__)
    #define HEADER_BUFFER_SIZE (256 + 1)
#else
    #define HEADER_BUFFER_SIZE (64 + 1)
#endif
typedef struct
{
    kal_uint32 u4BufferSize;
    kal_uint8 *pu1BufferStart;
    kal_uint8 *pu1BufferEnd;
    kal_uint8 *pu1RP;           // the Read pointer
    kal_uint8 *pu1WP;           // the Write pointer
    kal_uint32 u4Zombie;
    kal_bool fgIsBufferFull;    // TRUE if the buffer is full
    kal_uint8*   pu1HeaderBuffer;
    kal_uint32  u4LeftOverOf1stCluster;
    VENC_BIT_BUFFER_STATE_T eState;

#if defined(__VE_VENC_PROFILING_BITSTREAM__)
    kal_uint32 u4WriteCounter;  // for debugging
    kal_uint32 u4ReadCounter;   // for debugging
    kal_uint32 u4ScarceCounter; // for debugging
    kal_uint32 u4PeakSize;      // for debugging
#endif //__VE_VENC_PROFILING_BITSTREAM__
} VIDEO_ENCODER_BIT_BUFFER_T;

typedef struct
{
    VIDEO_ENC_MEMORY_T rCodecMemory;
    KAL_ADM_ID rCodecMemAdmId;
    kal_uint8* pu1StartAddr;
    kal_bool fgBSinCache;
} VIDEO_ENCODER_WORKING_MEM_T;

typedef struct
{
    kal_bool    fgVTRestart;                //VENC_PARAM_VT_RESTART
    kal_bool    fgShortHeader;              //VENC_PARAM_SHORT_HEADER
    kal_uint32  u4Width;                    //VENC_PARAM_WIDTH
    kal_uint32  u4Height;                   //VENC_PARAM_HEIGHT
    kal_uint32  u4SyncInternal;             //VENC_PARAM_SYNC_INTERVAL
    kal_uint32  u4Bitrate;                  //VENC_PARAM_BITRATE
    kal_uint32  u4PacketSize;               //VENC_PARAM_MAX_PKG_SIZE
    kal_uint32  u4FrameRate;                //VENC_PARAM_FRAME_RATE
    kal_uint32  u4GenHeaderFrameRate;       //VENC_PARAM_GEN_HEADER_FRM_RATE

    VIDEO_CODEC_ROTATE_ANGLE_T  eRotateAngle;   //VENC_PARAM_ROTATE
    VIDEO_ENCODER_QUALITY_T     eQuality;       //VENC_PARAM_QUALITY
    VIDEO_ENCODER_SCENARIO_T    eScenario;      //VENC_PARAM_SCENARIO
    VIDEO_ENCODER_CODEC_T       eCodecType;     //VENC_PARAM_CODEC_TYPE
    VIDEO_ENCODER_ADAPT_CALLBACK_T  rCallbacks; //VENC_PARAM_SET_CALLBACK
} VIDEO_ENCODER_ADAPT_SETTINGS_T;

typedef struct
{
    VIDEO_YUV_HEADER_T  arYUVHeaderPool[VIDEO_ENCODER_YUV_HEADER_Q_NUM];
}VENC_YUV_HEADER_POOL_T;

typedef struct
{
    kal_uint64          arTimeStampPool[VENC_TIME_STAMP_Q_NUM];
}VENC_TIME_STAMP_POOL_T;

typedef struct
{
    VIDEO_BUFFERHEADER_TYPE_T   arResendPool[VIDEO_ENCODER_RESEND_Q_NUM];
}VENC_RESEND_Q_POOL_T;

typedef struct
{
    VENC_YUV_HEADER_POOL_T* parYUVHeaderPool;
    VENC_TIME_STAMP_POOL_T* parTimeStampPool;
    VENC_RESEND_Q_POOL_T*   parResendPool;
} VENC_RING_BUFFER_POOL_T;

typedef struct
{
    VIDEO_CORE_RING_BUFFER_MGR_T rBufferMgr;
    kal_uint8*  pu1BufferAddr;
}  VENC_RING_BUFFER_MGR_T ;

typedef struct
{
    kal_uint8*  pu1StartAddress;
    kal_uint32  u4BufferSize;
} BISTREAM_BUFFER_T;
typedef struct
{
    kal_uint8*  pu1Addr;
    BISTREAM_BUFFER_UNIT_STATUS_T eStatus;
} BISTREAM_BUFFER_UNIT_T;

typedef struct
{
    kal_uint8*  pu1StartAddress;
    kal_uint8*  pu1DummyBuffer;
    kal_uint32  u4AvailableIdx;
    kal_uint32  u4EncodingIdx;
    kal_uint32  u4Ready2WriteIdx;
    kal_uint32  u4NextWritedIdx;
    kal_uint32  u4EncodingNum;
    BISTREAM_BUFFER_UNIT_T* parBufferPool;
} BISTREAM_BUFFER_CTRL_T;

#define VIDEO_ENCODE_TOTAL_FRM_NUM (VIDEO_ENCODER_INPUT_BUFFER_Q_NUM + VIDEO_ENCODER_YUV_HEADER_Q_NUM)
typedef struct
{
    VIDEO_COMM_STATE_T rCommState;
    VIDEO_ENCODER_INTERNAL_STATE_T eIntState;
    VIDEO_CODEC_T eCodec;
    VENC_CODEC_STATE_T eCodecState;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T rCustomSettings;
    VIDEO_ENCODER_WORKING_MEM_T rWorkingMem;
    VIDEO_ENCODER_CODEC_API_T *prCodecAPI;
    VENC_RING_BUFFER_POOL_T rRingBuffers;
    VENC_RING_BUFFER_MGR_T rYUVHeaderQ;  // a queue of YUV buffer headers
    VENC_RING_BUFFER_MGR_T rOutResendQ;
    VENC_RING_BUFFER_MGR_T rTimeStampQ;
    VIDEO_ENCODER_YUV_BUFFER_T rYuvBufferMgr;
    VIDEO_ENCODER_BIT_BUFFER_T rBitBufferMgr;
    BISTREAM_BUFFER_CTRL_T rBistreamBufferCtrl;
#if defined (__VE_VIDEO_VT_SUPPORT__)
    VIDEO_ENCODER_CHASSIS_MGR_T rChassisMgr;
#endif  // __VIDEO_VT_SUPPORT__
    VIDEO_ENCODER_SCENARIO_T eEncoderScenario;
    VIDEO_ENCODER_ADAPT_SETTINGS_T  rAdaptSettings;
    kal_uint32 u4SourceWidth;
    kal_uint32 u4SourceHeight;
    VENC_CLEAN_MODE_T   eCleanMode;
    kal_timerid rTimerID;
    kal_uint32 u4CodecConfig;

    kal_bool fgInitResendQ;
    kal_bool fgRdy2FlushCodec;
    kal_bool fgFlushedCodec;
    kal_bool fgSourceNotifyStop;
    kal_bool    fgLimitFrmBuff;
    kal_bool    fgTriggerEncoder;
    kal_bool    fgStartWakeUpTimer;
    kal_bool fgSetupCodec;
    kal_bool fgInitFrameBuffer;             // Indicate whether frame buffer has been sent to souce component or not (Do it once on lifetime)
    kal_bool fgStopInstantly;
    kal_bool fgGenerateHeader;
    kal_bool fgClosingEncoder;
    kal_bool fgPauseResume;
    kal_bool afgSceneChange[VIDEO_ENCODE_TOTAL_FRM_NUM];
    kal_uint32 u4SceneChangeWriteIndex;
    kal_mutexid rFillMutex;
    kal_uint64 u8TimeLimit;

    VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr;
    VIDEO_INTMEM_HANDLER_T* prIntMemHdlr;

    // workaround controller race condition
    kal_uint32  u4CleanCnt;
    VIDEO_BUFFERHEADER_TYPE_T rDummyBufferHeader;

    //debug info
    kal_uint32 u4InputQueueNumber;          // number of items in the input buffer queue
    kal_uint32 u4OutputQueueNumber;         // number of items in the output buffer queue

#if defined(__VE_VENC_PROFILING_CODEC__)
    kal_uint32 u4AccumEncodingTime;         // the accumulated encoding time
    kal_uint32 u4AccumEncodedFrames;        // number of frames encoded
    kal_uint32 u4MinEncodingTime;           // minimum of encoding time
    kal_uint32 u4MaxEncodingTime;           // maximum of encoding time
    kal_uint32 u4AvgEncodingTime;           // average of encoding time
#endif //__VE_VENC_PROFILING_CODEC__

#if defined(__VE_VENC_PROFILING_SENSOR__)
    kal_uint32 u4PreviousRcvTime;
    kal_uint32 u4TotalRcvTimeInMS;
    kal_uint32 u4TotalRcvFrameNum;
#endif //__VE_VENC_PROFILING_SENSOR__

#if defined(__VE_VENC_PROFILING_VT__)
    kal_uint32 u4EncodedFrameNum;
    kal_uint32 u4TimePassed;
    kal_uint32 u4ProfileStartTime;
    kal_uint32 u4EncodedBits;
#endif //__VE_VENC_PROFILING_VT__
    kal_bool    fgCompClosed;

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    kal_uint64 u8TLCaptureFrameTime;
    kal_uint32 u4TLCaptureFrameDuration;
    kal_uint64 u8TLEncodedFrameTime;
    kal_uint32 u4TLEncodedFrameDuration;
#endif
} VIDEO_ENCODER_MGR_T;

extern void VideoEncoderReleaseYUV(kal_uint8 *pu1Buff);
extern void VideoEncoderGenBistream(void);
extern void VideoEncoderAllocateBitstreamBuffer(
    kal_uint8** ppu1StartAddr,
    kal_uint8** ppu1EndAddr,
    kal_uint8** ppu1WriteAddr,
    kal_uint8** ppu1ReadAddr,
    kal_uint32* pu4BufferLength
    );
extern void VideoEncoderPaused(kal_uint8* pu1ReadPtr);
extern kal_uint32 VideoEncoderGetIntMem(kal_uint32 u4ReqSize);
extern void VideoEncoderFreeIntMem(kal_uint8* pu1FreeAddr, kal_uint32 u4FreeSize);

extern void VideoEncoderUpdateBitstreamWP(kal_uint8 *pu1WP, kal_int32 is_slice_contained);
extern void VideoEncoderQueryBitstreamNewWP
(
    kal_uint8  *pu1WP,       //the newWP ready to write to, which would contain data we assumed
    kal_uint8 **ppu1NextWP,
    kal_uint32 *pu4AvialbleLength
);

// This macro works only when "x" is 2^n.
#define ROUND_UP_TO_POWER_OF_TWO(data,x)        \
        (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))


#define VIDEO_ENCODER_SET_FRONT_END_TO_IDLE     0

#endif /* VIDEO_ENCODER_COMPONENT_V2_H */

