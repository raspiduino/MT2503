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
 * BtcmSrvPrmt.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MTK bluetooth primitive handle with BT stack
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
 *
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
#ifdef __BCM_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "Bcm_btcmSrvProt.h"
#include "Bcm_btcmSrvGprot.h"
#include "bcm_trc.h"
#include "bluetooth_bm_struct.h"


#ifdef __MMI_HFP_SUPPORT__
#include "bcm_BthfSrvGprot.h" 
#endif

#ifdef __SUPPORT_JBT__
#include "mmiapi_bt_struct.h"
#include "BTMMIBccGprots.h"
#endif

#ifndef __EMPTY_MMI__
#ifdef __GEMINI__
#include "PhoneSetupGprots.h"
#endif
#endif /* __EMPTY_MMI__ */

// #ifdef __DM_LAWMO_SUPPORT__
// #include "dmuigprot.h"
// #endif /*__DM_LAWMO_SUPPORT__*/

#include "conversions.h"
#include "bluetooth_struct.h"

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif

// RHR: add
#include "app_ltlcom.h"
#include "l4c_common_enum.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_general_types.h"
//#include "TimerEvents.h"
#include "kal_public_api.h"
// RHR: add

#ifdef __MMI_BT_SIMPLE_PAIR__
static void srv_bt_cm_security_keypress_notify_rsp_hdler(void);
#endif

#define BT_CM_PASSKEY_IND_HDLER       0
#define BT_CM_SECURITY_USER_CONFIRM   1
#define BT_CM_SECURITY_PASSKEY_NOTIFY 2

static void srv_bt_cm_key_ind_state_change(int,void*);
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_on_req_hdler
 * DESCRIPTION
 *  This function is to handle antenna on req, it sends MSG_ID_BT_POWERON_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_antenna_on_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifndef __EMPTY_MMI__
#ifdef __GEMINI__
    bt_poweron_req_struct* msg_p;
    U8 uart = (U8)srv_setting_get_uart_setting();

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ANTENNA_ON_REQ_HDLER,
        uart);
    if (uart == 0xff)
    {
        uart = 0;
    }

    msg_p = (bt_poweron_req_struct*)construct_local_para(
        sizeof(bt_poweron_req_struct),
        TD_CTRL);

    msg_p->dual_sim_uart_setting = uart;

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWERON_REQ, (void*)msg_p, NULL);
#else
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWERON_REQ, NULL, NULL);

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ANTENNA_ON_REQ_HDLER_2);

#endif /* __GEMINI__ */

#else
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWERON_REQ, NULL, NULL);

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ANTENNA_ON_REQ_HDLER_2);

#endif /* __EMPTY_MMI__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_on_rsp_hdler
 * DESCRIPTION
 *  This function is to handle antenna on cnf, it just reset SRV_BT_CM_RAMMASK_IS_READY
 * PARAMETERS
 *  msg         [IN]        inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_antenna_on_rsp_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ANTENNA_ON_RSP_HDLER);

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	srv_bt_cm_write_scanenable_mode_req_hdler((U8)BTBM_ADP_P_OFF_I_OFF);
	SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING_WRITE_SCAN_DISABLE);
	
	/* to ask BM(bluetooth management) to send link connect accept ind to MMI */
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_NOT_AUTO_REQ, NULL, NULL);


    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_off_req_hdler
 * DESCRIPTION
 *  This function is to handle antenna off request, it sends MSG_ID_BT_POWEROFF_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_antenna_off_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWEROFF_REQ, NULL, NULL);
    /* deal with the response at srv_bt_cm_antenna_off_rsp_hdler() */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_off_rsp_hdler
 * DESCRIPTION
 *  This function is to handler antenna off response
 *      1. reset SRV_BT_CM_RAMMASK_IS_READY
 *      2. invoke mmi_bt_scr_cb_deactivate callback function
 * PARAMETERS
 *  msg         [IN]        inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_antenna_off_rsp_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset bt ready mask */
#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (!SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_POWER_OFF_TIME_OUT))
    {
        StopTimer(BT_POWER_OFF_GUARD_TIMER);
    }

    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_POST_DEACTIVATING);
    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_READY);
    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
    SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
    srv_bt_cm_nvram_write_info(NVRAM_EF_BT_INFO_LID, (void*)0);

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ANTENNA_OFF_RSP_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_POWER_ON_TIME_OUT))
    {
        srv_bt_cm_activate_struct para1;

        SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_POWER_ON_TIME_OUT);
        para1.result = MMI_FALSE;
        srv_bt_cm_notify(SRV_BT_CM_EVENT_ACTIVATE, (void*)&para1);
    }
    else
    {
        srv_bt_cm_deactivate_struct para2;

        para2.result = MMI_TRUE;
        srv_bt_cm_notify(SRV_BT_CM_EVENT_DEACTIVATE, (void*)&para2);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_ready_ind_hdler
 * DESCRIPTION
 *  This function is to handler ready indication
 *      1. state transistion
 *      2. send MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_NOT_AUTO_REQ
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
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
#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
 *  srv_bt_cm_restart_req_ind_hdler
 * DESCRIPTION
 *  This function is to handle restart request indication, it invokes mmi_bt_scr_cb_panic_ind callback
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_restart_req_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_panic_ind_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* notify UI layer to re-init bt content */
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RESTART_REQ_IND_HDLER);

    srv_bt_cm_notify(SRV_BT_CM_EVENT_PANIC_IND, (void*)&para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_restart_rsp_hdler
 * DESCRIPTION
 *  This function is to handle restart response, send antenna on req to SRV_BT_CM
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_restart_rsp_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send antenna on req to BTH */
    /* while bt core reset, bt core will power on bt again */

    /* if it's requested by LAWMO reset, set IS_READY flag, and reset DM reset flag*/
#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RESTART_RSP_HDLER);

#ifdef __DM_LAWMO_SUPPORT__
    if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_DM_RESET))
    {
        SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_DM_RESET);
        if (g_srv_bt_cm_cntx.lawmo_lock_cb)
        {
            g_srv_bt_cm_cntx.lawmo_lock_cb(MMI_TRUE, "Bluetooth");
            g_srv_bt_cm_cntx.lawmo_lock_cb = NULL;
        }

        return;
    }
#endif /*__DM_LAWMO_SUPPORT__*/

    if (srv_bt_cm_is_activated())
    {
        srv_bt_cm_antenna_on_req_hdler();
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING);
        SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING);
    }
    else
    {
        srv_bt_cm_antenna_off_req_hdler();
    }
}


static void srv_bt_cm_dev_update_name(const srv_bt_cm_bt_addr* dev_addr, const U8* dev_name, U32 name_len)
{
    U32 i;

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_UPDATE_NAME,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_name);

    if (dev_name)
    {
        i = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_ALL_DEV);
        if (i < SRV_BT_CM_MAX_DEVICE_LIST)
        {
            if ((g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute &
                 SRV_BT_CM_DEVICE_ATTRIBUTE_USER_DEFINED_NAME) == 0)
            {
                srv_bt_cm_copy_n_utf8_chars(
                    g_srv_bt_cm_cntx.dev_list[i].dev_info.name,
                    SRV_BT_CM_BD_FNAME_LEN,
                    (U8*)dev_name,
                    name_len);
            }
        }
    }
}

static void srv_bt_cm_add_devname_addr( btbm_bd_addr_t bd_addr,kal_uint8 name[BTBM_ADP_MAX_NAME_LEN], kal_uint8 name_len, kal_uint8 name_req_result)
{
	U32 i;
        name_len = name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
        (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
        name_len;
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&bd_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        if ((srv_bt_cm_get_state() != SRV_BT_CM_STATE_BONDING) && (name_req_result != 0))
        {
            srv_bt_cm_dev_update_name((srv_bt_cm_bt_addr*)&bd_addr, (U8*)name, name_len);
        }
        memcpy(
            &g_srv_bt_cm_cntx.temp_dev,
            &g_srv_bt_cm_cntx.dev_list[i].dev_info,
            sizeof(srv_bt_cm_dev_struct));
    }
    else
    {
        const srv_bt_cm_dev_struct* dev_info_p = srv_bt_cm_get_dev_info_by_addr(
            (const srv_bt_cm_bt_addr*)&(bd_addr),
            SRV_BT_CM_ALL_DEV);
        if (dev_info_p)
        {
            g_srv_bt_cm_cntx.temp_dev.cod = dev_info_p->cod;
        }
		srv_bt_cm_copy_addr((void *)&(g_srv_bt_cm_cntx.temp_dev.bd_addr),(void *) &bd_addr);
        if ((srv_bt_cm_get_state() != SRV_BT_CM_STATE_BONDING) && (name_req_result != 0))
        {
            srv_bt_cm_copy_n_utf8_chars(
                g_srv_bt_cm_cntx.temp_dev.name,
                SRV_BT_CM_BD_FNAME_LEN,
                name,
                name_len);
        }
        else if (dev_info_p)
        {
            srv_bt_cm_copy_n_utf8_chars(
                g_srv_bt_cm_cntx.temp_dev.name,
                SRV_BT_CM_BD_FNAME_LEN,
                (U8*)dev_info_p->name,
                SRV_BT_CM_BD_FNAME_LEN);
        }
    }
    srv_bt_cm_dev_add_int((const srv_bt_cm_dev_struct*)&g_srv_bt_cm_cntx.temp_dev, SRV_BT_CM_RECENT_USED_DEV);

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_req_hdler
 * DESCRIPTION
 *  This function is to handle CM discovery request, it sends MSG_ID_BT_BM_DISCOVERY_REQ
 * PARAMETERS
 *  max_response        [IN]            max discovery result in response
 *  timeout             [IN]                the discovery timeout timer
 *  cod                 [IN]                  class of device
 *  name_discovery      [IN]            whether to do name discovery or not
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_discovery_req_hdler(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_discovery_req_struct*)construct_local_para(
        sizeof(bt_bm_discovery_req_struct),
        TD_CTRL);
    msg_p->cod = cod;
    msg_p->inquiry_length = ((timeout * 1000) / 1280);
    msg_p->inquiry_number = max_response;
    msg_p->access_mode = BTBM_GENERAL_INQUIRY;
    if (name_discovery)
    {
        msg_p->discovery_mode = BTBM_DISCOVERY_WITH_NAME;
    }
    else
    {
        msg_p->discovery_mode = BTBM_DISCOVERY_WITHOUT_NAME;
    }

	msg_p->discovery_type = BTBM_DISCOVERY_BR_EDR_ONLY;

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DISCOVERY_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_result_ind_hdler
 * DESCRIPTION
 *  This function is to handle discovery result indication and to process found device
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_discovery_result_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U32 j, name_len;
    bt_bm_discovery_result_ind_struct* msg_p = (bt_bm_discovery_result_ind_struct*)msg;
    srv_bt_cm_inquiry_indication_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DISCOVERY_RESULT_IND_HDLER,
        msg_p->cod,
        ((msg_p->bd_addr.nap & 0xff00) >> 8),
        (msg_p->bd_addr.nap & 0x00ff),
        (msg_p->bd_addr.uap),
        ((msg_p->bd_addr.lap & 0xff0000) >> 16),
        ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
        (msg_p->bd_addr.lap & 0x0000ff),
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    if ((g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIRING) && 
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIR_RES_IND))
    {
        return;
    }
	if( msg_p->device_type ==BTBM_DEVICE_TYPE_LE )
		return ;

    if (srv_bt_cm_get_dev_info_by_addr((srv_bt_cm_bt_addr*)(&msg_p->bd_addr), SRV_BT_CM_DISCOVERED_DEV))
    {
        return;
    }
	if(msg_p->name_len == 0)
	{
	    return;
	}
    name_len = msg_p->name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
        (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
        msg_p->name_len;
    srv_bt_cm_dev_update_name((srv_bt_cm_bt_addr*)&msg_p->bd_addr, (U8*)msg_p->name, name_len);
    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_INQUIR_RES_IND);

    /* Process Found Device */
    i = g_srv_bt_cm_cntx.discovered_dev_num;
    if (i < SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST)
    {
        g_srv_bt_cm_cntx.discovered_list[i].cod = msg_p->cod;
		srv_bt_cm_copy_addr(&g_srv_bt_cm_cntx.discovered_list[i].bd_addr,(srv_bt_cm_bt_addr*)&msg_p->bd_addr);

        j = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV);
        if (j < SRV_BT_CM_MAX_DEVICE_LIST)
        {
            memcpy(
                g_srv_bt_cm_cntx.discovered_list[i].name,
                g_srv_bt_cm_cntx.dev_list[j].dev_info.name,
                SRV_BT_CM_BD_FNAME_LEN);
        }
        else
        {
            srv_bt_cm_copy_n_utf8_chars(
                g_srv_bt_cm_cntx.discovered_list[i].name,
                SRV_BT_CM_BD_FNAME_LEN,
                msg_p->name,
                name_len);
        }

        g_srv_bt_cm_cntx.discovered_dev_num++;
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_INCREASE_DISCOVERED_DEV_NUM,
            g_srv_bt_cm_cntx.discovered_dev_num);
        MMI_BT_ASSERT(g_srv_bt_cm_cntx.discovered_dev_num <= SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST);

        para.discovered_dev_num = g_srv_bt_cm_cntx.discovered_dev_num;
        srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_IND, (void*)&para);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_update_ind_hdler
 * DESCRIPTION
 *  This function is to handle discovery update indication and to process found device
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/

void srv_bt_cm_discovery_update_ind_hdler(void* msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i = 0;
	U32 j, name_len;
	bt_bm_discovery_result_ind_struct* msg_p = (bt_bm_discovery_result_ind_struct*)msg;
	srv_bt_cm_inquiry_indication_struct para;
	const srv_bt_cm_dev_struct* discover_dev = srv_bt_cm_get_dev_info_by_addr((srv_bt_cm_bt_addr*)(&msg_p->bd_addr), SRV_BT_CM_DISCOVERED_DEV);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BT_CM_DISCOVERY_RESULT_IND_HDLER,
		msg_p->cod,
		((msg_p->bd_addr.nap & 0xff00) >> 8),
		(msg_p->bd_addr.nap & 0x00ff),
		(msg_p->bd_addr.uap),
		((msg_p->bd_addr.lap & 0xff0000) >> 16),
		((msg_p->bd_addr.lap & 0x00ff00) >> 8),
		(msg_p->bd_addr.lap & 0x0000ff),
		g_srv_bt_cm_cntx.state,
		g_srv_bt_cm_cntx.flag,
		g_srv_bt_cm_cntx.ram_flag,
		g_srv_bt_cm_cntx.deactivate_flag);

	if ((g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIRING) && 
		(g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIR_RES_IND))
	{
		return;
	}
	if( msg_p->device_type ==BTBM_DEVICE_TYPE_LE )
		return ;
	
	if (discover_dev)
	{
		name_len = msg_p->name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
			(SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
			msg_p->name_len;
		srv_bt_cm_dev_update_name((srv_bt_cm_bt_addr*)&msg_p->bd_addr, (U8*)msg_p->name, name_len);
		
		i = srv_bt_cm_get_dev_index((srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_DISCOVERED_DEV);
		if (i == 0xFFFFFFFF)
		{
			return;
		}
		srv_bt_cm_copy_n_utf8_chars(g_srv_bt_cm_cntx.discovered_list[i].name,
								SRV_BT_CM_BD_FNAME_LEN,	msg_p->name, name_len);		
	}

	SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_INQUIR_RES_IND);

	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BT_CM_INCREASE_DISCOVERED_DEV_NUM,
		g_srv_bt_cm_cntx.discovered_dev_num);
	MMI_BT_ASSERT(g_srv_bt_cm_cntx.discovered_dev_num <= SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST);

	para.discovered_dev_num = g_srv_bt_cm_cntx.discovered_dev_num;
	srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_IND, (void*)&para);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to handler discovery confirm and invoke mmi_bt_scr_cb_inquiry_cfm callback
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_discovery_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_cnf_struct* msg_p = (bt_bm_discovery_cnf_struct*)msg;
    srv_bt_cm_inquiry_complete_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DISCOVERY_CNF_HDLER);

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_BONDING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            srv_bt_cm_bond((U32)srv_bt_cm_get_action_item_index());
	    case SRV_BT_CM_STATE_INQUIR_CANCELLING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            para.result = msg_p->result;
            para.is_cancelled = MMI_TRUE;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_COMPLETE, (void*)&para);
            break;

        case SRV_BT_CM_STATE_DEACTIVATING:
            break;
        default:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                if(msg_p->total_number == g_srv_bt_cm_cntx.discovered_dev_num)
                {
                    para.result = BTBM_ADP_SUCCESS;
                }
                else
                {
                    para.result = BTBM_ADP_FAILED;
                }
            }
            else
            {
                para.result = msg_p->result;
            }

            para.is_cancelled = MMI_FALSE;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_COMPLETE, (void*)&para);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_cancel_discovery_req_hdler
 * DESCRIPTION
 *  This function is to handle cancel discovery request, it sends MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_cancel_discovery_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ, (void*)NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_cancel_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to handle cancel discovery confirm and invoke mmi_bt_scr_cb_inquiry_cancel callback
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_cancel_discovery_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_cancel_cnf_struct* msg_p = (bt_bm_discovery_cancel_cnf_struct*)msg;
    srv_bt_cm_inquiry_complete_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_CANCEL_DISCOVERY_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    switch (g_srv_bt_cm_cntx.state)
    {

        case SRV_BT_CM_STATE_BONDING:
            /* do nothing */
            /* if current state is bonding, shall not update bth state */
            /* the cancel-discovery cfm is coming because mmi will send cancel disconvery req before bonding */
            /* so it shall be in bonding state now */
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            srv_bt_cm_bond((U32)srv_bt_cm_get_action_item_index());
            break;

#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        case SRV_BT_CM_STATE_DEACTIVATING:
            /* do nothing*/
            /* this case will happen when it's under auto power on */
            /* when it's in discovery, and user press end key */
            break;
#endif /*__MMI_BT_AUTO_POWER_SWITCH__*/

        default:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            break;
    }

    para.result = msg_p->result;
    para.is_cancelled = MMI_TRUE;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_COMPLETE, (void*)&para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_local_name_req_hdler
 * DESCRIPTION
 *  This function is to handle set locak name request and send MSG_ID_BT_BM_WRITE_LOCAL_NAME_REQ
 * PARAMETERS
 *  name_len        [IN]            name length
 *  name            [IN]             name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_local_name_req_hdler(U8 name_len, U8* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_local_name_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_write_local_name_req_struct*)construct_local_para(
        sizeof(bt_bm_write_local_name_req_struct),
        TD_CTRL);
    msg_p->name_len = name_len;

    if (name_len > BTBM_ADP_MAX_NAME_LEN - 1)
    {
        msg_p->name_len = BTBM_ADP_MAX_NAME_LEN - 1;
        name[BTBM_ADP_MAX_NAME_LEN] = '\0';
    }

    memcpy(msg_p->name, name, msg_p->name_len + 1);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_WRITE_LOCAL_NAME_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_local_name_cnf_hdler
 * DESCRIPTION
 *  This function is to handle set local name confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_local_name_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U32 name_len = 0;
    bt_bm_write_local_name_cnf_struct* msg_p = (bt_bm_write_local_name_cnf_struct*)msg;
    srv_bt_cm_set_name_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_LOCAL_NAME_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag);

    result = (msg_p->result == BTBM_ADP_SUCCESS) ? MMI_TRUE : MMI_FALSE;
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_ACTIVATING:
            /* antenna on req->disable write scan enable(page off, inquiry off) */
            /* ->read BT address->set local name->set security->activate profiles */
            /* ->enable write scan mode */
            /* set security level */
            srv_bt_cm_security_level_req_hdler((MMI_BOOL)SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_AUTH));
            break;

        case SRV_BT_CM_STATE_HOST_NAME_SETTING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            if (result)
            {
                name_len = strlen((const char*)g_srv_bt_cm_cntx.host_name_setting);
                memcpy(
                    g_srv_bt_cm_cntx.host_dev.name,
                    g_srv_bt_cm_cntx.host_name_setting,
                    name_len + 2);
                if (g_srv_bt_cm_cntx.host_name_setting)
                {
                    OslMfree(g_srv_bt_cm_cntx.host_name_setting);
                    g_srv_bt_cm_cntx.host_name_setting = NULL;
                }

                srv_bt_cm_nvram_write_info(NVRAM_EF_BT_SYS_INFO_LID, (void*)0);
            }

#ifdef __SUPPORT_JBT__
            {
                mmi_bth_bcc_set_host_device_name_cb_struct param;

                param.result = result ? mmi_bt_bcc_result_succeeded : mmi_bt_bcc_result_failed;
                if (g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME].cb_func_ptr)
                {
                    g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME].cb_func_ptr((void*)&param);
                }
            }
#endif /*__SUPPORT_JBT__*/

            para.result = (U32)msg_p->result;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_NAME, (void*)&para);
            break;
    }

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_op11_hs32_cnx_bt_update();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_local_bd_addr_req_hdler
 * DESCRIPTION
 *  This function is to handle read local bd addr request and send MSG_ID_BT_BM_READ_LOCAL_ADDR_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_read_local_bd_addr_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_READ_LOCAL_ADDR_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_local_bd_addr_cnf_hdler
 * DESCRIPTION
 *  This function is to handle read local bd addr confirm and set local name
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_read_local_bd_addr_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 name_len;
    bt_bm_read_local_addr_cnf_struct* msg_p = (bt_bm_read_local_addr_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_READ_LOCAL_BD_ADDR_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        ((msg_p->bd_addr.nap&0xff00) >> 8),
        (msg_p->bd_addr.nap&0x00ff), 
        (msg_p->bd_addr.uap),
        ((msg_p->bd_addr.lap & 0xff0000) >> 16),
        ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
        (msg_p->bd_addr.lap & 0x0000ff));

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __TC01__ */

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
		srv_bt_cm_copy_addr(&g_srv_bt_cm_cntx.host_dev.bd_addr,(srv_bt_cm_bt_addr*) &msg_p->bd_addr);

        switch (g_srv_bt_cm_cntx.state)
        {
            case SRV_BT_CM_STATE_ACTIVATING:
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode */
                /* set local name */

//直接修改蓝牙名字  chengjun
#if defined (__BLE_QB__)
            {
                kal_uint8 ble_name[]={"NokeLock"};
                name_len = strlen((const char*)ble_name);
                srv_bt_cm_set_local_name_req_hdler(name_len, ble_name);
            }
#elif defined (__BLE_GB__)
            {
                kal_uint8 ble_name[]={"gb_nttel100"};
                name_len = strlen((const char*)ble_name);
                srv_bt_cm_set_local_name_req_hdler(name_len, ble_name);
            }
#elif defined (__BLE_MF__)
            {
                kal_uint8 ble_name[]={"mf_nf2319"};
                name_len = strlen((const char*)ble_name);
                srv_bt_cm_set_local_name_req_hdler(name_len, ble_name);
            }
#elif defined (__BLE_N07__)
            {
            	extern char name_data[20];
                //kal_uint8 ble_name[]={"songguo-ebike"};
                name_len = strlen((const char*)name_data);
                srv_bt_cm_set_local_name_req_hdler(name_len, name_data);
            }
#else
                name_len = strlen((const char*)g_srv_bt_cm_cntx.host_dev.name);
                srv_bt_cm_set_local_name_req_hdler(name_len, g_srv_bt_cm_cntx.host_dev.name);
#endif /* __BLE_QB__ */

                
                break;
        }
    }
    else
    {
        MMI_BT_ASSERT(0);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_remote_name_req_hdler
 * DESCRIPTION
 *  This function is to handle read remote name request and send MSG_ID_BT_BM_READ_REMOTE_NAME_REQ
 * PARAMETERS
 *  bt_add      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_read_remote_name_req_hdler(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_read_remote_name_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_read_remote_name_req_struct*)construct_local_para(
        sizeof(bt_bm_read_remote_name_req_struct),
        TD_CTRL);

	srv_bt_cm_copy_addr((srv_bt_cm_bt_addr *)&msg_p->bd_addr,dev_addr);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_READ_REMOTE_NAME_REQ, (void*)msg_p, NULL);
    /* deal with the response at srv_bt_cm_read_remote_name_cnf_hdler() */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_remote_name_cnf_hdler
 * DESCRIPTION
 *  This function is to handle read remote name confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_read_remote_name_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, name_len;
    bt_bm_read_remote_name_cnf_struct* msg_p = (bt_bm_read_remote_name_cnf_struct*)msg;
    srv_bt_cm_read_remote_dev_name_struct para2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_READ_REMOTE_NAME_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        ((msg_p->bd_addr.nap & 0xff00) >> 8),
        (msg_p->bd_addr.nap & 0x00ff),
        (msg_p->bd_addr.uap),
        ((msg_p->bd_addr.lap & 0xff0000) >> 16),
        ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
        (msg_p->bd_addr.lap & 0x0000ff));

    //msg_p->name[msg_p->name_len] = 0;
    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV);
        if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
        {
            return;
        }

        name_len = msg_p->name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
            (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
            msg_p->name_len;
        srv_bt_cm_copy_n_utf8_chars(
            g_srv_bt_cm_cntx.dev_list[i].dev_info.name,
            SRV_BT_CM_BD_FNAME_LEN,
            msg_p->name,
            name_len);

        g_srv_bt_cm_cntx.dev_list[i].dev_info.cod = msg_p->cod;
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)i);
    }


    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_READING_REMOTE_DEV_NAME:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            para2.dev_addr = (srv_bt_cm_bt_addr*)&msg_p->bd_addr;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME, (void*)&para2);
            break;

        default:
            para2.dev_addr = (srv_bt_cm_bt_addr*)&msg_p->bd_addr;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME, (void*)&para2);
            break;
    }
}

void srv_bt_cm_remote_name_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, name_len;
    bt_bm_remote_name_ind_struct* msg_p = (bt_bm_remote_name_ind_struct*)msg;
    srv_bt_cm_read_remote_dev_name_struct para2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_READ_REMOTE_NAME_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        ((msg_p->bd_addr.nap & 0xff00) >> 8),
        (msg_p->bd_addr.nap & 0x00ff),
        (msg_p->bd_addr.uap),
        ((msg_p->bd_addr.lap & 0xff0000) >> 16),
        ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
        (msg_p->bd_addr.lap & 0x0000ff));

    //msg_p->name[msg_p->name_len] = 0;
    if (msg_p->name_len != 0)
    {
        i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV);
        if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
        {
            return;
        }

        name_len = msg_p->name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
            (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
            msg_p->name_len;
        srv_bt_cm_copy_n_utf8_chars(
            g_srv_bt_cm_cntx.dev_list[i].dev_info.name,
            SRV_BT_CM_BD_FNAME_LEN,
            msg_p->name,
            name_len);

        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)i);
    }


    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_READING_REMOTE_DEV_NAME:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            para2.dev_addr = (srv_bt_cm_bt_addr*)&msg_p->bd_addr;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME, (void*)&para2);
            break;

        default:
            para2.dev_addr = (srv_bt_cm_bt_addr*)&msg_p->bd_addr;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME, (void*)&para2);
            break;
    }

}
static void srv_bt_cm_req_hdler_ext(srv_bt_cm_bt_addr bt_add, U8 sdap_len, U16* sdap_uuid,U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_bm_service_search_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_service_search_req_struct*)construct_local_para(sizeof(bt_bm_service_search_req_struct), TD_CTRL);

	srv_bt_cm_copy_addr((srv_bt_cm_bt_addr *)&(msg_p->bd_addr),&bt_add);
    msg_p->sdap_len = sdap_len;
    do {if(!(sdap_len <= (15))) {} } while (0);

    for (i = 0; i < sdap_len; i++)
    {
        msg_p->sdap_uuid[i] = sdap_uuid[i];
    }

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, msg_id, (void*)msg_p, 0);


}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sdc_search_req_hdler
 * DESCRIPTION
 *  This function is to handle SDC search request and send MSG_ID_BT_BM_SERVICE_SEARCH_REQ
 * PARAMETERS
 *  bt_add          [IN]            bd addr
 *  sdap_len        [IN]           SDAP length
 *  sdap_uuid       [IN]           SDAP UUID
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_sdc_search_req_hdler(srv_bt_cm_bt_addr bt_add, U8 sdap_len, U16* sdap_uuid)
{
	srv_bt_cm_req_hdler_ext(bt_add,sdap_len,sdap_uuid,MSG_ID_BT_BM_SERVICE_SEARCH_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sdc_search_ind_hdler
 * DESCRIPTION
 *  This function is to handle SDC search indication 
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_sdc_search_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 service_count;
    U32 i, j;
    U32 service_profile_uuid;
    bt_bm_service_search_result_ind_struct* msg_p = (bt_bm_service_search_result_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SDC_SEARCH_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        msg_p->uuid);

    if (msg_p->uuid == SRV_BT_CM_AUDIO_SINK_UUID)
    {
        service_profile_uuid = SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID;
    }
    else
    {
        service_profile_uuid = msg_p->uuid;
    }

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_SDC_SEARCHING:
            index = g_srv_bt_cm_cntx.action_index;
            service_count = g_srv_bt_cm_cntx.discovered_list[index].service_list_num;
            g_srv_bt_cm_cntx.discovered_list[index].service_list[service_count] = service_profile_uuid;
            g_srv_bt_cm_cntx.discovered_list[index].service_list_num++;
            MMI_BT_ASSERT(g_srv_bt_cm_cntx.discovered_list[index].service_list_num <= SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE);
            return 0; // return 1;

        case SRV_BT_CM_STATE_SDC_REFRESHING:
        case SRV_BT_CM_STATE_IDLE:
            i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV);
            if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
            {
                return 0; // return 1;
            }

            service_count = g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num;
            /* to filter out the duplicated sdc indication */
            for (j = 0; j < service_count; j++)
            {
                if (g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list[j] == service_profile_uuid)
                {
                    return 0; // return 1;
                }
            }

            if (j != g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num)
            {
                return 0; // return 1;
            }

            g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list[service_count] = service_profile_uuid;
            g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num++;
            MMI_BT_ASSERT(g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num <= SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE);
            return 0; // return 1;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sdc_search_cnf_hdler
 * DESCRIPTION
 *  This function is to handle SDC search confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_sdc_search_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_service_search_cnf_struct* msg_p = (bt_bm_service_search_cnf_struct*)msg;
    U32 i;
    srv_bt_cm_bond_res_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SDC_SEARCH_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        msg_p->searched_number,
        ((msg_p->bd_addr.nap & 0xff00) >> 8),
        (msg_p->bd_addr.nap & 0x00ff),
        (msg_p->bd_addr.uap),
        ((msg_p->bd_addr.lap & 0xff0000) >> 16),
        ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
        (msg_p->bd_addr.lap & 0x0000ff));

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_SDC_SEARCHING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            srv_bt_cm_dev_add_int(
                (const srv_bt_cm_dev_struct*)&g_srv_bt_cm_cntx.discovered_list[g_srv_bt_cm_cntx.action_index],
                SRV_BT_CM_PAIRED_DEV);
		   /*MAUI_03214569 */
           // g_srv_bt_cm_cntx.discovered_dev_num = 0;
           /* memset(
                &(g_srv_bt_cm_cntx.discovered_list),
                0,
                sizeof(srv_bt_cm_dev_struct) * SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST);*/
			/*MAUI_03214569 */
			srv_bt_cm_copy_addr(&para.dev_addr,(srv_bt_cm_bt_addr *) &(msg_p->bd_addr));
            para.result = SRV_BT_CM_RESULT_SUCCESS;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_BOND_RES, (void*)&para);
            return 0; // return 1;

        case SRV_BT_CM_STATE_SDC_REFRESHING:
        case SRV_BT_CM_STATE_PASSKEY_IND:
        case SRV_BT_CM_STATE_PASSKEY_RES:
        //case SRV_BT_CM_STATE_IDLE:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV);
            if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
            {
                return 0; // return 1;
            }

            if ((msg_p->result != BTBM_ADP_SUCCESS) && (msg_p->searched_number == 0))
            {
                /* re-store the original number of service list */
                g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num = g_srv_bt_cm_cntx.stored_ser_list_num;
            }
            srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)i);
            
            {
                srv_bt_cm_refresh_service_list_struct para;
                para.result = (U32)msg_p->result;
                //para.result = (msg_p->result == BTBM_ADP_SUCCESS) ? SRV_BT_CM_RESULT_SUCCESS : SRV_BT_CM_RESULT_FAILED;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_REFRESH_PROFILE, (void*)&para);
#ifdef __BCM_SUPPORT__
                cmd_hdlr_bt_service_search_cnf(msg_p->result == BTBM_ADP_SUCCESS ? KAL_TRUE : KAL_FALSE,msg_p->bd_addr);
#endif

            }
            return 0; // return 1;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_link_connect_accept_ind_hdler
 * DESCRIPTION
 *  This function is to handle if reaching max number of paired device 
 * PARAMETERS
 *  msg     [IN]    msg structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_link_connect_accept_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_link_connect_accept_ind_struct* msg_p = (bt_bm_link_connect_accept_ind_struct*)msg;
    bt_bm_link_connect_accept_rsp_struct* msg_rsp_p;
    srv_bt_cm_state_enum cm_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_LINK_CONNECT_ACCEPT_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    msg_rsp_p = (bt_bm_link_connect_accept_rsp_struct*)construct_local_para(
        sizeof(bt_bm_link_connect_accept_rsp_struct),
        TD_CTRL);
	srv_bt_cm_copy_addr(&(msg_rsp_p->bd_addr),(void *) &(msg_p->bd_addr));

    cm_state = g_srv_bt_cm_cntx.state;
    if ((cm_state != SRV_BT_CM_STATE_IDLE && 
         cm_state != SRV_BT_CM_STATE_CONNECTING &&
         cm_state != SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND)
       #ifdef __MMI_TELEPHONY_SUPPORT__
         || srv_mode_switch_is_switching()
       #endif
        )
    {
        msg_rsp_p->result = BTBM_ADP_FAILED;
    }
    else
    {
        msg_rsp_p->result = BTBM_ADP_SUCCESS;
    }

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_RSP, (void*)msg_rsp_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond_req_hdler
 * DESCRIPTION
 *  This function is to handle bond request and send MSG_ID_BT_BM_BONDING_REQ
 * PARAMETERS
 *  bt_add          [IN]            bd addr
 *  sdap_len        [IN]           SDAP length
 *  sdap_uuid       [IN]          SDAP UUID
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_bond_req_hdler(srv_bt_cm_bt_addr bt_add, U8 sdap_len, U16* sdap_uuid)
{
#ifdef _MMI_BT_ULTRA_SLIM_
	srv_bt_cm_req_hdler_ext(bt_add,sdap_len,sdap_uuid,MSG_ID_BT_BM_BONDING_REQ);
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_bm_bonding_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_bonding_req_struct*)construct_local_para(
        sizeof(bt_bm_bonding_req_struct),
        TD_CTRL);
    msg_p->bd_addr.lap = bt_add.lap;
    msg_p->bd_addr.uap = bt_add.uap;
    msg_p->bd_addr.nap = bt_add.nap;
    msg_p->sdap_len = sdap_len;
    MMI_BT_ASSERT(sdap_len <= BTBM_ADP_MAX_SDAP_UUID_NO);

    for (i = 0; i < sdap_len; i++)
    {
        msg_p->sdap_uuid[i] = sdap_uuid[i];
    }

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_BONDING_REQ, (void*)msg_p, NULL);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond_ind_hdler
 * DESCRIPTION
 *  This function is to handle bond indication
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_bond_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_bonding_result_ind_struct* msg_p = (bt_bm_bonding_result_ind_struct*)msg;
    srv_bt_cm_state_enum cm_state;
    srv_bt_cm_pair_res_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BOND_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

	srv_bt_cm_copy_addr(&para.dev_addr,(void *)&(msg_p->bd_addr));
    para.result = (msg_p->result == BTBM_ADP_SUCCESS) ? SRV_BT_CM_RESULT_SUCCESS : SRV_BT_CM_RESULT_FAILED;
    
    if (SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_FIRST_PAIR_REQ))
    {
        para.is_first_pair = MMI_TRUE;
        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_FIRST_PAIR_REQ);
    }
    else
    {
        para.is_first_pair = MMI_FALSE;
    }

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        g_srv_bt_cm_cntx.temp_dev.cod = msg_p->cod;
        srv_bt_cm_dev_add_int((const srv_bt_cm_dev_struct*)&g_srv_bt_cm_cntx.temp_dev, SRV_BT_CM_PAIRED_DEV);
    }

    memset(&g_srv_bt_cm_cntx.temp_dev, 0, sizeof(srv_bt_cm_dev_struct));

    cm_state = g_srv_bt_cm_cntx.state;
#ifdef __BCM_SUPPORT__
    if(srv_bt_cm_get_state() == SRV_BT_CM_STATE_NUMERIC_CONFIRM ||
        srv_bt_cm_get_state() == SRV_BT_CM_STATE_BONDING ||
        srv_bt_cm_get_state() == SRV_BT_CM_STATE_PASSKEY_NOTIFY ||
        srv_bt_cm_get_state() == SRV_BT_CM_STATE_PASSKEY_IND)
    {
        msg_bcm_pair_res_ind(SRV_BT_CM_EVENT_PAIR_RES,(para.result == SRV_BT_CM_RESULT_SUCCESS),para.dev_addr,para.is_first_pair);
    }
#endif
    if (!(SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_REJECT_PAIR_REQ)))
    {
        if (cm_state == SRV_BT_CM_STATE_PASSKEY_RES || 
            cm_state == SRV_BT_CM_STATE_PASSKEY_IND ||
            cm_state == SRV_BT_CM_STATE_PASSKEY_NOTIFY ||
            cm_state == SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL ||
            cm_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM ||
            cm_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
        }
        else if ((g_srv_bt_cm_cntx.tmp_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP) ||
                 (g_srv_bt_cm_cntx.tmp_state == SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL) ||
                 (g_srv_bt_cm_cntx.tmp_state == SRV_BT_CM_STATE_PASSKEY_RES))
        {
            if (cm_state == SRV_BT_CM_STATE_ACTIVATING_PROFILES)
            {
                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            }
            else
            {
                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
            }
            
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_BOND_IND_HDLER_2);
        }
    }
    else
    {
        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_REJECT_PAIR_REQ);
    }

    srv_bt_cm_notify(SRV_BT_CM_EVENT_PAIR_RES, (void*)&para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond_cnf_hdler
 * DESCRIPTION
 *  This function is to handle bond confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_bond_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_bonding_cnf_struct* msg_p = (bt_bm_bonding_cnf_struct*)msg;
    srv_bt_cm_bond_res_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BOND_CNF_HDLER);

    if (msg_p->result != SRV_BT_CM_BTBM_SUCCESS && g_srv_bt_cm_cntx.state >=SRV_BT_CM_STATE_IDLE)
    {
        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_BONDING)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
        }

		srv_bt_cm_copy_addr(&para.dev_addr,(void *)&(msg_p->bd_addr));
        para.result = SRV_BT_CM_BTBM_FAILED;
        srv_bt_cm_notify(SRV_BT_CM_EVENT_BOND_RES, (void*)&para);
    }
    else
    {

        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_BONDING)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_SDC_SEARCHING);
        }
    }
}


#ifdef __BT_BOND_CANCEL__
void srv_bt_cm_bond_cancel_req_hdler(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_bonding_cancel_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_bonding_cancel_req_struct*)construct_local_para(
        sizeof(bt_bm_bonding_cancel_req_struct),
        TD_CTRL);
	srv_bt_cm_copy_addr(&msg_p->bd_addr,dev_addr);
    srv_bt_cm_send_msg(
        MOD_BT,
        BT_APP_SAP,
        MSG_ID_BT_BM_BONDING_CANCEL_REQ,
        NULL,
        NULL);
}


void srv_bt_cm_bond_cancel_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_bonding_cancel_cnf_struct* msg_p = (bt_bm_bonding_cancel_cnf_struct*)msg;
    srv_bt_cm_bond_cancel_result para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
    {
        SRV_BT_CM_STATE_TRANS(g_srv_bt_cm_cntx.tmp_state);
        SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
    }
    else
    {
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
        SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
    }

    para.result = (msg_p->result == BTBM_ADP_SUCCESS) ? MMI_TRUE : MMI_FALSE;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_BOND_CANCEL, (void*)&para);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_debond_req_hdler
 * DESCRIPTION
 *  This function is to handle debond request and send MSG_ID_BT_BM_DELETE_TRUST_REQ
 * PARAMETERS
 *  dev_addr      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_debond_req_hdler(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_delete_trust_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_delete_trust_req_struct*)construct_local_para(
        sizeof(bt_bm_delete_trust_req_struct),
        TD_CTRL);
	srv_bt_cm_copy_addr(&(msg_p->bd_addr),dev_addr);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DELETE_TRUST_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_debond_cnf_hdler
 * DESCRIPTION
 *  This function is to handle debond confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_debond_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_delete_trust_cnf_struct* msg_p = (bt_bm_delete_trust_cnf_struct*)msg;
	srv_bt_cm_dev_struct delete_dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEBOND_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

	memcpy(&delete_dev_info, srv_bt_cm_get_dev_info((srv_bt_cm_bt_addr*)&msg_p->bd_addr), sizeof(delete_dev_info));
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_DELETING:
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                srv_bt_cm_dev_delete_int((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_PAIRED_DEV);

#ifdef __MMI_BT_AUTHORIZE__
                srv_bt_cm_block_list_update_req_hdler();
#else  /*  __MMI_BT_AUTHORIZE__ */
                {
                    srv_bt_cm_mydev_del_struct para;

                    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                    para.result = MMI_TRUE;
					para.del_dev= &delete_dev_info;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_MYDEV_DEL, (void*)&para);
                }
#endif /* __MMI_BT_AUTHORIZE__ */
            }
            else
            {
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                {
                    srv_bt_cm_mydev_del_struct para;
                    para.result = MMI_FALSE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_MYDEV_DEL, (void*)&para);
                }
            }
            break;

        case SRV_BT_CM_STATE_DELETING_ALL:
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                {
                    srv_bt_cm_dev_delete_int((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_PAIRED_DEV);
                    if (g_srv_bt_cm_cntx.paired_dev_num == 0)
                    {
#ifdef __MMI_BT_AUTHORIZE__
                        srv_bt_cm_block_list_update_req_hdler();
#else
                        {
                            srv_bt_cm_mydev_del_struct para;

                            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);

                            para.result = MMI_TRUE;
                            srv_bt_cm_notify(SRV_BT_CM_EVENT_MYDEV_DEL, (void*)&para);
                        }
#endif /* (__MMI_BT_AUTHORIZE__) */
                    }
                    else
                    {
                        srv_bt_cm_debond_req_hdler(&(g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.paired_idx_list[0]].dev_info.bd_addr));
                    }
                }
            }
            else
            {
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                {
                    srv_bt_cm_mydev_del_struct para;
                    para.result = MMI_FALSE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_MYDEV_DEL, (void*)&para);
                }
            }
            break;

        case SRV_BT_CM_STATE_DEBONDING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            /* ZHY: should notify MMI */
            break;

        default:
            return;
    }
}

void srv_bt_cm_copy_addr(void *dest,void *src)
{
		srv_bt_cm_bt_addr *addr_src= (srv_bt_cm_bt_addr *) src;
		srv_bt_cm_bt_addr *addr_dest= (srv_bt_cm_bt_addr *) dest;
		addr_dest->lap = addr_src->lap;
		addr_dest->nap = addr_src->nap;
		addr_dest->uap = addr_src->uap;

}

void srv_bt_cm_passkey_ind_hdler_ext(void *msg,int cmstate,int mode)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_bm_security_user_confirm_ind_struct* msg_p = (bt_bm_security_user_confirm_ind_struct*)msg;
	srv_bt_cm_bt_addr bd_add;
    srv_bt_cm_security_user_confirm_struct para;
	 srv_bt_cm_security_passkey_struct para_passk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bd_add.lap = msg_p->bd_addr.lap;
	bd_add.nap = msg_p->bd_addr.nap;
	bd_add.uap = msg_p->bd_addr.uap;
	srv_bt_cm_add_devname_addr( msg_p->bd_addr,msg_p->name, msg_p->name_len, msg_p->name_len!=0);

    if (srv_bt_cm_check_rejecting_state((void *)&msg_p->bd_addr))
    {
        /* reject the pair request */
    #ifdef __MMI_BT_SIMPLE_PAIR__
		if (mode == BT_CM_SECURITY_USER_CONFIRM)
			srv_bt_cm_security_user_confirm_rsp_hdler(bd_add, 0);
		else
			srv_bt_cm_security_keypress_notify_cancel_req_hdler(bd_add);
		#endif
        SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_REJECT_PAIR_REQ);
        return;
    }

	srv_bt_cm_key_ind_state_change(cmstate,(void *)&(msg_p->bd_addr));   
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV); 
  

	if (mode == BT_CM_SECURITY_USER_CONFIRM )
	{
		para.dev_name = g_srv_bt_cm_cntx.dev_list[i].dev_info.name;
		srv_bt_cm_copy_addr((void *)&(para.dev_addr), (void *)&(msg_p->bd_addr));
		para.display_numeric = msg_p->display_numeric;
		para.passcode = msg_p->numeric;
		srv_bt_cm_notify(SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM, (void*)&para);
	}
	else
	{
		para_passk.dev_name = g_srv_bt_cm_cntx.dev_list[i].dev_info.name;
		srv_bt_cm_copy_addr((void *)&(para_passk.dev_addr), (void *)&(msg_p->bd_addr));
		para_passk.passcode = msg_p->numeric;
		srv_bt_cm_notify(SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY, (void*)&para_passk);
	}

}

void srv_bt_cm_key_ind_state_change(int cmstate,void* bd_add)
{
	srv_bt_cm_bt_addr *bd_addr =(srv_bt_cm_bt_addr *) bd_add;
	if (srv_bt_cm_get_state() != SRV_BT_CM_STATE_BONDING)
    {
        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_CONNECTING && 
            srv_bt_cm_get_dev_index(bd_addr, SRV_BT_CM_ALL_DEV)
            == srv_bt_cm_get_action_item_index())
        {
            /* don't change the state, 
            because the passkey ind is triggered by the connecting to the device */
        }
        else
        {
            SRV_BT_CM_STATE_TRANS(cmstate);
        }
    }
    if (srv_bt_cm_get_dev_index(bd_addr, SRV_BT_CM_PAIRED_DEV)
        >= g_srv_bt_cm_cntx.paired_dev_num)
    {
        SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_FIRST_PAIR_REQ);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_passkey_ind_hdler
 * DESCRIPTION
 *  This function is to handle passkey indication
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_passkey_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 reject_pin_code[2];
    bt_bm_pin_code_ind_struct* msg_p = (bt_bm_pin_code_ind_struct*)msg;
    srv_bt_cm_pair_ind_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_PASSKEY_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);


    srv_bt_cm_add_devname_addr( msg_p->bd_addr,msg_p->name, msg_p->name_len, msg_p->name_len!=0);
	srv_bt_cm_copy_addr((void *)&para.dev_addr,(void *) &msg_p->bd_addr);
    para.enable_16digits_pin_code = msg_p->enable_16digits_pin_code;
        
       if(srv_bt_cm_check_rejecting_state((void *)&para.dev_addr))
        {
        memset(reject_pin_code, 0, 2);
        srv_bt_cm_passkey_ind_rsp_hdler(para.dev_addr, 0, reject_pin_code);
        SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_REJECT_PAIR_REQ);
        return;
        }
	srv_bt_cm_key_ind_state_change(SRV_BT_CM_STATE_PASSKEY_IND,(void* )&(msg_p->bd_addr));
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BT_CM_ALL_DEV);
    para.dev_name = g_srv_bt_cm_cntx.dev_list[i].dev_info.name;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_PAIR_IND, (void*)&para);
    }
  
MMI_BOOL srv_bt_cm_check_rejecting_state(void *bd_add)
        {
	srv_bt_cm_state_enum bth_state= srv_bt_cm_get_state();
	srv_bt_cm_bt_addr* bd_addr=(srv_bt_cm_bt_addr*) bd_add;;

    if (bth_state == SRV_BT_CM_STATE_INIT_ON ||
        bth_state == SRV_BT_CM_STATE_ACTIVATING ||
        bth_state == SRV_BT_CM_STATE_DEACTIVATING ||
        bth_state == SRV_BT_CM_STATE_PASSKEY_IND ||
        bth_state == SRV_BT_CM_STATE_PASSKEY_RES ||
        bth_state == SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND ||
        bth_state == SRV_BT_CM_STATE_INQUIRING ||
        bth_state == SRV_BT_CM_STATE_INQUIR_RES_IND ||
        bth_state == SRV_BT_CM_STATE_DEBONDING ||
        bth_state == SRV_BT_CM_STATE_DELETING ||
        bth_state == SRV_BT_CM_STATE_DELETING_ALL ||
        bth_state == SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION ||
        bth_state == SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION ||
        bth_state == SRV_BT_CM_STATE_SDC_SEARCHING ||
        bth_state == SRV_BT_CM_STATE_DISCONNECTING ||
        //bth_state == SRV_BT_CM_STATE_ACTIVATING_SIMAP ||
        //bth_state == SRV_BT_CM_STATE_DEACTIVATING_SIMAP ||
        bth_state == SRV_BT_CM_STATE_BLOCK_DEVICE_LINK ||
        bth_state == SRV_BT_CM_STATE_SDC_REFRESHING ||
        bth_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM ||
        bth_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP ||
        bth_state == SRV_BT_CM_STATE_ACTIVATING_PROFILES ||
        srv_bt_cm_is_pairing_permitted(*bd_addr) == MMI_FALSE ||
        (bth_state == SRV_BT_CM_STATE_CONNECTING && 
         (g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.action_index].dev_info.bd_addr.lap != bd_addr->lap ||
          g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.action_index].dev_info.bd_addr.uap != bd_addr->uap ||
          g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.action_index].dev_info.bd_addr.nap != bd_addr->nap) &&
         g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.action_index].ref_cnt > 0))
		return MMI_TRUE;
return MMI_FALSE;
    }

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_passkey_ind_rsp_hdler
 * DESCRIPTION
 *  This function is to handle passkey indication and send MSG_ID_BT_BM_PIN_CODE_RSP
 * PARAMETERS
 *  bt_add          [IN]            bd addr
 *  pin_len         [IN]            pin code length
 *  pin_code        [IN]           pin code
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_passkey_ind_rsp_hdler(srv_bt_cm_bt_addr bt_add, U8 pin_len, U8* pin_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_pin_code_rsp_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_pin_code_rsp_struct*)construct_local_para(sizeof(bt_bm_pin_code_rsp_struct), TD_CTRL);
	srv_bt_cm_copy_addr(&msg_p->bd_addr,(void *) &bt_add);
    msg_p->pin_len = pin_len;
    MMI_BT_ASSERT(pin_len <= SRV_BT_CM_PASSKEY_MAX_LEN);
    memcpy(msg_p->pin_code, pin_code, pin_len);

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_PIN_CODE_RSP, (void*)msg_p, NULL);
}


#ifdef __MMI_BT_SIMPLE_PAIR__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_user_confirm_ind_hdler
 * DESCRIPTION
 *  This function is to handle the numeric comparison indication of secure simple pairing
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_user_confirm_ind_hdler(void* msg)
{
  
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_USER_CONFIRM_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);
srv_bt_cm_passkey_ind_hdler_ext(msg,SRV_BT_CM_STATE_NUMERIC_CONFIRM,BT_CM_SECURITY_USER_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_user_confirm_rsp_hdler
 * DESCRIPTION
 *  This function is to respond the numeric comparison indication of secure simple pairing
 * PARAMETERS
 *  bt_add         [IN]        device address             
 *  accept         [IN]        end user response for the numeric comparison
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_user_confirm_rsp_hdler(srv_bt_cm_bt_addr bt_add, U8 accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_security_user_confirm_rsp_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_security_user_confirm_rsp_struct*)construct_local_para(
        sizeof(bt_bm_security_user_confirm_rsp_struct),
        TD_CTRL);
	srv_bt_cm_copy_addr(&msg_p->bd_addr,(void *) &bt_add);
    msg_p->accept = accept;

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_SECURITY_USER_CONFIRM_RSP, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_passkey_notify_ind_hdler
 * DESCRIPTION
 *  This function is to handle the passkey entry(notification) indication of secure simple pairing
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_passkey_notify_ind_hdler(void* msg)
{
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_PASSKEY_NOTIFY_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    srv_bt_cm_passkey_ind_hdler_ext(msg,SRV_BT_CM_STATE_PASSKEY_NOTIFY,BT_CM_SECURITY_PASSKEY_NOTIFY);  

}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_ind_hdler
 * DESCRIPTION
 *  This function is to handle the passkey entry(notification) keypress indication of secure simple pairing
 *  MMI can use indication to display how many digits inputted from remote device
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_keypress_notify_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_state_enum bth_state;
    bt_bm_security_keypress_notify_ind_struct* msg_p = (bt_bm_security_keypress_notify_ind_struct*)msg;
    srv_bt_cm_security_keypress_struct para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_KEYPRESS_NOTIFY_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    bth_state = srv_bt_cm_get_state();
    if (bth_state == SRV_BT_CM_STATE_PASSKEY_NOTIFY ||
        bth_state == SRV_BT_CM_STATE_BONDING)
    {
		srv_bt_cm_copy_addr(&para.dev_addr,(void *) &msg_p->bd_addr);
        para.num_digit = msg_p->event;
        
        srv_bt_cm_notify(SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY, (void*)&para);
    }

    srv_bt_cm_security_keypress_notify_rsp_hdler();
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_rsp_hdler
 * DESCRIPTION
 *  This function is to respond the passkey entry(notification) keypress indication of secure simple pairing
 *  to notify that MMI had updated the passkey entry(notification) screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_cm_security_keypress_notify_rsp_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_SECURITY_KEYPRESS_NOTIFY_RSP, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_cancel_req_hdler
 * DESCRIPTION
 *  This function is to respond the passkey entry(notification) keypress indication of secure simple pairing
 * PARAMETERS
 *  bt_add         [IN]        device address             
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_keypress_notify_cancel_req_hdler(srv_bt_cm_bt_addr bt_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_security_passkey_notify_cancel_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_KEYPRESS_NOTIFY_CANCEL_REQ_HDLER);

    msg_p = (bt_bm_security_passkey_notify_cancel_struct*)construct_local_para(
        sizeof(bt_bm_security_passkey_notify_cancel_struct),
        TD_CTRL);
	srv_bt_cm_copy_addr(&msg_p->bd_addr,(void *)&bt_add);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_SECURITY_KEYPRESS_NOTIFY_CANCEL_REQ, (void*)msg_p, NULL);
}
#endif /* __MMI_BT_SIMPLE_PAIR__ */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_active_link_req_hdler
 * DESCRIPTION
 *  This function is to release the existed active link after add this device to block list
 * PARAMETERS
 *  bt_add         [IN]        device address             
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_active_link_req_hdler(srv_bt_cm_bt_addr bt_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_block_active_link_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BLOCK_ACTIVE_LINK_REQ_HDLER);
    
    msg_p = (bt_bm_block_active_link_req_struct*)construct_local_para(
        sizeof(bt_bm_block_active_link_req_struct),
        TD_CTRL);
	srv_bt_cm_copy_addr(&msg_p->bd_addr,(void *)&bt_add);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_BLOCK_ACTIVE_LINK_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_active_link_cnf_hdler
 * DESCRIPTION
 *  This function is to handle the cnf of block active link request and invoke srv_bt_cm_block_list_update_req_hdler
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_active_link_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BLOCK_ACTIVE_LINK_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_BLOCK_DEVICE_LINK:
            srv_bt_cm_block_list_update_req_hdler();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_list_update_req_hdler
 * DESCRIPTION
 *  This function is to update the block list to BM of btstack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_list_update_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_block_list_update_req_struct* msg_p;
    U32 i, idx;
    U32 num_block_dev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BLOCK_LIST_UPDATE_REQ_HDLER);

    msg_p = (bt_bm_block_list_update_req_struct*)construct_local_para(
        sizeof(bt_bm_block_list_update_req_struct),
        TD_CTRL);
    num_block_dev = 0;
    for (i = 0; i < g_srv_bt_cm_cntx.paired_dev_num; ++i)
    {
        idx = g_srv_bt_cm_cntx.paired_idx_list[i];
        if (g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK &&
            num_block_dev < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST)
        {
			srv_bt_cm_copy_addr(&msg_p->block_list[num_block_dev],(void *)&(g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr));
            num_block_dev++;
        }
    }

    msg_p->num_block_list = num_block_dev;
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_BLOCK_LIST_UPDATE_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_list_update_cnf_hdler
 * DESCRIPTION
 *  This function is to handle the cnf of updating block list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_list_update_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BLOCK_LIST_UPDATE_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);
    
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_ACTIVATING:
            /* antenna on req->disable write scan enable(page off, inquiry off) */
            /* ->read BT address->set local name->set security->activate profiles */
            /* ->enable write scan mode-> update block list ->allow ACL link establishment */
            /* allow ACL link establishment */
            srv_bt_cm_allow_acl_link_establishment_req_hdler();
            break;

        case SRV_BT_CM_STATE_BLOCK_DEVICE_LINK:
            if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
            {
                SRV_BT_CM_STATE_TRANS(g_srv_bt_cm_cntx.tmp_state);
                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
            }
            else
            {
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            }
            
            {
                srv_bt_cm_set_authorize_struct para;
    
                para.result = MMI_TRUE;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_AUTHORIZE, (void*)&para);
            }
            break;

        case SRV_BT_CM_STATE_UNBLOCK_DEVICE_LINK:
            if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
            {
                SRV_BT_CM_STATE_TRANS(g_srv_bt_cm_cntx.tmp_state);
                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
            }
            else
            {
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            }
            

            {
                srv_bt_cm_unblock_struct para;
                para.result = MMI_TRUE;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_UNBLOCK, (void*)&para);
            }
            break;

        case SRV_BT_CM_STATE_DELETING:
        case SRV_BT_CM_STATE_DELETING_ALL:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            {
                srv_bt_cm_mydev_del_struct para;
                para.result = MMI_TRUE;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_MYDEV_DEL, (void*)&para);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_level_req_hdler
 * DESCRIPTION
 *  This function is to handle security level request and
 *  send MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_REQ
 * PARAMETERS
 *  auth_flag   [IN]    authentication flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_level_req_hdler(MMI_BOOL auth_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_authentication_mode_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_LEVEL_REQ_HDLER,
        auth_flag);

    msg_p = (bt_bm_write_authentication_mode_req_struct*)construct_local_para(
        sizeof(bt_bm_write_authentication_mode_req_struct),
        TD_CTRL);

    msg_p->mode = auth_flag ?
        BTBM_AUTHENTICATION_ENABLE :
        BTBM_AUTHENTICATION_DISABLE;
    srv_bt_cm_send_msg(
        MOD_BT,
        BT_APP_SAP,
        MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_REQ,
        (void*)msg_p,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_level_cnf_hdler
 * DESCRIPTION
 *  This function is to handle security level confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_level_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flight_mode;
    bt_bm_write_authentication_mode_cnf_struct* msg_p = (bt_bm_write_authentication_mode_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_LEVEL_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        msg_p->result,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag);

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        g_srv_bt_cm_cntx.host_security_level = msg_p->security_level;
    }
    else
    {
        MMI_BT_ASSERT(0);
    }

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_ACTIVATING:
        #ifdef __MMI_TELEPHONY_SUPPORT__
            flight_mode = (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF) ?
                MMI_TRUE :
                MMI_FALSE;
        #else
            flight_mode = MMI_FALSE;
        #endif
            if (!srv_bt_cm_is_all_supported_profiles_activated(flight_mode))
            {
                srv_bt_cm_activate_profiles_int(flight_mode);
            }
            else
            {
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode-> allow ACL link establishment */
                /* enable write scan mode */
                if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_VIS))
                {
                    srv_bt_cm_write_scanenable_mode_req_hdler((U8)BTBM_ADP_P_ON_I_ON);
                }
                else
                {
                    srv_bt_cm_write_scanenable_mode_req_hdler((U8)BTBM_ADP_P_ON_I_OFF);
                }

                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING_WRITE_SCAN_ENABLE);
            }
            break;

        case SRV_BT_CM_STATE_DEACTIVATING:
            break;


        case SRV_BT_CM_STATE_AUTHENTICATION_SETTING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                srv_bt_cm_nvram_write_info(NVRAM_EF_BT_INFO_LID, (void*)0);
            }
            {
                srv_bt_cm_set_authentication_struct para;
                para.result = (U32)msg_p->result;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_AUTHENTICATION, (void*)&para);
            }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_write_scanenable_mode_req_hdler
 * DESCRIPTION
 *  This function is to handle write scanenable mode request and send MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ
 * PARAMETERS
 *  connected_mode          [IN]            connected mode
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_write_scanenable_mode_req_hdler(U8 connected_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_scanenable_mode_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_WRITE_SCANENABLE_MODE_REQ_HDLER,
        connected_mode);

    msg_p = (bt_bm_write_scanenable_mode_req_struct*)construct_local_para(
        sizeof(bt_bm_write_scanenable_mode_req_struct),
        TD_CTRL);
    msg_p->mode = (btbm_scan_enable_type)connected_mode;
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ, (void*)msg_p, NULL);
    /* deal with the response at: srv_bt_cm_write_scanenable_mode_cnf_hdler() */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_write_scanenable_mode_cnf_hdler
 * DESCRIPTION
 *  This function is to handle write scanenable mode confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_write_scanenable_mode_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_scanenable_mode_cnf_struct* msg_p = (bt_bm_write_scanenable_mode_cnf_struct*)msg;
#ifdef __SUPPORT_JBT__
    mmi_bth_bcc_set_discoverable_mode_cb_struct param;
    U8 jsr_discoverable_mode;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_WRITE_SCANENABLE_MODE_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag,
        msg_p->result);

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
#endif

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        switch (g_srv_bt_cm_cntx.state)
        {
            case SRV_BT_CM_STATE_ACTIVATING:
                if (g_srv_bt_cm_cntx.tmp_state == SRV_BT_CM_STATE_ACTIVATING_WRITE_SCAN_DISABLE)
                {
                    srv_bt_cm_read_local_bd_addr_req_hdler();
                }
                else if (g_srv_bt_cm_cntx.tmp_state == SRV_BT_CM_STATE_ACTIVATING_WRITE_SCAN_ENABLE)
                {
#if defined(__MMI_BT_AUTHORIZE__)
                    srv_bt_cm_block_list_update_req_hdler();
#else
                    srv_bt_cm_allow_acl_link_establishment_req_hdler();
#endif /* __MMI_BT_AUTHORIZE__ */
                }

                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING);
                break;

            case SRV_BT_CM_STATE_DEACTIVATING:
                /* disable write scan enable(page off, inquiry off) */
                /* ->deactivate profiles */
                /* ->antenna off */
                if (srv_bt_cm_is_all_supported_profiles_deactivated())
                {
                    SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_ACTIVATED);
                    srv_bt_cm_antenna_off();
                }
                else
                {
                    srv_bt_cm_deactivate_profiles();
                }
                break;

            case SRV_BT_CM_STATE_VISIBILITY_SETTING:
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                switch (g_srv_bt_cm_cntx.tmp_visibility_type)
                {
                    case SRV_BT_CM_VISIBILITY_ON:
                        SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_VIS);
                        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS);
                        break;

#ifdef __MMI_BT_TEMP_VISIBILITY__
                    case SRV_BT_CM_VISIBILITY_TEMPORARY_ON:
                        SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS);
                        SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
                        break;
#endif  // __MMI_BT_TEMP_VISIBILITY__

                    case SRV_BT_CM_VISIBILITY_OFF:
                        SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
                        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS);
                        break;
                }

                g_srv_bt_cm_cntx.tmp_visibility_type = 0;
                srv_bt_cm_nvram_write_info(NVRAM_EF_BT_SYS_INFO_LID, (void*)0);
                {
                    srv_bt_cm_set_visibility_struct para;
                    para.result = MMI_TRUE;
                    para.is_from_mmi = MMI_TRUE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_VISIBILITY, (void*)&para);
                }
                break;

#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
            case SRV_BT_CM_STATE_SETTING_LIMIT_VISIBILITY:
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                /* BCC */
                {
                    srv_bt_cm_set_limit_discoverable_mode_struct para;
                    para.result = (U32)msg_p->result;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE, (void*)&para);
                    StopTimer(BT_CMD_GUARD_TIMER);
                }
                break;

            case SRV_BT_CM_STATE_RESETTING_LIMIT_VISIBILITY:
                srv_bt_cm_allow_acl_link_establishment_req_hdler();
                StopTimer(BT_CMD_GUARD_TIMER);
                break;
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/

            case SRV_BT_CM_STATE_DISCOVERABLE_MODE_SETTING:
#ifdef __SUPPORT_JBT__
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                param.result = mmi_bt_bcc_result_succeeded;

                /* update visibility */
                jsr_discoverable_mode = mmi_bth_bcc_get_discoverable_mode();
                switch (jsr_discoverable_mode)
                {
                    case BTBM_ADP_P_OFF_I_OFF:
                        SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
                        break;

                    case BTBM_ADP_P_OFF_I_ON:
                        SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_VIS);
                        break;

                    case BTBM_ADP_P_ON_I_OFF:
                        SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
                        break;

                    case BTBM_ADP_P_ON_I_ON:
                        SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_VIS);
                        break;
                }
                
                if (g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE].cb_func_ptr)
                {
                    g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE].cb_func_ptr((void*)&param);
                }
#endif /*__SUPPORT_JBT__*/
                break;

            default:
                {
                    srv_bt_cm_set_visibility_struct para;
                    para.result = MMI_TRUE;
                    para.is_from_mmi = MMI_FALSE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_VISIBILITY, (void*)&para);
                }
                break;
        }
    }
    /* BCC */
    else if (msg_p->result == BTBM_ADP_FAIL_NOT_ALLOW || msg_p->result == BTBM_ADP_FAIL_BUSY)
    {
        switch (g_srv_bt_cm_cntx.state)
        {
            case SRV_BT_CM_STATE_VISIBILITY_SETTING:
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                /* do not set any flag, just hold previous flag */
                g_srv_bt_cm_cntx.tmp_visibility_type = 0;
                {
                    srv_bt_cm_set_visibility_struct para;
                    para.result = MMI_FALSE;
                    para.is_from_mmi = MMI_TRUE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_VISIBILITY, (void*)&para);
                }
                break;

#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
            case SRV_BT_CM_STATE_SETTING_LIMIT_VISIBILITY:
            case SRV_BT_CM_STATE_RESETTING_LIMIT_VISIBILITY:
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                if (SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_LIMIT_VIS))
                {
                    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_LIMIT_VIS);
                }
                else
                {
                    SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_LIMIT_VIS);
                }

                {
                    srv_bt_cm_set_limit_discoverable_mode_struct para;
                    para.result = (U32)msg_p->result;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE, (void*)&para);
                }
                StopTimer(BT_CMD_GUARD_TIMER);
                break;
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/

            case SRV_BT_CM_STATE_DISCOVERABLE_MODE_SETTING:
#ifdef __SUPPORT_JBT__
                param.result = mmi_bt_bcc_result_failed;
                if (g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE].cb_func_ptr)
                {
                    g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE].cb_func_ptr((void*)&param);
                }
#endif /*__SUPPORT_JBT__*/
                break;

            default:
                /* already off state, no need to notify MMI, and set state as permanant off state */
                SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
                break;
        }
    }
    else
    {
        MMI_BT_ASSERT(0);
    }

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_op11_hs32_cnx_bt_update();
#endif

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_link_state_ind_hdler
 * DESCRIPTION
 *  This function is to handle link state indication
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_link_state_ind_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_LINK_STATE_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

//没意义  chengjun

}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_allow_acl_link_establishment_req_hdler
 * DESCRIPTION
 *  This function is to handle allow ACL link establishment request and send MSG_ID_BT_BM_LINK_ALLOW_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_allow_acl_link_establishment_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ALLOW_ACL_LINK_ESTABLISHMENT_REQ_HDLER);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_ALLOW_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_allow_acl_link_establishment_cnf_hdler
 * DESCRIPTION
 *  This function is to handle allow ACL link establishment confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_allow_acl_link_establishment_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JBT__
    mmi_bth_bcc_power_on_cb_struct param;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ALLOW_ACL_LINK_ESTABLISHMENT_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_ACTIVATING:
            /* antenna on req->disable write scan enable(page off, inquiry off) */
            /* ->read BT address->set local name->set security->activate profiles */
            /* ->enable write scan mode->update block list->allow ACL link establishment */
            /* complete power on procedure */
            //StopTimer(BT_WAIT_POWER_ON_TIMER);
            SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_READY);
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
            srv_bt_cm_nvram_write_info(NVRAM_EF_BT_INFO_LID, (void*)0);
            {
                srv_bt_cm_activate_struct para1;
                para1.result = MMI_TRUE;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_ACTIVATE, (void*)&para1);
            }
#ifdef __SUPPORT_JBT__
            param.result = mmi_bt_bcc_result_succeeded;

            if (g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_POWER_ON].cb_func_ptr)
            {
                g_srv_bt_cm_cntx.operation_cb_tbl[SRV_BT_CM_OPER_TYPE_POWER_ON].cb_func_ptr((void*)&param);
            }
#endif /*__SUPPORT_JBT__*/

#ifdef __DM_LAWMO_SUPPORT__
            if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_DM_RESET))
            {
                srv_bt_cm_lock_bt_module_req();
            }
#endif /*__DM_LAWMO_SUPPORT__*/
#ifdef __BCM_AT_CMD__
            cmd_hdlr_bt_power_on_cnf(KAL_TRUE);
#endif
            return 1;

#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
         case SRV_BT_CM_STATE_RESETTING_LIMIT_VISIBILITY: 
             SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
             /* BCC */
             {
                 srv_bt_cm_set_limit_discoverable_mode_struct para;
                 para.result = (U32)BTBM_ADP_SUCCESS;
                 srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE, (void*)&para);
             }
             return 1;
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/

        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_disallow_acl_link_establishment_cnf_hdler
 * DESCRIPTION
 *  This function is to handle disallow ACL link establishment confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_bt_cm_disallow_acl_link_establishment_cnf_hdler(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DISALLOW_ACL_LINK_ESTABLISHMENT_CNF_HDLER,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);
    
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_DEACTIVATING:
            /* disallow acl link establishment */
            /* ->disable write scan enable(page off, inquiry off) */
            /* ->deactivate profiles */
            /* ->antenna off */
            /* disable write scan enable(page off, inquiry off) */
            //srv_bt_cm_write_scanenable_mode_req_hdler((U8)BTBM_ADP_P_OFF_I_OFF);
            return 1;

//         case SRV_BT_CM_STATE_ACTIVATING_SIMAP:
//             /* disallow acl link establishment */
//             /* ->simap activate */
// #ifdef __MMI_SIMAP_SUPPORT__
//             //mmi_bth_simap_activate_req_hdler();
//         {
//             U32 i;
//             for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
//             {
//                 if (g_srv_bt_cm_profile_tbl[i].profile_id == SRV_BT_CM_SIM_ACCESS_PROFILE_UUID)
//                 {
//                     if (g_srv_bt_cm_profile_tbl[i].activater)
//                     {
//                         (*g_srv_bt_cm_profile_tbl[i].activater)();
//                     }
//                     break;
//                 }
//             }
//         }
// #endif
//             break;

#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
        case SRV_BT_CM_STATE_SETTING_LIMIT_VISIBILITY:
            srv_bt_cm_write_scanenable_mode_req_hdler(BTBM_ADP_P_ON_I_ON_L_OFF);
            return 1;
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/

        default:
            break;
    }

    return 0;
}


#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_lock_bt_module_req
 * DESCRIPTION
 *  This function is to lock BT module and send MSG_ID_BT_LOCK_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    return TRUE
 *****************************************************************************/
MMI_BOOL srv_bt_cm_lock_bt_module_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_LOCK_BT_MODULE_REQ);

    if (srv_bt_cm_is_activated())
    {
        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_LOCK_REQ, NULL, NULL);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /*__DM_LAWMO_SUPPORT__*/


mmi_ret srv_bt_cm_uart_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret retval = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __EMPTY_MMI__
#ifdef __GEMINI__
    if (evt->evt_id == EVT_ID_SRV_SETTING_UART_SETTING_CHANGED)
    {
        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_SWITCHING_ON ||
            srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
        {
            srv_setting_uart_notification_struct *data = 
                (srv_setting_uart_notification_struct*)evt;
            bt_active_uart_change_req_struct *req = 
                (bt_active_uart_change_req_struct *)construct_local_para(sizeof(*req), TD_DL);

            req->active_uart = (U8)data->new_uart;
            srv_bt_cm_send_msg(
                MOD_BT,
                BT_APP_SAP,
                MSG_ID_BT_ACTIVE_UART_CHANGE_REQ,
                req,
                NULL);
        }
    }
    else
    {
        retval = MMI_RET_ERR;
    }
#endif  // __GEMINI__
#endif /* __EMPTY_MMI__ */

    return retval;
}


#ifdef __DM_LAWMO_SUPPORT__
mmi_ret srv_bt_cm_lawmo_lock_ind_hdlr(mmi_event_struct* evt)
{
    srv_dm_lawmo_lock_ind_evt_struct* lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;
    switch (lawmo_lock_ind->cmd)
    {
        case SRV_DM_LAWMO_LOCK_CMD_LOCK:
            switch (srv_bt_cm_get_power_status())
            {
                case SRV_BT_CM_POWER_ON:
                case SRV_BT_CM_POWER_SWITCHING_ON:
                    g_srv_bt_cm_cntx.lawmo_lock_cb = (*lawmo_lock_ind->cb);
                    SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_DM_RESET);
                    srv_bt_cm_lock_bt_module_req();
                    break;

                default:
                    (*lawmo_lock_ind->cb)(MMI_TRUE, "Bluetooth");
                    break;
            }
            break;

        case SRV_DM_LAWMO_LOCK_CMD_UNLOCK:
            (*lawmo_lock_ind->cb)(MMI_TRUE, "Bluetooth");
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}
#endif


#endif /* __MMI_BT_SUPPORT__ */ 
