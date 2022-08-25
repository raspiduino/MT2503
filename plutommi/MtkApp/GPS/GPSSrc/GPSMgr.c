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
 * GPSMgr.c
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
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

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "SettingProfile.h"
#include "app_datetime.h"
#include "DateTimeGprot.h"

#include "gv.h"
#include "tst_def.h"

#include "MessagesL4Def.h"
#include "MessagesMiscell.h"
#include "SmsSrvGProt.h"

#include "Gps2lcsp_enum.h"
#include "Gps2lcsp_struct.h"
#include "gps_struct.h"
#include "mdi_agps.h"

#ifdef __AGPS_LOG_SUPPORT__
#include "EngineerModeAGPSlogGProt.h"
#endif

#if defined(__AGPS_USER_PLANE__) && defined(__SUPL_SUPPORT__)
#include "supl2mmi_enums.h"
#include "supl2mmi_struct.h"
#include "cbm_api.h"
#include "CbmSrvGprot.h"
#endif

#include "stack_common.h"
#include "stack_msgs.h"

#include "mdi_datatype.h"
#include "Mdi_gps.h"

#include "UcmSrvGprot.h"
#include "CallManagementGprot.h"
#include "CommonScreens.h"
#include "PhoneBookGprot.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "Conversions.h"
#include "DLAgentSrvDef.h"
#include "DLAgentSrvGProt.h"
#include "NwUsabSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "gps_ate.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#define MMI_GPS_MGR_IS_PHONELOCK ((MMI_BOOL)mmi_dmui_is_phone_lock())
#else
#define MMI_GPS_MGR_IS_PHONELOCK (MMI_FALSE)
#endif

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_gps_nvram_def.h"
#include "nvram_interface.h"
#include "fs_type.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_gps_def.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "mmi_frm_history_gprot.h"
#include "PhbSrvGprot.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"


#include "GPSResDef.h"
#include "GPSGProt.h"
#include "GPSMgrProt.h"
#include "GPSMgrAGPSUP.h"
#include "SimCtrlSrvGprot.h"
#include "GpioSrvGprot.h"
#include "GPSSetting.h"

#if defined(__GPS_SUPPORT__)
    #include "gps_struct.h"
#endif

#define MMI_AGPS_NEED_TLS
#define GPS_MGR_MAX_PLMN_LEN SRV_MAX_PLMN_LEN + 1

#if defined(__AGPS_USER_PLANE__)
typedef struct
{
    mmi_gps_manager_request_struct req_list[MAX_SUPL_REQ_NUM];
    U16 cur_id;
    S32 port;
    mmi_gps_manager_notify_struct notify_list[MAX_SUPL_REQ_NUM];
    U16 req_id_name[SUPL_MMI_MAX_REQ_LEN];
    mmi_gps_manager_push_struct push_list[MAX_SUPL_REQ_NUM];
    CHAR temp_push_data[SUPL_MMI_MAX_PUSH_SIZE];
    S16 cur_push_num;
    /* L modify */
    S16 cur_notify_num;
    mmi_gps_work_mode_enum cur_work_mode;
    U8 open_gps_num[UART_WORK_MODE_COUNT];
    MMI_BOOL is_pos;
    MMI_BOOL is_last_pos;
    MMI_BOOL is_count_duration;
    U32 pos_start_time;
    MMI_BOOL is_call_abort;
    MMI_BOOL is_time_out;
    MMI_BOOL is_regiest_call_notify;
    U8 app_id;
    srv_gps_notify_callback app_callback;
    void *app_user_data;
    U32 notify_timer_timeout;
    MMI_BOOL emerge_call;
    U8 rrc_setting;
    MMI_ID screen_group_gid;
    MMI_BOOL time_is_sync;
}mmi_gps_manager_context_struct;

static mmi_gps_manager_context_struct g_gps_mgr_ctx;

//#define __GPS_MGR_SUPL_UT__
#if defined(__GPS_MGR_SUPL_UT__)
    static void _ut_mmi_gps_mgr_supl_send_notify(void)
    {
        supl_mmi_status_ind_struct *local_param_ptr;
        ilm_struct *ilm_ptr;
        local_param_ptr = (supl_mmi_status_ind_struct*)construct_local_para(sizeof(supl_mmi_status_ind_struct), TD_CTRL);

        local_param_ptr->status = SUPL_MMI_STATUS_ACTIVATED;
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_AUTO;
        local_param_ptr->obj_valid = SUPL_MMI_COMP_NOTIFY;
        local_param_ptr->notify.notify_type = SUPL_MMI_NOTIFY_ONLY;
        local_param_ptr->notify.encodeing_type = SUPL_MMI_ENCODING_UCS2;
        kal_wsprintf((kal_wchar*)local_param_ptr->notify.req_id, "%w", L"MTK");
        kal_wsprintf((kal_wchar*)local_param_ptr->notify.client_name, "%w", L"MTK MODIS");

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
        msg_send_ext_queue(ilm_ptr);
    }

    static void _ut_mmi_gps_mgr_supl_send_confirm_allow(void)
    {
        supl_mmi_status_ind_struct *local_param_ptr;
        ilm_struct *ilm_ptr;
        local_param_ptr = (supl_mmi_status_ind_struct*)construct_local_para(sizeof(supl_mmi_status_ind_struct), TD_CTRL);

        local_param_ptr->status = SUPL_MMI_STATUS_ACTIVATED;
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_AUTO;
        local_param_ptr->obj_valid = SUPL_MMI_COMP_NOTIFY;
        local_param_ptr->notify.notify_type = SUPL_MMI_NOTIFY_ALLOW_NO_ANSWER;
        local_param_ptr->notify.encodeing_type = SUPL_MMI_ENCODING_UCS2;
        kal_wsprintf((kal_wchar*)local_param_ptr->notify.req_id, "%w", L"MTK");
        kal_wsprintf((kal_wchar*)local_param_ptr->notify.client_name, "%w", L"MTK MODIS");

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
        msg_send_ext_queue(ilm_ptr);
    }

    static void _ut_mmi_gps_mgr_supl_send_confirm_not_allow(void)
    {
        supl_mmi_status_ind_struct *local_param_ptr;
        ilm_struct *ilm_ptr;
        local_param_ptr = (supl_mmi_status_ind_struct*)construct_local_para(sizeof(supl_mmi_status_ind_struct), TD_CTRL);

        local_param_ptr->status = SUPL_MMI_STATUS_ACTIVATED;
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_AUTO;
        local_param_ptr->obj_valid = SUPL_MMI_COMP_NOTIFY;
        local_param_ptr->notify.notify_type = SUPL_MMI_NOTIFY_DENY_NO_ANSWER;
        local_param_ptr->notify.encodeing_type = SUPL_MMI_ENCODING_UCS2;
        kal_wsprintf((kal_wchar*)local_param_ptr->notify.req_id, "%w", L"MTK");
        kal_wsprintf((kal_wchar*)local_param_ptr->notify.client_name, "%w", L"MTK MODIS");

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
        msg_send_ext_queue(ilm_ptr);
    }
#endif // #if defined(__GPS_MGR_SUPL_UT__)

static void mmi_gps_mgr_set_work_mode(void);
static void mmi_gps_mgr_send_start_supl_req(void);
static void mmi_gps_mgr_supl_mmi_status_ind_hdlr(void *msg);
static void mmi_gps_mgr_supl_mmi_status_terminated(void *msg);
static void mmi_gps_mgr_supl_mmi_status_activated(void *msg);
static void mmi_gps_mgr_supl_mmi_status_stand_by(void *msg);
static void mmi_gps_mgr_show_notify_src(void);
void mmi_gps_mgr_exit_notify_src(void);
static void mmi_gps_mgr_show_confirm_src(void);
void mmi_gps_mgr_notify_accept(void);
void mmi_gps_mgr_notify_decline(void);
static void mmi_gps_mgr_notify_time_out(void);
static void mmi_gps_mgr_notify_send_rsp(supl_mmi_result_enum result, U16 index);
static void mmi_gps_mgr_supl_mmi_abort_ind_hdlr(void *msg);
static void mmi_gps_mgr_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length);
static void mmi_gps_mgr_gsa_callback(mdi_gps_nmea_gsa_struct *param);
//static void mmi_gps_mgr_time_sync(mdi_gps_nmea_rmc_struct *param);
static void _mmi_gps_mgr_abort_close_gps(U8 index);
static void mmi_gps_mgr_abort_error_rsp(U8 index);
static void _mmi_gps_mgr_abort_free_req(U8 index);
static MMI_BOOL mmi_gps_mgr_get_history_pos(supl_mmi_qop_struct *qop,
                                        supl_mmi_position_struct *pos,
                                        supl_mmi_req_assist_data_struct *filter);
static void mmi_gps_mgr_set_pos(supl_mmi_position_struct *pos);
static MMI_BOOL mmi_gps_mgr_check_ack_sms(srv_sms_event_struct* event_data);

    #ifndef __COSMOS_MMI__
        static void mmi_gps_mgr_app_notify_func(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data);
    #endif
#endif

static void mmi_gps_mgr_p_info_callback(mdi_gps_parser_p_info_enum type,void *param);

#if defined(__AGPS_USER_PLANE__)
extern void smsal_gsm7_unpack( kal_uint8  *old_data_ptr,
                               kal_uint8  *new_data_ptr,
                               kal_uint16      data_len,
                               kal_uint16        offset );
extern kal_uint16 applib_addr_gsm7_strlen(kal_uint8 *gsm7_array, kal_uint16 size);
extern const U8 DefaultToAsciiArray[128];
static void _mmi_gps_gsm7_to_ascii_array(kal_uint8  *gsm7_data,
                                 kal_uint8  *ascii_data,
                                 kal_uint16 data_len)
{
    kal_uint16 size = 0;
    kal_uint8 i = 0, j = 0;

    if (!gsm7_data || !ascii_data || data_len==0)
        return;

    size = strlen(gsm7_data);
    size = applib_addr_gsm7_strlen(gsm7_data, size);

    if (size > data_len-1)
        size = data_len-1;

    smsal_gsm7_unpack(gsm7_data, ascii_data, size, 0);

    for (i = 0, j = 0; i < size; i++, j++)
    {
        if (ascii_data[i] == 0x1B)
        {
            switch (ascii_data[i+1])
            {
                case 0x0A:
                    ascii_data[j] = 0x0C; //Form feed
                    break;
                case 0x14:
                    ascii_data[j] = 0x5E; //'^'
                    break;
                case 0x28:
                    ascii_data[j] = 0x7B; //'{'
                    break;
                case 0x29:
                    ascii_data[j] = 0x7D; //'}'
                    break;
                case 0x2F:
                    ascii_data[j] = 0x5C; //'\'
                    break;
                case 0x3C:
                    ascii_data[j] = 0x5B; //'['
                    break;
                case 0x3D:
                    ascii_data[j] = 0x7E; //'~'
                    break;
                case 0x3E:
                    ascii_data[j] = 0x5D; //']'
                    break;
                case 0x40:
                    ascii_data[j] = 0x7C; //'|'
                    break;
                case 0x65:
                    ascii_data[j] = 0x20;  //Euro sign is not included in ASCII, use space to replace it.
                    break;
                default:
                    ascii_data[j] = 0x1B;
                    break;
            }

            if (ascii_data[j] != 0x1B)
            {
                i++;
            }
        }
        else
        {
            ascii_data[j] = DefaultToAsciiArray[ascii_data[i]];
        }
    }
    ascii_data[j] = 0;
}

#if defined(MMI_GPS_MGR_DEBUG) && defined(__MMI_ENGINEER_MODE__)
extern MMI_BOOL mmi_em_dev_minigps_get_auto_reset_apgs(void);
extern void mmi_em_dev_minigps_reset_agps_data(void);
#endif /* MMI_GPS_MGR_DEBUG */
#endif

#ifdef __AGPS_CONTROL_PLANE__
extern mmi_ret mmi_gps_mgr_call_state_change_cp_proc(mmi_event_struct* param);
#endif

#define MMI_GPS_MGR_TEMP_BUF2_LENGTH            (1024/2)


#if defined(__GPS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  ATGPSATETestHandler
 * DESCRIPTION
 *  This function is to handle AT command for GPS ATE testing
 * PARAMETERS
 *  ind        [IN]        message data
 * RETURNS
 *  void
 *****************************************************************************/
static void ATGPSATETestHandler(void *ind)
{
    mmi_fm_gps_ate_test_cmd_req_hdlr(ind);
}
#endif

#if defined(__AGPS_USER_PLANE__)

static void _mmi_gps_mgr_set_state(kal_uint8 index, mmi_agps_state_enum state, kal_uint32 line)
{
    g_gps_mgr_ctx.req_list[index].state = state;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CHANGE_STATE, state, line);
}

static mmi_ret mmi_gps_mgr_call_state_change_up_proc(mmi_event_struct* param)
{
    ilm_struct *ilm_ptr;
    supl_mmi_abort_req_struct *local_param_ptr;
    mmi_agps_state_enum state;
    U16 i;
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *) param;

    /*emergency call*/
    if (MMI_TRUE == srv_ucm_is_emergency_call())
    {
        /*notify supl*/
        for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
        {
            if (g_gps_mgr_ctx.req_list[i].is_used == MMI_TRUE)
            {
                state = g_gps_mgr_ctx.req_list[i].state;
                if (state == MMI_AGPS_STATE_WORKING ||
                    state == MMI_AGPS_STATE_START ||
                    state == MMI_AGPS_STATE_ACTIVITATE ||
                    state == MMI_AGPS_STATE_WAIT_CNF ||
                    state == MMI_AGPS_STATE_STAND_BY ||
                    state == MMI_AGPS_STATE_WAIT_POS ||
                    state == MMI_AGPS_STATE_SET_WORK_MODE ||
                    state == MMI_AGPS_STATE_GPS_INIT ||
                    state == MMI_AGPS_STATE_PUSH_WAIT ||
                    state == MMI_AGPS_STATE_WAIT_RSP)
                {
                    ilm_ptr = allocate_ilm(MOD_MMI);
                    local_param_ptr = (supl_mmi_abort_req_struct*)construct_local_para(sizeof(supl_mmi_abort_req_struct), TD_CTRL);
                    local_param_ptr->req_id = g_gps_mgr_ctx.req_list[i].req_id;

                    ilm_ptr->src_mod_id = MOD_MMI;
                    ilm_ptr->dest_mod_id = MOD_SUPL;
                    ilm_ptr->sap_id = SUPL_MMI_SAP;
                    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_ABORT_REQ;
                    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
                    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ABORT_REQ);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, local_param_ptr->req_id);
                    msg_send_ext_queue(ilm_ptr);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);
                    _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_ABORT, __LINE__);

                    g_gps_mgr_ctx.emerge_call = MMI_TRUE;
                }
            }
        }
    }
    /*MT call accept*/
    if (SRV_UCM_ACCEPT_ACT == srv_ucm_query_curr_action())
    {
    /*notify supl*/
    }
    return MMI_RET_OK;
}
#endif

mmi_ret mmi_gps_mgr_call_state_change_proc(mmi_event_struct* param)
{

#if defined(__AGPS_USER_PLANE__)
    mmi_gps_mgr_call_state_change_up_proc(param);
#endif

#if defined(__AGPS_CONTROL_PLANE__)
    mmi_gps_mgr_call_state_change_cp_proc(param);
#endif

    /*emergency call*/
    if (MMI_TRUE == srv_ucm_is_emergency_call())
    {
        /*notify ss*/
    }
    /*MT call accept*/
    if (SRV_UCM_ACCEPT_ACT == srv_ucm_query_curr_action())
    {
        /*notify ss*/
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_da_file
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gps_mgr_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__AGPS_USER_PLANE__)
    U8 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__AGPS_USER_PLANE__)
    g_gps_mgr_ctx.cur_id = 0;
    for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
    {
        g_gps_mgr_ctx.req_list[i].is_used = MMI_FALSE;
        g_gps_mgr_ctx.push_list[i].is_used = MMI_FALSE;
    }
    g_gps_mgr_ctx.cur_notify_num = 0;
    g_gps_mgr_ctx.cur_push_num = 0;
    g_gps_mgr_ctx.cur_work_mode = MMI_GPS_WORK_NO_WORK;
    for (i = 0; i < UART_WORK_MODE_COUNT; i++)
    {
        g_gps_mgr_ctx.open_gps_num[i] = 0;
    }
    g_gps_mgr_ctx.emerge_call = MMI_FALSE;
    g_gps_mgr_ctx.time_is_sync = MMI_FALSE;
    g_gps_mgr_ctx.is_pos = MMI_FALSE;
    g_gps_mgr_ctx.is_last_pos = MMI_FALSE;
    g_gps_mgr_ctx.is_count_duration = MMI_FALSE;
    g_gps_mgr_ctx.is_call_abort = MMI_FALSE;
    g_gps_mgr_ctx.is_regiest_call_notify = MMI_FALSE;
    SetProtocolEventHandler(mmi_gps_mgr_supl_mmi_status_ind_hdlr, MSG_ID_SUPL_MMI_STATUS_IND);
    SetProtocolEventHandler(mmi_gps_mgr_supl_mmi_abort_ind_hdlr, MSG_ID_SUPL_MMI_ABORT_CNF);
    srv_sms_reg_port(
            7275,
            SRV_SMS_SIM_1,
            mmi_gps_mgr_check_ack_sms,
            NULL);
    srv_sms_reg_port(
            7275,
            SRV_SMS_SIM_2,
            mmi_gps_mgr_check_ack_sms,
            NULL);
    srv_sms_reg_port(
            7275,
            SRV_SMS_SIM_3,
            mmi_gps_mgr_check_ack_sms,
            NULL);
    srv_sms_reg_port(
            7275,
            SRV_SMS_SIM_4,
            mmi_gps_mgr_check_ack_sms,
            NULL);

    /* register CBM app_id */
    {
        cbm_app_info_struct info;

        memset(&info, 0, sizeof(info));

        g_gps_mgr_ctx.app_id = 0;
        info.app_str_id = STR_ID_GPS_SETTING_AGPS;
        info.app_icon_id = IMG_ID_GPS_AGPS_STATE_ICON;

        #if defined(__CMCC_AGPS_SUPPORT__)
            /* do not use WIFI in CMCC server */
            info.app_type = DTCNT_APPTYPE_GPS | DTCNT_APPTYPE_SKIP_WIFI;
        #else
            info.app_type = DTCNT_APPTYPE_GPS;
        #endif

        cbm_register_app_id_with_app_info(&info, &g_gps_mgr_ctx.app_id);
    }

    #ifdef __COSMOS_MMI__
        vapp_gps_mgr_notify_init();
    #else
        mmi_gps_mgr_register_notify_function(mmi_gps_mgr_app_notify_func, NULL);
    #endif

#endif
    mdi_gps_register_p_info_callback(mmi_gps_mgr_p_info_callback);

#if defined(__AGPS_CONTROL_PLANE__)
    mmi_gps_mgr_cp_init();
#endif

#ifdef __GPS_MGR_SUPL_UT__
    StartTimer(GPS_MGR_NOTIFY_TIMER_ID_5, 30000, _ut_mmi_gps_mgr_supl_send_notify);
    //StartTimer(GPS_MGR_NOTIFY_TIMER_ID_5, 30000, _ut_mmi_gps_mgr_supl_send_confirm_not_allow);
    //StartTimer(GPS_MGR_NOTIFY_TIMER_ID_5, 30000, _ut_mmi_gps_mgr_supl_send_confirm_allow);
#endif

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_INDICATION, mmi_gps_mgr_call_state_change_proc, NULL);
#endif

#if defined(__GPS_SUPPORT__)
    /* ATE test */
    SetProtocolEventHandler(ATGPSATETestHandler, MSG_ID_MMI_GPS_ATE_TEST_REQ);

    nvram_ltable_register(logical_data_item_table_mmi_gps);
#endif

    return MMI_RET_OK;
}

#if defined(__AGPS_USER_PLANE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_da_file
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_register_notify_function(srv_gps_notify_callback func,void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_mgr_ctx.app_callback = func;
    g_gps_mgr_ctx.app_user_data = user_data;

}

static MMI_BOOL _mmi_gps_mgr_check_push_req_criteria(S16 cur_push_num)
{
    MMI_BOOL ret = MMI_FALSE;
#ifdef __CMCC_AGPS__
    if (cur_push_num == 1)  // first SUPL push
    {
        ret = MMI_TRUE;
    }
#else
    if (cur_push_num == 1 || cur_push_num == 2) // at most 2 SUPL push co-exist
    {
        ret = MMI_TRUE;
    }
#endif

    return ret;
}

static MMI_BOOL _mmi_gps_mgr_add_into_push_list(U16 req_id, CHAR* data, U32 data_len)
{
    mmi_gps_manager_push_struct *push_p = NULL;
    U8 i;

    /* find first valid slot */
    for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.push_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        /* not found valid slot */
        ASSERT(0);
        return MMI_FALSE;
    }

    ASSERT(data_len <= SUPL_MMI_MAX_PUSH_SIZE);

    push_p = &g_gps_mgr_ctx.push_list[i];

    /* fill this slot */
    push_p->req_id = req_id;
    memcpy(push_p->data, data, data_len);
    push_p->data_len = data_len;
    push_p->is_used = MMI_TRUE;
    push_p->is_handling = MMI_FALSE;

    g_gps_mgr_ctx.cur_push_num++;

    return MMI_TRUE;
}

static MMI_BOOL _mmi_gps_mgr_remove_from_push_list(U16 req_id)
{
    U8 i;

    /* find first valid slot */
    for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.push_list[i].req_id == req_id &&
            g_gps_mgr_ctx.push_list[i].is_used == MMI_TRUE)
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
        return MMI_FALSE;
    }

    while (i < (MAX_SUPL_REQ_NUM - 1))
    {
        if (g_gps_mgr_ctx.push_list[i+1].is_used == MMI_TRUE)
        {
            memcpy(&g_gps_mgr_ctx.push_list[i], &g_gps_mgr_ctx.push_list[i+1], sizeof(mmi_gps_manager_push_struct));
            i++;
        }
        else
        {
            break;
        }
    }

    g_gps_mgr_ctx.push_list[i].is_used = MMI_FALSE;
    g_gps_mgr_ctx.cur_push_num--;

    return MMI_TRUE;
}

static mmi_gps_manager_push_struct* _mmi_gps_mgr_get_first_unhandled_push(void)
{
    mmi_gps_manager_push_struct* push_p = NULL;
    U8 i;

    /* find first valid slot */
    for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.push_list[i].is_used == MMI_TRUE &&
            g_gps_mgr_ctx.push_list[i].is_handling == MMI_FALSE)
        {
            push_p = &g_gps_mgr_ctx.push_list[i];
            break;
        }
    }

    return push_p;
}

static mmi_gps_manager_push_struct* _mmi_gps_mgr_get_current_push(U16 req_id)
{
    mmi_gps_manager_push_struct* push_p = NULL;
    U8 i;

    for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.push_list[i].req_id == req_id)
        {
            push_p = &g_gps_mgr_ctx.push_list[i];
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
        ASSERT(0);

        return push_p;
    }

    return push_p;
}

/*****************************************************************************
 * FUNCTION
 *  _mmi_gps_mgr_send_push_req
 * DESCRIPTION
 *  mdi _mmi_gps_mgr_send_push_req.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _mmi_gps_mgr_send_push_req(U32 req_id, MMI_BOOL need_retry)
{
    U8 index = 0xff;
    supl_mmi_push_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;
    MMI_BOOL plmn_ret, use_plmn;
    CHAR PLMNNum[GPS_MGR_MAX_PLMN_LEN];
    nvram_em_minigps_up_setting_struct agps_up_setting;
    mmi_gps_manager_push_struct* push_p;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_PUSH_REQ);

    if (req_id != GPS_MGR_INVALID_ID)
    {
        push_p = _mmi_gps_mgr_get_current_push((U16)req_id);
        if (push_p == NULL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

            return;
        }
    }
    else
    {
        push_p = _mmi_gps_mgr_get_first_unhandled_push();
        if (push_p == NULL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

            return;
        }
    }

    push_p->is_handling = MMI_TRUE;

    /* find index of req_list[] */
    for (index = 0; index < MAX_SUPL_REQ_NUM; index++)
    {
        if (g_gps_mgr_ctx.req_list[index].req_id == push_p->req_id)
        {
            break;
        }
    }

    ASSERT(index != MAX_SUPL_REQ_NUM);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

#ifdef __AGPS_LOG_SUPPORT__
    em_agpslog_start_session((U32)g_gps_mgr_ctx.req_list[index].req_id);
#endif

    local_param_ptr = (supl_mmi_push_req_struct*)construct_local_para(sizeof(supl_mmi_push_req_struct), TD_CTRL);

    local_param_ptr->len = push_p->data_len;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_PUSH_DATA_LEN, push_p->data_len);
    memcpy(local_param_ptr->data, push_p->data, push_p->data_len);
    ASSERT(push_p->data_len <= SUPL_MMI_MAX_PUSH_SIZE);

    data_account = mmi_gps_setting_get_data_account(g_gps_mgr_ctx.req_list[index].sim);
    mmi_gps_setting_get_profile(&agps_profile);

    local_param_ptr->nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)g_gps_mgr_ctx.req_list[index].sim, g_gps_mgr_ctx.app_id, MMI_FALSE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ACCOUND_ID, local_param_ptr->nwk_account_id);
    if (local_param_ptr->nwk_account_id == 0xffffffff)
    {
        _mmi_gps_mgr_abort_free_req(index);
        free_local_para((local_para_struct*) local_param_ptr);
        return;
    }
    switch (g_gps_mgr_ctx.req_list[index].sim)
    {
    case MMI_GPS_SETTING_PREFER_SIM_NO1:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM1;
        break;
    case MMI_GPS_SETTING_PREFER_SIM_NO2:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM2;
        break;
    case MMI_GPS_SETTING_PREFER_SIM_NO3:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM3;
        break;
    case MMI_GPS_SETTING_PREFER_SIM_NO4:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM4;
        break;
    default:
        ASSERT(0);
    }

    g_gps_mgr_ctx.req_list[index].need_retry = need_retry;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, need_retry, __LINE__);
    local_param_ptr->req_id =  g_gps_mgr_ctx.req_list[index].req_id;

    if (need_retry == MMI_TRUE)  // first try
    {
        use_plmn = MMI_FALSE;

        mmi_ucs2_to_asc((CHAR*)local_param_ptr->slp_addr, (CHAR*)agps_profile.addr);
        local_param_ptr->slp_port = (kal_uint16)agps_profile.port;
        if(local_param_ptr->slp_addr[0] == '0')
        {
            use_plmn = MMI_TRUE;
        }
    }
    else
    {
        /* this is retrying push */
        use_plmn = MMI_TRUE;
    }

    if (use_plmn)
    {
        plmn_ret = srv_sim_ctrl_get_home_plmn((mmi_sim_enum)(g_gps_mgr_ctx.req_list[index].sim + 1),PLMNNum,GPS_MGR_MAX_PLMN_LEN);
        if(plmn_ret == MMI_FALSE)
            return;
        kal_sprintf((local_param_ptr->slp_addr),
                     "h-slp.mnc0%c%c.mcc%c%c%c.pub.3gppnetwork.org",
                     PLMNNum[3],
                     PLMNNum[4],
                     PLMNNum[0],
                     PLMNNum[1],
                     PLMNNum[2]);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SLP_ADDRESS,
                             PLMNNum[3],
                             PLMNNum[4],
                             PLMNNum[0],
                             PLMNNum[1],
                             PLMNNum[2]);
        local_param_ptr->slp_port = 7275;
        g_gps_mgr_ctx.req_list[index].need_retry = MMI_FALSE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, MMI_FALSE, __LINE__);
    }

    /* read setttings from NVRAM */
    mmi_gps_setting_get_up_setting(&agps_up_setting);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, agps_up_setting.use_tls);
    g_gps_mgr_ctx.rrc_setting = agps_up_setting.payload;

    /* use TLS? */
    local_param_ptr->use_tls = agps_up_setting.use_tls;

    /* UT Timer */
    local_param_ptr->ut_timer_value = agps_up_setting.ut_timer;

    /* RRC Payload Type */
    switch (g_gps_mgr_ctx.rrc_setting)
    {
    case EM_GPS_UP_PAYLOAD_BOTH:
        local_param_ptr->payload_capability = SUPL_USE_RRC | SUPL_USE_RRLP;
        break;
    case EM_GPS_UP_PAYLOAD_RRLP:
        local_param_ptr->payload_capability = SUPL_USE_RRLP;
        break;
    case EM_GPS_UP_PAYLOAD_RRC:
        local_param_ptr->payload_capability = SUPL_USE_RRC;
        break;

    default:
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
        local_param_ptr->payload_capability = SUPL_USE_RRC | SUPL_USE_RRLP;
        break;
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_PUSH_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_PUSH_REQ);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_ctx.req_list[index].req_id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);

    _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_START, __LINE__);

    wgui_status_icon_bar_animate_icon(STATUS_ICON_AGPS_STATE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ICON_SHOW);
}

static mmi_gps_mgr_result_enum _mmi_gps_mgr_send_start_req(U32 i, kal_bool force_default_slp)
{
    supl_mmi_start_req_struct *local_param_ptr = NULL;
    MMI_BOOL plmn_ret;
    CHAR PLMNNum[GPS_MGR_MAX_PLMN_LEN];
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;
    ilm_struct *ilm_ptr = NULL;
    nvram_em_minigps_up_setting_struct agps_up_setting;
    supl_mmi_position_struct pos;
    supl_mmi_req_assist_data_struct filter;

    local_param_ptr = (supl_mmi_start_req_struct*)construct_local_para(sizeof(supl_mmi_start_req_struct), TD_CTRL);

    if (g_gps_mgr_ctx.req_list[i].work_mode == MMI_GPS_WORK_MODE_MA)
    {
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_SET_ASSIST;
    }
    else
    {
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_SET_BASE;
    }

    mmi_gps_mgr_get_history_pos(&g_gps_mgr_ctx.req_list[i].qop, &pos, &filter);
    memcpy(&local_param_ptr->qop, &g_gps_mgr_ctx.req_list[i].qop, sizeof(supl_mmi_qop_struct));

    data_account = mmi_gps_setting_get_data_account(g_gps_mgr_ctx.req_list[i].sim);
    mmi_gps_setting_get_profile(&agps_profile);

    local_param_ptr->nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)g_gps_mgr_ctx.req_list[i].sim, g_gps_mgr_ctx.app_id, MMI_FALSE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ACCOUND_ID, local_param_ptr->nwk_account_id);
    if (local_param_ptr->nwk_account_id == 0xffffffff)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

        free_local_para((local_para_struct*) local_param_ptr);

        return MMI_GPS_MGR_RESULT_PROFILE_ERROR;
    }
    switch (g_gps_mgr_ctx.req_list[i].sim)
    {
    case MMI_GPS_SETTING_PREFER_SIM_NO1:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM1;
        break;
    case MMI_GPS_SETTING_PREFER_SIM_NO2:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM2;
        break;
    case MMI_GPS_SETTING_PREFER_SIM_NO3:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM3;
        break;
    case MMI_GPS_SETTING_PREFER_SIM_NO4:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM4;
        break;
    default:
        ASSERT(0);
    }
#ifdef __MTK_TARGET__
    memcpy(&local_param_ptr->filter, &filter, sizeof(supl_mmi_req_assist_data_struct));
#else
    memset(&local_param_ptr->filter, 0, sizeof(supl_mmi_req_assist_data_struct));
    local_param_ptr->filter.almanac = MMI_TRUE;
    local_param_ptr->filter.utc_model= MMI_TRUE;
    local_param_ptr->filter.ionospheric_model= MMI_TRUE;
    local_param_ptr->filter.dgps_correction= MMI_TRUE;
    local_param_ptr->filter.ref_location= MMI_TRUE;
    local_param_ptr->filter.ref_time = MMI_TRUE;
    local_param_ptr->filter.acquisition_assist= MMI_TRUE;
    local_param_ptr->filter.realtime_integrity= MMI_TRUE;
    local_param_ptr->filter.navigation_model= MMI_TRUE;
 #endif

    mmi_ucs2_to_asc((CHAR*)local_param_ptr->slp_addr, (CHAR*)agps_profile.addr);
    local_param_ptr->slp_port = (kal_uint16)agps_profile.port;
    if(local_param_ptr->slp_addr[0] == '0' ||
       force_default_slp == KAL_TRUE)
    {
        plmn_ret = srv_sim_ctrl_get_home_plmn((mmi_sim_enum)(local_param_ptr->sim_id + 1),PLMNNum,GPS_MGR_MAX_PLMN_LEN);
        if(plmn_ret == MMI_FALSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

            free_local_para((local_para_struct*) local_param_ptr);

            return MMI_GPS_MGR_RESULT_PROFILE_ERROR;
        }
        kal_sprintf((local_param_ptr->slp_addr),
                     "h-slp.mnc0%c%c.mcc%c%c%c.pub.3gppnetwork.org",
                     PLMNNum[3],
                     PLMNNum[4],
                     PLMNNum[0],
                     PLMNNum[1],
                     PLMNNum[2]);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SLP_ADDRESS,
                 PLMNNum[3],
                 PLMNNum[4],
                 PLMNNum[0],
                 PLMNNum[1],
                 PLMNNum[2]);
        local_param_ptr->slp_port = 7275;
        g_gps_mgr_ctx.req_list[i].need_retry = MMI_FALSE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, MMI_FALSE, __LINE__);
    }

    /* read setttings from NVRAM */
    mmi_gps_setting_get_up_setting(&agps_up_setting);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, agps_up_setting.use_tls);

    g_gps_mgr_ctx.rrc_setting = agps_up_setting.payload;

    /* use TLS? */
    local_param_ptr->use_tls = agps_up_setting.use_tls;

    /* UT Timer */
    local_param_ptr->ut_timer_value = agps_up_setting.ut_timer;

    /* RRC Payload Type */
    switch (g_gps_mgr_ctx.rrc_setting)
    {
    case EM_GPS_UP_PAYLOAD_BOTH:
        local_param_ptr->payload_capability = SUPL_USE_RRC | SUPL_USE_RRLP;
        break;
    case EM_GPS_UP_PAYLOAD_RRLP:
        local_param_ptr->payload_capability = SUPL_USE_RRLP;
        break;
    case EM_GPS_UP_PAYLOAD_RRC:
        local_param_ptr->payload_capability = SUPL_USE_RRC;
        break;

    default:
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
        local_param_ptr->payload_capability = SUPL_USE_RRC | SUPL_USE_RRLP;
        break;
    }

    local_param_ptr->req_id = g_gps_mgr_ctx.req_list[i].req_id;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_START_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_START_REQ);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_ctx.req_list[i].req_id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);

    return MMI_GPS_MGR_RESULT_SUCCESS;
}

static void _mmi_gps_mgr_prev_popup_force_timeout(void)
{
    U8 index;

    for (index = 0; index < MAX_SUPL_REQ_NUM; index++)
    {
        if (g_gps_mgr_ctx.req_list[index].is_used == MMI_TRUE &&
            g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_WAIT_CNF)
        {
            break;
        }
    }

    if (index == MAX_SUPL_REQ_NUM)
    {
        return;
    }

    mmi_gps_mgr_notify_time_out();
}

static void _mmi_gps_mgr_abort_user_confirm(U16 index)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ABORT_USER_CONFIRM, index);

    StopTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id);
    g_gps_mgr_ctx.is_time_out = MMI_TRUE;

    (g_gps_mgr_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_CLOSE_UI, NULL, g_gps_mgr_ctx.app_user_data);

    srv_backlight_turn_off();

    if (mmi_frm_scrn_get_active_id() == SRC_ID_GPS_MGR_NOTIFY)
    {
        mmi_frm_scrn_close(g_gps_mgr_ctx.screen_group_gid, SRC_ID_GPS_MGR_NOTIFY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_da_file
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_da_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, CHAR* url, CHAR* mime_type_string)
{
    PU8 p;
    FS_HANDLE file_handle;
    U32 len;
    U32 file_len;
    U32 header_len;
    U16 len_push_patten1 = 8;
    U16 len_push_patten2 = 26;
    U8 *str_push_id = "X-Wap-Application-Id: ";
    U8 *str_push_patten1 = "ulp.ua\r\n";
    U8 *str_push_patten2 = "x-oma-application:ulp.ua\r\n";
    U8 index = 0;
    U8  current_use_sim = MMI_GPS_SETTING_PREFER_SIM_NO1;
    U8 i;
    //MMI_BOOL is_app_id_right;
    MMI_BOOL can_use_agps = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_DA_FILE, action);

    //is_app_id_right = MMI_FALSE;
    p = (U8*)srv_da_get_header(session_id, &header_len);
    //ASSERT(header_len > 0);

//    p = (U8*)(p + 2);
//    header_len = (U32)(*p);
    p = (U8*)strstr((const CHAR*)p, (const CHAR*)str_push_id);
    p += strlen((const CHAR*)str_push_id);

    if (!((p[0] == 49 && p[1] == 54) /* 16, 0x10 */||
        (!memcmp(p, str_push_patten1,len_push_patten1)) ||
        (!memcmp(p, str_push_patten2,len_push_patten2))
        ))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, 0, __LINE__);
        return;
    }
#if (0)
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

#if defined(__AGPS_CONTROL_PLANE__)
        if (mmi_gps_mgr_cp_is_ongoing() == MMI_TRUE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_CP_IS_ONGOING, __LINE__);
            return;
        }
#endif

    if (action == MMI_DA_PUSH_SIM1)
    {
        current_use_sim = MMI_GPS_SETTING_PREFER_SIM_NO1;
    }
    else if (action == MMI_DA_PUSH_SIM2)
    {
        current_use_sim = MMI_GPS_SETTING_PREFER_SIM_NO2;
    }
    else if (action == MMI_DA_PUSH_SIM3)
    {
        current_use_sim = MMI_GPS_SETTING_PREFER_SIM_NO3;
    }
    else if (action == MMI_DA_PUSH_SIM4)
    {
        current_use_sim = MMI_GPS_SETTING_PREFER_SIM_NO4;
    }

    can_use_agps = mmi_gps_check_if_can_use_agps();

    if ((current_use_sim == MMI_GPS_SETTING_PREFER_SIM_NO1 && srv_nw_usab_is_usable(MMI_SIM1) == MMI_FALSE) ||
        (current_use_sim == MMI_GPS_SETTING_PREFER_SIM_NO2 && srv_nw_usab_is_usable(MMI_SIM2) == MMI_FALSE) ||
        (current_use_sim == MMI_GPS_SETTING_PREFER_SIM_NO3 && srv_nw_usab_is_usable(MMI_SIM3) == MMI_FALSE) ||
        (current_use_sim == MMI_GPS_SETTING_PREFER_SIM_NO4 && srv_nw_usab_is_usable(MMI_SIM4) == MMI_FALSE))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SIM_NOT_VAILD);
        can_use_agps = MMI_FALSE;
    }

    if (mmi_gps_setting_get_send_location() == 0)
    {
        /* user not allow NI */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
        can_use_agps = MMI_FALSE;
    }

    if (can_use_agps)
    {
        for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
        {
            if(g_gps_mgr_ctx.req_list[i].is_used == MMI_FALSE)
            {
                break;
            }
        }
        index = i;
        if (i < MAX_SUPL_REQ_NUM)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

            g_gps_mgr_ctx.req_list[index].start_mode = MMI_GPS_START_MODE_NI;
            //g_gps_mgr_ctx.req_list[index].work_mode = agps_up_setting.molr_prefer;
            g_gps_mgr_ctx.req_list[index].is_used = MMI_TRUE;
            g_gps_mgr_ctx.req_list[index].req_id = g_gps_mgr_ctx.cur_id;
            g_gps_mgr_ctx.req_list[index].sim = current_use_sim;
            g_gps_mgr_ctx.cur_id++;

            file_handle = FS_Open((const WCHAR *) file_path, FS_READ_ONLY);
            FS_GetFileSize(file_handle, &file_len);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_PUSH_DATA_LEN, file_len);
            ASSERT(file_len <= SUPL_MMI_MAX_PUSH_SIZE);
            FS_Read(file_handle, g_gps_mgr_ctx.temp_push_data, file_len, &len);
            FS_Close(file_handle);
            #ifndef MMI_GPS_MGR_DEBUG
               FS_Delete(file_path);
            #endif

            _mmi_gps_mgr_add_into_push_list(g_gps_mgr_ctx.req_list[index].req_id, g_gps_mgr_ctx.temp_push_data, file_len);

        #ifdef __MMI_UCM__
            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0 &&
                srv_nw_info_get_protocol(MMI_SIM1) == MMI_GSM)
        #else
            if (isInCall() &&
                srv_nw_info_get_protocol(MMI_SIM1) == MMI_GSM)
        #endif
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_IN_ACLL);

                if (g_gps_mgr_ctx.cur_push_num == 1)
                {
                    g_gps_mgr_ctx.is_call_abort = MMI_TRUE;
                }
                else
                {
                    if (g_gps_mgr_ctx.is_call_abort == MMI_TRUE)
                    {
                    }
                    else
                    {
                        /* should not happened? */
                        /* call end after isInCall() check, so push list minus 1 */
                        /* we need mutex to protect push_list()? */
                        ASSERT(0);
                    }
                }
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ADD_TO_QUEUE);

                _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_PUSH_WAIT, __LINE__);

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, 0, __LINE__);
                return;
            }

            if (_mmi_gps_mgr_check_push_req_criteria(g_gps_mgr_ctx.cur_push_num))
            {
                _mmi_gps_mgr_send_push_req(GPS_MGR_INVALID_ID, MMI_TRUE);
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ADD_TO_QUEUE);

                _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_PUSH_WAIT, __LINE__);
            }
        }
    }

    /* Remove WAP PUSH */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, 0, __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_call_end
 * DESCRIPTION
 *  mdi uart parser callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_call_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CALL_END);
    if (g_gps_mgr_ctx.is_call_abort == MMI_TRUE)
    {
        _mmi_gps_mgr_send_push_req(GPS_MGR_INVALID_ID, MMI_TRUE);
        g_gps_mgr_ctx.is_call_abort = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_uart_p_callback
 * DESCRIPTION
 *  mdi uart parser callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_uart_p_callback(mdi_gps_parser_p_info_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_UART_P_CALLBACK, type);
    if(type == MDI_GPS_PARSER_P_SYSTEM_START_OK)
    {
        for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
        {
            if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_SET_WORK_MODE)
            {
                if (g_gps_mgr_ctx.cur_work_mode == MMI_GPS_WORK_MODE_MA)
                {
                    mdi_gps_uart_cmd(g_gps_mgr_ctx.req_list[i].gps_port, MDI_GPS_UART_GPS_SWITCH_MODE_MA, NULL);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'A');
                }
                else
                {
                    mdi_gps_uart_cmd(g_gps_mgr_ctx.req_list[i].gps_port, MDI_GPS_UART_GPS_SWITCH_MODE_MB, NULL);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'B');
                }
                StartTimer(GPS_MGR_SET_MODE_TIMER_ID, 5000, mmi_gps_mgr_set_work_mode);
            }
        }
    }
    else if(type == MDI_GPS_PARSER_P_GPS_MODE_SWITCH_OK)
    {
        StopTimer(GPS_MGR_SET_MODE_TIMER_ID);
        mmi_gps_mgr_send_start_supl_req();
    }
}

void mmi_gps_mgr_test_open(void)
{
    mmi_gps_mgr_uart_p_callback(MDI_GPS_PARSER_P_GPS_MODE_SWITCH_OK);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_open_gps
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_gps_mgr_open_gps(
    U16 port,
    mdi_gps_uart_work_mode_enum gps_mode,
    mmi_gps_work_mode_enum work_mode,
    supl_mmi_qop_struct *qop,
    void (*gps_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL can_use_agps;
    U8 i;
    U8 index;
    mmi_gps_mgr_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS, port, gps_mode, work_mode);
    if (MMI_TRUE == srv_ucm_is_emergency_call())
    {
        return MMI_GPS_MGR_RESULT_ECC_CALLING_ERROR;
    }

    can_use_agps = mmi_gps_check_if_can_use_agps();
    if (can_use_agps == MMI_FALSE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_AGPS_OFF, __LINE__);
        return MMI_GPS_MGR_RESULT_AGPS_OFF;
    }

#ifndef MMI_GPS_MGR_DEBUG
    if (work_mode == MMI_GPS_WORK_MODE_MA && gps_mode == MDI_GPS_UART_MODE_RAW_DATA)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_MA_RAW_DATA, __LINE__);
        return MMI_GPS_MGR_MA_RAW_DATA;
    }

#endif

#if defined(__AGPS_CONTROL_PLANE__)
    if (mmi_gps_mgr_cp_is_ongoing() == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_CP_IS_ONGOING, __LINE__);
        return MMI_GPS_MGR_RESULT_CP_IS_ONGOING;
    }
#endif

    if (g_gps_mgr_ctx.cur_work_mode != MMI_GPS_WORK_NO_WORK &&
        g_gps_mgr_ctx.cur_work_mode != work_mode)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_WORK_MODE_DIFFER, __LINE__);
        return MMI_GPS_MGR_RESULT_WORK_MODE_DIFFER;
    }

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_MORE_REQUEST, __LINE__);
        return MMI_GPS_MGR_RESULT_MORE_REQUEST;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, i);
    index = i;

    g_gps_mgr_ctx.req_list[index].start_mode = MMI_GPS_START_MODE_SI;
    g_gps_mgr_ctx.req_list[index].work_mode = work_mode;
    g_gps_mgr_ctx.req_list[index].gps_port = port;
    g_gps_mgr_ctx.req_list[index].gps_mode = gps_mode;
    g_gps_mgr_ctx.req_list[index].gps_callback = gps_callback;
    memcpy(&g_gps_mgr_ctx.req_list[index].qop, qop, sizeof(supl_mmi_qop_struct));
    g_gps_mgr_ctx.req_list[index].is_used = MMI_TRUE;
    g_gps_mgr_ctx.req_list[index].need_retry = MMI_TRUE;
    g_gps_mgr_ctx.req_list[index].is_retrying = MMI_FALSE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, MMI_TRUE, __LINE__);
    g_gps_mgr_ctx.req_list[index].req_id = g_gps_mgr_ctx.cur_id;
    g_gps_mgr_ctx.req_list[index].sim = (U8)mmi_gps_setting_get_sim();
    g_gps_mgr_ctx.cur_id++;
#ifdef __AGPS_LOG_SUPPORT__
    if (gps_mode == MDI_GPS_UART_MODE_LOCATION)
    {
        em_agpslog_start_session((U32)g_gps_mgr_ctx.req_list[index].req_id);
    }
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
              g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);
    if (g_gps_mgr_ctx.open_gps_num[gps_mode] == 0)
    {
        mdi_gps_register_p_callback(mmi_gps_mgr_uart_p_callback);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_UART);
        if (mdi_gps_uart_open(port, gps_mode, mmi_gps_mgr_gps_callback) < 0)
        {
            _mmi_gps_mgr_abort_free_req(index);

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_OPEN_GPS_FAIL, __LINE__);
            return MMI_GPS_MGR_RESULT_OPEN_GPS_FAIL;
        }

        if (g_gps_mgr_ctx.is_pos == MMI_FALSE &&
            g_gps_mgr_ctx.is_count_duration == MMI_FALSE)
        {
            kal_get_time(&g_gps_mgr_ctx.pos_start_time);
            g_gps_mgr_ctx.is_count_duration = MMI_TRUE;
        }

        mdi_gps_set_work_port((U8)port);

        g_gps_mgr_ctx.open_gps_num[gps_mode]++;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                  g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

        if (work_mode == MMI_GPS_WORK_MODE_MB &&
            (g_gps_mgr_ctx.is_pos == MMI_TRUE ||
             (g_gps_mgr_ctx.open_gps_num[0] + g_gps_mgr_ctx.open_gps_num[1] + g_gps_mgr_ctx.open_gps_num[2]) > 1))
        {
            _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_WAIT_POS, __LINE__);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_SUCCESS, __LINE__);

            return MMI_GPS_MGR_RESULT_SUCCESS;
        }

        if (work_mode == MMI_GPS_WORK_MODE_MB ||
            (work_mode == MMI_GPS_WORK_MODE_MA &&
             (g_gps_mgr_ctx.open_gps_num[0] + g_gps_mgr_ctx.open_gps_num[1] + g_gps_mgr_ctx.open_gps_num[2]) == 1))
        {
            g_gps_mgr_ctx.cur_work_mode = work_mode;

            if (work_mode == MMI_GPS_WORK_MODE_MA)
            {
                mdi_gps_uart_cmd(port, MDI_GPS_UART_GPS_SWITCH_MODE_MA, NULL);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'A');
            }
            else
            {
                mdi_gps_uart_cmd(port, MDI_GPS_UART_GPS_SWITCH_MODE_MB, NULL);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'B');
            }
            _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_SET_WORK_MODE, __LINE__);

            StartTimer(GPS_MGR_SET_MODE_TIMER_ID, 5000, mmi_gps_mgr_set_work_mode);

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_SUCCESS, __LINE__);

        #ifndef __MTK_TARGET__
           gui_start_timer(2000, mmi_gps_mgr_test_open);
        #endif

            return MMI_GPS_MGR_RESULT_SUCCESS;
        }
    }
    else
    {
        g_gps_mgr_ctx.open_gps_num[gps_mode]++;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);
    }

    if (work_mode == MMI_GPS_WORK_MODE_MB)
    {
        _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_WAIT_POS, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_SUCCESS, __LINE__);

        return MMI_GPS_MGR_RESULT_SUCCESS;
    }

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_SET_WORK_MODE)
        {
            _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_GPS_INIT, __LINE__);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_SUCCESS, __LINE__);

            return MMI_GPS_MGR_RESULT_SUCCESS;
        }
    }

    ret = _mmi_gps_mgr_send_start_req(index, KAL_FALSE);
    if (ret == MMI_GPS_MGR_RESULT_SUCCESS)
    {
        _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_WORKING, __LINE__);

        g_gps_mgr_ctx.req_list[index].gps_callback(MDI_GPS_SHOW_AGPS_ICON, NULL, 0);
        wgui_status_icon_bar_animate_icon(STATUS_ICON_AGPS_STATE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ICON_SHOW);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

         _mmi_gps_mgr_abort_close_gps(index);
         _mmi_gps_mgr_abort_free_req(index);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_set_work_mode
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_set_work_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_WORK_MODE);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_SET_WORK_MODE)
        {
            break;
        }
    }

    if (g_gps_mgr_ctx.req_list[i].is_used == MMI_FALSE)
    {
        return;
    }

    if (g_gps_mgr_ctx.cur_work_mode == MMI_GPS_WORK_MODE_MA)
    {
        ret = mdi_gps_uart_cmd(g_gps_mgr_ctx.req_list[i].gps_port, MDI_GPS_UART_GPS_SWITCH_MODE_MA, NULL);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'A');
    }
    else
    {
        ret = mdi_gps_uart_cmd(g_gps_mgr_ctx.req_list[i].gps_port, MDI_GPS_UART_GPS_SWITCH_MODE_MB, NULL);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'B');
    }

    if (ret != MDI_RES_GPS_UART_SUCCEED)
    {
        StartTimer(GPS_MGR_SET_MODE_TIMER_ID, 5000, mmi_gps_mgr_set_work_mode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_send_start_supl_req
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_send_start_supl_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_position_struct pos;
    supl_mmi_req_assist_data_struct filter;
    supl_mmi_status_rsp_struct *local_param_ptr2 = NULL;
    ilm_struct *ilm_ptr = NULL;
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_START_SUPL_REQ);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_SET_WORK_MODE ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_GPS_INIT)
        {
            if (g_gps_mgr_ctx.req_list[i].start_mode == MMI_GPS_START_MODE_SI)
            {
                mmi_gps_mgr_result_enum ret;

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, i);

                ret = _mmi_gps_mgr_send_start_req(i, KAL_FALSE);
                if (ret == MMI_GPS_MGR_RESULT_SUCCESS)
                {
                    _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_WORKING, __LINE__);

                    g_gps_mgr_ctx.req_list[i].gps_callback(MDI_GPS_SHOW_AGPS_ICON, NULL, 0);
                    wgui_status_icon_bar_animate_icon(STATUS_ICON_AGPS_STATE);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ICON_SHOW);
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

                    _mmi_gps_mgr_abort_close_gps(i);
                    _mmi_gps_mgr_abort_free_req(i);
                }
            }
            else
            {
                MMI_BOOL pos_ret;

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, i);

                local_param_ptr2 = (supl_mmi_status_rsp_struct*)construct_local_para(sizeof(supl_mmi_status_rsp_struct), TD_CTRL);

                pos_ret = mmi_gps_mgr_get_history_pos(&g_gps_mgr_ctx.req_list[i].qop, &pos, &filter);
                local_param_ptr2->req_id = g_gps_mgr_ctx.req_list[i].req_id;
                local_param_ptr2->obj_valid = 0;
                local_param_ptr2->notify_rsp.result = SUPL_MMI_RESULT_OK;
                SUPL_MMI_USE_NOTIFY_RSP(local_param_ptr2->obj_valid);
                if (pos_ret == MMI_TRUE)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SUPL_USE_POS, __LINE__);
                    SUPL_MMI_USE_POSITION(local_param_ptr2->obj_valid);
                }

                data_account = mmi_gps_setting_get_data_account(g_gps_mgr_ctx.req_list[i].sim);
                mmi_gps_setting_get_profile(&agps_profile);

                local_param_ptr2->nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)g_gps_mgr_ctx.req_list[i].sim, g_gps_mgr_ctx.app_id, MMI_FALSE);

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ACCOUND_ID, local_param_ptr2->nwk_account_id);
                if (local_param_ptr2->nwk_account_id == 0xffffffff)
                {
                    free_local_para((local_para_struct*) local_param_ptr2);
                    mmi_gps_mgr_abort_error_rsp(i);
                    return;
                }

                memcpy(&local_param_ptr2->pos, &pos, sizeof(supl_mmi_position_struct));

            #ifdef __MTK_TARGET__
                memcpy(&local_param_ptr2->filter, &filter, sizeof(supl_mmi_req_assist_data_struct));
            #else
                memset(&local_param_ptr2->filter, 0, sizeof(supl_mmi_req_assist_data_struct));
                local_param_ptr2->filter.acquisition_assist = KAL_TRUE;
                local_param_ptr2->filter.almanac = KAL_TRUE;
                local_param_ptr2->filter.dgps_correction = KAL_TRUE;
                local_param_ptr2->filter.ionospheric_model = KAL_TRUE;
                local_param_ptr2->filter.navigation_model = KAL_TRUE;
                local_param_ptr2->filter.navigation_model= KAL_TRUE;
                local_param_ptr2->filter.realtime_integrity = KAL_TRUE;
                local_param_ptr2->filter.ref_location = KAL_TRUE;
                local_param_ptr2->filter.ref_time = KAL_TRUE;
                local_param_ptr2->filter.utc_model = KAL_TRUE;
            #endif
                SUPL_MMI_USE_FILTER(local_param_ptr2->obj_valid);

                ilm_ptr = allocate_ilm(MOD_MMI);
                ilm_ptr->src_mod_id = MOD_MMI;
                ilm_ptr->dest_mod_id = MOD_SUPL;
                ilm_ptr->sap_id = SUPL_MMI_SAP;
                ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_RSP;
                ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr2;
                ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

                msg_send_ext_queue(ilm_ptr);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_STATUS_RSP);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_ctx.req_list[i].req_id);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);

                _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_WORKING, __LINE__);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_close_gps
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_gps_mgr_close_gps(
    U16 port,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    supl_mmi_abort_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CLOSE_GPS, port, mode);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if(g_gps_mgr_ctx.req_list[i].is_used == MMI_TRUE &&
           g_gps_mgr_ctx.req_list[i].start_mode == MMI_GPS_START_MODE_SI &&
           g_gps_mgr_ctx.req_list[i].gps_callback == gps_callback &&
           g_gps_mgr_ctx.req_list[i].gps_mode == mode &&
           g_gps_mgr_ctx.req_list[i].gps_port == port)
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM || g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_TERMINATE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_FALSE_GPS_CALLBACK, __LINE__);
        return MMI_GPS_MGR_RESULT_FALSE_GPS_CALLBACK;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, i);

    if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_ABORT)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_GPS_ABORTING, __LINE__);
        return MMI_GPS_MGR_RESULT_GPS_ABORTING;
    }
    else if (g_gps_mgr_ctx.req_list[i].state != MMI_AGPS_STATE_WAIT_POS &&
             g_gps_mgr_ctx.req_list[i].state != MMI_AGPS_STATE_SET_WORK_MODE &&
             g_gps_mgr_ctx.emerge_call == MMI_FALSE)
    {
        ilm_ptr = allocate_ilm(MOD_MMI);
        local_param_ptr = (supl_mmi_abort_req_struct*)construct_local_para(sizeof(supl_mmi_abort_req_struct), TD_CTRL);

        local_param_ptr->req_id = g_gps_mgr_ctx.req_list[i].req_id;

        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_SUPL;
        ilm_ptr->sap_id = SUPL_MMI_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_ABORT_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

        msg_send_ext_queue(ilm_ptr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ABORT_REQ);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_ctx.req_list[i].req_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);

        _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_ABORT, __LINE__);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_SUCCESS, __LINE__);
        return MMI_GPS_MGR_RESULT_SUCCESS;
    }
    else
    {
        _mmi_gps_mgr_abort_close_gps(i);

        _mmi_gps_mgr_abort_free_req(i);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_RETURN, MMI_GPS_MGR_RESULT_SUCCESS, __LINE__);
        return MMI_GPS_MGR_RESULT_SUCCESS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_supl_mmi_status_ind_hdlr
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_supl_mmi_status_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_STATUS_IND_HDLR);

    switch (supl_mmi_status_ind_p->status)
    {
        case SUPL_MMI_STATUS_TERMINATED:
            mmi_gps_mgr_supl_mmi_status_terminated(msg);
            break;
        case SUPL_MMI_STATUS_ACTIVATED:
            mmi_gps_mgr_supl_mmi_status_activated(msg);
            break;
        case SUPL_MMI_STATUS_STAND_BY:
            mmi_gps_mgr_supl_mmi_status_stand_by(msg);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_supl_mmi_status_terminated
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_supl_mmi_status_terminated(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;
    U32 id;
    U8 i;
    U8 index;
    U32 pos_end_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_STATUS_TERMINATED);

    id = supl_mmi_status_ind_p->req_id;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_ID, id);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].req_id == id )
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        return;
    }

    index = i;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

    if (supl_mmi_status_ind_p->result != SUPL_MMI_RESULT_OK &&
        supl_mmi_status_ind_p->cause != SUPL_MMI_CAUSE_NO_POSITION)
    {
        if (MMI_GPS_MGR_IS_PHONELOCK == MMI_FALSE)
        {
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_GPS_MGR_NETWORK_CREATE_FAIL +
                                    supl_mmi_status_ind_p->cause -
                                    SUPL_MMI_CAUSE_NETWORK_CREATE_FAIL)), MMI_EVENT_FAILURE, NULL);
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SHOW_POPUP);
    }
#ifdef MMI_AGPS_NEED_TLS

    //kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[GPS Mgr]:SUPL_MMI_CAUSE_TLS_AUTH_FAIL? = %d (%d)", supl_mmi_status_ind_p->cause, SUPL_MMI_CAUSE_TLS_AUTH_FAIL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CURR_START_MODE, g_gps_mgr_ctx.req_list[index].start_mode, __LINE__);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, g_gps_mgr_ctx.req_list[index].need_retry, __LINE__);

    if (supl_mmi_status_ind_p->cause == SUPL_MMI_CAUSE_TLS_AUTH_FAIL &&
        g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_SI &&
        //g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_WORKING &&
        g_gps_mgr_ctx.req_list[index].need_retry == MMI_TRUE)
    {
        mmi_gps_mgr_result_enum ret;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

        g_gps_mgr_ctx.req_list[index].need_retry = MMI_FALSE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, MMI_FALSE, __LINE__);

        ret = _mmi_gps_mgr_send_start_req(index, KAL_TRUE);
        g_gps_mgr_ctx.req_list[index].is_retrying = MMI_TRUE;

        if (ret == MMI_GPS_MGR_RESULT_SUCCESS)
        {
            _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_WORKING, __LINE__);

            wgui_status_icon_bar_animate_icon(STATUS_ICON_AGPS_STATE);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ICON_SHOW);
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);

            _mmi_gps_mgr_abort_close_gps(index);
            _mmi_gps_mgr_abort_free_req(index);
        }
        return;
    }

    //kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[GPS Mgr]:SUPL_MMI_CAUSE_TLS_AUTH_FAIL? = %d (%d)", supl_mmi_status_ind_p->cause, SUPL_MMI_CAUSE_TLS_AUTH_FAIL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CURR_START_MODE, g_gps_mgr_ctx.req_list[index].start_mode, __LINE__);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NEED_RETRY, g_gps_mgr_ctx.req_list[index].need_retry, __LINE__);

    if (supl_mmi_status_ind_p->cause == SUPL_MMI_CAUSE_TLS_AUTH_FAIL &&
        g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_NI &&
        g_gps_mgr_ctx.req_list[index].need_retry == MMI_TRUE)
    {
        _mmi_gps_mgr_send_push_req(g_gps_mgr_ctx.req_list[index].req_id, MMI_FALSE);
        g_gps_mgr_ctx.req_list[index].is_retrying = MMI_TRUE;

        return;
    }

#endif /* MMI_AGPS_NEED_TLS */

    if (g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_SI)
    {
        /* callback mmi */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CALLBACK_MMI);
        g_gps_mgr_ctx.req_list[index].gps_callback(MDI_GPS_PARSER_MA_STATUS, (void*)&supl_mmi_status_ind_p->position,
                                                sizeof(supl_mmi_status_ind_p->position));
        g_gps_mgr_ctx.req_list[index].gps_callback(MDI_GPS_HIDE_AGPS_ICON, NULL, 0);
    }

    if (SUPL_MMI_IF_POSITION_USED(supl_mmi_status_ind_p->obj_valid))
    {
        mmi_gps_mgr_set_pos(&supl_mmi_status_ind_p->position);
    }

    if (g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_WORKING)
    {
        if (g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_NI ||
            (g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_SI &&
            g_gps_mgr_ctx.req_list[index].work_mode == MMI_GPS_WORK_MODE_MA))
        {
            if ((g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_SI &&
                g_gps_mgr_ctx.req_list[index].work_mode == MMI_GPS_WORK_MODE_MA))
            {
                if (g_gps_mgr_ctx.is_count_duration == MMI_TRUE)
                {
                    kal_get_time(&pos_end_time);
                #ifdef __AGPS_LOG_SUPPORT__
                    em_agpslog_procedure_duration(
                            EM_AGPSLOG_PROC_POS_CAL,
                            (U16)kal_ticks_to_milli_secs(pos_end_time - g_gps_mgr_ctx.pos_start_time));
                #endif
                    g_gps_mgr_ctx.is_count_duration = MMI_FALSE;
                }
            }
        #ifdef MMI_GPS_MGR_DEBUG
            if (g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_NI ||
                g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_ABORT)
            {
        #endif
                if(g_gps_mgr_ctx.req_list[index].state != MMI_AGPS_STATE_START)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
                    _mmi_gps_mgr_abort_close_gps(index);
                }
                _mmi_gps_mgr_abort_free_req(index);
                if (g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_NI)
                {
                    _mmi_gps_mgr_send_push_req(GPS_MGR_INVALID_ID, MMI_TRUE);
                }
        #ifdef MMI_GPS_MGR_DEBUG
            }
            else
            {
                _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_WAIT_POS, __LINE__);
            }
        #endif
        }
        else if (g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_SI &&
                 g_gps_mgr_ctx.req_list[index].work_mode == MMI_GPS_WORK_MODE_MB)
        {
            _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_WAIT_POS, __LINE__);
        }
    }
    else if (g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_ABORT)
    {
        _mmi_gps_mgr_abort_close_gps(index);
        _mmi_gps_mgr_abort_free_req(index);
    }
    else if (g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_START ||
            g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_NI_ERROR)
    {
        _mmi_gps_mgr_abort_free_req(index);
        _mmi_gps_mgr_send_push_req(GPS_MGR_INVALID_ID, MMI_TRUE);
    }
    else if (g_gps_mgr_ctx.req_list[index].state == MMI_AGPS_STATE_WAIT_CNF)    // multiple SUPL push case
    {
        _mmi_gps_mgr_abort_user_confirm(index);
        _mmi_gps_mgr_abort_free_req(index);
        _mmi_gps_mgr_send_push_req(GPS_MGR_INVALID_ID, MMI_TRUE);
    }

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_PRT,
                    i,
                    g_gps_mgr_ctx.req_list[i].start_mode,
                    g_gps_mgr_ctx.req_list[i].work_mode,
                    g_gps_mgr_ctx.req_list[i].gps_mode,
                    g_gps_mgr_ctx.req_list[i].state,
                    g_gps_mgr_ctx.req_list[i].req_id,
                    g_gps_mgr_ctx.req_list[i].is_used);

        if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_START ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_ACTIVITATE ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_WAIT_CNF ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_WORKING ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_STAND_BY)
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_AGPS_STATE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ICON_HIDE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_supl_mmi_status_activated
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_supl_mmi_status_activated(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;
    U32 id;
    supl_mmi_position_struct pos;
    supl_mmi_req_assist_data_struct filter;
    supl_mmi_status_rsp_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;
    U8 i;
    U8 j;
    U8 index;
    MMI_BOOL is_usd;
    MMI_BOOL pos_ret;
    nvram_ef_agps_supl_notify_struct notify_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_STATUS_ACTIVATED);

    id = supl_mmi_status_ind_p->req_id;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_ID, id);

    mmi_gps_setting_get_supl_notify_setting(&notify_setting);

    g_gps_mgr_ctx.notify_timer_timeout = notify_setting.notify_time;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SUPL_NOTIFY_TIMER, g_gps_mgr_ctx.notify_timer_timeout, __LINE__);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].req_id == id )
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        return;
    }

    index = i;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

    if (supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_SET_ASSIST)
    {
        g_gps_mgr_ctx.req_list[index].work_mode = MMI_GPS_WORK_MODE_MA;
    }
    else if(supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_SET_BASE)
    {
        g_gps_mgr_ctx.req_list[index].work_mode = MMI_GPS_WORK_MODE_MB;
    }
    else if(supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_AUTO ||
            supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_NO_POSITION)
    {
        g_gps_mgr_ctx.req_list[index].work_mode = MMI_GPS_WORK_MODE_MB;
    }
    else if(supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_UNSUPPORTED)
    {
        g_gps_mgr_ctx.req_list[index].work_mode = MMI_GPS_WORK_MODE_MB;
    }
    else
    {
        ASSERT(0);
    }
    memcpy(&g_gps_mgr_ctx.req_list[index].qop, &supl_mmi_status_ind_p->qop, sizeof(supl_mmi_qop_struct));

    /* L modify */
    if (SUPL_MMI_IF_NOTIFY_USED(supl_mmi_status_ind_p->obj_valid) &&
        (supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_ONLY ||
         supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_ALLOW_NO_ANSWER ||
         supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_DENY_NO_ANSWER ))
    {
        _mmi_gps_mgr_prev_popup_force_timeout();

        g_gps_mgr_ctx.cur_notify_num = 0;
        g_gps_mgr_ctx.notify_list[0].req_id = supl_mmi_status_ind_p->req_id;
        memcpy(&g_gps_mgr_ctx.notify_list[0].notify,
               &supl_mmi_status_ind_p->notify,
               sizeof(supl_mmi_notify_struct));

    #ifdef MMI_GPS_MGR_OP01
        if (g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name[0] == 0 &&
            g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name[1] == 0 &&
            g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id[0] == 0 &&
            g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id[1] == 0)
        {
            mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_OK, g_gps_mgr_ctx.cur_notify_num);
            return;
        }
    #endif

        for (i = 0; i < MAX_NOTIFY_TIMER_ID; i++)
        {
            is_usd = MMI_FALSE;
            for (j = 0; j < MAX_SUPL_REQ_NUM; j++)
            {
                if (g_gps_mgr_ctx.notify_list[j].timer_id == NOTIFY_TIMER_ID_BEGIN + i)
                {
                    is_usd = MMI_TRUE;
                }
            }
            if (is_usd == MMI_FALSE)
            {
                g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id = (MMI_TIMER_IDS)(NOTIFY_TIMER_ID_BEGIN + i);
            }
        }
        /* L modify */
        g_gps_mgr_ctx.screen_group_gid = mmi_frm_group_create(GRP_ID_ROOT,
                                            GRP_ID_AUTO_GEN,
                                            NULL, NULL);
        mmi_frm_group_enter(g_gps_mgr_ctx.screen_group_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_WAIT_CNF, __LINE__);

        if(supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_ONLY)
        {
            mmi_gps_mgr_show_notify_src();
			StartTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id,
                       g_gps_mgr_ctx.notify_timer_timeout, mmi_gps_mgr_notify_time_out);
            /* notify only, send rsp immediately. */
            mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_OK, g_gps_mgr_ctx.cur_notify_num);
        }
        else if(supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_ALLOW_NO_ANSWER ||
                supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_DENY_NO_ANSWER)
        {
            mmi_gps_mgr_show_confirm_src();
            StartTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id,
                       g_gps_mgr_ctx.notify_timer_timeout, mmi_gps_mgr_notify_time_out);
        }
        return;
    }

    _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_ACTIVITATE, __LINE__);

    if(supl_mmi_status_ind_p->pos_method != SUPL_MMI_POS_METHOD_NO_POSITION)
    {
        if (g_gps_mgr_ctx.cur_work_mode != MMI_GPS_WORK_NO_WORK &&
            g_gps_mgr_ctx.cur_work_mode != g_gps_mgr_ctx.req_list[index].work_mode)
        {
            mmi_gps_mgr_abort_error_rsp(index);
            g_gps_mgr_ctx.req_list[index].state = MMI_AGPS_STATE_NI_ERROR;
            return;
        }

        g_gps_mgr_ctx.req_list[index].gps_mode = MDI_GPS_UART_MODE_LOCATION;

        if (g_gps_mgr_ctx.open_gps_num[MDI_GPS_UART_MODE_LOCATION] == 0)
        {
            g_gps_mgr_ctx.port = mmi_gps_get_port_number();
            g_gps_mgr_ctx.req_list[index].gps_port = g_gps_mgr_ctx.port;

            mdi_gps_register_p_callback(mmi_gps_mgr_uart_p_callback);

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_UART);
            if (mdi_gps_uart_open(g_gps_mgr_ctx.port, MDI_GPS_UART_MODE_LOCATION, mmi_gps_mgr_gps_callback) < 0)
            {
                mmi_gps_mgr_abort_error_rsp(index);
                g_gps_mgr_ctx.req_list[index].state = MMI_AGPS_STATE_NI_ERROR;
                return;
            }

            mdi_gps_set_work_port((U8)g_gps_mgr_ctx.port);

            g_gps_mgr_ctx.open_gps_num[MDI_GPS_UART_MODE_LOCATION]++;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                      g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

            if ((g_gps_mgr_ctx.open_gps_num[0] + g_gps_mgr_ctx.open_gps_num[1] + g_gps_mgr_ctx.open_gps_num[2]) == 1)
            {
            g_gps_mgr_ctx.cur_work_mode = g_gps_mgr_ctx.req_list[index].work_mode;

            if (g_gps_mgr_ctx.req_list[index].work_mode == MMI_GPS_WORK_MODE_MA)
            {
                mdi_gps_uart_cmd(g_gps_mgr_ctx.port, MDI_GPS_UART_GPS_SWITCH_MODE_MA, NULL);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'A');
            }
            else
            {
                mdi_gps_uart_cmd(g_gps_mgr_ctx.port, MDI_GPS_UART_GPS_SWITCH_MODE_MB, NULL);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'B');
            }

            _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_SET_WORK_MODE, __LINE__);

            StartTimer(GPS_MGR_SET_MODE_TIMER_ID, 5000, mmi_gps_mgr_set_work_mode);

            /* L modify */
            #ifndef __MTK_TARGET__
            gui_start_timer(2000, mmi_gps_mgr_test_open);
            #endif

            return;
        }
        }

        // not accumulate it when it caused by retrying. (already opened)
        if (g_gps_mgr_ctx.req_list[index].is_retrying == MMI_FALSE)
        {
            g_gps_mgr_ctx.open_gps_num[MDI_GPS_UART_MODE_LOCATION]++;
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                          g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

        for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
        {
            if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_SET_WORK_MODE)
            {
                _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_GPS_INIT, __LINE__);

                return;
            }
        }
    }
    pos_ret = mmi_gps_mgr_get_history_pos(&g_gps_mgr_ctx.req_list[id].qop, &pos, &filter);

    local_param_ptr = (supl_mmi_status_rsp_struct*)construct_local_para(sizeof(supl_mmi_status_rsp_struct), TD_CTRL);

    local_param_ptr->req_id = id;
    local_param_ptr->obj_valid = 0;
    local_param_ptr->notify_rsp.result = SUPL_MMI_RESULT_OK;
    SUPL_MMI_USE_NOTIFY_RSP(local_param_ptr->obj_valid);
    if (pos_ret == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SUPL_USE_POS, __LINE__);
        SUPL_MMI_USE_POSITION(local_param_ptr->obj_valid);
    }

    data_account = mmi_gps_setting_get_data_account(g_gps_mgr_ctx.req_list[index].sim);
    mmi_gps_setting_get_profile(&agps_profile);

    local_param_ptr->nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)g_gps_mgr_ctx.req_list[index].sim, g_gps_mgr_ctx.app_id, MMI_FALSE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ACCOUND_ID, local_param_ptr->nwk_account_id);
    if (local_param_ptr->nwk_account_id == 0xffffffff)
    {
        free_local_para((local_para_struct*) local_param_ptr);
        mmi_gps_mgr_abort_error_rsp(index);
        return;
    }

    memcpy(&local_param_ptr->pos, &pos, sizeof(supl_mmi_position_struct));
    if (pos_ret == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SUPL_USE_POS, __LINE__);
        SUPL_MMI_USE_POSITION(local_param_ptr->obj_valid);
    }

    /* L modify */
    #ifndef __MTK_TARGET__
    kal_mem_set((void*)&filter, 0, sizeof(supl_mmi_req_assist_data_struct));
    filter.ref_location = KAL_TRUE;
    filter.ref_time = KAL_TRUE;
    filter.navigation_model = KAL_TRUE;
    #endif
    memcpy(&local_param_ptr->filter, &filter, sizeof(supl_mmi_req_assist_data_struct));
    SUPL_MMI_USE_FILTER(local_param_ptr->obj_valid);

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_RSP;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_STATUS_RSP);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);

    _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_WORKING, __LINE__);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_supl_mmi_status_stand_by
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_supl_mmi_status_stand_by(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;
    U32 id;
    U8 i;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_STATUS_STAND_BY);

    id = supl_mmi_status_ind_p->req_id;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_ID, id);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].req_id == id )
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        return;
    }

    index = i;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

    if (supl_mmi_status_ind_p->notify.notify_type != SUPL_MMI_NOTIFY_NONE)
    {
        /* show notify */
    }

    _mmi_gps_mgr_abort_close_gps(index);

    _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_STAND_BY, __LINE__);
}

static void _mmi_gps_mgr_translate_ucs2_encoding(CHAR *temp, U32 temp_size)
{
    CHAR *p;
    CHAR temp_char;

    temp[0] =0;
    temp[1] =0;
    if (g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.encodeing_type == SUPL_MMI_ENCODING_UTF8)
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*)temp,
            1024 / 2,
            (U8*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name);
        mmi_ucs2cpy(
            (CHAR*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name,
            (CHAR*)temp);

        mmi_chset_utf8_to_ucs2_string(
            (U8*)temp,
            1024 / 2,
            (U8*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id);
        mmi_ucs2cpy(
            (CHAR*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id,
            (CHAR*)temp);
    }
    else if (g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.encodeing_type == SUPL_MMI_ENCODING_GSM_DEFAULT)
    {
        _mmi_gps_gsm7_to_ascii_array((kal_uint8 *)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name,
                          (kal_uint8 *)temp,
                          temp_size);

        mmi_asc_n_to_ucs2((CHAR*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name, temp, SUPL_MMI_MAX_CLIENT_LEN);

        _mmi_gps_gsm7_to_ascii_array((kal_uint8 *)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id,
                          (kal_uint8 *)temp,
                          temp_size);

        mmi_asc_n_to_ucs2((CHAR*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id, temp, SUPL_MMI_MAX_REQ_LEN);
    }
    else
    {
        p = g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name;
        if(p[0] == 0xfe && p[1] == 0xff)
        {
            while (*p !=0 || *(p + 1) != 0)
            {
                temp_char = *p;
                *p = *(p + 1);
                *(p + 1) = temp_char;
                p = p + 2;
            }
        }
        p = g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id;
        if(p[0] == 0xfe && p[1] == 0xff)
        {
            while (*p !=0 || *(p + 1) != 0)
            {
                temp_char = *p;
                *p = *(p + 1);
                *(p + 1) = temp_char;
                p = p + 2;
            }
        }
    }
}

static void _mmi_gps_mgr_up_prepare_notification_string(CHAR *temp)
{
    U16 temp2[MMI_GPS_MGR_TEMP_BUF2_LENGTH];
    S32 ret = 0;

    temp[0] =0;
    temp[1] =0;

    mmi_ucs2cat((CHAR*)temp, (CHAR*)GetString(STR_ID_GPS_MGR_REQ_POS));

    /* requestor */
    if (g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id[0] != 0 ||
			g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id[1] != 0)
    {
        mmi_ucs2cat((CHAR*)temp, (CHAR*)L"\n");
        mmi_ucs2cat((CHAR*)temp, (CHAR*)GetString(STR_ID_GPS_MGR_REQ_POS_REQUESTOR));

        memcpy(g_gps_mgr_ctx.req_id_name,g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id,2 * SUPL_MMI_MAX_REQ_LEN);
        ret = srv_phb_get_name_by_number(
            g_gps_mgr_ctx.req_id_name,
            temp2,
            MMI_GPS_MGR_TEMP_BUF2_LENGTH * 2);
        if (ret == MMI_TRUE && mmi_ucs2strlen((CHAR*)temp2) != 0)
        {
            mmi_ucs2cat((CHAR*)temp, (CHAR*)temp2);
        }
        else
        {
            mmi_ucs2cat((CHAR*)temp, (CHAR*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.req_id);
        }
    }

    /* application */
    if (g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name[0] != 0 ||
        g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name[1] != 0)
    {
        mmi_ucs2cat((CHAR*)temp, (CHAR*)L"\n");
        mmi_ucs2cat((CHAR*)temp, (CHAR*)GetString(STR_ID_GPS_MGR_REQ_POS_APPLICATION));
        mmi_ucs2cat((CHAR*)temp, (CHAR*)g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].notify.client_name);
    }
}


/*****************************************************************************
 * FUNCTION
*  mmi_gps_mgr_show_notify_src
* DESCRIPTION
*  initialise GPS Setting.
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_show_notify_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR temp[1024];
    mmi_gps_srv_notify_type_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_GPS_MGR_IS_PHONELOCK == MMI_TRUE)
    {
        return;
    }

    _mmi_gps_mgr_translate_ucs2_encoding(temp, 1024);
    _mmi_gps_mgr_up_prepare_notification_string(temp);

    g_gps_mgr_ctx.is_time_out = MMI_FALSE;

    notify.id = g_gps_mgr_ctx.cur_notify_num;
    notify.notify_p = (WCHAR*)temp;
    notify.type = MMI_GPS_SRV_NOTIFY_TYPE_POPUP;
    notify.owner = MMI_GPS_SRV_NOTIFY_OWNER_UP;

    ASSERT(g_gps_mgr_ctx.app_callback != NULL);
    (g_gps_mgr_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_POPUP, &notify, g_gps_mgr_ctx.app_user_data);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_show_notify_src
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_exit_notify_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NOTIFY_TIME_OUT);

    if (g_gps_mgr_ctx.is_time_out == MMI_FALSE)
    {
        StopTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id);
        srv_backlight_turn_off();
        /* already sent in SUPL activated ind */
        //mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_OK, 0);
    }
}


/*****************************************************************************
 * FUNCTION
*  mmi_gps_mgr_show_confirm_src
* DESCRIPTION
*  initialise GPS Setting.
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_show_confirm_src(void)
{
    CHAR temp[1024];
    mmi_gps_srv_notify_type_struct notify;

    if (MMI_GPS_MGR_IS_PHONELOCK == MMI_TRUE)
    {
        return;
    }

    _mmi_gps_mgr_translate_ucs2_encoding(temp, 1024);
    _mmi_gps_mgr_up_prepare_notification_string(temp);

    g_gps_mgr_ctx.is_time_out = MMI_FALSE;

    notify.id = g_gps_mgr_ctx.cur_notify_num;
    notify.notify_p = (WCHAR*)temp;
    notify.type = MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM;
    notify.owner = MMI_GPS_SRV_NOTIFY_OWNER_UP;

    ASSERT(g_gps_mgr_ctx.app_callback != NULL);
    (g_gps_mgr_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM, &notify, g_gps_mgr_ctx.app_user_data);

}


/*****************************************************************************
* FUNCTION
*  mmi_gps_mgr_notify_accept
* DESCRIPTION
*  initialise GPS Setting.
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_notify_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NOTIFY_ACCEPT);

    StopTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id);
    srv_backlight_turn_off();
    mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_OK, g_gps_mgr_ctx.cur_notify_num);

#ifndef __COSMOS_MMI__
    mmi_frm_scrn_close(g_gps_mgr_ctx.screen_group_gid,SRC_ID_GPS_MGR_NOTIFY);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_mgr_notify_decline
* DESCRIPTION
*  initialise GPS Setting.
* PARAMETERS
*  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_notify_decline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NOTIFY_DECLINE);

    StopTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id);
    srv_backlight_turn_off();
    mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_ERROR, g_gps_mgr_ctx.cur_notify_num);

#ifndef __COSMOS_MMI__
    mmi_frm_scrn_close(g_gps_mgr_ctx.screen_group_gid,SRC_ID_GPS_MGR_NOTIFY);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_notify_time_out
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_notify_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NOTIFY_TIME_OUT);

    StopTimer(g_gps_mgr_ctx.notify_list[g_gps_mgr_ctx.cur_notify_num].timer_id);
    g_gps_mgr_ctx.is_time_out = MMI_TRUE;

#ifndef __COSMOS_MMI__
    (g_gps_mgr_ctx.app_callback)(MMI_GPS_SRV_NOTIFY_TYPE_CLOSE_UI, NULL, g_gps_mgr_ctx.app_user_data);
#endif

    srv_backlight_turn_off();
    if (g_gps_mgr_ctx.notify_list[0].notify.notify_type == SUPL_MMI_NOTIFY_ALLOW_NO_ANSWER)
    {
        mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_OK, g_gps_mgr_ctx.cur_notify_num);
    }
    /* L modify */
    else if (g_gps_mgr_ctx.notify_list[0].notify.notify_type == SUPL_MMI_NOTIFY_ONLY)
    {
        /* already sent rsp when SUPL activated. */
    }
    else if (g_gps_mgr_ctx.notify_list[0].notify.notify_type == SUPL_MMI_NOTIFY_DENY_NO_ANSWER)
    {
        mmi_gps_mgr_notify_send_rsp(SUPL_MMI_RESULT_ERROR, g_gps_mgr_ctx.cur_notify_num);
    }

#ifdef __COSMOS_MMI__
    vapp_gps_mgr_notify_timeout();
#else
    if (mmi_frm_scrn_get_active_id() == SRC_ID_GPS_MGR_NOTIFY)
    {
        mmi_frm_scrn_close(g_gps_mgr_ctx.screen_group_gid, SRC_ID_GPS_MGR_NOTIFY);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_notify_send_rsp
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_notify_send_rsp(supl_mmi_result_enum result, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id;
    supl_mmi_position_struct pos;
    supl_mmi_req_assist_data_struct filter;
    supl_mmi_status_rsp_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;
    U8 i;
    U8 req_index;
    MMI_BOOL pos_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = g_gps_mgr_ctx.notify_list[index].req_id;

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].req_id == id )
    {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        return;
    }

    /* L modify */
    req_index = i;

    if (result == SUPL_MMI_RESULT_ERROR)
    {
        mmi_gps_mgr_abort_error_rsp(req_index);

        g_gps_mgr_ctx.req_list[req_index].state = MMI_AGPS_STATE_NI_ERROR;
        return;
    }

    g_gps_mgr_ctx.req_list[req_index].state = MMI_AGPS_STATE_ACTIVITATE;

    if (g_gps_mgr_ctx.cur_work_mode != MMI_GPS_WORK_NO_WORK &&
        g_gps_mgr_ctx.cur_work_mode != g_gps_mgr_ctx.req_list[req_index].work_mode)
    {
        mmi_gps_mgr_abort_error_rsp(req_index);

        g_gps_mgr_ctx.req_list[req_index].state = MMI_AGPS_STATE_NI_ERROR;
        return;
    }

    g_gps_mgr_ctx.req_list[req_index].gps_mode = MDI_GPS_UART_MODE_LOCATION;

    if (g_gps_mgr_ctx.open_gps_num[MDI_GPS_UART_MODE_LOCATION] == 0)
    {
        g_gps_mgr_ctx.port = mmi_gps_get_port_number();
		g_gps_mgr_ctx.req_list[req_index].gps_port = g_gps_mgr_ctx.port;

        mdi_gps_register_p_callback(mmi_gps_mgr_uart_p_callback);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_UART);
        if (mdi_gps_uart_open(g_gps_mgr_ctx.port, MDI_GPS_UART_MODE_LOCATION, mmi_gps_mgr_gps_callback) < 0)
        {
            mmi_gps_mgr_abort_error_rsp(req_index);

            g_gps_mgr_ctx.req_list[req_index].state = MMI_AGPS_STATE_NI_ERROR;
            return;
        }

        if (g_gps_mgr_ctx.is_pos == MMI_FALSE &&
            g_gps_mgr_ctx.is_count_duration == MMI_FALSE)
        {
            kal_get_time(&g_gps_mgr_ctx.pos_start_time);
            g_gps_mgr_ctx.is_count_duration = MMI_TRUE;
        }

        mdi_gps_set_work_port((U8)g_gps_mgr_ctx.port);

        g_gps_mgr_ctx.open_gps_num[MDI_GPS_UART_MODE_LOCATION]++;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                      g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

        if ((g_gps_mgr_ctx.open_gps_num[0] + g_gps_mgr_ctx.open_gps_num[1] + g_gps_mgr_ctx.open_gps_num[2]) == 1)
        {
            g_gps_mgr_ctx.cur_work_mode = g_gps_mgr_ctx.req_list[req_index].work_mode;

            if (g_gps_mgr_ctx.req_list[req_index].work_mode == MMI_GPS_WORK_MODE_MA)
            {
                mdi_gps_uart_cmd(g_gps_mgr_ctx.port, MDI_GPS_UART_GPS_SWITCH_MODE_MA, NULL);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'A');
            }
            else
            {
                mdi_gps_uart_cmd(g_gps_mgr_ctx.port, MDI_GPS_UART_GPS_SWITCH_MODE_MB, NULL);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SET_SWITCH_MODE, 'M', 'B');
            }

            _mmi_gps_mgr_set_state(req_index, MMI_AGPS_STATE_SET_WORK_MODE, __LINE__);

            StartTimer(GPS_MGR_SET_MODE_TIMER_ID, 5000, mmi_gps_mgr_set_work_mode);

            return;
        }
    }

    g_gps_mgr_ctx.open_gps_num[MDI_GPS_UART_MODE_LOCATION]++;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                      g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_SET_WORK_MODE)
        {
            _mmi_gps_mgr_set_state(req_index, MMI_AGPS_STATE_GPS_INIT, __LINE__);

            return;
        }
    }

    pos_ret = mmi_gps_mgr_get_history_pos(&g_gps_mgr_ctx.req_list[req_index].qop, &pos, &filter);

    local_param_ptr = (supl_mmi_status_rsp_struct*)construct_local_para(sizeof(supl_mmi_status_rsp_struct), TD_CTRL);

    local_param_ptr->req_id = id;
    local_param_ptr->obj_valid = 0;
    local_param_ptr->notify_rsp.result = SUPL_MMI_RESULT_OK;
    SUPL_MMI_USE_NOTIFY_RSP(local_param_ptr->obj_valid);
    if (pos_ret == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SUPL_USE_POS, __LINE__);
        SUPL_MMI_USE_POSITION(local_param_ptr->obj_valid);
    }

    data_account = mmi_gps_setting_get_data_account(g_gps_mgr_ctx.req_list[index].sim);
    mmi_gps_setting_get_profile(&agps_profile);

    local_param_ptr->nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)g_gps_mgr_ctx.req_list[index].sim, g_gps_mgr_ctx.app_id, MMI_FALSE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ACCOUND_ID, local_param_ptr->nwk_account_id);
    if (local_param_ptr->nwk_account_id == 0xffffffff)
    {
        free_local_para((local_para_struct*) local_param_ptr);
        mmi_gps_mgr_abort_error_rsp(req_index);
        return;
    }

    memcpy(&local_param_ptr->pos, &pos, sizeof(supl_mmi_position_struct));
    if (pos_ret == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SUPL_USE_POS, __LINE__);
        SUPL_MMI_USE_POSITION(local_param_ptr->obj_valid);
    }

    /* L modify */
    #ifndef __MTK_TARGET__
    kal_mem_set((void*)&filter, 0, sizeof(supl_mmi_req_assist_data_struct));
    filter.ref_location = KAL_TRUE;
    filter.ref_time = KAL_TRUE;
    filter.navigation_model = KAL_TRUE;
    #endif
    memcpy(&local_param_ptr->filter, &filter, sizeof(supl_mmi_req_assist_data_struct));
    SUPL_MMI_USE_FILTER(local_param_ptr->obj_valid);

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_RSP;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    g_gps_mgr_ctx.req_list[req_index].state = MMI_AGPS_STATE_WORKING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_notify_result
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gps_mgr_notify_result(MMI_BOOL is_enable, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifndef __COSMOS_MMI__
/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_notify_time_out
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_app_notify_func(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    MMI_BOOL scr_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
    case MMI_GPS_SRV_NOTIFY_TYPE_POPUP:
        scr_ret = mmi_frm_scrn_enter(
                g_gps_mgr_ctx.screen_group_gid,
                SRC_ID_GPS_MGR_NOTIFY,
                mmi_gps_mgr_exit_notify_src,
                NULL,
                MMI_FRM_FULL_SCRN
        );
        if(scr_ret == MMI_FALSE){
                return ;
        }

        guiBuffer = mmi_frm_scrn_get_gui_buf(g_gps_mgr_ctx.screen_group_gid,SRC_ID_GPS_MGR_NOTIFY);
        ShowCategory65Screen(
            (U8*)notify->notify_p,
            0,
            guiBuffer);
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        break;
    case MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM:
        scr_ret = mmi_frm_scrn_enter(
            g_gps_mgr_ctx.screen_group_gid,
            SRC_ID_GPS_MGR_NOTIFY,
            NULL,
            mmi_gps_mgr_show_notify_src,
            MMI_FRM_FULL_SCRN
        );
        if(scr_ret == MMI_FALSE){
            return ;
        }
        guiBuffer = mmi_frm_scrn_get_gui_buf(g_gps_mgr_ctx.screen_group_gid,SRC_ID_GPS_MGR_NOTIFY);
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type)notify->notify_p,
            0,
            guiBuffer);
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        SetLeftSoftkeyFunction(mmi_gps_mgr_notify_accept, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_gps_mgr_notify_decline, KEY_EVENT_UP);
        break;
    case MMI_GPS_SRV_NOTIFY_TYPE_CLOSE_UI:
        if (mmi_frm_scrn_get_active_id() == SRC_ID_GPS_MGR_NOTIFY)
        {
            mmi_frm_scrn_close(g_gps_mgr_ctx.screen_group_gid,SRC_ID_GPS_MGR_NOTIFY);
        }
        break;
    default:
        ASSERT(0);
    }
}
#endif // #ifdef __COSMOS_MMI__

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_supl_mmi_abort_ind_hdlr
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_supl_mmi_abort_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_abort_cnf_struct *supl_mmi_abort_cnf_p = (supl_mmi_abort_cnf_struct*)msg;
    U32 id;
    U8 i;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ABORT_IND_HDLR);

    id = supl_mmi_abort_cnf_p->req_id;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_ID, id);

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].req_id == id )
        {
            break;
        }
    }

    if (i == MAX_SUPL_REQ_NUM)
    {
        return;
    }

    index = i;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, index);

    g_gps_mgr_ctx.open_gps_num[g_gps_mgr_ctx.req_list[index].gps_mode]--;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                      g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

    if (g_gps_mgr_ctx.open_gps_num[g_gps_mgr_ctx.req_list[index].gps_mode] == 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CLOSE_GPS_UART);
        mdi_gps_uart_close(g_gps_mgr_ctx.req_list[index].gps_port,
                           g_gps_mgr_ctx.req_list[index].gps_mode,
                           mmi_gps_mgr_gps_callback);
        if ((g_gps_mgr_ctx.open_gps_num[0] + g_gps_mgr_ctx.open_gps_num[1] + g_gps_mgr_ctx.open_gps_num[2]) == 0)
        {
        g_gps_mgr_ctx.cur_work_mode = MMI_GPS_WORK_NO_WORK;
            g_gps_mgr_ctx.is_pos = MMI_FALSE;
        }
    }

    _mmi_gps_mgr_abort_free_req(id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_gps_callback
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U32 pos_end_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_GPS_CALLBACK, type);

    if (type == MDI_GPS_PARSER_NMEA_GSA)
    {
        mmi_gps_mgr_gsa_callback(buffer);
    }

    if (g_gps_mgr_ctx.is_pos == MMI_TRUE)
    {
        if (g_gps_mgr_ctx.time_is_sync == MMI_FALSE)
        {
            if (type == MDI_GPS_PARSER_NMEA_RMC)
            {
                /*mmi_gps_mgr_time_sync(buffer);*/
            }
        }

        if (g_gps_mgr_ctx.is_count_duration == MMI_TRUE)
        {
            kal_get_time(&pos_end_time);
        #ifdef __AGPS_LOG_SUPPORT__
            em_agpslog_procedure_duration(
                    EM_AGPSLOG_PROC_POS_CAL,
                    (U16)kal_ticks_to_milli_secs(pos_end_time - g_gps_mgr_ctx.pos_start_time));
        #endif
            g_gps_mgr_ctx.is_count_duration = MMI_FALSE;
        }
    }

    for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
    {
        if(g_gps_mgr_ctx.req_list[i].is_used == MMI_TRUE)
        {
            if (g_gps_mgr_ctx.req_list[i].start_mode == MMI_GPS_START_MODE_SI &&
                g_gps_mgr_ctx.req_list[i].work_mode == MMI_GPS_WORK_MODE_MB)
            {
                if ((type == MDI_GPS_PARSER_RAW_DATA &&
                     g_gps_mgr_ctx.req_list[i].gps_mode == MDI_GPS_UART_MODE_RAW_DATA) ||
                    (type != MDI_GPS_PARSER_RAW_DATA &&
                     g_gps_mgr_ctx.req_list[i].gps_mode != MDI_GPS_UART_MODE_RAW_DATA))
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CALLBACK_MMI);
                    g_gps_mgr_ctx.req_list[i].gps_callback(type, buffer, length);
                }

            #ifndef MMI_GPS_MGR_MA_NOT_ABORT_SUPL_WHEN_POS
                if (g_gps_mgr_ctx.is_pos == MMI_TRUE &&
                    g_gps_mgr_ctx.req_list[i].state != MMI_AGPS_STATE_WAIT_POS &&
                    g_gps_mgr_ctx.req_list[i].state != MMI_AGPS_STATE_ABORT)
                {
                    if (g_gps_mgr_ctx.req_list[i].state != MMI_AGPS_STATE_SET_WORK_MODE)
                {
                        ilm_ptr = allocate_ilm(MOD_MMI);
                        local_param_ptr = (supl_mmi_abort_req_struct*)construct_local_para(sizeof(supl_mmi_abort_req_struct), TD_CTRL);

                        local_param_ptr->req_id = g_gps_mgr_ctx.req_list[i].req_id;

                        ilm_ptr->src_mod_id = MOD_MMI;
                        ilm_ptr->dest_mod_id = MOD_SUPL;
                        ilm_ptr->sap_id = SUPL_MMI_SAP;
                        ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_ABORT_REQ;
                        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
                        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

                        msg_send_ext_queue(ilm_ptr);
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ABORT_REQ);
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_ctx.req_list[i].req_id);
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);
                     }

                    _mmi_gps_mgr_set_state(i, MMI_AGPS_STATE_WAIT_POS, __LINE__);
                }
            #endif
            }
        #ifdef MMI_GPS_MGR_DEBUG
            if (g_gps_mgr_ctx.req_list[i].start_mode == MMI_GPS_START_MODE_SI &&
                g_gps_mgr_ctx.req_list[i].work_mode == MMI_GPS_WORK_MODE_MA)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CALLBACK_MMI);
                g_gps_mgr_ctx.req_list[i].gps_callback(type, buffer, length);
            }
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_gsa_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_gsa_callback(mdi_gps_nmea_gsa_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gsa_struct *gsa_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gsa_data->fix_mode == '2' || gsa_data->fix_mode == '3')
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_FIXED, gsa_data->fix_mode);
        g_gps_mgr_ctx.is_last_pos = g_gps_mgr_ctx.is_pos;
        g_gps_mgr_ctx.is_pos = MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_NO_FIXED);
        g_gps_mgr_ctx.is_last_pos = g_gps_mgr_ctx.is_pos;
        g_gps_mgr_ctx.is_pos = MMI_FALSE;
        g_gps_mgr_ctx.time_is_sync = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_abort_close_gps
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _mmi_gps_mgr_abort_close_gps(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ABORT_CLOSE_GPS, index);
    g_gps_mgr_ctx.emerge_call = MMI_FALSE;
    if (g_gps_mgr_ctx.req_list[index].is_used == MMI_FALSE)
    {
        return;
    }

    g_gps_mgr_ctx.open_gps_num[g_gps_mgr_ctx.req_list[index].gps_mode]--;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_OPEN_GPS_NUM,
                  g_gps_mgr_ctx.open_gps_num[0], g_gps_mgr_ctx.open_gps_num[1], g_gps_mgr_ctx.open_gps_num[2]);

    if (g_gps_mgr_ctx.open_gps_num[g_gps_mgr_ctx.req_list[index].gps_mode] == 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CLOSE_GPS_UART);
        mdi_gps_uart_close(g_gps_mgr_ctx.req_list[index].gps_port,
                           g_gps_mgr_ctx.req_list[index].gps_mode,
                           mmi_gps_mgr_gps_callback);
        if ((g_gps_mgr_ctx.open_gps_num[0] + g_gps_mgr_ctx.open_gps_num[1] + g_gps_mgr_ctx.open_gps_num[2]) == 0)
        {
            g_gps_mgr_ctx.cur_work_mode = MMI_GPS_WORK_NO_WORK;
            g_gps_mgr_ctx.is_pos = MMI_FALSE;
            g_gps_mgr_ctx.is_count_duration = MMI_FALSE;
        /*#ifdef MMI_GPS_MGR_DEBUG
            {
                extern MMI_BOOL b_em_gps_reset_chip_103;
                extern MMI_BOOL b_em_gps_reset_chip_104;
                extern void em_gps_reset_data_104(void);
                extern void em_gps_reset_data_103(void);
                if(b_em_gps_reset_chip_104 == MMI_TRUE)
                {
                    em_gps_reset_data_104();
                }
                else if(b_em_gps_reset_chip_103 == MMI_TRUE)
                {
                    em_gps_reset_data_103();
                }
            }
        #endif*/
        #if defined(MMI_GPS_MGR_DEBUG) && defined(__MMI_ENGINEER_MODE__)
                if(mmi_em_dev_minigps_get_auto_reset_apgs() == MMI_TRUE)
                {
                    mmi_em_dev_minigps_reset_agps_data();
                }
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_abort_error_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_abort_error_rsp(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_rsp_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ABORT_ERROR_RSP, index);
    if (g_gps_mgr_ctx.req_list[index].is_used == MMI_FALSE)
    {
        return;
    }

    local_param_ptr = (supl_mmi_status_rsp_struct*)construct_local_para(sizeof(supl_mmi_status_rsp_struct), TD_CTRL);

    local_param_ptr->req_id = g_gps_mgr_ctx.req_list[index].req_id;
    local_param_ptr->obj_valid = 0;
    local_param_ptr->notify_rsp.result = SUPL_MMI_RESULT_ERROR;
    SUPL_MMI_USE_NOTIFY_RSP(local_param_ptr->obj_valid);

    data_account = mmi_gps_setting_get_data_account(g_gps_mgr_ctx.req_list[index].sim);
    mmi_gps_setting_get_profile(&agps_profile);

    local_param_ptr->nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)g_gps_mgr_ctx.req_list[index].sim, g_gps_mgr_ctx.app_id, MMI_FALSE);

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_RSP;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_STATUS_RSP);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_ID, g_gps_mgr_ctx.req_list[index].req_id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SEND_MSG_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_abort_free_req
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _mmi_gps_mgr_abort_free_req(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ABORT_FREE_REQ, index);
    if (g_gps_mgr_ctx.req_list[index].gps_mode == MDI_GPS_UART_MODE_LOCATION ||
      g_gps_mgr_ctx.req_list[index].start_mode == MMI_GPS_START_MODE_NI)
    {
    #ifdef __AGPS_LOG_SUPPORT__
        em_agpslog_end_session((U32)g_gps_mgr_ctx.req_list[index].req_id);
    #endif
    }
    if (g_gps_mgr_ctx.req_list[index].is_used == MMI_FALSE)
    {
        return;
    }

    if (index == 0) // current running req_id
    {
        /* reset work mode */
        g_gps_mgr_ctx.cur_work_mode = MMI_GPS_WORK_NO_WORK;
    }

    g_gps_mgr_ctx.req_list[index].is_used = MMI_FALSE;
    _mmi_gps_mgr_set_state(index, MMI_AGPS_STATE_TERMINATE, __LINE__);
    _mmi_gps_mgr_remove_from_push_list(g_gps_mgr_ctx.req_list[index].req_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_get_history_pos
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_gps_mgr_get_history_pos(supl_mmi_qop_struct *qop,
                                        supl_mmi_position_struct *pos,
                                        supl_mmi_req_assist_data_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_pos_qop_struct gps_qop;
    gps_pos_result_struct gps_history_pos;
    kal_uint16 gps_bitmap;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_qop.semi_maj_uncertain = qop->horacc;
    gps_qop.semi_min_uncertain = qop->horacc;
    gps_qop.altitude_uncertain_valid = qop->veracc_used;
    gps_qop.altitude_uncertain = qop->veracc;
    gps_qop.delay_valid = qop->delay_used;
    gps_qop.delay = qop->delay;
    gps_qop.age_valid = qop->maxLocAge_used;
    gps_qop.age = qop->maxLocAge;

    memset(&gps_history_pos, 0, sizeof(gps_pos_result_struct));
    ret = mdi_gps_agps_get_history_pos(&gps_qop, &gps_history_pos, &gps_bitmap);

    pos->time_stamp = gps_history_pos.tow;
    pos->week       = gps_history_pos.week;

    if (gps_history_pos.pos_estimate.sign_latitude == KAL_FALSE)
    {
        pos->pos_estimate.latitude_sign = SUPL_MMI_SIGN_NORTH;
    }
    else
    {
        pos->pos_estimate.latitude_sign = SUPL_MMI_SIGN_SOUTH;
    }
    pos->pos_estimate.latitude = gps_history_pos.pos_estimate.latitude;
    pos->pos_estimate.longtude = gps_history_pos.pos_estimate.longtitude;
    pos->pos_estimate.uncertainty_used = MMI_TRUE;
    pos->pos_estimate.uncertainty.major_axis = gps_history_pos.pos_estimate.unc_bear;
    pos->pos_estimate.uncertainty.semi_major = gps_history_pos.pos_estimate.unc_major;
    pos->pos_estimate.uncertainty.semi_minor = gps_history_pos.pos_estimate.unc_minor;
    pos->pos_estimate.confidence_used = MMI_TRUE;
    pos->pos_estimate.confidence = gps_history_pos.pos_estimate.confidence;
    pos->pos_estimate.altitude_info_used = MMI_TRUE;
    pos->pos_estimate.altitude_info.altitude = gps_history_pos.pos_estimate.altitude;
    if (gps_history_pos.pos_estimate.sign_altitude == MMI_FALSE)
    {
        pos->pos_estimate.altitude_info.direction = SUPL_MMI_DIRECTION_HEIGHT;
    }
    else
    {
        pos->pos_estimate.altitude_info.direction = SUPL_MMI_DIRECTION_DEPTH;
    }
    pos->pos_estimate.altitude_info.uncertainty = gps_history_pos.pos_estimate.unc_altitude;

    pos->velocity_used = MMI_TRUE;

    /* reset flags if not valid */
    if (ret == MMI_FALSE)
    {
        pos->pos_estimate.uncertainty_used = MMI_FALSE;
        pos->pos_estimate.confidence_used = MMI_FALSE;
        pos->pos_estimate.altitude_info_used = MMI_FALSE;
        pos->velocity_used = MMI_FALSE;
    }

    switch (gps_history_pos.pos_estimate.velocity.type)
    {
        case GPS_VELOCITY_HOR:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR;
            if (gps_history_pos.pos_estimate.velocity.v.hor_velocity.hor_speed == 0 &&
                gps_history_pos.pos_estimate.bearing == 0)
            {
                pos->velocity_used = MMI_FALSE;
            }
            else
            {
                pos->velocity.v.hor_velocity.bearing.data[0] = gps_history_pos.pos_estimate.bearing & 0xff;
                pos->velocity.v.hor_velocity.bearing.data[1] = gps_history_pos.pos_estimate.bearing >> 8;
                pos->velocity.v.hor_velocity.bearing.num_bits = 2;
                pos->velocity.v.hor_velocity.hor_speed.data[0] = gps_history_pos.pos_estimate.velocity.v.hor_velocity.hor_speed & 0xff;
                pos->velocity.v.hor_velocity.hor_speed.data[1] = gps_history_pos.pos_estimate.velocity.v.hor_velocity.hor_speed >> 8;
                pos->velocity.v.hor_velocity.hor_speed.num_bits = 2;
            }
            break;
        case GPS_VELOCITY_HOR_AND_VER:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR_AND_VER;
            /*pos->velocity.v.hor_uncertainty.bearing.data
            pos->velocity.v.hor_uncertainty.bearing.num_bits
            pos->velocity.v.hor_uncertainty.hor_speed.data
            pos->velocity.v.hor_uncertainty.hor_speed.num_bits
            pos->velocity.v.hor_uncertainty.hor_speed_uncertainty.data
            pos->velocity.v.hor_uncertainty.hor_speed_uncertainty.num_bits*/
            pos->velocity_used = MMI_FALSE;
            break;
        case GPS_VELOCITY_HOR_UNCERT:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR_UNCERT;
            /*pos->velocity.v.hv_velocity.bearing.data =
            pos->velocity.v.hv_velocity.bearing.num_bits =
            pos->velocity.v.hv_velocity.hor_speed.data
            pos->velocity.v.hv_velocity.hor_speed.num_bits*/
            pos->velocity_used = MMI_FALSE;
            break;
        case GPS_VELOCITY_HOR_AND_VER_UNCERT:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR_AND_VER_UNCERT;
            /*pos->velocity.v.hv_uncertainty.bearing.data
            pos->velocity.v.hv_uncertainty.bearing.num_bits =
            pos->velocity.v.hv_uncertainty.hor_speed.data
            pos->velocity.v.hv_uncertainty.hor_speed.num_bits
            pos->velocity.v.hv_uncertainty.hor_speed_uncertainty.data
            pos->velocity.v.hv_uncertainty.hor_speed_uncertainty.num_bits
            pos->velocity.v.hv_uncertainty.ver_direction.data
            pos->velocity.v.hv_uncertainty.ver_direction.num_bits
            pos->velocity.v.hv_uncertainty.ver_speed.data
            pos->velocity.v.hv_uncertainty.ver_speed.num_bits
            pos->velocity.v.hv_uncertainty.ver_speed_uncertainty.data
            pos->velocity.v.hv_uncertainty.ver_speed_uncertainty.num_bits*/
            pos->velocity_used = MMI_FALSE;
            break;
        default:
            pos->velocity_used = MMI_FALSE;
            break;
    }

    filter->almanac =            (gps_bitmap & GPS_ASSIST_MASK_ALMANAC)?MMI_TRUE:MMI_FALSE;
    filter->utc_model =          (gps_bitmap & GPS_ASSIST_MASK_UTC)?MMI_TRUE:MMI_FALSE;
    filter->ionospheric_model =  (gps_bitmap & GPS_ASSIST_MASK_IONOSPHERE)?MMI_TRUE:MMI_FALSE;
    filter->dgps_correction =    (gps_bitmap & GPS_ASSIST_MASK_DGPS_CORRECTION)?MMI_TRUE:MMI_FALSE;
    filter->ref_location =       (gps_bitmap & GPS_ASSIST_MASK_REF_LOCATION)?MMI_TRUE:MMI_FALSE;
    filter->ref_time =           (gps_bitmap & GPS_ASSIST_MASK_REF_TIME)?MMI_TRUE:MMI_FALSE;
    filter->acquisition_assist = (gps_bitmap & GPS_ASSIST_MASK_ACQUISITION)?MMI_TRUE:MMI_FALSE;
    filter->realtime_integrity = (gps_bitmap & GPS_ASSIST_MASK_RTI)?MMI_TRUE:MMI_FALSE;
    filter->navigation_model =   (gps_bitmap & GPS_ASSIST_MASK_NAVIGATION_MODEL)?MMI_TRUE:MMI_FALSE;
    /*filter->nav_model_data*/

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_get_history_pos
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_set_pos(supl_mmi_position_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_agps_set_pos_struct gps_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_pos.gps_week    = pos->week;
    gps_pos.tow         = pos->time_stamp;
    gps_pos.latitude = pos->pos_estimate.latitude;
    if (pos->pos_estimate.latitude_sign == SUPL_MMI_SIGN_NORTH)
    {
        gps_pos.sign_latitude = MMI_FALSE;
    }
    else
    {
        gps_pos.sign_latitude = MMI_TRUE;
    }

    gps_pos.longtitude = pos->pos_estimate.longtude;
    if (pos->pos_estimate.altitude_info_used)
    {
        if (pos->pos_estimate.altitude_info.direction == SUPL_MMI_DIRECTION_HEIGHT)
        {
            gps_pos.sign_altitude = MMI_FALSE;
        }
        else
        {
            gps_pos.sign_altitude = MMI_TRUE;
        }
        gps_pos.altitude = pos->pos_estimate.altitude_info.altitude;
        gps_pos.unc_vert = pos->pos_estimate.altitude_info.uncertainty;
    }
    else
    {
        gps_pos.sign_altitude = MMI_FALSE;
        gps_pos.altitude = 0;
        gps_pos.unc_vert = 0;
    }
    if (pos->pos_estimate.uncertainty_used)
    {
        gps_pos.unc_major = pos->pos_estimate.uncertainty.semi_major;
        gps_pos.unc_minor = pos->pos_estimate.uncertainty.semi_minor;
        gps_pos.unc_bear = pos->pos_estimate.uncertainty.major_axis;
    }
    else
    {
        gps_pos.unc_major = 0;
        gps_pos.unc_minor = 0;
        gps_pos.unc_bear = 0;
    }
    if (pos->pos_estimate.confidence_used)
    {
        gps_pos.confidence = pos->pos_estimate.confidence;
    }
    else
    {
        gps_pos.confidence = 0;
    }
    if (pos->velocity_used)
    {
        switch (pos->velocity.type)
        {
            case SUPL_MMI_VELOCITY_HOR:
                if (pos->velocity.v.hor_velocity.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hor_velocity.hor_speed.data[0];
                }
                else if (pos->velocity.v.hor_velocity.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hor_velocity.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hor_velocity.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }
                gps_pos.bearing = 0;
                break;
            case SUPL_MMI_VELOCITY_HOR_AND_VER:
                if (pos->velocity.v.hv_velocity.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hv_velocity.hor_speed.data[0];
                }
                else if (pos->velocity.v.hv_velocity.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hv_velocity.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hv_velocity.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }

                if (pos->velocity.v.hv_velocity.ver_direction.num_bits == 1)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_velocity.ver_direction.data[0];
                }
                else if (pos->velocity.v.hv_velocity.ver_direction.num_bits == 2)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_velocity.ver_direction.data[0];
                }
                else
                {
                    gps_pos.bearing = 0;
                }
                break;
            case SUPL_MMI_VELOCITY_HOR_UNCERT:
                if (pos->velocity.v.hor_uncertainty.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hor_uncertainty.hor_speed.data[0];
                }
                else if (pos->velocity.v.hor_uncertainty.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hor_uncertainty.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hor_uncertainty.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }
                gps_pos.bearing = 0;
                break;
            case SUPL_MMI_VELOCITY_HOR_AND_VER_UNCERT:
                if (pos->velocity.v.hv_uncertainty.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hv_uncertainty.hor_speed.data[0];
                }
                else if (pos->velocity.v.hv_uncertainty.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hv_uncertainty.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hv_uncertainty.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }

                if (pos->velocity.v.hv_uncertainty.ver_direction.num_bits == 1)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_uncertainty.ver_direction.data[0];
                }
                else if (pos->velocity.v.hv_uncertainty.ver_direction.num_bits == 2)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_uncertainty.ver_direction.data[0];
                }
                else
                {
                    gps_pos.bearing = 0;
                }
                break;
        }
    }
    else
    {
        gps_pos.h_speed = 0;
        gps_pos.bearing = 0;
    }

    mdi_gps_agps_set_pos(&gps_pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_check_ack_sms
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_gps_mgr_check_ack_sms(srv_sms_event_struct* event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_new_sms_struct * indata = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_sms_new_msg_struct *new_msg = (srv_sms_new_msg_struct *)indata->msg_data;
    U8 *msg_content = indata->content;
    MMI_BOOL can_use_agps;
    U8 i;
    U16 len = new_msg->message_len;
    //MMI_BOOL plmn_ret;
    //CHAR PLMNNum[GPS_MGR_MAX_PLMN_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_CHECK_ACK_SMS);
    if (len > 0)
    {
        can_use_agps = mmi_gps_check_if_can_use_agps();

        if (mmi_gps_setting_get_send_location() == 0)
        {
            /* user not allow NI */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_ERROR, __LINE__);
            can_use_agps = MMI_FALSE;
        }

        if (can_use_agps == MMI_TRUE)
        {
            for (i = 0; i <MAX_SUPL_REQ_NUM; i++)
            {
                if(g_gps_mgr_ctx.req_list[i].is_used == MMI_FALSE)
                {
                    break;
                }
            }
            if (i < MAX_SUPL_REQ_NUM)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_REQ_LIST_INDEX, i);
                g_gps_mgr_ctx.req_list[i].start_mode = MMI_GPS_START_MODE_NI;
                g_gps_mgr_ctx.req_list[i].is_used = MMI_TRUE;
                g_gps_mgr_ctx.req_list[i].req_id = g_gps_mgr_ctx.cur_id;
                g_gps_mgr_ctx.req_list[i].sim = (U8)mmi_gps_setting_get_sim();
                g_gps_mgr_ctx.cur_id++;
            #ifdef __AGPS_LOG_SUPPORT__
                em_agpslog_start_session((U32)g_gps_mgr_ctx.req_list[i].req_id);
            #endif

                _mmi_gps_mgr_add_into_push_list(g_gps_mgr_ctx.req_list[i].req_id, (CHAR*)msg_content, len);
                _mmi_gps_mgr_send_push_req(GPS_MGR_INVALID_ID, MMI_TRUE);
            }
        }
    }
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_is_agps_working
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_gps_mgr_is_agps_working(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_SUPL_REQ_NUM; i++)
    {
        if (g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_WORKING ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_STAND_BY ||
            g_gps_mgr_ctx.req_list[i].state == MMI_AGPS_STATE_ABORT)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#endif /* #if defined(__AGPS_USER_PLANE__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_mgr_check_ack_sms
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_mgr_p_info_callback(mdi_gps_parser_p_info_enum type,void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
    gps_p_info_gps_fix_struct *gps_fixed_ptr = (gps_p_info_gps_fix_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_P_INFO_CALLBACK, type);
    if (type == MDI_GPS_PARSER_P_GPS_FIXED_AND_TIME_OK)
    {
        if (mmi_gps_setting_get_time_sync())
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC);
        #ifdef __AGPS_LOG_SUPPORT__
            em_agpslog_mmi_date_time();
        #endif
            utc_time.nYear = (U16)(2000 + gps_fixed_ptr->utc_date.year);
            utc_time.nMonth = (U8)(gps_fixed_ptr->utc_date.month);
            utc_time.nDay = (U8)(gps_fixed_ptr->utc_date.day);
            utc_time.nHour = (U8)(gps_fixed_ptr->utc_time.hour);
            utc_time.nMin= (U8)(gps_fixed_ptr->utc_time.minute);
            utc_time.nSec= (U8)(gps_fixed_ptr->utc_time.second);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC_UTC);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC_YMD, utc_time.nYear, utc_time.nMonth, utc_time.nDay);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC_HMS, utc_time.nHour, utc_time.nMin, utc_time.nSec);

            applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC_RTC);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC_YMD, rtc_time.nYear, rtc_time.nMonth, rtc_time.nDay);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_TIME_SYNC_HMS, rtc_time.nHour, rtc_time.nMin, rtc_time.nSec);

            mmi_dt_set_rtc_dt((MYTIME *)&rtc_time);

        #if defined(__AGPS_USER_PLANE__)
            g_gps_mgr_ctx.time_is_sync = MMI_TRUE;
        #endif

        #ifdef __AGPS_LOG_SUPPORT__
            StartTimer(GPS_MGR_SET_MODE_TIMER_ID, 100, em_agpslog_mmi_date_time);
        #endif
        }
    }
}

#endif /* __GPS_SUPPORT__ || __BT_GPS_SUPPORT__ */

