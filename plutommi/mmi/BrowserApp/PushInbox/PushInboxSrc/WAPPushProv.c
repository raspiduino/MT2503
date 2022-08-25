
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
 * PushProv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This source file contains code for OTA provisioning of Trustlist data.
 *
 * Author: Ramneek Kalra
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "MMI_include.h"
    #include "MMI_features.h"
   // #include "CentralConfigAgentMsgDefs.h"
    #include "WAPPushUITypes.h"
    #include "MMIDataType.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"

#ifdef __WAP_PUSH_SUPPORT__

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

//#include "DataAccountDef.h"
//#include "DataAccountGprot.h"
#include "CentralConfigAgentGProt.h"

//#include "WAPPushUIProts.h"
#include "mmi_inet_app_trc.h"
#include "pmg_struct.h"

#include "UCMGProt.h"
//#include "UcmSrvGprot.h"
    #include "DebugInitDef_Int.h"
    #include "WAPPushSrvTypes.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "CcaSrvGprot.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "stack_msgs.h"
    #include "stack_config.h"
    #include "GlobalResDef.h"
    #include "WAPPushResDef.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #include "common_nvram_editor_data_item.h"
    #include "string.h"
    #include "mmi_frm_events_gprot.h"
    #include "Unicodexdcl.h"
    #include "CustDataRes.h"
    #include "mmi_rp_app_cca_def.h"
    #include "stdio.h"
    #include "custom_phb_config.h"
    #include "WAPPushSrvProts.h"
    #include "wgui_categories_text_viewer.h"
    #include "wgui_categories_util.h"
    #include "GlobalMenuItems.h"
    #include "GlobalConstants.h"
    #include "mmi_inet_app_trc.h"
    #include "mmi_frm_scenario_gprot.h"

/* Static API */
static void mmi_brw_push_ota_ui_entry_info_screen_display(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_cca_proc
 * DESCRIPTION
 *  Proc function for Data account CUI.
 * PARAMETERS
 *  mmi_event_struct*                    [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_cca_proc(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    switch(evt->evt_id)
    {

		 case EVT_ID_GROUP_DEINIT:
              mmi_frm_group_close(GRP_ID_BRW_PUSH_OPTION);
              break;
    }

    return MMI_RET_OK;
}


void mmi_wap_push_create_ota_group (void)
{
	//mmi_frm_group_create(mmi_cca_get_root_group(), GRP_ID_BRW_PUSH_OPTION, mmi_wap_push_cca_proc, NULL);
	//mmi_frm_group_enter(GRP_ID_BRW_PUSH_OPTION , MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create_ex(mmi_cca_get_root_group(), GRP_ID_BRW_PUSH_OPTION, mmi_wap_push_cca_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
}




mmi_ret mmi_wap_push_scrhdlr_delete_static_screen_1 (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT :
            MMI_TRACE(
                SRV_INET_TRC_G4_PUSH,
                TRC_MMI_BRW_PUSH_OTA_INFO_SCR_DELETED,
                g_srv_wap_push_ota_cntxt.scr_deleted,
                g_srv_wap_push_ota_cntxt.cca_status_sent);
            if ((MMI_FALSE == g_srv_wap_push_ota_cntxt.scr_deleted) && (MMI_FALSE == g_srv_wap_push_ota_cntxt.cca_status_sent))
            {
                /* If screen is deleted from history. and by some action unknown to me or by End key. */
                srv_wap_push_ota_mem_free_trustlist();
                g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_ENDKEY_PRESSED;
                g_srv_wap_push_ota_cntxt.cca_status_sent = MMI_TRUE;

                srv_wap_push_ota_send_cca_response(g_srv_wap_push_ota_cntxt.installed_result);
            }
            g_srv_wap_push_ota_cntxt.scr_deleted = MMI_FALSE;
        break;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_display_info_scrn_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_ota_display_info_scrn_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(GRP_ID_BRW_PUSH_OPTION, STR_ID_BRW_PUSH_OTA_SKIP_WHITELIST, srv_wap_push_ota_skip_whitelist_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_create_display_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  PU8(?)
 *****************************************************************************/
void mmi_wap_push_ota_create_display_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 single_space_char_ucs2[3 * ENCODING_LENGTH];
    S8 *colon_char_ucs2;
    U8 new_line_info[4];
    S8 buffer[((SRV_WAP_PUSH_OTA_PROXY_ID_LEN + 1) * ENCODING_LENGTH)];
    S8 ascii_buffer[SRV_WAP_PUSH_OTA_PROXY_ID_LEN + 2];

    S8 *address = (S8*)g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.crnt_trustlist_index]->addr;
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));
    mmi_asc_to_ucs2((S8*) new_line_info, (S8*) "\n");
    mmi_asc_to_ucs2((S8*) single_space_char_ucs2, (S8*) " ");

    colon_char_ucs2 = (S8*) GetString(STR_ID_BRW_PUSH_COLON_CHAR);

    mmi_ucs2cpy((PS8) subMenuData, (PS8) GetString(STR_ID_CCA_PUSH));
    mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

    mmi_ucs2cat((PS8) subMenuData, (PS8) GetString(STR_ID_PUSH_WHITE_LIST));
    mmi_ucs2cat((PS8) subMenuData, (PS8) colon_char_ucs2);
    mmi_ucs2cat((PS8) subMenuData, single_space_char_ucs2);

    memset(buffer, 0, sizeof(buffer));
    memset(ascii_buffer, 0, sizeof(ascii_buffer));

    sprintf(
        (S8*) ascii_buffer,
        (S8*) "%d/%d",
        g_srv_wap_push_ota_cntxt.crnt_trustlist_index + 1,
        g_srv_wap_push_ota_cntxt.crnt_trustlist_index + g_srv_wap_push_ota_cntxt.total_trustlist_count);

    mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);
    mmi_ucs2cat((PS8) subMenuData, (PS8) buffer);
    mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

    switch (g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.crnt_trustlist_index]->addr_type)
    {
        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP:    /* IP address */
            mmi_ucs2cat((PS8) subMenuData, (PS8) GetString(STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS));
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SENDER:    /* SENDER_ADD */
            mmi_ucs2cat((PS8) subMenuData, (PS8) GetString(STR_ID_BRW_PUSH_SENDER_ADDRESS));
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SMSC:  /* SMSC_ADD */
            mmi_ucs2cat((PS8) subMenuData, (PS8) GetString(STR_ID_BRW_PUSH_SMSC_ADDR));
            break;
    }
    mmi_ucs2cat((PS8) subMenuData, (PS8) colon_char_ucs2);
    mmi_ucs2cat((PS8) subMenuData, single_space_char_ucs2);

    length = strlen (address);

    if (length > MMI_PHB_NUMBER_LENGTH)
    {
        if (*(address + 0) == '+')
        {
            length = MMI_PHB_NUMBER_LENGTH + 1;
        }
        else
        {
            length = MMI_PHB_NUMBER_LENGTH;
        }
    }

    memset(buffer, 0, sizeof(buffer));
    mmi_asc_n_to_ucs2(
        (S8*) buffer,
        (S8*) address,
        length);

    mmi_ucs2cat((PS8) subMenuData, (PS8) buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_ota_ui_entry_info_screen_display
 * DESCRIPTION
 *  This API display the trustlist information.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_brw_push_ota_ui_entry_info_screen_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_BRW_PUSH_OPTION, SCR_ID_BRW_PUSH_OTA_INFO_DISPLAY, NULL, mmi_brw_push_ota_ui_entry_info_screen_display, 0))
    {
        return;
    }
	guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_BRW_PUSH_OPTION, SCR_ID_BRW_PUSH_OTA_INFO_DISPLAY);
    g_srv_wap_push_ota_cntxt.scr_deleted = MMI_FALSE;   /* MAUI_01330952 */

    mmi_wap_push_ota_create_display_info();

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_INSTALL,
        0,
        STR_ID_CCA_SKIP,
        0,
        (U8*) subMenuData,
        mmi_ucs2strlen((const S8*)subMenuData),
        guiBuffer);

    SetLeftSoftkeyFunction(srv_wap_push_ota_install_trustlist, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_wap_push_ota_display_info_scrn_rsk_hdlr, KEY_EVENT_UP);

	mmi_frm_scrn_set_leave_proc(GRP_ID_BRW_PUSH_OPTION, 
		SCR_ID_BRW_PUSH_OTA_INFO_DISPLAY, mmi_wap_push_scrhdlr_delete_static_screen_1);
}


void mmi_wap_push_ota_trustlist_prov_ui_done(U16 trustlist_count)
{
        if (trustlist_count > 0)
{

    MMI_TRACE(
        SRV_INET_TRC_G4_PUSH,
                    TRC_MMI_BRW_PUSH_OTA_NOT_IN_CALL_PROFILE_COUNT,
                    trustlist_count);

                             /* Not in call, delete all screens upto display info */

                g_srv_wap_push_ota_cntxt.scr_deleted = MMI_TRUE;
                mmi_wap_push_draw_dummy_screen(MMI_FALSE);
                g_srv_wap_push_ota_cntxt.scr_deleted = MMI_TRUE;
                mmi_frm_group_close(GRP_ID_BRW_PUSH_OPTION);
                mmi_wap_push_create_ota_group();
                mmi_brw_push_ota_ui_entry_info_screen_display();
                    }
                        else
                        {
            /* No more profiles to install. */


                MMI_TRACE(
                    SRV_INET_TRC_G4_PUSH,
                    TRC_MMI_BRW_PUSH_OTA_NOT_IN_CALL_PROFILE_COUNT,
                    trustlist_count);
                g_srv_wap_push_ota_cntxt.scr_deleted = MMI_TRUE;
            mmi_frm_group_close(GRP_ID_BRW_PUSH_OPTION);
    }
}

void mmi_wap_push_ota_ui_entry(void)
{
    mmi_wap_push_create_ota_group();
    mmi_brw_push_ota_ui_entry_info_screen_display();
    }



mmi_ret mmi_wap_push_ota_ui_entry_proc(mmi_event_struct* evt)
{
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_PROV_CUI_CREATE);
    mmi_wap_push_ota_ui_entry();
    return MMI_RET_OK;
}


mmi_ret mmi_wap_push_ota_trustlist_prov_ui_done_proc(mmi_event_struct* evt)
{
     MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_PROV_CUI_REDISPLAY);
     mmi_wap_push_ota_trustlist_prov_ui_done(g_srv_wap_push_ota_cntxt.total_trustlist_count);
     return MMI_RET_OK;
}
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 
#endif /* WAP_SUPPORT */ 

