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
 *   mpl_session.h
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

#ifndef _MPL_SESSION_H
#define _MPL_SESSION_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "mpl_common.h" // mpl common type definition
#include "mpl_player.h" // mpl player interface definition
#include "video_types_v2.h"
#include "source_provider_if.h"
#include "SubtitleFont_if.h"

/*****************************************************************************
 * Config
 *****************************************************************************/
#define MPL_DEBUG_INFO
#define VE_JAVA_SUPPORT

#define MPL_SESSION_MAX_CONTEXT 3
#define MPL_SESSION_INVALID_INDEX 0xFF
#define MPL_SESSION_INVALID_TIME 0xFFFFFFFFFFFFFFFF
#define MPL_SESSION_BUFFER_TIME_FOR_PLAY    (1000*6)
#define MPL_SESSION_MAX_TRACK_ARRARY 3

/*****************************************************************************
 * Define
 *****************************************************************************/
#define MPL_SET_FLAG(flag_) (self->bit_flag |= (flag_))
#define MPL_UNSET_FLAG(flag_) (self->bit_flag &= (~(flag_)))
#define MPL_IS_FLAG_SET(flag_) ((self->bit_flag & (flag_)) == (flag_))
#define MPL_SESSION_TIME_TO_COMPTIME(time) (time * 1000)
#define MPL_SESSION_COMPTIME_TO_TIME(time) (time / 1000)
#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define SELF(p, parent, member) (parent*)(((int)p) - OFFSET_OF(parent,member))
/*****************************************************************************
 * Enumeration
 *****************************************************************************/
typedef enum
{
    MPL_STATE_CLOSED,
    MPL_STATE_OPENING,
    MPL_STATE_READY,
    MPL_STATE_SEEKING,
    MPL_STATE_PLAYING,
    MPL_STATE_CLOSEING,
    MPL_STATE_PRE_SEEKING
} mpl_session_state_enum;

typedef enum{
    MPL_SESSION_EG_SOURCE_COMPLETE       = 0x00000001,
	MPL_SESSION_EG_SOURCE_ERROR          = 0x00000002,
    MPL_SESSION_EG_DECODER_COMPLETE      = 0x00000004,
	MPL_SESSION_EG_DECODER_ERROR         = 0x00000008,
	MPL_SESSION_EG_SCHEDULER_COMPLETE    = 0x00000010,
	MPL_SESSION_EG_SCHEDULER_ERROR       = 0x00000020,
	MPL_SESSION_EG_RENDER_COMPLETE       = 0x00000040,
	MPL_SESSION_EG_RENDER_ERROR          = 0x00000080,
	MPL_SESSION_EG_SOURCE_PORT_DONE      = 0x00000100,
	MPL_SESSION_EG_SOURCE_SEEK_TIME_DONE = 0x00000200,
	MPL_SESSION_EG_DECODER_FLSH_DONE     = 0x00000400,
	MPL_SESSION_EG_SOURCE_KEY_FRAME_DONE = 0x00000800,
	MPL_SESSION_EG_SOURCE_MEM_LACK       = 0x00001000,
	MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE = 0x00002000,
	MPL_SESSION_EG_SUBTITLEDECODER_ERROR    = 0x00004000,
    MPL_SESSION_EG_SOURCE_FREE_MEM          = 0x00008000,
    MPL_SESSION_EG_SOURCE_QUERY_FRM_DONE    = 0x00010000
} mpl_session_comp_eg_enum;

typedef enum
{
    MPL_SESSION_EVT_SOURCE_OPENED                  = 1,        /* 1 */
    MPL_SESSION_EVT_SOURCE_ERROR                   = (1 << 2), /* 4 */
    MPL_SESSION_EVT_DECODER_COMPLETE               = (1 << 3), /* 8 */
    MPL_SESSION_EVT_DECODER_RESOLUTION_NOT_SUPPORT = (1 << 4), /* 16 */
    MPL_SESSION_EVT_SCHEDULER_COMPLETE             = (1 << 6), /* 64 */
    MPL_SESSION_EVT_SCHEDULER_RECOVER_JUMP_TO_I    = (1 << 7), /* 128 */
    MPL_SESSION_EVT_SCHEDULER_RECOVER_STOP_AUDIO   = (1 << 8), /* 256 */
    MPL_SESSION_EVT_CLOCK_STOP                     = (1 << 9), /* 512 */
    MPL_SESSION_EVT_CLOCK_EXPECTED_BUF_NUM_RDY     = (1 << 10), /* 1024 */
    MPL_SESSION_EVT_RENDER_ERROR                   = (1 << 11), /* 2048 */
    MPL_SESSION_EVT_STREAMING_RESEND_EOS           = (1 << 12), /* 4096 */
    MPL_SESSION_EVT_SOURCE_PRE_SEEK_DOME           = (1 << 13), /* 8192 */
    MPL_SESSION_EVT_SUBTITLEDECODER_ERROR          = (1 << 14),
    MPL_SESSION_EVT_GET_AUDIO_TIME_2_SCHDULER      = (1 << 15),
    MPL_SESSION_EVT_DECODER_RETRY_FAILED           = (1 << 16),
    MPL_SESSION_EVT_SOURCE_AUDIO_UNDERFLOW         = (1 << 17),  
    MPL_SESSION_EVT_SOURCE_VIDEO_UNDERFLOW         = (1 << 18)    
} mpl_session_evt_enum;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * Structure
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    void *user_data;
    kal_uint8 event;
    kal_uint32 session_id;
}
mpl_session_aud_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
    kal_uint32 session_id;
    kal_uint8* pu1MyMPL;
}
mpl_session_vid_event_ind_struct;

/**
  * This struct contains video display settings.
  */
typedef struct
{
    void *image_buffer_p;           /**< assume the dimension of GDI layer is the same as LCD screen. */
    void *subtitle_image_buffer_p;
    kal_bool force_lcd_hw_trigger;
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    kal_uint32 subtitle_layer_element;
    kal_uint32 subtitle_blt_ctx;
    kal_uint32 subtitle_blt_dev;
    kal_uint16 display_width;       /**< width of video */
    kal_uint16 display_height;      /**< height of video */
    kal_uint16 subtitle_width;       /**< width of subtitle */
    kal_uint16 subtitle_height;      /**< height of subtitle */
    kal_int16 idp_rotate;           /**< IDP rotation */
    kal_uint8 display_device;       /**< must be MED_DISPLAY_TO_MAIN_LCD */
    kal_uint8 brightness;
    kal_uint8 contrast;
    kal_uint8 image_data_format;
    med_frame_enum frame_mode;
    mpl_renderer_3d_mode_enum e3DMode;
    kal_bool fgRendererVisible;
} mpl_session_video_config_t;

typedef kal_bool MPL_ERROR;
#define MPL_AUDIO_IDX       0
#define MPL_VIDEO_IDX       1
#define MPL_SUBTITLE_IDX    2
#define MPL_ERROR_RECORD_NUM 3

typedef struct
{
    mpl_player_t mpl;
    mpl_player_client_t* mpl_client;
    mpl_player_ctrl_dl_t dl_control;

    mpl_session_state_enum state;

    med_mode_enum media_mode;
    //med_track_enum media_track;
    mpl_scenario_enum media_scenario;
    med_type_enum media_type;  

    /* Source */
    VIDEO_COMPONENT_MI_TYPE_T *source_handle;
    VIDEO_CALLBACK_TYPE_T source_callback;
    void *source_cntx;
    kal_uint8 au1StreamIdx[SOURCE_PROVIDER_PORT_MAX];
    /* Audio */
    MHdl *mhdl_handle;
    SPIF_AUDIO_STREAM_INFO_T rAudioStream;
    SPIF_KEY_FRAME_TIME_T rKeyTime;
    Media_Format aud_format;
    media_time_t u8AudLastTime;
    kal_bool fgAudAddHeader;
    kal_uint32 u4AudDeltaTime;
    kal_uint8 play_audio;
    kal_uint8 audio_path;

    /* Video */
    VIDEO_COMPONENT_TYPE_T *decoder_handle;
    VIDEO_COMPONENT_TYPE_T *scheduler_handle;
    VIDEO_COMPONENT_TYPE_T *render_handle;

    VIDEO_CALLBACK_TYPE_T decoder_callback;
    VIDEO_CALLBACK_TYPE_T scheduler_callback;
    VIDEO_CALLBACK_TYPE_T clock_callback;
    VIDEO_CALLBACK_TYPE_T render_callback;

    VIDEO_EXTMEM_HANDLER_T *ext_handle;
    VIDEO_INTMEM_HANDLER_T *int_handle;

    SPIF_VIDEO_STREAM_INFO_T rVideoStream;

    kal_uint32 extmem_start_address;
    kal_uint32 intmem_start_address;

    kal_uint64 u8JumpTime;
    kal_uint64 u8Time4QueryKeyFrame;

#if defined(__VE_PARSE_TRANSFORMATION_INFO__)
    SPIF_TRANSFORMATION_INFO_T rTransformInfo;
#endif
    /* Subtitle*/
    SPIF_SUBTITLE_STREAM_INFO_T rSubtitleInfo;
    VIDEO_COMPONENT_TYPE_T *prSubtitleDecoderHdlr;
    VIDEO_CALLBACK_TYPE_T pfnSubtitleDecoderCallback;
    mpl_player_subtitle_track_info_t arSubtitleTrackInfo[MPL_SESSION_MAX_SUBTITLE_TRACK_NUM];
    kal_uint32 u4FontSize;
    subtitle_fontengine_struct rFontEngineApi;
    PFN_IS_LCC_SUPPORTED pfnIsLCCSupported;

    /* Misc. */
    kal_eventgrpid rEventID;
    mpl_player_open_t rOpenInfo;
    mpl_player_play_t rPlayInfo;
    mpl_player_seek_t rSeekInfo;
    media_stream_t aud_stream;
    media_stream_t vid_stream;
    media_time_t u8StartTime;
    media_time_t u8StopTime;
    media_time_t current_time;
    kal_uint64 u8VideoDuration;
    kal_uint64 u8AudioDuration;
    void *fs_handle;
    kal_bool fgBuffSupplier;    // indicate should provide bitstream buffer or not
    kal_bool fgSeekable;
    kal_bool fgAudError;
    kal_bool fgVidError;
    kal_bool fgSubtitleError;
    kal_bool fgAudFinished;
    kal_bool fgVidFinished;
    kal_bool fgBuffered;
    kal_bool fg3DAnaglyph;
    kal_bool fg3DSidebySide;

    kal_bool fgVideoRunning;
    kal_bool fgVideoBuffered;
    kal_bool fgAuidioBuffered;
    kal_bool fgCallbackedVideoTrackError;
    kal_bool fgCallbackedAudioTrackError;
    kal_bool fgRendererError;
    kal_bool fgLCDTriggered;
    kal_bool fgAudioUnderflow;
    kal_bool fgAudioReady2Play;
    kal_bool fgSourceRunning;
    kal_bool fgMPLCallbacked;
    kal_bool fgRendererPaused;
    kal_bool fgSupportTimeStretch;
    kal_bool fgForceSeeking;
    kal_bool fgClockEnabled;
    kal_bool fgDecoderRetryFailed;
    kal_bool fgFlushSubtitle;
    kal_bool fgCloseAudBTA2DPforOpen;

    kal_uint32 bit_flag;
    kal_uint32 play_speed;
    kal_uint8 elapse_ticks;
    kal_uint8 sleep_ticks;
    kal_uint8 brightness;
    kal_uint8 contrast;
    kal_bool fgDecoderStartBuffering;

    //Record the delayed error Source reports to MPL; reset when switching Source to IDLE
    MPL_ERROR afgSourceDelay[MPL_ERROR_RECORD_NUM];

    kal_timerid rTimerID;
    kal_mutexid rMutexID;
    mpl_player_track_info_t rVidTrackInfo;
    mpl_player_video_track_info_t rVidTrackInfoArray[MPL_SESSION_MAX_TRACK_ARRARY];
    VIDEO_DECODE_MODE_T eVidQuality;

    kal_uint32 u4JumpCount;
    /* Streaming */
    SP_PORT_TYPE_T eStreamingEOSPort;
    kal_uint32 u4AudFrameSize;
    kal_bool fgVidPathInitFail;

} mpl_session_struct;

typedef struct
{
    LOCAL_PARA_HDR
    mpl_session_struct* prSelf;
    mpl_session_evt_enum eEvent;
}MPLVP_SourceEventIND_T;

/*****************************************************************************
 * Declaration
 *****************************************************************************/
static media_error_t mpl_session_init_video_comp(mpl_session_struct *mpl);
static void mpl_session_audio_event_callback(MHdl *handle, Media_Event event);
static void mpl_session_video_event_callback(mpl_session_evt_enum event);
static media_time_t mpl_session_get_play_time(mpl_session_struct *self);
static media_error_t mpl_session_play_internal(mpl_session_struct *self, kal_bool close_bt_codec);
static void mpl_session_audio_event_callback_from_mpl(mpl_session_struct *self, Media_Event event);
static void mpl_session_set_render_bypass_in_running_state(mpl_session_struct *self, kal_bool bypass);
static media_error_t mpl_session_seek_internal(mpl_session_struct *self, mpl_player_seek_t* seek_struct);
static void _mpl_session_live_resend_eos_hdlr(void *param);
#endif /* _MPL_SESSION_H */

