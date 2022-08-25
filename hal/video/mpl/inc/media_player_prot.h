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
 *   media_player_int.h
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_PLAYER_INT_H
#define _MEDIA_PLAYER_INT_H

#if defined(__VIDEO_ARCHI_V2__)

#include "media_common.h"
#include "mpl_common.h" // the common defition for MPL
#include "media_enum.h"
#include "media_player.h"
#include "video_types_v2.h"
#include "kal_general_types.h"
#include "l1audio.h"
#include "kal_public_defs.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MPLY_SET_FLAG(flag_) (self->bit_flag |= (flag_))
#define MPLY_UNSET_FLAG(flag_) (self->bit_flag &= (~(flag_)))
#define MPLY_IS_FLAG_SET(flag_) ((self->bit_flag & (flag_)) == (flag_))

#define MEDIA_PLAYER_HAS_TRACK(track_) ((self->track & track_) != 0)
#define MEDIA_PLAYER_TIME_TO_COMPTIME(time) (time * 1000)
#define MEDIA_PLAYER_COMPTIME_TO_TIME(time) (time / 1000)
#define MEDIA_PLAYER_INVALID_INDEX (0xFFFFFFFF)
#define MEDIA_PLAYER_VOL_LEVEL_NOT_USED (0xFF)
#define MEDIA_PLAYER_AMR_SAMPLING_RATE (8000)
#define MEDIA_PLAYER_AMRWB_SAMPLING_RATE (16000)
#define MEDIA_PLAYER_ADTS_HEADER_LEN (7)
#define MPLY_LIVE_STREAM_IGNORE_UNDERFLOW (2000)

#define MPLY_AUD_RING_BUFFER_SIZE VID_RING_BUFFER_LEN
#define MPLY_AMR_RING_BUFFER_SIZE (4*1024)
#define MPLY_AUD_BUFFER_START_TO_PLAY (4*1024)

/* aud ring buffer size >= amr ring buffer size */
#if (MPLY_AMR_RING_BUFFER_SIZE > MPLY_AUD_RING_BUFFER_SIZE)
#undef MPLY_AMR_RING_BUFFER_SIZE
#define MPLY_AMR_RING_BUFFER_SIZE MPLY_AUD_RING_BUFFER_SIZE
#endif

/* amr ring buffer size >= start play ring buffer size */
#if (MPLY_AUD_BUFFER_START_TO_PLAY > MPLY_AMR_RING_BUFFER_SIZE)
#undef MPLY_AUD_BUFFER_START_TO_PLAY
#define MPLY_AUD_BUFFER_START_TO_PLAY (MPLY_AMR_RING_BUFFER_SIZE)
#endif

/***************************************************************************** 
 * Enumeration
 *****************************************************************************/
typedef enum{
    MEDIA_PLAYER_EG_DECODER_COMPLETE    = 0x00000001,
	MEDIA_PLAYER_EG_DECODER_ERROR       = 0x00000002,
	MEDIA_PLAYER_EG_SCHEDULER_COMPLETE  = 0x00000004,
	MEDIA_PLAYER_EG_SCHEDULER_ERROR     = 0x00000008,
	MEDIA_PLAYER_EG_CLOCK_COMPLETE      = 0x00000010,
	MEDIA_PLAYER_EG_CLOCK_ERROR         = 0x00000020,
	MEDIA_PLAYER_EG_RENDER_COMPLETE     = 0x00000040,
	MEDIA_PLAYER_EG_RENDER_ERROR        = 0x00000080,
	MEDIA_PLAYER_EG_DECODER_FLUSH_FRAME_DONE = 0x00000100
}media_player_comp_eg_enum;

typedef enum{   
    MEDIA_PLAYER_RENDER_GET_FRAME,
	MEDIA_PLAYER_RENDER_PLAY_INVISIBLE,
    MEDIA_PLAYER_RENDER_PLAY_VISIBLE
}media_player_render_param_type_enum;

typedef enum{
    MEDIA_PLAYER_PREV_FRAME,
	MEDIA_PLAYER_CURR_FRAME	
}media_player_frame_enum;

typedef enum
{
    MPLY_FLAG_SUPPORT_TIME_STRETCH      = 1,        /* 1 */
    MPLY_FLAG_SEEK_TIME_REACHED         = (1 << 1), /* 2 */
    MPLY_FLAG_LIVE_STREAM               = (1 << 2), /* 4 */
    MPLY_FLAG_IS_DUMMY_AUDIO            = (1 << 3), /* 8 */
    MPLY_FLAG_AUD_BUFF_FULL             = (1 << 4), /* 16 */
    MPLY_FLAG_VID_BUFF_FULL             = (1 << 5), /* 32 */
    MPLY_FLAG_SKIP_NON_I_FRAME          = (1 << 6), /* 64 */
    MPLY_FLAG_WAIT_FLUSH_FRAME          = (1 << 7), /* 128 */
    MPLY_FLAG_VID_BUFF_REQ_HANDING      = (1 << 8), /* 256 */
    MPLY_FLAG_VID_VISUAL_UPDATE_PAUSED  = (1 << 9),  /* 512 */
    MPLY_FLAG_RENDER_ERROR_HANDLING     = (1 << 10), /* 1024 */
    MPLY_FLAG_DECODE_UNSUPPORT_RES      = (1 << 11), /* 2048 */
    MPLY_FLAG_VID_USE_CUR_FRAME         = (1 << 12)  /* 4096 */
} media_player_bit_flag_enum;

/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct
{
    media_player_t itf;
    media_player_client_t* client;    
    
    media_player_state_enum state;
    media_player_video_config_t video_config;
    media_player_audio_config_t audio_config; 

    /* Component */  
    VIDEO_EXTMEM_HANDLER_T *ext_handle;
    VIDEO_INTMEM_HANDLER_T *int_handle;
    
    VIDEO_COMPONENT_TYPE_T *input_handle;
    VIDEO_COMPONENT_TYPE_T *decoder_handle;
    VIDEO_COMPONENT_TYPE_T *scheduler_handle;
    VIDEO_COMPONENT_TYPE_T *render_handle; 

    VIDEO_CALLBACK_TYPE_T decoder_callback;
    VIDEO_CALLBACK_TYPE_T scheduler_callback;
    VIDEO_CALLBACK_TYPE_T clock_callback;
    VIDEO_CALLBACK_TYPE_T render_callback;
    
    kal_uint64 audio_start_time;
    kal_uint64 stop_time;
    kal_uint64 current_time;
    kal_uint64 audio_last_time;
    kal_int64 max_empty_time;
    kal_uint64 key_frame_time;
    media_stream_t aud_stream;
    media_stream_t vid_stream;
    Media_Format aud_format;
    kal_uint32 vid_stream_index;
    kal_uint32 aud_stream_index;
    kal_uint32 total_duration;    
    kal_uint32 play_speed; 
    kal_uint32 comp_event;
    kal_uint32 aud_time_diff;
    kal_uint32 bit_flag;
    kal_uint32 predict_time;
    kal_bool aud_format_supported;
    
    kal_uint8 get_frame;   
    kal_uint8 vol_level;   
    kal_uint8 elapse_ticks;
    kal_uint8 sleep_ticks;
    mpl_scenario_enum media_scenario;
    med_mode_enum media_mode;
    kal_bool fgSeekable;
    
    media_player_aud_stream_status_enum aud_stream_status;
    media_player_vid_stream_status_enum vid_stream_status;

    /* Audio */
    kal_uint8 adts_header[MEDIA_PLAYER_ADTS_HEADER_LEN];
    kal_uint8 *audio_buf;   
    MHdl *mhdl_handle;
    
    kal_uint32 aud_session_id;
    kal_uint32 vid_session_id;
    kal_uint32 vid_life_cycle_id;
    
    /* Buffer */
    kal_uint32 aud_queue_num;
    kal_uint32 vid_queue_num;
    kal_uint32 silence_written_size;
    kal_uint32 aud_written_size;
    kal_uint32 adts_written_size;
    kal_uint32 aud_frame_size; /* The frame size in queue */
    kal_uint32 aud_frame_num; /* The frame num in audio ring buffer */
    kal_uint32 aud_ready_frame_num;
    media_data_t* audio_queue;
    media_data_t* video_queue;
    media_data_t* video_written_queue;

    kal_uint32 intmem_start_address;    /* internal memory start address for hardware engine buffer */
    kal_uint32 extmem_start_address;    /* external memroy start address for hardware engine buffer */
} media_player_cntx_struct;

extern media_player_cntx_struct *media_player_cntx_p;
extern kal_eventgrpid media_player_comp_eg;
extern kal_mutexid media_player_mutex;

/***************************************************************************** 
 * Declaration
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T media_player_decoder_callback(VIDEO_EVENT_TYPE_T event, kal_uint32 data1, kal_uint32 data2, void* data_ptr); 
static VIDEO_ERROR_TYPE_T media_player_scheduler_callback(VIDEO_EVENT_TYPE_T event, kal_uint32 data1, kal_uint32 data2, void* data_ptr); 
static VIDEO_ERROR_TYPE_T media_player_clock_callback(VIDEO_EVENT_TYPE_T event, kal_uint32 data1, kal_uint32 data2, void* data_ptr); 
static VIDEO_ERROR_TYPE_T media_player_render_callback(VIDEO_EVENT_TYPE_T event, kal_uint32 data1, kal_uint32 data2, void* data_ptr); 
static void media_player_add_to_queue(media_data_t **queue, media_data_t* data);
static void media_player_audio_dummy_callback(MHdl *handle, Media_Event event);
static void media_player_audio_event_callback(MHdl *handle, Media_Event event);
static void media_player_video_event_callback(media_player_comp_evt_enum event);
static void media_player_video_buffer_req_callback(void);
static media_error_t media_player_consume_audio_queue(media_player_t* mp);
static media_error_t media_player_consume_video_queue(media_player_t* mp);
static media_error_t media_player_deliver_vid_eof_buffer(media_player_t* mp);
static media_error_t media_player_play_dummy_audio(media_player_t* mp);
static media_error_t media_player_stop(media_player_t* mp);
static media_error_t media_player_write_to_audio_buffer(
                        media_player_t* mp, 
                        kal_uint8 *data,
                        kal_uint32 data_len,
                        kal_uint32 *written_size);
static void media_player_fill_decoder_buffer(
                media_player_t* mp, 
                VIDEO_BUFFERHEADER_TYPE_T *buffer_header, 
                media_data_t* media_data,
                kal_bool init_param);
static VIDEO_ERROR_TYPE_T media_player_decoder_fill_this_buffer(
                                VIDEO_BUFFERHEADER_TYPE_T *buf_header);
static media_error_t media_player_notify_eos(media_player_t* mp, kal_uint32 stream_index);
static media_error_t media_player_play_audio(media_player_t* mp);
static VIDEO_DECODER_CODEC_T media_player_codec_type_to_decoder_type(media_codec_type_t codec_type);

/* Common function */
extern media_error_t media_player_do_recover(media_player_t* mp, media_time_t key_frame_time);
extern void media_player_reset_queue(media_player_t* mp, media_player_queue_type_enum queue_type);
extern void media_player_remove_from_queue(media_data_t **queue, media_data_t* node);
extern void media_player_reset_recover(void *arg);

#endif /* defined(__VIDEO_ARCHI_V2__) */

#endif /* _MEDIA_PLAYER_INT_H */

