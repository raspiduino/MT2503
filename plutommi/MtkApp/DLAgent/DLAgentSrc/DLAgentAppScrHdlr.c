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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "CommonScreens.h"
#include "DLAgentAppScr.h"
#include "DLAgentSrvOMA.h"
#include "Das_struct.h"
//#include "ProtocolEvents.h"
//#include "app_mine.h"
//#include "FileMgr.h"
//#include "IdleAppDef.h"         /* g_keylock_context */

//#include "drm_def.h"            /* DRM_PROC_RESULT_OK */
//#include "drm_gprot.h"
//#include "DLAgentPlutoDef.h"
//#include "DLAgentPlutoGprot.h"
//#include "DLAgentPlutoprot.h"
//#include "DLAgentPlutoResDef.h"

#include "ProfilesSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrCuiGProt.h"
//#include "FileManagerGProt.h"   /* GetFileSystemErrorString */
//#include "FileManagerDef.h"
//#include "FileMgrResDef.h"
#include "browser_api.h"
//#include "UCMGProt.h"
#include "Menucuigprot.h"
#include "InlineCuiGprot.h"

    #include "mmi_rp_app_sms_def.h"

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
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#endif
/****************************************************************************
 * Global Functions
 ****************************************************************************/
static void mmi_da_app_scr_choice_init(void);
static void mmi_da_app_scr_storage_callback(
    mmi_da_scr_select_storage_context_struct *cntx,
    const U16* filepath,
    MMI_BOOL in_delete_cb,
    MMI_BOOL can_popup);
void mmi_da_app_job_on_details_selected(srv_da_job_struct *job);
static void mmi_da_app_scr_select_storage_final_ext(mmi_da_scr_select_storage_context_struct *cntx);
/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/
static mmi_da_scr_choice_context_struct g_mmi_da_scr_choice_cntx;
static S32 g_mmi_da_scr_select_storage_instance_count = 0;
static mmi_da_scr_select_storage_context_struct *g_mmi_da_scr_select_storage_top_cntx_p = NULL;
static mmi_da_context_struct g_mmi_da_context;
static mmi_da_scr_progressing_context_struct *g_mmi_da_scr_progressing_top_cntx = NULL;
static mmi_da_scr_async_move_cntx_struct *g_mmi_da_scr_async_move_cntx_p = NULL;
extern mmi_da_scr_full_screen_popup_context_struct *g_mmi_da_scr_full_screen_popup_cntx;
static MMI_BOOL g_da_del_download_option = MMI_TRUE;
static MMI_BOOL g_da_del_progressing = MMI_TRUE;
static MMI_BOOL g_da_del_dummy = MMI_TRUE;
static MMI_BOOL g_da_del_choice_screen = MMI_TRUE;
static MMI_BOOL g_da_del_dispatch_confirm = MMI_TRUE;
/****************************************************************************
 * Global variables
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_init
 * DESCRIPTION
 *  Initialization function for choice API.
 *  Be sure to call this function when system initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

S32 mmi_da_get_job_highlight_index(void)
{
	return g_mmi_da_context.job_list_highlight_index;
}

void mmi_da_set_job_highlight_index(S32 index)
{
	g_mmi_da_context.job_list_highlight_index = index;

}

mmi_da_scr_choice_screen_struct *mmi_da_app_get_top_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_da_scr_choice_cntx.top_screen;
}

mmi_da_scr_progressing_context_struct * mmi_da_app_get_top_cntx(void)
{	
	return g_mmi_da_scr_progressing_top_cntx;

}
void mmi_da_app_set_top_cntx(mmi_da_scr_progressing_context_struct *cntx)
{
	g_mmi_da_scr_progressing_top_cntx = cntx;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_init
 * DESCRIPTION
 *  Initialization function for choice API.
 *  Be sure to call this function when system initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_choice_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_da_scr_choice_cntx.free_screen_ids, 0, sizeof(g_mmi_da_scr_choice_cntx.free_screen_ids));
    
    g_mmi_da_scr_choice_cntx.free_screen_ids[0] = SCR_ID_DA_CONFIRM_0;
    g_mmi_da_scr_choice_cntx.free_screen_ids[1] = SCR_ID_DA_CONFIRM_1;
    g_mmi_da_scr_choice_cntx.free_screen_ids[2] = SCR_ID_DA_CONFIRM_2;
    g_mmi_da_scr_choice_cntx.free_screen_ids[3] = SCR_ID_DA_CONFIRM_3;
}

//TODO
extern void mmi_da_app_scr_trigger_when_enter_init(void);
/*****************************************************************************
* FUNCTION
*   mmi_da_scr_init
* DESCRIPTION
*   Initial the screen context
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_da_app_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_da_app_scr_choice_init();
    mmi_da_app_scr_trigger_when_enter_init();
}
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_choice_free_screen_context
 * DESCRIPTION
 *  Free a screen context. The screen ID will be recycled and the context
 *  will be removed from the context list.
 * PARAMETERS
 *  cntx    [IN] Screen context
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_choice_free_screen_context(mmi_da_scr_choice_screen_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_da_scr_choice_screen_struct *t_cntx;
    mmi_da_scr_choice_screen_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Free screen ID */
    for (i = 0; i < MMI_DA_MAX_CHOICE_SCREEN_NUM; i++)
    {
        if (g_mmi_da_scr_choice_cntx.free_screen_ids[i] == 0)
        {
            g_mmi_da_scr_choice_cntx.free_screen_ids[i] = cntx->screen_id;
        }
    }

    /* Remove from list */
    prev = NULL;
    for (t_cntx = g_mmi_da_scr_choice_cntx.top_screen; t_cntx != NULL; t_cntx = t_cntx->next)
    {
        if (t_cntx == cntx)
        {
            break;
        }

        prev = t_cntx;
    }

    MMI_ASSERT(t_cntx != NULL);

    if (prev == NULL)
    {
        g_mmi_da_scr_choice_cntx.top_screen = cntx->next;
    }
    else
    {
        prev->next = cntx->next;
    }
    
    srv_srv_da_adp_mem_free(cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_allocate_screen_context
 * DESCRIPTION
 *  Allocate a screen context struct. The returned context is already assigned
 *  a screen ID and inserted into context list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Screen context
 *****************************************************************************/
static mmi_da_scr_choice_screen_struct* mmi_da_app_scr_choice_allocate_screen_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cntx = (mmi_da_scr_choice_screen_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_choice_screen_struct));

    cntx->screen_id = 0;

    /* Free screen ID */
    for (i = 0; i < MMI_DA_MAX_CHOICE_SCREEN_NUM; i++)
    {
        if (g_mmi_da_scr_choice_cntx.free_screen_ids[i] != 0)
        {
            cntx->screen_id = g_mmi_da_scr_choice_cntx.free_screen_ids[i];
            g_mmi_da_scr_choice_cntx.free_screen_ids[i] = 0;
            break;
        }
    }

    MMI_ASSERT(cntx->screen_id != 0); /* Insufficient screen ID resource */

    /* Add to screen list */
    cntx->next = g_mmi_da_scr_choice_cntx.top_screen;
    g_mmi_da_scr_choice_cntx.top_screen = cntx;

    return cntx;
}
#endif
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_choice_delete_hdlr
 * DESCRIPTION
 *  Delete callback for choice screen.
 * PARAMETERS
 *  unused      [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_da_app_scr_choice_delete_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_da_scr_choice_cntx.top_screen;

    MMI_ASSERT(cntx != NULL);
    
    //ClearDelScrnIDCallbackHandler(cntx->screen_id, mmi_da_app_scr_choice_delete_hdlr);
    mmi_da_update_need_to_del_choice_screen(MMI_FALSE);
    if (cntx->delete_hdlr != NULL)
    {
        cntx->delete_hdlr(cntx->arg);
    }

    /* Delete callback handler will be cleared when free */
    mmi_da_app_scr_choice_free_screen_context(cntx);

    return (U8)MMI_FALSE;
}
#endif
mmi_ret mmi_da_app_choice_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related events */
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_group_close(MMI_DA_CONFIRM_SCREEN_GROUP);
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
        {
            if(mmi_da_get_active_scrn_grp() != MMI_DA_BRW_ENTRY_SCREEN_GROUP)
                mmi_frm_group_close(mmi_da_get_active_scrn_grp());
            mmi_da_set_active_scrn_grp(MMI_DA_CONFIRM_SCREEN_GROUP);
            break;
        }
        
        case EVT_ID_GROUP_INACTIVE:
        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            break; 
        }
      
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            mmi_frm_group_close(MMI_DA_CONFIRM_SCREEN_GROUP);
            break;
        default:
        break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
void mmi_da_app_http_confirm_csk_callback (void *arg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    srv_da_setting_struct       *setting_data;
    mmi_da_scr_storage_parameter_struct *para;
    void *select_storage_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    srv_da_adp_set_active_download_confirm_screen(job, 0);

    /* retrieve setting */
    setting_data = srv_da_get_setting_buffer();
    srv_da_http_get_setting(job, setting_data);

    /* store setting */
    srv_da_copy_setting(job, setting_data);

    /* prepare storage parameter */
    
    job->saved_to_my_fav = MMI_TRUE;
    
    para = (mmi_da_scr_storage_parameter_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_storage_parameter_struct));
    
    memset(para, 0, sizeof(mmi_da_scr_storage_parameter_struct));
    
    para->drv = setting_data->drv;
    para->storage = setting_data->storage;
  
    if (para->storage == SRV_DA_STORAGE_NONE)
    {
        para->storage = SRV_DA_STORAGE_AUTO;
    }
    para->select_storage = MMI_FALSE;

    mmi_wcscpy(para->folder, setting_data->folder);

    if (!setting_data->default_filename && setting_data->filename[0])
    {
        srv_da_extract_filepath(setting_data->filename, para->filename, para->fileext);
    }
    else if (job_data->filepath!= NULL && job_data->filepath[0] != L'\0')
    {
        /* Assigned filepath in FILE_DL msg */
        srv_da_extract_filepath(job_data->filepath, para->filename, para->fileext);
    }
    else
    {
        srv_da_extract_filename_from_url(job_data->url_ptr, para->filename, para->fileext);
    }

    if(job->mime_type != NULL)
    {
        mmi_asc_n_to_wcs(para->fileext, job->mime_type->file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
    }
    
#ifdef MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD
    para->select_filename = (!setting_data->default_filename && setting_data->filename[0] == 0) ? MMI_TRUE : MMI_FALSE;
#else
    para->select_filename = MMI_FALSE;
#endif

    para->filesize = job_data->size;
    
#ifdef __DRM_SUPPORT__
    /* DRM V1.0 content require twice space */
    if( job->mime_type && 
        (job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
         job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) )
    {
        para->filesize *= 2;
    }
#endif

    /* if app control (provide filepath callback), skip file size checking */
    if(job->setting_info.filepath_hdlr)
        para->filesize = 0;

    para->filecheck_func = srv_da_does_job_with_filepath_exist;

    /* confirmed, select storage now. */
    select_storage_instance = mmi_da_app_scr_select_storage(
        srv_da_http_filename_done,
        para,
        (U32)job,
        srv_da_job_get_title_icon(job));

    srv_da_adp_set_active_select_storage_instance(select_storage_instance);

    srv_srv_da_adp_mem_free(para);
}
#ifdef __MMI_OMA_DD_DOWNLOAD__
static void mmi_da_app_oma_confirm_csk_callback (void *arg)
{
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
    srv_da_oma_set_storage_selection(MMI_FALSE);
    job->saved_to_my_fav = MMI_TRUE;
    srv_da_oma_confirm_download_callback (arg, NULL);
}
#endif // __MMI_OMA_DD_DOWNLOAD__
#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
#ifndef MMI_DA_PLUTO_SLIM
U16 mmi_da_app_scr_show_choice_screen(srv_da_show_choice_screen_event_struct* para)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;
    //mmi_da_screen_group_id_enum  grp_id;
	srv_da_job_struct  *job = (srv_da_job_struct*)(para->arg);
	#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
        srv_da_setting_struct       *setting_data;
    #endif
    
	U16 lsk_id = STR_GLOBAL_YES;
    U16 rsk_id = STR_GLOBAL_NO;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/



    /* cntx will be added to screen list when allocate */
    cntx = mmi_da_app_scr_choice_allocate_screen_context();
    cntx->title_string_id = STR_GLOBAL_DOWNLOAD_ASK;

    if (job->type == SRV_DA_JOB_TYPE_PUSH)
	{
		cntx->title_icon_id =  srv_da_job_get_title_icon(job); //to do
		cntx->fill_msg_string = mmi_da_app_push_confirm_fill_msg_string;
	}
#ifdef MMI_DLA_MRE_SUPPORT
    else if (job->type == SRV_DA_JOB_TYPE_MREDL)
	{
		cntx->title_icon_id = IMG_GLOBAL_YES;
		cntx->fill_msg_string = mmi_da_app_mre_confirm_fill_msg_string;
	}
#endif
    else
	{	cntx->title_icon_id = srv_da_job_get_title_icon(job);
        if(job->type == SRV_DA_JOB_TYPE_NORMAL || job->type == SRV_DA_JOB_TYPE_MREDL)
            cntx->fill_msg_string = mmi_da_app_http_confirm_fill_msg_string;
#if defined (__MMI_OMA_DD_DOWNLOAD__)
		else if (job->type == SRV_DA_JOB_TYPE_OMADL)
			cntx->fill_msg_string = mmi_da_app_oma_confirm_fill_msg_string;
#endif
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
		else if(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
            cntx->fill_msg_string = mmi_da_app_confirm_fill_msg_string;
#endif
	}
    //cntx->title_icon_id = para->title_icon_id;

    cntx->show_cancel_ask = para->show_cancel_ask;
    cntx->arg = para->arg;
    cntx->lsk_hdlr = para->lsk_hdlr;
    cntx->rsk_hdlr = para->rsk_hdlr;
#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__

#ifdef MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD
        /* retrieve setting */
        setting_data = srv_da_get_setting_buffer();
        job->op->get_setting(job, setting_data);
        /* store setting */
        srv_da_copy_setting(job, setting_data);
        if (setting_data->storage == SRV_DA_STORAGE_NONE)
        {
            lsk_id = STR_GLOBAL_OPTIONS;
            rsk_id = STR_GLOBAL_CANCEL;
        }
#endif /* MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD */
#if defined (__MMI_OMA_DD_DOWNLOAD__)
	if (job->type == SRV_DA_JOB_TYPE_OMADL)
	{
		cntx->csk_hdlr = mmi_da_app_oma_confirm_csk_callback;

	}
	else 
#endif
    if (job->type == SRV_DA_JOB_TYPE_PUSH)
	{
        cntx->csk_hdlr = para->lsk_hdlr;
	}
	else
	{
		cntx->csk_hdlr = mmi_da_app_http_confirm_csk_callback;

	}
#endif
    cntx->delete_hdlr = para->delete_hdlr;
	cntx->lsk_string_id = lsk_id;
    cntx->rsk_string_id = rsk_id;
    if(!mmi_da_is_app_launched())
    {
        mmi_da_launch_app(MMI_DA_LAUNCH_FROM_BROWSER);
    }
    if(!mmi_frm_group_is_present(MMI_DA_CONFIRM_SCREEN_GROUP))
    {
        mmi_frm_group_create_ex(MMI_DA_BRW_ENTRY_SCREEN_GROUP, 
                                       MMI_DA_CONFIRM_SCREEN_GROUP,
                                       mmi_da_app_choice_scr_group_proc,
                                       (void*)NULL,
                                       MMI_FRM_NODE_SMART_CLOSE_FLAG);        
    }

    mmi_da_app_scr_entry_choice();
    if (cntx->delete_hdlr != NULL)
    {
        mmi_da_update_need_to_del_choice_screen(MMI_TRUE);
    }
    return cntx->screen_id;

}
#endif

//tODO rectify this api
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_remove_screen
 * DESCRIPTION
 *  Remove a screen from the top screen or history.
 * PARAMETERS
 *  screen_id       [IN] Screen ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_remove_screen(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == screen_id)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {   
        mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, screen_id);
    }
}

mmi_ret mmi_da_brw_entry_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related events */
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_group_close(MMI_DA_BRW_ENTRY_SCREEN_GROUP);
            if (srv_da_get_curr_job_in_setuping_state() != NULL)
				srv_da_job_cancel(srv_da_get_curr_job_in_setuping_state());
        }
        break;
        case EVT_ID_GROUP_ACTIVE:
        {
            g_mmi_da_context.da_app_scr_group_id = MMI_DA_BRW_ENTRY_SCREEN_GROUP;
        }
        case EVT_ID_GROUP_INACTIVE:
        {
            
        }
        break;

        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            
        }
        break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            mmi_frm_group_close(MMI_DA_BRW_ENTRY_SCREEN_GROUP);
            break;

        default:
        break;
    }
    return MMI_RET_OK;
}

#ifndef MMI_DA_PLUTO_SLIM
mmi_ret mmi_da_download_list_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related events */
        case EVT_ID_GROUP_ACTIVE:
        {
            if(g_mmi_da_context.da_app_scr_group_id != MMI_DA_BRW_ENTRY_SCREEN_GROUP)
                mmi_frm_group_close(g_mmi_da_context.da_app_scr_group_id);
            g_mmi_da_context.da_app_scr_group_id = MMI_DA_DOWNLOAD_LIST_GROUP;
        }
        break;
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_group_close(MMI_DA_DOWNLOAD_LIST_GROUP);
            break;
        }
        case EVT_ID_GROUP_INACTIVE:
        {
            
        }
        break;

        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            
        }
        break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            mmi_frm_group_close(MMI_DA_DOWNLOAD_LIST_GROUP);
            break;

        default:
        break;
    }
    return MMI_RET_OK;
}
#endif

MMI_BOOL mmi_da_is_app_launched(void)
{
    return (mmi_frm_group_is_present(MMI_DA_BRW_ENTRY_SCREEN_GROUP)) ;
}

void mmi_da_launch_app(mmi_da_app_launch_enum launch_type)
{
    if(launch_type == MMI_DA_LAUNCH_FROM_BROWSER)
    {
        if(!mmi_frm_group_is_present(MMI_DA_BRW_ENTRY_SCREEN_GROUP))
        {
            mmi_frm_group_create_ex(GRP_ID_ROOT, 
                                       MMI_DA_BRW_ENTRY_SCREEN_GROUP,
                                       mmi_da_brw_entry_group_proc,
                                       (void*)NULL,
                                       MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
        
    }
    else if(launch_type == MMI_DA_LAUNCH_FROM_IDLE)
    {
        if(!mmi_frm_group_is_present(MMI_DA_PUSH_ENTRY_SCREEN_GROUP))
        {
            mmi_frm_group_create_ex(GRP_ID_ROOT, 
                                       MMI_DA_PUSH_ENTRY_SCREEN_GROUP,
                                       mmi_da_brw_entry_group_proc,
                                       (void*)NULL,
                                       MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_mmi_da_context.da_app_scr_group_id = MMI_DA_PUSH_ENTRY_SCREEN_GROUP;
        }
    }
}
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_lsk_hdlr
 * DESCRIPTION
 *  LSK handler for choice screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_choice_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_da_scr_choice_cntx.top_screen;

    MMI_ASSERT(cntx != NULL);
    mmi_da_update_need_to_del_choice_screen(MMI_FALSE);
    if (cntx->lsk_hdlr != NULL)
    {
        cntx->lsk_hdlr(cntx->arg, NULL);
    }
    mmi_frm_scrn_close(MMI_DA_CONFIRM_SCREEN_GROUP, cntx->screen_id);
    mmi_da_app_scr_choice_free_screen_context(cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_callback_rsk_hdlr
 * DESCRIPTION
 *  Callback rsk_hdlr() and de-init instance.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_choice_callback_rsk_hdlr(mmi_da_scr_choice_screen_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_da_update_need_to_del_choice_screen(MMI_FALSE);

    if (cntx->rsk_hdlr != NULL)
    {
        cntx->rsk_hdlr(cntx->arg);
    }
    mmi_frm_scrn_close(MMI_DA_CONFIRM_SCREEN_GROUP, cntx->screen_id);
    mmi_da_app_scr_choice_free_screen_context(cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_rsk_confirm_proc
 * DESCRIPTION
 * 
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK;
 *****************************************************************************/
static mmi_ret mmi_da_app_scr_choice_rsk_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;
    mmi_alert_result_evt_struct *result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        result_evt = (mmi_alert_result_evt_struct*)evt;

        if (result_evt->result == MMI_ALERT_CNFM_YES)
        {
            cntx = (mmi_da_scr_choice_screen_struct*)result_evt->user_tag;
            mmi_da_app_scr_choice_callback_rsk_hdlr(cntx);
        }
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_choice_rsk_hdlr
 * DESCRIPTION
 *  RSK handler for choice screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_choice_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_da_scr_choice_cntx.top_screen;

    MMI_ASSERT(cntx != NULL);

    if (cntx->show_cancel_ask)
    {
        mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
        confirm_arg.user_tag = (void*)cntx;
        confirm_arg.callback = mmi_da_app_scr_choice_rsk_confirm_proc;
        mmi_confirm_display(
            get_string(STR_ID_DA_POPUP_CANCEL_ASK),
            MMI_EVENT_QUERY,
            &confirm_arg);
    }
    else
    {
        mmi_da_app_scr_choice_callback_rsk_hdlr(cntx);
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage_allocate_context
 * DESCRIPTION
 *  Allocate an instance and its screen IDs. The instance will be push into
 *  the stack list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Instance.
 *****************************************************************************/
static mmi_da_scr_select_storage_context_struct* mmi_da_app_scr_select_storage_allocate_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_da_scr_select_storage_instance_count >= 4)
    {
        return NULL;
    }

    cntx = (mmi_da_scr_select_storage_context_struct*)
        srv_da_adp_mem_allocate(sizeof(mmi_da_scr_select_storage_context_struct));

    /* Add cntx to list */
    cntx->next = g_mmi_da_scr_select_storage_top_cntx_p;
    g_mmi_da_scr_select_storage_top_cntx_p = cntx;
    g_mmi_da_scr_select_storage_instance_count++;

    return cntx;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage_go_back_on_drive_cause
 * DESCRIPTION
 *  Go back to appropriate screen because there is some problem on the drive.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_select_storage_go_back_on_drive_cause(
    mmi_da_scr_select_storage_context_struct *cntx, srv_da_scr_select_storage_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->cui_select_drive > 0)
    {
        if (cntx->cui_filename_editor > 0)
        {
            cui_filename_editor_close(cntx->cui_filename_editor);
            cntx->cui_filename_editor = 0;
        }
    }
    else
    {
        cntx->cause = cause;
        mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage_check_drive
 * DESCRIPTION
 *  Check the availability and free space of the drive selected.
 *  This function will control screens.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  Flag to continue going.
 *****************************************************************************/
static MMI_BOOL mmi_da_app_scr_select_storage_check_drive(mmi_da_scr_select_storage_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_scr_select_storage_cause_enum cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_NONE;
    
    /* if provided original_filepath, and the chosen storage are the same
        Skip the check */
    if (cntx->param.original_filepath == NULL ||
        cntx->param.original_filepath[0] != cntx->param.drv)
    {
        U16 error_str_id = 0;
        U32 filesize;        

        filesize = cntx->param.filesize;

        /* For resumption */
        if (cntx->param.skip_exist_check &&
            !cntx->param.select_storage &&
            !cntx->param.select_filename)
        {
            U16 *filepath;

            MMI_ASSERT(cntx->param.filename[0] != L'\0');

            filepath = (U16 *)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));

            /* complete full path */
            if (cntx->param.fileext[0] != L'\0')
            {
                kal_wsprintf(filepath,
                    "%c:\\%w%w.%w", 
                    cntx->param.drv, 
                    cntx->param.folder, 
                    cntx->param.filename,
                    cntx->param.fileext);
            }
            else
            {
                /* no ext */
                kal_wsprintf(filepath,
                    "%c:\\%w%w",
                    cntx->param.drv, 
                    cntx->param.folder, 
                    cntx->param.filename);
            }

            filesize = filesize - srv_da_util_get_file_size(filepath);

            srv_srv_da_adp_mem_free(filepath);
        }
    
        if (!srv_da_util_is_drive_available(cntx->param.drv))
        {
            cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_NO_AVAILABLE_STORAGE;
            error_str_id = STR_ID_DA_ERROR_STORAGE_IS_UNAVAILABLE;
        }
        else if (!srv_da_util_check_free_space(cntx->param.drv, filesize))
        {
            cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_INSUFFICIENT_MEMORY;
            error_str_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
        }

        if (error_str_id != 0)
        {
            mmi_da_app_show_popup_ext(error_str_id,SRV_DA_POPUP_TYPE_ERROR); //TBD
            mmi_da_app_scr_select_storage_go_back_on_drive_cause(cntx, cause);
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_select_storage_free_context
 * DESCRIPTION
 *  Free instance, remove it from the stack list.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_select_storage_free_context(mmi_da_scr_select_storage_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_da_scr_select_storage_top_cntx_p == cntx)
    {
        g_mmi_da_scr_select_storage_top_cntx_p = cntx->next;
    }
    else
    {
        mmi_da_scr_select_storage_context_struct *prev;
        mmi_da_scr_select_storage_context_struct *c_cntx;

        prev = NULL;
        for (c_cntx = g_mmi_da_scr_select_storage_top_cntx_p; c_cntx != NULL; c_cntx = c_cntx->next)
        {
            if (c_cntx == cntx)
            {
                break;
            }

            prev = c_cntx;
        }

        MMI_ASSERT(c_cntx != NULL);
        MMI_ASSERT(prev != NULL);
        
        prev->next = cntx->next;
    }
    
    srv_srv_da_adp_mem_free(cntx);
    g_mmi_da_scr_select_storage_instance_count--;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_close_select_storage
 * DESCRIPTION
 *  Close the instance of select storage. Remove all related screens.
 * PARAMETERS
 *  instance    [IN] Instance
 *  calback     [IN] Call the callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_close_select_storage(void *instance, MMI_BOOL callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;
    MMI_ID grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cntx = g_mmi_da_scr_select_storage_top_cntx_p; cntx != NULL; cntx = cntx->next)
    {
        if ((void*)cntx == instance)
        {
            break;
        }
    }
    
    if (cntx == NULL)
    {
        return;
    }

    grp_id = cntx->grp_id;
    cntx->grp_id = 0;
    
    if (cntx->cui_select_drive > 0)
    {
		#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
        cui_folder_selector_close(cntx->cui_select_drive);
		#else
        cui_storage_selector_close(cntx->cui_select_drive);
		#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
        cntx->cui_select_drive = 0;
    }
    if (cntx->cui_filename_editor > 0)
    {
        cui_filename_editor_close(cntx->cui_filename_editor);
        cntx->cui_filename_editor = 0;
    }

    if (callback)
    {
        cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_DELETE_SCREEN;
        mmi_da_app_scr_storage_callback(cntx, NULL, MMI_TRUE, MMI_FALSE);
    }

    if (grp_id > 0)
    {
        /* The context will be freed on group deinit */
        mmi_frm_group_close(grp_id);
    }
    else
    {
        mmi_da_app_scr_select_storage_free_context(cntx);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_remove_screen
 * DESCRIPTION
 *  Remove a screen from the top screen or history.
 * PARAMETERS
 *  screen_id       [IN] Screen ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_scr_remove_screen(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == screen_id)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        //DeleteScreenIfPresent(screen_id); 
        mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, screen_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_progressing_close
 * DESCRIPTION
 *  Close the progressing screen.
 * PARAMETERS
 *  screen_id   [IN] Screen ID
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_da_scr_progressing_close(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_progressing_context_struct *prev;
    mmi_da_scr_progressing_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev = NULL;
    for (cntx = g_mmi_da_scr_progressing_top_cntx; cntx != NULL; cntx = cntx->next)
    {
        if (cntx->screen_id == screen_id)
        {
            break;
        }
    
        prev = cntx;
    }

    if (cntx == NULL)
    {
        return MMI_FALSE;
    }

    if (cntx->timer_id != 0)
    {
        srv_da_timer_triggered_proc_cancel(cntx->timer_id);
        cntx->timer_id = 0;
    }

    //ClearDelScrnIDCallbackHandler(screen_id, mmi_da_app_scr_delete_progressing);
    mmi_da_update_need_to_delete_progressing(MMI_FALSE);

    mmi_da_scr_remove_screen(screen_id);

    if (g_mmi_da_scr_progressing_top_cntx == cntx)
    {
        g_mmi_da_scr_progressing_top_cntx = cntx->next;
    }
    else
    {
        prev->next = cntx->next;
    }

    srv_srv_da_adp_mem_free(cntx);
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *   mmi_da_app_select_storage_async_acceptance
 * DESCRIPTION
 *   Asynchronous response for select storage callback.
 * PARAMETERS
 *   mmi_da_acceptance_enum     [IN] Acceptance
 * RETURNS
 *   void
 *****************************************************************************/
void mmi_da_app_select_storage_async_acceptance(void *instance, srv_da_acceptance_enum acceptance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *prev;
    mmi_da_scr_select_storage_context_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    prev = NULL;
    for (cntx = g_mmi_da_scr_select_storage_top_cntx_p; cntx != NULL; cntx = cntx->next)
    {
        if ((void*)cntx == instance)
        {
            break;
        }

        prev = cntx;
    }
    
    if(cntx == NULL)
    {
        return;
    }
    
    switch (acceptance)
    {
        case SRV_DA_ACCEPTANCE_ACCEPT:
            mmi_da_app_scr_close_select_storage(cntx, MMI_FALSE);
            break;
    
        case SRV_DA_ACCEPTANCE_REJECT:
            cntx->already_called_back = MMI_FALSE;
            break;

        case SRV_DA_ACCEPTANCE_ASYNC:
        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_storage_callback
 * DESCRIPTION
 *  Call the callback function.
 * PARAMETERS
 *  cntx            [IN] Context/instance
 *  filepath        [IN] Resule filepath. If not selected/decided, pass NULL.
 *  in_delete_cb    [IN] In deleting context
 *  can_popup       [IN] Allow the callback to popup
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_storage_callback(
    mmi_da_scr_select_storage_context_struct *cntx,
    const U16* filepath,
    MMI_BOOL in_delete_cb,
    MMI_BOOL can_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  canback = MMI_FALSE;
    srv_da_acceptance_enum acceptance;
	MMI_BOOL canpopup = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //DA_TRACE_FUNC3(mmi_da_app_scr_storage_callback, 1, (U32)filepath, cntx->already_called_back);

    if (cntx->already_called_back)
    {
        /* Client should release resource by itself when deleting */
        return;
    }

    if (filepath != NULL &&
        !in_delete_cb &&
        (cntx->param.select_storage || cntx->param.select_filename))
    {
        canback = MMI_TRUE;
    }

    /*
     * [MAUI_01597922]
     * We should check free space again when create folder. Otherwise, if "Not enough memory"
     * happen after callback, it goes back to the filename editor only.
     * However, the free space evaulation is not fully correct. Because it MAY need space
     * to create a new file entry. It is not enough that only count in the file size.
     */
    if (canback)
    {
        if (!mmi_da_app_scr_select_storage_check_drive(cntx))
        {
            return;
        }
    }
    
    cntx->already_called_back = MMI_TRUE;
    if (filepath == NULL)
    {
        if (cntx != NULL &&
            mmi_da_scr_select_storage_get_cause(cntx) == SRV_DA_SCR_SELECT_STORAGE_CAUSE_ORIGINAL_FILE_LOST)
        {
            can_popup = MMI_TRUE;
        }
        else
        {
            can_popup = MMI_FALSE;
        }
    }
	if (!in_delete_cb && can_popup)
		canpopup = MMI_TRUE;

    acceptance = cntx->callback(
        cntx->user_data,
        (U16*)filepath,
        canback,
        canpopup,
        cntx);

    

    //DA_TRACE_FUNC3(mmi_da_app_scr_storage_callback, acceptance, canback, can_popup);

    switch (acceptance)
    {
        case SRV_DA_ACCEPTANCE_ACCEPT:
            if (!in_delete_cb)
            {
                mmi_da_app_select_storage_async_acceptance(cntx, acceptance);
            }
            break;
            
        case SRV_DA_ACCEPTANCE_REJECT:
            MMI_EXT_ASSERT(canback && !in_delete_cb, canback, in_delete_cb, 0);
            mmi_da_app_select_storage_async_acceptance(cntx, acceptance);
            break;

        case SRV_DA_ACCEPTANCE_ASYNC:
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }
    
}

void mmi_da_app_handle_push_process(S32 error_code, srv_da_push_async_move_arg_struct* async_move_arg)
{
    if (error_code != FS_NO_ERROR)
    {     
        if (async_move_arg->select_storage_instance != NULL)
        {
            if (async_move_arg->can_reject)
            {
                mmi_da_app_select_storage_async_acceptance(
                    async_move_arg->select_storage_instance,
                    SRV_DA_ACCEPTANCE_REJECT);
            }
            else
            {               
                mmi_da_app_select_storage_async_acceptance(
                    async_move_arg->select_storage_instance,
                    SRV_DA_ACCEPTANCE_ACCEPT);
            }
        }
    }
    else
    {
        if (async_move_arg->select_storage_instance != NULL)
        {
            mmi_da_app_select_storage_async_acceptance(
                async_move_arg->select_storage_instance,
                SRV_DA_ACCEPTANCE_ACCEPT);
        }
    }
}
static MMI_BOOL mmi_da_app_scr_show_select_drive(
    mmi_da_scr_select_storage_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
    cntx->cui_select_drive = cui_storage_selector_create(
        cntx->grp_id,
        (U8)cntx->param.drv,
        CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY);

    cui_storage_selector_set_title(
        cntx->cui_select_drive,
        STR_GLOBAL_STORAGE,
        cntx->icon_id);
        
    if (cntx->cui_select_drive == 0)
    {
        return MMI_FALSE;
    }

    cui_storage_selector_run(cntx->cui_select_drive);
#else /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
   
    cntx->cui_select_drive = cui_folder_selector_create(
        cntx->grp_id,
        (WCHAR*)L"root", 
        CUI_FOLDER_SELECTOR_STYLE_READ, 
        CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL | CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);

    cui_folder_selector_run(cntx->cui_select_drive);
#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage_is_drive_cause
 * DESCRIPTION
 *  Is the error can be recovered by change drive?
 * PARAMETERS
 *  fs_error    [IN] Error code of file system
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_da_app_scr_select_storage_is_drive_cause(S32 fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fs_error)
    {
        case FS_DRIVE_NOT_FOUND:
        case FS_UNSUPPORTED_DEVICE:
        case FS_ROOT_DIR_FULL:
        case FS_DISK_FULL:
        case FS_DRIVE_NOT_READY:
        case FS_DEVICE_BUSY:
        case FS_FLASH_MOUNT_ERROR:
        case FS_MSDC_MOUNT_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MSDC_NOT_PRESENT:
            return MMI_TRUE;
            
        default:
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_ret mmi_da_app_scr_overwrite_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;
    mmi_alert_result_evt_struct *result_evt;
    int fsret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        result_evt = (mmi_alert_result_evt_struct*)evt;

        if (result_evt->result == MMI_ALERT_CNFM_YES)
        {
            cntx = (mmi_da_scr_select_storage_context_struct*)result_evt->user_tag;
            
            fsret = srv_da_util_file_delete(cntx->filepath);
            if(fsret < 0)
            {
                mmi_da_app_show_popup_ext(srv_fmgr_fs_error_get_string(fsret), SRV_DA_POPUP_TYPE_ERROR);
            }
            else
            {                
                mmi_da_app_scr_storage_callback(cntx, cntx->filepath, MMI_FALSE, MMI_TRUE);
            }
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage_final
 * DESCRIPTION
 *  Complete variables passed to call back and do final checks.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_select_storage_final(mmi_da_scr_select_storage_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *full_filename;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cntx->param.original_filepath != NULL &&
        !srv_da_util_does_file_exist(cntx->param.original_filepath))
    {
        //DA_TRACE_FUNC1(mmi_da_app_scr_select_storage, 150);
        cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_ORIGINAL_FILE_LOST;
        mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_TRUE);
        return;
    }

    /*
     * Decide storage again after filename is decided for AUTO.
     * Consider the case of after filename is inputed but drive is removed.
     */
    if (!cntx->param.select_storage)
    {
        if (cntx->param.storage == SRV_DA_STORAGE_AUTO ||
            cntx->param.storage == SRV_DA_STORAGE_PUSH_TEMP)
        {
            srv_da_storage_enum storage;
            U16 drv;
        
            if (!srv_da_util_decide_drive_to_save_file(
                cntx->param.original_filepath,
                cntx->param.filesize, 
                &(drv),
                &(storage)) )
            {
                if (srv_da_get_number_of_available_drives() > 0)
                {
                    mmi_da_app_show_popup_ext(STR_GLOBAL_NOT_ENOUGH_MEMORY, SRV_DA_POPUP_TYPE_ERROR);  //TBD
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_INSUFFICIENT_MEMORY;
                }
                else
                {
                    mmi_da_app_show_popup_ext(STR_GLOBAL_INSERT_MEMORY_CARD, SRV_DA_POPUP_TYPE_ERROR);  //TBD
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_NO_AVAILABLE_STORAGE;
                }

                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);

                return;
            }

            cntx->param.drv = (S32)drv;
        }
    }

    if (!mmi_da_app_scr_select_storage_check_drive(cntx))
    {
        /* Problem on the drive, go back directly */
        return;
    }
    
    full_filename = (U16*)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(U16));
    
    if (cntx->param.fileext[0] != L'\0')
    {
        kal_wsprintf(full_filename, "%w.%w", cntx->param.filename, cntx->param.fileext);
    }
    else
    {
        mmi_wcscpy(full_filename, cntx->param.filename);
    }

    /* If filename is invalid, we assign a temp filename here */
    if (!srv_fmgr_path_is_filename_valid(full_filename))
    {
        U16 *folder_path;

        folder_path = (U16*)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        kal_wsprintf(folder_path, "%c:\\%w", cntx->param.drv, cntx->param.folder);
        srv_da_util_get_temp_filename(folder_path, cntx->filepath, SRV_FMGR_PATH_MAX_LEN);
        mmi_wcscpy(cntx->param.filename, srv_da_util_get_filename(cntx->filepath));
        srv_srv_da_adp_mem_free(folder_path);
    }

    srv_srv_da_adp_mem_free(full_filename);

    /* complete full path */
    if(cntx->param.fileext[0] != L'\0')
    {
        kal_wsprintf(cntx->filepath, "%c:\\%w%w.%w", 
                     cntx->param.drv, 
                     cntx->param.folder, 
                     cntx->param.filename,
                     cntx->param.fileext);
    }
    else
    {
        /* no ext */
        kal_wsprintf(cntx->filepath, "%c:\\%w%w",
                     cntx->param.drv, 
                     cntx->param.folder, 
                     cntx->param.filename);
    }

    if (cntx->param.original_filepath != NULL &&
        mmi_wcsicmp(cntx->filepath, cntx->param.original_filepath) == 0)
    {
        /* Path is not changed, following checkings are unnecessary */
        mmi_da_app_scr_storage_callback(cntx, cntx->filepath, MMI_FALSE, MMI_TRUE);
        return;
    }
    
    /* Create folder for the file */
    result = srv_da_util_create_file_dir(cntx->filepath, MMI_TRUE);
    if (result < 0)
    {
        //DA_TRACE_FUNC2(mmi_da_app_scr_select_storage, 170, result);
        mmi_da_app_show_popup_ext(srv_fmgr_fs_error_get_string(result), SRV_DA_POPUP_TYPE_ERROR);

        if (mmi_da_app_scr_select_storage_is_drive_cause(result))
        {
            mmi_da_app_scr_select_storage_go_back_on_drive_cause(
                cntx,
                SRV_DA_SCR_SELECT_STORAGE_CAUSE_FS_ERROR);
        }
        else
        {
            cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_FS_ERROR;
            mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
        }
        return;
    }

    if (cntx->param.filecheck_func != NULL &&
        cntx->param.filecheck_func(cntx->filepath, MMI_FALSE))
    {
        /*
         * File path is already occupied by other items, we can not use.
         * The original filepath does not equal to the new filepath, because we have checked.
         */
    
        if (cntx->param.select_filename)
        {
            cntx->param.filecheck_func(cntx->filepath, MMI_TRUE); /* Popup error message */
            /* Back to input name screen after the popup */
            return;
        }
        else
        {
            /* User did not choose the name, decide a new name automatically */
            //DA_TRACE_FUNC1(mmi_da_app_scr_select_storage, 200);
            srv_da_util_get_clear_filepath(cntx->filepath, cntx->param.filecheck_func);
        }
    }

    if (!cntx->param.skip_exist_check &&
        srv_da_util_does_file_exist(cntx->filepath))
    {
        /*
         * File already exists, assign a new name or show overwrite prompt.
         * The original filepath does not equal to the new filepath, because we have checked.
         */
        if (cntx->param.select_filename)
        {
            /* User decided the filename, show a confirmation */
            mmi_confirm_property_struct confirm_arg;

            mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
            confirm_arg.callback = mmi_da_app_scr_overwrite_confirm_proc;
            confirm_arg.user_tag = (void*)cntx;
            mmi_confirm_display(
                get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE),
                MMI_EVENT_QUERY,
                &confirm_arg);
            return;
        }
        else
        {
            /* User did not choose the name, decide a new name automatically */
            //DA_TRACE_FUNC1(mmi_da_app_scr_select_storage, 300);
            srv_da_util_get_clear_filepath(cntx->filepath, cntx->param.filecheck_func);
        }
    }

    /* if all ok, call back to User */
    mmi_da_app_scr_storage_callback(cntx, cntx->filepath, MMI_FALSE, MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage_decide_filename
 * DESCRIPTION
 *  Decide the filename.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_select_storage_decide_filename(
    mmi_da_scr_select_storage_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->param.select_filename)
    {
        mmi_wcsncpy(cntx->filename_buffer, cntx->param.filename, MMI_DA_MAX_FILENAME_INPUT_LEN);
        
        cntx->cui_filename_editor = cui_filename_editor_create(
            cntx->grp_id,
            cntx->filename_buffer,
            sizeof(cntx->filename_buffer),
            MMI_DA_MAX_FILENAME_INPUT_LEN,
            NULL,
            NULL);

        cui_filename_editor_set_title(
            cntx->cui_filename_editor,
            STR_GLOBAL_FILENAME,
            cntx->icon_id);

        if (cntx->cui_filename_editor > 0)
        {
            cui_filename_editor_run(cntx->cui_filename_editor);
        }
        else
        {
            /* Insufficient resource, generate in mmi_da_scr_select_storage_final() */
            cntx->param.select_filename = MMI_FALSE;
            mmi_da_app_scr_select_storage_final(cntx);
        }
    }
    else
    {
        /* If filename was not given, we will generate one in mmi_da_app_scr_select_storage_final() */
        mmi_da_app_scr_select_storage_final(cntx);
    }
}


static mmi_ret mmi_da_app_select_storage_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_da_scr_select_storage_context_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            cui_storage_selector_result_event_struct *drive_evt;
            
            drive_evt = (cui_storage_selector_result_event_struct*)evt;

            if (drive_evt->result > 0) /* User selected */
            {
                if (srv_da_util_is_drive_available((U16)drive_evt->result))
                {
                    cntx->param.drv = (U16)drive_evt->result;
                    mmi_da_app_scr_select_storage_decide_filename(cntx);
                }
                else /* Drive not available */
                {
                    mmi_da_app_show_popup_ext(STR_ID_DA_ERROR_STORAGE_IS_UNAVAILABLE, SRV_DA_POPUP_TYPE_ERROR);
                }
            }
            else if (drive_evt->result == 0) /* Cancelled */
            {
                cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_USER_BACK;
                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_TRUE);
            }
            else /* Error */
            {
                mmi_da_app_show_popup_ext(STR_GLOBAL_ERROR, SRV_DA_POPUP_TYPE_ERROR);
                cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_UNEXPECTED_ERROR;
                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
            }

            break;
        }
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            cui_filename_editor_result_event_struct *filename_evt;

            filename_evt = (cui_filename_editor_result_event_struct*)evt;

            if (filename_evt->result > 0) /* User inputted */
            {
                /* Filename is valid and decided by user, we can discard the original filename */
                mmi_wcscpy(cntx->param.filename, cntx->filename_buffer);
				#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
                mmi_da_app_scr_select_storage_final_ext(cntx);
				#else
                mmi_da_app_scr_select_storage_final(cntx);
				#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
            }
            else if (filename_evt->result == 0) /* Back */
            {
                if (cntx->cui_select_drive > 0)
                {
                    /* Back to select-drive screen */
                    cui_filename_editor_close(cntx->cui_filename_editor);
                    cntx->cui_filename_editor = 0;
                }
                else
                {
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_USER_BACK;
                    mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_TRUE);
                }
            }
            else /* Unexpected error */
            {
                mmi_da_app_show_popup_ext(STR_GLOBAL_ERROR, SRV_DA_POPUP_TYPE_ERROR);  //TBD
                cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_UNEXPECTED_ERROR;
                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
            }

            break;
        }
		#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
            {
                cui_folder_selector_result_event_struct *fmgr_evt = (cui_folder_selector_result_event_struct*)evt;
                if(fmgr_evt->result > 0)
                {
                    S32 error_code = FS_NO_ERROR;
                    srv_fmgr_fileinfo_struct info;
                    error_code = cui_folder_selector_get_selected_filepath(fmgr_evt->sender_id, &info, (WCHAR*)cntx->folder_path, (SRV_FMGR_PATH_MAX_LEN+1));
                    if(error_code < 0)
                    {
                        mmi_da_app_show_popup_ext(STR_GLOBAL_ERROR, SRV_DA_POPUP_TYPE_ERROR);
                        cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_UNEXPECTED_ERROR;
                        mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
                    }
                    else
                    {
                        cntx->param.drv = (U16)cntx->folder_path[0];
                        mmi_da_app_scr_select_storage_decide_filename(cntx);
                    }
                }
                else if (fmgr_evt->result == 0)
                {
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_USER_BACK;
                    mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_TRUE);
                }
                else
                {
                    mmi_da_app_show_popup_ext(STR_GLOBAL_ERROR, SRV_DA_POPUP_TYPE_ERROR);
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_UNEXPECTED_ERROR;
                    mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
                }
            }
            break;
    #endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:

            if (cntx->already_called_back)
            {
                /* Already callback */
            }
            else if (cntx->grp_id > 0) /* Not closed by mmi_da_scr_close_select_storage() */
            {
                cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_DELETE_SCREEN;
                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_TRUE, MMI_FALSE);
            }
            
            break;

        case EVT_ID_GROUP_DEINIT:
            mmi_da_app_scr_select_storage_free_context(cntx);
            break;
    }

    return MMI_RET_OK;
}


static void mmi_da_app_scr_select_storage_init_cntx(
    mmi_da_scr_select_storage_context_struct *cntx,
    mmi_da_scr_storage_callback_type callback,
    const mmi_da_scr_storage_parameter_struct* param,
    U32 arg,
    U16 title_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&(cntx->param), param, sizeof(mmi_da_scr_storage_parameter_struct));
    cntx->callback = callback;
    cntx->icon_id = title_icon_id;
    cntx->user_data = arg;
#ifndef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
	/* Check the number of drives, we don't let user to select storage when #drives <= 1 */
    if (srv_da_get_number_of_available_drives() <= 1 && cntx->param.select_storage)
    {
        cntx->param.select_storage = MMI_FALSE;
        cntx->param.storage = SRV_DA_STORAGE_AUTO;
        cntx->param.drv = SRV_FMGR_PUBLIC_DRV;
    }
#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */    
    
    cntx->already_called_back = MMI_FALSE;
    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_NONE;
    cntx->filename_buffer[0] = L'\0';
}

#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_select_storage_final_ext
 * DESCRIPTION
 *  Complete variables passed to call back and do final checks.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_select_storage_final_ext(mmi_da_scr_select_storage_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *full_filename;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cntx->param.original_filepath != NULL &&
        !srv_da_util_does_file_exist(cntx->param.original_filepath))
    {
        //DA_TRACE_FUNC1(mmi_da_scr_select_storage, 150);
        cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_ORIGINAL_FILE_LOST;
        mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_TRUE);
        return;
    }

    /*
     * Decide storage again after filename is decided for AUTO.
     * Consider the case of after filename is inputed but drive is removed.
     */
    if (!cntx->param.select_storage)
    {
        if (cntx->param.storage == SRV_DA_STORAGE_AUTO ||
            cntx->param.storage == SRV_DA_STORAGE_PUSH_TEMP)
        {
            srv_da_storage_enum storage;
            U16 drv;
        
            if (!srv_da_util_decide_drive_to_save_file(
                cntx->param.original_filepath,
                cntx->param.filesize, 
                &(drv),
                &(storage)) )
            {
                if (srv_da_get_number_of_available_drives() > 0)
                {
                    mmi_da_app_show_popup_ext(STR_GLOBAL_NOT_ENOUGH_MEMORY, SRV_DA_POPUP_TYPE_ERROR); 
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_INSUFFICIENT_MEMORY;
                }
                else
                {
                    mmi_da_app_show_popup_ext(STR_GLOBAL_INSERT_MEMORY_CARD, SRV_DA_POPUP_TYPE_ERROR); //to do
                    cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_NO_AVAILABLE_STORAGE;
                }

                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);

                return;
            }

            cntx->param.drv = (S32)drv;
        }
    }

    //TODO:: Check if path is available
    //if (!mmi_da_scr_select_storage_check_drive(cntx))
    {
        /* Problem on the drive, go back directly */
        //return;
    }

    full_filename = (U16*)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(U16));
    
    if (cntx->param.fileext[0] != L'\0')
    {
        kal_wsprintf(full_filename, "%w.%w", cntx->param.filename, cntx->param.fileext);
    }
    else
    {
        mmi_wcscpy(full_filename, cntx->param.filename);
    }

    /* If filename is invalid, we assign a temp filename here */
    if (!srv_fmgr_path_is_filename_valid(full_filename))
    {
        //U16 *folder_path;

        //folder_path = (U16*)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        //kal_wsprintf(folder_path, "%c:\\%w", cntx->param.drv, cntx->param.folder);
        srv_da_util_get_temp_filename(cntx->folder_path, cntx->filepath, SRV_FMGR_PATH_MAX_LEN);
        mmi_wcscpy(cntx->param.filename, srv_da_util_get_filename(cntx->filepath));
        //srv_srv_da_adp_mem_free(folder_path);
    }

    srv_srv_da_adp_mem_free(full_filename);

    /* complete full path */
    if(cntx->param.fileext[0] != L'\0')
    {
        if (cntx->folder_path[0] != L'\0')
        {
        kal_wsprintf(cntx->filepath, "%w%w.%w", 
                     cntx->folder_path, 
                     cntx->param.filename,
                     cntx->param.fileext);
    }
    else
    {
            kal_wsprintf(cntx->filepath, "%c:\\%w%w.%w", 
                cntx->param.drv, 
                cntx->param.folder, 
                cntx->param.filename,
                cntx->param.fileext);
        }
    }
    else
    {
        /* no ext */
        if (cntx->folder_path[0] != L'\0')
        {
        kal_wsprintf(cntx->filepath, "%w%w",
                     cntx->folder_path, 
                     cntx->param.filename);
    }
        else
        {
            kal_wsprintf(cntx->filepath, "%c:\\%w%w",
                cntx->param.drv, 
                cntx->param.folder, 
                cntx->param.filename);
        }
    }

    if (cntx->param.original_filepath != NULL &&
        mmi_wcsicmp(cntx->filepath, cntx->param.original_filepath) == 0)
    {
        /* Path is not changed, following checkings are unnecessary */
        mmi_da_app_scr_storage_callback(cntx, cntx->filepath, MMI_FALSE, MMI_TRUE);
        return;
    }
    
    /* Create folder for the file */
    result = srv_da_util_create_file_dir_ext(cntx->filepath, MMI_TRUE);
    if (result < 0)
    {
        //DA_TRACE_FUNC2(mmi_da_scr_select_storage, 170, result);
        mmi_da_app_show_popup_ext(srv_fmgr_fs_error_get_string(result), SRV_DA_POPUP_TYPE_ERROR);

        cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_FS_ERROR;
        mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);

        //TODO:: Below check can be implemented
        //if (mmi_da_scr_select_storage_is_drive_cause(result))
        //{
           // mmi_da_scr_select_storage_go_back_on_drive_cause(
               // cntx,
                //MMI_DA_SCR_SELECT_STORAGE_CAUSE_FS_ERROR);
        //}
        //else
        //{
            //cntx->cause = MMI_DA_SCR_SELECT_STORAGE_CAUSE_FS_ERROR;
           // mmi_da_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
        //}
        return;
    }

    if (cntx->param.filecheck_func != NULL &&
        cntx->param.filecheck_func(cntx->filepath, MMI_FALSE))
    {
        /*
         * File path is already occupied by other items, we can not use.
         * The original filepath does not equal to the new filepath, because we have checked.
         */
    
        if (cntx->param.select_filename)
        {
            cntx->param.filecheck_func(cntx->filepath, MMI_TRUE); /* Popup error message */
            /* Back to input name screen after the popup */
            return;
        }
        else
        {
            /* User did not choose the name, decide a new name automatically */
            //DA_TRACE_FUNC1(mmi_da_scr_select_storage, 200);
            srv_da_util_get_clear_filepath(cntx->filepath, cntx->param.filecheck_func);
        }
    }

    if (!cntx->param.skip_exist_check &&
        srv_da_util_does_file_exist(cntx->filepath))
    {
        /*
         * File already exists, assign a new name or show overwrite prompt.
         * The original filepath does not equal to the new filepath, because we have checked.
         */
        if (cntx->param.select_filename)
        {
            /* User decided the filename, show a confirmation */
            mmi_confirm_property_struct confirm_arg;

            mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
            confirm_arg.callback = mmi_da_app_scr_overwrite_confirm_proc;
            confirm_arg.user_tag = (void*)cntx;
            mmi_confirm_display(
                get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE),
                MMI_EVENT_QUERY,
                &confirm_arg);
            return;
        }
        else
        {
            /* User did not choose the name, decide a new name automatically */
            //DA_TRACE_FUNC1(mmi_da_scr_select_storage, 300);
            srv_da_util_get_clear_filepath(cntx->filepath, cntx->param.filecheck_func);
        }
    }

    /* if all ok, call back to User */
    mmi_da_app_scr_storage_callback(cntx, cntx->filepath, MMI_FALSE, MMI_TRUE);
}
#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */





/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_select_storage
 * DESCRIPTION
 *  The exported API of select-storage.
 * PARAMETERS
 *  callback        [IN] Result callback function
 *  parameter       [IN] Parameter to control policy and screen flow.
 *  arg             [IN] Will be passed to the callback
 *  title_icon_id   [IN] Title icon ID
 * RETURNS
 *  Instance handler, maybe NULL if the callback is called directly
 *****************************************************************************/
void* mmi_da_app_scr_select_storage(mmi_da_scr_storage_callback_type callback,
    mmi_da_scr_storage_parameter_struct* parameter,
    U32 arg,
    U16 title_icon_id)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;
#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
    U8                          drvLetter;
#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
   // mmi_da_screen_group_id_enum  grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_da_app_scr_select_storage_allocate_context();

    if (cntx == NULL)
    {
        mmi_da_app_show_popup_ext(STR_GLOBAL_INSUFFICIENT_MEMORY, SRV_DA_POPUP_TYPE_ERROR);  //TBD
        mmi_da_app_scr_storage_callback(NULL, NULL, MMI_FALSE, MMI_FALSE);
        return NULL;
    }

    mmi_da_app_scr_select_storage_init_cntx(
        cntx,
        callback,
        parameter,
        arg,
        title_icon_id);

    cntx->cui_select_drive = 0;
    cntx->cui_filename_editor = 0;

    if (cntx->param.select_storage || cntx->param.select_filename)
    {
        if(!mmi_da_is_app_launched())
        {
            mmi_da_launch_app(MMI_DA_LAUNCH_FROM_BROWSER);
        }
        if(!mmi_frm_group_is_present(MMI_DA_DOWNLOAD_LIST_GROUP))
        {
			if(!mmi_frm_group_is_present(MMI_DA_CONFIRM_SCREEN_GROUP))
			{
				mmi_frm_group_create_ex(MMI_DA_BRW_ENTRY_SCREEN_GROUP, 
											   MMI_DA_CONFIRM_SCREEN_GROUP,
											   mmi_da_app_choice_scr_group_proc,
											   (void*)NULL,
											   MMI_FRM_NODE_SMART_CLOSE_FLAG);				
			}
            cntx->grp_id = mmi_frm_group_create_ex(
                        MMI_DA_CONFIRM_SCREEN_GROUP,
                        MMI_DA_STORAGE_SELECTOR_GROUP,
                        mmi_da_app_select_storage_grp_proc,
                        cntx,
                        MMI_FRM_NODE_NONE_FLAG);
        }
        else
        {
            cntx->grp_id = mmi_frm_group_create_ex(
                        MMI_DA_DOWNLOAD_LIST_GROUP,
                        MMI_DA_STORAGE_SELECTOR_GROUP,
                        mmi_da_app_select_storage_grp_proc,
                        cntx,
                        MMI_FRM_NODE_NONE_FLAG);
            g_mmi_da_context.da_app_scr_group_id = MMI_DA_DOWNLOAD_LIST_GROUP; 
        }      
    }
    else
    {
        cntx->grp_id = 0;
    }

    if (cntx->param.select_storage)
    {
        if (mmi_da_app_scr_show_select_drive(cntx))
        {
            /* Select-drive screen has been shown, return the instance */
            return cntx;
        }
        else
        {
            /* Insufficient resource, decide drive automatically */
            cntx->param.select_storage = MMI_FALSE;
            cntx->param.storage = SRV_DA_STORAGE_AUTO;
        }
    }

    if (!cntx->param.select_storage)
    {
        /* Decide drive automatically */
        if (cntx->param.storage == SRV_DA_STORAGE_AUTO ||
            cntx->param.storage == SRV_DA_STORAGE_PUSH_TEMP)
        {
            srv_da_storage_enum storage;
            U16 drv;
        
            if (srv_da_util_decide_drive_to_save_file(
                cntx->param.original_filepath,
                cntx->param.filesize, 
                &(drv),
                &(storage)) )
            {
                /* Ok. We got an available drive. */
            }
            else if (cntx->param.storage == SRV_DA_STORAGE_PUSH_TEMP &&
                cntx->param.original_filepath != NULL)
            {
                /* Dispatch from the original path directly */
                mmi_da_app_scr_storage_callback(cntx, cntx->param.original_filepath, MMI_FALSE, MMI_TRUE);
                return NULL;
            }
            else if (srv_da_get_number_of_available_drives() > 0)
            {
                mmi_da_app_show_popup_ext(STR_GLOBAL_NOT_ENOUGH_MEMORY, SRV_DA_POPUP_TYPE_ERROR);  //TBD
                cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_INSUFFICIENT_MEMORY;
                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
                return NULL;
            }
            else
            {
                mmi_da_app_show_popup_ext(STR_GLOBAL_INSERT_MEMORY_CARD, SRV_DA_POPUP_TYPE_ERROR);  //TBD
                cntx->cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_NO_AVAILABLE_STORAGE;
                mmi_da_app_scr_storage_callback(cntx, NULL, MMI_FALSE, MMI_FALSE);
                return NULL;
            }

            cntx->param.drv = (S32)drv;
			#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
            //drvLetter = srv_fmgr_drv_get_letter_by_type (drv);
            kal_wsprintf(cntx->folder_path, "%c:\\%w", drv, cntx->param.folder);
        #endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
        }
    }

    /* Decide filename */
    mmi_da_app_scr_select_storage_decide_filename(cntx);
    
    if (!cntx->param.select_filename)
    {
        /* Was called-back in mmi_da_app_scr_select_storage_decide_filename */
        return NULL;
    }

    return cntx;
}

void mmi_da_app_curr_job_exit_abort_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_QUERY));
}
#ifndef MMI_DA_PLUTO_SLIM
S32 mmi_da_app_job_get_display_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_item_progress_struct info;
    U32                         percentage;
    S8                          *dl_str;
    S32                         i;
    U16                         icon_id;
    U16                         *ui_item_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(i=0; i<data_size; i++)
    {
        job = srv_da_get_nth_job(i + start_index);
        MMI_ASSERT(job);

        ui_item_buffer = (U16*)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        
        job->op->get_name(job, ui_item_buffer, SRV_FMGR_PATH_MAX_LEN + 1);

        /* MAUI_01038572 */
        /* Truncate too long tail to suit the MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE/ENCODING_LENGTH */ 
        if (mmi_wcslen(ui_item_buffer) > (MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE/ENCODING_LENGTH - 1))
        {
            mmi_wcscpy(
                (ui_item_buffer + MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE/ENCODING_LENGTH - 1 - 3),
                L"...");
        }

        mmi_wcscpy(menu_data[i].item_list[0], ui_item_buffer);

        srv_srv_da_adp_mem_free(ui_item_buffer);
#if defined (__MMI_OMA_DD_DOWNLOAD__)
       if (job->type == SRV_DA_JOB_TYPE_OMADL)
		mmi_da_oma_get_item_progress(job, &info);
		else
#endif 
		{
			info.processing_string_id = 0;
		
		}
        percentage = DA_JOB_GET_PROGRESS(job, info);

        dl_str = srv_da_util_format_size_total(info.currSize, info.fileSize);

        mmi_asc_to_ucs2((S8*)menu_data[i].item_list[2], (S8*)dl_str);

        if(percentage != MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
        {
            /* kal_wsprintf() does not support "%%" */
            kal_wsprintf(menu_data[i].item_list[1], "%d%c", percentage, '%');
        }
        else
        {
            menu_data[i].item_list[1][0] = L'\0';
        }

        switch(job->state)
        {
            case SRV_DA_JOB_STATE_DOWNLOADING:
            case SRV_DA_JOB_STATE_ABORTING:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_LOADING;
                break;

            case SRV_DA_JOB_STATE_PROCESSING:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_PROCESSING;
                break;

            case SRV_DA_JOB_STATE_COMPLETED:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_COMPLETE;
                break;

#ifdef __MMI_DA_RESUME__
            case SRV_DA_JOB_STATE_PAUSED:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_PAUSE;
                break;
#endif

            case SRV_DA_JOB_STATE_ABORTED:
            case SRV_DA_JOB_STATE_FAILED:
            default:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_PROCESSING;
                break;
        }

        menu_data[i].image_list[0] = (PU8)GetImage((U16)icon_id);
    }
    return i;
}
#endif
void mmi_da_remove_job_screens(srv_da_job_struct *job, MMI_BOOL is_in_job_specific_screen, S32 index)
{

    if(g_mmi_da_context.job_list_highlight_index == index)
    {
        g_mmi_da_context.job_list_highlight_index = -1;
    }
    else if(index != -1 && g_mmi_da_context.job_list_highlight_index > index)
    {
        g_mmi_da_context.job_list_highlight_index--;
    }
    if (srv_da_get_job_list_num() == 0)
    {
        if(mmi_frm_group_is_present(MMI_DA_DOWNLOAD_LIST_GROUP))
            mmi_frm_group_close(g_mmi_da_context.da_app_scr_group_id);
    }

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    mmi_da_close_job_list_option();
#endif
    if (is_in_job_specific_screen)
    {
	
        mmi_da_scr_remove_screen(SCR_ID_DA_JOB_DETAIL);
        mmi_da_scr_remove_screen(SCR_ID_DA_JOB_OBJECT_DESCRIPTION);

        if(mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_ABORT_CONFIRM)
        {
            mmi_frm_scrn_close_active_id();
        }
  
	
    }
#if defined (__MMI_NCENTER_SUPPORT__)
	mmi_da_cancel_alert(job);
#endif

    if(srv_da_get_job_list_num()  && srv_da_job_list_updated() && mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_LIST)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__        
        /* refresh */
        if(g_mmi_da_context.job_list_highlight_index < 0 || g_mmi_da_context.job_list_highlight_index >= srv_da_get_job_list_num())
            g_mmi_da_context.job_list_highlight_index = 0;
        mmi_cat_refresh_asyncdynamic_list(srv_da_get_job_list_num(), 
            g_mmi_da_context.job_list_highlight_index, 
            mmi_da_job_get_display_item, NULL);
#endif

    }

    //TODO DA_TRACE_ENDFUNC(mmi_da_free_job_and_remove_screens);

    /* send download info indication when job count is updated */
    if(srv_da_job_list_updated())
    {
        srv_da_send_download_info_ind();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_use_file_selected
 * DESCRIPTION
 *  User selected "Use file" item. Call dispatch handler
 * PARAMETERS
 *  job     [IN] Target job
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_on_use_file_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    
    /* If the user is already allowed to use the file and try to use,
       we will not notify complete again. */
    job->notified_complete = MMI_TRUE;
    
    if (mmi_da_job_check_file_before_operation(job) != SRV_DA_FILESTAMP_CHECK_OK)
    {
        return;
    }

#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_da_is_in_voice_call() && !srv_ucm_is_background_call())
#else
    if (srv_da_is_in_voice_call())
#endif
    {
        mmi_da_app_show_popup_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, SRV_DA_POPUP_TYPE_ERROR);
    }
    else
    {
        MMI_ASSERT(job->op->dispatch != NULL);
        job->op->dispatch(job);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_play_selected
 * DESCRIPTION
 *  User selected "Play" item. This function is available only for progressive
 *  download. Continue to report to the application.
 * PARAMETERS
 *  job     [IN] Target job
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_on_play_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_da_is_in_voice_call())
    {
        mmi_da_app_show_popup_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, SRV_DA_POPUP_TYPE_ERROR);
        return;
    }
    
    if (!job->reporting &&
        job->setting_info.filepath_hdlr != NULL &&
        job->state == SRV_DA_JOB_STATE_DOWNLOADING)
    {
        srv_da_item_progress_struct info;
        S32 job_id;

        job_id = DA_JOB_UNIQUE_ID(job);
    #if defined (__MMI_OMA_DD_DOWNLOAD__)
          if (job->type == SRV_DA_JOB_TYPE_OMADL)
		 mmi_da_oma_get_item_progress(job, &info);
		else
    #endif 
		{
			info.processing_string_id = 0;
    
		}
		DA_JOB_GET_PROGRESS(job, info);
        MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_FILEPATH_HDLR, job_id);

        /* Note app may call stop_pdl() in filepath_hdlr() */
        job->reporting = MMI_TRUE;
        
        job->setting_info.filepath_hdlr(
            DA_JOB_UNIQUE_ID(job),
            job->mime_type->mime_type,
            job->mime_type->mime_subtype,
            (U16*)job->op->get_filepath(job));
#ifndef MMI_DA_PLUTO_SLIM
        srv_da_report_to_app(job, &info);   //slim Will check job->reporting here
#endif    
    }
}


#ifdef __MMI_DA_RESUME__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_resume_selected
 * DESCRIPTION
 *  User selected "Resume". Resume the suspended download
 * PARAMETERS
 *  job     [IN] Target job
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_on_resume_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_da_job_check_file_before_operation(job) != SRV_DA_FILESTAMP_CHECK_OK)
    {
        return;
    }
    
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_PAUSED);
    MMI_ASSERT(job->op->resume);

    srv_da_set_allow_to_trigger_connection(MMI_TRUE);

    /* Don't start to report immediately when user resume the download */
    job->reporting = MMI_FALSE;

    if(srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_DOWNLOADING) +
        srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_PROCESSING) >= MMI_DA_MAX_DL)
    {
        mmi_da_app_show_popup_ext(STR_ID_DA_PROMPT_EXCEED_MAX_DL, SRV_DA_POPUP_TYPE_ERROR);
    }
    else
    {
        srv_da_job_resume(job);
    }
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_cancel_selected
 * DESCRIPTION
 *  User selected "Cancel". Show cancel confirm screen.
 * PARAMETERS
 *  job     [IN] Target job
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_on_cancel_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_set_curr_job(job);
    mmi_da_app_curr_job_entry_abort_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_remove_selected
 * DESCRIPTION
 *  User selected "Remove". Remove the item which is completed.
 * PARAMETERS
 *  job     [IN] Target job
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_on_remove_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    mmi_da_app_show_popup_ext(STR_GLOBAL_DONE, SRV_DA_POPUP_TYPE_DONE);
    //mmi_da_update_completed_cells(job);
#if defined (__MMI_NCENTER_SUPPORT__)
    if (job->notify_handle != NULL)
    {
		vsrv_ncenter_close_notification(job->notify_handle);
        mmi_da_cancel_alert(job);
    }
#endif
    srv_da_free_job_and_remove_screens(job);
}
#endif // multi
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_suspended_callback
 * DESCRIPTION
 *  Callback for suspended
 * PARAMETERS
 *  job         [IN] Job
 *  string_id   [IN] String to show
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_suspended_callback(srv_da_job_struct* job, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_ABORTED);
    job->state = SRV_DA_JOB_STATE_PAUSED;

    if( mmi_da_app_is_in_foreground_state() || mmi_frm_scrn_get_active_id() == SCR_ID_DA_WAITING_DUMMY)
    {
        mmi_da_app_show_popup_ext(STR_ID_DA_POPUP_SUSPENDED, SRV_DA_POPUP_TYPE_DONE);
    }
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_OBJECT_DESCRIPTION); 
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_DETAIL);
    //DeleteScreenIfPresent(SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
    //DeleteScreenIfPresent(SCR_ID_DA_JOB_DETAIL);
    mmi_da_close_job_list_option();
    srv_da_update_job_status(job);

    job->reporting = MMI_FALSE;
}

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_suspend_selected
 * DESCRIPTION
 *  Suspend option handler.
 * PARAMETERS
 *  job         [IN] Job to be suspended
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_on_suspend_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    prev_state = job->state;
    
    switch(prev_state)
    {
    case SRV_DA_JOB_STATE_DOWNLOADING:
    
        job->state = SRV_DA_JOB_STATE_ABORTING;
        job->was_stopped_by_upper_layer = MMI_TRUE;

        //EntryNewScreen(SCR_ID_DA_WAITING_DUMMY, NULL, NULL, NULL);
        mmi_frm_display_dummy_screen_ex(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_WAITING_DUMMY);
        ClearInputEventHandler(MMI_DEVICE_ALL);
        
        job->op->stop(job, 
                      prev_state,
                      MMI_TRUE,
                      mmi_da_job_suspended_callback);
        break;
        
    default:
        mmi_da_close_job_list_option();
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DUMMY)
        {
            mmi_frm_scrn_close_active_id();
        }
        break;
    }
}
#endif 
#endif //multi & fte
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_select_storage_get_cause
 * DESCRIPTION
 *  Get the cause of callback.
 * PARAMETERS
 *  instance    [IN] Instance
 * RETURNS
 *  Cause
 *****************************************************************************/
srv_da_scr_select_storage_cause_enum mmi_da_scr_select_storage_get_cause(void *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_select_storage_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_da_scr_select_storage_context_struct*)instance;

    return cntx->cause;
}
//#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_async_move_delete_moving
 * DESCRIPTION
 *  Delete function for moving screen. This function will cancel the move and
 *  release resources.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_async_move_delete_moving(void *arg, MMI_BOOL is_deleted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_async_move_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_da_scr_async_move_cntx_p;

    if (cntx != NULL)
    {
        cntx->is_deleted = is_deleted;

        if (cntx->in_moving)
        {
            srv_da_util_cancel_async_move();
            cntx->in_moving = MMI_FALSE;
            cntx->cancelled_by_upper_layer = MMI_TRUE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_async_move_deinit
 * DESCRIPTION
 *  Deinitialization function for UI-asynchronous move
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_async_move_deinit(mmi_da_scr_async_move_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == g_mmi_da_scr_async_move_cntx_p)
    {
        g_mmi_da_scr_async_move_cntx_p = NULL;
    }

    /* It should not be in moving */
    MMI_ASSERT(!cntx->in_moving);
    
    mmi_da_scr_progressing_close(cntx->screen_id);

    srv_srv_da_adp_mem_free(cntx->src_path);
    srv_srv_da_adp_mem_free(cntx->dest_path);
    srv_srv_da_adp_mem_free(cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_async_move_result_callback
 * DESCRIPTION
 *  Result callback function for asynchronous move API
 * PARAMETERS
 *  arg         [IN] Argument
 *  error_code  [IN] Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_async_move_result_callback(void *arg, S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_async_move_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_da_scr_async_move_cntx_p != NULL);

    cntx = g_mmi_da_scr_async_move_cntx_p;

    cntx->in_moving = MMI_FALSE;

    if (cntx->result_callback)
    {
        if (error_code == FS_ABORTED_ERROR && cntx->cancelled_by_upper_layer)
        {
            /* Aborted by upper layer */
            cntx->cancel_callback(cntx->arg, cntx->is_deleted);
        }
        else
        {
            cntx->result_callback(cntx->arg, error_code);
        }
    }

    mmi_da_scr_async_move_deinit(cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_async_move
 * DESCRIPTION
 *  Asnychronous move utility. This utility shows a "Please wait" screen
 *  during moving. And also provide handlings for cancellation.
 * PARAMETERS
 *  title_string_id     [IN] Title string ID for moveing screen
 *  title_icon_id       [IN] Title icon ID
 *  src_path            [IN] Source filepath
 *  dest_path           [IN] Destination filepath
 *  arg                 [IN] Client argument pointer, this pointer will be passed to
 *                           result_callback() and cancel_callback()
 *  result_callback     [IN] Result callback
 *  cancel_callback     [IN] Cancel callback. Note if client calls mmi_da_scr_async_move_cancel()
 *                           this function will also be invoked.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_async_move(
        U16 screen_id,
        U16 title_string_id,
        U16 title_icon_id,
        const U16 *src_path,
        const U16 *dest_path,
        MMI_BOOL cancel_rsk,
        void *arg, /* Pass to result_callback */
        void (*result_callback)(void *arg, S32 error_code),
        void (*cancel_callback)(void *arg, MMI_BOOL is_deleted))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_async_move_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_da_scr_async_move_cntx_p == NULL);

    g_mmi_da_scr_async_move_cntx_p =
        (mmi_da_scr_async_move_cntx_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_async_move_cntx_struct));
    cntx = g_mmi_da_scr_async_move_cntx_p;

    cntx->screen_id = screen_id;
    cntx->title_string_id = title_string_id;
    cntx->title_icon_id = title_icon_id;
    cntx->src_path = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(src_path) + 1) * sizeof(U16));
    mmi_wcscpy(cntx->src_path, src_path);
    cntx->dest_path = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(dest_path) + 1) * sizeof(U16));
    mmi_wcscpy(cntx->dest_path, dest_path);
    cntx->cancel_rsk = cancel_rsk;
    cntx->arg = arg;
    cntx->result_callback = result_callback;
    cntx->cancel_callback = cancel_callback;
    cntx->in_moving = MMI_FALSE;
    cntx->cancelled_by_upper_layer = MMI_FALSE;
    cntx->is_deleted = MMI_FALSE;
    
    mmi_da_app_scr_show_progressing(
        cntx->screen_id,
        cntx->title_string_id,
        cntx->title_icon_id,
        SRV_DA_PLEASE_WAIT,
        MMI_FALSE,
        cntx,
        mmi_da_scr_async_move_delete_moving);

    cntx->in_moving = MMI_TRUE;

    srv_da_util_async_move(
        cntx->src_path,
        cntx->dest_path,
        cntx,
        mmi_da_scr_async_move_result_callback);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_async_move_result_callback
 * DESCRIPTION
 *  Result callback for the async move of a move.
 * PARAMETERS
 *  arg         [IN] (mmi_da_job_struct*)Job
 *  error_code  [IN] FS error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_async_move_result_callback(void *arg, S32 error_code)
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
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DOWNLOAD_MOVING)
        {
            mmi_da_app_show_popup_ext(STR_GLOBAL_DONE, SRV_DA_POPUP_TYPE_DONE);
        }

#ifdef __DRM_SUPPORT__
        if(DRM_is_drm_file(0, (kal_wchar*)async_move_arg->dest_path))
        {
            DRM_register_file((kal_wchar*)async_move_arg->dest_path);
        }
#endif

        /* Assign the new path */
        job->op->assign_filepath(job, async_move_arg->dest_path);

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
        
        if (async_move_arg->can_reject &&
            error_code == FS_ABORTED_ERROR)
        {
            mmi_da_app_select_storage_async_acceptance(
                async_move_arg->select_storage_instance,
                SRV_DA_ACCEPTANCE_REJECT);
        }
        else
        {
            mmi_da_app_select_storage_async_acceptance(
                async_move_arg->select_storage_instance,
                SRV_DA_ACCEPTANCE_ACCEPT);
            mmi_da_set_active_select_storage_instance(NULL);
        }
    }

    srv_srv_da_adp_mem_free(async_move_arg->dest_path);
    srv_srv_da_adp_mem_free(async_move_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_async_move_cancel_callback
 * DESCRIPTION
 *  Cancel handler for the async move of a job.
 * PARAMETERS
 *  arg         [IN] (mmi_da_job_struct*)Job
 *  is_deleted  [IN] In deleting context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_async_move_cancel_callback(void *arg, MMI_BOOL is_deleted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_async_move_arg_struct *async_move_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_move_arg = (srv_da_job_async_move_arg_struct*)arg;

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

    srv_srv_da_adp_mem_free(async_move_arg->dest_path);
    srv_srv_da_adp_mem_free(async_move_arg);

    mmi_da_set_active_select_storage_instance(NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_move_select_storage_callback
 * DESCRIPTION
 *  Callback function for user decide the destination filepath.
 * PARAMETERS
 *  criteria        [IN] (mmi_da_job_struct*)Job
 *  filepath        [IN] The filepath user selected, NULL if not selected
 *  canback         [IN] Can reject the selection
 *  canpopup        [IN] Popup is allowed
 *  instance        [IN] Instance of select-storage
 * RETURNS
 *  Acceptance
 *****************************************************************************/
static srv_da_acceptance_enum mmi_da_job_move_select_storage_callback(
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
    
    if (filepath == NULL || !canback)
    {
        if (mmi_da_scr_select_storage_get_cause(instance) == SRV_DA_SCR_SELECT_STORAGE_CAUSE_ORIGINAL_FILE_LOST &&
            mmi_da_app_job_check_filestamp(job, NULL) == SRV_DA_FILESTAMP_CHECK_FAIL) /* Not exported for USB */
        {
            if (canpopup)
            {
                mmi_da_app_show_popup_ext(STR_ID_DA_ERROR_FILE_MISMATCH, SRV_DA_POPUP_TYPE_ERROR);
            }
            job->state = SRV_DA_JOB_STATE_ABORTED;
            srv_da_free_job_and_remove_screens(job);
        }
    
        mmi_da_set_active_select_storage_instance(NULL);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }

    src_filepath = job->op->get_filepath(job);

    if (mmi_wcscmp(src_filepath, filepath) == 0)
    {
        mmi_da_set_active_select_storage_instance(NULL);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }

    if (src_filepath[0] == filepath[0]) /* the same drive*/
    {
        FS_HANDLE fs_error;

        fs_error = srv_da_util_file_move(src_filepath, filepath, FS_MOVE_KILL);

        if (fs_error == FS_NO_ERROR)
        {
#ifdef __DRM_SUPPORT__
            if(DRM_is_drm_file(0, (kal_wchar*)filepath))
            {
                DRM_register_file((kal_wchar*)filepath);
            }
#endif

            /* Assign the new path */
            job->op->assign_filepath(job, filepath);
        
            mmi_da_app_show_popup_ext(STR_GLOBAL_DONE, SRV_DA_POPUP_TYPE_DONE);
            
            /* return MMI_DA_ACCEPTANCE_ACCEPT; */
        }
        else
        {
            mmi_da_app_show_popup_ext(srv_fmgr_fs_error_get_string(fs_error), SRV_DA_POPUP_TYPE_ERROR);

            mmi_da_set_active_select_storage_instance(NULL);
            return SRV_DA_ACCEPTANCE_ACCEPT;
        }
    }
    else
    {
        async_move_arg = (srv_da_job_async_move_arg_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_job_async_move_arg_struct));
        async_move_arg->job = job;
        async_move_arg->dest_path = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(filepath) + 1) * sizeof(U16));
        mmi_wcscpy(async_move_arg->dest_path, filepath);
        async_move_arg->select_storage_instance = instance;
        async_move_arg->can_reject = canback;

        mmi_da_app_async_move(
            SCR_ID_DA_DOWNLOAD_MOVING,
            SRV_DA_GLOBAL_MOVING,
            srv_da_job_get_title_icon(NULL),
            src_filepath,
            filepath,
            MMI_TRUE,
            async_move_arg,
            mmi_da_job_async_move_result_callback,
            mmi_da_job_async_move_cancel_callback);

        return SRV_DA_ACCEPTANCE_ASYNC;
    }
                
    mmi_da_set_active_select_storage_instance(NULL);
    return SRV_DA_ACCEPTANCE_ACCEPT;
}
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_move
 * DESCRIPTION
 *  Move the file of the job.
 * PARAMETERS
 *  job             [IN] job
 *  select_drive    [IN] To select another drive
 *  input_filename  [IN] To input another filename
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_move(
    srv_da_job_struct *job,
    MMI_BOOL select_drive,
    MMI_BOOL input_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_storage_parameter_struct *storage_para;
    const U16 *filepath;
    void *select_storage_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Should at lease one be MMI_TRUE */
    MMI_EXT_ASSERT(select_drive || input_filename, select_drive, input_filename, 0);
    
    storage_para = (mmi_da_scr_storage_parameter_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_storage_parameter_struct));

    memset(storage_para, 0, sizeof(srv_da_storage_parameter_struct));

    filepath = job->op->get_filepath(job);

    storage_para->storage = SRV_DA_STORAGE_USER_SELECT;
    storage_para->drv = (S32)filepath[0];

    srv_da_extract_filepath((U16*)filepath, storage_para->filename, storage_para->fileext);
    
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    srv_da_util_extract_folder(filepath, storage_para->folder);
    
    storage_para->filesize = srv_da_util_get_file_size((U16*)filepath);
    storage_para->original_filepath = filepath;
    storage_para->filecheck_func = srv_da_does_job_with_filepath_exist;
    storage_para->select_storage = (MMI_BOOL)select_drive;
    storage_para->select_filename = (MMI_BOOL)input_filename;
    storage_para->skip_exist_check = (MMI_BOOL)MMI_FALSE;

    select_storage_instance = mmi_da_app_scr_select_storage(
        mmi_da_job_move_select_storage_callback,
        storage_para,
        (U32)job,
        srv_da_job_get_title_icon(NULL));

    mmi_da_set_active_select_storage_instance(select_storage_instance);

    srv_srv_da_adp_mem_free(storage_para);
}

static void mmi_da_job_list_option_item_selected_hdlr(mmi_menu_id menuID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16                 error_id;
    srv_da_job_struct   *job;
    srv_da_job_filestamp_enum check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    job = srv_da_get_nth_job(mmi_da_get_job_highlight_index());
    MMI_ASSERT(job);

    switch (menuID)
    {
    case MENU_ID_DA_JOB_OPTION_USE_NOW:
    case MENU_ID_DA_JOB_OPTION_MOVE:
    case MENU_ID_DA_JOB_OPTION_RENAME:
#ifdef __MMI_DA_RESUME__
    case MENU_ID_DA_JOB_OPTION_RESUME:
#endif
        check_result = mmi_da_app_job_check_filestamp(job, &error_id);
        if(check_result != SRV_DA_FILESTAMP_CHECK_OK)
        {
            mmi_da_app_show_popup_ext(error_id, SRV_DA_POPUP_TYPE_ERROR);
            return;
        }
        break;
    case MENU_ID_DA_JOB_OPTION_CANCEL:
    
        #ifdef __USB_IN_NORMAL_MODE__
        {
            /* MAUI_01058311: If in USB mode, do not let user cancel. */
            const U16 *filepath;
            MMI_BOOL is_exported;
            
            filepath = job->op->get_filepath(job);

            is_exported = srv_usb_is_in_mass_storage_mode() && srv_usb_check_path_exported((WCHAR*)filepath);

            if (is_exported)
            {
                mmi_usb_app_unavailable_popup(0);
                return;
            }
        }
        #endif
        
        break;
        
    default:
        break;
    }

    switch (menuID)
    {
    case MENU_ID_DA_JOB_OPTION_VIEW_DETAIL:
        mmi_da_app_job_on_details_selected(job);
        break;
#ifndef __MMI_DA_CONF_PAGE_SLIM__
    case MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE:
#ifdef BROWSER_SUPPORT
        {
            const S8 *infoURL;

            MMI_ASSERT(job->op->get_infoURL != NULL);
            infoURL = job->op->get_infoURL(job);
            MMI_ASSERT(infoURL != NULL);

            if (wap_browser_is_open())
            {
                wap_start_browser(WAP_BROWSER_GOTO_URL_BACKGROUND, (const kal_uint8 *)infoURL);
            }
            else
            {
                wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8 *)infoURL);
            }

            /* Remove all download agent screens to go back to the browser.
               Notice that wap_start_browser() may popup a message. If it did,
               perhaps the URL is invalid, we do not remove any screen, */
            //DeleteScreenIfPresent(SCR_ID_DA_JOB_LIST); //TODO           
            mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_LIST);
        }
#endif
        break;
#endif
    case MENU_ID_DA_JOB_OPTION_USE_NOW:
        mmi_da_job_on_use_file_selected(job);
        break;

    case MENU_ID_DA_JOB_OPTION_MOVE:
    case MENU_ID_DA_JOB_OPTION_RENAME:
    
        MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);

        if (menuID == MENU_ID_DA_JOB_OPTION_MOVE)
        {
            if (srv_da_get_number_of_available_drives() > 1)
            {
                mmi_da_job_move(job, MMI_TRUE, MMI_FALSE);
            }
            else
            {
                mmi_da_app_show_popup_ext(STR_ID_DA_NO_OTHER_STORAGE, SRV_DA_POPUP_TYPE_ERROR);
            }
        }
        else
        {
            mmi_da_job_move(job, MMI_FALSE, MMI_TRUE);
        }
        
        break;

    case MENU_ID_DA_JOB_OPTION_REMOVE:
         mmi_da_job_on_remove_selected(job);
        break;

    case MENU_ID_DA_JOB_OPTION_REMOVE_ALL:
        /* MAUI_01078108: Don't go back to download list first and then go back to browser immediately */
        if (srv_da_remove_all_completed() > 0)
        {
            mmi_da_app_show_popup_ext(STR_GLOBAL_DONE, SRV_DA_POPUP_TYPE_DONE);
            
            if (srv_da_get_job_list_num() == 0)
            {
                //DeleteScreenIfPresent(SCR_ID_DA_JOB_LIST);              
                mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_LIST);
            }

            g_mmi_da_context.job_list_highlight_index = -1;

            srv_da_send_download_info_ind();
        }
        
        break;

    case MENU_ID_DA_JOB_OPTION_CANCEL:
        if (job->state != SRV_DA_JOB_STATE_DOWNLOADING &&
            job->state != SRV_DA_JOB_STATE_PROCESSING &&
            job->state != SRV_DA_JOB_STATE_PAUSED)
        {
            /* Do nothing */
            break;
        }
        else
        {
            mmi_da_job_on_cancel_selected(job);
        }
        
        break;

#ifdef __MMI_DA_RESUME__
    case MENU_ID_DA_JOB_OPTION_SUSPEND:
        mmi_da_job_on_suspend_selected(job);
        break;

    case MENU_ID_DA_JOB_OPTION_RESUME:
        mmi_da_job_on_resume_selected(job);
        break;
#endif

    case MENU_ID_DA_JOB_OPTION_PLAY: /* Available only during downloading */
        mmi_da_job_on_play_selected(job);        
        break;

    default:
        break;
    }
}

static mmi_ret mmi_da_scr_menu_proc_adp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_menu_struct *cntx;
    cui_menu_event_struct *menu_evt;
    mmi_da_scr_menu_evt_struct da_menu_evt;
    srv_da_job_struct *job;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_da_scr_menu_struct*)evt->user_data;
    job = cntx->user_data;
    if (cntx->valid_magic != MMI_DA_SCR_MENU_VALID_MAGIC)
    {
        /* Ignore */
        return MMI_RET_OK;
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
    #ifdef __MMI_DA_RESUME__
            mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_RESUME);
            mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_SUSPEND);
        #endif
            mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_PLAY);
            
            if (job->state == SRV_DA_JOB_STATE_COMPLETED)
            {
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_CANCEL);
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_CANCEL);
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE);
            }

            if (srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED) > 0)
            {
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE_ALL);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE_ALL);
            }
#ifndef __MMI_DA_CONF_PAGE_SLIM__
            if (job->op->get_infoURL != NULL
                && job->op->get_infoURL(job) != NULL)
            {
                
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE);
            }
#endif

            switch(job->state)
            {
            case SRV_DA_JOB_STATE_COMPLETED:
            {
                MMI_BOOL usb_mode;

                if (!job->setting_info.do_dispatch || job->type_handler->dispatch_hdlr== NULL)
                {
                    mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
                }
                else if (job->type_handler->dispatch_hdlr == srv_da_get_default_mime_type_handler()->dispatch_hdlr)
                {
                    if (srv_da_util_is_supported_by_fmgr(job->op->get_filepath(job)))
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
                    }
                    else
                    {
                        /* No option for the file */
                        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
                    }
                }
                else
                {
                    mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
                }

            #ifdef __USB_IN_NORMAL_MODE__
                usb_mode = srv_usb_is_in_mass_storage_mode();
            #else
                usb_mode = MMI_FALSE;
            #endif

                /* Do not show "Move" if there is only 1 drive or USB mode */
                if (srv_da_get_number_of_available_drives() <= 1 || usb_mode)
                {
                    mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
                }
                else
                {
                    mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
                }

                if (usb_mode)
                {
                    mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
                }
                else
                {
                    mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
                }
                
                break;
            } /* case MMI_DA_JOB_STATE_COMPLETED */

            case SRV_DA_JOB_STATE_DOWNLOADING:
        #ifdef __MMI_DA_RESUME__
                if(job->op->resume)
                {
                    mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_SUSPEND);
                }
        #endif
                if (job->setting_info.filepath_hdlr != NULL &&
                    job->setting_info.report_hdlr != NULL &&
                    !job->reporting &&
                    !srv_da_is_in_voice_call())
                {
                    mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_PLAY);
                }
                break;
                
            case SRV_DA_JOB_STATE_PROCESSING:
                break;

            case SRV_DA_JOB_STATE_PAUSED:
        #ifdef __MMI_DA_RESUME__
                if(job->op->resume)
                {
                    mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_RESUME);
                }
        #endif
                break;

            default:
                return;
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            menu_evt = (cui_menu_event_struct*)evt;

            MMI_FRM_INIT_EVENT(&da_menu_evt, 0);
            da_menu_evt.handle = cntx;
            da_menu_evt.selected_item = menu_evt->highlighted_menu_id;
            da_menu_evt.ori_evt_id = evt->evt_id;
            da_menu_evt.ori_evt = evt;
            MMI_FRM_SEND_EVENT(&da_menu_evt, cntx->client_proc, cntx->user_data);
            
            break;

        case EVT_ID_GROUP_DEINIT:
            cntx->valid_magic = 0;
            srv_srv_da_adp_mem_free(cntx);
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}

mmi_da_scr_menu_handle mmi_da_scr_menu_create_and_run(
    mmi_menu_id menu_id,
    mmi_da_scr_menu_proc client_proc,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_menu_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_da_scr_menu_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_menu_struct));
    cntx->valid_magic = MMI_DA_SCR_MENU_VALID_MAGIC;
    cntx->menu_id = menu_id;
    cntx->client_proc = client_proc;
    cntx->user_data = user_data;

    cntx->grp_id = mmi_frm_group_create_ex(
        MMI_DA_DOWNLOAD_LIST_GROUP,
        MMI_DA_DOWNLOAD_LIST_OPTIONS_CUI,
        mmi_da_scr_menu_proc_adp,
        cntx,
	MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //TODO confirm this g_mmi_da_context.da_app_scr_group_id = cntx->grp_id;

	cntx->cui_instance_id = cui_menu_create_and_run(
        cntx->grp_id,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        cntx->menu_id,
        MMI_TRUE,
        cntx);

    cui_menu_set_default_title_image_by_id(
        cntx->cui_instance_id,
        srv_da_util_get_icon_from_appid(APP_WAP));



    return (mmi_da_scr_menu_handle)cntx;
}

static mmi_ret mmi_da_job_list_option_proc(
    const mmi_da_scr_menu_evt_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (menu_evt->ori_evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            /* Put a dummy screen and remove Options */
            //EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
            mmi_frm_display_dummy_screen_ex(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_DUMMY);
            mmi_da_job_list_option_item_selected_hdlr(menu_evt->selected_item);

            if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DUMMY)
            {
                mmi_frm_scrn_close_active_id();
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_da_close_job_list_option();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

static void mmi_da_app_entry_job_list_option(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct   *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC(mmi_da_entry_job_list_option);


    job = srv_da_get_nth_job(mmi_da_get_job_highlight_index());
    if(!job)
    {
        mmi_da_close_job_list_option();
        return;
    }

#ifdef __MMI_DA_RESUME__
    mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_RESUME);
    mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_SUSPEND);
#endif
    mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_PLAY);
    
    if (job->state == SRV_DA_JOB_STATE_COMPLETED)
    {
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_CANCEL);
        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_CANCEL);
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE);
    }

    if(srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED) > 0)    
    {
        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE_ALL);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_REMOVE_ALL);
    }
#ifndef __MMI_DA_CONF_PAGE_SLIM__
    if (job->op->get_infoURL != NULL
        && job->op->get_infoURL(job) != NULL)
    {
        mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE);
    }
#endif

    switch(job->state)
    {
    case SRV_DA_JOB_STATE_COMPLETED:
    {
        MMI_BOOL usb_mode;

        if (!job->setting_info.do_dispatch || job->type_handler->dispatch_hdlr== NULL)
        {
            mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
        }
        else if (job->type_handler->dispatch_hdlr == srv_da_get_default_mime_type_handler()->dispatch_hdlr)
        {
            if (srv_da_util_is_supported_by_fmgr(job->op->get_filepath(job)))
            {
                mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
            }
            else
            {
                /* No option for the file */
                mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
            }
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_USE_NOW);
        }

    #ifdef __USB_IN_NORMAL_MODE__
        usb_mode = srv_usb_is_in_mass_storage_mode();
    #else
        usb_mode = MMI_FALSE;
    #endif

        /* Do not show "Move" if there is only 1 drive or USB mode */
        if (srv_da_get_number_of_available_drives() <= 1 || usb_mode)
        {
            mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_MOVE);
        }

        if (usb_mode)
        {
            mmi_frm_hide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_RENAME);
        }
        
        break;
    } /* case MMI_DA_JOB_STATE_COMPLETED */

    case SRV_DA_JOB_STATE_DOWNLOADING:
#ifdef __MMI_DA_RESUME__
        if(job->op->resume)
        {
            mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_SUSPEND);
        }
#endif
        if (job->setting_info.filepath_hdlr != NULL &&
            job->setting_info.report_hdlr != NULL &&
            !job->reporting &&
            !srv_da_is_in_voice_call())
        {
            mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_PLAY);
        }
        break;
        
    case SRV_DA_JOB_STATE_PROCESSING:
        break;

    case SRV_DA_JOB_STATE_PAUSED:
#ifdef __MMI_DA_RESUME__
        if(job->op->resume)
        {
            mmi_frm_unhide_menu_item(MENU_ID_DA_JOB_OPTION_RESUME);
        }
#endif
        break;

    default:
        return;
    }

    /* To protect job list option was not freed successfully */
    mmi_da_close_job_list_option();

    g_mmi_da_context.job_list_option = mmi_da_scr_menu_create_and_run(
        MENU_ID_DA_JOB_OPTION,
        mmi_da_job_list_option_proc,
        job);
}

static void mmi_da_entry_app_job_list_option(void)
{
}

void mmi_da_app_job_list_option_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct   *job;
	S32 job_list_highlight_index;
	job_list_highlight_index = mmi_da_get_job_highlight_index();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_get_nth_job(job_list_highlight_index);
    MMI_ASSERT(job);

    switch(mmi_da_app_job_check_filestamp(job, NULL))
    {
    case SRV_DA_FILESTAMP_CHECK_OK:
        mmi_da_app_entry_job_list_option();
        break;
        
    case SRV_DA_FILESTAMP_CHECK_FAIL_TEMP:
        mmi_da_app_entry_job_list_option();
        break;

    case SRV_DA_FILESTAMP_CHECK_FAIL:
        mmi_da_app_show_popup_ext(STR_ID_DA_ERROR_FILE_MISMATCH, SRV_DA_POPUP_TYPE_ERROR);
        srv_da_free_job_and_remove_screens(job);
        break;

    default:
        MMI_ASSERT(0);
        break;
    }
}


void mmi_da_app_job_display_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    S32 job_list_highlight_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	job_list_highlight_index = mmi_da_get_job_highlight_index();
    job = srv_da_get_nth_job(job_list_highlight_index);

    mmi_da_app_job_on_details_selected(job);
}

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
void mmi_da_app_job_list_highlight_hdlr(S32 hiliteidx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 job_list_highlight_index;
	S32 list_job_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	job_list_highlight_index = hiliteidx;
	list_job_num = srv_da_get_job_list_num();

    if (job_list_highlight_index < 0 ||
        job_list_highlight_index >= list_job_num)
    {
        job_list_highlight_index = 0;


    }
mmi_da_set_job_highlight_index(job_list_highlight_index);
#ifdef __MMI_FTE_SUPPORT__
    {
        srv_da_job_struct *job;
        
        job = srv_da_get_nth_job(job_list_highlight_index);
        mmi_da_job_set_toolbar(job);
#ifdef __MMI_ICON_BAR_SUPPORT__
        wgui_icon_bar_update();
#endif 
    }
#endif //__MMI_FTE_SUPPORT__
}
#endif //#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

void mmi_da_app_job_on_details_selected(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_da_job_check_file_before_operation(job) != SRV_DA_FILESTAMP_CHECK_OK)
    {
        return;
    }
	srv_da_set_curr_job(job);
    mmi_da_entry_job_detail();
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
    //mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_DETAIL);
}

void mmi_da_scr_menu_close(mmi_da_scr_menu_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_menu_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == MMI_DA_SCR_MENU_INVALID_HANDLE)
    {
        return;
    }
    
    cntx = (mmi_da_scr_menu_struct*)handle;

    MMI_EXT_ASSERT(cntx->valid_magic == MMI_DA_SCR_MENU_VALID_MAGIC,
        cntx->valid_magic, 0, 0);
    
    cui_menu_close(cntx->cui_instance_id);
}

void mmi_da_close_job_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if (g_mmi_da_context.job_list_option != MMI_DA_SCR_MENU_INVALID_HANDLE)
    {
        mmi_da_scr_menu_close(g_mmi_da_context.job_list_option);
        g_mmi_da_context.job_list_option = MMI_DA_SCR_MENU_INVALID_HANDLE;
    }
#endif
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
void mmi_da_app_job_list_tap_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        job = srv_da_get_nth_job(index);
        mmi_da_app_job_on_details_selected(job);
    }
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_da_close_job_list
 * DESCRIPTION
 *  Close job list screen which on the tpo.
 * PARAMETERS
 *  arg     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_close_job_list(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_LIST)
    {
        mmi_frm_scrn_close_active_id();
    }
}

#endif //__MMI_DOWNLOAD_AGENT_MULTI_DL__
void mmi_da_entry_job_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(!mmi_frm_group_is_present(MMI_DA_DOWNLOAD_LIST_GROUP))
    {
        mmi_frm_group_create_ex(MMI_DA_BRW_ENTRY_SCREEN_GROUP, 
                               MMI_DA_CONFIRM_SCREEN_GROUP,
                               mmi_da_app_choice_scr_group_proc,
                               (void*)NULL,
                               MMI_FRM_NODE_SMART_CLOSE_FLAG);        
        mmi_da_app_show_job_detail();
    }
    else
    {      
        mmi_da_app_show_job_detail();
    }
}

void mmi_da_app_check_and_trigger_popup_on_screen_entry(srv_da_job_struct *job, U16 drawing_screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL popup_triggered;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	popup_triggered = srv_da_get_popup_triggere();
    if(!mmi_is_redrawing_bk_screens())
    {
        if (!popup_triggered)
        {
            if(job->state == SRV_DA_JOB_STATE_FAILED ||
                (job->state == SRV_DA_JOB_STATE_COMPLETED && !job->notified_complete) ||
                job->pending_popup.type != SRV_DA_POPUP_TYPE_NONE)
            {
                ClearInputEventHandler(MMI_DEVICE_ALL);
                
                //srv_da_util_trigger_proc_ext(mmi_da_job_do_popup, job, drawing_screen_id);  //to do 
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_delete_progressing
 * DESCRIPTION
 *  Delete callback function for progressing screen.
 * PARAMETERS
 *  unused  [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_da_app_scr_delete_progressing(void *unused)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_progressing_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_da_scr_progressing_top_cntx;

    MMI_ASSERT(cntx != NULL);

    if (!cntx->cancel_rsk && cntx->cancel_callback == NULL)
    {
        return (U8)MMI_TRUE; /* Can not be deleted */
    }
    else if (cntx->cancel_callback != NULL)
    {
        cntx->cancel_callback(cntx->arg, MMI_TRUE);
    }

    //ClearDelScrnIDCallbackHandler(cntx->screen_id, mmi_da_app_scr_delete_progressing);
    mmi_da_update_need_to_delete_progressing(MMI_FALSE);
    g_mmi_da_scr_progressing_top_cntx = cntx->next;
    
    srv_srv_da_adp_mem_free(cntx);

    return (U8)MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_progressing_cancel
 * DESCRIPTION
 *  RSK "Cancel" handler for progrssing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_progressing_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_progressing_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_da_scr_progressing_top_cntx != NULL);
    
    cntx = g_mmi_da_scr_progressing_top_cntx;
    
    MMI_ASSERT(cntx->cancel_rsk != 0);

    g_mmi_da_scr_progressing_top_cntx = cntx->next;

    if (cntx->timer_id != 0)
    {
        srv_da_timer_triggered_proc_cancel(cntx->timer_id);
        cntx->timer_id = 0;
    }

    //ClearDelScrnIDCallbackHandler(cntx->screen_id, mmi_da_app_scr_delete_progressing);
    mmi_da_update_need_to_delete_progressing(MMI_FALSE);

    if (cntx->cancel_callback != NULL)
    {
        cntx->cancel_callback(cntx->arg, MMI_FALSE);
    }

    mmi_da_app_scr_remove_screen(cntx->screen_id);

    srv_srv_da_adp_mem_free(cntx);
}




/*****************************************************************************
* FUNCTION
*   srv_da_util_format_time
* DESCRIPTION
*   format output string buffer according to input time
* PARAMETERS
*   buffer  [OUT]   the formated time message,
*   total_secs [IN]    time                
* RETURNS
*   void
*****************************************************************************/
void mmi_da_app_util_format_time(U16 *buffer, U32 total_secs)
{
    U32 mins, secs;

    if(!buffer)
        return;

    buffer[0] = 0;
    
    if(total_secs == 0xFFFFFFFF)
        return;

    if(total_secs == 0)
    {
        kal_wsprintf(buffer, "< 1 %w", GetString(STR_ID_DA_PROMPT_SEC));
        return;
    }
    
    mins = total_secs / 60;
    secs = total_secs % 60;

    if(mins > 99)
    {
        kal_wsprintf(buffer, "> 99 %w 59 %w", GetString(STR_ID_DA_PROMPT_MINS), GetString(STR_ID_DA_PROMPT_SECS));
        secs = 0;
    }
    else if(mins > 1)
        kal_wsprintf(buffer, "%d %w ", mins, GetString(STR_ID_DA_PROMPT_MINS));
	else if (mins != 0)
        kal_wsprintf(buffer, "%d %w ", mins, GetString(STR_ID_DA_PROMPT_MIN));

    if(mins == 0 || secs != 0)
	{
		if (secs>1)
			kal_wsprintf(buffer + mmi_ucs2strlen((S8*)buffer), "%d %w", secs, GetString(STR_ID_DA_PROMPT_SECS));
		else
        kal_wsprintf(buffer + mmi_ucs2strlen((S8*)buffer), "%d %w", secs, GetString(STR_ID_DA_PROMPT_SEC));
}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_get_title_icon
 * DESCRIPTION
 *  Get the title icon of a download.
 * PARAMETERS
 *  job     [IN] Download job. If NULL, returns a general icon.
 * RETURNS
 *  Icon ID.
 *****************************************************************************/
U16 mmi_da_job_get_title_icon(const srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetRootTitleIcon(SERVICES_WAP_MENU_ID);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_is_allowed_to_be_dispatched
 * DESCRIPTION
 *  Is it allowed to dispatch the job on current extrisic condition?
 *  It checks dispatch handler, USB, call.. etc, but does NOT check active
 *  screen.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  MMI_TRUE if allowed
 *****************************************************************************/
static MMI_BOOL mmi_da_job_is_allowed_to_be_dispatched(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 *filepath;
    MMI_BOOL is_oma_dd_file;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->setting_info.do_dispatch)
    {
        return MMI_FALSE;
    }

    filepath = job->op->get_filepath(job);

    if (job->type_handler->dispatch_hdlr == NULL)
    {
        return MMI_FALSE;
    }

    /* Check whether dispatching is available */
    if (job->type_handler->dispatch_hdlr == srv_da_get_default_mime_type_handler()->dispatch_hdlr)
    {
        if (!srv_da_util_is_supported_by_fmgr(filepath)) /* No valid operation for the file */
        {
            return MMI_FALSE;
        }
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && srv_usb_check_path_exported((WCHAR*)filepath))
    {
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    is_oma_dd_file = MMI_FALSE;

#ifdef __MMI_OMA_DD_DOWNLOAD__
    if (job->mime_type != NULL && job->mime_type->mime_subtype == MIME_SUBTYPE_OMA_DD)
    {
        is_oma_dd_file = MMI_TRUE;
    }
#endif /* __MMI_OMA_DD_DOWNLOAD__ */

    /*
     * [MAUI_01756551]
     * We should forbid to launch application during call. Otherwise it will cause:
     * a) Launch application in normal call, which is not expected
     * b) Potential re-entrant of other applications
     */
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_da_is_in_voice_call() && !srv_ucm_is_background_call())
#else
    if (srv_da_is_in_voice_call() && !is_oma_dd_file)
#endif
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}
extern void mmi_da_job_cancel_dispatch(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_dispatch_to_app
 * DESCRIPTION
 *  Dispatch g_mmi_da_context.curr_job to appropriate application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_dispatch_to_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct   *job;
    U16                 err_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_get_curr_job();

    if (job == NULL)
    {
        mmi_da_scr_remove_screen(SCR_ID_DA_JOB_CALLBACK_CONFIRM);
        return;
    }
    
    if(SRV_DA_FILESTAMP_CHECK_OK != mmi_da_app_job_check_filestamp(job, &err_id))
    {
        mmi_da_app_show_popup_ext(err_id, SRV_DA_POPUP_TYPE_ERROR);
        mmi_da_job_cancel_dispatch();
        return;
    }
    
    job->op->dispatch(job);

    if (srv_da_is_job_valid(job))
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        if(!job->setting_info.can_minimize)
#endif
        {
            srv_da_free_job_and_remove_screens(job);
        }
    }

    mmi_da_scr_remove_screen(SCR_ID_DA_JOB_CALLBACK_CONFIRM);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_dispatch_confirm_remove_screen
 * DESCRIPTION
 *  Dispatch g_mmi_da_context.curr_job to appropriate application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_dispatch_confirm_remove_screen(void *unused)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_CALLBACK_CONFIRM)
    {
        mmi_frm_scrn_close_active_id();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_dispatch_confirm_delete_callback
 * DESCRIPTION
 *  Delete handler for dispatch confirm.
 * PARAMETERS
 *  in_param    [IN] Unused
 * RETURNS
 *  MMI_FALSE (can be deleted)
 *****************************************************************************/
U8 mmi_da_dispatch_confirm_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearDelScrnIDCallbackHandler(SCR_ID_DA_JOB_CALLBACK_CONFIRM, NULL);
    mmi_da_update_dispatch_confirm_del(MMI_FALSE);

    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_cancel_dispatch
 * DESCRIPTION
 *  Handler to cancel dispatching g_mmi_da_context.curr_job.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_cancel_dispatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_get_curr_job();
    
    if (job == NULL)
    {
        mmi_da_scr_remove_screen(SCR_ID_DA_JOB_CALLBACK_CONFIRM);
        return;
    }
    
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);

    //ClearDelScrnIDCallbackHandler(SCR_ID_DA_JOB_CALLBACK_CONFIRM, NULL);
    mmi_da_update_dispatch_confirm_del(MMI_FALSE);
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(!job->setting_info.can_minimize)
    {
        srv_da_free_job_and_remove_screens(job);
    }
#else
    srv_da_free_job_and_remove_screens(job);
#endif

    mmi_da_scr_remove_screen(SCR_ID_DA_JOB_CALLBACK_CONFIRM);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_notify_completed
 * DESCRIPTION
 *  Notify user the completion of the job.
 *  After notified, job->notified_complete will be set to MMI_TRUE.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_notify_completed(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

    srv_da_discard_pending_popup(job);

    /* Remove full screen popup or abort confirm screen of the job */
    if (srv_da_get_curr_job() == job)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_ABORT_CONFIRM)
        {
            //EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
            mmi_frm_display_dummy_screen_ex(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_DUMMY);
            mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_ABORT_CONFIRM);
        }
    }

    if (mmi_da_is_job_list_option_on_top())
    {
        if (srv_da_get_job_index(job) == g_mmi_da_context.job_list_highlight_index)
        {
            EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
            mmi_da_close_job_list_option();
        }
    }

    if (job->notified_complete || job->reporting)
    {
        /* If notified or reporting, we don't need to dispatch the file. */
        job->notified_complete = MMI_TRUE;
        job->reporting = MMI_FALSE;

        if (!job->setting_info.can_minimize)
        {
            srv_da_free_job_and_remove_screens(job);
        }
        
        return;
    }

    if (srv_da_get_curr_job() == job)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_FULL_SCREEN_POPUP)
        {
            //EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
            mmi_frm_display_dummy_screen_ex(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_DUMMY);
        }
        //DeleteScreenIfPresent(SCR_ID_DA_FULL_SCREEN_POPUP);       
        mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_FULL_SCREEN_POPUP);
    }

  //  if (!mmi_da_app_is_in_foreground_state())
   // {
   //     return;
   // }

    /* Download agent is on top, we are allowed to show download agent's screen */
    
    if (!mmi_da_job_is_allowed_to_be_dispatched(job))
    {
        //TODO 
UI_string_ID_type str_id;
    
#ifdef SLIM_WAP_MMS
	str_id = mmi_da_app_map_string(SRV_DA_GLOBAL_DONE, 0, SRV_DA_POPUP_TYPE_DONE);
		mmi_da_app_popup_for_job(job,
            SRV_DA_POPUP_TYPE_DONE,
			(U16*)get_string(str_id),
            MMI_FALSE, NULL);
#else
	str_id = mmi_da_app_map_string(SRV_DA_PROMPT_DL_COMPLETE, 0, SRV_DA_POPUP_TYPE_DONE);
		mmi_da_app_popup_for_job(job,
            SRV_DA_POPUP_TYPE_DONE,
            (U16*)get_string(str_id),
            MMI_FALSE, NULL);
#endif
            
        job->notified_complete = MMI_TRUE;
        
        if (!job->setting_info.can_minimize)
        {
            srv_da_free_job_and_remove_screens(job);
        }
        
        return;
    }

    if (job->setting_info.confirm_dispatch)
    {
        //if (mmi_da_is_suitable_to_popup_for_job(job))
        {
            srv_da_set_curr_job(job);
            mmi_da_curr_job_entry_dispatch_confirm();
            job->notified_complete = MMI_TRUE;
            //DeleteScreenIfPresent(SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
            //DeleteScreenIfPresent(SCR_ID_DA_JOB_DETAIL);            
            mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_OBJECT_DESCRIPTION);            
            mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_DETAIL);
            mmi_da_close_job_list_option();
        }

        /* Will be triggered when screen goes back */
        return;
    }
    else if (!job->setting_info.can_minimize)
    {
        //if (mmi_da_is_suitable_to_popup_for_job(job))
        {
            job->op->dispatch(job);
            srv_da_free_job_and_remove_screens(job);
        }
    }
    else
    {
        /* no confirm, directly dispatch */
        job->op->dispatch(job);
        srv_da_free_job_and_remove_screens(job);
    }

#else

    if(job->notified_complete || job->reporting)
    {
        srv_da_free_job_and_remove_screens(job);
        return;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
        mmi_da_job_entry_complete(job);
        mmi_da_scr_remove_screen(SCR_ID_DA_FULL_SCREEN_POPUP);
   // }

#endif
}

void mmi_da_job_complete(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_da_job_notify_completed(job);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_DUMMY)
    {
        mmi_frm_scrn_close_active_id();
    }
}
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_ICON_BAR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_da_toolbar_get_items
 * DESCRIPTION
 *  Fill the enabled_icons[], disable_icons[], prompt_strs[] for the job.
 * PARAMETERS
 *  job             [IN]  Job
 *  enabled_icons   [OUT] Array of enabled icons of toolbar items
 *  disabled_icons  [OUT] Array of disabled icons of toolbar items
 *  prompt_strs     [OUT] Array of prompt strings of toolbar items
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_toolbar_get_items(
    const srv_da_job_struct *job,
    U8 *enabled_icons[],
    U8 *disabled_icons[],
    U8 *prompt_strs[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_toolbar_config_struct config;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_DA_TOOLBAR_MAX_ITEM_NUM; i++)
    {
        mmi_da_toolbar_config[i](job, &config);
        
        if (config.enabled_img_id != 0)
        {
            enabled_icons[i] = (U8*)get_image(config.enabled_img_id);
        }
        else
        {
            enabled_icons[i] = NULL;
        }
        
        if (config.disabled_img_id != 0)
        {
            disabled_icons[i] = (U8*)get_image(config.disabled_img_id);
        }
        else
        {
            disabled_icons[i] = NULL;
        }

        if (config.prompt_str_id != 0)
        {
            prompt_strs[i] = (U8*)get_string(config.prompt_str_id);
        }
        else
        {
            prompt_strs[i] = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_on_toolbar_item_selected
 * DESCRIPTION
 *  Callback of toolbar item selected. Do corresponding action of the item.
 * PARAMETERS
 *  index       [IN] The index of the item selected
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_job_on_toolbar_item_selected(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    mmi_da_toolbar_config_struct config;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(index >= 0 && index < MMI_DA_TOOLBAR_MAX_ITEM_NUM,
        index, MMI_DA_TOOLBAR_MAX_ITEM_NUM, 0);

    job = srv_da_get_nth_job(g_mmi_da_context.job_list_highlight_index);

    if (job == NULL)
    {
        return;
    }
    
    mmi_da_toolbar_config[index](job, &config);
    
    if (config.handler != NULL)
    {
        config.handler(job);
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

MMI_BOOL mmi_da_scr_menu_is_on_top(mmi_da_scr_menu_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_menu_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_da_scr_menu_struct*)handle;

    return mmi_frm_group_is_in_top_scope(cntx->grp_id);
}

MMI_BOOL mmi_da_is_job_list_option_on_top(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if (g_mmi_da_context.job_list_option != MMI_DA_SCR_MENU_INVALID_HANDLE)
    {
        return mmi_da_scr_menu_is_on_top(g_mmi_da_context.job_list_option);
    }
#endif

    return MMI_FALSE;
}
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_set_toolbar
 * DESCRIPTION
 *  Set toolbar parameters before show or update category.
 * PARAMETERS
 *  job     [IN] The job selected currently
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_set_toolbar(const srv_da_job_struct *job)
{
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_ICON_BAR_SUPPORT__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 *enabled_icons[MMI_DA_TOOLBAR_MAX_ITEM_NUM];
    U8 *enabled_icons[4];
    U8 *disabled_icons[MMI_DA_TOOLBAR_MAX_ITEM_NUM];
    U8 *prompt_strs[MMI_DA_TOOLBAR_MAX_ITEM_NUM];
    mmi_da_toolbar_config_struct config;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job == NULL)
    {
        return;
    }
    
    mmi_da_toolbar_get_items(job, enabled_icons, disabled_icons, prompt_strs);
#ifdef __MMI_ICON_BAR_SUPPORT__    
    wgui_icon_bar_setup(
        MMI_DA_TOOLBAR_MAX_ITEM_NUM,
        enabled_icons,
        disabled_icons,
        prompt_strs,
        mmi_da_job_on_toolbar_item_selected);
#endif

    /*
     * wgui_icon_bar_set_item_enable_state() should be called after
     * wgui_icon_bar_setup. Otherwise it will not be applied.
     */
    for (i = 0; i < MMI_DA_TOOLBAR_MAX_ITEM_NUM; i++)
    {
        mmi_da_toolbar_config[i](job, &config);
#ifdef __MMI_ICON_BAR_SUPPORT__
        wgui_icon_bar_set_item_enable_state(i, config.is_enabled);
#endif 
    }
#endif /* __MMI_FTE_SUPPORT__ */
}

S32 mmi_da_job_get_display_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_item_progress_struct info;
    U32                         percentage;
    S8                          *dl_str;
    S32                         i;
    U16                         icon_id;
    U16                         *ui_item_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(i=0; i<data_size; i++)
    {
        job = srv_da_get_nth_job(i + start_index);
        MMI_ASSERT(job);

        ui_item_buffer = (U16*)srv_da_adp_mem_allocate((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        
        job->op->get_name(job, ui_item_buffer, SRV_FMGR_PATH_MAX_LEN + 1);

        /* MAUI_01038572 */
        /* Truncate too long tail to suit the MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE/ENCODING_LENGTH */ 
        if (mmi_wcslen(ui_item_buffer) > (MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE/ENCODING_LENGTH - 1))
        {
            mmi_wcscpy(
                (ui_item_buffer + MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE/ENCODING_LENGTH - 1 - 3),
                L"...");
        }

        mmi_wcscpy(menu_data[i].item_list[0], ui_item_buffer);

        srv_srv_da_adp_mem_free(ui_item_buffer);
#if defined (__MMI_OMA_DD_DOWNLOAD__)
         if (job->type == SRV_DA_JOB_TYPE_OMADL)
		mmi_da_oma_get_item_progress(job, &info);
		else
#endif
		{
			info.processing_string_id = 0;
        
		}
        percentage = DA_JOB_GET_PROGRESS(job, info);
        dl_str = srv_da_util_format_size_total(info.currSize, info.fileSize);

        mmi_asc_to_ucs2((S8*)menu_data[i].item_list[2], (S8*)dl_str);

        if(percentage != MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
        {
            /* kal_wsprintf() does not support "%%" */
            kal_wsprintf(menu_data[i].item_list[1], "%d%c", percentage, '%');
        }
        else
        {
            menu_data[i].item_list[1][0] = L'\0';
        }

        switch(job->state)
        {
            case SRV_DA_JOB_STATE_DOWNLOADING:
            case SRV_DA_JOB_STATE_ABORTING:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_LOADING;
                break;

            case SRV_DA_JOB_STATE_PROCESSING:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_PROCESSING;
                break;

            case SRV_DA_JOB_STATE_COMPLETED:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_COMPLETE;
                break;

#ifdef __MMI_DA_RESUME__
            case SRV_DA_JOB_STATE_PAUSED:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_PAUSE;
                break;
#endif

            case SRV_DA_JOB_STATE_ABORTED:
            case SRV_DA_JOB_STATE_FAILED:
            default:
                icon_id = IMG_ID_DA_DOWNLOAD_STATE_PROCESSING;
                break;
        }

        menu_data[i].image_list[0] = (PU8)GetImage((U16)icon_id);
    }
    return i;
}
#endif // #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_update_timer_handler
 * DESCRIPTION
 *  Refresh the screens for job(s).
 * PARAMETERS
 *  param       [IN] mmi_da_job_struct*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_update_timer_handler(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct   *job;
    srv_da_job_struct   *highlighted_job;
    U32                 percentage;
    UI_string_type      display[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!g_mmi_da_context.job_list_dirty_flag)
        return;
    
    g_mmi_da_context.job_list_dirty_flag = MMI_FALSE;
    job = (srv_da_job_struct*)param;
   
    if( mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_LIST )
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        /* update screen */
        if(g_mmi_da_context.job_list_highlight_index < 0 || g_mmi_da_context.job_list_highlight_index >= (S32)srv_da_get_curr_job_count())
            g_mmi_da_context.job_list_highlight_index = 0;

        highlighted_job = srv_da_get_nth_job(g_mmi_da_context.job_list_highlight_index);
        mmi_da_job_set_toolbar(highlighted_job);
        
        mmi_cat_refresh_asyncdynamic_list(srv_da_get_curr_job_count(), 
            g_mmi_da_context.job_list_highlight_index, 
            mmi_da_job_get_display_item, NULL);
#endif
    }
    else if(mmi_frm_scrn_get_active_id() == SCR_ID_DA_JOB_DETAIL && srv_da_get_curr_job() == job)
    {
        percentage = mmi_da_format_job_detail(job, (U16*)subMenuData, MAX_SUB_MENU_SIZE, MAX_SUB_MENUS/2);
//        display[] = (UI_string_type)(subMenuData);
        display[0] = (UI_string_type)(subMenuData)+MAX_SUB_MENU_SIZE;
        display[1] = (UI_string_type)(subMenuData)+MAX_SUB_MENU_SIZE*2;
        display[2] = (UI_string_type)(subMenuData)+MAX_SUB_MENU_SIZE*3;
#if defined(__MMI_MAINLCD_128X128__)
        if(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
            UpdateCategory402Value((U16)0, (U8*)display[0]);
        else
            UpdateCategory402Value((U16)percentage, NULL);
#else
        if(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
            Cat412UpdateList((UI_string_type)srv_da_util_get_filename((U16*)subMenuData), (U8)255, 1, display);
        else
            Cat412UpdateList((UI_string_type)srv_da_util_get_filename((U16*)subMenuData), (U8)percentage, 3, display);
#endif
    }

}
#ifndef MMI_DA_PLUTO_SLIM
void mmi_da_app_display_job_list(void)
{
#if defined(BROWSER_SUPPORT)
	mmi_da_app_close_all_screens();
#endif
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(!mmi_da_is_app_launched())
    {
        mmi_da_launch_app(MMI_DA_LAUNCH_FROM_BROWSER);
    }
    if(!mmi_frm_group_is_present(MMI_DA_DOWNLOAD_LIST_GROUP))
    {
        mmi_frm_group_create_ex(MMI_DA_BRW_ENTRY_SCREEN_GROUP, 
                               MMI_DA_DOWNLOAD_LIST_GROUP,
                               mmi_da_download_list_group_proc,
                               (void*)NULL,
                               MMI_FRM_NODE_SMART_CLOSE_FLAG);
        //g_mmi_da_context.da_app_scr_group_id = MMI_DA_DOWNLOAD_LIST_GROUP;
    }
    mmi_da_app_entry_job_list();

    mmi_da_check_presence_and_close_screen(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
    mmi_da_check_presence_and_close_screen(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_DETAIL);
    mmi_da_close_job_list_option();
#endif // #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

}
#endif
/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16  mmi_da_app_get_wap_error_string_id(S32 dls_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (dls_error < 0)
    {
        return (U16)srv_fmgr_fs_error_get_string(dls_error);
    }
        
    switch (dls_error)
    {
        case WAP_DL_ERROR_CONNECTION_CLOSED:
            string_id = STR_ID_DA_ERROR_CONNECT_CLOSED;
            break;
            
        case WAP_DL_ERROR_INVALID_FILE:
            string_id = STR_GLOBAL_INVALID_FILENAME;
            break;
            
        case WAP_DL_ERROR_DISK_FULL:
            string_id = (U16)srv_fmgr_fs_error_get_string(FS_DISK_FULL);
            break;
            
        case WAP_DL_ERROR_FILE_ACCESS:
            string_id = (U16)srv_fmgr_fs_error_get_string(FS_ACCESS_DENIED);
            break;
            
        case WAP_DL_ERROR_FILE_READ_ONLY:
            string_id = (U16)srv_fmgr_fs_error_get_string(FS_READ_ONLY_ERROR);
            break;

        case WAP_DL_ERROR_CANCELLED:
        case WAP_DL_ERROR_INVALID_SESSION_ID:
        case WAP_DL_ERROR_OK:
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }

    return string_id;
}

UI_string_ID_type mmi_da_app_map_string(U32 string_id, S32 cause, srv_da_popup_type_enum type)
{
	UI_string_ID_type str_id = 0;
	if (type == SRV_DA_POPUP_TYPE_FS_ERROR)
	{
		str_id = srv_fmgr_fs_error_get_string(cause);
		return str_id;
	}
	else if (type == SRV_DA_POPUP_TYPE_WAP_ERROR)
	{
		str_id = mmi_da_app_get_wap_error_string_id(cause);
		return str_id;
	}
	else
	{
		switch (string_id)
		{
			case SRV_DA_GLOBAL_NOT_SUPPORTED:
				str_id = STR_GLOBAL_NOT_SUPPORTED;
				break;
			case SRV_DA_GLOBAL_UNSUPPORTED_FORMAT:
				str_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
				break;
#ifdef __DRM_SUPPORT__
			case SRV_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME:
				str_id = STR_ID_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME;
				break;
#endif 
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
			case SRV_DA_JAVA_JOB_EXIST:
				str_id = STR_ID_DA_JAVA_JOB_EXIST;
				break;
			case SRV_DA_PROMPT_EXCEED_MAX_DL:
				str_id = STR_ID_DA_PROMPT_EXCEED_MAX_DL;
				break;
			case SRV_DA_JOB_EXIST:
				str_id = STR_ID_DA_JOB_EXIST;
				break;
#endif
			case SRV_DA_GLOBAL_NOT_ENOUGH_MEMORY:
				str_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
				break;
			case SRV_DA_GLOBAL_INSERT_MEMORY_CARD:
				str_id = STR_GLOBAL_INSERT_MEMORY_CARD;
				break;
			case SRV_DA_INSERT_MEMORY_CARD:
				str_id = STR_DA_INSERT_MEMORY_CARD;
				break;
			case SRV_DA_INSERT_MEM_CARD:
				str_id = STR_DA_INSERT_MEM_CARD;
				break; 
			case SRV_DA_GLOBAL_DRM_INVALID_FORMAT:
				str_id = STR_GLOBAL_DRM_INVALID_FORMAT;
				break;
			case SRV_DA_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL:
				str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
				break;
			case SRV_DLA_FAILED_TO_DOWNLOAD:
				str_id = STR_DLA_FAILED_TO_DOWNLOAD;
				break;
#if defined (__MMI_OMA_DD_DOWNLOAD__)
			case SRV_DA_AHTUENTICATION_FAILED:
				str_id = STR_ID_DA_AHTUENTICATION_FAILED;
				break;
			case SRV_DA_OMA_ERROR_SEND_REPORT_FAIL:
				str_id = STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL;
				break;
#endif
			case SRV_DA_GLOBAL_SAVED:
				str_id = STR_GLOBAL_SAVED;
				break;
#ifndef __MMI_DA_CONF_PAGE_SLIM__
			case SRV_DA_SAVED_TO_CARD:
				str_id = STR_ID_DA_SAVED_TO_CARD;
				break;
			case SRV_DA_GLOBAL_SAVED_TO_PHONE:
				str_id = STR_ID_DA_SAVED_TO_PHONE;
				break;
			case SRV_DA_UNABLE_TO_SAVE_FILE:
				str_id = STR_ID_DA_UNABLE_TO_SAVE_FILE;
				break;
#endif
			case SRV_DA_GLOBAL_INSUFFICIENT_MEMORY:
				str_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
				break;
#ifdef __MMI_DA_RESUME__
			case SRV_DA_ERROR_RESUME_FAIL:
				str_id = STR_ID_DA_ERROR_RESUME_FAIL;
				break;
#endif
			case SRV_DA_ERROR_CONNECT_CLOSED:
				str_id = STR_ID_DA_ERROR_CONNECT_CLOSED;
				break;
#if defined (__MMI_OMA_DD_DOWNLOAD__)
			case SRV_DA_OMA_ERROR_SEND_REPORT_CANCEL:
				str_id = STR_ID_DA_OMA_ERROR_SEND_REPORT_CANCEL;
				break;
#endif 
			case SRV_DA_PROMPT_DL_COMPLETE:
				str_id = STR_ID_DA_PROMPT_DL_COMPLETE;
				break;
			case SRV_DA_GLOBAL_CANCELLING:
				str_id = STR_GLOBAL_CANCELLING;
				break;
			case SRV_DA_PLEASE_WAIT:
				str_id = STR_GLOBAL_PLEASE_WAIT;
				break;
			case SRV_DA_PROCESSING:
				str_id = STR_ID_DA_PROCESSING;
				break;
			case SRV_DA_DRM_PROCESSING:
				str_id = STR_GLOBAL_DRM_PROCESSING;
				break;
			case SRV_DA_GLOBAL_SAVING:
				str_id = STR_GLOBAL_SAVING;
				break;
			case SRV_DA_GLOBAL_DONE:
				str_id = STR_GLOBAL_DONE;
				break;
			case SRV_DA_GLOBAL_MOVING:
				str_id= STR_GLOBAL_MOVING;
				break;
			case SRV_DA_NEW_PUSH:
				str_id = STR_ID_DA_NEW_PUSH;
				break;
            default:
                str_id = string_id;
                break;
		}
	}
	
	return str_id;
}
mmi_event_notify_enum mmi_da_app_map_popup_event(srv_da_popup_type_enum popup_event)
{
    mmi_event_notify_enum popup_type;
    switch (popup_event)
    {        
        case SRV_DA_POPUP_TYPE_ERROR:
            popup_type = MMI_EVENT_FAILURE;
            break;

        case SRV_DA_POPUP_TYPE_DONE:
        case SRV_DA_POPUP_TYPE_SAVED:
            popup_type = MMI_EVENT_SUCCESS;
            break;
        case SRV_DA_POPUP_TYPE_MESSAGE:    
        case SRV_DA_POPUP_TYPE_INFO:
        default:
            popup_type = MMI_EVENT_INFO;
            break;
    }
    return popup_type;
}


void mmi_da_app_show_user_defined_popup(srv_da_popup_message_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_da_is_popup_allowed())
    {
        switch (message->type)
        {
            case SRV_DA_POPUP_TYPE_NONE:
                return;

            case SRV_DA_POPUP_TYPE_MESSAGE:
            case SRV_DA_POPUP_TYPE_ERROR:
            case SRV_DA_POPUP_TYPE_DONE:
            case SRV_DA_POPUP_TYPE_INFO:
            case SRV_DA_POPUP_TYPE_SAVED:
                mmi_da_app_show_popup_error_ext(message->string, message->type);
                break;

            case SRV_DA_POPUP_TYPE_LONG_MESSAGE:
                mmi_da_app_show_full_screen_popup(
                    message->title_string_id,
                    message->title_icon_id,
                    message->string,
                    message->free_string_after_popup,
                    0);
                /* mmi_da_show_full_screen_popup() will free the string */
                message->free_string_after_popup = MMI_FALSE;
                break;
#ifdef __DRM_SUPPORT__
            case SRV_DA_POPUP_TYPE_DRM_PROCESSING_INFO:
                {
                    srv_da_drm_popup_info *drm_popup_info;

                    drm_popup_info = (srv_da_drm_popup_info*)message->info;

                    if (drm_popup_info != NULL)
                    {
                        mmi_da_drm_show_process_info(
                            drm_popup_info->result,
                            drm_popup_info->mime_type,
                            &(drm_popup_info->result_info),
                            drm_popup_info->action);

                        srv_srv_da_adp_mem_free(drm_popup_info); /* message->info will be cleaned afterward */
                    }
                }
                break;
#endif

            default:
                break;
        }
    }
    if (message->free_string_after_popup)
    {
        srv_srv_da_adp_mem_free(message->string);
    }
    message->type = SRV_DA_POPUP_TYPE_NONE;
    message->title_string_id = 0;
    message->title_icon_id = 0;
    message->string = NULL;
    message->free_string_after_popup = MMI_FALSE;
    message->info = NULL;
}

void mmi_da_app_show_full_screen_popup(U16 title_string_id,
    U16 title_icon_id,
    U16 *content,
    MMI_BOOL free_content, /* If MMI_FALSE, content should be permament data */
    U16 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_full_screen_popup_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
    mmi_frm_display_dummy_screen_ex(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_DUMMY);
    //DeleteScreenIfPresent(SCR_ID_DA_FULL_SCREEN_POPUP);   
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_FULL_SCREEN_POPUP);
    
    mmi_da_scr_full_screen_popup_free_context();

    cntx = (mmi_da_scr_full_screen_popup_context_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_full_screen_popup_context_struct));
    cntx->title_string_id = title_string_id;
    cntx->title_icon_id = title_icon_id;
    cntx->free_content_when_destroy = free_content;
    cntx->content = content;
    
    g_mmi_da_scr_full_screen_popup_cntx = cntx;

    mmi_da_scr_entry_full_screen_popup();

    if (tone_id != 0)
    {
        srv_prof_play_tone((srv_prof_tone_enum)tone_id, NULL);
    }

    //SetDelScrnIDCallbackHandler(SCR_ID_DA_FULL_SCREEN_POPUP, mmi_da_scr_delete_full_screen_popup);
}

void mmi_da_scr_full_screen_popup_ok_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_da_scr_full_screen_popup_free_context();

    mmi_frm_scrn_close_active_id();
}

void mmi_da_scr_full_screen_popup_free_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_full_screen_popup_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_da_scr_full_screen_popup_cntx;
    
    if (cntx != NULL)
    {
        if (cntx->free_content_when_destroy &&
            cntx->content != NULL)
        {
            srv_srv_da_adp_mem_free(cntx->content);
        }

        srv_srv_da_adp_mem_free(cntx);
        
        g_mmi_da_scr_full_screen_popup_cntx = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_delete_full_screen_popup
 * DESCRIPTION
 *  Delete handler for full screen popup.
 *  This function cleans resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_da_scr_delete_full_screen_popup(void *unused)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_da_scr_full_screen_popup_free_context();

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_show_simple_popup
 * DESCRIPTION
 *  Popup message.
 * PARAMETERS
 *  string_id   [IN] Message string ID
 *  type        [IN] Popup type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_show_popup(UI_string_ID_type string_id, S32 cause, srv_da_popup_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type;
    UI_string_ID_type str_id;    


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    popup_type = mmi_da_app_map_popup_event(type);    
    str_id = mmi_da_app_map_string(string_id, cause, type);
    if(type == SRV_DA_POPUP_TYPE_NMGR_POPUP)
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, popup_type, (WCHAR *)GetString(str_id));
    }
    else
    {
        mmi_da_app_show_popup_ext(str_id, type);
    }
}
#ifndef MMI_DA_PLUTO_SLIM
static mmi_ret mmi_da_entry_new_push_discard_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *result_evt;
    srv_da_push_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    item = (srv_da_push_item_struct*)evt->user_data;
    
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            result_evt = (mmi_alert_result_evt_struct*)evt;

            if (result_evt->result == MMI_ALERT_CNFM_YES)
            {
                srv_da_push_free_item(item);
            }
            mmi_frm_scrn_close(MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP, SCR_ID_DA_NEW_PUSH_IND);
            break;

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            /* Press End key on the group of new push */
            srv_da_push_free_item(item);
            mmi_frm_scrn_close(MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP, SCR_ID_DA_NEW_PUSH_IND);
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_entry_new_push_discard_ask
 * DESCRIPTION
 *  Before user really cancel a push, confirm first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_entry_new_push_discard_ask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.parent_id = mmi_frm_group_get_active_id();
    mmi_confirm_display_ext(
        STR_ID_DA_DISCARD_ASK,
        MMI_EVENT_QUERY,
        &confirm_arg);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_show_simple_popup
 * DESCRIPTION
 *  Popup message.
 * PARAMETERS
 *  string_id   [IN] Message string ID
 *  type        [IN] Popup type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_show_popup_ext(UI_string_ID_type str, srv_da_popup_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type;
    popup_type = mmi_da_app_map_popup_event(type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(str,popup_type,GRP_ID_ROOT,NULL);
}
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
 * FUNCTION
 *  mmi_da_entry_new_push_accept
 * DESCRIPTION
 *  Start to process the push.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_entry_new_push_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct     *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = srv_da_get_item_in_notifying();

    srv_da_push_prepend_to_list(srv_da_get_top_processing_list_item(), item);
    srv_da_push_remove_from_list(srv_da_get_item_to_be_confirm(), item);
    mmi_frm_scrn_close_active_id();
    mmi_da_launch_app(MMI_DA_LAUNCH_FROM_IDLE);
    srv_da_push_select_storage(item, NULL);
}

mmi_ret mmi_da_enter_push_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct     *item;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;
            item = srv_da_get_item_in_notifying();
#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
            ShowCategory154Screen(
                0,
                0,
                STR_GLOBAL_SAVE,
                0,
                STR_GLOBAL_DISCARD,
                0,
                (U8*)GetString(STR_ID_DA_NEW_PUSH),
                (U8*)GetString(mmi_da_search_mime_type_string(item->mime_type)),
                IMG_NEW_MESSAGE_NOTIFICATION_MSG,
                NULL);
            break;
        }

        case EVT_ID_WGUI_LSK_CLICK:
#ifndef __MMI_WGUI_DISABLE_CSK__
        case EVT_ID_WGUI_CSK_CLICK:
#endif
        {
            mmi_da_entry_new_push_accept();           
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_da_entry_new_push_discard_ask();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_GOBACK:
        {
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {            
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {           
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_entry_new_push_ind
* DESCRIPTION
*   Entry function: Enter the screen to indicate user there is a file need to process
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
static void mmi_da_entry_new_push(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct     *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_DA_PUSH_TRACE(mmi_da_entry_new_push);

    item = (srv_da_push_item_struct*)es_data->user_data;
    srv_da_set_item_in_notifying(item);

    /*
     * NOTE: SCR_ID_DA_NEW_PUSH_IND shall not be pushed into history,
     * let high-priority events(ex. miss calls) be shown first.
     */
    mmi_frm_scrn_create(es_data->group_id, es_data->scrn_id, mmi_da_enter_push_proc, NULL);
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
#endif //0
}

void mmi_da_app_notify_new_push(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *active_item;
    MMI_ID grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //DA_TRACE_FUNC(mmi_da_entry_new_push_ind);

    active_item = srv_da_push_get_head_item(srv_da_get_item_to_be_confirm());

    if (active_item != NULL)
    {
        grp_id = mmi_frm_group_create_ex(
            mmi_idle_get_group_id(),
            MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP,
            mmi_da_entry_new_push_discard_proc,
            active_item,
	    MMI_FRM_NODE_SMART_CLOSE_FLAG);

        srv_da_set_item_in_notifying(active_item);
        mmi_frm_scrn_create(grp_id, SCR_ID_DA_NEW_PUSH_IND, mmi_da_enter_push_proc, NULL);
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_show_simple_popup
 * DESCRIPTION
 *  Popup message.
 * PARAMETERS
 *  string_id   [IN] Message string ID
 *  type        [IN] Popup type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_show_popup_error_ext(U16 *str, srv_da_popup_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type;
    popup_type = mmi_da_app_map_popup_event(type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(str,popup_type,GRP_ID_ROOT,NULL);
}


MMI_BOOL mmi_da_app_popup_for_job_msg_ext(srv_da_job_struct *job, srv_da_popup_message_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Don't popup during reporting */
    if (job->reporting)
    {
        if (msg->free_string_after_popup &&
            msg->string != NULL)
        {
            srv_srv_da_adp_mem_free(msg->string);
            msg->string = NULL;
        }
        if (msg->info != NULL)
        {
            srv_srv_da_adp_mem_free(msg->info);
            msg->info = NULL;
        }
        msg->type = SRV_DA_POPUP_TYPE_NONE;
        return MMI_TRUE;
    }

    if (msg != &(job->pending_popup))
    {
        srv_da_discard_pending_popup(job);
    }
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

    if (srv_da_is_popup_allowed())
    {
        if (msg->type == SRV_DA_POPUP_TYPE_LONG_MESSAGE)
        {
             srv_da_set_curr_job(job);
        }
    
        goto POPUP;
    }
    else if (msg != &(job->pending_popup))
    {
        memcpy(&(job->pending_popup), msg, sizeof(srv_da_popup_message_struct));
        msg->type = SRV_DA_POPUP_TYPE_NONE;
    }
    
#else /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

    if (srv_da_is_popup_allowed())
    {
        if (msg->type == SRV_DA_POPUP_TYPE_LONG_MESSAGE)
        {
             srv_da_set_curr_job(job);
        }
    
        goto POPUP;
    }

#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
	return MMI_TRUE;
POPUP:
	mmi_da_app_show_user_defined_popup(msg);
	return MMI_TRUE;

}

MMI_BOOL mmi_da_app_popup_for_job_ext(
    srv_da_job_struct *job,	
    U16 title_string_id,
    U16 title_icon_id,
    srv_da_popup_type_enum type,
    U16 *message_str,
    MMI_BOOL free_string_after_popup,
    void *info)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_message_struct message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(type != SRV_DA_POPUP_TYPE_NONE, type, 0, free_string_after_popup);

    /* Don't popup during reporting */
    if (job->reporting)
    {
        if (free_string_after_popup)
        {
            srv_srv_da_adp_mem_free(message_str);
        }
        if (info != NULL)
        {
            srv_srv_da_adp_mem_free(info);
        }
        return MMI_TRUE;
    }
    
    message.type = type;
    message.title_string_id = title_string_id;
    message.title_icon_id = title_icon_id;
    message.string = message_str;
    message.free_string_after_popup = free_string_after_popup;
    message.info = info;

    return mmi_da_app_popup_for_job_msg_ext(job, &message);
}

void mmi_da_app_popup_for_job_msg(
    srv_da_job_struct *job,
	U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		U16 *popup_string;
        const U16 *popup_suffix;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/            
#ifdef __DRM_SUPPORT__
            popup_suffix = (const U16*)get_string(STR_ID_DA_RIGHTS_DELAYED_SUFFIX);
            popup_string = (U16 *)srv_da_adp_mem_allocate((mmi_wcslen(filepath) + mmi_wcslen(popup_suffix) + 10) * sizeof(U16));
            kal_wsprintf(popup_string, "%w%w", filepath, popup_suffix);
    mmi_da_app_popup_for_job_ext(job, STR_ID_DA_NO_RIGHTS, srv_da_job_get_title_icon(job), SRV_DA_POPUP_TYPE_LONG_MESSAGE, popup_string,  MMI_TRUE, NULL);
#endif /* __DRM_SUPPORT__ */
}

void mmi_da_app_popup_for_job(
    srv_da_job_struct *job,
    srv_da_popup_type_enum type,
    U16 *message_str,
    MMI_BOOL free_string_after_popup,
	void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_da_app_popup_for_job_ext(job, 0, 0, type, message_str, free_string_after_popup, info);
}


void mmi_da_app_popup_error_for_job(srv_da_job_struct *job, srv_da_popup_type_enum type, S32 cause, U16 error_str_id, MMI_BOOL terminate_job)
{
	UI_string_ID_type str_id;
    str_id = mmi_da_app_map_string(error_str_id, cause, type);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

    mmi_da_app_popup_for_job(job, SRV_DA_POPUP_TYPE_ERROR, (U16*)get_string(str_id), MMI_FALSE, NULL);
    if (job->reporting)
    {
        if (terminate_job)
        {
            job->state = SRV_DA_JOB_STATE_ABORTED;
        }
    }
    else
    {
        if (terminate_job)
        {
			
			job->state = SRV_DA_JOB_STATE_ABORTED;

		}

    }
    
#else /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

    mmi_da_app_popup_for_job(job, SRV_DA_POPUP_TYPE_ERROR, (U16*)get_string(str_id), MMI_FALSE, NULL);
    
    if (terminate_job)
    {
        job->state = SRV_DA_JOB_STATE_ABORTED;
    }
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_job_do_popup
 * DESCRIPTION
 *  Popup message for job. Either completed message or error message.
 * PARAMETERS
 *  arg         [IN] mmi_da_job_struct*
 *  screen_id   [IN] Triggered by which screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_job_do_popup(void* arg, S32 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_da_get_popup_triggere())
    {
        return;
    }

    srv_da_set_popup_triggerr(MMI_FALSE);
    
    job = (srv_da_job_struct*)arg;
    
    if (!srv_da_is_job_valid(job))
    {
        return;
    }

    if (mmi_da_is_suitable_to_popup_for_job(job))
    {
        if(job->state == SRV_DA_JOB_STATE_COMPLETED && !job->notified_complete)
        {
            mmi_da_job_complete(job);
           
            mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_CALLBACK_CONFIRM);
        }
        else if(job->state == SRV_DA_JOB_STATE_FAILED)
        {
            if (job->pending_popup.type != SRV_DA_POPUP_TYPE_NONE)
            {
                if (job->pending_popup.type == SRV_DA_POPUP_TYPE_LONG_MESSAGE)
                {
                    srv_da_set_curr_job(job);
                }
            
                mmi_da_app_show_user_defined_popup(&job->pending_popup);
            }
            else
            {
                mmi_da_app_show_popup_ext(STR_GLOBAL_ERROR, SRV_DA_POPUP_TYPE_ERROR);
            }
            
            job->state = SRV_DA_JOB_STATE_ABORTED;
            srv_da_free_job_and_remove_screens(job);
        }
        else if(job->pending_popup.type != SRV_DA_POPUP_TYPE_NONE)
        {
            if (job->pending_popup.type == SRV_DA_POPUP_TYPE_LONG_MESSAGE)
            {
                srv_da_set_curr_job(job);
            }
            mmi_da_app_show_user_defined_popup(&job->pending_popup);
        }
    }
}

void mmi_da_app_show_popup_with_callback(UI_string_ID_type string_id, mmi_proc_func callback)
{
    mmi_popup_property_struct popup_arg;
    mmi_popup_property_init(&popup_arg);
    popup_arg.callback = callback;
    mmi_popup_display_ext(string_id,MMI_EVENT_FAILURE, &popup_arg);
}


//tODO
#ifndef MMI_DA_PLUTO_SLIM
extern void mmi_da_scr_auth_show_confirm(mmi_da_auth_edit_struct *context);
/*****************************************************************************
 * FUNCTION
 *  mmi_da_auth_on_user_submitted
 * DESCRIPTION
 *  get the content of inline item and popup confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_auth_on_user_submitted(mmi_da_auth_edit_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Store the input to username/password */
    cui_inline_get_value(context->inline_cui_id, MMI_DA_AUTH_USERNAME_EDITOR, context->username);
    cui_inline_get_value(context->inline_cui_id, MMI_DA_AUTH_PASSWARD_EDITOR, context->password);

    mmi_da_scr_auth_show_confirm(context);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_oma_show_auth_screen
 * DESCRIPTION
 *  Show authtentication screen for the job. This function is called via
 *  trigger-when-enter(DOWNLOAD_PLEASE_WAIT).
 * PARAMETERS
 *  arg         [IN] mmi_da_job_struct*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_oma_show_auth_screen_delete_hdlr(void *argument)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_show_user_auth_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (mmi_da_show_user_auth_struct*)argument;
    if(item)
        OslMfree(item);
}
   

/*****************************************************************************
 * FUNCTION
 *  mmi_da_oma_show_auth_screen
 * DESCRIPTION
 *  Show authtentication screen for the job. This function is called via
 *  trigger-when-enter(DOWNLOAD_PLEASE_WAIT).
 * PARAMETERS
 *  arg         [IN] mmi_da_job_struct*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_oma_show_auth_screen(void *argument)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    mmi_da_show_user_auth_struct *arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arg = (mmi_da_show_user_auth_struct*)argument;
    job = (srv_da_job_struct*)(arg->arg);

    mmi_da_scr_user_auth(arg->auth_callback, (U32)job, srv_da_job_get_title_icon(job));
}

/*************************************************************************
* FUNCTION
*  mmi_da_scr_auth_get_inline_param
* DESCRIPTION
*  create the inline item 
* PARAMETERS
* RETURNS
*************************************************************************/
const cui_inline_struct *mmi_da_scr_auth_get_inline_param(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const cui_inline_item_caption_struct username_caption =
    {
        STR_GLOBAL_USERNAME
    };

    static const cui_inline_item_fullscreen_edit_struct username_editor = 
    {
        0,
        0,
        STR_GLOBAL_USERNAME,
        0,
        0,
        IMM_INPUT_TYPE_ENGLISH_SENTENCE,
        MMI_DA_AUTH_LEN_USERNAME,
        NULL
    };

    static const cui_inline_item_caption_struct passward_caption =
    {
        STR_GLOBAL_PASSWORD
    };

    static const cui_inline_item_fullscreen_edit_struct passward_editor = 
    {
        0,
        0,
        STR_GLOBAL_PASSWORD,
        0,
        0,
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        MMI_DA_AUTH_LEN_PASSWORD,
        NULL
    };

    static const cui_inline_item_softkey_struct softkey_setting = 
    {
        {
            { CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0 },
        	{ CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0 },
        	{ STR_GLOBAL_CANCEL, 0}
        }
    };

    static const cui_inline_set_item_struct component_list[] = 
    {
        { MMI_DA_AUTH_USERNAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &username_caption },
        { MMI_DA_AUTH_USERNAME_EDITOR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, &username_editor },
        { MMI_DA_AUTH_PASSWARD_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &passward_caption },
        { MMI_DA_AUTH_PASSWARD_EDITOR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, &passward_editor }
    };

    static const cui_inline_struct inline_param = 
    {
        sizeof(component_list) / sizeof(cui_inline_set_item_struct),
        STR_GLOBAL_AUTHENTICATION,
        0,
        CUI_INLINE_SCREEN_LOOP,
        (cui_inline_item_softkey_struct*)&softkey_setting,
        component_list
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &inline_param;
}
#endif
/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_da_app_is_in_foreground_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO double confirm this
    switch (mmi_frm_scrn_get_active_id())
    {
        case SCR_ID_DA_JOB_LIST:
        case SCR_ID_DA_JOB_DETAIL:
        case SCR_ID_DA_JOB_OBJECT_DESCRIPTION:
        case SCR_ID_DA_JOB_ABORT_CONFIRM:
        case SCR_ID_DA_DUMMY:
            return MMI_TRUE;

        default:
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            if (mmi_da_is_job_list_option_on_top())
            {
                return MMI_TRUE;
            }
#endif
            break;
    }

    // TODO: if in WAP browser, in_foregorund should be MMI_TRUE
    
    return MMI_FALSE;
}
#if defined (__MMI_OMA_DD_DOWNLOAD__)
#ifdef MMI_DA_CFG_OMA_EXPOSE_DD_TO_USER
/*****************************************************************************
 * FUNCTION
 *  mmi_da_oma_download_options_cancel
 * DESCRIPTION
 *  Cancel handler for the Cancel RSK of download options screen.
 *  The active job will be passed by curr_job.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_oma_download_options_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(srv_da_oma_get_current_job() != NULL);
    
    ClearInputEventHandler(MMI_DEVICE_ALL);
    
    g_da_del_download_option = MMI_FALSE;
    //ClearDelScrnIDCallbackHandler(SCR_ID_DA_OMA_DOWNLOAD_OPTION, NULL);
    
    srv_da_oma_open_nextURL(srv_da_oma_get_current_job());
    
    srv_da_oma_popup_and_send_report(
        srv_da_oma_get_current_job(),
        SRV_DA_OMA_USER_CANCELLED,
        MMI_TRUE,
        MMI_TRUE);
        
    srv_da_oma_set_current_job(NULL);
//TODO remove old history
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DA_OMA_DOWNLOAD_OPTION)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        //DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_OPTION);        
        mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_OMA_DOWNLOAD_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_oma_delete_download_option
 * DESCRIPTION
 *  Cancel da_oma_context.curr_job while the Options screen is being deleted.
 * PARAMETERS
 *  unused      [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_da_oma_delete_download_option(void *unused)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_da_oma_get_current_job() != NULL)
    {
        srv_da_oma_popup_and_send_report(
            srv_da_oma_get_current_job(),
            SRV_DA_OMA_USER_CANCELLED,
            MMI_TRUE,
            MMI_FALSE);
    }

    return (U8)MMI_FALSE; /* Allow to be deleted */
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_da_oma_cancel_download
 * DESCRIPTION
 *  Cancel handler for the "Please wait" of initializing WPS session and
 *  sending HTTP request
 * PARAMETERS
 *  arg         [IN] mmi_da_job_struct*
 *  is_deleted  [IN] In delete context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_oma_cancel_download(void *arg, MMI_BOOL is_deleted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;

    srv_da_oma_popup_and_send_report(job, SRV_DA_OMA_USER_CANCELLED, MMI_TRUE, (MMI_BOOL)(!is_deleted));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_oma_filename_done
 * DESCRIPTION
 *  Result of select-storage to save the file
 * PARAMETERS
 *  criteria        [IN] (mmi_da_push_item_struct*)Push item
 *  filepath        [IN] The filepath user selected, NULL if not selected
 *  canback         [IN] Can reject the selection
 *  canpopup        [IN] Popup is allowed
 *  instance        [IN] Instance of select-storage
 * RETURNS
 *  Acceptance
 *****************************************************************************/
srv_da_acceptance_enum mmi_da_oma_filename_done(
    U32 criteria, U16* filepath, MMI_BOOL canback, MMI_BOOL canpopup, void *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_omadl_job_struct     *job_data;

    srv_da_setting_struct       *setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)criteria;
    job_data = (srv_da_omadl_job_struct*)job->data_ptr;
    
    if (filepath == NULL)
    {
        srv_da_scr_select_storage_cause_enum cause;
        srv_da_oma_error_enum oma_error;

        if (instance != NULL)
        {
            cause = mmi_da_scr_select_storage_get_cause(instance);
        
            switch (cause)
            {
                case SRV_DA_SCR_SELECT_STORAGE_CAUSE_INSUFFICIENT_MEMORY:
                    oma_error = SRV_DA_OMA_INSUFFICIENT_MEMORY;
                    break;
                case SRV_DA_SCR_SELECT_STORAGE_CAUSE_USER_BACK:
                    //if (IsScreenPresent(SCR_ID_DA_OMA_DOWNLOAD_OPTION))
                    if(mmi_frm_scrn_is_present(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_OMA_DOWNLOAD_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                    {
                        /* Go back to download option after the select storage destroyed */
                        srv_da_oma_set_current_job(job);
                        mmi_da_set_active_select_storage_instance(NULL);
                        return SRV_DA_ACCEPTANCE_ACCEPT;
                    }
                    else
                    {
                        oma_error = SRV_DA_OMA_USER_CANCELLED;
                    }
                    break;
                case SRV_DA_SCR_SELECT_STORAGE_CAUSE_DELETE_SCREEN:
                    oma_error = SRV_DA_OMA_USER_CANCELLED;
                    break;
                default:
                    oma_error = SRV_DA_OMA_DEVICE_ABORTED;
                    break;
            }
        }
        else
        {
            cause = SRV_DA_SCR_SELECT_STORAGE_CAUSE_INSUFFICIENT_RESOURCE;
            oma_error = SRV_DA_OMA_DEVICE_ABORTED;
        }
        
        g_da_del_download_option = MMI_FALSE;
        //ClearDelScrnIDCallbackHandler(SCR_ID_DA_OMA_DOWNLOAD_OPTION, NULL);

        if (cause != SRV_DA_SCR_SELECT_STORAGE_CAUSE_DELETE_SCREEN)
        {
            srv_da_oma_open_nextURL(job);
            mmi_da_scr_remove_screen(SCR_ID_DA_OMA_DOWNLOAD_OPTION);
        }
        
        srv_da_oma_popup_and_send_report(job, oma_error, MMI_TRUE, canpopup);

        mmi_da_set_active_select_storage_instance(NULL);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }

    srv_da_set_allow_to_trigger_connection(MMI_TRUE);
    
    UCS2_STR_MALLOC_COPY(job_data->filepath, filepath);

#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
    if(job->dl_flag & DA_DL_FLAG_SPECIAL)
    {
        FS_HANDLE hd;
        if ((hd = FS_Open((PU16)filepath, FS_READ_ONLY)) >= 0)
        {
            FS_GetFileSize(hd, &(job_data->curr_size));
            FS_Close(hd);
        }
    }

    if(!(job->dl_flag & DA_DL_FLAG_SKIP_CONFIRM))
    {
        if (job_data->size != job_data->curr_size)/* MAUI_02636426: Only processing required no download initiated */
        {
            mmi_da_app_scr_show_progressing(
                SCR_ID_DA_DOWNLOAD_PLEASE_WAIT,
                STR_ID_DA_PROCESSING,
                srv_da_job_get_title_icon(job),
                STR_GLOBAL_PLEASE_WAIT,
                MMI_TRUE,
                job,
                mmi_da_oma_cancel_download);
        }
    }
#else

    mmi_da_app_scr_show_progressing(
        SCR_ID_DA_DOWNLOAD_PLEASE_WAIT,
        STR_ID_DA_PROCESSING,
        srv_da_job_get_title_icon(job),
        STR_GLOBAL_PLEASE_WAIT,
        MMI_TRUE,
        job,
        mmi_da_oma_cancel_download);

#endif
    g_da_del_download_option = MMI_FALSE;
    //ClearDelScrnIDCallbackHandler(SCR_ID_DA_OMA_DOWNLOAD_OPTION, NULL);
    //DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_OPTION);    
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_OMA_DOWNLOAD_OPTION);

#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
    if (job->dl_flag & DA_DL_FLAG_SPECIAL)
    {
        if (job_data->size == job_data->curr_size)
        {
            /* MAUI_02636426: Very specific case when user manage to pull out battery while Job was in processing state */
            setting = srv_da_get_setting_buffer();
            srv_da_oma_get_setting(job, setting);
            srv_da_copy_setting(job, setting);
	        job->state = SRV_DA_JOB_STATE_DOWNLOADING;
            srv_da_job_start(job);
            MMI_ASSERT(job->reporting);

	    job_data->oma_state = SRV_DA_OMA_STATE_DOWNLOADING;

	    job->state = SRV_DA_JOB_STATE_COMPLETED;
            srv_da_oma_do_next_procedure (job);
            return SRV_DA_ACCEPTANCE_ACCEPT;
        }
    }
#endif
        
    srv_da_oma_set_current_job(NULL);
    mmi_da_set_active_select_storage_instance(NULL);

    job_data->session = srv_da_wps_create_session_ex(
        (U32)job,
        SRV_DA_WPS_SETTING_DEFAULT,
        job_data->channel,
        srv_da_oma_session_created_callback,
        srv_da_oma_http_response_callback,
        srv_da_oma_http_auth_ind_callback,
        srv_da_oma_session_dl_progress_callback);

#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
    if (job->dl_flag & DA_DL_FLAG_SPECIAL)
    {
        MMI_BOOL unbuffered_write;
        unbuffered_write = MMI_TRUE;
        srv_da_wps_session_set_option(job_data->session, SRV_DA_WPS_OPTION_UNBUFFERED_WRITE, &(unbuffered_write));
    }
#endif

    return SRV_DA_ACCEPTANCE_ACCEPT;
}
#endif // #if defined (__MMI_OMA_DD_DOWNLOAD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_da_is_suitable_to_popup_for_job
 * DESCRIPTION
 *  Check if it suitable to popup a job-specific message (for one certain job).
 * PARAMETERS
 *  job     [IN]    The target job.
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_da_is_suitable_to_popup_for_job(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen_id = mmi_frm_scrn_get_active_id();

    if (active_screen_id == SCR_ID_DA_DUMMY)
    {
        active_screen_id = mmi_frm_scrn_get_neighbor_id(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_DUMMY,MMI_FRM_NODE_BEFORE_FLAG);
    }

    if ((active_screen_id == SCR_ID_DA_JOB_LIST) || (active_screen_id == SCR_ID_DA_JOB_DETAIL && srv_da_get_curr_job() == job) ||
        (active_screen_id == SCR_ID_DA_JOB_OBJECT_DESCRIPTION && srv_da_get_curr_job() == job) ||
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        (mmi_da_is_job_list_option_on_top()) ||
#endif
        (active_screen_id == SCR_ID_DA_JOB_ABORT_CONFIRM && srv_da_get_curr_job() == job)
    )
		return MMI_TRUE;

	else
		return MMI_FALSE;
}

#ifndef __MMI_DOWNLOAD_AGENT_MULTI_DL__
void mmi_da_job_entry_complete(srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    
    if(!mmi_da_job_is_allowed_to_be_dispatched(job))
    {
        if (!job->notified_complete)
        {
#ifdef SLIM_WAP_MMS            
			mmi_da_app_show_popup_ext(STR_GLOBAL_DONE, SRV_DA_POPUP_TYPE_DONE);
#else
			mmi_da_app_show_popup_ext(STR_ID_DA_PROMPT_DL_COMPLETE, SRV_DA_POPUP_TYPE_DONE);
#endif
        }
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
#endif
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_choice_close
 * DESCRIPTION
 *  Close choice screen.
 * PARAMETERS
 *  instance_id     [IN] Instance ID returned by mmi_da_scr_show_choice_screen()
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_scr_choice_close(U16 instance_id, MMI_BOOL callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *prev;
    mmi_da_scr_choice_screen_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (instance_id == 0)
    {
        return;
    }

    prev = NULL;
    for (cntx = g_mmi_da_scr_choice_cntx.top_screen; cntx != NULL; cntx = cntx->next)
    {
        if (cntx->screen_id == instance_id)
        {
            break;
        }

        prev = cntx;
    }

    /* Client should get the screen ID by the return value of mmi_da_scr_show_choice_screen() */
    MMI_ASSERT(cntx != NULL);

    //ClearDelScrnIDCallbackHandler(cntx->screen_id, mmi_da_app_scr_choice_delete_hdlr);
    mmi_da_update_need_to_del_choice_screen(MMI_FALSE);

    if (callback && cntx->delete_hdlr != NULL)
    {
        cntx->delete_hdlr(cntx->arg);
    }

    mmi_da_app_scr_remove_screen(cntx->screen_id);

    mmi_da_app_scr_choice_free_screen_context(cntx);
}

#endif
#if defined(BROWSER_SUPPORT)
//scrhdlr
/*****************************************************************************
 * FUNCTION
 *  mmi_da_close_all_screens
 * DESCRIPTION
 *  Close download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_close_all_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Assume that top screen does not belong to DLAgent */

    /* Top-down deletion, just like press End key */
    //DeleteScreenIfPresent(SCR_ID_DA_FULL_SCREEN_POPUP);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_FULL_SCREEN_POPUP);
    //DeleteScreenIfPresent(SCR_ID_DA_JOB_CALLBACK_CONFIRM);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_CALLBACK_CONFIRM);
    //DeleteScreenIfPresent(SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
    //DeleteScreenIfPresent(SCR_ID_DA_JOB_DETAIL);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_DETAIL);
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
    mmi_fmgr_close_da_file(); /* Close the Options provided by FMGR */
#endif
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    mmi_da_close_job_list_option();
#endif
    //DeleteScreenIfPresent(SCR_ID_DA_JOB_LIST);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_JOB_LIST);
    //DeleteScreenIfPresent(SCR_ID_DA_SCREEN_AUTH);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_SCREEN_AUTH);
    //DeleteScreenIfPresent(SCR_ID_DA_DOWNLOAD_PLEASE_WAIT);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_DOWNLOAD_PLEASE_WAIT);

    if (g_mmi_da_context.select_storage_instance != NULL)
    {
        mmi_da_app_scr_close_select_storage(g_mmi_da_context.select_storage_instance, MMI_TRUE);
        g_mmi_da_context.select_storage_instance = NULL;
    }

    //DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD);
    //DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_OPTION);
    mmi_da_check_presence_and_close_screen(g_mmi_da_context.da_app_scr_group_id, SCR_ID_DA_OMA_DOWNLOAD_OPTION);

    /* Remove download confirm screen */
#ifndef MMI_DA_PLUTO_SLIM
    if (g_mmi_da_context.download_confirm_screen != 0)
    {
        mmi_da_scr_choice_close(g_mmi_da_context.download_confirm_screen, MMI_TRUE);
        g_mmi_da_context.download_confirm_screen = 0;
    }
#endif

    if (srv_da_get_curr_job_in_setuping_state() != NULL)
    {
        srv_da_job_cancel(srv_da_get_curr_job_in_setuping_state());
        //handled in srvg_mmi_da_context.setuping_job = NULL;
    }
    mmi_frm_group_close(MMI_DA_CONFIRM_SCREEN_GROUP);
    mmi_frm_group_close(MMI_DA_DOWNLOAD_LIST_GROUP);
    mmi_frm_group_close(MMI_DA_BRW_ENTRY_SCREEN_GROUP);
}
#endif

srv_da_job_filestamp_enum mmi_da_app_job_check_filestamp (srv_da_job_struct* job, U16 *error_reason_id)
{
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16*  filepath = NULL;
    FS_HANDLE   filehandle = 0;
    UINT        filesize;
    S32         ret;
    U16         error_id = STR_ID_DA_ERROR_TEMP_UNAVAILABLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job);
    ret = SRV_DA_FILESTAMP_CHECK_OK;

    if (job->type == SRV_DA_JOB_TYPE_MREDL)
    {
        goto func_end;
    }
    
    if(job->state != SRV_DA_JOB_STATE_COMPLETED &&
        job->state != SRV_DA_JOB_STATE_PAUSED && job->state != SRV_DA_JOB_STATE_RESUMING) 
    {
        /* no need check */
        goto func_end;
    }

    
    // TODO: check for temporary or permant missing?

    filepath = job->op->get_filepath(job);

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() &&
        srv_usb_check_path_exported((WCHAR*)filepath))
    {
        /* if path is exported , it is temporary */
        ret = SRV_DA_FILESTAMP_CHECK_FAIL_TEMP;
        error_id = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
        goto func_end;
    }
#endif

    /* try to open file */
    filehandle = FS_Open((U16*)filepath, FS_READ_ONLY);

    if(filehandle >= FS_NO_ERROR)
    {
        /* we can provide more check here */
        if(job->filestamp.curr_size != 0xFFFFFFFF)
        {
            FS_GetFileSize(filehandle, &filesize);
            if(job->filestamp.curr_size != filesize)
            {
                ret = SRV_DA_FILESTAMP_CHECK_FAIL;
            }
        }
        FS_Close(filehandle);
    }
    else
    {
        error_id = srv_fmgr_fs_error_get_string(filehandle);
        switch(filehandle)
        {
        case FS_DEVICE_BUSY:
            ret = SRV_DA_FILESTAMP_CHECK_FAIL_TEMP;
            break;

        default:
            ret = SRV_DA_FILESTAMP_CHECK_FAIL;
        }
    }

func_end:
    //DA_TRACE_FUNC2(srv_da_job_check_filestamp, ret, filehandle);

    if(error_reason_id && error_id)
       *error_reason_id = error_id; 
       
    return ret;
#else
    return SRV_DA_FILESTAMP_CHECK_OK;
#endif    
}
void mmi_da_update_need_to_delete_progressing(MMI_BOOL need_delete)
{
    g_da_del_progressing = need_delete;
}

MMI_BOOL mmi_da_get_need_to_delete_progressing(void)
{
    return g_da_del_progressing;
}
void mmi_da_update_need_to_del_dummy(MMI_BOOL need_delete)
{
    g_da_del_dummy = need_delete;
}
MMI_BOOL mmi_da_get_need_to_del_dummy(void)
{
    return g_da_del_dummy;
}
#ifndef MMI_DA_PLUTO_SLIM
void mmi_da_update_need_to_del_choice_screen(MMI_BOOL need_delete)
{
    g_da_del_choice_screen = need_delete;
}

MMI_BOOL mmi_da_get_need_to_del_choice_screen(void)
{
    return g_da_del_choice_screen;
}
#endif
void mmi_da_update_dispatch_confirm_del(MMI_BOOL need_delete)
{
    g_da_del_dispatch_confirm = need_delete;
}
MMI_BOOL mmi_da_get_dispatch_confirm_del(void)
{
    return g_da_del_dispatch_confirm;
}
MMI_BOOL mmi_da_get_delete_download_option(void)
{
    return g_da_del_download_option;
}
void mmi_da_update_del_download_option(MMI_BOOL need_del)
{
    g_da_del_download_option = need_del;
}
void mmi_da_check_presence_and_close_screen(MMI_ID parent_id, MMI_ID scrn_id)
{
    if(mmi_frm_scrn_is_present(parent_id, scrn_id,
                                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(parent_id, scrn_id);
    }
}
MMI_ID mmi_da_get_active_scrn_grp(void)
{
    return g_mmi_da_context.da_app_scr_group_id;
}

void mmi_da_set_active_scrn_grp(MMI_ID grp_id)
{
    g_mmi_da_context.da_app_scr_group_id = grp_id;
}
void mmi_da_app_update_job_list_dirty_flag(MMI_BOOL new_value)
{
    g_mmi_da_context.job_list_dirty_flag = new_value;
}
MMI_BOOL mmi_da_app_get_job_list_dirty_flag(void)
{
    return g_mmi_da_context.job_list_dirty_flag;
}
U16 mmi_da_app_map_action_to_scr(U16 action_id)
{
    if(action_id == SRV_DA_ACTION_SCR_PLEASE_WAIT)
        return SCR_ID_DA_DOWNLOAD_PLEASE_WAIT;
    else if(action_id == SRV_DA_ACTION_SCR_PREFETCHING_CANCELLING)
        return SCR_ID_DA_DOWNLOAD_PREFETCHING_CANCELLING;
    else if(action_id == SRV_DA_ACTION_SCR_OMA_DOWNLOAD_OPTION)
        return SCR_ID_DA_OMA_DOWNLOAD_OPTION;
    else if(action_id == SRV_DA_ACTION_SCR_DRM_PROCESSING)
        return SCR_ID_DA_DRM_PROCESSING;
    else if(action_id == SRV_DA_ACTION_SCR_PUSH_MOVING)
        return SCR_ID_DA_PUSH_MOVING;
	else
		return SCR_ID_DA_DOWNLOAD_PLEASE_WAIT;
}

mmi_da_scr_select_storage_context_struct* mmi_da_get_storage_top(void)
{
    return g_mmi_da_scr_select_storage_top_cntx_p;
}
#endif /*__MMI_DOWNLOAD_AGENT__ */
