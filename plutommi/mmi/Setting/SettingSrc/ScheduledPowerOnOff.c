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
 * ScheduledPowerOnOff.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is intends for scheduled power on / off application
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2004
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * SchedulePowerOnOff.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements schedule power on of applications.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Settings Application implementation *********************/

/**************************************************************

   FILENAME : ScheduledPowerOnoff.c

   PURPOSE     : Scheduled power on of fhandling

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : 

**************************************************************/
#ifndef _MMI_SCHEDULEPOWERONOFF_C
#define _MMI_SCHEDULEPOWERONOFF_C

/*  Include: MMI header file */
#include "MMI_features.h"
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
#include "AlarmFrameworkProt.h"
#include "AlarmGprot.h"
//#include "ToDoListResDef.h"
#include "TodolistGprot.h"
#include "ScheduledPowerOnOff.h"
#include "ScheduledPowerOnOffGprot.h"

#include "ProfilesSrvGprot.h"
#include "UCMGprot.h"
#include "JavaAgencyDef.h"
#include "Menucuigprot.h"
#include "PhoneSetup.h"
#include "Inlinecuigprot.h"
#include "NotificationGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /*__USB_IN_NORMAL_MODE__*/
#include "Mdi_audio.h" // for suspend and resume audio play when display power off confirm popup
#include "ShutdownSrvGprot.h"

/* auto add by kw_check begin */
#include "mmi_rp_srv_spof_def.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "app_datetime.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_inline_edit.h"
#include "GlobalConstants.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "AlertScreen.h"
#include "mmi_pluto_res_range_def.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMI_trc_Int.h"
#include "wgui_categories_list.h"
#include "GpioSrvGprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "UcmSrvGprot.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "wgui.h"
#include "mmi_rp_app_alarm_def.h"
#include "UCMGProt.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "mmi_rp_app_uiframework_def.h"
/* auto add by kw_check end */
/* ... Add More MMI header */
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "ScrLockerGprot.h"
/*  Include: PS header file */
/* ... Add More PS header */
#include "AlarmProt.h"      
#include "MMI_ap_dcm_config.h"
#include "AlarmDef.h"
/* 
 * Define
 */
#define PHNSET_SPOF_CAPTION1 (CUI_INLINE_ITEM_ID_BASE + 1)
#define PHNSET_SPOF_SELECT1 (CUI_INLINE_ITEM_ID_BASE + 2)
#define PHNSET_SPOF_TIME1 (CUI_INLINE_ITEM_ID_BASE + 3)
/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
/* For inline CUI */
const static U16 g_spof_status_str_id[] = {SPOF_DISABLE_STRINGID, SPOF_ENABLE_STRINGID};

const static cui_inline_item_caption_struct g_spof_inline_caption1 = 
{
    SPOF_STATUS_STRINGID
};
const static cui_inline_item_select_struct g_spof_inline_select1 = 
{
    2, /* Enable and Disable */
    0,
    g_spof_status_str_id
};

const static cui_inline_item_time_struct g_spof_inline_time1 = 
{
    {0, 0, 0, 0, 0, 0},
    0
};
const static cui_inline_set_item_struct g_spof_inline_data[] =
{
    {PHNSET_SPOF_CAPTION1, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_spof_inline_caption1},
    {PHNSET_SPOF_SELECT1, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_spof_inline_select1},
    {PHNSET_SPOF_TIME1, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, NULL, &g_spof_inline_time1}    
};
const static cui_inline_struct g_spof_inline =
{
    sizeof(g_spof_inline_data) / sizeof(cui_inline_set_item_struct),
    STR_GLOBAL_EDIT,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_spof_inline_data
};
/* 
 * Local Function
 */

/* 
 * Global Variable
 */
spof_context_struct g_spof_cntx;

/* 
 * Global Function
 */
#ifdef __J2ME__
extern void jam_pause_dummy_screen(void);
extern void jam_resume_dummy_screen(void);
#endif /* __J2ME__ */ 

static void SpofShutDownPowerOffConfirmation(void);
static mmi_ret mmi_spof_setting_proc(mmi_event_struct *param);
static void mmi_init_spof_setting_list(mmi_menu_id menu_id, MMI_ID menu_cui_gid);
static MMI_BOOL mmi_spof_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg);
static void mmi_spof_entry_power_off_confirm(void);
static void mmi_spof_entry_power_off_confirm_init(mmi_scrn_essential_struct *scrn_data);
static mmi_ret mmi_spof_power_off_confirm_leave_proc(mmi_event_struct *evt); 
static void SpofSaveData(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  SPOFInitNvRam
 * DESCRIPTION
 *  Read nvram data of SPOF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFInitNvRam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_SPOF_DATA_SIZE];
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, &nvram_buf, NVRAM_ALM_SPOF_DATA_SIZE, &error);
    memcpy(g_spof_cntx.SPOFList, nvram_buf, sizeof(g_spof_cntx.SPOFList));

    /* zero initialized */
    if (g_spof_cntx.SPOFList[0].Hour > NUM_HRS_DAY)
    {
        memset(&g_spof_cntx.SPOFList, 0, sizeof(g_spof_cntx.SPOFList));
    }

    for (i = 0; i < NUM_OF_SPOF; i++)
	{
        if (i < SPOF_EACH_SCHEDULE_NUM)
    	{
    		g_spof_cntx.SPOFList[i].Type = SPOF_POWERON;    	
    	}
        else
        {
            g_spof_cntx.SPOFList[i].Type = SPOF_POWEROFF;    	
        }
	}

    /* no require to set any alarm */
}


/*****************************************************************************
 * FUNCTION
 *  SPOFReInitQueueCBH
 * DESCRIPTION
 *  Reinit SPOF to alarm queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "SPOFReInitQueueCBH");    
    for (i = 0; i < NUM_OF_SPOF; i++)
    {
        if (g_spof_cntx.SPOFList[i].Status == 1)
        {
            /* save the alarm in the nvram */
            MYTIME set_time, calc_time; 
            srv_reminder_type type;

            DTGetRTCTime(&set_time);
            set_time.nMin = g_spof_cntx.SPOFList[i].Min;
            set_time.nHour = g_spof_cntx.SPOFList[i].Hour;
            set_time.nSec = 0;
            calc_time = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
        
            if (g_spof_cntx.SPOFList[i].Type == SPOF_POWERON)
            {
                type = SRV_REMINDER_TYPE_SPON;
            }
            else
            {
                type = SRV_REMINDER_TYPE_SPOF;
            }
            srv_reminder_set(type, &calc_time, i);
        }
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "SPOFReInitQueueCBH id: %d, status: %d, type: %d", i, g_spof_cntx.SPOFList[i].Status, g_spof_cntx.SPOFList[i].Type); 
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "SPOFReInitQueueCBH hour %d, min %d", g_spof_cntx.SPOFList[i].Hour, g_spof_cntx.SPOFList[i].Min); 
    }

}


/*****************************************************************************
 * FUNCTION
 *  SponExpiryHandler
 * DESCRIPTION
 *  CallBack handler to execute SPON expiry.
 * PARAMETERS
 *  sponIndex       [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
U8 SponExpiryHandler(U8 sponIndex, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME set_time, resTime; 
    srv_reminder_type type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "SponExpiryHandler %d, %d, %d", sponIndex, (*period), power_on);
    *period = 0;

        GetDateTime(&set_time);
        set_time.nMin = g_spof_cntx.SPOFList[sponIndex].Min;
        set_time.nHour = g_spof_cntx.SPOFList[sponIndex].Hour;
        set_time.nSec = 0;
		
        resTime = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
        srv_reminder_set(SRV_REMINDER_TYPE_SPON, &resTime, sponIndex);

	if (power_on)
    {
        srv_reminder_notify_finish(MMI_FALSE);
    }
    else
    {
        //AlmSendPowerOn();
        srv_reminder_util_send_pwron();
    }
    #ifndef __MMI_DEV_NEW_SLIM__
      return ALM_HAS_NO_IND;
    #else
      return MMI_FALSE;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  SpofExpiryHandler
 * DESCRIPTION
 *  CallBack handler to execute SPOF expiry.
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
U8 SpofExpiryHandler(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME set_time, resTime; 
	srv_reminder_type type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "SponExpiryHandler %d, %d, %d", index, (*period), power_on);    
    *period = ALM_DEFAULT_EXPIRY_PERIOD;
	
    GetDateTime(&set_time);
    set_time.nMin = g_spof_cntx.SPOFList[index].Min;
    set_time.nHour = g_spof_cntx.SPOFList[index].Hour;
    set_time.nSec = 0;
	
    resTime = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
    srv_reminder_set(SRV_REMINDER_TYPE_SPOF, &resTime, index);
	
    if (power_on)
    {
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF,
                                         MMI_EVENT_SCHEDULE_POWER_OFF,
                                         mmi_spof_nmgr_expiry_callback,
                                         NULL);            	
        #ifndef __MMI_DEV_NEW_SLIM__
           return ALM_HAS_IND;
        #else
           return MMI_TRUE;
         #endif
    }
    else
    {
        srv_reminder_notify_finish(MMI_FALSE);        
        *period = ALM_WITHOUD_EXPIRY_PERIOD;
        #ifndef __MMI_DEV_NEW_SLIM__
              return ALM_HAS_NO_IND;
        #else
              return MMI_FALSE;
        #endif
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  EntrySpofApp
 * DESCRIPTION
 *  Entry function of schedule power on off application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySpofApp(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create_ex(
		parent_id,
        GRP_ID_PHNSET_SCHEDULE_POWER,
        mmi_spof_setting_proc,
        NULL,
		MMI_FRM_NODE_SMART_CLOSE_FLAG);
    menu_cui_gid = cui_menu_create(
        GRP_ID_PHNSET_SCHEDULE_POWER,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_SETTING_SCHEDULE_POWER,
        MMI_FALSE,
        NULL);

    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SCR_SETTING_CAPTION);  

    cui_menu_run(menu_cui_gid);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spof_entry_sub_menu
 * DESCRIPTION
 *  Entry the sub menu of schedule power on/off 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_spof_entry_sub_menu(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_cui_gid;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create_and_run(
        GRP_ID_PHNSET_SCHEDULE_POWER,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        menu_id,
        MMI_FALSE,
        NULL);

    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SCR_SETTING_CAPTION); 

    //cui_menu_run(menu_cui_gid);   
}
 

/*****************************************************************************
 * FUNCTION
 *  EntrySpofEdit
 * DESCRIPTION
 *  Entry function of inline editor screen of schedule power on off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySpofEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inlinecui_gid;
    cui_inline_set_item_time_struct spof_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inlinecui_gid = cui_inline_create(GRP_ID_PHNSET_SCHEDULE_POWER, &g_spof_inline);

    cui_inline_set_value(inlinecui_gid, PHNSET_SPOF_SELECT1, (void*)g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Status);

    memset(&spof_time, 0, sizeof(cui_inline_set_item_time_struct));
   
    spof_time.date_time.hour = (U16)g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Hour;
    spof_time.date_time.minute = (U16)g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Min;

    cui_inline_set_value(inlinecui_gid, PHNSET_SPOF_TIME1, (void*)&spof_time);

    //cui_inline_set_all_items_softkey_text(inlinecui_gid, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);

    cui_inline_run(inlinecui_gid);

    
}


/*****************************************************************************
 * FUNCTION
 *  SpofSaveData
 * DESCRIPTION
 *  Save SPOF data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SpofSaveData(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 NewHour, NewMin;
    cui_inline_set_item_time_struct spof_time;
    MYTIME set_time, calc_time; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        cui_id,
        PHNSET_SPOF_TIME1,
        (void*)&spof_time);
    NewHour = (U8)spof_time.date_time.hour;
    NewMin =  (U8)spof_time.date_time.minute;

    cui_inline_get_value(
        cui_id,
        PHNSET_SPOF_SELECT1,
        (void*)&g_spof_cntx.CurrHiliteActivation);    

   
    if (SpofIsTimeClash(NewHour, NewMin))
    {
		mmi_popup_display_simple_ext(SPOF_TIME_CONFLICT, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return;
    }

    /* if setting changed */
    if (g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Hour != NewHour ||
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Min != NewMin ||
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Status != g_spof_cntx.CurrHiliteActivation)
    {
        /* fill the SPOFList structure depending on the selected values */
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Status = (U8) g_spof_cntx.CurrHiliteActivation;
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Hour = NewHour;
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Min = NewMin;

        /* save the alarm in the nvram */
        SpofWritetoNvram();

        GetDateTime(&set_time);
        set_time.nMin = NewMin;
        set_time.nHour = NewHour;
        set_time.nSec = 0;
        calc_time = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
        if (g_spof_cntx.CurrHiliteActivation == SPOF_ENABLE)
        {
            srv_reminder_type type;
            if (g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Type == SPOF_POWERON)
            {
                type = SRV_REMINDER_TYPE_SPON;
            }
            else
            {
                type = SRV_REMINDER_TYPE_SPOF;
            }
            srv_reminder_cancel(type, g_spof_cntx.CurrItem);
            srv_reminder_set(type, &calc_time, g_spof_cntx.CurrItem);
        }
        else
        {
            srv_reminder_cancel(SRV_REMINDER_TYPE_SPON, g_spof_cntx.CurrItem);
            srv_reminder_cancel(SRV_REMINDER_TYPE_SPOF, g_spof_cntx.CurrItem);        
        }
    }

	mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_ROOT,
		NULL);

    cui_inline_close(cui_id);

}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  SpofWritetoNvram
 * DESCRIPTION
 *  Write SPOF Value to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofWritetoNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_SPOF_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvram_buf, 0, NVRAM_ALM_SPOF_DATA_SIZE);
    memcpy(nvram_buf, g_spof_cntx.SPOFList, sizeof(g_spof_cntx.SPOFList));
    WriteRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, (void*)nvram_buf, NVRAM_ALM_SPOF_DATA_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  SpofIsTimeClash
 * DESCRIPTION
 *  To check if the setting time clashes with other SPOF alarm
 * PARAMETERS
 *  hour        [IN]        Hour to be compared.
 *  min         [IN]        Min to be compared.
 * RETURNS
 *  TRUE if clash, otherwise FALSE.
 *****************************************************************************/
BOOL SpofIsTimeClash(U8 hour, U8 min)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_spof_cntx.CurrHiliteActivation == SPOF_ENABLE)
    {
        for (i = 0; i < NUM_OF_SPOF; i++)
        {
            if (i != g_spof_cntx.CurrItem)
                if (g_spof_cntx.SPOFList[i].Status == SPOF_ENABLE && hour == g_spof_cntx.SPOFList[i].Hour &&
                    min == g_spof_cntx.SPOFList[i].Min)
                {
                    return TRUE;
                }
        }
    }

    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spof_auto_shutdown
 * DESCRIPTION
 *  Auto shutdown the phone 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spof_auto_shutdown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if ((group_id == GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM) && (screen_id == SCR_ID_SPOF_CONFIRM) && (!srv_ucm_is_any_call()))
    {
        srv_shutdown_normal_start(0);
        srv_reminder_notify_finish(MMI_FALSE);
    }
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_spof_nmgr_expiry_callback
 * DESCRIPTION
 *  Callback function for NMGR 
 * PARAMETERS
 *  
 * RETURNS
 *  static MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_spof_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_spof_entry_power_off_confirm();
    return MMI_TRUE;
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_spof_entry_power_off_confirm
 * DESCRIPTION
 *  Entry schedule power off confirm screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_spof_entry_power_off_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not create a new screen when the power off screen is exist */
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM))
	{
        return;
    }
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM,
        mmi_spof_setting_proc, 
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
        GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM,
        SCR_ID_SPOF_CONFIRM,
        (FuncPtr)mmi_spof_entry_power_off_confirm_init,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spof_entry_power_off_confirm_init
 * DESCRIPTION
 *  Internal function for entry schedule power off confirm 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_spof_entry_power_off_confirm_init(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM,
            SCR_ID_SPOF_CONFIRM,
            NULL,
            (FuncPtr)mmi_spof_entry_power_off_confirm_init,
            MMI_FRM_FULL_SCRN))
	{
	    return;
	}
    mmi_frm_start_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    if (!mmi_is_redrawing_bk_screens() && !srv_ucm_is_any_call())
    {
        StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, mmi_spof_auto_shutdown);
        if (!mmi_frm_is_in_backward_scenario())
    	{
            mdi_audio_suspend_background_play();	
    	}
    }

    if (srv_ucm_is_any_call())
	{
        StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);	    
	}
	mmi_frm_nmgr_block_sound_vib_stop(MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM, SCR_ID_SPOF_CONFIRM);
    
    ShowCategory123Screen(
        SPOF_MAIN_TITLE_STRINGID,
        0,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        SPOF_POWER_OFF_CONFIRM,
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        guiBuffer);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_spof_entry_power_off_confirm_init()");        

    SetLeftSoftkeyFunction(SpofShutDownPowerOffConfirmation, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(SpofShutDownPowerOffConfirmation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SpofStopPowerOffConfirmation, KEY_EVENT_UP);
    SetKeyHandler(SpofStopPowerOffConfirmation, KEY_END, KEY_EVENT_DOWN); 
    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_UP);
//    SetKeyHandler(ShutdownSystemOperation, KEY_END, KEY_LONG_PRESS);
    mmi_frm_scrn_set_leave_proc(GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM, SCR_ID_SPOF_CONFIRM, mmi_spof_power_off_confirm_leave_proc);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spof_power_off_confirm_leave_proc
 * DESCRIPTION
 *  Leave proc for power off confirm screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_spof_power_off_confirm_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the confirm screen is in history stack, display confirm screen again */
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_spof_power_off_confirm_leave_proc()");    
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        return MMI_RET_PROHIBIT_SCRN_ENTER;
    }
    else
#endif
    {
        return MMI_RET_ALLOW_CLOSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SpofShutDownPowerOffConfirmation
 * DESCRIPTION
 *  Stop power off confirm screen manually.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SpofShutDownPowerOffConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);
	
	mmi_frm_nmgr_unblock_sound_vid_stop(MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND);
    mmi_frm_nmgr_control_end();
    if(srv_ucm_is_any_call())
    {
        mmi_ucm_app_entry_error_message();
        mdi_audio_resume_background_play();
        srv_reminder_notify_finish(MMI_FALSE);
        return;
    }
    else
    {
        srv_reminder_notify_finish(MMI_FALSE);
        srv_shutdown_normal_start(SRV_SPOF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SpofStopPowerOffConfirmation
 * DESCRIPTION
 *  Stop power off confirm screen manually.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofStopPowerOffConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "SpofStopPowerOffConfirmation()");
    mmi_frm_scrn_set_leave_proc(GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM, SCR_ID_SPOF_CONFIRM, NULL);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);
	mmi_frm_nmgr_unblock_sound_vid_stop(MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND);
    mmi_frm_nmgr_control_end();
    mdi_audio_resume_background_play();
    srv_reminder_notify_finish(MMI_FALSE);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_SPOF_CONFIRM)
    {
        mmi_frm_group_close(GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM);	
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spof_setting_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_spof_setting 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_spof_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)param; 
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)param;
	cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_GROUP_DEINIT)
	{
	    if (mmi_frm_group_get_active_id() == GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM)
	    {
                MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_spof_setting_proc()");    
                mmi_frm_end_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);
				
				mmi_frm_nmgr_unblock_sound_vid_stop(MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND);
                mmi_frm_nmgr_control_end();
	    }
	}
    if (cui_menu_is_menu_event(param->evt_id))
	{
        switch (param->evt_id)
        {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_init_spof_setting_list(menu_evt->parent_menu_id, menu_evt->sender_id);
            return MMI_RET_OK;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if (menu_evt->parent_menu_id == MENU_SETTING_SCHEDULE_POWER)
            {
                mmi_spof_entry_sub_menu(menu_evt->highlighted_menu_id);
            }
			else if (menu_evt->parent_menu_id == MENU_SETTING_SCHEDULE_POWER_ON
				|| menu_evt->parent_menu_id == MENU_SETTING_SCHEDULE_POWER_OFF)
			{
				g_spof_cntx.CurrItem = (U8)((cui_menu_event_struct*)param)->highlighted_menu_id;

				if (menu_evt->parent_menu_id == MENU_SETTING_SCHEDULE_POWER_OFF)
				{
					/* Change index for Schedule power off items */
					g_spof_cntx.CurrItem += SPOF_EACH_SCHEDULE_NUM;
				}
				EntrySpofEdit();
			}
            return MMI_RET_OK;        
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(((cui_menu_event_struct*)param)->sender_id);
            return MMI_RET_OK;
            
        default:
    		break;
        }	
	}
    switch (param->evt_id)
	{
	case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        SpofSaveData(submit_evt->sender_id);
        return MMI_RET_OK;

    case EVT_ID_CUI_INLINE_ABORT:
		cui_inline_close(submit_evt->sender_id);
        return MMI_RET_OK;
	case EVT_ID_CUI_INLINE_NOTIFY:
		if (notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
		{
			cui_inline_set_softkey_text(
				notify_event->sender_id, 
				notify_event->item_id,
				MMI_LEFT_SOFTKEY,
				STR_GLOBAL_SAVE);
		}
		return MMI_RET_OK;
	default:
		break;
	}
    return MMI_RET_OK;
}
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_spof_reminder_srv_proc
 * DESCRIPTION
 *  Proc function for reminder service 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_spof_reminder_srv_proc(mmi_event_struct *evt)
    	{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_reminder_evt_struct *reminder_evt = (srv_reminder_evt_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_spof_reminder_srv_proc id (%d)", evt->evt_id);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_spof_reminder_srv_proc type (%d)", reminder_evt->reminder_type);
    if ((reminder_evt->reminder_type != SRV_REMINDER_TYPE_SPON 
         && reminder_evt->reminder_type != SRV_REMINDER_TYPE_SPOF
         && reminder_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL) 
        || reminder_evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
	    return MMI_RET_OK;
	}
    switch (reminder_evt->notify)
	{
    case SRV_REMINDER_NOTIFY_INIT:
        SPOFInitNvRam();
        break;
        
    case SRV_REMINDER_NOTIFY_EXPIRY:
    {
        U16 period;
        if (reminder_evt->reminder_type == SRV_REMINDER_TYPE_SPON)
    	{
    	    SponExpiryHandler(reminder_evt->usr_data, &period, !reminder_evt->pwr_off);
    	}
        else
        {
    	    SpofExpiryHandler(reminder_evt->usr_data, &period, !reminder_evt->pwr_off);            
        }
        break;
    }
        
    case SRV_REMINDER_NOTIFY_REINIT:
        SPOFReInitQueueCBH();
        break;
        
    case SRV_REMINDER_NOTIFY_DEINIT:
        if (reminder_evt->reminder_type == SRV_REMINDER_TYPE_SPOF)        
        {
            SpofStopPowerOffConfirmation();
        }
		break;
	default:
		break;
	}
    return MMI_RET_OK;
}
 
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_init_spof_sub_menu
 * DESCRIPTION
 *  Init sub menu of schedule power on / off 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_init_spof_sub_menu(U32 type, MMI_ID menu_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_items = SPOF_EACH_SCHEDULE_NUM;
    U16 spof_states_icon[NUM_OF_SPOF];
    MYTIME tmpTime;
    U8 i;
	U8 index;
    mmi_menu_id *menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spof_cntx.CurrItem = 0;

    /* initialize list to display */
    for (i = 0; i < num_of_items; i++)
    {
		index = i;
		if (type == SPOF_POWEROFF)
		{
			index = i + SPOF_EACH_SCHEDULE_NUM;
		}
        /* get the value of spof_list */
        memset(&tmpTime, 0, sizeof(MYTIME));

        tmpTime.nHour = g_spof_cntx.SPOFList[index].Hour;
        tmpTime.nMin = g_spof_cntx.SPOFList[index].Min;

        time_string(&tmpTime, (UI_string_type) subMenuDataPtrs[i], DT_IDLE_SCREEN);

        /* get the value of spof_vicons */
        if (g_spof_cntx.SPOFList[index].Status == SPOF_DISABLE)
        {
            spof_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
        }
        else
        {
            spof_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
        }
    }
    
    /* Dynamically create a menu id list */
    menu_id = (mmi_menu_id*)OslMalloc(num_of_items * sizeof(mmi_menu_id));
    for(i = 0; i < num_of_items; i++)
    {
        menu_id[i]=(mmi_menu_id)i;
    }
    
    cui_menu_set_currlist(menu_cui_gid, num_of_items, menu_id);
    
    cui_menu_set_currlist_flags(menu_cui_gid, CUI_MENU_NORMAL_LIST);
    if (!mmi_frm_is_in_backward_scenario())
    {
        cui_menu_set_currlist_highlighted_id(menu_cui_gid, g_spof_cntx.CurrItem);
    }    
    for(i = 0; i < num_of_items; i++)
    {
       cui_menu_set_item_image(menu_cui_gid, menu_id[i], spof_states_icon[i]);
       cui_menu_set_item_string(menu_cui_gid, menu_id[i], (WCHAR*)subMenuDataPtrs[i]);
    }
    /* Free the menu id list */
    OslMfree(menu_id);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_init_spof_sub_menu
 * DESCRIPTION
 *  Init sub menu of schedule power on / off 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_init_spof_main_menu(MMI_ID menu_cui_gid)
{
   
    cui_menu_set_currlist_flags(menu_cui_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    if (!mmi_frm_is_in_backward_scenario())
    {
        cui_menu_set_currlist_highlighted_id(menu_cui_gid, 0);
    }    
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_init_spof_setting_list
 * DESCRIPTION
 *  Initialize schedule power on & off setting menu list 
 * PARAMETERS
 *  void
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_init_spof_setting_list(mmi_menu_id menu_id, MMI_ID menu_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    switch (menu_id)
	{
	case MENU_SETTING_SCHEDULE_POWER:
		/* main menu of schedule power */
        mmi_init_spof_main_menu(menu_cui_gid);
		break;
        
	case MENU_SETTING_SCHEDULE_POWER_ON:
        mmi_init_spof_sub_menu(SPOF_POWERON, menu_cui_gid);
        break;
        
    case MENU_SETTING_SCHEDULE_POWER_OFF:
        mmi_init_spof_sub_menu(SPOF_POWEROFF, menu_cui_gid);
        break;
        
	default:
		break;
	}    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  mmi_schedule_power_onoff_notify_screen_lock_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

mmi_ret mmi_schedule_power_onoff_notify_screen_lock_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING &&
		mmi_frm_scrn_is_present(GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM, SCR_ID_SPOF_CONFIRM, MMI_FRM_NODE_ALL_FLAG))
    {
    	if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
		{
			return MMI_RET_OK;
		}
		else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
		{
			return MMI_RET_ERR;
		}
    }
    return MMI_RET_OK;
}
#endif /* #ifdef __MMI_SCREEN_LOCK_ANY_TIME__ */
#endif
#endif /* _MMI_SCHEDULEPOWERONOFF_C */ // #ifndef _MMI_SCHEDULEPOWERONOFF_C

