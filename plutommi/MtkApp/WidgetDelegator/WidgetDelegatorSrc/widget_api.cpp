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
 *   widget_api.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements binding utilities for widget delegator and widget runtime
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
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

extern "C"
{
//#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "app_buff_alloc.h"

//#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
//#include "custom_config.h"

//#include "mmi_include.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "MMIDataType.h"
#include "sim_common_enums.h"
#include "string.h"
}

#include "MMI_features.h"
#ifdef __MMI_GADGET_SUPPORT__

extern "C"
{
#include "ImeiSrvGprot.h"
#include "simctrlsrvgprot.h"
//#include "nwnamesrvgprot.h"
#include "nwinfosrvgprot.h"
#include "cphssrvgprot.h"
#include "conversions.h"
//#include "commonscreens.h"
//#include "commonscreensprot.h"
//#include "simdetectionresdef.h"
#include "idlegprot.h"
#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#endif /*__MMI_URI_AGENT__*/
#include "widget_adp_struct.h"
#include "widget_api.h"
#include "mmi_rp_app_widget_delegator_def.h"
#include "gadget_adp_audio.h"
#include "custom_gadget_config.h"
#include "mmi_rp_app_wgtmgr_def.h"
#include "WgtMgrSrvGprot.h"
#include "SmsSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "ModeSwitchSrvGProt.h"

#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "app_mem.h"
#include "med_utility.h"
#include "GlobalConstants.h"
#include "fs_type.h"
#include "fs_func.h"
#include "PhbSrvGprot.h"
#include "app_str.h"

//#include "gadget_adp_log.h"
#include "vrt_system.h"     /* Add for calling vrt related function which used to adjust framerate */

#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif
}

#include "vadp_p2v_hs.h"
#include "vapp_hs_def.h"
#include "vapp_hs_widget_delegator.h"

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif /*__MTK_INTERNAL__ */

extern void gadget_adp_add_input_event(int id, void *view_handle, int type, int keycode, int x, int y);
extern "C" mmi_ret srv_wgtmgr_usb_notify_hdlr(mmi_event_struct *param);

extern "C" void widget_handle_browse_image_req(void *param);
extern "C" void widget_handle_capture_image_req(void *param);
static void widget_load_widget_response_handler(void *param);
static void widget_notify_content_update(void *param);
static void widget_notify_size_update(void *param);
static void widget_handle_display_dialog_ind(void *param);
static void widget_handle_open_url_ind(void *param);
static void widget_send_sms(WCHAR* number, WCHAR* data, void* user_data);
static void widget_send_sms_rsp(void *user_data, int ret);
static void widget_abort_all_sms_req(void);
int g_confirm_dialog_gid;
void *g_widget_asm = NULL;
widget_sending_sms_struct *g_widget_sms_list = NULL;
widget_contact_op_struct *g_widget_contact_op_list = NULL;


/* For Gadget and LiveWallpaper co-existence case */
kal_mutexid active_mode_mutex = NULL;
bool g_widget_active = false;
bool g_widget_active_mode_entered = false;

static void send_message(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    SEND_ILM(MOD_MMI, dst_id, MMI_GADGET_SAP, ilm_ptr);
}


static void widget_handle_query_device_info_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_query_device_info_cnf_struct *p = (widget_query_device_info_cnf_struct*) construct_local_para(
                                                sizeof(widget_query_device_info_cnf_struct),
                                                TD_RESET);

    mmi_sim_enum sim = (mmi_sim_enum)srv_sim_ctrl_get_one_available_sim();
    srv_nw_info_location_info_struct location_info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* IMEI */
    srv_imei_get_imei((sim == MMI_SIM2) ? MMI_SIM2 : MMI_SIM1, p->imei, sizeof(p->imei));

    if (sim > 0)
    {
        /* IMSI */
        srv_sim_ctrl_get_imsi(sim, p->imsi, sizeof(p->imsi));

        /* MSISDN */
        {
            const U16 *out = srv_cphs_get_msisdn_number(SRV_CPHS_MSISDN_TYPE_LINE1, sim);

            if (out)
            {
                mmi_chset_ucs2_to_utf8_string((kal_uint8 *) p->msisdn, sizeof(p->msisdn), (kal_uint8 *)out);
            }
        }

        /* Cell ID, MNC, MCC */
        if(srv_nw_info_get_location_info(sim, &location_info))
        {
            p->cell_id = location_info.cell_id;

            memcpy(p->network_mnc, location_info.plmn + SRV_MCC_LEN, sizeof(p->network_mnc));
            memcpy(p->network_mcc, location_info.plmn, (sizeof(p->network_mcc) - 1));
        }
    }

    send_message(p, NULL, MSG_ID_WIDGET_QUERY_DEVICE_INFO_CNF, MOD_GADGET);

}


static void widget_handle_terminate_widget_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_terminate_wgt_ind_struct *p = (widget_terminate_wgt_ind_struct*)param;

    VappHsWidgetDelegator *widget = VappHsWidgetDelegator::findByInstancId(p->wgt_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget)
    {
        return;
    }

    widget->onTerminate();
}

static void widget_handle_terminate_all_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_terminate_all_wgt_ind_struct *ind = (widget_terminate_all_wgt_ind_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->type == WIDGET_RESET_MEMORY_FULL)
    {
        /* reset all widget only when out of memory */
        vadp_p2v_hs_widget_reset(VAPP_HS_WIDGET_TYPE_GADGET, STR_ID_WIDGET_MEMORY_FULL);
    }
    else if (ind->type == WIDGET_RESET_NO_POPUP)
    {
        vadp_p2v_hs_widget_reset(VAPP_HS_WIDGET_TYPE_GADGET, 0);
    }

    send_message(NULL, NULL, MSG_ID_WIDGET_TERMINATE_ALL_WGT_CNF, MOD_GADGET);
}



static void widget_send_check_network_access_response(int response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_check_network_access_cnf_struct *p = (widget_check_network_access_cnf_struct*) construct_local_para(
                                                sizeof(widget_check_network_access_cnf_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->response = response; ;

    send_message(p, NULL, MSG_ID_WIDGET_CHECK_NETWORK_ACCESS_CNF, MOD_GADGET);
}



static mmi_ret widget_check_network_access_dialog_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_POPUP_QUIT)
    {
        switch(((mmi_alert_result_evt_struct *)param)->result)
        {
        case MMI_ALERT_CNFM_YES:
            widget_send_check_network_access_response(WIDGET_DLG_RESPONSE_YES);
            break;
        case MMI_ALERT_CNFM_NO:
            widget_send_check_network_access_response(WIDGET_DLG_RESPONSE_NO);
            break;
        case MMI_ALERT_CNFM_CANCEL:
            widget_send_check_network_access_response(WIDGET_DLG_RESPONSE_CANCEL);
            break;
        default:
            return MMI_RET_OK;
        }
        g_confirm_dialog_gid = 0;
    }

    return MMI_RET_OK;
}


static mmi_ret widget_check_sms_access_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_POPUP_QUIT)
    {
        mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)param;
        widget_sms_req_struct *req = (widget_sms_req_struct *)evt->user_tag;
        ASSERT(req);

        switch(evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            widget_send_sms(req->number, req->data, req->user_data);
            break;

        case MMI_ALERT_CNFM_NO:
        case MMI_ALERT_CNFM_CANCEL:
            widget_send_sms_rsp(req->user_data, WIDGET_SMS_NOT_ALLOWED);
            break;
        default:
            return MMI_RET_OK;
        }
        g_confirm_dialog_gid = 0;
        OslMfree(req);
    }

    return MMI_RET_OK;
}


static void widget_handle_check_network_access_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    if (mmi_frm_group_get_active_id() != GRP_ID_WIDGET_VIEW)
    {
        arg.parent_id = mmi_idle_get_group_id();
    }
    else
    {
        arg.parent_id = GRP_ID_WIDGET_VIEW;
    }

    arg.f_enter_history = 1;
    arg.callback = widget_check_network_access_dialog_callback;

    /* This is a dirty fix to let widget delegator know it is an interrupt raised by gadget engine.
       The function of wiget delegator might get called during mmi_confirm_display and
       g_confirm_dialog_gid is still 0 at that moment .*/
    g_confirm_dialog_gid = -1;

    g_confirm_dialog_gid = mmi_confirm_display((WCHAR *)GetString(STR_ID_WIDGET_ALLOW_NETWORK_ACCESS), MMI_EVENT_QUERY, &arg);

}


static void widget_check_access(mmi_id str_id, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    if (mmi_frm_group_get_active_id() != GRP_ID_WIDGET_VIEW)
    {
        arg.parent_id = mmi_idle_get_group_id();
    }
    else
    {
        arg.parent_id = GRP_ID_WIDGET_VIEW;
    }

    arg.f_enter_history = 1;
    arg.callback = callback;
    arg.user_tag = user_data;

    /* This is a dirty fix to let widget delegator know it is an interrupt raised by gadget engine.
       The function of wiget delegator might get called during mmi_confirm_display and
       g_confirm_dialog_gid is still 0 at that moment .*/
    g_confirm_dialog_gid = -1;
    g_confirm_dialog_gid = mmi_confirm_display((WCHAR *)GetString(str_id), MMI_EVENT_QUERY, &arg);
}


static void widget_send_sms_callback(srv_sms_callback_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_send_sms_rsp_struct *rsp = (widget_send_sms_rsp_struct *)construct_local_para(
                                                sizeof(widget_send_sms_rsp_struct),
                                                TD_RESET);
    widget_sending_sms_struct *temp = g_widget_sms_list;
    widget_sending_sms_struct *prev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->result == MMI_TRUE)
    {
        rsp->ret = WIDGET_SMS_OK;
    }
    else
    {
        rsp->ret = data->cause;
    }
    rsp->user_data = data->user_data;

    while (temp != NULL)
    {
        if (temp->user_data == data->user_data)
        {
            if (prev != NULL)
            {
                prev->next = temp->next;
            }
            else
            {
                g_widget_sms_list = temp->next;
            }
            OslMfree(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    send_message(rsp, NULL, MSG_ID_WIDGET_SEND_SMS_RSP, MOD_GADGET);
}


static void widget_send_sms(WCHAR* number, WCHAR* data, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim = (mmi_sim_enum)srv_sim_ctrl_get_one_available_sim();
    srv_sms_sim_enum sms_sim= SRV_SMS_SIM_1;
    SMS_HANDLE sms_handle;
    U16 content_size;
    widget_sending_sms_struct *new_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim == MMI_SIM1 && srv_mode_switch_get_network_mode(MMI_SIM1) == SRV_MODE_SWITCH_OFF)
    {
        sim = MMI_SIM2;
    }

    if (sim == MMI_SIM2)
    {
        sms_sim = SRV_SMS_SIM_2;
    }

    sms_handle = srv_sms_get_send_handle();

    /* insert a new node to sms list */
    new_node = (widget_sending_sms_struct *)OslMalloc(sizeof(widget_sending_sms_struct));
    new_node->next = g_widget_sms_list;
    g_widget_sms_list = new_node;
    new_node->sms_handle = sms_handle;
    new_node->user_data = user_data;

    /* set related info and send */
    srv_sms_set_address(sms_handle, (char*)number);
    srv_sms_set_sim_id(sms_handle, sms_sim);
    srv_sms_set_content_dcs(sms_handle, SRV_SMS_DCS_UCS2);
    content_size = mmi_ucs2strlen((const CHAR*)data) * ENCODING_LENGTH;
    srv_sms_set_content(sms_handle, (char*)data, content_size);
    srv_sms_send_msg(sms_handle, widget_send_sms_callback, user_data);
}


static void widget_abort_all_sms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_sending_sms_struct *next = g_widget_sms_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (next != NULL)
    {
        srv_sms_abort_send(next->sms_handle);
        next = next->next;
    }
}


static void widget_send_sms_rsp(void *user_data, int ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_send_sms_rsp_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (widget_send_sms_rsp_struct *)construct_local_para(
                                         sizeof(widget_send_sms_rsp_struct),
                                         TD_RESET);

    rsp->ret = ret;
    rsp->user_data = user_data;
    send_message(rsp, NULL, MSG_ID_WIDGET_SEND_SMS_RSP, MOD_GADGET);
}



static void widget_send_sms_req_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_send_sms_req_struct *req = (widget_send_sms_req_struct*)param;
    widget_sms_req_struct *sms = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_valid() == MMI_FALSE)
    {
        widget_send_sms_rsp(req->user_data, WIDGET_SMS_NOT_AVAILABLE);
    }
    else if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        widget_send_sms_rsp(req->user_data, SRV_SMS_CAUSE_NOT_READY);
    }
    else if (srv_sms_check_ucs2_number((char*)req->number) == MMI_FALSE)
    {
        widget_send_sms_rsp(req->user_data, SRV_SMS_CAUSE_NUMBER_INVALID);
    }
    else
    {
        sms = (widget_sms_req_struct *)OslMalloc(sizeof(widget_sms_req_struct));
        sms->user_data = req->user_data;
        kal_mem_cpy(sms->data, req->data, sizeof(sms->data));
        kal_mem_cpy(sms->number, req->number, sizeof(sms->number));
        widget_check_access(STR_ID_WIDGET_ALLOW_SEND_SMS, widget_check_sms_access_callback, sms);
    }
}

static void widget_send_contact_op_rsp(void *req, int ret, int index, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_contact_general_op_finished_ind_struct *ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (widget_contact_general_op_finished_ind_struct *)construct_local_para(
                                         sizeof(widget_contact_general_op_finished_ind_struct),
                                         TD_RESET);

    ind->ret = ret;
    ind->req = req;
    ind->contact_info = info;
    ind->store_index = index;
    send_message(ind, NULL, MSG_ID_WIDGET_CONTACT_GENERAL_OP_FINISHED_IND, MOD_GADGET);
}

void widget_contact_callback_func(S32 result, U16 store_index, void *user_data)
{

    widget_contact_op_struct *temp = g_widget_contact_op_list;
    widget_contact_op_struct *prev = NULL;
    void *contact_info = NULL;
    while (temp != NULL)
    {
        if (temp->user_data == user_data)
        {
            if (prev != NULL)
            {
                prev->next = temp->next;
            }
            else
            {
                g_widget_contact_op_list = temp->next;
            }
            contact_info = temp->info;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (result == SRV_PHB_NO_ERROR)
    {
        widget_send_contact_op_rsp(user_data, 1, store_index, contact_info);
    }
    else
    {
        widget_send_contact_op_rsp(user_data, 0, NULL, contact_info);
    }

}

static void widget_commit_contact_req_hdlr(void *param)
{
    widget_commit_contact_req_struct *req = (widget_commit_contact_req_struct*)param;

    if (srv_phb_check_storage_accessible(req->storage) == MMI_TRUE)
    {
        if (req->store_index != -1)
        {
            srv_phb_oplib_update_contact(req->store_index , (srv_phb_contact_info_struct *)req->contact_info, widget_contact_callback_func, req->user_data);
        }
        else
        {
            srv_phb_oplib_add_contact(req->storage, SRV_PHB_INVALID_INDEX, (srv_phb_contact_info_struct *)req->contact_info, widget_contact_callback_func, req->user_data);
        }
        widget_contact_op_struct *node = (widget_contact_op_struct *)OslMalloc(sizeof(widget_contact_op_struct));
        node->info = req->contact_info;
        node->user_data = req->user_data;
        node->next = g_widget_contact_op_list;
        g_widget_contact_op_list = node;

    }
    else
    {
        widget_send_contact_op_rsp(req->user_data, 0, 0, NULL);
    }
}


static void widget_delete_contact_req_hdlr(void *param)
{
    widget_delete_contact_req_struct *req = (widget_delete_contact_req_struct*)param;

    if (srv_phb_check_storage_accessible(req->storage) == MMI_TRUE)
    {
        srv_phb_oplib_delete_contact(req->store_index, widget_contact_callback_func, req->user_data);
    }
    else
    {
        widget_send_contact_op_rsp(req->user_data, 0, 0, NULL);
    }
}

static void widget_find_contacts_req_hdlr(void *param)
{
    widget_find_contacts_req_struct *req = (widget_find_contacts_req_struct*)param;
    widget_find_contacts_rsp_struct *rsp = (widget_find_contacts_rsp_struct *)construct_local_para(
                                         sizeof(widget_find_contacts_rsp_struct),
                                         TD_RESET);
    if (srv_phb_check_storage_accessible(req->storage) == MMI_TRUE)
    {
        srv_phb_filter_struct filter;
        filter.group_filter = NULL;
        filter.name_filter = NULL;
        filter.qsearch_filter = NULL;
        filter.storage = req->storage;
        
        if (app_ucs2_strlen((const kal_int8 *) req->name) > 0)
        {
            filter.name_filter = (srv_phb_name_filter_struct *)OslMalloc(sizeof(srv_phb_name_filter_struct));
            int len = app_ucs2_strlen((const kal_int8 *)req->name);
            filter.name_filter->key_word = (U16 *) OslMalloc((len+1) * sizeof(U16));
            app_ucs2_strcpy((kal_int8 *)filter.name_filter->key_word, (const kal_int8 *)req->name);
            filter.field_filter = SRV_PHB_ENTRY_FIELD_NAME;
        }
        else
        {
            filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;
        }
        int contact_length = 0;
      
        contact_length = srv_phb_oplib_build_contact_list(&filter, (U16 *)req->index_array, req->array_length);
        if (filter.name_filter)
        {
            if (filter.name_filter->key_word)
            {
                OslMfree(filter.name_filter->key_word);
            }
            OslMfree(filter.name_filter);
        }
        
        rsp->ret = contact_length >= 0 ? contact_length : -1;
        rsp->user_data = req->user_data;
        send_message(rsp, NULL, MSG_ID_WIDGET_FIND_CONTACTS_RSP, MOD_GADGET);


    }
    else
    {
        rsp->ret = -1;
        rsp->user_data = req->user_data;
        send_message(rsp, NULL, MSG_ID_WIDGET_FIND_CONTACTS_RSP, MOD_GADGET);
    }
}

static void widget_get_contact_info_req_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_get_contact_info_req_struct *req = (widget_get_contact_info_req_struct *)param;
    widget_get_contact_info_rsp_struct *rsp = (widget_get_contact_info_rsp_struct *)construct_local_para(
                                         sizeof(widget_get_contact_info_rsp_struct),
                                         TD_RESET);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 result = srv_phb_oplib_get_contact_info(req->store_index, (srv_phb_contact_info_struct *)req->info);
    rsp->ret = result;
    rsp->user_data = req->info;
    send_message(rsp, NULL, MSG_ID_WIDGET_GET_CONTACT_INFO_RSP, MOD_GADGET);


}

static void widget_load_widget_response_handler(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_load_widget_rsp_struct *p = (widget_load_widget_rsp_struct *)param;

    VappHsWidgetDelegator *widget = VappHsWidgetDelegator::findByInstancId(p->instance_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget)
    {
        return;
    }

    if(p->result == WIDGET_LOAD_OK)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, (PsIntFuncPtr)widget_notify_content_update, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_UPDATE_SIZE_IND, (PsIntFuncPtr)widget_notify_size_update, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_SHOW_VIEW_IND, (PsIntFuncPtr)widget_show_view_handler, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_ENTER_TEXT_IND, (PsIntFuncPtr)widget_handle_enter_text_ind, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_OPEN_URL_IND, (PsIntFuncPtr)widget_handle_open_url_ind, KAL_FALSE);
    }

    widget->onWidgetLoadResult(p->result, p->view_handle, p->width, p->height);
}


static void widget_handle_open_url_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_open_url_ind_struct *p = (widget_open_url_ind_struct*)param;
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_URI_AGENT__
    if (strlen(p->url))
    {
        if (srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_WIDGET, p->url, SRV_URIAGENT_OPTION_UNSPECIFIED, NULL) == SRV_URIAGENT_ERR_PROCESSING)
        {          
            mmi_popup_property_init(&arg);
            
            if (mmi_frm_group_get_active_id() != GRP_ID_WIDGET_VIEW)
            {
                arg.parent_id = mmi_idle_get_group_id();
            }
            else
            {
                arg.parent_id = GRP_ID_WIDGET_VIEW;
            }
            
            mmi_popup_display((WCHAR*) ((UI_string_type) GetString(STR_ID_WIDGET_BUSY_NOW_PLEASE_TRY_LATER)), MMI_EVENT_WARNING, &arg);
        }
    }
#endif /*__MMI_URI_AGENT__*/
}


static void widget_send_notify_content_update_response(int instance_id, void *view_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_notify_content_update_cnf_struct *p = (widget_notify_content_update_cnf_struct*) construct_local_para(
                                                sizeof(widget_notify_content_update_cnf_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;
    p->view_handle = view_handle;

    send_message(p, NULL, MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_CNF, MOD_GADGET);
}


static void widget_notify_content_update(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_notify_content_update_ind_struct *p = (widget_notify_content_update_ind_struct*)param;

    VappHsWidgetDelegator *widget = VappHsWidgetDelegator::findByInstancId(p->instance_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget)
    {
        widget_canvas_free(p->buffer);
        goto final;
    }

    widget->onWidgetContentUpdate(p->buffer);

final:
    //gadget_adp_set_redraw_pending(p->view_handle, MMI_FALSE); /*TESTING*/
    widget_send_notify_content_update_response(p->instance_id, p->view_handle);

}

static void widget_notify_size_update(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_update_size_ind_struct *p = (widget_update_size_ind_struct*)param;

    VappHsWidgetDelegator *widget = VappHsWidgetDelegator::findByInstancId(p->instance_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget || !p->view_handle)
    {
        return;
    }

    widget->onWidgetResize(p->width, p->height);
}

static void widget_send_allocate_asm_rsp(kal_bool ret, void *mem_addr, kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_allocate_asm_rsp_struct *p = (widget_allocate_asm_rsp_struct*) construct_local_para(
                                                sizeof(widget_allocate_asm_rsp_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->ret = ret;
    p->size = size;
    p->mem_addr	 = mem_addr;
    send_message(p, NULL, MSG_ID_WIDGET_ALLOCATE_ASM_RSP, MOD_GADGET);
}


static void widget_send_dialog_response(int response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_display_dialog_cnf_struct *p = (widget_display_dialog_cnf_struct*) construct_local_para(
                                                sizeof(widget_display_dialog_cnf_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->dlg_response = response; ;

    send_message(p, NULL, MSG_ID_WIDGET_DISPLAY_DIALOG_CNF, MOD_GADGET);
}


static mmi_ret widget_confirm_dialog_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_POPUP_QUIT)
    {
        switch(((mmi_alert_result_evt_struct *)param)->result)
        {
        case MMI_ALERT_CNFM_YES:
            widget_send_dialog_response(WIDGET_DLG_RESPONSE_YES);
            break;
        case MMI_ALERT_CNFM_NO:
            widget_send_dialog_response(WIDGET_DLG_RESPONSE_NO);
            break;
        case MMI_ALERT_CNFM_CANCEL:
            widget_send_dialog_response(WIDGET_DLG_RESPONSE_CANCEL);
            break;
        default:
            return MMI_RET_OK;
        }
        g_confirm_dialog_gid = 0;
    }

    return MMI_RET_OK;
}


static void widget_display_confirm_dialog(void *handle, const char *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buf;
    int buflen = (mmi_chset_utf8_strlen((kal_uint8*)message) > 100 ? 100 : mmi_chset_utf8_strlen((kal_uint8*)message));
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    buflen = (buflen + 1) * ENCODING_LENGTH;
    buf = (kal_uint8 *)OslMalloc(buflen);
    mmi_chset_utf8_to_ucs2_string(buf, buflen, (kal_uint8 *)message);

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    if (mmi_frm_group_get_active_id() != GRP_ID_WIDGET_VIEW)
    {
        arg.parent_id = mmi_idle_get_group_id();
    }
    else
    {
        arg.parent_id = GRP_ID_WIDGET_VIEW;
    }

    arg.f_enter_history = 1;
    arg.user_tag = handle;
    arg.callback = widget_confirm_dialog_callback;

    /* This is a dirty fix to let widget delegator know it is an interrupt raised by gadget engine.
       The function of wiget delegator might get called during mmi_confirm_display and
       g_confirm_dialog_gid is still 0 at that moment .*/
    g_confirm_dialog_gid = -1;

    g_confirm_dialog_gid = mmi_confirm_display((WCHAR *)buf, MMI_EVENT_QUERY, &arg);

    OslMfree(buf);
}

static void widget_display_alert_dialog(const char *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buf;
    int buflen = (mmi_chset_utf8_strlen((kal_uint8*)message) > 100 ? 100 : mmi_chset_utf8_strlen((kal_uint8*)message));
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buflen = (buflen + 1) * ENCODING_LENGTH;
    buf = (kal_uint8 *)OslMalloc(buflen);
    mmi_chset_utf8_to_ucs2_string(buf, buflen, (kal_uint8 *)message);

    mmi_popup_property_init(&arg);

    if (mmi_frm_group_get_active_id() != GRP_ID_WIDGET_VIEW)
    {
        arg.parent_id = mmi_idle_get_group_id();
    }
    else
    {
        arg.parent_id = GRP_ID_WIDGET_VIEW;
    }

    mmi_popup_display((WCHAR *)buf, MMI_EVENT_WARNING, &arg);

    OslMfree(buf);
}

static void widget_handle_display_dialog_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_display_dialog_ind_struct *p = (widget_display_dialog_ind_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p->dlg_type)
    {
        case WIDGET_DLG_TYPE_ALERT:
            widget_display_alert_dialog(p->message);
            break;
        case WIDGET_DLG_TYPE_CONFIRM:
            widget_display_confirm_dialog(p->view_handle, p->message);
            break;
        case WIDGET_DLG_TYPE_PROMPT:
            break;
        default:
            break;
    }
}


static void widget_cancel_allocate_asm(mmi_frm_appmem_evt_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_allocate_asm_rsp_struct *p = (widget_allocate_asm_rsp_struct*) construct_local_para(
                                                sizeof(widget_allocate_asm_rsp_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->ret = KAL_FALSE;
    send_message(p, NULL, MSG_ID_WIDGET_ALLOCATE_ASM_RSP, MOD_GADGET);
}


static void widget_free_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_widget_asm != NULL)
    {
        //applib_mem_ap_free(g_widget_asm);
        //g_widget_asm = NULL;
        mmi_frm_asm_free_r(APP_WIDGET_ADP, g_widget_asm);
        g_widget_asm = NULL;
    }
}


static void widget_free_asm_response_handler(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_free_asm();
    mmi_frm_group_close(APP_WIDGET_ADP);

    // TODO:  think about how to do

    if (mmi_frm_group_is_present(GRP_ID_WIDGET_VIEW))
    {
        mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }
    //else if (mmi_frm_group_is_present(GRP_ID_WGTMGR_MAIN))
    //{
    //    mmi_frm_group_close(GRP_ID_WGTMGR_MAIN);
    //}
    else
    {
        mmi_frm_asm_notify_stop_finished(APP_WIDGET_ADP, KAL_TRUE);
    }
}


static void widget_free_asm_indication_handler(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_free_asm();
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
#endif

static mmi_ret widget_asm_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
   	{
    case EVT_ID_ASM_CANCELED:
    {
        mmi_frm_group_close(APP_WIDGET_ADP);

        widget_send_allocate_asm_rsp(KAL_FALSE, NULL, 0);

        break;
    }
    case EVT_ID_ASM_PREPARED:
    {          
        int asm_size = custom_gadget_get_asm_mem_size();
        
        g_widget_asm = mmi_frm_asm_alloc_r(APP_WIDGET_ADP, asm_size);
        ASSERT(g_widget_asm);

        widget_send_allocate_asm_rsp(KAL_TRUE, g_widget_asm, asm_size);

        break;
    }
    case EVT_ID_ASM_FREE_REQ:
    {
        //if there is a detail view, gadget does not free ASM voluntarily
        // TODO: think about how to do???
        if (mmi_frm_group_is_present(GRP_ID_WIDGET_VIEW) == MMI_FALSE)
       	{
            //send_message(NULL, NULL, MSG_ID_WIDGET_FREE_ASM_REQ, MOD_GADGET);
            //return MMI_FRM_ASM_WAITING_TO_FREE;
        }

        break;
    }
    case EVT_ID_ASM_FORCE_FREE:
    {
        send_message(NULL, NULL, MSG_ID_WIDGET_FREE_ASM_REQ, MOD_GADGET);
        return MMI_FRM_ASM_WAITING_TO_FREE;
    }
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        /* do not delete this dangle group */
        return MMI_RET_ERR;
    }
    return MMI_RET_OK;
}


static void widget_allocate_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int asm_size = custom_gadget_get_asm_mem_size();
    mmi_frm_asm_property_struct p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_widget_asm == NULL);
    mmi_frm_group_create(GRP_ID_ROOT, APP_WIDGET_ADP, widget_asm_proc, NULL);

    mmi_frm_asm_property_init(&p);

    p.f_hide_in_oom = 1;

    mmi_frm_asm_set_property(APP_WIDGET_ADP, &p);

    //g_widget_wait_asm_rsp = VFX_TRUE;
    
    mmi_frm_asm_prepare(
            APP_WIDGET_ADP,
            asm_size,
            widget_asm_proc,
            NULL,
            MMI_FRM_ASM_F_NONE);
}


static void widget_handle_allocate_asm_req(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_allocate_asm();
}



/*************************************************************************
    Exported Functions
 *************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  widget_load_widget
 * DESCRIPTION
 *  to load a widget with specified id
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_load_widget(int instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_load_widget_req_struct *p = (widget_load_widget_req_struct*) construct_local_para(
                                                sizeof(widget_load_widget_req_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_check_data_account();

    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_LOAD_WIDGET_RSP, (PsIntFuncPtr)widget_load_widget_response_handler, KAL_FALSE);

    p->is_details = 0;
    p->instance_id = instance_id;

    send_message(p, NULL, MSG_ID_WIDGET_LOAD_WIDGET_REQ, MOD_GADGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_unload_widget
 * DESCRIPTION
 *  To unload a widget with specified id
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_unload_widget(int instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_unload_widget_ind_struct *p = (widget_unload_widget_ind_struct*) construct_local_para(
                                                sizeof(widget_unload_widget_ind_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    widget_close_editor_by_id(instance_id);
    widget_close_view_by_id(instance_id);

    p->instance_id = instance_id;

    send_message(p, NULL, MSG_ID_WIDGET_UNLOAD_WIDGET_IND, MOD_GADGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_show_setting_dialog
 * DESCRIPTION
 *  To ask widget runtime to bring up setting dialog
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_show_setting_dialog(int instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_show_setting_dialog_req_struct *p = (widget_show_setting_dialog_req_struct*) construct_local_para(
                                                sizeof(widget_show_setting_dialog_req_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;

    send_message(p, NULL, MSG_ID_WIDGET_SHOW_SETTING_DIALOG_REQ, MOD_GADGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_update_content
 * DESCRIPTION
 *  To notify widget runtime to redraw the content
 * PARAMETERS
 *  instance_id              [IN]
 *  view_handle              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_update_content(int instance_id, void *view_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_update_content_ind_struct *p = (widget_update_content_ind_struct*) construct_local_para(
                                                sizeof(widget_update_content_ind_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;
    p->view_handle = view_handle;

    send_message(p, NULL, MSG_ID_WIDGET_UPDATE_CONTENT_IND, MOD_GADGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_canvas_free
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_canvas_free(void *p)
{
    extern void gadget_adp_canvas_free(void *);
    gadget_adp_canvas_free(p);
}


/*****************************************************************************
 * FUNCTION
 *  widget_focus_in
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_focus_in(int instance_id, void *view_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_focus_in_ind_struct *p = (widget_focus_in_ind_struct*) construct_local_para(
                                                sizeof(widget_focus_in_ind_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;
    p->view_handle = view_handle;

    send_message(p, NULL, MSG_ID_WIDGET_FOCUS_IN_IND, MOD_GADGET);
}

/*****************************************************************************
 * FUNCTION
 *  widget_focus_out
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_focus_out(int instance_id, void *view_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_focus_out_ind_struct *p = (widget_focus_out_ind_struct*) construct_local_para(
                                                sizeof(widget_focus_out_ind_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;
    p->view_handle = view_handle;

    send_message(p, NULL, MSG_ID_WIDGET_FOCUS_OUT_IND, MOD_GADGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_slmm_pool_id
 * DESCRIPTION
 *  This function is used to get slmm pool id.
 * PARAMETERS
 *  void             
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" GADGET_ASM_SLMM_ID widget_get_slmm_pool_id(void)
{
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  widget_focus_out
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_disable_view_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_disable_view_cache_ind_struct *p = (widget_disable_view_cache_ind_struct*) construct_local_para(
                                                sizeof(widget_disable_view_cache_ind_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    p->is_heap_shrink = 0;
    
    send_message(p, NULL, MSG_ID_WIDGET_DISABLE_VIEW_CACHE_IND, MOD_GADGET);
}

/*****************************************************************************
 * FUNCTION
 *  widget_handle_key_event
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_handle_key_event(int id, void *view_handle, int mmi_keycode, int mmi_keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int keycode = 0, keytype = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    switch(mmi_keycode)
    {
    case KEY_0:
    case KEY_1:
    case KEY_2:
    case KEY_3:
    case KEY_4:
    case KEY_5:
    case KEY_6:
    case KEY_7:
    case KEY_8:
    case KEY_9:
        keycode = 0 + (keycode - KEY_0);
        break;
    case KEY_UP_ARROW:
        keycode = KEY_CODE_UP;
        break;
    case KEY_DOWN_ARROW:
        keycode = KEY_CODE_DOWN;
        break;
    case KEY_LEFT_ARROW:
        keycode = KEY_CODE_LEFT;
        break;
    case KEY_RIGHT_ARROW:
        keycode = KEY_CODE_RIGHT;
        break;
    case KEY_CLEAR:
        keycode = KEY_CODE_CLEAR;
        break;
    case KEY_VOL_UP:
        keycode = KEY_CODE_F23;
        break;
    case KEY_VOL_DOWN:
        keycode = KEY_CODE_F24;
        break;
    default:
        break;
    }

    switch(mmi_keytype)
    {
    case KEY_EVENT_DOWN:
    case KEY_LONG_PRESS:
    case KEY_REPEAT:
        keytype = KEY_DOWN_;
        break;
    case KEY_EVENT_UP:
        keytype = KEY_UP_;
        break;
    default:
        ASSERT(0);
    }

    gadget_adp_add_input_event(id, view_handle, keytype, keycode, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_handle_pen_event
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_handle_pen_event(int id, void *view_handle, int x, int y, int event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(event_type)
    {
    case PEN_DOWN:
        type = MOUSE_DOWN;
        break;
    case PEN_MOVE:
        type = MOUSE_MOVE;
        break;
    case PEN_UP:
        type = MOUSE_UP;
        break;
    case PEN_ABORT:
        type = MOUSE_ABORT;
        break;
    default:
        ASSERT(0);
    }

    gadget_adp_add_input_event(id, view_handle, type, 0, x, y);

}


/*****************************************************************************
 * FUNCTION
 *  widget_handle_enter_text_response
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_handle_enter_text_response(void *view_handle, int text_modified, kal_uint8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_enter_text_cnf_struct *p = (widget_enter_text_cnf_struct*) construct_local_para(
                                                sizeof(widget_enter_text_cnf_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->view_handle = view_handle;
    p->text_modified = text_modified;

    if (text_modified)
    {
        memcpy(p->text, text, MAX_STRING_LEN);
    }

    send_message(p, NULL, MSG_ID_WIDGET_ENTER_TEXT_CNF, MOD_GADGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_close_view
 * DESCRIPTION
 *  Notify widget runtime to close the specified view
 * PARAMETERS
 *  instance_id              [IN]
 *  view_handle              [IN]
 *  type                     [IN]
 *  reponse                  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_close_view(int instance_id, void *view_handle, int type, int response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_close_view_ind_struct *p = (widget_close_view_ind_struct*) construct_local_para(
                                                sizeof(widget_close_view_ind_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;
    p->view_handle = view_handle;
    p->type = type;
    p->response = response;

    send_message(p, NULL, MSG_ID_WIDGET_CLOSE_VIEW_IND, MOD_GADGET);

}


void *widget_lock_canvas(int instance_id, void *view_handle, void **buffer, int width, int height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappHsWidgetDelegator *widget;
    void *lock = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock = mmi_widget_view_lock_canvas(instance_id, view_handle, buffer, width, height);

    if (lock)
    {
        return lock;
    }

    widget = VappHsWidgetDelegator::findByInstancId(instance_id);

    if (!widget || widget->getViewHandle() != view_handle)
    {
        return NULL;
    }

    return widget->lockCanvas(buffer, width, height);
}


void widget_unlock_canvas(void *lock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(lock);

    ((canvas_lock_struct *)lock)->unlock_canvas(lock);
}



/*****************************************************************************
 * FUNCTION
 *  widget_mode_switch_notify_hdlr
 * DESCRIPTION
 *  check memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret widget_mode_switch_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *event = (srv_mode_switch_notify_struct *) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->evt_id)
    {
        case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
            if (event->gsm_select_mode == SRV_MODE_SWITCH_ALL_OFF)
            {
                widget_abort_all_sms_req();
            }
            break;
    }
    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  widget_fmgr_notify_hdlr
 * DESCRIPTION
 *  check memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret widget_fmgr_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_dev_op_enum op = WIDGET_DEV_UNMOUNT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
            op = WIDGET_DEV_MOUNT;

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            srv_fmgr_notification_dev_plug_event_struct *event = (srv_fmgr_notification_dev_plug_event_struct *)param;
            U32 i;

            for (i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == SRV_FMGR_CARD_DRV)
                {

                    widget_device_update_ind_struct *p = (widget_device_update_ind_struct*) construct_local_para(
                                                        sizeof(widget_device_update_ind_struct),
                                                        TD_RESET);

                    p->op = op;
                    send_message(p, NULL, MSG_ID_WIDGET_DEV_UPDATE_IND, MOD_GADGET);
                }
            }
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  widget_usb_notify_hdlr
 * DESCRIPTION
 *  check memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret widget_usb_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    switch(param->evt_id)
    {
        case EVT_ID_USB_EXIT_MS_MODE:
        {          
            srv_wgtmgr_usb_notify_hdlr(param);

            mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, (PsIntFuncPtr)widget_notify_content_update, KAL_FALSE);

            VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();

            if(iter)
            {
                mmi_frm_display_dummy_screen();
                mmi_frm_scrn_close_active_id();
            }

            break;
        }
    }
#endif
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  widget_wgtmgr_notify_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret widget_wgtmgr_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_notify_evt_struct *event = (srv_wgtmgr_notify_evt_struct *) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->evt_id)
    {
        case EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND:
            vadp_p2v_hs_widget_reset_by_id(VAPP_HS_WIDGET_TYPE_GADGET, event->id, 0);
            widget_unload_widget(event->id);
            break;

        case EVT_ID_SRV_WGTMGR_DELETE_WIDGET_IND:
            vadp_p2v_hs_widget_reset_by_id(VAPP_HS_WIDGET_TYPE_GADGET, event->id, 0);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  widget_wgtmgr_notify_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret widget_init_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_WGT_IND, (PsIntFuncPtr)widget_handle_terminate_widget_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_ALL_WGT_IND, (PsIntFuncPtr)widget_handle_terminate_all_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_ALLOCATE_ASM_REQ, (PsIntFuncPtr)widget_handle_allocate_asm_req, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_FREE_ASM_RSP, (PsIntFuncPtr)widget_free_asm_response_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_FREE_ASM_IND, (PsIntFuncPtr)widget_free_asm_indication_handler, KAL_FALSE);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_widget_get_widget_active_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" bool widget_get_widget_active_flag(void)
{
    return g_widget_active;
}

/*****************************************************************************
 * FUNCTION
 *  widget_set_widget_active_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_set_widget_active_flag(kal_bool active_flag)
{
    g_widget_active = active_flag;
}

/*****************************************************************************
 * FUNCTION
 *  widget_enter_widget_active_mode
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_enter_widget_active_mode(void)
{
    if (active_mode_mutex == NULL)
    {
        active_mode_mutex = kal_create_mutex("widget_active_mode");
    }

    if (widget_get_widget_active_flag() == true) 
    {
        kal_take_mutex(active_mode_mutex);
        
        if (g_widget_active_mode_entered == false)
        {
            g_widget_active_mode_entered = true;
     
            //gadget_adp_log_prompt_trace("Enter throttle mode");

            vrt_enter_throttle_mode('GAGT');
        }
        
        kal_give_mutex(active_mode_mutex);
    }
}

/*****************************************************************************
 * FUNCTION
 *  widget_leave_widget_active_mode
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_leave_widget_active_mode(void)
{
    if (active_mode_mutex == NULL)
    {
        active_mode_mutex = kal_create_mutex("widget_active_mode");
    }

    kal_take_mutex(active_mode_mutex);

    if (g_widget_active_mode_entered == true)
    {
        g_widget_active_mode_entered = false;

        //gadget_adp_log_prompt_trace("Leave throttle mode");

        vrt_leave_throttle_mode('GAGT');
    }

    kal_give_mutex(active_mode_mutex);
}

/*****************************************************************************
 * FUNCTION
 *  widget_alloc_nc_mem
 * DESCRIPTION
 * This function is used to allocate CAIRO memory for gadget engine to draw image and text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void*
 *****************************************************************************/
extern "C" void *widget_alloc_nc_mem(U32 size)
{
    //return med_alloc_ext_mem(size);
    return applib_asm_alloc_anonymous_nc(size);
}

/*****************************************************************************
 * FUNCTION
 *  widget_free_nc_mem
 * DESCRIPTION
 * This function is used to free CAIRO memory for gadget engine to draw image and text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void widget_free_nc_mem(void *ptr)
{
    //med_free_ext_mem((void**)&ptr);
    applib_asm_free_anonymous(ptr);
}

void widget_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_DISPLAY_DIALOG_IND, (PsIntFuncPtr)widget_handle_display_dialog_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_WGT_IND, (PsIntFuncPtr)widget_handle_terminate_widget_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_ALL_WGT_IND, (PsIntFuncPtr)widget_handle_terminate_all_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_CHECK_NETWORK_ACCESS_IND, (PsIntFuncPtr)widget_handle_check_network_access_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_ALLOCATE_ASM_REQ, (PsIntFuncPtr)widget_handle_allocate_asm_req, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_FREE_ASM_RSP, (PsIntFuncPtr)widget_free_asm_response_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_FREE_ASM_IND, (PsIntFuncPtr)widget_free_asm_indication_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_QUERY_DEVICE_INFO_IND, (PsIntFuncPtr)widget_handle_query_device_info_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_SEND_SMS_REQ, (PsIntFuncPtr)widget_send_sms_req_hdlr, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_COMMIT_CONTACT_REQ, (PsIntFuncPtr)widget_commit_contact_req_hdlr, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_DELETE_CONTACT_REQ, (PsIntFuncPtr)widget_delete_contact_req_hdlr, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_FIND_CONTACTS_REQ, (PsIntFuncPtr)widget_find_contacts_req_hdlr, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_GET_CONTACT_INFO_REQ, (PsIntFuncPtr)widget_get_contact_info_req_hdlr, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BROWSE_IMAGE_REQ, (PsIntFuncPtr)widget_handle_browse_image_req, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_CAPTURE_IMAGE_REQ, (PsIntFuncPtr)widget_handle_capture_image_req, KAL_FALSE);

    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_PLAY_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_audio_play_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_STOP_IN_MMI_IND, (PsIntFuncPtr)gadget_adp_audio_stop_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_GET_CURR_POS_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_audio_get_current_position_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_SET_CURR_POS_IN_MMI_IND, (PsIntFuncPtr)gadget_adp_audio_set_current_position_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_GET_DUR_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_audio_get_duration_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_GET_VOL_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_audio_get_volume_in_mmi, KAL_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_AUDIO_SET_VOL_IN_MMI_IND, (PsIntFuncPtr)gadget_adp_audio_set_volume_in_mmi, KAL_FALSE);
#ifdef __BITSTREAM_API_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_OPEN_HANDLE_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_open_handle_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_CLOSE_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_close_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_GET_BUFFER_STATUS_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_get_buffer_status_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_PUT_DATA_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_put_data_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_START_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_start_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_STOP_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_stop_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_GET_PLAY_TIME_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_get_play_time_in_mmi, KAL_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_SUSPEND_BACKGROUND_PLAY_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_suspend_background_play_in_mmi, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_BITSTREAM_AUDIO_RESUME_BACKGROUND_PLAY_IN_MMI_REQ, (PsIntFuncPtr)gadget_adp_bitstream_audio_resume_background_play_in_mmi, KAL_FALSE);
#endif
}
#endif /* __MMI_GADGET_SUPPORT__ */
