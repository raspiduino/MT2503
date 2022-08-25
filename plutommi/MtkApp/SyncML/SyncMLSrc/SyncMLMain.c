/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *    SyncMLMain.c
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
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/

#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"
#include "bt_a2dp_base_struct.h"
#include "kal_general_types.h"
#include "mmiapi_dm_struct.h"
#include "wgui_categories_list.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_rp_srv_syncml_def.h"
#include "GlobalResDef.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_rp_app_mobile_service_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "wap_adp.h"
#include "cbm_consts.h"
#include "NetSetSrvGprot.h"
#include "cbm_api.h"
#include "NetSetAppGprot.h"
#include "PhbSrvGprot.h"
#include "custom_mmi_default_value.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "CustMenuRes.h"
#include "AlarmFrameWorkProt.h"
#include "PhoneBookGprot.h"
#include "SyncmlGprot.h"
#include "SyncMLDef.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "PhoneBookGprot.h"
#include "syncml_common_customize.h"
#include "mmi2syncml_struct.h"
#ifdef SYNCML_DM_SUPPORT
#include "Cbfunc.h"
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
#include "UcmSrvGprot.h"
#include "PhoneBookResDef.h"  
#endif 
#include "BTMMIScrGprots.h"
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif
#include "cbmsrvgprot.h"
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
#include "Btcmcuigprot.h"
#endif
#include "menucuigprot.h"
#include "simctrlsrvgprot.h"

#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "Cbm_api.h"
#include "DtcntSrvGprot.h"

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
#include "ScrLockerGprot.h"
#endif

#if defined(__MMI_NCENTER_SUPPORT__)
#include "vsrv_ncenter.h"
#endif

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif

/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/
/*****************************************************************************
 * Define
 *****************************************************************************/
static CHAR g_syncml_sync_info[64];

#define INVALID_NETID 0xFFFFFFFF

/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
mmi_syncml_cntx_struct g_mmi_syncml_cntx;
extern mmi_syncml_account_struct g_syncml_account;

#if defined(__MMI_NCENTER_SUPPORT__)
mmi_syncml_ncenter_cntx_struct g_syncml_ncenter;
#endif
/* control alarm status*/
BOOL mmi_syncml_alarm_disable_status;

U16 g_syncml_temp_luid[MAX_SYNC_ITEMS];
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static void mmi_syncml_entry_sync_main(void);
static void mmi_syncml_entry_sync_account_list(void);
static void mmi_syncml_entry_sync_now_scrn(void);
static void mmi_syncml_entry_sync_abort(void);
static void mmi_syncml_entry_sync_abort_scrn(void);
static void mmi_syncml_start_sync_int(void);
static void mmi_syncml_read_init_data_from_nvram(void);

static mmi_ret mmi_syncml_no_server_addr_popup_proc(mmi_event_struct * param);
static mmi_ret mmi_syncml_no_application_popup_proc(mmi_event_struct * param);
static mmi_ret mmi_syncml_invalid_dtcnt_popup_proc(mmi_event_struct * param);
static mmi_ret mmi_syncml_no_phb_addr_popup_proc(mmi_event_struct * param);
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
static mmi_ret mmi_syncml_no_cal_addr_popup_proc(mmi_event_struct * param);
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
static mmi_ret mmi_syncml_no_task_addr_popup_proc(mmi_event_struct * param);
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
static mmi_ret mmi_syncml_no_note_addr_popup_proc(mmi_event_struct * param);
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif
static mmi_ret mmi_syncml_confirm_display_proc(mmi_event_struct *param);

static void mmi_syncml_cat_progress_count_string(U8 info_number);
static void mmi_syncml_go_back_background_sync(void);
static void mmi_syncml_sync_now_init_anchor(void);
static MMI_BOOL mmi_syncml_check_incomplete_database_setting(U8 account_index);
static MMI_BOOL mmi_syncml_sync_pre_check_is_successfull(void);
static void mmi_syncml_entry_account_dtcnt_list_check(void);

#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
static void mmi_syncml_popup_sync_backup_warning(void);
static void mmi_syncml_popup_sync_restore_warning(void);
static void mmi_syncml_perform_delete_all_records(void);
static void mmi_syncml_entry_delete_all_records(void);
static void mmi_syncml_refresh_sync_cancel(void);
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__   
static void mmi_syncml_app_sync_read_account(void);
static void mmi_syncml_app_sync_entry_account_list(mmi_id cui_gid);
static void mmi_syncml_app_sync_entry_sync_pre_check(void);
static void mmi_syncml_app_sync_account_highlight_handler(S32 index);
static mmi_ret cui_syncml_app_sync_proc(mmi_event_struct *param);
static void cui_syncml_app_sync_menu_cui_entry_evt_hdlr(mmi_event_struct *param);
#endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */

#if defined(__MMI_NCENTER_SUPPORT__)
static void mmi_syncml_ncenter_sync_bkg_callback(vsrv_notification_handle noti, VsrvNIntent intent, void* userData, U32 userDataSize);
static void mmi_syncml_ncenter_sync_bkg_destroy(void);

static void mmi_syncml_ncenter_sync_unfinish_callback(vsrv_notification_handle noti, VsrvNIntent intent, void* userData, U32 userDataSize);
static void mmi_syncml_ncenter_sync_unfinish_launch(void);

static void mmi_syncml_ncenter_sync_group_close(void);
#endif
/*****************************************************************************
 * Function definition
 *****************************************************************************/
#define screen_group_start
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_launch
 * DESCRIPTION
 *  lunch syncml app
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_entry_sync_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_scrn_insert
 * DESCRIPTION
 *  insert a screen into history
 * PARAMETERS
 *  scrn_id         [IN]    screen id
 *  entryFunPrt     [IN]    entry function
 *  flag            [IN]    position to insert
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_scrn_insert(mmi_id parent_id, U16 base_id, U16 scrn_id, FuncPtr entryFuncPtr, mmi_scenario_node_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_node_info_init(&node_info);
    node_info.id = scrn_id;
    node_info.entry_proc = (mmi_proc_func)entryFuncPtr;
    mmi_frm_scrn_insert(parent_id, base_id, &node_info, flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_post_evt_to_parent
 * DESCRIPTION
 *  insert a screen into history
 * PARAMETERS
 *  scrn_id         [IN]    screen id
 *  entryFunPrt     [IN]    entry function
 *  flag            [IN]    position to insert
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_group_post_evt_to_parent(mmi_id curr_gid, U16 evt_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, evt_id, curr_gid); 
    
    mmi_frm_group_post_to_parent(curr_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_confirm_display_proc
 * DESCRIPTION
 *  common confirmation proc function
 * PARAMETERS
 *  mmi_event_struct *param
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_confirm_display_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)param;
    mmi_syncml_confirm_struct *confirm_data = (mmi_syncml_confirm_struct *)evt->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            switch(evt->result)
            {
                case MMI_ALERT_CNFM_YES:
                    (confirm_data->lsk_f)();
                    break;
                case MMI_ALERT_CNFM_NO:
                    (confirm_data->rsk_f)();
                    break;

                /* free buffer on all exit */
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                    OslMfree(confirm_data);
                    break;
                default:
                    break;
            }
            
            break;
        }
        
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_confirm_display_with_proc
 * DESCRIPTION
 *  common confirmation proc function
 * PARAMETERS
 *  mmi_id parent_id, U16 str_id,  FuncPtr lsk_f, FuncPtr rsk_f
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_confirm_display_with_proc(
                                    mmi_id parent_id,
                                    WCHAR* string, 
                                    mmi_confirm_type_enum ctype, 
                                    FuncPtr lsk_f, 
                                    FuncPtr rsk_f, 
                                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_property_struct *arg_ptr;
    mmi_syncml_confirm_struct *confirm_data = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    confirm_data = (mmi_syncml_confirm_struct *)OslMalloc(sizeof(mmi_syncml_confirm_struct));
    
    confirm_data->lsk_f = lsk_f;
    confirm_data->rsk_f = rsk_f;
    confirm_data->user_data = user_data;
    
    mmi_confirm_property_init(&arg, ctype);
	arg.parent_id = parent_id;
    arg.callback = mmi_syncml_confirm_display_proc;
    arg.user_tag = (void*)confirm_data;

    if (user_data)
    {
        arg_ptr = (mmi_confirm_property_struct *)user_data;
        
        /* if new attribution will be set, pls use * user_data and reset them below here */
        arg.f_auto_map_empty_softkey = arg_ptr->f_auto_map_empty_softkey;
    }
    
    mmi_confirm_display(
        string, 
        MMI_EVENT_QUERY, 
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_display_with_proc
 * DESCRIPTION
 *  popup with proc function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_popup_display_with_proc(MMI_ID parent_id, WCHAR* string, mmi_event_notify_enum event_type, mmi_proc_func proc, void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.parent_id = parent_id;
    arg.callback = proc;
    arg.user_tag = user_data;
    mmi_popup_display(string, event_type, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_sync_main_proc
 * DESCRIPTION
 *  insert a screen into history
 * PARAMETERS
 *  scrn_id         [IN]    screen id
 *  entryFunPrt     [IN]    entry function
 *  flag            [IN]    position to insert
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_group_sync_main_proc(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(param->evt_id)
    {
        case EVT_ID_SYNC_MINIMIZE:
        {
            mmi_frm_group_close(GRP_ID_SYNC_MAIN);
            break;
        }
        /* menu cui event hdlr */
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {            
            mmi_syncml_menu_cui_hilite_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_syncml_menu_cui_select_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_syncml_menu_cui_entry_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_syncml_menu_cui_close_notify_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
			mmi_syncml_menu_cui_csk_select_evt_hdlr(param);
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_syncml_entry_sync_pre_check_return();
            break;
        }
        default:
            break;
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_sync_pre_check_proc
 * DESCRIPTION
 *  insert a screen into history
 * PARAMETERS
 *  scrn_id         [IN]    screen id
 *  entryFunPrt     [IN]    entry function
 *  flag            [IN]    position to insert
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_group_sync_pre_check_proc(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(param->evt_id)
    {
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
        /* bt select cui event hdlr */
        case EVT_ID_CUI_BT_CM_DEVICE_SELECT:
        {
            mmi_syncml_pc_sync_bt_sel_cui_proc(param);
            break;
        }
#endif
        case EVT_ID_GROUP_DEINIT:
        {
            g_mmi_syncml_cntx.is_pre_sync = 0;    
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


#define screen_group_end
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init
 * DESCRIPTION
 *  Initialize highlight, hint, and protocol event handlers for SyncML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_INI_PROCESS);

    /* only read from nvram once, then always use the global context */
    memset(&g_mmi_syncml_cntx, 0, sizeof(mmi_syncml_cntx_struct));

    mmi_syncml_read_init_data_from_nvram();

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
#endif

    mmi_syncml_init_account();

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif

    mmi_syncml_init_message_handlers();

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    mmi_syncml_bt_common_ini();
#endif

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    mmi_syncml_device_init();
#endif

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    mmi_syncml_pc_sync_init();
#endif

#if (defined(SYNCML_DM_SUPPORT) && defined(__MMI_SYNCML_CCA_SUPPORT__))
    mmi_dm_set_check_function(DM_SETTING_TYPE_PIM, mmi_syncml_checking_for_dm);
#endif

    mmi_syncml_init_regular_sync_notify_flag();
    
    g_mmi_syncml_cntx.sync_progress = 0xFF;

#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
    g_mmi_syncml_cntx.is_data_change_timeout = MMI_TRUE;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_main_menu
 * DESCRIPTION
 *  Synchronization main menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_main, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_syncml_entry_sync_main, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cbm_brearer_release
 * DESCRIPTION
 *  Release opened bearer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_cbm_brearer_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cbm_release_bearer(g_mmi_syncml_cntx.app_id[g_mmi_syncml_cntx.active_account - 1]);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cbm_brearer_display_popup
 * DESCRIPTION
 *  Release opened bearer and popup display screen
 * PARAMETERS
 *  MMI_ID_TYPE, mmi_event_notify_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_cbm_brearer_display_popup(MMI_ID_TYPE str_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_NCENTER_SUPPORT__)

	if(g_syncml_ncenter.noti_progressing != NULL)
	{
		mmi_syncml_ncenter_sync_bkg_destroy(); 
	}
	
	mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_TOTAL);
	mmi_syncml_ncenter_sync_unfinish_create(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
#endif 	

	mmi_syncml_cbm_brearer_release();
	
	mmi_syncml_restore_context();
	
	mmi_popup_display_simple(
		(WCHAR*)get_string(str_id), 
		event_type, 
		GRP_ID_ROOT, 
		NULL);
	
	mmi_frm_group_close(GRP_ID_SYNC_START);
	g_mmi_syncml_cntx.cbm_state = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cbm_brearer_disconn_callback
 * DESCRIPTION
 *  callbck function for cbm disconnection, only for diconn in connection management
 * PARAMETERS
 *  mmi_event_struct *param
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_cbm_brearer_disconn_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_info_struct *cbm_info = (srv_cbm_bearer_info_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	MMI_SYNCML_TRACE5(MMI_SYNCML_BEAR_CALLBACK_RESULT, cbm_info->account_id, cbm_info->state, cbm_info->error, cbm_info->error_cause, g_mmi_syncml_cntx.cbm_state);
	
    if (mmi_syncml_is_sync_now() && SRV_CBM_DISC_BY_CM == cbm_info->error)
    {
        mmi_syncml_abort_sync_req();
    }
	else
	{
		if (g_mmi_syncml_cntx.cbm_state == CBM_WOULDBLOCK)
		{		
			
			// check whether it is ok.
			if (g_mmi_syncml_cntx.abort_state == 1)
			{
				mmi_syncml_cbm_brearer_display_popup(STR_ID_SYNC_CANCELLED, MMI_EVENT_SUCCESS);
			}
			else if(cbm_info->state == SRV_CBM_DEACTIVATED)
			{
				mmi_syncml_cbm_brearer_display_popup(STR_ID_SYNC_DEFAULT_FAIL, MMI_EVENT_FAILURE);
			}
			else if (cbm_info->state == SRV_CBM_ACTIVATED)
			{
			#ifdef  __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#else
				mmi_syncml_start_sync_int();
			#endif
			}
			else
			{
				//
			}	
		}
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_sync_restore_warning
 * DESCRIPTION
 *  Pre-check function before start sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_syncml_sync_pre_check_is_successfull()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 account_index = g_mmi_syncml_cntx.selected_account;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* maybe there are some check fail, so create a new group first, if close precheck, edit group will be closed */
	mmi_frm_group_create(GRP_ID_SYNC_PRE_CHECK, GRP_ID_SYNC_EDIT, mmi_syncml_group_account_edit_proc, NULL);
	mmi_frm_group_enter(GRP_ID_SYNC_EDIT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_syncml_pre_read_account((U8)(account_index + 1));
    
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync() && 
        mmi_syncml_device_get_curr_role() == MMI_SYNCML_DEV_ROLE_B)
    {
        if (mmi_syncml_device_get_curr_state() == MMI_SYNCML_DEVICE_STATE_BT_CONNECTING)
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_SYNC_APP_SYNC_UNAVAILABLE), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);    
                
            mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
            return MMI_FALSE;
        }
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

    if ((g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
        && !mmi_syncml_is_phb_ready())
    {
        /* phonebook busy */            
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_PHB_BUSY), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);    
                    
        mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
        return MMI_FALSE;
    }

 #ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    /* BT sync needn't check the following condition */
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (g_mmi_syncml_cntx.transport_type[account_index] == MMI_SYNCML_TRANS_TYPE_INTERNET)
#endif
    {
        if (!wap_is_ready() 
#ifndef __MMI_WLAN_FEATURES__
            || !srv_nw_usab_any_sim_is_usable()
#endif
        )
        {
            /* wap not ready */
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_SYNC_WAP_NOT_READY), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
                
            mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
            return MMI_FALSE;
        }
    }

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

    /* 1 - server address check */
    if (!(g_mmi_syncml_cntx.account_validation[account_index] & MMI_SYNCML_ACCOUNT_VALID_MASK_SVR))
    {
        mmi_syncml_popup_display_with_proc(
            GRP_ID_SYNC_EDIT,
            (WCHAR *)get_string(STR_ID_SYNC_NO_SERVER_ADDR),
            MMI_EVENT_FAILURE, 
            mmi_syncml_no_server_addr_popup_proc, 
            NULL);
        
        return MMI_FALSE;
    }

    /* 2 - applications to sync check */
    if (g_mmi_syncml_cntx.app_to_sync[account_index] == 0)
    {        
        mmi_syncml_popup_display_with_proc(
            GRP_ID_SYNC_EDIT,
            (WCHAR *)get_string(STR_ID_SYNC_NO_APPLICATION),
            MMI_EVENT_FAILURE, 
            mmi_syncml_no_application_popup_proc, 
            NULL);
        
        return MMI_FALSE;
    }

    /* 3 - database setting check */
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    if (g_mmi_syncml_cntx.app_sync_menu == 0)
#endif
    {
        if (mmi_syncml_check_incomplete_database_setting(account_index) == MMI_FALSE)
        {
            return MMI_FALSE;   
        }
    }

#if 0  
/* under construction !*/
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
 
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_sync_now
 * DESCRIPTION
 *  Check function if email is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
void mmi_syncml_entry_sync_pre_check_return(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_syncml_cntx.is_pre_sync = 0;
    
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ 
    if (g_mmi_syncml_cntx.app_sync_menu)
    {
        mmi_syncml_app_sync_finish_hdlr(g_mmi_syncml_cntx.selected_account);
    }
#endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_sync_now
 * DESCRIPTION
 *  Check function if email is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_is_phb_sync_now() ||
        mmi_syncml_is_tdl_sync_now() ||
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        mmi_syncml_is_note_sync_now() ||
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__        
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
         MMI_FALSE)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_sync_aborting
 * DESCRIPTION
 *  Check function if phonebook is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_sync_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.abort_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_phb_ready
 * DESCRIPTION
 *  Check function if phonebook is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_phb_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL rtn = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_PHONEBOOK)
    {
        if (!srv_phb_startup_is_phb_ready() || mmi_phb_check_processing())
        {
            rtn = MMI_FALSE;
        }
    }
    return rtn;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_phb_sync_now
 * DESCRIPTION
 *  Notification to phonebook application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_phb_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.contact_sync_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_no_phb_addr_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_no_phb_addr_popup_proc(mmi_event_struct * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            if (MMI_POPUP_NORMAL_EXIT == evt->result)
            {
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_CONTACT_ADDR_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_db_contact, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);

			}
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_tdl_sync_now
 * DESCRIPTION
 *  Notification to to-do-list application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_tdl_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	if (g_mmi_syncml_cntx.calendar_sync_state)
	{
		return MMI_TRUE;
	}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	if (g_mmi_syncml_cntx.task_sync_state)
	{
		return MMI_TRUE;
	}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

	return MMI_FALSE;
}


#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_calendar_sync_now
 * DESCRIPTION
 *  Notification to to-do-list application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_calendar_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.calendar_sync_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_no_cal_addr_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_no_cal_addr_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    switch(evt->evt_id)
    {
	case EVT_ID_POPUP_QUIT:
        {
			if (MMI_POPUP_NORMAL_EXIT == evt->result)
			{   
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_CAL_ADDR_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_db_calendar, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);
            }
        }
    }
    return MMI_RET_OK;
}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */


#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_task_sync_now
 * DESCRIPTION
 *  Notification to to-do-list application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_task_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.task_sync_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_no_task_addr_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_no_task_addr_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            if (MMI_POPUP_NORMAL_EXIT == evt->result)
            {      
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_TASK_ADDR_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_db_task, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);
            }
            break;
        }
    }
    return MMI_RET_OK;
}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */


#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_note_sync_now
 * DESCRIPTION
 *  Notification to note application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_note_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.note_sync_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_no_note_addr_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_no_note_addr_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            if (MMI_POPUP_NORMAL_EXIT == evt->result)
            {   
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_NOTE_ADDR_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_db_note, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);
            }
            break;
        }
    }
    return MMI_RET_OK;
}
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */


#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*¡¡__MMI_SYNCML_BOOKMARK_SUPPORT__¡¡*/


#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */


/*****************************************************************************
* Local Function 
*****************************************************************************/
/* Local function can only be called within this .c file, it shall be declare 
 * as static */

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_main
 * DESCRIPTION
 *  Synchronization main menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    /* If device or pc sync, reject the entrance when connecting*/
    if (mmi_syncml_device_get_curr_state() == MMI_SYNCML_DEVICE_STATE_BT_CONNECTING ||
		(!mmi_syncml_is_sync_now() && mmi_syncml_device_is_connected()))
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);                
        return;
    }
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    /* If device sync is runing, forbidden */
    if (mmi_syncml_is_device_sync())
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);              
        return;
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

    if (mmi_syncml_is_sync_now())
    {
        mmi_syncml_group_entry_sync_start(GRP_ID_ROOT);
        return;
    }
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SYNC_MAIN, mmi_syncml_group_sync_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SYNC_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    /* maybe modify the account name by other app,(provisioning)*/
    mmi_syncml_read_account_name_display_strings();  

#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__   
    g_mmi_syncml_cntx.app_sync_menu = 0;
#endif    

    mmi_syncml_entry_sync_account_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_account_list
 * DESCRIPTION
 *  Synchronization account list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_account_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    menu_cui_gid = cui_menu_create(
                GRP_ID_SYNC_MAIN,
                CUI_MENU_SRC_TYPE_APPCREATE,
                CUI_MENU_TYPE_APPMAIN,
                MENU_ID_SYNCML_MAIN,
                MMI_FALSE,
                NULL);
        
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_init_data_from_nvram
 * DESCRIPTION
 *  Read name of accounts from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_read_init_data_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    U8 i, j, k;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS ; i++)
    {
        mmi_syncml_read_account_from_nvram((U8)(i + 1), (void *)temp_account);   

        /* account id is 0xff, set its default value */
        if (temp_account->account_id == 0xFF)
        {
            memset(temp_account, 0, sizeof(mmi_syncml_account_struct));
    
            temp_account->account_id = (i + 1);
            
            if (temp_account->transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
            {
                strcpy((CHAR*) temp_account->server_address, "http://");
            }
            strcpy((CHAR*) temp_account->contact_address, "./");
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
            strcpy((CHAR*) temp_account->calendar_address, "./");
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
            strcpy((CHAR*) temp_account->task_address, "./");
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
            strcpy((CHAR*) temp_account->note_address, "./");
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 

            for(j = 0; j<MMI_MAX_SIM_NUM; j++)
			{
                temp_account->net_id[j] = CBM_DEFAULT_ACCT_ID;   
			}

            temp_account->account_validation |= (MMI_SYNCML_ACCOUNT_VALID_MASK_NAME | MMI_SYNCML_ACCOUNT_VALID_MASK_CONN);

            mmi_syncml_write_account_to_nvram((U8)(i + 1), (void*)temp_account);
        }

        g_mmi_syncml_cntx.app_to_sync[i] = temp_account->app_to_sync;
        g_mmi_syncml_cntx.regular_sync[i] = temp_account->regular_sync;
        g_mmi_syncml_cntx.regular_sync_notify[i] = temp_account->regular_sync_notify;
        g_mmi_syncml_cntx.sas_flag[i] = temp_account->sas_flag;
        g_mmi_syncml_cntx.sync_type[i] = temp_account->sync_type;
        g_mmi_syncml_cntx.sync_report_status[i] = temp_account->sync_report_status;
        g_mmi_syncml_cntx.account_validation[i] = temp_account->account_validation;
        g_mmi_syncml_cntx.last_phb_anchor[i] = temp_account->last_phb_anchor;
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        g_mmi_syncml_cntx.last_cal_anchor[i] = temp_account->last_cal_anchor;
#endif
 
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        g_mmi_syncml_cntx.last_task_anchor[i] = temp_account->last_task_anchor;
#endif

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        g_mmi_syncml_cntx.last_note_anchor[i] = temp_account->last_note_anchor;
#endif

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        g_mmi_syncml_cntx.account_read_only[i] = temp_account->read_only;
#endif

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
        g_mmi_syncml_cntx.transport_type[i] = temp_account->transport_type;
#endif 
	
		for(k = 0; k < MMI_MAX_SIM_NUM; k++ )
    	{
			g_mmi_syncml_cntx.net_id[i][k] = temp_account->net_id[k];
    	}
    }/* for */

    OslMfree(temp_account);
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    mmi_syncml_device_read_nvram();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_account_name_display_strings
 * DESCRIPTION
 *  Read profile name display strings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
void mmi_syncml_read_account_name_display_strings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
    for (i = 0; i <MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        mmi_syncml_read_account_from_nvram((U8)(i + 1), (void *)temp_account);
        
        mmi_ucs2cpy((CHAR*) g_mmi_syncml_cntx.account_name_display[i], (CHAR*) temp_account->account_name);            
       
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		g_mmi_syncml_cntx.account_read_only[i] = temp_account->read_only;
#endif
    }	
    
    OslMfree(temp_account);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_no_server_addr_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_no_server_addr_popup_proc(mmi_event_struct * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            if (MMI_POPUP_NORMAL_EXIT == evt->result)
            {
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_SERVER_ADDR_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_server_setting, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);
            }
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_no_application_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_no_application_popup_proc(mmi_event_struct * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
			if (MMI_POPUP_NORMAL_EXIT == evt->result)
			{
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_APP_TO_SYNC_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_app_to_sync, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);
            }
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_dtcnt_list_check
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_dtcnt_list_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_syncml_check_data_account_ready(mmi_syncml_entry_account_dtcnt_list, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_invalid_dtcnt_popup_proc
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_invalid_dtcnt_popup_proc(mmi_event_struct * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt
        = (mmi_alert_result_evt_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
			if (MMI_POPUP_NORMAL_EXIT == evt->result)
			{
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_EDIT, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_DATA_ACCOUNT_QUREY), 
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_entry_account_dtcnt_list_check, 
                    mmi_frm_scrn_close_active_id, 
                    NULL);
            }
            break;
        }
      
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_check_incomplete_database_setting
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_syncml_check_incomplete_database_setting(U8 account_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
    {
        if (!(g_mmi_syncml_cntx.account_validation[account_index] & MMI_SYNCML_ACCOUNT_VALID_MASK_CON))
        {
            mmi_syncml_popup_display_with_proc(
                GRP_ID_SYNC_EDIT,
                (WCHAR *)get_string(STR_ID_SYNC_NO_CONTACT_ADDR),
                MMI_EVENT_FAILURE, 
                mmi_syncml_no_phb_addr_popup_proc, 
                NULL);
            
            return MMI_FALSE;
        }       
    }             
    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR)
    {
        if (!(g_mmi_syncml_cntx.account_validation[account_index] & MMI_SYNCML_ACCOUNT_VALID_MASK_CAL))
        {
            mmi_syncml_popup_display_with_proc(
                GRP_ID_SYNC_EDIT,
                (WCHAR *)get_string(STR_ID_SYNC_NO_CAL_ADDR),
                MMI_EVENT_FAILURE, 
                mmi_syncml_no_cal_addr_popup_proc, 
                NULL);
            
            return MMI_FALSE;
        }
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
    {
        if (!(g_mmi_syncml_cntx.account_validation[account_index] & MMI_SYNCML_ACCOUNT_VALID_MASK_TASK))
        {
            mmi_syncml_popup_display_with_proc(
                GRP_ID_SYNC_EDIT,
                (WCHAR *)get_string(STR_ID_SYNC_NO_TASK_ADDR),
                MMI_EVENT_FAILURE, 
                mmi_syncml_no_task_addr_popup_proc, 
                NULL);
            
            return MMI_FALSE;
        }
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_NOTE)
    {
        if (!(g_mmi_syncml_cntx.account_validation[account_index] & MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE))
        {
            mmi_syncml_popup_display_with_proc(
                GRP_ID_SYNC_EDIT,
                (WCHAR *)get_string(STR_ID_SYNC_NO_NOTE_ADDR),
                MMI_EVENT_FAILURE, 
                mmi_syncml_no_note_addr_popup_proc, 
                NULL);
            
            return MMI_FALSE;
        }
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_entry_sync_pre_check
 * DESCRIPTION
 *  PRE_CHECK group may be hung on SYNC_MAIN, APP_SYNC and ROOT group;
 *  it a temp group for check and will be close after sync is initiated;
 * PARAMETERS
 *  MMI_BOOL is_bt_sel  if need check bt device, only for PC SYNC
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_group_entry_sync_pre_check(mmi_id parent_id, MMI_BOOL is_bt_sel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 account_index = g_mmi_syncml_cntx.selected_account;
    MMI_BOOL is_success;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_group_create(parent_id, GRP_ID_SYNC_PRE_CHECK, mmi_syncml_group_sync_pre_check_proc, (void*)parent_id);
    mmi_frm_group_enter(GRP_ID_SYNC_PRE_CHECK, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (!mmi_syncml_is_sync_now())
    {
        g_mmi_syncml_cntx.is_pre_sync = 1;
        g_mmi_syncml_cntx.active_account = account_index + 1;
    }

    is_success = mmi_syncml_sync_pre_check_is_successfull();
    
    if(is_success)
    {
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
        if (is_bt_sel && g_mmi_syncml_cntx.transport_type[account_index] == MMI_SYNCML_TRANS_TYPE_BT)
        {
            mmi_syncml_pc_sync_entry_bt_select_cui(GRP_ID_SYNC_PRE_CHECK);
            return;
        }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        /* backup and restore related screen shoule hung on PRE_CHECK group */
        if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_BACKUP)
        {
            mmi_syncml_popup_sync_backup_warning();
            return;
        }
        if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_RESTORE)
        {
            mmi_syncml_popup_sync_restore_warning();
            return;
        }
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

        /**************************************************************************************/
        /**************************************************************************************/
        /* make sure entry_sync_start be called before group_close(GRP_ID_SYNC_PRE_CHECK),
         * or else, framework will smart close parent of GRP_ID_SYNC_PRE_CHECK when closing 
         * GRP_ID_SYNC_PRE_CHECK, then a failure will occur when group_create(GRP_ID_SYNC_START).
         * CMCC_PIM will fail to start. 
         */
        /* start sync */
        mmi_syncml_group_entry_sync_start(parent_id);
        mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
        /**************************************************************************************/
        /**************************************************************************************/
    }
    else
    {
        /* if check fail, will close group smart when close editor screen */
        mmi_syncml_entry_sync_pre_check_return(); 
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_lock_sync_db
 * DESCRIPTION
 *  Lock database duing open bear time;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
  *****************************************************************************/
static void mmi_syncml_lock_sync_db(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8	account_id;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	account_id = g_mmi_syncml_cntx.active_account - 1;
	
	if(g_mmi_syncml_cntx.app_to_sync[account_id] & SYNCML_DB_PHONEBOOK)
	{
		g_mmi_syncml_cntx.contact_sync_state = MMI_TRUE;
	}
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	if(g_mmi_syncml_cntx.app_to_sync[account_id] & SYNCML_DB_CALENDAR)
	{
		g_mmi_syncml_cntx.calendar_sync_state = MMI_TRUE;
	}
#endif

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	if(g_mmi_syncml_cntx.app_to_sync[account_id] & SYNCML_DB_TASK)
	{
		g_mmi_syncml_cntx.task_sync_state = MMI_TRUE;
	}
#endif

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	if(g_mmi_syncml_cntx.app_to_sync[account_id] & SYNCML_DB_NOTE)
	{
		g_mmi_syncml_cntx.note_sync_state = MMI_TRUE;
	}	
#endif

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

static void mmi_syncml_open_bear(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_account_struct *temp_account = NULL;
	
	U8 account_index = g_mmi_syncml_cntx.active_account - 1;
	srv_dtcnt_sim_type_enum sim_id;
	kal_uint32 net_id;
	kal_int8 cbm_ret;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	mmi_syncml_lock_sync_db();

	temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

	mmi_syncml_read_account_from_nvram((U8)(account_index + 1), (void*)temp_account);
	
    /* do not consider pc sync, another api to start sync for pc sync */

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
	srv_dtcnt_get_sim_preference(&sim_id);
	
    MMI_SYNCML_TRACE1(MMI_SYNCML_OPEN_BEAR_GET_SIM, sim_id);

	if(SRV_DTCNT_SIM_TYPE_NONE == sim_id)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}
	
    net_id = cbm_encode_data_account_id(
                            temp_account->net_id[sim_id - 1],                                                
                            (cbm_sim_id_enum)(sim_id - 1),                
                            g_mmi_syncml_cntx.app_id[account_index],                             
                            KAL_FALSE); 
	
	OslMfree(temp_account);

	cbm_ret = cbm_open_bearer(net_id);

	if (cbm_ret == CBM_WOULDBLOCK)
	{
		g_mmi_syncml_cntx.cbm_state = CBM_WOULDBLOCK;
	}
	else if (cbm_ret == CBM_OK)
	{
		mmi_syncml_start_sync_int();
	}
	else
	{
		mmi_syncml_restore_context();
		
		mmi_popup_display_simple(
						(WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
						MMI_EVENT_FAILURE, 
						GRP_ID_ROOT, 
						NULL);

		//TOOD: need close the screen group
		mmi_frm_group_close(GRP_ID_SYNC_START);

	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_entry_sync_start
 * DESCRIPTION
 *  "Sync Now" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_group_entry_sync_start(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_bear = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_group_create(parent_id, GRP_ID_SYNC_START, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_SYNC_START, MMI_FRM_NODE_SMART_CLOSE_FLAG);
       
#if defined(__MMI_NCENTER_SUPPORT__)
	mmi_syncml_ncenter_sync_reset();
#endif
	
	if (mmi_syncml_is_sync_now() && !mmi_syncml_is_sync_aborting())
    {
        mmi_syncml_entry_sync_now_scrn();
    }
    else if (mmi_syncml_is_sync_aborting())
    {
        mmi_syncml_entry_sync_abort_scrn();  
    }
    else
    {
        mmi_syncml_entry_sync_now_scrn();

#ifdef __MMI_SYNCML_DEVICE_SYNC__
		if (mmi_syncml_is_device_sync())
		{
			need_bear = MMI_FALSE;
		}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
		if (mmi_syncml_is_pc_sync())
		{
			need_bear = MMI_FALSE;
		}
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

		// start sync	
		if (need_bear)
		{
			mmi_syncml_open_bear();
		}
		else
		{ 
        mmi_syncml_start_sync_int();
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_now_scrn
 * DESCRIPTION
 *  only used to show "synchronizing" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_now_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 title_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_START,
            SCR_ID_SYNC_NOW, 
            NULL, 
            mmi_syncml_entry_sync_now_scrn, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    /* sync haven't begain yet */
    if (g_mmi_syncml_cntx.sync_progress == 0xFF)
    {
        mmi_ucs2cpy(g_syncml_sync_info, GetString(STR_ID_SYNC_PROGRESS));
    }
    else
    {
        mmi_ucs2cpy(g_syncml_sync_info, GetString((U16) (STR_ID_PROGRESS_LINK_ESTABLISHED + g_mmi_syncml_cntx.sync_progress)));
        mmi_syncml_cat_progress_count_string(g_mmi_syncml_cntx.sync_progress);
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    title_icon = (PU8)GetImage(GetRootTitleIcon(MENU_ID_SYNCML_MAIN));
#endif

    ShowCategory366Screen(
        (UI_string_type) GetString(STR_ID_SYNC_PROGRESS),
        title_icon,
        (UI_string_type) GetString(STR_ID_SYNC_MINIMIZE),
        0,
        (UI_string_type) GetString(STR_GLOBAL_CANCEL), /* STR_GLOBAL_ABORT, */
        0, /* IMG_ID_NETSET_ABORT_LSK, */
        (UI_string_type) g_syncml_sync_info,
        IMG_ID_SYNC_NOW,
        NULL);

    SetLeftSoftkeyFunction(mmi_syncml_go_back_background_sync, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_entry_sync_abort, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_syncml_go_back_background_sync, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_start_sync_int
 * DESCRIPTION
 *  Update progress info of synchronization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_start_sync_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_init_sync_report();
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (mmi_syncml_is_device_sync())
    {
        g_mmi_syncml_cntx.is_dev_log = MMI_TRUE;
   
        if (MMI_SYNCML_DEV_ROLE_B == mmi_syncml_device_get_curr_role())
    	{
            /* all the databases has been locked when accept the connection.*/
            mmi_syncml_device_lock_all_db();
            mmi_syncml_device_remoteinfo_ind_res(g_mmi_syncml_common_cntx.imei, MMI_SYNCML_DEV_SYNC_ACCEPT);
    	}
        else
        {
            mmi_syncml_device_init_anchor();
            mmi_syncml_get_imei_req();
        }
        return;
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync() && 
        mmi_syncml_device_get_curr_role()== MMI_SYNCML_DEV_ROLE_B)
	{    
        g_mmi_syncml_common_cntx.is_state_reset = MMI_FALSE;
        
	    /* now don't know app_to_sync as role B */
        mmi_syncml_device_lock_all_db();
        mmi_syncml_pc_sync_remoteinfo_ind_res(g_mmi_syncml_common_cntx.imei, MMI_SYNCML_DEV_SYNC_ACCEPT);
	    return;
	}
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

    mmi_syncml_sync_now_init_anchor();   
    mmi_syncml_get_imei_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_abort_scrn
 * DESCRIPTION
 *  entry "cancelling" screen, only for scrn 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_abort_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
	U16 title_icon;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
        if (!mmi_frm_scrn_enter(
                GRP_ID_SYNC_START, 
                SCR_ID_SYNC_ABORT, 
                NULL, 
            mmi_syncml_entry_sync_abort_scrn, 
                MMI_FRM_FULL_SCRN))
        {
            return;
        }

        image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    title_icon = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

        ShowCategory66Screen(
            STR_GLOBAL_CANCELLING,
            title_icon,
            0,
            0,
            0,
            0,
            (U8*) GetString(STR_GLOBAL_CANCELLING),
            image_id,
            NULL);
    
        SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_abort
 * DESCRIPTION
 *  abort sync on syncing screen by pressing RSK cancel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	MMI_SYNCML_TRACE0(MMI_SYNCML_ENTRY_ABORT);

	if ( (!g_mmi_syncml_cntx.is_sync_state)
#ifdef __MMI_SYNCML_DEVICE_SYNC__		
		&&(!mmi_syncml_is_device_sync())
#endif 
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
		&&(!mmi_syncml_is_pc_sync())
#endif 		
		)
	{
		mmi_syncml_cbm_brearer_display_popup(STR_ID_SYNC_CANCELLED, MMI_EVENT_SUCCESS);
		return;
	}

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    {
        mmi_syncml_entry_sync_abort_scrn();
        
        mmi_frm_scrn_close(GRP_ID_SYNC_START, SCR_ID_SYNC_NOW);

        mmi_syncml_abort_sync_req();   
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_update_progress_string
 * DESCRIPTION
 *  Update progress info of synchronization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_update_progress_string(U8 info_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_is_sync_now())
    {
        g_mmi_syncml_cntx.sync_progress = info_number;
        
        mmi_ucs2cpy(g_syncml_sync_info, GetString((U16) (STR_ID_PROGRESS_LINK_ESTABLISHED + info_number)));

	    mmi_syncml_cat_progress_count_string(info_number);

        /* no need to update screen if active screen is not "sync now" screen */
        if (mmi_frm_scrn_get_active_id() == SCR_ID_SYNC_NOW)
        {
            wgui_cat366_update_progress_string();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cat_progress_count_string
 * DESCRIPTION
 *  make progress count string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_cat_progress_count_string(U8 info_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[32];
    U16 current = 0, noc = 0;
    U8 progress_f = 0; /* flag for whether to show NOC info */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (info_number)
    {
        case PROGRESS_CONTACT_DATASTORE_SENDING:
            current = g_mmi_syncml_cntx.contact_send_current;
            noc = g_mmi_syncml_cntx.contact_send_noc;
            progress_f = 1;
            break;
			
        case PROGRESS_CONTACT_DATASTORE_RECEIVED:
            current = g_mmi_syncml_cntx.contact_recv_current;
            noc = g_mmi_syncml_cntx.contact_recv_noc;
            progress_f = 1;
            break;
			
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        case PROGRESS_CALENDAR_DATASTORE_SENDING:
            current = g_mmi_syncml_cntx.calendar_send_current;
            noc = g_mmi_syncml_cntx.calendar_send_noc;
            progress_f = 1;
            break;
			
        case PROGRESS_CALENDAR_DATASTORE_RECEIVED:
            current = g_mmi_syncml_cntx.calendar_recv_current;
            noc = g_mmi_syncml_cntx.calendar_recv_noc;
            progress_f = 1;
            break;
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        case PROGRESS_TASK_DATASTORE_SENDING:
            current = g_mmi_syncml_cntx.task_send_current;
            noc = g_mmi_syncml_cntx.task_send_noc;
            progress_f = 1;
            break;
			
        case PROGRESS_TASK_DATASTORE_RECEIVED:
            current = g_mmi_syncml_cntx.task_recv_current;
            noc = g_mmi_syncml_cntx.task_recv_noc;
            progress_f = 1;
            break;
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        case PROGRESS_NOTE_DATASTORE_SENDING:
            current = g_mmi_syncml_cntx.note_send_current;
            noc = g_mmi_syncml_cntx.note_send_noc;
            progress_f = 1;
            break;
			
        case PROGRESS_NOTE_DATASTORE_RECEIVED:
            current = g_mmi_syncml_cntx.note_recv_current;
            noc = g_mmi_syncml_cntx.note_recv_noc;
            progress_f = 1;
            break;
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
		
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
		
        default:
            break;
    }
    
	
    if (progress_f == 1)
    {
        if (current <= noc)
        {
            kal_wsprintf((PU16)temp, " %d/%d", current, noc);
            mmi_ucs2cat((CHAR*)g_syncml_sync_info, (CHAR*)temp);
        }
        else
        {
            kal_wsprintf((PU16)temp, " %d", current);
            mmi_ucs2cat((CHAR*)g_syncml_sync_info, (CHAR*)temp);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_hide_sync_menu
 * DESCRIPTION
 *  Hide sync menu when filght mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_hide_sync_menu(MMI_BOOL hide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (hide)
	{
#ifdef __MMI_BT_SUPPORT__
        /* If BT don't support in flight mode */
		if (!mmi_bt_is_to_display_bt_menu())
		{
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			mmi_frm_hide_menu_item(MENU_ID_SYNCML_DEV_MAIN);
#endif 
    		/* If pc sync, it can still sync via*/
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_SYNCML_MAIN);
#endif 
		}
#endif /*__MMI_BT_SUPPORT__ */

		/* If not support pc sync, hide this menu directly */
#ifndef __MMI_SYNCML_PC_SYNC_SUPPORT__
		mmi_frm_hide_menu_item(MENU_ID_SYNCML_MAIN);
#endif 
		
	}
	else /* unhide */
	{
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        if (mmi_frm_test_menu_item_hide(MENU_ID_SYNCML_DEV_MAIN))
        {
		    mmi_frm_unhide_menu_item(MENU_ID_SYNCML_DEV_MAIN);
        }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
        if (mmi_frm_test_menu_item_hide(MENU_ID_SYNCML_MAIN))
        {
		    mmi_frm_unhide_menu_item(MENU_ID_SYNCML_MAIN);
        }
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_go_back_background_sync
 * DESCRIPTION
 *  Go back history and keep background sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_go_back_background_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_NCENTER_SUPPORT__)	

	if( MMI_TRUE  
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)	
		&& !mmi_syncml_is_device_or_pc_sync()
#endif		
		)
	{
	    mmi_syncml_ncenter_sync_bkg_create(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
	}
	else		
	{
		mmi_syncml_ncenter_sync_bkg_create(MMI_SYNCML_NOTIFICATION_SYNC_DEVICE);
	}
	
#endif
	
    gid = mmi_frm_group_get_top_parent_group_id(GRP_ID_SYNC_START);

    /* if parent group of group start is ROOT */
    if (gid == GRP_ID_SYNC_START)
    {
        mmi_frm_group_close(gid);
    }
    /* maybe SYNC_MAIN/APP_SYNC/DEVICE_MAIN group */
    else
    {
        mmi_syncml_group_post_evt_to_parent(GRP_ID_SYNC_START, EVT_ID_SYNC_MINIMIZE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_pre_sync_now
 * DESCRIPTION
 *  handle PC sync if connection type for actived profile if BLUETOOTH
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static void mmi_syncml_sync_now_init_anchor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U8 account_index = g_mmi_syncml_cntx.active_account - 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    /* only A can init anchor */
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
    {
        g_mmi_syncml_cntx.regular_sync_notify[account_index] &= ~MMI_SYNCML_PHB_DATA_CHANGE;
        g_mmi_syncml_cntx.next_phb_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index] + 1;
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR)
    {
        g_mmi_syncml_cntx.regular_sync_notify[account_index] &= ~MMI_SYNCML_CALENDAR_DATA_CHANGE;
        g_mmi_syncml_cntx.next_cal_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index] + 1;
    }
    
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
    {
        g_mmi_syncml_cntx.regular_sync_notify[account_index] &= ~MMI_SYNCML_TASK_DATA_CHANGE;
        g_mmi_syncml_cntx.next_task_anchor = g_mmi_syncml_cntx.last_task_anchor[account_index] + 1;
    }        
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_NOTE)
    {
        g_mmi_syncml_cntx.regular_sync_notify[account_index] &= ~MMI_SYNCML_NOTE_DATA_CHANGE;
        g_mmi_syncml_cntx.next_note_anchor = g_mmi_syncml_cntx.last_note_anchor[account_index] + 1;
    }        
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (!mmi_syncml_is_pc_sync())
#endif
    {
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */ 
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_disable_alarm
 * DESCRIPTION
 *  Disable alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_disable_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_alarm_disable_status)
    {
        srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_FALSE);
        mmi_syncml_alarm_disable_status = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_enable_alarm
 * DESCRIPTION
 *  Enable alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_enable_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_alarm_disable_status)
    {
        srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_TRUE);
        mmi_syncml_alarm_disable_status = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_phb_ready_inner
 * DESCRIPTION
 *  Check function if phonebook is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_phb_ready_inner(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL rtn = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_phb_startup_is_phb_ready() || mmi_phb_check_processing())
    {
        rtn = MMI_FALSE;
    }
    
    return rtn;
}


#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_delete_all_records
 * DESCRIPTION
 *  Entry screen to delete all records
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_delete_all_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_PRE_CHECK,
            SCR_ID_SYNC_DELETE_ALL,
            NULL,
            mmi_syncml_entry_delete_all_records,
            MMI_FRM_UNKNOW_SCRN))
    {
        return;      
    }
    
    ShowCategory66Screen(
        STR_ID_SYNC_PROGRESS,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN),
        0,
        0,
        0,
        0,
        (U8 *) GetString(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_perform_delete_phb_one_by_one
 * DESCRIPTION
 *  Delete phonebook records one by one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_perform_delete_phb_one_by_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_count;
    mmi_id parent_id;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__    
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_count = srv_phb_sync_get_index_array(g_syncml_temp_luid, MAX_SYNC_ITEMS);

    /* if no phb need be deleted, we start to delete email */
    if (temp_count == 0)
    {
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */ 

            /* no phb and email need be deleted; */
            parent_id = (mmi_id)(U32)mmi_frm_group_get_user_data(GRP_ID_SYNC_PRE_CHECK);

            /* the parent_id may be ROOT/SYNC_MAIN/APP_SYNC group */
            mmi_syncml_group_entry_sync_start(parent_id);   
            mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
            
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__	
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */ 

    }
    
    else
    {
        srv_phb_sync_vcard(SYNCML_RECORD_DELETE, (U16 *) SYNCML_VOBJ_PATH, g_syncml_temp_luid[0], 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_backup_warning_yes
 * DESCRIPTION
 *  Query screen to start backup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_backup_warning_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_group_entry_sync_start((mmi_id)(U32)mmi_frm_group_get_user_data(GRP_ID_SYNC_PRE_CHECK));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_refresh_sync_cancel
 * DESCRIPTION
 *  Query screen to start backup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_refresh_sync_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_sync_backup_warning
 * DESCRIPTION
 *  Query screen to start backup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_popup_sync_backup_warning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_SYNC_PRE_CHECK, 
        (WCHAR*)get_string(STR_ID_SYNC_BACKUP_WARNING), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_entry_sync_backup_warning_yes, 
        mmi_frm_scrn_close_active_id, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_sync_restore_warning
 * DESCRIPTION
 *  Query screen to start restore
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_popup_sync_restore_warning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_SYNC_PRE_CHECK, 
        (WCHAR*)get_string(STR_ID_SYNC_BACKUP_WARNING), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_perform_delete_all_records, 
        mmi_frm_scrn_close_active_id, 
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_perform_delete_all_records
 * DESCRIPTION
 *  Delete phonebook and to-do-list records
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_perform_delete_all_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *fs_path;
    U16 temp_count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_entry_delete_all_records();

    /* for calendar/task/bookmark/note, will delete all data synchronously */
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    /* delete all calendars */
    if (g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_CALENDAR)
    {
        fs_path = OslMalloc(sizeof(SYNCML_CAL_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_CAL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_CAL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_mmi_syncml_cntx.active_account;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        temp_count = mmi_tdl_get_total_cal_index(g_syncml_temp_luid);
        for (i = 0; i < temp_count; i++)
        {
            mmi_tdl_sync_vevent(SYNCML_RECORD_DELETE, (CHAR*) SYNCML_VOBJ_PATH, &g_syncml_temp_luid[i], 0);
        }
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	/* Task sync */
    if (g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_TASK)
    {
        fs_path = OslMalloc(sizeof(SYNCML_TASK_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_TASK_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_mmi_syncml_cntx.active_account;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        temp_count = mmi_tdl_get_total_task_index(g_syncml_temp_luid);
        for (i = 0; i < temp_count; i++)
        {
            mmi_tdl_sync_vtodo(SYNCML_RECORD_DELETE, (CHAR*) SYNCML_VOBJ_PATH, &g_syncml_temp_luid[i], 0);
        }
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */   
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	/* Note sync */
    if (g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_NOTE)
    {
        fs_path = OslMalloc(sizeof(SYNCML_NOTE_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_NOTE_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_NOTE_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_mmi_syncml_cntx.active_account;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        temp_count = mmi_note_get_total_record_index_array(g_syncml_temp_luid);
        for (i = 0; i < temp_count; i++)
        {
            mmi_note_sync_pnote(SYNCML_RECORD_DELETE, (CHAR*) SYNCML_VOBJ_PATH, &g_syncml_temp_luid[i], 0);
        }
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNC_BOOKMARK_SUPPORT__ */

    /* for phb and email, will delete all data asynchronously */
    /* so we delete phb one by one firstly and then delete email one by one */

    /* for async database, delete all contacts, performed one by one */
    if (g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_PHONEBOOK)
    {
        fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH));
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_mmi_syncml_cntx.active_account;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        mmi_syncml_perform_delete_phb_one_by_one();
    }
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */ 
    else
    {
        mmi_syncml_group_entry_sync_start((mmi_id)(U32)mmi_frm_group_get_user_data(GRP_ID_SYNC_PRE_CHECK));
        mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
    }
}
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */


#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_status_icon
 * DESCRIPTION
 *  Whether show sync status icon
 * PARAMETERS
 *  status      [IN]      True:show     false:hide
 * RETURNS
 *  pBOOL
 *****************************************************************************/
void mmi_syncml_set_status_icon(MMI_BOOL status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (status == MMI_TRUE)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SYNCML);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SYNCML);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SYNCML);  
    }
    
    wgui_status_icon_bar_update();  
}
#endif /* __MMI_SYNCML_STATUS_ICON_SUPPORT__ */


#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__  
/*****************************************************************************
 * FUNCTION
 *  cui_syncml_app_sync_create
 * DESCRIPTION
 *  app sync create function
 * PARAMETERS
 *  parent_id           [IN]        parent group id
 *  app_type            [IN]        App type that sync menu enter    
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_id cui_syncml_app_sync_create(mmi_id parent_id, U8 app_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Check whether other app database is syncing or not*/
    if (mmi_syncml_is_sync_now())
    { 
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);         
        return g_id; 
    }    
   
    /* If device sync, then reject the entrance */
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    if (mmi_syncml_is_device_or_pc_sync())
    {
        /* Don't popup at this moment */
        if (mmi_syncml_device_get_curr_state() == MMI_SYNCML_DEVICE_STATE_BT_CONNECTING)
        {
            return g_id;
        }
            
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);         
        return g_id;
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

    if ((app_type == MMI_SYNCML_PHB_SYNC_MENU)&&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 
        || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        )
    {
        /* avoid app entry sync in calling */ 
         mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);       
        return g_id;
    } 
	
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif	
    g_id = mmi_frm_group_create(parent_id, GRP_ID_SYNC_APP_SYNC, cui_syncml_app_sync_proc, (void*)app_type);
    
    return g_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_syncml_app_sync_run
 * DESCRIPTION
 *  app sync cui run funtion
 * PARAMETERS
 *  cui_gid            [IN]        ths cui group_id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void cui_syncml_app_sync_run(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if (GRP_ID_INVALID == cui_gid)
    {
        return;
    }

    /* avoid select_account variable confusion */
    mmi_frm_group_close(GRP_ID_SYNC_MAIN);

    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* When first enter, highlight the first accout */
    g_mmi_syncml_cntx.selected_account = 0;

    mmi_syncml_app_sync_entry_account_list(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_syncml_app_sync_close
 * DESCRIPTION
 *  app sync cui close
 * PARAMETERS
 *  mmi_id          [IN]       group id will be closed
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void cui_syncml_app_sync_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (GRP_ID_INVALID == cui_gid)
    {
        cui_gid = GRP_ID_SYNC_APP_SYNC;
    }
    
    mmi_frm_group_close(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_syncml_app_sync_proc
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  evt            [IN]        event structure
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret cui_syncml_app_sync_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (g_mmi_syncml_cntx.app_sync_menu && !mmi_syncml_is_sync_now())
            {
                mmi_syncml_entry_sync_pre_check_return();
                g_mmi_syncml_cntx.app_sync_menu = 0;
            }
            break;
        case EVT_ID_SYNC_MINIMIZE:
            {
                mmi_syncml_group_post_evt_to_parent(
                    GRP_ID_SYNC_APP_SYNC,
                    EVT_ID_SYNC_MINIMIZE,
                    NULL);
                break;
            }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                mmi_syncml_app_sync_read_account();
                cui_syncml_app_sync_menu_cui_entry_evt_hdlr(param);
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct* evt = (cui_menu_event_struct *)param;
                g_mmi_syncml_cntx.selected_account = (U8)(g_mmi_syncml_cntx.valid_acct_id_array[evt->highlighted_menu_id] - 1);   
                mmi_syncml_app_sync_entry_sync_pre_check();
                break;
            }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct* evt = (cui_menu_event_struct *)param;
                cui_menu_close(evt->sender_id);
                break;
            }
        default:
            break;
    }

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_syncml_app_sync_menu_cui_entry_evt_hdlr
 * DESCRIPTION
 *  Callback function whether display the app sync menu 
 * PARAMETERS
 *  app_type            [IN]        App type that sync menu enter    
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void cui_syncml_app_sync_menu_cui_entry_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_MAX_SYNCML_ACCOUNTS];
    mmi_menu_id i = 0;
    cui_menu_event_struct *evt = (cui_menu_event_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_PROFILE),
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );
    
    for (i = 0; i < g_mmi_syncml_cntx.valid_acct_num; i++)
    {
        list_of_ids[i] = i;
    }

    cui_menu_set_currlist(evt->sender_id, g_mmi_syncml_cntx.valid_acct_num, list_of_ids);
 
    for (i = 0; i < g_mmi_syncml_cntx.valid_acct_num; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            list_of_ids[i], 
            (WCHAR*)g_mmi_syncml_cntx.account_name_display[i]);   
    }

    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    /* always highlight the first account when first enter account list screen */
    cui_menu_set_currlist_highlighted_id(evt->sender_id, list_of_ids[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_app_sync_is_display
 * DESCRIPTION
 *  Callback function whether display the app sync menu 
 * PARAMETERS
 *  app_type            [IN]        App type that sync menu enter    
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_app_sync_is_display(U8 app_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    MMI_BOOL is_display_sync_menu = MMI_FALSE;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* check whether to show sync menu on bt and flight mode senario */
#ifdef __MMI_BT_SUPPORT__
    if (!mmi_bt_is_to_display_bt_menu())
    { 
        return MMI_FALSE; 
    }
    else
    {
        is_display_sync_menu = MMI_TRUE;
    }
#else /* __MMI_BT_SUPPORT__ */
     /* if flight mode */
    if (!srv_mode_switch_is_network_service_available())
    {
        return MMI_FALSE;
    }
    else
    {
        is_display_sync_menu = MMI_TRUE;
    }
#endif /*__MMI_BT_SUPPORT__ */

    /* fetch account list */
    g_mmi_syncml_cntx.valid_acct_num = 0;

    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        mmi_syncml_read_account_from_nvram((U8)(i + 1), temp_account);
        
		/* check server setting, including server add,username,password */
        if (!(temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_SVR))
        {
            continue;
        }
        if ((temp_account->server_username[0] == 0) || (temp_account->server_password[0] == 0))
        {
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
            if (temp_account->transport_type != MMI_SYNCML_TRANS_TYPE_BT)
#endif
            {
                continue;
            }          
        }
        /* check specified database settings */
        if (!(temp_account->app_to_sync & app_type))
        {
            continue;               
        }
        else
        {
            if (!(temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_CON))
            {
                continue;
            }
        }
        /* check connection settings */
        if (!(temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_CONN))
        {
            if (temp_account->transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
            {
                continue;
            }
        }  
        /* valid account */
        g_mmi_syncml_cntx.valid_acct_id_array[g_mmi_syncml_cntx.valid_acct_num++] = i + 1;   
    }  
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_APP_SYNC_VALID_ACCT_NUM, g_mmi_syncml_cntx.valid_acct_num);

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }
    
    if (is_display_sync_menu && g_mmi_syncml_cntx.valid_acct_num)
    {
        return MMI_TRUE;      
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_app_sync_account_highlight_handler
 * DESCRIPTION
 *  This function is called by phb sync menu to enter SyncML
 * PARAMETERS
 *  app_type            [IN]        App type that sync menu enter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_app_sync_account_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_syncml_cntx.selected_account = (U8)(g_mmi_syncml_cntx.valid_acct_id_array[index] - 1);   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_app_sync_read_account
 * DESCRIPTION
 *  read account name list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_app_sync_read_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    U8 account_id;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
    for (i = 0; i < g_mmi_syncml_cntx.valid_acct_num; i++)
    {
        account_id = g_mmi_syncml_cntx.valid_acct_id_array[i];

        mmi_syncml_read_account_from_nvram(account_id, (void *)temp_account);        
     
        mmi_ucs2cpy((CHAR*) g_mmi_syncml_cntx.account_name_display[i], (CHAR*) temp_account->account_name);

        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_APP_SYNC_VALID_ACCT_ID, account_id);        
    }  
    
    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_restore_factory_default
 * DESCRIPTION
 *  Callback function restore other data related syncml MMI 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_app_sync_entry_account_list(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/  
    menu_cui_gid = cui_menu_create(
                        cui_gid, 
                        CUI_MENU_SRC_TYPE_APPCREATE, 
                        CUI_MENU_TYPE_APPMAIN, 
                        MENU_ID_PHB_SYNC, 
                        MMI_FALSE, 
                        NULL);

    cui_menu_run(menu_cui_gid);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_app_sync_entry_sync_pre_check
 * DESCRIPTION
 *  pre check for entry sync pre check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_app_sync_entry_sync_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 acount_id = g_mmi_syncml_cntx.selected_account;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_mmi_syncml_cntx.app_sync_menu = (U8)(U32)mmi_frm_group_get_user_data(GRP_ID_SYNC_APP_SYNC);
    
    g_mmi_syncml_cntx.temp_application_to_sync =  g_mmi_syncml_cntx.app_to_sync[acount_id];
    
    g_mmi_syncml_cntx.app_to_sync[acount_id] = g_mmi_syncml_cntx.app_sync_menu;
    
    mmi_syncml_group_entry_sync_pre_check(GRP_ID_SYNC_APP_SYNC, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_app_sync_finish_hdlr
 * DESCRIPTION
 *  app sync finish handler, should be called at three site
 *  1-sync unfinish and no sync report
 *  2-sync report deletion callback  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_app_sync_finish_hdlr(U8 account_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_APP_SYNC_FINISH_HDLR, account_index, g_mmi_syncml_cntx.app_to_sync[account_index], g_mmi_syncml_cntx.temp_application_to_sync);
    
    g_mmi_syncml_cntx.app_to_sync[account_index] 
        = g_mmi_syncml_cntx.temp_application_to_sync;
}
#endif /*__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__*/


#ifdef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_restore_factory_default
 * DESCRIPTION
 *  Callback function restore other data related syncml MMI 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_restore_factory_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *fs_path;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_syncml_is_sync_now())
    {
        mmi_syncml_abort_sync_req();
    }

    fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH));
   
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        mmi_ucs2cpy((CHAR*)fs_path, (CHAR*)SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + i;
        FS_Delete((U16*)fs_path);
    }

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        mmi_ucs2cpy((CHAR*)fs_path, (CHAR*)SYNCML_TASK_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + i;
        FS_Delete((U16*)fs_path);
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        mmi_ucs2cpy((CHAR*)fs_path, (CHAR*)SYNCML_NOTE_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_NOTE_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + i;
        FS_Delete((U16*)fs_path);
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        mmi_ucs2cpy((CHAR*)fs_path, (CHAR*)SYNCML_CAL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_CAL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + i;
        FS_Delete((U16*)fs_path);
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    OslMfree(fs_path);  
}
#endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */


#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_shutdown_callback
 * DESCRIPTION
 *  Callback for to-do-list record changed, for timer power off 
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_syncml_shutdown_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
	U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
	for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
	{
		if (g_mmi_syncml_cntx.regular_sync_notify[i] != 0)      
		{    
			mmi_syncml_read_account_from_nvram((U8)(i + 1), (void*)temp_account);
			temp_account->regular_sync_notify = g_mmi_syncml_cntx.regular_sync_notify[i];
			mmi_syncml_write_account_to_nvram((U8)(i + 1), (void*)temp_account);
		}
	}
    
    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }
	
	return MMI_RET_OK;
}
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
mmi_ret mmi_syncml_scrn_evt_handler(mmi_event_struct *evt)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
	mmi_scr_locker_pre_lock_evt_struct *lock_event;

  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:

			lock_event = (mmi_scr_locker_pre_lock_evt_struct *)evt;
			
			if(!mmi_syncml_is_sync_now())
			{
				break;	
			}
			
			if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
			{		
				return MMI_RET_ERR;
			}
			
			else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
			{
				return MMI_RET_OK;
			}
			break;
			
		default:
			break;
	}

	return MMI_RET_OK;
}
#endif
static void mmi_syncml_remote_reset_netid(U32 accnt_id, cbm_sim_id_enum cbm_sim_id)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
    mmi_syncml_account_struct *accnt;
    U32 new_netid;
      
  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/
    // encode the net_id as default net id.
    
    
    new_netid = cbm_encode_data_account_id(
    					CBM_DEFAULT_ACCT_ID,
    					cbm_sim_id,
    					g_mmi_syncml_cntx.app_id[accnt_id],
    					KAL_FALSE);

    // update the accnt infomation
    accnt = (mmi_syncml_account_struct *)OslMalloc(NVRAM_EF_SYNCML_ACCOUNT_SIZE);
	
    mmi_syncml_read_account_from_nvram(accnt_id + 1, accnt);

	accnt->net_id[cbm_sim_id] = new_netid;
	mmi_syncml_write_account_to_nvram(accnt_id + 1, accnt);
	
    OslMfree(accnt);
	
}

static void mmi_syncml_accnt_check_netid(U32 accnt_id)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
    U32 i, j;
    
  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/
    for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
    {          
		for(j = 0; j < MMI_MAX_SIM_NUM; j++)
		{
		    if (g_mmi_syncml_cntx.net_id[i][j] == INVALID_NETID)
            {
			    continue;
            }
        
        	if (accnt_id == (U32)cbm_get_original_account(g_mmi_syncml_cntx.net_id[i][j]))
            {
            	MMI_SYNCML_TRACE2(MMI_SYNCML_CHECK_NETID, accnt_id, g_mmi_syncml_cntx.net_id[i][j]);
				kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_2, "mmi_syncml_accnt_check_netid(): profile is %d, sim id is %d.", i, j);
            	mmi_syncml_remote_reset_netid(i, cbm_get_sim_id(g_mmi_syncml_cntx.net_id[i][j]));
        	}

        }
    }
}


static mmi_ret mmi_syncml_accnt_dtcnt_del_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_dtcnt_acct_delete_ind_evt_struct *dtcnt_evt;
	dtcnt_evt = (srv_dtcnt_acct_delete_ind_evt_struct *)evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	MMI_SYNCML_TRACE1(MMI_SYNC_SRV_RMT_EVT_DEL_NOTIFY, dtcnt_evt->del_num);
	
  	if ((dtcnt_evt != NULL) &&
		(dtcnt_evt->del_num != 0) && 
		((dtcnt_evt->cause == 0) || (dtcnt_evt->cause == 1)))
	{
  		U32 i;
		
		for (i = 0; i < dtcnt_evt->del_num; i++)
		{
            mmi_syncml_accnt_check_netid(dtcnt_evt->acc_id[i]);
		}
	}

	return MMI_RET_OK;
}


static mmi_ret mmi_syncml_accnt_dtcnt_update_notify(mmi_event_struct *evt)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
  	srv_dtcnt_acct_update_ind_evt_struct *dtcnt_evt;
  	dtcnt_evt = (srv_dtcnt_acct_update_ind_evt_struct *)evt;
  	
  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/  	 	
  	if ((dtcnt_evt != NULL) && (dtcnt_evt->cause == 1))
  	{	
        mmi_syncml_accnt_check_netid(dtcnt_evt->acc_id);  		
	}

	return MMI_RET_OK;
}


mmi_ret mmi_syncml_accnt_evt_handlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
		case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
		{
			mmi_syncml_accnt_dtcnt_del_notify(evt);
			break;
		}
		case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
		{
			mmi_syncml_accnt_dtcnt_update_notify(evt);
			break;
		}
		default:
			break;
	}
	
	return MMI_RET_OK;
}

#if defined(__MMI_NCENTER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_reset
 * DESCRIPTION
 *  reset notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_syncml_ncenter.noti_progressing != NULL)
	{
		mmi_syncml_ncenter_sync_bkg_destroy(); 
	}

	if(g_syncml_ncenter.noti_unfinished != NULL)
	{
		if(
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)	
		mmi_syncml_is_device_or_pc_sync() || 
#endif	
		MMI_FALSE)
		{
			mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_DEVICE);
		}
		else
		{
			mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_finish
 * DESCRIPTION
 *  sync finish, reset bkg noti and create unfinish noti if unfinish
 * PARAMETERS
 *  mmi_syncml_finish_sync_ind_struct *local_data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_finish(mmi_syncml_finish_sync_ind_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_syncml_ncenter_sync_bkg_destroy(); 

	if(SYNCML_GET_SYNC_STATUS(local_data->result) == SYNCML_OK)
	{
		return;
	}

	mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_TOTAL);
	
	if(
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)	
		mmi_syncml_is_device_or_pc_sync() ||
#endif	
		 MMI_FALSE)
	{
		mmi_syncml_ncenter_sync_unfinish_create(MMI_SYNCML_NOTIFICATION_SYNC_DEVICE);
	}
	else
	{
		mmi_syncml_ncenter_sync_unfinish_create(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_bkg_create
 * DESCRIPTION
 *  background sync, create notification
 * PARAMETERS
 *  mmi_syncml_notification_enum: remote or device
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_bkg_create(mmi_syncml_notification_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vsrv_ngroup_handle group_handle;
	vsrv_notification_handle noti_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	group_handle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, GRP_ID_SYNC_START);
	noti_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, group_handle, 0);


	vsrv_ncenter_set_ngroup_title_id(group_handle, STR_ID_SYNC_APP);
	vsrv_ncenter_set_notification_maintext_id(noti_handle, STR_ID_SYNC_PROGRESS);
	if (type == MMI_SYNCML_NOTIFICATION_SYNC_REMOTE)
	{
		vsrv_ncenter_set_notification_subtext_str(noti_handle, (WCHAR *)g_mmi_syncml_cntx.account_name_display[g_mmi_syncml_cntx.active_account - 1]);
	}
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
	else 
	{
		vsrv_ncenter_set_notification_subtext_str(noti_handle, (WCHAR *)g_mmi_syncml_common_cntx.remote_dev_name);
	}
#endif 		
	vsrv_ncenter_set_notification_intent_callback(noti_handle, mmi_syncml_ncenter_sync_bkg_callback, NULL, 0);
	vsrv_ncenter_set_notification_questiontext_id(noti_handle, STR_ID_SYNC_ABORT_SYNC_QUERY);
	vsrv_ncenter_notify_notification(noti_handle);
	
	g_syncml_ncenter.group_progressing= group_handle;
	g_syncml_ncenter.noti_progressing = noti_handle;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_bkg_destroy
 * DESCRIPTION
 *  background notification destroy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_ncenter_sync_bkg_destroy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(g_syncml_ncenter.group_progressing)
	{
		vsrv_ncenter_close_ngroup(g_syncml_ncenter.group_progressing);
	}

	if(g_syncml_ncenter.noti_progressing)
	{
		vsrv_ncenter_close_notification(g_syncml_ncenter.noti_progressing);
	}

	g_syncml_ncenter.group_progressing= NULL;
	g_syncml_ncenter.noti_progressing = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_bkg_callback
 * DESCRIPTION
 *  notifacation callback hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_bkg_callback(vsrv_notification_handle noti, VsrvNIntent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	switch(intent.type)
	{
		case VSRV_NINTENT_TYPE_LAUNCH:
			if (mmi_syncml_is_sync_now())
    		{
        		mmi_syncml_group_entry_sync_start(GRP_ID_ROOT);
    		}
			break;
		case VSRV_NINTENT_TYPE_TERMINATE:
			if (mmi_syncml_is_sync_now())
			{
				if ( (!g_mmi_syncml_cntx.is_sync_state)
                #ifdef __MMI_SYNCML_DEVICE_SYNC__		
					&&(!mmi_syncml_is_device_sync())
                #endif 
                #ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
					&&(!mmi_syncml_is_pc_sync())
                #endif 		
					)
				{
					mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_TOTAL);
					mmi_syncml_ncenter_sync_unfinish_create(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
					
					mmi_syncml_cbm_brearer_release();
					mmi_syncml_restore_context();
				}
				else
				{
				    mmi_syncml_ncenter_sync_bkg_destroy();
				    mmi_syncml_abort_sync_req_ext();
			    }
			}
			break;
		default:
			break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_group_close
 * DESCRIPTION
 *  cut all sync group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_ncenter_sync_group_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(mmi_frm_group_is_present(GRP_ID_SYNC_MAIN))
	{
		mmi_frm_group_close(GRP_ID_SYNC_MAIN);
	}

	if(mmi_frm_group_is_present(GRP_ID_SYNC_EDIT))
	{
		mmi_frm_group_close(GRP_ID_SYNC_EDIT);
	}
	
	if(mmi_frm_group_is_present(GRP_ID_SYNC_PRE_CHECK))
	{
		mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
	}
	
	if(mmi_frm_group_is_present(GRP_ID_SYNC_BT_SYNC_REQ))
	{
		mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
	}
	
	if(mmi_frm_group_is_present(GRP_ID_SYNC_OTAP_INSTALL))
	{
		mmi_frm_group_close(GRP_ID_SYNC_OTAP_INSTALL);
	}
	
	if(mmi_frm_group_is_present(GRP_ID_SYNC_APP_SYNC))
	{
		mmi_frm_group_close(GRP_ID_SYNC_APP_SYNC);
	}

	if(mmi_frm_group_is_present(GRP_ID_SYNC_DEV_MAIN))
	{
		mmi_frm_group_close(GRP_ID_SYNC_DEV_MAIN);
	}
	
	if(mmi_frm_group_is_present(GRP_ID_SYNC_BT_SYNC_REQ))
	{
		mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
	}
	
	if(mmi_frm_group_is_present(GRP_ID_PIM_SYNC))
	{
		mmi_frm_group_close(GRP_ID_PIM_SYNC);
	}

	if(mmi_frm_group_is_present(GRP_ID_PIM_SETTING))
	{
		mmi_frm_group_close(GRP_ID_PIM_SETTING);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_necnter_is_unfinish_account
 * DESCRIPTION
 *  To judge if it is unfinished account id
 * PARAMETERS
 *  U32 account index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_necnter_is_unfinish_account(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (MMI_BOOL)(g_syncml_ncenter.account_index == index);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_unfinish_create
 * DESCRIPTION
 *  create unfinished notification
 * PARAMETERS
 *  mmi_syncml_notification_enum: remote or device
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_unfinish_create(mmi_syncml_notification_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vsrv_ngroup_handle group_handle;
	vsrv_notification_handle noti_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if (type == MMI_SYNCML_NOTIFICATION_SYNC_REMOTE)
	{
		group_handle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, GRP_ID_SYNC_MAIN);
	}
	else
	{
		group_handle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, GRP_ID_SYNC_DEV_MAIN);
	}

	noti_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, group_handle, 1);
	
	vsrv_ncenter_set_ngroup_title_id(group_handle, STR_ID_SYNC_APP);
	vsrv_ncenter_set_notification_maintext_id(noti_handle, STR_ID_SYNC_DEFAULT_FAIL);
	if(type == MMI_SYNCML_NOTIFICATION_SYNC_REMOTE)
	{
		vsrv_ncenter_set_notification_subtext_str(noti_handle, (WCHAR *)g_mmi_syncml_cntx.account_name_display[g_mmi_syncml_cntx.active_account - 1]);
		g_syncml_ncenter.account_index = g_mmi_syncml_cntx.active_account;
	}
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
	else
	{
		vsrv_ncenter_set_notification_subtext_str(noti_handle, (WCHAR *)g_mmi_syncml_common_cntx.remote_dev_name);
	}
#endif

	vsrv_ncenter_set_notification_intent_callback(noti_handle, mmi_syncml_ncenter_sync_unfinish_callback, NULL, 0);
	vsrv_ncenter_notify_notification(noti_handle);

	g_syncml_ncenter.curr_type = type;
	g_syncml_ncenter.group_unfinish= group_handle;
	g_syncml_ncenter.noti_unfinished = noti_handle;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_unfinish_update
 * DESCRIPTION
 *  update unfinish notification
 * PARAMETERS
 *  U32 account index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_unfinish_update(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(!mmi_syncml_necnter_is_unfinish_account(index))
	{
		return;
	}

	if(g_syncml_ncenter.noti_unfinished &&
		g_syncml_ncenter.curr_type == MMI_SYNCML_NOTIFICATION_SYNC_REMOTE)
	{
		mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
		mmi_syncml_ncenter_sync_unfinish_create(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);		
	}

}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_unfinish_launch
 * DESCRIPTION
 *  launch sync app, remote or device.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_ncenter_sync_unfinish_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(mmi_syncml_is_sync_now())
	{
		if ( (!g_mmi_syncml_cntx.is_sync_state)
    #ifdef __MMI_SYNCML_DEVICE_SYNC__		
		&&(!mmi_syncml_is_device_sync())
    #endif 
    #ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
		&&(!mmi_syncml_is_pc_sync())
    #endif 		
		)
    	{
    		return;
    	}
		else
		{
		    mmi_popup_display_simple(
			    (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
			    MMI_EVENT_FAILURE, 
			    GRP_ID_ROOT, 
			    NULL);				
		    return;
	    }
	}
	
	mmi_syncml_ncenter_sync_group_close();
	
	if(g_syncml_ncenter.curr_type == MMI_SYNCML_NOTIFICATION_SYNC_REMOTE)
	{
	
	#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
	#else
		mmi_syncml_launch();
	#endif
	
	}
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	else
	{
		mmi_syncml_device_sync_launch();
	}
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_unfinish_destroy
 * DESCRIPTION
 *  unfinised notification destroy.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_ncenter_sync_unfinish_destroy(mmi_syncml_notification_enum unfinish_tupe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
	if(unfinish_tupe != g_syncml_ncenter.curr_type && 
		unfinish_tupe != MMI_SYNCML_NOTIFICATION_SYNC_TOTAL)
	{
		return;
	}
		
	
	if(g_syncml_ncenter.group_unfinish)
	{
		vsrv_ncenter_close_ngroup(g_syncml_ncenter.group_unfinish);
	}

	if(g_syncml_ncenter.noti_unfinished)
	{
		vsrv_ncenter_close_notification(g_syncml_ncenter.noti_unfinished);
	}
	
	g_syncml_ncenter.account_index = 0;
	g_syncml_ncenter.group_unfinish= NULL;
	g_syncml_ncenter.noti_unfinished = NULL;
	g_syncml_ncenter.curr_type = MMI_SYNCML_NOTIFICATION_SYNC_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ncenter_sync_unfinish_callback
 * DESCRIPTION
 *  unfinised notification callback hdlr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_ncenter_sync_unfinish_callback(vsrv_notification_handle noti, VsrvNIntent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(intent.type)
	{
		case VSRV_NINTENT_TYPE_LAUNCH:
			mmi_syncml_ncenter_sync_unfinish_launch();
			mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_TOTAL);
			break;
		case VSRV_NINTENT_TYPE_TERMINATE:
			mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_TOTAL);
			//Do nothing
			break;
		default:
			break;
	}

}
#endif

#endif /* __SYNCML_SUPPORT__ */

