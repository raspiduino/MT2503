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
 
 
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)
#include "mmi_frm_events_gprot.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
#include "DLAgentSrvIProt.h"
#include "DLAgentAppScr.h"
#if defined (__MMI_NCENTER_SUPPORT__)
#include "DLAgentAppNcenter.h"
#endif
#include "DLAgentSrvProt.h"
#include "DLAgentSrvOMA.h"
#include "DLAgentSrvWPS.h"
#include "DLAgentSrvMREProts.h"

#include "Menucuigprot.h"
#include "InlineCuiGprot.h"

    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_history_gprot.h"
    #include "UcmSrvGprot.h"
    #include "AlertScreen.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_public_api.h"
    #include "wgui.h"
    #include "wgui_categories_util.h"
    #include "DebugInitDef_Int.h"
    #include "string.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "mmi_rp_app_downloadagent_def.h"
    #include "mmi_rp_srv_downloadagent_def.h" //timers
    #include "GlobalResDef.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "fs_errcode.h"
    #include "CommonScreensResDef.h"
    #include "ImeGprot.h"
    #include "wgui_categories_popup.h"
    #include "custom_events_notify.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories.h"
    #include "wgui_categories_text_viewer.h"
    #include "mmi_res_range_def.h"
    #include "gui_typedef.h"
    #include "RightsMgrGProt.h"
#include "cbm_consts.h"
 #include "cbm_api.h"
#include "CbmSrvGprot.h"
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
#include "CbmCuiGprot.h"
#include "custom_data_account.h"
#endif /* MMI_DA_WLAN_PREFER_SUPPORT */

#define DA_SHOW_INFO(dst, format, tag_src, value_src) \
    kal_wsprintf((unsigned short*)(dst + mmi_ucs2strlen((S8*)dst)),(format),(tag_src), (value_src))
#define DA_GET_STRING(str_src) \
    (str_src == NULL || mmi_ucs2strlen(str_src) == 0) ? GetString(STR_ID_DA_PROMPT_UNKNOWN) : (str_src)



extern MMI_BOOL mmi_da_app_get_job_list_dirty_flag(void); //handle this
#if defined (__MMI_OMA_DD_DOWNLOAD__)
U32  mmi_da_oma_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_omadl_job_struct *job_data;
    U32 secs;
    U32 progress;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_OMADL);
    job_data = (srv_da_omadl_job_struct*)job->data_ptr;

    if(job->state == SRV_DA_JOB_STATE_PROCESSING)
    {
        switch (job_data->oma_state)
        {
            case SRV_DA_OMA_STATE_DOWNLOADING_ICON:
                info->processing_string_id = STR_ID_DA_OMA_DOWNLOADING_ICON;
                break;
            case SRV_DA_OMA_STATE_SENDING_INSTALL_NOTIFICATION:
                info->processing_string_id = STR_ID_DA_OMA_SEND_REPORT;
                break;
            default:
                info->processing_string_id = 0;
                break;
        }
    }
    else
    {
        info->processing_string_id = 0;
    }
}
#endif 
void mmi_da_abot_callback (srv_da_job_struct* job, U16 string_id)
{
    if (job->reporting)
    {
        srv_da_item_progress_struct info;
#if defined (__MMI_OMA_DD_DOWNLOAD__)
		if (job->type == SRV_DA_JOB_TYPE_OMADL)
			mmi_da_oma_get_item_progress(job, &info);
		else
#endif
		{
			info.processing_string_id = 0;
			
		}
		DA_JOB_GET_PROGRESS(job, info);
      
srv_da_report_to_app(job, &info);   //slim

    }
    srv_da_update_job_status (job);
}

void mmi_da_abort_all_downloading_jobs (void)
{
    srv_da_job_struct *job = NULL;

    job = (srv_da_job_struct *)srv_da_get_first_job();
    while (job)
    {
        if (job->state == SRV_DA_JOB_STATE_DOWNLOADING)
        {
            job->state = SRV_DA_JOB_STATE_ABORTING;
            job->was_stopped_by_upper_layer = MMI_TRUE;
            srv_da_stop_selected_job (job, SRV_DA_JOB_STATE_DOWNLOADING, MMI_TRUE, mmi_da_abot_callback);
            /* free job directly */
        }
        job = job->next_job;
    }
}
/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_da_display_job_detail(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //DA_TRACE_FUNC1(mmi_da_display_job_detail, 0);

    /*
     * MAUI_01212315: [RACING ISSUE]
     * Receive a WAP_FILE_DL_IND after job is created but not started yet(may be in confirm screen)
     * And the file of WAP_FILE_DL_IND is already in the list, it may try to open
     */
    //MMI_ASSERT(!srv_da_get_curr_job_in_setuping_state());
    if (!srv_da_can_receive_file())
    {
        return;
    }
    if (srv_da_get_curr_job_in_setuping_state() != NULL)
    {
        /* Another job is in INIT, may be in confirm screen */
        //DA_TRACE_FUNC1(mmi_da_display_job_detail, 1);
        return;
    }
    
    srv_da_init_job_list();

    if (SRV_DA_FILESTAMP_CHECK_OK == mmi_da_app_job_check_filestamp(job, NULL))
    {
        srv_da_set_curr_job(job);        
        mmi_da_entry_job_detail(); 
        mmi_da_check_presence_and_close_screen(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_OBJECT_DESCRIPTION);       
        //mmi_da_check_presence_and_close_screen(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_DETAIL);
    }
    else
    {
        mmi_da_app_show_popup_ext(STR_ID_DA_ERROR_FILE_MISMATCH, SRV_DA_POPUP_TYPE_ERROR);
        srv_da_free_job_and_remove_screens(job);
    }
}

void mmi_da_app_init(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8 buf_createpath[128];
    //int i;
#if defined(__MMI_DA_WPS_UTIL__) && defined(__HTTP_INTERFACE__)
	cbm_app_info_struct app_info;
	U8 ret_code;
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
	U8 cbm_app_id1;
	U8 cbm_app_id2;
#else
	U8 cbm_app_id;
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
extern void mmi_da_app_scr_init(void);
    /* init */
    mmi_da_app_scr_init();
    srv_da_adp_init();
#if defined(__MMI_DA_WPS_UTIL__) && defined(__HTTP_INTERFACE__)
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    app_info.app_str_id = STR_GLOBAL_DOWNLOAD;
    app_info.app_type = 0;
	cbm_app_id1 = srv_da_wps_get_cbm_id(SRV_DA_CBM_APP_ID1);
    cbm_register_app_id_with_app_info(&app_info, &cbm_app_id1);

     srv_da_wps_set_cbm_id(SRV_DA_CBM_APP_ID1, cbm_app_id1);

	srv_da_wps_register_bearer_fallback(cbm_app_id1);

    ret_code = srv_cbm_register_bearer_info(
        cbm_app_id1,
        SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
        srv_da_wps_nwk_fsm_bearer_info_ind, NULL);

	
    srv_da_wps_register_bearer_fallback(cbm_app_id1);

    app_info.app_icon_id = IMG_GLOBAL_COMMON_CSK;
    app_info.app_type |= DTCNT_APPTYPE_SPECIFIC_PROFILE;
	cbm_app_id2 = srv_da_wps_get_cbm_id(SRV_DA_CBM_APP_ID2);
    cbm_register_app_id_with_app_info(&app_info, &cbm_app_id2);
	srv_da_wps_set_cbm_id(SRV_DA_CBM_APP_ID2, cbm_app_id2);   

		srv_da_wps_register_bearer_fallback(cbm_app_id2);

    ret_code = srv_cbm_register_bearer_info(
        cbm_app_id2,
        SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
        srv_da_wps_nwk_fsm_bearer_info_ind, NULL);

	
    srv_da_wps_register_bearer_fallback(cbm_app_id2);


#else

	
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    app_info.app_str_id = STR_GLOBAL_DOWNLOAD;
    app_info.app_type = 0;
	cbm_app_id = srv_da_wps_get_cbm_id(SRV_DA_CBM_APP_ID_NONE);
    cbm_register_app_id_with_app_info(&app_info, &cbm_app_id);
	srv_da_wps_set_cbm_id(SRV_DA_CBM_APP_ID1, cbm_app_id);   
	ret_code = srv_cbm_register_bearer_info(
        cbm_app_id,
        SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
        srv_da_wps_nwk_fsm_bearer_info_ind, NULL);
    
#ifdef __CBM_BEARER_FALLBACK__
    srv_da_wps_register_bearer_fallback(srv_da_wps_context.cbm_app_id);
#endif

#endif /* MMI_DA_WLAN_PREFER_SUPPORT */
#endif //
//#endif
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
#endif //0
}

//TODO
extern void mmi_da_update_timer_handler(void* param);
void mmi_da_handle_job_status_updates(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_item_progress_struct info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_OMA_DD_DOWNLOAD__)
   if (job->type == SRV_DA_JOB_TYPE_OMADL)
			mmi_da_oma_get_item_progress(job, &info);
	else
#endif
		{
			info.processing_string_id = 0;

		}
    //DA_TRACE_FUNC3(mmi_da_update_job_status, DA_JOB_UNIQUE_ID(job), job->state, info.currSize);
	DA_JOB_GET_PROGRESS(job, info);
    if (job->reporting)
    {
    
srv_da_report_to_app(job, &info);   //slim
  
    }

    srv_da_send_download_info_ind();

    switch(job->state)
    {
    case SRV_DA_JOB_STATE_PROCESSING:
        /* Update now */
        if( mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_LIST ||
            (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_DETAIL && srv_da_get_curr_job() == job))
        {
            mmi_da_app_update_job_list_dirty_flag(MMI_TRUE);
            mmi_da_update_timer_handler((void*)job);
        }
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        if (mmi_da_is_job_list_option_on_top() &&
          srv_da_get_job_index(job) == mmi_da_get_job_highlight_index())
        {
            mmi_da_close_job_list_option();
        }
#endif
#if defined (__MMI_NCENTER_SUPPORT__)
if (job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
		mmi_da_update_all_cells((srv_da_job_struct*)job);
#endif
        break;
        
    case SRV_DA_JOB_STATE_DOWNLOADING:
        if( mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_LIST ||
            (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_DETAIL && srv_da_get_curr_job() == job))
        {
            // trigger a timer to refresh, 
            // use a dirty flag to mask sure only 1 timer is activated.
            if(!mmi_da_app_get_job_list_dirty_flag())
            {
                mmi_da_app_update_job_list_dirty_flag(MMI_TRUE);
                StartTimerEx(SRV_DA_TIMER_UPDATE_STATUS, 500, mmi_da_update_timer_handler, (void*)job);
            }
        }
#if defined (__MMI_NCENTER_SUPPORT__)
if (job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
		mmi_da_update_all_cells((srv_da_job_struct*)job);
#endif
        break;

    case SRV_DA_JOB_STATE_PAUSED:
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
#ifdef __MMI_DA_RESUME__
        srv_da_job_make_filestamp((srv_da_job_struct*)job);
        
        if (mmi_da_app_get_job_list_dirty_flag())
        {
            StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
        }
        
        mmi_da_app_update_job_list_dirty_flag(MMI_TRUE);
        mmi_da_update_timer_handler((void*)job);

        mmi_da_close_job_list_option();

        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_ABORT_CONFIRM)
        {
            if (srv_da_get_curr_job() == job)
            {
                mmi_frm_scrn_close_active_id();
            }
        }
#endif /* __MMI_DA_RESUME__ */
#if defined (__MMI_NCENTER_SUPPORT__)
		//mmi_da_update_all_cells((srv_da_job_struct*)job);
        if (job->notify_handle != NULL)
		vsrv_ncenter_close_notification(job->notify_handle);
#endif
if (job->reporting)
    {
        job->reporting = MMI_FALSE;
    }
#else
        // Should not enter paused state
        MMI_ASSERT(0);
#endif

        break;

    case SRV_DA_JOB_STATE_COMPLETED:
        
        srv_da_job_make_filestamp((srv_da_job_struct*)job);
        
        /* Force refresh */
        if(mmi_da_app_get_job_list_dirty_flag())
            StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
        mmi_da_app_update_job_list_dirty_flag(MMI_TRUE);
        mmi_da_update_timer_handler((void*)job);
#if defined (__MMI_NCENTER_SUPPORT__)
if (job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
{
		mmi_da_show_job_status((srv_da_job_struct*)job);
		mmi_da_update_completed_cells((srv_da_job_struct*)job);
}
#endif
if (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
{

        if (srv_da_dispatch_http_job(job))
		{
			job->op->dispatch(job);
			srv_da_free_job_and_remove_screens(job);
			srv_da_send_download_info_ind();
			return;
		}
}
		
        mmi_da_job_complete(job);


        return;

    case SRV_DA_JOB_STATE_FAILED:

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        mmi_da_close_job_list_option();
#endif

        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_ABORT_CONFIRM)
        {
            if (srv_da_get_curr_job() == job)
            {
                mmi_frm_scrn_close_active_id();
            }
        }

#ifndef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        //if(!IsScreenPresent(SCR_ID_DA_JOB_DETAIL) && !IsScreenPresent(SCR_ID_DA_JOB_OBJECT_DESCRIPTION))
        if(!mmi_frm_scrn_is_present(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_DETAIL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)
            && !mmi_frm_scrn_is_present(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_OBJECT_DESCRIPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))    
        {
            srv_da_free_job_and_remove_screens((srv_da_job_struct*)job);
        }
#endif                
#if defined (__MMI_NCENTER_SUPPORT__)		
		mmi_da_show_job_status((srv_da_job_struct*)job);  //Ncenter
		mmi_da_update_failed_cells((srv_da_job_struct*)job);
#endif
        return;

    case SRV_DA_JOB_STATE_ABORTED:
        // clean up.
        #if defined (__MMI_NCENTER_SUPPORT__)
		//mmi_da_update_all_cells((srv_da_job_struct*)job);
        if (job->notify_handle != NULL)
		vsrv_ncenter_close_notification(job->notify_handle);
        mmi_da_update_statusbar();
        #endif
        srv_da_free_job_and_remove_screens((srv_da_job_struct*)job);
        return;

    case SRV_DA_JOB_STATE_ABORTING:
        /* the only case will run into here is:
            1. the report handler aborted the job 
        */
        MMI_ASSERT(job->setting_info.report_hdlr);
        return;

    default:
        MMI_ASSERT(0); // not handled
        return;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_check_file_before_operation
 * DESCRIPTION
 *  Check the integrality of file. If file is changed or corrupted unexpectedly,
 *  this function pops an message to user and may remove the job directly.
 * PARAMETERS
 *  job     [IN] Target job
 * RETURNS
 *  mmi_da_job_filestamp_enum
 *****************************************************************************/
srv_da_job_filestamp_enum mmi_da_job_check_file_before_operation(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_id;
    srv_da_job_filestamp_enum check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_result = mmi_da_app_job_check_filestamp(job, &error_id);
    
    if (check_result != SRV_DA_FILESTAMP_CHECK_OK)
    {
        mmi_da_app_show_popup_ext(error_id, SRV_DA_POPUP_TYPE_ERROR);

        if (check_result == SRV_DA_FILESTAMP_CHECK_FAIL)
        {
#if defined (__MMI_NCENTER_SUPPORT__) 
            mmi_da_update_statusbar();
#endif
            srv_da_free_job_and_remove_screens(job);
        }
    }

    return check_result;
}
#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_drm_show_process_info
 * DESCRIPTION
 *  Call DRM API to popup proper message.
 * PARAMETERS
 *  result      [IN] Process result
 *  mime_type   [IN] Result MIME type
 *  info        [IN] Additional information of DRM result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_drm_show_process_info(
    S32 result,
    const applib_mime_type_struct *mime_type,
    const srv_da_drm_result_info_struct *info,
    srv_da_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rmgr_src_enum rmgr_src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    rmgr_src = MMI_RMGR_SRC_SAVE_AS;

    switch (action)
    {
        case MMI_DA_PUSH:
        case MMI_DA_PUSH_SIM2:
        case MMI_DA_PUSH_SIM3:
        case MMI_DA_PUSH_SIM4:
            rmgr_src = MMI_RMGR_SRC_PUSH;
            break;

        case MMI_DA_WAP_DOWNLOAD:
        case MMI_DA_OMA_DOWNLOAD:
            rmgr_src = MMI_RMGR_SRC_WAP_DOWNLOAD;
            break;

        case MMI_DA_SAVE_AS:
            rmgr_src = MMI_RMGR_SRC_SAVE_AS;
            break;

        default:
            break;
    }
    
    srv_rmgr_show_process_info(result, info->waiting, rmgr_src, (applib_mime_type_struct*)mime_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_drm_dispatch
 * DESCRIPTION
 *  Dispatch the DRM-processed file
 * PARAMETERS
 *  arg         [IN] (mmi_da_job_struct*)Job
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_drm_dispatch(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;

    if(!job->setting_info.do_dispatch || !job->type_handler->dispatch_hdlr)
    {
        mmi_da_app_show_popup_ext(STR_GLOBAL_SAVED, SRV_DA_POPUP_TYPE_SAVED);
        srv_da_free_job_and_remove_screens(job);
    }
    else if(job->setting_info.confirm_dispatch)
    {
        srv_da_set_curr_job(job);
        mmi_da_curr_job_entry_dispatch_confirm();
    }
    else
    {
        job->op->dispatch(job);
        srv_da_free_job_and_remove_screens(job);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_drm_async_save_as_result_callback
 * DESCRIPTION
 *  Result callback of saving DRM-processed file
 * PARAMETERS
 *  arg         [IN] (mmi_da_job_struct*)Job
 *  error_code  [IN] FS error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_drm_async_save_as_result_callback(void *arg, S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_async_move_arg_struct *async_move_arg;
    srv_da_job_struct *job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_move_arg = (srv_da_job_async_move_arg_struct*)arg;
    job = async_move_arg->job;

    if (error_code == FS_NO_ERROR)
    {
        if(DRM_is_drm_file(0, (kal_wchar*)async_move_arg->dest_path))
        {
            DRM_register_file((kal_wchar*)async_move_arg->dest_path);
        }

        /* Assign the new path */
        job->op->assign_filepath(job, async_move_arg->dest_path);
    
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_MOVING)
        {
            mmi_da_job_drm_dispatch(job);
        }
        else
        {
            mmi_da_scr_trigger_when_enter(SCR_ID_DA_DOWNLOAD_MOVING, mmi_da_job_drm_dispatch, job);
        }
        
        mmi_da_app_select_storage_async_acceptance(
            async_move_arg->select_storage_instance,
            SRV_DA_ACCEPTANCE_ACCEPT);
        mmi_da_set_active_select_storage_instance(NULL);
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_MOVING)
        {
            mmi_da_app_show_popup_ext(srv_fmgr_fs_error_get_string(error_code), SRV_DA_POPUP_TYPE_ERROR);
        }


        if (async_move_arg->can_reject)
        {
            mmi_da_app_select_storage_async_acceptance(
                async_move_arg->select_storage_instance,
                SRV_DA_ACCEPTANCE_REJECT);
        }
        else
        {
            srv_da_free_job_and_remove_screens(job);
            mmi_da_app_select_storage_async_acceptance(
                async_move_arg->select_storage_instance,
                SRV_DA_ACCEPTANCE_ACCEPT);
            mmi_da_set_active_select_storage_instance(NULL);
        }
    }

    OslMfree(async_move_arg->dest_path);
    OslMfree(async_move_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_drm_async_save_as_cancel_callback
 * DESCRIPTION
 *  Cancel callback of cancelling saving DRM-processed file
 * PARAMETERS
 *  arg         [IN] (mmi_da_job_struct*)Job
 *  is_deleted  [IN] In deleting callback context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_drm_async_save_as_cancel_callback(void *arg, MMI_BOOL is_deleted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_async_move_arg_struct *async_move_arg;
    srv_da_job_struct *job;
    const U16 *filepath;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_move_arg = (srv_da_job_async_move_arg_struct*)arg;
    job = async_move_arg->job;

    if (!is_deleted)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_MOVING)
        {
            mmi_da_app_show_popup_ext(STR_ID_DA_CANCELLED, SRV_DA_POPUP_TYPE_DONE);
        }

        mmi_da_app_select_storage_async_acceptance(
            async_move_arg->select_storage_instance,
            SRV_DA_ACCEPTANCE_ACCEPT);
    }

    filepath = job->op->get_filepath(job);
    if (filepath != NULL)
    {
        srv_da_util_file_delete(filepath);
    }
    srv_da_free_job_and_remove_screens(async_move_arg->job);

    OslMfree(async_move_arg->dest_path);
    OslMfree(async_move_arg);

    mmi_da_set_active_select_storage_instance(NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_drm_save_as_select_storage_callback
 * DESCRIPTION
 *  Result of select-storage to save DRM result
 * PARAMETERS
 *  criteria        [IN] (mmi_da_job_struct*)Job
 *  filepath        [IN] The filepath user selected, NULL if not selected
 *  canback         [IN] Can reject the selection
 *  canpopup        [IN] Popup is allowed
 *  instance        [IN] Instance of select-storage
 * RETURNS
 *  Acceptance
 *****************************************************************************/
static srv_da_acceptance_enum mmi_da_job_drm_save_as_select_storage_callback(
    U32 criteria,
    U16* filepath,
    MMI_BOOL canback,
    MMI_BOOL canpopup,
    void *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    srv_da_job_async_move_arg_struct *async_move_arg;
    const U16 *src_filepath;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)criteria;

    src_filepath = job->op->get_filepath(job);
    
    if (filepath == NULL)
    {
        /* Cancel to save */
        srv_da_util_file_delete(src_filepath);
        srv_da_free_job_and_remove_screens(job);
        mmi_da_set_active_select_storage_instance(NULL);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }

    if (mmi_wcscmp(src_filepath, filepath) == 0)
    {
        mmi_da_job_drm_dispatch(job);
        mmi_da_set_active_select_storage_instance(NULL);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }

    async_move_arg = (srv_da_job_async_move_arg_struct*)OslMalloc(sizeof(srv_da_job_async_move_arg_struct));
    async_move_arg->job = job;
    async_move_arg->dest_path = (U16*)OslMalloc((mmi_wcslen(filepath) + 1) * sizeof(U16));
    mmi_wcscpy(async_move_arg->dest_path, filepath);
    async_move_arg->select_storage_instance = instance;
    async_move_arg->can_reject = canback;
//#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__  

    mmi_da_app_async_move(
        SCR_ID_DA_DOWNLOAD_MOVING,
        STR_GLOBAL_SAVING,
        mmi_da_job_get_title_icon(job),
        src_filepath,
        filepath,
        MMI_FALSE,
        async_move_arg,
        mmi_da_job_drm_async_save_as_result_callback,
        mmi_da_job_drm_async_save_as_cancel_callback);
 //#endif   
    return SRV_DA_ACCEPTANCE_ASYNC;
}
//TODO
extern void* mmi_da_app_scr_select_storage(mmi_da_scr_storage_callback_type callback,
    mmi_da_scr_storage_parameter_struct* parameter,
    U32 arg,
    U16 title_icon_id);
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_drm_save_as_do_select_storage
 * DESCRIPTION
 *  Call select-storage module to decide storage and filename.
 * PARAMETERS
 *  arg         [IN] (mmi_da_job_struct*)Job
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_drm_save_as_do_select_storage(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    mmi_da_scr_storage_parameter_struct *storage_para;
    srv_da_setting_struct *setting;
    const U16 *filepath;
    void *select_storage_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    
    storage_para = (mmi_da_scr_storage_parameter_struct*)OslMalloc(sizeof(mmi_da_scr_storage_parameter_struct));

    memset(storage_para, 0, sizeof(mmi_da_scr_storage_parameter_struct));

    filepath = job->op->get_filepath(job);

    storage_para->storage = SRV_DA_STORAGE_USER_SELECT;
    storage_para->drv = (S32)filepath[0];

    srv_da_extract_filepath((U16*)filepath, storage_para->filename, storage_para->fileext);
    
    setting = srv_da_get_setting_buffer();
    job->op->get_setting(job, setting);
    srv_da_copy_setting(job, setting);
    mmi_wcscpy(storage_para->folder, setting->folder);
    
    storage_para->filesize = srv_da_util_get_file_size((U16*)filepath);
    storage_para->original_filepath = filepath;
    storage_para->filecheck_func = srv_da_does_job_with_filepath_exist;
    
#ifdef MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD
    storage_para->select_storage = MMI_TRUE;
#else
    storage_para->select_storage = MMI_FALSE;
#endif

#ifdef MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD
    storage_para->select_filename = MMI_TRUE;
#else
    storage_para->select_filename = MMI_FALSE;
#endif
    
    storage_para->skip_exist_check = MMI_FALSE;

    select_storage_instance = mmi_da_app_scr_select_storage(
        mmi_da_job_drm_save_as_select_storage_callback,
        storage_para,
        (U32)job,
        srv_da_job_get_title_icon(job));

    mmi_da_set_active_select_storage_instance(select_storage_instance);

    OslMfree(storage_para);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_job_drm_save_as
 * DESCRIPTION
 *  Show Save screen to save the result of DRM processing.
 * PARAMETERS
 *  job         [IN] Job
 *  drm_method  [IN] Method of the DRM object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_job_drm_save_as(srv_da_job_struct *job, drm_method_enum drm_method)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD) || defined(MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD)

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_DETAIL ||
        mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_OBJECT_DESCRIPTION)
    {
        mmi_da_job_drm_save_as_do_select_storage(job);
    }
    else
    {   
        mmi_da_check_presence_and_close_screen(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_OBJECT_DESCRIPTION);    
        if (mmi_da_scr_trigger_when_enter(SCR_ID_DA_JOB_DETAIL, mmi_da_job_drm_save_as_do_select_storage, job))
        {
            /* Ok. Wait for mmi_da_job_drm_save_as_do_select_storage be triggered. */
        }
        else
        {
            srv_da_free_job_and_remove_screens(job);
        }
    }

#else /* defined(MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD) || defined(MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD) */

    mmi_da_job_drm_dispatch(job);

#endif /* defined(MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD) || defined(MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD) */
}
#endif

/*****************************************************************************
 * [Trigger-when-enter API]
 *
 * If some event happens during interrupt, it is unsuitable to show screens.
 * This API provides a mechanism to trigger client's procedure after the end of
 * interrupt. This utility can only be used during some screen is in history.
 *****************************************************************************/

#define TRIGGER_WHEN_ENTER


/****************************************************************************
 * Configuration
 ****************************************************************************/



/****************************************************************************
 * Global Variable
 ****************************************************************************/
//TODO make this static
mmi_da_scr_trigger_when_enter_context_struct g_mmi_da_scr_trigger_when_enter_cntx;


/****************************************************************************
 * Private Functions
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_init
 * DESCRIPTION
 *  Initialize the utility of trigger-when-enter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_trigger_when_enter_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_trigger_when_enter_context_struct *g_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cntx = &g_mmi_da_scr_trigger_when_enter_cntx;
    
    g_cntx->top_dummy = NULL;

    g_cntx->free_screen[0] = SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_0;
    g_cntx->free_screen[1] = SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_1;
    g_cntx->free_screen[2] = SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_2;
    g_cntx->free_screen[3] = SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_3;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_allocate_screen
 * DESCRIPTION
 *  Allocate a dummy screen ID for a trigger-when-enter instance.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_da_scr_trigger_when_enter_allocate_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    screen_id = 0;

    for (i = 0; i < MMI_DA_SCR_TRIGGER_WHEN_ENTER_MAX_INSTANCES_NUM; i++)
    {
        screen_id = g_mmi_da_scr_trigger_when_enter_cntx.free_screen[i];
        
        if (screen_id != 0)
        {
            g_mmi_da_scr_trigger_when_enter_cntx.free_screen[i] = 0;
            break;
        }
    }

    MMI_ASSERT(screen_id != 0);

    return screen_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_free_screen
 * DESCRIPTION
 *  Free screen resource.
 * PARAMETERS
 *  screen_id   [IN] Dummy screen ID to be freed.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_trigger_when_enter_free_screen(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_DA_SCR_TRIGGER_WHEN_ENTER_MAX_INSTANCES_NUM; i++)
    {
        if (g_mmi_da_scr_trigger_when_enter_cntx.free_screen[i] == 0)
        {
            g_mmi_da_scr_trigger_when_enter_cntx.free_screen[i] = screen_id;
            break;
        }
    }

    MMI_ASSERT(i < MMI_DA_SCR_TRIGGER_WHEN_ENTER_MAX_INSTANCES_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_allocate_instance
 * DESCRIPTION
 *  Allocate an instance for trigger-when-enter procedure.
 * PARAMETERS
 *  void
 * RETURNS
 *  An instance.
 *****************************************************************************/
static mmi_da_scr_trigger_when_enter_inst_struct*
        mmi_da_scr_trigger_when_enter_allocate_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    top_dummy = (mmi_da_scr_trigger_when_enter_inst_struct*)OslMalloc(sizeof(mmi_da_scr_trigger_when_enter_inst_struct));
    top_dummy->next = g_mmi_da_scr_trigger_when_enter_cntx.top_dummy;
    g_mmi_da_scr_trigger_when_enter_cntx.top_dummy = top_dummy;

    return top_dummy;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_free_instance
 * DESCRIPTION
 *  Free the instance.
 * PARAMETERS
 *  top_dummy   [IN] The top instance to be freed.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_scr_trigger_when_enter_free_instance(
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(top_dummy == g_mmi_da_scr_trigger_when_enter_cntx.top_dummy);
    
    g_mmi_da_scr_trigger_when_enter_cntx.top_dummy = top_dummy->next;
    mmi_da_scr_trigger_when_enter_free_screen(top_dummy->screen_id);
    OslMfree(top_dummy);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_delete_dummy
 * DESCRIPTION
 *  Delete handler for the dummy screens of trigger-when-enter.
 * PARAMETERS
 *  unused      [IN] Unused.
 * RETURNS
 *  MMI_TRUE(Can not be deleted)
 *****************************************************************************/
U8 mmi_da_scr_trigger_when_enter_delete_dummy(void *unused)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    top_dummy = g_mmi_da_scr_trigger_when_enter_cntx.top_dummy;

    MMI_ASSERT(top_dummy != NULL);

    if (top_dummy->delete_callback != NULL)
    {
        top_dummy->delete_callback(top_dummy->arg);
        mmi_da_scr_trigger_when_enter_free_instance(top_dummy);
        return (U8)MMI_FALSE; /* Deletion is allowed */
    }
    
    return (U8)MMI_TRUE; /* Can not be deleted */
}



/****************************************************************************
 * Public Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter
 * DESCRIPTION
 *  If some event happens during interrupt, it is unsuitable to show screens.
 *  This API provides a mechanism to trigger client's procedure after the end of
 *  interrupt. func() will be called after interrupt.
 * PARAMETERS
 *  screen_id   [IN] When entering this screen, call func().
 *  func        [IN] Function to be called after interrupt
 *  arg         [IN] Will be passed into func
 * RETURNS
 *  MMI_TRUE if registerred successfully.
 *  MMI_FALSE if the screen is absent or on top, client have to call func by itself.
 *****************************************************************************/
MMI_BOOL mmi_da_scr_trigger_when_enter(U16 screen_id, void (*func)(void *arg), void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_da_scr_trigger_when_enter_ext(screen_id, func, NULL, arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_ext
 * DESCRIPTION
 *  If some event happens during interrupt, it is unsuitable to show screens.
 *  This API provides a mechanism to trigger client's procedure after the end of
 *  interrupt. func() will be called after interrupt.
 * PARAMETERS
 *  screen_id       [IN] When entering this screen, call func().
 *  func            [IN] Function to be called after interrupt
 *  delete_callback [IN] Delete callback function. If NULL, the the func should be
 *                       always triggered.
 *  arg             [IN] Will be passed into func
 * RETURNS
 *  MMI_TRUE if registerred successfully.
 *  MMI_FALSE if the screen is absent or on top, client have to call func by itself.
 *****************************************************************************/
MMI_BOOL mmi_da_scr_trigger_when_enter_ext(
    U16 screen_id,
    void (*func)(void *arg),
    void (*delete_callback)(void *arg),
    void *arg)
{
    //TODO check insert screen code
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;
    mmi_frm_node_struct *dummy_history;
    mmi_ret ret;
    MMI_BOOL inserted;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_get_active_id() == screen_id)
    {
        return MMI_FALSE;
    }

    top_dummy = mmi_da_scr_trigger_when_enter_allocate_instance();

    top_dummy->screen_id = mmi_da_scr_trigger_when_enter_allocate_screen();
    top_dummy->func = func;
    top_dummy->delete_callback = delete_callback;
    top_dummy->arg = arg;

    /* Insert dummy screen to history */
    dummy_history = (mmi_frm_node_struct*)OslMalloc(sizeof(mmi_frm_node_struct));
    memset(dummy_history, 0, sizeof(mmi_frm_node_struct));    
    dummy_history->id = top_dummy->screen_id;
    dummy_history->entry_proc = (mmi_proc_func)mmi_da_scr_trigger_when_enter_entry_dummy;
    dummy_history->user_data = NULL;    
    ret = mmi_frm_scrn_insert(mmi_da_get_active_scrn_grp(), screen_id, dummy_history, MMI_FRM_NODE_AFTER_FLAG);
    OslMfree(dummy_history);

	if (ret == MMI_RET_ERR)
		inserted = MMI_FALSE;
	else
		inserted = MMI_TRUE;

    if (inserted)
    {
        mmi_da_update_need_to_del_dummy(MMI_TRUE);
    }
    else    
    {
        /* Failed to insert, free the instance allocated */
        mmi_da_scr_trigger_when_enter_free_instance(top_dummy);
    }
    return inserted;
}

#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_da_http_confirm_fill_msg_string
 * DESCRIPTION
 *  Fill the message for confirm screen.
 * PARAMETERS
 *  arg         [IN] Job
 *  buffer      [IN] Buffer
 *  buffer_len  [IN] Length of buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len)
{
#ifdef __MMI_DA_WPS_UTIL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    U32 estimated_secs;
    U16 time_buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    buffer[0] = 0;
    if(job_data->size)
    {
        DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_SIZE), srv_da_util_format_size(job_data->size));

        /* calculte the time require to DL */
        estimated_secs = srv_da_wps_estimate_time_to_download((U32)job, MMI_FALSE, job_data->size);
        if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
        {
            mmi_da_app_util_format_time(time_buffer, estimated_secs);
            DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_ESTIMATED), time_buffer);
        }
    }
    else
    {
        DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_SIZE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    if(job->mime_type)
    {
        DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), job->mime_type->mime_string);
    }
    else if(job_data->mime_type_ptr)
    {
        DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), job_data->mime_type_ptr);
    }
    else
    {
        DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_TYPE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    if(!job->mime_type)
    {
        U16 *ptr;
        mmi_ucs2cat((S8*)buffer, (S8*)L"\n");
        mmi_ucs2cat((S8*)buffer, GetString(STR_ID_DA_PROMPT_NOT_SUPPORT));
        mmi_ucs2cat((S8*)buffer, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);
        ptr = buffer + (mmi_ucs2strlen((S8*)buffer)-1);
        if(*ptr == '\\')
            *ptr = 0;
        mmi_ucs2cat((S8*)buffer, GetString(STR_ID_DA_PROMPT_NOT_SUPPORT_END));
    }
#endif // #ifdef __MMI_DA_WPS_UTIL__
}
#endif /* MMI_DA_HTTP_DOWLOAD_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_confirm_fill_msg_string
 * DESCRIPTION
 *  Fill the message for confirm screen.
 * PARAMETERS
 *  arg         [IN] Job
 *  buffer      [IN] Buffer
 *  buffer_len  [IN] Length of buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_http_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len)
{
#ifndef MMI_DA_PLUTO_SLIM
#ifdef __MMI_DA_WPS_UTIL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    U32 estimated_secs;
    U16 time_buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    buffer[0] = 0;
    if(job_data->size)
    {
        DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_SIZE), srv_da_util_format_size(job_data->size));

        /* calculte the time require to DL */
        estimated_secs = srv_da_wps_estimate_time_to_download((U32)job, MMI_FALSE, job_data->size);
        if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
        {
            mmi_da_app_util_format_time(time_buffer, estimated_secs);
            DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_ESTIMATED), time_buffer);
        }
    }
    else
    {
        DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_SIZE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    if(job->mime_type)
    {
        DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), job->mime_type->mime_string);
    }
    else if(job_data->mime_type_ptr)
    {
        DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), job_data->mime_type_ptr);
    }
    else
    {
        DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_TYPE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    if(!job->mime_type)
    {
        U16 *ptr;
        mmi_ucs2cat((S8*)buffer, (S8*)L"\n");
        mmi_ucs2cat((S8*)buffer, GetString(STR_ID_DA_PROMPT_NOT_SUPPORT));
        mmi_ucs2cat((S8*)buffer, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);
        ptr = buffer + (mmi_ucs2strlen((S8*)buffer)-1);
        if(*ptr == '\\')
            *ptr = 0;
        mmi_ucs2cat((S8*)buffer, GetString(STR_ID_DA_PROMPT_NOT_SUPPORT_END));
    }
#endif
#endif

}

void mmi_da_app_mre_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_DLA_MRE_SUPPORT
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_mre_dl_detail_struct *dl_detail;
    srv_da_mre_dl_job_struct    *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;
    start_dl = job_data->detail->start_dl;

    DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_SIZE), srv_da_util_format_size(start_dl->size));
    DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), "VXP file");

    mmi_ucs2cat((S8*)buffer, (S8*)get_string(STR_ID_DA_PROMPT_NEED_DOWNLOADING_NOTIFY_CHARGE));
#endif

}


void mmi_da_app_push_confirm_fill_msg_string (void *arg, U16 *buffer, U32 buffer_len)
{
#ifndef MMI_DA_PLUTO_SLIM	
	U32 size = 0;
	srv_da_push_item_struct     *item;
	item = (srv_da_push_item_struct*)arg;
	buffer[0] = 0;

	size = srv_da_util_get_file_size (item->filepath);
	DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_SIZE), srv_da_util_format_size(size));

    if (item->mime_type)
	DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), item->mime_type->mime_string);
#endif
}

#if defined (__MMI_OMA_DD_DOWNLOAD__)
/*****************************************************************************
* FUNCTION
*  srv_da_oma_confirm_fill_msg_string
* DESCRIPTION
*   
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
void mmi_da_app_oma_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct          *job;
    srv_da_omadl_job_struct    *job_data;
    const srv_da_oma_dd_struct *dd_info;

    S32 i, j;
    U32 estimated_secs;
    U16 time_buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_omadl_job_struct*)job->data_ptr;
    
    dd_info = &job_data->dd_info;
    /* attribute display must follow ORDER appeared in Descriptor */
    /* name, vendor, type, size, description, infoURL, estimated time */
    buffer[0] = 0;
    for(i = 0; i < dd_info->attr_num; i++)
    {
        switch(dd_info->attr_order[i])
        {
        case DD_ELEM_NAME:
            DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_NAME), DA_GET_STRING(dd_info->name));
            break;
            
        case DD_ELEM_VENDOR:
            DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_VENDOR), DA_GET_STRING(dd_info->vendor));
            break;

        case DD_ELEM_TYPE:
            for(j=0;j<4;j++)
            {
                if(dd_info->type[j])
                {
                    /* type is Ascii */
                    DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_TYPE), dd_info->type[j]);
                }
            }
            break;
            
        case DD_ELEM_SIZE:
            if(dd_info->size != 0)
            {
                DA_SHOW_INFO(buffer, "%w\n%s\n", GetString(STR_ID_DA_PROMPT_SIZE), srv_da_util_format_size(dd_info->size));
            }
            else
            {
                DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_SIZE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
            }
            break;
            
        case DD_ELEM_DESCRIPTION:
            DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_DESC), DA_GET_STRING(dd_info->description));
            break;

        case DD_ELEM_INFO_URL:
            DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_INFOURL), DA_GET_STRING(dd_info->infoURL));
            break;
            
        default:
            break;
        }

    }


    estimated_secs = srv_da_wps_estimate_time_to_download_by_channel((U32)job, job_data->channel, job_data->dd_info.size);
    
    if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
    {
        mmi_da_app_util_format_time(time_buffer, estimated_secs);
        DA_SHOW_INFO(buffer, "%w\n%w\n", GetString(STR_ID_DA_PROMPT_ESTIMATED), time_buffer);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_oma_get_icon_result_description
 * DESCRIPTION
 *  Fill the status description of icon download result in string_buffer
 * PARAMETERS
 *  icon            [IN] icon structure
 *  string_buffer   [IN] string buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_oma_get_icon_result_description(
                const srv_da_oma_icon_struct *icon,
                U16 *string_buffer)
{
#ifdef __MMI_DA_OMA_ICONURI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result_str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (icon->state)
    {
        case SRV_DA_OMA_ICON_STATE_NONE:
            string_buffer[0] = L'\0';
            return;
            
        case SRV_DA_OMA_ICON_STATE_DOWNLOADING:
            mmi_ucs2cpy((S8*)string_buffer, GetString(STR_ID_DA_OMA_DOWNLOADING_ICON));
            return;
            
        case SRV_DA_OMA_ICON_STATE_SUCCEED:
            result_str_id = STR_GLOBAL_DONE;
            break;
            
        case SRV_DA_OMA_ICON_STATE_FAILED:
            result_str_id = STR_ID_DA_FAILED;
            break;
            
        case SRV_DA_OMA_ICON_STATE_CANCELLED:
        default:
            result_str_id = STR_ID_DA_CANCELLED;
            break;
    }

    kal_wsprintf(string_buffer, "%w - %w",
        GetString(STR_ID_DA_OMA_DOWNLOADING_ICON), GetString(result_str_id));
#endif /* __MMI_DA_OMA_ICONURI_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_oma_get_item_status_desc
 * DESCRIPTION
 *  Fill the object description of job in string_buffer[]
 * PARAMETERS
 *  job                 [IN]  Job.
 *  string_buffer       [IN]  Array of string buffers
 *  buffer_len          [IN]  Length of each string buffer element (in U16)
 *  num_of_buffers      [IN]  Number of string buffers. That is, this function can only
 *                            fill string_buffer[0..number_of_buffers-1]
 *  num_of_filled       [OUT] Number of filled buffer by this function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_oma_get_item_status_desc(
                const srv_da_job_struct *job,
                U16 *string_buffer[],       /* string_buffer[num_of_buffers] */
                const U32 buffer_len,       /* Max length per buffer */
                const U32 num_of_buffers,   /* Number of buffers */
                U32 *num_of_filled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_omadl_job_struct *job_data;
    U32 i;
    U16 status_desc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(buffer_len >= 50); /* Make sure the buffers long enough */
    MMI_ASSERT(num_of_buffers >= 2);

    job_data = (srv_da_omadl_job_struct*)job->data_ptr;

    i = 0;

    switch (job_data->oma_state)
    {
        case SRV_DA_OMA_STATE_DOWNLOADING_ICON:
        
            MMI_ASSERT(job_data->icon != NULL);
            mmi_da_oma_get_icon_result_description(job_data->icon, string_buffer[i++]);
            
            break;
            
        case SRV_DA_OMA_STATE_SENDING_INSTALL_NOTIFICATION:
            if (job_data->icon != NULL)
            {
                mmi_da_oma_get_icon_result_description(job_data->icon, string_buffer[i++]);
            }
            
            mmi_ucs2cpy((S8*)string_buffer[i++], GetString(STR_ID_DA_OMA_SEND_REPORT));
            
            break;

#ifdef __DRM_SUPPORT__
        case SRV_DA_OMA_STATE_POSTPROCESSING:
            status_desc_id = 0;
        
            switch (job_data->drm_status)
            {
                case SRV_DA_DRM_STATUS_WAITING_FOR_RIGHTS:
                    status_desc_id = STR_ID_DA_WAITING_FOR_RIGHTS;
                    break;

                case SRV_DA_DRM_STATUS_NO_RIGHTS:
                    status_desc_id = STR_ID_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME;
                    break;

                case SRV_DA_DRM_STATUS_PROCESSING:
                    status_desc_id = STR_GLOBAL_DRM_PROCESSING;
                    break;

                default:
                    break;
            }

            if (status_desc_id != 0)
            {
                mmi_wcsncpy(string_buffer[i], (U16*)GetString(status_desc_id), buffer_len - 1);
                string_buffer[i][buffer_len - 1] = L'\0';
                i++;
            }
            break;
#endif /* __DRM_SUPPORT__ */
            
        default:
            break;
    }

    *num_of_filled = i;
}

#endif //oma

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_status_desc
 * DESCRIPTION
 *  Fill the object description of job in string_buffer[]
 * PARAMETERS
 *  job                 [IN]  Job.
 *  string_buffer       [IN]  Array of string buffers
 *  buffer_len          [IN]  Length of each string buffer element (in U16)
 *  num_of_buffers      [IN]  Number of string buffers. That is, this function can only
 *                            fill string_buffer[0..number_of_buffers-1]
 *  num_of_filled       [OUT] Number of filled buffer by this function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_http_get_status_desc(
        const srv_da_job_struct *job,
        U16 *string_buffer[],       /* string_buffer[num_of_buffers] */
        const U32 buffer_len,       /* Max length per buffer(line) */
        const U32 num_of_buffers,   /* Number of buffers(lines) */
        U32 *num_of_filled)         /* Number of buffers(lines) filled */
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U16 status_desc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    status_desc_id = 0;

    switch (job->state)
    {
        case SRV_DA_JOB_STATE_PROCESSING:
            switch (job_data->drm_status)
            {
                case SRV_DA_DRM_STATUS_WAITING_FOR_RIGHTS:
                    status_desc_id = STR_ID_DA_WAITING_FOR_RIGHTS;
                    break;

                case SRV_DA_DRM_STATUS_NO_RIGHTS:
                    status_desc_id = STR_ID_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME;
                    break;

                case SRV_DA_DRM_STATUS_PROCESSING:
                    status_desc_id = STR_GLOBAL_DRM_PROCESSING;
                    break;

                default:
                    break;
            }

            if (status_desc_id != 0)
            {
                mmi_wcsncpy(string_buffer[0], (U16*)GetString(status_desc_id), buffer_len - 1);
                string_buffer[0][buffer_len - 1] = L'\0';
                *num_of_filled = 1;
            }
            else
            {
                *num_of_filled = 0;
            }
            
            break;
            
        default:
            *num_of_filled = 0;
            break;
    }
    
#else /* __DRM_SUPPORT__ */

    *num_of_filled = 0;

#endif /* __DRM_SUPPORT__ */
}

U32 mmi_da_format_job_detail(const srv_da_job_struct *job, U16* strBuffer, U32 buffer_len, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_item_progress_struct info;
    U32                         percentage;
    U16                         time_buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */
    S8                          *dl_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(count >= 3);
#if defined (__MMI_OMA_DD_DOWNLOAD__)
    if (job->type == SRV_DA_JOB_TYPE_OMADL)
		mmi_da_oma_get_item_progress(job, &info);
		else
#endif 
		{
			info.processing_string_id = 0;
		
		}
	percentage = DA_JOB_GET_PROGRESS(job, info);
    mmi_da_app_util_format_time(time_buffer, info.secs_remain);
    dl_str = srv_da_util_format_size_total(info.currSize, info.fileSize);

    /* Filepath */
    job->op->get_name(job, strBuffer, buffer_len);
    strBuffer[buffer_len-1] = 0;

    /* size information */
    mmi_asc_to_ucs2((S8*)(strBuffer + buffer_len), (S8*)dl_str);
    strBuffer[buffer_len*2-1] = 0;

    /* 2nd+3rd line */
    strBuffer[buffer_len*2] = 0;
    strBuffer[buffer_len*3] = 0;
    switch(job->state)
    {
    case SRV_DA_JOB_STATE_DOWNLOADING:
        /* display estimated time when downloading */
#if UI_DEVICE_WIDTH > UI_DEVICE_HEIGHT
        /* Landscape */
        kal_wsprintf((WCHAR*)(strBuffer + buffer_len*2), "%w %w", GetString(STR_ID_DA_PROMPT_TIME_REMAIN_EXT), time_buffer);
        strBuffer[buffer_len*3-1] = 0;
#else
        mmi_wcscpy(strBuffer + buffer_len*2, (U16*)get_string(STR_ID_DA_PROMPT_TIME_REMAIN_EXT));
        strBuffer[buffer_len*3-1] = 0;
        mmi_wcscpy(strBuffer + buffer_len*3, time_buffer);
        strBuffer[buffer_len*4-1] = 0;
#endif        
        break;

    case SRV_DA_JOB_STATE_PROCESSING:
        if (job->op->get_status_desc != NULL)
        {
            U16 *string_buffer[2];
            U32 num_of_filled;

            string_buffer[0] = &strBuffer[buffer_len * 2];
            string_buffer[1] = &strBuffer[buffer_len * 3];

            //job->op->get_status_desc(
                //job, string_buffer, buffer_len, 2, &num_of_filled);
#if defined (__MMI_OMA_DD_DOWNLOAD__)
			if (job->type == SRV_DA_JOB_TYPE_OMADL)
				mmi_da_oma_get_item_status_desc(job, string_buffer, buffer_len, 2, &num_of_filled);
			else
#endif
				mmi_da_http_get_status_desc(job, string_buffer, buffer_len, 2, &num_of_filled);
                
            MMI_ASSERT(num_of_filled <= 2);
        }
        else if (info.processing_string_id != 0)
        {
            mmi_wcsncpy((strBuffer + buffer_len*2), (U16*)get_string(info.processing_string_id), buffer_len-1);
            strBuffer[buffer_len*3-1] = 0;
        }
        break;
    }

    return percentage;
}
#endif // download_agent
