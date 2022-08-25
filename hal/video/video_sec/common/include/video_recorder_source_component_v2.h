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
 *   video_recorder_source_component_v2.h
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
#ifndef VIDEO_RECORDER_SOURCE_COMPONENT_V2_H
#define VIDEO_RECORDER_SOURCE_COMPONENT_V2_H


#include "drv_features_video.h"             // for __VE_SLIM_RECORDER_SOURCE__


#ifdef __VE_VIDEO_ARCHI_V2__


#if !defined(__VE_SLIM_RECORDER_SOURCE__)


/******************************************************************************
*******************************************************************************
* Here begins the non-slim version of Source.
*******************************************************************************
******************************************************************************/


#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "kal_general_types.h"
#include "video_buffer_management_v2.h"


#define VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM  16


typedef enum
{
    VIDEO_RECORDER_SOURCE_INIT,
    VIDEO_RECORDER_SOURCE_INIT_COMPLETE_BUFF,
    VIDEO_RECORDER_SOURCE_INIT_RECV_IDLE_CMD,
    VIDEO_RECORDER_SOURCE_IDLE,
    VIDEO_RECORDER_SOURCE_PRE_RUN,
    VIDEO_RECORDER_SOURCE_RUN,
    VIDEO_RECORDER_SOURCE_PRE_YUV_RUN,
    VIDEO_RECORDER_SOURCE_YUV_RUN,
    VIDEO_RECORDER_SOURCE_STOP
} VIDEO_RECORDER_SOURCE_INT_STATE_T;


// The following definitions are used in VIDEO_RECORDER_INPUT_BUFFER_T::u1BuffStatus[].
#define VRSRC_BUFFER_STATUS_FREE                        0
#define VRSRC_BUFFER_STATUS_IN_USE_WITHOUT_TIMESTAMP    1
#define VRSRC_BUFFER_STATUS_IN_USE_WITH_TIMESTAMP       2
#define VRSRC_MIN_NUM_OF_FRAME_BUFFER                   4


// The following definitions are used in VIDEO_RECORDER_INPUT_BUFFER_T::u1EncodeFlag[].
#define VRSRC_BUFFER_STATUS_INVALID                     0
#define VRSRC_BUFFER_STATUS_VALID                       1

typedef struct
{
    kal_uint64 au8TimeStamp[VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM];
    kal_uint32 u4EachBuffSize;
    kal_uint8 *pu1BuffAddr[VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM];
    kal_uint8 u1BuffStatus[VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM];
// #ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    kal_uint8 u1EncodeFlag[VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM];
// #endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    kal_uint32 u4ReadIdx;       // encoder return index
    kal_uint32 u4WriteIdx;      // send to encoder index
    kal_uint32 u4YUVWriteIdx;   // YUV fill index (from IDP)
    kal_uint32 u4YUVReadIdx;    // YUV fill index (from IDP)
    kal_uint32 u4DummyIdx;
    kal_uint32 u4BuffNum;
} VIDEO_RECORDER_INPUT_BUFFER_T;


typedef struct
{
    VIDEO_COMM_STATE_T rCommState;

    VIDEO_RECORDER_INPUT_BUFFER_T rInputBuffer;    // frame buffer control

    // state control
    VIDEO_RECORDER_SOURCE_INT_STATE_T eIntState;
    kal_uint32 u4KeepInterval;    //3 // 3 means 3 keep1 and drop 2, 1 means all keep
    kal_uint32 u4CurrInterval;
    kal_bool fgGetSourceBuffer;  // in order to check whether IDP and YUV source get buffer concurrency

    kal_uint8 *pu1YUVBuffer;
    kal_uint32 u4YUVInterval;
    DCL_HANDLE rGptHandle;

    // connected component information: Encoder
    PFN_EMPTY_THIS_BUFFER_T pfnEncoderEmptyThisBuffer;
    kal_uint32 u4DataPortIdx;               // the output port index connected to encoder component
    kal_uint32 u4DataPortConnectedIdx; // encoder component input port index

    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo;
    kal_uint32 u4MaxInsufficientFrames;         // Maximum number of insufficient frames
    kal_bool fgStopInstantly;                   // Stop immediately without returning all YUV from Encoder
    kal_bool fgEofSent;             // It indicates whether or not EOF has been sent to Encoder.
} VIDEO_RECORDER_SOURCE_STATE_T;


#else  // !defined(__VE_SLIM_RECORDER_SOURCE__)


/******************************************************************************
*******************************************************************************
* Here begins the slim version of Source.
*******************************************************************************
******************************************************************************/


#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "kal_general_types.h"
#include "video_buffer_management_v2.h"
#include "video_codec_mem_v2.h"


#define VRSRC_MIN_NUM_OF_FRAME_BUFFER                   2
#define VRSRC_MAX_NUM_OF_FRAME_BUFFER          VIDEO_ENC_MAX_YUV_FRAME_NUM


// There shall be at most two frames in IDP at any particular moment.
// Therefore, VRSRC_MAX_REF_COUNT can be defined to be two.
// Five is more like a number chosen at my will. :)
#define VRSRC_MAX_REF_COUNT                             0x05

// The following definitions are used in VRSRC_FRAME_BUFFER_T::au1Status[].
#define VRSRC_BUFFER_STATUS_FREE                        0
#define VRSRC_BUFFER_STATUS_UNKNOWN                     1
#define VRSRC_BUFFER_STATUS_JUNK                        2
#define VRSRC_BUFFER_STATUS_JEWEL                       3


typedef struct
{
    kal_uint64 au8TimeStamp[VRSRC_MAX_NUM_OF_FRAME_BUFFER];
    kal_uint8 *apu1Address[VRSRC_MAX_NUM_OF_FRAME_BUFFER];
    kal_uint8 au1Status[VRSRC_MAX_NUM_OF_FRAME_BUFFER];
    kal_uint8 au1RefCount[VRSRC_MAX_NUM_OF_FRAME_BUFFER];   // reference count
    kal_uint32 u4EachBufferSize;
    kal_uint32 u4IdxIdpGet;             /// the index to be obtained by IDP
    kal_uint32 u4IdxIdpRet;             /// the index to be returned by IDP
    // kal_uint32 u4IdxEncGet;             /// the index to be obtained by Encoder
    kal_uint32 u4IdxEncRet;          /// the index to be returned by Encoder
    kal_uint32 u4TotalBuffer;
    kal_uint32 u4PeakRefCount;          /// Peak value of reference count
    kal_uint32 u4Detention;             /// How many frame buffer is detained in Encoder?
} VRSRC_FRAME_BUFFER_T;


typedef enum
{
    VRSRC_ENDING_NONE,                          /// In the INIT or IDLE state, and no STOP command received
    VRSRC_ENDING_GOT_STOP_BUT_EOF_NOT_SENT,
    VRSRC_ENDING_GOT_STOP_AND_EOF_SENT
} VRSRC_ENDING_T;


typedef struct
{
    VIDEO_COMM_STATE_T rCommState;

    VRSRC_FRAME_BUFFER_T rFrameBuffer;              /// frame buffer manager

    // connected component information: Encoder
    PFN_EMPTY_THIS_BUFFER_T pfnEncoderEmptyThisBuffer;
    kal_uint32 u4DataPortIdx;                       /// the output port index connected to encoder component
    kal_uint32 u4DataPortConnectedIdx;              /// encoder component input port index

    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo;
    kal_uint32 u4MaxInsufficientFrames;             /// Maximum number of insufficient frames
    VRSRC_ENDING_T eEnding;

    kal_uint8 *pu1BufferAddressFromEncoder;         /// Keep the address return from Encoder for use in HISR
    kal_eventgrpid eActivateSrcHisrEvent;           /// To make encoder return buffer HISR is executed

#ifdef __VE_VIDEO_VT_SUPPORT__
    kal_uint8 *pu1YUVBuffer;  // VT image view
    kal_uint32 u4YUVInterval; // VT image view duration in 10 ms unit (GPT time base)
    DCL_HANDLE rGptHandle;
#endif
    kal_bool fgFrameBufferConfigured;               /// Has the frame buffer been configured?
    kal_bool fgTrespass;                            /// Check for concurrent access
    kal_bool fgSetToIdleState;                      /// Shall it set to IDLE after the IDLE command is received?
} VRSRC_MANAGER_T;



#endif  // !defined(__VE_SLIM_RECORDER_SOURCE__)


#endif  // __VE_VIDEO_ARCHI_V2__


#endif  // VIDEO_RECORDER_SOURCE_COMPONENT_V2_H

