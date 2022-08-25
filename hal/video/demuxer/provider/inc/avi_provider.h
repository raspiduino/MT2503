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
 *   avi_provider.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _AVI_PROVIDER_H
#define _AVI_PROVIDER_H

#include "drv_comm.h"

#include "source_provider_if.h"
#include "video_codec_utility_v2.h"

//#include "source_provider_component.h"

#define AVI_SP_VID_STREAM_NUM (2)
#define AVI_SP_AUD_STREAM_NUM (2)

#define AVI_SP_PROVIDER_CHECK_INTEGRITY_LEN (12)
#define AVI_SP_TEMP_BUF (1024) /* size = 1024 bytes */
#define AVI_SP_FASL_SEEK_HINT_IDX (1023) /* size = 1023*8*/ 
#define AVI_SP_FASL_FILE_INFO_BUF (1024) /* size = 1024 bytes */
#define AVI_SP_FASL_INDEX_BUF (1024) /* size = 1024 bytes */
#define AVI_SP_INDEX_MAX_ENTRIES (1024) /* 1024*8 bytes */
#define AVI_SP_VIDEO_LIST_ITEM_NUM (60) /*60*16 bytes*/
#define AVI_SP_AUDIO_LIST_ITEM_NUM (60) /*60*16 bytes*/

#define AVI_SP_VIDEO_GAP_SIZE (1024)
#define AVI_SP_AUDIO_GAP_SIZE (256)
#define AVI_SP_VIDEO_MIN_FETCH_SIZE (16*1024)
#define AVI_SP_AUDIO_MIN_FETCH_SIZE (1*1024)

#define AVI_SP_TRACE_FUNC_GROUP TRACE_GROUP_4
#define AVI_SP_TRACE_HIGH_GROUP TRACE_GROUP_2
#define AVI_SP_TRACE_LOW_GROUP TRACE_GROUP_4

#ifdef __VE_SP_AVI_LOG_HIGH__
#define AVI_SP_TRACE_FSAL_ERROR(Err1) drv_trace2(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_FSAL_ERROR, Err1, __LINE__)
#define AVI_SP_TRACE_PARSER_ERROR(Err1) drv_trace2(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_PARSER_ERROR, Err1, __LINE__)
#define AVI_SP_TRACE_PARAMETER_ERROR(Err1, Err2, Err3) drv_trace4(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_PARAMETER_ERROR, Err1, Err2, Err3, __LINE__)
#define AVI_SP_TRACE_WARNING(Err1, Err2, Err3) drv_trace4(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_WARNING, Err1, Err2, Err3, __LINE__)
#else
#define AVI_SP_TRACE_FSAL_ERROR(Err1) do{}while(0);
#define AVI_SP_TRACE_PARSER_ERROR(Err1) do{}while(0);
#define AVI_SP_TRACE_PARAMETER_ERROR(Err1, Err2, Err3) do{}while(0);
#define AVI_SP_TRACE_WARNING(Err1, Err2, Err3) do{}while(0);
#endif

#define AVI_SP_FOUR_BYTE_MAX_VALUE (0xFFFFFFFF)
#define AVI_SP_MASK_HIGH_TWO_BYTE  (0xFFFF0000)
#define AVI_SP_MASK_LOW_TWO_BYTE  (0xFFFF)
#define AVI_SP_MOVI_CHUNK_OVERHEAD (8) /* ##ss + size */
#define AVI_SP_FASL_SECTOR_SIZE  (512)
#define AVI_SP_STREAM_HEADER_SIZE (52) /* for some error file, it should 56 */

/* MJPEG */
#define AVI_SP_TAG_MJPG            ("MJPG")
/* MPEG-4 */
#define AVI_SP_TAG_MP4V            ("MP4V")
#define AVI_SP_TAG_XVID            ("XVID")
#define AVI_SP_TAG_DX50            ("DX50")
#define AVI_SP_TAG_DIVX            ("DIVX")
#define AVI_SP_TAG_DIV5            ("DIV5")
#define AVI_SP_TAG_3IVX            ("3IVX")
#define AVI_SP_TAG_3IV2            ("3IV2")
#define AVI_SP_TAG_RMP4            ("RMP4")
#define AVI_SP_TAG_FMP4            ("FMP4")
/* H.263 */
#define AVI_SP_TAG_H263            ("H263")
#define AVI_SP_TAG_S263            ("S263")
/* H.264 */
#define AVI_SP_TAG_AVC1            ("AVC1")
#define AVI_SP_TAG_DAVC            ("DAVC")
#define AVI_SP_TAG_H264            ("H264")
#define AVI_SP_TAG_X264            ("X264")

#define AVI_SP_TAG_RIFF            ("RIFF")
#define AVI_SP_TAG_AVI             ("AVI ")
#define AVI_SP_TAG_LIST            ("LIST")
#define AVI_SP_TAG_JUNK            ("JUNK")

#define AVI_SP_TAG_HEADER_LIST     ("hdrl")
#define AVI_SP_TAG_AVI_HEADER      ("avih")
#define AVI_SP_TAG_STREAM_LIST     ("strl")
#define AVI_SP_TAG_STREAM_HEADER   ("strh")
#define AVI_SP_TAG_STREAM_FORMAT   ("strf")
#define AVI_SP_TAG_MOVI            ("movi")
#define AVI_SP_TAG_IDX1            ("idx1")

#define AVI_SP_TAG_MAUI            ("IUAM")
#define AVI_SP_TAG_TRNS            ("TRNS")

#define AVI_SP_TAG_STREAM_TYPE_VID ("vids")
#define AVI_SP_TAG_STREAM_TYPE_AUD ("auds")

#define AVI_SP_TAG_XXWB_STREAM_TYPE (0x62770000)
#define AVI_SP_TAG_XXDB_STREAM_TYPE (0x62640000)
#define AVI_SP_TAG_XXDC_STREAM_TYPE (0x63640000)

/***************************
   enum
  ***************************/
typedef enum
{
    AVI_SP_FRAME_TYPE_I = 0,
    AVI_SP_FRAME_TYPE_P, 
    AVI_SP_FRAME_TYPE_B,
    AVI_SP_FRAME_TYPE_UNKNOWN
} AVI_SP_FRAME_TYPE_T;

typedef enum
{
    AVI_SP_STATE_FILL_BUFF = 0,
    AVI_SP_STATE_DEMUX_DATA
} AVI_SP_STATE_T;

typedef enum
{
    AVI_SP_EOF_NONE = 0,
    AVI_SP_EOF_WAIT_SEND,
    AVI_SP_EOF_DONE
} AVI_SP_EOF_T;

#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__  
typedef enum
{
    AVI_SP_FETCH_MIN = 0,
    AVI_SP_FETCH_SKIP,      
    AVI_SP_FETCH_FORCE
} AVI_SP_FETCH_SIZE_T;
#endif

typedef struct
{   
    kal_bool fgVideo;
    kal_bool fgAudio;
    kal_uint32 u4VideoNum;
    kal_uint32 u4AudioNum;
    kal_uint32 u4IndexNum;
} AVI_SP_SEEK_TABLE_STREAM_T;

typedef struct
{
    kal_uint32 u4FourCC1; 
    kal_uint32 u4Size;
    kal_uint32 u4FourCC2;
} AVI_SP_ATOM_T;

/* 56 byte */
typedef struct
{
    kal_uint32 micro_sec_per_frame; /* frame rate */
    kal_uint32 max_byte_per_sec;    /* transfer rate */
    kal_uint32 padding_factor;      /* padding factor - * this  */
    kal_uint32 flag;                /* flag */
    kal_uint32 total_frame;         /* total frame */
    kal_uint32 init_frames;         /* init frame */
    kal_uint32 num_of_stream;       /* num of streams */
    kal_uint32 suggest_buf_size;    /* suggested buffer size */
    kal_uint32 width;               /* video width */
    kal_uint32 height;              /* video height */
    kal_uint32 reserve[4];          /* reserve */
} AVI_SP_FILE_HEADER_T;

/* 52 byte */
typedef struct
{
    kal_uint32 fcc_type;
    kal_uint32 fcc_hdlr;
    kal_uint32 flag;
    kal_uint16 priority;
    kal_uint16 language;
    kal_uint32 init_frames;
    kal_uint32 scale;
    kal_uint32 rate;    /* rate/scale = sample/sec */
    kal_uint32 start;
    kal_uint32 length;
    kal_uint32 suggest_buf_size;
    kal_uint32 quality;
    kal_uint32 sample_size;
    kal_uint16 rect_left;
    kal_uint16 rect_top;
    kal_uint16 rect_right;
    kal_uint16 rect_bottom;
}AVI_SP_STREAM_HEADER_T;

typedef struct
{
    kal_uint32 size;
    kal_uint32 width;
    kal_uint32 height;
    kal_uint16 planes;
    kal_uint16 bit_count;
    kal_uint32 compression;
    kal_uint32 size_image;
    kal_uint32 x_pels_per_meter;
    kal_uint32 y_pels_per_meter;
    kal_uint32 color_used;
    kal_uint32 color_important;
} AVI_SP_VIDEO_FORMAT_HEADER_T; 

typedef struct
{
    kal_uint16 format;
    kal_uint16 channels;
    kal_uint32 sample_per_sec;
    kal_uint32 avg_byte_per_sec;
    kal_uint16 block_align;
    kal_uint16 bit_per_sample;
    kal_uint16 size;
} AVI_SP_AUDIO_FORMAT_HEADER_T; 

// audio format 
#define AVI_SP_AUD_FORMAT_WAV_UNKNOWN          0x0000
#define AVI_SP_AUD_FORMAT_WAV_PCM              0x0001
#define AVI_SP_AUD_FORMAT_WAV_ADPCM            0x0002
#define AVI_SP_AUD_FORMAT_WAV_IBM_CVSD         0x0005
#define AVI_SP_AUD_FORMAT_WAV_ALAW             0x0006
#define AVI_SP_AUD_FORMAT_WAV_MULAW            0x0007
#define AVI_SP_AUD_FORMAT_WAV_OKI_ADPCM        0x0010
#define AVI_SP_AUD_FORMAT_WAV_DVI_ADPCM        0x0011
#define AVI_SP_AUD_FORMAT_WAV_DIGISTD          0x0015
#define AVI_SP_AUD_FORMAT_WAV_DIGIFIX          0x0016
#define AVI_SP_AUD_FORMAT_WAV_YAMAHA_ADPCM     0x0020
#define AVI_SP_AUD_FORMAT_WAV_DSP_TRUESPEECH   0x0022
#define AVI_SP_AUD_FORMAT_WAV_GSM610           0x0031
#define AVI_SP_AUD_FORMAT_IBM_MULAW            0x0101
#define AVI_SP_AUD_FORMAT_IBM_ALAW             0x0102
#define AVI_SP_AUD_FORMAT_IBM_ADPCM            0x0103
#define AVI_SP_AUD_FORMAT_AMR_CBR              0x7A21
#define AVI_SP_AUD_FORMAT_AMR_VBR              0x7A22
#define AVI_SP_AUD_FORMAT_AMR_WB               0xA104
#define AVI_SP_AUD_FORMAT_FAAD_AAC             0x706D
#define AVI_SP_AUD_FORMAT_HDX4_AAC             0x0AAC
#define AVI_SP_AUD_FORMAT_MPEG2AAC             0x0180
#define AVI_SP_AUD_FORMAT_AAC                  0xA106
#define AVI_SP_AUD_FORMAT_AAC2                 0x00ff
#define AVI_SP_AUD_FORMAT_YMPEG                0x7000
#define AVI_SP_AUD_FORMAT_MPEG                 0x0050
#define AVI_SP_AUD_FORMAT_MPEGLAYER3           0x0055

typedef struct
{
    kal_uint32 u4ChunkId; /* use in index list, this value save ref time */
    kal_uint32 u4Flag;
    kal_uint32 u4ChunkOffset;
    kal_uint32 u4ChunkLength;
} AVI_SP_INDEX_T;

/* flags for AVI_SP_INDEX_T */
#define AVI_SP_IF_LIST             0x00000001
#define AVI_SP_IF_KEY_FRAME        0x00000010
#define AVI_SP_IF_NO_TIME          0x00000100
#define AVI_SP_IF_COMP_USE         0x0FFF0000
#define AVI_SP_IF_MTK_PARTIAL_DATA 0x10000000

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    kal_uint32 u4ChunkIdx; /* chunk index: time information */
    kal_uint32 u4Offset; /* offset in idx1 */
} AVI_SP_VBR_ENTRY_T;

typedef struct
{
    void* pvEntry;
    kal_uint32 u4MaxEntries;
    kal_uint32 u4NumEntries;
    kal_uint32 u4Granularity;
    kal_uint32 u4Counter; /* u4Counter<u4NumEntries*u4Granularity, u4Counter >= (u4NumEntries-1)*u4Granularity */
    //kal_uint32 u4LastRefTime; /* the entry must be a key frame */
    kal_uint32 u4RangeRefEndTime; /* the end time of last frame */
    kal_uint32 u4LastFileAddr;
} AVI_SP_SEEK_TABLE_T;

typedef struct
{
    STFSAL *prFsal;
    kal_bool fgVBR;
    kal_uint32 u4StreamNum; /* stream track number */
    kal_uint32 u4EntryOffset; /* index entry offset in file */
    kal_uint32 u4CurrentRefTime; /* current chunk start reference time */
    kal_uint32 u4CurrentRefEndTime; /* current chunk reference time */
    kal_uint32 u4IndexEndAddr;    
    kal_uint32 u4AdjustSize; /* adjust size of "movi" and "##ss size" */
} AVI_SP_IDX1_MGR_T; 

typedef struct
{
    AVI_SP_FILE_HEADER_T rFileHeader;
    AVI_SP_STREAM_HEADER_T rVidStreamHdr[AVI_SP_VID_STREAM_NUM];
    AVI_SP_STREAM_HEADER_T rAudStreamHdr[AVI_SP_AUD_STREAM_NUM];
    AVI_SP_VIDEO_FORMAT_HEADER_T rVidFormatHdr[AVI_SP_VID_STREAM_NUM];
    AVI_SP_AUDIO_FORMAT_HEADER_T rAudFormatHdr[AVI_SP_AUD_STREAM_NUM];

    SPIF_VIDEO_STREAM_INFO_T rVideoInfo[AVI_SP_VID_STREAM_NUM]; /* info for source component */
    SPIF_AUDIO_STREAM_INFO_T rAudioInfo[AVI_SP_AUD_STREAM_NUM]; /* info for source component */

    AVI_SP_SEEK_TABLE_T rVideoSeekTable;
    AVI_SP_SEEK_TABLE_T rAudioSeekTable;
    kal_uint32 u4VideoNum;
    kal_uint32 u4AudioNum;
    
    kal_uint32 u4MoviAddr;
    kal_uint32 u4IndexAddr;
    kal_uint32 u4IndexEndAddr;
    kal_uint32 u4MoviOffset; /* index offset could start from file (0) or movi start (point to "movi" fourCC), MoviOffset + offset point to "##ss" */
    kal_uint32 u4VideoRefTotalTime;
    kal_uint32 u4AudioRefTotalTime;
    
    kal_bool fgQuickClose;
    kal_bool fgAbort[SOURCE_PROVIDER_PORT_MAX];
#ifdef __VE_VIDEO_CLIPPER_SUPPORT__    
    kal_bool fgMtkFile;
#endif    
#ifdef __VE_PARSE_TRANSFORMATION_INFO__ 
    SPIF_TRANSFORMATION_INFO_T rTransformation;
#endif
} AVI_SP_PARSER_INFO_T;

typedef struct
{
    void *pvSourceHandle;
    SP_API_T *prSourceAPI;    
} AVI_SP_SRC_HANDLE_T;

typedef struct
{
    STFSAL rFsalFileInfo;
    STFSAL rFsalVideo;
    STFSAL rFsalAudio;
    STFSAL rFsalVideoIdx;
    STFSAL rFsalAudioIdx;

    FS_FileLocationHint *prSeekHintBuf;
    kal_uint8 *pu1FileInfoBuf;
    kal_uint8 *pu1VideoIdxBuf;
    kal_uint8 *pu1AudioIdxBuf;    
} AVI_SP_FILE_T;

#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__
typedef struct
{
    kal_bool fgVBR;
    AVI_SP_FETCH_SIZE_T eFetch;
    kal_uint32 u4FetchSize; /* process by eFetch value */
    kal_uint32 u4DataOffset;
    kal_uint32 u4CurRefEndTime;
} AVI_SP_NO_INDEX_CTRL_T;    
#endif

typedef struct
{
    kal_bool fgEnable; // this stream enable or not
    kal_uint32 u4SelectNum;
} AVI_SP_SETTING_T;

typedef struct
{
    AVI_SP_STATE_T eState;
    kal_uint64 u8StartTime;
    kal_uint64 u8EndTime;
    kal_uint64 u8CurrentTime;
    kal_uint32 u4BuffStartAddr; /* bitstream start address */
    kal_uint32 u4BuffSize; /* bitstream size */
    AVI_SP_EOF_T eEof;
    //kal_bool fgStreamEnable;
    kal_bool fgSendEof;
    PROVIDER_ERROR_T eError;

    // list info
    AVI_SP_IDX1_MGR_T rIndexStatus;
    AVI_SP_INDEX_T rCurrentIndex;
    //AVI_SP_INDEX_T *prListItem;
    VIDEO_CORE_RING_BUFFER_MGR_T rList;

#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__
    AVI_SP_NO_INDEX_CTRL_T rNoIndexCtrl;
#endif    
} AVI_SP_CONTROL_T;

typedef struct
{
    kal_uint8 *pu1TempBuf;
    AVI_SP_INDEX_T *prAListItem;
    AVI_SP_INDEX_T *prVListItem;
} AVI_SP_MEM_INFO_T;

typedef struct
{
    kal_uint32 u4AudioDirectRead;
    kal_uint32 u4VideoDirectRead;
    kal_uint32 u4AudioIdxRead;
    kal_uint32 u4VideoIdxRead;
    kal_uint32 u4AudioExitGap;
    kal_uint32 u4VideoExitGap;
    kal_uint32 u4AudioExitFull;
    kal_uint32 u4VideoExitFull;
} AVI_SP_PROFILE_T;

typedef struct
{
    // from source
    AVI_SP_SRC_HANDLE_T rSrcHandle;
    SPIF_PROVIDER_OPEN_INFO_T rOpenInfo;
    
    AVI_SP_FILE_T rFile;
    AVI_SP_PARSER_INFO_T rParser;
    AVI_SP_MEM_INFO_T rMemInfo;

    AVI_SP_SETTING_T rVideoUserSetting;
    AVI_SP_SETTING_T rAudioUserSetting;
    
    AVI_SP_CONTROL_T rVideoControl;
    AVI_SP_CONTROL_T rAudioControl;

#ifdef __VE_SP_AVI_PROFILE__
    AVI_SP_PROFILE_T rProfile;
#endif    
} AVI_SP_PROVIDER_CONTEXT_T;

#if defined(__VE_SP_AVI__)
extern PROVIDER_ERROR_T AviProviderGetHandle(void *pvSrcHandle, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr);
extern PROVIDER_ERROR_T AviProviderReleaseHandle(void* pvHandle);
extern kal_bool AviProviderCheckIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len);
#endif /* #if defined(__VE_SP_AVI__) */

#endif /* _AVI_PROVIDER_H */

