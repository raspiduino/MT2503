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
 *    SyncMLProt.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __SYNCML_PROT_H__
#define __SYNCML_PROT_H__

#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "BtcmSrvGprot.h"
#include "alertscreen.h"
#include "SyncMLStruct.h"

#include "Mmi2syncml_struct.h"
/*****************************************************************************
* Define  
*****************************************************************************/

/*****************************************************************************
* Typedef  
*****************************************************************************/

/*****************************************************************************
* Global Variables 
*****************************************************************************/
extern mmi_syncml_cntx_struct g_mmi_syncml_cntx;

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
extern mmi_syncml_common_cntx_struct g_mmi_syncml_common_cntx;
#endif

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif

/* control alarm status*/
extern BOOL mmi_syncml_alarm_disable_status;


/*****************************************************************************
* Global Function (for interal module) 
*****************************************************************************/
/* SyncmlAccount.c */
extern void mmi_syncml_init_account(void);
extern void mmi_syncml_read_account_from_nvram(U8 record_id, void *temp_buff);
extern void mmi_syncml_write_account_to_nvram(U8 record_id, void *temp_buff);
extern void mmi_syncml_pre_read_account(U8 account_index);
#ifdef __MMI_WLAN_FEATURES__
extern U32 mmi_syncml_get_active_account_bearer(void);
#endif
extern void mmi_syncml_entry_account_option(mmi_id parent_id);
extern void mmi_syncml_scrn_insert(mmi_id parent_id, U16 base_id, U16 scrn_id, FuncPtr entryFuncPtr, mmi_scenario_node_flag flag);
extern mmi_ret mmi_syncml_group_account_edit_proc(mmi_event_struct *param);
extern void mmi_syncml_menu_cui_entry_evt_hdlr(mmi_event_struct *event);
extern void mmi_syncml_menu_cui_exit_evt_hdlr(mmi_event_struct *event);
extern void mmi_syncml_menu_cui_hilite_evt_hdlr(mmi_event_struct *event);
extern void mmi_syncml_menu_cui_select_evt_hdlr(mmi_event_struct *event);
extern void mmi_syncml_menu_cui_close_notify_evt_hdlr(mmi_event_struct *event);
extern void mmi_syncml_menu_cui_csk_select_evt_hdlr(mmi_event_struct *event);
extern void mmi_syncml_entry_account_app_to_sync(void);
extern void mmi_syncml_entry_account_server_setting(void);
extern void mmi_syncml_entry_account_dtcnt_list(void);
extern void mmi_syncml_entry_account_db_contact(void);
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
extern void mmi_syncml_entry_account_db_calendar(void);
#endif 
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
extern void mmi_syncml_entry_account_db_task(void);
#endif 
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
extern void mmi_syncml_entry_account_db_note(void);
#endif 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif
extern void mmi_syncml_check_data_account_ready(FuncPtr fp, MMI_BOOL with_scr_lock);


/* SyncmlMain.c */
extern void mmi_syncml_group_entry_sync_start(mmi_id parent_id);
extern void mmi_syncml_cbm_brearer_disconn_callback(mmi_event_struct *param);
extern MMI_BOOL mmi_syncml_is_phb_ready(void);
extern void mmi_syncml_update_progress_string(U8 info_number);
extern void mmi_syncml_enable_alarm(void);
extern void mmi_syncml_disable_alarm(void);
extern MMI_BOOL mmi_syncml_is_phb_ready_inner(void);
extern void mmi_syncml_read_account_name_display_strings(void);
extern void mmi_syncml_entry_sync_pre_check_return(void);
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__   
extern void mmi_syncml_app_sync_finish_hdlr(U8 account_index);
#endif 
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
extern void mmi_syncml_perform_delete_phb_one_by_one(void);
#endif 
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__ 
extern void mmi_syncml_set_status_icon(MMI_BOOL status);
#endif

extern MMI_BOOL mmi_syncml_data_account_is_valid(U32 acct_id, U32* acct_id_out);

extern void mmi_syncml_popup_display_with_proc(MMI_ID parent_id, WCHAR* title, mmi_event_notify_enum event_type, mmi_proc_func proc, void * user_tag);
extern void mmi_syncml_confirm_display_with_proc(
                                    mmi_id parent_id,
                                    WCHAR* string, 
                                    mmi_confirm_type_enum ctype, 
                                    FuncPtr lsk_f, 
                                    FuncPtr rsk_f, 
                                    void *user_data);
extern void mmi_syncml_cbm_brearer_release(void);

#if defined(__MMI_NCENTER_SUPPORT__)
extern void mmi_syncml_ncenter_sync_reset(void);
extern void mmi_syncml_ncenter_sync_finish(mmi_syncml_finish_sync_ind_struct *local_data);
extern void mmi_syncml_ncenter_sync_bkg_create(mmi_syncml_notification_enum notification);

extern MMI_BOOL mmi_syncml_necnter_is_unfinish_account(U32 index);
extern void mmi_syncml_ncenter_sync_unfinish_create(mmi_syncml_notification_enum notification);
extern void mmi_syncml_ncenter_sync_unfinish_update(U32 index);
extern void mmi_syncml_ncenter_sync_unfinish_destroy(mmi_syncml_notification_enum unfinish_tupe);

#endif

/* SyncmlRegularity.c */
extern void mmi_syncml_init_regular_sync_notify_flag(void); 
#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
extern void mmi_syncml_data_change_timer_hdlr(void);
#endif

/* SyncmlChangelog.c */
extern U32 mmi_syncml_get_current_time(void);
extern U16 mmi_syncml_query_change_log(U8 operation, U8 database, U16 *luid);
extern void mmi_syncml_clearall_change_log(U8 profile_id, U8 database);

/* SyncmlReport.c */
extern void mmi_syncml_init_sync_report(void);
extern void mmi_syncml_set_database_sync_fail(U8 db_type);
extern void mmi_syncml_report_screen_hdlr(void* local_data);

/* SyncMLHandler.c */
extern void mmi_syncml_init_message_handlers(void);
extern void mmi_syncml_restore_context(void);
extern void mmi_syncml_get_imei_req(void);
extern void mmi_syncml_dummy_finish_sync(U16 str_id);
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

/* SyncMLCommon.c */
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
extern void mmi_syncml_device_ask_accept_conn_ind_hdlr(void *param);
extern void mmi_syncml_device_bt_connected_ind_hdlr(void *param);
extern void mmi_syncml_device_bt_disconnected_ind_hdlr(void *param);
extern void mmi_syncml_device_remoteinfo_ind_hdlr(void *param);
extern void mmi_syncml_device_sync_db_ind_hdlr(void *param);
extern void mmi_syncml_device_session_aborted_ind(void *param);
extern void mmi_syncml_device_reset_sync_state(void);
extern void mmi_syncml_common_finish_hdlr(void);
extern mmi_ret mmi_syncml_pc_sync_bt_sel_cui_proc(mmi_event_struct *event);
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

/* SyncMLEmail.c */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

/* SyncMLSAS.c */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

/* SyncMLviewlog.c */
extern void mmi_syncml_entry_sync_log(void);
extern void mmi_syncml_update_sync_log_to_nvram(void);

/* SyncMLOTAP.c */
#ifdef __MMI_SYNCML_CCA_SUPPORT__
extern S32 mmi_syncml_checking_for_dm(void);
#endif

/* SyncMLDevice.c */
#ifdef __MMI_SYNCML_DEVICE_SYNC__
extern void mmi_syncml_device_init(void);
extern void mmi_syncml_device_read_nvram(void);
extern void mmi_syncml_device_finish(void *param);
extern void mmi_syncml_device_init_anchor(void);
extern void mmi_syncml_device_read_sync_log(U8 record_id, void* nvram_buffer);
extern void mmi_syncml_device_clearall_change_log(U8 accnt_id, U8 database);
extern void mmi_syncml_device_read_account(U8 record_id, void* nvram_buffer);
extern void mmi_syncml_device_start_sync(U8 *imei);
extern MMI_BOOL mmi_syncml_device_locate_new_dev(srv_bt_cm_bt_addr *bt_addr, MMI_BOOL peer_flag);
extern void mmi_syncml_device_sync_yes(void);
extern void mmi_syncml_device_sync_no(void);
extern void mmi_syncml_device_state_pre_check(void);
extern void mmi_syncml_device_clear_callback(U8 result);
extern void mmi_syncml_device_add_remote_device(void);
extern void mmi_syncml_device_remoteinfo_ind_res(U8 *imei, U8 status);
extern void mmi_syncml_device_pre_check(mmi_syncml_device_client_callback client_callback);
extern void* mmi_syncml_device_get_setting_cntx(void);
extern void mmi_syncml_device_sync_entry_bt_select_cui(void);
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

/* SyncMLPcSync.c */
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
extern void mmi_syncml_pc_sync_init(void);
extern void mmi_syncml_pc_sync_entry_bt_select_cui(mmi_id parent_id);
extern void mmi_syncml_pc_sync_entry_sync_confirm(void);
extern void mmi_syncml_pc_sync_finish(U32 sync_result);
extern void mmi_syncml_pc_sync_yes(void);
extern void mmi_syncml_pc_sync_no(void);
extern void mmi_syncml_pc_sync_pre_check(void);
extern void mmi_syncml_pc_start_sync(U8 *imei);
extern void mmi_syncml_pc_sync_start_sync_req(U8 *imei);
extern void mmi_syncml_pc_sync_remoteinfo_ind_res(U8 *imei, U8 state);
extern void mmi_syncml_pc_sync_check_account(void);
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

/* SyncMLHandler.c */
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
extern void mmi_syncml_bt_common_ini(void);
extern void mmi_syncml_device_set_state(mmi_syncml_device_state_enum new_state);
extern void mmi_syncml_device_remoteinfo_confirm_check(void);
extern void mmi_syncml_device_entry_sync_confirm(void);
extern void mmi_syncml_device_lock_all_db(void);
extern void mmi_syncml_device_unlock_all_db(void);
extern MMI_BOOL mmi_syncml_device_bt_addr_compare(srv_bt_cm_bt_addr *addr1, srv_bt_cm_bt_addr *addr2);
extern MMI_BOOL mmi_syncml_is_device_or_pc_sync(void);
extern U8 mmi_syncml_device_get_curr_state(void);
extern U8 mmi_syncml_device_get_curr_role(void);
extern void mmi_syncml_device_bt_pwr_switch_notify(U8 bt_state);
extern MMI_BOOL mmi_syncml_device_is_connected(void);
extern void mmi_syncml_comm_disconn(void);

#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

extern void mmi_syncml_set_reminder(U8 accnt_index);

#endif /* __SYNCML_SUPPORT__ */
#endif /* __SYNCML_PROT_H__ */

