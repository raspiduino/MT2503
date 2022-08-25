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

/*******************************************************************************
 * Filename:
 * ---------
 * UMInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMGProt.h"
#include "UMDefs.h"
#include "UMProt.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "UcAppGprot.h"
#include "SmsAppGProt.h"
#include "smscuigprot.h"

/* Notification Manager */
#include "IdleNotificationManagerGprot.h"
/* Tone profile */
#include "ProfilesSrvGprot.h"

/* For no-SIM, filght mode checking */

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "UmSrvGprot.h"
#include "UmSrvDefs.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "Custom_ProvBox.h"
#include "custom_wap_config.h"
#include "stdio.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_common_app_trc.h"
#include "NwUsabSrvGprot.h"
#include "UcCuiGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "SmsUmBtMapGProt.h"
#endif /*__MMI_BT_MAP_CLIENT__*/


#include "mmi_rp_app_unifiedmessage_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "Mmi_rp_app_mainmenu_def.h"
#include "umncentergprot.h"
#endif
#include "mmi_rp_srv_status_icons_def.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "mmi_frm_mem_gprot.h"
#ifndef __MMI_SUPPORT_ASMV2__
#include "app_mem.h"
#endif
static MMI_RET mmi_um_app_proc(mmi_event_struct *evt);
static mmi_event_notify_enum event_type_new=MMI_EVENT_SMS;
static mmi_event_notify_enum event_type_old=MMI_EVENT_SMS;
#if (defined (__MMI_MAINLCD_96X64__)|| defined(__MMI_UM_ULTRA_SLIM__))
MMI_BOOL g_is_launch_from_nav_key=MMI_TRUE;
#endif
#ifdef __MMI_BT_MAP_CLIENT__
MMI_BOOL g_um_is_entry_main_menu = MMI_FALSE;
MMI_BOOL g_um_is_new_group = MMI_FALSE;
extern mmi_um_tab_page g_tab_last_enter;
#endif /* __MMI_BT_MAP_CLIENT__ */

#ifdef __MMI_BT_MAP_CLIENT__
extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;  
#endif /*__MMI_BT_MAP_CLIENT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_new_msg_ind
 * DESCRIPTION
 *  entry new msg
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_new_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_main_message_menu_int
 * DESCRIPTION
 *  A entry function for external entry main message menu.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_main_message_menu_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
 #ifdef __MMI_BT_MAP_CLIENT__ 
     mmi_um_ui_init();
     srv_um_cache_init();
     srv_um_listmgr_init();
     srv_sms_um_listmgr_init();
 #endif
#ifdef __MMI_SUPPORT_ASMV2__
     scrn_id = mmi_um_ui_if_entry_general(0, APP_UNIFIEDMESSAGE, MMI_TRUE, MMI_UM_ENTRY_SCREEN_MAIN_MENU, NULL);
#else
	 scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_MAIN_MENU, NULL);
#endif
#ifdef __MMI_BT_MAP_CLIENT__    
     g_sms_um_ui_main_menu_scrn_id = scrn_id;
#endif


    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


#if (BT_MAX_LINK_NUM > 1)
extern srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */
void mmi_um_entry_main_message_dev_ext(void)
{
#ifdef __MMI_BT_MAP_CLIENT__
        mmi_sms_bt_app_init();
#endif /* __MMI_BT_MAP_CLIENT__ */

#ifdef __MMI_SUPPORT_ASMV2__
    mmi_frm_app_launch(APP_UNIFIEDMESSAGE, 0, 0, mmi_um_app_proc, (void *)'MMSG', 0);
#else
	mmi_um_entry_main_message_menu_int();
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_show_dev_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_um_ui_sh_main_show_dev_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i,j;
	srv_bt_cm_bt_addr dev_addr;
	const srv_bt_cm_dev_struct* dev_info = NULL;
	S32 ret = SRV_BT_MAPC_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    kal_wsprintf((WCHAR*)menu_data[0].item_list[0], "Local");
    menu_data[0].image_list[0] = (PU8)mmi_bt_get_device_image(NULL);
    for (i = 1; i < num_item; i++)
	#else
    for (i = 0; i < num_item; i++)
	#endif
    {
        #ifdef __MTK_TARGET__
		ret = srv_bt_mapc_get_bt_addr_by_idx(&dev_addr, i);
		#else
        ret = SRV_BT_MAPC_FAIL_NOT_FOUND;
        #endif		
        if(ret == SRV_BT_MAPC_SUCCESS)	
        {
			dev_info = srv_bt_cm_get_dev_info_by_addr(&dev_addr, SRV_BT_CM_ALL_DEV);
        if (dev_info != NULL)
        {            
            srv_bt_cm_get_dev_ucs2_name(
                &dev_info->bd_addr,
                SRV_BT_CM_BD_UCS2_NAME_LEN,
                menu_data[i].item_list[0]);
                menu_data[i].image_list[0] = NULL;//(PU8)mmi_bt_get_device_image(dev_info->cod);
        }
        else
        {
            kal_wsprintf((WCHAR*)menu_data[i].item_list[0], "BT%d", i + 1);
                menu_data[i].image_list[0] = NULL;//(PU8)mmi_bt_get_device_image(NULL);
            }
        }
        else
        {
            kal_wsprintf((WCHAR*)menu_data[i].item_list[0], "BT%d", i + 1);
            menu_data[i].image_list[0] = NULL;//(PU8)mmi_bt_get_device_image(NULL);
        }

        for(j = 0; j < 10; j++)
        {
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_um_ui_sh_main_show_dev_list_get_item_async menu_data[i].item_list[0] = %x", menu_data[i].item_list[0][j]);
        }
		
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_um_ui_sh_main_show_dev_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_active_dev_index = index;
}

void mmi_um_ui_sh_main_show_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlighted_item = 0;
#if (BT_MAX_LINK_NUM > 1)
    #ifdef __MMI_TELEPHONY_SUPPORT__	
    S32 total = BT_MAX_LINK_NUM + 1;
    #else
    S32 total = BT_MAX_LINK_NUM;
    #endif
#endif	
    S32 cat_err = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (guiBuffer != NULL)
    {
        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
        g_sms_active_dev_index = hist->highlighted_item;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_um_ui_sh_main_show_dev_list_highlight_hdlr);

    #ifdef __MMI_BT_DIALER_SUPPORT__
    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    #endif

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);    
    wgui_cat1032_show(
        get_string(MAIN_MENU_MESSAGES_TEXT),
        NULL,
        get_string(STR_GLOBAL_OK),
        get_image(IMG_GLOBAL_OK),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        total,
        mmi_um_ui_sh_main_show_dev_list_get_item_async,
        NULL,
        highlighted_item,
        0,    
        0, /* to calculate the coordinate offset of string */
        0,
        guiBuffer,
        &cat_err);
    wgui_restore_list_menu_slim_style();

    /* register LSK, RSK hanlders */

    SetLeftSoftkeyFunction(mmi_um_entry_main_message_dev_ext, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_um_entry_main_message_dev_ext, KEY_EVENT_UP);	
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);  
	
}


mmi_ret mmi_um_ui_sh_main_dev_list_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_um_ui_sh_main_show_dev_list();
            break;

        case EVT_ID_SCRN_GOBACK:
            break;

        case EVT_ID_SCRN_DEINIT:
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

void mmi_um_entry_main_message_dev_list_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opt_grp_id = mmi_frm_group_create_ex(GRP_ID_ROOT,
        GRP_ID_AUTO_GEN,
        mmi_um_ui_sh_main_dev_list_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(opt_grp_id, 
        GRP_ID_AUTO_GEN, 
        mmi_um_ui_sh_main_dev_list_proc,
        NULL);
}
#endif /* (BT_MAX_LINK_NUM > 1) */	

void mmi_um_entry_main_message_menu(void)
{
#if (BT_MAX_LINK_NUM > 1)
    mmi_um_entry_main_message_dev_list_menu();
#else
#ifdef __MMI_BT_MAP_CLIENT__
        mmi_sms_bt_app_init();
#endif /* __MMI_BT_MAP_CLIENT__ */

#ifdef __MMI_SUPPORT_ASMV2__
    mmi_frm_app_launch(APP_UNIFIEDMESSAGE, 0, 0, mmi_um_app_proc, (void *)'MMSG', 0);
#else
	mmi_um_entry_main_message_menu_int();
#endif
#endif
}

#ifdef __MMI_UM_ULTRA_SLIM__
MMI_BOOL mmi_um_entry_box_with_check(void)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Check re-entry state */
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return MMI_FALSE;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return MMI_FALSE;
        }
    }
	return MMI_TRUE;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_main_message_menu_with_check
 * DESCRIPTION
 *  A entry function for external entry main message menu with checking 
 *  re-entry ability.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_main_message_menu_with_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Check re-entry state */
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return;
        }
    }
#else
	if (MMI_TRUE != mmi_um_entry_box_with_check())
	{
		mmi_um_current_not_avaiable_popup();
		return;
	}
#endif
#ifdef __MMI_SUPPORT_ASMV2__
    mmi_frm_app_launch(APP_UNIFIEDMESSAGE, 0, 0, mmi_um_app_proc, (void *)'MMSG', 0);
#else
	mmi_um_entry_main_message_menu_int();
#endif
    //mmi_um_entry_main_message_menu();
    return;
}



#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_simbox
 * DESCRIPTION
 *  Old function for entry simbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_simbox_with_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check re-entry state */
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return;
        }
    }
    mmi_um_pre_entry_simbox();
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_main_message_menu_update_by_app
 * DESCRIPTION
 *  Message ap could call this funciton to update the main menu screen by 
 *  menu item id and the updated string.
 *
 * PARAMETERS
 *  user_data:          [IN]    UM's user data
 *  menu_item_id:       [IN]    Menu item id
 *  update_string:      [IN]    Updated string
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_main_message_menu_update_by_app(void *user_data, U16 menu_item_id, U8 *update_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call screen handler to update main message screen */
    mmi_um_ui_sh_main_message_update_by_app(menu_item_id, update_string, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_write_msg
 * DESCRIPTION
 *  A entry function for external entry write message menu.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_WRITE_MESSAGE, NULL);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_write_msg_ext
 * DESCRIPTION
 *  A entry function for external entry write message menu extension version.
 *      It contains the UC/Postcard/Non-UC/Standalone_UC
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_write_msg_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If open SMS+MMS, it should open UC or selection screen */
#ifdef __MMI_MMS_IN_UM__
    #ifdef __MMI_UNIFIED_COMPOSER__
        cui_uc_write_msg_launch(GRP_ID_ROOT);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_um_entry_write_msg();
    #endif /* __MMI_UNIFIED_COMPOSER__ */
#else
    /* entry SMS editor */
    mmi_msg_pre_entry_write_new_msg();
#endif /* __MMI_UNIFIED_COMPOSER__ */
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_inbox
 * DESCRIPTION
 *  A entry function for external entry conversation box
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_conversation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    scrn_id = mmi_um_ui_if_entry_conversation_box(0, APP_UNIFIEDMESSAGE, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */

#ifdef __MMI_UM_ULTRA_SLIM__
void mmi_um_entry_box(srv_um_msg_box_enum box_type)
{
    U16 scrn_id;
    srv_um_box_identity_struct folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined (__MMI_MAINLCD_96X64__)|| defined(__MMI_UM_ULTRA_SLIM__))
	if(MMI_FALSE==mmi_um_entry_box_with_check())
	{
		mmi_um_current_not_avaiable_popup();
		return;
	}
#endif
    folder.msg_box_type = box_type;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
#if (defined (__MMI_MAINLCD_96X64__)|| defined(__MMI_UM_ULTRA_SLIM__))
	if(g_is_launch_from_nav_key==MMI_TRUE)
		scrn_id = mmi_um_ui_if_entry_general(0,GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);
	else
	{
#endif
#ifdef __MMI_SUPPORT_ASMV2__
    scrn_id = mmi_um_ui_if_entry_general(0, APP_UNIFIEDMESSAGE, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);
#else
	scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);
#endif
#if (defined (__MMI_MAINLCD_96X64__)|| defined(__MMI_UM_ULTRA_SLIM__))
		g_is_launch_from_nav_key=MMI_TRUE;
	}
#endif
#ifdef __MMI_BT_MAP_CLIENT__
        g_um_is_new_group = MMI_TRUE;
#endif /* __MMI_BT_MAP_CLIENT__ */

    mmi_um_ui_ut_send_init_event(scrn_id);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_inbox
 * DESCRIPTION
 *  A entry function for external entry inbox
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_INBOX;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, APP_UNIFIEDMESSAGE, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
#ifdef __MMI_BT_MAP_CLIENT__
    g_um_is_new_group = MMI_TRUE;
#endif /* __MMI_BT_MAP_CLIENT__ */
#else
    #ifdef __MMI_BT_MAP_CLIENT__
    g_tab_last_enter = MMI_UM_TAB_PAGE_LOCAL;
    g_sms_um_ui_main_menu_scrn_id = 0;
    mmi_um_ui_init();
    srv_um_cache_init();
    srv_um_listmgr_init();
    #endif
    mmi_um_entry_box(SRV_UM_MSG_BOX_INBOX);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_inbox_with_check
 * DESCRIPTION
 *  A entry function for external entry inbox with checking 
 *  re-entry ability.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_inbox_with_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* Check re-entry state */
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return;
        }
    }
#else
	if (MMI_TRUE != mmi_um_entry_box_with_check())
	{
		mmi_um_current_not_avaiable_popup();
		return;
	}
#endif
#ifdef __MMI_SUPPORT_ASMV2__
    mmi_frm_app_launch(APP_UNIFIEDMESSAGE, 0, 0, mmi_um_app_proc, (void *)'INBX', 0);
#else
#ifdef __MMI_UM_CONVERSATION_BOX__
                    if (MMI_TRUE == mmi_um_check_conversation_box_setting())
                    {
                        mmi_um_entry_conversation();
                    }
                    else
#endif /* __MMI_UM_CONVERSATION_BOX__ */
					{
						mmi_um_entry_inbox();
					}
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_draft
 * DESCRIPTION
 *  A entry function for external entry draft
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_DRAFT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
#else
    mmi_um_entry_box(SRV_UM_MSG_BOX_DRAFT);
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_outbox
 * DESCRIPTION
 *  A entry function for external entry outbox
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_UNSENT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, APP_UNIFIEDMESSAGE, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
#ifdef __MMI_BT_MAP_CLIENT__
    g_um_is_new_group = MMI_TRUE;
#endif /* __MMI_BT_MAP_CLIENT__ */
#else
    mmi_um_entry_box(SRV_UM_MSG_BOX_UNSENT);
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_sent
 * DESCRIPTION
 *  A entry function for external entry sent
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_SENT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
#else
    mmi_um_entry_box(SRV_UM_MSG_BOX_SENT);
#endif
    return;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_archive
 * DESCRIPTION
 *  A entry function for external entry archive
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_ARCHIVE;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_simbox
 * DESCRIPTION
 *  A entry function for external entry simbox
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_SIM;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_report
 * DESCRIPTION
 *  A entry function for external entry report box
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_REPORT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __MMI_UM_REPORT_BOX__ */


#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_delete_folder
 * DESCRIPTION
 *  A entry function for external entry delete folder
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_FALSE, MMI_UM_ENTRY_SCREEN_DELETE_FOLDER, NULL);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */


#ifdef __MMI_UM_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_template
 * DESCRIPTION
 *  A entry function for external entry template
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_TEMPLATE, NULL);
    
    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_setting
 * DESCRIPTION
 *  A entry function for external entry setting
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_SETTING, NULL);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_inbox
 * DESCRIPTION
 *  A entry function for external entry mark several inbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_ms_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_INBOX;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_ms_folder(folder, 0, GRP_ID_ROOT, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_draft
 * DESCRIPTION
 *  A entry function for external entry mark several draft
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_ms_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_DRAFT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_ms_folder(folder, 0, GRP_ID_ROOT, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_outbox
 * DESCRIPTION
 *  A entry function for external entry mark several outbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_ms_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_UNSENT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_ms_folder(folder, 0, GRP_ID_ROOT, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_sent
 * DESCRIPTION
 *  A entry function for external entry mark several sent
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_ms_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_SENT;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_ms_folder(folder, 0, GRP_ID_ROOT, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_archive
 * DESCRIPTION
 *  A entry function for external entry mark several archive
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_ms_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_ARCHIVE;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_ms_folder(folder, 0, GRP_ID_ROOT, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_simbox
 * DESCRIPTION
 *  A entry function for external entry mark several simbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_ms_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_SIM;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_ms_folder(folder, 0, GRP_ID_ROOT, MMI_TRUE);

    mmi_um_ui_ut_send_init_event(scrn_id);
    
    return;
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

typedef MMI_BOOL (*if_event_hdlr)(U16 screen_id, U16 event, void *arg);
U16 mmi_um_ui_if_entry_general(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp, U16 type, void *extend_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    U16 disp_scrn_id = 0;
    mmi_um_ui_aprc_st_enum aprc_type = MMI_UM_UI_SCRN_TYPE_TOTAL;
    if_event_hdlr evt_hdlr =  NULL;
    scrn_init_func init_func = NULL;
    MMI_BOOL result;
#ifdef __MMI_BT_MAP_CLIENT__
    MMI_BOOL is_entry_general_folde = MMI_FALSE;
    MMI_BOOL is_entry_loading = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));
    
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
#ifdef __MMI_BT_MAP_CLIENT__
    g_um_is_entry_main_menu = MMI_FALSE;
#endif /* __MMI_BT_MAP_CLIENT__ */
    switch (type)
    {
        case MMI_UM_ENTRY_SCREEN_MAIN_MENU:
        {
            disp_scrn_id = SCR_ID_UM_MAIN_MESSAGE;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_MAIN_MENU;
            evt_hdlr = mmi_um_ui_sh_main_msg_event_hdlr;
            init_func = mmi_um_ui_sh_main_msg_init;
        #ifdef __MMI_BT_MAP_CLIENT__
            g_um_is_entry_main_menu = MMI_TRUE;
        #endif /* __MMI_BT_MAP_CLIENT__ */
        }
            break;

        case MMI_UM_ENTRY_SCREEN_WRITE_MESSAGE:
        {
            /* Check pending action */
            if (mmi_um_ui_ut_check_all_msg_pending_action())
            {
                mmi_um_current_not_avaiable_popup();
                return 0;
            }
            disp_scrn_id = SCR_ID_UM_WRITE_MSG;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_LIST;
            evt_hdlr = mmi_um_ui_sh_write_msg_event_hdlr;
            init_func = mmi_um_ui_sh_write_msg_init;
        }
            break;

        case MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER:
        {
            /* Check network status */
            if (MMI_FALSE == mmi_um_ui_int_is_available())
            {
                mmi_um_current_not_avaiable_popup();
                return 0;
            }

            /* Check pending action */
            if (mmi_um_ui_ut_check_all_msg_pending_action())
            {
                return 0;
            }
            setting.folder.msg_box_type = ((srv_um_box_identity_struct *)extend_data)->msg_box_type;
            disp_scrn_id = SCR_ID_UM_FOLDER;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_FOLDER;
            evt_hdlr = mmi_um_ui_sh_general_folder_event_hdlr;
            init_func = mmi_um_ui_sh_general_folder_init;
        #ifdef __MMI_BT_MAP_CLIENT__
            is_entry_general_folde = MMI_TRUE;
        #endif /* __MMI_BT_MAP_CLIENT__ */
        }
            break;
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
        case MMI_UM_ENTRY_SCREEN_DELETE_FOLDER:
        {
            /* Check pending action */
            if (mmi_um_ui_ut_check_all_msg_pending_action())
            {
                return 0;
            }
            disp_scrn_id = SCR_ID_UM_DELETE_FOLDER;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_MAIN_MENU;
            /* Set screen handler */
            evt_hdlr = mmi_um_ui_sh_delete_folder_event_hdlr;
            init_func = mmi_um_ui_sh_delete_folder_init;
        }
            break;
#endif
        case MMI_UM_ENTRY_SCREEN_LOADING:
        {
            disp_scrn_id = SCR_ID_UM_PROCESSING;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING;
            /* Set screen handler */
            evt_hdlr = mmi_um_ui_sh_process_event_hdlr;
            init_func = mmi_um_ui_sh_process_init;
        #ifdef __MMI_BT_MAP_CLIENT__
            is_entry_loading = MMI_TRUE;
        #endif
        }
            break;
        case MMI_UM_ENTRY_SCREEN_DELETE_FOLDER_PROCESSING:
        {
            disp_scrn_id = SCR_ID_UM_PROCESSING;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING;
            /* Set screen handler */
        #ifdef __MMI_UM_OP_FSM_SUPPORT__
            evt_hdlr = mmi_um_ui_sh_process_del_folder_event_hdlr;
        #else
            evt_hdlr = mmi_um_ui_sh_process_del_folder_event_hdlr_without_op;
        #endif
            init_func = mmi_um_ui_sh_process_del_folder_init;
            setting.folder.msg_box_type = ((srv_um_box_identity_struct *)extend_data)->msg_box_type;
            setting.folder.msg_type = ((srv_um_box_identity_struct *)extend_data)->msg_type;
            setting.folder.sim_id = ((srv_um_box_identity_struct *)extend_data)->sim_id;

            break;
        }
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
        case MMI_UM_ENTRY_SCREEN_TEMPLATE:
        {
            /* Check pending action */
            if (mmi_um_ui_ut_check_all_msg_pending_action())
            {
                return 0;
            }
            if (MMI_FALSE == mmi_um_ui_int_is_available())
            {
                mmi_um_current_not_avaiable_popup();
                return 0;
            }
            disp_scrn_id = SCR_ID_UM_TEMPLATE;
            aprc_type = MMI_UM_UI_SCRN_TYPE_LIST;
            /* Set screen handler */
            evt_hdlr = mmi_um_ui_sh_template_event_hdlr;
            init_func = mmi_um_ui_sh_template_init;
        }
            break;
#endif

        case MMI_UM_ENTRY_SCREEN_SETTING:
        {
            /* Check pending action */
            if (mmi_um_ui_ut_check_all_msg_pending_action() ||
                (mmi_frm_scrn_is_present(setting.parent_group_id, SCR_ID_UM_SETTING, MMI_FRM_NODE_ALL_FLAG)))
            {
                return 0;
            }
            if (MMI_FALSE == mmi_um_ui_int_is_available())
            {
                mmi_um_current_not_avaiable_popup();
                return 0;
            }
            disp_scrn_id = SCR_ID_UM_SETTING;
            /* Set appearance */
            aprc_type = MMI_UM_UI_SCRN_TYPE_LIST;
            /* Set screen handler */
            evt_hdlr = mmi_um_ui_sh_setting_event_hdlr;
            init_func = mmi_um_ui_sh_setting_init;
        }
            break;

        default:
            break;
    }

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = disp_scrn_id;
    
    /* Set appearance */
    setting.aprc_type = aprc_type;
    
    /* Set screen handler */
    setting.event_hdlr = evt_hdlr;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, init_func);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_MAIN_MESSAGE, setting.scrn_id);
#ifdef __MMI_BT_MAP_CLIENT__
    if (is_entry_general_folde)
        g_um_general_folder_scrn_id = setting.disp_scrn_id;
    if (is_entry_loading)
        g_um_loading_scrn_id = setting.disp_scrn_id;
#endif

    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_write_msg
 * DESCRIPTION
 *  A entry function for write message
 *  If parent screen id = 0, it means there is no any parent.
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_write_msg(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    return mmi_um_ui_if_entry_general(parent_scrn_id,parent_grp_id,new_grp, MMI_UM_ENTRY_SCREEN_WRITE_MESSAGE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_process_delete_folder
 * DESCRIPTION
 *  A entry function to delete folder. This screen contains the operation FSM
 *  to delete the messages in the specified folder
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  folder                  [IN]: Folder type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_process_delete_folder(U16 parent_scrn_id, srv_um_box_identity_struct *folder, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    return mmi_um_ui_if_entry_general(parent_scrn_id,parent_grp_id,new_grp, MMI_UM_ENTRY_SCREEN_DELETE_FOLDER_PROCESSING, folder);
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_process_delete_conversation_box
 * DESCRIPTION
 *  A entry function to delete conversation box. This screen contains the 
 *  operation FSM to delete the messages in the specified folder.
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_process_delete_conversation_box(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_process_delete_folder(parent_scrn_id, &folder, parent_grp_id, new_grp);
    
    return scrn_id;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_setting_cs
 * DESCRIPTION
 *  A entry function for conversation box setting
 *  If parent screen id = 0, it means there is no any parent.
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_setting_cs(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_CONVERSATION_BOX_SETTING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_CONVERSATION_SETTING;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_setting_cs_evt_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_NONE;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_setting_cs_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_SETTING_CS, setting.scrn_id);

    return setting.scrn_id;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_processing
 * DESCRIPTION
 *  A entry function for processing. This screen does not have any finite 
 *  state machine. Only display a processing screen.
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_processing(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    return mmi_um_ui_if_entry_general(parent_scrn_id, parent_grp_id, new_grp, MMI_UM_ENTRY_SCREEN_LOADING, NULL);
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_conversation_box
 * DESCRIPTION
 *  A entry function for conversation box. This screen contains the entry 
 *  folder FSM.
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_conversation_box(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_folder_mode_enum mode;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check network status */
    if (/*srv_nw_usab_get_one_usable_sim() == MMI_SIM_NONE ||*/
        MMI_FALSE == mmi_um_ui_int_is_available())
    {
        mmi_um_current_not_avaiable_popup();
        return 0;
    }

    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_CONVERSATION_BOX;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_CONVERSATION_BOX;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_general_folder_event_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;;
    setting.folder.sim_id = SRV_UM_SIM_ALL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_general_folder_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_CONVERSATION_BOX, setting.scrn_id);

    /* Set the folder mode */
    mode = MMI_UM_FOLDER_MODE_CONVERSATION_BOX;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_FOLDER_MODE, (void *)&mode);    

    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_delete_thrd_msg
 * DESCRIPTION
 *  A entry function for deleting a thread message.
 *  If parent screen id = 0, it means there is no any parent.
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_delete_thrd_msg(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_cs_op_thrd_msg_evt_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;;
    setting.folder.sim_id = SRV_UM_SIM_ALL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_cs_op_thrd_msg_init);
    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_DELETE_THREAD_MSG, setting.scrn_id);

    action = MMI_UM_UI_ACTION_DELETE_THRD_MSG;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_mov2arc_thrd_msg
 * DESCRIPTION
 *  A entry function for moving a thread message into archive
 *  If parent screen id = 0, it means there is no any parent.
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_mov2arc_thrd_msg(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_cs_op_thrd_msg_evt_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;;
    setting.folder.sim_id = SRV_UM_SIM_ALL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_cs_op_thrd_msg_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_MOV2ARC_THREAD_MSG, setting.scrn_id);

    action = MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_thread_msg
 * DESCRIPTION
 *  A entry function for thread message screen.
 *  If parent screen id = 0, it means there is no any parent.
 *  It should also take the thread id into general folder via event
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  list_filter             [IN]: List filter
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_thread_msg(U16 parent_scrn_id, srv_um_list_filter_struct *list_filter, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_folder_mode_enum mode;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pending action */
    if (mmi_um_ui_ut_check_all_msg_pending_action())
    {
        return 0;
    }
    
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_THREAD_MSG;

    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_THRD_MSG;

    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_general_folder_event_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    /* Init by thread message itself */
    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_general_folder_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_THREAD_FOLDER, setting.scrn_id, list_filter->thread_id.type, list_filter->thread_id.value);

    /* Set the folder mode */
    mode = MMI_UM_FOLDER_MODE_THREAD_MSG;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_FOLDER_MODE, (void *)&mode);
    /* Set the thread id */
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_FILTER_TYPE, (void *)list_filter);

    return setting.scrn_id;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_conversation_box
 * DESCRIPTION
 *  A entry function for conversation box of mark several. This screen 
 *  contains the entry folder FSM.
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_conversation_box(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_folder_mode_enum mode;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_MS_CONVERSATION_BOX;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_MS_CONVERSATION_BOX;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_general_event_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = g_um_ui_ms_table_p;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_general_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_MS_CONVERSATION_BOX, setting.scrn_id);

    /* Set the folder mode */
    mode = MMI_UM_FOLDER_MODE_CONVERSATION_BOX;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_FOLDER_MODE, (void *)&mode);    

    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_cs_op_delete
 * DESCRIPTION
 *  A entry function for operation for delete thread message in mark several
 *  If parent screen id = 0, it means there is no any parent.
 *  It should also take the thread id into general folder via event
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  thread_id               [IN]: Thread id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_cs_op_delete(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_cs_op_mov2arc
 * DESCRIPTION
 *  A entry function for operation for move thread message to archive in mark 
 *  several
 *  If parent screen id = 0, it means there is no any parent.
 *  It should also take the thread id into general folder via event
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  thread_id               [IN]: Thread id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_cs_op_mov2arc(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_thread_msg
 * DESCRIPTION
 *  A entry function for thread message screen.
 *  If parent screen id = 0, it means there is no any parent.
 *  It should also take the thread id into general folder via event
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  list_filter             [IN]: List filter
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_thrd_msg(U16 parent_scrn_id, srv_um_list_filter_struct *list_filter, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_folder_mode_enum mode;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pending action */
    if (mmi_um_ui_ut_check_all_msg_pending_action())
    {
        return 0;
    }
    
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_MS_THREAD_MSG;

    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_MS_THRD_MSG;

    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_general_event_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_CONVERSATION;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = g_um_ui_ms_table_p;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    /* Init by thread message itself */
    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_general_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_MS_THREAD_FOLDER, setting.scrn_id, list_filter->thread_id.type, list_filter->thread_id.value);

    /* Set the folder mode */
    mode = MMI_UM_FOLDER_MODE_THREAD_MSG;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_FOLDER_MODE, (void *)&mode);
    /* Set the thread id */
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_FILTER_TYPE, (void *)list_filter);

    return setting.scrn_id;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_CONVERSATION_BOX__ */


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_folder
 * DESCRIPTION
 *  A entry function for external entry mark several folder like inbox, 
 *  draft and so on.
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_folder(srv_um_box_identity_struct folder, U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pending action */
    if (mmi_um_ui_ut_check_all_msg_pending_action())
    {
        return 0;
    }
    
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_MULTI_OP;

    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_MS;

    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_general_event_hdlr;
    setting.folder.msg_box_type = folder.msg_box_type;
    setting.folder.msg_type = folder.msg_type;
    setting.folder.sim_id = folder.sim_id;
    setting.scrn_data = g_um_ui_ms_table_p;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_general_init);

    MMI_ASSERT(result == MMI_TRUE);    

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_MS_FOLDER, setting.scrn_id, setting.folder.msg_box_type, setting.folder.msg_type, setting.folder.sim_id);

    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_op_delete_folder
 * DESCRIPTION
 *  A entry function for mark several delete process screen menu.
 *  (General folder)
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  box_type                [IN]: Message box type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_op_delete_folder(U16 parent_scrn_id, srv_um_msg_box_enum box_type, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = box_type;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_op_mov2arc_folder
 * DESCRIPTION
 *  A entry function for mark several move to archive process screen menu.
 *  (General folder)
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  box_type                [IN]: Message box type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_op_mov2arc_folder(U16 parent_scrn_id, srv_um_msg_box_enum box_type, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = box_type;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_op_mov2sim
 * DESCRIPTION
 *  A entry function for mark several move to archive process screen menu.
 *  (General folder)
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  box_type                [IN]: Message box type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_op_mov2sim(U16 parent_scrn_id, srv_um_msg_box_enum box_type, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = box_type;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_op_mov2phone
 * DESCRIPTION
 *  A entry function for mark several move to archive process screen menu.
 *  (General folder)
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  box_type                [IN]: Message box type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_op_mov2phone(U16 parent_scrn_id, srv_um_msg_box_enum box_type, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = box_type;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_op_cpy2sim
 * DESCRIPTION
 *  A entry function for mark several move to archive process screen menu.
 *  (General folder)
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  box_type                [IN]: Message box type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_op_cpy2sim(U16 parent_scrn_id, srv_um_msg_box_enum box_type, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = box_type;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_ms_op_cpy2phone
 * DESCRIPTION
 *  A entry function for mark several move to archive process screen menu.
 *  (General folder)
 *  If parent screen id = 0, it means there is no any parent
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  box_type                [IN]: Message box type
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_ms_op_cpy2phone(U16 parent_scrn_id, srv_um_msg_box_enum box_type, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_req_srv_action_enum action;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PROCESSING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_LOADING_PGRS;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_ms_action_event_hdlr;
    setting.folder.msg_box_type = box_type;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    setting.scrn_data = NULL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_ms_action_init);

    MMI_ASSERT(result == MMI_TRUE);

    action = MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE;
    mmi_um_ui_cc_send_event(setting.scrn_id, MMI_UM_UI_EVENT_SET_OP_TYPE, (void *)&action);
    return setting.scrn_id;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_query_data
 * DESCRIPTION
 *  A function to let NMGR call. It will query the data from UM.
 *
 * PARAMETERS
 *  answer              [IN]: The query data
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_nmgr_query_data(mmi_nmgr_answer_struct *answer)
{
    /* Initialize */
    memset(answer, 0, sizeof(mmi_nmgr_answer_struct));
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_new_msg_cancel
 * DESCRIPTION
 *  Cancel the new event by SMS/MMS/Push
 *
 * PARAMETERS
 *  msg_type            [IN]: Cancelled message type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_nmgr_new_msg_cancel(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

static MMI_RET mmi_um_app_proc(mmi_event_struct *evt)
{
    U32 flag = (U32)evt->user_data;
    switch (evt->evt_id)
    {
    case EVT_ID_APP_POST_ENTER:
        {
            mmi_app_evt_struct *p = (mmi_app_evt_struct *)evt;
            mmi_frm_asm_property_struct q;

            mmi_frm_asm_get_property(p->app_id, &q);
	        q.f_prepare_w_reserve = 0;
	        mmi_frm_asm_set_property(p->app_id, &q);
            switch(flag)
            {
            case 'INBX':
                {
#ifdef __MMI_UM_CONVERSATION_BOX__
                    if (MMI_TRUE == mmi_um_check_conversation_box_setting())
                    {
                        mmi_um_entry_conversation();
                    }
                    else
#endif /* __MMI_UM_CONVERSATION_BOX__ */
                    {
#ifdef __MMI_BT_MAP_CLIENT__
                        g_tab_last_enter = MMI_UM_TAB_PAGE_LOCAL;
                         g_sms_um_ui_main_menu_scrn_id = 0;
                         mmi_um_ui_init();
                         srv_um_cache_init();
                         srv_um_listmgr_init();
#endif
                        mmi_um_entry_inbox();
                    }
                    break;
                }
            case 'MMSG':
                {
                    mmi_um_entry_main_message_menu_int();
                    break;
                }
            case 'SFLD':
                {
#ifdef __MMI_UM_CONVERSATION_BOX__
                    if (MMI_TRUE == mmi_um_check_conversation_box_setting())
                    {
                        mmi_um_entry_conversation();
                    }
                    else
#endif /* __MMI_UM_CONVERSATION_BOX__ */
                    {
                        mmi_um_entry_outbox();
                    }
                    break;
                }
            }
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_lsk_handler
 * DESCRIPTION
 *  LSK handler for idle screen
 *
 * PARAMETERS
 *  data:           [IN]    Reserved
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_nmgr_lsk_handler(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return;
        }
    }

    {
#if (defined (__MMI_MAINLCD_96X64__)|| defined(__MMI_UM_ULTRA_SLIM__))
		g_is_launch_from_nav_key=MMI_FALSE;
#endif
#ifdef __MMI_SUPPORT_ASMV2__
        mmi_frm_app_launch(APP_UNIFIEDMESSAGE, 0, 0, mmi_um_app_proc, (void *)'INBX', 0);        
#else
#ifdef __MMI_UM_CONVERSATION_BOX__
                    if (MMI_TRUE == mmi_um_check_conversation_box_setting())
                    {
                        mmi_um_entry_conversation();
                    }
                    else
#endif /* __MMI_UM_CONVERSATION_BOX__ */
					{
						mmi_um_entry_inbox();
					}
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_send_failed_entry
 * DESCRIPTION
 *  LSK handler for idle screen
 *
 * PARAMETERS
 *  data:           [IN]    Reserved
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_send_failed_entry(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__    
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return;
        }
    }
#if 0
#if (defined(__MMI_UM_CONVERSATION_BOX__) && defined(__MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__)) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UM_CONVERSATION_BOX__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
	if (MMI_TRUE != mmi_um_entry_box_with_check())
	{
		mmi_um_current_not_avaiable_popup();
		return;
	}
#endif
#ifdef __MMI_SUPPORT_ASMV2__
    mmi_frm_app_launch(APP_UNIFIEDMESSAGE, 0, 0, mmi_um_app_proc, (void *)'SFLD', 0); 
#else
	
#ifdef __MMI_UM_CONVERSATION_BOX__
                    if (MMI_TRUE == mmi_um_check_conversation_box_setting())
                    {
                        mmi_um_entry_conversation();
                    }
                    else
#endif /* __MMI_UM_CONVERSATION_BOX__ */
					{
						mmi_um_entry_outbox();
					}
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_new_msg_notify_cancel_sms
 * DESCRIPTION
 *  Cancel SMS new message event
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_new_msg_notify_cancel_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_new_msg_notify_cancel_mms
 * DESCRIPTION
 *  Cancel MMS new message event
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_new_msg_notify_cancel_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_query_report_message
 * DESCRIPTION
 *  For Notification management used.
 *      When Notification manager wants the data from UM, it will call this 
 *      function to gather information. Thie funciton is used to query report
 *      message
 *
 * PARAMETERS
 *  answer:             [OUT]   The information for notification manager
 *
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mmi_um_nmgr_query_report_message(struct mmi_nmgr_answer_struct_s *answer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_evt;
    mmi_nmgr_info_struct sms_info; 
#ifdef __MMI_MMS_IN_UM__
    mmi_nmgr_info_struct mms_info;
#endif /* __MMI_MMS_IN_UM__ */
    WCHAR str_unread_msg[(MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1)] = {0};
    WCHAR idle_text1[(MMI_NMGR_MAX_STR_LEN + 1) ] = {0};   /* Text (line 1) used in idle notification */
    S8 *idle_text2 = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* start to get each message application information */
    curr_evt = mmi_nmgr_get_current_process_event();
    mmi_nmgr_get_app_info(MMI_NMGR_APP_SMS_REPORT, &sms_info);
#ifdef __MMI_MMS_IN_UM__
    mmi_nmgr_get_app_info(MMI_NMGR_APP_MMS_REPORT, &mms_info);
#endif /* __MMI_MMS_IN_UM__ */
    if (MMI_NMGR_APP_SMS_REPORT == curr_evt)
    {
        idle_text2 = sms_info.idle_text2;
    }
#ifdef __MMI_MMS_IN_UM__
    else if (MMI_NMGR_APP_MMS_REPORT == curr_evt)
    {
        idle_text2 = mms_info.idle_text2;
    }
#endif /* __MMI_MMS_IN_UM__ */
    else
    {
        MMI_ASSERT(0);
    }

    /* Initialize */
    memset(answer, 0, sizeof(mmi_nmgr_answer_struct));

    /* fill the information for notification manager */
    answer->total_num = sms_info.total_num 
                    #ifdef __MMI_MMS_IN_UM__
                        + mms_info.total_num 
                    #endif /* __MMI_MMS_IN_UM__ */
                        ;
    /* If there is no new message but still have the unread message, UM should reset as 0 for unread message */
    if (answer->total_num != 0)
    {
        if (answer->total_num > 1)
        {
            mmi_ucs2ncpy(
                answer->idle_text1,
                GetString(STR_UM_NEW_REPORT_MSG_ID),
                MMI_NMGR_MAX_STR_LEN);
        
            /* String => N unread message(s) */
            mmi_wsprintf(
                str_unread_msg, 
                MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN,
                STR_UM_UNREAD_MSG_NUMBER_ID,
                answer->total_num);
            mmi_ucs2ncpy(
                (CHAR*)answer->idle_text2,
                (const CHAR*)str_unread_msg,
                MMI_NMGR_MAX_STR_LEN);
        }
        else
        {
            mmi_ucs2cpy(
                answer->idle_text1, 
                (const CHAR*)idle_text1);
            mmi_ucs2cpy(
                answer->idle_text2, 
                (const CHAR*)idle_text2);
        }
    
        /* left softkey string id set as default(view) */
        answer->left_softkey = 0;
        answer->hdlr = mmi_um_nmgr_report_lsk_handler;
    #ifdef __LOW_COST_SUPPORT_COMMON__
        answer->image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
    #else /* __LOW_COST_SUPPORT_COMMON__ */
        answer->image = IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE;
    #endif /* __LOW_COST_SUPPORT_COMMON__ */
        answer->icon = IMG_UM_REPORT_ID;
        answer->user_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_report_lsk_handler
 * DESCRIPTION
 *  LSK handler for idle screen
 *
 * PARAMETERS
 *  data:           [IN]    Reserved
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_nmgr_report_lsk_handler(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_um_ui_ut_check_all_msg_reentry())
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* check re-entry cases, if some instances exist, destroy them */
    if (mmi_um_ui_cc_get_grp_num() > 0)
    {
        /* destroy may be failed */
        if (MMI_RET_OK != mmi_um_ui_cc_destroy_all_grp())
        {
            mmi_um_current_not_avaiable_popup();
            return;
        }
    }
    mmi_um_entry_report();
}
#endif /* __MMI_UM_REPORT_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_inbox
 * DESCRIPTION
 *  Old function for entry inbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_entry_inbox();
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_simbox
 * DESCRIPTION
 *  Old function for entry simbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_entry_simbox();
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


#if defined(__MMI_OP12_TOOLBAR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_sms_inbox
 * DESCRIPTION
 *  Old function for entry SMS only inbox
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_sms_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_launch_inbox_with_sms_only();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_inbox
 * DESCRIPTION
 *  Old function for entry inbox
 *
 * PARAMETERS
 *  msg_type            [IN]: Cancelled message type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_mms_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_launch_inbox_with_mms_only();
}
#endif /* __MMI_OP12_TOOLBAR__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_launch_inbox_with_sms_only
 * DESCRIPTION
 *  Launch inbox with SMS only
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_launch_inbox_with_sms_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_INBOX;
    folder.msg_type = SRV_UM_MSG_SMS;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_launch_inbox_with_mms_only
 * DESCRIPTION
 *  Launch inbox with SMS only
 *
 * PARAMETERS
 *  msg_type            [IN]: Cancelled message type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_launch_inbox_with_mms_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder.msg_box_type = SRV_UM_MSG_BOX_INBOX;
    folder.msg_type = SRV_UM_MSG_MMS;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE,  MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

    mmi_um_ui_ut_send_init_event(scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_current_not_avaiable_popup
 * DESCRIPTION
 *  display common popup showing "Current not avaiable"
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_current_not_avaiable_popup(void)
{
    mmi_popup_display_simple(
            (WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
}

#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_create_ncenter_group
 * DESCRIPTION
 *  create ncenter group to contain message related cells
 *
 * PARAMETERS
 *  
 * RETURNS
 *  vsrv_ngroup_handle
 *****************************************************************************/
vsrv_ngroup_handle mmi_um_create_ncenter_group(void)
{
    vsrv_ngroup_handle message_group = NULL;
    WCHAR ctext[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
    message_group = vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
    if (NULL == message_group)
    {
        message_group = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UNIFIEDMESSAGE);
        mmi_wcscpy(ctext, (WCHAR *)GetString(MAIN_MENU_MESSAGES_TEXT));    
        vsrv_ncenter_set_ngroup_title_str(message_group, ctext);

    }
    return message_group;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_create_ncenter_group
 * DESCRIPTION
 *  query ncenter group to contain message related cells
 *
 * PARAMETERS
 *  
 * RETURNS
 *  vsrv_ngroup_handle 
 *      return NULL if there is no existing group
 *****************************************************************************/
vsrv_ngroup_handle mmi_um_query_ncenter_group(void)
{
    return vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
}

#endif /* __MMI_NCENTER_SUPPORT__ */


static void mmi_um_alert_common(mmi_frm_nmgr_alert_struct *alert_info, 
							MMI_ID status_image_id,
							mmi_proc_func proc,
							NMGR_HANDLE *handler,
							MMI_ID popup_image_id)
{
	/*fill in app id for NSS query*/
	alert_info->app_id = APP_UNIFIEDMESSAGE; //your app id

	alert_info->ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|
						  MMI_FRM_NMGR_UI_STATUS_BAR_MASK|
						  MMI_FRM_NMGR_UI_POPUP_MASK;
	/*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
	alert_info->behavior_mask = PREFER_STATUS_BAR; // or PREFER_STATUS_BAR. PREFER_ICON_ONLY

	/*fill in the status bar information*/
	alert_info->status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	/*the image icon is used for text preview, can be different from popup*/
	/*fill in the status bar icon information*/
	alert_info->status_bar_icon_para.icon_id = status_image_id; 				
	 

	/*fill in the popup information*/	 
	alert_info->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
	/*the image icon is used for popup, can be different from text preview*/
	alert_info->popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
	alert_info->popup_para.popup_button_str_id=STR_GLOBAL_VIEW;

	/*fill in the app launch callback*/
	alert_info->app_proc_para.scrn_group_proc = proc;
	alert_info->app_proc_para.user_data= NULL;
	if (*handler != NULL)
	{
		event_type_old=event_type_new;
	}
	event_type_new=alert_info->event_type;

	*handler = mmi_frm_nmgr_alert(alert_info);
}

static void mmi_um_alert_set_image_only(mmi_frm_nmgr_alert_struct *alert_info, 
							MMI_ID status_image_id,
							mmi_proc_func proc,
							NMGR_HANDLE *handler,
							MMI_ID popup_image_id)
{
	/*fill in app id for NSS query*/
	alert_info->app_id = APP_UNIFIEDMESSAGE; //your app id

	alert_info->alert_option = MMI_FRM_NMGR_DISABLE_PREVIEW |
								MMI_FRM_NMGR_DISABLE_TONE |
								MMI_FRM_NMGR_DISABLE_VIB |
								MMI_FRM_NMGR_DISABLE_POPUP; /* selien set status icon */
	
	alert_info->ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
		/*fill in the status bar information*/
	alert_info->status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	/*the image icon is used for text preview, can be different from popup*/
	/*fill in the status bar icon information*/
	alert_info->status_bar_icon_para.icon_id = status_image_id; 				

	if (*handler != NULL)
	{
		mmi_frm_nmgr_alert_cancel(*handler);
	}
	*handler = mmi_frm_nmgr_alert(alert_info);
}


static NMGR_HANDLE g_new_msg_handle;
static mmi_frm_nmgr_alert_struct g_new_msg_alert;
static MMI_BOOL g_is_new_msg_icon_only;
#if !defined (__MMI_UM_ULTRA_SLIM__) || defined(__MMI_NCENTER_SUPPORT__)
static NMGR_HANDLE g_send_failed_msg_handle;
static mmi_frm_nmgr_alert_struct g_send_failed_msg_alert;
static MMI_BOOL g_is_send_failed_msg_icon_only;
#endif

#ifdef __MMI_BT_MAP_CLIENT__
MMI_ID g_um_general_folder_scrn_id = 0;
MMI_ID g_um_loading_scrn_id = 0;
#endif
void mmi_um_nmgr_unread_cancel(void)
{
	if (g_new_msg_handle != NULL)
	{
	    mmi_frm_nmgr_alert_cancel(g_new_msg_handle);
		g_new_msg_handle = NULL;
	}
}

#if !defined (__MMI_UM_ULTRA_SLIM__) || defined(__MMI_NCENTER_SUPPORT__ )
void mmi_um_nmgr_send_failed_cancel(void)
{
	if (g_send_failed_msg_handle != NULL)
	{
	    mmi_frm_nmgr_alert_cancel(g_send_failed_msg_handle);
		g_send_failed_msg_handle = NULL;
	}
}
#endif

static mmi_ret mmi_um_unread_popup_proc(mmi_event_struct *evt)
{    
	switch(evt->evt_id)
	{
		case EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH:
		case EVT_ID_NMGR_POPUP_APP_LAUNCH:
			mmi_um_nmgr_lsk_handler(NULL);
			
	    case EVT_ID_NMGR_ALERT_END:
			g_is_new_msg_icon_only = MMI_TRUE;
			break;
	}
    return MMI_OK;
} 

void mmi_um_alert_um_inbox_alert_data_prepare(mmi_frm_nmgr_alert_struct *alert_info)
{
	srv_um_get_msg_num_result data;
#ifndef __MMI_BT_DIALER_SUPPORT__
	static WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN * 2 + 1];
	
	mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_UNREAD_MSG));

	if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
	{
		if(data.inbox_unread_msg_number)
		{
			MMI_ID unread_string = STR_UM_UNREAD_MSGS_WITH_NUMBER;
			WCHAR sub_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];

			if (data.inbox_unread_msg_number == 1)
			{
				unread_string = STR_UM_UNREAD_MSG_WITH_NUMBER;
			}
			mmi_wsprintf(
				sub_text, 
				MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
				unread_string, 
				data.inbox_unread_msg_number);

			mmi_ucs2cat((CHAR *)main_text, (const CHAR *)L"\n");
			mmi_ucs2cat((CHAR *)main_text, (const CHAR *)sub_text);
		}
	}
	alert_info->popup_para.popup_string = main_text;
#else    
    MMI_ID string  = STR_UM_UNREAD_MSGS_WITH_NUMBER;
    static WCHAR unread_string[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];

	if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
	{
		if(data.inbox_unread_msg_number)
		{
			if (data.inbox_unread_msg_number == 1)
			{
				string = STR_UM_UNREAD_MSG_WITH_NUMBER;
			}
			mmi_wsprintf(
				unread_string, 
				MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
				string, 
				data.inbox_unread_msg_number);            
		}
	}
	alert_info->popup_para.popup_string = unread_string;
#endif
}


void mmi_um_alert_um_inbox_alert(mmi_frm_nmgr_alert_struct *alert)
{
	mmi_frm_nmgr_alert_struct *alert_info = (mmi_frm_nmgr_alert_struct *)alert;

	mmi_um_alert_um_inbox_alert_data_prepare(alert_info);
	mmi_um_alert_common(alert_info, 
		STATUS_ICON_INCOMING_SMS,
		mmi_um_unread_popup_proc,
		&g_new_msg_handle,
		0);
	g_is_new_msg_icon_only = MMI_FALSE;
    memcpy(&g_new_msg_alert, alert_info, sizeof(g_new_msg_alert));
}

void mmi_um_alert_um_inbox_alert_refresh(void)
{
	srv_um_get_msg_num_result data;
	if (g_new_msg_handle != NULL)
	{
		if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
		{
			if( 0 == data.inbox_unread_msg_number)
			{
			    mmi_frm_nmgr_alert_cancel(g_new_msg_handle);
				g_new_msg_handle = NULL;
				return;
			}
		}		
		if ((MMI_FALSE == g_is_new_msg_icon_only))
		{
			WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN * 2 + 1];
			NMGR_HANDLE new_msg_handle;
			
			mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_UNREAD_MSG));
			

			mmi_um_alert_um_inbox_alert_data_prepare(&g_new_msg_alert);
			g_new_msg_alert.app_id = APP_UNIFIEDMESSAGE; //your app id
			g_new_msg_alert.alert_option = MMI_FRM_NMGR_DISABLE_PREVIEW |
											MMI_FRM_NMGR_DISABLE_TONE |
											MMI_FRM_NMGR_DISABLE_VIB;
	        g_new_msg_alert.status_bar_icon_para.icon_id = STATUS_ICON_INCOMING_SMS;
			new_msg_handle=mmi_frm_nmgr_compose_alert_handle(APP_UNIFIEDMESSAGE,event_type_old, 0);
			if(event_type_old!=event_type_new)
			     mmi_frm_nmgr_alert_cancel(new_msg_handle);
			g_new_msg_handle = mmi_frm_nmgr_alert(&g_new_msg_alert);
			g_is_new_msg_icon_only = MMI_FALSE;
		}
	}
	#ifndef __MMI_NCENTER_SUPPORT__
	/* if ncenter is enabled, the icon is only set by ecenter entry */
	else
	{
		if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
		{
			if( 0 != data.inbox_unread_msg_number)
			{
				mmi_um_alert_um_inbox_alert_set_icon_only();
			}
		}

	}
	#endif
   
}

void mmi_um_alert_um_inbox_alert_set_icon_only(void)
{
	if (g_new_msg_handle == NULL)
	{
        srv_um_get_msg_num_result data;
        if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
        {
            if(data.inbox_unread_msg_number)
            {
		memset(&g_new_msg_alert, 0, sizeof(g_new_msg_alert));
		g_new_msg_alert.event_type = MMI_EVENT_INFO;
		g_new_msg_alert.scen_id = MMI_SCENARIO_ID_GENERAL;
		mmi_um_alert_set_image_only(&g_new_msg_alert,
			STATUS_ICON_INCOMING_SMS,
			NULL,
			&g_new_msg_handle,
			0);
		g_is_new_msg_icon_only = MMI_TRUE;
            }
        }
		return;
	}
}

#if !defined (__MMI_UM_ULTRA_SLIM__) || defined(__MMI_NCENTER_SUPPORT__ )
mmi_ret mmi_um_ncenter_send_failed_popup_proc(mmi_event_struct *evt)
{    
	switch(evt->evt_id)
	{
		case EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH:
		case EVT_ID_NMGR_POPUP_APP_LAUNCH:
	        mmi_um_send_failed_entry(NULL);
			
	    case EVT_ID_NMGR_ALERT_END:
			g_is_send_failed_msg_icon_only = MMI_TRUE;
			break;

	}
    return MMI_OK;
} 

void mmi_um_alert_um_outbox_alert_data_prepare(mmi_frm_nmgr_alert_struct *alert_info)
{
	srv_um_get_msg_num_result data;
#ifndef __MMI_BT_DIALER_SUPPORT__
	static WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN * 2 + 1];
	
	mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_SEND_FAILED_MSG));

	if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
	{
	    S32 count = mmi_um_ui_get_send_failed_count();
		if(count)
		{
            MMI_ID string  = STR_UM_SEND_FAILED_MSGS_NUMBER;
            WCHAR unread_string[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            
            if (count == 1)
            {
               string = STR_UM_SEND_FAILED_MSG_NUMBER;
            }
			mmi_wsprintf(
				unread_string, 
				MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
				string, 
				count);

			mmi_ucs2cat((CHAR *)main_text, (const CHAR *)L"\n");
			mmi_ucs2cat((CHAR *)main_text, (const CHAR *)unread_string);
		}
	}
	alert_info->popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
	alert_info->popup_para.popup_string = main_text;
#else
    S32 count = mmi_um_ui_get_send_failed_count();
    MMI_ID string  = STR_UM_SEND_FAILED_MSGS_NUMBER;
    static WCHAR failed_string[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];

	if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
	{
		if(count)
		{            
            if (count == 1)
            {
               string = STR_UM_SEND_FAILED_MSG_NUMBER;
            }
			mmi_wsprintf(
				failed_string, 
				MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
				string, 
				count); 
		}
	}
	alert_info->popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
	alert_info->popup_para.popup_string = failed_string;
#endif

}


void mmi_um_alert_um_outbox_alert_refresh(void)
{
	if (g_send_failed_msg_handle != NULL)
	{
	    if ((srv_um_check_ready()) && (0 == mmi_um_ui_get_send_failed_count()))
		{
			mmi_frm_nmgr_alert_cancel(g_send_failed_msg_handle);
			g_send_failed_msg_handle = NULL;
			return;
		}		
		if (MMI_FALSE == g_is_send_failed_msg_icon_only)
		{

			
			mmi_um_alert_um_outbox_alert_data_prepare(&g_send_failed_msg_alert);
			g_send_failed_msg_alert.app_id = APP_UNIFIEDMESSAGE; //your app id
			g_send_failed_msg_alert.alert_option = MMI_FRM_NMGR_DISABLE_PREVIEW |
											MMI_FRM_NMGR_DISABLE_TONE |
											MMI_FRM_NMGR_DISABLE_VIB;
		    g_send_failed_msg_alert.status_bar_icon_para.icon_id = STATUS_ICON_OUTBOX_INDICATOR;
			g_send_failed_msg_handle = mmi_frm_nmgr_alert(&g_send_failed_msg_alert);
			g_is_send_failed_msg_icon_only = MMI_FALSE;

		}
	}
	#ifndef __MMI_NCENTER_SUPPORT__ 
	/* if ncenter is enabled, the icon is only set by ecenter entry */
	else
	{
		if (((srv_um_check_ready()) && (0 != mmi_um_ui_get_send_failed_count())))
    	{
			mmi_um_alert_um_outbox_alert_set_icon_only();
    	}

	}
	#endif
}


void mmi_um_alert_um_outbox_alert_set_icon_only(void)
{
	if (g_send_failed_msg_handle == NULL)
	{
        S32 count = mmi_um_ui_get_send_failed_count();
        if(count>0)
        {
		memset(&g_send_failed_msg_alert, 0, sizeof(g_send_failed_msg_alert));
		g_send_failed_msg_alert.event_type = MMI_EVENT_INFO;
		g_send_failed_msg_alert.scen_id = MMI_SCENARIO_ID_GENERAL;
		mmi_um_alert_set_image_only(&g_send_failed_msg_alert,
			STATUS_ICON_OUTBOX_INDICATOR,
			NULL,
			&g_send_failed_msg_handle,
			0);
		g_is_send_failed_msg_icon_only = MMI_TRUE;
        }
		return;
	}
}


void mmi_um_alert_um_outbox_alert(mmi_frm_nmgr_alert_struct *alert_info)
{
    mmi_um_alert_um_outbox_alert_data_prepare(alert_info);
	mmi_um_alert_common(alert_info, 
		STATUS_ICON_OUTBOX_INDICATOR,
		mmi_um_ncenter_send_failed_popup_proc,
		&g_send_failed_msg_handle,
		0);
	g_is_send_failed_msg_icon_only = MMI_FALSE;
    memcpy(&g_send_failed_msg_alert, alert_info, sizeof(g_send_failed_msg_alert));

}

#endif
#ifndef __MMI_SUPPORT_ASMV2__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_app_mem_stop_callback
 * DESCRIPTION
 *  ASM1.0 application memmory stop callback
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

		mmi_um_ui_cc_grp_cntx_struct grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free Memory */
	memset(&grp_cntx,0,sizeof(mmi_um_ui_cc_grp_cntx_struct));

	memcpy(&grp_cntx,&g_um_ui_p->cc_cntx.grp_table[0],sizeof(mmi_um_ui_cc_grp_cntx_struct));

	/******** Destroy UM Grp context from OOM screen *******/
	mmi_um_ui_cc_del_grp_cntx(&grp_cntx);

    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_UM,KAL_TRUE);
    
}
#endif
#endif /* __UM_SUPPORT__ */
