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
 * SndrecDraw.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#if defined(__MMI_SOUND_RECORDER__)
#ifdef __MMI_SNDREC_SKIN__
#include "gdi_include.h"
#include "Wgui_include.h"
#include "Wgui.h"
#include "gui_font_size.h"

#include "SndrecProt.h"
#include "SndrecDef.h"

#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "gui.h"
#include "gui_typedef.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "gui_config.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "gdi_const.h"
#include "GlobalResDef.h"
#include "ScreenRotationGprot.h"
#include "gui_switch.h"
#include "mmi_rp_app_soundrecorder_def.h"
#include "gui_themes.h"
#include "gui_windows.h"
#include "wgui_touch_screen.h"
#include "gui_touch_feedback.h"
#include "Unicodexdcl.h"
#include "DebugInitDef_Int.h"
#include "Gui_touch_feedback.h"
#include "mmi_media_app_trc.h"
#include "wgui_softkeys.h"

/* For DCM */
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "mmi_ap_dcm_config.h"
#endif

#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
#define __MMI_SNDREC_SUPPORT_STATUS_BAR__
#endif /* (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */


/****************************************************************************
* function declaration
*****************************************************************************/
#ifdef  __MMI_SNDREC_SKIN__ 
static void mmi_sndrec_sk_init_main_image(void);
static void mmi_sndrec_redraw_main_all(void);
static void mmi_sndrec_hide_main_skins(void);
#ifndef __MMI_FTE_SUPPORT__
static void mmi_sndrec_redraw_title(void);
#endif

void mmi_sndrec_update_time_text(void);
static void mmi_sndrec_redraw_time_text(UI_string_type string, MMI_BOOL isNeedBlt);
static void mmi_sndrec_redraw_filename_background(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_sndrec_scroll_filename_handler(void);
#ifndef __MMI_FTE_SUPPORT__
static void mmi_sndrec_scroll_state_handler(void);
#endif
static void mmi_sndrec_get_time_string(UI_string_type string);
void mmi_sndrec_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_sndrec_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_sndrec_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_SNDREC_SKIN__ */


/****************************************************************************
* global variable
*****************************************************************************/
#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif

#ifdef __MMI_FTE_SUPPORT__
BOOL is_sndrec_skin_layer_drawn = FALSE;
#endif/*__MMI_FTE_SUPPORT__*/

static mmi_sndrec_main_draw_struct g_sndrec_main_draw;
static mmi_sndrec_screen_layer_struct g_sndrec_layer;

#ifdef __MMI_TOUCH_SCREEN__
static mmi_pen_point_struct mmi_sndrec_lsk_points[4];
static mmi_pen_point_struct mmi_sndrec_rsk_points[4];
static mmi_pen_polygon_area_struct mmi_sndrec_lsk_area;
static mmi_pen_polygon_area_struct mmi_sndrec_rsk_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 
extern MMI_BOOL g_sndrec_wait_next_prev;
extern mmi_sndrec_cntx g_sndrec_cntx;
extern const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[];

extern BOOL r2lMMIFlag;

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
extern MMI_BOOL mmi_sndrec_is_play_flag;
extern MMI_BOOL mmi_sndrec_is_play_goback;
#endif


S32 mmi_sndrec_mslt_skin_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_sndrec_draw_skin_struct *skin_p = g_sndrec_record_skins;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return skin_p->title_w;
}

#ifndef __MMI_FTE_SUPPORT__
S32 mmi_sndrec_mslt_skin_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_sndrec_draw_skin_struct *skin_p = g_sndrec_record_skins;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return skin_p->state_w;

}
#endif


#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif

#ifdef __MMI_FTE_SUPPORT__
static MMI_BOOL g_sndrec_enable_touch_feedback = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_touch_feedback_disable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_touch_feedback_disable(void)
{
    g_sndrec_enable_touch_feedback = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_touch_feedback_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_touch_feedback_enable(void)
{
    g_sndrec_enable_touch_feedback = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_query_is_touch_feedback_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Void             
 * RETURNS
 *  MMI_BOOL [out] 
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_query_is_touch_feedback_enable(void)
{
    return g_sndrec_enable_touch_feedback;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_blt_screen
 * DESCRIPTION
 *  blt full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_show_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  titleid         [IN]        
 *  leftkeyid       [IN]        
 *  rightkeyid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_show_main_screen(U16 titleid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&g_sndrec_layer.osdlayer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &g_sndrec_layer.skinlayer);
    gdi_layer_set_blt_layer(g_sndrec_layer.skinlayer, g_sndrec_layer.osdlayer, 0, 0);
#ifdef __MMI_FTE_SUPPORT__
	is_sndrec_skin_layer_drawn = FALSE;
#endif/*__MMI_FTE_SUPPORT__*/
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    clear_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    g_sndrec_main_draw.title.text = (UI_string_type) GetString(titleid);

    ExitCategoryFunction = mmi_sndrec_hide_main_skins;
    RedrawCategoryFunction = mmi_sndrec_redraw_main_all;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    gdi_get_alpha_blending_source_layer(&g_sndrec_layer.oldbldlayer);
    gdi_set_alpha_blending_source_layer(g_sndrec_layer.skinlayer);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SNDREC_DRAW_LAYER, 
                     g_sndrec_layer.oldbldlayer, g_sndrec_layer.skinlayer);
    mmi_sndrec_sk_init_main_image();
    mmi_sndrec_redraw_main_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_sk_init_main_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_sk_init_main_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    const mmi_sndrec_draw_skin_struct *skin_p = g_sndrec_record_skins;
    mmi_sndrec_main_draw_struct *draw_p = &g_sndrec_main_draw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  #ifdef __MMI_FTE_SUPPORT__
  /* FTE Changes
       - Remove Background image, change to use submenu’s background(Apply in all FTE Project)
       - Remove images of disabled status, change to 50% transparency(Apply in all FTE Project)
       - Remove unused images, new design no need(Apply in all FTE Project)
   */
    draw_p->title_color = gui_color(skin_p->title_text_color_r, skin_p->title_text_color_g, skin_p->title_text_color_b);
    draw_p->title_border_color = gui_color(
                                    skin_p->title_text_border_color_r,
                                    skin_p->title_text_border_color_g,
                                    skin_p->title_text_border_color_b);

    /* LSK */
    draw_p->lsk.up_img = (U8*) GetImage(skin_p->lsk_img_id);
	#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	draw_p->lsk.down_img = (U8*) GetImage(skin_p->lsk_img_down_id);
	#endif
    //draw_p->lsk.dis_img = (U8*) GetImage(skin_p->lsk_dis_img_id);

    draw_p->lsk.x = skin_p->lsk_img_x; 
    draw_p->lsk.y = skin_p->lsk_img_y;
    gui_measure_image(draw_p->lsk.up_img, &w, &h);
    draw_p->lsk.w = (S16)w;
    draw_p->lsk.h = (S16)h;

    /* RSK */
    draw_p->rsk.up_img = (U8*) GetImage(skin_p->rsk_img_id);
	#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	draw_p->rsk.down_img = (U8*) GetImage(skin_p->rsk_img_down_id);
	#endif
    //draw_p->rsk.dis_img = (U8*) GetImage(skin_p->rsk_dis_img_id);
    draw_p->rsk.x =  skin_p->rsk_img_x;
    draw_p->rsk.y =  skin_p->rsk_img_y;
    gui_measure_image(draw_p->rsk.up_img, &w, &h);
    draw_p->rsk.w = (S16)w;
    draw_p->rsk.h = (S16)h;

    draw_p->filename_color = gui_color(skin_p->name_text_color_r, skin_p->name_text_color_g, skin_p->name_text_color_b);
    draw_p->filename_border_color = gui_color(skin_p->name_text_border_color_r, skin_p->name_text_border_color_g, skin_p->name_text_border_color_b);
 
    draw_p->time_color = gui_color(skin_p->time_text_color_r, skin_p->time_text_color_g, skin_p->time_text_color_b);
    draw_p->time_border_color = gui_color(skin_p->time_text_border_color_r, skin_p->time_text_border_color_g, skin_p->time_text_border_color_b);

    /* Background Image */ 
    //draw_p->bg_img = (U8*) GetImage(skin_p->bg_img_id);

    /* REC Button */
    draw_p->record.up_img = (U8*) GetImage(skin_p->record_btn_up_id);
    //draw_p->record.disable_img = (U8*) GetImage(skin_p->record_btn_disable_id);
    draw_p->record.x = skin_p->record_btn_x;
    draw_p->record.y = skin_p->record_btn_y;
    gui_measure_image(draw_p->record.up_img, &w, &h);
    draw_p->record.w = (S16) w;
    draw_p->record.h = (S16) h;

 #ifndef __MMI_OP02_LEMEI__  /* start/stop in lemei*/
    draw_p->rec_pause.up_img = (U8*) GetImage(skin_p->record_pause_btn_up_id);
 #else
    if(g_sndrec_cntx.record.isEntryFromOther == MMI_TRUE && !mmi_sndrec_query_is_record_pause_enabled())
    {
        draw_p->rec_pause.up_img = (U8*) GetImage(skin_p->stop_btn_up_id);
    }
    else 
    {
        draw_p->rec_pause.up_img = (U8*) GetImage(skin_p->record_pause_btn_up_id);
    }
 #endif 

    /* REC PAUSE Button */
    draw_p->rec_pause.x = skin_p->record_btn_x;
    draw_p->rec_pause.y = skin_p->record_btn_y;
    gui_measure_image(draw_p->rec_pause.up_img, &w, &h);
    draw_p->rec_pause.w = (S16) w;
    draw_p->rec_pause.h = (S16) h;

    /* PLAY Button */
    draw_p->play.up_img = (U8*) GetImage(skin_p->play_btn_up_id);
    //draw_p->play.disable_img = (U8*) GetImage(skin_p->play_btn_diable_id);
    draw_p->play.x = skin_p->play_btn_x;
    draw_p->play.y = skin_p->play_btn_y;
    gui_measure_image(draw_p->play.up_img, &w, &h);
    draw_p->play.w = (S16) w;
    draw_p->play.h = (S16) h;

    /* PLAY PAUSE Button */
    draw_p->play_pause.up_img = (U8*) GetImage(skin_p->play_pause_btn_up_id);
    draw_p->play_pause.x = skin_p->play_btn_x;
    draw_p->play_pause.y = skin_p->play_btn_y;
    gui_measure_image(draw_p->play_pause.up_img, &w, &h);
    draw_p->play_pause.w = w;
    draw_p->play_pause.h = h;

    /* PREV Button */
    draw_p->previous.up_img = (U8*) GetImage(skin_p->prev_btn_up_id);
    //draw_p->previous.disable_img = (U8*) GetImage(skin_p->prev_btn_disable_id);
    draw_p->previous.x = skin_p->prev_btn_x;
    draw_p->previous.y = skin_p->prev_btn_y;
    gui_measure_image(draw_p->previous.up_img, &w, &h);
    draw_p->previous.w = w;
    draw_p->previous.h = h;

    /* NEXT Button */
    draw_p->next.up_img = (U8*) GetImage(skin_p->next_btn_up_id);
    //draw_p->next.disable_img = (U8*) GetImage(skin_p->next_btn_disable_id);
    draw_p->next.x = skin_p->next_btn_x;
    draw_p->next.y = skin_p->next_btn_y;
    gui_measure_image(draw_p->next.up_img, &w, &h);
    draw_p->next.w = w;
    draw_p->next.h = h;

    /* LIST Button */
	#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    draw_p->list.up_img = (U8*) GetImage(skin_p->list_btn_up_id);
    //draw_p->list.disable_img = (U8*) GetImage(skin_p->list_btn_disable_id);
    draw_p->list.x = skin_p->list_btn_x;
    draw_p->list.y = skin_p->list_btn_y;
    gui_measure_image(draw_p->list.up_img, &w, &h);
    draw_p->list.w = w;
    draw_p->list.h = h;
    #endif

    /* STOP Button */
    draw_p->stop.up_img = (U8*) GetImage(skin_p->stop_btn_up_id);
    //draw_p->stop.disable_img = (U8*) GetImage(skin_p->stop_btn_disable_id);
    draw_p->stop.x = skin_p->stop_btn_x;
    draw_p->stop.y = skin_p->stop_btn_y;
    gui_measure_image(draw_p->stop.up_img, &w, &h);
    draw_p->stop.w = w;
    draw_p->stop.h = h;

    /* REC Sign */
    draw_p->rec_icon.up_img = (U8*) GetImage(skin_p->rec_icon_id);
    //draw_p->rec_icon.disable_img = (U8*) GetImage(skin_p->rec_pause_icon_id);
    draw_p->rec_icon.x = skin_p->rec_icon_x;
    draw_p->rec_icon.y = skin_p->rec_icon_y;
    gui_measure_image(draw_p->rec_icon.up_img, &w, &h);
    draw_p->rec_icon.w = w;
    draw_p->rec_icon.h = h;

    /* REC PAUSE Sign */
    draw_p->rec_pause_icon.up_img = (U8*) GetImage(skin_p->rec_pause_icon_id);
    draw_p->rec_pause_icon.x = skin_p->rec_icon_x;
    draw_p->rec_pause_icon.y = skin_p->rec_icon_y;
    gui_measure_image(draw_p->rec_pause_icon.up_img, &w, &h);
    draw_p->rec_pause_icon.w = w;
    draw_p->rec_pause_icon.h = h;

    /* LINE */
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    draw_p->line_x = skin_p->line_img_x;
    draw_p->line_y = skin_p->line_img_y;
    draw_p->line_w = skin_p->line_img_w;
    draw_p->line_h = skin_p->line_img_h;
    draw_p->line_img = (U8*) GetImage(skin_p->line_img_id);
#else    
#ifdef __MMI_FTE_SUPPORT_SLIM__
    draw_p->line.up_img = (U8*) GetImage(skin_p->line_img_id);
    draw_p->line.x = skin_p->line_img_x;
    draw_p->line.y = skin_p->line_img_y;
#endif 
#endif

    /* CROSS*/
/*#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#ifdef __MMI_FTE_SUPPORT_SLIM__
    draw_p->cross.up_img = (U8*)GetImage(skin_p->cross_img_id);
    draw_p->cross.x = skin_p->cross_img_x;
    draw_p->cross.y = skin_p->cross_img_y;
#endif
#endif */

    draw_p->highlight_img.up_img = (U8*) GetImage(skin_p->highlight_img_id);
    gui_measure_image(draw_p->highlight_img.up_img, &w, &h);
    draw_p->highlight_img.w = w;
    draw_p->highlight_img.h = h;

    draw_p->animal.img = (U8*) GetImage(skin_p->animal_img_id);
    draw_p->animal.x = skin_p->animal_img_x;
    draw_p->animal.y = skin_p->animal_img_y;

    draw_p->title.x = skin_p->title_x;
    draw_p->title.y = skin_p->title_y;
    draw_p->title.w = skin_p->title_w;
    draw_p->title.h = skin_p->title_h;

    draw_p->filename.x = skin_p->filename_x;
    draw_p->filename.y = skin_p->filename_y;
    draw_p->filename.w = skin_p->filename_w;
    draw_p->filename.h = skin_p->filename_h;

    draw_p->time.x = skin_p->time_x;
    draw_p->time.y = skin_p->time_y;
    draw_p->time.w = skin_p->time_w;
    draw_p->time.h = skin_p->time_h;

#if 0 // def __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
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
  
#else/*__MMI_FTE_SUPPORT__*/

    draw_p->title_color = gui_color(skin_p->title_text_color_r, skin_p->title_text_color_g, skin_p->title_text_color_b);
    draw_p->title_border_color = gui_color(
                                    skin_p->title_text_border_color_r,
                                    skin_p->title_text_border_color_g,
                                    skin_p->title_text_border_color_b);
    draw_p->lsk.color = gui_color(skin_p->lsk_text_color_r, skin_p->lsk_text_color_g, skin_p->lsk_text_color_b);
    draw_p->lsk.border_color = gui_color(skin_p->lsk_text_border_color_r, skin_p->lsk_text_border_color_g, skin_p->lsk_text_border_color_b);
    draw_p->rsk.color = gui_color(skin_p->rsk_text_color_r, skin_p->rsk_text_color_g, skin_p->rsk_text_color_b);
    draw_p->rsk.border_color = gui_color(skin_p->rsk_text_border_color_r, skin_p->rsk_text_border_color_g, skin_p->rsk_text_border_color_b);
    draw_p->filename_color = gui_color(skin_p->name_text_color_r, skin_p->name_text_color_g, skin_p->name_text_color_b);
    draw_p->filename_border_color = gui_color(skin_p->name_text_border_color_r, skin_p->name_text_border_color_g, skin_p->name_text_border_color_b);
    draw_p->state_color = gui_color(skin_p->state_text_color_r, skin_p->state_text_color_g, skin_p->state_text_color_b);
    draw_p->state_border_color = gui_color(
                                    skin_p->state_text_border_color_r,
                                    skin_p->state_text_border_color_g,
                                    skin_p->state_text_border_color_b);
    draw_p->time_color = gui_color(skin_p->time_text_color_r, skin_p->time_text_color_g, skin_p->time_text_color_b);
    draw_p->time_border_color = gui_color(skin_p->time_text_border_color_r, skin_p->time_text_border_color_g, skin_p->time_text_border_color_b);
    draw_p->bg_img = (U8*) GetImage(skin_p->bg_img_id);
    draw_p->record.up_img = (U8*) GetImage(skin_p->record_btn_up_id);
    draw_p->record.down_img = (U8*) GetImage(skin_p->record_btn_down_id);
    draw_p->record.disable_img = (U8*) GetImage(skin_p->record_btn_disable_id);
    draw_p->record.x = skin_p->record_btn_x;
    draw_p->record.y = skin_p->record_btn_y;
    gui_measure_image(draw_p->record.up_img, &w, &h);
    draw_p->record.w = (S16) w;
    draw_p->record.h = (S16) h;

#ifndef __MMI_OP02_LEMEI__  /* start/stop in lemei*/
    draw_p->rec_pause.up_img = (U8*) GetImage(skin_p->record_pause_btn_up_id);
    draw_p->rec_pause.down_img = (U8*) GetImage(skin_p->record_pause_btn_down_id);
 #else
    if(g_sndrec_cntx.record.isEntryFromOther == MMI_TRUE && !mmi_sndrec_query_is_record_pause_enabled())
    {
        draw_p->rec_pause.up_img = (U8*) GetImage(skin_p->stop_btn_up_id);
        draw_p->rec_pause.down_img = (U8*) GetImage(skin_p->stop_btn_down_id);    
    }
    else 
    {
    draw_p->rec_pause.up_img = (U8*) GetImage(skin_p->record_pause_btn_up_id);
    draw_p->rec_pause.down_img = (U8*) GetImage(skin_p->record_pause_btn_down_id);
    }
#endif
    draw_p->rec_pause.x = skin_p->record_btn_x;
    draw_p->rec_pause.y = skin_p->record_btn_y;
    gui_measure_image(draw_p->rec_pause.up_img, &w, &h);
    draw_p->rec_pause.w = (S16) w;
    draw_p->rec_pause.h = (S16) h;

    draw_p->play.up_img = (U8*) GetImage(skin_p->play_btn_up_id);
    draw_p->play.down_img = (U8*) GetImage(skin_p->play_btn_down_id);
    draw_p->play.disable_img = (U8*) GetImage(skin_p->play_btn_diable_id);
    draw_p->play.x = skin_p->play_btn_x;
    draw_p->play.y = skin_p->play_btn_y;
    gui_measure_image(draw_p->play.up_img, &w, &h);
    draw_p->play.w = (S16) w;
    draw_p->play.h = (S16) h;

    draw_p->play_pause.up_img = (U8*) GetImage(skin_p->play_pause_btn_up_id);
    draw_p->play_pause.down_img = (U8*) GetImage(skin_p->play_pause_btn_down_id);
    draw_p->play_pause.x = skin_p->play_btn_x;
    draw_p->play_pause.y = skin_p->play_btn_y;
    gui_measure_image(draw_p->play_pause.up_img, &w, &h);
    draw_p->play_pause.w = w;
    draw_p->play_pause.h = h;

    draw_p->previous.up_img = (U8*) GetImage(skin_p->prev_btn_up_id);
    draw_p->previous.down_img = (U8*) GetImage(skin_p->prev_btn_down_id);
    draw_p->previous.disable_img = (U8*) GetImage(skin_p->prev_btn_disable_id);
    draw_p->previous.x = skin_p->prev_btn_x;
    draw_p->previous.y = skin_p->prev_btn_y;
    gui_measure_image(draw_p->previous.up_img, &w, &h);
    draw_p->previous.w = w;
    draw_p->previous.h = h;

    draw_p->next.up_img = (U8*) GetImage(skin_p->next_btn_up_id);
    draw_p->next.down_img = (U8*) GetImage(skin_p->next_btn_down_id);
    draw_p->next.disable_img = (U8*) GetImage(skin_p->next_btn_disable_id);
    draw_p->next.x = skin_p->next_btn_x;
    draw_p->next.y = skin_p->next_btn_y;
    gui_measure_image(draw_p->next.up_img, &w, &h);
    draw_p->next.w = w;
    draw_p->next.h = h;

    draw_p->list.up_img = (U8*) GetImage(skin_p->list_btn_up_id);
    draw_p->list.down_img = (U8*) GetImage(skin_p->list_btn_down_id);
    draw_p->list.disable_img = (U8*) GetImage(skin_p->list_btn_disable_id);
    draw_p->list.x = skin_p->list_btn_x;
    draw_p->list.y = skin_p->list_btn_y;
    gui_measure_image(draw_p->list.up_img, &w, &h);
    draw_p->list.w = w;
    draw_p->list.h = h;

    draw_p->animal.img = (U8*) GetImage(skin_p->animal_img_id);
    draw_p->animal.x = skin_p->animal_img_x;
    draw_p->animal.y = skin_p->animal_img_y;

    draw_p->title.x = skin_p->title_x;
    draw_p->title.y = skin_p->title_y;
    draw_p->title.w = skin_p->title_w;
    draw_p->title.h = skin_p->title_h;

    draw_p->filename.x = skin_p->filename_x;
    draw_p->filename.y = skin_p->filename_y;
    draw_p->filename.w = skin_p->filename_w;
    draw_p->filename.h = skin_p->filename_h;

    draw_p->state.x = skin_p->state_x;
    draw_p->state.y = skin_p->state_y;
    draw_p->state.w = skin_p->state_w;
    draw_p->state.h = skin_p->state_h;

    draw_p->time.x = skin_p->time_x;
    draw_p->time.y = skin_p->time_y;
    draw_p->time.w = skin_p->time_w;
    draw_p->time.h = skin_p->time_h;
#endif/*__MMI_FTE_SUPPORT__*/

}

#ifndef __MMI_FTE_SUPPORT__
#ifdef __MMI_SNDREC_SUPPORT_STATUS_BAR__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_redraw_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gdi_layer_push_clip();

    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    gdi_layer_set_clip(cx1, cy1, cx2, cy2);
    gdi_draw_solid_rect(cx1, cy1, cx2, cy2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_redraw_main_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FTE_SUPPORT__
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif
    gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    gdi_layer_lock_frame_buffer();
    if (!is_sndrec_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);

    /* Remove Background image, change to use submenu background(Apply in all FTE Project) */
    #if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
        //gdi_image_draw_resized(0,0,UI_device_width, UI_device_height, g_sndrec_main_draw.bg_img);
        //gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
        //gui_show_image(g_sndrec_main_draw.cross.x, g_sndrec_main_draw.cross.y, g_sndrec_main_draw.cross.up_img);
        gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
            current_MMI_theme->sub_menu_bkg_filler);
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        gdi_image_draw_resized(g_sndrec_main_draw.line_x, g_sndrec_main_draw.line_y, g_sndrec_main_draw.line_w, g_sndrec_main_draw.line_h, g_sndrec_main_draw.line_img);
    #else
        gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
    #endif
    #elif defined(__MMI_FTE_SUPPORT_SLIM__)
        //gdi_draw_solid_rect(0, 0, UI_device_width, UI_device_height, GDI_COLOR_BLACK);
        //gdi_image_draw_resized(0, g_sndrec_main_draw.lsk.y, UI_device_width, UI_device_height - g_sndrec_main_draw.lsk.y, g_sndrec_main_draw.bg_img);
        //gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
        gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
            current_MMI_theme->sub_menu_bkg_filler);
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
        gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
    #else
        //gui_show_image(0, 0, g_sndrec_main_draw.bg_img);
        gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
            current_MMI_theme->sub_menu_bkg_filler);
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    #endif

        /* show components */

        mmi_sndrec_redraw_main_lsk();
        mmi_sndrec_redraw_main_rsk();
    #if defined(__MMI_OP02_LEMEI__)
        if(mmi_sndrec_query_is_record_pause_enabled() == MMI_TRUE)
    #endif
        {
            mmi_sndrec_redraw_play_btn(MMI_FALSE);
            mmi_sndrec_redraw_prev_btn(MMI_FALSE);
            mmi_sndrec_redraw_next_btn(MMI_FALSE);
     #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_sndrec_redraw_list_btn(MMI_FALSE);
     #endif
            mmi_sndrec_redraw_rec_icon();
        }
        mmi_sndrec_redraw_record_btn(MMI_FALSE);
        mmi_sndrec_redraw_stop_btn(MMI_FALSE);

        if (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state || 
            MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state ||
            MMI_SNDREC_PREVIEW_STATE == g_sndrec_cntx.record.state)
        {
            mmi_sndrec_redraw_skins_animal_img(MMI_TRUE);
        }
        else
        {
            mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
        }
            /* tuner scale background */
        is_sndrec_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }
    
    gdi_layer_pop_clip();    
    mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
    
    if (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state || 
        MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state ||
        MMI_SNDREC_PREVIEW_STATE == g_sndrec_cntx.record.state)
    {
        mmi_sndrec_show_time_text_without_blt(MMI_TRUE);
    }
    else
    {
        mmi_sndrec_show_time_text_without_blt(MMI_FALSE);
    }
    
    gdi_layer_unlock_frame_buffer();
    mmi_sndrec_blt_screen();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#else/*__MMI_FTE_SUPPORT__*/

    gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);
    gui_show_image(0, 0, g_sndrec_main_draw.bg_img);
    gdi_layer_pop_and_restore_active();

    gdi_layer_pop_clip();

    /* show components */
    mmi_sndrec_redraw_title();
    mmi_sndrec_redraw_main_rsk();
    mmi_sndrec_redraw_main_lsk();
#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_TRUE)
#endif
    {
        mmi_sndrec_redraw_play_btn(MMI_FALSE);
        mmi_sndrec_redraw_prev_btn(MMI_FALSE);
        mmi_sndrec_redraw_next_btn(MMI_FALSE);
        mmi_sndrec_redraw_state_text();		
    }

    mmi_sndrec_redraw_record_btn(MMI_FALSE);	

    mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);

    if (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state || 
        MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state ||
        MMI_SNDREC_PREVIEW_STATE == g_sndrec_cntx.record.state)
    {
        mmi_sndrec_redraw_skins_animal_img(MMI_TRUE);
        mmi_sndrec_show_time_text_without_blt(MMI_TRUE);
    }
    else
    {
        mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
        mmi_sndrec_show_time_text_without_blt(MMI_FALSE);
    }
    gdi_layer_unlock_frame_buffer();
    mmi_sndrec_blt_screen();
#endif/*__MMI_FTE_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_skins_animal_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isact       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_skins_animal_img(MMI_BOOL isact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_w, img_h;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = g_sndrec_main_draw.animal.x;
    y1 = g_sndrec_main_draw.animal.y;
    gui_measure_image(g_sndrec_main_draw.animal.img, &img_w, &img_h);
    #ifndef __MMI_MAINLCD_320X240__
    x1 = (GDI_LCD_WIDTH - img_w) >> 1;
    #endif
    x2 = x1 + img_w - 1;
    y2 = y1 + img_h - 1;

    gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (GDI_ERROR_HANDLE != g_sndrec_main_draw.animal.img_handle)
    {
        gdi_image_stop_animation(g_sndrec_main_draw.animal.img_handle);
        g_sndrec_main_draw.animal.img_handle = GDI_ERROR_HANDLE;
    }
    if (isact)
    {
        gdi_image_draw_animation(x1, y1, g_sndrec_main_draw.animal.img, &g_sndrec_main_draw.animal.img_handle);
    }
    else
    {
        gdi_image_draw(x1, y1, g_sndrec_main_draw.animal.img);
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_sk_btbox
 * DESCRIPTION
 *  draw button display on BT Box main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_redraw_main_sk_btbox(mmi_sndrec_main_SK_button_struct sk, MMI_BOOL is_down, MMI_BOOL is_lsk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h, trunc_w;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    S32 start_x = is_lsk ? 0 : (UI_device_width/2 + 30);
    S32 start_y = UI_device_height - MMI_softkey_height;
    S32 softkey_width = 130;
    MMI_BOOL is_need_trunc = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Reset Button Down flag*/

    if(is_lsk)
    {
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height - 1,
            UI_device_width / 2,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    }
    else
    {
        gui_draw_filled_area(
            UI_device_width / 2, 
            UI_device_height - MMI_softkey_height - 1,
            UI_device_width,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    }

    if (is_down)
    {
        gui_draw_filled_area(
                  start_x, 
                  start_y,
                  start_x + softkey_width,
                  start_y + MMI_softkey_height - 1,                 
                  current_MMI_theme->softkey_lsk_down_filler);
    }
    else
    {
        gui_draw_filled_area(
                  start_x, 
                  start_y,
                  start_x + softkey_width, 
                  start_y + MMI_softkey_height - 1,
                  current_MMI_theme->softkey_bar_bkg_filler);
    }
    
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_color(gui_color(255,255,255));//(sk.color);
    gui_set_text_border_color(sk.border_color);
    gui_measure_string(sk.text, &str_w, &str_h);

    trunc_w = UI_DEVICE_WIDTH / 2;
    is_need_trunc = wgui_softkey_get_offset(
                        sk.text, 
                        &x1, 
                        &y1,
                        &trunc_w, 
                        (is_lsk == MMI_TRUE) ? MMI_LEFT_SOFTKEY : MMI_RIGHT_SOFTKEY,
                        mmi_frm_get_screen_rotate());
    
    y2 = str_h + y1;
    if (r2lMMIFlag)
    {
        x2 = x1;
        x1 = x2 - str_w;
    }
    else
    {
        x2 = str_w + x1;
    }

    if(!is_down)
    { 
        if (is_need_trunc)
        {
            if (r2lMMIFlag)
            {
                gui_print_truncated_borderd_text(x2,y1,trunc_w,sk.text); 
            }
            else
            {
                gui_print_truncated_borderd_text(x1,y1,trunc_w,sk.text); 
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
            gui_print_bordered_text(sk.text);
        }
    }
    else
    {
        if (is_need_trunc)
        {
            if (r2lMMIFlag)
            {
                gui_print_truncated_borderd_text(x2+1, y1+1,trunc_w,sk.text); 
            }
            else
            {
                gui_print_truncated_borderd_text(x1+1, y1+1,trunc_w,sk.text); 
            }
            
        }
        else
        {
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(x2+1, y1+1);
            }
            else
            {
                gui_move_text_cursor(x1+1, y1+1);
            }
            gui_print_bordered_text(sk.text);
        }
    }

#ifdef __MMI_TOUCH_SCREEN__
    if(is_lsk == MMI_TRUE)
    {
        mmi_sndrec_lsk_area.num = 4;
        mmi_sndrec_lsk_area.points = mmi_sndrec_lsk_points;
        mmi_sndrec_lsk_points[0].x = mmi_sndrec_lsk_points[3].x = start_x;
        mmi_sndrec_lsk_points[0].y = mmi_sndrec_lsk_points[1].y = start_y;
        mmi_sndrec_lsk_points[2].x = mmi_sndrec_lsk_points[1].x = start_x + softkey_width + 1;
        mmi_sndrec_lsk_points[3].y = mmi_sndrec_lsk_points[2].y = start_y + MMI_softkey_height;
    }
    else
    {
        mmi_sndrec_rsk_area.num = 4;
        mmi_sndrec_rsk_area.points = mmi_sndrec_rsk_points;
        mmi_sndrec_rsk_points[0].x = mmi_sndrec_rsk_points[3].x = start_x;
        mmi_sndrec_rsk_points[0].y = mmi_sndrec_rsk_points[1].y = start_y;
        mmi_sndrec_rsk_points[2].x = mmi_sndrec_rsk_points[1].x = start_x + softkey_width + 1;
        mmi_sndrec_rsk_points[3].y = mmi_sndrec_rsk_points[2].y = start_y + MMI_softkey_height;
    }
#endif    
}

#endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_sk_fte
 * DESCRIPTION
 *  draw lsk/rsk for fte
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_main_sk_fte(mmi_sndrec_main_SK_button_struct sk,PU8 draw_img,BOOL is_enable,MMI_BOOL is_lsk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    S32 start_x = is_lsk ? 0 : (UI_device_width/2 + 30);
    S32 start_y = UI_device_height - MMI_softkey_height;
    S32 softkey_width = 130;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/                        
	#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
	#endif
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    x1 = sk.x;
    y1 = sk.y;
    x2 = sk.x + sk.w;
    y2 = sk.y + sk.h;

    /* clear osdlayer firstly to clean pen down effect */
    gdi_layer_push_and_set_active(g_sndrec_layer.osdlayer);
    gdi_draw_solid_rect(
        0,
        UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1,
        UI_DEVICE_WIDTH,
        UI_DEVICE_HEIGHT - 1,
        GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    if(is_sndrec_skin_layer_drawn)
    {
        gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_TRANSPARENT);

        
    #if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
        //gdi_image_draw_resized(0,0,UI_device_width, UI_device_height, g_sndrec_main_draw.bg_img);
        /* Now for FTE draw the menu background image */
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    #elif defined(__MMI_FTE_SUPPORT_SLIM__)
        //gdi_image_draw_resized(0, sk.y, UI_device_width, UI_device_height - g_sndrec_main_draw.lsk.y, g_sndrec_main_draw.bg_img);
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    #else
        //gui_show_image(0, 0, g_sndrec_main_draw.bg_img);
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    #endif
    }    

    if (is_enable)
    {
        gui_show_image(x1, y1, draw_img);
    }
	else
    {
        gui_draw_image_with_alpha_transparent(
            draw_img,
            x1,
            y1,
            125);
    }

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if(is_lsk == MMI_TRUE)
    {
        mmi_sndrec_lsk_area.num = 4;
        mmi_sndrec_lsk_area.points = mmi_sndrec_lsk_points;
        mmi_sndrec_lsk_points[0].x = mmi_sndrec_lsk_points[3].x = start_x;
        mmi_sndrec_lsk_points[0].y = mmi_sndrec_lsk_points[1].y = start_y;
        mmi_sndrec_lsk_points[2].x = mmi_sndrec_lsk_points[1].x = start_x + softkey_width + 1;
        mmi_sndrec_lsk_points[3].y = mmi_sndrec_lsk_points[2].y = start_y + MMI_softkey_height;
    }
    else
    {
        mmi_sndrec_rsk_area.num = 4;
        mmi_sndrec_rsk_area.points = mmi_sndrec_rsk_points;
        mmi_sndrec_rsk_points[0].x = mmi_sndrec_rsk_points[3].x = start_x;
        mmi_sndrec_rsk_points[0].y = mmi_sndrec_rsk_points[1].y = start_y;
        mmi_sndrec_rsk_points[2].x = mmi_sndrec_rsk_points[1].x = start_x + softkey_width + 1;
        mmi_sndrec_rsk_points[3].y = mmi_sndrec_rsk_points[2].y = start_y + MMI_softkey_height;
    }
#else
    if(is_lsk == MMI_TRUE)
    {
        mmi_sndrec_lsk_area.num = 4;
        mmi_sndrec_lsk_area.points = mmi_sndrec_lsk_points;
        mmi_sndrec_lsk_points[0].x = mmi_sndrec_lsk_points[3].x = x1;
        mmi_sndrec_lsk_points[0].y = mmi_sndrec_lsk_points[1].y = y1;
        mmi_sndrec_lsk_points[2].x = mmi_sndrec_lsk_points[1].x = x2 + 1;
        mmi_sndrec_lsk_points[3].y = mmi_sndrec_lsk_points[2].y = y2 + 1;
    }
    else
    {
        mmi_sndrec_rsk_area.num = 4;
        mmi_sndrec_rsk_area.points = mmi_sndrec_rsk_points;
        mmi_sndrec_rsk_points[0].x = mmi_sndrec_rsk_points[3].x = x1;
        mmi_sndrec_rsk_points[0].y = mmi_sndrec_rsk_points[1].y = y1;
        mmi_sndrec_rsk_points[2].x = mmi_sndrec_rsk_points[1].x = x2 + 1;
        mmi_sndrec_rsk_points[3].y = mmi_sndrec_rsk_points[2].y = y2 + 1;
    }
#endif
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_button_fte
 * DESCRIPTION
 *  draw button display on fte main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_button_fte(mmi_sndrec_push_button_struct *draw_btn, MMI_BOOL is_enable,MMI_BOOL isdown)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    S32 diffx = 0;
    S32 diffy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = draw_btn->x;
    y1 = draw_btn->y;
    x2 = draw_btn->x + draw_btn->w - 1;
    y2 = draw_btn->y + draw_btn->h - 1;

    if (is_sndrec_skin_layer_drawn && is_enable)
    {
        diffx = g_sndrec_main_draw.highlight_img.w - draw_btn->w;
        diffy = g_sndrec_main_draw.highlight_img.h - draw_btn->h;
        x1 -= (diffx / 2);
        y1 -= (diffy / 2);
        x2 += ((1 + diffx) / 2);
        y2 += ((1 + diffy) / 2);

        if(isdown)
        {
            gdi_layer_push_and_set_clip(x1, y1, x2, y2);
              
            g_sndrec_cntx.record.isButtonDown = MMI_TRUE;
            gui_show_image(x1,  y1, g_sndrec_main_draw.highlight_img.up_img);
            mmi_sndrec_touch_feedback_enable();   
      
            gdi_layer_pop_clip();
        }
        else
        {
            g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
            gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);
            gdi_layer_push_and_set_clip(x1, y1, x2, y2);
            
        #if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
            //gdi_image_draw_resized(0,0,UI_device_width, UI_device_height, g_sndrec_main_draw.bg_img);
            //gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
            //gui_show_image(g_sndrec_main_draw.cross.x, g_sndrec_main_draw.cross.y, g_sndrec_main_draw.cross.up_img);
            /* Now for FTE draw the menu background image */
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler);
            #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                gdi_image_draw_resized(g_sndrec_main_draw.line_x, g_sndrec_main_draw.line_y, g_sndrec_main_draw.line_w, g_sndrec_main_draw.line_h, g_sndrec_main_draw.line_img);
            #else
                gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
            #endif
        #elif defined(__MMI_FTE_SUPPORT_SLIM__)
            //gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_BLACK);
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler);
            gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
        #else
            gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_TRANSPARENT);
            //gui_show_image(0, 0, g_sndrec_main_draw.bg_img);
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler);
        #endif
            gui_show_image(x1 + diffx/2, y1 + diffy/2, draw_btn->up_img);
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
        }

    }
    else
    {
        gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        
        if(is_sndrec_skin_layer_drawn)
        {
        #if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
            //gdi_image_draw_resized(0,0,UI_device_width, UI_device_height, g_sndrec_main_draw.bg_img);
            //gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
            //gui_show_image(g_sndrec_main_draw.cross.x, g_sndrec_main_draw.cross.y, g_sndrec_main_draw.cross.up_img);
            /* Now for FTE draw the menu background image */
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler);
            #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                gdi_image_draw_resized(g_sndrec_main_draw.line_x, g_sndrec_main_draw.line_y, g_sndrec_main_draw.line_w, g_sndrec_main_draw.line_h, g_sndrec_main_draw.line_img);
            #else
                gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
            #endif
        #elif defined(__MMI_FTE_SUPPORT_SLIM__)
            //gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_BLACK);
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler);
            gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
        #else
            gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_TRANSPARENT);
            //gui_show_image(0, 0, g_sndrec_main_draw.bg_img);
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler);
        #endif
        }  
        
        if (is_enable)
        {
            g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
            gui_show_image(x1, y1, draw_btn->up_img);
        }
        else
        {
            //gui_show_image(x1, y1, draw_btn->disable_img);
            gui_draw_image_with_alpha_transparent(
                draw_btn->up_img,
                x1,
                y1,
                125);
        }      
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_rec_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_rec_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn;
    S32 x1, y1, x2, y2;
    MMI_BOOL is_show = MMI_FALSE;
    PU8 draw_img = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_btn = &g_sndrec_main_draw.rec_icon;
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_REC_PAUSE_STATE:
            is_show = MMI_TRUE;
            draw_img=g_sndrec_main_draw.rec_pause_icon.up_img;
            break;
        case MMI_SNDREC_REC_STATE:
            is_show = MMI_TRUE;
            draw_img=draw_btn->up_img;
            break;
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:                
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
        case MMI_SNDREC_IDLE_STATE:
            break;

        default:
            ASSERT(0);
    }
    x1 = draw_btn->x;
    y1 = draw_btn->y;
    x2 = draw_btn->x + draw_btn->w - 1;
    y2 = draw_btn->y + draw_btn->h - 1;

    /*Reset Button Down flag*/
    gdi_layer_push_and_set_active(g_sndrec_layer.skinlayer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_TRANSPARENT);
    
#if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
    //gdi_image_draw_resized(0,0,UI_device_width, UI_device_height, g_sndrec_main_draw.bg_img);
    //gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
    //gui_show_image(g_sndrec_main_draw.cross.x, g_sndrec_main_draw.cross.y, g_sndrec_main_draw.cross.up_img);
    /* Now for FTE draw the menu background image */
    gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
        current_MMI_theme->sub_menu_bkg_filler);
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        gdi_image_draw_resized(g_sndrec_main_draw.line_x, g_sndrec_main_draw.line_y, g_sndrec_main_draw.line_w, g_sndrec_main_draw.line_h, g_sndrec_main_draw.line_img);
    #else
        gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
    #endif
#elif defined(__MMI_FTE_SUPPORT_SLIM__)
    //gdi_draw_solid_rect(x1,  y1, x2, y2, GDI_COLOR_BLACK);
    gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
        current_MMI_theme->sub_menu_bkg_filler);
    gui_show_image(g_sndrec_main_draw.line.x, g_sndrec_main_draw.line.y, g_sndrec_main_draw.line.up_img);
#else
    //gui_show_image(0, 0, g_sndrec_main_draw.bg_img);
    gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
        current_MMI_theme->sub_menu_bkg_filler);
#endif
    if(is_show)
    {
        gui_show_image(x1, y1, draw_img);
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_stop_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_stop_btn(MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn;
    MMI_BOOL is_enable = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return;
    }
#endif
    
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_REC_STATE:   
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            is_enable = MMI_TRUE;
            break;
            
        case MMI_SNDREC_IDLE_STATE:
            break;

        default:
            ASSERT(0);
    }
    draw_btn = &g_sndrec_main_draw.stop;
    mmi_sndrec_redraw_button_fte(draw_btn,is_enable,isdown);    
}

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_list_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_list_btn(MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn;
    MMI_BOOL is_enable = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return;
    }
#endif
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:                
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_REC_STATE:   
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            is_enable = MMI_FALSE;
            break;
            
        case MMI_SNDREC_IDLE_STATE:
            if (g_sndrec_cntx.record.isIncall)
            {
                is_enable = MMI_FALSE;
            }            
            break;
            
        default:
            ASSERT(0);
    }
    draw_btn = &g_sndrec_main_draw.list;
    
    mmi_sndrec_redraw_button_fte(draw_btn,is_enable,isdown);   
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
	
#else/*__MMI_FTE_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_sk
 * DESCRIPTION
 *  draw button display on non-fte main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
void mmi_sndrec_redraw_main_sk(mmi_sndrec_main_SK_struct sk, MMI_BOOL is_down, MMI_BOOL is_lsk)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h, trunc_w;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    MMI_BOOL is_need_trunc = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Reset Button Down flag*/

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_color(sk.color);
    gui_set_text_border_color(sk.border_color);
    gui_measure_string(sk.text, &str_w, &str_h);

    trunc_w = UI_DEVICE_WIDTH / 2;
    is_need_trunc = wgui_softkey_get_offset(
                        sk.text, 
                        &x1, 
                        &y1,
                        &trunc_w, 
                        (is_lsk == MMI_TRUE) ? MMI_LEFT_SOFTKEY : MMI_RIGHT_SOFTKEY,
                        mmi_frm_get_screen_rotate());
    
    y2 = str_h + y1;
    if (r2lMMIFlag)
    {
        x2 = x1;
        x1 = x2 - str_w;
    }
    else
    {
        x2 = str_w + x1;
    }

    if(!is_down)
    { 
        if (is_need_trunc)
        {
            if (r2lMMIFlag)
            {
                gui_print_truncated_borderd_text(x2,y1,trunc_w,sk.text); 
            }
            else
            {
                gui_print_truncated_borderd_text(x1,y1,trunc_w,sk.text); 
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
            gui_print_bordered_text(sk.text);
        }
    }
    else
    {
        if (is_need_trunc)
        {
            if (r2lMMIFlag)
            {
                gui_print_truncated_borderd_text(x2+1, y1+1,trunc_w,sk.text); 
            }
            else
            {
                gui_print_truncated_borderd_text(x1+1, y1+1,trunc_w,sk.text); 
            }
            
        }
        else
        {
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(x2+1, y1+1);
            }
            else
            {
                gui_move_text_cursor(x1+1, y1+1);
            }
            gui_print_bordered_text(sk.text);
        }
    }

#ifdef __MMI_TOUCH_SCREEN__
    if(is_lsk == MMI_TRUE)
    {
        mmi_sndrec_lsk_area.num = 4;
        mmi_sndrec_lsk_area.points = mmi_sndrec_lsk_points;
        mmi_sndrec_lsk_points[0].x = mmi_sndrec_lsk_points[3].x = x1;
        mmi_sndrec_lsk_points[0].y = mmi_sndrec_lsk_points[1].y = y1;
        mmi_sndrec_lsk_points[2].x = mmi_sndrec_lsk_points[1].x = x2 + 1;
        mmi_sndrec_lsk_points[3].y = mmi_sndrec_lsk_points[2].y = y2 + 1;
    }
    else
    {
        mmi_sndrec_rsk_area.num = 4;
        mmi_sndrec_rsk_area.points = mmi_sndrec_rsk_points;
        mmi_sndrec_rsk_points[0].x = mmi_sndrec_rsk_points[3].x = x1;
        mmi_sndrec_rsk_points[0].y = mmi_sndrec_rsk_points[1].y = y1;
        mmi_sndrec_rsk_points[2].x = mmi_sndrec_rsk_points[1].x = x2 + 1;
        mmi_sndrec_rsk_points[3].y = mmi_sndrec_rsk_points[2].y = y2 + 1;
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_button_non_fte
 * DESCRIPTION
 *  draw button display on non-fte main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/  
void mmi_sndrec_redraw_button_non_fte(mmi_sndrec_push_button_struct *draw_btn, MMI_BOOL is_enable,MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = draw_btn->x;
    y1 = draw_btn->y;
    x2 = draw_btn->x + draw_btn->w - 1;
    y2 = draw_btn->y + draw_btn->h - 1;
 
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (is_enable)
    {
        if (isdown)
        {
            g_sndrec_cntx.record.isButtonDown = MMI_TRUE;
            gui_show_image(x1, y1, draw_btn->down_img);
        }
        else
        {
            /*Reset Button Down flag*/
            g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
            gui_show_image(x1, y1, draw_btn->up_img);
        }
    }
    else
    {
        gui_show_image(x1, y1, draw_btn->disable_img);
    }

    gdi_layer_pop_clip(); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_state_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_state_text()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 str_w, str_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            if(!g_sndrec_wait_next_prev)
            {
                g_sndrec_main_draw.state.text = (UI_string_type) GetString(STR_ID_SNDREC_PLS_RECORD);
            }
            break;

        case MMI_SNDREC_REC_STATE:
            g_sndrec_main_draw.state.text = (UI_string_type) GetString(STR_ID_SNDREC_RECORDING);
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
            g_sndrec_main_draw.state.text = (UI_string_type) GetString(STR_ID_SNDREC_REC_PAUSED);
            break;

        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
            g_sndrec_main_draw.state.text = (UI_string_type) GetString(STR_ID_SNDREC_PLAYING);
            break;

        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            g_sndrec_main_draw.state.text = (UI_string_type) GetString(STR_ID_SNDREC_PLAY_PAUSED);
            break;

        default:
            ASSERT(0);
    }

    /*x1, y1, x2, y2 is the region without bolder*/
    x1 = g_sndrec_main_draw.state.x + 2;
    y1 = g_sndrec_main_draw.state.y + 1;
    x2 = g_sndrec_main_draw.state.x + g_sndrec_main_draw.state.w - 3;
    y2 = g_sndrec_main_draw.state.y + g_sndrec_main_draw.state.h - 2;

    gui_set_font(&MMI_medium_font);  

    gui_scrolling_text_stop(&g_sndrec_main_draw.scroll_text_state);
    gui_create_scrolling_text(
        &g_sndrec_main_draw.scroll_text_state,
        x1,
        y1,
        g_sndrec_main_draw.state.w - 4,
        g_sndrec_main_draw.state.h - 2,
        g_sndrec_main_draw.state.text,
        mmi_sndrec_scroll_state_handler,
        mmi_sndrec_redraw_filename_background,
        g_sndrec_main_draw.state_color,
        g_sndrec_main_draw.state_border_color);
    g_sndrec_main_draw.scroll_text_state.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
 
    gdi_layer_push_and_set_clip(x1 - 2, y1 - 1, x2 + 2, y2 + 1);

    gui_measure_string(g_sndrec_main_draw.state.text, &str_w, &str_h);
    if (str_w > (g_sndrec_main_draw.state.w - 4))
    {
        gui_change_scrolling_text(&g_sndrec_main_draw.scroll_text_state, g_sndrec_main_draw.state.text);
        gui_show_scrolling_text(&g_sndrec_main_draw.scroll_text_state);
    }
    else
    {
        gdi_draw_solid_rect(x1 - 2, y1 - 1, x2 + 2, y2 + 1, GDI_COLOR_TRANSPARENT);
        gui_set_text_color(g_sndrec_main_draw.state_color);
        gui_set_text_border_color(g_sndrec_main_draw.state_border_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + str_w, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        gui_set_line_height(str_h);
        gui_print_bordered_text(g_sndrec_main_draw.state.text);
    }
    gdi_layer_pop_text_clip();
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_redraw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = g_sndrec_main_draw.title.x;
    y1 = g_sndrec_main_draw.title.y;
    x2 = g_sndrec_main_draw.title.x + g_sndrec_main_draw.title.w - 1;
    y2 = g_sndrec_main_draw.title.y + g_sndrec_main_draw.title.h - 1;
 
    gdi_layer_push_and_set_clip(x1 - 2, y1 - 1, x2 + 2, y2 + 1);
    
    /*show satatus bar*/
#ifdef __MMI_SNDREC_SUPPORT_STATUS_BAR__
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_H_BAR,
        mmi_sndrec_redraw_status_icon);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
#endif
    
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gui_set_text_color(g_sndrec_main_draw.title_color);
    gui_set_text_border_color(g_sndrec_main_draw.title_border_color);

    gui_measure_string(g_sndrec_main_draw.title.text, &str_w, &str_h);
    if (g_sndrec_main_draw.title.w >= str_w)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor((x1 + x2 + str_w) / 2, y1);
        }
        else
        {
            gui_move_text_cursor((x1 + x2 - str_w) / 2, y1);
        }
        gui_set_line_height(str_h);
        gui_print_bordered_text(g_sndrec_main_draw.title.text);
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_borderd_text(x2, y1, g_sndrec_main_draw.title.w, g_sndrec_main_draw.title.text);
        }
        else
        {
            gui_print_truncated_borderd_text(x1, y1, g_sndrec_main_draw.title.w, g_sndrec_main_draw.title.text);
        }   
    }    
            
    gdi_layer_pop_clip();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_lsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_main_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
      PU8 draw_img = NULL;
      BOOL is_enable = TRUE;
#endif  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            if (mmi_sndrec_is_play_flag)
            {                
                g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_PLAY);
            }
            else
            {
                g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_ID_SNDREC_RECORD);
            }                
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
            g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_PAUSE);
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_CONTINUE);
            break;

        case MMI_SNDREC_PLAY_PAUSE_STATE:
            g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_PLAY);
            break;

        default:
            ASSERT(0);
    }

    /*Reset Button Down flag*/
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

    gdi_layer_push_text_clip();

    gui_draw_filled_area(
        0, 
        UI_device_height - MMI_softkey_height - 1,
        UI_device_width / 2,
        UI_device_height - 1,
        current_MMI_theme->softkey_bar_bkg_filler);

    gdi_layer_set_clip(0, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - 1);

    mmi_sndrec_redraw_main_sk_btbox(g_sndrec_main_draw.lsk, MMI_FALSE, MMI_TRUE);

    gdi_layer_pop_text_clip();

#elif defined(__MMI_FTE_SUPPORT__)
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            draw_img = g_sndrec_main_draw.lsk.up_img;
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
            //draw_img = g_sndrec_main_draw.lsk.dis_img;
            /* For FTE disabled button is 50 percent transparent up image */
            draw_img = g_sndrec_main_draw.lsk.up_img;
            is_enable=FALSE;
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            /* For FTE disabled button is 50 percent transparent up image */
            //draw_img = g_sndrec_main_draw.lsk.dis_img;
            draw_img = g_sndrec_main_draw.lsk.up_img;
            is_enable = FALSE;
            break;

        default:
            ASSERT(0);
    }
    mmi_sndrec_redraw_main_sk_fte(g_sndrec_main_draw.lsk,draw_img,is_enable,MMI_TRUE);

#else/*__MMI_FTE_SUPPORT__*/
    
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_OPTIONS);
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
            g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_PAUSE);
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            g_sndrec_main_draw.lsk.text = (UI_string_type) GetString(STR_GLOBAL_CONTINUE);
            break;

        default:
            ASSERT(0);
    }

    /*Reset Button Down flag*/
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

    gdi_layer_push_text_clip();
    gdi_draw_solid_rect(
        0,
        UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1,
        UI_DEVICE_WIDTH / 2,
        UI_DEVICE_HEIGHT - 1,
                        GDI_COLOR_TRANSPARENT);
    gdi_layer_set_clip(0, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - 1);

    mmi_sndrec_redraw_main_sk(g_sndrec_main_draw.lsk, MMI_FALSE, MMI_TRUE);

    gdi_layer_pop_text_clip();
#endif /* __MMI_FTE_SUPPORT__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_rsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_main_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
        PU8 draw_img = NULL;
        BOOL is_enable = TRUE;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
            g_sndrec_main_draw.rsk.text = (UI_string_type) GetString(STR_GLOBAL_BACK);
            break;

        case MMI_SNDREC_REC_STATE:
        #if defined(__MMI_OP02_LEMEI__)
            if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
            {
                g_sndrec_main_draw.rsk.text = (UI_string_type) GetString(STR_GLOBAL_BACK);
                break;
            }
        #endif
        
        case MMI_SNDREC_REC_PAUSE_STATE:        
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            g_sndrec_main_draw.rsk.text = (UI_string_type) GetString(STR_GLOBAL_STOP);
            break;

        default:
            ASSERT(0);
    }

    /*Reset Button Down flag*/
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

    gdi_layer_push_text_clip();

    gdi_draw_solid_rect(UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, 
                        UI_DEVICE_WIDTH -1, UI_DEVICE_HEIGHT - 1, 
                        GDI_COLOR_TRANSPARENT);
    gdi_layer_set_clip(UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, 
                       UI_DEVICE_WIDTH -1, UI_DEVICE_HEIGHT - 1);
    
    mmi_sndrec_redraw_main_sk_btbox(g_sndrec_main_draw.rsk, MMI_FALSE, MMI_FALSE); 

    gdi_layer_pop_text_clip();

#elif defined(__MMI_FTE_SUPPORT__) 
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            draw_img = g_sndrec_main_draw.rsk.up_img;
            break;

        case MMI_SNDREC_REC_STATE:
        #if defined(__MMI_OP02_LEMEI__)
            if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
            {
                draw_img = g_sndrec_main_draw.rsk.up_img;
                break;
            }
        #endif
        
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            //draw_img = g_sndrec_main_draw.rsk.dis_img;
            /* For FTE disabled button is 50 percent transparent up image */
            draw_img = g_sndrec_main_draw.rsk.up_img;
            is_enable = FALSE;
            break;

        default:
            ASSERT(0);
    }
    mmi_sndrec_redraw_main_sk_fte(g_sndrec_main_draw.rsk, draw_img ,is_enable,MMI_FALSE);	

#else/*__MMI_FTE_SUPPORT__*/

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            g_sndrec_main_draw.rsk.text = (UI_string_type) GetString(STR_GLOBAL_BACK);
            break;

        case MMI_SNDREC_REC_STATE:
        #if defined(__MMI_OP02_LEMEI__)
            if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
            {
                g_sndrec_main_draw.rsk.text = (UI_string_type) GetString(STR_GLOBAL_BACK);
                break;
            }
        #endif
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            g_sndrec_main_draw.rsk.text = (UI_string_type) GetString(STR_GLOBAL_STOP);
            break;

        default:
            ASSERT(0);
    }

    /*Reset Button Down flag*/
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

    gdi_layer_push_text_clip();

    gdi_draw_solid_rect(UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, 
                        UI_DEVICE_WIDTH -1, UI_DEVICE_HEIGHT - 1, 
                        GDI_COLOR_TRANSPARENT);
    gdi_layer_set_clip(UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, 
                       UI_DEVICE_WIDTH -1, UI_DEVICE_HEIGHT - 1);
    
    mmi_sndrec_redraw_main_sk(g_sndrec_main_draw.rsk, MMI_FALSE, MMI_FALSE); 

    gdi_layer_pop_text_clip();
 
#endif/*__MMI_FTE_SUPPORT__*/ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_lsk_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_main_lsk_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        S32 diffx;
        S32 diffy;
#endif
        S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        PU8 draw_img = NULL;
        BOOL is_enable = TRUE;
#endif 

#endif  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return;
    }
#endif
    
    g_sndrec_cntx.record.isButtonDown = MMI_TRUE;
#ifdef __MMI_FTE_SUPPORT__
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            break;
        #else
            return;
        #endif         
        default:
            ASSERT(0);
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

	#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	draw_img = g_sndrec_main_draw.lsk.down_img;
    
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_sndrec_redraw_main_sk_btbox(g_sndrec_main_draw.lsk, MMI_TRUE, MMI_TRUE);
    #else
	mmi_sndrec_redraw_main_sk_fte(g_sndrec_main_draw.lsk, draw_img, is_enable, MMI_TRUE);
    #endif
	#else
    diffx = g_sndrec_main_draw.highlight_img.w - g_sndrec_main_draw.lsk.w;
    diffy = g_sndrec_main_draw.highlight_img.h - g_sndrec_main_draw.lsk.h;
    
    x1 = g_sndrec_main_draw.lsk.x - (diffx / 2);
    y1 = g_sndrec_main_draw.lsk.y - (diffy / 2);
    x2 = x1 + g_sndrec_main_draw.lsk.w + diffx - 1;
    y2 = y1 + g_sndrec_main_draw.lsk.h + diffy - 1;

    gui_push_and_set_clip(x1, y1, x2, y2);

    /* button */
    gui_show_image(x1, y1, g_sndrec_main_draw.highlight_img.up_img);

    gui_pop_clip();
	#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

    mmi_sndrec_touch_feedback_enable();

#else/*__MMI_FTE_SUPPORT__*/

        
    gdi_draw_solid_rect(
        0,
        UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1,
        UI_DEVICE_WIDTH / 2,
        UI_DEVICE_HEIGHT - 1,
        GDI_COLOR_TRANSPARENT);

    gdi_layer_push_and_set_clip(0, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - 1);
        
    mmi_sndrec_redraw_main_sk(g_sndrec_main_draw.lsk,MMI_TRUE, MMI_TRUE);

    gdi_layer_pop_text_clip();
 
#endif/*__MMI_FTE_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_main_rsk_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_main_rsk_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        S32 diffx;
        S32 diffy;
#endif
        S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        PU8 draw_img = NULL;
        BOOL is_enable = TRUE;
	#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#endif  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sndrec_cntx.record.isButtonDown = MMI_TRUE;
#ifdef __MMI_FTE_SUPPORT__
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            break;
        #else
            return;
        #endif
        
        default:
            ASSERT(0);
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 


	#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	draw_img = g_sndrec_main_draw.rsk.down_img;
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_sndrec_redraw_main_sk_btbox(g_sndrec_main_draw.rsk, MMI_TRUE, MMI_FALSE);
    #else
	mmi_sndrec_redraw_main_sk_fte(g_sndrec_main_draw.rsk, draw_img, is_enable, MMI_FALSE);
    #endif
	#else
    diffx = g_sndrec_main_draw.highlight_img.w - g_sndrec_main_draw.rsk.w;
    diffy = g_sndrec_main_draw.highlight_img.h - g_sndrec_main_draw.rsk.h;
    
    x1 = g_sndrec_main_draw.rsk.x - (diffx / 2);
    y1 = g_sndrec_main_draw.rsk.y - (diffy / 2);
    x2 = x1 + g_sndrec_main_draw.rsk.w + diffx - 1;
    y2 = y1 + g_sndrec_main_draw.rsk.h + diffy - 1;

    gui_push_and_set_clip(x1, y1, x2, y2);
    /* button */
    gui_show_image(x1, y1, g_sndrec_main_draw.highlight_img.up_img);
    gui_pop_clip();
	#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#else/*__MMI_FTE_SUPPORT__*/
    
    gdi_draw_solid_rect(UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, 
                        UI_DEVICE_WIDTH -1, UI_DEVICE_HEIGHT, 
                        GDI_COLOR_TRANSPARENT);
    gdi_layer_push_and_set_clip(UI_DEVICE_WIDTH / 2, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - 1, 
                       UI_DEVICE_WIDTH -1, UI_DEVICE_HEIGHT - 1);
    
    mmi_sndrec_redraw_main_sk(g_sndrec_main_draw.rsk, MMI_TRUE, MMI_FALSE);

    gdi_layer_pop_text_clip(); 
#endif/*__MMI_FTE_SUPPORT__*/

#if defined (__MMI_FTE_SUPPORT__)
    mmi_sndrec_touch_feedback_enable();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_record_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_record_btn(MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn;
    MMI_BOOL is_enable = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_REC_STATE:
            draw_btn = &g_sndrec_main_draw.rec_pause;
            break;
        case MMI_SNDREC_IDLE_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
            draw_btn = &g_sndrec_main_draw.record;
            break;
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            draw_btn = &g_sndrec_main_draw.record;
            is_enable = MMI_FALSE;
            break;
        default:
            return;
    }
    /* button */
#ifdef __MMI_FTE_SUPPORT__
    mmi_sndrec_redraw_button_fte(draw_btn,is_enable,isdown);   
#else/*__MMI_FTE_support__*/
    mmi_sndrec_redraw_button_non_fte(draw_btn,is_enable,isdown);   
#endif/*MMI_FTE_SUPPORT*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_play_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_play_btn(MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn = NULL;
    MMI_BOOL is_enable = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return;
    }
#endif
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
            draw_btn = &g_sndrec_main_draw.play_pause;
            break;
       
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            draw_btn = &g_sndrec_main_draw.play;
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_REC_STATE:    
            draw_btn = &g_sndrec_main_draw.play;
            is_enable = MMI_FALSE;
            break;
            
        case MMI_SNDREC_IDLE_STATE:
            draw_btn = &g_sndrec_main_draw.play;
            if(mmi_sndrec_check_file_isnull() || g_sndrec_cntx.record.isIncall)
            {
                is_enable = MMI_FALSE;
            }
            break;
            
        default:
            ASSERT(0);
    }

#ifdef __MMI_FTE_SUPPORT__
    mmi_sndrec_redraw_button_fte(draw_btn,is_enable,isdown);    
#else/*__MMI_FTE_support__*/
    mmi_sndrec_redraw_button_non_fte(draw_btn,is_enable,isdown);
#endif/*__MMI_FTE_SUPPORT__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_next_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_next_btn(MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn;
    MMI_BOOL is_enable = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return;
    }
#endif
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:                
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_REC_STATE:   
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            is_enable = MMI_FALSE;
            break;
            
        case MMI_SNDREC_IDLE_STATE:
            if (mmi_sndrec_check_file_isnull() || g_sndrec_cntx.record.isIncall)
            {
                is_enable = MMI_FALSE;
            }            
            break;
            
        default:
            ASSERT(0);
    }
    draw_btn = &g_sndrec_main_draw.next;

#ifdef __MMI_FTE_SUPPORT__
    mmi_sndrec_redraw_button_fte(draw_btn,is_enable,isdown);   
#else/*__MMI_FTE_support__*/
    mmi_sndrec_redraw_button_non_fte(draw_btn,is_enable,isdown);
#endif/*__MMI_FTE_SUPPORT__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_prev_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isdown      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_prev_btn(MMI_BOOL isdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_push_button_struct *draw_btn;
    //S32 x1, y1, x2, y2;
    MMI_BOOL is_enable = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return;
    }
    #endif

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:                   
            break;
            
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_REC_STATE:   
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            is_enable = MMI_FALSE;
            break;
            
        case MMI_SNDREC_IDLE_STATE:
            if (mmi_sndrec_check_file_isnull() || g_sndrec_cntx.record.isIncall)
            {
                is_enable = MMI_FALSE;
            }            
            break;
        default:
            ASSERT(0);
    }
    draw_btn = &g_sndrec_main_draw.previous;

#ifdef __MMI_FTE_SUPPORT__
    mmi_sndrec_redraw_button_fte(draw_btn,is_enable,isdown);    
#else/*__MMI_FTE_support__*/
    mmi_sndrec_redraw_button_non_fte(draw_btn,is_enable,isdown);
#endif/*__MMI_FTE_SUPPORT__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hide_main_skins
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_hide_main_skins(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_flatten_to_base(g_sndrec_layer.skinlayer, g_sndrec_layer.osdlayer, 0, 0);
    gdi_layer_free(g_sndrec_layer.skinlayer);
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(g_sndrec_layer.osdlayer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_sndrec_draw_skin_struct *skin_p = g_sndrec_record_skins;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sndrec_main_draw.pen_dn_obj = MMI_SNDREC_NONE;

    for (i = MMI_SNDREC_NONE + 1; i < MMI_SNDREC_TOTAL; i++)
    {
        switch (i)
        {
            case MMI_SNDREC_LSK:
                area = (mmi_pen_polygon_area_struct*) & mmi_sndrec_lsk_area;
                point = pos;
                break;

            case MMI_SNDREC_RSK:
                area = (mmi_pen_polygon_area_struct*) & mmi_sndrec_rsk_area;
                point = pos;
                break;

            case MMI_SNDREC_RECORD:
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_btn_area;
                point.x = pos.x - skin_p->record_btn_x;
                point.y = pos.y - skin_p->record_btn_y;
                break;

            case MMI_SNDREC_PLAY:
                area = (mmi_pen_polygon_area_struct*) & skin_p->play_btn_area;
                point.x = pos.x - skin_p->play_btn_x;
                point.y = pos.y - skin_p->play_btn_y;
                break;

            case MMI_SNDREC_PREV:
                area = (mmi_pen_polygon_area_struct*) & skin_p->prev_btn_area;
                point.x = pos.x - skin_p->prev_btn_x;
                point.y = pos.y - skin_p->prev_btn_y;
                break;

            case MMI_SNDREC_NEXT:
                area = (mmi_pen_polygon_area_struct*) & skin_p->next_btn_area;
                point.x = pos.x - skin_p->next_btn_x;
                point.y = pos.y - skin_p->next_btn_y;
                break;
         #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            case MMI_SNDREC_LIST:
                area = (mmi_pen_polygon_area_struct*) & skin_p->list_btn_area;
                point.x = pos.x - skin_p->list_btn_x;
                point.y = pos.y - skin_p->list_btn_y;
                break;
         #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */       
        #ifdef __MMI_FTE_SUPPORT__
            case MMI_SNDREC_STOP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->stop_btn_area;
                point.x = pos.x - skin_p->stop_btn_x;
                point.y = pos.y - skin_p->stop_btn_y;
                break;
        #endif/*__MMI_FTE_SUPPORT__*/
        
            default:
                return;
        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            g_sndrec_main_draw.pen_dn_obj = i;
            break;
        }
    }

    switch (g_sndrec_main_draw.pen_dn_obj)
    {
        case MMI_SNDREC_LSK:
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            if(g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE)
            {
                mmi_sndrec_redraw_play_btn(MMI_TRUE);
            }
            else
            {
                mmi_sndrec_redraw_record_btn(MMI_TRUE);
            } 
        #endif
            mmi_sndrec_redraw_main_lsk_down();
            break;

        case MMI_SNDREC_RSK:
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            if(g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE || mmi_sndrec_is_play_flag == MMI_TRUE)
            {
                mmi_sndrec_redraw_stop_btn(MMI_TRUE);
            } 
        #endif
            mmi_sndrec_redraw_main_rsk_down();
            break;

        case MMI_SNDREC_RECORD:
            mmi_sndrec_redraw_record_btn(MMI_TRUE);
            break;

        case MMI_SNDREC_PLAY:
            mmi_sndrec_redraw_play_btn(MMI_TRUE);
            break;

        case MMI_SNDREC_PREV:
            mmi_sndrec_redraw_prev_btn(MMI_TRUE);
            break;

        case MMI_SNDREC_NEXT:
            mmi_sndrec_redraw_next_btn(MMI_TRUE);
            break;
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    	case MMI_SNDREC_LIST:
         #ifdef __MMI_FTE_SUPPORT__
                mmi_sndrec_redraw_list_btn(MMI_TRUE);
         #endif
            break;
    #endif
        
     #ifdef __MMI_FTE_SUPPORT__
        case MMI_SNDREC_STOP:
            mmi_sndrec_redraw_stop_btn(MMI_TRUE);
            break;
     #endif/*__MMI_FTE_SUPPORT__*/
        
        default:
            return;
    }
    
 #ifdef __MMI_FTE_SUPPORT__ 
    if(mmi_sndrec_query_is_touch_feedback_enable() == MMI_TRUE)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        mmi_sndrec_touch_feedback_disable();	
    }
#endif
    mmi_sndrec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //const mmi_sndrec_draw_skin_struct *skin_p = g_sndrec_record_skins;
    //mmi_pen_polygon_area_struct *area = NULL;
    //mmi_pen_point_struct point;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sndrec_main_draw.pen_dn_obj)
    {
        case MMI_SNDREC_LSK:
            /*if (mmi_pen_check_inside_polygon(&mmi_sndrec_lsk_area, pos))
            {
                mmi_sndrec_mainscr_lsk_up_hdlr();
            }*/
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            if(g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE || mmi_sndrec_is_play_flag == MMI_TRUE)
            {
                mmi_sndrec_release_play_btn();
            }
            else
            {
                mmi_sndrec_release_record_btn();
            }
        #endif
            mmi_sndrec_mainscr_lsk_up_hdlr();
            break;

        case MMI_SNDREC_RSK:
            /*if (mmi_pen_check_inside_polygon(&mmi_sndrec_rsk_area, pos))
            {
                mmi_sndrec_mainscr_rsk_up_hdlr();
            }*/
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__   
            if((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) 
                || (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
            {
                if(g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE)
                {
                    mmi_sndrec_is_play_goback = MMI_TRUE;
                }
                mmi_sndrec_release_stop_btn();
            }                        
        #endif 
            mmi_sndrec_mainscr_rsk_up_hdlr();
            break;

        case MMI_SNDREC_RECORD:
            if (g_sndrec_cntx.record.state != MMI_SNDREC_PLAY_STATE ||
                g_sndrec_cntx.record.state != MMI_SNDREC_PLAY_PAUSE_STATE ||
                g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_STATE ||
                g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_PAUSE_STATE)
            {
                /*area = (mmi_pen_polygon_area_struct*) &skin_p->record_btn_area;
                point.x = pos.x - skin_p->record_btn_x;
                point.y = pos.y - skin_p->record_btn_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                #ifdef __MMI_OP02_LEMEI__
                   if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
                   {
                        mmi_sndrec_release_record_btn_other_app();
                   }
                   else
                   {
                        mmi_sndrec_release_record_btn();
                   }
                #else
                        mmi_sndrec_release_record_btn();
                #endif    
                }*/
                #ifdef __MMI_OP02_LEMEI__
                   if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
                   {
                        mmi_sndrec_release_record_btn_other_app();
                }
                   else
                   {
                        mmi_sndrec_release_record_btn();
                   }
                #else
                        mmi_sndrec_release_record_btn();
                #endif
            }
            break;
            
        case MMI_SNDREC_PLAY:
            /*area = (mmi_pen_polygon_area_struct*) &skin_p->play_btn_area;
            point.x = pos.x - skin_p->play_btn_x;
            point.y = pos.y - skin_p->play_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_release_play_btn();
            }*/
            mmi_sndrec_release_play_btn();
            break;

        case MMI_SNDREC_PREV:
            /*area = (mmi_pen_polygon_area_struct*) &skin_p->prev_btn_area;
            point.x = pos.x - skin_p->prev_btn_x;
            point.y = pos.y - skin_p->prev_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_release_prev_btn();
            }*/
            mmi_sndrec_release_prev_btn();
            break;

        case MMI_SNDREC_NEXT:
            /*area = (mmi_pen_polygon_area_struct*) &skin_p->next_btn_area;
            point.x = pos.x - skin_p->next_btn_x;
            point.y = pos.y - skin_p->next_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_release_next_btn();
            }*/
            mmi_sndrec_release_next_btn();
            break;

    #ifdef __MMI_FTE_SUPPORT__            
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case MMI_SNDREC_LIST:
            /*area = (mmi_pen_polygon_area_struct*) &skin_p->list_btn_area;
            point.x = pos.x - skin_p->list_btn_x;
            point.y = pos.y - skin_p->list_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_release_list_btn();
            }*/
            mmi_sndrec_release_list_btn();
            break;
    #endif
        case MMI_SNDREC_STOP:
            /*area = (mmi_pen_polygon_area_struct*) &skin_p->stop_btn_area;
            point.x = pos.x - skin_p->stop_btn_x;
            point.y = pos.y - skin_p->stop_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_release_stop_btn();
            }*/
            mmi_sndrec_release_stop_btn();
            break;
    #endif/*__MMI_FTE_SUPPORT__*/
    
        default:
            return;
    }
    g_sndrec_main_draw.pen_dn_obj = NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_sndrec_draw_skin_struct *skin_p = g_sndrec_record_skins;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sndrec_main_draw.pen_dn_obj)
    {
        case MMI_SNDREC_LSK:
            if (mmi_pen_check_inside_polygon(&mmi_sndrec_lsk_area, pos))
            {
                mmi_sndrec_redraw_main_lsk_down();
            }
            else
            {
                mmi_sndrec_redraw_main_lsk();
                mmi_sndrec_redraw_play_btn(MMI_FALSE);
                mmi_sndrec_redraw_record_btn(MMI_FALSE);
                mmi_sndrec_redraw_prev_btn(MMI_FALSE);
                mmi_sndrec_redraw_next_btn(MMI_FALSE);
            }
            break;

        case MMI_SNDREC_RSK:
            if (mmi_pen_check_inside_polygon(&mmi_sndrec_rsk_area, pos))
            {
                mmi_sndrec_redraw_main_rsk_down();
            }
            else
            {
                mmi_sndrec_redraw_main_rsk();
                mmi_sndrec_redraw_play_btn(MMI_FALSE);
                mmi_sndrec_redraw_record_btn(MMI_FALSE);
                mmi_sndrec_redraw_prev_btn(MMI_FALSE);
                mmi_sndrec_redraw_next_btn(MMI_FALSE);
            }
            break;

        case MMI_SNDREC_RECORD:
            if (g_sndrec_cntx.record.state != MMI_SNDREC_PLAY_STATE ||
                g_sndrec_cntx.record.state != MMI_SNDREC_PLAY_PAUSE_STATE ||
                g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_STATE ||
                g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_PAUSE_STATE)
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_btn_area;
                point.x = pos.x - skin_p->record_btn_x;
                point.y = pos.y - skin_p->record_btn_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_sndrec_redraw_record_btn(MMI_TRUE);
                }
                else
                {
                    mmi_sndrec_redraw_record_btn(MMI_FALSE);
                }
            }
            break;

        case MMI_SNDREC_PLAY:
            area = (mmi_pen_polygon_area_struct*) & skin_p->play_btn_area;
            point.x = pos.x - skin_p->play_btn_x;
            point.y = pos.y - skin_p->play_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_redraw_play_btn(MMI_TRUE);
            }
            else
            {
                mmi_sndrec_redraw_play_btn(MMI_FALSE);
            }
            break;

        case MMI_SNDREC_PREV:
            area = (mmi_pen_polygon_area_struct*) & skin_p->prev_btn_area;
            point.x = pos.x - skin_p->prev_btn_x;
            point.y = pos.y - skin_p->prev_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_redraw_prev_btn(MMI_TRUE);
            }
            else
            {
                mmi_sndrec_redraw_prev_btn(MMI_FALSE);
            }
            break;

        case MMI_SNDREC_NEXT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->next_btn_area;
            point.x = pos.x - skin_p->next_btn_x;
            point.y = pos.y - skin_p->next_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_redraw_next_btn(MMI_TRUE);
            }
            else
            {
                mmi_sndrec_redraw_next_btn(MMI_FALSE);
            }
            break;

     #ifdef __MMI_FTE_SUPPORT__
        #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case MMI_SNDREC_LIST:    
            area = (mmi_pen_polygon_area_struct*) & skin_p->list_btn_area;
            point.x = pos.x - skin_p->list_btn_x;
            point.y = pos.y - skin_p->list_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_redraw_list_btn(MMI_TRUE);
            }
            else
            {
                mmi_sndrec_redraw_list_btn(MMI_FALSE);
            }
            
            break;
           #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */ 
        case MMI_SNDREC_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->stop_btn_area;
            point.x = pos.x - skin_p->stop_btn_x;
            point.y = pos.y - skin_p->stop_btn_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_sndrec_redraw_stop_btn(MMI_TRUE);
            }
            else
            {
                mmi_sndrec_redraw_stop_btn(MMI_FALSE);
            }
            break;
        #endif/*__MMI_FTE_SUPPORT__*/
        
        default:
            return;
    }
    mmi_sndrec_blt_screen();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#define SNDREC_TIME
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_show_time_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isact       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_show_time_text(MMI_BOOL isact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 timestr[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            mmi_sndrec_get_play_time_string(timestr);
            break;

    #if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
        case MMI_SNDREC_IDLE_STATE:
            if(mmi_sndrec_is_play_flag)
            {
                mmi_sndrec_get_play_time_string(timestr);
            }
            else
            {
                mmi_sndrec_get_record_time_string(timestr);
            }
            break;
    #endif

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
    #if !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
        case MMI_SNDREC_IDLE_STATE:
    #endif
            mmi_sndrec_get_record_time_string(timestr);
            break;

        default:
            ASSERT(0);
    }
    mmi_sndrec_redraw_time_text(timestr, MMI_TRUE);
    if (!isact)
    {
        gui_cancel_timer(mmi_sndrec_update_time_text);
    }
    else
    {
        gui_start_timer(200, mmi_sndrec_update_time_text);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_show_time_text_without_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isact       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_show_time_text_without_blt(MMI_BOOL isact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 timestr[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            mmi_sndrec_get_play_time_string(timestr);
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
        case MMI_SNDREC_IDLE_STATE:
		#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
			if(g_sndrec_wait_next_prev || mmi_sndrec_is_play_flag)
		#else
            if(g_sndrec_wait_next_prev)
		#endif            
            {
                mmi_sndrec_get_play_time_string(timestr);            
            }
            else
            {
                mmi_sndrec_get_record_time_string(timestr);
            }
            break;

        default:
            ASSERT(0);
    }
    
    mmi_sndrec_redraw_time_text(timestr, MMI_FALSE);
    if (!isact)
    {
        gui_cancel_timer(mmi_sndrec_update_time_text);
    }
    else
    {
        gui_start_timer(200, mmi_sndrec_update_time_text);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_update_time_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_update_time_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_time_string(temp);
    if (mmi_ucs2strlen((CHAR *)temp))
    {
        mmi_sndrec_redraw_time_text(temp, MMI_TRUE);
    }
    gui_start_timer(200, mmi_sndrec_update_time_text);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_time_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_redraw_time_text(UI_string_type string, MMI_BOOL isNeedBlt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 str_h;
#ifndef __MMI_VECTOR_FONT_SUPPORT__    
    U32 string_len = 0;
    U32 counter = 0;
    S32 char_width_0 = 0;
    S32 char_width_9 = 0;
    S32 char_max_width = 0;
    S32 char_colon_width = 0;
    S32 char_slash_width = 0;
    S32 offset = 0;
    MMI_BOOL isColon = MMI_FALSE;
    MMI_BOOL isSlash = MMI_FALSE;
    MMI_BOOL isSpace = MMI_FALSE;
#else
    S32 str_w;
#endif
#if defined (__MMI_MAINLCD_320X240__)
	stFontAttribute font_size ;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = g_sndrec_main_draw.time.x + 2;
    y1 = g_sndrec_main_draw.time.y + 1;
    x2 = g_sndrec_main_draw.time.x + g_sndrec_main_draw.time.w - 2;
    y2 = g_sndrec_main_draw.time.y + g_sndrec_main_draw.time.h - 1;
    
    gdi_layer_push_and_set_clip(x1 - 2, y1 - 1, x2 + 2, y2 + 1);
    gdi_draw_solid_rect(x1 - 2, y1 - 1, x2 + 2, y2 + 1, GDI_COLOR_TRANSPARENT);

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	
    #if defined (__MMI_MAINLCD_320X240__)
    memcpy(&font_size, &MMI_small_font, sizeof(stFontAttribute));
    //font_size.size = 5;
    gui_set_font(&font_size);
    #else
    gui_set_font(&MMI_small_font);
    #endif

#else
#ifdef __MMI_MAINLCD_320X480__
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_small_font);
#endif
#endif

    gui_set_text_color(g_sndrec_main_draw.time_color);
    gui_set_text_border_color(g_sndrec_main_draw.time_border_color);

#ifndef __MMI_VECTOR_FONT_SUPPORT__
    string_len = mmi_ucs2strlen((const CHAR*)string);
    MMI_ASSERT(string_len > 0);

    gui_measure_character(L':', &char_colon_width, &str_h);
    gui_measure_character(L'/', &char_slash_width, &str_h);
    gui_measure_character(L'0', &char_width_0, &str_h);	
    gui_measure_character(L'9', &char_width_9, &str_h);
    char_max_width = (char_width_0 >= char_width_9) ? char_width_0 : char_width_9;
    
    for (counter = 0; counter < string_len; counter++)
    {
        isColon = (string[counter] == ':') ? MMI_TRUE : MMI_FALSE; 
        isSlash = (string[counter] == '/') ? MMI_TRUE : MMI_FALSE;
        isSpace = (string[counter] == ' ') ? MMI_TRUE : MMI_FALSE;

        /* move cursor. */
        if (r2lMMIFlag)
        {
            //str_w = string_len * char_max_width;
            if (isColon)
            {
                gui_move_text_cursor(x1 + char_colon_width + offset, y1);
            }
            else if (isSlash)
            {
                gui_move_text_cursor(x1 + char_slash_width + offset, y1);
            }
            else if (isSpace)
            {
                gui_move_text_cursor(x1 + char_slash_width + offset, y1);
            }
            else
            {
                gui_move_text_cursor(x1 + char_max_width + offset, y1);
            }
        }
        else
        {
            
            gui_move_text_cursor(x1 + offset, y1);
        }
        if (!isSpace)
            gui_print_bordered_character(string[counter]);
        
        if (isColon)
        {
            offset += char_colon_width;
        } 
        else if (isSlash)
        {
            offset += char_slash_width;
        }
        else if (isSpace)
        {
            /* For any space do not increase offset and do not draw anything */
            offset += 0;
        }
        else
        {
            offset += char_max_width;
        }
    }    
#else /* __MMI_VECTOR_FONT_SUPPORT__ */
    if (r2lMMIFlag)
    {
        gui_measure_string(string, &str_w, &str_h);
        gui_move_text_cursor(x1 + str_w, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1 + 1);
    }

    gui_print_bordered_text(string);

#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
    gdi_layer_pop_text_clip();

    if (isNeedBlt)
    {
        gdi_layer_blt_previous(x1 - 2, y1 - 1, x2 + 2, y2 + 1); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_redraw_file_name(U16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if(*filename == NULL)
    {
        wcscpy(filename, g_sndrec_main_draw.title.text);
    }
#endif
    
    x1 = g_sndrec_main_draw.filename.x;
    y1 = g_sndrec_main_draw.filename.y;
    x2 = g_sndrec_main_draw.filename.x + g_sndrec_main_draw.filename.w - 1;
    y2 = g_sndrec_main_draw.filename.y + g_sndrec_main_draw.filename.h - 1;

    gui_set_font(&MMI_medium_font);

    gui_scrolling_text_stop(&g_sndrec_main_draw.scroll_text);
    gui_create_scrolling_text(
        &g_sndrec_main_draw.scroll_text,
        x1,
        y1,
        g_sndrec_main_draw.filename.w,
        g_sndrec_main_draw.filename.h,
        filename,
        mmi_sndrec_scroll_filename_handler,
        mmi_sndrec_redraw_filename_background,
        g_sndrec_main_draw.filename_color,
        g_sndrec_main_draw.filename_border_color);
    g_sndrec_main_draw.scroll_text.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

    gdi_layer_push_and_set_clip(x1 - 2, y1 - 1, x2 + 2 , y2 + 1);

    gui_measure_string(g_sndrec_cntx.record.displayname, &str_w, &str_h);

    if (str_w > g_sndrec_main_draw.filename.w)
    {
        gui_change_scrolling_text(&g_sndrec_main_draw.scroll_text, g_sndrec_cntx.record.displayname);
        gui_show_scrolling_text(&g_sndrec_main_draw.scroll_text);
    }
    else
    {
        gui_set_text_color(g_sndrec_main_draw.filename_color);
        gui_set_text_border_color(g_sndrec_main_draw.filename_border_color);
        mmi_sndrec_redraw_filename_background(x1 - 2, y1 - 1, x2 + 2, y2 + 1);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (g_sndrec_main_draw.filename.w + str_w) / 2, y1);
        }
        else
        {
            gui_move_text_cursor(x1 + (g_sndrec_main_draw.filename.w - str_w) / 2, y1);
        }
        gui_set_line_height(str_h);
        gui_print_bordered_text(g_sndrec_cntx.record.displayname);
    }   
    
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_scroll_filename_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_scroll_filename_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_sndrec_main_draw.scroll_text);
}

#ifndef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_scroll_state_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_scroll_state_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_sndrec_main_draw.scroll_text_state);
}
#endif


#ifdef __MMI_SNDREC_SKIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_draw_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_exit_draw_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&g_sndrec_main_draw.scroll_text);
    gui_scrolling_text_stop(&g_sndrec_main_draw.scroll_text_state);
    gdi_set_alpha_blending_source_layer(g_sndrec_layer.oldbldlayer);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SNDREC_DRAW_LAYER, 
                     g_sndrec_layer.oldbldlayer, g_sndrec_layer.skinlayer);
    gdi_image_stop_animation(g_sndrec_main_draw.animal.img_handle);
    gui_cancel_timer(mmi_sndrec_update_time_text);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_redraw_filename_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_redraw_filename_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_time_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_get_time_string(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state ||
        MMI_SNDREC_PREVIEW_STATE == g_sndrec_cntx.record.state)
    {
        mmi_sndrec_get_play_time_string(string);
    }
    else if (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state)
    {
        mmi_sndrec_get_record_time_string(string);
    }
}

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

#endif /*__MMI_SNDREC_SKIN__*/
#endif /*defined(__MMI_SOUND_RECORDER__)*/ 

