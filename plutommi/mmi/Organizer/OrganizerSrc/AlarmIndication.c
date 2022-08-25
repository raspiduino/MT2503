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
 *  AlarmIndication.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
    #include "MMI_features.h"

/*****************************************************************************
 * Header files
 *****************************************************************************/
#include "Mdi_audio.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_profiles_def.h"
#include "GpioSrvGprot.h"

#include "AlarmProt.h"
#include "AlarmDef.h"
#include "AlarmGProt.h"
#include "AlarmFrameworkProt.h"
#include "HomeScreenOp11V32Gprot.h"
#include "AzaanAlarmProt.h"
#include "PoweronChargerProt.h"

#include "BootupSrvGprot.h"
#include "AlarmsrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"
    #include "custom_mmi_default_value.h"
    #include "MMIDataType.h"
    #include "DateTimeType.h"
    #include "app_datetime.h"
    #include "string.h"
    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "wgui_categories_util.h"
    #include "NotificationGprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalResDef.h"
    #include "mmi_rp_app_alarm_def.h"
    #include "mmi_frm_input_gprot.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_list.h"
    #include "TimerEvents.h"
    #include "mmi_frm_timer_gprot.h"
    #include "gui_typedef.h"
    #include "gui_data_types.h"
    #include "Unicodexdcl.h"
    #include "CustDataRes.h"
    #include "wgui_categories_popup.h"
    #include "mmi_frm_history_gprot.h"
    #include "wgui_categories.h"
    #include "custom_srv_prof_defs.h"
    #include "custom_led_patterns.h"
    #include "mmi_common_app_trc.h"
    #include "kal_general_types.h"
#ifdef __MMI_DEV_NEW_SLIM__
	#include "gdi_include.h"
	#include "ReminderSrvGprot.h"
#endif

#include "gui_touch_feedback.h"
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
#include "ScrLockerGprot.h"
#include "mmi_rp_app_scr_locker_def.h"
#endif    

/*****************************************************************************
 * Typedef  
 *****************************************************************************/


/*****************************************************************************
 * Define
 *****************************************************************************/
#define ALARM_TONE_IN_CALL SRV_PROF_TONE_SMS_INCALL

/*****************************************************************************
 * Global Variables 
 *****************************************************************************/

/*****************************************************************************
 * Local function 
 *****************************************************************************/
static void AlmReInitQueueCBH(void);
#ifdef __MMI_RTC_TEST_SLIM__
static void AlmExpiryHandlerCB(U8 index, U16 *period, BOOL power_on, srv_reminder_type reminder_type);
#else
static U8 AlmExpiryHandlerCB(U8 index, U16 *period, BOOL power_on);
#endif
static void mmi_alm_entry_indication_screen(void);
static void AlmHandleEndKey(void);
static void ExitAlmIndicationScreen(void);
static void mmi_alm_stop_vibrate(void);
static srv_prof_ret mmi_alm_play_tone_callback(srv_prof_ret result);
static void mmi_alm_play_tone(void);
#ifdef __MMI_ALM_CUST_VOLUME__
static void AlmPlayAlarmToneWithVol(U8 volume);
#endif
static mmi_ret mmi_alm_group_leave_proc(mmi_event_struct* evt);

static void mmi_alm_stop_int(void);

static MMI_BOOL g_mmi_alm_self_close = MMI_FALSE;
static MMI_BOOL g_mmi_alm_play_tone = MMI_FALSE;
static MMI_BOOL g_mmi_alm_play_vib = MMI_FALSE;

#ifdef MOTION_SENSOR_SUPPORT
static SRV_SENSOR_HANDLE g_sensor_handle = 0;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_remdr_notify_hdlr
 * DESCRIPTION
 *  Set callback function needed by alarm framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_alm_remdr_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;
	U16 period;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	MMI_ALM_TRACE2(MMI_ALM_REMDR_NOTIFY_HDLR, remdr_evt->reminder_type, remdr_evt->notify);
	
#ifdef __MMI_RTC_TEST_SLIM__
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_ALM && 
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL&&
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_FACTORY)     
#else
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_ALM && 
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
#endif
	{
		return MMI_RET_OK;
	}
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
			srv_alm_init(NULL);
			AlmInitNvram();
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:

	#ifdef __MMI_RTC_TEST_SLIM__
			AlmExpiryHandlerCB(remdr_evt->usr_data, &period, !remdr_evt->pwr_off, remdr_evt->reminder_type);
	#else
			AlmExpiryHandlerCB(remdr_evt->usr_data, &period, !remdr_evt->pwr_off);
    #endif
  
			break;

		case SRV_REMINDER_NOTIFY_REINIT:
			AlmReInitQueueCBH();
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			AlmSnoozeHandler();
			break;
#ifndef __MMI_DEV_NEW_SLIM__
		default:
			break;
#endif
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  AlmReInitQueueCBH
 * DESCRIPTION
 *  Callback handler of reiniting alarm to alarm queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void AlmReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ALM_TRACE0(MMI_ALM_REINIT_Q);
	
	srv_alm_reset_reminder();
#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_nmgr_expiry_callback
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_alm_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg)
{

#ifndef __MMI_DEV_NEW_SLIM__ 
	if (g_alm_frm_cntx.CurrAlmIndex == 0xFF)
	{
		return MMI_TRUE;
	}
#endif
    g_mmi_alm_self_close = MMI_TRUE;
		mmi_frm_group_close(GRP_ID_ALM_IND);
    
    EntryAlmIndicationScreen();
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  AlmExpiryHandlerCB
 * DESCRIPTION
 *  CallBack handler to execute alarm expiry.
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_RTC_TEST_SLIM__
static void AlmExpiryHandlerCB(U8 index, U16 *period, BOOL power_on, srv_reminder_type reminder_type)    
{

		g_alm_cntx.active_alm_idx = index;
		//kal_prompt_trace(MOD_MMI ,"AlmExpiryHandlerCB,reminder_type:%d ",reminder_type);   //__MMI_DEV_NEW_SLIM__
	
		if (power_on)
		{
			if(reminder_type == SRV_REMINDER_TYPE_FACTORY)
			{
				//kal_prompt_trace(MOD_MMI ,"power on ");
				srv_reminder_notify_finish(MMI_FALSE);
			}
			else
	
			{
				update_mainlcd_dt_display();
				
				mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_REMINDER_ALARM,
											 MMI_EVENT_REMINDER_ALARM,
											 mmi_alm_nmgr_expiry_callback,
											 NULL);
			}
		}
		else
		{
		
			if(reminder_type == SRV_REMINDER_TYPE_FACTORY)
			{	
				//kal_prompt_trace(MOD_MMI ,"power off ");
				srv_reminder_notify_finish(MMI_TRUE);
			}
			else
		
			{
				gdi_init();				
				mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_REMINDER_ALARM,
												 MMI_EVENT_REMINDER_ALARM,
												 mmi_alm_nmgr_expiry_callback,
												 NULL);
			}
		}

		return;
	}



#else
static U8 AlmExpiryHandlerCB(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(index);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_alm_cntx.active_alm_idx = index;
    if (power_on)
    {
        update_mainlcd_dt_display();
        ret = mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_REMINDER_ALARM,
                                         MMI_EVENT_REMINDER_ALARM,
                                         mmi_alm_nmgr_expiry_callback,
                                         NULL);
    }
    else
    {
    #ifdef __MMI_DEV_NEW_SLIM__
		gdi_init();	
	#else
        AlmInitLCDModule();
	#endif
        ret = mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_REMINDER_ALARM,
                                         MMI_EVENT_REMINDER_ALARM,
                                         mmi_alm_nmgr_expiry_callback,
                                         NULL);
    }

    if (ret)
    {
        return ALM_HAS_IND;
    }
 
    return ALM_HAS_NO_IND;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_ind_proc
 * DESCRIPTION
 *  Group event process function for alarm indication
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_alm_ind_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_frm_group_close(GRP_ID_ALM_IND);
        break;
		
    case EVT_ID_GROUP_DEINIT:
		g_mmi_alm_play_tone = MMI_FALSE;
        g_mmi_alm_play_vib = MMI_FALSE;
		break;
#ifndef __MMI_DEV_NEW_SLIM__		
    default:
        break;
#endif
    }

    return MMI_RET_OK;
}
    
/*****************************************************************************
* FUNCTION
*  EntryAlmIndicationScreen
* DESCRIPTION
*  Display indication screen and play alarm tone when alarm expires.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryAlmIndicationScreen(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

#ifdef __MMI_DEV_NEW_SLIM__
	 mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_ALM_IND, mmi_alm_ind_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
     mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_ALM_IND, mmi_alm_ind_proc, NULL);
     mmi_frm_group_enter(GRP_ID_ALM_IND, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#endif

     mmi_alm_entry_indication_screen();    
}


/*****************************************************************************
* FUNCTION
 *  mmi_alm_key_proc
 * DESCRIPTION
 *  key proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_alm_key_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_key_evt_struct *evt = (mmi_frm_key_evt_struct *)param;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (evt->evt_id == EVT_ID_PRE_KEY)
	{
		if (evt->key_code == KEY_END && evt->key_type == KEY_EVENT_DOWN)
		{
			mmi_alm_stop_int();
		}
	}
	
	return MMI_RET_OK;
}

#ifdef MOTION_SENSOR_SUPPORT
void mmi_alm_motion_turnover_callback(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	srv_sensor_motion_turnover_struct *p_turnover;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    MMI_ASSERT(sensor_type == SRV_SENSOR_MOTION_TURNOVER);
    MMI_ASSERT(g_sensor_handle > 0);
    p_turnover = (srv_sensor_motion_turnover_struct *)sensor_data;
    if(p_turnover->direction != SRV_SENSOR_MOTION_TURNOVER_DOWN)
    {
        return;
    }
    mmi_alm_stop_tone();
	mmi_alm_stop_vibrate();
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_alm_entry_indication_screen
* DESCRIPTION
*  Display indication screen and play alarm tone when alarm expires.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_alm_entry_indication_screen(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     U8 *guiBuffer;
     MYTIME currTime;
     U8 timeString[SIZE_OF_DATE_STRING];
     static U8 dateString[SIZE_OF_ALARM_STRING + SIZE_OF_DATE_STRING];
     U8 almindex = g_alm_cntx.active_alm_idx;
     U16 lsk_str, rsk_str;
	 srv_alm_node_type *node;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
	 MMI_ALM_TRACE0(MMI_ALM_INDICATION_SCREEN);
     if (!mmi_frm_scrn_enter(
             GRP_ID_ALM_IND, 
             SCR_ID_ALM_INDICATION, 
             ExitAlmIndicationScreen, 
             (FuncPtr)mmi_alm_entry_indication_screen, 
             MMI_FRM_FULL_SCRN))
     {
         return;
     }
#ifdef MOTION_SENSOR_SUPPORT     
     if(srv_reminder_get_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER))
     {
	     g_sensor_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_TURNOVER,
	                             NULL,
	                             mmi_alm_motion_turnover_callback,
	                             NULL);
	 }
#endif
#ifndef __MMI_DEV_NEW_SLIM__
     StopTimer(ALARM_TIMER_WAIT_FOR_CALL);
#endif
     if (!IsMyTimerExist(ALARM_ALERT_NOTIFYDURATION_TIMER))
     {
         StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, AlmSnoozeHandler);
     }
     mmi_frm_scrn_set_leave_proc(GRP_ID_ALM_IND, SCR_ID_ALM_INDICATION, mmi_alm_group_leave_proc);
     mmi_frm_start_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);

	 if(g_mmi_alm_play_tone == MMI_TRUE)
	 {
	 	mmi_alm_play_tone();
	 }
	 if(g_mmi_alm_play_vib == MMI_TRUE)
	 {
	 	srv_vibrator_on();
		gui_touch_feedback_disable_vibrate();
	 }

     GetDateTime(&currTime);
     time_string(&currTime, (UI_string_type) timeString, DT_IDLE_SCREEN);
     /* prepare string to display */

     date_string(&currTime, (UI_string_type) dateString, DT_IDLE_SCREEN);
     mmi_ucs2cat((CHAR*) dateString, (CHAR*) L"\n");
     mmi_ucs2cat((CHAR*) dateString, (CHAR*) timeString);

     /* flush key because alarm if some key is not released, the alarm may be stopped */
     ClearKeyEvents();

#ifndef __MMI_DEV_NEW_SLIM__ 
     g_alm_cntx.IsSaveToHistory = 1;
#endif

     guiBuffer = mmi_frm_scrn_get_active_gui_buf();
     lsk_str = STR_GLOBAL_STOP;

	 node = (srv_alm_node_type *)srv_alm_read(almindex);
#ifdef __MMI_DEV_NEW_SLIM__

	rsk_str = (node->Snooze >= MAX_SNOOZE_CHANCES ? 0 : ALARMS_SNOOZE_STRINGID);
#else

     if (node->Snooze >= MAX_SNOOZE_CHANCES)
     {
         rsk_str = 0;
     }
     else
     {
         rsk_str = ALARMS_SNOOZE_STRINGID;
     }
	 
#endif	 
	 srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

     EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	 
     mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
	 
#ifdef __MMI_DEV_NEW_SLIM__
	 ShowCategory121Screen(
         lsk_str,
         0,
         rsk_str,
         0,
         dateString,
         0,
         guiBuffer,
         1);
#else	 
     ShowCategory121Screen(
         lsk_str,
         0,
         rsk_str,
         0,
         dateString,
         ALARM_ANIMATION_INDICATION_IMAGEID,
         guiBuffer,
         1);
#endif
     if (node->Snooze < MAX_SNOOZE_CHANCES)
     {
         SetRightSoftkeyFunction(AlmSnoozeHandler, KEY_EVENT_UP);
     }

     SetLeftSoftkeyFunction(AlmStopHandler, KEY_EVENT_UP);
     SetCenterSoftkeyFunction(AlmStopHandler, KEY_EVENT_UP);
	 mmi_frm_scrn_set_key_proc(GRP_ID_ALM_IND, SCR_ID_ALM_INDICATION, mmi_alm_key_proc);
	 
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
	 mmi_frm_cb_reg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, mmi_alm_group_leave_proc, NULL);
#endif

     /* register END key for power on alarm */
     if (AlmIsRTCPwron())
     {
         ClearKeyHandler(KEY_END, KEY_EVENT_UP);
         ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
         if (mmi_frm_kbd_is_key_supported(KEY_POWER))
         {
             ClearKeyHandler(KEY_END, KEY_LONG_PRESS);       
             ClearKeyHandler(KEY_POWER, KEY_EVENT_UP);
             ClearKeyHandler(KEY_POWER, KEY_EVENT_DOWN);
             //SetKeyHandler(AlmHandleEndKey, KEY_POWER, KEY_LONG_PRESS);
			 SetKeyLongpressHandler(AlmHandleEndKey, KEY_POWER);
         }
         else
         {
             //SetKeyHandler(AlmHandleEndKey, KEY_END, KEY_LONG_PRESS);
			 SetKeyLongpressHandler(AlmHandleEndKey, KEY_END);
         }        
         mmi_charbat_update_status_icon();
     }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_group_leave_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_alm_group_leave_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
	mmi_scr_locker_pre_lock_evt_struct *lock_event;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
    		if (!g_mmi_alm_self_close)
    		{
	            AlmSnoozeHandler();  	
	            g_mmi_alm_self_close = MMI_FALSE;
            }
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
	        mmi_frm_cb_dereg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, mmi_alm_group_leave_proc,NULL);
#endif
            break;			
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
         case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
		 	lock_event = (mmi_scr_locker_pre_lock_evt_struct *)evt;
			
			if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
			{		
				AlmSnoozeHandler();
				return MMI_RET_OK;
			}			
			else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
			{
				return MMI_RET_ERR;
			}
		 	break;
#endif
#ifndef __MMI_DEV_NEW_SLIM__
        default:
            break;
#endif
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
*  AlmHandleEndKey
* DESCRIPTION
*  End key handler of alarm indication screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void AlmHandleEndKey(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
	 srv_alm_node_type *node;
     U8 i;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_ALM_TRACE0(MMI_ALM_END_KEY);
	 
     mmi_alm_stop_tone();

     i = g_alm_cntx.active_alm_idx;

     RETURN_IF_FAIL(i < NUM_OF_ALM);
	 
	 node = srv_alm_read(i);
  	 node->Snooze = 0;

     if (node->Freq == ALM_FREQ_ONCE)    /* reset the alarm state */
     {
         node->State = UNSET_STATE;
     }
     srv_alm_write(i, node);
#ifdef __MMI_DEV_NEW_SLIM__
     mmi_frm_group_close(GRP_ID_ALM_IND);
	 srv_reminder_util_send_pwron();
#else
     AlmExitIndScreen();
     AlmSendPowerOn();
#endif
}


/*****************************************************************************
* FUNCTION
*  ExitAlmIndicationScreen
* DESCRIPTION
*  Exit function of alarm indication screen.
*  If exits screen because of interrupts, add screen to history.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void ExitAlmIndicationScreen(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_alm_stop_tone();
	 srv_backlight_turn_off();
#ifdef MOTION_SENSOR_SUPPORT	 
     if(g_sensor_handle > 0)
     {
         srv_sensor_stop_listen(g_sensor_handle);
         g_sensor_handle = 0;
         
     }
#endif	 
     mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);
}

#ifndef __MMI_DEV_NEW_SLIM__ 

/*****************************************************************************
* FUNCTION
*  AlmCommonExitProcedure
* DESCRIPTION
*  Stop alarm tone by user or timeout.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void AlmCommonExitProcedure(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     g_alm_cntx.IsSaveToHistory = 0;
     mmi_alm_stop_tone();
}


/*****************************************************************************
* FUNCTION
*  AlmExitIndScreen
* DESCRIPTION
*  Exit alarm indication screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void AlmExitIndScreen(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     mmi_frm_group_close(GRP_ID_ALM_IND);
}
#endif

static void mmi_alm_stop_int(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
	alm_nvram_struct *alm_node;
	U8 index = g_alm_cntx.active_alm_idx;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
	MMI_ALM_TRACE2(MMI_ALM_STOP, 0, index);
	 
     StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
#ifdef __MMI_DEV_NEW_SLIM__ 
    mmi_alm_stop_tone();
#else
     AlmCommonExitProcedure();
#endif

	RETURN_IF_FAIL(index < NUM_OF_ALM);
	alm_node = (alm_nvram_struct *)srv_alm_read(index);
             
     /* factory alarm does not have to re-schedule */
     alm_node->Snooze = 0;

     if (alm_node->Freq == ALM_FREQ_ONCE)/* reset the alarm state */
         {
         alm_node->State = UNSET_STATE;
         if (srv_alm_active_alms() == 0)
             {
                 AlmDeactivateIndicator();
             }
         }
         
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM)
    {
        /* When it is alarm boot up, there is only on group GRP_ID_ALM_IND */
        /* It should be closed or the power on screen may be displayed incorrectly */
        mmi_frm_group_close(GRP_ID_ALM_IND);
    } 
	
	 srv_alm_write(index, alm_node);

	 srv_reminder_notify_finish(MMI_TRUE);

	 g_alm_cntx.active_alm_idx = 0xFF;

}

/*****************************************************************************
* FUNCTION
*  AlmStopHandler
* DESCRIPTION
*  Handler for stopping alarm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void AlmStopHandler(void)
{
     mmi_alm_stop_int();
	 mmi_frm_group_close(GRP_ID_ALM_IND);
}


/*****************************************************************************
* FUNCTION
*  AlmSnoozeHandler
* DESCRIPTION
*  Handler for snoozing alarm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void AlmSnoozeHandler(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
	 alm_nvram_struct *alm_node;
     U8 index = g_alm_cntx.active_alm_idx;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    MMI_ALM_TRACE1(MMI_ALM_SNOOZE, index);
	 
	if (mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_REMINDER_ALARM,
										  mmi_alm_nmgr_expiry_callback,
										  NULL))
	{
		mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_REMINDER_ALARM, 
								   			  mmi_alm_nmgr_expiry_callback, 
								  			  NULL);
	}
	
     StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
	RETURN_IF_FAIL(index < NUM_OF_ALM);

	 alm_node = srv_alm_read(index);
#ifdef __MMI_DEV_NEW_SLIM__
	mmi_alm_stop_tone();
#else
     AlmCommonExitProcedure();
#endif

#ifndef __MMI_DEV_NEW_SLIM__
     if (alm_node->Snooze < MAX_SNOOZE_CHANCES)
#endif
     {
     	alm_node->Snooze++;
	 	alm_node->State = SET_STATE;
	
		srv_alm_write(index, alm_node);
		srv_reminder_notify_finish(MMI_FALSE);
		g_alm_cntx.active_alm_idx = 0xFF;

		mmi_frm_group_close(GRP_ID_ALM_IND);
     }
#ifndef __MMI_DEV_NEW_SLIM__
     else
     {
         AlmStopHandler();
     }
#endif
}


/*****************************************************************************
* FUNCTION
*  AlmActivateIndicator
* DESCRIPTION
*  Show alarm status icon in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void AlmActivateIndicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
#ifdef __MMI_SUBLCD__
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_ALARM);
#endif 
#endif 
    wgui_status_icon_bar_update();
}


/*****************************************************************************
* FUNCTION
*  AlmDeactivateIndicator
* DESCRIPTION
*  Hide alarm status icon in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void AlmDeactivateIndicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALARM);
#ifdef __MMI_SUBLCD__
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SUBLCD_ALARM);
#endif
#endif 
    wgui_status_icon_bar_update();
}


/*****************************************************************************
* FUNCTION
*  mmi_alm_play_tone_callback
* DESCRIPTION
*  Get Snooze Interval
* PARAMETERS
*  void
* RETURNS
*  Snooze interval
*****************************************************************************/
static srv_prof_ret mmi_alm_play_tone_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RETURN_VAL_IF_FAIL(g_alm_cntx.active_alm_idx < NUM_OF_ALM, SRV_PROF_RET_NO);

    MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE_CALLBACK, result);
	
    if (result != SRV_PROF_RET_PLAY_FINISHED)
    {
        srv_prof_play_tone(SRV_PROF_TONE_ALARM, NULL);
    }
     
    return SRV_PROF_RET_YES;
}


/*****************************************************************************
* FUNCTION
*  mmi_alm_play_tone
* DESCRIPTION
*  Get Snooze Interval
* PARAMETERS
*  void
* RETURNS
*  Snooze interval
*****************************************************************************/
static void mmi_alm_play_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 alarm_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

	MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE, 0);

    alarm_index = g_alm_cntx.active_alm_idx;
    RETURN_IF_FAIL(alarm_index < NUM_OF_ALM);

    if (!g_alm_cntx.is_tone_playing)
    {
         mdi_audio_suspend_background_play();
     
         /* Play special tone in call */
         if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
         {
#if 0
#ifndef	__OP01__		 	
/* under construction !*/
/* under construction !*/
#endif			 
#else
	MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE, 11);
	
	srv_prof_play_tone(ALARM_TONE_IN_CALL,NULL);
#endif
         }
         else
         {        
#if 0
#if defined(__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
/* under construction !*/
#endif 
#endif 
             {
#if defined (__MMI_PROFILE_HIGH_PRIORITY__)
						if (srv_prof_if_can_ring())
#endif
           {
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
                 alm_nvram_struct *alm_node = srv_alm_read(alarm_index);
             
                 if (alm_node->AudioOption == ALM_AUDIO_OPTIONS_TONE)
                 {
          #ifndef __MMI_ALARM_SLIM2__
                     if (alm_node->AudioOptionValue == ALARM_TONE_FILE)
                     {
                     	srv_prof_ret ret;
                     	MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE, 12);
                         ret = srv_prof_play_tone_with_filepath(
                                                SRV_PROF_TONE_ALARM, 
                                                (WCHAR*)alm_node->tone_path, 
                                                SRV_PROF_RING_TYPE_REPEAT, 
                                                mmi_alm_play_tone_callback);
                         
                         if (ret == SRV_PROF_RET_FAIL)
                         {
                             MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE, 13);
					#ifndef __MMI_DEV_NEW_SLIM__
                             srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
                                                    mmi_alm_default_ring_id(), 
                                                    SRV_PROF_RING_TYPE_REPEAT, 
                                                    NULL);
					#else
                             srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
                                                    ALARM_DEFAULT_RING_ID, 
                                                    SRV_PROF_RING_TYPE_REPEAT, 
                                                    NULL);			
					#endif
                         }

                     }
                     else
			#endif
                     {
                     	MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE, 14);
                         srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
                                                alm_node->AudioOptionValue, 
                                                SRV_PROF_RING_TYPE_REPEAT, 
                                                NULL);
                     }
                 }
#if 0
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__                 
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
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
#endif
#else /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
	    MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE, 17);
             srv_prof_play_tone(SRV_PROF_TONE_ALARM, NULL);
#endif
             }
             }
         }
		 
        g_alm_cntx.is_tone_playing = MMI_TRUE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_alm_stop_tone
* DESCRIPTION
*  Stops Any Alarm Tone that may be playing
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_alm_stop_tone(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
#if 0     
#if defined (__MMI_ALM_ALERT_TYPE__) || defined (__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
/* under construction !*/
#endif 
#else
#if defined (__MMI_ALM_ALERT_TYPE__) 
     U8 alert_type;
#endif 
#endif 
     U8 alarm_index = g_alm_cntx.active_alm_idx;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
	 MMI_ALM_TRACE1(MMI_ALM_STOP_TONE, g_alm_cntx.is_tone_playing);

     RETURN_IF_FAIL(alarm_index < NUM_OF_ALM);

     if (g_alm_cntx.is_tone_playing || g_mmi_alm_play_tone)
     {
     	srv_alm_node_type *node = srv_alm_read(alarm_index);
#if defined (__MMI_ALM_ALERT_TYPE__)

         alert_type = node->AlertType;
         switch (alert_type)
         {
             case ALM_ALERT_VIBRATION_AND_RING:
             case ALM_ALERT_RING:
		#ifdef __MMI_ALM_CUSTOMIZE_TONE__
	 	if (node->AudioOption == ALM_AUDIO_OPTIONS_TONE)
	 	{
		    srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
		}
		else
		{
		    mdi_audio_stop_fmr();
				/* If there is no earphone, default tone will be playing. */
				if (srv_prof_is_tone_playing(SRV_PROF_TONE_ALARM))
				{
					srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
				}
		}
		#else
		    srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
		#endif
                 break;
	#ifndef __MMI_DEV_NEW_SLIM__
             default:
                 break;
	#endif
         }
#else /* __MMI_ALM_ALERT_TYPE__ */

		#ifdef __MMI_ALM_CUSTOMIZE_TONE__
		 if (node->AudioOption == ALM_AUDIO_OPTIONS_TONE)
		 {
			 srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
		 }
		 else
		 {
			 mdi_audio_stop_fmr();
		 }
         #else
             srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
         #endif
#endif
         g_alm_cntx.is_tone_playing = MMI_FALSE;

         mdi_audio_resume_background_play();
     }

     mmi_alm_stop_vibrate();
}

#ifdef __MMI_ALM_CUST_VOLUME__
/*****************************************************************************
 * FUNCTION
 *  AlmPlayAlarmToneWithVol
 * DESCRIPTION
 *  Play alarm tone with setting volume level.
 * PARAMETERS
 *  volume      [IN]        
 *  U8(?)       [IN]        Volumn level
 * RETURNS
 *  void
 *****************************************************************************/
static void AlmPlayAlarmToneWithVol(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 alarm_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE_WITH_VOL, volume);
	
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    
    alarm_index = g_alm_cntx.active_alm_idx;
    RETURN_IF_FAIL(alarm_index < NUM_OF_ALM);

    if (!g_alm_cntx.is_tone_playing)
    {
        srv_prof_play_req_struct play_req;
        alm_nvram_struct *alm_node;
        srv_prof_audio_type_enum audio_type = SRV_PROF_AUDIO_STRING;
        
        mdi_audio_suspend_background_play();
#if 0
    #ifdef __MMI_PROFILE_ALERT_TYPE_DOMINANT__
/* under construction !*/
    #endif 
    #endif 
        {
            /* Added support for Alarm Audio Options i.e. FM Radio as alarm tone. */
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
            alm_node = srv_alm_read(alarm_index);
            if (alm_node->AudioOption == ALM_AUDIO_OPTIONS_TONE)
            {
                srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_ALARM);
                if (alm_node->AudioOptionValue == ALARM_TONE_FILE)
                {                    
                	MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE_WITH_VOL, 11);
                    if (srv_fmgr_fs_path_exist(alm_node->tone_path) < 0)
                    {
                    	MMI_ALM_TRACE1(MMI_ALM_PLAY_TONE_WITH_VOL, 12);
                        play_req.audio_id = g_alm_cntx.default_tone;
                    }
                    else
                    {
                        play_req.audio_path = alm_node->tone_path;
			audio_type = SRV_PROF_AUDIO_FILE;
                    }                    
                }
                else
                {
                    play_req.audio_id = alm_node->AudioOptionValue;
                }
                play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
                play_req.volume = volume;
                play_req.tone_type = SRV_PROF_TONE_ALARM;
                play_req.audio_path = MDI_DEVICE_SPEAKER_BOTH;
                play_req.callback = NULL;
		        play_req.audio_type = audio_type;
                srv_prof_play_tone_with_full_struct(&play_req);          
          }
#if 0
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
#endif
#else /* __MMI_ALM_CUSTOMIZE_TONE__ */
            srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_ALARM);

            play_req.audio_id = g_alm_cntx.default_tone;
            play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
            play_req.volume = volume;
            play_req.tone_type = SRV_PROF_TONE_ALARM;
            play_req.callback = NULL;
	        play_req.audio_type = audio_type;
            srv_prof_play_tone_with_full_struct(&play_req);
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

        }

        g_alm_cntx.is_tone_playing = MMI_TRUE;
    }
}
#endif /* __MMI_ALM_CUST_VOLUME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_stop_vibrate
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_stop_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_alm_cntx.vibing || g_mmi_alm_play_vib)
    {
#if 0
#if defined (__MMI_ALM_ALERT_TYPE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifndef __MMI_DEV_NEW_SLIM__
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
#elif defined(__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
/* under construction !*/
#endif
#else
#if defined (__MMI_ALM_ALERT_TYPE__)
		srv_alm_node_type *node = srv_alm_read(g_alm_cntx.active_alm_idx);

		switch (node->AlertType)
        {
            case ALM_ALERT_VIBRATION_AND_RING:
            case ALM_ALERT_VIBRATION:
                srv_vibrator_off();
                gui_touch_feedback_enable_vibrate();
                break;
	#ifndef __MMI_DEV_NEW_SLIM__
            default:
                break;
	#endif
        }
#endif
#endif

        g_alm_cntx.vibing = MMI_FALSE; 
    }
    
}

#define NMGR_HANDLER
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_nmgr_evt_tone_handlr
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_alm_nmgr_evt_tone_handlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_custom_evt_struct *evt = (mmi_nmgr_custom_evt_struct*)param;
    srv_alm_node_type *node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ALM_TRACE1(MMI_ALM_EVT_TONE_HDLR, 0);
	
    if (evt->scenario_id != MMI_SCENARIO_ID_REMINDER_ALARM)
    {
    	MMI_ALM_TRACE1(MMI_ALM_EVT_TONE_HDLR, 1);
       return MMI_RET_OK;
    }
    
    if (g_alm_cntx.active_alm_idx >= NUM_OF_ALM)
    {
    	MMI_ALM_TRACE1(MMI_ALM_EVT_TONE_HDLR, 2);
        return MMI_RET_OK;
    }

    #ifdef __MMI_ALM_ALERT_TYPE__
	node = srv_alm_read(g_alm_cntx.active_alm_idx);
    if (node->AlertType == ALM_ALERT_VIBRATION)
    {
    	MMI_ALM_TRACE1(MMI_ALM_EVT_TONE_HDLR, 3);
        return MMI_RET_OK;
    }
    #endif
	if (mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_REMINDER_ALARM,
										  mmi_alm_nmgr_expiry_callback,
										  NULL))
	{
    	MMI_ALM_TRACE1(MMI_ALM_EVT_VIB_HDLR, 4);
        if ((mmi_frm_get_active_scenario_id() == MMI_SCENARIO_ID_USB_WEBCAM)||
			(mmi_frm_get_active_scenario_id() == MMI_SCENARIO_ID_UCM_OUTGOING_CALL))
    	{
            /* Play a notification ring tone if in web camera screen */
#if 0
#ifndef	__OP01__			
/* under construction !*/
#endif
#else
            srv_prof_play_tone(ALARM_TONE_IN_CALL,NULL);
#endif
    	}
        return MMI_RET_OK;
	}	

    mmi_alm_play_tone();
	g_mmi_alm_play_tone = MMI_TRUE;
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_nmgr_evt_vib_handlr
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_alm_nmgr_evt_vib_handlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_custom_evt_struct *evt = (mmi_nmgr_custom_evt_struct*)param;
	srv_alm_node_type *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ALM_TRACE1(MMI_ALM_EVT_VIB_HDLR, 0);
	
    if (evt->scenario_id != MMI_SCENARIO_ID_REMINDER_ALARM)
    {
    	MMI_ALM_TRACE1(MMI_ALM_EVT_VIB_HDLR, 1);
       return MMI_RET_OK;
    }
    
    if (g_alm_cntx.active_alm_idx >= NUM_OF_ALM)
    {
    	MMI_ALM_TRACE1(MMI_ALM_EVT_VIB_HDLR, 2);
        return MMI_RET_OK;
    }

	if (mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_REMINDER_ALARM,
										  mmi_alm_nmgr_expiry_callback,
										  NULL))
	{
    	MMI_ALM_TRACE1(MMI_ALM_EVT_VIB_HDLR, 3);
        return MMI_RET_OK;
	}
	
#if 0
#if defined (__MMI_ALM_ALERT_TYPE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_PROFILE_HIGH_PRIORITY__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_DEV_NEW_SLIM__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#elif defined(__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PROFILE_ALERT_TYPE_DOMINANT__ */
#else
#if defined (__MMI_ALM_ALERT_TYPE__)
	node = srv_alm_read(g_alm_cntx.active_alm_idx);
    switch (node->AlertType)
    {
        case ALM_ALERT_VIBRATION_AND_RING:
        case ALM_ALERT_VIBRATION:
#if defined (__MMI_PROFILE_HIGH_PRIORITY__)
		 if (srv_prof_if_can_vibrate())
#endif
		{
            srv_vibrator_on();
            gui_touch_feedback_disable_vibrate();
            g_alm_cntx.vibing = MMI_TRUE;
			g_mmi_alm_play_vib = MMI_TRUE;
		}	
            break;
#ifndef __MMI_DEV_NEW_SLIM__
        default:
            break;
#endif
    }
#endif

#endif
    return MMI_RET_OK;
}

