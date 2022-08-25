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
 *   ft_fnc_bt.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Bluetooth Function
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__BT_SUPPORT__)

/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "task_config.h"
#ifdef MTK_TARGET
#include "app_buff_alloc.h"
#endif /* MTK_TARGET */
/*************************************************************************
* Include Statements for MAUI
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_bt.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "ps_public_enum.h" //for L4C_SETTING_DUAL_SIM_UART
#define MAX_PAK_SENT  5
kal_bool  ft_gl_bt_update_online= KAL_TRUE;  // default value: enable
/* for build warning */
extern kal_uint32 L1I_GetTimeStamp( void );
/*******************************************************************************
*
*  BT Operation
*
*******************************************************************************/
kal_uint16   ft_gl_bt_op;
kal_bool g_bol_ft_bt_period=KAL_FALSE;
kal_bool g_ft_bt_txtest=KAL_FALSE;
kal_bool g_ft_bt_rxtest=KAL_FALSE;
kal_uint32  g_RXstart_time=0;
kal_uint32  g_TXstart_time;//[MAX_PAK_SENT];//=0;
kal_uint32  g_TXend_time;//[MAX_PAK_SENT];//=0;
//kal_uint16    g_sentlgth=0;
kal_uint32  g_u4Recvlgth = 0;    // record the total length of packets that RX received
kal_uint32  g_u4RXnum = 0;      // record the callback is being called for RX throughput test
kal_uint32  g_u4TotalTime =0;  // record the total time in receiving packets
kal_uint16  g_TXnum=0;
extern kal_uint16   ft_gl_bt_period_token;
extern kal_uint16   ft_gl_bt_token;
static HciCommand     hciCommand;
//static HciMetaBuffer  hcibuf;
void  FT_BT_Operation(const FT_BT_REQ *req, peer_buff_struct *peer_buff_in)
{
    kal_uint8   sendstatus=0;
    kal_uint8   dummy_data[1021];  // maximum: 1021 bytes
    ilm_struct  *ilm_ptr;
    FT_BT_CNF   *ilm_cnf;
    switch(req->op)
    {
#ifdef __BTMTK__
        case FT_BT_OP_HCI_SEND_COMMAND:
        {
            //Meta_TxRxInit();
            if(req->cmd.hci.opcode == 3075) // HCI_Reset: 0x0C03
            {
                Custom_Meta_ResetHci();
            }
            Custom_Meta_RegisterHciEventHandler( Meta_InitEventHandler );
            kal_mem_cpy(hciCommand.parms, req->cmd.hci.cmd, req->cmd.hci.len);
            Custom_Meta_SendHciCommand(req->cmd.hci.opcode, req->cmd.hci.len, &hciCommand);
            if(req->cmd.hci.opcode==1028) //cancel periodic command
            {
                g_bol_ft_bt_period=KAL_FALSE;
            }
            if(req->cmd.hci.opcode==1027) //periodic command
            {
                g_bol_ft_bt_period=KAL_TRUE;
                ft_gl_bt_period_token=ft_gl_bt_token; //keep periodic command token
            }
            ft_gl_bt_op=req->op;
            break;
        }
        case FT_BT_OP_HCI_CLEAN_COMMAND:
        {
            Custom_Meta_CleanCommand();
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case FT_BT_OP_HCI_SEND_DATA:
        {
            Custom_Meta_RegisterHciEventHandler( Meta_InitEventHandler );
            kal_mem_cpy(dummy_data, req->cmd.buf.buffer,req->cmd.buf.len);
            sendstatus=Custom_Meta_SendHciData(req->cmd.buf.con_hdl, req->cmd.buf.len, dummy_data);//req->cmd.buf.buffer);
            if(sendstatus!=0)
            {
                if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                    return;
                }
                ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
                // assign primitive id
                ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
                // assign op
                ilm_cnf->op = req->op;
                //ilm_cnf->status = FT_CNF_OK;
                ilm_cnf->status = sendstatus;
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            }
            ft_gl_bt_op=req->op;
            break;
        }
        case FT_BT_OP_HCI_TX_PURE_TEST_V2:
        {
            kal_uint32 end_time;
            kal_uint16 pkt_sent, prev_pkt_sent;
            kal_uint8  err_times;
            g_ft_bt_txtest=KAL_TRUE;
            g_TXstart_time = L1I_GetTimeStamp();  // record the start time
            g_TXnum = req->cmd.txpuretest.total_pks; // remember the total packets has to be sent
            // ask BT start to do throughput test
            sendstatus = Custom_Meta_StartTxPureTest(req->cmd.txpuretest.con_hdl, req->cmd.txpuretest.len, req->cmd.txpuretest.total_pks);
            if(sendstatus!=0)
            {
                if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                    return;
                }
                ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
                // assign primitive id
                ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
                // assign op
                ilm_cnf->op = req->op;
                //ilm_cnf->status = FT_CNF_OK;
                ilm_cnf->status = sendstatus;
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                break;
            }
            // txstat_v2
            pkt_sent = 0;
            prev_pkt_sent = 0;
            err_times = 0;
            while(1)
            {
                kal_sleep_task(50);
                //query current pkt sent number
                pkt_sent = Custom_Meta_QueryTxPureTest();
                end_time = L1I_GetTimeStamp();
                //check if we should stop querying
                //don't send the last message and wait for the callback for HCI_META_PKT_SENT_OUT
                if(pkt_sent == req->cmd.txpuretest.total_pks)
                    break;
                if(pkt_sent == prev_pkt_sent)
                    err_times++;
                // sent to PC side
                if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                    return;
                }
                ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
                // assign primitive id
                ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
                // assign op
                ilm_cnf->op = req->op;
                if(err_times == 5) // stop querying and send error CNF to PC side
                {
                    //ilm_cnf->status = FT_CNF_OK;
                    ilm_cnf->status = FT_CNF_FAIL;
                    //prepare the result
                    ilm_cnf->result.txstat_v2.used_time = 0;
                    ilm_cnf->result.txstat_v2.sent_num = 0;
                    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                    break;
                }
                //ilm_cnf->status = FT_CNF_OK;
                ilm_cnf->status = sendstatus;
                //prepare the result
                ilm_cnf->result.txstat_v2.used_time = (end_time - g_TXstart_time)*4.615;
                ilm_cnf->result.txstat_v2.sent_num = pkt_sent;
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                prev_pkt_sent = pkt_sent;
                kal_sleep_task(50);
            }
            g_ft_bt_txtest=KAL_FALSE;
            break;
        }
        case FT_BT_OP_HCI_TX_PURE_TEST:
        {
            // directly send error CNF to PC side, to let it know we don't support anymore
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) return;
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            // assign primitive id
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            // assign op
            ilm_cnf->op = req->op;
            //ilm_cnf->status = FT_CNF_OK;
            ilm_cnf->status = FT_CNF_FAIL;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case FT_BT_OP_HCI_RX_TEST_START_V2:
        {
            kal_uint32 msg_num;
            kal_uint8  no_update;
            kal_uint32  u4PrevTotalRecvLen;  // record the last time
            kal_uint32  u4PrevTotalTime;
            g_ft_bt_rxtest = KAL_TRUE;
            g_RXstart_time = 0; // reset the timestamp
            g_u4Recvlgth = 0 ; // reset the receive packet length
            g_u4RXnum = 0 ; // reset the number of times that the callback is being called
            g_u4TotalTime = 10;  // reset the number, in case there is only one packet
            u4PrevTotalRecvLen = 0;
            u4PrevTotalTime = 0;
            no_update = 0;
            while(1)
            {
                msg_get_ext_queue_info(task_info_g[INDX_FT].task_ext_qid, &msg_num);
                if(msg_num >0)  // another message is waiting for processing, so stop the while loop
                {
                    if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                        return;
                    }
                    ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
                    ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
                    ilm_cnf->op = req->op;
                    ilm_cnf->status = FT_CNF_OK;
                    ilm_cnf->eventtype = 254;
                    ilm_cnf->result.rxstat_v2.used_time=0;
                    ilm_cnf->result.rxstat_v2.len= 0;
                    ilm_cnf->result.rxstat_v2.stop_flag= 2;
                    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                    break;
                }
                kal_sleep_task(100); // sleep for a while
                if(g_u4Recvlgth !=0) // means we start to receive the packet
                {
                    if(g_u4Recvlgth - u4PrevTotalRecvLen ==0) // means the same
                    {
                        no_update++;
                    }
                    else // different, so send the CNF back to PC side
                    {
                        no_update = 0; // reset the flag
                        if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                            return;
                        }
                        ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
                        ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
                        ilm_cnf->op = req->op;
                        ilm_cnf->status = FT_CNF_OK;
                        ilm_cnf->eventtype = 254;
                        ilm_cnf->result.rxstat_v2.used_time=(g_u4TotalTime - u4PrevTotalTime)*4.615;
                        ilm_cnf->result.rxstat_v2.len= g_u4Recvlgth - u4PrevTotalRecvLen;
                        u4PrevTotalRecvLen = g_u4Recvlgth;
                        u4PrevTotalTime = g_u4TotalTime;
                        ilm_cnf->result.rxstat_v2.stop_flag= 0;
                        FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                    }
                }
                // check if the BT stacks stops to receiving
                if(no_update == 4) // send the CNF to notify that we already recv all
                {
                    if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                        return;
                    }
                    ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
                    ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
                    ilm_cnf->op = req->op;
                    ilm_cnf->status = FT_CNF_OK;
                    ilm_cnf->eventtype = 254;
                    ilm_cnf->result.rxstat_v2.used_time=0;
                    ilm_cnf->result.rxstat_v2.len= 0;
                    ilm_cnf->result.rxstat_v2.stop_flag= 1;
                    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                    break;
                }
            }
            g_ft_bt_rxtest = KAL_FALSE;
            // jump out the loop, so we should make g_ft_bt_rx_test = KAL_FALSE;
            break;
        }
        case FT_BT_OP_HCI_RX_TEST_START:
        {
            g_ft_bt_rxtest=KAL_TRUE;
            g_RXstart_time = 0 ; // because we can not get the time for the first time receiving, added by Shu-Min
            //ft_gl_bt_op=req->op;
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case FT_BT_OP_HCI_RX_TEST_END:
        {
            g_ft_bt_rxtest=KAL_FALSE;
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case FT_BT_OP_ENABLE_NVRAM_ONLINE_UPDATE:
        case FT_BT_OP_DISABLE_NVRAM_ONLINE_UPDATE:
        {
            ft_gl_bt_update_online = (req->op==FT_BT_OP_ENABLE_NVRAM_ONLINE_UPDATE)? true:false;
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#ifndef __BTMODULE_MT6601__
        case FT_BT_OP_ENABLE_PCM_CLK_SYNC_SIGNAL:
        {
            uint16 m_para[NUM_MODE_PARAS];
            kal_mem_set(m_para,0x0, sizeof(m_para));
            L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para); // set to BT earphone mode
            KT_Play(0, 0, 0); // freq = 0, continuous playing
            // send cnf to PC side
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case FT_BT_OP_DISABLE_PCM_CLK_SYNC_SIGNAL:
        {
            uint16 m_para[NUM_MODE_PARAS];
            kal_mem_set(m_para,0x0, sizeof(m_para));
            KT_Stop();
            L1SP_SetSpeechMode(SPH_MODE_NORMAL, m_para); // set to normal mode
            // send cnf to PC side
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // end of #ifndef __BTMODULE_MT6601__
        case FT_BT_OP_POWER_ON_EX:
        case FT_BT_OP_POWER_ON_EX2:
        {
            kal_uint8 uart_settings = 0;
            kal_uint8 bt_check_times= 0;
            kal_uint8 wait_flag = 0;
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) )  return;
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID;
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
#ifdef __GEMINI__
            uart_settings = ft_query_dual_sim_uart_settings();
#endif // #ifdef __GEMINI__
            /**
             * extra power on sequence decision for non-signaling RX support to bypass original patch
             * special path is needed for MT6622 to do Non-signaling RX test
             */
            if(req->op == FT_BT_OP_POWER_ON_EX2)
            {
                /* META Non_Signaling RX support */
                if(req->cmd.poweron_ex2.hci.opcode == 0x4E52)
                {
                    BtRadio_Set_MT6622_META_NSR_Support(0x01);
                }
                else
                {
                    BtRadio_Set_MT6622_META_NSR_Support(0x00);
                }
                /* update wait flag */
                wait_flag = req->cmd.poweron_ex2.m_u1Flag;
            }
            else if(req->op == FT_BT_OP_POWER_ON_EX)
            {
                /* update wait flag */
                wait_flag = req->cmd.m_u1Flag;
            }
            Custom_BTPowerOn(uart_settings);
            if(wait_flag == 1)
            {
                ilm_cnf->status = FT_CNF_FAIL;
                while(1)
                {
                    if(Custom_BTQueryPowerOnState())  // BT really power on
                    {
                        ilm_cnf->status = FT_CNF_OK;
                        break;
                    }
                    if(bt_check_times ==10)  break;
                    kal_sleep_task(150);  // 1 implies sleep 4.6 ms //
                    bt_check_times ++;
                }
            }
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case FT_BT_OP_POWER_OFF_EX:
        {
            kal_uint8 bt_check_times=0;
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) )  return;
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            ilm_cnf->op = req->op;
            ilm_cnf->status = FT_CNF_OK;
            Custom_BTPowerOff();
            if(req->cmd.m_u1Flag == 1)
            {
                ilm_cnf->status = FT_CNF_FAIL;
                while(1)
                {
                    if(!Custom_BTQueryPowerOnState()) // BT really power OFF
                    {
                        ilm_cnf->status = FT_CNF_OK;
                        break;
                    }
                    if(bt_check_times ==10)  break;
                    kal_sleep_task(150);  // 1 implies sleep 4.6 ms //
                    bt_check_times ++;
                }
            }
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // __BTMTK__
        default:
            // unknown op
            // allocate confirm primitive
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            // assign primitive id
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
            // assign op
            ilm_cnf->op = req->op;
            //ilm_cnf->status = FT_CNF_OK;
            ilm_cnf->status = FT_CNF_FAIL;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
    }
}
#ifdef __BTMTK__
void Meta_InitEventHandler(U8 Event, HciCallbackParms *parms)
{
    kal_uint32  end_time=0;
    if(Event==HCI_CONTROLLER_EVENT)
    {
        kal_uint32 hcievent_start_address = 0;
        kal_uint32 hcievent_end_address   = 0;
        // assign return status
        ilm_struct  *ilm_ptr;
        FT_BT_CNF *ilm_cnf;
        if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
            return;
        }
        /* get the size of the hcievent response */
        hcievent_start_address = (kal_uint32)&(( (FT_BT_CNF*)(ilm_ptr->local_para_ptr) )->header );
        hcievent_end_address   = (kal_uint32)&(( (FT_BT_CNF*)(ilm_ptr->local_para_ptr) )->result.hcievent.parms[256] );
        /* re-allocate local parameter */
        free_local_para(ilm_ptr->local_para_ptr);
        ilm_ptr->local_para_ptr = construct_local_para((hcievent_end_address - hcievent_start_address), TD_RESET);
        if(ilm_ptr->local_para_ptr == NULL)
        {
            return;
        }
        ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
        // assign primitive id
        ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID;
        // assign op
        ilm_cnf->op = (FT_BT_OP)ft_gl_bt_op;
        ilm_cnf->eventtype = Event;
        ilm_cnf->result.hcievent.status = parms->status;
        if( BT_STATUS_SUCCESS == parms->status ) {
            ilm_cnf->status = FT_CNF_OK;
        }
        else {
            ilm_cnf->status = FT_CNF_FAIL;
        }
        ilm_cnf->result.hcievent.event = parms->ptr.hciEvent->event;
        ilm_cnf->result.hcievent.len=parms->ptr.hciEvent->len;
        kal_mem_cpy(ilm_cnf->result.hcievent.parms, parms->ptr.hciEvent->parms, parms->ptr.hciEvent->len);
        if( g_bol_ft_bt_period)
        {
            if(ilm_cnf->result.hcievent.event==1||ilm_cnf->result.hcievent.event==2||
                    (ilm_cnf->result.hcievent.event==14&&ilm_cnf->result.hcievent.parms[1]==3&&ilm_cnf->result.hcievent.parms[2]==4
                    ))//3,4 mean periodic command
            {
                _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, ft_gl_bt_period_token);
            }
            else //while periodic command, send another command
            {
                _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, ft_gl_bt_token);
            }
        }
        else
        {
            _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, ft_gl_bt_token);
        }
    }
    else if(Event==HCI_DATA_IND)
    {
        ilm_struct  *ilm_ptr;
        FT_BT_CNF *ilm_cnf;
        if (g_ft_bt_rxtest==FALSE)//Don't Send DATA CNF while g_ft_bt_rxtest is true
        {
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            // assign primitive id
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID;
            // assign op
            ilm_cnf->op = (FT_BT_OP)ft_gl_bt_op;
            ilm_cnf->status = FT_CNF_OK;
            ilm_cnf->eventtype = Event;
            ilm_cnf->result.hcibuffer.con_hdl=parms->ptr.rxMetaBuff->con_hdl;
            ilm_cnf->result.hcibuffer.len=parms->ptr.rxMetaBuff->len;
            kal_mem_cpy(ilm_cnf->result.hcibuffer.buffer, parms->ptr.rxMetaBuff->buffer, parms->ptr.rxMetaBuff->len);
            _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, ft_gl_bt_token);
        }
        else  // for RX throughput test
        {
            g_u4RXnum++;   // record how many times the callback is being called
            g_u4Recvlgth = g_u4Recvlgth + parms->ptr.rxMetaBuff->len;   // calculate the total length
            end_time = L1I_GetTimeStamp();//g_TXstart_time[0] = L1I_GetTimeStamp(); // record the 2nd packet
            if(g_u4RXnum == 1) g_u4TotalTime = 10;
            else g_u4TotalTime = g_u4TotalTime + (end_time - g_RXstart_time);
            g_RXstart_time = end_time;
        }
    }
    else if(Event==HCI_PACKET_HANDLED)
    {
        if (g_ft_bt_txtest==FALSE)//Don't Send DATA CNF while g_ft_bt_txtest is true
        {
            ilm_struct  *ilm_ptr;
            FT_BT_CNF *ilm_cnf;
            if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
                return;
            }
            ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
            // assign primitive id
            ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID;
            // assign op
            ilm_cnf->op = (FT_BT_OP)ft_gl_bt_op;
            ilm_cnf->eventtype = Event;
            if( BT_STATUS_SUCCESS == parms->status ) {
                ilm_cnf->status = FT_CNF_OK;
            }
            else {
                ilm_cnf->status = FT_CNF_FAIL;
            }
            ilm_cnf->result.hcipacket.len=parms->ptr.packet->dataLen;
            kal_mem_cpy(ilm_cnf->result.hcipacket.data, parms->ptr.packet->data, parms->ptr.packet->dataLen);
            _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, ft_gl_bt_token);
        }
    }
    else if (Event == HCI_META_PKT_SENT_OUT)  // this is for TX throughput test, modified for FT_BT_OP_HCI_TX_PURE_TEST_V2
    {
        ilm_struct  *ilm_ptr;
        FT_BT_CNF *ilm_cnf;
        g_TXend_time = L1I_GetTimeStamp();
        if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_BT_CNF))) ) {
            return;
        }
        ilm_cnf = (FT_BT_CNF *)ilm_ptr->local_para_ptr;
        // assign primitive id
        ilm_cnf->header.ft_msg_id = FT_BT_CNF_ID; //remember to add FT_BT_CNF_ID to ft_msg
        // assign op
        ilm_cnf->op = FT_BT_OP_HCI_TX_PURE_TEST_V2;
        ilm_cnf->status = FT_CNF_OK;
        ilm_cnf->eventtype = HCI_META_PKT_SENT_OUT;
        ilm_cnf->result.txstat_v2.used_time = (g_TXend_time - g_TXstart_time)*4.615;
        ilm_cnf->result.txstat_v2.sent_num = g_TXnum;
        FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
    }
}
#endif // #ifdef __BTMTK__
///////

#ifdef __BTMTK__
#ifdef __GEMINI__
kal_uint8 ft_query_dual_sim_uart_settings(void)
{
    kal_uint8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    kal_bool status = KAL_FALSE;
    status = nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID,
            NVRAM_SYS_FLIGHTMODE_STATE,
            buffer,
            NVRAM_EF_SYS_CACHE_OCTET_SIZE);
    sprintf((kal_char *)g_FT_debug_buf,"uart_settings:%d", buffer[L4C_SETTING_DUAL_SIM_UART]);
    tst_sys_trace(g_FT_debug_buf);
    if (status == KAL_TRUE)
        return buffer[L4C_SETTING_DUAL_SIM_UART];
    else
        return 0;
}

#endif  //__GEMINI__
#endif  // __BTMTK__
#endif  // #if defined(__BT_SUPPORT__)
