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
 *  FileManagerResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager Defines
 *
 * Author:
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _FMGR_RES_DEF_H_
#define _FMGR_RES_DEF_H_
#include "MMI_features.h"

#include "mmi_rp_srv_filemanager_def.h"

#ifdef __PLUTO_MMI_PACKAGE__
#if defined (__MMI_FILE_MANAGER__)
#if !defined(__IOT__)
#include "mmi_rp_app_filemanager_def.h"
#endif
#endif
#include "mmi_res_range_def.h"
#include "MMIDataType.h"

/****************************************************************************
* Define - Macro
*****************************************************************************/

/****************************************************************************/

#ifdef __FS_SORT_SUPPORT__      
#define FMGR_GENERAL_OPT_SORT \
    MENU_ID_FMGR_GEN_OPTION_SORT,
#else
#define FMGR_GENERAL_OPT_SORT 
#endif

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
#define FMGR_GENERAL_OPT_MULTI_SELECT \
    MENU_ID_FMGR_GEN_OPTION_MARK_SEVERAL,
#else
#define FMGR_GENERAL_OPT_MULTI_SELECT 
#endif 

#ifndef __MMI_SLIM_FILE_MANAGER__
#define FMGR_GENERAL_OPT_DELETE_ALL \
    MENU_ID_FMGR_GEN_OPTION_DELETE_ALL,
#else
#define FMGR_GENERAL_OPT_DELETE_ALL 
#endif

#ifdef __MMI_RMGR__
#define FMGR_GENERAL_OPT_MORE_RITS \
    MENU_ID_FMGR_GEN_OPTION_MORE_RITS,
#else
#define FMGR_GENERAL_OPT_MORE_RITS
#endif

#define FMGR_GENERAL_OPTION \
    MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND, \
    MENU_ID_FMGR_GEN_OPTION_FORWARD_USE, \
    MENU_ID_FMGR_FOLDER_CREATE, \
    FMGR_GENERAL_OPT_MORE_RITS \
    MENU_ID_FMGR_GEN_OPTION_RENAME, \
    MENU_ID_FMGR_GEN_OPTION_DELETE, \
    FMGR_GENERAL_OPT_SORT \
    FMGR_GENERAL_OPT_MULTI_SELECT \
    MENU_ID_FMGR_GEN_OPTION_COPY, \
    MENU_ID_FMGR_GEN_OPTION_MOVE, \
    FMGR_GENERAL_OPT_DELETE_ALL \
    MENU_ID_FMGR_GEN_OPTION_DETAIL, \


#define ADD_FMGR_MENUITEM(x) ADD_APPLICATION_MENUITEM2(x)

/****************************************************************************/
#if defined(__IOT__)
#ifndef FILE_MANAGER_OTHER_BASE
#define FILE_MANAGER_OTHER_BASE (0)
#endif
#endif
/****************************************************************************
* Define - Enum
*****************************************************************************/

typedef enum
{
    FMGR_SCR_BASE = FILE_MANAGER_OTHER_BASE + 1,

    /* 2.0 screen begin */

    SCR_ID_FMGR_EXPLORER_BASE,
    SCR_ID_FMGR_EXPLORER_BASE_1,
    SCR_ID_FMGR_EXPLORER_BASE_2,
    SCR_ID_FMGR_EXPLORER_BASE_3,
    SCR_ID_FMGR_EXPLORER_BASE_4,
    SCR_ID_FMGR_EXPLORER_END = SCR_ID_FMGR_EXPLORER_BASE + 5,

    SCR_ID_FMGR_OPTION_BASE,
    SCR_ID_FMGR_OPTION_BASE_1,
    SCR_ID_FMGR_OPTION_BASE_2,
    SCR_ID_FMGR_OPTION_BASE_3,
    SCR_ID_FMGR_OPTION_BASE_4,
    SCR_ID_FMGR_OPTION_END = SCR_ID_FMGR_OPTION_BASE + 5,

    SCR_ID_FMGR_GENERAL_DUMMY,
    SCR_ID_FMGR_OPTION_DUMMY,
    
    /* mark multi file */
    SCR_ID_FMGR_MULTI_SELECT,

    SCR_ID_FMGR_PROCESSING,
    SCR_ID_FMGR_CARD_SOFT_UNMOUNT,

    /* tab support */
    SCR_ID_FMGR_TAB_BASE,
    SCR_ID_FMGR_TAB_1,
    SCR_ID_FMGR_TAB_2,
    SCR_ID_FMGR_TAB_3,
    SCR_ID_FMGR_TAB_4,
    SCR_ID_FMGR_TAB_END = SCR_ID_FMGR_TAB_BASE + 5,
    
    /* 2.0 screen end */

    SCR_FMGR_FILENAME_EDITOR,
    SCR_FMGR_DETAIL,
    SCR_FMGR_CARD_DETAIL,
    SCR_FMGR_PHONE_LOCK_VERIFY,

    /* Following screen id are obsolete */
    
    SCR_FMGR_MAIN,
    //SCR_FMGR_SEL_DRV,

    //SCR_FMGR_DRIVE_OPTION,
    //SCR_FMGR_FOLDER_OPTION,
    SCR_FMGR_FILE_OPTION,

    //SCR_FMGR_APP_DRIVE_OPTION,
    //SCR_FMGR_APP_FOLDER_OPTION,
    SCR_FMGR_APP_EMPTY_FOLDER_OPTION,
    SCR_FMGR_APP_FILE_OPTION,

    SCR_FMGR_DA_FILE_OPTION,
    //SCR_FMGR_DA_FORWARD_OPTION,

    //SCR_FMGR_INFO,
    //SCR_FMGR_FORWARD_OPTION,
    //SCR_FMGR_SORT_OPTION,
    
    //SCR_FMGR_EDITOR_OPTION,

    //SCR_FMGR_TREE_EXPLORER,
    //SCR_FMGR_TREE_DRIVE_OPTION,
    //SCR_FMGR_TREE_OPTION,

    //SCR_FMGR_COPY_ANIMATION,
    //SCR_FMGR_DELETE_ANIMATION,
    //SCR_FMGR_DRIVE_ANIMATION,

    //SCR_FMGR_ABORTING,
      
    //SCR_FMGR_CONFIRM,

    //FMGR_SCR_MARKER,    // MARKER!

    /* DRM */
    //SCR_FMGR_MUL_ODF_EXPLORER,
    //SCR_FMGR_APP_MUL_ODF_OPTION,

    //SCR_ID_FMGR_MULTI_SELECT_LOADING,

    NO_OF_FMGR_SCR
} FMGR_SCR_IDS;

#define SCR_FMGR_EXPLORER   SCR_ID_FMGR_EXPLORER_BASE

typedef enum
{
    FMGR_STRING_BASE = FILE_MANAGER_OTHER_BASE + 1,
    NO_OF_FMGR_TEXT
} FMGR_STRING_IDS;

#define STR_ID_FMGR_INVALID_IMAGE_FORMAT    STR_GLOBAL_INVALID_FORMAT
#define STR_FMGR_SORT_NONE                  STR_GLOBAL_NONE
#define FMGR_FS_FAIL_GET_MEM_TEXT           STR_GLOBAL_NOT_ENOUGH_MEMORY
#define FMGR_FS_DISK_FULL_TEXT              STR_GLOBAL_NOT_ENOUGH_MEMORY
#define STR_FMGR_SORT                       STR_GLOBAL_SORT_BY
#define STR_FMGR_INVALID_FORMAT             STR_GLOBAL_UNSUPPORTED_FORMAT
#define FMGR_FS_INVALID_FILENAME_TEXT       STR_GLOBAL_INVALID_FILENAME
#define STR_FMGR_REM_DEVICE                 STR_GLOBAL_MEMORY_CARD
#define STR_FMGR_NOR_FLASH                  STR_GLOBAL_PHONE
#define STR_FMGR_NAND_FLASH                 STR_GLOBAL_PHONE

#define STR_ID_FMGR_EMPTY_FOLDER            STR_ID_FMGR_NO_FILES

typedef enum
{
    FMGR_IMAGE_BASE = FILE_MANAGER_OTHER_BASE + 1,
    NO_OF_FMGR_IMG
} FMGR_IMG_IDS;

#define    MENU_FMGR_GEN_OPTION_FORWARD            MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND
#define    MENU_FMGR_GEN_OPTION_RENAME             MENU_ID_FMGR_GEN_OPTION_RENAME
#define    MENU_FMGR_GEN_OPTION_DELETE             MENU_ID_FMGR_GEN_OPTION_DELETE
#define    MENU_FMGR_GEN_OPTION_DETAIL             MENU_ID_FMGR_GEN_OPTION_DETAIL
#define    MENU_FMGR_GEN_OPTION_COPY               MENU_ID_FMGR_GEN_OPTION_COPY
#define    MENU_FMGR_GEN_OPTION_MOVE               MENU_ID_FMGR_GEN_OPTION_MOVE
#ifndef __MMI_SLIM_FILE_MANAGER__
#define    MENU_FMGR_GEN_OPTION_DELETE_ALL         MENU_ID_FMGR_GEN_OPTION_DELETE_ALL
#endif
#define    MENU_FMGR_GEN_OPTION_SORT               MENU_ID_FMGR_GEN_OPTION_SORT

#define    MENU_FMGR_SELECT_DONE                   MENU_ID_FMGR_FOLDER_SELECT_DONE
#define    MENU_FMGR_GEN_OPTION_OPEN               MENU_ID_FMGR_FOLDER_OPEN

#else

#define STR_ID_FMGR_INVALID_IMAGE_FORMAT    STR_GLOBAL_INVALID_FORMAT
#define STR_FMGR_SORT_NONE                  STR_GLOBAL_NONE
#define FMGR_FS_FAIL_GET_MEM_TEXT           STR_GLOBAL_NOT_ENOUGH_MEMORY
#define FMGR_FS_DISK_FULL_TEXT              STR_GLOBAL_NOT_ENOUGH_MEMORY
#define STR_FMGR_SORT                       STR_GLOBAL_SORT_BY
#define STR_FMGR_INVALID_FORMAT             STR_GLOBAL_UNSUPPORTED_FORMAT
#define FMGR_FS_INVALID_FILENAME_TEXT       STR_GLOBAL_INVALID_FILENAME
#define STR_FMGR_REM_DEVICE                 STR_GLOBAL_MEMORY_CARD
#define STR_FMGR_NOR_FLASH                  STR_GLOBAL_PHONE
#define STR_FMGR_NAND_FLASH                 STR_GLOBAL_PHONE

#define STR_ID_FMGR_EMPTY_FOLDER            STR_GLOBAL_EMPTY

typedef enum
{
    STR_ID_FMGR_NO_FORWARD_OPTION = GET_RESOURCE_BASE(VAPP_FMGR)+101, /* BASE_ID + 1 */
    //STR_ID_FMGR_NOT_AVAILABLE,
    STR_FMGR_TITLE,
    STR_FMGR_FOLDER_CREATE,
    STR_FMGR_FORMAT,
    STR_FMGR_FORMATING,
    STR_FMGR_FORMAT_CONFIRM,
    STR_FMGR_UNMOUNTING,
    STR_FMGR_CARD_NAME,
    STR_ID_FMGR_TOTAL_SIZE,
    STR_ID_FMGR_FREE_SIZE,
    STR_FMGR_USE,
    STR_FMGR_COPIED,
    STR_FMGR_MOVED,
    STR_FMGR_COPY_TO,
    STR_FMGR_MOVE_TO,
    STR_FMGR_MARK_SEVERAL,
    STR_FMGR_MARK_DELETE,
    STR_FMGR_MARK_COPY,
    STR_FMGR_MARK_MOVE,
    STR_FMGR_MARK_PRINT,
    STR_ID_FMGR_MARK_TO_BT,
    STR_FMGR_MARK_MAX_FILE,
    STR_FMGR_MARK_SEVERAL_PRESS_STAR,
    STR_FMGR_MARK_SEVERAL_TOUCH_BOX,
    STR_ID_FMGR_MARK_ALL_PROTECTED,
    STR_ID_FMGR_MARK_PARTIAL_PROTECTED_CONFIRM,
    STR_ID_FMGR_MARK_PARTIAL_FOLDERS_CONFIRM,
    STR_ID_FMGR_MARK_ALL_CAN_NOT_SEND,
    STR_ID_FMGR_MARK_ALL_CAN_NOT_SEND_CONFIRM,
    STR_FMGR_SORT_BY_NAME,
    STR_FMGR_SORT_BY_TYPE,
    STR_FMGR_SORT_BY_TIME,
    STR_FMGR_SORT_BY_SIZE,
    STR_FMGR_INVALID_EMS_FORMAT,
    STR_ID_FMGR_DRV_FREE_SPACE,
    STR_ID_FMGR_DRV_TOTAL_SPACE,
    STR_ID_FMGR_FILE_DATE,
    STR_ID_FMGR_FILE_SIZE,
    STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE,
    STR_ID_FMGR_QUESTION_MARK,
    STR_ID_FMGR_NO_AVAILABLE_STORAGE,
    STR_ID_FMGR_NEW_FOLDER_LSK,
    STR_ID_FMGR_FOLDER_NAME,
    STR_ID_FMGR_CARD_NAME,
    STR_ID_FMGR_NO_FILES,
    STR_ID_FMGR_NO_FOLDERS,
    STR_ID_FMGR_FOLDER_THE_SAME,
    STR_ID_FMGR_CONTINUE_CONFIRM,
    STR_ID_FMGR_RESTART_CONTINUE,
    MMI_RP_APP_FILEMANAGER_STR_MAX
}mmi_rp_app_filemanager_str_enum;

typedef enum
{
    MENU_ID_FMGR_DRIVE_OPTIONS = GET_RESOURCE_BASE(VAPP_FMGR)+101, /* BASE_ID + 1 */
    MENU_ID_FMGR_APP_DRIVE_OPTIONS,
    MENU_ID_FMGR_DRIVE_OPEN,
    MENU_ID_FMGR_DRIVE_FORMAT,
    MENU_ID_FMGR_DRIVE_UNMOUNT,
    MENU_ID_FMGR_DRIVE_SELECT_DONE,
    MENU_ID_FMGR_DRIVE_RENAME,
    MENU_ID_FMGR_CARD_DETAIL,
    MENU_ID_FMGR_FOLDER_OPTIONS,
    MENU_ID_FMGR_APP_FOLDER_OPTIONS,
    MENU_ID_FMGR_FOLDER_OPEN,
    MENU_ID_FMGR_FOLDER_CREATE,
    MENU_ID_FMGR_FOLDER_SELECT_DONE,
    MENU_ID_FMGR_HYPERLINK_OPTIONS,
    MENU_ID_FMGR_HYPERLINK_APP_FUNC,
    MENU_ID_FMGR_TREE_OPTIONS,
    MENU_ID_FMGR_TREE_SELECT,
    MENU_ID_FMGR_TREE_OPEN,
    MENU_ID_FMGR_GEN_TYPE_OPTIONS,
    MENU_ID_FMGR_GEN_OPTION_FORWARD_USE,
    MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND,
    MENU_ID_FMGR_GEN_OPTION_DETAIL,
    MENU_ID_FMGR_GEN_OPTION_MORE_RITS,
    MENU_ID_FMGR_GEN_OPTION_RENAME,
    MENU_ID_FMGR_GEN_OPTION_COPY,
    MENU_ID_FMGR_GEN_OPTION_MOVE,
    MENU_ID_FMGR_GEN_OPTION_MARK_SEVERAL,
    MENU_ID_FMGR_GEN_OPTION_MARK_OPTION,
    MENU_ID_FMGR_GEN_OPTION_MARK_DELETE,
    MENU_ID_FMGR_GEN_OPTION_MARK_COPY,
    MENU_ID_FMGR_GEN_OPTION_MARK_MOVE,
    MENU_ID_FMGR_GEN_OPTION_MARK_APP_COPY,
    MENU_ID_FMGR_GEN_OPTION_MARK_APP_MOVE,
    MENU_ID_FMGR_MARK_OPTION_TO_BT,
    MENU_ID_FMGR_GEN_OPTION_MARK_MARK,
    MENU_ID_FMGR_GEN_OPTION_MARK_UNMARK,
    MENU_ID_FMGR_GEN_OPTION_MARK_MARK_ALL,
    MENU_ID_FMGR_GEN_OPTION_MARK_UNMARK_ALL,
    MENU_ID_FMGR_GEN_OPTION_MARK_EXIT,
    MENU_ID_FMGR_GEN_OPTION_DELETE,
    MENU_ID_FMGR_GEN_OPTION_DELETE_ALL,
    MENU_ID_FMGR_GEN_OPTION_SORT,
    MENU_ID_FMGR_SORT_BY_NAME,
    MENU_ID_FMGR_SORT_BY_TYPE,
    MENU_ID_FMGR_SORT_BY_TIME,
    MENU_ID_FMGR_SORT_BY_SIZE,
    MENU_ID_FMGR_SORT_NONE,
    MENU_ID_FMGR_EDITOR_OPTION,
    MENU_ID_FMGR_EDITOR_DONE,
    MENU_ID_FMGR_EDITOR_INPUT_METHOD,
    MMI_RP_APP_FILEMANAGER_MENU_MAX
}mmi_rp_app_filemanager_menu_enum;

#define NO_OF_FMGR_SCR GET_RESOURCE_BASE(VAPP_FMGR)+100
#define NO_OF_FMGR_TEXT GET_RESOURCE_BASE(VAPP_FMGR)+100 
#define NO_OF_FMGR_IMG GET_RESOURCE_BASE(VAPP_FMGR)+100 
#endif

#endif
