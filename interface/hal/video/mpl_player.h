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
 * mpl_player.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file defines MediaPortingLayer interface of video player.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 08 2013 gary.huang
 * removed!
 * .
 *
 * 06 21 2012 eason.lin
 * removed!
 * .
 *
 * 05 30 2012 eason.lin
 * removed!
 * .
 *
 * 05 17 2012 elsie.yen
 * removed!
 * .
 *
 * 05 14 2012 eason.lin
 * removed!
 * .
 *
 * 04 23 2012 eason.lin
 * removed!
 * .
 *
 * 03 20 2012 eason.lin
 * removed!
 * .
 *
 * 03 20 2012 eason.lin
 * removed!
 * .
 *
 * 03 19 2012 eason.lin
 * removed!
 * .
 *
 * 02 15 2012 eason.lin
 * removed!
 * .
 *
 * 02 10 2012 leroy.lin
 * removed!
 * .
 *
 * 02 09 2012 leroy.lin
 * removed!
 * .
 *
 * 02 09 2012 leroy.lin
 * removed!
 * .
 *
 * 01 19 2012 eason.lin
 * removed!
 * .
 *
 * 12 22 2011 eason.lin
 * removed!
 * .
 *
 * 12 21 2011 eason.lin
 * removed!
 * .
 *
 * 12 02 2011 eason.lin
 * removed!
 * .
 *
 * 11 30 2011 pibben.tung
 * removed!
 * .
 *
 * 11 27 2011 eason.lin
 * removed!
 * .
 *
 * 10 24 2011 annu.wang
 * removed!
 * .
 *
 * 10 11 2011 gary.huang
 * removed!
 * .
 *
 * 09 30 2011 annu.wang
 * removed!
 * .
 *
 * 08 17 2011 annu.wang
 * removed!
 * .
 *
 * 08 11 2011 annu.wang
 * removed!
 * .
 *
 * 07 26 2011 annu.wang
 * removed!
 * .
 *
 * 07 07 2011 stella.yang
 * removed!
 * .
 *
 * 05 31 2011 annu.wang
 * removed!
 * .
 *
 * 05 20 2011 annu.wang
 * removed!
 * .
 *
 * 04 14 2011 annu.wang
 * removed!
 * .
 *
 * 04 13 2011 stella.yang
 * removed!
 * .
 *
 * 04 01 2011 stella.yang
 * removed!
 * .
 *
 * 03 03 2011 annu.wang
 * removed!
 * .
 *
 * 02 18 2011 annu.wang
 * removed!
 * .
 *
 * 02 16 2011 annu.wang
 * removed!
 * .
 *
 * 02 10 2011 annu.wang
 * removed!
 * .
 *
 * 12 19 2010 stella.yang
 * removed!
 * .
 *
 * 11 30 2010 stella.yang
 * removed!
 * .
 *
 * 09 10 2010 stella.yang
 * removed!
 * .
 *
 * 08 27 2010 stella.yang
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MPL_PLAYER_H
#define _MPL_PLAYER_H

#include "kal_general_types.h"
#include "mpl_common.h" // the common defition for MPL
#include "SubtitleFont_if.h"

#if defined(__VIDEO_ARCHI_V2__)
#include "hal_custom_video_if.h"
#endif

#if !defined(__MODEM_COMPONENT__) && !defined(__MODEM_PRODUCT__)
#include "video_subtitle_decoder_custom_if.h"
#else
#define VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL                   0
#define VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL                  0
#endif  // !defined(__MODEM_COMPONENT__) && !defined(__MODEM_PRODUCT__)


/*
 * Interface to allocate / free media external memory
 */

/*****************************************************************************
 * DESCRIPTION
 *  Parameters of player interface
 *****************************************************************************/
typedef enum
{
    MPL_PARAM_CURRENT_PLAY_TIME,        /* [kal_uint64 *] To GET current play time of player */
    MPL_PARAM_AUD_FORMAT,               /* [kal_uint16 *] To GET audio format of the opened video file */
    MPL_PARAM_AUD_VOLUME,               /* [kal_uint8 *]  To GET/SET audio volume level of player */
    MPL_PARAM_FILE_HANDLE,              /* [kal_uint32 *] To GET file handle opened by player */
    MPL_PARAM_DISPLAY,                  /* [kal_uint32 *] To SET display device to player */
    MPL_PARAM_DUMMY_AUD_PLAYING,        /* [kal_bool *] To GET if dummy audio is playing */
    MPL_PARAM_AUD_PLAYING,              /* [kal_bool *] To GET if audio is playing */
    MPL_PARAM_STOP_TIME,                /* [kal_uint64 *] To SET stop time */
    MPL_PARAM_TIME_TO_FRAME,            /* [mpl_player_param_time_and_frame_mapping_t *] To GET frame index from time */
    MPL_PARAM_FRAME_TO_TIME,            /* [mpl_player_param_time_and_frame_mapping_t *] To GET time from frame index */
    MPL_PARAM_SLEEP_TIME,               /* [kal_uint64 *] To SET sleep time */
    MPL_PARAM_MAX_VID_FRAME_TIME,       /* [kal_uint64 *] To GET max received vid frame time */
    MPL_PARAM_BRIGHTNESS,               /* [kal_uint32 *] To SET brightness */
    MPL_PARAM_CONTRAST,                 /* [kal_uint32 *] To SET contrast */
    MPL_PARAM_AUD_TIME_DIFF,            /* [kal_uint32 *] To SET delta time of audio frames, the audio maybe lost in the streaming case or un-aligned in the begin of file play */
    MPL_PARAM_IS_SEEKABLE,              /* [kal_bool *] To GET if player is seekable, TRUE: support seek, FALSE: do not support seek */
    MPL_PARAM_AUD_ADD_HEADER,           /* [kal_bool *] To SET player that adts header is needed to set aac format */
    MPL_PARAM_IS_LCD_UPDATED,           /* [kal_bool *] To GET LCD was updated by renderer or not */
    MPL_PARAM_VID_TRACK,                /* [kal_bool *] To GET video track information */
    MPL_PARAM_GET_STREAMING_BUFFER_INFO,/* [kal_bool *] To GET video track information */
    MPL_PARAM_SET_FONT_SIZE,            /* [kal_uint8 *] Set the font size for subtitle. Default is 16*/
    MPL_PARAM_GET_SUBTITLE_TRACKS,      /* [mpl_player_track_info_t*] Get subtitle track information*/
    MPL_PARAM_SET_SUBTITLE_TRACKS,      /* [kal_uint32*] Set the subtitle track for playing*/
    MPL_PARAM_GET_STREAMING_BUFFER_STATUS, /* [mpl_player_streaming_buffer_status_t *] To GET buffer status on video streaming */
    MPL_PARAM_GET_KEYFRAME_TIME,        /* [mpl_player_param_query_keyframe_time_t *] Get the time of the key frame just before the specified time*/
    MPL_PARAM_IS_PROPRIETARY_FORMAT,    /* [kal_bool *] To GET whether the file is recorded with proprietary format */
    MPL_PARAM_TOTAL_COUNT

}mpl_player_param_enum;

typedef struct
{
    //Input
    kal_uint32 u4StreamIdx;
    //Output
    kal_uint32 u4Free;
    kal_uint32 u4Total;
    kal_bool fgBufferHigh;
} mpl_player_streaming_buffer_status_t;

/*****************************************************************************
 * DESCRIPTION
 *  Parameter structure of track info
 *****************************************************************************/

typedef enum
{
    MPL_TRACK_DEFAULT = 0xFF
}mpl_vid_track_enum;

typedef enum
{
    MPL_VIDEO_2D_NORMAL,
    MPL_VIDEO_3D
} mpl_video_track_type_enum;

typedef struct
{
    kal_uint32 u4TrackIndex;
    mpl_video_track_type_enum eVidTrackType;
} mpl_player_video_track_info_t;

typedef struct
{
    kal_uint32 u4Num;
    void *pvTrackInfo;
}mpl_player_track_info_t;

typedef struct
{
    kal_uint32 u4TrackIndex;
    kal_uint32 u4Language;
}mpl_player_subtitle_track_info_t;

/*****************************************************************************
 * DESCRIPTION
 *  Parameter structure of time & frame mapping
 *****************************************************************************/
typedef struct
{
    kal_uint64 time;
    kal_uint32 frame;
}mpl_player_param_time_and_frame_mapping_t;

/*****************************************************************************
 * DESCRIPTION
 *  Sturcture for querying the time of the key frame just before a specific t-
 *  me
 *****************************************************************************/
typedef struct
{
    kal_uint64 u8Time_IN;
    kal_uint64 u8KeyFrameTime_OUT;
}mpl_player_param_query_keyframe_time_t;

/*****************************************************************************
 * DESCRIPTION
 *  Parameter structure of sleep time
 *****************************************************************************/
typedef struct
{
    kal_uint8 elapse_ticks;
    kal_uint8 sleep_ticks;
}mpl_player_param_sleep_time_t;

/*****************************************************************************
 * DESCRIPTION
 *  Enum/structure of open request
 *****************************************************************************/
typedef enum
{
    MED_VID_AUDIO_ONLY      = (0x1),
    MED_VID_VISUAL_ONLY     = (0x1<<1),
    MED_VID_BOTH            = (MED_VID_AUDIO_ONLY | MED_VID_VISUAL_ONLY),
    MED_VID_META            = (0x1<<2),
    MED_VID_SUBTITLE        = (0x1<<3)
}med_track_enum;

typedef enum
{
    MPL_DECODER,
    MPL_QVGA,
    MPL_PREVIEW,
    MPL_CIF,
    MPL_INFO,
    MPL_MPEG4_DECODER,
    MPL_DECODER_N_SUBTITLE,
    MPL_UPTO_QVGA,
    MPL_UPTO_CIF,    
    MPL_QVGA_MPEG4SP,
    MPL_MAX_SCENARIO = 0xFF
}mpl_scenario_enum;

typedef enum
{
    MPL_OPEN_PARAM,
    MPL_SEEK_PARAM,
    MPL_GET_FRAME_PARAM,
    MPL_PLAY_PARAM,
    MPL_GET_MOT_META
}mpl_player_param_type_enum;

typedef enum
{
    MED_VID_FRAME_STRETCH,
    MED_VID_FRAME_FIT_OUTSIDE,
    MED_VID_FRAME_FIT_INSIDE
}med_frame_enum;

typedef enum
{
    MPL_RENDERER_3D_MODE_OFF = 0,
    MPL_RENDERER_3D_MODE_SIDE_BY_SIDE,
    MPL_RENDERER_3D_MODE_TOP_DOWN
}mpl_renderer_3d_mode_enum;

typedef enum
{
    MPL_THUMBNAIL_NONE = 0,
    MPL_THUMBNAIL_JPG  = 1,
    MPL_THUMBNAIL_PNG  = 2,
    MPL_THUMBNAIL_BMP  = 3 
} mpl_thumbnail_type_enum;

typedef kal_uint32 (*PFN_IS_LCC_SUPPORTED)(kal_uint32 u4ISO);

typedef struct
{
	subtitle_fontengine_struct* prFontEngineApi;
	PFN_IS_LCC_SUPPORTED pfnIsLCCSupported;
} mpl_player_external_api_t;

typedef struct
{
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 data_size;
    med_track_enum open_track;
    kal_bool enable_aud_only;   /* allows to open aud only video */
    kal_uint16 app_id;
    kal_uint16 scenario_id;     /* Give a scenario usage */
    kal_int32 *file_handle;      /* FS_HANDLE */
    mpl_player_external_api_t rExternalAPI;
    kal_bool fgCloseAudBTA2DPforOpen;
}mpl_player_open_t;

/**************************************
* Parameters
*
* @stop_on_decode_errors:
*  - 1: video track would be considered erroneous when decoder found some errors consecutively
*  - 0 (default): disable callbacks for decoder errors
*************************************/
typedef struct
{
    kal_uint8 get_frame;
    kal_uint64 time;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_bool force_seek;
    med_track_enum seek_track;
    kal_int16 idp_rotate;
    kal_uint8 image_data_format;
    med_frame_enum frame_mode;
    kal_bool stop_on_decode_errors;
}mpl_player_seek_t;

typedef struct
{
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 idp_rotate;
    kal_uint8 image_data_format;
    med_frame_enum frame_mode;
    mpl_renderer_3d_mode_enum e3DMode;
    void *subtitle_image_buffer_p;
    kal_uint16 subtitle_width;
    kal_uint16 subtitle_height;
    kal_uint8 subtitle_data_format;
}mpl_player_get_frame_t;

typedef struct
{
    kal_wchar *title_desc_ptr;
    kal_uint16 title_desc_len;

    kal_wchar *artist_desc_ptr;
    kal_uint16 artist_desc_len;

    kal_wchar *date_desc_ptr;
    kal_uint16 date_desc_len;

    kal_wchar *annotation_desc_ptr;
    kal_uint16 annotation_desc_len;

    kal_wchar *type_desc_ptr;
    kal_uint16 type_desc_len;

   kal_uint8 *thumbnail_data_ptr;
   kal_uint32 thumbnail_data_allocated_len;
   kal_uint32 thumbnail_data_usaged_len;

   mpl_thumbnail_type_enum thumbnail_type;
}mpl_player_get_mot_meta_t;

typedef struct
{
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 display_offset_x;
    kal_uint16 display_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 contrast;
    kal_int16 brightness;
    kal_int16 play_speed;
    kal_uint8 play_audio;
    kal_uint8 display_device;
    kal_uint8 audio_path;
    kal_int16 lcd_rotate;
    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_bool force_lcd_hw_trigger;
    kal_int16 idp_rotate;
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    med_frame_enum frame_mode;
    mpl_renderer_3d_mode_enum e3DMode;
    kal_uint32 subtitle_layer_element;
    kal_uint32 subtitle_blt_ctx;
    kal_uint32 subtitle_blt_dev;
    void *subtitle_image_buffer_p;
    kal_uint16 subtitle_width;
    kal_uint16 subtitle_height;
    kal_uint8 subtitle_data_format;
}mpl_player_play_t;

typedef struct
{
    kal_wchar *title_desc_ptr;
    kal_uint8 title_desc_len;

    kal_wchar *artist_desc_ptr;
    kal_uint8 artist_desc_len;

    kal_wchar *album_desc_ptr;
    kal_uint8 album_desc_len;

    kal_wchar *author_desc_ptr;
    kal_uint8 author_desc_len;

    kal_wchar *copyright_desc_ptr;
    kal_uint8 copyright_desc_len;

    kal_wchar *date_desc_ptr;
    kal_uint8 date_desc_len;

}mpl_player_get_meta_t;

typedef enum
{
    MED_NO_TRACK = 0x00,
    MED_AUDIO_TRACK = 0x01,
    MED_VISUAL_TRACK = 0x02,
    MED_BOTH_TRACK = 0x03
}
med_vid_track_enum;

typedef struct
{
    kal_uint64 duration;
    kal_uint64 vid_duration;
    kal_uint64 aud_duration;
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 audio_channel_num;
    kal_uint32 audio_sampling_rate;
    kal_uint8  track_info;
    kal_uint32 total_frame_num;
    kal_int32 file_handle;
    kal_uint32 aud_format;
    const void* sdp;
}mpl_player_get_media_info_t;

/*****************************************************************************
 * DESCRIPTION
 *  Parameter structure of private data payload
 *****************************************************************************/
typedef struct
{
    unsigned int u4PayloadNumber;
    void *pu1PayloadAddress;
    
#ifdef __VE_KMV_SUPPORT__
    void *pu1KMVPayloadAddress;
    kal_uint32 u4KMVSize;  
#endif

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

/* MED Audio function callback */
typedef void (*PFN_AUD_STRETCH_CLOSE_T)(void);
typedef kal_int32 (*PFN_AUD_STRETCH_SET_SPEED_T)(kal_uint16 speed);
typedef void (*PFN_AUD_BT_A2DP_OPEN_CODEC_T)(kal_int32 audio_format);
typedef void (*PFN_AUD_BT_A2DP_CLOSE_FOR_OPEN_T)(void);
typedef void (*PFN_AUD_GET_ACTIVE_DEVICE_PATH_BY_MODE_T)(kal_uint8 request_path, void (*set_path_func)(kal_uint8));
typedef void (*PFN_AUD_MELODY_SET_OUTPUT_DEVICE_T)(kal_uint8 device);

/* each component should implement this type*/
typedef struct
{
    PFN_AUD_STRETCH_CLOSE_T                     pfn_aud_stretch_close;
    PFN_AUD_STRETCH_SET_SPEED_T                 pfn_aud_stretch_set_speed;
    PFN_AUD_BT_A2DP_OPEN_CODEC_T                pfn_aud_bt_a2dp_open_codec;
    PFN_AUD_BT_A2DP_CLOSE_FOR_OPEN_T            pfn_aud_bt_a2dp_close_codec_for_open;
    PFN_AUD_GET_ACTIVE_DEVICE_PATH_BY_MODE_T    pfn_aud_get_active_device_path_by_mode;
    PFN_AUD_MELODY_SET_OUTPUT_DEVICE_T          pfn_aud_melody_set_output_device;
} MED_AUD_CALLBACK_FUNC_T;

extern void mpl_session_set_med_audio_callback(MED_AUD_CALLBACK_FUNC_T *pfn);

/////////////////////////////////
/////// Control struct //////////
/////////////////////////////////

/*****************************************************************************
 * DESCRIPTION
 *  Controls of player; Currently, we have two controls: Progressive Download and Video Editor controls.
 *  Each control has its interface to be implemented, if you do not support those special features, you may not need to implement those.
 */
typedef enum
{
    PLAYER_CONTROL_DL,          /* player_control_dl_t */
    PLAYER_CONTROL_LIVE,        /* player_control_dl_t */
} mpl_player_control_t;

/*****************************************************************************
 * DESCRIPTION
 *  Query capability of MPL player
 */
typedef struct
{
    kal_bool b_IsBitstreamMemInternal;  /* [kal_bool] To GET who is the supplier of bitstream buffer */
} mpl_player_capability_t;

//////////////////////////////////////////////
/////// Control: Progressive Download ////////
//////////////////////////////////////////////

/*****************************************************************************
 * DESCRIPTION
 *  Interface of download control, you must implement those two interfaces if you need to support video downlaod related functions.
 */
typedef struct mpl_player_ctrl_dl_t mpl_player_ctrl_dl_t;
struct mpl_player_ctrl_dl_t
{
    media_error_t (*get_percent)(mpl_player_ctrl_dl_t* itf, kal_uint32* percentage_p); /* Is pdl ready to play */

    media_error_t (*get_max_time)(mpl_player_ctrl_dl_t* itf, kal_uint64 *max_time_p);  /* get pdl max play time */
};

/*****************************************************************************
 * DESCRIPTION
 *  Event type of player;
 */
typedef enum
{
    MPL_PLAYER_EVENT_OPEN,  /* open event callback */
    MPL_PLAYER_EVENT_SEEK,  /* seek event callback */
    MPL_PLAYER_EVENT_PLAY,  /* play event callback */
    MPL_PLAYER_EVENT_CLOSE  /* close event callback */
} mpl_player_event_t;

/*****************************************************************************
 * DESCRIPTION
 *  Callback functions of open, play, seek and get_snapshot are defined here.
 */
typedef struct mpl_player_client_t mpl_player_client_t;
struct mpl_player_client_t
{
    /* Memory allcator and free api. */
    void* (*mem_alloc_func)(mpl_player_client_t *client, kal_uint32 size, med_mem_type_enum type, char* file_p, long line_p);

    void (*mem_free_func)(mpl_player_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p);

    void (*on_event)(mpl_player_client_t *client, mpl_player_event_t event, media_error_t result); /* On event, when an opeartion is an async call, this must be called after the operation are finished. */
};

/*****************************************************************************
 * DESCRIPTION
 *  This defines the interfaces which should be implemented to support basic functions of video player.
 */
typedef struct mpl_player_t mpl_player_t;
struct mpl_player_t
{
    /* To open the video file. (sync or async)*/
    media_error_t (*open)(mpl_player_t* itf, mpl_player_open_t* open_struct);
    media_error_t (*play)(mpl_player_t* itf, mpl_player_play_t* play_struct);
    media_error_t (*stop_play)(mpl_player_t* itf);
    /* To do seek operation. (sync or async) */
    media_error_t (*seek)(mpl_player_t* itf, mpl_player_seek_t* seek_struct);
    media_error_t (*stop_seek)(mpl_player_t* itf);
    media_error_t (*get_frame)(mpl_player_t* itf, mpl_player_get_frame_t* frame_struct);
    media_error_t (*get_param)(mpl_player_t* itf, mpl_player_param_enum param, void *value);
    media_error_t (*set_param)(mpl_player_t* itf, mpl_player_param_enum param, void *value);
    media_error_t (*get_meta)(mpl_player_t* itf, mpl_player_get_meta_t *meta_struct);
    media_error_t (*get_media_info)(mpl_player_t* itf, mpl_player_get_media_info_t* media_info_struct);
    /* To get thumbnail. Before 09A you may not implement this. */
    media_error_t (*get_thumbnail) (mpl_player_t* itf, void* iframe_struct);
    /* To query special ability by getting control,
       if returns MED_S_OK, it means that we support this special features,
       if returns MED_E_FAIL, it means that we did not support this features. */
    media_error_t (*get_control)(mpl_player_t* itf, mpl_player_control_t control_id, void** control);
    media_error_t (*close)(mpl_player_t* itf);
    /* To resume render */
    media_error_t (*resume_visual_update)(mpl_player_t* itf, mpl_player_play_t* play_struct);
    /* To pause render */
    media_error_t (*pause_visual_update)(mpl_player_t* itf);
    /* To release visual content */
    media_error_t (*release_visual)(mpl_player_t* itf);
    media_error_t (*add_video_stream)(mpl_player_t* itf, media_stream_t* stream, kal_uint32* stream_index);
    media_error_t (*add_audio_stream)(mpl_player_t* itf, media_stream_t* stream, kal_uint32* stream_index);
    media_error_t (*prepare)(mpl_player_t* itf);
    media_error_t (*deliver)(mpl_player_t* mp, kal_uint32 stream_index, media_data_t* media_data);
    media_error_t (*get_buff_status)(mpl_player_t* mp, kal_uint32 u4StreamIdx, kal_uint32 *pu4Free, kal_uint32 *pu4Total);
    media_error_t (*notify_eos)(mpl_player_t* mp, kal_uint32 stream_index);
    media_error_t (*get_default)(mpl_player_t* mp, mpl_player_param_type_enum param_id, void* default_param);
    void (*destroy)(mpl_player_t* itf);
    media_error_t (*get_mot_meta)(mpl_player_t* itf, mpl_player_get_mot_meta_t *meta_struct);
};

extern kal_bool media_session_init(void);
extern mpl_player_t* construct_media_session(mpl_player_client_t* client);
extern media_error_t* query_mpl_player_capability(mpl_player_capability_t* capability);
extern media_error_t mp4_mp_is_prog_dl_file(kal_uint8* p_file_buf, kal_uint32 buf_size, kal_bool* is_pdl);
extern media_error_t mp4_mp_scramble_buffer(kal_uint8* p_file_buf, kal_uint32 buf_size);


#define VIDEO_SUBTITLE_RECT_MAX_WIDTH   VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL
#define VIDEO_SUBTITLE_RECT_MAX_HEIGHT  VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL

#ifdef CUSTOMIZE_MAX_SUBTITLE_TRACK_NUMBER
    #define MPL_SESSION_MAX_SUBTITLE_TRACK_NUM (CUSTOM_SUBTITLE_TRACK_NUMBER)
    #if ((CUSTOM_SUBTITLE_TRACK_NUMBER > 16)||(CUSTOM_SUBTITLE_TRACK_NUMBER < 1))
        #error "CUSTOM_SUBTITLE_TRACK_NUMBER can only be set between 1 and 16"
    #endif
#else
    #define MPL_SESSION_MAX_SUBTITLE_TRACK_NUM  (4)
#endif

#endif /* _MPL_PLAYER_H */

