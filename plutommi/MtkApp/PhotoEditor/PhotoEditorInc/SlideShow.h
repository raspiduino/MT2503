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
 *  SlideShow.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Slide Show Applcation Header of PhotoEditor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SLIDSHOW_H_
#define _SLIDSHOW_H_

#include "MMI_features.h"
#ifdef __MMI_SLIDESHOW__

/***************************************************************************** 
* Define
*****************************************************************************/

/* Transition effects */
//#define __MMI_SLIDSHOW_WIPE_ENABLE__ 
#define __MMI_SLIDSHOW_M3D_SUPPORT__      /* for M3D support */

#define SLIDSHOW_MAX_FILENAME_CHAR          (SRV_FMGR_PATH_MAX_FILE_NAME_LEN -SRV_FMGR_PATH_MAX_FILE_EXT_LEN )      /* max file name len */
#define SLIDSHOW_FRAME_BUFFER_SIZE          ((UI_DEVICE_WIDTH*UI_DEVICE_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)

#ifdef __MMI_SLIDESHOW_SPECIFIC_SPEED__
#define SLIDSHOW_LOW_SPEED                  (10000)      /* 5 sec    */
#define SLIDSHOW_MEDIUM_SPEED               (5000)      /* 3 sec    */
#define SLIDSHOW_FAST_SPEED                 (1000)      /* 1 sec    */
#else
#define SLIDSHOW_LOW_SPEED                  (5000)      /* 10 sec    */
#define SLIDSHOW_MEDIUM_SPEED               (3000)       /* 5 sec    */
#define SLIDSHOW_FAST_SPEED                 (1000)      /* 1 sec    */
#endif

#define SLIDSHOW_ANIM_NEXT_IMG_DELAY        (300)       /* 0.3 sec  */
#define SLIDSHOW_ERROR_SKIP_DELAY           (500)       /* 0.5 sec  */
#define SLIDSHOW_HORIZONTAL_VIEW            (1)
#define BACKGROUND_MUSIC_ON                 (1)
#define SLIDSHOW_OSD_FADE_OUT_TIME          (2*1000)    /* 2 sec */
#define SLIDSHOW_OSD_FADE_OUT_VALUE         (32)        /* fade 32/256 */
#define SLIDSHOW_OSD_FADE_IN_VALUE          (32)        /* fade in 32/256 */
#define SLIDSHOW_EFFECT_SHIFT_VALUE         (10)        
#ifdef __TC01__
/* under construction !*/
#else
#define SLIDSHOW_INIT_AUDIO_VOL             (LEVEL4)    /* LEVEL4 == 3 */
#endif
#define SLIDSHOW_KEY_PRESS_DELAY            (400)       /* delay time of pressing a key (in ms)*/

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
#define SLIDESHOW_FRAME_BUFFER_SIZE         ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#define SLIDESHOW_FRAME_BUFFER_SIZE_24_BIT  (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 3)
#else
#define SLIDESHOW_FRAME_BUFFER_SIZE         (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 2)
#endif
#define SLIDESHOW_FILE_FOLDER_SEPERATOR     L"."

#define SLIDSHOW_POWER_SAVING
#define SLIDSHOW_POW_SAVE_DELAY  (120000)    /* auto turn off backlight if paused over 2 minutes */

/*softkey rotate coordinate, used on the landscape platform*/
#define MMI_SLIDESHOW_ROTATE_TOP_GAP (3)
#define MMI_SLIDESHOW_ROTATE_RIGHT_GAP (3)
#define MMI_SLIDESHOW_ROTATE_SOFTKEY_WIDTH  (LCD_WIDTH/2)

#ifdef __MMI_MAINLCD_320X240__
#define __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
#endif

/***************************************************************************** 
* typedef 
*****************************************************************************/

typedef enum
{
    SLIDSHOW_TYPE_OF_PLAY,
    SLIDSHOW_SPEED,
    SLIDSHOW_EFFECT,
    SLIDSHOW_BGM,
    SLIDSHOW_HORIZONTAL_DISPLAY,
    SLIDSHOW_SOUND_EFFECT,
    SLIDSHOW_SETTING_COUNT
} slidshow_setting_enum;

typedef enum
{
    SLIDSHOW_AUTO_ONCE,
    SLIDSHOW_AUTO_REPEAT,
    SLIDSHOW_MANUAL
} slidshow_type_of_play_enum;

typedef enum
{
    SLIDSHOW_LOW,
    SLIDSHOW_MEDIUM,
    SLIDSHOW_FAST
} slidshow_speed_enum;

typedef enum
{
    SLIDSHOW_EFFECT_NORMAL,
    SLIDSHOW_EFFECT_FADE_IN,
    SLIDSHOW_EFFECT_SPLIT,
#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__ 
    SLIDSHOW_EFFECT_WIPE,
#endif /* __MMI_SLIDSHOW_WIPE_ENABLE__  */  
    SLIDSHOW_EFFECT_RANDOM,

    SLIDSHOW_EFFECT_TOTAL
} slidshow_effect_enum;

typedef enum
{
    SLIDSHOW_BGM_OFF,
    SLIDSHOW_BGM_SELECT
} slidshow_bgm_enum;

typedef enum
{
    SLIDSHOW_AUDIO_OFF,
    SLIDSHOW_AUDIO1,
    SLIDSHOW_AUDIO2,
    SLIDSHOW_AUDIO3
} slidshow_sound_effect_enum;

typedef enum
{
    SLIDSHOW_VIDEO_CLOSE = 0,       /* close == file not open   */
    SLIDSHOW_VIDEO_STOP,            /* opened, but not playing  */        
    SLIDSHOW_VIDEO_PLAYING,         /* opened and playing       */
    SLIDSHOW_VIDEO_PAUSE            /* paused                   */
} slidshow_video_stat_enum;

#ifdef __DRM_SUPPORT__
typedef enum
{
    SLIDESHOW_DRM_FREE_TO_DISP = 0,         /* not a DRM file or we have rights */
    SLIDESHOW_DRM_PROHIBIT,         /* we don't have right */
    SLIDESHOW_DRM_ARCHIVE,          /* multipart DRM */
    
    SLIDESHOW_DRM_TOTAL
} slideshow_drm_type_enum;
#endif /* __DRM_SUPPORT__ */

typedef enum
{
    SLIDESHOW_ERR_NO_ERROR = 0,         /* no error */
    SLIDESHOW_ERR_OTHER,
    SLIDESHOW_ERR_PROHIBIT,
   
    SLIDESHOW_ERR_TOTAL
} slideshow_error_cause_enum;

/* 64 byte */
typedef struct
{
    /* Slide Show - 28 byte */
    S32 type_of_play;
    S32 speed;
    S32 effect;
    S32 bgm;
    S32 horz;
    S32 sound_effect;
    S32 is_bgm_path_short;

    /* reserve 36 byte for future app */
    S32  file_sort_type;
    U8 reserve[32];

} slidshow_nvram_data_struct;


typedef struct
{
    /*64 Bit*/
    U64 play_time;
    U64 vdo_total_duration;

    /*32 Bit*/
    S32 effect_value;
    S32 speed_value;
    S32 resized_image_offset_x;
    S32 resized_image_offset_y;
    S32 resized_image_width;
    S32 resized_image_height;
    S32 tv_layer_w;
    S32 tv_layer_h;
    S32 tv_offset_x;
    S32 tv_offset_y;
    S32 is_short_path;
    S32 idx2shift;
    S32 text_select_highlight_index;
    S32 fl_idx;
    S32 file_index_from_others;
    U32 fmgr_service_id;
    U32 fmgr_service_id_of_select_audio;
#ifdef __DRM_SUPPORT__
    U32 id_DRM;
#endif 
    U32 curr_play_time;

    gdi_handle h_animate;
    gdi_handle h_animate_tv;

    gdi_handle base_layer_handle;
    gdi_handle osd_layer_handle;
    gdi_handle play_layer_handle;
    gdi_handle osd_layer_handle_of_idp_rotate;
    gdi_handle extra_layer_1;
    gdi_handle extra_layer_2;
	gdi_handle bg_layer_handle;

    PU8 osd_layer_buf_ptr;
    PU8 play_layer_buf_ptr;
    PU8 osd_layer_buf_ptr_of_idp_rotate;
    PU8 bg_layer_buf_ptr;
	PU8 base_layer_buf_ptr;
    PU8 app_mem_bufer;
    PS8 audio_file_path;
    PS8 tmp_file_path;
    PS8 media_obj_file_path[SRV_FMGR_PATH_BUFFER_SIZE];
    PU8 fmgr_list_buffer;

    /*16 Bit*/
    U16 osd_opacity;
    U16 sort_type;

    /*8 Bit*/
    U8 is_typeofplay_set;
    U8 is_speed_set;
    U8 is_effect_set;
    U8 is_sound_effect_selected;
    U8 is_file_sort;
    S8 audio_volume;

    /*Special*/
    BOOL is_edited;
    BOOL is_bgmusic_selected;
    BOOL is_random_effect;
    BOOL is_lsk_pressed;
    BOOL is_rsk_pressed;
    BOOL is_left_arrow_pressed;
    BOOL is_right_arrow_pressed;
    BOOL is_vdo_opened;
    BOOL is_image_type;
    BOOL is_video_type;
    BOOL is_video_file;
    BOOL is_bgm_play;
    BOOL is_select_file;
    BOOL extra_layer_var;
    BOOL is_bgm_set;
    BOOL is_horz_view_set;
    BOOL is_sub_display;                /* for drawing sublcd when playing video. */
    BOOL cat57_done_flag;
    BOOL is_valid_bgm;
    BOOL time_4_next_img;
    BOOL effect_finish;                 /* can trigger next img */
    BOOL is_diff_anim;                  /* for blocking sequence gif files with rapidly key press */
    BOOL is_from_next;                  /* for user pressed lak  after passed an invalid file */
    BOOL is_finished;                   /* to check if play finished for option menu hilight item.*/
    BOOL s7y_enable;              /* remember if source key is enabled or not       */
    BOOL is_animation;
    
    MMI_BOOL is_sort_finished;
    MMI_BOOL is_stop_play;
    MMI_BOOL is_file; /*TRUE : file, FALSE: folder*/
    MMI_BOOL apply_file_index;
    MMI_BOOL is_from_other_app;
    MMI_BOOL is_drawing_video_use_idp;
    MMI_BOOL is_stop_resume;
    MMI_BOOL is_hilite_change;
    MMI_BOOL is_in_background_call;
    MMI_BOOL is_video_drm_prohibit;
    MMI_BOOL is_pen_down;
    MMI_BOOL is_video_play_finished;
    MMI_BOOL is_prev_file_image;
    MMI_BOOL is_meet_folder_selector_error;

    /*Others Bit*/
    GDI_RESULT result;
    slideshow_error_cause_enum error_code;               /* back from error popup */    
    slidshow_video_stat_enum v_state;
    color text_color;
    color text_border_color;
    gdi_color old_source_key;     /* save the layer source key for the base layer   */
    FuncPtr end_key_hdlr;
    /* nvram setting */
    slidshow_nvram_data_struct setting;
    /* text inline selection */
    UI_string_type play_type_str[3];    /* auto once, auto repeat, manual */
    UI_string_type speed_str[3];        /* Low, medium, fast */
    UI_string_type effect_str[5];       /* normal, fade in, split, wipe, random */
    UI_string_type bgm_str[2];          /* off, select from file */
    UI_string_type horz_str[2];         /* off, on */
    UI_string_type sound_effect_str[4]; /* off, aud1, aud2, aud3 */
    UI_string_type file_sort_str[5];
    SRV_FMGR_FILELIST_HANDLE fl_hdl;
    FMGR_FILTER filter;
    mmi_slideshow_browse_type_enum browse_type;
    mmi_id cur_gid;
    mmi_id setting_gid;
} slidshow_cntx_struct;

/* Touch Screen */
#ifdef __MMI_TOUCH_SCREEN__

#include "wgui_touch_screen.h"

typedef enum
{
    SLIDSHOW_NONE,
    SLIDSHOW_LSK,
    SLIDSHOW_RSK,
    SLIDSHOW_LEFT_ARROW,
    SLIDSHOW_RIGHT_ARROW
} slidshow_touch_item_enum;

typedef struct
{
    U32 pen_event_on_object;
    wgui_component_info_struct lsk;
    wgui_component_info_struct rsk;
    wgui_component_info_struct left_arrow;
    wgui_component_info_struct right_arrow;
} slidshow_touch_screen_context_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 


typedef enum
{
    MMI_SLIDSHOW_FILE_SORT_BY_NONE = 0,
    MMI_SLIDSHOW_FILE_SORT_BY_NAME,
    MMI_SLIDSHOW_FILE_SORT_BY_TYPE,
    MMI_SLIDSHOW_FILE_SORT_BY_TIME,
    MMI_SLIDSHOW_FILE_SORT_BY_SIZE,
    MMI_SLIDSHOW_FILE_SORT_BY_ALL
} mmi_slidshow_file_sort_enum;

#endif /* __MMI_SLIDESHOW__ */ 
#endif /* _SLIDSHOW_H_ */ 

