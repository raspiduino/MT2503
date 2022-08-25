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
 *   media_player.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_PLAYER_H
#define _MEDIA_PLAYER_H

#if defined(__VIDEO_ARCHI_V2__)

#include "mpl_common.h" // the common defition for MPL
#include "mpl_player.h"

#include "media_enum.h"

#include "kal_general_types.h"
#include "app_ltlcom.h"
/**
  * Player client.
  */
typedef struct media_player_client_t media_player_client_t;
struct media_player_client_t
{
    /* Memory allcator and free api. */
    void*(*mem_alloc_func) (media_player_client_t *client, kal_int32 size, med_mem_type_enum type, char* file_p, long line_p);

    void (*mem_free_func)  (media_player_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p);

    /**
      * Notifies player event.
      *
      * @param event [IN] Event code.
      * @param event_param [IN] Event-specific parameter.
      */
    void (*on_event)(media_player_client_t* client, media_player_event_t event, kal_int32 event_param);
};

/**
  * This struct contains player configuration.
  */
typedef struct
{
    kal_uint32 quality;

} media_player_config_t;

/**
  * This struct contains video display settings.
  */
typedef struct
{
    void *image_buffer_p;           /**< assume the dimension of GDI layer is the same as LCD screen. */
    //kal_uint32 image_buffer_size;   /**< currently unused. must be 0. */

    kal_uint16 display_width;       /**< width of video */
    kal_uint16 display_height;      /**< height of video */
    //kal_uint16 display_offset_x;    /**< x position of video */
    //kal_uint16 display_offset_y;    /**< y position of video */

    kal_uint8 display_device;       /**< must be MED_DISPLAY_TO_MAIN_LCD */

    kal_uint8 lcd_id;               /**< must be MAIN_LCD */

    kal_uint32 update_layer;        /**< where the video should be drawed to */
    kal_uint32 hw_update_layer;     /**< the layers to show on LCD (inculding video, OSD, or others) */

    kal_bool force_lcd_hw_trigger;

    kal_int16 lcd_rotate;
    kal_bool visible;
    kal_uint32 brightness;
    kal_uint32 contrast;
    kal_uint32 gamma;
    med_frame_enum frame_mode;
    kal_uint16 repeats;             /**< repeat count, 0xffff: infinite */

    kal_int16 idp_rotate;           /**< IDP rotation */
    kal_uint8 image_data_format;
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    
#if MT6228_SERIES || MT6238_SERIES
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239)|| defined(MT6268) ||defined(MT6268A)) */

} media_player_video_config_t;

/**
  * This struct contains audio settings for media player.
  */
typedef struct
{
    kal_uint8 play_audio;
    kal_uint8 audio_path;

} media_player_audio_config_t;

/**
  * This struct contains buffer status of media player.
  */
typedef struct
{
    media_time_t duration;      /**< Buffered media duration, in milliseconds. */
    kal_uint32 free_bytes;      /**< Free space in bytes. */
    kal_uint32 used_bytes;      /**< Used space in bytes. */

} media_stream_buffer_status_t;

/**
  * This struct contains playback parameters. Change of these parameters requires player restart.
  */
typedef struct
{   
    media_player_start_mode_t start_mode;
    kal_uint64 audio_start_time;
    /* For play */
    kal_uint32 play_speed;
    kal_uint64 stop_time;
    kal_bool live_stream;
    kal_bool close_bt_codec;
    
    /* For seek */
    kal_uint8 get_frame;
    kal_uint8 flush_buffer;
} media_player_start_params_t;


/**
  * This struct contains buffer status.
  */
typedef struct
{
    kal_uint32 size; 
    kal_uint32 ring_size;
} media_player_buffer_params_t;

/**
  * This struct contains video resolution
  */
typedef struct
{
    kal_uint32 width; 
    kal_uint32 height;
} media_player_video_resolution_params_t;

/**
  * This struct contains sleep time
  */
typedef struct
{
    kal_uint8 elapse_ticks;
    kal_uint8 sleep_ticks;
} media_player_video_sleep_time_params_t;

/**
  * The parameter which can be dynamically changed when playing
  */
typedef struct
{
    media_player_param_type_t type;
    union
    {
        kal_uint8 volume;
        kal_uint8 brightness;
        kal_uint8 contrast;
        kal_bool playing;
        kal_bool need_aud_frame;
        kal_uint32 play_speed;
        kal_uint32 aud_time_diff;        
        media_time_t time;
        media_player_buffer_params_t aud_buffer;
        media_player_video_resolution_params_t video_size;
        media_player_video_sleep_time_params_t sleep_time;        
    }val;
} media_player_param_t;

typedef void* (*mply_alloc_func) (kal_uint32 size, void* user_data);
typedef void  (*mply_free_func)  (void* ptr, void* user_data);

/* media player */

typedef struct media_player_t media_player_t;

struct media_player_t
{
    /**
      * Opens player and allocates necessary resource for media playback.
      *
      * @param client [IN] A pointer to the client interface.
      * @param config [IN] A pointer to the player configuration.
      */
    media_error_t (*open)(media_player_t* mp, mpl_scenario_enum media_scenario, med_mode_enum media_mode, kal_bool fgSeekable);

    /**
      * Adds a new video stream to the player.
      *
      * @param stream [IN] A pointer to the stream info.
      * @param video_config [IN] A pointer to video configuration.
      * @param stream_index [OUT] A pointer to a variable that receives the index of newly added stream.
      */
    media_error_t (*add_video_stream)(media_player_t* mp, media_stream_t* stream, kal_uint32* stream_index);
    
   /**
      * Adds a new audio stream to the player.
      *
      * @param stream [IN] A pointer to the stream info.
      * @param audio_config [IN] A pointer to audio configuration.
      * @param stream_index [OUT] A pointer to a variable that receives the index of newly added stream.
      */
    media_error_t (*add_audio_stream)(media_player_t* mp, media_stream_t* stream, kal_uint32* stream_index);

    /**
      * Init the player.
      */
    media_error_t (*prepare)(media_player_t* mp);
    
    /**
      * Retrieves video configuration of specified stream.
      *
      * @param stream_index [IN] Index to specify the stream.
      * @param video_config [OUT] A pointer to a struct that receives video configuration.
      */
    media_error_t (*get_video_config)(media_player_t* mp, kal_uint32 stream_index, media_player_video_config_t* video_config);

    /**
      * Updates video configuration of specified stream. Note that some configuration items cannot be updated after the player is started.
      *
      * @param stream_index [IN] Index to specify the stream.
      * @param video_config [IN] A pointer to new video configuration.
      */
    media_error_t (*set_video_config)(media_player_t* mp, kal_uint32 stream_index, media_player_video_config_t* video_config);

    /**
      * Retrieves audio configuration of specified stream.
      *
      * @param stream_index [IN] Index to specify the stream.
      * @param audio_config [OUT] A pointer to a struct that receives audio configuration.
      */
    media_error_t (*get_audio_config)(media_player_t* mp, kal_uint32 stream_index, media_player_audio_config_t* audio_config);

    /**
      * Updates audio configuration of specified stream. Note that some configuration item cannot be updated after the player is started.
      *
      * @param stream_index [IN] Index to specify the stream.
      * @param audio_config [IN] A pointer to new audio configuration.
      */
    media_error_t (*set_audio_config)(media_player_t* mp, kal_uint32 stream_index, media_player_audio_config_t* audio_config);

    /**
      * Starts the playback with specified parameters.
      *
      * @param params [IN] A pointer to playback parameters.
      */
    media_error_t (*start)(media_player_t* mp, media_player_start_params_t* params);

    /**
      * Retrieves buffer status of specified stream.
      *
      * @param stream_index [IN] Index to specify the stream.
      * @param buffer_status [OUT] A pointer to a struct that receives buffer status.
      */
    media_error_t (*get_buffer_status)(media_player_t* mp, kal_uint32 stream_index, media_stream_buffer_status_t* buffer_status);
    /**
      * Set parameter
      *
      * @param param [IN] parameter
      */
    media_error_t (*set_param)(media_player_t* mp, media_player_param_t *param);

    /**
      * Retrieves parameter
      *
      * @param param [OUT] A pointer to media_player_param_t
      */
    media_error_t (*get_param)(media_player_t* mp, media_player_param_t *param);

    /**
      * Stops the playback.
      *
      */
    media_error_t (*stop)(media_player_t* mp);

    /**
      * Pause visual update.
      *
      */
    media_error_t (*pause_visual_update)(media_player_t* mp);

    /**
      * Resume visual update.
      *
      */
    media_error_t (*resume_visual_update)(media_player_t* mp);
    
    /**
      * Stops visual update.
      *
      */
    media_error_t (*release_visual)(media_player_t* mp);

    /**
      * Jump to i frame.
      *
      */
    media_error_t (*jump_to_i_frame)(media_player_t* mp, media_time_t key_frame_time);
    
    /**
      * Delivers media data to the player.
      *
      * @param stream_index [IN] Specified the stream from which the media data comes.
      * @param data [IN] A pointer to media data.
      */
    media_error_t (*deliver)(media_player_t* mp, kal_uint32 stream_index, media_data_t* media_data);
   
    /**
      * Notify end of file
      */
    media_error_t (*notify_eos)(media_player_t* mp, kal_uint32 stream_index);

    /**
      * Closes the media player and releases the resources in use.
      */
    media_error_t (*close)(media_player_t* mp);

    /**
      * Destroys itself.
      */
    void (*destroy)(media_player_t* mp);
};

extern media_player_t* construct_media_player(media_player_client_t* client);
extern kal_bool media_player_init(void);

#endif /* defined(__VIDEO_ARCHI_V2__) */

#endif /* _MEDIA_PLAYER_H */
