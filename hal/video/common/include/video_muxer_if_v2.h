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
 *   video_muxer_if_v2.h
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
#ifndef __VIDEO_MUXER_IF_V2_H__
#define __VIDEO_MUXER_IF_V2_H__

#include "kal_public_defs.h"
#include "video_types_v2.h"
#include "l1audio.h"
#include "fs_type.h"

/****************************************
*  Common defines
****************************************/
typedef enum
{
    MUXER_SCENARIO_UNKNOWN  =   0,
    MUXER_SCENARIO_RECORD,
    MUXER_SCENARIO_CREATE_FILE,
    MUXER_SCENARIO_NUM
} MUXER_SCENARIO_T;

typedef enum
{
    MUXER_MUTEX_COMPONENT   =   0,
    MUXER_MUTEX_COMMON_STATE,
    MUXER_MUTEX_NUM
} MUXER_MUTEX_T;

typedef enum
{
    MUXER_CONTAINER_TYPE_UNKNOWN    =   0,
    MUXER_CONTAINER_MP4,
    MUXER_CONTAINER_AVI,
    MUXER_CONTAINER_RTP,
    MUXER_CONTAINER_TYPE_NUM
} MUXER_CONTAINER_TYPE_T;

//CW stands for clock-wise
typedef enum
{
    MUXER_ROTATE_0_CW = 0,
    MUXER_ROTATE_90_CW,
    MUXER_ROTATE_180_CW,
    MUXER_ROTATE_270_CW
} MUXER_ROTATION_ANGLE_T;

void MuxerInitResource(void);
void MuxerMainNonDCM(ilm_struct *prILM);

/****************************************
*  APIs for IL
****************************************/
typedef struct
{
    kal_uint32 u4VideoBitRate;
    kal_uint32 u4VideoFrameRate;
    kal_uint32 u4FrameWidth;
    kal_uint32 u4FrameHeight;
    VIDEO_ENCODER_TYPE_T eEncoderType;
    MUXER_ROTATION_ANGLE_T eRotateAngle;
    kal_bool fgHorizontallyMirror;
} MUXER_VIDEO_CONFIG_T;

typedef struct
{
    kal_uint32 u4AudioBitRate;
    kal_uint32 u4AudioFrameSize;
    kal_uint32 u4AudioFrameDuration;
    Media_Format eAudioFormat;
    kal_bool fgRecordAudio;
    kal_uint32 u4AudioSampleRate;
    kal_uint32 u4AudioChannelNum;
    kal_uint32 u4AudioBitPerSample;
} MUXER_AUDIO_CONFIG_T;

VIDEO_COMPONENT_TYPE_T* GetMuxerHandle(VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr);
VIDEO_ERROR_TYPE_T ReleaseMuxerHandle(VIDEO_COMPONENT_TYPE_T *prHandle);
VIDEO_ERROR_TYPE_T FillMuxerAudioBuffer(kal_uint8 *pu1AudioBuf, kal_uint32 u4AudioSize);
kal_uint32  GetMuxerMemorySize(const MUXER_CONTAINER_TYPE_T eType, MUXER_SCENARIO_T eScenario);

kal_bool MuxerIsTempFileExisted(MUXER_CONTAINER_TYPE_T eType, kal_wchar* pwszWorkingPath);
void MuxerDeleteTempFile(MUXER_CONTAINER_TYPE_T eType, kal_wchar* pwszWorkingPath);
kal_uint32 MuxerGetMinSpaceToRecord(MUXER_CONTAINER_TYPE_T eType, kal_uint32 u4EncodeWidth, kal_uint32 u4EncodeHeight);
kal_uint32 MuxerGetLeftOverOfVideoBitstream(MUXER_CONTAINER_TYPE_T eType);
kal_uint32 MuxerGetHeaderSizeOfAudioFile(MUXER_CONTAINER_TYPE_T eType);
void MuxerSetVideoWriteThreshold(MUXER_CONTAINER_TYPE_T eType, kal_uint32 u4WriteThreshold);
void MuxerSetAbortSaving(void);

/****************************************
*  APIs for adaptation layers
****************************************/
extern void* MuxerGetMemory(kal_uint32 u4MemSize, kal_bool fgCacheable);
extern void MuxerFreeMemory(void* pMemoryAddr);
void MuxerRemoveFileName(kal_wchar *pu2FileName);
void MuxerGetDiskInfo(const kal_wchar * const pau2WorkingPath, kal_uint32 * const pu4ClusterSize, kal_uint64 * const u8FreeDiskSize);

#ifdef __VE_STREAM_SERVER_SUPPORT__
kal_bool MuxerQueryStopState(void);
#endif

#define MuxerAdaptGetMemory(u4MemSize, fgCacheable) MuxerGetMemory(u4MemSize, fgCacheable)
#define MuxerAdaptFreeMemory(pMemoryAddr) MuxerFreeMemory(pMemoryAddr)
#define MuxerAdaptRemoveFileName(pu2FileName) MuxerRemoveFileName(pu2FileName)
#define MuxerAdaptQueryAbortSaving(void) MuxerQueryAbortSaving(void)
#define MuxerAdaptGetDiskInfo(pau2WorkingPath, pu4ClusterSize, u8FreeDiskSize) MuxerGetDiskInfo(pau2WorkingPath, pu4ClusterSize, u8FreeDiskSize)

/****************************************
*  Interface of adaptation layers
****************************************/
typedef struct
{
    kal_uint8*  pu1Addr;
    kal_uint32  u4Size;
    kal_bool    fgValid;
} MUXER_BUFFER_T;

//DataType of Muxer
#define MX_DATATYPE_UNKNOWN                 (0)
#define MX_DATATYPE_AUDIO                   (1)
#define MX_DATATYPE_VIDEO                   (2)
#define MX_DATATYPE_VIDEO_SEQUENCE_HEADER   (3)
#define MX_DATATYPE_ALL                     (4)
#define MX_DATATYPE_IDX                     (5)
#define MX_DATATYPE_DATA                    (6)
//

//FrameType of Muxer
#define MX_FRAMETYPE_UNKNOWN    (0)
#define MX_FRAMETYPE_INTRA      (1)
#define MX_FRAMETYPE_INTER      (2)
//

#define MAX_BUFFER_PARTITION 2
typedef struct
{
    kal_uint64  u8TimeStamp;
    kal_uint32  u4DataType;     //MX_DATATYPE_UNKNOWN
    kal_uint32  u4FrameType;    //MX_FRAMETYPE_UNKNOWN
    void *      pPrivateData;
    MUXER_BUFFER_T  arData[MAX_BUFFER_PARTITION];
} MUXER_PROCESS_PARAM_T;

typedef struct
{
    kal_uint32 u4DataType;
    kal_bool fgFlush;
} MUXER_WRITE_PARAM_T;

typedef struct
{
    // input
    kal_uint32 u4Width;
    kal_uint32 u4Height;

    // output
    kal_uint32 u4MinSpace;
} MUXER_GET_MIN_SPACE_T;

typedef struct
{
    VIDEO_ERROR_TYPE_T (*pfnOpen)(void);
    VIDEO_ERROR_TYPE_T (*pfnInit)(void);
    VIDEO_ERROR_TYPE_T (*pfnGetParam)(VIDEO_PARAM_TYPE_T , void *);
    VIDEO_ERROR_TYPE_T (*pfnSetParam)(VIDEO_PARAM_TYPE_T , void *);
    VIDEO_ERROR_TYPE_T (*pfnDirectlyGetParam)(VIDEO_PARAM_TYPE_T , void *);
    VIDEO_ERROR_TYPE_T (*pfnDirectlySetParam)(VIDEO_PARAM_TYPE_T , void *);
    VIDEO_ERROR_TYPE_T (*pfnProcessData)(MUXER_PROCESS_PARAM_T *);
    VIDEO_ERROR_TYPE_T (*pfnWriteData2File)(MUXER_WRITE_PARAM_T *);
    VIDEO_ERROR_TYPE_T (*pfnCreateFile)(void);
    VIDEO_ERROR_TYPE_T (*pfnDeInit)(void);
    VIDEO_ERROR_TYPE_T (*pfnClose)(void);
} MUXER_ADAPT_API_T;

typedef MUXER_ADAPT_API_T* (*PFN_GET_HANDLE)(void);

#define MUXER_EVNET_0                   (0x1 << 0)
#define MUXER_EVNET_1                   (0x1 << 1)
#define MUXER_EVNET_REACH_SIZE_LIMIT    (0x1 << 2)
#define MUXER_EVENT_NUM 2

#define MP4_EVENT_RDY_2_WRITE_AUDIO     MUXER_EVNET_0
#define MP4_EVENT_RDY_2_WRITE_VIDEO     MUXER_EVNET_1
#define MP4_EVENT_REACH_SIZE_LIMIT      MUXER_EVNET_REACH_SIZE_LIMIT
#define MP4_EVENT_RETURN_BUFFER         (0x1 << 3)
#define AVI_EVENT_RDY_2_WRITE_IDX       MUXER_EVNET_0
#define AVI_EVENT_RDY_2_WRITE_DATA      MUXER_EVNET_1

#define RTP_EVENT_RDY_2_SEND_VIDEO		MUXER_EVNET_0
#define RTP_EVENT_RDY_2_SEND_AUDIO		MUXER_EVNET_1
#define RTP_EVENT_RETURN_BUFFER         (0x1 << 3)


typedef void (*PFN_CALLBACK)(kal_uint32 u4Event, void* pParam);



#endif // __VIDEO_MUXER_IL_IF_V2_H__
