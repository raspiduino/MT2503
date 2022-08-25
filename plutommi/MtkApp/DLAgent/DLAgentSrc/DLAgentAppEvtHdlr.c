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
 
 
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_frm_events_gprot.h"
#include "DLAgentSrvIProt.h"
#include "DLAgentAppScr.h"
#include "DLAgentAppMain.h"
#include "DLAgentSrvProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "Menucuigprot.h"
#include "InlineCuiGprot.h"
#include "FileMgrCuiGprot.h"
#if defined (__MMI_NCENTER_SUPPORT__)
#include "DLAgentAppNcenter.h"
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#include "mmi_rp_app_downloadagent_def.h"
#endif


srv_da_auth_callback_type g_da_auth_callback;
extern mmi_ret mmi_da_evt_new_download_confirm_screen(mmi_event_struct *evnt)
{
#ifndef MMI_DA_PLUTO_SLIM
	U16 choice_instance_id;
    srv_da_show_choice_screen_event_struct *para;
    para = (srv_da_show_choice_screen_event_struct*)evnt;
    if(!mmi_da_is_app_launched())
    {
        mmi_da_launch_app(MMI_DA_LAUNCH_FROM_BROWSER);
    }
	choice_instance_id = mmi_da_app_scr_show_choice_screen(para);
	srv_da_adp_set_active_download_confirm_screen((srv_da_job_struct*)para->arg, choice_instance_id);
#endif
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_init_app
* DESCRIPTION
*   initial download agent, set handler and state and initial table
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
extern void mmi_da_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* init */

 extern void mmi_da_app_init(void);
 mmi_da_app_init();

}

mmi_ret mmi_da_evt_confirm_oma_download(mmi_event_struct *evnt)
{
#ifdef __MMI_OMA_DD_DOWNLOAD__
    mmi_da_oma_entry_download_option(); 
#endif // __MMI_OMA_DD_DOWNLOAD__
    return MMI_RET_OK;
}

//todo
#ifdef __MMI_OMA_DD_DOWNLOAD__
extern srv_da_acceptance_enum mmi_da_oma_filename_done(
    U32 criteria, U16* filepath, MMI_BOOL canback, MMI_BOOL canpopup, void *instance);
#endif
extern mmi_ret mmi_da_evt_select_storage(mmi_event_struct *evnt)
{
	srv_da_display_select_storage_event_struct *param;
    param = (srv_da_display_select_storage_event_struct*)evnt;
    if(param->job_type == MMI_DA_WAP_DOWNLOAD)
    {
#if defined(BROWSER_SUPPORT)
	    mmi_da_app_scr_select_storage(srv_da_http_filename_done, (mmi_da_scr_storage_parameter_struct*)param->para, param->arg, srv_da_job_get_title_icon((srv_da_job_struct *)param->arg));
#endif
    }
#ifdef __MMI_OMA_DD_DOWNLOAD__
    else if (param->job_type == MMI_DA_OMA_DOWNLOAD)
    {
        mmi_da_app_scr_select_storage(mmi_da_oma_filename_done, (mmi_da_scr_storage_parameter_struct*)param->para, param->arg, srv_da_job_get_title_icon((srv_da_job_struct *)param->arg));    	
    }
#endif
    else
    {
        mmi_da_app_scr_select_storage(srv_da_push_filename_done, (mmi_da_scr_storage_parameter_struct*)param->para, param->arg, srv_da_job_get_title_icon((srv_da_job_struct *)param->arg));
    }
	    return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_set_active_download_confirm_screen(mmi_event_struct *event)
{
    return MMI_RET_OK;
}

void mmi_da_enter_idle_screen_notify(void)  
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_ENTER_IDLE);
    DA_TRACE_FUNC(mmi_da_enter_idle_screen_notify);
#if 0
#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
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
#ifndef __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__
    srv_da_suspend_all_job(SRV_DA_ERROR_BROWSER_CLOSED); 
#endif 

    srv_da_push_enter_idle_screen_callback();

}
U8 mmi_da_launch_ring_buffer_check(void)    
{
#ifndef __MMI_NCENTER_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode())
        return MMI_FALSE;
#endif

    if (srv_da_get_item_to_be_confirm_num() > 0)
    {
        return MMI_TRUE;
    }
#endif //__MMI_NCENTER_SUPPORT__
	return MMI_FALSE;
}
void mmi_da_entry_new_push_ind(void)        
{
#ifndef MMI_DA_PLUTO_SLIM   
    mmi_da_app_notify_new_push();
#endif
}
mmi_ret mmi_da_scr_select_storage_on_dev_plug_out(mmi_event_struct *evt)
{
#ifdef __FS_CARD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:

            for (cntx = mmi_da_get_storage_top(); cntx != NULL; cntx = cntx->next)
            {
                if (cntx->cui_select_drive > 0)
                {
                    if (cntx->cui_filename_editor > 0 &&
                        !srv_da_util_is_drive_available(cntx->param.drv))
                    {
                        /* Go back to select drive screen */
                        cui_filename_editor_close(cntx->cui_filename_editor);
                        cntx->cui_filename_editor = 0;
                    }
                }
            }  
            break;
    }
    
#endif /* __FS_CARD_SUPPORT__ */
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_popup(mmi_event_struct *evnt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_event_struct *evt = (srv_da_popup_event_struct*)evnt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_da_app_show_popup(evt->string_id, evt->cause, evt->type);
    return MMI_RET_OK;
}


extern mmi_ret mmi_da_evt_display_job_list(mmi_event_struct *evnt)
{
	#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 job_list_highlight_index;
	srv_da_job_struct* job;
	srv_da_display_job_list_event_struct *para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //DA_TRACE_FUNC1(mmi_da_display_job_list, 0);
	para = (srv_da_display_job_list_event_struct*)evnt;
	job = para->job;
	
    /*
     * MAUI_01212315: [RACING ISSUE]
     * Receive a WAP_FILE_DL_IND after job is created but not started yet(may be in confirm screen)
     * And the file of WAP_FILE_DL_IND is already in the list, it may try to open
     */
    /* MMI_ASSERT(!g_mmi_da_context.setuping_job); */
    if (srv_da_get_curr_job_in_setuping_state() != NULL)
    {
        /* Another job is in INIT, may be in confirm screen */
        //DA_TRACE_FUNC1(mmi_da_display_job_list, 1);
        return;
    }
    
    srv_da_init_job_list();
    if(!srv_da_get_job_list_num())
        return;
    
    job_list_highlight_index = job ? srv_da_get_job_index(job) : 0;
	mmi_da_set_job_highlight_index(job_list_highlight_index);
    
    mmi_da_app_display_job_list(); 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
#endif    
	
	return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_display_job_detail(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_display_job_detail_event_struct *detail_evt = (srv_da_display_job_detail_event_struct*)evnt;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_da_launch_app(MMI_DA_LAUNCH_FROM_BROWSER);
    mmi_da_display_job_detail(detail_evt->job);
    return MMI_RET_OK;
}

mmi_ret mmi_da_evt_enter_usb_mode(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
 extern mmi_ret mmi_da_evt_update_ncenter (mmi_event_struct *evnt)
{
 #if defined (__MMI_NCENTER_SUPPORT__)  
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 type;  
	srv_da_update_ncenter_event_struct  *evt = (srv_da_update_ncenter_event_struct*)evnt;
	srv_da_job_struct *job = (srv_da_job_struct *)evt->arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	type = evt->type;

    
    if ((evt->type == SRV_DA_JOB_TYPE_PUSH) && (evt->show == MMI_TRUE))
    {
        //srv_da_set_item_in_notifying(evt->arg);
        //VcpDLAgentNCenter::showPushStatus(evt->arg);
        mmi_da_show_push_status(evt->arg);
        mmi_da_show_push_obj_ncenter(evt->arg,type);
    }
    else
    {
    mmi_da_show_ncenter(job, type);
    }
#endif 
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_show_progress(mmi_event_struct *evnt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_show_progressing_event_struct *evt = (srv_da_show_progressing_event_struct*)evnt;
    U16 scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = mmi_da_app_map_action_to_scr(evt->screen_id);
    mmi_da_app_scr_show_progressing(
        scr_id,
        evt->title_string_id,
        evt->title_icon_id,
        evt->message_id,
        evt->cancel_rsk,
        evt->arg,
        evt->cancel_callback);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_popup_message_right_now
 * DESCRIPTION
 *  Popup message for job RIGHT NOW regardless current condition.
 *  NOTE: The message content will be cleaned after popup.
 * PARAMETERS
 *  message     [IN/OUT] Message
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_da_popup_message_right_now(srv_da_popup_message_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   

}
extern mmi_ret mmi_da_evt_popup_error_for_job(mmi_event_struct *evnt)
{
	srv_da_popup_error_for_job_struct *evt = (srv_da_popup_error_for_job_struct *)evnt;
	mmi_da_app_popup_error_for_job(evt->job, evt->type, evt->cause, evt->error_str_id, evt->terminate_job);
	return MMI_RET_OK;



}

extern mmi_ret mmi_da_evt_popup_for_job(mmi_event_struct *evnt)
{
	srv_da_popup_message_for_job_struct *evt = (srv_da_popup_message_for_job_struct *)evnt;
	UI_string_ID_type str_id;
    str_id = mmi_da_app_map_string(evt->error_str_id, 0, evt->type);
	mmi_da_app_popup_for_job (evt->job, evt->type,  (U16*)get_string(str_id), evt->free_string_after_popup, evt->info);
	return MMI_RET_OK;


}

extern mmi_ret mmi_da_evt_popup_for_job_msg(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_for_job_msg_event_struct *evt = (srv_da_popup_for_job_msg_event_struct*)evnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	mmi_da_app_popup_for_job_msg(evt->job, evt->filepath);
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_set_active_select_storage_instance(mmi_event_struct *evnt)
{
	return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_close_processing(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_progressing_close_event_struct *evt = (srv_da_progressing_close_event_struct*)evnt;
    U16 scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = mmi_da_app_map_action_to_scr(evt->screen_id);
    mmi_da_scr_progressing_close(scr_id);
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_popup_error_code_with_callback(mmi_event_struct *evnt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_for_error_code_event_struct *evt = (srv_da_popup_for_error_code_event_struct*)evnt;
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->error_code)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    case SRV_DA_IERROR_EXCEED_MAX_JOB:
        string_id = STR_ID_DA_PROMPT_EXCEED_MAX_JOB;
        break;
    case SRV_DA_IERROR_EXCEED_MAX_DL:
        string_id = STR_ID_DA_PROMPT_EXCEED_MAX_DL;
        break;
    case SRV_DA_IERROR_ANOTHER_JOB:
        string_id = STR_ID_DA_JOB_EXIST;
        break;
#endif
    default:
        string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
        break;
    }
    mmi_da_app_show_popup_with_callback(string_id, evt->callback);
    return MMI_RET_OK;
}


extern mmi_ret mmi_da_evt_wps_http_rsp_callback(mmi_event_struct *evnt)
{
#ifdef __MMI_DA_RESUME__
#ifdef  __MMI_DOWNLOAD_AGENT_MULTI_DL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_wps_http_response_event_struct *evt = (srv_da_wps_http_response_event_struct*)evnt;
    MMI_BOOL enter_job_list;
    srv_da_job_struct *job;
    srv_da_normal_dl_job_struct *job_data;
    MMI_BOOL is_resume;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)evt->job;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    is_resume = (job_data->curr_size > 0);
    if(evt->is_error)
    {

    }
    else
    {
        enter_job_list = (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_PLEASE_WAIT) ? MMI_TRUE : MMI_FALSE;        
    #ifdef MMI_DA_WLAN_PREFER_SUPPORT
        {
            MMI_BOOL                    is_deleted = MMI_FALSE;
            is_deleted = mmi_da_scr_progressing_close(SCR_ID_DA_DOWNLOAD_PLEASE_WAIT);
            while (is_deleted)
            {
                is_deleted = mmi_da_scr_progressing_close(SCR_ID_DA_DOWNLOAD_PLEASE_WAIT);
            }
        }
    #else   
        mmi_da_scr_progressing_close(SCR_ID_DA_DOWNLOAD_PLEASE_WAIT);
    #endif /* MMI_DA_WLAN_PREFER_SUPPORT */
        if(enter_job_list)
        {
    #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            if(job->setting_info.can_minimize)
            {
                /* bring up list screen */
                mmi_da_app_display_job_list(job, MMI_FALSE);
            }
            else
    #endif        
            {
                /* directly go to job detail */
                mmi_da_app_show_job_detail();
            }
        }

        if (is_resume && evt->status == 200)
        {
            /* 200 Ok: Resume is not supported by server; otherwise, it would be 206 Partial Content */
            
            if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_LIST || mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_DETAIL)
            {
                mmi_da_app_show_popup_ext(STR_ID_DA_PROMPT_RESUME_NOT_SUPPORTED_BY_SERVER, SRV_DA_POPUP_TYPE_INFO);
            }
        }                
    }
#endif 
#endif
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_oma_handle_http_rsp(mmi_event_struct *event)
{
    return MMI_RET_OK;
}
#ifndef MMI_DA_PLUTO_SLIM
extern void mmi_da_oma_show_auth_screen(void *arg);
extern void mmi_da_oma_show_auth_screen_delete_hdlr(void *arg);
#endif
extern mmi_ret mmi_da_evt_show_user_auth_screen(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef MMI_DA_PLUTO_SLIM
    srv_da_show_user_auth_event_struct  *evt = (srv_da_show_user_auth_event_struct*)evnt;
    srv_da_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)evt->arg;
    if(job->state == SRV_DA_JOB_STATE_PAUSED || job->state == SRV_DA_JOB_STATE_RESUMING)
    {
        mmi_da_scr_user_auth(evt->auth_callback, (U32)job, srv_da_job_get_title_icon(job));
    }
    else
    {
    #ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
        if(job->dl_flag & DA_DL_FLAG_SKIP_CONFIRM)
        {
            /* No "Please wait" screen, show directly */
            mmi_da_scr_user_auth(evt->auth_callback, (U32)job, srv_da_job_get_title_icon(job));
        }
        else
    #endif
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_PLEASE_WAIT)
            {
                mmi_da_scr_user_auth(evt->auth_callback, (U32)job, srv_da_job_get_title_icon(job));
            }
            else /* Be interrupted */
            {
                mmi_da_show_user_auth_struct *auth_data;
                auth_data = (mmi_da_show_user_auth_struct*)OslMalloc(sizeof(mmi_da_show_user_auth_struct));
                auth_data->arg = (U32)job;
                auth_data->auth_callback = evt->auth_callback;
                if (mmi_da_scr_trigger_when_enter_ext(SCR_ID_DA_DOWNLOAD_PLEASE_WAIT, mmi_da_oma_show_auth_screen, mmi_da_oma_show_auth_screen_delete_hdlr, auth_data))
                {
                    /* Auth screen will be shown after interrupt */
                }
                else
                {
                    evt->auth_callback((U32)job, NULL, NULL);
                }
            }
        }
    }
#endif
    return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_push_process_item(mmi_event_struct *event)
{
    return MMI_RET_OK;
}



extern mmi_ret mmi_da_evt_update_job_status(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_item_progress_struct info;
    srv_da_job_struct           *job;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_update_job_event_struct    *evt = (srv_da_update_job_event_struct*)evnt;
    job = (srv_da_job_struct*)evt->job;
    MMI_ASSERT(job);
    mmi_da_handle_job_status_updates(job);
    return MMI_RET_OK;
}


extern mmi_ret mmi_da_job_drm_save_as(mmi_event_struct *evnt)
{
#ifdef __DRM_SUPPORT__
    srv_da_drm_save_as_event_struct  *evt = (srv_da_drm_save_as_event_struct*)evnt;
    mmi_da_app_job_drm_save_as(evt->job, evt->drm_method);
#endif
	return MMI_RET_OK;
}

extern mmi_ret mmi_da_update_content_by_drm_processing(mmi_event_struct *evnt)
{
	return MMI_RET_OK;
}


extern mmi_ret mmi_da_evt_click_job(mmi_event_struct *evnt)
{
    srv_da_push_process_event_struct  *evt = (srv_da_push_process_event_struct*)evnt;
    srv_da_push_async_move_arg_struct *async_arg = (srv_da_push_async_move_arg_struct*)evt->arg;
    mmi_da_app_handle_push_process(evt->error_code, async_arg);
	return MMI_RET_OK;
}

extern mmi_ret mmi_da_evt_job_aborted_callback(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_curr_job_aborted_event_struct *evt = (srv_da_curr_job_aborted_event_struct*)evnt;
    srv_da_job_struct *job = evt->job;
    U16 string_id = evt->string_id; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_ABORTED);
    
    if((mmi_da_app_is_in_foreground_state() || mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_PLEASE_WAIT) &&
        !job->reporting)
    {
        if(string_id == 0)
        {
            string_id = STR_ID_DA_CANCELLED;
        }
        mmi_da_app_show_popup_ext(string_id, SRV_DA_POPUP_TYPE_DONE);
    }

    mmi_da_scr_progressing_close(SCR_ID_DA_DOWNLOAD_PLEASE_WAIT);
	mmi_da_scr_remove_screen(SCR_ID_DA_JOB_DETAIL);
    srv_da_update_job_status(job);    

    return MMI_RET_OK;
}
extern void mmi_da_remove_job_screens(srv_da_job_struct *, MMI_BOOL, S32);
extern mmi_ret mmi_da_evt_remove_job_screen(mmi_event_struct *event)
{
    srv_da_remove_scr_event_struct *evt = (srv_da_remove_scr_event_struct*)event;
    mmi_da_remove_job_screens(evt->job, evt->is_in_job_screen, evt->index);
    return MMI_RET_OK;
}
//TODO 
extern void mmi_da_app_close_all_screens(void);
extern mmi_ret mmi_da_evt_close_app(mmi_event_struct* para)
{
#if defined(BROWSER_SUPPORT)
    mmi_da_app_close_all_screens();
#endif
    return MMI_RET_OK;
}
extern mmi_ret mmi_da_evt_usb_available(mmi_event_struct* para)
{
#ifdef __MMI_USB_SUPPORT__
    mmi_usb_app_unavailable_popup(0);
#endif
    return MMI_RET_OK;
}
#endif // #ifdef __MMI_DOWNLOAD_AGENT__
