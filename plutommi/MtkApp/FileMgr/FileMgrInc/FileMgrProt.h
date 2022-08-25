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
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _FMGR_PROT_H_
#define _FMGR_PROT_H_

#if defined(__MMI_FILE_MANAGER__)


#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

#ifndef _FMGR_GPROT_H_
#error "include FileMgrGProt.h first"
#endif

/***************************************************************************/

#if defined(__OP12__) && defined(__FS_CARD_SUPPORT__) && !defined(__MMI_SLIM_FILE_MANAGER__)
#define FMGR_TAB_SUPPORT
#endif

#define FMGR_BROWSE_SUPPORT_FOLDER_CHANGE

#if defined(__FS_SORT_SUPPORT__)
#define _MMI_FMGR_ASYNC_SORT_SUPPORT_
#undef __MMI_FMGR_SUPPORT_SORT_PARTIAL_DISPLAY__
#endif

#if defined(__MMI_MY_FAVORITE_HYPERLINK_SUPPORT__) || defined(__MMI_JAVA_FMGR_HYPERLINK__)
#define __FMGR_HYPERLINK_SUPPORT__
#endif

#if defined(__MMI_MY_FAVORITE__)
/* under construction !*/
#endif

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__ 
#define __FMGR_FTE_TOOLBAR_SUPPORT__
#endif
#define __FMGR_FTE_MENU_INTERACT_SUPPORT__
#endif

#ifndef __FMGR_KEY_RULE__
#define __FMGR_KEY_RULE__
#endif

/* following compile option are temporary and should be removed after MP */
#define __FMGR_USE_EDITOR_CUI__
#define __FMGR_USE_MENU_CUI__
//#define __FMGR_USE_SELF_MENU__

/****************************************************************************
* FMGR Internal testing option
*****************************************************************************/
#undef FMGR_INTERNAL_TEST

#ifdef FMGR_INTERNAL_TEST
    #ifndef __FMGR_HYPERLINK_SUPPORT__  /* turn on Hyperlink */
    #define __FMGR_HYPERLINK_SUPPORT__
    #endif

    #ifndef __MMI_FMGR_CUSTICON_SUPPORT__ /* turn on Icon support */
    #define __MMI_FMGR_CUSTICON_SUPPORT__
    #endif

    #define _MMI_FMGR_ENABLE_PERF_

    #ifndef __FMGR_CUSTOM_ROOT_SUPPORT__
    #define __FMGR_CUSTOM_ROOT_SUPPORT__
    #endif
#endif

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "FileMgrGProt.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_public_api.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "mmi_rp_file_type_def.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"

/****************************************************************************
* Define
*****************************************************************************/

/********************************* Setting **********************************/

/* Re-entry is supported now, here define the max re-entry value */
#ifdef __MMI_SLIM_FILE_MANAGER__
/* Currently SLIM project can create 3 instance in normal scenario */
/* #define MMI_FMGR_INSTANCE_MAX_NUM       (2)*/
#define MMI_FMGR_INSTANCE_MAX_NUM       (3)
#else
#define MMI_FMGR_INSTANCE_MAX_NUM       (3)
#endif

/* Sorting related */
#if defined(__FS_SORT_SUPPORT__)
#define FMGR_MAX_SORT                   (FS_SORT_MAX_ENTRY)
#define FMGR_SORT_WORKING_BUFFER_SIZE   FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(FMGR_MAX_SORT)
#define FMGR_SORT_SORTING_BUFFER_SIZE   FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(FMGR_MAX_SORT)
#else
#define FMGR_MAX_SORT                   (0)
#define FMGR_SORT_WORKING_BUFFER_SIZE   (4)
#define FMGR_SORT_SORTING_BUFFER_SIZE   (4)
#endif
#define FMGR_SORT_BUFFER_SIZE           (FMGR_SORT_WORKING_BUFFER_SIZE+FMGR_SORT_SORTING_BUFFER_SIZE)

#define FMGR_MAX_FILES_IN_FOLDER        65535

#if defined(__MMI_MAINLCD_128X128__)
    #define FMGR_MATRIX_COLUMN_NUM      (3)
    #define FMGR_MATRIX_ROW_NUM         (2)
#elif defined(__MMI_MAINLCD_240X400__)
    #define FMGR_MATRIX_COLUMN_NUM      (4)
    #define FMGR_MATRIX_ROW_NUM         (5)
#elif defined(__MMI_MAINLCD_320X480__)
    #define FMGR_MATRIX_COLUMN_NUM      (4)
    #define FMGR_MATRIX_ROW_NUM         (5)
#else
    #define FMGR_MATRIX_COLUMN_NUM      (3)
    #define FMGR_MATRIX_ROW_NUM         (3)
#endif

#ifdef FMGR_TAB_SUPPORT
#define FMGR_MAX_TAB_COUNT              2
#endif

/* The maximum length of a file's fullpath, including null character */
#define FMGR_MAX_PATH_LEN           (260)
/* The maximum length of a file's fullpath in bytes, including null character */
#define FMGR_PATH_BUFFER_SIZE       (520)

/********************************** Macro **********************************/

#ifndef __MTK_TARGET__
#define FMGR_TRACE0(tr, f)              mmi_fmgri_modis_showtrace(f)
#define FMGR_TRACE1(tr, f, a1)          mmi_fmgri_modis_showtrace(f, a1)
#define FMGR_TRACE2(tr, f, a1, a2)      mmi_fmgri_modis_showtrace(f, a1, a2)
#define FMGR_TRACE3(tr, f, a1, a2, a3)  mmi_fmgri_modis_showtrace(f, a1, a2, a3)
#else
#define FMGR_TRACE0(tr, f)              MMI_TRACE(MMI_COMMON_TRC_G1_FMGR, tr)
#define FMGR_TRACE1(tr, f, a1)          MMI_TRACE(MMI_COMMON_TRC_G1_FMGR, tr, a1)
#define FMGR_TRACE2(tr, f, a1, a2)      MMI_TRACE(MMI_COMMON_TRC_G1_FMGR, tr, a1, a2)
#define FMGR_TRACE3(tr, f, a1, a2, a3)  MMI_TRACE(MMI_COMMON_TRC_G1_FMGR, tr, a1, a2, a3)
#endif

#if defined(DEBUG_KAL)
#define FMGR_ASSERT(expr)  {if(!(expr)) { ASSERT(0); } else {}}
#else
#define FMGR_ASSERT(expr)  ASSERT(expr)
#endif

#define FMGR_DisplayPopup(str_id, popup_type)            mmi_fmgri_displaypopup(str_id, popup_type, __LINE__, NULL)
#define FMGR2_DisplayPopup(i, str_id, popup_type)        mmi_fmgri_instance_display_popup(i, str_id, popup_type, (U16)0, MMI_FALSE, __LINE__)
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
#define FMGR2_DisplayPopupStr(i, str_buf, popup_type)    mmi_fmgri_instance_display_popup_str(i, (S8*)str_buf, popup_type, __LINE__)
#endif
#define FMGR2_DisplayPopupCB(i, str_id, popup_type)      mmi_fmgri_instance_display_popup(i, str_id, popup_type, (U16)0, MMI_TRUE, __LINE__)
#define FMGR3_DisplayPopup(id, str_id, popup_type)       mmi_fmgri_instance_display_popup(0, str_id, popup_type, (U16)id, MMI_FALSE, __LINE__)

#define FMGR_FLAG_IS_SET(b, a)       ((b & (0x1 << a)) >> a)
#define FMGR_SET_FLAG(b, a)          (b |= (0x1 << a))
#define FMGR_UNSET_FLAG(b, a)        (b &= ~(0x1 << a))
#define FMGR_TOGGLE_FLAG(b, a)       (b ^= (0x1 << a))

#define FMGR_PATH_ROOT                  L"root"

/********************************** Enum  **********************************/

typedef enum
{
    MMI_FMGR_TYPE_NONE = 0,
    MMI_FMGR_TYPE_APP,
#ifdef __FMGR_STORAGE_SELECTOR_CUI__
    MMI_FMGR2_TYPE_STORAGE_SELECTOR,
#endif
    MMI_FMGR2_TYPE_FILE_SELECTOR,
    MMI_FMGR2_TYPE_FOLDER_SELECTOR,
    MMI_FMGR2_TYPE_FOLDER_BROWSER,
#ifdef __FMGR_FILE_OPTION_CUI__
    MMI_FMGR2_TYPE_FILE_OPTION,
#endif
#ifdef __DRM_V02__
    MMI_FMGR_TYPE_VIEW_ARCHIVE,
#endif
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
    MMI_FMGR_TYPE_SEL_FILE_MUlTI,
#endif

    MMI_FMGR_TYPE_NUM

} mmi_fmgri_type_enum;

/* internal flag occupy top 8 bit */
typedef enum
{  
    FMGR_IFLAG_HIDE_LOADING_PATH            = 0x01000000,
        
#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    FMGR_IFLAG_CUSTOM_ROOT                  = 0x02000000,
#endif

    FMGR_IFLAG_WAIT_POPUP                   = 0x04000000,

    FMGR_IFLAG_INTERNAL                     = 0x08000000,   /* without notify creation */

    FMGR_IFLAG_DEAD                         = 0x10000000,
    
    FMGR_IFLAG_ENUM = 0x7F000000
} fmgr_flag_internal_enum;

typedef enum
{
    MMI_FMGR_OPTION_TYPE_NORMAL = 0,
    MMI_FMGR_OPTION_TYPE_RADIO,
    MMI_FMGR_OPTION_TYPE_SUB_LEVEL,
    MMI_FMGR_OPTION_TYPE_FULL_SCREEN,

    MMI_FMGR_OPTION_TYPE_NUM

} mmi_fmgri_option_type_enum;

typedef enum
{
    FMGR_ACTION_FORMAT = FMGR_ACTION_END,
    FMGR_ACTION_CHECK_DRIVE,
    FMGR_ACTION_UNMOUNT,
    FMGR_ACTION_MARK_COPY,
    FMGR_ACTION_MARK_MOVE,
    FMGR_ACTION_MARK_DELETE,    
    FMGR_ACTION_MARK_PRINT,    
    FMGR_ACTION_UNMARK_ALL,        
    
    FMGR_ACTION_RENAME_DRIVE,
    FMGR_ACTION_CARD_DETAIL,
    

    FMGR_ACTION_CREATE_FOLDER,
    FMGR_ACTION_RENAME_FILE,
    FMGR_ACTION_RENAME_FOLDER,
    FMGR_ACTION_DELETE_SINGLE,
    FMGR_ACTION_DELETE_FOLDER,
    FMGR_ACTION_DELETE_ALL,
    FMGR_ACTION_DELETE_BY_FILTER,
    
    FMGR_ACTION_FWD_WALLPAPER,
    FMGR_ACTION_FWD_SUB_WALLPAPER,
    FMGR_ACTION_FWD_SCREENSAVER,
    FMGR_ACTION_FWD_POWER_ON,
    FMGR_ACTION_FWD_POWER_OFF,
    FMGR_ACTION_FWD_PHONEBOOK,
    FMGR_ACTION_FWD_TODOLIST,
    FMGR_ACTION_FWD_PROFILE,
    FMGR_ACTION_FWD_BGSOUND,
    FMGR_ACTION_FWD_SMS,
    FMGR_ACTION_FWD_MMS,
    FMGR_ACTION_FWD_EMS,
    FMGR_ACTION_FWD_EMAIL,
    FMGR_ACTION_FWD_IRDA,
    FMGR_ACTION_FWD_BT,
    FMGR_ACTION_PRINT_TO_PICTBRIGE,
    FMGR_ACTION_PRINT_TO_BLUETOOTH,

    FMGR_ACTION_OTHER,  /* for other app using FMT, ex:Ebook,DLAgent */
    FMGR_ACTION_OTHER_DEL_FOLDER,

    FMGR_ACTION_TOTAL

} fmgr_tree_action_enum;

typedef enum
{
    MMI_FMGR_FILEINFO_FLAG_IS_USED,
    MMI_FMGR_FILEINFO_FLAG_IS_ABLE_DISPLAY,
    MMI_FMGR_FILEINFO_FLAG_IS_ARCHIEVE,
    MMI_FMGR_FILEINFO_FLAG_IS_IN_ARCHIEVE,

    MMI_FMGR_FILEINFO_FLAG_ARCHIEVE_QUERIED,
    MMI_FMGR_FILEINFO_FLAG_DISPLAY_QUERIED,

    MMI_FMGR_FILEINFO_FLAG_MAX
} mmi_fmgri_fileinfo_flag_enum;

typedef enum
{
    /* FMGR internal error if < MMI_FMGR_ERROR_MAX */
    MMI_FMGRI_ERROR_START = MMI_FMGR_ERROR_MAX,
    MMI_FMGR_ERROR_EMPTY,
    MMI_FMGR_ERROR_PATH_TOO_DEEP,
    MMI_FMGR_ERROR_DEVICE_BUSY,
#ifdef __USB_IN_NORMAL_MODE__
    MMI_FMGR_ERROR_USB_MODE,
#endif

    MMI_FMGR_ERROR_BUFFER,

    MMI_FMGR_ERROR_LOADING_CANCEL,

    MMI_FMGR_ERROR_REQUIRE_ASYNC_LOADING,

    MMI_FMGRI_ERROR_MAX
    
} mmi_fmgr_internal_error_enum;

typedef enum
{
    FMGR_NORMAL_DRIVE = 0,
    FMGR_LINK_FOLDER = -1,
    FMGR_LINK_ITEM = -2
    
} fmgr_internal_drive_enum;

typedef enum
{
    FMGRI_DISPLAY_TYPE_BASE = FMGR_DISPLAY_TYPE_TOTAL,
        
    FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST, /* multi select */

    FMGRI_DISPLAY_TYPE_EXPAND_LIST,      /* List screen, highlight item is expanded */
    FMGRI_DISPLAY_TYPE_EXPAND_MS_LIST,   /* multi select, highlight item is expanded */

    FMGRI_DISPLAY_TYPE_NO_LIST,          /* file option, no explorer screen */
	
    FMGRI_DISPLAY_TYPE_TOTAL
    
} fmgr_internal_display_type_enum;


/********************************* Typedef ********************************/
/* Table */
typedef void (*mmi_fmgr_enabler_callback)(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
typedef void (*mmi_fmgr_handler_callback)(U16 menu_id, S8* filepath, const FMGR_FILE_INFO_STRUCT* fileinfo, U16 keyCode);

/* Option screen helper function
 *
 */
typedef U16 (*mmi_fmgri_option_callback)(U16 opt_menu_id, U16 menu_id, U32 data, U16 keyCode);
typedef S32 (*mmi_fmgri_option_entry_callback)(U16 opt_menu_id, U32 data);


typedef struct _fmgr_drive_info_struct
{
    U16 drv_path[SRV_FMGR_DRV_MAX_NAME_LEN + 1];
    U16 string_id;
    U16 icon_id;
    S16 drv_type;
    U16 lsk_string_id;
    FuncPtr lsk_hdlr;
    FuncPtr rarrow_hdlr;
#ifdef FMGR_TAB_SUPPORT
    U32 tab_id;
#endif /* FMGR_TAB_SUPPORT */
} fmgr_drive_info_struct;

typedef struct _fmgr_instance_struct 
{
    /* Basic data */
    U8 id; /* Instance id */
    U8 type; /* Instance type, mmi_fmgri_type_enum */
    U16 app_id; /* Application id */    
    U8 display_type; /* Screen type, LIST / LIST_TITLE / MATRIX */
    U8 arrow_type; /* Arrow type is for category display, CAT213_ARROW_XXX */
    U8 dirty_level;
    U8 key_binding;
    U16 title_icon_id;
    U16 title_str_id;
#ifdef FMGR_TAB_SUPPORT
    U32 tab_id;
#endif /* FMGR_TAB_SUPPORT */
    S32 cur_index;
    /* Instance`s type-specific data */
    U32 flag;
    U32 cust_data;
    /* User data */
    U32 user_data; /* This is data of user (those who create this instance) */
    U32 drv_type; /* Display drive type, srv_fmgr_drivelist_type_enum */
    /* Data related */
    S8 file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
    FMGR_FILTER filter_type;
    /* Delay post event */
    mmi_event_struct* delay_event;
    MMI_BOOL is_disable_ncenter;   /* disable ncenter or not */
} mmi_fmgr_instance_struct;

typedef struct _mmi_fmgr_context_struct
{
    /* Search file index */        
    U8  search_instance_id;    
    /* instance list */
    U8  instance_num;
    /* Query cache */
    U8                          _align0;
    U8                          _align1;
    
    U16                         query_app_id;
#if defined(__DRM_V02__) || defined __MMI_FMGR_MULTI_SELECT_SUPPORT__ 
    U16                         id_mark_counter;
#endif
    S8  *query_filepath;
#ifdef FMGR_TAB_SUPPORT
    U32                         query_tab_id;
#endif   


    S8  search_filename[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
#if defined(__DRM_V02__) || defined __MMI_FMGR_MULTI_SELECT_SUPPORT__
    U16                         instance_id_mark[MMI_FMGR_INSTANCE_MAX_NUM];
#endif
    mmi_fmgr_instance_struct    instance_list[MMI_FMGR_INSTANCE_MAX_NUM];
    FMGR_FILE_INFO_STRUCT       query_fileinfo;    

} mmi_fmgr_context_struct;

typedef struct {
    mmi_id                      parent_group_id;
    mmi_id                      option_group_id;
#ifdef __FMGR_USE_MENU_CUI__
    mmi_id                      menu_group_id;
#endif
    U16                         option_menu_id;
    U16                         highlight_idx;
    U16                         icon_id;
    U16                         title_str_id;
    U8                          display_type;
    mmi_fmgri_option_callback   callback;
    mmi_fmgri_option_entry_callback entry_callback;
    U32                         data;
    U16                         highlight_menu_id; /* only for first time enter */
    FuncPtr                     ime_close_callback;
    U32                         item_mask;
} fmgr_option_info_struct;

/****************************************************************************
* Global variable
*****************************************************************************/

/****************************************************************************
* Global Function
*****************************************************************************/

extern U32 mmi_fmgri_hash_func(const S8* path);

/* Prepare forward option
 *  This API will reset all childitem under given menu id, and call their enabler one by one.
 *  After API return, all unavailable option is hidden.
 *  Note. Can be used on both send/use option.
 */
extern void mmi_fmgri_prepare_option(mmi_fmgr_instance_struct *instance, U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgri_prepare_forward_option(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);

extern S32  mmi_fmgri_get_forward_option(S8* filepath, const FMGR_FILE_INFO_STRUCT* fileinfo, U16 app_id, MMI_BOOL is_send);

extern S32  mmi_fmgri_get_file_option(S8* file_path, S8 need_convert, U32 flag, U16 app_id);

/* Table query function 
 * 
 */
extern mmi_fmgr_enabler_callback mmi_fmgri_table_get_forward_enabler(U16 menu_id);
extern mmi_fmgr_enabler_callback mmi_fmgri_table_get_option_enabler(U16 menu_id);

extern BOOL mmi_fmgr_filter_check_by_index_and_ext(FMGR_FILTER *filter_type, S8 *ext);

extern void mmi_fmgri_show_option(mmi_id parent,
                                  U16 option_menu_id, 
                                  mmi_fmgri_option_callback callback, 
                                  U32 data, 
                                  U16 icon_id);
extern void mmi_fmgri_show_option_ex(mmi_id parent,
                                  U16 option_menu_id, 
                                  mmi_fmgri_option_callback callback, 
                                  U32 data, 
                                  U16 icon_id, U16 title_str_id,
                                  mmi_fmgri_option_entry_callback entry_callback,
                                  mmi_fmgri_option_type_enum type,
                                  U16 highlight_menu_id);
#ifdef __FMGR_FILE_OPTION_CUI__
extern void mmi_fmgri_show_option_for_file_option_cui(mmi_id parent, U16 option_menu_id, 
                           mmi_fmgri_option_callback callback, 
                           U32 data, U16 icon_id, 
                           U16 title_str_id,
                           mmi_fmgri_option_entry_callback entry_callback,
                           mmi_fmgri_option_type_enum type,
                           U16 highlight_menu_id,
                           WCHAR* title_str);
#endif
#ifndef __FMGR_USE_EDITOR_CUI__
extern void mmi_fmgri_show_edit_option(mmi_id parent,
                                  U16 option_menu_id, 
                                  mmi_fmgri_option_callback callback, 
                                  U32 data, 
                                  U16 icon_id,
                                  FuncPtr ime_close_callback);
#endif
extern void mmi_fmgri_close_option(U16 option_menu_id, U32 data);
extern void mmi_fmgri_close_options(U32 data);
extern void mmi_fmgri_option_replace_appstring(U16 menu_id, U16 string_id);

extern U16 mmi_fmgri_get_menu_link(U16 menu_id);

#if 0   /* This is for option link, disable it for now */
/* under construction !*/
/* under construction !*/
#endif

/* Filepath helper function
 *  These function take "root" into consideration.
 */
extern MMI_BOOL mmi_fmgri_filepath_compose(S8* buffer, U32 buffer_len, 
                                       S8* base_folder,
                                       FMGR_FILE_INFO_STRUCT *file_info,
                                       MMI_BOOL add_slash);
extern MMI_BOOL mmi_fmgri_filepath_go_up_level(S8* file_path);

/* Query api helper function
 *  
 */
extern void mmi_fmgri_query_result_setup(S8* filepath, FMGR_FILE_INFO_STRUCT* info, U16 app_id);
extern void mmi_fmgri_query_result_clear(void);
#ifdef FMGR_TAB_SUPPORT
extern void mmi_fmgri_query_result_tab_setup(U32 tab_id);
extern U32  mmi_fmgri_get_query_tab(void);
#endif

/* 
 *  
 */
#define mmi_fmgri_get_and_lock_buffer()   mmi_fmgri_get_and_lock_buffer_internal(__LINE__)
extern S8*  mmi_fmgri_get_and_lock_buffer_internal(S32 line);
extern void mmi_fmgri_free_and_unlock_buffer(S8* buffer);

#ifdef __FMGR_HYPERLINK_SUPPORT__
/* 
 *  
 */
extern mmi_fmgr_hyperlink_callback mmi_fmgri_table_get_hyperlink_callback(U16 app_id, S8* path);
#endif /* __FMGR_HYPERLINK_SUPPORT__ */

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
/* 
 *  
 */
extern S32  mmi_fmgri_table_cr_get_count(U32 drv_mask, S8 exclude_item);

extern MMI_BOOL mmi_fmgri_table_cr_get_info(U32 drv_mask, S32 index, fmgr_drive_info_struct* info, S8 exclude_item);
extern S32  mmi_fmgri_table_cr_get_index(const U16* path, S8 exclude_item, S8 full_match, U8 drv_type);

#ifdef FMGR_TAB_SUPPORT
extern S32  mmi_fmgri_table_tab_get_count(U32 tab_id);
extern S32  mmi_fmgri_table_tab_get_path(U32 tab_id, S32 tab_index, WCHAR* path, U32 path_size);
extern U16  mmi_fmgri_table_tab_get_icon(U32 tab_id, S32 tab_index);
extern U16  mmi_fmgri_table_tab_get_title(U32 tab_id, S32 tab_index);
extern S32  mmi_fmgri_table_tab_get_index(U32 tab_id, const WCHAR* path);
extern MMI_BOOL mmi_fmgri_table_tab_switch(U32 tab_id, WCHAR* path, U32 path_size, S8 offset);

extern S32  mmi_fmgri_table_tab_get_root_index(U32 tab_id, const WCHAR* path, U8 drv_type, S8 exclude_item, S8 full_match);
#endif
#endif

/* 
 *  
 */
extern void mmi_fmgri_displaypopup(U16 err_str_id, mmi_event_notify_enum popup_type, S32 fileline, FuncPtr f);

#ifndef __MTK_TARGET__
extern void mmi_fmgri_modis_showtrace(char* format, ...);
#endif

/* 
 *  
 */
#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
extern BOOL mmi_fmgr_cidb_notify_hdlr(U32 notify_flag, void* para);
#endif

/* 
 *  
 */
typedef void (*mmi_fmgri_sort_buffer_callback)(U32 data);
extern void* mmi_fmgri_sort_buffer_alloc(U32 size, mmi_fmgri_sort_buffer_callback cb, U32 data);
extern void mmi_fmgri_sort_buffer_free(void* buffer);
extern void mmi_fmgri_sort_buffer_update_config(void* buffer, mmi_fmgri_sort_buffer_callback new_cb, U32 new_data);

/* 
 *  
 */
#if defined (__MMI_FMGR_FOLDER_COPY_SUPPORT__)
extern MMI_BOOL mmi_fmgri_main_can_modify_folder(mmi_fmgr_instance_struct *instance, const S8* path);
extern MMI_BOOL mmi_fmgri_msa_is_src_folder(U32 instance_id, S8 *dst_path);
extern MMI_BOOL mmi_fmgri_msa_is_src_folder_for_compare_all(U32 instance_id, const S8 *dst_path);
#endif
#ifdef __FS_CARD2_SUPPORT__
MMI_BOOL mmi_fmgri_is_drv_card_2_type_by_path(const S8 *file_path);
#endif
#ifdef _MMI_FMGR_ENABLE_PERF_
typedef enum
{
    MMI_FMGRI_PERF_START = 0,
    MMI_FMGRI_PERF_fmgr_gui_get_file_item_callback,
    MMI_FMGRI_PERF_fmgr_gui_get_file_info_callback,
    MMI_FMGRI_PERF_fmgr_gui_get_image_path_callback,
    MMI_FMGRI_PERF_fmgr_gui_get_file_menuitem_callback,
    MMI_FMGRI_PERF_mmi_fmgri_gui_display_list,
    MMI_FMGRI_PERF_fmgr_general_entry_explorer,
    MMI_FMGRI_PERF_fmgr_general_key_event_hdlr,
    MMI_FMGRI_PERF_fmgr_option_key_hdlr,
    MMI_FMGRI_PERF_fmgr_main_mark_several_get_file_image,
    MMI_FMGRI_PERF_fmgr_main_mark_several_get_file_description,
    MMI_FMGRI_PERF_ShowCategory426Screen,
    MMI_FMGRI_PERF_NUM

} mmi_fmgri_perf_enum;

extern void mmi_fmgri_perf_start(mmi_fmgri_perf_enum id, S32 data);
extern void mmi_fmgri_perf_end(mmi_fmgri_perf_enum id);

#define FMGR_PERF_START(id, data)   mmi_fmgri_perf_start(MMI_FMGRI_PERF_##id, data)
#define FMGR_PERF_END(id)           mmi_fmgri_perf_end(MMI_FMGRI_PERF_##id)
#else
#define FMGR_PERF_START(id, data)   
#define FMGR_PERF_END(id)
#endif


/* Move to GProt.h later
 *  
 */

#else

#define FMGR_ASSERT(expr)  ASSERT(expr)

#endif /* #if defined (__MMI_FILE_MANAGER__) */

#endif /* _FMGR_PROT_H_ */
