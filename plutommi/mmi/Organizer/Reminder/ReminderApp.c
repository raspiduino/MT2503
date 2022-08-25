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
 *  ReminderApp.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Test code from reminder service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#include "MMIDataType.h"
#include "ReminderSrvGprot.h"
#include "UsbDeviceGprot.h"
#include "PowerOnChargerProt.h"
#include "AlarmGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_app_alarm_def.h"
#include "BootupSrvGprot.h"
#include "Wgui_categories_util.h"

#ifdef __MMI_USB_SUPPORT__
#include "UsbSrvGprot.h"
#endif

/* For auto close timer in mmi_reminder_entry_pwron_confirm()*/
#include "TimerEvents.h"
#include "AlarmFrameworkProt.h"
#include "AlarmDef.h"
#include "GpioSrvGprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef MMI_BOOL (*srv_reminder_check_funcptr)(void);

/****************************************************************************
 * Define
 ****************************************************************************/
#define MMI_RMDR_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)

//#define __REMINDER_UT__
/****************************************************************************
 * Global variables
 ****************************************************************************/

/****************************************************************************
 * Local variables
 ****************************************************************************/
static srv_reminder_check_funcptr srv_reminder_util_check_table[] = 
{
	#ifdef __MMI_USB_SUPPORT__
	srv_usb_is_connected,
	#endif
	mmi_gpio_is_charger_connected,
#ifdef __USB_IN_NORMAL_MODE__
	srv_usb_is_in_mass_storage_mode,
#endif /* __USB_IN_NORMAL_MODE__ */
#ifdef __MMI_WEBCAM__
	mmi_usb_webcam_is_active,
#endif /* __MMI_WEBCAM__ */
	NULL
};


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_util_send_pwron
 * DESCRIPTION
 *  Display check disk screen, reset language, then send power on request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_reminder_can_pwroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	U32 count, j;
	MMI_BOOL ret = MMI_TRUE;
	
	srv_bootup_mode_enum bmode = srv_bootup_get_booting_mode();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/	
    if (bmode == SRV_BOOTUP_MODE_ALARM)
	{
	    return MMI_TRUE;
	}
    
	count = sizeof(srv_reminder_util_check_table) / sizeof(srv_reminder_check_funcptr);
	
	for (j = 0; j < count; j++)
	{
		/* if there is any existed AP, don't pwr-off */
		if (srv_reminder_util_check_table[j] != NULL &&
			srv_reminder_util_check_table[j]())
		{
			ret = MMI_FALSE;
			break;
		}
	}

	MMI_RMDR_TRACE1(MMI_RMDR_CAN_PWR_OFF, ret);
	
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_almfrm_confirm_int
 * DESCRIPTION
 *  Internal function for handle power on/off confirm 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_almfrm_confirm_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
	mmi_frm_scrn_close_active_id();	
    srv_reminder_notify_finish(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_almfrm_pwron
 * DESCRIPTION
 *  Check history before sending power off request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_almfrm_pwron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_almfrm_confirm_int();
	srv_reminder_util_send_pwron();
}

/*****************************************************************************
* FUNCTION
*  mmi_almfrm_poweroff
* DESCRIPTION
*  Check history before sending power off request.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_almfrm_poweroff(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    mmi_almfrm_confirm_int();
    srv_reminder_util_send_pwroff();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reminder_exit_pwron_confirm
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_reminder_exit_pwron_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    if (srv_reminder_is_expiring())
	{
        /* There is another reminder expiry */        
        mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_ALM_PWRON_CONFIRM);	
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_reminder_entry_pwron_confirm
* DESCRIPTION
*  Display confirmation screen to decide power on or not.
*  This screen is used for power off alarm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_reminder_entry_pwron_confirm(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     U8 *guiBuffer;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (!mmi_frm_scrn_enter(
             GRP_ID_ROOT, 
             SCR_ID_ALM_PWRON_CONFIRM, 
             (FuncPtr)mmi_reminder_exit_pwron_confirm, 
             (FuncPtr)mmi_reminder_entry_pwron_confirm, 
             MMI_FRM_FULL_SCRN))
     {
         return;
     }
     
     //mmi_alm_disable_pwroff();
	 
     guiBuffer = mmi_frm_scrn_get_active_gui_buf();
     
	 EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
     if (!IsMyTimerExist(ALARM_ALERT_NOTIFYDURATION_TIMER))
     {
         StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, mmi_almfrm_poweroff);
     }    
	 srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
     ShowCategory123Screen(
         STR_GLOBAL_ALARM,
         0,
         STR_GLOBAL_YES,
         IMG_GLOBAL_YES,
         STR_GLOBAL_NO,
         IMG_GLOBAL_NO,
         ALARMS_POWER_ON,
         mmi_get_event_based_image(MMI_EVENT_QUERY),
         guiBuffer);

     SetLeftSoftkeyFunction(mmi_almfrm_pwron, KEY_EVENT_UP);
     SetRightSoftkeyFunction(mmi_almfrm_poweroff, KEY_EVENT_UP);
     ClearKeyHandler(KEY_END, KEY_EVENT_UP);
     ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
     //SetKeyHandler(mmi_almfrm_pwron, KEY_END, KEY_LONG_PRESS);
	 SetKeyLongpressHandler(mmi_almfrm_pwron, KEY_END);
     SetCenterSoftkeyFunction(mmi_almfrm_pwron, KEY_EVENT_UP);

#ifndef __MMI_DEV_NEW_SLIM__
#ifdef __MMI_SUBLCD__
     /* to prevent double displayed this screen */
     mmi_frm_nmgr_notify_sublcd(MMI_SCENARIO_ID_REMINDER_ALARM);
#endif
#endif

}


mmi_ret mmi_reminder_on_pwrreset_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	srv_reminder_pwrreset_evt_struct *pwr_evt;
	srv_bootup_mode_enum mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/
	MMI_ASSERT(evt != NULL);
	
	if (evt->evt_id != EVT_ID_SRV_REMINDER_PWRRESET_REQ)
	{
		return MMI_RET_OK;
	}
	
	pwr_evt = (srv_reminder_pwrreset_evt_struct *)evt;
	mode = srv_bootup_get_booting_mode();
	switch(mode)
	{
		case SRV_BOOTUP_MODE_USB:
		case SRV_BOOTUP_MODE_CHARGE:
		case SRV_BOOTUP_MODE_PRECHARGE:
		{
        	srv_reminder_util_send_pwroff();
            break;
		}

        case SRV_BOOTUP_MODE_ALARM:
		{
			if (!pwr_evt->pwr_confirm)
			{
			    srv_reminder_util_send_pwroff();
			}
			else
			{
                mmi_reminder_entry_pwron_confirm();
			}
			break;
		}

		default:
		{
            srv_reminder_notify_finish(MMI_FALSE);
			break;
		}
	}

	return MMI_RET_OK;
}

/****************************************************************************
 * Test Framework
 ****************************************************************************/
#if 0
#ifdef __REMINDER_UT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __REMINDER_UT__ */
#endif

mmi_ret mmi_remdr_ut_notify_hdlr(mmi_event_struct *evt)
{
#ifdef __REMINDER_UT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if(evt == NULL)
	{
		return MMI_RET_ERR;
	}
	
	if(evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_INIT");
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_EXPIRY");
			srv_reminder_notify_finish(MMI_TRUE);
			break;

		case SRV_REMINDER_NOTIFY_REINIT:
			mmi_rmdr_ut_add1(NULL);
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_REINIT");
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_DEINIT");
			srv_reminder_notify_finish(MMI_TRUE);
			break;

		default:
			break;
	}


	return MMI_RET_ERR;
#else /* __REMINDER_UT__ */
	return MMI_RET_OK;
#endif /* __REMINDER_UT__ */

}

void mmi_reminder_ut(U8 index)
{
#ifdef __REMINDER_UT__

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // kal_prompt_trace(MOD_MMI, "[ReminderApp.c] welcome to Reminder UT! ");
	
    if (index == 0)
    {
        StartTimer(KEY_TIMER_ID_NONE, 2000, mmi_reminder_ut_timer);
    }
    else
    {
        for (i = 0; i < ARRAY_COUNT(g_mmi_rmdr_ut); i++)
        {
            if (g_mmi_rmdr_ut[i].index == index)
            {
                g_mmi_rmdr_ut[i].test(NULL);
				break;
            }
        }
    }
#else
	//kal_prompt_trace(MOD_MMI, "[ReminderApp.c] Please open UT mode! ");	  
#endif /* __REMINDER_UT__ */
}



