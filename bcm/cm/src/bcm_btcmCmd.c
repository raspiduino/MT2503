/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE: BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES:
*  EXPRESS OR IMPLIED: INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY: FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY: INCORPORATED IN: OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE: AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE:
*  AT MEDIATEK'S OPTION: TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE:
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA: USA: EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES: CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO: CA: UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bcm_cmd.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for handling cmd from atci.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 16 2016 ye.tian
 * removed!
 * fix 'cnf' memory leak in cmd_hdlr_bt_profile_act_cnf().
 *
 * 03 10 2015 zhen.tian
 * removed!
 * .
 *
 * 03 09 2015 zhen.tian
 * removed!
 * .
 *
 * 03 04 2015 xiaowei.wang
 * removed!
 * .
 *
 * 01 27 2015 zhen.tian
 * removed!
 * .
 *
 * 01 23 2015 zhen.tian
 * removed!
 * .
 *
 * 09 29 2014 chaonan.zhao
 * removed!
 * .
 *
 * 07 01 2014 chaonan.zhao
 * removed!
 * add compile option"__BT_SPP_PROFILE__" to "#include "BcmSppUtility.h"".
 *
 * 05 15 2014 guoqing.ren
 * removed!
 * fix pbap server connect output error when success.
 *
 * 05 13 2014 guoqing.ren
 * removed!
 * fix many bugs in ebtpact handling.
 *
>>>> ORIGINAL //MAUI/BRANCHES_11C/11CW1418MP/mcu/bcm/cm/src/bcm_btcmCmd.c#6
==== THEIRS //MAUI/BRANCHES_11C/11CW1418MP/mcu/bcm/cm/src/bcm_btcmCmd.c#11
 * 05 09 2014 hujin.hu
 * removed!
 * add HFP bt state.
 *
 * 05 09 2014 hujin.hu
 * removed!
 * .
 *
 * 05 08 2014 hujin.hu
 * removed!
 * .
 *
==== YOURS //ws_xiuqin.hu_3015/MAUI/BRANCHES_11C/11CW1418SP/mcu/bcm/cm/src/bcm_btcmCmd.c
 * 05 13 2014 hujin.hu
 * removed!
 * patch HFP back to 1418SP.
 *
<<<<
 * 04 18 2014 hujin.hu
 * removed!
 * .
 *
 * 04 17 2014 hujin.hu
 * removed!
 * .
 *
 * 04 11 2014 hujin.hu
 * removed!
 * .
 *
 * 04 09 2014 yinling.he
 * removed!
 * check in OPP PBAP code.
 *
 * 04 09 2014 hujin.hu
 * removed!
 * [M2M]HFP checkin.
 *
 * 03 21 2014 yinling.he
 * removed!
 * [M2M] check in OPP & PBAPC code.
 *
 * 02 20 2014 guoqing.ren
 * removed!
 * sppc connect fail also need destory inst.
 *
 * 02 19 2014 guoqing.ren
 * removed!
 * fix spp client definition and some  spp client connect issue.
 *
 * 02 18 2014 guoqing.ren
 * removed!
 * Fix PAIR way judge condition when confirm them.
 *
 * 02 17 2014 guoqing.ren
 * removed!
 * 	Adjust the mem allocate location to avoid memory leak.
 *
 * 02 17 2014 guoqing.ren
 * removed!
 * 	diff PIN Code accept/reject with PASSKEY Code accept/reject msg flow.
 *
 * 02 14 2014 guoqing.ren
 * removed!
 * 	Add operation condition for pair reject cnf.
 *
 * 02 14 2014 guoqing.ren
 * removed!
 * 	Add operation condition for pair reject cnf.
 *
 * 02 11 2014 guoqing.ren
 * removed!
 * 	Fix BT NVRAM define, and we found that BT ADDR need change LID.
 *
 * 02 10 2014 guoqing.ren
 * removed!
 * 	Fix bug that when got state of a conn with an addr we didn't consider the conn role.
 *
 *------------------------------------------------------------------------------
 * Upper this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_AT_CMD__

/*****************
Include Statements
******************/
//#include "kal_release.h"      	/* Basic data type */

//#include "stack_common.h"  
//#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */

//#include "stacklib.h"        	/* Basic type for dll: evshed: stacktimer */

//#include "event_shed.h"       	/* Event scheduler */

//#include "stack_timer.h"      	/* Stack timer */
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "Bcm_btcmSrvProt.h"
#ifdef __BT_SPP_PROFILE__
#include "BcmSppSrv.h"
#include "bcm_spp_app.h"
#endif
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"
#include "bcmadp.h"
#include "bcm_struct.h"
#include "Bcm_btcmSrvGprot.h"
#include "btdrv_types.h"
#include "bcm_btcmApp.h"
#include "Bluetooth_struct.h"
#include "nvram_editor_data_item.h"
#ifdef __BT_SPP_PROFILE__
#include "BcmSppUtility.h"
#endif
#include "bcm_btcmCmd.h"
#ifdef __BT_PBAP_CLIENT__
#include "bcm_pbapGprot.h"
#endif
#if defined(__BT_HF_PROFILE__)
#include "bcm_hfpApp.h"
#endif/*#if defined(__BT_HFG_PROFILE__)*/

#if defined(__BT_HFG_PROFILE__)
#include "bcm_BthfSrv.h"
#include "bcm_BthfSrvGprot.h"
#include "bcm_BthScoPathSrvGprot.h"
#endif/*#if defined(__BT_HFG_PROFILE__)*/


extern bcm_context_struct *BCM_PTR;

const kal_uint32 index_profile_map[] = 
{
    SRV_BT_CM_SPP_PROFILE_UUID,

	SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID,
	SRV_BT_CM_OBEX_PBA_PROFILE_UUID,
	SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID,
	SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID,
	
	SRV_BT_CM_HF_PROFILE_UUID,
	SRV_BT_CM_HFG_PROFILE_UUID,

    /* please add new profile UUID before this line,
      *   and after any exisited profile in this array.
      *   after you added new profile, you should also enlarge this array's size.
      *   the maxmum size of this array is 64, 
      *   if you need larger, we also need larger interface between BCM & ATCI. 
      *   or else profiles larger than 64 will not paser to profile bit map.
      */
};

kal_bool is_bt_cmd_cm_allow(ilm_struct* msg)
{
    kal_bool is_allow = KAL_FALSE;
    switch(msg->msg_id)
    {
        case MSG_ID_BCM_POWER_ONOFF_REQ:
        {
            bcm_power_onoff_req_struct *req = (bcm_power_onoff_req_struct*)msg->local_para_ptr;
            if(req->on_off == 0)//power on
            {
                if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_INIT_ON)
                    is_allow = KAL_TRUE;
            }
            else //power off
            {
                if(srv_bt_cm_get_state() >= SRV_BT_CM_STATE_IDLE)
                    is_allow = KAL_TRUE;
            }
        }
            break;
        case MSG_ID_BCM_WRITE_LOCAL_NAME_REQ:
        case MSG_ID_BCM_READ_LOCAL_NAME_REQ: 
        case MSG_ID_BCM_DISCOVERY_PARA_REQ:
        case MSG_ID_BCM_WRITE_AUTHENTICATION_MODE_REQ:
        case MSG_ID_BCM_READ_AUTHENTICATION_MODE_REQ:
        case MSG_ID_BCM_SNIFF_PARA_REQ:
        case MSG_ID_BCM_PROFILE_CONN_REQ:
        {
            if(srv_bt_cm_get_state() >= SRV_BT_CM_STATE_IDLE)
            {
                is_allow = KAL_TRUE;
            }
        }
            break;
        case MSG_ID_BCM_WRITE_LOCAL_ADDR_REQ:
        {
            if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_INIT_ON)
                is_allow = KAL_TRUE;
        }        
            break;
        case MSG_ID_BCM_WRITE_SCANENABLE_MODE_REQ:
        case MSG_ID_BCM_READ_REMOTE_NAME_REQ:
        case MSG_ID_BCM_SERVICE_SEARCH_REQ:
        case MSG_ID_BCM_DEV_LIST_OP_REQ:
        case MSG_ID_BCM_PROFILE_ACT_REQ:
        {
            if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_IDLE)
            {
                is_allow = KAL_TRUE;
            }
        }
            break;
        case MSG_ID_BCM_DISCOVERY_REQ:
        {
            #ifdef __SP_BT_STACK__ // srv_bt_cm_search() already has this check, so we ignore here.
            if((srv_bt_cm_get_state() >= SRV_BT_CM_STATE_IDLE) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_INQUIRING) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_INQUIR_RES_IND) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_INQUIR_CANCELLING) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_BONDING) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_PASSKEY_IND) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_PASSKEY_RES) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_NUMERIC_CONFIRM) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_PASSKEY_NOTIFY) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL) &&
                (srv_bt_cm_get_state() != SRV_BT_CM_STATE_SDC_SEARCHING))
            #endif
            {
                is_allow = KAL_TRUE;
            }
        }
            break;
        case MSG_ID_BCM_DISCOVERY_CANCEL_REQ:
        {
            #ifdef __SP_BT_STACK__ // srv_bt_cm_search_abort() already has this check, so we ignore here.
            if((srv_bt_cm_get_state() == SRV_BT_CM_STATE_INQUIRING) ||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_INQUIR_RES_IND))
            #endif
            {
                is_allow = KAL_TRUE;
            }
        }
            break;
        case MSG_ID_BCM_BONDING_REQ:
        {
            #ifdef __SP_BT_STACK__ // srv_bt_cm_bond() already has this check, so we ignore here.
            if((srv_bt_cm_get_state() == SRV_BT_CM_STATE_IDLE) ||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_INQUIRING)||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_INQUIR_RES_IND))
            #endif
            {
                is_allow = KAL_TRUE;
            }
        }
        
            break;
        case MSG_ID_BCM_BONDING_RSP_REQ:
        {
            if((srv_bt_cm_get_state() == SRV_BT_CM_STATE_PASSKEY_NOTIFY) ||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_NUMERIC_CONFIRM)||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_PASSKEY_IND)||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_BONDING)||
                (srv_bt_cm_get_state() == SRV_BT_CM_STATE_CONNECTING))
            {
                is_allow = KAL_TRUE;
            }
        }
            break;       
        case MSG_ID_BCM_READ_LOCAL_ADDR_REQ:
        case MSG_ID_BCM_PROFILE_STATE_QUERY_REQ:
        case MSG_ID_BCM_CM_STATE_QUERY_REQ:
        case MSG_ID_BCM_RSSI_REQ:		
#if defined(__BT_HFG_PROFILE__)
		case MSG_ID_BCM_HFG_READ_AUDIO_PATH_REQ:
#endif
        {
            {
                is_allow = KAL_TRUE;
            }
        }
            break;
        default:
            break;
    }
    
    BCM_STATE_ENTRY(STATE_CM_STATE_ALLOW,is_allow);
    
    return is_allow;
}

kal_bool is_bt_cmd_profile_allow(ilm_struct* msg)
{
    kal_uint32 profile;
    kal_bool is_allow = KAL_FALSE;
    switch(msg->msg_id)
    {
        case MSG_ID_BCM_PROFILE_CONN_REQ:
        {
            
            srv_bt_cm_bt_addr dev_addr;
    
            bcm_profile_conn_req_struct *req = (bcm_profile_conn_req_struct*)msg->local_para_ptr;
    
            dev_addr.lap = req->bd_addr.lap;
            dev_addr.uap = req->bd_addr.uap;
            dev_addr.nap = req->bd_addr.nap;
            
            profile = req->profile;
#ifdef __BT_SPP_PROFILE__
            if(req->profile == SRV_BT_CM_SPP_PROFILE_UUID)//
            {
                //server role is ALW open, here we use it to accept or reject an client.
                if(req->role)//server, 
                {
                    if(req->op == 0)//disconnect, means server want disconnected or reject the aurhorizing 
                    {
                        if(srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_AUTHORIZING ||
                            srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_CONNECTED)
                            is_allow = KAL_TRUE;

                    }
                    else // connect, means server want accept the aurhorizing
                    {
                        if(srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_AUTHORIZING)
                            is_allow = KAL_TRUE;
                    }
                }
                else //client
                {
                    if(req->op == 0)//disconnect
                    {
                        if(srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_ACTIVATE ||
                            srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_AUTHORIZING ||
                            srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_CONNECTED)
                            is_allow = KAL_TRUE;

                    }
                    else // connect
                    {
                        if(srv_bt_spp_get_state(dev_addr,req->role) == SRV_SPP_CONN_STATE_IDLE)
                            is_allow = KAL_TRUE;
                    }
                }
            }
#endif
#ifdef __BT_PBAP_CLIENT__
            if(req->profile == SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID)//
            {
                is_allow = KAL_TRUE;                
            }
#endif /*__BT_PBAP_CLIENT__*/

#ifdef __BCM_PBAP_SERVER__
            if(req->profile == SRV_BT_CM_OBEX_PBA_PROFILE_UUID)//
            {
                is_allow = KAL_TRUE;                
            }
#endif /*__BT_PBAP_CLIENT__*/
#ifdef __MMI_OPP_SUPPORT__
            if(req->profile == SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID
                || req->profile == SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID)//
            {
                is_allow = KAL_FALSE; /* OPP will manage its connection itself, don't use BTCM conn msg for OPP*/
            }
#endif /*__MMI_OPP_SUPPORT__*/


#ifdef __BT_HF_PROFILE__
			if(req->profile == SRV_BT_CM_HF_PROFILE_UUID)//
			{
				//server role is ALW open, here we use it to accept or reject an client.
				if(req->role == 0)// HF
				{
					if(req->op == 0)//disconnect
					{
						is_allow = KAL_TRUE;
					}
					else // connect
					{
						is_allow = KAL_TRUE;
					}
				}
			}
#endif/*__BT_HF_PROFILE__*/
#ifdef __BT_HFG_PROFILE__
			if(req->profile == SRV_BT_CM_HFG_PROFILE_UUID)//
			{
				//server role is ALW open, here we use it to accept or reject an client.
				if(req->role)//AG 
				{
					if(req->op == 0)//disconnect, means server want disconnected or reject the aurhorizing 
					{
						is_allow = KAL_TRUE;

					}
					else // connect, means server want accept the aurhorizing
					{
						is_allow = KAL_TRUE;
					}
				}
			}
#endif/*__BT_HFG_PROFILE__*/
#ifdef __BT_A2DP_PROFILE__
			if(req->profile == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)//
			{
				//server role is ALW open, here we use it to accept or reject an client.
				if(req->role)//AG 
				{
					if(req->op == 0)//disconnect, means server want disconnected or reject the aurhorizing 
					{
						is_allow = KAL_TRUE;

					}
					else // connect, means server want accept the aurhorizing
					{
						is_allow = KAL_TRUE;
					}
				}
			}

#endif/*__BT_HFG_PROFILE__*/

        }
            break;
        default:
            is_allow = KAL_TRUE;
            break;
    }
    BCM_STATE_ENTRY(STATE_PROFILE_STATE_ALLOW,profile,is_allow);
    return is_allow;

}

void cmd_hdlr_bt_power_on_req(ilm_struct* msg)
{
    bcm_power_onoff_req_struct *req = (bcm_power_onoff_req_struct*)msg->local_para_ptr;
    
    BCM_FUNC_ENTRY(FUNC_BCM_BT_POWER_ON_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if(req->on_off)// 1 power off
        {
            srv_bt_cm_switch_off();
            bcm_set_ext_cm_state(BCM_EXT_CM_STATE_UNKNOWN);
        }
        else //0 power on
        {
            srv_bt_cm_switch_on();
            bcm_set_ext_cm_state(BCM_EXT_CM_STATE_START);
        }
    }
    else
    {   
        cmd_hdlr_bt_power_on_cnf(KAL_FALSE);
    }
}
void cmd_hdlr_bt_power_on_cnf(kal_uint8 result)
{
    bcm_power_onoff_cnf_struct *cnf = NULL;   
    BCM_FUNC_ENTRY(FUNC_BCM_BT_POWER_ON_CNF);

    //when BT RESET, this api will be called, so we need this condition.
    if(BCM_PTR->curr_req == MSG_ID_BCM_POWER_ONOFF_REQ)
    {
        cnf = (bcm_power_onoff_cnf_struct*)construct_local_para(sizeof(bcm_power_onoff_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_POWER_ONOFF_CNF, cnf, NULL);

        if(result == KAL_TRUE)
        {
            if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_IDLE)
            {
                bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);
            }
            else
            {
                bcm_set_ext_cm_state(BCM_EXT_CM_STATE_UNKNOWN);
            }
        }
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_write_local_name_req(ilm_struct* msg)
{
    bcm_write_local_name_req_struct *req = (bcm_write_local_name_req_struct*)msg->local_para_ptr;
    kal_uint8 *name = NULL;
    
    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_LOCAL_NAME_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;

    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if(req->name_len > 0 && req->name)
        {
            name = (kal_uint8*)get_ctrl_buffer(req->name_len+2);
            memcpy(name,req->name,req->name_len);
            name[req->name_len] = '\0';
            srv_bt_cm_set_host_dev_name(name);
            free_ctrl_buffer(name);
        }
        else
        {
            cmd_hdlr_bt_write_local_name_cnf(KAL_FALSE);
        }
    }
    else
    {   
        cmd_hdlr_bt_write_local_name_cnf(KAL_FALSE);
    }
}
void cmd_hdlr_bt_write_local_name_cnf(kal_uint8 result)
{
    bcm_write_local_name_cnf_struct *cnf = NULL;
    
    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_LOCAL_NAME_CNF);
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_write_local_name_cnf_struct*)construct_local_para(sizeof(bcm_write_local_name_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_WRITE_LOCAL_NAME_CNF, cnf, NULL);
    }
    
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_read_local_name_req(ilm_struct* msg)
{
    bcm_read_local_name_req_struct *req = (bcm_read_local_name_req_struct*)msg->local_para_ptr;
    
    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_LOCAL_NAME_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_host_dev_info();
        cmd_hdlr_bt_read_local_name_cnf(KAL_TRUE,dev_info->name,strlen(dev_info->name));
    }
    else
    {   
        cmd_hdlr_bt_read_local_name_cnf(KAL_FALSE,NULL,0);
    }
}
void cmd_hdlr_bt_read_local_name_cnf(kal_uint8 result,kal_uint8 *name,kal_uint8 name_len)
{
    bcm_read_local_name_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_LOCAL_NAME_CNF);
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_read_local_name_cnf_struct*)construct_local_para(sizeof(bcm_read_local_name_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;

        if(result)
        {
            cnf->name_len = name_len > (BTBM_ADP_MAX_NAME_LEN - 1) ?
                (BTBM_ADP_MAX_NAME_LEN - 1) : name_len;
            if(name && name_len > 0)
            {
                memcpy(cnf->name,name,name_len);
            }
        }

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_READ_LOCAL_NAME_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_write_local_addr_req(ilm_struct* msg)
{
    bcm_write_local_addr_req_struct *req = (bcm_write_local_addr_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_LOCAL_ADDR_REQ);    
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        nvram_ef_btradio_mtk_bt_chip_struct read_struct;
        srv_bt_cm_nvram_struct read_struct2;
        
        //MOD_BT READ THIS LID EARCH TIME BT START
        if(KAL_TRUE == nvram_external_read_data(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID, 1, (kal_uint8*)&read_struct, NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE))
        {
            read_struct.BDAddr[0] = (req->bd_addr.lap & 0xFF);
            read_struct.BDAddr[1] = ((req->bd_addr.lap >> 8) & 0xFF);
            read_struct.BDAddr[2] = ((req->bd_addr.lap >> 16) & 0xFF);
            read_struct.BDAddr[3] = req->bd_addr.uap;
            read_struct.BDAddr[4] = ((req->bd_addr.nap & 0xFF));
            read_struct.BDAddr[5] = ((req->bd_addr.nap >> 8) & 0xFF);

            result = nvram_external_write_data(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID,1,(kal_uint8*)&read_struct,NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE);
        
            if(result && KAL_TRUE == nvram_external_read_data(NVRAM_EF_BT_INFO_LID, 1, (kal_uint8*)&read_struct2, NVRAM_EF_BT_INFO_SIZE))
            {
                read_struct2.host_dev.bd_addr.lap = req->bd_addr.lap;
                read_struct2.host_dev.bd_addr.uap = req->bd_addr.uap;
                read_struct2.host_dev.bd_addr.nap = req->bd_addr.nap;

                result = nvram_external_write_data(NVRAM_EF_BT_INFO_LID,1,(kal_uint8*)&read_struct2,NVRAM_EF_BT_INFO_SIZE);
            }
        }
    }
    
    cmd_hdlr_bt_write_local_addr_cnf(result);
}

void cmd_hdlr_bt_write_local_addr_cnf(kal_uint8 result)
{
    bcm_write_local_addr_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_LOCAL_ADDR_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_write_local_addr_cnf_struct*)construct_local_para(sizeof(bcm_write_local_addr_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_WRITE_LOCAL_ADDR_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_read_local_addr_req(ilm_struct* msg)
{
    bcm_read_local_addr_req_struct *req = (bcm_read_local_addr_req_struct*)msg->local_para_ptr;
    srv_bt_cm_nvram_struct read_struct;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_LOCAL_ADDR_REQ);
    
    memset(&read_struct,0x00,sizeof(srv_bt_cm_nvram_struct));

    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {

         /*power off, we use data in nvram */
        if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_INIT_ON)
        {
            result = nvram_external_read_data(NVRAM_EF_BT_INFO_LID, 1, (kal_uint8*)&read_struct, NVRAM_EF_BT_INFO_SIZE);
        }
        else
        /*not power off, we use data in buffer */
        {
            srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_host_dev_info();
            read_struct.host_dev.bd_addr.lap = dev_info->bd_addr.lap;
            read_struct.host_dev.bd_addr.uap = dev_info->bd_addr.uap;
            read_struct.host_dev.bd_addr.nap = dev_info->bd_addr.nap;
            result = KAL_TRUE;
        }
        
    }
    cmd_hdlr_bt_read_local_addr_cnf(result,read_struct.host_dev.bd_addr);
}
void cmd_hdlr_bt_read_local_addr_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr)
{
    bcm_read_local_addr_cnf_struct *cnf = NULL;
      
    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_LOCAL_ADDR_CNF);

    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_read_local_addr_cnf_struct*)construct_local_para(sizeof(bcm_read_local_addr_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->bd_addr.lap = bd_addr.lap;
        cnf->bd_addr.uap = bd_addr.uap;
        cnf->bd_addr.nap = bd_addr.nap;
        
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_READ_LOCAL_ADDR_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
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
#endif
void cmd_hdlr_bt_write_scan_mode_req(ilm_struct* msg)
{
    bcm_write_scanenable_mode_req_struct *req = (bcm_write_scanenable_mode_req_struct*)msg->local_para_ptr;
    srv_bt_cm_visibility_type visibility_type = SRV_BT_CM_VISIBILITY_TOTAL;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_SCAN_MODE_REQ);    

    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {

        if(req->modenotconnected == 0)//unvisable
        {
            visibility_type = SRV_BT_CM_VISIBILITY_OFF;
        }
        else if(req->modenotconnected == 1 && req->visable_time == 0)//visable forever
        {        
            visibility_type = SRV_BT_CM_VISIBILITY_ON;
        }
        else if(req->modenotconnected == 1 && req->visable_time > 0) // temple visable
        {        
            visibility_type = SRV_BT_CM_VISIBILITY_TEMPORARY_ON;
        }
        else
        {
            // do nothing but return error.
            cmd_hdlr_bt_write_scan_mode_cnf(result);
            return;

        }
           
        if (visibility_type != SRV_BT_CM_VISIBILITY_TOTAL && 
            SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_visibility(visibility_type))
        {
        /* because SRV_BT_CM_VISIBILITY_TEMPORARY_ON in srv_bt_cm_set_visibility()
            *   will start a timer BT_TEMP_VISIBLE_TIMER 60s
            *   we need restart it with a new durition.
            */
            StopTimer(BT_TEMP_VISIBLE_TIMER);
            if(visibility_type == SRV_BT_CM_VISIBILITY_TEMPORARY_ON)
            {
                //when temporary on , we start the timer to stop it in future.
                StartTimer(
                    BT_TEMP_VISIBLE_TIMER,
                    req->visable_time * 1000,//seconds to ms
                    srv_bt_cm_set_temp_visibility_timeout);
            }
            return;
        }
        
    }
    cmd_hdlr_bt_write_scan_mode_cnf(result);
}

void cmd_hdlr_bt_write_scan_mode_cnf(kal_uint8 result)
{
    bcm_write_scanenable_mode_cnf_struct *cnf = NULL;   
    cnf = (bcm_write_scanenable_mode_cnf_struct*)construct_local_para(sizeof(bcm_write_scanenable_mode_cnf_struct), TD_RESET);
    cnf->src_id = BCM_PTR->curr_usr;
    cnf->result = result;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_SCAN_MODE_CNF);
    if(BCM_PTR->curr_req_src != 0)
    {
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_WRITE_SCANENABLE_MODE_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}


void cmd_hdlr_bt_discovery_para_req(ilm_struct* msg)
{
    bcm_discovery_para_struct *req = (bcm_discovery_para_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DISCOVERY_PARA_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id; 
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if(req->op == 0) //set
        {
            if(req->urc_interval >= req->inquiry_length)
            {
                BCM_PTR->urc_interval = req->urc_interval;
                BCM_PTR->inquiry_length = req->inquiry_length;
                BCM_PTR->inquiry_number = req->inquiry_number;
                BCM_PTR->cod = req->cod;
                result = KAL_TRUE;
            }
            else
            {
                //trace here, invalid parameter
            }
        }
        else if(req->op == 1)//read
        {
            // the cnf api will help to read data.
            result = KAL_TRUE;
        }
    }
    cmd_hdlr_bt_discovery_para_cnf(result,req->op);
}
void cmd_hdlr_bt_discovery_para_cnf(kal_uint8 result,kal_uint8 op)
{
    bcm_discovery_para_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DISCOVERY_PARA_CNF);
    if(BCM_PTR->curr_req_src != 0)
    {   
        cnf = (bcm_discovery_para_cnf_struct*)construct_local_para(sizeof(bcm_discovery_para_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        cnf->op = op;

        if(result)
        {
            cnf->urc_interval = BCM_PTR->urc_interval;
            cnf->inquiry_length = BCM_PTR->inquiry_length;
            cnf->inquiry_number = BCM_PTR->inquiry_number;
            cnf->cod = BCM_PTR->cod;
        }
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_DISCOVERY_PARA_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void bt_discover_restart_timeout(void)
{
    //    BCM_FUNC_ENTRY(MMI_BT_G7_BT_DEINIT);  
    if(SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_search(BCM_PTR->inquiry_number,BCM_PTR->inquiry_length,BCM_PTR->cod,KAL_TRUE))
    {
        //trace here, search failed, need retry.
    }
    else
    {
        bcm_set_ext_cm_state(BCM_EXT_CM_STATE_INQUIRING);
    }
}
void bt_discover_restart_timeout_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;    

    bt_discover_restart_timeout();
    
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
    
    StartTimer((kal_uint16) (timer_id),BCM_PTR->urc_interval * 1000,bt_discover_restart_timeout);//bt_discover_restart_timeout_bcm_adp
}

void cmd_hdlr_bt_discover_req(ilm_struct* msg)
{
    bcm_discovery_struct *req = (bcm_discovery_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DISCOVERY_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_search(BCM_PTR->inquiry_number,BCM_PTR->inquiry_length,BCM_PTR->cod,KAL_TRUE))
        {
            //start a timer to re-discover
            //StartTimer(BT_INQ_TIMER,BCM_PTR->urc_interval * 1000,bt_discover_restart_timeout);
            bcm_set_ext_cm_state(BCM_EXT_CM_STATE_INQUIRING);
            result = KAL_TRUE;
        }
        else
        {
            //trace here, search failed, need retry.
        }
    }
    cmd_hdlr_bt_discovery_cnf(result);
}
void cmd_hdlr_bt_discovery_cnf(kal_uint8 result)
{
    bcm_discovery_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DISCOVERY_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_discovery_cnf_struct*)construct_local_para(sizeof(bcm_discovery_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        cnf->total_number = 0;//useless value now.
    }
    
    bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_DISCOVERY_CNF, cnf, NULL);
    
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_discover_cancel_req(ilm_struct* msg)
{
    bcm_discovery_cancel_struct *req = (bcm_discovery_cancel_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DISCOVERY_CANCEL_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {        
        //stop the re-discover timer
        StopTimer(BT_INQ_TIMER);
        if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_search_abort())
        {
            bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);
            result = KAL_TRUE;
            return;
        }
        else
        {
            //trace here, search cancel failed, error case. 
            //then we should check state check table.
        }
    }
    cmd_hdlr_bt_discovery_cancel_cnf(result,0);
}

void cmd_hdlr_bt_discovery_cancel_cnf(kal_uint8 result,kal_uint8 total_number)
{
    bcm_discovery_cancel_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DISCOVERY_CANCEL_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_discovery_cancel_cnf_struct*)construct_local_para(sizeof(bcm_discovery_cancel_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        cnf->total_number = total_number;//useless value now.
    
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_DISCOVERY_CANCEL_CNF, cnf, NULL);
    }
    bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);
    
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}


void cmd_hdlr_bt_read_remote_name_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;
    bcm_read_remote_name_req_struct *req = (bcm_read_remote_name_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_REMOTE_NAME_REQ);

    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    dev_addr.lap = req->bd_addr.lap;
    dev_addr.uap = req->bd_addr.uap;
    dev_addr.nap = req->bd_addr.nap;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        
        if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_read_remote_dev_name(&dev_addr))
        {
            return;
        }
        else
        {
            //trace here, we need the fail reason, so print them. 
            //also we should check state check table.
        }
    }
    cmd_hdlr_bt_read_remote_name_cnf(result,dev_addr,NULL,0);

}
void cmd_hdlr_bt_read_remote_name_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr,kal_uint8* name, kal_uint8 name_len)
{
    bcm_read_remote_name_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_REMOTE_NAME_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_read_remote_name_cnf_struct*)construct_local_para(sizeof(bcm_read_remote_name_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->bd_addr.lap = bd_addr.lap;
        cnf->bd_addr.uap = bd_addr.uap;
        cnf->bd_addr.nap = bd_addr.nap;    

        if(result)
        {
            cnf->name_len = name_len > (BTBM_ADP_MAX_NAME_LEN - 1) ?
                (BTBM_ADP_MAX_NAME_LEN - 1) : name_len;
            if(name && name_len > 0)
            {
                memcpy(cnf->name,name,name_len);
            }
        }
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_READ_REMOTE_NAME_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void bt_bonding_timeout(void)
{
    if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
    {
        //this is used to avoid case the timer expired after bonding result return by BT.
        cmd_hdlr_bt_bonding_cnf(KAL_FALSE,BCM_PTR->dev_addr,NULL,0,0,0,NULL,0);
        bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);
    }    
}

void bt_bonding_timeout_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;
    
    bt_bonding_timeout();
    
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}

void cmd_hdlr_bt_bonding_req(ilm_struct* msg)
{
    kal_uint8 index;
    bcm_bonding_req_struct *req = (bcm_bonding_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_BONDING_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    BCM_PTR->dev_addr.lap = req->bd_addr.lap;
    BCM_PTR->dev_addr.uap = req->bd_addr.uap;
    BCM_PTR->dev_addr.nap = req->bd_addr.nap;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        index = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&(BCM_PTR->dev_addr), SRV_BT_CM_DISCOVERED_DEV);
        if (index < SRV_BT_CM_MAX_DEVICE_LIST)
        {
            if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_bond(index))
            {
                //start a timer to drop bonding request
                
                if(req->timeout > 0 && req->timeout < 20)
                {
                    StartTimer(BT_BOND_TIMER,req->timeout * 1000,bt_bonding_timeout);
                }
                bcm_set_ext_cm_state(BCM_EXT_CM_STATE_PAIRING);
                return;
            }
            else
            {
                //trace here, we need the fail reason, so print them. 
                //also we should check state check table.
            }
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
    cmd_hdlr_bt_bonding_cnf(result,BCM_PTR->dev_addr,NULL,0,0,0,NULL,0);
}

void cmd_hdlr_bt_bonding_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr,kal_uint8* name, kal_uint8 name_len,kal_uint8 display_numeric,kal_uint8 enable_16digits_pin_code,kal_uint8 *password,kal_uint8 password_len)
{
    bcm_bond_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_BONDING_CNF);

    if(BCM_PTR->curr_req != 0)
    {
        cnf = (bcm_bond_cnf_struct*)construct_local_para(sizeof(bcm_bond_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->dev_addr.lap = bd_addr.lap;
        cnf->dev_addr.uap = bd_addr.uap;
        cnf->dev_addr.nap = bd_addr.nap;

        if(result)
        {
            cnf->name_len = name_len > (BTBM_ADP_MAX_NAME_LEN - 1) ?
                (BTBM_ADP_MAX_NAME_LEN - 1) : name_len;
            if(name && name_len > 0)
            {
                memcpy(cnf->name,name,name_len);
            }

            cnf->display_numeric = display_numeric;
            cnf->enable_16digits_pin_code = enable_16digits_pin_code;
            cnf->password_len = password_len;
            if(password && password_len > 0)
            {
                memcpy(cnf->password,password,password_len);
            }
            BCM_PTR->dev_addr = bd_addr;
        }
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_BONDING_CNF, cnf, NULL);
        bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);
        StopTimer(BT_BOND_TIMER);
    }
    
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;

    //we should not clear BCM_PTR->dev_addr, becasue we'll use it in cmd_hdlr_bt_bonding_rsp_req()
}


void cmd_hdlr_bt_bonding_rsp_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;
    kal_uint8 index;
    bcm_bonding_rsp_req_struct *req = (bcm_bonding_rsp_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_BONDING_RSP_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    BCM_PTR->op = req->accept;

//    we didn't give addr in bcm_bonding_rsp_req_struct.
//    dev_addr.lap = req->dev_addr.lap;
//    dev_addr.uap = req->dev_addr.uap;
//    dev_addr.nap = req->dev_addr.nap;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_PASSKEY_NOTIFY ||
            (srv_bt_cm_get_state() == SRV_BT_CM_STATE_BONDING && 
            BCM_PTR->cm_pair_state == BCM_CM_PAIR_STATE_PASSKEY_NOTIFY))
        {
            if(req->accept)
            {
                srv_bt_cm_passkey_ind_rsp_hdler(BCM_PTR->dev_addr,req->password_len,req->password);
            }
            else
            {
                /*the name of this function is strange, 
                         * but from srv_bt_cm_passkey_ind_hdler_ext() we know it's right.
                         */
                srv_bt_cm_security_keypress_notify_cancel(&(BCM_PTR->dev_addr));
            }
            memset(&(BCM_PTR->dev_addr),0,sizeof(BCM_PTR->dev_addr));
            result = KAL_TRUE;
            return;
        }
		else if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_PASSKEY_IND ||
            (srv_bt_cm_get_state() == SRV_BT_CM_STATE_BONDING && 
            BCM_PTR->cm_pair_state == BCM_CM_PAIR_STATE_PIN_CODE))
        {
    		kal_uint8 reject_pin_code[2];
            if(req->accept)
            {
			    srv_bt_cm_passkey_ind_rsp_hdler(BCM_PTR->dev_addr,req->password_len,req->password);
            }
			else
			{
                memset(reject_pin_code,0,2);
			    srv_bt_cm_passkey_ind_rsp_hdler(BCM_PTR->dev_addr,0,reject_pin_code);
			}
            memset(&(BCM_PTR->dev_addr),0,sizeof(BCM_PTR->dev_addr));
            result = KAL_TRUE;
            return;
        }
        else if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_NUMERIC_CONFIRM ||
            ((srv_bt_cm_get_state() == SRV_BT_CM_STATE_BONDING 
            || srv_bt_cm_get_state() == SRV_BT_CM_STATE_CONNECTING) && 
            BCM_PTR->cm_pair_state == BCM_CM_PAIR_STATE_USER_CONFIRM))
        {
            srv_bt_cm_security_numeric_confirm(&(BCM_PTR->dev_addr), req->accept);
            memset(&(BCM_PTR->dev_addr),0,sizeof(BCM_PTR->dev_addr));
            result = KAL_TRUE;
            return;
        }
        else
        {
            //may be a wrong cmd, we don't memset &(BCM_PTR->dev_addr)
            result = KAL_FALSE;
        }
    }
    cmd_hdlr_bt_bonding_rsp_cnf(result,dev_addr);
}
void cmd_hdlr_bt_bonding_rsp_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr)
{
    bcm_bonding_rsp_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_BONDING_RSP_CNF);

    if(BCM_PTR->curr_req != 0)
    {
        cnf = (bcm_bonding_rsp_cnf_struct*)construct_local_para(sizeof(bcm_bonding_rsp_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->bd_addr.lap = bd_addr.lap;
        cnf->bd_addr.uap = bd_addr.uap;
        cnf->bd_addr.nap = bd_addr.nap;

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_BONDING_RSP_CNF, cnf, NULL);
    }
    
    BCM_PTR->op = 0;
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_service_search_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr bd_addr;
    bcm_service_search_req_struct *req = (bcm_service_search_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_SERIVCE_SEARCH_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id; 
    
    bd_addr.lap = req->bd_addr.lap;
    bd_addr.uap = req->bd_addr.uap;
    bd_addr.nap = req->bd_addr.nap;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_refresh_service_list(&bd_addr))
        {
            result = KAL_TRUE;
            return;
        }
        else
        {
            result = KAL_FALSE;
        }
    }
    cmd_hdlr_bt_service_search_cnf(result,bd_addr);
}

void cmd_hdlr_bt_service_search_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr)
{
    bcm_service_search_cnf_struct *cnf = NULL;  
    kal_uint64 support_profile_map = 0;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_SERVICE_SEARCH_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_service_search_cnf_struct*)construct_local_para(sizeof(bcm_service_search_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->bd_addr.lap = bd_addr.lap;
        cnf->bd_addr.uap = bd_addr.uap;
        cnf->bd_addr.nap = bd_addr.nap;
        if(result == KAL_TRUE)
        {
            kal_uint32 i,j = 0;
            kal_uint8 service_count = 0;
            i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&bd_addr, SRV_BT_CM_ALL_DEV);
            if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
            {
                cnf->result = KAL_FALSE; 
            }

            service_count = g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num;
            /* to filter out the duplicated sdc indication */
            for (j = 0; j < service_count; j++)
            {
                bt_profile_to_map(KAL_TRUE,&support_profile_map,g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list[j]);
            }

        }
        cnf->support_profile_map = support_profile_map;

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_SERVICE_SEARCH_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

kal_bool bt_profile_to_map(kal_bool is_add,kal_uint64 *profile_map, kal_uint32 profile_uuid)
{
    kal_uint8 i = 0;
    // where the profile is (un)masked to map.
    kal_bool result = KAL_FALSE;

    if(profile_map == NULL)
        return KAL_FALSE;

	kal_prompt_trace(MOD_BCM,"is_add is %d, profile is %x",is_add,profile_uuid);
    for(i = 0; i < sizeof(index_profile_map)/sizeof(kal_uint32); i++)
    {
        if(index_profile_map[i] == profile_uuid)
        {
            if(is_add)// add
            {
                *profile_map |= (1 << i);
            }
            else //remove
            {
                *profile_map &= ~(1 << i);
            }
            result = KAL_TRUE;
            break;
        }
    }
    return result;
}
kal_uint8 bt_profile_map_to_list(kal_uint8 masked,kal_uint64 profile_map, kal_uint32 *profile_list,kal_uint8 profile_list_number)
{
    kal_uint8 i = 0;
    kal_uint8 j = 0;
    kal_uint8 max_list_number = 0;

    if(profile_list == NULL || profile_list_number == 0)
        return 0;

    max_list_number = profile_list_number < sizeof(index_profile_map)/sizeof(kal_uint32) ? profile_list_number : sizeof(index_profile_map)/sizeof(kal_uint32);
    
    while(i < max_list_number)
    {
        if(masked == ( (profile_map >> i) & 1 ))
        {            
            profile_list[j] = index_profile_map[i];
            j++;
        }
        i++;
    }
    
    kal_prompt_trace(MOD_BCM,"return is %d",j);
    kal_prompt_trace(MOD_BCM,"map is %x",profile_map);
    //BCM_GROUP7_ENTRY(GROUP3_BCM_CMD_PROFILE_MAP,profile_map,i);
    return j; // return how many profile we have passed to list.
}
kal_uint8 bt_current_activate_profiles_to_map(kal_uint64 *profile_map)
{
    kal_uint8 i,j = 0;
    kal_uint8 max_list_number = 0;

    kal_prompt_trace(MOD_BCM,"profile_map addr %x",profile_map);

    if(profile_map == NULL)
    {
        return 0;
    }
    
    *profile_map = 0;
	for (j = 0; j < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; j++)
	{
		i = 0;
	    for(i = 0; i < sizeof(index_profile_map)/sizeof(kal_uint32); i++)
	    {
			if(index_profile_map[i] == g_srv_bt_cm_profile_tbl[j].profile_id)
			{
	            BCM_GROUP7_ENTRY(GROUP3_BCM_CMD_PROFILE_STATUS,g_srv_bt_cm_profile_tbl[j].profile_id,
	                g_srv_bt_cm_profile_tbl[j].deactivate_flag,
	                g_srv_bt_cm_cntx.deactivate_flag,
	                g_srv_bt_cm_profile_tbl[j].activater,
	                g_srv_bt_cm_profile_tbl[j].deactivater);
				if ( ((g_srv_bt_cm_cntx.deactivate_flag & g_srv_bt_cm_profile_tbl[j].deactivate_flag) == 0) ||
					(g_srv_bt_cm_profile_tbl[j].activater == 0))
				{
					bt_profile_to_map(KAL_TRUE,profile_map,index_profile_map[i]);
					break;
				}
			}
        } 
    }
    //ASSERT(i<64);
    return i; // return how many profile we have passed to map.
} 

void cmd_hdlr_bt_write_auth_mode_req(ilm_struct* msg)
{
    bcm_write_authentication_mode_req_struct *req = (bcm_write_authentication_mode_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_AUTH_MODE_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {        
       //currently, we only support 0~3,sec_mode. not support enc_mode.
        if(req->sec_mode < 0 || req->sec_mode > 3 || req->enc_mode < 0 || req->enc_mode > 2)
        {
            result = KAL_FALSE;
        }
        else if(req->sec_mode == srv_bt_cm_get_host_dev_security_level())
        {
            result = KAL_TRUE;
        }
        else if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_authentication_adp(req->sec_mode))
        {
            result = KAL_TRUE;
            return;
        }
        else
        {
            result = KAL_FALSE;
        }
        
    }
    cmd_hdlr_bt_write_auth_mode_cnf(result,srv_bt_cm_get_host_dev_security_level(),0);
}
void cmd_hdlr_bt_write_auth_mode_cnf(kal_uint8 result,btbm_authentication_mode sec_mode,kal_uint8 enc_mode)
{
    bcm_write_authentication_mode_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_WRITE_AUTH_MODE_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_write_authentication_mode_cnf_struct*)construct_local_para(sizeof(bcm_write_authentication_mode_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->sec_mode = sec_mode;
        cnf->enc_mode = enc_mode;

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_WRITE_AUTHENTICATION_MODE_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

kal_int32 srv_bt_cm_set_authentication_adp(btbm_authentication_mode mode)
{   
    //copy the logic from srv_bt_cm_set_authentication()
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_AUTHENTICATION,
        mode);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        if (mode)
        {
            SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_AUTH);
        }
        else
        {
            SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_AUTH);
        }

        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_AUTHENTICATION_SETTING);
        //we copy below from srv_bt_cm_security_level_req_hdler((MMI_BOOL)SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_AUTH));
        {
            bt_bm_write_authentication_mode_req_struct* msg_p;
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_SECURITY_LEVEL_REQ_HDLER,
                mode);
        
            msg_p = (bt_bm_write_authentication_mode_req_struct*)construct_local_para(
                sizeof(bt_bm_write_authentication_mode_req_struct),
                TD_CTRL);
        
            msg_p->mode = mode;
            srv_bt_cm_send_msg(
                MOD_BT,
                BT_APP_SAP,
                MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_REQ,
                (void*)msg_p,
                NULL);
        }

        return SRV_BT_CM_RESULT_SUCCESS;
    }
    
    return SRV_BT_CM_RESULT_FAILED;
}


void cmd_hdlr_bt_read_auth_mode_req(ilm_struct* msg)
{
    bcm_read_authentication_mode_req_struct *req = (bcm_read_authentication_mode_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_AUTH_MODE_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        result = KAL_TRUE;        
    }
    cmd_hdlr_bt_read_auth_mode_cnf(result,srv_bt_cm_get_host_dev_security_level(),0);
}
void cmd_hdlr_bt_read_auth_mode_cnf(kal_uint8 result,btbm_authentication_mode sec_mode,kal_uint8 enc_mode)
{
    bcm_read_authentication_mode_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_READ_AUTH_MODE_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_read_authentication_mode_cnf_struct*)construct_local_para(sizeof(bcm_read_authentication_mode_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->sec_mode = sec_mode;
        cnf->enc_mode = enc_mode;

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_READ_AUTHENTICATION_MODE_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_dev_list_op_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;//incoming device address
    srv_bt_cm_bt_addr *bd_addr;//outputing device address list
    
    bcm_dev_list_op_req_struct *req = (bcm_dev_list_op_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;
    kal_uint8 list_number = 0;
    bd_addr = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DEV_LIST_OP_REQ);    

    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    BCM_PTR->op = req->op;
    
    dev_addr.lap = req->bd_addr.lap;
    dev_addr.uap = req->bd_addr.uap;
    dev_addr.nap = req->bd_addr.nap;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        /*
            * 0 delete
            * 1 locate
            * 2 delete all
            * 3 most recently used
            * 4 return total list
            */
        switch(req->op)
        {
            case 0:
                //cnf at SRV_BT_CM_EVENT_MYDEV_DEL
                if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_dev_del(&dev_addr))
                {
                    result = KAL_TRUE;
                    return;
                }
                break;
            case 1:
            {
                kal_uint32 i = 0;
                i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&dev_addr, SRV_BT_CM_PAIRED_DEV);
                if (i < g_srv_bt_cm_cntx.paired_dev_num)
                {
                    list_number = 1;
                    bd_addr = (srv_bt_cm_bt_addr *)get_ctrl_buffer(sizeof(srv_bt_cm_bt_addr));
                    bd_addr->lap = req->bd_addr.lap;
                    bd_addr->uap = req->bd_addr.uap;
                    bd_addr->nap = req->bd_addr.nap;    
                    result = KAL_TRUE;
                }
                else
                    result = KAL_FALSE;
            }
                break;
            case 2:
                //cnf at SRV_BT_CM_EVENT_MYDEV_DEL
                if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_dev_del_all())
                {
                    result = KAL_TRUE;
                    return;
                }
                break;
            case 3:
            {
                //got the recent used list and copy the to bd_addr
                kal_uint32 i, idx, total_num, max_recent_number = 0;
                kal_uint8* idx_list = NULL;               
                total_num = g_srv_bt_cm_cntx.recent_dev_num;
                idx_list = g_srv_bt_cm_cntx.recent_idx_list;

                max_recent_number = total_num < SRV_BT_CM_MAX_USED_DEVICE_LIST ? total_num : SRV_BT_CM_MAX_USED_DEVICE_LIST;

                if(max_recent_number > 0)
                {
                    bd_addr = (srv_bt_cm_bt_addr*)get_ctrl_buffer(max_recent_number * sizeof(srv_bt_cm_bt_addr));

                    for (i = 0; i < max_recent_number; i++)
                    {
                        idx = idx_list ? idx_list[i] : i;
                        
                        bd_addr[i].lap = g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr.lap;
                        bd_addr[i].uap = g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr.uap;
                        bd_addr[i].nap = g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr.nap;
                    }
                    }
                list_number = max_recent_number;
                result = KAL_TRUE;
            }
                break;
            case 4:
            {
                //got the total list and copy the to bd_addr
                kal_uint32 i, idx, total_num, max_total_number = 0;
                kal_uint8* idx_list = NULL;               
                total_num = g_srv_bt_cm_cntx.paired_dev_num;
                idx_list = g_srv_bt_cm_cntx.paired_idx_list;

                max_total_number = total_num < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST ? total_num : SRV_BT_CM_MAX_PAIRED_DEVICE_LIST;

                kal_prompt_trace(MOD_BCM,"case 4 max total number is %d",max_total_number);
                if(max_total_number > 0)
                {
                    bd_addr = (srv_bt_cm_bt_addr*)get_ctrl_buffer(max_total_number * sizeof(srv_bt_cm_bt_addr));

                    for (i = 0; i < max_total_number; i++)
                    {
                        idx = idx_list ? idx_list[i] : i;
                        
                        bd_addr[i].lap = g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr.lap;
                        bd_addr[i].uap = g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr.uap;
                        bd_addr[i].nap = g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr.nap;
                    }
                }
                list_number = max_total_number;
                result = KAL_TRUE;
            }
                break;
            default:
                result = KAL_FALSE;
                break;
        }
        
    }
    cmd_hdlr_bt_dev_list_op_cnf(result,req->op,list_number,bd_addr);
}
void cmd_hdlr_bt_dev_list_op_cnf(kal_uint8 result,kal_uint8 op,kal_uint8 list_number,srv_bt_cm_bt_addr *bd_addr)
{
    bcm_dev_list_op_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_DEV_LIST_OP_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_dev_list_op_cnf_struct*)construct_local_para(sizeof(bcm_dev_list_op_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;

        cnf->op = op;
        cnf->list_number = list_number;
        
        if(bd_addr && list_number > 0)
        {
            int i = 0;
            int max_list_number = list_number < SRV_BT_CM_MAX_DEVICE_LIST ? list_number : SRV_BT_CM_MAX_DEVICE_LIST;
            for(i = 0; i < max_list_number; i++)
            {
                cnf->bd_addr[i].lap = bd_addr[i].lap;
                cnf->bd_addr[i].uap = bd_addr[i].uap;
                cnf->bd_addr[i].nap = bd_addr[i].nap;
            }
        }

        /*
            * 0 delete
            * 1 locate
            * 2 delete all
            * 3 most recently used
            * 4 return total list
            */
        switch(op)
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                result = KAL_FALSE;
                //MMI_ASSERT(0);
                //some place call this function with wrong op, we print some trace.
                break;
        }

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_DEV_LIST_OP_CNF, cnf, NULL);
    }
    if(bd_addr)
    {
        free_ctrl_buffer(bd_addr);
        bd_addr = NULL;
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
    BCM_PTR->op = 0;
}

void cmd_hdlr_bt_profile_state_query_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;
    kal_uint8 profile_state;
    bcm_profile_state_query_req_struct *req = (bcm_profile_state_query_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_PROFILE_STATE_QUERY_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    dev_addr.lap = req->bd_addr.lap;
    dev_addr.uap = req->bd_addr.uap;
    dev_addr.nap = req->bd_addr.nap;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        result = srv_bt_cm_get_profile_state(req->profile,dev_addr,&profile_state);        
    }
    cmd_hdlr_bt_profile_state_query_cnf(result,req->profile,profile_state);
}
void cmd_hdlr_bt_profile_state_query_cnf(kal_uint8 result,kal_uint32 profile,kal_uint8 profile_state)
{
    bcm_profile_state_query_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_PROFILE_STATE_QUERY_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_profile_state_query_cnf_struct*)construct_local_para(sizeof(bcm_profile_state_query_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;

        cnf->profile = profile;
        cnf->profile_state = profile_state;
        
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_PROFILE_STATE_QUERY_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}
#ifdef __BT_SPP_PROFILE__

kal_uint8 bcm_get_ext_spp_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role)
{
    kal_uint8 profile_state = srv_bt_spp_get_state(dev_addr,role);

    switch(profile_state)
    {
        case SRV_SPP_CONN_STATE_IDLE: // means only app init, but not activate. after deactivating , it'll be IDLE.
            profile_state = BCM_EXT_PROFILE_STATE_IDLE;
            break;
        case SRV_SPP_CONN_STATE_ACTIVATE: //for server: after activate( or when begin to connect), it will be ACTIVATE State.
            profile_state = BCM_EXT_PROFILE_STATE_ACTIVATE;
            break;
        case SRV_SPP_CONN_STATE_AUTHORIZING://just for server: authorizing between connecting establishment.
            profile_state = BCM_EXT_PROFILE_STATE_AUTHORIZING;
            break;
        case SRV_SPP_CONN_STATE_CONNECTED://connected
            profile_state = BCM_EXT_PROFILE_STATE_ACTIVATE;
            break;
        case SRV_SPP_CONN_STATE_DISCONNECTING://disconnecting
            profile_state = BCM_EXT_PROFILE_STATE_DISCONNECTING;
            break;
        case SRV_SPP_CONN_STATE_DEACTIVATING://deactivating
            profile_state = BCM_EXT_PROFILE_STATE_DEACTIVATING;
            break;
        default:
            profile_state = BCM_EXT_PROFILE_STATE_START;
            break;
    }
    return profile_state;
}
#endif
#ifdef __BT_PBAP_CLIENT__
kal_uint8 bcm_get_ext_pbapc_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role)
{
    bcm_pbapc_state profile_state = bcm_pbapc_query_state(dev_addr);
    kal_uint8 state;

    if(profile_state <= BCM_PBAPC_STATE_ENABLE)
    {
        state = BCM_EXT_PROFILE_STATE_IDLE;
    }
    else if(profile_state < BCM_PBAPC_STATE_CONNECTED)
    {
        state = BCM_EXT_PROFILE_STATE_AUTHORIZING;
    }
    else if(profile_state < BCM_PBAPC_STATE_DISCONECTTING)
    {
        state = BCM_EXT_PROFILE_STATE_ACTIVATE;
    }
    else if(profile_state == BCM_PBAPC_STATE_DISCONECTTING)
    {
        state = BCM_EXT_PROFILE_STATE_DISCONNECTING;
    }
    else if(profile_state == BCM_PBAPC_STATE_INVALID)
    {
        state = BCM_EXT_PROFILE_STATE_ERROR;
    }
    else
        state = BCM_EXT_PROFILE_STATE_START;

    return state;
}
#endif /*__BT_PBAP_CLIENT__*/

#if defined(__BCM_PBAP_SERVER__)
kal_uint8 bcm_get_ext_pbap_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role)
{
    return bcm_pbap_get_state(dev_addr);
}
#endif


#ifdef __MMI_OPP_SUPPORT__
kal_uint8 bcm_get_ext_opp_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role)
{
    return bcm_opp_get_state(dev_addr,role);
}
#endif /*__MMI_OPP_SUPPORT__*/


kal_bool srv_bt_cm_get_profile_state(kal_uint32 profile,srv_bt_cm_bt_addr dev_addr,kal_uint8 *profile_state)
{    
    if(profile_state == NULL)
        return KAL_FALSE;
    switch (profile)
    {
#ifdef __BT_SPP_PROFILE__
        case SRV_BT_CM_SPP_PROFILE_UUID:
            *profile_state = bcm_get_ext_spp_state(dev_addr,1);//server only if both server & client connected to one peer
            return KAL_TRUE;
#endif
#ifdef __BT_PBAP_CLIENT__
        case SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID:
            *profile_state = bcm_get_ext_pbapc_state(dev_addr,0);//client
            return KAL_TRUE;
#endif
#ifdef __BCM_PBAP_SERVER__
        case SRV_BT_CM_OBEX_PBA_PROFILE_UUID:
            *profile_state = bcm_get_ext_pbap_state(dev_addr,0);//client
            return KAL_TRUE;
#endif

#ifdef __MMI_OPP_SUPPORT__
        case SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID:
            *profile_state = bcm_get_ext_opp_state(dev_addr,1);//server
            return KAL_TRUE;
        case SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID:
            *profile_state = bcm_get_ext_opp_state(dev_addr,0);//client
            return KAL_TRUE;
#endif

#if defined(__BT_HF_PROFILE__)
		case SRV_BT_CM_HF_PROFILE_UUID://HF
			{
			*profile_state = bcm_get_ext_hf_state(dev_addr, 1);
			}
			return KAL_TRUE;
#endif/*#if defined(__BT_HF_PROFILE__)*/

#if defined(__BT_HFG_PROFILE__)
	case SRV_BT_CM_HFG_PROFILE_UUID://HFG
		{
			*profile_state = bcm_get_ext_hfg_state(dev_addr, 1);
		}
		return KAL_TRUE;

#endif
        default :
            *profile_state = 0;
            return KAL_FALSE;
            break;
    }
    return KAL_FALSE;
}
void bcm_set_ext_cm_state(kal_uint8 state)
{
    BCM_FUNC_ENTRY(FUNC_BCM_SET_EXT_CM_STATE);
    if(state > BCM_EXT_CM_STATE_ERROR && state < BCM_EXT_CM_STATE_MAX)
    {
        BCM_STATE_ENTRY(STATE_BCM_EXT_CM,BCM_PTR->ext_cm_state);
        BCM_PTR->ext_cm_state = state;
        BCM_STATE_ENTRY(STATE_BCM_EXT_CM,state);
    }
}
kal_uint8 bcm_get_ext_cm_state(void)
{
    kal_uint8 state = 7;
    BCM_FUNC_ENTRY(FUNC_BCM_GET_EXT_CM_STATE);
    BCM_STATE_ENTRY(STATE_BCM_EXT_CM,BCM_PTR->ext_cm_state);
    return BCM_PTR->ext_cm_state; //bcm_ext_cm_state
}

void cmd_hdlr_bt_cm_state_query_req(ilm_struct* msg)
{
    bcm_cm_state_query_req_struct *req = (bcm_cm_state_query_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_CM_STATE_QUERY_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;

    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {        
        result = KAL_TRUE;
    }
    cmd_hdlr_bt_cm_state_query_cnf(result,bcm_get_ext_cm_state());
}
void cmd_hdlr_bt_cm_state_query_cnf(kal_uint8 result,kal_uint8 cm_state)
{
    bcm_cm_state_query_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_CM_STEATE_QUERY_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_cm_state_query_cnf_struct*)construct_local_para(sizeof(bcm_cm_state_query_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->cm_state = cm_state;
        
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_CM_STATE_QUERY_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_sniff_para_req(ilm_struct* msg)
{
    kal_int8  sniff_level;
    bcm_sniff_para_req_struct *req = (bcm_sniff_para_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_SNIFF_PARA_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    
    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
/*
    MTK_SNIFF_PARA_SET     = 0,   //most of time, use peer device's sniff parameter,if your device is phone/mid
    MTK_SNIFF_PARA_DIALER  = 1,   //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_DIALER1 = 2,   //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_DIALER2 = 3,   //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_SET_HF  = 4,   //hf,custom should not use it
    MTK_SNIFF_PARA_SET_HFG = 5,   //hfg,custom should not use it
    MTK_SNIFF_PARA_END            //defaut value for custom,interval will select right value
*/
        if(req->op == 0)//0 write, 1 read
        {
            if(req->sniff_level >= 0 && req->sniff_level <= 3)
            {
                Custom_Set_BT_Sniff_Parameter(req->sniff_level);
                sniff_level = Custom_Get_BT_Sniff_Parameter();
                result = KAL_TRUE;
            }
        }
        else//0 write, 1 read
        {
            sniff_level = Custom_Get_BT_Sniff_Parameter();
            result = KAL_TRUE;
        }    
    }
    cmd_hdlr_bt_sniff_para_cnf(result,req->op,sniff_level);
}
void cmd_hdlr_bt_sniff_para_cnf(kal_uint8 result, kal_uint8 op,    kal_int8  sniff_level)
{
    bcm_sniff_para_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_SNIFF_PARA_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_sniff_para_cnf_struct*)construct_local_para(sizeof(bcm_sniff_para_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        cnf->op = op;
        
        cnf->sniff_level = sniff_level;
        
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_SNIFF_PARA_CNF, cnf, NULL);
    }
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void cmd_hdlr_bt_rssi_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;
    kal_int16 rssi = 0;
    bcm_rssi_req_struct *req = (bcm_rssi_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_RSSI_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;

    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        bt_read_rssi_req_struct* bt_read_rssi = (bt_read_rssi_req_struct*)construct_local_para((kal_uint16)sizeof(bt_read_rssi_req_struct),TD_CTRL);
        
        
        bt_read_rssi->lap = req->bd_addr.lap;
        bt_read_rssi->uap = req->bd_addr.uap;
        bt_read_rssi->nap = req->bd_addr.nap;
 
        bcm_send_ilm(MOD_BT,MSG_ID_BT_READ_RSSI_REQ,(local_para_struct*)bt_read_rssi,NULL);
        result = KAL_TRUE;
        return;
    }
    cmd_hdlr_bt_rssi_cnf(result,dev_addr,rssi);
}
void cmd_hdlr_bt_rssi_cnf(kal_uint8 result, srv_bt_cm_bt_addr dev_addr,kal_int16 rssi)
{
    bcm_rssi_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_RSSI_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_rssi_cnf_struct*)construct_local_para(sizeof(bcm_rssi_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;
        
        cnf->rssi = rssi;
        
        cnf->bd_addr.lap = dev_addr.lap;
        cnf->bd_addr.uap = dev_addr.uap;
        cnf->bd_addr.nap = dev_addr.nap;
        
        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_RSSI_CNF, cnf, NULL);
    }

    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

void bcm_bt_read_rssi_cnf(void *msg)
{
    srv_bt_cm_bt_addr dev_addr;
    bt_read_rssi_cnf_struct* rssi_cnf = (bt_read_rssi_cnf_struct*)msg;
    dev_addr.lap = rssi_cnf->lap;
    dev_addr.nap = rssi_cnf->nap;
    dev_addr.uap = rssi_cnf->uap;
    
    cmd_hdlr_bt_rssi_cnf(rssi_cnf->result == BT_STATUS_SUCCESS ? KAL_TRUE : KAL_FALSE,dev_addr,rssi_cnf->rssi_value);
}

void cmd_hdlr_bt_profile_act_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;
    kal_uint8 invalid_profile_number = 0;
    kal_uint32 profile_id[SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE] = {0};
    kal_int16 rssi = 0;
    bcm_profile_act_req_struct *req = (bcm_profile_act_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;
    kal_uint8 *name = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_PROFILE_ACT_REQ);
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;  
    
    BCM_PTR->profile_map = req->profile_map;
    BCM_PTR->act_profile_map = req->profile_map;
    BCM_PTR->deact_profile_map = ~(req->profile_map);

    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        int i = 0;
        int j = 0;//j is used for calculate profiles need to act
        int m = 0;
        int n = 0;//n is used for calculate profiles need to deact
        int t = 0;// t is used for count how many profiles were (de)acted .

        //1st, for each profile , check next action
        for(i = 0; i <sizeof(index_profile_map)/sizeof(kal_uint32); i++)
        {
	        for (j = 0; j < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; j++)
			{
				if(index_profile_map[i] == g_srv_bt_cm_profile_tbl[j].profile_id)
				{
		            BCM_GROUP7_ENTRY(GROUP3_BCM_CMD_PROFILE_STATUS,g_srv_bt_cm_profile_tbl[j].profile_id,
		                g_srv_bt_cm_profile_tbl[j].deactivate_flag,
		                g_srv_bt_cm_cntx.deactivate_flag,
		                g_srv_bt_cm_profile_tbl[j].activater,
		                g_srv_bt_cm_profile_tbl[j].deactivater);
					if((BCM_PTR->profile_map & (1 << i)) > 0)//activate
					{
						if ( (g_srv_bt_cm_cntx.deactivate_flag & g_srv_bt_cm_profile_tbl[j].deactivate_flag) == 0)
						{
							//already activated. mark finished.
							bt_profile_to_map(KAL_FALSE,&(BCM_PTR->full_map),index_profile_map[i]);
							break;
						}
						else// not activated yet.
						{
							if (g_srv_bt_cm_profile_tbl[j].activater)
	                        {
	                            (*g_srv_bt_cm_profile_tbl[j].activater)();
	                        }
	                        else
	                        {
	                        	//don't have activator, mark finished
	            				bt_profile_to_map(KAL_FALSE,&(BCM_PTR->full_map),index_profile_map[i]);         				
	                        }
						}
					}
					else //deactivate
					{
						if ( (g_srv_bt_cm_cntx.deactivate_flag & g_srv_bt_cm_profile_tbl[j].deactivate_flag) > 0)
						{
							//already deactivated. mark finished.
							bt_profile_to_map(KAL_FALSE,&(BCM_PTR->full_map),index_profile_map[i]);
						}
						else// not activated yet.
						{
							if (g_srv_bt_cm_profile_tbl[j].deactivater)
	                        {
	                            (*g_srv_bt_cm_profile_tbl[j].deactivater)();
	                        }
	                        else
	                        {
	                        	//don't have activator, mark finished
	            				bt_profile_to_map(KAL_FALSE,&(BCM_PTR->full_map),index_profile_map[i]);         				
	                        }
						}
					}
					break;
				}
		    }
        }
    }
    cmd_hdlr_bt_profile_act_cnf(result,KAL_TRUE,0xFFFF);
}

void cmd_hdlr_bt_profile_act_cnf(kal_uint8 result,kal_bool is_act,kal_uint32 profile_id)
{
    kal_int8 i,j = 0;
    bcm_profile_act_cnf_struct *cnf = NULL;  
    kal_uint64 support_profile_map = 0;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_PROFILE_ACT_CNF);
    kal_prompt_trace(MOD_BCM,"result is %d,is_act is %d",result,is_act);

    if(BCM_PTR->curr_req_src != 0)
    {
        //this means this api called when no ACT/DEACT REQ from ATCI, ignore it.
        if((BCM_PTR->act_profile_map == 0 && BCM_PTR->deact_profile_map == 0) 
            || profile_id == 0)//profile_id == 0 means there are some uncorrect calling of this API
        {
            //we should add some warining trace here.
            return;
        }

        //cnf = (bcm_profile_act_cnf_struct*)construct_local_para(sizeof(bcm_profile_act_cnf_struct), TD_RESET);
        //cnf->src_id = BCM_PTR->curr_usr;
        {
            kal_uint8 zero_bits = 0;
            //mask this profile (de)activate request has finished.
            kal_prompt_trace(MOD_BCM,"BCM_PTR->full_map before is %x",BCM_PTR->full_map);
            bt_profile_to_map(KAL_FALSE,&(BCM_PTR->full_map),profile_id);
            kal_prompt_trace(MOD_BCM,"BCM_PTR->full_map after is %x",BCM_PTR->full_map);

            for(zero_bits = 0; zero_bits < sizeof(index_profile_map)/sizeof(kal_uint32); zero_bits++)
            {
                // if there are 1 in the first sizeof(index_profile_map)/sizeof(kal_uint32) bit, 
                // it means still has profile not finished.
                if((BCM_PTR->full_map & (1 << zero_bits)) > 0)
                    break;
            }
            
            kal_prompt_trace(MOD_BCM,"zero_bits number is %d",zero_bits);
            if(zero_bits == sizeof(index_profile_map)/sizeof(kal_uint32))
            {   
                cnf = (bcm_profile_act_cnf_struct*)construct_local_para(sizeof(bcm_profile_act_cnf_struct), TD_RESET) ;
                cnf->src_id = BCM_PTR->curr_usr;            
                //it means all profile op finished.
                // then we check wether current profile_map is equal to request map
                bt_current_activate_profiles_to_map(&support_profile_map);

                kal_prompt_trace(MOD_BCM,"support_profile_map is %x",support_profile_map);
                kal_prompt_trace(MOD_BCM,"BCM_PTR->profile_map is %x",BCM_PTR->profile_map);
                /*if current profile_map is equal to request map
                        *  it means all success.
                        *  else it means partial success
                        */
                if(support_profile_map == BCM_PTR->profile_map)
                {
                    cnf->result = KAL_TRUE;
                }
                else
                {
                	//we still mark it as Success to output value.
                    cnf->result = KAL_TRUE;
                }
		        cnf->acted_profile_map = support_profile_map;

		        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_PROFILE_ACT_CNF, cnf, NULL);
    
			    BCM_PTR->profile_map = 0;
			    BCM_PTR->act_profile_map = 0;
			    BCM_PTR->deact_profile_map = 0;
			    BCM_PTR->full_map = 0xFFFFFFFFFFFFFFFF;
			    
			    BCM_PTR->curr_usr = 0;
			    BCM_PTR->curr_req = 0;
			    BCM_PTR->curr_req_src = 0;
            }

        } 
    }
}

void cmd_hdlr_bt_profile_conn_req(ilm_struct* msg)
{
    srv_bt_cm_bt_addr dev_addr;
    bcm_profile_conn_req_struct *req = (bcm_profile_conn_req_struct*)msg->local_para_ptr;
    kal_bool result = KAL_FALSE;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_PROFILE_CONN_REQ);
    
    dev_addr.lap = req->bd_addr.lap;
    dev_addr.uap = req->bd_addr.uap;
    dev_addr.nap = req->bd_addr.nap;
    
    BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
    BCM_PTR->op = req->op;

    if(is_bt_cmd_cm_allow(msg) && is_bt_cmd_profile_allow(msg))
    {
        if(req->op)//connect
        {
            bcm_set_ext_cm_state(BCM_EXT_CM_STATE_CONNECTING);
        }
#ifdef __BT_SPP_PROFILE__
        if(req->profile == SRV_BT_CM_SPP_PROFILE_UUID)//
        {
            if(req->role)//server, 
            {
                if(req->op == 0)//disconnect, means server want disconnected or reject the aurhorizing 
                {
                    switch(srv_bt_spp_get_state(dev_addr,req->role))
                    {
                        case SRV_SPP_CONN_STATE_AUTHORIZING:
                        {   //reject an client
                            bcm_app_spp_authorize_rsp(dev_addr,req->profile,KAL_FALSE);
                            result = KAL_TRUE;
                            //always success, so we cnf this req. 
                        }
                            break;
                        case SRV_SPP_CONN_STATE_CONNECTED:
                        {   //disconnect a connection, we should get the conn_id, and release it.
                            // we should not use srv_spp_close() because it will deactivate spp.
                            srv_spp_conn_cntx* conn;
                            if(conn = srv_spp_get_conn_by_handle_addr(g_bcm_spp_cntx_p->handle,dev_addr))
                            {
                                //set state to disconnecting when spp disconnect
                                // for  passive flag
                                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DISCONNECTING);								
                                g_srv_bt_cm_cntx.disconnect_con_id = conn->conn_id;
                                srv_bt_cm_release_conn(conn->conn_id);
                            }
                            result = KAL_TRUE;
                            //always success, so we cnf this req. don't wait for ind.
                        }
                            break;
                        default:
                            break;
                    }
                }
                else // connect, means server want accept the aurhorizing
                {
                    if(srv_bt_spp_get_state(dev_addr,req->role)== SRV_SPP_CONN_STATE_AUTHORIZING)
                    {   //accept an client
                        bcm_app_spp_authorize_rsp(dev_addr,req->profile,KAL_TRUE);
                        result = KAL_TRUE;
                        //wait response from BT, care SRV_BT_CM_EVENT_CONNECT_RES
                        return;
                    }
                }
            }
            else //client
            {
                if(req->op == 0)//disconnect
                {                    
                    srv_spp_conn_cntx* conn;
                    if(conn = srv_spp_get_conn_by_handle_addr(g_bcm_spp_client_cntx->handle,dev_addr))
                    {
                        //srv_bt_cm_release_conn(conn->conn_id);
                        //set state to disconnecting when spp disconnect
                        // for	passive flag
                        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DISCONNECTING);						
                        g_srv_bt_cm_cntx.disconnect_con_id = conn->conn_id;
                        srv_spp_close(g_bcm_spp_client_cntx->handle);
                    }
                    result = KAL_TRUE;
                    //always success, so we cnf this req. 
                }
                else // connect
                {
                    srv_spp_instance* inst;
                    //we should int sppc when need, not from the beginning of BT pwr on.
                    /*----------------------------------------------------------------
                                 * Before we init a sppc, we need know does it have a connected connection?
                                 * if yes , we should not init it again.
                                 * if no, we could init it .
                                 *----------------------------------------------------------------
                                 */
                   /*
                                * we init sppc client(g_bcm_spp_client_cntx) each time we receive sppc conn reqest.
                                * but it not perfect.
                                * because when we get the state of the client, if the client is not init yet, we may get handle 0's inst,
                                * the handle 0's inst may be the inited spps client(g_bcm_spp_cntx_p).
                                * so we just add a flag is_initted to record whether or not the sppc is initeded.
                                */
                    if(g_bcm_spp_client_cntx->is_initted)
                    {
                        inst = srv_spp_get_inst_by_handle(g_bcm_spp_client_cntx->handle);
                    }
                    else
                    {
                        inst = NULL;
                    }
                    
                    //it means inst not exist or connection exisited.
                    kal_prompt_trace(MOD_BCM,"before sppc init, it's inst is %x",inst);
                    if(inst)
                        kal_prompt_trace(MOD_BCM,"before sppc init, it's inst->cntx.connect is %x",inst->cntx.connect);
                    if(inst == NULL || inst->cntx.connect == NULL)
                    {
                        bcm_app_sppc_init();
                        
                        if(SRV_SPP_INVALID_HANDLE != g_bcm_spp_client_cntx->handle)
                        {
                            bcm_app_spp_connect(dev_addr);
                            result = KAL_TRUE;
                            //wait response from BT, care SRV_BT_CM_EVENT_CONNECT_RES
                            return;
                        }
                    }
                }
            }
        }
#endif
#ifdef __BT_PBAP_CLIENT__
        if(req->profile == SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID)//
        {
            if(req->role)//server, 
            {
                result = KAL_FALSE;
            }
            else //client
            {
                if(req->op == 0)//disconnect, means client want disconnected or reject the aurhorizing 
                {
                    result = bcm_pbapc_disconnect(req->bd_addr);
                }
                else // connect, means client want accept the aurhorizing
                {
                    result = bcm_pbapc_connect_to_server(req->bd_addr);
                }
                if(result == KAL_TRUE)
                    return;
            }
        }
#endif

#ifdef __BCM_PBAP_SERVER__
        if(req->profile == SRV_BT_CM_OBEX_PBA_PROFILE_UUID)//
        {
            if(req->role)//server, 
            {
                if(req->op == 0)//disconnect, means client want disconnected or reject the aurhorizing 
                {
                    result = KAL_FALSE;
                }
                else // connect, means client want accept the aurhorizing
                {
                    result = bcm_pbap_accept_conn(&req->bd_addr);
                    kal_prompt_trace(MOD_BCM,"bcm_pbap_accept_conn result is %d",result);
                }
                if(result == KAL_TRUE)
                    return;
            }
            else //client
            {
                
                result = KAL_FALSE;
            }
        }    
#endif

#ifdef __MMI_OPP_SUPPORT__
            if(req->profile == SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID
                || req->profile == SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID)//
            { 
                result = KAL_FALSE;
            }

#endif

#ifdef __BT_HF_PROFILE__ 
        if(req->profile == SRV_BT_CM_HF_PROFILE_UUID)//
        {      
            if(req->role == 0)//HF, 
            {          
                if(req->op == 0)//disconnect
                {                    
                	if(srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
                	{
                  		srv_bt_dialer_cm_disconnect_req(&dev_addr,NULL);
                	}	

	                result = KAL_TRUE;
                    //always success, so we cnf this req. 
                }
                else // connect
                {
      				
      				srv_bt_dialer_send_connect_req(&dev_addr, NULL);
      				result = KAL_TRUE;
                }			
            }
        }
#endif/*#ifdef __BT_HF_PROFILE__ */

#ifdef __BT_HFG_PROFILE__ 
		if(req->profile == SRV_BT_CM_HFG_PROFILE_UUID)//
		{
		
			if(req->role)//AG, 
			{          
				if(req->op == 0)//disconnect, means server want disconnected or reject the aurhorizing 
				{
					bcm_hfp_disconnect();	
					result = KAL_TRUE;
				}
				else // connect, means server want accept the aurhorizing
				{
					bcm_hfp_connect(dev_addr);
					result = KAL_TRUE;
				}
		
			}
		}
#endif/*#ifdef __BT_HFG_PROFILE__ */	

#ifdef __BT_A2DP_PROFILE__ 
	    if(req->profile == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)//
		{
			if(req->role)
			{          
				if(req->op == 0)//disconnect
				{
					bcm_a2dp_disconnect(&dev_addr);	
				
					return; //we will return dirrect and do not use profile cnf
				}
				else // connect, 
				{
					bcm_a2dp_connect(&dev_addr);
					
					return; //we will return dirrect and do not use profile cnf
				}
			}
		} 
#endif/*#ifdef __BT_HFG_PROFILE__ */	


    }
    cmd_hdlr_bt_profile_conn_cnf(result,dev_addr,req->profile,req->role);
}
void cmd_hdlr_bt_profile_conn_cnf(kal_uint8 result,srv_bt_cm_bt_addr dev_addr,kal_uint32 profile,kal_uint8 role)
{
    bcm_profile_conn_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_BT_PROFILE_CONN_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
        cnf = (bcm_profile_conn_cnf_struct*)construct_local_para(sizeof(bcm_profile_conn_cnf_struct), TD_RESET);
        cnf->src_id = BCM_PTR->curr_usr;
        cnf->result = result;

        cnf->profile = profile;
        cnf->role = role;
        cnf->op = BCM_PTR->op;
        
        cnf->bd_addr.lap = dev_addr.lap;
        cnf->bd_addr.uap = dev_addr.uap;
        cnf->bd_addr.nap = dev_addr.nap;

        bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_PROFILE_CONN_CNF, cnf, NULL);
    }
    bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);

    BCM_PTR->op = 0;
    
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
}

#if defined(__BT_HF_PROFILE__)

void srv_hfp_hfclcc_req(ilm_struct* msg)
{
	
	bcm_hfp_hfclcc_req_struct *req = (bcm_hfp_hfclcc_req_struct*)msg->local_para_ptr;	

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCLCC_REQ);

	BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;

	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		srv_hfp_hfclcc_cnf(MMI_FALSE);
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCLCC_REQ_INT);
	    return;
	}

	if(!bcm_ucm_clcc_bt())
	{
		srv_hfp_hfclcc_cnf(MMI_FALSE);
	}
	else
	{
		srv_hfp_hfclcc_cnf(MMI_TRUE);
	}
}

void srv_hfp_hfclcc_cnf(kal_uint8 result)
{

    bcm_hfp_hfclcc_cnf_struct *cnf = NULL;

    BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCLCC_CNF);
    
    if(BCM_PTR->curr_req_src != 0)
    {
		cnf = (bcm_hfp_hfclcc_cnf_struct*)construct_local_para(sizeof(bcm_hfp_hfclcc_cnf_struct), TD_RESET);
		cnf->src_id = BCM_PTR->curr_usr;
		cnf->result = result;
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCLCC_CNF_INT);
		bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_CLCC_CNF, cnf, NULL);
    }
	
	BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
	
}


void srv_hfp_hfata_req(ilm_struct* msg)
{
	bcm_hfp_hfata_req_struct *req = (bcm_hfp_hfata_req_struct*)msg->local_para_ptr;	

    BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATA_REQ);

	BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;
	
	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		srv_hfp_hfata_cnf(MMI_FALSE);
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATA_REQ_INT);
		return;
	}
	
	if(!bcm_ucm_answer_bt())
	{
		srv_hfp_hfata_cnf(MMI_FALSE);
	}
	else
	{
		srv_hfp_hfata_cnf(MMI_TRUE);
	}
}

void srv_hfp_hfata_cnf(kal_uint8 result)
{
	   bcm_hfp_hfata_cnf_struct *cnf = NULL;
	
	   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATA_CNF);
	   
	   if(BCM_PTR->curr_req_src != 0)
	   {
			cnf = (bcm_hfp_hfata_cnf_struct*)construct_local_para(sizeof(bcm_hfp_hfata_cnf_struct), TD_RESET);
			cnf->src_id = BCM_PTR->curr_usr;
			cnf->result = result;
			BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATA_CNF_INT);
			bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_ATA_CNF, cnf, NULL);
	   }
	
	   BCM_PTR->curr_usr = 0;
	   BCM_PTR->curr_req = 0;
	   BCM_PTR->curr_req_src = 0;

}


void srv_hfp_hfchup_req(ilm_struct* msg)
{
	bcm_hfp_req_struct *req = (bcm_hfp_req_struct*)msg->local_para_ptr;	

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHUP_REQ);

	BCM_PTR->curr_usr = req->src_id;
    BCM_PTR->curr_req = msg->msg_id;
    BCM_PTR->curr_req_src = msg->src_mod_id;

	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		srv_hfp_hfchup_cnf(MMI_FALSE);
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHUP_REQ_INT);
	    return;	
	}
	
	if(!bcm_ucm_chup_hdlr_bt(req->act))
	{
		srv_hfp_hfchup_cnf(MMI_FALSE);
	}
	else
	{
		srv_hfp_hfchup_cnf(MMI_TRUE);	
	}
}

void srv_hfp_hfchup_cnf(kal_uint8 result)
{
   bcm_hfp_hfata_cnf_struct *cnf = NULL;

   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHUP_CNF);
	   
   if(BCM_PTR->curr_req_src != 0)
   {	
	   cnf = (bcm_hfp_hfata_cnf_struct*)construct_local_para(sizeof(bcm_hfp_hfata_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->role = 1;
	   cnf->result = result;
	   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHUP_CNF_INT);
	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_CHUP_CNF, cnf, NULL);
   }

   BCM_PTR->curr_usr = 0;
   BCM_PTR->curr_req = 0;
   BCM_PTR->curr_req_src = 0;

}

void srv_hfp_hfchld_req(ilm_struct* msg)
{
	bcm_hfp_chld_req_struct *req = (bcm_hfp_chld_req_struct*)msg->local_para_ptr;	

	int result;

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHLD_REQ);

	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;
		
	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHLD_REQ);
		srv_hfp_hfchld_cnf(MMI_FALSE);
	    return;
	}

	result =  bcm_ucm_chld_hdlr_bt(req->act, req->index);
		
	srv_hfp_hfchld_cnf(result);

}


void srv_hfp_hfchld_cnf(kal_uint8 result)
{
   bcm_hfp_cnf_struct *cnf = NULL;

   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHLD_CNF);

   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_hfp_cnf_struct*)construct_local_para(sizeof(bcm_hfp_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;
	   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFCHLD_CNF_INT);
	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_CHLD_CNF, cnf, NULL);
   }

   BCM_PTR->curr_usr = 0;
   BCM_PTR->curr_req = 0;
   BCM_PTR->curr_req_src = 0;

}


void srv_hfp_hfatd_req(ilm_struct* msg)
{
	bcm_hfp_atd_req_struct *req = (bcm_hfp_atd_req_struct*)msg->local_para_ptr;	

	int result;

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATD_REQ);
	
	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;

	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		srv_hfp_hfchld_cnf(MMI_FALSE);
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATD_REQ_INT);
	    return;
	}	
	
	if(req->type == 0)//dial with string
	{
		result = bcm_ucm_dial_bt(req->num);
	}
	else if(req->type == 1)
	{
		result = bcm_ucm_dial_last_bt();
	}
	else if(req->type == 2)
	{
		result = bcm_ucm_dial_mem_bt(req->index);
	}
	else
	{
		result = MMI_FALSE;
	}

	srv_hfp_hfchld_cnf(result);

}

void srv_hfp_hfatd_cnf(kal_uint8 result)
{
   bcm_hfp_cnf_struct *cnf = NULL;

   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATD_CNF);
   
   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_hfp_cnf_struct*)construct_local_para(sizeof(bcm_hfp_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;
	   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFATD_CNF_INT);
	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_ATD_CNF, cnf, NULL);
   }

   BCM_PTR->curr_usr = 0;
   BCM_PTR->curr_req = 0;
   BCM_PTR->curr_req_src = 0;	
}


void srv_hfp_hfvts_req(ilm_struct* msg)
{
	bcm_hfp_req_struct *req = (bcm_hfp_req_struct*)msg->local_para_ptr;	

    BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFVTS_REQ);
	
	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;

	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		srv_hfp_hfvts_cnf(MMI_FALSE);
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFVTS_REQ_INT);
		 return;
	}
	
	if(!bcm_ucm_send_dtmf_bt(req->act))
	{
		srv_hfp_hfvts_cnf(MMI_FALSE);
	}
	else
	{
		srv_hfp_hfvts_cnf(MMI_TRUE);
	}
}

void srv_hfp_hfvts_cnf(kal_uint8 result)
{
	bcm_hfp_cnf_struct *cnf = NULL;

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFVTS_CNF);
   
   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_hfp_cnf_struct*)construct_local_para(sizeof(bcm_hfp_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;
	   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFVTS_CNF_INT); 
	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_VTS_CNF, cnf, NULL);
   }

	BCM_PTR->curr_usr = 0;
	BCM_PTR->curr_req = 0;
	BCM_PTR->curr_req_src = 0;	
	
}


void srv_hfp_hfrvc_req(ilm_struct* msg)
{
	bcm_hfp_rvc_req_struct *req = (bcm_hfp_rvc_req_struct*)msg->local_para_ptr;	

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFRVC_REQ);
	
	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;

	if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	{
		srv_hfp_hfrvc_cnf(MMI_FALSE);
		BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFRVC_REQ_INT);
	    return;
	}
	
	if(!bcm_ucm_remote_volume_control_bt(req->act, req->vol))
	{
		srv_hfp_hfrvc_cnf(MMI_FALSE);
	}
	else
	{
		srv_hfp_hfrvc_cnf(MMI_TRUE);
	}
}

void srv_hfp_hfrvc_cnf(kal_uint8 result)
{
	bcm_hfp_cnf_struct *cnf = NULL;

	BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFRVC_CNF);
   
   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_hfp_cnf_struct*)construct_local_para(sizeof(bcm_hfp_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;
	   BCM_FUNC_ENTRY(FUNC_BCM_SRV_HFP_HFRVC_CNF_INT);
	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HF_RAV_CNF, cnf, NULL);
   }

	BCM_PTR->curr_usr = 0;
	BCM_PTR->curr_req = 0;
	BCM_PTR->curr_req_src = 0;		
}

kal_uint8 bcm_get_ext_hf_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role)
{
    bcm_hf_state_enum profile_state = bcm_get_hf_state(dev_addr,role);

    switch(profile_state)
    {
        case SRV_HF_STATE_IDLE: // means only app init, but not activate. after deactivating , it'll be IDLE.
            profile_state = BCM_EXT_PROFILE_STATE_IDLE;
            break;
        case SRV_HF_STATE_ACTIVE: //for server: after activate( or when begin to connect), it will be ACTIVATE State.
            profile_state = BCM_EXT_PROFILE_STATE_ACTIVATE;
            break;
        case SRV_HF_STATE_CONNECTED://connected
            profile_state = BCM_EXT_PROFILE_STATE_ACTIVATE;
            break;
        case SRV_HF_STATE_DISCONNECTING://disconnecting
            profile_state = BCM_EXT_PROFILE_STATE_DISCONNECTING;
            break;
        case SRV_HF_STATE_DEACTIVATING://deactivating
            profile_state = BCM_EXT_PROFILE_STATE_DEACTIVATING;
            break;
        default:
            profile_state = BCM_EXT_PROFILE_STATE_START;
            break;
    }
    return profile_state;
}


#endif/*#if defined(__BT_HF_PROFILE__)*/

#if defined(__BT_HFG_PROFILE__)

kal_uint8 bcm_get_ext_hfg_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role)
{
    bcm_hfg_state_enum profile_state = bcm_bthf_get_hfg_state(dev_addr,role);

    switch(profile_state)
    {
        case SRV_HFG_STATE_IDLE: // means only app init, but not activate. after deactivating , it'll be IDLE.
            profile_state = BCM_EXT_PROFILE_STATE_IDLE;
            break;
        case SRV_HFG_STATE_ACTIVE: //for server: after activate( or when begin to connect), it will be ACTIVATE State.
            profile_state = BCM_EXT_PROFILE_STATE_ACTIVATE;
            break;
        case SRV_HFG_STATE_CONNECTED://connected
            profile_state = BCM_EXT_PROFILE_STATE_ACTIVATE;
            break;
        case SRV_HFG_STATE_DISCONNECTING://disconnecting
            profile_state = BCM_EXT_PROFILE_STATE_DISCONNECTING;
            break;
        case SRV_HFG_STATE_DEACTIVATING://deactivating
            profile_state = BCM_EXT_PROFILE_STATE_DEACTIVATING;
            break;
        default:
            profile_state = BCM_EXT_PROFILE_STATE_START;
            break;
    }
	MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BCM_GET_HFG_STATE,
        profile_state);
    return profile_state;
}

void srv_hfg_set_audio_path_req(ilm_struct* msg)
{
	bcm_hfg_set_audio_path_req_struct *req = (bcm_hfg_set_audio_path_req_struct*)msg->local_para_ptr;
	U32* mode;
	BTHFAudioMode value  = (BTHFAudioMode)req->act + 1;
	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;

	if(value != BTHF_AUD_REMOTE && value != BTHF_AUD_LOCAL)
	{
		srv_hfg_set_audio_path_cnf(MMI_FALSE);
		return;
	}
	
	mode = srv_bthf_read_config(BTHF_CFG_AUDIO_PATH);
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_HFG_SET_AUDIO_PATH_REQ,
        value,
        *mode);

	if(value == *mode)
	{
		srv_hfg_set_audio_path_cnf(MMI_TRUE);
		return;
	}
	
	srv_bthf_save_config(BTHF_CFG_AUDIO_PATH, &value);
	srv_hfg_set_audio_path_cnf(MMI_TRUE);
	
#if defined(__MMI_BT_AUDIO_SUPPORT__)
    if (srv_bthf_get_status() > BTHF_STATUS_DETACH)
    {
        if (value == BTHF_AUD_LOCAL)
        {
            //srv_btsco_close_stream_req();
            srv_btsco_switch_profile_path(MMI_FALSE);
        }
        else
        {
            //srv_btsco_open_stream_req();
            srv_btsco_switch_profile_path(MMI_TRUE);
        }
    }
#endif
}

void srv_hfg_set_audio_path_cnf(kal_uint8 result)
{
	bcm_hfg_set_audio_path_cnf_struct *cnf = NULL;
   
   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_hfg_set_audio_path_cnf_struct*)construct_local_para(sizeof(bcm_hfg_set_audio_path_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;

	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HFG_SET_AUDIO_PATH_CNF, cnf, NULL);
   }

	BCM_PTR->curr_usr = 0;
	BCM_PTR->curr_req = 0;
	BCM_PTR->curr_req_src = 0;		
}

void srv_hfg_read_audio_path_req(ilm_struct* msg)
{
	bcm_hfg_read_audio_path_req_struct *req = (bcm_hfg_read_audio_path_req_struct*)msg->local_para_ptr;	
	U32* mode = srv_bthf_read_config(BTHF_CFG_AUDIO_PATH);
	
	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;
	if(*mode == BTHF_AUD_REMOTE || *mode == BTHF_AUD_LOCAL)	
		srv_hfg_read_audio_path_cnf(MMI_TRUE, (kal_uint8)*mode);
	else
		srv_hfg_read_audio_path_cnf(MMI_FALSE, 0);
}

void srv_hfg_read_audio_path_cnf(kal_uint8 result, kal_uint8 value)
{
	bcm_hfg_read_audio_path_cnf_struct *cnf = NULL;
   
   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_hfg_read_audio_path_cnf_struct*)construct_local_para(sizeof(bcm_hfg_read_audio_path_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;
	   cnf->value = value - 1;
	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_HFG_READ_AUDIO_PATH_CNF, cnf, NULL);
   }

	BCM_PTR->curr_usr = 0;
	BCM_PTR->curr_req = 0;
	BCM_PTR->curr_req_src = 0;		
}

#endif/*#if defined(__BT_HFG_PROFILE__)*/
#ifdef __BT_A2DP_PROFILE__
void srv_a2dp_reconfig_start_req(ilm_struct* msg)
{
	bcm_a2dp_reconfig_start_req_struct *req = (bcm_a2dp_reconfig_start_req_struct*)msg->local_para_ptr;
	
	BCM_PTR->curr_usr = req->src_id;
	BCM_PTR->curr_req = msg->msg_id;
	BCM_PTR->curr_req_src = msg->src_mod_id;
	
	if(req->op==1)
	{
		bcm_a2dp_reconfig_start(&req->bt_addr,
							NULL,
							req->sample_rate,
							req->stereo
							);
	}
	else
	{
		bcm_a2dp_pause();
	}

}

void srv_a2dp_reconfig_start_cnf(kal_uint8 result)
{
	bcm_a2dp_reconfig_start_cnf_struct *cnf = NULL;
   kal_prompt_trace(MOD_BCM,"[wxw]srv_a2dp_reconfig_start_cnf result:%d src:%d",result,BCM_PTR->curr_req_src);
   if(BCM_PTR->curr_req_src != 0)
   {
	   cnf = (bcm_a2dp_reconfig_start_cnf_struct*)construct_local_para(sizeof(bcm_a2dp_reconfig_start_cnf_struct), TD_RESET);
	   cnf->src_id = BCM_PTR->curr_usr;
	   cnf->result = result;

	   bcm_send_ilm(BCM_PTR->curr_req_src, MSG_ID_BCM_A2DP_RECONFIG_START_CNF, cnf, NULL);
   }

	BCM_PTR->curr_usr = 0;
	BCM_PTR->curr_req = 0;
	BCM_PTR->curr_req_src = 0;		
}
#endif


#endif

