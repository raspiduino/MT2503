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
 * BTB.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the source file of BTB
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

#include "mmi_features.h"

#ifdef __MMI_BT_BTBOX_NOLCD__

#include "kal_trace.h"
#include "MMI_conn_app_trc.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "BtcmSrvGprot.h"
#include "BtconnScr.h"
#include "BTconncfg.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "gpiosrvgprot.h"
#include "nvram_common_defs.h"
#include "BTMMIA2DPScr.h"
#include "BTMMIScr.h"
#include "ProfilesSrvGprot.h"
#include "BTB.h"
#include "mmi_frm_input_event.h"
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
#include  "BTMMIAntilostScr.h"
#endif  //__MMI_BT_ANTI_LOST_BY_RSSI__
#ifdef __MMI_BT_MUSIC_NOLCD__
#include "Mmi_rp_app_bt_music_nolcd_def.h"
#endif /* __MMI_BT_MUSIC_NOLCD__ */

#include "A2dpSrvGprot.h"
#include "AvrcpSrvGprot.h"

#include "BTMMIObexGprots.h"
#include "BTMMIA2DP.h"
#include "BthScoPathSrvGprot.h"



#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
extern void mmi_bt_avrcp_init(void);
#endif /* defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__) */

#ifdef __MMI_HF_SUPPORT__
extern void srv_bt_dialer_init(void);
extern void srv_bt_dialer_deinit(void);
#endif  //__MMI_HF_SUPPORT__

static const FuncPtr btb_cm_profile_init_tbl[] =
{
    srv_bt_cm_init,
    mmi_bt_common_init,
    #ifdef __MMI_A2DP_SUPPORT__
    mmi_bt_a2dp_init,
    #endif  //__MMI_A2DP_SUPPORT__
    #if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
    mmi_bt_avrcp_init,
    #endif  //defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
    #ifdef __MMI_HF_SUPPORT__
    srv_bt_dialer_init,
    #endif  //__MMI_HF_SUPPORT__
    NULL
};

static const FuncPtr btb_cm_profile_deinit_tbl[] =
{
    #ifdef __MMI_HF_SUPPORT__
    srv_bt_dialer_deinit,
    #endif  //__MMI_HF_SUPPORT__

    NULL
};


/***************************************************************************** 
 * Golobal function
 *****************************************************************************/
extern U16 mmi_btdialer_app_launch_func(void *param, U32 param_size);
extern void mmi_btdialer_cm_app_exit_func(void);
extern void mmi_bt_dialor_disconnect(srv_bt_cm_bt_addr* dev_addr);
extern MMI_BOOL mmi_bt_music_nolcd_is_playing_notify(void);
extern void mmi_bt_dialer_link_state_ind(void* para);

/***************************************************************************** 
 * Local functions
 *****************************************************************************/
static void btb_reset(MMI_BOOL reset_by_linein);
static void mmi_bt_dialer_set_disconn_req(MMI_BOOL req);
static void mmi_bt_dialer_disconnect_lsk(void);
static void mmi_bt_dialer_disconn_hdlr(void);
static mmi_bt_dialer_conn_callback_item *mmi_bt_dialer_next_callback_item(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL is_connect, MMI_BOOL is_indicate);
static MMI_BOOL mmi_bt_dialer_get_time_out_flag(void);
void mmi_bt_dialer_set_connected_dev_info(srv_bt_cm_dev_struct *dev_info);
void mmi_bt_dialer_clean_connected_dev_info(srv_bt_cm_dev_struct *dev_info);
static void mmi_bt_dialor_callback_int(srv_bt_cm_bt_addr* dev_addr,  MMI_BOOL result,MMI_BOOL is_connect, mmi_bt_dialer_conn_callback_item *callback_item);
static void mmi_bt_dialer_callback_done_int(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL is_connect);
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
static void mmi_bt_dialer_set_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev);
static void mmi_bt_dialer_clean_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev);
static void mmi_bt_dialer_disconn_excpt_hdlr(void *msg_ptr);
static void mmi_bt_dialer_auto_reconn_hdlr(void);
static void mmi_bt_dialer_auto_reconn_start(void);
static void mmi_bt_dialer_auto_reconn_first_start_check(void);

U32 mmi_bt_dialer_get_pre_autoreconn_inx_array(srv_bt_cm_bt_addr* dev_addr);
static void mmi_bt_dialer_set_pre_autoreconn_addr(srv_bt_cm_bt_addr *bd_addr);
static void mmi_bt_dialer_clean_pre_autoreconn_dev_addr(srv_bt_cm_bt_addr *dev_addr);


#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/


/**************************************************************************** 
 * Globol Variable
 *****************************************************************************/
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
static mmi_bt_reconn_ctx_struct  g_mmi_bt_reconn_ctx[BT_DEVICE_LINK_NUM];
static srv_bt_cm_bt_addr bd_pconn_addr[BT_DEVICE_LINK_NUM];
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/


/**************************************************************************** 
 * Local Variable
 *****************************************************************************/
static MMI_BOOL g_mmi_is_disconn_req=MMI_FALSE;
static MMI_BOOL time_out_flag = MMI_FALSE;
static MMI_BOOL g_bt_is_all_disconn = MMI_FALSE;
static MMI_BOOL g_mmi_is_vis_change_in_busy_state=MMI_FALSE;
WCHAR name_buf[BT_DEVICE_LINK_NUM][SRV_BT_CM_BD_FNAME_LEN + 20];
static mmi_frm_proc_id_info_struct g_id_info;
static mmi_id g_parent_id = NULL ;
srv_bt_cm_dev_struct g_connected_dev_info[BT_DEVICE_LINK_NUM];
mmi_bt_conn_headset_struct g_mmi_bt_dialer_headset_cntx;

S32 g_quick_conn_idx;
mmi_bt_scr_cntx_struct g_mmi_bt_scr_cntx;


static btb_context_struct g_btb_context;


#ifdef __MMI_LINE_IN__
extern MMI_BOOL mmi_linein_is_plug_in(void);
#endif  //__MMI_LINE_IN__




/*****************************************************************************
 * FUNCTION
 *  btb_post_event
 * DESCRIPTION
 *  This function is post event
 * PARAMETERS
 *  evt_id
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_post_event(MMI_ID evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_POST_EVENT, evt_id);
    MMI_FRM_INIT_EVENT(&evt, evt_id);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  btb_get_state
 * DESCRIPTION
 *  This function is get BTB state
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  btb_state_enum
 *****************************************************************************/
static btb_state_enum btb_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_btb_context.state;
}


/*****************************************************************************
 * FUNCTION
 *  btb_set_state
 * DESCRIPTION
 *  This function is set BTB state
 * PARAMETERS
 *  btb_state_enum
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_set_state(btb_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_SET_STATE, g_btb_context.state, state);
    g_btb_context.state = state;
}


/*****************************************************************************
 * FUNCTION
 *  btb_quiry_source_role
 * DESCRIPTION
 *  This function is to check if BTB has source role
 * PARAMETERS
 *  index		[IN]		the source index if return TRUE
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL btb_quiry_source_role(U8* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_a2dp_quiry_by_role(A2DP_ROLE_SOURCE, index);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_QUIRY_ROLE, 1, result, *index, srv_bt_cm_get_state(), btb_get_state());
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  btb_quiry_sink_role
 * DESCRIPTION
 *  This function is to check if BTB has sink role
 * PARAMETERS
 *  index		[IN]		the sink index if return TRUE
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL btb_quiry_sink_role(U8* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_a2dp_quiry_by_role(A2DP_ROLE_SINK, index);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_QUIRY_ROLE, 0, result, *index, srv_bt_cm_get_state(), btb_get_state());
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  btb_is_available
 * DESCRIPTION
 *  This function is to check if BTB is in IDLE state
 * PARAMETERS
 *  need_check_btb_state
 *  need_check_bt_state
 *  need_check_line_in
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL btb_is_available(MMI_BOOL need_check_btb_state, MMI_BOOL need_check_bt_state, MMI_BOOL need_check_line_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    srv_bt_cm_state_enum bt_state = srv_bt_cm_get_state();
    btb_state_enum btb_state = btb_get_state();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_is_completed() && srv_bt_cm_is_activated())
    {
        result = MMI_TRUE;
    }
    
    if (need_check_btb_state && btb_state != BTB_STATE_IDLE)
    {
        result = MMI_FALSE;
    }

    if (need_check_bt_state && bt_state != SRV_BT_CM_STATE_IDLE)
    {
        result = MMI_FALSE;
    }
    
    #ifdef __MMI_LINE_IN__
    if (need_check_line_in && mmi_linein_is_plug_in())
    {
        result = MMI_FALSE;
    }
    #endif  //__MMI_LINE_IN__
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_IS_AVAILABLE, need_check_btb_state, need_check_bt_state, need_check_line_in, result, bt_state, btb_state);
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  btb_get_linked_devices
 * DESCRIPTION
 *  This function is to get BTB linked devices
 * PARAMETERS
 *  
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 btb_get_linked_devices(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_cm_get_linked_dev_list_idx();
}


/*****************************************************************************
 * FUNCTION
 *  btb_link_is_full
 * DESCRIPTION
 *  This function is to check whether BTB link is full
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL btb_link_is_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (btb_get_linked_devices() >= __BT_MAX_LINK_NUM__ ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  btb_block
 * DESCRIPTION
 *  This function is to block/unblock BTB passive connection/disconnection
 * PARAMETERS
 *  block
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL btb_block(MMI_BOOL block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL prevent_flag = srv_bt_cm_get_prevent_connect_flag();
    S32 result = SRV_BT_CM_RESULT_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_LINE_IN__
    if (mmi_linein_is_plug_in() && !block)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]btb_block, can't unblock if line in is plug in!");
        return MMI_FALSE;
    }
    #endif  //__MMI_LINE_IN__
    
    if (block != prevent_flag)
    {
        result = srv_bt_cm_set_prevent_connect_flag(block);
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_BLOCK, block, prevent_flag, result, srv_bt_cm_get_state(), btb_get_state());

    if (!block && result == SRV_BT_CM_RESULT_SUCCESS)
    {//turn off visibility after 60s
        srv_bt_cm_restart_temp_visibility_timer();
    }
    
    return (result == SRV_BT_CM_RESULT_SUCCESS ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  btb_a2dp_is_connected_ex
 * DESCRIPTION
 *  This function is to check if XXX BT's A2DP and AVRCP is connected
 * PARAMETERS
 *  dev_addr		[IN]		the profile related dev_addr
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
static MMI_BOOL btb_a2dp_is_connected_ex(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) && srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_a2dp_is_connected
 * DESCRIPTION
 *  This function is to check if XXX BT's A2DP and AVRCP is connected
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
static MMI_BOOL btb_a2dp_is_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) && srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CT_CONNECTION))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_a2dp_is_disconnected_ex
 * DESCRIPTION
 *  This function is to check if XXX BT's A2DP and AVRCP is disconnected
 * PARAMETERS
 *  dev_addr		[IN]		the profile related dev_addr
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
static MMI_BOOL btb_a2dp_is_disconnected_ex(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) || srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_a2dp_is_disconnected
 * DESCRIPTION
 *  This function is to check if XXX BT's A2DP and AVRCP is disconnected
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
static MMI_BOOL btb_a2dp_is_disconnected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CT_CONNECTION))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_is_connected_ex
 * DESCRIPTION
 *  This function is to check if XXX BT is connected
 * PARAMETERS
 *  dev_addr		[IN]		the profile related dev_addr
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
static MMI_BOOL btb_is_connected_ex(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) && srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr)) ||
        srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_is_connected
 * DESCRIPTION
 *  This function is to check if XXX BT is connected
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
static MMI_BOOL btb_is_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) && srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CT_CONNECTION)) ||
        srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_is_disconnected_ex
 * DESCRIPTION
 *  This function is to check if XXX BT is disconnected
 * PARAMETERS
 *  dev_addr		[IN]		the profile related dev_addr
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is disconnected
 *                      FALSE : the profile is not disconnected
 *****************************************************************************/
static MMI_BOOL btb_is_disconnected_ex(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr) ||
        srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) ||
        srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_is_disconnected
 * DESCRIPTION
 *  This function is to check if XXX BT is disconnected
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  MMI_BOOL            TRUE : the BT is disconnected
 *                      FALSE : the profile is not disconnected
 *****************************************************************************/
static MMI_BOOL btb_is_disconnected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION) ||
        srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) ||
        srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CT_CONNECTION))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  btb_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 event_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(btb_cm_profile_init_tbl) / sizeof(FuncPtr)); i++)
    {
        if (btb_cm_profile_init_tbl[i])
        {
            (*btb_cm_profile_init_tbl[i])();
        }
    }

    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    //#ifdef __MMI_BT_DIALER_SUPPORT__
    mmi_bt_dialer_enhanced_init();
    #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    
    #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    mmi_bt_anti_lost_init();
    #endif  //__MMI_BT_ANTI_LOST_BY_RSSI__
    
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
                 
                #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
                #if (__BT_MAX_LINK_NUM__ > 1)
                 SRV_BT_CM_EVENT_LINK_STATE_IND |
                #else  //(__BT_MAX_LINK_NUM__ > 1)
                 SRV_BT_CM_EVENT_FAIL_CONN_TO |
                #endif  //(__BT_MAX_LINK_NUM__ > 1)
                #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
    
    g_btb_context.handle = srv_bt_cm_set_notify((srv_bt_cm_notifier)btb_event_notify_handle, event_mask, NULL);
    btb_set_state(BTB_STATE_IDLE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INIT, g_btb_context.handle);

}


/*****************************************************************************
 * FUNCTION
 *  btb_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < (sizeof(btb_cm_profile_deinit_tbl) / sizeof(FuncPtr)); i++)
    {
        if (btb_cm_profile_deinit_tbl[i])
        {
            (*btb_cm_profile_deinit_tbl[i])();
        }
    }

    srv_bt_cm_reset_notify(g_btb_context.handle);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DEINIT, g_btb_context.handle);

}


/*****************************************************************************
 * FUNCTION
 *  btb_enable
 * DESCRIPTION
 *  This function is BTBox enable BT function
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_STATE_CHANGE, 0);
    if (btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE))
    {
        btb_set_state(BTB_STATE_IDLE);
        btb_block(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_disable
 * DESCRIPTION
 *  This function is BTBox disable BT function
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_STATE_CHANGE, 1);

    if (btb_is_available(MMI_FALSE, MMI_FALSE, MMI_FALSE))
    {
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_RESETTING);
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTED);
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_DISCONNECTED);
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_VISIBILITY_ON_LED);
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_SINK_CONNECTED);
        btb_reset(MMI_TRUE);
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
/* under construction !*/
#endif

    
/*****************************************************************************
 * FUNCTION
 *  btb_connect_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_connect_ext(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_EXT,
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff));

    #ifdef __MMI_BTB_APPLICATION_BQB__
    mmi_bt_dialor_connect(dev_addr);
    #else  //__MMI_BTB_APPLICATION_BQB__
    mmi_bt_dialer_connect_a2dp_src(dev_addr, NULL);
    #endif  //__MMI_BTB_APPLICATION_BQB__
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect_ext
 * DESCRIPTION
 *  This function is BTBox disconnect function
 * PARAMETERS
 *  srv_bt_cm_bt_addr* dev_addr
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_disconnect_ext(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_dev_in_link_table(dev_addr))
    {
        mmi_bt_dialor_disconnect((srv_bt_cm_bt_addr*)dev_addr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_turn_on_visibility
 * DESCRIPTION
 *  only slave or idle box can turn on visibility, master will always on unless it has two links.
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void btb_turn_on_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_TEMPORARY_ON);
    mmi_frm_input_event_notify(NOTIFY_ID_BT_VISIBILITY_ON, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  btb_turn_off_visibility
 * DESCRIPTION
 *  master visibility cannot be turn off, it will turn off itself when it has two links.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_turn_off_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_OFF);
    mmi_frm_input_event_notify(NOTIFY_ID_BT_VISIBILITY_OFF, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  btb_change_visibility
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_change_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE) || btb_link_is_full()
        #if (__BT_MAX_LINK_NUM__ > 1)
        || srv_bt_cm_get_box_role() == SRV_BT_CM_BOX_ROLE_SLAVE
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
        )
    {
        mmi_frm_input_event_notify(NOTIFY_ID_BT_OPERATION_FAIL, NULL);
        return;
    }
    if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_OFF)
    {
        btb_turn_on_visibility();
    }
    else
    {
        btb_turn_off_visibility();
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_reset_int
 * DESCRIPTION
 *  reset BT.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_reset_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, index;
    U32 linked_devices = btb_get_linked_devices();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_RESET_INT, btb_get_state(), linked_devices);
    
    if (linked_devices > 0)
    {
        const srv_bt_cm_dev_struct *dev_info = srv_bt_cm_get_linked_dev_info(0);
        if (dev_info)
        {
            btb_disconnect_ext((const srv_bt_cm_bt_addr *)&dev_info->bd_addr);
        }
        else
        {
            kal_prompt_trace(MOD_MMI, "[BTB]btb_reset_int, get linked dev info fail");
        }
    }
    else
    {
        if (g_btb_context.reset_by_linein)
        {//line in plug in resetting needn't to clear pair info
            btb_set_state(BTB_STATE_IDLE);
        }
        else
        {
            S32 result = srv_bt_cm_dev_del_all();
            kal_prompt_trace(MOD_MMI, "[BTB]btb_reset_int, del_all_result=%d,linked_devices=%d", result, linked_devices);
            mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_RESETTING);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_reset
 * DESCRIPTION
 *  reset BT.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_reset(MMI_BOOL reset_by_linein)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BTB]btb_reset");
    if (!reset_by_linein && !btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE))
    {
        mmi_frm_input_event_notify(NOTIFY_ID_BT_OPERATION_FAIL, NULL);
    }
    else
    {
        #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        mmi_bt_dialer_auto_reconn_reset();
        #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        
        #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
        mmi_bt_anti_lost_screen_close();
        #endif  //__MMI_BT_ANTI_LOST_BY_RSSI__
        
        g_btb_context.reset_by_linein = reset_by_linein;
        btb_set_state(BTB_STATE_RESETTING);
        if (!g_btb_context.reset_by_linein)
        {
            mmi_frm_input_event_notify(NOTIFY_ID_BT_RESETTING, NULL);
        }
        if (!btb_block(MMI_TRUE))
        {
            btb_reset_int();
        }
    }
}


#if (__BT_MAX_LINK_NUM__ > 1)

void btb_inquiry_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    av_bt_inquiry_start_callback();

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_search(
            SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
            BTB_INQUIRY_TIMEOUT_DURATION,
            BTB_INQUIRY_COD,
            MMI_TRUE))
    {
        kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_dev, start searching");
    }
    else
    {
        av_bt_inquiry_stop_callback();
        kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_dev, search fail");
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
        mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
        btb_set_state(BTB_STATE_IDLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_inquiry_result_notify
 * DESCRIPTION
 *  This function is to handle inquiry result
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_inquiry_result_notify(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 discoveried_dev_counter = srv_bt_cm_get_searched_dev_num();
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (discoveried_dev_counter > 0 && btb_is_available(MMI_FALSE, MMI_FALSE, MMI_TRUE) && btb_get_state() == BTB_STATE_ACTIVE_CONNECTING && !btb_link_is_full())
    {
        for (i = 0; i < discoveried_dev_counter; i++)
        {
            srv_bt_cm_dev_struct *discov_dev_p = srv_bt_cm_get_searched_dev_info(i);
            if (discov_dev_p)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INQUIRY_NOTIFY, 0, i, discov_dev_p->cod, 
                    ((discov_dev_p->bd_addr.nap & 0xff00) >> 8),
                    (discov_dev_p->bd_addr.nap & 0x00ff),
                    (discov_dev_p->bd_addr.uap),
                    ((discov_dev_p->bd_addr.lap & 0xff0000) >> 16),
                    ((discov_dev_p->bd_addr.lap & 0x00ff00) >> 8),
                    (discov_dev_p->bd_addr.lap & 0x0000ff),
                    srv_bt_cm_is_box_ext(discov_dev_p->cod, discov_dev_p->name),
                    discov_dev_p->name[0], discov_dev_p->name[1], discov_dev_p->name[2], discov_dev_p->name[3], btb_get_state());
                
                if (srv_bt_cm_is_box_ext(discov_dev_p->cod, (U8*)(discov_dev_p->name)) && !srv_bt_cm_is_master_box(discov_dev_p->cod, (U8*)(discov_dev_p->name)))
                {
                    kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_result_notify, it is Box, abort searching,BT_state=%d", srv_bt_cm_get_state());
                    srv_bt_cm_search_abort();
                    break;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_inquiry_complete
 * DESCRIPTION
 *  This function is to handle inquiry complete
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_inquiry_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 discoveried_dev_counter = srv_bt_cm_get_searched_dev_num();
    U8 i = 0;
    srv_bt_cm_inquiry_complete_struct *event = (srv_bt_cm_inquiry_complete_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (discoveried_dev_counter > 0 && btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE) && btb_get_state() == BTB_STATE_ACTIVE_CONNECTING && !btb_link_is_full())
    {
        for (i = 0; i < discoveried_dev_counter; i++)
        {
            srv_bt_cm_dev_struct *discov_dev_p = srv_bt_cm_get_searched_dev_info(i);
            if (discov_dev_p)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INQUIRY_NOTIFY, 1, i, discov_dev_p->cod,                     
                    ((discov_dev_p->bd_addr.nap & 0xff00) >> 8),
                    (discov_dev_p->bd_addr.nap & 0x00ff),
                    (discov_dev_p->bd_addr.uap),
                    ((discov_dev_p->bd_addr.lap & 0xff0000) >> 16),
                    ((discov_dev_p->bd_addr.lap & 0x00ff00) >> 8),
                    (discov_dev_p->bd_addr.lap & 0x0000ff),
                    srv_bt_cm_is_box_ext(discov_dev_p->cod, discov_dev_p->name),
                    discov_dev_p->name[0], discov_dev_p->name[1], discov_dev_p->name[2], discov_dev_p->name[3], btb_get_state());
                
                if (srv_bt_cm_is_box_ext(discov_dev_p->cod, (U8*)(discov_dev_p->name)) && !srv_bt_cm_is_master_box(discov_dev_p->cod, (U8*)(discov_dev_p->name)) &&
                    !btb_is_connected_ex((const srv_bt_cm_bt_addr*)&(discov_dev_p->bd_addr)))
                {
                    kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_complete, it is Box, connecting");
                    //btb_connect_ext(&discov_dev_p->bd_addr);
                    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_bond(i))
                    {
                        return;
                    }
                    break;
                }
            }
        }
    }
    
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
    mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
    btb_set_state(BTB_STATE_IDLE);

}


/*****************************************************************************
 * FUNCTION
 *  btb_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE) || btb_link_is_full() || btb_quiry_source_role(&index))
    {
        mmi_frm_input_event_notify(NOTIFY_ID_BT_OPERATION_FAIL, NULL);
        return;
    }
    
    btb_set_state(BTB_STATE_ACTIVE_CONNECTING);
    //btb_inquiry_dev();  //call after set prevent flag
    mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTING, NULL);

    if (!btb_block(MMI_TRUE))
    {
        btb_inquiry_dev();
    }
}

#endif  //(__BT_MAX_LINK_NUM__ > 1)


/*****************************************************************************
 * FUNCTION
 *  btb_connection_verify
 * DESCRIPTION
 *  This function is verify whether both A2DP and AVRCP connected/disconnected
 * PARAMETERS
 *  dev_addr
 *  is_connect
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL btb_connection_verify(const srv_bt_cm_bt_addr* dev_addr, MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BTB]btb_connection_verify, A2DP=%d,AVRCP=%d", srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr), srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr));
    if (is_connect)
    {
        if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) && !srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))
        {
            const mmi_bt_dialer_conn_callback_item *callback_item = mmi_bt_dialer_next_callback_item((srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_HF_CONNECTION, MMI_FALSE, MMI_FALSE);
            if (srv_bt_cm_get_busy_dev() == NULL &&
                (callback_item != NULL) && 
                (callback_item->indx != 0xFF))
            {
                mmi_bt_dialer_set_disconn_req(MMI_TRUE);
                callback_item->disconn((srv_bt_cm_bt_addr*)dev_addr, mmi_bt_dialor_callback);
            }
            kal_prompt_trace(MOD_MMI, "[BTB]A2DP connected but AVRCP is not connected");

            result = MMI_FALSE;
        }
        else if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr) && !srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
        {
            const mmi_bt_dialer_conn_callback_item *callback_item = mmi_bt_dialer_next_callback_item((srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_FALSE, MMI_FALSE);
            if (srv_bt_cm_get_busy_dev() == NULL &&
                (callback_item != NULL) && 
                (callback_item->indx != 0xFF))
            {
                mmi_bt_dialer_set_disconn_req(MMI_TRUE);
                callback_item->disconn((srv_bt_cm_bt_addr*)dev_addr, mmi_bt_dialor_callback);
            }
            kal_prompt_trace(MOD_MMI, "[BTB]AVRCP connected but A2DP is not connected");

            result = MMI_FALSE;
        }
    }
    else if (!btb_a2dp_is_disconnected_ex(dev_addr))
    {
        const mmi_bt_dialer_conn_callback_item *callback_item = mmi_bt_dialer_next_callback_item((srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_HF_CONNECTION, MMI_FALSE, MMI_FALSE);
        if (srv_bt_cm_get_busy_dev() == NULL &&
            (callback_item != NULL) && 
            (callback_item->indx != 0xFF))
        {
            mmi_bt_dialer_set_disconn_req(MMI_TRUE);
            callback_item->disconn((srv_bt_cm_bt_addr*)dev_addr, mmi_bt_dialor_callback);
        }
        kal_prompt_trace(MOD_MMI, "[BTB]need to disconnect leaving profile, A2DP=%d,AVRCP=%d", srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr), srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr));
        result = MMI_FALSE;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECTION_VERIFY, 
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        is_connect, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  btb_set_name_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_set_name_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_name_struct *event = (srv_bt_cm_set_name_struct *)para;
    U32 linked_devices = btb_get_linked_devices();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_SET_NAME_COMPLETE, event->result, linked_devices, srv_bt_cm_get_prevent_connect_flag(), srv_bt_cm_get_state(), btb_get_state());

    if (linked_devices == 0 && btb_is_available(MMI_FALSE, MMI_TRUE, MMI_FALSE) && btb_get_state() == BTB_STATE_RESETTING)
    {
        if (g_btb_context.reset_by_linein)
        {//line in plug in resetting needn't to clear pair info
            btb_set_state(BTB_STATE_IDLE);
        }
        else
        {
            S32 result = srv_bt_cm_dev_del_all();
            kal_prompt_trace(MOD_MMI, "[BTB]btb_set_name_complete, del_all_result=%d, BT_state=%d", result, srv_bt_cm_get_state());
        }
        g_btb_context.reset_by_linein = MMI_FALSE;
    }
    
    if (!btb_link_is_full() && btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE))
    {
        btb_block(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_set_visibility_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_set_visibility_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_visibility_struct *event = (srv_bt_cm_set_visibility_struct *)para; 
    //U32 linked_devices = btb_get_linked_devices();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_SET_VISIBILITY_COMPLETE, event->is_from_mmi, event->result);

    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_VISIBILITY_ON_LED);
    if (srv_bt_cm_get_visibility() != SRV_BT_CM_VISIBILITY_OFF)
    {
        mmi_frm_input_event_notify(NOTIFY_ID_BT_VISIBILITY_ON_LED, NULL);
    }

    #ifdef __MMI_LINE_IN__
    if (mmi_linein_is_plug_in())
    {
        if (g_btb_context.reset_by_linein && btb_is_available(MMI_FALSE, MMI_TRUE, MMI_FALSE) && btb_get_state() == BTB_STATE_RESETTING)
        {
            btb_reset_int();
        }
        else
        {
            btb_set_state(BTB_STATE_IDLE);
        }
        return;
    }
    #endif  //__MMI_LINE_IN__
    
    if (!btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE))
    {
        kal_prompt_trace(MOD_MMI, "[BTB]btb_set_visibility_complete, sth wrong");
        if (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING)
        {
            mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
            mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
        }
        btb_set_state(BTB_STATE_IDLE);
        return;
    }

    if (btb_get_state() == BTB_STATE_IDLE)
    {
    }
    #if (__BT_MAX_LINK_NUM__ > 1)
    else if (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING)
    {
        btb_inquiry_dev();
    }
    #endif  //(__BT_MAX_LINK_NUM__ > 1)
    else if (btb_get_state() == BTB_STATE_ACTIVE_DISCONNECTING)
    {
        btb_disconnect_ext((const srv_bt_cm_bt_addr*)&g_btb_context.opt_after_set_visibility.bd_addr);
    }
    else if (btb_get_state() == BTB_STATE_PASSIVE_CONNECTING)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]BTB_STATE_PASSIVE_CONNECTING, addr=[0x%02x:%02x:%02x:%02x:%02x:%02x],result=%d,is_connect=%d,callback_item=%x",
                ((g_btb_context.opt_after_set_visibility.bd_addr.nap & 0xff00) >> 8),
                (g_btb_context.opt_after_set_visibility.bd_addr.nap & 0x00ff),
                (g_btb_context.opt_after_set_visibility.bd_addr.uap),
                ((g_btb_context.opt_after_set_visibility.bd_addr.lap & 0xff0000) >> 16),
                ((g_btb_context.opt_after_set_visibility.bd_addr.lap & 0x00ff00) >> 8),
                (g_btb_context.opt_after_set_visibility.bd_addr.lap & 0x0000ff),
                g_btb_context.opt_after_set_visibility.result,
                g_btb_context.opt_after_set_visibility.is_connect,
                g_btb_context.opt_after_set_visibility.callback_item);
        mmi_bt_dialor_callback_int(&g_btb_context.opt_after_set_visibility.bd_addr, g_btb_context.opt_after_set_visibility.result,
            g_btb_context.opt_after_set_visibility.is_connect, &g_btb_context.opt_after_set_visibility.callback_item);
    }
    else if (btb_get_state() == BTB_STATE_PASSIVE_DISCONNECTING)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]BTB_STATE_PASSIVE_DISCONNECTING, addr=[0x%02x:%02x:%02x:%02x:%02x:%02x],result=%d,is_connect=%d,callback_item=%x",
                ((g_btb_context.opt_after_set_visibility.bd_addr.nap & 0xff00) >> 8),
                (g_btb_context.opt_after_set_visibility.bd_addr.nap & 0x00ff),
                (g_btb_context.opt_after_set_visibility.bd_addr.uap),
                ((g_btb_context.opt_after_set_visibility.bd_addr.lap & 0xff0000) >> 16),
                ((g_btb_context.opt_after_set_visibility.bd_addr.lap & 0x00ff00) >> 8),
                (g_btb_context.opt_after_set_visibility.bd_addr.lap & 0x0000ff),
                g_btb_context.opt_after_set_visibility.result,
                g_btb_context.opt_after_set_visibility.is_connect,
                g_btb_context.opt_after_set_visibility.callback_item);
        mmi_bt_dialor_callback_int(&g_btb_context.opt_after_set_visibility.bd_addr, g_btb_context.opt_after_set_visibility.result,
            g_btb_context.opt_after_set_visibility.is_connect, &g_btb_context.opt_after_set_visibility.callback_item);
    }
    else if (btb_get_state() == BTB_STATE_RESETTING)
    {
        btb_reset_int();
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect
 * DESCRIPTION
 *  disconnect source first.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, index;
    MMI_BOOL need_disconnect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    mmi_bt_dialer_auto_reconn_reset();
    #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    
    #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    mmi_bt_anti_lost_screen_close();
    #endif  //__MMI_BT_ANTI_LOST_BY_RSSI__

    if (!btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE))
    {
        kal_prompt_trace(MOD_MMI, "[BTB]btb_disconnect fail");
        mmi_frm_input_event_notify(NOTIFY_ID_BT_OPERATION_FAIL, NULL);
        return;
    }
    
    #if (__BT_MAX_LINK_NUM__ > 1)
    if (btb_quiry_sink_role(&index))
    {
        a2dp_dev_info_struct a2dp_dev_info = {0};
        srv_a2dp_get_dev_info_by_index(&a2dp_dev_info, index);
        kal_prompt_trace(MOD_MMI, "[BTB]BT device to be disconnected, addr:0x%02x:%02x:%02x:%02x:%02x:%02x",
                    ((a2dp_dev_info.address.nap & 0xff00) >> 8),
                    (a2dp_dev_info.address.nap & 0x00ff),
                    (a2dp_dev_info.address.uap),
                    ((a2dp_dev_info.address.lap & 0xff0000) >> 16),
                    ((a2dp_dev_info.address.lap & 0x00ff00) >> 8),
                    (a2dp_dev_info.address.lap & 0x0000ff));
        
        memcpy(&g_btb_context.opt_after_set_visibility.bd_addr, &(a2dp_dev_info.address), sizeof(srv_bt_cm_bt_addr));
        need_disconnect = MMI_TRUE;
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT, index);
    }
    else
    #endif  //(__BT_MAX_LINK_NUM__ > 1)
    {
        const srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_linked_dev_info(0);
        if (dev_p)
        {
            kal_prompt_trace(MOD_MMI, "[BTB]BT device to be disconnected 1, addr:0x%02x:%02x:%02x:%02x:%02x:%02x",
                        ((dev_p->bd_addr.nap & 0xff00) >> 8),
                        (dev_p->bd_addr.nap & 0x00ff),
                        (dev_p->bd_addr.uap),
                        ((dev_p->bd_addr.lap & 0xff0000) >> 16),
                        ((dev_p->bd_addr.lap & 0x00ff00) >> 8),
                        (dev_p->bd_addr.lap & 0x0000ff));
            memcpy(&g_btb_context.opt_after_set_visibility.bd_addr, &(dev_p->bd_addr), sizeof(srv_bt_cm_bt_addr));
            need_disconnect = MMI_TRUE;
        }
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT, -1);
    }

    if (need_disconnect)
    {        
        btb_set_state(BTB_STATE_ACTIVE_DISCONNECTING);
        g_btb_context.opt_after_set_visibility.is_connect = MMI_FALSE;
        if (!btb_block(MMI_TRUE))
        {
            btb_disconnect_ext((const srv_bt_cm_bt_addr*)&g_btb_context.opt_after_set_visibility.bd_addr);
        }
    }
    else
    {
        mmi_frm_input_event_notify(NOTIFY_ID_BT_OPERATION_FAIL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_connected_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result
 *  
 * RETURNS
 *  srv_prof_ret
 *****************************************************************************/
static srv_prof_ret btb_connected_notify_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_NOTIFY_CALLBACK, 0, result);

    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnected_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result
 *  
 * RETURNS
 *  srv_prof_ret
 *****************************************************************************/
static srv_prof_ret btb_disconnected_notify_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_NOTIFY_CALLBACK, 1, result);

    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  btb_connect_success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_connect_success(const srv_bt_cm_bt_addr* dev_addr, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 linked_devices;
    U8 index;
    MMI_BOOL found = MMI_FALSE;
    MMI_BOOL need_notify = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btb_is_connected_ex(dev_addr))
    {
        srv_bt_cm_set_dev_link_state((srv_bt_cm_bt_addr *)dev_addr, MMI_TRUE);
    }
    linked_devices = btb_get_linked_devices();
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_SUCCESS, 
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff),
                    btb_get_state(), linked_devices,
                    #if (__BT_MAX_LINK_NUM__ > 1)
                    srv_bt_cm_get_box_role(),
                    #else  //(__BT_MAX_LINK_NUM__ > 1)
                    0,
                    #endif  //(__BT_MAX_LINK_NUM__ > 1)
                    result);
    
    g_btb_context.hf_connect = MMI_FALSE;
    g_btb_context.a2dp_connect = MMI_FALSE;
    g_btb_context.avrcp_connect = MMI_FALSE;
    g_btb_context.hf_disconnect = MMI_FALSE;
    g_btb_context.a2dp_disconnect = MMI_FALSE;
    g_btb_context.avrcp_disconnect = MMI_FALSE;
    
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
    memset(&g_btb_context.opt_after_set_visibility, 0, sizeof(btb_opt_after_set_visibility_struct));
    
    if (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING && !result)
    {
        mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
        return;
    }
    
    #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    mmi_bt_anti_lost_screen_close();
    #endif  /* __MMI_BT_ANTI_LOST_BY_RSSI__ */

    if (!btb_connection_verify(dev_addr, MMI_TRUE) && !btb_is_connected_ex(dev_addr))
    {
        if (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING)
        {
            mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
        }
        return;
    }
    
    if (btb_get_state() == BTB_STATE_ACTIVE_DISCONNECTING || btb_get_state() == BTB_STATE_PASSIVE_DISCONNECTING || btb_get_state() == BTB_STATE_RESETTING)
    {
        //connect in disconnecting state, needn't notify
        need_notify = MMI_FALSE;
    }
    btb_set_state(BTB_STATE_IDLE);
    
    if (btb_is_connected_ex(dev_addr))
    {
        #if (__BT_MAX_LINK_NUM__ > 1)
        if (srv_bt_cm_is_box(dev_addr))
        {//Box connecting
            found = btb_quiry_source_role(&index);
            kal_prompt_trace(MOD_MMI, "[BTB]found source=%d,index=%d", found, index);
            if (found)
            {
                srv_bt_cm_set_box_role(SRV_BT_CM_BOX_ROLE_MASTER);
            }
            else
            {
                found = btb_quiry_sink_role(&index);
                kal_prompt_trace(MOD_MMI, "[BTB]found sink=%d,index=%d", found, index);
                if (found)
                {        
                    srv_bt_cm_set_box_role(SRV_BT_CM_BOX_ROLE_SLAVE);
                    btb_block(MMI_TRUE);
                }
            }
            kal_prompt_trace(MOD_MMI, "[BTB]Connection between Boxes");
        }
        else
        {//SP connecting
            if (srv_bt_cm_get_box_role() == SRV_BT_CM_BOX_ROLE_SLAVE)
            {//slave cannot connect to SP
                kal_prompt_trace(MOD_MMI, "[BTB]slave cannot connect to SP");
                btb_disconnect_ext(dev_addr);
                return;
            }
            else
            {//the first one connect to SP will be master
                kal_prompt_trace(MOD_MMI, "[BTB]the first one connect to SP will be master");
                srv_bt_cm_set_box_role(SRV_BT_CM_BOX_ROLE_MASTER);
            }
        }
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
        
        if (btb_link_is_full())
        {
            //link is full, prevent connect
            if (btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE))
            {
                btb_block(MMI_TRUE);
            }
        }
        #if (__BT_MAX_LINK_NUM__ > 1)
        else if (srv_bt_cm_get_box_role() != SRV_BT_CM_BOX_ROLE_SLAVE)
        {
            if (btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE))
            {
                btb_block(MMI_FALSE);
            }
        }
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
    }
    
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_SINK_CONNECTED);
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTED);
    
    if (need_notify && btb_is_connected_ex(dev_addr)
        #ifdef __MMI_LINE_IN__
        && !mmi_linein_is_plug_in()
        #endif  //__MMI_LINE_IN__
        )
    {
        mmi_input_event_notify_param notify_param = {0};
        notify_param.aud_cb = btb_connected_notify_callback;

        #if (__BT_MAX_LINK_NUM__ > 1)
        found = btb_quiry_sink_role(&index);
        if (found)
        {
            mmi_frm_input_event_notify(NOTIFY_ID_BT_SINK_CONNECTED, &notify_param);
        }
        else
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
        {
            mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTED, &notify_param);
        }
    }

    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
    {//post A2DP connected
        btb_post_event(EVT_ID_BTB_A2DP_CONNECTED);
    }

#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    mmi_bt_dialer_set_pre_autoreconn_addr((srv_bt_cm_bt_addr*)dev_addr);
#endif
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    if(!mmi_bt_anti_lost_is_in_list((srv_bt_cm_bt_addr*)dev_addr))//if have not eisted in anti-lost list,so do it.
    {
        mmi_bt_anti_lost_enable_req((srv_bt_cm_bt_addr*)dev_addr, MMI_TRUE);
    }
    // add this device to anti-lost list.
    mmi_bt_anti_lost_add_addr((srv_bt_cm_bt_addr*)dev_addr);
#endif/*__MMI_BT_ANTI_LOST_BY_RSSI__*/
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect_success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_disconnect_success(const srv_bt_cm_bt_addr* dev_addr, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 linked_devices;
    //the second SP will connect HF and AVRCP, and later will disconnect AVRCP, or if user only choose HF to connect, we will connect A2DP and AVRCP, and AVRCP will connect success, and later AVRCP will be disconnect.
    MMI_BOOL need_notify = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btb_is_disconnected_ex(dev_addr))
    {
        srv_bt_cm_set_dev_link_state((srv_bt_cm_bt_addr *)dev_addr, MMI_FALSE);
    }
    linked_devices = btb_get_linked_devices();
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT_SUCCESS, 
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff),
                    btb_get_state(), linked_devices,
                    #if (__BT_MAX_LINK_NUM__ > 1)
                    srv_bt_cm_get_box_role(),
                    #else  //(__BT_MAX_LINK_NUM__ > 1)
                    0,
                    #endif  //(__BT_MAX_LINK_NUM__ > 1)
                    result);
    
    g_btb_context.hf_connect = MMI_FALSE;
    g_btb_context.a2dp_connect = MMI_FALSE;
    g_btb_context.avrcp_connect = MMI_FALSE;
    g_btb_context.hf_disconnect = MMI_FALSE;
    g_btb_context.a2dp_disconnect = MMI_FALSE;
    g_btb_context.avrcp_disconnect = MMI_FALSE;    

    memset(&g_btb_context.opt_after_set_visibility, 0, sizeof(btb_opt_after_set_visibility_struct));
    
    if (!btb_connection_verify(dev_addr, MMI_FALSE))
    {
        return;
    }

    if (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING || btb_get_state() == BTB_STATE_PASSIVE_CONNECTING || btb_get_state() == BTB_STATE_RECONNECTING)
    {
        //disconnect in connecting state, needn't notify
        need_notify = MMI_FALSE;
    }
    if (btb_get_state() != BTB_STATE_RESETTING)
    {
        btb_set_state(BTB_STATE_IDLE);
    }
    
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTED);
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_SINK_CONNECTED);
    
    //notify
    if (need_notify && btb_is_disconnected_ex(dev_addr)
        #ifdef __MMI_LINE_IN__
        && !mmi_linein_is_plug_in()
        #endif  //__MMI_LINE_IN__
        )
    {
        mmi_input_event_notify_param notify_param = {0};
        notify_param.aud_cb = btb_disconnected_notify_callback;
        
        mmi_frm_input_event_notify(NOTIFY_ID_BT_DISCONNECTED, &notify_param);
    }
    
    if (!srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
    {//post A2DP disconnected event
        btb_post_event(EVT_ID_BTB_A2DP_DISCONNECTED);
    }
    
    if (linked_devices == 0)
    {
        #if (__BT_MAX_LINK_NUM__ > 1)
        srv_bt_cm_box_role pre_role = srv_bt_cm_get_box_role();        
        srv_bt_cm_set_box_role(SRV_BT_CM_BOX_ROLE_NONE);
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
        
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTED);
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_RESETTING);

        #if (__BT_MAX_LINK_NUM__ > 1)
        if (pre_role != SRV_BT_CM_BOX_ROLE_MASTER)
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
        {//not master needn't to change name, so do the following directly
            if (btb_is_available(MMI_FALSE, MMI_TRUE, MMI_FALSE) && btb_get_state() == BTB_STATE_RESETTING)
            {
                if (g_btb_context.reset_by_linein)
                {//line in plug in resetting needn't to clear pair info
                    btb_set_state(BTB_STATE_IDLE);
                }
                else
                {
                    S32 result = srv_bt_cm_dev_del_all();
                    kal_prompt_trace(MOD_MMI, "[BTB]btb_disconnect_success, del_all_result=%d,linked_devices=%d", result, linked_devices);
                }
            }
            g_btb_context.reset_by_linein = MMI_FALSE;
        }
    }
    #if (__BT_MAX_LINK_NUM__ > 1)
    else
    {
        U8 index = 0;
        MMI_BOOL found = MMI_FALSE;
        found = btb_quiry_sink_role(&index);
        mmi_frm_input_event_disable_notify();
        if (found)
        {
            mmi_frm_input_event_notify(NOTIFY_ID_BT_SINK_CONNECTED, NULL);
        }
        else
        {
            mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTED, NULL);  
        }          
        mmi_frm_input_event_enable_notify();

        if (linked_devices == 1)
        {
            if (btb_get_state() == BTB_STATE_RESETTING)
            {
                if (btb_is_disconnected_ex(dev_addr))
                {
                    const srv_bt_cm_dev_struct *dev_info = srv_bt_cm_get_linked_dev_info(0);
                    if (dev_info)
                    {
                        btb_disconnect_ext((const srv_bt_cm_bt_addr *)&dev_info->bd_addr);
                    }
                }
            }
        }
    }
    #endif  //(__BT_MAX_LINK_NUM__ > 1)

    if (!btb_link_is_full() && btb_is_available(MMI_TRUE, MMI_TRUE, MMI_FALSE))
    {
        #ifdef __MMI_LINE_IN__
        if (mmi_linein_is_plug_in())
        {
            btb_block(MMI_TRUE);
        }
        else
        #endif  //__MMI_LINE_IN__
        {
            btb_block(MMI_FALSE);
        }
    }
}


//#define __BTB_TEST__
#ifdef __BTB_TEST__

/*****************************************************************************
 * FUNCTION
 *  btb_key_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_key_test(mmi_frm_key_evt_struct *key_evt)
{
    kal_prompt_trace(MOD_MMI, "[BTB]btb_key_test,key[%d,%d],BT power status=%d,visibility=%d,linked_devices=%d,BT service state=%d,state=%d", key_evt->key_code, key_evt->key_type, srv_bt_cm_get_power_status(), srv_bt_cm_get_visibility(), btb_get_linked_devices(), srv_bt_cm_get_state(), btb_get_state());
}

#endif  //__BTB_TEST__

/*****************************************************************************
 * FUNCTION
 *  btb_pair_ind
 * DESCRIPTION
 *  This function is to handle pair indicate
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_pair_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_ind_struct *event = (srv_bt_cm_pair_ind_struct *)para;
    kal_uint8 pin_size = 0;
    kal_uint8 *pin_code = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_PAIR_IND,
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));
}


/*****************************************************************************
 * FUNCTION
 *  btb_pair_res
 * DESCRIPTION
 *  This function is to handle pair response
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_pair_res(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_res_struct *event = (srv_bt_cm_pair_res_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_PAIR_RES, event->result,
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));
}


/*****************************************************************************
 * FUNCTION
 *  btb_bond_res
 * DESCRIPTION
 *  This function is to handle bond response
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_bond_res(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bond_res_struct *event = (srv_bt_cm_bond_res_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_BOND_RES, event->result,
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));

    if (event->result != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
        mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
        btb_set_state(BTB_STATE_IDLE);
        return;
    }
    
    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    mmi_bt_dialer_auto_reconn_reset();
    #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    
    if (btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE) && btb_get_state() == BTB_STATE_ACTIVE_CONNECTING)
    {
        btb_connect_ext(&(event->dev_addr));
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_security_user_confirm
 * DESCRIPTION
 *  This function is to handle pair confirm
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_security_user_confirm(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_security_user_confirm_struct *event = (srv_bt_cm_security_user_confirm_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_SECURITY_USER_CONFIRM, event->display_numeric,
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));
    kal_prompt_trace(MOD_MMI, "[BTB]dev_name=[%s],passcode=[%s]", event->dev_name, event->passcode);

    #ifdef __MMI_BT_SIMPLE_PAIR__
    srv_bt_cm_security_numeric_confirm(&(event->dev_addr), MMI_TRUE);
    #endif  //__MMI_BT_SIMPLE_PAIR__
}


/*****************************************************************************
 * FUNCTION
 *  btb_mydev_delete_complete
 * DESCRIPTION
 *  This function is to handle srv_bt_cm_del_all complete
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_mydev_delete_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_mydev_del_struct *event = (srv_bt_cm_mydev_del_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_MYDEV_DELETE_COMPLETE, event->result,
                    ((event->del_dev->bd_addr.nap & 0xff00) >> 8),
                    (event->del_dev->bd_addr.nap & 0x00ff),
                    (event->del_dev->bd_addr.uap),
                    ((event->del_dev->bd_addr.lap & 0xff0000) >> 16),
                    ((event->del_dev->bd_addr.lap & 0x00ff00) >> 8),
                    (event->del_dev->bd_addr.lap & 0x0000ff));
    kal_prompt_trace(MOD_MMI, "[BTB]delete dev_name=[%s],cod=[%d]", event->del_dev->name, event->del_dev->cod);
    
    mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_RESETTING);

    if (btb_get_state() == BTB_STATE_RESETTING && btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE))
    {
        btb_block(MMI_FALSE);
    }

    btb_set_state(BTB_STATE_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  btb_connect_res
 * DESCRIPTION
 *  This function is to handle connect response
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_connect_res(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_conn_res_struct *event = (srv_bt_cm_conn_res_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_RES, event->result, event->profile_id, btb_get_linked_devices(),
                    ((event->dev_addr->nap & 0xff00) >> 8),
                    (event->dev_addr->nap & 0x00ff),
                    (event->dev_addr->uap),
                    ((event->dev_addr->lap & 0xff0000) >> 16),
                    ((event->dev_addr->lap & 0x00ff00) >> 8),
                    (event->dev_addr->lap & 0x0000ff));

    kal_prompt_trace(MOD_MMI, "[BTB]btb_connect_res, BTstate=%d,BTBstate=%d", srv_bt_cm_get_state(), btb_get_state());
    
    #ifdef __MMI_LINE_IN__
    if (mmi_linein_is_plug_in())
    {
        kal_prompt_trace(MOD_MMI, "[BTB]there are still connection in line in mode, hf=%d,a2dp=%d,avrcp=%d.", srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION), srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION), srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CONNECTION));
        btb_reset(MMI_TRUE);
        return;
    }
    #endif  //__MMI_LINE_IN__

    #ifdef  __MMI_BTB_APPLICATION_BQB__
    if (event->profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID && srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, event->dev_addr))
    {//post A2DP connected
        btb_post_event(EVT_ID_BTB_A2DP_CONNECTED);
    }
    #endif  //__MMI_BTB_APPLICATION_BQB__
    
    if (btb_get_state() != BTB_STATE_ACTIVE_DISCONNECTING && btb_get_state() != BTB_STATE_PASSIVE_DISCONNECTING && btb_get_state() != BTB_STATE_RESETTING)
    {
        if (event->profile_id == SRV_BT_CM_HF_PROFILE_UUID)
        {
            if (!btb_a2dp_is_connected_ex((const srv_bt_cm_bt_addr*)event->dev_addr))
            {
                g_btb_context.hf_connect = MMI_TRUE;
            }
        }
        else if (event->profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
        {
            g_btb_context.a2dp_connect = MMI_TRUE;
        }
        else if (event->profile_id == SRV_BT_CM_AV_REMOTE_CONTROL_UUID)
        {
            g_btb_context.avrcp_connect = MMI_TRUE;
        }
        kal_prompt_trace(MOD_MMI, "[BTB]btb_connect_res, BT_state=%d,BTB_state=%d,hf=%d,a2dp=%d,avrcp=%d", srv_bt_cm_get_state(), btb_get_state(),
            g_btb_context.hf_connect, g_btb_context.a2dp_connect, g_btb_context.avrcp_connect);
        
        if ((
            #if (__BT_MAX_LINK_NUM__ > 1)
            !srv_bt_cm_is_box((const srv_bt_cm_bt_addr*)event->dev_addr) && 
            #endif  //(__BT_MAX_LINK_NUM__ > 1)
            g_btb_context.hf_connect && btb_a2dp_is_connected()) ||
            (g_btb_context.a2dp_connect && g_btb_context.avrcp_connect) || btb_a2dp_is_connected_ex((const srv_bt_cm_bt_addr*)event->dev_addr))
        {
            btb_connect_success((const srv_bt_cm_bt_addr*)event->dev_addr, (event->result == SRV_BT_CM_RESULT_SUCCESS ? MMI_TRUE : MMI_FALSE));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect_ind
 * DESCRIPTION
 *  This function is to handle disconnect indicate
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_disconnect_ind(void *para)
{// TODO: mmi_a2dp_reset_dev_info will make more A2DP DISCONNECT IND when disconnect
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_disconnect_ind_struct *event = (srv_bt_cm_disconnect_ind_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT_IND, event->profile_id, event->passive, btb_get_linked_devices(),
                    ((event->dev_addr->nap & 0xff00) >> 8),
                    (event->dev_addr->nap & 0x00ff),
                    (event->dev_addr->uap),
                    ((event->dev_addr->lap & 0xff0000) >> 16),
                    ((event->dev_addr->lap & 0x00ff00) >> 8),
                    (event->dev_addr->lap & 0x0000ff));

    kal_prompt_trace(MOD_MMI, "[BTB]btb_disconnect_ind, BTstate=%d,BTBstate=%d", srv_bt_cm_get_state(), btb_get_state());
    
    #ifdef  __MMI_BTB_APPLICATION_BQB__
    if (event->profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID && !srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, event->dev_addr))
    {//post A2DP disconnected
        btb_post_event(EVT_ID_BTB_A2DP_DISCONNECTED);
    }
    #endif  //__MMI_BTB_APPLICATION_BQB__
    
    //if (btb_get_state() != BTB_STATE_ACTIVE_CONNECTING && btb_get_state() != BTB_STATE_PASSIVE_CONNECTING && btb_get_state() != BTB_STATE_RECONNECTING)
    {
        if (event->profile_id == SRV_BT_CM_HF_PROFILE_UUID)
        {
            g_btb_context.hf_disconnect = MMI_TRUE;
        }
        else if (event->profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
        {
            g_btb_context.a2dp_disconnect = MMI_TRUE;
        }
        else if (event->profile_id == SRV_BT_CM_AV_REMOTE_CONTROL_UUID)
        {
            g_btb_context.avrcp_disconnect = MMI_TRUE;
        }
        kal_prompt_trace(MOD_MMI, "[BTB]btb_disconnect_ind, BTstate=%d,BTBstate=%d,hf=%d,a2dp=%d,avrcp=%d", srv_bt_cm_get_state(), btb_get_state(),
            g_btb_context.hf_disconnect, g_btb_context.a2dp_disconnect, g_btb_context.avrcp_disconnect);
        
        if ((
            #if (__BT_MAX_LINK_NUM__ > 1)
            !srv_bt_cm_is_box((const srv_bt_cm_bt_addr*)event->dev_addr) && 
            #endif  //(__BT_MAX_LINK_NUM__ > 1)
            g_btb_context.hf_disconnect && !btb_a2dp_is_connected_ex((const srv_bt_cm_bt_addr*)event->dev_addr)) ||
            (g_btb_context.a2dp_disconnect && g_btb_context.avrcp_disconnect) || btb_is_disconnected_ex((const srv_bt_cm_bt_addr*)event->dev_addr))
        {
            btb_disconnect_success((const srv_bt_cm_bt_addr*)event->dev_addr, MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_power_switch_on_complete
 * DESCRIPTION
 *  This function is to handle power switch on complete
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_power_switch_on_complete(void *para)   /* power switch rsp */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_activate_struct *event = (srv_bt_cm_activate_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_TRACKER, 0, event->result);
    /*
      * In BT power ON procedure, send BT connect cmd will set btb context state to inquiry, but BT stack won't response inquiry request
      * when BT powered on, send BT connect  request again,  BTB won't send inquiry to BT stack, and it leads that BT can't connect.
      * so need to reset state
      */

    btb_set_state(BTB_STATE_IDLE);

    if (btb_is_available(MMI_TRUE, MMI_TRUE, MMI_FALSE))
    {
        #if (__BT_MAX_LINK_NUM__ > 1)
        srv_bt_cm_set_box_role(SRV_BT_CM_BOX_ROLE_NONE);
        #endif  //(__BT_MAX_LINK_NUM__ > 1)

        #ifdef __MMI_LINE_IN__
        if(mmi_linein_is_plug_in())
        {
            //srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_DISALLOW_REQ, NULL, NULL);
            if (!srv_bt_cm_get_prevent_connect_flag())
            {
                S32 result = srv_bt_cm_set_prevent_connect_flag(MMI_TRUE);
                kal_prompt_trace(MOD_MMI, "[BTB]btb_power_switch_on_complete, srv_bt_cm_set_prevent_connect_flag[1,%d]", result);
            }
        }
        else
        #endif  //__MMI_LINE_IN__
        {
            srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_OFF);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_power_switch_off_complete
 * DESCRIPTION
 *  This function is to handle power switch off complete
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_power_switch_off_complete(void *para)  /* power switch rsp */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_deactivate_struct *event = (srv_bt_cm_deactivate_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_TRACKER, 1, event->result);
    
    #ifdef __MMI_BT_DIALER_SUPPORT__
    mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_DISCONN_EVENT_ID, NULL, MMI_TRUE);
    #endif  //__MMI_BT_DIALER_SUPPORT__
}


/*****************************************************************************
 * FUNCTION
 *  btb_panic_ind_post
 * DESCRIPTION
 *  This function is to handle BT abnormal restart
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_panic_ind_post(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_TRACKER, 2, 0);
    
    srv_bt_cm_recover_panic_req();    
    btb_deinit();
    btb_init();
}


/*****************************************************************************
 * FUNCTION
 *  btb_panic_ind
 * DESCRIPTION
 *  This function is to handle BT abnormal restart
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_panic_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_deactivate_struct *event = (srv_bt_cm_deactivate_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_TRACKER, 3, event->result);
    
    #ifdef __MMI_BT_AUDIO_SUPPORT__

    #ifdef __MMI_A2DP_SUPPORT__
    mmi_a2dp_bt_power_off_callback(MMI_TRUE);
    #endif  //__MMI_A2DP_SUPPORT__
    srv_btsco_reset(btb_panic_ind_post);

    #else  //__MMI_BT_AUDIO_SUPPORT__

    btb_panic_ind_post();
    
    #endif  //__MMI_BT_AUDIO_SUPPORT__
}


/*****************************************************************************
 * FUNCTION
 *  btb_pair_res
 * DESCRIPTION
 *  This function is to handle pair res
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_event_notify_handle(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_EVENT_NOTIFY, event);
    switch (event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE:
            btb_power_switch_on_complete(para);
            break;

        case SRV_BT_CM_EVENT_DEACTIVATE:
            btb_power_switch_off_complete(para);
            break;

        #if (__BT_MAX_LINK_NUM__ > 1)
        case SRV_BT_CM_EVENT_INQUIRY_IND:
            btb_inquiry_result_notify(para);
            break;

        case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
            btb_inquiry_complete(para);
            break;
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
        
        case SRV_BT_CM_EVENT_PAIR_IND:
            btb_pair_ind(para);
            break;

        case SRV_BT_CM_EVENT_PAIR_RES:
            btb_pair_res(para);
            break;

        case SRV_BT_CM_EVENT_BOND_RES:
            btb_bond_res(para);
            break;
            
        case SRV_BT_CM_EVENT_CONNECT_RES:
            btb_connect_res(para);
            break;

        case SRV_BT_CM_EVENT_DISCONNECT_IND:
            btb_disconnect_ind(para);
            break;

        case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
            break;

        case SRV_BT_CM_EVENT_SET_VISIBILITY:
            btb_set_visibility_complete(para);
            break;

        case SRV_BT_CM_EVENT_SET_NAME:
            btb_set_name_complete(para);
            break;

        case SRV_BT_CM_EVENT_SCO_IND:
            break;

        case SRV_BT_CM_EVENT_PANIC_IND:
            btb_panic_ind(para);
            break;

        case SRV_BT_CM_EVENT_BEGIN_ACTIVATE:
            break;
            
        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            break;

        case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
            btb_security_user_confirm(para);
            break;
            
        case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
            break;
            
        case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
            break;
            
        #if !defined(__MMI_BT_SLIM__)
        case SRV_BT_CM_EVENT_REFRESH_PROFILE:
            break;
        #endif  // !defined(__MMI_BT_SLIM__)

        #ifdef __MMI_BT_AUTHORIZE__
        case SRV_BT_CM_EVENT_SET_AUTHORIZE:
            break;
            
        case SRV_BT_CM_EVENT_UNBLOCK:
            break;
        #endif  // __MMI_BT_AUTHORIZE__

        #ifdef __MMI_SIMAP_SUPPORT__
        case SRV_BT_CM_EVENT_SET_SIMAP:
            break;
        #endif  // __MMI_SIMAP_SUPPORT__

        #ifdef __BT_AUTO_DETECT_SUPPORT__
        case SRV_BT_CM_EVENT_CHIP_DETECT:
            break;
        #endif  // __BT_AUTO_DETECT_SUPPORT__
        case SRV_BT_CM_EVENT_MYDEV_DEL:
            btb_mydev_delete_complete(para);
            break;
            
        case SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME:
            break;
            
        #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        #if (__BT_MAX_LINK_NUM__ > 1)
        case SRV_BT_CM_EVENT_LINK_STATE_IND:
        #else  //(__BT_MAX_LINK_NUM__ > 1)
        case SRV_BT_CM_EVENT_FAIL_CONN_TO:
        #endif  //(__BT_MAX_LINK_NUM__ > 1)
            mmi_bt_dialer_link_state_ind(para);
            break;
        #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret btb_event_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_EVENT_HDLR, event->evt_id);
    
    #ifdef __MMI_LINE_IN__
    if (mmi_linein_is_plug_in() &&
        (event->evt_id == EVT_ID_BTB_CHANGE_VISIBILITY || event->evt_id == EVT_ID_BTB_CONNECT ||
        event->evt_id == EVT_ID_BTB_DISCONNECT || event->evt_id == EVT_ID_BTB_RESET))
    {
        kal_prompt_trace(MOD_MMI, "[BTB]can operate when line in is plug in!");
        return MMI_RET_OK;
    }
    #endif  //__MMI_LINE_IN__
    
    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_COMPLETED:
            //btb_power_on();
            break;
            
        case EVT_ID_SRV_SHUTDOWN_NORMAL_START:
            //btb_power_off();
            break;
            
        case EVT_ID_BTB_CHANGE_VISIBILITY:
            btb_change_visibility();
            break;
            
        case EVT_ID_BTB_CONNECT:
            #if (__BT_MAX_LINK_NUM__ > 1)
            btb_connect();
            #endif  //(__BT_MAX_LINK_NUM__ > 1)
            break;
            
        case EVT_ID_BTB_DISCONNECT:
            btb_disconnect();
            break;

        case EVT_ID_BTB_RESET:
            btb_reset(MMI_FALSE);
            break;
            
        #ifdef __MMI_LINE_IN__
        case EVT_ID_GPIO_LINEIN_PLUG_IN:
            btb_disable();
            break;
        case EVT_ID_GPIO_LINEIN_PLUG_OUT:
            btb_enable();
            break;
        #endif  //__MMI_LINE_IN__
        #ifdef __BTB_TEST__
        case EVT_ID_PRE_KEY_EVT_ROUTING:
            btb_key_test((mmi_frm_key_evt_struct*)event);
            break;
        #endif  //__BTB_TEST__
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_is_dev_cod_match
 * DESCRIPTION
 *  This function is to check the matchness of cod mask
 *  For the device cod, it should be exactly match
 * PARAMETERS
 *  device_cod    the cod of the device
 *  specific_cod  the cod mask set
 * RETURNS
 *  MMI_BOOL      MMI_TRUE  the cod mask match
 *                MMI_FALSE otherwise
 *****************************************************************************/
MMI_BOOL mmi_bt_is_dev_cod_match(U32 device_cod, U32 specific_cod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL match = MMI_FALSE;
    U32 major_service = 0, major_device = 0, minor_device = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (specific_cod == 0xFFFFFFFF)
    {
        match = MMI_TRUE;
    }
    else if (specific_cod == MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK)
    {
        match = MMI_TRUE;
    }
    else
    {
        major_service = 0x00FFE000 & specific_cod;
        major_device = 0x00001F00 & specific_cod;
        minor_device = 0x000000FC & specific_cod;
        if ((major_service & device_cod) != 0)
        {
            if ((major_device == 0) && (minor_device == 0))
            {
                match = MMI_TRUE;
            }
            else if (((device_cod & 0x1F00) == major_device) && ((minor_device == 0) || ((device_cod & 0xFF) == minor_device)))
            {
                match = MMI_TRUE;
            }
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_DEV_COD_MATCH, device_cod, specific_cod, match);
    return match;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_time_out_flag
 * DESCRIPTION
 *  This function is for getting time page out flag.
 * PARAMETERS
 *  void 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_bt_dialer_get_time_out_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIME_OUT_FLAG, time_out_flag);
    return time_out_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_time_out_flag
 * DESCRIPTION
 *  This function is for setting time page out flag.
 * PARAMETERS
 *  MMI_BOOL 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_time_out_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_out_flag = flag;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIME_OUT_FLAG, time_out_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_disconn_req
 * DESCRIPTION
 *  This function is for setting disconnecting flag.
 * PARAMETERS
 *  MMI_BOOL req
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_set_disconn_req(MMI_BOOL req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_is_disconn_req = req;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_DISCONN_REQ_FLAG, g_mmi_is_disconn_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_disconn_req
 * DESCRIPTION
 *  This function is for getting disconnecting flag.
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  MMI_BOOL g_mmi_is_disconn_req
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_disconn_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_GET_DISCONN_REQ_FLAG, g_mmi_is_disconn_req);
    return g_mmi_is_disconn_req;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_main_menu_bt_dialer
 * DESCRIPTION
 *  This function is Main menu entry function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_main_menu_bt_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MAIN_MENU);
    ASSERT(0);
}


static void mmi_bt_conn_pop_show_timer_hdlr(void* usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_bt_conn_pop_show_timer_hdlr");
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_dialor_conn_success
 * DESCRIPTION
 *  This function is for showning connected popup function
 * PARAMETERS
 *  srv_bt_cm_dev_struct* dev_p
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_dialor_conn_success(srv_bt_cm_dev_struct* dev_p)
{// TODO: check whether this function can be tidy
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
    WCHAR string1[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                     */
    /*----------------------------------------------------------------*/
    if (dev_p == NULL)
    {
        return;
    }

    mmi_chset_utf8_to_ucs2_string((kal_uint8*)string, (SRV_BT_CM_BD_UCS2_NAME_LEN * 2), (kal_uint8*)dev_p->name);
    mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_CONN_EVENT_ID, dev_p, MMI_FALSE);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_EVENT);

    mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
    kal_prompt_trace(MOD_MMI, "[BTB]STRING = %s", string1);

    srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_TRUE);
    mmi_bt_dialer_set_connected_dev_info(dev_p);

#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
   // if(!mmi_bt_anti_lost_is_in_list(&dev_p->bd_addr))//if have not eisted in anti-lost list,so do it.
   // {
   //     mmi_bt_anti_lost_enable_req(&dev_p->bd_addr, MMI_TRUE);
   // }
    // add this device to anti-lost list.
   // mmi_bt_anti_lost_add_addr(&dev_p->bd_addr);
#endif/*__MMI_BT_ANTI_LOST_BY_RSSI__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_dialor_help
 * DESCRIPTION
 *  This function is for showning help function
 * PARAMETERS
 *  srv_bt_cm_dev_struct *dev_p
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_dialor_help(srv_bt_cm_dev_struct *dev_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_ABOUT);
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_next_callback_item
 * DESCRIPTION
 *  This function is for call callback function.
 * PARAMETERS
 *  srv_bt_cm_connection_type conn_type
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_bt_dialer_conn_callback_item *mmi_bt_dialer_next_callback_item(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    static MMI_BOOL has_first_item_conn = MMI_FALSE;
    U32 total = mmi_bt_dialer_tbl_count();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_FUNC, conn_type, is_connect, is_indicate);

    if(is_indicate)
    {//passive
        #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        if (is_connect && conn_type == SRV_BT_CM_HF_CONNECTION)
        {
            mmi_bt_dialer_auto_reconn_reset();
        }
        #endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        
        if(!is_connect && !mmi_bt_dialer_app_is_connected_ex(dev_addr))
        {//not connected, not disconnect
            return NULL;
        }
        
        if (!is_connect && conn_type == SRV_BT_CM_HF_CONNECTION)
        {
            if (srv_bt_cm_is_dev_busy(dev_addr))
            {
                mmi_bt_dialer_set_time_out_flag(MMI_TRUE);
            }
            else
            {//only disconnect HF
                return NULL;
            }
        }
        
        if (!is_connect && conn_type == SRV_BT_CM_AVRCP_CT_CONNECTION)
        {//avrcp and a2dp must both be disconnected
            if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
            {
                return &g_mmi_btdialer_callback_tbl[1];
            }
        }

        #ifdef __MMI_BTB_APPLICATION_BQB__
        if (is_connect && conn_type == SRV_BT_CM_AVRCP_CT_CONNECTION && !srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
        {
            return &g_mmi_btdialer_callback_tbl[1];
        }
        #endif  //__MMI_BTB_APPLICATION_BQB__
    }
    else
    {//active
        //for A2DP special case: not call disconnect from CM.
        if(!is_connect && 
            srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr) &&
            conn_type == SRV_BT_CM_A2DP_CONNECTION)
        {
            return NULL;
        }
    }

    #ifdef __MMI_LINE_IN__
    if (is_connect && mmi_linein_is_plug_in())
    {//don't connect if in line in mode
        return NULL;
    }
    #endif  //__MMI_LINE_IN__
    
    if (conn_type == SRV_BT_CM_NO_CONNECTION)
    {
        return &g_mmi_btdialer_callback_tbl[0];
    }
    
    for (i = 0; i < total; i++)
    {
        if (g_mmi_btdialer_callback_tbl[i].type == conn_type)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_RESET_BUSY_STATE, conn_type, dev_addr->lap,dev_addr->nap,dev_addr->uap);
            srv_bt_cm_set_dev_busy_state(dev_addr, conn_type, MMI_FALSE);
            break;
        }
    }
    
    if ((i + 1) < total)
    {
        return &g_mmi_btdialer_callback_tbl[i + 1];
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_NEXTITEM, i, total);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_callback_done
 * DESCRIPTION
 *  This function is bt dialer callback done
 * PARAMETERS
 *  srv_bt_cm_bt_addr*
 *  MMI_BOOL
 *  MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_callback_done(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL result, MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when reconnection started, then should not show popup*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_DONE, result,is_connect,dev_addr->lap, dev_addr->nap, dev_addr->uap);

    if(!srv_bt_cm_is_dev_busy(dev_addr))
    {
        mmi_bt_dialer_callback_done_int(dev_addr, is_connect);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[BTB]BT is busy in mmi_bt_dialer_callback_done");
    }

    kal_prompt_trace(MOD_MMI, "[BTB]mmi_bt_dialer_callback_done, BTstate=%d,BTBstate=%d", srv_bt_cm_get_state(), btb_get_state());
    if (btb_get_state() == BTB_STATE_PASSIVE_CONNECTING || btb_get_state() == BTB_STATE_PASSIVE_DISCONNECTING || btb_get_state() == BTB_STATE_RECONNECTING)
    {
        btb_set_state(BTB_STATE_IDLE);
    }

    #if defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    mmi_frm_input_event_notify_remove(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT, 0));
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_callback_done_int
 * DESCRIPTION
 *  This function is a internal bt dialer callback done
 * PARAMETERS
 *  srv_bt_cm_bt_addr*
 *  MMI_BOOL
 *  MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_callback_done_int(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p;
    WCHAR string1[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_dev_info(dev_addr);
    if (!dev_p)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]mmi_bt_dialer_callback_done_int, dev_p is null");
        return;
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_DONE_INT, is_connect,dev_addr->lap, dev_addr->nap, dev_addr->uap);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHOW_POP);

    if (is_connect)
    {
        if (btb_is_connected_ex((const srv_bt_cm_bt_addr*)&dev_p->bd_addr))
        {
            mmi_bt_show_dialor_conn_success(dev_p);
            #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN_STATUS, is_connect, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);
            if (MMI_TRUE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag)
            {
                g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag = MMI_FALSE;
                mmi_bt_dialer_clean_autoreconn_dev(&g_mmi_bt_reconn_ctx[0]);
                if (!mmi_bt_dialer_is_addr_equal_0(&g_mmi_bt_reconn_ctx[0].bd_addr))
                {
                    mmi_bt_dialer_auto_reconn_first_start_check();//  for the 2nd device do the auto conenct
                }
            }
            #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_FAIL_POPUP);
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr, MMI_FALSE);
        }
    }
    else
    {
        if (!btb_is_connected_ex((const srv_bt_cm_bt_addr*)&dev_p->bd_addr))
        {
            #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
            mmi_bt_anti_lost_stop(&dev_p->bd_addr);
            mmi_bt_anti_lost_clean_addr(&dev_p->bd_addr);//clean the device in anti-lost list.
            #endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
            if (!srv_shutdown_is_running())
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)string,
                    (SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
                    (kal_uint8*)dev_p->name);
                mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
                kal_prompt_trace(MOD_MMI_CONN_APP, "[BTB]STRING = %s, 1", string1);
                mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_DISCONN_EVENT_ID, dev_p, MMI_FALSE);
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIS_EVENT);
            }
            mmi_bt_dialer_set_disconn_req(MMI_FALSE);
        }
    }
    
    if (mmi_bt_dialer_get_time_out_flag())
    {
        mmi_bt_dialer_set_time_out_flag(MMI_FALSE); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_callback
 * DESCRIPTION
 *  This function is bt dialer callback function
 * PARAMETERS
 *  srv_bt_cm_connection_type conn_type
 * MMI_BOOL result
 * MMI_BOOL is_connect
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_callback(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result, MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p = NULL;
    mmi_bt_dialer_conn_callback_item *callback_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CALLBACK, 0,
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff),
                    conn_type, result, is_connect, is_indicate, srv_bt_cm_get_state(), btb_get_state());
    
    srv_bt_cm_copy_addr(&g_mmi_bt_scr_cntx.conn_dev_add, dev_addr);

    dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&g_mmi_bt_scr_cntx.conn_dev_add);
    if (!dev_p)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]mmi_bt_dialor_callback, dev_p is null");
        if (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING)
        {
            mmi_frm_input_event_notify_remove(NOTIFY_ID_BT_CONNECTING);
            mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTION_FAIL, NULL);
            btb_set_state(BTB_STATE_IDLE);
        }
        return;
    }
    
    callback_item = mmi_bt_dialer_next_callback_item(&dev_p->bd_addr, conn_type, is_connect, is_indicate);
    
    if(is_connect)
    {        
        if (is_indicate && btb_get_state() == BTB_STATE_IDLE)
        {
            if (btb_a2dp_is_connected_ex((const srv_bt_cm_bt_addr*)dev_addr))
            {
                kal_prompt_trace(MOD_MMI, "[BTB]connected");
            }
            else if (result)
            {
                if (mmi_bt_dialer_get_time_out_flag())
                {
                    callback_item = NULL;
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_NULL);
                }
                if (callback_item != NULL)
                {                    
                    btb_set_state(BTB_STATE_PASSIVE_CONNECTING);
                    if (btb_block(MMI_TRUE))
                    {
                        memcpy(&g_btb_context.opt_after_set_visibility.callback_item, callback_item, sizeof(mmi_bt_dialer_conn_callback_item));
                        memcpy(&g_btb_context.opt_after_set_visibility.bd_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
                        g_btb_context.opt_after_set_visibility.result = result;
                        g_btb_context.opt_after_set_visibility.is_connect = is_connect;
                        return;
                    }
                }
            }
        }
        
        if (mmi_bt_dialer_get_time_out_flag())
        {
            callback_item = NULL;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_NULL);
        }
    }
    else
    {        
        if (is_indicate && btb_get_state() == BTB_STATE_IDLE)
        {
            if (btb_is_disconnected_ex((const srv_bt_cm_bt_addr*)dev_addr))
            {
                kal_prompt_trace(MOD_MMI, "[BTB]disconnected");
            }
            else if (result && callback_item != NULL)
            {
                btb_set_state(BTB_STATE_PASSIVE_DISCONNECTING);
                if (btb_block(MMI_TRUE))
                {
                    memcpy(&g_btb_context.opt_after_set_visibility.callback_item, callback_item, sizeof(mmi_bt_dialer_conn_callback_item));
                    memcpy(&g_btb_context.opt_after_set_visibility.bd_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
                    g_btb_context.opt_after_set_visibility.result = result;
                    g_btb_context.opt_after_set_visibility.is_connect = is_connect;
                    return;
                }
            }
        }      
    }

    mmi_bt_dialor_callback_int(&dev_p->bd_addr, result, is_connect, callback_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_callback_int
 * DESCRIPTION
 *  This function is a internal bt dialer callback function
 * PARAMETERS
 *  srv_bt_cm_bt_addr*
 * MMI_BOOL result
 * MMI_BOOL is_connect
 * mmi_bt_dialer_conn_callback_item *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialor_callback_int(srv_bt_cm_bt_addr* dev_addr,  MMI_BOOL result, MMI_BOOL is_connect, mmi_bt_dialer_conn_callback_item *callback_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CALLBACK_INT, result, is_connect, dev_addr->lap, dev_addr->nap, dev_addr->uap);

    if(callback_item != NULL)
    {
        if (is_connect)
        {
            #ifdef __MMI_LINE_IN__
            if (mmi_linein_is_plug_in())
            {//don't connect if in line in mode
                mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
            }
            else
            #endif  //__MMI_LINE_IN__
            {
                if (result)
                {
                    srv_bt_cm_set_dev_link_state(dev_addr, MMI_TRUE);
                }
                if (callback_item->conn != NULL)
                {
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CBITEM_CONN_NULL);
                    if (btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE))
                    {
                        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_SET_BUSY_STATE, callback_item->type, dev_addr->lap, dev_addr->nap, dev_addr->uap);
                        srv_bt_cm_set_dev_busy_state(dev_addr, callback_item->type, MMI_TRUE);
                        callback_item->conn(&g_mmi_bt_scr_cntx.conn_dev_add, mmi_bt_dialor_callback);
                    }
                }
                else
                {
                    mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
                }
            }
        }
        else
        {
            if(callback_item->disconn != NULL)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CBITEM_CONN_NULL);
                if (btb_is_available(MMI_FALSE, MMI_TRUE, MMI_FALSE))
                {
                    callback_item->disconn(&g_mmi_bt_scr_cntx.conn_dev_add, mmi_bt_dialor_callback);
                }
            }
            else
            {
                mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
            }
        }
    }
    else
    {
        mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_disconnect
 * DESCRIPTION
 *  This function is bt dialer disconnect function
 * PARAMETERS
 *  srv_bt_cm_bt_addr* dev_addr
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_disconnect(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_bt_dialer_conn_callback_item *callback_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_DIS_FROM_DAILER, dev_addr->lap, dev_addr->nap, dev_addr->uap);
    callback_item = mmi_bt_dialer_next_callback_item(dev_addr, SRV_BT_CM_NO_CONNECTION, MMI_FALSE, MMI_FALSE);
    if (srv_bt_cm_get_busy_dev() == NULL &&
        (callback_item != NULL) && 
        (callback_item->indx != 0xFF))
    {
        mmi_bt_dialer_set_disconn_req(MMI_TRUE);
        callback_item->disconn(dev_addr, mmi_bt_dialor_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_connect
 * DESCRIPTION
 *  This function is bt dialer connect function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_connect(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dialer_conn_callback_item *callback_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_item = mmi_bt_dialer_next_callback_item(dev_addr, SRV_BT_CM_NO_CONNECTION, MMI_TRUE, MMI_FALSE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_CONNECT_FROM_DIALER);
  
    if (srv_bt_cm_get_busy_dev() == NULL &&
        (callback_item) != NULL && 
        (callback_item->indx) != 0xFF)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_SET_BUSY_STATE, callback_item->type, dev_addr->lap,dev_addr->nap,dev_addr->uap);
        if (btb_is_available(MMI_TRUE, MMI_TRUE, MMI_TRUE)
            #ifdef __MMI_BTB_APPLICATION_BQB__
            || (btb_get_state() == BTB_STATE_ACTIVE_CONNECTING && btb_is_available(MMI_FALSE, MMI_TRUE, MMI_TRUE))  //BQB will raise active connection by this API
            #endif  //__MMI_BTB_APPLICATION_BQB__
            )
        {
            btb_set_state(BTB_STATE_RECONNECTING);
            srv_bt_cm_set_dev_busy_state(dev_addr, callback_item->type, MMI_TRUE);
            if (callback_item != NULL)
            {
                callback_item->conn(dev_addr, mmi_bt_dialor_callback);
            }
        }
    }
    else
    {
        U16 pop_str_id = STR_BT_SERVICE_UNAVAILABLE;
    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        if(MMI_TRUE == srv_bt_cm_get_auto_reconn_flag(dev_addr))
        {
            kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection start @ mmi_bt_dialor_connect");
            StartTimer(BT_DIALER_AUTO_RECONN_TIMER,g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq, mmi_bt_dialer_auto_reconn_hdlr);
            return;
        }
    #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
    }
}  


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dialor_mydev_opt_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_dialor_mydev_opt_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_bt_entry_dialor_mydev_opt_group_proc");
    ASSERT(0);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_emit_event
 * DESCRIPTION
 *  This function is bt dialer emit evnet function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_app_emit_event(U32 event_id, void* event_info, MMI_BOOL is_all_dis)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_event_struct event_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;
    event_data.is_dis_all = is_all_dis;
    MMI_FRM_CB_EMIT_EVENT(&event_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_connect
 * DESCRIPTION
 *  This function is bt dialer auto connect function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_connect(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_is_connected
 * DESCRIPTION
 *  This function is judged bt dialer is connected function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_app_is_connected()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CT_CONNECTION))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_CONNECTED); 
        return MMI_TRUE;
        
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_NOT_CONNECTED); 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_is_connected
 * DESCRIPTION
 *  This function is judged bt dialer is connected function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_app_is_connected_ex(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_CONNECTED); 
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_NOT_CONNECTED); 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_cent
 * DESCRIPTION
 *  This function is center key function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_cent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_bt_dialer_cent");
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_cent_flag
 * DESCRIPTION
 *  This function is whether is center key function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_cent_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_cent_flag
 * DESCRIPTION
 *  This function is set center key flag function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_cent_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_bt_dialer_set_cent_flag");
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_shutdown
 * DESCRIPTION
 *  This function is bt dialer shutdown function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bt_dialer_shutdown(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0);//  wait for Yiquan's interface
    g_id_info = id_info;
    memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(srv_bt_cm_bt_addr));
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap); 

#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
    mmi_bt_dialer_auto_reconn_reset();
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/  

    if (mmi_bt_dialer_app_is_connected_ex(&g_mmi_bt_scr_cntx.conn_dev_add))
    {
        if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) || 
            srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) ||
            mmi_bt_dialer_get_headset_flag(&g_mmi_bt_scr_cntx.conn_dev_add))
        {
            //mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);
            kal_prompt_trace(MOD_MMI, "[BTB]call mmi_bt_entry_release_device_connections");
        }
        else
        {
            mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
        }
        if(mmi_bt_dialer_get_disconn_req())
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_TIMER);
            StartTimer(BT_DIALER_DISCONN_TIMER,50,mmi_bt_dialer_disconn_hdlr);
            return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
        }
    }
    return MMI_FRM_PROC_RESULT_COMPLETED;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_disconn_hdlr
 * DESCRIPTION
 *  This function is bt dialer disconnect hdlr in shutdown function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_disconn_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_HDLR);

    if (!mmi_bt_dialer_get_disconn_req())
    {        
        if (mmi_bt_dialer_app_is_connected())
        {
            srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0);//  wait for Yiquan's interface
            memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(srv_bt_cm_bt_addr));
            if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) 
               || mmi_bt_dialer_get_headset_flag(&(dev_p->bd_addr)))
            {
                //mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);
                kal_prompt_trace(MOD_MMI, "[BTB]call mmi_bt_entry_release_device_connections");
            }
            else
            {
                mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
            }
            if (mmi_bt_dialer_get_disconn_req())
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_TIMER);
                StartTimer(BT_DIALER_DISCONN_TIMER,50,mmi_bt_dialer_disconn_hdlr);
            }
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_STOP_TIMER);
            StopTimer(BT_DIALER_DISCONN_TIMER);
            mmi_frm_proc_notify_completed(g_id_info);
        }
    }
    else
    {
        StartTimer(BT_DIALER_DISCONN_TIMER,50,mmi_bt_dialer_disconn_hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_connect_time_out_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  N/A
 *
 *
 * RETURNS
 *  N/A
 *****************************************************************************/
void mmi_bt_dialer_connect_time_out_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIMER_OUT_HDLR);

    if (srv_bt_cm_get_busy_dev() != NULL)
    {
        // don't do connect the next profile.
        mmi_bt_dialer_set_time_out_flag(MMI_TRUE);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIMER_OUT_HDLR_SET_TRUE);
    }

#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    mmi_frm_input_event_notify_remove(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT, 0));
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_link_state_ind
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void* para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_link_state_ind(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if (__BT_MAX_LINK_NUM__ > 1)
    srv_bt_cm_link_sate_ind_struct* event = (srv_bt_cm_link_sate_ind_struct*)para;
    #else  //(__BT_MAX_LINK_NUM__ > 1)
    srv_bt_cm_fail_conn_to_struct* event = (srv_bt_cm_fail_conn_to_struct*)para;
    #endif  //(__BT_MAX_LINK_NUM__ > 1)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BTB]mmi_bt_dialer_link_state_ind, reason=%d,addr:0x%02x:%02x:%02x:%02x:%02x:%02x", event->reason,    
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    switch(event->reason)
    {
        case BTBM_ADP_FAIL_LINK_PAGE_TIMEOUT:
        {
            mmi_bt_dialer_connect_time_out_hdlr(NULL);
            break;
        }
        case BTBM_ADP_FAIL_LINK_CONNECTION_TIMEOUT:
        {
            mmi_bt_dialer_disconn_excpt_hdlr(&event->dev_addr);
            break;
        }
        default:
            break;
    }
#endif
}


#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_reset
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_reset(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        srv_bt_cm_bt_addr* curr = &g_mmi_bt_reconn_ctx[i].bd_addr;
        if (mmi_bt_dialer_is_addr_equal_0(curr))
        {
            continue;
        }

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_RESET, curr->lap, curr->uap, curr->nap);
        if (g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag == MMI_TRUE)
        {
            srv_bt_cm_set_auto_reconn_flag(&g_mmi_bt_reconn_ctx[i].bd_addr, MMI_FALSE);
            memset(&g_mmi_bt_reconn_ctx[i],0,sizeof(mmi_bt_reconn_ctx_struct));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_disconn_excpt_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  N/A
 *
 * RETURNS
 *  NMMI_BOOLA
 *****************************************************************************/
static void mmi_bt_dialer_disconn_excpt_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_reconn_ctx_struct temp_dev;
    srv_bt_cm_bt_addr* dev_addr =(srv_bt_cm_bt_addr*)msg_ptr;
    U32 indx = -1 ; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_CONNECT_LOST,
        ((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff), (dev_addr->uap));
//#ifdef __MMI_A2DP_SUPPORT__
   // if(BT_A2DP_SOURCE == srv_a2dp_get_role(&g_mmi_bt_reconn_ctx[0].bd_addr))
   //     return;
//#endif /* __MMI_A2DP_SUPPORT__ */

#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    mmi_frm_input_event_notify_remove(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT, 0));
#endif

    indx = mmi_bt_dialer_get_pre_autoreconn_inx_array(dev_addr);

    if((indx >= 0)&&(indx < BT_DEVICE_LINK_NUM))
    {           
        mmi_bt_dialer_clean_pre_autoreconn_dev_addr(dev_addr);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RECONN_GET_ITEM, indx);
        return;
    }
    
    memcpy(&temp_dev.bd_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
    temp_dev.bt_dialer_reconn_flag = MMI_TRUE;
    temp_dev.bt_dialer_reconn_accu_time = 0;
    temp_dev.bt_dialer_reconn_duration = MMI_BT_DIALER_AUTO_RECONN_DURATION;
    temp_dev.bt_dialer_reconn_freq = MMI_BT_DIALER_AUTO_RECONN_FREQ;
    mmi_bt_dialer_set_autoreconn_dev(&temp_dev);
    if (!mmi_bt_dialer_is_addr_equal_0(&temp_dev.bd_addr))
    {
        if(!mmi_bt_dialer_app_is_connected_ex(&temp_dev.bd_addr) && !srv_bt_cm_is_dev_busy(&temp_dev.bd_addr) )
        {
            mmi_bt_dialer_auto_reconn_first_start_check();//  for disconenction done. do the auto conenct
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_autoreconn_dev
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * mmi_bt_reconn_ctx_struct *
 *
 * RETURNS
 *  N/A
 *****************************************************************************/
static void mmi_bt_dialer_set_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 j = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_CONNECTED_DEV_FUNC,dev->bd_addr.lap,dev->bd_addr.nap,dev->bd_addr.uap);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&dev->bd_addr, &g_mmi_bt_reconn_ctx[i].bd_addr))
        {
            break;
        }
        if (mmi_bt_dialer_is_addr_equal_0(&g_mmi_bt_reconn_ctx[i].bd_addr))
        {
            memcpy(&g_mmi_bt_reconn_ctx[i],dev, sizeof(mmi_bt_reconn_ctx_struct));
            srv_bt_cm_set_auto_reconn_flag(&g_mmi_bt_reconn_ctx[i].bd_addr, MMI_TRUE);
            break;
        }
    }
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_SET_DEV,i,g_mmi_bt_reconn_ctx[i].bd_addr.lap,g_mmi_bt_reconn_ctx[i].bd_addr.nap,g_mmi_bt_reconn_ctx[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_pre_autoreconn_addr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr *
 *
 * RETURNS
 *  N/A
 *****************************************************************************/
static void mmi_bt_dialer_set_pre_autoreconn_addr(srv_bt_cm_bt_addr *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 j = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_CONNECTED_DEV_FUNC,bd_addr->lap,bd_addr->nap,bd_addr->uap);


#ifdef __MMI_A2DP_SUPPORT__
        if(BT_A2DP_SOURCE == srv_a2dp_get_role(bd_addr))
        {
            mmi_bt_dialer_clean_pre_autoreconn_dev_addr(bd_addr);
            return;
        }    
#endif /* __MMI_A2DP_SUPPORT__ */



    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal( bd_addr, &bd_pconn_addr[i]))
        {
            break;
        }
        if (mmi_bt_dialer_is_addr_equal_0(&bd_pconn_addr[i]))
        {
            memcpy(&bd_pconn_addr[i],bd_addr, sizeof(srv_bt_cm_bt_addr));
            break;
        }
    }
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_SET_DEV,i,bd_pconn_addr[i].lap,bd_pconn_addr[i].nap,bd_pconn_addr[i].uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_clean_pre_autoreconn_dev_addr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  mmi_bt_reconn_ctx_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_clean_pre_autoreconn_dev_addr(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(dev_addr, &bd_pconn_addr[i]))
        {
            memset(&bd_pconn_addr[i],0,sizeof(srv_bt_cm_bt_addr));
        }
    }
    for(i = 0; i< BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_CLEAN_DEV,i,bd_pconn_addr[i].lap,bd_pconn_addr[i].nap,bd_pconn_addr[i].uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_clean_autoreconn_dev
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  mmi_bt_reconn_ctx_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_clean_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&dev->bd_addr, &g_mmi_bt_reconn_ctx[i].bd_addr))
        {
            srv_bt_cm_set_auto_reconn_flag(&dev->bd_addr, MMI_FALSE);
            for (j = i; j < BT_DEVICE_LINK_NUM - 1; j++)
            {
                //shift array
                memcpy(&g_mmi_bt_reconn_ctx[j],&g_mmi_bt_reconn_ctx[j + 1], sizeof(mmi_bt_reconn_ctx_struct));
            }
            memset(&g_mmi_bt_reconn_ctx[BT_DEVICE_LINK_NUM - 1],0,sizeof(mmi_bt_reconn_ctx_struct));
        }
    }
    for(i = 0; i< BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_CLEAN_DEV,i,g_mmi_bt_reconn_ctx[i].bd_addr.lap,g_mmi_bt_reconn_ctx[i].bd_addr.nap,g_mmi_bt_reconn_ctx[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_pre_autoreconn_inx_array
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr* 
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_dialer_get_pre_autoreconn_inx_array(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&bd_pconn_addr[i], dev_addr))
        {
            return i;
        }
    }
    
    return -1;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_autoreconn_inx_array
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr* 
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_dialer_get_autoreconn_idx_array(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_mmi_bt_reconn_ctx[i].bd_addr, dev_addr))
        {
            return i;
        }
    }
    
    return -1;    
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_first_start_check
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_first_start_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN_STATUS, 0, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);

    if (MMI_TRUE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag && 0 == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time)
    {
        if (IsMyTimerExist(BT_DIALER_AUTO_RECONN_TIMER))
        {
            StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
            mmi_bt_dialer_auto_reconn_hdlr();
        }
        else
        {
        #if defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
            mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BT_ANTI_LOST_IND, mmi_bt_anti_lost_ind_proc, NULL); 
            mmi_frm_group_enter(GRP_ID_BT_ANTI_LOST_IND, MMI_FRM_NODE_NONE_FLAG);
            mmi_bt_anti_lost_send_notify(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_ABDISC,0));
            kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection start @ mmi_bt_dialer_auto_reconn_first_start_check");
            StartTimer(BT_DIALER_AUTO_RECONN_TIMER, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq, mmi_bt_dialer_auto_reconn_hdlr);
        #endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */
        }
    }
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    else if (MMI_FALSE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag)
    {
        kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection finish");
        if (srv_btsco_is_sco_open() && srv_bt_dialer_is_any_call() 
            && !mmi_ucm_is_ucm_sg_bt(mmi_frm_group_get_active_id()))
        {
            // need create bt call group and close anti lost group by bt call
            return;
        }
        if(srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION)
            && !mmi_frm_group_is_present(GRP_ID_BT_MUSIC_NOLCD))
        {
            // need create bt music group and close anti lost group by bt music
            return;
        }
        if(mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
        {
            kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection end @ mmi_bt_dialer_auto_reconn_first_start_check");
            mmi_frm_group_close(GRP_ID_BT_ANTI_LOST_IND);
        }
    }
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 * void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN,g_mmi_bt_reconn_ctx[0].bd_addr.lap,g_mmi_bt_reconn_ctx[0].bd_addr.nap,g_mmi_bt_reconn_ctx[0].bd_addr.uap, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);
    g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time += g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq;
    if (g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time > g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_duration)
    {
        g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag = MMI_FALSE;
    }
    if (g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag == MMI_FALSE)
    {
        g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time = 0;
        StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
        mmi_bt_dialer_clean_autoreconn_dev(&g_mmi_bt_reconn_ctx[0]);
        mmi_bt_dialer_auto_reconn_first_start_check();
        return;
    }
    mmi_bt_dialer_auto_reconn_start();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_start
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN,g_mmi_bt_reconn_ctx[0].bd_addr.lap,g_mmi_bt_reconn_ctx[0].bd_addr.nap,g_mmi_bt_reconn_ctx[0].bd_addr.uap, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);
    StartTimer(BT_DIALER_AUTO_RECONN_TIMER,g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq, mmi_bt_dialer_auto_reconn_hdlr);
    mmi_bt_dialor_connect(&g_mmi_bt_reconn_ctx[0].bd_addr);
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    mmi_bt_anti_lost_send_notify(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT, 0));
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_restart
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RECONN_RESTART);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        srv_bt_cm_bt_addr* curr = &g_mmi_bt_reconn_ctx[i].bd_addr;

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_RESET, curr->lap, curr->uap, curr->nap);

        if (g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag == MMI_TRUE)
        {
            g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_accu_time = 0;
            g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_duration = MMI_BT_DIALER_AUTO_RECONN_DURATION;
            g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_freq = MMI_BT_DIALER_AUTO_RECONN_FREQ;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_reconn_item
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_bt_dialer_get_reconn_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag)
            break;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RECONN_GET_ITEM, i);

    return i;
}
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/


#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_acl_timeout_discon_hdlr
 * DESCRIPTION
 *  bt acl disconncet timeout event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_dialer_acl_timeout_discon_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the SCR_BT_CONNECTING screen is exist or not */
    return MMI_RET_OK;
}
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_enhanced_init
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_enhanced_init(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag = MMI_FALSE;
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_accu_time = 0;
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_duration = MMI_BT_DIALER_AUTO_RECONN_DURATION;
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_freq = MMI_BT_DIALER_AUTO_RECONN_FREQ;
        memset(&bd_pconn_addr[i],0,sizeof(srv_bt_cm_bt_addr));
    }
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_headset_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_headset_flag(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(dev_addr == NULL)
    {
        return result;
    }
    if( g_mmi_bt_dialer_headset_cntx.bt_addr.lap == dev_addr->lap &&
        g_mmi_bt_dialer_headset_cntx.bt_addr.uap == dev_addr->uap &&
        g_mmi_bt_dialer_headset_cntx.bt_addr.nap == dev_addr->nap)
    {
        result = g_mmi_bt_dialer_headset_cntx.headset_flag & 1; 
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_GET_HS_FLAG, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_headset_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  MMI_BOOL
 *
 * RETURNS
 * void
 *****************************************************************************/
void mmi_bt_dialer_set_headset_flag(MMI_BOOL flag
    #if (__BT_MAX_LINK_NUM__ > 1)
    , srv_bt_cm_bt_addr* dev_addr
    #endif  //(__BT_MAX_LINK_NUM__ > 1)
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_dialer_headset_cntx.headset_flag = flag;
    #if (__BT_MAX_LINK_NUM__ > 1)
    if(dev_addr)
    {
        g_mmi_bt_dialer_headset_cntx.bt_addr.lap = dev_addr->lap;
        g_mmi_bt_dialer_headset_cntx.bt_addr.uap = dev_addr->uap;
        g_mmi_bt_dialer_headset_cntx.bt_addr.nap = dev_addr->nap;
    }
    else
    {
        memset(&g_mmi_bt_dialer_headset_cntx.bt_addr, 0, sizeof(srv_bt_cm_bt_addr));
    }
    #endif  //(__BT_MAX_LINK_NUM__ > 1)
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_HS_FLAG, g_mmi_bt_dialer_headset_cntx.headset_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_all_disconn_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_all_disconn_flag(MMI_BOOL is_all_disconn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_bt_is_all_disconn = is_all_disconn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ALL_DISCONN_FLAG, g_bt_is_all_disconn);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_all_disconn_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_all_disconn_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return g_bt_is_all_disconn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ALL_DISCONN_FLAG, g_bt_is_all_disconn);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_connected_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_dev_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_connected_dev_info(srv_bt_cm_dev_struct *dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S16 error;
    U32 p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_CONNECTED_DEV_FUNC,dev_info->bd_addr.lap,dev_info->bd_addr.nap,dev_info->bd_addr.uap);

    if(!srv_bt_cm_is_dev_addr_equal(&g_connected_dev_info[0].bd_addr, &dev_info->bd_addr))
    {
        for(p = BT_DEVICE_LINK_NUM-1; p > 0; p--)
        {
            memcpy(&g_connected_dev_info[p],&g_connected_dev_info[p-1], sizeof(srv_bt_cm_dev_struct));
        }
        memcpy(&g_connected_dev_info[0],dev_info, sizeof(srv_bt_cm_dev_struct));
    }

    for(i = 0; i< BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DEV_INFOR, i, g_connected_dev_info[i].bd_addr.lap,g_connected_dev_info[i].bd_addr.nap,g_connected_dev_info[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_clean_connected_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_dev_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_clean_connected_dev_info(srv_bt_cm_dev_struct *dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CLN_DEV_INFO_FUN);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_connected_dev_info[i].bd_addr, &dev_info->bd_addr))
        {
            memset(&g_connected_dev_info[i], 0, sizeof(srv_bt_cm_dev_struct));
        }
    }
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DEV_INFOR, i, g_connected_dev_info[i].bd_addr.lap,g_connected_dev_info[i].bd_addr.nap,g_connected_dev_info[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_is_addr_equal_0
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * const srv_bt_cm_bt_addr*
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_is_addr_equal_0(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_addr)
    {
        if ((dev_addr->lap == 0) &&
            (dev_addr->uap == 0) &&
            (dev_addr->nap == 0))
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ADDR_EQUAL_ZERO,dev_addr->lap,dev_addr->uap,dev_addr->nap);
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
}


#ifdef __MMI_A2DP_SUPPORT__
#ifdef __MMI_BT_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_connect_a2dp_src_cb
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr*
 * srv_bt_cm_connection_type
 * MMI_BOOL
 * MMI_BOOL
 * MMI_BOOL
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_connect_a2dp_src_cb(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result, MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CALLBACK, 1,
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff),
                    conn_type, result, is_connect, is_indicate, srv_bt_cm_get_state(), btb_get_state());
    
    dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_dev_info(dev_addr);
    if (!dev_p)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]mmi_bt_dialor_connect_a2dp_src_cb, dev_p is null");
        return;
    }

    if(is_connect)
    {
        if(result)
        {
            mmi_bt_show_dialor_conn_success(dev_p);
            #if (__BT_MAX_LINK_NUM__ > 1)
            mmi_bt_dialer_set_headset_flag(MMI_TRUE, dev_addr);
            #else  //(__BT_MAX_LINK_NUM__ > 1)
            mmi_bt_dialer_set_headset_flag(MMI_TRUE);
            #endif  //(__BT_MAX_LINK_NUM__ > 1)
        }
        else
        {            
            #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
            srv_bt_cm_set_dev_busy_state(dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_FALSE);
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
            if(MMI_TRUE == srv_bt_cm_get_auto_reconn_flag(dev_addr))
            {
                return;
            }
            #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
        }
    }
    
    srv_bt_cm_set_dev_busy_state(dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_connect_a2dp_src
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr* 
 * mmi_id group_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_connect_a2dp_src(srv_bt_cm_bt_addr *dev_addr, mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_dev_busy_state(dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_TRUE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_A2DP_SRC,dev_addr->lap,dev_addr->uap,dev_addr->nap);
    srv_bt_a2dp_src_cm_connect_req(dev_addr, mmi_bt_dialor_connect_a2dp_src_cb);
}
#endif/*__MMI_BT_SPEAKER_SUPPORT__*/
#endif/*__MMI_A2DP_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_align_connected_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *
 * RETURNS
 *  U32     [OUT]   total entry
 *****************************************************************************/
U32 mmi_bt_dialer_align_connected_dev_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 j_start;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i<BT_DEVICE_LINK_NUM-1; i++)
    {
        if( mmi_bt_dialer_is_addr_equal_0(&g_connected_dev_info[i].bd_addr) )
            break;
    }

    j_start = i+1;

    for(; i<BT_DEVICE_LINK_NUM-1; i++)
    {
        for(j=j_start; j<BT_DEVICE_LINK_NUM; j++)
        {
            if( !mmi_bt_dialer_is_addr_equal_0(&g_connected_dev_info[j].bd_addr) )
            {
                memcpy(&g_connected_dev_info[i], &g_connected_dev_info[j], sizeof(srv_bt_cm_dev_struct));
                memset(&g_connected_dev_info[j], 0, sizeof(srv_bt_cm_dev_struct));
                j_start = j+1;
                break;
            }
        }
        if(j==BT_DEVICE_LINK_NUM)
            break;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_insert_connected_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *
 * RETURNS
 *  U32     [OUT]   Insert position
 *****************************************************************************/
U32 mmi_bt_dialer_insert_connected_dev_info(srv_bt_cm_dev_struct *dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num;
    U32 i;
    U32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = mmi_bt_dialer_align_connected_dev_info();

    kal_prompt_trace(MOD_MMI, "[BTCONN] new dev: %x %s", dev_info->bd_addr, dev_info->name);

    #if (__BT_MAX_LINK_NUM__ > 1)
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_ADD_DEV_INFO, total_num);
    #endif  //(__BT_MAX_LINK_NUM__ > 1)
    for(i=0; i<total_num; i++)
    {
        if(srv_bt_cm_is_dev_addr_equal(&g_connected_dev_info[i].bd_addr, &dev_info->bd_addr))
        {
            kal_prompt_trace(MOD_MMI, "[BTCONN] mmi_bt_dialer_insert_connected_dev_info B %d", i);
            return total_num;
        }
    }
#ifdef __MMI_A2DP_SUPPORT__
    if(BT_A2DP_SINK == srv_a2dp_get_role(&dev_info->bd_addr))
    {
        kal_prompt_trace(MOD_MMI, "[BTCONN] mmi_bt_dialer_insert_connected_dev_info C");

        for(i=0; i<total_num; i++)
        {
            if(BT_A2DP_SOURCE == srv_a2dp_get_role(&g_connected_dev_info[i].bd_addr))
            {
                for(j=total_num+1; j>i; j--)
                {
                    memcpy(&g_connected_dev_info[j], &g_connected_dev_info[j-1], sizeof(srv_bt_cm_dev_struct));
                }
                
                break;
            }
        }
        kal_prompt_trace(MOD_MMI, "[BTCONN] mmi_bt_dialer_insert_connected_dev_info D %d", i);
        memcpy(&g_connected_dev_info[i], dev_info, sizeof(srv_bt_cm_dev_struct));
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        kal_prompt_trace(MOD_MMI, "[BTCONN] mmi_bt_dialer_insert_connected_dev_info E");
        memcpy(&g_connected_dev_info[total_num], dev_info, sizeof(srv_bt_cm_dev_struct));
    }

    return total_num++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_index_by_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_dev_struct*
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U32 mmi_bt_dialer_get_index_by_dev_info(srv_bt_cm_bt_addr *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i<BT_DEVICE_LINK_NUM; i++)
    {
        if(srv_bt_cm_is_dev_addr_equal(&g_connected_dev_info[i].bd_addr, bd_addr))
            break;
    }

    kal_prompt_trace(MOD_MMI, "[BTCONN] mmi_bt_dialer_get_index_by_dev_info i:%d", i);
    ASSERT(i<BT_DEVICE_LINK_NUM);

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ower_off_pre_process
 * DESCRIPTION
 *  This function is pre process of host device power off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bt_power_off_pre_process(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_power_off_pre_process");
	#ifdef __MMI_A2DP_SUPPORT__
	#ifdef __BT_SPEAKER_SUPPORT__
	#ifdef __MMI_BT_SPEAKER_SUPPORT__
	if(aud_bt_a2dp_is_codec_opened() == KAL_TRUE)
	aud_send_bt_close_sink_codec_req(MOD_MMI);
        #endif /*__MMI_BT_SPEAKER_SUPPORT__*/
	#endif //__MMI_A2DP_SUPPORT__
	#endif //__BT_SPEAKER_SUPPORT__
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_power_on
 * DESCRIPTION
 *  This function is to check if Bluetooth is power on
 * PARAMETERS
 *  is_popup        [IN]            if Bluetooth is not power on, whether to show the power on confirm
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is power on
 *                  FALSE : Bluetooth is not power on
 *****************************************************************************/
MMI_BOOL mmi_bt_is_power_on(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (SRV_BT_CM_POWER_ON == srv_bt_cm_get_power_status() ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_to_display_bt_menu
 * DESCRIPTION
 *  This function is to decide to show BT menu or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : show BT menu
 *                  FALSE : don't show BT menu
 *****************************************************************************/
MMI_BOOL mmi_bt_is_to_display_bt_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_IS_TO_DISPLAY_BT_MENU, result);
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_power_on_confirm
 * DESCRIPTION
 *  This function is display power on confirm screen
 * PARAMETERS
 *  flag         [IN]            screen flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_power_on_confirm(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init_power
 * DESCRIPTION
 *  This function is to execute the bt power on when phone power on
 *     mmi_event_struct *evt
 * PARAMETERS
 *  mmi_event_struct *evt
 *
 *
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
MMI_RET mmi_bt_init_power(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BTB]mmi_bt_init_power");
    // not in flight mode, bt on, then power on
    #if !defined(__MMI_BT_DIALER_SUPPORT__ ) || defined(__MMI_TELEPHONY_SUPPORT__)
    if (srv_mode_switch_is_network_service_available())
    {
        srv_bt_cm_switch_on();
    }
	#else
    {
        srv_bt_cm_switch_on();
    }
    #endif

    return MMI_RET_OK;
}


void MMI_BT_SET_FLAG(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_SET_SCR_FLAG,
        g_mmi_bt_scr_cntx.flag,
        (g_mmi_bt_scr_cntx.flag | x));
    g_mmi_bt_scr_cntx.flag |=  x ;
}


void MMI_BT_RESET_FLAG(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_RESET_SCR_FLAG,
        g_mmi_bt_scr_cntx.flag,
        ((g_mmi_bt_scr_cntx.flag)&(~x)));
    g_mmi_bt_scr_cntx.flag &= ~x;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_hilight_handler
 * DESCRIPTION
 *  This function is Bluetooth highlight handler
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_main_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#endif  //__MMI_BT_BTBOX_NOLCD__

