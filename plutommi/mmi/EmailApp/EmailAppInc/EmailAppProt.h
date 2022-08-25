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
 * EmailAppProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local enum, constant and prototypes for Email application
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_EMAILPROT_H_
#define _MMI_EMAILPROT_H_

/*---------------------------------------------------------------------------*/
/* Header files */
/*---------------------------------------------------------------------------*/
#include "MMI_features.h"

#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#endif
#include "cbmsrvgprot.h"
#include "emailsrvgprot.h"
#include "EmailAppCore.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "customer_ps_inc.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/

#define MMI_EMAIL_TOTAL_POOL                            ((MAX_ASYNCDYNAMIC_ITEMS_BUFF + MMI_EMAIL_MAX_MSG_PER_PAGE - 1) / MMI_EMAIL_MAX_MSG_PER_PAGE)
#define MMI_EMAIL_TOTAL_MSG_BUFF                        ((MMI_EMAIL_TOTAL_POOL + 1) * MMI_EMAIL_MAX_MSG_PER_PAGE)
#define MMI_EMAIL_MAX_DISP_ADDR_NUM                     6
#define MMI_EMAIL_BASIC_FOLDER_NUM                      4
#define MMI_EMAIL_MAX_TIME_DISP_LEN                     5 /* 10:30, 12.12, 2010 */

#ifdef __MMI_URI_AGENT__
/* URI related */
#define EMAIL_URI_MAILTO_SCHEME                         "mailto"
#define EMAIL_URI_MAILTO_TO_HEADER                      "to"
#define EMAIL_URI_MAILTO_CC_HEADER                      "cc"
#define EMAIL_URI_MAILTO_FROM_HEADER                    "from"
#define EMAIL_URI_MAILTO_SUB_HEADER                     "subject"
#define EMAIL_URI_MAILTO_BODY_HEADER                    "body"
#define EMAIL_URI_BUFFER_LENGTH                         255
#endif

#define MMI_EMAIL_MAX_TB_NUMBER                         3

#define MMI_EMAIL_MAX_CONT_LEN                          2 * 1024

#define MMI_EMAIL_MAX_DWNL_LEN                          15
#define MMI_EMAIL_MIN_PORT                              1
#define MMI_EMAIL_MAX_PORT                              65535

#define MMI_EMAIL_NUM_TEMPLATES                         10
#define MMI_EMAIL_MAX_TEMPLATE_LENGTH                   40

#define MMI_EMAIL_MAX_SUBJ_LEN                          50
#define MMI_EMAIL_MAX_ATT_DISP_LEN                      30
#define MMI_EMAIL_MAX_ADDR_DISP_LEN                     SRV_EMAIL_MAX_DISP_NAME_LEN + SRV_EMAIL_MAX_ADDR_LEN + 7
#define MMI_EMAIL_IS_DISCONNECT_STATE(state)            ((state == SRV_EMAIL_NWK_DISCONNECTED) ? TRUE : FALSE)
#define MMI_EMAIL_MAX_DETAIL_LEN                        (3 * 1024)

typedef void (*email_save_send_callback)(BOOL result, void *user_data);
typedef void (*mmi_email_switch_storage_callback)(BOOL result);
typedef void (*mmi_email_copy_file_to_view_callback)(WCHAR *new_file_path);

extern const WCHAR g_email_subj_left_op[];
extern const WCHAR g_email_subj_right_op[];
extern const WCHAR g_email_2dots[];
extern const WCHAR g_email_kilobyte[];

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/
typedef enum
{
    MMI_EMAIL_MSG_FIELD_UPDATE_NONE = 0x00,
    MMI_EMAIL_MSG_FIELD_UPDATE_TO = 0x01,
    MMI_EMAIL_MSG_FIELD_UPDATE_CC = 0x02,
    MMI_EMAIL_MSG_FIELD_UPDATE_BCC = 0x04,
    MMI_EMAIL_MSG_FIELD_UPDATE_PRIO = 0x08,
    MMI_EMAIL_MSG_FIELD_UPDATE_SUBJ = 0x10,
    MMI_EMAIL_MSG_FIELD_UPDATE_ATT = 0x20,
    MMI_EMAIL_MSG_FIELD_UPDATE_CONT = 0x40,
    MMI_EMAIL_MSG_FIELD_UPDATE_ALL = 0xff
} mmi_email_msg_field_update_enum;


typedef enum
{
    MMI_EMAIL_MSG_OP_NONE = 0,
    MMI_EMAIL_MSG_OP_NEW,
    MMI_EMAIL_MSG_OP_EDIT,
    MMI_EMAIL_MSG_OP_READ
} mmi_email_msg_operation_enum;


typedef enum
{
    MMI_EMAIL_ACCT_SYNC_NONE = 0x00,
    MMI_EMAIL_ACCT_SYNC_NUM = 0x01,
    MMI_EMAIL_ACCT_SYNC_FLAG = 0x02
} mmi_email_sync_type_enum;


typedef enum
{
    MMI_EMAIL_ACCT_STATE_INIT = 0,
    MMI_EMAIL_ACCT_STATE_CONNECTING,
    MMI_EMAIL_ACCT_STATE_ASK_CONNECT,
    MMI_EMAIL_ACCT_STATE_CONNECTED,
    MMI_EMAIL_ACCT_STATE_AUTH,
    MMI_EMAIL_ACCT_STATE_ASK_AUTH,
    MMI_EMAIL_ACCT_STATE_AUTH_VERIFIED,
    MMI_EMAIL_ACCT_STATE_SYNC,
    MMI_EMAIL_ACCT_STATE_SYNC_DONE
} mmi_email_acct_state_enum;


typedef enum
{
    MMI_EMAIL_ACCT_DISCONNECTED = 0,
    MMI_EMAIL_ACCT_DISCONNECTING,
    MMI_EMAIL_ACCT_CONNECTED,
    MMI_EMAIL_ACCT_CONNECTING
} mmi_email_connect_status_enum;


typedef enum
{
    MMI_EMAIL_NWK_CONNECT = 0,
    MMI_EMAIL_NWK_RECEIVE_NEW,
    MMI_EMAIL_NWK_OPT_TOTAL
} mmi_email_nwk_opt_enum;

typedef enum
{
    EMAIL_PHB_CUI_TYPE_NONE = 0,
    EMAIL_PHB_CUI_COMP_ADDR_TYPE,
    EMAIL_PHB_CUI_SEND_FILE_TYPE,
    EMAIL_PHB_CUI_UE_OPTION_TYPE,
    EMAIL_PHB_CUI_UE_SELECT_TYPE,
	EMAIL_PHB_CUI_ACCT_SELECT_TYPE,
	EMAIL_PHB_CUI_WIZARD_SELECT_TYPE,
    EMAIL_PHB_CUI_READ_SAVE_EMAIL_TYPE,
    EMAIL_PHB_CUI_CONT_SAVE_EMAIL_TYPE,
    EMAIL_PHB_CUI_CONT_SAVE_NUM_TYPE,
    EMAIL_PHB_CUI_TYPE_TOTAL
} mmi_email_phb_cui_type_enum;

typedef enum
{
    EVT_ID_ACCT_SETTING_EXIT = (EMAIL_BASE + 1),
    EVT_ID_EMN_LIST_SCREEN_EXIT,
    EVT_ID_ENTRY_SEND_TO_ADDR_SCREEN,
    EVT_ID_ACCT_SETTING_MAX
} mmi_email_acct_setting_evt_enum;

typedef enum
{
    EMAIL_PRE_COMP_TYPE_NEW = 0,
    EMAIL_PRE_COMP_TYPE_TEMPLATE,
    EMAIL_PRE_COMP_TYPE_EXTRACT,
    EMAIL_PRE_COMP_TYPE_ADDR_SEND,
    EMAIL_PRE_COMP_TYPE_CONTINUE,
    EMAIL_PRE_COMP_TYPE_REPLY,
    EMAIL_PRE_COMP_TYPE_REPLY_ALL,
    EMAIL_PRE_COMP_TYPE_FORWARD,
    EMAIL_PRE_COMP_TYPE_EDIT
} mmi_email_prepare_comp_type_enum;


typedef enum
{
    MMI_EMAIL_SS_SAVE = 0x01,
    MMI_EMAIL_SS_SAVE_NEW = 0x02,
    MMI_EMAIL_SS_SEND = 0x04,
    MMI_EMAIL_SS_MOVE = 0x08,
    MMI_EMAIL_SS_CHANGE = 0x10
} email_app_save_send_opt_enum;


typedef enum
{
    MMI_EMAIL_COMP_SAVE_TO = 0x01,
    MMI_EMAIL_COMP_SAVE_CC = 0x02,
    MMI_EMAIL_COMP_SAVE_BCC = 0x04,
    MMI_EMAIL_COMP_SAVE_SUB = 0x08,
    MMI_EMAIL_COMP_SAVE_CON = 0x10,
    MMI_EMAIL_COMP_SAVE_ATT = 0x20,
    MMI_EMAIL_COMP_SAVE_PRI = 0x40,
    MMI_EMAIL_COMP_SAVE_ALL = 0xff
} email_app_save_part_enum;


/*---------------------------------------------------------------------------*/
/* Struct */
/*---------------------------------------------------------------------------*/

typedef struct
{
    mmi_id acct_select_gid;
    mmi_id acct_main_gid;
    mmi_id folder_main_gid;
    mmi_id more_box_gid;
    mmi_id composer_gid;
    mmi_id reader_gid;
    mmi_id acct_setting_gid;
} mmi_email_main_entry_gid_array_struct;


typedef struct
{
    U32 unread_inbox_count;
    U32 total_inbox_count;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID basic_folder_id[4];
    WCHAR acct_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
    mmi_email_connect_status_enum connect_status;
} mmi_email_account_item_info_struct;

typedef struct 
{
    mmi_id parent_id;
    EMAIL_MSG_ID msg_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_ACCT_ID acct_id;
    BOOL entry_from_folder;
    srv_email_fldr_type_enum folder_type;
} mmi_email_entry_read_struct;


typedef struct 
{
    mmi_id parent_id;
    BOOL is_close_parent;
    BOOL edit_from_outbox;
    EMAIL_MSG_ID msg_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_ACCT_ID acct_id;
    mmi_email_prepare_comp_type_enum type;
} mmi_email_prepare_comp_struct;


typedef struct
{
    EMAIL_MSG_ID msg_id;
    EMAIL_MSG_HANDLE msg_handle;
    S32 msg_update_state;
    S32 msg_operation;
    srv_email_fldr_msg_info_node_struct msg_info;
} mmi_email_msg_info_struct;


typedef struct
{
    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_ACCT_ID acct_id;
    S32 attach_index;
    srv_email_msg_funcptr_type callback;
} mmi_email_retrieve_msg_struct;


typedef struct
{
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_MSG_ID msg_id;
    BOOL is_incoming;
    mmi_id parent_id;
    void *user_data;
    mmi_email_nwk_opt_enum nwk_opt;
    srv_email_acct_funcptr_type connect_callback;
} mmi_email_connect_process_struct;


typedef struct
{
    EMAIL_ACCT_ID acct_id;
    S32 sync_opt;
    srv_email_acct_funcptr_type sync_callback;
} mmi_email_sync_process_struct;


typedef struct
{
    EMAIL_ACCT_ID acct_id;
    S32 connect_state;
    S32 sync_opt;
    srv_email_acct_funcptr_type connect_callback;
    srv_email_acct_funcptr_type sync_callback;
} mmi_email_connect_struct;


typedef struct
{
    BOOL result;
    void *user_data;
    U32 unread_count;
    U32 total_count;
    S32 major_error_code;
    S32 minor_error_code;
    EMAIL_ACCT_ID acct_id;
} mmi_email_connect_result_struct;


typedef struct
{
    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_REQ_ID req_id;
    EMAIL_MSG_ID new_msg_id;
} mmi_email_send_struct;


typedef struct _mmi_email_remote_folder_tree_node_struct
{
    U16 folder_name[30];
    struct _mmi_email_remote_folder_tree_node_struct *parent_node;
    struct _mmi_email_remote_folder_tree_node_struct *next_node;
    struct _mmi_email_remote_folder_tree_node_struct *sub_node;
} mmi_email_remote_folder_tree_node_struct;

typedef struct
{
    BOOL result;
    U32 unread_count;
    U32 total_count;
    S32 error_code;
    EMAIL_ACCT_ID acct_id;
} mmi_email_batch_receive_result_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id grp_id;
    mmi_id cbm_id;
    EMAIL_ACCT_ID dst_acct_id;
    EMAIL_FLDR_ID dst_fldr_id;
    EMAIL_MSG_ID new_msg_id;
    EMAIL_REQ_ID req_id;
    EMAIL_MSG_HANDLE msg_handle;
    U16 str_id;
    U16 img_id;
    U16 curr_opt;
    void *user_data;
    BOOL is_exit;
    srv_cbm_bearer_event_type_enum cbm_type;
    email_app_save_send_opt_enum opt;
    srv_email_msg_save_part_enum save_part;
    email_save_send_callback callback;
} email_app_save_send_proc_struct;


typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER         /* evt_id: event is; user_data: the receiver's user_data */
} mmi_email_acct_setting_evt_struct;


typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER         /* evt_id: event is; user_data: the receiver's user_data */
} mmi_email_entry_send_to_addr_evt_struct;


/*---------------------------------------------------------------------------*/
/* Variables */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Prototypes */
/*---------------------------------------------------------------------------*/

/* get the detailed error string */
extern U16 mmi_email_util_get_err_code(S32 major, S32 minor);

/* display popup screen of error information */
extern void mmi_email_util_display_error_popup(mmi_id grp_id, S32 error_id);

/* display popup screen */
extern void mmi_email_util_display_popup(
                mmi_id grp_id,
                CHAR *string,
                mmi_event_notify_enum event);

/* display popup screen with callback */
extern void mmi_email_util_display_popup_ext(
                mmi_id grp_id,
                mmi_proc_func func,
                WCHAR *string,
                mmi_event_notify_enum event);

/* display confirm screen */
extern void mmi_email_util_display_confirm(
                mmi_id grp_id,
                FuncPtr lsk_func,
                FuncPtr rsk_func,
                mmi_proc_func func,
                BOOL is_map_csk,
                CHAR *string,
                mmi_event_notify_enum event);

/* display confirm screen with interruption handler */
extern void mmi_email_util_display_confirm_ext(
                mmi_id grp_id,
                FuncPtr lsk_func,
                FuncPtr rsk_func,
                FuncPtr interrupt_func,
                mmi_proc_func func,
                BOOL is_map_csk,
                CHAR *string,
                mmi_event_notify_enum event);

/* get the file extension name */
extern WCHAR *mmi_email_get_file_ext(WCHAR *file_name);

/* get the file mime type by extension name */
extern void mmi_email_util_get_mine_type(WCHAR *filename, S32 *mime_type, S32 *mime_subtype);

/* get the file is DRM lock file */
extern BOOL mmi_email_drm_is_file_lock(WCHAR* file_name, BOOL *is_drm_file);

/* get the folder ID according to account ID and index */
extern srv_email_result_enum mmi_email_util_get_fldr_id_by_acct(
                                EMAIL_ACCT_ID acct_id,
                                S32 count,
                                S32 *folder_type,
                                EMAIL_FLDR_ID *fldr_id);

/* get account delete option */
extern srv_email_result_enum mmi_email_get_acct_del_opt(
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_delete_option_enum *del_opt);

/* get the Email main screen group ID */
extern mmi_id mmi_email_get_main_group_id(void);

/* get and save the account array info to APP's structure for screen display */
extern void mmi_email_save_acct_array_info(void);

/* display the account select screen to let user to choose to view */
extern void mmi_email_entry_account_select(void);

/* enter the account main screen */
extern void mmi_email_entry_account_main(mmi_id parent_id, EMAIL_ACCT_ID acct_id);

/* get the folders' info and save the data to structure for screen display */
extern void mmi_email_list_folders_info(void);

/* list folder callback when async */
extern void mmi_email_list_folder_callback(
                EMAIL_ACCT_HANDLE acct_handle,
                void *user_data,
                srv_email_result_enum result);

/* 
 * --enter folder screen--
 * create handle
 * save handle
 * get messages number
 * create memory pool and init
 * prepare to query messages
 * show the folder screen
 */
extern void mmi_email_pre_entry_folder(
                mmi_id parent_id,
                EMAIL_ACCT_ID acct_id,
                EMAIL_FLDR_ID folder_id,
                srv_email_fldr_type_enum folder_type,
                BOOL outside);

/* 
 * --get the memory for message list buffer--
 * alloc the memory for messages storage
 * query messages according to count
 * show loading screen
 */
extern void mmi_email_get_msgs_list_info_buffer(srv_email_fldr_msg_info_struct *list_ptr, S32 count);

/* 
 * --get the mails info according to count and start index--
 * query messages according to count and start index
 * show loading screen
 */
extern void mmi_email_query_msgs_array(EMAIL_FLDR_HANDLE handle, S32 count, S32 start_index);

/*
 * --the callback function of folder asnyc operation--
 */
extern void mmi_email_folder_async_op_callback(
                EMAIL_FLDR_HANDLE fldr_handle,
                void *user_data,
                srv_email_result_enum result);

/* 
 * --the callback of list the mails--
 * save messages info
 * try to update the folder list
 */
extern void mmi_email_get_msgs_list_info_callback(
                EMAIL_FLDR_HANDLE fldr_handle,
                void *user_data,
                srv_email_result_enum result);

/* 
 * --get async item data callback for category use--
 * whether ready to update the list or to query the needed items
 */
extern S32 mmi_email_get_async_folder_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 dataSize);

/* the callback of get the message detailed info */
extern void mmi_email_get_msg_info_callback(
                EMAIL_FLDR_HANDLE fldr_handle,
                void *user_data,
                srv_email_result_enum result);

/* set the structure value to display message details screen */
extern void mmi_email_init_msg_detail_struct(EMAIL_MSG_ID msg_id, EMAIL_FLDR_ID fldr_id, EMAIL_ACCT_ID acct_id, mmi_id grp_id);

/* to show the message details screen */
extern void mmi_email_show_msg_detail(void);

/*
 * reset the read content and release resource
 */
extern void mmi_email_reset_curr_read_info(void);

/* 
 * --state check before entry read screen--
 * create message handle
 * save handle
 * get message state
 * whether to retrieve the message
 */
extern BOOL mmi_email_pre_entry_read(mmi_email_entry_read_struct *read_data);

/*
 * --prepare the message info for reading--
 * get basic info
 * get content info
 * get reply to info
 * get recipients info
 * get sender info
 * get subject info
 * call APP core API to convert data for display
 */
extern void mmi_email_prepare_read_info(mmi_email_msg_info_struct *msg_info);

/*
 * --show the read screen--
 */
extern void mmi_email_entry_read(void);

extern void mmi_email_read_pf_update_info(EMAIL_MSG_HANDLE msg_handle, S32 major, S32 minor, S32 down_size);


/*
 * reset the compose information
 */
extern void mmi_email_reset_curr_comp_info(void);

/*
 * set the data before entry compose screen
 */
extern void mmi_email_prepare_entry_comp(mmi_email_prepare_comp_struct *comp_data);

/*
 * --edit Email--
 */
extern void mmi_email_edit_msg(mmi_email_msg_info_struct *msg_item);


/*
 *
 */
void mmi_email_batch_receive_report(mmi_email_batch_receive_result_struct *result, MMI_BOOL working);

void mmi_email_batch_receive_remove(EMAIL_ACCT_ID acct_id);

/*
 * --entry Inbox by account ID--
 */
extern void mmi_email_entry_acct_inbox(EMAIL_ACCT_ID acct_id);

/*
 * --Check the address validity--
 */
extern BOOL mmi_email_util_chk_addr(WCHAR *mailAddr);
extern BOOL mmi_email_util_is_server_vaild(CHAR *server);
extern BOOL mmi_email_util_is_username_vaild(CHAR *username);
extern S32 mmi_email_util_get_num_len(U32 number);
extern void mmi_email_util_get_default_server(WCHAR *p_email_addr, WCHAR *p_server_buf);
extern void mmi_email_util_get_default_user_name(WCHAR *p_email_addr, WCHAR *p_name_buf);

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern void mmi_email_hs_init_acct_info(void);
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_URI_AGENT__
extern void mmi_email_uri_mailto_handler(
                                         srv_uriagent_appid_enum ura_appid,
                                         char *url,
                                         char *param,
                                         srv_uriagent_options_enum options,
                                         srv_uriagent_uri_request_hdlr_cb cb);
#endif

extern S32 mmi_email_uti_strnicmp(char *first, char *last, S32 length);
extern BOOL mmi_email_util_chk_addr_ex(WCHAR *mailAddr);
extern void mmi_email_pre_entry_template_list(mmi_id parent_id, BOOL is_add_to_comp);
extern WCHAR *mmi_email_get_template_content(void);
extern WCHAR *mmi_email_read_extract_get_sent_addr(void);
extern void mmi_email_request_rights(void);
extern mmi_id mmi_email_get_active_group_id(void);
extern void mmi_email_set_active_group_id(mmi_id grp_id);
extern void mmi_email_set_ss(email_app_save_send_proc_struct *info);
extern void mmi_email_save_send(void);
extern void mmi_email_read_recipient_get_sent_addr(WCHAR **mail_addr, WCHAR **mail_name);

extern BOOL mmi_email_comp_append_template(WCHAR *text);
extern void mmi_email_util_get_folder_name(
                EMAIL_ACCT_ID acct_id,
                EMAIL_ACCT_HANDLE acct_handle,
                EMAIL_FLDR_ID fldr_id,
                srv_email_fldr_type_enum *fldr_type,
                WCHAR *name);
extern void mmi_email_generate_default_acct_name(
        WCHAR *p_acct_name,
        S32 acct_num, 
        WCHAR (*p_exist_acct_name_array)[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1]);
extern MMI_BOOL mmi_email_store_acct_misc_info(EMAIL_ACCT_ID account_id);
extern void mmi_email_destroy_acct_misc_info(EMAIL_ACCT_ID account_id);
extern void mmi_email_set_acct_attribute(srv_email_acct_info_struct *p_acct_info);
extern BOOL mmi_email_acct_get_refresh_status(void);
extern void mmi_email_acct_set_refresh_status(mmi_id menu_id, BOOL enable);

extern U32 mmi_email_get_unread_count(void);
extern BOOL mmi_email_is_drive_valid(CHAR drive);
extern U16 mmi_email_folder_get_status_icon(EMAIL_MSG_ID msg_id, BOOL has_attach, U8 priority, BOOL is_read);

extern void mmi_email_acct_del_notify(EMAIL_ACCT_ID acct_id);
extern void mmi_email_reset_app_comp_info(void);

extern void mmi_email_msg_del_callback(EMAIL_MSG_ID msg_id);
extern void mmi_email_util_play_receive_tone(void);
extern void mmi_email_display_app_core_popup(mmi_id group_id, mmi_email_app_core_result_enum app_core_result);


#ifdef __MMI_EMAIL_REMOTE_FOLDER__
extern WCHAR *mmi_email_remote_get_curr_folder_name(void);
#endif
extern void mmi_email_set_disconnect_to_edit_setting(void);
extern mmi_ret mmi_email_disconnect_to_edit_setting(mmi_event_struct *param);
extern void mmi_email_copy_file_to_view(mmi_id grp_id, WCHAR *file_path, WCHAR *file_ext, mmi_email_copy_file_to_view_callback callback);
extern MMI_BOOL mmi_email_util_dir_exist(const WCHAR *path);
extern void mmi_email_init_copy_file_dir(void);
extern void *mmi_email_get_read_cont_buff_ptr(S32 *cont_len);
extern void mmi_email_reset_curr_fldr_info(void);
extern void mmi_email_exit_app_by_asm(void);
extern BOOL mmi_email_check_msg_valid(EMAIL_MSG_ID msg_id);
extern void mmi_email_exit_save_send(void);
extern U16 mmi_email_util_get_error_string_id(S32 error_id);

extern void mmi_email_set_popup_process(MMI_BOOL popup_process);


extern void mmi_email_batch_receive_init(void);
extern void mmi_email_emn_nmgr_query(void);

extern void mmi_email_comp_asm_stop(void);
extern void mmi_email_read_asm_stop(void);


extern BOOL mmi_email_is_mre_busy(void);
extern void mmi_email_app_mre_send_abort_interal(void);

extern srv_email_addr_struct *mmi_email_comp_get_addlist(void);
extern srv_email_attach_struct *mmi_email_comp_get_attlist(void);
extern WCHAR *mmi_email_comp_get_content_buffer(void);


void mmi_email_ui_refresh_mainmenu(void);
void mmi_email_ui_refresh_account(EMAIL_ACCT_ID acc_id);
void mmi_email_ui_refresh_folder(EMAIL_ACCT_ID acc_id, EMAIL_FLDR_ID fld_id);
void mmi_email_ui_refresh_message(void);

void mmi_email_ui_close_outboxmsg(EMAIL_ACCT_ID acc_id);

// Used by AUTO-CHECK / PUSH / EMN 
extern void mmi_email_emn_set_new_emn_notify_flag(MMI_BOOL flag);
extern MMI_BOOL mmi_email_emn_get_new_emn_notify_flag(void);

extern void mmi_email_close_nmgr_screen(void);

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern void mmi_email_close_hs_screen(void);
#endif

#endif /* _MMI_EMAILAPPPROT_H_ */
