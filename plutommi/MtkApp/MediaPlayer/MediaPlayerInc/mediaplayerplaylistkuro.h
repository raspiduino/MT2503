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
*  MeidaPlayerPlayListKuro.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media Player Playlist module for kuro player
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __MEDIA_PLAYER_PLAY_LIST_KURO_H__
#define __MEDIA_PLAYER_PLAY_LIST_KURO_H__

#if defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_KURO_SUPPORT__)

    #include "MMIDataType.h"
    #include "GlobalConstants.h"
    #include "kal_general_types.h"
    #include "FileMgrSrvGProt.h"
    #include "gui_data_types.h"
    #include "MediaPlayerPlayList.h"
    #include "fs_type.h"


#define MMI_KURO_DEFAULT_PRESET_FOLDER    L"KuroSong"
#define MMI_KURO_DEFAULT_DOWNLOAD_FOLDER  L"KuroSong\\airload"
#define KURO_WAP_URL          			  L"http://wap.kuro.cn"
#define MMI_KURO_DEFAULT_KUR_EXT          L".kur"
#define MMI_KURO_DEFAULT_KLR_EXT          L".klr"

#define MMI_KURO_IMEI_BUF_SIZE            10
#define MMI_KURO_MAX_URL_LENGTH           255
#define KURO_MAX_PROFILE_APN_LEN          99 

/*Kuro online list type */
typedef enum
{
    MEDPLY_KURO_LIST_TYPE_NONE,
    MEDPLY_KURO_LIST_TYPE_NEWEST_SONG,
    MEDPLY_KURO_LIST_TYPE_HOT_SONG,
    MEDPLY_KURO_LIST_TYPE_POPULAR_ARTIST,
    MEDPLY_KURO_LIST_TYPE_RECOMMEND_ALBUM,
    MEDPLY_KURO_LIST_TYPE_SONG_OF_POPUARTIST,
    MEDPLY_KURO_LIST_TYPE_SONG_OF_RECOMALBUM,
    MEDPLY_KURO_LIST_TYPE_TOTAL
}mmi_medply_kuro_online_song_type_enum;

/* kuro local list type*/
typedef enum
{
    MEDPLY_KURO_LOCAL_ALL_SONGS,
    MEDPLY_KURO_LOCAL_PRESET_SONGS,
    MEDPLY_KURO_LOCAL_DOWNLOAD_SONGS,
    MEDPLY_KURO_LOCAL_PRESET_SONGS_LIST,
    MEDPLY_KURO_LOCAL_TYPE_TOTAL
}mmi_medply_kuro_local_song_type_enum;
/* download state enum */

typedef enum
{
    MEDPLY_KURO_DL_CONNECTING,/* mapping with kuro enum */
    MEDPLY_KURO_DL_WAITING,    
    MEDPLY_KURO_DL_PROCESSING,
    MEDPLY_KURO_DL_COMPLETED,
    MEDPLY_KURO_DL_FAILED,
    MEDPLY_KURO_DL_STOP,
    MEDPLY_KURO_DL_STATUS_TOTAL
}mmi_medply_kuro_download_status_enum;

/* air song type */
typedef enum
{
    MEDPLY_KURO_AIRSONG_NONE,
    MEDPLY_KURO_AIRSONG_TYPE_HOT_SONG,
    MEDPLY_KURO_AIRSONG_TYPE_ARTIST,
    MEDPLY_KURO_AIRSONG_TYPE_ALBUM,
    MEDPLY_KURO_AIRSONG_TYPE_TOTAL
}mmi_medply_kuro_airsong_type_enum;

/* entry download manager */
typedef  enum
{
    MEDPLY_KURO_ENTRY_DL_FROM_VIEW,
    MEDPLY_KURO_ENTRY_DL_FROM_DOWNLOAD
}mmi_medply_kuro_entry_dl_manage_type_enum;

/*local kuro song list option*/
typedef enum
{
    MEDPLY_KURO_LOCAL_LIST_OP_PLAY,
    MEDPLY_KURO_LOCAL_LIST_OP_ACTIVATE,
    MEDPLY_KURO_LOCAL_LIST_OP_ADD_TO_PLST,
    MEDPLY_KURO_LOCAL_LIST_OP_ADD_AND_PLAY,
    MEDPLY_KURO_LOCAL_LIST_OP_DELETE_FILE
}mmi_medply_kuro_local_list_options_type;

typedef struct
{
    S32 highlight;
    U32 item_count;
    U16 item_index;
    U16 sub_item_index;
    U16 cur_grp_id;
    U16 cur_scr_id;
    U16 title[MAX_SUBMENU_CHARACTERS];
    mmi_medply_kuro_online_song_type_enum  type;
    U8  status;
    MMI_BOOL is_downloadXML;
    MMI_BOOL is_downloadsong;
    MMI_BOOL waiting_flag;
}mmi_medply_kuro_online_cntx_struct;

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
} mmi_medply_kuro_online_list_item_info_struct;

typedef struct
{
    U32 total;
    S32 highlight;
    U16 cache_start_index;
    U16 cache_end_index;
    mmi_medply_kuro_online_list_item_info_struct cache[MMI_MEDPLY_LIST_BUFF_SIZE];
} mmi_medply_kuro_online_list_struct;

typedef struct
{
    U32 Fee;
    MMI_BOOL isEnoughSpace;
    MMI_BOOL isExists;
    MMI_BOOL isInDownloadList;
} mmi_medply_kuro_online_song_info_struct;

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    U16 download_task_index;
    U16 download_percentage;     
    U8  download_stauts;
} mmi_medply_kuro_download_task_item_info_struct;

typedef struct
{
    U32  total;
    S32 highlight;
    U32 cache_start_index;
    U32 cache_end_index;
    MMI_BOOL update_flag;
    mmi_medply_kuro_download_task_item_info_struct cache[MMI_MEDPLY_LIST_BUFF_SIZE];
} mmi_medply_kuro_download_task_list_struct;

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    S32 index_in_list;
    U8 is_short;
    U8 is_activate; /* 2 unknown 1:unactive 0:activate */
    UI_character_type foldername[(SRV_FMGR_PATH_MAX_LEN+1)];
    MMI_BOOL in_subfolder; 
    MMI_BOOL is_used;
}mmi_medply_kuro_local_list_item_info_struct;

typedef struct
{
    UI_character_type filepath[(SRV_FMGR_PATH_MAX_LEN+1)];
    UI_character_type kur_name[(SRV_FMGR_PATH_MAX_LEN+1)];
    UI_character_type search_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    FS_DOSDirEntry file_info;
}mmi_medply_kuro_local_list_search_struct;

typedef struct
{
    U16 directory_idx;
    U16 total_file;
    //U16 start_idx;
    //U16 end_idx;
} mmi_medply_kuro_sub_dir_info_struct;

typedef struct
{
    MMI_BOOL prepare_done;
    U32 total;
    S32 highlight;

    U16 cache_start_index;
    U16 cache_end_index;
    S32 folder_exp[2];
    U16 head;
    U16 tail;

    U16 total_sub_directory;
    U16 total_file_in_root;     //list all file in root directory in the head of list!

    mmi_medply_kuro_local_list_item_info_struct cache[MMI_MEDPLY_LIST_BUFF_SIZE];
    mmi_medply_kuro_sub_dir_info_struct*    sub_directory_info_p;

    U32 index_pre;
    S32 create_folder_result;   
    U8  list_type;
    U8 option_type;  
    mmi_medply_kuro_local_list_search_struct* search_p;
}mmi_medply_kuro_local_list_struct;

typedef struct
{
    UI_character_type title[MAX_SUBMENU_CHARACTERS];
    UI_character_type path[MEDPLY_MAX_PATH_LEN]; 
    S32 hilight_pre;  
}mmi_medply_kuro_local_context_struct;

typedef void (*result_func_ptr)(S32 result);
typedef void (*action_func_ptr)(void);

#define MEDPLY_KURO_DIR_CACHE_PRESET_DIR           (0x12345678)
#define MEDPLY_KURO_DIR_CACHE_FILE_LIST            (0x98765432)

typedef enum
{
    MEDPLY_FS_SCAN_FILE_FIRST,
    MEDPLY_FS_SCAN_FILE_NEXT,
    MEDPLY_FS_SCAN_DIR_FIRST,
    MEDPLY_FS_SCAN_DIR_NEXT,
    MEDPLY_FS_SCAN_ENTER_DIR,
    MEDPLY_FS_SCAN_EXIT_DIR,
    MEDPLY_FS_SCAN_SUB_FIRST,
    MEDPLY_FS_SCAN_SUB_NEXT,
    MEDPLY_FS_SCAN_RESET,
    MEDPLY_FS_SCAN_PHASE_TOTAL
} mmi_medply_fs_scan_phase_enum;


typedef enum
{
    MEDPLY_FS_SCAN_MODE_ALL_SONGS,
    MEDPLY_FS_SCAN_MODE_PRESET_SONGS,
    MEDPLY_FS_SCAN_MODE_PRESET_SONGS_DIR,
    MEDPLY_FS_SCAN_MODE_DOWNLOAD_SONGS,
    MEDPLY_FS_SCAN_MODE_END
} mmi_medply_fs_scan_flag_enum;

typedef struct
{
    FS_HANDLE find_hdlr;
    U32 time_slice;
    
    U8  run_flag;
    U8  run_limit;
    U16 phase;

    U32 internal_fs_idx;

    U16 file_count;
    U16 sub_dir_count;

    mmi_medply_kuro_local_list_struct* list_cntx_p;
    action_func_ptr	action_func;
    result_func_ptr	result_func;
    UI_character_type path_cache[MEDPLY_MAX_PATH_LEN];
} mmi_medply_fs_scan_handle_struct;
#endif  /* #if defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_KURO__) */

#endif  /* __MEDIA_PLAYER_PLAY_LIST_KURO_H__ */
