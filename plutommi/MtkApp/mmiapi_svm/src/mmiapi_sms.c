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
 * mmiapi_sms.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== *******************************************************************************/

#include "MMI_include.h"

#define MMIAPI_USING_SMS
#define MMIAPI_USING_UI
#define MMIAPI_USING_BLOCKING
#include "mmiapi_struct.h"
#include "mmiapi.h"
#include "mmiapi_func.h"

#include "ems.h"
#include "wgui_ems.h"
//#include "MessagesMiscell.h"
#include "EMSMiscell.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "PhoneBookGprot.h"
#if (MMI_MAX_SIM_NUM >= 2)

#endif
#include "SmsSrvGprot.h"
#include "csmcc_enums.h"

static SMS_HANDLE sending_handle = NULL;

/******************************************************************************************************************
  *  SMS Sending
  *
  ******************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_send_rsp
 * DESCRIPTION
 *  this function will be called when SMS sent.
 * CALLS
 *  
 * PARAMETERS
 *  msgRsp      [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_send_rsp(srv_sms_callback_struct *result_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_send_user_data_struct *mod_buf;
    module_type mod_src;
    kal_int32 vm_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mod_buf = (mmiapi_sms_send_user_data_struct*) result_data->user_data;
    mod_src = mod_buf->mod_src;
    vm_id = mod_buf->vm_id;
    OslMfree(mod_buf);
	
    ASSERT(mod_src != MOD_NIL);

    sending_handle = NULL;

    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_sms_send_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_send_rsp_struct);
        p->result = (kal_bool)(result_data->result == MMI_TRUE);
	p->vm_id = vm_id;
        SEND_MESSAGE(MOD_MMI, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_SEND_RSP, p, NULL);
    }

    BLOCKING_BOOLEAN_RETURN_VALUE(mod_src, (kal_bool) (result_data->result == 1));
    BLOCKING_FINISH(mod_src);

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_send_req
 * DESCRIPTION
 *  mmiapi engine will use EMS library to pack data, and send SMS
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_send_req(mmiapi_sms_send_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;
	U8 address[MAX_DIGITS_SMS + 1];
	U16 w_address[MAX_DIGITS_SMS + 1];
	//S8 *content = NULL;
	U16 length = 0;
	mmiapi_sms_send_user_data_struct *mod_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    {		
				sms_handle = srv_sms_get_send_handle();
		
				if (msg->dcs == SRV_SMS_DCS_8BIT)
				{
		        srv_sms_set_content_dcs(sms_handle, msg->dcs);
				}
        
        srv_sms_set_class_type(sms_handle, SRV_SMS_CLASS_1);

        if (msg->port_number >= 0)
        {
            srv_sms_set_data_port(sms_handle, (U16) msg->port_number, (U16) msg->port_number);
        }

#if (MMI_MAX_SIM_NUM == 2)
        if (msg->isSlave)
        {
            srv_sms_set_sim_id(sms_handle, SRV_SMS_SIM_2);
        }
        else
        {
            srv_sms_set_sim_id(sms_handle, SRV_SMS_SIM_1);
        }
#else if (MMI_MAX_SIM_NUM >= 3)
        srv_sms_set_sim_id(sms_handle, (srv_sms_sim_enum) msg->sim_id);
#endif

        /* the sending screen should not show because the blocking mechanism of JAVA */
        srv_sms_set_send_type(sms_handle, SRV_SMS_BG_SEND);

        /* Do not allow empty SC address  */
        //srv_sms_set_not_allow_empty_sc(sms_handle);

		srv_sms_set_counter_without_change(sms_handle);

		if (msg->isNotDispSendingIcon)
		{
			srv_sms_set_no_sending_icon(sms_handle);
		}

        if (msg->addr.type == CSMCC_INTERNATIONAL_ADDR)
        {
            address[length] = '+';
            length++;
        }
		memcpy((S8*) &(address[length]), (S8*) msg->addr.number, msg->addr.length);
        mmi_asc_n_to_ucs2((S8*) w_address, (S8*) address, msg->addr.length + length);
		w_address[msg->addr.length + length] = (U16)0;
		srv_sms_set_address(sms_handle, (S8*) w_address);
        srv_sms_set_content(sms_handle, (S8*) msg->msg, (U16) msg->msg_length);
		mod_buf = OslMalloc(sizeof(mmiapi_sms_send_user_data_struct));
		mod_buf->mod_src = mod_src;
        mod_buf->vm_id = msg->vm_id;
        sending_handle = sms_handle;
		srv_sms_send_msg(sms_handle, mmiapi_sms_send_rsp, (void*) mod_buf);
        free_ctrl_buffer(msg->msg);
    }
}

/******************************************************************************************************************
  *  SMS application data indicate
  *
  ******************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_ind
 * DESCRIPTION
 *  when incoming store to pool, mmiapi engine will call this function
 *  to send notify to user
 * CALLS
 *  
 * PARAMETERS
 *  msg             [?]         
 *  mod_dest        [IN]        
 *  serial          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmiapi_sms_ind(srv_sms_event_struct* event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_new_sms_struct * data = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_sms_new_msg_struct *new_msg = (srv_sms_new_msg_struct *)data->msg_data;
    U16 mod_dest;
    U16 len = new_msg->message_len;
    mmiapi_sms_ind_struct *p = NEW_LOCAL_PTR(mmiapi_sms_ind_struct);    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->port_number = new_msg->dest_port;
    p->dcs = new_msg->dcs;
    p->con_len = len;
    mod_dest = *((U16 *)(event_data->user_data));
    if (len > (MMI_SMS_MAX_MSG_SEG * 160))
    {
        len = MMI_SMS_MAX_MSG_SEG * 160;
    }
    if(len > 0)
    {
        p->content = OslMalloc(len + 2);
        memcpy(p->content, data->content, len);
    }

    if (new_msg->dcs == SRV_SMS_DCS_7BIT || new_msg->dcs == SRV_SMS_DCS_UCS2)
    {
         p->type = 0;
    }
    else
    {
        p->type = 1;
    }
    mmi_asc_to_ucs2((S8 *)p->address,  (S8 *)new_msg->number);
    memcpy(&(p->time), &(new_msg->timestamp), sizeof(MYTIME));
    if (mod_dest == MOD_MMI)
    {   /* Wilson, temp solution to send message to MMI itself. */
        SEND_MESSAGE(MOD_WAP, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_IND, p, NULL);
    }
    else
    {
        SEND_MESSAGE(MOD_MMI, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_IND, p, NULL);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_ind_with_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  mod_dest        [IN]        
 *  port            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_ind_with_data(U8 *data, module_type mod_dest, int port)
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
 *  mmiapi_sms_check_incoming_msg_rsp
 * DESCRIPTION
 *  the mmiapi check incoming message response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_check_incoming_msg_rsp(module_type mod_dest, int result)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_check_incoming_msg_req
 * DESCRIPTION
 *  user can check if the incoming message arrive or not.
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_check_incoming_msg_req(mmiapi_sms_check_incoming_msg_req_struct *msg, module_type mod_src)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_timestamp_rsp
 * DESCRIPTION
 *  the mmiapi get incoming message timestamp response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  scts            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_timestamp_rsp(module_type mod_dest, kal_uint8 *scts)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_timestamp_req
 * DESCRIPTION
 *  fetch the message timestamp
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_timestamp_req(
        mmiapi_sms_get_incoming_msg_timestamp_req_struct *msg,
        module_type mod_src)
{

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_address_rsp
 * DESCRIPTION
 *  the mmiapi get incoming message address response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  oa              [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_address_rsp(module_type mod_dest, l4_addr_bcd_struct *oa)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_address_req
 * DESCRIPTION
 *  fetch the message address
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_address_req(mmiapi_sms_get_incoming_msg_address_req_struct *msg, module_type mod_src)
{

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_rsp
 * DESCRIPTION
 *  the mmiapi get incoming message response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  msg             [?]         
 *  msg_len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_rsp(module_type mod_dest, kal_uint8 *msg, int msg_len)
{

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_req
 * DESCRIPTION
 *  fetch the message
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_req(mmiapi_sms_get_incoming_msg_req_struct *msg, module_type mod_src)
{

}

/******************************************************************************************************************
  *  SMS register port number
  *
  ******************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_register_port_rsp
 * DESCRIPTION
 *  this function will be called after L4C process the sms register port number request.
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_register_port_rsp(void *msg, module_type mod_src, U16 result)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_register_port_req
 * DESCRIPTION
 *  mmiapi engine will send register port number request to L4C
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_register_port_req(mmiapi_sms_register_port_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type * mod_id = NULL;
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);
    
    #if (MMI_MAX_SIM_NUM >= 2)
     sim_id = (srv_sms_sim_enum)msg->sim_id;	
    #if (MMI_MAX_SIM_NUM == 2)
        if (msg->isSlave)
        {
            sim_id = SRV_SMS_SIM_2;
        }
        else
        {
            sim_id = SRV_SMS_SIM_1;
        }
    #endif
    #endif
    
    if (msg->enable)
    {
        mod_id = OslMalloc(sizeof(module_type));
        *mod_id = mod_src;
        srv_sms_reg_port(
           (U16) msg->port_number,
            sim_id,
            mmiapi_sms_ind,
            mod_id);
    }
    else
    {
       mod_id = (module_type *) srv_sms_unreg_port(
                                       (U16) msg->port_number,
                                        sim_id,
                                        mmiapi_sms_ind,
                                        mod_id);  
       if (mod_id != NULL)
       {
            OslMfree(mod_id);
       }
    }
    
    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_sms_register_port_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_register_port_rsp_struct);

        p->result = KAL_TRUE;
        p->cause = 0;
        p->vm_id = msg->vm_id;
        if (mod_src == MOD_MMI)
        {   /* Wilson, temp solution to send message to MMI itself. */
            SEND_MESSAGE(MOD_WAP, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP, p, NULL);
        }
        else
        {
           SEND_MESSAGE(MOD_MMI, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP, p, NULL);
        }
    }

    BLOCKING_BOOLEAN_RETURN_VALUE(mod_src, (kal_bool)KAL_TRUE);
    BLOCKING_FINISH(mod_src);	

}

/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_register_port_rsp
 * DESCRIPTION
 *  Callback of mmiapi_sms_get_smsc_addr_rsp
 *  
 * PARAMETERS
 *  data         [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_smsc_addr_rsp(void *data, module_type mod_src, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (!IS_BLOCKING(mod_src))
    //{
        mmiapi_sms_get_smsc_addr_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_smsc_addr_rsp_struct);

        p->result = result;
        if(result == KAL_TRUE && data != NULL)
		{
			len = strlen((const S8*)data);
			if(len != 0)
			{
				if(len > SRV_SMS_MAX_ADDR_LEN)
				{
				    len = SRV_SMS_MAX_ADDR_LEN;
			    }
				memcpy(p->sc_addr, (S8*) data, SRV_SMS_MAX_ADDR_LEN + 1);
				p->sc_addr_len = len + 1;
		    }
			else
		    {
		        p->result =KAL_FALSE;
			}
	    }
		else
		{
		    p->result = KAL_FALSE;
	    }
        SEND_MESSAGE(MOD_MMI, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_GET_SMSC_ADDR_RSP, p, NULL);
       //}

    //BLOCKING_INT_RETURN_VALUE(mod_src, result);
    //BLOCKING_FINISH(mod_src);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_smsc_addr_req
 * DESCRIPTION
 *  mmiapi engine will call sms function to get active sc addr
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_smsc_addr_req(mmiapi_sms_get_smsc_addr_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
    srv_sms_setting_struct default_setting = {0};
    S8 *sc_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 2)
    if(msg->isSlave)
    {
         sim_id = SRV_SMS_SIM_2;
    }
	else
	{
	    sim_id = SRV_SMS_SIM_1;
	}
#else if (MMI_MAX_SIM_NUM >= 3)
    sim_id = (srv_sms_sim_enum) msg->sim_id;
#endif

    srv_sms_get_default_setting(sim_id);
    memcpy(&default_setting, srv_sms_get_default_setting(sim_id), sizeof(srv_sms_setting_struct));

    sc_addr = default_setting.sc_addr;

    mmiapi_sms_get_smsc_addr_rsp(sc_addr,  msg->mod_id,  KAL_TRUE);
}


