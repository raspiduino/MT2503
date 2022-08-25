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
*  MediaPlayerFTEMainScreen.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player FTE Main screen
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "MMI_include.h"

#if defined(__MMI_MEDIA_PLAYER_FTE__)

#include "MMIDataType.h"  
#include "kal_general_types.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "SSCStringTable.h"
#include "string.h"
    
#include "gui.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gui_font_size.h"
#include "gui_windows.h"
#include "gdi_lcd_config.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "gui_themes.h"
#include "wgui_inputs.h"

#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_gestures_gprot.h"
#include "TimerEvents.h"
#include "CustDataRes.h"
#include "GpioSrvGprot.h"
#include "lcd_sw_inc.h"

#include "FileMgrSrvGProt.h"
#include "UcmSrvGprot.h"
#include "app_mem.h"
#include "PixcomFontEngine.h"
#include "meta_tag_api.h"

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gui_spectrum.h"
#endif

#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
#include "lyrics_parser.h"
#endif

#include "mdi_include.h"
#include "mdi_video.h"
#include "mdi_audio.h"

#include "MediaAppWidgetDef.h"
#include "mmi_rp_app_medply_def.h"
#include "MediaPlayerGprot.h"
#include "MediaPlayerProt.h"
#include "MediaPlayerFTEMainScreen.h"
#include "resource_mediaplayer_skins.h"
#include "MediaPlayerKuroSkin.h"
#include "MediaPlayerEnumDef.h"
#include "MMI_media_app_trc.h"
#include "MediaPlayerPlayList.h"
#include "kurodatatype.h"    

/*
**  PART BLT, for LCD update to HW may has tearing when we update region is not full screen
**  driver hope MMI need update from line 0, ie y postion should be 0; 
**  it will caused top layer update together with view layer
**  currently we only modify this for audio demo animation
*/
//#define MMI_MEDPLY_COMP_USING_PART_BLT
//#ifdef  MMI_MEDPLY_COMP_USING_PART_BLT
//#include "lcd_if.h"
/*void lcd_enable_partial_update(kal_bool flag); */
//#endif

/*
**  #define GDI_COLOR_FORMAT_UYVY422       6    
**  use UYUV to play video for good performance, but need GDI & HW support this function first!    
*/

/*  DEFINE INLINE FILE MACRO
*/
#if defined(MT6225)
#define MMI_MEDPLY_COMP_USING_RGB888_LAYER      0
#else
#define MMI_MEDPLY_COMP_USING_RGB888_LAYER      1
#endif

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) && defined(__MMI_MEDIA_PLAYER_AUDIO__)
#define MMI_MEDPLY_COMP_USING_GESTURES          1
#else     
#define MMI_MEDPLY_COMP_USING_GESTURES          0
#endif

//HAL
#if defined(__MMI_MAINLCD_320X240__)
#define MMI_MEDPLY_COMP_FULLSCR_ROTATE_BUFFER	0
#else
#define MMI_MEDPLY_COMP_FULLSCR_ROTATE_BUFFER	1
#endif

#if defined(__MMI_MAINLCD_320X240__)
#define MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER    0
#else
#define MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER    1
#endif

#ifdef __MMI_VIDEO_3D_ANAGLYPH__
#define MMI_MSCR_SHOW_3D_VIDEO_ICON
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#define MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
#if defined(__MMI_MAINLCD_320X480__)
#define MMI_MSCR_SUBTITLE_FONT_SIZE                   20
#else
#define MMI_MSCR_SUBTITLE_FONT_SIZE                   16
#endif
#define MMI_MSCR_SUBTITLE_HOR_GAP                     2
#define MMI_MSCR_SUBTITLE_CF_DEEPTH                   4
/*due to some char will not align, such as "p" and "g", may be partcially cut if set subtitle layer height equal to line_num*font_height
  *so, line_num = actual_line_number * 2. 
  * e.g when we want to show 2 line subtitle, MMI_MSCR_SUBTITLE_LINE_NUMBER must defined to 4.
  */
#define MMI_MSCR_SUBTITLE_LINE_NUMBER                 4
#define MMI_MSCR_SUBTITLE_MAX_BUF_SIZE                (MMI_MSCR_SUBTITLE_LINE_NUMBER*MMI_MSCR_SUBTITLE_FONT_SIZE*GDI_LCD_HEIGHT*MMI_MSCR_SUBTITLE_CF_DEEPTH)
#else  /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */
#define MMI_MSCR_SUBTITLE_MAX_BUF_SIZE                0
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */

#if (0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER) && (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_BUFFER)
#define MMI_MEDPLY_COMP_VIDEO_ROTATE
#endif

#ifdef __MMI_MAINLCD_320X480__ 
#define MMI_MEDPLY_HILIGHT_ICON_W				80  /*keep 4 byte align*/         
#define MMI_MEDPLY_HILIGHT_ICON_H				80  /*keep 4 byte align*/
#define MMI_MEDPLY_DOT_W                        24
#else
#define MMI_MEDPLY_HILIGHT_ICON_W				48  /*keep 4 byte align*/             
#define MMI_MEDPLY_HILIGHT_ICON_H				48  /*keep 4 byte align*/    
#define MMI_MEDPLY_DOT_W                        20
#endif

#ifdef __MMI_MAINLCD_320X480__
#define MMI_MEDPLY_VOLUME_STEP					5
#elif __MMI_MAINLCD_240X400__
#define MMI_MEDPLY_VOLUME_STEP					5
#else
#define MMI_MEDPLY_VOLUME_STEP					5
#endif

#ifdef __MMI_MAINLCD_320X480__
#define MMI_MEDPLY_RATING_W						40
#define MMI_MEDPLY_RATING_STEP					10
#elif __MMI_MAINLCD_240X400__
#define MMI_MEDPLY_RATING_W						32
#define MMI_MEDPLY_RATING_STEP					5
#else
#define MMI_MEDPLY_RATING_W						32
#define MMI_MEDPLY_RATING_STEP					5
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#define MMI_MSCR_SPECTRUM_NUM					16
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#define MMI_MSCR_COLOR_DEPTH					2
#define MMI_MSCR_LAYER_BUFFER_SIZE				MEDPLY_MAIN_SCREEN_LAYER_SIZE
#define MMI_MSCR_LAYER_COLOR_BACKGROUND			GDI_COLOR_BLACK
#define MMI_MSCR_LAYER_COLOR_TRANSPARENT		GDI_COLOR_TRANSPARENT 
#define MMI_MSCR_FILE_NAME_LEN					(SRV_FMGR_PATH_MAX_LEN+1)
#define MMI_MSCR_FILE_PATH_LEN					(SRV_FMGR_PATH_MAX_LEN+1)
#define MMI_MSCR_USER_RATE_MAX_LEVEL			5
/*
**  (MDI_AUD_VOL_EX_NUM-1)  used in 0 can hear sound
**  MDI_AUD_VOL_EX_MUTE_MAX used in 0 can not hear sound, mute
*/
#define MMI_MSCR_VOLUME_MAX_LEVEL				MDI_AUD_VOL_EX_MUTE_MAX
#define MMI_MSCR_ARTWORK_SIZE					(MMI_MSCR_LAYER_BUFFER_SIZE-MEDPLY_MAIN_SCREEN_HDL_SIZE)


#define MMI_MSCR_ERR_IMG_ID						0

#define MEDPLY_MAX(x,y) ((x)>(y)?(x):(y))

#define mmi_mscr_clean_blt_rgn()				\
    do											\
    {											\
        g_blt_rgn.x = 0;						\
        g_blt_rgn.y = 0;						\
        g_blt_rgn.w = 0;						\
        g_blt_rgn.h = 0;						\
												\
    } while (0)
#define mmi_mscr_delete_layer                   gdi_layer_free

#define MMI_MSCR_UI_UPDATE_PLAY_TIME            400     /*MS*/
#define MMI_MSCR_UI_UPDATE_SEEK_TIME            100 
#define MMI_MSCR_UI_START_PLAY_TIME             50      /*MS*/
#define MMI_MSCR_UI_POPUP_FADEOUT_TIME          5000    /*MS*/
#define MMI_MSCR_UI_UPDATE_SEEK_CONTENT         5000
#define MMI_MSCR_UI_GESTURE_MOVE_TIME           20      /*MS*/
#define MMI_MSCR_UI_UPDATE_STATUS_TIME          200

/*  
**  DEFINE MAIN SCREEN CONTEXT STRUCT
*/
typedef struct
{ 
    U64             duration;					/*file duration*/
    U64             playtime;
    U64             seektime;
    U64             cachetime;
    U32             flags;    

    U8*             mem_artwork;				/*This memory must same large as layer_mem*/
    U8*             mem_scr_layer;				/*layer create by screen base memory*/
    U8*             mem_base_layer;				/*base layer memory, use for create title/view/panel layer; use for 2d_copy*/
    U8*             mem_gdi_layer;				/*gdi screen memory, create for background image*/
	U8*             mem_hilight;				/*layer create by screen base memory*/

    gdi_handle      layer_hdl[MMI_MSCR_LAYER_ID_TOTAL];
    gdi_handle      layer_video_hdl;        /* add for HAL*/
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    gdi_handle      layer_subtitle_hdl;     /* subtitle layer */
    #endif
	gdi_handle      layer_full_scr_hdl;     
    gdi_handle      layer_gesture;				/*this layer can be created when gesture begin*/
	gdi_handle      layer_prev_icon_bar_hdl;	/*save old icon bar layer handle for resume*/
    gdi_handle      layer_base_hdl;				/**/
    gdi_handle      layer_popup_hdl;
    gdi_handle      layer_ani_hdl;
    gdi_handle      layer_full_ani_hdl;
    gdi_handle      layer_hilight;

    gdi_handle      ani_popup_hdl;				/*popup loading or waiting animation handler*/
    gdi_handle      ani_video_demo_hdl;			/*audio demo animation handler*/

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    mmi_medply_meta_struct*             meta_p; /*lyrics mode also need init meta*/
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    spectrum_struct*    spectrum_p;
#endif											/*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif    

/*#if defined(__MMI_MEDIA_PLAYER_VIDEO__)*/
    mmi_medply_video_play_para_struct*  video_p;
/*#endif*/
    mmi_medply_rect_struct              rgn_popup;
    mmi_medply_rect_struct              rgn_hilight;
	S16 gesture_offset;
    U16 ani_str_id;
    U16 layer_full_scr_w;
    U16 layer_full_scr_h;
    U8  rgn_hide_flag[MMI_MEDPLY_RGN_ID_TOTAL];
    U8  rgn_disable_flag[MMI_MEDPLY_RGN_ID_TOTAL];
    U8  rgn_push_down_id;
	U8  loading_percent;
	U8	popup_type;
    U8  ui_status;
    U8  id_animation;
    U8  view_content;
	U8  view_content_fullscr;
    U8  view_mode;
    
    U8  seek_duration_dst_range;
    U8  video_flags;
        /*
        **  DEFINE VIDEO LAYER FLAGS   
        */
        #define MMI_MSCR_HD_VID_HAS_RESIZE_VIEW             0x01
        #define MMI_MSCR_HD_VID_HAS_RESIZE_LAYER            0x02
        #define MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER         0x04
        #define MMI_MSCR_HD_VID_HAS_USE_UYVY422             0x08
        #define MMI_MSCR_HD_VID_HAS_USE_UYVY422_FULLAYER    0x10
    U8  hilight_flags;
        /*
        **  define hilight flags
        **  before show hilight we'll save old image data of layer
        */     
        #define MMI_MSCR_IS_HILIGHT_PAINT                   0x01
        #define MMI_MSCR_IS_HILIGHT_ERASED                  0x02
    U8  data_from;
    
}   mmi_medply_ui_handle_struct;

/*
**	define global variable
*/
static  mmi_medply_ui_struct                g_mscr_ui;
static  mmi_medply_ui_handle_struct*        g_mscr_hd   = NULL;
    /*
	**	define handle global flags	
	*/
	#define MMI_MSCR_HD_HAS_ROTATE_BY_LAYER     0x00000001  /*Check Whether LCD has been rotate by layer*/	
    #define MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER   0x00000002
    #define MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER   0x00000004
    #define MMI_MSCR_HD_HAS_POPUP_TIMER         0x00000008

    #define MMI_MSCR_HD_HAS_LAYER_ROTATE        0x00000010
    #define MMI_MSCR_HD_HAS_OSD_LAYER           0x00000020  /*maybe we can use layer handle to check whether there has osd aniamtion*/
    #define MMI_MSCR_HD_HAS_PAINT_BG            0x00000040
    #define MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK    0x00000080

    #define MMI_MSCR_HD_HAS_INIT_SPECTRUM       0x00000100
    #define MMI_MSCR_HD_HAS_PLAY_SPECTRUM       0x00000200
    #define MMI_MSCR_HD_HAS_SEEKING_WITH_PEN    0x00000400  
    #define MMI_MSCR_HD_HAS_SEEKING_WITH_KEY    0x00000800

    #define MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV   0x00004000
    #define MMI_MSCR_HD_HAS_PAUSE_ALL           0x00008000

    #define MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI    0x00010000
    #define MMI_MSCR_HD_HAS_PLAYING_TIMER       0x00020000
    #define MMI_MSCR_HD_HAS_STATUS_TIMER        0x00040000
    #define MMI_MSCR_HD_HAS_PEPARE_META         0x00080000 

    #define MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE   0x00100000 
    #define MMI_MSCR_HD_HAS_FULL_SCREEN         0x00200000  /*Check Whether Current play is in full screen*/
    #define MMI_MSCR_HD_HAS_USED_ARTWORK_MEM    0x00400000  /*Check Whether Current play is in full screen*/

    #define MMI_MSCR_HD_IS_RIGHT_TO_LEFT        0x01000000
 
    #define MMI_MSCR_HD_IS_APP_WAITING_PLAY     0x10000000
    #define MMI_MSCR_HD_IS_APP_DELTETING        0x20000000
    #define MMI_MSCR_HD_IS_OSD_WAITING_START    0x40000000  
    #define MMI_MSCR_HD_IS_POPUP_DB_BUFFER      0x80000000    
    
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__  
static  U32                                 g_mscr_flag = 0;
#endif
    /*
    **  define app global flags	
    */ 
    #define MMI_MSCR_UI_HAS_INIT                0x01
    #define MMI_MSCR_UI_HAS_PARSE_LYRICS        0x02
    #define MMI_MSCR_UI_IS_LYRICS_READY         0x04
/*
**	define static function
**	
*/
static  mmi_medply_rect_struct              g_blt_rgn;

static  void    mmi_mscr_merge_blt_rgn(S16 x, S16 y, S16 w, S16 h);

static  void	mmi_mscr_create_handle(void);
static  void	mmi_mscr_delete_handle(void);

static  U8		mmi_mscr_get_view_content(void);
static  void	mmi_mscr_init_view_content(void);

static  void	mmi_mscr_prepare_layer(void);
static  void	mmi_mscr_unprepare_layer(void);
static  gdi_handle  mmi_mscr_create_layer(U8* mem_p, S32 mem_size, 
                        mmi_medply_rect_struct* rgn_p);
static  void    mmi_mscr_prepare_hw_video_layer(MMI_BOOL is_full);
    
static  void    mmi_mscr_init_ui_status(void);
static  void    mmi_mscr_init_regn_status(void);

static  void    mmi_mscr_set_status_and_ani(U8 ui_status, U8 id_ani);
static  void    mmi_mscr_update_duration(void);
static  void    mmi_mscr_update_redraw_button(void);
static  void    mmi_mscr_update_video_content(void);

static  void    mmi_mscr_prepare_view_content(void);
static  void    mmi_mscr_unprepare_view_content(void);

static  void    mmi_mscr_start_playing(void);
static  void    mmi_mscr_stop_playing(void);
static  void    mmi_mscr_update_playing(void);
static  void    mmi_mscr_update_view_content(U8 is_update_content);
static  void    mmi_mscr_update_ui_status(void);

static  void    mmi_mscr_pause(void);
static  void    mmi_mscr_resume(void);

static  void    mmi_mscr_prepare_full_scr(void);
static  void    mmi_mscr_reprepae_full_scr(void);
static  void    mmi_mscr_unprepare_full_scr(void);
/*
**  define seek related functions
*/
static  void    mmi_mscr_seek_begin(void);
static  void    mmi_mscr_seek_end(U8 is_resume);
static  void    mmi_mscr_seek_update(void);
static  void    mmi_mscr_update_seeking(void);
/*
**  define osd animation related function
*/
static  void    mmi_mscr_prepare_osd_layer(void);
static  void    mmi_mscr_reprepare_osd_layer(void);
static  void    mmi_mscr_reprepare_osd_layer_full_scr(void);
static  void    mmi_mscr_unprepare_osd_layer(void);

static  void    mmi_mscr_start_osd_animation(void);
static  void    mmi_mscr_stop_osd_animation(void);
static  void    mmi_mscr_paint_osd_animation_background(U8 is_clip_text);

static  void    mmi_mscr_draw_osd_ani_before_callback(GDI_RESULT ret);

static  void    mmi_mscr_blt_osd_ani_callback(GDI_RESULT ret);
/*
**  define popup related function
*/
static  MMI_BOOL    mmi_mscr_open_popup(void);
static  void    mmi_mscr_reset_popup(void);
static  void    mmi_mscr_close_popup(void);
static  void    mmi_mscr_paint_popup(void);
static  void    mmi_mscr_popup_timeout(void);
static  void    mmi_mscr_popup_restart_timer(void);

static  void    mmi_mscr_prepare_popup_layer(void);
static  void    mmi_mscr_unprepare_popup_layer(void);
/*
**  define lyrics function
*/
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
static  lyrics_meta_struct*                 g_lyrics    = NULL;
static  mmi_medply_lyrics_box_struct        g_lyrics_box;

static  void    mmi_mscr_prepare_lyrics(void);
static  void    mmi_mscr_unprepare_lyrics(void);
static  void    mmi_mscr_config_lyrics(void);
static  void    mmi_mscr_parse_lyrics(void);
static  void    mmi_mscr_update_lyrics(void);
static  void    mmi_mscr_draw_lyrics(void);

#endif /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/

/*
**  define demo animation function
*/
static  void    mmi_mscr_play_video_demo(void);
static  void    mmi_mscr_stop_video_demo(void);
static  void    mmi_mscr_before_blt_video_demo_callback(GDI_RESULT ret);
#ifdef  MMI_MEDPLY_COMP_USING_PART_BLT
static  void    mmi_mscr_after_blt_video_demo_callback(GDI_RESULT ret);
#endif
static  void    mmi_mscr_draw_video_demo(void);

/*
**  define spectrum function
*/
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
static  void    mmi_mscr_init_spectrum(void);
static  void    mmi_mscr_play_spectrum(void);
static  void    mmi_mscr_stop_spectrum(void);
static  void    mmi_mscr_draw_spectrum_callback(S32 x1, S32 y1, S32 x2, S32 y2);
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

static  void    mmi_mscr_prepare_video(void);
static  void    mmi_mscr_unprepare_video(void);
static  void    mmi_mscr_resize_video_layer(void);
/*
**	define configure function
*/
static  void    mmi_mscr_config_layer_rotate(void);
static  void    mmi_mscr_config_layer_blt(void);
static  void    mmi_mscr_config_backlight(void);
static  void    mmi_mscr_config_button_image(U8 id);

/*
**  define meta function
*/
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
static  void    mmi_mscr_init_meta(void);
static  void    mmi_mscr_prepare_meta(void);
static  void    mmi_mscr_unprepare_meta(void);
static  void    mmi_mscr_draw_meta(void);
static  void    mmi_mscr_draw_meta_scroll_bg(S32 x1, S32 y1, S32 x2, S32 y2);
static  void    mmi_mscr_draw_meta_title_scroll_callback(void);
static  void    mmi_mscr_draw_meta_album_scroll_callback(void);
static  void    mmi_mscr_draw_meta_artist_scroll_callback(void);

static  U8      mmi_mscr_paint_meta_artwork(void);
#endif
/*
**  define draw function
*/
static  void    mmi_mscr_beg_paint(gdi_handle layer_hdl, mmi_medply_rect_struct* rgn_p);
static  void    mmi_mscr_add_paint_rgn(gdi_handle layer_hdl, mmi_medply_rect_struct* rgn_p);
static  void    mmi_mscr_add_paint_rgn_ex(gdi_handle layer_hdl, mmi_medply_rect_struct* rgn_p, 
                                          S16 x_border, S16 y_border);
static  void    mmi_mscr_end_paint(void);

static  void    mmi_mscr_draw_duration(void);
static  void    mmi_mscr_draw_button_id(U8 id);
static  void    mmi_mscr_paint_button_id(U8 id);

static  void    mmi_mscr_draw_title(void);
static  void    mmi_mscr_draw_panel(void);
static  void    mmi_mscr_draw_view(void);
static  void    mmi_mscr_draw_background(void);
static  void    mmi_mscr_paint_region_backgroud(mmi_medply_rect_struct* rgn_p);

static  void    mmi_mscr_paint_duration_bar(void);
static  void    mmi_mscr_paint_ticks(void);

static  void    mmi_mscr_draw_popup_volume(S32 volume, U8 is_hilight);
static  void    mmi_mscr_paint_popup_volume_bar(S32 volume, U8 is_hilight);

static  void    mmi_mscr_paint_popup_userate_bar(S32 volume);

static  void    mmi_mscr_prepare_hilight(U8 button_id);
static  void    mmi_mscr_unprepare_hilight(void);
static  void    mmi_mscr_reset_hilight(void);
static  void    mmi_mscr_backup_hilight(void);
static  void    mmi_mscr_paint_hilight(void); 

static  void    mmi_mscr_paint_scroll(scrolling_text* scroll_p,
                                      U32* flags,
                                      U32 flag_init, 
                                      U32 flag_move, U32 attr_draw);
static  void    mmi_mscr_paint_text(mmi_medply_rect_struct* rgn_p,
                                    mmi_medply_rect_struct* rgn_clip_p,
                                    U16* txt_p, U8 attr_w, U8 attr_h,
                                    U8 use_border, S32 trunc_w);
    /*MACRO FOR DRAW TEXT*/
    #define     MMI_MSCR_TXT_DRAW_ALEFT     0x02
    #define     MMI_MSCR_TXT_DRAW_ARIGHT    0x04
    #define     MMI_MSCR_TXT_DRAW_ATOP      0x02
    #define     MMI_MSCR_TXT_DRAW_ABOTTOM   0x04

static  U8      mmi_mscr_paint_image_mem(mmi_medply_rect_struct* rgn_p, 
                                         U8* img_p, U32 img_size,
                                         U8 img_type, U8 resize_f);

#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)    
static  void   mmi_mscr_draw_icon_bar_callback(void);
#endif

/*
**	define status check function
**	wrap some api for may changed!
*/
static  void        mmi_mscr_enable_backlight(U8 is_enable);
static  U8          mmi_mscr_compare_region(mmi_medply_rect_struct* rgn_1_p, mmi_medply_rect_struct* rgn_2_p);
static  MMI_BOOL    mmi_mscr_is_pt_in_rgn(S16 x, S16 y, mmi_medply_rect_struct* rgn_p);
    /*
    **  define return value
    */
    #define     MMI_MSCR_RGN_2IN1           0x00
    #define     MMI_MSCR_RGN_1IN2           0x01
    #define     MMI_MSCR_RGN_INTERSECT      0x02
    #define     MMI_MSCR_RGN_OUT            0x03
#ifdef __MMI_TOUCH_SCREEN__
static  U8      mmi_mscr_get_pt_range(S16 x, mmi_medply_rect_struct* rgn_p);
#endif /*__MMI_TOUCH_SCREEN__*/
/*
**	define inline static function
**	inline function for wrap ctrl global variable
*/
static  U8      mmi_inline_is_background_call(void);
static  U8      mmi_inline_is_single_play(void);
static  U8		mmi_inline_is_full_screen(void);
static  U8      mmi_inline_is_button_disable(S32 button_id);
static  U8      mmi_inline_is_duration_seek_able(void);
static  U8      mmi_inline_is_stream_url(void);

#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
static  void*	mmi_inline_malloc(kal_uint32 nSize, kal_uint32 user_data);
static  void	mmi_inline_free(void* p, kal_uint32 user_data);
#endif

static  U8      mmi_inline_get_status(void);
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
static  U16*    mmi_inline_get_title_path(U8* data_from);
#endif
static  U64     mmi_inline_get_duration(void);
static  U64     mmi_inline_get_playtime(void);
static  void    mmi_inline_set_playtime(U64 playtime);

static  U32     mmi_inline_get_media_type(void);
static  U32     mmi_inline_get_media_format(void);
static  U8      mmi_inline_get_cache_percent(void);
static  U32     mmi_inline_get_cache_step(void);
static  U32     mmi_inline_get_video_track(void);
static  U8      mmi_inline_is_spectrum_blocked(void);

static  U8      mmi_inline_get_volume_level(void);
static  U8      mmi_inline_is_volume_mute(void);
static  MMI_ID  mmi_inline_get_group_id(void);
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
static  void    mmi_mscr_gesture_prepare(void);
static  void    mmi_mscr_gesture_unprepare(void);
static  void    mmi_mscr_gesture_start(void);
static  void    mmi_mscr_gesture_stop(void);
static  void    mmi_mscr_gesture_move(void);
static  void    mmi_mscr_gesture_get_next_view_content(void);
#endif
#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
static  MMI_BOOL  mmi_inline_is_3d_mode(void);
#endif

#ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
MMI_BOOL        mmi_inline_has_subtitle(void);
static void     mmi_inline_set_subtitle_font_size(U8 font_size);
#endif


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_prepare
* DESCRIPTION
*  Enter new screen, call this function to prepare memory and resource
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PREPARE);

    mmi_mscr_create_handle();
    mmi_mscr_prepare_layer();    
    mmi_mscr_init_ui_status();   
    
    /*
    **  (ONLY ONE TIME)INIT BEGIN
    */
    mmi_mscr_clean_blt_rgn();
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    mmi_mscr_init_meta();
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    mmi_mscr_init_spectrum();
#endif  /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif  /*__MMI_MEDIA_PLAYER_AUDIO__*/  
    
    /*
    **  INIT END   
    */

    /*MAUI_01599613, need check if view content has ready*/
    if ((MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content) &&
        (MMI_MEDPLY_ANI_BT_CONNECTING == g_mscr_hd->id_animation))
    {
        mmi_mscr_update_video_content();
    }
    mmi_mscr_prepare_view_content();

    MMI_MSCR_MSG_TRACE(0);
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_merge_blt_rgn
* DESCRIPTION
*  merge blt region
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_merge_blt_rgn(S16 x, S16 y, S16 w, S16 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S16 x2, y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_MERGE_BLT_RGN, x,y,w,h);
    
    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }
    if (g_blt_rgn.h == 0 || g_blt_rgn.w == 0)
    {
        mmi_medply_main_screen_set_clip_rgn(x, y, w, h);
        return;
    }
    x2 = g_blt_rgn.x + g_blt_rgn.w;
    y2 = g_blt_rgn.y + g_blt_rgn.h;
    
    if (g_blt_rgn.x > x)
    {
        g_blt_rgn.x = x;
    }
    if (g_blt_rgn.y > y)
    {
        g_blt_rgn.y = y;
    }
    if (x2 < x + w)
    {
        x2 = x + w;
    }
    if (y2 < y + h)
    {
        y2 = y + h;
    }  
    g_blt_rgn.w = x2 - g_blt_rgn.x;
    g_blt_rgn.h = y2 - g_blt_rgn.y;
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_create_handle
* DESCRIPTION
*  init handle memory
*   +-----------------+
*   |    ui_handle    | 
*   +-----------------+
*   |    meta info    | <- audio case for example
*   +-----------------+  
*   | Spectrum struct |
*   +-----------------+
*   |    Layer mem    |
*   +-----------------+
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_create_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* mem_p;
    U32 nBasicSize, nVideoSize, nAudioSize, nKuroSize, nMemSize, nTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	nAudioSize	= 0;
    nMemSize	= 0;
	nKuroSize	= 0;
    nBasicSize	= sizeof(mmi_medply_ui_handle_struct);
    nVideoSize	= sizeof(mmi_medply_video_play_para_struct);


#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    nAudioSize = sizeof(mmi_medply_meta_struct);

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    nAudioSize += sizeof(spectrum_struct);
#endif  /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif  /*__MMI_MEDIA_PLAYER_AUDIO__*/
    
    /* find largest context*/
    nMemSize += nAudioSize;
    /* calculate totla context momery size*/
    nMemSize += nBasicSize;
    /* add video context*/
    nMemSize += nVideoSize;
    MMI_ASSERT(MEDPLY_MAIN_SCREEN_HDL_SIZE >= nMemSize);
    mem_p	= mmi_frm_asm_alloc_nc_r(mmi_inline_get_group_id(), MMI_MSCR_LAYER_BUFFER_SIZE * 2);   
    MMI_ASSERT(mem_p != NULL); 
    
    /*allocate momery to context handler*/

	nTemp		= MMI_MEDPLY_HILIGHT_ICON_W*MMI_MEDPLY_HILIGHT_ICON_H*MMI_MSCR_COLOR_DEPTH;
    g_mscr_hd   = (mmi_medply_ui_handle_struct*)mem_p;
	/*
	**	popup screen memory+hilight mem should keep in one screen size
	**	if popup use rgb888 and keep in double buffer; the double buffer size will share with artwork! 
	*/
	g_mscr_hd->mem_hilight		= (U8*)mem_p+nMemSize;
    g_mscr_hd->mem_scr_layer	= (U8*)mem_p+nMemSize+nTemp;		
    g_mscr_hd->mem_artwork		= (U8*)mem_p+nMemSize+MMI_MSCR_LAYER_BUFFER_SIZE;
    
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_mscr_hd->meta_p			= (mmi_medply_meta_struct*)(mem_p+nBasicSize);
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    g_mscr_hd->spectrum_p		= (spectrum_struct*)(mem_p+nBasicSize+sizeof(mmi_medply_meta_struct));
#endif  /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif  /*__MMI_MEDIA_PLAYER_AUDIO__*/    

    g_mscr_hd->video_p  = (mmi_medply_video_play_para_struct*)(mem_p+nBasicSize + nAudioSize + nKuroSize);

    /*init global context*/
    g_mscr_hd->flags            = 0;
    g_mscr_hd->video_flags      = 0;
    g_mscr_hd->hilight_flags    = 0;
    g_mscr_hd->ui_status        = MMI_MEDPLY_STATUS_TOTAL;
    g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;     
    g_mscr_hd->ani_popup_hdl		= GDI_NULL_HANDLE;      
    g_mscr_hd->ani_video_demo_hdl   = GDI_NULL_HANDLE;

    g_mscr_hd->popup_type		= MMI_MSCR_POPUP_TYPE_NONE;

    /*check whether it's in full screen play*/
    if (mmi_inline_is_full_screen())
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_FULL_SCREEN;
    }    
    g_mscr_hd->view_mode        = MMI_MSCR_VIEW_MODE_TOTAL;
	g_mscr_hd->ani_str_id		= 0;
	g_mscr_hd->cachetime		= 0;
	g_mscr_hd->duration			= 0;
	g_mscr_hd->gesture_offset	= 0;
	g_mscr_hd->id_animation		= 0;
	g_mscr_hd->loading_percent	= 0;
	g_mscr_hd->playtime			= 0;
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
	g_mscr_hd->layer_gesture	= GDI_NULL_HANDLE;
#endif
	g_mscr_hd->layer_popup_hdl	= GDI_NULL_HANDLE;
	g_mscr_hd->layer_ani_hdl	= GDI_NULL_HANDLE;
	g_mscr_hd->layer_full_ani_hdl	= GDI_NULL_HANDLE;
    g_mscr_hd->layer_hilight    = GDI_NULL_HANDLE;
    //HAL
    g_mscr_hd->layer_video_hdl = GDI_NULL_HANDLE;
    
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    g_mscr_hd->layer_subtitle_hdl = GDI_NULL_HANDLE;
    #endif
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_delete_handle
* DESCRIPTION
*  release handle memory
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_delete_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*Release full memory*/
    mmi_frm_asm_free_r(mmi_inline_get_group_id(), (void *)g_mscr_hd);
    g_mscr_hd = NULL;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_get_view_content
* DESCRIPTION
*   get view content
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  U8		mmi_mscr_get_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      u8Ret = MMI_MSCR_CONTENT_NULL;
    U8      u8Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_inline_get_media_type())
    {
    case MEDPLY_TYPE_AUDIO:
    case MEDPLY_TYPE_PDL_AUDIO:
        
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_MAINSCR_DISP, 
            (void*)&u8Value);
        
        switch(u8Value)
        {
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        case MMI_MEDPLY_MAINSCR_DISP_SPECTRUM:/*spectrum*/
            
            u8Ret = MMI_MSCR_CONTENT_SPECTRUM;
            break;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
        case MMI_MEDPLY_MAINSCR_DISP_LYRICS:/*lyrics*/
            
            u8Ret = MMI_MSCR_CONTENT_LYRICS;
            break;
#endif /* __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__ */
        case MMI_MEDPLY_MAINSCR_DISP_DETAIL:/*detail*/  
            
            u8Ret = MMI_MSCR_CONTENT_METAINFO;
            break;
        default:
            break;
        }      
        break;
		case MEDPLY_TYPE_VIDEO:
		case MEDPLY_TYPE_PDL_VIDEO:
		case MEDPLY_TYPE_STREAM: 
		case MEDPLY_TYPE_STREAM_RTSP:
		case MEDPLY_TYPE_STREAM_SDP:    
		case MEDPLY_TYPE_STREAM_RAM:    
			
			u8Ret = MMI_MSCR_CONTENT_VIDEO_NULL; 
			break;
		default:
			MMI_MSCR_MSG_TRACE(0);
			if (mmi_medply_plst_is_video_list())
			{
				u8Ret = MMI_MSCR_CONTENT_VIDEO_NULL; 
			}
			break;
    }    
    return  u8Ret;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_view_content
* DESCRIPTION
*   init view content
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static void		mmi_mscr_init_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  view_mode = g_mscr_hd->view_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_mscr_hd->view_content = mmi_mscr_get_view_content();
    g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
	g_mscr_hd->view_mode	= MMI_MSCR_VIEW_MODE_AUDIO; 

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_mscr_hd->meta_p->flags    = 0;
#endif

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_INIT_VIEW_CONTENT, g_mscr_hd->view_content);
	switch(g_mscr_hd->view_content)
    {
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        break;        
#endif   
    case MMI_MSCR_CONTENT_METAINFO:  
		
        g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_VIDEO_DEMO;           
        g_mscr_hd->meta_p->meta_data.artwork.size = MMI_MSCR_ARTWORK_SIZE;
        break;
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:
        
        g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_VIDEO_DEMO;
        break;
#endif
#endif/*#if defined(__MMI_MEDIA_PLAYER_AUDIO__)*/
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_DEMO:    
    case MMI_MSCR_CONTENT_VIDEO_NULL:    
        
		g_mscr_hd->view_mode = MMI_MSCR_VIEW_MODE_VIDEO; 
        break;
    default:

        g_mscr_hd->view_mode = MMI_MSCR_VIEW_MODE_TOTAL; 
        break;
    }     
    if (view_mode != g_mscr_hd->view_mode)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG;
        /*hilight in view region, need clear after view mode changed!*/
        if (g_mscr_hd->layer_hilight == g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW])
        {
            mmi_medply_main_screen_set_and_draw_button((mmi_medply_regn_id_enum)(g_mscr_hd->rgn_push_down_id), 
                MMI_MEDPLY_RGN_STATUS_UP);
        }
    }
    /*do not change view mode after view content first init*/
    return;
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_layer
* DESCRIPTION
*   create media player main screen layer
* PARAMETERS
*   mem_p:
*           
* RETURNS
*  void
 *****************************************************************************/
static  void	mmi_mscr_prepare_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 nMemSize, nLeftSize;
    U8* pLayerMem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_layer_multi_layer_enable();
    gdi_layer_get_base_handle(&g_mscr_hd->layer_base_hdl);

    gdi_layer_push_and_set_active(g_mscr_hd->layer_base_hdl);
    gdi_layer_get_buffer_ptr(&g_mscr_hd->mem_base_layer);
    gdi_layer_pop_and_restore_active();

    gdi_layer_create(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, &g_mscr_hd->layer_full_scr_hdl);
    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    gdi_layer_get_buffer_ptr(&g_mscr_hd->mem_gdi_layer);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_set_source_key(FALSE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);	/*disable transfer color for video player*/
    gdi_layer_pop_and_restore_active();

 
    /*Create OSD Layer use same memory of full screen Layer*/
    pLayerMem = g_mscr_hd->mem_gdi_layer;
    nLeftSize = MMI_MSCR_LAYER_BUFFER_SIZE;

    for (i = 0; i < MMI_MSCR_LAYER_ID_TOTAL; i++)
    {
        nMemSize = g_mscr_ui.layer_rgn[i].w*g_mscr_ui.layer_rgn[i].h*
            MMI_MSCR_COLOR_DEPTH;

        MMI_ASSERT(nLeftSize >= nMemSize);
        
        g_mscr_hd->layer_hdl[i] = mmi_mscr_create_layer(pLayerMem, nMemSize, 
            &g_mscr_ui.layer_rgn[i]);
        
        pLayerMem += nMemSize;
        nLeftSize -= nMemSize;
    } 
    
    //HAL
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        mmi_mscr_prepare_hw_video_layer(MMI_TRUE);
    }
    else
    {
        mmi_mscr_prepare_hw_video_layer(MMI_FALSE);
    }
    
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)    
    g_mscr_hd->layer_prev_icon_bar_hdl = wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR,
        mmi_mscr_draw_icon_bar_callback);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#endif
    /*init lcd rotate*/
    if (gdi_lcd_get_rotate_by_layer())
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_ROTATE_BY_LAYER;
    }

        gdi_lcd_set_rotate_by_layer(TRUE);
     
    /*init rotate before blt*/
    mmi_mscr_config_layer_rotate();
    /*init blt layer before draw image or animation*/
    mmi_mscr_config_layer_blt();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_layer
* DESCRIPTION
*   release media player main screen layer
* PARAMETERS
*   mem_p:
*           
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_unprepare_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //gdi_layer_flatten_previous_to_base();
    gdi_layer_multi_layer_disable();
    
    /*Release gdi layer*/
    for (i = 0; i < MMI_MSCR_LAYER_ID_TOTAL; i++)
    {        
        mmi_mscr_delete_layer(g_mscr_hd->layer_hdl[i]);
    }    

	if (GDI_NULL_HANDLE != g_mscr_hd->layer_full_scr_hdl)
	{
		mmi_mscr_delete_layer(g_mscr_hd->layer_full_scr_hdl);
	}

	if (GDI_NULL_HANDLE != g_mscr_hd->layer_full_ani_hdl)
	{
		mmi_mscr_delete_layer(g_mscr_hd->layer_full_ani_hdl);
	}

	if (GDI_NULL_HANDLE != g_mscr_hd->layer_ani_hdl)
	{
		mmi_mscr_delete_layer(g_mscr_hd->layer_ani_hdl);
	}
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
	if (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture)
	{
		mmi_mscr_delete_layer(g_mscr_hd->layer_gesture);
	}
#endif
	if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
	{
		mmi_mscr_delete_layer(g_mscr_hd->layer_popup_hdl);
	}
    /* HAL */
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_video_hdl)
    {
        mdi_util_hw_layer_free(g_mscr_hd->layer_video_hdl);
        g_mscr_hd->layer_video_hdl = NULL;
    }

    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_subtitle_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
        mdi_util_hw_layer_free(g_mscr_hd->layer_subtitle_hdl);
        g_mscr_hd->layer_subtitle_hdl = NULL;
    }
    #endif

    /* restore rotate layer flag */
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_ROTATE_BY_LAYER)
    {
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {
        gdi_lcd_set_rotate_by_layer(FALSE);
    }    
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_mscr_hd->layer_prev_icon_bar_hdl);
#endif
}


#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_meta
* DESCRIPTION
*   init meta display scroll context
* PARAMETERS
*   void         
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_init_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    S32 layer_x, layer_y;
    stFontAttribute *font;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);  
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_pop_and_restore_active();
    
    /*init title scroll*/
    x = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].x - layer_x);
    y = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].y - layer_y);
    w = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].w);
    h = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].h);
    
    g_mscr_hd->meta_p->meta_data.title[0] = 0;
    
    gui_create_scrolling_text(
        &g_mscr_hd->meta_p->title,
        x, y, w, h,
        g_mscr_hd->meta_p->meta_data.title,
        mmi_mscr_draw_meta_title_scroll_callback,
        mmi_mscr_draw_meta_scroll_bg,
        gui_color(255, 255, 255),
        gui_color(255, 255, 255));
    
    font = gui_font_get_type(GUI_FONT_SIZE_LIST);
    kal_mem_cpy(&g_mscr_hd->meta_p->title.text_font, font, sizeof(stFontAttribute));
    g_mscr_hd->meta_p->title.flags &= ~UI_SCROLLING_TEXT_BORDERED_TEXT;
    
    /*init album scroll*/
    x = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].x - layer_x);
    y = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].y - layer_y);
    w = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].w);
    h = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].h);
    
    g_mscr_hd->meta_p->meta_data.album[0] = 0;
    
    gui_create_scrolling_text(
        &g_mscr_hd->meta_p->album,
        x, y, w, h,
        g_mscr_hd->meta_p->meta_data.album,
        mmi_mscr_draw_meta_album_scroll_callback,
        mmi_mscr_draw_meta_scroll_bg,
        gui_color(255, 255, 255),
        gui_color(255, 255, 255));
    
    kal_mem_cpy(&g_mscr_hd->meta_p->album.text_font, font, sizeof(stFontAttribute));
    g_mscr_hd->meta_p->album.flags &= ~UI_SCROLLING_TEXT_BORDERED_TEXT;
    
    /*init artist scroll*/
    x = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].x - layer_x);
    y = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].y - layer_y);
    w = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].w);
    h = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].h);
    
    g_mscr_hd->meta_p->meta_data.artist[0] = 0;
    
    gui_create_scrolling_text(
        &g_mscr_hd->meta_p->artist,
        x, y, w, h,
        g_mscr_hd->meta_p->meta_data.artist,
        mmi_mscr_draw_meta_artist_scroll_callback,
        mmi_mscr_draw_meta_scroll_bg,
        gui_color(255, 255, 255),
        gui_color(255, 255, 255));
    
    kal_mem_cpy(&g_mscr_hd->meta_p->artist.text_font, font, sizeof(stFontAttribute));
    g_mscr_hd->meta_p->artist.flags &= ~UI_SCROLLING_TEXT_BORDERED_TEXT;
    
    /*init meta content*/
    g_mscr_hd->meta_p->flags = 0;
    g_mscr_hd->meta_p->meta_data.album[0]           = 0;
    g_mscr_hd->meta_p->meta_data.artist[0]          = 0;
    g_mscr_hd->meta_p->meta_data.title[0]           = 0;
    g_mscr_hd->meta_p->meta_data.user_rating        = 0;
    g_mscr_hd->meta_p->meta_data.artwork.mime_type  = META_TAG_IMG_TOTAL;
    g_mscr_hd->meta_p->meta_data.artwork.size       = MMI_MSCR_ARTWORK_SIZE;
    g_mscr_hd->meta_p->meta_data.lyrics.size        = 0;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_meta
* DESCRIPTION
*   prepare meta display information, this may cost long time
* PARAMETERS
*   void         
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_prepare_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nRet;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_READY)
    {
        return;
    }
    g_mscr_hd->meta_p->flags |= MMI_MSCR_META_HAS_READY;
    g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_ARTWORK;

    g_mscr_hd->meta_p->meta_data.album[0]           = 0;
    g_mscr_hd->meta_p->meta_data.artist[0]          = 0;
    g_mscr_hd->meta_p->meta_data.title[0]           = 0;
    g_mscr_hd->meta_p->meta_data.user_rating        = 0;
    g_mscr_hd->meta_p->meta_data.artwork.mime_type  = META_TAG_IMG_TOTAL;
    g_mscr_hd->meta_p->meta_data.artwork.size       = MMI_MSCR_ARTWORK_SIZE;
    g_mscr_hd->meta_p->meta_data.lyrics.size        = 0;

    if (mmi_inline_is_single_play())
    {
        /*
        **   Do not display any meta information in single player
        */
        MMI_MSCR_ERR_TRACE(0);
        return;
    }   
    nRet = mmi_medply_plst_get_current_details(&g_mscr_hd->meta_p->meta_data);
    if (nRet < 0)   /*need change to standart return value*/
    {
        MMI_MSCR_ERR_TRACE(nRet);
        return;
    }
    
    gui_change_scrolling_text(&g_mscr_hd->meta_p->title, 
        (UI_string_type)&g_mscr_hd->meta_p->meta_data.title);
    gui_change_scrolling_text(&g_mscr_hd->meta_p->album, 
        (UI_string_type)&g_mscr_hd->meta_p->meta_data.album);
    gui_change_scrolling_text(&g_mscr_hd->meta_p->artist, 
        (UI_string_type)&g_mscr_hd->meta_p->meta_data.artist);
    
    MMI_MSCR_MSG_TRACE(g_mscr_hd->meta_p->meta_data.artwork.size);
    nRet = mmi_medply_plst_get_current_artwork_ex(g_mscr_hd->mem_artwork,
                            &g_mscr_hd->meta_p->meta_data.artwork.size);
    MMI_MSCR_MSG_TRACE(nRet);
    MMI_MSCR_MSG_TRACE(g_mscr_hd->meta_p->meta_data.artwork.size);

    if (nRet >= 0)
    {
        if (g_mscr_hd->meta_p->meta_data.artwork.size > 0 && 
            g_mscr_hd->meta_p->meta_data.artwork.size <= MMI_MSCR_ARTWORK_SIZE)
        {
            g_mscr_hd->meta_p->flags |= MMI_MSCR_META_HAS_ARTWORK;
            mmi_mscr_draw_background();
        }        
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_meta
* DESCRIPTION
*   un-prepare meta content, stop scroll text
* PARAMETERS
*   void         
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_unprepare_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
    {
        g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_MOVE_TITLE;
        gui_scrolling_text_stop(&g_mscr_hd->meta_p->title);
    }
    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
    {
        g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_MOVE_ALBUM;
        gui_scrolling_text_stop(&g_mscr_hd->meta_p->album);
    }
    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
    {
        g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_MOVE_ARTIST;
        gui_scrolling_text_stop(&g_mscr_hd->meta_p->artist);
    }
    g_mscr_hd->meta_p->flags &= ~(MMI_MSCR_META_HAS_INIT_TITLE|
        MMI_MSCR_META_HAS_INIT_ALBUM|
        MMI_MSCR_META_HAS_INIT_ARTIST);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_meta
* DESCRIPTION
*   draw meta
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_draw_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U32 attr = (MMI_MSCR_TXT_DRAW_ATOP << 8);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_lock_frame_buffer();/*disable gui blt lcd*/

    if (GDI_NULL_HANDLE == g_mscr_hd->layer_gesture)
    {        
        mmi_mscr_beg_paint(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW], 
            &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW]);
    }
    else
    {
        mmi_mscr_beg_paint(g_mscr_hd->layer_gesture, 
            &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW]);
    }       
    
    mmi_mscr_paint_scroll(&g_mscr_hd->meta_p->title, &g_mscr_hd->meta_p->flags,
        MMI_MSCR_META_HAS_INIT_TITLE,
        MMI_MSCR_META_HAS_MOVE_TITLE,
        attr);
    mmi_mscr_paint_scroll(&g_mscr_hd->meta_p->album, &g_mscr_hd->meta_p->flags,
        MMI_MSCR_META_HAS_INIT_ALBUM,
        MMI_MSCR_META_HAS_MOVE_ALBUM,
        attr);
    mmi_mscr_paint_scroll(&g_mscr_hd->meta_p->artist, &g_mscr_hd->meta_p->flags,
        MMI_MSCR_META_HAS_INIT_ARTIST,
        MMI_MSCR_META_HAS_MOVE_ARTIST,
        attr);

    mmi_mscr_paint_button_id(MMI_MEDPLY_RGN_ID_SHUFFLE);
    mmi_mscr_paint_button_id(MMI_MEDPLY_RGN_ID_REPEAT);
    mmi_mscr_paint_button_id(MMI_MEDPLY_RGN_ID_USER_RATING);

    mmi_mscr_end_paint();
    
    gdi_layer_unlock_frame_buffer();
    
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_scroll_bg
* DESCRIPTION
*   Clean scroll background
* PARAMETERS
*   region x y        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_scroll_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct rgn;
    gdi_handle layer;
    S32 layer_x, layer_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
    if ((MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content) &&
        (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture))
    {
        layer = g_mscr_hd->layer_gesture;
    }
    else
#endif
    {
        layer = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW];
    }
    gdi_layer_push_and_set_active(layer);
    gdi_layer_get_position(&layer_x, &layer_y);

    rgn.x = (S16)(x1 + layer_x);
    rgn.y = (S16)(y1 + layer_y);
    rgn.w = (S16)x2 - x1 + 1;/*add 1 for border, x2-x1+1 = W, 239-0+1 = 240*/
    rgn.h = (S16)y2 - y1 + 1;/*add 1 for border*/
    mmi_mscr_paint_region_backgroud(&rgn);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_title_scroll_callback
* DESCRIPTION
*   draw meta title scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_title_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    gui_handle_scrolling_text(&g_mscr_hd->meta_p->title);
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_album_scroll_callback
* DESCRIPTION
*   draw meta album scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_album_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    gui_handle_scrolling_text(&g_mscr_hd->meta_p->album);
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_artist_scroll_callback
* DESCRIPTION
*   draw meta artist scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_artist_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    gui_handle_scrolling_text(&g_mscr_hd->meta_p->artist);
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_meta_artwork
* DESCRIPTION
*   draw artwork
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8    mmi_mscr_paint_meta_artwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_medply_rect_struct  rgn;
    S32         layer_x, layer_y;
    S16         x, y;
    U8          img_draw_f;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    gdi_layer_get_position(&layer_x, &layer_y); 
    
    x = (S16)(g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].x - layer_x);
    y = (S16)(g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].y - layer_y);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x, y, 
        x + g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].w,
        y + g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].h); 
   
    rgn.x = x;
    rgn.y = y;
    rgn.w = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].w;
    rgn.h = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].h;
    
    img_draw_f = mmi_mscr_paint_image_mem(&rgn, 
        g_mscr_hd->mem_artwork, 
        g_mscr_hd->meta_p->meta_data.artwork.size,
        g_mscr_hd->meta_p->meta_data.artwork.mime_type, 1);

    MMI_MSCR_MSG_TRACE(img_draw_f);

    gdi_layer_pop_clip();
    return  img_draw_f;
}
#endif


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_video
* DESCRIPTION
*   init video region
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_prepare_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     resize_w, resize_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {   
        /* HAL */
		if(MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content_fullscr)
		{
        gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
		}
		else
		{
		    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
		}
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);    
        gdi_layer_pop_and_restore_active();
        return;
    }

    /*
    **  handle normal view mode
    */
    /* HAL */
    #ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
    }
    else
    {
       gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    }
    resize_w = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w;
    resize_h = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h;
    
    /*#if defined(MT6253) || defined(MT6253D) || defined(MT6253T)*/
    /*
    *   for YUV422 also need keep video size align to even
    *   remove this compile option check, always keep video size align to even
    */
    /* 
    * MT6253 HW resizer has some limitation, frame buffer size:
    * (1) width % 2 = 0
    * (2) height % 2 = 0
    */ 
    if (resize_w == 1 || resize_h == 1)
    {
        if (1 == resize_w)
        {
            resize_w++;
        }
        if (1 == resize_h)
        {
            resize_h++;
        }
    }
    if (resize_w % 2 != 0)
    {
        /* shrink 1 pixel */
        resize_w --;
        MMI_MSCR_MSG_TRACE(resize_w);
    }
    if (resize_h % 2 != 0)
    {
        /* shirink 1 pixel */
        resize_h --;
        MMI_MSCR_MSG_TRACE(resize_h);
    }
/*#endif*/
    if (resize_w != g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w &&
        resize_h != g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h)
    {
        gdi_layer_resize(resize_w, resize_h);
        g_mscr_hd->video_flags |= MMI_MSCR_HD_VID_HAS_RESIZE_VIEW;  
    }
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);    
    gdi_layer_pop_and_restore_active();  

    /*do set blt layer after video layer resize*/
    if (g_mscr_hd->video_flags & MMI_MSCR_HD_VID_HAS_RESIZE_VIEW)
    {
        mmi_mscr_config_layer_blt();
    }    
    #else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
    }
    else
    {
       gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    }
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);    
    gdi_layer_pop_and_restore_active();
    #endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_video
* DESCRIPTION
*   init video region
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_unprepare_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(g_mscr_hd->video_flags);

    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_DELTETING)
    {
        /*do not clear layer for layer will flatten to base, and 3 layers shared with full screen layer!*/
        MMI_MSCR_MSG_TRACE(0);
        return;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_resize_video_layer
* DESCRIPTION
*  reset video layer for video play
* PARAMETERS
*  void     
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_resize_video_layer(void)
{
#ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     offset_x, offset_y, x, y, video_w, video_h;
    S32     resize_w, resize_h, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    /*To get image fit size and offset*/    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
#if defined(MMI_MEDPLY_COMP_VIDEO_ROTATE)
        /*layer buffer and video display not match*/
        video_w = g_mscr_hd->video_p->video_height;
        video_h = g_mscr_hd->video_p->video_width;
#else
        video_w = g_mscr_hd->video_p->video_width;
        video_h = g_mscr_hd->video_p->video_height;
#endif
        x = 0;
        y = 0;

        layer_w = g_mscr_hd->layer_full_scr_w;
        layer_h = g_mscr_hd->layer_full_scr_h;
    }
    else
    {
        video_w = g_mscr_hd->video_p->video_width;
        video_h = g_mscr_hd->video_p->video_height;

        x = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x;
        y = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y;

        layer_w = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w;
        layer_h = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h;
    }
    MMI_MSCR_MSG_TRACE(layer_w);
    MMI_MSCR_MSG_TRACE(layer_h);
    
    gdi_image_util_fit_bbox(
            ((layer_w > MDI_VDOPLY_MAX_HW_LAYER_SIZE) ? MDI_VDOPLY_MAX_HW_LAYER_SIZE : layer_w),
            ((layer_h > MDI_VDOPLY_MAX_HW_LAYER_SIZE) ? MDI_VDOPLY_MAX_HW_LAYER_SIZE : layer_h),
        video_w, video_h, &offset_x, &offset_y, &resize_w, &resize_h);
        
    MMI_MSCR_MSG_TRACE(resize_w);
    MMI_MSCR_MSG_TRACE(resize_h);

/* #if defined(MT6253) || defined(MT6253D) || defined(MT6253T)*/
    /* 
    * MT6253 HW resizer has some limitation, frame buffer size:
    * (1) width % 2 = 0
    * (2) height % 2 = 0
    */ 
    if (resize_w == 1 || resize_h == 1)
    {
        if (1 == resize_w)
        {
            resize_w++;
            MMI_MSCR_ERR_TRACE(resize_w);
        }
        if (1 == resize_h)
        {
            resize_h++;
            MMI_MSCR_ERR_TRACE(resize_w);
        }
    }
    if (resize_w % 2 != 0)
    {
        /* shrink 1 pixel */
        resize_w --;
    }
    if (resize_h % 2 != 0)
    {
        /* shirink 1 pixel */
        resize_h --;
    }
    /* need re-calculate offset due to w,h coordinate */
    if (layer_w >= resize_w)
    {
        offset_x = (layer_w - resize_w) / 2 ;
        
    }
    if (layer_h >= resize_h)
    {
        offset_y = (layer_h - resize_h) / 2 ;
        
    }
  /*#endif */

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        g_mscr_hd->video_flags |= MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
    }
    else
    {
        g_mscr_hd->video_flags |= MMI_MSCR_HD_VID_HAS_RESIZE_LAYER;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->video_p->layer_hdl);
    gdi_layer_resize(resize_w, resize_h); 
    gdi_layer_set_position(x + offset_x, y + offset_y);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND); 
    gdi_layer_pop_and_restore_active();

    /*do set blt layer after video layer resize*/
    mmi_mscr_config_layer_blt();
#endif
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_ui_status
* DESCRIPTION
*   init view display content, and init timer for moving, init blt layers
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_init_ui_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    **  do this for build cache can't update with play time;
    */
    g_mscr_hd->duration = 0;
    g_mscr_hd->playtime = 0;
    g_mscr_ui.duration_img.md_range = 0;
    g_mscr_ui.duration_img.fg_range = 0;
    
    mmi_medply_get_ui_status(&g_mscr_hd->ui_status, &g_mscr_hd->id_animation); 
    mmi_mscr_init_view_content();

    /*
    **  do this after init meta info for user rate box init;
    */
    mmi_mscr_init_regn_status();
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG)
    {
        /*Can't set status ans animation before main screen has draw out*/
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, g_mscr_hd->id_animation);    
    }
    else
    {
        mmi_mscr_update_duration();    
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_APP_WAITING_PLAY;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_regn_status
* DESCRIPTION
*   init button and image box status
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_init_regn_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
    ** config hide status
    */
    kal_mem_set(g_mscr_hd->rgn_hide_flag, 0, MMI_MSCR_BUTTON_ID_EX_TOTAL);
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(0);

        g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_LKEY]    = 1;
        //g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_ZOOM]    = 1;        
        g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_REPEAT]  = 1;
        g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SHUFFLE] = 1;        
        g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_USER_RATING]     = 1;
    }
    else
    {   /*only hide option for background call*/
        if (mmi_inline_is_background_call())
        {
            MMI_MSCR_MSG_TRACE(1);

            g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_LKEY] = 1;     
        }
    }    

    #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
	    switch(g_mscr_hd->view_content)
        {  
        case MMI_MSCR_CONTENT_LYRICS:
        case MMI_MSCR_CONTENT_SPECTRUM:
        case MMI_MSCR_CONTENT_METAINFO:
        case MMI_MSCR_CONTENT_NULL:   
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
            break;
        case MMI_MSCR_CONTENT_VIDEO:
        case MMI_MSCR_CONTENT_VIDEO_DEMO:
        case MMI_MSCR_CONTENT_VIDEO_NULL:            
		#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 0;
		#else
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
		#endif
			break;
		default:
            break;
        }
    #endif
    
    /*
     * config disable status
     */
    kal_mem_set(g_mscr_hd->rgn_disable_flag, 0, MMI_MSCR_BUTTON_ID_EX_TOTAL);   

    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_CONTROL_BUTTONS))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 1;
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 1;
    #ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 1;
    #endif
    }
    else if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PAUSE))
    {/*pause can be single disable for some audio can't pause*/
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
    }
    //02841731
    else if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PLAY))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
    }

    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_SNAPSHOT))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
    }
    
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_ZOOM))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 1;
    }
    /*
     * config button image
     */
    /*To Init play or pause buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
    /*To Init Repeat Buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_REPEAT);
    /*To Init Shuffle Buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_SHUFFLE);
    /*To Init user rating buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_USER_RATING);   

    
   #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
        mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_MODE);
        if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PLAY_MODE))
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
        } 
   #endif
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_create_layer
* DESCRIPTION
*   create media player main screen layer
* PARAMETERS
*   mem_p:
*           
* RETURNS
*  void
*****************************************************************************/
static  gdi_handle  mmi_mscr_create_layer(U8* mem_p, S32 mem_size, 
                                          mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle gdi_hd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_layer_create_using_outside_memory(
        rgn_p->x, rgn_p->y, rgn_p->w, rgn_p->h,
        &gdi_hd, mem_p, mem_size);
    
    gdi_layer_push_and_set_active(gdi_hd);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);  /*for there has no background layer, so background color changeto black*/
    gdi_layer_set_source_key(FALSE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);  /*disable transfer color for video player*/
    /*gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);*/               /*for we always copy background from background layer, no need to clean layer*/
    gdi_layer_pop_and_restore_active();
    
    return  gdi_hd;
}


//HAL
/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_hw_video_layer
* DESCRIPTION
*   
* PARAMETERS
*   
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_hw_video_layer(MMI_BOOL is_full)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_util_create_hw_layer_extmemory_in_struct    hw_layer_para_in;
    mdi_util_create_hw_layer_out_struct             hw_layer_para_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_video_hdl);
    MMI_MSCR_MSG_TRACE(is_full);
    memset(&hw_layer_para_in, 0, sizeof(mdi_util_create_hw_layer_extmemory_in_struct));
    memset(&hw_layer_para_out, 0, sizeof(mdi_util_create_hw_layer_out_struct));

    //reset flags
    g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
    g_mscr_hd->video_flags &= ~(MMI_MSCR_HD_VID_HAS_RESIZE_VIEW|MMI_MSCR_HD_VID_HAS_RESIZE_LAYER);

    if (GDI_NULL_HANDLE != g_mscr_hd->layer_video_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_video_hdl);
        mdi_util_hw_layer_free(g_mscr_hd->layer_video_hdl);
        g_mscr_hd->layer_video_hdl = GDI_NULL_HANDLE;
    }
    if (is_full)
    {
        //hw_layer_para_in.app_id = 0;
        hw_layer_para_in.buffer = (void*)g_mscr_hd->mem_gdi_layer;
        hw_layer_para_in.buffer_size = MMI_MSCR_LAYER_BUFFER_SIZE;
        hw_layer_para_in.offset_x = 0;
        hw_layer_para_in.offset_y = 0;
        hw_layer_para_in.width = GDI_LCD_HEIGHT;
        hw_layer_para_in.height = GDI_LCD_WIDTH;
        hw_layer_para_in.scenario_id = MDI_MULTIMEDIA_VIDEO;
    }
    else
    {
        //hw_layer_para_in.app_id = 0;
        hw_layer_para_in.buffer = (void*)((gdi_layer_struct*)(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]))->buf_ptr;
        hw_layer_para_in.buffer_size = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w*
                                       g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h*MMI_MSCR_COLOR_DEPTH;
        hw_layer_para_in.offset_x = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x;
        hw_layer_para_in.offset_y = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y;
        hw_layer_para_in.width = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w;
        hw_layer_para_in.height = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h;
        hw_layer_para_in.scenario_id = MDI_MULTIMEDIA_VIDEO;
    }
    g_mscr_hd->layer_video_hdl = mdi_util_hw_layer_create_with_extmemory(&hw_layer_para_in, &hw_layer_para_out);

    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
	gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);
	gdi_layer_pop_and_restore_active();

#ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_subtitle_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
        mdi_util_hw_layer_free(g_mscr_hd->layer_subtitle_hdl);
        g_mscr_hd->layer_subtitle_hdl = GDI_NULL_HANDLE;
    }
    if (is_full)
    {
        hw_layer_para_in.buffer = (void*)g_mscr_hd->mem_artwork;
        hw_layer_para_in.buffer_size = (g_mscr_hd->layer_full_scr_w - 2*MMI_MSCR_SUBTITLE_FONT_SIZE)*
                                       MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER*MMI_MSCR_SUBTITLE_CF_DEEPTH;
        hw_layer_para_in.offset_x = MMI_MSCR_SUBTITLE_FONT_SIZE;
        hw_layer_para_in.offset_y = g_mscr_hd->layer_full_scr_h - MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER - MMI_MSCR_SUBTITLE_HOR_GAP;
        hw_layer_para_in.width = g_mscr_hd->layer_full_scr_w - 2*MMI_MSCR_SUBTITLE_FONT_SIZE;
        hw_layer_para_in.height = MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER;
    }
    else
    {
        //hw_layer_para_in.app_id = 0;
        hw_layer_para_in.buffer = (void*)g_mscr_hd->mem_artwork;
        hw_layer_para_in.buffer_size = g_mscr_ui.subtitle_rgn.w*g_mscr_ui.subtitle_rgn.h*MMI_MSCR_SUBTITLE_CF_DEEPTH;
        hw_layer_para_in.offset_x = g_mscr_ui.subtitle_rgn.x;
        hw_layer_para_in.offset_y = g_mscr_ui.subtitle_rgn.y;
        hw_layer_para_in.width = g_mscr_ui.subtitle_rgn.w;
        hw_layer_para_in.height = g_mscr_ui.subtitle_rgn.h;
    }
    hw_layer_para_in.scenario_id = MDI_MULTIMEDIA_SUBTITLE;
    hw_layer_para_in.color_format = GDI_COLOR_FORMAT_32;
    g_mscr_hd->layer_subtitle_hdl = mdi_util_hw_layer_create_with_extmemory(&hw_layer_para_in, &hw_layer_para_out);

    gdi_layer_push_and_set_active(g_mscr_hd->layer_subtitle_hdl);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    mmi_inline_set_subtitle_font_size(MMI_MSCR_SUBTITLE_FONT_SIZE);
#endif

}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_layer_rotate
* DESCRIPTION
*   config layers rotate
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_config_layer_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  bRotateLayer = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* HAL */
    g_mscr_hd->video_p->idp_rotate			= MDI_VIDEO_LCD_ROTATE_0;
#if (0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        g_mscr_hd->video_p->layer_lcd_rotate	= MDI_VIDEO_LCD_ROTATE_270;
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);	
    }
    else
    { 			
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        g_mscr_hd->video_p->layer_lcd_rotate		= MDI_VIDEO_LCD_ROTATE_0;
    } 
#else /*(0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)*/
    g_mscr_hd->video_p->layer_lcd_rotate			= MDI_VIDEO_LCD_ROTATE_0;
	g_mscr_hd->video_p->idp_rotate					= MDI_VIDEO_LCD_ROTATE_0;
#endif/*(0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)*/

            
    MMI_MSCR_MSG_TRACE(bRotateLayer);    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CONFIG_ROTATE, 
		g_mscr_hd->video_p->layer_lcd_rotate,	g_mscr_hd->video_p->idp_rotate);	
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_layer_blt
* DESCRIPTION
*   config blt to lcd layers
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_config_layer_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle  layer_4 = GDI_NULL_HANDLE;
    /* HAL */
    gdi_handle  tempHdlr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    **  in kuro mode, we use artwork memory to create temp animation layer;
    */
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /* HAL */
        if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content_fullscr)
        {
            tempHdlr = g_mscr_hd->layer_video_hdl;
        }
        else
        {
            tempHdlr = g_mscr_hd->layer_full_scr_hdl;
        }
        #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
        if(MMI_TRUE == mmi_inline_has_subtitle())
        {
            if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
            {           
                gdi_layer_set_blt_layer(tempHdlr, g_mscr_hd->layer_subtitle_hdl, g_mscr_hd->layer_full_ani_hdl, GDI_NULL_HANDLE);            
                g_mscr_hd->video_p->layer_blt_flag  = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
            }
            else
            {                          
                gdi_layer_set_blt_layer(tempHdlr, g_mscr_hd->layer_subtitle_hdl, GDI_NULL_HANDLE, GDI_NULL_HANDLE);            
                g_mscr_hd->video_p->layer_blt_flag  = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
            }
            g_mscr_hd->video_p->layer_subtitle_hdl    = g_mscr_hd->layer_subtitle_hdl;
            g_mscr_hd->video_p->layer_subtitle_flag   = GDI_LAYER_ENABLE_LAYER_1;
        }
        else
        #endif
        {
            if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
            {           
                gdi_layer_set_blt_layer(tempHdlr, g_mscr_hd->layer_full_ani_hdl, GDI_NULL_HANDLE, GDI_NULL_HANDLE);            
                g_mscr_hd->video_p->layer_blt_flag  = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
            }
            else
            {                          
                gdi_layer_set_blt_layer(tempHdlr, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);            
                g_mscr_hd->video_p->layer_blt_flag  = GDI_LAYER_ENABLE_LAYER_0;
            }
        }
        
        g_mscr_hd->video_p->layer_hdl       = g_mscr_hd->layer_video_hdl;
        g_mscr_hd->video_p->layer_play_flag = GDI_LAYER_ENABLE_LAYER_0;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->popup_type);  

        #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
        if(MMI_TRUE == mmi_inline_has_subtitle())
        {
            layer_4 = g_mscr_hd->layer_subtitle_hdl;
            if (GDI_NULL_HANDLE != g_mscr_hd->layer_ani_hdl)
            {
                layer_4 = g_mscr_hd->layer_ani_hdl;
            }
        }
        else
        #endif
        {
            switch (g_mscr_hd->popup_type)
            {
            case    MMI_MSCR_POPUP_TYPE_RATING:
            case    MMI_MSCR_POPUP_TYPE_KURO:
            case    MMI_MSCR_POPUP_TYPE_VOLUME:     
            
                layer_4 = g_mscr_hd->layer_popup_hdl;
                /*break; do not add break here, for the layer4 may not created for aniamtion created first!*/
            default:

                if (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture)
                {
                    layer_4 = g_mscr_hd->layer_gesture;
                }
                else if (GDI_NULL_HANDLE != g_mscr_hd->layer_ani_hdl)
                {
                    layer_4 = g_mscr_hd->layer_ani_hdl;
                }
                break;
            }
        }
        
        MMI_MSCR_MSG_TRACE(layer_4);  
        /*
        **  move view layer up then top, reason is 6236 will support db buffer in hw;
        **  must set hw layer(video layer at top or bottom!)
        */ 
        /* HAL */
        if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content)
        {
            tempHdlr = g_mscr_hd->layer_video_hdl;
        }
        else
        {
            tempHdlr = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW];
        }
        gdi_layer_set_blt_layer(
            tempHdlr,   
            g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP],                      
            g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL],
            layer_4);

        
        g_mscr_hd->video_p->layer_blt_flag = 
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
        if (GDI_NULL_HANDLE != layer_4)
        {
            g_mscr_hd->video_p->layer_blt_flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
        g_mscr_hd->video_p->layer_play_flag = GDI_LAYER_ENABLE_LAYER_0;
        g_mscr_hd->video_p->layer_hdl       = g_mscr_hd->layer_video_hdl;

        #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
        if(layer_4 == g_mscr_hd->layer_subtitle_hdl)
        {
            g_mscr_hd->video_p->layer_subtitle_flag = GDI_LAYER_ENABLE_LAYER_3;
            g_mscr_hd->video_p->layer_subtitle_hdl        = g_mscr_hd->layer_subtitle_hdl;
        }
        #endif
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_backlight
* DESCRIPTION
*   config backlight
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_config_backlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  is_enable = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status))
    {
        switch(g_mscr_hd->view_content)
        {
        case MMI_MSCR_CONTENT_VIDEO:
            
            is_enable = 1;
            break;
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__   
        case MMI_MSCR_CONTENT_LYRICS:
            if (g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY)
            {
                is_enable = 1;
            }
            break;
#endif
            
        default:
            break;
        }
        /*10A No screen saver*/
        /*if (mmi_inline_is_single_play())
        {
            MMI_MSCR_MSG_TRACE(is_enable);
            is_enable = 1;
        }*/
    }
    mmi_mscr_enable_backlight(is_enable);
    MMI_MSCR_MSG_TRACE(is_enable);
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_config_button_image
* DESCRIPTION
*  config button image id
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_config_button_image(U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nRet;
    U8  u8Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MEDPLY_RGN_ID_REPEAT:
        /*Single Player do not support repeater*/
        if (mmi_inline_is_single_play())
        {
            u8Value = MMI_MEDPLY_SETTINGS_REPEAT_OFF;
        }
        else
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT, 
                (void*)&u8Value);
        }        
        if (MMI_MEDPLY_SETTINGS_REPEAT_OFF == u8Value)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.repeat_off_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.repeat_off_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_REPEAT].up_img_id   
                                                = g_medply_fte_skin.repeat_off_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_REPEAT].down_img_id 
                                                = g_medply_fte_skin.repeat_off_img_id;
        }
        else if (MMI_MEDPLY_SETTINGS_REPEAT_ONE == u8Value)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.repeat_one_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.repeat_one_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_REPEAT].up_img_id   
                                                = g_medply_fte_skin.repeat_one_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_REPEAT].down_img_id
                                                = g_medply_fte_skin.repeat_one_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.repeat_all_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.repeat_all_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_REPEAT].up_img_id   
                                                = g_medply_fte_skin.repeat_all_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_REPEAT].down_img_id 
                                                = g_medply_fte_skin.repeat_all_img_id;
        }
    	break;
    case MMI_MEDPLY_RGN_ID_SHUFFLE:

        /*Single Player do not support shuffle*/
        if (mmi_inline_is_single_play())
        {
            u8Value = MMI_MEDPLY_SETTINGS_OFF;
        }
        else
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SHUFFULE, 
                (void*)&u8Value);
        }
        if (MMI_MEDPLY_SETTINGS_OFF == u8Value)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.shuffle_off_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.shuffle_off_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_SHUFFLE].up_img_id   
                                                = g_medply_fte_skin.shuffle_off_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_SHUFFLE].down_img_id 
                                                = g_medply_fte_skin.shuffle_off_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.shuffle_on_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.shuffle_on_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_SHUFFLE].up_img_id   
                                                = g_medply_fte_skin.shuffle_on_img_id;
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_KURO_SHUFFLE].down_img_id 
                                                = g_medply_fte_skin.shuffle_on_img_id;
        }
    	break;
    case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:
        
        nRet = 0;
        if (g_mscr_hd->id_animation != MMI_MEDPLY_ANI_SNAP_SHOT && g_mscr_hd->id_animation != MMI_MEDPLY_ANI_NULL)
        {            
            nRet = 1;      
            if (mmi_inline_is_single_play())
            {
                /*single player when in opening status, not permit to stop*/
                if (MMI_MEDPLY_ANI_VIDEO_OPENING == g_mscr_hd->id_animation)
                {
                    nRet = 0;
                }
            }
        }    
        if ((MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status) || (0 != nRet))
        {
            g_mscr_ui.touch_btn[id].up_img_id       = g_medply_fte_skin.pause_img_id;
            g_mscr_ui.touch_btn[id].down_img_id     = g_medply_fte_skin.pause_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id  = g_medply_fte_skin.pause_disable_img_id;            
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id       = g_medply_fte_skin.play_img_id;
            g_mscr_ui.touch_btn[id].down_img_id     = g_medply_fte_skin.play_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id  = g_medply_fte_skin.play_disable_img_id;
        }
        break;
    case MMI_MEDPLY_RGN_ID_USER_RATING:
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        if(!mmi_inline_is_single_play())
        {
            nRet = mmi_medply_plst_get_current_details(&g_mscr_hd->meta_p->meta_data);
            MMI_MSCR_MSG_TRACE(nRet);
            nRet = g_mscr_hd->meta_p->meta_data.user_rating;
        }
        else
    #endif
        {
            nRet = 0;
        }
        g_mscr_ui.touch_btn[id].up_img_id       = g_medply_fte_skin.rating_btn_img_id + nRet;
        g_mscr_ui.touch_btn[id].down_img_id     = g_mscr_ui.touch_btn[id].up_img_id;
        break;
    case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:

        if (mmi_inline_is_volume_mute())
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.mute_on_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.mute_on_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.mute_off_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.mute_off_img_id;
        }
        break;

    		
    #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
    case MMI_MEDPLY_RGN_ID_MODE:
        if (mmi_inline_is_3d_mode())
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.mode_3d_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.mode_3d_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                                        g_medply_fte_skin.mode_3d_disable_img_id;            
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_fte_skin.mode_2d_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_fte_skin.mode_2d_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                                        g_medply_fte_skin.mode_3d_disable_img_id;
        }
        break;
    #endif
	

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_duration
* DESCRIPTION
*  update duration time and duration image
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mscr_hd->duration = mmi_inline_get_duration();
    
    if (g_mscr_hd->flags & 
        (MMI_MSCR_HD_HAS_SEEKING_WITH_PEN|MMI_MSCR_HD_HAS_SEEKING_WITH_KEY))
    {   /*Do not update playtime in Seek status*/
        return;
    }
    g_mscr_hd->playtime = mmi_inline_get_playtime();
    
    if (g_mscr_hd->duration > 0)
    {
        g_mscr_ui.duration_img.fg_range = 
            (U8)(g_mscr_hd->playtime*100/g_mscr_hd->duration);
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->duration);
        g_mscr_ui.duration_img.fg_range = 0;
    }    
    /*must do get cache after play time updated*/
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();  
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_redraw_button
* DESCRIPTION
*  update duration image 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_update_redraw_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_CONTROL_BUTTONS))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 1;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 1;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    #ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 1;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
    #endif
        
    }
    else if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PAUSE))
    {
        /* only stop enabled*/
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    #ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
    #endif
    }
    else
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 0;
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    #ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
    #endif
    }
    //02841731
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PLAY))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
    }
    
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_ZOOM))
    {
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 1;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_ZOOM);
        }
    }   
    else
    {
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_ZOOM);
        }
    }
    
    #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PLAY_MODE))
    {
        if(0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
            mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_MODE);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_MODE);
        }
    } 
	else
    {
        if(1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE] = 0;
            mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_MODE);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_MODE);
        }
    }
    #endif
    
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_PLAY_PAUSE); 
    mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_update_video_content
* DESCRIPTION
*   update video content before video playing
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_update_video_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 view_content_old = g_mscr_hd->view_content;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UPDATE_VIDEO_CONTENT);
    
    switch(mmi_inline_get_video_track())
    {
    case MDI_VIDEO_TRACK_A_ONLY:
        
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO_DEMO;
        g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
        break;
    case MDI_VIDEO_TRACK_AV:
    case MDI_VIDEO_TRACK_V_ONLY:
        
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO;
        g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
        break;
    default:  
        
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO_NULL;                 
        break;
    }       
    if (view_content_old != g_mscr_hd->view_content)    
    {
        MMI_MSCR_MSG_TRACE(view_content_old);  

        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
            mmi_mscr_reprepae_full_scr();
        }
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
        {
            mmi_mscr_stop_osd_animation();
            if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
            {
                mmi_mscr_reprepare_osd_layer_full_scr();
            }
            mmi_mscr_config_layer_rotate();
            mmi_mscr_start_osd_animation();
        }
        else
        {
            mmi_mscr_config_layer_rotate();
        }  
        /*DB BUFFER MAY SWITCH WITH SINGLE BUFFER*/
        if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
        {
            /* Should not reset popup rather close popup since this
             * is not supported along with subtitles */
        #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
            if(MMI_TRUE == mmi_inline_has_subtitle())
            {
                mmi_mscr_close_popup();
            }
            else
        #endif 
            {
                mmi_mscr_reset_popup();
            }
        }
		mmi_mscr_config_layer_blt();
    }
    MMI_MSCR_MSG_TRACE(g_mscr_hd->view_content);  
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_view_content
* DESCRIPTION
*   init view content
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;

    switch(g_mscr_hd->view_content)
    {
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)    
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_prepare_lyrics();  
        if (!(g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY))
        {
            /*Lyrics Parse failed, change to audio demo mode*/
            g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO_DEMO;
        }
        break;        
#endif   
    case MMI_MSCR_CONTENT_METAINFO:  
                
        mmi_mscr_prepare_meta();
        g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_VIDEO_DEMO;   
        break;
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:
        
        g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_VIDEO_DEMO; 
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_layer_pop_and_restore_active();
        break;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */
    case MMI_MSCR_CONTENT_NULL:

        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_layer_pop_and_restore_active();
        break;
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_NULL:  
        
        mmi_mscr_prepare_video();
        break;
    default:
        break;
    }
    /*
    *   lyrics mode or kuro mode may change to video demo mode
    *   Do init video demo mode in last step.
    */
    if (MMI_MSCR_CONTENT_VIDEO_DEMO == g_mscr_hd->view_content)
    {
        g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;        
        mmi_mscr_prepare_video();
    }    
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_view_content
* DESCRIPTION
*   release view content resource
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_unprepare_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_content = g_mscr_hd->view_content;

    g_mscr_hd->view_content = MMI_MSCR_CONTENT_NULL;
    g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_NULL;

    switch(view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_unprepare_lyrics();          
        break;        
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:
        
        mmi_mscr_stop_spectrum();
        break;
#endif   
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)    
    case MMI_MSCR_CONTENT_METAINFO:  
        
        mmi_mscr_unprepare_meta();
        break;
#endif     
    case MMI_MSCR_CONTENT_VIDEO_DEMO:    
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_NULL:
        
        mmi_mscr_unprepare_video();
        break;    
    default:
        break;
    }    
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_start_playing
* DESCRIPTION
*   begin playing status
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_start_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8  view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }    
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG))
        {
            MMI_MSCR_ERR_TRACE(0);/*change long time to wait main screen draw background first!*/
            gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME, mmi_mscr_start_playing);
            return;
        }
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PLAYING_TIMER;

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL)
    {   /*Do not show playing in pause status*/
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER))
    {
        gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME, mmi_mscr_update_playing);
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER;        
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    else
    {
        view_content = g_mscr_hd->view_content;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_START_PLAYING, view_content);

    switch(view_content)
    { 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:  
        /*start to show spectrum*/
        mmi_mscr_play_spectrum();
        break;
#endif
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        /*start to show video demo ani*/
        mmi_mscr_play_video_demo();
        break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_stop_playing
* DESCRIPTION
*   stop playing status
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_stop_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8  view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER)
    {
        gui_cancel_timer(mmi_mscr_start_playing);
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PLAYING_TIMER;

        MMI_MSCR_ERR_TRACE(0);
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER)
    {
        gui_cancel_timer(mmi_mscr_update_playing);
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER;

        MMI_MSCR_ERR_TRACE(1);
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    else
    {
        view_content = g_mscr_hd->view_content;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_PLAYING, view_content);

    switch(view_content)
    { 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:  
        /*start to show spectrum*/
        mmi_mscr_stop_spectrum();
        break;
#endif
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        /*start to show video demo ani*/
        mmi_mscr_stop_video_demo();
        break;
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_DELTETING))
        {
            mmi_mscr_update_lyrics();    
            mmi_mscr_draw_lyrics();
        }
        break;        
#endif      
        
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_update_playing
* DESCRIPTION
*   update playing status
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_update_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);

    gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME, mmi_mscr_update_playing);
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER;
    mmi_mscr_update_duration();    
    mmi_mscr_update_view_content(1);    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_view_content
* DESCRIPTION
*  show seeking view
* PARAMETERS
*  is_update_content: whether update view        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_update_view_content(U8 is_update_content) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_mscr_draw_duration();

    if (0 != is_update_content)
    {
        switch(g_mscr_hd->view_content)
        {
#if defined(__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__) 
        case MMI_MSCR_CONTENT_LYRICS:

            mmi_mscr_update_lyrics();
            mmi_mscr_draw_lyrics();
        	break;
#endif  /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/ 

        default:

            mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h);
            break;
        }   
    }
    mmi_medply_main_screen_blt();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_update_ui_status
* DESCRIPTION
*   after ctrl status change, use time call update status
* PARAMETERS
*    
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_update_ui_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ui_status, ani_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_STATUS_TIMER;
    
    mmi_medply_get_ui_status(&ui_status, &ani_id);
    mmi_medply_main_screen_set_status_and_ani(ui_status, ani_id);
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE;
        mmi_medply_main_screen_blt();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_pause
* DESCRIPTION
*  pause timer and scroll text for full screen play
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAUSE_ALL;
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        if (MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content)
        {
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
            {
                gui_scrolling_text_stop(&g_mscr_hd->meta_p->title);
                g_mscr_hd->meta_p->title.scroll_x = 0;
            }
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
            {
                gui_scrolling_text_stop(&g_mscr_hd->meta_p->album);
                g_mscr_hd->meta_p->album.scroll_x = 0;
            }
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
            {
                gui_scrolling_text_stop(&g_mscr_hd->meta_p->artist);
                g_mscr_hd->meta_p->artist.scroll_x = 0;
            }
        }
    }
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */
    MMI_MSCR_MSG_TRACE(g_mscr_hd->ui_status);
    
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_stop_playing();
    }  
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_resume
* DESCRIPTION
*  resume timer and scroll text for back from full screen play
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAUSE_ALL;
    
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        if (MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content)
        {
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
            {
                gui_scrolling_text_start(&g_mscr_hd->meta_p->title);
            }
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
            {
                gui_scrolling_text_start(&g_mscr_hd->meta_p->album);
            }
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
            {
                gui_scrolling_text_start(&g_mscr_hd->meta_p->artist);
            }
        }
    }
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */

    MMI_MSCR_MSG_TRACE(g_mscr_hd->ui_status);
    
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER))
        {
            gui_start_timer(MMI_MSCR_UI_START_PLAY_TIME, mmi_mscr_start_playing);
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAYING_TIMER;
        }
    } 
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_start_osd_animation
* DESCRIPTION
*   start osd animation
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_start_osd_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_START_OSD_ANI, g_mscr_hd->popup_type);    

    /*in gesture status, not show osd and popup*/
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->layer_gesture);
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_OSD_WAITING_START;
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_IS_OSD_WAITING_START;
       
    /*before show any animation, close popup screen first*/
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)  
    {
        mmi_mscr_close_popup();
    }
    mmi_mscr_stop_osd_animation();
    mmi_mscr_prepare_osd_layer();     
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl);
    }
    else
    {                
        gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl);
    }   
    /*Draw Animation Background Image*/
    gdi_anim_set_draw_before_callback(mmi_mscr_draw_osd_ani_before_callback);

    gdi_anim_set_blt_before_callback(mmi_mscr_blt_osd_ani_callback);
    
    x = g_medply_fte_skin.wait_ani_fg_x - g_medply_fte_skin.wait_ani_bg_x;
    y = g_medply_fte_skin.wait_ani_fg_y - g_medply_fte_skin.wait_ani_bg_y;
    
    gdi_image_draw_animation_id(x, y, g_medply_fte_skin.wait_ani_fg_id, &g_mscr_hd->ani_popup_hdl);
    gdi_layer_pop_and_restore_active();    
    

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl);
    }
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_stop_osd_animation
* DESCRIPTION
*   stop osd animation
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_stop_osd_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x,y,w,h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_OSD_ANI, g_mscr_hd->popup_type);

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl);
        }
        else
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl);
        }
        gdi_layer_get_position(&x, &y);
        gdi_layer_get_dimension(&w, &h);
        gdi_layer_pop_and_restore_active();  
        mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    }
    
    mmi_mscr_unprepare_osd_layer();

    if (GDI_NULL_HANDLE != g_mscr_hd->ani_popup_hdl)
    {
        if (GDI_ERROR_HANDLE != g_mscr_hd->ani_popup_hdl)
        {
            gdi_image_stop_animation(g_mscr_hd->ani_popup_hdl);
        }
        g_mscr_hd->ani_popup_hdl = GDI_NULL_HANDLE;      
    }   
    g_mscr_hd->flags &= ~MMI_MSCR_HD_IS_OSD_WAITING_START;
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_paint_osd_animation_background
* DESCRIPTION
*   paint osd animation background
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_paint_osd_animation_background(U8 is_clip_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct  rgn;
    U16 *pop_str_p;
    U16 pop_str[32];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    rgn.x = g_medply_fte_skin.popup_txt_rgn_x - g_medply_fte_skin.wait_ani_bg_x;
    rgn.y = g_medply_fte_skin.popup_txt_rgn_y - g_medply_fte_skin.wait_ani_bg_y;
    rgn.w = g_medply_fte_skin.popup_txt_rgn_w;
    rgn.h = g_medply_fte_skin.popup_txt_rgn_h;
    
    if (0 != is_clip_text)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(rgn.x, rgn.y, rgn.x+rgn.w, rgn.y+rgn.h);
    }
    gdi_image_draw_id(0, 0, g_medply_fte_skin.wait_img_bg_id);
    if (0 != is_clip_text)
    {
        gdi_layer_pop_clip();
    }
    
    if (MMI_MEDPLY_ANI_LOADING != g_mscr_hd->id_animation)
    {
        pop_str_p = (U16*)GetString(g_mscr_hd->ani_str_id);
    }
    else if (MMI_MEDPLY_ANI_LOADING == g_mscr_hd->id_animation)
    {
        kal_wsprintf((WCHAR*)pop_str, "%w: %d%w", 
            GetString(g_mscr_hd->ani_str_id), g_mscr_hd->loading_percent, L"%"); 
        pop_str_p = pop_str;
    }
    else
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->id_animation);
    }   
    
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST)); 
    gui_set_text_color(MMI_MSCR_COLOR_WHITE);     
    mmi_mscr_paint_text(&rgn, &rgn, pop_str_p, 0, 0, 0, g_medply_fte_skin.popup_txt_rgn_w);
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_osd_ani_before_callback
* DESCRIPTION
*   draw fulls screen animation callback, special function for MT6238 series 
* PARAMETERS
*   ret:    [IN]   animation result    
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_draw_osd_ani_before_callback(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI)
    {
        MMI_MSCR_MSG_TRACE(ret);
        return;
    }
    if (GDI_SUCCEED != ret)
    {
        MMI_MSCR_ERR_TRACE(ret);
        return;
    }

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl);
        }
    else
    {        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl);
    }
    mmi_mscr_paint_osd_animation_background(0);
    
    gdi_layer_pop_and_restore_active();

    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_blt_ani_callback
* DESCRIPTION
*   process before animation paint to lcd
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_blt_osd_ani_callback(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_ANI_CB, ret);
    
    if (NULL == g_mscr_hd)
    {
        /*Add Log for this is callback function, can't ctrl by module itself*/
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER))
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }    
    if (GDI_SUCCEED != ret)
    {
        MMI_MSCR_ERR_TRACE(ret);
        return;
    }
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl);
    }
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    mmi_medply_main_screen_blt();
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_osd_layer
* DESCRIPTION
*   prepare osd animation layers
* PARAMETERS
*   popup_type: animation popup type         
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_prepare_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color_format color_fmt;
    S32 size;
    U8* mem_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (1 == MMI_MEDPLY_COMP_USING_RGB888_LAYER)
    color_fmt = GDI_COLOR_FORMAT_32;
    size = g_medply_fte_skin.wait_ani_bg_w * g_medply_fte_skin.wait_ani_bg_h * 4;
#else
    color_fmt = GDI_COLOR_FORMAT_16;
    size = g_medply_fte_skin.wait_ani_bg_w * g_medply_fte_skin.wait_ani_bg_h * 2;
#endif 
   
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_ani_hdl) 
    {
        gdi_layer_create_cf_using_outside_memory(
            color_fmt,
            g_medply_fte_skin.wait_ani_bg_x, g_medply_fte_skin.wait_ani_bg_y, 
            g_medply_fte_skin.wait_ani_bg_w, g_medply_fte_skin.wait_ani_bg_h,
            &g_mscr_hd->layer_ani_hdl, g_mscr_hd->mem_scr_layer, size);
        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active(); 
        
    }

    if (GDI_NULL_HANDLE == g_mscr_hd->layer_full_ani_hdl)
    {
        S32 x, y, w, h;

#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER) /*landscape*/
        x = (GDI_LCD_WIDTH  - g_medply_fte_skin.wait_ani_bg_w)/2;
        y = (GDI_LCD_HEIGHT - g_medply_fte_skin.wait_ani_bg_h)/2;
        w = g_medply_fte_skin.wait_ani_bg_w;
        h = g_medply_fte_skin.wait_ani_bg_h; 

        mem_p = g_mscr_hd->mem_scr_layer;
#else
        {
            x = (GDI_LCD_HEIGHT - g_medply_fte_skin.wait_ani_bg_w)/2;
            y = (GDI_LCD_WIDTH  - g_medply_fte_skin.wait_ani_bg_h)/2;
            w = g_medply_fte_skin.wait_ani_bg_w;
            h = g_medply_fte_skin.wait_ani_bg_h;

            mem_p = g_mscr_hd->mem_scr_layer;
        }
#endif/*(0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)*/
        gdi_layer_create_cf_using_outside_memory(
            color_fmt, x, y, w, h,
            &g_mscr_hd->layer_full_ani_hdl,
            mem_p, size);
        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active(); 
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_LAYER;    
    mmi_mscr_config_layer_blt();
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_reprepare_osd_layer_full_scr
* DESCRIPTION
*   reprepare full screen osd animation layers
* PARAMETERS
*   popup_type: animation popup type         
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_reprepare_osd_layer_full_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color_format color_fmt;
    S32 x, y, w, h;
    S32 size;
    U8* mem_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (1 == MMI_MEDPLY_COMP_USING_RGB888_LAYER)
    color_fmt = GDI_COLOR_FORMAT_32;
    size = g_medply_fte_skin.wait_ani_bg_w * g_medply_fte_skin.wait_ani_bg_h * 4;
#else
    color_fmt = GDI_COLOR_FORMAT_16;
    size = g_medply_fte_skin.wait_ani_bg_w * g_medply_fte_skin.wait_ani_bg_h * 2;
#endif    
    

    if (GDI_NULL_HANDLE != g_mscr_hd->layer_full_ani_hdl)
    {
        mmi_mscr_delete_layer(g_mscr_hd->layer_full_ani_hdl);
    }        
       
#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER) 
    x = (GDI_LCD_WIDTH  - g_medply_fte_skin.wait_ani_bg_w)/2;
    y = (GDI_LCD_HEIGHT - g_medply_fte_skin.wait_ani_bg_h)/2;
    w = g_medply_fte_skin.wait_ani_bg_w;
    h = g_medply_fte_skin.wait_ani_bg_h; 
    
    mem_p = g_mscr_hd->mem_scr_layer;
#else
    {
        x = (GDI_LCD_HEIGHT - g_medply_fte_skin.wait_ani_bg_w)/2;
        y = (GDI_LCD_WIDTH  - g_medply_fte_skin.wait_ani_bg_h)/2;
        w = g_medply_fte_skin.wait_ani_bg_w;
        h = g_medply_fte_skin.wait_ani_bg_h;
        
        mem_p = g_mscr_hd->mem_scr_layer;
    }
#endif/*#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)*/
    gdi_layer_create_cf_using_outside_memory(
        color_fmt, x, y, w, h,
        &g_mscr_hd->layer_full_ani_hdl,
        mem_p, size);
    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl); 
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active(); 
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_reprepare_osd_layer
* DESCRIPTION
*   reprepare osd animation layers
* PARAMETERS
*   popup_type: animation popup type         
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_reprepare_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        if (GDI_NULL_HANDLE != g_mscr_hd->layer_full_ani_hdl)
        { 
                g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI;
            gdi_layer_push_and_set_active(g_mscr_hd->layer_full_ani_hdl); 
            gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();            

        }
    }
    else
    {
        if (GDI_NULL_HANDLE != g_mscr_hd->layer_ani_hdl) 
        {            
                gdi_layer_push_and_set_active(g_mscr_hd->layer_ani_hdl); 
                gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active(); 

                g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI;
            }
    }
    mmi_mscr_config_layer_blt();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_osd_layer
* DESCRIPTION
*   unprepare osd animation layers
* PARAMETERS
*   void         
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_unprepare_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_OSD_LAYER;

    if (GDI_NULL_HANDLE != g_mscr_hd->layer_ani_hdl)
    {
        mmi_mscr_delete_layer(g_mscr_hd->layer_ani_hdl);
        g_mscr_hd->layer_ani_hdl = GDI_NULL_HANDLE;
    }
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_full_ani_hdl)
    {
        mmi_mscr_delete_layer(g_mscr_hd->layer_full_ani_hdl);
        g_mscr_hd->layer_full_ani_hdl = GDI_NULL_HANDLE;
    }
    mmi_mscr_config_layer_blt();
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_open_popup
* DESCRIPTION
*   show popup screen in main screen
* PARAMETERS
*   void       
* RETURNS
*  void
*****************************************************************************/
static  MMI_BOOL    mmi_mscr_open_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     layer_x, layer_y, layer_w, layer_h;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return  MMI_FALSE;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return  MMI_FALSE;
    }    

    if (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return  MMI_FALSE;
    }

    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_popup_hdl);
        mmi_mscr_close_popup();
    }
    mmi_mscr_prepare_popup_layer();

    gdi_layer_push_and_set_active(g_mscr_hd->layer_popup_hdl); 
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    
    mmi_mscr_paint_popup();
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_POPUP_DB_BUFFER)
    {
        gdi_layer_toggle_double();
        mmi_mscr_paint_popup();
    }
#endif
    gdi_layer_pop_and_restore_active();

    g_mscr_hd->rgn_popup.x = (S16)layer_x;
    g_mscr_hd->rgn_popup.y = (S16)layer_y;
    g_mscr_hd->rgn_popup.w = (S16)layer_w;
    g_mscr_hd->rgn_popup.h = (S16)layer_h;

    mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, (S16)layer_w, (S16)layer_h);
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_POPUP_TIMER)
    {
        gui_cancel_timer(mmi_mscr_popup_timeout);
    }
    else
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_POPUP_TIMER;
    }
    gui_start_timer(MMI_MSCR_UI_POPUP_FADEOUT_TIME, mmi_mscr_popup_timeout);

    return  MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_reset_popup
* DESCRIPTION
*   re-created popup screen in main screen
* PARAMETERS
*   void       
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_reset_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_mscr_unprepare_popup_layer();
    mmi_mscr_prepare_popup_layer();
    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_popup_hdl); 
    
    mmi_mscr_paint_popup();
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_POPUP_DB_BUFFER)
    {
        gdi_layer_toggle_double();
        mmi_mscr_paint_popup();
    }
#endif
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn(g_mscr_hd->rgn_popup.x, g_mscr_hd->rgn_popup.y, 
        g_mscr_hd->rgn_popup.w, g_mscr_hd->rgn_popup.h);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_paint_popup
* DESCRIPTION
*   paint popup screen in main screen
* PARAMETERS
*   void       
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_paint_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 volume;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mscr_hd->popup_type)
    {
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    case MMI_MSCR_POPUP_TYPE_RATING:
        
        gdi_image_draw_id(0, 0, g_mscr_ui.rating_img.bg_img_id);
        
        g_mscr_ui.rating_img.temp_val = g_mscr_hd->meta_p->meta_data.user_rating;
        mmi_mscr_paint_popup_userate_bar(g_mscr_hd->meta_p->meta_data.user_rating);
        break;
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */
    case MMI_MSCR_POPUP_TYPE_VOLUME:
        
        gdi_image_draw_id(0, 0, g_mscr_ui.volume_img.bg_img_id);
        
        volume = mmi_inline_get_volume_level();     
        mmi_mscr_paint_popup_volume_bar(volume, 0);
        mmi_mscr_paint_button_id(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);    
        break;
        
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_close_popup
* DESCRIPTION
*   close popup screen in main screen
* PARAMETERS
*   void       
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_close_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_popup_hdl);

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_POPUP_TIMER)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_POPUP_TIMER;
        gui_cancel_timer(mmi_mscr_popup_timeout);
    }
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_popup_hdl)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_DELTETING))
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_popup_hdl); 
        gdi_layer_get_position(&layer_x, &layer_y);
        gdi_layer_get_dimension(&layer_w, &layer_h);
        gdi_layer_pop_and_restore_active();

        mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, (S16)layer_w, (S16)layer_h);
    }
    mmi_mscr_unprepare_popup_layer();    

    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_DELTETING))
    {
        if (MMI_MSCR_POPUP_TYPE_RATING == g_mscr_hd->popup_type)
        {
            mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_USER_RATING);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_USER_RATING);
        }
    }   
    g_mscr_hd->popup_type = MMI_MSCR_POPUP_TYPE_NONE; 

    /*clean popup hilight item, when popup closed*/
    if (g_mscr_hd->rgn_push_down_id >= MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL && 
        g_mscr_hd->rgn_push_down_id <= MMI_MEDPLY_RGN_ID_VOLUME_SPEAK)
    {
        g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;
    }
    
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_DELTETING))
    {
        mmi_medply_back_to_normal_screen();
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_popup_timeout
* DESCRIPTION
*   close popup screen in main screen
* PARAMETERS
*   void       
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_popup_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(g_mscr_hd);
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_POPUP_TIMER)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_POPUP_TIMER;
        gui_cancel_timer(mmi_mscr_popup_timeout);
    }
    mmi_mscr_close_popup();
    mmi_medply_main_screen_blt();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_popup_restart_timer
* DESCRIPTION
*  
* PARAMETERS
*  volume:       
* RETURNS
*  layer handle
 *****************************************************************************/
static  void    mmi_mscr_popup_restart_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_POPUP_TIMER)
    {
        gui_cancel_timer(mmi_mscr_popup_timeout);
        gui_start_timer(MMI_MSCR_UI_POPUP_FADEOUT_TIME, mmi_mscr_popup_timeout);
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_popup_layer
* DESCRIPTION
*   prepare popup layers
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_prepare_popup_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color_format color_fmt;
    S32 x = 0, y = 0, w = 0, h = 0, size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mscr_hd->popup_type)
    {
    case MMI_MSCR_POPUP_TYPE_RATING:

        x = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].x;
        y = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].y;
        w = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].w;
        h = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].h;
    	break;
    case MMI_MSCR_POPUP_TYPE_KURO:

        x = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_KURO].x;
        y = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_KURO].y;
        w = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_KURO].w;
        h = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_KURO].h;
    	break;
    case MMI_MSCR_POPUP_TYPE_VOLUME:

        x = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].x;
        y = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].y;
        w = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].w;
        h = g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].h;
        break;
    default:

        MMI_MSCR_MSG_TRACE(g_mscr_hd->popup_type);
        ASSERT(0);
        break;
    }
    if (0 != w % 2)
    {
        w++;
    }
    if (0 != h % 2)
    {
        h++;
    }
#if (1 == MMI_MEDPLY_COMP_USING_RGB888_LAYER)
    color_fmt = GDI_COLOR_FORMAT_32;
    size = w * h * 4;
#else
    color_fmt = GDI_COLOR_FORMAT_16;
    size = w * h * 2;
#endif
    
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->popup_type);
        ASSERT(g_mscr_hd->popup_type == MMI_MSCR_POPUP_TYPE_VOLUME); 

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
        gdi_layer_blt_with_double_buffer_enable();
        /* 
                  * work around for gdi.
                  * In order to resolve tearing of osd layer, should tell gdi which layer is used as hw layer
                  * only apply on 6252.
                  */
        //gdi_layer_set_hw_update_layer(g_mscr_hd->layer_video_hdl);
        gdi_layer_create_cf_using_outside_memory(
            color_fmt,
            x, y, w, h,
            &g_mscr_hd->layer_popup_hdl,
            g_mscr_hd->mem_scr_layer,   
            (S32)size);
#else
        gdi_layer_create_cf_double_using_outside_memory(
            color_fmt,
            x, y, w, h,
            &g_mscr_hd->layer_popup_hdl,
            g_mscr_hd->mem_scr_layer,                   /* based memory*/
            size,
            g_mscr_hd->mem_scr_layer + size,            /*gdi screen memory*/
            size);  
#endif
        
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_POPUP_DB_BUFFER;
    }
    else
    {
        gdi_layer_create_cf_using_outside_memory(
            color_fmt, x, y, w, h,
            &g_mscr_hd->layer_popup_hdl, g_mscr_hd->mem_scr_layer, size);        
    }    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_popup_hdl);     
    gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_POPUP_DB_BUFFER)
    {
        gdi_layer_toggle_double();
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    }
#endif
    gdi_layer_pop_and_restore_active(); 
    
    mmi_mscr_config_layer_blt();
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_osd_layer
* DESCRIPTION
*   unprepare osd animation layers
* PARAMETERS
*   void         
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_unprepare_popup_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {
        mmi_mscr_delete_layer(g_mscr_hd->layer_popup_hdl);
        g_mscr_hd->layer_popup_hdl = GDI_NULL_HANDLE;
    }
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_POPUP_DB_BUFFER)
    {
        gdi_layer_blt_with_double_buffer_disable();        
    }   
#endif
    g_mscr_hd->flags &= ~MMI_MSCR_HD_IS_POPUP_DB_BUFFER;
    mmi_mscr_config_layer_blt();
}


#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_lyrics
* DESCRIPTION
*   prepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_prepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 font_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_lyrics_box.time_out   = 0;
    g_lyrics_box.last_time  = (U16)(g_mscr_hd->playtime/MMI_MSCR_UI_UPDATE_PLAY_TIME);
       
    if (NULL == g_lyrics)
    {
        gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST)); 
        font_h = gui_get_character_height();
        /*check normal screen lyrics region is ok*/
        if ((g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].h < (font_h + 2)) || 
            (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].w <= 4*font_h))
        {
            return;
        }
        g_lyrics_box.font_height    = font_h; 
        
        g_lyrics = lyrics_parse_create(MMI_MSCR_UI_UPDATE_PLAY_TIME,/*lyrics update ms*/
            mmi_inline_malloc, mmi_inline_free, 0); 
    }    
    if ((NULL != g_lyrics) && !(g_mscr_flag & MMI_MSCR_UI_HAS_PARSE_LYRICS))
    {
        mmi_mscr_parse_lyrics();
        if (g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY)
        {
            mmi_mscr_config_lyrics();
            mmi_mscr_update_lyrics();
        }
        else
        {
            mmi_mscr_unprepare_lyrics();
        }
    } 
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_lyrics
* DESCRIPTION
*   unprepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_unprepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (NULL != g_lyrics)
    {     
        lyrics_parse_release();
        g_lyrics = NULL;
    }
    g_mscr_flag &= ~(MMI_MSCR_UI_HAS_PARSE_LYRICS|MMI_MSCR_UI_IS_LYRICS_READY);    
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_lyrics
* DESCRIPTION
*   configure lyrics display region 
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_config_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!(g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY))
    {
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    }    
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_pop_and_restore_active();
    
    g_lyrics_box.line_count     = 
        (U8)((layer_h - MMI_MSCR_LYRICS_BORDER_Y) / (g_lyrics_box.font_height+MMI_MSCR_LYRICS_GAP_H));    
    if (g_lyrics_box.line_count > MMI_MSCR_LYRICS_MAX_LINE)
    {
        g_lyrics_box.line_count = MMI_MSCR_LYRICS_MAX_LINE;
    }
    g_lyrics_box.line_focus     = g_lyrics_box.line_count/2;
    g_lyrics_box.line_focus_id  = LYRICS_MAX_LINES; 
    g_lyrics_box.line_height    = layer_h/g_lyrics_box.line_count;
    
    g_lyrics_box.rgn_txt.x = layer_x;
    g_lyrics_box.rgn_txt.y = layer_y + MMI_MSCR_LYRICS_BORDER_Y;
    g_lyrics_box.rgn_txt.w = layer_w;
    g_lyrics_box.rgn_txt.h = g_lyrics_box.line_height*g_lyrics_box.line_count;
    g_lyrics_box.rgn_txt.y = g_lyrics_box.rgn_txt.y + 
        (layer_h - g_lyrics_box.rgn_txt.h) / 2;
    
    lyrics_unformat_line(g_lyrics);
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST)); 
    /*must do set font before format line*/
    lyrics_format_line(g_lyrics, g_lyrics_box.rgn_txt.w,
        (U32)g_mscr_hd->duration, gui_get_string_width_n); 
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_parse_lyrics
* DESCRIPTION
*  parse lyrics
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_parse_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16*    media_file_path;
    U16*    meta_title = NULL;
    U16     lyric_file_path[MMI_MSCR_FILE_PATH_LEN];
    S32     nRet;
    U16     lyric_err_str_id;
    U8      lyric_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    media_file_path = mmi_inline_get_title_path(&g_mscr_hd->data_from);
    if (MMI_MSCR_DATA_FROM_FILE != g_mscr_hd->data_from)
    {
        return;
    }
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    if(!mmi_inline_is_single_play())
    {
        nRet = mmi_medply_plst_get_current_details(&g_mscr_hd->meta_p->meta_data);
        if (MEDPLY_PLST_NO_ERROR == nRet)
        {
            meta_title = g_mscr_hd->meta_p->meta_data.title;
        }
    }
#endif
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
        case LYRICS_ERR_INVAILD_DATA:
            
            lyric_err_str_id = STR_ID_MEDPLY_MSCR_ERR_DATA_LYRICS_FILE;
            break;
        case LYRICS_ERR_OPEN_FILE_FAILED:
            
            lyric_err_str_id = STR_ID_MEDPLY_MSCR_ERR_OPEN_LYRICS_FILE;
            break;
        default:
            
            lyric_err_str_id = STR_ID_MEDPLY_MSCR_NO_LYRICS_FILE;
            break;
        }
        lyrics_set_err_text(g_lyrics, (kal_uint16*)GetString(lyric_err_str_id));
    }
    else
    {
        g_mscr_flag |= MMI_MSCR_UI_IS_LYRICS_READY;
    }
    g_mscr_flag |= MMI_MSCR_UI_HAS_PARSE_LYRICS; 
    g_lyrics_box.line_focus_id = LYRICS_MAX_LINES;  
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_lyrics
* DESCRIPTION
*  update lyrics display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_update_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 lineID, nextID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == g_lyrics)
    {
        /*screen may delete by delete call back function*/
        return;
    }
    g_lyrics_box.last_time = (U16)(g_mscr_hd->playtime/MMI_MSCR_UI_UPDATE_PLAY_TIME);

    lineID = lyrics_get_line(g_lyrics, g_lyrics_box.last_time);
    if (lineID == g_lyrics_box.line_focus_id)
    {
        if (g_lyrics_box.last_time > g_lyrics->lines_p[lineID].id_time)
        {
            g_lyrics_box.time_out = 
                (U16)(g_lyrics_box.last_time - g_lyrics->lines_p[lineID].id_time);
        }
        else
        {
            g_lyrics_box.time_out = 0;
        }
        return;
    }
    
    if (lineID < LYRICS_MAX_LINES)
    {
        nextID = g_lyrics->lines_p[lineID].id_next;
    }
    else
    {
        nextID = LYRICS_MAX_LINES;
    }
    if (nextID < LYRICS_MAX_LINES)
    {
        g_lyrics_box.next_time = g_lyrics->lines_p[nextID].id_time;
    }
    else
    {
        g_lyrics_box.next_time = 
            (U32)(g_mscr_hd->duration/MMI_MSCR_UI_UPDATE_PLAY_TIME);
    }
    g_lyrics_box.curr_time      = g_lyrics->lines_p[lineID].id_time;
    g_lyrics_box.line_focus_id  = lineID;

    if (g_lyrics_box.last_time > g_lyrics->lines_p[lineID].id_time)
    {
        g_lyrics_box.time_out   = 
            (U16)(g_lyrics_box.last_time - g_lyrics->lines_p[lineID].id_time);
    }
    else
    {
        g_lyrics_box.time_out   = 0;
    }
    
    g_lyrics_box.line_id[g_lyrics_box.line_focus] = g_lyrics_box.line_focus_id;
    lineID = g_lyrics_box.line_focus_id;
    
    for (i = g_lyrics_box.line_focus-1; i >= 0; i--)
    {
        if (lineID < LYRICS_MAX_LINES)
        {
            g_lyrics_box.line_id[i] = g_lyrics->lines_p[lineID].id_prev;
            lineID = g_lyrics_box.line_id[i];
        }
        else
        {
            g_lyrics_box.line_id[i] = LYRICS_MAX_LINES;
        }
    }
    lineID = g_lyrics_box.line_focus_id;
    for (i = g_lyrics_box.line_focus+1; i <= g_lyrics_box.line_count; i++)
    {   
        if (lineID < LYRICS_MAX_LINES)
        {
            g_lyrics_box.line_id[i] = g_lyrics->lines_p[lineID].id_next;
            lineID = g_lyrics_box.line_id[i];
        }
        else
        {
            g_lyrics_box.line_id[i] = LYRICS_MAX_LINES;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_lyrics
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     layer_x, layer_y, layer_w, layer_h;
    S16     x, y, h, yOff, yBeg;
    U16     *pStr, u16Tmp, nLen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if ((NULL == g_lyrics) || !(g_mscr_flag & MMI_MSCR_UI_HAS_PARSE_LYRICS) )
    {
        MMI_MSCR_ERR_TRACE(g_lyrics);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*in full screen, use video layer to draw lyrics text*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
        gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        if (GDI_NULL_HANDLE == g_mscr_hd->layer_gesture)
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);            
            /*Vector font need set alpha blending layer*/
            gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
        }
        else
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_gesture);
            /*Vector font need set alpha blending layer*/
            gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_gesture);
        }       
    }    
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);    
    gdi_layer_get_position(&layer_x, &layer_y);  
    gdi_layer_get_dimension(&layer_w, &layer_h);
    mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, (S16)layer_w, (S16)layer_h);

    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST));
    
    x = g_lyrics_box.rgn_txt.x;
    y = g_lyrics_box.rgn_txt.y;  
    h = g_lyrics_box.rgn_txt.h;
    
    if (g_lyrics_box.next_time > g_lyrics_box.curr_time)
    {
        yOff = (S16)(g_lyrics_box.line_height*g_lyrics_box.time_out/
            (g_lyrics_box.next_time-g_lyrics_box.curr_time));
    }
    else
    {
        yOff = 0;
    }
    yBeg = (S16)(y-layer_y);
    
    g_lyrics_box.rgn_txt.x = (S16)(x-layer_x);
    g_lyrics_box.rgn_txt.y = (S16)(y-layer_y-yOff);
    g_lyrics_box.rgn_txt.h = g_lyrics_box.line_height;     
    
    kal_mem_cpy(&g_lyrics_box.rgn_clip, &g_lyrics_box.rgn_txt, 
        sizeof(mmi_medply_rect_struct));
    
    for (i = 0; i <= g_lyrics_box.line_count; i++)
    {
        pStr = NULL;
        if (g_lyrics_box.line_id[i] < LYRICS_MAX_LINES)
        {
            pStr = g_lyrics->lines_p[g_lyrics_box.line_id[i]].st_text;
            nLen = g_lyrics->lines_p[g_lyrics_box.line_id[i]].ln_text; 
        }
        if (NULL != pStr)
        {
            if (g_lyrics_box.rgn_txt.y < yBeg)
            {
                g_lyrics_box.rgn_clip.y = yBeg;
                g_lyrics_box.rgn_clip.h = g_lyrics_box.rgn_txt.y - yBeg + 
                    g_lyrics_box.rgn_txt.h;
            }
            else if (g_lyrics_box.rgn_txt.y+g_lyrics_box.font_height > yBeg+h)
            {
                g_lyrics_box.rgn_clip.y = g_lyrics_box.rgn_txt.y;
                g_lyrics_box.rgn_clip.h = yBeg + h - g_lyrics_box.rgn_txt.y;
            }
            else
            {
                g_lyrics_box.rgn_clip.y = g_lyrics_box.rgn_txt.y;
                g_lyrics_box.rgn_clip.h = g_lyrics_box.rgn_txt.h;
            }
            
            u16Tmp = pStr[nLen];
            pStr[nLen] = 0;   

            if (i == g_lyrics_box.line_focus)
            {
                gui_set_text_border_color(MMI_MSCR_LYRICS_FOCUS_COLOR_BG);  
                gui_set_text_color(MMI_MSCR_LYRICS_FOCUS_COLOR_FG); 

                mmi_mscr_paint_text(&g_lyrics_box.rgn_txt, &g_lyrics_box.rgn_clip, 
                    pStr, 0, MMI_MSCR_TXT_DRAW_ATOP, 1, -1);
            }
            else
            {
                gui_set_text_border_color(MMI_MSCR_LYRICS_NORMAL_COLOR_BG); 
                gui_set_text_color(MMI_MSCR_LYRICS_NORMAL_COLOR_FG); 

                mmi_mscr_paint_text(&g_lyrics_box.rgn_txt, &g_lyrics_box.rgn_clip, 
                    pStr, 0, MMI_MSCR_TXT_DRAW_ATOP, 1, -1);
            } 
            pStr[nLen] = u16Tmp;
        }
        g_lyrics_box.rgn_txt.y += g_lyrics_box.line_height;        
    }
    g_lyrics_box.rgn_txt.x = x;
    g_lyrics_box.rgn_txt.y = y;
    g_lyrics_box.rgn_txt.h = h;   
    
    gdi_pop_and_restore_alpha_blending_source_layer(); 
    gdi_layer_pop_and_restore_active();

}


#endif
/*****************************************************************************
* FUNCTION
*   mmi_mscr_play_video_demo
* DESCRIPTION
*   play demo video animation
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_play_video_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    S32 img_w, img_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(0);
    
    if (GDI_NULL_HANDLE != g_mscr_hd->ani_video_demo_hdl)
    {
        MMI_MSCR_MSG_TRACE(1);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*in full screen, use video layer to draw lyrics text*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        //gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    }
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);      
    gdi_image_get_dimension_id(IMG_ID_MEDPLY_FTE_AUDIO_ANI, &img_w, &img_h);
    
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    
    MMI_MSCR_MSG_TRACE(w);
    MMI_MSCR_MSG_TRACE(h);
    
    x = (w - img_w) >> 1;
    y = (h - img_h) >> 1;
    
    /*When there has osd layer, so need flat two layers*/
    gdi_anim_set_blt_before_callback(mmi_mscr_before_blt_video_demo_callback);   
#ifdef  MMI_MEDPLY_COMP_USING_PART_BLT
    gdi_anim_set_blt_after_callback(mmi_mscr_after_blt_video_demo_callback);
#endif
    gdi_image_draw_animation_id(x, y, IMG_ID_MEDPLY_FTE_AUDIO_ANI, &g_mscr_hd->ani_video_demo_hdl);
    gdi_layer_pop_and_restore_active();  
    
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_stop_video_demo
* DESCRIPTION
*   stop demo video animation
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_stop_video_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(g_mscr_hd->ani_video_demo_hdl);
    
    if (GDI_NULL_HANDLE != g_mscr_hd->ani_video_demo_hdl)
    {
        if (GDI_ERROR_HANDLE != g_mscr_hd->ani_video_demo_hdl)
        {
            gdi_image_stop_animation(g_mscr_hd->ani_video_demo_hdl);
        }
        g_mscr_hd->ani_video_demo_hdl = GDI_NULL_HANDLE;         
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_DELTETING)
    {
        return;
    }
    mmi_mscr_draw_video_demo();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_before_blt_video_demo_callback
* DESCRIPTION
*   process before animation paint to lcd
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_before_blt_video_demo_callback(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_DEMO_CB, ret);
    MMI_MSCR_MSG_TRACE(0);

//#ifdef  MMI_MEDPLY_COMP_USING_PART_BLT
//    lcd_enable_partial_update(KAL_TRUE);
//#endif    

    if (NULL == g_mscr_hd)
    {
        /*Add Log for this is callback function, can't ctrl by module itself*/
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
}

#ifdef  MMI_MEDPLY_COMP_USING_PART_BLT
/*****************************************************************************
* FUNCTION
*   mmi_mscr_after_blt_video_demo_callback
* DESCRIPTION
*   process after animation paint to lcd
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_after_blt_video_demo_callback(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_DEMO_CB, ret);
    MMI_MSCR_MSG_TRACE(1);

    //lcd_enable_partial_update(KAL_FALSE);

    if (NULL == g_mscr_hd)
    {
        /*Add Log for this is callback function, can't ctrl by module itself*/
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
}
#endif

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_video_demo
* DESCRIPTION
*   draw demo video frame
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_draw_video_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    S32 img_w, img_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*in full screen, use video layer to draw lyrics text*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        if (GDI_NULL_HANDLE == g_mscr_hd->layer_gesture)
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);            
        }
        else
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_gesture);
        }     
    }
    
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);    
    gdi_image_get_dimension_id(IMG_ID_MEDPLY_FTE_AUDIO_ANI, &img_w, &img_h);
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    
    x = (w - img_w) >> 1;
    y = (h - img_h) >> 1;
    
    MMI_MSCR_MSG_TRACE(w);
    MMI_MSCR_MSG_TRACE(h);
    
    gdi_image_draw_id(x, y, IMG_ID_MEDPLY_FTE_AUDIO_ANI);
    gdi_layer_pop_and_restore_active();
    
}


#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
/*****************************************************************************
* FUNCTION
*  mmi_mscr_init_spectrum
* DESCRIPTION
*  INIT spectrum display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_INIT_SPECTRUM)
    {
        return;
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_INIT_SPECTRUM;
    g_mscr_hd->spectrum_p->start_x = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].x;
    g_mscr_hd->spectrum_p->start_y = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].y;
    g_mscr_hd->spectrum_p->width   = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].w;
    g_mscr_hd->spectrum_p->height  = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].h;
    
    g_mscr_hd->spectrum_p->number_of_bars  = MMI_MSCR_SPECTRUM_NUM;
    g_mscr_hd->spectrum_p->style           = STYLE_BARS;
    g_mscr_hd->spectrum_p->target_lcd      = GDI_LCD_MAIN_LCD_HANDLE;
    g_mscr_hd->spectrum_p->target_layer    = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW];
    g_mscr_hd->spectrum_p->draw_callback   = mmi_mscr_draw_spectrum_callback;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_play_spectrum
* DESCRIPTION
*  play spectrum display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_play_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != mmi_inline_is_spectrum_blocked())
    {   
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
	
        if (srv_backlight_is_lcd_sleep())
        {
            MMI_MSCR_MSG_TRACE(1);
            return;
        }
        
    if (g_mscr_hd->flags & 
        (MMI_MSCR_HD_HAS_SEEKING_WITH_KEY|MMI_MSCR_HD_HAS_SEEKING_WITH_PEN))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAY_SPECTRUM))
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAY_SPECTRUM;

        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        
        mdi_audio_start_calc_spectrum();
        mmi_audio_spectrum_init_display(g_mscr_hd->spectrum_p);
        mmi_audio_spectrum_start_display(g_mscr_hd->spectrum_p);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_stop_spectrum
* DESCRIPTION
*  stop spectrum display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_stop_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAY_SPECTRUM)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PLAY_SPECTRUM;
        
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);

        mdi_audio_stop_calc_spectrum(); 
        mmi_audio_spectrum_stop_display(g_mscr_hd->spectrum_p);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_spectrum_callback
* DESCRIPTION
*  draw spectrum display background
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_draw_spectrum_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /*
    **  TODO: better repace as mmi_mscr_paint_region_backgroud
    **  Currently only use black color as background.
    */
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    gdi_draw_solid_rect(x1, y1, x2, y2, MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();
}
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

/*****************************************************************************
* FUNCTION
*   mmi_mscr_set_status_and_ani
* DESCRIPTION
*   init view display content, and init timer for moving, init blt layers
* PARAMETERS
*   ui_status:  new ui status
*   id_ani:     animation id for main screen to show  
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_set_status_and_ani(U8 ui_status, U8 id_ani)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(id_ani);
    
    if (MMI_MEDPLY_ANI_LOADING != id_ani)
    {
    /*
    **  Clean loading percentage in there, 
    **  for the api not used in pair by ctrl
        */
        MMI_MSCR_MSG_TRACE(id_ani);
        g_mscr_hd->loading_percent = 0;
    }
    
    g_mscr_hd->id_animation = id_ani;
    /*To Stop Animation and remove the OSD flag*/
    switch(id_ani)
    {
    case MMI_MEDPLY_ANI_LOADING:

        g_mscr_hd->ani_str_id = STR_ID_MEDPLY_FTE_LOADING;
        break;
    case MMI_MEDPLY_ANI_VIDEO_OPENING:

        g_mscr_hd->ani_str_id = STR_ID_MEDPLY_FTE_OPENING;
        break;
    case MMI_MEDPLY_ANI_BT_CONNECTING:

        g_mscr_hd->ani_str_id = STR_ID_MEDPLY_FTE_BT_CONNECT;
        break;
    case MMI_MEDPLY_ANI_RTP_CONNECTING:

        g_mscr_hd->ani_str_id = STR_ID_MEDPLY_FTE_RTP_CONNECT;
        break;
    case MMI_MEDPLY_ANI_SNAP_SHOT:

        g_mscr_hd->ani_str_id = STR_ID_MEDPLY_FTE_SNAPSHOT;
        break;
    default :    
        
        g_mscr_hd->ani_str_id = 0;
        break;
    }
    
    /*
    *   the status need update first before update status
    */
    mmi_mscr_update_duration();
    mmi_mscr_draw_duration();   /*paint with background*/
    
    if (g_mscr_hd->ui_status != ui_status)
    {   /*NO status update*/
        MMI_MSCR_MSG_TRACE(ui_status);
        g_mscr_hd->ui_status = ui_status;   
    }
    
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {    
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER))
        {
            gui_start_timer(MMI_MSCR_UI_START_PLAY_TIME, mmi_mscr_start_playing);
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAYING_TIMER;
        }
    }
    else
    {
        mmi_mscr_stop_playing();
    }
    /*
    *   The ui status may changed, although ui state may same
    *   button status need update after status change
    */
    mmi_mscr_update_redraw_button();
    
    if (0 != g_mscr_hd->ani_str_id)
    {  
        /*g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;*/
        mmi_mscr_start_osd_animation();
    }    
    else
    {
        /*Stop animation, reset g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;*/
        mmi_mscr_stop_osd_animation();
    }
    mmi_mscr_config_layer_blt();  
    mmi_mscr_config_backlight();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_beg_paint
* DESCRIPTION
*  paint prepare
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_beg_paint(gdi_handle layer_hdl, mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_hdl); 
    gdi_push_and_set_alpha_blending_source_layer(layer_hdl);
    gdi_layer_reset_clip();  
    
    if (NULL != rgn_p)
    {
        mmi_mscr_add_paint_rgn(layer_hdl, rgn_p);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_add_paint_rgn
* DESCRIPTION
*  add paint region 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_add_paint_rgn(gdi_handle layer_hdl, mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mscr_add_paint_rgn_ex(layer_hdl, rgn_p, 0, 0);
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_add_paint_rgn_ex
* DESCRIPTION
*  add paint region 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_add_paint_rgn_ex(gdi_handle layer_hdl, mmi_medply_rect_struct* rgn_p, 
                                          S16 x_border, S16 y_border)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_medply_rect_struct  rect;
    U8 nRet;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    rect.x = rgn_p->x - x_border;
    rect.y = rgn_p->y - y_border;
    rect.w = (S16)(rgn_p->w + x_border*2);
    rect.h = (S16)(rgn_p->h + y_border*2);

    if (layer_hdl == g_mscr_hd->layer_hilight)
    {
        if (g_mscr_hd->hilight_flags & MMI_MSCR_IS_HILIGHT_PAINT)
        {
            nRet = mmi_mscr_compare_region(&rect, &g_mscr_hd->rgn_hilight);
            if (MMI_MSCR_RGN_1IN2 == nRet || MMI_MSCR_RGN_INTERSECT == nRet)
            {
                mmi_mscr_reset_hilight();
                g_mscr_hd->hilight_flags |= MMI_MSCR_IS_HILIGHT_ERASED;
            }
            if (MMI_MSCR_RGN_2IN1 == nRet)
            {   /*hiligth will cover by current paint*/
                g_mscr_hd->hilight_flags &= ~MMI_MSCR_IS_HILIGHT_PAINT;
                g_mscr_hd->hilight_flags |= MMI_MSCR_IS_HILIGHT_ERASED;
            }
        }
        else
        {   /*hilight has not paint, need paint at end paint*/
            g_mscr_hd->hilight_flags |= MMI_MSCR_IS_HILIGHT_ERASED;
        }
    }
    
    /*popup layer no need to restore background*/
    if (layer_hdl != g_mscr_hd->layer_popup_hdl)
    {
        mmi_mscr_paint_region_backgroud(&rect);
    }
    mmi_mscr_merge_blt_rgn(rect.x, rect.y, rect.w, rect.h);
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_end_paint
* DESCRIPTION
*  paint unprepare
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_end_paint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->hilight_flags & MMI_MSCR_IS_HILIGHT_ERASED)
    {
        mmi_mscr_merge_blt_rgn(g_mscr_hd->rgn_hilight.x, g_mscr_hd->rgn_hilight.y,
            g_mscr_hd->rgn_hilight.w, g_mscr_hd->rgn_hilight.h);
        mmi_mscr_paint_hilight();   
    }
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_duration
* DESCRIPTION
*  update duration image and ticks
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_draw_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_medply_rect_struct  rgn_bar;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
        return;
    }

    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG))
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        /*do not update anything when background has not ready, this should be main screen has not been redraw*/
        return;
    }
    rgn_bar.x = 0;
    rgn_bar.y = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.y;
    rgn_bar.w = GDI_LCD_WIDTH;
    rgn_bar.h = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.h+1;
    
    mmi_mscr_beg_paint(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL], &rgn_bar);
    mmi_mscr_add_paint_rgn(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL], 
        &g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT]);
    mmi_mscr_add_paint_rgn(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL], 
        &g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT]);
    /*show image box*/
    mmi_mscr_paint_duration_bar();
    mmi_mscr_paint_ticks();    
    mmi_mscr_end_paint();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_button_id
* DESCRIPTION
*  draw button by id
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_button_id(U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer_hdl = GDI_NULL_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != g_mscr_hd->rgn_hide_flag[id])
    {
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
        return;
    } 
    /*if update button not in it's view mode, should be return*/
    if (MMI_MEDPLY_RGN_ID_USER_RATING == id)
    {   /*only update this button in audio mode*/
        if (MMI_MSCR_CONTENT_METAINFO != g_mscr_hd->view_content)
        {
            MMI_MSCR_MSG_TRACE(id);
            return;
        }
    }
    if (id >= MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL && id <= MMI_MEDPLY_RGN_ID_VOLUME_SPEAK)
    {   /*only update those button in popup screen*/
        if (GDI_NULL_HANDLE == g_mscr_hd->layer_popup_hdl)
        {
            MMI_MSCR_MSG_TRACE(id);
            return;
        }
        layer_hdl = g_mscr_hd->layer_popup_hdl;
    }
    if (id >= MMI_MEDPLY_RGN_ID_KURO && id <= MMI_MEDPLY_RGN_ID_KURO_REPEAT)
    {
        if (MMI_MSCR_VIEW_MODE_KURO != g_mscr_hd->view_mode)
        {
            MMI_MSCR_MSG_TRACE(id);
            return;
        }
    }
    if (GDI_NULL_HANDLE == layer_hdl)
    {        
        if (MMI_MSCR_RGN_1IN2 == mmi_mscr_compare_region(&g_mscr_ui.touch_btn[id].pen_rgn,
            &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL]))
        {
            layer_hdl = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL];
        }
        else if (MMI_MSCR_RGN_1IN2 == mmi_mscr_compare_region(&g_mscr_ui.touch_btn[id].pen_rgn, 
            &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW]))
        {
            layer_hdl = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW];
        }
    }
    if (GDI_NULL_HANDLE != layer_hdl)
    {
        /*
        **  pen touch region should large then view region, or we should get image dimension for paint region
        */
        mmi_mscr_beg_paint(layer_hdl, &g_mscr_ui.touch_btn[id].pen_rgn);
        mmi_mscr_paint_button_id(id);
        mmi_mscr_end_paint();        
    }
    else
    {
        MMI_MSCR_ERR_TRACE(id);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_title
* DESCRIPTION
*   draw title bar
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_mscr_beg_paint(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP], 
        &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP]);
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    wgui_status_icon_bar_update();
#endif
    mmi_mscr_end_paint();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_panel
* DESCRIPTION
*   draw panel region
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_draw_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_mscr_beg_paint(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL], &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL]);
    
    gdi_layer_reset_clip();
    
    /*show duration bar*/
    mmi_mscr_paint_duration_bar();
    mmi_mscr_paint_ticks();
    
    /*paint control buttons*/
    for (i = 0; i <= MMI_MEDPLY_RGN_ID_ZOOM; i++)
    {
        mmi_mscr_paint_button_id(i);    
    }   
    /*End Paint*/
    mmi_mscr_end_paint();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_view
* DESCRIPTION
*   draw view region
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_draw_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8 view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    else
    {
        view_content = g_mscr_hd->view_content;
    }
    MMI_MSCR_MSG_TRACE(view_content);  
    
    switch(view_content)
    {    
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_draw_lyrics();
        break;
#endif   
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)    
    case MMI_MSCR_CONTENT_METAINFO:     
        
        mmi_mscr_draw_meta();
        break;  
#endif
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        
        MMI_MSCR_MSG_TRACE(g_mscr_hd->ani_video_demo_hdl);
        if (GDI_NULL_HANDLE == g_mscr_hd->ani_video_demo_hdl)
        {
            mmi_mscr_draw_video_demo();  
        }        
        break;  
    case MMI_MSCR_CONTENT_SPECTRUM:
    case MMI_MSCR_CONTENT_VIDEO_NULL: 
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_NULL:
    default:
        break;
    }
}
/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_background
* DESCRIPTION
*   draw normal screen background
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_draw_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do nothing in full screen status*/
        return;
    } 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_base_hdl);

    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG))
    {
        if (MMI_MSCR_VIEW_MODE_AUDIO == g_mscr_hd->view_mode)
        {
            gdi_image_draw_id(0, 0, IMG_ID_MEDPLY_FTE_AUDIO_BG);

            gdi_image_draw_id(g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE1].x, 
                g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE1].y, IMG_ID_MEDPLY_FTE_SEPERATE_LINE);

            gdi_image_draw_id(g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE2].x, 
                g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE2].y, IMG_ID_MEDPLY_FTE_SEPERATE_LINE);
        }
        else
        {
            gdi_image_draw_id(0, 0, IMG_ID_MEDPLY_FTE_VIDEO_BG);
        }
        /*paint item nerver changed in background*/
        gdi_image_draw_id(g_mscr_ui.duration_img.view_x, g_mscr_ui.duration_img.view_y, 
            g_mscr_ui.duration_img.bg_img_id);

        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAINT_BG;
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK;
    }
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    if ((g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_ARTWORK) && 
        (MMI_MSCR_VIEW_MODE_AUDIO == g_mscr_hd->view_mode))
    {       
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK))
        {
            if (0 != mmi_mscr_paint_meta_artwork())
            {
                /*set this flag for update background when file changed*/
                g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK;
            }
        }
    }
#endif
	gdi_layer_pop_and_restore_active();

    
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_paint_region_backgroud
* DESCRIPTION
*   paint region background
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_paint_region_backgroud(mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h, i, x, y, w, h;
    S32 line_src_size, line_cpy_size, line_dst_size;
    U8* layer_mem;
    U8* mem_src, *mem_dst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position(&layer_x, &layer_y);

    i = mmi_mscr_compare_region(rgn_p, &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW]);
    MMI_MSCR_MSG_TRACE(i);

    if (MMI_MSCR_RGN_1IN2 == i)
    {
        switch(g_mscr_hd->view_content)
        {
        case MMI_MSCR_CONTENT_METAINFO:
        case MMI_MSCR_CONTENT_KURO:    
            break;    
        /*those 4 type only earse black color*/
        case MMI_MSCR_CONTENT_LYRICS:
        case MMI_MSCR_CONTENT_SPECTRUM:  
        case MMI_MSCR_CONTENT_VIDEO:
        case MMI_MSCR_CONTENT_VIDEO_DEMO:
        case MMI_MSCR_CONTENT_VIDEO_NULL:        
        default:    

            gdi_draw_solid_rect(rgn_p->x - layer_x, rgn_p->y - layer_y, 
                rgn_p->x - layer_x + rgn_p->w, rgn_p->y - layer_y + rgn_p->h, 
                MMI_MSCR_LAYER_COLOR_BACKGROUND);
            return;
        }
    }
    
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_get_buffer_ptr(&layer_mem);
    /*
    **  assume layer begin as same x position 0, and same size with LCD;
    **  assume region must in site layer
    */    
    if (rgn_p->x < layer_x)
    {
        rgn_p->x = layer_x;
    }
    x = rgn_p->x - layer_x;
    if (x > layer_w)
    {
        MMI_MSCR_ERR_TRACE(x);
        return;
    }

    if (rgn_p->y < layer_y)
    {
        rgn_p->y = layer_y;
    }
    y = rgn_p->y - layer_y;
    if (y > layer_h)
    {
        MMI_MSCR_ERR_TRACE(y);
        return;
    }
    w = rgn_p->x + rgn_p->w - layer_x - x;
    if (w > layer_w)
    {
        w = layer_w;
    }
    if (w <= 0)
    {
        MMI_MSCR_ERR_TRACE(w);
        return;
    }
    h = rgn_p->y + rgn_p->h - layer_y - y;
    if (h > layer_h)
    {
        h = layer_h;
    }
    if (h <= 0)
    {
        MMI_MSCR_ERR_TRACE(h);
        return;
    }

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        line_src_size = GDI_LCD_HEIGHT * MMI_MSCR_COLOR_DEPTH;
    }
    else
    {
        line_src_size = GDI_LCD_WIDTH * MMI_MSCR_COLOR_DEPTH;
    }    
    line_dst_size   = layer_w*MMI_MSCR_COLOR_DEPTH;
    line_cpy_size   = w*MMI_MSCR_COLOR_DEPTH;

    mem_src = g_mscr_hd->mem_base_layer + rgn_p->y*line_src_size + rgn_p->x*MMI_MSCR_COLOR_DEPTH;
    mem_dst = layer_mem + y*line_dst_size + x*MMI_MSCR_COLOR_DEPTH;

    for (i = 0; i < rgn_p->h; i++)
    {
        kal_mem_cpy(mem_dst, mem_src, line_cpy_size);
        mem_dst += line_dst_size;
        mem_src += line_src_size;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_duration_bar
* DESCRIPTION
*  paint duration bar
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_duration_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, x1, y1, x2, y2, w, h, but_w, but_h;
    S32 offset_x, offset_y;
    mmi_medply_img_box_struct*  img_p = &g_mscr_ui.duration_img;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*redraw duration bar*/    
    gdi_layer_get_position(&offset_x, &offset_y);  
    x1 = img_p->view_x - offset_x;
    y1 = img_p->view_y - offset_y;

    gdi_layer_push_clip();     
    if (0 != img_p->md_range && MMI_MSCR_ERR_IMG_ID != img_p->md_img_id)
    {
        gdi_image_get_dimension_id(img_p->md_img_id, &w, &h);
        
        x2 = x1 + w * img_p->md_range/100;
        y2 = y1 + h;
        
        gdi_layer_set_clip(x1, y1, x2, y2);   
        gdi_image_draw_id(x1, y1, img_p->md_img_id);
    }
    
    if (MMI_MSCR_ERR_IMG_ID != img_p->fg_img_id)
    {
        gdi_image_get_dimension_id(img_p->fg_img_id, &w, &h);
        
        x2 = x1 + w * img_p->fg_range/100;
        y2 = y1 + h;  

        if (0 != img_p->fg_range)
        {
            gdi_layer_set_clip(x1, y1, x2, y2);   
            gdi_image_draw_id(x1, y1, img_p->fg_img_id);
        }
        /*redraw touch button if need*/
        if (0 != mmi_inline_is_duration_seek_able())
        {      
            gdi_image_get_dimension_id(g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].up_img_id, 
                &but_w, &but_h);
            
            y = ((h-but_h) / 2) + y1;            
            x = x2 - (but_w / 2);

            gdi_layer_set_clip(x, y, x + but_w , y + but_h);        
            gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].down_img_id);
            /*update for touch*/
            g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.x = x + offset_x;
        }
    }     
    gdi_layer_pop_clip();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_ticks
* DESCRIPTION
*  draw time ticks
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_medply_rect_struct  rgn;
    S32 offset_x, offset_y;
    U32 time;
    U32 str[8];
    U16 h, m, s;
    U8  attr_w, attr_h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw bg firstly*/    
    gdi_layer_get_position(&offset_x, &offset_y);
    
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(255, 255, 255));
    
    /*draw current time*/
    time = (U32)((g_mscr_hd->playtime+500)/1000);
    h = time/ 3600;  
    if (h > 99)
    {   /*Error protected*/
        MMI_MSCR_ERR_TRACE(h);
        h = 99;
        m = 59;
        s = 59;
    }
    else
    {
        m = (time - h * 3600) / 60;
        s = (time - h * 3600 - m * 60);
    }
    kal_wsprintf((WCHAR*)str, "%02d:%02d:%02d",h, m, s);
    
    rgn.x = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].x - offset_x;
    rgn.y = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].y - offset_y;
    rgn.w = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].w;
    rgn.h = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].h;
    attr_w = MMI_MSCR_TXT_DRAW_ALEFT;
    attr_h = MMI_MSCR_TXT_DRAW_ATOP;
    
    mmi_mscr_paint_text(&rgn, &rgn, (unsigned short *)str, attr_w, attr_h, 0, -1);
    
    /*draw duration time*/
    time = (U32)((g_mscr_hd->duration+500)/1000);
    h = time/ 3600;  
    if (h > 99)
    {   /*Error protected*/
        MMI_MSCR_ERR_TRACE(h);
        h = 99;
        m = 59;
        s = 59;
    }
    else
    {
        m = (time - h * 3600) / 60;
        s = (time - h * 3600 - m * 60);
    }
    kal_wsprintf((WCHAR*)str, "%02d:%02d:%02d",h, m, s);
    
    rgn.x = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].x - offset_x;
    rgn.y = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].y - offset_y;
    rgn.w = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].w;
    rgn.h = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].h;
    attr_w = MMI_MSCR_TXT_DRAW_ALEFT;
    attr_h = MMI_MSCR_TXT_DRAW_ATOP;
    
    mmi_mscr_paint_text(&rgn, &rgn, (unsigned short *)str, attr_w, attr_h, 0, -1);
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_button_id
* DESCRIPTION
*  draw button by id
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_button_id(U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, x, y;
    U16 img_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != g_mscr_hd->rgn_hide_flag[id])
    {
        return;
    } 
    gdi_layer_get_position(&layer_x, &layer_y);
    
    x = g_mscr_ui.touch_btn[id].view_x - layer_x;
    y = g_mscr_ui.touch_btn[id].view_y - layer_y;  
    
    if (0 != g_mscr_hd->rgn_disable_flag[id])
    {
        img_id = g_mscr_ui.touch_btn[id].disable_img_id;
    }
    else
    {
        if (g_mscr_hd->rgn_push_down_id == id)
        {
            img_id = g_mscr_ui.touch_btn[id].down_img_id;
        }
        else
        {
            img_id = g_mscr_ui.touch_btn[id].up_img_id;
        }
    }   
    gdi_image_draw_id(x, y, img_id);    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_popup_volume
* DESCRIPTION
*  show volume bar   
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_draw_popup_volume(S32 volume, U8 is_hilight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_push_and_set_active(g_mscr_hd->layer_popup_hdl);   
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_POPUP_DB_BUFFER)
    {
        gdi_layer_toggle_double();
    }    
#endif
    mmi_mscr_paint_popup_volume_bar(volume, is_hilight);
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);
    mmi_mscr_paint_button_id(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);
    
    gdi_layer_pop_and_restore_active();    
    
    mmi_mscr_merge_blt_rgn(g_mscr_hd->rgn_popup.x, g_mscr_hd->rgn_popup.y, 
        g_mscr_hd->rgn_popup.w, g_mscr_hd->rgn_popup.h);
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_popup_volume_bar
* DESCRIPTION
*  show volume bar   
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_popup_volume_bar(S32 volume, U8 is_hilight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y;
    S32 x, y, w, h, x2, y2;
    S32 fg_w, fg_h;
    U16 image_draw_id;
    U16 image_base_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_image_get_dimension_id(g_mscr_ui.volume_img.fg_img_id, &fg_w, &fg_h);
    
    x = g_mscr_ui.volume_img.view_x - layer_x;
    y = g_mscr_ui.volume_img.view_y - layer_y;
    h = fg_h;
    /*w = ((volume * fg_w) / MDI_AUD_VOL_EX_MUTE_MAX);*/
    w = ((volume * (fg_w - MMI_MEDPLY_DOT_W))/MDI_AUD_VOL_EX_MUTE_MAX) + (MMI_MEDPLY_DOT_W/2);
    
    /* draw bg */    
    gdi_image_draw_id(0, 0, g_mscr_ui.volume_img.bg_img_id);
    
    /* draw fg */
    x2 = x + w;
    y2 = y + fg_h;
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(x, y, x2, y2);
    gdi_image_draw_id(x, y, g_mscr_ui.volume_img.fg_img_id);
    gdi_layer_pop_clip();
    
    
    /* redraw touch button*/
    y = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.y - layer_y;     

    if (0 != is_hilight)
    {
        image_base_id = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].down_img_id;
    }
    else
    {
        image_base_id = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].up_img_id;
    }
    gdi_image_get_dimension_id(image_base_id, &w, &h);

    image_draw_id = image_base_id;

    if ((volume <=  1) || (volume >= MDI_AUD_VOL_EX_MUTE_MAX - 1))
    {
        if (0 == volume)
        {
            image_draw_id = image_base_id - 2;
        }
        else if (1 == volume)
        {
            image_draw_id = image_base_id -1;
        }
        else if (MDI_AUD_VOL_EX_MUTE_MAX == volume)
        {
            x = x + fg_w - w;
            image_draw_id = image_base_id + 2;
        }
        else if ((MDI_AUD_VOL_EX_MUTE_MAX - 1)== volume)
        {
            x = x + fg_w - w;
            image_draw_id = image_base_id + 1;
        }
        gdi_image_draw_id(x, y, image_draw_id);   
        g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.x = x + layer_x;
    }
    else
    {
        x = x2 - (w / 2);
        gdi_layer_push_clip();
        gdi_layer_set_clip(x, y, x + w , y + h);
        
        gdi_image_draw_id(x, y, image_draw_id);
        gdi_layer_pop_clip();
        g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.x = x + layer_x;
    }   
    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_popup_userate_bar
* DESCRIPTION
*  show user rating bar   
* PARAMETERS
*  volume        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_popup_userate_bar(S32 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y;
    S32 x,y,w;
    S32 fg_w, fg_h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_image_get_dimension_id(g_mscr_ui.rating_img.fg_img_id, &fg_w, &fg_h);
    
    x = g_mscr_ui.rating_img.view_x - layer_x;
    y = g_mscr_ui.rating_img.view_y - layer_y;
    w = volume * (g_mscr_ui.rating_img.star_w + g_mscr_ui.rating_img.interval);
    
    /* draw bg */    
    gdi_image_draw_id(0, 0, g_mscr_ui.rating_img.bg_img_id);
    
    /* draw fg */
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(x, y, x + w, y + fg_h);
    gdi_image_draw_id(x, y, g_mscr_ui.rating_img.fg_img_id);
    gdi_layer_pop_clip();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_prepare_hilight
* DESCRIPTION
*  before show hilight we set hightlight button
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_prepare_hilight(U8 button_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 but_w, but_h, img_w, img_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_hilight)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->layer_hilight);
        mmi_mscr_unprepare_hilight();
    }
    if (MMI_MSCR_RGN_1IN2 == mmi_mscr_compare_region(&g_mscr_ui.touch_btn[button_id].pen_rgn,
        &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL]))
    {
        g_mscr_hd->layer_hilight = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL];
    }
    else if (MMI_MSCR_RGN_1IN2 == mmi_mscr_compare_region(&g_mscr_ui.touch_btn[button_id].pen_rgn, 
        &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW]))
    {
        g_mscr_hd->layer_hilight = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW];
    }
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_hilight)
    {
        MMI_MSCR_MSG_TRACE(0);
        return;
    }    
    gdi_image_get_dimension_id(g_mscr_ui.touch_btn[button_id].up_img_id, &but_w, &but_h);
    gdi_image_get_dimension_id(IMG_ID_MEDPLY_FTE_HL_BTN, &img_w, &img_h);

    g_mscr_hd->rgn_hilight.x = g_mscr_ui.touch_btn[button_id].view_x + (but_w - img_w)/2;
    g_mscr_hd->rgn_hilight.y = g_mscr_ui.touch_btn[button_id].view_y + (but_h - img_h)/2;
    g_mscr_hd->rgn_hilight.w = img_w;
    g_mscr_hd->rgn_hilight.h = img_h;    
    if (g_mscr_hd->layer_hilight == g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW])
    {
        /*move hightlight region two pixel up for there has shadow*/        
        if (g_mscr_hd->rgn_hilight.y >= 2)
        {
            g_mscr_hd->rgn_hilight.y -= 2;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_unprepare_hilight
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_unprepare_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_hilight)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hilight); 
    mmi_mscr_reset_hilight();
    gdi_layer_pop_and_restore_active();

    mmi_mscr_merge_blt_rgn(g_mscr_hd->rgn_hilight.x, g_mscr_hd->rgn_hilight.y,
        g_mscr_hd->rgn_hilight.w, g_mscr_hd->rgn_hilight.h);
    
    g_mscr_hd->layer_hilight = GDI_NULL_HANDLE;
    g_mscr_hd->hilight_flags = 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_reset_hilight
* DESCRIPTION
*  before show hilight we will keep the old background
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_reset_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h, i, w, h;
    S32 line_src_size, line_cpy_size, line_dst_size;
    U8* layer_mem;
    U8* mem_src, *mem_dst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_hilight)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (!(g_mscr_hd->hilight_flags & MMI_MSCR_IS_HILIGHT_PAINT))
    {
        /*have not paint hilight, no need restore*/
        MMI_MSCR_MSG_TRACE(g_mscr_hd->hilight_flags);
        return;
    }
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_get_buffer_ptr(&layer_mem);

    w = layer_w - (g_mscr_hd->rgn_hilight.x - layer_x);
    if (w > g_mscr_hd->rgn_hilight.w)
    {
        w = g_mscr_hd->rgn_hilight.w;
    }
    line_src_size   = w * MMI_MSCR_COLOR_DEPTH;
    line_dst_size   = layer_w*MMI_MSCR_COLOR_DEPTH;
    line_cpy_size   = line_src_size;
    
    mem_src = g_mscr_hd->mem_hilight;
    mem_dst = layer_mem + (g_mscr_hd->rgn_hilight.y - layer_y)*line_dst_size + 
        (g_mscr_hd->rgn_hilight.x-layer_x)*MMI_MSCR_COLOR_DEPTH;
    
    h = layer_h - (g_mscr_hd->rgn_hilight.y - layer_y);
    if (h > g_mscr_hd->rgn_hilight.h)
    {
        h = g_mscr_hd->rgn_hilight.h;
    } 
    for (i = 0; i < h; i++)
    {
        kal_mem_cpy(mem_dst, mem_src, line_cpy_size);
        mem_dst += line_dst_size;
        mem_src += line_src_size;
    }
    g_mscr_hd->hilight_flags &= ~MMI_MSCR_IS_HILIGHT_PAINT;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_backup_hilight
* DESCRIPTION
*  before show hilight we will keep the old background
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_backup_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h, i, w, h;
    S32 line_src_size, line_cpy_size, line_dst_size;
    U8* layer_mem;
    U8* mem_src, *mem_dst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_hilight)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_get_buffer_ptr(&layer_mem);
    
    w = layer_w - (g_mscr_hd->rgn_hilight.x - layer_x);
    if (w > g_mscr_hd->rgn_hilight.w)
    {
        w = g_mscr_hd->rgn_hilight.w;
    }    
    line_dst_size  = w * MMI_MSCR_COLOR_DEPTH;
    line_src_size  = layer_w*MMI_MSCR_COLOR_DEPTH;
    line_cpy_size  = line_dst_size;    
    
    mem_src = layer_mem + (g_mscr_hd->rgn_hilight.y - layer_y)*line_src_size + 
        (g_mscr_hd->rgn_hilight.x-layer_x)*MMI_MSCR_COLOR_DEPTH;
    mem_dst = g_mscr_hd->mem_hilight;
    
    h = layer_h - (g_mscr_hd->rgn_hilight.y - layer_y);
    if (h > g_mscr_hd->rgn_hilight.h)
    {
        h = g_mscr_hd->rgn_hilight.h;
    }     
    for (i = 0; i < h; i++)
    {
        kal_mem_cpy(mem_dst, mem_src, line_cpy_size);
        mem_dst += line_dst_size;
        mem_src += line_src_size;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_hilight
* DESCRIPTION
*  paint hilight image
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mscr_backup_hilight();

    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_image_draw_id(g_mscr_hd->rgn_hilight.x-layer_x, 
        g_mscr_hd->rgn_hilight.y-layer_y, IMG_ID_MEDPLY_FTE_HL_BTN);

    g_mscr_hd->hilight_flags |= MMI_MSCR_IS_HILIGHT_PAINT;
    g_mscr_hd->hilight_flags &= ~MMI_MSCR_IS_HILIGHT_ERASED;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_scroll
* DESCRIPTION
*   draw scroll text
* PARAMETERS
*  scroll_p :
*  flag_init:
*  flag_scroll:        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_paint_scroll(scrolling_text* scroll_p,
                                      U32* flags,
                                      U32 flag_init, 
                                      U32 flag_move, U32 attr_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/       
    mmi_medply_rect_struct rgn;
    S32 str_w, str_h;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gui_set_text_color(scroll_p->text_color); 
    
    if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
    {
        gui_set_text_border_color(scroll_p->text_border_color);
    }
    gui_set_font(&scroll_p->text_font);
    
    rgn.x = scroll_p->x;
    rgn.y = scroll_p->y;
    rgn.w = scroll_p->width;
    rgn.h = scroll_p->height;
    
    if (!(*flags & flag_init))
    {
        *flags |= flag_init;        
        gui_measure_string(scroll_p->text, &str_w, &str_h);
        
        if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
        {/*Add Two Pixtel for text border*/
            str_w += 2;
        }
        
        if (str_w > scroll_p->width)
        {       
            if (!(*flags & flag_move))
            {
                *flags |= flag_move;
                if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL))
                {
                    gui_scrolling_text_start(scroll_p);
                }
            }
        }
        else
        {
            if (*flags & flag_move)
            {
                *flags &= ~flag_move;
                gui_scrolling_text_stop(scroll_p);                
            }
        }
    }
    if (*flags & flag_move)
    {
        /*To Show Scrolling Text*/
        gui_redraw_scrolling_text(scroll_p);
    }
    else
    {
        if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
        {
            mmi_mscr_paint_text(&rgn, &rgn, scroll_p->text, 
                (U8)(attr_draw&0xff), (U8)((attr_draw>>8)&0xff), 1, -1);
        }
        else
        {
            mmi_mscr_paint_text(&rgn, &rgn, scroll_p->text, 
                (U8)(attr_draw&0xff), (U8)((attr_draw>>8)&0xff), 0, -1);
        }
    }    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_paint_text
* DESCRIPTION
*  draw text
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_paint_text(mmi_medply_rect_struct* rgn_p,
                                    mmi_medply_rect_struct* rgn_clip_p,
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
        
    if (0 != rgn_clip_p)
    {
        gui_push_text_clip();
        gui_set_text_clip(rgn_clip_p->x-1, rgn_clip_p->y-1, 
            rgn_clip_p->x+rgn_clip_p->w+1, rgn_clip_p->y+rgn_clip_p->h+1);
    }    
    switch(attr_w)
    {
    case MMI_MSCR_TXT_DRAW_ALEFT:
        
        x = rgn_p->x;
        break;
    case MMI_MSCR_TXT_DRAW_ARIGHT:
        
        /*The Str_w may not exactly right*/
        x = rgn_p->x + (rgn_p->w - 1) - str_w;
        break;
    default:
        
        x = rgn_p->x + (rgn_p->w - str_w) / 2;
        break;
    }    
    if (r2lMMIFlag)
    {        
        x += (str_w -1);
        if (0 != use_border)
        {
            x -= 2;
        }
    } 
    
    switch(attr_h)
    {
    case MMI_MSCR_TXT_DRAW_ATOP:
        
        y = rgn_p->y;
        break;
    case MMI_MSCR_TXT_DRAW_ABOTTOM:
        
        y = rgn_p->y + (rgn_p->h - 1) - str_h;
        break;
    default:
        
        y = rgn_p->y + (rgn_p->h - str_h) / 2;
        break;
    } 
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
*  mmi_mscr_paint_image_mem
* DESCRIPTION
*  draw image from memory
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8      mmi_mscr_paint_image_mem(mmi_medply_rect_struct* rgn_p, 
                                         U8* img_p, U32 img_size,
                                         U8 img_type, U8 resize_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, resize_w, resize_h; 
    GDI_RESULT  ret_val;
    U8  gdi_img_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(img_type)
    {
    case META_TAG_IMG_PNG :     gdi_img_type = GDI_IMAGE_TYPE_PNG; break;
    case META_TAG_IMG_JPG:      gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
    case META_TAG_IMG_JPEG:     gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
    case META_TAG_IMG_GIF:      gdi_img_type = GDI_IMAGE_TYPE_GIF; break;
    case META_TAG_IMG_BMP:      gdi_img_type = GDI_IMAGE_TYPE_BMP; break;
        
    default:                    return  0;
    }
    if (0 != resize_f)
    {
        ret_val = gdi_image_get_dimension_mem(gdi_img_type, img_p, img_size,
            &w, &h);
        MMI_MSCR_MSG_TRACE(w);
        MMI_MSCR_MSG_TRACE(h);
        if (GDI_SUCCEED != ret_val)
        {
            return  0;
        }
        /*To get image fit size and offset*/
        gdi_image_util_fit_bbox(rgn_p->w, rgn_p->h,
            w, h, &x, & y, &resize_w, &resize_h);

        MMI_MSCR_MSG_TRACE(resize_w);
        MMI_MSCR_MSG_TRACE(resize_h);
        MMI_MSCR_MSG_TRACE(rgn_p->w);
        MMI_MSCR_MSG_TRACE(rgn_p->h);
        
        ret_val = gdi_image_draw_resized_mem(rgn_p->x + x, 
            rgn_p->y + y, resize_w, resize_h, img_p, gdi_img_type, img_size);   
    }
    else
    {
        ret_val = gdi_image_draw_mem(rgn_p->x, rgn_p->y, img_p, gdi_img_type,
            img_size);
    }
    if (GDI_SUCCEED != ret_val)
    {
        return  0;
    }
    return  1;
}

#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)    
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
static  void   mmi_mscr_draw_icon_bar_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;
    mmi_medply_rect_struct rgn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    rgn.x = cx1;
    rgn.y = cy1;
    rgn.w = cx2-cx1+1;
    rgn.h = cy2-cy1+1;
    mmi_mscr_beg_paint(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP], &rgn);
    mmi_mscr_end_paint();
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_unprepare
* DESCRIPTION
*  Exit main screen, call this function to release screen based memory and resource
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UNPREPARE);

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_IS_APP_DELTETING;

#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
    mmi_mscr_gesture_stop();
#endif
    /* hide popup before unprepare */
    mmi_mscr_close_popup(); 
    /*Stop Seek timer*/
    mmi_mscr_seek_end(0);    
    /*Stop OSD ani*/
    mmi_mscr_stop_osd_animation();    
    /*Stop Scroll Text and Playing timer and Spectrum and demo video Ani*/
    mmi_mscr_pause();
    /*Stop status timer*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_STATUS_TIMER)
    {
        gui_cancel_timer(mmi_mscr_update_ui_status);
    } 
    /* move flatten to ahead, due to HAL modify
     * if unprepare_view_content_before flatten, layer config will error.
     */
    gdi_layer_flatten_previous_to_base();
    mmi_mscr_unprepare_view_content();
    mmi_mscr_config_layer_blt();
    mmi_mscr_unprepare_layer();    
    mmi_mscr_enable_backlight(0);
    
    mmi_mscr_delete_handle();

    MMI_MSCR_MSG_TRACE(0);
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_prepare_view
* DESCRIPTION
*  update view content, do special init for each content 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void    mmi_medply_main_screen_prepare_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PREPARE_VIEW);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_prepare_view_content();
    mmi_mscr_config_layer_blt();  
    mmi_mscr_config_backlight();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_unprepare_view
* DESCRIPTION
*  release view content 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_unprepare_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UNPREPARE_VIEW);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_unprepare_view_content();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_redraw
* DESCRIPTION
*  redraw main screen according to current status, but not blt to lcd
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_REDRAW);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_lock_frame_buffer();
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)    
    {        
        /*Only View in Full Screen*/
        mmi_mscr_draw_view();

        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);  
    }
    else
    {
        mmi_mscr_draw_background();
        mmi_mscr_draw_title();
        mmi_mscr_draw_view();
        mmi_mscr_draw_panel();  
        
        /*Set Layer for get layer invalidate region*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_base_hdl);
    }
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_pop_and_restore_active();
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_LAYER_ROTATE)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        mmi_medply_main_screen_set_clip_rgn((S16)layer_y, (S16)layer_x,
            (S16)layer_h, (S16)layer_w);
    }
    else
    {
        mmi_medply_main_screen_set_clip_rgn((S16)layer_x, (S16)layer_y,
            (S16)layer_w, (S16)layer_h);
	}
    
    gdi_layer_unlock_frame_buffer();
    
    MMI_MSCR_MSG_TRACE(0);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_reset
* DESCRIPTION
*  reset main screen
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_RESET);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
    g_lyrics_box.line_focus_id = LYRICS_MAX_LINES;
#endif
    mmi_mscr_update_duration();
    mmi_mscr_seek_end(0);
    mmi_mscr_stop_playing();
    mmi_mscr_stop_osd_animation();
    
    mmi_medply_main_screen_redraw();
    
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER))
        {
            gui_start_timer(MMI_MSCR_UI_START_PLAY_TIME, mmi_mscr_start_playing);
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAYING_TIMER;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_delete
* DESCRIPTION
*  screen has deleted from history, call this function to release APP Based or other
*   global memory
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
U8  mmi_medply_main_screen_delete(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return  MMI_HIST_ALLOW_DELETING;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_blt
* DESCRIPTION
*  blt to LCD according to redraw function, it will have no effect when call this function
*   without any redraw happend.
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle h1,h2,h3,h4;
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == g_blt_rgn.w || 0 == g_blt_rgn.h)
    {
        MMI_MSCR_ERR_TRACE(g_blt_rgn.w);
        return;
    }
    
    if((g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN) &&
        (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER))
    {        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
        gdi_layer_get_position(&x, &y);
        gdi_layer_get_dimension(&w, &h);
        gdi_layer_pop_and_restore_active();
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_LAYER_ROTATE)
        {
            MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
            mmi_mscr_merge_blt_rgn((S16)y,(S16)x,(S16)h,(S16)w);
        }
        else
        {
            mmi_mscr_merge_blt_rgn((S16)x,(S16)y,(S16)w,(S16)h);
        }
    } 
    
    gdi_layer_blt_previous(g_blt_rgn.x, g_blt_rgn.y, g_blt_rgn.x + g_blt_rgn.w-1, 
        g_blt_rgn.y + g_blt_rgn.h-1);
    gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);
    /*mmi_frm_ui_force_update_now();*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_HDL, h1,h2,h3,h4);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_RGN, g_blt_rgn.x, g_blt_rgn.y, g_blt_rgn.w, g_blt_rgn.h);
    
    mmi_mscr_clean_blt_rgn();
    /*
    **  do init ui status in redraw function
    **  because the ui status change will caused animation or spectrum start
    **  the animation should blt better after screen has been paint.
    */
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_APP_WAITING_PLAY)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_IS_APP_WAITING_PLAY;
        if ((MMI_MEDPLY_STATUS_READY == g_mscr_hd->ui_status || 
            MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status) && 
            (MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content))
        {
            mmi_mscr_update_video_content();
        }
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, g_mscr_hd->id_animation);
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_and_draw_button
* DESCRIPTION
*  Set main screen button status and redraw button.
* PARAMETERS
*  mmi_medply_regn_id_enum      : region id or button id
*  mmi_medply_regn_status_enum  : region status       
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_set_and_draw_button(mmi_medply_regn_id_enum id,
                                                mmi_medply_regn_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL temp_flag = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_AND_DRAW_BUTTON,id,status);

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (id >= MMI_MSCR_BUTTON_ID_EX_TOTAL)
    {
        MMI_MSCR_ERR_TRACE(id);
        return;
    }
    switch(status)
    {
    case MMI_MEDPLY_RGN_STATUS_DOWN:        
        
        g_mscr_hd->rgn_push_down_id = id;
        g_mscr_hd->rgn_disable_flag[id] = 0; 
        break;
    case MMI_MEDPLY_RGN_STATUS_UP:
        
        g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;
        g_mscr_hd->rgn_disable_flag[id] = 0; 
        
        mmi_mscr_config_button_image((U8)id);
        break;
    case MMI_MEDPLY_RGN_STATUS_DISABLE:
        
        g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;
        g_mscr_hd->rgn_disable_flag[id] = 1; 
        break;
    default:
        
        ASSERT(0);
        break;
    }    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
        MMI_MSCR_MSG_TRACE(1);
        return;
    }    
    if (0 != g_mscr_hd->rgn_hide_flag[id])
    {
        MMI_MSCR_MSG_TRACE(id);
        return;
    }
    /*use same region id to ctrl difference icon*/    
    if (MMI_MSCR_CONTENT_KURO == g_mscr_hd->view_content)
    {
        if (MMI_MEDPLY_RGN_ID_SHUFFLE == id)
        {
            id = MMI_MEDPLY_RGN_ID_KURO_SHUFFLE;
            temp_flag = MMI_TRUE;
        }
        else if (MMI_MEDPLY_RGN_ID_REPEAT == id)
        {
            id = MMI_MEDPLY_RGN_ID_KURO_REPEAT;
            temp_flag = MMI_TRUE;
        }
        if (temp_flag)
        {
            switch(status)
            {
            case MMI_MEDPLY_RGN_STATUS_DOWN:
                g_mscr_hd->rgn_push_down_id = id;
                g_mscr_hd->rgn_disable_flag[id] = 0; 
                break;
            case MMI_MEDPLY_RGN_STATUS_UP:
                g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;
                g_mscr_hd->rgn_disable_flag[id] = 0; 
                break;
            case MMI_MEDPLY_RGN_STATUS_DISABLE:
                g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;
                g_mscr_hd->rgn_disable_flag[id] = 1; 
                break;
            default:
                ASSERT(0);
                break;
            }
        }
    }

    /*check if need hide popup screen before draw pen down effect*/
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {        
        MMI_MSCR_MSG_TRACE(id);
        if (id >= MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL && id <= MMI_MEDPLY_RGN_ID_VOLUME_SPEAK)
        {
            mmi_mscr_popup_restart_timer();
        }
        else if (MMI_MEDPLY_RGN_STATUS_DOWN == status)
        {
            mmi_mscr_close_popup();
        }
    }
    if (MMI_MEDPLY_RGN_STATUS_DOWN == status)
    {
        if (g_mscr_ui.touch_btn[g_mscr_hd->rgn_push_down_id].up_img_id == 
            g_mscr_ui.touch_btn[g_mscr_hd->rgn_push_down_id].down_img_id)
        {
            /*hilight only support 16 color layer now!*/
            mmi_mscr_prepare_hilight(g_mscr_hd->rgn_push_down_id);
        }
    }
    else
    {
        mmi_mscr_unprepare_hilight();
    }   
    mmi_mscr_draw_button_id((U8)id);    
    MMI_MSCR_MSG_TRACE(2);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_show_volme_tuning
* DESCRIPTION
*  show volume tuning screen  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
MMI_BOOL    mmi_medply_main_screen_show_volme_tuning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    bRet, bBlt = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return  MMI_FALSE;
    }
   
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    if(MMI_TRUE == mmi_inline_has_subtitle())
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return  MMI_TRUE;
    }
    #endif
   
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {    
        if (g_mscr_hd->popup_type == MMI_MSCR_POPUP_TYPE_VOLUME)
        {
            MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
            mmi_mscr_popup_restart_timer();
            return  MMI_TRUE;
        }
        mmi_mscr_close_popup();
        bBlt = MMI_TRUE;
    }
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);

    g_mscr_hd->popup_type = MMI_MSCR_POPUP_TYPE_VOLUME;
    bRet = mmi_mscr_open_popup();  
    MMI_MSCR_ERR_TRACE(bRet);
    if (bRet || bBlt)
    {
        mmi_medply_main_screen_blt();
    }
    return  bRet;    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_update_mute
* DESCRIPTION
*  update mute button  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_update_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    
    
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    if(MMI_TRUE == mmi_inline_has_subtitle())
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    #endif
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)    
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_popup_hdl)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }    
    if (g_mscr_hd->popup_type != MMI_MSCR_POPUP_TYPE_VOLUME)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
        return;
    }
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);
    mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);  
    mmi_mscr_popup_restart_timer();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_update_vol
* DESCRIPTION
*  update volume bar  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void    mmi_medply_main_screen_update_vol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 volume;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    

    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    if(MMI_TRUE == mmi_inline_has_subtitle())
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    #endif
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)    
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_popup_hdl)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }    
    if (g_mscr_hd->popup_type != MMI_MSCR_POPUP_TYPE_VOLUME)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
        return;
    }
    volume = mmi_inline_get_volume_level();
    mmi_mscr_draw_popup_volume(volume, 0);
    mmi_mscr_popup_restart_timer();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_update_touch_volume
* DESCRIPTION
*  Show user rating popup setting screen. 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
 *****************************************************************************/
U8   mmi_medply_main_screen_update_touch_volume(S16 x, U8 is_hilight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, interval;
    S32 temp_volume;
    U8  volume;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    volume = mmi_inline_get_volume_level();

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return  volume;
    }    

    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    if(MMI_TRUE == mmi_inline_has_subtitle())
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return  volume;
    }
    #endif
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)    
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return  volume;
    }
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_popup_hdl)
    {
        MMI_MSCR_ERR_TRACE(0);
        return  volume;
    }    
    if (g_mscr_hd->popup_type != MMI_MSCR_POPUP_TYPE_VOLUME)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
        return  volume;
    }    
    gdi_image_get_dimension_id(g_mscr_ui.volume_img.fg_img_id, &w, &h);
    interval = w/MDI_AUD_VOL_EX_MUTE_MAX;
    temp_volume = (x - g_mscr_ui.volume_img.view_x + interval/2)*MDI_AUD_VOL_EX_MUTE_MAX/w;
    if (temp_volume < 0)
    {
        volume = 0;
    }
    else if (temp_volume > MDI_AUD_VOL_EX_MUTE_MAX)
    {
        volume = MDI_AUD_VOL_EX_MUTE_MAX;
    }
    else
    {
        volume = (U8)temp_volume;
    }
    mmi_mscr_draw_popup_volume(volume, is_hilight);
    mmi_mscr_popup_restart_timer();

    MMI_MSCR_MSG_TRACE(volume);
    
    return volume;   
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_show_kuro_setting
* DESCRIPTION
*  show kuro settings
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
MMI_BOOL    mmi_medply_main_screen_show_kuro_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    bRet, bBlt = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return  MMI_FALSE;
    }
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {    
        if (g_mscr_hd->popup_type == MMI_MSCR_POPUP_TYPE_KURO)
        {
            MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
            mmi_mscr_popup_restart_timer();
            return  MMI_TRUE;
        }
        mmi_mscr_close_popup();
        bBlt = MMI_TRUE;
    }    
    /* Need check active key states, every time show kuro settings*/
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_SNAPSHOT))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
    }
    else
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 0;
    }
    #ifdef __MMI_AUDIO_PITCH_SHIFTING__
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PITCH_INC))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PITCH_INC] = 1;
    }
    else
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PITCH_INC] = 0;
    }
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PITCH_DEC))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PITCH_DEC] = 1;
    }
    else
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PITCH_DEC] = 0;
    }
    #endif

    g_mscr_hd->popup_type = MMI_MSCR_POPUP_TYPE_KURO;

    bRet = mmi_mscr_open_popup();  
    MMI_MSCR_MSG_TRACE(bRet);    
    if (bRet || bBlt)
    {
        mmi_medply_main_screen_blt();
    }
    return  bRet;    
}
#ifdef __MMI_AUDIO_PITCH_SHIFTING__
/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_tune
* DESCRIPTION
*  redraw volume  
* PARAMETERS
*  volume: level for display        
* RETURNS
*  void
 *****************************************************************************/
void    mmi_medply_main_screen_draw_tune(S16 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}
#endif /*__MMI_AUDIO_PITCH_SHIFTING__*/

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_show_user_rating
* DESCRIPTION
*  Show user rating popup setting screen. 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
*****************************************************************************/
MMI_BOOL  mmi_medply_main_screen_show_user_rating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    bRet, bBlt = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return  MMI_FALSE;
    }
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {    
        if (g_mscr_hd->popup_type == MMI_MSCR_POPUP_TYPE_RATING)
        {
            MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
            mmi_mscr_popup_restart_timer();
            return  MMI_TRUE;
        }
        mmi_mscr_close_popup();
        bBlt = MMI_TRUE;
    }    
    g_mscr_hd->popup_type = MMI_MSCR_POPUP_TYPE_RATING;
    
    bRet = mmi_mscr_open_popup();  
    MMI_MSCR_MSG_TRACE(bRet);    
    if (bRet || bBlt)
    {
        mmi_medply_main_screen_blt();
    }
    return  bRet;  
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_update_rating
* DESCRIPTION
*  Show user rating popup setting screen. 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
*****************************************************************************/
U8 mmi_medply_main_screen_update_rating(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rating;
    S32 fg_w, fg_h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return g_mscr_hd->meta_p->meta_data.user_rating;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)    
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return  g_mscr_hd->meta_p->meta_data.user_rating;
    }
    if (GDI_NULL_HANDLE == g_mscr_hd->layer_popup_hdl)
    {
        MMI_MSCR_ERR_TRACE(0);
        return  g_mscr_hd->meta_p->meta_data.user_rating;
    }    
    if (g_mscr_hd->popup_type != MMI_MSCR_POPUP_TYPE_RATING)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
        return  g_mscr_hd->meta_p->meta_data.user_rating;
    }    
    /*2 for border check, if touch in the start, then hilight it*/
    rating  = ((x - g_mscr_ui.rating_img.view_x) + 
        (g_mscr_ui.rating_img.star_w + g_mscr_ui.rating_img.interval - 2)) /
        (g_mscr_ui.rating_img.star_w + g_mscr_ui.rating_img.interval);
    
    /*add check to forbid invalid value*/
    if (rating < 0)
    {
        rating  = 0;
    }
    if (rating > 5)
    {
        rating = 5;
    }
    if (rating != g_mscr_ui.rating_img.temp_val)
    {
        g_mscr_ui.rating_img.temp_val = rating;

        gdi_layer_push_and_set_active(g_mscr_hd->layer_popup_hdl); 
        mmi_mscr_paint_popup_userate_bar(rating);
        gdi_layer_pop_and_restore_active();

        gdi_image_get_dimension_id(g_mscr_ui.rating_img.fg_img_id, &fg_w, &fg_h);

        mmi_mscr_merge_blt_rgn(g_mscr_ui.rating_img.view_x, 
            g_mscr_ui.rating_img.view_y, (S16)fg_w, (S16)fg_h);
    }    
    mmi_medply_main_screen_blt();
    mmi_mscr_popup_restart_timer();

    MMI_MSCR_MSG_TRACE(g_mscr_ui.rating_img.temp_val);

    return  g_mscr_ui.rating_img.temp_val;
#else
    return 0;
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_duration
* DESCRIPTION
*  redraw duration  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void    mmi_medply_main_screen_draw_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_DURATION);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_update_duration();
    mmi_mscr_draw_duration();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_cache
* DESCRIPTION
*  redraw cache bar  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_draw_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct  rgn_bar;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_CACHE);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG))
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        /*do not update anything when background has not ready, this should be main screen has not been redraw*/
        return;
    }
    if (g_mscr_hd->flags & 
        (MMI_MSCR_HD_HAS_UPDATE_PLAY_TIMER|MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER))
    {
        /*do not update anything in timer update*/
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    rgn_bar.x = 0;
    rgn_bar.y = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.y;
    rgn_bar.w = GDI_LCD_WIDTH;
    rgn_bar.h = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.h+1;
    
    mmi_mscr_beg_paint(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_PANEL], &rgn_bar);
    mmi_mscr_paint_duration_bar();
    mmi_mscr_end_paint();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_lkey_down
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_draw_lkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_LKEY, 
        MMI_MEDPLY_RGN_STATUS_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_lkey_up
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_draw_lkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_LKEY, 
        MMI_MEDPLY_RGN_STATUS_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_rkey_down
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_draw_rkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_RKEY, 
        MMI_MEDPLY_RGN_STATUS_DOWN);
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_lkey_up
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_draw_rkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_RKEY, 
        MMI_MEDPLY_RGN_STATUS_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_video_updated
* DESCRIPTION
*  for video play layer need update, set video layer region to blt 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_video_updated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_VIDEO_UPDATE);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
	/*
    if (MMI_MSCR_CONTENT_VIDEO != g_mscr_hd->view_content)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->view_content);
        return;
    }*/

	if(g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO_DEMO)
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
	    {
	        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
	    }
	    else
	    {
	        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
	    } 
		gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
	    gdi_layer_pop_and_restore_active();
    }

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    }
    //gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_pop_and_restore_active();
    
    MMI_MSCR_MSG_TRACE(layer_w);
    MMI_MSCR_MSG_TRACE(layer_h);
   
    if (layer_w > 0 && layer_h > 0)
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_LAYER_ROTATE)
        {
            MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
            mmi_mscr_merge_blt_rgn((S16)layer_y, (S16)layer_x, 
                (S16)layer_h, (S16)layer_w);
        }
        else
        {
            mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, 
                (S16)layer_w, (S16)layer_h);
        }        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_clear_video_layer
* DESCRIPTION
*  clear video play layer from main screen 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_clear_video_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32     layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CLEAR_VIDEO_LAYER);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (MMI_MSCR_CONTENT_VIDEO != g_mscr_hd->view_content)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->view_content);
        return;
    }
    /* HAL */
    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();
    
/*
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    }   
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();
    
    MMI_MSCR_MSG_TRACE(layer_w);
    MMI_MSCR_MSG_TRACE(layer_h);
    
    if (layer_w > 0 && layer_h > 0)
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_LAYER_ROTATE)
        {
            MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
            mmi_mscr_merge_blt_rgn((S16)layer_y, (S16)layer_x, 
                (S16)layer_h, (S16)layer_w);
        }
        else
        {
            mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, 
                (S16)layer_w, (S16)layer_h);
        }      
    }
*/
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_get_video_layer
* DESCRIPTION
*  get video play layer from main screen 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void    mmi_medply_main_screen_get_video_parameter(mmi_medply_video_play_para_struct* video_layer_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 video_w, video_h;
    U8  flags;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_GET_PARAMETER);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (NULL == video_layer_info_p)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    mmi_mscr_update_video_content();
    
    MMI_MSCR_MSG_TRACE(video_layer_info_p->video_width);
    MMI_MSCR_MSG_TRACE(video_layer_info_p->video_height);
    
    video_w = g_mscr_hd->video_p->video_width;
    video_h = g_mscr_hd->video_p->video_height;
    g_mscr_hd->video_p->video_width   =  video_layer_info_p->video_width;
    g_mscr_hd->video_p->video_height  =  video_layer_info_p->video_height;
    
    kal_mem_cpy(video_layer_info_p, g_mscr_hd->video_p, 
        sizeof(mmi_medply_video_play_para_struct));
    
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    if(MMI_FALSE == mmi_inline_has_subtitle())
    {
        video_layer_info_p->layer_subtitle_hdl = GDI_NULL_HANDLE;
        MMI_MSCR_MSG_TRACE(0);
    }
    else
    {
    /* MAUI_03185572, need valid subtitle handle if subtitle present *
     * but it is not configured along with OSD animation image       */
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
        video_layer_info_p->layer_subtitle_hdl = g_mscr_hd->layer_subtitle_hdl;
    }
    #endif

    
    if (MMI_MSCR_CONTENT_VIDEO != g_mscr_hd->view_content)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->view_content);
        return;
    }    
    
    if (0 == g_mscr_hd->video_p->video_width ||
        0 == g_mscr_hd->video_p->video_height)
    {
        MMI_MSCR_MSG_TRACE(0);
        return;
    }
    //HAL    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        flags = MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
    }
    else
    {
        flags = MMI_MSCR_HD_VID_HAS_RESIZE_LAYER;
    }
    if ((g_mscr_hd->video_flags & flags) && 
        (g_mscr_hd->video_p->video_width == video_w) &&
        (g_mscr_hd->video_p->video_height == video_h))
    {
        MMI_MSCR_MSG_TRACE(0);
        return;
    }
    
    mmi_mscr_resize_video_layer();   
}    

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_clip_rgn
* DESCRIPTION
*  used for blt to lcd, if rgn w and h <= 0, will do nothing;
*  default clip region will get from redraw regions 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
*****************************************************************************/
void    mmi_medply_main_screen_set_clip_rgn(S16 x, S16 y, S16 w, S16 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_CLIP_RGN, x,y,w,h);
    
    g_blt_rgn.x = x;
    g_blt_rgn.y = y;
    g_blt_rgn.w = w;
    g_blt_rgn.h = h;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_prepare_full_scr
* DESCRIPTION
*  prepare full screen UI
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_prepare_full_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PREPARE_FULL_SCREEN);
    
    /*Change to Full Screen, pause main screen first*/
    mmi_mscr_pause();

    //HAL
#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)    
    g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
    g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
#else
    g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
    g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
#endif
    mmi_mscr_prepare_hw_video_layer(MMI_TRUE);
    
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    /*Icon Bar default is show, need hide it when change to full screen*/
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
#endif     
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_FULL_SCREEN;

    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
    {
        g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
    }

/* 
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
    {
    #if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_BUFFER)
        g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
    #else
        g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
    #endif

        g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
    }
    else
    {
#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)    
        g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
#else
        g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
#endif
    }
*/
    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    gdi_layer_set_position(0, 0); 
    gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND); 
    gdi_layer_pop_and_restore_active();

    /* HAL */
    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
    gdi_layer_set_position(0, 0); 
    gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_config_layer_blt();
        
    switch(g_mscr_hd->view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_config_lyrics();
        mmi_mscr_update_lyrics();
        break;        
#endif   
    case MMI_MSCR_CONTENT_NULL:
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
    case MMI_MSCR_CONTENT_VIDEO_NULL:
    default:
        break;
    }
    mmi_mscr_resume();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_reprepae_full_scr
* DESCRIPTION
*  reprepare full screen UI
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_mscr_reprepae_full_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 layer_full_scr_w, layer_full_scr_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_MSCR_MSG_TRACE(g_mscr_hd->flags); 
    layer_full_scr_w = g_mscr_hd->layer_full_scr_w;
    layer_full_scr_h = g_mscr_hd->layer_full_scr_h;

/* HAL */ 
#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)    
    g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
    g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
#else
    g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
    g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
#endif
    /*
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
    {
    #if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_BUFFER)
        g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
    #else
        g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
    #endif

    }
    else
    {
    #if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)    
        g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
    #else
        g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
        g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
    #endif
    }
    */
    if (layer_full_scr_w != g_mscr_hd->layer_full_scr_w || layer_full_scr_h != g_mscr_hd->layer_full_scr_h)
    {
        g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
        gdi_layer_set_position(0, 0); 
        gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND); 
        gdi_layer_pop_and_restore_active();
        /* HAL */
        gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl);
        gdi_layer_set_position(0, 0); 
        gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND); 
        gdi_layer_pop_and_restore_active();
        
        mmi_mscr_config_layer_blt();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_unprepare_full_scr
* DESCRIPTION
*  restore normal screen ui
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_unprepare_full_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UNPREPARE_FULL_SCREEN);
    
    /*Change from Full Screen, pause main screen first*/
    mmi_mscr_pause();

    //HAL
    mmi_mscr_prepare_hw_video_layer(MMI_FALSE);
    
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)    
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
 #endif   
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_FULL_SCREEN;
    mmi_mscr_update_duration();
    
    switch(g_mscr_hd->view_content)
    {
    case MMI_MSCR_CONTENT_METAINFO:
         /* Due to artwork memory buffer overlap with subtitle layer buffer, so need to reprepare meta */
        if ((g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_ARTWORK) && 
            !(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK))
        {       
            g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_READY;
            mmi_mscr_prepare_meta();
        }
        break;
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_config_lyrics();
        mmi_mscr_update_lyrics();
        break;        
#endif       
    case MMI_MSCR_CONTENT_SPECTRUM: 
    case MMI_MSCR_CONTENT_NULL: 
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_layer_pop_and_restore_active();
        break;
	case MMI_MSCR_CONTENT_VIDEO_NULL:  
    case MMI_MSCR_CONTENT_VIDEO:
		gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hdl); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_layer_pop_and_restore_active();
		break;
    default:	
        break;
    }
    mmi_mscr_resume();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_full_screen
* DESCRIPTION
*  
* PARAMETERS
*  full_f       
* RETURNS
*  layer handle
 *****************************************************************************/
extern void mmi_medply_main_screen_set_full_screen(MMI_BOOL full_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    bChange = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_FULL_SCREEN, full_f);

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }

    /*stop gesture*/
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
    mmi_mscr_gesture_stop();
#endif
    mmi_mscr_close_popup();
    
    if ((MMI_MEDPLY_STATUS_READY == g_mscr_hd->ui_status || 
         MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status) && 
        (MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content))
    {
        mmi_mscr_update_video_content();
    }

    if (full_f)
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
        {           
            bChange = MMI_TRUE;
            /*KURO Mode need redraw background*/
            mmi_mscr_prepare_full_scr();            
        }
    }
    else
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {     
            bChange = MMI_TRUE;
            /*KURO Mode need redraw background*/
            mmi_mscr_unprepare_full_scr();            
        }
    }  
    if (bChange)
    {
        mmi_mscr_config_layer_rotate();
        mmi_mscr_config_layer_blt();
        /*
        **  For Full video Layer has use same buffer with title/view/pannel layers
        **  So when change full screen status, need clear layer first.
        **  Clear layer buffer will do in mmi_medply_main_screen_redraw
        */
        mmi_mscr_reprepare_osd_layer();
        mmi_medply_main_screen_redraw();        
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_get_pt_rgn
* DESCRIPTION
*  get point touched region
* PARAMETERS
*  void       
* RETURNS
*  mmi_medply_regn_id_enum
 *****************************************************************************/
U8   mmi_medply_main_screen_get_pt_rgn(mmi_pen_point_struct pt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct tmp_rgn;
    S32 temp_id, is_in_popup;
    S32 i = MMI_MEDPLY_RGN_ID_NULL;
#ifndef MMI_MEDPLY_TOUCH_ICON_ONLY
    S32 img_w, img_h;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*In gesture progress, do not allow touch*/

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return  MMI_MEDPLY_RGN_ID_NULL;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        return  MMI_MEDPLY_RGN_ID_NULL;
    }
    /*User press ctrl panel*/
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {
        /*find touch in popup screen*/
        is_in_popup = 0;

        switch(g_mscr_hd->popup_type)
        {
        case MMI_MSCR_POPUP_TYPE_RATING:

            if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.popup_rgn[g_mscr_hd->popup_type]))
            {
                is_in_popup = 1;
                i = MMI_MEDPLY_RGN_ID_MODIFY_RATING;
            }
            break;
        case MMI_MSCR_POPUP_TYPE_VOLUME:

            if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.popup_rgn[g_mscr_hd->popup_type]))
            {                
#ifdef MMI_MEDPLY_TOUCH_ICON_ONLY
                if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn))
                {
                    i = MMI_MEDPLY_RGN_ID_VOLUME_BAR;
                }
#else
                gdi_image_get_dimension_id(g_mscr_ui.volume_img.fg_img_id, &img_w, &img_h);

                tmp_rgn.x = g_mscr_ui.volume_img.view_x;
                tmp_rgn.y = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.y;
                tmp_rgn.w = img_w;
                tmp_rgn.h = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.h;
                if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &tmp_rgn))
                {
                    i = MMI_MEDPLY_RGN_ID_VOLUME_BAR;
                }
#endif
                is_in_popup = 1;
            }   
            break;
        case MMI_MSCR_POPUP_TYPE_KURO:

            if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.popup_rgn[g_mscr_hd->popup_type]))
            {
                for (temp_id = MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL; temp_id < MMI_MEDPLY_RGN_ID_ACTIVATE + 1; temp_id++)
                {
                    if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.touch_btn[temp_id].pen_rgn))
                    {
                        i = temp_id;
                        break;
                    }
                }
                is_in_popup = 1;
            }
            break;
        default:
            /*touch out of popup region, popup need fade away*/
            break;
        }
        if (0 != is_in_popup)
        {
            if (MMI_MEDPLY_RGN_ID_NULL == i)
            {
                i = MMI_MEDPLY_RGN_ID_POPUP;
            }
            mmi_mscr_popup_restart_timer();
        }
        return  i;
    }

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
    {
        tmp_rgn.x = g_medply_fte_skin.wait_ani_bg_x;
        tmp_rgn.y = g_medply_fte_skin.wait_ani_bg_y;
        tmp_rgn.w = g_medply_fte_skin.wait_ani_bg_w;
        tmp_rgn.h = g_medply_fte_skin.wait_ani_bg_h;
        if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &tmp_rgn))
        {
            return  MMI_MEDPLY_RGN_ID_NULL;
        }
    }

    /*find in panel*/
    if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL]))
    {
        /*for (i = MMI_MSCR_BUTTON_IN_PANEL_BEGIN; i < MMI_MSCR_BUTTON_IN_PANEL_TOTAL; i++)*/
        for (i = MMI_MEDPLY_RGN_ID_PLAY_PAUSE; i <= MMI_MEDPLY_RGN_ID_DURATION_BAR; i++)        
        {
            if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.touch_btn[i].pen_rgn))
            {
                return  i;
            }
        }
#ifndef MMI_MEDPLY_TOUCH_ICON_ONLY
        gdi_image_get_dimension_id(g_mscr_ui.duration_img.fg_img_id, &img_w, &img_h);
        tmp_rgn.x = g_mscr_ui.duration_img.view_x;
        tmp_rgn.y = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.y;
        tmp_rgn.w = img_w;
        tmp_rgn.h = g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.h;

        if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &tmp_rgn))
        {
            return MMI_MEDPLY_RGN_ID_DURATION_BAR;
        }
#endif
    }
    /*find in audio meta view*/
    else if(mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW])) 
    {
        if (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture)
        {/*In gesture progress, do not allow tap on !*/
            MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_gesture);
            return  MMI_MEDPLY_RGN_ID_NULL;
        }
        if (g_mscr_hd->view_content == MMI_MSCR_CONTENT_METAINFO)
        {
            for (i = MMI_MSCR_BUTTON_IN_VIEW_BEGIN ; i < MMI_MSCR_BUTTON_IN_VIEW_TOTAL; i++)
            {
                if (mmi_mscr_is_pt_in_rgn(pt.x, pt.y, &g_mscr_ui.touch_btn[i].pen_rgn) &&
                   (1 != g_mscr_hd->rgn_hide_flag[i]))
                {
                    return  i;
                }
            }     
        }
    }
    return  MMI_MEDPLY_RGN_ID_NULL;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_pen_down
* DESCRIPTION
*  pause currently play timer, to whether need start seeking timer  
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_duration_pen_down(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct rgn;
    S32 w,h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_ui.duration_img.fg_range > g_mscr_ui.duration_img.md_range )
    {
        MMI_MSCR_ERR_TRACE(g_mscr_ui.duration_img.fg_range);
        MMI_MSCR_ERR_TRACE(g_mscr_ui.duration_img.md_range);
    }
    
    gdi_image_get_dimension_id(g_mscr_ui.duration_img.fg_img_id, &w, &h);
    rgn.x = g_mscr_ui.duration_img.view_x;
    rgn.y = g_mscr_ui.duration_img.view_y;
    rgn.w = w;
    rgn.h = h;
    
    g_mscr_hd->seek_duration_dst_range = mmi_mscr_get_pt_range(x, &rgn);

    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_WITH_PEN;
    
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].up_img_id   
        = g_medply_fte_skin.duration_btn_img_hl_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].down_img_id     
        = g_medply_fte_skin.duration_btn_img_hl_id;    
    
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);    
    mmi_mscr_seek_begin();   
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_pen_move
* DESCRIPTION
*  change video layer to full screen or not 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_duration_pen_move(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct rgn;
    S32 w,h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    
    gdi_image_get_dimension_id(g_mscr_ui.duration_img.fg_img_id, &w, &h);
    rgn.x = g_mscr_ui.duration_img.view_x;
    rgn.y = g_mscr_ui.duration_img.view_y;
    rgn.w = w;
    rgn.h = h;
    
    g_mscr_hd->seek_duration_dst_range = mmi_mscr_get_pt_range(x, &rgn);   
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    mmi_mscr_seek_update();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_pen_up
* DESCRIPTION
*  seek with pen touch, pen up action 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_duration_pen_up(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct rgn;
    S32 w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }    
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].up_img_id   
        = g_medply_fte_skin.duration_btn_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].down_img_id     
        = g_medply_fte_skin.duration_btn_img_id;
    
    gdi_image_get_dimension_id(g_mscr_ui.duration_img.fg_img_id, &w, &h);
    rgn.x = g_mscr_ui.duration_img.view_x;
    rgn.y = g_mscr_ui.duration_img.view_y;
    rgn.w = w;
    rgn.h = h;
    
    g_mscr_hd->seek_duration_dst_range = mmi_mscr_get_pt_range(x, &rgn);

    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);    
    mmi_mscr_seek_end(1);
}
#endif  /*#ifdef __MMI_TOUCH_SCREEN__*/

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_seek_prev
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void    mmi_medply_main_screen_duration_seek_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->seek_duration_dst_range = 0;
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_WITH_KEY;
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    
    mmi_mscr_seek_begin(); 
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_seek_next
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void    mmi_medply_main_screen_duration_seek_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->seek_duration_dst_range = 100;
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_WITH_KEY;
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    
    mmi_mscr_seek_begin(); 
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_seek_done
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void    mmi_medply_main_screen_duration_seek_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }  
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }    
    /*will clear seeking flags in end function*/
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    
    mmi_mscr_seek_end(1);  
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_seek_begin
* DESCRIPTION
*  begin seek 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_seek_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U64 dst_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Stop playing first*/
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_stop_playing();
    }  
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER;
        gui_cancel_timer(mmi_mscr_update_seeking);
    }
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();
    g_mscr_hd->duration = mmi_inline_get_duration();
    g_mscr_hd->seektime = g_mscr_hd->playtime;
    dst_time = g_mscr_hd->seek_duration_dst_range*g_mscr_hd->duration/100;
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        if (g_mscr_ui.duration_img.md_range < 100)
        {
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER;
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);
        }
        if (g_mscr_hd->playtime != dst_time)
        {
            if (g_mscr_hd->seek_duration_dst_range <= g_mscr_ui.duration_img.md_range)
            {
                g_mscr_ui.duration_img.fg_range = g_mscr_hd->seek_duration_dst_range;
                g_mscr_hd->playtime = g_mscr_ui.duration_img.fg_range*g_mscr_hd->duration/100;
            }
            else if (g_mscr_ui.duration_img.fg_range > g_mscr_ui.duration_img.md_range)
            {
            /*  if g_mscr_ui.duration_img.fg_range == g_mscr_ui.duration_img.md_range
            *   do not update play tim
                */
                g_mscr_ui.duration_img.fg_range = g_mscr_ui.duration_img.md_range;
                g_mscr_hd->playtime = g_mscr_ui.duration_img.fg_range*g_mscr_hd->duration/100;
            }
            mmi_mscr_update_view_content(1);
        }
        else
        {
            mmi_mscr_update_view_content(0);
        }
    }
    else if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        if ((g_mscr_hd->playtime != dst_time) ||
            (g_mscr_ui.duration_img.md_range < 100))
        {   
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER;
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_seek_end
* DESCRIPTION
*  seek end 
* PARAMETERS
*  is_resume        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_seek_end(U8 is_resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U32 has_begin = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        has_begin |= MMI_MSCR_HD_HAS_SEEKING_WITH_KEY;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        has_begin |= MMI_MSCR_HD_HAS_SEEKING_WITH_PEN;
    }
    if (0 == has_begin)
    {
        MMI_MSCR_ERR_TRACE(has_begin);
        return;
    }
    g_mscr_hd->flags &= ~has_begin;
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_UPDATE_SEEK_TIMER;
        gui_cancel_timer(mmi_mscr_update_seeking);
    }
    mmi_inline_set_playtime(g_mscr_hd->playtime);
    
    if (0 != is_resume && MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER))
        {
            gui_start_timer(MMI_MSCR_UI_START_PLAY_TIME, mmi_mscr_start_playing);
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAYING_TIMER;
        }
    }    
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_seek_update
* DESCRIPTION
*  begin seek 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_seek_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U64         dst_time, play_time;
    U32         step;
    MMI_BOOL    isforward = MMI_TRUE;
    U8          fg_range, md_range, update_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    md_range = g_mscr_ui.duration_img.md_range;
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();
    /*For duration may change in build cache*/
    g_mscr_hd->duration = mmi_inline_get_duration();

    MMI_MSCR_MSG_TRACE(g_mscr_hd->duration);
    
    dst_time = g_mscr_hd->seek_duration_dst_range*g_mscr_hd->duration/100;
    update_content = 0;/*default: not to update content in seeking*/
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {       
        if (g_mscr_hd->playtime != dst_time)
        {            
            if (g_mscr_hd->seek_duration_dst_range <= g_mscr_ui.duration_img.md_range)
            {
                update_content = 1;
                g_mscr_ui.duration_img.fg_range = g_mscr_hd->seek_duration_dst_range;
                g_mscr_hd->playtime = g_mscr_ui.duration_img.fg_range*g_mscr_hd->duration/100;
            }
            else if (g_mscr_ui.duration_img.fg_range != g_mscr_ui.duration_img.md_range)
            {
                g_mscr_ui.duration_img.fg_range = g_mscr_ui.duration_img.md_range;
                /*MAUI_01835043, can get exact playtime*/
                g_mscr_hd->playtime = g_mscr_hd->cachetime;
                if (g_mscr_hd->playtime - g_mscr_hd->seektime >= MMI_MSCR_UI_UPDATE_SEEK_CONTENT)
                {
                    MMI_MSCR_MSG_TRACE(g_mscr_ui.duration_img.md_range);
                    g_mscr_hd->seektime = g_mscr_hd->playtime;
                    update_content = 1;
                }
            }            
            mmi_mscr_update_view_content(update_content);
        }
        else if (md_range < 100)
        {
            /*To speed draw image to layer*/
            mmi_mscr_update_view_content(0);
        }
    }
    else if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        if (g_mscr_hd->playtime != dst_time) 
        {   
            play_time = g_mscr_hd->playtime;
            step = mmi_inline_get_cache_step();
            if (play_time < dst_time)
            {
                isforward = MMI_TRUE;
                if (play_time + step < dst_time)
                {
                    play_time += step;
                }
                else
                {
                    play_time = dst_time;
                }
            }
            else if (play_time > dst_time)
            {
                isforward = MMI_FALSE;
                if (play_time > step)
                {
                    play_time -= step;
                }
                else
                {
                    play_time = 0;
                }
            }          
            if (g_mscr_hd->duration > 0)
            {
                fg_range = (U8)(play_time*100/g_mscr_hd->duration);
            }
            else
            {
                MMI_MSCR_ERR_TRACE(g_mscr_hd->duration);
                fg_range = 0;
            } 
            if (fg_range <= g_mscr_ui.duration_img.md_range)
            {
                g_mscr_ui.duration_img.fg_range = fg_range;
                g_mscr_hd->playtime = play_time;
                if (g_mscr_hd->playtime > g_mscr_hd->seektime)
                {
                    if (g_mscr_hd->playtime - g_mscr_hd->seektime >= 
                        MMI_MSCR_UI_UPDATE_SEEK_CONTENT)
                    {
                        g_mscr_hd->seektime = g_mscr_hd->playtime;
                        update_content = 1;
                    }
                }
                else
                {
                    if (g_mscr_hd->seektime - g_mscr_hd->playtime >= 
                        MMI_MSCR_UI_UPDATE_SEEK_CONTENT)
                    {
                        g_mscr_hd->seektime = g_mscr_hd->playtime;
                        update_content = 1;
                    }
                }
                if (g_mscr_hd->playtime == dst_time)
                {
                    update_content = 1;
                }
                /*MAUI_01835043, can get exact playtime*/
                if ((fg_range == g_mscr_ui.duration_img.md_range) && isforward)
                {
                    if (g_mscr_hd->cachetime >= g_mscr_hd->playtime)
                    {
                        g_mscr_hd->playtime = g_mscr_hd->cachetime;
                        if (g_mscr_hd->seektime != g_mscr_hd->playtime)
                        {
                            MMI_MSCR_MSG_TRACE(g_mscr_ui.duration_img.md_range);
                            g_mscr_hd->seektime = g_mscr_hd->playtime;
                            update_content = 1;                            
                         }
                    }
                    else
                    {
                        g_mscr_hd->playtime = g_mscr_hd->cachetime;
                        MMI_MSCR_ERR_TRACE(g_mscr_hd->playtime);
                        MMI_MSCR_ERR_TRACE(g_mscr_hd->cachetime);
                    }
                }
                mmi_mscr_update_view_content(update_content);
            }
        }
        else if (md_range < 100)
        {
            /*To speed draw image to layer*/
            mmi_mscr_update_view_content(0);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_seeking
* DESCRIPTION
*  update seek timer 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_update_seeking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U64 dst_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        if (g_mscr_ui.duration_img.md_range < 100)
        {
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);            
            mmi_mscr_seek_update();
        }        
    }
    else if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        dst_time = g_mscr_hd->seek_duration_dst_range*g_mscr_hd->duration/100;
        
        if ((g_mscr_hd->playtime != dst_time) ||
            (g_mscr_ui.duration_img.md_range < 100))
        {   
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);
            mmi_mscr_seek_update();
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_show_loading
* DESCRIPTION
*  show animation loading
* PARAMETERS
*  percent:  loading percentage 
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_show_loading(U8 percent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  is_update = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SHOW_LOADING, percent);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    } 
    if (percent > 100)
    {
        MMI_MSCR_ERR_TRACE(percent);
        return;
    }
    g_mscr_hd->loading_percent = percent;

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
    {
        if (MMI_MEDPLY_ANI_LOADING == g_mscr_hd->id_animation)
        {
            is_update = 1;            
        }
    }
    if (0 == is_update)
    {
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, MMI_MEDPLY_ANI_LOADING);
    }
    else
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG_OSD_ANI;
    }     
    mmi_medply_main_screen_blt();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_hide_loading
* DESCRIPTION
*   
* PARAMETERS
*  animation:      [IN]
* RETURNS
*  void
*****************************************************************************/
void    mmi_medply_main_screen_hide_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_medply_main_screen_stop_animation(MMI_MEDPLY_ANI_LOADING);
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_play_animation
* DESCRIPTION
*   
* PARAMETERS
*  animation:      [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_medply_main_screen_play_animation(U8 animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PLAY_ANI, animation);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (animation < MMI_MEDPLY_ANI_LOADING || 
        animation > MMI_MEDPLY_ANI_SNAP_SHOT)
    {
        MMI_MSCR_ERR_TRACE(animation);
        return;
    }
    mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, animation);   
    mmi_medply_main_screen_blt();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_stop_animation
* DESCRIPTION
*   
* PARAMETERS
*  animation:      [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_stop_animation(U8 animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_ANI);
    MMI_MSCR_MSG_TRACE(animation);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    /*has animation*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)
    {
        if (animation != g_mscr_hd->id_animation)
        {
            MMI_MSCR_ERR_TRACE(g_mscr_hd->id_animation);
        }        
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, MMI_MEDPLY_ANI_NULL);  
        mmi_medply_main_screen_blt();
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_widget_callback_hdlr
* DESCRIPTION
*   
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/ 
static void mmi_medply_main_screen_widget_callback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.widget_callback != NULL)
    {
        g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK,NULL);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_file_path
* DESCRIPTION
*   
* PARAMETERS
*  status:      [IN]
*  ani:         [IN]
* RETURNS
*  void
*****************************************************************************/ 
void    mmi_medply_main_screen_set_file_path(U16* filename, MMI_BOOL file_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_FILE_PATH);
    if(g_medply.widget_callback != NULL)
    {
        StartTimer(MEDPLY_WIDGET_CALLBACK_TIMER, 0,mmi_medply_main_screen_widget_callback_hdlr);
    }

    #ifdef __MMI_NCENTER_SUPPORT__
    mmi_medply_ncenter_update_media();
    #endif

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    /*if set this flags, need clean background MMI_MSCR_HD_HAS_PAINT_BG*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG_ARTWORK;
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG;
    }
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
    mmi_mscr_gesture_stop();
#endif
    /*close popup setting*/
    mmi_mscr_close_popup();

    mmi_mscr_stop_playing();
    mmi_mscr_unprepare_view_content();
   
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        mmi_mscr_prepare_hw_video_layer(MMI_TRUE);
    }
    else
    {
        mmi_mscr_prepare_hw_video_layer(MMI_FALSE);
    }
    
    mmi_mscr_init_ui_status();
    /*prepare view need remove if Ctrl call mmi_medply_main_screen_prepare_view*/
    mmi_mscr_prepare_view_content();
    
    /*need config layer rotate again*/
    mmi_mscr_config_layer_rotate();
    /*after change display content, must do layer blt reset*/
    mmi_mscr_config_layer_blt();  
    mmi_mscr_config_backlight();
    
    mmi_medply_main_screen_redraw();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_status_and_ani
* DESCRIPTION
*   
* PARAMETERS
*  status:      [IN]
*  ani:         [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_medply_main_screen_set_status_and_ani(U8 status, U8 ani)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_STATUS_AND_ANI, status, ani);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    
    MMI_MSCR_MSG_TRACE(status);
    
    if ((MMI_MEDPLY_STATUS_READY == status || 
        MMI_MEDPLY_STATUS_PLAYING == status) && 
        (MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content))
    {
        mmi_mscr_update_video_content();
    }
    mmi_mscr_set_status_and_ani(status, ani);  
    
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h);
        if (g_mscr_hd->ui_status != status)
        {
            mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].x,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].y,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].w,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].h);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_update_title
* DESCRIPTION
*  mainly used when need update title. 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_update_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UPDATE_TITLE);
    /*
          * FTE main screen is not support title, so this is dummy function.
	  */
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_change_status
* DESCRIPTION
*  play spectrum 
* PARAMETERS
*  blt_f    [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_medply_change_status(MMI_BOOL blt_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ui_status, ani_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CHANGE_STATUS, blt_f);
    
    if(g_medply.widget_callback != NULL)
    {
        g_medply.widget_callback(g_medply.widget_callback_userdata, 
            MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK,NULL);
    }
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (blt_f)
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE;
    }
    
    mmi_medply_get_ui_status(&ui_status, &ani_id);
    
    if (MMI_MEDPLY_ANI_SNAP_SHOT == ani_id || MMI_MEDPLY_ANI_NULL == ani_id)
    {
        mmi_mscr_update_ui_status();
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_STATUS_TIMER))
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_STATUS_TIMER;
        gui_start_timer(MMI_MSCR_UI_UPDATE_STATUS_TIME, mmi_mscr_update_ui_status);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_get_ui_status
* DESCRIPTION
*  play spectrum 
* PARAMETERS
*  ui_status    [OUT]
*  id_ani       [OUT]
* RETURNS
*  void
 *****************************************************************************/
extern void mmi_medply_get_ui_status(U8* ui_status, U8* id_ani)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state       = mmi_inline_get_status(); 
    *ui_status  = MMI_MEDPLY_STATUS_IDLE;
    *id_ani     = MMI_MEDPLY_ANI_NULL;

    if (mmi_inline_is_single_play())
    {  
        switch(state)
        {
        case SINGLE_STATE_AUDIO_READY:        
        case SINGLE_STATE_VIDEO_READY:
        case SINGLE_STATE_PDL_VIDEO_READY:          
        case SINGLE_STATE_PDL_AUDIO_READY:
        case SINGLE_STATE_STREAM_CONNECTED:    

        case SINGLE_STATE_AUDIO_PAUSE_PROGRESSING:    
        case SINGLE_STATE_VIDEO_PAUSE_PROGRESSING:   
        case SINGLE_STATE_PDL_VIDEO_PAUSE_PROGRESSING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            break;    
        case SINGLE_STATE_AUDIO_PLAY: 
        case SINGLE_STATE_VIDEO_PLAY:   
        case SINGLE_STATE_STREAM_PLAY: 
        case SINGLE_STATE_PDL_AUDIO_PLAY:    
        case SINGLE_STATE_PDL_VIDEO_PLAY:        
            
        case SINGLE_STATE_AUDIO_PLAY_PROGRESSING:
        case SINGLE_STATE_VIDEO_PLAY_PROGRESSING:    
        case SINGLE_STATE_STREAM_PLAY_PROGRESSING:  
        case SINGLE_STATE_PDL_VIDEO_PLAY_PROGRESSING:
            
            *ui_status  = MMI_MEDPLY_STATUS_PLAYING;
            break;
        case SINGLE_STATE_AUDIO_BT_CONNECTING:
        case SINGLE_STATE_VIDEO_BT_CONNECTING:
        case SINGLE_STATE_STREAM_BT_CONNECTING:
        case SINGLE_STATE_PDL_VIDEO_BT_CONNECTING:
        case SINGLE_STATE_PDL_AUDIO_BT_CONNECTING:
            /*prepare bt connecting animation*/
            *id_ani     = MMI_MEDPLY_ANI_BT_CONNECTING;
            break;

        case SINGLE_STATE_VIDEO_OPENING:
        case SINGLE_STATE_PDL_VIDEO_OPENING:
            
            *id_ani     = MMI_MEDPLY_ANI_VIDEO_OPENING;
            break;
        case SINGLE_STATE_STREAM_CONNECTING:   
            
            *id_ani     = MMI_MEDPLY_ANI_RTP_CONNECTING;
            break;
        case SINGLE_STATE_PDL_VIDEO_PAUSE_BUFFERING:
        case SINGLE_STATE_PDL_VIDEO_PLAY_BUFFERING:
        case SINGLE_STATE_PDL_AUDIO_BUFFERING:
        case SINGLE_STATE_STREAM_BUFFERING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            *id_ani     = MMI_MEDPLY_ANI_LOADING;
            break;
        default:
            break;
        }
    }
    else
    {
        switch(state)
        {
        case MEDPLY_STATE_AUDIO_READY:
        case MEDPLY_STATE_VIDEO_READY:
        case MEDPLY_STATE_STREAM_CONNECTED:
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:  
        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            break;

        /*
         *  There three states all background play states, 
         *  so no not need show animation.
         */
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:    
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            /*do not add break here*/
        case MEDPLY_STATE_AUDIO_PLAY:    
        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:    
        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            
        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:    
        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:    
            
            *ui_status  = MMI_MEDPLY_STATUS_PLAYING;
            break;
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_BT_CONNECTING:
            /*prepare bt connecting animation*/
            *id_ani     = MMI_MEDPLY_ANI_BT_CONNECTING;
            break;
        case MEDPLY_STATE_VIDEO_OPENING:
                
            *id_ani     = MMI_MEDPLY_ANI_VIDEO_OPENING;
            break;
        case MEDPLY_STATE_STREAM_CONNECTING:   
            
            *id_ani     = MMI_MEDPLY_ANI_RTP_CONNECTING;
            break;
        case MEDPLY_STATE_STREAM_BUFFERING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            *id_ani     = MMI_MEDPLY_ANI_LOADING;
            break;
        case MEDPLY_STATE_SNAPSHOT:
            
            *id_ani     = MMI_MEDPLY_ANI_SNAP_SHOT;
            break;
        default:
            break;
        }
    }    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_GET_UI_STATUS, state, *ui_status, *id_ani);
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_close_popup_setting
* DESCRIPTION
*  get point touched region
* PARAMETERS
*  void       
* RETURNS
*  mmi_medply_regn_id_enum
*****************************************************************************/
void    mmi_medply_main_screen_close_popup_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    
    MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_popup_hdl);
    
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)
    {
        mmi_mscr_close_popup();   
        mmi_medply_main_screen_blt();
    }    
}

#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
/*****************************************************************************
* FUNCTION
*  mmi_mscr_gesture_prepare
* DESCRIPTION
*  play spectrum 
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_gesture_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct rgn;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(g_mscr_hd->layer_gesture == GDI_NULL_HANDLE);

    rgn.x = (S16)g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x;
    rgn.y = (S16)g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y;
    rgn.w = (S16)g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w;
    rgn.h = (S16)g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h;

    gdi_layer_create_using_outside_memory(
        rgn.x,
        rgn.y,
        rgn.w,
        rgn.h,
        &g_mscr_hd->layer_gesture,
        g_mscr_hd->mem_scr_layer,
        rgn.w * rgn.h * MMI_MSCR_COLOR_DEPTH);    

    mmi_mscr_unprepare_view_content();
    mmi_mscr_gesture_get_next_view_content();
    mmi_mscr_prepare_view_content();

    mmi_mscr_beg_paint(g_mscr_hd->layer_gesture, &rgn);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);			
    gdi_layer_set_source_key(FALSE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    mmi_mscr_end_paint();


    switch(g_mscr_hd->view_content)
    {
    case MMI_MSCR_CONTENT_METAINFO:       
        
        mmi_mscr_draw_meta();
        break;
        
    case MMI_MSCR_CONTENT_SPECTRUM:
       
        break;
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
    case MMI_MSCR_CONTENT_LYRICS:

        mmi_mscr_draw_lyrics();
        break;
#endif /* __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__ */

    default:

        mmi_mscr_draw_video_demo();
        break;
    }    
    mmi_mscr_config_layer_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_gesture_unprepare
* DESCRIPTION
*  play spectrum 
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_gesture_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* mem_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(g_mscr_hd->layer_gesture != GDI_NULL_HANDLE);

    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    gdi_layer_get_buffer_ptr(&mem_p);
    gdi_layer_pop_and_restore_active();

    kal_mem_cpy(mem_p, g_mscr_hd->mem_scr_layer, 
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w*g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h* MMI_MSCR_COLOR_DEPTH);
    
    mmi_mscr_delete_layer(g_mscr_hd->layer_gesture);
    g_mscr_hd->layer_gesture = GDI_NULL_HANDLE;

    mmi_mscr_config_layer_blt();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_gesture_start
* DESCRIPTION
*   
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_gesture_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*pause main screen first, after gesture stop then resume*/
    mmi_mscr_pause();
    mmi_mscr_gesture_prepare();    

    g_mscr_hd->gesture_offset = 0;
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_RIGHT_TO_LEFT)
    {
        start_pos = GDI_LCD_WIDTH;
    }
    else
    {
        start_pos = 0-GDI_LCD_WIDTH;
    }    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_gesture);
    gdi_layer_set_position(start_pos, g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y);
    gdi_layer_pop_and_restore_active();
    
    gui_start_timer(MMI_MSCR_UI_GESTURE_MOVE_TIME, mmi_mscr_gesture_move);
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_gesture_stop
* DESCRIPTION
*   
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_gesture_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_mscr_hd->layer_gesture == GDI_NULL_HANDLE)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    gui_cancel_timer(mmi_mscr_gesture_move);

    mmi_mscr_gesture_unprepare();

    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
    gdi_layer_set_position(0, g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y);
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h);
    mmi_medply_main_screen_blt();
  
    mmi_mscr_update_duration();   
    mmi_mscr_draw_view();
    mmi_mscr_update_view_content(0);
    mmi_mscr_resume();

    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_OSD_WAITING_START)
    {
        mmi_mscr_start_osd_animation();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_gesture_move
* DESCRIPTION
*   
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_gesture_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }    
    g_mscr_hd->gesture_offset += 40;   
    if (g_mscr_hd->gesture_offset >= GDI_LCD_WIDTH)
    {
        g_mscr_hd->gesture_offset = GDI_LCD_WIDTH;
        mmi_mscr_gesture_stop();
        return;
    }
    gui_start_timer(MMI_MSCR_UI_GESTURE_MOVE_TIME, mmi_mscr_gesture_move);
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_RIGHT_TO_LEFT)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
        gdi_layer_set_position(-g_mscr_hd->gesture_offset, g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_mscr_hd->layer_gesture);
        gdi_layer_set_position(GDI_LCD_WIDTH-g_mscr_hd->gesture_offset, 
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_VIEW]);
        gdi_layer_set_position(g_mscr_hd->gesture_offset, g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_mscr_hd->layer_gesture);
        gdi_layer_set_position(g_mscr_hd->gesture_offset - GDI_LCD_WIDTH, 
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y);
        gdi_layer_pop_and_restore_active();
    }    

    mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h);
    mmi_medply_main_screen_blt();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_gesture_get_next_view_content
* DESCRIPTION
*   
* PARAMETERS
*  status:      [IN]
*  ani:         [IN]
* RETURNS
*  void
 *****************************************************************************/ 
static  void    mmi_mscr_gesture_get_next_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 new_view_set;
    U8  u8Value;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_MAINSCR_DISP, 
        (void*)&u8Value);
    
    new_view_set = (S16)u8Value;
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_RIGHT_TO_LEFT)
    {
        new_view_set++;
    }
    else
    {
        new_view_set--;
    }
    if (new_view_set < MMI_MEDPLY_MAINSCR_DISP_DETAIL)
    {
        new_view_set = MMI_MEDPLY_MAINSCR_DISP_ALL - 1;
    }
    else if (new_view_set >= MMI_MEDPLY_MAINSCR_DISP_ALL)
    {
        new_view_set = MMI_MEDPLY_MAINSCR_DISP_DETAIL;
    }
    
    switch(new_view_set)
    {
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MEDPLY_MAINSCR_DISP_SPECTRUM:            
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_SPECTRUM;
        break;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */
        
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
    case MMI_MEDPLY_MAINSCR_DISP_LYRICS:            
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_LYRICS;
        break;
#endif /* __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__ */
        
    case MMI_MEDPLY_MAINSCR_DISP_DETAIL:            
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_METAINFO;
        break;
    default:
        ASSERT(0);
        break;
    }    
    mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_MAINSCR_DISP,
                                   (void*)&new_view_set);
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_gesture_hdl
* DESCRIPTION
*   
* PARAMETERS
*  mmi_frm_gesture_event_enum       
* RETURNS
*  layer handle
 *****************************************************************************/
void     mmi_medply_main_screen_gesture_hdl(mmi_frm_gesture_event_enum event)
{
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_popup_hdl)      /*has popup*/
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->popup_type);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_LAYER)       /*has osd animation*/
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }    
    
    if (MMI_MSCR_VIEW_MODE_AUDIO != g_mscr_hd->view_mode)   /*only audio has 3 view type*/
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->view_mode);
        return;
    }        
    /*already start!*/
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_gesture)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->layer_gesture);
        return;
    }    
    switch(event)
    {
    case MMI_FRM_GESTURE_RIGHT:

        g_mscr_hd->flags &= ~MMI_MSCR_HD_IS_RIGHT_TO_LEFT;
        break;
    case MMI_FRM_GESTURE_LEFT:

        g_mscr_hd->flags |= MMI_MSCR_HD_IS_RIGHT_TO_LEFT;
        break;
    default:
        return;
    }
    mmi_mscr_gesture_start();
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_check_gesture_valid
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
extern MMI_BOOL mmi_medply_check_gesture_valid(mmi_frm_gesture_rect_struct *rgn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (1 == MMI_MEDPLY_COMP_USING_GESTURES)
    /*kuro and audio will merge together in player list, so check with kuro and audio*/
    if(MMI_MSCR_VIEW_MODE_VIDEO != g_mscr_hd->view_mode)
    {
        rgn->x1 = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x;
        rgn->y1 = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y;
        rgn->x2 = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x + g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w;
        rgn->y2 = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y + g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h;

        return MMI_TRUE;        
    }
    else
    {
        rgn->x1 = 0;
        rgn->y1 = 0;
        rgn->x2 = 0;
        rgn->y2 = 0;
    }
#endif
    return  MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_lcd_sleep_out_handler
* DESCRIPTION
*  back light has turn on, just goto play spectrum
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_lcd_sleep_out_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SLEEP_OUT);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    MMI_MSCR_MSG_TRACE(g_mscr_hd->view_content);
    MMI_MSCR_MSG_TRACE(g_mscr_hd->ui_status);

    mmi_mscr_update_duration();
    mmi_medply_main_screen_redraw();
    mmi_medply_main_screen_blt();
    
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    /*When in full screen, do not restart spectrum*/
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        if ((MMI_MSCR_CONTENT_SPECTRUM == g_mscr_hd->view_content) &&
            (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status))
        {
            mmi_mscr_play_spectrum();
        }
    }
#endif
    
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_lcd_sleep_in_handler
* DESCRIPTION
*  back light has turn off  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_lcd_sleep_in_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SLEEP_IN);
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    mmi_mscr_stop_spectrum();
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_init
* DESCRIPTION
*  INIT SKIN AND UI
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*init layer region*/
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].x		= g_medply_fte_skin.top_layer_rgn_x;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].y		= g_medply_fte_skin.top_layer_rgn_y;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].w		= g_medply_fte_skin.top_layer_rgn_w;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].h		= g_medply_fte_skin.top_layer_rgn_h;
    
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].x	= g_medply_fte_skin.view_layer_rgn_x;
	
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].y		= g_medply_fte_skin.view_layer_rgn_y;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].w		= g_medply_fte_skin.view_layer_rgn_w;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_VIEW].h		= g_medply_fte_skin.view_layer_rgn_h;
    
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].x		= g_medply_fte_skin.panel_layer_rgn_x;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].y		= g_medply_fte_skin.panel_layer_rgn_y;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].w		= g_medply_fte_skin.panel_layer_rgn_w;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_PANEL].h		= g_medply_fte_skin.panel_layer_rgn_h;

    /*init meta item region*/
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].x	= g_medply_fte_skin.title_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].y	= g_medply_fte_skin.title_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].w	= g_medply_fte_skin.title_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].h	= g_medply_fte_skin.title_txt_rgn_h;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].x	= g_medply_fte_skin.album_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].y	= g_medply_fte_skin.album_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].w	= g_medply_fte_skin.album_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ALBUM_TXT].h	= g_medply_fte_skin.album_txt_rgn_h;
    
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].x	= g_medply_fte_skin.artist_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].y	= g_medply_fte_skin.artist_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].w	= g_medply_fte_skin.artist_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_ARTIST_TXT].h	= g_medply_fte_skin.artist_txt_rgn_h;
		/*this two line and cover image can directly draw in background*/
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE1].x	= g_medply_fte_skin.meta_sep_line1_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE1].y	= g_medply_fte_skin.meta_sep_line1_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE1].w	= g_medply_fte_skin.meta_sep_line1_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE1].h	= g_medply_fte_skin.meta_sep_line1_h;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE2].x	= g_medply_fte_skin.meta_sep_line2_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE2].y	= g_medply_fte_skin.meta_sep_line2_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE2].w	= g_medply_fte_skin.meta_sep_line2_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SEP_LINE2].h	= g_medply_fte_skin.meta_sep_line2_h;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].x	= g_medply_fte_skin.meta_img_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].y	= g_medply_fte_skin.meta_img_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].w	= g_medply_fte_skin.meta_img_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_COVER_IMG].h	= g_medply_fte_skin.meta_img_rgn_h;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].x	= g_medply_fte_skin.time_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].y	= g_medply_fte_skin.time_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].w	= g_medply_fte_skin.time_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TIME_TXT].h	= g_medply_fte_skin.time_txt_rgn_h;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].x = g_medply_fte_skin.duration_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].y = g_medply_fte_skin.duration_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].w = g_medply_fte_skin.duration_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION_TXT].h = g_medply_fte_skin.duration_txt_rgn_h;
    
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].x		= g_medply_fte_skin.lyrics_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].y		= g_medply_fte_skin.lyrics_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].w		= g_medply_fte_skin.lyrics_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].h		= g_medply_fte_skin.lyrics_rgn_h;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].x	= g_medply_fte_skin.spectrum_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].y	= g_medply_fte_skin.spectrum_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].w	= g_medply_fte_skin.spectrum_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].h	= g_medply_fte_skin.spectrum_rgn_h;
    
    /*init touch button*/
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].view_x	= g_medply_fte_skin.play_pause_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].view_y	= g_medply_fte_skin.play_pause_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.x = g_medply_fte_skin.play_pause_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.y = g_medply_fte_skin.play_pause_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.w = g_medply_fte_skin.play_pause_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.h = g_medply_fte_skin.play_pause_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].up_img_id = g_medply_fte_skin.play_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].down_img_id = g_medply_fte_skin.play_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].disable_img_id = g_medply_fte_skin.play_disable_img_id;

#ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].view_x		= g_medply_fte_skin.stop_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].view_y		= g_medply_fte_skin.stop_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.x	= g_medply_fte_skin.stop_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.y	= g_medply_fte_skin.stop_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.w	= g_medply_fte_skin.stop_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.h	= g_medply_fte_skin.stop_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].up_img_id	= g_medply_fte_skin.stop_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].down_img_id = g_medply_fte_skin.stop_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].disable_img_id	= g_medply_fte_skin.stop_disable_img_id;
#endif

#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].view_x = g_medply_fte_skin.mode_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].view_y = g_medply_fte_skin.mode_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.x = g_medply_fte_skin.mode_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.y = g_medply_fte_skin.mode_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.w = g_medply_fte_skin.mode_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.h = g_medply_fte_skin.mode_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].up_img_id = g_medply_fte_skin.mode_2d_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].down_img_id = g_medply_fte_skin.mode_2d_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].disable_img_id = g_medply_fte_skin.mode_2d_disable_img_id;
#endif

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].view_x		= g_medply_fte_skin.prev_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].view_y		= g_medply_fte_skin.prev_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.x	= g_medply_fte_skin.prev_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.y	= g_medply_fte_skin.prev_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.w	= g_medply_fte_skin.prev_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.h	= g_medply_fte_skin.prev_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].up_img_id	= g_medply_fte_skin.prev_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].down_img_id = g_medply_fte_skin.prev_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].disable_img_id	= g_medply_fte_skin.prev_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].view_x		= g_medply_fte_skin.next_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].view_y		= g_medply_fte_skin.next_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.x	= g_medply_fte_skin.next_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.y	= g_medply_fte_skin.next_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.w	= g_medply_fte_skin.next_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.h	= g_medply_fte_skin.next_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].up_img_id	= g_medply_fte_skin.next_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].down_img_id = g_medply_fte_skin.next_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].disable_img_id	= g_medply_fte_skin.next_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].view_x		= g_medply_fte_skin.shuffle_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].view_y		= g_medply_fte_skin.shuffle_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.x	= g_medply_fte_skin.shuffle_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.y	= g_medply_fte_skin.shuffle_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.w	= g_medply_fte_skin.shuffle_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.h	= g_medply_fte_skin.shuffle_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].up_img_id	= g_medply_fte_skin.shuffle_on_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].down_img_id	= g_medply_fte_skin.shuffle_on_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].disable_img_id = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].view_x		= g_medply_fte_skin.repeat_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].view_y		= g_medply_fte_skin.repeat_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.x		= g_medply_fte_skin.repeat_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.y		= g_medply_fte_skin.repeat_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.w		= g_medply_fte_skin.repeat_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.h		= g_medply_fte_skin.repeat_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].up_img_id		= g_medply_fte_skin.repeat_off_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].down_img_id	= g_medply_fte_skin.repeat_off_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].disable_img_id = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].view_x	= g_medply_fte_skin.rating_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].view_y	= g_medply_fte_skin.rating_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].pen_rgn.x = g_medply_fte_skin.rating_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].pen_rgn.y = g_medply_fte_skin.rating_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].pen_rgn.w = g_medply_fte_skin.rating_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].pen_rgn.h = g_medply_fte_skin.rating_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].up_img_id = g_medply_fte_skin.rating_btn_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].down_img_id = g_medply_fte_skin.rating_btn_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_USER_RATING].disable_img_id = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].view_x		= g_medply_fte_skin.lsk_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].view_y		= g_medply_fte_skin.lsk_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.x	= g_medply_fte_skin.lsk_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.y	= g_medply_fte_skin.lsk_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.w	= g_medply_fte_skin.lsk_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.h	= g_medply_fte_skin.lsk_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].up_img_id	= g_medply_fte_skin.lsk_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].down_img_id = g_medply_fte_skin.lsk_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].disable_img_id = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].view_x		= g_medply_fte_skin.rsk_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].view_y		= g_medply_fte_skin.rsk_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.x	= g_medply_fte_skin.rsk_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.y	= g_medply_fte_skin.rsk_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.w	= g_medply_fte_skin.rsk_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.h	= g_medply_fte_skin.rsk_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].up_img_id	= g_medply_fte_skin.rsk_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].down_img_id = g_medply_fte_skin.rsk_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].disable_img_id = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].view_x      = g_medply_fte_skin.zoom_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].view_y      = g_medply_fte_skin.zoom_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.x   = g_medply_fte_skin.zoom_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.y   = g_medply_fte_skin.zoom_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.w   = g_medply_fte_skin.zoom_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.h   = g_medply_fte_skin.zoom_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].up_img_id   = g_medply_fte_skin.zoom_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].down_img_id     = g_medply_fte_skin.zoom_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].disable_img_id  = g_medply_fte_skin.zoom_disable_img_id;

    /*init duration bar display*/
    g_mscr_ui.duration_img.view_x		= g_medply_fte_skin.duration_bar_pos_x;//12;
    g_mscr_ui.duration_img.view_y		= g_medply_fte_skin.duration_bar_pos_y;//235;
    g_mscr_ui.duration_img.bg_img_id    = g_medply_fte_skin.duration_bar_bg_disable_img_id;
    g_mscr_ui.duration_img.fg_img_id    = g_medply_fte_skin.duration_bar_fg_img_id;
    g_mscr_ui.duration_img.md_img_id    = g_medply_fte_skin.duration_bar_mg_img_id;
    
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].view_x      = g_medply_fte_skin.duration_btn_pos_x;//12;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].view_y      = g_medply_fte_skin.duration_btn_pos_y;//230;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.x   = g_medply_fte_skin.duration_btn_rgn_x;//12;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.y   = g_medply_fte_skin.duration_btn_rgn_y;//230;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.w   = g_medply_fte_skin.duration_btn_rgn_w;//15;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].pen_rgn.h   = g_medply_fte_skin.duration_btn_rgn_h;//15;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].up_img_id   = g_medply_fte_skin.duration_btn_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].down_img_id     = g_medply_fte_skin.duration_btn_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_DURATION_BAR].disable_img_id  = MMI_MSCR_ERR_IMG_ID;

    /*For volume set*/    
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].x = g_medply_fte_skin.volume_set_regn_x;
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].y = g_medply_fte_skin.volume_set_regn_y;
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].w = g_medply_fte_skin.volume_set_regn_w;
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_VOLUME].h = g_medply_fte_skin.volume_set_regn_h;
    
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].view_x      = g_medply_fte_skin.mute_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].view_y      = g_medply_fte_skin.mute_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.x   = g_medply_fte_skin.mute_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.y   = g_medply_fte_skin.mute_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.w   = g_medply_fte_skin.mute_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.h   = g_medply_fte_skin.mute_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].up_img_id   = g_medply_fte_skin.mute_on_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].down_img_id     = g_medply_fte_skin.mute_on_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].disable_img_id  = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].view_x      = g_medply_fte_skin.volume_btn_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].view_y      = g_medply_fte_skin.volume_btn_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.x   = g_medply_fte_skin.volume_btn_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.y   = g_medply_fte_skin.volume_btn_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.w   = g_medply_fte_skin.volume_btn_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].pen_rgn.h   = g_medply_fte_skin.volume_btn_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].up_img_id   = g_medply_fte_skin.volume_btn_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].down_img_id = g_medply_fte_skin.volume_btn_img_hl_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_BAR].disable_img_id  = MMI_MSCR_ERR_IMG_ID;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_VOLUME].x = g_medply_fte_skin.volume_bar_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_VOLUME].y = g_medply_fte_skin.volume_bar_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_VOLUME].w = g_medply_fte_skin.volume_bar_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_VOLUME].h = g_medply_fte_skin.volume_bar_rgn_h;

    g_mscr_ui.volume_img.view_x     = g_medply_fte_skin.volume_bar_rgn_x;
    g_mscr_ui.volume_img.view_y     = g_medply_fte_skin.volume_bar_rgn_y;
    g_mscr_ui.volume_img.bg_img_id  = g_medply_fte_skin.volume_set_bg_img_id;
    g_mscr_ui.volume_img.fg_img_id  = g_medply_fte_skin.volume_bar_fg_img_id;
    g_mscr_ui.volume_img.md_img_id  = MMI_MSCR_ERR_IMG_ID;

    /*User rating set*/
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].x = g_medply_fte_skin.rating_set_regn_x;
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].y = g_medply_fte_skin.rating_set_regn_y;
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].w = g_medply_fte_skin.rating_set_regn_w;
    g_mscr_ui.popup_rgn[MMI_MSCR_POPUP_TYPE_RATING].h = g_medply_fte_skin.rating_set_regn_h;

    /*init user rating bar*/
    g_mscr_ui.rating_img.view_x     = g_medply_fte_skin.rating_star_pos_x;
    g_mscr_ui.rating_img.view_y     = g_medply_fte_skin.rating_star_pos_y;
    g_mscr_ui.rating_img.bg_img_id  = g_medply_fte_skin.rating_set_bg_img_id;
    g_mscr_ui.rating_img.fg_img_id  = g_medply_fte_skin.rating_star_fg_img_id;
    g_mscr_ui.rating_img.star_w     = MMI_MEDPLY_RATING_W;
    g_mscr_ui.rating_img.interval   = MMI_MEDPLY_RATING_STEP;

    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    g_mscr_ui.subtitle_rgn.x        = g_medply_fte_skin.view_layer_rgn_x + MMI_MSCR_SUBTITLE_FONT_SIZE;
    g_mscr_ui.subtitle_rgn.y        = g_medply_fte_skin.view_layer_rgn_y + g_medply_fte_skin.view_layer_rgn_h - 
                                          MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER - MMI_MSCR_SUBTITLE_HOR_GAP;
    g_mscr_ui.subtitle_rgn.w        = g_medply_fte_skin.view_layer_rgn_w - 2 * MMI_MSCR_SUBTITLE_FONT_SIZE;
    g_mscr_ui.subtitle_rgn.h        = MMI_MSCR_SUBTITLE_FONT_SIZE * MMI_MSCR_SUBTITLE_LINE_NUMBER;
    #endif

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_enable_backlight
* DESCRIPTION
*   enable back light, when tv out change status, there also change play status.  
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_enable_backlight(U8 is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != is_enable)
    {        
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV))
        {
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV;
            
            /* 
            * This is used to solve a very rare situation. When the screen previous 
            * to this screen is a horizontal screen. Before enter this screen, 
            * the IMELODY turn off the back light. While exit previous screen, 
            * the layer rotate back to normal size and the content is not correct.
            * So when calling srv_backlight_turn_on, 
            * LCD is in sleepin state and draw wrong content to LCD.
            * So we need to clear the buffer first to avoid this situation.
            */
            /*gdi_layer_clear(GDI_COLOR_BLACK); */               
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        }
    }
    else
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV)
        {
            g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV;
            
            srv_backlight_turn_off();
        }
    }    
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_compare_region
* DESCRIPTION
*   
* PARAMETERS
*   mem_p:
*           
* RETURNS
#define     MMI_MSCR_RGN_2IN1           0x00
#define     MMI_MSCR_RGN_1IN2           0x01
#define     MMI_MSCR_RGN_INTERSECT      0x02
#define     MMI_MSCR_RGN_OUT            0x03
*****************************************************************************/
static  U8      mmi_mscr_compare_region(mmi_medply_rect_struct* rgn_1_p, mmi_medply_rect_struct* rgn_2_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    MMI_BOOL    r1p1, r1p2, r2p1, r2p2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Check Left-Top & righ-Bottom Point whether all in region 2*/
    r1p1    = mmi_mscr_is_pt_in_rgn(rgn_1_p->x, rgn_1_p->y, rgn_2_p);
    r1p2    = mmi_mscr_is_pt_in_rgn((S16)(rgn_1_p->x+rgn_1_p->w), (S16)(rgn_1_p->y+rgn_1_p->h), rgn_2_p);

    if (r1p1 && r1p2)
    {
        return  MMI_MSCR_RGN_1IN2;
    }
    r2p1    = mmi_mscr_is_pt_in_rgn(rgn_2_p->x, rgn_2_p->y, rgn_1_p);
    r2p2    = mmi_mscr_is_pt_in_rgn((S16)(rgn_2_p->x+rgn_2_p->w), (S16)(rgn_2_p->y+rgn_2_p->h), rgn_1_p);

    if (r2p1 && r2p2)
    {
        return  MMI_MSCR_RGN_2IN1;
    }

    if (r1p1 || r1p2 || r2p1 || r2p2)
    {
        return  MMI_MSCR_RGN_INTERSECT;
    }

    r1p1    = mmi_mscr_is_pt_in_rgn(rgn_1_p->x, (S16)(rgn_1_p->y+rgn_1_p->h), rgn_2_p);
    r1p2    = mmi_mscr_is_pt_in_rgn((S16)(rgn_1_p->x+rgn_1_p->w), rgn_1_p->y, rgn_2_p);

    if (r1p1 || r1p2)
    {
    return  MMI_MSCR_RGN_INTERSECT;
}
    return  MMI_MSCR_RGN_OUT;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_is_pt_in_rgn
* DESCRIPTION
*  check whether touch point in region 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  MMI_BOOL mmi_mscr_is_pt_in_rgn(S16 x, S16 y, mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if ((x >= rgn_p->x) && (x <= rgn_p->x+rgn_p->w) &&
        (y >= rgn_p->y) && (y <= rgn_p->y+rgn_p->h))
    {
        return  MMI_TRUE;
    }
    return  MMI_FALSE;
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_mscr_get_pt_range
* DESCRIPTION
*  check whether touch point in region 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8  mmi_mscr_get_pt_range(S16 x, mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U8 range;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x < rgn_p->x)
    {
        range = 0;
    }
    else if (x >= rgn_p->x + rgn_p->w)
    {
        range = 100;
    }
    else
    {
        range = (x-rgn_p->x)*100/rgn_p->w;
    }
    return  range;
}
#endif /*__MMI_TOUCH_SCREEN__*/

/*****************************************************************************
* FUNCTION
*  mmi_inline_is_full_screen
* DESCRIPTION
*  check current play is in full screen
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8 mmi_inline_is_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  g_medply.fullscreen;
}


#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
/*****************************************************************************
* FUNCTION
*  mmi_inline_malloc
* DESCRIPTION
*  
* PARAMETERS
*        
* RETURNS
*  success return memory address, 
*****************************************************************************/
static  void* mmi_inline_malloc(kal_uint32 nSize, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        return  NULL;
    }
    MMI_MSCR_MSG_TRACE(nSize);
    if (nSize >= MMI_MSCR_ARTWORK_SIZE - MMI_MSCR_SUBTITLE_MAX_BUF_SIZE)
    {
        MMI_MSCR_ERR_TRACE(nSize);
        return  applib_mem_screen_alloc_framebuffer(nSize);    
    }

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_USED_ARTWORK_MEM)
    {
        MMI_MSCR_ERR_TRACE(0);
        return  applib_mem_screen_alloc_framebuffer(nSize);    
    }
    else
    {
        MMI_MSCR_MSG_TRACE(1);
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_USED_ARTWORK_MEM;

        return  (void*)(g_mscr_hd->mem_artwork + MMI_MSCR_SUBTITLE_MAX_BUF_SIZE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_free
* DESCRIPTION
*  
* PARAMETERS
*        
* RETURNS
*  
*****************************************************************************/
static  void  mmi_inline_free(void* p, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(p);
        return;
    }
    if ((U8*)p == g_mscr_hd->mem_artwork + MMI_MSCR_SUBTITLE_MAX_BUF_SIZE)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_USED_ARTWORK_MEM;
        MMI_MSCR_MSG_TRACE(1);

        return;
    }
    MMI_MSCR_ERR_TRACE(p);
    applib_mem_screen_free(p);
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_inline_get_status
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8 mmi_inline_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.state);
        return  g_single.state;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.state);
        return  g_medply.state;
    }
}

#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
/*****************************************************************************
* FUNCTION
*  mmi_inline_get_title_path
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U16*    mmi_inline_get_title_path(U8* data_from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        /*stream title*/
        if (0 != g_single.specified_title[0] && 
            0 != g_single.specified_title[1])
        {
            *data_from = MMI_MSCR_DATA_FROM_STREAM;
            
            return  (U16*)g_single.specified_title;
        }
        
        if (0 != g_single.filefullpath[0])
        {
            if (0 != mmi_inline_is_stream_url())
            {
                *data_from = MMI_MSCR_DATA_FROM_STREAM;
            }
            else
            {
                *data_from = MMI_MSCR_DATA_FROM_FILE;
            }
            return  (U16*)g_single.filefullpath;
        }
    }
    else
    {
#ifdef __MMI_MEDIA_PLAYER_STREAM__
        /*stream title*/
        if (0 != g_medply.stream_title[0] && 
            0 != g_medply.stream_title[1])
        {
            *data_from = MMI_MSCR_DATA_FROM_STREAM;
            
            return  (U16*)g_medply.stream_title;
        }
#endif
        if (0 != g_medply.filefullpath[0])
        {
            if (0 != mmi_inline_is_stream_url())
            {
                *data_from = MMI_MSCR_DATA_FROM_STREAM;
            }
            else
            {
                *data_from = MMI_MSCR_DATA_FROM_FILE;
            }
            return  (U16*)g_medply.filefullpath;
        }
    }
    *data_from = MMI_MSCR_DATA_FROM_NULL;
    
    return  (U16*)GetString(STR_ID_MEDPLY_APP_TITLE);
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_duration
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U64     mmi_inline_get_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.duration);
        return  g_single.duration;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.duration);
        return  g_medply.duration;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_playtime
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U64     mmi_inline_get_playtime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.current_time);
        return  g_single.current_time;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.current_time);
        return  g_medply.current_time;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_playtime
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void    mmi_inline_set_playtime(U64 playtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(playtime);
    
    if (mmi_inline_is_single_play())
    {
        g_single.current_time = playtime;
    }
    else
    {
        g_medply.current_time = playtime;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_background_call
* DESCRIPTION
*  inline function to check whether the background call valid;
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8 mmi_inline_is_background_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        return 1;
    }
#endif /* __MMI_BACKGROUND_CALL__ */
    
    return 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_is_single_play
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8  mmi_inline_is_single_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  mmi_medply_is_single_player_activated();
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_is_button_disable
* DESCRIPTION
*  inline function to check whether the button is disabled;
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8      mmi_inline_is_button_disable(S32 button_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = 0;
    MMI_BOOL bDisable;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != mmi_inline_is_background_call())
    {
        /*In background call, button need disabled*/
        ret = 1;
    }

    bDisable = mmi_medply_is_button_disabled((mmi_medply_disabled_button_enum)button_id);
    MMI_MSCR_MSG_TRACE(button_id);
    if (bDisable)
    {
        ret = 1;
    }
    MMI_MSCR_MSG_TRACE(ret);
    return  ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_duration_seek_able
* DESCRIPTION
*  inline function to check duration is seek able
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8      mmi_inline_is_duration_seek_able(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != mmi_inline_is_background_call())
    {
        /*In background call, disabled seek*/
        return  0;
    }
    
    return !mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PROGRESS_BAR) ;
    
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_is_stream_url
* DESCRIPTION
*  inline function to check the fullfilepath whether it's stream url
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8  mmi_inline_is_stream_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U32 u32Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    u32Value = mmi_inline_get_media_type();
    if (MEDPLY_TYPE_STREAM_RTSP == u32Value)
    {
        return 1;
    }
#ifdef __MMI_VIDEO_STREAM__
    if (MEDPLY_TYPE_STREAM == u32Value)
    {
        u32Value = mmi_inline_get_media_format();
        if (MEDPLY_FORMAT_RTSP == u32Value)
        {
            return  1;
        }
    }
#endif
    return  0;
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_media_type
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U32 mmi_inline_get_media_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.media_type);
        return  g_single.media_type;
    }
    else
    {
        MMI_MSCR_MSG_TRACE( g_medply.media_type);
        return  g_medply.media_type;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_media_format
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U32 mmi_inline_get_media_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(MEDPLY_FORMAT_TOTAL);
        /*g_single.; without media_format like g_medply*/
        return  MEDPLY_FORMAT_TOTAL;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.media_format);
        return  g_medply.media_format;
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_inline_get_cache_percent
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8      mmi_inline_get_cache_percent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8  u8CachePer;
    U64 u64Duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    u64Duration = mmi_inline_get_duration();
    
    if (mmi_medply_get_build_cache_process(&g_mscr_hd->cachetime))
    {
        if (u64Duration != 0)
        {
            u8CachePer = (U8)(g_mscr_hd->cachetime * 100 / u64Duration);
        }
        else
        {
            MMI_MSCR_ERR_TRACE(g_mscr_hd->cachetime);
            u8CachePer = 0;
        }
    }
    else
    {
        u8CachePer = 100;
        g_mscr_hd->cachetime = u64Duration;
        MMI_MSCR_MSG_TRACE(u64Duration);
    }
    
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_MSG_TRACE(u8CachePer);
        return  u8CachePer;
    }
    /*Cache less then play percent, use play time*/
    if (u8CachePer < g_mscr_ui.duration_img.fg_range)
    {
        u8CachePer = g_mscr_ui.duration_img.fg_range;
    }
    /*Cache less then old cache percent, use old percent*/
    if (u8CachePer < g_mscr_ui.duration_img.md_range)
    {
        u8CachePer = g_mscr_ui.duration_img.md_range;
    }
    /*  Sync play time to cache time, should do in driver or in ctrl module,
    *   not in main screen
    */
    MMI_MSCR_MSG_TRACE(u8CachePer);
    return  u8CachePer;
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_get_cache_step
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U32 mmi_inline_get_cache_step(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.progress_speed);
        
        return  g_single.progress_speed;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.progress_speed);
        
        return  g_medply.progress_speed;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_get_video_track
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U32     mmi_inline_get_video_track(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.track);
        
        return  g_single.track;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.track);
        
        return  g_medply.track;
    }
#else
    return 0;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_group_id
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  MMI_ID mmi_inline_get_group_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(GRP_ID_MEDPLY_SINGLE);
        return  GRP_ID_MEDPLY_SINGLE;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(APP_MEDPLY);
        return  APP_MEDPLY;
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_inline_is_spectrum_blocked
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8  mmi_inline_is_spectrum_blocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
    if (mmi_inline_is_single_play())
    {
        return  0;
    }
    else
    {
        return  g_medply.A2DP_blocked;
    }
#else
    return  0;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_volume_level
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8  mmi_inline_get_volume_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.volume);
        return  g_single.volume;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.volume);
        return  g_medply.volume;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_volume_mute
* DESCRIPTION
*  inline function to get volume mute flag
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  U8  mmi_inline_is_volume_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        return  g_single.mute;
    }
    else
    {
        return  g_medply.mute;
    }
}

#ifdef __MMI_AUDIO_VOCAL_REMOVAL__
/*****************************************************************************
* FUNCTION
*  mmi_inline_is_tone_mute
* DESCRIPTION
*  inline function to get tone mute flag
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_inline_is_tone_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.vocal_removal);
        return  g_single.vocal_removal;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.vocal_removal);
        return  g_medply.vocal_removal;
    }
}
#endif /* __MMI_AUDIO_VOCAL_REMOVAL__ */

#ifdef __MMI_AUDIO_PITCH_SHIFTING__  
/*****************************************************************************
* FUNCTION
*  mmi_inline_get_tone_level
* DESCRIPTION
*  inline function to get tone level
* PARAMETERS
*  void        
* RETURNS
*  S16
*****************************************************************************/
static S16      mmi_inline_get_tone_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.pitch);
        return  g_single.pitch;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.pitch);
        return  g_medply.pitch;
    }
}
#endif

#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
/*****************************************************************************
* FUNCTION
*  mmi_inline_is_3d_mode
* DESCRIPTION
*  inline function to get seekable flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  MMI_BOOL mmi_inline_is_3d_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
	U16 play_mode;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.has_2d_mode);
        MMI_MSCR_MSG_TRACE(g_single.has_3d_mode);
        if(g_single.has_2d_mode && g_single.has_3d_mode)
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PLAY_MODE, &play_mode);
            MMI_MSCR_MSG_TRACE(play_mode);
            if(play_mode == MDI_VIDEO_TRACK_3D)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else if(g_single.has_3d_mode)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
        
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.has_2d_mode);
        MMI_MSCR_MSG_TRACE(g_medply.has_3d_mode);
        if(g_medply.has_2d_mode && g_medply.has_3d_mode)
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PLAY_MODE, &play_mode);
            MMI_MSCR_MSG_TRACE(play_mode);
            if(play_mode == MDI_VIDEO_TRACK_3D)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else if(g_medply.has_3d_mode)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
	
}
#endif

#ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
/*****************************************************************************
* FUNCTION
*  mmi_inline_is_3d_mode
* DESCRIPTION
*  inline function to get seekable flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
MMI_BOOL mmi_inline_has_subtitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_medply.media_type == MEDPLY_TYPE_AUDIO)
    {
        /* No subtitles for audio files */
        return MMI_FALSE;
    }
    else if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.has_subtitle);
        return  g_single.has_subtitle;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.has_subtitle);
        return  g_medply.has_subtitle;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_set_subtitle_font_size
* DESCRIPTION
*  inline function to set subtitle font size
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static void mmi_inline_set_subtitle_font_size(U8 font_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(font_size);
    g_medply.subtitle_font_size = font_size;
}

#endif


#endif /* __MMI_MEDIA_PLAYER_FTE__ */

