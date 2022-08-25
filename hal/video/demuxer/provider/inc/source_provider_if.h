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

#ifndef SOURCE_PROVIDER_IF_H
#define SOURCE_PROVIDER_IF_H

#include "fsal.h"
#include "mpl_player.h"
#include "mpl_common.h"
#include "mpl_session_mem.h"
#include "video_types_v2.h"


/*********************************************************
  MED Part
  *********************************************************/

/***************************
   enum
  ***************************/
typedef enum
{
    SOURCE_PROVIDER_ERROR_NONE = 0,
    SOURCE_PROVIDER_ERROR,  /* general error case */
    SOURCE_PROVIDER_ASSERT_ERROR,
    SOURCE_PROVIDER_ERROR_TIMEOUT,
    SOURCE_PROVIDER_ERROR_BUF_FULL,
    SOURCE_PROVIDER_ERROR_MEM_LACK
}SP_ERROR_TYPE_T;

typedef enum
{
    SOURCE_PROVIDER_TRACK_AUDIO     = (0x1<<0),       
    SOURCE_PROVIDER_TRACK_VIDEO     = (0x1<<1), 
    SOURCE_PROVIDER_TRACK_SUBTITLE  = (0x1<<2), 
    SOURCE_PROVIDER_TRACK_META      = (0x1<<3)         
} SP_TRACK_T;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    SOURCE_PROVIDER_MP4 = 0,
    SOURCE_PROVIDER_AVI,
    SOURCE_PROVIDER_RM,
    SOURCE_PROVIDER_FLV,
    SOURCE_PROVIDER_STREAMING,
    SOURCE_PROVIDER_MKV,
    SOURCE_PROVIDER_MAX
} SP_FILE_TYPE_T;

typedef enum
{
    SOURCE_RPOVIDER_NONE = 0,
    SOURCE_PROVIDER_SEEK = 0x1
} SP_CAPABILITY_T;

typedef enum
{
    SOURCE_PROVIDER_PORT_AUDIO = 0x0,
    SOURCE_PROVIDER_PORT_VIDEO,
    SOURCE_PROVIDER_PORT_SUBTITLE,
    SOURCE_PROVIDER_PORT_MAX
} SP_PORT_TYPE_T;

typedef enum
{
    SOURCE_PROVIDER_SEARCH_FORWARD = 0,           /**< the search keyframe direction for feature time */
    SOURCE_PROVIDER_SEARCH_BACKWARD,              /**< the search keyframe direction for past time */
} SP_SEARCH_DIR_T;

typedef enum
{
    SOURCE_PROVIDER_TRACK_NORMAL = 0,           /**< Normal track */
    SOURCE_PROVIDER_TRACK_PRIVATE_3D,           /**< Private 3D track */
} SP_TRACK_PROPERTY;

typedef enum
{
    SOURCE_PROVIDER_FLAG_OUTPUT_PORT = 0x1,
    SOURCE_PROVIDER_FLAG_SEEK_TIME = 0x1<<1,
    SOURCE_PROVIDER_FLAG_GET_KEY_FRAME_TIME = 0x1<<2,
    SOURCE_PROVIDER_FLAG_FLUSH_STREAM_BUFFER = 0x1<<3,
    SOURCE_PROVIDER_FLAG_QUERY_FRAME_BUF = 0x1<<4
} SP_CONTROL_FLAG_T;

typedef enum
{
    SOURCE_RPOVIDER_THUMBNAIL_ONE = 0,
    SOURCE_PROVIDER_THUMBNAIL_JPG = 0x1,
    SOURCE_PROVIDER_THUMBNAIL_PNG = 0x2,
    SOURCE_PROVIDER_THUMBNAIL_BMP = 0x3
} SP_THUMBNAIL_TYPE_T;
/***************************
   struct
  ***************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    void * pvHandle; /* IL client handle */
    SP_TRACK_T eTrack;
    med_mode_enum eOpenType; /* media open type */
    SP_FILE_TYPE_T eFileType;  /* media file extension type */
    kal_uint8* pu1Data; /* file path or buffer start address */
    kal_uint32 u4Size; /* buffer length */
    MPL_SESSION_MEM_API_T *prAPI;
    //MPL_SESSION_EMPTY_BUFFER_API_T *prEmptyAPI;
    //VIDEO_EXTMEM_HANDLER_T *prExtMemHandle; // Help to do: modify new handle and new API that provider from il client
} SPIF_MEDIA_INFO_T;

typedef struct
{
    kal_uint32 u4StreamIndex;
    media_codec_type_t eCodecType;
    kal_uint64 u8Duration;    /* stream duration. zero if unknown */
    kal_uint32 u4Width;        /* picture width */
    kal_uint32 u4Height;       /* picture height */
    kal_uint32 u4Fps;                 /* frames per second. Can be zero if the value is unknown. */
    kal_uint32 u4AvgBitrate;   /* average bits per second */
    SP_TRACK_PROPERTY eProperty;
} SPIF_VIDEO_STREAM_INFO_T;

typedef struct
{
    // cook
    kal_uint32 u4Samples;
    kal_uint32 u4Regions;
    kal_uint32 u4CplStart;
    kal_uint32 u4CplQBits;
    kal_uint32 u4BitPerFrame;
} SPIF_AUDIO_RA_INFO;

typedef struct
{
    kal_uint32 u4StreamIndex;
    media_codec_type_t eCodecType;
    kal_uint64 u8Duration;    /* stream duration. zero if unknown */
    kal_uint16 u2Channels;            /* number of channels */
    kal_uint16 u2BitsPerSample; /* bits per sample */
    kal_uint32 u4SampleRate;        /* sample rate, in samples per second */
    kal_uint32 u4FrameDuration;    // us, frame length, cook only(u4Samples * 1000000 / u4SampleRate)
    kal_bool fgAddHeader;   // for AAC with header case

    union
    {
        SPIF_AUDIO_RA_INFO rAudioRA;
    } uCodec;
} SPIF_AUDIO_STREAM_INFO_T;

typedef struct
{
    kal_uint32 u4StreamIndex;
    media_codec_type_t eCodecType;
    kal_uint64 u8Duration;    /* stream duration. zero if unknown */
    kal_uint32 u4Language;
    kal_bool fgDefault;   // Default track
} SPIF_SUBTITLE_STREAM_INFO_T;

typedef struct
{
    kal_bool fgSupport;
    kal_uint32 u4Num;
    void *pvStreamInfo;
} SPIF_STREAM_INFO_T;

typedef struct
{
    kal_wchar *pu2Author;
    kal_uint16 u2AuthorLen;
    kal_wchar *pu2Album;
    kal_uint16 u2AlbumLen;
    kal_wchar *pu2Copyright;
    kal_uint16 u2CopyrightLen;

    kal_wchar *pu2Title; // movie name
    kal_uint16 u2TitleLen;
    kal_wchar *pu2Artist; // movie star
    kal_uint16 u2ArtistLen;
    kal_wchar *pu2Date; //record date
    kal_uint16 u2DateLen;

    kal_wchar *pu2Annotation; //comment
    kal_uint32 u4AnnotationLen;
    kal_wchar *pu2Type ; //file category
    kal_uint16 u2TypeLen;
    kal_uint8 *pu1ThumbnailData; //=> Thumbnail
    kal_uint32 u4ThumbnailDataAllocatedLen;
    kal_uint32 u4ThumbnailDataUsagedLen;
    SP_THUMBNAIL_TYPE_T eThumbnailType;  //=> thumbnail type
} SPIF_META_DATA_T;

typedef struct
{
    kal_uint64 u8StartTime;  /* input: search stat time */
    SP_PORT_TYPE_T ePort; /* choice audio or video */
    SP_SEARCH_DIR_T eDirect; /* seach direct */
    kal_uint64 u8KeyFrameTime; /* output */
} SPIF_KEY_FRAME_TIME_T;

typedef struct
{
    SP_PORT_TYPE_T ePort; /* choice audio or video */
    kal_uint32 u4Frame;
    kal_uint64 u8FrameTime;
} SPIF_FRAME_TIME_T; /* for frame2time or time2frame*/

typedef struct
{
    SP_PORT_TYPE_T ePort; /* choice audio or video */
    kal_uint32 u4FreeBuf;
    kal_uint32 u4TotalBuf;
    kal_bool fgBufferHigh;
} SPIF_STREAMING_BUF_INFO_T; 

typedef struct
{
    SP_PORT_TYPE_T eType;
    kal_bool fgEndTimeSendEof; /* send eof when playback reach end time*/
    kal_bool fgOnlyUpdateTime;  /* it doesn't clear buffer of header and bitstream */
    kal_uint64 u8StartTime; /* play start point, ms */
    kal_uint64 u8EndTime;  /* play end point, ms */
} SPIF_SEEK_TIME_T;

typedef struct
{
    SP_PORT_TYPE_T eType;
    kal_uint64 u8SetTime;
} SPIF_DIRECT_SEEK_TIME_T;

typedef struct
{
    SP_PORT_TYPE_T eType;
    kal_bool fgEnable;
} SPIF_PORT_T;

typedef struct
{
    SP_PORT_TYPE_T eType;
    kal_uint8 u1Track;
} SPIF_STREAM_T;

typedef struct
{
    SP_PORT_TYPE_T eType;
} SPIF_FLUSH_BUF_T;

typedef struct
{
    SP_PORT_TYPE_T eType;
    kal_uint8 u1Track;
    kal_uint64 u8Input;
    kal_uint64 u8Output;
} SPIF_COMMON_INFO_T;

typedef struct
{
    kal_uint64 u8AudioAvailDur; /* current available duration to audio */
    kal_uint64 u8VideoAvailDur; /* current available duration to video */
    kal_uint32 u4AudioRestBitstreamSize; /* rest audio bitstream size from start_time */
    kal_uint32 u4VideoRestBitstreamSize; /* rest video bitstream size from start_time */
    kal_uint32 u4AudioBufPercentage; /* usage of audio buffer in provider */
    kal_uint32 u4VideoBufPercentage; /* usage of video buffer in provider */
} SPIF_BUF_INFO_T;

typedef struct
{
    kal_uint32 start_time;
    SPIF_BUF_INFO_T *prBufStatus;   
} SPIF_BUF_STATUS_T; /* PGDL buffer status */

typedef struct
{
    kal_uint64 u8LastTime;
    kal_uint32 u4PredictionLength;   
} SPIF_STREAMING_SILENT_INFO_T; 

typedef struct
{
    kal_int32 file_handle; /* handle of file */
} SPIF_DRM_INFO_T; 

typedef struct
{
    SP_PORT_TYPE_T eType;
    kal_bool fgEnable;
} SPIF_ABORT_INFO_T;

typedef struct
{
    kal_bool fgVideo;
    kal_bool fgAudio;
    kal_bool fgSubtitle;
} SPIF_SNED_HEADER_T; 

typedef struct
{
    kal_uint16 u2Rotation;
    kal_uint8 u1HorizontalMirror;
    kal_uint8 u1VertialMirror;
} SPIF_TRANSFORMATION_INFO_T; 

typedef struct
{
    kal_uint8 configurationVersion;
    kal_uint8 AVCProfileIndication;
    kal_uint8 profile_compatibility;
    kal_uint8 AVCLevelIndication;
    kal_uint8 lengthSizeMinusOne;
} SPIF_AVC_CONF_RECORD_T;


typedef struct
{
	kal_uint8  kmvMeta[400];//KMV_META_LEN
	kal_uint16 recH;
	kal_uint16 recW;
	kal_uint16 nsize;
	kal_uint8  tType;

} SPIF_KMV_DECODER_PAYLOAD_INFO_T;


typedef struct
{
    SP_PORT_TYPE_T eType;  //input
    SP_CONTROL_FLAG_T u4ControlFlag; //output
    kal_bool fgParserError; //output
} SPIF_PORT_INFO_T;

/***************************
   extern frunction
  ***************************/
#ifdef __VE_SOURCE_PROVIDER__  
extern void SourceProviderSrcMain(ilm_struct *prIlm);
extern VIDEO_ERROR_TYPE_T GetSourceProviderHandle(SPIF_MEDIA_INFO_T *prMediaInfo, void *pvSrcHandle, VIDEO_COMPONENT_MI_TYPE_T **prSrcType);
extern VIDEO_ERROR_TYPE_T ReleaseSourceProviderHandle(void *pvHandle);
extern SP_FILE_TYPE_T SourceProviderContainerType(med_mode_enum eOpenType, kal_uint8* pu1Data, kal_uint32 u4Size);
extern VIDEO_ERROR_TYPE_T SourceProviderStreamingAddHeader(void* pvHandle, SP_PORT_TYPE_T eType, media_dec_config_t *prConfig);
extern VIDEO_ERROR_TYPE_T SourceProviderStreamingAddData(void* pvHandle, SP_PORT_TYPE_T eType, media_data_t *prData, SPIF_STREAMING_SILENT_INFO_T *prSilentInfo);
extern VIDEO_ERROR_TYPE_T SourceProviderStreamingAddEof(void* pvHandle, SP_PORT_TYPE_T eType, kal_uint64 u8EndTime);
#endif

/*********************************************************
  Provider Part
  *********************************************************/


/***************************
   enum
  ***************************/
typedef enum
{
    PROVIDER_ERROR_NONE = 0,
    PROVIDER_ERROR, /* general case */
    PROVIDER_ERROR_WAIT_DATA,
    PROVIDER_ERROR_EOF,
    PROVIDER_ERROR_WAIT_RESOURCE,
    PROVIDER_ERROR_NOT_FINISH,
    PROVIDER_ERROR_NOT_SUPPORT,
    PROVIDER_ERROR_TERMINATE,
    PROVIDER_ERROR_DELAY_REPORT_WITH_EOF
} PROVIDER_ERROR_T;

typedef enum
{
    PROVIDER_PARAM_VID_STREAM_INFO,
    PROVIDER_PARAM_AUD_STREAM_INFO,
    PROVIDER_PARAM_SUBS_STREAM_INFO,
    PROVIDER_PARAM_META_DATA,
    PROVIDER_PARAM_META_CAPABILITY,
    PROVIDER_PARAM_KEY_FRAME_TIME,
    PROVIDER_PARAM_TIME_TO_FRAME,
    PROVIDER_PARAM_FRAME_TO_TIME,
    PROVIDER_PARAM_DRM_FSAL,
    PROVIDER_PARAM_SEEK_TIME,
       //PROVIDER_PARAM_DIRECT_SEEK,
    PROVIDER_PARAM_SELECT_STREAM,
    PROVIDER_PARAM_DESELECT_STREAM,
    PROVIDER_PARAM_SEND_HEADER,
    //PROVIDER_PARAM_SEND_VIDEO_HEADER,
    PROVIDER_PARAM_QURERY_FRAME_BUF,
    PROVIDER_PARAM_QUICK_CLOSE,
    PROVIDER_PARAM_ABORT_PROCESS,
    PROVIDER_PARAM_MTK_FILE,
    PROVIDER_PARAM_TRANSFORMATION_INFO,
    PROVIDER_PARAM_AVC_CONF_RECORD,
    PROVIDER_PARAM_3D_SBS,
    PROVIDER_PARAM_HEADER_INFO,
    PROVIDER_PARAM_MAX
} PROVIDER_PARAM_TYPE_T;

/***************************
   struct
  ***************************/
typedef struct
{
    kal_bool fgBufMode;
    kal_bool fgSetBuffer;
    kal_bool fgSetSeekHint;
    STFSAL* prFileHandle;
    kal_uint8* pu1Data; /* file path or buffer start address */
    kal_uint32 u4Size; /* buffer length */
    kal_uint8* pu1SetBuf;
    kal_uint32 u4SetBufSize;
    FS_FileLocationHint *prSeekHint; /* FSAL seek hint */
    kal_uint32 u4SetHintSize;
} SPIF_OPEN_INFO_T;

typedef struct
{
    SP_TRACK_T eOpenTrack;
    med_mode_enum eOpenType;
    kal_uint8 *pu1Data;
    kal_uint32 u4DataSize;
} SPIF_PROVIDER_OPEN_INFO_T;

typedef struct
{
    kal_uint8 *pu1Addr;
    kal_uint32 u4FrameSize;
    kal_uint64 u8Timestamp;
    kal_uint32 u4PayloadNum; // video only, the item in payload
    kal_uint32 u4PayloadSize; //video only, the total size of payload
    kal_uint8 *pu1Payload;

    kal_uint32 u4KMVPayloadSize;
    kal_uint8 *pu1KMVPayload;

    kal_bool fgKeyFrame;
    kal_bool fgHeader;
    kal_bool fgEof;
    kal_bool fgSilent;  // audio only
} SPIF_PROVIDER_FRAME_INFO_T;

typedef struct
{
    SP_PORT_TYPE_T eType; //input
    kal_bool fgHeader; 
} SPIF_PROVIDER_HEADER_INFO_T;

/******************************************************************************
  * The function table
 ******************************************************************************/
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_OPEN_T) (void *pvHandle, SPIF_PROVIDER_OPEN_INFO_T *prInfo);
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_CLOSE_T) (void *pvHandle);
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_INIT_T) (void *pvHandle);
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_DE_INIT_T) (void *pvHandle);
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_GET_PARAMETER_T)(void *pvHandle, PROVIDER_PARAM_TYPE_T  eCmd, void *pParam);
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_SET_PARAMETER_T)(void *pvHandle, PROVIDER_PARAM_TYPE_T  eCmd, void * pParam);
typedef PROVIDER_ERROR_T (*PFN_PROVIDER_PARSE_T) (void *pvHandle, kal_uint32 *pu4Time);

// Provider implement API
typedef struct
{
    PFN_PROVIDER_OPEN_T PFN_OPEN;
    PFN_PROVIDER_CLOSE_T PFN_CLOSE;
    PFN_PROVIDER_INIT_T PFN_INIT;
    PFN_PROVIDER_DE_INIT_T PFN_DE_INIT;
    PFN_PROVIDER_GET_PARAMETER_T PFN_GET_PARAMETER;
    PFN_PROVIDER_SET_PARAMETER_T PFN_SET_PARAMETER;
    PFN_PROVIDER_PARSE_T PFN_PARSE_VIDEO;
    PFN_PROVIDER_PARSE_T PFN_PARSE_AUDIO;
    #ifdef __VE_SUBTITLE_SUPPORT__
    PFN_PROVIDER_PARSE_T PFN_PARSE_SUBTITLE;
    #endif
} PROVIDER_API_T;

typedef void* (*SPFN_SP_MEM_SET_T) (void *pVoid, kal_int32 u4Value,kal_uint32 u4Size);
typedef void (*SPFN_SP_MEM_COPY_T) (void *pDest, void *pSrc, kal_uint32 u4Size);
typedef void* (*SPFN_SP_MALLOC_CLA_T) (void *pvHandle, kal_uint32 u4Size, kal_bool fgCacheable);
typedef void (*SPFN_SP_FREE_CLA_T) (void *pvHandle, void *pVoid);
typedef kal_uint32 (*SPFN_SP_BITSTREAM_BUF_SIZE_T) (void *pvHandle, SP_PORT_TYPE_T ePort);
typedef kal_uint32 (*SPFN_SP_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE_T) (void *pvHandle, SP_PORT_TYPE_T ePort, kal_uint32 u4RequiredSize, kal_uint32 *u4AllocatedSize);
typedef void (*SPFN_SP_BITSTREAM_BUF_UPDATA_ADD_T)(void *pvHandle, SP_PORT_TYPE_T ePort, kal_uint32 u4Add);
typedef PROVIDER_ERROR_T (*SPFN_SP_ADD_ONE_DATA_T)(void *pvHandle, SP_PORT_TYPE_T ePort, SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo);
typedef PROVIDER_ERROR_T (*SPFN_SP_BASE_FILE_OPEN_T)(SPIF_OPEN_INFO_T *rOpenInfo);

// provider use these function to obtain system resource
typedef struct
{
    SPFN_SP_MEM_SET_T SPFN_MEM_SET;
    SPFN_SP_MEM_COPY_T SPFN_MEM_COPY;
    SPFN_SP_MALLOC_CLA_T SPFN_MALLOC_CLA;
    SPFN_SP_FREE_CLA_T SPFN_FREE_CLA;
    SPFN_SP_BITSTREAM_BUF_SIZE_T SPFN_BITSTREAM_BUF_SIZE;
    SPFN_SP_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE_T SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE;
    SPFN_SP_BITSTREAM_BUF_UPDATA_ADD_T SPFN_BITSTREAM_BUF_UPDATA_ADD;
    SPFN_SP_ADD_ONE_DATA_T SPFN_ADD_ONE_DATA;
    SPFN_SP_BASE_FILE_OPEN_T SPFN_BASE_FILE_OPEN;
} SP_API_T;

/***************************
   For extneral function interface
  ***************************/
typedef struct
{
    void *pvHandle;
    PROVIDER_API_T *prAPI;
} SPIF_PROVIDER_HANDLE_T;

/*********************************************************
  Decoder Part
  *********************************************************/
/*
typedef struct
{
    unsigned int u4PayloadNumber;
    void *pu1PayloadAddress;
} SPIF_DECODE_PAYLOAD_T;

typedef struct
{
    kal_uint32 u4Address;
    kal_uint32 u4Length;
} SPIF_H264_DECODER_PAYLOAD_INFO_T;

typedef struct
{
    kal_uint32 u4Address;
    kal_uint32 u4Length;
    kal_bool  fgValid;
} SPIF_RM_DECODER_PAYLOAD_INFO_T;
*/

#endif // SOURCE_PROVIDER_IF_H

