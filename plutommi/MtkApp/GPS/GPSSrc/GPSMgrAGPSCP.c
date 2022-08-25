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
 * GPSMgrAGPSCP.c
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 * GPS manager for AGPS control plane
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if defined(__AGPS_CONTROL_PLANE__)

#include "custom_events_notify.h"
#include "Unicodexdcl.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_msg_struct.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "string.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "custom_phb_config.h"
#include "mmi_rp_srv_gps_def.h"
#include "mmi_frm_history_gprot.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "PhbSrvGprot.h"
#include "wgui_categories_popup.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "agpsEncode.h"
#include "l4c2abm_struct.h"
#include "rmmi_common_enum.h"
#include "ps_public_utility.h"

#include "stack_common.h"
#include "stack_msgs.h"

#include "Mdi_gps.h"

#include "l3_inc_enums.h"
#include "UcmSrvGprot.h"
#include "NwInfoSrvGprot.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#define MMI_GPS_MGR_IS_PHONELOCK ((MMI_BOOL)mmi_dmui_is_phone_lock())
#else
#define MMI_GPS_MGR_IS_PHONELOCK (MMI_FALSE)
#endif

#include "gps2lcsp_enum.h"
#include "gps2lcsp_struct.h"

#include "GPSResDef.h"
#include "GPSGProt.h"
#include "GPSMgrProt.h"
#include "GPSMgrAGPSCP.h"
#include "GPSSetting.h"
#include "mdi_agps.h"
#include "GpioSrvGprot.h"

/*temp solution include Tim's file and owner is Tim*/
#include "agpsEncode.c"

#define __MMI_AGPS_CP_USE_QUERY_BITMAP__

mmi_gps_manager_cp_context_struct g_gps_mgr_cp_ctx;

static void mmi_gps_mgr_mmi_ss_mtlr_begin_ind_hdlr(void *msg,module_type src_mod);
static void mmi_gps_mgr_mtlr_notify_handler(void);
static void mmi_gps_mgr_show_mtlr_notify_src(mmi_gps_manager_mtlr_notify_struct *notify_p);
void mmi_gps_mgr_exit_mtlr_notify_src(void);
static void mmi_gps_mgr_show_mtlr_confirm_src(void);
static void mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_BOOL is_success, mmi_gps_manager_mtlr_notify_struct *mtlr_req);
static void mmi_gps_mgr_mmi_ss_mtlr_begin_res_rsp_hdlr(void *msg);

static void mmi_gps_mgr_mmi_ss_aerq_begin_ind_hdlr(void *msg,module_type src_mod);
static void mmi_gps_mgr_send_mmi_ss_aerq_begin_res_req(MMI_BOOL is_success, U8 ref_num, mmi_gps_manager_mtlr_ae_req_struct *mtlr_ae_req_p);
static void mmi_gps_mgr_mmi_ss_aerq_begin_res_rsp_hdlr(void *msg);

static mmi_ret mmi_gps_mgr_mmi_nw_attach_ind_hdlr(void *msg);
static void mmi_gps_mgr_send_mmi_ss_aerp_begin_req(U8 begin_index);

static void mmi_gps_mgr_mmi_ss_aerp_begin_rsp_hdlr(void *msg);
static void mmi_gps_mgr_mmi_ss_aecl_begin_ind_hdlr(void *msg,module_type src_mod);
static void mmi_gps_mgr_send_mmi_ss_aecl_begin_res_req(MMI_BOOL is_success, U8 index, mmi_gps_manager_mtlr_ae_req_struct *mtlr_ae_req_p);
static void mmi_gps_mgr_mmi_ss_aecl_begin_res_rsp_hdlr(void *msg);
static MMI_BOOL mmi_gps_mgr_check_area_event(U8 index);
static void mmi_gps_mgr_switch_mode_callback(mdi_gps_parser_info_enum type);

static void mmi_gps_mgr_agps_new_key_needed_ind_hdlr(void *msg);
static void mmi_gps_mgr_send_agps_key_update_rsp(void *msg);

static S32 mmi_gps_mgr_start_molr_internal(
    mmi_ss_molr_begin_req_struct *molr_info,
    mdi_gps_uart_work_mode_enum gps_mode,
    MMI_BOOL is_send_location,
    MMI_BOOL is_single,
    U32 delay,
    U16* req_id,
    void (*callback)(S32 type, void *buffer, U32 length));
static void mmi_gps_mgr_send_mmi_ss_molr_begin_req(U8 index);
static void mmi_gps_mgr_mmi_ss_molr_begin_rsp_hdlr(void *msg);
static void mmi_gps_mgr_send_mmi_ss_molr_end_req(mmi_gps_manager_molr_req_struct *molr_req_p, MMI_BOOL is_success);

static void mmi_gps_mgr_clean_molr_req_item(U8 index);
static void mmi_gps_mgr_molr_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length);
static void mmi_gps_mgr_send_location(void);

static mmi_gps_mgr_dcs_enum mmi_gps_mgr_decode_cbsdcs(U8 dcs);

static U8 mmi_gps_mgr_convert_bcd_to_asc(U8 *source, U8 *dest, U32 count);
static U8 mmi_gps_mgr_get_ch_byte_24008(U8 bcd);
#ifndef __COSMOS_MMI__
    static void mmi_gps_mgr_cp_app_notify_func(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data);
#endif
static void mmi_gps_mgr_mtlr_notify_time_out(void);

extern void smsal_gsm7_unpack(kal_uint8  *packed_data,
                       kal_uint8  *unpacked_data,
                       kal_uint16 data_len,
                       kal_uint16 offset);

//#define __GPS_MGR_MTLR_UT__
#ifdef __GPS_MGR_MTLR_UT__
static void _ut_mmi_gps_mgr_mtlr_send_notify(void)
{
    mmi_ss_mtlr_begin_ind_struct *local_param_ptr;
    ilm_struct *ilm_ptr;
    local_param_ptr = (mmi_ss_mtlr_begin_ind_struct*)construct_local_para(sizeof(mmi_ss_mtlr_begin_ind_struct), TD_CTRL);

    local_param_ptr->ss_id = 0;
    local_param_ptr->notification.validity = KAL_TRUE;
    local_param_ptr->notification.notificationType = L4C_SS_NotificationToMSUser_notifyLocationAllowed;
    //local_param_ptr->notification.locationType = 0; /* MANDATORY */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MTLR_BEGIN_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}

static void _ut_mmi_gps_mgr_mtlr_send_confirm_allow(void)
{
    mmi_ss_mtlr_begin_ind_struct *local_param_ptr;
    ilm_struct *ilm_ptr;
    local_param_ptr = (mmi_ss_mtlr_begin_ind_struct*)construct_local_para(sizeof(mmi_ss_mtlr_begin_ind_struct), TD_CTRL);

    local_param_ptr->ss_id = 0;
    local_param_ptr->notification.validity = KAL_TRUE;
    local_param_ptr->notification.notificationType = L4C_SS_NotificationToMSUser_notifyAndVerify_LocationAllowedIfNoResponse;
    //local_param_ptr->notification.locationType = 0; /* MANDATORY */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MTLR_BEGIN_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}

static void _ut_mmi_gps_mgr_mtlr_send_confirm_not_allow(void)
{
    mmi_ss_mtlr_begin_ind_struct *local_param_ptr;
    ilm_struct *ilm_ptr;
    local_param_ptr = (mmi_ss_mtlr_begin_ind_struct*)construct_local_para(sizeof(mmi_ss_mtlr_begin_ind_struct), TD_CTRL);

    local_param_ptr->ss_id = 0;
    local_param_ptr->notification.validity = KAL_TRUE;
    local_param_ptr->notification.notificationType = L4C_SS_NotificationToMSUser_notifyAndVerify_LocationNotAllowedIfNoResponse;
    //local_param_ptr->notification.locationType = 0; /* MANDATORY */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MTLR_BEGIN_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}

static void _mmi_gps_mgr_mtlr_notify_ut_timeout_func(void)
{
    mmi_ss_mtlr_begin_ind_struct *local_param_ptr;
    ilm_struct *ilm_ptr;
    local_param_ptr = (mmi_ss_mtlr_begin_ind_struct*)construct_local_para(sizeof(mmi_ss_mtlr_begin_ind_struct), TD_CTRL);

    local_param_ptr->ss_id = 0;
    local_param_ptr->notification.notificationType = L4C_SS_NotificationToMSUser_notifyLocationAllowed;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MTLR_BEGIN_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}

#endif

mmi_ret mmi_gps_mgr_call_state_change_cp_proc(mmi_event_struct* param)
{
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *) param;
    ilm_struct *ilm_ptr;
    mmi_agps_cp_abort_req_struct *local_param_ptr;

    /*emergency call*/
    if (MMI_TRUE == srv_ucm_is_emergency_call())
    {
        local_param_ptr = (mmi_agps_cp_abort_req_struct*)construct_local_para(sizeof(mmi_agps_cp_abort_req_struct), TD_CTRL);
        local_param_ptr->is_abort_molr = MMI_FALSE; /*only when mmi exit shoud set to true*/
    /*notify NI-LR*/
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_L4C;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_AGPS_CP_ABORT_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
        msg_send_ext_queue(ilm_ptr);
        g_gps_mgr_cp_ctx.emerge_call = MMI_TRUE;
    }
    /*MT call accept*/
    if (SRV_UCM_ACCEPT_ACT == srv_ucm_query_curr_action())
    {
    /*notify NI-LR*/
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_cp_is_ongoing
 * DESCRIPTION
 *  get if cp is ongoing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_gps_mgr_cp_is_ongoing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gps_mgr_cp_ctx.mtlr_count > 0)
    {
        return MMI_TRUE;
    }

    for (i = 0; i < MAX_MTLR_LN_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.notify_list[i].is_used == MMI_TRUE)
        {
            break;
        }
    }
    if (i == MAX_MTLR_LN_REQ_NUM)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_mtlr_start_hdle
 * DESCRIPTION
 *  process MMI_SS_MTLR_START_IND message
 * PARAMETERS
 *  msg - message information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_mtlr_start_hdle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_mgr_cp_ctx.mtlr_count++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_mtlr_end_hdlr
 * DESCRIPTION
 *  process MMI_SS_MTLR_END_IND message
 * PARAMETERS
 *  msg - message information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_mtlr_end_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_mgr_cp_ctx.mtlr_count--;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_cp_init
 * DESCRIPTION
 *  initialise GPS manager for AGPS control plane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_cp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_mgr_cp_ctx.cur_id = 1;
    g_gps_mgr_cp_ctx.mtlr_count = 0;
    g_gps_mgr_cp_ctx.is_pos = MMI_FALSE;
    g_gps_mgr_cp_ctx.emerge_call = MMI_FALSE;
    g_gps_mgr_cp_ctx.ss_id = 0;

    for (i = 0; i < MAX_MTLR_LN_REQ_NUM; i++)
    {
        g_gps_mgr_cp_ctx.notify_list[i].is_used = MMI_FALSE;
        g_gps_mgr_cp_ctx.notify_list[i].state = MMI_AGPS_STATE_TERMINATE;
        g_gps_mgr_cp_ctx.notify_list[i].src_mod = MOD_NIL;
    }

    g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = 0;
    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used = MMI_FALSE;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state = MMI_AGPS_STATE_TERMINATE;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_first = MMI_TRUE;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].src_mod = MOD_NIL;
    }
    memset(&g_gps_mgr_cp_ctx.last_area_info, 0, sizeof(mmi_nw_attach_ind_struct));

    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        g_gps_mgr_cp_ctx.molr_req_list[i].is_used = MMI_FALSE;
        g_gps_mgr_cp_ctx.molr_req_list[i].state = MMI_AGPS_STATE_TERMINATE;
        g_gps_mgr_cp_ctx.molr_req_list[i].src_mod = MOD_NIL;
    }

    #ifdef __COSMOS_MMI__
        /* VAPP version, already register in mmi_gps_mgr_init() */
    #else
        mmi_gps_mgr_cp_register_notify_function(mmi_gps_mgr_cp_app_notify_func, NULL);
    #endif

    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_mtlr_begin_ind_hdlr, MSG_ID_MMI_SS_MTLR_BEGIN_IND);
    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_mtlr_begin_res_rsp_hdlr, MSG_ID_MMI_SS_MTLR_BEGIN_RES_RSP);

    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_aerq_begin_ind_hdlr, MSG_ID_MMI_SS_AERQ_BEGIN_IND);
    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_aerq_begin_res_rsp_hdlr, MSG_ID_MMI_SS_AERQ_BEGIN_RES_RSP);

    SetProtocolEventHandler(mmi_gps_mgr_mmi_nw_attach_ind_hdlr, EVT_ID_SRV_NW_INFO_LOCATION_CHANGED);
    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_aerp_begin_rsp_hdlr, MSG_ID_MMI_SS_AERP_BEGIN_RSP);
    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_aecl_begin_ind_hdlr, MSG_ID_MMI_SS_AECL_BEGIN_IND);
    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_aecl_begin_res_rsp_hdlr, MSG_ID_MMI_SS_AECL_BEGIN_RES_RSP);

    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_molr_begin_rsp_hdlr, MSG_ID_MMI_SS_MOLR_BEGIN_RSP);

    SetProtocolEventHandler(mmi_gps_mgr_agps_new_key_needed_ind_hdlr,MSG_ID_MMI_AGPS_NEW_KEY_NEEDED_IND);

    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_mtlr_start_hdle, MSG_ID_MMI_AGPS_CP_START_IND);
    SetProtocolEventHandler(mmi_gps_mgr_mmi_ss_mtlr_end_hdlr, MSG_ID_MMI_AGPS_CP_END_IND);

#ifdef __GPS_MGR_MTLR_UT__
    //StartTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID, 30000, _ut_mmi_gps_mgr_mtlr_send_notify);
	//StartTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID, 30000, _ut_mmi_gps_mgr_mtlr_send_confirm_allow);
	StartTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID, 30000, _ut_mmi_gps_mgr_mtlr_send_confirm_not_allow);
#endif
}

void mmi_gps_mgr_cp_register_notify_function(srv_gps_notify_callback func, void* user_data)
{
    g_gps_mgr_cp_ctx.app_callback = func;
    g_gps_mgr_cp_ctx.app_user_data = user_data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_mtlr_begin_ind_hdlr
 * DESCRIPTION
 *  process MMI_SS_MTLR_BEGIN_IND message
 * PARAMETERS
 *  msg - message information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_mtlr_begin_ind_hdlr(void *msg,module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_mtlr_begin_ind_struct *mmi_ss_mtlr_begin_ind_p = (mmi_ss_mtlr_begin_ind_struct*)msg;
    mmi_gps_manager_mtlr_notify_struct mtlr_req;
    U8 i;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_BEGIN_IND);

    for (i = 0; i < MAX_MTLR_LN_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.notify_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.notify_list[i].req_id == mmi_ss_mtlr_begin_ind_p->ss_id)
        {
            U8 j;

            /* eliminate previous notify with the same ss_id */
            /* because SS already close it */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_BEGIN_IND);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MTLR_BEGIN_RES_REQ, i);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_BEGIN_IND);

            StopTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID);
            if (mmi_frm_scrn_get_active_id() == SRC_ID_GPS_MGR_MTLR_NOTIFY)
            {
                 mmi_frm_scrn_close(g_gps_mgr_cp_ctx.screen_group_gid, SRC_ID_GPS_MGR_MTLR_NOTIFY);
            }
            for (j = i; j < MAX_MTLR_LN_REQ_NUM - 1; j++)
            {
                memcpy(&g_gps_mgr_cp_ctx.notify_list[j], &g_gps_mgr_cp_ctx.notify_list[j + 1], sizeof(mmi_gps_manager_mtlr_notify_struct));
            }
            g_gps_mgr_cp_ctx.notify_list[MAX_MTLR_LN_REQ_NUM - 1].is_used = MMI_FALSE;

            break;
        }
    }

    for (i = 0; i < MAX_MTLR_LN_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.notify_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }
    index = i;
    if (index == MAX_MTLR_LN_REQ_NUM)
    {
        /* notify list full */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_REQ_LIST_FULL);
        memset(&mtlr_req, 0, sizeof(mmi_gps_manager_mtlr_notify_struct));
        mtlr_req.req_id = mmi_ss_mtlr_begin_ind_p->ss_id;
        mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_FALSE, &mtlr_req);
        return;
    }
    memcpy(&g_gps_mgr_cp_ctx.notify_list[index].notify_info, mmi_ss_mtlr_begin_ind_p, sizeof(mmi_ss_mtlr_begin_ind_struct));
    g_gps_mgr_cp_ctx.notify_list[index].is_used = MMI_TRUE;
    g_gps_mgr_cp_ctx.notify_list[index].state = MMI_AGPS_STATE_PUSH_WAIT;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_LN_STATE_CHANGE, index, MMI_AGPS_STATE_PUSH_WAIT);
    g_gps_mgr_cp_ctx.notify_list[index].req_id = g_gps_mgr_cp_ctx.notify_list[index].notify_info.ss_id;
    g_gps_mgr_cp_ctx.notify_list[index].src_mod = src_mod;

    //g_gps_mgr_cp_ctx.notify_list[index].req_id = g_gps_mgr_cp_ctx.cur_id;
    //g_gps_mgr_cp_ctx.cur_id++;

    if (mmi_gps_check_if_can_use_agps() == MMI_FALSE ||     // can't use agps
        mmi_gps_setting_get_send_location() == MMI_FALSE)   // user not allow
    {
        /* can't use agps  or  user not allow */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_CAN_NOT_USE_AGPS);
        mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_FALSE, &g_gps_mgr_cp_ctx.notify_list[index]);
		g_gps_mgr_cp_ctx.notify_list[index].is_used = MMI_FALSE;
        return;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_LN_REQ_INDEX, index);


    if (index == 0)
    {
        mmi_gps_mgr_mtlr_notify_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mtlr_notify_handler
 * DESCRIPTION
 *  process mtlr notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mtlr_notify_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_NOTIFY_HDLR);

    if (g_gps_mgr_cp_ctx.notify_list[0].is_used == MMI_FALSE)
    {
        /* notify list is null */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_REQ_LIST_NULL);
        return;
    }

    g_gps_mgr_cp_ctx.screen_group_gid = mmi_frm_group_create(GRP_ID_ROOT,
                                               GRP_ID_AUTO_GEN,
                                               NULL, NULL);
    mmi_frm_group_enter(g_gps_mgr_cp_ctx.screen_group_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_gps_mgr_cp_ctx.notify_list[0].state = MMI_AGPS_STATE_WAIT_CNF;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_LN_STATE_CHANGE, 0, MMI_AGPS_STATE_WAIT_CNF);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_NOTIFY_TYPR, g_gps_mgr_cp_ctx.notify_list[0].notify_info.notification.notificationType);
    switch (g_gps_mgr_cp_ctx.notify_list[0].notify_info.notification.notificationType)
    {
        case L4C_SS_NotificationToMSUser_notifyLocationAllowed:
            mmi_gps_mgr_show_mtlr_notify_src(&g_gps_mgr_cp_ctx.notify_list[0]);
            StartTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID, MMI_GPS_MGR_MTLR_NOTIFY_DELAY, mmi_gps_mgr_mtlr_notify_time_out);
            /* notify only, send rsp immediately. */
            mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_TRUE, &g_gps_mgr_cp_ctx.notify_list[0]);
            break;
        case L4C_SS_NotificationToMSUser_notifyAndVerify_LocationAllowedIfNoResponse:
        case L4C_SS_NotificationToMSUser_notifyAndVerify_LocationNotAllowedIfNoResponse:
            mmi_gps_mgr_show_mtlr_confirm_src();
            StartTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID, MMI_GPS_MGR_MTLR_CONFIRM_DELAY, mmi_gps_mgr_mtlr_notify_time_out);
            break;
        case L4C_SS_NotificationToMSUser_locationNotAllowed:
            mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_TRUE, &g_gps_mgr_cp_ctx.notify_list[0]);
            break;
        default:
            mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_FALSE, &g_gps_mgr_cp_ctx.notify_list[0]);
            break;
    }
}

/*
static MMI_BOOL mmi_gps_mgr_decode_dcs_string(L4C_SS_LocationNotificationArg *notify_info_p, U8 *out_p, U32 length)
{
    MMI_BOOL is_request_id_valid = MMI_TRUE;
    mmi_gps_mgr_dcs_enum dcs_type;
    CHAR temp[1024];
    CHAR *p;
    CHAR temp_char;
    U8 i;

    dcs_type = mmi_gps_mgr_decode_cbsdcs(notify_info_p->lcsRequestorID.dataCodingScheme.stringData[0]);
    kal_mem_set(temp, 0, sizeof(temp));
    kal_mem_set(out_p, 0, length);
    switch (dcs_type)
    {
        case MMI_GPS_MGR_DEFAULT_DCS:
            smsal_gsm7_unpack((kal_uint8 *)notify_info_p->lcsRequestorID.requestorIDString.stringData,
                      (kal_uint8 *)temp,
                      1024,
                      0);
            mmi_asc_to_ucs2((CHAR*)out_p, (CHAR*)temp);
            break;
        case MMI_GPS_MGR_8BIT_DCS:
            kal_mem_cpy(
                temp,
                notify_info_p->lcsRequestorID.requestorIDString.stringData,
                sizeof(U8) * notify_info_p->lcsRequestorID.requestorIDString.numOctets);
            mmi_asc_to_ucs2((CHAR*)out_p, (CHAR*)temp);
            break;
        case MMI_GPS_MGR_UCS2_DCS:
            kal_mem_cpy(
                out_p,
                notify_info_p->lcsRequestorID.requestorIDString.stringData,
                sizeof(U8) * notify_info_p->lcsRequestorID.requestorIDString.numOctets);
            p = (CHAR*)out_p;
            for (i = 0; i < notify_info_p->lcsClientName.nameString.numOctets; i += 2)
            {
                temp_char = *p;
                *p = *(p + 1);
                *(p + 1) = temp_char;
                p = p + 2;
            }
            break;
        default:
           is_request_id_valid = MMI_FALSE;
           break;
    }
    return is_request_id_valid;
}
*/

static void _mmi_gps_mgr_cp_prepare_notification_string(CHAR *temp, CHAR *temp2, MMI_BOOL is_request_id_valid, MMI_BOOL is_client_name_valid, MMI_BOOL is_external_address_valid)
{
    S32 ret = 0;

    temp[0] =0;
    temp[1] =0;

    mmi_ucs2cat((CHAR*)temp, (CHAR*)GetString(STR_ID_GPS_MGR_REQ_POS));

    /* requestor */
    if (is_client_name_valid)
    {
        mmi_ucs2cat((CHAR*)temp, (CHAR*)L"\n");
        mmi_ucs2cat((CHAR*)temp, (CHAR*)GetString(STR_ID_GPS_MGR_REQ_POS_REQUESTOR));

        ret = srv_phb_get_name_by_number(g_gps_mgr_cp_ctx.client_name, (U16*)temp2, 1024);
        if (ret == MMI_TRUE && mmi_ucs2strlen((CHAR*)temp2) != 0)
        {
            mmi_ucs2cat((CHAR*)temp, (CHAR*)temp2);
        }
        else
        {
            mmi_ucs2cat((CHAR*)temp, (CHAR*)g_gps_mgr_cp_ctx.client_name);
        }
        if (is_external_address_valid)
        {
            mmi_ucs2cat((CHAR*)temp, (CHAR*)L" ");
            mmi_ucs2cat((CHAR*)temp, (CHAR*)g_gps_mgr_cp_ctx.extrenal_address);
        }
    }

    /* application */
    if (is_request_id_valid)
    {
        mmi_ucs2cat((CHAR*)temp, (CHAR*)L"\n");
        mmi_ucs2cat((CHAR*)temp, (CHAR*)GetString(STR_ID_GPS_MGR_REQ_POS_APPLICATION));
        mmi_ucs2cat((CHAR*)temp, (CHAR*)g_gps_mgr_cp_ctx.request_id);
    }
}

/*****************************************************************************
 * FUNCTION
*  mmi_gps_mgr_show_mtlr_notify_src
* DESCRIPTION
*  show mtlr notify
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_show_mtlr_notify_src(mmi_gps_manager_mtlr_notify_struct *notify_p)
{
    CHAR temp[1024];
    CHAR temp2[1024];
    CHAR *p;
    CHAR temp_char;
    U8 i;
    L4C_SS_LocationNotificationArg *notify_info_p;

    mmi_gps_mgr_dcs_enum dcs_type;
    U16 gsm7_len;
    MMI_BOOL is_request_id_valid = MMI_FALSE;
    MMI_BOOL is_client_name_valid = MMI_FALSE;
    MMI_BOOL is_external_address_valid = MMI_FALSE;
    mmi_gps_srv_notify_type_struct notify;

    if (MMI_GPS_MGR_IS_PHONELOCK == MMI_TRUE)
    {
        return;
    }

    notify_info_p = &notify_p->notify_info.notification;

    if ((notify_info_p->validity & L4C_SS_LocationNotificationArg_lcsRequestorID_valid) &&
        notify_info_p->lcsRequestorID.requestorIDString.numOctets > 0)
    {
        is_request_id_valid = MMI_TRUE;
        dcs_type = mmi_gps_mgr_decode_cbsdcs(notify_info_p->lcsRequestorID.dataCodingScheme.stringData[0]);
        switch (dcs_type)
        {
            kal_mem_set(g_gps_mgr_cp_ctx.request_id, 0, sizeof(g_gps_mgr_cp_ctx.request_id));
            case MMI_GPS_MGR_DEFAULT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                gsm7_len = notify_info_p->lcsClientName.nameString.numOctets;
                gsm7_len = smsal_msg_len_in_character(SMSAL_DEFAULT_DCS,(U16)gsm7_len,notify_info_p->lcsClientName.nameString.stringData[gsm7_len - 1]);
                if(gsm7_len > 1024)
                {
                    gsm7_len = 1024;
                }
                smsal_gsm7_unpack((kal_uint8 *)notify_info_p->lcsRequestorID.requestorIDString.stringData,
                          (kal_uint8 *)temp,
                          gsm7_len,
                          0);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.request_id, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_8BIT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                kal_mem_cpy(
                    temp,
                    notify_info_p->lcsRequestorID.requestorIDString.stringData,
                    sizeof(U8) * notify_info_p->lcsRequestorID.requestorIDString.numOctets);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.request_id, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_UCS2_DCS:
                kal_mem_cpy(
                    g_gps_mgr_cp_ctx.request_id,
                    notify_info_p->lcsRequestorID.requestorIDString.stringData,
                    sizeof(U8) * notify_info_p->lcsRequestorID.requestorIDString.numOctets);
                p = (CHAR*)g_gps_mgr_cp_ctx.request_id;
                for (i = 0; i < notify_info_p->lcsClientName.nameString.numOctets; i += 2)
                {
                    temp_char = *p;
                    *p = *(p + 1);
                    *(p + 1) = temp_char;
                    p = p + 2;
                }
                break;
            default:
               is_request_id_valid = MMI_FALSE;
               break;
        }
    }

    if ((notify_info_p->validity & L4C_SS_LocationNotificationArg_lcsClientName_valid) &&
        notify_info_p->lcsClientName.nameString.numOctets > 0)
    {
        is_client_name_valid = MMI_TRUE;
        dcs_type = mmi_gps_mgr_decode_cbsdcs(notify_info_p->lcsClientName.dataCodingScheme.stringData[0]);
        switch (dcs_type)
        {
            kal_mem_set(g_gps_mgr_cp_ctx.client_name, 0, sizeof(g_gps_mgr_cp_ctx.client_name));
            case MMI_GPS_MGR_DEFAULT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                gsm7_len = notify_info_p->lcsClientName.nameString.numOctets;
                gsm7_len = smsal_msg_len_in_character(SMSAL_DEFAULT_DCS,(U16)gsm7_len,notify_info_p->lcsClientName.nameString.stringData[gsm7_len - 1]);
                if(gsm7_len > 1024)
                {
                    gsm7_len = 1024;
                }
                smsal_gsm7_unpack((kal_uint8 *)notify_info_p->lcsClientName.nameString.stringData,
                          (kal_uint8 *)temp,
                          gsm7_len,
                          0);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.client_name, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_8BIT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                kal_mem_cpy(
                    temp,
                    notify_info_p->lcsClientName.nameString.stringData,
                    sizeof(U8) * notify_info_p->lcsClientName.nameString.numOctets);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.client_name, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_UCS2_DCS:
                kal_mem_cpy(
                    g_gps_mgr_cp_ctx.client_name,
                    notify_info_p->lcsClientName.nameString.stringData,
                    sizeof(U8) * notify_info_p->lcsClientName.nameString.numOctets);
                p = (CHAR*)g_gps_mgr_cp_ctx.client_name;
                for (i = 0; i < notify_info_p->lcsClientName.nameString.numOctets; i += 2)
                {
                    temp_char = *p;
                    *p = *(p + 1);
                    *(p + 1) = temp_char;
                    p = p + 2;
                }
                break;
            default:
               is_client_name_valid = MMI_FALSE;
               break;
        }
    }

    if ((notify_info_p->validity & L4C_SS_LocationNotificationArg_lcsClientExternalID_valid) &&
        (notify_info_p->lcsClientExternalID.validity & L4C_SS_LCSClientExternalID_externalAddress_valid))
    {
        kal_mem_set(temp, 0, sizeof(temp));
        kal_mem_set(temp2, 0, sizeof(temp2));
        mmi_gps_mgr_convert_bcd_to_asc(
            (U8*)&notify_info_p->lcsClientExternalID.externalAddress.stringData[1],
            (U8*)temp,
            notify_info_p->lcsClientExternalID.externalAddress.numOctets - 1);
        if (notify_info_p->lcsClientExternalID.externalAddress.stringData[0] == 0x91)
        {
            strcpy(temp2, "+");
        }
        strcat(temp2, temp);
        mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.extrenal_address, (CHAR*)temp2);
        is_external_address_valid = MMI_TRUE;
    }

    kal_mem_set(temp, 0, sizeof(temp));

    _mmi_gps_mgr_cp_prepare_notification_string(temp, temp2, is_request_id_valid, is_client_name_valid, is_external_address_valid);

    g_gps_mgr_cp_ctx.is_time_out = MMI_FALSE;

    notify.id = 0;
    notify.notify_p = (WCHAR*)temp;
    notify.type = MMI_GPS_SRV_NOTIFY_TYPE_POPUP;
    notify.owner = MMI_GPS_SRV_NOTIFY_OWNER_CP;

    ASSERT(g_gps_mgr_cp_ctx.app_callback != NULL);
    (g_gps_mgr_cp_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_POPUP, &notify, g_gps_mgr_cp_ctx.app_user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_exit_mtlr_notify_src
 * DESCRIPTION
 *  exit mtlr notify screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_exit_mtlr_notify_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gps_mgr_cp_ctx.is_time_out == MMI_FALSE)
    {
        StopTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID);
        srv_backlight_turn_off();
        /* already sent in SUPL activated ind */
        //mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_TRUE, &g_gps_mgr_cp_ctx.notify_list[0]);
    }
}


/*****************************************************************************
 * FUNCTION
*  mmi_gps_mgr_show_mtlr_confirm_src
* DESCRIPTION
*  show mtlr confirm
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_show_mtlr_confirm_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR temp[1024];
    CHAR temp2[1024];
    CHAR *p;
    CHAR temp_char;
    U8 i;
    L4C_SS_LocationNotificationArg *notify_info_p;

    mmi_gps_mgr_dcs_enum dcs_type;
    U16 gsm7_len;
    MMI_BOOL is_request_id_valid = MMI_FALSE;
    MMI_BOOL is_client_name_valid = MMI_FALSE;
    MMI_BOOL is_external_address_valid = MMI_FALSE;
    mmi_gps_srv_notify_type_struct notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_GPS_MGR_IS_PHONELOCK == MMI_TRUE)
    {
        return;
    }
    //EntryNewScreen(SRC_ID_GPS_MGR_MTLR_NOTIFY, NULL, mmi_gps_mgr_show_mtlr_confirm_src, NULL);
    //DeleteNHistory(SRC_ID_GPS_MGR_MTLR_NOTIFY);
    //guiBuffer = GetCurrGuiBuffer(SRC_ID_GPS_MGR_MTLR_NOTIFY);

    notify_info_p = &g_gps_mgr_cp_ctx.notify_list[0].notify_info.notification;

    if ((notify_info_p->validity & L4C_SS_LocationNotificationArg_lcsRequestorID_valid) &&
        notify_info_p->lcsRequestorID.requestorIDString.numOctets > 0)
    {
        is_request_id_valid = MMI_TRUE;
        dcs_type = mmi_gps_mgr_decode_cbsdcs(notify_info_p->lcsRequestorID.dataCodingScheme.stringData[0]);
        switch (dcs_type)
        {
            kal_mem_set(g_gps_mgr_cp_ctx.request_id, 0, sizeof(g_gps_mgr_cp_ctx.request_id));
            case MMI_GPS_MGR_DEFAULT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                gsm7_len = notify_info_p->lcsClientName.nameString.numOctets;
                gsm7_len = smsal_msg_len_in_character(SMSAL_DEFAULT_DCS,(U16)gsm7_len,notify_info_p->lcsClientName.nameString.stringData[gsm7_len - 1]);
                if(gsm7_len > 1024)
                {
                    gsm7_len = 1024;
                }
                smsal_gsm7_unpack((kal_uint8 *)notify_info_p->lcsRequestorID.requestorIDString.stringData,
                          (kal_uint8 *)temp,
                          gsm7_len,
                          0);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.request_id, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_8BIT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                kal_mem_cpy(
                    temp,
                    notify_info_p->lcsRequestorID.requestorIDString.stringData,
                    sizeof(U8) * notify_info_p->lcsRequestorID.requestorIDString.numOctets);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.request_id, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_UCS2_DCS:
                kal_mem_cpy(
                    g_gps_mgr_cp_ctx.request_id,
                    notify_info_p->lcsRequestorID.requestorIDString.stringData,
                    sizeof(U8) * notify_info_p->lcsRequestorID.requestorIDString.numOctets);
                p = (CHAR*)g_gps_mgr_cp_ctx.request_id;
                for (i = 0; i < notify_info_p->lcsClientName.nameString.numOctets; i += 2)
                {
                    temp_char = *p;
                    *p = *(p + 1);
                    *(p + 1) = temp_char;
                    p = p + 2;
                }
                break;
            default:
               is_request_id_valid = MMI_FALSE;
               break;
        }
    }

    if ((notify_info_p->validity & L4C_SS_LocationNotificationArg_lcsClientName_valid) &&
        notify_info_p->lcsClientName.nameString.numOctets > 0)
    {
        is_client_name_valid = MMI_TRUE;
        dcs_type = mmi_gps_mgr_decode_cbsdcs(notify_info_p->lcsClientName.dataCodingScheme.stringData[0]);
        switch (dcs_type)
        {
            kal_mem_set(g_gps_mgr_cp_ctx.client_name, 0, sizeof(g_gps_mgr_cp_ctx.client_name));
            case MMI_GPS_MGR_DEFAULT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                gsm7_len = notify_info_p->lcsClientName.nameString.numOctets;
                gsm7_len = smsal_msg_len_in_character(SMSAL_DEFAULT_DCS,(U16)gsm7_len,notify_info_p->lcsClientName.nameString.stringData[gsm7_len - 1]);
                if(gsm7_len > 1024)
                {
                    gsm7_len = 1024;
                }
                smsal_gsm7_unpack((kal_uint8 *)notify_info_p->lcsClientName.nameString.stringData,
                          (kal_uint8 *)temp,
                          gsm7_len,
                          0);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.client_name, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_8BIT_DCS:
                kal_mem_set(temp, 0, sizeof(temp));
                kal_mem_cpy(
                    temp,
                    notify_info_p->lcsClientName.nameString.stringData,
                    sizeof(U8) * notify_info_p->lcsClientName.nameString.numOctets);
                mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.client_name, (CHAR*)temp);
                break;
            case MMI_GPS_MGR_UCS2_DCS:
                kal_mem_cpy(
                    g_gps_mgr_cp_ctx.client_name,
                    notify_info_p->lcsClientName.nameString.stringData,
                    sizeof(U8) * notify_info_p->lcsClientName.nameString.numOctets);
                p = (CHAR*)g_gps_mgr_cp_ctx.client_name;
                for (i = 0; i < notify_info_p->lcsClientName.nameString.numOctets; i += 2)
                {
                    temp_char = *p;
                    *p = *(p + 1);
                    *(p + 1) = temp_char;
                    p = p + 2;
                }
                break;
            default:
               is_client_name_valid = MMI_FALSE;
               break;
        }
    }

    if ((notify_info_p->validity & L4C_SS_LocationNotificationArg_lcsClientExternalID_valid) &&
        (notify_info_p->lcsClientExternalID.validity & L4C_SS_LCSClientExternalID_externalAddress_valid))
    {
        kal_mem_set(temp, 0, sizeof(temp));
        kal_mem_set(temp2, 0, sizeof(temp2));
        mmi_gps_mgr_convert_bcd_to_asc(
            (U8*)&notify_info_p->lcsClientExternalID.externalAddress.stringData[1],
            (U8*)temp,
            notify_info_p->lcsClientExternalID.externalAddress.numOctets - 1);
        if (notify_info_p->lcsClientExternalID.externalAddress.stringData[0] == 0x91)
        {
            strcpy(temp2, "+");
        }
        strcat(temp2, temp);
        mmi_asc_to_ucs2((CHAR*)g_gps_mgr_cp_ctx.extrenal_address, (CHAR*)temp2);
        is_external_address_valid = MMI_TRUE;
    }

    kal_mem_set(temp, 0, sizeof(temp));

    _mmi_gps_mgr_cp_prepare_notification_string(temp, temp2, is_request_id_valid, is_client_name_valid, is_external_address_valid);

    g_gps_mgr_cp_ctx.is_time_out = MMI_FALSE;

    notify.id = 0;
    notify.notify_p = (WCHAR*)temp;
    notify.type = MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM;
    notify.owner = MMI_GPS_SRV_NOTIFY_OWNER_CP;

    ASSERT(g_gps_mgr_cp_ctx.app_callback != NULL);
    (g_gps_mgr_cp_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM, &notify, g_gps_mgr_cp_ctx.app_user_data);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_mgr_mtlr_notify_accept
* DESCRIPTION
*  accept handler of mtlr notify
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_mtlr_notify_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID);
    srv_backlight_turn_off();

    mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_TRUE, &g_gps_mgr_cp_ctx.notify_list[0]);

#ifndef __COSMOS_MMI__
    mmi_frm_scrn_close(g_gps_mgr_cp_ctx.screen_group_gid, SRC_ID_GPS_MGR_MTLR_NOTIFY);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_mgr_mtlr_notify_decline
* DESCRIPTION
*  decline handler of mtlr notify
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_mtlr_notify_decline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(GPS_MGR_MTLR_NOTIFY_TIMER_ID);
    srv_backlight_turn_off();

    mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_FALSE, &g_gps_mgr_cp_ctx.notify_list[0]);

#ifndef __COSMOS_MMI__
     mmi_frm_scrn_close(g_gps_mgr_cp_ctx.screen_group_gid, SRC_ID_GPS_MGR_MTLR_NOTIFY);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mtlr_notify_time_out
 * DESCRIPTION
 *  mtlr notify time out handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mtlr_notify_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_mgr_cp_ctx.is_time_out = MMI_TRUE;

    srv_backlight_turn_off();

    switch (g_gps_mgr_cp_ctx.notify_list[0].notify_info.notification.notificationType)
    {
        case L4C_SS_NotificationToMSUser_notifyLocationAllowed:
            /* already sent rsp when mtlr_begin_ind hdlr. */
            break;
        case L4C_SS_NotificationToMSUser_notifyAndVerify_LocationAllowedIfNoResponse:
            mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_TRUE, &g_gps_mgr_cp_ctx.notify_list[0]);
            break;
        case L4C_SS_NotificationToMSUser_notifyAndVerify_LocationNotAllowedIfNoResponse:
            mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_FALSE, &g_gps_mgr_cp_ctx.notify_list[0]);
            break;
        default:
            mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_FALSE, &g_gps_mgr_cp_ctx.notify_list[0]);
            break;
    }

#ifdef __COSMOS_MMI__
    vapp_gps_mgr_cp_notify_timeout();
#else
    (g_gps_mgr_cp_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_CLOSE_UI, NULL, g_gps_mgr_cp_ctx.app_user_data);
    if (mmi_frm_scrn_get_active_id() == SRC_ID_GPS_MGR_MTLR_NOTIFY)
    {
         mmi_frm_scrn_close(g_gps_mgr_cp_ctx.screen_group_gid, SRC_ID_GPS_MGR_MTLR_NOTIFY);
    }
#endif
}

#ifndef __COSMOS_MMI__
static void mmi_gps_mgr_cp_app_notify_func(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data)
{
    U8* guiBuffer;
    MMI_BOOL scr_ret;

    switch(type)
    {
    case MMI_GPS_SRV_NOTIFY_TYPE_POPUP:
        scr_ret = mmi_frm_scrn_enter(
    		g_gps_mgr_cp_ctx.screen_group_gid,
    		SRC_ID_GPS_MGR_MTLR_NOTIFY,
    		mmi_gps_mgr_exit_mtlr_notify_src,
    		NULL,
    		MMI_FRM_FULL_SCRN
    	);
    	if(scr_ret == MMI_FALSE){
    		return ;
    	}
        guiBuffer = mmi_frm_scrn_get_gui_buf(g_gps_mgr_cp_ctx.screen_group_gid,SRC_ID_GPS_MGR_MTLR_NOTIFY);
        ShowCategory65Screen(
            (U8*)notify->notify_p,
            0,
            guiBuffer);
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        break;
    case MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM:
        scr_ret = mmi_frm_scrn_enter(
            g_gps_mgr_cp_ctx.screen_group_gid,
            SRC_ID_GPS_MGR_MTLR_NOTIFY,
            NULL,
            mmi_gps_mgr_show_mtlr_notify_src,
            MMI_FRM_FULL_SCRN
        );
    	if(scr_ret == MMI_FALSE){
    		return ;
        }

        guiBuffer = mmi_frm_scrn_get_gui_buf(g_gps_mgr_cp_ctx.screen_group_gid,SRC_ID_GPS_MGR_MTLR_NOTIFY);
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type)notify->notify_p,
            0,
            guiBuffer);
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        SetLeftSoftkeyFunction(mmi_gps_mgr_mtlr_notify_accept, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_gps_mgr_mtlr_notify_decline, KEY_EVENT_UP);
        break;
    case MMI_GPS_SRV_NOTIFY_TYPE_CLOSE_UI:
        if (mmi_frm_scrn_get_active_id() == SRC_ID_GPS_MGR_MTLR_NOTIFY)
        {
            mmi_frm_scrn_close(g_gps_mgr_cp_ctx.screen_group_gid, SRC_ID_GPS_MGR_MTLR_NOTIFY);
        }
        break;
    default:
        ASSERT(0);
    }
}
#endif // #ifdef __COSMOS_MMI__

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req
 * DESCRIPTION
 *  send MMI_SS_MTLR_BEGIN_RES_REQ message
 * PARAMETERS
 *  is_success - response info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_mtlr_begin_res_req(MMI_BOOL is_success, mmi_gps_manager_mtlr_notify_struct *mtlr_notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_mtlr_begin_res_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MTLR_BEGIN_RES_REQ, is_success);
    local_param_ptr = (mmi_ss_mtlr_begin_res_req_struct*)construct_local_para(sizeof(mmi_ss_mtlr_begin_res_req_struct), TD_CTRL);

    local_param_ptr->response.validity = L4C_SS_LocationNotificationRes_verificationResponse_valid;

    if (is_success)
    {
        local_param_ptr->response.verificationResponse = L4C_SS_VerificationResponse_permissionGranted;
        mtlr_notify->state = MMI_AGPS_STATE_WORKING;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_LN_STATE_CHANGE, 0, MMI_AGPS_STATE_WORKING);
    }
    else
    {
        mtlr_notify->state = MMI_AGPS_STATE_TERMINATE;
        local_param_ptr->response.verificationResponse = L4C_SS_VerificationResponse_permissionDenied;
    }
    local_param_ptr->ss_id = (kal_uint8)mtlr_notify->req_id;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    if (mtlr_notify->src_mod != MOD_NIL)
    {
        ilm_ptr->dest_mod_id = mtlr_notify->src_mod;
    }
    else
    {
        ilm_ptr->dest_mod_id = MOD_L4C;
    }
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MTLR_BEGIN_RES_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MTLR_BEGIN_RES_REQ_MSG);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_mtlr_begin_res_rsp_hdlr
 * DESCRIPTION
 *  process MMI_SS_MTLR_BEGIN_RES_RSP message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_mtlr_begin_res_rsp_hdlr(void *msg)
{
    U8 i;
    mmi_ss_mtlr_begin_res_rsp_struct* rsp = (mmi_ss_mtlr_begin_res_rsp_struct*)msg;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_BEGIN_RES_RSP);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_LN_STATE, 0, g_gps_mgr_cp_ctx.notify_list[0].state);

    /* check if current processing notify. because maybe the rsp of dropped out req */
    if (rsp->ss_id == g_gps_mgr_cp_ctx.notify_list[0].req_id &&
        g_gps_mgr_cp_ctx.notify_list[0].is_used == MMI_TRUE)
    {
        /* previous notify done, try to process next one */
        for (i = 0; i < MAX_MTLR_LN_REQ_NUM - 1; i++)
        {
            memcpy(&g_gps_mgr_cp_ctx.notify_list[i], &g_gps_mgr_cp_ctx.notify_list[i + 1], sizeof(mmi_gps_manager_mtlr_notify_struct));
        }
        g_gps_mgr_cp_ctx.notify_list[MAX_MTLR_LN_REQ_NUM - 1].is_used = MMI_FALSE;

        /* try to process next request */
        mmi_gps_mgr_mtlr_notify_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_aerq_begin_ind_hdlr
 * DESCRIPTION
 *  process MMI_SS_AREQ_BEGIN_IND  message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_aerq_begin_ind_hdlr(void *msg, module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_aerq_begin_ind_struct *mmi_ss_aerq_begin_ind_p = (mmi_ss_aerq_begin_ind_struct*)msg;
    mmi_gps_manager_mtlr_ae_req_struct mtlr_ae_req;
    U8 i;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_AERQ_BEGIN_IND);
    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }
    index = i;
    if (index == MAX_MTLR_AE_REQ_NUM)
    {
        /* notify list full */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_REQ_LIST_FULL);
        mtlr_ae_req.area_info.ss_id = mmi_ss_aerq_begin_ind_p->ss_id;
        mtlr_ae_req.src_mod = src_mod;
        mmi_gps_mgr_send_mmi_ss_aerq_begin_res_req(MMI_FALSE, mmi_ss_aerq_begin_ind_p->aerq.referenceNumber.stringData[0], &mtlr_ae_req);
        return;
    }

    memcpy(&g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].area_info, mmi_ss_aerq_begin_ind_p, sizeof(mmi_ss_aerq_begin_ind_struct));
    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].last_event_time = 0;
    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].need_send_req = MMI_FALSE;
    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_used = MMI_TRUE;
    //g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].req_id = mmi_ss_aerq_begin_ind_p->ss_id;
    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_first = MMI_TRUE;
    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].src_mod = src_mod;

    if (mmi_gps_check_if_can_use_agps() == MMI_FALSE ||     // can't use agps
        mmi_gps_setting_get_send_location() == MMI_FALSE || // user not allow
        !mmi_gps_setting_get_em_on_off())                   // mtlr switch off
    {
        /* can't use agps or mtlr switch off */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_CAN_NOT_USE_AGPS);
        mmi_gps_mgr_send_mmi_ss_aerq_begin_res_req(MMI_FALSE, mmi_ss_aerq_begin_ind_p->aerq.referenceNumber.stringData[0], &g_gps_mgr_cp_ctx.mtlr_ae_req_list[index]);
		g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_used = MMI_FALSE;
        return;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_REQ_INDEX, index);

    mmi_gps_mgr_send_mmi_ss_aerq_begin_res_req(MMI_TRUE, mmi_ss_aerq_begin_ind_p->aerq.referenceNumber.stringData[0], &g_gps_mgr_cp_ctx.mtlr_ae_req_list[index]);

    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state = MMI_AGPS_STATE_START;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, index, MMI_AGPS_STATE_START);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_aerq_begin_res_req
 * DESCRIPTION
 *  send MMI_SS_AERQ_BEGIN_RES_REQ message
 * PARAMETERS
 *  is_success - response info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_aerq_begin_res_req(MMI_BOOL is_success, U8 ref_num, mmi_gps_manager_mtlr_ae_req_struct *mtlr_ae_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_aerq_begin_res_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_AERQ_BEGIN_RES_REQ, is_success, ref_num);
    g_gps_mgr_cp_ctx.cur_mtlr_ae_req_result = is_success;

    local_param_ptr = (mmi_ss_aerq_begin_res_req_struct*)construct_local_para(sizeof(mmi_ss_aerq_begin_res_req_struct), TD_CTRL);

    g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = ref_num;
    if (is_success)
    {
        local_param_ptr->cause = 0;
    }
    else
    {
        local_param_ptr->cause = (U8)CM_SS_ERR_FACILITYNOTSUPPORTED;
    }

    local_param_ptr->ss_id = (kal_uint8)mtlr_ae_req_p->area_info.ss_id;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    if (mtlr_ae_req_p->src_mod != MOD_NIL)
    {
        ilm_ptr->dest_mod_id = mtlr_ae_req_p->src_mod;
    }
    else
    {
        ilm_ptr->dest_mod_id = MOD_L4C;
    }
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_AERQ_BEGIN_RES_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_aerq_begin_res_rsp_hdlr
 * DESCRIPTION
 *  process MMI_SS_AERQ_BEGIN_RES_RSP message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_aerq_begin_res_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    L4C_SS_LCS_AreaEventRequestArg *area_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_AERQ_BEGIN_RES_RSP);
    if (g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num == 0)
    {
        return;
    }

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].area_info.aerq;
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE &&
            area_info_p->referenceNumber.stringData[0] == g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num)
        {
            g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = 0;
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state = MMI_AGPS_STATE_WORKING;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, i, MMI_AGPS_STATE_WORKING);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_nw_attach_ind_hdlr
 * DESCRIPTION
 *  process MMI_NW_ATTACH_IND message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_gps_mgr_mmi_nw_attach_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_attach_ind_struct *mmi_nw_attach_ind_p = (mmi_nw_attach_ind_struct*)msg;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_NW_ATTACH_IND);

    memcpy(&g_gps_mgr_cp_ctx.cur_area_info.plmn, mmi_nw_attach_ind_p->plmn, sizeof(U8) * (MAX_PLMN_STRING_LEN + 1));
    memcpy(&g_gps_mgr_cp_ctx.cur_area_info.lac, mmi_nw_attach_ind_p->lac, sizeof(U8) * 2);

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state == MMI_AGPS_STATE_WORKING)
        {
            if (mmi_gps_mgr_check_area_event(i))
            {
                g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].need_send_req = MMI_TRUE;
            }
        }
    }
    mmi_gps_mgr_send_mmi_ss_aerp_begin_req(0);

    memcpy(&g_gps_mgr_cp_ctx.last_area_info, &g_gps_mgr_cp_ctx.cur_area_info, sizeof(mmi_gps_manager_l4c_area_info_struct));
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_aerp_begin_req
 * DESCRIPTION
 *  send MMI_SS_AERP_BEGIN_REQ message
 * PARAMETERS
 *  begin_index - traverse all request item from this index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_aerp_begin_req(U8 begin_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_aerp_begin_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    L4C_SS_LCS_AreaEventRequestArg *area_info_p;
    U8 i;
    U8 index;
    U32 time;
    U16 interval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_AERP_BEGIN_REQ, begin_index);
    ASSERT(begin_index < MAX_MTLR_AE_REQ_NUM);

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state == MMI_AGPS_STATE_WAIT_RSP)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE, i, MMI_AGPS_STATE_WAIT_RSP);
            return;
        }
    }

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        index = begin_index + i;
        if (index >= MAX_MTLR_AE_REQ_NUM)
        {
            index -= MAX_MTLR_AE_REQ_NUM;
        }

        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state == MMI_AGPS_STATE_WORKING &&
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].need_send_req == MMI_TRUE)
        {
            break;
        }
    }

    if (i == MAX_MTLR_AE_REQ_NUM)
    {
        return;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_REQ_INDEX, index);

    kal_get_time(&time);
    interval = (U16)kal_ticks_to_milli_secs(time - g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].last_event_time) / 1000;
    area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].area_info.aerq;
    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_first = MMI_FALSE;

    if (area_info_p->areaEventInfo.occurrenceInfo == L4C_SS_OccurrenceInfo_multipleTimeEvent &&
        interval < area_info_p->areaEventInfo.intervalTime)
    {
        return;
    }
    else
    {
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].last_event_time = time;
    }

    local_param_ptr = (mmi_ss_aerp_begin_req_struct*)construct_local_para(sizeof(mmi_ss_aerp_begin_req_struct), TD_CTRL);
    local_param_ptr->ss_id = (kal_uint8)g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].area_info.ss_id;
    local_param_ptr->is_initial = g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_first;
    local_param_ptr->aerp.validity = area_info_p->validity;
    memcpy(&local_param_ptr->aerp.referenceNumber, &area_info_p->referenceNumber, sizeof(L4C_SS_LCS_ReferenceNumber));
    memcpy(&local_param_ptr->aerp.h_gmlc_address, &area_info_p->h_gmlc_address, sizeof(L4C_SS_GSN_Address));
    memcpy(&local_param_ptr->aerp.r_gmlc_address, &area_info_p->r_gmlc_address, sizeof(L4C_SS_GSN_Address));

    g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = area_info_p->referenceNumber.stringData[0];

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].src_mod != MOD_NIL)
    {
        ilm_ptr->dest_mod_id = g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].src_mod;
    }
    else
    {
        ilm_ptr->dest_mod_id = MOD_L4C;
    }
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_AERP_BEGIN_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_AERP_BEGIN_REQ_MSG);

    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state = MMI_AGPS_STATE_WAIT_RSP;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, index, MMI_AGPS_STATE_WAIT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_aerp_begin_rsp_hdlr
 * DESCRIPTION
 *  process MMI_SS_AERP_BEGIN_RSP message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_aerp_begin_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 index;
    L4C_SS_LCS_AreaEventRequestArg *area_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_AERP_BEGIN_RSP);

    if (g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num == 0)
    {
        return;
    }

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].area_info.aerq;
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state == MMI_AGPS_STATE_WAIT_RSP &&
            area_info_p->referenceNumber.stringData[0] == g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num)
        {
            break;
        }
    }
    index =i;
    if (index == MAX_MTLR_AE_REQ_NUM)
    {
        return;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_REQ_INDEX, index);
    g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = 0;
    area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].area_info.aerq;
    if (area_info_p->areaEventInfo.occurrenceInfo == L4C_SS_OccurrenceInfo_multipleTimeEvent)
    {
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].need_send_req = MMI_FALSE;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state = MMI_AGPS_STATE_WORKING;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, index, MMI_AGPS_STATE_WORKING);
    }
    else
    {
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_used = MMI_FALSE;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state = MMI_AGPS_STATE_TERMINATE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, index, MMI_AGPS_STATE_TERMINATE);
    }

    mmi_gps_mgr_send_mmi_ss_aerp_begin_req(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_aecl_begin_ind_hdlr
 * DESCRIPTION
 *  process MMI_SS_AECL_BEGIN_IND message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_aecl_begin_ind_hdlr(void *msg,module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_aecl_begin_ind_struct *mmi_ss_aecl_begin_ind_p = (mmi_ss_aecl_begin_ind_struct*)msg;
    U8 i;
    U8 index;
    L4C_SS_LCS_AreaEventRequestArg *area_info_p;
    mmi_gps_manager_mtlr_ae_req_struct  mtlr_ae_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_AECL_BEGIN_IND);
    memset(&mtlr_ae_req, 0, sizeof(mmi_gps_manager_mtlr_ae_req_struct));
    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].area_info.aerq;
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE &&
            area_info_p->referenceNumber.stringData[0] == mmi_ss_aecl_begin_ind_p->aecl.referenceNumber.stringData[0])
        {
            break;
        }
    }
    index =i;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_REQ_INDEX, index);
    if (index == MAX_MTLR_AE_REQ_NUM)
    {
        memcpy(&mtlr_ae_req.area_info.aerq.referenceNumber, &mmi_ss_aecl_begin_ind_p->aecl.referenceNumber, sizeof(L4C_SS_LCS_ReferenceNumber));
        memcpy(&mtlr_ae_req.area_info.aerq.h_gmlc_address, &mmi_ss_aecl_begin_ind_p->aecl.h_gmlc_address, sizeof(L4C_SS_GSN_Address));
        mtlr_ae_req.area_info.ss_id = mmi_ss_aecl_begin_ind_p->ss_id;
        mtlr_ae_req.src_mod = src_mod;
        mmi_gps_mgr_send_mmi_ss_aecl_begin_res_req(MMI_FALSE, index, &mtlr_ae_req);
    }
    else
    {
        mmi_gps_mgr_send_mmi_ss_aecl_begin_res_req(MMI_TRUE, index, &g_gps_mgr_cp_ctx.mtlr_ae_req_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_aecl_begin_res_req
 * DESCRIPTION
 *  send MMI_SS_AECL_BEGIN_RES_REQ message
 * PARAMETERS
 *  is_success - response info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_aecl_begin_res_req(MMI_BOOL is_success, U8 index, mmi_gps_manager_mtlr_ae_req_struct *mtlr_ae_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_aecl_begin_res_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    L4C_SS_LCS_AreaEventRequestArg *area_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_AECL_BEGIN_RES_REQ, is_success, index);
    g_gps_mgr_cp_ctx.cur_mtlr_ae_req_result = is_success;
    area_info_p = &mtlr_ae_req_p->area_info.aerq;

    local_param_ptr = (mmi_ss_aecl_begin_res_req_struct*)construct_local_para(sizeof(mmi_ss_aecl_begin_res_req_struct), TD_CTRL);
    local_param_ptr->ss_id = mtlr_ae_req_p->area_info.ss_id;

    if (is_success)
    {
        local_param_ptr->cause = 0;
    }
    else
    {
        local_param_ptr->cause = (U8)CM_SS_ERR_FACILITYNOTSUPPORTED;
    }

    g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = area_info_p->referenceNumber.stringData[0];

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    if (mtlr_ae_req_p->src_mod != MOD_NIL)
    {
        ilm_ptr->dest_mod_id = mtlr_ae_req_p->src_mod;
    }
    else
    {
        ilm_ptr->dest_mod_id = MOD_L4C;
    }
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_AECL_BEGIN_RES_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_AECL_BEGIN_RES_REQ_MSG);

    g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state = MMI_AGPS_STATE_ABORT;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, index, MMI_AGPS_STATE_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_aecl_begin_res_rsp_hdlr
 * DESCRIPTION
 *  process MMI_SS_AECL_BEGIN_RES_RSP message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_aecl_begin_res_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 index;
    L4C_SS_LCS_AreaEventRequestArg *area_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_AECL_BEGIN_RES_RSP);
    if (g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num == 0)
    {
        return;
    }

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].area_info.aerq;
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE &&
            area_info_p->referenceNumber.stringData[0] == g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num &&
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state == MMI_AGPS_STATE_ABORT)
        {
            break;
        }
    }
    index =i;
    if (index != MAX_MTLR_AE_REQ_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_REQ_INDEX, index);
        g_gps_mgr_cp_ctx.last_mtlr_ae_ref_num = 0;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].is_used = MMI_FALSE;
        g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].state = MMI_AGPS_STATE_TERMINATE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MTLR_AE_STATE_CHANGE, index, MMI_AGPS_STATE_TERMINATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_stop_mtlr_area_event_request
 * DESCRIPTION
 *  stop all MTLR Area Event request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_gps_mgr_stop_mtlr_area_event_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_aerp_end_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    U8 i;
    S32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_STOP_MTLR_AE);

    for (i = 0; i < MAX_MTLR_AE_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used == MMI_TRUE)
        {
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].is_used = MMI_FALSE;
            g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].state = MMI_AGPS_STATE_TERMINATE;

            ret = 0;
        }
    }

    if (ret == 0)
    {
        local_param_ptr = (mmi_ss_aerp_end_req_struct*)construct_local_para(sizeof(mmi_ss_aerp_end_req_struct), TD_CTRL);

        local_param_ptr->cause = 0;
        local_param_ptr->ss_id = g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].area_info.ss_id;
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        if (g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].src_mod != MOD_NIL)
        {
            ilm_ptr->dest_mod_id = g_gps_mgr_cp_ctx.mtlr_ae_req_list[i].src_mod;
        }
        else
        {
            ilm_ptr->dest_mod_id = MOD_L4C;
        }
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_AERP_END_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

        msg_send_ext_queue(ilm_ptr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_AERP_END_REQ_MSG);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_check_area_event
 * DESCRIPTION
 *  check if area event is happen
 * PARAMETERS
 *  index - mtlr ae request index
 * RETURNS
 *  result
 *****************************************************************************/
static MMI_BOOL mmi_gps_mgr_check_area_event(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[7];
    U8 lcs_areaIdentification[MAX_PLMN_STRING_LEN + 1 + 4];
    U8 l4c_areaIdentification[MAX_PLMN_STRING_LEN + 1 + 4];
    L4C_SS_LCS_AreaEventRequestArg *lcs_area_info_p = &g_gps_mgr_cp_ctx.mtlr_ae_req_list[index].area_info.aerq;
    U8 i;
    U8 j;
    U32 event_type = 0;
    MMI_BOOL same_of_cur_area = MMI_FALSE;
    MMI_BOOL same_of_last_area = MMI_FALSE;
    U8 num_cmp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_type = (U32)lcs_area_info_p->deferredLocationEventType.stringData[0];

    for (i = 0; i < lcs_area_info_p->areaEventInfo.areaDefinition.areaList.numElements; i++)
    {
        switch (lcs_area_info_p->areaEventInfo.areaDefinition.areaList.element[i].areaType)
        {
            case L4C_SS_AreaType_countryCode:
                num_cmp = 3;
                break;
            case L4C_SS_AreaType_plmnId:
                num_cmp = 6;
                break;
            case L4C_SS_AreaType_locationAreaId:
                num_cmp = 8;
                break;
            case L4C_SS_AreaType_routingAreaId:
                num_cmp = 9;
                break;
            case L4C_SS_AreaType_cellGlobalId:
            case L4C_SS_AreaType_utranCellId:
                num_cmp = MAX_PLMN_STRING_LEN + 1 + 4;
                break;
        }

        memset(temp, 0, sizeof(U8) * 7);
        memcpy(
            temp,
            lcs_area_info_p->areaEventInfo.areaDefinition.areaList.element[i].areaIdentification.stringData,
            sizeof(U8) * lcs_area_info_p->areaEventInfo.areaDefinition.areaList.element[i].areaIdentification.numOctets);

        lcs_areaIdentification[0] = 0x30 + (temp[0] & 0x0F);
        lcs_areaIdentification[1] = 0x30 + ((temp[0] & 0xF0) >> 4);
        lcs_areaIdentification[2] = 0x30 + (temp[1] & 0x0F);
        lcs_areaIdentification[3] = 0x30 + (temp[2] & 0x0F);
        lcs_areaIdentification[4] = 0x30 + ((temp[2] & 0xF0) >> 4);
        if ((temp[1] & 0xF0) == 0xF0)    /* 5-digit MCC/MNC */
        {
            lcs_areaIdentification[5] = 0;
        }
        else    /* 6-digit MCC/MNC */
        {
            lcs_areaIdentification[5] = 0x30 + ((temp[1] & 0xF0) >> 4);
            lcs_areaIdentification[6] = 0;
        }
        memcpy(&lcs_areaIdentification[MAX_PLMN_STRING_LEN + 1], &temp[3], sizeof(U8) * 4);

        memset(l4c_areaIdentification, 0, sizeof(U8) * (MAX_PLMN_STRING_LEN + 1 + 4));
        memcpy(&l4c_areaIdentification[0], g_gps_mgr_cp_ctx.cur_area_info.plmn, sizeof(U8) * (MAX_PLMN_STRING_LEN + 1));
        memcpy(&l4c_areaIdentification[MAX_PLMN_STRING_LEN + 1], g_gps_mgr_cp_ctx.cur_area_info.lac, sizeof(U8) * 2);


        for (j = 0; j < num_cmp; j++)
        {
            if (lcs_areaIdentification[j] != l4c_areaIdentification[j])
            {
                break;
            }
        }

        if (j == num_cmp)
        {
            same_of_cur_area = MMI_TRUE;
        }

        memset(l4c_areaIdentification, 0, sizeof(U8) * (MAX_PLMN_STRING_LEN + 1 + 4));
        memcpy(&l4c_areaIdentification[0], g_gps_mgr_cp_ctx.last_area_info.plmn, sizeof(U8) * (MAX_PLMN_STRING_LEN + 1));
        memcpy(&l4c_areaIdentification[MAX_PLMN_STRING_LEN + 1], g_gps_mgr_cp_ctx.last_area_info.lac, sizeof(U8) * 2);


        for (j = 0; j < num_cmp; j++)
        {
            if (lcs_areaIdentification[j] != l4c_areaIdentification[j])
            {
                break;
            }
        }

        if (j == num_cmp)
        {
            same_of_last_area = MMI_TRUE;
        }

        if (((event_type & L4C_SS_DeferredLocationEventType_enteringIntoArea) && !same_of_last_area && same_of_cur_area) ||
            ((event_type & L4C_SS_DeferredLocationEventType_leavingFromArea) && same_of_last_area && !same_of_cur_area) ||
            ((event_type & L4C_SS_DeferredLocationEventType_beingInsideArea) && same_of_cur_area))
        {
            return MMI_TRUE;
        }
    }

    if (event_type & L4C_SS_DeferredLocationEventType_msAvailable)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_start_molr
 * DESCRIPTION
 *  start a molr request
 * PARAMETERS
 *  molr_info - molr information
 *  req_id - request id
 *  callback - callback
 * RETURNS
 *  result
 *****************************************************************************/
S32 mmi_gps_mgr_start_molr(
    mmi_ss_molr_begin_req_struct *molr_info,
    mdi_gps_uart_work_mode_enum gps_mode,
    U16* req_id,
    void (*callback)(S32 type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_gps_mgr_start_molr_internal(molr_info, gps_mode, MMI_FALSE, MMI_FALSE, 0, req_id, callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_start_molr_internal
 * DESCRIPTION
 *  start a molr request
 * PARAMETERS
 *  molr_info - molr information
 *  req_id - request id
 *  callback - callback
 * RETURNS
 *  result
 *****************************************************************************/
static S32 mmi_gps_mgr_start_molr_internal(
    mmi_ss_molr_begin_req_struct *molr_info,
    mdi_gps_uart_work_mode_enum gps_mode,
    MMI_BOOL is_send_location,
    MMI_BOOL is_single,
    U32 delay,
    U16* req_id,
    void (*callback)(S32 type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 index;
    MMI_BOOL need_open_gps;
    MMI_BOOL lcs_has_not_work;
    MMI_BOOL need_start_timer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_START_MOLR);

    if (!mmi_gps_check_if_can_use_agps())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_CAN_NOT_USE_AGPS);
        return MMI_GPS_MGR_RESULT_AGPS_OFF;
    }

    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }

    index = i;

    if (index == MAX_MOLR_REQ_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_REQ_LIST_FULL);
        return MMI_GPS_MGR_RESULT_MORE_REQUEST;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_REQ_INDEX, index);
    memcpy(&g_gps_mgr_cp_ctx.molr_req_list[index].molr_info, molr_info, sizeof(mmi_ss_molr_begin_req_struct));
    g_gps_mgr_cp_ctx.molr_req_list[index].gps_mode = gps_mode;
    g_gps_mgr_cp_ctx.molr_req_list[index].callback = callback;
    g_gps_mgr_cp_ctx.molr_req_list[index].is_send_location = is_send_location;
    g_gps_mgr_cp_ctx.molr_req_list[index].is_single = is_single;
    g_gps_mgr_cp_ctx.molr_req_list[index].delay = delay;
    g_gps_mgr_cp_ctx.molr_req_list[index].last_send_time = 0;
    g_gps_mgr_cp_ctx.molr_req_list[index].is_used = MMI_TRUE;
    g_gps_mgr_cp_ctx.molr_req_list[index].state = MMI_AGPS_STATE_START;
    g_gps_mgr_cp_ctx.molr_req_list[index].is_first = MMI_TRUE;

    /* include sim 1 */
    g_gps_mgr_cp_ctx.molr_req_list[index].src_mod = MOD_L4C;

    {
        #if MMI_SIM_TOTAL > 1
            mmi_gps_setting_prefer_sim_enum prefer_sim;
            prefer_sim = mmi_gps_setting_get_sim();

            if (prefer_sim == MMI_GPS_SETTING_PREFER_SIM_NO2)
            {
                g_gps_mgr_cp_ctx.molr_req_list[index].src_mod = MOD_L4C_2;
            }
        #endif

        #if MMI_SIM_TOTAL > 2
            else if (prefer_sim == MMI_GPS_SETTING_PREFER_SIM_NO3)
            {
                g_gps_mgr_cp_ctx.molr_req_list[index].src_mod = MOD_L4C_3;
            }
        #endif

        #if MMI_SIM_TOTAL > 3
            else if (prefer_sim == MMI_GPS_SETTING_PREFER_SIM_NO4)
            {
                g_gps_mgr_cp_ctx.molr_req_list[index].src_mod = MOD_L4C_4;
            }
        #endif
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_STATE_CHANGE, index, MMI_AGPS_STATE_START);
    g_gps_mgr_cp_ctx.molr_req_list[index].req_id = g_gps_mgr_cp_ctx.cur_id;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_cp_ctx.molr_req_list[index].req_id);
    g_gps_mgr_cp_ctx.cur_id++;

    need_open_gps = MMI_TRUE;
    lcs_has_not_work = MMI_TRUE;
    need_start_timer = MMI_TRUE;
    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_TRUE)
        {
            if (i != index)
            {
                if (g_gps_mgr_cp_ctx.molr_req_list[i].gps_mode == gps_mode)
                {
                    need_open_gps = MMI_FALSE;
                }
                if (g_gps_mgr_cp_ctx.molr_req_list[i].is_send_location == MMI_TRUE)
                {
                    need_start_timer = MMI_TRUE;
                }
            }

            if (g_gps_mgr_cp_ctx.molr_req_list[i].state == MMI_AGPS_STATE_WAIT_POS ||
                g_gps_mgr_cp_ctx.molr_req_list[i].state == MMI_AGPS_STATE_WORKING)
            {
                lcs_has_not_work = MMI_FALSE;
            }
        }
    }

    if (need_open_gps)
    {
        g_gps_mgr_cp_ctx.port = mmi_gps_get_port_number();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_OPRN_GPS, g_gps_mgr_cp_ctx.port, gps_mode);
        g_gps_mgr_cp_ctx.is_ready = MMI_FALSE;
        if (mdi_gps_uart_open(g_gps_mgr_cp_ctx.port, gps_mode, mmi_gps_mgr_molr_gps_callback) < 0)
        {
            mmi_gps_mgr_clean_molr_req_item(index);
            return MMI_GPS_MGR_RESULT_OPEN_GPS_FAIL;
        }
        mdi_gps_register_p_callback(mmi_gps_mgr_switch_mode_callback);

        mdi_gps_set_work_port((U8)g_gps_mgr_cp_ctx.port);
    }

    if (!lcs_has_not_work || g_gps_mgr_cp_ctx.is_pos)
    {
        g_gps_mgr_cp_ctx.molr_req_list[index].state = MMI_AGPS_STATE_WAIT_POS;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_STATE_CHANGE, index, MMI_AGPS_STATE_WAIT_POS);
    }
    else
    {
        mmi_gps_mgr_send_mmi_ss_molr_begin_req(index);
        g_gps_mgr_cp_ctx.molr_req_list[index].state = MMI_AGPS_STATE_WORKING;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_STATE_CHANGE, index, MMI_AGPS_STATE_WORKING);
    }

    if (need_start_timer)
    {
        gui_cancel_timer(mmi_gps_mgr_send_location);
        gui_start_timer(1000, mmi_gps_mgr_send_location);
    }

    *req_id = g_gps_mgr_cp_ctx.molr_req_list[index].req_id;
    return MMI_GPS_MGR_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_stop_molr
 * DESCRIPTION
 *  stop a molr request
 * PARAMETERS
 *  req_id - request id
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_gps_mgr_stop_molr(U16 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_agps_cp_abort_req_struct *local_param_ptr;
    U8 i;
    U8 index;
    MMI_BOOL need_close_gps;
    MMI_BOOL need_cancel_timer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_STOP_MOLR);
    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.molr_req_list[i].req_id == req_id)
        {
            break;
        }
    }

    index = i;

    if (index == MAX_MOLR_REQ_NUM)
    {
        return MMI_GPS_MGR_RESULT_INVALID_REQ_ID;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_REQ_INDEX, index);
    need_close_gps = MMI_TRUE;
    need_cancel_timer = MMI_TRUE;
    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_TRUE)
        {
            if (i != index)
            {
                if (g_gps_mgr_cp_ctx.molr_req_list[i].gps_mode == g_gps_mgr_cp_ctx.molr_req_list[index].gps_mode)
                {
                    need_close_gps = MMI_FALSE;
                    break;
                }
                if (g_gps_mgr_cp_ctx.molr_req_list[i].is_send_location == MMI_TRUE)
                {
                    need_cancel_timer = MMI_FALSE;
                    break;
                }
            }
        }
    }

    if (need_close_gps)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_CLOSE_GPS, g_gps_mgr_cp_ctx.port, g_gps_mgr_cp_ctx.molr_req_list[index].gps_mode);
        mdi_gps_uart_close(g_gps_mgr_cp_ctx.port,
                           g_gps_mgr_cp_ctx.molr_req_list[index].gps_mode,
                           mmi_gps_mgr_molr_gps_callback);
    }

    if (need_cancel_timer)
    {
        gui_cancel_timer(mmi_gps_mgr_send_location);
    }

    if(g_gps_mgr_cp_ctx.emerge_call == MMI_FALSE){
    /*abort the request*/
    local_param_ptr = (mmi_agps_cp_abort_req_struct*)construct_local_para(sizeof(mmi_agps_cp_abort_req_struct), TD_CTRL);
    local_param_ptr->is_abort_molr = MMI_TRUE; /*only when mmi exit shoud set to true*/
    /*notify NI-LR*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_AGPS_CP_ABORT_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
    } else {
        g_gps_mgr_cp_ctx.emerge_call = MMI_FALSE;
    }

    if (g_gps_mgr_cp_ctx.molr_req_list[index].state == MMI_AGPS_STATE_WORKING)
    {
        mmi_gps_mgr_send_mmi_ss_molr_end_req(&g_gps_mgr_cp_ctx.molr_req_list[index], MMI_FALSE);
    }

    mmi_gps_mgr_clean_molr_req_item(index);

    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_TRUE)
        {
            break;
        }
    }

    if (i == MAX_MOLR_REQ_NUM)
    {
        g_gps_mgr_cp_ctx.is_pos = MMI_FALSE;
    }

    return MMI_GPS_MGR_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_molr_begin_wait_gps_ready
 * DESCRIPTION
 *  send MMI_SS_MOLR_BEGIN_REQ message
 * PARAMETERS
 *  index - index of molr request list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_molr_begin_wait_gps_ready(void)
{
    static U16 count = 0;

    count++;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MOLR_BEGIN_WAIT_GPS_READY, g_gps_mgr_cp_ctx.is_ready, count);

    if (g_gps_mgr_cp_ctx.molr_req_list[g_gps_mgr_cp_ctx.waiting_index].molr_info.molr.locationMethod == L4C_SS_LocationMethod_msAssistedEOTD)
    {
        mdi_gps_uart_cmd(mdi_get_gps_port(),MDI_GPS_UART_GPS_SWITCH_MODE_MA, NULL);
    }
    else
    {
        mdi_gps_uart_cmd(mdi_get_gps_port(),MDI_GPS_UART_GPS_SWITCH_MODE_MB, NULL);
    }
    if (count>30)
    {
        g_gps_mgr_cp_ctx.is_ready = MMI_TRUE;
    }
    if (g_gps_mgr_cp_ctx.is_ready == MMI_TRUE)
    {
        mmi_gps_mgr_send_mmi_ss_molr_begin_req(g_gps_mgr_cp_ctx.waiting_index);
    }
    else
    {
        gui_start_timer(500, mmi_gps_mgr_send_mmi_ss_molr_begin_wait_gps_ready);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_molr_begin_req
 * DESCRIPTION
 *  send MMI_SS_MOLR_BEGIN_REQ message
 * PARAMETERS
 *  index - index of molr request list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_molr_begin_req(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_molr_begin_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    gps_pos_qop_struct qop;
    gps_pos_result_struct history_pos;
    cp_mmi_req_assist_data_struct gps_data;
    U8 encodebuf[CP_MAX_GPS_ASSISTANCE_DATA_LEN];
    U16 bitmap;
    U8  oct_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MOLR_BEGIN_REQ, index);

#ifdef __MMI_AGPS_CP_USE_QUERY_BITMAP__
    if (g_gps_mgr_cp_ctx.is_ready == MMI_FALSE)
    {
        g_gps_mgr_cp_ctx.waiting_index = index;
        mmi_gps_mgr_send_mmi_ss_molr_begin_wait_gps_ready();

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_RETURN, g_gps_mgr_cp_ctx.is_ready, __LINE__);

        return;
    }

    local_param_ptr = (mmi_ss_molr_begin_req_struct*)construct_local_para(sizeof(mmi_ss_molr_begin_req_struct), TD_CTRL);
    /*get the old assist data request*/
    /*
        GPS_ASSIST_MASK_ALMANAC                 (1<<0)
        GPS_ASSIST_MASK_UTC                     (1<<1)
        GPS_ASSIST_MASK_IONOSPHERE              (1<<2)
        GPS_ASSIST_MASK_NAVIGATION_MODEL        (1<<3)
        GPS_ASSIST_MASK_DGPS_CORRECTION         (1<<4)
        GPS_ASSIST_MASK_REF_LOCATION            (1<<5)
        GPS_ASSIST_MASK_REF_TIME                (1<<6)
        GPS_ASSIST_MASK_ACQUISITION             (1<<7)
        GPS_ASSIST_MASK_RTI                     (1<<8)
    */
    mdi_gps_agps_get_history_pos(&qop,&history_pos,&bitmap);
    memset(&gps_data, 0,sizeof(cp_mmi_req_assist_data_struct));
    gps_data.almanac =            (bitmap & GPS_ASSIST_MASK_ALMANAC)?MMI_TRUE:MMI_FALSE;
    gps_data.utc_model =          (bitmap & GPS_ASSIST_MASK_UTC)?MMI_TRUE:MMI_FALSE;
    gps_data.ionospheric_model =  (bitmap & GPS_ASSIST_MASK_IONOSPHERE)?MMI_TRUE:MMI_FALSE;
    gps_data.dgps_correction =    (bitmap & GPS_ASSIST_MASK_DGPS_CORRECTION)?MMI_TRUE:MMI_FALSE;
    gps_data.ref_location =       (bitmap & GPS_ASSIST_MASK_REF_LOCATION)?MMI_TRUE:MMI_FALSE;
    gps_data.ref_time =           (bitmap & GPS_ASSIST_MASK_REF_TIME)?MMI_TRUE:MMI_FALSE;
    gps_data.acquisition_assist = (bitmap & GPS_ASSIST_MASK_ACQUISITION)?MMI_TRUE:MMI_FALSE;
    gps_data.realtime_integrity = (bitmap & GPS_ASSIST_MASK_RTI)?MMI_TRUE:MMI_FALSE;
    gps_data.navigation_model =   (bitmap & GPS_ASSIST_MASK_NAVIGATION_MODEL)?MMI_TRUE:MMI_FALSE;
    oct_num = AsnEncode_SS2_gpsAssistanceData(&gps_data, encodebuf);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_DATA, bitmap, oct_num, encodebuf[0], encodebuf[1], encodebuf[2], encodebuf[3], encodebuf[4], encodebuf[5]);
    if (oct_num > 0 && oct_num <= 38)
    {
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.numOctets = oct_num;
        memcpy(g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData, encodebuf, oct_num);
    }
    else
    {
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.numOctets = 6;
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData[0] = 0x6F;
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData[1] = 0;
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData[2] = 0;
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData[3] = 0;
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData[4] = 0;
        g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr.gpsAssistanceData.stringData[5] = 0;
    }
#else
    local_param_ptr = (mmi_ss_molr_begin_req_struct*)construct_local_para(sizeof(mmi_ss_molr_begin_req_struct), TD_CTRL);
#endif

    memcpy(&local_param_ptr->molr, &g_gps_mgr_cp_ctx.molr_req_list[index].molr_info.molr, sizeof(L4C_SS_LCS_MOLRArg));

    local_param_ptr->ss_id = g_gps_mgr_cp_ctx.molr_req_list[index].req_id;
    local_param_ptr->is_initial = g_gps_mgr_cp_ctx.molr_req_list[index].is_first;
    g_gps_mgr_cp_ctx.molr_req_list[index].is_first = MMI_FALSE;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    if (g_gps_mgr_cp_ctx.molr_req_list[index].src_mod != MOD_NIL)
    {
        ilm_ptr->dest_mod_id = g_gps_mgr_cp_ctx.molr_req_list[index].src_mod;
    }
    else
    {
        ilm_ptr->dest_mod_id = MOD_L4C;
    }
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MOLR_BEGIN_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MOLR_BEGIN_REQ_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_mmi_ss_molr_begin_rsp_hdlr
 * DESCRIPTION
 *  process MMI_SS_MOLR_BEGIN_RSP message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_mmi_ss_molr_begin_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_molr_begin_rsp_struct *mmi_ss_molr_begin_rsp_p = (mmi_ss_molr_begin_rsp_struct*)msg;
    U8 i;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_BEGIN_RSP);

    if(g_gps_mgr_cp_ctx.need_cipher_key == MMI_TRUE){
	 mmi_gps_mgr_send_agps_key_update_rsp(msg);
	 g_gps_mgr_cp_ctx.need_cipher_key = MMI_FALSE;
         return;
    }

    for (i = 0; i < MAX_MOLR_REQ_NUM; i++)
    {
        if (g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_cp_ctx.molr_req_list[i].state == MMI_AGPS_STATE_WORKING)
        {
            break;
        }
    }
    index = i;
    if (index == MAX_MOLR_REQ_NUM)
    {
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_REQ_INDEX, index);

    if (mmi_ss_molr_begin_rsp_p->result)
    {
        mmi_gps_mgr_send_mmi_ss_molr_end_req(&g_gps_mgr_cp_ctx.molr_req_list[i],MMI_TRUE);
    }

    g_gps_mgr_cp_ctx.molr_req_list[index].state = MMI_AGPS_STATE_WAIT_POS;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_MOLR_STATE_CHANGE, index, MMI_AGPS_STATE_WAIT_POS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_mmi_ss_molr_end_req
 * DESCRIPTION
 *  send MMI_SS_MOLR_END_REQ message
 * PARAMETERS
 *  is_success - response
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_mmi_ss_molr_end_req(mmi_gps_manager_molr_req_struct *molr_req_p, MMI_BOOL is_success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_molr_end_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MOLR_END_REQ);
    local_param_ptr = (mmi_ss_molr_end_req_struct*)construct_local_para(sizeof(mmi_ss_molr_end_req_struct), TD_CTRL);

    if (is_success)
    {
        local_param_ptr->cause = 0;
    }
    else
    {
        local_param_ptr->cause = (U8)CM_SS_ERR_FACILITYNOTSUPPORTED;
    }
    local_param_ptr->ss_id = molr_req_p->req_id; /*ss_id*/

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    if (molr_req_p->src_mod != MOD_NIL)
    {
        ilm_ptr->dest_mod_id = molr_req_p->src_mod;
    }
    else
    {
        ilm_ptr->dest_mod_id = MOD_L4C;
    }
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MOLR_END_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MOLR_END_REQ_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_clean_molr_req_item
 * DESCRIPTION
 *  clean a molr request item
 * PARAMETERS
 *  index - index of molr request list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_clean_molr_req_item(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gps_mgr_cp_ctx.molr_req_list[index].is_used == MMI_FALSE)
    {
        return;
    }

    g_gps_mgr_cp_ctx.molr_req_list[index].is_used = MMI_FALSE;
    g_gps_mgr_cp_ctx.molr_req_list[index].state = MMI_AGPS_STATE_TERMINATE;
    g_gps_mgr_cp_ctx.molr_req_list[index].src_mod = MOD_NIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_molr_gps_callback
 * DESCRIPTION
 *  handle gps callback of molr request
 * PARAMETERS
 *  type - gps info type
 *  buffer - pointer of info buffer
 *  length - length of info buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_molr_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mdi_gps_nmea_gsa_struct *gsa_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_GPS_CALLBACK, type);

    if (type == MDI_GPS_PARSER_NMEA_GSA)
    {
        gsa_data = (mdi_gps_nmea_gsa_struct*)buffer;
        if (gsa_data->fix_mode == '2' || gsa_data->fix_mode == '3')
        {
            g_gps_mgr_cp_ctx.is_pos = MMI_TRUE;
        }
        else
        {
            g_gps_mgr_cp_ctx.is_pos = MMI_FALSE;
        }
    }

    for (i = 0; i <MAX_MOLR_REQ_NUM; i++)
    {
        if(g_gps_mgr_cp_ctx.molr_req_list[i].is_used == MMI_TRUE)
        {
            if (g_gps_mgr_cp_ctx.is_pos &&
                g_gps_mgr_cp_ctx.molr_req_list[i].state == MMI_AGPS_STATE_WORKING)
            {
                //mmi_gps_mgr_send_mmi_ss_molr_end_req(MMI_FALSE);

                //g_gps_mgr_cp_ctx.molr_req_list[i].state = MMI_AGPS_STATE_WAIT_POS;
            }

            if ((type == MDI_GPS_PARSER_RAW_DATA &&
                 g_gps_mgr_cp_ctx.molr_req_list[i].gps_mode == MDI_GPS_UART_MODE_RAW_DATA) ||
                (type != MDI_GPS_PARSER_RAW_DATA &&
                 g_gps_mgr_cp_ctx.molr_req_list[i].gps_mode != MDI_GPS_UART_MODE_RAW_DATA) &&
                g_gps_mgr_cp_ctx.molr_req_list[i].is_send_location == MMI_FALSE)
            {
                g_gps_mgr_cp_ctx.molr_req_list[i].callback(type, buffer, length);
            }
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_molr_gps_callback
 * DESCRIPTION
 *  handle gps callback of molr request
 * PARAMETERS
 *  type - gps info type
 *  buffer - pointer of info buffer
 *  length - length of info buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_switch_mode_callback(mdi_gps_parser_info_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MDI_GPS_PARSER_P_GPS_MODE_SWITCH_OK)
    {
        g_gps_mgr_cp_ctx.is_ready = MMI_TRUE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_GPS_READY, g_gps_mgr_cp_ctx.is_ready, __LINE__);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_start_send_location
 * DESCRIPTION
 *  start send location
 * PARAMETERS
 *  molr_info - molr information
 *  req_id - request id
 *  callback - callback
 * RETURNS
 *  result
 *****************************************************************************/
S32 mmi_gps_mgr_start_send_location(
    mmi_ss_molr_begin_req_struct * molr_info,
    U16* req_id,
    MMI_BOOL is_single,
    U32 delay,
    void (*callback)(S32 type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_gps_mgr_start_molr_internal(
                molr_info,
                MDI_GPS_UART_MODE_LOCATION,
                MMI_TRUE,
                is_single,
                delay,
                req_id,
                callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_stop_send_location
 * DESCRIPTION
 *  stop send location
 * PARAMETERS
 *  req_id - request id
 * RETURNS
 *  result
 *****************************************************************************/
S32 mmi_gps_mgr_stop_send_location(U16 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_gps_mgr_stop_molr(req_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_location
 * DESCRIPTION
 *  send location
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_location(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U32 time;
    U32 interval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gps_mgr_cp_ctx.is_pos)
    {
        for (i = 0; i <MAX_MOLR_REQ_NUM; i++)
        {
            if (g_gps_mgr_cp_ctx.molr_req_list[i].is_send_location == MMI_TRUE)
            {
                if (g_gps_mgr_cp_ctx.molr_req_list[i].is_single == MMI_TRUE)
                {
                    /* send location */
                    g_gps_mgr_cp_ctx.molr_req_list[i].callback(255, NULL, 0);
                    mmi_gps_mgr_stop_send_location(g_gps_mgr_cp_ctx.molr_req_list[i].req_id);
                }
                else
                {
                    kal_get_time(&time);
                    interval = (U32)kal_ticks_to_milli_secs(time - g_gps_mgr_cp_ctx.molr_req_list[i].last_send_time) / 1000;
                    if (interval >= g_gps_mgr_cp_ctx.molr_req_list[i].delay)
                    {
                        /* send location */
                        g_gps_mgr_cp_ctx.molr_req_list[i].callback(255, NULL, 0);
                        g_gps_mgr_cp_ctx.molr_req_list[i].last_send_time = time;
                    }
                }
            }
        }
    }
    gui_start_timer(1000, mmi_gps_mgr_send_location);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_mgr_decode_cbsdcs
* DESCRIPTION
*   This function decodes the data coding scheme.
*
* PARAMETERS
*  a  IN       dcs
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
static mmi_gps_mgr_dcs_enum mmi_gps_mgr_decode_cbsdcs(U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_gps_mgr_dcs_enum alphabet_type;
    U8 coding_group = (dcs >> 4);
    U8 coding_bits = (dcs & 0x0f);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alphabet_type = MMI_GPS_MGR_DEFAULT_DCS;

    switch (coding_group)
    {
        case 0x00:
            alphabet_type = MMI_GPS_MGR_DEFAULT_DCS;
            break;
        case 0x01:
            if (coding_bits == 0)
                alphabet_type = MMI_GPS_MGR_DEFAULT_DCS;
            else if (coding_bits == 1)
                alphabet_type = MMI_GPS_MGR_UCS2_DCS;
            else
                alphabet_type = MMI_GPS_MGR_RESERVED_DCS;
            break;
        case 0x02:
            alphabet_type = MMI_GPS_MGR_DEFAULT_DCS;
            if (coding_bits > 0x04)
            {
                alphabet_type = MMI_GPS_MGR_RESERVED_DCS;
            }
            break;
        case 0x03:
            alphabet_type = MMI_GPS_MGR_DEFAULT_DCS;
            break;
        case 0x04:                     /* General Data Coding Scheme */
        case 0x05:
        case 0x06:
        case 0x07:
            alphabet_type = (mmi_gps_mgr_dcs_enum) (dcs & MMI_GPS_MGR_RESERVED_DCS);
            break;

        case 0x08:                     /* 0x08 - 0x0d: Reserved */
        case 0x09:                     /* UDH structure, do it in the future */
        case 0x0a:
        case 0x0b:
        case 0x0c:
        case 0x0d:
        case 0x0e:                     /* defined by WAP forum */
            alphabet_type = MMI_GPS_MGR_RESERVED_DCS;
            break;

        case 0x0f:                     /* Data Coding/Message Class */
            alphabet_type = (mmi_gps_mgr_dcs_enum) (dcs & MMI_GPS_MGR_8BIT_DCS);
            break;
        default:
            alphabet_type = MMI_GPS_MGR_RESERVED_DCS;
            break;
    }

    return alphabet_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_convert_bcd_to_asc
 * DESCRIPTION
 *  convert bcd to asc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_gps_mgr_convert_bcd_to_asc(U8 *source, U8 *dest, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ch1, ch2;
    U8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((source == NULL) || (dest == NULL))
    {
        ASSERT(0);
    }

    while ((source[i] != 0xff) && j < MAX_CC_ADDR_LEN - 1 && i < count)
    {
        ch1 = source[i] & 0x0f;
        ch2 = (source[i] & 0xf0) >> 4;

        *((U8*) dest + j) = mmi_gps_mgr_get_ch_byte_24008(ch1);

        if (ch2 == 0x0f)
        {
            *((U8*) dest + j + 1) = RMMI_END_OF_STRING_CHAR;
            return j + 1;
        }
        else
        {
            *((U8*) dest + j + 1) = mmi_gps_mgr_get_ch_byte_24008(ch2);
        }
        i++;
        j += 2;
    }
    *((U8*) dest + j) = RMMI_END_OF_STRING_CHAR;
    return j;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_get_ch_byte_24008
 * DESCRIPTION
 *  convert bcd to asc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_gps_mgr_get_ch_byte_24008(U8 bcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 digit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bcd <= 9)
    {
        digit = bcd + RMMI_CHAR_0;
    }
    else
    {
        switch (bcd)
        {
            case 0x0a:
                digit = RMMI_CHAR_STAR;
                break;
            case 0x0b:
                digit = RMMI_CHAR_POUND;
                break;
            case 0x0c:
                digit = rmmi_char_a;
                break;
            case 0x0d:
                digit = rmmi_char_b;
                break;
            case 0x0e:
                digit = rmmi_char_c;
                break;
            default:
                digit = RMMI_END_OF_STRING_CHAR;
                break;
        }
    }
    return digit;
}

static void mmi_gps_mgr_agps_new_key_needed_ind_hdlr(void *msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_molr_begin_req_struct molr_info;
    mmi_ss_molr_begin_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    molr_info.molr.molr_Type = L4C_SS_MOLR_Type_deCipheringKeys;
    molr_info.molr.validity = 0;
    molr_info.is_initial = KAL_TRUE;
    molr_info.ss_id = g_gps_mgr_cp_ctx.ss_id++;
    g_gps_mgr_cp_ctx.need_cipher_key = MMI_TRUE;

    local_param_ptr = (mmi_ss_molr_begin_req_struct*)construct_local_para(sizeof(mmi_ss_molr_begin_req_struct), TD_CTRL);

    memcpy(local_param_ptr,&molr_info,sizeof(mmi_ss_molr_begin_req_struct));

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_SS_MOLR_BEGIN_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CP_SEND_MOLR_BEGIN_REQ_MSG);
}

static void mmi_gps_mgr_send_agps_key_update_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_ss_molr_begin_rsp_struct *mmi_ss_molr_begin_rsp_p = (mmi_ss_molr_begin_rsp_struct*)msg;
    mmi_agps_key_update_req_struct *local_param_ptr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/

    local_param_ptr = (mmi_agps_key_update_req_struct*)construct_local_para(sizeof(mmi_agps_key_update_req_struct), TD_CTRL);
    strncpy(local_param_ptr->sib15_current_deciphering_key,mmi_ss_molr_begin_rsp_p->molr_res.decipheringKeys.stringData + 1,7);
    strncpy(local_param_ptr->sib15_next_deciphering_key,mmi_ss_molr_begin_rsp_p->molr_res.decipheringKeys.stringData + 8,7);
    local_param_ptr->sib15_ciphering_key_flag = mmi_ss_molr_begin_rsp_p->molr_res.decipheringKeys.stringData[0];

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_AGPS_KEY_UPDATE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}

#endif /* __AGPS_CONTROL_PLANE__ */
