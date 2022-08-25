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
 *  Sample_SMS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for SMS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "APPSDKFrameworkGProt.h"
#include "APPSDKAppGProt.h"        
#include "APPSDKSystemServiceGProt.h"
/****************************************************************************
*
*  [Sample]
*  Purpose   : send SMS
*  Function  : send SMS and implement callback function 
*  Notice    : 
*  Branch    : 08A later
*  API Ref   : mmi_frm_sms_send_sms_for_other_app 
*  
*
*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_sample_send_sms_callback
 * DESCRIPTION
 *  send sms callback function
 * PARAMETERS
 *  callback_data   :  send result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_send_sms_callback(srv_sms_callback_struct* callback_data)
{

	if (callback_data->result == MMI_TRUE)
	{
		/* send successfully */
	}
    	else
	{
        	switch(callback_data->cause)
		{
            		case SRV_SMS_CAUSE_SEND_ABORT:
                     case SRV_SMS_CAUSE_NOT_READY:
                     case SRV_SMS_CAUSE_SEND_BUSY:
                     case SRV_SMS_CAUSE_MEM_FULL:
                     case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
                     case SRV_SMS_CAUSE_DATA_INVALID:
                     case SRV_SMS_CAUSE_DATA_EXCEED:
                     case SRV_SMS_CAUSE_NUMBER_EMPTY:
                     case SRV_SMS_CAUSE_NUMBER_INVALID:
                     case SRV_SMS_CAUSE_SC_EMPTY:
                     case SRV_SMS_CAUSE_SC_INVALID:
                     case SRV_SMS_CAUSE_FDL_FAIL:
                     case SRV_SMS_CAUSE_AT_CONFLICT:
                     case SRV_SMS_CAUSE_OP_CONFLICT:
                     case SRV_SMS_CAUSE_EMAIL_NO_SPACE:
                     case SRV_SMS_CAUSE_UNKNOWN_ERROR:
                     default:
				/* send failed */
		        	break;
		}
 	}
	
}


#define MAX_DIGITS_SMS  21

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_send_sms
 * DESCRIPTION
 *  send sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_send_sms(S8* number, U16* content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE send_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    send_handle = srv_sms_get_send_handle();
    if (send_handle == NULL)
    {
	/* can not get handle */
	return;
    }

    if ((U16)srv_sms_is_bg_send_action_busy() == MMI_TRUE)
    {
	/* background sending is busy */
	return;
    }

    /* set address number */
    srv_sms_set_address(send_handle, number);
    /* set content of DCS encoding */
    srv_sms_set_content_dcs(send_handle, SRV_SMS_DCS_UCS2);
    /* set content */
    srv_sms_set_content(send_handle, (S8*)content, (U16)((mmi_wcslen(content)+1)*2));

    /* set SIM1 */
    srv_sms_set_sim_id(send_handle, SRV_SMS_SIM_1);

    /* send request */
    srv_sms_send_msg(send_handle, mmi_sample_send_sms_callback, NULL);
    
}


/****************************************************************************
*
*  [Sample]
*  Purpose   :write SMS screen
*  Function  : entry write SMS screen 
*  Notice    : 
*  Branch    : 08A later
*  API Ref   : mmi_frm_sms_api_entry_write_msg 
*  
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_write_sms
 * DESCRIPTION
 *  entry write sms screen with number and content
 * PARAMETERS
 *  number: destination number
 *  content: default content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_write_sms(S8*number, U16* content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    para.ascii_addr = (U8*)get_ctrl_buffer((kal_uint16)(MAX_DIGITS_SMS + 1));

    strncpy((S8*)para.ascii_addr, (S8*)number, MAX_DIGITS_SMS);
    para.ascii_addr[MAX_DIGITS_SMS] = 0;

    /* only if content is UCS2 format */
    para.stringlength = mmi_wcslen(content);
    if (para.stringlength!=0)
    {
        para.string = (S8*)get_ctrl_buffer((kal_uint16)(para.stringlength) * ENCODING_LENGTH);
    }
    mmi_wcscpy((U16*)para.string, content);

    /* only if content is UCS2 format */
    para.dcs = SMSAL_UCS2_DCS;
	
    /* if reply */
    para.flag = MMI_SMS_ENTRY_WRITE_REPLY;

    mmi_sms_write_msg_lanch(0, &para);

    free_ctrl_buffer(para.ascii_addr);
    if (para.stringlength!=0)
    {
        free_ctrl_buffer(para.string);
    }
}
