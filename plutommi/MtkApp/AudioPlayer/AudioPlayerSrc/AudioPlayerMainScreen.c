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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__) || !defined(__MMI_FTE_SUPPORT__)

/* dependent headers for AudioPlayerXXX.h" */
#include "mdi_audio.h"
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
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gdi_datatype.h"
#include "gui_windows.h"
#include "gdi_const.h"
#include "CustDataRes.h"
#include "gui.h"
#include "gdi_include.h"
#include "kal_public_api.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"
#include "gui_config.h"
#include "ScreenRotationGprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "gui_themes.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "lcd_sw_inc.h"
#include "GlobalResDef.h"
#include "gpiosrvgprot.h"
#include "Wgui_categories_multimedia.h"
#if !(defined __MMI_MAINLCD_96X64__)
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
#include "lyrics_parser.h"
#endif/*__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__*/
//#undef __GDI_MEMORY_PROFILE_2__

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || (defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
#ifndef __MMI_AUDIO_PLAYER_SKIN_SHOW_ICON_BAR__
#define __MMI_AUDIO_PLAYER_SKIN_SHOW_ICON_BAR__
#endif
#endif

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);
#endif /*__MMI_TOUCH_SCREEN__*/

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gui_spectrum.h"
#endif 

#ifdef __MMI_A2DP_SUPPORT__
extern MMI_BOOL wait_open_bt;
#endif


#ifdef __MMI_WEARABLE_DEVICE__
#define MMI_SWATCH_BACK_MOVE_THRESHOLD_X  (LCD_WIDTH/3)
static MMI_BOOL g_swatch_is_pen_down = MMI_FALSE;
static mmi_pen_point_struct g_swatch_pen_down_pos = {0};
#endif  //__MMI_WEARABLE_DEVICE__

#define MAIN_SCREEN_VARIBALES

S16         g_audply_main_selected_button = AUDPLY_MAIN_DISABLED;   //Is any playing control button seleted
MMI_BOOL    g_audply_main_selected_button_down;         //Is any button being selected down
static MMI_BOOL     audply_main_init_images_done;
static MMI_BOOL     audply_main_init_title_scrolling_done;
static color        audply_main_text_border_color;
static gdi_color    audply_main_text_bg_color;
static color        audply_main_text_fg_color;
static PU8          audply_main_pause_off_img;
static PU8          audply_main_pause_down_img;
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL     g_audply_main_pen_move_more_than_once ; /*to avoid play\pause icon keep changing from one another when pen move*/
static S32          g_audply_progress_bar_current_x_pos ; /*the x coordinate of progress bar to decide fast forward or rewind*/
static S32          g_audply_progress_bar_pen_down_x_pos ; /*the x coordinate of pen down action on progress bar for refine target time*/
#endif /* __MMI_TOUCH_SCREEN__ */ 
static audply_main_title_struct         audply_main_title;
static audply_main_time_struct          audply_main_time;
static audply_main_file_index_struct    audply_main_file_index;
static audply_main_volumebar_struct     audply_main_volumebar;
static audply_main_progressbar_struct   audply_main_progressbar;
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
static audply_main_volumectrl_struct    audply_main_volume_inc, audply_main_volume_dec;
#endif
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__) //|| defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
static audply_main_repeat_struct        audply_main_repeat;
static audply_main_shuffle_struct       audply_main_shuffle;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
audply_main_animation_struct            audply_main_animation;
#endif 

#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
static audply_main_bg_struct            audply_main_bg;
#ifdef __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__
static audply_main_push_button_struct 	audply_vol_speaker;
static audply_main_push_button_struct 	audply_vol_speaker_mute;
#endif

#else
static PU8                              audply_main_bg_img;
static audply_main_playlisticon_struct  audply_main_playlisticon;
#ifdef __MMI_TOUCH_SCREEN__
static audply_main_setting_struct       audply_main_setting;
#endif
#endif

static S16          audply_main_buttons_x1;
static S16          audply_main_buttons_y1;
static S16          audply_main_buttons_x2;
static S16          audply_main_buttons_y2;
static U8           audply_main_skin_index;
static audply_main_button_struct        audply_main_buttons[NO_OF_AUDPLY_MAIN_BUTTONS];
static scrolling_text                   audply_main_scrolling_title;
static UI_string_type                   audply_main_LSK_text;
static UI_string_type                   audply_main_RSK_text;
#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
static audply_main_push_button_struct audply_main_LSK;
static audply_main_push_button_struct audply_main_RSK;
#endif

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
static S16 audply_skin_line_x;
static S16 audply_skin_line_y;
static S16 audply_skin_line_w;
static S16 audply_skin_line_h;
static PU8 audply_skin_line_img_id; 
#endif


GDI_HANDLE          audply_osd_layer = 0;
GDI_HANDLE          audply_skin_layer = 0;
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
GDI_HANDLE          audply_old_bld_layer;
#endif
MMI_BOOL            is_audply_skin_layer_drawn;// = MMI_FALSE;

extern WCHAR        *MMI_title_string;                     /* from wgui_categories.c */
extern S32          MMI_title_height;                                /* from wgui_categories.c */
extern S32          UI_device_width;                                 /* from gui_wrapper.c */
extern S32          UI_device_height;                                /* from gui_wrapper.c */
extern S32          MMI_softkey_height;

extern U32          g_mmi_audply_seek_target_time;
extern U32          audio_build_cache_progress;
extern U8           audio_cache[BUILD_CACHE_SIZE];
extern MMI_BOOL     g_mmi_audply_longpressed;
extern MMI_BOOL     g_mmi_audply_init_done; /* from AudioPlayerSrc.c */
#ifdef __MMI_BIDI_ALG__
extern BOOL         r2lMMIFlag;             /* definedi n gui_inputs.c */
#endif
extern audply_struct                g_audply;                              /* from AudioPlayerSrc.c */
extern const audply_skin_struct     g_audply_skins[NO_OF_SKIN]; /* from AudioPlayerSrc.c */

/* sub LCD */
#ifdef __MMI_SUBLCD__
static scrolling_text               audply_sub_LCD_scrolling_title;
static scrolling_text               *audply_sub_LCD_scrolling_title_p = NULL;
extern bitmap                       *current_LCD_device_bitmap;   /* defined in wgui.c */
extern bitmap                       main_LCD_device_bitmap;       /* defined in wingui.c */
extern bitmap                       sub_LCD_device_bitmap;        /* defined in wingui.c */
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TOUCH_SCREEN__
static S32                          audply_pen_event_on_object;// = AUDPLY_PEN_NONE;
static mmi_pen_point_struct         LSK_points[4];
static mmi_pen_point_struct         RSK_points[4];
static mmi_pen_polygon_area_struct  LSK_area;
static mmi_pen_polygon_area_struct  RSK_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
extern MMI_BOOL                     g_audply_spectrum_blocked;
extern spectrum_struct              g_aud_ply_spectrum;
#ifdef __MMI_SUBLCD__
extern spectrum_struct              g_aud_ply_spectrum_sub_lcd;
#endif
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
extern audply_lyric_struct          audply_lyric;
extern audply_lyric_printing_struct audply_lyric_print;
extern MMI_BOOL                     lyric_reEntry;
extern MMI_BOOL                     lyric_parse_ok;
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
extern lyrics_meta_struct*  g_audply_lyrics;
extern mmi_audply_lyrics_box_struct g_audply_lyrics_box;
#endif/*__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__*/

extern scrolling_text               *audply_scrolling_lyric_p1;

/* from History.c */
extern S32                          mmi_is_redrawing_bk_screens(void);
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
static void mmi_audply_redraw_main_repeat_shuffle(void);
#endif
static void mmi_audply_draw_button(S32 x, S32 y, U8 *img_p, audply_buttons_state_enum state);
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
static void mmi_audply_redraw_main_AP_title(void);
#endif
static void mmi_audply_redraw_main_softkey(MMI_BOOL is_left, MMI_BOOL is_down);
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_ICON_BAR__)
void mmi_audply_redraw_statusbar_bg_callback(void);
#endif

#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
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
    const audply_skin_struct *skin_p = &g_audply_skins[skin];
    S32 i, w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__
	/* bg image */
	audply_main_bg.audply_main_bg_img 			= (PU8) GetImage(skin_p->bg_image_id);
	audply_main_bg.audply_main_bg_panel_x 		= skin_p->bg_panel_x;
	audply_main_bg.audply_main_bg_panel_y 		= skin_p->bg_panel_y;
#if !defined(__MMI_MAINLCD_320X240__)
	audply_main_bg.audply_main_bg_panel_img		= (PU8) GetImage(skin_p->bg_panel_id);
#endif

	/* speaker */
	audply_vol_speaker.x		= skin_p->speaker_x;
	audply_vol_speaker.y		= skin_p->speaker_y;
	audply_vol_speaker.w		= skin_p->speaker_w;
	audply_vol_speaker.h		= skin_p->speaker_h;
	audply_vol_speaker.up_img	= (PU8) GetImage(skin_p->speaker_up_id);
	audply_vol_speaker.dis_img	= (PU8) GetImage(skin_p->speaker_down_id);
	audply_vol_speaker_mute.x		= skin_p->speaker_x;
	audply_vol_speaker_mute.y		= skin_p->speaker_y;
	audply_vol_speaker_mute.w		= skin_p->speaker_w;
	audply_vol_speaker_mute.h		= skin_p->speaker_h;
	audply_vol_speaker_mute.up_img	= (PU8) GetImage(skin_p->speaker_mute_up_id);
	audply_vol_speaker_mute.dis_img = (PU8) GetImage(skin_p->speaker_mute_down_id);

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
#endif
	/* bg and fg imge initialize */
    audply_main_bg.audply_main_bg_color             = gdi_act_color_from_rgb(255, skin_p->bg_color_r, skin_p->bg_color_g, skin_p->bg_color_b);
    audply_main_bg.audply_main_bg_title_img         = (PU8) GetImage(skin_p->bg_title_image_id);
    audply_main_bg.audply_main_bg_title.x           = skin_p->title_x;
    audply_main_bg.audply_main_bg_title.y           = skin_p->title_y;
    audply_main_bg.audply_main_bg_title.w           = skin_p->title_w;
    audply_main_bg.audply_main_bg_title.h           = skin_p->title_h;
    audply_main_bg.audply_main_bg_progress_img      = (PU8) GetImage(skin_p->bg_progress_image_id);
    audply_main_bg.audply_main_bg_progress.x        = skin_p->progressbar_x;
    audply_main_bg.audply_main_bg_progress.y        = skin_p->progressbar_y;
    audply_main_bg.audply_main_bg_progress.w        = skin_p->progressbar_w;
    audply_main_bg.audply_main_bg_progress.h        = skin_p->progressbar_h;
    audply_main_bg.audply_main_bg_volume_img        = (PU8) GetImage(skin_p->bg_volume_image_id);
    audply_main_bg.audply_main_bg_volume.x          = skin_p->volumebar_x;
    audply_main_bg.audply_main_bg_volume.y          = skin_p->volumebar_y;
    gdi_image_get_dimension(audply_main_bg.audply_main_bg_volume_img, &w, &h);
    audply_main_bg.audply_main_bg_volume.w          = w;
    audply_main_bg.audply_main_bg_volume.h          = h;
    audply_main_bg.audply_main_bg_softkey_color     = GDI_COLOR_GRAY;
    audply_main_bg.audply_main_bg_button_img        = (PU8) GetImage(skin_p->bg_button_id);
    audply_main_bg.audply_main_button_img_hilite    = (PU8) GetImage(skin_p->fg_down_id);
    audply_main_bg.audply_main_button_img_disable   = (PU8) GetImage(skin_p->fg_disable_id);
    /* audply_main_text_border_color, text fg, bg color */
    audply_main_text_border_color                   = gui_color(skin_p->text_border_color_r, skin_p->text_border_color_g, skin_p->text_border_color_b);
    audply_main_text_fg_color                       = gui_color(skin_p->text_fg_color_r, skin_p->text_fg_color_g, skin_p->text_fg_color_b);
#ifdef __GDI_MEMORY_PROFILE_2__
    audply_main_text_bg_color = GDI_COLOR_TRANSPARENT ;   /* transparent */
#else 
    audply_main_text_bg_color = gdi_act_color_from_rgb(255,skin_p->text_bg_color_r, skin_p->text_bg_color_g, skin_p->text_bg_color_b);
#endif 

    /* title */
    audply_main_title.x         = skin_p->title_x;
    audply_main_title.y         = skin_p->title_y;
    audply_main_title.w         = skin_p->title_w;
    audply_main_title.h         = skin_p->title_h;
    /* time */
    audply_main_time.x1         = skin_p->time_left_x;
    audply_main_time.y1         = skin_p->time_left_y;
    audply_main_time.x2         = skin_p->time_right_x;
    audply_main_time.y2         = skin_p->time_right_y;
    for (i = 0; i < 10; i++)
    {
        audply_main_time.num_id[i] = skin_p->ticks_image_id[i];
    }
    audply_main_time.col_id     = skin_p->ticks_image_id[i];
    /* file index */
    audply_main_file_index.x    = skin_p->file_index_x;
    audply_main_file_index.y    = skin_p->file_index_y;
    audply_main_file_index.w    = skin_p->file_index_w;
    audply_main_file_index.h    = skin_p->file_index_h;
    /* volume */
    audply_main_volumebar.x     = skin_p->volumebar_x;
    audply_main_volumebar.y     = skin_p->volumebar_y;
    audply_main_volumebar.ind_len               = skin_p->volumebar_ind_len;
    audply_main_volumebar.bar_direction         = skin_p->volumebar_direction;
    audply_main_volumebar.ind_img               = (PU8) GetImage(skin_p->volumebar_ind_image_id);
    gdi_image_get_dimension(audply_main_volumebar.ind_img, &w, &h);
    audply_main_volumebar.w     = (S16) w;
    audply_main_volumebar.h     = (S16) h;
    /* progress bar */
    audply_main_progressbar.x   = skin_p->progressbar_x;
    audply_main_progressbar.y   = skin_p->progressbar_y;
    audply_main_progressbar.img                 = (PU8) GetImage(skin_p->progressbar_image_id);
    audply_main_progressbar.img_fail            = (PU8) GetImage(skin_p->progressbar_fail_image_id);
    audply_main_progressbar.w                   = (S16) skin_p->progressbar_w;
    audply_main_progressbar.h                   = (S16) skin_p->progressbar_h;
    /* play, pause, stop, prev, next buttons */
    audply_main_buttons[AUDPLY_MAIN_PREV].x     = skin_p->prev_button_x;
    audply_main_buttons[AUDPLY_MAIN_PREV].y     = skin_p->prev_button_y;
    audply_main_buttons[AUDPLY_MAIN_PREV].off_img           = (PU8) GetImage(skin_p->prev_button_image_id);
	#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    audply_main_buttons[AUDPLY_MAIN_PREV].disabled_img      = (PU8) GetImage(skin_p->prev_button_dis_image_id);
	#else
    audply_main_buttons[AUDPLY_MAIN_PREV].disabled_img      = (PU8) GetImage(skin_p->prev_button_image_id);
	#endif
    audply_main_buttons[AUDPLY_MAIN_PREV].down_img          = (PU8) GetImage(skin_p->prev_button_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].x                 = skin_p->next_button_x;
    audply_main_buttons[AUDPLY_MAIN_NEXT].y                 = skin_p->next_button_y;
    audply_main_buttons[AUDPLY_MAIN_NEXT].off_img           = (PU8) GetImage(skin_p->next_button_image_id);
	#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    audply_main_buttons[AUDPLY_MAIN_NEXT].disabled_img      = (PU8) GetImage(skin_p->next_button_dis_image_id);
	#else
    audply_main_buttons[AUDPLY_MAIN_NEXT].disabled_img      = (PU8) GetImage(skin_p->next_button_image_id);
	#endif
	audply_main_buttons[AUDPLY_MAIN_NEXT].down_img          = (PU8) GetImage(skin_p->next_button_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].x                 = skin_p->play_button_x;
    audply_main_buttons[AUDPLY_MAIN_PLAY].y                 = skin_p->play_button_y;
    audply_main_buttons[AUDPLY_MAIN_PLAY].off_img           = (PU8) GetImage(skin_p->play_button_image_id);
	#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    audply_main_buttons[AUDPLY_MAIN_PLAY].disabled_img      = (PU8) GetImage(skin_p->play_button_dis_image_id);
	#else
	audply_main_buttons[AUDPLY_MAIN_PLAY].disabled_img      = (PU8) GetImage(skin_p->play_button_image_id);
	#endif
	audply_main_buttons[AUDPLY_MAIN_PLAY].down_img          = (PU8) GetImage(skin_p->play_button_image_id);
    audply_main_pause_off_img                               = (PU8) GetImage(skin_p->pause_button_image_id);
    audply_main_pause_down_img                              = (PU8) GetImage(skin_p->pause_button_image_id);
    /* calculate buttons boundary */
    gdi_image_get_dimension((PU8) audply_main_buttons[0].down_img, &w, &h);
    audply_main_buttons[0].w    = (S16) w;
    audply_main_buttons[0].h    = (S16) h;
    audply_main_buttons_x1      = audply_main_buttons[0].x;
    audply_main_buttons_y1      = audply_main_buttons[0].y;
    audply_main_buttons_x2      = audply_main_buttons[0].x + w - 1;
    audply_main_buttons_y2      = audply_main_buttons[0].y + h - 1;
    for (i = 1; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
       #ifdef __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__
        gdi_image_get_dimension(audply_main_buttons[i].down_img, &w, &h);
       #else
        gdi_image_get_dimension((PU8) GetImage(skin_p->bg_button_id), &w, &h);
       #endif
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

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    /* animation */
    audply_main_animation.x                 = skin_p->animation_x;
    audply_main_animation.y                 = skin_p->animation_y;
    audply_main_animation.animation_img     = (PU8) GetImage(skin_p->animation_image_id);
    gdi_image_get_dimension(audply_main_animation.animation_img, &w, &h);
    audply_main_animation.w                 = (S16) w;
    audply_main_animation.h                 = (S16) h;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 

#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__) //|| defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
    /* repeat */
    audply_main_repeat.x                    = skin_p->repeat_x;
    audply_main_repeat.y                    = skin_p->repeat_y;
    audply_main_repeat.off_up_img           = (PU8) GetImage(skin_p->repeat_off_image_id);
    audply_main_repeat.all_up_img           = (PU8) GetImage(skin_p->repeat_all_image_id);
    audply_main_repeat.one_up_img           = (PU8) GetImage(skin_p->repeat_one_image_id);
    audply_main_repeat.off_down_img         = (PU8) GetImage(skin_p->repeat_off_image_id);
    audply_main_repeat.all_down_img         = (PU8) GetImage(skin_p->repeat_all_image_id);
    audply_main_repeat.one_down_img         = (PU8) GetImage(skin_p->repeat_one_image_id);
    audply_main_repeat.down                 = MMI_FALSE;
    gdi_image_get_dimension(audply_main_repeat.off_up_img, &w, &h);
    audply_main_repeat.w                    = (S16) w;
    audply_main_repeat.h                    = (S16) h;
    /* shuffle */
    audply_main_shuffle.x                   = skin_p->shuffle_x;
    audply_main_shuffle.y                   = skin_p->shuffle_y;
    audply_main_shuffle.off_up_img          = (PU8) GetImage(skin_p->shuffle_off_image_id);
    audply_main_shuffle.on_up_img           = (PU8) GetImage(skin_p->shuffle_on_image_id);    
    audply_main_shuffle.off_down_img        = (PU8) GetImage(skin_p->shuffle_off_image_id);
    audply_main_shuffle.on_down_img         = (PU8) GetImage(skin_p->shuffle_on_image_id);    
    audply_main_shuffle.down                = MMI_FALSE;
    gdi_image_get_dimension(audply_main_shuffle.off_up_img , &w, &h);
    audply_main_shuffle.w                   = (S16) w;
    audply_main_shuffle.h                   = (S16) h;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_aud_ply_spectrum.target_lcd           = GDI_LCD_MAIN_LCD_HANDLE;
    g_aud_ply_spectrum.start_x              = skin_p->spectrum_display_x;
    g_aud_ply_spectrum.start_y              = skin_p->spectrum_display_y;
    g_aud_ply_spectrum.width                = skin_p->spectrum_display_w;
    g_aud_ply_spectrum.height               = skin_p->spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
    audply_lyric_print.start_x              = skin_p->lyric_display_x;
    audply_lyric_print.start_y              = skin_p->lyric_display_y;
    audply_lyric_print.width                = skin_p->lyric_display_w;
    audply_lyric_print.height               = skin_p->lyric_display_h;

    if(audply_lyric_print.start_x >= 0)
    {
        audply_lyric_print.lyric_fg_color       = gui_color((U8)skin_p->lyric_fg_color_r, (U8)skin_p->lyric_fg_color_g, (U8)skin_p->lyric_fg_color_b);
        audply_lyric_print.lyric_border_color   = gui_color((U8)skin_p->lyric_border_color_r, (U8)skin_p->lyric_border_color_g, (U8)skin_p->lyric_border_color_b);
    }
#elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)

    g_audply_lyrics_box.rgn_txt.x              = skin_p->lyric_display_x;
    g_audply_lyrics_box.rgn_txt.y              = skin_p->lyric_display_y;
    g_audply_lyrics_box.rgn_txt.w              = skin_p->lyric_display_w;
    g_audply_lyrics_box.rgn_txt.h              = skin_p->lyric_display_h;
	g_audply_lyrics_box.color.r =	skin_p->lyric_fg_color_r;
	g_audply_lyrics_box.color.g =   skin_p->lyric_fg_color_g;
	g_audply_lyrics_box.color.b =   skin_p->lyric_fg_color_b;
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

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ 
    audply_skin_line_x = skin_p->line_img_x;
    audply_skin_line_y = skin_p->line_img_y;
    audply_skin_line_w = skin_p->line_img_w;
    audply_skin_line_h = skin_p->line_img_h;
    audply_skin_line_img_id = (PU8) GetImage(skin_p->line_img_id);
#endif

}

#else
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
    const audply_skin_struct *skin_p = &g_audply_skins[skin];
    S32 i, w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bg */
    audply_main_bg_img = (PU8) GetImage(skin_p->bg_image_id);
    /* audply_main_text_border_color, text fg, bg color */
    audply_main_text_border_color = gui_color(skin_p->text_border_color_r, skin_p->text_border_color_g, skin_p->text_border_color_b);
    audply_main_text_fg_color = gui_color(skin_p->text_fg_color_r, skin_p->text_fg_color_g, skin_p->text_fg_color_b);
#ifdef __GDI_MEMORY_PROFILE_2__
    audply_main_text_bg_color = GDI_COLOR_TRANSPARENT ;   /* transparent */
#else 
    audply_main_text_bg_color = gdi_act_color_from_rgb(255,skin_p->text_bg_color_r, skin_p->text_bg_color_g, skin_p->text_bg_color_b);
#endif 

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

    /* progress bar */
    audply_main_progressbar.x = skin_p->progressbar_x;
    audply_main_progressbar.y = skin_p->progressbar_y;
    audply_main_progressbar.img = (PU8) GetImage(skin_p->progressbar_image_id);
    audply_main_progressbar.img_fail = (PU8) GetImage(skin_p->progressbar_fail_image_id);
    gui_measure_image(audply_main_progressbar.img, &w, &h);
    audply_main_progressbar.w = (S16) w;
    audply_main_progressbar.h = (S16) h;
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
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
#endif
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

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    /* animation */
    audply_main_animation.x = skin_p->animation_x;
    audply_main_animation.y = skin_p->animation_y;
    audply_main_animation.animation_img = (PU8) GetImage(skin_p->animation_image_id);
    gdi_image_get_dimension(audply_main_animation.animation_img, &w, &h);
    audply_main_animation.w = (S16) w;
    audply_main_animation.h = (S16) h;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 

#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__) //|| defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)

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
#endif

void mmi_audply_gdi_layer_push_clip(S32 x1,S32 y1,S32 x2,S32 y2)
{
    #if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
    #endif
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
}

void mmi_audply_gdi_layer_pop_clip_blt(S32 x1,S32 y1,S32 x2,S32 y2)
{
    gdi_layer_pop_clip();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
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
        #ifdef __MMI_BIDI_ALG__
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(UI_device_width - x - 2, y);
            }
            else
         #endif
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
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &audply_skin_layer);
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

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
/* Set status bar's blending layer */
    wgui_status_icon_bar_set_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR, audply_skin_layer);
#endif

#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* init images */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    mmi_audply_init_main_screen_images(skin);
    audply_main_skin_index = skin;
    audply_main_init_images_done = MMI_TRUE;
    audply_main_init_title_scrolling_done = MMI_FALSE;
#else
    if (!audply_main_init_images_done || audply_main_skin_index != skin)
    {
        mmi_audply_init_main_screen_images(skin);
        audply_main_skin_index = skin;
        audply_main_init_images_done = MMI_TRUE;
        audply_main_init_title_scrolling_done = MMI_FALSE;
    }
    else
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__))
    /*if both lyircs and spec are valid and initially are both turned on and 
      they shall be mutually exclusive
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
#endif        

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
        SetKeyDownHandler(mmi_audply_redraw_LSK_down, KEY_LSK);
    }
    SetKeyDownHandler(mmi_audply_redraw_RSK_down, KEY_RSK);

    /* associate functions */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
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
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_audply_redraw_LSK_up();
    mmi_audply_redraw_RSK_up();
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(audply_lyric.is_ready)
    {
        mmi_audply_stop_scroll_lyric_and_clean_screen();
    }
    mmi_audply_lyric_check_backlight(MMI_FALSE);
    lyric_reEntry = MMI_TRUE;
#elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
if(g_audply_lyrics_box.is_ready)
{
    	mmi_audply_unprepare_lyrics();
    }
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
g_audply.in_main_screen = MMI_FALSE;
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    mmi_audply_spectrum_display_stop();
#endif 

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    /* stop animation */
    if (audply_main_animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(audply_main_animation.img_handle);
    }
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
#ifdef __GDI_MEMORY_PROFILE_2__

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    wgui_status_icon_bar_reset_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR);
#endif

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
  //  gdi_layer_clear(GDI_COLOR_BLACK);
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
    audply_main_volume_inc.down = MMI_FALSE;
    audply_main_volume_dec.down = MMI_FALSE;
#endif
#ifdef __MMI_TOUCH_SCREEN__
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    audply_main_setting.down = MMI_FALSE;
#endif
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)    
    audply_main_repeat.down = MMI_FALSE;
    audply_main_shuffle.down = MMI_FALSE;
#endif
    audply_pen_event_on_object = AUDPLY_PEN_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 
}

#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
void mmi_audply_set_LSK_text(U16 lsk_text_id)
{
    audply_main_LSK_text = (UI_string_type) GetString(lsk_text_id);
}
#endif

//#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
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
#ifdef __MMI_TOUCH_SCREEN__
	LSK_area.num = 4;
	LSK_area.points = (mmi_pen_point_struct*) LSK_points;
	LSK_points[0].x = LSK_points[3].x = x1;
	LSK_points[0].y = LSK_points[1].y = y1;
	LSK_points[1].x = LSK_points[2].x = x2 + 1;
	LSK_points[2].y = LSK_points[3].y = y2 + 1;
#endif
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
#ifdef __MMI_TOUCH_SCREEN__
	RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = x1;
    RSK_points[0].y = RSK_points[1].y = y1;
    RSK_points[1].x = RSK_points[2].x = x2 + 1;
    RSK_points[2].y = RSK_points[3].y = y2 + 1;
#endif
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
        gui_set_clip(x1, 11, x2, y2);
#if !defined(__MMI_MAINLCD_320X240__)
		gdi_image_draw(
			audply_main_bg.audply_main_bg_panel_x, 
			audply_main_bg.audply_main_bg_panel_y, 
			audply_main_bg.audply_main_bg_panel_img);
#endif
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
#ifdef __MMI_TOUCH_SCREEN__
	LSK_area.num = 4;
	LSK_area.points = (mmi_pen_point_struct*) LSK_points;
	LSK_points[0].x = LSK_points[3].x = x1;
	LSK_points[0].y = LSK_points[1].y = y1;
	LSK_points[1].x = LSK_points[2].x = x2 + 1;
	LSK_points[2].y = LSK_points[3].y = y2 + 1;
#endif

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
        gui_set_clip(x1, y1, x2, y2);
#if !defined(__MMI_MAINLCD_320X240__)
		gdi_image_draw(
			audply_main_bg.audply_main_bg_panel_x, 
			audply_main_bg.audply_main_bg_panel_y, 
			audply_main_bg.audply_main_bg_panel_img);
#endif
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
#ifdef __MMI_TOUCH_SCREEN__
	RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = x1;
    RSK_points[0].y = RSK_points[1].y = y1;
    RSK_points[1].x = RSK_points[2].x = x2 + 1;
    RSK_points[2].y = RSK_points[3].y = y2 + 1;
#endif


}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_LSK_down
 * DESCRIPTION
 *  redraw shifted LSK for key press down event
 *  BQL
 *  can not merge with RSK down easily , since the callback function para
 *  but we can consider to wrapper SK render logic 4in1 logic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_LSK_down(void)
{
    mmi_audply_redraw_main_softkey(MMI_TRUE, MMI_TRUE);
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
    mmi_audply_redraw_main_softkey(MMI_FALSE, MMI_TRUE);

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
    mmi_audply_redraw_main_softkey(MMI_TRUE, MMI_FALSE);

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
    mmi_audply_redraw_main_softkey(MMI_FALSE, MMI_FALSE);

}
#endif

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
        /*show satatus bar*/
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_ICON_BAR__)
        wgui_status_icon_bar_register_hide_callback(
            WGUI_STATUS_ICON_BAR_H_BAR, 
            mmi_audply_redraw_statusbar_bg_callback);
        wgui_set_wallpaper_on_bottom(MMI_TRUE);
        wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
        wgui_status_icon_bar_update();
#endif

        /* show animation */
    #ifdef __MMI_AUDIO_PLAYER_ANIMATION__
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
	  if ((!(g_audply.lyrics_display &&
        mmi_audply_is_lyrics_valid())) || (g_audply_lyrics == NULL))
#endif
    {
        mmi_audply_redraw_animation();
    }
    #endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */
    #ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
        /* show AP title */
        mmi_audply_redraw_main_AP_title();
    #endif
        /* show LSK */
        if(!bg_call)
        {
            mmi_audply_redraw_LSK_up();
        }
        /* show RSK */
        mmi_audply_redraw_RSK_up();
            
#ifdef __GDI_MEMORY_PROFILE_2__
        is_audply_skin_layer_drawn = MMI_TRUE;
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
#ifdef __MMI_TOUCH_SCREEN__
    /*show setting icon*/
    mmi_audply_redraw_main_setting(audply_main_setting.down);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif

    /*repeat and shuffle*/


#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
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
    }
    else
    {
        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
    }     
#endif

#ifdef __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__
	if (g_audply.volume == 0)
	{
		mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
	}
	else
	{
		mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
	}	  
#endif
    /*show buttons*/
    mmi_audply_redraw_main_buttons();
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    /*play list icon*/
    mmi_audply_redraw_main_playlisticon();
#endif
    /*show progress bar*/
    mmi_audply_redraw_main_progressbar();
    /*main title*/
    mmi_audply_redraw_main_title();
    /*file index*/
    mmi_audply_redraw_main_file_index();
    /*main time*/
    mmi_audply_redraw_main_time();
    /*main vol bar*/        
    mmi_audply_redraw_main_volumebar();
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)

    mmi_audply_redraw_main_repeat_shuffle();
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

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

#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_ICON_BAR__)
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
	gdi_draw_solid_rect(cx1, cy1, cx2, cy2,GDI_COLOR_TRANSPARENT);
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    /* draw title bg */
    gdi_image_draw_resized(
        audply_main_title.x, 
        audply_main_title.y, 
        audply_main_title.w, 
        audply_main_title.h, 
        audply_main_bg.audply_main_bg_title_img);
#else
    gdi_image_draw(0, 0, audply_main_bg_img);
#endif
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
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else
	gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
#endif
#else
    gdi_draw_solid_rect(x1, y1, x2, y2, audply_main_text_bg_color);
#endif
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
static void mmi_audply_scroll_main_title_handler(void)
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
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
    gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    /* draw bg */
#if 0
	#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if !defined(__MMI_MAINLCD_320X240__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	#else
/* under construction !*/
	#endif
#endif
        gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->sub_menu_bkg_filler); 
            gui_draw_filled_area( 
                        0, 
                        UI_device_height - MMI_softkey_height, 
                        UI_device_width - 1, 
                        UI_device_height - 1, 
                        current_MMI_theme->softkey_bar_bkg_filler);
	#if 0
	#if !defined(__MMI_MAINLCD_320X240__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	#endif
    /* draw progress bg */
    gdi_image_draw_resized(
        audply_main_bg.audply_main_bg_progress.x + 1, 
        audply_main_bg.audply_main_bg_progress.y + 1, 
        audply_main_bg.audply_main_bg_progress.w - 2, 
        audply_main_bg.audply_main_bg_progress.h - 2, 
        audply_main_bg.audply_main_bg_progress_img);
    /* draw volume bg */
    gdi_image_draw_resized(
        audply_main_bg.audply_main_bg_volume.x, 
        audply_main_bg.audply_main_bg_volume.y, 
        audply_main_bg.audply_main_bg_volume.w, 
        audply_main_bg.audply_main_bg_volume.h, 
        audply_main_bg.audply_main_bg_volume_img);
    /* draw softkey bg */
    gui_draw_filled_area(
        0, 
        UI_device_height - MMI_softkey_height,
        UI_device_width - 1,
        UI_device_height - 1,
        current_MMI_theme->softkey_bar_bkg_filler);
    //gdi_layer_save_bmp_file(audply_skin_layer, (CHAR*)L"D:\\5.bmp"); 

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    /* draw skin line*/
    gdi_image_draw_resized(
        audply_skin_line_x,
        audply_skin_line_y,
        audply_skin_line_w,
        audply_skin_line_h,
        audply_skin_line_img_id);
#endif
    
#else
    gdi_image_draw(0, 0, audply_main_bg_img);
#endif
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

}

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
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
    gdi_image_get_dimension(audply_main_animation.animation_img, &width, &height);
    gdi_layer_push_and_set_clip( audply_main_animation.x,
        audply_main_animation.y,
        audply_main_animation.x + width,
        audply_main_animation.y + height);
    gdi_image_draw_animation(
        audply_main_animation.x,
        audply_main_animation.y,
        audply_main_animation.animation_img,
        &audply_main_animation.img_handle);

    /* gdi will not blt first frame, so we need blt it self */
    gdi_layer_blt_previous(
        audply_main_animation.x,
        audply_main_animation.y,
        audply_main_animation.x + width,
        audply_main_animation.y + height);
    gdi_layer_pop_clip();
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
    S32 y_offset = 0,x_offset = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#if defined(__MMI_MAINLCD_320X240__)
	gui_set_font(&MMI_small_font);    
#elif !defined(__MMI_MAINLCD_320X480__)
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_large_font);
#endif

    gui_set_text_color(audply_main_text_fg_color);
    gui_measure_string(g_audply.title, &w, &character_height);
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    x_offset = 20;
    y_offset = (audply_main_title.h - character_height) / 2;
#endif
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
    if (w > audply_main_title.w - (x_offset*2))
    {
        gui_redraw_scrolling_text(&audply_main_scrolling_title);
    }
    else
    {
        /* background */
        mmi_audply_redraw_main_title_background(x1, y1, x2, y2);
#ifdef __MMI_BIDI_ALG__
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (audply_main_title.w + w) / 2, y1 + y_offset);
        }
        else
#endif
        {
            gui_move_text_cursor(x1 + (audply_main_title.w - w) / 2, y1 + y_offset);
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
    if (audply_main_init_title_scrolling_done)
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
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */

#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__

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
static void mmi_audply_redraw_main_AP_title(void)
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
	#if defined(__MMI_MAINLCD_320X240__)
	gui_set_font(&MMI_small_font);    
#else
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));

#endif


    gui_set_text_color(head_text_color);
    gui_set_text_border_color(audply_main_text_border_color);
    
    gui_measure_string(MMI_title_string, &str_w, &str_h);
    gui_set_line_height(str_h);
    if (str_w > UI_device_width)
    {
        str_w = UI_device_width;
    }
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_ICON_BAR__)
    height_base = MMI_status_bar_height-1;
#endif
    gdi_layer_push_and_set_clip(0, height_base, UI_device_width - 1, height_base+MMI_title_height - 1);
#ifdef __MMI_BIDI_ALG__
    if (r2lMMIFlag)
    {
        x1 = (UI_device_width + str_w) / 2;
    }
    else
#endif
    {
        x1 = (UI_device_width - str_w) / 2;
    }
    gui_print_truncated_borderd_text(x1, height_base+((MMI_title_height - str_h)/2) , UI_device_width - 2, MMI_title_string);
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 


}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_softkey
 * DESCRIPTION
 *  redraw audio player main softkey
 *  BQL
 *  can not merge with RSK down easily , since the callback function para
 *  but we can consider to wrapper SK render logic 4in1 logic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_redraw_main_softkey(MMI_BOOL is_left, MMI_BOOL is_down)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    S32 offset_x, offset_y, truncated_w;
    S32 offset_down = is_down ? 1 : 0;
#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    S32 start_x = is_left ? 0 : (UI_device_width/2 + 30);
    S32 start_y = UI_device_height - MMI_softkey_height;
    S32 softkey_width = 130;
#endif
    MMI_BOOL truncated = MMI_FALSE;
    color head_text_color = gui_color(255, 255, 255);
    UI_string_type string_text = is_left ? audply_main_LSK_text : audply_main_RSK_text;
    WGUI_SOFTKEY_ENUM string_type = is_left ? MMI_LEFT_SOFTKEY : MMI_RIGHT_SOFTKEY;
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_polygon_area_struct  *string_area = is_left ? &LSK_area : &RSK_area;
    mmi_pen_point_struct         *string_points = is_left ? LSK_points : RSK_points;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
*/
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    if(is_down)
    {
 	gui_set_text_color(*current_MMI_theme->LSK_down_text_color);
	gui_set_text_border_color(*current_MMI_theme->softkey_down_text_border_color);
    }
    else
    {
    	gui_set_text_color(*current_MMI_theme->LSK_up_text_color);
        gui_set_text_border_color(*current_MMI_theme->softkey_text_border_color);
    }

    #if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__) && defined(__MMI_AUDPLY_WALK_PLAY__)
    if (is_left && g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST && g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        color c = {128, 128, 128, 90};
        if (is_down)
            return;
     	gui_set_text_color(c);
    }
    #endif  //defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__) && defined(__MMI_AUDPLY_WALK_PLAY__)

    gui_measure_string(string_text, &str_w, &str_h);
    truncated = wgui_softkey_get_offset(
                    string_text,
                    &offset_x, 
                    &offset_y, 
                    &truncated_w,
                    string_type,
                #ifdef __MMI_SCREEN_ROTATE__
                    mmi_frm_get_screen_rotate()
                #else
                    0
                #endif
                    );

    y1 = offset_y;
    y2 = offset_y + str_h;
#ifdef __MMI_BIDI_ALG__
    if(r2lMMIFlag)
    {
        x2 = offset_x;
        x1 = x2 - str_w ;
    }
    else
#endif
    {
        x1 = offset_x;
        x2 = x1 + str_w;
    }

#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    mmi_audply_gdi_layer_push_clip(start_x, start_y, start_x + softkey_width, start_y + MMI_softkey_height - 1);
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
#else
    mmi_audply_gdi_layer_push_clip(x1-1, y1-1, x2+2, y2+2);
#if defined(__GDI_MEMORY_PROFILE_2__)
    gdi_draw_solid_rect(x1-1, y1-1, x2+2, y2+2, GDI_COLOR_TRANSPARENT); 
#else
    /* draw softkey bg */
    gui_draw_filled_area(
        0, 
        UI_device_height - MMI_softkey_height,
        UI_device_width - 1,
        UI_device_height - 1,
        current_MMI_theme->softkey_bar_bkg_filler);
#endif
#endif
    if(truncated)
    {
        gui_print_truncated_borderd_text(
            offset_x+1,
            offset_y+1,
            truncated_w, 
            string_text);
    }
    else
    {
#ifdef __MMI_BIDI_ALG__
        if(r2lMMIFlag)
        {
            gui_move_text_cursor(x2 + offset_down, y1 + offset_down);
        }
        else
#endif            
        {
            gui_move_text_cursor(x1 + offset_down, y1 + offset_down);
        }

        gui_print_bordered_text(string_text);
    }
    
   /* gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1-1, y1-1, x2+2, y2+2);
#endif *//* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_audply_gdi_layer_pop_clip_blt(start_x, start_y, start_x + softkey_width, start_y + MMI_softkey_height - 1);
#else
    mmi_audply_gdi_layer_pop_clip_blt(x1-1, y1-1, x2+2, y2+2);
#endif

#ifdef __MMI_TOUCH_SCREEN__
    string_area->num = 4;
    string_area->points = (mmi_pen_point_struct*) string_points;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    string_points[0].x = string_points[3].x = start_x;
    string_points[0].y = string_points[1].y = start_y;
    string_points[1].x = string_points[2].x = start_x + softkey_width + 1;
    string_points[2].y = string_points[3].y = start_y + MMI_softkey_height + 1;
#else
    string_points[0].x = string_points[3].x = x1;
    string_points[0].y = string_points[1].y = y1;
    string_points[1].x = string_points[2].x = x2 + 1;
    string_points[2].y = string_points[3].y = y2 + 1;
#endif
#endif /* __MMI_TOUCH_SCREEN__ */ 

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
    S32 x_offset = 0;
    S32 y_offset = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previous scroll text */
    if (audply_main_init_title_scrolling_done)
    {
        gui_scrolling_text_stop(&audply_main_scrolling_title);
    }
    else
    {
        audply_main_init_title_scrolling_done = MMI_TRUE;
    }
#if defined(__MMI_MAINLCD_320X240__)
	gui_set_font(&MMI_small_font);    
#elif !defined(__MMI_MAINLCD_320X480__)
    gui_set_font(&MMI_medium_font);

#else
    gui_set_font(&MMI_large_font);
#endif

    gui_set_text_color(audply_main_text_fg_color);
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    if (!mmi_ucs2strlen((CHAR*)g_audply.title))
    {
        mmi_ucs2ncpy((CHAR *)g_audply.title, (CHAR *)MMI_title_string, SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    }
#endif
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_layer_push_and_set_active(audply_osd_layer);
#endif
    gui_measure_string(g_audply.title, &w, &character_height);
   
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    x_offset = 20;
    y_offset = (audply_main_title.h - character_height) / 2;
#endif

    gui_create_scrolling_text(
        &audply_main_scrolling_title,
        x1 + x_offset,
        y1 + y_offset,
        audply_main_title.w - (x_offset*2),
        audply_main_title.h - (y_offset*2),
        g_audply.title,
        mmi_audply_scroll_main_title_handler,
        mmi_audply_redraw_main_title_background,
        audply_main_text_fg_color,
        audply_main_text_border_color);
#if defined(__MMI_MAINLCD_320X240__)
	audply_main_scrolling_title.text_font = MMI_small_font;
#else
    audply_main_scrolling_title.text_font = MMI_medium_font;
#endif

/*#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    */
    mmi_audply_gdi_layer_push_clip(x1, y1, x2, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
#else
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
#endif 

    /* title */
    gui_scrolling_text_stop(&audply_main_scrolling_title);

    if (w > audply_main_title.w - (x_offset*2))
    {
        /* scrolling */
        gui_change_scrolling_text(&audply_main_scrolling_title, g_audply.title);
        gui_show_scrolling_text(&audply_main_scrolling_title);
    }
    else
    {
        /* background */
        mmi_audply_redraw_main_title_background(x1, y1, x2, y2);
#ifdef __MMI_BIDI_ALG__
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (audply_main_title.w + w) / 2, y1 + y_offset);
        }
        else
#endif
        {
            gui_move_text_cursor(x1 + (audply_main_title.w - w) / 2, y1 + y_offset);
        }

        gui_set_line_height(character_height);
        gui_print_text(g_audply.title);
    }
    //gdi_layer_save_bmp_file(audply_skin_layer, (CHAR*)L"D:\\3.bmp");
    //gdi_layer_save_bmp_file(audply_osd_layer, (CHAR*)L"D:\\4.bmp");
    
   /* gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif *//* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    mmi_audply_gdi_layer_pop_clip_blt(x1, y1, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__    //__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__ 
gdi_layer_pop_and_restore_active();
#endif
}

#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
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
#endif


#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__

void mmi_aduply_get_image_for_time(U16* img_idx, U32 time,U32 hour_flag)
{

    U16 h, m, s;
    h = time/ 3600;  
    if (h > 99)
    {   /*Error protected*/
        h = 99;
        m = 59;
        s = 59;
    }
    else
    {
        m = (time - h * 3600) / 60;
        s = (time - h * 3600 - m * 60);
    }
    /*init play time image*/
    if(hour_flag != 0)
    {
    img_idx[0] = audply_main_time.num_id[h/10];
    img_idx[1] = audply_main_time.num_id[h%10];
    img_idx[2] = audply_main_time.col_id;
    }
    else
    {
        img_idx[0] = NULL;
        img_idx[1] = NULL;
        img_idx[2] = NULL;
      }
    img_idx[3] = audply_main_time.num_id[m/10];
    img_idx[4] = audply_main_time.num_id[m%10];
    
    img_idx[5] = audply_main_time.col_id;
    
    img_idx[6] = audply_main_time.num_id[s/10];
    img_idx[7] = audply_main_time.num_id[s%10];
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
    S32 i, x, y;
    S32 num_w, col_w;
    S32 offset_y;
    U32 time;
    U16 img_idx[16];
    S32 time_width = 0;
    U32 h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
			gui_lock_double_buffer();
#endif 
#ifdef __GDI_MEMORY_PROFILE_2__
		gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    time = (U32)(mmi_audply_get_play_seconds() + 500) / 1000;

     
    h = ((g_audply.duration + 500) / 1000)/ 3600;  
    mmi_aduply_get_image_for_time(&img_idx[0],time,h);
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
#endif
    time = (U32)((g_audply.duration + 500) / 1000);
    mmi_aduply_get_image_for_time(&img_idx[8],time,h);
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
  #endif
    x = audply_main_time.x1;
    y = audply_main_time.y1;
    
    gdi_image_get_dimension_id(audply_main_time.num_id[0], &num_w, &offset_y);
    gdi_image_get_dimension_id(audply_main_time.col_id, &col_w, &offset_y);
    gdi_layer_push_and_set_clip( audply_main_time.x1, 
        audply_main_time.y1, 
        audply_main_time.x2, 
        audply_main_time.y2 + offset_y);
	#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(audply_main_time.x1, 
        audply_main_time.y1, 
        audply_main_time.x2, 
        audply_main_time.y2 + offset_y, GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    /* we don't set clip here because its caller will do that */
	gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
#endif
    for (i = 0; i < 16; i++)
    {
       
        if(img_idx[i] == NULL)
            continue;
        gdi_image_draw_id(x, y, img_idx[i]);
        if (audply_main_time.col_id == img_idx[i])
        {
            x += col_w + 1;
            time_width += col_w + 1;
        }
        else
        {
            x += num_w + 1;
            time_width += num_w + 1;
        }
        if(i == 7)
        {
    x = audply_main_time.x2 - time_width;
    y = audply_main_time.y2;
        }
            
    }

  
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
    #endif
	gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
		gdi_pop_and_restore_alpha_blending_source_layer();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            audply_main_time.x1, 
            audply_main_time.y1, 
            audply_main_time.x2, 
            audply_main_time.y2 + offset_y);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


#else
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
    CHAR temp[8];
    UI_character_type time_str[8];
    U32 elapsed_seconds = mmi_audply_get_play_seconds();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elapsed_seconds = elapsed_seconds + 500;
    elapsed_seconds /= 1000 ;
    sprintf(temp, "%02d:%02d", elapsed_seconds / 60, elapsed_seconds % 60);
    mmi_asc_to_ucs2((CHAR*) time_str, (CHAR*) temp);

/*#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    */
    mmi_audply_gdi_layer_push_clip(x1, y1, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, audply_main_text_bg_color);
#else
	gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
#endif

#ifdef __MMI_MAINLCD_240X400__
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_small_font);
#endif
    gui_set_text_color(audply_main_text_fg_color);
    gui_measure_string(time_str, &str_w, &str_h);

#ifdef __MMI_BIDI_ALG__
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + (audply_main_time.w + str_w) / 2, y1 + 1);
    }
    else
#endif        
    {
        gui_move_text_cursor(x1 + (audply_main_time.w - str_w) / 2, y1 + 1);
    }
    gui_print_text(time_str);
    /*i_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif *//* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    mmi_audply_gdi_layer_pop_clip_blt(x1, y1, x2, y2);
}
#endif
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
    //CHAR temp[24]; //bql: use wsprinf to save code
    UI_character_type file_index[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_audply_playlist_is_empty())
    {
        S32 total = mmi_audply_playlist_get_total();
        S32 index = mmi_audply_playlist_get_current_index();
        kal_wsprintf(file_index, "%d/%d", index + 1, total);
    }
    else
    {
        kal_wsprintf(file_index, "0/0");
    }
    //mmi_asc_to_ucs2((CHAR*) file_index, (CHAR*) temp);

/*f(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    */
    mmi_audply_gdi_layer_push_clip(x1, y1, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, audply_main_text_bg_color);
#else
	gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
#endif
#if defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__) 
#ifndef __MMI_MAINLCD_320X480__
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_large_font);
#endif
#else
    gui_set_font(&MMI_small_font);
#endif
    gui_set_text_color(audply_main_text_fg_color);
    gui_measure_string(file_index, &str_w, &str_h);

#ifdef __MMI_BIDI_ALG__
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + (audply_main_file_index.w + str_w) / 2, y1 + 1);
    }
    else
#endif        
    {
        gui_move_text_cursor(x1 + (audply_main_file_index.w - str_w) / 2, y1 + 1);
    }
    gui_print_text(file_index);
   /* gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif*/ /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
   mmi_audply_gdi_layer_pop_clip_blt(x1, y1, x2, y2);
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
	U32 quota = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
	quota = (U32) g_audply.volume;
#else
	quota = (U32) g_audply.volume;
#endif
	
    if(audply_main_volumebar.bar_direction == HORIZONTAL_VOL_BAR )
    {
        diff = audply_main_volumebar.ind_len + 
             quota * (audply_main_volumebar.w - 
             audply_main_volumebar.ind_len) /(MDI_AUD_VOL_EX_NUM -1);
        if (diff > (U32) audply_main_volumebar.w)
        {
            diff = (U32) audply_main_volumebar.w;
        }
    }
    else if(audply_main_volumebar.bar_direction == VERTICAL_VOL_BAR )
    {
        diff = audply_main_volumebar.ind_len + 
             quota * (audply_main_volumebar.h - 
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

/*#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    
    gdi_layer_push_and_set_clip(x1, y1, x2, y2); 
    */
    mmi_audply_gdi_layer_push_clip(x1, y1, x2, y2);
    
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, audply_main_text_bg_color);
    gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#else
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    /* draw volume bg */
    gdi_image_draw_resized(
        audply_main_bg.audply_main_bg_volume.x, 
        audply_main_bg.audply_main_bg_volume.y, 
        audply_main_bg.audply_main_bg_volume.w, 
        audply_main_bg.audply_main_bg_volume.h, 
        audply_main_bg.audply_main_bg_volume_img);
#endif
#endif

	if (diff)
	{
	    if(audply_main_volumebar.bar_direction == HORIZONTAL_VOL_BAR)
		{
			gdi_layer_set_clip(x1, y1, x1 + diff, y2);
		}
		else
		{
			gdi_layer_set_clip(x1, y1+audply_main_volumebar.h-diff, x2, y2);
		}

		gdi_image_draw(x1, y1, audply_main_volumebar.ind_img);
	}
	//gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
		gdi_pop_and_restore_alpha_blending_source_layer();
#endif

/*
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif *//* (UI_DOUBLE_BUFFER_SUPPORT) */ 
mmi_audply_gdi_layer_pop_clip_blt(x1, y1, x2, y2);

}


#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
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

#endif
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

    dx = (U32)(audply_main_progressbar.w * ((float)elapsed_ms/(float)g_audply.duration)) ;

#ifdef __MMI_TOUCH_SCREEN__
    g_audply_progress_bar_current_x_pos = x1 + dx ;
#endif    
/*
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    gdi_layer_push_and_set_clip(x1+1, y1+1, x1+audply_main_progressbar.w-2, y1+audply_main_progressbar.h-2);
#else
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
#endif*/
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
        mmi_audply_gdi_layer_push_clip(x1+1, y1+1, x1+audply_main_progressbar.w-2, y1+audply_main_progressbar.h-2);
#else
        mmi_audply_gdi_layer_push_clip(x1, y1, x2, y2);
#endif

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, audply_main_text_bg_color);
#else 
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
    gdi_draw_solid_rect(x1, y1, x2, y2, audply_main_text_bg_color);
#endif
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if (g_audply.duration > 0)
#else
    if(seekable)
#endif
    {
        gdi_layer_set_clip(x1, y1, x1 + dx, y2);
        if (elapsed_ms != 0)
        {
            #ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
            gdi_image_draw_resized(x1+1, y1+1, audply_main_progressbar.w-2, audply_main_progressbar.h-2,  audply_main_progressbar.img);
            #else
            gdi_image_draw(x1, y1, audply_main_progressbar.img);
            #endif
        }
    }
    else
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
        #ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
        gdi_image_draw_resized(x1+1, y1+1, audply_main_progressbar.w-2, audply_main_progressbar.h-2, audply_main_progressbar.img_fail);
        #else
        gdi_image_draw(x1, y1, audply_main_progressbar.img_fail);
        #endif
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif
  /*  gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif *//* (UI_DOUBLE_BUFFER_SUPPORT) */ 
mmi_audply_gdi_layer_pop_clip_blt(x1, y1, x2, y2);
}



static void mmi_audply_draw_button(S32 x, S32 y, U8 *img_p, audply_buttons_state_enum state)
{

#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 w_fg, h_fg;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	gdi_image_get_dimension(img_p, &w_fg, &h_fg);
	gdi_layer_push_and_set_clip(x, y, x + w_fg - 1, y + h_fg - 1);
    /*gdi_image_draw_resized(
        0, 
        0, 
        UI_device_width, 
        UI_device_height, 
        audply_main_bg.audply_main_bg_img);
    gdi_image_draw(
        audply_main_bg.audply_main_bg_panel_x, 
        audply_main_bg.audply_main_bg_panel_y, 
        audply_main_bg.audply_main_bg_panel_img);
        */
	//gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
	gui_draw_filled_area(0,0,UI_device_width-1,UI_device_height-1, 
 	       current_MMI_theme->sub_menu_bkg_filler);
	if(state == AUDPLY_MAIN_DISABLE)
	{
		
		gui_draw_image_with_alpha_transparent(img_p,x,y,128);
	}
	else
	{

	gdi_image_draw(x , y , img_p);
	}
	switch (state)
	{
		case AUDPLY_MAIN_DOWN:
		{

			gdi_image_draw_resized(x, y, w_fg, h_fg, audply_main_bg.audply_main_button_img_hilite);

			break;
		}
		default:
			break;
	}
	
	//gdi_pop_and_restore_alpha_blending_source_layer();
	gdi_layer_pop_clip();
    //gdi_layer_save_bmp_file(gdi, (CHAR*)L"D:\\2.bmp");

#elif defined(__MMI_SLIM_IMG_RES__)



    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w_bg, h_bg;
    S32 w_fg, h_fg;
    gdi_handle active_layer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension(audply_main_bg.audply_main_bg_button_img, &w_bg, &h_bg);
    gdi_image_get_dimension(img_p, &w_fg, &h_fg);
    gdi_layer_push_and_set_clip(x, y, x + w_bg - 1, y + h_bg - 1);
    gdi_draw_solid_rect(x, y, x + w_bg - 1, y + h_bg - 1, audply_main_bg.audply_main_bg_color);

    /* render button general background */
    gdi_image_draw(x, y, audply_main_bg.audply_main_bg_button_img);
    /* render button general forground */
    gdi_image_draw(x + (w_bg - w_fg) / 2, y + (h_bg - h_fg) / 2, img_p);
    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);
    switch (state)
    {
        case AUDPLY_MAIN_DOWN:
        {
            gdi_image_draw_resized(x, y, w_bg, h_bg, audply_main_bg.audply_main_button_img_hilite);
            break;
        }
        case AUDPLY_MAIN_DISABLE:
        {
            gdi_image_draw_resized(x, y, w_bg, h_bg, audply_main_bg.audply_main_button_img_disable);
            break;
        }
        default:
            break;
    }
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_clip();

#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw(x, y, img_p);
#endif
    return;
}

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

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(audply_skin_layer);
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */

/*#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 


    gdi_layer_push_and_set_clip(audply_main_buttons_x1, audply_main_buttons_y1, audply_main_buttons_x2, audply_main_buttons_y2);
    */
    mmi_audply_gdi_layer_push_clip(audply_main_buttons_x1, audply_main_buttons_y1, audply_main_buttons_x2, audply_main_buttons_y2);
    /*Redraw Play/Pause button, choose by state.*/
    if (selected_button == AUDPLY_MAIN_DISABLED)
    {
        mmi_audply_draw_button(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_buttons[AUDPLY_MAIN_PLAY].off_img, AUDPLY_MAIN_DISABLE);
    }
    else if (selected_button == AUDPLY_MAIN_PLAY && g_audply_main_selected_button_down)
    {
        mmi_audply_draw_button(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_buttons[AUDPLY_MAIN_PLAY].down_img, AUDPLY_MAIN_DOWN);
    }
    else if (selected_button == AUDPLY_MAIN_PAUSE && g_audply_main_selected_button_down)
    {
        if (g_audply.state == STATE_PLAY)
        {
            mmi_audply_draw_button(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_pause_down_img, AUDPLY_MAIN_DOWN);
        }
    }
    else
    {
        if (g_audply.state == STATE_PLAY)
        {
            mmi_audply_draw_button(audply_main_buttons[AUDPLY_MAIN_PLAY].x,audply_main_buttons[AUDPLY_MAIN_PLAY].y,audply_main_pause_off_img, AUDPLY_MAIN_UP);
        }
        else
        {
            mmi_audply_draw_button(audply_main_buttons[AUDPLY_MAIN_PLAY].x, audply_main_buttons[AUDPLY_MAIN_PLAY].y, audply_main_buttons[AUDPLY_MAIN_PLAY].off_img, AUDPLY_MAIN_UP);
        }
    }
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    /*Redraw Prev, Next, Stop button*/
    for (i = AUDPLY_MAIN_PREV; i <= AUDPLY_MAIN_NEXT; i++)
    {
        if (selected_button == AUDPLY_MAIN_DISABLED)
        {
            mmi_audply_draw_button(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].off_img, AUDPLY_MAIN_DISABLE);
        }
        else if (selected_button == i && g_audply_main_selected_button_down)
        {
            mmi_audply_draw_button(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].down_img, AUDPLY_MAIN_DOWN);
        }
        else
        {
            mmi_audply_draw_button(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].off_img, AUDPLY_MAIN_UP);
        }
    }
#else
    /*Redraw Prev, Next, Stop button*/
    for (i = AUDPLY_MAIN_PREV; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
        if (selected_button == AUDPLY_MAIN_DISABLED)
        {
            mmi_audply_draw_button(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].off_img, AUDPLY_MAIN_DISABLE);
        }
        else if (selected_button == i && g_audply_main_selected_button_down)
        {
            mmi_audply_draw_button(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].down_img, AUDPLY_MAIN_DOWN);
        }
        else
        {
            mmi_audply_draw_button(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].off_img, AUDPLY_MAIN_UP);
        }
    }
#endif
   /* gdi_layer_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        audply_main_buttons_x1,
        audply_main_buttons_y1,
        audply_main_buttons_x2,
        audply_main_buttons_y2);
#endif*/ /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
mmi_audply_gdi_layer_pop_clip_blt(audply_main_buttons_x1,
                        audply_main_buttons_y1,
                        audply_main_buttons_x2,
                        audply_main_buttons_y2);
#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */

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
#ifdef __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__

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

#endif
}

#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__) //|| defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)

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
    gdi_layer_push_and_set_active(audply_skin_layer);
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */
    audply_main_repeat.down = MMI_FALSE;
	audply_main_shuffle.down = MMI_FALSE;
    
    /* show repeat icon */
    x1 = (S32) audply_main_repeat.x;
    y1 = (S32) audply_main_repeat.y;
    x2 = x1 + audply_main_repeat.w - 1;
    y2 = y1 + audply_main_repeat.h - 1;
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
    mmi_audply_draw_button(x1, y1, image_id, AUDPLY_MAIN_UP);

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
    mmi_audply_draw_button(x1, y1, image_id, AUDPLY_MAIN_UP);

#ifdef __GDI_MEMORY_PROFILE_2__
	gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */
}
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
    S32 w_bg,h_bg;
    PU8 image_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __GDI_MEMORY_PROFILE_2__
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    gdi_layer_push_and_set_active(audply_skin_layer);
	gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#else
    gdi_layer_push_and_set_active(audply_osd_layer);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */

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

    /* background & indicator */
    mmi_audply_draw_button(x1, y1, image_id, down ? AUDPLY_MAIN_DOWN : AUDPLY_MAIN_UP);
    
#ifdef __GDI_MEMORY_PROFILE_2__
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
	gdi_pop_and_restore_alpha_blending_source_layer();
	gdi_layer_pop_and_restore_active();
#else
	gdi_layer_pop_and_restore_active();
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */

#if(UI_DOUBLE_BUFFER_SUPPORT)
#if (!defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__) && defined(__MMI_SLIM_IMG_RES__))
    gdi_image_get_dimension(audply_main_bg.audply_main_bg_button_img, &w_bg, &h_bg);
		x2 = x1 + w_bg;
		y2 = y1 + h_bg;
#endif
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
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
    S32 w_bg,h_bg;
    PU8 image_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
        gdi_layer_push_and_set_active(audply_skin_layer);
		gdi_push_and_set_alpha_blending_source_layer(audply_skin_layer);
#else
        gdi_layer_push_and_set_active(audply_osd_layer);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */
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

    /* background & indicator */
    mmi_audply_draw_button(x1, y1, image_id, down ? AUDPLY_MAIN_DOWN : AUDPLY_MAIN_UP);

#ifdef __GDI_MEMORY_PROFILE_2__
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
		gdi_pop_and_restore_alpha_blending_source_layer();
		gdi_layer_pop_and_restore_active();
#else
		gdi_layer_pop_and_restore_active();
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */

#if(UI_DOUBLE_BUFFER_SUPPORT)
#if (!defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__) && defined(__MMI_SLIM_IMG_RES__))
        gdi_image_get_dimension(audply_main_bg.audply_main_bg_button_img, &w_bg, &h_bg);
		x2 = x1 + w_bg;
		y2 = y1 + h_bg;
#endif
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
	if(!audply_main_repeat.down)
		return;
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
	if(!audply_main_shuffle.down)
		return;
    g_audply.random_mode = (g_audply.random_mode + 1)%2 ;
    index = mmi_audply_playlist_get_current_index();
    if (index >= 0)
    {
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }
}

#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/





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


#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
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

#endif

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
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_WEARABLE_DEVICE__
    g_swatch_is_pen_down = MMI_TRUE;
    g_swatch_pen_down_pos.x = pos.x;
    g_swatch_pen_down_pos.y = pos.y;
    #endif  //__MMI_WEARABLE_DEVICE__
    
    audply_pen_event_on_object = AUDPLY_PEN_NONE;

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
            case AUDPLY_PEN_MAIN_PLAY:
                area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
                point.x = pos.x - skin_p->play_button_x;
                point.y = pos.y - skin_p->play_button_y;
                break;
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
            case AUDPLY_PEN_MAIN_STOP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
                point.x = pos.x - skin_p->stop_button_x;
                point.y = pos.y - skin_p->stop_button_y;
                break;
            case AUDPLY_PEN_MAIN_SETTING:
                area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                break;
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
#endif

        #if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)                
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

        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            audply_pen_event_on_object = i;
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
        #if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
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
            if(g_audply.seekable)
            {
                g_audply_progress_bar_pen_down_x_pos = pos.x ;
                mmi_audply_touch_progress_hdlr(pos.x);
            }
            break;
        case AUDPLY_PEN_MAIN_PREV:
            mmi_audply_press_prev_button_down();
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__    
            mmi_audply_redraw_main_buttons();  
        #endif            
            break;
        case AUDPLY_PEN_MAIN_NEXT:
            mmi_audply_press_next_button_down();
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__    
            mmi_audply_redraw_main_buttons();   
        #endif
            break;
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
        case AUDPLY_PEN_MAIN_SETTING:
            mmi_audply_redraw_main_setting(MMI_TRUE);
            break;
        case AUDPLY_PEN_MAIN_STOP:
            mmi_audply_press_stop_button_down();
            break;
#endif
        case AUDPLY_PEN_MAIN_PLAY:
            g_audply_main_pen_move_more_than_once = MMI_FALSE ;
            mmi_audply_press_play_button_down();
            break;
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
        case AUDPLY_PEN_MAIN_REPEAT:
            mmi_audply_redraw_main_repeat(MMI_TRUE);
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            mmi_audply_redraw_main_shuffle(MMI_TRUE);
            break;            
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
        case AUDPLY_PEN_MAIN_VOLUME_INC:
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
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
                }
               
                mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_FALSE);
            }
            break;
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            if (g_audply.volume == MDI_AUD_VOL_EX_MUTE_MIN)
            {
                mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_TRUE);
            }
            else
            {
                mmi_audply_press_dec_volume();
                
                if (g_audply.volume < MDI_AUD_VOL_EX_MUTE_MAX - 1)
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
                }
                mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_FALSE);
            }
            break;
#endif
        default:
            break;
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_LSK:
            mmi_audply_redraw_LSK_up();
            break;
        case AUDPLY_PEN_RSK:
            mmi_audply_redraw_RSK_up();
            break;
    }
    g_audply_main_selected_button_down = MMI_FALSE;
    audply_pen_event_on_object = AUDPLY_PEN_NONE;
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
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_WEARABLE_DEVICE__
    if (g_swatch_is_pen_down && ((pos.x - g_swatch_pen_down_pos.x) > MMI_SWATCH_BACK_MOVE_THRESHOLD_X))  //swipe right
    {
        mmi_frm_scrn_close_active_id();
        g_swatch_is_pen_down = MMI_FALSE;
        return;
    }
    #endif  //__MMI_WEARABLE_DEVICE__
    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_SEEK:
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
            else
            {
                 g_audply_main_selected_button_down = MMI_FALSE;
                 StopTimer(AUDPLY_SEEKING_TIMER);
                 mmi_audply_redraw_main_buttons();
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
            else
            {
                 g_audply_main_selected_button_down = MMI_FALSE;
                 StopTimer(AUDPLY_SEEKING_TIMER);
                 mmi_audply_redraw_main_buttons();
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
	    else
	    {
		g_audply_main_selected_button_down = MMI_FALSE;
                mmi_audply_redraw_main_buttons();
	    }
            break;
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
        case AUDPLY_PEN_MAIN_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
            point.x = pos.x - skin_p->stop_button_x;
            point.y = pos.y - skin_p->stop_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_stop_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_SETTING:
            area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
            point.x = pos.x - skin_p->setting_x;
            point.y = pos.y - skin_p->setting_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {    
                mmi_audply_redraw_main_setting(MMI_FALSE);  
            #if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
                mmi_audply_entry_two_layers_settings();
            #elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
                if (AUDPLY_SETTING_ITEM_COUNT <= 10)
                {
                    mmi_audply_entry_settings();
                }
                else
                {
                    mmi_audply_entry_two_layers_settings();
                }
            #endif
            }
            break;
#endif
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
            case AUDPLY_PEN_MAIN_VOLUME_DEC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                if (g_audply.volume == 0)
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
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
                } 
                break;
#endif
    #if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
        case AUDPLY_PEN_MAIN_REPEAT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
            point.x = pos.x - skin_p->repeat_x;
            point.y = pos.y - skin_p->repeat_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_touch_repeat_toggle();
                
            }
            mmi_audply_redraw_main_repeat(MMI_FALSE);
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
            point.x = pos.x - skin_p->shuffle_x;
            point.y = pos.y - skin_p->shuffle_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_touch_shuffle_toggle();
               
            }
	   mmi_audply_redraw_main_shuffle(MMI_FALSE);
            break;            
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */            

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
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

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
                    if (g_audply.state_before_longpress == STATE_PLAY)
                    {
                        mmi_audply_press_next_button_up();
                        g_audply.state_before_longpress = STATE_IDLE;
                    }
                    g_audply_main_selected_button_down = MMI_FALSE;
                    StopTimer(AUDPLY_SEEKING_TIMER);
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
                    if (g_audply.state_before_longpress == STATE_PLAY)
                    {
                        mmi_audply_press_prev_button_up();
                        g_audply.state_before_longpress = STATE_IDLE;
                    }
                    g_audply_main_selected_button_down = MMI_FALSE;
                    StopTimer(AUDPLY_SEEKING_TIMER);
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
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
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
                g_audply_main_selected_button_down = MMI_FALSE;
            }
        break;
        case AUDPLY_PEN_MAIN_SETTING:
            area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
            point.x = pos.x - skin_p->setting_x;
            point.y = pos.y - skin_p->setting_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_setting(MMI_TRUE);
            }else
            {
                mmi_audply_redraw_main_setting(MMI_FALSE);
                g_audply_main_selected_button_down = MMI_FALSE;
            }           
            break;
#endif
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
            point.x = pos.x - skin_p->volume_inc_x;
            point.y = pos.y - skin_p->volume_inc_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                if (g_audply.volume < MDI_AUD_VOL_EX_NUM - 1)
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_FALSE);
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
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
                }
                g_audply_main_selected_button_down = MMI_FALSE;
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
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_TRUE);
                }
            }
            else
            {
                if (g_audply.volume > 0)
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
                }
                else
                {
                    mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
                }
                g_audply_main_selected_button_down = MMI_FALSE;
            }
            break;
#endif
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)// || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)                
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
                g_audply_main_selected_button_down = MMI_FALSE;
            }
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
            point.x = pos.x - skin_p->shuffle_x;
            point.y = pos.y - skin_p->shuffle_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_shuffle(MMI_TRUE);
            }
            else
            {
                mmi_audply_redraw_main_shuffle(MMI_FALSE);
                g_audply_main_selected_button_down = MMI_FALSE;
            }
            break;
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
        case AUDPLY_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_audply_redraw_LSK_down();
            }
            else
            {
                mmi_audply_redraw_LSK_up();
                g_audply_main_selected_button_down = MMI_FALSE;
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
                g_audply_main_selected_button_down = MMI_FALSE;
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
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audply_pen_event_on_object)
    {
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
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
                    }
                    else
                    {
                        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
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
                }
            }
            break;
#endif
        default:
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
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_MAIN_PREV:
        {
            area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
            point.x = pos.x - skin_p->prev_button_x;
            point.y = pos.y - skin_p->prev_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                StopTimer(AUDPLY_SEEKING_TIMER);
                mmi_audply_press_prev_button_longpress();
            }
            break;
        }
        case AUDPLY_PEN_MAIN_NEXT:
        {
            area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
            point.x = pos.x - skin_p->next_button_x;
            point.y = pos.y - skin_p->next_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                StopTimer(AUDPLY_SEEKING_TIMER);
                mmi_audply_press_next_button_longpress();
            }
            break;
        }
        default:
            break;
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
        StopTimer(AUDPLY_SEEKING_TIMER);
        StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_fast_forward);
    }
    else
    {
        /*rewind*/
        StopTimer(AUDPLY_SEEKING_TIMER);
        StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_rewind);
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
    StopTimer(AUDPLY_DISPLAY_LYRICS_TIMER);
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
        mmi_audply_redraw_main_buttons();
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
    }     
     
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
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

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
MMI_BOOL mmi_audply_is_lyrics_valid(void)
{
    if (g_audply_skins[g_audply.skin].lyric_display_x >= 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */

#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) &&(defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__))
MMI_BOOL mmi_audply_spectrum_lyrics_exclusive(void)
{
    if (g_audply_skins[g_audply.skin].spectrum_lyrics_exclusive)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) */

#endif /*__MMI_MAINLCD_96X64__*/
#endif /*#ifdef __MMI_FTE_SUPPORT__*/
#if !(defined __MMI_MAINLCD_96X64__)
void mmi_audply_reset_skin_layer(void)
{
	is_audply_skin_layer_drawn = MMI_FALSE;
	mmi_audply_redraw_main_screen();
}
#endif /*0*/
#if defined __MMI_MAINLCD_96X64__


S16         g_audply_main_selected_button = AUDPLY_MAIN_DISABLED;
MMI_BOOL    g_audply_main_selected_button_down;         //Is any button being selected down
extern audply_struct g_audply;

void mmi_audply_redraw_main_repeat(MMI_BOOL down)
{
}
void mmi_audply_touch_repeat_toggle(void)
{
}
void mmi_audply_redraw_main_shuffle(MMI_BOOL down)
{
}
void mmi_audply_touch_shuffle_toggle(void)
{
}

void mmi_audply_redraw_main_buttons(void)
{
}

void mmi_audply_redraw_main_time(void)
{
	if(g_audply.in_main_screen)
	{
		wgui_cat223_update_duration(g_audply.new_play_time/4.615);
	}
}

void mmi_audply_redraw_main_progressbar(void)
{
}


void mmi_audply_redraw_main_file_index(void)
{
}

void mmi_audply_redraw_main_title(void)
{
	mmi_audply_update_main();

}

void mmi_audply_redraw_main_volumebar(void)
{
}

void mmi_audply_redraw_LSK_up(void)
{
}
void mmi_audply_redraw_RSK_up(void)
{
}
void mmi_audply_redraw_main_screen(void)
{
    mmi_audply_update_main();

}

void mmi_audply_exit_mainscreen(void)
{
	g_audply.in_main_screen = MMI_FALSE;
}

#endif/*__MMI_MAINLCD_96X64__*/
#endif /* __MMI_AUDIO_PLAYER__ */ 
