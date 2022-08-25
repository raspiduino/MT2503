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

/* Filename:
 * ---------
 *    SyncMLAccount.c
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
#include "custom_mmi_default_value.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_syncml_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "BtcmSrvGprot.h"
#include "wap_adp.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "AlertScreen.h"
#include "AlarmFrameWorkProt.h"
#include "IdleGprot.h"
#include "ScrSaverGprot.h"
#include "SyncMLGProt.h"
#include "SyncMLDef.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "PhoneBookGprot.h"
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
#include "BTMMIScrGprots.h"
#endif
#include "simctrlsrvgprot.h"

#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "ModeSwitchSrvGprot.h"

#ifdef  __MMI_WLAN_FEATURES__
#include "DtcntSrvGprot.h"
#endif

/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/

/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
extern U8 g_syncml_display_info[1024];


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static void mmi_syncml_set_alarm_expiry_time_cb(U8 index, MYTIME *alarmTime, U8 *repeat, U8 *weekday, MYTIME *preReminder);
static U8 mmi_syncml_set_alarm_expiry_hdlr_cb(U8 index, U16 *period, BOOL power_on);
static void mmi_syncml_reinit_alarm_queue_cb(void);
static void mmi_syncml_regular_sync_timer_hdlr(void);
static void mmi_syncml_regular_sync_notification_accept(void);
static void mmi_syncml_regular_sync_notification_cancel(void);
static U16 mmi_syncml_regular_sync_check(U8 acct_index);
static void mmi_syncml_entry_regular_sync_query(void);
static mmi_ret mmi_syncml_group_regulary_sync_proc(mmi_event_struct *param);

/*****************************************************************************
 * Function definition
 *****************************************************************************/
mmi_ret mmi_syncml_rmdr_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables																	   */
	/*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;
	U16 period;

	/*----------------------------------------------------------------*/
	/* Code Body																		   */
	/*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_SYNCML && 
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
			mmi_syncml_set_alarm_expiry_hdlr_cb(remdr_evt->usr_data, &period, !remdr_evt->pwr_off);
			srv_reminder_notify_finish(0);
			break;

		case SRV_REMINDER_NOTIFY_REINIT:
			mmi_syncml_reinit_alarm_queue_cb();
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			break;

		default:
			break;
	}

	return MMI_RET_OK;
}

void mmi_syncml_set_reminder(U8 accnt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME almTime, expTime, preMinder;
	U8 freq, wday;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	mmi_syncml_set_alarm_expiry_time_cb(
		accnt_index,
		&almTime,
		&freq,
		&wday,
		&preMinder);
	
	expTime = srv_reminder_calc_time(&almTime, (srv_reminder_repeat_enum)freq, wday);
	
	srv_reminder_set(SRV_REMINDER_TYPE_SYNCML,
					 &expTime,
					 accnt_index);	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_syncml_alarm
 * DESCRIPTION
 *  Initialize the alarm callback functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_ALARM_SLIM__
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))   
    mmi_alm_set_start_index(ALM_TYPE_SYNCML, ALM_SYNCML);
    AlmSetExpiryTimeCB(ALM_TYPE_SYNCML, mmi_syncml_set_alarm_expiry_time_cb);
    AlmSetExpiryHandlerCB(ALM_TYPE_SYNCML, mmi_syncml_set_alarm_expiry_hdlr_cb);
    AlmSetInitHandlerCB(ALM_TYPE_SYNCML, NULL, mmi_syncml_reinit_alarm_queue_cb);
    AlmSetStopAlarmCB(ALM_TYPE_SYNCML, NULL);
#endif /*(defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))*/    
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_regular_sync_notify_flag
 * DESCRIPTION
 *  Initialize regular sync notify flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_regular_sync_notify_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i ++)
    {  
        if (g_mmi_syncml_cntx.regular_sync[i] == MMI_SYNCML_REGULAR_SYNC_POWER_ON)
        {
            /* Maybe power_on_mode cover the other regulary sync , such as data_change */
            g_mmi_syncml_cntx.regular_sync_notify[i] = MMI_SYNCML_POWER_ON_SYNC;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_sync_alarm_expired
 * DESCRIPTION
 *  Sync alarm idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_syncml_is_sync_alarm_expired(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_is_sync_now())
    {
        return 0;
    }
    
    /* If multipul account was set regular sync, regular sync notification order: Power_on, regular, data change */
    g_mmi_syncml_cntx.selected_account = 0;
    
    /* Power_on_sync */
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        if (g_mmi_syncml_cntx.regular_sync_notify[i] != MMI_SYNCML_POWER_ON_SYNC)
        {
            continue;                     
        }

        check_result = mmi_syncml_regular_sync_check(i);

        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_REG_SYNC_RESULT, check_result, i);

        if(check_result <= MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN)
        {
            return 0;
        }
        else if (MMI_SYNCML_REG_SYNC_CHECK_CONTINUE == check_result)
        {
            continue;
        }
        else /* MMI_SYNCML_REG_SYNC_CHECK_PASS == check_result */
        {
            g_mmi_syncml_cntx.selected_account = i;
            return 1;
        }
    }

    /* Alarm_sync */
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        if (g_mmi_syncml_cntx.regular_sync_notify[i] != MMI_SYNCML_REGULARY_SYNC)
        {
            continue;                     
        }

        check_result = mmi_syncml_regular_sync_check(i);
        
        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_REG_SYNC_RESULT, check_result, i); 
        
        if(check_result <= MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN)
        {
            return 0;
        }
        else if (MMI_SYNCML_REG_SYNC_CHECK_CONTINUE == check_result)
        {
            continue;
        }
        else /* MMI_SYNCML_REG_SYNC_CHECK_PASS == check_result */
        {
            g_mmi_syncml_cntx.selected_account = i;
            return 1;
        }
    }

#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    /* Data_change_sync, only supported on Vodafone phone and only one account can 
       be set */
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        if (g_mmi_syncml_cntx.regular_sync_notify[i] >= MMI_SYNCML_POWER_ON_SYNC
			|| g_mmi_syncml_cntx.regular_sync_notify[i] == 0)
        {
            continue;                     
        }
       
#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
        /* for data changed sync , should delay 3min on Vodafone proj*/
        if (g_mmi_syncml_cntx.is_data_change_timeout == MMI_FALSE)
        {
            return 0;
        }
#endif /* __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__ */

        check_result = mmi_syncml_regular_sync_check(i);
        
        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_REG_SYNC_RESULT, check_result, i);
        
        if(check_result <= MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN)
        {
            return 0;
        }
        else if (MMI_SYNCML_REG_SYNC_CHECK_CONTINUE == check_result)
        {
            /* only support data changed sync on one account */
            return 0;
        }
        else /* MMI_SYNCML_REG_SYNC_CHECK_PASS == check_result */
        {
            g_mmi_syncml_cntx.selected_account = i;
            return 1;
        }
    }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
    
    return 0;
}

mmi_ret mmi_syncml_sync_regular_insert(mmi_event_struct *evt)  {
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 i_index = 0 ;
	/*----------------------------------------------------------------*/
	/* Code  body 																														*/
	/*----------------------------------------------------------------*/
	i_index = g_mmi_syncml_cntx.selected_account;
	mmi_syncml_set_reminder(i_index);
	  
}

mmi_ret mmi_syccml_sync_alarm_post(mmi_event_struct *evt)
{
	mmi_event_struct revt;
	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SYNC_REGULARY, mmi_syncml_group_regulary_sync_proc, NULL);
	mmi_frm_group_enter(GRP_ID_SYNC_REGULARY, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_syncml_entry_regular_sync_query();

	MMI_FRM_INIT_EVENT(&revt, 0xFFFE);
    mmi_frm_post_event(&revt, mmi_syncml_sync_regular_insert, NULL);
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_alarm_hdlr
 * DESCRIPTION
 *  Sync alarm idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sync_alarm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_REGULARY_SYNC_HDL);
    
	MMI_FRM_INIT_EVENT(&evt, 0xFFFE);
	mmi_frm_post_event(&evt, mmi_syccml_sync_alarm_post, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_regulary_sync_proc
 * DESCRIPTION
 *  Callback data change sync timer time out
 * PARAMETERStimeout
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_group_regulary_sync_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        /* interrup or entry other new node both should close the group */
        case EVT_ID_GROUP_INACTIVE:
            mmi_frm_group_close(GRP_ID_SYNC_REGULARY);
            break;
        default:
            break;
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_regular_sync_query
 * DESCRIPTION
 *  Callback data change sync timer time out
 * PARAMETERStimeout
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_regular_sync_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sync_alarm_string = STR_ID_SYNC_POWER_ON_QUERY;
    U8 account_index = g_mmi_syncml_cntx.selected_account;
    mmi_syncml_account_struct *temp_account = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no need delete SCR_ID_SYNC_ALARM_QUERY, because it is not in history*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_REGULARY,
            SCR_ID_SYNC_ALARM_QUERY, 
            NULL, 
            mmi_syncml_entry_regular_sync_query, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* if it is power on sync */
    if (g_mmi_syncml_cntx.regular_sync_notify[account_index] ==  MMI_SYNCML_POWER_ON_SYNC)
    {  
        sync_alarm_string = STR_ID_SYNC_POWER_ON_QUERY;
    }
    else if (g_mmi_syncml_cntx.regular_sync_notify[account_index] == MMI_SYNCML_REGULARY_SYNC)
    {
        sync_alarm_string = STR_ID_SYNC_ALARM_EXPIRED_QUERY;
    }    
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    else if ((g_mmi_syncml_cntx.regular_sync_notify[account_index] >= MMI_SYNCML_PHB_DATA_CHANGE)
                && (g_mmi_syncml_cntx.regular_sync_notify[account_index] <= MMI_SYNCML_EMAIL_DATA_CHANGE))
    {
        sync_alarm_string = STR_ID_SYNC_DATA_CHANGED_QUERY;
    } 
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
    else
    {    
        MMI_ASSERT("regular_sync_notify error");
    }

    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

    /* temporarily read profiles to check if they are not initialized */
    mmi_syncml_read_account_from_nvram((U8)(account_index + 1), (void *)temp_account);
    
    mmi_ucs2cpy((CHAR*) g_mmi_syncml_cntx.account_name_display[account_index], (CHAR*) temp_account->account_name);              

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }

    kal_wsprintf(
        (U16*)g_syncml_display_info, 
        "%w\n\n%w%w\n%w", 
        GetString(sync_alarm_string),
        GetString(STR_ID_SYNC_PROFILE_NAME),
        GetString(STR_ID_SYNCML_COLON),
        (CHAR*)g_mmi_syncml_cntx.account_name_display[account_index]);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory7Screen(
        STR_ID_SYNC_MENU,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)g_syncml_display_info,
        NULL);

     SetLeftSoftkeyFunction(mmi_syncml_regular_sync_notification_accept, KEY_EVENT_UP);
     SetRightSoftkeyFunction(mmi_syncml_regular_sync_notification_cancel, KEY_EVENT_UP);
     SetCenterSoftkeyFunction(mmi_syncml_regular_sync_notification_accept, KEY_EVENT_UP);
        
     SetKeyHandler(mmi_syncml_regular_sync_notification_cancel, KEY_END, KEY_EVENT_DOWN);
}


#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_data_change_timer_hdlr
 * DESCRIPTION
 *  Callback data change sync timer time out
 * PARAMETERStimeout
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_data_change_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_syncml_cntx.is_data_change_timeout = MMI_TRUE;
      
    if (mmi_idle_is_active()
    #if defined(__MMI_SCREEN_SAVER__)
        || mmi_scr_saver_is_active()
    #endif
    )
    {
        if (mmi_syncml_is_sync_alarm_expired())
        {        
            mmi_syncml_sync_alarm_hdlr();
        }
    } 
}
#endif /* __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__ */



/*****************************************************************************
* Local Function  
*****************************************************************************/
/* Local function can only be called within this .C file, it shallbe declare */ 
/* as static */

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_regular_sync_check
 * DESCRIPTION
 *  The function is used to check status before, it popup notification order
 *  is power on, regular sync, data changed sync
 * PARAMETERStimeout
 *  void
 * RETURNS
 *  MMI_TRUE                 
 *  MMI_FALSE          
 *****************************************************************************/
static U16 mmi_syncml_regular_sync_check(U8 acct_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check database ready for all account */
    if ((g_mmi_syncml_cntx.app_to_sync[acct_index] & SYNCML_DB_PHONEBOOK)
        && !mmi_phb_check_ready(MMI_FALSE))
    {        
        StartTimer(SYNCML_POWER_ON_SYNC_TIMER, 2000, mmi_syncml_regular_sync_timer_hdlr);
        return MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN;
    }
    
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (g_mmi_syncml_cntx.transport_type[acct_index] == MMI_SYNCML_TRANS_TYPE_BT)
    {
        /* handle the BT haven't been initialized totally */
        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_SWITCHING_ON)
        {
            StartTimer(SYNCML_POWER_ON_SYNC_TIMER, 2000, mmi_syncml_regular_sync_timer_hdlr);
            return MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN;
        }
        /* not support BT in flight mode */
        if (!srv_mode_switch_is_network_service_available() && !mmi_bt_is_to_display_bt_menu())
        {                        
            if (g_mmi_syncml_cntx.regular_sync_notify[acct_index] 
                == MMI_SYNCML_POWER_ON_SYNC)
            {
                /* For power on sync, if current senario don't permmit sync, should cancel this sync */
                g_mmi_syncml_cntx.regular_sync_notify[acct_index] = 0; 
                return MMI_SYNCML_REG_SYNC_CHECK_CONTINUE;
            }
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ 
            else if (g_mmi_syncml_cntx.regular_sync_notify[acct_index] < MMI_SYNCML_POWER_ON_SYNC
                && g_mmi_syncml_cntx.regular_sync_notify[acct_index] >= MMI_SYNCML_PHB_DATA_CHANGE)
            {
                return MMI_SYNCML_REG_SYNC_CHECK_CONTINUE;
            }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
            /* alam sync */
            else
            {
                return MMI_SYNCML_REG_SYNC_CHECK_CONTINUE;
            }
        }
    }
    else
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
    {   
        /* sim is valid but wap is not ready */
        if (srv_sim_ctrl_any_sim_is_available() && !wap_is_ready())
        {
            StartTimer(SYNCML_POWER_ON_SYNC_TIMER, 2000, mmi_syncml_regular_sync_timer_hdlr);
            return MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN; 
        }

        /* invalid sim or flight mode */
        if (!srv_mode_switch_is_network_service_available()
#ifdef __MMI_WLAN_FEATURES__
            && srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_ACTIVE 
            && srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_CONNECTED
#else
            || !srv_sim_ctrl_any_sim_is_available()
#endif
            )
        {       
            if (g_mmi_syncml_cntx.regular_sync_notify[acct_index] 
                == MMI_SYNCML_POWER_ON_SYNC)
            {
                /* For power on sync, if current senario don't permmit sync, should cancel this sync */
                g_mmi_syncml_cntx.regular_sync_notify[acct_index] = 0; 
                return MMI_SYNCML_REG_SYNC_CHECK_CONTINUE;
            }
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ 
            else if (g_mmi_syncml_cntx.regular_sync_notify[acct_index] < MMI_SYNCML_POWER_ON_SYNC
                && g_mmi_syncml_cntx.regular_sync_notify[acct_index] >= MMI_SYNCML_PHB_DATA_CHANGE)
            {
                return MMI_SYNCML_REG_SYNC_CHECK_CONTINUE;
            }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
            /* alarm sync */
            else
            {
                return MMI_SYNCML_REG_SYNC_CHECK_CONTINUE;
            }
        }
    }

    /* pass all check */
    return MMI_SYNCML_REG_SYNC_CHECK_PASS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_expiry_time_cb
 * DESCRIPTION
 *  Sync alarm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_set_alarm_expiry_time_cb(U8 index, MYTIME *alarmTime, U8 *repeat, U8 *weekday, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);

    switch (g_mmi_syncml_cntx.regular_sync[index])
    {
        case MMI_SYNCML_REGULAR_SYNC_EVERY_DAY:
            alarmTime->nYear = currTime.nYear;
            alarmTime->nMonth = currTime.nMonth;
            alarmTime->nDay = currTime.nDay;
            alarmTime->nHour = 12;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_EVERYDAY;
            *weekday = 0;
            break;

        case MMI_SYNCML_REGULAR_SYNC_EVERY_WEEK:
            alarmTime->nYear = currTime.nYear;
            alarmTime->nMonth = currTime.nMonth;
            alarmTime->nDay = currTime.nDay;
            alarmTime->DayIndex = DOW(alarmTime->nYear, alarmTime->nMonth, alarmTime->nDay);
            alarmTime->nHour = 12;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_DAYS; /* serveral days in a week */
            *weekday = 0x01; /* Sunday */
            break;

        case MMI_SYNCML_REGULAR_SYNC_EVERY_MONTH:
            alarmTime->nYear = currTime.nYear;
            alarmTime->nMonth = currTime.nMonth;
            alarmTime->nDay = 1;
            alarmTime->nHour = 12;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_MONTHLY;
            *weekday = 0;
            break;

        default:
            alarmTime->nYear = 0;
            alarmTime->nMonth = 0;
            alarmTime->nDay = 0;
            alarmTime->nHour = 0;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_OFF;
            *weekday = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_expiry_hdlr_cb
 * DESCRIPTION
 *  Sync alarm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_syncml_set_alarm_expiry_hdlr_cb(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_ALARM_EXPIRY_PHONE_STATE, index, power_on);

    MMI_ASSERT(index < MMI_MAX_SYNCML_ACCOUNTS);
    
    *period = ALM_WITHOUD_EXPIRY_PERIOD;

    /* First save the flag once user plug out the battery */
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    mmi_syncml_read_account_from_nvram((U8)(index + 1), (void*)temp_account);
    temp_account->regular_sync_notify = MMI_SYNCML_REGULARY_SYNC;
    mmi_syncml_write_account_to_nvram((U8)(index + 1), (void *)temp_account);
    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }

    /* If the phone power on */
    if (power_on)
    {
        g_mmi_syncml_cntx.regular_sync_notify[index] = MMI_SYNCML_REGULARY_SYNC;

        if (mmi_idle_is_active()
        #if defined(__MMI_SCREEN_SAVER__)
            || mmi_scr_saver_is_active()
        #endif
        )
        {
            if (mmi_syncml_is_sync_alarm_expired())
            {        
                mmi_syncml_sync_alarm_hdlr();
            }
        }
    }

#ifndef __MMI_DEV_NEW_SLIM__
    return ALM_HAS_NO_IND;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_reinit_alarm_queue_cb
 * DESCRIPTION
 *  Sync alarm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_reinit_alarm_queue_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        if (g_mmi_syncml_cntx.regular_sync[i] > MMI_SYNCML_REGULAR_SYNC_POWER_ON)
        {
			mmi_syncml_set_reminder(i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_regular_sync_timer_hdlr
 * DESCRIPTION
 *  Timer to wait WAP and phonebook ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_regular_sync_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_REG_SYNC_TIMER_HDLR);
    
    if (mmi_idle_is_active()
    #if defined(__MMI_SCREEN_SAVER__)
        || mmi_scr_saver_is_active()
    #endif
    )
    {
        if (mmi_syncml_is_sync_alarm_expired())
        {        
            mmi_syncml_sync_alarm_hdlr();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_alarm_accept
 * DESCRIPTION
 *  Sync alarm acceptance
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_regular_sync_notification_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    g_mmi_syncml_cntx.regular_sync_notify[g_mmi_syncml_cntx.selected_account] = 0;

    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    mmi_syncml_read_account_from_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)temp_account);
    temp_account->regular_sync_notify = 0;
    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void *)temp_account);

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }
        
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    if (mmi_syncml_is_device_or_pc_sync())
    {
		mmi_popup_display_simple(
			(WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
			MMI_EVENT_FAILURE, 
			GRP_ID_ROOT, 
			NULL); 
        mmi_frm_group_close(GRP_ID_SYNC_REGULARY);
    }
    else
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */
    {   
        mmi_frm_group_close(GRP_ID_SYNC_REGULARY);
        mmi_syncml_group_entry_sync_pre_check(GRP_ID_ROOT, MMI_TRUE); 
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_alarm_cancel
 * DESCRIPTION
 *  Sync alarm calcellation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_regular_sync_notification_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_mmi_syncml_cntx.regular_sync_notify[g_mmi_syncml_cntx.selected_account] = 0;
    
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    mmi_syncml_read_account_from_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)temp_account);
    temp_account->regular_sync_notify = 0;
    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void *)temp_account);

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }

    mmi_frm_group_close(GRP_ID_SYNC_REGULARY);
}

#endif /* __SYNCML_SUPPORT__ */

