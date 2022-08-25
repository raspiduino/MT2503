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
*  AudioPlayerPlayList.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player play list
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __AUDIO_PLAYER_PLAY_LIST_H__
#define __AUDIO_PLAYER_PLAY_LIST_H__
#include "MMI_features.h"

#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"

#include "fs_type.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
/*
 * Need to include:
 * (1) MMIDataType.h
 */

#define MMI_AUDPLY_PLAYLIST_ERR_BEGIN       (-10500)


#ifdef __MMI_AUDIO_PLAYER__
#ifndef __MMI_ULTRA_SLIM_AUDIO_PLAYER__

#ifdef __MMI_SLIM_AUDIO_PLAYER__
#define MMI_AUDPLY_LIST_BUFF_SIZE   8
#else 
#define MMI_AUDPLY_LIST_BUFF_SIZE   16
#endif

#define MMI_AUDPLY_LIST_RECORD_SIZE (((SRV_FMGR_PATH_MAX_LEN+1)+1)*ENCODING_LENGTH)

#define ClrBitSet( index, bitset )     ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet( index, bitset )     ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn( index, bitset )    ((bitset)[(index)>>3] & (1<<((index)&0x07)))

#define MARK_DRIVE(path) ((path)[0] = (UI_character_type)g_audply.present_list)
#define MARK_DRIVE_PS8(path) ((path)[0] = (CHAR)g_audply.present_list, (path)[1] = 0)
#define MARK_LNAME(path) ((path)[0] = L'L')
#define MARK_SNAME(path) ((path)[0] = L'S')
#define MARK_LNAME2(path) ((path)[0] = 'L',(path)[1] = 0)
#define MARK_SNAME2(path) ((path)[0] = 'S',(path)[1] = 0)
#define IS_LNAME(path) ((path)[0] == L'L')
#define IS_SNAME(path) ((path)[0] == L'S')
#define IS_LNAME2(path) ((path)[0] == 'L' && (path)[1] == 0)
#define IS_SNAME2(path) ((path)[0] == 'S' && (path)[1] == 0)
#define EOS(nob) ((nob)>1 ? ((nob)>>1)-1: 0)

#define MMI_AUDPLY_MAX_PICK_PER_SLICE           (20)
#define MMI_AUDPLY_MAX_EDITOR_LEN               (260)
#define MMI_AUDPLY_MAX_DEPTH_DIRECTORY          (16)
#define MMI_AUDPLY_BLOCK_DATA_SIZE              (128)
#define MMI_AUDPLY_MAX_PLAYLIST_ITEM            (1024)
#define MMI_AUDPLY_MAX_BITSET_SIZE              (MMI_AUDPLY_MAX_PLAYLIST_ITEM / 8)
/* playlist module error code. */
#define MMI_AUDPLY_PLAYLIST_NO_ERROR                (0)
#define MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED        (-10501)
#define MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED         (-10502)
#define MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST            (-10503)    /* it is not playlist file. */
#define MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME    (-10504)
#define MMI_AUDPLY_PLAYLIST_ERR_EMPTY_FILENAME      (-10505)
#define MMI_AUDPLY_PLAYLIST_ERR_FILE_EXISTS         (-10506)
#define MMI_AUDPLY_PLAYLIST_ERR_WRONG_VER           (-10507)    /* wrong version number. */
#define MMI_AUDPLY_PLAYLIST_ERR_LIST_FULL           (-10508)
#define MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED        (-10509)

#define MMI_AUDPLY_PLAYLIST_ERR_CREATE_FAILED       (-10510)
#define MMI_AUDPLY_PLAYLIST_ERR_OPEN_FAILED         (-10511)
#define MMI_AUDPLY_PLAYLIST_ERR_INVALID_PARA        (-10512)

#define MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE            (-10513)
#define MMI_AUDPLY_PLAYLIST_ERR_EXIST_FILE          (-10514)

#define MMI_AUDPLY_PLAYLIST_ERR_NO_MEM              (-10515)
#define MMI_AUDPLY_PLAYLIST_ERR_META                    (-10516)

#define MMI_AUDPLY_DEFAULT_FOLDER                   L"@Playlists"

#define MMI_AUDPLY_MULTIPLE_LIST_EXT            L".mal" //mal
#define MMI_AUDPLY_DEFAULT_LIST_NAME            L"audio_play_list.sal"

#define MUSIC_FOLDER L"My Music\\"
#define MMI_AUDPLY_DEFAULT_PATH    L"@Playlists\\audio_play_list.sal"

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
#define MMI_AUDPLY_OP_LINK1     L"http://musicstore.mob2.orange.fr"
#endif

typedef enum
{
    MMI_AUDPLY_DRV_PHONE = 0,
#if defined(__FS_CARD_SUPPORT__)        
    MMI_AUDPLY_DRV_CARD,
#endif
#if defined(__OTG_ENABLE__)
    MMI_AUDPLY_DRV_REMOVABLE_OTG1,
    MMI_AUDPLY_DRV_REMOVABLE_OTG2,
    MMI_AUDPLY_DRV_REMOVABLE_OTG3,
    MMI_AUDPLY_DRV_REMOVABLE_OTG4,
    MMI_AUDPLY_DRV_REMOVABLE_OTG5,
    MMI_AUDPLY_DRV_REMOVABLE_OTG6,
    MMI_AUDPLY_DRV_REMOVABLE_OTG7,
    MMI_AUDPLY_DRV_REMOVABLE_OTG8,
#endif
#if defined(__SIM_PLUS__)
    MMI_AUDPLY_DRV_REMOVABLE_SIM1,
    MMI_AUDPLY_DRV_REMOVABLE_SIM2,
    MMI_AUDPLY_DRV_REMOVABLE_SIM3,
    MMI_AUDPLY_DRV_REMOVABLE_SIM4,
#endif    
#if defined(__MSDC2_SD_MMC__)
    MMI_AUDPLY_DRV_MSDC2_SD_STORAGE,
#endif /* __MSDC2_SD_MMC__ */
    MMI_AUDPLY_DRV_TOTAL
} mmi_audply_drv_support_list_struct;

typedef enum
{
    MMI_AUDPLY_EDITOR_NEW,      /* create playlist. */
    MMI_AUDPLY_EDITOR_RENAME,   /* rename playlist. */
    MMI_AUDPLY_EDITOR_EDIT_URL, /* enter URL. */
    MMI_AUDPLY_EDITOR_TYPE_TOTAL
} mmi_audply_editor_type_enum;

typedef enum
{
    MMI_AUDPLY_LIST_PHASE_INIT,
    MMI_AUDPLY_LIST_PHASE_SET_DRV,
    MMI_AUDPLY_LIST_PHASE_SEARCH_FIRST,
    MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT,
    MMI_AUDPLY_LIST_PHASE_SEARCH_FOLDER,
    MMI_AUDPLY_LIST_PHASE_FORWARDS,
    MMI_AUDPLY_LIST_PHASE_BACKWARDS,
    MMI_AUDPLY_LIST_PHASE_FINISH,
    MMI_AUDPLY_LIST_PHASE_ERR_HDLR,
    MMI_AUDPLY_LIST_PHASE_SEARCH_ODF,
    MMI_AUDPLY_LIST_PHASE_BACKWARDS_ODF,
    MMI_AUDPLY_LIST_PHASE_CANCEL,
    MMI_AUDPLY_LIST_PHASE_END
} mmi_audply_generate_phase_enum;


typedef enum
{
    MMI_AUDPLY_PLAYLIST_PLST = 1,
    MMI_AUDPLY_PLAYLIST_TOTAL
} mmi_audply_playlist_type_enum;

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];   
    U8 file_type;
    U8 is_short;
} mmi_audply_list_item_info_struct;

typedef struct
{
    S32 total;
    S32 highlight;
    U16 cache_start_index;
    U16 cache_end_index;
    UI_character_type title[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_audply_list_item_info_struct cache[MMI_AUDPLY_LIST_BUFF_SIZE];
} mmi_audply_dynamic_list_data_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *context;
} mmi_audply_playlist_search_continue_req_struct;



#ifdef __MMI_AUDPLY_MULTIPLE_LIST__


typedef struct
{
    U32 pattern_begin;
    CHAR data[MMI_AUDPLY_BLOCK_DATA_SIZE];
    U32 next_ptr;
    U32 pattern_end;
} mmi_audply_playlist_block_node_struct;

typedef struct
{
    U32 offset;
    U16 index;
    U8  used_block;
    U8  is_active;  /* short name: is_active == 2, long name: is_active == 1. */
} mmi_audply_playlist_index_node_struct;

#define AUDPLY_PLAYLIST_TYPE_ID                 "ALST"
#define AUDPLY_PLAYLIST_VERSION                 "01"
#define AUDPLY_PLAYLIST_DATA_OFFSET             (sizeof(mmi_audply_playlist_header_struct))
#define AUDPLY_PLAYLIST_FOOTER_PATTERN          0xFEFEFEFE
#define AUDPLY_PLAYLIST_BLOCK_PATTERN_1         0x3F3F3F3F      
#define AUDPLY_PLAYLIST_BLOCK_PATTERN_2         0x4F4F4F4F

typedef struct
{
    CHAR type_id[4];
    CHAR version[2];
    U16 total_slot;
    U32 footer_pattern_offset;
    mmi_audply_playlist_index_node_struct empty_node;
    mmi_audply_playlist_index_node_struct index[MMI_AUDPLY_MAX_PLAYLIST_ITEM];
    U32 pattern;
} mmi_audply_playlist_header_struct;


typedef struct
{
    U32 footer_pattern;
    CHAR type_id[4];
} mmi_audply_playlist_footer_struct;

#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */


/*
**  stack node structure
*/
typedef struct
{
    U16 level;   /* stack level. */
    U16 total_sub_folder;    /* total sub-folder number in this level. */
    U16 index;               /* current index in all sub-folder. */
    U16 fs_index;            /* fs index for FS_FindFirst(). */
} mmi_audply_playlist_stack_node_struct;

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
    FS_HANDLE list_file_handle;
    
    U16 phase;
    U16 stack_index;     /* folder level & stack level. */
    
    UI_character_type path_cache[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    mmi_audply_playlist_stack_node_struct stack[MMI_AUDPLY_MAX_DEPTH_DIRECTORY];
#ifdef __DRM_V02__
    void* DRM_find_cntx;
#endif
} mmi_audply_playlist_generate_struct;



typedef struct
{
    S32 pick_index;
    S32 pick_count;
    S32 total;
    
    U8 bitset[MMI_AUDPLY_MAX_BITSET_SIZE];
    FS_HANDLE fs_hdlr;
    
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
#ifdef __MMI_AUDPLY_MULTIPLE_LIST__
    UI_character_type title[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_audply_playlist_header_struct header;
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */
} mmi_audply_playlist_struct;

typedef struct
{
    U8 is_active;
    CHAR drv_letter;
} mmi_audply_drv_list_struct;


typedef struct
{
    MMI_BOOL list_loaded;
    mmi_audply_drv_list_struct drv[MMI_AUDPLY_DRV_TOTAL];
    U8 drv_num;
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)    
    U8 editor_type;
    UI_character_type editor_buffer[MMI_AUDPLY_MAX_EDITOR_LEN + 1];
    mmi_audply_playlist_struct browser_list;
#endif
    mmi_audply_playlist_struct current_list;
    mmi_audply_dynamic_list_data_struct list_ui;
    mmi_audply_playlist_generate_struct generate_info;
} mmi_audply_playlist_cntx_struct;

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
typedef struct
{
    U32 file_offset;        //cache file offset , always sync with update_cntx.offset
    U32 cache_offset;       //cache current offset which always point to the begin of one file path
    U32 cache_size;         //cached size (read file size)
    U32 cache_limit;        //cache buffer size
    CHAR* cache_buffer_ptr;   //cache buffer
} audply_auto_update_cache_struct;

typedef struct
{
    UI_character_type old_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    UI_character_type new_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    FS_HANDLE present_list; //present list fs handle
    FS_HANDLE temp_file;    //only used in update delete action
    U32 counter;
    U32 deleted;
    U32 offset;             //cache file offset
    U32 old_path_len;
    U8 action_type;
    MMI_BOOL is_folder;
} audply_auto_update_struct;
#endif /* defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */


/* extern API. */
extern void mmi_audply_check_whether_build_cache(
                MMI_BOOL *need_to_build_cache, MMI_BOOL *seekable, const UI_string_type ext);
extern S32 mmi_audply_lookup_audio_file_format(const UI_string_type ext);
#if defined(MT6223) || defined(MT6223P)
extern MMI_BOOL mmi_audply_check_support_A2DP_or_not(const UI_string_type ext);
#endif
extern void mmi_audply_extract_ext(const UI_string_type filename, UI_string_type ext);
extern void mmi_audply_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext);
extern void mmi_audply_extract_filename(UI_string_type filename, const UI_string_type path);
extern MMI_BOOL mmi_audply_does_file_exist(const UI_string_type path);
extern MMI_BOOL mmi_audply_is_any_file_selected(void);
extern MMI_BOOL mmi_audply_is_audio_path(const UI_string_type path);
extern U8 mmi_audply_get_current_list_drv(void);

extern void mmi_audply_playlist_reset_ui_cntx(void);
extern U8 mmi_audply_util_count_optional_drv(void);
extern U8 mmi_audply_playlist_get_path(UI_string_type fullfilename, S32 index);
extern U8 mmi_audply_playlist_get_path_for_player(UI_string_type fullfilename, S32 index);
extern S32 mmi_audply_playlist_do_pick(void);
extern S32 mmi_audply_playlist_pick_next(void);
extern S32 mmi_audply_playlist_pick_prev(void);
extern MMI_BOOL mmi_audply_playlist_get_filename(UI_string_type filename, S32 index);
extern S32 mmi_audply_playlist_get_total(void);
extern S32 mmi_audply_playlist_get_total(void);

extern void mmi_audply_playlist_set_pick_index(S32 index);
extern void mmi_audply_playlist_set_start(S32 index);
extern MMI_BOOL mmi_audply_playlist_is_valid(void);
extern MMI_BOOL mmi_audply_playlist_is_empty(void);

extern void mmi_audply_playlist_entry_playlist(void);
extern void mmi_audply_playlist_display_popup(S32 error_code, FuncPtr callback);
extern S32 mmi_audply_playlist_get_current_index(void);
extern S32 mmi_audply_playlist_get_current_highlight(void);

extern MMI_BOOL mmi_audply_playlist_apply_picked_file(void);

extern void mmi_audply_playlist_module_init(void);
extern void mmi_audply_playlist_init(void);
extern void mmi_audply_playlist_ui_highlight_hdlr(S32 index);
extern pBOOL mmi_audply_playlist_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern mmi_ret mmi_audply_plst_notify_hdlr(mmi_event_struct *event);

#ifdef __MMI_AUDIO_PLAYER_SINGLE_LIST__
extern void mmi_audply_playlist_check_status(void);
extern void mmi_audply_single_highlight_hdlr_init(void);
extern void mmi_audply_highlight_option_play(void);
extern void mmi_audply_highlight_option_details(void);
extern void mmi_audply_highlight_option_add(void);
extern void mmi_audply_highlight_option_remove(void);
extern void mmi_audply_highlight_option_removeall(void);
extern void mmi_audply_highlight_option_refresh(void);
extern void mmi_audply_highlight_option_add_to_ring(void);
extern void mmi_audply_highlight_option_settings(void);
extern void mmi_audply_need_generate_playlist(void);
extern void mmi_audply_need_load_playlist(void);
extern void mmi_audply_playlist_set_default_playlist_path(void);
extern S32 mmi_audply_playlist_check_and_set_default_playlist_path(UI_string_type file_path,  CHAR driver_letter);
#endif

#ifdef __MMI_AUDPLY_MULTIPLE_LIST__
extern void mmi_audply_multiple_highlight_hdlr_init(void);
extern void mmi_audply_highlight_option_play(void);
extern void mmi_audply_highlight_option_details(void);
extern void mmi_audply_highlight_option_add(void);
extern void mmi_audply_highlight_option_remove(void);
extern void mmi_audply_highlight_option_moveup(void);
extern void mmi_audply_highlight_option_movedown(void);
extern void mmi_audply_highlight_option_forward_use(void);
extern void mmi_audply_highlight_option_forward_send(void);
extern void mmi_audply_highlight_option_settings(void);

extern void mmi_audply_highlight_listmgr_option_new(void);
extern void mmi_audply_highlight_listmgr_option_load(void);
extern void mmi_audply_highlight_listmgr_option_delete(void);
extern void mmi_audply_highlight_listmgr_option_rename(void);

extern void mmi_audply_playlist_entry_listmgr(void);
extern void mmi_audply_playlist_load_last_list(void);
#endif

extern void mmi_audply_playlist_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list);
extern void mmi_audply_playlist_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list);
extern void mmi_audply_playlist_usb_plug_out_hdlr(void);
extern void mmi_audply_playlist_usb_plug_in_hdlr(void);
extern void mmi_audply_playlist_post_format_hdlr(CHAR drv);



#else /* __MMI_ULTRA_SLIM_AUDIO_PLAYER__ */


#define NEW_CODE_TMP_OPT

#ifdef __MMI_SLIM_AUDIO_PLAYER__
#define MMI_AUDPLY_LIST_BUFF_SIZE   8
#else 
#define MMI_AUDPLY_LIST_BUFF_SIZE   16
#endif

#define MMI_AUDPLY_LIST_RECORD_SIZE (((SRV_FMGR_PATH_MAX_LEN+1)+1)*ENCODING_LENGTH)

#define ClrBitSet( index, bitset )     ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet( index, bitset )     ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn( index, bitset )    ((bitset)[(index)>>3] & (1<<((index)&0x07)))

#define MARK_DRIVE(path) ((path)[0] = (UI_character_type)g_audply.present_list)
#define MARK_DRIVE_PS8(path) ((path)[0] = (CHAR)g_audply.present_list, (path)[1] = 0)
#define MARK_LNAME(path) ((path)[0] = L'L')
#define MARK_SNAME(path) ((path)[0] = L'S')
#define MARK_LNAME2(path) ((path)[0] = 'L',(path)[1] = 0)
#define MARK_SNAME2(path) ((path)[0] = 'S',(path)[1] = 0)
#define IS_LNAME(path) ((path)[0] == L'L')
#define IS_SNAME(path) ((path)[0] == L'S')
#define IS_LNAME2(path) ((path)[0] == 'L' && (path)[1] == 0)
#define IS_SNAME2(path) ((path)[0] == 'S' && (path)[1] == 0)
#define EOS(nob) ((nob)>1 ? ((nob)>>1)-1: 0)

//#define MMI_AUDPLY_MAX_PICK_PER_SLICE           (20)
//#define MMI_AUDPLY_MAX_EDITOR_LEN               (260)
//#define MMI_AUDPLY_MAX_DEPTH_DIRECTORY          (16)
//#define MMI_AUDPLY_BLOCK_DATA_SIZE              (128)
#define MMI_AUDPLY_MAX_PLAYLIST_ITEM            (1024)
#define MMI_AUDPLY_MAX_BITSET_SIZE              (MMI_AUDPLY_MAX_PLAYLIST_ITEM / 8)
/* playlist module error code. */
//#define MMI_AUDPLY_PLAYLIST_NO_ERROR                (0)
//#define MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED        (-10501)
//#define MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED         (-10502)
//#define MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST            (-10503)    /* it is not playlist file. */
//#define MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME    (-10504)
//#define MMI_AUDPLY_PLAYLIST_ERR_EMPTY_FILENAME      (-10505)
//#define MMI_AUDPLY_PLAYLIST_ERR_FILE_EXISTS         (-10506)
//#define MMI_AUDPLY_PLAYLIST_ERR_WRONG_VER           (-10507)    /* wrong version number. */
//#define MMI_AUDPLY_PLAYLIST_ERR_LIST_FULL           (-10508)
//#define MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED        (-10509)

//#define MMI_AUDPLY_PLAYLIST_ERR_CREATE_FAILED       (-10510)
//#define MMI_AUDPLY_PLAYLIST_ERR_OPEN_FAILED         (-10511)
//#define MMI_AUDPLY_PLAYLIST_ERR_INVALID_PARA        (-10512)

#define MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE            (-10513)
//#define MMI_AUDPLY_PLAYLIST_ERR_EXIST_FILE          (-10514)

#define MMI_AUDPLY_PLAYLIST_ERR_NO_MEM              (-10515)
#define MMI_AUDPLY_PLAYLIST_ERR_META                    (-10516)

#define MMI_AUDPLY_DEFAULT_FOLDER                   L"@Playlists"

//#define MMI_AUDPLY_MULTIPLE_LIST_EXT            L".mal" //mal
#define MMI_AUDPLY_DEFAULT_LIST_NAME            L"audio_play_list_slim.sal"

#define MUSIC_FOLDER L"My Music\\"
#define MMI_AUDPLY_DEFAULT_PATH    L"@Playlists\\audio_play_list_slim.sal"

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
#define MMI_AUDPLY_OP_LINK1     L"http://musicstore.mob2.orange.fr"
#endif

typedef enum
{
    MMI_AUDPLY_DRV_PHONE = 0,
#if defined(__FS_CARD_SUPPORT__)        
    MMI_AUDPLY_DRV_CARD,
#endif
#if defined(__OTG_ENABLE__)
    MMI_AUDPLY_DRV_REMOVABLE_OTG1,
    MMI_AUDPLY_DRV_REMOVABLE_OTG2,
    MMI_AUDPLY_DRV_REMOVABLE_OTG3,
    MMI_AUDPLY_DRV_REMOVABLE_OTG4,
    MMI_AUDPLY_DRV_REMOVABLE_OTG5,
    MMI_AUDPLY_DRV_REMOVABLE_OTG6,
    MMI_AUDPLY_DRV_REMOVABLE_OTG7,
    MMI_AUDPLY_DRV_REMOVABLE_OTG8,
#endif
#if defined(__SIM_PLUS__)
    MMI_AUDPLY_DRV_REMOVABLE_SIM1,
    MMI_AUDPLY_DRV_REMOVABLE_SIM2,
    MMI_AUDPLY_DRV_REMOVABLE_SIM3,
    MMI_AUDPLY_DRV_REMOVABLE_SIM4,
#endif    
#if defined(__MSDC2_SD_MMC__)
    MMI_AUDPLY_DRV_MSDC2_SD_STORAGE,
#endif /* __MSDC2_SD_MMC__ */
    MMI_AUDPLY_DRV_TOTAL
} mmi_audply_drv_support_list_struct;

/*
typedef enum
{
    MMI_AUDPLY_PLAYLIST_PLST = 1,
    MMI_AUDPLY_PLAYLIST_TOTAL
} mmi_audply_playlist_type_enum;
*/

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];   
    U8 file_type;
    U8 is_short;
} mmi_audply_list_item_info_struct;

typedef struct
{
    S32 total;
    S32 highlight;
    U16 cache_start_index;
    U16 cache_end_index;
    UI_character_type title[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_audply_list_item_info_struct cache[MMI_AUDPLY_LIST_BUFF_SIZE];
} mmi_audply_dynamic_list_data_struct;



/*
**  Structure for getting all media files under a folder.1092
*/
typedef struct
{
    UI_character_type path_cache[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
} mmi_audply_playlist_generate_struct;



typedef struct
{
    S32 pick_index;
    S32 pick_count;
    S32 total;
    
    U8 bitset[MMI_AUDPLY_MAX_BITSET_SIZE];
    FS_HANDLE fs_hdlr;
    
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

} mmi_audply_playlist_struct;

typedef struct
{
    U8 is_active;
    CHAR drv_letter;
} mmi_audply_drv_list_struct;


typedef struct
{
    MMI_BOOL list_loaded;
    mmi_audply_drv_list_struct drv[MMI_AUDPLY_DRV_TOTAL];
    U8 drv_num;
    mmi_audply_playlist_struct current_list;
    mmi_audply_dynamic_list_data_struct list_ui;
    mmi_audply_playlist_generate_struct generate_info;
} mmi_audply_playlist_cntx_struct;

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
typedef struct
{
    U32 file_offset;        //cache file offset , always sync with update_cntx.offset
    U32 cache_offset;       //cache current offset which always point to the begin of one file path
    U32 cache_size;         //cached size (read file size)
    U32 cache_limit;        //cache buffer size
    CHAR* cache_buffer_ptr;   //cache buffer
} audply_auto_update_cache_struct;

typedef struct
{
    UI_character_type old_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    UI_character_type new_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    FS_HANDLE present_list; //present list fs handle
    FS_HANDLE temp_file;    //only used in update delete action
    U32 counter;
    U32 deleted;
    U32 offset;             //cache file offset
    U32 old_path_len;
    U8 action_type;
    MMI_BOOL is_folder;
} audply_auto_update_struct;
#endif /* defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */


/* extern API. */
extern void mmi_audply_check_whether_build_cache(
                MMI_BOOL *need_to_build_cache, MMI_BOOL *seekable, const UI_string_type ext);
extern S32 mmi_audply_lookup_audio_file_format(const UI_string_type ext);
#if defined(MT6223) || defined(MT6223P)
extern MMI_BOOL mmi_audply_check_support_A2DP_or_not(const UI_string_type ext);
#endif
extern void mmi_audply_extract_ext(const UI_string_type filename, UI_string_type ext);
extern void mmi_audply_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext);
extern void mmi_audply_extract_filename(UI_string_type filename, const UI_string_type path);
extern MMI_BOOL mmi_audply_does_file_exist(const UI_string_type path);
extern MMI_BOOL mmi_audply_is_any_file_selected(void);
extern MMI_BOOL mmi_audply_is_audio_path(const UI_string_type path);
extern U8 mmi_audply_get_current_list_drv(void);

extern void mmi_audply_playlist_reset_ui_cntx(void);
extern U8 mmi_audply_util_count_optional_drv(void);
extern U8 mmi_audply_playlist_get_path(UI_string_type fullfilename, S32 index);
extern U8 mmi_audply_playlist_get_path_for_player(UI_string_type fullfilename, S32 index);
extern S32 mmi_audply_playlist_do_pick(void);
extern S32 mmi_audply_playlist_pick_next(void);
extern S32 mmi_audply_playlist_pick_prev(void);
extern MMI_BOOL mmi_audply_playlist_get_filename(UI_string_type filename, S32 index);
extern S32 mmi_audply_playlist_get_total(void);
extern S32 mmi_audply_playlist_get_total(void);

extern void mmi_audply_playlist_set_pick_index(S32 index);
extern void mmi_audply_playlist_set_start(S32 index);
extern MMI_BOOL mmi_audply_playlist_is_valid(void);
extern MMI_BOOL mmi_audply_playlist_is_empty(void);

extern void mmi_audply_playlist_entry_playlist(void);
extern void mmi_audply_playlist_display_popup(S32 error_code, FuncPtr callback);
extern S32 mmi_audply_playlist_get_current_index(void);
extern S32 mmi_audply_playlist_get_current_highlight(void);

extern MMI_BOOL mmi_audply_playlist_apply_picked_file(void);

extern void mmi_audply_playlist_module_init(void);
extern void mmi_audply_playlist_init(void);
extern void mmi_audply_playlist_ui_highlight_hdlr(S32 index);
extern pBOOL mmi_audply_playlist_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern mmi_ret mmi_audply_plst_notify_hdlr(mmi_event_struct *event);

#ifdef __MMI_AUDIO_PLAYER_SINGLE_LIST__
extern void mmi_audply_playlist_check_status(void);
extern void mmi_audply_single_highlight_hdlr_init(void);
extern void mmi_audply_need_generate_playlist(void);
extern void mmi_audply_need_load_playlist(void);
extern void mmi_audply_playlist_set_default_playlist_path(void);
extern S32 mmi_audply_playlist_check_and_set_default_playlist_path(UI_string_type file_path,  CHAR driver_letter);
#endif


extern void mmi_audply_playlist_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list);
extern void mmi_audply_playlist_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list);
extern void mmi_audply_playlist_usb_plug_out_hdlr(void);
extern void mmi_audply_playlist_usb_plug_in_hdlr(void);
extern void mmi_audply_playlist_post_format_hdlr(CHAR drv);


#define MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT 1000
#define MMI_AUDPLY_MAX_FOLDER_LEVEL 16

#define MMI_AUDPLY_PATH_LEN MMI_AUDPLY_LIST_RECORD_SIZE

typedef enum
{
	MMI_AUDPLY_ACTION_REFRESH,
	MMI_AUDVDOPLY_ACTION_ADD,
	MMI_AUDPLY_ACTION_END
}mmi_audply_playlist_action_enum;


typedef enum
{
    MMI_AUDPLY_PLAYLIST_RESULT_NO_ERROR,
    MMI_AUDPLY_PLAYLIST_RESULT_NO_FILE,
    MMI_AUDPLY_PLAYLIST_RESULT_DIR,
    MMI_AUDPLY_PLAYLIST_RESULT_INVALID_FILE,
    MMI_AUDPLY_PLAYLIST_RESULT_END
} mmi_audply_playlist_result_enum;


typedef struct
{
    U8 curr_level;
    U8 state;
    U16 total_no_of_audios;
    U16 curr_index[MMI_AUDPLY_MAX_FOLDER_LEVEL];
    U16 recent_folder[MMI_AUDPLY_PATH_LEN];
    U16 absolute_count;
    PU8 header;
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;

} mmi_audply_playlist_mgr_struct;

#endif /* __MMI_ULTRA_SLIM_AUDIO_PLAYER__ */
#endif /* __MMI_AUDIO_PLAYER__ */ 


#endif /* __AUDIO_PLAYER_PLAY_LIST_H__ */ 

