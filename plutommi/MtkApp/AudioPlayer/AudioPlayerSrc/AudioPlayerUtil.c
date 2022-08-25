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
*   AudioPlayerUtil.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player's external API which used without audio player compile option.
*
* Author:
* -------
*  
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#include "mdi_datatype.h"
#include "CommonScreens.h"
#include "mdi_audio.h"

#include "AudioPlayerResDef.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerPlayList.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "CommonScreensResDef.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_prof_def.h"

#if defined(__MMI_AUDIO_PLAYER__)
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gui_windows.h"
#include "gui_data_types.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "fs_type.h"
#include "gdi_include.h"
#include "gui_config.h"
#include "gui_themes.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
//#include "GeneralDeviceGprot.h"
#include "string.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_audioplayer_def.h"


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gui_spectrum.h"
#endif 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
//#include "gpioInc.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "gpiosrvgprot.h"
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
#include "lyrics_parser.h"
#endif
/*extern global variables*/
extern GDI_HANDLE audply_skin_layer;
extern GDI_HANDLE audply_osd_layer;
extern scrolling_text audply_main_scrolling_title;
#if defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && defined(__MMI_AUDIO_PLAYER__)
static U16 option_texts[7]; 
static S32 selected_random_mode;
#endif
extern MMI_BOOL g_audply_main_selected_button_down;
extern MMI_BOOL g_mmi_audply_init_done;
extern MMI_BOOL g_mmi_audply_play_completed_after_button_down;
#ifdef __MMI_FM_RADIO__
extern void mmi_fmrdo_power_on(BOOL turn_on);
#endif  /* __MMI_FM_RADIO__ */
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
/* for regenerate/refresh list */
extern MMI_BOOL need_refresh_list; 
extern MMI_BOOL need_reload_list;
#endif


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
spectrum_struct g_aud_ply_spectrum;
static MMI_BOOL is_spectrum_calc_on = MMI_FALSE;
extern MMI_BOOL g_audply_spectrum_blocked;
//extern BOOL mmi_gpio_is_lcd_sleep(void);
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
mmi_audply_lyrics_box_struct g_audply_lyrics_box;
lyrics_meta_struct*  g_audply_lyrics = NULL;
static  void mmi_audply_config_lyrics(void);
static  void mmi_audply_parse_lyrics(void);
#endif


#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
#if !defined(__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__)
__align(2) CHAR g_mmi_lyric_str_buff[AUDPLY_LYRIC_STR_BUFF_MAX_SIZE];
#else
CHAR *g_mmi_lyric_str_buff = NULL;
#endif /*__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__*/
audply_lyric_struct audply_lyric;
audply_lyric_printing_struct audply_lyric_print;
scrolling_text audply_scrolling_lyric1;
scrolling_text *audply_scrolling_lyric_p1 = NULL;
MMI_BOOL lyric_reEntry = MMI_FALSE; 
MMI_BOOL lyric_parse_ok = MMI_FALSE;
static MMI_BOOL lyric_backlight_has_turn_on = MMI_FALSE;
static MMI_BOOL lyric_full = MMI_FALSE;
extern U8 PhnsetGetDefEncodingType(void);
#ifndef __MMI_SUBLCD__
extern bitmap *current_LCD_device_bitmap;   /* defined in wgui.c */
extern bitmap main_LCD_device_bitmap;       /* defined in wingui.c */
extern bitmap sub_LCD_device_bitmap;        /* defined in wingui.c */
#endif /* __MMI_SUBLCD__ */ 
#ifdef __GDI_MEMORY_PROFILE_2__
extern GDI_HANDLE audply_osd_layer;      /* defined in AudioPlayerMainScren.c */
#endif /*__GDI_MEMORY_PROFILE_2__*/
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */

static void (*mmi_audply_pop_callback)(void) = NULL;
static void (*mmi_audply_pop_intercallback)(void) = NULL;

extern audply_struct g_audply;

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
extern audply_main_spec_animation_struct audply_spec_animation;
#endif



#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_calc_spectrum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_calc_spectrum(MMI_BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_spectrum_calc_on)
    {
        if (!on)
        {
            mdi_audio_stop_calc_spectrum();
        }
    }
    else
    {
        if (on)
        {
            mdi_audio_start_calc_spectrum();
        }
    }
    is_spectrum_calc_on = on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_turn_on_spectrum
 * DESCRIPTION
 *  called when back light is truned on.
 * IMPACT
 *  start calcting specturm and drawing spectrum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_audply_turn_on_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.spectrum_style != 0 &&
        mmi_audply_is_spectrum_valid() &&
        !g_audply_spectrum_blocked)
    {
        if (g_audply.state == STATE_PLAY)
        {
            if (g_audply.in_main_screen)
            {
                mmi_audply_calc_spectrum(MMI_TRUE);
                mmi_audio_spectrum_init_display(&g_aud_ply_spectrum);
                mmi_audio_spectrum_start_display(&g_aud_ply_spectrum);
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_turn_off_spectrum
 * DESCRIPTION
 *  called when back light is truned off.
 * IMPACT
 *  stop calcing specturm and stop drawing spectrum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_audply_turn_off_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.spectrum_style != 0)
    {
        if (g_audply.state == STATE_PLAY)
        {
            mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum);
            mmi_audply_calc_spectrum(MMI_FALSE);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_spectrum_display_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_spectrum_display_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    gdi_handle base_handle;
    S32 x1, y1, x2, y2;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_SPECTRUM_DISPLAY_START);
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    x1 = audply_spec_animation.x;
    y1 = audply_spec_animation.y;
    x2 = x1 + audply_spec_animation.w;
    y2 = y1 + audply_spec_animation.h;

/* start calc top and vals */
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif

    mmi_audply_get_base_screen_handle(&base_handle);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(base_handle);
#endif  

    gui_push_clip();
    gdi_image_stop_animation_all();
    gdi_layer_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_BLACK);

#endif /* MMI_FTE_SUPPORT*/
    
    /* start calc top and vals */
    mmi_audply_calc_spectrum(MMI_TRUE);
    mmi_audio_spectrum_init_display(&g_aud_ply_spectrum);
    mmi_audio_spectrum_start_display(&g_aud_ply_spectrum);

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */
#endif  /* MMI_FTE_SUPPORT*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_spectrum_display_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_spectrum_display_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
	gdi_handle base_handle;
	S32 x1, y1, x2, y2;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_SPECTRUM_DISPLAY_STOP);

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    x1 = audply_spec_animation.x;
    y1 = audply_spec_animation.y;
    x2 = x1 + audply_spec_animation.w;
    y2 = y1 + audply_spec_animation.h;


#endif
#if !defined(__MMI_SUBLCD__)
    /* stop calc top and vals */
    mmi_audply_calc_spectrum(MMI_FALSE);
#endif /* !defined(__MMI_SUBLCD__) */ 
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif

    mmi_audply_get_base_screen_handle(&base_handle);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(base_handle);
#endif 

    gui_push_clip();
#endif /* MMI_FTE_SUPPORT*/

    mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum);

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)


    gdi_layer_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_BLACK);

    if (g_audply.state != STATE_PLAY)
    {
        mmi_audply_redraw_animation();
    }
    gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */


#endif/* MMI_FTE_SUPPORT*/
}
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 




#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
static MMI_BOOL mmi_audply_parse_lyric(U16 *cur_char);
static MMI_BOOL mmi_audply_lrc_FS_Read_one_line(
                            FS_HANDLE handle,
                            CHAR *temp_buf_pool,
                            const U32 temp_buf_pool_size,
                            U32 *read_size,
                            mmi_chset_enum lrc_encoding_chset,
                            audply_UCS2_encode_enum BL);
static void mmi_audply_redraw_lyric_background(S32 x1, S32 y1, S32 x2, S32 y2);
static S32 UCS2StrMatch(const CHAR *strSrc, const CHAR *break_chars, S32 matchs_count, CHAR **strMatchs);
static mmi_chset_enum mmi_audply_lrc_encoding_type(const CHAR *str, audply_UCS2_encode_enum *BL);
static void mmi_audply_clear_lyric_context(void);
static void mmi_audply_lyric_post_process(CHAR *src, U32 total_size);
static void mmi_audply_lyric_UCS2_memcpy(CHAR *dest, CHAR *src, U32 total_size, audply_UCS2_encode_enum BL);
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stop_scroll_lyric_and_clean_screen
 * DESCRIPTION
 *  to stop the scrolling lyric and replace with transparent color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stop_scroll_lyric_and_clean_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.lyrics_display &&
        g_audply.in_main_screen &&
        mmi_audply_is_lyrics_valid()
       )
    {
        /* clean the screen */
        if (audply_scrolling_lyric_p1)
        {
            gui_scrolling_text_stop(audply_scrolling_lyric_p1);
            audply_scrolling_lyric_p1 = NULL;
        }
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_push_and_set_active(audply_lyric_print.target_layer);
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_lock_frame_buffer();
    #endif 
        gdi_layer_push_and_set_clip(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);
        mmi_audply_redraw_lyric_background(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);

        gdi_layer_pop_clip();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_lyric_background
 * DESCRIPTION
 *  redraw audio player lyric  background
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_redraw_lyric_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_scroll_lyric_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_scroll_lyric_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_scrolling_lyric_p1)
    {
        gui_handle_scrolling_text(audply_scrolling_lyric_p1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_lyric
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_lyric(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #ifdef __MMI_SUBLCD__
    if (audply_lyric.is_ready && audply_lyric.cur_line)
    {
        S32 x, y;           /* the cursor position */
        S32 str_w, str_h;   /* the lyric width and height */
        audply_lyric_line_struct *cur_line = audply_lyric.cur_line;
        bitmap *saved_graphics_context = current_LCD_device_bitmap; //bql: the meaning and relationship with __MMI_AUDIO_PLAYER_ON_SUBLCD__

    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_push_and_set_active(audply_lyric_print.target_layer);
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_lock_frame_buffer();
    #endif 

        gdi_layer_push_and_set_clip(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);

        if (audply_scrolling_lyric_p1)  /* if there is some scroll lyric, make it stop no matter how. */
        {
            gui_scrolling_text_stop(audply_scrolling_lyric_p1);
            audply_scrolling_lyric_p1 = NULL;
        }

        if (cur_line->line_lyric1)
        {
            gui_set_font(&MMI_medium_font);
            gui_measure_string((UI_string_type) cur_line->line_lyric1, &str_w, &str_h);
            y = audply_lyric_print.start_y + audply_lyric_print.height / 2 - str_h / 2;
            y = y-2 ; /*for bordered*/
            x = audply_lyric_print.start_x + 2  ;  /* +2 to prevent bordered char from exceeding the edge*/

            mmi_audply_redraw_lyric_background(
                audply_lyric_print.start_x,
                audply_lyric_print.start_y,
                audply_lyric_print.start_x + audply_lyric_print.width,
                audply_lyric_print.start_y + audply_lyric_print.height);

            if (str_w <= audply_lyric_print.width - 2)
            {
                S32 temp_x;

                /* y+4 for bordered lyrics */
                gdi_layer_push_and_set_clip(x, y, x + audply_lyric_print.width, y + str_h + 4);
                gui_set_text_color(audply_lyric_print.lyric_fg_color);
                gui_set_text_border_color(audply_lyric_print.lyric_border_color);
                #ifdef __MMI_BIDI_ALG__
                if (r2lMMIFlag)
                {
                    temp_x = x + (audply_lyric_print.width + str_w) / 2;
                }
                else
                #endif
                {
                    temp_x = x + (audply_lyric_print.width - str_w) / 2;
                }
                gui_move_text_cursor(temp_x, y+2);
                gui_print_bordered_text((UI_string_type) cur_line->line_lyric1);
                gdi_layer_pop_clip();
            }
            else    /* scroll */
            {
                audply_scrolling_lyric_p1 = &audply_scrolling_lyric1;
                gui_create_scrolling_text(
                    audply_scrolling_lyric_p1,
                    x,
                    y+2,
                    audply_lyric_print.width-4,   /* -4 to prevent bordered wrods from exceeding the edge*/
                    str_h,
                    (UI_string_type) cur_line->line_lyric1,
                    mmi_audply_scroll_lyric_handler,
                    mmi_audply_redraw_lyric_background,
                    audply_lyric_print.lyric_fg_color,
                    audply_lyric_print.lyric_border_color);

                audply_scrolling_lyric_p1->text_font = MMI_medium_font;
                audply_scrolling_lyric_p1->scroll_size = 3; /* the pixel number of each scroll action. */
                audply_scrolling_lyric_p1->scroll_time = 150;   /* in ms. the time between each scroll action. */
                audply_scrolling_lyric_p1->scroll_pause = 5;    /* the pause time after showing the lyric and strat to scroll.
                                                                   the time is scroll_time*scroll_pause ; */
                audply_scrolling_lyric_p1->flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
                /* audply_scrolling_lyric_p1->scroll_gap = 32 ;  */
                /* while the whole lyric is scroll over, it should re-appear by scrolling out.
                   this is the gap in pixels between the re-appear scrolling out */
                gui_show_scrolling_text(audply_scrolling_lyric_p1);

            }
        }
        else
        {
            mmi_audply_redraw_lyric_background(
                audply_lyric_print.start_x,
                audply_lyric_print.start_y,
                audply_lyric_print.start_x + audply_lyric_print.width,
                audply_lyric_print.start_y + audply_lyric_print.height);
        }

        gdi_layer_pop_clip();

    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
        //bql: should we consider to wrap it under compile option of __MMI_AUDIO_PLAYER_ON_SUBLCD__
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_on_time
 * DESCRIPTION
 *  called during every update_play_seconds() to manipulate the whole action of audply lyrics.
 * PARAMETERS
 *  void
 *  BOOL is_show(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lyric_on_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_lyric.is_ready && audply_lyric.cur_line)
    {
        S32 next_line_time = 0;
        S32 play_time = mmi_audply_get_play_seconds() - audply_lyric.offset_time;
        audply_lyric_line_struct *cur_line = audply_lyric.first_line;

        if (audply_lyric.cur_line->next)
        {
            next_line_time = audply_lyric.cur_line->next->time;
        }
        else
        {
            next_line_time = 0xffffff;
        }
        if (play_time >= audply_lyric.cur_line->time && play_time < next_line_time)
        {
            if (!lyric_reEntry)
            {
                return;
            }
            else
            {
                lyric_reEntry = MMI_FALSE;
            }
        }
        
        if (play_time < audply_lyric.first_line->time)
        {
            return;
        }
        
        while (cur_line)
        {
            if (cur_line->next)
            {
                if (play_time >= cur_line->time && play_time < cur_line->next->time)
                {
                    audply_lyric.cur_line = cur_line;
                    //bql: the reason to update a stack variable in the while loop without any usage?
                    next_line_time = cur_line->next->time;
                    break;
                }
                else
                {
                    cur_line = cur_line->next;
                }
            }
            else
            {
                audply_lyric.cur_line = cur_line;
                //bql: the reason to update a stack variable in the while loop without any usage?
                next_line_time = 0xffffff;
                break;
            }
        }
        //bql: strage logs to record new_play_time which seems not changed in current logic.
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_RRINT_LYRICS,g_audply.new_play_time);
        mmi_audply_redraw_lyric();
    }
}


/*****************************************************************************
 * FUNCTION
 *  UCS2StrMatch
 * DESCRIPTION
 *  For lyric parse string
 * PARAMETERS
 *  strSrc              [IN]        
 *  break_chars         [IN]        
 *  matchs_count        [IN]        
 *  strMatchs           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 UCS2StrMatch(const CHAR *strSrc, const CHAR *break_chars, S32 matchs_count, CHAR **strMatchs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset, i;
    U16 *src = (U16*) strSrc;
    S32 src_length = mmi_ucs2strlen(strSrc);
    S32 break_chars_length = mmi_ucs2strlen(break_chars);
    U16 **matchs = (U16 **) strMatchs;
    CHAR *is_matching = (CHAR*)OslMalloc(matchs_count);
    CHAR *matchs_length = (CHAR*)OslMalloc(matchs_count);


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < matchs_count; i++)
    {
        is_matching[i] = 1;
        matchs_length[i] = mmi_ucs2strlen(strMatchs[i]);
    }

    for (offset = 0; offset < src_length; offset++)
    {
        MMI_BOOL no_match_all = MMI_TRUE;

        for (i = 0; i < matchs_count; i++)
        {
            if (!is_matching[i])    /* not match */
            {
                continue;
            }
            no_match_all = MMI_FALSE;
            if (offset == matchs_length[i])
            {
                S32 x = 0;

                for (; x < break_chars_length; x++)
                {
                    if (src[offset] == ((U16*) break_chars)[x])
                    {
                        OslMfree(is_matching);
                        OslMfree(matchs_length);
                        return i;   /* match */
                    }
                }
                is_matching[i] = 0;
            }
            else if (matchs[i][offset] != src[offset])
            {
                is_matching[i] = 0;
            }
        }
        if (no_match_all)
        {
            OslMfree(is_matching);
            OslMfree(matchs_length);
            return -1;
        }
    }
    OslMfree(is_matching);
    OslMfree(matchs_length);
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_check_backlight
 * DESCRIPTION
 *  check if the backlight should be turned on for displaying lyric.
 *  conditions to fit : 1. under play state
 *  2. lyrics_display == 1
 *  3. lyric parse ok
 *  4. in audply main screen
 * PARAMETERS
 *  on      [IN]        Boolean to check turn on or turn off.  on:1, off:0
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lyric_check_backlight(MMI_BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!on && lyric_backlight_has_turn_on)    /* to turn off backlight */
    {
        srv_backlight_turn_off();
        lyric_backlight_has_turn_on = MMI_FALSE;
    }
    else if (on && !lyric_backlight_has_turn_on)    /* to turn on backlight while displaying lyric */
    {
        if (g_audply.state == STATE_PLAY &&
            g_audply.lyrics_display &&
            lyric_parse_ok && 
            g_audply.in_main_screen &&
            mmi_audply_is_lyrics_valid())
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
            lyric_backlight_has_turn_on = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lrc_encoding_type
 * DESCRIPTION
 *  check if the lrc is an Unicode encoded file or the user specified encoded file.
 * PARAMETERS
 *  str     [IN]        Pointer to the text source.
 *  BL      [OUT]       A number to verify big or little indian
 * RETURNS
 *  a mmi_chset_enum that sprcifies UTF8/UCS2/User Specified  encoded type.
 *****************************************************************************/
static mmi_chset_enum mmi_audply_lrc_encoding_type(const CHAR *str, audply_UCS2_encode_enum *BL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //bql: why only need to check the first 3 Byte to determine encode type? 
    //Or else, does it mean that user specified encoded byte for this file with the first 3 Byte?
    if (str[0] == (CHAR) 0xEF && str[1] == (CHAR) 0xBB && str[2] == (CHAR) 0xBF)
    {
        *BL = NON_UCS2;
        return MMI_CHSET_UTF8;
    }
    else if (str[0] == (CHAR) 0xFE && str[1] == (CHAR) 0xFF)
    {
        *BL = UCS2_BIG_ENDIAN;
        return MMI_CHSET_UCS2;
    }
    else if (str[0] == (CHAR) 0xFF && str[1] == (CHAR) 0xFE)
    {
        *BL = UCS2_LITTLE_ENDIAN;
        return MMI_CHSET_UCS2;
    }
    else
    {
        *BL = NON_UCS2;
        return (mmi_chset_enum)PhnsetGetDefEncodingType();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stop_lyric
 * DESCRIPTION
 *  called when audio playing is stopped
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stop_lyric(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean the scrolling screen. */
    mmi_audply_stop_scroll_lyric_and_clean_screen();
    audply_lyric.is_ready = MMI_FALSE;
    lyric_parse_ok = MMI_FALSE;
    mmi_audply_lyric_check_backlight(MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_clear_lyric_context
 * DESCRIPTION
 *  Clear all lyric context and set audply_lyric.is_ready to FALSE.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_clear_lyric_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_scrolling_lyric_p1)
    {
        gui_scrolling_text_stop(audply_scrolling_lyric_p1);
        audply_scrolling_lyric_p1 = NULL;
    }
    memset(g_mmi_lyric_str_buff, 0, AUDPLY_LYRIC_STR_BUFF_MAX_SIZE);
    memset(&audply_lyric, 0, sizeof(audply_lyric_struct));
    lyric_full = MMI_FALSE;
    audply_lyric.is_ready = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_post_process
 * DESCRIPTION
 *  If  the string buffer pool is not large enough, the string might ended in the middle of a
 *  lyrics line.which indicates that it is not ended in '\n' nor '\t'. the parser only takes the
 *  lyrics ended with '\n' or '\t'. this function try to take care of it.
 * PARAMETERS
 *  src             [?]         
 *  total_size      [IN]        in bytes
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_lyric_post_process(CHAR *src, U32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_length = 0;
    CHAR *temp_src = src + total_size - 2;    /* subtract by 2 because it is 2 byte aligned. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U16* temp_src = (U16*)src + (total_size/2) -1  ; */
    if (mmi_ucs2find(temp_src, (CHAR*) L"\r\n", &num_length, -1) == 1)
    {
        temp_src -= num_length * 2;
        memset(temp_src + 2, 0, num_length * 2);
    }
    else
    {
        src[total_size - 1] = 0x00;
        src[total_size - 2] = '\n';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_UCS2_memcpy
 * DESCRIPTION
 *  If  the string buffer pool is not large enough, the string might ended in the middle of a
 *  lyrics line.which indicates that it is not ended in '\n' nor '\t'. the parser only takes the
 *  lyrics ended with '\n' or '\t'. this function try to take care of it.
 * PARAMETERS
 *  dest            [?]         
 *  src             [?]         
 *  total_size      [IN]        in bytes
 *  BL              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_lyric_UCS2_memcpy(CHAR *dest, CHAR *src, U32 total_size, audply_UCS2_encode_enum BL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (BL == UCS2_LITTLE_ENDIAN)
    {
        memcpy(dest, src, total_size);
    }
    else if (BL == UCS2_BIG_ENDIAN)
    {
        U32 i;
        //bql: there must be some common knowledge that i do not reached for BIG5

        for (i = 0; i < total_size; i += 2)
        {
            *(dest + i) = *(src + i + 1);
            *(dest + i + 1) = *(src + i);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lrc_FS_Read_one_line
 * DESCRIPTION
 *  read a line from FS into a temp buffer
 *  1. if the buffer is not large enough : append '\n' in the end of it and seek for real '\n' in the FS
 *  2. if the buffer is larger than one line : seek for first '\n' in FS
 * IMPACT
 *  when it is successfully parsed, it'll set audply_lyric.is_ready to TRUE.
 *  otherwise, it is reset to FALSE by calling mmi_audply_clear_lyric().
 * PARAMETERS
 *  handle                  [IN]        File handle for FS
 *  temp_buf_pool           [IN]        Temp buffer bool to store the read chars from FS
 *  temp_buf_pool_size      [IN]        Max size for one line
 *  read_size               [OUT]       The real read size for one line
 *  lrc_encoding_chset      [IN]        
 *  BL                      [IN]        To indicate big or little endian
 * RETURNS
 *  return TRUE if it's successfully read; otherwise, return FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_audply_lrc_FS_Read_one_line(
                                        FS_HANDLE handle,
                                        CHAR *temp_buf_pool,
                                        const U32 temp_buf_pool_size,
                                        U32 *read_size,
                                        mmi_chset_enum lrc_encoding_chset,
                                        audply_UCS2_encode_enum BL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_Read(handle, temp_buf_pool, temp_buf_pool_size, read_size) < 0)
    {
        return MMI_FALSE;
    }
    else if (*read_size != 0)
    {
        U32 i;
        U32 line_len;
        U32 read_over_total_line_len = 0;
        MMI_BOOL found = MMI_FALSE;

        for (i = 0; i < *read_size; i++)
        {
            if (lrc_encoding_chset == MMI_CHSET_UCS2)
            {
                if (BL == UCS2_LITTLE_ENDIAN)
                {
                    if (temp_buf_pool[i] == '\n' && temp_buf_pool[i + 1] == 0)
                    {
                        found = MMI_TRUE;
                        break;
                    }
                }
                else if (BL == UCS2_BIG_ENDIAN)
                {
                    if (temp_buf_pool[i] == 0 && temp_buf_pool[i + 1] == '\n')
                    {
                        found = MMI_TRUE;
                        break;
                    }
                }
                i++;
            }
            else
            {
                if (temp_buf_pool[i] == '\n')
                {
                    found = MMI_TRUE;
                    break;
                }
            }
        }

        if (found)
        {
            /* if found, i will not be added by for loop. */
            line_len = i + 1;
            /* make it 2 byte aligned. */
            if (lrc_encoding_chset == MMI_CHSET_UCS2)
            {
                line_len++;
            }
        }
        else
        {
            line_len = i;
        }
        /* reach the end of file */
        if ((line_len < *read_size) || (line_len == *read_size && found))
        {
            /* seek back to the end of first line */
            FS_Seek(handle, line_len - *read_size, FS_FILE_CURRENT);
            /* replace with zero value till the end of temp_buf */
            memset(temp_buf_pool + line_len, 0, *read_size - line_len);
        }
        else    /* line_len == *read_size || !found */
        {
            CHAR *read_over_buf = NULL;
            const U32 read_over_buf_size = 256;
            U32 read_over_read_size;
            U32 j, read_over_line_len;
            U32 read_over_total_size = 0;

            if ((read_over_buf = OslMalloc(read_over_buf_size)) == NULL)
            {
                //Will never run into
                return MMI_FALSE;
            }
            else
            {
                memset(read_over_buf, 0, read_over_buf_size);
            }

            if(temp_buf_pool_size-line_len>=2)
            {
                line_len += 2 ;
                *read_size = line_len;
            }

            if (BL == UCS2_LITTLE_ENDIAN)
            {
                temp_buf_pool[line_len - 1] = 0;
                temp_buf_pool[line_len - 2] = '\n';

            }
            else if (BL == UCS2_BIG_ENDIAN)
            {
                temp_buf_pool[line_len - 1] = '\n';
                temp_buf_pool[line_len - 2] = 0;
            }
            else
            {
                temp_buf_pool[line_len - 2] = '\n';
                temp_buf_pool[line_len - 1] = 0;
            }

            found = MMI_FALSE;
            do
            {
                if (FS_Read(handle, read_over_buf, read_over_buf_size, &read_over_read_size) < 0)
                {
                    OslMfree(read_over_buf);
                    return MMI_FALSE;
                }

                if (!read_over_read_size)   /* end of file */
                {
                    OslMfree(read_over_buf);
                    return MMI_TRUE;
                }
                else
                {
                    for (j = 0; j < read_over_read_size; j++)
                    {
                        if (lrc_encoding_chset == MMI_CHSET_UCS2)
                        {
                            if (BL == UCS2_LITTLE_ENDIAN)
                            {
                                if (read_over_buf[j] == '\n' && read_over_buf[j + 1] == 0)
                                {
                                    found = MMI_TRUE;
                                    break;
                                }
                            }
                            else if (BL == UCS2_BIG_ENDIAN)
                            {
                                if (read_over_buf[j] == 0 && read_over_buf[j + 1] == '\n')
                                {
                                    found = MMI_TRUE;
                                    break;
                                }
                            }
                            j++;
                        }
                        else
                        {
                            if (read_over_buf[j] == '\n')
                            {
                                found = MMI_TRUE;
                                break;
                            }
                        }

                    }
                    read_over_line_len = j + 1;

                    /* make it 2 byte aligned */
                    if (lrc_encoding_chset == MMI_CHSET_UCS2)
                    {
                        read_over_line_len++;
                    }

                    read_over_total_line_len += read_over_line_len;
                    read_over_total_size += read_over_read_size;
                }
                /* haven't reach the end */
            } while (read_over_line_len >= read_over_read_size && !found);
            OslMfree(read_over_buf);
            FS_Seek(handle, read_over_total_line_len - read_over_total_size, FS_FILE_CURRENT);
        }
        *read_size = line_len;  /* + read_over_total_line_len ; */
        return MMI_TRUE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_lyric
 * DESCRIPTION
 *  Init and parse lyric
 * IMPACT
 *  when it is successfully parsed, it'll set audply_lyric.is_ready to TRUE.
 *  otherwise, it is reset to FALSE by calling mmi_audply_clear_lyric().
 * PARAMETERS
 *  void
 * RETURNS
 *  return TRUE if it's successfully parsed; otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_audply_init_lyric(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    UI_character_type *file_name_end = NULL, *temp_file_name_end = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    if (g_mmi_lyric_str_buff == NULL)
    {
        return MMI_FALSE;
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__*/

    mmi_audply_clear_lyric_context();

    mmi_ucs2cpy((CHAR*)audply_lyric.lyric_file_path, (CHAR*)g_audply.filefullname);

    temp_file_name_end = audply_lyric.lyric_file_path;
    while( (temp_file_name_end = (UI_character_type*) mmi_ucs2chr((CHAR*) temp_file_name_end, L'.')) != NULL )
    {
        file_name_end = temp_file_name_end;
        temp_file_name_end++;
    }

    if (file_name_end)
    {
        *file_name_end = 0;
    }
    mmi_ucs2cat((CHAR*)audply_lyric.lyric_file_path, (CHAR*)L".lrc");

    if ((handle = FS_Open((PU16) audply_lyric.lyric_file_path, FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        U32 file_size = 0;
        U32 str_size = 0;

        CHAR *temp_buf_pool = NULL;
        const U32 temp_buf_pool_size = AUDPLY_LYRIC_TMP_BUFF_MAX_SIZE;   /* 128 ;//256 ; */
        U32 read_size;

        CHAR *str_buf_pool = g_mmi_lyric_str_buff;    /* converted buff pool */
        CHAR *temp_str_buf_pool = str_buf_pool;
        U32 buf_size = AUDPLY_LYRIC_STR_BUFF_MAX_SIZE;           /* size of converted buff pool */
        U32 temp_str_buf_size = buf_size;

        U32 total_read_size = 0;
        U32 total_str_size = 0;

        audply_UCS2_encode_enum BL = NON_UCS2;  /* when it is encoded in UCS2, use this variable to indicate Big or Little endian */

        if (FS_GetFileSize(handle, &file_size) < 0 || !file_size)
        {
            FS_Close(handle);
            return MMI_FALSE;
        }
        //bql: no need the check
        temp_buf_pool = OslMalloc(temp_buf_pool_size);
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        memset(temp_buf_pool, 0, temp_buf_pool_size);

        /* to know what coding type it is */
        FS_Read(handle, temp_buf_pool, 3, &read_size);
        audply_lyric.lrc_encoding_chset = mmi_audply_lrc_encoding_type(temp_buf_pool, &BL);
        FS_Seek(handle, -3, FS_FILE_CURRENT);

        while (total_read_size < file_size && !lyric_full)
        {
            /* read one line until '\n' */
            if (mmi_audply_lrc_FS_Read_one_line
                (handle, temp_buf_pool, temp_buf_pool_size, &read_size, audply_lyric.lrc_encoding_chset, BL) == MMI_FALSE)
            {
                OslMfree((void*)temp_buf_pool);
                FS_Close(handle);
                return MMI_FALSE;
            }
            if (!read_size)
            {
                break;
            }
            // append zero if not large enough.
            //                      if(read_size<temp_buf_pool_size)
            //                              memset(temp_buf_pool+read_size,0,temp_buf_pool_size-read_size) ;

            if (audply_lyric.lrc_encoding_chset != MMI_CHSET_UCS2)
            {
                if (temp_str_buf_size >= 4) /* if size is smaller than 4 , the converter might over write the un-authorized memory space. */
                {
                    str_size = mmi_chset_convert(
                                audply_lyric.lrc_encoding_chset,
                                MMI_CHSET_UCS2,
                                temp_buf_pool,
                                temp_str_buf_pool,
                                temp_str_buf_size);
                    /* str_size -= 2 ; */
                    temp_str_buf_pool[str_size - 1] = 0;
                    temp_str_buf_pool[str_size - 2] = '\n';
                }
                if (temp_str_buf_size == str_size + 2)
                {
                    //bql: why do we have to truncate the /n again in this case
                    mmi_audply_lyric_post_process(str_buf_pool, buf_size);
                }

                // if need to concern about the str_buf not adequate situation, need to append '\n' ??
                //MMI_ASSERT(str_size!=0) ;
            }
            else
            {
                if (temp_str_buf_size < read_size)
                {
                    mmi_audply_lyric_UCS2_memcpy((CHAR*)temp_str_buf_pool, (CHAR*)temp_buf_pool, temp_str_buf_size, BL);
                    str_size = read_size;
                    //bql: why do we have to truncate the /n again in this case
                    mmi_audply_lyric_post_process(str_buf_pool, buf_size);
                }
                else
                {
                    mmi_audply_lyric_UCS2_memcpy((CHAR*)temp_str_buf_pool, (CHAR*)temp_buf_pool, read_size, BL);
                    str_size = read_size;
                }
            }

            if (!(mmi_audply_parse_lyric((U16*) temp_str_buf_pool)))
            {
                OslMfree((void*)temp_buf_pool);
                audply_lyric.is_ready = MMI_FALSE;
                FS_Close(handle);
                return MMI_FALSE;
            }

            /* str_buff is not adequate for the lrc file. */
            if (total_str_size + str_size > buf_size)   /* temp_str_buf_size) */
            {
                total_str_size = buf_size;
                break;
            }
            total_str_size += str_size;
            total_read_size += read_size;
            temp_str_buf_size -= str_size;
            temp_str_buf_pool += str_size;

        }

        OslMfree((void*)temp_buf_pool);

/*        if (total_str_size > buf_size)
        {
            audply_lyric.lyric_buf_pool.str_size = buf_size;
        }
        else
        {
            audply_lyric.lyric_buf_pool.str_size = total_str_size - 2;
        }

        audply_lyric.lyric_buf_pool.buf = str_buf_pool;
        audply_lyric.lyric_buf_pool.buf_size = buf_size;*/

        audply_lyric.cur_line = audply_lyric.first_line;
        audply_lyric.is_ready = MMI_TRUE;
        FS_Close(handle);
        return MMI_TRUE;

    }
    return MMI_FALSE;   /* no such .lrc exists. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_parse_lyric
 * DESCRIPTION
 *  parse current lyric string
 * PARAMETERS
 *  cur_char        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_audply_parse_lyric(U16 *cur_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audply_lyric_parse_status_enum status = LINE_START;
    S32 match_index = 0;
    S32 num_length = 0;
    S32 time_phase1, time_phase2, time_phase3, time_phaseMS;
    U32 temp_time;
    S32 temp_num, i, j;
    U16 *temp_ptrU16;
    U16 *tag_ids[5] = {L"ar", L"ti", L"al", L"by", L"offset" };

    S32 time_count_line = 0;    /* counting how many time tages for one lyric */
    CHAR *line_lyric1 = NULL ;

    audply_lyric_line_struct *temp_lyric = NULL;
    audply_lyric_line_struct *cur_lyric = NULL;
    audply_lyric_line_struct *pre_lyric = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cur_char)
    {
        switch (status)
        {
            case LINE_START:
                time_count_line = 0;
                line_lyric1 = NULL;

                if ((cur_char = (U16*) mmi_ucs2chr((CHAR*) cur_char, L'[')) == NULL)
                {
                    return MMI_TRUE;
                }
                else
                {
                    status = TAG_START;
                }
                break;

            case LINE_END:
                if (line_lyric1 || time_count_line)
                {
                    if (!audply_lyric.first_line)
                    {
                        audply_lyric.first_line = &audply_lyric.lyric[0];
                        for (j = 0; j < time_count_line; j++)
                        {
                            if (audply_lyric.first_line->time > audply_lyric.lyric[j].time)
                            {
                                audply_lyric.first_line = &audply_lyric.lyric[j];
                            }
                        }
                    }
                    for (i = 0; i < time_count_line; i++)
                    {
                        temp_lyric = &audply_lyric.lyric[audply_lyric.lyric_count - i - 1];
                        temp_lyric->line_lyric1 = line_lyric1;
                        /* temp_lyric->line_lyric2 = line_lyric2; */
                        cur_lyric = audply_lyric.first_line;
                        pre_lyric = NULL;
                        while (cur_lyric)
                        {
                            if(temp_lyric == cur_lyric)
                            {
                                break;
                            }
                            if (temp_lyric->time < cur_lyric->time)
                            {
                                temp_lyric->next = cur_lyric;
                                if (pre_lyric)
                                {
                                    pre_lyric->next = temp_lyric;
                                }
                                else
                                {
                                    audply_lyric.first_line = temp_lyric;
                                }
                                break;
                            }
                            pre_lyric = cur_lyric;
                            cur_lyric = cur_lyric->next;
                            ASSERT(pre_lyric != cur_lyric);                            
                        }
                        if (!cur_lyric && temp_lyric != audply_lyric.first_line)
                        {
                            if (pre_lyric)
                            {
                                pre_lyric->next = temp_lyric;
                            }
                            else
                            {
                                audply_lyric.first_line = temp_lyric;
                            }
                        }
                    }
                }
                return MMI_TRUE;
            case TAG_START:
                time_phase1 = 0xffffff;
                time_phase2 = 0xffffff;
                time_phase3 = 0xffffff;
                time_phaseMS = 0xffffff;

                TRIM_LEFT;
                match_index = UCS2StrMatch((CHAR*) cur_char, (CHAR*) L"[]:. \t\r\n", 5, (CHAR **) tag_ids);

                if (match_index == -1)
                {
                    cur_char--;
                    status = TAG_TIME1;
                }
                else
                {
                    cur_char += mmi_ucs2strlen((CHAR*) tag_ids[match_index]);
                    TRIM_LEFT;
                    if (!cur_char)
                    {
                        return MMI_TRUE;
                    }
                    if (*cur_char != L':')
                    {
                        FIND_TAG_END;
                    }
                    else
                    {
                        switch (match_index)    /* { L"ar", L"ti", L"al", L"by", L"offset" } */
                        {
                            case 0:
                                status = TAG_ID_AR;
                                break;
                            case 1:
                                status = TAG_ID_TI;
                                break;
                            case 2:
                                status = TAG_ID_AL;
                                break;
                            case 3:
                                status = TAG_ID_BY;
                                break;
                            case 4:
                                status = TAG_ID_OFFSET;
                                break;
                        }
                    }
                }
                break;

            case TAG_END:
                temp_time = 0xffffff;
                if (time_phase1 != 0xffffff && time_phase2 != 0xffffff && time_phase3 != 0xffffff)
                {
                    temp_time = time_phase1 * 3600 + time_phase2 * 60 + time_phase3;
                }
                else if (time_phase1 != 0xffffff && time_phase2 != 0xffffff)
                {
                    temp_time = time_phase1 * 60 + time_phase2;
                }
                else if (time_phase1 != 0xffffff)
                {
                    temp_time = time_phase1;
                }

                if(temp_time != 0xffffff)
                {
                    temp_time *= 1000 ;
                    if (time_phaseMS != 0xffffff)
                    {
                        temp_time += time_phaseMS ;                                            
                    }
                }
                else
                {
                    if (time_phaseMS != 0xffffff)
                    {
                        temp_time = time_phaseMS ;
                     }
                }
                
                if (temp_time != 0xffffff)
                {
                    /* handle more than one time tags for one lyric */
                    temp_lyric = &audply_lyric.lyric[audply_lyric.lyric_count++];
                    time_count_line++;
                    temp_lyric->next = NULL;
                    temp_lyric->time = temp_time;
                    if (audply_lyric.lyric_count == AUDPLY_LYRIC_MAX_LINE_COUNT)
                    {
                        lyric_full = MMI_TRUE;
                        return MMI_TRUE;
                    }
                }

                cur_char = (U16*) mmi_ucs2trim_left((CHAR*) cur_char, (CHAR*) L" \t");
                if (!cur_char)
                {
                    return MMI_TRUE;
                }
                if (*cur_char == L'[')
                {
                    status = TAG_START;
                }
                else if (*cur_char == L'\r' || *cur_char == L'\n')
                {
                    status = LINE_END;
                }
                else
                {
                    status = TAG_LYRIC1;
                    continue;
                }
                break;

            case TAG_LYRIC1:
                if (mmi_ucs2find((CHAR*) cur_char, (CHAR*) L"\r\n", &num_length, 1) == -1)
                {
                    return MMI_FALSE;
                }
                line_lyric1 = (CHAR*) cur_char;
                cur_char += num_length;
                /*       if (*cur_char == L'`')
                   {
                   status = TAG_LYRIC2;
                   continue;
                   } */
                if (*cur_char == L'\r' || *cur_char == L'\n')
                {
                    status = LINE_END;
                }
                *cur_char = 0;
                break;

                /*
                 * case TAG_LYRIC2:
                 * if (mmi_ucs2find((CHAR*)cur_char,(CHAR*)L"\r\n", &num_length, 1) == -1)
                 * {
                 * return MMI_FALSE;
                 * }
                 * line_lyric2 = (CHAR*)cur_char;
                 * cur_char += num_length;
                 * status = LINE_END;
                 * *cur_char = 0;
                 * break;
                 */
            case TAG_TIME1:
                TRIM_LEFT;
                if (mmi_ucs2toi((CHAR*) cur_char, &time_phase1, &num_length) >= 0 &&
                    time_phase1 >= 0 && time_phase1 <= 60)
                {
                    cur_char += num_length;
                    TRIM_LEFT;
                    if (*cur_char == L':')
                    {
                        status = TAG_TIME2;
                    }
                    else if (*cur_char == L'.')
                    {
                        status = TAG_MS;
                    }
                    else
                    {
                        FIND_TAG_END;
                    }
                }
                else
                {
                    time_phase1 = 0xffffff;
                    FIND_TAG_END;
                }
                break;

            case TAG_TIME2:
                TRIM_LEFT;
                if (mmi_ucs2toi((CHAR*) cur_char, &time_phase2, &num_length) >= 0 &&
                    time_phase2 >= 0 && time_phase2 <= 60)
                {
                    cur_char += num_length;
                    TRIM_LEFT;
                    if (*cur_char == L':')
                    {
                        status = TAG_TIME3;
                    }
                    else if (*cur_char == L'.')
                    {
                        status = TAG_MS;
                    }
                    else
                    {
                        FIND_TAG_END;
                    }
                }
                else
                {
                    time_phase2 = 0xffffff;
                    FIND_TAG_END;
                }
                break;

            case TAG_TIME3:
                TRIM_LEFT;
                if (mmi_ucs2toi((CHAR*) cur_char, &time_phase3, &num_length) >= 0 &&
                    time_phase3 >= 0 && time_phase3 <= 60)
                {
                    cur_char += num_length;
                    TRIM_LEFT;
                    if (*cur_char == L'.')
                    {
                        status = TAG_MS;
                    }
                    else
                    {
                        FIND_TAG_END;
                    }
                }
                else
                {
                    time_phase3 = 0xffffff;
                    FIND_TAG_END;
                }
                break;

            case TAG_MS:
                TRIM_LEFT;
                if (mmi_ucs2toi((CHAR*) cur_char, &time_phaseMS, &num_length) >= 0 &&
                      time_phaseMS >= 0 && time_phaseMS < 1000)
                {
                    if(time_phaseMS>0 && time_phaseMS < 10)
                    {
                        time_phaseMS *= 100 ;
                    }
                    else if(time_phaseMS>=10 && time_phaseMS < 100)
                    {
                        time_phaseMS *= 10 ;
                    }
                }
                else
                {
                    time_phaseMS = 0xffffff;
                }
                FIND_TAG_END;
                break;
            case TAG_ID_AR:
                temp_ptrU16 = (U16*) mmi_ucs2chr((CHAR*) cur_char, L']');
                if (temp_ptrU16 == NULL)
                {
                    return MMI_TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_ARTIST_LEN + 1)
                   {
                   mmi_ucs2ncpy((CHAR*)audply_lyric.lyric_tag_id.artist,(CHAR*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_TI:
                temp_ptrU16 = (U16*) mmi_ucs2chr((CHAR*) cur_char, L']');
                if (temp_ptrU16 == NULL)
                {
                    return MMI_TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_TITLE_LEN + 1)
                   {
                   mmi_ucs2ncpy((CHAR*)audply_lyric.lyric_tag_id.title,(CHAR*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_AL:
                temp_ptrU16 = (U16*) mmi_ucs2chr((CHAR*) cur_char, L']');
                if (temp_ptrU16 == NULL)
                {
                    return MMI_TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_ALBUM_LEN + 1)
                   {
                   mmi_ucs2ncpy((CHAR*)audply_lyric.lyric_tag_id.album,(CHAR*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_BY:
                temp_ptrU16 = (U16*) mmi_ucs2chr((CHAR*) cur_char, L']');
                if (temp_ptrU16 == NULL)
                {
                    return MMI_TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_GENRE_LEN + 1)
                   {
                   mmi_ucs2ncpy((CHAR*)audply_lyric.lyric_tag_id.genre,(CHAR*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_OFFSET:
                TRIM_LEFT;
                if (mmi_ucs2toi((CHAR*) cur_char, &temp_num, &num_length) >= 0)
                {
                    audply_lyric.offset_time = temp_num;
                }
                FIND_TAG_END;
                break;

            default:
                break;
        }   /* End switch */

        cur_char++;
    }   /* End whlie */
    return MMI_TRUE;
}
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_free_mem_lyrics
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
static  void  mmi_audply_free_mem_lyrics(void* p, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    applib_mem_screen_free(p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_malloc_mem_lyrics
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return memory address, 
 *****************************************************************************/
static  void* mmi_audply_malloc_mem_lyrics(kal_uint32 nSize, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     return  applib_mem_screen_alloc_framebuffer(nSize);   
}


/*****************************************************************************
* FUNCTION
*   mmi_audply_prepare_lyrics
* DESCRIPTION
*   prepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
void mmi_audply_prepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply_lyrics_box.time_out   = 0;
    g_audply_lyrics_box.last_time  = (U16)(g_audply.new_play_time/MMI_AUDPLY_UI_UPDATE_PLAY_TIME);

    if (NULL == g_audply_lyrics)
    {
        g_audply_lyrics = lyrics_parse_create(MMI_AUDPLY_UI_UPDATE_PLAY_TIME,/*lyrics update ms*/
            mmi_audply_malloc_mem_lyrics, mmi_audply_free_mem_lyrics, 0); 
    }    
    if (g_audply.lyrics_display)
    {
        mmi_audply_parse_lyrics();
       if(g_audply_lyrics_box.is_ready)
        {
            mmi_audply_config_lyrics();
            mmi_audply_update_lyrics();
			mmi_audply_reset_skin_layer();
			mmi_audply_draw_lyrics();
					
        }
        else
        {
            mmi_audply_unprepare_lyrics();
        }
    } 
}


/*****************************************************************************
* FUNCTION
*   mmi_audply_unprepare_lyrics
* DESCRIPTION
*   unprepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
void mmi_audply_unprepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	GDI_HANDLE base_handle;
	S32 x1, y1, x2, y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (NULL != g_audply_lyrics)
    {     
        lyrics_parse_release();
        g_audply_lyrics = NULL;
    }
	  
	  if(!g_audply_lyrics_box.is_ready)
	  {
	  	 return;
	  }
	 srv_backlight_turn_off();    
	g_audply_lyrics_box.is_ready = 0;
	if(g_audply.in_main_screen)
	{
	    x1 = g_audply_lyrics_box.rgn_txt.x;
	    y1 = g_audply_lyrics_box.rgn_txt.y;  
	    x2 = x1 + g_audply_lyrics_box.rgn_txt.w;
	    y2 = y1 + g_audply_lyrics_box.rgn_txt.h;;

#if(UI_DOUBLE_BUFFER_SUPPORT)
	    gui_lock_double_buffer();
#endif


#ifdef __GDI_MEMORY_PROFILE_2__
	    gdi_layer_push_and_set_active(audply_osd_layer);
#endif 

	    gui_push_clip();


	    gdi_layer_set_clip(x1,y1,x2,y2);
	    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
	
    	mmi_audply_redraw_animation();

	    gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
	    gdi_layer_pop_and_restore_active();
#endif

#if(UI_DOUBLE_BUFFER_SUPPORT)
	    gui_unlock_double_buffer();
	    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif
	}

}


/*****************************************************************************
* FUNCTION
*   mmi_audply_config_lyrics
* DESCRIPTION
*   configure lyrics display region 
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_audply_config_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!g_audply_lyrics_box.is_ready)
    {
        return;
    }
   srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
   gui_set_font(&MMI_small_font);
   g_audply_lyrics_box.font_height = gui_get_character_height();
   g_audply_lyrics_box.line_count = 
        (U8)(120/(g_audply_lyrics_box.font_height+MMI_AUDPLY_LYRICS_GAP_H) );    
    if (g_audply_lyrics_box.line_count > MMI_AUDPLY_LYRICS_MAX_LINE)
    {
        g_audply_lyrics_box.line_count = MMI_AUDPLY_LYRICS_MAX_LINE;
    }
    g_audply_lyrics_box.line_focus     = 0;
    g_audply_lyrics_box.line_focus_id  = AUDPLY_LYRIC_MAX_LINE_COUNT; 
    g_audply_lyrics_box.line_height    = g_audply_lyrics_box.rgn_txt.h/g_audply_lyrics_box.line_count;
    
    
    g_audply_lyrics_box.rgn_txt.h = g_audply_lyrics_box.line_height*g_audply_lyrics_box.line_count;
	
    gdi_image_stop_animation_all();
    lyrics_unformat_line(g_audply_lyrics);
    lyrics_format_line(g_audply_lyrics, g_audply_lyrics_box.rgn_txt.w,
        (U32)g_audply.duration, gui_get_string_width_n); 
}


/*****************************************************************************
* FUNCTION
*  mmi_audply_parse_lyrics
* DESCRIPTION
*  parse lyrics
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_audply_parse_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16*    media_file_path;
    U16    meta_title[90];
    U16     lyric_file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32     nRet;
    U16     lyric_err_str_id = STR_GLOBAL_ERROR;
    U8      lyric_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    media_file_path = g_audply.filefullname;
	mmi_audply_extract_filename(meta_title,media_file_path);
   
    lyric_ret = lyrics_convert_file_name(media_file_path, 
        meta_title, lyric_file_path); 
    
    if (LYRICS_ERR_NONE == lyric_ret)
    {
        lyric_ret = lyrics_parse_file(lyric_file_path);
    }
    if (LYRICS_ERR_NONE != lyric_ret)
    {
        switch(lyric_ret)
        {
        	lyric_err_str_id = STR_ID_AUDPLY_ERR_DATA_LYRICS_FILE;
            break;
        case LYRICS_ERR_OPEN_FILE_FAILED:

            lyric_err_str_id = STR_ID_AUDPLY_ERR_OPEN_LYRICS_FILE;
            break;
        default:
            lyric_err_str_id = STR_ID_AUDPLY_NO_LYRICS_FILE;
			break;
        }
        lyrics_set_err_text(g_audply_lyrics, (kal_uint16*)GetString(lyric_err_str_id));
    }
    else
    {
      g_audply_lyrics_box.is_ready = 1;
    }
  
    g_audply_lyrics_box.line_focus_id = AUDPLY_LYRIC_MAX_LINE_COUNT;  
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_text
* DESCRIPTION
*  draw text
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_audply_draw_text(mmi_audply_rect_struct* rgn_p,
                                mmi_audply_rect_struct* rgn_clip_p,
                                U16* txt_p, U8 attr_w, U8 attr_h,
                                U8 use_border, S32 trunc_w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 x, y, str_w, str_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string(txt_p, &str_w, &str_h);
    if (0 != use_border)
    {
        str_h += 2;
        str_w += 2;
    }
	if (trunc_w > 0)
    {
		
		str_w = trunc_w;		
		
    }

        
    if (0 != rgn_clip_p)
    {
        gui_push_text_clip();
        gui_set_text_clip(rgn_clip_p->x, rgn_clip_p->y, 
            rgn_clip_p->x+rgn_clip_p->w, rgn_clip_p->y+rgn_clip_p->h);
    }    
  
        
        x = rgn_p->x + (rgn_p->w - str_w) / 2;
   
    if (r2lMMIFlag)
    {        
        x += str_w;
        if (0 != use_border)
        {
            x -= 2;
        }
    } 
    
    y = rgn_p->y;
    gui_move_text_cursor(x, y);
    
    if (trunc_w < 0)
    {
        if (0 != use_border)
        {
            gui_print_bordered_text(txt_p);
        }
        else
        {
            gui_print_text(txt_p);
        }
    }
    else
    {
        if (0 != use_border)
        {
            gui_print_truncated_borderd_text(x, y, trunc_w, txt_p);
        }
        else
        {
            gui_print_truncated_text(x, y, trunc_w, txt_p);
        }
    }
    
    
    if (0 != rgn_clip_p)
    {
        gui_pop_text_clip();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_audply_update_lyrics
* DESCRIPTION
*  update lyrics display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_audply_update_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 lineID, nextID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == g_audply_lyrics)
    {
        /*screen may delete by delete call back function*/
        return;
    }
    g_audply_lyrics_box.last_time = (U16)(g_audply.new_play_time/MMI_AUDPLY_UI_UPDATE_PLAY_TIME);

    lineID = lyrics_get_line(g_audply_lyrics, g_audply_lyrics_box.last_time);
    if (lineID == g_audply_lyrics_box.line_focus_id)
    {
        if (g_audply_lyrics_box.last_time > g_audply_lyrics->lines_p[lineID].id_time)
        {
            g_audply_lyrics_box.time_out = 
                (U16)(g_audply_lyrics_box.last_time - g_audply_lyrics->lines_p[lineID].id_time);
        }
        else
        {
            g_audply_lyrics_box.time_out = 0;
        }
        return;
    }
    
    if (lineID < AUDPLY_LYRIC_MAX_LINE_COUNT)
    {
        nextID = g_audply_lyrics->lines_p[lineID].id_next;
    }
    else
    {
        nextID = AUDPLY_LYRIC_MAX_LINE_COUNT;
    }
    if (nextID < AUDPLY_LYRIC_MAX_LINE_COUNT)
    {
        g_audply_lyrics_box.next_time = g_audply_lyrics->lines_p[nextID].id_time;
    }
    else
    {
        g_audply_lyrics_box.next_time = 
            (U32)(g_audply.duration/MMI_AUDPLY_UI_UPDATE_PLAY_TIME);
    }
    g_audply_lyrics_box.curr_time      = g_audply_lyrics->lines_p[lineID].id_time;
    g_audply_lyrics_box.line_focus_id  = lineID;

    if (g_audply_lyrics_box.last_time > g_audply_lyrics->lines_p[lineID].id_time)
    {
        g_audply_lyrics_box.time_out   = 
            (U16)(g_audply_lyrics_box.last_time - g_audply_lyrics->lines_p[lineID].id_time);
    }
    else
    {
        g_audply_lyrics_box.time_out   = 0;
    }
    
    g_audply_lyrics_box.line_id[g_audply_lyrics_box.line_focus] = g_audply_lyrics_box.line_focus_id;
    lineID = g_audply_lyrics_box.line_focus_id;
    
    for (i = g_audply_lyrics_box.line_focus-1; i >= 0; i--)
    {
        if (lineID < AUDPLY_LYRIC_MAX_LINE_COUNT)
        {
            g_audply_lyrics_box.line_id[i] = g_audply_lyrics->lines_p[lineID].id_prev;
            lineID = g_audply_lyrics_box.line_id[i];
        }
        else
        {
            g_audply_lyrics_box.line_id[i] = AUDPLY_LYRIC_MAX_LINE_COUNT;
        }
    }
    lineID = g_audply_lyrics_box.line_focus_id;
    for (i = g_audply_lyrics_box.line_focus+1; i <= g_audply_lyrics_box.line_count; i++)
    {   
        if (lineID < AUDPLY_LYRIC_MAX_LINE_COUNT)
        {
            g_audply_lyrics_box.line_id[i] = g_audply_lyrics->lines_p[lineID].id_next;
            lineID = g_audply_lyrics_box.line_id[i];
        }
        else
        {
            g_audply_lyrics_box.line_id[i] = AUDPLY_LYRIC_MAX_LINE_COUNT;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_audply_draw_lyrics
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_audply_draw_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S16     x, y, h, w,yOff, yBeg;
    U16     *pStr, u16Tmp, nLen;
	U16 font_r, font_g, font_b;
	U16 skin_r, skin_g, skin_b;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if ((NULL == g_audply_lyrics)|| !g_audply_lyrics_box.is_ready)
    {
       // MMI_audply_ERR_TRACE(g_audply_lyrics);
        return;
    }
	skin_r = g_audply_lyrics_box.color.r;
	skin_g = g_audply_lyrics_box.color.g;
	skin_b = g_audply_lyrics_box.color.b;
	x = g_audply_lyrics_box.rgn_txt.x;
    y = g_audply_lyrics_box.rgn_txt.y;  
    h = g_audply_lyrics_box.rgn_txt.h;
	w = g_audply_lyrics_box.rgn_txt.w;

#if(UI_DOUBLE_BUFFER_SUPPORT)
		gui_lock_double_buffer();
#endif
   
   	 gdi_layer_push_and_set_active(audply_osd_layer);
	 gdi_layer_set_clip(x,y,x+w,y+h);
     gdi_draw_solid_rect(x, y, x + w, y + h,GDI_COLOR_TRANSPARENT);

    gui_set_font(&MMI_small_font);
    

    
    if (g_audply_lyrics_box.next_time > g_audply_lyrics_box.curr_time)
    {
        yOff = (S16)(g_audply_lyrics_box.line_height*g_audply_lyrics_box.time_out/
            (g_audply_lyrics_box.next_time-g_audply_lyrics_box.curr_time));
    }
    else
    {
        yOff = 0;
    }
    yBeg = 0;
    
    g_audply_lyrics_box.rgn_txt.x = x;
    g_audply_lyrics_box.rgn_txt.y = y;
    g_audply_lyrics_box.rgn_txt.h = g_audply_lyrics_box.line_height;     
    
    kal_mem_cpy(&g_audply_lyrics_box.rgn_clip, &g_audply_lyrics_box.rgn_txt, 
        sizeof(mmi_audply_rect_struct));
    
    for (i = 0; i <= g_audply_lyrics_box.line_count; i++)
    {
        pStr = NULL;
        if (g_audply_lyrics_box.line_id[i] < LYRICS_MAX_LINES)
        {
            pStr = g_audply_lyrics->lines_p[g_audply_lyrics_box.line_id[i]].st_text;
            nLen = g_audply_lyrics->lines_p[g_audply_lyrics_box.line_id[i]].ln_text; 
        }
        if (NULL != pStr)
        {
            if (g_audply_lyrics_box.rgn_txt.y < yBeg)
            {
                g_audply_lyrics_box.rgn_clip.y = yBeg;
                g_audply_lyrics_box.rgn_clip.h = g_audply_lyrics_box.rgn_txt.y - yBeg + 
                    g_audply_lyrics_box.rgn_txt.h;
            }
            else if (g_audply_lyrics_box.rgn_txt.y - y + 2 +g_audply_lyrics_box.font_height > yBeg+h)
            {
                g_audply_lyrics_box.rgn_clip.y = g_audply_lyrics_box.rgn_txt.y;
                g_audply_lyrics_box.rgn_clip.h = yBeg + h - g_audply_lyrics_box.rgn_txt.y;
            }
            else
            {
                g_audply_lyrics_box.rgn_clip.y = g_audply_lyrics_box.rgn_txt.y;
                g_audply_lyrics_box.rgn_clip.h = g_audply_lyrics_box.rgn_txt.h;
            }
            
            u16Tmp = pStr[nLen];
            pStr[nLen] = 0;   

            if (i == g_audply_lyrics_box.line_focus)
            {
               gui_set_text_color(MMI_AUDPLY_LYRICS_FOCUS_COLOR_FG); 
			
                mmi_audply_draw_text(&g_audply_lyrics_box.rgn_txt, &g_audply_lyrics_box.rgn_clip, 
                    pStr, 0, 0, 0, -1);
            }
            else
            {
				font_r = (skin_r * (g_audply_lyrics_box.line_count *3 - (i*2)))/(g_audply_lyrics_box.line_count*4);
				font_g = (skin_g * (g_audply_lyrics_box.line_count * 3- (i*2)))/(g_audply_lyrics_box.line_count*4);
				font_b = (skin_b * (g_audply_lyrics_box.line_count * 3 - (i*2)))/(g_audply_lyrics_box.line_count*4);
				gui_set_text_color(gui_color(font_r, font_g, font_b)); 
                mmi_audply_draw_text(&g_audply_lyrics_box.rgn_txt, &g_audply_lyrics_box.rgn_clip, 
                    pStr, 0, 0, 0, -1);
            } 
         
            pStr[nLen] = u16Tmp;
        }
        g_audply_lyrics_box.rgn_txt.y += g_audply_lyrics_box.line_height;        
    }
    g_audply_lyrics_box.rgn_txt.x = x;
    g_audply_lyrics_box.rgn_txt.y = y;
    g_audply_lyrics_box.rgn_txt.h = h;   
    
   gdi_layer_pop_and_restore_active();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x, y, x + w, y + h);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}



void mmi_audply_update_lyrics_on_time(void)
{
	mmi_audply_update_lyrics();
	mmi_audply_draw_lyrics();
	StartTimer(AUDPLY_DISPLAY_LYRICS_TIMER,MMI_AUDPLY_UI_UPDATE_PLAY_TIME,mmi_audply_update_lyrics_on_time);
}


void mmi_audply_stop_update_lyric(void)
{
	mmi_audply_update_lyrics();
	mmi_audply_draw_lyrics();
}
#endif/*__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__*/
#endif  /* __MMI_AUDIO_PLAYER__ */

#ifdef __MMI_FILE_MANAGER__
//bql: some functions that may be compiled event if __MMI_AUDIO_PLAYER__ is not be defined
//Since audio single player will be switched on while !__MMI_MEDIA_PLAYER_AUDIO__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_display_popup_proc1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  struct      [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
 mmi_ret mmi_audply_display_popup_proc1(mmi_alert_result_evt_struct *evt)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (EVT_ID_ALERT_QUIT == evt->evt_id)
     {
         switch (evt->result)
         {
             case MMI_ALERT_NORMAL_EXIT:
            #if defined(__MMI_AUDIO_PLAYER__)	
                 mmi_audply_pop_callback(); //<execute popup callback here>
             #endif    
                 break;
                 
             case MMI_ALERT_INTERRUPT_EXIT:
        #if defined(__MMI_AUDIO_PLAYER__)	
                 mmi_audply_pop_intercallback();
        #endif
                 break;
         }
     }
    return MMI_RET_OK;
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_display_popup
 * DESCRIPTION
 *  call display pop up with corresponding parameter with the result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_display_popup(S32 result, FuncPtr callback, FuncPtr InterrCallBack) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_PLAYER__)
    mmi_audply_pop_callback = callback;
    mmi_audply_pop_intercallback = InterrCallBack;
#endif	
    
    if (result < MMI_AUDPLY_PLAYLIST_ERR_BEGIN)
    {
        #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_playlist_display_popup(result, callback);
        #endif
    }
    else if(result <= MDI_AUDIO_FAIL)   /* MDI error code. */
    {
        if(callback)
        {
            do {
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
            #if defined(__MMI_AUDIO_PLAYER__)
                if (!g_audply.background_play)
                {
                    arg.parent_id = GRP_ID_AUDPLY_MAIN;
                }
                else
            #endif/*__MMI_AUDIO_PLAYER__*/	
                {
                    arg.parent_id = GRP_ID_ROOT; 
                }
                arg.callback = (mmi_proc_func)mmi_audply_display_popup_proc1;
                mmi_popup_display_ext((mmi_audply_err_str(result)), MMI_EVENT_FAILURE, &arg);
            }while(0);
             
             
        }
        else
        {
            mmi_popup_display_ext((mmi_audply_err_str(result)), MMI_EVENT_FAILURE, NULL);
            
        }
    }

    else if(result < 0) /*FS error code*/
    {
        if(callback)
        {
            do
            {
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                #if defined(__MMI_AUDIO_PLAYER__)
                if (!g_audply.background_play)
                {
                    arg.parent_id = GRP_ID_AUDPLY_MAIN;
                }
                else
                #endif
                {
                    arg.parent_id = GRP_ID_ROOT; 
                }
                arg.callback = (mmi_proc_func)mmi_audply_display_popup_proc1;
                mmi_popup_display_ext((srv_fmgr_fs_error_get_string_and_popup_type(result, 0)), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result), &arg);
            }while(0);
                      
        }
        else
        {
           mmi_popup_display_ext((srv_fmgr_fs_error_get_string_and_popup_type(result, 0)), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result), NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_err_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_audply_err_str(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_AUDPLY_TRC_ERROR_STR, result);
    switch (result)
    {
        case MDI_AUDIO_DRM_PROHIBIT:
        case MDI_AUDIO_DRM_TIMEOUT:
            return STR_GLOBAL_DRM_PROHIBITED;
        case MDI_AUDIO_BUSY:
            return STR_ID_AUDPLY_DEVICE_BUSY;
        case MDI_AUDIO_DISC_FULL:
            return STR_ID_AUDPLY_LIST_FULL;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            return STR_ID_AUDPLY_OPEN_FILE_ERROR;
        case MDI_AUDIO_BAD_FORMAT:
            return STR_ID_AUDPLY_BAD_FORMAT;
        case MDI_AUDIO_INVALID_FORMAT:
            return STR_GLOBAL_INVALID_FORMAT;
        case MDI_AUDIO_UNSUPPORTED_CHANNEL:
            return STR_ID_AUDPLY_UNSUPPORTED_CHANNEL;
        case MDI_AUDIO_UNSUPPORTED_FREQ:
            return STR_ID_AUDPLY_UNSUPPORTED_FREQ;
        case MDI_AUDIO_UNSUPPORTED_TYPE:
            return STR_ID_AUDPLY_UNSUPPORTED_TYPE;
        case MDI_AUDIO_FAIL:
/*        case MDI_AUDIO_ERROR: default string */
            return STR_ID_AUDPLY_ERROR;
        case MDI_AUDIO_NO_SPACE:
            return STR_ID_AUDPLY_NO_SPACE;
            
    
        case MDI_AUDIO_UNSUPPORTED_SPEED:
            return STR_ID_AUDPLY_UNSUPPORTED_SPEED;
 
            
        case MDI_AUDIO_MP4_NO_AUDIO_TRACK:
            return STR_ID_AUDPLY_NO_AUDIO_TRACK;
        case MDI_AUDIO_DECODER_NOT_SUPPORT:
            return STR_ID_AUDPLY_DECODER_NOT_SUPPORT;
        default:
            return STR_ID_AUDPLY_COMMAND_ERROR;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_auddply_play_event_callback_hdlr
 * DESCRIPTION
 *  this is callback handler to query if audio is playing or not 
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
mmi_ret mmi_auddply_play_event_callback_hdlr(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     MMI_BOOL result = MMI_FALSE;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (event->evt_id == EVT_ID_SRV_PROF_IS_PLAYING)
    {
    	
    	#ifdef __MMI_AUDIO_PLAYER__
      if (mmi_audply_is_playing())
      {
      	result =  MMI_TRUE;
      }
      #endif
      
      #ifndef __MMI_MEDIA_PLAYER_AUDIO__
      if(mmi_audply_is_single_play_activated())
      {
         result = MMI_TRUE;
      }
      #endif

   }	
    return result;
	
}

#endif
#if defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && defined(__MMI_AUDIO_PLAYER__)

static void mmi_sub_audply_exit_audply_app(void);
static MMI_BOOL mmi_sub_audply_refresh_list_key_handler(void);
static void mmi_sub_audply_refresh_list_popup(void);
static void mmi_sub_audply_exit_popup_error(void);
static void mmi_sub_audply_popup_error(void);
static MMI_BOOL mmi_sub_audply_entry_option_key_handler(void);
static MMI_BOOL mmi_sub_audply_entry_playlist_key_handler(void);
static MMI_BOOL mmi_sub_audply_entry_repeat_setting_key_handler(void);
static void mmi_sub_audply_exit_main(void);
static void mmi_sub_audply_entry_main(void);
static void mmi_sub_audply_exit_option(void);
static void mmi_sub_audply_option_highlight_hdlr(S32 index);
static void mmi_sub_audply_repeat_highlight_hdlr(S32 index);
static void mmi_sub_audply_entry_option(void);
static void mmi_sub_audply_option_lsk(void);
static void mmi_sub_audply_shuffle_setting(void);
/*static void mmi_sub_audply_play_file(void);*/
static void mmi_sub_audply_entry_playlist(void);
static void mmi_sub_audply_exit_playlist(void);
static void mmi_sub_audply_set_repeat(void);
static void mmi_sub_audply_entry_repeat_setting(void);
static U8 mmi_sub_audply_delete_history_hdlr(void *in_param);
static void mmi_sub_audply_press_prev_button_down(void);
static void mmi_sub_audply_press_prev_button_up(void);
static void mmi_sub_audply_press_next_button_down(void);
static void mmi_sub_audply_press_next_button_up(void);
static void mmi_sub_audply_press_play_button_down(void);
static void mmi_sub_audply_press_play_button_up(void);
static void mmi_sub_audply_play_file_in_sub_playlist(void);
static void mmi_sub_audply_update_main(void);
#define SUB_AUDIO_PLAYER_FUNCTION_BODY
/*****************************************************************************
 * FUNCTION
 *  HighlightSubAudioPlayer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSubAudioPlayer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler((FuncPtr)mmi_sub_audply_entry_main_key_handler, KEY_BACK, KEY_EVENT_DOWN);	
    SetKeyHandler((FuncPtr)mmi_sub_audply_entry_main_key_handler, KEY_PLAY_STOP, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_audply_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_sub_audply_exit_audply_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = MMI_FALSE;
    mmi_audply_stop_playing();
    EntrySubLCDMainMenu();
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_refresh_list_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/
static MMI_BOOL mmi_sub_audply_refresh_list_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SUB_MAIN_MENU_SCREENID, mmi_sub_audply_refresh_list_popup, 1);
    	return MMI_TRUE;		
    }
    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_refresh_list_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void

 *****************************************************************************/

static void mmi_sub_audply_refresh_list_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DinitSubLCDHistory();
    ShowCategory311Screen(
    (PU8)GetString(STR_ID_AUDPLY_OPTION_REGEN_LIST),
               IMG_ID_AUDPLY_SUB_SKIN_REFRESH_LIST,
                NULL);
    StartTimer(POPUP_SUBLCD, 1000,(FuncPtr)EntrySubLCDMainMenu);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_popup_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/

MMI_BOOL mmi_sub_audply_popup_error_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_MAIN_SUBLCD, mmi_sub_audply_popup_error, 1);
    	return MMI_TRUE;		
    }
    return MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_popup_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/
static void mmi_sub_audply_exit_popup_error(void)
{
    StopTimer(POPUP_SUBLCD);
    GoBackSubLCDHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_popup_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/
static void mmi_sub_audply_popup_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory311Screen(
    (PU8)GetString(STR_GLOBAL_ERROR),
                IMG_ID_AUDPLY_SUB_SKIN_ERROR,
                NULL);
    StartTimer(POPUP_SUBLCD, 1000,(FuncPtr)mmi_sub_audply_exit_popup_error);

    SetKeyHandler(mmi_sub_audply_exit_popup_error,KEY_PLAY_STOP,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_exit_popup_error,KEY_FWD,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_exit_popup_error,KEY_BACK,KEY_EVENT_DOWN);
    SetSubLCDExitHandler(NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_main_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

MMI_BOOL mmi_sub_audply_entry_main_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_MAIN_SUBLCD, mmi_sub_audply_entry_main, 1);
    	return MMI_TRUE;	
    }
    return MMI_FALSE;	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_option_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

static MMI_BOOL mmi_sub_audply_entry_option_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_option, 1);
    	return MMI_TRUE;	
    }
    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_playlist_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

static MMI_BOOL mmi_sub_audply_entry_playlist_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_playlist, 1);
    	return MMI_TRUE;	
    }
    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_repeat_setting_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

static MMI_BOOL mmi_sub_audply_entry_repeat_setting_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_repeat_setting, 1);
    	return MMI_TRUE;	
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_main
 * DESCRIPTION
 *   exit sub LCD audio player 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_exit_main(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum_sub_lcd);
    #endif 
    gui_scrolling_text_stop(&audply_main_scrolling_title);
    UI_set_sub_LCD_graphics_context();  
    #ifdef __GDI_MEMORY_PROFILE_2__
	if(audply_skin_layer)
	{
    gdi_layer_flatten_to_base(audply_skin_layer, audply_osd_layer, 0, 0);
    gdi_layer_free(audply_skin_layer);
		audply_skin_layer = 0;
    gdi_layer_multi_layer_disable();
    gdi_layer_set_blt_layer(audply_osd_layer, 0, 0, 0);
	}
    #endif 
    if (!g_audply.background_play)
    {
        // There is a case that state = STATE_IDLE and need_replay = MMI_TRUE
        // and we need to prevent from replay after this function call by setting need_replay = MMI_FALSE
        g_audply.need_replay = MMI_FALSE;
        mmi_audply_stop_playing();
    }
    g_audply.in_sub_screen = MMI_FALSE;
    SubLCDHistory.entryFuncPtr = mmi_sub_audply_entry_main;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_AUDPLY_MAIN_SUBLCD);
    UI_set_main_LCD_graphics_context();
  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_main
 * DESCRIPTION
 *  entry sub LCD audio player screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        ExecSubLCDCurrExitHandler();
        UI_set_sub_LCD_graphics_context();
        ClearAllKeyHandler();
        mmi_sub_audply_popup_error_key_handler();
        UI_set_main_LCD_graphics_context();
        return;
    }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

	ExecSubLCDCurrExitHandler();
    UI_set_sub_LCD_graphics_context();
    ClearAllKeyHandler();
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    
    #ifdef __MMI_FM_RADIO__
    mmi_fmrdo_power_on(MMI_FALSE);
    #endif 
    
    /* initialization after re-power on */
    if (!g_mmi_audply_init_done)
    {
        //mmi_audply_get_fs_info();
    
        /* register mdi background handler */
//        g_audply.need_restore = MMI_FALSE;
        g_audply.wait_next = MMI_FALSE;
        g_audply.need_replay = MMI_FALSE;
        g_audply.in_list_screen = MMI_FALSE;
        g_audply.state = STATE_IDLE;
        g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
        if (FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
        {
            g_audply.present_list = (U8)SRV_FMGR_PUBLIC_DRV;
        }
        else
        {
            g_audply.present_list = g_audply.preferred_list;
        }
        if (g_audply.list_auto_gen)
    	{
            need_refresh_list = MMI_TRUE;
    	}
    }    
    else if (mmi_audply_playlist_is_empty())
    {
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;
    }

    mmi_audply_playlist_set_default_playlist_path();

    if (!g_mmi_audply_init_done)
    {
        if (mmi_audply_playlist_is_valid())
        {
            mmi_audply_need_load_playlist();
        }
        if (g_audply.list_auto_gen)
    	{
            need_refresh_list = MMI_TRUE;
    	}
    }
    g_mmi_audply_init_done = MMI_TRUE;
    g_audply.in_sub_screen = MMI_TRUE;
    g_audply.in_main_screen  = MMI_FALSE;
    mmi_sub_audply_update_main();
    SetSubLCDExitHandler(mmi_sub_audply_exit_main);   
    /* MTK Leo end */
    UI_set_main_LCD_graphics_context();
    
    SetDelScrnIDCallbackHandler(SCR_ID_AUDPLY_MAIN_SUBLCD, (HistoryDelCBPtr) mmi_sub_audply_delete_history_hdlr);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_option
 * DESCRIPTION
 *  exit sub LCD audio player option screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_exit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = (FuncPtr)mmi_sub_audply_entry_option;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_AUDPLY_OPTION_SUBLCD);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_option_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for sub LCD audio player option menu
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_sub_audply_option_highlighted_item = (U16) index;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_repeat_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for sub LCD audio player repeat setting menu
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_repeat_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_sub_audply_repeat_highlighted_item = (U16) index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_option
 * DESCRIPTION
 *  sub LCD audio player entry option menu
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[6];
    S32 n_items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();    
    ClearAllKeyHandler();
    if(!mmi_audply_playlist_is_empty())
    {
        option_texts[n_items] = STR_ID_AUDPLY_PLAYLIST;
        item_icons[n_items] = IMG_GLOBAL_L1;
		mmi_sub_audply_option_func[n_items] = (FuncPtr) mmi_sub_audply_entry_playlist_key_handler;			
        n_items++;

        option_texts[n_items] = STR_ID_AUDPLY_SETTINGS_REPEAT;
        item_icons[n_items] =  IMG_GLOBAL_L1+n_items;
		mmi_sub_audply_option_func[n_items]  =(FuncPtr) mmi_sub_audply_entry_repeat_setting_key_handler;		 
		n_items++;
    	if(g_audply.random_mode)			 
        {
        	option_texts[n_items] = STR_ID_AUDPLY_SETTINGS_SHUFFLE_ON;
	    }
    	else
        {
		    option_texts[n_items] = STR_ID_AUDPLY_SETTINGS_SHUFFLE_OFF;
        }
        item_icons[n_items] =  IMG_GLOBAL_L1+n_items;
		mmi_sub_audply_option_func[n_items] = mmi_sub_audply_shuffle_setting;		 
		n_items++;		 
				 
        option_texts[n_items] = STR_ID_AUDPLY_SUB_OPTION_EXIT;
        item_icons[n_items] =  IMG_GLOBAL_L1+n_items;
		mmi_sub_audply_option_func[n_items] = mmi_sub_audply_exit_audply_app;
		n_items++;
		
        RegisterHighlightHandler(mmi_sub_audply_option_highlight_hdlr);
         
        ShowCategory314Screen((U8*)get_string(STR_GLOBAL_OPTIONS), 
                                              IMG_GLOBAL_OPTIONS, 
                                              n_items, 
                                              option_texts, 
                                              item_icons, 
                                              NULL, 
                                              (S32) g_mmi_sub_audply_option_highlighted_item, 
                                              NULL);
         SetKeyHandler(mmi_sub_audply_option_lsk,KEY_BACK , KEY_EVENT_DOWN);
         SetKeyHandler(mmi_sub_audply_option_lsk,KEY_PLAY_STOP, KEY_EVENT_DOWN);
         SetKeyHandler(GoBackSubLCDHistory, KEY_FWD, KEY_EVENT_DOWN);
		  
    }
    else
    {
        mmi_sub_audply_refresh_list_key_handler();
    }
    SetSubLCDExitHandler(mmi_sub_audply_exit_option);
    UI_set_main_LCD_graphics_context();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_option_lsk
 * DESCRIPTION
 *  sub LCD audio player option's function
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_option_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sub_audply_option_func[g_mmi_sub_audply_option_highlighted_item]();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_option_lsk
 * DESCRIPTION
 *  sub LCD audio player option's function
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_shuffle_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      	   
	if(g_audply.random_mode)
	{
		g_audply.random_mode = 0;
		selected_random_mode = 0;

	}
	else
	{
        g_audply.random_mode = 1;
		selected_random_mode =1;
	}
    WriteValue(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE, &error);
    GoBackSubLCDHistory();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_playlist
 * DESCRIPTION
 *  entry sub LCD audio player playlist
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_entry_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id;
    S32 highlighted_item = 0;
    U8  total_drv_num;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    U8 driveletter;
    U8 *storage_str_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();   
    ClearAllKeyHandler();
	g_audply.in_sub_list_screen =  MMI_TRUE;

    /* title */
    
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    total_drv_num = srv_fmgr_drivelist_count(drvlist);
    driveletter =  g_audply.present_list;
    storage_str_p = (U8*)get_string(srv_fmgr_drv_get_string(driveletter));
    srv_fmgr_drivelist_destroy(drv_list);



    if (total_drv_num >1 && storage_str_p != NULL)
    {
        title_id = (g_audply.present_list == (U8)SRV_FMGR_PUBLIC_DRV) ? STR_ID_AUDPLY_LIST_FROM_PHONE : STR_ID_AUDPLY_LIST_FROM_CARD;
    }
    else
    {
        title_id = STR_ID_AUDPLY_PLAYLIST;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_audply_playlist_ui_highlight_hdlr);


    if (mmi_audply_playlist_get_current_index() >= 0)  /* highlighted item */
    {
        highlighted_item = mmi_audply_playlist_get_current_index();
    }
    else
    {
        highlighted_item = 0;   /* this should never happen */
    }
    
    /* show category screen */
    if (mmi_audply_playlist_is_empty())
    {
	    ASSERT(0);
    }
    else
    {
        /* if we delete some items and the previous highlighted item is out of boundary, set it to the last one */
		ShowCategory315Screen((U8 *)get_string(title_id), 
			GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
			mmi_audply_playlist_get_total(), 
			mmi_audply_playlist_get_item, 
			NULL, 
			(S32) highlighted_item, 
			MMI_FALSE,
			NULL, 
			NULL);

    }
    /* register LSK, RSK hanlders */

    /* register left right arrow key handler */
   SetKeyHandler(mmi_sub_audply_play_file_in_sub_playlist, KEY_BACK, KEY_EVENT_DOWN);
   SetKeyHandler(mmi_sub_audply_play_file_in_sub_playlist, KEY_PLAY_STOP, KEY_EVENT_DOWN);
   SetKeyHandler(GoBackSubLCDHistory, KEY_FWD, KEY_EVENT_DOWN);
   SetSubLCDExitHandler(mmi_sub_audply_exit_playlist); 
    /* register volume inc, dec handlers */
    UI_set_main_LCD_graphics_context();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_playlist
 * DESCRIPTION
 *  exit sub LCD audio player playlist
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_exit_playlist(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	SubLCDHistoryNode SubLCDHistory;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_audply.in_sub_list_screen =  MMI_FALSE;

	SubLCDHistory.entryFuncPtr = (FuncPtr)mmi_sub_audply_entry_playlist;
	AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_AUDPLY_PLAYLIST_SUBLCD);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_set_repeat
 * DESCRIPTION
 *  sub LCD audio player repeat setting
 * PARAMETERS
 *  null		
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_set_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();  
    ClearAllKeyHandler();
    g_audply.repeat_mode = g_mmi_sub_audply_repeat_highlighted_item;
    WriteValue(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE, &error);
    GoBackSubLCDHistory();
    UI_set_main_LCD_graphics_context();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_repeat_setting
 * DESCRIPTION
 *  entry sub LCD audio player repeat setting
 * PARAMETERS
 *  null		
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_entry_repeat_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[3] ;
    U16 item_texts[3];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();
    ClearAllKeyHandler();
    //g_mmi_audply_settings_repeat[0] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_OFF;
    //g_mmi_audply_settings_repeat[1] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ONCE;
    //g_mmi_audply_settings_repeat[2] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ALL;
    item_texts[0] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_OFF;
    item_texts[1] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ONCE;
    item_texts[2] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ALL;
    item_icons[0] = (g_audply.repeat_mode == REPEAT_OFF) ? IMG_ID_AUDPLY_SUB_SKIN_REPEAT_SELECTED:IMG_ID_AUDPLY_SUB_SKIN_REPEAT_NOT_SELECTED;
    item_icons[1] = (g_audply.repeat_mode == REPEAT_ONE) ? IMG_ID_AUDPLY_SUB_SKIN_REPEAT_SELECTED:IMG_ID_AUDPLY_SUB_SKIN_REPEAT_NOT_SELECTED;
    item_icons[2] = (g_audply.repeat_mode == REPEAT_ALL) ? IMG_ID_AUDPLY_SUB_SKIN_REPEAT_SELECTED:IMG_ID_AUDPLY_SUB_SKIN_REPEAT_NOT_SELECTED;
    g_mmi_sub_audply_repeat_highlighted_item = (U16)g_audply.repeat_mode;
	RegisterHighlightHandler(mmi_sub_audply_repeat_highlight_hdlr);
	ShowCategory314Screen((PU8)get_string(STR_ID_AUDPLY_SETTINGS_REPEAT),
							IMG_ID_AUDPLY_SETTINGS_REPEAT, 
							3,
							item_texts, 
							item_icons, 
							NULL, 
							(S32)g_mmi_sub_audply_repeat_highlighted_item, 
							NULL);
	
	SetKeyHandler(mmi_sub_audply_set_repeat, KEY_BACK,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_set_repeat,KEY_PLAY_STOP,KEY_EVENT_DOWN);
	SetKeyHandler(GoBackSubLCDHistory,KEY_FWD,KEY_EVENT_DOWN);
    UI_set_main_LCD_graphics_context();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_sub_audply_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_audply.background_play)
    {
        g_audply.need_replay = MMI_FALSE;
        mmi_audply_stop_playing();
    }
    g_audply.in_sub_screen = MMI_FALSE;
    if (need_refresh_list && g_audply.state != STATE_IDLE)
    {	
   	need_refresh_list = MMI_FALSE;
    }
    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_prev_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_press_prev_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PREV;
    g_audply_main_selected_button_down = MMI_TRUE;

    /* update button display */
    UI_set_sub_LCD_graphics_context();
    mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
    UI_set_main_LCD_graphics_context();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_prev_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_press_prev_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_PREV))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = MMI_FALSE;
       #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        gui_cancel_timer(mmi_audply_scroll_lyric_handler);
      #endif 
        StopTimer(AUDPLY_COUNT_PLAY_TIMER);
	    StopTimer(AUDPLY_DISPLAY_LYRICS_TIMER);
        /* pick the prev song */
        mmi_audply_playlist_pick_prev();
        if (mmi_audply_playlist_apply_picked_file())
        {
            if (g_audply.state == STATE_PLAY ||
                g_mmi_audply_play_completed_after_button_down || g_audply.need_replay
            #ifdef __MMI_A2DP_SUPPORT__
                || mmi_audply_is_wait_open_bt()
            #endif
                )
            {
                StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
                mmi_audply_do_stop_action(MMI_FALSE);
                #ifdef __MMI_A2DP_SUPPORT__
                    /* since filename is changed, we have to stop av bt open, or the configuration might be wrong */
                    mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
                #endif
                    StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);    /* wait for 0.7 second to request play */
                    g_audply.wait_next = MMI_TRUE;
            }

            mmi_audply_clear_play_seconds();
            
            /* update main title, file_index, time */

                UI_set_sub_LCD_graphics_context();
                mmi_audply_redraw_main_file_index();
                mmi_audply_redraw_main_title();
                mmi_audply_redraw_main_time();
	         	UI_set_main_LCD_graphics_context();
        }

        g_mmi_audply_play_completed_after_button_down = MMI_FALSE;

        /* update main buttons */
        if(g_audply.in_sub_screen)
        {
             UI_set_sub_LCD_graphics_context();
             mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
     	     UI_set_main_LCD_graphics_context();
       }
        else if(g_audply.in_sub_list_screen) 
         {
            dynamic_list_goto_item(mmi_audply_playlist_get_current_index());
        }   
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_next_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_press_next_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_NEXT;
    g_audply_main_selected_button_down = MMI_TRUE;

    /* update button display */
    UI_set_sub_LCD_graphics_context();            
    mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
    UI_set_main_LCD_graphics_context();  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_next_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_press_next_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_NEXT))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = MMI_FALSE;
        StopTimer(AUDPLY_COUNT_PLAY_TIMER);
		StopTimer(AUDPLY_DISPLAY_LYRICS_TIMER);
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        gui_cancel_timer(mmi_audply_scroll_lyric_handler);
    #endif 
        /* pick the next song */
        mmi_audply_playlist_pick_next();
        if (mmi_audply_playlist_apply_picked_file())
        {
            if (g_audply.state == STATE_PLAY || 
                g_mmi_audply_play_completed_after_button_down || g_audply.need_replay
            #ifdef __MMI_A2DP_SUPPORT__
                || mmi_audply_is_wait_open_bt()
            #endif
                )
            {
                StopTimer(AUDPLY_DELAY_PLAY_TIMER);
                mmi_audply_do_stop_action(MMI_FALSE);
            #ifdef __MMI_A2DP_SUPPORT__
                /* since filename is changed, we have to stop av bt open, or the configuration might be wrong */
                mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
            #endif
                StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);    /* wait for 0.7 second to request play */
                g_audply.wait_next = MMI_TRUE;
            }
               
            mmi_audply_clear_play_seconds();

            /* update main title, file_index, time */ 
                UI_set_sub_LCD_graphics_context();
                mmi_audply_redraw_main_file_index();
                mmi_audply_redraw_main_title();
                mmi_audply_redraw_main_time();
	            UI_set_main_LCD_graphics_context();   
        }

        g_mmi_audply_play_completed_after_button_down = MMI_FALSE;

        /* update main buttons */
        if(g_audply.in_sub_screen)
        {
            UI_set_sub_LCD_graphics_context();            
            mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
	        UI_set_main_LCD_graphics_context();
       }
        else if(g_audply.in_sub_list_screen)
        {
            dynamic_list_goto_item(mmi_audply_playlist_get_current_index());
        }   
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_play_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_press_play_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* update selected button state */
    g_audply_main_selected_button_down = MMI_TRUE;
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;  /* change selected button */
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
 #endif
    UI_set_sub_LCD_graphics_context();
    mmi_sub_audply_redraw_main_toggle_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
    UI_set_main_LCD_graphics_context();   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_play_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_press_play_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
   if (g_audply_main_selected_button_down && g_audply_main_selected_button == AUDPLY_MAIN_PLAY)
    {
        /* update selected button state */
        g_audply_main_selected_button_down = MMI_FALSE;

        if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
        {
            mmi_audply_pause();   /* do pause action */
        }
        else    /* g_audply.state == STATE_IDLE */
        {
            mmi_audply_play();    /* do play action */
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_play_file_in_sub_playlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_play_file_in_sub_playlist(void)
{
	mmi_audply_playlist_set_start(mmi_audply_playlist_get_current_highlight());
	mmi_audply_playlist_set_pick_index(mmi_audply_playlist_get_current_highlight());
	if (mmi_audply_playlist_apply_picked_file())
	{
		mmi_audply_stop_playing();
  		GoBackToSubLCDHistory(SCR_ID_AUDPLY_MAIN_SUBLCD);
		mmi_audply_play();
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sub_update_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sub_audply_update_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_update_main_button_flag();
    /* show main screen */
    mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_GLOBAL_LIST, STR_GLOBAL_BACK, g_audply.skin);

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    /* re print lyric, or it will  only be written while next lyric time tag is reached. */
    if (g_audply.lyrics_display && g_audply.state != STATE_IDLE && mmi_audply_is_lyrics_valid())
    {
    #ifndef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
        U8 new_encoding_type = PhnsetGetDefEncodingType() ;
        if(audply_lyric.lrc_encoding_chset != new_encoding_type )   
        {
            lyric_parse_ok = mmi_audply_init_lyric();
        }
    #else
        lyric_parse_ok = mmi_audply_init_lyric();
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__ */
    }
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    /*KEY_PLAY_STOP KEY_FWD KEY_BACK*/
    SetKeyHandler(mmi_sub_audply_press_prev_button_down, KEY_BACK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_press_prev_button_up, KEY_BACK, KEY_EVENT_UP);
        
    SetKeyHandler(mmi_sub_audply_press_next_button_down, KEY_FWD, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_press_next_button_up, KEY_FWD, KEY_EVENT_UP);
        
    SetKeyHandler(mmi_sub_audply_press_play_button_down, KEY_PLAY_STOP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_press_play_button_up, KEY_PLAY_STOP, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_PLAY_STOP, KEY_EVENT_REPEAT);
		
    SetKeyHandler((FuncPtr)mmi_sub_audply_entry_option_key_handler, KEY_PLAY_STOP, KEY_EVENT_LONG_PRESS);
}
#endif /* defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && defined(__MMI_AUDIO_PLAYER__)  */
