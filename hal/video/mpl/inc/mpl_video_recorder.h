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
 * mpl_video_recorder.h
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * This file is the internal header file of the Media Porting Layer of video recorder.
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
 * 12 24 2013 tofar.huang
 * removed!
 * 	.
 * 
 * 08 24 2012 pibben.tung
 * removed!
 * .
 *
 * 07 09 2012 pibben.tung
 * removed!
 * .
 *
 * 06 13 2012 pibben.tung
 * removed!
 * .
 *
 * 04 02 2012 pibben.tung
 * removed!
 * .
 *
 * 03 21 2012 leroy.lin
 * removed!
 * .
 *
 * 02 13 2012 leroy.lin
 * removed!
 * .
 *
 * 01 31 2012 leroy.lin
 * removed!
 * .
 *
 * 01 31 2012 leroy.lin
 * removed!
 * .
 *
 * 12 14 2011 leroy.lin
 * removed!
 * .
 *
 * 12 06 2011 leroy.lin
 * removed!
 * .
 *
 * 10 18 2011 leroy.lin
 * removed!
 * .
 *
 * 09 16 2011 leroy.lin
 * removed!
 * .
 *
 * 08 26 2011 leroy.lin
 * removed!
 * .
 *
 * 08 17 2011 leroy.lin
 * removed!
 * .
 *
 * 08 15 2011 leroy.lin
 * removed!
 * .
 *
 * 08 09 2011 leroy.lin
 * removed!
 * .
 *
 * 08 04 2011 leroy.lin
 * removed!
 * .
 *
 * 07 27 2011 leroy.lin
 * removed!
 * .
 *
 * 07 26 2011 leroy.lin
 * removed!
 * .
 *
 * 07 13 2011 leroy.lin
 * NULL
 * Correct control flow so that Source can have frame buffer before IDP tries to get frame buffer.
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MPL_VIDEO_RECORDER_H
#define MPL_VIDEO_RECORDER_H

#include "drv_features_video.h"
#include "mpl_common.h"
#include "mpl_recorder.h"
#include "kal_public_defs.h"
#include "video_types_v2.h"
#include "video_muxer_if_v2.h"


#define MPLVR_FILE_NAME_ALIAS           "MPLVR"


#define MPLVR_EVENT_SOURCE_COMPLETE     ((kal_uint32)0x00000001)
#define MPLVR_EVENT_SOURCE_ERROR        ((kal_uint32)0x00000002)
#define MPLVR_EVENT_SOURCE_ALL          (MPLVR_EVENT_SOURCE_COMPLETE | MPLVR_EVENT_SOURCE_ERROR)

#define MPLVR_EVENT_ENCODER_COMPLETE    ((kal_uint32)0x00000010)
#define MPLVR_EVENT_ENCODER_ERROR       ((kal_uint32)0x00000020)
#define MPLVR_EVENT_ENCODER_ALL         (MPLVR_EVENT_ENCODER_COMPLETE | MPLVR_EVENT_ENCODER_ERROR)

#define MPLVR_EVENT_MUXER_COMPLETE      ((kal_uint32)0x00000100)
#define MPLVR_EVENT_MUXER_ERROR         ((kal_uint32)0x00000200)
#define MPLVR_EVENT_MUXER_ALL           (MPLVR_EVENT_MUXER_COMPLETE | MPLVR_EVENT_MUXER_ERROR)
#define MPLVR_EVENT_MUXER_ABORT         ((kal_uint32)0x00000400)
// The event MPLVR_EVENT_MUXER_ABORT is set in the Muxer's callback function
// of the abort_saving() API.  It can be better named a more descriptive name,
// and this name is used simply because it is shorter.


#define MPLVR_TIME_SCALE_MILLISECOND    1000
#define MPLVR_TIME_SCALE_MICROSECOND    1000000


// FIXME: Use audio API for the following definitions.
#define MPLVR_AUDIO_SAMPLING_RATE_8000  0x0B

/* 0x03 = DSP AMR 12.20 type */
#define MPLVR_AUDIO_AMR_TYPE            0x03
#define MPLVR_AUDIO_PCM_TYPE            0


typedef void (*PFN_AUDIO_CALLBACK_T)(Media_Event event);


typedef enum
{
    MPLVR_STATE_CLOSED = 0,
    MPLVR_STATE_OPENED,
    MPLVR_STATE_RECORDING,
    MPLVR_STATE_PAUSED,
    MPLVR_STATE_RECORDING_AUDIO,
    MPLVR_STATE_STOPPED,
    MPLVR_STATE_SAVING_FILE,
    MPLVR_STATE_ABORTING_SAVING_FILE,
    MPLVR_STATE_UNKNOWN = 0x1FFFFFFF
} MPLVR_STATE_T;


typedef enum
{
    MPLVR_AUDIO_STATE_CLOSED = 0,
    MPLVR_AUDIO_STATE_OPENED,
    MPLVR_AUDIO_STATE_RUNNING,
    MPLVR_AUDIO_STATE_PAUSED,
    MPLVR_AUDIO_STATE_STOPPED,
    MPLVR_AUDIO_STATE_UNKNOWN = 0x1FFFFFFF
} MPLVR_AUDIO_STATE_T;


typedef enum
{
    MPLVR_VIDEO_STATE_CLOSED = 0,
    MPLVR_VIDEO_STATE_OPENED,
    MPLVR_VIDEO_STATE_IDLE,
    MPLVR_VIDEO_STATE_RUNNING,
    MPLVR_VIDEO_STATE_STOPPED,
    MPLVR_VIDEO_STATE_UNKNOWN = 0x1FFFFFFF
} MPLVR_VIDEO_STATE_T;


typedef enum
{
    MPLVR_MUXER_STATE_CLOSED = 0,
    MPLVR_MUXER_STATE_OPENED,
    MPLVR_MUXER_STATE_RUNNING,
    MPLVR_MUXER_STATE_STOPPED,
    MPLVR_MUXER_STATE_UNKNOWN = 0x1FFFFFFF
} MPLVR_MUXER_STATE_T;


typedef void (*PFN_MPLVR_REDIRECTION_T)(kal_uint32 u4Param1, kal_uint32 u4Param2);


typedef struct
{
    LOCAL_PARA_HDR
    PFN_MPLVR_REDIRECTION_T pfnRedirect;
    kal_uint32 u4Param1;
    kal_uint32 u4Param2;
} MPLVR_ASYNC_CALL_T;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


typedef struct
{
    mpl_recorder_t *prInterface;
    mpl_recorder_client_t *prClient;

    kal_eventgrpid eEvent;
    MPLVR_STATE_T eState;
    MPLVR_AUDIO_STATE_T eAudioState;
    MPLVR_VIDEO_STATE_T eVideoState;
    MPLVR_MUXER_STATE_T eMuxerState;
    // VIDEO_SCENARIO_T eScenario;

    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo;
    VIDEO_INTMEM_HANDLER_T *prIntMemInfo;
    kal_mutexid eMutex;  // To protect send audio buffer in 2 context. MED and AUDIO tasks

    // Video
    VIDEO_COMPONENT_TYPE_T *prSourceHandle;     // Interface to Source
    VIDEO_COMPONENT_TYPE_T *prEncoderHandle;    // Interface to Encoder
    VIDEO_COMPONENT_TYPE_T *prMuxerHandle;      // Interface to Muxer
    kal_uint8 *pu1VideoExtMemAddr;      /* external memory address */
    kal_uint32 u4VideoExtMemSize;       /* external memory size */
    VIDEO_ENCODER_TYPE_T eEncoderType;
    kal_uint32 u4EncoderFrameRate;
    kal_uint32 u4EncoderBitRate;

    kal_uint32 u4FrameWidth;
    kal_uint32 u4FrameHeight;
    kal_uint32 u4MinFreeSpace;

    #if 1 //[MAUI_03208340] Frame Rate Table user may be changed after opening for menu generation
    // parameters for open operation
    kal_uint32 u4format;
    kal_uint32 u4quality;
    kal_uint32 u4storage;
    kal_uint32 u4user;
    kal_uint32 u4eSoftwareRotator;
    kal_uint32 u4imagewidth;
    kal_uint32 u4imageheight;
    #endif

    // Muxer
    kal_uint8 *pu1MuxerMemAddr;
    kal_uint32 u4MuxerMemSize;
    MUXER_CONTAINER_TYPE_T eMuxerContainerType;

    // Audio
    kal_uint8 *pu1AudioMemAddr;         /* audio ring buffer */
    kal_uint32 u4AudioMemSize;          /* size of audio ring buffer in byte */
    kal_uint8 *pu1LastAudioAddr;        /* Address of last audio data sent to Muxer */
    kal_uint32 u4LastAudioSize;         /* Size of last audio data sent to Muxer */
    kal_uint32 u4AccuAudioDataTime;     /* Accumulated time from audio data in time scale 8000. */
    Media_Format eAudioFormat;
    kal_uint32 u4AudioSampleRate;
    kal_uint32 u4AudioChannelNum;
    kal_uint32 u4AudioBitPerSample;
    kal_uint32 u4AudioFrameDuration;    /* in millisecond */
    kal_uint32 u4AudioFrameSize;        /* in byte */
    kal_uint32 u4AudioBitRate;          /* in bit */
    kal_uint32 u4AudioDataThresholdInTwoByte;

    // Callback from aborting file saving/merge may run concurrently with file
    // saving/merge.  It is a good idea to have its own variable for error code.
    media_error_t eMediaErrorFromAbortCallback;

    // To implement synchronous API for stop(), pause(), and close().
    media_error_t eSynchronousMediaError;

#ifdef __VE_TIME_LAPSE_VIDEO_RECORDER__
    kal_uint32 u4EncodeOneofNSecond; // in micro second
    kal_uint32 u4PlaybackFps;
#endif
    kal_bool fgSynchronousCall;

    kal_bool fgRecordAudio;             /* for debugging */
    kal_bool fgRecordYuv;               /* for debugging and quick diagnosis of customer's problem */

    kal_bool fgErrorOfSaveCommandReported;
    kal_bool fgErrorOfStopCommandReported;
    kal_bool fgGeneralErrorReported;

    kal_bool fgDirectCoupledSensor;
#ifdef __VE_DCM_WITH_COMPRESSION__
    kal_bool fgInDCM;
#endif  // __VE_DCM_WITH_COMPRESSION__

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    MPL_RECORDER_ROTATION_ANGLE_T ePlaybackRotationAngle;  /* to support motion sensor */
#endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__

#ifdef __VE_STREAM_SERVER_SUPPORT__
	kal_uint8 u1VideoRTPHandle;
	kal_uint8 u1AudioRTPHandle;
#endif


} MPLVR_MANAGER_T;


// This is the external interface for MPL users.
// MPL users shall not include mp4_recorder.h.  Therefore, I would like to
// change construct_mp4_recorder() to MPL_ConstructRecorder(), and put the new
// interface in "interface/hal/video/mpl_recorder.h".
extern mpl_recorder_t* construct_mp4_recorder(mpl_recorder_client_t* mpl_recorder_client);
extern mpl_recorder_t* construct_avi_recorder(mpl_recorder_client_t* mpl_recorder_client);


#endif  // MPL_VIDEO_RECORDER_H
