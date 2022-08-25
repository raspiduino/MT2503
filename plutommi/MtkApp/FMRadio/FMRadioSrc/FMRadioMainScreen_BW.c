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
*  FMRadioMainScreen_BW.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main screen drawing program
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
#ifdef __MMI_MAINLCD_96X64__


#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_non_specific_general_types.h"
#include "gui_data_types.h"
#include "gui.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "gui_windows.h"
#include "gui_config.h"
#include "ScreenRotationGprot.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "gui_themes.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_font_size.h"
#include "PixcomFontEngine.h"
#include "wgui_categories_multimedia.h"


#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
#include "CustThemesRes.h"
extern MMI_theme *current_MMI_theme;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 

#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__
#include "rf_desense_test.h"
#endif /*__RF_DESENSE_TEST__*/
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __MMI_SLIM_IMG_RES__
#define MMI_FMRDO_SLIM_BG_COLOR  gdi_act_color_from_rgb(255, 248, 248, 248)
#endif /* __MMI_SLIM_IMG_RES__ */

#define MMI_FMRDO_TEXT_HORZ_ACENTER     0x00000001
#define MMI_FMRDO_TEXT_HORZ_ALEFT       0x00000002
#define MMI_FMRDO_TEXT_HORZ_ARIGHT      0x00000004
#define MMI_FMRDO_TEXT_VERT_ACERTER     0x00000010
#define MMI_FMDRO_TEXT_VERT_ATOP        0x00000020
#define MMI_FMRDO_TEXT_VERT_ABOTTOM     0x00000040
#define MMI_FMRDO_TEXT_HAS_BORDER       0x00000100

#define MMI_FMRDO_FLAG_SCROLLING        0x00000001

#define FMRDO_FLAG_SET(f, b)        ((f) |= (b))
#define FMRDO_FLAG_RESET(f, b)      ((f) &= ~(b))
#define FMRDO_FALG_CLEAR(f)         ((f) &= 0 )
#define FMRDO_FLAG_CHECK(f, b)      ((f) & (b))



typedef struct
{
    S32 flag;
#ifdef __MMI_TOUCH_SCREEN__
    S32                         pen_event;
    mmi_pen_point_struct        LSK_points[4];
    mmi_pen_point_struct        RSK_points[4];
    mmi_pen_polygon_area_struct LSK_area;
    mmi_pen_polygon_area_struct RSK_area;
#endif

#ifdef __MMI_FM_RADIO_ANIMATION__
    gdi_handle  anim_layer;
    U8*         anim_layer_buf;
#endif /* __MMI_FM_RADIO_ANIMATION__ */  

#ifdef __MMI_FM_RADIO_RDS__
    U16         rds_str1[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
#endif/*__MMI_FM_RADIO_RDS__*/

} fmrdo_main_draw_cntx;

static fmrdo_main_draw_struct fmrdo_main_draw;  /* all memeber variables are zero initial */

extern mmi_fmrdo_struct g_fmrdo;                    /* defined in FMRadioSrc.c */
extern S32 UI_device_width;                         /* from gui_wrapper.c */
extern S32 UI_device_height;                        /* from gui_wrapper.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
 

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);




/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_main_images
 * DESCRIPTION
 *  Initialize main draw structure for images
 * PARAMETERS
 *  skin_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_main_images(S32 skin_index)
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
 *  mmi_fmrdo_show_main
 * DESCRIPTION
 *  Show skin screen
 * PARAMETERS
 *  left_softkey        [IN]        
 *  right_softkey       [IN]        
 *  skin_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	U8 *guibuffer;
    U16 imgid = 0;
    U16 timeflag = 0;
    U32 duration = 0;
	WCHAR *freq_text = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

	/* draw screen by category */
	guibuffer = mmi_frm_scrn_get_active_gui_buf();
	mmi_fmrdo_redraw_main_channel_name(0);
    freq_text = (WCHAR*)fmrdo_main_draw.channel_name_str;
	if (!mmi_fmrdo_is_power_on())
	{	
        imgid = IMG_ID_FMRDO_SKIN_1_ANIMATION_PAUSE;
	}
    else
    {
        imgid = IMG_ID_FMRDO_SKIN_1_ANIMATION;
    }
	ShowCategory223FMRadioScreen_ext(
			(WCHAR*)GetString(STR_ID_FMRDO_TITLE),
         	(PU8)GetImage((U16)GetRootTitleIcon(MENU_ID_FMRDO_MAIN)),
        	left_softkey,
        	right_softkey,
			imgid,
			freq_text,
		    guibuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hide_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hide_main(void)
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
 *  mmi_fmrdo_util_update_sk_area
 * DESCRIPTION
 *  P0 +------------+ p1
 *     |            |
 *     |            |
 *  p3 +----------- + p2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_update_sk_area(mmi_pen_point_struct *points, S32 x, S32 y, S32 w, S32 h)
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
 *  mmi_fmrdo_util_draw_soft_key
 * DESCRIPTION
 *  Draw soft key function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_draw_soft_key(MMI_BOOL is_lsk, MMI_BOOL is_down)
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
 *  mmi_fmrdo_util_draw_simple_text
 * DESCRIPTION
 *  draw simple text
 * PARAMETERS
 *  button      [IN]        
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_util_draw_simple_text(const fmrdo_main_rect_struct *rect, U16* txt_p, U32 flags)
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
 *  mmi_fmrdo_redraw_main_LSK_down
 * DESCRIPTION
 *  Draw LSK as down on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_LSK_down(void)
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
 *  mmi_fmrdo_redraw_main_RSK_down
 * DESCRIPTION
 *  Draw RSK as down on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_RSK_down(void)
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
 *  mmi_fmrdo_redraw_main_LSK_up
 * DESCRIPTION
 *  Redraw LSK as UP on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_LSK_up(void)
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
 *  mmi_fmrdo_redraw_main_RSK_up
 * DESCRIPTION
 *  Redraw RSK as Up on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_RSK_up(void)
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
 *  mmi_fmrdo_scroll_channel_name_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scroll_channel_name_hdlr(void)
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
 *  mmi_fmrdo_redraw_main_background
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
void mmi_fmrdo_redraw_main_background(S32 x1, S32 y1, S32 x2, S32 y2)
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
 *  mmi_fmrdo_redraw_main_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_all(void)
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
 *  mmi_fmrdo_redraw_main_frequency
 * DESCRIPTION
 *  Redraw frequency on main screen
 * PARAMETERS
 *  freq            [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_frequency(U16 freq, BOOL is_shown)
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
 *  mmi_fmrdo_redraw_main_channel_name
 * DESCRIPTION
 *  Redraw channel name on main screen
 * PARAMETERS
 *  other_str       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_channel_name(UI_string_type other_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    UI_string_type str = NULL;
	UI_character_type prefix_str[] = L"FM ";
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (other_str == NULL)
    {
		str = fmrdo_main_draw.channel_name_str;
        if (g_fmrdo.channel_index >= 0)
        {
            kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
        }
        else
        {
        	kal_wsprintf(str, "%w%d.%d", prefix_str,g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);
        }
    }
    else
    {
        str = other_str;
    }
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_title
 * DESCRIPTION
 *  Redraw channel name on main screen
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#ifdef __MMI_FM_RADIO_RDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_name
 * DESCRIPTION
 *  Redraw channel name on main screen
 * PARAMETERS
 *  other_str       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_redraw_main_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.rds_text.x;
    S32 y1 = fmrdo_main_draw.rds_text.y;
    S32 x2 = fmrdo_main_draw.rds_text.x + fmrdo_main_draw.rds_text.w - 1;
    S32 y2 = fmrdo_main_draw.rds_text.y + fmrdo_main_draw.rds_text.h - 1;
    S32 str_w, str_h;
    UI_string_type str;
    UI_font_type rds_font = gui_font_get_type(GUI_FONT_SIZE_TITLE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_REDRAW_MAIN_TEXT_ENTRY);
    if(mmi_fmrdo_rds_is_on() && g_fmrdo.is_power_on)
    {
    str = fmrdo_main_draw.rds_text_str;
    if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
    {
        kal_wsprintf(str, "%w. %w", g_fmrdo.rds.prog_name, g_fmrdo.rds.radio_text);    
    }
    else if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
    {
         kal_wsprintf(str, "%w", g_fmrdo.rds.prog_name);
    }
    else if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
    {
         kal_wsprintf(str, "%w",g_fmrdo.rds.radio_text);
    }
    else
    {
        str[0] = 0;
    }
    if(mmi_ucs2cmp((CHAR *)fmrdo_draw_cntx_p->rds_str1, (CHAR *)str) != 0)
    {
        mmi_ucs2cpy((CHAR *)fmrdo_draw_cntx_p->rds_str1, (CHAR *)str);
    }
    else
    {
        if(mmi_ucs2cmp((CHAR *)str, (CHAR *)"") != 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_REDRAW_MAIN_TEXT_BOTH_STRINGS_SAME);
            return;
        }
    }
    /* stop previous scroll text */
    if (!fmrdo_main_draw.is_rds_text_scroll_ready)
    {
        gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
    }
    else
    {
        fmrdo_main_draw.is_rds_text_scroll_ready = TRUE;
    }

    gui_create_scrolling_text(
        &fmrdo_main_draw.rds_text_scroll,
        x1 + 2,
        y1 + 1,
        fmrdo_main_draw.rds_text.w - 4,
        fmrdo_main_draw.rds_text.h - 2,
        str,
        mmi_fmrdo_scroll_rds_text_hdlr,
        mmi_fmrdo_redraw_main_background,
        fmrdo_main_draw.rds_text_color,
        fmrdo_main_draw.rds_text_border_color);
    fmrdo_main_draw.rds_text_scroll.text_font = *rds_font;
    fmrdo_main_draw.rds_text_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    /* stop scrolling if necessary */
    gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);

    gui_set_font(rds_font);
    gui_measure_string(str, &str_w, &str_h);

    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);

    /* text */
    if (str_w > fmrdo_main_draw.rds_text.w - 4)
    {
        /* scrolling */
        gui_change_scrolling_text(&fmrdo_main_draw.rds_text_scroll, str);
        gui_set_text_color(fmrdo_main_draw.rds_text_color);
        gui_set_text_border_color(fmrdo_main_draw.rds_text_border_color);
        gui_show_scrolling_text(&fmrdo_main_draw.rds_text_scroll);
    }
    else
    {
        /* no scrolling */
        gui_set_text_color(fmrdo_main_draw.rds_text_color);
        gui_set_text_border_color(fmrdo_main_draw.rds_text_border_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.rds_text.w + str_w) / 2,
                y1 + (fmrdo_main_draw.rds_text.h - str_h) / 2);
        }
        else
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.rds_text.w - str_w) / 2,
                y1 + (fmrdo_main_draw.rds_text.h - str_h) / 2);
        }
        gui_print_bordered_text(str);
    }

    gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
#endif 
    }
    else
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(TRUE);
    #endif 
        gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
    #ifndef __GDI_MEMORY_PROFILE_2__ 
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);
    #endif 
    #ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(FALSE);
    #endif 
    }
    gdi_layer_blt_previous(x1, y1, x2, y2);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scroll_channel_name_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scroll_rds_text_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
#endif 
    gui_handle_scrolling_text(&fmrdo_main_draw.rds_text_scroll);
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
#endif 
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_push_button
 * DESCRIPTION
 *  Redraw push buttons on main screen
 * PARAMETERS
 *  button      [IN]        
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_redraw_main_ind(U8 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_ind_struct *ind_button_p = NULL;
    S32 x1, y1, x2, y2;
    PU8 draw_img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_RDS_REDRAW_MAIN_IND_IND_RECEIVED,ind);
    switch (ind)
    {
        case FMRDO_RDS_IND_MAIN:
            ind_button_p = &fmrdo_main_draw.rds_ind;
            if(((g_fmrdo.rds.status_mask & RT_RECIEVE) || (g_fmrdo.rds.status_mask & PS_RECIEVE) || (g_fmrdo.rds.status_mask & TP_RECIEVE) || (g_fmrdo.rds.status_mask & AF_RECIEVE)) && (g_fmrdo.rds.rds_setting.is_rds_on))/*ps name recieved or rt recieved through flags*/
            {
                draw_img = ind_button_p->up_img;
            }
            else if (g_fmrdo.rds.rds_setting.is_rds_on)
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                draw_img = ind_button_p->dis_img;
            }
            break;
        case FMRDO_RDS_IND_TP:
            ind_button_p = &fmrdo_main_draw.tp_ind;
            if((g_fmrdo.rds.status_mask & TP_RECIEVE) && g_fmrdo.rds.rds_setting.is_tp_on)
            {
                draw_img = ind_button_p->up_img;
            }
            else if(g_fmrdo.rds.rds_setting.is_tp_on)
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                draw_img = ind_button_p->dis_img;
            }
            break;
        case FMRDO_RDS_IND_AF:
            ind_button_p = &fmrdo_main_draw.af_ind;
            if(g_fmrdo.rds.status_mask & AF_RECIEVE && g_fmrdo.rds.rds_setting.is_af_on)
            {
                draw_img = ind_button_p->up_img;
            }
            else if(g_fmrdo.rds.rds_setting.is_af_on)
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                draw_img = ind_button_p->dis_img;
            }
            break;
        default:
            return;
    }

    x1 = ind_button_p->x;
    y1 = ind_button_p->y;
    x2 = ind_button_p->x + ind_button_p->w - 1;
    y2 = ind_button_p->y + ind_button_p->h - 1;

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    /* button */
    gui_show_image(x1, y1, draw_img);
    gdi_layer_pop_clip();
    
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
#endif 

    gdi_layer_blt_previous(x1, y1, x2, y2);
}
#endif /*__MMI_FM_RADIO_RDS__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_tuner
 * DESCRIPTION
 *  Redraw tuner on main screen
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_channel_tuner(U16 freq)
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
 *  mmi_fmrdo_redraw_main_volume
 * DESCRIPTION
 *  Redraw volume indicator on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_volume(void)
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
 *  mmi_fmrdo_restore_main_SK
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for restore back to play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_restore_main_SK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_twinkle_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_twinkle_searching(BOOL is_shown)
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
 *  mmi_fmrdo_change_main_SK_hw_searching
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_main_SK_hw_searching(void)
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
 *  mmi_fmrdo_clear_main_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_clear_main_RSK(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}



#endif /* __FM_RADIO_HW_SEARCH__ */ 

#endif /* __MMI_MAINLCD_96X64__ */
#endif /* __MMI_FM_RADIO__ */ 

