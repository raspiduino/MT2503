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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *   
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
 
 
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)
#if defined (__MMI_NCENTER_SUPPORT__)
#include "mmi_frm_events_gprot.h"
#include "DLAgentSrvIProt.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "wgui_categories_text_viewer.h"
#include "Vsrv_ncenter.h"
#include "mmi_frm_events_gprot.h"
#include "DLAgentSrvIProt.h"
#include "DLAgentAppScr.h"
#include "DLAgentAppMain.h"
#include "DLAgentAppNcenter.h"
#include "DLAgentSrvProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "Menucuigprot.h"
#include "InlineCuiGprot.h"

#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#include "mmi_rp_app_downloadagent_def.h"
#endif

static NMGR_HANDLE g_da_nmgr_alert_handle;
static NMGR_HANDLE g_da_push_nmgr_alert_handle;


/*  NCenter 2.0  Begin  */

srv_da_job_struct* mmi_da_job_get_job_by_id(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct* job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_get_list_job();
    while(job)
    {
        if(id == DA_JOB_GET_ID(job))
            return job;

        job = job->next_job;
    }
    return NULL;
}



void mmi_da_update_statusbar(void)
{
    
	U16 job_count = 0;
    job_count = srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_DOWNLOADING) +
                srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_PROCESSING);

    if (job_count)
    {
        if (!wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOADING))
        {
            wgui_status_icon_bar_show_icon(STATUS_ICON_DOWNLOADING);
        }
    }
    else
    {
        if (wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOADING))
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_DOWNLOADING);
        }
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

}

void mmi_da_ncenter_event_cb(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
	U32										*job_id = (U32 *)(userData);
	srv_da_job_struct *job;
	S32 job_list_highlight_index;

	if(intent.type == VSRV_NINTENT_TYPE_LAUNCH || intent.type == VSRV_NINTENT_TYPE_TAP)
	{
		
		
		job = mmi_da_job_get_job_by_id(*job_id);
                 vsrv_ncenter_close_notification(job->notify_handle);
        job->notify_handle = NULL;
		#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
			if(job->setting_info.can_minimize)
			{
				/* bring up list screen */

		job_list_highlight_index = job ? srv_da_get_job_index(job) : 0;
		mmi_da_set_job_highlight_index(job_list_highlight_index);
		mmi_da_app_display_job_list();
			}
			else
	   #endif
			{
				#if defined(BROWSER_SUPPORT)
				mmi_da_app_close_all_screens();
				#endif
				srv_da_adp_display_job_detail(job);
			}		
        if(!mmi_da_any_job_present())
        {
        if(g_da_nmgr_alert_handle)
            mmi_frm_nmgr_alert_cancel(g_da_nmgr_alert_handle);
	}
        }
    else if (intent.type == VSRV_NINTENT_TYPE_TERMINATE || intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        job = mmi_da_job_get_job_by_id(*job_id);
        srv_da_curr_job_do_abort(job);
      if(g_da_nmgr_alert_handle)
            mmi_frm_nmgr_alert_cancel(g_da_nmgr_alert_handle);
    }
	else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
	{
		job = mmi_da_job_get_job_by_id(*job_id);
		if (job->state == SRV_DA_JOB_STATE_DOWNLOADING)
		{
			mmi_da_update_all_cells(job);
		}
		else if (job->state == SRV_DA_JOB_STATE_COMPLETED)
		{
			mmi_da_update_completed_cells(job);
		}
		else
		{
		}

	}
	else
	{
	}
 
}

void mmi_da_nmgr_event_cb(mmi_scenario_id scen_id, void *arg)
{
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__	
		mmi_da_app_display_job_list();
#endif

}


U32 mmi_da_fill_subtext (srv_da_job_struct     *job, U16 state, U16 *sub_text)
{
   // U16 job_count = 0;
	   S8                 buffer_temp [300] = {'\0',};
     U16                ui_item_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
       U16                *temp_str = NULL;

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

        job->op->get_name(job, ui_item_buffer, SRV_FMGR_PATH_MAX_LEN + 1);
        temp_str = (U16*)srv_da_util_get_filename ((U16*)ui_item_buffer);
        mmi_ucs2ncpy ((S8*)buffer_temp, (S8*)temp_str, MMI_DA_MAX_FILENAME_INPUT_LEN);
        memset (ui_item_buffer, 0, (SRV_FMGR_PATH_MAX_LEN + 2));
        mmi_ucs2ncpy ((S8*)ui_item_buffer, (S8*)buffer_temp, MMI_DA_MAX_FILENAME_INPUT_LEN);

		//mmi_ucs2cpy(sub_text, (WCHAR *)ui_item_buffer);
		//mmi_ucs2cat(GetString (STR_DLA_IS_DOWNLOADING), sub_text);
		
        if (state == SRV_DA_JOB_STATE_DOWNLOADING)
        {
           
		kal_wsprintf(sub_text, "%w%w%w",
                     ui_item_buffer, " ", GetString (STR_DLA_IS_DOWNLOADING));
        }
        if (state == SRV_DA_JOB_STATE_FAILED)
        {
            
					kal_wsprintf(sub_text, "%w%w%w",
                     ui_item_buffer, " ",
					 GetString (STR_DLA_IS_FAILED_TO_DOWNLOAD));
        }
        if (state == SRV_DA_JOB_STATE_COMPLETED)
        {
           
		kal_wsprintf(sub_text, "%w%w%w",
                     ui_item_buffer," ",
					 GetString (STR_DLA_IS_COMPLETED_DOWNLOAD));
        }
    
    return 0;
}

vsrv_ngroup_handle group_hdl = NULL;
vsrv_notification_handle p_noti_hdl;
vsrv_ngroup_handle push_group_hdl = NULL;

mmi_ret mmi_da_push_hdlr_proc(mmi_event_struct *evt)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        mmi_da_app_display_job_list();
#endif
    }
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_completed_push_obj_nmgr_proc(mmi_event_struct*);
void mmi_da_show_push_status(srv_da_push_item_struct *item)//, U32 job_type)
{
	
   U16                ui_item_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
    U16                temp_filename[MMI_DA_MAX_FILENAME_INPUT_LEN + 2] = {'\0', };
    U16                ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
    mmi_frm_nmgr_alert_struct alert_info;
    //new
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));

	alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
	alert_info.app_proc_para.user_data = NULL;

    alert_info.app_id = APP_DOWNLOADAGENT;
    alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK | MMI_FRM_NMGR_UI_STATUS_ICON_MASK | MMI_FRM_NMGR_UI_POPUP_MASK;
    alert_info.behavior_mask = PREFER_DEFAULT;
    alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alert_info.status_bar_para.display_string = (WCHAR *)ui_item_buffer;
    alert_info.status_bar_para.image_type =MMI_NMGR_IMG_RES_ID;
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_PUSHED_OBJ;
    alert_info.app_proc_para.scrn_group_proc = &mmi_da_completed_push_obj_nmgr_proc;
    alert_info.app_proc_para.user_data = NULL;
    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
	alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
	alert_info.popup_para.image.id = IMG_ID_DA_DOWNLOAD_ICON;
    alert_info.popup_para.popup_string = (WCHAR *)ui_item_buffer;
	alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);

    alert_info.event_type = MMI_EVENT_UNREAD_MSG;
	alert_info.status_bar_para.display_string = (WCHAR *)ui_item_buffer;
	alert_info.status_bar_para.image.id = IMG_ID_DA_NC_PUSH;         //used for textpreview
    srv_da_push_get_filename (item, temp_filename, ext);

    mmi_ucs2cpy ((S8*)ui_item_buffer, (S8*)get_string (STR_ID_DA_NEW_PUSHED_OBJECT));
    mmi_ucs2cat ((S8*)ui_item_buffer, (S8*)" ");
    mmi_ucs2ncat ((S8*)ui_item_buffer, (S8*)temp_filename, MMI_DA_MAX_FILENAME_INPUT_LEN);

    /* Using the same event priority as download completed */
    //mmi_frm_nmgr_notify(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_DA_DOWNLOAD_COMPLETED, &noti);
    g_da_push_nmgr_alert_handle = mmi_frm_nmgr_alert(&alert_info);
}
void mmi_da_show_ncenter(srv_da_job_struct *job, U32 type)
{
    
    //vsrv_notification_handle noti_hdl;
	srv_da_job_struct		*current_job = NULL;
	srv_da_job_struct		*job_temp;
	mmi_image_src_struct imag;
	S32 					job_id_temp;
	U32 					*job_id = NULL;
	U16 sub_text[65] = {0,};
    U16 job_count = 0;
	WCHAR title[20];
    srv_da_job_struct		*first_job = srv_da_get_first_job();
	if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT))
	{
		group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT);
		ASSERT(group_hdl != NULL);
		//mmi_wcscpy(title, (WCHAR *)L"Downloads");
        mmi_ucs2cpy ((S8*)title, (S8*)get_string (STR_ID_DA_DOWNLOADS));
		vsrv_ncenter_set_ngroup_title_str(group_hdl, title);
	}
	/* For downloading cell update */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
		
		job_id_temp = DA_JOB_GET_ID(job);
		job_id = (U32 *)(&job_id_temp);

    job->notify_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING,group_hdl,*job_id);
	
    ASSERT(job->notify_handle != NULL);
	//srv_da_adp_set_job_notify_handle(notify_hdl);
	imag.type = MMI_IMAGE_SRC_TYPE_RES_ID;
	imag.data.res_id = IMG_ID_DA_NC_DOWNLOAD;
    vsrv_ncenter_set_notification_maintext_str(job->notify_handle,(WCHAR*)GetString(STR_ID_DA_DOWNLOADING));
	mmi_da_fill_subtext (job, SRV_DA_JOB_STATE_DOWNLOADING, sub_text);
    vsrv_ncenter_set_notification_subtext_str(job->notify_handle, (WCHAR*)sub_text);
    //vsrv_ncenter_set_notification_questiontext(job->notify_handle, (WCHAR *)L"Discard downloading?");
    vsrv_ncenter_set_notification_questiontext_str(job->notify_handle, (WCHAR*)GetString(STR_ID_DA_ASK_DISCARD_DOWNLOADING));
	vsrv_ncenter_set_notification_icon(job->notify_handle, imag);
    vsrv_ncenter_set_notification_intent_callback(job->notify_handle, mmi_da_ncenter_event_cb, (void *)job_id, sizeof(U32));
    vsrv_ncenter_notify_notification(job->notify_handle);
	mmi_da_update_statusbar();
}


mmi_ret mmi_da_completed_push_obj_nmgr_proc(mmi_event_struct *evt)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;
	srv_da_push_item_struct *active_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_item = srv_da_push_get_top_screen_stack_item();
	
		if (!active_item)
		{
			return;
		}
		//srv_da_push_remove_item_processed (active_item);
		srv_da_set_item_in_notifying(active_item);
    
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH || evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {  
        item = srv_da_get_item_in_notifying();
        vsrv_ncenter_close_notification(item->notify_handle);
        srv_da_push_prepend_to_list(srv_da_get_top_processing_list_item(), item);
        srv_da_push_remove_from_list(srv_da_get_item_to_be_confirm(), item);
        srv_da_push_select_storage(item, NULL);
        if(g_da_push_nmgr_alert_handle)
            mmi_frm_nmgr_alert_cancel(mmi_frm_nmgr_compose_alert_handle(APP_DOWNLOADAGENT, MMI_EVENT_DEFAULT, STATUS_ICON_PUSHED_OBJ));
		
    }    
    return MMI_RET_OK;
}
void DLAgentPushNCenterIntentCallback(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSizee)
{
    srv_da_push_item_struct *active_item;
#ifdef __MMI_USB_SUPPORT__
	if (srv_usb_is_in_mass_storage_mode())
	{
		mmi_usb_app_unavailable_popup(0);
		return;
	}
#endif /* __MMI_USB_SUPPORT__ */

	
	active_item = srv_da_push_get_top_screen_stack_item();
	if(intent.type == VSRV_NINTENT_TYPE_LAUNCH || intent.type == VSRV_NINTENT_TYPE_TAP)
	{
		if (!active_item)
		{
			return;
		}
		//srv_da_push_remove_item_processed (active_item);		
		srv_da_set_item_in_notifying(active_item);
		{
            srv_da_push_item_struct *item;
			item = srv_da_get_item_in_notifying();
            srv_da_push_prepend_to_list(srv_da_get_top_processing_list_item(), item);
            srv_da_push_remove_from_list(srv_da_get_item_to_be_confirm(), item);
            srv_da_push_select_storage(item, NULL);
		}
        if(g_da_push_nmgr_alert_handle)
            mmi_frm_nmgr_alert_cancel(mmi_frm_nmgr_compose_alert_handle(APP_DOWNLOADAGENT, MMI_EVENT_DEFAULT, STATUS_ICON_PUSHED_OBJ));
		//mmi_da_show_push_obj_ncenter(active_item,SRV_DA_JOB_TYPE_PUSH);
	}
	else if(intent.type == VSRV_NINTENT_TYPE_TERMINATE || intent.type == VSRV_NINTENT_TYPE_CLEAR)
	{
		srv_da_push_remove_item_processed (active_item);
		//mmi_da_show_push_obj_ncenter(active_item, SRV_DA_JOB_TYPE_PUSH);
        if(g_da_push_nmgr_alert_handle)
           mmi_frm_nmgr_alert_cancel(mmi_frm_nmgr_compose_alert_handle(APP_DOWNLOADAGENT, MMI_EVENT_DEFAULT, STATUS_ICON_PUSHED_OBJ));
		
	}
}

void mmi_da_show_push_obj_ncenter(srv_da_push_item_struct *item, U32 type)
{
    WCHAR title[20];
    U16 *item_id;
    U16 sub_text[65] = {0,};
    U16    *tempFilename = NULL;
    U16    filename[MMI_DA_MAX_FILENAME_INPUT_LEN + 1];
    U16    fileext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    mmi_image_src_struct imag;
    U16 temp_item = item->unique_id;
    item_id = &temp_item;
    //VsrvNGroupSingleTitle *dlagent_push_object_group;
	//VSRV_NGROUP_CREATE_EX(dlagent_push_object_group,VsrvNGroupSingleTitle,(VAPP_DLAGENT + 100));
    if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT + 100))
	{
        push_group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT + 100);
	    ASSERT(push_group_hdl != NULL);
	    mmi_wcscpy(title, (WCHAR *)L"Download objects");
	    vsrv_ncenter_set_ngroup_title_str(push_group_hdl, title);
    }
	//VsrvNotificationEvent *noti = NULL;
	//VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, (VAPP_DLAGENT + 100, 0));
	//each case will update status bar for push object
    item->notify_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT,push_group_hdl,*item_id);
	//vapp_dla_update_statusbar_push_object();
	if(srv_da_push_get_top_screen_stack_item() == NULL)
	{
		vsrv_ncenter_close_notification(item->notify_handle);
		vsrv_ncenter_close_ngroup(push_group_hdl);		
		return;
	}
	if(item->filename)
    {
        tempFilename = srv_da_util_get_filename(item->filename);
    }
    else if(item->filepath)
    {
        tempFilename = srv_da_util_get_filename(item->filepath);
    }
    else
    {
        ASSERT(0);
    }
    srv_da_extract_filepath(tempFilename, filename, fileext);
	
	mmi_ucs2cpy((S8 *)sub_text, (S8 *)filename);
    imag.type = MMI_IMAGE_SRC_TYPE_RES_ID;
	imag.data.res_id = IMG_ID_DA_NC_PUSH;
    vsrv_ncenter_set_notification_maintext_str(item->notify_handle,(WCHAR*)GetString(STR_ID_DA_PUSHED_OBJECT));
    vsrv_ncenter_set_notification_subtext_str(item->notify_handle, (WCHAR*)sub_text);
	vsrv_ncenter_set_notification_icon(item->notify_handle, imag);
    vsrv_ncenter_set_notification_intent_callback(item->notify_handle, DLAgentPushNCenterIntentCallback, (void *)item_id, sizeof(U32));
    vsrv_ncenter_notify_notification(item->notify_handle);
}
mmi_ret mmi_da_completed_nmgr_proc(mmi_event_struct *evt)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH || evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        mmi_da_app_display_job_list();
#endif
        if(g_da_nmgr_alert_handle)
            mmi_frm_nmgr_alert_cancel(g_da_nmgr_alert_handle);
    }
    return MMI_RET_OK;
}


void mmi_da_show_job_status(srv_da_job_struct*job)
{
	S8                 buffer_temp [300] = {'\0',};
    U16                ui_item_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
    U16                *temp_str = NULL;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
    mmi_frm_nmgr_alert_struct alert_info;
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
    job->op->get_name(job, ui_item_buffer, SRV_FMGR_PATH_MAX_LEN + 1);
    temp_str = (U16*)srv_da_util_get_filename ((U16*)ui_item_buffer);
    mmi_ucs2ncpy ((S8*)buffer_temp, (S8*)temp_str, MMI_DA_MAX_FILENAME_INPUT_LEN);
    memset (ui_item_buffer, 0, (SRV_FMGR_PATH_MAX_LEN + 2));
    mmi_ucs2ncpy ((S8*)ui_item_buffer, (S8*)buffer_temp, MMI_DA_MAX_FILENAME_INPUT_LEN);
    mmi_ucs2cat ((S8*)ui_item_buffer, (S8*)" ");

    //new code
    alert_info.app_id = APP_DOWNLOADAGENT;
    alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;    
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK | MMI_FRM_NMGR_UI_STATUS_ICON_MASK | MMI_FRM_NMGR_UI_POPUP_MASK;
    alert_info.behavior_mask = PREFER_DEFAULT;
if (job->setting_info.can_minimize)
{
    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
}
else
{
	alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE;
    alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_OK);  
}
	alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
	alert_info.popup_para.image.id = IMG_ID_DA_DOWNLOAD_ICON;
    alert_info.popup_para.popup_string = (WCHAR *)ui_item_buffer;
	//alert_info.popup_para.popup_button_string = popup_button_string;
    alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alert_info.status_bar_para.display_string = (WCHAR *)ui_item_buffer;
    alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert_info.app_proc_para.scrn_group_proc = &mmi_da_completed_nmgr_proc;
    alert_info.app_proc_para.user_data = NULL;
   
    //end new code
    


    if (job->state == SRV_DA_JOB_STATE_FAILED)
    {
        mmi_ucs2cat ((S8*)ui_item_buffer, (S8*)get_string (STR_DLA_IS_FAILED_TO_DOWNLOAD));
        alert_info.event_type = MMI_EVENT_DA_DOWNLOAD_FAILED;
        //mmi_frm_nmgr_notify(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_DA_DOWNLOAD_FAILED, &noti);
        alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_OK);
        alert_info.event_type = MMI_EVENT_DA_DOWNLOAD_FAILED;
		alert_info.status_bar_para.image.id = IMG_ID_DA_NC_FAILED;
		alert_info.status_bar_icon_para.icon_id = STATUS_ICON_DOWNLOAD_FAILED;
    }
    else
    {
        mmi_ucs2cat ((S8*)ui_item_buffer, (S8*)get_string (STR_DLA_IS_COMPLETED_DOWNLOAD));
        //mmi_frm_nmgr_notify(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_DA_DOWNLOAD_COMPLETED, &noti);
        alert_info.event_type = MMI_EVENT_DA_DOWNLOAD_COMPLETED;
		alert_info.status_bar_para.image.id = IMG_ID_DA_NC_COMPLETE;
		alert_info.status_bar_icon_para.icon_id = STATUS_ICON_DOWNLOAD_COMPLETED;
    }
    g_da_nmgr_alert_handle = mmi_frm_nmgr_alert(&alert_info);
    mmi_da_update_all_cells(job);

}

void mmi_da_ncenter_show_completed_cell(srv_da_job_struct *job, MMI_BOOL show, U16 job_count)
{
	U16 sub_text[65];
	S32 job_id_temp;
	U32 *job_id;
	mmi_image_src_struct imag;
	WCHAR title[20];
	

	if (job_count > 1)
	{
		//vsrv_ncenter_close_notification(job->notify_handle);

	}
	if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT))
	{
		group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT);
		ASSERT(group_hdl != NULL);
		mmi_wcscpy(title, (WCHAR *)get_string (STR_ID_DA_DOWNLOADS));    
		vsrv_ncenter_set_ngroup_title_str(group_hdl, title);
	}
	job_id_temp = DA_JOB_GET_ID(job);
	job_id = (U32 *)(&job_id_temp);
	if (job->notify_handle == vsrv_ncenter_query_notification(group_hdl, *job_id))
	{
		vsrv_ncenter_close_notification(job->notify_handle);
		if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT))
		{
			group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT);
			ASSERT(group_hdl != NULL);
			mmi_wcscpy(title, (WCHAR *)get_string (STR_ID_DA_DOWNLOADS));    
			vsrv_ncenter_set_ngroup_title_str(group_hdl, title);
		}
	}
	job->notify_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT,group_hdl, *job_id);
	
	if (show)
	{
		
		ASSERT(job->notify_handle != NULL);
		//srv_da_adp_set_job_notify_handle(notify_hdl);
		imag.type = MMI_IMAGE_SRC_TYPE_RES_ID;
		imag.data.res_id = IMG_ID_DA_NC_COMPLETE;
		vsrv_ncenter_set_notification_maintext_str(job->notify_handle,(WCHAR*)get_string (STR_ID_DA_COMPLETED));
		mmi_da_fill_subtext (job, SRV_DA_JOB_STATE_COMPLETED, sub_text);
		vsrv_ncenter_set_notification_subtext_str(job->notify_handle, (WCHAR*)sub_text);
		vsrv_ncenter_set_notification_icon(job->notify_handle, imag);
		vsrv_ncenter_set_notification_intent_callback(job->notify_handle, mmi_da_ncenter_event_cb, (void *)job_id, sizeof(U32));
		vsrv_ncenter_notify_notification(job->notify_handle);
		mmi_da_update_statusbar();
    }
    else
    {
        //cell->m_show = VFX_FALSE;
        //cell->m_signalStateChanged.emit(cell, VAPP_NCENTER_STATE_HIDE);  //to do
		if (job->notify_handle != NULL)
		vsrv_ncenter_close_notification(job->notify_handle);
    }
    
}

void mmi_da_update_completed_cells(srv_da_job_struct *job)
{
	U16 job_count = 0;
    

    job_count = srv_da_count_job(srv_da_is_notified, SRV_DA_JOB_STATE_COMPLETED);

    
    if (job_count)
    {
        //evt.show = MMI_TRUE;
		mmi_da_ncenter_show_completed_cell(job, MMI_TRUE, job_count);

    }
    else
    {
        //evt.show = MMI_FALSE;
		mmi_da_ncenter_show_completed_cell(job, MMI_FALSE, 0);
    }
    
}
void mmi_da_ncenter_show_downloading_cell (srv_da_job_struct *job, MMI_BOOL show, U16 job_count)
{
	U16 sub_text[65];
		S32 job_id_temp;
	U32 *job_id;
	mmi_image_src_struct imag;
	
	WCHAR title[20];
	
	if (job_count > 1)
	{
		//vsrv_ncenter_close_notification(job->notify_handle);
	}

		if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT))
	{
		group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT);
		ASSERT(group_hdl != NULL);
		mmi_wcscpy(title, (WCHAR *)get_string (STR_ID_DA_DOWNLOADS));    
		vsrv_ncenter_set_ngroup_title_str(group_hdl, title);
	}

	job_id_temp = DA_JOB_GET_ID(job);
	job_id = (U32 *)(&job_id_temp);
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
/* under construction !*/
/* under construction !*/
#endif
	job->notify_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING,group_hdl, *job_id);
	if (show)
	{
		
		ASSERT(job->notify_handle != NULL);
		//srv_da_adp_set_job_notify_handle(notify_hdl);
		imag.type = MMI_IMAGE_SRC_TYPE_RES_ID;
		imag.data.res_id = IMG_ID_DA_NC_DOWNLOAD;
		vsrv_ncenter_set_notification_maintext_str(job->notify_handle,(WCHAR*)get_string (STR_ID_DA_DOWNLOADING));
		mmi_da_fill_subtext (job, SRV_DA_JOB_STATE_DOWNLOADING, sub_text);
		vsrv_ncenter_set_notification_subtext_str(job->notify_handle, (WCHAR*)sub_text);
                vsrv_ncenter_set_notification_questiontext_str(job->notify_handle, (WCHAR*)GetString(STR_ID_DA_ASK_DISCARD_DOWNLOADING));
		vsrv_ncenter_set_notification_icon(job->notify_handle, imag);
		vsrv_ncenter_set_notification_intent_callback(job->notify_handle, mmi_da_ncenter_event_cb, (void *)job_id, sizeof(U32));
		vsrv_ncenter_notify_notification(job->notify_handle);
		mmi_da_update_statusbar();  
    }
    else
    {
        
		//cell->m_show = VFX_FALSE;// to do
        //cell->m_signalStateChanged.emit(cell, VAPP_NCENTER_STATE_HIDE);
		
		if (job->notify_handle != NULL)
		vsrv_ncenter_close_notification(job->notify_handle);
    }
    
}

void mmi_da_update_status_icons(void)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
}
void mmi_da_update_all_cells(srv_da_job_struct *job)
{
	S32 job_count = 0;
    /* For downloading cell update */
    job_count = srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_DOWNLOADING) +
                srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_PROCESSING);

   
    if (job_count)
    {
        mmi_da_ncenter_show_downloading_cell(job, MMI_TRUE, job_count);
    }
    else
    {
        mmi_da_ncenter_show_downloading_cell(job, MMI_FALSE, 0);
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    //updateStatusIcons();
	mmi_da_update_status_icons();
    srv_da_send_download_info_ind();
}
void mmi_da_ncenter_show_failed_cell (srv_da_job_struct *job, MMI_BOOL show, U16 job_count)
{
    
    U16 sub_text[65];
	S32 job_id_temp;
	U32 *job_id;
	mmi_image_src_struct imag;
	
	WCHAR title[20];
	

	if (job_count > 1)
	{
		//vsrv_ncenter_close_notification(job->notify_handle);
	}
	if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT))
	{
		group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT);
		ASSERT(group_hdl != NULL);
		mmi_wcscpy(title, (WCHAR *)get_string (STR_ID_DA_DOWNLOADS));    
		vsrv_ncenter_set_ngroup_title_str(group_hdl, title);
	}
		job_id_temp = DA_JOB_GET_ID(job);
		job_id = (U32 *)(&job_id_temp);
	if (job->notify_handle == vsrv_ncenter_query_notification(group_hdl, *job_id))
	{
		vsrv_ncenter_close_notification(job->notify_handle);
		if (!vsrv_ncenter_query_ngroup(APP_DOWNLOADAGENT))
		{
			group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_DOWNLOADAGENT);
			ASSERT(group_hdl != NULL);
			mmi_wcscpy(title, (WCHAR *)get_string (STR_ID_DA_DOWNLOADS));    
			vsrv_ncenter_set_ngroup_title_str(group_hdl, title);
		}
	}
		job->notify_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT,group_hdl, *job_id);

	if (show)
	{

		ASSERT(job->notify_handle != NULL);
		//srv_da_adp_set_job_notify_handle(notify_hdl);
		imag.type = MMI_IMAGE_SRC_TYPE_RES_ID;
		imag.data.res_id = IMG_ID_DA_NC_FAILED;
		vsrv_ncenter_set_notification_maintext_str(job->notify_handle,(WCHAR*)get_string (STR_GLOBAL_FAILED));
		mmi_da_fill_subtext (job, SRV_DA_JOB_STATE_FAILED, sub_text);
		vsrv_ncenter_set_notification_subtext_str(job->notify_handle, (WCHAR*)sub_text);
		vsrv_ncenter_set_notification_icon(job->notify_handle, imag);
		vsrv_ncenter_set_notification_intent_callback(job->notify_handle, mmi_da_ncenter_event_cb, (void *)job_id, sizeof(U32));
		vsrv_ncenter_notify_notification(job->notify_handle);
		mmi_da_update_statusbar();  
    }
    else
    {
        //cell->m_show = VFX_FALSE;  //to do
        //cell->m_signalStateChanged.emit(cell, VAPP_NCENTER_STATE_HIDE);
		if (job->notify_handle != NULL)
		vsrv_ncenter_close_notification(job->notify_handle);
    }
    return ;
}
void mmi_da_update_failed_cells (srv_da_job_struct* job)
{
    U16 job_count = 0;
    
    job_count = srv_da_count_job(srv_da_is_notified, SRV_DA_JOB_STATE_FAILED);

    
    if (job_count)
    {
        mmi_da_ncenter_show_failed_cell(job, MMI_TRUE, job_count);
    }
    else
    {
       mmi_da_ncenter_show_failed_cell(job, MMI_FALSE, 0);
    }
   
}
void mmi_da_cancel_alert(srv_da_job_struct *job)
{
    if(g_da_nmgr_alert_handle)
	{
            	if (job->state == SRV_DA_JOB_STATE_COMPLETED)
                     mmi_frm_nmgr_alert_cancel(mmi_frm_nmgr_compose_alert_handle(APP_DOWNLOADAGENT, MMI_EVENT_DEFAULT, STATUS_ICON_DOWNLOAD_COMPLETED));
		else if (job->state == SRV_DA_JOB_STATE_COMPLETED)
                     mmi_frm_nmgr_alert_cancel(mmi_frm_nmgr_compose_alert_handle(APP_DOWNLOADAGENT, MMI_EVENT_DEFAULT, STATUS_ICON_DOWNLOAD_FAILED));
		else
			return;
        }
}
MMI_BOOL mmi_da_any_job_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct   *job;
    U32                 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_get_list_job();
    while(job)
    {
        if (job->notify_handle)
		{
            return MMI_TRUE;
		}
        job = job->next_job;
    }
    return MMI_FALSE;
}

/*  NCenter 2.0  End  */

#endif //NCenter

#endif //Download Agent
