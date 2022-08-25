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
*  AudioPlayerMainScreen.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Karaoke Header file
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __KARAOKE_H__
#define __KARAOKE_H__

#include "mmi_features.h"
#include "kal_public_defs.h"
#include "mmidatatype.h"
#include "FileMgrSrvGprot.h"
#include "gui_data_types.h"

#ifdef __MMI_KARAOKE__

#ifndef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
#define __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
#endif

#define MMI_KARAOKE_MARK_DRIVE(path) ((path)[0] = (UI_character_type)g_karaoke_cntx.current_list.present_list)
#define MMI_KARAOKE_MARK_LNAME(path) ((path)[0] = L'L')
#define MMI_KARAOKE_MARK_SNAME(path) ((path)[0] = L'S')
#define MMI_KARAOKE_IS_LNAME(path) ((path)[0] == L'L')
#define MMI_KARAOKE_IS_SNAME(path) ((path)[0] == L'S')
#define MMI_KARAOKE_EOS(nob) ((nob)>1 ? ((nob)>>1)-1: 0)

#define MMI_KARAOKE_DEFAULT_DRV SRV_FMGR_CARD_DRV  //SRV_FMGR_PUBLIC_DRV

#define MMI_KARAOKE_MAX_DEPTH_DIRECTORY          (16)

#define MMI_KARAOKE_LIST_SEARCH_LOOP_TIMER		(20)  //when search exceed MMI_KARAOKE_LIST_SEARCH_LIMIT_IN_LOOP in one folder, break
#define MMI_KARAOKE_LIST_SEARCH_LIMIT_IN_LOOP	(10)  //when search exceed this limit in one folder, break for MMI_KARAOKE_LIST_SEARCH_LOOP_TIMER

#define MMI_KARAOKE_LIST_BUFF_SIZE   (16)
#define MMI_KARAOKE_MAX_LIST_ITEM    (1024)
#define MMI_KARAOKE_LIST_RECORD_SIZE (((SRV_FMGR_PATH_MAX_LEN+1)+1)*ENCODING_LENGTH)

#define MMI_KARAOKE_REMOVE_BUF_SIZE     (10 * MMI_KARAOKE_LIST_RECORD_SIZE)

#define MMI_KARAOKE_DELAY_PLAY	    (1000)
#define MMI_KARAOKE_VOLUME_DELAY	(5000)

#define MMI_KARAOKE_LIST_DEFAULT_FOLDER                 L"@Karaoke"
#define MMI_KARAOKE_SONG_LIST_DEFAULT_PATH              L""//L"My Music\\"
#define MMI_KARAOKE_SONG_LIST_DEFAULT_NAME              L"song_list.sal"
#define MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH            L"Karaoke_Records\\"
#define MMI_KARAOKE_RECORD_LIST_DEFAULT_NAME            L"record_list.sal"

#define MMI_KARAOKE_NO_ERROR                (0)
#define MMI_KARAOKE_ERR_BEGIN               (-10500)
#define MMI_KARAOKE_ERR_WRITE_FAILED        (-10501)
#define MMI_KARAOKE_ERR_READ_FAILED         (-10502)
#define MMI_KARAOKE_ERR_NOT_PLST            (-10503)    /* it is not playlist file. */
#define MMI_KARAOKE_ERR_INVALID_FILENAME    (-10504)
#define MMI_KARAOKE_ERR_EMPTY_FILENAME      (-10505)
#define MMI_KARAOKE_ERR_FILE_EXISTS         (-10506)
#define MMI_KARAOKE_ERR_WRONG_VER           (-10507)    /* wrong version number. */
#define MMI_KARAOKE_ERR_LIST_FULL           (-10508)
#define MMI_KARAOKE_ERR_LIST_DAMAGED        (-10509)

#define MMI_KARAOKE_ERR_CREATE_FAILED       (-10510)
#define MMI_KARAOKE_ERR_OPEN_FAILED         (-10511)
#define MMI_KARAOKE_ERR_INVALID_PARA        (-10512)

#define MMI_KARAOKE_ERR_NO_SPACE            (-10513)
#define MMI_KARAOKE_ERR_EXIST_FILE          (-10514)

#define MMI_KARAOKE_ERR_NO_MEM              (-10515)
#define MMI_KARAOKE_ERR_META                (-10516)

#define MMI_KARAOKE_ERR_INVALID_FORMAT		(-10517)

#define MDI_KARAOKE_VOL_EX_MAX 16 //should not equal to MDI_KARAOKE_VOL_EX_MIN
#define MDI_KARAOKE_VOL_EX_MIN 0  //should not equal to MDI_KARAOKE_VOL_EX_MAX

typedef enum
{
	MMI_KARAOKE_EVENT_PREPARE_LYRIC,
	MMI_KARAOKE_EVENT_SING,
	MMI_KARAOKE_EVENT_PLAY_RECORD
} mmi_karaoke_event_enum;

typedef enum
{
    MMI_KARAOKE_ITEM_SONG_LIST,
    MMI_KARAOKE_ITEM_RECORD_LIST
} mmi_karaoke_item_enum;

typedef enum
{
    MMI_KARAOKE_GENERATE_PHASE_INIT,
    MMI_KARAOKE_GENERATE_PHASE_SET_DRV,
    MMI_KARAOKE_GENERATE_PHASE_SEARCH_FIRST,
    MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT,
    MMI_KARAOKE_GENERATE_PHASE_SEARCH_FOLDER,
    MMI_KARAOKE_GENERATE_PHASE_FORWARDS,
    MMI_KARAOKE_GENERATE_PHASE_BACKWARDS,
    MMI_KARAOKE_GENERATE_PHASE_FINISH,
    MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR,
    MMI_KARAOKE_GENERATE_PHASE_SEARCH_ODF,
    MMI_KARAOKE_GENERATE_PHASE_BACKWARDS_ODF,
    MMI_KARAOKE_GENERATE_PHASE_CANCEL,
    MMI_KARAOKE_GENERATE_PHASE_END
} mmi_karaoke_generate_phase_enum;

typedef enum
{
    MMI_KARAOKE_ACTION_COPY,
    MMI_KARAOKE_ACTION_DELETE,
    MMI_KARAOKE_ACTION_DELETE_FAIL,
    MMI_KARAOKE_ACTION_RENAME,
    MMI_KARAOKE_ACTION_MOVE,
    MMI_KARAOKE_ACTION_DELETE_ALL,
    MAX_MMI_KARAOKE_ACTION
} mmi_karaoke_action_enum;

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
	MMI_KARAOKE_PEN_STATUS_NONE,
	MMI_KARAOKE_PEN_STATUS_DOWN_IN_PREV,
	MMI_KARAOKE_PEN_STATUS_DOWN_IN_NEXT,
	MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK,
	MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC,
	MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK_ICON,
	MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC_ICON
} mmi_karaoke_pen_status;
#endif  //__MMI_TOUCH_SCREEN__



typedef struct
{
    LOCAL_PARA_HDR
    void *context;
} mmi_karaoke_search_continue_req_struct;

/*
**  stack node structure
*/
typedef struct
{
    U16 level;   /* stack level. */
    U16 total_sub_folder;    /* total sub-folder number in this level. */
    U16 index;               /* current index in all sub-folder. */
    U16 fs_index;            /* fs index for FS_FindFirst(). */
} mmi_karaoke_list_stack_node_struct;

/*
**  Structure for getting all media files under a folder.1092
*/
typedef struct
{
    U32 appended_number;
    U32 total_number;
    S32 last_error_code;
    U32 footer_pattern_offset;
    FS_HANDLE search_handle;
    FS_HANDLE generate_handle;
    
    U16 phase;
    U16 stack_index;     /* folder level & stack level. */
    
    UI_character_type path_cache[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    mmi_karaoke_list_stack_node_struct stack[MMI_KARAOKE_MAX_DEPTH_DIRECTORY];
#ifdef __DRM_V02__
    void* DRM_find_cntx;
#endif
} mmi_karaoke_list_generate_struct;

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];   
    U8 file_type;
    U8 is_short;
} mmi_karaoke_list_item_info_struct;

typedef struct
{
    S32 total;
    S32 highlight;
    U16 cache_start_index;
    U16 cache_end_index;
    UI_character_type title[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_karaoke_list_item_info_struct cache[MMI_KARAOKE_LIST_BUFF_SIZE];
} mmi_karaoke_dynamic_list_data_struct;

typedef struct
{
    /* present play list */
    U8 present_list;
    MMI_BOOL list_loaded;
    FS_HANDLE fs_hdlr;
    S32 remove_offset;
    S32 remove_count;
    FS_HANDLE remove_hdlr;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_karaoke_dynamic_list_data_struct list_data;
} mmi_karaoke_list_struct;

typedef struct
{
    mmi_id group_id;
    mmi_karaoke_item_enum item;
    mmi_karaoke_list_struct current_list;
    mmi_karaoke_list_generate_struct generate_info;
	U32 new_play_time;  /*the latest play time get from hardware*/
	UI_character_type filefullname[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	UI_character_type Rec_filepath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 +17];
	UI_character_type song_title[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	U32 duration; /*song duration in MS*/
	S32 songtitle_x;
	S32 songtitle_y;
	S32 songtitle_width;
	S32 songtitle_height;
	MMI_BOOL need_resume;
	MMI_BOOL need_resing;
	MMI_BOOL is_playing_records;
	MMI_BOOL is_interrupted;
	MMI_BOOL play_record_for_reviewing;
	MMI_BOOL is_singing;
	MMI_BOOL is_paused;
	MMI_BOOL is_eof;
	MMI_BOOL mdi_callback_registed;
	MMI_BOOL origin_enable;
	MMI_BOOL key_longpress;
	MMI_BOOL focus_on_aud_vol;  //True means we're going to adjust aud vol, False means we're going to adjust mic's volume
	MMI_BOOL aud_mute;
	MMI_BOOL mic_mute;
	kal_uint8 vol;
	kal_uint16 aud_vol;  // Audio volume for sing
	kal_uint16 mic_vol;  // Mic volume for sing
	#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
	kal_uint16 remix_aud_vol;  // Audio volume for remix
	kal_uint16 remix_mic_vol;  // Mic volume for remix
	#endif
	#ifdef __LINE_IN_SUPPORT__
	MMI_BOOL force_use_linein_mice;
	#endif
    MMI_BOOL remove_all;  //for remove confirm
    MMI_BOOL record_auto_gen;
	#ifdef __MMI_TOUCH_SCREEN__
	mmi_karaoke_pen_status pen_status;
	#endif
	GDI_HANDLE animation_hdlr;  //if there is no lyric when singing/playing, show the animation
    S32 record_list_highlight_index;  //for saving the highlight index before record is deleted
    kal_uint8* vol_layer_buf;
	GDI_HANDLE vol_layer_hdlr;
} mmi_karaoke_context_struct;
#define KARAOKE_AUD_GAIN_MIN 0    //should not equal to KARAOKE_AUD_GAIN_MAX
#define KARAOKE_AUD_GAIN_MAX 0x100  //should not equal to KARAOKE_AUD_GAIN_MIN
#define KARAOKE_AUD_VOL_DEFAULT 12 //default level12
#define KARAOKE_AUD_GAIN_UNIT ((KARAOKE_AUD_GAIN_MAX-KARAOKE_AUD_GAIN_MIN)/(MDI_KARAOKE_VOL_EX_MAX-MDI_KARAOKE_VOL_EX_MIN))

#define KARAOKE_MIC_GAIN_MIN 0    //should not equal to KARAOKE_MIC_GAIN_MAX
#define KARAOKE_MIC_GAIN_MAX 0x300  //should not equal to KARAOKE_MIC_GAIN_MIN
#define KARAOKE_MIC_VOL_DEFAULT 12 //default level12
#define KARAOKE_MIC_GAIN_UNIT ((KARAOKE_MIC_GAIN_MAX-KARAOKE_MIC_GAIN_MIN)/(MDI_KARAOKE_VOL_EX_MAX-MDI_KARAOKE_VOL_EX_MIN))


#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
#define KARAOKE_REMIX_AUD_GAIN_MIN 0  //should not equal to KARAOKE_REMIX_AUD_GAIN_MAX
#define KARAOKE_REMIX_AUD_GAIN_MAX 0x100 //should not equal to KARAOKE_REMIX_AUD_GAIN_MIN
#define KARAOKE_REMIX_AUD_VOL_DEFAULT 12 //default level12
#define KARAOKE_REMIX_AUD_GAIN_UNIT ((KARAOKE_REMIX_AUD_GAIN_MAX-KARAOKE_REMIX_AUD_GAIN_MIN)/(MDI_KARAOKE_VOL_EX_MAX-MDI_KARAOKE_VOL_EX_MIN))

#define KARAOKE_REMIX_MIC_GAIN_MIN 0 //should not equal to KARAOKE_REMIX_MIC_GAIN_MAX
#define KARAOKE_REMIX_MIC_GAIN_MAX 0x300 //should not equal to KARAOKE_REMIX_MIC_GAIN_MIN
#define KARAOKE_REMIX_MIC_VOL_DEFAULT 12 //default level12
#define KARAOKE_REMIX_MIC_GAIN_UNIT ((KARAOKE_REMIX_MIC_GAIN_MAX-KARAOKE_REMIX_MIC_GAIN_MIN)/(MDI_KARAOKE_VOL_EX_MAX-MDI_KARAOKE_VOL_EX_MIN))
#endif

#if defined(__MMI_MAINLCD_240X320__)
#define TITLE_X 0
#define TITLE_Y 20
#define TITLE_width UI_DEVICE_WIDTH
#define TITLE_height 35

#define LYRICS_X  35
#define LYRICS_Y   55
#define LYRICS_width  (UI_DEVICE_WIDTH-70)
#define LYRICS_height (UI_DEVICE_HEIGHT-LYRICS_Y-15-40-10-15-10+1)

#define LYRICS_PICTURE_X (35+(LYRICS_width/*LYRICS_width*/-90)/2)
#define LYRICS_PICTURE_Y (65+(LYRICS_height/*LYRICS_height*/-81)/2)
#define LYRICS_PICTURE_width 90
#define LYRICS_PICTURE_height 81

#define TIME_X 5//10;
#define TIME_Y (LYRICS_Y+LYRICS_height + 10)
#define TIME_width (UI_DEVICE_WIDTH-20)
#define TIME_height 15

#define PLAY_REC_TIME_X 5//10;
#define PLAY_REC_TIME_Y (LYRICS_Y+LYRICS_height)
#define PLAY_REC_TIME_width (UI_DEVICE_WIDTH-10)
#define PLAY_REC_TIME_height 15

#define KARAOKE_BG_PROGRESS_X 5
#define KARAOKE_BG_PROGRESS_Y (UI_DEVICE_HEIGHT-40-25)
#define KARAOKE_BG_PROGRESS_W (UI_DEVICE_WIDTH-10)
#define KARAOKE_BG_PROGRESS_H 15

#define KARAOKE_FG_PROGRESS_X 5
#define KARAOKE_FG_PROGRESS_Y (UI_DEVICE_HEIGHT-40-25)
#define KARAOKE_FG_PROGRESS_W (UI_DEVICE_WIDTH-10)
#define KARAOKE_FG_PROGRESS_H 15

#define KARAOKE_PREV_ICON_X 0
#define KARAOKE_PREV_ICON_Y ((UI_DEVICE_HEIGHT-26)/2)
#define KARAOKE_PREV_ICON_W 32
#define KARAOKE_PREV_ICON_H 26

#define KARAOKE_NEXT_ICON_X (UI_DEVICE_WIDTH-32)
#define KARAOKE_NEXT_ICON_Y ((UI_DEVICE_HEIGHT-26)/2)
#define KARAOKE_NEXT_ICON_W 32
#define KARAOKE_NEXT_ICON_H 26

#define MMI_KARAOKE_TITLE_COLOR      gui_color(255, 255, 255)
#define MMI_KARAOKE_TIME_COLOR      gui_color(255, 255, 255)

#elif defined(__MMI_MAINLCD_320X240__)
S32 TITLE_X = 0;
S32 TITLE_Y = 17;
S32 TITLE_width = UI_DEVICE_WIDTH;
S32 TITLE_height = 20;

S32 LYRICS_X = 27;
S32 LYRICS_Y = 42;
S32 LYRICS_width = 270-4;
S32 LYRICS_height = 130;

S32 LYRICS_PICTURE_X = 25+(270/*LYRICS_width*/-90)/2;
S32 LYRICS_PICTURE_Y = 42+(130/*LYRICS_height*/-81)/2;
S32 LYRICS_PICTURE_width = 90;
S32 LYRICS_PICTURE_height = 81;

S32 TIME_X = 5;//10;
S32 TIME_Y = 172;
S32 TIME_width = 310;
S32 TIME_height = 17;

S32 KARAOKE_BG_PROGRESS_X = 0;
S32 KARAOKE_BG_PROGRESS_Y = 190;
S32 KARAOKE_BG_PROGRESS_W = UI_DEVICE_WIDTH;
S32 KARAOKE_BG_PROGRESS_H = 10;

S32 KARAOKE_FG_PROGRESS_X = 0;
S32 KARAOKE_FG_PROGRESS_Y = 190;
S32 KARAOKE_FG_PROGRESS_W = UI_DEVICE_WIDTH;
S32 KARAOKE_FG_PROGRESS_H = 10;

S32 KARAOKE_PREV_ICON_X = 0;
S32 KARAOKE_PREV_ICON_Y = (UI_DEVICE_HEIGHT-26)/2;
S32 KARAOKE_PREV_ICON_W = 32;
S32 KARAOKE_PREV_ICON_H = 26;

S32 KARAOKE_NEXT_ICON_X = UI_DEVICE_WIDTH-32;
S32 KARAOKE_NEXT_ICON_Y = (UI_DEVICE_HEIGHT-26)/2;
S32 KARAOKE_NEXT_ICON_W = 32;
S32 KARAOKE_NEXT_ICON_H = 26;

#define MMI_KARAOKE_TITLE_COLOR      gui_color(255, 255, 255)
#define MMI_KARAOKE_TIME_COLOR      gui_color(255, 255, 255)

#endif /* #if defined(__MMI_MAINLCD_240X320__) */

#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
#define MMI_KARAOKE_UI_UPDATE_PLAY_TIME 500
#if defined(__MMI_MAINLCD_240X320__)
#define MMI_KARAOKE_LYRICS_MAX_LINE		7
#else
#define MMI_KARAOKE_LYRICS_MAX_LINE		4
#endif
#define MMI_KARAOKE_LYRICS_GAP_H               2 
#define MMI_KARAOKE_LYRICS_FOCUS_COLOR_FG      gui_color(209, 235, 250)
#define MMI_KARAOKE_LYRICS_FOCUS_COLOR_BG      gui_color(255, 255, 255)
#define MMI_KARAOKE_LYRICS_NORMAL_COLOR_FG     gui_color(116, 200, 248)
#define MMI_KARAOKE_LYRICS_NORMAL_COLOR_BG     gui_color(245, 245, 245)

typedef struct
{
    S16 x;
    S16 y;    
    S16 w;
    S16 h;

} mmi_karaoke_rect_struct;

typedef struct
{
    S16 r;
    S16 g;    
    S16 b;

} mmi_karaoke_color_struct;


typedef struct
{    
    mmi_karaoke_rect_struct rgn_txt;
    mmi_karaoke_rect_struct rgn_clip;
	mmi_karaoke_color_struct color;
    U16 last_time;
    U16 curr_time;
    U16 next_time;
    U16 line_focus_id;
    U16 time_out;
    U16 line_id[MMI_KARAOKE_LYRICS_MAX_LINE+1];  /*add 1 for scroll display*/ 
    U8  line_focus;
    U8  line_count;
    U8  font_height;
    U8  line_height;
	U8  is_ready;
    
} mmi_karaoke_lyrics_box_struct;

#define  KARAOKE_LYRIC_MAX_LINE_COUNT      200   /* pre-defined number of lyirc lines */
#define  KARAOKE_LYRIC_STR_BUFF_MAX_SIZE   (8 * 1024)  /* pre-defined max lyric string buffer size : bytes */
#define  KARAOKE_LYRIC_TMP_BUFF_MAX_SIZE   128   /* pre-defined max lyric buffer size for one line : bytes ; must be two bytes aligned */

typedef enum
{
    LINE_START,
    LINE_END,
    TAG_START,
    TAG_END,
    TAG_LYRIC1,
    TAG_TIME1,
    TAG_TIME2,
    TAG_TIME3,
    TAG_MS,
    TAG_ID_AR,
    TAG_ID_TI,
    TAG_ID_AL,
    TAG_ID_BY,
    TAG_ID_OFFSET
} karaoke_lyric_parse_status_enum;

typedef struct
{
    U16 hour;
    U8  minute;
    U8  second;
}mmi_karaoke_time_struct;            /* temp memory */
#endif  //__MMI_KARAOKE_LYRIC_NLINE_DISPLAY__

#if defined(__MMI_MAINLCD_240X320__)
#define KARAOKE_VOL_LAYER_X 40
#define KARAOKE_VOL_LAYER_Y 80
#define KARAOKE_VOL_LAYER_W 160
#define KARAOKE_VOL_LAYER_H 150

#define MMI_KARAOKE_VOL_POP_BG_COLOR          gdi_act_color_from_rgb(255, 0x0a, 0x19, 0x36)
#define MMI_KARAOKE_VOL_POP_BORDER_COLOR      gdi_act_color_from_rgb(255, 0x38, 0x89, 0xa0)

#define KARAOKE_VOL_SPK_SEL_X 70 
#define KARAOKE_VOL_SPK_SEL_Y KARAOKE_VOL_LAYER_Y+15
#define KARAOKE_VOL_MIC_SEL_X 130 
#define KARAOKE_VOL_MIC_SEL_Y KARAOKE_VOL_LAYER_Y+15
#define KARAOKE_VOL_SEL_W 40
#define KARAOKE_VOL_SEL_H 120


#define KARAOKE_VOL_SPK_BG_X 85
#define KARAOKE_VOL_SPK_BG_Y KARAOKE_VOL_SPK_SEL_Y+10 
#define KARAOKE_VOL_MIC_BG_X 145
#define KARAOKE_VOL_MIC_BG_Y KARAOKE_VOL_SPK_SEL_Y+10 
#define KARAOKE_VOL_BG_W 10
#define KARAOKE_VOL_BG_H 60

#define KARAOKE_VOL_SPK_ICON_X 80
#define KARAOKE_VOL_SPK_ICON_Y KARAOKE_VOL_SPK_BG_Y+KARAOKE_VOL_BG_H+20 
#define KARAOKE_VOL_MIC_ICON_X 140
#define KARAOKE_VOL_MIC_ICON_Y KARAOKE_VOL_SPK_BG_Y+KARAOKE_VOL_BG_H+20 
#define KARAOKE_VOL_ICON_W 21
#define KARAOKE_VOL_ICON_H 21
#elif defined(__MMI_MAINLCD_320X240__)
#define KARAOKE_VOL_LAYER_X 55
#define KARAOKE_VOL_LAYER_Y 35
#define KARAOKE_VOL_LAYER_W 210
#define KARAOKE_VOL_LAYER_H 150

#define MMI_KARAOKE_VOL_POP_BG_COLOR          gdi_act_color_from_rgb(255, 0x0a, 0x19, 0x36)
#define MMI_KARAOKE_VOL_POP_BORDER_COLOR      gdi_act_color_from_rgb(255, 0x38, 0x89, 0xa0)

#define KARAOKE_VOL_SPK_SEL_X 96
#define KARAOKE_VOL_SPK_SEL_Y 50
#define KARAOKE_VOL_MIC_SEL_X 184
#define KARAOKE_VOL_MIC_SEL_Y 50
#define KARAOKE_VOL_SEL_W 40
#define KARAOKE_VOL_SEL_H 120


#define KARAOKE_VOL_SPK_BG_X 112
#define KARAOKE_VOL_SPK_BG_Y 63
#define KARAOKE_VOL_MIC_BG_X 197
#define KARAOKE_VOL_MIC_BG_Y 63
#define KARAOKE_VOL_BG_W 10
#define KARAOKE_VOL_BG_H 60

#define KARAOKE_VOL_SPK_ICON_X 107
#define KARAOKE_VOL_SPK_ICON_Y 133
#define KARAOKE_VOL_MIC_ICON_X 192
#define KARAOKE_VOL_MIC_ICON_Y 133
#define KARAOKE_VOL_ICON_W 21
#define KARAOKE_VOL_ICON_H 21
#endif

void mmi_karaoke_display_popup(S32 error_code, FuncPtr callback);

#endif  //__MMI_KARAOKE__
#endif  //__KARAOKE_H__ 

