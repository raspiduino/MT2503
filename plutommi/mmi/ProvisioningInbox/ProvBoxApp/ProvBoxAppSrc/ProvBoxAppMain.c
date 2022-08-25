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
 * ProvBoxAppMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox App main procedure.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#ifdef __MMI_PROV_MESSAGE_SUPPORT__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "APPSDKAppGProt.h"

#include "mmi_inet_app_trc.h"

#include "IdleNotificationManagerGprot.h"

#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"

#if defined(__DM_LAWMO_SUPPORT__) && defined(__MMI_PROV_IN_UM__)
#include "mmiapi_dm_struct.h"
#include "DmSrvGprot.h"
#endif

#if defined(__MMI_OP11_HOMESCREEN__) && defined(__MMI_PROV_IN_UM__)
/* under construction !*/
#endif

#ifdef __MMI_PROV_IN_UM__
#include "UMGProt.h"
#endif
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"

#include "mmi_rp_app_cca_def.h"
#include "mmi_rp_app_provbox_def.h"
#include "mmi_rp_srv_status_icons_def.h"

#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxAppGProt.h"
#include "ProvBoxAppProt.h"

 
/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
static mmi_provbox_context_struct g_provbox_context = {0};

/*****************************************************************************
 * Local function
 *****************************************************************************/
static void mmi_provbox_app_init_msg_reg(void);

static void mmi_provbox_app_hilit_idx_hdlr(U32 new_msg_timestamp);

static void mmi_provbox_msg_delete_all(srv_provbox_box_type_enum box_type);

static srv_provbox_result_enum mmi_provbox_msg_delete_all_by_type(srv_provbox_box_type_enum box_type);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
static void mmi_provbox_msg_move_to_archive(U32 msg_id);
#endif

static MMI_BOOL mmi_provbox_new_msg_is_need_notify(srv_provbox_msg_type_enum msg_type);

static void mmi_provbox_new_msg_notify(void);
static void mmi_provbox_nmgr_end(void);

/*===========================================================================
 * Function defined
 *==========================================================================*/
mmi_provbox_context_struct *mmi_provbox_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_provbox_context;
}

#if defined(__MMI_APP_MANAGER_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
mmi_id mmi_provbox_appmgr_launch(void* param, U32 param_size)
{
	return mmi_provbox_pre_entry_from_message(GRP_ID_ROOT);
}
#endif

/*===========================================================================
 * NMGR Handle
 *==========================================================================*/

#define MMI_PROVBOX_NMGR

#ifdef __MMI_NCENTER_SUPPORT__

static vsrv_ngroup_handle mmi_provbox_ncenter_get_group(void)
{
    vsrv_ngroup_handle gid;

#ifdef __MMI_PROV_IN_UM__
    gid = (vsrv_ngroup_handle)mmi_um_query_ncenter_group();
    if (gid == (vsrv_ngroup_handle)VSRV_NGROUP_INVALID_ID)
        return (vsrv_ngroup_handle)mmi_um_create_ncenter_group();
    else
        return gid;
#else
    //if (g_provbox_context.ncenter_gid != (vsrv_ngroup_handle)VSRV_NGROUP_INVALID_ID)
    //    return g_provbox_context.ncenter_gid;
    //else
    {
        gid = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_PROVBOX);
        vsrv_ncenter_set_ngroup_title_str(gid, (WCHAR *)get_string(STR_ID_PROVBOX_APP));
        g_provbox_context.ncenter_gid = gid;
        return gid;
    }
#endif

}

static void mmi_provbox_ncenter_intent_callback(vsrv_notification_handle nid, vsrv_nintent intent, void* userData, U32 userDataSize)
{

    U8 num;
    WCHAR notify[MMI_PROVBOX_NMGR_QUERY_TEXT_MAX_LEN + 1] = {0};
	  
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_NMGR_HDLR);
    
    if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
		#ifndef __MMI_PROV_IN_UM__
	         mmi_provbox_pre_entry_from_message(GRP_ID_ROOT);
        #endif
            //mmi_provbox_msg_install(srv_provbox_get_new_msg_id());
        if (g_provbox_context.hnmgr != 0)
        {
            mmi_frm_nmgr_alert_cancel(g_provbox_context.hnmgr);
            g_provbox_context.hnmgr = 0;
        }
    }
    else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        g_provbox_context.ncenter_nid = (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID;
        if (g_provbox_context.hnmgr != 0)
        {
            mmi_frm_nmgr_alert_cancel(g_provbox_context.hnmgr);
            g_provbox_context.hnmgr = 0;
        }
    }
    else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
    {
		g_provbox_context.ncenter_gid = vsrv_ncenter_query_ngroup(APP_PROVBOX);
		if (g_provbox_context.ncenter_gid == (vsrv_ngroup_handle)VSRV_NGROUP_INVALID_ID)
		        mmi_provbox_ncenter_get_group();
		 vsrv_ncenter_set_ngroup_title_str(g_provbox_context.ncenter_gid, (WCHAR *)get_string(STR_ID_PROVBOX_APP));
		 vsrv_ncenter_set_notification_maintext_str(nid, (WCHAR *)get_string(STR_ID_PROVBOX_APP));
		 
		 num =  srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
		 kal_wsprintf(notify, "%d %w", 
			    num,
                get_string(STR_ID_PROVBOX_NMGR_QUERY_UNREAD_MSGS));
		 vsrv_ncenter_set_notification_subtext_str(nid, (WCHAR*)notify);
		 vsrv_ncenter_notify_notification(nid); 
    }
}

static void mmi_provbox_ncenter_clear_notification(void)
{
    if (g_provbox_context.ncenter_nid != (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID)
        vsrv_ncenter_close_notification(g_provbox_context.ncenter_nid);
    g_provbox_context.ncenter_nid = (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID;
}

static vsrv_notification_handle mmi_provbox_ncenter_get_notification(vsrv_ngroup_handle gid, mmi_provbox_ncenter_nid_enum type)
{
    vsrv_notification_handle nid;

    switch(type)
    {
        case MMI_PROVBOX_NCENTER_NID_NEW_SETTING:
            //if (g_provbox_context.ncenter_nid != (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID)
            //    return g_provbox_context.ncenter_nid;
            nid  = 
                vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, gid, type);
            g_provbox_context.ncenter_nid = nid;
            vsrv_ncenter_set_notification_maintext_str(nid, (WCHAR *)get_string(STR_ID_PROVBOX_APP));
            break;
            
        case MMI_PROVBOX_NCENTER_NID_INBOX_FULL:
            //if (g_provbox_context.ncenter_full_nid != (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID)
            //    return g_provbox_context.ncenter_full_nid;
            nid  = 
                vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, gid, type);
            g_provbox_context.ncenter_full_nid = nid;
            vsrv_ncenter_set_notification_maintext_str(nid, (WCHAR *)get_string(STR_ID_PROVBOX_APP));
            break;
            
        default:
            return NULL;
    }
    
    vsrv_ncenter_set_notification_intent_callback(nid, mmi_provbox_ncenter_intent_callback, NULL, 0);
    
    return nid;
}



static void mmi_provbox_ncenter_notify_new_msg(void)
{
#ifndef __MMI_PROV_IN_UM__
    U8 num;
    vsrv_ngroup_handle gid;
    vsrv_notification_handle nid;
    applib_time_struct timestamp;
    WCHAR notify[MMI_PROVBOX_NMGR_QUERY_TEXT_MAX_LEN + 1] = {0};
    
	num =  srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);

	if(num == 0)
	{
		mmi_provbox_ncenter_clear_notification();
	}
	else
	{
                GetDateTime(&timestamp);
                gid = mmi_provbox_ncenter_get_group();
                nid = mmi_provbox_ncenter_get_notification(gid, MMI_PROVBOX_NCENTER_NID_NEW_SETTING);
                vsrv_ncenter_set_notification_timestamp(nid,&timestamp);
                kal_wsprintf(notify, "%d %w", 
			num,
                        get_string(STR_ID_PROVBOX_NMGR_QUERY_UNREAD_MSGS));

                vsrv_ncenter_set_notification_subtext_str(nid, (WCHAR*)notify);
                vsrv_ncenter_notify_notification(nid); 
	}

#endif
}

void mmi_provbox_ncenter_notify_inbox_full(void)
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
#endif
}

#endif /* __MMI_NCENTER_SUPPORT__*/

/* New NMGR*/
static mmi_ret mmi_provbox_nmgr_proc(mmi_event_struct *evt)
{
    if(evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH ||
       evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
    #ifdef __MMI_NCENTER_SUPPORT__
        mmi_provbox_ncenter_notify_new_msg();
    #endif
	#ifndef __MMI_PROV_IN_UM__
	    mmi_provbox_pre_entry_from_message(GRP_ID_ROOT);
    #endif
        //mmi_provbox_nmgr_hdlr(NULL);
    }
    else if(evt->evt_id == EVT_ID_NMGR_ALERT_END)
    {
/*    #ifdef __MMI_NCENTER_SUPPORT__
        mmi_provbox_ncenter_clear_notification();
      #endif
*/
        //mmi_provbox_nmgr_cancel();
        mmi_provbox_nmgr_end();
    }
    return MMI_TRUE;
}

static void mmi_cca_provbox_notify_new_msg(void)
{    
	WCHAR temp_buf[128];
    mmi_frm_nmgr_alert_struct alert_info;
    U32 unread_num,sim_idx = 0;
    WCHAR notify[MMI_PROVBOX_NMGR_QUERY_TEXT_MAX_LEN + 1] = {0};

    sim_idx =  mmi_provbox_get_new_msg_idx();
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
    
	unread_num = srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);

	kal_wsprintf(temp_buf, "%d %w", unread_num, get_string(STR_ID_CCA_NEW_SETTING));
    
#ifdef __MMI_PROV_IN_UM__
    /*fill in app id for NSS query*/
    alert_info.app_id = APP_PROVBOX;
    /*fill in the basic info*/
    alert_info.scen_id = MMI_SCENARIO_ID_PROVISIOING;
    alert_info.event_type = mmi_provbox_get_notify_event(sim_idx);
    
    alert_info.status_bar_para.display_string = (WCHAR *)temp_buf;
    alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    alert_info.status_bar_para.image.id = IMG_SI_PROVMSG;
#else
    alert_info.status_bar_para.image.id = IMG_SI_SMS_INDICATOR;
#endif
    mmi_um_alert_um_inbox_alert(&alert_info);
    
#else

    alert_info.app_id = APP_PROVBOX;
    alert_info.scen_id = MMI_SCENARIO_ID_PROVISIOING;
    alert_info.event_type = mmi_provbox_get_notify_event(sim_idx);
    /*fill in the notification information, if your app's notification can be controlled by NSS, your UI mask must include icon, status bar and popup*/
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
    /*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
    alert_info.behavior_mask = PREFER_POPUP; // or PREFER_STATUS_BAR. PREFER_ICON_ONLY
    /*fill in the status bar information*/
    alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    /*the image icon is used for text preview, can be different from popup*/
    /*Please check the ID with Shuaihui Ren to make sure if the icon can fit your requirement*/
    //alert_info.status_bar_para.app_type = NATIVE_APP_TYPE;
    alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    alert_info.status_bar_para.image.id = IMG_SI_PROVMSG;
#else
    alert_info.status_bar_para.image.id = IMG_SI_SMS_INDICATOR;
#endif
    alert_info.status_bar_para.display_string = (WCHAR *)temp_buf;
    /*fill in the popup information*/    
    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    /*the image icon is used for popup, can be different from text preview*/
    //alert_info.popup_para.app_type = NATIVE_APP_TYPE;
    alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert_info.popup_para.image.id = IMG_ID_CCA_NEW_SETTING_IDLE;
        //get_string(STR_ID_PROVBOX_NMGR_QUERY_UNREAD_MSGS));
    alert_info.popup_para.popup_string = (WCHAR *)temp_buf;
    alert_info.popup_para.popup_button_string = (WCHAR*)get_string(STR_GLOBAL_READ);
    /*fill in the status bar icon information*/
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_PROVMSG_STATE;
    #else
      alert_info.status_bar_icon_para.icon_id = STATUS_ICON_INCOMING_SMS;
    #endif

    /*fill in the app launch callback*/
    alert_info.app_proc_para.scrn_group_proc = &mmi_provbox_nmgr_proc;
    alert_info.app_proc_para.user_data = NULL;	
    alert_info.app_proc_para.data_size = 0;
    g_provbox_context.hnmgr = mmi_frm_nmgr_alert(&alert_info);
   /* Once notification is done clear it */
	MMI_PROVBOX_RESET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY);
#endif
}


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_nmgr_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_nmgr_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_info_struct data = {0};
    WCHAR notify[MMI_PROVBOX_NMGR_QUERY_TEXT_MAX_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROV_IN_UM__
    if (0 == MMI_PROVBOX_GET_BIT_VALUE(g_provbox_context.flags, 
               MMI_PROVBOX_FLAG_BIT_IDX_NMGR_NOTIFY, 
               MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY)
    )
    {
        mmi_nmgr_answer(MMI_NMGR_APP_PROVISIOING, MMI_NMGR_RESULT_OK, &data, NULL);
        return;
    }
#endif

    kal_wsprintf(notify, "%d %w", 
        srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL),
        get_string(STR_ID_PROVBOX_NMGR_QUERY_UNREAD_MSGS));

    data.total_num = (S32) srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
    data.idle_text1 = (CHAR *)get_string(STR_ID_CCA_NEW_SETTING);
    data.idle_text2 = (CHAR *)notify;
    data.image = IMG_ID_CCA_NEW_SETTING_IDLE;
#ifndef __MMI_PROV_IN_UM__
    data.left_softkey = STR_GLOBAL_READ;
#endif

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_NMGR_QUERY, data.total_num);

    mmi_nmgr_answer(MMI_NMGR_APP_PROVISIOING, MMI_NMGR_RESULT_OK, &data, mmi_provbox_nmgr_hdlr);
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_nmgr_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_nmgr_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_NMGR_CANCEL, g_provbox_context.flags);
    MMI_PROVBOX_RESET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY);
#ifdef __MMI_NCENTER_SUPPORT__
    mmi_provbox_ncenter_clear_notification();
#endif
    if (g_provbox_context.hnmgr != 0)
    {

        mmi_frm_nmgr_alert_cancel(g_provbox_context.hnmgr);
        /*MAUI_03193216 :
          We update status icon now. this scenario is created because in notification we set style to None. So in this way when we enter settings screen 
		  then we cancel notification which result in removal of status icon. So we have to update it now.
		*/
#ifndef __MMI_PROV_IN_UM__
		mmi_provbox_update_status_icon();
#endif
        g_provbox_context.hnmgr = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_nmgr_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_nmgr_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_NMGR_CANCEL, g_provbox_context.flags);
    MMI_PROVBOX_RESET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY);
    g_provbox_context.hnmgr = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_nmgr_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_nmgr_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_NMGR_HDLR);
#ifndef __MMI_PROV_IN_UM__
    mmi_provbox_msg_install(srv_provbox_get_new_msg_id());
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_idle_new_msg_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_provbox_idle_new_msg_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_IDLE_NEW_MSG_CHECK, g_provbox_context.flags);

    return (U8)MMI_PROVBOX_GET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_IDX_NMGR_NOTIFY, MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_idle_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_idle_new_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    sim_idx =  mmi_provbox_get_new_msg_idx();
    //mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_PROVISIOING, mmi_provbox_get_notify_event(sim_idx), NULL);
    mmi_cca_provbox_notify_new_msg();
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_IDLE_NEW_MSG_IND, sim_idx);
}

/*===========================================================================
 * NMGR Handle End
 *==========================================================================*/

 
/*===========================================================================
 * Dm lawmo Handle
 *==========================================================================*/
#define MMI_PROVBOX_DM_LAWMO_HDLR

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_lawmo_lock_ind_hdlr
 *
 * DESCRIPTION
 *  This function is to handle lawmo lock command
 *
 * PARAMETERS
 *  mmi_event_struct *evt [IN]
 *  evt should transfer to srv_dm_lawmo_lock_ind_evt_struct
 *
 * RETURNS
 *  mmi_ret  MMI_RET_OK indicate that ProvBoxApp have done lawmo lock
 *
 *****************************************************************************/
#if defined(__DM_LAWMO_SUPPORT__) && defined(__MMI_PROV_IN_UM__)
mmi_ret mmi_provbox_lawmo_lock_ind_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_lock_ind_evt_struct* lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lawmo_lock_ind->cmd)
    {
        case SRV_DM_LAWMO_LOCK_CMD_LOCK:
        {
            MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LAWMO_LOCK_IND_LOCK);
            mmi_provbox_hide_status_icon();
            
            // the 2nd param input app special debug info
            (*lawmo_lock_ind->cb)(MMI_TRUE, "Provisioning message");
            break;
        }

        case SRV_DM_LAWMO_LOCK_CMD_UNLOCK:
        {
            MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LAWMO_LOCK_IND_UNLOCK);
            mmi_provbox_update_status_icon();
            
            // the 2nd param input app special debug info
            // Apps may not send unlock result report
            (*lawmo_lock_ind->cb)(MMI_TRUE, "Provisioning message");
            break;
        }

        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_lawmo_wipe_ind_hdlr
 *
 * DESCRIPTION
 *  This function is to handle lawmo wipe event
 *
 * PARAMETERS
 *  mmi_event_struct* evt [IN]
 *
 * RETURNS
 *  mmi_ret
 *
 *****************************************************************************/
mmi_ret mmi_provbox_lawmo_wipe_ind_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind = 
        (srv_dm_lawmo_wipe_ind_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_DM_LAWMO_WIPE_CMD_APP_WIPE == lawmo_wipe_ind->cmd)
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LAWMO_WIPE_IND_HDLR);
        /* When DM send LAWMO wipe command, Provisioning message should 
           wipe all relate messages, which include in inbox, archive box
           and extern box*/
        mmi_provbox_msg_delete_all_by_type(SRV_PROVBOX_BOX_TYPE_WHOLE_ALL);
        
        // the 2nd param input app special debug info
        // must report wipe result
        (*lawmo_wipe_ind->cb)(MMI_TRUE, "Provisioning message");
    }
    
    return MMI_RET_OK;
}
#endif

/*===========================================================================
 * New message Handle
 *==========================================================================*/
#define MMI_PROVBOX_NEW_MSG_HDLR

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_handle_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_handle_new_msg_ind(srv_provbox_evt_new_msg_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, 
        MMI_PROVBOXAPP_TRC_NEW_MSG_IND, 
        data->cmn_info.read_status,
        data->cmn_info.timestamp,
        data->cmn_info.msg_type);

    /* update unread msg num */
    if (mmi_provbox_is_unread_msg(data->cmn_info.read_status))
    {
        MMI_PROVBOX_SET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY);
    }

    /* update status icon */
#ifndef __MMI_PROV_IN_UM__
    mmi_provbox_update_status_icon();
#else
	if (srv_provbox_is_full())
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UPDATE_FULL_ICON);
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_blink_icon(STATUS_ICON_PROVMSG_STATE);
#else
		    wgui_status_icon_bar_blink_icon(IMG_SI_SMS_INDICATOR);
#endif
    }
#endif
    /* to update list highlight item */
    mmi_provbox_app_hilit_idx_hdlr(data->cmn_info.timestamp);

    /* Handle DM phone lock*/
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__*/
    
    /* new msg popup */
    if (mmi_provbox_new_msg_is_need_notify(data->cmn_info.msg_type))
    {
        mmi_provbox_new_msg_notify();

        if (SCR_ID_PROVBOX_LIST_MENU == mmi_frm_scrn_get_active_id())
        {
            mmi_provbox_nmgr_cancel();
        }
    }

#ifndef __MMI_PROV_IN_UM__
    if (SCR_ID_PROVBOX_LIST_MENU == mmi_frm_scrn_get_active_id()) /* For FW2.0 */
    {
        mmi_provbox_refresh_list_scrn();
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_is_msg_need_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_info        [IN]
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_provbox_new_msg_is_need_notify(srv_provbox_msg_type_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return msg_type != MMI_PROVBOX_MSG_TYPE_SIM_MMSICP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_new_msg_notify
 *
 * DESCRIPTION
 *  This function is to notify that target receive a new provisioning message
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *
 *****************************************************************************/
static void mmi_provbox_new_msg_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx = 0;
    mmi_event_notify_enum event_type = MMI_EVENT_SMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_idx =  mmi_provbox_get_new_msg_idx();
    event_type = mmi_provbox_get_notify_event(sim_idx);

#if defined(__MMI_OP11_HOMESCREEN__) && defined(__MMI_PROV_IN_UM__)
/* under construction !*/
#endif 
    {
    #ifdef __MMI_NCENTER_SUPPORT__
        mmi_provbox_ncenter_notify_new_msg();
    #endif
        //mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_PROVISIOING, event_type, (WCHAR *)get_string(STR_ID_CCA_NEW_SETTING));
        mmi_cca_provbox_notify_new_msg();
    }
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_NEW_MSG_NOTIFY, sim_idx, event_type);
}

/*===========================================================================
 * App Handle
 *==========================================================================*/
#define MMI_PROVBOX_APP_HDLR
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_init
 *
 * DESCRIPTION
 *  This function is to initial provboxapp
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *
 *****************************************************************************/
void mmi_provbox_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_NCENTER_SUPPORT__)
    //#ifndef __MMI_PROV_IN_UM__
    g_provbox_context.ncenter_gid = (vsrv_ngroup_handle)VSRV_NGROUP_INVALID_ID;
    //#endif
    g_provbox_context.ncenter_nid = (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID;
    g_provbox_context.ncenter_full_nid = (vsrv_notification_handle)VSRV_NOTIFICATION_INVALID_ID;
#endif
    /* Init Primitive message */
    mmi_provbox_app_init_msg_reg();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_is_ready
 *
 * DESCRIPTION
 *  This function is to check if provboxapp is ready
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL  [OUT]
 *  MMI_TRUE  provboxapp is ready
 *  MMI_FALSE provbxoapp is not ready
 *
 *****************************************************************************/
MMI_BOOL mmi_provbox_app_is_ready(void)
{
    return srv_provbox_is_ready();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_init_msg_reg
 *
 * DESCRIPTION
 *  This function is to register message handler
 *
 * PARAMETERS
 *  void
 *
 * RETRUE
 *  void
 *****************************************************************************/
static void mmi_provbox_app_init_msg_reg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Handle cca process provisioning message install cnf */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_CCA_PROCESS_PROV_MSG_CNF,
        (PsIntFuncPtr) mmi_provbox_msg_handle_cca_process_prov_msg_cnf,
        MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_error_hdlr
 *
 * DESCRIPTION
 *  This function is to handle provboxapp error which is to close all screen of 
 *  provboxapp
 *
 * PARAMETERS
 *  void
 *
 * RETRUE
 *  void
 *****************************************************************************/
void mmi_provbox_app_error_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(mmi_provbox_scrn_group_get_id());
}

/*===========================================================================
 * Hilite indx Handle
 *==========================================================================*/
#define MMI_PROVBOX_APP_HILIT_IDX
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_hilit_idx_hdlr
 *
 * DESCRIPTION
 *  This function is to handle provboxapp error which is to close all screen of 
 *  provboxapp
 *
 * PARAMETERS
 *  U32    [In]
 *  new_msg_timestamp: it is the time of reveiced new provisioning message
 * RETRUE
 *  void
 *****************************************************************************/
static void mmi_provbox_app_hilit_idx_hdlr(U32 new_msg_timestamp)
{
#ifndef __MMI_PROV_IN_UM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_properties_struct msg_info = {0};
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_is_present(
            mmi_provbox_scrn_group_get_id(), 
            SCR_ID_PROVBOX_LIST_MENU, 
            MMI_FRM_NODE_ALL_FLAG))
    {
         return;
    }
    
    msg_info.msg_id = cntx->cur_msg_id;

    srv_provbox_msg_get_properties(&msg_info);
    
    if (msg_info.cmn_info.timestamp < new_msg_timestamp )
    {
        cntx->cur_hilit_idx++;
    }
#endif
}


/*===========================================================================
 * Application process operate Handle
 *==========================================================================*/
#define MMI_PROVBOX_APP_PROC_OPERATE

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_install
 *
 * DESCRIPTION
 *  This function is to install a provisioning message
 *
 * PARAMETERS
 *  U32    [In]
 *  msg_id: it is to indicate which provisioning message is installed
 * RETRUE
 *  srv_provbox_result_enum  [Out]
 *  SRV_PROVBOX_RESULT_OK: return the result of install message
 *****************************************************************************/
srv_provbox_result_enum mmi_provbox_msg_install(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_provbox_is_in_call())
    {
        mmi_provbox_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
        return SRV_PROVBOX_RESULT_OK;
    }
    
    if (mmi_provbox_scrn_group_get_id() != GRP_ID_INVALID &&
        MMI_PROVBOX_GET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_IDX_INSTALL, MMI_PROVBOX_FLAG_BIT_INSTALL))
    {
        MMI_PROVBOX_SET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_CLOSING_WIDGET_INST);
        mmi_provbox_scrn_group_close();
        return SRV_PROVBOX_RESULT_OK;
    }
    
    /* Remove idle new msg popup */
    mmi_provbox_nmgr_cancel();
    
    mmi_provbox_scrn_group_create(GRP_ID_ROOT);
    
    /* becuase install is ansyc progress, show progress to stop any operation by user */
    mmi_provbox_progress_scrn_show(MMI_PROVBOX_OP_INSTALLING);
    
    MMI_PROVBOX_SET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_INSTALL);
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_INSTALL, msg_id, g_provbox_context.flags);
    
    mmi_provbox_send_cca_process_prov_msg_req(msg_id);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_install_done
 *
 * DESCRIPTION
 *  this function is call after finishing to install provisioning message
 *
 * PARAMETERS
 *  data        [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_msg_install_done(srv_cca_process_prov_msg_cnf_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_INSTALL_DONE, data->msg_id, g_provbox_context.flags, data->status);

    /* Handle DM phone lock*/
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        MMI_PROVBOX_RESET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_INSTALL);
        return;
    }
#endif

#ifdef __MMI_PROV_IN_UM__
    if (MMI_PROVBOX_GET_BIT_VALUE(g_provbox_context.flags, 
        MMI_PROVBOX_FLAG_BIT_IDX_CLOSING_WIDGET_INST, MMI_PROVBOX_FLAG_BIT_CLOSING_WIDGET_INST) &&
        g_provbox_context.cur_msg_id)
    {
		MMI_PROVBOX_RESET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_CLOSING_WIDGET_INST);
        //mmi_provbox_msg_install(g_provbox_context.cur_msg_id);
    }
	else
    srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_MSG_CONTENT_CHANGED, data->msg_id, NULL);
#endif

    if (!MMI_PROVBOX_GET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_IDX_INSTALL, MMI_PROVBOX_FLAG_BIT_INSTALL))
    {
        return;
    }
   
    /* when ansync process finishs, progress should be close, and user can do other operation */
    mmi_provbox_progress_scrn_close();

    MMI_PROVBOX_RESET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_INSTALL);
#ifndef __MMI_PROV_IN_UM__
    mmi_provbox_update_status_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_delete_confirm
 *
 * DESCRIPTION
 *  this function is to handle the event of delete confirm popup
 *
 * PARAMETERS
 *  data        [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_provbox_msg_delete_confirm(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_DELETE_CONFIRM, alert->result, alert->user_tag);

            if (MMI_ALERT_CNFM_YES == alert->result)
            {
                 mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
                 mmi_provbox_op_enum op_type = (mmi_provbox_op_enum)alert->user_tag;
            
            
                 if (MMI_PROVBOX_OP_DELECTING == op_type)
                 {
                     mmi_provbox_msg_delete(cntx->cur_msg_id);
                 }
                 else if (MMI_PROVBOX_OP_DELECTING_ALL == op_type)
                 {
                     mmi_provbox_msg_delete_all(cntx->cur_box_type);
                 }
		    #ifdef __MMI_PROV_IN_UM__
				 if (!srv_provbox_is_full())
				 {
					MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UPDATE_HIDE_ICON);
				#ifndef __MMI_STATUS_ICON_BAR_SLIM__
					wgui_status_icon_bar_hide_icon(STATUS_ICON_PROVMSG_STATE);
				#else
					wgui_status_icon_bar_hide_icon(STATUS_ICON_INCOMING_SMS);
				#endif
				 }
			#endif
				 
			#ifdef __MMI_NCENTER_SUPPORT__ 
					mmi_provbox_ncenter_notify_new_msg();
			#endif
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
 *  mmi_provbox_msg_delete
 *
 * DESCRIPTION
 *  this function is to delete the special message which is indicated by msg_id
 *
 * PARAMETERS
 *  U32      [IN]
 *  msg_id: indicate the deleted provisioning message
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_msg_delete(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_msg_delete(msg_id);

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_DELETE, result, msg_id);

    if (SRV_PROVBOX_RESULT_READING == result)
    {
        mmi_provbox_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }
    else if (SRV_PROVBOX_RESULT_OK == result)
    {
        mmi_provbox_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_provbox_popup(STR_ID_PROVBOX_DELETE_FAIL, MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_delete_all_by_type
 *
 * DESCRIPTION
 *  this function is to delete the related provisioning messages which are
 *  indicated by message box type
 *
 * PARAMETERS
 *  srv_provbox_box_type_enum      [IN]
 *  box_type: indicate which type of provisioning message is deleted
 *
 * RETURNS
 *  srv_provbox_result_enum        [OUT]
 *  SRV_PROVBOX_RESULT_OK:   deletes messages successfully
 *  SRV_PROVBOX_RESULT_FAIL: fail to deletes message
 *****************************************************************************/
static srv_provbox_result_enum mmi_provbox_msg_delete_all_by_type(srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = 0;
    srv_provbox_result_enum delete_result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_msg_delete_all_struct data = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (box_type)
    {
        data.box_type = MMI_PROVBOX_GET_AVALIABLE_VALUE(box_type, idx);
        if(data.box_type) /* May be 0 */
        {
            data.del_all_type = SRV_PROVBOX_DEL_ALL_MSG_MODE_UNDEFINED;

            do {
                delete_result = srv_provbox_msg_delete_all(&data);
            } while(SRV_PROVBOX_RESULT_CONTINUE == delete_result);
            
            MMI_PROVBOX_RESET_VALUE(box_type, idx);
        }
        
        idx++;
    }
    
    return delete_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_delete_all
 *
 * DESCRIPTION
 *  this function is to delete the related provisioning messages which are
 *  indicated by message box type
 *
 * PARAMETERS
 *  srv_provbox_box_type_enum      [IN]
 *  box_type: indicate which type of provisioning message is deleted
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_msg_delete_all(srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum delete_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_result = mmi_provbox_msg_delete_all_by_type(box_type);

    //MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_DELETE_ALL, delete_result, box_type);

    if (SRV_PROVBOX_RESULT_OK == delete_result)
    {
        mmi_provbox_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    }
    else if (SRV_PROVBOX_RESULT_READING == delete_result)
    {
        mmi_provbox_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }
    else
    {
        mmi_provbox_popup(STR_ID_PROVBOX_DELETE_ALL_POPUP_MSGS, MMI_EVENT_FAILURE);
    }
}



#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
 
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_move_to_achive_confirm
 *
 * DESCRIPTION
 *  this function is to handle event of move to achive confirm popup
 *
 * PARAMETERS
 *  mmi_event_struct      [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_provbox_msg_move_to_achive_confirm(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

            if (MMI_ALERT_CNFM_YES == alert->result)
            {
                 mmi_provbox_msg_move_to_archive(cntx->cur_msg_id);
            }
            
            //MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_DELETE_ALL, alert->result, cntx->cur_msg_id);
            break;
         }
         
         default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_move_to_archive
 *
 * DESCRIPTION
 *  this function is operation which move the special message to archive box
 *
 * PARAMETERS
 *  U32      [IN]
 *  msg_id: indicate which message is moved to archive box
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_msg_move_to_archive(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_multi_op_struct multi_cntx = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    multi_cntx.box_type     = SRV_PROVBOX_BOX_TYPE_INBOX;
    multi_cntx.msg_id[0]    = msg_id;
    multi_cntx.msg_num      = 1;
    multi_cntx.op           = SRV_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE;
    multi_cntx.op_result[0] = SRV_PROVBOX_RESULT_FAIL;

    srv_provbox_msg_multi_op_hdlr(&multi_cntx);
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_MOVE_TO_ACHIVE, multi_cntx.op_result[0], msg_id);
    
    if (SRV_PROVBOX_RESULT_OK != multi_cntx.op_result[0])
    {
        mmi_provbox_popup(STR_ID_PROVBOX_FAIL_TO_MOVE, MMI_EVENT_FAILURE);        
    }
    else
    {
        mmi_provbox_popup(STR_ID_PROVBOX_MOVED, MMI_EVENT_SUCCESS);
    }
}

#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_read_properties
 *
 * DESCRIPTION
 *  this function is operation which get the properties of provisioning message
 *
 * PARAMETERS
 *  U32      [IN]
 *  msg_id: indicate which message is readed the properties
 *
 *  WCHAR *  [IN]
 *  properties: the address of properties buffer
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_msg_read_properties(U32 msg_id, WCHAR * properties)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_properties_struct msg_info = {0};
    srv_provbox_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == properties)
    {
        return;
    }

    msg_info.msg_id = msg_id;
    
    result = srv_provbox_msg_get_properties(&msg_info);

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_READ_PROPERTIES, result, msg_id);
    
    if (SRV_PROVBOX_RESULT_NOT_FOUND == result)
    {
        mmi_provbox_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }

    srv_provbox_set_msg_status(msg_info.msg_id, SRV_PROVBOX_MSG_READ_STATUS_READ);

    mmi_provbox_compose_properties(properties, &msg_info.cmn_info);
}

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
