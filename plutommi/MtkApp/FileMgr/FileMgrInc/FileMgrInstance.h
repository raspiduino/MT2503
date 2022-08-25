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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#if defined (__MMI_FILE_MANAGER__)

#ifndef _FMGR_INSTANCE_H_
#define _FMGR_INSTANCE_H_

#ifndef _FMGR_PROT_H_
#error "include FileMgrProt.h first"
#endif

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
//#include "FileMgrProt.h"
#include "FileMgrProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FileMgrGProt.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
/****************************************************************************
* Define
*****************************************************************************/

/********************************* Setting **********************************/


/********************************** Macro **********************************/

#define FMGRI_INSTANCE_INDEX_NOT_CHANGE     -1
#define FMGRI_INSTANCE_INDEX_TO_FIRST_POS   -2

/********************************** Enum  **********************************/

typedef enum
{
    FMGRI_KEY_EVENT_BEGIN = 0x10000,
    FMGRI_EVENT_LSK, 
    FMGRI_EVENT_RSK, 
    FMGRI_EVENT_LEFT_ARROW, 
    FMGRI_EVENT_RIGHT_ARROW, 
    
    FMGRI_EVENT_TOUCH_CLICK, 
    FMGRI_EVENT_CSK, 
    FMGRI_EVENT_DEF_CMD, 
    FMGRI_EVENT_SEND_KEY, 

    FMGRI_KEY_EVENT_NUM
    
} mmi_fmgri_instance_key_event_enum;

/* check if instance need register following keys */
typedef enum
{
    MMI_FMGRI_KEY_NONE,
    MMI_FMGRI_KEY_ARROW         = 0x01,
    MMI_FMGRI_KEY_LSK           = 0x02,
    MMI_FMGRI_KEY_RSK           = 0x04,
    
    MMI_FMGRI_KEY_CSK           = 0x10,
    MMI_FMGRI_KEY_TOUCH         = 0x20,
    MMI_FMGRI_KEY_SEND          = 0x40,

    MMI_FMGRI_KEY_ALL           = 0x0F, /* by default, no CSK & touch & Send */

    MMI_FMGRI_KEY_MAX

} mmi_fmgri_key_binding_flag;

typedef enum
{
    FMGRI_NOTIFY_EVENT_BEGIN = 0x20000,

    FMGRI_EVENT_SCREEN_DELETING,    /* (1) Notify the instance being deleted. */
    FMGRI_EVENT_SCREEN_ENTRY,       /* (1) Notify the active instance. */
    FMGRI_EVENT_SCREEN_EXIT,        /* (1) Notify the active instance. */
    FMGRI_EVENT_INSTANCE_CREATING,  /* (N) Notify all current instances that a new instance is being created. */
    FMGRI_EVENT_DRIVE_UNMOUNT,      /* (N) Notify all current instances that card is plugged-out or unmount. */
    FMGRI_EVENT_DRIVE_MOUNT,      /* (N) Notify all current instances that card is plugged-in or mount. */
    FMGRI_EVENT_APP_NOTIFY,         /* (N) Notify all current instance about mmi_fmgr_notify_event_flag */

    FMGRI_NOTIFY_EVENT_NUM
    
} mmi_fmgri_instance_notify_event_enum;

typedef enum
{
    FMGRI_CMD_BEGIN = 0x40000,

    FMGRI_CMD_GET_MARK_STATE,
    FMGRI_CMD_TOGGLE_MARK_STATE,
    FMGRI_CMD_GET_EMPTY_STR,
    FMGRI_CMD_EXECUTE_MENU,         /* para = (mmi_fmgri_key_binding_flag << 16) | (menu_id) */

    FMGRI_CMD_NUM
    
} mmi_fmgri_instance_command_enum;

typedef enum
{
    FMGRI_DIRTY_CHANGE_INDEX            = 0x01,
    FMGRI_DIRTY_RESET_TO_FIRST_INDEX    = 0x02,    /* reset index to zero or first non-hyperlink item */

    FMGRI_DIRTY_ALL = 0xFF
} mmi_fmgri_dirty_enum;

/********************************* Typedef ********************************/

/* Instance type callback table */
typedef mmi_ret (*mmi_fmgri_instance_key_event_funcptr_type)(mmi_fmgr_instance_struct *instance, S32 event_type);
typedef void (*mmi_fmgri_instance_notify_event_funcptr_type)(mmi_fmgr_instance_struct *instance, S32 event_type, U32 data);
typedef void (*mmi_fmgri_instance_highlight_funcptr_type)(mmi_fmgr_instance_struct *instance, S32 idx);
typedef MMI_BOOL (*mmi_fmgri_instance_error_funcptr_type)(mmi_fmgr_instance_struct *instance, S32 error);
typedef S32  (*mmi_fmgri_instance_cust_cmd_funcptr_type)(mmi_fmgr_instance_struct *instance, S32 cmd, S32 para, void* data);
typedef MMI_BOOL (*mmi_fmgri_instance_hyperlink_funcptr_type)(mmi_fmgr_instance_struct *instance, fmgr_hyperlink_action_enum action, S32 para, S32* result);
typedef mmi_ret (*mmi_fmgri_instance_proc_funcptr_type)(mmi_fmgr_instance_struct *instance, mmi_event_struct *param);

typedef struct
{
    mmi_fmgri_instance_key_event_funcptr_type       key_event_cb;
    mmi_fmgri_instance_notify_event_funcptr_type    notify_event_cb;
    mmi_fmgri_instance_highlight_funcptr_type       highlight_cb;
    mmi_fmgri_instance_error_funcptr_type           error_cb;
#ifdef __FMGR_HYPERLINK_SUPPORT__
    mmi_fmgri_instance_hyperlink_funcptr_type       hyperlink_cb;
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
    mmi_fmgri_instance_cust_cmd_funcptr_type        cust_cmd_cb;
    mmi_fmgri_instance_proc_funcptr_type            event_proc_cb;
} mmi_fmgri_instance_callback_table_struct;

/* Used by FMGRI_EVENT_INSTANCE_CREATING */
typedef struct
{
    mmi_id owner;
    mmi_fmgri_type_enum type;
} mmi_fmgri_instance_notify_creation_struct;

/* Used by FMGRI_EVENT_APP_NOTIFY */
typedef struct
{
    U32 notify_flag; /* srv_fmgr_notification_event_enum */
    void* notify_data;
} mmi_fmgri_instance_notify_app_info_struct;

/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/

/****************************************************************************/
/* instance init, called by fmgr_init()
 */
extern void mmi_fmgri_instance_init(void);


/****************************************************************************/
/* instance create/release function, called by Main/Service
 */
extern mmi_fmgr_instance_struct* mmi_fmgri_instance_create(mmi_id owner, mmi_fmgri_type_enum type);
extern mmi_fmgr_instance_struct* mmi_fmgri_instance_create_ex(mmi_id owner, mmi_fmgri_type_enum type);    /* no re-entry notify */
extern void mmi_fmgri_instance_release(mmi_fmgr_instance_struct* instance);
#if defined(__DRM_V02__) || defined __MMI_FMGR_MULTI_SELECT_SUPPORT__
extern U32 mmi_fmgri_instance_get_export_id(mmi_fmgr_instance_struct* instance);
extern mmi_fmgr_instance_struct* mmi_fmgri_instance_get_instance_by_export_id(U32 exported_id);
#endif
extern mmi_ret mmi_fmgr_notify_hdlr(mmi_event_struct *param);
extern MMI_BOOL mmi_fmgri_instance_notify_all(mmi_fmgri_instance_notify_event_enum event, U32 data);
extern MMI_BOOL mmi_fmgri_instance_execute_command(U8 instance_id, S32 cmd, S32 para, void* data);

/****************************************************************************/
/* get current instance, called by Main/Service
 */
extern mmi_fmgr_instance_struct* mmi_fmgri_get_active_instance(void);  // Through ActiveScreenId to know instance id, and retrieve instance

extern mmi_fmgr_instance_struct* mmi_fmgri_get_instance_by_id(U8 instance_id); 

extern MMI_BOOL mmi_fmgri_is_instance_id_valid(U8 instance_id);

extern MMI_BOOL mmi_fmgri_is_screen_id_valid(U16 screen_id);

/****************************************************************************/
/* instance APIs, called by GUI/FSData
 */

extern U8   mmi_fmgri_get_active_instance_id(void);

extern void mmi_fmgri_instance_get_filepath_and_filter(U8 instance_id, S8 **filepath_pp, FMGR_FILTER *filter_p);

extern S32  mmi_fmgri_instance_get_cur_index(U8 instance_id);

extern BOOL mmi_fmgri_instance_get_title_info(U8 instance_id, U16* string_id, U16* icon_id);

extern U16  mmi_fmgri_instance_get_list_style(U8 instance_id);

extern U16  mmi_fmgri_instance_get_screen_id(U8 instance_id);
    
extern U8   mmi_fmgri_instance_get_arrow_type(U8 instance_id);

#ifdef __FMGR_HYPERLINK_SUPPORT__
extern S32  mmi_fmgri_instance_get_hyperlink_count(U8 instance_id);

extern MMI_BOOL mmi_fmgri_instance_get_hyperlink_info(U8 instance_id, S32 index, mmi_fmgr_hyperlink_info_struct* info);

extern void mmi_fmgri_instance_prepare_hyperlink(U8 instance_id);
#endif

extern S32 mmi_fmgri_instance_get_display_str(U8 instance_id, S8 *display_str_buff, S32 buff_len);

extern MMI_BOOL mmi_fmgri_instance_accept_empty_folder(void);

/****************************************************************************/
/* general explorer function, called by Main/Service
 */
extern void mmi_fmgri_instance_general_entry_explorer(mmi_fmgr_instance_struct* instance, S8* default_highlight_filename);

extern void mmi_fmgri_instance_general_entry_explorer_dummy(mmi_fmgr_instance_struct* instance);

extern void mmi_fmgri_instance_general_refresh(mmi_fmgr_instance_struct* instance);

extern void mmi_fmgri_instance_general_refresh_by_id(U8 instance_id, S32 index);

extern MMI_BOOL mmi_fmgri_instance_general_enter_folder(mmi_fmgr_instance_struct* instance);

extern MMI_BOOL mmi_fmgri_instance_general_leave_folder(mmi_fmgr_instance_struct* instance);

extern void mmi_fmgri_instance_general_update_path(mmi_fmgr_instance_struct* instance, const S8* new_path);

extern void mmi_fmgri_instance_general_back_to_root(mmi_fmgr_instance_struct* instance);

extern void mmi_fmgri_instance_general_reset_index(mmi_fmgr_instance_struct* instance);

extern void mmi_fmgri_instance_general_set_search_filename(mmi_fmgr_instance_struct* instance, S8* search_name);

/* return >= 0 if handled, < 0 if not */
extern S32 mmi_fmgri_instance_general_option_handler(U16 opt_menu_id, U16 menu_id, U32 data, U16 keyCode);

extern void mmi_fmgri_instance_general_close(mmi_fmgr_instance_struct* instance);

extern void mmi_fmgri_instance_general_close_by_id(U8 instance_id);

extern MMI_BOOL mmi_fmgri_instance_display_popup(mmi_fmgr_instance_struct* instance, U16 string_id, mmi_event_notify_enum popup_type, U16 parent_id, MMI_BOOL is_pop_with_cb, S32 line);

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
extern MMI_BOOL mmi_fmgri_instance_display_popup_str(mmi_fmgr_instance_struct* instance, S8* string_ptr, mmi_event_notify_enum popup_type, S32 line);
#endif
extern void mmi_fmgri_instance_post_event(mmi_fmgr_instance_struct* instance, mmi_event_struct* event);

/****************************************************************************/
/* general root function
 */
#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
extern S32  mmi_fmgri_instance_cr_get_count(U8 instance_id, U32 drv_mask);

extern S32  mmi_fmgri_instance_cr_get_info(U8 instance_id, U32 drv_mask, 
                                           S32 index, fmgr_drive_info_struct* info);
#ifdef FMGR_TAB_SUPPORT
extern S32  mmi_fmgri_instance_cr_tab_get_index(U8 instance_id);
#endif

#endif

#endif /* _FMGR_INSTANCE_H_ */
#endif /* #if defined (__MMI_FILE_MANAGER__) */
