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
 *   mp4_muxer_adapter_v2.h
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
 ****************************************************************************/
#include "drv_features_video.h"

#ifndef __MP4_MUXER_ADAPTER_V2_H__
#define __MP4_MUXER_ADAPTER_V2_H__

#include "fsal.h"
#include "fs_type.h"

#include "video_muxer_if_v2.h"
#include "mp4_muxer_adapter_if_v2.h"
#include "mp4_muxer_adapter_buffer_management_v2.h"
#include "video_buffer_management_v2.h"

#define __ENABLE_STBL_PSEUDO_MERGE__
//#define __ENABLE_DEBUG__

/******************************************************************************
* Macro Definition
******************************************************************************/
#define _MP4_TEMP_FILE_ATTRIBUTES       (FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)

// Temp file list
#define _MP4_VIDEO_FILE             (L"~mp4v.tmp")              // video data file
#define _MP4_AUDIO_FILE             (L"~mp4a.tmp")              // audio data file
#define _MP4_TEMP_META_FILE         (L"~mp4tm.tmp")             // temp meta file
#define _MP4_REAL_META_FILE         (L"~mp4rm.tmp")             // real meta file
#define _MP4_VIDEO_STTS_FILE        (L"~mp4v_stts.tmp")         // video stts file
#define _MP4_VIDEO_STSZ_FILE        (L"~mp4v_stsz.tmp")         // video stsz file
#define _MP4_VIDEO_STCO_FILE        (L"~mp4v_stco.tmp")         // video stco file
#define _MP4_VIDEO_STSS_FILE        (L"~mp4v_stss.tmp")         // video stss file

#define MAX_UNFINISHED_DATA         4       // for size-limited, unfinished video data
#define MAX_AUDIO_BUFFER_SECTION    2
#define TIME_PER_AMR_FRAME          20000   // AMR: 20ms per frame
#define SIZE_PER_AMR_FRAME          32      // AMR: 32 bytes per frame

/******************************************************************************
* Enum Definition
******************************************************************************/
typedef enum
{
    MP4_VIDEO_FILE = 0,
    MP4_AUDIO_FILE,
    MP4_TEMP_META_FILE,
    MP4_REAL_META_FILE,
    MP4_VIDEO_STTS_FILE,
    MP4_VIDEO_STSZ_FILE,
    MP4_VIDEO_STCO_FILE,
    MP4_VIDEO_STSS_FILE,
    MP4_NUM_OF_FILE,
    MP4_MAX_OF_FILE = 0x1FFFFFFF
} MP4_FILE_HANDLE_TYPE_T;

/******************************************************************************
* Structure Definition
******************************************************************************/
typedef struct
{
    STFSAL rFile[MP4_NUM_OF_FILE];
} MP4_FILE_MGR_T;

typedef struct
{
    kal_uint8*  pu1Addr;
    kal_uint32  u4Size;
    kal_bool    fgValid;
    kal_uint32  u4OriSize;
} AUDIO_BUFFER_T;

typedef struct
{
    AUDIO_BUFFER_T      arAudioBuf[MAX_AUDIO_BUFFER_SECTION];
    kal_uint32          u4AudioBufRIdx;
    kal_uint32          u4AudioBufWIdx;
    kal_uint32          u4AudioTotalSize;
} MP4_AUDIO_MGR_T;

typedef struct
{
    kal_uint32 u4AccuBitDataSize;
    kal_uint32 u4AccuBitDataDuration;
    kal_uint32 u4PeakBitDataSize;
    kal_uint32 u4PeakBitDataDuration;
} MP4_INFO_T;

typedef struct
{
    kal_uint8*  pu1Addr;
    kal_uint32  u4Size;
}MP4_UNFINISHED_DATA_T;

typedef struct
{
    MP4_BIT_CTRL_MGR_T  rBitCtrlMgr;            // bitstream buffer control unit

    MUXER_SCENARIO_T    eScenario;
    MUXER_AUDIO_CONFIG_T  rAudioConfig;         // audio configuration
    MUXER_VIDEO_CONFIG_T  rVideoConfig;         // video configuration
    MP4_INFO_T          rInfo;                  // for accounting

    kal_wchar           *pau2FilePath;          // recorded file path
    kal_wchar           *pau2WorkingPath;       // recorded working path

    MP4_FILE_MGR_T      rMp4FileMgr;            // file handle mgr for managing all opened files
    PFN_CALLBACK        pfnCallBack;

    MUXER_PROCESS_PARAM_T rParameterSet;
    MP4_AUDIO_MGR_T     rAudioMgr;
    MP4_UNFINISHED_DATA_T  rUnfinishedData[MAX_UNFINISHED_DATA];
    kal_uint32          u4AudioLeftOver;
    kal_uint32          u4TotalVFrames;         // total number of received video frames
    kal_uint32          u4UnfinishedDataIdx;
    kal_bool            fgGetParameterSet;      // for keeping parameter set

    kal_uint64          u8FileSizeLimit;
    kal_uint64          u8CurrentFileSize;
    kal_uint64          u8FreeDiskSize;
    kal_uint32          u4MinSpace2Record;
    kal_uint32          u4ClusterSize;
    kal_uint32          u4TimeLimit;
    kal_bool            fgEnableSizeLimit;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    kal_uint32          u4TLFrameDuration;
#endif
} MP4_MUXER_ADAPTER_STATE_T;

/******************************************************************************
* Macro function
******************************************************************************/
#define FSAL_ERR_RTN(prFile, stmt)    \
    if (##stmt !=  FSAL_OK)                \
    {   \
        return MP4_FSALFailHdlr(prFile); \
    }

#define VIDEO_ERR_RTN(stmt)   \
    eError = ##stmt;    \
    if (eError !=  VIDEO_ERROR_NONE)    \
    {   \
        return eError;  \
    }

#define VIDEO_ERR_BREAK(stmt) \
    eError = ##stmt;    \
    if (eError != VIDEO_ERROR_NONE) \
    {   \
        break;  \
    }

#define MP4_ASSERT(stmt)  \
    if (!(##stmt)) {ASSERT(0);}

#define MP4_CLUSTERALIGNEDSIZE(Size, ClusterSize) \
    do{ \
        Size = ((Size + ClusterSize - 1) / ClusterSize) * ClusterSize;  \
    }while(0)

#define _MP4_CHECK_ABORT_SAVING() \
    if (MuxerAdaptQueryAbortSaving() == KAL_TRUE)  \
    {   \
        return VIDEO_ERROR_MUXER_ABORT_SAVING_DONE;  \
    }

//#define __DEBUG_MP4_MUXER__

#if defined(__DEBUG_MP4_MUXER__)
    #define _MP4_DEBUG_ASSERT() do{ASSERT(0);}while(0)
#else
    #define _MP4_DEBUG_ASSERT() do{}while(0)
#endif

/******************************************************************************
* Function
******************************************************************************/
VIDEO_ERROR_TYPE_T MP4_FSALFailHdlr(STFSAL *prFile);

#endif // __MP4_MUXER_ADAPTER_V2_H__
