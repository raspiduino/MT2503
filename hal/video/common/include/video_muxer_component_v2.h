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
 *   video_muxer_component_v2.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 ****************************************************************************/
#include "drv_features_video.h"

#ifndef __VIDEO_MUXER_COMPONENT_V2_H__
#define __VIDEO_MUXER_COMPONENT_V2_H__
#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "video_muxer_if_v2.h"
#include "kal_public_defs.h"
#include "video_muxer_if_v2.h"
#include "video_codec_utility_v2.h"

#define MUXER_AUDIO_PORT 0
#define MUXER_VIDEO_PORT 1

typedef enum
{
    MUXER_CLOSED = 0,
    MUXER_CLOSING,
    MUXER_INITIALIZED,
    MUXER_IDLING,
    MUXER_RUNNING,
    MUXER_STOPPING,
    MUXER_STOPPED,
    MUXER_STATE_NUM
} MUXER_STATE_T;

typedef enum
{
    //for processing command/input queue
    MX_NO_COMMAND,
    MX_PROCESSED_COMMAND,
    MX_NO_BITSTREAM,
    MX_SENT_BITSTREAM_2_ADAPT
} MUXER_RETURN_T;

typedef struct
{
    LOCAL_PARA_HDR
} MUXER_IND_T;

typedef struct
{
    MUXER_VIDEO_CONFIG_T rVideoConfig;
    MUXER_AUDIO_CONFIG_T rAudioConfig;
    kal_uint64  u8SizeLimit;
    kal_uint32  u4TimeLimit;
    kal_uint32  u4VideoWriteThreshold;
    kal_wchar   *pawszWorkingPath;
    kal_wchar   *pawszFileNamePath;
    MUXER_SCENARIO_T    eScenario;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    kal_uint32  u4TLFrameRate;
#endif

#ifdef __VE_SUPPORT_RTP_MUXER_ADAPTER__
	kal_uint8  u1VidRTPHandle;
	kal_uint8  u1AudRTPHandle;
#endif


} MUXER_ADAPT_SETTING_T;

typedef enum
{
    MUXER_ACT_PROCESS_VIDEO = 0,
    MUXER_ACT_PROCESS_AUDIO,
    MUXER_ACT_PROCESS_DATA,
    MUXER_ACT_CREATE_FILE,
    MUXER_ACT_SUSPENDING,
} MUXER_ACTIVITY_T;

typedef struct
{
    kal_uint64 u8TimeStamp;
    kal_uint8* pu1BufferAddr;
    kal_uint32 u4Size;
    VIDEO_BUFFERFLAG_TYPE_T eFlag;
}MUXER_RESENDQ_ITEM_T;

typedef struct
{
    VIDEO_CORE_RING_BUFFER_MGR_T rCoreMgr;
    kal_uint8* pu1BufferAddr;
    kal_uint32 u4QueueNumber;
    kal_bool fgInit;
}MUXER_RESENDQ_MGR_T;

typedef struct
{
    VIDEO_COMM_STATE_T rCommState;
    MUXER_ADAPT_SETTING_T rAdaptSettings;
    MUXER_RESENDQ_MGR_T rVideoResendQMgr;
    MUXER_RESENDQ_MGR_T rAudioResendQMgr;
    MUXER_BUFFER_T arVideoData[MAX_BUFFER_PARTITION];

    VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr;
    MUXER_CONTAINER_TYPE_T  eAdaptType;
    MUXER_ADAPT_API_T*  prAdaptAPI;

    kal_uint32  u4MemAddr;
    kal_uint32  u4MemSize;
    KAL_ADM_ID  rADMID;
    kal_eventgrpid rEventGroupID;

    kal_uint32  u4VideoPort;
    kal_uint32  u4AudioPort;
    kal_uint32  au4EventDataType[MUXER_EVENT_NUM];
    kal_bool    fgInitAdaptation;
    kal_bool    fgInitDriver;
    kal_bool    fgCreatedFile;
    kal_bool    fgAbortSavingOk;

    MUXER_STATE_T   eInternalState;
    kal_mutexid rMuxerMutex;
    kal_mutexid rMuxerMutex2;
    kal_timerid rTimerID;
    kal_bool    fgStartWakeUpTimer;
    kal_bool    fgAbortSaving;
    kal_bool    fgCompClosed;
#ifdef __VE_STREAM_SERVER_SUPPORT__
    kal_bool    fgGotStopCommand;
#endif

    
} MUXER_MGR_T;

#endif // __VIDEO_MUXER_COMPONENT_V2_H__
