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
 *   npplg_av_main.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures, enums, interfaces used in A/V Plug-in.
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
#ifndef NPPLG_AV_MAIN_H
#define NPPLG_AV_MAIN_H

#include "MMI_features.h"

#include "npplg_av_include.h"
#include "mdi_datatype.h"

#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "fs_type.h"
#include "gdi_datatype.h"
#include "stack_config.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "npplg_wrapper.h"


/************************************************************
 * Define
 ************************************************************/

#define NPPLG_AV_OPERA_NOT_PROVIDE_CORRECT_FILE_EXTENSION

/* A/V Plug-in supports playing embedded video object inside the browser only when this compile option is defined.
 * If this compile option is not defined, user can only launch media player to play the video.
 */
#if defined(__MP4_DEC_HW_SUPPORT__) || defined(__H264_DEC_HW_SUPPORT__)
#define NPPLG_AV_EMBEDDED_VDO_SUPPORT
#endif

/* When user presses ¡¨Fast forward¡¨ or ¡¨Rewind¡¨ playback control and the pen keeps holding on the screen,
 * A/V Plug-in will use timer to simulate repeat event.
 * The first timer interval used to simulate the repeat event is 0.6 second.
 */
#define NPPLG_AV_FIRST_REPEAT_TIMER_INTERVAL 600

/* The second timer interval used to simulate the repeat event is 0.3 second. */
#define NPPLG_AV_SECOND_REPEAT_TIMER_INTERVAL 300

/* Following timer interval used to simulate the repeat event is 0.1 second. */
#define NPPLG_AV_THIRD_REPEAT_TIMER_INTERVAL 100

/* This timer interval is used to update progress bar when plug-in is playing audio or video. */
#define NPPLG_AV_UPDATE_PROGRESS_BAR_INTERVAL 500

/*
 * When plug-in finishes playing audio or video, it will first fill the progress 
 * bar completely. Plug-in would set a timer and reset the play panel after timer expires.
 */
#define NPPLG_AV_RESET_PLAY_PANEL_INTERVAL 100

/* The folder name where plug-in stores temporary audio file and video file */
#define NPPLG_AV_TMP_FILE_PATH "@avplugin"

/* The maximum length of the folder path */
#define NPPLG_AV_MAX_FOLDER_LEN 16

/* The maximum number of instances A/V Plug-in can support.
 * The real number depends on the available memory at runtime.
 */
#define NPPLG_AV_MAX_INSTANCE_NUM 65535

/* The maximum value of uint32 */
#define NPPLG_AV_MAX_UINT32 0xFFFFFFFF

/* The maximum chunk buffer size A/V Plug-in will allocate at one time. */
// TODO: adjust the value in IT phase
#define NPPLG_AV_MAX_CHUNK_SIZE (16 * 1024) /* 16KB */

/*
 * The maximum number of playback control in audio play panel
 * 1. NPPLG_AV_CTRL_TYPE_PLAY
 * 2. NPPLG_AV_CTRL_TYPE_STOP
 * 3. NPPLG_AV_CTRL_TYPE_FAST_FORWARD
 * 4. NPPLG_AV_CTRL_TYPE_REWIND
 * 5. NPPLG_AV_CTRL_TYPE_MUTE
 */
#ifdef __COSMOS_MMI_PACKAGE__
#define NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM 4
#else
#define NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM 5
#endif /* __COSMOS_MMI_PACKAGE__ */

/*
 * The maximum number of playback control in video play panel
 * 1. NPPLG_AV_CTRL_TYPE_PLAY
 * 2. NPPLG_AV_CTRL_TYPE_STOP
 * 3. NPPLG_AV_CTRL_TYPE_FAST_FORWARD
 * 4. NPPLG_AV_CTRL_TYPE_REWIND
 * 5. NPPLG_AV_CTRL_TYPE_MUTE
 * 6. NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER
 */
#ifdef __COSMOS_MMI_PACKAGE__
#define NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM 5
#else
#define NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM 6
#endif /* __COSMOS_MMI_PACKAGE__ */

/* The maximum volume level */
#define NPPLG_AV_MAX_VOLUME_LEVEL 15


/* The timer interval to start processing image timer */
#define NPPLG_AV_UPDATE_PROCESSING_IMG_DELAY 300


/************************************************************
 * Typedef
 ************************************************************/

/* A/V Plug-in trace message */
#define NPPLG_AV_TRC_GROUP MMI_MEDIA_TRC_G6_NPPLG

/* Memory free macro */
#define NPPLG_AV_MEM_FREE(x, y) {npplg_av_main_free_memory(x, y); y = NULL;}

/* Change app state */
#define NPPLG_AV_APP_ENTER_STATE(_APP_ID_, _APP_STATE_, _NEW_STATE_)   \
    do {                                                                    \
        (_APP_STATE_) = (_NEW_STATE_);                                      \
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_ENTER_STATE_MSG, (_APP_ID_), (_NEW_STATE_), (__LINE__));    \
    } while(0);

/* Change object state */
#define NPPLG_AV_OBJ_ENTER_STATE(_INSTANCE_ID_, _OBJ_STATE_, _NEW_STATE_)   \
    do {                                                                    \
        (_OBJ_STATE_) = (_NEW_STATE_);                                      \
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_OBJ_ENTER_STATE_MSG, (_INSTANCE_ID_), (_NEW_STATE_), (__LINE__));    \
    } while(0);


/* The state of A/V Plug-in */
typedef enum
{
  NPPLG_AV_USER_STATE_TERMINATED = 0,
  NPPLG_AV_USER_STATE_INITIALIZED,
  NPPLG_AV_USER_STATE_INSTANCE_CREATED,
  NPPLG_AV_USER_STATE_INSTANCE_ACTIVE
} npplg_av_user_state_enum;

/* The object type of the plug-in instance */
typedef enum
{
  NPPLG_AV_OBJ_TYPE_AUDIO = 0,
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
  NPPLG_AV_OBJ_TYPE_VIDEO,
#endif
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
  NPPLG_AV_OBJ_TYPE_STREAMING,
#endif
  NPPLG_AV_OBJ_TYPE_UNKNOWN
} npplg_av_obj_type_enum;

/* The event type used in inline audio/video plug-in internally */
typedef enum
{
  NPPLG_AV_INT_EVT_UNKNOWN = 0,
  NPPLG_AV_INT_EVT_PLAY,
#ifdef __COSMOS_MMI_PACKAGE__
  NPPLG_AV_INT_EVT_AUTO_PLAY,
#endif
  NPPLG_AV_INT_EVT_PAUSE,
  NPPLG_AV_INT_EVT_STOP,
  NPPLG_AV_INT_EVT_FAST_FORWARD_START,
  NPPLG_AV_INT_EVT_FAST_FORWARD_STOP,
  NPPLG_AV_INT_EVT_REWIND_START,
  NPPLG_AV_INT_EVT_REWIND_STOP,
  NPPLG_AV_INT_EVT_LAUNCH_MEDIA_PLAYER
} npplg_av_int_evt_enum;

/* The timers used in inline audio/video plug-in internally */
typedef enum
{
  NPPLG_AV_TIMER_AUDIO_BUILD_CACHE_CHECK = 0,
  NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR,
  NPPLG_AV_TIMER_SEEK_REPEAT,
  NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG,
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
  NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL,
#endif
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_PDL__)
  NPPLG_AV_TIMER_PDL_BUF_CHECK,
#endif
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
  NPPLG_AV_TIMER_STREAM_BUF_CHECK,
#endif
  NPPLG_AV_TIMER_RESET_PLAY_PANEL,
  NPPLG_AV_TIMER_TOTAL
} npplg_av_timer_enum;

/* This enum describes that the playback control is enabled or disabled */
typedef enum
{
  NPPLG_AV_CTRL_DISP_ENABLE = 0,
  NPPLG_AV_CTRL_DISP_DISABLE
} npplg_av_ctrl_disp_enum;

/* This enum describes the type of the playback control */
typedef enum
{
  NPPLG_AV_CTRL_TYPE_NOT_SUPPORT = 0,
  NPPLG_AV_CTRL_TYPE_PLAY,
  NPPLG_AV_CTRL_TYPE_PAUSE,
  NPPLG_AV_CTRL_TYPE_STOP,
  NPPLG_AV_CTRL_TYPE_FAST_FORWARD,
  NPPLG_AV_CTRL_TYPE_REWIND,
  NPPLG_AV_CTRL_TYPE_MUTE,  /* Do not put MUTE control in COSMOS project because COSMOS project implement global volume setting feature */
  NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER,
  NPPLG_AV_CTRL_TYPE_PROGRESS_BAR,
  NPPLG_AV_CTRL_TYPE_TIME,
  NPPLG_AV_CTRL_TYPE_SEPARATE_LINE,
  NPPLG_AV_CTRL_TYPE_TOTAL
} npplg_av_ctrl_type_enum;

/* This enum describes the state of the play panel */
typedef enum
{
  NPPLG_AV_PLAY_PANEL_STATE_DISPLAY = 0,
  NPPLG_AV_PLAY_PANEL_STATE_HIDE,
  NPPLG_AV_PLAY_PANEL_STATE_HIDE_MOUSE_DOWN,
  NPPLG_AV_PLAY_PANEL_STATE_TOTAL
} npplg_av_play_panel_state_enum;

/* This enum describes the data retrieval state */
typedef enum
{
  NPPLG_AV_OBJ_DL_STATE_NULL = 0,
  NPPLG_AV_OBJ_DL_STATE_DOWNLOADING,
  NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK
} npplg_av_obj_dl_state_enum;

/* This enum describes the data retrieval state */
typedef enum
{
  NPPLG_AV_OBJ_PAINT_BUF_NULL = 0,
  NPPLG_AV_OBJ_PAINT_BUF_OK,
  NPPLG_AV_OBJ_PAINT_BUF_FAIL
} npplg_av_obj_paint_buf_enum;

typedef enum
{
  NPPLG_AV_OK = 0,
  NPPLG_AV_FAIL = -1
} npplg_av_result_enum;

typedef enum
{
  NPPLG_AV_RES_STATUS_NULL,
  NPPLG_AV_RES_STATUS_OCCUPYING,
  NPPLG_AV_RES_STATUS_OCCUPIED,
  NPPLG_AV_RES_STATUS_RELEASING
} npplg_av_res_status_enum;

typedef enum
{
  NPPLG_AV_ERROR_NULL = 0,
  NPPLG_AV_ERROR_FILE,
  NPPLG_AV_ERROR_NETWORK,
  NPPLG_AV_ERROR_TOTAL
} npplg_av_error_enum;


/* The structure of one playback control */
typedef struct
{
  kal_int32     x;          /* Coordinates of top left corner */
  kal_int32     y;  
  kal_int32     width;      /* The width of the control */
  kal_int32     height;     /* The height of the control */
  kal_uint8     display;    /* Indicate this control is enabled, disabled or should not be drawn */
  kal_uint8     type;       /* The type of the control */
  kal_bool      pressed;    /* Indicate the control is pressed or not */
} npplg_av_obj_control_struct;

/* The timer structure */
typedef struct npplg_av_timer_st
{
  struct npplg_av_timer_st *next;
  kal_int32     timer_id;
  kal_uint8     timer_type; /* npplg_av_timer_type_enum */
  kal_bool      valid;  
} npplg_av_timer_struct;

/* The structure of one plug-in instance */
typedef struct
{
  kal_uint32    instance_id;
  kal_uint32    dl_req_id;          /* The request id of download request */
  kal_int32     x;                  /* Coordinates of top left corner */
  kal_int32     y;
  kal_int32     width;              /* The width of the embedded object */
  kal_int32     height;             /* The height of the embedded object */
  kal_int32     processing_img_h;   /* The height of the processing image */
  kal_int32     seek_repeat_num;    /* Count the number of pen/key repeat events which are simulated by plug-in */
  kal_char      *url;               /* The URL of the embedded object */
  kal_char      *mime_type;         /* The MIME type of the embedded object */
  kal_wchar     *file_path;
  void          *obj_data;          /* npplg_av_audio_data_struct or npplg_av_video_data_struct */
  NPStream      *stream;
  NPP           brw_instance;
  npplg_av_timer_struct         *timer_list;
  npplg_av_obj_control_struct   **control_list;     /* Indicate the position and size of the playback controls */
  npplg_av_obj_control_struct   *empty_control;     /* Indicate the corresponding action if user clicks the empty area of the object */ 
  npplg_av_obj_control_struct   *pressed_control;   /* Indicate the pressed control */
  npplg_av_window_struct        plugin_window;      /* Plug-in's internal window */
  void          *window;
  NPWindow      *np_window;
  NPRect        clip_region;        /* Clipping rectangle coordinates */
  FS_HANDLE     file_handle;        /* File handle is used when plug-in receives raw data from application */
  kal_uint8     app_id;
  kal_uint8     obj_type;           /* npplg_av_obj_type_enum */
  kal_uint8     control_num;        /* The number of the controls in control_list array */
  kal_uint8     processing_img_indx;
  kal_uint8     play_panel_state;   /* The state of the play panel */
  kal_uint8     dl_state;           /* Indicate whether audio or video file has been downloaded to handset (npplg_av_obj_dl_state_enum) */
  kal_uint8     error;
  kal_int8      state;              /* The state of the plug-in instance */
  kal_int8      prev_state;         /* The state before entering paused state */
  kal_bool      seekable;           /* Indicate the object (video or audio) is seekable or not */
  kal_bool      focused;            /* Indicate the object has got/lost keyboard focus */
  kal_bool      suspend;            /* Indicate whether plug-in receives suspend event */
  kal_bool      mute;               /* Indicate the speaker is on or off */
  kal_bool      deleting;           /* Indicate plug-in is deleting the instance */
  kal_bool      processing;         /* Indicate whether plug-in should draw processing image */
  kal_bool      active;             /* Set as TRUE when plug-in receives ACTIVATE event, Set as FALSE when plug-in receives DEACTIVATE event */
  kal_bool      reset_seek_ctrl;    /* Indicate whether need to reset seek control when state is changed to idle state */
  gdi_color_format  color_format;   /* GDI color format */
} npplg_av_instance_struct;

/* Instance linked list */
typedef struct npplg_av_instance_list_st
{
  npplg_av_instance_struct *instance;
  struct npplg_av_instance_list_st *next;
} npplg_av_instance_list_struct;

/* The context of each plug-in user */
typedef struct
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
  gdi_handle    vdo_layer_handle;   /* The GDI handle of video layer */
  kal_uint8     *vdo_layer_buf;     /* Video layer buffer */
#endif
  npplg_av_instance_struct *active_instance;        /* Current active instance */
  npplg_av_instance_struct *interrupt_instance;     /* Next active instance */
  npplg_av_instance_list_struct *auto_play_queue;   /* The instance would be played after the page is loaded */
  npplg_av_instance_list_struct *instance_list;
  module_type   mod_id;             /* Application's module id */
  module_type   mimic_mod_id;       /* Application's module id for mimic task */
#ifdef __COSMOS_MMI_PACKAGE__
  gdi_color     transparent_color;
#endif /* __COSMOS_MMI_PACKAGE__ */
  kal_uint16    mem_app_id;
  kal_uint16    rotate;             /* Screen rotate value */
  kal_uint8     interrupt_event;    /* The event should be passed to next active instance */
  kal_uint8     state;              /* npplg_av_user_state_enum */
  kal_uint8     instance_num;       /* Number of created plug-in instance */
  kal_uint8     volume;             /* Global output volume: volume level is 16 and level 0 is mute */
  kal_bool      mute;               /* Indicate the speaker is on or off */
  kal_bool      is_suspend_by_mmi;  /* Indicate plug-in is already suspended by MMI */
  kal_bool      lcm_update;
} npplg_av_app_context_struct;

/* The context of A/V Plug-in */
typedef struct
{
  kal_int32     drive_letter;       /* The drive of plug-in folder */
  kal_int32     icon_width;         /* The width of one playback control */
  kal_int32     icon_height;        /* The height of one playback control */
  kal_int32     bar_height;         /* The height of the progress bar */
  kal_int32     separate_width;     /* The width of control's separate line */
  kal_uint32    session_id;
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
  kal_uint32    blt_layer_flag;
  kal_uint32    hw_layer_flag;
#endif
  npplg_av_app_context_struct app_cnxt[NPPLG_AV_APP_ID_TOTAL];
  kal_uint8     processing_img_num;
  kal_uint8     audio_callback_app_id;  /* The app id that audio callback should use to get instance */
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
  kal_uint8     video_callback_app_id;  /* The app id that video callback should use to get instance */
#ifdef __MMI_VIDEO_STREAM__
  kal_uint8     stream_callback_app_id; /* The app id that stream callback should use to get instance */
#endif
#endif
  kal_uint8     play_app_id;
  kal_uint8     res_status;
  kal_bool      is_speech_mode;     /* Whether target is in call */
  kal_bool      backlight_on;       /* Whether backlight is on */
} npplg_av_context_struct;


/************************************************************
 * Global Function
 ************************************************************/
extern NPError npplg_av_main_create_instance(NPMIMEType mime_type,
                                             NPP instance,
                                             kal_uint16 mode,
                                             kal_int16 argc,
                                             kal_char *argn[],
                                             kal_char *argv[],
                                             NPSavedData *saved,
                                             kal_uint8 app_id);
extern NPError npplg_av_main_set_window(NPP instance, NPWindow *window);
extern kal_int16 npplg_av_main_handle_event(NPP instance, void *event);
extern void npplg_av_main_start_download(npplg_av_instance_struct * plugin_data, kal_uint8 state);
extern void npplg_av_main_abort_download_req(npplg_av_instance_struct *plugin_data);
extern U8 npplg_av_main_launch_media_player_handler(void *msg);
extern U8 npplg_av_main_resume_background_play(void *msg);
extern U8 npplg_av_main_notify_mmi_ind_handler(void *msg);
extern U8 npplg_av_main_suspend_background_play_req_handler(void *msg);
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern U8 npplg_av_main_create_vdo_layer_req_handler(void *msg);
extern U8 npplg_av_main_free_vdo_layer_ind_handler(void *msg);
extern U8 npplg_av_main_update_vdo_layer_ind_handler(void *msg);
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */
extern void npplg_av_main_free_memory(kal_uint8 app_id, void *data);
extern void npplg_av_main_set_callback_app_id(kal_uint8 obj_type, kal_uint8 app_id);
extern kal_uint8 npplg_av_main_get_callback_app_id(kal_uint8 obj_type);
extern npplg_av_instance_struct *npplg_av_main_get_active_instance(kal_uint8 app_id);
extern void npplg_av_main_set_active_instance(npplg_av_instance_struct *active_instance,
                                              kal_bool clear_interrupt,
                                              kal_uint8 app_id);
extern kal_uint8 npplg_av_main_get_volume(kal_uint8 app_id);
extern void npplg_av_main_set_mute(kal_bool mute, kal_uint8 app_id);
extern void npplg_av_main_add_auto_play_instance(npplg_av_instance_struct *plugin_data);
extern kal_bool npplg_av_main_start_timer(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type, kal_uint32 interval);
extern void npplg_av_main_stop_timer(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type);
extern void npplg_av_main_stop_all_timer(npplg_av_instance_struct *plugin_data);
extern kal_bool npplg_av_main_check_timer_start(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type);
extern kal_bool npplg_av_main_reset_control_state(npplg_av_instance_struct *plugin_data, kal_bool issue_evt);
extern module_type npplg_av_main_get_app_mod_id(kal_uint8 app_id);
extern kal_bool npplg_av_main_decide_video_visual_update(kal_uint8 app_id, kal_bool lcm_update);
extern void npplg_av_main_switch_backlight(kal_bool backlight_on);

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern gdi_handle npplg_av_main_create_video_layer(kal_uint8 app_id,
                                                   npplg_av_rect_struct *rect_in,
                                                   npplg_av_rect_struct *rect_out);
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

extern kal_uint32 npplg_av_main_get_data_account(kal_uint8 app_id);
extern void npplg_av_main_get_visible_screen_area(npplg_av_instance_struct *plugin_data,
                                                  kal_int32 *x,
                                                  kal_int32 *y,
                                                  kal_int32 *w,
                                                  kal_int32 *h);
extern void npplg_av_main_display_popup(npplg_av_instance_struct *plugin_data, MMI_ID_TYPE message_id);
extern void npplg_av_main_convert_coordinate(npplg_av_instance_struct *plugin_data,
                                             kal_int32 old_x,
                                             kal_int32 old_y,
                                             kal_int32 *new_x,
                                             kal_int32 *new_y);
extern void npplg_av_main_get_gdi_layer(kal_uint8 app_id,
                                        gdi_handle *handle_1,
                                        gdi_handle *handle_2,
                                        gdi_handle *handle_3);
extern gdi_color npplg_av_main_get_transparent_color(kal_uint8 app_id);
extern void *npplg_av_main_alloc_noncache_memory(kal_uint8 app_id, kal_uint32 size);
extern void npplg_av_main_free_noncache_memory(kal_uint8 app_id, void *data);
extern void npplg_av_main_adjust_volume(kal_uint8 app_id, kal_bool volume_up);
extern void npplg_av_main_suspend_background_play(kal_uint8 app_id, kal_bool suspend_bgplay);
extern void npplg_av_main_interrupt_callback(mdi_result result, void *user_data);
extern void npplg_av_main_suspend_background_play_rsp_handler(void *info);
extern void npplg_av_main_audio_play_res_handler(void *info);
extern void npplg_av_main_mmi_resume_ind_handler(void *info);
extern void npplg_av_main_auto_play_audio_ind_handler(void *info);
extern void npplg_av_main_reset_ind_handler(void *info);
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern void npplg_av_main_create_vdo_layer_rsp_handler(void *info);
#endif
extern void npplg_av_main_remove_instance_from_list(npplg_av_instance_list_struct **list, npplg_av_instance_struct *plugin_data);


extern NPNetscapeFuncs g_npplg_av_netscape_funcs[NPPLG_AV_APP_ID_TOTAL]; /* Netscape Function table */
extern npplg_av_context_struct g_npplg_av_context;

#endif /* NPPLG_AV_MAIN_H */
