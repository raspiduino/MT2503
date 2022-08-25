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
 *   Video_filereader_component.h
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 ****************************************************************************/
#ifndef VIDEO_FILEREADER_COMPONENT_H
#define VIDEO_FILEREADER_COMPONENT_H

#ifdef __VIDEO_ARCHI_V2__
#include "video_comm_v2.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "video_types_v2.h"
#include "video_bitstream_buffer_management_v2.h"
#include "video_comm_component_v2.h"
#include "video_decoder_demuxer_if_v2.h"

/****************************************************************************
*
* Global parameter
*
*****************************************************************************/
#define VIDEO_FILEREADER_INPUT_BUFF_SIZE            0
#define VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM          (VIDEO_BITSTREAM_BUFF_MAX_NUM*2) // 300 NAL unit payload information for frames

// Define reasonable number of SPS&PPS in our system
//
#define VIDEO_FILEREADER_NAL_PARAM_CTRL_BUFF_NUM   288 // 288 NAL unit payload information for parameter set

// Bitstream buffer size
#define VIDEO_FILEREADER_BITSTREAM_BUFF_SIZE        (320*240*3/2*3)

// For container AVC information
#define VIDEO_FILEREADER_AVC_CONFIG_LENGTH  5

#define VIDEO_FILEREADER_SCALE_UNIT   VIDEO_COMMON_TIME_BASE // us

// Define fill bitstream buffer threshold in bytes
#define VIDEO_FILEREADER_BITSTREAM_BUFF_FILL_THRESHOLD (128*1024)

#define VIDEO_FILEREADER_PARAMSET_LENGTH 3000// 3000 bytes
#define VIDEO_FILEREADER_MAX_PARAMSET_NUM 288 // 32 + 256

#define VIDEO_FILEREADER_CMD_BUFFER_QUEUE_NUM   10
#define VIDEO_FILEREADER_INPUT_BUFFER_QUEUE_NUM   0
#define VIDEO_FILEREADER_OUTPUT_BUFFER_QUEUE_NUM   10

#define TIMEBASE_VIDEO_TO_MICROS(_TIME)     VIDEO_ANYBASE_TO_ANYBASE(_TIME, _rVideoFileReaderState.u4VideoTimeScale, VIDEO_FILEREADER_SCALE_UNIT)
#define TIMEBASE_MICROS_TO_VIDEO(_TIME)     VIDEO_ANYBASE_TO_ANYBASE(_TIME, VIDEO_FILEREADER_SCALE_UNIT, _rVideoFileReaderState.u4VideoTimeScale)
// file adap read parameter

/****************************************************************************
*
* Profile
*
*****************************************************************************/
// File reader internal compile option
#define __VIDEO_FILEREADER_PROFILE_ENABLE__

#define VIDEO_FILEREADER_MEASURE_HIGH       10
#define VIDEO_FILEREADER_MEASURE_LOW        5
#define VIDEO_FILEREADER_AVAIL_FRAME_WINDOW 50

typedef struct
{
    kal_uint32 u4AccumulatedCount;

    // Size
    kal_uint32 u4AvgFetchSize;
    kal_uint32 u4MaxFetchSize;
    kal_uint32 u4TotalFetchSize;
    kal_uint32 u4ContinuousReachMaxCount;
    kal_uint32 u4NotContinuousCount;
    kal_uint32 u4FetchCountUnderThreshold;
    kal_uint32 u4FetchThreshold;

    // Time
    kal_uint32 u4AvgFetchTime;
    kal_uint32 u4MaxFetchTime;
    kal_uint32 u4TotalFetchTime;

    // Available frame
    kal_uint32 u4AvailFrameIndex;
    kal_uint32 au4AvailFrameWindow[VIDEO_FILEREADER_AVAIL_FRAME_WINDOW];

}VIDEO_FILEREADER_PROFILE_T;


typedef struct
{
    kal_bool fgIsFull;
    kal_uint32 u4ReadIndex;
    kal_uint32 u4WriteIndex;

    // The buffer is used for frame record
    H264_DECODER_INPUT_PARAM_T arPrivateData[VIDEO_BITSTREAM_BUFF_MAX_NUM];
    H264_DECODER_PAYLOAD_INFO_T arNALCTRLBuff[VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM];
}VIDEO_FILEREADER_NAL_CTRL_BUFF_T;

typedef enum
{
    AVC_NALU_LENGTH_1 = 1,
    AVC_NALU_LENGTH_2 = 2,
    AVC_NALU_LENGTH_4 = 4
}VIDEO_FILEREADER_FILE_AVC_NAL_LENGTH_T;

typedef struct
{
    STFSAL *prSTFSAL;
    kal_uint32 u4StartFrame;
    kal_uint32 u4EndFrame;
    kal_uint32 u4TargetFrame;
    kal_uint32 u4ResultCount;    // Means that how many frames we fetch in that transition
    kal_uint32 u4MaxFetchSize;   // Define maximum fetch size. If fetch size > , filling process will stop.
    kal_uint32 u4BeginOfBuffAddr; // Define start address of bitstream buffer
    kal_uint32 u4EndOfBuffAddr;   // Define end address of bitstream buffer
    kal_uint32 u4ResultSize;
    kal_uint32 u4ReadOffset;
    kal_uint32 u4WriteOffset;
    kal_uint32 *pu4FrameNum;
    kal_uint32 *pu4FrameAddr;
    kal_uint32 *pu4FrameLength;
    kal_uint64 *pu4FrameTime;
    kal_uint32 u4MaxFileAccessSize; //Defines the access size of File system.
    kal_uint32 au4TempFileOffset[VIDEO_BITSTREAM_BUFF_MAX_NUM + 1]; // temp storage to enhance speed
} VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T;

// Parameter Set Information
typedef struct
{
    // MPEG-4 & H.264 common, excluding H.263
    //
    kal_uint8 au1ParamSetBuff[VIDEO_FILEREADER_PARAMSET_LENGTH];
    kal_uint32 u4ParamSetTotalSize;

    // Only for H.264
    //
    kal_uint32 u4NALuSizeInfo;
    kal_uint32 u4NumOfNALuParamSet;
    kal_uint32 au4NALuOfParamSetAddr[VIDEO_FILEREADER_MAX_PARAMSET_NUM];
    kal_uint32 au4NALuOfParamSetLength[VIDEO_FILEREADER_MAX_PARAMSET_NUM];

    // The private data is used only for H.264
    // The buffer is used for parameter set record
    kal_uint32 u4TotalNALSize;
    H264_DECODER_INPUT_PARAM_T rPrivateData;
    H264_DECODER_PAYLOAD_INFO_T arNALCTRLBuff[VIDEO_FILEREADER_NAL_PARAM_CTRL_BUFF_NUM];
} VIDEO_FILEREADER_PARAM_SET_STRUCT_T;


typedef struct
{
    VIDEO_COMM_STATE_T rCommState;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;
    STFSAL *prFileReaderFSAL;
    STMp4Parser *prFileReaderMp4Parser;

    // Seek component
    // Timescale: us 10^6
    kal_uint64 u8SeekTime;
    kal_uint32 u4SeekFrame;
    kal_uint32 u4SeekPrevIFrame;

    // File system adaptation
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;

    // Control information
    kal_bool fgIsFatalError;
    kal_bool fgClosingComp;
    kal_bool fgIsDeliverParamSet;
    kal_bool fgIsDeliverEOF;
    kal_bool fgWaitForFreeAnyFrame;  // This flag is used when bitstream buffer is not enough to fetch any frame
    kal_uint32 u4DeliverFrame; // Indicate to the next deliver frame number
    kal_uint32 u4FreeFrame; // Indicate to the next free frame number
    kal_bool fgEmptyThisBufferFail;

    // Container information
    VIDEO_DECODER_TYPE_T u4VideoDecodeType; // MPEG4, H263, H264
    kal_uint64 u8VideoDuration; // Get media file total duration
    kal_uint32 u4VideoTimeScale;
    kal_uint32 u4VideoTotalFrame;

    // Video width & height
    kal_uint32 u4VideoWidth;
    kal_uint32 u4VideoHeight;

    // Parameter set data
    VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData;

    // NAL Control Buffer
    VIDEO_FILEREADER_NAL_CTRL_BUFF_T *prNALCTRLBuffer;

    // Profile statistic
    VIDEO_FILEREADER_PROFILE_T rProfileData;

} VIDEO_FILEREADER_STATE_T;


extern VIDEO_COMPONENT_TYPE_T gVideoFileReaderComp;


#endif /* __VIDEO_ARCHI_V2__ */
#endif /* VIDEO_FILEREADER_COMPONENT_H */


