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
 *  FileMgrGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager exported APIs.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _FMGR_GPROT_H_
#define _FMGR_GPROT_H_


// Move to MMI_feature.h
// #define __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__

// Move to MMI_feature.h
// #define __MMI_FMGR_SUPPORT_SOFT_UNMOUNT__

/****************************************************************************
* FileMgr.h 
*****************************************************************************/

#define __FILE_MANAGER_GPROT_H_
#define _FILE_MGR_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "MMIDatatype.h"

#include "fs_errcode.h"

#include "fs_type.h"
#ifdef __MMI_FTE_SUPPORT__
#include "gui_typedef.h"
#endif

#include "FileMgrSrvGProt.h"


#include "kal_general_types.h"
#include "mmi_rp_file_type_def.h"
#include "custom_mmi_default_value.h"

#include "flash_opt.h"	/* __PUBLIC_DRIVE_AVAILABLE__ */
/****************************************************************************
* Setting
*****************************************************************************/
//#if defined (__MMI_FILE_MANAGER__)

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_FMGR_SUPPORT_THUMB_DECODE__
#define FMGR_USING_CACHE
#endif 

#ifdef __MMI_MAINLCD_240X320__
#define FMGR_THUMB_IMAGE_BUFFER_SIZE         (100*1024)  /* 100 k */    /* this buffer imporve viewing performace alot !! */
#else 
#define FMGR_THUMB_IMAGE_BUFFER_SIZE         (60*1024)   /* 60 k */     /* this buffer imporve viewing performace alot !! */
#endif 
/* DOM-NOT_FOR_SDK-END */

//#endif
/****************************************************************************
* Define
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/* The maximum length of a file's fullpath, including null character */
//#define FMGR_MAX_PATH_LEN           (260)
/* The maximum length of a file's extension, NOT including null character */
//#define FMGR_MAX_EXT_LEN            (5)
/* the maximum length of a volumn */
//#define FMGR_MAX_VOLUMN_LEN         (5)
/* The maximum length of a file's fullpath in characters, NOT including null character */
//#define FMGR_PATH_CHAR_COUNT        (259)
/* The maximum length of a drive's name, NOT including null character */
//#define FMGR_MAX_DRIVE_NAME_LEN  16
/* DOM-NOT_FOR_SDK-END */

/* the maximum length of a file's name */
#define FMGR_MAX_INPUT_FILE_LEN     (SRV_FMGR_PATH_MAX_FILE_NAME_LEN - SRV_FMGR_PATH_MAX_FILE_EXT_LEN)

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef LOW_COST_SUPPORT
/* For FS_XDelete() : 5204 bytes = 5KB */
#define MMI_FMGR_XDELETE_FOLDER_MAX_LEVEL    (39)
#define MMI_FMGR_XDELETE_MAX_BUFFER          (FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL(MMI_FMGR_XDELETE_FOLDER_MAX_LEVEL))

/* For FS_Move() base: 528+2048 */
#define MMI_FMGR_COPY_SPEED_UP_BUFFER        (0)
#define MMI_FMGR_COPY_BASE_BUFFER            (2568)

#define MMI_FMGR_COPY_MAX_BUFFER             (MMI_FMGR_COPY_BASE_BUFFER+MMI_FMGR_COPY_SPEED_UP_BUFFER)

#else

/* For FS_XDelete() : 10360 bytes = 10KB */
#define MMI_FMGR_XDELETE_FOLDER_MAX_LEVEL    (128)
#define MMI_FMGR_XDELETE_MAX_BUFFER          (FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL(MMI_FMGR_XDELETE_FOLDER_MAX_LEVEL))

/* For FS_Move() */
#define MMI_FMGR_COPY_SPEED_UP_BUFFER        (8*1024)
#define MMI_FMGR_COPY_BASE_BUFFER            (1024)
#define MMI_FMGR_COPY_MAX_BUFFER             (MMI_FMGR_COPY_BASE_BUFFER+MMI_FMGR_COPY_SPEED_UP_BUFFER)
#endif


/* app memory for copy/delete fs lock buffer + enhance card drive copy throughput */
#define MMI_FMGR_APP_MEM_SIZE        (MMI_FMGR_COPY_MAX_BUFFER > MMI_FMGR_XDELETE_MAX_BUFFER?MMI_FMGR_COPY_MAX_BUFFER:MMI_FMGR_XDELETE_MAX_BUFFER)

#if !defined(__MMI_FMGR_MULTI_SELECT_SUPPORT_WITH_ASM__)
#define __MMI_FMGR_MULTI_SELECT_SUPPORT_WITH_ASM__
#endif

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
#define FMGR_MAX_MARK_ITEM              50

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT_WITH_ASM__
/* app memory for mark several */
#define SIZE_OF_MSA_STRUCT_SIZE_ARRAY (sizeof(U32)*FMGR_MAX_MARK_ITEM)
#define SIZE_OF_MSA_STRUCT_TIME_ARRAY (sizeof(U32)*FMGR_MAX_MARK_ITEM)
#define SIZE_OF_MSA_STRUCT_NAME_ARRAY (sizeof(S8)*FMGR_MAX_MARK_ITEM*(SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH)
#define SIZE_OF_MSA_STRUCT_FLAG_ARRAY (sizeof(S8)*FMGR_MAX_MARK_ITEM)

#define MMI_FMGR_MARK_SEVERAL_MEM_SIZE \
        SIZE_OF_MSA_STRUCT_SIZE_ARRAY + SIZE_OF_MSA_STRUCT_TIME_ARRAY \
        + SIZE_OF_MSA_STRUCT_NAME_ARRAY + SIZE_OF_MSA_STRUCT_FLAG_ARRAY
#endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT_WITH_ASM__ */
#endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

#if !defined (__MMI_ULTRA_SLIM_FILE_MANAGER__) || defined (__PUBLIC_DRIVE_AVAILABLE__)
#define __FMGR_STORAGE_SELECTOR_CUI__
#endif

#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
#define __FMGR_FILE_OPTION_CUI__
#endif
/* DOM-NOT_FOR_SDK-END */

/****************************************************************************
* Typedef                                                            
*****************************************************************************/
//#if defined (__MMI_FILE_MANAGER__)

/* 
 * Flags used by mmi_fmgr_select_path(), mmi_fmgr_browse_path()
 */
typedef enum
{
    FMGR_SELECT_DEFAULT                     = 0x0, 
    FMGR_SELECT_BROWSE                      = FMGR_SELECT_DEFAULT,  /* Obsolete */
    FMGR_SELECT_FILE_SET                    = FMGR_SELECT_DEFAULT,  /* Obsolete */

    /* Following flags are used by mmi_fmgr_select_path() */
    FMGR_SELECT_FILE                        = 0x00000001,           /* select file */
    FMGR_SELECT_FOLDER                      = 0x00000002,           /* select folder */
    FMGR_SELECT_FILE_OR_FOLDER              = FMGR_SELECT_FILE | FMGR_SELECT_FOLDER,    /* select file & folder */

    FMGR_SELECT_REPEAT                      = 0x00000004,   /* repeat selection. If this flag is not 
                                                               specified, after use select a file/folder,
                                                               select screen will disappear automatically.
                                                               If this flag is specified, select screen will
                                                               remain to allow user select next file/folder,
                                                               Caller must use mmi_fmgr_close_select_path() 
                                                               to end the selection */
    FMGR_FLAG_PREVIEW_AUDIO                 = 0x00000008,   /* If this flag is specified, FMGR will play 
                                                               current highlight audio file. This is used
                                                               by profiles APPs when user is selecting a 
                                                               ringtone */

    FMGR_FLAG_CHECK_SENDABLE                = 0x00000010,   /* DRM related. If this flag is specified, FMGR 
                                                               will check if a user selected file can be sent
                                                               or not before callback to APPs.
                                                               For non-sendable file, DRM prohibit error is 
                                                               displayed, user can select another file.
                                                               Only valid when DRM_SUPPORT is on. */
    FMGR_FLAG_CHECK_USABLE                  = 0x00000020,   /* DRM related. If this flag is specified, FMGR 
                                                               will check if a user selected file can be used
                                                               or not before callback to APPs.
                                                               For non-usable file, DRM prohibit error is 
                                                               displayed, user can select another file.
                                                               Only valid when DRM_SUPPORT is on. */

    FMGR_FLAG_BACK_TO_UPPER_DIRECTORY       = 0x00000040,   /* If this flag is specified, RSK Back will back 
                                                               to upper directory, instead of cancel selection */
                                                               
    FMGR_FLAG_FIXED_PATH                    = 0x00080000,   /* VF Project will overwrite select path start from 'root'(my files)
                                                               if App not support my files style, it should specify this flag to
                                                               ask FMGR not overwrite the path */

    /* Following flags are used by mmi_fmgr_select_path() or mmi_fmgr_browse_path() */
    FMGR_SELECT_ARCHIVE                     = 0x00000100,   /* DRM 2.0 related. If this flag is specified, a 
                                                               multipart ODF is treated as a single file
                                                               user can select it.
                                                               If not specified, a multipart ODF is treated
                                                               as a folder, user can only open it.
                                                               This flag cannot be used with 
                                                               FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT. 
                                                               Only valid when __DRM_V02__ is on. */
    FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT  = 0x00000200,   /* DRM 2.0 related. If this flag is sepcifed, a
                                                               multipart ODF can not be selected, nor can be
                                                               opened. 
                                                               This flag cannot be used with FMGR_SELECT_ARCHIVE 
                                                               Only valid when __DRM_V02__ is on. */
    
    /* Internel used by My Favorite/My Files */
    FMGR_FLAG_BASEPATH                      = 0x00010000,   /* Internel use, please dont use this flag */
    FMGR_FLAG_ENABLE_CHANGE_FOLDER          = 0x00020000 | FMGR_FLAG_BASEPATH,  /* Internel use, please 
                                                               dont use this flag */

    /* Following flags are used by mmi_fmgr_browse_path() */
#ifdef __FMGR_CSK_FORWARD__
    FMGR_FLAG_FAST_FORWARD_CSK              = 0x00040000,   /* If this flag is specified, a center softkey
                                                               icon will appear when highlight file is 
                                                               sendable. User can press CSK to enter send menu
                                                               directly to forward this file to MMS/BT/Email 
                                                               */
#endif

    FMGR_FLAG_ENUM = 0x7FFFFFFF
} fmgr_flag_enum;

//#endif

/****************************************************************************/

/* Used by mmi_fmgr_util_send_copy_req() to indicate 
 *  this is Copy or Move operation
 */
typedef enum
{
    FMGR_ACTION_NONE = 0,
        
    FMGR_ACTION_COPY,       /* Copy */
    FMGR_ACTION_MOVE,       /* Move */

    FMGR_ACTION_END

} fmgr_action_enum;

/****************************************************************************/

//#if defined (__MMI_FILE_MANAGER__)
/* Used by mmi_fmgr_browse_path(), APPs can choose the display style of browse UI
 */
typedef enum
{
    FMGR_DISPLAY_TYPE_ICON_LIST,        /* with large icon in each list-item, such as: Image viewer, video player, ... */
    FMGR_DISPLAY_TYPE_BANNER_LIST,      /* with banner in the top of screen. such as: FMGR, ... */
    FMGR_DISPLAY_TYPE_SIMPLE_LIST,      /* just list screen, no banner, no icon */
    FMGR_DISPLAY_TYPE_MATRIX,           /* matrix list, such as image viewer */

    FMGR_DISPLAY_TYPE_TOTAL
    
} fmgr_display_type_enum;

/* If a application want to use hyperlink, it should provide a callback to FMGR_HYPERLINK_COL 
 *  in FileMgrTable.h, this callback should support following enum and return data
 */
typedef enum
{
    FMGR_HYPERLINK_GET_COUNT,   /* check if current path require hyperlink support, if yes, how many? */
    FMGR_HYPERLINK_GET_INFO,    /* return information of each hyperlink item */
    FMGR_HYPERLINK_PREPARE      /* preare information */
    
} fmgr_hyperlink_action_enum;

/* FMGR Error code, it is extend from FS Error code */
typedef enum
{
    MMI_FMGR_ERROR_OK = 0,  

    /* FS   error if < 0 */

    /* FMGR error if < FS_MINIMUM_ERROR_CODE */
    MMO_FMGR_ERROR_START = FS_MINIMUM_ERROR_CODE,

    MMI_FMGR_ERROR_LOADING,         /* Folder loading(Sort) still processing, can not display file list */
    MMI_FMGR_ERROR_INDEX_INVALID,   /* Folder has been changed (file list is dirty), re-loading is required */
    MMI_FMGR_ERROR_NO_SLOT,         /* No more slot to create file list */
    MMI_FMGR_ERROR_INVALID_PARAM,   /* Invalid parameter */

    MMI_FMGR_ERROR_MAX
    
} mmi_fmgr_error_enum;


/****************************************************************************/

/* Used by mmi_fmgr_select_path() for FMGR to callback when user select a drive 
 * or cancel the selection 
 */
typedef void (*mmi_fmgr_select_drv_callback)(S8 drv);

/* If a APP want to receive notify from FMGR, it should provide this callback handler
 */
typedef BOOL (*mmi_fmgr_notify_callback)(U32 notify_flag, void* para1);

/* If a APP want to display hyperlink, it should provide this callback handler
 */
typedef MMI_BOOL (*mmi_fmgr_hyperlink_callback)(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);

//#endif

/****************************************************************************/
/* Error code mapping to Error string structure
 * This is exported for RightsManager only
 */
typedef struct
{
    S32 errorNo;            /* error code */
    MMI_ID_TYPE stringId;   /* error string id */
} mmi_fmgr_fs_error_info_struct;

/* Error code mapping to Error string structure
 * This is exported for RightsManager only
 */
typedef mmi_fmgr_fs_error_info_struct FsErrorEntryStruct;

/****************************************************************************/

//#if defined (__MMI_FILE_MANAGER__)

/****************************************************************************/

/* This struct store all data related to a file or folder */
typedef struct
{
    S8 file_name[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH]; /* name */
    S8 file_ext[(SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) *ENCODING_LENGTH]; /* extension */
    FMGR_FILTER file_type; /* type */
    U32 file_size; /* size */
    U16 index; /* index, obsolete */
    MYTIME time; /* creation date */
    U8 attribute; /* attribute, refer to FS_ATTR_XXX */

    /* should be removed, no longer exists now */
    MMI_BOOL is_short;
    U8 flag;
    /* should be removed, no longer exists now */
} FMGR_FILE_INFO_STRUCT;

/****************************************************************************/

/* Used by mmi_fmgr_browse_path() for APP to provide own setting 
 *  For empty case, FMGR provide 3 kind of setting
 *  1. option for empty list    :   empty_opt_menu_id
 *  2. APP handle LSK itself    :   empty_lsk_string_id && empty_lsk_hdlr
 *  3. No LSK                   :   3 empty field are all zero.
 */
typedef struct {
    
    U8  display_type;           /* assign display style, refer to fmgr_display_type_enum */
    U16 option_menu_id;         /* option menu to display when user press LSK on any file */
    
    U16 empty_opt_menu_id;      /* option menu to display when user press LSK on empty list */
    U16 empty_lsk_string_id;    /* change LSK display on empty list */
    FuncPtr empty_lsk_hdlr;     /* LSK hanlder on empty list */

    FuncPtr entry_callback;     /* called every time entry browse file list screen */
    FuncPtr quit_callback;      /* called when quit browse screen (not exit screen), APP can do 
                                   cleanup here. */

#ifdef __MMI_FTE_SUPPORT__
    U16 tb_btn_count;
    U16 tb_btn_menus[3];
    gui_icon_bar_item_resource_struct tb_btn_res[3];
#endif
    
} mmi_fmgr_browse_setting_struct;

/****************************************************************************/

/* Info that a hyperlink item should provide */
typedef struct {
    U16     small_icon_id;  /* small icon */
    U16     large_icon_id;  /* large icon */
    S8*     string_ptr;     /* item text string */
    S8*     sub_string_ptr; /* item text sub-string */
    U16     lsk_string_id;  /* LSK string when user highlights this hyperlink */
    FuncPtr lsk_handler;    /* LSK handler when user selects this hyperlink */

} mmi_fmgr_hyperlink_info_struct;

//#endif

/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_init
 * DESCRIPTION
 *  Init FMGR and FMGR sub module, including: instance, fsdata, main, 
 *  service, service_hdlr, option module.
 *  This is called by InitializeAll()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_init_mmi
 * DESCRIPTION
 *  Init FMGR MMI related context
 *  This is called by InitAllApplications()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_init_mmi(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_init_drive
 * DESCRIPTION
 *  initialize drive list, this API will also be called when enter/leave 
 *  mass storage mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_init_drive(void);

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
#if defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_multi_print_done
 * DESCRIPTION
 *  Called by PictBrdige to end multi print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_multi_print_done(void);
#endif
#endif /* #ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

#if defined (__MMI_FILE_MANAGER__)

/* --------------------------------------------------------- Main API -*/
/*  launch FileMgr App, called by MainMenu / Idle / Shortcut
 */
 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_launch
 * DESCRIPTION
 *  launch FMGR application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_launch_ex
 * DESCRIPTION
 *  launch FMGR application, My files style
 * PARAMETERS
 *  app_id      : [IN] application id, currently only APP_MYFAVORITE can use this API
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_launch_ex(U16 app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_app_mem_stop_callback
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_app_mem_stop_callback(void);

/* --------------------------------------------------------- Service API -*/
/* DOM-NOT_FOR_SDK-BEGIN */
#define mmi_fmgr_sel_drv_and_enter      mmi_fmgr_select_drive
#define mmi_fmgr_select_path_and_enter  mmi_fmgr_select_path
#define fmgr_reset_app_select           mmi_fmgr_close_select_path
/* DOM-NOT_FOR_SDK-END */

/*  Select Drive
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_select_drive
 * DESCRIPTION
 *  A service let user select a drive.
 *  If user choose a drive, FMGR will callback with drive letter
 *  If user cancel the select, FMGR will callback with drive letter = 0
 * PARAMETERS
 *  app_id      : [IN] application id, used to display correct title icon
 *  callback    : [IN] callback to indicate user selection
 *  default_highlight_storage : [IN] default drive letter to highlight on
 * RETURN VALUES
 *  0       :   fail to create screen
 *  != 0    :   instance unique id, can be used in mmi_fmgr_close_service()
 *****************************************************************************/
extern U32  mmi_fmgr_select_drive(U16 app_id, 
                                  mmi_fmgr_select_drv_callback callback, 
                                  S8 default_highlight_storage);
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_select_drive
 * DESCRIPTION
 *  A service let user select a drive.
 *  If user choose a drive, FMGR will callback with drive letter
 *  If user cancel the select, FMGR will callback with drive letter = 0
 * PARAMETERS
 *  icon_id     : [IN] title icon
 *  callback    : [IN] callback to indicate user selection
 *  default_highlight_storage : [IN] default drive letter to highlight on
 * RETURN VALUES
 *  0       :   fail to create screen
 *  != 0    :   instance unique id, can be used in mmi_fmgr_close_service()
 *****************************************************************************/
extern U32  mmi_fmgr_select_drive2(U16 icon_id, 
                                  mmi_fmgr_select_drv_callback callback, 
                                  S8 default_highlight_storage);

/*  Select File / Folder
 */
 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_select_path
 * DESCRIPTION
 *  A service let user to select single file or folder.
 *  If user select a file or folder, FMGR will callback with filepath
 *  If user cancel selection, FMGR will callback with NULL
 * PARAMETERS
 *  app_id      : [IN] application id, used to display title icon
 *  flag        : [IN] select options, refer to fmgr_flag_enum
 *  filter      : [IN] only matched files are available for selection
 *  base_path   : [IN] start folder
 *  callback    : [IN] callback when user do / cancel selection
 * RETURN VALUES
 *  0       :   fail to create screen
 *  != 0    :   instance unique id, can be used in mmi_fmgr_close_service()
 *****************************************************************************/
extern U32  mmi_fmgr_select_path(U16 app_id, 
                                 U32 flag,
                                 FMGR_FILTER filter, 
                                 S8* base_path, 
                                 PsExtFuncPtr callback);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_close_select_path
 * DESCRIPTION
 *  If caller specify FMGR_SELECT_REPEAT in sel_type, select_path is not auto
 *  released after callback. Caller should use this API to remove select_path
 *  service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_close_select_path(void);

/*  Browse Path, 
 *      the setting should be inited using mmi_fmgr_browse_init_setting();
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_browse_init_setting
 * DESCRIPTION
 *  before using mmi_fmgr_browse_path, the setting struct should be inited by
 *  this API
 * PARAMETERS
 *  setting : [IN] setting to be inited
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_browse_init_setting(mmi_fmgr_browse_setting_struct* setting);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_browse_path
 * DESCRIPTION
 *  Browse service let application can focus on file handling, not bothering 
 *  with file list detail.
 * PARAMETERS
 *  app_id      : [IN] application id
 *  flag        : [IN] browse flag, refer to fmgr_flag_enum
 *  filter      : [IN] only matched files are displayed
 *  base_path   : [IN] start folder
 *  setting     : [IN] setting structure
 * RETURN VALUES
 *  0       :   fail to create screen
 *  != 0    :   instance unique id, can be used in mmi_fmgr_close_service()
 *****************************************************************************/
extern U32  mmi_fmgr_browse_path(U16 app_id, 
                                 U32 flag, 
                                 FMGR_FILTER filter, 
                                 S8 *base_path, 
                                 mmi_fmgr_browse_setting_struct* setting);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_browse_change_display_type
 * DESCRIPTION
 *  Used by Application who use mmi_fmgr_browse_path()
 *  change the display type of current instance
 * PARAMETERS
 *  app_id  : [IN] application id
 *  new_type: [IN] new display type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_browse_change_display_type(U16 app_id, fmgr_display_type_enum new_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_browse_change_filepath
 * DESCRIPTION
 *  Used by Application who use mmi_fmgr_browse_path()
 *  change folder to another path
 * PARAMETERS
 *  app_id      : [IN] application id
 *  base_path   : [IN] a new path
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_browse_change_filepath(U16 app_id, S8 *base_path);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_browse_get_current_index
 * DESCRIPTION
 *  Used by Application who use mmi_fmgr_browse_path()
 *  Query current index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern S32  mmi_fmgr_browse_get_current_index(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_browse_set_current_index
 * DESCRIPTION
 *  Used by Application who use mmi_fmgr_browse_path()
 *  Set current index
 * PARAMETERS
 *  index   : [IN] new index
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_browse_set_current_index(S32 index);

#ifdef __MMI_DOWNLOAD_AGENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_receive_da_file
 * DESCRIPTION
 *  Entry for DLAgent, display a option screen for this downloaded file
 * PARAMETERS
 *  session_id
 *  mime_type
 *  mime_subtype
 *  action
 *  file_path   : [IN] path of downloaded file
 *  url
 *  mime_type_string
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_receive_da_file(S32 session_id, 
                                     S32 mime_type, 
                                     S32 mime_subtype, 
                                     S32 action, 
                                     U16 *file_path, 
                                     S8  *url, 
                                     S8  *mime_type_string);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_da_get_option
 * DESCRIPTION
 *  check if a file has available option or not
 * PARAMETERS
 *  filepath    : [IN] path
 * RETURN VALUES
 *  < 0 : FS error
 *  = 0 : Ok, but no avaiable option
 *  > 0 : Ok, and there is available option, return option menu id
 *****************************************************************************/
extern S32 mmi_fmgr_da_get_option(S8* filepath);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_close_da_file
 * DESCRIPTION
 *  close FMGR DLAgent instance
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_close_da_file(void);
#endif

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_close_service
 * DESCRIPTION
 *  Every FMGR service has a unique id, caller can use this API and ID to do
 *  clean up
 * PARAMETERS
 *  fmgr_id : [IN] unique id
 * RETURN VALUES
 *  TRUE    : service is closed
 *  FALSE   : service not found
 *****************************************************************************/
extern BOOL mmi_fmgr_close_service(U32 fmgr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_current_fileinfo
 * DESCRIPTION
 *  Due to our Framework limitation, application handler can not retrieve 
 *  information of current file. This API is to help application handler can
 *  get this info.
 *  Information of current file will be setuped before FMGR callback App handler,
 *  and be cleared after the callback return.
 * 
 *  During FileMgr callback, such as:
 *      1. Select path callback
 *      2. Browse option menu handler
 *      3. Menu enbaler callback
 *  Call this API can obtain information of current file.
 *  At other scenario, this API return NULL
 * PARAMETERS
 *  info    : [OUT] info of current file
 *  app_id  : [OUT] app_id of current application
 * RETURNS
 *  S8*, path of current file
 *****************************************************************************/
extern S8*  mmi_fmgr_get_current_fileinfo(FMGR_FILE_INFO_STRUCT* info, U16* app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_info_by_path
 * DESCRIPTION
 *  Query detail information of a file.
 *  [Note] this operation require a FS_Open, it may take a long while under 
 *         extreme condition
 * PARAMETERS
 *  filepath    : [IN]  path of file
 *  info        : [OUT] return detail info
 * RETURNS
 *  S32     < 0 means FS error
 *          = 0 means success
 *****************************************************************************/
extern S32  mmi_fmgr_get_file_info_by_path(S8* filepath, FMGR_FILE_INFO_STRUCT *info);


/* --------------------------------------------------------- Option API -*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_reset_menu_set
 * DESCRIPTION
 *  A tool API to unhide all child menu of given parent menu.
 * PARAMETERS
 *  parent_menu_id     : [IN]  the parent menu id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_reset_menu_set(U16 parent_menu_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_close_option_screen
 * DESCRIPTION
 *  This is for other application to close option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_close_option_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_app_title_info
 * DESCRIPTION
 *  Query title icon / string id by application id
 * PARAMETERS
 *  app_id      : [IN] application id
 *  title_id    : [OUT] title string id
 *  icon_id     : [OUT] title icon id
 *  path        : [IN] path, optinal, some application will have different 
 *                     icon/string depend on current path (Ex. My Favorite)
 *                     These APPs should provide their checking API to FMGR.
 * RETURNS
 *  BOOL        : TRUE if info found
 *****************************************************************************/
extern MMI_BOOL mmi_fmgr_get_app_title_info(U16 app_id, U16* title_id, U16* icon_id, S8* path);

#endif /* __MMI_FILE_MANAGER__ */


/* --------------------------------------------------------- Utility API -*/
/*  obsolete API
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_file_limit_check
 * DESCRIPTION
 *  util function for some api to check file's limit
 *  to gather all api's file decode limit here
 * PARAMETERS
 *  array_ptr   : [IN] Array pointer
 *  filename    : [IN] Filename
 *  error_str_pp : [OUT] Error string pointer's ptr
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_fmgr_util_file_limit_check(S32 type, CHAR *filename, CHAR **error_str_pp);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_file_limit_check2
 * DESCRIPTION
 *  util function for some api to check file's limit
 *  to gather all api's file decode limit here
 * PARAMETERS
 *  array_ptr   : [IN] Array pointer
 *  filename    : [IN] Filename
 *  errorno_p   : [OUT] Error code, may be FS / GDI / MDI error
 * RETURNS
 *  0 means the check success, others means the check fail, 
 *  error string id is returned.
 *****************************************************************************/
extern U16 mmi_fmgr_util_file_limit_check2(S32 type, CHAR *filename, S32 *errorno_p);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_file_limit_check3
 * DESCRIPTION
 *  util function for some api to check file's limit
 *  to gather all api's file decode limit here
 * PARAMETERS
 *  array_ptr   : [IN] Array pointer
 *  filename    : [IN] Filename
 *  errorno_p   : [OUT] Error code, may be FS / GDI / MDI error
 *  res_group_type : [IN] group type of the passed in file
 * RETURNS
 *  0 means the check success, others means the check fail, 
 *  error string id is returned.
 *****************************************************************************/
extern U16 mmi_fmgr_util_file_limit_check3(S32 type, CHAR *filename, S32 *errorno_p, U16 res_group_type);

#ifdef __FS_CARD2_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_hide_menuid_for_2nd_card
 * DESCRIPTION
 *  hide specific menu id in 2nd memory card scope.
 * PARAMETERS
 *  option_menu_id         : [IN] menu id
 *  path                   : [IN] parent path
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fmgr_util_hide_menuid_for_2nd_card(U16 option_menu_id, const S8* path);
#endif

#if !defined(FMT_NOT_PRESENT)
/* --------------------------------------------------------- General FMT API -*/

/* DOM-NOT_FOR_SDK-BEGIN */
extern S32 mmi_fmgr_util_send_checkdrive_req(U8 this_api_is_obsolete_please_do_not_use_it);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_send_format_req
 * DESCRIPTION
 *  send a drive format request
 * PARAMETERS
 *  drive_letter : [IN] drive letter to be format
 *  level       : [IN] format level, can be FS_FORMAT_HIGH or FS_FORMAT_LOW, see FS documents
 *  callback    : [IN] callback when job is done
 * RETURNS
 *  if < 0, request is not sent due to there is error, callback will not be trigger.
 *  if = 0, request sent, callback will be trigger later with the final result 
 *****************************************************************************/
extern S32 mmi_fmgr_util_send_format_req(U8 drive_letter, U32 level, PsFuncPtr callback);

#endif

/* DOM-NOT_FOR_SDK-BEGIN */

#if defined (__MMI_FILE_MANAGER__) && defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__)

#define MMI_FMGR_MULTI_SEL_NON_SENDABLE 0x01

typedef struct _mmi_fmgr_multi_sel_item_struct
{
    const S8* filepath;
    S8  send_protected;
} mmi_fmgr_multi_sel_item_struct;

extern S32  mmi_fmgr_multi_sel_lock_curr(U32 fmgr_id, mmi_fmgr_multi_sel_item_struct* item);
extern void mmi_fmgr_multi_sel_unlock_curr(U32 fmgr_id, mmi_fmgr_multi_sel_item_struct* item);

extern void mmi_fmgr_multi_sel_unmark_curr(U32 fmgr_id);

extern void mmi_fmgr_multi_sel_process_next(U32 fmgr_id);
extern void mmi_fmgr_multi_sel_filter(U32 fmgr_id, U8 flag);
extern U32  mmi_fmgr_multi_sel_get_remain_count(U32 fmgr_id);

#endif

/* DOM-NOT_FOR_SDK-END */

/* --------------------------------------------------------- move to APP API -*/

#endif /* _FMGR_GPROT_H_ */


