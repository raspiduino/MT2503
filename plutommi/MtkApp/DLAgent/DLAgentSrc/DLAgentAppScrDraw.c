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
#include "DLAgentSrvProt.h"
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
#include "Conversions.h"
#include "ProfilesSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrCuiGProt.h"
//#include "FileManagerGProt.h"   /* GetFileSystemErrorString */
//#include "FileManagerDef.h"
//#include "FileMgrResDef.h"

//#include "UCMGProt.h"
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
    #include "DLAgentSrvOMA.h"

static S32 g_mmi_da_highlighted_index = -1;
mmi_da_scr_full_screen_popup_context_struct *g_mmi_da_scr_full_screen_popup_cntx = NULL;
extern mmi_da_scr_trigger_when_enter_context_struct g_mmi_da_scr_trigger_when_enter_cntx;

static void mmi_da_app_curr_job_do_abort_key_hdlr(void);





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
static void mmi_da_entry_new_push_accept(srv_da_push_item_struct     *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    srv_da_push_prepend_to_list(srv_da_get_top_processing_list_item(), item);
    srv_da_push_remove_from_list(srv_da_get_item_to_be_confirm(), item);
    mmi_frm_scrn_close_active_id();
    srv_da_push_select_storage(item, NULL);
}

void mmi_da_nmgr_accept(void)
{
    srv_da_push_item_struct *item;
	srv_da_push_item_struct *active_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = srv_da_push_get_top_screen_stack_item();
	if (!item)
	{
		return;
	}
	srv_da_push_prepend_to_list(srv_da_get_top_processing_list_item(), item);
    srv_da_push_remove_from_list(srv_da_get_item_to_be_confirm(), item);
    srv_da_push_select_storage(item, NULL);


}
	
void mmi_da_nmgr_reject(void)
{
    srv_da_push_item_struct *item;
	srv_da_push_item_struct *active_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = srv_da_push_get_top_screen_stack_item();
		if (!item)
		{
			return;
		}
		//srv_da_push_remove_item_processed (active_item);
		srv_da_set_item_in_notifying(item);
	srv_da_push_free_item(item);


    
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
static mmi_ret mmi_da_push_cancel_rsk_confirm_proc(mmi_event_struct *evt)
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
            mmi_da_nmgr_reject();
			mmi_frm_scrn_close(MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP, SCR_ID_DA_NEW_PUSH_IND);
        }
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
static void mmi_da_entry_new_push_cancel_ask(void)
    {  
	mmi_confirm_property_struct confirm_arg;
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
	confirm_arg.softkey[1].str = (WCHAR*)((UI_string_type)GetString(STR_GLOBAL_YES));
	confirm_arg.softkey[2].str = (WCHAR*)((UI_string_type)GetString(STR_GLOBAL_NO));
	confirm_arg.f_enter_history = MMI_TRUE;
    confirm_arg.callback = mmi_da_push_cancel_rsk_confirm_proc;
	mmi_confirm_display(get_string(STR_GLOBAL_CANCEL), MMI_EVENT_QUERY, &confirm_arg);	
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
        
mmi_ret mmi_da_enter_new_push_proc(mmi_event_struct *evt)
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
		

			 ShowCategory66Screen(
						NULL,
						NULL,
						STR_GLOBAL_VIEW,
						0,
						STR_GLOBAL_CANCEL,
						0,
						(U8*)get_string(STR_ID_DA_NEW_PUSH),
						0,
						NULL);

	           break;
    }    
   
        case EVT_ID_WGUI_LSK_CLICK:
//#ifndef __MMI_WGUI_DISABLE_CSK__
        case EVT_ID_WGUI_CSK_CLICK:
//#endif
        {
            mmi_da_nmgr_accept();           
			mmi_frm_scrn_close(MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP, SCR_ID_DA_NEW_PUSH_IND);
            return MMI_RET_KEY_HANDLED;
    }    
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_da_entry_new_push_cancel_ask();
			//mmi_frm_scrn_close(MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP, SCR_ID_DA_NEW_PUSH_IND);
            return MMI_RET_KEY_HANDLED;
        }

        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {            
			 mmi_frm_scrn_close(MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP, SCR_ID_DA_NEW_PUSH_IND);
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
 *  mmi_da_entry_new_push_discard_ask
 * DESCRIPTION
 *  Before user really cancel a push, confirm first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static mmi_ret mmi_da_entry_new_push_nmgr_proc(mmi_event_struct *evt)
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
#endif
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

static mmi_ret mmi_da_nmgr_proc(mmi_event_struct *evt)
{
    
	srv_da_push_item_struct *active_item;
	MMI_ID grp_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	active_item = srv_da_push_get_head_item(srv_da_get_item_to_be_confirm());

	 if (active_item != NULL)
    {
        grp_id = mmi_frm_group_create_ex(
            mmi_idle_get_group_id(),
            MMI_DA_PUSH_IDLE_ENTRY_SCREEN_GROUP,
            mmi_da_entry_new_push_nmgr_proc,
            active_item,
	    MMI_FRM_NODE_SMART_CLOSE_FLAG);

        srv_da_set_item_in_notifying(active_item);
        mmi_frm_scrn_create(grp_id, SCR_ID_DA_NEW_PUSH_IND, mmi_da_enter_new_push_proc, NULL);
	 }

    return MMI_RET_OK;
}



mmi_ret mmi_da_show_nmgr_alert(void)
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
#endif
	mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_GENERAL,MMI_EVENT_DEFAULT,mmi_da_nmgr_proc,NULL);

	return MMI_RET_OK;
    

}

#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_choice_csk_hdlr
 * DESCRIPTION
 *  LSK handler for choice screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_choice_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_da_app_get_top_screen();

    MMI_ASSERT(cntx != NULL);

    mmi_da_update_need_to_del_choice_screen(MMI_FALSE);

    if (cntx->csk_hdlr != NULL)
    {
        cntx->csk_hdlr(cntx->arg);
    }

    mmi_frm_scrn_close(MMI_DA_CONFIRM_SCREEN_GROUP, cntx->screen_id);

    mmi_da_app_scr_choice_free_screen_context(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_choice_opt_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for internet service menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_da_app_scr_choice_opt_menu_cui_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_da_scr_choice_screen_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_da_app_get_top_screen();
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_DA_DOWNLOAD_CNF_OPT_SAVE)
            {
                MMI_ASSERT(cntx != NULL);
                mmi_da_update_need_to_del_choice_screen(MMI_FALSE);
                if (cntx->csk_hdlr != NULL)
                {
                    cntx->csk_hdlr(cntx->arg);
                }
                mmi_da_scr_remove_screen(cntx->screen_id);
                mmi_da_app_scr_choice_free_screen_context(cntx);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DA_DOWNLOAD_CNF_OPT_SAVE_TO)
            {
                MMI_ASSERT(cntx != NULL);
                mmi_da_update_need_to_del_choice_screen(MMI_FALSE);
                if (cntx->lsk_hdlr != NULL)
                {
                    cntx->lsk_hdlr(cntx->arg, NULL);
                }
                mmi_da_scr_remove_screen(cntx->screen_id);
                mmi_da_app_scr_choice_free_screen_context(cntx);
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cntx->menu_gid);
            break;
    }
    return MMI_RET_OK;
}


void mmi_da_scr_choice_lsk_opt_hdlr (void)
{
	mmi_da_scr_choice_screen_struct *cntx;
    cntx = mmi_da_app_get_top_screen();
    cntx->group_id = mmi_frm_group_create(MMI_DA_CONFIRM_SCREEN_GROUP,
        GRP_ID_AUTO_GEN, 
        mmi_da_app_scr_choice_opt_menu_cui_proc, 
        NULL);
    if(cntx->group_id == GRP_ID_INVALID)
		return;
    mmi_frm_group_enter(cntx->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cntx->menu_gid = cui_menu_create(cntx->group_id,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_DA_DOWNLOAD_CNF_OPT,
        MMI_TRUE,
        NULL);
    cui_menu_run(cntx->menu_gid);
}


#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
#ifndef MMI_DA_PLUTO_SLIM
mmi_ret mmi_da_choice_hdlr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;
    U16 *buffer;
    U32 buffer_len;
    //U8 *gui_buffer;
    //srv_da_job_struct           *job;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;

            cntx = mmi_da_app_get_top_screen();

            MMI_ASSERT(cntx != NULL);

            buffer = (U16*)subMenuData;
            buffer_len = sizeof(subMenuData);

            cntx->fill_msg_string(cntx->arg, buffer, buffer_len);
			#ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
				if (cntx->lsk_string_id != STR_GLOBAL_YES)
				{	
					EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
				}
				else
				{
					EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
				}
    
			#else
            if (cntx->lsk_string_id != 0 && cntx->lsk_hdlr != NULL)
            {
#ifndef __MMI_WGUI_DISABLE_CSK__
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
            }
			#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
            
            ShowCategory74Screen(
                cntx->title_string_id,
                cntx->title_icon_id,
                cntx->lsk_string_id,
                0,
                cntx->rsk_string_id,
                0,
                (U8*)buffer,
                buffer_len,
                p->gui_buffer);
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            cntx = mmi_da_app_get_top_screen();
            //mmi_da_update_need_to_del_choice_screen(MMI_FALSE);
        #ifdef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
			if (cntx->lsk_string_id != STR_GLOBAL_YES)
			{
				mmi_da_scr_choice_lsk_opt_hdlr();
            }
			else
                mmi_da_app_scr_choice_lsk_hdlr();
		#else			
				mmi_da_app_scr_choice_lsk_hdlr();
		#endif
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_da_update_need_to_del_choice_screen(MMI_FALSE);
            mmi_da_app_scr_choice_rsk_hdlr(); 
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_GOBACK:
        {
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            if(mmi_da_get_need_to_del_choice_screen())
                mmi_da_app_scr_choice_delete_hdlr();
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
#endif

mmi_ret mmi_da_app_progressing_proc(mmi_event_struct *evt)
{
    mmi_da_scr_progressing_context_struct *cntx;
    cntx = mmi_da_app_get_top_cntx();
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            
            ShowCategory66Screen(
                cntx->title_string_id,
                cntx->title_icon_id,
                0,
                0,
                (U16)(cntx->cancel_rsk ? STR_GLOBAL_CANCEL : 0),
                0,
                (U8*)get_string(cntx->message_id),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
            if (cntx->cancel_callback == NULL)
            {
                ClearKeyHandler(KEY_END, KEY_EVENT_DOWN); /* Disable End key */
            }

            if (cntx->timer_id != 0)
            {
                srv_da_timer_triggered_proc_cancel(cntx->timer_id);
                cntx->timer_id = 0;
            }
        }
        break;
        case EVT_ID_WGUI_RSK_CLICK:
        {
            if (cntx->cancel_rsk)
            {
                mmi_da_app_scr_progressing_cancel();
            }
             return MMI_RET_KEY_HANDLED;
        }
       
        case EVT_ID_SCRN_GOBACK:
        {
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            if(mmi_da_get_need_to_delete_progressing())
                mmi_da_app_scr_delete_progressing(NULL);
            break;
        }
    }
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_entry_progressing
 * DESCRIPTION
 *  Entry function of progressing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_progressing_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_da_app_get_top_cntx();
    mmi_frm_scrn_create(mmi_da_get_active_scrn_grp(), cntx->screen_id, mmi_da_app_progressing_proc, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_put_real_progressing
 * DESCRIPTION
 *  Replace the dummy progressing by a real progressing.
 * PARAMETERS
 *  arg_p       [IN] mmi_da_scr_progressing_context_struct*
 *  arg_v       [IN] Screen ID of progressing
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_app_scr_put_real_progressing(void *arg_p, S32 arg_v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_progressing_context_struct *cntx;
    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_da_scr_progressing_context_struct*)arg_p;
    screen_id = (U16)arg_v;

    if (mmi_da_app_get_top_cntx() == cntx && /* Make sure cntx is valid */
        cntx->screen_id == screen_id &&
        mmi_frm_scrn_get_active_id() == screen_id)
    {        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_show_progressing
 * DESCRIPTION
 *  Show progressing screen.
 *  If can_cancel == MMI_FALSE && cancel_callback == NULL, the delete callback
 *  will prevent the screen from being deleted.
 * PARAMETERS
 *  screen_id           [IN] Screen ID
 *  title_string_id     [IN] Title string ID
 *  title_icon_id       [IN] Title icon ID
 *  message_id          [IN] String ID of the message, ex: "Please wait"
 *  can_cancel          [IN] Provide RSK "Cancel"
 *  arg                 [IN] Will be passed to cancel_callback()
 *  cancel_callback     [IN] When user press "Cancel" or screen is deleted,
 *                           this function will be invoked.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_show_progressing(
    U16 screen_id,
    U16 title_string_id,
    U16 title_icon_id,
    U16 message_id,
    MMI_BOOL cancel_rsk, /* Show RSK "Cancel" */
    void *arg,
    void (*cancel_callback)(void *arg, MMI_BOOL is_deleted))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_progressing_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cancel_rsk)
    {
        MMI_ASSERT(cancel_callback != NULL);
    }
    
    cntx = (mmi_da_scr_progressing_context_struct*)srv_da_adp_mem_allocate(sizeof(mmi_da_scr_progressing_context_struct));

    cntx->screen_id = screen_id;
    cntx->title_string_id = mmi_da_app_map_string(title_string_id, 0, SRV_DA_POPUP_TYPE_NONE); //top
    cntx->title_icon_id = title_icon_id;
    cntx->message_id = mmi_da_app_map_string(message_id,0,SRV_DA_POPUP_TYPE_NONE);
    cntx->cancel_rsk = cancel_rsk;
    cntx->arg = arg;
    cntx->cancel_callback = cancel_callback;

    /* Set to active screen */
    cntx->next = mmi_da_app_get_top_cntx();
    //g_mmi_da_scr_progressing_top_cntx = cntx;
	mmi_da_app_set_top_cntx(cntx);
    
    mmi_da_app_scr_entry_progressing();    
    mmi_da_update_need_to_delete_progressing(MMI_TRUE);

}

static void mmi_da_app_curr_job_do_abort_key_hdlr(void)
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
        mmi_frm_scrn_close_active_id();
        return;
    }

    switch (job->state)
    {
        case SRV_DA_JOB_STATE_DOWNLOADING:
        case SRV_DA_JOB_STATE_PROCESSING:
        case SRV_DA_JOB_STATE_PAUSED:
            break;
        default:
            mmi_frm_scrn_close_active_id();
            return;
    }
    mmi_frm_scrn_close_active_id();
    mmi_da_app_scr_show_progressing(
        SCR_ID_DA_DOWNLOAD_PLEASE_WAIT,
        0,
        0,
        SRV_DA_GLOBAL_CANCELLING,
        MMI_FALSE,
        NULL,
        NULL);

    
    srv_da_curr_job_do_abort(job);
}


mmi_ret mmi_da_job_abort_hdlr_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;
            if(p->is_first_active)
            {
#ifndef __MMI_WGUI_DISABLE_CSK__                
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);    
#endif
                ShowCategory165Screen(
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    get_string(STR_GLOBAL_CANCEL),
                    mmi_get_event_based_image(MMI_EVENT_QUERY),
                    NULL);
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_QUERY), NULL);
            }
			else
			{
				mmi_frm_scrn_close_active_id();
			}
            return MMI_RET_OK;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            mmi_da_app_curr_job_do_abort_key_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_frm_scrn_close_active_id();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_INACTIVE:
        {
            mmi_da_app_curr_job_exit_abort_confirm();
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

void mmi_da_app_curr_job_entry_abort_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_da_job_struct* curr_job;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_job = srv_da_get_curr_job();

    MMI_ASSERT(curr_job != NULL);
    
    mmi_frm_scrn_create(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_ABORT_CONFIRM, mmi_da_job_abort_hdlr_proc, NULL);
    //EntryNewScreen(SCR_ID_DA_JOB_ABORT_CONFIRM, mmi_da_app_curr_job_exit_abort_confirm, NULL, NULL);       
}

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
mmi_ret mmi_da_downloadlist_hdlr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct   *job;
    S32 job_list_highlight_index;
	MMI_BOOL job_list_updated;
	S32 list_job_num;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;

            job_list_highlight_index = mmi_da_get_job_highlight_index();
	        job_list_updated = srv_da_job_list_updated();
	        list_job_num = srv_da_get_job_list_num();
            guiBuffer = p->gui_buffer;
            if (job_list_updated)
	        {
                guiBuffer = NULL;
		        srv_da_job_set_list_updated(MMI_FALSE);
            }

            if (job_list_highlight_index < 0 ||
                job_list_highlight_index >= list_job_num)
            {
                job_list_highlight_index = 0;
		        mmi_da_set_job_highlight_index(job_list_highlight_index);
            }
        
            job = srv_da_get_nth_job(job_list_highlight_index);

            mmi_da_job_set_toolbar(job);    
#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif            
#ifndef MMI_DA_PLUTO_SLIM
            ShowCategory427Screen(
                (UI_string_type)GetString(STR_ID_DA_JOB_LIST),
                (PU8)GetImage(srv_da_job_get_title_icon(NULL)),
                (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
                (PU8)GetImage(IMG_GLOBAL_OPTIONS),
                (UI_string_type)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                list_job_num,
                mmi_da_app_job_get_display_item,
                job_list_highlight_index,
                guiBuffer);
#endif

            if(!(p->is_bg_redrawing))
            {
                if (list_job_num == 0)
                {
                    srv_da_util_trigger_proc(mmi_da_app_close_job_list, NULL);
                   return MMI_RET_OK;
                }

                //g_mmi_da_context.curr_job = NULL;
		        srv_da_set_curr_job(NULL);
                
                if(!srv_da_get_popup_triggere())
                {
                    /* check for 3 item:
                        1: job with error
                        2: job with popup info
                        3: job is completed and not notify yet */
                    if (job != NULL &&
                        !srv_da_job_match_state_func(job, SRV_DA_JOB_STATE_FAILED) &&
                        !srv_da_job_match_need_complete_notify_func(job, 0) &&
                        !srv_da_job_has_popupinfo_func(job, 0))
                    {
                        job = NULL;
                    }

                    if (job == NULL)
                    {
                        job = srv_da_find_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_FAILED);
                    }
                    if (job == NULL)
                    {
                        job = srv_da_find_job(srv_da_job_match_need_complete_notify_func, 0);
                    }
                    if (job == NULL)
                    {
                        job = srv_da_find_job(srv_da_job_has_popupinfo_func, 0);
                    }

                    if (job != NULL)
                    {
                        /* complete job must be tested for filestamp */
                        if(!srv_da_job_match_need_complete_notify_func(job, 0) ||
                            SRV_DA_FILESTAMP_CHECK_OK == mmi_da_app_job_check_filestamp(job, NULL))
                        {
                            ClearInputEventHandler(MMI_DEVICE_ALL);
					        srv_da_set_popup_triggerr(MMI_TRUE);
                           
                            srv_da_util_trigger_proc_ext(mmi_da_job_do_popup, job, SCR_ID_DA_JOB_DETAIL); 
                            return MMI_RET_OK;
                        }
                    }
                }
            }

            //SetLeftSoftkeyFunction(mmi_da_app_job_list_option_hdlr, KEY_EVENT_UP);
            //SetCenterSoftkeyFunction(mmi_da_app_job_display_details, KEY_EVENT_UP);
            //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
            wgui_register_tap_callback(mmi_da_app_job_list_tap_hdlr);
        #endif
            //RegisterHighlightHandler(mmi_da_app_job_list_highlight_hdlr);
            break;
        }
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            S32 hiliteidx;
            /*----------------------------------------------------------------*/
            /* Local Variables                                                */
            /*----------------------------------------------------------------*/
            S32 job_list_highlight_index;
	        S32 list_job_num;
            /*----------------------------------------------------------------*/
            /* Code Body                                                      */
            /*----------------------------------------------------------------*/
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            hiliteidx = cat_evt->item_index;
			mmi_da_app_job_list_highlight_hdlr(hiliteidx);
			return MMI_RET_CHANGED;
        }
#ifndef __MMI_WGUI_DISABLE_CSK__
        case EVT_ID_WGUI_CSK_CLICK:
        {
            mmi_da_app_job_display_details();
            return MMI_RET_KEY_HANDLED;
        }
#endif
        case EVT_ID_WGUI_LSK_CLICK:
        {
            mmi_da_app_job_list_option_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_frm_scrn_close_active_id(); 
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

void mmi_da_app_entry_job_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    srv_da_job_struct   *job;
    S32 job_list_highlight_index;
	MMI_BOOL job_list_updated;
	S32 list_job_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // DA_TRACE_FUNC(mmi_da_entry_job_list);
	
	//job_list_updated = srv_da_job_list_updated();
	//list_job_num = srv_da_get_job_list_num();
    mmi_frm_scrn_create(MMI_DA_DOWNLOAD_LIST_GROUP, SCR_ID_DA_JOB_LIST, mmi_da_downloadlist_hdlr_proc, NULL);
        }
#endif
#ifdef __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__

mmi_ret mmi_da_view_obj_desc_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    U8* text_buffer;
    U32 text_buffer_size;
    U8* gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
           // mmi_frm_scrn_active_evt_struct * p=
            //(mmi_frm_scrn_active_evt_struct *)evt;
            job = srv_da_get_curr_job();

            MMI_ASSERT(job != NULL);
            MMI_ASSERT(job->op->is_object_desc_available != NULL
                && job->op->is_object_desc_available(job));
            text_buffer = (U8*)subMenuData;
            text_buffer = (U8*)(((U32)text_buffer + 1) & ~0x1); /* align to U16 */
            text_buffer_size = sizeof(subMenuData) - 3;
            
            job->op->get_object_desc(job, (U16*)text_buffer, text_buffer_size);
            
            gui_buffer = p->gui_buffer;

            ShowCategory74Screen(
                STR_GLOBAL_DETAILS,
                mmi_da_job_get_title_icon(job),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                text_buffer,
                text_buffer_size,
                gui_buffer);

            mmi_da_check_and_trigger_popup_on_screen_entry(job, SCR_ID_DA_JOB_OBJECT_DESCRIPTION);
            return MMI_RET_OK;        
}

        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_frm_scrn_close_active_id();
            return MMI_RET_KEY_HANDLED;
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
 *  mmi_da_entry_view_object_desc
 * DESCRIPTION
 *  The entry function of View Object Description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_entry_view_object_desc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // srv_da_job_struct *job;
   // U8* text_buffer;
    //U32 text_buffer_size;
    //U8* gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_scrn_create(MMI_DA_DOWNLOAD_LIST_GROUP, SCR_ID_DA_JOB_OBJECT_DESCRIPTION, mmi_da_view_obj_desc_proc, NULL);
}

#endif /* __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__ */

mmi_ret mmi_da_job_details_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    U32                         percentage;
    U16                         rsk_string_id, titleId;
    UI_string_type              display[3];
    MMI_BOOL                    can_minimize;
    U16                         bannerId;
    MMI_BOOL                    is_object_desc_available;
    U16                         *rsk_string;
    U16                         object_desc_string_id = 0;
    U16                         *object_desc_string = NULL;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;            
            job = srv_da_get_curr_job();
            MMI_ASSERT(job != NULL);            
            percentage = mmi_da_format_job_detail(job, (U16*)subMenuData, MAX_SUB_MENU_SIZE, MAX_SUB_MENUS/2);
        #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            can_minimize = job->setting_info.can_minimize;
        #else
            can_minimize = MMI_FALSE;
        #endif
           if (mmi_frm_scrn_is_present(mmi_da_get_active_scrn_grp(), 
                                        SCR_ID_DA_JOB_LIST, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                can_minimize = MMI_TRUE;
            }
            rsk_string_id = can_minimize ? STR_GLOBAL_BACK : STR_GLOBAL_CANCEL;
        #ifdef __DRM_SUPPORT__
            if (srv_da_is_drm_right(job->mime_type) || srv_da_is_drm_roap(job->mime_type))
            {
                rsk_string_id = 0;
            }
        #endif
            if (rsk_string_id != 0)
            {
                rsk_string = (UI_string_type)get_string(rsk_string_id);
            }
            else
            {
                rsk_string = NULL;
            }            
            titleId = STR_GLOBAL_DETAILS;            
           //TODO 
            if (!mmi_frm_scrn_is_present(mmi_da_get_active_scrn_grp(),
                                        SCR_ID_DA_JOB_LIST, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                /* Enter from options */
                titleId = STR_GLOBAL_DOWNLOADING;
            }
#ifndef MMI_DA_PLUTO_SLIM
            if(job->state == SRV_DA_JOB_STATE_COMPLETED || job->state == SRV_DA_JOB_STATE_PAUSED)
                bannerId = 0;
            else
                bannerId = IMG_ID_DA_DOWNLOAD_PROGRESS_BANNER;
#else
				 bannerId = 0;
#endif

            display[0] = (UI_string_type)(subMenuData)+MAX_SUB_MENU_SIZE;
            display[1] = (UI_string_type)(subMenuData)+MAX_SUB_MENU_SIZE*2;
            display[2] = (UI_string_type)(subMenuData)+MAX_SUB_MENU_SIZE*3;

            if (job->op->is_object_desc_available != NULL &&
                job->op->is_object_desc_available(job))
				is_object_desc_available = MMI_TRUE;
			else
				is_object_desc_available = MMI_FALSE;

        #ifdef __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__
            if (is_object_desc_available)
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            }
            object_desc_string_id = is_object_desc_available ? STR_ID_DA_VIEW_OBJECT_DESC_SHORT : 0;
            object_desc_string = (UI_string_type)(is_object_desc_available ? GetString(STR_ID_DA_VIEW_OBJECT_DESC_SHORT) : NULL);
        #endif
            
        #if defined(__MMI_MAINLCD_128X128__)
            ShowCategory402Screen(
                (U8*) GetString(titleId),
                mmi_da_job_get_title_icon(job),
                (U16)object_desc_string_id,
                0,
                rsk_string_id, 
                0,
                NULL,
                (U16)(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN ? 0 : percentage), /* % */
                (U8*)(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN ? NULL : display[0]) /* progress_string */
                );
        #else

            ShowCategory412Screen(
                (UI_string_type)GetString(titleId),
                (PU8)GetImage(mmi_da_job_get_title_icon(job)),
                (UI_string_type)object_desc_string,
                NULL,
                rsk_string,
                NULL,
                (PU8)GetImage(bannerId),
                (UI_string_type)srv_da_util_get_filename((U16*)subMenuData),
                (U8)(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN ? 255 : percentage), /* % */
                (S32)(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN ? 1 : 3),         /* num_of_items */
                display,
                (U8*)NULL);

        #endif
#if 0
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__
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
/* under construction !*/
/* under construction !*/
#endif                 
                    mmi_da_app_check_and_trigger_popup_on_screen_entry(job, SCR_ID_DA_JOB_DETAIL);
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
			job = srv_da_get_curr_job();
            MMI_ASSERT(job != NULL);
    #ifdef __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__
            is_object_desc_available = (job->op->is_object_desc_available != NULL &&
                job->op->is_object_desc_available(job));
            if(is_object_desc_available)
                mmi_da_entry_view_object_desc();
    #endif
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
			job = srv_da_get_curr_job();
            MMI_ASSERT(job != NULL);

			#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
				can_minimize = job->setting_info.can_minimize;
			#else
				can_minimize = MMI_FALSE;
			#endif

            if (mmi_frm_scrn_is_present(mmi_da_get_active_scrn_grp(), 
                                        SCR_ID_DA_JOB_LIST, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                can_minimize = MMI_TRUE;
            }
            rsk_string_id = can_minimize ? STR_GLOBAL_BACK : STR_GLOBAL_CANCEL;
        #ifdef __DRM_SUPPORT__
            if (srv_da_is_drm_right(job->mime_type) || srv_da_is_drm_roap(job->mime_type))
            {
                rsk_string_id = 0;
            }
        #endif
			switch (rsk_string_id)
			{
				case STR_GLOBAL_BACK:
							mmi_frm_scrn_close_active_id();
					break;
		    
				case STR_GLOBAL_CANCEL:
							mmi_da_app_curr_job_entry_abort_confirm();
					break;

				default:
					break;
			}
            return MMI_RET_KEY_HANDLED;
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
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
 * FUNCTION
 *  mmi_da_app_scr_entry_choice
 * DESCRIPTION
 *  Entry function of choice screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_app_scr_entry_choice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_choice_screen_struct *cntx;
    U16 *buffer;
    U32 buffer_len;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_da_app_get_top_screen();

    MMI_ASSERT(cntx != NULL);
    
    mmi_frm_scrn_create(mmi_da_get_active_scrn_grp(),cntx->screen_id,mmi_da_choice_hdlr_proc, NULL);
}
#endif
#if defined (__MMI_OMA_DD_DOWNLOAD__)
#ifdef MMI_DA_CFG_OMA_EXPOSE_DD_TO_USER

mmi_ret mmi_da_view_dd_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_omadl_job_struct *job_data;
    U8          *guiBuffer;
    S8          *ddcontent = (S8*)hintData;
    S8          *ddcontent2 = (S8*)subMenuData;
    FS_HANDLE   hd = -1;
    UINT        fileSize, sizeRead;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;
            MMI_ASSERT(srv_da_oma_get_current_job());
            job_data = (srv_da_omadl_job_struct*)srv_da_oma_get_current_job()->data_ptr;
            
            /* load text from DD */
            if ((hd = FS_Open(job_data->dd_filepath, FS_READ_ONLY)) < 0)
                goto errorFs;

            if(FS_GetFileSize(hd, &fileSize) < 0)
                goto errorFs;

            if(fileSize >= sizeof(hintData))
                fileSize = sizeof(hintData)-1;

            if(FS_Read(hd, ddcontent, fileSize, &sizeRead)<0)
                goto errorFs;

            ddcontent[sizeRead] = '\0';
            FS_Close(hd);
            hd = -1;

            mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (S8*)ddcontent, (S8*)ddcontent2, sizeof(subMenuData));

            /* Save UCS2 content in context */    
            job_data->dd_content_string = ddcontent2;
            ShowCategory74Screen(
                STR_ID_DA_OMA_VIEW_DD,
                mmi_da_job_get_title_icon(srv_da_oma_get_current_job()),
                0,
                0,
                STR_GLOBAL_BACK,
                0,
                (U8*) job_data->dd_content_string,
                fileSize,
                p->gui_buffer);

            //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
            //SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            return MMI_RET_OK;

            /* clean up if there is error */
        errorFs:
            mmi_da_app_show_popup_ext(srv_fmgr_fs_error_get_string(hd), SRV_DA_POPUP_TYPE_ERROR);

            if(hd >= 0)
                FS_Close(hd);          
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_frm_scrn_close_active_id();
            return MMI_RET_KEY_HANDLED;
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

static void mmi_da_oma_entry_download_view_dd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Entry New Screen */
    //EntryNewScreen(SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD, mmi_da_oma_exit_download_view_dd, mmi_da_oma_entry_download_view_dd, NULL);
    mmi_frm_scrn_create(MMI_DA_CONFIRM_SCREEN_GROUP,SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD,mmi_da_view_dd_proc, NULL);
    
}
#endif /* #ifdef MMI_DA_CFG_OMA_EXPOSE_DD_TO_USER */
mmi_ret mmi_da_download_options_proc(mmi_event_struct *evt)
{
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;

            /* 3. Retrieve no of child of menu item to be displayed */
            nNumofItem = GetNumOfChild_Ext(MENU_ID_DA_OMA_DL_OPTION);

            MMI_ASSERT(nNumofItem == 2);
            /* 4. Get attribute of menu to be displayed */

            /* 5. Retrieve string ids in sequence of given menu item to be displayed */
            GetSequenceStringIds_Ext(MENU_ID_DA_OMA_DL_OPTION, nStrItemList);

            /* 6 Set current parent id */
            //SetParentHandler(MENU_ID_DA_OMA_DL_OPTION);
#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
            ShowCategory52Screen(
                STR_GLOBAL_OPTIONS,
                mmi_da_job_get_title_icon(srv_da_oma_get_current_job()),
                STR_GLOBAL_OK,
                0,
                STR_GLOBAL_CANCEL,
                0,
                nNumofItem,
                nStrItemList,
                (PU16) gIndexIconsImageList,
                NULL,
                0, 0,
                p->gui_buffer);

            /* 9.Register function with right softkey */
            //SetRightSoftkeyFunction(mmi_da_oma_download_options_cancel, KEY_EVENT_UP);
            //SetKeyHandler(mmi_da_oma_download_options_cancel, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            //SetDelScrnIDCallbackHandler(SCR_ID_DA_OMA_DOWNLOAD_OPTION, mmi_da_oma_delete_download_option);
            mmi_da_update_del_download_option(MMI_TRUE);
            break;
        }
        case EVT_ID_SCRN_GET_CURR_PARENT_ID:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            cat_evt->parent_id = MENU_ID_DA_OMA_DL_OPTION;
            break;
        }
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            g_mmi_da_highlighted_index = cat_evt->item_index;
            break;
            //return MMI_RET_CHANGED;
        }        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            if(g_mmi_da_highlighted_index == 0)
                srv_da_oma_select_storage(srv_da_oma_get_current_job());
            else if(g_mmi_da_highlighted_index == 1)
                mmi_da_oma_entry_download_view_dd();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_da_oma_download_options_cancel();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_GOBACK:
        {
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            if(mmi_da_get_delete_download_option())
            {
                mmi_da_oma_delete_download_option();
                mmi_da_update_del_download_option(MMI_FALSE);
            }
        }
        break;
        case EVT_ID_SCRN_DEINIT:
        {
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* #if defined (__MMI_OMA_DD_DOWNLOAD__) */
void mmi_da_app_show_job_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO proc
    //if(!IsScreenPresent(SCR_ID_DA_JOB_LIST))
    //TODO if(!mmi_frm_scrn_is_present(MMI_DA_DOWNLOAD_LIST_GROUP, SCR_ID_DA_JOB_LIST, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))    
    if(!mmi_frm_group_is_present(MMI_DA_DOWNLOAD_LIST_GROUP))
    {
        mmi_frm_scrn_create(MMI_DA_CONFIRM_SCREEN_GROUP,SCR_ID_DA_JOB_DETAIL,mmi_da_job_details_proc, NULL);
    }
    else
    {      
        mmi_frm_scrn_create(MMI_DA_DOWNLOAD_LIST_GROUP,SCR_ID_DA_JOB_DETAIL,mmi_da_job_details_proc, NULL);
    }
    
}
#if defined (__MMI_OMA_DD_DOWNLOAD__)
void mmi_da_oma_entry_download_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(MMI_DA_CONFIRM_SCREEN_GROUP,SCR_ID_DA_OMA_DOWNLOAD_OPTION,mmi_da_download_options_proc, NULL);
    /* 1 Call Exit Handler */
    //EntryNewScreen(SCR_ID_DA_OMA_DOWNLOAD_OPTION, NULL, mmi_da_oma_entry_download_option, NULL);
}
#endif 
mmi_ret mmi_da_full_scrn_popup_hdlr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_full_screen_popup_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    cntx = g_mmi_da_scr_full_screen_popup_cntx;
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;
#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
            ShowCategory74Screen(
                cntx->title_string_id,
                cntx->title_icon_id,
                STR_GLOBAL_OK,
                0,
                0,
                0,
                (U8*)cntx->content,
                (mmi_wcslen(cntx->content) + 1) * sizeof(U16),
                NULL);
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            mmi_da_scr_full_screen_popup_ok_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            break;
        }
        case EVT_ID_SCRN_GOBACK:
        {
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            mmi_da_scr_delete_full_screen_popup(NULL);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_da_scr_full_screen_popup_free_context();
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_entry_full_screen_popup
 * DESCRIPTION
 *  Ok key handler. Free context and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_scr_entry_full_screen_popup(void)
{
    mmi_frm_scrn_create(MMI_DA_BRW_ENTRY_SCREEN_GROUP, SCR_ID_DA_FULL_SCREEN_POPUP, mmi_da_full_scrn_popup_hdlr_proc, NULL);
    //EntryNewScreen(SCR_ID_DA_FULL_SCREEN_POPUP, NULL, mmi_da_scr_entry_full_screen_popup, NULL);
}
//TODO
extern void mmi_da_job_dispatch_to_app(void);
extern void mmi_da_job_cancel_dispatch(void);
extern U8 mmi_da_dispatch_confirm_delete_callback(void *in_param);
extern void mmi_da_dispatch_confirm_remove_screen(void *unused);

mmi_ret mmi_da_app_dispatch_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    U8 *guiBuffer;
    U8 *text_buffer;
    U16 *text_buffer_in_U16;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p=
            (mmi_frm_scrn_active_evt_struct *)evt;

            job = srv_da_get_curr_job();

            //SetDelScrnIDCallbackHandler(SCR_ID_DA_JOB_CALLBACK_CONFIRM, (HistoryDelCBPtr) mmi_da_dispatch_confirm_delete_callback);
            mmi_da_update_dispatch_confirm_del(MMI_TRUE);
            if (job == NULL)
            {
                srv_da_util_trigger_proc(mmi_da_dispatch_confirm_remove_screen, NULL);
                return MMI_RET_OK;
            }

            text_buffer = (U8*)subMenuData;
            text_buffer_in_U16 = (U16*)(((U32)text_buffer + 1) & ~0x1); /* Align to U16 */

            job->op->get_name(job, text_buffer_in_U16, SRV_FMGR_PATH_MAX_LEN + 1);
            
        #ifndef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
            mmi_wcscat(text_buffer_in_U16, (U16*)get_string(STR_ID_DA_READY_FOR_USE_ASK_SUFFIX));
        #else
            if (job->saved_to_my_fav == MMI_TRUE)
            {
                mmi_wcscat(text_buffer_in_U16, (U16*)get_string(STR_ID_DA_READY_FOR_USE_ASK_SUFFIX));
            }
            else
            {
                mmi_wcscat(text_buffer_in_U16, (U16*)get_string(STR_ID_DA_READY_FOR_USE_ASK_SUFFIX_EXT));
            }
        #endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
            ShowCategory74Screen(
                STR_ID_DA_JOB_USE,
                mmi_da_job_get_title_icon(job),
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (U8*)text_buffer_in_U16,
                (mmi_wcslen(text_buffer_in_U16) + 1) * sizeof(U16),
                p->gui_buffer);
                break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:

        case EVT_ID_WGUI_CSK_CLICK:

        {
            mmi_da_job_dispatch_to_app();
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_da_job_cancel_dispatch(); 
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_GOBACK:
        {
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            if(mmi_da_get_dispatch_confirm_del())
                mmi_da_dispatch_confirm_delete_callback(NULL);
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
 *  mmi_da_curr_job_entry_dispatch_confirm
 * DESCRIPTION
 *  Entry function of dispatch confirm for g_mmi_da_context.curr_job.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_curr_job_entry_dispatch_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    U8 *guiBuffer;
    U8 *text_buffer;
    U16 *text_buffer_in_U16;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

    mmi_frm_scrn_create(mmi_da_get_active_scrn_grp(), SCR_ID_DA_JOB_CALLBACK_CONFIRM, mmi_da_app_dispatch_confirm_proc, NULL);

    //EntryNewScreen(SCR_ID_DA_JOB_CALLBACK_CONFIRM, NULL, mmi_da_curr_job_entry_dispatch_confirm, NULL);
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
#ifndef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__ */
#ifndef __MMI_WGUI_DISABLE_CSK__
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
#endif //0
}
//TODO
#ifndef MMI_DA_PLUTO_SLIM
extern const cui_inline_struct *mmi_da_scr_auth_get_inline_param(void);
/*************************************************************************
* FUNCTION
*  mmi_da_scr_entry_auth
* DESCRIPTION
*  enter auth screen and enter inline editor
* PARAMETERS
* RETURNS
*************************************************************************/
static void mmi_da_scr_entry_auth(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_list[4];
    const cui_inline_struct *inline_param;
    mmi_da_auth_edit_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_da_auth_edit_struct*)mmi_frm_group_get_user_data(group_id);
    
    inline_param = mmi_da_scr_auth_get_inline_param();
    context->inline_cui_id = cui_inline_create(context->grp_id, inline_param);
    
    cui_inline_set_title_icon(context->inline_cui_id, context->icon_id);
    
    icon_list[0] = gIndexIconsImageList[0];
    icon_list[1] = 0;
    icon_list[2] = gIndexIconsImageList[1];
    icon_list[3] = 0;
    cui_inline_set_icon_list(context->inline_cui_id, icon_list);

	cui_inline_set_softkey_icon(
        context->inline_cui_id, 
		MMI_DA_AUTH_USERNAME_EDITOR, 
		MMI_CENTER_SOFTKEY, 
		IMG_GLOBAL_COMMON_CSK);

	cui_inline_set_softkey_icon(
        context->inline_cui_id, 
		MMI_DA_AUTH_PASSWARD_EDITOR, 
		MMI_CENTER_SOFTKEY, 
		IMG_GLOBAL_COMMON_CSK);

    cui_inline_run(context->inline_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_auth_grp_proc
 * DESCRIPTION
 *  proc function of da auth screen
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_da_auth_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_auth_edit_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_da_auth_edit_struct*)evt->user_data;
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_da_auth_on_user_submitted(context);
            break;
            
        case EVT_ID_CUI_INLINE_ABORT:
            context->closed_by_user = MMI_TRUE;
            cui_inline_close(context->inline_cui_id);
            if (context->callback != NULL)
            {
                context->callback(context->user_data, NULL, NULL, MMI_FALSE);
                context->callback = NULL; 
            }
            mmi_frm_group_close(context->grp_id);
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            if (!context->closed_by_user && /* close by framework */
                context->callback != NULL)  
            {
                context->callback(context->user_data, NULL, NULL, MMI_TRUE);
                context->callback = NULL;
            }
            break;
            
        case EVT_ID_GROUP_DEINIT:
            OslMfree(context);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_send_confirm_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_da_scr_auth_send_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *result_evt;
    mmi_da_auth_edit_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We assume that the confirm will not create another group */

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        result_evt = (mmi_alert_result_evt_struct*)evt;

        if (result_evt->result == MMI_ALERT_CNFM_YES)
        {
            context = (mmi_da_auth_edit_struct*)result_evt->user_tag;
        
            MMI_ASSERT(context->callback != NULL);
            context->callback(
                        context->user_data,
                        context->username,
                        context->password,
                        MMI_FALSE);
            context->callback = NULL;

            context->closed_by_user = MMI_TRUE;
            
            cui_inline_close(context->inline_cui_id);
            mmi_frm_group_close(context->grp_id);
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_show_confirm
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_scr_auth_show_confirm(mmi_da_auth_edit_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->username[0] == L'\0') /* Empty string */
    {
        mmi_da_app_show_popup_ext(STR_DA_EMPTY_USERNAME, SRV_DA_POPUP_TYPE_ERROR);
    }
    else
    {
        mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
        confirm_arg.callback = mmi_da_scr_auth_send_confirm_proc;
        confirm_arg.user_tag = (void*)context;
        mmi_confirm_display(
            get_string(STR_ID_DA_POPUP_SEND_ASK),
            MMI_EVENT_QUERY,
            &confirm_arg);
    }
}
#endif
#ifndef MMI_DA_PLUTO_SLIM
/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_da_scr_user_auth(mmi_da_scr_auth_callback_type callback, U32 user_data, U16 title_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_auth_edit_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(callback != NULL);
    
    context = (mmi_da_auth_edit_struct*)OslMalloc(sizeof(mmi_da_auth_edit_struct));
    memset(context, 0, sizeof(mmi_da_auth_edit_struct));

    context->callback = callback;
    context->user_data = user_data;
    context->icon_id = title_icon_id;
    context->grp_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_da_auth_grp_proc, context, MMI_FRM_NODE_NONE_FLAG);

    mmi_da_scr_entry_auth(context->grp_id);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_trigger_when_enter_trigger_proc_hdlr
 * DESCRIPTION
 *  Trigger handler. This function will check whether active screen is
 *  the dummy screen. If yes, calls client's procedure and remove the dymmy screen.
 * PARAMETERS
 *  arg     [IN] (mmi_da_scr_trigger_when_enter_instance_struct*)
 * RETURNS
 *  MMI_TRUE(Can not be deleted)
 *****************************************************************************/
static void mmi_da_scr_trigger_when_enter_trigger_proc_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    top_dummy = (mmi_da_scr_trigger_when_enter_inst_struct*)arg;

    if (mmi_frm_scrn_get_active_id() == top_dummy->screen_id)
    {
        //ClearDelScrnIDCallbackHandler(top_dummy->screen_id, mmi_da_scr_trigger_when_enter_delete_dummy);
        mmi_da_update_need_to_del_dummy(MMI_FALSE);
    
        top_dummy->func(top_dummy->arg);

        mmi_da_scr_remove_screen(top_dummy->screen_id);
        mmi_da_scr_trigger_when_enter_free_instance(top_dummy);
    }
    else
    {
        /*
         * Be interrupted again, do nothing.
         * When the dummy screen rises again, this function will be triggered again.
         */
    }
}

mmi_ret mmi_da_app_trigger_when_enter_proc(mmi_event_struct *evt)
{
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            top_dummy = g_mmi_da_scr_trigger_when_enter_cntx.top_dummy;
            srv_da_util_trigger_proc(mmi_da_scr_trigger_when_enter_trigger_proc_hdlr, top_dummy);
        }
        break;
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:       
        {
            if(mmi_da_get_need_to_del_dummy())
                mmi_da_scr_trigger_when_enter_delete_dummy(NULL);
        }
        break;
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
 *  mmi_da_scr_trigger_when_enter_entry_dummy
 * DESCRIPTION
 *  Entry function of dummy screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_scr_trigger_when_enter_entry_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_scr_trigger_when_enter_inst_struct *top_dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    top_dummy = g_mmi_da_scr_trigger_when_enter_cntx.top_dummy;
    mmi_frm_scrn_create(mmi_da_get_active_scrn_grp() , top_dummy->screen_id,
        mmi_da_app_trigger_when_enter_proc, NULL);    
}

#endif /*__MMI_DOWNLOAD_AGENT__ */
