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
 *   FMScheduleRecScreen.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  .............
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_FMSRSCREEN_C
#define _MMI_FMSRSCREEN_C

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "wgui_softkeys.h"
#include "gui_font_size.h"

#ifdef __MMI_TOUCH_SCREEN__
#endif 
#ifdef __MMI_SUBLCD__
#endif 

/* ... Add More MMI header */
#include "DateTimeGProt.h"
#include "FMScheduleRecDef.h"
#include "FMScheduleRecType.h"
#include "FMScheduleRecProt.h"
#include "FMScheduleRecScreen.h"

#ifdef __MMI_FMSR_SKIN_SYN_TO_THEME__
#include "CustThemesRes.h"
extern MMI_theme *current_MMI_theme;

#include "FMRadioResDef.h"
#endif /* __MMI_FMSR_SKIN_SYN_TO_THEME__ */ 

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    FMSR_PEN_NONE,
    FMSR_PEN_LSK,
    FMSR_PEN_RSK,
    FMSR_PEN_COUNT
} FMSR_PEN_STATE;

typedef enum
{
    FMSR_PEN_SK_UP,
    FMSR_PEN_SK_DOWN
} FMSR_SOFTKEY_STATE;

extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* 
 * Define
 */
#define FMSR_LSK_X_OFFSET  7
#define FMSR_LSK_Y_OFFSET  2
#define FMSR_RSK_X_OFFSET  6
#define FMSR_RSK_Y_OFFSET  3

/* 
 * Local Variable
 */

#ifdef __GDI_MEMORY_PROFILE_2__
GDI_HANDLE fmsr_osd_layer;  /* Draw on this layer */
GDI_HANDLE fmsr_skin_layer; /* Draw background layer */
BOOL is_fmsr_skin_layer_drawn = FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

fmsr_rec_screen_struct g_fmsr_screen;
extern const fmsr_skin_struct g_fmsr_skins[];   /* defined in "resource_fmschedulerec_skins.c" */

#ifdef __MMI_TOUCH_SCREEN__
static S32 fmsr_pen_event_on_object = FMSR_PEN_NONE;
static mmi_pen_point_struct LSK_points[4];
static mmi_pen_point_struct RSK_points[4];
static mmi_pen_polygon_area_struct LSK_area;
static mmi_pen_polygon_area_struct RSK_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern BOOL r2lMMIFlag; /* definedi n gui_inputs.c */

/* 
 * Global Function
 */
extern void set_on_idlescreen(S32 temo_on_idlescreen);
extern void set_main_LCD_time_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));

#ifdef __MMI_FMSR_SKIN_SYN_TO_THEME__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_init_for_theme
 * DESCRIPTION
 *  init colors when theme changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_init_for_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_screen.SK_text_color = *(current_MMI_theme->LSK_up_text_color);
    g_fmsr_screen.SK_text_border_color = *(current_MMI_theme->softkey_text_border_color);

    g_fmsr_screen.title_text_color = *(current_MMI_theme->title_text_color);

    g_fmsr_screen.status_text_color = *(current_MMI_theme->media_player_content_text_color);

    g_fmsr_screen.freq_text_color = *(current_MMI_theme->media_player_content_text_color);

    g_fmsr_screen.date_text_color = *(current_MMI_theme->media_player_content_text_color);

    g_fmsr_screen.time_text_color = *(current_MMI_theme->media_player_content_text_color);

}

#endif /* __MMI_FMSR_SKIN_SYN_TO_THEME__ */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_init_screen
 * DESCRIPTION
 *  Init the screen coordinate, strings, ... for FM record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_init_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const fmsr_skin_struct *skin_p = &g_fmsr_skins[0];  /* Currently only one skin */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FMSR_SKIN_SYN_TO_THEME__
    mmi_fmsr_init_for_theme();
#else /* __MMI_FMSR_SKIN_SYN_TO_THEME__ */ 
    g_fmsr_screen.SK_text_color = gui_color(skin_p->SK_text_color_r, skin_p->SK_text_color_g, skin_p->SK_text_color_b);
    g_fmsr_screen.SK_text_border_color = gui_color(skin_p->SK_text_border_color_r, skin_p->SK_text_border_color_g, skin_p->SK_text_border_color_b);
    g_fmsr_screen.title_text_color = gui_color(skin_p->title_text_color_r, skin_p->title_text_color_g, skin_p->title_text_color_b);
    g_fmsr_screen.status_text_color = gui_color(skin_p->status_text_color_r, skin_p->status_text_color_g, skin_p->status_text_color_b);
    g_fmsr_screen.freq_text_color = gui_color(skin_p->freq_text_color_r, skin_p->freq_text_color_g, skin_p->freq_text_color_b);
    g_fmsr_screen.date_text_color = gui_color(skin_p->date_text_color_r, skin_p->date_text_color_g, skin_p->date_text_color_b);
    g_fmsr_screen.time_text_color = gui_color(skin_p->time_text_color_r, skin_p->time_text_color_g, skin_p->time_text_color_b);
#endif /* __MMI_FMSR_SKIN_SYN_TO_THEME__ */ 

    g_fmsr_screen.bg_img = (PU8) GetImage(skin_p->bg_image_id);

    g_fmsr_screen.title.y = skin_p->title_text_y;

    g_fmsr_screen.status.y = skin_p->status_text_y;

    g_fmsr_screen.freq.y = skin_p->freq_text_y;

    g_fmsr_screen.duration.y = skin_p->duration_text_y;

    g_fmsr_screen.date.y = skin_p->date_text_y;

    g_fmsr_screen.time.y = skin_p->time_text_y;;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_show_main
 * DESCRIPTION
 *  Display the main FM record screen
 * PARAMETERS
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_show_main(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* UI_UNUSED_PARAMETER(history_buffer); */

    /* Always call get image function for ENFB project */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    mmi_fmsr_init_screen();
#endif 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&fmsr_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &fmsr_skin_layer);
    gdi_layer_set_blt_layer(fmsr_skin_layer, fmsr_osd_layer, 0, 0);

    gdi_push_and_set_alpha_blending_source_layer(fmsr_skin_layer);

    is_fmsr_skin_layer_drawn = FALSE;

#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    wgui_title_set_menu_shortcut_number(-1);
    SetupCategoryKeyHandlers();

    if (history_buffer == NULL)
    {
        g_fmsr_screen.LSK_text = get_string(left_softkey);
        g_fmsr_screen.RSK_text = get_string(right_softkey);
        g_fmsr_screen.title_text = get_string(STR_ID_FMSR_APP);
        g_fmsr_screen.status_text = get_string(STR_ID_FMSR_RECORDING);
    }

    /* associate functions */
    ExitCategoryFunction = mmi_fmsr_hide_main;
    RedrawCategoryFunction = mmi_fmsr_redraw_main_all;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    /* draw screen */
    set_on_idlescreen(1);
    mmi_fmsr_redraw_main_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_hide_main
 * DESCRIPTION
 *  Hide main FM record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_hide_main(void)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_to_base(fmsr_skin_layer, fmsr_osd_layer, 0, 0);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_free(fmsr_skin_layer);
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(fmsr_osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

#ifdef __MMI_TOUCH_SCREEN__
    fmsr_pen_event_on_object = FMSR_PEN_NONE;
#endif 

    /* associate functions */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    close_main_LCD_time_display();
    set_on_idlescreen(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_hide_status_icons
 * DESCRIPTION
 *  clear status bar background as the FMSR's background image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_hide_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();

    gui_set_clip(0, 0, UI_device_width - 1, MMI_status_bar_height - 1);
#ifdef __MMI_FMSR_SKIN_SYN_TO_THEME__
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->special_screen_bkg_filler);
#endif 
    gui_show_image(0, 0, (PU8) GetImage(IMG_ID_FMSR_BACKGROUND));

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_main_all
 * DESCRIPTION
 *  Redraw function for FM radio main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_main_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FMSR_SKIN_SYN_TO_THEME__
    mmi_fmsr_init_for_theme();
#endif 

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_push_text_clip();

    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifdef __GDI_MEMORY_PROFILE_2__
    if (!is_fmsr_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmsr_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
        /* main background */
    #ifdef __MMI_FMSR_SKIN_SYN_TO_THEME__
        gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->special_screen_bkg_filler);
    #endif /* __MMI_FMSR_SKIN_SYN_TO_THEME__ */ 
        gui_show_image(0, 0, (PU8) GetImage(IMG_ID_FMSR_BACKGROUND));
    #ifdef __GDI_MEMORY_PROFILE_2__
        is_fmsr_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gui_pop_text_clip();
    gui_pop_clip();

    /* wgui_status_icon_bar_register_hide_callback(0, mmi_fmsr_hide_status_icons); */
    wgui_set_wallpaper_on_bottom(TRUE);
#ifndef __MMI_MAINLCD_128X160__
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
#endif 

    mmi_fmsr_redraw_state();
    mmi_fmsr_redraw_frequency();
    mmi_fmsr_redraw_duration();
#ifdef __MMI_MAINLCD_320X480__
    mmi_fmsr_redraw_title();
#endif 
    mmi_fmsr_redraw_time(); /* Draw from bottom */
    mmi_fmsr_redraw_date();

    mmi_fmsr_redraw_LSK_up();
    mmi_fmsr_redraw_RSK_up();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_state
 * DESCRIPTION
 *  Redraw state text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 y1, y2;
    S32 str_w, str_h;
    static S32 height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_font(&MMI_medium_font);
    gui_measure_string(g_fmsr_screen.status_text, &str_w, &str_h);
    if (height < str_h)
    {
        height = str_h;
    }
    else
    {
        str_h = height;
    }

    y1 = g_fmsr_screen.status.y;
    y2 = y1 + str_h;

    gui_set_clip(0, y1, UI_device_width - 1, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(0, y1, UI_device_width - 1, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 

    gui_push_text_clip();
    gui_set_text_clip(0, y1, UI_device_width - 1, y2);

    gui_set_text_color(g_fmsr_screen.status_text_color);

    x = UI_device_width / 2 - str_w / 2;
    y = y1;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + str_w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }

    gui_print_text(g_fmsr_screen.status_text);

    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, y1, UI_device_width - 1, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_frequency
 * DESCRIPTION
 *  Redraw frequency text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_frequency(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 y1, y2;
    S32 str_w, str_h;
    UI_character_type str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((UI_string_type) str, "FM %d.%d", g_fmsr_cntx.rec.freqency / 10, g_fmsr_cntx.rec.freqency % 10);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_font(&MMI_medium_font);
    gui_measure_string(str, &str_w, &str_h);

    y1 = g_fmsr_screen.freq.y;
    y2 = y1 + str_h;

    gui_set_clip(0, y1, UI_device_width - 1, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(0, y1, UI_device_width - 1, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 

    gui_push_text_clip();
    gui_set_text_clip(0, y1, UI_device_width - 1, y2);

    gui_set_text_color(g_fmsr_screen.freq_text_color);

    x = UI_device_width / 2 - str_w / 2;
    y = y1;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + str_w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }

    gui_print_text(str);

    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, y1, UI_device_width - 1, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_init_duration
 * DESCRIPTION
 *  Init duration counter
 * PARAMETERS
 *  t               [OUT]         
 *  duration        [IN]          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_init_duration(UI_time *t, U16 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf1, buf2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->DayIndex = 0;
    buf1 = duration / 60;
    t->nSec = duration - buf1 * 60;
    buf2 = buf1 / 60;
    t->nMin = buf1 - buf2 * 60;
    t->nHour = (U8) buf2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_title
 * DESCRIPTION
 *  Redraw title on recording screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2, str_w, str_h, x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_font(&MMI_large_font);
    gui_measure_string(g_fmsr_screen.title_text, &str_w, &str_h);

    y1 = g_fmsr_screen.title.y;
    y2 = y1 + str_h;

    x = UI_device_width / 2 - str_w / 2;
    y = y1;

    gui_set_clip(0, y1, UI_device_width - 1, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(0, y1, UI_device_width - 1, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 

    gui_push_text_clip();
    gui_set_text_clip(0, y1, UI_device_width - 1, y2);

    gui_set_text_color(g_fmsr_screen.status_text_color);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + str_w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }

    gui_print_text(g_fmsr_screen.title_text);

    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, y1, UI_device_width - 1, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_duration_background
 * DESCRIPTION
 *  Redraw durtion background
 * PARAMETERS
 *  x1      [IN]        Start x postion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_duration_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = *current_MMI_theme->datetime_bar_background_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();
    gui_fill_rectangle(x1 - 2, y1 - 2, x2 + 2, y2 + 2, c);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_duration
 * DESCRIPTION
 *  Redraw durtion counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[] = L"44:44:44";  /* Use widest character to estimate font size */
    S32 str_w, str_h;
    S32 x, y;
    UI_time t;
    U32 duration = mmi_fmsr_get_duration_ticks();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_large_font);
    gui_measure_string(str, &str_w, &str_h);

    x = UI_device_width / 2 - str_w / 2;
    y = g_fmsr_screen.duration.y;

    mmi_fmsr_redraw_init_duration(&t, (U16) (duration * 0.004615 + 0.5));
    set_time_duration(&t, duration);

    if (g_fmsr_cntx.rec.is_start_duration)
    {
        set_main_LCD_time_duration_hide_function(mmi_fmrdo_redraw_duration_background);
        set_time_display(1, x, y, str_w + 1, str_h);
    }
    else
    {
        set_main_LCD_time_duration_hide_function(mmi_fmrdo_redraw_duration_background);
        set_time_display(0, x, y, str_w + 1, str_h);
    }

    time_display_duration();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_date
 * DESCRIPTION
 *  Redraw date text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 y1, y2;
    S32 str_w, str_h;
    UI_character_type str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((UI_string_type) str, "%4d/%2d/%2d", g_fmsr_cntx.rec.year, g_fmsr_cntx.rec.mon, g_fmsr_cntx.rec.day);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_font(&MMI_medium_font);
    gui_measure_string(str, &str_w, &str_h);

    y1 = g_fmsr_screen.date.y;
    y2 = y1 + str_h;

    gui_set_clip(0, y1, UI_device_width - 1, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(0, y1, UI_device_width - 1, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 

    gui_push_text_clip();
    gui_set_text_clip(0, y1, UI_device_width - 1, y2);

    gui_set_text_color(g_fmsr_screen.date_text_color);

    x = UI_device_width / 2 - str_w / 2;
    y = y1;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + str_w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }

    gui_print_text(str);

    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, y1, UI_device_width - 1, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_time
 * DESCRIPTION
 *  Redraw time text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 y1, y2;
    S32 str_w, str_h;
    UI_character_type str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        (UI_string_type) str,
        "%2d:%2d - %2d:%2d",
        g_fmsr_cntx.rec.hour1,
        g_fmsr_cntx.rec.min1,
        g_fmsr_cntx.rec.hour2,
        g_fmsr_cntx.rec.min2);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_font(&MMI_small_font);
    gui_measure_string(str, &str_w, &str_h);

    y1 = g_fmsr_screen.time.y;
    y2 = y1 + str_h;

    gui_set_clip(0, y1, UI_device_width - 1, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(0, y1, UI_device_width - 1, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 

    gui_push_text_clip();
    gui_set_text_clip(0, y1, UI_device_width - 1, y2);

    gui_set_text_color(g_fmsr_screen.time_text_color);

    x = UI_device_width / 2 - str_w / 2;
    y = y1;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + str_w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }

    gui_print_text(str);

    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, y1, UI_device_width - 1, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_LSK_up
 * DESCRIPTION
 *  Redraw LSK up icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_LSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    S32 dim_x1, dim_x2, dim_y1, dim_y2;
    S32 truncated_width;
    pBOOL is_truncated;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_color(g_fmsr_screen.SK_text_color);
    gui_set_text_border_color(g_fmsr_screen.SK_text_border_color);

    /* show LSK */
    gui_measure_string(g_fmsr_screen.LSK_text, &str_w, &str_h);
    is_truncated = wgui_softkey_get_offset(
                       g_fmsr_screen.LSK_text,
                       &x1, 
                       &y1,
                       &truncated_width,
                       MMI_LEFT_SOFTKEY,
                       mmi_frm_get_screen_rotate());
    wgui_softkey_get_position(MMI_LEFT_SOFTKEY, &dim_x1, &dim_y1);
    wgui_softkey_get_dimension(MMI_LEFT_SOFTKEY, &dim_x2, &dim_y2);
    dim_y2 += dim_y1;
    dim_x2 += dim_x1;
    gui_push_clip();
    gui_set_clip(dim_x1, dim_y1 - 1, UI_device_width / 2, dim_y2 - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(dim_x1, dim_y1, UI_device_width / 2, dim_y2 - 1, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(dim_x1, dim_y1 - 1, UI_device_width / 2, dim_y2 - 1);
    if (is_truncated)
    {
        gui_print_truncated_borderd_text(x1, y1, truncated_width, g_fmsr_screen.LSK_text);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
        gui_print_bordered_text(g_fmsr_screen.LSK_text);
    }
    gui_pop_text_clip();

#ifdef __MMI_TOUCH_SCREEN__
    if (r2lMMIFlag)
    {
        x2 = x1;
        x1 -= str_w;
    }
    else
    {
        x2 = str_w + x1;
    }
    y2 = str_h + y1;
    LSK_area.num = 4;
    LSK_area.points = (mmi_pen_point_struct*) LSK_points;
    LSK_points[0].x = LSK_points[3].x = x1;
    LSK_points[0].y = LSK_points[1].y = y1;
    LSK_points[1].x = LSK_points[2].x = x2 + 1;
    LSK_points[2].y = LSK_points[3].y = y2 + 1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(dim_x1, dim_y1 - 1, UI_device_width / 2, dim_y2 - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_RSK_up
 * DESCRIPTION
 *  Redraw RSK up icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_RSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    S32 truncated_width;
    pBOOL is_truncated;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_color(g_fmsr_screen.SK_text_color);
    gui_set_text_border_color(g_fmsr_screen.SK_text_border_color);

    /* show RSK */
    gui_measure_string(g_fmsr_screen.RSK_text, &str_w, &str_h);
    is_truncated = wgui_softkey_get_offset(
                       g_fmsr_screen.RSK_text, 
                       &x1, 
                       &y1, 
                       &truncated_width,
                       MMI_RIGHT_SOFTKEY,
                       mmi_frm_get_screen_rotate());
    if (r2lMMIFlag)
    {
        x2 = x1;
        x1 -= str_w;
    }
    else
    {
        x2 = str_w + x1;
    }
    y2 = str_h + y1;
    gui_push_clip();
    gui_set_clip(UI_device_width / 2, y1 - 1, x2 + 1, y2 + 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(UI_device_width / 2, y1 - 1, x2 + 1, y2 + 1, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (is_truncated)
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_borderd_text(x2, y1, truncated_width, g_fmsr_screen.RSK_text);
        }
        else
        {
            gui_print_truncated_borderd_text(x1, y1, truncated_width, g_fmsr_screen.RSK_text);
        }
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x2, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        gui_print_bordered_text(g_fmsr_screen.RSK_text);
    }
    gui_pop_text_clip();

#ifdef __MMI_TOUCH_SCREEN__
    RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = x1;
    RSK_points[0].y = RSK_points[1].y = y1;
    RSK_points[1].x = RSK_points[2].x = x2 + 1;
    RSK_points[2].y = RSK_points[3].y = y2 + 1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_device_width / 2, y1 - 1, x2 + 1, y2 + 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_LSK_down
 * DESCRIPTION
 *  Redraw LSK down icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_LSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    S32 truncated_width;
    pBOOL is_truncated;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_color(g_fmsr_screen.SK_text_color);
    gui_set_text_border_color(g_fmsr_screen.SK_text_border_color);

    /* show LSK */
    gui_measure_string(g_fmsr_screen.LSK_text, &str_w, &str_h);
    is_truncated = wgui_softkey_get_offset(
                       g_fmsr_screen.LSK_text, 
                       &x1, 
                       &y1,
                       &truncated_width,
                       MMI_LEFT_SOFTKEY,
                       mmi_frm_get_screen_rotate());
    x1 += 1;
    y1 += 1;
    if (r2lMMIFlag)
    {
        x2 = x1;
        x1 -= str_w;
    }
    else
    {
        x2 = str_w + x1;
    }
    y2 = str_h + y1;
    gui_push_clip();
    gui_set_clip(x1 - 2, y1 - 2, UI_device_width / 2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1 - 2, y1 - 2, UI_device_width / 2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (is_truncated)
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_borderd_text(x2, y1, truncated_width, g_fmsr_screen.LSK_text);
        }
        else
        {
            gui_print_truncated_borderd_text(x1, y1, truncated_width, g_fmsr_screen.LSK_text);
        }
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x2, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        gui_print_bordered_text(g_fmsr_screen.LSK_text);
    }
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1 - 2, y1 - 2, UI_device_width / 2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_RSK_down
 * DESCRIPTION
 *  Redraw RSK down icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_RSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    S32 truncated_width;
    pBOOL is_truncated;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_color(g_fmsr_screen.SK_text_color);
    gui_set_text_border_color(g_fmsr_screen.SK_text_border_color);

    /* show RSK */
    gui_measure_string(g_fmsr_screen.RSK_text, &str_w, &str_h);
    is_truncated = wgui_softkey_get_offset(
                       g_fmsr_screen.RSK_text, 
                       &x1, 
                       &y1,
                       &truncated_width,
                       MMI_RIGHT_SOFTKEY,
                       mmi_frm_get_screen_rotate());
    x1 += 1;
    y1 += 1;
    if (r2lMMIFlag)
    {
        x2 = x1;
        x1 -= str_w;
    }
    else
    {
        x2 = str_w + x1;
    }
    y2 = str_h + y1;
    gui_push_clip();
    gui_set_clip(UI_device_width / 2, y1 - 2, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(UI_device_width / 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, g_fmsr_screen.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (is_truncated)
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_borderd_text(x2, y1, truncated_width, g_fmsr_screen.RSK_text);
        }
        else
        {
            gui_print_truncated_borderd_text(x1, y1, truncated_width, g_fmsr_screen.RSK_text);
        }
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x2, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        gui_print_bordered_text(g_fmsr_screen.RSK_text);
    }
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_device_width / 2, y1 - 2, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_redraw_LSK
 * DESCRIPTION
 *  Change LSK string and redraw
 * PARAMETERS
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_redraw_LSK(U16 left_softkey, U16 left_softkey_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_screen.LSK_text = (UI_string_type) GetString(left_softkey);
    /* mmi_fmsr_redraw_LSK_down( ); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_change_pause_screen
 * DESCRIPTION
 *  Change record screen to pause screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_change_pause_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_screen.status_text = get_string(STR_GLOBAL_PAUSE);
    g_fmsr_cntx.rec.is_start_duration = FALSE;

    mmi_fmsr_redraw_state();
    mmi_fmsr_redraw_LSK(STR_GLOBAL_CONTINUE, IMG_GLOBAL_OK);
    mmi_fmsr_redraw_duration();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_restore_recording_screen
 * DESCRIPTION
 *  Restore from pause screen to record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_restore_recording_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_screen.status_text = get_string(STR_ID_FMSR_RECORDING);
    g_fmsr_cntx.rec.is_start_duration = TRUE;

    mmi_fmsr_redraw_state();
    mmi_fmsr_redraw_LSK(STR_GLOBAL_PAUSE, IMG_GLOBAL_OK);
    mmi_fmsr_redraw_duration();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    mmi_pen_point_struct point = {0, 0};
    mmi_pen_polygon_area_struct *area = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmsr_pen_event_on_object = FMSR_PEN_NONE;

    for (i = FMSR_PEN_LSK; i < FMSR_PEN_COUNT; i++)
    {
        switch (i)
        {
            case FMSR_PEN_LSK:
                area = (mmi_pen_polygon_area_struct*) & LSK_area;
                point = pos;
                break;
            case FMSR_PEN_RSK:
                area = (mmi_pen_polygon_area_struct*) & RSK_area;
                point = pos;
                break;
        }

        if (mmi_pen_check_inside_polygon(area, point))
        {
            fmsr_pen_event_on_object = i;
            break;
        }
    }

    switch (fmsr_pen_event_on_object)
    {
        case FMSR_PEN_LSK:
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            break;
        case FMSR_PEN_RSK:
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmsr_pen_event_on_object)
    {
        case FMSR_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            // mmi_fmsr_redraw_LSK_up();    /* Redraw after execute handler */
            break;

        case FMSR_PEN_RSK:

            mmi_fmsr_redraw_RSK_up();   /* Redraw before execute handler */
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmsr_pen_event_on_object)
    {
        case FMSR_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_fmsr_redraw_LSK_down();
            }
            else
            {
                mmi_fmsr_redraw_LSK_up();
            }
            break;
        case FMSR_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                mmi_fmsr_redraw_RSK_down();
            }
            else
            {
                mmi_fmsr_redraw_RSK_up();
            }
            break;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_SUBLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_entry_sublcd_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory301Screen((PU8) GetString(STR_ID_FMSR_APP), 0, NULL);
    SetSubLCDExitHandler(mmi_fmsr_exit_sublcd_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_exit_sublcd_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_entry_sublcd_msg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_entry_sublcd_msg_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory301Screen((PU8) GetString(STR_ID_FMSR_RECORD_FINISH_1 + g_fmsr_cntx.rec.index), 0, NULL);
    SetSubLCDExitHandler(mmi_fmsr_exit_sublcd_msg_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_exit_sublcd_msg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_exit_sublcd_msg_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_SUBLCD__ */ 

#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ 
#endif /* _MMI_FMSRSCREEN_C */ 

