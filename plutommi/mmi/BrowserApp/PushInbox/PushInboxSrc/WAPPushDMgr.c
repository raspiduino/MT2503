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
 * WAPPushDMgr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the various data manager API of Push message.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "MMI_include.h"
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "custom_phb_config.h"
    #include "common_nvram_editor_data_item.h"
    #include "pmg_struct.h"
    #include "kal_general_types.h"
#ifdef __WAP_PUSH_SUPPORT__
#include "MessagesResourceData.h"
//#include "IdleAppProt.h"
#include "CommonScreens.h"
//#include "time.h"
#include "WAPPushUIProts.h"


#ifdef __MMI_FTE_SUPPORT__
#include "wgui_categories_util.h"
#endif /*__MMI_FTE_SUPPORT__*/

    #include "WAPPushSrvProts.h"
    #include "Unicodexdcl.h"
    #include "WAPPushSrvTypes.h"
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #include "string.h"
    #include "GlobalResDef.h"
    #include "WAPPushUITypes.h"
    #include "InlineCuiGprot.h"
    #include "gui_data_types.h"
    #include "gui.h"
    #include "WAPPushScreenHdlr.h"
    #include "wap_adp.h"
    #include "mmi_rp_app_sms_def.h"
    #include "custom_events_notify.h"
    #include "wgui_inline_edit.h"
    #include "CustDataRes.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_util.h"
    #include "GlobalMenuItems.h"
    #include "ImeGprot.h"
    #include "wgui_categories_inputs.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "MMI_inet_app_trc.h"
    #include "mmi_frm_events_gprot.h"
    #include "custom_mmi_default_value.h"
    #include "app_datetime.h"
    #include "DateTimeType.h"
    #include "gui_typedef.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_public_api.h"
    #include "CustMenuRes.h"
//  #if defined(__VODAFONE_R12_LIVE__)  
 //   #include "op_custom_wap_config.h"
// #endif /* defined(__VODAFONE_R12_LIVE__) */

    #include "WAPPushResDef.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "menucuigprot.h"
 #include "gui_effect_oem.h"
#include "wgui_touch_screen.h"





/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_confirm_modify_add_trust_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_confirm_modify_add_trust_list(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rec_index = 0;
    U16 index = 0;
    S8 ascii_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0', };
    S8 smsc_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0', };
    S8 ascii_sep[2] = {WAP_PMG_ADDR_PHONE_SEP, '\0' };
    nvram_push_addr_struct *curr_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2strlen(g_push_set_p->sender_address) == 0) && ((mmi_ucs2strlen(g_push_set_p->smsc_address) == 0)))
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_ATLEAST_ONE_FIELD_REQUIRED);
        return;
    }
    if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_EDIT)
    {
        mmi_ucs2_to_asc(ascii_addr, (S8*) g_push_set_p->sender_address);
        strcat(ascii_addr, ascii_sep);
        mmi_ucs2_to_asc(smsc_addr, (S8*) g_push_set_p->smsc_address);
        strcat(ascii_addr, smsc_addr);
        strcat(ascii_addr, ascii_sep);
        if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
            curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
        }
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
            curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
        }
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        if (!(strcmp((S8*) curr_item->addr, ascii_addr)))   /* User edited again with same entry no need to modify */
        {
			if (g_push_cntxt->inline_gid != GRP_ID_INVALID)
			{
				cui_inline_close(g_push_cntxt->inline_gid);
			}
            g_push_cntxt->inline_gid = GRP_ID_INVALID;
            return;
        }
    }
    if (!srv_wap_push_check_valid_number(g_push_set_p->sender_address))
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_SETTING_INVALID_SENDER);
        return;
    }
    if (!srv_wap_push_check_valid_number(g_push_set_p->smsc_address))
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_SETTING_INVALID_SMSC);
        return;
    }
    mmi_wap_push_event_based_confirm (
        STR_GLOBAL_SAVE_ASK,
        mmi_wap_push_setting_modify_or_add_list,
        mmi_wap_push_go_back_two_screen,
		mmi_wap_push_setting_modify_or_add_list);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_confirm_ip_add_modify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_confirm_ip_add_modify(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ip_value[4] = { '\0', };
    U32 ip_sum = 0;
    S8 ip_sep[2] = { '.', '\0' };
    S8 temp_ip_part[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS] = { '\0', };
    S8 ip_addr[MAX_PUSH_IP_ADDR_NUM_LEN * ENCODING_LENGTH];
    U16 rec_index = 0;
    U16 index = 0;
    nvram_push_addr_struct *curr_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ip_value[0] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP1);
    ip_value[1] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP2);
    ip_value[2] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP3);
    ip_value[3] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP4);

    ip_sum = ip_value[0] + ip_value[1] + ip_value[2] + ip_value[3];

    if (ip_sum == 0x00)
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_INVALID_IP);
        return;
    }
    if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_EDIT)
    {
        if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
            curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
        }
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
            curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
        }
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        mmi_ucs2_to_asc((S8*) ip_addr, g_push_set_p->IP1);
        strcat((S8*) ip_addr, (S8*) ip_sep);

        mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP2);
        strcat(ip_addr, temp_ip_part);
        strcat((S8*) ip_addr, (S8*) ip_sep);

        mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP3);
        strcat(ip_addr, temp_ip_part);
        strcat((S8*) ip_addr, (S8*) ip_sep);

        mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP4);
        strcat((S8*) ip_addr, temp_ip_part);
        if (!strcmp((S8*) ip_addr, (S8*) curr_item->addr))
        {
			if (g_push_cntxt->inline_gid != GRP_ID_INVALID)
			{
				cui_inline_close(g_push_cntxt->inline_gid);
			}
            g_push_cntxt->inline_gid = GRP_ID_INVALID;
            return;
        }
    }
    mmi_wap_push_event_based_confirm (
        STR_GLOBAL_SAVE_ASK,
        mmi_wap_push_setting_modify_or_add_ip_addr,
        mmi_wap_push_go_back_two_screen,
		mmi_wap_push_setting_modify_or_add_ip_addr);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_inline_screen_done_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  hdlr        [OUT]
 *  scr_id      [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_set_inline_screen_done_hdlr (Default_func_ptr *hdlr, U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
    case SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM:
        *hdlr = mmi_wap_push_confirm_modify_add_trust_list;
        break;
    case SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR:
        *hdlr = mmi_wap_push_confirm_ip_add_modify;
        break;
    default:
        *hdlr = NULL;
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_number_of_inline_scr_item
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
U16 mmi_wap_push_get_number_of_inline_scr_item (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(screen_id)
    {
    case SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM:
        return MMI_BRW_PUSH_ADD_NEW_PH_NUM_END;
        
    case SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR:
        return MMI_BRW_PUSH_ADD_NEW_IP_END;
        
    case SCR_ID_BRW_PUSH_ADD_BOOKMARK:
        return MMI_BRW_PUSH_ADD_BKM_END;
        
    default:
        break;
        
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_bkm_set_buffers
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_add_bkm_set_buffers (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_push_cntxt->add_bkm.title, 0, ((MMI_BRW_PUSH_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH));
    memset(g_push_cntxt->add_bkm.url, 0, ((WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH));
    if (g_srv_wap_push_cntxt->selected_message.url != NULL)
    {
        mmi_asc_n_to_ucs2(g_push_cntxt->add_bkm.url, g_srv_wap_push_cntxt->selected_message.url, WAP_MAX_URL_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_progress_scr_img_and_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_id      [IN]         
 *  str_id         [OUT]        
 *  img_id         [OUT]         
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_progress_scr_img_and_str_id (U16 screen_id, U16 *str_id, U16 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(screen_id)
    {
    case SCR_ID_PUSH_POPUP_SCREEN:
        *str_id = g_push_cntxt->msg_str_id;
        *img_id = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
        break;
    default:
        *str_id = STR_GLOBAL_PLEASE_WAIT;
        *img_id = (U16) mmi_get_event_based_image((mmi_event_notify_enum)mmi_wap_push_map_internal_event (SRV_WAP_PUSH_EVENT_PROGRESS));
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_notification_scr_img_and_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_id      [IN]         
 *  str_id         [OUT]        
 *  img_id         [OUT]         
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_notification_scr_img_and_str_id (U16 screen_id, U16 *str_id, U16 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(screen_id)
    {
    case SCR_ID_BRW_NEW_PUSH_MESSAGE_IND:
        *str_id = STR_ID_PUSH_SERVICE_MESSAGE_RCVD;
        *img_id = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
        break;
    case SCR_ID_BRW_PUSH_MSG_DELETED:
        *str_id = STR_ID_BRW_PUSH_MSG_DELETED;
        *img_id = IMG_GLOBAL_INFO;
        break;
    default:
        *str_id = 0;
        *img_id = 0;
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_add_bkm_image_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list        [IN]        
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_add_bkm_image_icon (U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE_CAPTION] = gIndexIconsImageList[count];
	image_list[MMI_BRW_PUSH_INLINE_ADD_BKM_ADDRESS_CAPTION] = gIndexIconsImageList[++count];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fill_inline_struct_for_add_bookmark
 * DESCRIPTION
 *  Function to fill values in common inline structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_fill_inline_struct_for_add_bookmark (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For title caption */
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE_CAPTION], (U8*) GetString(STR_ID_BRW_PUSH_TITLE));

    /* For title string */
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE],
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_push_cntxt->add_bkm.title,
        MMI_BRW_PUSH_MAX_TITLE_LENGTH + 1,
        (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_ONE_LESS_CHARACTER),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE], mmi_wap_push_full_screen_edit);

    /* For Address caption */
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_ADDRESS_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_ADDRESS_CAPTION], (U8*) GetString(STR_GLOBAL_ADDRESS));

    /* For Address string (URL) */
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_URL], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_URL],
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_push_cntxt->add_bkm.url,
        WAP_MAX_URL_LENGTH + 1,
        IMM_INPUT_TYPE_URL,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[MMI_BRW_PUSH_INLINE_ADD_BKM_URL], mmi_wap_push_full_screen_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fill_inline_item_for_add_bkm
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_fill_inline_item_for_add_bkm (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_fill_inline_struct_for_add_bookmark();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_check_selected_msg_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  True if selected message data is ready.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_check_selected_msg_data_ready (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_push_cntxt->selected_message.msg_type != WAP_PMG_MSGTYPE_NULL)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_data_of_selected_message
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_data_of_selected_message (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_push_cntxt->read_from_um)
    {
        trans_id = PUSH_GET_MSG_TO_DISPLAY_FROM_UM_TRANS_ID;
    }
    else
    {
        trans_id = PUSH_GET_MSG_TO_DISPLAY_TRANS_ID;
    }
    srv_wap_push_get_full_message (g_srv_wap_push_cntxt->selected_message_id, trans_id);
}

#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_construct_dlg_display_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_construct_dlg_display_data(void)
{
	/*----------------------------------------------------------------*/
	/*Local Variables                                                 */
    /*----------------------------------------------------------------*/
	S8 port[12] = {'\0',};
	S8 sender_addr[WAP_PMG_MAX_ADDR_CHARS + 1] = {'\0',};
	S8 ucs2_sender_addr[((WAP_PMG_MAX_ADDR_CHARS + 1) * ENCODING_LENGTH) + 2] = {'\0','\0',};
	S8 sep[2] = {WAP_PMG_ADDR_PHONE_SEP,'\0'};
	pmg_addr_struct  *smsc = NULL;
	pmg_addr_struct  *sender = NULL;
	wps_pmg_dlg_unknown_addr_req_struct *unknown_data = NULL;
	wps_pmg_dlg_sia_confirm_req_struct *sia_data = NULL;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_START_CONSTRUCT_DISPLAY_DATA_FOR, g_srv_wap_push_cntxt->curr_dlg->dlg_type);
	memset((S8*)subMenuData, 0, sizeof(subMenuData));
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	if(g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_UNKNOWN_ADDR)
	{
		mmi_ucs2cpy((S8*) subMenuData, (S8*)GetString(STR_ID_BRW_PUSH_SERVICE_MSG_FROM));
		mmi_ucs2cat((S8*) subMenuData, "\n");
		unknown_data = (wps_pmg_dlg_unknown_addr_req_struct*)(&(g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg));
		smsc = &(unknown_data->smsc);
		sender = &(unknown_data->from);
		if((sender->addr_type == WAP_PMG_ADDR_PHONE) || (smsc->addr_type == WAP_PMG_ADDR_PHONE))
		{
			if(sender->addr && sender->addr[0] != '\0')
			{
				strcpy((S8*) sender_addr, (S8*) sender->addr);
			}
			if((sender_addr[0] == '\0') && (smsc->addr && smsc->addr[0] != '\0'))
			{
				strcpy((S8*) sender_addr, (S8*) sep);
			}
			else if(smsc->addr && smsc->addr[0] != '\0')
			{
				strcat((S8*) sender_addr, (S8*) sep);
			}
			if(smsc->addr && smsc->addr[0] != '\0')
			{
				strcat((S8*) sender_addr, (S8*) smsc->addr);
			}
		}
		else
		{
			if(sender->addr && sender->addr[0] != '\0')
			{
				strcpy((S8*) sender_addr, (S8*) sender->addr);
		    }
			else
		    {
				strcpy((S8*) sender_addr, (S8*) smsc->addr);
			}
		}

		mmi_asc_to_ucs2((S8*)ucs2_sender_addr, (S8*)sender_addr);
		mmi_ucs2cat((S8*) subMenuData, (S8*)ucs2_sender_addr);
	
		mmi_ucs2cat((S8*) subMenuData, "\n");
		mmi_ucs2cat((S8*) subMenuData, "\n");
		memset(ucs2_sender_addr,'\0',sizeof(ucs2_sender_addr));
//#ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
		if(unknown_data->msg_type == WAP_PMG_MSGTYPE_SL)
		{
			if(unknown_data->href[0] != '\0')
			{
				mmi_asc_n_to_ucs2(ucs2_sender_addr, (S8*)unknown_data->href, NVRAM_PUSH_SENDER_ADDR_LEN_MAX);
			}
			mmi_ucs2cat((S8*) subMenuData, (S8*)L"[");
			mmi_ucs2cat((S8*) subMenuData, (S8*)ucs2_sender_addr);
			mmi_ucs2cat((S8*) subMenuData, (S8*)L"]");
		}
		else if(unknown_data->msg_type == WAP_PMG_MSGTYPE_SI)
		{
			if(unknown_data->text[0] != '\0')
			{
				if (unknown_data->text_type == WAP_PMG_STRTYPE_ASCII)
				{
					mmi_asc_n_to_ucs2(
						ucs2_sender_addr, 
						(S8*)unknown_data->text, 
						NVRAM_PUSH_SENDER_ADDR_LEN_MAX);
				}
				else if (unknown_data->text_type == WAP_PMG_STRTYPE_UCS2)
				{
					mmi_ucs2ncpy(
						(S8*) ucs2_sender_addr,
						(S8*) unknown_data->text,
						NVRAM_PUSH_SENDER_ADDR_LEN_MAX / ENCODING_LENGTH);
				}				
			}
			else
			{
				if(unknown_data->href[0] != '\0')
				{
					mmi_asc_n_to_ucs2(ucs2_sender_addr, (S8*)unknown_data->href, NVRAM_PUSH_SENDER_ADDR_LEN_MAX);
			    }
		    }
			if(strlen(ucs2_sender_addr))
			{
		mmi_ucs2cat((S8*) subMenuData, (S8*)L"[");
		mmi_ucs2cat((S8*) subMenuData, (S8*)ucs2_sender_addr);
		mmi_ucs2cat((S8*) subMenuData, (S8*)L"]");
	    }
	    }
//#endif /* __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__ */
		else if(unknown_data->msg_type == WAP_PMG_MSGTYPE_SIA)
		{
			mmi_ucs2cat((S8*) subMenuData, "\n");
			mmi_ucs2cat((S8*) subMenuData, "\n");
			mmi_ucs2cat((S8*) subMenuData, (S8*)GetString(STR_ID_BRW_PUSH_SIA_REQ_TITLE));
		}
		else if(unknown_data->msg_type == WAP_PMG_MSGTYPE_CO)
		{
			mmi_ucs2cat((S8*) subMenuData, "\n");
			mmi_ucs2cat((S8*) subMenuData, "\n");
			mmi_ucs2cat((S8*) subMenuData, (S8*)GetString(STR_ID_BRW_PUSH_CO_REQ));
		}

	}
	else if(g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_SIA)
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
	{
		sia_data = (wps_pmg_dlg_sia_confirm_req_struct*)(&(g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia));
		mmi_ucs2cpy((S8*) subMenuData, (S8*)GetString(STR_ID_BRW_PUSH_CONFIRM_SIA_REQ));
		mmi_ucs2cat((S8*) subMenuData, "\n");
		mmi_ucs2cat((S8*) subMenuData, "\n");

		mmi_ucs2cat((S8*) subMenuData, (S8*)GetString(STR_ID_BRW_PUSH_HOST_ADDR));
		mmi_ucs2cat((S8*) subMenuData, "\n");
		mmi_asc_to_ucs2(ucs2_sender_addr, (S8*)sia_data->host_addr.addr);
		mmi_ucs2cat((S8*) subMenuData, (S8*)ucs2_sender_addr);
		mmi_ucs2cat((S8*) subMenuData, "\n");
		mmi_ucs2cat((S8*) subMenuData, "\n");

		mmi_ucs2cat((S8*) subMenuData, (S8*)GetString(STR_ID_BRW_PUSH_HOST_PORT));
		mmi_ucs2cat((S8*) subMenuData, "\n");
		gui_itoa((U32)sia_data->host_port,(U16*)port,10);
		mmi_ucs2cat((S8*) subMenuData, port);
	}
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_END_CONSTRUCT_DISPLAY_DATA);
}
#endif
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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_create_display_format_from_selected_message
 * DESCRIPTION
 *  Create the display buffer for category.
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_create_display_format_from_selected_message (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 size = 0;
	U16 len = 0;
    S8 *ucs2_msg = NULL;
    S8 ucs2_time_string[SI_DATE_N_TIME_STRING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_CREATE_DISPLAY_FORMAT);
    /* Displaying Sender address */
    if (g_srv_wap_push_cntxt->selected_message.from.addr != NULL)
    {
        size = strlen ((S8*)g_srv_wap_push_cntxt->selected_message.from.addr);
        mmi_ucs2cpy((S8*) subMenuData, GetString(STR_ID_BRW_PUSH_SENDER_ADDR));
        mmi_ucs2cat((S8*) subMenuData, "\n");

        ucs2_msg = (S8*) OslMalloc((size + 1) *ENCODING_LENGTH);
        memset (ucs2_msg, 0, ((size + 1) *ENCODING_LENGTH));
		mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_srv_wap_push_cntxt->selected_message.from.addr);
		mmi_ucs2cat((S8*) subMenuData, ucs2_msg);
		mmi_ucs2cat((S8*)subMenuData, "\n");
		mmi_ucs2cat((S8*)subMenuData, "\n");
		OslMfree(ucs2_msg);
        ucs2_msg = NULL;
    }
    
    /* Displaying Created time */
    mmi_ucs2cat((S8*)subMenuData, GetString(STR_ID_BRW_PUSH_CREATED_TIME));
    mmi_ucs2cat((S8*)subMenuData, "\n");

    srv_wap_push_create_ucs2_time_format_string (g_srv_wap_push_cntxt->selected_message.created, ucs2_time_string);
    mmi_ucs2cat((S8*)subMenuData, ucs2_time_string);
    mmi_ucs2cat((S8*)subMenuData, "\n");
	mmi_ucs2cat((S8*)subMenuData, "\n");

    /* Displaying Expired time */
    if ((g_srv_wap_push_cntxt->selected_message.msg_type == WAP_PMG_MSGTYPE_SI) && (g_srv_wap_push_cntxt->selected_message.expired != 0))
    {
        mmi_ucs2cat((S8*)subMenuData, GetString(STR_ID_BRW_PUSH_EXPIRY_TIME));
        mmi_ucs2cat((S8*)subMenuData, "\n");

        srv_wap_push_create_ucs2_time_format_string (g_srv_wap_push_cntxt->selected_message.expired, ucs2_time_string);
        mmi_ucs2cat((S8*)subMenuData, ucs2_time_string);
        mmi_ucs2cat((S8*)subMenuData, "\n");
	    mmi_ucs2cat((S8*)subMenuData, "\n");
    }

    /* Displaying Message priority */
    mmi_ucs2cat((S8*) subMenuData, GetString(STR_ID_BRW_PUSH_PRIORITY_TITLE));
    mmi_ucs2cat((S8*)subMenuData, "\n");

    if (g_srv_wap_push_cntxt->selected_message.priority == WAP_PMG_MSGPRIO_LOW)
    {
        mmi_ucs2cat((S8*) subMenuData, GetString(STR_GLOBAL_LOW));
    }
    else if (g_srv_wap_push_cntxt->selected_message.priority == WAP_PMG_MSGPRIO_MEDIUM)
    {
        mmi_ucs2cat((S8*) subMenuData, GetString(STR_GLOBAL_MEDIUM));
    }
    else if (g_srv_wap_push_cntxt->selected_message.priority == WAP_PMG_MSGPRIO_HIGH)
    {
        mmi_ucs2cat((S8*) subMenuData, GetString(STR_GLOBAL_HIGH));
    }
	mmi_ucs2cat((S8*) subMenuData, "\n");
	mmi_ucs2cat((S8*) subMenuData, "\n");

    /* Displaying Message URL */
#ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
    if (g_srv_wap_push_cntxt->selected_message.url != NULL)
    {
        size = strlen (g_srv_wap_push_cntxt->selected_message.url);
        mmi_ucs2cat((S8*) subMenuData, GetString(STR_ID_BRW_PUSH_URL_TITLE));
        mmi_ucs2cat((S8*)subMenuData, "\n");

        ucs2_msg = (S8*) OslMalloc((size + 1) *ENCODING_LENGTH);
        memset (ucs2_msg, 0, ((size + 1) *ENCODING_LENGTH));
        mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_srv_wap_push_cntxt->selected_message.url);
        mmi_ucs2cat((S8*) subMenuData, ucs2_msg);
        mmi_ucs2cat((S8*) subMenuData, "\n");
        mmi_ucs2cat((S8*) subMenuData, "\n");
        OslMfree(ucs2_msg);
        ucs2_msg = NULL;
    }
#endif /* __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__ */

    /* Displaying Message Text */
	if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_ASCII)
	{
		len = strlen((S8*)g_srv_wap_push_cntxt->selected_message.text);
	}
	else if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_UCS2)
	{
		len = mmi_ucs2strlen((S8*)g_srv_wap_push_cntxt->selected_message.text);
	}
    if ((g_srv_wap_push_cntxt->selected_message.msg_type == WAP_PMG_MSGTYPE_SI) && 
        (g_srv_wap_push_cntxt->selected_message.text != NULL) && (len != 0))
    {
        mmi_ucs2cat((S8*) subMenuData, GetString(STR_ID_BRW_PUSH_MESSAGE_TITLE));
        mmi_ucs2cat((S8*)subMenuData, "\n");

        if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_ASCII)
        {
            size = strlen ((S8*)g_srv_wap_push_cntxt->selected_message.text);
            ucs2_msg = (S8*) OslMalloc((size + 1) * ENCODING_LENGTH);
            memset (ucs2_msg, 0, ((size + 1) *ENCODING_LENGTH));
            mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_srv_wap_push_cntxt->selected_message.text);
            mmi_ucs2cat((S8*) subMenuData, ucs2_msg);
            OslMfree(ucs2_msg);

        }
        else if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_UCS2)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) g_srv_wap_push_cntxt->selected_message.text);
        }
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXIT_CREATE_DISPLAY_FORMAT);
}

#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
void mmi_push_dmgr_get_slide_buttons_middle_string (U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_index = 0;
    U16 total_num = 0;
    S8 tmp_str[10] = {'\0','\0', };
    //S8 buffer[40] = {'\0','\0', };
    S8 sep[4] = {'/', '\0', '\0', '\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_um_get_slide_buttons_data (&current_index, &total_num);
    gui_itoa(current_index, (UI_string_type) tmp_str, 10);
    mmi_ucs2cpy ((S8*)string, (S8*)tmp_str);
    memset (tmp_str, 0, 10);
    mmi_ucs2cat((S8*)string, (S8*) sep);
    gui_itoa(total_num, (UI_string_type) tmp_str, 10);
    mmi_ucs2cat((S8*)string, (S8*) tmp_str);
}


MMI_BOOL mmi_dmgr_if_lnk_available (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_index = 0;
    U16 total_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_wap_push_um_get_slide_buttons_data (&current_index, &total_num);
    return (current_index - 1);
}


MMI_BOOL mmi_dmgr_if_rnk_available (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_index = 0;
    U16 total_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_um_get_slide_buttons_data (&current_index, &total_num);
    if (current_index == total_num)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_message_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id         [IN]
 *  title_str      [OUT]
 *  lsk_str        [OUT]
 *  lsk_img        [OUT]
 *  rsk_str        [OUT]
 *  rsk_img        [OUT]
 *  handler        [OUT]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_message_screen_data (
        U16 scr_id, 
        U16 *title_str, 
        U16 *lsk_str, 
        U16 *lsk_img, 
        U16 *rsk_str, 
        U16 *rsk_img, 
        Default_func_ptr *handler,
        Default_func_ptr *csk_func,
        Default_func_ptr *lnk_func,
        Default_func_ptr *rnk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    case SCR_ID_BRW_READ_SERVICE_MESSAGE:
        {
            *title_str = STR_ID_PUSH_MESSAGE;
            *lsk_str = STR_GLOBAL_OPTIONS;
            *lsk_img = IMG_GLOBAL_OPTIONS;
            *rsk_str = STR_GLOBAL_BACK;
            *rsk_img = IMG_GLOBAL_BACK;
            *handler = mmi_wap_push_create_display_format_from_selected_message;
            *csk_func = mmi_wap_push_launch_selected_message;
#ifdef __MMI_PUSH_IN_UM__
        #ifdef __MMI_UM_ITERATOR_VIEWER__
            if (g_srv_wap_push_cntxt->read_from_um)
            {
                *lnk_func = mmi_wap_push_hanndle_lnk_on_viewer;
                *rnk_func = mmi_wap_push_hanndle_rnk_on_viewer;
            }
            else
            {
                *lnk_func = NULL;
                *rnk_func = NULL;
            }
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */
        }
        break;
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
    case SCR_ID_PUSH_DISPALY_SIA_CNF:
        {
            if(g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_SIA)
            {
                *title_str = STR_ID_BRW_PUSH_SIA_REQ_TITLE;
                *lsk_str = STR_GLOBAL_YES;
                *lsk_img = IMG_GLOBAL_YES;
                *rsk_str = STR_GLOBAL_NO;
                *rsk_img = IMG_GLOBAL_NO;
                *handler = mmi_wap_push_construct_dlg_display_data;
		        *lnk_func = NULL;
		        *rnk_func = NULL;
                *csk_func = NULL;
            }
            else
            {
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                *title_str = STR_ID_BRW_PUSH_UNMATCHED_ADDRESS;
                *lsk_str = STR_GLOBAL_OPTIONS;
                *lsk_img = IMG_GLOBAL_OPTIONS;
                *rsk_str = STR_GLOBAL_BACK;
                *rsk_img = IMG_GLOBAL_BACK;
                *lnk_func = NULL;
                *rnk_func = NULL;
                *handler = mmi_wap_push_construct_dlg_display_data;
                *csk_func = mmi_wap_push_accept_unknwn_addr_req;
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
            }
        }
        break;
 #endif
    default:
        ASSERT (0);
        break;
    }
}
#ifndef __MMI_WAP_PUSH_SIA_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_check_sia_dlg_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  True if selected message data is ready.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_check_sia_dlg_data_ready (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_data_of_sia_dlg
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_data_of_sia_dlg (void)
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
 *  mmi_wap_push_handle_rsk_on_sia_dlg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_handle_rsk_on_sia_dlg_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_UNKNOWN_ADDR)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        mmi_wap_push_go_back_unknwn_addr_screen();
    #endif
    }
    else if (g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_SIA)
    {
        mmi_wap_push_go_back_sia_req_screen();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_lsk_sia_dlg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_handle_lsk_sia_dlg_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_UNKNOWN_ADDR)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        mmi_wap_push_entry_unknwn_addr_opt_menu();
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    }
    else if (g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_SIA)
    {
        mmi_wap_push_sia_req_accept();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_end_key_sia_dlg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_end_key_sia_dlg_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_UNKNOWN_ADDR)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        mmi_wap_push_go_back_unknwn_addr_screen();
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    }
    else if (g_srv_wap_push_cntxt->curr_dlg->dlg_type == SRV_WAP_PUSH_DLG_TYPE_SIA)
    {
        mmi_wap_push_go_back_sia_req_screen();
    }
    else
    {
        ASSERT(0);
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_inbox_status
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_set_inbox_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    g_push_cntxt->notify_nmgr = MMI_BRW_PUSH_NOTIFY_NMGR_NOT_NOTIFY;
    srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
    mmi_wap_push_cancel_pending_events();
#ifdef __MMI_PUSH_IN_UM__
    g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
#endif

    if (g_push_inbox_ctxt->inbox_state == SRV_WAP_PUSH_INBOX_NEED_REFRESH)
    {
        /* This will force category to highlight the index pointed by ==> g_push_inbox_ctxt->sel_idx */
        mmi_wap_push_clear_inbox_history();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_inbox_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num             [OUT]
 *  selected        [OUT]
 *  img_id          [OUT]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_inbox_details (U16 *num, U16 *selected, U16 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *num = g_push_inbox_ctxt->num_of_messages;
    *selected = g_push_inbox_ctxt->sel_idx;

    *img_id = IMG_ID_BRW_PUSH_READ;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_service_message_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_read      [IN]
 *  sim_id       [IN]
 *  expire_time  [IN]
 * RETURNS
 *  Icon Image.
 *****************************************************************************/
U8* mmi_wap_push_get_service_message_image (U8 is_read, U32 sim_id, U32 expire_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_GET_LIST_ICON, (U16)is_read, (U16)sim_id, expire_time);
//#ifdef __MMI_WAP_DUAL_SIM__
#if 0
#if (MMI_MAX_SIM_NUM == 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* _GEMINI_*/  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*_GEMINI_*/
#endif

	 if (is_read == 0)
    {
        if (expire_time == 0 || expire_time > (S32) srv_wap_push_get_current_utc_time())
        {
            image_id = IMG_ID_BRW_PUSH_UNREAD;
        }
        else
        {
            image_id = IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
        }
    }
    else
    {
        if (expire_time == 0 || expire_time > (S32) srv_wap_push_get_current_utc_time())
        {
            image_id = IMG_ID_BRW_PUSH_READ;
        }
        else
        {
            image_id = IMG_ID_BRW_PUSH_EXPIRED_READ;
        }
	 }
    return get_image(image_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_async_items
 * DESCRIPTION
 *  Fill dynamic list items of each folder
 * PARAMETERS
 *  start_indx      [IN]            Start index of item to be retrieved.
 *  menuData        [IN/OUT]        UI structure to store the list data.
 *  num_item        [IN]            Number of items revrieved.
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_wap_push_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 counter = 0;
    U16 incr;
    U16 len = 0;
    pmg_msg_list_struct   *msg_data = NULL;
    S8 ucs2_string[(SRV_WAP_PUSH_TOTAL_CHAR_TO_DISPLAY_IN_LIST + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_push_inbox_ctxt->inbox_state != SRV_WAP_PUSH_INBOX_NEED_REFRESH) &&
        (start_indx >= (S32) g_push_inbox_ctxt->start_index) && 
        ((start_indx + num_item -1) <= (S32) g_push_inbox_ctxt->end_index))
    {
        g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_STATE_LIST_DISPLAYED;

        counter = start_indx - g_push_inbox_ctxt->start_index;
        for (incr = 0; incr < num_item; ++incr)
        {
            msg_data = &g_push_inbox_ctxt->list_item[counter];
            if (msg_data->msg_type == WAP_PMG_MSGTYPE_SI)
            {
                if (msg_data->text[0] != '\0')
                {
                    if (msg_data->text_type == WAP_PMG_STRTYPE_ASCII)
                    {
                        memset(ucs2_string, 0, sizeof(ucs2_string));
                        mmi_asc_to_ucs2((S8*) ucs2_string, (S8*) msg_data->text);
                        len = mmi_ucs2strlen((S8*) ucs2_string);

                        if (len > MAX_SUBMENU_CHARACTERS - 1)
                        {
                            mmi_ucs2ncpy((S8*) menuData[incr].item_list[0], (S8*) ucs2_string, MAX_SUBMENU_CHARACTERS - 3);
                            mmi_ucs2cat((S8*) menuData[incr].item_list[0], ".\0.\0.\0");
                        }
                        else
                        {
                            mmi_ucs2cpy((S8*) menuData[incr].item_list[0], (S8*) ucs2_string);
                        }

                    }
                    else if (msg_data->text_type == WAP_PMG_STRTYPE_UCS2)
                    {
                        len = mmi_ucs2strlen((S8*) msg_data->text);
                        if (len > MAX_SUBMENU_CHARACTERS - 1)
                        {
                            mmi_ucs2ncpy(
                                (S8*) menuData[incr].item_list[0],
                                (S8*) msg_data->text,
                                MAX_SUBMENU_CHARACTERS - 3);
                            mmi_ucs2cat((S8*) menuData[incr].item_list[0], ".\0.\0.\0");
                        }
                        else
                        {
                            mmi_ucs2cpy((S8*) menuData[incr].item_list[0], (S8*) msg_data->text);
                        }
                    }
                }
                else
                {
                #ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
                    memset(ucs2_string, 0, sizeof(ucs2_string));
                    mmi_asc_to_ucs2((S8*) ucs2_string, (S8*) msg_data->href);
                    len = mmi_ucs2strlen((S8*) ucs2_string);
                    if (len > MAX_SUBMENU_CHARACTERS - 1)
                    {
                        mmi_ucs2ncpy((S8*) menuData[incr].item_list[0], (S8*) ucs2_string, MAX_SUBMENU_CHARACTERS - 3);
                        mmi_ucs2cat((S8*) menuData[incr].item_list[0], ".\0.\0.\0");
                    }
                    else
                    {
                        mmi_ucs2cpy((S8*) menuData[incr].item_list[0], (S8*) ucs2_string);
                    }
                #else
                    mmi_ucs2cpy((S8*) menuData[incr].item_list[0], (S8*) GetString(STR_ID_PUSH_NO_SUBJECT));
                #endif /* __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__ */
                }

                menuData[incr].image_list[0] = mmi_wap_push_get_service_message_image (msg_data->read, msg_data->sim_id, msg_data->expired);
            }
            else if (msg_data->msg_type == WAP_PMG_MSGTYPE_SL)
            {
            #ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
                memset(ucs2_string, 0, sizeof(ucs2_string));

                mmi_asc_to_ucs2((S8*) ucs2_string, (S8*) msg_data->href);
                len = mmi_ucs2strlen((S8*) ucs2_string);

                if (len > MAX_SUBMENU_CHARACTERS - 1)
                {
                    mmi_ucs2ncpy((S8*) menuData[incr].item_list[0], (S8*) ucs2_string, MAX_SUBMENU_CHARACTERS - 3);
                    mmi_ucs2cat((S8*) menuData[incr].item_list[0], ".\0.\0.\0");
                }
                else
                {
                    mmi_ucs2cpy((S8*) menuData[incr].item_list[0], (S8*) ucs2_string);
                }
            #else
                mmi_ucs2cpy((S8*) menuData[incr].item_list[0], (S8*) GetString(STR_ID_PUSH_NO_SUBJECT));
            #endif /* __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__ */
             menuData[incr].image_list[0] = mmi_wap_push_get_service_message_image (msg_data->read, msg_data->sim_id, 0);

            }
           //changes
       
        #if (MMI_MAX_SIM_NUM >= 2)
            if (msg_data->sim_id == WAP_PMG_SIM1)
            {
                menuData[incr].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM1);  
            }
            else if (msg_data->sim_id == WAP_PMG_SIM2)
            {
                menuData[incr].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM2);  
            }
        #if (MMI_MAX_SIM_NUM >= 3) 
            else if (msg_data->sim_id == WAP_PMG_SIM3)
            {
                menuData[incr].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM3);  
            }
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)    
            else if (msg_data->sim_id == WAP_PMG_SIM4)
            {
                menuData[incr].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM4);  
            }
        #endif
            else
            {
                menuData[incr].image_list[1] = NULL;
            }
        #endif        /*   (MMI_MAX_SIM_NUM >= 2)  */ 
            counter++;
        }
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ASYNC_DYNAMIC_CATEGORY_CALLBACK_REPLIED_SUCCESS);
        return num_item;
    }
    else
    {
        if (g_push_inbox_ctxt->inbox_state != SRV_WAP_PUSH_INBOX_STATE_LOADING)
        {
            g_push_inbox_ctxt->msg_cnt_requested = SRV_WAP_PUSH_TOTAL_PUSH_LIST;

            g_push_inbox_ctxt->start_index = 0;
            g_push_inbox_ctxt->end_index = 0;

            if (g_push_inbox_ctxt->num_of_messages <= SRV_WAP_PUSH_TOTAL_PUSH_LIST)
            {
                g_push_inbox_ctxt->msg_cnt_requested = g_push_inbox_ctxt->num_of_messages;
            }
            if (start_indx > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
            {
                g_push_inbox_ctxt->read_index = start_indx - MAX_ASYNCDYNAMIC_ITEMS_BUFF;
            }
            else
            {
                g_push_inbox_ctxt->read_index = 0;
            }
            g_push_inbox_ctxt->curr_index = 0;

            if (g_push_inbox_ctxt->num_of_messages < (U32)(g_push_inbox_ctxt->read_index + g_push_inbox_ctxt->msg_cnt_requested))
            {
                g_push_inbox_ctxt->msg_cnt_requested = g_push_inbox_ctxt->num_of_messages - g_push_inbox_ctxt->read_index;
            }
            srv_wap_push_get_list_from_service_layer (g_push_inbox_ctxt->read_index, 
				g_push_inbox_ctxt->msg_cnt_requested,
				PUSH_MSG_LIST_INBOX_DSPLY_TRANS_ID, 
				WAP_PMG_PARAM_NOT_SPECIFIED);
        }
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ASYNC_DYNAMIC_CATEGORY_CALLBACK_REPLIED_FAILED);
    #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
        g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_STATE_LOADING;
        return WGUI_GET_DATA_LOADING;
    #else
        if (g_push_inbox_ctxt->inbox_state != SRV_WAP_PUSH_INBOX_NEED_REFRESH)
        {
            mmi_wap_push_display_async_loading_screen ();
        }
        g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_STATE_LOADING;
        return WGUI_GET_DATA_NONE;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_title_str_id_for_msg_deleted_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  title string.
 *****************************************************************************/
U16 mmi_wap_push_get_title_str_id_for_msg_deleted_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_push_cntxt->read_from_um)
    {
        return STR_GLOBAL_INBOX;
    }
    else
    {
        return STR_ID_PUSH_INBOX;
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
#if (MMI_MAX_SIM_NUM == 2)  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __GEMINI__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_list_item
 * DESCRIPTION
 *  Callback used by push setting category screen to get selected list dynamically.
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_wap_push_get_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_str[(NVRAM_PUSH_SENDER_ADDR_LEN_MAX + 2) * ENCODING_LENGTH] = { '\0', '\0', };
    U16 record_index = 0;
    U16 index = 0;
    U16 string_len = 0;
    nvram_push_addr_struct *curr_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *img_buff_p = get_image(gIndexIconsImageList[item_index % 31]);     /* Raise question when index > 30 */
    memset(str_buff, 0, (MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH));

    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        if (g_push_set_p->total_wl_entry < NVRAM_PUSH_MAX_NUM_WHITE_LIST)
        {
            if (item_index == 0)
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_ID_PUSH_INBOX_ADD_NEW));
                return TRUE;
            }
            item_index--;
        }
        srv_wap_push_get_record_and_index(&record_index, &index, item_index);
        curr_item = &g_push_set_p->white_list[record_index].white_list[index];
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        if (g_push_set_p->total_bl_entry < NVRAM_PUSH_MAX_NUM_BLACK_LIST)
        {
            if (item_index == 0)
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_ID_PUSH_INBOX_ADD_NEW));
                return TRUE;
            }
            item_index--;
        }
        srv_wap_push_get_record_and_index(&record_index, &index, item_index);
        curr_item = &g_push_set_p->black_list[record_index].black_list[index];
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    if (curr_item->addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER)
    {
        string_len = strlen((S8*) curr_item->addr);
        srv_wap_push_get_display_ansii_number_format(ucs2_str, (S8*) curr_item->addr, string_len);
        string_len = mmi_ucs2strlen(ucs2_str);

        if (string_len > MAX_SUBMENU_CHARACTERS)
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) ucs2_str, (MAX_SUBMENU_CHARACTERS - 3));
            mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
        }
        else
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) ucs2_str, string_len);
        }
    }
    else if (curr_item->addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS)
    {
        mmi_asc_to_ucs2((S8*) str_buff, (S8*) curr_item->addr);
    }
    return TRUE;
#else 
	return TRUE;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_title_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  Current title icon id.
 *****************************************************************************/
U16 mmi_wap_push_get_title_icon (U16 default_title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 2)
    if (g_push_inbox_ctxt->title_icon_id == 0)
    {
        return default_title_id;//GetRootTitleIcon(default_title_id);
    }
    else
    {
        return g_push_inbox_ctxt->title_icon_id;
    }
#else 
    return default_title_id;//GetRootTitleIcon(default_title_id);
#endif /* __MMI_WAP_DUAL_SIM__ */
}

void mmi_wap_push_set_title_icon (U16 title_icon_id)
{
    g_push_inbox_ctxt->title_icon_id = title_icon_id;
}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fill_add_ph_no_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_fill_add_ph_no_screen_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemCaption(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR_CAPTION], (U8*) GetString(STR_ID_BRW_PUSH_SENDER_ADDRESS));
    SetInlineItemCaption(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR_CAPTION], (U8*) GetString(STR_ID_BRW_PUSH_SMSC_ADDR));
    LeftJustifyInlineItem((wgui_inline_items + 1));

    SetInlineItemTextEdit(
        &wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR],
        (U8*) g_push_set_p->sender_address,
        (MMI_PHB_NUMBER_LENGTH + 1),
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);

    LeftJustifyInlineItem(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR]);
    SetInlineItemTextEdit(
        &wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR],
        (U8*) g_push_set_p->smsc_address,
        (MMI_PHB_NUMBER_LENGTH + 1),
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_exit_add_ph_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_exit_add_ph_no(void)
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
 *  mmi_wap_push_fill_ip_addr_inline_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_fill_ip_addr_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 proxy_ip[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_IP_ADDR], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_IP_ADDR_CAPTION], (U8*) GetString(STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS));

    if (srv_wap_push_convert_proxy_ipstring_to_array((U8*) g_push_set_p->ip_addr, proxy_ip) != SRV_WAP_PUSH_ERR)
    {
        ReturnThreeDigitString((U8*) g_push_set_p->IP1, proxy_ip[0]);
        ReturnThreeDigitString((U8*) g_push_set_p->IP2, proxy_ip[1]);
        ReturnThreeDigitString((U8*) g_push_set_p->IP3, proxy_ip[2]);
        ReturnThreeDigitString((U8*) g_push_set_p->IP4, proxy_ip[3]);
    }
    else
    {
        ReturnThreeDigitString((U8*) g_push_set_p->IP1, (U8) g_push_set_p->ip_addr[0]);
        ReturnThreeDigitString((U8*) g_push_set_p->IP2, (U8) g_push_set_p->ip_addr[1]);
        ReturnThreeDigitString((U8*) g_push_set_p->IP3, (U8) g_push_set_p->ip_addr[2]);
        ReturnThreeDigitString((U8*) g_push_set_p->IP4, (U8) g_push_set_p->ip_addr[3]);
    }

    SetInlineItemIP4(
        &wgui_inline_items[MMI_BRW_PUSH_ADD_NEW_IP_ADDR],
        (U8*) g_push_set_p->IP1,
        (U8*) g_push_set_p->IP2,
        (U8*) g_push_set_p->IP3,
        (U8*) g_push_set_p->IP4,
        PreparedIPAddressString);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_exit_add_new_by_ip_addr_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_exit_add_new_by_ip_addr_screen(void)
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
 *  mmi_wap_push_set_crnt_hilited_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_set_crnt_hilited_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        if (g_push_set_p->total_wl_entry < NVRAM_PUSH_MAX_NUM_WHITE_LIST)
        {
            if (index == 0)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
                ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
                SetLeftSoftkeyFunction(mmi_wap_push_setting_entry_wl_add_new_menu, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_wap_push_setting_entry_wl_add_new_menu, KEY_EVENT_UP);
                return;
            }
            g_push_set_p->selected_wl_entry = index - 1;
        }
        else
        {
            g_push_set_p->selected_wl_entry = index;
        }
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        if (g_push_set_p->total_bl_entry < NVRAM_PUSH_MAX_NUM_BLACK_LIST)
        {
            if (index == 0)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
                ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
                SetLeftSoftkeyFunction(mmi_wap_push_setting_entry_wl_add_new_menu, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_wap_push_setting_entry_wl_add_new_menu, KEY_EVENT_UP);
                return;
            }
            g_push_set_p->selected_bl_entry = index - 1;
        }
        else
        {
            g_push_set_p->selected_bl_entry = index;
        }
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_OTA)
    {
        ChangeLeftSoftkey(STR_GLOBAL_REPLACE, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_NO);
        SetLeftSoftkeyFunction(srv_wap_push_replace_selected_wl_addr, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(srv_wap_push_replace_selected_wl_addr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(srv_wap_push_cancel_ota_replace, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_wap_push_setting_entry_wl_opt_menu, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_wap_push_modify_pre_entry, KEY_EVENT_UP);
    }
}

mmi_ret mmi_push_setting_list_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_SETTING_LIST;
            break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_frm_group_close (GRP_ID_BRW_PUSH_SETTING_LIST);
            //g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        default:
            {
                if (evt->user_data)
                {
					mmi_wap_push_screenDB_struct *scrDB = evt->user_data;
					if (NULL != scrDB->screen)
					{

						cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

						if (((mmi_wap_push_scrhdlr_static_screen_struct *)scrDB->screen)->leaf_node_hdlr)
						{
							((mmi_wap_push_scrhdlr_static_screen_struct *)scrDB->screen)->leaf_node_hdlr(evt);
						}
						if (menu_evt->evt_id == EVT_ID_CUI_MENU_CLOSE_REQUEST)
						{
							OslMfree(scrDB->screen);
							scrDB->screen = NULL;
						}
					}
                }
            }
            break;

    }


    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_entry_list_screen
 * DESCRIPTION
 *  Entry to the current selected list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_entry_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id, &node_info)!= MMI_RET_ERR)
    {
        mmi_frm_group_create(g_push_cntxt->scr_grp_id, GRP_ID_BRW_PUSH_SETTING_LIST, mmi_push_setting_list_group_proc, NULL);
    }
    else
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_SETTING_LIST, mmi_push_setting_list_group_proc, NULL);
    }

    mmi_frm_group_enter(GRP_ID_BRW_PUSH_SETTING_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //mmi_frm_group_set_caller (GRP_ID_BRW_PUSH_INBOX, g_push_cntxt->scr_grp_id);
    g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_SETTING_LIST;


    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTERS_LIST_SCREEN, g_push_set_p->selected_list_type);
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        mmi_wap_push_setting_entry_white_list();
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        mmi_wap_push_setting_entry_black_list();
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_pre_entry_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_pre_entry_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_entry_list_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_confirm_before_list_edit
 * DESCRIPTION
 *  Display a confirmation before editing White list or Black list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_confirm_before_list_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST) &&
        mmi_wap_push_is_screen_present (SCR_ID_BRW_PUSH_OTA_INFO_DISPLAY))
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
        return;
    }
    mmi_wap_push_event_based_confirm (
        STR_ID_BRW_PUSH_CONFIRM_LIST_MODIFY,
        mmi_wap_push_pre_entry_list_screen,
        mmi_push_close_active_screen,
	    mmi_wap_push_pre_entry_list_screen);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */



#ifdef __MMI_WAP_PUSH_WHITE_LIST__
#ifdef __MMI_FTE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_push_is_current_item_add_new
 * DESCRIPTION
 * 
 * PARAMETERS
 *  index          [IN]
 * RETURNS
 *  true if curent item is ADD new otherwise return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_push_is_current_item_add_new (S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST) && 
        (g_push_set_p->total_wl_entry < NVRAM_PUSH_MAX_NUM_WHITE_LIST) &&
        (index == 0))
    {
        return MMI_TRUE;
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else if (g_push_set_p->total_bl_entry < NVRAM_PUSH_MAX_NUM_BLACK_LIST &&
        (index == 0))
    {
        return MMI_TRUE;
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_FTE_SUPPORT__) &&  defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_push_handle_tap_on_validation_list_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  tap_type       [IN]
 *  index          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_handle_tap_on_validation_list_screen (mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_OTA)
    {
        srv_wap_push_replace_selected_wl_addr();
    }
	else if (mmi_push_is_current_item_add_new(index))
	{
        mmi_wap_push_setting_entry_wl_add_new_menu();
	}
	else if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
	{
        mmi_wap_push_modify_pre_entry();
	} 
}
#endif
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */





#endif /* WAP_SUPPORT*/
