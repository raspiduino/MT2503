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
 *  UCMInterface.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM exported APIs source file
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"
#ifdef __MMI_UCM__
#include "mmi_rp_core_ucm_def.h"
#include "mmi_rp_app_ucm_def.h"
#include "UCMGProt.h"
#include "UCMProt.h"
#include "UcmCoreProt.h"
#include "UcmSrvGProt.h"
#ifdef __MMI_URI_AGENT__
#include "UcmUhaProt.h"
#endif /* __MMI_URI_AGENT__ */

#include "NwInfoSrvGprot.h" /* srv_nw_info_get_protocol */
#ifdef __MMI_VIDEO_TELEPHONY__
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_is_network_service_available , srv_mode_switch_get_current_mode */
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_VIDEO_TELEPHONY__
#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_unavailable_cause */
#endif /* __MMI_VIDEO_TELEPHONY__ */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "string.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "Unicodexdcl.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_unavailable_cause */
#if (defined( __MMI_BT_CALL_SUPPORT__ ) && !defined(__MMI_TELEPHONY_SUPPORT__))
#include "BtcmSrvGprot.h" /* SRV_BT_CM_HF_CONNECTION */
#endif /* __MMI_BT_SUPPORT__ */

mmi_ucm_cntx_struct g_mmi_ucm_cntx;
mmi_ucm_cntx_struct *g_ucm_p = &g_mmi_ucm_cntx;

static MMI_BOOL flight_mode_finished = MMI_FALSE;
static MMI_BOOL flight_mode_initiated = MMI_FALSE;

#if (defined( __MMI_BT_CALL_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__))
mmi_ucm_make_call_para_struct* g_make_call_para_bt;
#endif /* __MMI_BT_CALL_SUPPORT__ && __MMI_TELEPHONY_SUPPORT__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init
 * DESCRIPTION
 *  Initialize UCM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_context();
    mmi_core_ucm_init_context();
#ifdef __MMI_URI_AGENT__
    mmi_ucm_uha_init();
#endif /* __MMI_URI_AGENT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_vt_init();
#endif /* __MMI_VIDEO_TELEPHONY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_key
 * DESCRIPTION
 *  end key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index_array[SRV_UCM_MAX_GROUP];
	srv_ucm_group_info_struct group_info;
	S32 call_num;
	srv_ucm_single_call_act_req_struct end_single_act_req;
	srv_ucm_single_group_act_req_struct end_conference_act_req;
	srv_ucm_call_info_struct call_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
    {
        if (srv_ucm_is_pending_action() == MMI_TRUE)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_RELEASE_PROCESSING);
            mmi_ucm_end_all_processing_action();
        }
        else if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_RELEASE_OUTGOING);
            mmi_ucm_outgoing_call_endkey();
        }
		
        else if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) > 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_RELEASE_ACTIVE);  
    		call_num = srv_ucm_query_group_data(group_index_array[0], &group_info);
			
            if (call_num == 1)
            {
            	srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
				srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info);
				memcpy(&(end_single_act_req.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));
				
				srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &end_single_act_req, NULL, mmi_ucm_act_callback);
            }
            else
            {
                end_conference_act_req.action_group = group_info.group_id;
    			end_conference_act_req.call_type = group_info.call_type; 
				
                srv_ucm_act_request(SRV_UCM_END_CONFERENCE_ACT, &end_conference_act_req, NULL, mmi_ucm_act_callback);
            }
        }
        else if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) > 0)
        {
            /* release first matched held group */
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_RELEASE_HELD);
    		call_num = srv_ucm_query_group_data(group_index_array[0], &group_info);
			
            if (call_num == 1)
            {
            	srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
				srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info);
				memcpy(&(end_single_act_req.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));
				
				srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &end_single_act_req, NULL, mmi_ucm_act_callback);
            }
            else
            {
                end_conference_act_req.action_group = group_info.group_id;
    			end_conference_act_req.call_type = group_info.call_type; 
				
                srv_ucm_act_request(SRV_UCM_END_CONFERENCE_ACT, &end_conference_act_req, NULL, mmi_ucm_act_callback);
            }			
        }
        else if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_RELEASE_INCOMING);
            mmi_ucm_incoming_call_endkey();
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_NO_CALL);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_marker_scrn_id
 * DESCRIPTION
 *  get marker screen id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_ucm_get_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GRP_ID_UCM_MARKER;
}


#ifdef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_intermediate_marker_scrn_id
 * DESCRIPTION
 *  get intermediate marker screen id
 * PARAMETERS
 *  void
 * RETURNS
 *  Screen ID of intermediate call marker
 *****************************************************************************/
U16 mmi_ucm_get_intermediate_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GRP_ID_UCM_INT_MARKER;
}
#endif /* __MMI_BACKGROUND_CALL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_error_message
 * DESCRIPTION
 *  Error message API for applications which operations are not allowed during in-call.
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_entry_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
MMI_STR_ID mmi_ucm_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID  str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    if (error_result == MMI_UCM_ERR_IS_BG_CALL)
    {
        str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
    }
    return str_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_call_para
 * DESCRIPTION
 * initialize make call parameter. The default value is for common use 
 * PARAMETERS
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_call_para(mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));   
    make_call_para->dial_type = SRV_UCM_CALL_TYPE_NO_DATA_CSD;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_call_para_for_sendkey
 * DESCRIPTION
 * initialize make call parameter for sendkey triggered behaviors. 
 * The default value of dial type will be the type which is decided when pressing send key 
 * PARAMETERS
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_call_para_for_sendkey(mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));
    make_call_para->dial_type = g_ucm_p->call_misc.sendkeys_makecall_dial_type;
    return;
}

MMI_RET mmi_ucm_flight_mode_processing_hdlr(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY)
	{
		flight_mode_initiated = MMI_TRUE;
	}
	if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY)
	{
		flight_mode_finished = MMI_TRUE;
	}
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_launch
 * DESCRIPTION
 *  Dial call api, if there are more than 1 available type, will show call type selection screen, 
 *  if there is only one available type, will make call directly, if disallow to make call, will popup error message
 *  Before filling in make_call_para structure, caller can use mmi_ucm_init_call_para or mmi_ucm_init_call_para_for_sendkey
 *  to init structure first, 
 *  then fill in specific parameters they want
 * PARAMETERS
 *  caller_gid:                [IN]      caller screen group id. before group screen mechanism is ready, fill 0 always
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  Return ucm app group screen id, before group screen mechanism is ready, return 0 always
 *****************************************************************************/
U16 mmi_ucm_call_launch(U16 caller_gid, mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 unicodeLen = 0, i, dial_type_count;
    srv_ucm_dial_act_req_struct check_act_req;
    srv_ucm_result_enum tmp_permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    srv_ucm_result_enum first_permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
#ifdef __MMI_UCM_ECC_BEST_EFFORT__
    mmi_ucm_ecc_hdlr_enum ECC_result;
#endif /* __MMI_UCM_ECC_BEST_EFFORT__ */

#ifdef __MMI_BT_CALL_SUPPORT__
    mmi_id menu_id;
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
#endif /* __MMI_BT_CALL_SUPPORT__ */

    mmi_id parent_gid = mmi_frm_group_get_active_id();
    parent_gid = mmi_frm_group_get_top_parent_group_id(parent_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_LAUNCH_P2, make_call_para->dial_type, mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri));
    /* these parameter should set here for mmi_ucm_exec_dial_cb_by_result */

    g_ucm_p->mo_info.callback = make_call_para->adv_para.after_make_call_callback;
    g_ucm_p->mo_info.callback_para = make_call_para->adv_para.after_callback_user_data;

#ifdef __MMI_BT_CALL_SUPPORT__
    if (!mmi_ucm_is_emergency_number(make_call_para->dial_type, make_call_para->ucs2_num_uri)
        && !mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_CALL_SELECT);
        unicodeLen = mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri);
        if (unicodeLen == 0)
        {
            make_call_cb_para.result = SRV_UCM_RESULT_EMPTY_NUMBER;
            make_call_cb_para.user_data = make_call_para->adv_para.after_callback_user_data;
            if (make_call_para->adv_para.after_make_call_callback != NULL)
            {
                make_call_para->adv_para.after_make_call_callback(&make_call_cb_para);
            }
            mmi_popup_display_ext(srv_ucm_query_error_message(SRV_UCM_RESULT_EMPTY_NUMBER), MMI_EVENT_FAILURE, NULL);
            return GRP_ID_INVALID;
        }
        g_make_call_para_bt = OslMalloc(sizeof(mmi_ucm_make_call_para_struct));
        memcpy(g_make_call_para_bt, make_call_para, sizeof(mmi_ucm_make_call_para_struct));
        g_make_call_para_bt->ucs2_num_uri = OslMalloc(sizeof(U16)*(SRV_UCM_MAX_NUM_URI_LEN+1));
        unicodeLen = (SRV_UCM_MAX_NUM_URI_LEN > unicodeLen) ? (unicodeLen) : (SRV_UCM_MAX_NUM_URI_LEN);
        mmi_ucs2ncpy((CHAR*)g_make_call_para_bt->ucs2_num_uri, (CHAR*)make_call_para->ucs2_num_uri, unicodeLen);
        if (make_call_para->adv_para.phb_data != NULL)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 100);
            g_make_call_para_bt->adv_para.phb_data = OslMalloc(sizeof(U16)*(SRV_UCM_BT_MAX_DIS_NAME_FROM_APP+1));
            memcpy(g_make_call_para_bt->adv_para.phb_data, make_call_para->adv_para.phb_data, sizeof(U16)*(SRV_UCM_BT_MAX_DIS_NAME_FROM_APP+1));
        }

        mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MO_SELECT);
        cui_menu_create_and_run(GRP_ID_UCM_MO_SELECT,
                                CUI_MENU_SRC_TYPE_RESOURCE,
                                CUI_MENU_TYPE_APPMAIN,
                                MENU_ID_UCM_CALL_SELECT,
                                MMI_TRUE,
                                NULL);
        return GRP_ID_UCM_MO_SELECT;
    }
#endif /* __MMI_BT_CALL_SUPPORT__ */

    mmi_ucm_set_act_request_dial_user_data(g_ucm_p->mo_info.callback_para);

    /* mask unsupported call type. current, can not dial CSD/DATA call from ucm app */
    make_call_para->dial_type &= ~(SRV_UCM_CALL_TYPE_DATA_CSD_ALL);

#if (MMI_MAX_SIM_NUM < 4)
    make_call_para->dial_type &= ~(SRV_UCM_SIM4_CALL_TYPE_ALL);
#if (MMI_MAX_SIM_NUM < 3)
    make_call_para->dial_type &= ~(SRV_UCM_SIM3_CALL_TYPE_ALL);
#if (MMI_MAX_SIM_NUM < 2)
    make_call_para->dial_type &= ~(SRV_UCM_SIM2_CALL_TYPE_ALL);
#endif /* (MMI_MAX_SIM_NUM < 2) */
#endif /* (MMI_MAX_SIM_NUM < 3) */
#endif /* (MMI_MAX_SIM_NUM < 4) */

#ifndef __MMI_VOIP__
    make_call_para->dial_type &= ~(SRV_UCM_VOIP_CALL_TYPE);
#endif /* __MMI_VOIP__ */

#ifndef __MMI_VIDEO_TELEPHONY__
    make_call_para->dial_type &= ~(SRV_UCM_VIDEO_CALL_TYPE_ALL);
#else /* __MMI_VIDEO_TELEPHONY__ */
    if ((make_call_para->dial_type & SRV_UCM_VIDEO_CALL_TYPE) &&
        (make_call_para->dial_type & SRV_UCM_VIDEO_CALL_TYPE_SIM2))
    {
        make_call_para->dial_type &= ~(SRV_UCM_VIDEO_CALL_TYPE_ALL);
        make_call_para->dial_type |= mmi_ucm_vt_get_valid_video_call_type();
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (parent_gid != GRP_ID_UCM_PRE_MO)
    {
        mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
        mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_PRE_MO);
    }

    /* check if ECC already exists */
    if (srv_ucm_is_emergency_call())
    {
        mmi_popup_display_ext(srv_ucm_query_error_message(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL), MMI_EVENT_FAILURE, NULL);
        mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_SOS_CALL_EXISTS);
    #ifdef __MMI_BT_CALL_SUPPORT__
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    #endif // __MMI_BT_CALL_SUPPORT__    
        mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
        return GRP_ID_INVALID; /* should return ucm app's group id */
    }

    /* use global para to keep some info */
    /* for mmi_ucm_outgoing_call_sendkey, mmi_ucm_dial_option_make_call, mmi_ucm_is_sos_wait_dial. because this api can not give input parameter */

    /* translate input URI to ascii and copy to g_ucm_p->mo_info.dial_num.num_uri */
    unicodeLen = mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri);
    unicodeLen = (SRV_UCM_MAX_NUM_URI_LEN > unicodeLen) ? (unicodeLen) : (SRV_UCM_MAX_NUM_URI_LEN);
    mmi_wcs_n_to_asc((CHAR*)g_ucm_p->mo_info.dial_num.num_uri, make_call_para->ucs2_num_uri, unicodeLen * ENCODING_LENGTH);

#ifdef __MMI_VIDEO_TELEPHONY__
    /* special handle for only video call type + ECC number case */
    if (!(make_call_para->dial_type & ~SRV_UCM_VIDEO_CALL_TYPE_ALL))
    {
        /* if user dial ECC number with VT type, the type will change to voice type automatically */
        make_call_para->dial_type = mmi_ucm_convert_to_valid_ecc_call_type(make_call_para->dial_type, g_ucm_p->mo_info.dial_num.num_uri);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    /* keep rest info */
    g_ucm_p->mo_info.dial_type = make_call_para->dial_type;
    g_ucm_p->mo_info.highlight_dial_type = make_call_para->adv_para.highlight_dial_type;
    g_ucm_p->mo_info.module_id = make_call_para->adv_para.module_id;
    g_ucm_p->mo_info.is_ip_dial = make_call_para->adv_para.is_ip_dial;
    g_ucm_p->mo_info.phb_data = make_call_para->adv_para.phb_data;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_LAUNCH_P4, g_ucm_p->mo_info.dial_type, g_ucm_p->mo_info.module_id, g_ucm_p->mo_info.is_ip_dial, make_call_para->ucs2_num_uri);

    /* fill check_act_req */
    /* mmi_ucs2ncpy: If unicodLen = 0, just add '\0' for check_act_req.num_uri, so no need to memset check_act_req.num_uri */
    mmi_ucs2ncpy((CHAR*)check_act_req.num_uri, (CHAR*) make_call_para->ucs2_num_uri, unicodeLen);
    check_act_req.is_ip_dial = make_call_para->adv_para.is_ip_dial;
    check_act_req.module_id = make_call_para->adv_para.module_id;
    check_act_req.phb_data = make_call_para->adv_para.phb_data;

#ifdef __MMI_UCM_ECC_BEST_EFFORT__
    /* ECC related handler */
    /* handle ECC with given input call type */
    ECC_result = mmi_ucm_ecc_check_handler(make_call_para->dial_type, &check_act_req, MMI_TRUE);

    if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == ECC_result)
    {
        return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */ 
    }

    /* best effort for ECC */
    if (MMI_UCM_ECC_HDLR_ALL_PASS == ECC_result)
    {
        ECC_result = mmi_ucm_ecc_check_handler(make_call_para->dial_type, &check_act_req, MMI_FALSE);
        if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == ECC_result)
        {
            return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */
        }
    }

    /* handle ECC in best-effort way if the number is ECC for all given types but can not permit to dial in previous step */
    if (MMI_UCM_ECC_HDLR_ALL_PASS == ECC_result)
    {
        ECC_result = mmi_ucm_ecc_check_handler(SRV_UCM_CALL_TYPE_ALL, &check_act_req, MMI_TRUE);
        if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == ECC_result)
        {
            return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */
        }
    }

    if (MMI_UCM_ECC_HDLR_ALL_PASS == ECC_result)
    {
        if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == mmi_ucm_ecc_check_handler(SRV_UCM_CALL_TYPE_ALL, &check_act_req, MMI_FALSE))
        {
            return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */
        }
    }
#endif /* __MMI_UCM_ECC_BEST_EFFORT__ */

    /* if the input number is a SS, mCare, CRSS,  launch corresponding application*/
    if (MMI_FALSE == srv_ucm_is_emergency_number(make_call_para->dial_type , g_ucm_p->mo_info.dial_num.num_uri)&&
        g_ucm_p->mo_info.is_ip_dial != MMI_TRUE &&
        srv_ucm_intercept(make_call_para->dial_type, make_call_para->ucs2_num_uri, make_call_para->adv_para.module_id) == MMI_TRUE)
    {
        mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_OK);
    #ifdef __MMI_BT_CALL_SUPPORT__
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    #endif // __MMI_BT_CALL_SUPPORT__
        mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
        mmi_ucm_delete_dtmf_editor_screen();
        return GRP_ID_INVALID;
    }

    /* decide the available call type based on permit with input dial type */

    /* check each type's dial related permit. the priority will be dial, hold&dial, endall&dial */
    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE; i++)
    {
        if (make_call_para->dial_type & (1 << i))
        {
            check_act_req.call_type = (srv_ucm_call_type_enum)(1 << i);
            if ((tmp_permit_result = mmi_ucm_dial_option(&check_act_req, MMI_UCM_PERMIT_ONLY)) != SRV_UCM_RESULT_OK)
            {
                 g_ucm_p->mo_info.dial_type &= ~(1 << i);
            }
            if (tmp_permit_result > first_permit_result)
            {
                first_permit_result = tmp_permit_result;
            }
        }
    }

    /* prepare menu based on the dial type */
    dial_type_count = mmi_ucm_dial_option_prepare_menu_item(g_ucm_p->mo_info.dial_type);
#if (MMI_MAX_SIM_NUM >= 3)
    g_ucm_p->mo_info.dial_type_count = dial_type_count;
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    /* decide the available dial types, if ==0, pop err msg */
    if (dial_type_count == 0)
    {
        if (SRV_UCM_RESULT_UNSPECIFIED_ERROR == first_permit_result)
        {
            first_permit_result = SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        }
        mmi_ucm_display_error_popup(first_permit_result);
        mmi_ucm_exec_dial_cb_by_result(first_permit_result);
    #ifdef __MMI_BT_CALL_SUPPORT__
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    #endif // __MMI_BT_CALL_SUPPORT__    
        mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
        return GRP_ID_INVALID; /*should return ucm app's group id */
    }
   
    /* dial call directly if only one call type */
    if (dial_type_count == 1)
    {
        check_act_req.call_type = g_ucm_p->mo_info.dial_type;

       // MMI_ASSERT(first_permit_act_op != SRV_UCM_NO_ACT);  /* because at least one permit is pass */
    #ifdef __MMI_VIDEO_TELEPHONY__
        /* not dial VT call if out of 3G coverage */
        if (((SRV_UCM_VIDEO_CALL_TYPE == check_act_req.call_type) && (srv_nw_info_get_protocol(MMI_SIM1) != MMI_WCDMA)) ||
            ((SRV_UCM_VIDEO_CALL_TYPE_SIM2 == check_act_req.call_type) && (srv_nw_info_get_protocol(MMI_SIM2) != MMI_WCDMA)))
        {
            mmi_popup_display_ext(STR_ID_UCM_OUT_OF_3G_COVERAGE, MMI_EVENT_FAILURE, NULL);
            mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL);
        #ifdef __MMI_BT_CALL_SUPPORT__
            mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
        #endif // __MMI_BT_CALL_SUPPORT__
            mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
            return GRP_ID_INVALID; /*should return ucm app's group id */
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        /* background sound */
    #ifdef __MMI_BG_SOUND_EFFECT__
        if (MMI_TRUE == srv_ucm_is_emergency_number(check_act_req.call_type , (U8 *)g_ucm_p->mo_info.dial_num.num_uri))
        {
            /* Do nothing, because if it's ECC, should not enter bgsound even bgsound permit is ok */
        }
        /* if UCM srv can provide srv_ucm_query_bgs_outgoing_call_permit, then the check can be replaced */
        else if (MMI_TRUE == srv_ucm_query_bgs_outgoing_call_permit(g_ucm_p->mo_info.dial_type))
        {
            if (g_ucm_p->call_misc.is_bgs_selected == MMI_FALSE)
            {
                /* enter select background sound effect */
                mmi_ucm_enter_bgs_effect_select(GRP_ID_UCM_PRE_MO);
                mmi_frm_scrn_close(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_DIAL_CALL_TYPE_MENU);
                return GRP_ID_UCM_PRE_MO;
            }
            else
            {
                /* reset the flag and continue outgoing call procedure */
                g_ucm_p->call_misc.is_bgs_selected = MMI_FALSE;
            }
        }
    #endif /* __MMI_BG_SOUND_EFFECT__ */

        /* dial out */
        if ((tmp_permit_result = mmi_ucm_dial_option(&check_act_req, MMI_UCM_EXEC_IF_PERMIT_PASS)) != SRV_UCM_RESULT_OK)
        {
            mmi_ucm_display_error_popup(tmp_permit_result);
            mmi_ucm_exec_dial_cb_by_result(tmp_permit_result);
        #ifdef __MMI_BT_CALL_SUPPORT__
            mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
        #endif // __MMI_BT_CALL_SUPPORT__
            mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
            return GRP_ID_INVALID;
        }
        return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */
    }
#if (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    else if ((GetNumOfChild_Ext(MENU_ID_UCM_CALL_TYPE) == 1) &&
             (GetSeqItemId_Ext(MENU_ID_UCM_CALL_TYPE, 0) == MENU_ID_UCM_CALL_TYPE_VOICE))
    {
        /* only voice call types available, go to sim selection screen */
		if ((flight_mode_initiated && flight_mode_finished) || (!flight_mode_initiated))
		{
        mmi_ucm_dial_option_select_sim();
			flight_mode_initiated = MMI_FALSE;
			flight_mode_finished = MMI_FALSE;
		}
        return GRP_ID_UCM_PRE_MO;
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)  */
    /* if available types > 1, need display call type selection */
    else if (dial_type_count > 1)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_LAUNCH_P1, GetNumOfChild_Ext(MENU_ID_UCM_CALL_TYPE));
		if ((flight_mode_initiated && flight_mode_finished) || (!flight_mode_initiated))
		{
        mmi_ucm_enter_call_type();
			flight_mode_initiated = MMI_FALSE;
			flight_mode_finished = MMI_FALSE;

		}
        return GRP_ID_UCM_PRE_MO; /*should return ucm app's group id */
    }
    else
    {
        MMI_ASSERT(0);
    }

    return GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_reconstruct
 * DESCRIPTION
 *  Reconstruct UCM screens in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_reconstruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_group_id = mmi_frm_group_get_active_id();
    MMI_ID top_group_id = GRP_ID_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RECONSTRUCT);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /* delete all call screebs */
        mmi_ucm_delete_all_screen();

        /* add marker to history */
		
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) != srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CSD_CALL_TYPE_ALL, NULL))
        {
            /* no marker for single active csd call */
            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0 && srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
            {
                mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_MARKER, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_marker_sg_proc);    
            }
        }

        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 || srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 )
        {
            /* add in call screen to history */
        #ifdef __MMI_VIDEO_TELEPHONY__
            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0 || srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
            {
                mmi_ucm_add_sg_to_root(GRP_ID_UCM_VT, GRP_ID_UCM_MARKER, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_marker_sg_proc);
                top_group_id = GRP_ID_UCM_VT;
            }
            else
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            {
                mmi_ucm_add_incall_sg_scrn(SRV_UCM_VOICE_CALL_TYPE, active_group_id, MMI_FRM_NODE_BEFORE_FLAG);
                top_group_id = GRP_ID_UCM_INCALL;
            }
        }

        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 )
        {
        #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
            /* add intermediate_marker to history */
            mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_INT_MARKER, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_int_marker_sg_proc);    
        #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

            /* add incoming call screen to history */
#ifdef __SLIM_UCM__
            //mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_MT, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_mt_sg_proc);
#else
            mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_MT, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_mt_sg_proc);
#endif
            mmi_ucm_enter_incoming_call();
            top_group_id = GRP_ID_UCM_MT;
        }

        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 )
        {
        #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
            /* add intermediate_marker to history */
            mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_INT_MARKER, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_int_marker_sg_proc);    
        #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

            /* add outgoing call screen to history */
#ifdef __SLIM_UCM__
            //mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_MO, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_mo_sg_proc);    
#else
            mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_MO, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_mo_sg_proc);    
#endif
            mmi_ucm_enter_outgoing_call();
            top_group_id = GRP_ID_UCM_MO;
        }

        if (srv_ucm_is_pending_action() == MMI_TRUE)
        {
        #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
            if (!mmi_frm_group_is_present(GRP_ID_UCM_INT_MARKER))
            {
                /* add intermediate_marker to history */
                mmi_ucm_add_sg_to_root(active_group_id, GRP_ID_UCM_INT_MARKER, MMI_FRM_NODE_BEFORE_FLAG, mmi_ucm_int_marker_sg_proc); 
            }
        #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

            if (GRP_ID_INVALID != top_group_id)
            {
                mmi_ucm_enter_processing_screen(top_group_id);
            }
        }	
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_showAOC
 * DESCRIPTION
 *  Get AOC display status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: should display AOC info
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_show_aoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_cost.uid_info.call_id != SRV_UCM_INVALID_INDEX) 
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_sendkeys_for_call
 * DESCRIPTION
 *   send keys (ex, sendkey1 or sendkey2) handler.  
 *   if the caller application (ex. idle) need to have different behaviors for dual sim project and single sim project, 
 *   should register different sendkey handler by itself. 
 *   This API provides common sendkeys handler (dual sim: sendkey1 and 2, single sim: sendkey).
 * PARAMETERS
 *  newCallFunc:            [IN]      callback function after sendkey is pressed. Caller should trigger make call if necessary
 *  keyevent:            [IN]   KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key is pressed or released
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_sendkeys_for_call(FuncPtr newCallFunc, mmi_key_types_enum keyevent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_sendkey_hdlr(newCallFunc);
    switch(keyevent)
{
    case KEY_EVENT_UP:
#if (MMI_MAX_SIM_NUM >= 2)
    SetKeyUpHandler(mmi_ucm_sendkeys_send1_hdlr, KEY_SEND);
#ifdef __SENDKEY2_SUPPORT__
    SetKeyUpHandler(mmi_ucm_sendkeys_send2_hdlr, KEY_SEND2);
#endif /* __SENDKEY2_SUPPORT__ */
#else /*(MMI_MAX_SIM_NUM >= 2)*/
    SetKeyUpHandler(mmi_ucm_sendkeys_send_hdlr, KEY_SEND);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
break;
case KEY_EVENT_DOWN:
	
#if (MMI_MAX_SIM_NUM >= 2)
    SetKeyDownHandler(mmi_ucm_sendkeys_send1_hdlr, KEY_SEND);
#ifdef __SENDKEY2_SUPPORT__
    SetKeyDownHandler(mmi_ucm_sendkeys_send2_hdlr, KEY_SEND2);
#endif /* __SENDKEY2_SUPPORT__ */
#else /*(MMI_MAX_SIM_NUM >= 2)*/
    SetKeyDownHandler(mmi_ucm_sendkeys_send_hdlr, KEY_SEND);
#endif /* (MMI_MAX_SIM_NUM >= 2) */

break;
}
}


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_volume_change_cb
 * DESCRIPTION
 *  Handler for that volume is changed on non_VTCS incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_volume_change_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)    
    { 
        /*because user can not adjust time to silent level in volume-adjust-screen*/
        mmi_ucm_vt_set_speaker_status(MMI_TRUE);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_check_launch_capability
 * DESCRIPTION
 *  Check if the video call screen can be launched or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means can launch video call screen
 *  otherwise means cannot
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_check_launch_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum check_sim = MMI_SIM1;
    mmi_sim_enum sim_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_3G_SWITCH__
    check_sim = srv_netset_get_3g_capability_sim();
#endif /* __MMI_3G_SWITCH__ */

    if (MMI_FALSE == srv_mode_switch_is_network_service_available() ||
        (SRV_MODE_SWITCH_OFF == srv_mode_switch_get_network_mode(check_sim)))
    {
        return MMI_FALSE;
    }

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if ((check_sim & sim_id) &&
            (srv_sim_ctrl_get_unavailable_cause(sim_id) != SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_appmgr_launch
 * DESCRIPTION
 *  Video call App manager launch fucntion
 * PARAMETERS
 *  param                   [IN] no use now
 *  param_size            [IN] no use now
 * RETURNS
 *  Group id
 *****************************************************************************/
mmi_id mmi_ucm_vt_appmgr_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_app_launch();
    return GRP_ID_UCM_VT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_app_launch
 * DESCRIPTION
 *  launch video call application (used for entering vt app from call center)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_app_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_ucm_vt_check_launch_capability())
    {
        /* disallow to enter, use popup */
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, NULL);
        return;
    }
    mmi_ucm_vt_enter_in_call();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_vt_sg_in_active
 * DESCRIPTION
 *  check if the active is VT screen (active call exist, not preview mode)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means current active screen is VT and VT call exists
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_vt_sg_in_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0) &&
        (GRP_ID_UCM_VT == mmi_frm_group_get_active_id()))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* __MMI_VIDEO_TELEPHONY__ */



/* ==================================================================================== */
/* =============WRAPPER APIs=========================================================== */
/* ==================================================================================== */


/* This is a wrapper api for apps which is used before revise. */
/* These applications must use set channel before calling this MakeCall API */
/* Therefore here cna use get channel to decide the call type */
/*****************************************************************************
 * FUNCTION
 *  MakeCall
 * DESCRIPTION
 *  a wrapper API for other applications to trigger make call action
 *  Only for the applications which already use it before UCM3.0 revise.  
 *  New common api mmi_ucm_call_launch is recommended.
 * PARAMETERS
 *  ucs2_strNumber:            [IN]      UCS2 number uri with null termination
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCall(CHAR* ucs2_strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;
    mmi_ucm_make_call_para_struct makecall_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       

    call_type = SRV_UCM_VOICE_CALL_TYPE;
    mmi_ucm_init_call_para(&makecall_para);
    makecall_para.dial_type = call_type;
    makecall_para.ucs2_num_uri = (U16*)ucs2_strNumber;
    mmi_ucm_call_launch(0, &makecall_para);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_make_call
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  call_type       [IN]            Call type
 *  num_uri			[IN]			Number or URI in unicode string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_make_call(mmi_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);  
    make_call_para.dial_type = (srv_ucm_call_type_enum)call_type;
    make_call_para.ucs2_num_uri = (U16*)num_uri;
    mmi_ucm_call_launch(0, &make_call_para);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetCmMarkerScrnID
 * DESCRIPTION
 *  a wrapper API for getting cm marker screen id (mmi_ucm_get_marker_scrn_id)
 * PARAMETERS
 *  void
 * RETURNS
 *  Maker screen id.
 *****************************************************************************/
U16 GetCmMarkerScrnID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_get_marker_scrn_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_entry_error_message
 * DESCRIPTION
 *  a wrapper API for displaying error message API for applications which operations are not 
 *  allowed during in-call (mmi_ucm_entry_error_message)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_entry_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_entry_error_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_get_marker_scrn_id
 * DESCRIPTION
 *  a wrapper API for getting cm marker screen id (mmi_ucm_get_marker_scrn_id)
 * PARAMETERS
 *  void
 * RETURNS
 *  Maker screen id.
 *****************************************************************************/
U16 mmi_ucm_app_get_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_get_marker_scrn_id();
}


#ifdef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_get_intermediate_marker_scrn_id
 * DESCRIPTION
 *   a wrapper API for getting intermediate marker screen id (mmi_ucm_get_intermediate_marker_scrn_id)
 * PARAMETERS
 *  U16
 * RETURNS
 *  Intermediate marker screen id.
 *****************************************************************************/
U16 mmi_ucm_app_get_intermediate_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_get_intermediate_marker_scrn_id();
}
#endif /*__MMI_BACKGROUND_CALL__*/


#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_set_to_active_grp
 * DESCRIPTION
 *  Get the incall screen to be the active screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_change_to_incall_scrn(void)
{
#if !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL);
    MMI_ID scrn_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, incall_type, MMI_FALSE, NULL) > 0) ||
        (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, incall_type, MMI_FALSE, NULL) > 0))
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        if ((srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0) ||
            (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0))
        {
            mmi_frm_set_active_group(GRP_ID_UCM_MARKER);
            mmi_frm_set_active_group(GRP_ID_UCM_VT);
            scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_UCM_VT, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
            if (SCR_ID_UCM_VT_INCALL != scrn_id)
            {
                mmi_frm_scrn_multiple_close(GRP_ID_UCM_VT, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_VT_INCALL, MMI_FALSE);
            }
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            mmi_frm_set_active_group(GRP_ID_UCM_MARKER);
            mmi_frm_set_active_group(GRP_ID_UCM_INCALL);
            scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_UCM_INCALL, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
            if (SCR_ID_UCM_IN_CALL != scrn_id)
            {
                mmi_frm_scrn_multiple_close(GRP_ID_UCM_INCALL, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_IN_CALL, MMI_FALSE); 
            }
        }
    }
#endif /* !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
}

#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */

#endif /* __MMI_UCM__ */

