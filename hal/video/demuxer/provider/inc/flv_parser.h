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
 *
 * Filename:
 * ---------
 * flv_parser.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FLV parser Definitions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 *******************************************************************************/

#ifndef __FLV_PARSER_H__
#define __FLV_PARSER_H__

#include "fsal.h"

#define FLV_FILE_START 0x464C56

#define FLV_HEADER_TYPE_FLAGS_RESERVED_BITS5  (0xF8)
#define FLV_HEADER_TYPE_FLAGS_AUDIO (0x04)
#define FLV_HEADER_TYPE_FLAGS_RESERVED_BITS1  (0x02)
#define FLV_HEADER_TYPE_FLAGS_VIDEO (0x01)

#define FLV_TAG_RESERVED (0xC0)
#define FLV_TAG_FILTER (0x20)
#define FLV_TAG_FILTER_OFFSET (5)
#define FLV_TAG_TAGTYPE (0x1F)

#define AUDIO_TAG (0x8)
#define VIDEO_TAG (0x9)
#define SCRIPT_DATA_TAG (0x12)

#define FLV_SOUND_FORMAT_AAC 10

#define MAX_SPS_NUMBER 32
#define MAX_PPS_NUMBER 256

#define FLV_KEY_FRAME 1
#define FLV_INTER_FRAME 2
#define FLV_DISPOSABLE_INTER_FRAME 3
#define FLV_GENERATED_KEY_FRAME 4
#define FLV_VIDEO_INFO_COMMAND_FRAME 5

#define FLV_TAG_LENGTH 11
#define FLV_VIDEO_TAG_HDR_LENGTH 5

#define FLV_AUDIO_TAG_HDR_LENGTH 1
#define FLV_AUDIO_TAG_HDR_LENGTH_AAC 2

#define FLV_AVCDECCONFSIZEMIN 5

#define FLV_PREV_TAG_SIZE_LENGTH 4

#define FLV_PARSER_FILE_GET_CUR_POS(pos) \
   if (FSAL_GetCurPos(pFLVParser->pstFSAL, &(pos))!=FSAL_OK) \
      return FLV_PARSER_FILE_ACCESS_ERROR

#define FLV_PARSER_CHECK_ARG(exp) \
   if (!(exp)) \
      return FLV_PARSER_INVALID_ARGUMENT

#define FLV_ASSERT( exp )          \
{                           \
   if( !( exp ) )          \
   {ASSERT(0);}          \
}

// Video key frame is built during demuxing without key table
// #define __VE_FLV_PSEUDO_KEY_TABLE__


typedef enum
{
    AMF_Number = 0,
    AMF_Boolean,
    AMF_String,
    AMF_Object,
    AMF_MovieClip, // reserved, not supported
    AMF_Null,
    AMF_Undefined,
    AMF_Reference,
    AMF_ECMAArray,
    AMF_ObjectEndMarker,
    AMF_StrictArray,
    AMF_Date,
    AMFLongString
}ScriptDataValue;

typedef enum {
   FLV_LINEAR_PCM = 0,
   FLV_ADPCM,
   FLV_MP3,
   FLV_LINEAR_PCM_LE,
   FLV_NELLYMOSER_16K_MONO,
   FLV_NELLYMOSER_8K_MONO,
   FLV_NELLYMOSER,
   FLV_G711_ALAW_PCM,
   FLV_G711_MULAW_PCM,
   FLV_RESERVED,
   FLV_AAC,
   FLV_SPEEX,
   FLV_MP3_8K,
   FLV_DEVICE_SPECIFIC,
   FLV_AUDIO_UNDEFINED
} FLV_AUDIO_CODEC_FORMAT;

typedef enum {
   FLV_SORESON_H263 = 2,
   FLV_SCREEN_VIDEO,
   FLV_ON2_VP6,
   FLV_ON2_VP6_ALPHA_CHANNEL,
   FLV_SCREEN_VIDEO_V2,
   FLV_AVC,
   FLV_VIDEO_UNDEFINED
} FLV_VIDEO_CODEC_FORMAT;

#define FLV_RESERVED_TRACK_NO 0xFF
typedef enum {
   FLV_TRACK_AUDIO = 0,
   FLV_TRACK_VIDEO = 1,
   FLV_TRACK_TOTAL
} FLV_Track_Type;

typedef struct
{
    unsigned int totalSize;
    unsigned int offset;
    unsigned int LengthSizeMinusOne;
    unsigned char ConVer;
    unsigned char profile;
    unsigned char profile_comp;
    unsigned char level;
}AVCDecConfRecord;

typedef enum
{
    FLV_KEYFRAME_INIT = 0,
    FLV_KEYFRAME_START,
    FLV_KEYFRAME_PARSED
} KeyFrameStatus;

#define FLV_MAX_KEYFRAME_STORE 100
#define FLV_MAX_MEMO_KEYFRAME_STORE 10

typedef struct
{
    unsigned int Real_Count; // With key frame case. Determined from meta
    KeyFrameStatus eFileOffset;
    KeyFrameStatus eTime;
    unsigned int KeyOffestStart; // with key frame case, the start offset of "filepositions"
    unsigned int KeyTimestart; // with key frame case, the start offset of "times"
    unsigned int last_index; // with key frame case, the largest key index (< Real_Count)
    unsigned int valid_end_idx; // key frame array 值有意義的最大值. e.g. clip有60張key frame, 這個值就是59
    unsigned int au4FileVOffset[FLV_MAX_KEYFRAME_STORE]; // Video tag offset
    unsigned int au4Time[FLV_MAX_KEYFRAME_STORE];
    unsigned int au4VFrmIdx[FLV_MAX_KEYFRAME_STORE];  // Video frame index

    unsigned int interval;  // Key frame interval for subsample
    unsigned int accum;  // accumulation of interval
    unsigned int MaxReadOffset;
    unsigned int MaxReadTime;
}FLV_KeyFrameTable;

typedef struct
{
    unsigned int index;
    unsigned int au4FileVOffset[FLV_MAX_MEMO_KEYFRAME_STORE]; // Video tag offset
    unsigned int au4Time[FLV_MAX_MEMO_KEYFRAME_STORE];
    unsigned int au4VFrmIdx[FLV_MAX_MEMO_KEYFRAME_STORE];  // Video frame index
}FLV_MemoKeyFrameTable;

typedef struct
{
    STFSAL *pstFSAL;
    FSAL_Status eFSALErr;
    unsigned char FLVTAG_Filter;
    unsigned char FLVTAG_TagType;
    unsigned int FLVTAG_DataSize;
    unsigned int FLVTAG_Timestamp;
    unsigned char FLVTAG_TimestampExtended;
    unsigned char FLVTAG_StreamID;

    // Video
    unsigned char VideoFrameType;
    int CompositionTimeOffset;
}FLVParser;

typedef struct
{
    unsigned char version;
    unsigned char FLVHeader_TypeFlagsAudio;
    unsigned char FLVHeader_TypeFlagsVideo;
    unsigned int FLVHeader_DataOffset;

    unsigned int VideoFrameNum;
    unsigned int AudioFrameNum;
    unsigned int FirstVideoTagOffset;
    unsigned int FirstAudioTagOffset;

    //MetaData
    FLV_AUDIO_CODEC_FORMAT AudioCodecId;
    unsigned int AudioDataRate; // Audio bit rate in kbs
    unsigned int AudioDelay; // delay introduced by the audio codec in seconds
    unsigned int AudioSampleRate; // frequency at which the audio stream is replayed
    unsigned int AudioSampleSize;
    unsigned int duration; // in seconds
    unsigned int VideoFrameRate; // Number of Video frames per second *1000
    unsigned int AudioFrameRate; // Number of Audio frames per second
    unsigned int width;
    unsigned int height;
    kal_bool stereo;
    FLV_VIDEO_CODEC_FORMAT VideoCodecId;
    unsigned int VideoDataRate; // kbs
    FLV_KeyFrameTable rKeyFrames;

    // Audio 14496-3
    unsigned char bAudioObjectType;
    unsigned char bAudioSamplingFreqIndex;  // sampling frequency index (defined in 14496-3)
    unsigned char bAudioChannelConfig;      // channel configuration (14496-3, Table 1.16)

    // AVCDecoderCOnfigurationRecord
    AVCDecConfRecord rAVCDecConfig;

    // FSAL for key table reading
    STFSAL* pt_fsal_key_table; /* FSAL handle pointer to file */
    kal_uint32* p_fsal_key_table_buf; /* FSAL working buffer pointer to file */

    // Maintain latest audio frame file offset and time
    unsigned int LatestAudioTagOffset;
    unsigned int LatestAudioTagTime;

    // To fast break parsing loops
    kal_bool fgFastBreak;

    // profile
    kal_uint32 u4ParseTime;
}FLVMetaData;

typedef enum {
  FLV_PARSER_OK = 1,
  FLV_PARSER_AUDIO_CONFIG_OK,
  FLV_PARSER_VIDEO_CONFIG_OK,
  FLV_PARSER_AUDIO_DATA_OK,
  FLV_PARSER_VIDEO_DATA_OK,
  FLV_PARSER_INVALID_HEADER,
  FLV_PARSER_FILE_ACCESS_ERROR,
  FLV_PARSER_INVALID_ARGUMENT,
  FLV_PARSER_FILE_READ_ERROR,
  FLV_PARSER_FILE_READ_EOF,
  FLV_PARSER_FILE_SEEK_ERROR,
  FLV_PARSER_METADATA_ERROR,
  FLV_PARSER_AUDIO_FORMAT_NOT_SUPPORT,
  FLV_PARSER_VIDEO_FORMAT_NOT_SUPPORT,
  FLV_PARSER_PARSE_14496_3_BOXLENGTH_ERROR,
  FLV_PARSER_INVALID_AUDIO_SAMPLE_FREQ_IDX,
  FLV_PARSER_AUDIO_TOO_MANY_CHANNEL,
  FLV_PARSER_960_120_IMDCT_NOT_SUPPORT,
  FLV_PARSER_PARSE_14496_3_ERROR,
  FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT,
  FLV_PARSER_AVCODEC_NOT_SUPPORT,
  FLV_PARSER_BUFFER_READ_OVER,
  FLV_PARSER_VIDEO_PKT_EOS,
  FLV_PARSER_FAST_BREAK
} FLV_Parser_Status;



FLV_Parser_Status FLV_Parse(FLVParser *pFLVParser, STFSAL *pstFSAL, FLVMetaData *ptMetaData);
FLV_Parser_Status FLV_BuildKeyTable(FLVParser *pFLVParser, FLVMetaData *ptMetaData);
FLV_Parser_Status FLV_GetTrackAvail(FLVMetaData *pFLVMetadata, FLV_Track_Type eTrackType, kal_uint8 *has_this_track);
kal_uint32 FLV_GetCodecType(FLVMetaData* pFLVMetadata, FLV_Track_Type eTrackType);
FLV_Parser_Status FLV_GetMediaDuration(FLVMetaData* pFLVMetadata, kal_uint32 *pDuration);
FLV_Parser_Status FLV_GetVideoResolution(FLVMetaData* pFLVMetadata, kal_uint32 *width, kal_uint32 *height);
FLV_Parser_Status FLV_GetAverageBitRate(FLVMetaData* pFLVMetadata, kal_uint32 *bitrate, FLV_Track_Type eTrackType);
FLV_Parser_Status FLV_GetFrameRate(FLVMetaData* pFLVMetadata, kal_uint32 *fps);
kal_uint16 FLV_Audio_GetChannelCount(FLVMetaData* pFLVMetadata);
kal_uint16 FLV_Audio_GetSampleSize(FLVMetaData* pFLVMetadata);
kal_uint32 FLV_Audio_GetSampleRate(FLVMetaData* pFLVMetadata);
FLV_Parser_Status FLV_Tag(FLVParser *pFLVParser);
FLV_Parser_Status FLV_Tag_Buf(FLVParser *pFLVParser, kal_uint8* start, kal_uint32 length);
FLV_Parser_Status FLV_AudioTag(FLVParser *pFLVParser, FLVMetaData *pMetadata);
FLV_Parser_Status FLV_VideoTag(FLVParser *pFLVParser, FLVMetaData *pMetadata);
FLV_Parser_Status FLV_VideoTag_Buf(FLVParser *pFLVParser, FLVMetaData *pMetadata, kal_uint8* start, kal_uint32 length);
FLV_Parser_Status FLV_PrevKeyFramebyTime(FLVParser* pstParser, FLVMetaData* pFLVMetadata,
    kal_uint32 SeekTime,
    kal_uint32 *pKeyIndex, kal_uint32 *pOffset, kal_uint32 *pTime,
    FLV_Track_Type eTrackType);

#ifdef __VE_FLV_PSEUDO_KEY_TABLE__
void FLV_BuildPseuKeyTable(FLVMetaData *pMetadata, kal_uint32 uTime, kal_uint32 uOffset);
kal_uint32 FLV_GetPseuKeyTableMaxTime(FLVMetaData *pMetadata, kal_uint32* puOffset);
void FLV_UpdatePseuKeyTableMaxRead(FLVMetaData *pMetadata, kal_uint32 uTime, kal_uint32 uOffset);

#endif

#endif


