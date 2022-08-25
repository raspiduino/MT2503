/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * q03c_mms_v01_agentMain.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#if defined(OBIGO_Q03C_MMS_V01)

#include "mmi_frm_gprot.h"
#include "custom_wap_config.h"
#include "CommonScreens.h"
#include "app_str.h"
#include "conversions.h"
#include "q03c_mms_V01_agentprot.h"
#include "q03c_mms_V01_agentSettings.h"
#include "DRM_def.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __MMI_URI_AGENT__
#include "URIAgentGProt.h"
#endif /* #ifdef __MMI_URI_AGENT__ */

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "UMGProt.h"
#include "UcAppGprot.h"
#include "mms_api.h"
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
#include "q03c_mms_v01_agentobjind.h"
#include "q03c_mms_V01_agentResDef.h"
#include "mea_api.h"

/*******************************************************************************
 * Global Variable
 *******************************************************************************/
/* MMS V01 agent global context */
mmi_mms_v01_agent_context_struct g_mmi_mms_V01_agent_ctx;

/*******************************************************************************
 * Extern declaration
 *******************************************************************************/
#ifdef __MMI_URI_AGENT__
#ifdef __UNIFIED_COMPOSER_SUPPORT__
extern void mms_uri_parser(char *param, mms_entry_write_struct *data);
#else
extern kal_bool mms_uri_is_present_valid_address(char *text);
#endif
#endif /* #ifdef __MMI_URI_AGENT__ */
extern void goto_mms_editor(mms_content_entry_struct *data);

/*******************************************************************************
 * Functions
 *******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_q03c_mms_v01_agent_set_protocol_event_hdlr
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_q03c_mms_v01_agent_set_protocol_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_DUAL_SIM__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_SIM_STATUS_INFO_IND,
        (PsIntFuncPtr) mmi_mms_v01_agent_sim_status_info_hdlr,
        MMI_TRUE);
#endif /* __MMI_MMS_DUAL_SIM__ */ 
    SetProtocolEventHandler(mmi_mms_make_call_req_hdlr, MSG_ID_MMS_MAKE_CALL_REQ);
    SetProtocolEventHandler(mmi_mms_enter_sms_editor_hdlr, MSG_ID_MMS_ENTER_SMS_EDITOR_REQ);
	SetProtocolEventHandler(mmi_mms_obj_ind_res_hdlr, MSG_ID_MMS_OBJ_RES);
    SetProtocolEventHandler(mmi_mms_insert_text_req_hdlr,MSG_ID_MEA_INSERT_TEXT_REQ);
    SetProtocolEventHandler(mmi_mms_brw_launch_req_hdlr, MSG_ID_MMS_LAUNCH_BROWSER_REQ);
    SetProtocolEventHandler(mmi_mmsv01_set_profile_rsp_hdlr, MSG_ID_MEA_SET_PROFILE_RSP);
    SetProtocolEventHandler(mmi_mms_add_bookmark_req_hdlr, MSG_ID_MEA_ADD_BOOKMARK_REQ);

    /*Set settings rsp hdlr*/
    SetProtocolEventHandler(mmi_mms_set_settings_rsp_hdlr, MSG_ID_MEA_SET_SETTING_RSP);
    
    /*Get settings req hdlr*/
    SetProtocolEventHandler(mmi_mms_get_settings_req_hdlr, MSG_ID_MEA_GET_SETTING_REQ);

    /*MMMS Ready IND*/
    SetProtocolEventHandler(mmi_mms_ready_ind_hdlr, MSG_ID_MMS_READY_IND);

    /*MMS Terminate IND*/
    SetProtocolEventHandler(mmi_mms_terminate_ind_hdlr, MSG_ID_MMS_TERMINATE_IND);
    /*MEA terminate indication*/
    SetProtocolEventHandler(mmi_mms_mea_terminate_ind_hdlr, MSG_ID_MEA_TERMINATE_IND);

    /*For JSR*/
    SetProtocolEventHandler(mmi_mmsv01_jsr_get_mms_profile_req, MSG_ID_WAP_MMC_GET_MMS_PROF_REQ);


#ifdef __MMI_MMS_BGSR_SUPPORT__

    SetProtocolEventHandler(mmi_mms_bgsr_send_msg_req_hdlr, MSG_ID_MMS_BGSR_SEND_REQ);
    SetProtocolEventHandler(mmi_mms_bgsr_msg_req_hdlr, MSG_ID_MMS_BGSR_DOWNLOAD_REQ);
    SetProtocolEventHandler(mmi_mms_bgsr_cancel_send_msg_req_hdlr, MSG_ID_MMS_BGSR_CANCEL_SEND_REQ);
    SetProtocolEventHandler(mmi_mms_bgsr_cancel_download_msg_req_hdlr, MSG_ID_MMS_BGSR_CANCEL_DOWNLOAD_REQ);
    //SetProtocolEventHandler(/*handler*/ ,MSG_ID_MMS_BGSR_NAV_ACTIVATE_BGSR_REQ);
    // Remember to change the primitive
    SetProtocolEventHandler(mmi_mms_bgsr_change_msg_req_hdlr, MSG_ID_MMS_BGSR_DELETE_MSG_REQ);
    /* SetProtocolEventHandler(mmi_mms_bgsr_get_msg_info_req_hdlr ,MSG_ID_MMS_BGSR_GET_MSG_INFO_REQ); */

#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    /*Create*/
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_create_req_hdlr, MSG_ID_MMI_MMS_VENDOR_CREATE_REQ);
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_create_rsp_hdlr, MSG_ID_WAP_MMA_CREATE_RSP);

    /*Send*/
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_send_req_hdlr, MSG_ID_MMI_MMS_VENDOR_SEND_REQ);
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_send_rsp_hdlr, MSG_ID_WAP_MMA_SEND_RSP);

    /*Delete*/    
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_delete_req_hdlr, MSG_ID_MMI_MMS_VENDOR_DELETE_REQ);
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_delete_rsp_hdlr, MSG_ID_WAP_MMA_DELETE_RSP);

    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_cancel_send_req_hdlr, MSG_ID_MMI_MMS_VENDOR_CANCEL_SEND_REQ);
    SetProtocolEventHandler(mmi_mmsv01_agent_vendor_cancel_send_rsp_hdlr, MSG_ID_WAP_MMA_CANCEL_SEND_RSP);


    
#endif

}
#ifdef __MMI_MMS_V01_USE_ASM__
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_asm_init
 * DESCRIPTION
 *  Register with ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_asm_init(void)
{
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_ASM_INIT);
   
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_MMS_V01,
        STR_ID_MMSV01_AGENT_MMS_TITLE,
        IMG_ID_MMSV01_AGENT_TITLE_NORMAL,
        mmi_mmsv01_agent_asm_deinit);
}
#endif /* __MMI_MMS_V01_USE_ASM__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_mms_q03c_mms_v01_agent_init
 * DESCRIPTION
 *  MMS V01 Agent init function
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_q03c_mms_v01_agent_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Just a safe check */
    memset(&g_mmi_mms_V01_agent_ctx, 0, sizeof(mmi_mms_v01_agent_context_struct));

#ifdef __MMI_URI_AGENT__
    {
        int err_code;
        extern void mms_uri_insert_hdlr(kal_uint32 ura_appid, char *url, char *param, kal_uint32 options, void *cb);

        err_code = mmi_uriagent_register_hdlr_by_scheme("mms", (mmi_uriagent_uri_request_hdlr_fn) mms_uri_insert_hdlr, 0);
        ASSERT(err_code == MMI_URIAGENT_ERR_OK || err_code == MMI_URIAGENT_ERR_SCHEME_IS_REGISTERED);
        err_code = mmi_uriagent_register_hdlr_by_scheme("mmsto", (mmi_uriagent_uri_request_hdlr_fn) mms_uri_insert_hdlr, 0);
        ASSERT(err_code == MMI_URIAGENT_ERR_OK || err_code == MMI_URIAGENT_ERR_SCHEME_IS_REGISTERED);
    }
#endif /* __MMI_URI_AGENT__ */ 
    mmi_mms_q03c_mms_v01_agent_set_protocol_event_hdlr();
	mmi_mmsv01_agent_init_object_ind_data();
#ifdef __MMI_MMS_V01_USE_ASM__
    mmi_mmsv01_agent_asm_init();
#endif /*__MMI_MMS_V01_USE_ASM__*/
/*Rahul*/
    mmi_mmsv01_agent_settings_init();
}


/*****************************************************************************
 * FUNCTION
 *  mms_is_file_can_be_forwarded_to_mms
 * DESCRIPTION
 *  The function is used to check if the media can be forwarded to MMS
 * PARAMETERS
 *  filename        [IN]        Encoded by UCS2
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_is_file_can_be_forwarded_to_mms(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __UNIFIED_COMPOSER_SUPPORT__
    kal_int16 size = 0;
    char *str = NULL;
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ /* #ifndef __UNIFIED_COMPOSER_SUPPORT__   */
    kal_bool return_val = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mms_is_ready())
    {
    #ifdef __UNIFIED_COMPOSER_SUPPORT__
        return TRUE;
    #else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
        size = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)filename);
        str = OslMalloc(size + 1);
        mmi_chset_ucs2_to_utf8_string((kal_uint8*) str, size + 1, (kal_uint8*) filename);
        if (mea_mmsV01_agent_filename_2_mimetype(str) != NULL)
        {
            char *ext = strrchr(str, '.');

            if (app_stricmp(ext, ".dm") == 0
        #ifndef __DRM_SUPPORT__
                || app_stricmp(ext, ".dcf") == 0
        #endif 
        #ifndef __DRM_V02__
                || app_stricmp(ext, ".odf") == 0
        #endif 
                )
            {
                return_val = FALSE;
            }
            else
            {
                return_val = TRUE;
            }
        }
        else
        {
            return_val = FALSE;
        }

        OslMfree(str);
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    }

    return return_val;
}

#ifdef __MMI_URI_AGENT__
/*****************************************************************************
 * FUNCTION
 *  mms_uri_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a URI scheme
 * CALLS
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [?]         
 *  param           [?]         
 *  options         [IN]        
 *  cb              [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_uri_insert_hdlr(kal_uint32 ura_appid, char *url, char *param, kal_uint32 options, void *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_uriagent_uri_request_hdlr_cb uri_cb = (mmi_uriagent_uri_request_hdlr_cb) cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
	
	g_mmi_mms_V01_agent_ctx.mms_uri_param = param;

    if (uri_cb != NULL)
    {
        uri_cb(ura_appid, MMI_URIAGENT_APPID_MMS, MMI_URIAGENT_ERR_OK);
    }

    if (!mms_is_ready())
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        return;
    }

    if (options == MMI_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
    {
        mmi_display_popup_confirm(
            (UI_string_type) get_string(STR_GLOBAL_YES),
            (PU8) GetImage(IMG_GLOBAL_YES),
            (UI_string_type) get_string(STR_GLOBAL_NO),
            (PU8) GetImage(IMG_GLOBAL_NO),
            (UI_string_type) get_string(STR_ID_MMSV01_AGENT_SEND_MMS_QUERY),
            MMI_EVENT_QUERY);

        SetLeftSoftkeyFunction(mms_uri_insert_hdlr_ext, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
    else
    {
        mms_uri_insert_hdlr_ext();
    }
}

#ifdef __UNIFIED_COMPOSER_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mms_uri_translate
 * DESCRIPTION
 *  Translate mms structure into uc structure
 * CALLS
 *  
 * PARAMETERS
 *  data        [IN]     
 *  uc_data     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mms_uri_translate(mms_entry_write_struct *data, mmi_uc_entry_write_struct *uc_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_addr_struct *this_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uc_data->addr_num = data->addr_num;
    uc_data->text_buffer = data->text_buffer;
    uc_data->text_num = data->text_num;
    uc_data->subject = data->subject;
    this_addr = data->addr;
    while (this_addr != NULL)
    {
        mmi_uc_addr_struct *addr_data;

        addr_data = OslMalloc(sizeof(mmi_uc_addr_struct));

        addr_data->addr = this_addr->addr;
        addr_data->group = this_addr->group;
        addr_data->type = this_addr->type;
        addr_data->next = NULL;
        if (uc_data->addr == NULL)
        {
            uc_data->addr = addr_data;
        }
        else
        {
            mmi_uc_addr_struct **tmp = &(uc_data->addr);
            mmi_uc_addr_struct *insert;

            insert = *tmp;
            while (insert->next != NULL)
            {
                insert = insert->next;
            }
            insert->next = addr_data;
        }
        this_addr = this_addr->next;
    }

}
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ /* #ifdef __UNIFIED_COMPOSER_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mms_uri_insert_hdlr_ext
 * DESCRIPTION
 *  Start MMS in editor with a param
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_uri_insert_hdlr_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    char *param = g_mmi_mms_V01_agent_ctx.mms_uri_param;
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    mms_entry_write_struct tmp_data;
    mmi_uc_entry_write_struct uc_data = {0, };


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&tmp_data, 0x00, sizeof(mms_entry_write_struct));

    mms_uri_parser(param, &tmp_data);

    if (tmp_data.addr_num == 0)
    {
        mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_INVALID_RECIP_ADDRESS), MMI_EVENT_FAILURE);

        return;
    }

    memset(&uc_data, 0x00, sizeof(mmi_uc_entry_write_struct));
    uc_data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
    uc_data.info_type = MMI_UC_INFO_TYPE_MMS;

    mms_uri_translate(&tmp_data, &uc_data);

    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, (mmi_uc_entry_write_struct*) & uc_data);

#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 

    mms_content_entry_struct data = {0, };

	if (!mms_uri_is_present_valid_address(param))
	{
		mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_INVALID_RECIP_ADDRESS), MMI_EVENT_FAILURE);
		return;
	}

    data.mode = MMS_NEW_URI;
    data.text_buffer = param;
    goto_mms_editor(&data);
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mms_uri_addr_enqueue
 * DESCRIPTION
 *  to enqueue the address data into address queue
 * CALLS
 *  
 * PARAMETERS
 *  addr_data       [IN]         
 *  addr_queue      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_uri_addr_enqueue(mms_addr_struct *addr_data, mms_addr_struct **addr_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mms_addr_struct *insert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    if (addr_data == NULL)
    {
        return;
    }

    if (*addr_queue == NULL)
    {
        *addr_queue = addr_data;
        return;
    }

    insert = *addr_queue;
    while (insert->next != NULL)
    {
        insert = insert->next;
    }
    insert->next = addr_data;

}


/*****************************************************************************
 * FUNCTION
 *  mms_uri_is_new_header
 * DESCRIPTION
 *  Tells whether a new header has been reached while parsing the URI
 * CALLS
 *  
 * PARAMETERS
 *  str             [?]         
 *  cur_header      [IN]        
 * RETURNS
 *  int
 *****************************************************************************/
int mms_uri_is_new_header(char *str, int cur_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMS_URI_IS_SEPARATOR(*str))
    {
        if (cur_header == MMS_URI_HEADER_TO || cur_header == MMS_URI_HEADER_CC)
        {
            return KAL_TRUE;
        }
        str++;
    }
    else
    {
        return KAL_FALSE;
    }

    if (*str)
    {
        if (strncmp(str, MMS_URI_TO, 3) == 0 || strncmp(str, MMS_URI_CC, 3) == 0
            || strncmp(str, MMS_URI_BODY, 5) == 0 || strncmp(str, MMS_URI_SUBJECT, 8) == 0)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;

}

#ifdef __UNIFIED_COMPOSER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mms_uri_parser
 * DESCRIPTION
 *  parse a URI text into uc data
 * CALLS
 *  
 * PARAMETERS
 *  text        [IN]     
 *  uc_data     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mms_uri_parser(char *text, mms_entry_write_struct *uc_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int start = 0, end = 0, cur_header = MMS_URI_HEADER_TO;
    char *str = NULL;
    char *tmp_str = NULL;
    /*----------------------------------------------------------------*/ 
    /* Code Body                                                      */ 
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str = text;
    end = 0;

    if (MMS_URI_IS_SEPARATOR(*str))
    {
        while (MMS_URI_IS_SEPARATOR(*str))
        {
            str++;
        }
        if (strncmp(str, MMS_URI_TO, 3) == 0)
        {
            cur_header = MMS_URI_HEADER_TO;
            str += 3;
        }
        else if (strncmp(str, MMS_URI_CC, 3) == 0)
        {
            cur_header = MMS_URI_HEADER_CC;
            str += 3;
        }
        else if (strncmp(str, MMS_URI_SUBJECT, 8) == 0)
        {
            cur_header = MMS_URI_HEADER_SUBJECT;
            str += 8;
        }
        else if (strncmp(str, MMS_URI_BODY, 5) == 0)
        {
            cur_header = MMS_URI_HEADER_BODY;
            str += 5;
        }
    }

    while (str != NULL)
    {
        if (str[end] == 0 || mms_uri_is_new_header(str + end, cur_header))
        {
            if (end - start != 0)
            {
                tmp_str = OslMalloc(end - start + 1);
                memset(tmp_str, 0, end - start + 1);
                if (str)
                {
                    strncpy(tmp_str, str, end - start);
                }

                switch (cur_header)
                {
                        int temp = sizeof(mms_addr_struct);

                    case MMS_URI_HEADER_TO:
                    case MMS_URI_HEADER_CC:
                    {
                        mms_addr_struct *addr_data;

                        if (uc_data->addr_num >= wap_custom_get_max_mms_address())
                        {
                            break;
                        }

                        if (tmp_str != NULL)
                        {
                            if (mea_mmsV01_agent_get_valid_addr_type(tmp_str) == MEA_ADDR_TYPE_NONE)
                            {
                                break;
                            }
                        }

                        uc_data->addr_num++;
                        addr_data = OslMalloc(sizeof(mms_addr_struct));

                        if (strstr(tmp_str, "@") == NULL)
                        {
                            addr_data->type = MMS_ADDRESS_TYPE_PHONE_NUMBER;
                        }
                        else
                        {
                            addr_data->type = MMS_ADDRESS_TYPE_EMAIL;
                        }
                        if (cur_header == MMS_URI_HEADER_TO)
                        {
                            addr_data->group = MMS_ADDRESS_GROUP_TYPE_TO;
                        }
                        else
                        {
                            addr_data->group = MMS_ADDRESS_GROUP_TYPE_CC;
                        }

                        addr_data->addr = OslMalloc((end + 1) * 2);
                        mmi_chset_utf8_to_ucs2_string(addr_data->addr, (end + 1) * 2, (kal_uint8*) tmp_str);
                        addr_data->previous = addr_data->next = NULL;

                        mms_uri_addr_enqueue(addr_data, &(uc_data->addr));

                        break;
                    }
                    case MMS_URI_HEADER_SUBJECT:
                    {
                        if (uc_data->subject == NULL)
                        {
                            uc_data->subject = OslMalloc((end + 1) * 2);
                            mmi_chset_utf8_to_ucs2_string(uc_data->subject, (end + 1) * 2, (kal_uint8*) tmp_str);

                        }
                        break;
                    }
                    case MMS_URI_HEADER_BODY:
                    {
                        if (uc_data->text_buffer == NULL)
                        {
                            /* uc_data->text_buffer = MSF_MEM_ALLOC(1, (end+1) * 2);
                               widget_utf8_to_ucs2_string(uc_data->text_buffer,(end+1) * 2,(const kal_uint8 *)tmp_str); */
                            uc_data->text_buffer = OslMalloc((end + 1) * 2);
                            mmi_chset_utf8_to_ucs2_string(uc_data->text_buffer, (end + 1) * 2, (kal_uint8*) tmp_str);
                            uc_data->text_num = end;
                        }
                        break;
                    }
                }
                OslMfree(tmp_str);
            }

            if (str[end] == 0)
            {
                break;
            }
            str += (end - start) + 1;
            start = end = 0;
            if (str)
            {
                if (strncmp(str, MMS_URI_TO, 3) == 0)
                {
                    cur_header = MMS_URI_HEADER_TO;
                    str += 3;
                }
                else if (strncmp(str, MMS_URI_CC, 3) == 0)
                {
                    cur_header = MMS_URI_HEADER_CC;
                    str += 3;
                }
                else if (strncmp(str, MMS_URI_SUBJECT, 8) == 0)
                {
                    cur_header = MMS_URI_HEADER_SUBJECT;
                    str += 8;
                }
                else if (strncmp(str, MMS_URI_BODY, 5) == 0)
                {
                    cur_header = MMS_URI_HEADER_BODY;
                    str += 5;
                }

                if (cur_header == MMS_URI_HEADER_TO || cur_header == MMS_URI_HEADER_CC)
                {
                    while (strncmp(str, " ", 1) == 0)
                    {
                        str++;
                    }
                }
            }
            continue;
        }
        end++;
    }
}

#else  /* __UNIFIED_COMPOSER_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mms_uri_is_present_valid_address
 * DESCRIPTION
 *  Checks for a valid address in URI string
 * CALLS
 *  
 * PARAMETERS
 *  text        [IN]      *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mms_uri_is_present_valid_address(char *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int start = 0, end = 0, cur_header = MMS_URI_HEADER_TO;
    char *str = NULL;
    char *tmp_str = NULL;
	kal_bool is_valid_address = FALSE;
    /*----------------------------------------------------------------*/ 
    /* Code Body                                                      */ 
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str = text;
    end = 0;

	if (str != NULL)
	{	

		do
		{
			while (MMS_URI_IS_SEPARATOR(*str))
			{
				str++;
			}
			if (strncmp(str, MMS_URI_TO, 3) == 0)
			{
				cur_header = MMS_URI_HEADER_TO;
				str += 3;
			}
			else if (strncmp(str, MMS_URI_CC, 3) == 0)
			{
				cur_header = MMS_URI_HEADER_CC;
				str += 3;
			}
			else if (strncmp(str, MMS_URI_SUBJECT, 8) == 0)
			{
				cur_header = MMS_URI_HEADER_SUBJECT;
				str += 8;
			}
			else if (strncmp(str, MMS_URI_BODY, 5) == 0)
			{
				cur_header = MMS_URI_HEADER_BODY;
				str += 5;
			}
			if (cur_header == MMS_URI_HEADER_TO || cur_header == MMS_URI_HEADER_CC)
			{
				while (strncmp(str, " ", 1) == 0)
				{
					str++;
				}
			}

			while (str[end] != 0 && !mms_uri_is_new_header(str + end, cur_header))
			{
				end++;
			}

			if (end - start != 0)
			{
				tmp_str = OslMalloc(end - start + 1);
				memset(tmp_str, 0, end - start + 1);
				if (str)
				{
					strncpy(tmp_str, str, end - start);
				}

				if ( cur_header == MMS_URI_HEADER_TO ||
					 cur_header == MMS_URI_HEADER_CC)
				{
					if (tmp_str != NULL)
					{
						if (mea_mmsV01_agent_get_valid_addr_type(tmp_str) == MEA_ADDR_TYPE_NONE)
						{
							is_valid_address = FALSE;
						}
						else
						{
							is_valid_address = TRUE;
						}
					}
				}
				OslMfree(tmp_str);
			}
			str += (end - start) + 1;
			start = end = 0;
		} while (str != NULL && !is_valid_address && *str != 0);
	}

	return is_valid_address;
}

#endif /* __UNIFIED_COMPOSER_SUPPORT__ */




#endif /* __MMI_URI_AGENT__ */ /* #ifdef __MMI_URI_AGENT__ */

#endif /* defined(OBIGO_Q03C_MMS_V01) */ 

