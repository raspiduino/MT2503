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
 *   source_provider_component.h
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
 ****************************************************************************/

#ifndef SOURCE_PROVIDER_COMPONENT_H
#define SOURCE_PROVIDER_COMPONENT_H

#include "video_types_v2.h"
#include "mpl_common.h"
#include "mpl_player.h"
#include "mpl_session_mem.h"
#include "video_codec_utility_v2.h"
#include "video_comm_component_v2.h"
#include "source_provider_if.h"


#define SP_MAX_FILE_NAME_LEN (MPL_MAX_FILE_NAME_LEN)
#define SP_CHK_INTEGRITY_BUF_LEN (20)
#define SP_DPL_OPEN_SLEEP_TICK (20)  // ticks
#define SP_V2SRC1 (MOD_VFILE)
#define SP_V2SRC2 (MOD_VSRC)
#define SP_MESSAGE_ID_1 (MSG_ID_SOURCE_PROVIDER_DATA_IND)
#define SP_MESSAGE_ID_2 (MSG_ID_VSRC_SOURCE_PROVIDER_DATA_IND)
#define SP_INVALID_TIME (-1)
#define SP_TRACK_DEFAULT (0xff)
#define SP_VIDEO_AUDIO_INPUT_PORT (0)
#define SP_TASK_MAX_PARSER_TIME (33)
#define SP_TASK_WAKE_UP_TICK (40)

#define SP_TRACE_FUNC_GROUP TRACE_GROUP_1
#define SP_TRACE_HIGH_GROUP TRACE_GROUP_1
#define SP_TRACE_LOW_GROUP TRACE_GROUP_3

#ifdef __VE_SP_LOG_HIGH__
#define SP_TRACE_FSAL_ERROR(Err1, Err2, Source) drv_trace4(SP_TRACE_HIGH_GROUP, SP_FSAL_ERROR, Err1, Err2, __LINE__, Source)
#define SP_TRACE_COMPONENT_ERROR(Err1, Err2, Handle) drv_trace4(SP_TRACE_HIGH_GROUP, SP_COMPONENT_ERROR, Err1, Err2, __LINE__, Handle)
#define SP_TRACE_PRV_FUNCTION_ERROR(Err1, Err2, Handle) drv_trace4(SP_TRACE_HIGH_GROUP, SP_PRV_FUNCTION_ERROR, Err1, Err2, __LINE__, Handle)
#define SP_TRACE_MEMORY_ERROR(Err1, Err2, Handle) drv_trace4(SP_TRACE_HIGH_GROUP, SP_MEMORY_ERROR, Err1, Err2, __LINE__, Handle)
#define SP_TRACE_PARAMETER_ERROR(Err1, Err2, Err3) drv_trace4(SP_TRACE_HIGH_GROUP, SP_PARAMETER_ERROR, Err1, Err2, Err3, __LINE__)
#define SP_TRACE_CONTAINER_TYPE_ERROR(Err1, Err2, Handle) drv_trace4(SP_TRACE_HIGH_GROUP, SP_CONTAINER_TYPE_ERROR, Err1, Err2, __LINE__, Handle)
#else
#define SP_TRACE_FSAL_ERROR(Err1, Err2, Source) do{}while(0);
#define SP_TRACE_COMPONENT_ERROR(Err1, Err2, Handle) do{}while(0);
#define SP_TRACE_PRV_FUNCTION_ERROR(Err1, Err2, Handle) do{}while(0);
#define SP_TRACE_MEMORY_ERROR(Err1, Err2, Handle) do{}while(0);
#define SP_TRACE_PARAMETER_ERROR(Err1, Err2, Err3) do{}while(0);
#define SP_TRACE_CONTAINER_TYPE_ERROR(Err1, Err2, Handle) do{}while(0);
#endif

typedef enum
{
    SOURCE_PROVIDER_MSG_COMMAND = 0,
    SOURCE_PROVIDER_MSG_FILLBUFFER,
    SOURCE_PROVIDER_MSG_EMPTYBUFFER,
    SOURCE_PROVIDER_MSG_WAKEUP,
    SOURCE_PROVIDER_MSG_SET_PARAM,
    SOURCE_PROVIDER_MSG_GET_PARAM,
    SOURCE_PROVIDER_MSG_WAKEUP_SRC_V,
    SOURCE_PROVIDER_MSG_TRIGGER_SRC_V,
    SOURCE_PROVIDER_MSG_SRC_V_MAIN
} SP_MESSAGE_T;

typedef enum
{
    SOURCE_PROVIDER_ACTION_NONE = 0x0,
    SOURCE_PROVIDER_ACTION_COMMAND,
    SOURCE_PROVIDER_ACTION_OUTPUT_BUFFER,
    SOURCE_PROVIDER_ACTION_OUTPUT_BITSTREAM_FULL,
    SOURCE_PROVIDER_ACTION_AUDIO_PARSER,
    SOURCE_PROVIDER_ACTION_SUBTITLE_PARSER,
    SOURCE_PROVIDER_ACTION_VIDEO_PARSER,    
    SOURCE_PROVIDER_ACTION_MAX
} SP_PROCESS_ACTION_T;

typedef enum
{
    SOURCE_PROVIDER_EG_STOP_RQ = 1 << 0
} SP_PROCESS_EVENT_GROUP_T;

/***************************
   For interanl
  ***************************/
typedef struct
{
    LOCAL_PARA_HDR 
    void *prHandle;
    kal_uint32 u4Param1;    
}SP_IND_T;

typedef struct
{
    VIDEO_CORE_RING_BUFFER_MGR_T rMgr;
    kal_mutexid rMutex;
    kal_uint32 u4Send;
    kal_uint32 u4UnSendNum;
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
    kal_uint64 u8MaxTime; //ms
    kal_uint64 u8MinTime; //ms
    #endif
}SP_BUFFER_HEADER_T;

typedef struct
{
    kal_uint32 u4StartAdd;
    kal_uint32 u4RealStartAdd;    
    kal_uint32 u4WriteAdd;
    kal_uint32 u4ReadAdd;
    kal_uint32 u4RealSize;
    kal_uint32 u4LeftSize1;
    kal_uint32 u4LeftSize2;
    kal_uint32 u4LockSize;
    kal_mutexid rMutex;
    kal_bool fgInitialized;
} SP_BITSTREAM_BUF_T;

typedef struct
{
    KAL_ADM_ID rAdmID;
    kal_mutexid rMutex;
} SP_PRIVATE_BUF_T;

typedef struct
{
    kal_uint32 u4CoreMem;
    kal_uint32 u4VideoMem;
    kal_uint32 u4AudioMem;
#ifdef __VE_SUBTITLE_SUPPORT__     
    kal_uint32 u4SubtitleMem;
#endif
} SPIF_PROVIDER_MEM_INFO_T;

typedef struct
{
    // Video full condition 
    kal_uint32 u4VLeftBitstreamBuf;
    kal_uint32 u4VLeftPrivateData;
    // Video Min. condition
    kal_uint32 u4VMinBitstreamBuf;
    kal_uint32 u4VMinBufHeader;
    // Video Each task exit condition
    kal_uint32 u4VExitValue;

    // Audio full condition 
    kal_uint32 u4ALeftBitstreamBuf;
    kal_uint32 u4ALeftPrivateData;
    // Audio Min. condition
    kal_uint32 u4AMinBitstreamBuf;
    kal_uint32 u4AMinBufHeader;
    // Audio Each task exit condition
    kal_uint32 u4AExitValue;   

#ifdef __VE_SUBTITLE_SUPPORT__
    // Subtitle full condition 
    kal_uint32 u4SLeftBitstreamBuf;
    kal_uint32 u4SLeftPrivateData;
    // Subtitle Min. condition
    kal_uint32 u4SMinBitstreamBuf;
    kal_uint32 u4SMinBufHeader;
    // Subtitle Each task exit condition
    kal_uint32 u4SExitValue;
#endif    
} SP_PARSER_PARAM_T;


/***************************
   For context
  ***************************/
typedef struct
{
    module_type eRunTask;
    kal_uint32 u4TaskMessageID;
} SP_TASK_INFO_T;

typedef struct
{
    kal_uint32 u4Addr; /* the start address of the file located */
    kal_uint32 u4Size; /* file size */
} SP_BUF_INFO_T;

typedef struct
{
    med_mode_enum eOpenType; /* media open type */
    SP_FILE_TYPE_T eFileType;  /* media file extension type */
    union{
        kal_wchar file_name[SP_MAX_FILE_NAME_LEN]; /* file name */
        SP_BUF_INFO_T rBuf;
    }u_src;        
} SP_SOURCE_INFO_T;

typedef struct
{
    void *pvHandle; /* med handle */
    MPL_SESSION_MEM_API_T *prAPI; /*med provider API*/
    MPL_SESSION_EMPTY_BUFFER_API_T *prEmptyAPI; /*med empty buffer API*/
} SP_MED_HANDLE_T;

typedef struct
{
    kal_uint64 u8StartTime[SOURCE_PROVIDER_PORT_MAX]; /* play start point, ms */
    kal_uint64 u8EndTime[SOURCE_PROVIDER_PORT_MAX];  /* play end point, ms */
    kal_uint64 u8CurrentTime[SOURCE_PROVIDER_PORT_MAX]; /* current parse time , ms */
    kal_bool fgSeekDone[SOURCE_PROVIDER_PORT_MAX];
    kal_bool fgSelect[SOURCE_PROVIDER_PORT_MAX];
    kal_uint8 u1Track[SOURCE_PROVIDER_PORT_MAX];
    kal_bool fgEof[SOURCE_PROVIDER_PORT_MAX];
    kal_bool fgParserError[SOURCE_PROVIDER_PORT_MAX];
    SP_CONTROL_FLAG_T u4ControlFlag[SOURCE_PROVIDER_PORT_MAX];
    void *pvControlData[SOURCE_PROVIDER_PORT_MAX];
    kal_bool fgAbort[SOURCE_PROVIDER_PORT_MAX];
    SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo;
    SPIF_AUDIO_STREAM_INFO_T *prAudioStreamInfo;
#ifdef __VE_SUBTITLE_SUPPORT__
    SPIF_SUBTITLE_STREAM_INFO_T *prSubtitleStreamInfo;
#endif
} SP_PLAYBACK_INFO_T;

typedef struct
{
    kal_bool fgWaitClose;
    kal_bool fgVideoTaskRun; /* SRC_V running */
    kal_bool fgVideoTaskMsg; /* message in SRC_V queue */
    kal_bool fgQuickClose;
    kal_uint8 u1TriggerVideoTask; 
    
} SP_CONTROL_INFO_T;

typedef struct
{
    // component
    void *pvExtMemComponent;
    VIDEO_EXTMEM_HANDLER_T *prComponentHandle;

    //Source
    void *pvSrcPrvAdm;
    KAL_ADM_ID rSrcPrvAdmId;

    void *pvBufHeader[SOURCE_PROVIDER_PORT_MAX];
    SP_BUFFER_HEADER_T rBufHeader[SOURCE_PROVIDER_PORT_MAX];
    
    void *pvPrivateData[SOURCE_PROVIDER_PORT_MAX];
    SP_PRIVATE_BUF_T rPrivateData[SOURCE_PROVIDER_PORT_MAX];
    
    void *pvBitstreamBuf[SOURCE_PROVIDER_PORT_MAX];
    SP_BITSTREAM_BUF_T rBitstreamBuf[SOURCE_PROVIDER_PORT_MAX];
} SP_MEM_INFO_T;

typedef struct
{
    kal_uint32 u4ItemInputQ;
    kal_uint32 u4ItemOutputQ;
} SP_DEBUG_INFO_T;

typedef struct
{
    kal_uint32 u4EmptyCount[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4HeaderFull[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4PrivateFull[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4BitstreamFull[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4MixLeftHeader[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4MixLeftPrivate[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4MixLeftBitstream[SOURCE_PROVIDER_PORT_MAX];
    
    kal_uint32 u4Tirgger[SOURCE_PROVIDER_MSG_WAKEUP_SRC_V];
    
    kal_uint32 u4ExitEntry[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4ExitCount[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4ExitTimer[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4ExitData[SOURCE_PROVIDER_PORT_MAX];    
    kal_uint32 u4ExitBufferlow[SOURCE_PROVIDER_PORT_MAX]; 
    kal_uint32 u4ExitOther[SOURCE_PROVIDER_PORT_MAX];
    kal_uint32 u4ExitOtherWaitRes[SOURCE_PROVIDER_PORT_MAX];
    
} SP_PROFILE_INFO_T;

typedef struct
{
    SP_TASK_INFO_T rTaskInfo;
    
    // from MED
    SP_TRACK_T eTrack;
    SP_MED_HANDLE_T rMedHandle;
    SP_SOURCE_INFO_T rSrcInfo;

    // from provider
    SPIF_PROVIDER_MEM_INFO_T rPrvReqMem;
    SPIF_PROVIDER_HANDLE_T rPrvHandle;
    SP_PARSER_PARAM_T *prPrvParserParam;

    //SP_FILE_TYPE_T eRealFileType;
    SP_MEM_INFO_T rMemInfo;
    VIDEO_COMM_STATE_T rCommState;
    SPIF_STREAM_INFO_T rStreamInfo[SOURCE_PROVIDER_PORT_MAX];
    SP_CAPABILITY_T eCapabiltiy;

    kal_mutexid rSrcVBufHeaderMutex;
    kal_mutexid rSrcVBitstreamMutex;
    kal_mutexid rSrcVPrivateDataMutex;
    kal_mutexid rSrcABufHeaderMutex;
    kal_mutexid rSrcABitstreamMutex;
    kal_timerid rTimerID; /* wake up for SRC task */
    kal_bool fgSetWakeupTimer;

    // can reset
    SP_PLAYBACK_INFO_T rPlayInfo;
    SP_CONTROL_INFO_T rControlInfo;
#ifdef __VE_SP_DBG__
    SP_DEBUG_INFO_T rDebugInfo;
#endif
#ifdef __VE_SP_PROFILE__
    SP_PROFILE_INFO_T rProfile;
#endif
} SRC_PRIVDER_CONTEXT_T;

// This macro works only when "x" is 2^n.
#define SP_ROUND_UP_TO_POWER_OF_TWO(data,x)                                 \
    (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))

#endif //SOURCE_PROVIDER_COMPONENT_H
