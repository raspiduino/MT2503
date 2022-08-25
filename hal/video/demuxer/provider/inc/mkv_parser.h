/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mkv_parser.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_video.h"

#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)
#ifndef MKV_PARSER_H
#define MKV_PARSER_H

//#define __MKV_PARSER_ASSERTUNKNOW__
#define __MKV_TRACE__

#ifdef __VE_SLIM_PROJECT__
//#if 1
#define __MKV_SLIM__
#endif

#ifndef __MKV_SLIM__
#define __MKV_PARSER_DEBUG__
#define __MKV_CLUSTER_TABLE__
#endif

//#define __MKV_PARSER_SWLA__

#ifdef __VE_MOT_CATEGORY__ 
//#if 1
#define __MKV_PARSER_META__
#endif 

#define __MKV_INDEX_TABLE__

#define __MKV_KEYFRAME_TIME_CACHE__

#ifdef __MKV_INDEX_TABLE__
#define MKV_PARSER_INDEX_TABLE_COUNT 256
#define MKV_PARSER_INDEX_TABLE_MIN_TIMEINTERVAL 1000
#else
typedef struct MKV_PROVIDER_INDEX_TABLE
{
    kal_bool fgdummy;
}MKV_PROVIDER_INDEX_TABLE;

#endif

#ifdef __MKV_CLUSTER_TABLE__
#define MKV_PARSER_CLUSTER_TABLE_COUNT 256
#define MKV_PARSER_CLUSTER_CACHE_COUNT 5
#else
typedef struct MKV_PARSER_CLUSTERELEMENT_TABLE
{
   kal_bool fgdummy;
}MKV_PARSER_CLUSTERELEMENT_TABLE;
#endif

#define MKV_DEFAULT_TIMECODESCALE 1000000

/* MKV EBML ID  */

#define MKV_CLASS_A_ELEMENTS_SIZE  1
#define MKV_CLASS_B_ELEMENTS_SIZE  2
#define MKV_CLASS_D_ELEMENTS_SIZE  4
#define MKV_UNKNOWN_LENGTH 0xFFFFFFFF

#define MKV_EBML_ID            0x1A45DFA3
#define MKV_EBML_VERSION       0x4286
#define MKV_READ_VERSION        0x42F7
#define MKV_MAXID_LENGTH        0x42F2
#define MKV_MAXSIZE_LENGTH      0x42F3
#define MKV_DCOTYPE            0x4282
#define MKV_DOCTYPE_VERSION     0x4287
#define MKV_DOCTYPE_READVERSION 0x4285

#define MKV_SEGMENT_ID     0x18538067

#define MKV_SEGMENTINFO_ID 0x1549A966
#define MKV_SEGMENTINFO_DURATION      0x4489
#define MKV_SEGMENTINFO_TIMECODESCALE 0x2AD7B1
#define MKV_SEGMENTINFO_FILENAME       0x7384
#define MKV_SEGMENTINFO_TITLE          0x7BA9

#define MKV_SEEKHEAD_ID    0x114D9B74
#define MKV_SEEK           0x4DBB
#define MKV_SEEK_ID        0x53AB
#define MKV_SEEK_POSITION  0x53AC

#define MKV_CLUSTER_ID     0x1F43B675
#define MKV_CLUSTER_BLOCKGROUP     0xA0
#define MKV_CLUSTER_BLOCK_DURATION  0x9B
#define MKV_CLUSTER_BLOCK_REFERENCEBLOCK 0xFB

#define MKV_CLUSTER_BLOCK          0xA1
#define MKV_CLUSTER_SIMPLEBLOCK    0xA3
#define MKV_CLUSTER_TIMECODE       0xE7
#define MKV_CLUSTER_POSITION       0xA7
#define MKV_CLUSTER_PRESIZE        0xAB


#define MKV_TRACKS_ID      0x1654AE6B
#define MKV_TRACK_ENTRY     0xAE
#define MKV_TRACK_NUMBER    0xD7
#define MKV_TRACK_UID      0x73C5
#define MKV_TRACK_TYPE      0x83
#define MKV_TRACK_FLAG_LACING 0x9C
#define MKV_TRACK_FLAG_DEFAULT 0x88
#define MKV_TRACK_MINCACHE  0x6DE7
#define MKV_TRACK_CODECID   0x86
#define MKV_TRACK_CODECPRIVATE   0x63A2
#define MKV_TRACK_DEFAULT_DURATION   0x23E383
#define MKV_TRACK_LANGUAGE   0x22B59C
#define MKV_TRACK_NAME   0x536E

#define MKV_TRACK_VIDEO_ID   0xE0
#define MKV_TRACK_VIDEO_PIXEL_WIDTH     0xB0
#define MKV_TRACK_VIDEO_PIXEL_HEIGHT    0xBA
#define MKV_TRACK_VIDEO_DISPLAY_WIDTH   0x54B0
#define MKV_TRACK_VIDEO_DISPLAY_HEIGHT  0x54BA
#define MKV_TRACK_VIDEO_STEREOMODE     0x53B8

#define MKV_TRACK_AUDIO_ID   0xE1
#define MKV_TRACK_AUDIO_SAMPLING_FREQUENCY   0xB5
#define MKV_TRACK_AUDIO_CHANNELS   0x9F
#define MKV_TRACK_AUDIO_OUTPUT_SAMPLING_FREQUENCY   0x78B5
#define MKV_TRACK_AUDIO_BITDEPTH   0x6264

#define MKV_TRACK_CONTENT_ENCODINGS_ID    0x6D80
#define MKV_TRACK_CONTENT_ENCODING_ID     0x6240
#define MKV_TRACK_CONTENT_ENCODING_ORDER  0x5031
#define MKV_TRACK_CONTENT_ENCODING_SCOPE  0x5032
#define MKV_TRACK_CONTENT_ENCODING_TYPE   0x5033
#define MKV_TRACK_CONTENT_COMPRESSION     0x5034
#define MKV_TRACK_CONTENT_COMPALGO        0x4254
#define MKV_TRACK_CONTENT_COMPSETTINGS    0x4255

#define MKV_CUES_ID        0x1C53BB6B
#define MKV_CUE_POINT       0xBB
#define MKV_CUE_TIME        0xB3
#define MKV_CUE_TRACK_POSITION    0xB7
#define MKV_CUE_TRACK       0xF7
#define MKV_CUE_CLUSTER_POSITION  0xF1
#define MKV_CUE_CLUSTER_BLOCK_NUMBER  0x5378

#define MKV_CHAPTERS_ID    0x1043A770

#define MKV_TAGS_ID        0x1254C367
#define MKV_TAG            0x7373
#define MKV_TAG_SIMPLETAG  0x67C8
#define MKV_TAG_NAME       0x45A3
#define MKV_TAG_STRING     0x4487
#define MKV_TAG_LANGUAGE       0x447A

#define MKV_ATTACHMENTS_ID 0x1941A469
#define MKV_ATTACHED_FILE  0x61A7
#define MKV_FILE_NAME      0x466E
#define MKV_FILE_MINETYPE  0x4660
#define MKV_FILE_DATA      0x465C
#define MKV_FILE_UID      0x46AE

#define MKV_VOID           0xEC
#define MKV_CRC32ID        0xBF

//-------------------------------
// Memory 

#define SEEKHEAD_BUFFER_SIZE   256
#define TRACKS_BUFFER_SIZE     10*1024 
#define TAG_BUFFER_SIZE     1024 
#define ATTACH_BUFFER_SIZE     1024 
#define MKV_SUPPORT_TRACK_NUM  10
#define MKV_TRACK_CODECID_MAXSIZE 32
#define MKV_TRACK_CODEC_PRIVATEDATA_MAXSIZE 2048
#define SEGMENTINFO_BUFFER_SIZE   1024
#define MKV_WORKING_MEMORY     1024

typedef enum
{
    MKV_PARSER_ERROR_NONE,
    MKV_PARSER_ERROR_EOF,
    MKV_PARSER_ERROR_CORRUPT,
    MKV_PARSER_ERROR_MAX
}MKV_PARSER_ERROR_T;

typedef enum
{
    MKV_SEEK_START,
    MKV_SEEK_CUR,
    MKV_SEEK_END
}MKV_SEEKFILE_T;

typedef enum
{
    MKV_TRACKTYPE_NONE =0,
    MKV_TRACKTYPE_VIDEO = 0x1,
    MKV_TRACKTYPE_AUDIO = 0x2,
    MKV_TRACKTYPE_COMPLEX = 0x3,
    MKV_TRACKTYPE_LOGO = 0x10,
    MKV_TRACKTYPE_SUBTITLE = 0x11,
    MKV_TRACKTYPE_BUTTON = 0x12,
    MKV_TRACKTYPE_CONTROL = 0x20,
    MKV_TRACKTYPE_MAX
}MKV_TRACKTYPE_T;

typedef enum
{
    //video
    MKV_CODECID_V_MPEG4_ISO_ASP,
    MKV_CODECID_V_MPEG4_ISO_AVC,
    MKV_CODECID_V_MS_VFW_FOURCC,
    MKV_CODECID_V_VP8,
    MKV_CODECID_V_H264,
    MKV_CODECID_V_XVID,
    MKV_CODECID_V_MJPEG,    

    //audio
    MKV_CODECID_A_AAC,    
    MKV_CODECID_A_MPEG_L3,
    MKV_CODECID_A_VORBIS,
    MKV_CODECID_A_AC3,
    MKV_CODECID_A_DTS,
    MKV_CODECID_A_AAC_MPEG4_LC,
    MKV_CODECID_A_AAC_MPEG4_LC_SBR,
    MKV_CODECID_A_MPEG_L1,    
    MKV_CODECID_A_MPEG_L2,
    MKV_CODECID_A_MS_ACM,
    MKV_CODECID_A_PCM_INT_BIG,
    MKV_CODECID_A_PCM_INT_LIT,    
    MKV_CODECID_A_WAVPACK4,	  
    
    //subtitle
    MKV_CODECID_S_TEXT_UTF8,
    MKV_CODECID_S_TEXT_ASS,
    MKV_CODECID_S_TEXT_SSA,
    MKV_CODECID_S_VOBSUB,
    MKV_CODECID_UNKNOW = 0xFF
}MKV_CODECID_T;

typedef struct mkv_parser_track_video
{
    kal_uint32 u4PixelWidth;
    kal_uint32 u4PixelHeight;
#ifndef __MKV_SLIM__	
    kal_uint32 u4DisplayWidth;
    kal_uint32 u4DisplayHeight;
#endif	
#ifdef __VE_3D_SIDE_BY_SIDE__
    kal_uint32 u4StereoMode;
#endif
}mkv_parser_track_video;

typedef struct mkv_parser_track_audio
{
    kal_uint32 u4SamplingFrequency;
#ifndef __MKV_SLIM__	
    kal_uint32 u4OutputsamplingFrequency;
#endif
    kal_uint32 u4Channels;
    kal_uint32 u4BitDepth;
}mkv_parser_track_audio;


typedef struct mkv_parser_track
{
    mkv_parser_track_video* VideoInfo;
    mkv_parser_track_audio* AudioInfo;
    kal_uint32 u4TrackNumber;
    kal_int32 i4ContentCompAlgo;
    kal_uint32 pu1ContentCompSettingLen;	
    kal_uint8* pu1ContentCompSettings;
    MKV_TRACKTYPE_T u4TrackType;
    MKV_CODECID_T CodecID;
    kal_uint32 u4CodecPrivateLen;
    kal_uint8* pu1CodecPrivate;
#ifdef __VE_SUBTITLE_SUPPORT__	
    kal_uint8* pu1Language;
    kal_bool fgFlagDefault;
#endif
    kal_uint64 u8DefaultDuration;	
#ifndef __MKV_SLIM__	
    kal_uint64 u8TrackUID;
    kal_uint32 u4MinCache;
    kal_uint8* pu1Name;
    kal_bool fgFlagLacing;
#endif	
    void* next;
}mkv_parser_track;

typedef struct mkv_ebml_element
{
    kal_uint32 u4EbmlIDLen;
    kal_uint32 u4EbmlID;
    kal_uint32 u4ElementSizeLen;	
    kal_uint32 u4ElementSize;
    kal_uint8* pu1Element;	
    kal_uint32 u4EbmlTotalLength;
}mkv_ebml_element;

typedef struct mkv_parser_cluster
{
#if defined(__MKV_INDEX_TABLE__) || defined(__MKV_CLUSTER_TABLE__)
    kal_uint64 u4ClusterStart; // from MKV_CLUSTER_ID 
#endif    
    kal_uint64 u4ClusterBase;  // after length of Cluster
    kal_uint64 u4TimeCode;
    kal_uint32 u4Length;
    kal_uint32 u4Offset;
}mkv_parser_cluster;

typedef struct mkv_parser_block
{
    kal_uint32 u4TrackNumber;
    kal_uint32 u4Length;
    kal_uint32 u4Framecount;
    kal_uint32 u4Duration;	
    kal_int16  i2Timecode;
    kal_uint8  u2Lacetype;	
    kal_bool   fgkeyframe;
#ifndef __MKV_SLIM__	
    kal_bool   fgInvisible;
    kal_bool   fgDiscardable;
#endif	
    kal_bool   fgDuration;
    kal_uint32* u4FrameLen;

}mkv_parser_block;

typedef struct mkv_parser_cuepoint
{
    kal_uint32 u4CueTime;
//    kal_uint32 u4CueTrack;	
    kal_uint64 u4CueClusterPosition;	
}mkv_parser_cuepoint;


typedef enum 
{
    MKV_BLOCKFLAG_DISCARDABLE = 0x0,
    MKV_BLOCKFLAG_LACINGFLAG = 0x6,		
    MKV_BLOCKFLAG_INVISIBLE = 0x8,		
    MKV_BLOCKFLAG_KEYFRAME = 0x80		
}MKV_BLOCKFLAG_T;

typedef enum 
{
    MKV_BLOCKLACING_NONE,
    MKV_BLOCKLACING_XIPH,
    MKV_BLOCKLACING_FIXED,
    MKV_BLOCKLACING_EBML    
}MKV_BLOCKLACING_T;

typedef enum 
{
    MKV_MIMETYPE_NONE,
    MKV_MIMETYPE_JPEG,
    MKV_MIMETYPE_PNG
}MKV_MIMETYPE_T;

typedef enum 
{
    MKV_META_TITLE,
    MKV_META_ARTIST,
    MKV_META_DATE,    
    MKV_META_ANNOTATION,        
    MKV_META_TYPE,            
    MKV_META_THUMB,     
    MKV_META_THUMBTYPE,     
    MKV_META_MAX     
}MKV_META_T;



#ifdef __MKV_INDEX_TABLE__
typedef struct MKV_PROVIDER_INDEX_ITEM
{
    kal_uint64 u4ClusterPosition;	
    kal_uint32 u4ClusterOffset;	
    kal_uint32 u4Time;	
}MKV_PROVIDER_INDEX_ITEM;

typedef struct MKV_PROVIDER_INDEX_TABLE
{
    kal_uint32 u4MaxTime;
	kal_uint32 u4Used;
	kal_uint32 u4CompressedTime;
	MKV_PROVIDER_INDEX_ITEM table[MKV_PARSER_INDEX_TABLE_COUNT];
}MKV_PROVIDER_INDEX_TABLE;

typedef struct MKV_PARSER_CLUSTER_TABLE
{
    kal_uint32 u4Timecode;
    kal_uint64 u4Start;
}MKV_PARSER_CLUSTER_TABLE;

#endif

#ifdef __MKV_CLUSTER_TABLE__
typedef struct MKV_PARSER_CLUSTER_ELEMENT
{
    kal_uint16 u2ClusterID;
    kal_uint16 u2TrackID;
    kal_uint32 u4Offset;	
#ifdef __MKV_PARSER_DEBUG__	
    kal_uint64 u4ClusterBase;
    kal_uint32 u4Timecode;	
#endif
}MKV_PARSER_CLUSTER_ELEMENT;

typedef struct MKV_PARSER_CLUSTER_INOF
{
    kal_uint64 u4ClusterBase;
    kal_uint32 u4MinOffset;		
    kal_uint32 u4MaxOffset;	
    kal_uint32 u4Timecode;  // cluster base timecode		
    kal_uint32 u4MaxTimestamp;  // Maxoffest timestamp (has added cluster base timecode)   
    kal_uint16 u2Used;	
    kal_uint8  u1TrackOwner;
    kal_bool   fgDisableFill;	
#ifdef __VE_SUBTITLE_SUPPORT__	  // 0:audio, 1: video, 2:subtitle
    kal_uint16 u2CacheCount[3];
#else
    kal_uint16 u2CacheCount[2];
#endif
}MKV_PARSER_CLUSTER_INOF;

typedef struct MKV_PARSER_CLUSTERELEMENT_TABLE
{
    kal_uint8 u1ClusterInfoWrite;	
    kal_uint8 u1ClusterInfoUsed;	
    kal_uint8 u1ClusterInfoMaxBase;	
    kal_uint32 u4Read;
    kal_uint32 u4Write;
    kal_uint32 u4Used;
    MKV_PARSER_CLUSTER_ELEMENT table[MKV_PARSER_CLUSTER_TABLE_COUNT];
}MKV_PARSER_CLUSTERELEMENT_TABLE;
#endif


/* Function pointer definitions */
typedef kal_uint32 (*mkv_read_func_ptr) (void* pUserRead,
                                    void*   pFilehdr,
                                    kal_uint8*   pBuf, /* Must be at least ulBytesToRead long */
                                    kal_uint32  ulBytesToRead);
typedef kal_bool (*mkv_seek_func_ptr) (void*  pUserRead,
                                      kal_uint32 ulOffset,
                                      MKV_SEEKFILE_T ulOrigin);


typedef kal_uint32 (*mkv_get_curpos_func_prt)(void* file_handle);

typedef void* (*mkv_malloc_func_ptr) (const void* pUserMem, kal_uint32 ulSize, kal_bool fgAssert);
typedef void  (*mkv_free_func_ptr)   (const void* pUserMem, void** ptr);
typedef void (*mkv_error_func_ptr) (void* pUserError, MKV_PARSER_ERROR_T err, const char* msg);

typedef kal_bool (*mkv_deliver_func_ptr) (void *pvHandle, mkv_parser_block* block);


typedef struct mkv_parser
{
    mkv_read_func_ptr fpRead;
    void* pUserRead;	
    mkv_seek_func_ptr fpSeek;
    mkv_get_curpos_func_prt fpGetcurpos;
    mkv_malloc_func_ptr fpMalloc;
    mkv_free_func_ptr fpMfree;
    void* pUserMem;
    mkv_error_func_ptr fpErr;
    mkv_deliver_func_ptr fpDeliver;
    void* pUserDeliver;

    void* pfilehdr;  //for header process

    kal_uint64 u4SegmentLength;
    kal_uint32 u4SegmentDataBase;

    kal_uint64 u4SegmentInfoBase;
    kal_uint64 u4TracksBase;
    kal_uint64 u4CuesBase;
    kal_uint64 u4ClusterBase;
    kal_uint64 u4SeekheadBase;	
#ifdef __MKV_PARSER_META__
    kal_uint64 u4TagsBase;
    kal_uint64 u4AttachmentsBase;

    kal_uint32 u4Meta[MKV_META_MAX][2];	
#endif

    kal_uint64 u4Duration;
    kal_uint64 u4TimecodeScale;
#ifndef __MKV_SLIM__	
    kal_uint8* pu1Filename;
    kal_uint8* pu1Title;
#endif
    kal_uint32 u4TrackCount;
    mkv_parser_track *pTrackList;
    kal_bool fgVideoTrack;  // for setup index table
#ifdef __MKV_INDEX_TABLE__
    MKV_PROVIDER_INDEX_TABLE* pIndexTable;
    MKV_PARSER_CLUSTER_TABLE rClusterCache[2];
#endif	
#ifdef __MKV_CLUSTER_TABLE__
    MKV_PARSER_CLUSTER_INOF rCacheCluster[MKV_PARSER_CLUSTER_CACHE_COUNT];
    MKV_PARSER_CLUSTERELEMENT_TABLE* pClusterTable;
#endif
    kal_uint8 u1VideoTrackIndex;
#if defined(__MKV_INDEX_TABLE__) || defined(__MKV_CLUSTER_TABLE__)
    kal_uint8 u1AudioTrackIndex;
    kal_uint8 u1SubtitleTrackIndex;
#endif

#ifdef  __MKV_KEYFRAME_TIME_CACHE__
    kal_uint32 u4AudioQueryTime;    
    kal_uint32 u4AudioKeyframeTime;	
    kal_uint32 u4VideoQueryTime;    
    kal_uint32 u4VideoKeyframeTime;		
#endif
}mkv_parser;


#ifdef __MKV_PARSER_SWLA__
#define MKV_PARSER_START_LOGGING(sym)  VIDEO_START_LOGGING(sym)
#define MKV_PARSER_STOP_LOGGING(sym) VIDEO_STOP_LOGGING(sym)
#define MKV_PARSER_LABEL_LOGGING(sym) VIDEO_LABEL_LOGGING(sym)
#else
#define MKV_PARSER_START_LOGGING(sym)  do{}while(0);
#define MKV_PARSER_STOP_LOGGING(sym) do{}while(0);
#define MKV_PARSER_LABEL_LOGGING(sym) do{}while(0);
#endif

#ifdef __MKV_TRACE__
#define MKV_TRACE1(a,b,c)  drv_trace1(a,b,c)
#define MKV_TRACE2(a,b,c,d)  drv_trace2(a,b,c,d)
#define MKV_TRACE4(a,b,c,d,e,f)  drv_trace4(a,b,c,d,e,f)
#define MKV_TRACE8(a,b,c,d,e,f,g,h,i,j)  drv_trace8(a,b,c,d,e,f,g,h,i,j)
#else
#define MKV_TRACE1(a,b,c)  do{}while(0);
#define MKV_TRACE2(a,b,c,d)  do{}while(0);
#define MKV_TRACE4(a,b,c,d,e,f)  do{}while(0);
#define MKV_TRACE8(a,b,c,d,e,f,g,h,i,j)  do{}while(0);
#endif

extern mkv_parser* mkv_parser_create(void* pUserError, mkv_error_func_ptr  fpError, void* pUserMem, mkv_malloc_func_ptr fpMalloc, mkv_free_func_ptr fpFree);
extern void mkv_parser_close(mkv_parser* pParser);
extern kal_bool mkv_parser_init(mkv_parser* pParser, kal_bool fgCheckIndextable, kal_uint32 u4Filesize);
extern kal_bool mkv_parser_check_ebml(kal_uint8* pBuf);
extern kal_bool mkv_parser_set_io(mkv_parser* pParser, void* pUserRead, void* pfilehdr, mkv_read_func_ptr fpRead, mkv_seek_func_ptr fpSeek, mkv_get_curpos_func_prt fpGetcurpos);
extern kal_bool mkv_parser_select_track(mkv_parser* pParser, MKV_TRACKTYPE_T eType, kal_uint32 u4TrackNumber, kal_bool fgSelect);
extern MKV_PARSER_ERROR_T mkv_parser_demux(mkv_parser* pParser, kal_uint32 u4TrackNumber, void* pReadhdr, mkv_parser_cluster* pCluster);
extern kal_bool mkv_parser_set_deliver(mkv_parser* pParser,void* pUserDeliver, mkv_deliver_func_ptr fpDeliver);
extern kal_bool mkv_parser_seek(mkv_parser* pParser, void* pTrackhdr, kal_uint32 time, kal_uint32* pu4keyframetime, mkv_parser_cluster* pcluster, kal_bool fgReset);
extern kal_bool mkv_parser_get_keyframe_time(mkv_parser* pParser, kal_uint32 u4TrackNumber, kal_uint32 u4Targettime, kal_uint32* p4Keyframetime, MKV_TRACKTYPE_T eTracktype, kal_bool* pfgAbort);
extern void mkv_parser_get_meta(mkv_parser* pParser, MKV_META_T eMetaType, void* pBuffer, kal_uint32 u4Len, kal_uint32* pu4Size);

extern kal_uint64 _mkv_read_byte_little_endian(kal_uint8 * pBuf, kal_uint32 u4size);
extern kal_uint64 _mkv_read_byte(kal_uint8 * pBuf, kal_uint32 u4size);

#endif //MKV_PARSER_H
#endif //__VE_MKV_FILE_FORMAT_SUPPORT__
