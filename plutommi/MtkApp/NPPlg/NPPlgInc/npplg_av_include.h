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
 *   npplg_av_include.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures, enums, interfaces exported by A/V Plug-in.
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
#ifndef NPPLG_AV_INCLUDE_H
#define NPPLG_AV_INCLUDE_H

#include "npplg_wrapper.h"
#include "gdi_include.h"
#include "gdi_datatype.h"
#include "npn_mtk.h"
#include "kal_general_types.h"


/************************************************************
 * Define
 ************************************************************/

/* Blt layer config */
#define NPPLG_AV_BLT_LAYER_FLAG (GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3)

/* Video layer config */
#define NPPLG_AV_VDO_PLAY_LAYER_FLAG GDI_LAYER_ENABLE_LAYER_0


/************************************************************
 * Typedef
 ************************************************************/

/* Start timer */
typedef kal_int32 (*npplg_av_start_timer)(void *plugin_window, kal_uint32 timeout_ms);

/* Stop timer */
typedef kal_uint32 (*npplg_av_stop_timer) (void *plugin_window, kal_int32 timer_id);

/* Return the visible area in screen coordinate */
typedef void (*npplg_av_get_visible_screen_area)(void *plugin_window, int *x, int *y, int *w, int *h);

/* Translate the x,y from logical coordinate in core to screen coordinate */
typedef void (*npplg_av_trans_to_screen_coord)(void *plugin_window, int *x, int *y);

/*
 * Display error popup
 * title [IN]: title string
 * message [IN]: error message
 */
typedef void (*npplg_av_display_popup) (void *window, char *title, char *message);


/*
 * The user of A/V Plug-in
 * If Google Gadget use A/V Plug-in, should add one app id for it
 */
#if defined(OPERA_V10_BROWSER) && defined(__GADGET_SUPPORT__)

typedef enum
{
  NPPLG_AV_APP_ID_OPERA_BROWSER = 0,    /* Represent Opera Browser */
  NPPLG_AV_APP_ID_GOOGLE_GADGET,        /* Represent Google Gadget */
  NPPLG_AV_APP_ID_TOTAL
} npplg_av_app_id_enum;

#elif defined(OPERA_V10_BROWSER) && !defined(__GADGET_SUPPORT__)

typedef enum
{
  NPPLG_AV_APP_ID_OPERA_BROWSER = 0,    /* Represent Opera Browser */
  NPPLG_AV_APP_ID_TOTAL
} npplg_av_app_id_enum;

#elif !defined(OPERA_V10_BROWSER) && defined(__GADGET_SUPPORT__)

typedef enum
{
  NPPLG_AV_APP_ID_GOOGLE_GADGET = 0,        /* Represent Google Gadget */
  NPPLG_AV_APP_ID_TOTAL
} npplg_av_app_id_enum;

#else

typedef enum
{
  NPPLG_AV_APP_ID_TOTAL = 1
} npplg_av_app_id_enum;

#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */

/* Event type */
typedef enum
{
  NPPLG_AV_EVT_TYPE_PAINT = 0,
  NPPLG_AV_EVT_TYPE_TIMER,
  NPPLG_AV_EVT_TYPE_KEY,
  NPPLG_AV_EVT_TYPE_MOUSE,
  NPPLG_AV_EVT_TYPE_ACTIVATE,       /* Sent to activate or deactivate a plug-in instance */
  NPPLG_AV_EVT_TYPE_FOCUS,          /* Sent to inform a plug-in instance that it has got/lost focus */
  NPPLG_AV_EVT_TYPE_SCREEN_SCROLLED /* Sent to inform a plug-in instance that the page is scrolled so plug-in should update video layer */
} npplg_av_evt_type_enum;

/* The reason why the key event was triggered */
typedef enum
{
  NPPLG_AV_EVT_KEY_DOWN = 0,
  NPPLG_AV_EVT_KEY_UP
} npplg_av_evt_key_enum;

/* The reason why the mouse event was triggered */
typedef enum
{
  NPPLG_AV_EVT_MOUSE_MOVE = 0,
  NPPLG_AV_EVT_MOUSE_DOWN,
  NPPLG_AV_EVT_MOUSE_UP
} npplg_av_evt_mouse_enum;


/* Rectangle */
typedef struct
{
  kal_int32 x;
  kal_int32 y;
  kal_int32 w;
  kal_int32 h;
} npplg_av_rect_struct;

/* The structure of paint event */
typedef struct
{
  npplg_av_rect_struct  paint_area;     /* The location and size of the area to repaint in plug-in window coordinates */
  void                  *area_ptr;      /* Pointer to the upper left corner of the area to repaint */
  gdi_handle            gdi_layer;
} npplg_av_evt_paint_struct;

/* The structure of timer event */
typedef struct
{
  kal_int32             timer_id;       /* The id of the timer that was triggered */
} npplg_av_evt_timer_struct;

/* The structure of key event */
typedef struct
{
  kal_int32             repeat_count;   /* The repeat count is increased for each key down. A repeat_count > 0 means that the key is held down */
  kal_int16             key;            /* mmi_keypads_enum */
  kal_uint8             reason;         /* npplg_av_evt_key_enum */
} npplg_av_evt_key_struct;

/* The structure of mouse event */
typedef struct
{
  kal_int32             x;              /* The x-position of the mouse pointer when the event was triggered  */
  kal_int32             y;              /* The y-position of the mouse pointer when the event was triggered */
  kal_uint8             reason;         /* npplg_av_evt_mouse_enum */
} npplg_av_evt_mouse_struct;

/* The structure of activate event */
typedef struct
{
  kal_bool              activate;       /* TRUE: activate a plug-in instance, FALSE: deactivate a plug-in instance */
} npplg_av_evt_activate_struct;

/* The structure of focus event */
typedef struct
{
  kal_bool              focus;          /* TRUE: focus in, FALSE: focus out */
} npplg_av_evt_focus_struct;

/* The event which is taken place in the plug-in's window or drawable area or needed by the plug-in */
typedef struct
{
  void                      *detail;        /* The detail info of the event */
  npplg_av_evt_type_enum    type;           /* npplg_av_evt_type_enum */
} npplg_av_event_struct;

/* Paint info */
typedef struct
{
  kal_int32 width;
  kal_int32 height;
  kal_int32 pixel_size;
  kal_int32 stride;
  kal_int8  pixel_format;
} npplg_av_paint_info_struct;

/* Plug-in's window structure */
typedef struct
{
  npplg_av_start_timer              start_timer;
  npplg_av_stop_timer               stop_timer;
  npplg_av_get_visible_screen_area  get_visible_screen_area;
  npplg_av_trans_to_screen_coord    trans_coord;
  npplg_av_display_popup            display_popup;
  void                              *data;
} npplg_av_window_struct;


/************************************************************
 * Global Function
 ************************************************************/
extern void npplg_av_main_initialize(void);
extern NPError npplg_av_main_user_initialize(NPNetscapeFuncs *ns_table,
                                             NPPluginFuncs *plugin_func,
                                             NPluginMTKExtFuncs *ext_func,
                                             kal_uint8 app_id);
extern NPError npplg_av_main_user_terminate(kal_uint8 app_id);
extern void npplg_av_main_get_aud_default_size(kal_int32 *width, kal_int32 *height);
extern void npplg_av_main_auto_play_audio(kal_uint8 app_id, kal_bool notify_app);
extern kal_bool npplg_av_main_is_playing(kal_uint8 app_id);
extern gdi_handle npplg_av_main_get_video_layer_handle(kal_uint8 app_id);
extern void npplg_av_main_mmi_notify_suspend(kal_uint8 app_id);
extern void npplg_av_main_mmi_notify_resume(kal_uint8 app_id);
extern void npplg_av_main_mmi_notify_close(kal_uint8 app_id);
extern void npplg_av_main_mmi_notify_reset(kal_uint8 app_id);
extern void npplg_av_main_mmi_notify_video_visual_update(kal_uint8 app_id, kal_bool lcm_update, kal_bool force_update, kal_bool clear_vdo_layer);
extern void npplg_av_main_mmi_notify_screen_rotate(kal_uint8 app_id, kal_int32 lcd_orientation);
extern void npplg_av_main_stop_current_activity(kal_uint8 app_id);
extern gdi_handle npplg_av_main_get_plugin_layer(kal_uint8 app_id);
extern kal_bool npplg_av_main_message_dispatcher(void *ilm_ptr);
extern void npplg_av_main_notify_scroll(kal_uint8 app_id);
extern void npplg_av_main_notify_screen_rotation_complete(kal_uint8 app_id, kal_int32 lcd_orientatioin);
extern NPError npplg_av_main_is_instance_active(NPP instance, kal_bool *is_active);
extern void npplg_av_main_assign_utility_function(NPP instance, npplg_av_window_struct *plugin_win);

#endif /* NPPLG_AV_INCLUDE_H */
