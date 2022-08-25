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
*  MedplyMainScreen.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player main screen drawing prototype
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef _MEDIA_PLAYER_MAIN_SCREEN_H
#define _MEDIA_PLAYER_MAIN_SCREEN_H
#include "MMI_features.h"

    #include "MMIDataType.h"
    #include "MediaPlayerEnumDef.h"
    #include "MediaPlayerPlayList.h"
    #include "CustThemesRes.h"
    #include "MMI_media_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_media_app_trc.h"

////#include "Conversions.h"
#include "Gui_windows.h"

#ifdef __MMI_MEDIA_PLAYER__
/*
*   DEFINE INLINE COMPILE OPTION
*/
typedef enum
{
    MMI_MSCR_DATA_FROM_NULL  = 0,
    MMI_MSCR_DATA_FROM_FILE,
    MMI_MSCR_DATA_FROM_STREAM,
    MMI_MSCR_DATA_FROM_TOTAL
        
} mmi_medply_data_enum;

typedef enum
{
    MMI_MSCR_CONTENT_NULL  = 0,
    
    MMI_MSCR_CONTENT_LYRICS,
    MMI_MSCR_CONTENT_SPECTRUM,
    MMI_MSCR_CONTENT_METAINFO,
    MMI_MSCR_CONTENT_ARTWORK,
    MMI_MSCR_CONTENT_KURO,
    MMI_MSCR_CONTENT_VIDEO_NULL,
    MMI_MSCR_CONTENT_VIDEO,    
    /*  MMI_MSCR_CONTENT_VIDEO_DEMO:
    *   video file only has audio track
    *   audio file, but can't find lyrics file when in lyrics mode
    *   kuro file, but can't find lyrics file.
    *   audio file in meta/spectrum mode, but change to full screen.
    */
    MMI_MSCR_CONTENT_VIDEO_DEMO,
    MMI_MSCR_CONTENT_TOTAL
        
} mmi_medply_content_enum;

typedef enum
{
    MMI_MSCR_LAYER_ID_TOP = 0,
    MMI_MSCR_LAYER_ID_MID,
    MMI_MSCR_LAYER_ID_CTL,
    
    MMI_MSCR_LAYER_ID_TOTAL
        
} mmi_medply_layer_enum;

typedef enum
{    
    MMI_MSCR_ITEM_ID_TITLE_TXT = 0,
    MMI_MSCR_ITEM_ID_META_IMG,
    MMI_MSCR_ITEM_ID_META_TXT,
    MMI_MSCR_ITEM_ID_LYRICS,
    MMI_MSCR_ITEM_ID_SPECTRUM,
    
    MMI_MSCR_ITEM_ID_DURATION,
    MMI_MSCR_ITEM_ID_LKEY_BTN,
    MMI_MSCR_ITEM_ID_RKEY_BTN,
    
    MMI_MSCR_ITEM_ID_TOTAL
        
} mmi_medply_item_enum;

typedef struct
{
    S16 x;
    S16 y;    
    S16 w;
    S16 h;

} mmi_medply_rect_struct;

typedef struct
{    
    S16 view_x;
    S16 view_y;
    
    U16 bg_img_id;
    U16 fg_img_id;
    U16 md_img_id;
    U8  fg_range;
    U8  md_range;
    #if defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_FTE_SUPPORT__)
    MMI_BOOL is_9slice;
    U32 resized_width;
    U32 resized_height;
    #endif
} mmi_medply_img_box_struct;

typedef struct
{    
    S16 bg_view_x;
    S16 bg_view_y;
	S16 fg_view_x;
	S16 fg_view_y; /*这个是算出来的*/

	U16 fg_img_id;
	U16 bg_img_id;

	S16 fg_step; /*滑块间间隔*/
	S16 fg_offset_y; /*滑块在最上方时，与BG Image的相对位置*/

} mmi_medply_tone_box_struct;

typedef struct
{    
    mmi_medply_rect_struct pen_rgn;

    S16 view_x;
    S16 view_y;
    
    U16 up_img_id;
    U16 down_img_id;
    U16 disable_img_id;
    
} mmi_medply_pen_box_struct;

typedef struct
{    
    S16 view_x;
    S16 view_y;
    
    U16 base_number_img_id;
    U16 bias_img_id;
    U16 colon_img_id;    
    
} mmi_medply_tck_box_struct;



#define MMI_MSCR_BUTTON_ID_BASIC_TOTAL  		(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK+1)
#define MMI_MSCR_BUTTON_ID_EX_TOTAL				MMI_MSCR_BUTTON_ID_BASIC_TOTAL

typedef struct
{
    S16 wait_ani_w;
    S16 wait_ani_h;
    
    mmi_medply_rect_struct      layer_rgn[MMI_MSCR_LAYER_ID_TOTAL];    
    mmi_medply_rect_struct      items_rgn[MMI_MSCR_ITEM_ID_TOTAL];
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mmi_medply_rect_struct      subtitle_rgn;
    #endif

    mmi_medply_pen_box_struct   touch_btn[MMI_MSCR_BUTTON_ID_EX_TOTAL];
    mmi_medply_img_box_struct   rates_img;
    mmi_medply_img_box_struct   duration_img;
    mmi_medply_img_box_struct   volume_img;	
	mmi_medply_tck_box_struct   ticks_box;
} mmi_medply_ui_struct;

typedef struct
{
    mmi_medply_details_for_display_struct   meta_data;

    scrolling_text  title;                  /*title*/
    scrolling_text  album;                  /*album*/
    scrolling_text  artist;                 /*artist*/
    
    U32 flags;
    
} mmi_medply_meta_struct;

#define MMI_MSCR_META_HAS_INIT_TITLE        0x0001
#define MMI_MSCR_META_HAS_MOVE_TITLE        0x0002 
#define MMI_MSCR_META_HAS_INIT_ALBUM        0x0004
#define MMI_MSCR_META_HAS_MOVE_ALBUM        0x0008 
#define MMI_MSCR_META_HAS_INIT_ARTIST       0x0010
#define MMI_MSCR_META_HAS_MOVE_ARTIST       0x0020  

#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
#define MMI_MSCR_LYRICS_MAX_LINE            6//9 
#define MMI_MSCR_LYRICS_GAP_H               6
#define MMI_MSCR_LYRICS_BG_GDI_COLOR        GDI_COLOR_BLACK
#define MMI_MSCR_LYRICS_FOCUS_COLOR_FG      gui_color(255, 255, 0)
#define MMI_MSCR_LYRICS_FOCUS_COLOR_BG      gui_color(128, 128, 0)
#define MMI_MSCR_LYRICS_NORMAL_COLOR_FG     gui_color(203, 203, 203)
#define MMI_MSCR_LYRICS_NORMAL_COLOR_BG     gui_color(101, 101, 101)

typedef struct
{    
    mmi_medply_rect_struct rgn_txt;
    mmi_medply_rect_struct rgn_clip;
    U16 last_time;
    U16 curr_time;
    U16 next_time;
    U16 line_focus_id;
    U16 time_out;
    U16 line_id[MMI_MSCR_LYRICS_MAX_LINE+1];  /*add 1 for scroll display*/ 
    U8  line_focus;
    U8  line_count;
    U8  font_height;
    U8  line_height;    
    
} mmi_medply_lyrics_box_struct;
#endif  /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/

extern  MMI_theme *current_MMI_theme;

#define mmi_mscr_delete_layer               gdi_layer_free

#define MMI_MSCR_ERR_TRACE(VAL)					\
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MAIN_SCREEN_ERR_REPORT, __LINE__, VAL)
#define MMI_MSCR_MSG_TRACE(VAL)					\
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MAIN_SCREEN_MSG_REPORT, __LINE__, VAL)

#endif  /*#ifdef __MMI_MEDIA_PLAYER__*/

#endif  /*_MEDIA_PLAYER_MAIN_SCREEN_H*/
