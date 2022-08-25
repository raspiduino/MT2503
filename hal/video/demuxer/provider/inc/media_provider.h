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
 *   media_provider.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_PROVIDER_H
#define _MEDIA_PROVIDER_H

#if defined(__VIDEO_ARCHI_V2__)

#include "media_common.h"
#include "mpl_common.h" // the common defition for MPL

typedef enum
{
    MEDIA_PROVIDER_STATE_CLOSED = 0,
    MEDIA_PROVIDER_STATE_OPENED,
    MEDIA_PROVIDER_STATE_STARTED,
    MEDIA_PROVIDER_STATE_STOPPED,

    MEDIA_PROVIDER_STATE_OPENING,
    MEDIA_PROVIDER_STATE_STARTING,
    MEDIA_PROVIDER_STATE_PDL_META_BUFFERING,
    MEDIA_PROVIDER_STATE_CLOSING,
    MEDIA_PROVIDER_STATE_HOLDING

} media_provider_state_t;

typedef enum
{
    MEDIA_PROVIDER_EVENT_OPENED,            /**< the provider is opened */
    MEDIA_PROVIDER_EVENT_STARTED,           /**< the provider is started */
    MEDIA_PROVIDER_EVENT_PAUSED,            /**< the provider is paused */
    MEDIA_PROVIDER_EVENT_STOPPED,           /**< the provider is stopped */
    MEDIA_PROVIDER_EVENT_SEEKED,            /**< seeked to a new position */
    MEDIA_PROVIDER_EVENT_CLOSED,             /**< the provided is closed */
    MEDIA_PROVIDER_EVENT_END_OF_MEDIA,      /**< the media has reached its end */
    MEDIA_PROVIDER_EVENT_END_OF_STREAM,     /**< the stream has reached its end */
    MEDIA_PROVIDER_EVENT_STOP_TIME_REACHED, /**< reached the specified end time */
    MEDIA_PROVIDER_EVENT_ONE_FRAME_SENT,    /**< sent first frame in one frame mode */
    MEDIA_PROVIDER_EVENT_AUDIO_TIME_DIFF_ACQUIRED, /**< notify audio ts diff */
    MEDIA_PROVIDER_EVENT_BUFFER_OVERFLOW,       /**< notify provider have been buffer overflow */
    MEDIA_PROVIDER_EVENT_MEMORY_INSUFFICIENT    = -1,    /**< sent memory insufficient when alloc frame buffer failed. */
    MEDIA_PROVIDER_EVENT_CORRUPTED_DATA         = -2,    /**< sent corrupted data when get packet failed. */
    MEDIA_PROVIDER_EVENT_OPEN_FAIL              = -3,   /**< the provider async open fail.. */
    MEDIA_PROVIDER_EVENT_START_FAIL             = -4,   /**< the provider async start fail.. */
    MEDIA_PROVIDER_EVENT_DISCONNECTED           = -5    /**< streaming disconnected */

} media_provider_event_t;

typedef enum
{
    MEDIA_PROVIDER_IS_LIVE         = 0x01,
    MEDIA_PROVIDER_CAN_SEEK        = 0x02,
    MEDIA_PROVIDER_CAN_PAUSE       = 0x04,
    MEDIA_PROVIDER_IS_STREAMING    = 0x08

} media_provider_characteristics_t;

typedef enum
{
    MEDIA_SEARCH_FORWARD = 0,           /**< the search keyframe direction is forwarding */
    MEDIA_SEARCH_BACKWARD,              /**< the search keyframe direction is backwarding */
    MEDIA_SEARCH_DIR_NUM                /**< the total search keyframe directions */

} media_search_dir_t;

typedef struct media_provider_client_t media_provider_client_t;
struct media_provider_client_t
{
    /* Memory allcator and free api. */
    void*(*mem_alloc_func) (media_provider_client_t *client, kal_int32 size, med_mem_type_enum type, char* file_p, long line_p);

    void (*mem_free_func)  (media_provider_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p);

    /**
      * Notifies a new stream is found. This notification should be sent before MEDIA_PROVIDER_EVENT_OPENED event.
      *
      * @param stream [IN] A pointer to newly found media stream.
      */
    void (*on_stream_found)(media_provider_client_t* client, media_stream_t* stream);

    /**
      * Notifies media data of some stream has arrived.
      *
      * @param stream_index [IN] Index of stream from which the data comes.
      * @param data [IN] A pointer to the media data
      */
    void (*on_media_data)(media_provider_client_t* client, kal_uint32 stream_index, media_data_t* data);

    /**
      * Notifies provider event.
      *
      * @param event [IN] Event code. @see media_provider_event_t.
      * @param event_param [IN] Event parameter.
      */
    media_error_t (*on_event)(media_provider_client_t* client, media_provider_event_t event, kal_uint32 event_param);
};

typedef enum
{
    METADATA_ITEM_NONE,
    METADATA_ITEM_AUTHOR,
    METADATA_ITEM_TITLE,
    METADATA_ITEM_ARTIST,
    METADATA_ITEM_ALBUM,
    METADATA_ITEM_COPYRIGHT,
    METADATA_ITEM_DATE,

    /* iTune specific */
    METADATA_ITEM_ILST_ALB,
    METADATA_ITEM_ILST_ART,
    METADATA_ITEM_ILST_aART,
    METADATA_ITEM_ILST_CMT,
    METADATA_ITEM_ILST_DAY,
    METADATA_ITEM_ILST_NAM,
    METADATA_ITEM_ILST_GNRE,
    METADATA_ITEM_ILST_GER,
    METADATA_ITEM_ILST_TRKN,
    METADATA_ITEM_ILST_TOO,
    METADATA_ITEM_ILST_CPRT,
    METADATA_ITEM_ILST_GRP,
    METADATA_ITEM_ILST_DESC,
    METADATA_ITEM_ILST_LYR

} media_provider_metadata_item_t;

#define INVALID_METADATA_INT ((kal_uint32)-1)

typedef struct media_provider_buf_status_t
{
    media_time_t avail_dur_a; /* current available duration to audio */
    media_time_t avail_dur_v; /* current available duration to video */
    kal_uint32 rest_bitstream_size_a; /* rest audio bitstream size from start_time */
    kal_uint32 rest_bitstream_size_v; /* rest video bitstream size from start_time */
    kal_uint32 buf_percentage_a; /* usage of audio buffer in provider */
    kal_uint32 buf_percentage_v; /* usage of video buffer in provider */
} media_provider_buf_status_t;

typedef struct media_provider_download_t media_provider_download_t;
struct media_provider_download_t
{
    /**
      * Get current buffer status from a specific time.
      *
      * @param start_time [IN] Specifies the start time in ms.
      * @param pt_buf_status [OUT] A pointer to a structure to indicate current buffer status from a specific time.
      */
    media_error_t (*get_buf_status)(media_provider_download_t* dl, media_time_t start_time, media_provider_buf_status_t* pt_buf_status);
};

typedef struct media_provider_metadata_t media_provider_metadata_t;
struct media_provider_metadata_t
{
    /**
      * Retrieves string value of specified item.
      *
      * @param item [IN] Specifies the item to retrieve.
      * @return NULL if specified item cannot be found. valid string pointer otherwise.
      */
    const kal_wchar* (*get_string)(media_provider_metadata_t* md, media_provider_metadata_item_t item);

    /**
      * Retrieves integer value of specified item.
      *
      * @param item [IN] Specifies the item to retrieve.
      * @return INVALID_METADATA_INT if specified item cannot be found. valid integer value otherwise.
      */
    kal_uint32 (*get_int)(media_provider_metadata_t* md, media_provider_metadata_item_t item);
};

typedef struct media_provider_streaming_t media_provider_streaming_t;
struct media_provider_streaming_t
{
    /**
      * Retrieves sdp from provider
      *
      * @return med_stream_sdp_info_t*
      * @return NULL if specified item cannot be found. valid pointer otherwise.
      */
    const void* (*get_sdp)(media_provider_streaming_t* md);
};

typedef struct media_provider_frame_positioning_t media_provider_frame_positioning_t;
struct media_provider_frame_positioning_t
{
    /**
      * Converts the given frame number to the corresponding media time. The method only performs the calculations.
      * It does not position the media to the given frame.
      *
      * @param frame_number [IN] The input frame number for the conversion.
      * @param time [OUT] A pointer to a variable that receives the converted media time in microseconds for the given frame. If the conversion fails, -1 is returned.
      */
    media_error_t (*map_frame_to_time)(media_provider_frame_positioning_t* fp, kal_uint32 stream_idx, kal_uint32 frame_number, media_time_t* time);

    /**
      * Converts the given media time to the corresponding frame number starting from 0. The method only performs the calculations.
      * It does not position the media to the given media time.
      *
      * The frame returned is the nearest frame that has a media time less than or equal to the given media time.
      *
      * @param time [IN] The input media time for the conversion in microseconds.
      * @param frame_number [OUT] A pointer to a variable that receives the converted frame number for the given media time. If the conversion fails, -1 is returned.
      */
    media_error_t (*map_time_to_frame)(media_provider_frame_positioning_t* fp, kal_uint32 stream_idx, media_time_t time, kal_uint32* frame_number);

    /**
      * Gets media time of the key frame before the specified time.
      *
      * @param time [IN] The input media time to start key frame searching from.
      * @param key_frame_time [OUT] A pointer to a variable that receives the media time of key frame.
      */
    media_error_t (*get_key_frame_time)(media_provider_frame_positioning_t* fp, kal_uint32 stream_idx, media_search_dir_t dir, media_time_t time, media_time_t* key_frame_time);

    /**
      * Seek to key frame with the specified time.
      *
      * @param time [IN] Seek to the time.
      */
    media_error_t (*seek)(media_provider_frame_positioning_t* fp, kal_uint32 stream_idx, media_time_t time);
};

typedef enum
{
    MEDIA_PROVIDER_CONTROL_METADATA,            /**< For media_provider_metadata_t. */
    MEDIA_PROVIDER_CONTROL_FRAME_POSITIONING,   /**< For media_provider_frame_positioning_t. */
    MEDIA_PROVIDER_CONTROL_DOWNLOAD,
    MEDIA_PROVIDER_CONTROL_STREAMING            /**< For media_provider_streaming_t. */
} media_provider_control_type_t;

typedef enum
{
    MEDIA_PROVIDER_MODE_NORMAL,         /**< Normal playback. */
    MEDIA_PROVIDER_MODE_AUDIO,          /**< Audio only. */
    MEDIA_PROVIDER_MODE_VIDEO,          /**< Video only. */
    MEDIA_PROVIDER_MODE_META            /**< Metadata parsing. */

} media_provider_mode_t;

typedef enum
{
    MEDIA_PROVIDER_OPEN_NONE           = 0,
    MEDIA_PROVIDER_OPEN_FILE           = 1, /**< File mode. */
    MEDIA_PROVIDER_OPEN_FILE_WITH_FSAL = 2, /**< File mode, client provide FSAL handle. */
    MEDIA_PROVIDER_OPEN_URL            = 3, /**< Streaming mode. */
    MEDIA_PROVIDER_OPEN_BUFFER         = 4, /**< Buffer mode. */
    MEDIA_PROVIDER_OPEN_CONNECT        = 5, /**< Streaming with connect param mode. */
    MEDIA_PROVIDER_OPEN_PDL            = 6  /**< Progressive Download mode. */

} media_provider_open_source_t;

typedef enum
{
    MP_START_ONE_FRAME_ONLY = 0x01,
    MP_START_VIDEO_RESUME   = 0x02

} media_provider_start_flags_t;

typedef struct media_provider_t media_provider_t;
struct media_provider_t
{
    /**
      * Retrieves pointers to the supported control interface.
      *
      * @param control_type [IN] The identifier of the control being requested.
      * @param control [OUT] The address of a pointer variable that receives the control pointer requested in the control_type parameter.
      */
    media_error_t (*get_control)(media_provider_t* mp, media_provider_control_type_t control_type, void** control);

    /**
      * Opens specified media by its path.
      *
      * @param path [IN] Media path to open.
      * @param client [IN] A pointer to the client interface.
      */
    media_error_t (*open)(media_provider_t* mp, media_provider_open_source_t source,
                            const kal_uint8* data, const kal_uint32 len, media_provider_client_t* client);

    /**
      * Retrieves the characteristics of the media provider.
      *
      * @param characteristics [OUT] A pointer to a variable that receives a bitwise OR of zero or more flags from media_provider_characteristics enum.
      */
    media_error_t (*get_characteristics)(media_provider_t* mp, kal_uint32* characteristics);

    /**
      * Starts or seeks the media by specifying where to start playback.
      *
      * @param start_time [IN,OPTIONAL] The start time of playback, in milliseconds. If NULL is specified, the provider will resume from previously stopped position.
      * @param stop_time [IN,OPTIONAL] The stop time of playback, in milliseconds. If NULL is specified, the provider will run until the end of media is reached.
      * @param flags [IN] The flags that control how the provider is started. @see media_provider_start_flags_t.
      */
    media_error_t (*start)(media_provider_t* mp, media_time_t* start_time, media_time_t* stop_time, kal_uint32 flags);

    /**
      * Dispatchs media data until running out of demux buffer.
      */
    media_error_t (*dispatch)(media_provider_t* mp);

    /**
      * Selects a stream in the presentation.
      *
      * @param type [IN] The stream index to select, indexed from zero.
      */
    media_error_t (*select_stream)(media_provider_t* mp, kal_uint32 stream_index);

    /**
      * Deselects a stream in the presentation.
      *
      * @param type [IN] The stream index to deselect, indexed from zero.
      */
    media_error_t (*deselect_stream)(media_provider_t* mp, kal_uint32 stream_index);

    /**
      * Specifies where to stop playback.
      *
      * @param stop_time [IN,OPTIONAL] Stop time in milliseconds. If NULL is specified, end of media is assumed.
      */
    media_error_t (*set_stop_time)(media_provider_t* mp, media_time_t* stop_time);

    /**
      * Retrieves current time of specified stream.
      *
      * @param stream_index [IN] Index of stream of which the position is queried.
      * @param stream_time [OUT,OPTIONAL] A pointer to a variable that receives current position relative to the beginning of media in milliseconds.
      */
    media_error_t (*get_stream_time)(media_provider_t* mp, kal_uint32 stream_index, media_time_t* stream_time);

    /**
      * Stops all active streams. Note that it may be started again later to resume from the current position.
      */
    media_error_t (*stop)(media_provider_t* mp);

    /**
      * Closes the media provider and releases the resources in use.
      */
    media_error_t (*close)(media_provider_t* mp);

    /**
      * Destroys itself.
      */
    void (*destroy)(media_provider_t* mp);
};

extern media_provider_t* construct_rm_media_provider(media_provider_client_t* client, media_provider_mode_t mode);
extern media_provider_t* construct_mp4_media_provider(media_provider_client_t* client, media_provider_mode_t mode);
extern media_provider_t* construct_avi_media_provider(media_provider_client_t* client, media_provider_mode_t mode);
extern media_provider_t* construct_flv_media_provider(media_provider_client_t* client, media_provider_mode_t mode);
extern kal_bool ValidateFLVFormat(void* FileName);
extern kal_bool ValidateF4VFormat(void* FileName);

#if 0 // remove for HAL 
/* under construction !*/
#endif

#define media_provider_alloc_ext_mem(client, size) (((media_provider_client_t*)client)->mem_alloc_func(client, size, MED_MEM_NONCACHE, __FILE__, __LINE__))
#define media_provider_alloc_cacheable_ext_mem(client, size) (((media_provider_client_t*)client)->mem_alloc_func(client, size, MED_MEM_CACHE, __FILE__, __LINE__))
#define media_provider_free_ext_mem(client, p) (((media_provider_client_t*)client)->mem_free_func(client, p, MED_MEM_NONCACHE, __FILE__, __LINE__))

#endif //#if defined(__VIDEO_ARCHI_V2__)

#endif /* _MEDIA_PROVIDER_H */
