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

/*******************************************************************************
 * Filename:
 * ---------
 * mpl_video_clipper.h
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * This file is the internal header file of the Media Porting Layer of video clipper.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 03 2012 tofar.huang
 * removed!
 * .
 *
 * 03 26 2012 tofar.huang
 * removed!
 * .
 *
 * 03 05 2012 tofar.huang
 * removed!
 * .
 *
 * 12 28 2011 tofar.huang
 * removed!
 * .
 *
 * 12 16 2011 tofar.huang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MPL_VIDEO_CLIPPER_H
#define _MPL_VIDEO_CLIPPER_H

#include "mpl_clipper.h"
#include "video_types_v2.h"
#include "kal_public_defs.h"
#include "source_provider_if.h"
#include "video_muxer_if_v2.h"
#include "vcodec_enc_demuxer_if.h"
#include "video_codec_utility_v2.h"

#define __VE_TRANSFORMATION_INFO__

#define MPLVC_INVALID_INDEX 0xFF

#define MPLVC_EG_SOURCE_ALL (MPLVC_EG_SOURCE_COMPLETE | MPLVC_EG_SOURCE_ERROR | MPLVC_EG_SOURCE_MEM_LACK)
#define MPLVC_EG_SOURCE_ERR (MPLVC_EG_SOURCE_ERROR | MPLVC_EG_SOURCE_MEM_LACK)
#define MPLVC_EG_MUXER_ALL  (MPLVC_EG_MUXER_COMPLETE | MPLVC_EG_MUXER_ERROR)
#define MPLVC_EG_MUXER_ERR  (MPLVC_EG_MUXER_ERROR)

typedef enum
{
    MPLVC_STATE_CLOSED = 0,
    MPLVC_STATE_READY,
    MPLVC_STATE_RUNNING,
    MPLVC_STATE_STOPPED,
    MPLVC_STATE_SAVING_FILE,
    MPLVC_STATE_UNKNOWN = 0x1FFFFFFF
} MPLVC_STATE_T;

typedef enum{
    MPLVC_EG_SOURCE_COMPLETE        = 0x00000001,
    MPLVC_EG_SOURCE_ERROR           = 0x00000002,
    MPLVC_EG_SOURCE_MEM_LACK        = 0x00000004,
    MPLVC_EG_SOURCE_SEEK_TIME_DONE  = 0x00000008,
    MPLVC_EG_SOURCE_PORT_DONE       = 0x00000010,
    MPLVC_EG_SOURCE_KEY_FRAME_DONE  = 0x00000020,
    MPLVC_EG_MUXER_COMPLETE         = 0x00000100,
    MPLVC_EG_MUXER_ERROR            = 0x00000200,
    MPLVC_EG_VIDEO_EOS              = 0x00010000,
    MPLVC_EG_AUDIO_EOS              = 0x00020000
} MPLVC_comp_eg_enum;

typedef enum
{
    MPLVC_COMP_STATE_CLOSED = 0,
    MPLVC_COMP_STATE_INITIALIZED,
    MPLVC_COMP_STATE_IDLE,
    MPLVC_COMP_STATE_RUNNING,
    MPLVC_COMP_STATE_STOPPED,
    MPLVC_COMP_UNKNOWN = 0x1FFFFFFF
} MPLVC_COMP_STATE_T;

// TODO: For Debug, remove
typedef enum
{
    _ENTER_ = 0,
    _EXIT_
}MPLVC_FUNCALL;

typedef enum
{
    MSG_MPLVC_FILLBUFFER,
    MSG_MPLVC_EMPTYBUFFER,
    MSG_MPLVC_WAKEUP
} MPLVC_MESSAGE_T;

typedef void (*PFN_MPLVC_REDIRECTION_T)(void *pParam1, void *pParam2, void *pParam3);
typedef struct
{
    LOCAL_PARA_HDR
    PFN_MPLVC_REDIRECTION_T pfnRedirect;
    void *pParam1;
    void *pParam2;
    void *pParam3;
} MPLVC_ASYNC_CALL_T;

// Buffer manger definition

#if !defined(ENABLE_VIDEO_CLIPPER_CUSTOM_SETTING)
    #define MPLVC_ONE_VIDEO_BUFFER_SIZE       (512 * 1024)
    #define MPLVC_ONE_AUDIO_BUFFER_SIZE       (16 * 1024)
#else
    #define MPLVC_ONE_VIDEO_BUFFER_SIZE       (CUSTOM_MPLVC_ONE_VIDEO_BUFFER_SIZE)
    #define MPLVC_ONE_AUDIO_BUFFER_SIZE       (CUSTOM_MPLVC_ONE_AUDIO_BUFFER_SIZE)
#endif
#define MPLVC_VIDOE_BUFFER_NUM            (2)
#define MPLVC_AUDIO_BUFFER_NUM            (2)

#define MAX_VIDEO_BITSTREAM_SIZE  (MPLVC_ONE_VIDEO_BUFFER_SIZE * MPLVC_VIDOE_BUFFER_NUM)
#define MAX_VIDEO_INPUT_QUEUE_SIZE  (64)
#define MAX_VIDEO_RETURN_QUEUE_SIZE (MAX_VIDEO_INPUT_QUEUE_SIZE * 2)
#define MAX_AUDIO_BITSTREAM_SIZE  (MPLVC_ONE_AUDIO_BUFFER_SIZE * MPLVC_AUDIO_BUFFER_NUM)
#define MAX_AUDIO_INPUT_QUEUE_SIZE  (16)
#define MAX_AUDIO_RETURN_QUEUE_SIZE (MAX_AUDIO_INPUT_QUEUE_SIZE * 2)
#define MAX_VOS_SIZE                (100)
#define MAX_BUFFER_MGR_SIZE         (8192)
#define MPLVC_EXT_MEM_SIZE          (MAX_VIDEO_BITSTREAM_SIZE + MAX_AUDIO_BITSTREAM_SIZE + MAX_BUFFER_MGR_SIZE)

// ring buffer manager
typedef struct
{
    kal_uint32 u4BitstreamSize;
    kal_uint32 u4Used; // in bytes
    kal_uint32 u4CollectingSize;
    kal_uint32 u4BitstreamThreshold;
    kal_uint32 u4ReadPos;
    kal_uint32 u4WritePos;
    kal_uint8 *pau1Buffer;
}MPLVC_BITSTEAM_MGR;

// video buffer manager
typedef struct
{
    VIDEO_CORE_RING_BUFFER_MGR_T    rInputQMgr;
    MPLVC_BITSTEAM_MGR              rBitStreamMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T    rReturnQMgr;
    VIDEO_BUFFERHEADER_TYPE_T   rResendBufferHeader; // For resend half-frame
    kal_bool                    fgNeed2Resend;
    kal_bool                    fgWaitForPS;
}MPLVC_VIDEO_BUFFER_MGR_T;

// audio buffer manager
typedef struct 
{
    VIDEO_CORE_RING_BUFFER_MGR_T    rInputQMgr;
    MPLVC_BITSTEAM_MGR              rBitStreamMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T    rReturnQMgr;
}MPLVC_AUDIO_BUFFER_MGR_T;

typedef VIDEO_ERROR_TYPE_T (*PFN_EMPTYTHISBUFFER)(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader);
typedef VIDEO_ERROR_TYPE_T (*PFN_FILLTHISBUFFER)(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader);
typedef struct
{
    mpl_clipper_t rItf;
    mpl_clipper_client_t rMplClient;
    mpl_clipper_open_t rOpenInfo;

#if defined(__VE_TRANSFORMATION_INFO__)
    SPIF_TRANSFORMATION_INFO_T rTransformInfo;
#endif

    MPLVC_STATE_T eState;
    kal_eventgrpid eEvent;
    MPLVC_COMP_STATE_T eSourceState;
    MPLVC_COMP_STATE_T eMuxerState;

    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo;
    kal_timerid rTimerID;
    kal_bool    fgStartWakeUpTimer;
    kal_mutexid rTimerMutexID;
    kal_mutexid rMainMutexID;
    
    // Source
    VIDEO_COMPONENT_MI_TYPE_T *prSourceHandle;
    void *prSourceCntx; // Pointer to SRC_PRIVDER_CONTEXT_T
    VIDEO_CALLBACK_TYPE_T rSourceCallback;
    SPIF_VIDEO_STREAM_INFO_T rSPVideoStream;
    SPIF_AUDIO_STREAM_INFO_T rSPAudioStream;
    kal_uint8 u1VideoStreamIdx;
    kal_uint8 u1AudioStreamIdx;
    SP_FILE_TYPE_T eSourceContainerType;

    // Audio
    Media_Format eAudioFormat;
    kal_bool fgRecordAudio;
    kal_uint32 u4AudioFrameSize;        /* in byte */
    kal_uint32 u4AudioFrameDuration;    /* in millisecond */
    kal_uint32 u4AudioBitRate;          /* in bit */
    kal_uint32 u4AudioSampleRate;
    kal_uint32 u4AudioChannelNum;
    kal_uint32 u4AudioBitPerSample;

    // Video
    VIDEO_ENCODER_TYPE_T eEncoderType;
    kal_uint32 u4EncoderFrameRate;
    kal_uint32 u4EncoderBitRate;
    kal_uint32 u4FrameWidth;
    kal_uint32 u4FrameHeight;
    
    // Muxer
    VIDEO_COMPONENT_TYPE_T *prMuxerHandle;
    kal_uint8 *pu1MuxerMemAddr;
    kal_uint32 u4MuxerMemSize;
    MUXER_CONTAINER_TYPE_T eMuxerContainerType;
    MUXER_SCENARIO_T eMuxerScenario;

    // Misc.
    PFN_EMPTYTHISBUFFER pfnEmptyThisBuffer;
    PFN_FILLTHISBUFFER pfnFillThisBuffer;
    kal_uint64 u8BaseFrameTime;
    kal_uint32 u4ClipDuration;
    kal_bool fgSeekable;
    kal_bool fgDiskFull;
    kal_bool fgErrorOfSaveCommandReported;
    kal_bool fgProcessing;
    kal_bool fgCanceled;
    kal_bool fgStopped;
    kal_bool fgDoFileMerge;
}MPLVC_MANAGER_T;

// global buffer manager
typedef struct
{
    MPLVC_VIDEO_BUFFER_MGR_T rVideoBufferMgr;
    MPLVC_AUDIO_BUFFER_MGR_T rAudioBufferMgr;

    //
    kal_uint8           au1VOSBuffer[MAX_VOS_SIZE]; // TODO:
    H264_ENC_CONF_REC   rH264Configuration;
    
    MPLVC_MANAGER_T *prMplvcMgr;
    kal_mutexid     rMutexID;

    kal_uint32 u4VProgress;
    kal_uint32 u4AProgress; 
    
    // Buffer header
    VIDEO_BUFFERHEADER_TYPE_T arVideoInputQ[MAX_VIDEO_INPUT_QUEUE_SIZE];
    VIDEO_BUFFERHEADER_TYPE_T arVideoReturnQ[MAX_VIDEO_RETURN_QUEUE_SIZE];
    VIDEO_BUFFERHEADER_TYPE_T arAudioInputQ[MAX_AUDIO_INPUT_QUEUE_SIZE];
    VIDEO_BUFFERHEADER_TYPE_T arAudioReturnQ[MAX_AUDIO_RETURN_QUEUE_SIZE];
}MPLVC_BUFFER_MGR_T;

#define MEDIA_ERR_RTN(stmt)   \
    eMError = ##stmt;    \
    if (eMError !=  MED_S_OK)    \
    {   \
        return eMError;  \
    }

#define MEDIA_ERRLOG_RTN(stmt)   \
    eMError = ##stmt;    \
    if (eMError !=  MED_S_OK)    \
    {   \
        kal_trace(TRACE_GROUP_1, MPLVC_TRC_MEDIA_ERROR, eMError, __LINE__); \
        return eMError;  \
    }

#endif
