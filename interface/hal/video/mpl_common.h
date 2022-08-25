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
 * Filename:
 * ---------
 * mpl_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes function prototypes of media porting layer.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MPL_COMMON_H_
#define _MPL_COMMON_H_

#include "kal_general_types.h"
#include "l1audio.h"


/* Defines */

#define MPL_MAX_FILE_NAME_LEN  261



/* Basic types */

/* this shall be sync with aud_defs.h, backward compatible */
typedef enum
{
    MED_TYPE_NONE           = -1,
    MED_TYPE_GSM_FR         = MEDIA_FORMAT_GSM_FR,        /* 0 */
    MED_TYPE_GSM_HR         = MEDIA_FORMAT_GSM_HR,        /* 1 */
    MED_TYPE_GSM_EFR        = MEDIA_FORMAT_GSM_EFR,       /* 2 */
    MED_TYPE_AMR            = MEDIA_FORMAT_AMR,           /* 3 */
    MED_TYPE_AMR_WB         = MEDIA_FORMAT_AMR_WB,        /* 4 */
    MED_TYPE_DAF            = MEDIA_FORMAT_DAF,           /* 5 */
    MED_TYPE_AAC            = MEDIA_FORMAT_AAC,           /* 6 */
    MED_TYPE_PCM_8K         = MEDIA_FORMAT_PCM_8K,        /* 7 */
    MED_TYPE_PCM_16K        = MEDIA_FORMAT_PCM_16K,       /* 8 */
    MED_TYPE_G711_ALAW      = MEDIA_FORMAT_G711_ALAW,     /* 9 */
    MED_TYPE_G711_ULAW      = MEDIA_FORMAT_G711_ULAW,     /* 10 */
    MED_TYPE_DVI_ADPCM      = MEDIA_FORMAT_DVI_ADPCM,     /* 11 */
    MED_TYPE_VR             = MEDIA_FORMAT_VRD,           /* 12 */
    MED_TYPE_WAV            = MEDIA_FORMAT_WAV,           /* 13 */
    MED_TYPE_WAV_ALAW       = MEDIA_FORMAT_WAV_ALAW,      /* 14 */
    MED_TYPE_WAV_ULAW       = MEDIA_FORMAT_WAV_ULAW,      /* 15 */
    MED_TYPE_WAV_DVI_ADPCM  = MEDIA_FORMAT_WAV_DVI_ADPCM, /* 16 */
    MED_TYPE_SMF            = MEDIA_FORMAT_SMF,           /* 17 */
    MED_TYPE_IMELODY        = MEDIA_FORMAT_IMELODY,       /* 18 */
    MED_TYPE_SMF_SND        = MEDIA_FORMAT_SMF_SND,       /* 19 */
    MED_TYPE_MMF            = MEDIA_FORMAT_MMF,           /* 20 */
    MED_TYPE_AU             = MEDIA_FORMAT_AU,            /* 21 */
    MED_TYPE_AIFF           = MEDIA_FORMAT_AIFF,          /* 22 */
    MED_TYPE_VRSI           = MEDIA_FORMAT_VRSI,          /* 23 */
    MED_TYPE_WMA            = MEDIA_FORMAT_WMA,           /* 24 */
    MED_TYPE_M4A            = MEDIA_FORMAT_M4A,           /* 25 */
    MED_TYPE_BSAC           = MEDIA_FORMAT_BSAC,          /* 31 */
    MED_TYPE_MUSICAM        = MEDIA_FORMAT_MUSICAM,       /* 32 */
    MED_TYPE_APE            = MEDIA_FORMAT_APE,           /* 42 */
    MED_TYPE_TONE           = MEDIA_FORMAT_JTS,           /* 44 : JTone */
    MED_TYPE_VORBIS         = MEDIA_FORMAT_VORBIS,
    MED_TYPE_FLAC           = MEDIA_FORMAT_FLAC,
    MED_TYPE_KURO           = MEDIA_FORMAT_UNKNOWN,       /* 45: The types that are not re-mappable to Media_Format should start from here */
    MED_TYPE_KURO_AAC,      /* 46 */
    MED_TYPE_RMVB,          /* 47 */
    MED_TYPE_RM,            /* 48 */
    MED_TYPE_RA,            /* 49 */
    MED_TYPE_RV,            /* 50 */
    MED_TYPE_MIDI,          /* 51 : JMidi */
    MED_TYPE_3GP,           /* 52 */
    MED_TYPE_MP4,           /* 53 */
    MED_TYPE_JPG,           /* 54 */
    MED_TYPE_GIF,           /* 55 */
    MED_TYPE_MJPG,          /* 56 */
    MED_TYPE_PNG,           /* 57 */
    MED_TYPE_AVI,           /* 58 */
    MED_TYPE_FLV,           /* 59 */
    MED_TYPE_F4V,           /* 60 */
    MED_TYPE_MOV,           /* 61 */
    MED_TYPE_MKV,           /* 62 */
    MED_TYPE_F4A,           /* 63 */
    MED_TYPE_MOT,
    MED_TYPE_YTS,
    MED_TYPE_KMV,
    MED_NO_OF_TYPE
}med_type_enum;

typedef enum
{
    /* success code */

    MED_S_OK                    = 0,        /**< the result is okay */
    MED_S_FALSE                 = 1,        /**< no error generally */
    MED_S_ASYNC                 = 2,        /**< the operation is asynchronous */
    MED_S_TERMINATED            = 3,
    MED_S_PLAY_FINISH           = 4,

    /* generic errors */
    MED_E_RESERVED              = -1,
    MED_E_FAIL                  = -2,
    MED_E_WRONG_STATE           = -3,
    MED_E_INVALID_PARAM         = -4,
    MED_E_RESOURCE_CONFLICT     = -5,
    MED_E_NOT_IMPLEMENTED       = -6,
    MED_E_NOT_SUPPORTED         = -7,
    MED_E_OVER_LIMIT            = -8,
    MED_E_OUT_OF_MEMORY         = -9,
    MED_E_BUSY                  = -10,
    MED_E_ABORTED               = -11,
    MED_E_CORRUPTED_DATA        = -12,
    MED_E_NO_MORE_DATA          = -13,
    MED_E_UNSUPPORTED_FORMAT    = -14,
    MED_E_FSAL_ERROR            = -15,
    MED_E_PARSER_ERROR          = -16,
    MED_E_OPEN_FILE_FAIL        = -17,
    MED_E_PDL_SHORT_OF_BUF      = -18,
    MED_E_NO_REQUIRED_TRACK     = -19,
    MED_E_FRAME_RATE_TOO_HIGH   = -20,
    MED_E_INVALID_RESOLUTION    = -21,
    MED_E_AUDIO_ERROR           = -22,
    MED_E_VIDEO_ERROR           = -23,
    MED_E_BAD_FORMAT            = -24,
    MED_E_MEM_INSUFFICIENT      = -25,
    MED_E_DECODER_NOT_SUPPORT   = -26,
    MED_E_STOP_TIME_REACHED     = -27,
    MED_E_PDL_AUDIO_UNDERFLOW   = -28,
    MED_E_PDL_VIDEO_UNDERFLOW   = -29,
    MED_E_MP4_NO_VIDEO_TRACK    = -30,
    MED_E_NO_DISC               = -31,
    MED_E_DISC_FULL             = -32,
    MED_E_WRITE_PROTECTION      = -33,
    MED_E_END_OF_FILE           = -34,
    MED_E_ERROR                 = -35,
    MED_E_MP4_PRODUCER_ERROR    = -36,
    MED_E_MP4_SAMPLEDATA_ERROR  = -37,
    MED_E_VIDEO_NO_FRAME_ENCODED = -38,
    MED_E_BUFFER_INSUFFICIENT   = -39,
    MED_E_SIZE_LIMIT_LESS_THAN_MIN_SIZE = -40,
    MED_E_TERMINATING           = -41,      /* An error occured, and video recording is terminating. There will be a callback to the layer above MPL later. */
    MED_E_VIDEO_TRACK_ERROR     = -42,
    MED_E_AUDIO_TRACK_ERROR     = -43,
    MED_E_MASS_STORAGE_MODE     = -44,      /* write protection in mass storage mode */
    MED_E_FS_ERROR              = -45,      /* file system error */

    MED_E_STREAM_BASE                   = -100,
    MED_E_STREAM_INVALID_SDP            = MED_E_STREAM_BASE - 1,
    MED_E_STREAM_UNSUPPORTED_CODEC      = MED_E_STREAM_BASE - 2,
    MED_E_STREAM_UNSUPPORTED_BANDWIDTH  = MED_E_STREAM_BASE - 3,
    MED_E_STREAM_BUFFER_UNDERFLOW       = MED_E_STREAM_BASE - 4,
    MED_E_STREAM_BUFFER_OVERFLOW        = MED_E_STREAM_BASE - 5,
    MED_E_STREAM_AV_UNSYNC              = MED_E_STREAM_BASE - 6,
    MED_E_STREAM_BUFFER_HIGH            = MED_E_STREAM_BASE - 7,
    MED_E_STREAM_RTP_ERROR			   		  = MED_E_STREAM_BASE - 8,

    MED_E_STREAM_RTSP_BASE              = -200,
    MED_E_STREAM_RTSP_SET_CHANNEL_FAIL  = MED_E_STREAM_RTSP_BASE - 1,
    MED_E_STREAM_RTSP_REQUEST_FAIL      = MED_E_STREAM_RTSP_BASE - 2

} media_error_t;

typedef enum
{
    MED_MODE_STREAM = 0,        /* Streaming media mode */
    MED_MODE_FILE,              /* File media mode */
    MED_MODE_ARRAY,             /* Array media mode */
    MED_MODE_BUFFER,            /* Buffer mode, used for camera capture, media task allocate the capture buffer and return the address, release the buffer when camera power off. */
    MED_MODE_EDITOR_FILE,       /* File for video editor, will store the context */
    MED_MODE_PDL_FILE,          /* Progressive DL video file */
    MED_MODE_PREVIEW,          /* preview*/
    MED_MODE_MOT_FILE,          /* mot mode file */
    MED_MODE_MOT_PREVIEW,       /* mot mode preview */
    MED_MODE_YTS_FILE,          /* .yts format file*/
    MED_MODE_PDL_YTS_FILE,      /* .yts format Progressive DL*/
    MED_MODE_CMMB,               /*same like MED_MODE_STREAM but add enhancement according to the characristics of the bitstream from CMMB*/
    MED_MODE_KMV_FILE,          /* kmv mode file */
    MED_MODE_KMV_PREVIEW,       /* kmv mode preview */
    MED_NO_OF_MODE
}med_mode_enum;

typedef kal_uint64 media_time_t;

typedef enum
{
    MEDIA_DATA_FLAG_KEY_FRAME     = 0x01,     /**< key frame */
    MEDIA_DATA_FLAG_DISCONTINUITY = 0x02,     /**< specify discontinuity after seeking */
    MEDIA_DATA_FLAG_DECODE_ONLY         = 0x04,     /**< for decode only */
    MEDIA_DATA_FLAG_PARTIAL_FRAME_BEGIN = 0x08,     /**< indicate partial of frame begin */
    MEDIA_DATA_FLAG_PARTIAL_FRAME_END   = 0x10,     /**< indicate partial of frame end */
    MEDIA_DATA_FLAG_WITH_ADTS_HEADER    = 0x20      /**< indicate audio data with adts header */
} media_data_flag_t;

/**
  * Represents a media data. It is the basic unit for data transport in the pipeline.
  */
typedef struct media_data_t
{
    kal_uint8* data;            /**< Data pointer. */
    kal_uint32 size;            /**< Data size, in bytes. */
    media_time_t display_time;  /**< Presentation time */
    media_time_t decode_time;   /**< Decoding time */
    kal_uint32 flags;       /**< Flags to indicate special attributes. @see media_data_flag_t. */
    void* specific_info;    /**< Codec specific info pointer. */

    /**
      * Release it after use.
      */
    void (*release)(struct media_data_t* md);
    struct media_data_t* next; /* Used by media player */
} media_data_t;

/* Media stream */
typedef enum
{
    MEDIA_STREAM_TYPE_UNKNOWN,
    MEDIA_STREAM_TYPE_AUDIO,
    MEDIA_STREAM_TYPE_VIDEO,
    MEDIA_STREAM_TYPE_SUBTITLE    
} media_stream_type_t;

/**
  * Generic audio format info.
  */
typedef struct
{
    kal_uint16 channels;            /**< number of channels */
    kal_uint16 bits_per_sample;     /**< bits per sample */
    kal_uint32 sample_rate;         /**< sample rate, in samples per second */

} media_audio_info_t;

/**
  * Generic video format info.
  */
typedef struct
{
    kal_uint32 width, height;       /**< picture width/height */
    kal_uint32 frame_count;         /**< total frame number. Can be zero if the value is unknown. */
    kal_uint32 fps;                 /**< frames per second. Can be zero if the value is unknown. */
    kal_uint32 avg_bitrate;         /**< average bits per second */

} media_video_info_t;

/**
  * Codec type.
  */
typedef enum
{
    MEDIA_CODEC_NONE = 0,

    /* video */
    MEDIA_CODEC_VID_MPEG4,
    MEDIA_CODEC_VID_H263,
    MEDIA_CODEC_VID_H264,
    MEDIA_CODEC_VID_MJPG,
    MEDIA_CODEC_VID_RV_1,       /**< RealVideo 1.0 */
    MEDIA_CODEC_VID_RV_G2,      /**< RealVideo G2 */
    MEDIA_CODEC_VID_RV_8,       /**< RealVideo 8 */
    MEDIA_CODEC_VID_RV_9,       /**< RealVideo 9 */
    MEDIA_CODEC_VID_RV_10,      /**< RealVideo 10 */
    MEDIA_CODEC_VID_VP8,    

    /* audio */
    MEDIA_CODEC_AUD_AAC,        /* AAC generic, include LC-AAC */
    MEDIA_CODEC_AUD_HE_AAC,     /* aacPlus */
    MEDIA_CODEC_AUD_BSAC,       /* Bit Slice Arithmetic Coding */
    MEDIA_CODEC_AUD_AMR,
    MEDIA_CODEC_AUD_AMR_WB,
    MEDIA_CODEC_AUD_PCM,        /* PCM */
    MEDIA_CODEC_AUD_MPEG,       /* MP2/MUSICAM */
    MEDIA_CODEC_AUD_MPEGLAYER3, /* MP3 */
    MEDIA_CODEC_AUD_RA_VOICE,   /**< RealAudio Voice */
    MEDIA_CODEC_AUD_RA_8_LBR,   /**< RealAudio 8 Low Bitrate */
    MEDIA_CODEC_AUD_RA_8_HBR,  /**< RealAudio 8 High Bitrate */
    MEDIA_CODEC_AUD_VORBIS,

    /* subtitle */
    MEDIA_CODEC_SUB_UTF8,
    MEDIA_CODEC_SUB_SSA,	
	
    MEDIA_CODEC_AUD_DRA
} media_codec_type_t;


#define MAX_NUM_PRP_SIZE 8
/**
  * Copied from RealFormat SDK
  */
typedef struct
{
    kal_uint32 ulLength;
    kal_uint32 ulMOFTag;
    kal_uint32 ulSubMOFTag;
    kal_uint16 usWidth;
    kal_uint16 usHeight;
    kal_uint16 usBitCount;
    kal_uint16 usPadWidth;
    kal_uint16 usPadHeight;
    kal_uint32 ufFramesPerSecond;
    kal_uint32 ulOpaqueDataSize;
    kal_uint8* pOpaqueData;

    /* from OpaqueData */
    kal_uint32 ulMajorBitstreamVersion;
    kal_uint32 ulMinorBitstreamVersion;

    kal_uint32 prp_size;
    kal_uint8* prp_data;

    void*      pCodecInitInfo;

} media_rv_dec_config_t;

/**
  * Copied from RealFormat SDK
  */
typedef struct
{
    kal_uint32 ulSampleRate;
    kal_uint32 ulActualRate;
    kal_uint16 usBitsPerSample;
    kal_uint16 usNumChannels;
    kal_uint16 usAudioQuality;
    kal_uint16 usFlavorIndex;
    kal_uint32 ulBitsPerFrame;
    kal_uint32 ulGranularity;
    kal_uint32 ulOpaqueDataSize;
    kal_uint8* pOpaqueData;

    /* for ra8lbr(cook) only */
    kal_int32 nSamples;
    kal_int32 nRegions;
    kal_int32 delay;
    kal_int32 cplStart;
    kal_int32 cplQBits;

    void*      pCodecInitInfo;

} media_ra_dec_config_t;

typedef struct
{
    kal_uint8 *pu1VOS;
    kal_uint32 u4VOSSize;

} media_video_mpeg4_dec_config_t;

typedef struct
{
    kal_uint8 *pu1Buffer;
    kal_uint32 u4BuffSize;
    void* pPrivateData;

} media_video_h264_dec_config_t;

/**
  * Generic decoder configuration that is used to initialize decoder object.
  */
typedef struct
{
    media_codec_type_t codec;

    union
    {
        media_video_mpeg4_dec_config_t mpeg4;
        media_video_h264_dec_config_t h264;

        media_rv_dec_config_t rv;   /**< RealVideo */
        media_ra_dec_config_t ra;   /**< RealAudio */
    } u;

} media_dec_config_t;

typedef struct
{
    kal_uint32 index;                       /**< stream index */
    kal_uint32 timestamp_resolution;        /**< Reserved. Not used now */
    media_time_t duration;                  /**< stream duration. zero if unknown */
    kal_bool selected;                      /**< is it default stream? */

    media_stream_type_t type;
    union
    {
        media_audio_info_t audio;
        media_video_info_t video;

    } info;   /**< type-specific info */

    media_dec_config_t dec_config;          /**< decoder configuration */

} media_stream_t;

/* Display output device */
enum
{
    MED_DISPLAY_NONE = 0,
    MED_DISPLAY_TO_MAIN_LCD,
    MED_DISPLAY_TO_SUB_LCD,
    MED_NO_OF_DISPLAY_DEVICE
};

typedef enum
{
    MED_MEM_NONCACHE,
    MED_MEM_CACHE,
    MED_MEM_AUD_RINGBUFF
} med_mem_type_enum;

#endif /* _MPL_COMMON_H_ */
