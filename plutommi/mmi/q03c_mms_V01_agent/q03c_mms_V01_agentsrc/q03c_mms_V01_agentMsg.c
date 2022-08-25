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
 * q03c_mms_v01_agentmsg.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#if defined(OBIGO_Q03C_MMS_V01)

#include "mmi_frm_gprot.h"
#include "SimDetectionStruct.h"
#include "conversions.h"

/* SMS includes */
#include "SmsAppGprot.h"
#include "smsal_l4c_enum.h"
#include "q03c_mms_V01_agentprot.h"
#include "q03c_mms_v01_agentobjind.h"
#include "q03c_mms_V01_agentSettings.h"
#include "mea_api.h"
#include "wps_struct.h"
#include "mmc_struct.h"

#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGProt.h"
#endif 

#include "UCMGProt.h"
#ifdef __MMI_MMS_BGSR_SUPPORT__
extern void mmi_mms_bgsr_get_msg_info_cb(U32 msg_id, mmi_mms_bgsr_msg_info_struct *msg_info);
extern void mmi_mms_bgsr_change_msg_cb(U32 msg_id, U8 result);
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 


#ifdef __MMI_WAP_PROF__
#include "WAPProfileGProt.h"
#include "WAPProfileType.h"
#include "WAPprovisioningType.h"
#else /* __MMI_WAP_PROF__ */ 
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#endif /* __MMI_WAP_PROF__ */ 

#include "JavaAgencyDef.h"


extern mmi_mms_v01_agent_context_struct g_mmi_mms_V01_agent_ctx;

#ifdef __MMI_MMS_DUAL_SIM__


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_v01_agent_sim_status_info_hdlr
 * DESCRIPTION
 *  Handles Sim Status Info
 * CALLS
 *  
 * PARAMETERS
 *  in_msg      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_mms_v01_agent_sim_status_info_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_status_info_ind_struct *sim_status_info = (mmi_sim_status_info_ind_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(in_msg);
    /* MMI_TRACE (MMI_INET_TRC_G6_MMS, MMI_MMS_BGSR_SIM_STATUS_INFO, 
       sim_status_info->sim_id, 
       sim_status_info->sim_inserted, 
       sim_status_info->setting_mode, 
       sim_status_info->sim1_can_read, 
       sim_status_info->sim2_can_read, 
       sim_status_info->sim1_type, 
       sim_status_info->sim2_type, 
       __LINE__); */
    switch (sim_status_info->sim_id)
    {
        case MMI_SIM_ID_SIM1:
            g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
            if (sim_status_info->setting_mode == MMI_SIM_ID_SIM1 ||
                sim_status_info->setting_mode == MMI_SIM_ID_DUAL_SIM)
            {
                if (sim_status_info->sim1_can_read == MMI_TRUE || sim_status_info->sim1_type == MMI_SIM_TYPE_VALID_SIM)
                {
                    g_mmi_mms_V01_agent_ctx.is_sim1_valid = TRUE;
                }
            }

            if (sim_status_info->setting_mode == MMI_SIM_ID_SIM1)
            {
                g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;
            }

            break;

        case MMI_SIM_ID_SIM2:
            g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;
            if (sim_status_info->setting_mode == MMI_SIM_ID_SIM2 ||
                sim_status_info->setting_mode == MMI_SIM_ID_DUAL_SIM)
            {
                if (sim_status_info->sim2_can_read == MMI_TRUE || sim_status_info->sim2_type == MMI_SIM_TYPE_VALID_SIM)
                {
                    g_mmi_mms_V01_agent_ctx.is_sim2_valid = TRUE;
                }
            }

            if (sim_status_info->setting_mode == MMI_SIM_ID_SIM2)
            {
                g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
            }

            break;

        case MMI_SIM_ID_DUAL_SIM:
            switch (sim_status_info->setting_mode)
            {
                case MMI_SIM_ID_SIM1:
                    if (sim_status_info->sim1_can_read == MMI_TRUE ||
                        sim_status_info->sim1_type == MMI_SIM_TYPE_VALID_SIM)
                    {
                        g_mmi_mms_V01_agent_ctx.is_sim1_valid = TRUE;
                    }
                    else
                    {
                        g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
                    }
                    g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;

                    break;

                case MMI_SIM_ID_SIM2:
                    if (sim_status_info->sim2_can_read == MMI_TRUE ||
                        sim_status_info->sim2_type == MMI_SIM_TYPE_VALID_SIM)
                    {
                        g_mmi_mms_V01_agent_ctx.is_sim2_valid = TRUE;
                    }
                    else
                    {
                        g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;
                    }
                    g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
                    break;

                case MMI_SIM_ID_DUAL_SIM:
                    g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
                    g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;

                    if (sim_status_info->sim1_can_read == MMI_TRUE ||
                        sim_status_info->sim1_type == MMI_SIM_TYPE_VALID_SIM)
                    {
                        g_mmi_mms_V01_agent_ctx.is_sim1_valid = TRUE;
                    }
                    if (sim_status_info->sim2_can_read == MMI_TRUE ||
                        sim_status_info->sim2_type == MMI_SIM_TYPE_VALID_SIM)
                    {
                        g_mmi_mms_V01_agent_ctx.is_sim2_valid = TRUE;
                    }
                    break;

                case MMI_SIM_ID_FLIGHT_MODE:
                    g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
                    g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;
                    break;
                default:
                    break;
            }
            break;

        case MMI_SIM_ID_NO_SIM:
        case MMI_SIM_ID_FLIGHT_MODE:
            g_mmi_mms_V01_agent_ctx.is_sim1_valid = FALSE;
            g_mmi_mms_V01_agent_ctx.is_sim2_valid = FALSE;
            break;

        default:
            break;
    }
    /*Is it possible to replace it with API*/
    if (g_mmi_mms_V01_agent_ctx.is_mms_ready)
    {
        mmi_mmsv01_set_current_profile_req();
    }
    mmi_mmsv01_agent_check_and_restart_object_indication_timer();
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_v01_agent_is_valid_sim
 * DESCRIPTION
 *  Check if particular sim is valid or not
 * CALLS
 *  
 * PARAMETERS
 *  in_msg      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_v01_agent_is_valid_sim(kal_uint8 simid)
{
	if (simid == MMI_SIM_ID_SIM1)
	{
		return g_mmi_mms_V01_agent_ctx.is_sim1_valid;


	}
	else if (simid == MMI_SIM_ID_SIM2)
	{
		return g_mmi_mms_V01_agent_ctx.is_sim1_valid;
	}

	return FALSE;

}



#endif /* __MMI_MMS_DUAL_SIM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_make_call_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number           [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_make_call_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mmsv01_agent_use_number_req_struct *data = NULL;
    mmi_ucm_make_call_para_struct make_call_para = {0,};
    kal_uint8 ucs2num[(SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data = (mmi_mmsv01_agent_use_number_req_struct*)p;

    mmi_chset_utf8_to_ucs2_string((kal_uint8*)ucs2num , (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH, (kal_uint8*)data->text);

    mmi_ucm_init_call_para(&make_call_para);  
    make_call_para.adv_para.after_make_call_callback = NULL; 
    make_call_para.dial_type = SRV_UCM_CALL_TYPE_ALL;
    make_call_para.ucs2_num_uri = (U16*)ucs2num;
    mmi_ucm_call_launch(0, &make_call_para);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_obj_ind_res_hdlr
 * DESCRIPTION
 *  It handles the obj indication response from WAP task
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_mms_obj_ind_res_hdlr(void *p)
{
	if (p != NULL)
	{
		mmi_mmsv01_agent_object_indication_rsp(p);
	}


}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_insert_text_req_hdlr
 * DESCRIPTION
 *  Insert text handler
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_insert_text_req_hdlr(void *p, int src_mod, void *message)
{

    peer_buff_struct *peer_buff_ptr = (peer_buff_struct *)((ilm_struct*)message)->peer_buff_ptr;
	if (peer_buff_ptr != NULL)
	{

       
        kal_uint8 *peer_pdu = NULL;
        kal_uint16 peer_pdu_len = 0;
        
        
        peer_pdu = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        mms_text_insert_hdlr(NULL, 0, (char*)peer_pdu, peer_pdu_len);
       
       
	}
    else
    {
        /*TODO:: Rahul put log here to track the empty string*/
        mms_text_insert_hdlr(NULL, 0, NULL, 0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_enter_sms_editor_hdlr
 * DESCRIPTION
 *  It enters sms editor with specified information.
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_enter_sms_editor_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct sendData = {0, };
	mmi_mmsv01_agent_use_number_req_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data = (mmi_mmsv01_agent_use_number_req_struct*)p;
    memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

    sendData.string = NULL;
    sendData.stringlength = 0;
    sendData.dcs = SMSAL_UCS2_DCS;
    sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sendData.ascii_addr = (U8*) data->text;

    mmi_sms_write_msg_lanch(0, &sendData);
}

#ifdef __MMI_MMS_BGSR_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_send_msg_req_hdlr
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_send_msg_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    param = (mmi_mms_bgsr_msg_struct*) p;

    mmi_mms_bgsr_send_req(1, param->msg_id, param->is_rr, param->send_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_chagne_message_req_hdlr
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_chagne_message_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    param = (mmi_mms_bgsr_msg_struct*) p;
    g_mmi_mms_V01_agent_ctx.mmi_mms_bgsr_op = param->op;
    g_mmi_mms_V01_agent_ctx.mmi_mms_bgsr_op_msg_id = param->msg_id;
    mmi_mms_bgsr_change_msg_notify(param->msg_id, param->op, param->folder, mmi_mms_bgsr_change_msg_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_msg_req_hdlr
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_msg_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct*) p;

    mmi_mms_bgsr_download_req(1, param->msg_id, param->expire_time, param->size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_cancel_send_msg_req_hdlr
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_cancel_send_msg_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct*) p;

    mmi_mms_bgsr_cancel_send_req(param->msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_cancel_download_msg_req_hdlr
 * DESCRIPTION
 *  handle wap task to cancel download the message
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_cancel_download_msg_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct*) p;

    mmi_mms_bgsr_cancel_download_req(param->msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_change_msg_req_hdlr
 * DESCRIPTION
 *  notify to BGSR about deletion
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_change_msg_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    param = (mmi_mms_bgsr_msg_struct*) p;
    if (param->op == MMI_MMS_BGSR_OP_DELETE_ALL_INBOX_OUTBOX)
    {
        mmi_mms_bgsr_change_msg_notify(
            param->msg_id,
            MMI_MMS_BGSR_OP_DELETE_ALL_INBOX,
            MMI_MMS_BGSR_FOLDER_INBOX,
            NULL);

        mmi_mms_bgsr_change_msg_notify(
            param->msg_id,
            MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX,
            MMI_MMS_BGSR_FOLDER_OUTBOX,
            NULL);
    }
    else
    {
        mmi_mms_bgsr_change_msg_notify(param->msg_id, param->op, param->folder, NULL);

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_msg_info_req_hdlr
 * DESCRIPTION
 *  handle wap task to get message info
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_get_msg_info_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_info_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    param = (mmi_mms_bgsr_msg_info_struct*) p;
    mmi_mms_bgsr_get_msg_info(param->msg_id, param, mmi_mms_bgsr_get_msg_info_cb);

}
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_mea_terminate_ind_hdlr
 * DESCRIPTION
 *  Terminate Indication handler from MEA
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_mea_terminate_ind_hdlr(void *p)
{
    /*Release ASM memory*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_MEA_TERMINATE_HDLR);

#ifdef __MMI_MMS_V01_USE_ASM__
    applib_mem_ap_free(g_mmi_mms_V01_agent_ctx.asm_pool_id);
    if (g_mmi_mms_V01_agent_ctx.is_forced_shutdown)
    {
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MMS_V01, TRUE);
        g_mmi_mms_V01_agent_ctx.is_forced_shutdown = FALSE;
    }
    
    /*reset the asm pool pointer to NULL*/
    g_mmi_mms_V01_agent_ctx.asm_pool_id = NULL;
#endif

    if (g_mmi_mms_V01_agent_ctx.url_req != NULL)
    {
        S8 ucs2Url[(WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH] = {0,};

        mmi_chset_utf8_to_ucs2_string((kal_uint8*)ucs2Url , (WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, (kal_uint8*)g_mmi_mms_V01_agent_ctx.url_req);
        wap_start_browser(g_mmi_mms_V01_agent_ctx.type, (U8*) ucs2Url);

        OslMfree(g_mmi_mms_V01_agent_ctx.url_req);
        g_mmi_mms_V01_agent_ctx.url_req = NULL;
    }

    mmi_mmsv01_deinit_settings_ui();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_brw_launch_req_hdlr
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_brw_launch_req_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
    mmi_mmsv01_agent_launch_brw_req_struct *data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data = (mmi_mmsv01_agent_launch_brw_req_struct*) p;

    if (data->type == WAP_BROWSER_GOTO_URL)
    {
        /*Save this in temperory context and launch the BRW after MEA termination*/
        g_mmi_mms_V01_agent_ctx.url_req = OslMalloc(strlen((char*)data->url) + 1);
        g_mmi_mms_V01_agent_ctx.type = data->type;
        memset(g_mmi_mms_V01_agent_ctx.url_req, 0, strlen((char*)data->url) +1 );
        memcpy((S8 *)g_mmi_mms_V01_agent_ctx.url_req, (S8 *) data->url, strlen((char*)data->url));         
    }
    else
    {
        /*Case of save bookmark*/
        S8 ucs2Url[(WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH] = {0,};
        mmi_chset_utf8_to_ucs2_string((kal_uint8*)ucs2Url , (WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, (kal_uint8*)data->url);
        wap_start_browser(data->type, (U8*) ucs2Url);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_handle_select_bookmark_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_handle_select_bookmark_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_select_bookmark_rsp_struct *msg_rsp = (wap_select_bookmark_rsp_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*Rahul Add Log here*/ 
    if (msg_rsp->result == 1) /*BRW use 0 and 1 for result 1->OK*/
    {
        mmi_mmsv01_agent_send_add_bookmark_rsp(msg_rsp->url, MEA_RESULT_OK);
        GoBackHistory(); /*To delete Bookmark screen*/
    }
    else
    {
        mmi_mmsv01_agent_send_add_bookmark_rsp(msg_rsp->url, MEA_RESULT_FAILED);
    }

}

void mmi_mms_add_bookmark_req_hdlr(void *p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_entry_select_bookmark() == 0)
    {
        SetProtocolEventHandler(mmi_mms_handle_select_bookmark_rsp, MSG_ID_WAP_SELECT_BOOKMARK_RSP);
    }

    }

void mmi_mmsv01_get_mms_profile_rsp(U8 result, U8 *value, U8 value_length, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_get_mms_prof_rsp_struct *myMsgPtr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_get_mms_prof_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_get_mms_prof_rsp_struct));
    myMsgPtr->result = result;
    myMsgPtr->value_len = value_length;
    if (value_length > 0 && value != NULL)
    {
        memcpy(myMsgPtr->value, value, value_length);
    }

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = J2ME_MMI_SAP;

    ilm_ptr->dest_mod_id = MOD_JAM;
    
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_GET_MMS_PROF_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_mms_profile_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_GET_MMS_PROF_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_jsr_get_mms_profile_req(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_get_mms_prof_req_struct *Message;

#ifdef __MMI_WAP_PROF__
    mmi_wap_prof_profile_content_struct *profile_data;
#else 
    nvram_profile_content_struct *profile_data;
#endif 
    U8 result = 2;  /* invalid prof id. */
    U8 value_length = 0;
    U8 *value = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_get_mms_prof_req_struct*) msg;

    switch (Message->access_id)
    {
        case 0: /*MMS_PROF_MMSC_ADDRESS*/
        {
            value = (U8*) OslMalloc(256);

#ifdef __MMI_WAP_PROF__
#ifdef __MMI_WAP_DUAL_SIM__
            if(Message->simId == MMC_SIM_CARD_SLAVE)
            {
                profile_data = mmi_wap_prof_get_profile_content(MMI_WAP_PROF_SIMID_SIM2, MMI_WAP_PROF_APPID_MMS, (U8) - 1, NULL);
            }
            else
#endif
            {
                profile_data = mmi_wap_prof_get_profile_content(MMI_WAP_PROF_SIMID_DEFAULT, MMI_WAP_PROF_APPID_MMS, (U8) - 1, NULL);
            }
#else 
            profile_data = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_mms_profile();
#endif 
            if (NULL == profile_data)
            {
                result = 1; /* MMS not ready yet. */
                break;
            }
            value_length = strlen((S8*) profile_data->url) + 1;

            if (value_length > 256)
            {
                ASSERT(0);  /* memory corruption */
            }
            memcpy(value, profile_data->url, value_length);
            result = 0;
        #ifdef __MMI_WAP_PROF__
            if (profile_data != NULL)
            {
                OslMfree(profile_data);
                profile_data = NULL;
            }
        #endif /* __MMI_WAP_PROF__ */ 
            break;
        }

        default:    /* will send result as 2 invalid profile */
            break;

    }
    mmi_mmsv01_get_mms_profile_rsp(result, value, value_length, mod_id);

    if (NULL != value)
    {
        OslMfree(value);
    }
}


void mmi_mms_ready_ind_hdlr(void *p)
{
    g_mmi_mms_V01_agent_ctx.is_mms_ready = TRUE;
    mmi_mmsv01_set_current_profile_req();
    mmi_mmsv01_set_settings_req();
}


void mmi_mms_terminate_ind_hdlr(void *p)
{
    g_mmi_mms_V01_agent_ctx.is_mms_ready = FALSE;
#ifdef __MMI_MMS_DUAL_SIM__
    mmi_mmsv01_clear_profile_set_flag();
#endif
}



void mmi_mms_get_settings_req_hdlr(void *p)
{
    mmi_mmsv01_get_settings_req_hdlr();
}


void mmi_mms_set_settings_rsp_hdlr(void *p)
{
    /*hello*/
}

#endif /* defined(OBIGO_Q03C_MMS_V01) */ 