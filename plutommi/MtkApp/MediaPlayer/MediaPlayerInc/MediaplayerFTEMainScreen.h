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
*  MediaPlayerFTEMainScreen.h
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
//#include "Conversions.h"
#include "Gui_windows.h"

#include "MediaPlayerPlayList.h"
#include "kurotypedef.h"
#include "MMI_media_app_trc.h"
#include "MediaPlayerEnumDef.h"
#include "mmi_media_app_trc.h"

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

#define MMI_MSCR_GESGURE_MAX_VIEW = (MMI_MSCR_CONTENT_METAINFO + 1)

typedef enum
{
    MMI_MSCR_CONTENT_NULL  = 0,
    
    MMI_MSCR_CONTENT_LYRICS,
    MMI_MSCR_CONTENT_SPECTRUM,
    MMI_MSCR_CONTENT_METAINFO,
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
        
} mmi_medply_view_content_enum;

typedef enum
{
    MMI_MSCR_VIEW_MODE_AUDIO,
    MMI_MSCR_VIEW_MODE_VIDEO,
	MMI_MSCR_VIEW_MODE_KURO,
	MMI_MSCR_VIEW_MODE_TOTAL

}mmi_medply_view_mode_enum;

typedef enum
{
    MMI_MSCR_LAYER_ID_TOP = 0,
    MMI_MSCR_LAYER_ID_VIEW,
    MMI_MSCR_LAYER_ID_PANEL,  

    MMI_MSCR_LAYER_ID_TOTAL
       
} mmi_medply_fte_layer_enum;

typedef enum
{    
    MMI_MSCR_ITEM_ID_TITLE_TXT = 0,
    MMI_MSCR_ITEM_ID_ALBUM_TXT,
    MMI_MSCR_ITEM_ID_ARTIST_TXT,
    MMI_MSCR_ITEM_ID_SEP_LINE1,
    MMI_MSCR_ITEM_ID_SEP_LINE2,
    MMI_MSCR_ITEM_ID_COVER_IMG,
    MMI_MSCR_ITEM_ID_TIME_TXT,
    MMI_MSCR_ITEM_ID_DURATION_TXT,

    MMI_MSCR_ITEM_ID_LYRICS,
    MMI_MSCR_ITEM_ID_SPECTRUM,
    MMI_MSCR_ITEM_ID_VOLUME,
    
    MMI_MSCR_ITEM_ID_TOTAL
        
} mmi_medply_fte_item_enum;


typedef struct
{
    S16 x;
    S16 y;    
    S16 w;
    S16 h;

} mmi_medply_rect_struct;

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
    S16 start_x;
    S16 start_y;
    S16 move_step;
    U16 image_id;

} mmi_medply_slider_struct;


typedef struct
{    
    S16 view_x;
    S16 view_y;
    
    U16 bg_img_id;
    U16 fg_img_id;
    U16 md_img_id;
    U8  fg_range;
    U8  md_range;
    
} mmi_medply_img_box_struct;

typedef struct
{    
    S16 view_x;
    S16 view_y;
    
    U16 bg_img_id;
    U16 fg_img_id;
    U16 star_w;
    U16 interval;
    U8  temp_val;
   
} mmi_medply_star_box_struct;

typedef enum
{    
    MMI_MSCR_POPUP_TYPE_KURO = 0,
    MMI_MSCR_POPUP_TYPE_VOLUME,
    MMI_MSCR_POPUP_TYPE_RATING,
    
    MMI_MSCR_POPUP_TYPE_TOTAL,
    MMI_MSCR_POPUP_TYPE_NONE 
        
} mmi_medply_fte_popup_type_enum;


#define MMI_MSCR_BUTTON_IN_PANEL_BEGIN          MMI_MEDPLY_RGN_ID_PLAY_PAUSE
#define MMI_MSCR_BUTTON_IN_PANEL_TOTAL          (MMI_MEDPLY_RGN_ID_DURATION_BAR+1)
#define MMI_MSCR_BUTTON_IN_VIEW_BEGIN           MMI_MEDPLY_RGN_ID_SHUFFLE
#define MMI_MSCR_BUTTON_IN_VIEW_TOTAL           (MMI_MEDPLY_RGN_ID_USER_RATING+1)
#define MMI_MSCR_BUTTON_ID_EX_TOTAL             (MMI_MEDPLY_RGN_ID_KURO_REPEAT + 1)
#define MMI_MSCR_BUTTON_IN_POPUP_BEGIN          MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL
#define MMI_MSCR_BUTTON_IN_POPUP_TOTAL          (MMI_MEDPLY_RGN_ID_VOLUME_SPEAK + 1)

typedef struct
{
    mmi_medply_rect_struct      layer_rgn[MMI_MSCR_LAYER_ID_TOTAL];    
    mmi_medply_rect_struct      items_rgn[MMI_MSCR_ITEM_ID_TOTAL];
    mmi_medply_rect_struct      popup_rgn[MMI_MSCR_POPUP_TYPE_TOTAL];
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mmi_medply_rect_struct      subtitle_rgn;
    #endif

    mmi_medply_pen_box_struct   touch_btn[MMI_MSCR_BUTTON_ID_EX_TOTAL];
    mmi_medply_img_box_struct   duration_img;
    mmi_medply_img_box_struct   volume_img;
    mmi_medply_star_box_struct   rating_img;
	
    S16 wait_ani_w;
    S16 wait_ani_h;

} mmi_medply_ui_struct;


typedef struct
{
    mmi_medply_details_for_display_struct   meta_data;

    scrolling_text  title;                  /*title*/
    scrolling_text  album;                  /*album*/
    scrolling_text  artist;                 /*artist*/
    
    U32 flags;
    
} mmi_medply_meta_struct;

#define  MMI_MSCR_COLOR_WHITE              gui_color(255,255,255)

#define MMI_MSCR_META_HAS_READY             0x1000
#define MMI_MSCR_META_HAS_ARTWORK           0x2000
#define MMI_MSCR_META_HAS_INIT_TITLE        0x0001
#define MMI_MSCR_META_HAS_MOVE_TITLE        0x0002 
#define MMI_MSCR_META_HAS_INIT_ALBUM        0x0004
#define MMI_MSCR_META_HAS_MOVE_ALBUM        0x0008 
#define MMI_MSCR_META_HAS_INIT_ARTIST       0x0010
#define MMI_MSCR_META_HAS_MOVE_ARTIST       0x0020 


#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
#define MMI_MSCR_LYRICS_BORDER_Y            5 //pixtels
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


#define MMI_MSCR_ERR_TRACE(VAL)                 \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MAIN_SCREEN_ERR_REPORT, __LINE__, VAL)
#define MMI_MSCR_MSG_TRACE(VAL)                 \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MAIN_SCREEN_MSG_REPORT, __LINE__, VAL)
