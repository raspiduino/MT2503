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
 *   MSpaceLisScreen.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   M Space Src
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_features.h" 
#ifdef __MMI_MRE_MSPACE__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "MMIDataType.h"
#include "MenuCuiGprot.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "MMI_mre_trc.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "stdio.h"
#include "gui.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
	
#include "vmopt.h"
#include "MRESrvGProt.h"
#include "MREAppMgrSrvGprot.h"
#include "Conversions.h"
	
#include "vmio.h"
#include "vmcert_sdk.h"
#include "vmgettag_sdk.h"
#include "app_str.h"
#include "GlobalConstants.h"
	
#include "MASSrvGprot.h"

#include "MSpaceDef.h"	
#include "MSpaceGprot.h"
#include "MSpaceMainScreen.h"
#include "MSpaceAppScreen.h"
	
#include "mmi_rp_app_mspace_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_mre_def.h"
#include "liblist.h"


/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
extern mmi_mspace_ms_struct g_mspace_cntx;


#if !(defined(__MMI_DA_RESUME__) && defined(__MMI_DOWNLOAD_AGENT__))
VMBOOL g_mspace_as_no_dla = 1;
#elif (!defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__))
VMBOOL g_mspace_as_no_dla = 1;
#else
VMBOOL g_mspace_as_no_dla = 0;
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
void mmi_mspace_as_lis_update(void);
static void mmi_mspace_as_data_download_handler(S32 hdl, void * para);
void mmi_mspace_as_update(void);


/***************************************************************************** 
* Extern Function
*****************************************************************************/


void mmi_mspace_as_waiting_scrn_rsk_cancel_hdlr(void)
{
	S32 ret;
	MMI_ID group_id, scrn_id;

	if (g_mspace_cntx.cur_as_lis_hdl > 0)
	{
		ret = srv_as_data_cancel(g_mspace_cntx.cur_as_lis_hdl);	
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_AWSR_CANCEL_S, g_mspace_cntx.cur_as_lis_hdl, ret);
		g_mspace_cntx.cur_as_lis_hdl = 0;
	}

	if (g_mspace_cntx.cur_as_app_hdl > 0)
	{
		ret = srv_as_data_cancel(g_mspace_cntx.cur_as_app_hdl);	
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_AWSR_CANCEL_S, g_mspace_cntx.cur_as_app_hdl, ret);
		g_mspace_cntx.cur_as_app_hdl = 0;
	}

	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
	if (scrn_id == SCR_ID_MSPACE_WAITING)
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);
	}
}


static mmi_ret mmi_mspace_as_waiting_scrn_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct*)evt;
	U16 keyCode = key_evt->key_code;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (evt->evt_id == EVT_ID_PRE_KEY)
	{
		if (keyCode == KEY_END || keyCode == KEY_HOME)
		{
			if (g_mspace_cntx.cur_as_status == E_MSPACE_AS_STARTING)
				return MMI_RET_KEY_HANDLED;
			else
				return MMI_RET_OK;
		}
	}
	
	return MMI_RET_OK;
}


void mmi_mspace_as_enter_waiting_scrn(void)
{
	S32 ret;
	
    ret = mmi_frm_scrn_enter(
            GRP_ID_MSPACE,
            SCR_ID_MSPACE_WAITING,
            NULL,
            mmi_mspace_as_enter_waiting_scrn,
            0);

    if (ret == MMI_FALSE)
    {
        return;
    }

	mmi_frm_scrn_set_key_proc(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, mmi_mspace_as_waiting_scrn_proc);


	ShowCategory163Screen(NULL, 
					NULL, 
					(WCHAR *) GetString(STR_GLOBAL_CANCEL),
					(PU8)GetImage(IMG_GLOBAL_BACK),
					(WCHAR *) GetString(STR_ID_MSPACE_WAITING),
					IMG_GLOBAL_PROGRESS,
					NULL);

	SetRightSoftkeyFunction(mmi_mspace_as_waiting_scrn_rsk_cancel_hdlr, KEY_EVENT_UP);

}

void mmi_mspace_as_display_waiting(void)
{
	mmi_mspace_as_enter_waiting_scrn();
}


void mmi_mspace_as_downloading_scrn_rsk_cancel_hdlr(void)
{
	S32 ret;
	MMI_ID group_id, scrn_id;

	if (g_mspace_cntx.cur_as_lis_hdl > 0)
	{
		ret = srv_as_data_cancel(g_mspace_cntx.cur_as_lis_hdl);	
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ADSR_CANCEL_S, g_mspace_cntx.cur_as_lis_hdl, ret);
		g_mspace_cntx.cur_as_lis_hdl = 0;
	}

	if (g_mspace_cntx.cur_as_app_hdl > 0)
	{
		ret = srv_as_data_cancel(g_mspace_cntx.cur_as_app_hdl);	
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_AWSR_CANCEL_S, g_mspace_cntx.cur_as_app_hdl, ret);
		g_mspace_cntx.cur_as_app_hdl = 0;
	}

	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
	if (scrn_id == SCR_ID_MSPACE_DOWNLOADING)
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);
	}	
}

void mmi_mspace_as_enter_downloading_scrn(void)
{
	S32 ret;
	
    ret = mmi_frm_scrn_enter(
            GRP_ID_MSPACE,
            SCR_ID_MSPACE_DOWNLOADING,
            NULL,
            mmi_mspace_as_enter_downloading_scrn,
            0);

    if (ret == MMI_FALSE)
    {
        return;
    }

	ShowCategory163Screen(NULL, 
					NULL, 
					(WCHAR *) GetString(STR_GLOBAL_CANCEL),
					(PU8)GetImage(IMG_GLOBAL_BACK),
					(WCHAR *) GetString(STR_ID_MSPACE_DOWNLOADING),
					IMG_GLOBAL_PROGRESS,
					NULL);

	SetRightSoftkeyFunction(mmi_mspace_as_downloading_scrn_rsk_cancel_hdlr, KEY_EVENT_UP);

}

void mmi_mspace_as_display_downloading(void)
{
	mmi_mspace_as_enter_downloading_scrn();
}


static mmi_ret mmi_mspace_as_display_updating_confirmCb(mmi_alert_result_evt_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	S32 ret;
	S32 hdl = (S32)evt->user_tag;

	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_UPDATING_EVT_S, evt->evt_id, evt->result);
	
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (evt->result)
		{
		  case MMI_ALERT_CNFM_1:
			break;
		  case MMI_ALERT_CNFM_2:
			break;
		  case MMI_ALERT_CNFM_3:	// right softkey
			ret = srv_as_data_cancel(hdl);	
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ADUC_CANCEL_S, hdl, ret);
			break;
		  case MMI_ALERT_NORMAL_EXIT:
			g_mspace_cntx.confirm_gid = 0;
			break;
		  default:
			break; 
		}
	}
	return MMI_RET_OK;
}


void mmi_mspace_as_display_updating(S32 hdl)
{
	mmi_confirm_property_struct arg;
	
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)(get_string(0));
	arg.softkey[2].str = (WCHAR *)(get_string(STR_GLOBAL_CANCEL));
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.callback = (mmi_proc_func)mmi_mspace_as_display_updating_confirmCb;
	arg.user_tag = (void*)hdl;	
	g_mspace_cntx.confirm_gid = mmi_confirm_display((WCHAR *)((U16*)get_string(STR_ID_MSPACE_UPDATING)), MMI_EVENT_PROGRESS, &arg);
}

static mmi_ret mmi_mspace_as_display_connect_server_failed_confirmCb(mmi_alert_result_evt_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_CONNECT_FAIL_EVT_S, evt->evt_id, evt->result);
	
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (evt->result)
		{
		  case MMI_ALERT_CNFM_1:	// retry
			mmi_mspace_as_update();
			break;
		  case MMI_ALERT_CNFM_2:
			break;
		  case MMI_ALERT_CNFM_3:	// back
			break;	
		  case MMI_ALERT_NORMAL_EXIT:
			g_mspace_cntx.confirm_gid = 0;
		  default:
			break; 
		}
	}
	return MMI_RET_OK;
}


void mmi_mspace_display_connect_server_failed(void)
{
	mmi_confirm_property_struct arg;
	
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)(get_string(STR_ID_MSPACE_RETRY));
	arg.softkey[2].str = (WCHAR *)(get_string(STR_GLOBAL_BACK));
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.callback = (mmi_proc_func)mmi_mspace_as_display_connect_server_failed_confirmCb;
	mmi_confirm_display((WCHAR *)((U16*)get_string(STR_ID_MSPACE_CONNECT_SERVER_FAILED)), MMI_EVENT_QUERY, &arg);
}


void mmi_mspace_as_lis_updating(S32 hdl)
{
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}
	
	if (g_mspace_cntx.confirm_gid == 0)
	{
		mmi_mspace_as_display_updating(hdl);
	}
}	


S32 mmi_mspace_as_lis_available_update(S32 hdl)
{
	S32 ret;
	
	ret = srv_as_data_download(hdl, NULL, mmi_mspace_as_data_download_handler, NULL);
    return ret;
}

void mmi_mspace_as_lis_no_update(void)
{
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}
}


void mmi_mspace_as_lis_downloaded(void)
{
	mmi_mspace_as_lis_update();

	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}
	else
	{
		// whether race condition handling
	}
}

void mmi_mspace_as_lis_query_connect_fail(void)
{
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}

	mmi_mspace_display_connect_server_failed();
}

void mmi_mspace_as_lis_download_connect_fail(void)
{
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}

	mmi_mspace_display_connect_server_failed();
}


void mmi_mspace_as_data_query_handler(S32 hdl, void * para)
{
	srv_as_cb_app_query_t *query_info = (srv_as_cb_app_query_t *)para;	
    S32 ret;
	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_DATA_QUERY_EVT_S, hdl, query_info->state, g_mspace_cntx.cur_as_lis_hdl);

		switch (query_info->state){
			case E_SRV_AS_QUERYING: // query
				break;
			case E_SRV_AS_AVAILABLE_UPDATE: // query
				ret = mmi_mspace_as_lis_available_update(hdl);
				if (ret < 0)
				{
                    mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);       
				}
				break;
			case E_SRV_AS_NO_UPDATE: // query
				mmi_mspace_as_lis_no_update();
				break;
			case E_SRV_AS_CONNECTING:
				g_mspace_cntx.cur_as_lis_hdl = hdl;
				break;	
			case E_SRV_AS_CONNECTED:
				break;	
			case E_SRV_AS_DOWNLOADING: // download
				break;	
			case E_SRV_AS_DOWNLOADED: // download
				g_mspace_cntx.cur_as_lis_hdl = 0;
				break;	
			case E_SRV_AS_HOST_NOT_FOUND:
			case E_SRV_AS_PIPE_CLOSED:
			case E_SRV_AS_PIPE_BROKEN:
			case E_SRV_AS_FAILURE:
			case E_SRV_AS_ERR_PATH:
				mmi_mspace_as_lis_query_connect_fail();			
				g_mspace_cntx.cur_as_lis_hdl = 0;
				break;		
			case E_SRV_AS_INSTALL_SUCC:
				break;
			case E_SRV_AS_INSTALL_FAIL:
				break;	
			default:
				break;
		}		

	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_DATA_QUERY_EVT_E, g_mspace_cntx.cur_as_lis_hdl);

}


void mmi_mspace_as_data_download_handler(S32 hdl, void * para)
{
	srv_as_cb_app_download_t *download_info = (srv_as_cb_app_download_t *)para;

	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_DATA_DOWNLOAD_EVT_S, hdl, download_info->state, g_mspace_cntx.cur_as_lis_hdl);

		switch (download_info->state){
			case E_SRV_AS_QUERYING: // query
				break;
			case E_SRV_AS_AVAILABLE_UPDATE: // query
				break;
			case E_SRV_AS_NO_UPDATE: // query
				break;
			case E_SRV_AS_CONNECTING:	
				g_mspace_cntx.cur_as_lis_hdl = hdl;
				break;	
			case E_SRV_AS_CONNECTED:
				break;	
			case E_SRV_AS_DOWNLOADING: // download
				mmi_mspace_as_lis_updating(hdl);
				break;	
			case E_SRV_AS_DOWNLOADED: // download
				mmi_mspace_as_lis_downloaded();
				g_mspace_cntx.cur_as_lis_hdl = 0;
				break;	
			case E_SRV_AS_HOST_NOT_FOUND:
			case E_SRV_AS_PIPE_CLOSED:
			case E_SRV_AS_PIPE_BROKEN:
			case E_SRV_AS_FAILURE:
			case E_SRV_AS_ERR_PATH:
				mmi_mspace_as_lis_download_connect_fail();
				g_mspace_cntx.cur_as_lis_hdl = 0;
				break;		
			case E_SRV_AS_INSTALL_SUCC:
				break;
			case E_SRV_AS_INSTALL_FAIL:
				break;		
			default:
				break;
		}		

	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_DATA_DOWNLOAD_EVT_E, g_mspace_cntx.cur_as_lis_hdl);

}


void mmi_mspace_as_free_list(void)
{
	srv_as_app_node_t *app_item_ptr = NULL;
	S32 list_index = 0;

	
	if (g_mspace_cntx.cur_app_static_info != NULL)
	{
		kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_static_info);
		g_mspace_cntx.cur_app_static_info = NULL;
	}

	if (g_mspace_cntx.cur_app_dynamic_info != NULL)
	{	
		kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_dynamic_info);
		g_mspace_cntx.cur_app_dynamic_info = NULL;
	}

	if (g_mspace_cntx.cur_app_icon != NULL)
	{	
		kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_icon);
		g_mspace_cntx.cur_app_icon = NULL;
	}

	
	if (g_mspace_cntx.get_app_icon != NULL)
	{
		kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.get_app_icon);
		g_mspace_cntx.get_app_icon = NULL;
	}	
	if (g_mspace_cntx.get_app_static_info != NULL)
	{
		kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.get_app_static_info);
		g_mspace_cntx.get_app_static_info = NULL;
	}
	
}


MMI_BOOL mmi_mspace_as_get_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    //WCHAR list_path[50];	
	srv_as_app_node_t *app_item_ptr = NULL;
	S32 item_index = 0;
	S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	g_mspace_cntx.app_num = srv_as_list_get_record_num();
	if (g_mspace_cntx.app_num == 0)
	{	
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_LIST_NUM_ZERO, g_mspace_cntx.app_num);	// no app
		return MMI_TRUE;
	}	
	if (g_mspace_cntx.app_num < 0)
	{	
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_LIST_NUM_FAIL, g_mspace_cntx.app_num);	// error handling
		return MMI_FALSE;
	}	


	g_mspace_cntx.cur_app_static_info = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, sizeof(srv_as_app_node_t), __FILE__, __LINE__);
	if (g_mspace_cntx.cur_app_static_info == NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_STAT_INFO_MEM_FAIL);
		return MMI_FALSE;
	}
	g_mspace_cntx.cur_app_dynamic_info= kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, sizeof(srv_as_app_info_t), __FILE__, __LINE__);
	if (g_mspace_cntx.cur_app_dynamic_info == NULL)
	{	
		kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_static_info);
		g_mspace_cntx.cur_app_static_info = NULL;
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_DYNM_INFO_MEM_FAIL);
		return MMI_FALSE;
	}
	
	g_mspace_cntx.hl_idx = -1;
	
	return MMI_TRUE;
}

void mmi_mspace_as_update_app_item(void)
{
	S32 ret;

	ret = srv_as_list_get_info(g_mspace_cntx.hl_idx, 1, g_mspace_cntx.cur_app_static_info, g_mspace_cntx.cur_app_dynamic_info);
	if (ret < 0)
	{
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_UPDATE_APP_GET_INFO_FAIL, g_mspace_cntx.hl_idx, ret);
		return;
	}

}


void mmi_mspace_as_lis_init(void)
{
	mmi_mspace_as_get_list();
}

void mmi_mspace_as_lis_update(void)
{
	mmi_mspace_as_free_list();
	mmi_mspace_as_get_list();
}

void mmi_mspace_as_init(void)
{
	srv_as_list_init();

	mmi_mspace_as_lis_init();
}

void mmi_mspace_as_update(void)
{
	srv_as_data_query_t query_info;
	S32 ret;

	mmi_mspace_as_display_waiting();

	query_info.qry = E_SRV_AS_APP_QUERY_LIS;
	query_info.app_id = 0;
	query_info.app_ver = NULL;
	query_info.app_info = NULL;
	srv_as_data_query(&query_info, mmi_mspace_as_data_query_handler, NULL);

	// update current hdl item
}

void mmi_mspace_as_app_install_success(void)
{
	g_mspace_cntx.cur_as_status = E_MSPACE_AS_INSTALL_SUCCESS;

	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_as_no_dla)
	{
		if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
		}
	}

	mmi_popup_display((WCHAR*) GetString(STR_ID_MSPACE_INSTALL_SUCCESS), MMI_EVENT_SUCCESS, NULL);
	
	mmi_mspace_as_update_app_item();
	
	ChangeLeftSoftkey(0, 0);
	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);	
}

void mmi_mspace_as_app_install_fail(void)
{
	g_mspace_cntx.cur_as_status = E_MSPACE_AS_INSTALL_FAIL;

	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_as_no_dla)
	{
		if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
		}
	}
	mmi_popup_display((WCHAR*) GetString(STR_ID_MSPACE_INSTALL_FAIL), MMI_EVENT_FAILURE, NULL);
}

void mmi_mspace_as_app_available_update(void)
{
	g_mspace_cntx.cur_as_status = E_MSPACE_AS_STARTING;
}

void mmi_mspace_as_app_downloading(void)
{
	MMI_ID group_id, scrn_id;

	g_mspace_cntx.cur_as_status = E_MSPACE_AS_DOWNLOADING;

	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);

	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}	

	if (g_mspace_as_no_dla)
	{
		if ( scrn_id == SCR_ID_MSPACE_WAITING
			&& MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_mspace_as_display_downloading();
		}
	}
}

void mmi_mspace_as_app_failure(void)
{
	g_mspace_cntx.cur_as_status = E_MSPACE_AS_FAIL;

	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_as_no_dla)
	{
		if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
		}
	}

	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}

	if (g_mspace_as_no_dla)
	{
		mmi_popup_display((WCHAR*) GetString(STR_ID_MSPACE_CONNECTION_FAILED), MMI_EVENT_FAILURE, NULL);	
	}	
}


void mmi_mspace_as_app_memory_limit(void)
{
	//g_mspace_cntx.cur_as_status = E_MSPACE_AS_FAIL;
	
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_as_no_dla)
	{
		if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
		}
	}
	
	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}
	
	mmi_popup_display((WCHAR*) GetString(STR_ID_VAPP_M_SPACE_MEMORY_LIMITATION), MMI_EVENT_FAILURE, NULL);	
}

void mmi_mspace_as_app_number_limit(void)
{
	//g_mspace_cntx.cur_as_status = E_MSPACE_AS_FAIL;
	
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_as_no_dla)
	{
		if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
		}
	}

	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}
	
	mmi_popup_display((WCHAR*) GetString(STR_MRE_REACH_MAX_NUM), MMI_EVENT_FAILURE, NULL);	
}

void mmi_mspace_as_app_no_update(void)
{
	//g_mspace_cntx.cur_as_status
	
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}

	if (g_mspace_as_no_dla)
	{
		if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
		{
			mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
		}
	}

	if (g_mspace_cntx.confirm_gid > 0)
	{
		mmi_alert_dismiss(g_mspace_cntx.confirm_gid);
		g_mspace_cntx.confirm_gid = 0;
	}
	
	//mmi_popup_display()
}

void mmi_mspace_as_app_download_handler(S32 hdl, void * para)
{
	srv_as_cb_app_download_t *download_info = (srv_as_cb_app_download_t *)para;

	if (g_mspace_cntx.adm_pool_id)
	{
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_RUN_APP_DOWNLOAD_EVT_S, hdl, download_info->state, g_mspace_cntx.cur_as_app_hdl);

			switch (download_info->state){
				case E_SRV_AS_QUERYING: // query
					// popup
					break;
				case E_SRV_AS_AVAILABLE_UPDATE: // query
					mmi_mspace_as_app_available_update();
					break;
				case E_SRV_AS_NO_UPDATE: // query
					mmi_mspace_as_app_no_update();
					break;
				case E_SRV_AS_CONNECTING:
					g_mspace_cntx.cur_as_app_hdl = hdl;
					break;	
				case E_SRV_AS_CONNECTED:
					break;	
				case E_SRV_AS_DOWNLOADING: // download
					mmi_mspace_as_app_downloading();
					break;	
				case E_SRV_AS_DOWNLOADED: // download
					break;	
				case E_SRV_AS_HOST_NOT_FOUND:
				case E_SRV_AS_PIPE_CLOSED:
				case E_SRV_AS_PIPE_BROKEN:
				case E_SRV_AS_FAILURE:
				case E_SRV_AS_ERR_PATH:
				case E_SRV_AS_ERR_ABORT:	
					mmi_mspace_as_app_failure();
					g_mspace_cntx.cur_as_app_hdl = 0;
					break;		
				case E_SRV_AS_INSTALL_SUCC:
					mmi_mspace_as_app_install_success();
					g_mspace_cntx.cur_as_app_hdl = 0;
					break;
				case E_SRV_AS_INSTALL_FAIL:
					mmi_mspace_as_app_install_fail();
					g_mspace_cntx.cur_as_app_hdl = 0;
					break;		
				default:
					break;
			}		

		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_RUN_APP_DOWNLOAD_EVT_E, g_mspace_cntx.cur_as_app_hdl);
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_EXIT_APP_DOWNLOAD_EVT_S, hdl, download_info->state);
	
		switch (download_info->state){
			case E_SRV_AS_QUERYING: // query
			case E_SRV_AS_AVAILABLE_UPDATE: // query
			case E_SRV_AS_NO_UPDATE: // query
			case E_SRV_AS_CONNECTING:
			case E_SRV_AS_CONNECTED:
			case E_SRV_AS_DOWNLOADING: // download
			case E_SRV_AS_DOWNLOADED: // download
				break;	
			case E_SRV_AS_HOST_NOT_FOUND:
			case E_SRV_AS_PIPE_CLOSED:
			case E_SRV_AS_PIPE_BROKEN:
			case E_SRV_AS_FAILURE:
			case E_SRV_AS_ERR_PATH:
			case E_SRV_AS_ERR_ABORT:	
				mmi_popup_display((WCHAR*) GetString(STR_ID_MSPACE_CONNECTION_FAILED), MMI_EVENT_FAILURE, NULL);
				break;		
			case E_SRV_AS_INSTALL_SUCC:
				mmi_popup_display((WCHAR*) GetString(STR_ID_MSPACE_INSTALL_SUCCESS), MMI_EVENT_SUCCESS, NULL);
				break;
			case E_SRV_AS_INSTALL_FAIL:
				mmi_popup_display((WCHAR*) GetString(STR_ID_MSPACE_INSTALL_FAIL), MMI_EVENT_FAILURE, NULL);
				break;		
			default:
				break;
		}

		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_EXIT_APP_DOWNLOAD_EVT_E);
	}
}

void mmi_mspace_as_app_download(void)
{
	S32 ret;

	g_mspace_cntx.cur_as_status = E_MSPACE_AS_NONE;

	mmi_mspace_as_display_waiting();

	ret = srv_as_app_download(g_mspace_cntx.hl_idx, mmi_mspace_as_app_download_handler, NULL);
	// error handling
	if (ret == -17)
	{
		mmi_mspace_as_app_memory_limit();
	}
	if (ret == -18)
	{
		mmi_mspace_as_app_number_limit();
	}
	
}


static mmi_ret mmi_mspace_as_display_update_confirmCb(mmi_alert_result_evt_struct *evt)
{
	S32 ret;
	S32 hdl = (S32)evt->user_tag;
	
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (evt->result)
		{
		  case MMI_ALERT_CNFM_1:
		  case MMI_ALERT_CNFM_2:
		  	mmi_mspace_as_app_download();
			break;
		  case MMI_ALERT_CNFM_3:
			break;
		  case MMI_ALERT_NORMAL_EXIT:
			g_mspace_cntx.confirm_gid = 0;
			break;
		  default:
			break; 
		}
	}
	return MMI_RET_OK;
}


void mmi_mspace_as_app_update(void)
{
	mmi_confirm_property_struct arg;
	srv_as_app_node_t *app_static_info_ptr = NULL;
	WCHAR dis_buf[MSPACE_MAX_STRING * 2];	// should not need consider category size limit
	U32 pos;

	app_static_info_ptr = g_mspace_cntx.cur_app_static_info;	
	
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)(get_string(STR_GLOBAL_UPDATE));
	arg.softkey[2].str = (WCHAR *)(get_string(STR_GLOBAL_BACK));
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.f_auto_question_mark = MMI_TRUE;
	arg.callback = (mmi_proc_func)mmi_mspace_as_display_update_confirmCb;

	memset(dis_buf, 0, MSPACE_MAX_STRING * 2 * 2);	
	pos = 0;	
	mmi_wcsncpy(dis_buf + pos, get_string(STR_GLOBAL_UPDATE), MSPACE_MAX_STRING);
	pos = mmi_wcslen(dis_buf);	
	*(dis_buf + pos) = 0x000A;	
	pos++;
	mmi_wcsncpy(dis_buf + pos, (app_static_info_ptr->dis_name), MSPACE_MAX_STRING);	
	
	mmi_confirm_display(dis_buf, MMI_EVENT_QUERY, &arg);
}

static mmi_ret mmi_mspace_as_display_install_confirmCb(mmi_alert_result_evt_struct *evt)
{
	S32 ret;
	S32 hdl = (S32)evt->user_tag;
	
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (evt->result)
		{
		  case MMI_ALERT_CNFM_1:
		  case MMI_ALERT_CNFM_2:
		  	mmi_mspace_as_app_download();
			break;
		  case MMI_ALERT_CNFM_3:
			break;
		  case MMI_ALERT_NORMAL_EXIT:
			g_mspace_cntx.confirm_gid = 0;
			break;
		  default:
			break; 
		}
	}
	return MMI_RET_OK;
}



void mmi_mspace_as_app_install(void)
{
	mmi_confirm_property_struct arg;
	srv_as_app_node_t *app_static_info_ptr = NULL;
	WCHAR dis_buf[MSPACE_MAX_STRING * 2];	// should not need consider category size limit
	U32 pos;

	app_static_info_ptr = g_mspace_cntx.cur_app_static_info;	
	
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)(get_string(STR_GLOBAL_INSTALL));
	arg.softkey[2].str = (WCHAR *)(get_string(STR_GLOBAL_BACK));
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.f_auto_question_mark = MMI_TRUE;
	arg.callback = (mmi_proc_func)mmi_mspace_as_display_install_confirmCb;

	memset(dis_buf, 0, MSPACE_MAX_STRING * 2 * 2);	
	pos = 0;	
	mmi_wcsncpy(dis_buf + pos, get_string(STR_GLOBAL_INSTALL), MSPACE_MAX_STRING);
	pos = mmi_wcslen(dis_buf);	
	*(dis_buf + pos) = 0x000A;	
	pos++;
	mmi_wcsncpy(dis_buf + pos, (app_static_info_ptr->dis_name), MSPACE_MAX_STRING);	
	
	mmi_confirm_display(dis_buf, MMI_EVENT_QUERY, &arg);
}


#endif /* __MMI_MRE_MSPACE__ */ 
