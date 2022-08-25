/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *	dmuiprot.h
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file external functions for DMUI application.
 *
 * Author:
 * -------
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 *
 *****************************************************************************/
#ifndef _DMUIPROT_H
#define _DMUIPROT_H
#include "mmi_features.h"
#include "DMTypeDef.h"
#include "dmuigprot.h"
#include "InlineCuiGprot.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmiapi_dm_struct.h"
#include "app_ltlcom.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"

#ifdef __MMI_SYNCML_DM_OTAP__
#include "mmi_rp_app_cca_def.h"
#include "CcaSrvGprot.h"
#include "CentralConfigAgentGProt.h"
#endif

#define ALERT_INPUT_INLINE_ITEM_ID_1 CUI_INLINE_ITEM_ID_BASE
#define ALERT_INPUT_INLINE_ITEM_ID_2 (CUI_INLINE_ITEM_ID_BASE + 1)

#define RETRY_MAX_TIME                          3
#define DMUI_MAX_DT_INPUT_LENGTH                3
#define DMUI_MAX_IPADDRES_LENGTH                4
#define DMUI_MAX_SERVERID                       5
#define DMUI_MAX_PROXY_PORT_LEN                 6
#define DMUI_MIN_PIN_LENGTH                     4
#define DMUI_MAX_PIN_LENGTH                     8
#define DM_DEFAULT_PROFILE_INDEX                0
#define MMI_DMUI_DEFAULT_UPDATE_DEFER_TIME      30
#define MAX_SYNCML_DM_PROFILES                  DMUI_MAX_SERVERID

#define DMUI_DOWNLOAD_RESUME_NEED_CONFIRM_TIME  5*60*1000
#define DMUI_WAIT_FOR_APP_INIT_TIME             3*1000

#define TMP_BUFFER_SIZE                         256
#define MMI_DMUI_STR_BUFFER_SIZE                64
#define DMUI_INPUT_BUFFER_SIZE                  2048

#define DM_PUSH_TEMP_FILE_NAME          L"Z:\\@dm\\dmpush.tmp"
#define DM_SCOMO_APP_CMD_INFO_FILE_NAME L"Z:\\@dm\\scomo_app_cmd_info.tmp"

#ifndef DMUI_MAX_SERVERID
#define DMUI_MAX_SERVERID DM_ACCOUNT_MAX_NUM
#endif 

#if defined(__MMI_OP01_DM_PROFILE_SETTING__) || defined(__MMI_OP12_DM_PROFILE_SETTING__) || defined(__OP02_DM__)
#define MMI_DM_OP
#endif

#if defined(__OP01_3G__) || defined(__UMTS_RAT__)
#define MMI_DM_3G
#endif

#ifdef __DM_MO_SUPPORT__
typedef enum
{
    MMI_DMUI_REPORT_MARK_NEED_NOT_REPORT,
    MMI_DMUI_REPORT_MARK_NOT_REPORT,
    MMI_DMUI_REPORT_MARK_REPORT,
    MMI_DMUI_REPORT_MARK_TOTAL
} mmi_dmui_report_mark_enum;

typedef enum
{
    MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE,
    MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR,
    MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA,
    MMI_DMUI_MO_SPECIAL_APP_TOTAL
} mmi_dmui_mo_special_app_enum;
#endif /* __DM_MO_SUPPORT__ */

#define __SYNCML_DM_TEST__

#define DMUI_SPLIT_STRING L"<!NEXT>"

typedef enum
{
    DM_NETWORK_AVAILABLE = 0,
    DM_NETWORK_NOT_AVAILABLE,
    DM_NETWORK_TOTAL
} dm_network_state_enum;

typedef enum
{
    MMI_DMUI_ENDING_MSG_DEFAULT,
    MMI_DMUI_ENDING_MSG_TIMEOUT,
    MMI_DMUI_ENDING_MSG_SESSION_FAIL,
    MMI_DMUI_ENDING_MSG_NO_MEM,
    MMI_DMUI_ENDING_MSG_END
} mmi_dmui_ending_msg_enum;

typedef void (*TimeOutFuncPtr) (void);
typedef void (*LSKFuncPtr) (void);
typedef void (*RSKFuncPtr) (void);

typedef struct
{
    U16 LSK_str;
    U16 LSK_img;
    U16 RSK_str;
    U16 RSK_img;
    UI_string_type message;
    U16 message_image;
    U16 toneId;
    U32 confirmDuration;
    TimeOutFuncPtr confirmTimeOutFunc;
    LSKFuncPtr LSKFunc;
    RSKFuncPtr RSKFunc;
} dmui_confirm_struct;

#define DMUI_SEND_MSG_TO_DMPS(msgid, req) mmi_frm_send_ilm(MOD_DM, msgid, (oslParaType*)req, NULL)

#define DMUI_SEND_MSG_TO_MMI(msgid, req) mmi_frm_send_ilm(MOD_MMI, msgid, (oslParaType*)req, NULL)

#define DMUI_SEND_MSG_TO_OTHER_MOD(mod_id, msgid, req) mmi_frm_send_ilm(mod_id, msgid, (oslParaType*)req, NULL)

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern const U16 gIndexIconsImageList[];

extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];

MMI_BOOL mmi_dmui_serverid_valid(S8 *p_serverid);

typedef enum
{
    MMI_DMUI_SERVERID = CUI_INLINE_ITEM_ID_BASE,
    MMI_DMUI_SERVERID_EDITOR,
    MMI_DMUI_SERVER_PASSWORD,
    MMI_DMUI_SERVER_PASSWORD_EDITOR,
    MMI_DMUI_SERVER_ADDRESS,
    MMI_DMUI_SERVER_ADDRESS_EDITOR,
    MMI_DMUI_USERNAME,
    MMI_DMUI_USERNAME_EDITOR,
    MMI_DMUI_USER_PASSWORD,
    MMI_DMUI_USER_PASSWORD_EDITOR,
    MMI_DMUI_DATA_ACCOUNT,
    MMI_DMUI_DATA_ACCOUNT_EDITOR,
    MMI_DMUI_AUTHTYPE,
    MMI_DMUI_AUTHTYPE_EDITOR,
    MMI_DMUI_INLINE_ITEM_TOTAL
} dmui_setting_inline_item_enum;

typedef enum
{
    MMI_DMUI_IDLE_STATUS = 0,
    MMI_DMUI_INIT_SESSION_STATUS,
    MMI_DMUI_BOOTSTRAP_USERPIN_STATUS,
    MMI_DMUI_SET_PSERVERID_STATUS,
    MMI_DMUI_EDIT_SET_PSERVERID_STATUS, /* set P_serverid when edit P_serverid item and server id changed */

    MMI_DMUI_ERASE_SET_PSERVERID_STATUS,            /* set P_serverid when erase P_serverid item and server id empty */
    MMI_DMUI_ADD_ACCOUNT_STATUS,
    MMI_DMUI_EDIT_ACTIVATED_ADD_ACCOUNT_STATUS,     /* add account when edit op with server id active */
    MMI_DMUI_EDIT_INACTIVATED_ADD_ACCOUNT_STATUS,   /* add account when edit op with server id inactive */
    MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS,      /* del inactivated account when erase operation */

    MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS,        /* del activated account when erase operation */
    MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS,     /* del account when edit operation with activated server id */
    MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS,   /* del account when edit operation with inactivated server id */
    MMI_DMUI_GET_ACCOUNT_STATUS,
    MMI_DMUI_DOWNLOAD_STATUS,

    MMI_DMUI_UPDATE_STATUS,
    MMI_DMUI_ALERT_STATUS,
    MMI_DMUI_ONLY_INIT_SERVERID_STATUS,
    MMI_DMUI_ONLY_INIT_PSERVERID_STATUS,
    MMI_DMUI_INIT_GET_ACCOUNT_STATUS,               /* get account when in init status */

    MMI_DM_OTA_ADD_ACCOUNT_STATUS,
    MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_ACTIVATED_DEL_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_ACTIVATED_ADD_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS,

    MMI_DM_OTA_INIT_ADD_ACCOUNT_STATUS,
    MMI_DM_OTA_INIT_DEL_ACCOUNT_STATUS,
    MMI_DM_OTA_INIT_SET_PSERVERID_STATUS,
    MMI_DMUI_STATUS_TOTAL
} dmui_message_status_enum;

typedef enum
{
    MMI_DMUI_UPDATE_DEFER_TIME_1_HOUR,
    MMI_DMUI_UPDATE_DEFER_TIME_2_HOUR,
    MMI_DMUI_UPDATE_DEFER_TIME_4_HOUR,
    MMI_DMUI_UPDATE_DEFER_TIME_24_HOUR,
    MMI_DMUI_UPDATE_DEFER_TIME_TOTAL
} dmui_update_defer_time;

typedef enum
{
    MMI_DMUI_FOTA_STATUS_IDLE,
    MMI_DMUI_FOTA_STATUS_RECV_NOTIFY,
    MMI_DMUI_FOTA_STATUS_NOTIFY_DLAGENT,
    MMI_DMUI_FOTA_STATUS_DL_START,
    MMI_DMUI_FOTA_STATUS_DL_PAUSE,
    MMI_DMUI_FOTA_STATUS_DL_RESUME,
    MMI_DMUI_FOTA_STATUS_DL_FINISH,
    MMI_DMUI_FOTA_STATUS_UPDATE_RECV_NOTIFY,
    MMI_DMUI_FOTA_STATUS_UPDATE_DEFER,
    MMI_DMUI_FOTA_STATUS_UPDATE_REBOOT,
    MMI_DMUI_FOTA_STATUS_END,
} dmui_fota_status_enum;

typedef struct
{
    U16 year;
    U16 month;
    U16 day;
    U16 hour;
    U16 minute;

    U8 ip_addr[4];
} dmui_alert_input_struct;

typedef struct
{
    U8 dmui_serverid[DM_MAX_ID_STR];
    U8 dmui_nodename[DM_MAX_ID_STR];    /* from 1 - DMUI_MAX_SERVERID */
} dmui_serverid_map_struct;

typedef struct
{
    U8 server_id[DM_MAX_ID_STR];
    U8 provurl[DM_MD5_HASH_LENGTH];
    U8 proxy_id[DM_MD5_HASH_LENGTH];
    dm_profile_type_enum profile_type;
    MMI_BOOL read_only;
} mmi_dm_profile_struct;

typedef struct
{
    MMI_STR_ID str_id;
    mmi_event_notify_enum event_id;
} mmi_dmui_nmgr_notify_info_struct;

typedef struct
{
    dm_account_struct dmui_cur_edit_account;
    dm_omadl_dd_struct dmui_display_info;
    dm_alert_struct dmui_alert_struct;
    dmui_alert_input_struct dmui_alert_input_context;   /* struct for alert input */
    dmui_message_status_enum dmui_status;               /* DMUI message status */
    U8 dmui_alert_input_text[DMUI_INPUT_BUFFER_SIZE];   /* input text */
    U8 dmui_alert_string[DMUI_INPUT_BUFFER_SIZE];
    MMI_STR_ID mmi_dmui_authtype[DM_AUTH_TYPE_TOTAL];
    U8 dmui_alert_default_value[MAX_SUB_MENUS];
    U8 pin_password[(DMUI_MAX_PIN_LENGTH + 1) *ENCODING_LENGTH];
    U8 proxy_port_str[DMUI_MAX_PROXY_PORT_LEN *ENCODING_LENGTH];
    U8 dmui_hilite_index;                               /* index of high light item */
    U8 dmui_alert_choice_num;                           /* number of alert choice list */
    U32 dmui_hilite_serverid_index;                     /* high light server id index */
    U8 dmui_primary_serverid[DM_MAX_ID_STR];
    U8 dmui_alert_choice_send[DMUI_INPUT_BUFFER_SIZE];
    mmi_dm_profile_struct dmui_profile_array[DMUI_MAX_SERVERID];
    U16 dmui_dl_percent;                                /* download progress */
    U16 dmui_alert_scr_id;                              /* current alert screen id */

    U16 app_id;     /* Save app_id for get & update DM   */
    S32 prof_id;    /* Save prof id for get & update DM  */
    S32 hConfig;

    kal_wchar *dmui_dd_rsp_file_path;
    MMI_BOOL dmui_data_account_init;    /* flag to mark data account init or not */
    MMI_BOOL is_reg_sim_success;
    MMI_ID cui_profile_setting_inline_id;
    MMI_ID cui_session_alert_input_inline_id;
    MMI_ID cui_option_menu_id;
    MMI_ID cui_default_profile_option_menu_id;
    mmi_dmui_ending_msg_enum ending_msg;
} dmui_context_struct;

#ifdef __DM_MO_SUPPORT__
typedef struct
{
    mmi_dmui_app_id_enum        app_id;
    mmi_dmui_mo_type_enum       mo_type;
    void                        *callback;
    mmi_dmui_report_mark_enum   report_mark;
    mmi_dmui_status_enum        status;
} mmi_dmui_mo_register_info_struct;

typedef struct
{
    U8 max_reg_app;
    mmi_dmui_cmd_enum mo_cmd;
    mmi_dmui_cmd_enum curr_mo_cmd;
    mmi_dmui_mo_type_enum mo_type;
    mmi_dmui_mo_type_enum curr_mo_type;
    mmi_dmui_status_enum mo_status[MMI_DMUI_MO_TYPE_TOTAL];
    MMI_BOOL is_cmd_success;
    MMI_BOOL is_curr_cmd_success;
    MMI_BOOL is_server_cmd;
    mmi_dmui_mo_register_info_struct mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_TOTAL];
    mmi_dmui_mo_register_info_struct mo_reg_info[
                                    #ifdef __DM_LAWMO_SUPPORT__
                                        (S32)MMI_DMUI_APP_ID_TOTAL * 2 +
                                    #endif /* __DM_LAWMO_SUPPORT__ */
                                    #ifdef __DM_SCOMO_SUPPORT__
                                        0 +
                                    #endif /* __DM_SCOMO_SUPPORT__ */
                                        1];
} mmi_dmui_mo_context_struct;
#endif /* __DM_MO_SUPPORT__ */

typedef struct
{
    UI_string_type message;
    mmi_event_notify_enum event_id;
    U32 duration;
} dmui_prompt_message_struct;

typedef struct 
{
    LOCAL_PARA_HDR  /*header of local paramter*/
    S32 cause;
} dmui_da_report_struct;

extern void mmi_dmui_launch(void);
extern mmi_ret mmi_dmui_setting_scr_group_proc(mmi_event_struct *evt);
extern mmi_ret mmi_dmui_session_scr_group_proc(mmi_event_struct *evt);

extern MMI_BOOL mmi_dmui_serverid_valid(S8 *p_serverid);

/* save server id list to global struct */
extern void mmi_dmui_save_serverid_list(U8 *sour_str);

/* waiting screen when edit or erase DM setting */
extern void mmi_dmui_waiting_entry(void);
extern mmi_ret mmi_dmui_waiting_leave_proc(mmi_event_struct *evt);

/* high light function for DMUI setting screens */
extern void mmi_dmui_highlight_main(void);

/* entry function for DMUI main menu and send message to DM PS */
extern void mmi_dmui_entry_main(void);

/* entry option menu with empty server id item or not */
extern void mmi_dmui_entry_option_main(void);

#ifdef MMI_DM_OP
extern void mmi_dmui_entry_option_main_default_profile(void);
#endif /* MMI_DM_OP */

/* high light functions for option screen items */
extern void mmi_dmui_entry_option_activate(void);
extern void mmi_dmui_entry_option_edit(void);
extern void mmi_dmui_entry_option_edit_pre(void);
extern void mmi_dmui_entry_option_view(void);

extern void mmi_dmui_save_highlight_serverid(S32 index);
extern void mmi_dmui_info_hilite_handler(S32 hiliteid);

/* function to check user input in info edit screen */
extern void mmi_dmui_info_checkinput_popup(void);
extern void mmi_dmui_info_checkinput(void);
extern void mmi_dmui_get_value_from_setting_inline(void);

extern void mmi_dmui_entry_option_erase_confirm(void);
extern void mmi_dmui_entry_option_erase_confirm_yes(void);
extern void mmi_dmui_entry_option_erase_confirm_no(void);

extern void mmi_dmui_info_save_no(void);

/* entry function of data account */
extern void mmi_dmui_entry_dtcnt_sel(void);
extern void mmi_dmui_dtcnt_sel_save(mmi_event_struct *evt);

/* call back function for data account ready and read account name */
extern void mmi_dmui_main_data_account_check(void);

/* function to response different case in DM setting edit screen with different case of server id */
extern void mmi_dmui_info_save_confirm_serverid_inactivated_changed(void);
extern void mmi_dmui_info_save_confirm_serverid_activated_changed(void);
extern void mmi_dmui_info_save_confirm_serverid_nochanged(void);

/* receive DM PS message and display screen and other functions */
/* functions for download progress screen */
extern void mmi_dmui_download_progress_cancel(void);
extern void mmi_dmui_download_progress_no(void);
extern void mmi_dmui_display_download_progress(U32 percentage);

extern void mmi_dmui_entry_reset_progress(void);

extern void mmi_dmui_init_session_confirm_yes(void);
extern void mmi_dmui_init_session_confirm_no(void);

/* function to response key event of user pin input screen */
extern MMI_BOOL mmi_dmui_user_pin_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg);
extern void mmi_dmui_entry_user_pin_confirm(void);
extern void mmi_dmui_entry_user_pin_confirm_ok(void);
extern void mmi_dmui_entry_user_pin_confirm_no(void);
extern void mmi_dmui_user_pin_change_lsk(U8 *text, U8 *cursor, S32 length);

/* function to entry download or update screen */
extern void mmi_dmui_entry_download_confirm(void);
extern MMI_BOOL mmi_dmui_fota_update_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg);
extern void mmi_dmui_fota_entry_update_confirm(void);
extern void mmi_dmui_read_info_from_file(U16 *file_path);
extern void mmi_dmui_oma_fill_info(U16 srcid, S8 *out);
extern MMI_BOOL mmi_dmui_display_dl_progress_hdlr(mmi_scenario_id scen_id, void *arg);

/* function to response user input in download confirm screen */
extern void mmi_dmui_download_confirm_cancel_hdlr(void);
extern void mmi_dmui_download_confirm_yes_hdlr(void);
extern void mmi_dmui_download_confirm_no_hdlr(void);

/* function to response user input in update confirm screen */
extern void mmi_dmui_fota_send_update_accept_rsp(void);
extern void mmi_dmui_fota_send_update_defer_rsp(void);
extern void mmi_dmui_fota_entry_update_defer(void);
extern void mmi_dmui_fota_update_defer_highlight_hdlr(S32 index);
extern void mmi_dmui_fota_update_defer_lsk_ok(void);
extern mmi_ret mmi_dmui_fota_update_scrn_leave_proc(mmi_event_struct *evt);
extern mmi_ret mmi_dmui_reboot_leave_proc(mmi_event_struct *evt);

extern void mmi_dmui_reset_rsp_handle(void *msg);

/* functions for entry alert message screen */
extern void mmi_dmui_entry_alert_display(void);
extern void mmi_dmui_entry_alert_confirm(void);
extern void mmi_dmui_entry_alert_input(void);
extern void mmi_dmui_entry_alert_single_choice(void);
extern void mmi_dmui_entry_alert_multi_choice(void);

/* alert confirm */
extern void mmi_dmui_entry_alert_confirm_ok(void);
extern void mmi_dmui_alert_confirm_no(void);
extern void mmi_dmui_alert_confirm_cancel(void);

/* alert input */
extern void mmi_dmui_alert_input_confirm(void);
extern void mmi_dmui_alert_input_confirm_yes(void);
extern void mmi_dmui_alert_input_save_value(void);

extern void mmi_dmui_alert_parse_string(void);
extern void mmi_dmui_alert_parse_status(void);

/* alert single choice */
extern void mmi_dmui_hilite_single_choice_handle(S32 hilited);
extern void mmi_dmui_entry_alert_single_choice_ok(void);

extern void mmi_dmui_init_serverid(void);

/* alert multi choice */
extern void mmi_dmui_alert_multi_choice_confirm(void);
extern void mmi_dmui_alert_multi_choice_confirm_yes(void);

/* DM MMI confirm time out function */
extern void ConfirmTimerOver(void);

/* DM MMI confirm screen with user define time out */
extern void mmi_dmui_otap_confirm(void);
extern MMI_BOOL mmi_dmui_otap_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg);
extern mmi_ret mmi_dmui_ota_confirm_leave_proc(mmi_event_struct *evt);

extern void mmi_dmui_fill_confirm_struct(
                U16 LSK_str,
                U16 LSK_img,
                U16 RSK_str,
                U16 RSK_img,
                UI_string_type message,
                U16 message_image,
                U16 toneId,
                U32 confirmDuration,
                TimeOutFuncPtr confirmTimeOutFunc,
                FuncPtr LSKFunc,
                FuncPtr RSKFunc);

MMI_BOOL mmi_dmui_check_self_reg_sim_match(void);

#ifdef MMI_DM_OP
/* function to init default DM setting profile */
extern void mmi_dm_ota_init_profile(void);
extern void mmi_dm_ota_init_profile2(void);
#endif /* MMI_DM_OP */ 

/* function for message from DM PS */
extern void mmi_dmui_init_config_info_cnf_hdlr(void *msg);
extern void mmi_dmui_self_register_result_ind_hdlr(void *msg);
extern void mmi_dmui_add_account_rsp_handle(void *msg);
extern void mmi_dmui_del_account_rsp_handle(void *msg);
extern void mmi_dmui_get_account_rsp_handle(void *msg);
extern void mmi_dmui_list_serverid_rsp_handle(void *msg);
extern void mmi_dmui_get_pserverid_rsp_handle(void *msg);
extern void mmi_dmui_set_pserverid_rsp_handle(void *msg);
extern void mmi_dmui_init_session_ind_handle(void *msg);
extern void mmi_dmui_userpin_ind_handle(void *msg);
extern void mmi_dmui_download_ind_handle(void *msg);
extern void mmi_dmui_fota_update_req_ind_hdlr(void *msg);
extern void mmi_dmui_alert_ind_handle(void *msg);
extern void mmi_dmui_alert_entry_hdlr(dm_alert_type_enum alert_type);
extern void mmi_dmui_reset_ind_handle(void *msg);
extern void mmi_dmui_download_progress_ind_handle(void *msg);
extern void mmi_dmui_change_account_ind_handle(void *msg);
extern void mmi_dmui_exec_complete_ind_handle(void *msg);
extern void mmi_dmui_session_start_ind_handle(void *msg);
extern void mmi_dmui_session_finish_ind_handle(void *msg);
extern void mmi_dmui_error_ind_handle(void *msg);
extern void mmi_dmui_ps_status_ind_handle(void *msg);
extern MMI_BOOL mmi_dmui_ps_status_entry_hdlr(mmi_scenario_id scen_id, void *arg);
extern void mmi_dmui_da_state_pause_ind_handle(void *msg);
extern void mmi_dmui_da_state_abort_ind_handle(void *msg);
extern void mmi_dmui_da_state_complete_ind_handle(void *msg);

extern void mmi_dmui_start_dl_ind_handle(void *msg);
extern MMI_BOOL mmi_dmui_dl_via_dlagent_entry_hdlr(mmi_scenario_id scen_id, void *arg);
extern void mmi_dmui_dl_resume_ind_handle(void *msg);
extern void mmi_dmui_dl_report_callback(BOOL success);
extern void mmi_dmui_dl_report(dm_dl_status_enum result);

extern void mmi_dmui_entry_download_progress(void);
extern mmi_ret mmi_dmui_download_progress_leave_proc(mmi_event_struct *evt);
extern U8 mmi_dmui_is_in_call(void);
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
extern void mmi_dmui_none_del_waiting_entry(void);
extern void mmi_dmui_display_popup(UI_string_type string, mmi_event_notify_enum event_id, U32 duration);
extern void mmi_dmui_display_popup_timeout(void);
extern mmi_ret mmi_dmui_ucm_callback_handler(mmi_event_struct* param);
extern void mmi_dmui_ucm_defer_to_notify_callback(void);
extern MMI_BOOL mmi_dmui_defer_nmgr_entry_hdlr(mmi_scenario_id scen_id, void *arg);
extern void mmi_dmui_download_resume_confirm_timer_callback(void);
extern MMI_BOOL mmi_syncml_dm_check(void);
extern void mmi_dmui_all_app_init_hdlr(void);
extern void mmi_dmui_remove_non_del_screen(MMI_ID group_id, MMI_ID scr_id);
extern mmi_ret mmi_dmui_save_profile_cnf_cb(mmi_event_struct *evt);
extern mmi_ret mmi_dmui_del_profile_cnf_cb(mmi_event_struct *evt);
extern mmi_ret mmi_dmui_alert_input_cnf_cb(mmi_event_struct *evt);
extern mmi_ret mmi_dmui_alert_multi_choice_cnf_cb(mmi_event_struct *evt);
extern void mmi_dmui_conn_with_dtcnt_ind_hdlr(void *msg);
extern void mmi_dmui_set_ending_msg(mmi_dmui_ending_msg_enum ending_msg);
extern void mmi_dmui_run_ending_msg(void);
extern MMI_BOOL mmi_dmui_popup_ps_rsp_result(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string);

#ifdef __MMI_SYNCML_DM_OTAP__

typedef struct
{
    S32 auth_level;
    dm_auth_type_enum auth_pref;
    U8 auth_pref_unused[3];
    U8 auth_name[DM_MAX_ID_STR];
    U8 auth_pw[DM_MAX_ID_STR];
    U8 auth_nonce[DM_MAX_NAME_STR];
} mmi_dm_ota_appauth_struct;

typedef struct
{
    U8 proxy_id[DM_MD5_HASH_LENGTH];
    U8 conn_type;
    U8 conn_ref[DM_MAX_ID_STR];
    U8 proxy_addr[DM_MAX_IP_SIZE];
    U8 proxy_user_name[DM_MAX_ID_STR];
    U8 proxy_user_pw[DM_MAX_ID_STR];
    U32 proxy_port;
    U16 data_account_id;
    U8 data_account_id_unused[2];
    MMI_BOOL proxy_used;
    U8 proxy_used_unused[3];
} mmi_dm_ota_conn_setting_struct;

typedef struct
{
    U32 port_num;
    dm_auth_type_enum auth_pref;
    U8 auth_pref_unused[3];
    dm_addr_type_enum addr_type;
    U8 addr_type_unused[3];
    U8 node_name[DM_MAX_ID_STR];
    U8 server_addr[DM_MAX_URI_SIZE];
    U8 server_id[DM_MAX_ID_STR];
    U8 server_pw[DM_MAX_ID_STR];
    U8 server_nonce[DM_MAX_NAME_STR];
    U8 server_prenonce[DM_MAX_NAME_STR];
    U8 user_name[DM_MAX_ID_STR];
    U8 user_pw[DM_MAX_ID_STR];
    U8 client_nonce[DM_MAX_NAME_STR];
    U8 acct_name[DM_MAX_ID_STR];
    U8 provurl[DM_MD5_HASH_LENGTH];
    U8 proxy_id[DM_MD5_HASH_LENGTH]; /* For mapping profile number use. */
    MMI_BOOL read_only;
    MMI_BOOL match_upadte;
    dm_profile_type_enum profile_type;
    mmi_dm_ota_conn_setting_struct conn_setting;
} mmi_dm_ota_account_struct;

typedef struct
{
    U16 conf_id;    /* Configuration ID                  */
    S32 doc_hdl;    /* Configuration document handle     */

    U8 num_profiles;                                /* Num of processed profiles         */
    U8 num_proxy;                                   /* Num of processed proxy */
    U8 iter;                                        /* Used to traverse profiles         */
    U8 num_installed;
    U32 edit_serverid_index;                        /* index of provisioning server id in server id array */
    cca_status_enum setting_status;                 /* status of install setting */
    U8 total_valid_profiles;                        /* Num of total valid profiles */
    
    MMI_BOOL isvalidprof[MAX_SYNCML_DM_PROFILES];   /* Used to place profiles index that are valid */
    mmi_dm_ota_account_struct profile[MAX_SYNCML_DM_PROFILES];
    /* Be a temp storage used to store the settings of the new profile. */
    mmi_dm_ota_conn_setting_struct *proxy[MAX_SYNCML_DM_PROFILES];
    /* Be a temp storage used to store the data of the new proxy. */

} syncml_dm_ota_context_struct;

extern mmi_ret mmi_dmui_ota_screen_group_proc(mmi_event_struct *evt);

/* set value to DM message struct */
extern void mmi_syncml_dm_set_value(dm_account_struct *ptr_dm_account, mmi_dm_ota_account_struct *ptr_dm_ota);

extern void mmi_syncml_dm_entry_installation_pre(void);
extern void mmi_syncml_dm_entry_installation(void);

extern void mmi_syncml_dm_next_profile(void);

extern MMI_BOOL Is_ANSII_format(S8 *dest);
extern void mmi_syncml_dm_ansii2unicode(S8 *pOutBuffer, S8 *pInBuffer, U32 len);

extern S16 mmi_syncml_dm_new_otap_proxy(syncml_dm_ota_context_struct *cntx);
extern void mmi_syncml_dm_free_otap_proxy(void);

/* END key when display SYNCML setting information */
extern mmi_ret mmi_dmui_ota_install_leave_proc(mmi_event_struct *evt);

/* find empty profile exist or not */
extern void mmi_syncml_dm_find_empty_profile(void);

/* when user select skip in display screen and pop up this confirm window */
extern void mmi_syncml_dm_display_skip_confirm(void);

/* entry a process of install profile */
extern void mmi_syncml_dm_install_profile(void);

/* function to receive node data from CCA */
extern cca_status_enum mmi_syncml_dm_proc_cca_nodes(
                        S32 doc_hdl,
                        S32 node_hdl,
                        U16 symbol,
                        cca_iterator_struct *param_list,
                        void *user_data);

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/* entry replace screen */
extern void mmi_syncml_dm_entry_replacement(void);
#endif

/* get valid profile number */
extern U8 mmi_syncml_dm_get_valid_profile_num(void);

/* display server id list */
extern void mmi_syncml_dm_server_id_list(void);

/* high light and select function in server id list */
extern void mmi_syncml_dm_server_id_list_select(S32 index);

/* replace server id function */
extern void mmi_syncml_dm_replace_profile(void);

/* send update profile result message to CCA */
extern void mmi_syncml_dm_send_cca_update_prof_end(cca_status_enum status);

/* send get profile result message to CCA */
extern void mmi_syncml_send_cca_dm_get_profile(cca_status_enum status);

/* send status to CCA application */
extern void mmi_dmui_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status);

/* justifie whether the new provisioning profile matches the update rule */
extern void mmi_syncmal_dm_justify_profile_update(mmi_dm_ota_account_struct *pAccount);

extern mmi_ret mmi_dmui_ota_exist_replace_cnf_cb(mmi_event_struct *evt);
#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
extern mmi_ret mmi_dmui_ota_full_replace_cnf_cb(mmi_event_struct *evt);
#endif
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/* right-soft key handler of server-id list screen */ 
extern void mmi_syncml_dm_back_from_serverid_list(void);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
#endif /* __MMI_SYNCML_DM_OTAP__ */ 

#ifdef __DM_LAWMO_SUPPORT__
extern void mmi_dmui_lawmo_req_ind_hdlr(void *msg);
extern void mmi_dmui_send_lawmo_req_ind(dm_lawmo_result_enum result);
extern void mmi_dmui_lawmo_cmd_sender(void);
extern void mmi_dmui_lawmo_special_app_cmd_sender(mmi_dmui_mo_special_app_enum spe_app_index);
extern void mmi_dmui_lawmo_cmd_finish(void);
extern void mmi_dmui_send_lawmo_cmd_req(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd);
extern void mmi_dmui_lawmo_cmd_rsp_hdlr(void *msg);
extern mmi_dmui_cmd_enum mmi_dmui_get_lawmo_cmd(dm_lawmo_cmd_enum cmd);
extern void mmi_dmui_switch_nw_mode(void);
extern mmi_ret mmi_dmui_switch_nw_mode_cb(mmi_event_struct *evt);
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __DM_SCOMO_SUPPORT__
extern void mmi_dmui_scomo_install_by_srv_ind_hdlr(void *msg);
extern void mmi_dmui_scomo_remove_by_srv_ind_hdlr(void *msg);
extern void mmi_dmui_scomo_install_by_user_rsp_hdlr(void *msg);
extern void mmi_dmui_scomo_remove_by_user_rsp_hdlr(void *msg);
extern void mmi_dmui_scomo_handle_unfinished_report(void);
extern void mmi_dmui_scomo_app_operate_notify(
                mmi_dmui_app_id_enum app_id,
                mmi_dmui_cmd_enum cmd,
                mmi_dmui_scomo_app_report_info_struct *scomo_info);
extern mmi_dmui_cmd_enum mmi_dmui_get_scomo_cmd(dm_scomo_command_enum cmd);
#endif /* __DM_SCOMO_SUPPORT__ */

#ifdef __DM_MO_SUPPORT__
extern void mmi_dmui_change_status_on_command(void);
extern void mmi_dmui_change_status_after_command(void);
extern mmi_dmui_mo_type_enum mmi_dmui_get_mo_type(mmi_dmui_cmd_enum cmd);
extern U32 mmi_dmui_mo_switch_error_code(mmi_dmui_result_enum result);
#endif /* __DM_MO_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_dmui_fte_main_menu_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* _DMUIPROT_H */ 
