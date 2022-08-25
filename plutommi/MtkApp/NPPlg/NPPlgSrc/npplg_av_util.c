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
 *   npplg_av_util.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Provide utility functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

/************************************************************
 * Include
 ************************************************************/
#include "MMI_features.h"

#include "stack_config.h"

/* Applib header file */
#include "app_mine.h"
#include "app_str.h"

/* Charset convert */
#include "Conversions.h"

/* MDI header file */
#include "mdi_datatype.h"
#include "mdi_include.h"

/* A/V Plug-in header file */
#include "npplg_av_include.h"
#include "npplg_av_main.h"
#include "npplg_av_audio.h"
#include "npplg_av_video.h"
#include "npplg_av_stream.h"
#include "npplg_av_util.h"
#include "npplg_av_custom_config.h"
#include "mmi_rp_app_npplg_def.h"
#include "npplg_struct.h"

#include "kal_public_defs.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "FontRes.h"
#include "PixcomFontEngine.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "stdio.h"
#include "string.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_common.h"
#include "stack_ltlcom.h"
#include "kal_active_module.h"
#include "GlobalResDef.h"


/* Conversions.h does not add this function but many applications use it to calculate the destination buffer size*/
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);


/************************************************************
 * Define
 ************************************************************/
#define NPPLG_AV_INSTANCE_ID_DIGIT_NUM 12


/************************************************************
 * Global Variable
 ************************************************************/
/* A/V Plug-in mutex */
volatile module_type g_npplg_av_mutex_tid = MOD_NIL;
volatile int g_npplg_av_mutex_cnt = 0;
kal_mutexid g_npplg_av_mutex;


/************************************************************
 * Static Declaration
 ************************************************************/
static kal_bool npplg_av_util_allocate_control_list(npplg_av_instance_struct *plugin_data, kal_int32 control_num);
static void npplg_av_util_fill_control_field(npplg_av_obj_control_struct *control,
                                             kal_int32 x,
                                             kal_int32 y,
                                             kal_int32 width,
                                             kal_int32 height,
                                             kal_uint8 display,
                                             kal_uint8 type,
                                             kal_bool pressed);
static void npplg_av_util_draw_one_control(npplg_av_instance_struct *plugin_data,
                                           npplg_av_obj_control_struct *ctrl,
                                           gdi_handle paint_layer,
                                           npplg_av_rect_struct paint_area);
static void npplg_av_util_draw_processing_image(npplg_av_instance_struct *plugin_data,
                                                gdi_handle paint_layer);
static kal_bool npplg_av_util_can_launch_player(kal_uint8 player_type);


/************************************************************
 * Local Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_allocate_control_list
 * DESCRIPTION
 *  This function is used to allocate the memory used by playback controls.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  control_num     [IN]        Number of controls which the object has
 * RETURNS
 *  The result of allocation
 * RETURN VALUE LIST
 *  KAL_TRUE            Allocate successfully
 *  KAL_FALSE           Failed to allocate controls
 *****************************************************************************/
static kal_bool npplg_av_util_allocate_control_list(npplg_av_instance_struct *plugin_data, kal_int32 control_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_bool ret = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plugin_data->control_num = control_num;
    plugin_data->control_list = (npplg_av_obj_control_struct**)
                                    g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(npplg_av_obj_control_struct*) * control_num);

    if (plugin_data->control_list == NULL)
    {
        plugin_data->control_num = 0;
        return KAL_FALSE;
    }
    
    for (i = 0; i < control_num; i++)
    {
        plugin_data->control_list[i] = (npplg_av_obj_control_struct*)
                                            g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(npplg_av_obj_control_struct));

        if (plugin_data->control_list[i] == NULL)
        {
            ret = KAL_FALSE;
            break;
        }
    }

    if (ret == KAL_FALSE)
    {
        for (i = 0; i < control_num; i++)
        {
            NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->control_list[i]);
        }
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->control_list);
        plugin_data->control_num = 0;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_fill_control_field
 * DESCRIPTION
 *  This function is used to fill the fields of control.
 * PARAMETERS
 *  control     [IN/OUT]    Playback control or progress bar
 *  x           [IN]        Coordinates of top left corner
 *  y           [IN]        Coordinates of top left corner
 *  width       [IN]        The width of the control
 *  height      [IN]        The height of the control
 *  display     [IN]        Indicate this control is enabled, disabled or should not be drawn
 *  type        [IN]        Control type
 *  pressed     [IN]        Indicate the control is pressed or not
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_util_fill_control_field(npplg_av_obj_control_struct *control,
                                             kal_int32 x,
                                             kal_int32 y,
                                             kal_int32 width,
                                             kal_int32 height,
                                             kal_uint8 display,
                                             kal_uint8 type,
                                             kal_bool pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control->display = display;
    control->pressed = pressed;
    control->type = type;
    control->x = x;
    control->y = y;
    control->width = width;
    control->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_draw_one_control
 * DESCRIPTION
 *  This function is used to draw one control
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  ctrl            [IN]        The control should be drawn
 *  paint_layer     [IN]        Paint layer
 *  paint_area      [IN]        Paint area
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_util_draw_one_control(npplg_av_instance_struct *plugin_data,
                                           npplg_av_obj_control_struct *ctrl,
                                           gdi_handle paint_layer,
                                           npplg_av_rect_struct paint_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x, y, update_width;
    kal_uint8 *img_ptr;
    kal_uint64 total_time, play_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = plugin_data->x + ctrl->x;
    y = plugin_data->y + ctrl->y;

    if (x > (paint_area.x + paint_area.w - 1) ||
        (x + ctrl->width - 1) < paint_area.x ||
        y > (paint_area.y + paint_area.h - 1) ||
        (y + ctrl->height - 1) < paint_area.y)
    {
        return;
    }

    if (ctrl->type == NPPLG_AV_CTRL_TYPE_PROGRESS_BAR)
    {
        kal_int32 new_clip_x1, new_clip_y1, new_clip_x2, new_clip_y2;

        update_width = 0;

        /* Draw progress bar background */
        new_clip_x1 = ((paint_area.x < x) ? x : paint_area.x);
        new_clip_y1 = ((paint_area.y < y) ? y : paint_area.y);
        new_clip_x2 = (((paint_area.x + paint_area.w - 1) < (x + ctrl->width - 1)) ? (paint_area.x + paint_area.w - 1) : (x + ctrl->width - 1));
        new_clip_y2 = (((paint_area.y + paint_area.h - 1) < (y + ctrl->height - 1)) ? (paint_area.y + paint_area.h - 1) : (y + ctrl->height - 1));

        img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PROGRESS_BG);

        gdi_layer_push_clip();
        gdi_layer_set_clip(new_clip_x1, new_clip_y1, new_clip_x2, new_clip_y2);
        gdi_push_and_set_alpha_blending_source_layer(paint_layer);
        gdi_image_draw_resized_blend2layers(x,
                                            y,
                                            ctrl->width,
                                            g_npplg_av_context.bar_height,
                                            img_ptr);
        gdi_pop_and_restore_alpha_blending_source_layer();
        gdi_layer_pop_clip();
        
        
        /* Get the total duration and the current playing time */
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            total_time = ((npplg_av_audio_data_struct*)plugin_data->obj_data)->total_time;
            play_time =  ((npplg_av_audio_data_struct*)plugin_data->obj_data)->play_time;
        }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        else
        {
            total_time = ((npplg_av_video_data_struct*)plugin_data->obj_data)->total_time;
            play_time =  ((npplg_av_video_data_struct*)plugin_data->obj_data)->play_time;
        }
#else /* __MMI_VIDEO_PLAY_SUPPORT__ */
        else
        {
            ASSERT(0);
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */


        if (total_time > 0 && play_time > 0)
        {
            /* Draw foreground image */
            update_width = (kal_int32)(play_time * ctrl->width / total_time);
            img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PROGRESS_FG);
            
            new_clip_x1 = ((paint_area.x < x) ? x : paint_area.x);
            new_clip_y1 = ((paint_area.y < y) ? y : paint_area.y);
            new_clip_x2 = (((paint_area.x + paint_area.w - 1) < (x + update_width - 1)) ? (paint_area.x + paint_area.w - 1) : (x + update_width - 1));
            new_clip_y2 = (((paint_area.y + paint_area.h - 1) < (y + ctrl->height - 1)) ? (paint_area.y + paint_area.h - 1) : (y + ctrl->height - 1));

            gdi_layer_push_clip();
            gdi_layer_set_clip(new_clip_x1, new_clip_y1, new_clip_x2, new_clip_y2);
            gdi_push_and_set_alpha_blending_source_layer(paint_layer);
            gdi_image_draw_resized_blend2layers(x,
                                                y,
                                                update_width,
                                                g_npplg_av_context.bar_height,
                                                img_ptr);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_clip();
        }
    }
    else if (ctrl->type == NPPLG_AV_CTRL_TYPE_TIME)
    {
        stFontAttribute font, small_font = {0, 0, 0, SMALL_FONT, 0, 0};
        U8 arr_count;
        kal_wchar str[20];
        kal_int32 p_hour, p_min, p_sec, t_hour, t_min, t_sec;
        
        /*
         * Convert time to string
         * Get the total duration and the current playing time
         */
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            total_time = ((npplg_av_audio_data_struct*)plugin_data->obj_data)->total_time / NPPLG_AV_UTIL_SEC_TO_MS;
            play_time =  ((npplg_av_audio_data_struct*)plugin_data->obj_data)->play_time / NPPLG_AV_UTIL_SEC_TO_MS;
        }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        else
        {
            total_time = ((npplg_av_video_data_struct*)plugin_data->obj_data)->total_time / NPPLG_AV_UTIL_SEC_TO_MS;
            play_time =  ((npplg_av_video_data_struct*)plugin_data->obj_data)->play_time / NPPLG_AV_UTIL_SEC_TO_MS;
        }
#else /* __MMI_VIDEO_PLAY_SUPPORT__ */
        else
        {
            ASSERT(0);
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
        
        t_hour = total_time / NPPLG_AV_UTIL_HOUR_TO_SEC;
        t_min = (total_time % NPPLG_AV_UTIL_HOUR_TO_SEC) / NPPLG_AV_UTIL_MIN_TO_SEC;
        t_sec = total_time % NPPLG_AV_UTIL_MIN_TO_SEC;

        p_hour = play_time / NPPLG_AV_UTIL_HOUR_TO_SEC;
        p_min = (play_time % NPPLG_AV_UTIL_HOUR_TO_SEC) / NPPLG_AV_UTIL_MIN_TO_SEC;
        p_sec = play_time % NPPLG_AV_UTIL_MIN_TO_SEC;

        if (play_time >= NPPLG_AV_UTIL_TIME)
        {
            if (total_time >= NPPLG_AV_UTIL_TIME)
            {
                kal_wsprintf(str, "99:59:59 / 99:59:59");
            }
            else
            {
                kal_wsprintf(str, "99:59:59 / %02d:%02d:%02d", t_hour, t_min, t_sec);
            }
        }
        else
        {
            if (total_time >= NPPLG_AV_UTIL_TIME)
            {
                kal_wsprintf(str, "%02d:%02d:%02d / 99:59:59", p_hour, p_min, p_sec);
            }
            else
            {
                kal_wsprintf(str, "%02d:%02d:%02d / %02d:%02d:%02d", p_hour, p_min, p_sec, t_hour, t_min, t_sec);
            }
        }

        /* Draw string */
        GetFont(&font, &arr_count);
        SetFont(small_font, 0);
        mmi_fe_set_text_color(g_npplg_av_cfg_play_time_str_color);
        mmi_fe_show_string_ext(x, y, (U8*)str);
    }
    else
    {
        kal_int32 img_w, img_h, real_x, real_y;

        if (plugin_data->control_num == 1 &&
            (ctrl->type == NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER ||
             ctrl->type == NPPLG_AV_CTRL_TYPE_PLAY ||
             ctrl->type == NPPLG_AV_CTRL_TYPE_STOP))
        {
            img_ptr = npplg_av_util_get_image(ctrl->type, ctrl->display, ctrl->pressed, plugin_data->control_num);
            gdi_image_get_dimension(img_ptr, &img_w, &img_h);

            if (ctrl->pressed)
            {
                real_x = x + (ctrl->width - img_w) / 2 + 2;
                real_y = y + (ctrl->height - img_h) / 2 + 2;
            }
            else
            {
                real_x = x + (ctrl->width - img_w) / 2;
                real_y = y + (ctrl->height - img_h) / 2;
            }
            gdi_push_and_set_alpha_blending_source_layer(paint_layer);
            gdi_image_draw_blend2layers(real_x, real_y, img_ptr);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        else
        {
            if (ctrl->pressed)
            {
                /* Fill background */
                img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_HIGHLIGHT);
                gdi_push_and_set_alpha_blending_source_layer(paint_layer);
                gdi_image_draw_resized_blend2layers(x, y, ctrl->width, ctrl->height, img_ptr);
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
            
            img_ptr = npplg_av_util_get_image(ctrl->type, ctrl->display, ctrl->pressed, plugin_data->control_num);
            gdi_image_get_dimension(img_ptr, &img_w, &img_h);
            real_x = x + (ctrl->width - img_w) / 2;
            real_y = y + (ctrl->height - img_h) / 2;
            gdi_push_and_set_alpha_blending_source_layer(paint_layer);
            gdi_image_draw_blend2layers(real_x, real_y, img_ptr);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_draw_processing_image
 * DESCRIPTION
 *  This function is used to draw processing image.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  paint_layer     [IN]        Paint layer
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_util_draw_processing_image(npplg_av_instance_struct *plugin_data,
                                                gdi_handle paint_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x, y, img_w, img_h;
    kal_uint8 *img_ptr;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(plugin_data->x,
                        plugin_data->y,
                        plugin_data->x + plugin_data->width - 1,
                        plugin_data->y + plugin_data->processing_img_h - 1,
                        GDI_COLOR_BLACK);

    img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PROCESSING);
    gdi_image_get_dimension(img_ptr, &img_w, &img_h);

    x = plugin_data->x + (plugin_data->width - img_w) / 2;

    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        /* If object is audio, always draw processing image in the center */
        y = plugin_data->y + (plugin_data->height - img_h) / 2;
    }
    else
    {
        y = plugin_data->y + (plugin_data->processing_img_h - img_h) / 2;
    }

    if (g_npplg_av_context.processing_img_num > 0 &&
        plugin_data->processing_img_indx >= g_npplg_av_context.processing_img_num)
    {
        plugin_data->processing_img_indx = 0;

    }

    /*
     * To get animation delay, plug-in should call gdi_anim_draw_frames() instead of
     * gdi_image_draw_frames() because gdi_image_draw_frames() won't update gdi_anim_delay_time.
     *
     * If plug-in calls gdi_image_draw_frames(), gdi_anim_get_delay() will return unexpected value.
     *
     * After plug-in calls gdi_anim_draw_frames(), plug-in should get delay and stop animation.
     */
    gdi_push_and_set_alpha_blending_source_layer(paint_layer);
    ret = gdi_image_draw_frames_blend2layers(x, y, img_ptr, plugin_data->processing_img_indx);
    gdi_pop_and_restore_alpha_blending_source_layer();
    
    if (ret < 0)
    {
        g_npplg_av_context.processing_img_num = plugin_data->processing_img_indx;
        plugin_data->processing_img_indx = 0;
        gdi_push_and_set_alpha_blending_source_layer(paint_layer);
        ret = gdi_image_draw_frames_blend2layers(x, y, img_ptr, 0);
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_can_launch_player
 * DESCRIPTION
 *  This function is used to check whether plug-in can launch player
 * PARAMETERS
 *  player_type     [IN]    Player type
 * RETURNS
 *  Indicate whether plug-in can launch player
 *****************************************************************************/
static kal_bool npplg_av_util_can_launch_player(kal_uint8 player_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__PLUTO_MMI_PACKAGE__)

    if (player_type == NPPLG_AV_PLAYER_TYPE_AUDIO)
    {
        return KAL_TRUE;
    }
    else if (player_type == NPPLG_AV_PLAYER_TYPE_VIDEO)
    {
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)
        return KAL_TRUE;
#endif
    }
    else if (player_type == NPPLG_AV_PLAYER_TYPE_STREAM)
    {
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_STREAM__)
        return KAL_TRUE;
#endif
    }

#elif defined(__COSMOS_MMI_PACKAGE__)

    if (player_type == NPPLG_AV_PLAYER_TYPE_AUDIO)
    {
        return KAL_TRUE;
    }
    else if (player_type == NPPLG_AV_PLAYER_TYPE_VIDEO || player_type == NPPLG_AV_PLAYER_TYPE_STREAM)
    {
#ifdef __MMI_FTO_GALLERY__
        return KAL_TRUE;
#endif
    }

#endif /* __PLUTO_MMI_PACKAGE__ */

    return KAL_FALSE;
}


/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_gen_filename
 * DESCRIPTION
 *  This utility function is to generate the filename.
 *  Caller should free the memory which is allocated for the filename.
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  instance_id     [IN]        Instance id
 *  drive_letter    [IN]        The drive of plug-in folder
 *  url             [IN]        URL
 *  mime_type       [IN]        MIME type
 *  file_path       [OUT]       Generated filename
 * RETURNS
 *  Generated filename
 *****************************************************************************/
kal_wchar *npplg_av_util_gen_filename(kal_uint8 app_id,
                                      kal_uint32 instance_id,
                                      kal_int32 drive_letter,
                                      kal_char *url,
                                      kal_char *mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 url_len, gen_fname_len;
    kal_char *file_extension;
    kal_wchar *gen_fname = NULL;
    applib_mime_type_struct *entry = NULL;
    kal_char temp[NPPLG_AV_INSTANCE_ID_DIGIT_NUM] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Should not use URL to extract filename
     *
     * Consider following scenario:
     * 1. http://wap1.mtk.com.tw/a.mp4
     * 2. http://wap1.mtk.com.tw/iris/a.mp4
     *
     * If we extract file name from URL, the first created file a.mp3 is deleted when plug-in creates the second a.mp3 file.
     * It is not correct behavior.
     *
     * Generate a unique filename
     * 1. Extract the file extension from the URL
     * 2. Use the plug-in instance id as the filename
     * 3. Filename would be plugin_instance_id.file_extension
     * 4. If can not extract valid file extension, use the MIME type
     */
    ASSERT(url != NULL && mime_type != NULL);
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_GEN_FILENAME, instance_id, url);

    sprintf(temp, "%d", instance_id);
    url_len = strlen(url);

    /* Find file extension from URL */
    for (file_extension = (url + url_len); file_extension >= url; file_extension--)
    {
        if (*file_extension == '.')
        {
            file_extension++;
            break;
        }
    }

    if (url_len <= 0 ||
        file_extension <= url ||
        file_extension > (url + url_len) ||
        (entry = applib_mime_type_look_up(NULL, file_extension, MIME_TYPE_NONE, MIME_SUBTYPE_NONE)) == NULL)
    {
        /*
         * URL does not have file extension or file extension is wrong
         * Use the MIME type to find the file extension
         */

        if ((entry = applib_mime_type_look_up(mime_type, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE)) == NULL)
        {
            ASSERT(0);
            return NULL;
        }

        file_extension = entry->file_ext;
    }

    gen_fname_len = (strlen(NPPLG_AV_TMP_FILE_PATH) + strlen(temp) + strlen(file_extension) + 6) * sizeof(kal_wchar); /* drive_letter:\@avplugin\temp.file_extension */
    gen_fname = (kal_wchar*)g_npplg_av_netscape_funcs[app_id].memalloc(gen_fname_len);
    if (gen_fname == NULL)
    {
        return NULL;
    }
    
    memset(gen_fname, 0, gen_fname_len);
    kal_wsprintf(gen_fname,
                 "%c:\\%s\\%s.%s",
                 drive_letter,
                 NPPLG_AV_TMP_FILE_PATH,
                 temp,
                 file_extension);
    
    return gen_fname;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_get_image
 * DESCRIPTION
 *  This function is used to get the image according to the control type and control display.
 * PARAMETERS
 *  type        [IN]        Control type
 *  display     [IN]        Indicate this control is enabled, disabled or should not be drawn
 *  ctrl_num    [IN]        Number of play controls
 *  pressed     [IN]        Pressed or not
 * RETURNS
 *  Image pointer
 *****************************************************************************/
kal_uint8 *npplg_av_util_get_image(kal_uint8 type, kal_uint8 display, kal_bool pressed, kal_uint8 ctrl_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (type)
    {
        case NPPLG_AV_CTRL_TYPE_PLAY:
        {
            if (ctrl_num > 1)
            {
                if (display == NPPLG_AV_CTRL_DISP_ENABLE)
                {
                    if (pressed)
                        return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PLAY_PRESSED);
                    else
                        return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PLAY);
                }
                else if (display == NPPLG_AV_CTRL_DISP_DISABLE)
                {
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PLAY_DISABLE);
                }
            }
            else
            {
                return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PLAY_ONLY);
            }
            break;
        }

        case NPPLG_AV_CTRL_TYPE_PAUSE:
        {
            if (display == NPPLG_AV_CTRL_DISP_ENABLE)
            {
                if (pressed)
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PAUSE_PRESSED);
                else
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PAUSE);
            }
            else if (display == NPPLG_AV_CTRL_DISP_DISABLE)
            {
                return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PAUSE_DISABLE);
            }
            break;
        }

        case NPPLG_AV_CTRL_TYPE_STOP:
        {
            if (ctrl_num > 1)
            {
                if (display == NPPLG_AV_CTRL_DISP_ENABLE)
                {
                    if (pressed)
                        return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_STOP_PRESSED);
                    else
                        return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_STOP);
                }
                else if (display == NPPLG_AV_CTRL_DISP_DISABLE)
                {
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_STOP_DISABLE);
                }
            }
            else
            {
                return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_STOP_ONLY);
            }
            break;
        }

        case NPPLG_AV_CTRL_TYPE_FAST_FORWARD:
        {
            if (display == NPPLG_AV_CTRL_DISP_ENABLE)
            {
                if (pressed)
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_FAST_FORWARD_PRESSED);
                else
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_FAST_FORWARD);
            }
            else if (display == NPPLG_AV_CTRL_DISP_DISABLE)
            {
                return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_FAST_FORWARD_DISABLE);
            }
            break;
        }

        case NPPLG_AV_CTRL_TYPE_REWIND:
        {
            if (display == NPPLG_AV_CTRL_DISP_ENABLE)
            {
                if (pressed)
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_REWIND_PRESSED);
                else
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_REWIND);
            }
            else if (display == NPPLG_AV_CTRL_DISP_DISABLE)
            {
                return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_REWIND_DISABLE);
            }
            break;
        }

        case NPPLG_AV_CTRL_TYPE_MUTE:
        {
            if (display == NPPLG_AV_CTRL_DISP_ENABLE)
            {
                if (pressed)
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_SPEAKER_ON_PRESSED);
                else
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_SPEAKER_ON);
            }
            else if (display == NPPLG_AV_CTRL_DISP_DISABLE)
            {
                if (pressed)
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_SPEAKER_OFF_PRESSED);
                else
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_SPEAKER_OFF);
            }
            break;
        }

        case NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER:
        {
            if (ctrl_num > 1)
            {
                if (pressed)
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_MEDIA_PLAYER_PRESSED);
                else
                    return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_MEDIA_PLAYER);
            }

            return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_MEDIA_PLAYER_PLAY);
        }

        case NPPLG_AV_CTRL_TYPE_SEPARATE_LINE:
            return (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_CTRL_SEPARATE_LINE);

        default:
            break;
    }

    ASSERT(0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_compose_play_panel
 * DESCRIPTION
 *  This function is used to decide which playback controls should be displayed and the position of them.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  obj_type            [IN]    Object type
 *  ctrl_arrey          [IN]    Indicate the layout of the playback controls
 *  play_panel_num      [IN]    The number of different play panel
 *  support_ctrl_num    [IN]    The maximum number of playback control in play panel
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_compose_play_panel(npplg_av_instance_struct *plugin_data,
                                      kal_uint8 obj_type,
                                      const kal_uint8 *ctrl_array[],
                                      kal_uint8 play_panel_num,
                                      kal_uint8 support_ctrl_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x, y, i, j, obj_width, obj_height, icon_width, icon_height, bar_height, render_width, render_height, x1, y1;
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
    kal_int32 separate_width;
#endif
    kal_bool cache_built = KAL_FALSE, launch_aud_player = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Free old controls */
    npplg_av_util_free_control_list(plugin_data);    

#ifdef OPERA_V10_BROWSER
    /*
     * MAUI_02579576
     * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
     * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
     */
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
        (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
        plugin_data->window = NULL;
    }
#endif /* OPERA_V10_BROWSER */

    if (plugin_data->window == NULL || plugin_data->width <= 0 || plugin_data->height <= 0)
    {
        return;
    }
    
    icon_width = g_npplg_av_context.icon_width;
    icon_height = g_npplg_av_context.icon_height;
    obj_width = plugin_data->width;
    obj_height = plugin_data->height;
    bar_height = g_npplg_av_context.bar_height;
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
    separate_width = g_npplg_av_context.separate_width;
#endif

    npplg_av_main_get_visible_screen_area(plugin_data, &x1, &y1, &render_width, &render_height);

    if (obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

        if (aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK ||
            aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL)
        {
            cache_built = KAL_TRUE;
        }

        if (aud_data->only_launch_aud_player)
        {
            launch_aud_player = KAL_TRUE;
        }
    }

#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    if ((obj_type == NPPLG_AV_OBJ_TYPE_AUDIO &&
         (plugin_data->dl_state != NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK ||
          cache_built == KAL_FALSE ||
          launch_aud_player == KAL_TRUE ||
          obj_width < (2 * icon_width + separate_width))) ||
        (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
         (obj_width < NPPLG_AV_CFG_MIN_VDO_WIDTH ||
          obj_width < (2 * icon_width + separate_width) ||
          obj_height < NPPLG_AV_CFG_MIN_VDO_HEIGHT ||
          obj_height < (2 * icon_height) ||
          obj_width > render_width ||
          obj_height > render_height)))
#else
    if (plugin_data->dl_state != NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK ||
        cache_built == KAL_FALSE ||
        launch_aud_player == KAL_TRUE ||
        obj_width < (2 * icon_width + separate_width))
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#else /* NPPLG_AV_CFG_DRAW_SEPARATE_LINE */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    if ((obj_type == NPPLG_AV_OBJ_TYPE_AUDIO &&
         (plugin_data->dl_state != NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK ||
          cache_built == KAL_FALSE ||
          launch_aud_player == KAL_TRUE ||
          obj_width < (2 * icon_width))) ||
        (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
         (obj_width < NPPLG_AV_CFG_MIN_VDO_WIDTH ||
          obj_width < (2 * icon_width) ||
          obj_height < NPPLG_AV_CFG_MIN_VDO_HEIGHT ||
          obj_height < (2 * icon_height) ||
          obj_width > render_width ||
          obj_height > render_height)))
#else
    if (plugin_data->dl_state != NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK ||
        cache_built == KAL_FALSE ||
        launch_aud_player == KAL_TRUE ||
        obj_width < (2 * icon_width))
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#endif /* NPPLG_AV_CFG_DRAW_SEPARATE_LINE */
    {
        /*
         * Audio object
         * (1) Plug-in will only draw the "Play" playback control.
         * (2) When user presses the "Play" icon, plug-in will play the audio and change the icon to "Pause" icon.
         * (3) When user presses the "Pause" icon, plug-in will pause the audio playing and change the icon to "Play" icon.
         *
         * Video object (file, PDL, streaming)
         * (1) Draw a "Media player" icon in the center
         * (2) When user clicks the video object, plug-in would launch the media player to play the video.
         */

        x = (obj_width - icon_width) / 2;
        y = (obj_height - icon_height) / 2;
        
        if (npplg_av_util_allocate_control_list(plugin_data, 1) == KAL_FALSE)
        {
            return;
        }

        npplg_av_util_fill_control_field(plugin_data->control_list[0],
                                         x,
                                         y,
                                         icon_width,
                                         icon_height,
                                         NPPLG_AV_CTRL_DISP_ENABLE,
                                         ctrl_array[0][0],
                                         KAL_FALSE);

        plugin_data->empty_control = plugin_data->control_list[0];
        plugin_data->processing_img_h = obj_height;
    }
    else
    {
        /* Calculate the width and height of string "00:00:00 / 00:00:00" */
        stFontAttribute font, small_font = {0, 0, 0, SMALL_FONT, 0, 0};
        U8 arr_count;
        S32 str_w, str_h, w[4], h[4];
        kal_int32 max_h, average_w;

        GetFont(&font, &arr_count);
        SetFont(small_font, 0);
        mmi_fe_measure_string_by_char_num((U8*)(L"0123456789"), 12, &w[0], &h[0]);
        mmi_fe_measure_string_by_char_num((U8*)(L":"), 4, &w[1], &h[1]);
        mmi_fe_measure_string_by_char_num((U8*)(L"/"), 1, &w[2], &h[2]);
        mmi_fe_measure_string_by_char_num((U8*)(L" "), 2, &w[3], &h[3]);
        SetFont(font, arr_count);
        str_w = w[0] + w[1] + w[2] + w[3] + NPPLG_AV_UTIL_SPACE;
        str_h = h[0];

        for (i = 1; i < 4; i++)
        {
            if (h[i] > str_h)
            {
                str_h = h[i];
            }
        }

        if (str_h > bar_height)
        {
            max_h = str_h;
        }
        else
        {
            max_h = bar_height;
        }
    
        for (i = 1; i < play_panel_num; i++)
        {
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
            if ((obj_width >= ((i + 1) * icon_width + i * separate_width) &&
                 obj_width < ((i + 2) * icon_width + (i + 1) * separate_width)) ||
                i == (play_panel_num - 1))
#else
            if ((obj_width >= ((i + 1) * icon_width) &&
                 obj_width < ((i + 2) * icon_width)) ||
                i == (play_panel_num - 1))
#endif
            {
                kal_bool prog_bar, play_time;
                kal_int32 play_idx, ctrl_num;

                prog_bar = KAL_FALSE;
                play_time = KAL_FALSE;
                x = 0;
                y = obj_height - icon_height;
                play_idx = 0;

                for (j = 0; j < support_ctrl_num; j++)
                {
                    if (ctrl_array[i][j] == NPPLG_AV_CTRL_TYPE_PLAY)
                    {
                        play_idx = j;
                    }
                }

                if (i == (play_panel_num - 1) &&
                    obj_width >= ((i + 1) * (icon_width + separate_width) + str_w + NPPLG_AV_UTIL_SPACE))
                {
                    if (obj_width < ((i + 3) * icon_width + (i + 1) * separate_width + str_w + NPPLG_AV_UTIL_SPACE * 2) &&
                        obj_height < (icon_height + bar_height + NPPLG_AV_UTIL_SPACE))
                    {
                        /* Can only put icon + playing time */
                        play_time = KAL_TRUE;
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                        ctrl_num = (i + 1) * 2 + 1;
#else
                        ctrl_num = i + 2;
#endif
                        plugin_data->processing_img_h = y;
                    }
                    else
                    {
                        /* Can put progress bar + playing time */
                        prog_bar = KAL_TRUE;
                        play_time = KAL_TRUE;
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                        ctrl_num = (i + 1) * 2 + 2;
#else
                        ctrl_num = i + 3;
#endif

                        if (obj_width >= ((i + 3) * icon_width + (i + 1) * separate_width + str_w + NPPLG_AV_UTIL_SPACE * 2))
                        {
                            plugin_data->processing_img_h = y;
                        }
                        else
                        {
                            plugin_data->processing_img_h = y - bar_height - NPPLG_AV_UTIL_SPACE;
                        }
                    }
                }
                else
                {
                    /* Decide whether we can put icon + progress bar + playing time */
                    if (obj_height < (icon_height + max_h + NPPLG_AV_UTIL_SPACE) ||
                        obj_width < str_w)
                    {
                        /* Can not put progress bar + playing time */
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                        ctrl_num = i * 2 + 1;
#else
                        ctrl_num = i + 1;
#endif
                        plugin_data->processing_img_h = y;
                    }
                    else
                    {
                        if (obj_width >= (str_w + icon_width * 2 + NPPLG_AV_UTIL_SPACE * 2))
                        {
                            /* Can put progress bar + playing time */
                            prog_bar = KAL_TRUE;
                            play_time = KAL_TRUE;
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                            ctrl_num = i * 2 + 3;
#else
                            ctrl_num = i + 3;
#endif
                        }
                        else
                        {
                            /* Can only put playing time */
                            play_time = KAL_TRUE;
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                            ctrl_num = i * 2 + 2;
#else
                            ctrl_num = i + 2;
#endif
                        }
                        
                        plugin_data->processing_img_h = y - max_h - NPPLG_AV_UTIL_SPACE;
                    }
                }

                /* Allocate control list */
                if (npplg_av_util_allocate_control_list(plugin_data, ctrl_num) == KAL_FALSE)
                {
                    return;
                }

                if (i == (play_panel_num - 1) &&
                    obj_width >= ((i + 1) * (icon_width + separate_width) + str_w + NPPLG_AV_UTIL_SPACE))
                {
                    /* Add playing time */
                    npplg_av_util_fill_control_field(plugin_data->control_list[i + 1],
                                                     obj_width - str_w,
                                                     y + (icon_height - str_h) / 2,
                                                     str_w,
                                                     str_h,
                                                     NPPLG_AV_CTRL_DISP_ENABLE,
                                                     NPPLG_AV_CTRL_TYPE_TIME,
                                                     KAL_FALSE);

                    if (obj_width < ((i + 3) * icon_width + (i + 1) * separate_width + str_w + NPPLG_AV_UTIL_SPACE * 2))
                    {
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                        average_w = (obj_width - (i + 1) * separate_width - str_w - NPPLG_AV_UTIL_SPACE) / (i + 1);
#else
                        average_w = (obj_width - str_w - NPPLG_AV_UTIL_SPACE) / (i + 1);
#endif

                        if (obj_height >= (icon_height + bar_height + NPPLG_AV_UTIL_SPACE))
                        {
                            /* Add progress bar */
                            npplg_av_util_fill_control_field(plugin_data->control_list[i + 2],
                                                             NPPLG_AV_UTIL_SPACE,
                                                             y - bar_height - NPPLG_AV_UTIL_SPACE / 2,
                                                             obj_width - NPPLG_AV_UTIL_SPACE * 2,
                                                             bar_height,
                                                             NPPLG_AV_CTRL_DISP_ENABLE,
                                                             NPPLG_AV_CTRL_TYPE_PROGRESS_BAR,
                                                             KAL_FALSE);
                        }
                    }
                    else
                    {
                        average_w = icon_width;

                        /* Add progress bar */
                        npplg_av_util_fill_control_field(plugin_data->control_list[i + 2],
                                                         (i + 1) * (icon_width + separate_width) + NPPLG_AV_UTIL_SPACE,
                                                         y + (icon_height - bar_height) / 2,
                                                         obj_width - (i + 1) * (icon_width + separate_width) - str_w - NPPLG_AV_UTIL_SPACE * 2,
                                                         bar_height,
                                                         NPPLG_AV_CTRL_DISP_ENABLE,
                                                         NPPLG_AV_CTRL_TYPE_PROGRESS_BAR,
                                                         KAL_FALSE);
                    }
                }
                else
                {
                    if (play_time == KAL_TRUE)
                    {
                        /* Add playing time */
                        npplg_av_util_fill_control_field(plugin_data->control_list[i + 1],
                                                         obj_width - str_w,
                                                         y - (max_h - str_h) / 2 - str_h - NPPLG_AV_UTIL_SPACE / 2,
                                                         str_w,
                                                         str_h,
                                                         NPPLG_AV_CTRL_DISP_ENABLE,
                                                         NPPLG_AV_CTRL_TYPE_TIME,
                                                         KAL_FALSE);
                    }

                    if (prog_bar == KAL_TRUE)
                    {
                        /* Add progress bar */
                        npplg_av_util_fill_control_field(plugin_data->control_list[i + 2],
                                                         NPPLG_AV_UTIL_SPACE,
                                                         y - (max_h - bar_height) / 2 - bar_height - NPPLG_AV_UTIL_SPACE / 2,
                                                         obj_width - str_w - NPPLG_AV_UTIL_SPACE * 2,
                                                         bar_height,
                                                         NPPLG_AV_CTRL_DISP_ENABLE,
                                                         NPPLG_AV_CTRL_TYPE_PROGRESS_BAR,
                                                         KAL_FALSE);
                    }

#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                    average_w = (obj_width - i * separate_width) / (i + 1);
#else
                    average_w = obj_width / (i + 1);
#endif
                }

                for (j = 0; j < (i + 1); j++)
                {
                    if (j == i)
                    {
                        if (i == (play_panel_num - 1) &&
                            obj_width >= ((i + 1) * (icon_width + separate_width) + str_w + NPPLG_AV_UTIL_SPACE))
                        {
                            if (obj_width < ((i + 3) * icon_width + (i + 1) * separate_width + str_w + NPPLG_AV_UTIL_SPACE * 2))
                            {
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                                average_w = obj_width - (i + 1) * separate_width - j * average_w - str_w - NPPLG_AV_UTIL_SPACE;
#else
                                average_w = obj_width - j * average_w - str_w - NPPLG_AV_UTIL_SPACE;
#endif
                            }
                        }
                        else
                        {
#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                            average_w = obj_width - i * separate_width - j * average_w; /* The width of the last control */
#else
                            average_w = obj_width - j * average_w; /* The width of the last control */
#endif
                        }
                    }
                    
                    if (ctrl_array[i][j] == NPPLG_AV_CTRL_TYPE_FAST_FORWARD ||
                        ctrl_array[i][j] == NPPLG_AV_CTRL_TYPE_REWIND)
                    {
                        npplg_av_util_fill_control_field(plugin_data->control_list[j],
                                                         x,
                                                         y,
                                                         average_w,
                                                         icon_height,
                                                         (plugin_data->seekable ? NPPLG_AV_CTRL_DISP_ENABLE : NPPLG_AV_CTRL_DISP_DISABLE),
                                                         ctrl_array[i][j],
                                                         KAL_FALSE);
                        x += average_w;
                    }
                    else if (ctrl_array[i][j] == NPPLG_AV_CTRL_TYPE_MUTE)
                    {
                        npplg_av_util_fill_control_field(plugin_data->control_list[j],
                                                         x,
                                                         y,
                                                         average_w,
                                                         icon_height,
                                                         (plugin_data->mute ? NPPLG_AV_CTRL_DISP_DISABLE : NPPLG_AV_CTRL_DISP_ENABLE),
                                                         ctrl_array[i][j],
                                                         KAL_FALSE);
                        x += average_w;
                    }
                    else
                    {
                        npplg_av_util_fill_control_field(plugin_data->control_list[j],
                                                         x,
                                                         y,
                                                         average_w,
                                                         icon_height,
                                                         NPPLG_AV_CTRL_DISP_ENABLE,
                                                         ctrl_array[i][j],
                                                         KAL_FALSE);
                        x += average_w;
                    }

#ifdef NPPLG_AV_CFG_DRAW_SEPARATE_LINE
                    if ((j != i) ||
                        ((j == i) && (i == (play_panel_num - 1)) && (obj_width >= ((i + 1) * (icon_width + separate_width) + str_w + NPPLG_AV_UTIL_SPACE))))
                    {
                        npplg_av_util_fill_control_field(plugin_data->control_list[ctrl_num - j - 1],
                                                         x,
                                                         y,
                                                         separate_width,
                                                         icon_height,
                                                         NPPLG_AV_CTRL_DISP_DISABLE,
                                                         NPPLG_AV_CTRL_TYPE_SEPARATE_LINE,
                                                         KAL_FALSE);
                        x += separate_width;
                    }
#endif
                }

                plugin_data->empty_control = plugin_data->control_list[play_idx];
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_free_control_list
 * DESCRIPTION
 *  This function is used to free the memory used by playback controls.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_free_control_list(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < plugin_data->control_num; i++)
    {
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->control_list[i]);
    }
    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->control_list);
    plugin_data->empty_control = NULL;
    plugin_data->pressed_control = NULL;
    plugin_data->control_num = 0;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_invalidate_rect
 * DESCRIPTION
 *  This function is used to notify application that plug-in wants to update screen.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  ctrl            [IN]        The control which should be redrawn
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_invalidate_rect(npplg_av_instance_struct *plugin_data, npplg_av_obj_control_struct *ctrl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NPRect rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctrl != NULL)
    {
        rect.left = ctrl->x;
        rect.top = ctrl->y;
        rect.right = ctrl->x + ctrl->width - 1;
        rect.bottom = ctrl->y + ctrl->height - 1;
    }
    else
    {
        rect.left = 0;
        rect.top = 0;
        rect.right = plugin_data->width - 1;
        rect.bottom = plugin_data->height - 1;
    }
    g_npplg_av_netscape_funcs[plugin_data->app_id].invalidaterect(plugin_data->brw_instance, &rect);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_draw_controls
 * DESCRIPTION
 *  This function is used to refresh embedded audio object area.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  paint_layer     [IN]        The GDI layer where plug-in will draw the playback controls
 *  paint_area      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_draw_controls(npplg_av_instance_struct *plugin_data,
                                 gdi_handle paint_layer,
                                 npplg_av_rect_struct paint_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_uint8 *img_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef OPERA_V10_BROWSER
    /*
     * MAUI_02579576
     * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
     * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
     */
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
        (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
        plugin_data->window = NULL;
    }
#endif /* OPERA_V10_BROWSER */

    if (plugin_data->window == NULL ||
        paint_layer == GDI_NULL_HANDLE)
    {
        return;
    }
    
    /* Draw playback control on the paint buffer */
    gdi_layer_push_and_set_active(paint_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(paint_area.x,
                       paint_area.y,
                       paint_area.x + paint_area.w - 1,
                       paint_area.y + paint_area.h - 1);

    gdi_draw_solid_rect(plugin_data->x,
                        plugin_data->y,
                        plugin_data->x + plugin_data->width - 1,
                        plugin_data->y + plugin_data->height - 1,
                        GDI_COLOR_BLACK);

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO ||
        plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
    {
        npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

        if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE && plugin_data->processing == KAL_FALSE)
        {
            gdi_draw_solid_rect(plugin_data->x + vdo_data->offset_x,
                                plugin_data->y + vdo_data->offset_y,
                                plugin_data->x + vdo_data->offset_x + vdo_data->layer_w - 1,
                                plugin_data->y + vdo_data->offset_y + vdo_data->layer_h - 1,
                                npplg_av_main_get_transparent_color(plugin_data->app_id));
        }
        else if (vdo_data->vdo_layer_handle == GDI_NULL_HANDLE &&
                 plugin_data->processing == KAL_FALSE &&
                 vdo_data->audio_only == KAL_TRUE &&
                 vdo_data->layer_w > 0 &&
                 vdo_data->layer_h > 0)
        {
#ifdef __MMI_VIDEO_STREAM__
            if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE) ||
                (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING && plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_IDLE))
#else
            if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
#endif /* __MMI_VIDEO_STREAM__ */
            {
                kal_int32 img_w, img_h;

                img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_VIDEO_SMALL);
                gdi_image_get_dimension(img_ptr, &img_w, &img_h);
        
                /* Draw a image because the video only has audio track */
                gdi_image_draw(plugin_data->x + (vdo_data->layer_w - img_w) / 2,
                               plugin_data->y + (vdo_data->layer_h - img_h) / 2,
                               img_ptr);
            }
        }
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

    if (plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_DISPLAY)
    {
        if (plugin_data->control_num > 1)
        {
            if ((plugin_data->processing_img_h + g_npplg_av_context.icon_height) < plugin_data->height)
            {
                /* Draw the background image of progress bar */
                img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PROGRESS_PANEL);
                gdi_push_and_set_alpha_blending_source_layer(paint_layer);
                gdi_image_draw_resized_blend2layers(plugin_data->x,
                                                    plugin_data->y + plugin_data->processing_img_h,
                                                    plugin_data->width,
                                                    plugin_data->height - plugin_data->processing_img_h - g_npplg_av_context.icon_height,
                                                    img_ptr);
                gdi_pop_and_restore_alpha_blending_source_layer();
            }

            /* Draw the background image of play panel */
            img_ptr = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PLAY_PANEL);
            gdi_push_and_set_alpha_blending_source_layer(paint_layer);
            gdi_image_draw_resized_blend2layers(plugin_data->x,
                                                plugin_data->y + plugin_data->height - g_npplg_av_context.icon_height,
                                                plugin_data->width,
                                                g_npplg_av_context.icon_height,
                                                img_ptr);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }

        for (i = 0; i < plugin_data->control_num; i++)
        {
            npplg_av_util_draw_one_control(plugin_data,
                                           plugin_data->control_list[i],
                                           paint_layer,
                                           paint_area);
        }

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        if (plugin_data->obj_type != NPPLG_AV_OBJ_TYPE_AUDIO &&
            plugin_data->control_num > 1)
        {
            npplg_av_video_show_additional_info(plugin_data, paint_layer);
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    /* Check if plug-in should draw processing image */
    if (plugin_data->processing)
    {
        npplg_av_util_draw_processing_image(plugin_data, paint_layer);
    }

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_get_control
 * DESCRIPTION
 *  This function is used to get specific control.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  ctrl_type       [IN]        Control type
 * RETURNS
 *  Found control
 *****************************************************************************/
npplg_av_obj_control_struct *npplg_av_util_get_control(npplg_av_instance_struct *plugin_data, kal_uint8 ctrl_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < plugin_data->control_num; i++)
    {
        if (plugin_data->control_list[i]->type == ctrl_type)
        {
            return plugin_data->control_list[i];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_show_processing_image
 * DESCRIPTION
 *  This function is used to show processing image.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  start_timer     [IN]        Set timer after drawing the image
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_show_processing_image(npplg_av_instance_struct *plugin_data, kal_bool start_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plugin_data->processing = KAL_TRUE;
    npplg_av_util_invalidate_rect(plugin_data, NULL);

    /* Start a timer to update processing image */
    if (start_timer)
    {
        npplg_av_main_start_timer(plugin_data,
                                  NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG,
                                  NPPLG_AV_UPDATE_PROCESSING_IMG_DELAY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_update_play_control
 * DESCRIPTION
 *  This function is used to update "Play" control.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  playing         [IN]        Audio/video is playing or not
 *  draw            [IN]        Should draw on the paint buffer or not
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_update_play_control(npplg_av_instance_struct *plugin_data,
                                       kal_bool playing,
                                       kal_bool draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *play, *stop, *pause, *update_ctrl;
    npplg_av_obj_control_struct **ctrl_list;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    play = NULL;
    stop = NULL;
    pause = NULL;
    update_ctrl = NULL;
    ctrl_list = plugin_data->control_list;
    
    for (i = 0; i < plugin_data->control_num; i++)
    {
        if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_PLAY)
        {
            play = ctrl_list[i];
        }
        else if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_STOP)
        {
            stop = ctrl_list[i];
        }
        else if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_PAUSE)
        {
            pause = ctrl_list[i];
        }
    }

    if (playing)
    {
        /* Change "Play" control to "Pause" control or "Stop" control */
        if ((play != NULL && stop != NULL && pause != NULL) ||
            (play != NULL && stop == NULL && pause != NULL))
        {
            play->display = NPPLG_AV_CTRL_DISP_DISABLE;
            update_ctrl = play;
        }
        else if (play != NULL && stop != NULL && pause == NULL)
        {
            npplg_av_util_fill_control_field(play,
                                             play->x,
                                             play->y,
                                             play->width,
                                             play->height,
                                             (plugin_data->seekable ? NPPLG_AV_CTRL_DISP_ENABLE : NPPLG_AV_CTRL_DISP_DISABLE),
                                             NPPLG_AV_CTRL_TYPE_PAUSE,
                                             KAL_FALSE);
            update_ctrl = play;
        }
        else if (play != NULL && stop == NULL && pause == NULL)
        {
            npplg_av_util_fill_control_field(play,
                                             play->x,
                                             play->y,
                                             play->width,
                                             play->height,
                                             NPPLG_AV_CTRL_DISP_ENABLE,
                                             NPPLG_AV_CTRL_TYPE_STOP,
                                             KAL_FALSE);
            update_ctrl = play;
        }
    }
    else
    {
        /* Change "Pause" control or "Stop" control to "Play" control */
        if (play == NULL && pause != NULL && stop != NULL)
        {
            update_ctrl = pause;
        }
        else if (play == NULL && pause == NULL && stop != NULL)
        {
            update_ctrl = stop;
        }
        else if (play == NULL && pause != NULL && stop == NULL)
        {
            update_ctrl = pause;
        }
        else if (play != NULL)
        {
            update_ctrl = play;
        }

        if (update_ctrl != NULL)
        {
            npplg_av_util_fill_control_field(update_ctrl,
                                             update_ctrl->x,
                                             update_ctrl->y,
                                             update_ctrl->width,
                                             update_ctrl->height,
                                             NPPLG_AV_CTRL_DISP_ENABLE,
                                             NPPLG_AV_CTRL_TYPE_PLAY,
                                             KAL_FALSE);
        }
    }
    
    if (update_ctrl && draw)
    {
        npplg_av_util_invalidate_rect(plugin_data, update_ctrl);
    }
}



/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_disable_play_control
 * DESCRIPTION
 *  1. Disable "Play" control if there is "Stop" control or "Pause" control
 *  2. Change "Play" control to "Stop" control or "Pause" control
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  draw            [IN]        Should draw on the paint buffer or not
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_disable_play_control(npplg_av_instance_struct *plugin_data, kal_bool draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *play, *stop, *pause;
    npplg_av_obj_control_struct **ctrl_list;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    play = NULL;
    stop = NULL;
    pause = NULL;
    ctrl_list = plugin_data->control_list;
    
    for (i = 0; i < plugin_data->control_num; i++)
    {
        if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_PLAY)
        {
            play = ctrl_list[i];
        }
        else if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_STOP)
        {
            stop = ctrl_list[i];
        }
        else if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_PAUSE)
        {
            pause = ctrl_list[i];
        }
    }

    if (play != NULL)
    {
        if (stop != NULL || pause != NULL)
        {
            play->display = NPPLG_AV_CTRL_DISP_DISABLE;
            if (draw)
            {
                npplg_av_util_invalidate_rect(plugin_data, play);
            }
        }
        else
        {
            /* Change "Play" control to "Stop" control or "Pause" control */
            npplg_av_util_update_play_control(plugin_data, KAL_TRUE, draw);
        }
    }
    else if (stop != NULL && pause != NULL)
    {
        npplg_av_util_fill_control_field(pause,
                                         pause->x,
                                         pause->y,
                                         pause->width,
                                         pause->height,
                                         NPPLG_AV_CTRL_DISP_DISABLE,
                                         NPPLG_AV_CTRL_TYPE_PLAY,
                                         KAL_FALSE);

        if (draw)
        {
            npplg_av_util_invalidate_rect(plugin_data, pause);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_update_seek_control
 * DESCRIPTION
 *  This function is used to update "Rewind" and "Fast Forward" controls.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_update_seek_control(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *rewind, *fast_forward;
    npplg_av_obj_control_struct **ctrl_list;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rewind = NULL;
    fast_forward = NULL;
    ctrl_list = plugin_data->control_list;
    
    for (i = 0; i < plugin_data->control_num; i++)
    {
        if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_REWIND)
        {
            rewind = ctrl_list[i];
        }
        else if (ctrl_list[i]->type == NPPLG_AV_CTRL_TYPE_FAST_FORWARD)
        {
            fast_forward = ctrl_list[i];
        }
    }

    if (rewind != NULL)
    {
        rewind->display = (plugin_data->seekable ? NPPLG_AV_CTRL_DISP_ENABLE : NPPLG_AV_CTRL_DISP_DISABLE);
    }

    if (fast_forward != NULL)
    {
        fast_forward->display = (plugin_data->seekable ? NPPLG_AV_CTRL_DISP_ENABLE : NPPLG_AV_CTRL_DISP_DISABLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_calculate_play_time_for_seek
 * DESCRIPTION
 *  Calculate next playing time
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  forward         [IN]        TRUE: fast forward, FALSE: rewind
 *  next_play_time  [OUT]       Next playing time
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_calculate_play_time_for_seek(npplg_av_instance_struct *plugin_data,
                                                kal_bool forward,
                                                kal_int64 *next_play_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 seek_time, total_time, play_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get the total duration and the current playing time */
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        total_time = ((npplg_av_audio_data_struct*)plugin_data->obj_data)->total_time;
        play_time =  ((npplg_av_audio_data_struct*)plugin_data->obj_data)->play_time;
    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    else
    {
        total_time = ((npplg_av_video_data_struct*)plugin_data->obj_data)->total_time;
        play_time =  ((npplg_av_video_data_struct*)plugin_data->obj_data)->play_time;
    }
#else /* __MMI_VIDEO_PLAY_SUPPORT__ */
    else
    {
        ASSERT(0);
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    
#ifdef NPPLG_AV_CFG_SEEK_BY_RATIO

    seek_time = total_time * NPPLG_AV_CFG_SEEK_RATIO;

#else /* NPPLG_AV_CFG_SEEK_BY_RATIO */

    seek_time = NPPLG_AV_CFG_SEEK_TIME;

#endif /* NPPLG_AV_CFG_SEEK_BY_RATIO */

    if (forward)
    {
        play_time += seek_time;
        if (play_time > total_time)
        {
            play_time = total_time;
        }
    }
    else
    {
        if (play_time <= seek_time)
        {
            play_time = 0;
        }
        else
        {
            play_time -= seek_time;
        }
    }

    *next_play_time = play_time;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_update_play_time_for_seek
 * DESCRIPTION
 *  Update play time according to seek_repeat_num
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  forward         [IN]        TRUE: fast forward, FALSE: rewind
 *  next_play_time  [OUT]       Next playing time
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_update_play_time_for_seek(npplg_av_instance_struct *plugin_data,
                                             kal_bool forward,
                                             kal_int64 next_play_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *update_ctrl;
    kal_uint32 update_timer_interval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->seek_repeat_num == 0)
    {
        update_timer_interval = NPPLG_AV_FIRST_REPEAT_TIMER_INTERVAL;
    }
    else if (plugin_data->seek_repeat_num == 1 || plugin_data->seek_repeat_num == -1)
    {
        update_timer_interval = NPPLG_AV_SECOND_REPEAT_TIMER_INTERVAL;
    }
    else
    {
        update_timer_interval = NPPLG_AV_THIRD_REPEAT_TIMER_INTERVAL;
    }

    if (forward)
    {
        plugin_data->seek_repeat_num++;
    }
    else
    {
        plugin_data->seek_repeat_num--;
    }

    /* Update play time */
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        ((npplg_av_audio_data_struct*)plugin_data->obj_data)->play_time = (kal_uint32)next_play_time;
    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    else
    {
        ((npplg_av_video_data_struct*)plugin_data->obj_data)->play_time = next_play_time;
    }
#else /* __MMI_VIDEO_PLAY_SUPPORT__ */
    else
    {
        ASSERT(0);
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    
    npplg_av_main_start_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT, update_timer_interval);
    update_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_PROGRESS_BAR);
    if (update_ctrl != NULL)
    {
        npplg_av_util_invalidate_rect(plugin_data, update_ctrl);
    }

    update_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_TIME); 
    if (update_ctrl != NULL)
    {
        npplg_av_util_invalidate_rect(plugin_data, update_ctrl);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_seek
 * DESCRIPTION
 *  Seek audio or video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  forward         [IN]        TRUE: fast forward, FALSE: rewind
 *  next_play_time  [OUT]       Next playing time
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_seek(npplg_av_instance_struct *plugin_data, kal_bool forward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 next_play_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_util_calculate_play_time_for_seek(plugin_data, forward, &next_play_time);
    npplg_av_util_update_play_time_for_seek(plugin_data, forward, next_play_time);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_launch_media_player_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_LAUNCH_MEDIA_PLAYER_IND to MMI.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  src_module      [IN]        Source module
 *  player_type     [IN]        Which player plug-in should launch
 *  rtsp            [IN]        This request is RTSP:// or not
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_launch_media_player_ind(npplg_av_instance_struct *plugin_data,
                                                module_type src_module,
                                                kal_uint8 player_type,
                                                kal_bool rtsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_launch_media_player_ind_struct *launch_media_player_ind;
    kal_int32 str_len, url_len;
    kal_char *title_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether we can launch player first */
    if (npplg_av_util_can_launch_player(player_type) == KAL_FALSE)
    {
        npplg_av_main_display_popup(plugin_data, STR_GLOBAL_NOT_SUPPORTED);
        return;
    }

    if ((rtsp == KAL_TRUE && (plugin_data->url == NULL || strlen(plugin_data->url) == 0)) ||
        (rtsp == KAL_FALSE && plugin_data->file_path == NULL))
    {
        return;
    }

    if (rtsp == KAL_FALSE)
    {
        str_len = app_ucs2_wcslen(plugin_data->file_path);

        if (str_len >= NPPLG_MAX_FILEPATH_LEN)
        {
            MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_LAUNCH_MEDIA_PLAYER, NPPLG_AV_FAIL);
            return;
        }
    }
    else
    {
        str_len = strlen(plugin_data->url);

        if (str_len >= (NPPLG_MAX_FILEPATH_LEN * sizeof(kal_wchar)))
        {
            MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_LAUNCH_MEDIA_PLAYER, NPPLG_AV_FAIL);
            return;
        }
    }

    launch_media_player_ind = (npplg_av_launch_media_player_ind_struct*)
                                    construct_local_para(sizeof(npplg_av_launch_media_player_ind_struct), TD_CTRL | TD_RESET);

    memset(launch_media_player_ind->filepath, 0, sizeof(kal_wchar) * NPPLG_MAX_FILEPATH_LEN);
    memset(launch_media_player_ind->title, 0, sizeof(kal_wchar) * NPPLG_MAX_TITLE_LEN);
    if (rtsp)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        strncpy((char*)launch_media_player_ind->filepath, plugin_data->url, sizeof(kal_wchar) * NPPLG_MAX_FILEPATH_LEN - 1);
#else
        chset_convert(CHSET_UTF8, CHSET_UCS2, plugin_data->url, (char*)launch_media_player_ind->filepath, sizeof(kal_wchar) * NPPLG_MAX_FILEPATH_LEN);
#endif
    }
    else
    {
        app_ucs2_wcsncpy(launch_media_player_ind->filepath, plugin_data->file_path, str_len);
    }
    launch_media_player_ind->player_type = player_type;
    launch_media_player_ind->app_id = plugin_data->app_id;
    launch_media_player_ind->rtsp = rtsp;

    if (plugin_data->url == NULL || strlen(plugin_data->url) == 0)
    {
        if (str_len >= NPPLG_MAX_TITLE_LEN)
        {
            app_ucs2_wcsncpy(launch_media_player_ind->title, plugin_data->file_path, NPPLG_MAX_TITLE_LEN - 1);
        }
        else
        {
            app_ucs2_wcsncpy(launch_media_player_ind->title, plugin_data->file_path, str_len);
        }
    }
    else
    {
        url_len = strlen(plugin_data->url);
        title_ptr = plugin_data->url + (url_len - 1);

        if (url_len > 1 && *title_ptr != '/')
        {
            while (*title_ptr != '/' && url_len > 0)
            {
                title_ptr--;
                url_len--;
            }
            title_ptr++;
        }
        else
        {
            title_ptr = plugin_data->url;
        }
        
        chset_convert(CHSET_UTF8, CHSET_UCS2, title_ptr, (char*)launch_media_player_ind->title, sizeof(kal_wchar) * NPPLG_MAX_TITLE_LEN);
    }

    npplg_av_util_send_ilm(src_module, MOD_MMI, MSG_ID_NPPLG_AV_LAUNCH_MEDIA_PLAYER_IND, launch_media_player_ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_suspend_background_play_rsp
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP to plug-in task.
 * PARAMETERS
 *  dest_module     [IN]        Destination module
 *  app_id          [IN]        Application id
 *  result          [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_suspend_background_play_rsp(module_type dest_module, kal_uint8 app_id, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_suspend_background_play_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (npplg_av_suspend_background_play_rsp_struct*)
                construct_local_para(sizeof(npplg_av_suspend_background_play_rsp_struct), TD_CTRL | TD_RESET);

    rsp->result = result;
    rsp->app_id = app_id;

    npplg_av_util_send_ilm(MOD_MMI, dest_module, MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP, rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_resume_background_play_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_RESUME_BACKGROUND_PLAY_IND to MMI task.
 * PARAMETERS
 *  src_module      [IN]        Source module
 *  obj_type        [IN]        Object type
 *  resume_bgplay   [IN]        Resume background play or not
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_resume_background_play_ind(module_type src_module, kal_uint8 obj_type, kal_bool resume_bgplay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_resume_background_play_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_resume_background_play_ind_struct*)
                construct_local_para(sizeof(npplg_av_resume_background_play_ind_struct), TD_CTRL | TD_RESET);

    ind->obj_type = obj_type;
    ind->resume_bgplay = resume_bgplay;

    npplg_av_util_send_ilm(src_module, MOD_MMI, MSG_ID_NPPLG_AV_RESUME_BACKGROUND_PLAY_IND, ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_mmi_resume_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_MMI_RESUME_IND to engine task.
 * PARAMETERS
 *  dest_module     [IN]        Destination module
 *  instance_id     [IN]        Plug-in instance id
 *  app_id          [IN]        Application id
 *  state           [IN]        Resume state
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_mmi_resume_ind(module_type dest_module,
                                       kal_uint32 instance_id,
                                       kal_uint8 app_id,
                                       kal_uint8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_mmi_resume_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_mmi_resume_ind_struct*)
                construct_local_para(sizeof(npplg_av_mmi_resume_ind_struct), TD_CTRL | TD_RESET);

    ind->instance_id = instance_id;
    ind->app_id = app_id;
    ind->state = state;

    npplg_av_util_send_ilm(MOD_MMI, dest_module, MSG_ID_NPPLG_AV_MMI_RESUME_IND, ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_auto_play_audio_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_AUTO_PLAY_AUDIO_IND to engine task.
 * PARAMETERS
 *  dest_module     [IN]        Destination module
 *  app_id          [IN]        Application id
 *  notify_app      [IN]        Whether plug-in need to notify application if plug-in does not need to play audio
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_auto_play_audio_ind(module_type dest_module, kal_uint8 app_id, kal_bool notify_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_auto_play_audio_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_auto_play_audio_ind_struct*)
                construct_local_para(sizeof(npplg_av_auto_play_audio_ind_struct), TD_CTRL | TD_RESET);

    ind->app_id = app_id;
    ind->notify_app = notify_app;

    npplg_av_util_send_ilm(MOD_MMI, dest_module, MSG_ID_NPPLG_AV_AUTO_PLAY_AUDIO_IND, ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_reset_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_RESET_IND to engine task.
 * PARAMETERS
 *  dest_module     [IN]        Destination module
 *  instance_id     [IN]        Plug-in instance id
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_reset_ind(module_type dest_module, kal_uint32 instance_id, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_reset_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_reset_ind_struct*)
                construct_local_para(sizeof(npplg_av_reset_ind_struct), TD_CTRL | TD_RESET);

    ind->instance_id = instance_id;
    ind->app_id = app_id;
    
    npplg_av_util_send_ilm(MOD_MMI, dest_module, MSG_ID_NPPLG_AV_RESET_IND, ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_notify_mmi_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_NOTIFY_MMI_IND to MMI task.
 * PARAMETERS
 *  src_module      [IN]        Source module
 *  instance_id     [IN]        Plug-in instance id
 *  app_id          [IN]        Application id
 *  action          [IN]        Action plug-in should do when plug-in handle MSG_ID_NPPLG_AV_NOTIFY_MMI_IND in MMI task
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_notify_mmi_ind(module_type src_module, kal_uint32 instance_id, kal_uint8 app_id, kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_notify_mmi_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_notify_mmi_ind_struct*)
                construct_local_para(sizeof(npplg_av_notify_mmi_ind_struct), TD_CTRL | TD_RESET);

    ind->instance_id = instance_id;
    ind->app_id = app_id;
    ind->action = action;

    npplg_av_util_send_ilm(src_module, MOD_MMI, MSG_ID_NPPLG_AV_NOTIFY_MMI_IND, ind, NULL);
}


#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_create_vdo_layer_req
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_REQ to MMI task.
 * PARAMETERS
 *  src_module          [IN]        Source module
 *  instance_id         [IN]        Plug-in instance id
 *  app_id              [IN]        Application id
 *  rect                [IN]        Video position and size
 *  transparent_color   [IN]        Transparent color
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_create_vdo_layer_req(module_type src_module,
                                             kal_uint32 instance_id,
                                             kal_uint8 app_id,
                                             npplg_av_rect_struct *rect,
                                             gdi_color transparent_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_create_vdo_layer_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (npplg_av_create_vdo_layer_req_struct*)
                construct_local_para(sizeof(npplg_av_create_vdo_layer_req_struct), TD_CTRL | TD_RESET);

    req->src_mod = src_module;
    req->instance_id = instance_id;
    req->app_id = app_id;
    req->x = rect->x;
    req->y = rect->y;
    req->w = rect->w;
    req->h = rect->h;
    req->transparent_color = transparent_color;

    npplg_av_util_send_ilm(src_module, MOD_MMI, MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_create_vdo_layer_rsp
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_RSP to engine task.
 * PARAMETERS
 *  dest_module     [IN]        Destination module
 *  app_id          [IN]        Application id
 *  instance_id     [IN]        Plug-in instance id
 *  result          [IN]        Result
 *  layer_handle    [IN]        Video layer handle
 *  blt_layer_flag  [IN]        Blt layer flag
 *  hw_layer_flag   [IN]        HW layer flag
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_create_vdo_layer_rsp(module_type dest_module,
                                             kal_uint8 app_id,
                                             kal_uint32 instance_id,
                                             kal_int32 result,
                                             gdi_handle layer_handle,
                                             kal_uint32 blt_layer_flag,
                                             kal_uint32 hw_layer_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_create_vdo_layer_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (npplg_av_create_vdo_layer_rsp_struct*)
                construct_local_para(sizeof(npplg_av_create_vdo_layer_rsp_struct), TD_CTRL | TD_RESET);
    rsp->app_id = app_id;
    rsp->instance_id = instance_id;
    rsp->result = result;
    rsp->layer_handle = layer_handle;
    rsp->blt_layer_flag = blt_layer_flag;
    rsp->hw_layer_flag = hw_layer_flag;

    npplg_av_util_send_ilm(MOD_MMI, dest_module, MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_RSP, rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_free_vdo_layer_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_FREE_VDO_LAYER_IND to MMI task.
 * PARAMETERS
 *  src_module      [IN]        Source module
 *  app_id          [IN]        Application id
 *  instance_id     [IN]        Plug-in instance id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_free_vdo_layer_ind(module_type src_module, kal_uint8 app_id, kal_uint32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_free_vdo_layer_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_free_vdo_layer_ind_struct*)
                construct_local_para(sizeof(npplg_av_free_vdo_layer_ind_struct), TD_CTRL | TD_RESET);
    ind->app_id = app_id;
    ind->instance_id = instance_id;

    npplg_av_util_send_ilm(src_module, MOD_MMI, MSG_ID_NPPLG_AV_FREE_VDO_LAYER_IND, ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_update_vdo_layer_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_NPPLG_AV_UPDATE_VDO_LAYER_IND to MMI task.
 * PARAMETERS
 *  src_module          [IN]        Source module
 *  app_id              [IN]        Application id
 *  instance_id         [IN]        Plug-in instance id
 *  rect                [IN]        Video position and size
 *  transparent_color   [IN]      Transparent color
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_update_vdo_layer_ind(module_type src_module,
                                             kal_uint8 app_id,
                                             kal_uint32 instance_id,
                                             npplg_av_rect_struct *rect,
                                             gdi_color transparent_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_update_vdo_layer_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (npplg_av_update_vdo_layer_ind_struct*)
                construct_local_para(sizeof(npplg_av_update_vdo_layer_ind_struct), TD_CTRL | TD_RESET);
    ind->app_id = app_id;
    ind->instance_id = instance_id;
    ind->x = rect->x;
    ind->y = rect->y;
    ind->w = rect->w;
    ind->h = rect->h;
    ind->transparent_color = transparent_color;

    npplg_av_util_send_ilm(src_module, MOD_MMI, MSG_ID_NPPLG_AV_UPDATE_VDO_LAYER_IND, ind, NULL);
}
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_cvt_utf8_to_ucs2
 * DESCRIPTION
 *  Convert UTF-8 string to UCS-2
 * PARAMETERS
 *  utf8_str    [IN]        UTF-8 source string
 *  app_id      [IN]        Application id
 * RETURNS
 *  UCS-2 string
 *****************************************************************************/
kal_wchar *npplg_av_util_cvt_utf8_to_ucs2(const kal_char* utf8_str, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 str_len, dest_buf_len;
    kal_wchar *dest_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_chset_utf8_strlen((const kal_uint8*)utf8_str);
    dest_buf_len = (str_len + 1) * ENCODING_LENGTH;
    dest_buf = g_npplg_av_netscape_funcs[app_id].memalloc(dest_buf_len);
    if (dest_buf == NULL)
    {
        return NULL;
    }
    chset_convert(CHSET_UTF8, CHSET_UCS2, (char*)utf8_str, (char*)dest_buf, dest_buf_len);

    return dest_buf;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_cvt_ucs2_to_utf8
 * DESCRIPTION
 *  Convert UCS-2 string to UTF-8
 * PARAMETERS
 *  ucs2_str    [IN]        UCS-2 source string
 *  app_id      [IN]        Application id
 * RETURNS
 *  UTF-8 string
 *****************************************************************************/
kal_uint8 *npplg_av_util_cvt_ucs2_to_utf8(const kal_char* ucs2_str, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 dest_buf_len;
    kal_uint8 *dest_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_buf_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)ucs2_str) + 1;
    dest_buf = g_npplg_av_netscape_funcs[app_id].memalloc(dest_buf_len);
    if (dest_buf == NULL)
    {
        return NULL;
    }
    mmi_chset_ucs2_to_utf8_string(dest_buf, dest_buf_len, (kal_uint8*)ucs2_str);

    return dest_buf;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_display_mdi_error_popup
 * DESCRIPTION
 *  Utility function to show MDI error popup
 * PARAMETERS
 *  result      [IN]        MDI execution result
 *  plugin_data [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_display_mdi_error_popup(MDI_RESULT result, npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id;
    mmi_event_notify_enum event_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get the error string id from MDI and display error popup */
    string_id = mdi_util_get_mdi_error_info(result, &event_type);
    npplg_av_main_display_popup(plugin_data, string_id);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_init_mutex_lock
 * DESCRIPTION
 *  Create mutex
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_init_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_npplg_av_mutex = kal_create_mutex("AVPlugin");
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_mutex_lock
 * DESCRIPTION
 *  Lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_mutex_lock(kal_char *file, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*kal_wap_trace(MOD_MMI_MEDIA_APP, NPPLG_AV_TRC_GROUP, "[AVPLUGIN] LOCK line %d, file %s", line, file);*/
    
    if (kal_get_active_module_id() != g_npplg_av_mutex_tid)
    {
        kal_take_mutex(g_npplg_av_mutex);
        g_npplg_av_mutex_tid = kal_get_active_module_id();
    }
    ++g_npplg_av_mutex_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_mutex_unlock
 * DESCRIPTION
 *  Unlock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_mutex_unlock(kal_char *file, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*kal_wap_trace(MOD_MMI_MEDIA_APP, NPPLG_AV_TRC_GROUP, "[AVPLUGIN] UNLOCK line %d, file %s", line, file);*/
    
    ASSERT(g_npplg_av_mutex_tid == kal_get_active_module_id());

    --g_npplg_av_mutex_cnt;

    if (g_npplg_av_mutex_cnt == 0)
    {
        g_npplg_av_mutex_tid = MOD_NIL;
        kal_give_mutex(g_npplg_av_mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_util_send_ilm
 * DESCRIPTION
 *  This function is used to send message.
 * PARAMETERS
 *  src_mod         [IN]        Source module
 *  dest_mod        [IN]        Destination module
 *  msg_id          [IN]        Message id
 *  local_para_ptr  [IN]        Local parameter
 *  peer_buff_ptr   [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_util_send_ilm(module_type src_mod,
                            module_type dest_mod,
                            msg_type msg_id,
                            void *local_para_ptr,
                            void *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id = MMI_MMI_SAP;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (src_mod)
    {
        case MOD_MMI:
        {
            switch (dest_mod)
            {
#ifdef OPERA_V10_BROWSER
                case MOD_OPERA_CORE:
                {
                    sap_id = OPERA_MMI_SAP;
                    break;
                }
#endif

#ifdef __GADGET_SUPPORT__
                case MOD_GADGET:
                {
                    sap_id = MMI_GADGET_SAP;
                    break;
                }
#endif

                case MOD_MMI:
                default:
                    break;
            }
            break;
        }

#ifdef OPERA_V10_BROWSER
        case MOD_OPERA_CORE:
        {
            switch (dest_mod)
            {
                case MOD_MMI:
                {
                    sap_id = OPERA_MMI_SAP;
                    break;
                }
                
                default:
                    break;
            }
            break;
        }
#endif

#ifdef __GADGET_SUPPORT__
        case MOD_GADGET:
        {
            switch (dest_mod)
            {
                case MOD_MMI:
                {
                    sap_id = GADGET_MMI_SAP;
                    break;
                }

                default:
                    break;
            }
            break;
        }
#endif

        default:
            break;
    }
    
    ilm_ptr = allocate_ilm(src_mod);
    ilm_ptr->src_mod_id = src_mod;
    ilm_ptr->dest_mod_id = dest_mod;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*)local_para_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*)peer_buff_ptr;
    msg_send_ext_queue(ilm_ptr);
}

#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */
