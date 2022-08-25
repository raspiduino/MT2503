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
 *   bcm_msg.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for instead of app layer in BCM (just like MMI BT APP) .
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
 * 02 15 2017 zhenzhen.xu
 * removed!
 * Add srv_a2dp_reconfig_start_cnf() in bcm_a2dp_reconfig_start() and bcm_a2dp_pause().
 *
 * 05 30 2016 ye.tian
 * removed!
 * fix spp srv error.
 *
 * 03 10 2015 zhen.tian
 * removed!
 * .
 *
 * 03 04 2015 xiaowei.wang
 * removed!
 * .
 *
 * 02 04 2015 zhen.tian
 * removed!
 * .
 *
 * 01 27 2015 zhen.tian
 * removed!
 * .
 *
 * 09 12 2014 chaonan.zhao
 * removed!
 * .
 *
 * 04 25 2014 guoqing.ren
 * removed!
 * bt stack 3.0(blueanel) has a modification that when inquery number overload while inquering,
 * it will send discover_cancel_cnf to user.
 *
 * 04 17 2014 yinling.he
 * removed!
 * .
 *
 * 04 14 2014 yinling.he
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
 * 02 20 2014 guoqing.ren
 * removed!
 * when sppc is not init, we need return NULL inst in state check function.
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
 * 	Correct the format of bcm_app_spp_authorize_rsp's 1st para..
 *
 * 02 14 2014 guoqing.ren
 * removed!
 * 	Correct the connection addr getting method by event .
 *
 * 02 14 2014 guoqing.ren
 * removed!
 * 	Add operation condition for pair reject cnf.
 *
 * 02 14 2014 guoqing.ren
 * removed!
 * 	Fix bugg that  2nd conn of spp server error handling.
 *
 * 02 13 2014 guoqing.ren
 * removed!
 * 	Add condition to limit cnf during bt power off.
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
#include "bcm_spp_app.h"
#endif
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"
#include "bcmadp.h"
#include "bcm_struct.h"
#include "bcm_btcmApp.h"

#ifdef __BT_HF_PROFILE__
#include "bcm_BTDialerSrvGprot.h"
#include "bcm_hfpApp.h"
#endif/*#ifdef __BT_HF_PROFILE__*/

#if defined( __BT_HF_PROFILE__) || defined( __BT_HFG_PROFILE__)
#include "bcm_BtAudioSrvGprot.h"
#endif /*defined( __BT_HF_PROFILE__) || defined( __BT_HFG_PROFILE__)*/

#ifdef __BT_OPP_PROFILE__
#include "bcm_OppGprots.h"
#endif
#ifdef __BT_PBAP_CLIENT__
#include "bcm_pbapGprot.h"
#endif
#ifdef __MMI_PBAP_SUPPORT__
#include "bcm_PbapSrv.h"
#endif
#ifdef __BT_A2DP_PROFILE__
#include "bcm_A2dpSrv.h"
void bcm_a2dp_init(void);
#endif
#ifdef __BT_HFG_PROFILE__
bcm_btaud_cntx_struct bcm_btaud_cntx;
bcm_btaud_cntx_struct *g_bcm_btaud_cntx = &bcm_btaud_cntx;
void bcm_hfg_init(void);
void bcm_hfg_deinit(void);

#endif/*#ifdef __BT_HFG_PROFILE__*/

#ifdef __BT_HF_PROFILE__ 
void bcm_hf_init(void);
void bcm_hf_deinit(void);
#endif/*__BT_HF_PROFILE__*/

#ifdef __BT_AVRCP_PROFILE__
void bcm_avrcp_init(void);
#endif

void bcm_bt_cm_init(void);
void bt_event_notify_handle(U32 event, void* para);

void cmd_hdlr_bcm_event_ind(kal_uint32 event,kal_uint8 result,kal_uint8 *para,kal_uint16 para_len);
void cmd_hdlr_profile_event_ind(kal_uint32 profile,kal_uint32 event,kal_uint8 result,kal_uint8 *para,kal_uint16 para_len);
void msg_bcm_activate_ind(kal_uint32 event,kal_uint32 result);
void msg_bcm_deactivate_ind(kal_uint32 event,kal_uint32 result);
void msg_bcm_discovery_result_ind(kal_uint32 event,kal_uint32 result,srv_bt_cm_bt_addr bd_addr,kal_uint8 *name);
void msg_bcm_inquiry_complete_ind(kal_uint32 event,kal_uint32 result,kal_bool is_cancelled);
void msg_bcm_pair_ind(kal_uint32 event,kal_uint8 result, kal_uint8 *dev_name, srv_bt_cm_bt_addr dev_addr,kal_uint8 enable_16digits_pin_code);
void msg_bcm_security_user_confirm_ind(kal_uint32 event,kal_uint8 result, kal_uint8 *dev_name, srv_bt_cm_bt_addr dev_addr,kal_uint8 display_numeric,kal_uint8 *passcode,kal_uint8 pass_len);
void msg_bcm_security_passkey_ind(kal_uint32 event,kal_uint8 result, kal_uint8 *dev_name, srv_bt_cm_bt_addr dev_addr,kal_uint8 *passcode);
void msg_bcm_pair_res_ind(kal_uint32 event,kal_uint8 result, srv_bt_cm_bt_addr dev_addr,kal_bool is_first_pair);
void msg_bcm_disconnect_ind(kal_uint32 event,kal_uint8 result, srv_bt_cm_bt_addr dev_addr,kal_uint32  profile_id,kal_bool passive);
void msg_bcm_release_all_ind(kal_uint32 event,kal_uint8 result, srv_bt_cm_bt_addr dev_addr);
void msg_bcm_set_visibility_ind(kal_uint32 event,kal_uint8 result, kal_bool is_from_mmi);





static const bcm_app_func_ptr bcm_profile_init_tbl[] =
{
    srv_bt_cm_init,
#ifdef __BT_SPP_PROFILE__
    bcm_app_spp_init,
#endif
#ifdef __BT_OPP_PROFILE__
    bcm_opp_init,
#endif
#ifdef __BT_PBAP_CLIENT__
    bcm_pbapc_init,
#endif
#ifdef __BCM_PBAP_SERVER__
    bcm_pbap_init,
#endif
#ifdef __BT_HF_PROFILE__
	bcm_hf_init,
#endif/*#ifdef __BT_HF_PROFILE__*/
#ifdef __BT_HFG_PROFILE__
	bcm_hfg_init,
#endif/*#ifdef __BT_HFG_PROFILE__*/
#ifdef __BT_A2DP_PROFILE__
	bcm_a2dp_init,
#endif
#ifdef __BT_AVRCP_PROFILE__
	bcm_avrcp_init,
#endif
    NULL
};

static const bcm_app_func_ptr bcm_profile_deinit_tbl[] =
{
    /*
        *may be spp need deint here.
        * but mmi server didn't deinit ,so we do not do this.
        */
#ifdef __BT_OPP_PROFILE__
    bcm_opp_deinit,
#endif
#ifdef __BT_PBAP_CLIENT__
    bcm_pbapc_deinit,
#endif
#ifdef __BCM_PBAP_SERVER__
    bcm_pbap_deinit,
#endif
#ifdef __BT_HF_PROFILE__        
    bcm_hf_deinit,    
#endif/*#ifdef __BT_HF_PROFILE__*/
#ifdef __BT_HFG_PROFILE__
	bcm_hfg_deinit,
#endif/*#ifdef __BT_HFG_PROFILE__*/	

    NULL
};

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_deinit
 * DESCRIPTION
 *  This function is to deinit all profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bcm_app_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_DEINIT);

    for (i = 0; i < (sizeof(bcm_profile_deinit_tbl) / sizeof(bcm_app_func_ptr)); i++)
    {
        if (bcm_profile_deinit_tbl[i])
        {
            (*bcm_profile_deinit_tbl[i])();
        }
    }

    srv_bt_cm_reset_notify(BCM_PTR->cm_handle);
    

    //we do more clear action than mmi bt service
    BCM_PTR->curr_usr = 0;
    BCM_PTR->curr_req = 0;
    BCM_PTR->curr_req_src = 0;
    BCM_PTR->op = 0;
    BCM_PTR->profile_map = 0;
    BCM_PTR->act_profile_map = 0;
    BCM_PTR->deact_profile_map = 0;
    memset(&(BCM_PTR->dev_addr),0,sizeof(srv_bt_cm_bt_addr));
}


/*****************************************************************************
 * FUNCTION
 *  bcm_app_init
 * DESCRIPTION
 *  This function is to initialize Bluetooth profiles app
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bcm_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INIT);

    for (i = 0; i < (sizeof(bcm_profile_init_tbl) / sizeof(bcm_app_func_ptr)); i++)
    {
        if (bcm_profile_init_tbl[i])
        {
            (*bcm_profile_init_tbl[i])();
        }
    }

    bcm_bt_cm_init();
}

void bcm_bt_cm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SCR_INIT);
    //memset(&g_mmi_bt_scr_cntx, 0, sizeof(mmi_bt_scr_cntx_struct));
    event_mask = SRV_BT_CM_EVENT_ACTIVATE |
                 SRV_BT_CM_EVENT_DEACTIVATE  |
                 SRV_BT_CM_EVENT_INQUIRY_IND |
                 SRV_BT_CM_EVENT_INQUIRY_COMPLETE |
                 SRV_BT_CM_EVENT_PAIR_IND |
                 SRV_BT_CM_EVENT_BOND_RES|
                 SRV_BT_CM_EVENT_PAIR_RES |
                 SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM |
                 SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY |
                 SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY |
                 SRV_BT_CM_EVENT_CONNECT_RES |
                 SRV_BT_CM_EVENT_DISCONNECT_IND |
                 SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
#if !defined(__MMI_BT_SLIM__)
                 SRV_BT_CM_EVENT_REFRESH_PROFILE |
#endif  // !defined(__MMI_BT_SLIM__)
#ifdef __MMI_BT_AUTHORIZE__
                 SRV_BT_CM_EVENT_SET_AUTHORIZE |
                 SRV_BT_CM_EVENT_UNBLOCK |
#endif  // __MMI_BT_AUTHORIZE__
// #ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
//                  SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE |
// #endif  // __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
#ifdef __MMI_SIMAP_SUPPORT__
                 SRV_BT_CM_EVENT_SET_SIMAP |
#endif  // __MMI_SIMAP_SUPPORT__
#ifdef __BT_AUTO_DETECT_SUPPORT__
                 SRV_BT_CM_EVENT_CHIP_DETECT |
#endif  // __BT_AUTO_DETECT_SUPPORT__
                 SRV_BT_CM_EVENT_MYDEV_DEL |
                 SRV_BT_CM_EVENT_SET_VISIBILITY |
                 SRV_BT_CM_EVENT_SET_NAME |
                 SRV_BT_CM_EVENT_SCO_IND |
                 SRV_BT_CM_EVENT_PANIC_IND |
                 SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME |
                 SRV_BT_CM_EVENT_BEGIN_ACTIVATE |
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE |
                 SRV_BT_CM_EVENT_SET_AUTHENTICATION;

    BCM_PTR->cm_handle = srv_bt_cm_set_notify((srv_bt_cm_notifier)bt_event_notify_handle, event_mask, NULL);
}


/*蓝牙操作后的事件通知 -- chengjun  2017-05-18*/
/*BCM发消息通知L4C -- chengjun  2017-05-23*/
extern void  track_ble_on_start_gatt_server(void);

void bt_event_notify_handle(kal_uint32 event, void* para)
{
    kal_prompt_trace(MOD_BCM,"bt_event_notify_handle RECEIVED EVENT %d",event);

#if defined (__BLE_DEBUG_LOG__)
    {
        char testLog[128] = {0};
        sprintf(testLog, "bt_event_notify_handle %d\r\n",event);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
    }
#endif /* __BLE_DEBUG_LOG__ */
    
    switch (event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE://蓝牙打开了
        {
            srv_bt_cm_activate_struct *event_struct = (srv_bt_cm_activate_struct *)para;
            
            msg_bcm_activate_ind(event,event_struct->result);

#if defined (__BLE_GATT__)
	track_ble_on_start_gatt_server();
#endif /* __BLE_GATT__ */
#if defined (__BLE_N07__)
			track_ble_gatt_event(0,1);
#endif
        }        
            break;

        case SRV_BT_CM_EVENT_DEACTIVATE:
        {
            srv_bt_cm_deactivate_struct *event_struct = (srv_bt_cm_deactivate_struct *)para;
            cmd_hdlr_bt_power_on_cnf(KAL_TRUE);
            msg_bcm_deactivate_ind(event,event_struct->result);
			
#if defined (__BLE_N07__)
			track_ble_gatt_event(0,0);
#endif
        }   
            break;

        case SRV_BT_CM_EVENT_INQUIRY_IND:
        {
            U8 discov_dev_counter = 0;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_INQ_RESULT);

            discov_dev_counter = srv_bt_cm_get_searched_dev_num();
            /* display first found entry or finish inquiry action */
            if (discov_dev_counter <= BCM_PTR->inquiry_number)
            {
                msg_bcm_discovery_result_ind(event,KAL_TRUE,g_srv_bt_cm_cntx.discovered_list[discov_dev_counter-1].bd_addr,(kal_uint8*)(g_srv_bt_cm_cntx.discovered_list[discov_dev_counter-1].name));
            }
        }
            break;

        case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
        {
            kal_uint32 result;
            kal_bool is_cancelled;
            U8 discov_dev_counter = 0;
            srv_bt_cm_inquiry_complete_struct *event_struct = (srv_bt_cm_inquiry_complete_struct *)para;
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INQ_COMPLETE, event_struct->result);

            discov_dev_counter = srv_bt_cm_get_searched_dev_num();

            switch (event_struct->result)
            {
                case BTBM_ADP_SUCCESS:
                    result = KAL_TRUE;
                    break;
                case BTBM_ADP_FAILED:                
                case BTBM_ADP_BUSY:
                case BTBM_ADP_NOT_ALLOW:
                default:
                    result = KAL_FALSE;
                    break;
            }            
			//we need notify ATCI when received DISCOVER_CANCEL_CNF while discovering on BLUEANGEL
			msg_bcm_inquiry_complete_ind(event,result,event_struct->is_cancelled);        
			if(event_struct->is_cancelled) {//&& BCM_PTR->curr_req == CANCEL_REQ
				cmd_hdlr_bt_discovery_cancel_cnf(result,discov_dev_counter);
			}

        }
            break;
        case SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME:
        {
            srv_bt_cm_bt_addr addr;
            kal_uint8 name_len;
            kal_uint8 i;
            srv_bt_cm_read_remote_dev_name_struct *event_struct = (srv_bt_cm_read_remote_dev_name_struct *)para;
            if(event_struct->dev_addr)
                memcpy(&addr,event_struct->dev_addr,sizeof(srv_bt_cm_bt_addr));

            i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&addr, SRV_BT_CM_ALL_DEV);
            if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
            {
                cmd_hdlr_bt_read_remote_name_cnf(KAL_FALSE,addr,NULL,0);
            }
            else
            {
                name_len = strlen(g_srv_bt_cm_cntx.dev_list[i].dev_info.name);
                cmd_hdlr_bt_read_remote_name_cnf(KAL_TRUE,addr,g_srv_bt_cm_cntx.dev_list[i].dev_info.name,name_len);
            }
        }
            break;
        case SRV_BT_CM_EVENT_PAIR_IND:
        {
            kal_uint8 asc_pin_buf[32] = {0};
            srv_bt_cm_pair_ind_struct *event_struct = (srv_bt_cm_pair_ind_struct *)para;
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_PASSKEY_INPUT);
            BCM_PTR->cm_pair_state = BCM_CM_PAIR_STATE_PIN_CODE;
            
            if (srv_bt_cm_get_paired_dev_num() >= SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
                !srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr *)&(event_struct->dev_addr), SRV_BT_CM_PAIRED_DEV))
            {
                srv_bt_cm_send_passkey(&(event_struct->dev_addr), asc_pin_buf, MMI_FALSE);
                
                if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
                {
                /* when this event, we have state check in srv_bt_cm_check_rejecting_state() to ensure this will not happen:
                            *  ATCI sending bonding_req while  another device trying bonding us.
                            */
                    cmd_hdlr_bt_bonding_cnf(KAL_FALSE,event_struct->dev_addr,NULL,0,0,0,NULL,0);
                }
                else
                {
                    //do nothing because we reject this ind.
                }                   
                return;
            }

            if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
            {
            /* when this event, we have state check in srv_bt_cm_check_rejecting_state() to ensure this will not happen:
                        *  ATCI sending bonding_req while  another device trying bonding us.
                        */
                cmd_hdlr_bt_bonding_cnf(KAL_TRUE,event_struct->dev_addr,event_struct->dev_name,strlen(event_struct->dev_name),
                    0,event_struct->enable_16digits_pin_code,NULL,0);
            }
            else
            {
                //ind this event.
                msg_bcm_pair_ind(event,KAL_TRUE,event_struct->dev_name,event_struct->dev_addr,event_struct->enable_16digits_pin_code);
            }
            
        }            
            break;

        case SRV_BT_CM_EVENT_PAIR_RES:
        {
            /*
                    * There are two scenarios can send this event:
                    * 1 BCM received BONDING_RESULT_IND after BCM send BOND_RES_REQ.
                    * 2 BCM received BONDING_RESULT_IND after BCM send BOND_REQ and BCM CNFed 
                    *       but no BOND_RES_REQ was sent.
                    * the 1st case we just use cmd_hdlr_bt_bonding_rsp_cnf() handle this EVENT.
                    * the 2nd case we should send ind to ATCI, but we didn't call msg_bcm_pair_res_ind() here because
                    *       we can't get all condition we need. we add it to srv_bt_cm_bond_ind_hdler().
                    */
            srv_bt_cm_pair_res_struct *event_struct = (srv_bt_cm_pair_res_struct *)para;
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_PAIR_RESULT, event_struct->result);

            if(srv_bt_cm_get_state() != SRV_BT_CM_STATE_DEACTIVATING)
            {
                if(BCM_PTR->op == 0)//disconnect, if connect failed we should send true to ATCI, means disconnect success.
                {
                    cmd_hdlr_bt_bonding_rsp_cnf((event_struct->result != SRV_BT_CM_RESULT_SUCCESS)? KAL_TRUE : KAL_FALSE,event_struct->dev_addr);
                }
                else //connect,if connect failed we should send false to ATCI, means connect failed.
                {
                    cmd_hdlr_bt_bonding_rsp_cnf((event_struct->result == SRV_BT_CM_RESULT_SUCCESS)? KAL_TRUE : KAL_FALSE,event_struct->dev_addr);
                }
            }

            BCM_PTR->cm_pair_state = BCM_CM_PAIR_STATE_IDLE;
        }           
            break;

        case SRV_BT_CM_EVENT_BOND_RES:
        {
            /* from the log, we found that each time MOD_BT send MSG_ID_BT_BM_BONDING_CNF
                     * it will send another MSG_ID_BT_BM_BONDING_RESULT_IND in earlier time.
                     *  so SRV_BT_CM_EVENT_PAIR_RES would have been sent.
                     *  so we don't handle this event.
                     */
        }
            break;

#ifdef __MMI_BT_SIMPLE_PAIR__
        case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
        {            
            srv_bt_cm_security_user_confirm_struct *event_struct = (srv_bt_cm_security_user_confirm_struct *)para;
            
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_G7_BT_SECURITY_USER_CONFIRM,
                event_struct->dev_addr.lap,
                event_struct->dev_addr.uap,
                event_struct->dev_addr.nap);
            
            BCM_PTR->cm_pair_state = BCM_CM_PAIR_STATE_USER_CONFIRM;

            if (srv_bt_cm_get_paired_dev_num() == SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
                !srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr*)&(event_struct->dev_addr), SRV_BT_CM_PAIRED_DEV))
            {
                srv_bt_cm_security_numeric_confirm(&(event_struct->dev_addr), MMI_FALSE);
                if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
                {
                /* when this event, we have state check in srv_bt_cm_check_rejecting_state() to ensure this will not happen:
                            *  ATCI sending bonding_req while  another device trying bonding us.
                            */
                    cmd_hdlr_bt_bonding_cnf(KAL_FALSE,event_struct->dev_addr,NULL,0,0,0,NULL,0);
                }
                else
                {
                    //do nothing because we reject this ind.
                }
                return;
            }
            
            if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
            {
            /* when this event, we have state check in srv_bt_cm_check_rejecting_state() to ensure this will not happen:
                        *  ATCI sending bonding_req while  another device trying bonding us.
                        */
                cmd_hdlr_bt_bonding_cnf(KAL_TRUE,event_struct->dev_addr,event_struct->dev_name,strlen(event_struct->dev_name),
                    event_struct->display_numeric,0,event_struct->passcode,6);
            }
            else
            {
                //ind this event.
                msg_bcm_security_user_confirm_ind(event,KAL_TRUE,event_struct->dev_name,event_struct->dev_addr,event_struct->display_numeric,event_struct->passcode,6);
            }            
        }
            break;

        case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
        {
            srv_bt_cm_security_passkey_struct *event_struct = (srv_bt_cm_security_passkey_struct *)para;


            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_G7_BT_SECURITY_PASSKEY_NOTIFY,
                event_struct->dev_addr.lap,
                event_struct->dev_addr.uap,
                event_struct->dev_addr.nap);

            BCM_PTR->cm_pair_state = BCM_CM_PAIR_STATE_PASSKEY_NOTIFY;
            
            if (srv_bt_cm_get_paired_dev_num() >= SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
                !srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr*)&(event_struct->dev_addr), SRV_BT_CM_PAIRED_DEV))
            {
                srv_bt_cm_security_keypress_notify_cancel(&(event_struct->dev_addr));
                if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
                {
                /* when this event, we have state check in srv_bt_cm_check_rejecting_state() to ensure this will not happen:
                            *  ATCI sending bonding_req while  another device trying bonding us.
                            */
                    cmd_hdlr_bt_bonding_cnf(KAL_FALSE,event_struct->dev_addr,NULL,0,0,0,NULL,0);
                }
                else
                {
                    //do nothing because we reject this ind.
                }
                return;
            }

            if(BCM_PTR->curr_req == MSG_ID_BCM_BONDING_REQ)
            {
            /* when this event, we have state check in srv_bt_cm_check_rejecting_state() to ensure this will not happen:
                        *  ATCI sending bonding_req while  another device trying bonding us.
                        */
                cmd_hdlr_bt_bonding_cnf(KAL_TRUE,event_struct->dev_addr,event_struct->dev_name,strlen(event_struct->dev_name),
                    0,0,event_struct->passcode,strlen(event_struct->passcode));
            }
            else
            {
                //ind this event.
                msg_bcm_security_passkey_ind(event,KAL_TRUE,event_struct->dev_name,event_struct->dev_addr,event_struct->passcode);
            }                
        }            
            break;

        case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
            // not support yet.

            BCM_PTR->cm_pair_state = BCM_CM_PAIR_STATE_KEYPRESS_NOTIFY;
            break;
#endif

        case SRV_BT_CM_EVENT_CONNECT_RES:
        {
            kal_uint8 role = 0;
            srv_bt_cm_conn_res_struct *event_struct = (srv_bt_cm_conn_res_struct *)para;
#ifdef __BT_SPP_PROFILE__
            if(event_struct->profile_id == SRV_BT_CM_SPP_PROFILE_UUID)
            {
                const srv_spp_instance* inst = NULL; 
                //inst = srv_spp_get_inst_by_handle(g_bcm_spp_cntx_p->handle);
				inst = srv_spp_get_inst_by_conn_id(event_struct->conn_id);
                role = SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_ROLE_SERVER);
				
            }
#endif
#ifdef __BT_PBAP_CLIENT__
            if(event_struct->profile_id == SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID)
            {
                role = 0;
                bcm_pbapc_connect_result(*(event_struct->dev_addr),event_struct->result);                
            }
#endif
#ifdef __BCM_PBAP_SERVER__
            if(event_struct->profile_id == SRV_BT_CM_OBEX_PBA_PROFILE_UUID)
            {       
            }//do nothing
#endif
#ifdef __MMI_OPP_SUPPORT__
            //do nothing, OPP profile connection is not initiated by BTCM CMD
#endif
            if(srv_bt_cm_get_state() != SRV_BT_CM_STATE_DEACTIVATING)
            {
                cmd_hdlr_bt_profile_conn_cnf((event_struct->result == SRV_BT_CM_BTBM_SUCCESS),
                    *(event_struct->dev_addr),event_struct->profile_id,role);
            }
        }
            break;

        case SRV_BT_CM_EVENT_DISCONNECT_IND:
        {
            srv_bt_cm_bt_addr dev_addr ;
            srv_bt_cm_disconnect_ind_struct *event_struct = (srv_bt_cm_disconnect_ind_struct *)para;
        	dev_addr.lap = event_struct->dev_addr->lap;
        	dev_addr.uap= event_struct->dev_addr->uap;
        	dev_addr.nap = event_struct->dev_addr->nap;
        	

        	/*
        	        * two scenarios will received SRV_BT_CM_EVENT_DISCONNECT_IND:
        	        * 1. disconnect by peer.  we should send indcation.
        	        * 2. connect from self but failed. we should send cnf also, but we put the cnf code into conn app's CONNECT event handler..
        	        */
            msg_bcm_disconnect_ind( event, KAL_TRUE,dev_addr,event_struct->profile_id,event_struct->passive);

        }        
            break;

        case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
        {
            srv_bt_cm_bt_addr dev_addr;
            srv_bt_cm_release_all_struct *event_struct = (srv_bt_cm_release_all_struct *)para;
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_RELEASE_ALL_CONN_COMPLETE, event_struct->result);
            if(event_struct->dev_addr)
            {
                dev_addr.lap = event_struct->dev_addr->lap;
                dev_addr.uap = event_struct->dev_addr->uap;
                dev_addr.nap = event_struct->dev_addr->nap;
            }
            else
            {
                dev_addr.lap = 0;
                dev_addr.uap = 0;
                dev_addr.nap = 0;
            }
            msg_bcm_release_all_ind(event,event_struct->result,dev_addr);
        }        
            break;

        case SRV_BT_CM_EVENT_REFRESH_PROFILE:
        {
            /*
                    * Because event SRV_BT_CM_EVENT_REFRESH_PROFILE doesn't take dev_addr,
                    * so we can't get dev_addr.
                    * Thus we insert cmd_hdlr_bt_service_search_cnf() to place where SRV_BT_CM_EVENT_REFRESH_PROFILE was sent.
                    * it is srv_bt_cm_sdc_search_cnf_hdler().
                    */
            //cmd_hdlr_bt_service_search_cnf(result,srv_bt_cm_bt_addr bd_addr);
        }
            break;

        case SRV_BT_CM_EVENT_MYDEV_DEL:
        {
            srv_bt_cm_mydev_del_struct *event = (srv_bt_cm_mydev_del_struct *)para;
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_DEL_TR_RES, event->result);
            //may be delete all or one. that's why we add op in BCM_PTR
            cmd_hdlr_bt_dev_list_op_cnf(event->result,BCM_PTR->op,0,NULL);
        }
            break;

#ifdef __MMI_BT_AUTHORIZE__
        case SRV_BT_CM_EVENT_SET_AUTHORIZE:
        // currently we don't have at for ALYs Connect or Rejet, so not used yet.
            break;

        case SRV_BT_CM_EVENT_UNBLOCK:
        //tell ap some dev set to be unblock, not used yet.
            break;
#endif

        case SRV_BT_CM_EVENT_SET_VISIBILITY:
        {
            srv_bt_cm_set_visibility_struct *event_struct = (srv_bt_cm_set_visibility_struct *)para;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_VIS_COMPLETE);
            
            if (event_struct->is_from_mmi)
            {
                // we need CNF ATCI
                cmd_hdlr_bt_write_scan_mode_cnf(event_struct->result);
            }
            else
            {
                // we need IND ATCI
                msg_bcm_set_visibility_ind(event,event_struct->result,event_struct->is_from_mmi);
            }

        }
            break;

        case SRV_BT_CM_EVENT_SET_NAME: 
        {
            srv_bt_cm_set_name_struct *event_struct = (srv_bt_cm_set_name_struct *)para;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_NAME_PROC_COMPLETE, event_struct->result);
            cmd_hdlr_bt_write_local_name_cnf((event_struct->result == BTBM_ADP_SUCCESS) ? MMI_TRUE : MMI_FALSE);
        }
            break;

#ifdef __MMI_SIMAP_SUPPORT__
        case SRV_BT_CM_EVENT_SET_SIMAP:
        //not support SIMAP yet.
            break;
#endif

        case SRV_BT_CM_EVENT_SCO_IND:
        //not support yet.
            break;

        case SRV_BT_CM_EVENT_PANIC_IND:
        {
            srv_bt_cm_panic_ind_struct *event_struct = (srv_bt_cm_panic_ind_struct *)para;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PANIC_IND_POST_PROCESS);

            //StopTimer(BT_RELEASE_ALL_CON_GUARD_TIMER);
            //StopTimer(BT_POPUP_TIMER);

            srv_bt_cm_recover_panic_req();


            bcm_app_deinit();

            bcm_app_init();
            
            cmd_hdlr_bcm_event_ind(event,KAL_TRUE,NULL,0);

        }        
            break;



#ifdef __BT_AUTO_DETECT_SUPPORT__
        case SRV_BT_CM_EVENT_CHIP_DETECT:
        //not used yet.
            break;
#endif

        case SRV_BT_CM_EVENT_BEGIN_ACTIVATE:
        //not used for ATCI yet.
            break;
            
        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE://蓝牙关闭
        //not used for ATCI yet.
            break;
        case SRV_BT_CM_EVENT_SET_AUTHENTICATION:
        {
            srv_bt_cm_set_authentication_struct *event_struct = (srv_bt_cm_set_authentication_struct *)para;
            cmd_hdlr_bt_write_auth_mode_cnf((event_struct->result == BTBM_ADP_SUCCESS ? KAL_TRUE : KAL_FALSE),srv_bt_cm_get_host_dev_security_level(),0);
        }
            break;
        default:
            break;
    }
}


void cmd_hdlr_bcm_event_ind(kal_uint32 event,kal_uint8 result,kal_uint8 *para,kal_uint16 para_len)
{
    bcm_event_ind_struct *ind = NULL;   
    ind = (bcm_event_ind_struct*)construct_local_para(sizeof(bcm_event_ind_struct), TD_RESET);

    ind->event = event;
    ind->result = result;
    ind->para = para;
    ind->para_len = para_len;
    
    bcm_send_ilm(MOD_L4C, MSG_ID_BCM_EVENT_IND, ind, NULL);
}
void cmd_hdlr_profile_event_ind(kal_uint32 profile,kal_uint32 event,kal_uint8 result,kal_uint8 *para,kal_uint16 para_len)
{
    bcm_profile_event_ind_struct *ind = NULL;   
    ind = (bcm_profile_event_ind_struct*)construct_local_para(sizeof(bcm_profile_event_ind_struct), TD_RESET);

    ind->profile = profile; 
    ind->event = event;
    ind->result = result;
    ind->para = para;
    ind->para_len = para_len;
    
    bcm_send_ilm(MOD_L4C, MSG_ID_BCM_PROFILE_EVENT_IND, ind, NULL);
}
void msg_bcm_activate_ind(kal_uint32 event,kal_uint32 result)
{
    bcm_activate_struct *ind  = (bcm_activate_struct*)get_ctrl_buffer(sizeof( bcm_activate_struct));
    ind->result = result;

    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof( bcm_activate_struct));
}
void msg_bcm_deactivate_ind(kal_uint32 event,kal_uint32 result)
{
    bcm_deactivate_struct *ind  = (bcm_deactivate_struct*)get_ctrl_buffer(sizeof( bcm_deactivate_struct));
    ind->result = result;

    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof( bcm_deactivate_struct));
}

void msg_bcm_discovery_result_ind(kal_uint32 event,kal_uint32 result,srv_bt_cm_bt_addr bd_addr,kal_uint8 *name)
{
    bcm_discovery_result_ind_struct *ind  = (bcm_discovery_result_ind_struct*)get_ctrl_buffer(sizeof( bcm_discovery_result_ind_struct));
    ind->bd_addr.lap = bd_addr.lap;
    ind->bd_addr.uap = bd_addr.uap;
    ind->bd_addr.nap = bd_addr.nap;

    if(name)
        ind->name_len = strlen(name);
    if(ind->name_len > 0)
        memcpy(&(ind->name),name,ind->name_len);
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_discovery_result_ind_struct)); 

}
void msg_bcm_inquiry_complete_ind(kal_uint32 event,kal_uint32 result,kal_bool is_cancelled)
{
    bcm_inquiry_complete_struct *ind  = (bcm_inquiry_complete_struct*)get_ctrl_buffer(sizeof( bcm_inquiry_complete_struct));
    ind->result = result;
    ind->is_cancelled = is_cancelled;
    
    bcm_set_ext_cm_state(BCM_EXT_CM_STATE_READY);

    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_discovery_result_ind_struct)); 

}
void msg_bcm_pair_ind(kal_uint32 event,kal_uint8 result, kal_uint8 *dev_name, srv_bt_cm_bt_addr dev_addr,kal_uint8 enable_16digits_pin_code)
{
    //ind this event.
    bcm_pair_ind_struct *ind = (bcm_pair_ind_struct*)get_ctrl_buffer(sizeof(bcm_pair_ind_struct));
    ind->dev_addr.lap = dev_addr.lap;
    ind->dev_addr.uap = dev_addr.uap;
    ind->dev_addr.nap = dev_addr.nap;
    ind->enable_16digits_pin_code = enable_16digits_pin_code;
    
    if(dev_name)
    {
        ind->name_len = strlen(dev_name);
        memcpy(ind->name,dev_name,ind->name_len);
    }

    BCM_PTR->dev_addr = dev_addr;
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_pair_ind_struct));
}

void msg_bcm_security_user_confirm_ind(kal_uint32 event,kal_uint8 result, kal_uint8 *dev_name, srv_bt_cm_bt_addr dev_addr,kal_uint8 display_numeric,kal_uint8 *passcode,kal_uint8 pass_len)
{
    kal_uint8 max_len = 0;
    //ind this event.
    bcm_security_user_confirm_struct *ind = (bcm_security_user_confirm_struct*)get_ctrl_buffer(sizeof(bcm_security_user_confirm_struct));
    ind->dev_addr.lap = dev_addr.lap;
    ind->dev_addr.uap = dev_addr.uap;
    ind->dev_addr.nap = dev_addr.nap;

    ind->display_numeric = display_numeric;
    if(dev_name)
    {
        ind->name_len = strlen(dev_name);
        max_len = ind->name_len < sizeof(ind->name) ? ind->name_len : sizeof(ind->name);
        memcpy(ind->name,dev_name,ind->name_len);
    }

    if(passcode)
    {
        ind->password_len= strlen(passcode) < pass_len ? strlen(passcode) : pass_len;
        max_len = ind->password_len < sizeof(ind->password) ? ind->password_len : sizeof(ind->password);
        memcpy(ind->password,passcode,ind->password_len);
    }
    BCM_PTR->dev_addr = dev_addr;
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_security_user_confirm_struct));
}

void msg_bcm_security_passkey_ind(kal_uint32 event,kal_uint8 result, kal_uint8 *dev_name, srv_bt_cm_bt_addr dev_addr,kal_uint8 *passcode)
{
    //ind this event.
    bcm_security_passkey_struct *ind = (bcm_security_passkey_struct*)get_ctrl_buffer(sizeof(bcm_security_passkey_struct));
    ind->dev_addr.lap = dev_addr.lap;
    ind->dev_addr.uap = dev_addr.uap;
    ind->dev_addr.nap = dev_addr.nap;
    
    if(dev_name)
    {
        ind->name_len = strlen(dev_name);
        memcpy(ind->name,dev_name,ind->name_len);
    }

    if(passcode)
    {
        ind->password_len= strlen(passcode);
        memcpy(ind->password,passcode,ind->password_len);
    }
    BCM_PTR->dev_addr = dev_addr;
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_security_passkey_struct));
}
void msg_bcm_pair_res_ind(kal_uint32 event,kal_uint8 result, srv_bt_cm_bt_addr dev_addr,kal_bool is_first_pair)
{
    //ind this event.
    bcm_pair_res_struct *ind = (bcm_pair_res_struct*)get_ctrl_buffer(sizeof(bcm_pair_res_struct));
    ind->dev_addr.lap = dev_addr.lap;
    ind->dev_addr.uap = dev_addr.uap;
    ind->dev_addr.nap = dev_addr.nap;
    
    ind->is_first_pair = is_first_pair;
    ind->result = result;
    
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_pair_res_struct));
}

void msg_bcm_disconnect_ind(kal_uint32 event,kal_uint8 result, srv_bt_cm_bt_addr dev_addr,kal_uint32  profile_id,kal_bool passive)
{
    //ind this event.
    bcm_disconnect_ind_struct *ind = (bcm_disconnect_ind_struct*)get_ctrl_buffer(sizeof(bcm_disconnect_ind_struct));
    ind->dev_addr.lap = dev_addr.lap;
    ind->dev_addr.uap = dev_addr.uap;
    ind->dev_addr.nap = dev_addr.nap;
    
    ind->passive = passive;
    ind->profile_id = profile_id;
    
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_disconnect_ind_struct));
}
void msg_bcm_release_all_ind(kal_uint32 event,kal_uint8 result, srv_bt_cm_bt_addr dev_addr)
{
    //ind this event.
    bcm_release_all_struct *ind = (bcm_release_all_struct*)get_ctrl_buffer(sizeof(bcm_release_all_struct));
    ind->dev_addr.lap = dev_addr.lap;
    ind->dev_addr.uap = dev_addr.uap;
    ind->dev_addr.nap = dev_addr.nap;
    
    ind->result = result;
    
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)ind,sizeof(bcm_release_all_struct));
}

void msg_bcm_set_visibility_ind(kal_uint32 event,kal_uint8 result, kal_bool is_from_mmi)
{
    // we need IND ATCI
    bcm_set_visibility_struct *visibility = (bcm_set_visibility_struct *)get_ctrl_buffer(sizeof(bcm_set_visibility_struct));
    visibility->is_from_mmi = is_from_mmi;
    visibility->result = result;
    cmd_hdlr_bcm_event_ind(event,result,(kal_uint8*)visibility,sizeof(bcm_set_visibility_struct));
}

#endif

#ifdef __BT_HFG_PROFILE__

static S32 bcm_btaud_notify_hdlr(U32 event, U32 arg, void *user_data)
{
    switch (event) {
    case BTAUD_EV_ATTACH_REQ:
        srv_btaud_accept(g_bcm_btaud_cntx->srv_hd);
		//srv_btaud_attach
        break;

    case BTAUD_EV_ATTACH_ABORT:
        
        //btaud_auth_aborted();
        
        break;

    case BTAUD_EV_ATTACH_IND:
		srv_btaud_get_device_info(arg, &g_bcm_btaud_cntx->dev_info);
        
       // btaud_attach_ind(arg);
        
        break;

    case BTAUD_EV_ATTACH_FAIL:
        
        //btaud_attach_fail();
        
        break;

    case BTAUD_EV_CHNL_UPDATE:
        
        //btaud_chnl_update(arg);
        
        break;

    case BTAUD_EV_DETACH_IND://detach
        
      //  btaud_detach_ind(arg);
        
        break;

    case BTAUD_EV_SWITCH_IND:
        break;

#ifdef __BT_SPK_VOL_CONTROL__
    case BTAUD_EV_VOLUME_IND:
        
        mdi_audio_sync_volume_from_bt((U8)arg);
        
        break;
#endif

    default:
        break;
    }

    return 0;
}


void bcm_btaud_init(void)
{
    U32 events = BTAUD_EV_ATTACH_IND |
                 BTAUD_EV_ATTACH_FAIL |
                 BTAUD_EV_DETACH_IND |
                 BTAUD_EV_SWITCH_IND |
                 BTAUD_EV_SWITCH_FAIL |
                 BTAUD_EV_CHNL_UPDATE |
                 BTAUD_EV_ATTACH_REQ |
                 BTAUD_EV_VOLUME_IND |
                 BTAUD_EV_ATTACH_ABORT;
    
    memset(g_bcm_btaud_cntx, 0, sizeof(*g_bcm_btaud_cntx));

    srv_btaud_init();

    g_bcm_btaud_cntx->srv_hd = srv_btaud_open(BTAUD_LEVEL_ADMIN, BTAUD_CHNL_ANY);
    srv_btaud_set_notify(g_bcm_btaud_cntx->srv_hd, events,(BtAudNotify)bcm_btaud_notify_hdlr, NULL);
}

void bcm_btaud_deinit(void)
{
    srv_btaud_close(g_bcm_btaud_cntx->srv_hd);
    g_bcm_btaud_cntx->srv_hd = 0;
    srv_btaud_deinit();
}
#endif/*#ifdef __BT_HFG_PROFILE__*/

#ifdef __BT_HF_PROFILE__
void bcm_hf_init(void)
{
#ifdef __BT_HFG_PROFILE__
//
	//bcm_btaud_init();
#endif/*#ifdef __BT_HFG_PROFILE__*/
	bcm_ucm_cntx_init();
	bcm_btdialer_init();
}

void bcm_hf_deinit(void)
{
#ifdef __BT_HFG_PROFILE__
//	bcm_btaud_deinit();
#endif/*#ifdef __BT_HFG_PROFILE__*/
	bcm_btdialer_deinit();

}
#endif/*#ifdef __BT_HF_PROFILE__*/

#ifdef __BT_HFG_PROFILE__
void bcm_hfg_init(void)
{

	bcm_btaud_init();
}

void bcm_hfg_deinit(void)
{
	bcm_btaud_deinit();
}

void bcm_hfp_connect(srv_bt_cm_bt_addr bt_addr)
{
	srv_btaud_attach(g_bcm_btaud_cntx->srv_hd, &bt_addr);
	//srv_bt_dialer_send_connect_req
}

void bcm_hfp_disconnect(void)
{
	srv_btaud_detach(g_bcm_btaud_cntx->srv_hd);
	//srv_bt_dialer_send_disconnect_req
}

#endif/*#ifdef __BT_HFG_PROFILE__*/

#ifdef __BT_A2DP_PROFILE__
void bcm_a2dp_init(void)
{
	srv_a2dp_init();
}
void bcm_a2dp_connect(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_a2dp_src_cm_connect_req(bt_addr, NULL);
}

void bcm_a2dp_reconfig_start(srv_bt_cm_bt_addr *bt_addr,WCHAR * filename,U16 sample_rate,U8 stereo)
{
	S32 result=0;
	result=srv_a2dp_reconfig_start_streaming(bt_addr,filename,sample_rate,stereo,KAL_TRUE);

	if(result==SRV_A2DP_OPEN_FAILED)
	{	
		srv_a2dp_reconfig_start_cnf(KAL_FALSE);
	}
	else{
		srv_a2dp_reconfig_start_cnf(KAL_TRUE);
	}
}

void bcm_a2dp_pause()
{
	srv_a2dp_pause_stream();
	srv_a2dp_reconfig_start_cnf(KAL_TRUE);

}

void bcm_a2dp_disconnect(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_a2dp_cm_disconnect_req(bt_addr, NULL);
}

#endif

#ifdef __BT_AVRCP_PROFILE__

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 bcm_bt_avrcp_cmd_hdlr(U8 command, srv_avrcp_key_events key_events) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = SRV_AVRCP_CR_ACCEPT;
	bcm_avrcp_cmd_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_AVRCP_HDLR,command,key_events);
	kal_prompt_trace(MOD_BCM,"bcm_bt_avrcp_cmd_hdlr command:%x key_events:%d",command,key_events);
	ind = (bcm_avrcp_cmd_ind_struct*)construct_local_para(sizeof(bcm_avrcp_cmd_ind_struct), TD_RESET);
	ind->command = command;
	ind->key_events = key_events;
			
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_AVRCP_CMD_IND, ind, NULL);
	
	return result;
    
}

void bcm_avrcp_set_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func)
{
    srv_avrcp_set_cmd_hdlr((AVRCP_SRV_CMD_CALLBACK)callback_func);
}

void bcm_avrcp_init(void)
{
	srv_avrcp_init();	
    bcm_avrcp_set_cmd_hdlr(bcm_bt_avrcp_cmd_hdlr);
}

#endif

