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
*  MediaPlayerPlayListUI.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player play list UI
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __MEDIA_PLAYER_PLAY_LIST_UI_H__
#define __MEDIA_PLAYER_PLAY_LIST_UI_H__

#include "MMI_features.h"

#if defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"

#include "PlstSrvGprot.h"
#include "MediaPlayerPlayList.h"

#include "FileMgrSrvGProt.h"

#define MMI_MEDPLY_LISTUI_FILENAME          L"media_lib"
#define MMI_MEDPLY_LISTUI_MAX_VIEW_DEPT     6
#define MEDPLY_MAX_OPTION_LIST              15

/*state flag*/
#define MMI_MEDPLY_LISTUI_IS_SEARCH     0x00000001
#define MMI_MEDPLY_LISTUI_IS_MULTISEL   0x00000002
#define MMI_MEDPLY_LISTUI_IS_MULTIADD   0x00000004
#define MMI_MEDPLY_LISTUI_IS_ORGANIZE   0x00000008

#define MMI_MEDPLY_LISTUI_IS_REFRESH    0x00000010
#define MMI_MEDPLY_LISTUI_IS_DEF_PLST   0x00000020
#define MMI_MEDPLY_LISTUI_NEED_RESET_HL 0x00000040
#define MMI_MEDPLY_LISTUI_IS_SET_CACHE  0x00000080

typedef enum
{
    MEDPLY_DETAIL_FILENAME,
    MEDPLY_DETAIL_TITLE,
    MEDPLY_DETAIL_ARTIST,
    MEDPLY_DETAIL_ALBUM,
    MEDPLY_DETAIL_AUTHOR,
    MEDPLY_DETAIL_GENRE,
    MEDPLY_DETAIL_COPYRIGHTS,
    MEDPLY_DETAIL_DESCRIPTION,
    MEDPLY_DETAIL_YEAR,
    MEDPLY_DETAIL_TRACK_NUM,
    MEDPLY_DETAIL_DURATION,
    MEDPLY_DETAIL_SIZE,
    MEDPLY_DETAIL_QUALITY,
    MEDPLY_DETAIL_CHANNEL, 
    MEDPLY_DETAIL_PLAY_COUNT,
    MEDPLY_DETAIL_USER_RATING,
    MEDPLY_DETAIL_VOLUME,
    MEDPLY_DETAIL_LAST_PLAYED,
    MEDPLY_DETAIL_LAST_MODIFIED,
    MEDPLY_DETAIL_LOCAL,
    MEDPLY_DETAIL_TOTAL
} mmi_medply_listui_detail_enum;


typedef enum
{
    LIST_TYPE_NONE,
    LIST_TYPE_ALL_SONG_LIST,
    LIST_TYPE_ALL_VIDEO_LIST,
    LIST_TYPE_ARTIST_LIST,    
    LIST_TYPE_ALBUM_LIST,
    LIST_TYPE_GENRE_LIST,
    LIST_TYPE_PLST_LIST,
    LIST_TYPE_ACTIVE_LIST,
    LIST_TYPE_ARTIST_ALBUM_LIST,
    LIST_TYPE_CATEGORY_SONG_LIST,    //song list under category
    LIST_TYPE_PLST_SONG_LIST,
    LIST_TYPE_ADDTO_PLST_LIST,
    LIST_TYPE_IMAGE_FLOW,
    LIST_TYPE_TOTAL
    
} mmi_medply_listui_list_type;

/* details enum */

typedef enum
{
    LISTUI_DETAILS_TYPE_TITLE,
    LISTUI_DETAILS_TYPE_ARTIST,
    LISTUI_DETAILS_TYPE_ALBUM,
    LISTUI_DETAILS_TYPE_GENRE,
    LISTUI_DETAILS_TYPE_AUTHOR,
    LISTUI_DETAILS_TYPE_DESCRIPTION,
    LISTUI_DETAILS_TYPE_TRACK_NUM,
    LISTUI_DETAILS_TYPE_YEAR,
    LISTUI_DETAILS_TYPE_USER_RATING,
    LISTUI_DETAILS_TYPE_FORMAT,
    LISTUI_DETAILS_TYPE_TOTAL
} mmi_medply_details_item_enum;

typedef enum
{
    /* base info. */
    MEDPLY_DB_UPDATE_TITLE              = 0x00000001,
    MEDPLY_DB_UPDATE_ARTIST             = 0x00000002,
    MEDPLY_DB_UPDATE_ALBUM              = 0x00000004,
    /* details info. */
    MEDPLY_DB_UPDATE_GENRE              = 0x00000100,
    MEDPLY_DB_UPDATE_DESCRIPTION        = 0x00000200,
    MEDPLY_DB_UPDATE_AUTHOR             = 0x00000400,
    MEDPLY_DB_UPDATE_YEAR               = 0x00000800,
    MEDPLY_DB_UPDATE_TRACKNUM           = 0x00001000,
    /* ext info. */
    MEDPLY_DB_UPDATE_COUNT              = 0x00010000,
    MEDPLY_DB_UPDATE_VOL                = 0x00020000,
    MEDPLY_DB_UPDATE_RATING             = 0x00040000,
    MEDPLY_DB_UPDATE_PLAYED             = 0x00080000,
    MEDPLY_DB_UPDATE_MODIFIED           = 0x00100000,
    /* display info. */
    MEDPLY_DB_UPDATE_LYRICS             = 0x01000000,
    MEDPLY_DB_UPDATE_ARTWORK            = 0x02000000,
    
    MEDPLY_DB_UPDATE_ALL                = 0x7FFFFFFF
} mmi_medply_db_update_item_flag;


typedef enum
{
    LISTUI_FMGR_ADD_FILES = 0,
    LISTUI_FMGR_EDIT_ALBUM,
    LISTUI_FMGR_TYPE_END
} mmi_medply_listui_fmgr_type;


typedef enum
{
    LISTUI_TILT_STATE_INVALID = 0,
    LISTUI_TILT_STATE_INIT,
    LISTUI_TILT_STATE_HORIZ,
    LISTUI_TILT_STATE_VERTI,

    LISTUI_TILT_STATE_END
} mmi_medply_listui_tilt_state;


typedef struct
{
    U16 year;
    U8 month;
    U8 day;
    U8 hour;
    U8 min;
} mmi_medply_time_record_struct;

typedef struct
{
    S32 hint_idx;
    UI_character_type hint_buff[MAX_SUBMENU_CHARACTERS];
} mmi_medply_plstui_hint_cache_struct;

typedef struct
{
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    UI_character_type title[MMI_MEDPLY_MAX_TITLE_LEN + 1];
    UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN + 1];
    UI_character_type album[MMI_MEDPLY_MAX_ALBUM_LEN + 1];
    UI_character_type author[MMI_MEDPLY_MAX_AUTHOR_LEN + 1];
    UI_character_type genre[MMI_MEDPLY_MAX_GENRE_LEN + 1];
    UI_character_type year[MMI_MEDPLY_MAX_YEAR_LEN];
    UI_character_type copyrights[MMI_MEDPLY_MAX_COPYRIGHTS_LEN + 1];
    UI_character_type description[MMI_MEDPLY_MAX_DESCRIPTION_LEN + 1];
    UI_character_type track_num[MMI_MEDPLY_MAX_TRACKNUM_LEN];
    UI_character_type duration[MMI_MEDPLY_MAX_DURATION_LEN];
    UI_character_type size[MMI_MEDPLY_MAX_SIZE_LEN];/* max size for U32 bytes type is "1194:59:59" */
    UI_character_type quality[25];
    UI_character_type channel_num[20];
    UI_character_type play_count[20];    /* 65536 */ 
    UI_character_type user_rating[MMI_MEDPLY_MAX_USER_RATING_LEN]; 
    UI_character_type volume[20];/* 65535 */
    UI_character_type last_played[MMI_MEDPLY_MAX_TIME_LEN];
    UI_character_type last_modified[MMI_MEDPLY_MAX_TIME_LEN];
    UI_character_type local[MEDPLY_MAX_FILE_LEN];
} mmi_medply_listui_details_view_struct;

typedef struct
{   
    srv_plst_media_details_struct*          raw_p;
    mmi_medply_listui_details_view_struct*  view_p;
    mmi_medply_listui_details_view_struct*  backup_p;   
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1)];
    U16 details_item_id[MEDPLY_DETAIL_TOTAL];
    U32 modify_flag;
    U32 media_id;
    MMI_BOOL modify_rate_by_mscr;
    mmi_id inline_gid;
    U16 highlighted_item;
    U16 edit_index;
    U16 format;
    U8  rate_index;
    U8  is_audio;
    U8  temp_rating;
    U8  rating_update_flag;
}mmi_medply_listui_details_info_struct;


typedef struct
{
    U16 title[MEDPLY_MAX_FILE_LEN];   

    S32 flag;

    mmi_id child_id;
    mmi_id fwd_id;
    S32 list_type; //please refer mmi_medply_listui_list_type, for config ui customize,related get_item,get_hint callback.
    S32 list_scr_id;
    U32 total;
    S32 highlight;        
    U32 artist_idx;
    U32 artist_id;
    U32 def_list_type;
    U32 imgfl_index;
    /* backup before entry addto plst list*/
    S32 list_type_backup;
    S32 list_scr_id_backup;
    /* OPT data for mark several */
    S32 mark_highlight;
    S32 mark_ref;
    /* organize flag */
    S32 hold_id;
    MMI_BOOL is_hold;
    MMI_BOOL is_changed;
    /* OPT data, for add to plst */
    S32 cache_file_idx;//addto_plst_idx;
    S32 cache_plst_idx;
    S32 launch_scr_id;
    S32 search_scr_id;
    /* OPT data for send &  use as */
    S32 opt_menu_id;
    S32 opt_hilite_index;
    U16 curr_hilite_path[MEDPLY_MAX_PATH_LEN];
    U16 popup_strid;
    
} mmi_medply_listui_list_info_struct;


/*
**  Editor.
*/
typedef struct
{
    U8 editor_type;
    U16 limit; 
    U16 editor_title_id;
    UI_character_type editor_buffer[MMI_MEDPLY_MAX_EDITOR_LEN + 1];
    UI_string_type original_string_p;
    mmi_id  gid;
    MMI_BOOL (*done_func)(void);
} mmi_medply_listui_editor_cntx_struct;


typedef struct
{
    UI_string_type path;
    void*   user_date;          /*reserve for caller*/
    void*   mem_ptr;            /*memory for create service handle*/
    U8*     temp_mem_ptr;
    S32     srv_hdlr;
    S32     max_item_support;   /* max list item support */
    U32     mem_size;           /* memory size */
    S32     state_flag;
    U32     def_list_set;
    
}mmi_medply_listui_srv_contx_struct;


/*
translate UI list flow to DB service Logic.
UI list menu only care about list_type.
+---------+--------+              +-------------+
|  index  |  view  |              |  list_type  |
+---------+--------+ <-curr_prt ->+-------------|
|  index  |  view  |              |  list_type  | 
+---------+--------+              +-------------|
|  index  |  view  |              |  list_type  |   
+---------+--------+              +-------------+
*/  
typedef struct
{
    srv_plst_list_view_struct view_set[MMI_MEDPLY_LISTUI_MAX_VIEW_DEPT];
    S32 list_type[MMI_MEDPLY_LISTUI_MAX_VIEW_DEPT];
    S32 curr_ptr; //initialize -1;
}mmi_medply_listui_view_stack_struct;

typedef struct
{
    MMI_BOOL is_play_fail;
    U32 total;
    U32 curr_sel_index;
    U32 pick_index;
    S32 failed_count;
    S32 failed_nofile;
    S32 last_error;
    
    U32 plst_id;
    U32 id;
} mmi_medply_listui_playing_cntx_struct;

typedef struct
{
    mmi_medply_listui_list_info_struct  list_info;
    mmi_medply_listui_playing_cntx_struct playing;
    mmi_medply_listui_view_stack_struct view_stack;
    mmi_medply_listui_srv_contx_struct  srv_cntx;
    mmi_medply_listui_details_info_struct details_info;
    mmi_medply_listui_editor_cntx_struct  editor_cntx;
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
    mmi_medply_listui_tilt_state   tilt_state;
    S32   tilt_handle;
#endif
} mmi_medply_listui_context_struct;

#define MMI_LISTUI_ERR_TRACE(VAL) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_FTE_LISTUI_ERR_REPORT, __LINE__, VAL)

#define MMI_LISTUI_WARN_TRACE(VAL) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_FTE_LISTUI_WARN_REPORT, __LINE__, VAL)

#define MMI_LISTUI_MSG_TRACE1(VAL) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_FTE_LISTUI_MSG_REPORT, __LINE__, VAL)

#define MMI_LISTUI_MSG_TRACE2(VAL1, VAL2) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_FTE_LISTUI_MSG_REPORT, __LINE__, VAL1, VAL2)

#endif /* __MMI_MEDIA_PLAYER_PLST_DB_STYLE__ */
#endif /* __MEDIA_PLAYER_PLAY_LIST_UI_H__ */
