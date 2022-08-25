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
 *  FactoryAlarm.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  factory alarm implement file, facotry mode owner should move these code to its own source file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "DateTimeGprot.h"
#include "ReminderSrvGprot.h"
#include "DateTimeType.h"

#include "mmi_rp_app_alarm_def.h"
#include "AlarmGprot.h"
#include "AlarmDef.h"
#include "mmi_rp_srv_reminder_def.h"
#include "TimerEvents.h"
#include "AlarmFrameworkProt.h"
#include "Wgui_categories_util.h"
#include "AlarmProt.h"

static U8 FactoryExpiryHandler(U8 Index, U16 *period, BOOL power_on);
static mmi_ret mmi_factory_alm_proc(mmi_event_struct* evt);
static void mmi_facotry_alm_exit_scr(void);
static void mmi_facotry_alm_entry_scr(void);

extern void srv_reminder_util_send_pwron(void);
extern void srv_reminder_util_send_pwroff(void);
extern void srv_reminder_util_pwroff_req(void);
#ifndef __MMI_RTC_TEST_SLIM__

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
mmi_ret mmi_factory_alm_remdr_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;
	U16 period;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(evt != NULL, MMI_RET_ERR);
	RETURN_VAL_IF_FAIL(evt->evt_id == EVT_ID_SRV_REMINDER_NOTIFY, MMI_RET_OK);
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	RETURN_VAL_IF_FAIL(remdr_evt->reminder_type == SRV_REMINDER_TYPE_FACTORY || 
					   remdr_evt->reminder_type == SRV_REMINDER_TYPE_TOTAL, 
					   MMI_RET_OK);
	
	switch(remdr_evt->notify)
	{		
		case SRV_REMINDER_NOTIFY_EXPIRY:
			FactoryExpiryHandler(remdr_evt->usr_data, &period, !remdr_evt->pwr_off);
			break;
			
		default:
			break;
	}

	return MMI_RET_OK;
}
#endif

static void mmi_factory_alm_set_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
		srv_reminder_util_pwroff_req();
#else
		exit(0);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_factory_alm_set
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  index           [IN]        
 *  alarmTime       [?]         
 *  Freq            [?]         
 *  WeekDays        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_factory_alm_set(U8 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime, alarmTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(sec < 60);
	
    DTGetRTCTime(&alarmTime);
    memset(&incTime, 0, sizeof(MYTIME));
    incTime.nSec = sec;
    IncrementTime(alarmTime, incTime, &alarmTime);
	
	srv_reminder_set_with_callback(
		SRV_REMINDER_TYPE_FACTORY, 
		&alarmTime,
		mmi_factory_alm_set_callback,
		NULL,
		0);	
}
#ifndef __MMI_RTC_TEST_SLIM__

static MMI_BOOL mmi_factory_alm_nmgr_callback(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DEV_NEW_SLIM__
	mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_ALM_IND, mmi_factory_alm_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_ALM_IND, mmi_factory_alm_proc, NULL);
	mmi_frm_group_enter(GRP_ID_ALM_IND, MMI_FRM_NODE_SMART_CLOSE_FLAG); 
#endif

	mmi_facotry_alm_entry_scr();
	
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  FactoryExpiryHandler
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  Index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 FactoryExpiryHandler(U8 Index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!power_on)
    {
        gdi_init();
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_REMINDER_OTHER,
                                   MMI_EVENT_REMINDER_OTHER,
                                   mmi_factory_alm_nmgr_callback,
                                   NULL);
        return ALM_HAS_IND;
    }
    else
    {
        srv_reminder_notify_finish(MMI_FALSE);
    }
    
    return ALM_HAS_NO_IND;
}

static void mmi_facotry_alm_exit_scr(void)
{
	mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_OTHER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_factory_alm_proc
 * DESCRIPTION
 *  Group event process function for alarm indication
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_factory_alm_proc(mmi_event_struct* evt)
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
		mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_OTHER);
        mmi_frm_group_close(GRP_ID_ALM_IND);
        break;
        
    default:
        break;
    }

    return MMI_RET_OK;
}

static void mmi_facotry_alm_lsk_hdlr(void)
{
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
	mmi_frm_group_close(GRP_ID_ALM_IND);
	srv_reminder_util_send_pwron();
}

static void mmi_facotry_alm_entry_scr(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     U8 *guiBuffer;
     MYTIME currTime;
     U8 timeString[SIZE_OF_DATE_STRING];
     static U8 dateString[SIZE_OF_ALARM_STRING + SIZE_OF_DATE_STRING];

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (!mmi_frm_scrn_enter(
             GRP_ID_ALM_IND, 
             SCR_ID_ALM_INDICATION, 
             mmi_facotry_alm_exit_scr, 
             (FuncPtr)mmi_facotry_alm_entry_scr, 
             MMI_FRM_FULL_SCRN))
     {
         return;
     }

     StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, srv_reminder_util_send_pwroff);
	 
     mmi_frm_start_scenario(MMI_SCENARIO_ID_REMINDER_OTHER);

     GetDateTime(&currTime);
     time_string(&currTime, (UI_string_type)timeString, DT_IDLE_SCREEN);

     memset(dateString, 0, ENCODING_LENGTH);
     mmi_ucs2cpy((CHAR*) dateString, (CHAR*) L"\n");
     mmi_ucs2cat((CHAR*) dateString, (CHAR*) GetString(ALARMS_POWER_ON));

     /* flush key because alarm if some key is not released, the alarm may be stopped */
     ClearKeyEvents();

     guiBuffer = mmi_frm_scrn_get_active_gui_buf();
  
     EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

     ShowCategory121Screen(
         STR_GLOBAL_YES,
         IMG_GLOBAL_YES,
         STR_GLOBAL_NO,
         IMG_GLOBAL_NO,
         dateString,
         0, //ALARM_ANIMATION_INDICATION_IMAGEID,
         guiBuffer,
         1);

     SetLeftSoftkeyFunction(mmi_facotry_alm_lsk_hdlr, KEY_EVENT_UP);
     SetRightSoftkeyFunction(srv_reminder_util_send_pwroff, KEY_EVENT_UP);
     SetCenterSoftkeyFunction(mmi_facotry_alm_lsk_hdlr, KEY_EVENT_UP);
     
}

#endif
