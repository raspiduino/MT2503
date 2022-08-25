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
 * BTMMIBcc.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BCC(Bluetooth Control Center)
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "MMI_features.h"
#if defined(__MMI_BT_SUPPORT__) && defined(__SUPPORT_JBT__)
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "mmi_include.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"
#include "GpioSrvGprot.h"
#include "ModeSwitchSrvGprot.h"

/* mmi bt bcc header files */
#include "mmiapi_bt_struct.h"

/* cm header files */
#include "BtcmSrvGprot.h"


/* bcc header files */
#include "btmmibccgprots.h"
#include "btmmibcc.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_bth_bcc_cntx_struct g_mmi_bth_bcc_cntx;

/***************************************************************************** 
* External Functions
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_init_handler
 * DESCRIPTION
 *  This function is to init handler and invoke mmi_bth_bcc_init_event_handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_init_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_INIT);
	
    memset(&g_mmi_bth_bcc_cntx, 0, sizeof(mmi_bth_bcc_cntx_struct));
	mmi_bth_bcc_init_event_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_init_event_handler
 * DESCRIPTION
 *  This function is to init event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_INIT_EVENT);

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_bth_bcc_authorize_req_hdler, MSG_ID_MMI_BT_BCC_AUTHORIZE_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_is_authorized_req_hdler, MSG_ID_MMI_BT_BCC_IS_AUTHORIZED_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_is_trusted_req_hdler, MSG_ID_MMI_BT_BCC_IS_TRUSTED_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_get_security_mode_req_hdler, MSG_ID_MMI_BT_BCC_GET_HOST_SECURITY_MODE_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_get_preknown_device_count_req_hdler, MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICE_COUNT_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_get_preknown_device_req_hdler, MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICES_REQ);


    SetProtocolEventHandler(mmi_bth_bcc_power_on_req_hdler, MSG_ID_MMI_BT_BCC_POWER_ON_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_restore_req_hdler, MSG_ID_MMI_BT_BCC_RESTORE_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_set_host_device_name_req_hdler, MSG_ID_MMI_BT_BCC_SET_HOST_DEVICE_NAME_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_get_host_device_name_req_hdler, MSG_ID_MMI_BT_BCC_GET_HOST_DEVICE_NAME_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_set_discoverable_mode_req_hdler, MSG_ID_MMI_BT_BCC_SET_DISCOVERABLE_MODE_REQ);
    SetProtocolEventHandler(mmi_bth_bcc_get_discoverable_mode_req_hdler, MSG_ID_MMI_BT_BCC_GET_DISCOVERABLE_MODE_REQ);

    SetProtocolEventHandler(mmi_bth_bcc_get_native_pwr_status_req_hdler, MSG_ID_MMI_BT_BCC_GET_NATIVE_PWR_STATUS_REQ);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_authorize_req_hdler
 * DESCRIPTION
 *  This function is to handle authorize request and send MSG_ID_MMI_BT_BCC_AUTHORIZE_CNF
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_authorize_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_authorize_req_struct *msg_p = (mmi_bt_bcc_authorize_req_struct*) msg;
    mmi_bt_bcc_authorize_cnf_struct *msg_cnf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_AUTHORIZE_REQ,
		            ((msg_p->dev_addr.nap & 0xff00) >> 8),
		            (msg_p->dev_addr.nap & 0x00ff),
		            (msg_p->dev_addr.uap),
		            ((msg_p->dev_addr.lap & 0xff0000) >> 16),
		            ((msg_p->dev_addr.lap & 0x00ff00) >> 8),
		            (msg_p->dev_addr.lap & 0x0000ff));


    msg_cnf_p = (mmi_bt_bcc_authorize_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_authorize_cnf_struct), TD_CTRL);
	/* donot support authorization setting in MMI BT CM */
	/* always return succeeded for jsr82 */
    msg_cnf_p->result = mmi_bt_bcc_result_succeeded;
    msg_cnf_p->dev_addr.nap = msg_p->dev_addr.nap;
    msg_cnf_p->dev_addr.uap = msg_p->dev_addr.uap;
    msg_cnf_p->dev_addr.lap = msg_p->dev_addr.lap;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_AUTHORIZE_CNF, (void*)msg_cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_is_authorized_req_hdler
 * DESCRIPTION
 *  This function is to handle is authorized request and send MSG_ID_MMI_BT_BCC_IS_AUTHORIZED_CNF
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_is_authorized_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_is_authorized_req_struct *msg_p = (mmi_bt_bcc_is_authorized_req_struct*) msg;
    mmi_bt_bcc_is_authorized_cnf_struct *msg_cnf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_IS_AUTHORIZED_REQ,
		            ((msg_p->dev_addr.nap & 0xff00) >> 8),
		            (msg_p->dev_addr.nap & 0x00ff),
		            (msg_p->dev_addr.uap),
		            ((msg_p->dev_addr.lap & 0xff0000) >> 16),
		            ((msg_p->dev_addr.lap & 0x00ff00) >> 8),
		            (msg_p->dev_addr.lap & 0x0000ff));


    msg_cnf_p = (mmi_bt_bcc_is_authorized_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_is_authorized_cnf_struct), TD_CTRL);
	/* donot support authorization setting in MMI BT CM */
	/* always return succeeded for jsr82 */
    msg_cnf_p->result = mmi_bt_bcc_result_succeeded;
    msg_cnf_p->dev_addr.nap = msg_p->dev_addr.nap;
    msg_cnf_p->dev_addr.uap = msg_p->dev_addr.uap;
    msg_cnf_p->dev_addr.lap = msg_p->dev_addr.lap;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_IS_AUTHORIZED_CNF, (void*)msg_cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_is_trusted_req_hdler
 * DESCRIPTION
 *  This function is to handle is trusted request and send MSG_ID_MMI_BT_BCC_IS_TRUSTED_CNF
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_is_trusted_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_is_trusted_req_struct *msg_p = (mmi_bt_bcc_is_trusted_req_struct*) msg;
    mmi_bt_bcc_is_trusted_cnf_struct *msg_cnf_p;
	srv_bt_cm_dev_struct *dev_p;
	U32 device_count, i;
	mmi_bt_bcc_result_code result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_IS_TRUSTED_REQ,
		            ((msg_p->dev_addr.nap & 0xff00) >> 8),
		            (msg_p->dev_addr.nap & 0x00ff),
		            (msg_p->dev_addr.uap),
		            ((msg_p->dev_addr.lap & 0xff0000) >> 16),
		            ((msg_p->dev_addr.lap & 0x00ff00) >> 8),
		            (msg_p->dev_addr.lap & 0x0000ff));

    msg_cnf_p = (mmi_bt_bcc_is_trusted_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_is_trusted_cnf_struct), TD_CTRL);
	/* check if existed in paired list */
	device_count = (U32)srv_bt_cm_get_paired_dev_num();
	for (i=0; i<device_count; i++)
	{
		dev_p = srv_bt_cm_get_paired_dev_info((U16)i);
		if ( dev_p->bd_addr.nap == msg_p->dev_addr.nap &&
			 dev_p->bd_addr.uap == msg_p->dev_addr.uap &&
			 dev_p->bd_addr.lap == msg_p->dev_addr.lap)
		{
			break;
		}
		
	}

    if (i >= device_count)
	{

		/* not in paired list */
		/* not trusted */
		result = mmi_bt_bcc_result_failed;
	}
	else
	{
		/* in paired list */
		/* trusted */
		result = mmi_bt_bcc_result_succeeded;
	}
	
    msg_cnf_p->result = result;
    msg_cnf_p->dev_addr.nap = msg_p->dev_addr.nap;
    msg_cnf_p->dev_addr.uap = msg_p->dev_addr.uap;
    msg_cnf_p->dev_addr.lap = msg_p->dev_addr.lap;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_IS_TRUSTED_CNF, (void*)msg_cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_security_mode_req_hdler
 * DESCRIPTION
 *  This function is to handle get security mode request and send MSG_ID_MMI_BT_BCC_GET_HOST_SECURITY_MODE_CNF
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_get_security_mode_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_get_host_security_mode_cnf_struct *msg_cnf_p;
	U8 security_level;
	mmi_bt_bcc_security_mode result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_GET_SECURITY_MODE);

    msg_cnf_p = (mmi_bt_bcc_get_host_security_mode_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_get_host_security_mode_cnf_struct), TD_CTRL);
	/* security mode */
	security_level = srv_bt_cm_get_host_dev_security_level();
	switch(security_level)
	{
		case SRV_BT_CM_SEC_MODE1_NON_SECURE:
			result = mmi_bt_bcc_security_mode_1;
			break;
		case SRV_BT_CM_SEC_MODE2_SERVICE:
			result = mmi_bt_bcc_security_mode_2;
			break;
		case SRV_BT_CM_SEC_MODE3_LINK:
			result = mmi_bt_bcc_security_mode_3;
			break;
		case SRV_BT_CM_SEC_MODE4_SIMPLE:
			result = mmi_bt_bcc_security_mode_4;
			break;
		default:	
			result = mmi_bt_bcc_security_mode_1;
			break;
	}
    msg_cnf_p->security_mode= result;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_GET_HOST_SECURITY_MODE_CNF, (void*)msg_cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_preknown_device_count_req_hdler
 * DESCRIPTION
 *  This function is to handle get preknown device count request and send MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICE_COUNT_CNF
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_get_preknown_device_count_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_get_preknown_device_count_cnf_struct *msg_cnf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_GET_PREKNOWN_DEV_COUNT);

    msg_cnf_p = (mmi_bt_bcc_get_preknown_device_count_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_get_preknown_device_count_cnf_struct), TD_CTRL);
	/* device count */
    msg_cnf_p->device_count = (U32)srv_bt_cm_get_paired_dev_num();

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICE_COUNT_CNF, (void*)msg_cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_preknown_device_req_hdler
 * DESCRIPTION
 *  This function is to handle get preknown device request and send MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICES_CNF
 * PARAMETERS
 *  msg         [IN]            interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_get_preknown_device_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_get_preknown_devices_cnf_struct *msg_cnf_p;
	U32 i;
	U32 device_count;
	srv_bt_cm_dev_struct *dev_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_GET_PREKNOWN_DEV_LIST);

    msg_cnf_p = (mmi_bt_bcc_get_preknown_devices_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_get_preknown_devices_cnf_struct), TD_CTRL);
	/* copy paired device list to preknown device list */
	device_count = (U32)srv_bt_cm_get_paired_dev_num();
	for (i=0; i<device_count; i++)
	{
		dev_p = srv_bt_cm_get_paired_dev_info((U16)i);
		/* code */
		g_mmi_bth_bcc_cntx.preknown_dev_list[i].cod	= dev_p->cod;
		/* name */
		memcpy(g_mmi_bth_bcc_cntx.preknown_dev_list[i].name, dev_p->name, MMI_BT_BCC_MAX_HOST_DEV_NAME_LEN);
		/* device address */
		g_mmi_bth_bcc_cntx.preknown_dev_list[i].bd_addr.nap = dev_p->bd_addr.nap;
		g_mmi_bth_bcc_cntx.preknown_dev_list[i].bd_addr.uap = dev_p->bd_addr.uap;
		g_mmi_bth_bcc_cntx.preknown_dev_list[i].bd_addr.lap = dev_p->bd_addr.lap;		
		
	}
    msg_cnf_p->device_count = device_count;
    msg_cnf_p->preknown_dev_p = (mmi_bt_bcc_dev_info_struct *)g_mmi_bth_bcc_cntx.preknown_dev_list;
    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICES_CNF, (void*)msg_cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_power_on_req_hdler
 * DESCRIPTION
 *  This function is to handle power on request
 * PARAMETERS
 *  msg             [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_power_on_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_state_enum bth_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_POWER_ON_REQ, srv_bt_cm_get_state(), srv_bt_cm_is_activated() );

	bth_state = srv_bt_cm_get_state();
	
    if (srv_bt_cm_is_activated())
    {
    	if (bth_state < SRV_BT_CM_STATE_IDLE && bth_state != SRV_BT_CM_STATE_DEACTIVATING)
    	{
			/* switching power to be on */    		
			mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_during_power_switching);
    	}
		else if (bth_state == SRV_BT_CM_STATE_DEACTIVATING)
		{
			/* switching power to be off */    		
			mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_during_power_switching);
		}
		else if (srv_bt_cm_is_simap_activate())
		{
			/* simap is activated, might have to prohibit other Bluetoot operation */    		
			mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_simap_activated);
		}
		else
		{
#ifndef __MMI_BT_IN_FLIGHT_MODE__
			if (srv_mode_switch_is_network_service_available())
			{

				/* not allow to power on BT because of flight mode */ 
				mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_in_flight_mode);
			}
			else
#endif /*__MMI_BT_IN_FLIGHT_MODE__*/               
			{
				/* power is already on */    		
				mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_power_already_on);
			}
		}
		
    }
	else
	{
    	if (bth_state == SRV_BT_CM_STATE_INIT_ON || bth_state == SRV_BT_CM_STATE_IDLE)
		{
#ifndef __MMI_BT_IN_FLIGHT_MODE__
			/* power is off */
			if (srv_mode_switch_is_network_service_available())
			{

				/* not allow to power on BT because of flight mode */ 
				mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_in_flight_mode);
			}
			else
#endif /*__MMI_BT_IN_FLIGHT_MODE__*/                
			{
				/* switch the power on */
				//srv_bt_cm_set_flag(SRV_BT_CM_MASK_ACTIVATED);
				srv_bt_cm_switch_on();
				srv_bt_cm_register_operation_callback(SRV_BT_CM_OPER_TYPE_POWER_ON, (FuncPtr)mmi_bth_bcc_power_on_cb_hdler);
				
			}
				
		}
		else
		{
			/* un-expected state */
			MMI_BT_ASSERT(0);
		}
		
	}


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_restore_req_hdler
 * DESCRIPTION
 *  This function is to handle restore request
 * PARAMETERS
 *  msg             [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_restore_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_bt_cm_state_enum bth_state;
     /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_QUERY_CM_STATUS, 
    				srv_bt_cm_get_state(), 
    				srv_bt_cm_is_activated(),
					g_mmi_bth_bcc_cntx.bt_setting_modified,
    				srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON,
	 				g_mmi_bth_bcc_cntx.jsr_discoverable_mode,
					srv_bt_cm_get_host_dev_security_level());
	
	bth_state = srv_bt_cm_get_state();
	if (bth_state != SRV_BT_CM_STATE_IDLE)
	{
		mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_failed);	
	}
	else
	{
		/* host dev name */
		if (g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_HOST_NAME)
		{
			srv_bt_cm_set_host_dev_name(g_mmi_bth_bcc_cntx.host_dev_name);
			srv_bt_cm_register_operation_callback(SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME, (FuncPtr)mmi_bth_bcc_set_host_device_name_cb_hdler);
			MMI_BTH_BCC_STATE_TRANS(MMI_BTH_BCC_STAT_HOST_NAME_RESTORING);
 		}
		else if (g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_DISCOVERABLE_MODE)
		{
			g_mmi_bth_bcc_cntx.jsr_discoverable_mode = (U8)g_mmi_bth_bcc_cntx.discoverable_mode;
			srv_bt_cm_set_discoverable_mode((U32)g_mmi_bth_bcc_cntx.discoverable_mode);
			srv_bt_cm_register_operation_callback(SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE, (FuncPtr)mmi_bth_bcc_set_discoverable_mode_cb_hdler);
			MMI_BTH_BCC_STATE_TRANS(MMI_BTH_BCC_STAT_DISCOVERABLE_MODE_RESTORING);
		}
		else
		{
			mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_succeeded);	
		}
			
  
		
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_set_host_device_name_req_hdler
 * DESCRIPTION
 *  This function is to handle set host device name request
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_set_host_device_name_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_state_enum bth_state;
	mmi_bt_bcc_set_host_device_name_req_struct *inf_p = (mmi_bt_bcc_set_host_device_name_req_struct *)msg;
	srv_bt_cm_dev_struct *host_dev_p;
     /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_QUERY_CM_STATUS, 
    				srv_bt_cm_get_state(), 
    				srv_bt_cm_is_activated(),
					g_mmi_bth_bcc_cntx.bt_setting_modified,
    				srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON,
	 				g_mmi_bth_bcc_cntx.jsr_discoverable_mode,
					srv_bt_cm_get_host_dev_security_level());

	bth_state = srv_bt_cm_get_state();
	if (bth_state != SRV_BT_CM_STATE_IDLE || !srv_bt_cm_is_activated())
	{
		mmi_bth_bcc_set_host_device_name_cnf_hdler(mmi_bt_bcc_result_failed);	
	}
	else
	{
		if (!(g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_HOST_NAME))
		{
			/* store the host dev name */
			g_mmi_bth_bcc_cntx.bt_setting_modified |= MMI_BTH_BCC_HOST_NAME;
			host_dev_p = srv_bt_cm_get_host_dev_info();
			memcpy(g_mmi_bth_bcc_cntx.host_dev_name, host_dev_p->name, MMI_BT_BCC_MAX_HOST_DEV_NAME_LEN);
		}

		srv_bt_cm_set_host_dev_name(inf_p->dev_name);
		srv_bt_cm_register_operation_callback(SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME, (FuncPtr)mmi_bth_bcc_set_host_device_name_cb_hdler);
		
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_host_device_name_req_hdler
 * DESCRIPTION
 *  This function is to handle get host device name request and send MSG_ID_MMI_BT_BCC_GET_HOST_DEVICE_NAME_CNF
 * PARAMETERS
 *  msg         [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_get_host_device_name_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_get_host_device_name_cnf_struct *msg_cnf_p;
	srv_bt_cm_dev_struct *host_dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_GET_HOST_DEV_NAME);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_QUERY_CM_STATUS, 
    				srv_bt_cm_get_state(), 
    				srv_bt_cm_is_activated(),
					g_mmi_bth_bcc_cntx.bt_setting_modified,
    				srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON,
	 				g_mmi_bth_bcc_cntx.jsr_discoverable_mode,
					srv_bt_cm_get_host_dev_security_level());

    msg_cnf_p = (mmi_bt_bcc_get_host_device_name_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_get_host_device_name_cnf_struct), TD_CTRL);
	/* host device name */
    msg_cnf_p->result = mmi_bt_bcc_result_succeeded;
	host_dev_p = srv_bt_cm_get_host_dev_info();
	memcpy(msg_cnf_p->dev_name, host_dev_p->name, MMI_BT_BCC_MAX_HOST_DEV_NAME_LEN);

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_GET_HOST_DEVICE_NAME_CNF, (void*)msg_cnf_p, NULL);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_set_discoverable_mode_req_hdler
 * DESCRIPTION
 *  This function is to handle set discoverable mode request
 * PARAMETERS
 *  msg         [IN]            interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_set_discoverable_mode_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_state_enum bth_state;
	mmi_bt_bcc_set_discoverable_mode_req_struct *inf_p = (mmi_bt_bcc_set_discoverable_mode_req_struct *)msg;
	MMI_BOOL visibility;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_QUERY_CM_STATUS, 
    				srv_bt_cm_get_state(), 
    				srv_bt_cm_is_activated(),
					g_mmi_bth_bcc_cntx.bt_setting_modified,
    				srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON,
	 				g_mmi_bth_bcc_cntx.jsr_discoverable_mode,
					srv_bt_cm_get_host_dev_security_level());

	bth_state = srv_bt_cm_get_state();
	if (bth_state != SRV_BT_CM_STATE_IDLE || !srv_bt_cm_is_activated())
	{
		mmi_bth_bcc_set_discoverable_mode_cnf_hdler(mmi_bt_bcc_result_failed);	
	}
	else
	{
		if (!(g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_DISCOVERABLE_MODE))
		{
			/* store the discoverable mode */
			g_mmi_bth_bcc_cntx.bt_setting_modified |= MMI_BTH_BCC_DISCOVERABLE_MODE;
			if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON)
			{
			    g_mmi_bth_bcc_cntx.discoverable_mode = mmi_bt_bcc_discoverable_mode_p_on_i_on;
			}
			else
			{
			    g_mmi_bth_bcc_cntx.discoverable_mode = mmi_bt_bcc_discoverable_mode_p_on_i_off;
			}
		}

		g_mmi_bth_bcc_cntx.jsr_discoverable_mode = (U8)inf_p->discoverable_mode;
		srv_bt_cm_set_discoverable_mode((U32)inf_p->discoverable_mode);
		srv_bt_cm_register_operation_callback(SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE, (FuncPtr)mmi_bth_bcc_set_discoverable_mode_cb_hdler);
		
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_discoverable_mode_req_hdler
 * DESCRIPTION
 *  This function is to handle get discoverable mode request and send MSG_ID_MMI_BT_BCC_GET_DISCOVERABLE_MODE_CNF
 * PARAMETERS 
 *  msg             [IN]        interlayer message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_get_discoverable_mode_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_get_discoverable_mode_cnf_struct *msg_cnf_p;
	MMI_BOOL visibility;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_GET_DISCOVERABLE_MODE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_QUERY_CM_STATUS, 
    				srv_bt_cm_get_state(), 
    				srv_bt_cm_is_activated(),
					g_mmi_bth_bcc_cntx.bt_setting_modified,
    				srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON,
	 				g_mmi_bth_bcc_cntx.jsr_discoverable_mode,
					srv_bt_cm_get_host_dev_security_level());

    msg_cnf_p = (mmi_bt_bcc_get_discoverable_mode_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_get_discoverable_mode_cnf_struct), TD_CTRL);
	/* discoverable mode */
    msg_cnf_p->result = mmi_bt_bcc_result_succeeded;
	if (g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_DISCOVERABLE_MODE)
	{
		msg_cnf_p->discoverable_mode = g_mmi_bth_bcc_cntx.jsr_discoverable_mode;
	}
	else
	{
		if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON)
		{
		    msg_cnf_p->discoverable_mode = mmi_bt_bcc_discoverable_mode_p_on_i_on;
		}
		else
		{
		    msg_cnf_p->discoverable_mode = mmi_bt_bcc_discoverable_mode_p_on_i_off;
		}

	}

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_GET_DISCOVERABLE_MODE_CNF, (void*)msg_cnf_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_native_pwr_status_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_get_native_pwr_status_req_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_state_enum bth_state;
    mmi_bt_bcc_get_native_pwr_status_cnf_struct *msg_cnf_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_NATIVE_PWR_STATUS_REQ, srv_bt_cm_get_state(), srv_bt_cm_is_activated() );

    msg_cnf_p = (mmi_bt_bcc_get_native_pwr_status_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_get_native_pwr_status_cnf_struct), TD_CTRL);
	bth_state = srv_bt_cm_get_state();
	
    if (srv_bt_cm_is_activated())
    {
    	if (bth_state < SRV_BT_CM_STATE_IDLE && bth_state != SRV_BT_CM_STATE_DEACTIVATING)
    	{
			/* switching power to be on */    		
		    msg_cnf_p->native_pwr_status = mmi_bt_bcc_native_pwr_switching_on;
    	}
		else if (bth_state == SRV_BT_CM_STATE_DEACTIVATING)
		{
			/* switching power to be off */    		
		    msg_cnf_p->native_pwr_status = mmi_bt_bcc_native_pwr_switching_off;
		}
		else
		{
			/* power is already on */    		
		    msg_cnf_p->native_pwr_status = mmi_bt_bcc_native_pwr_on;
		}
		
    }
	else
	{
		/* power is already off */    		
	    msg_cnf_p->native_pwr_status = mmi_bt_bcc_native_pwr_off;
	}

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_GET_NATIVE_PWR_STATUS_CNF, (void*)msg_cnf_p, NULL);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_power_on_cnf_hdler
 * DESCRIPTION
 *  This function is to handle power on confirm and send MSG_ID_MMI_BT_BCC_POWER_ON_CNF
 * PARAMETERS
 *  result          [IN]        power on result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_code result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_power_on_cnf_struct *msg_cnf_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_cnf_p = (mmi_bt_bcc_power_on_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_power_on_cnf_struct), TD_CTRL);
	/* result */
    msg_cnf_p->result = result;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_POWER_ON_CNF, (void*)msg_cnf_p, NULL);
	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_POWER_ON);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_power_on_cb_hdler
 * DESCRIPTION
 *  This function is to handle power on callback and invoke mmi_bth_bcc_power_on_cnf_hdler
 * PARAMETERS
 *  param_p         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_power_on_cb_hdler(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bth_bcc_power_on_cb_struct *inf_p = (mmi_bth_bcc_power_on_cb_struct*)param_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (inf_p->result == mmi_bt_bcc_result_succeeded)
	{
		mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_succeeded);
	}
	else
	{

		mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_failed);
	}

	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_POWER_ON);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_restore_cnf_hdler
 * DESCRIPTION
 *  This function is to handle restore confirm and send MSG_ID_MMI_BT_BCC_RESTORE_CNF
 * PARAMETERS
 *  result          [IN]        restore result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_code result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_restore_cnf_struct *msg_cnf_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_cnf_p = (mmi_bt_bcc_restore_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_restore_cnf_struct), TD_CTRL);
	/* result */
    msg_cnf_p->result = result;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_RESTORE_CNF, (void*)msg_cnf_p, NULL);
	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_RESTORE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_restore_cb_hdler
 * DESCRIPTION
 *  This function is to handle restore callback and invoke mmi_bth_bcc_restore_cnf_hdler
 * PARAMETERS
 *  param_p         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_restore_cb_hdler(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bth_bcc_restore_cb_struct *inf_p = (mmi_bth_bcc_restore_cb_struct*)param_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (inf_p->result == mmi_bt_bcc_result_succeeded)
	{
		mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_succeeded);
	}
	else
	{

		mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_failed);
	}

	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_RESTORE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_set_host_device_name_cnf_hdler
 * DESCRIPTION
 *  This function is to handle set host device name confirm and send MSG_ID_MMI_BT_BCC_SET_HOST_DEVICE_NAME_CNF
 * PARAMETERS
 *  result          [IN]        set host device name result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_set_host_device_name_cnf_hdler(mmi_bt_bcc_result_code result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_set_host_device_name_cnf_struct *msg_cnf_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_cnf_p = (mmi_bt_bcc_set_host_device_name_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_set_host_device_name_cnf_struct), TD_CTRL);
	/* result */
    msg_cnf_p->result = result;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_SET_HOST_DEVICE_NAME_CNF, (void*)msg_cnf_p, NULL);

	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_set_host_device_name_cb_hdler
 * DESCRIPTION
 *  This function is to handle set host device name callback and invoke mmi_bth_bcc_set_host_device_name_cnf_hdler
 * PARAMETERS
 *  param_p         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_set_host_device_name_cb_hdler(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bth_bcc_set_host_device_name_cb_struct *inf_p = (mmi_bth_bcc_set_host_device_name_cb_struct*)param_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (g_mmi_bth_bcc_cntx.state)
	{
		case MMI_BTH_BCC_STAT_HOST_NAME_RESTORING:
				if (g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_DISCOVERABLE_MODE &&
					inf_p->result == mmi_bt_bcc_result_succeeded)
				{
					g_mmi_bth_bcc_cntx.jsr_discoverable_mode = (U8)g_mmi_bth_bcc_cntx.discoverable_mode;
					srv_bt_cm_set_discoverable_mode((U32)g_mmi_bth_bcc_cntx.discoverable_mode);
					srv_bt_cm_register_operation_callback(SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE, (FuncPtr)mmi_bth_bcc_set_discoverable_mode_cb_hdler);
					MMI_BTH_BCC_STATE_TRANS(MMI_BTH_BCC_STAT_DISCOVERABLE_MODE_RESTORING);
				}
				else
				{
					if (inf_p->result == mmi_bt_bcc_result_succeeded)
					{
						mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_succeeded);
					}
					else
					{

						mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_failed);
					}
					MMI_BTH_BCC_STATE_TRANS(MMI_BTH_BCC_STAT_IDLE);
				}
				g_mmi_bth_bcc_cntx.bt_setting_modified &= ~MMI_BTH_BCC_HOST_NAME;
				break;
		default:	
				if (inf_p->result == mmi_bt_bcc_result_succeeded)
				{
					mmi_bth_bcc_set_host_device_name_cnf_hdler(mmi_bt_bcc_result_succeeded);
				}
				else
				{

					mmi_bth_bcc_set_host_device_name_cnf_hdler(mmi_bt_bcc_result_failed);
				}
				break;

	}


	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_set_discoverable_mode_cnf_hdler
 * DESCRIPTION
 *  This function is to handle set discoverable mode confirm and send MSG_ID_MMI_BT_BCC_SET_DISCOVERABLE_MODE_CNF
 * PARAMETERS
 *  result          [IN]        set discoveralbe mode result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_set_discoverable_mode_cnf_hdler(mmi_bt_bcc_result_code result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_set_discoverable_mode_cnf_struct *msg_cnf_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_cnf_p = (mmi_bt_bcc_set_discoverable_mode_cnf_struct*) construct_local_para(sizeof(mmi_bt_bcc_set_discoverable_mode_cnf_struct), TD_CTRL);
	/* result */
    msg_cnf_p->result = result;

    srv_bt_cm_send_msg(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_BT_BCC_SET_DISCOVERABLE_MODE_CNF, (void*)msg_cnf_p, NULL);

	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME);
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_set_discoverable_mode_cb_hdler
 * DESCRIPTION
 *  This function is to handle set discoverable mode callback and invoke mmi_bth_bcc_set_discoverable_mode_cnf_hdler
 * PARAMETERS
 *  param_p     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_bcc_set_discoverable_mode_cb_hdler(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bth_bcc_set_discoverable_mode_cb_struct *inf_p = (mmi_bth_bcc_set_discoverable_mode_cb_struct*)param_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch (g_mmi_bth_bcc_cntx.state)
	{
		case MMI_BTH_BCC_STAT_DISCOVERABLE_MODE_RESTORING:
				if (inf_p->result == mmi_bt_bcc_result_succeeded)
				{
					mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_succeeded);
				}
				else
				{

					mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_failed);
				}
				MMI_BTH_BCC_STATE_TRANS(MMI_BTH_BCC_STAT_IDLE);
				g_mmi_bth_bcc_cntx.bt_setting_modified &= ~MMI_BTH_BCC_DISCOVERABLE_MODE;
				break;
		default:	
				if (inf_p->result == mmi_bt_bcc_result_succeeded)
				{
					mmi_bth_bcc_set_discoverable_mode_cnf_hdler(mmi_bt_bcc_result_succeeded);
				}
				else
				{

					mmi_bth_bcc_set_discoverable_mode_cnf_hdler(mmi_bt_bcc_result_failed);
				}
				break;

	} 

	srv_bt_cm_unregister_operation_callback(SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bcc_get_discoverable_mode
 * DESCRIPTION
 *  This function is to get discoverable mode
 * PARAMETERS
 *  void
 * RETURNS
 *  U8          discoverable mode
 *****************************************************************************/
U8 mmi_bth_bcc_get_discoverable_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 result;
	MMI_BOOL visibility;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_QUERY_CM_STATUS, 
    				srv_bt_cm_get_state(), 
    				srv_bt_cm_is_activated(),
					g_mmi_bth_bcc_cntx.bt_setting_modified,
              srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON,
	 				g_mmi_bth_bcc_cntx.jsr_discoverable_mode,
					srv_bt_cm_get_host_dev_security_level());

	if (g_mmi_bth_bcc_cntx.bt_setting_modified & MMI_BTH_BCC_DISCOVERABLE_MODE)
	{
		result = g_mmi_bth_bcc_cntx.jsr_discoverable_mode;
	}
	else
	{
		if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON)
		{
		    result = mmi_bt_bcc_discoverable_mode_p_on_i_on;
		}
		else
		{
		    result = mmi_bt_bcc_discoverable_mode_p_on_i_off;
		}
	}
		
	return result;
}


#endif /* __SUPPORT_JBT__ */ 

