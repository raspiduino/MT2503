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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
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
 
 
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef DOWNLOAD_AGENT_APP_SCR_H
#define DOWNLOAD_AGENT_APP_SCR_H
#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)
#include "DLAgentSrvProt.h"
#include "InlineCuiGprot.h"
#include "wgui_touch_screen.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "ExtDeviceDefs.h"
#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
#include "USBSrvGProt.h"
#endif 
#include "IdleGprot.h"
/****************************************************************************
 * [Choice screen API]
 *
 * Provide choice screens that support multiple instances.
 ****************************************************************************/

typedef struct
{
    applib_mime_subtype_enum mime_subtype;
    UI_string_ID_type string_id;
} mmi_da_mime_type_str_struct;
typedef struct
{
    MMI_BOOL is_enabled;
    U16 enabled_img_id;
    U16 disabled_img_id;
    U16 prompt_str_id;
    void (*handler)(srv_da_job_struct *job);
} mmi_da_toolbar_config_struct;

typedef enum
{
    MMI_DA_LAUNCH_FROM_BROWSER,
	MMI_DA_LAUNCH_FROM_IDLE,
    MMI_DA_APP_LAUNCH_END 
} mmi_da_app_launch_enum;

typedef void (*mmi_da_job_get_toolbar_config_func)(
    const srv_da_job_struct *job,
    mmi_da_toolbar_config_struct *config);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_ICON_BAR_SUPPORT__)
extern void mmi_da_toolbar_get_details_config(const srv_da_job_struct *job, mmi_da_toolbar_config_struct *config);
extern void mmi_da_toolbar_get_play_use_config(const srv_da_job_struct *job, mmi_da_toolbar_config_struct *config);
#ifdef __MMI_DA_RESUME__
extern void mmi_da_toolbar_get_suspend_resume_config(const srv_da_job_struct *job, mmi_da_toolbar_config_struct *config);
#endif
extern void mmi_da_toolbar_get_cancel_remove_config(const srv_da_job_struct *job, mmi_da_toolbar_config_struct *config);
static const mmi_da_job_get_toolbar_config_func mmi_da_toolbar_config[] =
{
    mmi_da_toolbar_get_details_config,
    mmi_da_toolbar_get_play_use_config,
#ifdef __MMI_DA_RESUME__
    mmi_da_toolbar_get_suspend_resume_config,
#endif
    mmi_da_toolbar_get_cancel_remove_config
};

#define MMI_DA_TOOLBAR_MAX_ITEM_NUM \
    (sizeof(mmi_da_toolbar_config) / sizeof(mmi_da_toolbar_config[0]))
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) */
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern void mmi_da_app_job_on_details_selected(srv_da_job_struct *job);
extern void mmi_da_job_on_remove_selected(srv_da_job_struct *job);
extern void mmi_da_job_on_cancel_selected(srv_da_job_struct *job);
extern void mmi_da_job_on_resume_selected(srv_da_job_struct *job);
extern void mmi_da_job_on_suspend_selected(srv_da_job_struct *job);
extern void mmi_da_job_on_use_file_selected(srv_da_job_struct *job);
extern void mmi_da_job_on_play_selected(srv_da_job_struct *job);
#endif


#define CHOICE_API


/****************************************************************************
 * Constances
 *****************************************************************************/

#define MMI_DA_AUTH_LEN_USERNAME 31
#define MMI_DA_AUTH_LEN_PASSWORD 31

/*
 * Max number of instances of choice screens.
 * To increase this value, we also have to register new screen IDs and
 * add it to mmi_da_scr_choice_init().
 */
#define MMI_DA_MAX_CHOICE_SCREEN_NUM 4

typedef struct mmi_da_scr_choice_context_struct_s
{
    U16 screen_id;
    U16 title_string_id;
    U16 title_icon_id;
    U16 lsk_string_id;
    U16 rsk_string_id;
    MMI_BOOL show_cancel_ask;
    void *arg;
    void (*fill_msg_string)(void *arg, U16 *buffer, U32 buffer_len);
    void (*lsk_hdlr)(void *arg, U16 *filepath);
    void (*rsk_hdlr)(void *arg);
#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
	void (*csk_hdlr)(void *arg);
    U32  group_id;
    U32  menu_gid;
#endif
    void (*delete_hdlr)(void *arg);

    struct mmi_da_scr_choice_context_struct_s *next;
} mmi_da_scr_choice_screen_struct;

typedef enum
{
    MMI_DA_CONFIRM_SCREEN_GROUP = DOWNLOAD_BASE,
    MMI_DA_BRW_ENTRY_SCREEN_GROUP,
    MMI_DA_STORAGE_SELECTOR_GROUP,
    MMI_DA_DOWNLOAD_LIST_GROUP,
    MMI_DA_DOWNLOAD_LIST_OPTIONS_CUI,
    MMI_DA_PUSH_ENTRY_SCREEN_GROUP,
    MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP
} mmi_da_screen_group_id_enum;

typedef struct {
    mmi_da_scr_choice_screen_struct *top_screen;
    U16 free_screen_ids[MMI_DA_MAX_CHOICE_SCREEN_NUM];
} mmi_da_scr_choice_context_struct;
extern void mmi_da_job_set_toolbar(const srv_da_job_struct *job); //TODO 
extern void mmi_da_job_do_popup(void* arg, S32 screen_id); //TODO
  //TO DO
extern void mmi_da_app_show_popup_ext(UI_string_ID_type str, srv_da_popup_type_enum type);
//TO DO
extern UI_string_ID_type mmi_da_app_map_string(U32 string_id, S32 cause, srv_da_popup_type_enum type);
extern void mmi_da_app_util_format_time(U16 *buffer, U32 total_secs);
extern srv_da_job_filestamp_enum mmi_da_app_job_check_filestamp (srv_da_job_struct* job, U16 *error_reason_id);

extern void mmi_da_app_popup_for_job(
    srv_da_job_struct *job,
    srv_da_popup_type_enum type,
    U16 *message_str,
    MMI_BOOL free_string_after_popup,
	void *info);
extern void mmi_da_app_show_popup_error_ext(U16 *str, srv_da_popup_type_enum type);
extern void mmi_da_app_show_popup(UI_string_ID_type string_id, S32 cause, srv_da_popup_type_enum type);
extern void mmi_da_app_popup_error_for_job(srv_da_job_struct *job, srv_da_popup_type_enum type, S32 cause, U16 error_str_id, MMI_BOOL terminate_job);
extern void mmi_da_scr_entry_full_screen_popup(void);
extern void mmi_da_scr_full_screen_popup_free_context(void);
extern void mmi_da_app_curr_job_exit_abort_confirm(void);
extern void mmi_da_app_show_full_screen_popup(U16 title_string_id,
    U16 title_icon_id,
    U16 *content,
    MMI_BOOL free_content, /* If MMI_FALSE, content should be permament data */
    U16 tone_id);
extern MMI_BOOL mmi_da_is_app_launched(void);
/****************************************************************************
 * [Select storage API]
 *
 * This API decides drive and filename.
 * If client requires, a select storage and/or a filename editor will be shown to user.
 ****************************************************************************/

#define STORAGE_SELECTION

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef srv_da_acceptance_enum (*mmi_da_scr_storage_callback_type)(
    U32 arg,
    U16* filepath,
    MMI_BOOL canback,
    MMI_BOOL canpopup,
    void *instance);


typedef struct
{
    U16     drv;
    srv_da_storage_enum     storage;
    
    U16     filename[MMI_DA_MAX_FILENAME_INPUT_LEN + 1];
    U16     folder[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 2]; /* Includes tail '\' */
    U16     fileext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    
    U32     filesize;                   /* for checking capacity, 0 if not checking */
    const U16 *original_filepath;         /* if provide original filepath, overwrite will not prompt if match */
    
    MMI_BOOL (*filecheck_func)(const U16* filepath, MMI_BOOL bpopup);

    MMI_BOOL    select_storage;             /* user select storage */
    MMI_BOOL    select_filename;            /* user input filename, if MMI_TRUE will check overwrite */

    MMI_BOOL    skip_exist_check;

} mmi_da_scr_storage_parameter_struct;

typedef struct 
{
    U32 arg;
    srv_da_auth_callback_type  auth_callback;
} mmi_da_show_user_auth_struct;

typedef struct mmi_da_scr_select_storage_context_struct_s
{
    /* choose storage */
    srv_da_storage_parameter_struct param;
    mmi_da_scr_storage_callback_type    callback;
    U32                                 user_data;
    U16                                 filename_buffer[MMI_DA_MAX_FILENAME_INPUT_LEN + 1];
    U16                                 filepath[SRV_FMGR_PATH_MAX_LEN + 1];
	U16                                 folder_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16                                 icon_id;
    MMI_BOOL                            already_called_back;
    srv_da_scr_select_storage_cause_enum cause;

    MMI_ID                              grp_id;
    MMI_ID                              cui_select_drive;
    MMI_ID                              cui_filename_editor;
    
    struct mmi_da_scr_select_storage_context_struct_s *next;
} mmi_da_scr_select_storage_context_struct;

#ifndef MMI_DA_PLUTO_SLIM
extern U16 mmi_da_app_scr_show_choice_screen(srv_da_show_choice_screen_event_struct* para);

extern void mmi_da_app_scr_entry_choice(void);
extern void mmi_da_app_scr_choice_lsk_hdlr(void);
extern void mmi_da_app_scr_choice_callback_rsk_hdlr(mmi_da_scr_choice_screen_struct *cntx);
#endif
extern mmi_da_scr_choice_screen_struct *mmi_da_app_get_top_screen(void);
extern void mmi_da_app_scr_choice_rsk_hdlr(void);
extern MMI_BOOL mmi_da_scr_trigger_when_enter(U16 screen_id, void (*func)(void *arg), void *arg);
extern MMI_BOOL mmi_da_scr_trigger_when_enter_ext(
    U16 screen_id, 
    void (*func)(void *arg),
    void (*delete_callback)(void *arg),
    void *arg);
extern MMI_BOOL mmi_da_is_job_list_option_on_top(void);
extern MMI_BOOL mmi_da_app_is_in_foreground_state(void);
extern MMI_BOOL mmi_da_is_suitable_to_popup_for_job(srv_da_job_struct *job);
extern void mmi_da_scr_trigger_when_enter_entry_dummy(void);
extern U8 mmi_da_scr_trigger_when_enter_delete_dummy(void *unused);
extern void mmi_da_update_need_to_delete_progressing(MMI_BOOL need_delete);
extern void mmi_da_update_need_to_del_choice_screen(MMI_BOOL need_delete);
extern void mmi_da_update_dispatch_confirm_del(MMI_BOOL need_delete);
extern void mmi_da_check_presence_and_close_screen(MMI_ID parent_id, MMI_ID scrn_id);
extern UI_string_ID_type mmi_da_search_mime_type_string(const applib_mime_type_struct * type);
/*****************************************************************************
 * [Authentication screen]
 *
 *
 *****************************************************************************/

#define AUTH_SCR

/****************************************************************************
 * Enum
 ****************************************************************************/

typedef enum
{
    MMI_DA_AUTH_USERNAME_CAPTION = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_DA_AUTH_USERNAME_EDITOR,
    MMI_DA_AUTH_PASSWARD_CAPTION,
    MMI_DA_AUTH_PASSWARD_EDITOR,
    MMI_DA_AUTH_END_OF_ENUM
} mmi_da_auth_enum;


/****************************************************************************
 * Structure
 ****************************************************************************/
typedef void (*mmi_da_scr_auth_callback_type)(U32 criteria, U16*, U16*, MMI_BOOL in_delete);

typedef struct _mmi_da_auth_edit_struct
{
    /* auth */
    MMI_ID grp_id;
    MMI_ID inline_cui_id;
    U16 username[MMI_DA_AUTH_LEN_USERNAME + 1];
    U16 password[MMI_DA_AUTH_LEN_PASSWORD + 1];

    U32                                 user_data;
    mmi_da_scr_auth_callback_type       callback;
    U16                                 icon_id;
    
    /*
     * recognize who close the session, framework or user, 
     * because the different callback action with different case
     */
    MMI_BOOL closed_by_user;
} mmi_da_auth_edit_struct;

/****************************************************************************
 * [Asynchnous move API]
 *
 * Asyncnronous move. It displays a Moving("Please wait") screen while doing move.
 ****************************************************************************/

#define MMI_DA_SCR_ASYNC_MOVE


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct {
    U16 screen_id;
    U16 title_string_id;
    U16 title_icon_id;
    U16 *src_path;
    U16 *dest_path;
    MMI_BOOL cancel_rsk;
    void *arg;
    void (*result_callback)(void *arg, S32 error_code);
    void (*cancel_callback)(void *arg, MMI_BOOL is_deleted);

    MMI_BOOL in_moving;
    MMI_BOOL is_deleted;
    MMI_BOOL cancelled_by_upper_layer;
} mmi_da_scr_async_move_cntx_struct;


/****************************************************************************
 * [Progressing screen API]
 *
 * It shows a progressing screen.
 ****************************************************************************/

#define PROGRESSING_SCREEN

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct mmi_da_scr_progressing_context_struct_s
{
    U16 screen_id;
    U16 title_string_id;
    U16 title_icon_id;
    U16 message_id;
    U16 timer_id;
    MMI_BOOL cancel_rsk;
    void *arg;
    void (*cancel_callback)(void *arg, MMI_BOOL is_deleted);

    struct mmi_da_scr_progressing_context_struct_s *next; /* Lower progressing screens */
} mmi_da_scr_progressing_context_struct;


/****************************************************************************
 * [Full screen API]
 *
 * It shows a popup but full screen.
 ****************************************************************************/

#define FULL_SCREEN_POPUP


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    U16 title_icon_id;
    U16 title_string_id;
    U16 *content;
    MMI_BOOL free_content_when_destroy;
} mmi_da_scr_full_screen_popup_context_struct;
typedef void *mmi_da_scr_menu_handle;

typedef struct
{    
    S32                 job_list_highlight_index;
    MMI_BOOL            job_list_dirty_flag;
    MMI_BOOL            popup_triggered;

    U16                 download_confirm_screen;
    void*               select_storage_instance;

    S32                 job_id_list[10];  /* Remove hardcoding for 10 jobs */

    /* If the user selected No for bearer ask, we do not try to build
       a new connection. Treat this case as the user cancel any following actions. */
    MMI_ID              da_app_scr_group_id;
    mmi_da_scr_menu_handle job_list_option;
} mmi_da_context_struct;

/*****************************************************************************
 * [Trigger-when-enter API]
 *
 * If some event happens during interrupt, it is unsuitable to show screens.
 * This API provides a mechanism to trigger client's procedure after the end of
 * interrupt. This utility can only be used during some screen is in history.
 *****************************************************************************/

#define TRIGGER_WHEN_ENTER


/****************************************************************************
 * Configuration
 ****************************************************************************/

#define MMI_DA_SCR_TRIGGER_WHEN_ENTER_MAX_INSTANCES_NUM 4


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct mmi_da_scr_trigger_when_enter_inst_struct_s
{
    U16 screen_id;
    void (*func)(void *arg);
    void (*delete_callback)(void *arg);
    void *arg;

    struct mmi_da_scr_trigger_when_enter_inst_struct_s *next;
} mmi_da_scr_trigger_when_enter_inst_struct;


typedef struct
{
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;
    U16 free_screen[MMI_DA_SCR_TRIGGER_WHEN_ENTER_MAX_INSTANCES_NUM];
} mmi_da_scr_trigger_when_enter_context_struct;

/*****************************************************************************
 * [Menu CUI adaptor]
 *
 *
 *****************************************************************************/


#define MMI_DA_SCR_MENU_VALID_MAGIC (0x05060708)


#define MMI_DA_SCR_MENU_INVALID_HANDLE NULL

typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_menu_id selected_item;
    mmi_da_scr_menu_handle handle;
    mmi_id ori_evt_id;
    mmi_event_struct *ori_evt;
} mmi_da_scr_menu_evt_struct;

typedef mmi_ret (*mmi_da_scr_menu_proc)(const mmi_da_scr_menu_evt_struct *menu_evt);


typedef struct
{
    U32 valid_magic;

    MMI_ID grp_id;
    MMI_ID cui_instance_id;
    mmi_menu_id menu_id;
    mmi_da_scr_menu_proc client_proc;
    void *user_data;
} mmi_da_scr_menu_struct;
extern S32 mmi_da_get_job_highlight_index(void);
extern void mmi_da_set_job_highlight_index(S32 index);
#ifndef MMI_DA_PLUTO_SLIM
extern S32 mmi_da_app_job_get_display_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif
extern void mmi_da_app_scr_progressing_cancel(void);
extern U8 mmi_da_app_scr_delete_progressing(void *unused);
extern void mmi_da_app_check_and_trigger_popup_on_screen_entry(srv_da_job_struct *job, U16 drawing_screen_id);
extern void mmi_da_app_scr_remove_screen(U16 screen_id);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern void mmi_da_app_close_job_list(void *arg);
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
extern void mmi_da_app_job_list_tap_hdlr(mmi_tap_type_enum tap_type, S32 index);
#endif //__MMI_FTE_SUPPORT__
extern void mmi_da_app_job_list_highlight_hdlr(S32 hiliteidx);
extern void mmi_da_app_job_list_option_hdlr(void);
#ifndef MMI_DA_PLUTO_SLIM
extern S32 mmi_da_app_job_get_display_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif
extern mmi_da_scr_progressing_context_struct *mmi_da_app_get_top_cntx(void);
extern void mmi_da_app_set_top_cntx(mmi_da_scr_progressing_context_struct *cntx);
extern void mmi_da_app_job_display_details(void);
extern void mmi_da_close_job_list_option(void);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static S32 mmi_da_job_get_display_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif
extern U32 mmi_da_app_format_job_detail(const srv_da_job_struct *job, U16* strBuffer, U32 buffer_len, U32 count);
//#ifndef MMI_DA_PLUTO_SLIM
extern void mmi_da_app_http_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len);
extern void mmi_da_app_confirm_mre_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len);
extern void mmi_da_app_push_confirm_fill_msg_string (void *arg, U16 *buffer, U32 buffer_len);
//#endif
#if defined (__MMI_OMA_DD_DOWNLOAD__)
extern void mmi_da_app_oma_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len);
#endif
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
extern void mmi_da_app_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len);
#endif
extern U32 mmi_da_format_job_detail(const srv_da_job_struct *job, U16* strBuffer, U32 buffer_len, U32 count);
extern void mmi_da_update_timer_handler(void* param);
extern srv_da_job_filestamp_enum mmi_da_job_check_file_before_operation(srv_da_job_struct *job);
extern void mmi_da_app_popup_for_job_msg(
    srv_da_job_struct *job,
	U16 *filepath);
extern MMI_ID mmi_da_get_active_scrn_grp(void);
extern void mmi_da_set_active_scrn_grp(MMI_ID grp_id);
extern void mmi_da_launch_app(mmi_da_app_launch_enum launch_type);
extern void mmi_da_app_update_job_list_dirty_flag(MMI_BOOL new_value);
extern MMI_BOOL mmi_da_app_get_job_list_dirty_flag(void);
extern U16 mmi_da_app_map_action_to_scr(U16 action_id);
extern void* mmi_da_app_scr_select_storage(mmi_da_scr_storage_callback_type callback,
    mmi_da_scr_storage_parameter_struct* parameter,
    U32 arg,
    U16 title_icon_id);
extern void mmi_da_entry_job_detail(void);
extern mmi_da_scr_select_storage_context_struct* mmi_da_get_storage_top(void);
#ifndef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern void mmi_da_job_entry_complete(srv_da_job_struct *job);
#endif 
extern srv_da_scr_select_storage_cause_enum mmi_da_scr_select_storage_get_cause(void *instance);
extern void mmi_da_app_close_all_screens(void);
#endif

extern void mmi_da_job_complete(srv_da_job_struct* job);
extern void mmi_da_update_need_to_del_dummy(MMI_BOOL need_delete);
extern MMI_BOOL mmi_da_get_need_to_del_choice_screen(void);
extern U8 mmi_da_app_scr_choice_delete_hdlr(void);
extern MMI_BOOL mmi_da_get_need_to_delete_progressing(void);
extern U16 mmi_da_job_get_title_icon(const srv_da_job_struct *job);
extern void mmi_da_scr_full_screen_popup_ok_hdlr(void);
extern U8 mmi_da_scr_delete_full_screen_popup(void *unused);
extern MMI_BOOL mmi_da_get_dispatch_confirm_del(void);
extern void mmi_da_auth_on_user_submitted(mmi_da_auth_edit_struct *context);
extern void mmi_da_app_scr_remove_screen(U16 screen_id);
extern void mmi_da_scr_trigger_when_enter_free_instance(mmi_da_scr_trigger_when_enter_inst_struct *top_dummy);
extern void mmi_da_app_notify_new_push(void);
extern void mmi_da_display_job_detail(srv_da_job_struct* job);
extern void mmi_da_app_scr_show_progressing(
    U16 screen_id,
    U16 title_string_id,
    U16 title_icon_id,
    U16 message_id,
    MMI_BOOL cancel_rsk, /* Show RSK "Cancel" */
    void *arg,
    void (*cancel_callback)(void *arg, MMI_BOOL is_deleted));
extern MMI_BOOL mmi_da_scr_progressing_close(U16 screen_id);
extern void mmi_da_app_show_popup_with_callback(UI_string_ID_type string_id, mmi_proc_func callback);
extern void mmi_da_scr_user_auth(mmi_da_scr_auth_callback_type callback, U32 user_data, U16 title_icon_id);
extern void mmi_da_handle_job_status_updates(srv_da_job_struct *job);
extern void mmi_da_app_handle_push_process(S32 error_code, srv_da_push_async_move_arg_struct* async_move_arg);
extern void mmi_da_app_scr_remove_screen(U16 screen_id);
extern void mmi_da_app_show_job_detail(void);
extern void mmi_da_curr_job_entry_dispatch_confirm(void);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern void mmi_da_app_async_move(U16 screen_id,
        U16 title_string_id,
        U16 title_icon_id,
        const U16 *src_path,
        const U16 *dest_path,
        MMI_BOOL cancel_rsk,
        void *arg, /* Pass to result_callback */
        void (*result_callback)(void *arg, S32 error_code),
        void (*cancel_callback)(void *arg, MMI_BOOL is_deleted));
#endif
extern mmi_ret mmi_da_show_nmgr_alert(void);
#endif /* DOWNLOAD_AGENT_APP_SCR_H */
