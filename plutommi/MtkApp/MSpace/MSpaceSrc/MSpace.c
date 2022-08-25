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
 *   MApp.c
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
#include "USBSrvGProt.h"
#include "MenuCuiGprot.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "MMI_mre_trc.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
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
#include "liblist.h"

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
mmi_mspace_ms_struct g_mspace_cntx;

extern void mmi_mspace_as_lis_update(void);

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Extern Function
*****************************************************************************/


static void mmi_mre_enter_mspace(void)
{
	// read local lis file
	mmi_mspace_as_init();

	/* enter Main Screen */
	if (mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_MAIN, MMI_FRM_NODE_ALL_FLAG))
	{
		mmi_frm_scrn_close_active_id();
	}
	else
	{
		mmi_mspace_entry_main_scrn();
	}

	// connect to server to update
	mmi_mspace_as_update();
}

static void mmi_mspace_entry_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* start mspace from main menu */
    mmi_mre_enter_mspace();

    return;
}


mmi_ret mmi_mspace_option_menu_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    menu_evt = (cui_menu_event_struct *)evt;

    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_OPTION_MENU_S, evt->evt_id, menu_evt->highlighted_menu_id);

    switch (evt->evt_id)
    {
    	case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MSPACE_OPTION_TO_UPDATE_DETAILS:					
                    mmi_mspace_os_app_open();
                    break;
				case MENU_ID_MSPACE_OPTION_TO_UPDATE_UPDATE:
                    mmi_mspace_os_app_update();
					break;
				case MENU_ID_MSPACE_OPTION_TO_INSTALL_DETAILS:
                    mmi_mspace_os_app_open();
					break;
				case MENU_ID_MSPACE_OPTION_TO_INSTALL_INSTALL:
                    mmi_mspace_os_app_install();
					break;
				case MENU_ID_MSPACE_OPTION_TO_DETAILS_DETAILS:
                    mmi_mspace_os_app_open();
					break;
                default:
                    break;
            }
            break;
			
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
			break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            break;
		default:
			break;
    }
    return MMI_RET_OK;
}

static void mmi_mspace_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init context struct */
    memset(&g_mspace_cntx, 0, sizeof(g_mspace_cntx));
	g_mspace_cntx.cur_as_status = E_MSPACE_AS_NONE;
	g_mspace_cntx.hl_idx = -1;

}

static mmi_ret mmi_mspace_grp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	// cancal if updating lis
	if (g_mspace_cntx.cur_as_lis_hdl > 0)
	{
		ret = srv_as_data_cancel(g_mspace_cntx.cur_as_lis_hdl); 
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ADSR_CANCEL_S, g_mspace_cntx.cur_as_lis_hdl, ret);
		g_mspace_cntx.cur_as_lis_hdl = 0;
	}

    /* release list */
	mmi_mspace_as_free_list();

    /* Delete ADM */
    if (g_mspace_cntx.adm_pool_id)
    {
        ret = kal_adm_delete(g_mspace_cntx.adm_pool_id);

        MMI_ASSERT(ret == KAL_SUCCESS);
        g_mspace_cntx.adm_pool_id = NULL;
    }

    /* release dynamic memory */
    if (g_mspace_cntx.dyn_mem_pool != NULL)
    {
        applib_mem_ap_free(g_mspace_cntx.dyn_mem_pool);
        g_mspace_cntx.dyn_mem_pool = NULL;
    }

	srv_as_list_deinit();

    /* deinit MSPACE context */
    mmi_mspace_cntx_init();


	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}	

	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
	}	

	return MMI_RET_OK;
}

static mmi_ret mmi_msapce_grp_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_RET_OK;
}

static mmi_ret mmi_mspace_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GROUP_PROC_EVT_S, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            ret = mmi_msapce_grp_active();
            break;
        case EVT_ID_GROUP_DEINIT:
            ret = mmi_mspace_grp_deinit();
            break;

        /************************* Menu CUI event *****************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
			break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
			break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
			break;
			
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
			ret = mmi_mspace_option_menu_handler(evt);
			break;
			
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:			
			cui_menu_close(g_mspace_cntx.option_gid);
			g_mspace_cntx.option_gid = 0;
			break;
        case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE:
            break;
		default:
			break;
    }

    return ret;
}


static void mmi_mspace_asm_stop_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ASM_STOP_CB_S);

    mmi_frm_group_close(GRP_ID_MSPACE);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MSPACE, KAL_TRUE);

    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ASM_STOP_CB_E);
}

static void mmi_mspace_alloc_mem_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ALLOC_MEM_CB_S, g_mspace_cntx.dyn_mem_pool);

    mmi_mspace_start();

    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ALLOC_MEM_CB_E, g_mspace_cntx.dyn_mem_pool);
}


static MMI_BOOL mmi_mspace_start_int(void)
{

    /* Init MSPACE context */
    mmi_mspace_cntx_init();

	applib_mem_ap_register(APPLIB_MEM_AP_ID_MSPACE, STR_ID_MSPACE_NAME, IMG_ID_MSPACE_MAIN_MENU_ICON, mmi_mspace_asm_stop_cb);
	
	/* allocate memory */
	if (g_mspace_cntx.dyn_mem_pool == NULL)
	{
        g_mspace_cntx.dyn_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MSPACE, MMI_MSPACE_MAX_DYN_MEM_SIZE);
		if (g_mspace_cntx.dyn_mem_pool == NULL)
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ALLOCATE_MEM_FAIL);
	
			/* register callback */
			mmi_frm_appmem_prompt_to_release_mem(
				APPLIB_MEM_AP_ID_MSPACE,
				0,
				MMI_MSPACE_MAX_DYN_MEM_SIZE,
				mmi_mspace_alloc_mem_cb);
		
			return MMI_FALSE;
		}
		else
		{
			/* Create ADM */
			g_mspace_cntx.adm_pool_id = kal_adm_create(
											(void*)g_mspace_cntx.dyn_mem_pool,
											MMI_MSPACE_MAX_DYN_MEM_SIZE,
											NULL,
											KAL_TRUE);
			MMI_ASSERT(g_mspace_cntx.adm_pool_id != NULL);
		}
	}

    return MMI_TRUE;
}


void mmi_mspace_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_START_S);

    if (mmi_frm_group_is_present(GRP_ID_MSPACE))
    {
        mmi_frm_group_close(GRP_ID_MSPACE);
    }

#ifdef __MMI_USB_SUPPORT__
		/* is in storage mode */
		if (srv_usb_is_in_mass_storage_mode())
		{
			/* phone drive is exported, can't use this app */
			mmi_usb_app_unavailable_popup(0);	/* pass 0 will show default string */
			//MMI_TRACE;
			return;
		}
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* enter screen group */
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MSPACE, mmi_mspace_grp_proc, NULL);
    mmi_frm_group_enter(GRP_ID_MSPACE, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);

    /* MSpace init */
    if (!mmi_mspace_start_int())
    {
        mmi_frm_group_close(GRP_ID_MSPACE);
    }
    else
    {
        /* enter loading screen */
        mmi_mspace_entry_loading_scrn();
    }

}

static void mmi_mspace_card_plug_in_hdlr(void)
{
	srv_as_list_deinit();
	srv_as_list_init();
	mmi_mspace_as_lis_update();
}

static void mmi_mspace_card_plug_out_hdlr(void)
{
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_APP_MAIN, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_APP_MAIN);		
	}
	
	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_WAITING);		
	}	

	if ( MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING, MMI_FRM_NODE_ALL_FLAG) )
	{
		mmi_frm_scrn_close(GRP_ID_MSPACE, SCR_ID_MSPACE_DOWNLOADING);		
	}	

        //mmi_mspace_as_lis_update();
        if (g_mspace_cntx.cur_as_app_hdl > 0)
        {
            srv_as_data_cancel(g_mspace_cntx.cur_as_app_hdl);
            g_mspace_cntx.cur_as_app_hdl = 0;
        }
	mmi_mspace_as_free_list();
	g_mspace_cntx.app_num = 0;
}

mmi_ret mmi_mspace_fmgr_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mspace_cntx.adm_pool_id)
    {
        switch (param->evt_id)
        {
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
                mmi_mspace_card_plug_out_hdlr();
                break;
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
                mmi_mspace_card_plug_in_hdlr();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}

mmi_ret mmi_mspace_enter_usb_mode_ms_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE;

    if (g_mspace_cntx.adm_pool_id)
    {
    #if defined(__MMI_USB_SUPPORT__)
        if (srv_usb_is_in_mass_storage_mode())
        {
            mmi_frm_group_close(GRP_ID_MSPACE);
            //MMI_TRACE;
        }
    #endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    }

    //MMI_TRACE;
    return MMI_RET_OK;
}


void HighlightMSpace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_mspace_start, KEY_EVENT_UP);
	ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_mspace_start,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


mmi_ret mmi_mspace_srv_appmgr_install_package_callback(mmi_event_struct *evt)
{
    if (g_mspace_cntx.adm_pool_id)
    {
	    mmi_mspace_as_update_app_item();
    }
    
    return MMI_RET_OK;
}

mmi_ret mmi_mspace_srv_appmgr_update_install_package_callback(mmi_event_struct *evt)
{
    if (g_mspace_cntx.adm_pool_id)
    {
	    mmi_mspace_as_update_app_item();
    }
    
    return MMI_RET_OK;
}


#endif /* __MMI_MRE_MSPACE__ */ 

