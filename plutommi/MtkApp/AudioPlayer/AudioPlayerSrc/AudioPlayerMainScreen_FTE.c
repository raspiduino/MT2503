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
*  AudioPlayerMainScreen.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main screen
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_AUDIO_PLAYER__
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
/* dependent headers for AudioPlayerXXX.h" */
#include "mdi_datatype.h"
#include "Conversions.h"
#include "FileManagerGProt.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "Gui_font_size.h"
#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGProt.h"
#endif

#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerPlayList.h"
#include "Filemgrsrvgprot.h"
#include "gui_touch_feedback.h"



#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);
#endif /*__MMI_TOUCH_SCREEN__*/

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gui_spectrum.h"
#endif 

#ifdef __MMI_A2DP_SUPPORT__
extern MMI_BOOL wait_open_bt;
#endif
#include "gpiosrvgprot.h"

/* Impacted by RHR */
#include "TimerEvents.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_audioplayer_def.h"

#define MAIN_SCREEN_VARIBALES
static MMI_BOOL init_images_done = MMI_FALSE;
static MMI_BOOL init_title_scrolling_done = MMI_FALSE;
/* gloabl variable. */
S16 g_audply_main_selected_button = AUDPLY_MAIN_DISABLED;
MMI_BOOL g_audply_main_selected_button_down = MMI_FALSE;
MMI_BOOL g_touch_play_button_flag = 0;


static color text_border_color;
static gdi_color text_bg_color;
static color text_fg_color;
static PU8 audply_main_bg_img;
static PU8 audply_main_pause_off_img;
static PU8 audply_main_pause_down_img;
static audply_main_title_struct audply_main_title;
static audply_main_time_struct audply_main_time;
static audply_main_file_index_struct audply_main_file_index;
static audply_main_playlisticon_struct audply_main_playlisticon;
static audply_main_volumebar_struct audply_main_volumebar;
static audply_main_progressbar_struct audply_main_progressbar;
static audply_main_volumectrl_struct audply_main_volume_inc, audply_main_volume_dec;

#ifdef __MMI_TOUCH_SCREEN__
static audply_main_setting_struct audply_main_setting;
static MMI_BOOL g_audply_main_pen_move_more_than_once ; /*to avoid play\pause icon keep changing from one another when pen move*/
static S32 g_audply_progress_bar_current_x_pos ; /*the x coordinate of progress bar to decide fast forward or rewind*/
static S32 g_audply_progress_bar_pen_down_x_pos ; /*the x coordinate of pen down action on progress bar for refine target time*/
extern void mmi_audply_seek_forward(void);
extern void mmi_audply_seek_rewind(void);
#endif /* __MMI_TOUCH_SCREEN__ */ 

audply_main_animation_struct audply_main_animation;

#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
static audply_main_repeat_struct audply_main_repeat;
static audply_main_shuffle_struct audply_main_shuffle;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

static audply_main_button_struct audply_main_buttons[NO_OF_AUDPLY_MAIN_BUTTONS];
static S16 audply_main_buttons_x1;
static S16 audply_main_buttons_y1;
static S16 audply_main_buttons_x2;
static S16 audply_main_buttons_y2;
static U8 audply_main_skin_index;
static scrolling_text audply_main_scrolling_title;
static UI_string_type audply_main_LSK_text;
static UI_string_type audply_main_RSK_text;

static audply_main_push_button_struct audply_main_LSK;
static audply_main_push_button_struct audply_main_RSK;

static audply_main_push_button_struct audply_vol_speaker;
static audply_main_push_button_struct audply_vol_speaker_mute;
/*Spectrum animation*/
audply_main_spec_animation_struct audply_spec_animation;

audply_main_push_button_struct LSK;

#ifdef __GDI_MEMORY_PROFILE_2__
GDI_HANDLE audply_osd_layer;
GDI_HANDLE audply_skin_layer;
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
GDI_HANDLE audply_old_bld_layer;
#endif
MMI_BOOL is_audply_skin_layer_drawn = MMI_FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

extern audply_struct g_audply;                              /* from AudioPlayerSrc.c */
extern const audply_skin_struct g_audply_skins[1]; /* from AudioPlayerSrc.c */
extern U32 g_mmi_audply_seek_target_time;
extern MMI_BOOL g_mmi_audply_longpressed;
//extern MMI_BOOL g_mmi_audply_non_play_longpressed;
extern U32 audio_build_cache_progress;
extern U8 audio_cache[BUILD_CACHE_SIZE];

extern UI_string_type MMI_title_string;                     /* from wgui_categories.c */
extern S32 MMI_title_height;                                /* from wgui_categories.c */
extern S32 UI_device_width;                                 /* from gui_wrapper.c */
extern S32 UI_device_height;                                /* from gui_wrapper.c */

extern MMI_BOOL g_mmi_audply_init_done; /* from AudioPlayerSrc.c */
extern BOOL r2lMMIFlag;             /* definedi n gui_inputs.c */

/* sub LCD */
#ifdef __MMI_SUBLCD__
static scrolling_text audply_sub_LCD_scrolling_title;
static scrolling_text *audply_sub_LCD_scrolling_title_p = NULL;
extern bitmap *current_LCD_device_bitmap;   /* defined in wgui.c */
extern bitmap main_LCD_device_bitmap;       /* defined in wingui.c */
extern bitmap sub_LCD_device_bitmap;        /* defined in wingui.c */
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TOUCH_SCREEN__
static S32 audply_pen_event_on_object = AUDPLY_PEN_NONE;
static mmi_pen_point_struct LSK_points[4];
static mmi_pen_point_struct RSK_points[4];
static mmi_pen_polygon_area_struct LSK_area;
static mmi_pen_polygon_area_struct RSK_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
extern MMI_BOOL g_audply_spectrum_blocked;
extern spectrum_struct g_aud_ply_spectrum;
#ifdef __MMI_SUBLCD__
extern spectrum_struct g_aud_ply_spectrum_sub_lcd;
#endif

//extern BOOL mmi_gpio_is_lcd_sleep(void);
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
extern audply_lyric_struct audply_lyric;
extern audply_lyric_printing_struct audply_lyric_print;
extern MMI_BOOL lyric_reEntry;
extern MMI_BOOL lyric_parse_ok;
#endif

extern scrolling_text *audply_scrolling_lyric_p1;

/* from History.c */
extern S32 mmi_is_redrawing_bk_screens(void);
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
static void mmi_audply_redraw_main_repeat_shuffle(void);
#endif
extern void mmi_audply_update_seeking_state(MMI_BOOL state);
extern MMI_BOOL mmi_audply_get_seeking_state(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_main_screen_images
 * DESCRIPTION
 *  init audio player main screen images
 * PARAMETERS
 *  skin        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_init_main_screen_images(U8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const audply_skin_struct *skin_p = &g_audply_skins[0];
    S32 i, w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bg */
    audply_main_bg_img = (PU8) GetImage(skin_p->bg_image_id);

    /* text_border_color, text fg, bg color */
    text_border_color = gui_color(skin_p->text_border_color_r, skin_p->text_border_color_g, skin_p->text_border_color_b);
    text_fg_color = gui_color(skin_p->text_fg_color_r, skin_p->text_fg_color_g, skin_p->text_fg_color_b);
#ifdef __GDI_MEMORY_PROFILE_2__
    text_bg_color = GDI_COLOR_TRANSPARENT ;   /* transparent */
#else 
    text_bg_color = gdi_act_color_from_rgb(255,skin_p->text_bg_color_r, skin_p->text_bg_color_g, skin_p->text_bg_color_b);
#endif 

	/*LSK*/
    audply_main_LSK.x = skin_p->lsk_pos_x;
	audply_main_LSK.y = skin_p->lsk_pos_y;
	audply_main_LSK.up_img = get_image(skin_p->lsk_up_img_id);
    audply_main_LSK.dis_img = get_image(skin_p->lsk_down_img_id);
	gui_measure_image(audply_main_LSK.dis_img, &w, &h);
	audply_main_LSK.w = w;
	audply_main_LSK.h = h;

	/*RSK*/
	audply_main_RSK.x = skin_p->rsk_pos_x;
	audply_main_RSK.y = skin_p->rsk_pos_y;
	audply_main_RSK.up_img = get_image(skin_p->rsk_up_img_id);
    audply_main_RSK.dis_img = get_image(skin_p->rsk_down_img_id);
	gui_measure_image(audply_main_RSK.dis_img, &w, &h);
	audply_main_RSK.w = w;
	audply_main_RSK.h = h;



    /* title */
    audply_main_title.x = skin_p->title_x;
    audply_main_title.y = skin_p->title_y;
    audply_main_title.w = skin_p->title_w;
    audply_main_title.h = skin_p->title_h;

    /* time */
    audply_main_time.x = skin_p->time_x;
    audply_main_time.y = skin_p->time_y;
    audply_main_time.w = skin_p->time_w;
    audply_main_time.h = skin_p->time_h;

    /* file index */
    audply_main_file_index.x = skin_p->file_index_x;
    audply_main_file_index.y = skin_p->file_index_y;
    audply_main_file_index.w = skin_p->file_index_w;
    audply_main_file_index.h = skin_p->file_index_h;

    /* play list icon */
    audply_main_playlisticon.x = skin_p->playlisticon_x;
    audply_main_playlisticon.y = skin_p->playlisticon_y;
    audply_main_playlisticon.list_icon[LIST_FROM_PHONE] =
        (PU8) GetImage(skin_p->playlisticon_images_id[LIST_FROM_PHONE]);
    audply_main_playlisticon.list_icon[LIST_FROM_CARD] = (PU8) GetImage(skin_p->playlisticon_images_id[LIST_FROM_CARD]);
    gdi_image_get_dimension(audply_main_playlisticon.list_icon[LIST_FROM_PHONE], &w, &h);

    audply_main_playlisticon.w = (S16) w;
    audply_main_playlisticon.h = (S16) h;

    /* volume */
    audply_main_volumebar.x = skin_p->volumebar_x;
    audply_main_volumebar.y = skin_p->volumebar_y;
    audply_main_volumebar.ind_len = skin_p->volumebar_ind_len;
    audply_main_volumebar.bar_direction = skin_p->volumebar_direction;
    audply_main_volumebar.ind_img = (PU8) GetImage(skin_p->volumebar_ind_image_id);
    gdi_image_get_dimension(audply_main_volumebar.ind_img, &w, &h);
    audply_main_volumebar.w = (S16) w;
    audply_main_volumebar.h = (S16) h;

    /*Volume_speaker On*/
     audply_vol_speaker.x = skin_p->volume_spk_pos_x;
     audply_vol_speaker.y = skin_p->volume_spk_pos_y;
     audply_vol_speaker.up_img = get_image(skin_p->volume_spk_out_up_img_id);
     audply_vol_speaker.dis_img = get_image(skin_p->volume_spk_out_down_img_id);
     gui_measure_image(audply_vol_speaker.up_img, &w, &h);
     audply_vol_speaker.w = w;
     audply_vol_speaker.h = h;
     /* VOlume speaker mute*/
     audply_vol_speaker_mute.up_img = get_image(skin_p->volume_spk_mute_up_img_id);
     audply_vol_speaker_mute.dis_img = get_image(skin_p->volume_spk_mute_down_img_id);
     
     /*Spectrum_animation_coordinates*/
     audply_spec_animation.x = skin_p->spec_animation_x;
     audply_spec_animation.y = skin_p->spec_animation_y;
     audply_spec_animation.w = skin_p->spec_animation_w;
     audply_spec_animation.h = skin_p->spec_animation_h;
    

    /* progress bar */
    audply_main_progressbar.x = skin_p->progressbar_x;
    audply_main_progressbar.y = skin_p->progressbar_y;
    audply_main_progressbar.img_bg = (PU8)GetImage(skin_p->progressbar_image_id_bg);
    audply_main_progressbar.img = (PU8) GetImage(skin_p->progressbar_image_id_fg);
    audply_main_progressbar.img_fail = (PU8) GetImage(skin_p->progressbar_image_id_mg);
    gui_measure_image(audply_main_progressbar.img, &w, &h);
    audply_main_progressbar.w = (S16) w;
    audply_main_progressbar.h = (S16) h;
    
    /* volume inc & dec control */
    audply_main_volume_inc.x = skin_p->volume_inc_x;
    audply_main_volume_inc.y = skin_p->volume_inc_y;
    audply_main_volume_inc.up_img = (PU8) GetImage(skin_p->volume_inc_up_image_id);
    audply_main_volume_inc.down_img = (PU8) GetImage(skin_p->volume_inc_down_image_id);
    audply_main_volume_inc.disable_img = (PU8) GetImage(skin_p->volume_inc_disable_image_id);
    gdi_image_get_dimension(audply_main_volume_inc.up_img, &w, &h);
    audply_main_volume_inc.w = (S16) w;
    audply_main_volume_inc.h = (S16) h;
    audply_main_volume_inc.down = MMI_FALSE;

    audply_main_volume_dec.x = skin_p->volume_dec_x;
    audply_main_volume_dec.y = skin_p->volume_dec_y;
    audply_main_volume_dec.up_img = (PU8) GetImage(skin_p->volume_dec_up_image_id);
    audply_main_volume_dec.down_img = (PU8) GetImage(skin_p->volume_dec_down_image_id);
    audply_main_volume_dec.disable_img = (PU8) GetImage(skin_p->volume_dec_disable_image_id);
    gdi_image_get_dimension(audply_main_volume_dec.up_img, &w, &h);
    audply_main_volume_dec.w = (S16) w;
    audply_main_volume_dec.h = (S16) h;
    audply_main_volume_dec.down = MMI_FALSE;
#ifdef __MMI_TOUCH_SCREEN__

    /* setting icon */
    audply_main_setting.x = skin_p->setting_x;
    audply_main_setting.y = skin_p->setting_y;
    audply_main_setting.up_img = (PU8) GetImage(skin_p->setting_up_image_id);
    audply_main_setting.down_img = (PU8) GetImage(skin_p->setting_down_image_id);
    gdi_image_get_dimension(audply_main_setting.up_img, &w, &h);
    audply_main_setting.w = (S16) w;
    audply_main_setting.h = (S16) h;
    audply_main_setting.down = MMI_FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* play, pause, stop, prev, next buttons */
    audply_main_buttons[AUDPLY_MAIN_PREV].x = skin_p->prev_button_x;
    audply_main_buttons[AUDPLY_MAIN_PREV].y = skin_p->prev_button_y;
    audply_main_buttons[AUDPLY_MAIN_PREV].off_img = (PU8) GetImage(skin_p->prev_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].disabled_img = (PU8) GetImage(skin_p->prev_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].down_img = (PU8) GetImage(skin_p->prev_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_NEXT].x = skin_p->next_button_x;
    audply_main_buttons[AUDPLY_MAIN_NEXT].y = skin_p->next_button_y;
    audply_main_buttons[AUDPLY_MAIN_NEXT].off_img = (PU8) GetImage(skin_p->next_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].disabled_img = (PU8) GetImage(skin_p->next_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].down_img = (PU8) GetImage(skin_p->next_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_PLAY].x = skin_p->play_button_x;
    audply_main_buttons[AUDPLY_MAIN_PLAY].y = skin_p->play_button_y;
    audply_main_buttons[AUDPLY_MAIN_PLAY].off_img = (PU8) GetImage(skin_p->play_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].disabled_img = (PU8) GetImage(skin_p->play_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].down_img = (PU8) GetImage(skin_p->play_button_down_image_id);
    audply_main_pause_off_img = (PU8) GetImage(skin_p->pause_button_off_image_id);
    audply_main_pause_down_img = (PU8) GetImage(skin_p->pause_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_STOP].x = skin_p->stop_button_x;
    audply_main_buttons[AUDPLY_MAIN_STOP].y = skin_p->stop_button_y;
    audply_main_buttons[AUDPLY_MAIN_STOP].off_img = (PU8) GetImage(skin_p->stop_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].disabled_img = (PU8) GetImage(skin_p->stop_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].down_img = (PU8) GetImage(skin_p->stop_button_down_image_id);

    /* calculate buttons boundary */
    gdi_image_get_dimension(audply_main_buttons[0].off_img, &w, &h);
    audply_main_buttons[0].w = (S16) w;
    audply_main_buttons[0].h = (S16) h;
    audply_main_buttons_x1 = audply_main_buttons[0].x;
    audply_main_buttons_y1 = audply_main_buttons[0].y;
    audply_main_buttons_x2 = audply_main_buttons[0].x + w - 1;
    audply_main_buttons_y2 = audply_main_buttons[0].y + h - 1;
    for (i = 1; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
        gdi_image_get_dimension(audply_main_buttons[i].off_img, &w, &h);
        audply_main_buttons[i].w = (S16) w;
        audply_main_buttons[i].h = (S16) h;
        if (audply_main_buttons[i].x < audply_main_buttons_x1)
        {
            audply_main_buttons_x1 = audply_main_buttons[i].x;
        }
        if (audply_main_buttons[i].y < audply_main_buttons_y1)
        {
            audply_main_buttons_y1 = audply_main_buttons[i].y;
        }
        if (audply_main_buttons[i].x + w - 1 > audply_main_buttons_x2)
        {
            audply_main_buttons_x2 = audply_main_buttons[i].x + w - 1;
        }
        if (audply_main_buttons[i].y + h - 1 > audply_main_buttons_y2)
        {
            audply_main_buttons_y2 = audply_main_buttons[i].y + h - 1;
        }
    }


    /* animation */
    audply_main_animation.x = skin_p->animation_x;
    audply_main_animation.y = skin_p->animation_y;
    audply_main_animation.animation_img = (PU8) GetImage(skin_p->animation_image_id);
    gdi_image_get_dimension(audply_main_animation.animation_img, &w, &h);
    audply_main_animation.w = (S16) w;
    audply_main_animation.h = (S16) h;


#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
    /* repeat */
    audply_main_repeat.x = skin_p->repeat_x;
    audply_main_repeat.y = skin_p->repeat_y;
    audply_main_repeat.off_up_img = (PU8) GetImage(skin_p->repeat_off_up_image_id);
    audply_main_repeat.all_up_img = (PU8) GetImage(skin_p->repeat_all_up_image_id);
    audply_main_repeat.one_up_img = (PU8) GetImage(skin_p->repeat_one_up_image_id);
#ifdef __MMI_TOUCH_SCREEN__
    audply_main_repeat.off_down_img = (PU8) GetImage(skin_p->repeat_off_down_image_id);
    audply_main_repeat.all_down_img = (PU8) GetImage(skin_p->repeat_all_down_image_id);
    audply_main_repeat.one_down_img = (PU8) GetImage(skin_p->repeat_one_down_image_id);
    audply_main_repeat.down = MMI_FALSE;
#endif /*__MMI_TOUCH_SCREEN__*/
    gdi_image_get_dimension(audply_main_repeat.off_up_img, &w, &h);
    audply_main_repeat.w = (S16) w;
    audply_main_repeat.h = (S16) h;
    /* shuffle */
    audply_main_shuffle.x = skin_p->shuffle_x;
    audply_main_shuffle.y = skin_p->shuffle_y;
    audply_main_shuffle.off_up_img = (PU8) GetImage(skin_p->shuffle_off_up_image_id);
    audply_main_shuffle.on_up_img = (PU8) GetImage(skin_p->shuffle_on_up_image_id);    
#ifdef __MMI_TOUCH_SCREEN__
    audply_main_shuffle.off_down_img = (PU8) GetImage(skin_p->shuffle_off_down_image_id);
    audply_main_shuffle.on_down_img = (PU8) GetImage(skin_p->shuffle_on_down_image_id);
    audply_main_shuffle.down = MMI_FALSE;
#endif /*__MMI_TOUCH_SCREEN__*/
    gui_measure_image(audply_main_shuffle.off_up_img, &w, &h);
    audply_main_shuffle.w = (S16) w;
    audply_main_shuffle.h = (S16) h;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_aud_ply_spectrum.target_lcd = GDI_LCD_MAIN_LCD_HANDLE;
    g_aud_ply_spectrum.start_x = skin_p->spectrum_display_x;
    g_aud_ply_spectrum.start_y = skin_p->spectrum_display_y;
    g_aud_ply_spectrum.width = skin_p->spectrum_display_w;
    g_aud_ply_spectrum.height = skin_p->spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    audply_lyric_print.start_x = skin_p->lyric_display_x;
    audply_lyric_print.start_y = skin_p->lyric_display_y;
    audply_lyric_print.width = skin_p->lyric_display_w;
    audply_lyric_print.height = skin_p->lyric_display_h;

    if(audply_lyric_print.start_x >= 0)
    {
        audply_lyric_print.lyric_fg_color = gui_color((U8)skin_p->lyric_fg_color_r, (U8)skin_p->lyric_fg_color_g, (U8)skin_p->lyric_fg_color_b);
        audply_lyric_print.lyric_border_color = gui_color((U8)skin_p->lyric_border_color_r, (U8)skin_p->lyric_border_color_g, (U8)skin_p->lyric_border_color_b);
    }

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__))
    /*if both lyircs and spec are valid and initially are both turned on and they shall be mutually exclusive
      force lyrics_display to be turned off*/
    if (mmi_audply_is_lyrics_valid() &&
		mmi_audply_is_spectrum_valid() &&
		mmi_audply_spectrum_lyrics_exclusive() &&
		g_audply.spectrum_style &&
		g_audply.lyrics_display)
    {
        g_audply.lyrics_display = 0;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_subLCD_background
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
void mmi_audply_redraw_subLCD_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(x1, y1, x2, y2, c);
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_subLCD_text_scroll_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_subLCD_text_scroll_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    gui_handle_scrolling_text(&audply_sub_LCD_scrolling_title);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_subLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_show     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_subLCD(MMI_BOOL is_show)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUB_WALLPAPER__
    color border_color = gui_color(0, 0, 0);
    color text_color = gui_color(255, 255, 255);
#else /* __MMI_SUB_WALLPAPER__ */ 
    color text_color = gui_color(0, 0, 0);
#endif /* __MMI_SUB_WALLPAPER__ */ 
    S32 x1, y1, x2, y2, x, y, str_w, str_h;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_audply_init_done)
    {
        return;
    }
    
    g_audply.is_subLCD_shown = MMI_TRUE;

    UI_set_sub_LCD_graphics_context();

    gui_lock_double_buffer();

    if (audply_sub_LCD_scrolling_title_p != NULL)
    {
        gui_scrolling_text_stop(audply_sub_LCD_scrolling_title_p);
        audply_sub_LCD_scrolling_title_p = NULL;
    }

    /* clear background */
    x1 = 0;
    y1 = 13;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    mmi_audply_redraw_subLCD_background(x1, y1, x2, y2);

    if (is_show)
    {
        /* draw song name */
        gui_set_font(&MMI_medium_font);
        gui_measure_string(g_audply.title, &str_w, &str_h);
    #ifdef __MMI_SUB_WALLPAPER__
        str_w += 1;
        str_h += 2;
    #endif /* __MMI_SUB_WALLPAPER__ */ 
        x = (UI_device_width - str_w) / 2;
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (g_audply.spectrum_style != 0 && mmi_audply_is_spectrum_valid() && !g_audply_spectrum_blocked)
        {
            y = 15;
        }
        else
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
            y = 12 + (UI_device_height - 12 - str_h) / 2;

        if (x >= 0)
        {
            gui_push_text_clip();
            gui_set_text_color(text_color);
        #ifdef __MMI_SUB_WALLPAPER__
            gui_set_text_border_color(border_color);
        #endif 
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(UI_device_width - x - 2, y);
            }
            else
            {
                gui_move_text_cursor(x, y);
            }
        #ifdef __MMI_SUB_WALLPAPER__
            gui_set_text_clip(x, y - 1, x + str_w - 1, y + str_h - 1);
            gui_print_bordered_text(g_audply.title);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            gui_set_text_clip(x, y, x + str_w - 1, y + str_h - 1);
            gui_print_text(g_audply.title);
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            gui_pop_text_clip();
        }
        else
        {
            /* scroll */
            x = 0;
            audply_sub_LCD_scrolling_title_p = &audply_sub_LCD_scrolling_title;
            mmi_ucs2cpy((CHAR*)g_audply.sub_title,(CHAR*)g_audply.title);
            gui_create_scrolling_text(audply_sub_LCD_scrolling_title_p,
                                      x + 2, y, UI_device_width - 4, str_h, g_audply.sub_title,
                                      mmi_audply_subLCD_text_scroll_handler, mmi_audply_redraw_subLCD_background,
                                      text_color,
        #ifdef __MMI_SUB_WALLPAPER__
                                      border_color
        #else 
                                      text_color
        #endif 
                );
            /* Leo start 20050906 */
        #ifdef __MMI_SUB_WALLPAPER__
            audply_sub_LCD_scrolling_title_p->flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
        #endif 
            /* Leo end */
            audply_sub_LCD_scrolling_title_p->text_font = MMI_medium_font;
            gui_show_scrolling_text(audply_sub_LCD_scrolling_title_p);
        }

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (g_audply.spectrum_style != 0 && !srv_backlight_is_lcd_sleep() && mmi_audply_is_spectrum_valid() && !g_audply_spectrum_blocked)
        {
            /* draw spectrum */
            g_aud_ply_spectrum_sub_lcd.target_layer = 0;
            g_aud_ply_spectrum_sub_lcd.target_lcd = GDI_LCD_SUB_LCD_HANDLE;
            g_aud_ply_spectrum_sub_lcd.start_x = 2;
            g_aud_ply_spectrum_sub_lcd.start_y = y + str_h + 2;
            g_aud_ply_spectrum_sub_lcd.height = UI_device_height - g_aud_ply_spectrum_sub_lcd.start_y - 4;
            g_aud_ply_spectrum_sub_lcd.width = UI_device_width - 4;
            g_aud_ply_spectrum_sub_lcd.style = g_audply.spectrum_style;
            switch (g_aud_ply_spectrum_sub_lcd.style)
            {
                case STYLE_BLOCKS:
                case STYLE_BARS:
                    g_aud_ply_spectrum_sub_lcd.number_of_bars = 16;
                    break;
                case STYLE_CIRCLES:
                    g_aud_ply_spectrum_sub_lcd.number_of_bars = 8;
                    break;
                default:
                    ASSERT(0);
            }

            mmi_audio_spectrum_init_display(&g_aud_ply_spectrum_sub_lcd);
            if (g_audply.state == STATE_PLAY)
            {
                mmi_audio_spectrum_start_display(&g_aud_ply_spectrum_sub_lcd);
            }
        }
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);

    gui_pop_clip();

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_subLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_subLCD()
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.is_subLCD_shown)
    {
        bitmap *saved_graphics_context;

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum_sub_lcd);
    #endif 

        saved_graphics_context = current_LCD_device_bitmap;

        UI_set_sub_LCD_graphics_context();

        if (audply_sub_LCD_scrolling_title_p != NULL)
        {
            gui_scrolling_text_stop(audply_sub_LCD_scrolling_title_p);
            audply_sub_LCD_scrolling_title_p = NULL;
        }
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }

        g_audply.is_subLCD_shown = MMI_FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_show_mainscreen
 * DESCRIPTION
 *  show audio player main screen
 * PARAMETERS
 *  title               [IN]        
 *  left_softkey        [IN]        
 *  right_softkey       [IN]        
 *  skin                [IN]        
 *  U8* history_buffer(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_show_mainscreen(U16 title, U16 left_softkey, U16 right_softkey, U8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bg_call = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        bg_call = MMI_TRUE;
    }
#endif
    
    MMI_title_string = (UI_string_type) GetString(title);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&audply_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    {
        gdi_layer_create(0, 0, UI_device_width, UI_device_height, &audply_skin_layer);
    }

    gdi_layer_push_and_set_active(audply_skin_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_set_blt_layer(audply_skin_layer, audply_osd_layer, 0, 0);
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        gdi_get_alpha_blending_source_layer(&audply_old_bld_layer);
        gdi_set_alpha_blending_source_layer(audply_skin_layer);
    #endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_aud_ply_spectrum.target_layer = audply_osd_layer;
#endif 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    audply_lyric_print.target_layer = audply_osd_layer;
#endif 

#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* init images */
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    if (!init_images_done || audply_main_skin_index != skin)
#endif        
    {
        mmi_audply_init_main_screen_images(skin);
        audply_main_skin_index = skin;
        init_images_done = MMI_TRUE;
        init_title_scrolling_done = MMI_FALSE;
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    is_audply_skin_layer_drawn = MMI_FALSE;
#endif 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (g_audply.spectrum_style != 0 )
    {
        g_aud_ply_spectrum.style = g_audply.spectrum_style;
        switch (g_aud_ply_spectrum.style)
        {
            case STYLE_BLOCKS:
            case STYLE_BARS:
                g_aud_ply_spectrum.number_of_bars = 16;
                break;
            case STYLE_CIRCLES:
                g_aud_ply_spectrum.number_of_bars = 8;
                break;
            default:
                ASSERT(0);
        }
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

            clear_key_handlers();
            clear_left_softkey();
            clear_right_softkey();
            audply_main_LSK_text = (UI_string_type) GetString(left_softkey);
            audply_main_RSK_text = (UI_string_type) GetString(right_softkey);
            if(!bg_call)
            {        
	        SetKeyHandler(mmi_audply_redraw_LSK_down, KEY_LSK, KEY_EVENT_DOWN);
            }
            SetKeyHandler(mmi_audply_redraw_RSK_down, KEY_RSK, KEY_EVENT_DOWN);

    /* associate functions */
    {
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    }
    /* draw screen */
    mmi_audply_redraw_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_mainscreen
 * DESCRIPTION
 *  exit audio player main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_mainscreen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&audply_main_scrolling_title);

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(audply_lyric.is_ready)
    {
    mmi_audply_stop_scroll_lyric_and_clean_screen();
    }
    mmi_audply_lyric_check_backlight(MMI_FALSE);
    lyric_reEntry = MMI_TRUE;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    mmi_audply_spectrum_display_stop();
#endif 


    /* stop animation */
    if (audply_main_animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(audply_main_animation.img_handle);
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        gdi_set_alpha_blending_source_layer(audply_old_bld_layer);
    #endif
	if(audply_skin_layer)
	{
    gdi_layer_flatten_to_base(audply_skin_layer, audply_osd_layer, 0, 0);
    gdi_layer_free(audply_skin_layer);
		audply_skin_layer = 0;
    gdi_layer_multi_layer_disable();
	}

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(audply_osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    audply_main_volume_inc.down = MMI_FALSE;
    audply_main_volume_dec.down = MMI_FALSE;
#ifdef __MMI_TOUCH_SCREEN__
    audply_main_setting.down = MMI_FALSE;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__    
    audply_main_repeat.down = MMI_FALSE;
    audply_main_shuffle.down = MMI_FALSE;
#endif
    audply_pen_event_on_object = AUDPLY_PEN_NONE;
    g_audply.curr_pen_state = AUDPLY_PEN_CURR_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_LSK_down
 * DESCRIPTION
 *  redraw shifted LSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_LSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 x1, y1, x2, y2;
    

	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);

#endif 

	x1 = audply_main_LSK.x;
	y1 = audply_main_LSK.y;
	x2=  audply_main_LSK.x + audply_main_LSK.w;
	y2 = audply_main_LSK.y + audply_main_LSK.h;

	gui_push_clip();
	
	gui_set_clip(x1, y1, x2, y2);

	/* button */
    gui_show_image(x1, y1, audply_main_LSK.dis_img);

	 gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_RSK_down
 * DESCRIPTION
 *  redraw shifted RSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_RSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


	
     S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 

	x1 = audply_main_RSK.x;
	y1 = audply_main_RSK.y;
	x2=  audply_main_RSK.x + audply_main_RSK.w;
	y2 = audply_main_RSK.y + audply_main_RSK.h;

	gui_push_clip();
	
	gui_set_clip(x1, y1, x2, y2);

	/* button */
    gui_show_image(x1, y1, audply_main_RSK.dis_img);

	 gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_LSK_up
 * DESCRIPTION
 *  redraw shifted LSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_LSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 x1, y1, x2, y2;
    PU8 draw_img = audply_main_LSK.up_img;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
   gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 

	x1 = audply_main_LSK.x;
	y1 = audply_main_LSK.y;
	x2=  x1 + audply_main_LSK.w;
	y2 = y1 + audply_main_LSK.h;

    gui_push_clip();
	
	gui_set_clip(x1, y1, x2, y2);

	if (is_audply_skin_layer_drawn)
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_layer_push_and_set_active(audply_skin_layer);
        gui_push_clip();
        gui_set_clip(LSK_points[0].x, LSK_points[0].y, LSK_points[2].x, LSK_points[2].y);
        gui_show_image(0, 0, audply_main_bg_img);
        gui_show_image(x1, y1, draw_img);
        gui_pop_clip();
        gdi_layer_pop_and_restore_active();

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    #else 
        gui_show_image(x1,y1, draw_img);
    #endif 
    }
    else
    {
        gui_show_image(x1, y1, draw_img);
    }
	
	
	gui_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 
 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_RSK_up
 * DESCRIPTION
 *  redraw shifted RSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_RSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 x1, y1, x2, y2;
    PU8 draw_img = audply_main_RSK.up_img;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 

	x1 = audply_main_RSK.x;
	y1 = audply_main_RSK.y;
	x2=  x1 + audply_main_RSK.w;
	y2 = y1 + audply_main_RSK.h;

    gui_push_clip();
	
	gui_set_clip(x1, y1, x2, y2);

	if (is_audply_skin_layer_drawn)
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_layer_push_and_set_active(audply_skin_layer);
        gui_push_clip();
        gui_set_clip(RSK_points[0].x, RSK_points[0].y, RSK_points[2].x, RSK_points[2].y);
        gui_show_image(0, 0, audply_main_bg_img);
        gui_show_image(x1, y1, draw_img);
        gui_pop_clip();
        gdi_layer_pop_and_restore_active();

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    #else 
        gui_show_image(x1,y1, draw_img);
    #endif 
    }
    else
    {
        gui_show_image(x1, y1, draw_img);
    }
	
	gui_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 


}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_screen
 * DESCRIPTION
 *  redraw audio player main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bg_call = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        bg_call = MMI_TRUE;
    }
#endif
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background ,head, LSK, and RSK */
#ifdef __GDI_MEMORY_PROFILE_2__
    if (!is_audply_skin_layer_drawn)
    {
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

        /*show backgroud image*/
        mmi_audply_redraw_background();
		
		/*show progress_bar_background image*/
		mmi_audply_redraw_background_progress_bar();
		
            /*show satatus bar*/
    #if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
            wgui_status_icon_bar_register_hide_callback(
                WGUI_STATUS_ICON_BAR_H_BAR, 
                mmi_audply_redraw_statusbar_bg_callback);
            wgui_set_wallpaper_on_bottom(MMI_TRUE);
            wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
            wgui_status_icon_bar_update();
    #endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
     if (!(g_audply.spectrum_style != 0 &&
        mmi_audply_is_spectrum_valid() &&
             !g_audply_spectrum_blocked && g_audply.state == STATE_PLAY))
            /* show animation */
    {
            mmi_audply_redraw_animation();
        }
#else
     mmi_audply_redraw_animation();

#endif/*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
	
        
	           
            /* show LSK */
            if(!bg_call)
            {
                mmi_audply_redraw_main_LSK();
            }
            /* show RSK */
            mmi_audply_redraw_main_RSK();
            
#ifdef __GDI_MEMORY_PROFILE_2__
        is_audply_skin_layer_drawn = MMI_TRUE;
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    #ifdef __MMI_TOUCH_SCREEN__
        /*show setting icon*/
       // mmi_audply_redraw_main_setting(audply_main_setting.down);
    #endif /* __MMI_TOUCH_SCREEN__ */ 

        /*repeat and shuffle*/
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
        mmi_audply_redraw_main_repeat_shuffle();
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

        /*vol control*/
        if (g_audply.volume == MDI_AUD_VOL_EX_NUM - 1)
        {
            mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
        }
        else
        {
            mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
        }
        
        if (g_audply.volume == 0)
        {
            mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
			mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
        }
        else
        {
            mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
			mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
        }     
        

        /*buttons*/

    {
        mmi_audply_redraw_main_buttons();
    }

    /*play list icon*/
   // mmi_audply_redraw_main_playlisticon();

	
        /*show progress bar*/
        mmi_audply_redraw_main_progressbar();

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
     if (g_audply.spectrum_style != 0 &&
             mmi_audply_is_spectrum_valid() &&
             !g_audply_spectrum_blocked && g_audply.state == STATE_PLAY)
     {
         mmi_audply_redraw_spec_blank_area();
         
     }
#endif

    /*main title*/
    mmi_audply_redraw_main_title();
    /*file index*/
    mmi_audply_redraw_main_file_index();
    /*main time*/
    mmi_audply_redraw_main_time();
    /*main vol bar*/        
    mmi_audply_redraw_main_volumebar();


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (!mmi_is_redrawing_bk_screens())
    {
    if (g_audply.spectrum_style != 0 && mmi_audply_is_spectrum_valid() && !g_audply_spectrum_blocked)
    {
            if (g_audply.state == STATE_PLAY)
            {
                /* start calc top and vals */
                mmi_audply_calc_spectrum(MMI_TRUE);
           	    mmi_audio_spectrum_init_display(&g_aud_ply_spectrum);
         	    mmi_audio_spectrum_start_display(&g_aud_ply_spectrum);
            }
    }
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_statusbar_bg_callback
 * DESCRIPTION
 *  redraw the background of status bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_statusbar_bg_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    gdi_layer_push_and_set_clip(cx1, cy1, cx2, cy2);
    gdi_image_draw(0,0,audply_main_bg_img);
    gdi_layer_pop_clip();
}
#endif /* __MMI_MAINLCD_240X400__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_title_background
 * DESCRIPTION
 *  redraw audio player main title background
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_title_background(S32 x1, S32 y1, S32 x2, S32 y2)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_scroll_main_title_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_scroll_main_title_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&audply_main_scrolling_title);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_background_progress_bar
 * DESCRIPTION
 *  redraw audio player background progress bar image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_background_progress_bar(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 x1 = audply_main_progressbar.x;
    S32 y1 = audply_main_progressbar.y;
    S32 x2 = audply_main_progressbar.x + audply_main_progressbar.w - 1;
    S32 y2 = audply_main_progressbar.y + audply_main_progressbar.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_MEMORY_PROFILE_2__
     gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	gdi_image_draw(x1, y1, audply_main_progressbar.img_bg);
      
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
     gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_background
 * DESCRIPTION
 *  redraw audio player background image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_background(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_MEMORY_PROFILE_2__
     gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
    gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_image_draw(0, 0, audply_main_bg_img);
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
     gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_animation
 * DESCRIPTION
 *  redraw audio player animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_skin_layer);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_anim_set_blt_after_callback(mmi_audply_anim_blt_after_callback);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    audply_main_animation.img_handle = GDI_ERROR_HANDLE;
    gdi_image_draw_animation(
        audply_main_animation.x,
        audply_main_animation.y,
        audply_main_animation.animation_img,
        &audply_main_animation.img_handle);

    /* gdi will not blt first frame, so we need blt it self */
    gdi_image_get_dimension(audply_main_animation.animation_img, &width, &height);
    gdi_layer_blt_previous(
        audply_main_animation.x,
        audply_main_animation.y,
        audply_main_animation.x + width,
        audply_main_animation.y + height);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
}

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_title_for_anim
 * DESCRIPTION
 *  redraw audio player main title only for animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_redraw_main_title_for_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height, w;
    S32 x1 = audply_main_title.x;
    S32 y1 = audply_main_title.y;
    S32 x2 = audply_main_title.x + audply_main_title.w - 1;
    S32 y2 = audply_main_title.y + audply_main_title.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifndef __MMI_MAINLCD_320X480__
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_large_font);
#endif

    gui_set_text_color(text_fg_color);
    gui_measure_string(g_audply.title, &w, &character_height);

    if (w > audply_main_title.w)
    {
        gui_redraw_scrolling_text(&audply_main_scrolling_title);
    }
    else
    {
        /* background */
        mmi_audply_redraw_main_title_background(x1, y1, x2, y2);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (audply_main_title.w + w) / 2, y1);
        }
        else
        {
            gui_move_text_cursor(x1 + (audply_main_title.w - w) / 2, y1);
        }
        gui_set_line_height(character_height);
        gui_print_text(g_audply.title);
    }
    gdi_layer_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_anim_blt_after_callback
 * DESCRIPTION
 *  redraw strings on animation after a frame animation blt
 * PARAMETERS
 *  GDI_RESULT  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_anim_blt_after_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < GDI_SUCCEED || g_audply.in_main_screen != MMI_TRUE)
    {
        return;
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_osd_layer);
#endif
    if (init_title_scrolling_done)
    {
        mmi_audply_redraw_main_title_for_anim();
    }

    mmi_audply_redraw_main_file_index();

    mmi_audply_redraw_main_time();
    
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
    if (audply_lyric.is_ready && audply_lyric.cur_line && audply_scrolling_lyric_p1 != NULL)
    {
        gui_redraw_scrolling_text(audply_scrolling_lyric_p1);
    }
#endif

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif 
}
#endif /*__MMI_VECTOR_FONT_SUPPORT__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_AP_title
 * DESCRIPTION
 *  redraw audio player main AP title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_AP_title(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1;
    color head_text_color = gui_color(255, 255, 255);
    S32 height_base = 0 ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));

    gui_set_text_color(head_text_color);
    gui_set_text_border_color(text_border_color);
    
    gui_measure_string(MMI_title_string, &str_w, &str_h);
    gui_set_line_height(str_h);
    if (str_w > UI_device_width)
    {
        str_w = UI_device_width;
    }
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    height_base = MMI_status_bar_height-1;
#endif
    gdi_layer_push_and_set_clip(0, height_base, UI_device_width - 1, height_base+MMI_title_height - 1);
    if (r2lMMIFlag)
    {
        x1 = (UI_device_width + str_w) / 2;
    }
    else
    {
        x1 = (UI_device_width - str_w) / 2;
    }
    gui_print_truncated_borderd_text(x1, height_base+((MMI_title_height - str_h)/2) , UI_device_width - 2, MMI_title_string);
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 


}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_LSK
 * DESCRIPTION
 *  redraw audio player main LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_LSK(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 x1, y1, x2, y2;
    PU8 draw_img = audply_main_LSK.up_img;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
  gdi_layer_push_and_set_active(audply_skin_layer);
  gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 

	x1 = audply_main_LSK.x;
	y1 = audply_main_LSK.y;
	x2=  x1 + audply_main_LSK.w;
	y2 = y1 + audply_main_LSK.h;

    gui_push_clip();
	
	gui_set_clip(x1, y1, x2, y2);

	gui_show_image(x1, y1, draw_img);
	
	gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
	LSK_area.num = 4;
    LSK_area.points = (mmi_pen_point_struct*) LSK_points;
    LSK_points[0].x = LSK_points[3].x = x1;
    LSK_points[0].y = LSK_points[1].y = y1;
    LSK_points[1].x = LSK_points[2].x = x2 + 1;
    LSK_points[2].y = LSK_points[3].y = y2 + 1;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_RSK
 * DESCRIPTION
 *  redraw audio player main RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_RSK(void)
{


	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 x1, y1, x2, y2;
    PU8 draw_img = audply_main_RSK.up_img;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
  gdi_layer_push_and_set_active(audply_skin_layer);
  gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 

	x1 = audply_main_RSK.x;
	y1 = audply_main_RSK.y;
	x2=  x1 + audply_main_RSK.w;
	y2 = y1 + audply_main_RSK.h;

    gui_push_clip();
	
	gui_set_clip(x1, y1, x2, y2);

	gui_show_image(x1, y1, draw_img);
	
	gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
	RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = x1;
    RSK_points[0].y = RSK_points[1].y = y1;
    RSK_points[1].x = RSK_points[2].x = x2 + 1;
    RSK_points[2].y = RSK_points[3].y = y2 + 1;
	

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_title
 * DESCRIPTION
 *  redraw audio player main title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height, w;
    S32 x1 = audply_main_title.x;
    S32 y1 = audply_main_title.y;
    S32 x2 = audply_main_title.x + audply_main_title.w - 1;
    S32 y2 = audply_main_title.y + audply_main_title.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previous scroll text */
    if (init_title_scrolling_done)
    {
        gui_scrolling_text_stop(&audply_main_scrolling_title);
    }
    else
    {
        init_title_scrolling_done = MMI_TRUE;
    }

    gui_create_scrolling_text(
        &audply_main_scrolling_title,
        x1,
        y1,
        audply_main_title.w,
        audply_main_title.h,
        g_audply.title,
        mmi_audply_scroll_main_title_handler,
        mmi_audply_redraw_main_title_background,
        text_fg_color,
        text_border_color);
    audply_main_scrolling_title.text_font = MMI_medium_font;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    /* title */
    gui_scrolling_text_stop(&audply_main_scrolling_title);
#ifndef __MMI_MAINLCD_320X480__
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_large_font);
#endif

    gui_set_text_color(text_fg_color);
    gui_measure_string(g_audply.title, &w, &character_height);

    if (w > audply_main_title.w)
    {
        /* scrolling */
        gui_change_scrolling_text(&audply_main_scrolling_title, g_audply.title);
        gui_show_scrolling_text(&audply_main_scrolling_title);
    }
    else
    {
        /* background */
        mmi_audply_redraw_main_title_background(x1, y1, x2, y2);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (audply_main_title.w + w) / 2, y1);
        }
        else
        {
            gui_move_text_cursor(x1 + (audply_main_title.w - w) / 2, y1);
        }
        gui_set_line_height(character_height);
        gui_print_text(g_audply.title);
    }

    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_playlisticon
 * DESCRIPTION
 *  redraw audio player present play list icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_playlisticon(void)
{
#if !defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_playlisticon.x;
    S32 y1 = audply_main_playlisticon.y;
    S32 x2 = audply_main_playlisticon.x + audply_main_playlisticon.w - 1;
    S32 y2 = audply_main_playlisticon.y + audply_main_playlisticon.h - 1;
    U8 playlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_audply.present_list == (U8)SRV_FMGR_CARD_DRV)
    {
        playlist = LIST_FROM_CARD;
    }
    else
    {
        playlist = LIST_FROM_PHONE;
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* play list icon */

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_image_draw(x1, y1, audply_main_playlisticon.list_icon[playlist]);
    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_volume_speaker
 * DESCRIPTION
 *  redraw audio player speaker icon
 * PARAMETERS
 *  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_volume_speaker(MMI_BOOL mute)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_vol_speaker.x;
    S32 y1 = audply_vol_speaker.y;
    S32 x2 = audply_vol_speaker.x + audply_vol_speaker.w - 1;
    S32 y2 = audply_vol_speaker.y + audply_vol_speaker.h - 1;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 


    /* speaker icon */

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	if (mute)
	{
		gdi_image_draw(x1, y1, audply_vol_speaker_mute.up_img);
	}
	else
	{
		gdi_image_draw(x1, y1, audply_vol_speaker.up_img);
	}

    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 	

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 


}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_time
 * DESCRIPTION
 *  redraw audio player main time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_time.x;
    S32 y1 = audply_main_time.y;
    S32 x2 = audply_main_time.x + audply_main_time.w - 1;
    S32 y2 = audply_main_time.y + audply_main_time.h - 1;
    S32 str_w, str_h;
    CHAR temp[16];
	UI_character_type time_str[16];
    U32 elapsed_seconds = mmi_audply_get_play_seconds();
	U32 total_duration = g_audply.duration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	if (elapsed_seconds > total_duration)
	{
		total_duration = elapsed_seconds;
	}

    if (mmi_audply_playlist_is_empty())
    {
	total_duration = 0;
    }


    elapsed_seconds = elapsed_seconds + 500;
    elapsed_seconds /= 1000 ;
	total_duration = total_duration + 500;
	total_duration /= 1000;
    sprintf(temp, "%02d:%02d / %02d:%02d", elapsed_seconds / 60, elapsed_seconds % 60,total_duration / 60,total_duration % 60);
    mmi_asc_to_ucs2((CHAR*) time_str, (CHAR*) temp);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & time */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);

#ifdef __MMI_MAINLCD_240X400__
    gui_set_font(&MMI_small_font);
#else
    gui_set_font(&MMI_small_font);
#endif
    gui_set_text_color(text_fg_color);
    gui_measure_string(time_str, &str_w, &str_h);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + (audply_main_time.w + str_w) / 2, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + (audply_main_time.w - str_w) / 2, y1 + 1);
    }
    gui_print_text(time_str);
    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_file_index
 * DESCRIPTION
 *  mmi_audply_redraw_main_file_index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_file_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_file_index.x;
    S32 y1 = audply_main_file_index.y;
    S32 x2 = audply_main_file_index.x + audply_main_file_index.w - 1;
    S32 y2 = audply_main_file_index.y + audply_main_file_index.h - 1;
    S32 str_w, str_h;
    CHAR temp[24];
    UI_character_type file_index[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_audply_playlist_is_empty())
    {
        S32 total = mmi_audply_playlist_get_total();
        S32 index = mmi_audply_playlist_get_current_index();
        sprintf(temp, "%d/%d", index + 1, total);
    }
    else
    {
        sprintf(temp, "0/0");
    }
    mmi_asc_to_ucs2((CHAR*) file_index, (CHAR*) temp);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & file index */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);

    gui_set_font(&MMI_medium_font);
    gui_set_text_color(text_fg_color);
    gui_measure_string(file_index, &str_w, &str_h);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + (audply_main_file_index.w + str_w) / 2, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + (audply_main_file_index.w - str_w) / 2, y1 + 1);
    }
    gui_print_text(file_index);
    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_volumebar
 * DESCRIPTION
 *  redraw audio player main volume bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_volumebar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_volumebar.x;
    S32 y1 = audply_main_volumebar.y;
    S32 x2 = audply_main_volumebar.x + audply_main_volumebar.w - 1;
    S32 y2 = audply_main_volumebar.y + audply_main_volumebar.h - 1;
    U32 diff = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(audply_main_volumebar.bar_direction == HORIZONTAL_VOL_BAR )
    {
        diff = audply_main_volumebar.ind_len + 
             ((U32) g_audply.volume) * (audply_main_volumebar.w - 
             audply_main_volumebar.ind_len) / MDI_AUD_VOL_EX_NUM;
        if (diff > (U32) audply_main_volumebar.w)
        {
            diff = (U32) audply_main_volumebar.w;
        }
    }
    else if(audply_main_volumebar.bar_direction == VERTICAL_VOL_BAR )
    {
        diff = audply_main_volumebar.ind_len + 
             ((U32) g_audply.volume) * (audply_main_volumebar.h - 
             audply_main_volumebar.ind_len) / MDI_AUD_VOL_EX_NUM;
        if (diff > (U32) audply_main_volumebar.h)
        {
            diff = (U32) audply_main_volumebar.h;
        }
    }
    else
    {
        ASSERT(0);
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 


    /* background & indicator */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2); 
    
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);

    if(audply_main_volumebar.bar_direction == HORIZONTAL_VOL_BAR)
    {
        gdi_layer_set_clip(x1, y1, x1 + diff, y2);
    }else
    {
        gdi_layer_set_clip(x1, y1+audply_main_volumebar.h-diff, x2, y2);
    }

    gdi_image_draw(x1, y1, audply_main_volumebar.ind_img);
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 


#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_volumectrl
 * DESCRIPTION
 *  redraw audio player main volume inc / dec control
 * PARAMETERS
 *  sel         [IN]        0 -> dec, 1 -> inc
 *  down        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_volumectrl(U8 sel, MMI_BOOL down, MMI_BOOL disable)
{
/* because Land scape 128x128 and 128x160 without touch screen should not show volume ctrl buttons. */    
#if (((LCD_WIDTH > 128) && (LCD_HEIGHT > 160)) || ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160) && defined(__MMI_TOUCH_SCREEN__)))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    audply_main_volumectrl_struct *volumectrl_p = (sel == 0) ? &audply_main_volume_dec : &audply_main_volume_inc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = volumectrl_p->x;
    y1 = volumectrl_p->y;
    x2 = volumectrl_p->x + volumectrl_p->w - 1;
    y2 = volumectrl_p->y + volumectrl_p->h - 1;
    /* update the down state */
    volumectrl_p->down = down;

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2); 
    if (disable)
    {
        gdi_image_draw(x1, y1, volumectrl_p->disable_img);
    }
    else
    {
        gdi_image_draw(x1, y1, (down ? volumectrl_p->down_img : volumectrl_p->up_img));
    }
    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */

    kal_sleep_task(20);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_progressbar
 * DESCRIPTION
 *  redraw audio player main progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_progressbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_progressbar.x;
    S32 y1 = audply_main_progressbar.y;
    S32 x2 = audply_main_progressbar.x + audply_main_progressbar.w - 1;
    S32 y2 = audply_main_progressbar.y + audply_main_progressbar.h - 1;
    U32 dx ; 
	S32 but_w, but_h;
	S32 x, y;
    U32 elapsed_ms = mmi_audply_get_play_seconds();
    MMI_BOOL seekable = g_audply.seekable;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        seekable = MMI_FALSE;
    }
#endif

	gdi_image_get_dimension_id(IMG_ID_AUDPLY_FTE_PROGRESS_BTN, 
                &but_w, &but_h);

	if (elapsed_ms >= g_audply.duration)
	{
		dx = (U32)(audply_main_progressbar.w - but_w);
	}
	else
	{
		dx = (U32)((audply_main_progressbar.w - but_w) * ((float)elapsed_ms/(float)g_audply.duration)) ;
	}


#ifdef __MMI_TOUCH_SCREEN__
    g_audply_progress_bar_current_x_pos = x1 + dx ;
#endif    

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

	
	y = y2 - (((y2 - y1) + but_h) / 2);            
    x = x1 - (but_w / 2);
    gdi_layer_push_and_set_clip(x1, y, x2, y + but_h);
	gdi_draw_solid_rect(x1, y, x2, y + but_h, GDI_COLOR_BLACK);
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);

    if(seekable)
    {
		U16 img_id =  g_audply.curr_pen_state != AUDPLY_PEN_PRESSED ? IMG_ID_AUDPLY_FTE_PROGRESS_BTN : IMG_ID_AUDPLY_FTE_PROGRESS_BTN_HL;
		x = x1 + dx;


		gdi_layer_set_clip(x, y, x + but_w, y + but_w);   
#ifdef __MMI_MAINLCD_240X320__
		gdi_draw_solid_rect(x, y, x + but_w - 1, y + but_w , GDI_COLOR_BLACK);
#endif
        gdi_image_draw_id(x, y, img_id);

#ifdef __MMI_MAINLCD_240X400__
	gdi_layer_set_clip(x1-1, y, x1, y + but_h);
	gdi_draw_solid_rect(x1-1, y, x1, y + but_h, GDI_COLOR_BLACK);
#endif /*__MMI_MAINLCD_240X400__*/
        /*update for touch*/
    }

	if(seekable)
    {
        gdi_layer_set_clip(x1, y1, x1 + dx, y2);
        if (elapsed_ms != 0)
        {
            gdi_image_draw(x1, y1, audply_main_progressbar.img);
        }
    }
    else
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_image_draw(x1, y1, audply_main_progressbar.img_fail);
    }
    
    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y, x2, y + but_h);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_repeat_shuffle
 * DESCRIPTION
 *  redraw audio player main repeat and shuffle icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_redraw_main_repeat_shuffle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1, y1, x2, y2;
    PU8 image_id = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 
    
    /* show repeat icon */
    x1 = (S32) audply_main_repeat.x;
    y1 = (S32) audply_main_repeat.y;
    x2 = x1 + audply_main_repeat.w - 1;
    y2 = y1 + audply_main_repeat.h - 1;
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    switch (g_audply.repeat_mode)
    {
        case REPEAT_OFF:
            image_id = audply_main_repeat.off_up_img;
            break;
        case REPEAT_ALL:
            image_id = audply_main_repeat.all_up_img;
            break;
        case REPEAT_ONE:
            image_id = audply_main_repeat.one_up_img;
            break;
        default:
            ASSERT(0);
    }

	

    
    gdi_image_draw(x1, y1, image_id);

    /* show shuffle icon */
    x1 = (S32) audply_main_shuffle.x;
    y1 = (S32) audply_main_shuffle.y;
    x2 = x1 + audply_main_shuffle.w - 1;
    y2 = y1 + audply_main_shuffle.h - 1;
    gdi_layer_set_clip(x1, y1, x2, y2);
    switch (g_audply.random_mode)
    {
        case SHUFFLE_OFF:
            image_id = audply_main_shuffle.off_up_img;
            break;
        case SHUFFLE_ON:
            image_id = audply_main_shuffle.on_up_img;
            break;
        default:
            ASSERT(0);
    }
    gdi_image_draw(x1, y1, image_id);

    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
   gdi_pop_and_restore_alpha_blending_source_layer();
#endif /* __GDI_MEMORY_PROFILE_2__ */

}
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_buttons
 * DESCRIPTION
 *  redraw audio player main buttons
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S16 selected_button = g_audply_main_selected_button;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        selected_button = AUDPLY_MAIN_DISABLED;
    }
#endif


#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */



    /* background & buttons */
    gdi_layer_push_and_set_clip(audply_main_buttons_x1, audply_main_buttons_y1, audply_main_buttons_x2, audply_main_buttons_y2);

    /*Redraw Play/Pause button, choose by state.*/
    if (selected_button == AUDPLY_MAIN_DISABLED)
    {
        gdi_image_draw(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_buttons[AUDPLY_MAIN_PLAY].disabled_img);
    }
    else if (selected_button == AUDPLY_MAIN_PLAY && g_audply_main_selected_button_down)
    {
        /*if (g_audply.state == STATE_PLAY)
        {
            gdi_image_draw(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_pause_down_img);
        }
        else*/
        {
            gdi_image_draw(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_buttons[AUDPLY_MAIN_PLAY].down_img);
        }
    }
    else if (selected_button == AUDPLY_MAIN_PAUSE && g_audply_main_selected_button_down)
    {
        if (g_audply.state == STATE_PLAY)
        {
            gdi_image_draw(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_pause_down_img);
        }
    }
    else
    {
        if (g_audply.state == STATE_PLAY)
        {
            gdi_image_draw(audply_main_buttons[AUDPLY_MAIN_PLAY].x,audply_main_buttons[AUDPLY_MAIN_PLAY].y,audply_main_pause_off_img);
        }
        else
        {
            gdi_image_draw(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_buttons[AUDPLY_MAIN_PLAY].off_img);
        }
    }
    /*Redraw Prev, Next, Stop button*/
    for (i = AUDPLY_MAIN_PREV; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
        if (selected_button == AUDPLY_MAIN_DISABLED)
        {
            gdi_image_draw(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].disabled_img);
        }
        else if (selected_button == i && g_audply_main_selected_button_down)
        {
            gdi_image_draw(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].down_img);
        }
        else
        {
            gdi_image_draw(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].off_img);
        }
    }
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif /* __GDI_MEMORY_PROFILE_2__ */
	

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        audply_main_buttons_x1,
        audply_main_buttons_y1,
        audply_main_buttons_x2,
        audply_main_buttons_y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 


}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_proportional_time_from_x
 * DESCRIPTION
 *  calculate the proportional time of audio content from input coordinate
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the current x coordinate
 *****************************************************************************/
S32 mmi_audply_get_current_x_coordinate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_audply_progress_bar_current_x_pos ;
}

static U32 mmi_audply_get_proportional_time_from_x_internal(S16 cor_x);
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_proportional_time_from_x
 * DESCRIPTION
 *  calculate the proportional time of audio content from input coordinate
 * PARAMETERS
 *  cor_x         [IN]      x coordinate
 * RETURNS
 *  returns the proportional time according to the input x coordinate in ms
 *****************************************************************************/
U32 mmi_audply_get_proportional_time_from_x_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_audply_get_proportional_time_from_x_internal((S16)g_audply_progress_bar_pen_down_x_pos);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_proportional_time_from_x_internal
 * DESCRIPTION
 *  calculate the proportional time of audio content from input coordinate
 * PARAMETERS
 *  cor_x         [IN]      x coordinate
 * RETURNS
 *  returns the proportional time according to the input x coordinate in ms
 *****************************************************************************/
static U32 mmi_audply_get_proportional_time_from_x_internal(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cor_x -= audply_main_progressbar.x ;
   
    if(cor_x<0)   /*in front of progress bar, set time to 0*/
    {
        return 0;
    }
    else if(cor_x > audply_main_progressbar.w)  /*in back of progress bar, set time to druation*/
    {
        return g_audply.duration;
    }
    else /*proportional time*/
    {
        return (U32)(g_audply.duration * ((float)cor_x / (float)audply_main_progressbar.w)) ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_setting
 * DESCRIPTION
 *  redraw audio player main setting icon
 * PARAMETERS
 *  down        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_setting(MMI_BOOL down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_setting.x;
    S32 y1 = audply_main_setting.y;
    S32 x2 = audply_main_setting.x + audply_main_setting.w - 1;
    S32 y2 = audply_main_setting.y + audply_main_setting.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update the down state */
    audply_main_setting.down = down;

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_image_draw(x1, y1, (down ? audply_main_setting.down_img : audply_main_setting.up_img));
    gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */
}

#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_repeat
 * DESCRIPTION
 *  redraw audio player main repeat icon
 * PARAMETERS
 *  down        [IN]        to indicate weather the button is up or down.
 *                          down = TURE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_repeat(MMI_BOOL down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S32 x1 = (S32) audply_main_repeat.x;
    S32 y1 = (S32) audply_main_repeat.y;
    S32 x2 = x1 + audply_main_repeat.w - 1;
    S32 y2 = y1 + audply_main_repeat.h - 1;


    PU8 image_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /* update the down state */
    audply_main_repeat.down = down;

    switch (g_audply.repeat_mode)
    {
        case REPEAT_OFF:
            image_id = down ? audply_main_repeat.off_down_img : audply_main_repeat.off_up_img ; 
            break;
        case REPEAT_ALL:
            image_id = down ? audply_main_repeat.all_down_img: audply_main_repeat.all_up_img; 
            break;
        case REPEAT_ONE:
            image_id = down ? audply_main_repeat.one_down_img: audply_main_repeat.one_up_img; 
            break;
        default:
            ASSERT(0);
    }

	

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 



    /* background & indicator */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_image_draw(x1, y1, image_id);
    gdi_layer_pop_clip();

	
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 	

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_repeat_toggle
 * DESCRIPTION
 *  handle the switching action among repear sates.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_repeat_toggle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.repeat_mode = (g_audply.repeat_mode + 1)%3 ;
    index = mmi_audply_playlist_get_current_index();
    if (index >= 0)
    {
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_shuffle
 * DESCRIPTION
 *  redraw audio player main shuffle icon
 * PARAMETERS
 *  down        [IN]        to indicate weather the button is up or down.
 *                          down = TURE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_shuffle(MMI_BOOL down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = (S32) audply_main_shuffle.x;
    S32 y1 = (S32) audply_main_shuffle.y;
    S32 x2 = x1 + audply_main_shuffle.w - 1;
    S32 y2 = y1 + audply_main_shuffle.h - 1;

    PU8 image_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update the down state */
    audply_main_shuffle.down = down;

    switch (g_audply.random_mode)
    {
        case SHUFFLE_OFF:
            image_id = down ? audply_main_shuffle.off_down_img : audply_main_shuffle.off_up_img ; 
            break;
        case SHUFFLE_ON:
            image_id = down ? audply_main_shuffle.on_down_img: audply_main_shuffle.on_up_img; 
            break;
        default:
            ASSERT(0);
    }


#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif 


    /* background & indicator */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_image_draw(x1, y1, image_id);
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
#endif 


#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 


}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_repeat_toggle
 * DESCRIPTION
 *  handle the switching action among repear sates.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_shuffle_toggle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.random_mode = (g_audply.random_mode + 1)%2 ;
    index = mmi_audply_playlist_get_current_index();
    if (index >= 0)
    {
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }
}
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
	MMI_BOOL is_touch_feed = MMI_FALSE;
	MMI_BOOL is_touch_flag_buttons = MMI_FALSE;
	MMI_BOOL is_play_touched = MMI_FALSE;
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audply_pen_event_on_object = AUDPLY_PEN_NONE;
	g_audply.curr_pen_state = AUDPLY_PEN_CURR_NONE;
	
    for (i = AUDPLY_PEN_LSK; i < AUDPLY_PEN_COUNT; i++)
    {
        switch (i)
        {
            case AUDPLY_PEN_LSK:
                area = (mmi_pen_polygon_area_struct*) & LSK_area;
                point = pos;
                break;
            case AUDPLY_PEN_RSK:
                area = (mmi_pen_polygon_area_struct*) & RSK_area;
                point = pos;
                break;
            case AUDPLY_PEN_SEEK:
                area = (mmi_pen_polygon_area_struct*) & skin_p->seek_area;
                point.x = pos.x - skin_p->progressbar_x;
                point.y = pos.y - skin_p->progressbar_y;
                break;
            case AUDPLY_PEN_MAIN_PREV:
                area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
                point.x = pos.x - skin_p->prev_button_x;
                point.y = pos.y - skin_p->prev_button_y;
                break;
            case AUDPLY_PEN_MAIN_NEXT:
                area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
                point.x = pos.x - skin_p->next_button_x;
                point.y = pos.y - skin_p->next_button_y;
                break;
            case AUDPLY_PEN_MAIN_STOP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
                point.x = pos.x - skin_p->stop_button_x;
                point.y = pos.y - skin_p->stop_button_y;
                break;
            case AUDPLY_PEN_MAIN_PLAY:
                area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
                point.x = pos.x - skin_p->play_button_x;
                point.y = pos.y - skin_p->play_button_y;
                break;
            case AUDPLY_PEN_MAIN_SETTING:
                area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                break;
        #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__                
            case AUDPLY_PEN_MAIN_REPEAT:
                area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
                point.x = pos.x - skin_p->repeat_x;
                point.y = pos.y - skin_p->repeat_y;
                break;
            case AUDPLY_PEN_MAIN_SHUFFLE:
                area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
                point.x = pos.x - skin_p->shuffle_x;
                point.y = pos.y - skin_p->shuffle_y;
                break;
        #endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
            case AUDPLY_PEN_MAIN_VOLUME_INC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
                point.x = pos.x - skin_p->volume_inc_x;
                point.y = pos.y - skin_p->volume_inc_y;
                break;
            case AUDPLY_PEN_MAIN_VOLUME_DEC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                break;
        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            audply_pen_event_on_object = i;
			is_touch_feed = MMI_TRUE;
            break;
        }
    }

#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        switch (audply_pen_event_on_object)
        {
            case AUDPLY_PEN_RSK:
            case AUDPLY_PEN_MAIN_SETTING:
        #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
            case AUDPLY_PEN_MAIN_REPEAT:
            case AUDPLY_PEN_MAIN_SHUFFLE:
        #endif
            case AUDPLY_PEN_MAIN_VOLUME_INC:
            case AUDPLY_PEN_MAIN_VOLUME_DEC:
            {
                break;
            }

            default:
            {
                audply_pen_event_on_object = AUDPLY_PEN_NONE;
            }
        }
    }
#endif

    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_LSK:
            mmi_audply_redraw_LSK_down();
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            break;
        case AUDPLY_PEN_RSK:
            mmi_audply_redraw_RSK_down();
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            break;
        case AUDPLY_PEN_SEEK:
			if(mmi_audply_is_playing())
			{
				is_play_touched=MMI_TRUE;
			}
            if(g_audply.seekable)
            {
		g_audply.curr_pen_state = AUDPLY_PEN_PRESSED;
                g_audply_progress_bar_pen_down_x_pos = pos.x ;
                mmi_audply_touch_progress_hdlr(pos.x);
            }
			else
			{
				is_touch_feed = MMI_FALSE;

			}
			is_touch_flag_buttons = MMI_TRUE;
            break;
        case AUDPLY_PEN_MAIN_PREV:
            mmi_audply_press_prev_button_down();
			is_touch_flag_buttons = MMI_TRUE;
            break;
        case AUDPLY_PEN_MAIN_NEXT:
            mmi_audply_press_next_button_down();
			is_touch_flag_buttons = MMI_TRUE;
            break;
        case AUDPLY_PEN_MAIN_STOP:
            mmi_audply_press_stop_button_down();
			is_touch_flag_buttons = MMI_TRUE;
            break;
        case AUDPLY_PEN_MAIN_PLAY:
            g_audply_main_pen_move_more_than_once = MMI_FALSE ;
            mmi_audply_press_play_button_down();
			is_touch_flag_buttons = MMI_TRUE;
			is_play_touched=MMI_TRUE;
            break;
        case AUDPLY_PEN_MAIN_SETTING:
           // mmi_audply_redraw_main_setting(MMI_TRUE);
            break;
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
        case AUDPLY_PEN_MAIN_REPEAT:
            mmi_audply_redraw_main_repeat(MMI_TRUE);
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            mmi_audply_redraw_main_shuffle(MMI_TRUE);
            break;            
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            if (g_audply.volume == MDI_AUD_VOL_EX_NUM - 1)
            {
                mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_TRUE);
				mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
            }
            else
            {                
                mmi_audply_press_inc_volume();
                if (g_audply.volume > 0)
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
					mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
					mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                }
               
                mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_FALSE);
            }
			
            break;
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            if (g_audply.volume == 0)
            {
                mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_TRUE);
				mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
            }
            else
            {
                mmi_audply_press_dec_volume();
                
                if (g_audply.volume < MDI_AUD_VOL_EX_NUM - 1)
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
					mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
					mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                }
                mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_FALSE);
				mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
            }
            break;
    }
    
	if (is_touch_feed)
	{
		if (mmi_audply_playlist_is_empty())
		{
			if (!is_touch_flag_buttons)
			{	
				gui_touch_feedback_enable_tone();
				g_touch_play_button_flag = MMI_FALSE;
				//mdi_audio_suspend_background_play();
				kal_prompt_trace(MOD_MMI,"mmi_audply_pen_down_hdlr: g_touch_play_button_flag = 0");
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
				gui_touch_feedback_disable_tone();
			}
			else
			{
				is_touch_flag_buttons = MMI_FALSE;
			}
			
		}
		else
		{
			if ( !is_play_touched && !mmi_audply_is_playing())
			{	
				gui_touch_feedback_enable_tone();
				g_touch_play_button_flag = MMI_FALSE;
				//mdi_audio_suspend_background_play();
				kal_prompt_trace(MOD_MMI,"mmi_audply_pen_down_hdlr: g_touch_play_button_flag = 0");
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
				gui_touch_feedback_disable_tone();
			}
			else if (!mmi_audply_is_playing())
			{
			    gui_touch_feedback_enable_tone();
				g_touch_play_button_flag = MMI_TRUE;
				mdi_audio_suspend_background_play();
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
				gui_touch_feedback_disable_tone();
			}
			else
			{
			    kal_prompt_trace(MOD_MMI,"mmi_audply_pen_down_hdlr: g_touch_play_button_flag = 1 ");
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN_VIBRATE);
			}
			is_touch_feed = MMI_FALSE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_abort_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    mmi_pen_point_struct point;
//    mmi_pen_polygon_area_struct *area = NULL;
//    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audply_pen_event_on_object)
    {
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */            
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
        case AUDPLY_PEN_LSK:
            mmi_audply_redraw_LSK_up();
            break;
        case AUDPLY_PEN_RSK:
            mmi_audply_redraw_RSK_up();
            break;
    }
    g_audply_main_selected_button_down = MMI_FALSE;
    audply_pen_event_on_object = AUDPLY_PEN_NONE;
	g_audply.curr_pen_state = AUDPLY_PEN_CURR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[0];
	g_audply.curr_pen_state = AUDPLY_PEN_RELEASED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* For touch_feedback*/
	
	if (g_touch_play_button_flag)
	{
		 kal_prompt_trace(MOD_MMI,"mmi_audply_pen_up_hdlr: stop feedback sound");
		mdi_audio_stop_string();
		mdi_audio_resume_background_play();
		g_touch_play_button_flag =MMI_FALSE;
	}

    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_SEEK:
			if(mmi_audply_get_seeking_state() == AUDPLY_SEEK_STATE_REWIND)
			{
				mmi_audply_seek_rewind();
				StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_touch_progress_pen_up);
				return;
			}
			else if(mmi_audply_get_seeking_state() == AUDPLY_SEEK_STATE_FORWARD)
			{
				mmi_audply_seek_forward();
				StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_touch_progress_pen_up);
			    return;
			}
			//g_audply.curr_pen_state = AUDPLY_PEN_RELEASED;
            mmi_audply_touch_progress_pen_up();
            break;
        case AUDPLY_PEN_MAIN_NEXT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
            point.x = pos.x - skin_p->next_button_x;
            point.y = pos.y - skin_p->next_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_next_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_PREV:
            area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
            point.x = pos.x - skin_p->prev_button_x;
            point.y = pos.y - skin_p->prev_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_prev_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
            point.x = pos.x - skin_p->stop_button_x;
            point.y = pos.y - skin_p->stop_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_stop_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_PLAY:
            area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
            point.x = pos.x - skin_p->play_button_x;
            point.y = pos.y - skin_p->play_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_play_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_SETTING:
            area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
            point.x = pos.x - skin_p->setting_x;
            point.y = pos.y - skin_p->setting_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {    
              //  mmi_audply_redraw_main_setting(MMI_FALSE);  
            #if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
                mmi_audply_entry_two_layers_settings();
            #elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
                if (AUDPLY_SETTING_ITEM_COUNT <= 10)
                {
                 //   mmi_audply_entry_settings();
                }
                else
                {
                  //  mmi_audply_entry_two_layers_settings();
                }
            #endif
            }
            break;
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
        case AUDPLY_PEN_MAIN_REPEAT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
            point.x = pos.x - skin_p->repeat_x;
            point.y = pos.y - skin_p->repeat_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_touch_repeat_toggle();
                mmi_audply_redraw_main_repeat(MMI_FALSE);
            }
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
            point.x = pos.x - skin_p->shuffle_x;
            point.y = pos.y - skin_p->shuffle_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_touch_shuffle_toggle();
                mmi_audply_redraw_main_shuffle(MMI_FALSE);
            }
            break;            
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */            
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
            point.x = pos.x - skin_p->volume_dec_x;
            point.y = pos.y - skin_p->volume_dec_y;
            if (g_audply.volume == 0)
            {
                mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
		mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
            }
            else
            {
                mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
		mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
            } 
            break;
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
            point.x = pos.x - skin_p->volume_inc_x;
            point.y = pos.y - skin_p->volume_inc_y;
            if (g_audply.volume == MDI_AUD_VOL_EX_NUM - 1)
            {
                mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
            }
            else
            {
                mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
		mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
            } 
            break;
        case AUDPLY_PEN_LSK:
            mmi_audply_redraw_LSK_up();
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            break;
        case AUDPLY_PEN_RSK:
            mmi_audply_redraw_RSK_up();
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
            break;
    }

    audply_pen_event_on_object = AUDPLY_PEN_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_SEEK:
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_PROGRESS_PEN_MOVE,g_audply.seekable);
            if(g_audply.seekable)
            {
                g_audply_progress_bar_pen_down_x_pos = pos.x ;
                mmi_audply_touch_progress_seeking(pos.x);
            }
            break;
		case AUDPLY_PEN_MAIN_NEXT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
            point.x = pos.x - skin_p->next_button_x;
            point.y = pos.y - skin_p->next_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_next_button_down();
            }
            else
            {
                if (g_audply.in_main_screen)
                {
                    g_audply_main_selected_button_down = MMI_FALSE;
                    /* when stop button down, the play button will be switched to play icon
                       but, if the stylus is moved out of the button, it shall switch back to 
                       pause icon.*/
					StopTimer(AUDPLY_SEEKING_TIMER);
                    if(g_audply.state == STATE_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }                    
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
		case AUDPLY_PEN_MAIN_PREV:
            area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
            point.x = pos.x - skin_p->prev_button_x;
            point.y = pos.y - skin_p->prev_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_prev_button_down();
            }else
            {                
                if (g_audply.in_main_screen)
                {
                    g_audply_main_selected_button_down = MMI_FALSE;
                    /* when stop button down, the play button will be switched to play icon
                       but, if the stylus is moved out of the button, it shall switch back to 
                       pause icon.*/
					StopTimer(AUDPLY_SEEKING_TIMER);
                    if(g_audply.state == STATE_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }                    
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
		case AUDPLY_PEN_MAIN_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
            point.x = pos.x - skin_p->stop_button_x;
            point.y = pos.y - skin_p->stop_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_stop_button_down();
            }
            else
            {
                if (g_audply.in_main_screen)
                {
                    g_audply_main_selected_button_down = MMI_FALSE;
                    /* when stop button down, the play button will be switched to play icon
                       but, if the stylus is moved out of the button, it shall switch back to 
                       pause icon.*/
                    if(g_audply.state == STATE_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
		case AUDPLY_PEN_MAIN_PLAY:
            area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
            point.x = pos.x - skin_p->play_button_x;
            point.y = pos.y - skin_p->play_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                g_audply_main_pen_move_more_than_once = MMI_FALSE;
                mmi_audply_press_play_button_down();
            }else
            {
                if (g_audply.in_main_screen && !g_audply_main_pen_move_more_than_once)
                {
                    g_audply_main_selected_button_down = MMI_FALSE;
                    g_audply_main_pen_move_more_than_once = MMI_TRUE ;
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
        case AUDPLY_PEN_MAIN_SETTING:
            area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
            point.x = pos.x - skin_p->setting_x;
            point.y = pos.y - skin_p->setting_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
              //  mmi_audply_redraw_main_setting(MMI_TRUE);
            }else
            {
                //mmi_audply_redraw_main_setting(MMI_FALSE);
            }           
            break;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__                
        case AUDPLY_PEN_MAIN_REPEAT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
            point.x = pos.x - skin_p->repeat_x;
            point.y = pos.y - skin_p->repeat_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_repeat(MMI_TRUE);
            }else
            {
                mmi_audply_redraw_main_repeat(MMI_FALSE);
            }
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
            point.x = pos.x - skin_p->shuffle_x;
            point.y = pos.y - skin_p->shuffle_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_shuffle(MMI_TRUE);
            }else
            {
                mmi_audply_redraw_main_shuffle(MMI_FALSE);
            }
            break;
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
            point.x = pos.x - skin_p->volume_inc_x;
            point.y = pos.y - skin_p->volume_inc_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                if (g_audply.volume < MDI_AUD_VOL_EX_NUM - 1)
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_FALSE);
		    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_TRUE);
					
                }
            }
            else
            {
                if (g_audply.volume < MDI_AUD_VOL_EX_NUM - 1)
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
		    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
					
                }
            }
            break;
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
            point.x = pos.x - skin_p->volume_dec_x;
            point.y = pos.y - skin_p->volume_dec_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                if (g_audply.volume > 0)
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_FALSE);
		    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_TRUE);
					mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                }
            }
            else
            {
                if (g_audply.volume > 0)
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
		    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
		    mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                }
            }
            break;
        case AUDPLY_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_audply_redraw_LSK_down();
            }
            else
            {
                mmi_audply_redraw_LSK_up();
            }
            break;
        case AUDPLY_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                mmi_audply_redraw_RSK_down();
            }
            else
            {
                mmi_audply_redraw_RSK_up();
            }
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_repeat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
            point.x = pos.x - skin_p->volume_inc_x;
            point.y = pos.y - skin_p->volume_inc_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                if (g_audply.volume == MDI_AUD_VOL_EX_NUM - 1)
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_TRUE);
                }
                else
                {
            
                    mmi_audply_press_inc_volume();
                    if (g_audply.volume > 0)
                    {
                        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
			mmi_audply_redraw_main_volume_speaker(MMI_FALSE);

                    }
                    else
                    {
                        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
			mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                    }
                    
                    mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_FALSE);
                }
            }
            break;
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
            point.x = pos.x - skin_p->volume_dec_x;
            point.y = pos.y - skin_p->volume_dec_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                if (g_audply.volume == 0)
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_TRUE);
		    mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                }
                else
                {
                    mmi_audply_press_dec_volume();
                    if (g_audply.volume < MDI_AUD_VOL_EX_NUM - 1)
                    {
                        mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
                    }
                    else
                    {
                        mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
                    }
                    mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_FALSE);
		    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                }
            }
            break;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_long_tab_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
  S16 i;
  mmi_pen_point_struct point;
  mmi_pen_polygon_area_struct *area = NULL;
  const audply_skin_struct *skin_p = &g_audply_skins[0];
  

	/*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/

	for (i = AUDPLY_PEN_LSK; i < AUDPLY_PEN_COUNT; i++)
	{
		switch (i)
        {
			case AUDPLY_PEN_MAIN_PREV:
                area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
                point.x = pos.x - skin_p->prev_button_x;
                point.y = pos.y - skin_p->prev_button_y;
				if (mmi_pen_check_inside_polygon(area, point))
				{
					mmi_audply_press_prev_button_longpress();
				}
                break;

            case AUDPLY_PEN_MAIN_NEXT:
                area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
                point.x = pos.x - skin_p->next_button_x;
                point.y = pos.y - skin_p->next_button_y;
				if (mmi_pen_check_inside_polygon(area, point))
				{
					mmi_audply_press_next_button_longpress();
				}
				break;

			default:
				break;

		}
     
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_progress_seeking
 * DESCRIPTION
 *  decide the touch seeking direction (fast forward/rewind)
 * PARAMETERS
 *  cor_x       [IN]    x coordinate of touch down position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_progress_seeking(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 current_x ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    current_x =  mmi_audply_get_current_x_coordinate();
    g_mmi_audply_seek_target_time = mmi_audply_get_proportional_time_from_x_internal(cor_x);
    /*compare x cordinate*/
    if(cor_x >= current_x)
    {
        /*fast forward*/
	mmi_audply_update_seeking_state(AUDPLY_SEEK_STATE_FORWARD);
        StopTimer(AUDPLY_SEEKING_TIMER);
	StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_seek_forward);
    }
    else
    {
        /*rewind*/
	mmi_audply_update_seeking_state(AUDPLY_SEEK_STATE_REWIND);
        StopTimer(AUDPLY_SEEKING_TIMER);
	StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_seek_rewind);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_progress_hdlr
 * DESCRIPTION
 *  take care the touch progress build cache and progress bar drawing
 *  we think of touch progress the same as longpress action
 * PARAMETERS
 *  cor_x       [IN]    x coordinate of touch down position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_progress_hdlr(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_TOUCH_PROGRESS_HDLR);
    /*while wait next, the touch progress shall do nothing*/
    if(g_audply.wait_next)
    {
        audply_pen_event_on_object = AUDPLY_PEN_NONE ;
        return;
    }

    g_mmi_audply_longpressed = MMI_TRUE;

    /*stop file even in MMI it looks like it's only paused for seeking*/
    g_audply.state_before_longpress = g_audply.state;
    if (!g_audply.seekable)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_TOUCH_NOT_SEEKABLE);
        return;
    }
    if (g_audply.state != STATE_IDLE
    #ifdef __MMI_A2DP_SUPPORT__
        || wait_open_bt
    #endif    	
    	)
    {
    #ifdef __MMI_A2DP_SUPPORT__
        if(wait_open_bt)
        {
            g_audply.state_before_longpress = STATE_PLAY;
        }
    #endif    	
        mmi_audply_seek_stop_playing();
        g_audply_main_selected_button_down = MMI_FALSE;
        //mmi_audply_redraw_main_buttons();
    }
    else
    {
        /*check and refresh cache*/
        mmi_audply_refresh_cache(MMI_TRUE);
    }

    if (g_audply.need_to_build_cache && audio_build_cache_progress < 100)
    {
        /*send message to med_v to start process*/
        mdi_audio_start_build_cache((kal_wchar*)g_audply.filefullname,
                                    audio_cache, 
                                    BUILD_CACHE_SIZE,
                                    g_audply.audio_cache_file_buf_p,
                                    BUILD_CACHE_FILE_BUF_SIZE,
                                    g_audply.audio_cache_proc_buf_p,
                                    BUILD_CACHE_PROC_BUF_SIZE,
                                    mmi_audply_build_cache_fail_callback_hdlr,
                                    &audio_build_cache_progress);  
     }

    StopTimer(AUDPLY_COUNT_PLAY_TIMER);

    mmi_audply_touch_progress_seeking(cor_x);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_progress_pen_up
 * DESCRIPTION
 *  handle play potion after progress pen up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_progress_pen_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
     StopTimer(AUDPLY_SEEKING_TIMER);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_TOUCH_PROGRESS_PEN_UP,g_mmi_audply_longpressed);

    /* if it's not longpressed, it means it is blocked 
       by wait next, so pen up shall do nothing*/
    if(!g_mmi_audply_longpressed)
    {
        return;
    }

   /*must be set to false before mmi_audply_paly() to prevent paly fail and
     then popup screen calls exit main screen to set some values incorrectly*/     
     g_mmi_audply_longpressed = MMI_FALSE;

    if (g_audply.seekable)
    {
        if (g_audply.need_to_build_cache)
        {        
            /*stop budild cache*/
            mdi_audio_stop_build_cache();
        }
          
        if(g_audply.state_before_longpress == STATE_PLAY)
        {
            mmi_audply_play();
        }
        else
        {
//            g_mmi_audply_non_play_longpressed = MMI_TRUE;
//            g_audply.state = g_audply.state_before_longpress;
        }
    }
    else    /* unseekable, for user release longpress next/prev button, then reset selected button */
    {
        if (g_audply.state_before_longpress == STATE_PLAY)
        {
            if (g_audply.state != STATE_PLAY)
            {
                mmi_audply_play();
            }
            else
            {
                g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
            }
        }
        else
        {
//            g_mmi_audply_non_play_longpressed = MMI_TRUE;
//            g_audply.state = g_audply.state_before_longpress;
        }
    }     
     
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
	mmi_audply_redraw_main_progressbar();
    }     
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
MMI_BOOL mmi_audply_is_spectrum_valid(void)
{
    if (g_audply_skins[g_audply.skin].spectrum_display_x >= 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
MMI_BOOL mmi_audply_is_lyrics_valid(void)
{
    if (g_audply_skins[g_audply.skin].lyric_display_x >= 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */

#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
MMI_BOOL mmi_audply_spectrum_lyrics_exclusive(void)
{
    if (g_audply_skins[g_audply.skin].spectrum_lyrics_exclusive)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_base_screen_handle
 * DESCRIPTION
 *  get the base screen handle.
 * PARAMETERS
 *  gdi_handle		*base_handle       
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_audply_get_base_screen_handle(gdi_handle *base_handle)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*base_handle=audply_skin_layer;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_spec_blank_area
 * DESCRIPTION
 * draws blank area
 * PARAMETERS
 *  gdi_handle		*base_handle       
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_audply_redraw_spec_blank_area(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	gdi_handle base_handle;
	S32 x1, y1, x2, y2;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	x1 = audply_spec_animation.x;
	y1 = audply_spec_animation.y;
	x2 = x1 + audply_spec_animation.w;
	y2 = y1 + audply_spec_animation.h;
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
			gui_lock_double_buffer();
#endif

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_layer_push_and_set_active(audply_skin_layer);
#endif

	gui_push_clip();
	gdi_layer_set_clip(x1,y1,x2,y2);
	gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_BLACK);
	gui_pop_clip();
	#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_layer_pop_and_restore_active();
	#endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */
}

#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_AUDIO_PLAYER__ */ 

