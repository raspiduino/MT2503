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
*  AudioPlayerWalk.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player walk header file
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifdef __MMI_AUDPLY_WALK_PLAY__
#ifndef __AUDIO_PLAYER_WALK_H__
#define __AUDIO_PLAYER_WALK_H__
#include "AudioPlayerPlayList.h"


#define MMI_AUDPLY_WALK_DEFAULT_PATH    SRV_FMGR_CARD_DRV//SRV_FMGR_PUBLIC_DRV
#define MMI_AUDPLY_WALK_PATH_SIZE               ((SRV_FMGR_PATH_MAX_LEN+1) + 1)
#define MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY     (4)

#define MMI_AUDPLY_CACHE_NUM 50     //Cache Count
#define MMI_AUDPLY_RECACHE_NUM 10   //Temp Cache count
#define CACHE_JOB_NUM 15            //Job number
#define SEARCH_PREV_FOLDER_INDEX 60

typedef enum
{
    AUDPLY_PLAY_STYLE_BY_FILE_ORDER,
    AUDPLY_PLAY_STYLE_BY_PLAYLIST
} audply_play_style;

typedef enum
{
    CACHE_VALIDATION_SUCCESS,
    CACHE_VALIDATION_FAIL,
    CACHE_VALIDATION_BREAK_POINT_NOT_EXIST
}mmi_audply_cache_validation_result;

typedef enum
{
	AUDPLY_WALK_FOLDER_RESULT_FAIL,
	AUDPLY_WALK_FOLDER_RESULT_SUCCESS,
	AUDPLY_WALK_FOLDER_RESULT_CONTINUE
} mmi_audply_walk_folder_result_enum;

typedef enum
{
	AUDPLY_WALK_PREV_FOLDER_RESULT_FAIL,
	AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS,
	AUDPLY_WALK_PREV_FOLDER_RESULT_CONTINUE
} mmi_audply_walk_prev_folder_result_enum;


typedef enum
{
    AUDPLY_WALK_CACHE_STATE_NONE,
    AUDPLY_WALK_CACHE_STATE_CACHING,
    AUDPLY_WALK_CACHE_STATE_FINISH
}audply_walk_cache_state;

/*
**  stack node structure
*/
typedef struct
{
    U16 fs_index;            /* fs index for FS_FindFirst(). */
} mmi_audply_walk_stack_node_struct;


typedef struct
{
	UI_character_type Cache_file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	S32 FS_Index;
	S16 Next_valid_index;
}audply_walk_cache_struct;


typedef struct
{
	audply_walk_cache_struct cache_buffer[MMI_AUDPLY_CACHE_NUM];
	S16 Cache_header_index;
	S16 Cache_footer_index;
	audply_walk_cache_state cache_state;
	S32 Cache_index;
}audply_walk_cache_int_struct;

typedef struct
{
	audply_walk_cache_struct cache_buffer[MMI_AUDPLY_RECACHE_NUM];
	S16 Cache_header_index;
	S16 Cache_footer_index;
	audply_walk_cache_state cache_state;
	S32 Cache_index;
}audply_walk_cache_int_temp_struct;


typedef struct
{
	UI_character_type file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	mmi_audply_walk_stack_node_struct stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];
	FS_HANDLE current_file_handler;
}audply_walk_cache_service_work_struct;

typedef struct
{
	UI_character_type file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	FS_HANDLE current_file_handler;
}audply_walk_temp_cache_service_work_struct;


typedef struct
{
    U16 fs_index;            /* fs index for FS_FindFirst(). */
} audply_new_cache_stack_struct;


typedef struct
{
	CHAR *file_path;
	audply_new_cache_stack_struct *stack;
}audply_new_cache_context_struct;

typedef struct
{
	mmi_audply_walk_stack_node_struct temp_stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];
	UI_character_type previous_folder_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
}audply_new_cache_temp_out_context_struct;


typedef enum
{
    AUDPLY_WALK_STATE_NONE,
    AUDPLY_WALK_STATE_PREV,
    AUDPLY_WALK_STATE_NEXT
} audply_walk_state;


#ifdef __MMI_BTBOX_NOLCD__
typedef struct
{
    U16 level;   /* stack level. */
    U16 total_sub_folder;    /* total sub-folder number in this level. */
    U16 index;               /* current index in all sub-folder. */
    U16 fs_index;            /* fs index for FS_FindFirst(). */
} mmi_audply_playlist_stack_node_struct;
#endif


/*
**  Structure for walking all media files under root
*/
typedef struct
{
    MMI_BOOL auto_walk_done;  //to make sure only one auto walk each time
    MMI_BOOL searching;
	MMI_BOOL correcting_stack;  //whether correcting stack
    U16 total;
    //U32 sort_type;
    S32 last_error_code;
    U32 footer_pattern_offset;
    FS_HANDLE search_handle;
    audply_walk_state state;
    
    //U16 phase;
    U16 stack_index;     /* folder level & stack level. */
    U8 *filefullname;    /* point to g_audply.filefullname */
    
    UI_character_type path_cache[MMI_AUDPLY_WALK_PATH_SIZE];
    //mmi_audply_walk_cache_struct cache;
    mmi_audply_walk_stack_node_struct stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];
} mmi_audply_walk_struct;

#ifdef __MMI_BTBOX_NOLCD__
typedef struct{
	mmi_audply_walk_struct walk;
	U32 new_play_time;
}btbox_audply_struct;

typedef enum
{
    AUDPLY_WALK_BTBOX_STATE_IDLE,
    AUDPLY_WALK_BTBOX_STATE_PLAY,
    AUDPLY_WALK_BTBOX_STATE_PAUSE,
    AUDPLY_WALK_BTBOX_STATE_NONE
} audply_btbox_play_state;


typedef struct{
	audply_btbox_play_state play_state;
	U8 volume;
	U8 volume_nvram;
	MMI_BOOL is_support_pause;
	MMI_BOOL wait_next;
	MMI_BOOL is_kacaroke_enable;
	MMI_BOOL is_orignal_enable;
	MMI_BOOL kacaroke_timer_enable;
	MMI_BOOL is_prev_press;
	MMI_BOOL is_play_success;
	MMI_BOOL is_processing_karaoke;
	MMI_BOOL need_resume_play;
	MMI_BOOL play_by_background;
	MMI_BOOL is_init_done;
	UI_character_type filefullname[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	U32 Error_callback_time;
#ifdef __MMI_A2DP_SUPPORT__
	MMI_BOOL wait_open_bt;
    MMI_BOOL to_resume;
#endif
}audioplay_btbox_struct;

#endif

extern void mmi_audply_walk_init(void);
extern MMI_BOOL mmi_audply_walk_get_prev(U8 *filefullname);
extern MMI_BOOL mmi_audply_walk_get_next(U8 *filefullname);
extern void mmi_audply_walk_search_cancel_hdlr(void);

extern mmi_ret mmi_audply_walk_proc(mmi_event_struct *evt);

extern MMI_BOOL mmi_audply_check_is_the_first_file(CHAR *file_path);
extern MMI_BOOL mmi_audply_add_cache(CHAR *file_path);
extern MMI_BOOL mmi_audply_add_cache_previous_folder(CHAR *file_path);    
extern mmi_audply_walk_prev_folder_result_enum mmi_audply_get_prev_media_file_folder(CHAR *full_file_path);
extern mmi_audply_walk_prev_folder_result_enum mmi_audply_get_prev_media_file_folder_ext(CHAR *full_file_path, mmi_audply_walk_stack_node_struct *stack);

extern MMI_BOOL mmi_audply_add_cache_temp(CHAR *file_path);
extern void mmi_audply_walk_get_stack_info_by_path(CHAR *path);
extern MMI_BOOL mmi_audply_add_temp_cache_previous_folder(CHAR *file_path);
extern void mmi_audply_walk_cache_init(void);
extern void* mmi_audply_query_cache_cntx_pointer();
extern void* mmi_audply_query_cache_cntx_stack_pointer();
extern void mmi_audply_cache_set_caching_state(void);
extern MMI_BOOL mmi_audply_walk_is_audio_file(CHAR *filename);

#endif  //__AUDIO_PLAYER_WALK_H__
#endif  //__MMI_AUDPLY_WALK_PLAY__

