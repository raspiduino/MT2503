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
 *   avi_muxer_v2.h
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
 *
 ****************************************************************************/
#include "drv_features_video.h"

#ifndef __AVI_MUXER_V2_H__
#define __AVI_MUXER_V2_H__

//#include "fsal.h"
#include "fs_type.h"

#include "video_muxer_if_v2.h"
#include "avi_muxer_if_v2.h"

#define _AVI_SIZE_OF_WORKING_PATH_BUFFER    (_MAX_FILE_NAME_N_PATH)
#define _AVI_SIZE_OF_FILE_NAME_BUFFER       (_MAX_FILE_NAME_N_PATH)
#define _AVI_MAX_FILE_SIZE_OF_AVI_10        (2U * 1024U * 1024U * 1024U - 1U)  //for AVI 1.0: size < 2GB

#define _AVI_VISUAL_FILE                    (L"~avi_visual.tmp")
#define _AVI_IDX_FILE                       (L"~avi_idx.tmp")
#define _AVI_INFO_FILE                      (L"~avi_info.tmp")

#define _AVI_IF_LIST             (0x00000001)
#define _AVI_IF_KEY_FRAME        (0x00000010)
#define _AVI_IF_NO_TIME          (0x00000100)
#define _AVI_IF_COMP_USE         (0x0FFF0000)

#define _AVI_TAG_RIFF            (0x46464952)//("RIFF")
#define _AVI_TAG_AVI             (0x20495641)//("AVI ")
#define _AVI_TAG_LIST            (0x5453494C)//("LIST")
#define _AVI_TAG_JUNK            ("JUNK")

/* MJPEG */
#define _AVI_TAG_MJPG            ("MJPG")
/* MPEG-4 */
#define _AVI_TAG_MP4V            ("MP4V")
#define _AVI_TAG_XVID            ("XVID")
#define _AVI_TAG_DX50            ("DX50")
#define _AVI_TAG_DIVX            ("DIVX")
#define _AVI_TAG_DIV5            ("DIV5")
#define _AVI_TAG_3IVX            ("3IVX")
#define _AVI_TAG_3IV2            ("3IV2")
#define _AVI_TAG_RMP4            ("RMP4")
#define _AVI_TAG_FMP4            ("FMP4")
/* H.263 */
#define _AVI_TAG_H263            ("H263")
#define _AVI_TAG_S263            ("S263")
/* H.264 */
#define _AVI_TAG_AVC1            ("AVC1")
#define _AVI_TAG_DAVC            ("DAVC")
#define _AVI_TAG_H264            ("H264")
#define _AVI_TAG_X264            ("X264")

#define _AVI_TAG_HEADER_LIST     (0x6C726468)//("hdrl")
#define _AVI_TAG_AVI_HEADER      (0x68697661)//("avih")
#define _AVI_TAG_STREAM_LIST     (0x6C727473)//("strl")
#define _AVI_TAG_STREAM_HEADER   (0x68727473)//("strh")
#define _AVI_TAG_STREAM_FORMAT   (0x66727473)//("strf")
#define _AVI_TAG_MOVI            (0x69766F6D)//("movi")
#define _AVI_TAG_IDX1            ("idx1")
#define _AVI_TAG_STREAM_TYPE_VID ("vids")
#define _AVI_TAG_STREAM_TYPE_AUD ("auds")
#define _AVI_TAG_WB              ("  wb")
#define _AVI_TAG_DC              ("  dc")
#define _AVI_TAG_DB              ("  db")

/*video clipper*/
#define _AVI_TAG_IUAM           (0x4D415549)//("IUAM")
#define _AVI_MTK_BOX_SIZE       24
#define _AVI_MTK_BOX_CONTENT    ("http://www.mediatek.com")

// Rotation/Mirror information
#define _AVI_TAG_TRNS           (0x534E5254)//("TRNS")
#define _AVI_TRNS_CHUNK_SIZE    4

#define _AVI_AUD_FORMAT_WAV_PCM              0x0001

#define _SIZE_4CC           4
#define _SIZE_LIST_TAG      4
#define _SIZE_LIST_NAME     4
#define _SIZE_LIST_SIZE     4
#define _SIZE_CHUNK_SIZE    4

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
} _AVI_STREAM_HEADER_T;

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
} _AVI_FILE_HEADER_T;

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
} _AVI_VIDEO_FORMAT_HEADER_T;

typedef struct
{
    kal_uint16 format;
    kal_uint16 channels;
    kal_uint32 sample_per_sec;
    kal_uint32 avg_byte_per_sec;
    kal_uint16 block_align;
    kal_uint16 bit_per_sample;
    kal_uint16 size;
} _AVI_AUDIO_FORMAT_HEADER_T;

typedef struct
{
    kal_uint32 chunk_id;
    kal_uint32 flag;
    kal_uint32 chunk_offset;
    kal_uint32 chunk_lenght;
} _AVI_INDEX_T;


typedef struct
{
    //kal_uint32 u4Format;
    kal_uint32 u4SampleRate;
    kal_uint32 u4Channel;
    kal_uint32 u4BitPerSample;
} _AVI_AUDIO_CONFIG_T;

typedef struct
{
    kal_uint32 u4Format;
    kal_uint16 u2Width;
    kal_uint16 u2Height;
    kal_uint32 u4FrameRate;
    //kal_uint32 u4VideoRate;    /* u4VideoRate/u4VideoScale = frame rate*/
    //kal_uint32 u4VideoScale;
} _AVI_VIDEO_CONFIG_T;

typedef struct
{
    kal_uint16 u2Rotation;
    kal_uint8  u1HorizontalMirror;
    kal_uint8  u1VerticalMirror;
}_AVI_TRANSFORMATION_INFO_T;

typedef enum
{
    AVAILABLE,
    WAITING_2_WRITE,
} _AVI_BUFF_STATE_T;

typedef struct
{
    MUXER_AUDIO_CONFIG_T rAudioConfig;
    MUXER_VIDEO_CONFIG_T rVideoConfig;
    kal_uint64 u8SizeLimit;
    kal_wchar *pau2FilePath;
    kal_wchar *pau2WorkingPath;
    PFN_CALLBACK pfnCallback;
    kal_uint32 u4TimeLimit;
    MUXER_SCENARIO_T eScenario;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    kal_uint32 u4TLFrameRate;
#endif
} _AVI_CONFIG_T;

typedef struct
{
    kal_uint32  u4VideoFrameNum;
    kal_uint32  u4AudioDataWritten;
    kal_uint32  u4TotalAVDataWritten;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    kal_uint32 u4TLFrameRate;
#endif
    MUXER_VIDEO_CONFIG_T rVideoConfig;
    MUXER_AUDIO_CONFIG_T rAudioConfig;
} _AVI_INFO_T;

typedef struct
{
    kal_uint32 u4BufferNum;
    kal_uint32 u4BufferSize;
    kal_uint32 au4BuffWritten[_AVI_MAX_BUFFER_NUM];
    kal_uint8* apu1Buff[_AVI_MAX_BUFFER_NUM];
    kal_uint32 u4WriteThreshold;
    _AVI_BUFF_STATE_T aeBuffState[_AVI_MAX_BUFFER_NUM];
    kal_uint8 u1ActiveBuffIdx;
    kal_uint8 u1Next2WriteBuffidx;
} _AVI_BUFFER_CTRL_T;

typedef struct
{
    kal_uint64  u8TimeStamp;
    kal_uint32  u4DataType;     //MX_DATATYPE_UNKNOWN
    kal_uint32  u4Size;
    MUXER_BUFFER_T  arData[MAX_BUFFER_PARTITION];
    kal_bool    fgIsValid;
    kal_bool    fgHeaderValid;
} AVI_UNFINISHED_PARAM_T;


typedef struct
{
#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
    AVI_UNFINISHED_PARAM_T  rUnfinishedBuffer;
    kal_uint8               u1IdxBuffer[sizeof(_AVI_INDEX_T)];
    kal_uint32              u4IdxBufferSize;
#endif
    kal_uint8 *pau1DataFileName;
    kal_uint8 *pau1IdxFileName;
    FS_HANDLE rDataHandle;
    FS_HANDLE rIdxHandle;
    FS_HANDLE rInfoHandle;
    kal_uint32 u4DataFileSize;
    kal_uint32 u4IdxFileSize;

    kal_uint32 u4TotalAVDataWritten;
    kal_uint32 u4AVDataOffset;

    kal_uint32 u4MaxAudioDataWritten;
    kal_uint32 u4AudioDataWritten;
    kal_uint32 u4VideoFrameNum;

    _AVI_BUFFER_CTRL_T* prDataBuffCtrl;
    _AVI_BUFFER_CTRL_T* prIdxBuffCtrl;

    kal_uint32 u4LastFrameRemainder;
    kal_uint64 u8CurrentFileSize;

    kal_uint32 u4ClusterSize;
    kal_uint64 u8FreeDiskSize;

    kal_mutexid rMutex;
    kal_int32 i4FSRet;

    kal_bool fgSetSizeLimit;
} _AVI_MUXER_CTRL_T;

#define _AVI_WRITEDATA_THRESHOLD     (_AVI_ONE_DATA_BUFF_SIZE)
#define _AVI_WRITEINDEX_THRESHOLD    (_AVI_ONE_IDX_BUFF_SIZE)

#define AVI_ASSERT(expr)    \
        do{                 \
            if(!(expr)){    \
                ASSERT(0);  \
            }               \
        }while(0)

#endif // __AVI_MUXER_V2_H__
