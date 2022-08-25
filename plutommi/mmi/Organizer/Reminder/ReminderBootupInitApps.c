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
 *  ReminderBootupInitApps.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  RTC bootup init table.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "gdi_include.h"
#include "kal_general_types.h"
#include "mmi_rp_srv_reminder_def.h"
/****************************************************************************
 * Typedef
 ****************************************************************************/
#ifndef __MMI_ALARM_SLIM__

typedef struct
{
    mmi_proc_func hdlr;
} mmi_bootup_init_table_entry_struct;


/****************************************************************************
 * Handler table
 ****************************************************************************/

/* Declare function prototypes */
#define MMI_BOOTUP_INIT_REG_BEGIN(evt_id)
#define MMI_BOOTUP_INIT_REG(hdlr) extern mmi_ret hdlr(mmi_event_struct *evt);
#define MMI_BOOTUP_INIT_ADP(hdlr) \
    static mmi_ret hdlr##_adp(mmi_event_struct *evt) { extern void hdlr(void); hdlr(); return MMI_RET_OK; }

#define MMI_BOOTUP_INIT_REG_END(evt_id)
#include "ReminderBootupInitConfig.h"
#undef MMI_BOOTUP_INIT_REG_BEGIN
#undef MMI_BOOTUP_INIT_REG
#undef MMI_BOOTUP_INIT_ADP
#undef MMI_BOOTUP_INIT_REG_END

/* Generate the handler table */
#define MMI_BOOTUP_INIT_REG_BEGIN(evt_id) \
    static const mmi_bootup_init_table_entry_struct evt_id##_table[] = {
#define MMI_BOOTUP_INIT_REG(hdlr) { hdlr },
#define MMI_BOOTUP_INIT_ADP(hdlr) { hdlr##_adp },
#define MMI_BOOTUP_INIT_REG_END(evt_id) { NULL }  };
#include "ReminderBootupInitConfig.h"
#undef MMI_BOOTUP_INIT_REG_BEGIN
#undef MMI_BOOTUP_INIT_REG
#undef MMI_BOOTUP_INIT_ADP
#undef MMI_BOOTUP_INIT_REG_END

#define MMI_BOOTUP_INIT_GET_TABLE(evt_id) (evt_id##_table)

/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_reminder_bootup_init_apps
 * DESCRIPTION
 *  Invoke the callbacks in the table.
 * PARAMETERS
 *  evt     [IN] Event to be sent to the callbacks
 *  table   [IN] The callback table
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reminder_bootup_init_apps(
    mmi_event_struct *evt,
    const mmi_bootup_init_table_entry_struct *table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_bootup_init_table_entry_struct *entry;
#ifdef __MMI_BOOTUP_TIME_PROFILING__
    U32 curr_tick;
    U32 prev_tick;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&curr_tick);
#endif

    for (entry = table; entry->hdlr != NULL; entry++)
    {
        entry->hdlr(evt);
        
#ifdef __MMI_BOOTUP_TIME_PROFILING__
        prev_tick = curr_tick;
        kal_get_time(&curr_tick);
        MMI_TRACE(MMI_COMMON_TRC_FUNC, TRC_MMI_BOOTUP_INIT_TIME,
            (U32)(entry->hdlr), (curr_tick - prev_tick));
#endif
    }
}

#endif

#ifdef  __MMI_ALARM_SLIM__
static void mmi_reminder_bootup_init_apps(mmi_event_struct *evt)
{
	
		applib_dt_init_time();
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
		InitUnicodeSupport();
#endif
		PhnsetReadGPIOSetting();
		srv_backlight_init_context_early();
		mdi_audio_init();
		mmi_fe_init();
		InitFramework();/* Initialize framework */
		InitHardwareEvents();
		setup_UI_wrappers();
		PopulateResData();
		PowerAndEndKeyHandler();	/* deepali */
		initialize_UI_demo();
		InitChargerPwrOn();
		srv_prof_init();
		InitSettingNVRAM();
	 
#ifdef __MMI_USB_SUPPORT__
		InitMMIUsbContext();
#endif 
		mdi_audio_init_event_hdlrs();
		srv_reminder_init(NULL);		
#ifdef __MMI_THEMES_APPLICATION__
		InitThemes();
#endif 
		initialize_mainmenu_title_icons();/*for GetRootTitleIcon*/
	
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_reminder_bootup_start
 * DESCRIPTION
 *  Start RTC booting flow.
 *  This function is the handler of EVT_ID_SRV_REMINDER_BOOTUP_START.
 * PARAMETERS
 *  evt     :[IN] mmi_event_struct*
 * RETURNS
 *  Always MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_reminder_bootup_start(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct rmdr_evt;
#ifndef __MMI_ALARM_SLIM__
    const mmi_bootup_init_table_entry_struct *table;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(evt != NULL);
	if (evt->evt_id != EVT_ID_SRV_REMINDER_BOOTUP_START)
	{
		return MMI_RET_OK;
	}
	/* Init all related app. */
    MMI_FRM_INIT_EVENT(&rmdr_evt, EVT_ID_SRV_REMINDER_BOOTUP_INIT);  
#ifdef __MMI_ALARM_SLIM__

    mmi_reminder_bootup_init_apps(&rmdr_evt);
#else
    table = MMI_BOOTUP_INIT_GET_TABLE(EVT_ID_SRV_REMINDER_BOOTUP_INIT);
    mmi_reminder_bootup_init_apps(&rmdr_evt, table);
#endif
    
    /* Notify bootup complete event */
    MMI_FRM_INIT_EVENT(&rmdr_evt, EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE);
    MMI_FRM_CB_EMIT_EVENT(&rmdr_evt);
    
    return MMI_RET_OK;
}

