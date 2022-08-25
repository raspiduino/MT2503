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
 * WAPProfileMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is main source file for UPP profile module.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMIDataType.h"
#include "GlobalResDef.h"




#include "DataAccountGProt.h"
#include "DataAccountCUIGprot.h"


#include "Wap_ps_struct.h"
#include "custom_nvram_editor_data_item.h"
#include "Conversions.h"

#include "CommonScreens.h"


#include "DtcntSrvGprot.h"

#include "Custom_data_account.h"
#include "dtcntsrviprot.h"


#ifdef WAP_SUPPORT

#include "WAPProfSrvConfig.h"
#include "WAPProfileSrvType.h"
#ifdef PROV_SUPPORT
#include "WAPProvisioningSrvType.h"        /* prov action enum. */
#include "WAPProvisioningSrvProt.h" 
#endif
#include "WAPProfileProt.h"
#include "WAPProfileSrvProt.h"
#include "WAPProfileSrvGprot.h"
#include "WAPProfResDef.h"
#include "mmi_rp_app_mmi_wap_prof_def.h"

//------------------------------ suggest Add ------------------------------

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "kal_public_api.h"
#include "cbm_api.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "cbm_consts.h"
#include "string.h"
#include "stack_config.h"
#include "mmi_frm_scenario_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "mmi_frm_mem_gprot.h"
//#include "app_buff_alloc.h"
#include "mmi_frm_history_gprot.h"
//------------------------------ usage ------------------------------

mmi_id  mmi_wap_prof_dtcnt_cui_id =  GRP_ID_INVALID;
srv_wap_prof_sim_id_enum cui_sim_id;
srv_wap_prof_app_id_enum cui_app_id;

/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_app__init
* DESCRIPTION
*  This is the WAP PROF Initialization API. Called at bootup.
* PARAMETERS
*  void
* RETURNS
*  mmi_ret
*****************************************************************************/
mmi_ret mmi_wap_prof_app_init(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	cbm_app_info_struct info;

	U8 i,cbm_app_id;

	kal_uint16 app_icon_id[] = 
    {
        IMG_GLOBAL_WEB_BROWSER_CSK,
#if (MMI_MAX_SIM_NUM>=2)	
        IMG_GLOBAL_COMMON_CSK,
#endif
#if (MMI_MAX_SIM_NUM>=3)
        IMG_GLOBAL_MARK_CSK,
#endif
#if (MMI_MAX_SIM_NUM>=4)
        IMG_GLOBAL_NEXT_CSK
#endif
    };

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_INIT_ENTER);

	/***** initialization for Browser *******/

	info.app_str_id = STR_ID_WAP_PROF_CBM_BROWSER;
	info.app_icon_id = IMG_GLOBAL_WEB_BROWSER_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);

#ifdef WAP2
	info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP;
#else
	info.app_type = DTCNT_APPTYPE_BRW_WAP;
#endif 

	for(i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        info.app_icon_id = app_icon_id[i];

	cbm_register_app_id_with_app_info(
		&info,
		&cbm_app_id);
        srv_wap_prof_set_cbm_app((srv_wap_prof_sim_id_enum)i , SRV_WAP_PROF_APPID_BRW ,cbm_app_id);
    }

#if defined(MMS_SUPPORT)
	info.app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
	info.app_type = DTCNT_APPTYPE_MMS;

	for(i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        info.app_icon_id = app_icon_id[i];

	cbm_register_app_id_with_app_info(
		&info,
		&cbm_app_id);
        srv_wap_prof_set_cbm_app((srv_wap_prof_sim_id_enum)i , SRV_WAP_PROF_APPID_MMS ,cbm_app_id);
    }
#endif

	srv_wap_prof_process_init_event();
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_app_activate_profile
* DESCRIPTION
*  Activates a profile. It is a Non-Blocking API as primitive needs to be sent to WAP.
*  if other modules need not be informed then pass MMI_FALSE as 2nd parm.
* PARAMETERS
*  index                       [IN]        
*  b_inform_other_module       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_wap_prof_app_activate_profile(U32 index, MMI_BOOL b_inform_other_module, srv_wap_prof_sim_id_enum sim_info, srv_wap_prof_app_id_enum app_info )
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//MMI_BOOL is_subs_dtcnt;
	srv_wap_prof_sim_id_enum sim_id = sim_info;
	srv_wap_prof_app_id_enum app_id = app_info;



	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVATE_PROFILE, index);

	if ((app_id >= SRV_WAP_PROF_APPID_END) || (sim_id >= SRV_WAP_PROF_SIMID_END))
	{
		ASSERT(app_id < SRV_WAP_PROF_APPID_END);
		ASSERT(sim_id < SRV_WAP_PROF_SIMID_END);
		return;
	}

	/* Update active profile index. Dont commit to NVRAM. */
	/* Commit to NVRAM if not informing other modules. */
	/* index has to be from 0-9 only, and 10-12 for SIM profiles. */
	//srv_wap_prof_set_active_profile_index(sim_id, app_id, index, (!b_inform_other_module));

	if (MMI_TRUE == b_inform_other_module)
	{
		srv_wap_prof_set_active_profile_index(sim_id, app_id, index, MMI_FALSE);
		srv_wap_prof_set_module_status();
		/* Call other application API/ Primitive to change active profile. */
		srv_wap_prof_active_profile_changed(sim_id, app_id);
		/*
		* Do not do anything after sending active profile changed req as it is Non Blocking. 
		* * anythign else should be done in srv_wap_prof_active_profile_change_confirmation_callback(..)
		*/
	}
	else
		srv_wap_prof_set_active_profile_index(sim_id, app_id, index, MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_entry_dtcnt_cui
* DESCRIPTION
*  API for entering the data account cui.
* PARAMETERS
*  void                    [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_wap_prof_app_entry_dtcnt_cui(U8 cbm_app_id, mmi_id parent_id, U16 icon_id, U16 app_menu_id) 
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	U8 i;
	mmi_dtcnt_acct_valid_type_enum dtcnt_validity_status;
	U32 sim_account_id = 0;

	cui_dtcnt_select_run_struct para;

	U8 primary_dtcnt_id = (U8) -1;
	//U8 secondary_dtcnt_id = (U8) -1;
	cbm_account_info_struct data_account_info;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 

	memset(&para, 0, sizeof(cui_dtcnt_select_run_struct));
	memset(&data_account_info, 0, sizeof(cbm_account_info_struct));

	for(i=0;i<MMI_MAX_SIM_NUM;i++)
	{
		sim_account_id = srv_wap_prof_get_active_dtcnt_index(i,cui_app_id);
		dtcnt_validity_status = mmi_dtcnt_acct_is_valid(sim_account_id);
		MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ENTRY_DTCNT_CUI, dtcnt_validity_status);
		if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE)
	{
			sim_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)i, cbm_app_id, KAL_FALSE);  
	}
		cbm_decode_data_account_id_ext(sim_account_id, &data_account_info);

	primary_dtcnt_id = data_account_info.account[0].account_id;
	//secondary_dtcnt_id = data_account_info.account[1].account_id;

	if(primary_dtcnt_id == CBM_DEFAULT_ACCT_ID)
			srv_dtcnt_get_auto_acc_id(sim_account_id, &para.sim_account_id[i]);
	else 
			para.sim_account_id[i] = sim_account_id;
	}

	para.bearers = srv_wap_prof_get_data_account_list_bearer_scope(cui_app_id);
	para.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
	para.app_id = cbm_app_id;

	para.icon_id = icon_id;
	para.str_id = STR_GLOBAL_DATA_ACCOUNT;
	para.AppMenuID = app_menu_id;

	para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
	para.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
	para.option = (cui_dtcnt_select_option_enum) (CUI_DTCNT_SELECT_DEFAULT | 
		CUI_DTCNT_SELECT_BEARER_SWITCH |
		CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH |
		CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT);

	if (cui_app_id == SRV_WAP_PROF_APPID_MMS)
	{
		para.option |= CUI_DTCNT_SELECT_SIM_PROFILE;
	}

	MMI_PRINT(
		SRV_WAP_PROF_MOD_INET_APP,
		SRV_WAP_PROF_TRC_GRP9,
		(S8*) "[WAP_PROF] Entry CUI parameters. bearer = %d, appid = %d, icon_id = %d, account_id = %d, select_option = %d, sim_selection = %d",
		para.bearers,
		para.app_id,
		para.icon_id,
		para.account_id,
		para.option,
		para.sim_selection);

	mmi_frm_group_create_ex(parent_id, (MMI_ID) MMI_WAP_PROF_DTCNT_CUI_GRP_ID, mmi_wap_prof_app_dtcnt_cui_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_wap_prof_dtcnt_cui_id = cui_dtcnt_select_create((MMI_ID) MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
	cui_dtcnt_select_set_param(mmi_wap_prof_dtcnt_cui_id, &para);
	cui_dtcnt_select_run(mmi_wap_prof_dtcnt_cui_id);

}


/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_dtcnt_cui_proc
* DESCRIPTION
*  Proc function for Data account CUI.
* PARAMETERS
*  mmi_event_struct*                    [IN]        
* RETURNS
*  mmi_ret
*****************************************************************************/
mmi_ret mmi_wap_prof_app_dtcnt_cui_proc(mmi_event_struct* evt)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	cbm_account_info_struct data_account_info;
	U32 get_account_id = 0;
	U8 primary_dtcnt_id = (U8) -1;
	U8 secondary_dtcnt_id = (U8) -1;
	cui_dtcnt_sim_enum sim;
	U32 sim_account_id;

	cui_dtcnt_select_event_any_sim_selected_struct *event =  (cui_dtcnt_select_event_any_sim_selected_struct *)evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
	case EVT_ID_GROUP_DEINIT:
		mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;  
		break;

	case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
		
		/* If user selected an account and press OK, send this event to APP’s proc, APP need to save the account ID and close the CUI */
		sim = event->selectSim;

		sim_account_id = (U32)event->accountId;
		cbm_decode_data_account_id_ext(sim_account_id, &data_account_info);
			primary_dtcnt_id = data_account_info.account[0].account_id;
			secondary_dtcnt_id = data_account_info.account[1].account_id;
		cui_sim_id = (srv_wap_prof_sim_id_enum)sim;
			get_account_id = srv_wap_prof_encode_dtcnt(primary_dtcnt_id, secondary_dtcnt_id, cui_sim_id, cui_app_id);

		if(get_account_id != srv_wap_prof_get_active_dtcnt_index(cui_sim_id, cui_app_id) )
		{
			cbm_decode_data_account_id_ext(get_account_id, &data_account_info);
			primary_dtcnt_id = data_account_info.account[0].account_id;
			secondary_dtcnt_id = (U8) - 1;
			if (data_account_info.acct_num > 1)
			{
				secondary_dtcnt_id = data_account_info.account[1].account_id;
			}
			mmi_wap_prof_app_activate_profile(get_account_id, MMI_TRUE, cui_sim_id, cui_app_id);
		}
		else if(get_account_id == srv_wap_prof_get_active_dtcnt_index(cui_sim_id, cui_app_id) )
		{    
			if(SRV_WAP_PROF_AXN_CFG_DTCNT == srv_wap_prof_get_action())
				mmi_wap_prof_app_activate_profile(get_account_id, MMI_TRUE,cui_sim_id, cui_app_id);
		}
		break;

		/* If user press cancel, send this event to APP’s proc, APP can just close the CUI */
	case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
	case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
		/* If CUI’s part screen closed abnormally not by user, send this event to APP’s proc, APP can just  close the CUI*/
	case CUI_DTCNT_SELECT_EVENT_CLOSE:
		cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
		mmi_frm_group_close((MMI_ID)MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
		mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;
		/* If APP fill wrong parameter to run CUI it will send this event, no need to close CUI */   
	case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
		break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
* vapp_wap_prof_app_entry_cui_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
void mmi_wap_prof_entry_dtcnt_cui_hdlr(void)
{
	return ;
}


/*****************************************************************************
* FUNCTION
* mmi_wap_prof_app_entry_cui_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
S32 mmi_wap_prof_app_entry_cui_hdlr(mmi_event_struct* evt)   
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	srv_wap_prof_entry_dtcnt_cui_struct *event;
	U8 cbm_app_id;
	mmi_id parent_id;
	U16 icon_id;
	U16 app_menu_id;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	event = (srv_wap_prof_entry_dtcnt_cui_struct*)evt;
	cui_sim_id = event->sim_id;
	cui_app_id = event->app_id;
	cbm_app_id = event->cbm_app_id;
	parent_id = event->parent_id;
	icon_id = event->icon_id;
	app_menu_id = event->app_menu_id;
	if( mmi_dtcnt_ready_check(mmi_wap_prof_entry_dtcnt_cui_hdlr, MMI_FALSE) )
	{
		mmi_wap_prof_app_entry_dtcnt_cui(cbm_app_id, parent_id, icon_id, app_menu_id);
	}

	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
* vapp_wap_prof_app_entry_cui_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
#ifdef PROV_SUPPORT
void mmi_wap_prof_app_dtcnt_ready_check_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prov_dtcnt_ready_check_evt_struct *event;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	event = (srv_wap_prov_dtcnt_ready_check_evt_struct *)evt;
	if(mmi_dtcnt_ready_check(event->callback, event->scrn_lock))
	{
		srv_wap_prof_prov_dtcnt_ready_callback();
	}
}
#endif

/*****************************************************************************
* FUNCTION
* mmi_wap_prof_app_activate_profile_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    evt :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
S32 mmi_wap_prof_app_activate_profile_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_sim_id_enum sim_id;
	srv_wap_prof_app_id_enum app_id;
	MMI_BOOL inform_others;
	U32 index;
	srv_wap_prof_activate_profile_struct *event;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	event = (srv_wap_prof_activate_profile_struct*)evt;

	sim_id = event->sim_info;
	app_id = event->app_info;
	inform_others = event->inform_others;
	index = event->index;

	mmi_wap_prof_app_activate_profile(index,inform_others, sim_id, app_id);		

	return MMI_RET_OK;

}

#ifndef __SRV_UPP_SLIM__
/*****************************************************************************
* FUNCTION
* mmi_wap_prof_app_close_please_wait_screen
* DESCRIPTION
*  function to handle the service callback for closing the please wait screen shown through DA CUI.
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/

S32 mmi_wap_prof_app_close_please_wait_screen(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_profile_source_enum profile_content_src;
	//srv_wap_prof_action_enum action;
	MMI_BOOL end_key_pressed;
	srv_wap_prof_close_scr_struct *event;
	event=(srv_wap_prof_close_scr_struct*)param;
	profile_content_src = event->profile_content_src;
	//action = event->action;
	end_key_pressed = event->end_key_pressed;

	if (SRV_WAP_PROF_PROFILE_SRC_USER == profile_content_src || SRV_WAP_PROF_PROFILE_SRC_DTCNT_DELETED == profile_content_src)
	{

		if (MMI_FALSE == end_key_pressed)
		{

			mmi_frm_scrn_close(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT);

		}
	}	
	return MMI_RET_OK;
}
#endif
/*****************************************************************************
* FUNCTION
* mmi_wap_prof_app_show_popup_hdlr
* DESCRIPTION
*  function to handle the service callback for displaying the popup.
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/

S32 mmi_wap_prof_app_show_popup_hdlr(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_display_popup_struct *event;
	U16 action = 0; 
	srv_wap_prof_result_enum result; 
	MMI_BOOL use_action_as_string_id; 
	FuncPtr popup_end_callback;
	FuncPtr popup_exit_callback;
	event = (srv_wap_prof_display_popup_struct *)param;
	// action = event->action;
	result = event->result;
	use_action_as_string_id = event->use_action_as_string_id;
	popup_end_callback = event->popup_end_callback;
	popup_exit_callback = event->popup_exit_callback;
	switch(event->action)
	{
	case SRV_WAP_PROF_GLOBAL_NOT_AVAILABLE:
		action = STR_GLOBAL_NOT_AVAILABLE ;
		break;
#if 0
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
	default:
		action = STR_GLOBAL_ERROR;
		break;
	}

	mmi_wap_prof_app_ui_display_popup(action, result, use_action_as_string_id, popup_end_callback, popup_exit_callback);    /* Global string usage */
	return MMI_RET_OK;
}



/*****************************************************************************
* FUNCTION
* mmi_wap_prof_app_is_dtcnt_valid_hdlr
* DESCRIPTION
*  function to handle the service callback for data acccount validity status.
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
mmi_ret mmi_wap_prof_app_is_dtcnt_valid_hdlr(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_check_dtcnt_valid_struct *event;
	
	srv_wap_prof_sim_id_enum sim_id;
	srv_wap_prof_app_id_enum app_id;
	U8 profile_id;
	
	mmi_dtcnt_acct_valid_type_enum  dtcnt_validity_status;
	event = (srv_wap_prof_check_dtcnt_valid_struct*)param;

	sim_id = event->sim_id;
	app_id = event->app_id;
	profile_id = event->profile_id;
        event->result = KAL_TRUE;

#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)  
	if(sim_id == SRV_WAP_PROF_SIMID_WLAN )
	{ 
		event->result = KAL_TRUE;  
	}
#endif

	if(profile_id != 0)
	{
		dtcnt_validity_status = mmi_dtcnt_acct_is_valid( srv_wap_prof_get_active_dtcnt_index(sim_id, app_id) );

		if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_SECOND || dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE) 
		{   
			event->result = KAL_FALSE;
		}
		MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_IS_DTCNT_VALID, sim_id, app_id, profile_id, event->result);
	}
	return MMI_RET_OK;
}


/* MAUI_01508716 starts */
/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_app_close_cui
* DESCRIPTION
*  close all the profile operations abruptly.
* PARAMETERS
*  app_id
* RETURNS
*  void
*****************************************************************************/
void mmi_wap_prof_app_close_cui(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifndef __SRV_UPP_SLIM__
	mmi_frm_scrn_close(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT);
#endif
	if( mmi_wap_prof_dtcnt_cui_id != GRP_ID_INVALID )
	{
		cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
		mmi_frm_group_close((MMI_ID) MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
		mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;
	}
}

/* MAUI_01730813 starts */
/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_app_is_re_entry_allowed
* DESCRIPTION
*  This API checks if profile re-entry scenario is allowed. If yes, it de-inits previous instance.
* PARAMETERS
*  void
* RETURNS
* MMI_BOOL
*****************************************************************************/
mmi_ret mmi_wap_prof_app_is_re_entry_allowed(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_module_status_enum module_status;
	srv_wap_prof_re_entry_allowed_struct *event;
		
	//srv_wap_prof_sim_id_enum sim_id;
	srv_wap_prof_app_id_enum app_id;
	
	event = (srv_wap_prof_re_entry_allowed_struct *)param;

	//sim_id = event->sim_id;
	app_id = event->app_id;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	srv_wap_prof_get_module_status(&module_status);
	MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_REENTRY_CHECK, module_status);
#ifdef PROV_SUPPORT
	if((mmi_frm_scrn_is_present(MMI_WAP_PROV_CCA_GRP_ID, SCR_ID_WAP_PROF_PROV_DISPLAY_INFO, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
		||(SRV_WAP_PROF_WAITING == module_status))
#else
	if(SRV_WAP_PROF_WAITING == module_status)
#endif
	{
		/* 
		* Re-entry not allowed in case if provisioning is going on or profile is waiting, which will be ready after sometime.
		* If does not become ready, then it is a bug. Display info screen is deleted by UM if ProvBox is ON, hence this check
		* will work only when Provisioning inbox is turned OFF.
		*/
        event->result = MMI_FALSE;
		return MMI_RET_OK;
	}
#ifndef __SRV_UPP_SLIM__
	else if ( mmi_wap_prof_dtcnt_cui_id != GRP_ID_INVALID ) //10ADA Checks if DA screen is present
		/* ((IsScreenPresent(SCR_ID_WAP_PROF_PROFILE_LIST)) ||
		(IsScreenPresent(SCR_ID_WAP_PROF_PROFILE_DETAILS)))*/
	{

		srv_wap_prof_kill_profile(app_id);
	}
#endif

    event->result = MMI_TRUE;
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_register_cbm_app_id
* DESCRIPTION
*  This API is used to register app id with cbm dynamically.
* PARAMETERS
*  MMI_BOOL id
*  srv_wap_prof_sim_id_enum sim_id
*  srv_wap_prof_app_id_enum app_id
* RETURNS
* U8
*****************************************************************************/

U8 mmi_wap_prof_register_cbm_app_id(MMI_BOOL id, srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  U8 value;
	  U32 account_id,temp_account_id;
	  cbm_app_info_struct info;
	  U8 cbm_app_id;

	kal_uint16 app_icon_id[] = 
    {
            IMG_GLOBAL_WEB_BROWSER_CSK,
		#if (MMI_MAX_SIM_NUM>=2)	
            IMG_GLOBAL_COMMON_CSK,
		#endif
		#if (MMI_MAX_SIM_NUM >= 3)
			IMG_GLOBAL_MARK_CSK,
		#endif
		#if (MMI_MAX_SIM_NUM >= 4)
			IMG_GLOBAL_NEXT_CSK
		#endif
    };
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   	if(app_id == SRV_WAP_PROF_APPID_BRW)
	{
			if(id == MMI_TRUE)
			{
					#ifdef WAP2
						info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_SKIP_WIFI;
					#else
						info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_SKIP_WIFI;
					#endif 
			}
			else
			{
					#ifdef WAP2
						info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP;
					#else
						info.app_type = DTCNT_APPTYPE_BRW_WAP;
					#endif 
			}
			info.app_str_id = STR_ID_WAP_PROF_CBM_BROWSER;
	}
		

#if defined(MMS_SUPPORT)
	else
	{
			if(id == MMI_TRUE)
					info.app_type = DTCNT_APPTYPE_MMS | DTCNT_APPTYPE_SKIP_WIFI;
			else
					info.app_type = DTCNT_APPTYPE_MMS;

			info.app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
	}
#endif
		
    info.app_icon_id = app_icon_id[sim_id];
    cbm_app_id = srv_wap_prof_get_cbm_app_id(app_id, sim_id);
   
    cbm_deregister_app_id(cbm_app_id);
	value = cbm_register_app_id_with_app_info(
		&info,
			&cbm_app_id);

   account_id  = srv_wap_prof_get_active_dtcnt_index(app_id,sim_id);
   temp_account_id = cbm_set_app_id(account_id, cbm_app_id);
   srv_wap_prof_set_active_profile_index(sim_id, app_id, temp_account_id, MMI_TRUE);
   srv_wap_prof_set_cbm_app(sim_id, app_id,cbm_app_id);

   return value;
}
#endif /* WAP_SUPPORT */ 
