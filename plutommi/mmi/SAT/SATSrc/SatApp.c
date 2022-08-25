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
 *  SatApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SAT feature.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"
#include "AlarmFrameworkProt.h"
#include "Service.h"
#include "ServiceDefs.h"
#include "PhoneSetup.h"
#include "CharBatSrvGprot.h"
#include "PowerOnChargerProt.h"
#include "gui.h"
#include "UcmSrvGprot.h"
#include "IdleGprot.h"
#include "AlertScreen.h"
#include "ScrlockerGprot.h"
#include "SatSrvGprot.h"				// MAUI_03245579	

#ifdef __SATCC__
#ifdef BROWSER_SUPPORT
#include "Browser_api.h"
#endif /* BROWSER_SUPPORT */
#endif /* __SATCC__ */

#if defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */
#endif /* __MMI_OP01_MENU_9MATRIX__ */

#include "SatSrvGprot.h"
#include "SatAppProt.h"
#include "mmi_rp_srv_sat_def.h"
#include "mmi_rp_app_sat_def.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "NotificationGprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "GpioSrvGprot.h"
#include "wgui_categories_popup.h"
#include "custom_mmi_default_value.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "wgui_inputs.h"
#include "Unicodexdcl.h"
#include "ProfilesSrvGprot.h"
#include "custom_srv_prof_defs.h"
#include "mmi_rp_app_charger_def.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "SSCResDef.h"
#include "menucuigprot.h"
#include "custom_events_notify.h"
#include "gui_switch.h"
#include "wgui.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "stdio.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "app_mem.h"
#include "gdi_include.h"
#include "PhoneSetupGprots.h"
#include "FontRes.h"
#include "AlarmSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "Dmuigprot.h"
#include "GeneralSettingSrvGprot.h"
#include "CommonScreensResDef.h"
#include "ReminderSrvGprot.h"			//MAUI_03245579

#ifdef __MMI_NCENTER_SUPPORT__
#include "ModeSwitchSrvGprot.h"
#include "Vapp_sat_pluto.h"    //MAUI_03183732
#endif

/**************************************************************
 * MARCO                                                      * 
 **************************************************************/
#define MMI_SAT_MENU_ITEM_MAX_NUM   30

/* SAT Timer unit is second */
#define MMI_SAT_WAIT_TIMER_DURATION             15
#define MMI_SAT_HELP_TIMER_DURATION             90
#define MMI_SAT_NO_RESPONSE_DURATION            60

#ifndef __DOCOMO_IOT_ONLY__
#define MMI_SAT_DISPLAY_TEXT_DELAY_DURATION     5
#else
#define MMI_SAT_DISPLAY_TEXT_DELAY_DURATION     10
#endif

#define MMI_SAT_POPUP_DURATION                  1
#define MMI_SAT_REFRESH_REBOOT_DURATION         3
#define MMI_SAT_INFINITE_DURATION               0xFFFF

#define SAT_LANG_CHINESE                "zh"
#define SAT_LANG_ENGLISH                "en"

#define MMI_SAT_ICON_PATH_LENGTH    32


/**************************************************************
 * Structure Declaration
 **************************************************************/
typedef struct
{
    mmi_id parent_gid;
    MMI_ID app_gid;
    mmi_id sub_gid;

    MMI_BOOL calling_icon_available;
    CHAR *calling_icon_path;
} mmi_sat_context_struct;


typedef enum
{
    SAT_K_NONE     = 0x00,
    SAT_K_SEND_KEY = 0x01,
    SAT_K_LSK      = 0x02,
    SAT_K_CSK      = 0x04,
    SAT_K_RSK_BACK = 0x08,
    SAT_K_RSK_CANCEL = 0x10,
    SAT_K_END_KEY  = 0x20,
    SAT_K_ABORT    = 0x40,

} mmi_sat_key_enum;

#define SAT_K_LCRBE     (mmi_sat_key_enum)(SAT_K_LSK | SAT_K_CSK | SAT_K_RSK_BACK | SAT_K_END_KEY)
#define SAT_K_LCRCE     (mmi_sat_key_enum)(SAT_K_LSK | SAT_K_CSK | SAT_K_RSK_CANCEL | SAT_K_END_KEY)


/**************************************************************
 * Static Variables Defination                                *
 **************************************************************/
static mmi_sat_context_struct      g_sat_context[MMI_SIM_TOTAL];

srv_sat_proactive_sim_struct *gb_cmd_s_info;
#ifndef __SAT_LOWCOST_UI_DISABLE__
#ifdef __SATCC__
#ifdef BROWSER_SUPPORT
extern void srv_sat_terminal_response_launch_browser_stage1(mmi_sim_enum sim_id);		//vik 


extern void srv_sat_terminal_response_launch_browser_stage2(							//vik
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res);

#endif /*BROWSER_SUPPORT*/
#endif /* __SATCC__*/
#endif /*__SAT_LOWCOST_UI_DISABLE__*/

static void (*handle_cmd_fun[]) (srv_sat_proactive_sim_struct *cmd_info) = {
	 mmi_sat_display_text_process,
	 //mmi_sat_get_inkey_process,
	 //mmi_sat_get_input_process,
	 mmi_sat_get_process,
	 mmi_sat_get_process,
	 //mmi_sat_play_tone_process,
	 mmi_sat_get_process,
	 mmi_sat_sim_refresh_process,
	 NULL,
	 //mmi_sat_select_item_process,
	 mmi_sat_get_process,
	 //mmi_sat_send_sms_process,
	 mmi_sat_get_process,
	 //mmi_sat_send_ss_process,
	 mmi_sat_get_process,
	 //mmi_sat_send_ss_result_process,
	 mmi_sat_get_process,
	 //mmi_sat_send_ussd_process,
	 mmi_sat_get_process,
	 //mmi_sat_send_ussd_result_process,
	 mmi_sat_get_process,
	 mmi_sat_setup_call_process,
	 NULL,
	 NULL,
#ifdef __SATCB__
	 mmi_sat_run_at_cmd_process,
#else
	 NULL,
	 
#endif /* __SATCB__ */
	 mmi_sat_send_dtmf_process,

	#ifndef __SAT_LOWCOST_UI_DISABLE__
       
	mmi_sat_language_notification_process,

#ifdef __SATCC__
    #ifdef BROWSER_SUPPORT
	mmi_sat_launch_browser_process,
	#else	
	
	NULL,

	#endif /* BROWSER_SUPPORT */
#else
	 NULL,
#endif /* __SATCC__ */

#else
	 NULL,
         NULL,
  #endif /* __SAT_LOWCOST_UI_DISABLE__ */

	 /*mmi_sat_refresh_app_menu,*/									//MAUI_03319009

	 #ifdef __SATCE__

	 mmi_sat_open_channel_process,
	 mmi_sat_close_channel_process,
	 mmi_sat_send_data_process,
	 mmi_sat_recv_data_process

	#else
	 NULL,
	 NULL,
	 NULL,
	 NULL

	#endif /*__SATCE__*/

	};			//slim

MMI_BOOL wraper_to_SRV_SAT_CMD_SETUP_CALL(mmi_sat_group_data_struct *group_data ,mmi_sat_response_enum res_type);

#ifdef __SATCC__
MMI_BOOL wrapper_to_SRV_SAT_CMD_LAUNCH_BROWSER(mmi_sat_group_data_struct *group_data ,mmi_sat_response_enum res_type);
#endif /* __SATCC__ */

//slim
void mmi_sat_enable_alarm(void);		//MAUI_03245579

#ifdef __SATCE__

void mmi_sat_open_channel_scrn_entry(mmi_scrn_essential_struct* scrn_info);	
void mmi_sat_close_channel_scrn_entry(mmi_scrn_essential_struct* scrn_info);
void mmi_sat_send_data_scrn_entry(mmi_scrn_essential_struct* scrn_info);
void mmi_sat_recv_data_scrn_entry(mmi_scrn_essential_struct* scrn_info);

#endif /*__SATCE__*/


//slim

static MMI_BOOL (*response_to_cmd[]) (mmi_sat_group_data_struct *group_data , mmi_sat_response_enum res_type ) = {
	mmi_sat_display_text_response,
	mmi_sat_get_input_and_inkey_response,
	mmi_sat_get_input_and_inkey_response,
	mmi_sat_play_tone_response,
	NULL,
	mmi_sat_main_menu_response,
	mmi_sat_sub_menu_response,
	NULL,
	NULL,
	mmi_sat_send_ss_and_ussd_result_response,
	NULL,
	mmi_sat_send_ss_and_ussd_result_response,
	wraper_to_SRV_SAT_CMD_SETUP_CALL,
	NULL,
	NULL,
	NULL,
	mmi_sat_send_dtmf_response,
	NULL,

#ifdef __SATCC__
	wrapper_to_SRV_SAT_CMD_LAUNCH_BROWSER,
#else
	NULL,
#endif /* __SATCC__ */
	
	#ifdef __SATCE__

	mmi_sat_open_channel_response,
	mmi_sat_close_channel_response,
	mmi_sat_send_data_response,
	mmi_sat_recv_data_response

	
	#else
	 NULL,
	 NULL,
	 NULL,
	 NULL

	#endif /*__STACE__*/

	
};			//slim

	void wrapper_to_EVT_ID_SRV_SAT_PROACTIVE_SIM(mmi_event_struct *evt);
	void wrapper_to_EVT_ID_SRV_SAT_SETUP_MENU(mmi_event_struct *evt);
	void wrapper_to_EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY(mmi_event_struct *evt);
	void wrapper_to_EVT_ID_SRV_SAT_SESSION_END(mmi_event_struct *evt);
	void wrapper_to_EVT_ID_SRV_SAT_SIM_CTRL_INFO(mmi_event_struct *evt);
	void wrapper_to_mmi_idle_update_service_area(mmi_event_struct *evt);

static void (*rec_ind[])(mmi_event_struct *evt) = {
	wrapper_to_EVT_ID_SRV_SAT_PROACTIVE_SIM,
	wrapper_to_EVT_ID_SRV_SAT_SETUP_MENU,
	wrapper_to_EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY,
	wrapper_to_mmi_idle_update_service_area,
	wrapper_to_EVT_ID_SRV_SAT_SESSION_END,
	wrapper_to_EVT_ID_SRV_SAT_SIM_CTRL_INFO
};			//slim




void wrapper_for_OslMfree(void **buf);					//slim

/*****************************************************************************
 * Local function 
 *****************************************************************************/
static void mmi_sat_set_soft_key_hdlr(mmi_sat_key_enum key);


/**************************************************************
 * Function Defination                                        *
 **************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SAT_CONTEXT
 * DESCRIPTION
 *  get sat context by sim id.
 * PARAMETERS
 *  sim_id      [IN]    sim id
 * RETURNS
 *  sat context
 *****************************************************************************/
static mmi_sat_context_struct *SAT_CONTEXT(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return &g_sat_context[mmi_frm_sim_to_index(sim_id)];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_init_group_data
 * DESCRIPTION
 *  initialize group data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_sat_group_data_struct *mmi_sat_init_group_data(mmi_sim_enum sim_id, srv_sat_cmd_enum cmd_type, void *data, MMI_BOOL is_wait , void (*fun) (mmi_scrn_essential_struct* scrn_info))	//slim
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;													//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)OslMalloc(sizeof(mmi_sat_group_data_struct));

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_GROUP_DATA_ALLOC, (U32)group_data);

    memset(group_data, 0, sizeof(mmi_sat_group_data_struct));
    group_data->sim_id          = sim_id;
    group_data->cmd_type        = cmd_type;
    group_data->data_ptr        = data;
    group_data->is_wait_scrn    = is_wait;


	group_data->func_p = (FuncPtr) fun;			


    return group_data;
}

/****************************************************************************
*FUNCTION
 *  wraper_to_SRV_SAT_CMD_SETUP_CALL
 * DESCRIPTION
 * wrapper to SRV_SAT_CMD_SETUP_CALL
 * PARAMETERS
 *  group_data  , res_type
 * RETURNS
 * MMI_BOOL
*/
MMI_BOOL wraper_to_SRV_SAT_CMD_SETUP_CALL(mmi_sat_group_data_struct *group_data ,mmi_sat_response_enum res_type)
{
	MMI_BOOL ret;
	srv_ucm_result_enum error_code = SRV_UCM_RESULT_OK;
    ret = mmi_sat_setup_call_response(group_data->sim_id, res_type, &error_code);
    if (error_code != SRV_UCM_RESULT_OK)
    {
          mmi_popup_display_ext(srv_ucm_query_error_message(error_code), MMI_EVENT_FAILURE, NULL);
          ret = MMI_TRUE;
    }

    if (res_type != SAT_RES_OK || error_code != SRV_UCM_RESULT_OK)
    {
		//vikrant slim starts

          /* if (SAT_CONTEXT(group_data->sim_id)->calling_icon_path)
           {
                OslMfree(SAT_CONTEXT(group_data->sim_id)->calling_icon_path);
                SAT_CONTEXT(group_data->sim_id)->calling_icon_path = NULL;
           }
		   */
		wrapper_for_OslMfree((void **)(&(SAT_CONTEXT(group_data->sim_id)->calling_icon_path)));

		//vikrant slim ends


           SAT_CONTEXT(group_data->sim_id)->calling_icon_available = MMI_FALSE;
    }
	return ret;
}

#ifdef __SATCC__

/****************************************************************************
*FUNCTION
 * wrapper_to_SRV_SAT_CMD_LAUNCH_BROWSER
 * DESCRIPTION
 * wrapper to SRV_SAT_CMD_LAUNCH_BROWSER
 * PARAMETERS
 * group_data  , res_type
 * RETURNS
 * MMI_BOOL
*/
MMI_BOOL wrapper_to_SRV_SAT_CMD_LAUNCH_BROWSER(mmi_sat_group_data_struct *group_data ,mmi_sat_response_enum res_type)
{
	MMI_BOOL ret = MMI_FALSE;
    #ifndef __SAT_LOWCOST_UI_DISABLE__
       // if(group_data->cmd_type == SRV_SAT_CMD_LANGUAGE_NOTIFICATION)
            

    #ifdef BROWSER_SUPPORT
        if(group_data->cmd_type ==  SRV_SAT_CMD_LAUNCH_BROWSER)
        {
            ret = mmi_sat_launch_browser_response(group_data->sim_id, res_type);
            if (res_type == SAT_RES_OK)
            {
                mmi_sat_launch_browser_method(SAT_CONTEXT(group_data->sim_id)->sub_gid);
            }
            
        }
    #endif /* BROWSER_SUPPORT */ 
   #endif
	return ret;

}


#endif /* __SATCC__ */

/*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_group_data_free
 * DESCRIPTION
 *  Free sat group data.
 * PARAMETERS
 *  group_data          [IN]       group data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sat_group_data_free(mmi_sat_group_data_struct *group_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_GROUP_DATA_DEALLOC, (U32)group_data);

   //slim starts
	/*if (group_data->input_buf != NULL)
    {
        OslMfree(group_data->input_buf);
        group_data->input_buf = NULL;
    }

    if (group_data != NULL)
    {
        OslMfree(group_data);
    }*/

	wrapper_for_OslMfree((void**)(&(group_data->input_buf)));
	wrapper_for_OslMfree((void**)&(group_data));

	//slim ends
}

//slim starts

/****************************************************************************
* function
* wrapper_for_OslMfree
* DESCRIPTION
* wrapper function for OslMfree to avoid checking of null pointer.
* PARAMETER
* void
* RETURNS
* void
*****************************************************************************/

void wrapper_for_OslMfree(void **buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(*buf != NULL)
	{
		OslMfree(*buf);
		*buf = NULL;
    }
}

//slim ends


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_set_timer_data
 * DESCRIPTION
 *  initialize timer data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_sat_timer_data_struct *mmi_sat_set_timer_data(srv_sat_cmd_enum cmd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_timer_data_struct *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = (mmi_sat_timer_data_struct *)OslMalloc(sizeof(mmi_sat_timer_data_struct));
    user_data->cmd_type = cmd_type;
    user_data->is_inform = MMI_TRUE;

    return user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_is_in_screen
 * DESCRIPTION
 *  Judge whether is in sat screen.
 * PARAMETERS
 *  sim_id          [IN]       sim id
 * RETURNS
 *  MMI_TRUE is in sat screen.
 *****************************************************************************/
static MMI_BOOL mmi_sat_is_in_screen(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)((SAT_CONTEXT(sim_id)->app_gid != GRP_ID_INVALID &&
                        curr_id == SAT_CONTEXT(sim_id)->app_gid) ||
                        (mmi_frm_scrn_get_active_id() == SCR_ID_SAT_CMD_SCREEN && 
                        curr_id == SAT_CONTEXT(sim_id)->sub_gid ||
                        mmi_frm_group_is_present(GRP_ID_SAT_INPUT_OPT)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_app_init
 * DESCRIPTION
 *  initialize sat app context data .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    mmi_sat_create_folder();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_delete_app
 * DESCRIPTION
 *  delete app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sat_delete_app(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_DELETE_APP);
    mmi_frm_group_close(SAT_CONTEXT(sim_id)->app_gid);
    mmi_frm_group_close(SAT_CONTEXT(sim_id)->sub_gid);
    SAT_CONTEXT(sim_id)->app_gid = GRP_ID_INVALID;
    SAT_CONTEXT(sim_id)->sub_gid = GRP_ID_INVALID;
}


#ifdef __J2ME__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_is_group_active
 * DESCRIPTION
 *  provide for java DM install.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sat_is_group_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (mmi_sat_is_in_screen((mmi_sim_enum)(1 << i)))
        {
            return MMI_TRUE;
        } 
    }

    return MMI_FALSE;
}
#endif /* __J2ME__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_menu_string
 * DESCRIPTION
 *  Get SAT menu string by menu id.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sim_enum mmi_sat_menu_id_to_sim_id(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
#ifndef __MMI_OP12_MENU_12MATRIX__

        case MENU_ID_SAT1_ENTRY:
            sim_id = MMI_SIM1;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_SAT2_ENTRY:
            sim_id = MMI_SIM2;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_SAT3_ENTRY:
            sim_id = MMI_SIM3;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 3 */
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_SAT4_ENTRY:
            sim_id = MMI_SIM4;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 4 */
    #endif /* MMI_MAX_SIM_NUM >= 2 */

#endif /* __MMI_OP12_MENU_12MATRIX__ */

        default :
            sim_id = MMI_SIM_NONE;
            break;
    }

    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_call_type_to_sim_id
 * DESCRIPTION
 *  Get sim id by call type.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sim_enum mmi_sat_call_type_to_sim_id(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(call_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM1;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if(call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if(call_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM3;
    }
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    else if(call_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM4;
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
    else
    {
        sim_id = MMI_SIM_NONE;
    }

    MMI_ASSERT(sim_id);

    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_app_launch
 * DESCRIPTION
 *  Lanch SAT application.
 * PARAMETERS
 *  parent_gid        [IN]      parent group id
 *  sim_id              [IN]      sim id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_app_launch(mmi_id parent_gid, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;											//slim
    mmi_id *gid_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_APP_LAUNCH, sim_id, parent_gid);

    gid_p = &SAT_CONTEXT(sim_id)->app_gid;
    SAT_CONTEXT(sim_id)->parent_gid = parent_gid;

    group_data = mmi_sat_init_group_data(sim_id, SRV_SAT_CMD_SETUP_MENU, (srv_sat_setup_menu_struct *)srv_sat_get_setup_menu(sim_id), MMI_FALSE , NULL);
    mmi_sat_enter_app_group(SAT_CONTEXT(sim_id)->parent_gid, sim_id, gid_p, group_data);
    mmi_frm_scrn_first_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, (FuncPtr)mmi_sat_main_and_sub_menu_scrn_entry, gid_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_refresh_app_menu
 * DESCRIPTION
 *  Refresh menu which SAT in.
 * PARAMETERS
 *  sim_id              [IN]        sim id
 *  is_present         [IN]         SAT setup menu is ready
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_refresh_app_menu(mmi_sim_enum sim_id, MMI_BOOL is_present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id, scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&grp_id, &scrn_id);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

#if (defined __MMI_OP01_MENU_9MATRIX__) || (defined __MMI_OP01_MENU_12MATRIX__)
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */
#else /* __MMI_OP01_MENU_9MATRIX__ */
#ifdef __MMI_OP12_MENU_12MATRIX__
    if (scrn_id == MAIN_MENU_SCREENID)
    {
        mmi_frm_scrn_close_active_id();
        goto_main_menu();
    }
#else /* __MMI_OP12_MENU_12MATRIX__ */
    if (scrn_id == SERVICES_MAIN_MENU_SCREEN_ID)
    {
        mmi_frm_scrn_close_active_id();
        mmi_serivce_main_menu_scrn();
    }
#endif /* __MMI_OP12_MENU_12MATRIX__ */
#endif /* __MMI_OP01_MENU_9MATRIX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_enter_app_group
 * DESCRIPTION
 *  enter sat main group/ sub group.
 * PARAMETERS
 *  parent_gid          [IN]        parent group id
 *  sim_id                [IN]        sim id
 *  gid_p                 [OUT]     sat group id
 *  user_data           [IN]        sat group data
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sat_enter_app_group(mmi_id parent_gid, mmi_sim_enum sim_id, mmi_id *gid_p, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	MMI_BOOL ret = MMI_FALSE;																//vikrant	
	//int arg;																				//vikrant

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_ENTER_APP_GROUP);

    if ((*gid_p != GRP_ID_INVALID) && (*gid_p != GRP_ID_ROOT) && mmi_frm_group_is_present(*gid_p))
    {
        MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CLOSE_GROUP_ID, *gid_p);
        mmi_frm_group_close(*gid_p);
    }

    if (parent_gid == GRP_ID_INVALID)
    {
        parent_gid = GRP_ID_ROOT;
    }

    *gid_p = mmi_frm_group_create_ex(parent_gid, GRP_ID_AUTO_GEN, mmi_sat_app_group_proc, user_data, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (*gid_p != GRP_ID_INVALID)
    {
		//slim starts

       // MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_ENTER_GROUP_STATE, parent_gid, *gid_p, 1);
       // return MMI_TRUE;
		//arg = 1;

		//slim  ends
		ret = MMI_TRUE;

    }
   /* else
    {
		//slim starts

       // MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_ENTER_GROUP_STATE, parent_gid, *gid_p, 0);
       // return MMI_FALSE;
		ret = MMI_FALSE;
		//arg = 0;
    }
	*/

	//MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_ENTER_GROUP_STATE, parent_gid, *gid_p, arg);

return ret;

		//slim ends

}

/*****************************************************************************
 * FUNCTION
 *  wrapper_to_EVT_ID_SRV_SAT_PROACTIVE_SIM
 * DESCRIPTION
 *  wrapper for EVT_ID_SRV_SAT_PROACTIVE_SIM
 * PARAMETERS
 *  evt  
 *****************************************************************************/
void wrapper_to_EVT_ID_SRV_SAT_PROACTIVE_SIM(mmi_event_struct *evt)
{
			srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SIM_ID, event->proactive_sim->sim_id);
            if (event->proactive_sim->cmd_type == SRV_SAT_CMD_SETUP_MENU)
            {
                mmi_sat_handle_setup_menu_cmd(event->proactive_sim);
    }
    else
    {
                mmi_sat_handle_instant_cmd(event->proactive_sim);
            }
}

/*****************************************************************************
 * FUNCTION
 * wrapper_to_mmi_idle_update_service_area
 * DESCRIPTION
 * wrapper for mmi_idle_update_service_area
 * PARAMETERS
 *  evt  
 *****************************************************************************/
void wrapper_to_mmi_idle_update_service_area(mmi_event_struct *evt)
{
	mmi_idle_update_service_area();
}

/*****************************************************************************
 * FUNCTION
 *  wrapper_to_EVT_ID_SRV_SAT_SETUP_MENU
 * DESCRIPTION
 *  wrapper for EVT_ID_SRV_SAT_SETUP_MENU
 * PARAMETERS
 *  evt  
 *****************************************************************************/
void wrapper_to_EVT_ID_SRV_SAT_SETUP_MENU(mmi_event_struct *evt)
{
			srv_sat_setup_menu_event_struct *event = (srv_sat_setup_menu_event_struct *)evt;
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SIM_ID, event->sim_id);

            if (!event->present)
            {            
                mmi_sat_delete_app(event->sim_id);
            }

            mmi_sat_refresh_app_menu(event->sim_id, event->present);
}

/*****************************************************************************
 * FUNCTION
 *  wrapper_to_EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY
 * DESCRIPTION
 *  wrapper for EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY
 * PARAMETERS
 *  evt  
 *****************************************************************************/
void wrapper_to_EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY(mmi_event_struct *evt)
{
	       #ifdef __MMI_NCENTER_SUPPORT__
			mmi_SAT_create_scroll_text(evt, APP_SAT);   //MAUI_03183732
         #else
            mmi_idle_update_service_area();	
          #endif
}

/*****************************************************************************
 * FUNCTION
 *  wrapper_to_EVT_ID_SRV_SAT_SIM_CTRL_INFO
 * DESCRIPTION
 *  wrapper for EVT_ID_SRV_SAT_SIM_CTRL_INFO
 * PARAMETERS
 *  evt  
 *****************************************************************************/
void wrapper_to_EVT_ID_SRV_SAT_SIM_CTRL_INFO(mmi_event_struct *evt)
{
	            srv_sat_sim_ctrl_info_event_struct *event = (srv_sat_sim_ctrl_info_event_struct *)evt;
            mmi_confirm_display(event->alpha_id, MMI_EVENT_INFO, NULL);

           // OslMfree(event->alpha_id);
	wrapper_for_OslMfree((void**)(&(event->alpha_id)));		// slim
}

/*****************************************************************************
 * FUNCTION
 *  wrapper_to_EVT_ID_SRV_SAT_SESSION_END
 * DESCRIPTION
 *  wrapper for EVT_ID_SRV_SAT_SIM_CTRL_INFO
 * PARAMETERS
 *  evt  
 *****************************************************************************/
void wrapper_to_EVT_ID_SRV_SAT_SESSION_END(mmi_event_struct *evt)
{
	        srv_sat_session_end_event_struct *event = (srv_sat_session_end_event_struct *)evt;
            srv_sat_proactive_sim_struct *last_cmd_info = (srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(event->sim_id);
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SIM_ID, event->sim_id);

        #ifdef __DM_LAWMO_SUPPORT__
            if (mmi_dmui_is_phone_lock() && mmi_frm_scrn_get_active_id() == SCR_ID_SAT_CMD_SCREEN)
            {
               mmi_sat_delete_app(event->sim_id);
            }
        #endif

            /* press softkey for display text of immediate response type */
            if (last_cmd_info->cmd_type == SRV_SAT_CMD_DISPLAY_TEXT)
            {
                srv_sat_display_text_struct *display_text = (srv_sat_display_text_struct *)(&last_cmd_info->cmd_data);
                if (display_text->immediate_res)
                {
                    return;
                }
    }

            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CMD_SESSION_END, last_cmd_info->cmd_type, SAT_CONTEXT(event->sim_id)->sub_gid);
            mmi_frm_group_close(SAT_CONTEXT(event->sim_id)->sub_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_recv_ind
 * DESCRIPTION
 *  Receive SAT service indication.
 * PARAMETERS
 *  evt          [IN]       event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_sat_recv_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_PROACTIVE_SIM_EVENT, EVT_ID_SRV_SAT_PROACTIVE_SIM);
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_RECV_IND, evt->evt_id);

	//slim starts

    if((*rec_ind[evt->evt_id-EVT_ID_SRV_SAT_PROACTIVE_SIM]))	//evt->evt_id-EVT_ID_SRV_SAT_PROACTIVE_SIM is used for getting array index
	{
	(*rec_ind[evt->evt_id-EVT_ID_SRV_SAT_PROACTIVE_SIM])(evt);
	}
	/*
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SAT_PROACTIVE_SIM:
        {
            srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SIM_ID, event->proactive_sim->sim_id);
            if (event->proactive_sim->cmd_type == SRV_SAT_CMD_SETUP_MENU)
            {
                mmi_sat_handle_setup_menu_cmd(event->proactive_sim);
            }
            else
            {
                mmi_sat_handle_instant_cmd(event->proactive_sim);
            }
            break;
        }

        case EVT_ID_SRV_SAT_SETUP_MENU:
        {
            srv_sat_setup_menu_event_struct *event = (srv_sat_setup_menu_event_struct *)evt;
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SIM_ID, event->sim_id);

            if (!event->present)
            {            
                mmi_sat_delete_app(event->sim_id);
            }

            mmi_sat_refresh_app_menu(event->sim_id, event->present);
            break;
        }

        case EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY:
        {

         #ifdef __MMI_NCENTER_SUPPORT__
			mmi_SAT_create_scroll_text(evt, APP_SAT);   //MAUI_03183732
         #else
            mmi_idle_update_service_area();	
          #endif
            break;
        }

        case EVT_ID_SRV_SAT_SIM_REFRESH:
        {
            mmi_idle_update_service_area();
            break;
        }

        case EVT_ID_SRV_SAT_SESSION_END:
        {
            srv_sat_session_end_event_struct *event = (srv_sat_session_end_event_struct *)evt;
            srv_sat_proactive_sim_struct *last_cmd_info = (srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(event->sim_id);
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SIM_ID, event->sim_id);

        #ifdef __DM_LAWMO_SUPPORT__
            if (mmi_dmui_is_phone_lock() && mmi_frm_scrn_get_active_id() == SCR_ID_SAT_CMD_SCREEN)
            {
               mmi_sat_delete_app(event->sim_id);
            }
        #endif*/

            /* press softkey for display text of immediate response type */
            /*if (last_cmd_info->cmd_type == SRV_SAT_CMD_DISPLAY_TEXT)
            {
                srv_sat_display_text_struct *display_text = (srv_sat_display_text_struct *)(&last_cmd_info->cmd_data);
                if (display_text->immediate_res)
                {
                    break;
                }
            }

            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CMD_SESSION_END, last_cmd_info->cmd_type, SAT_CONTEXT(event->sim_id)->sub_gid);
            mmi_frm_group_close(SAT_CONTEXT(event->sim_id)->sub_gid);
            break;
        }

        case EVT_ID_SRV_SAT_SIM_CTRL_INFO:
        {
            srv_sat_sim_ctrl_info_event_struct *event = (srv_sat_sim_ctrl_info_event_struct *)evt;
            mmi_confirm_display(event->alpha_id, MMI_EVENT_INFO, NULL);

            OslMfree(event->alpha_id);
            break;
        }

        default:
            break;
    }
	*/

// slim ends

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_recv_ucm_ind
 * DESCRIPTION
 *  Receive UCM indication.
 * PARAMETERS
 *  evt          [IN]       event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_sat_recv_ucm_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)evt;
	mmi_sim_enum sim_id = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (ind->ind_type)
    {
        case SRV_UCM_OUTGOING_CALL_IND:
        {
            srv_ucm_outgoing_call_ind_struct *call_outgoing = (srv_ucm_outgoing_call_ind_struct *)ind->ptr;
            //mmi_sim_enum sim_id = MMI_SIM_NONE;

            if (call_outgoing->module_id == SRV_UCM_MODULE_ORIGIN_SAT)
            {
                sim_id = mmi_sat_call_type_to_sim_id(call_outgoing->uid_info.call_type);

                MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_OUT_GOING_CALL_IND, SRV_SAT_CMD_SETUP_CALL , SAT_CONTEXT(sim_id)->sub_gid);
                mmi_frm_group_close(SAT_CONTEXT(sim_id)->sub_gid);
            }

            break;
        }

        case SRV_UCM_RELEASE_IND:
        {
            srv_ucm_release_ind_struct *call_release = (srv_ucm_release_ind_struct *)ind->ptr;
            //mmi_sim_enum sim_id = MMI_SIM_NONE;

            if (call_release->module_id == SRV_UCM_MODULE_ORIGIN_SAT)
            {
                MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_SEND_CALL_ABORT_REQ);
                sim_id = mmi_sat_call_type_to_sim_id(call_release->uid_info.call_type);

                srv_sat_setup_call_abort_req(sim_id);

            #ifndef __SAT_DISABLE_ICON_SUPPORT__
                if (SAT_CONTEXT(sim_id)->calling_icon_path)
                {
                    OslMfree(SAT_CONTEXT(sim_id)->calling_icon_path);
                    SAT_CONTEXT(sim_id)->calling_icon_path = NULL;
                    SAT_CONTEXT(sim_id)->calling_icon_available = MMI_FALSE;
                }
            #endif /* __SAT_DISABLE_ICON_SUPPORT__ */
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
 *  mmi_sat_recv_idle_available
 * DESCRIPTION
 *  receive idle enter event.
 * PARAMETERS
 *  cmd_info          [IN]       command information
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sat_recv_idle_ind(mmi_event_struct *evt)
{
#ifndef __SAT_LOWCOST_UI_DISABLE__
    srv_sat_envelope_idle_screen_available();
#endif /* __SAT_LOWCOST_UI_DISABLE__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_handle_setup_menu_cmd
 * DESCRIPTION
 *  Handle setup menu command.
 * PARAMETERS
 *  cmd_info          [IN]       command information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_handle_setup_menu_cmd(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;									//slim
    srv_sat_setup_menu_struct *setup_menu = NULL;
    MMI_ID grp_id, scrn_id;

    mmi_id *gid_p = &SAT_CONTEXT(cmd_info->sim_id)->app_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CMD_PROCESSING, SRV_SAT_CMD_SETUP_MENU);

    mmi_frm_get_active_scrn_id(&grp_id, &scrn_id);
    setup_menu = (srv_sat_setup_menu_struct *)srv_sat_get_setup_menu(cmd_info->sim_id);

    if (!setup_menu->present)
    {
        mmi_sat_delete_app(cmd_info->sim_id);
        return;
    }

    if ((*gid_p != GRP_ID_INVALID) && (grp_id != GRP_ID_ROOT) && (grp_id == *gid_p))
    {
        group_data = mmi_sat_init_group_data(cmd_info->sim_id, SRV_SAT_CMD_SETUP_MENU, setup_menu, MMI_FALSE , NULL);
        if (mmi_sat_enter_app_group(
                    SAT_CONTEXT(cmd_info->sim_id)->parent_gid,
                    cmd_info->sim_id,
                    gid_p,
                    group_data))
        {
            mmi_frm_scrn_first_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, (FuncPtr)mmi_sat_main_and_sub_menu_scrn_entry, gid_p);
        }
    }
    else if (mmi_frm_group_is_present(*gid_p))
    {
        group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(*gid_p);
        group_data->menu_index = 0;
        mmi_frm_scrn_clean_gui_buf(*gid_p, SCR_ID_SAT_CMD_SCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_handle_instant_cmd
 * DESCRIPTION
 *  Handle proactive commands except setup menu command.
 * PARAMETERS
 *  cmd_info          [IN]       command information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_handle_instant_cmd(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CMD_PROCESSING, cmd_info->cmd_type);

#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock() && mmi_frm_scrn_get_active_id() == SCR_ID_SAT_CMD_SCREEN)
    {
        mmi_sat_delete_app(cmd_info->sim_id);
    }
#endif


	//slim starts

	gb_cmd_s_info = cmd_info;

	if((*handle_cmd_fun[cmd_info->cmd_type - 1]))
	{
			(*handle_cmd_fun[cmd_info->cmd_type - 1])(cmd_info);
	}
/*
    switch (cmd_info->cmd_type)
    {
        case SRV_SAT_CMD_DISPLAY_TEXT:
            mmi_sat_display_text_process(cmd_info);
            break;

        case SRV_SAT_CMD_GET_INKEY:
            mmi_sat_get_inkey_process(cmd_info);
            break;

        case SRV_SAT_CMD_GET_INPUT:
            mmi_sat_get_input_process(cmd_info);
            break;

        case SRV_SAT_CMD_PLAY_TONE:
            mmi_sat_play_tone_process(cmd_info);
            break;

        case SRV_SAT_CMD_SELECT_ITEM:
            mmi_sat_select_item_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_SMS:
            mmi_sat_send_sms_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_SS:
            mmi_sat_send_ss_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
            mmi_sat_send_ss_result_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_USSD:
            mmi_sat_send_ussd_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
            mmi_sat_send_ussd_result_process(cmd_info);
            break;

        case SRV_SAT_CMD_SETUP_CALL:
            mmi_sat_setup_call_process(cmd_info);
            break;

        case SRV_SAT_CMD_RUN_AT_COMMAND:
            mmi_sat_run_at_cmd_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_DTMF:
            mmi_sat_send_dtmf_process(cmd_info);
            break;

        case SRV_SAT_CMD_REFRESH:
            mmi_sat_sim_refresh_process(cmd_info);
            break;

    #ifndef __SAT_LOWCOST_UI_DISABLE__
        case SRV_SAT_CMD_LANGUAGE_NOTIFICATION:
            mmi_sat_language_notification_process(cmd_info);
            break;

    #ifdef BROWSER_SUPPORT
        case SRV_SAT_CMD_LAUNCH_BROWSER:
            mmi_sat_launch_browser_process(cmd_info);
            break;

*/
  //#endif /* BROWSER_SUPPORT */
  //#endif /* __SAT_LOWCOST_UI_DISABLE__ */

  /*  #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
            mmi_sat_open_channel_process(cmd_info);
            break;

        case SRV_SAT_CMD_CLOSE_CHANNEL:
            mmi_sat_close_channel_process(cmd_info);
            break;

        case SRV_SAT_CMD_SEND_DATA:
            mmi_sat_send_data_process(cmd_info);
            break;

        case SRV_SAT_CMD_RECEIVE_DATA:
            mmi_sat_recv_data_process(cmd_info);
            break;
	*/
   // #endif /* __SATCE__ */
/*
        default:
            break;
    }
	*/

// slim  ends

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_instant_cmd_show_by_nmgr
 * DESCRIPTION
 *  Control command screen by nmgr.
 * PARAMETERS
 *  func_ptr          [IN]       screen entry function
 *  arg                 [IN]       group data
 * RETURNS
 *  MMI_TREU refer to <mmi_frm_nmgr_notify_by_app>
 *****************************************************************************/
static MMI_BOOL mmi_sat_instant_cmd_show_by_nmgr(mmi_noti_scrn_func_ptr func_ptr, mmi_sat_group_data_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_NON_TONE, func_ptr, arg);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sat_main_and_sub_menu_scrn_entry
 * DESCRIPTION
 *  SAT main menu screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_main_and_sub_menu_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *list_items[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *list_items_icons[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *list_hints[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *gui_buffer = NULL;
	U8 *title_string = NULL;
    S32 hilite_index = 0;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_setup_menu_struct *menu_data = NULL;
	srv_sat_select_item_struct *menu_select_data = NULL;
    mmi_id grp_id;
    S32 i, max_items_num;
    mmi_sat_key_enum sat_sk_hdlr = SAT_K_LCRBE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
	if(group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
	{
		menu_data = (srv_sat_setup_menu_struct *)group_data->data_ptr;
		grp_id = SAT_CONTEXT(group_data->sim_id)->app_gid;
		group_data->is_sent = MMI_FALSE;
	}
	else
	{
		menu_select_data = (srv_sat_select_item_struct *)group_data->data_ptr;
		grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

	}
    

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_main_and_sub_menu_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

	if(group_data->cmd_type == SRV_SAT_CMD_SELECT_ITEM)
	{
		srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);
	}

    
    memset(list_items, 0, sizeof(list_items));
    memset(list_hints, 0, sizeof(list_hints));
    memset(list_items_icons, 0, sizeof(list_items_icons));

	if(group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
	{
		max_items_num = menu_data->num_of_item > MMI_SAT_MENU_ITEM_MAX_NUM ? MMI_SAT_MENU_ITEM_MAX_NUM : menu_data->num_of_item;
	}
	else
	{
		max_items_num = menu_select_data->num_of_item > MMI_SAT_MENU_ITEM_MAX_NUM ? MMI_SAT_MENU_ITEM_MAX_NUM : menu_select_data->num_of_item;
	}


    for (i = 0; i < max_items_num; i++)
    {
		if(group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
		{
			list_items[i] = (PU8)menu_data->item_list[i].alpha_id;
			list_items_icons[i] = menu_data->item_list[i].icon.data;
			list_hints[i] = mmi_sat_get_cmd_hint(menu_data->item_list[i].next_action_ind, SRV_SAT_CMD_SETUP_MENU);
		}
		else
		{
			list_items[i] = (PU8)menu_select_data->item_list[i].alpha_id;
			list_items_icons[i] = menu_select_data->item_list[i].icon.data;
			list_hints[i] = mmi_sat_get_cmd_hint(menu_select_data->item_list[i].next_action_ind, SRV_SAT_CMD_SELECT_ITEM);
			if (menu_select_data->default_id == menu_select_data->item_list[i].id)
				{
					hilite_index = i;
				}
		}

    }

	if(group_data->cmd_type == SRV_SAT_CMD_SELECT_ITEM)
	{
		    title_string = (U8 *)menu_select_data->alpha_id;
			if ((!menu_select_data->icon.available || menu_select_data->icon.attr != SRV_SAT_ICON_SELF_EX) &&
				(title_string == NULL || *title_string == '\0'))
			{
				if (SAT_CONTEXT(group_data->sim_id)->app_gid == GRP_ID_INVALID)
					{
						title_string = (U8 *)srv_sat_get_menu_title(group_data->sim_id);
					}		
				else
					{
						mmi_sat_group_data_struct *gdata = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(SAT_CONTEXT(group_data->sim_id)->app_gid);
						title_string = (U8 *)srv_sat_get_menu_item(group_data->sim_id, (S32)gdata->menu_index);
					}
			}
	}

    mmi_sat_set_key_and_pen_handler();
    RegisterHighlightHandler(mmi_sat_hilit_menu_index_hdlr);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

	if(group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
	{
		ShowCategory174Screen(
			(PU8)menu_data->alpha_id,
			menu_data->icon.data,
			(PU8)GetString(STR_GLOBAL_OK),
			(PU8)GetImage(IMG_GLOBAL_OK),
			(PU8)GetString(STR_GLOBAL_BACK),
			(PU8)GetImage(IMG_GLOBAL_BACK),
			max_items_num,
			list_items,
			list_items_icons,
			list_hints,
			0,
			group_data->menu_index,
			gui_buffer);
		    
		if (menu_data->help_available)
			{
				sat_sk_hdlr |= SAT_K_SEND_KEY;
			}
	}

	else
	{
		ShowCategory174Screen(
			title_string,
			menu_select_data->icon.data,
			(PU8)GetString(STR_GLOBAL_OK),
			(PU8)GetImage(IMG_GLOBAL_OK),
			(PU8)GetString(STR_GLOBAL_BACK),
			(PU8)GetImage(IMG_GLOBAL_BACK),
			max_items_num,
			list_items,
			list_items_icons,
			list_hints,
			0,
			hilite_index,
			gui_buffer);
			
		if (menu_select_data->help_available)
			{
				sat_sk_hdlr |= SAT_K_SEND_KEY;
			}
	}



	if(group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
	{
		sat_sk_hdlr &= ~SAT_K_END_KEY;
	}

    mmi_sat_set_soft_key_hdlr(sat_sk_hdlr);

	
	if(group_data && group_data->cmd_type == SRV_SAT_CMD_SELECT_ITEM)
	{
		//if(group_data)			//vikrant	- MAUI_03243383
		{
			srv_sat_start_timer(
					group_data->sim_id,
					SAT_TIMER_NO_RESPONSE,
					MMI_SAT_NO_RESPONSE_DURATION,
					mmi_sat_timer_expiry_hdlr,
					mmi_sat_set_timer_data(SRV_SAT_CMD_SELECT_ITEM));
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_main_menu_scrn_entry
 * DESCRIPTION
 *  SAT main menu screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_main_menu_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  U8 *list_items[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *list_items_icons[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *list_hints[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_setup_menu_struct *menu_data = NULL;
    mmi_id grp_id;
    S32 i, max_items_num;
    mmi_sat_key_enum sat_sk_hdlr = SAT_K_LCRBE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    menu_data = (srv_sat_setup_menu_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->app_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_main_menu_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    group_data->is_sent = MMI_FALSE;
    memset(list_items, 0, sizeof(list_items));
    memset(list_hints, 0, sizeof(list_hints));
    memset(list_items_icons, 0, sizeof(list_items_icons));

    max_items_num = menu_data->num_of_item > MMI_SAT_MENU_ITEM_MAX_NUM ? MMI_SAT_MENU_ITEM_MAX_NUM : menu_data->num_of_item;

    for (i = 0; i < max_items_num; i++)
    {
        list_items[i] = (PU8)menu_data->item_list[i].alpha_id;
        list_items_icons[i] = menu_data->item_list[i].icon.data;
        list_hints[i] = mmi_sat_get_cmd_hint(menu_data->item_list[i].next_action_ind, SRV_SAT_CMD_SETUP_MENU);
    }

    mmi_sat_set_key_and_pen_handler();
    RegisterHighlightHandler(mmi_sat_hilit_menu_index_hdlr);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory174Screen(
        (PU8)menu_data->alpha_id,
        menu_data->icon.data,
        (PU8)GetString(STR_GLOBAL_OK),
        (PU8)GetImage(IMG_GLOBAL_OK),
        (PU8)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        max_items_num,
        list_items,
        list_items_icons,
        list_hints,
        0,
        group_data->menu_index,
        gui_buffer);

    if (menu_data->help_available)
    {
        sat_sk_hdlr |= SAT_K_SEND_KEY;
    }

    sat_sk_hdlr &= ~SAT_K_END_KEY;
    mmi_sat_set_soft_key_hdlr(sat_sk_hdlr);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_main_menu_response
 * DESCRIPTION
 *  SAT setup menu response.
 * PARAMETERS
 *  sim_id          [IN]        sim id
 *  res_type       [IN]         response type
 * RETURNS
 *  Return MMI_TRUE will show please screen.
 *****************************************************************************/
MMI_BOOL mmi_sat_main_menu_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
	mmi_sim_enum sim_id = group_data->sim_id;				// slim
    mmi_id gid = SAT_CONTEXT(sim_id)->app_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res_type)
    {
        case SAT_RES_OK:
            srv_sat_envelope_menu_selection(sim_id, mmi_sat_get_menu_id(gid), MMI_FALSE);
            ret = MMI_TRUE;
            break;

        case SAT_RES_HELP:
            srv_sat_envelope_menu_selection(sim_id, mmi_sat_get_menu_id(gid), MMI_TRUE);
            ret = MMI_TRUE;
            break;

        case SAT_RES_BACK:
            mmi_frm_scrn_close_active_id();
            break;

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_scrn_pre_entry
 * DESCRIPTION
 *  For nmgr handler.
 * PARAMETERS
 *  scen_id          [IN]        scenario id
 *  arg                [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sat_scrn_pre_entry(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
    mmi_id *gid_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)arg;
    gid_p = &SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_sat_enter_app_group(SAT_CONTEXT(group_data->sim_id)->app_gid, group_data->sim_id, gid_p, arg))
    {    
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_PRE_ENTER_SCREEN, group_data->cmd_type);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    mmi_frm_scrn_first_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, (FuncPtr)group_data->func_p, gid_p);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_select_item_process
 * DESCRIPTION
 *  Select item command process.
 * PARAMETERS
 *  group_data          [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_select_item_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  mmi_sat_group_data_struct *group_data;																//vikrant

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_sub_menu_scrn_entry); //slim
    // group_data->func_p = (FuncPtr)mmi_sat_sub_menu_scrn_entry;				//slim
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_sub_menu_scrn_entry
 * DESCRIPTION
 *  select item command enter screen function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_sub_menu_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /* U8 *list_items[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *list_hints[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *list_items_icons[MMI_SAT_MENU_ITEM_MAX_NUM];
    U8 *gui_buffer = NULL;
    U8 *title_string = NULL;
    S32 hilite_index = 0;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_select_item_struct *menu_data = NULL;
    mmi_id grp_id;
    S32 i, max_items_num;
    mmi_sat_key_enum sat_sk_hdlr = SAT_K_LCRBE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    menu_data = (srv_sat_select_item_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_sub_menu_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    memset(list_items, 0, sizeof(list_items));
    memset(list_hints, 0, sizeof(list_hints));
    memset(list_items_icons, 0, sizeof(list_items_icons));

    max_items_num = menu_data->num_of_item > MMI_SAT_MENU_ITEM_MAX_NUM ? MMI_SAT_MENU_ITEM_MAX_NUM : menu_data->num_of_item;

    for (i = 0; i < max_items_num; i++)
    {
        list_items[i] = (PU8)menu_data->item_list[i].alpha_id;
        list_items_icons[i] = menu_data->item_list[i].icon.data;
        list_hints[i] = mmi_sat_get_cmd_hint(menu_data->item_list[i].next_action_ind, SRV_SAT_CMD_SELECT_ITEM);

        if (menu_data->default_id == menu_data->item_list[i].id)
        {
            hilite_index = i;
        }
    }

    title_string = (U8 *)menu_data->alpha_id;
    if ((!menu_data->icon.available || menu_data->icon.attr != SRV_SAT_ICON_SELF_EX) &&
        (title_string == NULL || *title_string == '\0'))
    {
        if (SAT_CONTEXT(group_data->sim_id)->app_gid == GRP_ID_INVALID)
        {
            title_string = (U8 *)srv_sat_get_menu_title(group_data->sim_id);
        }
        else
        {
            mmi_sat_group_data_struct *gdata = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(SAT_CONTEXT(group_data->sim_id)->app_gid);
            title_string = (U8 *)srv_sat_get_menu_item(group_data->sim_id, (S32)gdata->menu_index);
        }
    }

    mmi_sat_set_key_and_pen_handler();
    RegisterHighlightHandler(mmi_sat_hilit_menu_index_hdlr);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory174Screen(
        title_string,
        menu_data->icon.data,
        (PU8)GetString(STR_GLOBAL_OK),
        (PU8)GetImage(IMG_GLOBAL_OK),
        (PU8)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        max_items_num,
        list_items,
        list_items_icons,
        list_hints,
        0,
        hilite_index,
        gui_buffer);

    if (menu_data->help_available)
    {
        sat_sk_hdlr |= SAT_K_SEND_KEY;
    }

    mmi_sat_set_soft_key_hdlr(sat_sk_hdlr);

	if(group_data)			//vikrant	- MAUI_03243383
	{
    srv_sat_start_timer(
            group_data->sim_id,
            SAT_TIMER_NO_RESPONSE,
            MMI_SAT_NO_RESPONSE_DURATION,
            mmi_sat_timer_expiry_hdlr,
            mmi_sat_set_timer_data(SRV_SAT_CMD_SELECT_ITEM));
}
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_sub_menu_response
 * DESCRIPTION
 *  select item command response function.
 * PARAMETERS
 *  sim_id      [IN]        sim id
 *  res_type   [IN]         response type
 * RETURNS
 *  Return MMI_TRUE will show please screen.
 *****************************************************************************/
MMI_BOOL mmi_sat_sub_menu_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
	mmi_sim_enum sim_id = group_data->sim_id;				//slim - slim
    mmi_id gid = SAT_CONTEXT(sim_id)->sub_gid;
	srv_sat_terminal_res_enum res;			//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RES_OK:
			//slim starts
           /* srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    mmi_sat_get_menu_id(gid));*/
			res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;			
			//slim ends
            break;

        case SAT_RES_HELP:
			//slim starts
            /*srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    mmi_sat_get_menu_id(gid));*/
			res = SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER;
			//slim ends
            break;

        case SAT_RES_BACK:
			//slim starts
            /*srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    mmi_sat_get_menu_id(gid)); */
			res = SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER;
			//slim ends
            break;

        case SAT_RES_TERMINATED:
			//slim starts
            /*srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    mmi_sat_get_menu_id(gid));*/
			res = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;
			//slim ends
            ret = MMI_FALSE;
            break;

        default:
			//slim starts
			return ret;
           // break;
    }
srv_sat_terminal_response_select_item(
                    sim_id,
                    res,
                    mmi_sat_get_menu_id(gid));
			//vikrant ends
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_menu_id
 * DESCRIPTION
 *  Get menu item id and convert to SIM item id.
 * PARAMETERS
 *  void
 * RETURNS
 *  return item id
 *****************************************************************************/
U8 mmi_sat_get_menu_id(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_item_struct *item = NULL;
    srv_sat_setup_menu_struct *main_menu = NULL;
    srv_sat_select_item_struct *sub_menu = NULL;
    U8 hilit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(gid);
    hilit_index = group_data->item_index;

    if (group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
    {
        main_menu = (srv_sat_setup_menu_struct *)group_data->data_ptr;
        group_data->menu_index = group_data->item_index;
        item = main_menu->item_list;
    }
    else
    {
        sub_menu = (srv_sat_select_item_struct *)group_data->data_ptr;
        item = sub_menu->item_list;
    }

    return item[hilit_index].id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_display_text_process
 * DESCRIPTION
 *  Display text command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_display_text_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;										//vikrant
    srv_sat_display_text_struct *display_text = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display_text = (srv_sat_display_text_struct *)(&cmd_info->cmd_data);

    if (!mmi_idle_is_group_active() &&
        !mmi_sat_is_in_screen(cmd_info->sim_id) &&
        display_text->priority == SRV_SAT_PRIORITY_NORMAL)
    {
        MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_DO_NOT_INFORM_USER, 2);

        srv_sat_terminal_response_display_text(
                cmd_info->sim_id,
                SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                SRV_SAT_ADDITIONAL_RES_SCREEN_BUSY);

        return;
    }

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, display_text, MMI_FALSE , mmi_sat_display_text_scrn_entry); //slim
   // group_data->func_p = (FuncPtr)mmi_sat_display_text_scrn_entry;		//slim

    if (mmi_scr_locker_is_locked()
        #ifdef __DM_LAWMO_SUPPORT__
            && !mmi_dmui_is_phone_lock()
        #endif
        )
    {
        mmi_sat_scrn_pre_entry(MMI_SCENARIO_ID_GENERAL, group_data);
    }
    else
    {
        mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_display_text_scrn_entry
 * DESCRIPTION
 *  Display text command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_display_text_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_display_text_struct *display_text = NULL;
    mmi_sat_timer_data_struct *user_data = NULL;
    mmi_id grp_id;

	U16 timer;		//slim		
	U16 duration;		//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_display_text_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    display_text = (srv_sat_display_text_struct *)group_data->data_ptr;

    mmi_sat_set_key_and_pen_handler();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef __MMI_NCENTER_SUPPORT__
	vapp_ncenter_disable_drag();  //MAUI_03218918
#endif

    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)display_text->text_string,
        display_text->icon.data,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr(SAT_K_LCRBE);

    if (display_text->immediate_res)
    {
        mmi_sat_me_response_to_cmd(grp_id, SAT_RES_IMMEDIATE_OK);
    }

    user_data = mmi_sat_set_timer_data(SRV_SAT_CMD_DISPLAY_TEXT);
    if (display_text->clear_type == SRV_SAT_CLEAR_AFTER_SHORT_DELAY)
    {
		//slim starts

		/*
        srv_sat_start_timer(
                group_data->sim_id,
                SAT_TIMER_CLEAR_DELAY,
                MMI_SAT_DISPLAY_TEXT_DELAY_DURATION,
                mmi_sat_timer_expiry_hdlr,
                user_data);
		*/

		timer = SAT_TIMER_CLEAR_DELAY;
		duration = MMI_SAT_DISPLAY_TEXT_DELAY_DURATION;

		//slim ends
    }
    else
    {
		//slim starts

		/*
        srv_sat_start_timer(
                group_data->sim_id,
                SAT_TIMER_NO_RESPONSE,
                MMI_SAT_NO_RESPONSE_DURATION,
                mmi_sat_timer_expiry_hdlr,
                user_data);
		*/
		timer = SAT_TIMER_NO_RESPONSE;
		duration = MMI_SAT_NO_RESPONSE_DURATION;

		//slim ends
    }

	//slim starts

		srv_sat_start_timer(
                group_data->sim_id,
                timer,
                duration,
                mmi_sat_timer_expiry_hdlr,
                user_data);

	//slim ends
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_display_text_response
* DESCRIPTION
*  Display text command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
*  is_sent      [IN]        already sent terminal response
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_display_text_response( mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)	//slim
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
	mmi_sim_enum sim_id = group_data->sim_id;											//slim
    srv_sat_terminal_res_enum res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);
    srv_sat_stop_timer(sim_id, SAT_TIMER_CLEAR_DELAY);

    switch (res_type)
    {
        case SAT_RES_OK:
        case SAT_RES_IMMEDIATE_OK:
        case SAT_RES_DELAY_OK:
            res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;
            break;

        case SAT_RES_BACK:
            res = SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER;
            break;

        case SAT_RES_TERMINATED:
            res = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;
            break;

        case SAT_RES_NO_RESPONSE:
            res = SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER;
            break;

        default:
            break;
    }

    srv_sat_terminal_response_display_text(
            sim_id,
            res,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

#ifdef __MMI_NCENTER_SUPPORT__
	vapp_ncenter_enable_drag(); //MAUI_03218918
#endif

    if (res_type == SAT_RES_OK || res_type == SAT_RES_DELAY_OK || res_type == SAT_RES_BACK)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_process
 * DESCRIPTION
 *  Get inkey command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sat_get_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;
	srv_sat_play_tone_struct *play_tone = NULL;

	srv_sat_launch_browser_struct *browser = NULL;

	srv_sat_send_ss_struct *send_ss = NULL;
	srv_sat_send_ussd_struct *send_ussd = NULL;
	srv_sat_send_sms_struct *send_sms = NULL;
	srv_sat_run_at_command_struct *at_cmd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // group_data = (mmi_sat_group_data_struct *)OslMalloc(sizeof(mmi_sat_group_data_struct));
	
	switch (cmd_info->cmd_type)
	{
		case SRV_SAT_CMD_GET_INKEY:
		case SRV_SAT_CMD_GET_INPUT:
			//get_in = cmd_info->cmd_type;
			group_data = mmi_sat_init_group_data(cmd_info->sim_id,cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_get_in_scrn_entry);
			break;

		/*case SRV_SAT_CMD_GET_INPUT:
			get_in = cmd_info->cmd_type;
			group_data = mmi_sat_init_group_data(cmd_info->sim_id,cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_get_in_scrn_entry);
			break;
		*/

		case SRV_SAT_CMD_SELECT_ITEM:
			group_data = mmi_sat_init_group_data( cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_main_and_sub_menu_scrn_entry);
			break;

		case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
		case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE, mmi_sat_send_ussd_ss_result_scrn_entry);
			break;

		/*case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE, mmi_sat_send_ussd_ss_result_scrn_entry);
			break;
		*/

		case SRV_SAT_CMD_PLAY_TONE:
			play_tone = (srv_sat_play_tone_struct *)(&cmd_info->cmd_data);
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, play_tone, MMI_FALSE , mmi_sat_send_s_scrn_entry);
			break;

#ifdef __SATCC__
		case SRV_SAT_CMD_LAUNCH_BROWSER:
			browser = (srv_sat_launch_browser_struct *)(&cmd_info->cmd_data);
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, browser, MMI_FALSE , mmi_sat_setup_call_and_launch_browser_confirm_scrn_entry);
			break;
#endif /* __SATCC__ */


		case SRV_SAT_CMD_SEND_SS:
			send_ss = (srv_sat_send_ss_struct *)(&cmd_info->cmd_data);
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_ss, MMI_FALSE , mmi_sat_send_s_scrn_entry);
			break;

		case SRV_SAT_CMD_SEND_USSD:
			send_ussd = (srv_sat_send_ussd_struct *)(&cmd_info->cmd_data);
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_ussd, MMI_FALSE , mmi_sat_send_s_scrn_entry);
			break;

		case SRV_SAT_CMD_SEND_SMS:
			send_sms = (srv_sat_send_sms_struct *)(&cmd_info->cmd_data);
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_sms, MMI_FALSE , mmi_sat_send_s_scrn_entry);

#ifdef __SATCB__
		case SRV_SAT_CMD_RUN_AT_COMMAND:
			at_cmd = (srv_sat_run_at_command_struct *)(&cmd_info->cmd_data);
			group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, at_cmd, MMI_FALSE , mmi_sat_send_dtmf_at_cmd_scrn_entry);
			break;
#endif /* __SATCB__ */

		default:
			break;
	}
  //  group_data->func_p = (FuncPtr)mmi_sat_get_inkey_scrn_entry;			//slim
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_inkey_process
 * DESCRIPTION
 *  Get inkey command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
 /*
 void mmi_sat_get_inkey_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  //  mmi_sat_group_data_struct *group_data;										//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = mmi_sat_init_group_data(cmd_info->sim_id,cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_get_inkey_scrn_entry); //slim
  //  group_data->func_p = (FuncPtr)mmi_sat_get_inkey_scrn_entry;			//slim
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_inkey_scrn_entry
 * DESCRIPTION
 *  Get inkey command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 /*
 void mmi_sat_get_inkey_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  PU8 gui_buffer = NULL;
    U32 input_type;

	//slim starts

	U16 str;
	U16 img;
	void (*f) (void);

	//slim ends

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_get_inkey_struct *get_inkey = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    get_inkey = (srv_sat_get_inkey_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_get_inkey_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (get_inkey->input_type == SRV_SAT_INPUT_YES_NO)
    {
        U8 *option_list[2];
        group_data->is_yes_no = MMI_TRUE;

        option_list[0] = (PU8)GetString(STR_GLOBAL_YES);
        option_list[1] = (PU8)GetString(STR_GLOBAL_NO);

        RegisterHighlightHandler(mmi_sat_hilit_menu_index_hdlr);

        ShowCategory172Screen(
            (PU8)get_inkey->text_string,
            get_inkey->icon.data,
            (U8*)GetString(STR_GLOBAL_OK),
            0,
            (U8*)GetString(STR_GLOBAL_BACK),
            0,
            2,
            option_list,
            0,
            0,
            gui_buffer);

        mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_LCRBE & ~SAT_K_END_KEY));
    }
    else
    {
        group_data->input_min_len = 1;
        group_data->is_yes_no = MMI_FALSE;
        if (!group_data->input_buf)
        {
            group_data->input_buf = (CHAR *)OslMalloc(ENCODING_LENGTH * 2);
            MMI_ASSERT(group_data->input_buf);
            memset(group_data->input_buf, 0, ENCODING_LENGTH * 2);
        }

        if (get_inkey->input_type == SRV_SAT_INPUT_DIGIT_ONLY)
        {
            input_type = IMM_INPUT_TYPE_SIM_NUMERIC;
            MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;

           //slim starts
			/*
            ShowCategory171Screen(
                (PU8)GetString(STR_GLOBAL_OK),
                (PU8)GetImage(IMG_GLOBAL_OK),
                (PU8)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                (PU8)get_inkey->text_string,
                get_inkey->icon.data,
                input_type,
                (PU8)group_data->input_buf,
                2,
                gui_buffer);

            SetLeftSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);
			*/

	/*		str = STR_GLOBAL_OK;
			img = IMG_GLOBAL_OK;
			f = mmi_sat_response_input_digit_olny_hdlr;

			//slim ends

        }
        else
        {
            input_type = IMM_INPUT_TYPE_SENTENCE;
            if (get_inkey->input_type == SRV_SAT_INPUT_SMS_DEFAULT)
            {
                input_type &= ~IMM_INPUT_TYPE_SENTENCE;
                input_type |= IMM_INPUT_TYPE_ASCII_CHAR;
            }

			//slim starts

			/*
            ShowCategory171Screen(
                (PU8)GetString(STR_GLOBAL_OPTIONS),
                (PU8)GetImage(IMG_GLOBAL_OPTIONS),
                (PU8)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                (PU8)get_inkey->text_string,
                get_inkey->icon.data,
                input_type,
                (PU8)group_data->input_buf,
                2,
                gui_buffer);

            SetLeftSoftkeyFunction(mmi_sat_input_option_hdlr, KEY_EVENT_UP);
			*/
	/*		str = STR_GLOBAL_OPTIONS;
			img = IMG_GLOBAL_OPTIONS;
			f = mmi_sat_input_option_hdlr;

			//slim ends
        }

		//slim starts

		 ShowCategory171Screen(
                (PU8)GetString(str),
                (PU8)GetImage(img),
                (PU8)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                (PU8)get_inkey->text_string,
                get_inkey->icon.data,
                input_type,
                (PU8)group_data->input_buf,
                2,
                gui_buffer);

            SetLeftSoftkeyFunction(f, KEY_EVENT_UP);

		//slim ends


        SetCenterSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);
        SetCategory171RightSoftkeyFunction(mmi_sat_response_back_hdlr, KEY_EVENT_UP);
    }

    if (get_inkey->help_available)
    {
        //SetKeyHandler(mmi_sat_response_help_hdlr, KEY_SEND, KEY_EVENT_UP);
		SetKeyUpHandler(mmi_sat_response_help_hdlr, KEY_SEND);
    }

    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);

    srv_sat_start_timer(
            group_data->sim_id,
            SAT_TIMER_NO_RESPONSE,
            MMI_SAT_NO_RESPONSE_DURATION,
            mmi_sat_timer_expiry_hdlr,
            mmi_sat_set_timer_data(SRV_SAT_CMD_GET_INKEY));
}
*/


/*****************************************************************************
* FUNCTION
*  mmi_sat_get_inkey_response
* DESCRIPTION
*  Get inkey command response function.
* PARAMETERS
*  sim_id      [IN]         sim id
*  res_type   [IN]        response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
/*MMI_BOOL mmi_sat_get_inkey_response( mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /* MMI_BOOL ret = MMI_FALSE;

	//slim starts

	MMI_BOOL is_yes_selected = MMI_FALSE;
	WCHAR *input_buf = (WCHAR *)group_data->input_buf;
	mmi_sim_enum sim_id = group_data->sim_id;
	srv_sat_terminal_res_enum res;	


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
	/*if (group_data->is_yes_no)
            {
                if (!group_data->item_index)
                {
                    is_yes_selected = MMI_TRUE;
                }
            }

	//slim ends

    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RES_OK:
        {
			//slim starts

          /*  srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    is_yes_selected,
                    input_buf);*/


			/*res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;

			//slim ends
            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_HELP:
        {
			//slim starts

            /*srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    MMI_FALSE,
                    NULL);*/

			/*is_yes_selected = MMI_FALSE;
			input_buf = NULL;
			res = SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER;

			//slim ends
            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_BACK:
        {
			//slim starts

          /*  srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    MMI_FALSE,
                    NULL);*/

			/*is_yes_selected = MMI_FALSE;
			input_buf = NULL;
			res = SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER;

			//slim ends
            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_TERMINATED:
        {
			//slim ends

           /* srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    MMI_FALSE,
                    NULL);*/

			/*is_yes_selected = MMI_FALSE;
			input_buf = NULL;
			res = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;

			//slim ends
            ret = MMI_FALSE;
            break;
        }

        default:
		//slim starts

           return ret;
			// break;
    }

	srv_sat_terminal_response_get_inkey(
                    sim_id,
                    res,
                    is_yes_selected,
                    input_buf);

		//slim ends
    return ret;
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_input_process
 * DESCRIPTION
 *  Get input command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*void mmi_sat_get_input_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  mmi_sat_group_data_struct *group_data;											//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = mmi_sat_init_group_data(cmd_info->sim_id,cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_get_in_scrn_entry);  //slim
    //group_data->func_p = (FuncPtr)mmi_sat_get_input_scrn_entry;			//slim
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}*/

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_in_scrn_entry
 * DESCRIPTION
 *  Get input command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_in_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;
    U32 input_type;

	U16 str;			//slim
	U16 img;			//slim
	void (*f) (void);		//slim

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_get_input_struct *get_input = NULL;
	srv_sat_get_inkey_struct *get_inkey = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);

	if(group_data->cmd_type == SRV_SAT_CMD_GET_INPUT)
	{
		get_input = (srv_sat_get_input_struct *)group_data->data_ptr;
	}
	else
	{
		get_inkey = (srv_sat_get_inkey_struct *)group_data->data_ptr;
	}

    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_get_in_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
}

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);
	mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);


	
	
if(group_data->cmd_type == SRV_SAT_CMD_GET_INKEY)
{
    if (get_inkey->input_type == SRV_SAT_INPUT_YES_NO)
    {
       U8 *option_list[2];
        group_data->is_yes_no = MMI_TRUE;

        option_list[0] = (PU8)GetString(STR_GLOBAL_YES);
        option_list[1] = (PU8)GetString(STR_GLOBAL_NO);

        RegisterHighlightHandler(mmi_sat_hilit_menu_index_hdlr);

        ShowCategory172Screen(
            (PU8)get_inkey->text_string,
            get_inkey->icon.data,
            (U8*)GetString(STR_GLOBAL_OK),
            0,
            (U8*)GetString(STR_GLOBAL_BACK),
            0,
            2,
            option_list,
            0,
            0,
            gui_buffer);

        mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_LCRBE & ~SAT_K_END_KEY));
    }
    else
    {
        group_data->input_min_len = 1;
        group_data->is_yes_no = MMI_FALSE;
        if (!group_data->input_buf)
        {
            group_data->input_buf = (CHAR *)OslMalloc(ENCODING_LENGTH * 2);
            MMI_ASSERT(group_data->input_buf);
            memset(group_data->input_buf, 0, ENCODING_LENGTH * 2);
        }

        if (get_inkey->input_type == SRV_SAT_INPUT_DIGIT_ONLY)
        {
            input_type = IMM_INPUT_TYPE_SIM_NUMERIC;
            MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;

           //slim starts
			/*
            ShowCategory171Screen(
                (PU8)GetString(STR_GLOBAL_OK),
                (PU8)GetImage(IMG_GLOBAL_OK),
                (PU8)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                (PU8)get_inkey->text_string,
                get_inkey->icon.data,
                input_type,
                (PU8)group_data->input_buf,
                2,
                gui_buffer);

            SetLeftSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);
			*/

			str = STR_GLOBAL_OK;
			img = IMG_GLOBAL_OK;
			f = mmi_sat_response_input_digit_olny_hdlr;

			//slim ends

        }
        else
        {
            input_type = IMM_INPUT_TYPE_SENTENCE;
            if (get_inkey->input_type == SRV_SAT_INPUT_SMS_DEFAULT)
            {
                input_type &= ~IMM_INPUT_TYPE_SENTENCE;
                input_type |= IMM_INPUT_TYPE_ASCII_CHAR;
            }

			//slim starts

			/*
            ShowCategory171Screen(
                (PU8)GetString(STR_GLOBAL_OPTIONS),
                (PU8)GetImage(IMG_GLOBAL_OPTIONS),
                (PU8)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                (PU8)get_inkey->text_string,
                get_inkey->icon.data,
                input_type,
                (PU8)group_data->input_buf,
                2,
                gui_buffer);

            SetLeftSoftkeyFunction(mmi_sat_input_option_hdlr, KEY_EVENT_UP);
			*/
			str = STR_GLOBAL_OPTIONS;
			img = IMG_GLOBAL_OPTIONS;
			f = mmi_sat_input_option_hdlr;

			//slim ends
        }

		//slim starts

		 ShowCategory171Screen(
                (PU8)GetString(str),
                (PU8)GetImage(img),
                (PU8)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                (PU8)get_inkey->text_string,
                get_inkey->icon.data,
                input_type,
                (PU8)group_data->input_buf,
                2,
                gui_buffer);

            /*SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
		//ChangeCenterSoftkey(TEXT_SOFTKEY_OK_MK, 0);

        SetCenterSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);
        SetCategory171RightSoftkeyFunction(mmi_sat_response_back_hdlr, KEY_EVENT_UP);*/
	}
}
	
	
else if (group_data->cmd_type = SRV_SAT_CMD_GET_INPUT)
{
			group_data->input_min_len = get_input->min_length;
			if (!group_data->input_buf)
				{
					group_data->input_max_len = (U8)(get_input->max_length >= get_input->min_length ? get_input->max_length : get_input->min_length);
					group_data->input_buf = (CHAR *)OslMalloc(group_data->input_max_len * ENCODING_LENGTH + ENCODING_LENGTH);
					memset(group_data->input_buf, 0, group_data->input_max_len * ENCODING_LENGTH + ENCODING_LENGTH);

					if (get_input->default_text!= NULL && get_input->max_length >= mmi_wcslen(get_input->default_text))
						{
							mmi_wcscpy((WCHAR *)group_data->input_buf, get_input->default_text);
						}
}

			if ( get_input->input_type == SRV_SAT_INPUT_DIGIT_ONLY)
				{
					
						if (get_input->echo_mode)
							{
								input_type = IMM_INPUT_TYPE_SIM_NUMERIC;
								MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;
							}
						else
							{
								input_type = IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD;
							}

		//slim starts
		/*
        ShowCategory171Screen(
            (PU8)GetString(STR_GLOBAL_OK),
            (PU8)GetImage(IMG_GLOBAL_OK),
            (PU8)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            (PU8)get_input->text_string,
            get_input->icon.data,
            input_type,
            (PU8)group_data->input_buf,
            group_data->input_max_len + 1,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);

		*/

							str = STR_GLOBAL_OK;
							img = IMG_GLOBAL_OK;
							f = mmi_sat_response_input_digit_olny_hdlr;

		//slim ends
			}
					
			else
				{
					if (get_input->echo_mode)
					{
						input_type = IMM_INPUT_TYPE_SENTENCE;
					}
					else
					{
						input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
					}

					if (get_input->input_type == SRV_SAT_INPUT_SMS_DEFAULT)
					{
						input_type &= ~IMM_INPUT_TYPE_SENTENCE;
						input_type |= IMM_INPUT_TYPE_ASCII_CHAR;
}

		//slim starts
		
		/*
        ShowCategory171Screen(
            (PU8) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            (PU8)get_input->text_string,
            get_input->icon.data,
            input_type,
            (PU8)group_data->input_buf,
            group_data->input_max_len + 1,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_sat_input_option_hdlr, KEY_EVENT_UP);
		*/

						str = STR_GLOBAL_OPTIONS;
						img = IMG_GLOBAL_OPTIONS;
						f = mmi_sat_input_option_hdlr;

		//slim ends
				}

	//slim starts

	 ShowCategory171Screen(
            (PU8) GetString(str),
            (PU8) GetImage(img),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            (PU8)get_input->text_string,
            get_input->icon.data,
            input_type,
            (PU8)group_data->input_buf,
            group_data->input_max_len + 1,
            gui_buffer);

       /* SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);        
		SetCategory171RightSoftkeyFunction(mmi_sat_response_back_hdlr, KEY_EVENT_UP);*/

	//slim ends
			
}
if((group_data->cmd_type == SRV_SAT_CMD_GET_INKEY && get_inkey->input_type != SRV_SAT_INPUT_YES_NO) || (group_data->cmd_type == SRV_SAT_CMD_GET_INPUT))
{
		SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);        
		SetCategory171RightSoftkeyFunction(mmi_sat_response_back_hdlr, KEY_EVENT_UP);
}
			

    if ((group_data->cmd_type == SRV_SAT_CMD_GET_INPUT && get_input->help_available) || (group_data->cmd_type == SRV_SAT_CMD_GET_INKEY && get_inkey->help_available))
    {
        SetKeyHandler(mmi_sat_response_help_hdlr, KEY_SEND, KEY_EVENT_DOWN);
		//SetKeyUpHandler(mmi_sat_response_help_hdlr, KEY_SEND);
    }

    //SetCenterSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);        
    
    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);


			srv_sat_start_timer(
					group_data->sim_id,
					SAT_TIMER_NO_RESPONSE,
					MMI_SAT_NO_RESPONSE_DURATION,
					mmi_sat_timer_expiry_hdlr,
					mmi_sat_set_timer_data(group_data->cmd_type));
		

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_input_scrn_entry
 * DESCRIPTION
 *  Get input command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*void mmi_sat_get_input_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  PU8 gui_buffer = NULL;
    U32 input_type;

	U16 str;			//slim
	U16 img;			//slim
	void (*f) (void);		//slim

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_get_input_struct *get_input = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    get_input = (srv_sat_get_input_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_get_input_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    group_data->input_min_len = get_input->min_length;
    if (!group_data->input_buf)
    {
        group_data->input_max_len = (U8)(get_input->max_length >= get_input->min_length ? get_input->max_length : get_input->min_length);
        group_data->input_buf = (CHAR *)OslMalloc(group_data->input_max_len * ENCODING_LENGTH + ENCODING_LENGTH);
        memset(group_data->input_buf, 0, group_data->input_max_len * ENCODING_LENGTH + ENCODING_LENGTH);

        if (get_input->default_text!= NULL && get_input->max_length >= mmi_wcslen(get_input->default_text))
        {
            mmi_wcscpy((WCHAR *)group_data->input_buf, get_input->default_text);
        }
    }

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (get_input->input_type == SRV_SAT_INPUT_DIGIT_ONLY)
    {
        if (get_input->echo_mode)
        {
            input_type = IMM_INPUT_TYPE_SIM_NUMERIC;
            MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;
        }
        else
        {
            input_type = IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD;
        }

		//slim starts
		/*
        ShowCategory171Screen(
            (PU8)GetString(STR_GLOBAL_OK),
            (PU8)GetImage(IMG_GLOBAL_OK),
            (PU8)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            (PU8)get_input->text_string,
            get_input->icon.data,
            input_type,
            (PU8)group_data->input_buf,
            group_data->input_max_len + 1,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);

		*/

	/*	str = STR_GLOBAL_OK;
		img = IMG_GLOBAL_OK;
		f = mmi_sat_response_input_digit_olny_hdlr;

		//slim ends
    }
    else
    {
        if (get_input->echo_mode)
        {
            input_type = IMM_INPUT_TYPE_SENTENCE;
        }
        else
        {
            input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
        }

        if (get_input->input_type == SRV_SAT_INPUT_SMS_DEFAULT)
        {
            input_type &= ~IMM_INPUT_TYPE_SENTENCE;
            input_type |= IMM_INPUT_TYPE_ASCII_CHAR;
        }

		//slim starts
		
		/*
        ShowCategory171Screen(
            (PU8) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            (PU8)get_input->text_string,
            get_input->icon.data,
            input_type,
            (PU8)group_data->input_buf,
            group_data->input_max_len + 1,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_sat_input_option_hdlr, KEY_EVENT_UP);
		*/

	/*	str = STR_GLOBAL_OPTIONS;
		img = IMG_GLOBAL_OPTIONS;
		f = mmi_sat_input_option_hdlr;

		//slim ends
    }

	//slim starts

	 ShowCategory171Screen(
            (PU8) GetString(str),
            (PU8) GetImage(img),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            (PU8)get_input->text_string,
            get_input->icon.data,
            input_type,
            (PU8)group_data->input_buf,
            group_data->input_max_len + 1,
            gui_buffer);

        SetLeftSoftkeyFunction(f, KEY_EVENT_UP);

	//slim ends

    if (get_input->help_available)
    {
        //SetKeyHandler(mmi_sat_response_help_hdlr, KEY_SEND, KEY_EVENT_UP);
		SetKeyUpHandler(mmi_sat_response_help_hdlr, KEY_SEND);
    }

    SetCenterSoftkeyFunction(mmi_sat_response_input_digit_olny_hdlr, KEY_EVENT_UP);        
    SetCategory171RightSoftkeyFunction(mmi_sat_response_back_hdlr, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);

    srv_sat_start_timer(
            group_data->sim_id,
            SAT_TIMER_NO_RESPONSE,
            MMI_SAT_NO_RESPONSE_DURATION,
            mmi_sat_timer_expiry_hdlr,
            mmi_sat_set_timer_data(SRV_SAT_CMD_GET_INPUT));
}
*/


/*****************************************************************************
* FUNCTION
*  mmi_sat_get_input_and_inkey_response
* DESCRIPTION
*  Get input command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_get_input_and_inkey_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_sat_terminal_res_enum res;
	MMI_BOOL is_yes_selected = MMI_FALSE;

	//slim starts

	mmi_sim_enum sim_id = group_data->sim_id;	
	WCHAR *input_buf = (WCHAR *)group_data->input_buf;

	if (group_data->cmd_type == SRV_SAT_CMD_GET_INKEY  && group_data->is_yes_no)
            {
                if (!group_data->item_index)
                {
                    is_yes_selected = MMI_TRUE;
                }
            }

	//slim ends


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RES_OK:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    input_buf);*/
			res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;		//vikrant

            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_HELP:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    NULL);*/
			res = SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER;		//vikrant
			input_buf = NULL;											//vikrant
            ret = MMI_TRUE;
			if(group_data->cmd_type == SRV_SAT_CMD_GET_INKEY)
			{
				is_yes_selected = MMI_FALSE;
			}
            break;
        }

        case SAT_RES_BACK:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    NULL);*/
			res = SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER;		
			input_buf = NULL;																		//vikrant	
            ret = MMI_TRUE;
			if(group_data->cmd_type == SRV_SAT_CMD_GET_INKEY)
			{
				is_yes_selected = MMI_FALSE;
			}
            break;
        }

        case SAT_RES_TERMINATED:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    NULL);*/
			res = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;			
			input_buf = NULL;															
			if(group_data->cmd_type == SRV_SAT_CMD_GET_INKEY)
			{
				is_yes_selected = MMI_FALSE;
			}
            break;
        }

        default:
			//slim starts
			return ret;			
          //  break;			
    }
	if(group_data->cmd_type == SRV_SAT_CMD_GET_INPUT)
	{
	srv_sat_terminal_response_get_input(											
                    sim_id,
                    res,
                    input_buf);
	}
	else
	{
		srv_sat_terminal_response_get_inkey(
                    sim_id,
                    res,
                    is_yes_selected,
                    input_buf);
	}
			//slim ends
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_sat_get_input_response
* DESCRIPTION
*  Get input command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
/*MMI_BOOL mmi_sat_get_input_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*MMI_BOOL ret = MMI_FALSE;
    srv_sat_terminal_res_enum res;

	//slim starts

	mmi_sim_enum sim_id = group_data->sim_id;	
	WCHAR *input_buf = (WCHAR *)group_data->input_buf;

	//slim ends


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RES_OK:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    input_buf);*/
			/*res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;		//vikrant

            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_HELP:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    NULL);*/
			/*res = SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER;		//vikrant
			input_buf = NULL;											//vikrant
            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_BACK:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    NULL);*/
			/*res = SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER;		
			input_buf = NULL;																		//vikrant	
            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_TERMINATED:
        {
          /*  srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    NULL);*/
			/*res = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;			
			input_buf = NULL;															
            break;
        }

        default:
			//slim starts
			return ret;			
          //  break;			
    }
	srv_sat_terminal_response_get_input(											
                    sim_id,
                    res,
                    input_buf);
			//slim ends
    return ret;
}
*/


/*****************************************************************************
* FUNCTION
*  mmi_sat_input_text_check
* DESCRIPTION
*  Input validity check.
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE is valid.
*****************************************************************************/
MMI_BOOL mmi_sat_input_text_check(mmi_sat_group_data_struct *group_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len;
    U8 display_info[64], temp_info[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = (U16)(mmi_ucs2strlen((CHAR *)group_data->input_buf));
    if (len < group_data->input_min_len)
    {
        mmi_ucs2cpy((CHAR *)display_info, (CHAR *)get_string(STR_ID_SAT_GET_INPUT_LENGTH_NOT_ENOUGH));
        kal_wsprintf((PU16)temp_info, "%d", group_data->input_min_len);
        mmi_ucs2cat((CHAR *)display_info, (CHAR *)temp_info);

        mmi_popup_display((WCHAR *)display_info, MMI_EVENT_FAILURE, NULL);

        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_play_tone_process
 * DESCRIPTION
 *  Play tone command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 ****************************************************************************/
/*
void mmi_sat_play_tone_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  mmi_sat_group_data_struct *group_data;											//slim
    srv_sat_play_tone_struct *play_tone = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  play_tone = (srv_sat_play_tone_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, play_tone, MMI_FALSE , mmi_sat_play_tone_scrn_entry);	
   // group_data->func_p = (FuncPtr)mmi_sat_play_tone_scrn_entry;				//slim
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_play_tone_scrn_entry
 * DESCRIPTION
 *  Play tone command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*void mmi_sat_play_tone_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /* PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_play_tone_struct *play_tone = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    play_tone = (srv_sat_play_tone_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_play_tone_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (!(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED) &&
        !(srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED))
#else 
    if (!(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED))
#endif 
    {
        /* not play tone in slient mode */
     /*   srv_prof_play_tone_with_id(SRV_PROF_TONE_SAT, play_tone->tone, SRV_PROF_RING_TYPE_REPEAT, NULL);
    }

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)play_tone->alpha_id,
        play_tone->icon.data,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_RSK_BACK | SAT_K_END_KEY));

    srv_sat_start_timer(
            group_data->sim_id,
            SAT_TIMER_PLAY_TONE,
            play_tone->duration,
            mmi_sat_timer_expiry_hdlr,
            mmi_sat_set_timer_data(SRV_SAT_CMD_PLAY_TONE));
}
*/


/*****************************************************************************
* FUNCTION
*  mmi_sat_play_tone_response
* DESCRIPTION
*  Play tone command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_play_tone_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
	mmi_sim_enum sim_id = group_data->sim_id;								// slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_stop_timer(sim_id, SAT_TIMER_PLAY_TONE);
    srv_prof_stop_tone(SRV_PROF_TONE_SAT);

    switch (res_type)
    {
        case SAT_RES_BACK:
        {
			//slim starts

			/*
            srv_sat_terminal_response_play_tone(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);
			*/

			//slim ends

            ret = MMI_TRUE;
            break;
        }

        case SAT_RES_TERMINATED:
        {                
			//slim starts

			/*
            srv_sat_terminal_response_play_tone(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);
			*/

			//slim ends
            break;
        }

        default:
            return ret;
    }

	//slim starts

	 srv_sat_terminal_response_play_tone(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

	 //slim ends

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_sms_process
 * DESCRIPTION
 *  Send SMS command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*void mmi_sat_send_sms_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  mmi_sat_group_data_struct *group_data;													//slim		
    srv_sat_send_sms_struct *send_sms = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  send_sms = (srv_sat_send_sms_struct *)(&cmd_info->cmd_data); 

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_sms, MMI_FALSE , mmi_sat_send_s_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_send_sms_scrn_entry;				
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/

void mmi_sat_send_s_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_sms_struct *send_sms = NULL;
	srv_sat_send_ussd_struct *send_ussd = NULL;
	srv_sat_send_ss_struct *send_ss = NULL;
	srv_sat_play_tone_struct *play_tone = NULL;
    mmi_id *gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);

	if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_SMS)
	{
		send_sms = (srv_sat_send_sms_struct *)group_data->data_ptr;
	}
	else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_USSD)
	{
		send_ussd = (srv_sat_send_ussd_struct *)group_data->data_ptr;
	}
	else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_SS)
	{
		send_ss = (srv_sat_send_ss_struct *)group_data->data_ptr;
	}
	else if(group_data->cmd_type == SRV_SAT_CMD_PLAY_TONE)
	{
		play_tone = (srv_sat_play_tone_struct *)group_data->data_ptr;
	}

    gid_p = &SAT_CONTEXT(group_data->sim_id)->sub_gid;


    if (!mmi_frm_scrn_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_s_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);
	if(group_data->cmd_type == SRV_SAT_CMD_PLAY_TONE)
	{
		#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (!(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED) &&
        !(srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED))
#else 
    if (!(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED))
#endif 
    {
        /* not play tone in slient mode */
        srv_prof_play_tone_with_id(SRV_PROF_TONE_SAT, play_tone->tone, SRV_PROF_RING_TYPE_REPEAT, NULL);
    }
	}

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    /*ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_sms->alpha_id, send_sms->icon.data, gui_buffer);*/

	if(group_data->cmd_type == SRV_SAT_CMD_PLAY_TONE)
	{
		ShowCategory151Screen(
			0,
			0,
			0,
			0,
			STR_GLOBAL_BACK,
			IMG_GLOBAL_BACK,
			(PU8)play_tone->alpha_id,
			play_tone->icon.data,
			gui_buffer);

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_RSK_BACK | SAT_K_END_KEY));

    srv_sat_start_timer(
            group_data->sim_id,
            SAT_TIMER_PLAY_TONE,
            play_tone->duration,
            mmi_sat_timer_expiry_hdlr,
            mmi_sat_set_timer_data(SRV_SAT_CMD_PLAY_TONE));
	}
	else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_SMS)
	{
		ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_sms->alpha_id, send_sms->icon.data, gui_buffer);
	}

	else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_USSD)
	{
		ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_ussd->alpha_id, send_ussd->icon.data, gui_buffer);
	}

	else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_SS)
	{
		ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_ss->alpha_id, send_ss->icon.data, gui_buffer);
	}

	if(group_data->cmd_type != SRV_SAT_CMD_PLAY_TONE)
	{
		ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
	}

    if (gui_buffer == NULL && group_data->cmd_type != SRV_SAT_CMD_PLAY_TONE)
    {
        group_data->is_sent = MMI_TRUE;

		if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_SMS)
		{
			srv_sat_terminal_response_send_sms_stage1(group_data->sim_id);
		}
		else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_USSD)
		{
			srv_sat_terminal_response_send_ussd_stage1(group_data->sim_id);
		}
		else if(gb_cmd_s_info->cmd_type == SRV_SAT_CMD_SEND_SS)
		{
			 srv_sat_terminal_response_send_ss_stage1(group_data->sim_id);
		}
    }
	
	
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_sms_scrn_entry
 * DESCRIPTION
 *  Send SMS command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_sms_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /* PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_sms_struct *send_sms = NULL;
    mmi_id *gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    send_sms = (srv_sat_send_sms_struct *)group_data->data_ptr;
    gid_p = &SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_sms_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_sms->alpha_id, send_sms->icon.data, gui_buffer);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (gui_buffer == NULL)
    {
        group_data->is_sent = MMI_TRUE;
        srv_sat_terminal_response_send_sms_stage1(group_data->sim_id);
    }
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ss_process
 * DESCRIPTION
 *  Send SS command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ss_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 /*   mmi_sat_group_data_struct *group_data;												//slim
    srv_sat_send_ss_struct *send_ss = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 /*   send_ss = (srv_sat_send_ss_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_ss, MMI_FALSE , mmi_sat_send_s_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_send_ss_scrn_entry;						
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ss_scrn_entry
 * DESCRIPTION
 *  Send SS command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ss_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 /*   PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_ss_struct *send_ss = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    send_ss = (srv_sat_send_ss_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_ss_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_ss->alpha_id, send_ss->icon.data, gui_buffer);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (gui_buffer == NULL)
    {
        group_data->is_sent = MMI_TRUE;
        srv_sat_terminal_response_send_ss_stage1(group_data->sim_id);
    }
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ss_result_process
 * DESCRIPTION
 *  Send SS result process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ss_result_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 /*   mmi_sat_group_data_struct *group_data;														//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE, mmi_sat_send_ss_result_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_send_ss_result_scrn_entry;					
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ss_result_scrn_entry
 * DESCRIPTION
 *  Send SS result screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ss_result_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_ss_struct *send_ss_res = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    send_ss_res = (srv_sat_send_ss_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_ss_result_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)send_ss_res->text_string,
        NULL,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_LCRBE & ~SAT_K_END_KEY));
}
*/


/*****************************************************************************
* FUNCTION
*  mmi_sat_send_ss_and_ussd_result_response
* DESCRIPTION
*  Send SS result response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_ss_and_ussd_result_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	//slim starts

	mmi_sim_enum sim_id = group_data->sim_id;
	srv_sat_send_ss_struct *send_ss = (srv_sat_send_ss_struct *)group_data->data_ptr;
	U8 length_ss = send_ss->length;
	PU8 add_info_ss = send_ss->additional_info;

	srv_sat_send_ussd_struct *send_ussd = (srv_sat_send_ussd_struct *)group_data->data_ptr;
	U8 length_ussd = send_ussd->length;
	PU8 add_info_ussd = send_ussd->additional_info;

	//slim ends

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(group_data->cmd_type == SRV_SAT_CMD_SEND_SS_RETURN_RESULT)
	{
    srv_sat_terminal_response_send_ss_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            length_ss,
            add_info_ss);
	}
	else
	{
		srv_sat_terminal_response_send_ussd_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            length_ussd,
            add_info_ussd);
	}

	if(group_data->cmd_type == SRV_SAT_CMD_SEND_SS_RETURN_RESULT)
	{
		return res_type != SAT_RES_TERMINATED ? MMI_FALSE : MMI_TRUE;
	}
	else
	{
		return res_type == SAT_RES_TERMINATED ? MMI_FALSE : MMI_TRUE;
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_sat_send_ss_result_response
* DESCRIPTION
*  Send SS result response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
/*MMI_BOOL mmi_sat_send_ss_result_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	//slim starts

	/*mmi_sim_enum sim_id = group_data->sim_id;
	srv_sat_send_ss_struct *send_ss = (srv_sat_send_ss_struct *)group_data->data_ptr;
	U8 length = send_ss->length;
	PU8 add_info = send_ss->additional_info;

	//slim ends

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*srv_sat_terminal_response_send_ss_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            length,
            add_info);

    return res_type != SAT_RES_TERMINATED ? MMI_FALSE : MMI_TRUE;
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ussd_process
 * DESCRIPTION
 *  Send USSD command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ussd_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  mmi_sat_group_data_struct *group_data;										//slim
    srv_sat_send_ussd_struct *send_ussd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* send_ussd = (srv_sat_send_ussd_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_ussd, MMI_FALSE , mmi_sat_send_s_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_send_ussd_scrn_entry;					
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ussd_scrn_entry
 * DESCRIPTION
 *  Send USSD command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ussd_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_ussd_struct *send_ussd = NULL;
    mmi_id *gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    send_ussd = (srv_sat_send_ussd_struct *)group_data->data_ptr;
    gid_p = &SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_ussd_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)send_ussd->alpha_id, send_ussd->icon.data, gui_buffer);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (gui_buffer == NULL)
    {
        group_data->is_sent = MMI_TRUE;
        srv_sat_terminal_response_send_ussd_stage1(group_data->sim_id);
    }
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ussd_result_process
 * DESCRIPTION
 *  Send USSD command result process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ussd_result_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  mmi_sat_group_data_struct *group_data;											//slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_send_ussd_result_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_send_ussd_result_scrn_entry;					
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}
*/

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ussd_result_scrn_entry
 * DESCRIPTION
 *  Send USSD command result screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_send_ussd_ss_result_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_ussd_struct *send_ussd_res = NULL;
	srv_sat_send_ss_struct *send_ss_res = NULL;
    mmi_id *gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);

	if(group_data->cmd_type == SRV_SAT_CMD_SEND_USSD_RETURN_RESULT)
	{
		send_ussd_res = (srv_sat_send_ussd_struct *)group_data->data_ptr;
	}
	else
	{
		send_ss_res = (srv_sat_send_ss_struct *)group_data->data_ptr;
	}
    gid_p = &SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_ussd_ss_result_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	if(group_data->cmd_type == SRV_SAT_CMD_SEND_USSD_RETURN_RESULT)
	{
			ShowCategory151Screen(
				0,
				0,
				STR_GLOBAL_OK,
				IMG_GLOBAL_OK,
				STR_GLOBAL_BACK,
				IMG_GLOBAL_BACK,
				(PU8)send_ussd_res->text_string,
				NULL,
				gui_buffer);
	}
	else
	{
		    ShowCategory151Screen(
				0,
				0,
				STR_GLOBAL_OK,
				IMG_GLOBAL_OK,
				STR_GLOBAL_BACK,
				IMG_GLOBAL_BACK,
				(PU8)send_ss_res->text_string,
				NULL,
				gui_buffer);
	}

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_LCRBE & ~SAT_K_END_KEY));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_ussd_result_scrn_entry
 * DESCRIPTION
 *  Send USSD command result screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mmi_sat_send_ussd_result_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_ussd_struct *send_ussd_res = NULL;
    mmi_id *gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    send_ussd_res = (srv_sat_send_ussd_struct *)group_data->data_ptr; 
    gid_p = &SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_ussd_result_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)send_ussd_res->text_string,
        NULL,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_LCRBE & ~SAT_K_END_KEY));
}
*/


/*****************************************************************************
* FUNCTION
*  mmi_sat_send_ussd_result_response
* DESCRIPTION
*  Send USSD command result response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]        response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
/*MMI_BOOL mmi_sat_send_ussd_result_response( mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
	//slim starts

	mmi_sim_enum sim_id = group_data->sim_id;
	srv_sat_send_ss_struct *send_ss = (srv_sat_send_ss_struct *)group_data->data_ptr;
	U8 length = send_ss->length;
	PU8 add_info = send_ss->additional_info;

	//slim ends

    srv_sat_terminal_response_send_ussd_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            length,
            add_info);

//slim starts

   // return res_type == SAT_RES_TERMINATED ? MMI_FALSE : MMI_TRUE;

	if(res_type == SAT_RES_TERMINATED)
	{
		return MMI_FALSE;
	}
	else
	{
		return MMI_TRUE;
	}

//slim ends
}
*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_setup_call_process
 * DESCRIPTION
 *  Setup call command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_setup_call_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;													//vikrant

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_stop_timer(cmd_info->sim_id, SAT_TIMER_WAIT);

    if (srv_charbat_is_low_battery())
    {
        ChgrPlayLowBatTone();
        if (MMI_FALSE == srv_charbat_check_if_mo_allow())
        {
            srv_charbat_set_low_bat_threshold(LBAT_TALK_DURCNT_PROHIBIT);
        }
        else
        {
            srv_charbat_set_low_bat_threshold(LBAT_TALK_DURCNT_NORMAL);
        }
    }

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, &cmd_info->cmd_data, MMI_FALSE , mmi_sat_setup_call_confirm_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_setup_call_confirm_scrn_entry;				
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_setup_call_confirm_scrn_entry
 * DESCRIPTION
 *  Setup call command confirm screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_setup_call_confirm_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_setup_call_struct *call = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    call = (srv_sat_setup_call_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_setup_call_confirm_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (call->icon2.available)
    {
        SAT_CONTEXT(group_data->sim_id)->calling_icon_available =
            mmi_sat_save_calling_icon(
                group_data->sim_id,
                call->icon2.data,
                mmi_sat_create_calling_icon_path(
                    group_data->sim_id,
                    &SAT_CONTEXT(group_data->sim_id)->calling_icon_path));
    }
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (PU8)call->alpha_id1,
        call->icon1.data,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr(SAT_K_LCRCE);
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_setup_call_response
* DESCRIPTION
*  Setup call command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_setup_call_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type, srv_ucm_result_enum *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res_type)
    {
        case SAT_RES_OK:
            mmi_sat_setup_call_ucm_requset(sim_id, error_code);
            break;

        case SAT_RES_CANCEL:
            srv_sat_terminal_response_setup_call_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RES_TERMINATED:
            srv_sat_terminal_response_setup_call_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            break;

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_setup_call_ucm_requset
* DESCRIPTION
*  Call UCM service to lauch a call.
* PARAMETERS
*  sim_id      [IN]        sim id
* RETURNS
*  void
*****************************************************************************/
void mmi_sat_setup_call_ucm_requset(mmi_sim_enum sim_id, srv_ucm_result_enum *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct dial_req;
    srv_ucm_result_enum result;
    srv_sat_proactive_sim_struct *cmd_data = NULL;
    srv_sat_setup_call_struct *call = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmd_data = (srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(sim_id); 
    call = (srv_sat_setup_call_struct *)(&cmd_data->cmd_data);
    memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));

#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_id == MMI_SIM2)
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim_id == MMI_SIM3)
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim_id == MMI_SIM4)
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
    else
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
    }
#else
    dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
#endif /* MMI_MAX_SIM_NUM >= 2 */

    dial_req.module_id = SRV_UCM_MODULE_ORIGIN_SAT;
    mmi_asc_n_to_ucs2((CHAR *)dial_req.num_uri, (CHAR *)call->number, SRV_UCM_MAX_NUM_URI_LEN);

    /* Dial */
    result = srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, &dial_req);
    if (result == SRV_UCM_RESULT_OK)
    {
        srv_ucm_act_request(SRV_UCM_DIAL_ACT, &dial_req, NULL, NULL);
    }
    else
    {
        /* Error handling for action can't be performed */
        //mmi_sat_ucm_display_popup(result);
        *error_code = result;
        srv_sat_terminal_response_setup_call_stage2(
                sim_id,
                SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_dtmf_process
 * DESCRIPTION
 *  Send DTMF command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_send_dtmf_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;														//slim
    srv_sat_send_dtmf_struct *dtmf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmf = (srv_sat_send_dtmf_struct *)(&cmd_info->cmd_data);

    srv_sat_terminal_response_send_dtmf_stage1(cmd_info->sim_id);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, dtmf, MMI_FALSE , mmi_sat_send_dtmf_scrn_entry);	//slim
    //group_data->func_p = (FuncPtr)mmi_sat_send_dtmf_scrn_entry;				
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_dtmf_scrn_entry
 * DESCRIPTION
 *  Send DTMF command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_send_dtmf_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_dtmf_struct *dtmf = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    dtmf = (srv_sat_send_dtmf_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_send_dtmf_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_sat_set_key_and_pen_handler();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)dtmf->alpha_id,
        dtmf->icon.data,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_ABORT | SAT_K_END_KEY));
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_send_dtmf_response
* DESCRIPTION
*  Send DTMF command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_dtmf_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_sim_enum sim_id = group_data->sim_id;									// slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_send_dtmf_abort_req(sim_id);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_run_at_cmd_process
 * DESCRIPTION
 *  Run AT  command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/

#ifdef __SATCB__
void mmi_sat_run_at_cmd_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;											//vikrant
    srv_sat_run_at_command_struct *at_cmd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    at_cmd = (srv_sat_run_at_command_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, at_cmd, MMI_FALSE , mmi_sat_run_at_cmd_scrn_entry);	//vikrant
    //group_data->func_p = (FuncPtr)mmi_sat_run_at_cmd_scrn_entry;			//vikrant
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_run_at_cmd_scrn_entry
 * DESCRIPTION
 *  Run AT command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_run_at_cmd_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_run_at_command_struct *at_cmd = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    at_cmd = (srv_sat_run_at_command_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_run_at_cmd_srcn_exit, (FuncPtr)mmi_sat_run_at_cmd_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)at_cmd->alpha_id, at_cmd->icon.data, NULL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    srv_sat_start_timer(
            group_data->sim_id,
            SAT_TIMER_POPUP,
            MMI_SAT_POPUP_DURATION,
            mmi_sat_timer_expiry_hdlr,
            mmi_sat_set_timer_data(SRV_SAT_CMD_RUN_AT_COMMAND));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_run_at_cmd_srcn_exit
 * DESCRIPTION
 *  Run AT command screen exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_run_at_cmd_srcn_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());
    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_POPUP);
}

#endif /* __SATCB__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_sim_refresh_process
 * DESCRIPTION
 *  Sim refresh.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_sim_refresh_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_refresh_struct *refresh = NULL;
    MMI_ID group_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh = (srv_sat_refresh_struct *)(&cmd_info->cmd_data);

    if (refresh->refresh_type == SRV_SAT_REFRESH_RESET)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        mmi_popup_display_ext(STR_ID_SAT_SIM_REFRESH, MMI_EVENT_PROGRESS, NULL);
    #ifndef __SIM_RESET_BY_SIM__
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
        {
            srv_alm_normal_reset(MMI_TRUE, 3);
        }
    #endif /*__SIM_RESET_BY_SIM__ */
    }
    else
    {
        mmi_sat_please_wait_scrn_pre_entry(cmd_info->sim_id, STR_ID_SAT_SIM_REFRESH, 0);
    }
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

#ifdef __SATCC__
#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_launch_browser_process
 * DESCRIPTION
 *  Launch browser command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_launch_browser_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;											//vikrant
    srv_sat_launch_browser_struct *browser = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    browser = (srv_sat_launch_browser_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, browser, MMI_FALSE , mmi_sat_launch_browser_confirm_scrn_entry);	//vikrant
    //group_data->func_p = (FuncPtr)mmi_sat_launch_browser_confirm_scrn_entry;				//vikrant
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_launch_browser_confirm_scrn_entry
 * DESCRIPTION
 *  Launch browser command confirm screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_launch_browser_confirm_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_launch_browser_struct *browser = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    browser = (srv_sat_launch_browser_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_exit, (FuncPtr)mmi_sat_launch_browser_confirm_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    mmi_sat_set_key_and_pen_handler();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (PU8)browser->alpha_id,
        browser->icon.data,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr(SAT_K_LCRCE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_launch_browser_method
 * DESCRIPTION
 *  Launch browser method function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_launch_browser_method(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_launch_browser_struct *browser = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(gid);
    browser = (srv_sat_launch_browser_struct *)group_data->data_ptr;

    if ((browser->browser_mode == SRV_SAT_LAUNCH_USE_EXISTING ||
        browser->browser_mode == SRV_SAT_LAUNCH_CLOSE_EXISTING_AND_LAUNCH_NEW) &&
        wap_browser_is_open())
    {
        mmi_frm_scrn_close(gid, SCR_ID_SAT_CMD_SCREEN); 
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_launch_browser_response
* DESCRIPTION
*  Launch browser response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_launch_browser_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    switch (res_type)
    {
        case SAT_RES_OK:

#ifndef __SAT_LOWCOST_UI_DISABLE__
#ifdef __SATCC__
#ifdef BROWSER_SUPPORT

            srv_sat_terminal_response_launch_browser_stage1(sim_id);                

#endif /*BROWSER_SUPPORT*/
#endif /* __SATCC__*/
#endif /*__SAT_LOWCOST_UI_DISABLE__*/

            break;

        case SAT_RES_CANCEL:

#ifndef __SAT_LOWCOST_UI_DISABLE__
#ifdef __SATCC__
#ifdef BROWSER_SUPPORT

            srv_sat_terminal_response_launch_browser_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

#endif /*BROWSER_SUPPORT*/
#endif /* __SATCC__*/
#endif /*__SAT_LOWCOST_UI_DISABLE__*/

            ret = MMI_TRUE;
            break;

        case SAT_RES_TERMINATED:

#ifndef __SAT_LOWCOST_UI_DISABLE__
#ifdef __SATCC__
#ifdef BROWSER_SUPPORT

            srv_sat_terminal_response_launch_browser_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

#endif /*BROWSER_SUPPORT*/
#endif /* __SATCC__*/
#endif /*__SAT_LOWCOST_UI_DISABLE__*/

            break;

        default:
            break;
    }

    return ret;
}
#endif /* BROWSER_SUPPORT */ 


#endif /* __SATCC__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_language_notification_process
 * DESCRIPTION
 *  Language notification process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_language_notification_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_language_notification_struct *language = (srv_sat_language_notification_struct *)&cmd_info->cmd_data;
    U8 lang_sel = (U8)GetLanguageIndexByLangCode((CHAR *)language->lang);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    if (!language->is_specified)
    {
        lang_sel = language->lang[0];
    }

    if (lang_sel != 0xFF && lang_sel != gCurrLangIndex)
    {
        mmi_popup_property_struct arg;

        mmi_setting_set_language(lang_sel);

        mmi_popup_property_init(&arg);
        arg.callback = mmi_sat_language_notification_done;
        arg.user_tag = &cmd_info->sim_id;
        mmi_popup_display_ext(STR_ID_SAT_LANGUAGE_CHANGED, MMI_EVENT_SUCCESS, &arg);

        return;
    }

    srv_sat_terminal_response_language_notification(
        cmd_info->sim_id,
        SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_language_notification_done
 * DESCRIPTION
 *  Language notification call  back.
 * PARAMETERS
 *  param      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sat_language_notification_done(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_ALERT_QUIT)
    {
        mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)param;
        if (evt->result == MMI_POPUP_NORMAL_EXIT || evt->result == MMI_POPUP_INTERRUPT_EXIT)
        {
            mmi_sim_enum sim_id = *(mmi_sim_enum *)evt->user_tag;
            srv_sat_terminal_response_language_notification(
                sim_id,
                SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
        }
    }

    return MMI_RET_OK;
}

#endif /* __SAT_LOWCOST_UI_DISABLE__ */


#ifdef __SATCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_open_channel_process
 * DESCRIPTION
 *  Open channel command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_open_channel_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;														//vikrant
    srv_sat_open_channel_struct *open_channel = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    open_channel = (srv_sat_open_channel_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, open_channel, MMI_FALSE , mmi_sat_open_channel_scrn_entry);	//vikrant
    //group_data->func_p = (FuncPtr)mmi_sat_open_channel_scrn_entry;			//vikrant
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_open_channel_confirm_scrn_entry
 * DESCRIPTION
 *  Open channel command confirm screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_open_channel_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_open_channel_struct *open_channel = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
	
	if(group_data)				//vikrant - MAUI_03243564
	{
    open_channel = (srv_sat_open_channel_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, NULL, (FuncPtr)mmi_sat_open_channel_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (PU8)open_channel->alpha_id,
        open_channel->icon.data,
        gui_buffer);

    mmi_sat_set_soft_key_hdlr((mmi_sat_key_enum)(SAT_K_LCRCE | SAT_K_SEND_KEY));
}
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_open_channel_response
* DESCRIPTION
*  Open channel command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_open_channel_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

	mmi_sim_enum sim_id = group_data->sim_id;									//vikrant slim 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res_type)
    {
        case SAT_RES_OK:
            srv_sat_terminal_response_open_channel(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RES_CANCEL:
            srv_sat_terminal_response_open_channel(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RES_TERMINATED:
            srv_sat_terminal_response_open_channel(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            break;

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_close_channel_process
 * DESCRIPTION
 *  Close channel command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_close_channel_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;												//vikrant
    srv_sat_close_channel_struct *close_channel = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    close_channel = (srv_sat_close_channel_struct *)(&cmd_info->cmd_data);

    srv_sat_stop_timer(cmd_info->sim_id, SAT_TIMER_WAIT);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, close_channel, MMI_FALSE , mmi_sat_close_channel_scrn_entry);	//vikrant
    //group_data->func_p = (FuncPtr)mmi_sat_close_channel_scrn_entry;		//vikrant
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_close_channel_scrn_entry
 * DESCRIPTION
 *  Close channel command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_close_channel_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_close_channel_struct *close_channel = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);

	if(group_data)				//vikrant	- MAUI_03243571
	{
    close_channel = (srv_sat_close_channel_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, NULL, (FuncPtr)mmi_sat_close_channel_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        (PU8)close_channel->alpha_id,
        close_channel->icon.data,
        gui_buffer);

    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);
}
}


#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
/*****************************************************************************
* FUNCTION
*  mmi_sat_close_channel_response
* DESCRIPTION
*  Close channel command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_close_channel_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_sim_enum sim_id = group_data->sim_id;								//vikrant slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_close_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

    return MMI_FALSE;
}
#endif /* __SRV_SAT_TR_CLOSE_CHANNEL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_data_process
 * DESCRIPTION
 *  Send data command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_send_data_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;											//vikrant
    srv_sat_send_data_struct *send_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_data  = (srv_sat_send_data_struct *)(&cmd_info->cmd_data);

    srv_sat_stop_timer(cmd_info->sim_id, SAT_TIMER_WAIT);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, send_data, MMI_FALSE , mmi_sat_send_data_scrn_entry);	//vikrant
    //group_data->func_p = (FuncPtr)mmi_sat_send_data_scrn_entry;			//vikrant
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_send_data_scrn_entry
 * DESCRIPTION
 *  Send data command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_send_data_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_send_data_struct *send_data = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);

	if(group_data)				//vikrant -MAUI_03243578
	{
    send_data = (srv_sat_send_data_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, NULL, (FuncPtr)mmi_sat_send_data_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        (PU8)send_data->alpha_id,
        send_data->icon.data,
        gui_buffer);

    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);
}
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_send_data_response
* DESCRIPTION
*  Send data command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_data_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_sim_enum sim_id = group_data->sim_id;									//vikrant slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_send_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_recv_data_process
 * DESCRIPTION
 *  receive data command process.
 * PARAMETERS
 *  group_data      [IN]        group data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_recv_data_process(srv_sat_proactive_sim_struct *cmd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data;										//vikrant
    srv_sat_receive_data_struct *recv_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_data  = (srv_sat_receive_data_struct *)(&cmd_info->cmd_data);

    group_data = mmi_sat_init_group_data(cmd_info->sim_id, cmd_info->cmd_type, recv_data, MMI_FALSE , mmi_sat_recv_data_scrn_entry);	//vikrant
    //group_data->func_p = (FuncPtr)mmi_sat_recv_data_scrn_entry;							//vikrant
    mmi_sat_instant_cmd_show_by_nmgr(mmi_sat_scrn_pre_entry, group_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_recv_data_scrn_entry
 * DESCRIPTION
 *  Receive data command screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_recv_data_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_sat_group_data_struct *group_data = NULL;
    srv_sat_receive_data_struct *recv_data = NULL;
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);
    recv_data = (srv_sat_receive_data_struct *)group_data->data_ptr;
    grp_id = SAT_CONTEXT(group_data->sim_id)->sub_gid;

    if (!mmi_frm_scrn_enter(grp_id, SCR_ID_SAT_CMD_SCREEN, NULL, (FuncPtr)mmi_sat_recv_data_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        (PU8)recv_data->alpha_id,
        recv_data->icon.data,
        gui_buffer);

    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_recv_data_response
* DESCRIPTION
*  Receive data command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_recv_data_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_sim_enum sim_id = group_data->sim_id;									//vikrant slim

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_receive_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

    return MMI_FALSE;
}
#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_hilit_menu_index_hdlr
 * DESCRIPTION
 *  Highlight menu item index handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_hilit_menu_index_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

    group_data->item_index = (U8)index;

    if (group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
    {
        group_data->menu_index = (U8)index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_cmd_hint
 * DESCRIPTION
 *  To get menu item hints(next indication).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
PU8 mmi_sat_get_cmd_hint(srv_sat_cmd_enum cmd_type, srv_sat_cmd_enum for_cmd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cmd_type)
    {
        case SRV_SAT_CMD_SEND_SMS:
            res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_SEND_SMS);
            break;

        case SRV_SAT_CMD_SETUP_CALL:
             res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_SETUP_CALL);
             break;

#ifdef __SATCC__
        case SRV_SAT_CMD_LAUNCH_BROWSER:
            res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_LAUNCH_BROWSER);
            break;

#endif /* __SATCC__ */

        case SRV_SAT_CMD_PROVIDE_LOCAL_INFORMATION:
            if (for_cmd_type == SRV_SAT_CMD_SETUP_MENU)
            {
                res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFORMATION);
            }
            else
            {
                res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFO);
            }
            break;

        default:
            break;
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_input_option_hdlr
 * DESCRIPTION
 *  Input option handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_input_option_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_id;
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

    mmi_frm_group_create_ex(
        SAT_CONTEXT(group_data->sim_id)->sub_gid,
        GRP_ID_SAT_INPUT_OPT,
        mmi_sat_input_option_proc,
        group_data,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);


    menu_id = cui_menu_create(
                    GRP_ID_SAT_INPUT_OPT,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_FROM_RESOURCE,
                    MENU_ID_SAT_INPUT_OPTION,
                    MMI_FALSE,
                    NULL);

    cui_menu_run(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_please_wait_scrn_pre_entry
 * DESCRIPTION
 *  To get wait strig and icon, enter group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_please_wait_scrn_pre_entry(mmi_sim_enum sim_id, U16 string, U16 image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_id;
    mmi_sat_group_data_struct *group_data;										//vikrant
    MMI_ID *gid_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = SAT_CONTEXT(sim_id)->app_gid;
    gid_p = &SAT_CONTEXT(sim_id)->sub_gid;

    if (!mmi_sat_is_in_screen(sim_id))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_PLEASE_WAIT_PRE);

    group_data = mmi_sat_init_group_data(sim_id, SRV_SAT_CMD_NONE, NULL, MMI_TRUE , NULL);		//vikrant
    if (!mmi_sat_enter_app_group(parent_id, sim_id, gid_p, group_data))
    {
        return;
    }

    group_data->wait_string = string;
    group_data->wait_image  = mmi_get_event_based_image(MMI_EVENT_PROGRESS);

    mmi_frm_scrn_first_enter(*gid_p, SCR_ID_SAT_CMD_SCREEN, (FuncPtr)mmi_sat_please_wait_scrn_entry, gid_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_please_wait_scrn_entry
 * DESCRIPTION
 *  Please wait screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_please_wait_scrn_entry(mmi_scrn_essential_struct* scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(scrn_info->group_id);

    if (!mmi_frm_scrn_enter(
                SAT_CONTEXT(group_data->sim_id)->sub_gid,
                SCR_ID_SAT_CMD_SCREEN,
                mmi_sat_please_wait_exit,
                (FuncPtr)mmi_sat_please_wait_scrn_entry,
                MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_PLEASE_WAIT_SCRN);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    ClearHighlightHandler();

#ifdef __MMI_SAT_PLEASE_WAIT_ONLY_TEXT__
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)GetString(group_data->waitString), 0, NULL);
#else /* __MMI_SAT_PLEASE_WAIT_ONLY_TEXT__ */ 

    if (group_data->wait_image == 0)
    {
        ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)GetString(group_data->wait_string), 0, NULL);
    }
    else
    {
        ShowCategory151Screen(
            0,
            0,
            0,
            0,
            0,
            0,
            (PU8)GetString(group_data->wait_string),
            (PU8)GetImage(group_data->wait_image),
            NULL);
    }
#endif /* __MMI_SAT_PLEASE_WAIT_ONLY_TEXT__ */ 

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

#ifdef __SAT_DISABLE_ALARM__
    mmi_sat_disable_alarm();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_please_wait_exit
 * DESCRIPTION
 *  Please wait screen exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_please_wait_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

#ifdef __SAT_DISABLE_ALARM__
    mmi_sat_enable_alarm();
#endif

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_timer_expiry_hdlr
 * DESCRIPTION
 *  SAT Timer expiry handler.
 * PARAMETERS
 *  callback_data       [IN]        callback data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_timer_expiry_hdlr(srv_sat_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_timer_data_struct *user_data = NULL;
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = (mmi_sat_timer_data_struct *)callback_data->user_data;

    if (!callback_data->result)
    {
      // slim starts
		/* if (user_data)
        {
            OslMfree(user_data);
            user_data = NULL;
        }
		*/

		wrapper_for_OslMfree((void**)(&user_data));

		//slim ends

        return;
    }

    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(SAT_CONTEXT(callback_data->sim_id)->sub_gid);

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_TIMER_EXPIRY);

    switch (callback_data->timer_id)
    {
        case SAT_TIMER_WAIT:
        {
        #ifdef __SAT_DISABLE_ALARM__
            mmi_sat_enable_alarm();
        #endif

    #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
            if (mmi_sat_is_in_screen(callback_data->sim_id))
            {
                if (srv_clam_is_close())
                {
                    mmi_idle_display();
                    return;
                }
            }
    #endif /* __MMI_CLAMCLOSE_BACK2IDLE__ */ 

            mmi_frm_group_close(SAT_CONTEXT(callback_data->sim_id)->sub_gid);
            break;
        }

        case  SAT_TIMER_CLEAR_DELAY:
        {
            mmi_sat_me_response_to_cmd(SAT_CONTEXT(callback_data->sim_id)->sub_gid, SAT_RES_DELAY_OK);
            break;
        }

        case SAT_TIMER_POPUP:
        {
            mmi_frm_group_close(SAT_CONTEXT(callback_data->sim_id)->sub_gid);
            break;
        }

        case SAT_TIMER_PLAY_TONE:
        {
            srv_prof_stop_tone(SRV_PROF_TONE_SAT);
            srv_sat_terminal_response_play_tone(
                    callback_data->sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);

            group_data->is_sent = MMI_TRUE;
            if (user_data->is_inform)
            {
                mmi_sat_please_wait_scrn_pre_entry(callback_data->sim_id, STR_GLOBAL_PLEASE_WAIT, 0);
            }
            break;
        }

        case SAT_TIMER_NO_RESPONSE:
        {
            switch (user_data->cmd_type)
            {
                case SRV_SAT_CMD_SELECT_ITEM:
                {
                    srv_sat_terminal_response_select_item(
                            callback_data->sim_id,
                            SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                            0);
                    break;
                }

                case SRV_SAT_CMD_DISPLAY_TEXT:
                {
                    mmi_sat_me_response_to_cmd(SAT_CONTEXT(callback_data->sim_id)->sub_gid, SAT_RES_NO_RESPONSE);
                    break;
                }

                case SRV_SAT_CMD_GET_INKEY:
                {
                    srv_sat_terminal_response_get_inkey(
                            callback_data->sim_id,
                            SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                            MMI_FALSE,
                            NULL);
                    break;
                }

                case SRV_SAT_CMD_GET_INPUT:
                {
                    srv_sat_terminal_response_get_input(
                            callback_data->sim_id,
                            SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                            NULL);
                    break;
                }
                
                case SRV_SAT_CMD_SEND_SS:
                {
                    srv_sat_terminal_response_send_ss_stage2(
                            callback_data->sim_id,
                            SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                            0,
                            NULL);
                    break;
                }

                default:
                    break;
            }

            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CLOSE_GROUP_ID,  mmi_frm_group_get_active_id());
            group_data->is_sent = MMI_TRUE;
            mmi_frm_group_close(SAT_CONTEXT(callback_data->sim_id)->sub_gid);
            break;
        }

        default:
            break;
    }

    //slim starts
	/*
    if (user_data)
    {
        OslMfree(user_data);
        user_data = NULL;
    }
	*/
	wrapper_for_OslMfree((void**)(&user_data));
}


void mmi_sat_set_soft_key_hdlr(mmi_sat_key_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key & SAT_K_SEND_KEY)
    {
        //SetKeyHandler(mmi_sat_response_help_hdlr, KEY_SEND, KEY_EVENT_UP);
		SetKeyUpHandler(mmi_sat_response_help_hdlr, KEY_SEND);
    }

    if (key & SAT_K_LSK)
    {
        SetLeftSoftkeyFunction(mmi_sat_response_ok_hdlr, KEY_EVENT_UP);
    }

    if (key & SAT_K_CSK)
    {
        SetCenterSoftkeyFunction(mmi_sat_response_ok_hdlr, KEY_EVENT_UP);
    }

    if (key & SAT_K_RSK_BACK)
    {
        SetRightSoftkeyFunction(mmi_sat_response_back_hdlr, KEY_EVENT_UP);
    }

    if (key & SAT_K_RSK_CANCEL)
    {
        SetRightSoftkeyFunction(mmi_sat_response_cancel_hdlr, KEY_EVENT_UP);
    }


    if (key & SAT_K_END_KEY)
    {
        mmi_frm_scrn_set_leave_proc(mmi_frm_group_get_active_id(), SCR_ID_SAT_CMD_SCREEN, mmi_sat_scrn_generic_leave_proc);
    }

    if (key & SAT_K_ABORT)
    {
        SetRightSoftkeyFunction(mmi_sat_response_abort_hdlr, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_ok_hdlr
 * DESCRIPTION
 *  Command performed successfully.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_response_ok_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sat_me_response_to_cmd(mmi_frm_group_get_active_id(), SAT_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_input_digit_olny_hdlr
 * DESCRIPTION
 *  Only for get inkey/get input digit only left handler process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sat_response_input_digit_olny_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
    MMI_ID gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_get_active_id();
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(gid);
    if (mmi_sat_input_text_check(group_data))
    {
        mmi_sat_me_response_to_cmd(gid, SAT_RES_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_help_hdlr
 * DESCRIPTION
 *  Help information required by user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_response_help_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sat_me_response_to_cmd(mmi_frm_group_get_active_id(), SAT_RES_HELP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_back_hdlr
 * DESCRIPTION
 *  Backward move.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_response_back_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sat_me_response_to_cmd(mmi_frm_group_get_active_id(), SAT_RES_BACK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_cancel_hdlr
 * DESCRIPTION
 *  Unable to process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_response_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sat_me_response_to_cmd(mmi_frm_group_get_active_id(), SAT_RES_CANCEL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_abort_hdlr
 * DESCRIPTION
 *  Command abort function, Send DTMF.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_response_abort_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sat_me_response_to_cmd(mmi_frm_group_get_active_id(), SAT_RES_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_response_terminated_hdlr
 * DESCRIPTION
 *  Command terminated by user function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_response_terminated_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sat_me_response_to_cmd(mmi_frm_group_get_active_id(), SAT_RES_TERMINATED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_me_response_to_cmd
 * DESCRIPTION
 *  ME response function.
 * PARAMETERS
 *  grp_id          [IN]        group id
 *  res_type      [IN]         response type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_me_response_to_cmd(mmi_id grp_id, mmi_sat_response_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(grp_id);
    ret = MMI_FALSE;

    if (group_data->is_sent)
    {
        /* press softkey for display text of immediate response type*/
        if (group_data->cmd_type != SAT_RES_NO_RESPONSE)
        {
            mmi_frm_group_close(SAT_CONTEXT(group_data->sim_id)->sub_gid);
        }

        return;
    }

    group_data->is_sent = MMI_TRUE;

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_ME_RESPONSE, group_data->sim_id, group_data->cmd_type, res_type);

	//slim starts

	if((*response_to_cmd[group_data->cmd_type -1]))
	{

	ret = (*response_to_cmd[group_data->cmd_type -1])(group_data, res_type);

	}

        // slim ends

  /* switch (group_data->cmd_type)
    {
        case SRV_SAT_CMD_DISPLAY_TEXT:
        {
            ret = mmi_sat_display_text_response(group_data->sim_id, res_type);
            break;
        }

        case SRV_SAT_CMD_GET_INKEY:
        {
            MMI_BOOL is_yes_selected = MMI_FALSE;
            if (group_data->is_yes_no)
            {
                if (!group_data->item_index)
                {
                    is_yes_selected = MMI_TRUE;
                }
            }
            ret = mmi_sat_get_inkey_response(group_data->sim_id, res_type, is_yes_selected, (WCHAR *)group_data->input_buf);
            break;
        }

        case SRV_SAT_CMD_GET_INPUT:
        {
            ret = mmi_sat_get_input_response(group_data->sim_id, res_type, (WCHAR *)group_data->input_buf);
            break;
        }

        case SRV_SAT_CMD_PLAY_TONE:
        {
            ret = mmi_sat_play_tone_response(group_data->sim_id, res_type);  
            break;
        }

        case SRV_SAT_CMD_SETUP_MENU:
        {
            ret = mmi_sat_main_menu_response(group_data->sim_id, res_type);
            break;
        }

        case SRV_SAT_CMD_SELECT_ITEM:
        {
            ret = mmi_sat_sub_menu_response(group_data->sim_id, res_type);
            break;
        }

        case SRV_SAT_CMD_SEND_SMS:
            break;

        case SRV_SAT_CMD_SEND_SS:
            break;

        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
        {
            srv_sat_send_ss_struct *send_ss = (srv_sat_send_ss_struct *)group_data->data_ptr;
            ret = mmi_sat_send_ss_result_response(group_data->sim_id, res_type, send_ss->length, send_ss->additional_info);
            break;
        }

        case SRV_SAT_CMD_SEND_USSD:
            break;

        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
        {
            srv_sat_send_ussd_struct *send_ussd = (srv_sat_send_ussd_struct *)group_data->data_ptr;
            ret = mmi_sat_send_ussd_result_response(group_data->sim_id, res_type, send_ussd->length, send_ussd->additional_info);
            break;
        }

        case SRV_SAT_CMD_SETUP_CALL:
        {
            srv_ucm_result_enum error_code = SRV_UCM_RESULT_OK;
            ret = mmi_sat_setup_call_response(group_data->sim_id, res_type, &error_code);
            if (error_code != SRV_UCM_RESULT_OK)
            {
                mmi_popup_display_ext(srv_ucm_query_error_message(error_code), MMI_EVENT_FAILURE, NULL);
                ret = MMI_TRUE;
            }

            if (res_type != SAT_RES_OK || error_code != SRV_UCM_RESULT_OK)
            {
                if (SAT_CONTEXT(group_data->sim_id)->calling_icon_path)
                {
                    OslMfree(SAT_CONTEXT(group_data->sim_id)->calling_icon_path);
                    SAT_CONTEXT(group_data->sim_id)->calling_icon_path = NULL;
                }

                SAT_CONTEXT(group_data->sim_id)->calling_icon_available = MMI_FALSE;
            }
            break;
        }

        case SRV_SAT_CMD_RUN_AT_COMMAND:
            break;

        case SRV_SAT_CMD_SEND_DTMF:
        {
            ret = mmi_sat_send_dtmf_response(group_data->sim_id, res_type);
            break;
        }

    #ifndef __SAT_LOWCOST_UI_DISABLE__
        case SRV_SAT_CMD_LANGUAGE_NOTIFICATION:
            break;

    #ifdef BROWSER_SUPPORT
        case SRV_SAT_CMD_LAUNCH_BROWSER:
        {
            ret = mmi_sat_launch_browser_response(group_data->sim_id, res_type);
            if (res_type == SAT_RES_OK)
            {
                mmi_sat_launch_browser_method(SAT_CONTEXT(group_data->sim_id)->sub_gid);
            }
            break;
        }*/
   // #endif /* BROWSER_SUPPORT */ 
  /* #endif

    #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
        {
            ret = mmi_sat_open_channel_response(group_data->sim_id, res_type);
            break;
        }

        #ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
        case SRV_SAT_CMD_CLOSE_CHANNEL:
        {
            ret = mmi_sat_close_channel_response(group_data->sim_id, res_type);
            break;
        }
        #endif

        case SRV_SAT_CMD_SEND_DATA:
        {
            ret = mmi_sat_send_data_response(group_data->sim_id, res_type);
            break;
        }

        case SRV_SAT_CMD_RECEIVE_DATA:
        {
            ret = mmi_sat_recv_data_response(group_data->sim_id, res_type);
            break;
        }
    #endif  __SATCE__ 

        default:
            break;
    }

	*/

    if (ret)
    {
        mmi_sat_please_wait_scrn_pre_entry(group_data->sim_id, STR_GLOBAL_PLEASE_WAIT, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_set_key_and_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_set_key_and_pen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id grp_id;
    mmi_id scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&grp_id, &scrn_id);
    mmi_frm_scrn_set_key_proc(grp_id, scrn_id, mmi_sat_key_proc);

#ifdef __MMI_TOUCH_SCREEN__
    //mmi_pen_set_event_handler_callback(mmi_sat_touch_pen_pre_hdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_PRE_TOUCH_EVT_ROUTING, mmi_sat_touch_pen_pre_hdlr, NULL);
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_scrn_generic_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sat_scrn_generic_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *gid_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_GENERIC_LEAVE_PROC);
            gid_p = (MMI_ID *)param->user_data;
            mmi_sat_me_response_to_cmd(*gid_p, SAT_RES_TERMINATED);
            break;
        }

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_scrn_generic_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_scrn_generic_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

    MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_GENERIC_EXIT);

    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_NO_RESPONSE);
    srv_sat_stop_timer(group_data->sim_id, SAT_TIMER_CLEAR_DELAY);

#ifdef __MMI_TOUCH_SCREEN__
    //mmi_pen_set_event_handler_callback(NULL, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_PRE_TOUCH_EVT_ROUTING, mmi_sat_touch_pen_pre_hdlr, NULL);
#endif

    if (group_data->cmd_type == SRV_SAT_CMD_DISPLAY_TEXT && group_data->is_sent == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G3_SAT, MMI_SAT_CLOSE_GROUP_ID, SAT_CONTEXT(group_data->sim_id)->sub_gid);
        mmi_frm_group_close(SAT_CONTEXT(group_data->sim_id)->sub_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_app_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sat_app_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            if (!group_data->is_wait_scrn)
            {
                if (group_data->cmd_type == SRV_SAT_CMD_SETUP_MENU)
                {
                    SAT_CONTEXT(group_data->sim_id)->parent_gid = GRP_ID_INVALID;
                    SAT_CONTEXT(group_data->sim_id)->app_gid = GRP_ID_INVALID;
                }
                else if (!group_data->is_sent)
                {
                #ifdef __SATCE__
                    if (group_data->cmd_type == SRV_SAT_CMD_SEND_DATA ||
                        group_data->cmd_type == SRV_SAT_CMD_RECEIVE_DATA ||
                        group_data->cmd_type == SRV_SAT_CMD_CLOSE_CHANNEL)
                    {
                        SAT_CONTEXT(group_data->sim_id)->sub_gid = GRP_ID_INVALID;
                        mmi_sat_group_data_free(group_data);
                        break;
                    }
                #endif /* __SATCE__ */

                    mmi_sat_me_response_to_cmd(SAT_CONTEXT(group_data->sim_id)->sub_gid, SAT_RES_TERMINATED);
                    srv_sat_free_last_proactive_sim(group_data->sim_id, group_data->cmd_type);
                    SAT_CONTEXT(group_data->sim_id)->sub_gid = GRP_ID_INVALID;
                }
            }

            mmi_sat_group_data_free(group_data);
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_input_option_proc
 * DESCRIPTION
 *  Input option proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sat_input_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            if (mmi_frm_is_in_backward_scenario() && mmi_frm_scrn_get_count(GRP_ID_SAT_INPUT_OPT) == 0)
            {
                mmi_frm_group_close(GRP_ID_SAT_INPUT_OPT);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SAT_INPUT_DONE_OPT)
            {
                group_data = (mmi_sat_group_data_struct *)evt->user_data;
                if (group_data->cmd_type == SRV_SAT_CMD_GET_INPUT)
                {
                    if (mmi_sat_input_text_check(group_data))
                    {
                        mmi_sat_me_response_to_cmd(SAT_CONTEXT(group_data->sim_id)->sub_gid, SAT_RES_OK);
                    }
                }
                else if (group_data->cmd_type == SRV_SAT_CMD_GET_INKEY)
                {
                    if (mmi_sat_input_text_check(group_data))
                    {
                        mmi_sat_me_response_to_cmd(SAT_CONTEXT(group_data->sim_id)->sub_gid, SAT_RES_OK);
                    }
                }
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    if (cui_menu_is_menu_event(evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, GRP_ID_SAT_INPUT_OPT);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_key_proc
 * DESCRIPTION
 *  Restart no response timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sat_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_PRE_KEY)
    {
        group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());
		if(group_data)   //MAUI_03218918
        srv_sat_resume_timer(group_data->sim_id, SAT_TIMER_NO_RESPONSE, MMI_TRUE);
    }

    return MMI_RET_OK;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_touch_pen_pre_hdlr
 * DESCRIPTION
 *  For touch framework to callback to handle pen DOWN/UP/ABORT cases
 * PARAMETERS
 *  U16     [IN]    touch pen events
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_sat_touch_pen_pre_hdlr(U16 touch_event)
void mmi_sat_touch_pen_pre_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;
	//U16 touch_event = (evt->evt_id);
	mmi_multi_touch_event_struct *touch_evt = (mmi_multi_touch_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

	if(touch_evt->touch_data[0].event == MMI_PEN_EVENT_DOWN)
	{
		srv_sat_resume_timer(group_data->sim_id, SAT_TIMER_NO_RESPONSE, MMI_TRUE);
	}

    /*switch (touch_event)
    {
        case MMI_PEN_EVENT_DOWN:
            srv_sat_resume_timer(group_data->sim_id, SAT_TIMER_NO_RESPONSE, MMI_TRUE);
            break;

		// starts

			case MMI_PEN_EVENT_UP:
                        case MMI_PEN_EVENT_ABORT:
            break;
		*/

		// ends

       /* default:
            break;
    }*/
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_calculate_screen_capability
 * DESCRIPTION
 *  Export to SMU to calculate screen capability for profile download
 * PARAMETERS
 *  max_char_down       [OUT]
 *  max_char_accross    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_calculate_screen_capability(kal_uint8 *max_char_down, kal_uint8 *max_char_accross)
{
    /* approximate calculation */
#ifdef __MMI_FTE_SUPPORT__
    *max_char_down = (kal_uint8)((MMI_POP_UP_DIALOG_HEIGHT / 2) / MMI_FE_FONT_SIZE_MEDIUM); /* Height divide by 2 only to the height of icon */
    *max_char_accross = (kal_uint8)((UI_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X) / MMI_FE_FONT_SIZE_MEDIUM);

#else
    *max_char_down = (kal_uint8)((MMI_POP_UP_DIALOG_HEIGHT / 2) / MMI_FE_FONT_SIZE_MEDIUM);
    *max_char_accross = (kal_uint8)((MMI_POP_UP_DIALOG_WIDTH - 2*UI_POPUP_BORDER_SIZE) / MMI_FE_FONT_SIZE_MEDIUM);

#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_is_calling_icon_availabe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sat_is_calling_icon_availabe(mmi_sim_enum sim_id)
{
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    return SAT_CONTEXT(sim_id)->calling_icon_available;

#else
    return MMI_FALSE;

#endif /* __SAT_DISABLE_ICON_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_calling_icon_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]
 * RETURNS
 *  CHAR *
 *****************************************************************************/
CHAR *mmi_sat_get_calling_icon_path(mmi_sim_enum sim_id)
{
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (mmi_sat_is_calling_icon_availabe(sim_id))
    {
        return SAT_CONTEXT(sim_id)->calling_icon_path;
    }
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */

    return NULL;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    CHAR path_ascii[MMI_SAT_ICON_PATH_LENGTH];
    CHAR path_usc2[MMI_SAT_ICON_PATH_LENGTH];
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = SRV_FMGR_PUBLIC_DRV;
    if (drive > 0)
    {
        sprintf(path_ascii, "%c:\\sat", (CHAR)drive);
        mmi_asc_to_ucs2(path_usc2, path_ascii);

        fh = FS_Open((U16*)path_usc2, FS_OPEN_DIR | FS_READ_ONLY);
        if (fh > 0)
        {
            FS_Close(fh);
        }
        else
        {
            if (FS_CreateDir((U16*)path_usc2) == FS_NO_ERROR)
            {
                FS_SetAttributes((U16*)path_usc2, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_create_calling_icon_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
CHAR *mmi_sat_create_calling_icon_path(mmi_sim_enum sim_id, CHAR **save_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    CHAR path_ascii[MMI_SAT_ICON_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = SRV_FMGR_PUBLIC_DRV;
    if (drive > 0)
    {
        *save_path = (CHAR *)OslMalloc(MMI_SAT_ICON_PATH_LENGTH * ENCODING_LENGTH);
        sprintf(path_ascii, "%c:\\sat\\%d.pbm", (CHAR)drive, (U32)sim_id);
        mmi_asc_to_ucs2(*save_path, path_ascii);

        return *save_path;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_save_calling_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sat_save_calling_icon(mmi_sim_enum sim_id, PU8 icon_data, CHAR *save_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *scr_asm_ptr = NULL;
    GDI_HANDLE temp_layer;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (icon_data == NULL)
    {
        return MMI_FALSE;
    }

    scr_asm_ptr = applib_mem_screen_alloc_framebuffer((*(icon_data + 8)) * (*(icon_data + 12)) * 2);

    memcpy(scr_asm_ptr, (icon_data + 8 + 13), (*(icon_data + 8)) * (*(icon_data + 12)) * 2);

    ret = gdi_layer_create_cf_using_outside_memory(
                  GDI_COLOR_FORMAT_16,
                  0,
                  0,
                  *(icon_data + 8),
                  *(icon_data + 12),
                  &temp_layer,
                  (U8*)scr_asm_ptr,
                  (*(icon_data + 8)) * (*(icon_data + 12)) * 2);

    MMI_ASSERT(ret == GDI_SUCCEED);

    ret = gdi_layer_save_bmp_file(temp_layer, save_path);
    gdi_layer_free(temp_layer);
    applib_mem_screen_free(scr_asm_ptr);

    if (ret != GDI_SUCCEED)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


#ifdef __SAT_DISABLE_ALARM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_disable_alarm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_disable_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());
    if (!group_data->alm_enable_flag)
    {
        group_data->alm_enable_flag = 1;
        AlmDisableExpiryHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_enable_alarm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sat_enable_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_group_data_struct *group_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_sat_group_data_struct *)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());
    if (group_data->alm_enable_flag)
    {
        group_data->alm_enable_flag = 0;
        // AlmEnableExpiryHandler();					//MAUI_03245579
		srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_TRUE);			//MAUI_03245579
    }
}
#endif /* __SAT_DISABLE_ALARM__ */


#ifdef __MMI_NCENTER_SUPPORT__
mmi_ret mmi_sat_mode_switch_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *mode_status = (srv_mode_switch_notify_struct*)evt;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY == evt->evt_id)
    {
        if (SRV_MODE_SWITCH_ON == mode_status->select_flight_mode)
        {
            for (i = 0; i < MMI_SIM_TOTAL; i ++)
            {
                mmi_sat_delete_app((mmi_sim_enum)(1 << i));
            }
        }
    }

    return MMI_RET_OK;
}
#endif /* __MMI_NCENTER_SUPPORT__ */
