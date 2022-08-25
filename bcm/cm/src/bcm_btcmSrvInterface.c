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
 * BtcmSrvInterface.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM external API and internal API declaration
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_BT_SUPPORT__
#include "MMI_features.h"
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "BtcmSrvGprot.h"
#include "BtcmSrvProt.h"
#include "bluetooth_bm_struct.h"

#ifdef __MMI_HFP_SUPPORT__
#include "bcm_BthfSrvGprot.h"
#endif /*__MMI_HFP_SUPPORT__*/

#ifdef __SUPPORT_JBT__
#include "mmiapi_bt_struct.h"
#include "BTMMIBccGprots.h"
#endif

#include "ModeSwitchSrvGprot.h"

// #ifdef __DM_LAWMO_SUPPORT__
// #include "dmuigprot.h"
// #endif /*__DM_LAWMO_SUPPORT__*/

#include "conversions.h"

// RHR: add
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "mmiapi_dm_struct.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "app_ltlcom.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
//#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "bluetooth_struct.h"
// RHR: add
#include "mmi_rp_srv_btcm_def.h"
#include "SimCtrlSrvGprot.h"
#else
#include "Bcm_btcmSrvGprot.h"
#include "Bcm_btcmSrvProt.h"
#include "bcmadp.h"
#include "bcm_trc.h"
#include "bluetooth_bm_struct.h"

#ifdef __MMI_HFP_SUPPORT__
#include "bcm_BthfSrvGprot.h"
#endif /*__MMI_HFP_SUPPORT__*/

#ifdef __SUPPORT_JBT__
//#include "mmiapi_bt_struct.h"
//#include "BTMMIBccGprots.h"
#endif

#include "conversions.h"

// RHR: add
#include "kal_trace.h"
#include "string.h"
#include "app_ltlcom.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "kal_general_types.h"
//#include "TimerEvents.h"
#include "kal_public_api.h"
#include "bluetooth_struct.h"

#endif

/* profile ID and connection type mapping table */
const U16 profile_id_to_connect_type_map[SRV_BT_CM_NUM_OF_PROFILE_UUID][2] = 
{
#if defined(__MMI_HFP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
#ifdef __BT_DIALER_SUPPORT__
    {SRV_BT_CM_HF_PROFILE_UUID, SRV_BT_CM_HF_CONNECTION},
#else
    {SRV_BT_CM_HF_PROFILE_UUID, SRV_BT_CM_HFP_CONNECTION},
#endif
    {SRV_BT_CM_HFG_PROFILE_UUID, SRV_BT_CM_HFP_CONNECTION},
    {SRV_BT_CM_HS_PROFILE_UUID, SRV_BT_CM_HSP_CONNECTION},
    {SRV_BT_CM_HEADSET_AG_SERVICE_UUID, SRV_BT_CM_HSP_CONNECTION},
#endif
#ifdef __MMI_DUN_SUPPORT__
    {SRV_BT_CM_DUN_PROFILE_UUID, SRV_BT_CM_DUN_CONNECTION},
#endif
#if defined(__MMI_SPP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_SPP_PROFILE_UUID, SRV_BT_CM_SPP_CONNECTION},
#endif
#ifndef __MMI_BT_SLIM__
    {SRV_BT_CM_LAP_PROFILE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_OBEX_IR_MC_SYNC_SERVICE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_ICP_PROFILE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_PAN_PANU_PROFILE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_PAN_NAP_PROFILE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_PAN_GN_PROFILE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_DIRECT_PRINTING, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_CTP_PROFILE_UUID, SRV_BT_CM_NO_CONNECTION},
    {SRV_BT_CM_AUDIO_SOURCE_UUID, SRV_BT_CM_NO_CONNECTION},
#endif
#if defined(__MMI_OPP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID, SRV_BT_CM_OPP_CONNECTION},
#endif
#if defined(__MMI_FTC_SUPPORT__) ||defined(__MMI_FTS_SUPPORT__)
    {SRV_BT_CM_OBEX_FILE_TRANSFER_UUID, SRV_BT_CM_FTP_CONNECTION},
#endif
#if defined(__MMI_A2DP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_AUDIO_SINK_UUID, SRV_BT_CM_A2DP_SINK_CONNECTION},
    {SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID, SRV_BT_CM_A2DP_CONNECTION},
#endif
#if defined(__MMI_AVRCP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID, SRV_BT_CM_AVRCP_CONNECTION},
#endif
#if defined(__MMI_AVRCP_CT_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_AV_REMOTE_CONTROL_UUID, SRV_BT_CM_AVRCP_CT_CONNECTION},
#endif
#ifdef __MMI_FAX_SUPPORT__
    {SRV_BT_CM_FAX_PROFILE_UUID, SRV_BT_CM_FAX_CONNECTION}, 
#endif
#ifdef __MMI_BIP_SUPPORT__
    {SRV_BT_CM_OBEX_IMAGING_UUID, SRV_BT_CM_BIPC_CONNECTION},
    {SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID, SRV_BT_CM_BIP_CONNECTION},
#endif
#ifdef __MMI_BPP_SUPPORT__
    {SRV_BT_CM_BASIC_PRINTING, SRV_BT_CM_BPP_CONNECTION},
#endif
#if defined(__MMI_HIDD_SUPPORT__)
    {SRV_BT_CM_HID_PROFILE_UUID, SRV_BT_CM_HID_CONNECTION},
#endif
#ifdef __MMI_SIMAP_SUPPORT__
    {SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, SRV_BT_CM_SIMAP_CONNECTION},
#endif
#if defined(__MMI_PBAP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_OBEX_PBA_PROFILE_UUID, SRV_BT_CM_PBAP_CONNECTION},
#endif
#if defined(__MMI_BT_PBAP_CLIENT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID, SRV_BT_CM_PBAPC_CONNECTION},
#endif
#ifdef __MMI_BPP_SUPPORT__
    {SRV_BT_CM_OBEX_BPPS_PROFILE_UUID, SRV_BT_CM_BPP_CONNECTION},
#endif
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    {SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, SRV_BT_CM_SYNCML_CONNECTION},
#endif
#if defined(__MMI_OPP_SUPPORT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID, SRV_BT_CM_OPPC_CONNECTION},
#endif
#ifdef __MMI_FTC_SUPPORT__
    {SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID, SRV_BT_CM_FTPC_CONNECTION},
#endif
#if defined(__MMI_BT_MAP_CLIENT__) ||defined(__BT_DIALER_SUPPORT__)
    {SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID, SRV_BT_CM_MAPC_CONNECTION},
#endif
    {0,0}
};

/* inquiry profile table */
const U32 inquiry_profile_tbl[] = 
{
#ifdef __MMI_HFP_SUPPORT__
    SRV_BT_CM_HS_PROFILE_UUID,
#endif

#if defined(__MMI_HFP_SUPPORT__) || defined(__MMI_HF_SUPPORT__)
    SRV_BT_CM_HF_PROFILE_UUID,
#endif

#ifdef __MMI_SPP_SUPPORT__
    SRV_BT_CM_SPP_PROFILE_UUID,
#endif 

#ifdef __MMI_DUN_SUPPORT__
    SRV_BT_CM_DUN_PROFILE_UUID,
#endif 

#ifdef __MMI_OPP_SUPPORT__
    SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID,
#endif 

#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_FTS_SUPPORT__)
    SRV_BT_CM_OBEX_FILE_TRANSFER_UUID,
#endif 

#ifdef __MMI_A2DP_SUPPORT__
    SRV_BT_CM_AUDIO_SINK_UUID,
#endif

#if defined(__MMI_AVRCP_CT_SUPPORT__) || defined(__BT_SPEAKER_SUPPORT__)
    SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID,
#endif

#ifdef __MMI_BPP_SUPPORT__
    SRV_BT_CM_OBEX_BPPS_PROFILE_UUID,
#endif 

#ifdef __MMI_SIMAP_SUPPORT__
    SRV_BT_CM_SIM_ACCESS_PROFILE_UUID,
#endif 

#ifdef __MMI_FAX_SUPPORT__
    SRV_BT_CM_FAX_PROFILE_UUID,
#endif 

#if defined(__MMI_HIDD_SUPPORT__)
    SRV_BT_CM_HID_PROFILE_UUID,
#endif 

#ifdef __MMI_BIP_SUPPORT__
    SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID,
#endif 
#ifdef __MMI_BT_PBAP_CLIENT__
    SRV_BT_CM_OBEX_PBA_PROFILE_UUID,
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
		SRV_BT_CM_HEADSET_AG_SERVICE_UUID,
#endif 
#ifdef __MMI_BT_MAP_CLIENT__
    SRV_BT_CM_MESSAGE_ACCESS_PROFILE_SERVER_UUID,
    SRV_BT_CM_MESSAGE_NOTIF_SERVER_UUID,
#endif

    SRV_BT_CM_MAX_PROFILE_UUID
};

const U32 inq_prof_tbl_len = sizeof(inquiry_profile_tbl) / sizeof(U32);

srv_bt_cm_hdlr_struct srv_bt_cm_handle[SRV_BT_CM_MAX_INSTANCE_NUM];


static void srv_bt_cm_nvram_read_info(void);
#ifdef __MMI_BT_TEMP_VISIBILITY__
void srv_bt_cm_set_temp_visibility_timeout(void);
#endif 
static void srv_bt_cm_free_connection_id(S32 conn_id);
#ifdef __BT_AUTO_DETECT_SUPPORT__
static void srv_bt_cm_check_chip(void);
#endif

/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_bqb_test_flag
 * DESCRIPTION
 *  this function is get currently bqb set
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  MMI_TRUE : currently is BQB set
 *  MMI_FALSE: currently is for normal set
 ******************************************************************************/
MMI_BOOL srv_bt_cm_get_bqb_test_flag(void)
{
	U8 bqb_flag;
	S16 error;
    // in order to pass the first build , we ignore this line. ADD BY GUOQING.REN
    // after the first build passed, we need add a NVRAM LID to instead this value.
    //ReadValue(BT_BQB_TEST, &bqb_flag, DS_BYTE, &error);
	return (MMI_BOOL)bqb_flag;
}

/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_bqb_test_flag
 * DESCRIPTION
 *  this function is set currently bqb set
 * PARAMETERS
 *  bqb_flag
 *  MMI_TRUE : currently is BQB set
 *  MMI_FALSE: currently is for normal set
 *  
 * RETURNS
 * void
 ******************************************************************************/
void srv_bt_cm_set_bqb_test_flag(MMI_BOOL bqb_flag)
{
	U8 bqb = (U8)bqb_flag;
	S16 error;
    
    // in order to pass the first build , we ignore this line. ADD BY GUOQING.REN
    // after the first build passed, we need add a NVRAM LID to instead this value.
    //WriteValue(BT_BQB_TEST, &bqb, DS_BYTE, &error);

	#ifdef __MMI_BT_APPLICATION_BQB__
	{
		kal_bool use_custom_cod = KAL_FALSE;
		U32 cod = (SRV_BT_NETWORKING_MAJOR_SERVICE_MASK | SRV_BT_CAPTURING_MAJOR_SERVICE_MASK | SRV_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK | \
				SRV_BT_AUDIO_MAJOR_SERVICE_MASK| SRV_BT_TELEPHONY_MAJOR_SERVICE_MASK | SRV_BT_PHONE_MAJOR_DEVICE_MASK | SRV_BT_CELLULAR_MINOR_DEVICE_MASK);

		if (bqb_flag)
		{
			use_custom_cod = KAL_TRUE;
			cod |= SRV_BT_RENDERING_MAJOR_SERVICE_MASK;
		}

		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BtCmSrv] srv_bt_cm_set_bqb_test_flag() bqb set = %d", (kal_int8)use_custom_cod);
		Custom_Config_Set_BT_COD(cod, use_custom_cod);
	}
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_power_status
 * DESCRIPTION
 *  This function is to get power status
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_power_status_enum   
 *    SRV_BT_CM_POWER_ON means BT power is ON
 *    SRV_BT_CM_POWER_OFF means BT power is OFF
 *    SRV_BT_CM_POWER_SWITCHING_ON means switching power to be ON now
 *    SRV_BT_CM_POWER_SWITCHING_OFF means switching power to be OFF now 
 *****************************************************************************/
srv_bt_cm_power_status_enum srv_bt_cm_get_power_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_power_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_INIT_ON:
            status = SRV_BT_CM_POWER_OFF;
            break;

        case SRV_BT_CM_STATE_ACTIVATING:
            status = SRV_BT_CM_POWER_SWITCHING_ON;
            break;
            
        case SRV_BT_CM_STATE_DEACTIVATING:
            status = SRV_BT_CM_POWER_SWITCHING_OFF;
            break;
            
        default:
            status = SRV_BT_CM_POWER_ON;
            break;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_POWER_STATUS,
        status);

    return status;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_profile_connecting
 * DESCRIPTION
 *  This function is to check if a profile is connecting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : the profile is connecting
 *  MMI_FALSE : the profile is not connecting
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_profile_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (!g_srv_bt_cm_cntx.existed_conn[i].active))
        {
            result = MMI_TRUE;
            break;
        }
    }

    // in order to pass the first build , we ignore this line. ADD BY GUOQING.REN
    // after the first build passed, we need ask RD not to ref an APP level Trace in SERVICE..
    //TRC_MSG(MMI_BT_G7_SRV_BT_CM_IS_PROFILE_CONNECTING, "[BTSRV] : srv_bt_cm_is_profile_connecting(), conn_id = %d, result = %d")
/*    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_SRV_BT_CM_IS_PROFILE_CONNECTING,
        (result? g_srv_bt_cm_cntx.existed_conn[i].conn_id : 0),
        result);
*/
        return result;
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_profile_connected
 * DESCRIPTION
 *  This function is to check if XXX profile connected
 * PARAMETERS
 *  conn_type       [IN]        to check if conn_type is connected, conn_type is defind in srv_bt_cm_connection_type 
 * RETURNS
 *  MMI_BOOL            TRUE : the profile is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_profile_connected(srv_bt_cm_connection_type conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (g_srv_bt_cm_cntx.existed_conn[i].active) &&
            (srv_bt_cm_get_conn_type(g_srv_bt_cm_cntx.existed_conn[i].profile_id) == conn_type))
        {
            result = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_PROFILE_CONNECTED,
        conn_type,
        result);

    return result;
}

MMI_BOOL srv_bt_cm_is_hf_profile_connected(U32 i)
{
if(((g_srv_bt_cm_cntx.existed_conn[i].profile_id == SRV_BT_CM_HF_PROFILE_UUID) ||
             (g_srv_bt_cm_cntx.existed_conn[i].profile_id == SRV_BT_CM_HFG_PROFILE_UUID) ||
             (g_srv_bt_cm_cntx.existed_conn[i].profile_id == SRV_BT_CM_HS_PROFILE_UUID) ||
             (g_srv_bt_cm_cntx.existed_conn[i].profile_id == SRV_BT_CM_HEADSET_AG_SERVICE_UUID)) &&
            (g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0))
            return MMI_TRUE;
return MMI_FALSE;

}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_activated
 * DESCRIPTION
 *  This function is to check if bt is activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    TRUE : bluetooth is activated
 *              FALSE : bluetooth is not activated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_ACTIVATED);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_ACTIVATED,
        result);

    return result;
}


S32 srv_bt_cm_get_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_VISIBILITY,
        g_srv_bt_cm_cntx.a2dp_prohibit_vis,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag);

    if (g_srv_bt_cm_cntx.a2dp_prohibit_vis)
    {
        return SRV_BT_CM_VISIBILITY_OFF;
    }

    if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_VIS))
    {
        return SRV_BT_CM_VISIBILITY_ON;
    }
#ifdef __MMI_BT_TEMP_VISIBILITY__
    else if (SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS))
    {
        return SRV_BT_CM_VISIBILITY_TEMPORARY_ON;
    }
#endif  // __MMI_BT_TEMP_VISIBILITY__
    else
    {
        return SRV_BT_CM_VISIBILITY_OFF;
    }
}


S32 srv_bt_cm_set_visibility(srv_bt_cm_visibility_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_inquiry_mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_VISIBILITY,
        type,
        g_srv_bt_cm_cntx.state);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        switch (type)
        {
            case SRV_BT_CM_VISIBILITY_ON:
                StopTimer(BT_TEMP_VISIBLE_TIMER);
                page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
                break;

#ifdef __MMI_BT_TEMP_VISIBILITY__
            case SRV_BT_CM_VISIBILITY_TEMPORARY_ON:
                page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
                StartTimer(
                    BT_TEMP_VISIBLE_TIMER,
                    SRV_BT_CM_TEMP_VISIBLE_TIMER_DUR,
                    srv_bt_cm_set_temp_visibility_timeout);
                break;
#endif  // __MMI_BT_TEMP_VISIBILITY__

            case SRV_BT_CM_VISIBILITY_OFF:
                StopTimer(BT_TEMP_VISIBLE_TIMER);
                //page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF_L_OFF;
                break;
        }

        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_VISIBILITY_SETTING);
        srv_bt_cm_write_scanenable_mode_req_hdler(page_inquiry_mode);
        /* will deal with the result in API:
         * srv_bt_cm_write_scanenable_mode_cnf_hdler()
         * 
         * remember the value, if success, then modify the flag,
         * else do not set the flag */
        g_srv_bt_cm_cntx.tmp_visibility_type = (U8)type;
        if (g_srv_bt_cm_cntx.a2dp_prohibit_vis)
        {
            srv_bt_cm_set_a2dp_prohibit_vis(MMI_FALSE);
        }

        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}

#ifdef __MMI_BT_TEMP_VISIBILITY__
void srv_bt_cm_set_temp_visibility_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_TEMP_VISIBILITY_TIMEOUT);

    SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS);
    g_srv_bt_cm_cntx.tmp_visibility_type = 0;
    srv_bt_cm_nvram_write_info(NVRAM_EF_BT_SYS_INFO_LID, (void*)0);
    srv_bt_cm_write_scanenable_mode_req_hdler(BTBM_ADP_P_ON_I_OFF);
}

#endif
#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
void srv_bt_cm_set_limit_visibility_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_limit_discoverable_mode_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_LIMIT_VISIBILITY_TIMEOUT_HDLR);

    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
    para.result = SRV_BT_CM_BTBM_FAILED;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE, (void*)&para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_limit_vis
 * DESCRIPTION
 *  This function is to set limited discoverable mode
 * PARAMETERS
 *  MMI_BOOL        visability, true means to set limit discovery mode, 
 *                              false means to reset limit discovery mode
 *  user_data   [IN]            user data 
 * RETURNS
 *  void            
 *****************************************************************************/
S32 srv_bt_cm_set_limit_vis(MMI_BOOL vis)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_inquiry_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_LIMIT_VIS,
        vis);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
    	srv_bt_cm_state_enum state = g_srv_bt_cm_cntx.state;
        StartTimer(
            BT_CMD_GUARD_TIMER,
            SRV_BT_CM_CMD_TIMER_DUR,
            srv_bt_cm_set_limit_visibility_timeout_hdlr);

        if (vis)
        {
			state=SRV_BT_CM_STATE_SETTING_LIMIT_VISIBILITY;
            SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_LIMIT_VIS);
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_DISALLOW_REQ, NULL, NULL);
        }
        else
        {
        	state=SRV_BT_CM_STATE_RESETTING_LIMIT_VISIBILITY;
            SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_LIMIT_VIS);
            if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_VIS))
            {
                page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
            }
            else
            {
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
            }

            srv_bt_cm_write_scanenable_mode_req_hdler(page_inquiry_mode);
        }

		SRV_BT_CM_STATE_TRANS(state);
        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_limit_vis
 * DESCRIPTION
 *  This function is to check the limited visibility setting of bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL            TRUE : the device is limited visible
 *                      FALSE : the device is not limited visible
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_limit_vis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_LIMIT_VIS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_LIMIT_VIS,
        result);

    return result;
}
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_auth
 * DESCRIPTION
 *  This function is to check the authentication setting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : the authentication is on
 *                  FALSE : the authentication is off
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_authentication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_AUTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_AUTHENTICATION,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_audio_path_to_headset
 * DESCRIPTION
 *  This function is to check if the audio path is set to headset
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : the audio path is set to headphone
 *                  FALSE : the audio path is leave in phone
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_audio_path_to_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    {
        U32* mode = srv_bthf_read_config(BTHF_CFG_AUDIO_PATH);

        if (*mode == BTHF_AUD_REMOTE)
        {
            result = MMI_TRUE;
        }
    }
#endif /* __MMI_HFP_SUPPORT__ */

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_AUDIO_PATH_TO_HEADSET,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_incall_aud_swap2bt
 * DESCRIPTION
 *  This function is to is incall and audio path is swap to bluetooth device
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    TRUE : the audio path is swap to bluetooth device
 *              FALSE : the audio path is not swap to bluetooth device
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_incall_aud_swap2bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_INCALL_AUD_SWAP2BT,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_audio_link_on
 * DESCRIPTION
 *  This function is to if headset audio link is connected
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL            TRUE : headset audio link is connected
 *                      FALSE : headset audio link is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_audio_link_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; i++)
    {
        if (srv_bt_cm_is_hf_profile_connected(i) &&
            (g_srv_bt_cm_cntx.existed_conn[i].audio_on))
        {
            result = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_AUDIO_LINK_ON,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_dev_conn_active
 * DESCRIPTION
 *  This function is to check if certain device is connected
 * PARAMETERS
 *  dev_addr:    [IN]    device address  
 * RETURNS
 *  MMI_BOOL    TRUE : the device is connected
 *              FASLE : the device is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_dev_conn_active(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        for (j = 0; j < SRV_BT_CM_MAX_CONNECTION; ++j)
        {
            if ((g_srv_bt_cm_cntx.existed_conn[j].conn_id > 0) &&
                (g_srv_bt_cm_cntx.existed_conn[j].index_of_dev_list == i) &&
                (g_srv_bt_cm_cntx.existed_conn[j].active))
            {
                result = MMI_TRUE;
                break;
            }
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_DEV_CONN_ACTIVE,
        result,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_simap_activate
 * DESCRIPTION
 *  This function is to check if SIMAP is activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL            TRUE : SIMAP is activated
                        FALSE : SIMAP is not activated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_simap_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
#ifdef __MMI_SIMAP_SUPPORT__
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if (SRV_BT_CM_SIM_ACCESS_PROFILE_UUID == g_srv_bt_cm_profile_tbl[i].profile_id)
        {
            if (!(g_srv_bt_cm_cntx.deactivate_flag & g_srv_bt_cm_profile_tbl[i].deactivate_flag))
            {
                result = MMI_TRUE;
            }
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_SIMAP_ACTIVATE,
        result);

#endif //__MMI_SIMAP_SUPPORT__

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_host_dev_security_level
 * DESCRIPTION
 *  This function is to get host device security level
 * PARAMETERS
 *  void
 * RETURNS
 *  U8      host device security level
 *****************************************************************************/
U8 srv_bt_cm_get_host_dev_security_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_HOST_DEV_SECURITY_LEVEL,
        g_srv_bt_cm_cntx.host_security_level);

    return g_srv_bt_cm_cntx.host_security_level;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_discoverable_mode
 * DESCRIPTION
 *  This function is to set discoverable mode and invoke srv_bt_cm_write_scanenable_mode_req_hdler
 * PARAMETERS
 *  discoverable_mode     [IN]            discoverable mode value
 * RETURNS
 *  MMI_BOOL        TRUE : set discoverable mode successfully
 *                  FALSE : otherwise
 *****************************************************************************/
S32 srv_bt_cm_set_discoverable_mode(U32 discoverable_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_DISCOVERABLE_MODE,
        discoverable_mode);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        if (discoverable_mode <= BTBM_ADP_P_ON_I_ON)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DISCOVERABLE_MODE_SETTING);
            srv_bt_cm_write_scanenable_mode_req_hdler((U8)discoverable_mode);
            result = MMI_TRUE;
        }
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_host_dev_name
 * DESCRIPTION
 *  This function is to set host device name and invoke srv_bt_cm_set_local_name_req_hdler
 * PARAMETERS
 *  name        [IN]             name
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_cm_set_host_dev_name(U8* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 name_len = 0;
    srv_bt_cm_set_name_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_HOST_DEV_NAME,
        name);

    name_len = strlen((const char*)name);
    if (name_len > (SRV_BT_CM_BD_FNAME_LEN - 2))
    {
        name_len = SRV_BT_CM_BD_FNAME_LEN - 2;
        name[SRV_BT_CM_BD_FNAME_LEN - 1] = '\0';
        name[SRV_BT_CM_BD_FNAME_LEN - 2] = '\0';
    }

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        srv_bt_cm_set_local_name_req_hdler((U8)name_len, name);
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_HOST_NAME_SETTING);
        /* store the name pointer before receiving local name setting cfm
         * deal with the result in srv_bt_cm_set_local_name_cnf_hdler() */
        g_srv_bt_cm_cntx.host_name_setting = (U8*)OslMalloc(name_len + 2);
        memcpy(
            g_srv_bt_cm_cntx.host_name_setting,
            name,
            name_len + 2);

        return SRV_BT_CM_RESULT_SUCCESS;
    }
    else
    {
        memcpy(
            g_srv_bt_cm_cntx.host_dev.name,
            name,
            name_len + 2);
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_SYS_INFO_LID, (void*)0);

        para.result = SRV_BT_CM_RESULT_SUCCESS;
        srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_NAME, (void*)&para);
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_dev_property_check
 * DESCRIPTION
 *  This function is to check if device is matched certain property
 * PARAMETERS
 *  srv_bt_cm_bt_addr       [IN]        BT device address    
 *  prop                    [IN]        device property, refer to srv_bt_cm_dev_property_enum
 * RETURNS
 *  MMI_BOOL  MMI_TRUE meaans matched, MMI_FALSE means not matched
 *****************************************************************************/
MMI_BOOL srv_bt_cm_dev_property_check(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_property_enum prop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    const srv_bt_cm_dev_struct* dev_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get trust device info */
    dev_p = srv_bt_cm_get_dev_info_by_addr(
        (const srv_bt_cm_bt_addr*)dev_addr,
        SRV_BT_CM_ALL_DEV);

    if (dev_p)
    {
        switch (prop)
        {   
            case SRV_BT_CM_DEV_PROPERTY_AUTHORIZE:
                if (dev_p->attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_AUTHORIZE &&
                    !(dev_p->attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK))
                {
                    result = MMI_TRUE;
                }
                break;

            case SRV_BT_CM_DEV_PROPERTY_BLOCK:
                if (dev_p->attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK)
                {
                    result = MMI_TRUE;
                }
                break;

            case SRV_BT_CM_DEV_PROPERTY_PAIR:
                if (srv_bt_cm_get_dev_info_by_addr(
                    (const srv_bt_cm_bt_addr*)dev_addr,
                    SRV_BT_CM_PAIRED_DEV))
                {
                    result = MMI_TRUE;
                }
                break;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_PROPERTY_CHECK,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap,
        prop,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_default_dev_addr
 * DESCRIPTION
 *  This function is to get default device address, 
 *  NULL means default device not existed
 * PARAMETERS
 *  dev_type    [IN]    default device type
 * RETURNS
 *  srv_bt_cm_bt_addr        default device address pointer, 
 *                           NULL means default device not existed
 *****************************************************************************/
srv_bt_cm_bt_addr* srv_bt_cm_get_default_dev_addr(srv_bt_cm_default_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr* result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dev_type)
    {
#ifdef __MMI_HFP_SUPPORT__
        case SRV_BT_CM_DEFAULT_DEV_TYPE_HS:
            result = (srv_bt_cm_bt_addr*)srv_bthf_read_config(BTHF_CFG_DEF_DEVICE);
            break;
#endif /* __MMI_HFP_SUPPORT__ */

#if defined(__MMI_HIDD_SUPPORT__)
        case SRV_BT_CM_DEFAULT_DEV_TYPE_HID:
            if (g_srv_bt_cm_cntx.idx_of_last_hid_dev < g_srv_bt_cm_cntx.paired_dev_num)
            {
                U32 idx;

                idx = g_srv_bt_cm_cntx.paired_idx_list[g_srv_bt_cm_cntx.idx_of_last_hid_dev];
                result = &(g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr);
            }
            break;
#endif  // __MMI_HIDD_SUPPORT__

        default:
            break;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEFAULT_DEV_ADDR,
        result);

    return result;
}

#ifndef __EMPTY_MMI__
#if MMI_MAX_SIM_NUM > 1
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_prefer_sim
 * DESCRIPTION
 *  This function is to get prefer SIM setting binding to specific device.
 * PARAMETERS
 *  dev_addr    [IN]    BD address of corresponding device
 * RETURNS
 *  mmi_sim_enum        related prefer SIM setting
 *****************************************************************************/
mmi_sim_enum srv_bt_cm_get_prefer_sim(const srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev;
    U32 index;
    U8 sim_option, result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info_by_addr(dev_addr, SRV_BT_CM_PAIRED_DEV);

    if (!dev)
        return MMI_SIM1;

    index = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_PAIRED_DEV);

    /* we use high 4 bits of attribute to store sim information */
    sim_option = (dev->attribute & 0xf0) >> 4;

    if (!sim_option)
        result = MMI_SIM1;
    else
        result = sim_option;

    if (result != sim_option)
    {
        dev->attribute = ((dev->attribute & 0x0f) | (result << 4));
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void *)index);
    }

    return (mmi_sim_enum)result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_prefer_sim
 * DESCRIPTION
 *  This function is to set prefer SIM setting binding to specific device.
 * PARAMETERS
 *  dev_addr    [IN]    BD address of corresponding device
 *  sim         [IN]    related prefer SIM setting
 * RETURNS
 *  void        no need to care about executed result for caller.
 *****************************************************************************/
void srv_bt_cm_set_prefer_sim(const srv_bt_cm_bt_addr *dev_addr, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev;
    U32 index;
    U8 sim_option;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info_by_addr(dev_addr, SRV_BT_CM_PAIRED_DEV);

    if (!dev) return;

    if (!(sim & MMI_SIM_ALL))
        return;

    /* we use high 4 bits to store sim information */
    sim_option = (dev->attribute & 0xf0) >> 4;

    if (sim_option != sim)
    {
        index = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_PAIRED_DEV);
        sim_option = sim;
        dev->attribute = ((dev->attribute & 0x0f) | (sim_option << 4));
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void *)index);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_binding_sim
 * DESCRIPTION
 *  This function is to get binding SIM corresponding to specific device. 
 *  result depends on both prefer SIM setting and current SIM available status.
 * PARAMETERS
 *  dev_addr    [IN]    BD address of corresponding device
 * RETURNS
 *  mmi_sim_enum        related prefer SIM setting
 *****************************************************************************/
mmi_sim_enum srv_bt_cm_get_binding_sim(const srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_option, sim_avail;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_option = srv_bt_cm_get_prefer_sim(dev_addr);
    sim_avail = (mmi_sim_enum)srv_sim_ctrl_get_one_available_sim();

    if (srv_sim_ctrl_is_available(sim_option) ||
        sim_avail == MMI_SIM_NONE)
        return sim_option;

    return sim_avail;
}
#endif
#endif /* __EMPTY_MMI__ */

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_check_dev_profile_support_status
 * DESCRIPTION
 *  This function is to check if a service is support or not on a certain device
 * PARAMETERS
 *  addr           [IN]    address of the device
 *  service id      [IN]    the service to find
 * RETURNS
 *  MMI_BOOL    TRUE : the service is supported
                        FALSE : the service is not supported
 *****************************************************************************/
MMI_BOOL srv_bt_cm_check_dev_profile_support_status(srv_bt_cm_bt_addr* dev_addr, U32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL result = MMI_FALSE;
    const srv_bt_cm_dev_struct* dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (service_id != 0)
    {
        dev_p = srv_bt_cm_get_dev_info_by_addr(
            (const srv_bt_cm_bt_addr*)dev_addr,
            SRV_BT_CM_ALL_DEV);
        if (dev_p)
        {
            for (i = 0; i < dev_p->service_list_num; i++)
            {
                if (dev_p->service_list[i] == service_id)
                {
                    result = MMI_TRUE;
                    break;
                }
            }
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_CHECK_DEV_PROFILE_SUPPORT_STATUS,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap,
        service_id,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_default_dev
 * DESCRIPTION
 *  This function is to set default device
 * PARAMETERS
 *  dev_type    [IN]    default device type
 *  dev_addr    [IN]    device address
 * RETURNS
 *  srv_bt_cm_result_codes_enum        the result of setting default device
 *****************************************************************************/
srv_bt_cm_result_codes_enum srv_bt_cm_set_default_dev(srv_bt_cm_default_dev_type_enum dev_type, srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_result_codes_enum result = SRV_BT_CM_RESULT_FAILED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_DEFAULT_DEV,
        dev_type,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap);

    switch (dev_type)
    {
#ifdef __MMI_HFP_SUPPORT__
        case SRV_BT_CM_DEFAULT_DEV_TYPE_HS:
        {
            BTHFResult tmpresult = srv_bthf_save_config(BTHF_CFG_DEF_DEVICE, dev_addr);
            if (tmpresult == BTHF_RESULT_SUCC)
            {
                result = SRV_BT_CM_RESULT_SUCCESS;
            }
            break;
        }
#endif /* __MMI_HFP_SUPPORT__ */

#if defined(__MMI_HIDD_SUPPORT__)
        case SRV_BT_CM_DEFAULT_DEV_TYPE_HID:
        {
            U32 i;
			i = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_ALL_DEV);
			kal_prompt_trace(MOD_MMI, "srv_bt_cm_set_default_dev i= %d", i);
			if(i < SRV_BT_CM_MAX_DEVICE_LIST)
			{
				g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute |= SRV_BT_CM_DEVICE_ATTRIBUTE_HIDD;
				kal_prompt_trace(MOD_MMI, "srv_bt_cm_set_default_dev g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute= 0x%x",g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute);
				srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)i);
                result = SRV_BT_CM_RESULT_SUCCESS;
			}
            i = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_PAIRED_DEV);
            if (i < g_srv_bt_cm_cntx.paired_dev_num)
            {
                g_srv_bt_cm_cntx.idx_of_last_hid_dev = i;
                srv_bt_cm_nvram_write_info(NVRAM_EF_BT_INFO_LID, (void*)0);
                result = SRV_BT_CM_RESULT_SUCCESS;
            }
            break;
        }
#endif  // __MMI_HIDD_SUPPORT__

        default:
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_dev_cod
 * DESCRIPTION
 *  This function is to get device cod
 * PARAMETERS
 *  dev_addr         [IN]   device address
 * RETURNS
 *  U32         class of device
 *****************************************************************************/
U32 srv_bt_cm_get_dev_cod(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 device_cod = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        device_cod = g_srv_bt_cm_cntx.dev_list[i].dev_info.cod;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_COD,
        i,
        device_cod);

    return device_cod;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_dev_cod
 * DESCRIPTION
 *  This function is to set device cod and write into nvram
 * PARAMETERS
 *  srv_bt_cm_bt_addr   [IN]        device address
 *  cod                 [IN]        class of device
 * RETURNS
 *  srv_bt_cm_result_codes_enum         
 *****************************************************************************/
S32 srv_bt_cm_set_dev_cod(srv_bt_cm_bt_addr* dev_addr, U32 cod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    srv_bt_cm_result_codes_enum result = SRV_BT_CM_RESULT_DEV_NOT_FOUND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        g_srv_bt_cm_cntx.dev_list[i].dev_info.cod = cod;
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)i);
        result = SRV_BT_CM_RESULT_SUCCESS;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_DEV_COD,
        i,
        cod);

    return result;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_dev_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr:    [IN]
 *  name_p:      [IN]
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_bt_cm_set_dev_name(srv_bt_cm_bt_addr* dev_addr, U8* name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_DEV_NAME,
        name_p);

    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        srv_bt_cm_copy_n_utf8_chars(
            g_srv_bt_cm_cntx.dev_list[i].dev_info.name,
            SRV_BT_CM_BD_FNAME_LEN,
            name_p,
            (SRV_BT_CM_BD_UCS2_NAME_LEN - 1));
        g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute |= SRV_BT_CM_DEVICE_ATTRIBUTE_USER_DEFINED_NAME;
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)i);
        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_dev_name
 * DESCRIPTION
 *  This function is to get the device name
 * PARAMETERS
 *  dev_addr                [IN]        bluetooth address
 *  max_name_len            [IN]        allowed max length of name_p
 *  name_p                  [OUT]       name buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_get_dev_name(srv_bt_cm_bt_addr* dev_addr, U32 max_name_len, U8* name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_dev_info_by_addr(
        (const srv_bt_cm_bt_addr*)dev_addr,
        SRV_BT_CM_ALL_DEV);;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_p[0] = 0;
    if (dev_p)
    {
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_GET_DEV_NAME,
            max_name_len,
            mmi_chset_utf8_strlen((kal_uint8*)dev_p->name));
        srv_bt_cm_copy_n_utf8_chars(
            name_p,
            (U16)max_name_len,
            (U8*)dev_p->name,
            (U8)(SRV_BT_CM_BD_FNAME_LEN / 3));
    }
}


void srv_bt_cm_get_dev_ucs2_name(const srv_bt_cm_bt_addr* dev_addr, U32 max_name_len, WCHAR* name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info_by_addr(
        dev_addr,
        SRV_BT_CM_ALL_DEV);

    name_p[0] = 0;
    if (dev_info)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)name_p,
            (max_name_len * 2),
            (kal_uint8*)dev_info->name);
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_UCS2_NAME,
        name_p[0]);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_read_remote_dev_name
 * DESCRIPTION
 *  this function is to read the remote device name again
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_bt_cm_read_remote_dev_name(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_READ_REMOTE_DEV_NAME,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff));

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_IDLE:
            i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
            if (i < SRV_BT_CM_MAX_DEVICE_LIST)
            {
                srv_bt_cm_read_remote_name_req_hdler(dev_addr);
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_READING_REMOTE_DEV_NAME);
                return SRV_BT_CM_RESULT_SUCCESS;
            }
            
            return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_headset_connected
 * DESCRIPTION
 *  This function is to check if headset is connected
 * PARAMETERS
 *  index_of_paried_list    [IN]    the device index of the headset
 * RETURNS
 *  MMI_BOOL        TRUE : headset is connected
                    FALSE : headset is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_headset_connected(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, profile_id, index;
    MMI_BOOL result = MMI_FALSE;
    srv_bt_cm_connect_struct* existed_conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_ALL_DEV);
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; i++)
    {
        existed_conn_p = &g_srv_bt_cm_cntx.existed_conn[i];
        profile_id = existed_conn_p->profile_id;
        if ((existed_conn_p->conn_id > 0) &&
            (existed_conn_p->active) &&
            (existed_conn_p->index_of_dev_list == index) &&
            ((profile_id == SRV_BT_CM_HF_PROFILE_UUID) ||
             (profile_id == SRV_BT_CM_HFG_PROFILE_UUID) ||
             (profile_id == SRV_BT_CM_HS_PROFILE_UUID) ||
             (profile_id == SRV_BT_CM_HEADSET_AG_SERVICE_UUID) ||
             (profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)))
        {
            result = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_HEADSET_CONNECTED,
        index,
        result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_activate_cnf_hdler
 * DESCRIPTION
 *  This function is to handle activate confirm
 * PARAMETERS
 *  profile_id      [IN]            profile id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_activate_cnf_hdler(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ACTIVATE_CNF_HDLER,
        profile_id,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if (profile_id == g_srv_bt_cm_profile_tbl[i].profile_id)
        {
            srv_bt_cm_reset_deactivate_flag((U32)g_srv_bt_cm_profile_tbl[i].deactivate_flag);
            break;
        }
    }
	
#ifdef __BCM_SUPPORT__
	cmd_hdlr_bt_profile_act_cnf(KAL_TRUE,KAL_TRUE,profile_id); 	
#endif

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_ACTIVATING:
            if (srv_bt_cm_is_all_supported_profiles_activated(
                #ifdef __MMI_TELEPHONY_SUPPORT__
                    (MMI_BOOL)(srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
                #else
                    (MMI_BOOL)MMI_TRUE
                #endif
            ))
            {
            
              
                SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_ACTIVATED);
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

        /* bt already on in flight mode, then change to normal mode */
        case SRV_BT_CM_STATE_ACTIVATING_PROFILES:
            if (srv_bt_cm_is_all_supported_profiles_activated(MMI_FALSE))
            {
                /* if all profiles activated, change state to SRV_BT_CM_STATE_IDLE
                 * and invoke activate function */
                U32 state,tmpstate;
                SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_READY);
                if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
                {
					state=g_srv_bt_cm_cntx.tmp_state;
                    tmpstate=SRV_BT_CM_STATE_INIT_ON;
                }
                else
                {
                    state=SRV_BT_CM_STATE_IDLE;
                    tmpstate=SRV_BT_CM_STATE_INIT_ON;
                }
				SRV_BT_CM_STATE_TRANS(state);
				SRV_BT_CM_TMP_STATE_TRANS(tmpstate);
                srv_bt_cm_nvram_write_info(NVRAM_EF_BT_INFO_LID, (void*)0);
                {
                    srv_bt_cm_activate_struct para;
                    para.result = MMI_TRUE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_ACTIVATE, (void*)&para);
                }
            }
            break;

        default:
#ifdef __MMI_SIMAP_SUPPORT__
            if (profile_id == SRV_BT_CM_SIM_ACCESS_PROFILE_UUID)
            {
                srv_bt_cm_set_simap_struct para;
                para.result = MMI_TRUE;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_SIMAP, (void*)&para);
            }
#endif //__MMI_SIMAP_SUPPORT__
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_deactivate_cnf_hdler
 * DESCRIPTION
 *  This function is to handle deactive confirm
 * PARAMETERS
 *  profile_id      [IN]            profile id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_deactivate_cnf_hdler(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEACTIVATE_CNF_HDLER,
        profile_id,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);
    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if (profile_id == (g_srv_bt_cm_profile_tbl[i].profile_id))
        {
            srv_bt_cm_set_deactivate_flag((U32)g_srv_bt_cm_profile_tbl[i].deactivate_flag);
            break;
        }
    }
#ifdef __BCM_SUPPORT__
	cmd_hdlr_bt_profile_act_cnf(KAL_TRUE,KAL_FALSE,profile_id); 	
#endif

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_DEACTIVATING:
            /* check if all services are deactivated */
            if (srv_bt_cm_is_all_supported_profiles_deactivated())
            {
                SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_ACTIVATED);
                srv_bt_cm_antenna_off();
            }
            break;

//         case SRV_BT_CM_STATE_DEACTIVATING_SIMAP:
//             /* simap deactivate */
//             /* -> allow acl link establishment */
//             srv_bt_cm_allow_acl_link_establishment_req_hdler();
//             break;
            
        default:
#ifdef __MMI_SIMAP_SUPPORT__
            if (profile_id == SRV_BT_CM_SIM_ACCESS_PROFILE_UUID)
            {
                srv_bt_cm_set_simap_struct para;
                para.result = MMI_TRUE;
                srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_SIMAP, (void*)&para);
            }
#endif //__MMI_SIMAP_SUPPORT__
            break;
    }
}


static S32 srv_bt_cm_allocate_conn_id_int(const srv_bt_cm_bt_addr* dev_addr, U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if (g_srv_bt_cm_cntx.existed_conn[i].conn_id == 0)
        {
            g_srv_bt_cm_cntx.existed_conn[i].index_of_dev_list = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_ALL_DEV);
            if (g_srv_bt_cm_cntx.existed_conn[i].index_of_dev_list < SRV_BT_CM_MAX_DEVICE_LIST)
            {
                MMI_TRACE(
                    MMI_CONN_TRC_G7_BT,
                    SRV_BT_CM_ALLOCATE_CONN_ID_INT,
                    (i + 1));
                g_srv_bt_cm_cntx.existed_conn[i].profile_id = profile_id;
                return (g_srv_bt_cm_cntx.existed_conn[i].conn_id = i + 1);
            }
        }
    }

    return -1;
}

// S32 srv_bt_cm_get_connection_index(S32 conn_id)
// {
//     if (conn_id > 0 && conn_id <= SRV_BT_CM_MAX_CONNECTION)
//     {
//         return conn_id - 1;
//     }
//     return -1;
// }


static void srv_bt_cm_free_connection_id(S32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_FREE_CONNECTION_ID,
        conn_id);

    if (conn_id > 0 && conn_id <= SRV_BT_CM_MAX_CONNECTION)
    {
        memset(
            &g_srv_bt_cm_cntx.existed_conn[conn_id - 1],
            0,
            sizeof(srv_bt_cm_connect_struct));
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_start_conn
 * DESCRIPTION
 *  This function is to process connect request
 * PARAMETERS
 *  in_out    :    [IN]    MMI_TRUE: incoming connection, MMI_FALSE: outgong connection
 *  profile_id:    [IN]
 *  dev_addr  :    [IN]
 *  dev_name  :    [IN]
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_bt_cm_start_conn(MMI_BOOL in_out, U32 profile_id, srv_bt_cm_bt_addr* dev_addr, CHAR* dev_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 conn_id = -1;
    srv_bt_cm_dev_struct dev;
    const srv_bt_cm_dev_struct* dev_info_p = srv_bt_cm_get_dev_info_by_addr(
        (const srv_bt_cm_bt_addr*)dev_addr,
        SRV_BT_CM_ALL_DEV);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_DIALER_SUPPORT__
	if( srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, dev_addr) ||
		srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_MAPC_CONNECTION, dev_addr) ||
		srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HSP_CONNECTION, dev_addr) ||
		srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr)
	)
	{
		if( !srv_bt_cm_is_dev_conn_active(dev_addr))
		{
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"return -1");
			return -1;
		}
	}
#endif
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_START_CONN,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        in_out,
        profile_id,
        dev_name,
        g_srv_bt_cm_cntx.state);

    if (dev_info_p)
    {
        memcpy(
            &dev,
            dev_info_p,
            sizeof(srv_bt_cm_dev_struct));
    }
    else
    {
        memset(&dev, 0, sizeof(srv_bt_cm_dev_struct));
	srv_bt_cm_copy_addr(&dev.bd_addr,dev_addr);
    }

    if (dev_name)
    {
        srv_bt_cm_copy_n_utf8_chars(
            dev.name,
            SRV_BT_CM_BD_FNAME_LEN,
            (U8*)dev_name,
            (SRV_BT_CM_BD_UCS2_NAME_LEN - 1));
    }
    srv_bt_cm_dev_add_int((const srv_bt_cm_dev_struct*)&dev, SRV_BT_CM_RECENT_USED_DEV);
#ifndef __BT_SPEAKER_SUPPORT__
#ifdef __MMI_BT_CM_CONNECT_EXCLUDE_A2DP__
    if ((profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID) ||
        (profile_id == SRV_BT_CM_AV_REMOTE_CONTROL_UUID) ||
        (profile_id == SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID))
    {
        if (srv_bt_cm_get_paired_dev_num() >= SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
            !srv_bt_cm_get_dev_info_by_addr(dev_addr, SRV_BT_CM_PAIRED_DEV))
        {
            return -1;
        }

        conn_id = srv_bt_cm_allocate_conn_id_int(dev_addr, profile_id);
        return conn_id;
    }
#endif  // __MMI_BT_CM_CONNECT_EXCLUDE_A2DP__
#endif
    if (!in_out)                 // outgoing connection
    {
        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_IDLE)
        {
            conn_id = srv_bt_cm_allocate_conn_id_int(dev_addr, profile_id);
            if (conn_id > 0)
            {
                i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
                srv_bt_cm_set_action_index(i);
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_CONNECTING);
            }
        }
    }
    else                        // incomming connection
    {
        srv_bt_cm_state_enum bth_state;

        bth_state = srv_bt_cm_get_state();
        if (bth_state == SRV_BT_CM_STATE_INIT_ON ||
            bth_state == SRV_BT_CM_STATE_ACTIVATING ||
            bth_state == SRV_BT_CM_STATE_DEACTIVATING ||
            bth_state == SRV_BT_CM_STATE_PASSKEY_IND ||
            bth_state == SRV_BT_CM_STATE_PASSKEY_RES ||
            bth_state == SRV_BT_CM_STATE_INQUIRING ||
            bth_state == SRV_BT_CM_STATE_INQUIR_RES_IND ||
            bth_state == SRV_BT_CM_STATE_DEBONDING ||
            bth_state == SRV_BT_CM_STATE_DELETING ||
            bth_state == SRV_BT_CM_STATE_DELETING_ALL ||
            bth_state == SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION ||
            bth_state == SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION ||
            bth_state == SRV_BT_CM_STATE_BONDING ||
            bth_state == SRV_BT_CM_STATE_SDC_SEARCHING ||
            bth_state == SRV_BT_CM_STATE_SDC_REFRESHING ||
            bth_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM ||
            bth_state == SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP ||
            bth_state == SRV_BT_CM_STATE_CONNECTING ||
            bth_state == SRV_BT_CM_STATE_DISCONNECTING ||
            bth_state == SRV_BT_CM_STATE_PASSKEY_NOTIFY ||
            bth_state == SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL
        #ifdef __MMI_TELEPHONY_SUPPORT__
            || srv_mode_switch_is_switching()
        #endif
        )
        {
            /* reject the connect accept confirm */
            //return conn_id;
        }
        else
        {
            conn_id = srv_bt_cm_allocate_conn_id_int(dev_addr, profile_id);
            if (conn_id > 0)
            {
                i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
                srv_bt_cm_push_conn_cnf_stack(profile_id, conn_id);
                if (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND)
                {
                    if (g_srv_bt_cm_cntx.state > SRV_BT_CM_STATE_IDLE)
                    {
                        SRV_BT_CM_TMP_STATE_TRANS(g_srv_bt_cm_cntx.state);
                    }
                    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND);
                }
            }
        }
    }

    return conn_id;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_connect_ind
 * DESCRIPTION
 *  this function is to handle connect indication
 * PARAMETERS
 *  conn_id:    [IN]    connection ID
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_bt_cm_connect_ind(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 j;
    srv_bt_cm_conn_res_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_CONNECT_IND,
        g_srv_bt_cm_cntx.state,
        conn_id);

    if (conn_id == 0 || conn_id > SRV_BT_CM_MAX_CONNECTION)
    {
        return;
    }

    srv_bt_cm_clear_specific_conn_cnf_stack(conn_id);
    j = g_srv_bt_cm_cntx.existed_conn[conn_id - 1].index_of_dev_list;
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_DELETING:
        case SRV_BT_CM_STATE_DEBONDING:
            if (srv_bt_cm_get_action_item_index() == j)
            {
                return;
            }
            break;

        case SRV_BT_CM_STATE_DELETING_ALL:
            return;

        case SRV_BT_CM_STATE_CONNECTING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            break;

        case SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND:
            if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
            {
                SRV_BT_CM_STATE_TRANS(g_srv_bt_cm_cntx.tmp_state);
                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
            }
            else
            {
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            }
            break;
    }

    /* check if already in existed conn list */
    /* if yes, udpate it */
    /* if not, add it */
    if (!g_srv_bt_cm_cntx.existed_conn[conn_id - 1].active)
    {
        g_srv_bt_cm_cntx.existed_conn[conn_id - 1].active = MMI_TRUE;
    }

#ifdef __MMI_A2DP_SUPPORT__
    if (g_srv_bt_cm_cntx.existed_conn[conn_id - 1].profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
    {
        /* to disable the visibility */
        /* to avoid remote devie to inquiry us while a2dp is active and to impact the audio quality */
        if (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_DEACTIVATING)
        {
            if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_VIS) || SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS))
            {
                srv_bt_cm_set_a2dp_prohibit_vis(MMI_TRUE);

#ifdef __MMI_BT_TEMP_VISIBILITY__
                /* if it is tempt visibility, set it as off state, and don't recover it after a2dp disconnect */
                if (SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS))
                {
                    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS);
                }
#endif  // __MMI_BT_TEMP_VISIBILITY__

                srv_bt_cm_write_scanenable_mode_req_hdler(BTBM_ADP_P_ON_I_OFF);
            }
        }
    }
#endif  // __MMI_A2DP_SUPPORT__
    para.conn_id = conn_id;
    para.dev_addr = &(g_srv_bt_cm_cntx.dev_list[j].dev_info.bd_addr);
    para.profile_id = g_srv_bt_cm_cntx.existed_conn[conn_id - 1].profile_id;
    para.result = SRV_BT_CM_BTBM_SUCCESS;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_CONNECT_RES, (void*)&para);
}


/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_stop_conn
 * DESCRIPTION
 *  This function is to handle disconnection indication
 * PARAMETERS
 *  conn_id:     [IN]     conneciton id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_stop_conn(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i,state;
    srv_bt_cm_disconnect_ind_struct *para1;
    srv_bt_cm_release_all_struct *para2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_STOP_CONN,
        conn_id);

    if (conn_id == 0 || conn_id > SRV_BT_CM_MAX_CONNECTION)
    {
        return;
    }

#ifdef __MMI_A2DP_SUPPORT__
    if (g_srv_bt_cm_cntx.existed_conn[conn_id - 1].profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
    {
        /* to active the visibility while a2dp_prohibit_vis is TRUE */
        if (g_srv_bt_cm_cntx.a2dp_prohibit_vis)
        {
            srv_bt_cm_set_a2dp_prohibit_vis(MMI_FALSE);

            /* don't recover temp visibility */
            if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_VIS))
            {
                if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_DEACTIVATING)
                {
                    srv_bt_cm_set_visibility_struct para3;
                    //srv_bt_cm_nvram_write_info(NVRAM_EF_BT_SYS_INFO_LID, (void*)0);
                    para3.result = MMI_TRUE;
                    para3.is_from_mmi = MMI_FALSE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_VISIBILITY, (void*)&para3);
                }
                else
                {
                    srv_bt_cm_write_scanenable_mode_req_hdler(BTBM_ADP_P_ON_I_ON);
                }
            }
        }
    }
#endif  // __MMI_A2DP_SUPPORT__

    para1 = (srv_bt_cm_disconnect_ind_struct *)OslMalloc(sizeof(*para1));

    i = g_srv_bt_cm_cntx.existed_conn[conn_id - 1].index_of_dev_list;
    para1->dev_addr = &g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr;
    para1->profile_id = g_srv_bt_cm_cntx.existed_conn[conn_id - 1].profile_id;
    if ((g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION ||
         g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION ||
         g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_DEACTIVATING ||
         g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_DISCONNECTING) &&
         g_srv_bt_cm_cntx.disconnect_con_id == conn_id)
    {
        para1->passive = MMI_FALSE;
    }
    else
    {
        para1->passive = MMI_TRUE;
    }

    if (g_srv_bt_cm_cntx.existed_conn[conn_id - 1].audio_on)
    {
        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);
    }
    srv_bt_cm_free_connection_id(conn_id);
    srv_bt_cm_clear_specific_conn_cnf_stack(conn_id);

    srv_bt_cm_post_notify(SRV_BT_CM_EVENT_DISCONNECT_IND, para1);

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND:
            if (srv_bt_cm_pop_conn_cnf_stack() == NULL)
            {
                if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
                {
                    state=g_srv_bt_cm_cntx.tmp_state;
                }
                else
                {
                    state=SRV_BT_CM_STATE_IDLE;
                }
                SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
				SRV_BT_CM_STATE_TRANS(state);
            }
            break;

        case SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION:
            if (g_srv_bt_cm_cntx.disconnect_con_id != conn_id)
            {
                break;
            }

            if (srv_bt_cm_release_all_conn() != SRV_BT_CM_RESULT_SUCCESS)
            {
                StopTimer(BT_RELEASE_ALL_CON_GUARD_TIMER);
                if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
                {
                    state=g_srv_bt_cm_cntx.tmp_state;
                    SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
                }
                else
                {
                    state=SRV_BT_CM_STATE_IDLE;
                }
                 SRV_BT_CM_STATE_TRANS(state);
                /* all connections are released */
                para2 = (srv_bt_cm_release_all_struct *)OslMalloc(sizeof(*para2));
                para2->dev_addr = NULL;
                para2->result = MMI_TRUE;
                srv_bt_cm_post_notify(SRV_BT_CM_EVENT_RELEASE_ALL_CONN, para2);
            }
            break;

        case SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION:
            if (g_srv_bt_cm_cntx.disconnect_con_id != conn_id)
            {
                break;
            }

            if (srv_bt_cm_release_dev_conn(&(g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.action_index].dev_info.bd_addr))
                != SRV_BT_CM_RESULT_SUCCESS)
            {
                if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
                {
                    state=g_srv_bt_cm_cntx.tmp_state;
                    SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
                }
                else
                {
                    state=SRV_BT_CM_STATE_IDLE;
                }
                 SRV_BT_CM_STATE_TRANS(state);
                /* all connections are released */
                para2 = (srv_bt_cm_release_all_struct *)OslMalloc(sizeof(*para2));
                para2->dev_addr = &(g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.action_index].dev_info.bd_addr);
                para2->result = MMI_TRUE;
                srv_bt_cm_post_notify(SRV_BT_CM_EVENT_RELEASE_ALL_CONN, para2);
            }
            break;

        case SRV_BT_CM_STATE_DEACTIVATING:
            if (SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_PRE_DEACTIVATING))
            {
                if (srv_bt_cm_release_all_conn() == SRV_BT_CM_RESULT_SUCCESS)
                {
                    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DEACTIVATING);
                }
                else
                {
                    StopTimer(BT_RELEASE_ALL_CON_GUARD_TIMER);
                    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_PRE_DEACTIVATING);
                    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
                    srv_bt_cm_switch_off();
                }
            }
            break;

        case SRV_BT_CM_STATE_CONNECTING:
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            break;

        case SRV_BT_CM_STATE_BONDING:
        case SRV_BT_CM_STATE_INQUIRING:
        case SRV_BT_CM_STATE_INQUIR_RES_IND:
        case SRV_BT_CM_STATE_SDC_SEARCHING:
            break;

        default:
            if (g_srv_bt_cm_cntx.tmp_state == SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND)
            {
                if (srv_bt_cm_pop_conn_cnf_stack() == NULL)
                {
                    SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
                }
            }
            else
            {
                if (g_srv_bt_cm_cntx.tmp_state > SRV_BT_CM_STATE_IDLE)
                {
                    state=g_srv_bt_cm_cntx.tmp_state;
                    SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_INIT_ON);
                }
                else
                {
                    state=SRV_BT_CM_STATE_IDLE;
                }
				SRV_BT_CM_STATE_TRANS(state);
            }
            break;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sco_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to handle SCO connent confirm
 * PARAMETERS
 *  result              [IN]            connect result
 *  conn_id       [IN]         connection id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_sco_connect_cnf_hdler(U8 result, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_bt_cm_sco_ind_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SCO_CONNECT_CNF_HDLER,
        result,
        conn_id,
        g_srv_bt_cm_cntx.state);

    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; i++)
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (g_srv_bt_cm_cntx.existed_conn[i].conn_id == conn_id))
        {
            break;
        }
    }

    if (i >= SRV_BT_CM_MAX_CONNECTION)
    {
        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);
        para.result = MMI_FALSE;
    }
    else
    {
        if (!result)
        {
            SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);
            g_srv_bt_cm_cntx.existed_conn[i].audio_on = MMI_TRUE;
        }

        para.result = g_srv_bt_cm_cntx.existed_conn[i].audio_on ? MMI_TRUE: MMI_FALSE;
    }

    srv_bt_cm_notify(SRV_BT_CM_EVENT_SCO_IND, (void*)&para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sco_connect_ind_hdler
 * DESCRIPTION
 *  This function is to handle SCO connect indication
 * PARAMETERS
 *  conn_id       [IN]            connection id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_sco_connect_ind_hdler(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_sco_ind_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SCO_CONNECT_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        conn_id);

    if ( conn_id > 0 && conn_id <= SRV_BT_CM_MAX_CONNECTION)
    {
        SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);
        g_srv_bt_cm_cntx.existed_conn[conn_id - 1].audio_on = MMI_TRUE;
        para.result = MMI_TRUE;
    }
    else
    {
        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);
        para.result = MMI_FALSE;    
    }

    srv_bt_cm_notify(SRV_BT_CM_EVENT_SCO_IND, (void*)&para);
}




/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sco_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to SCO disconnection indication
 * PARAMETERS
 *  conn_id       [IN]            connection id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_sco_disconnect_ind_hdler(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_sco_ind_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SCO_DISCONNECT_IND_HDLER,
        g_srv_bt_cm_cntx.state,
        conn_id);

    SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_SWAP2BT);
    if ((conn_id > 0) && (conn_id < SRV_BT_CM_MAX_CONNECTION))
    {
        g_srv_bt_cm_cntx.existed_conn[conn_id - 1].audio_on = MMI_FALSE;
    }

    para.result = MMI_FALSE;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_SCO_IND, (void*)&para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_init
 * DESCRIPTION
 *  This function is to init CM
 *        1. set flag
 *        2. init context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_INIT);
    //memset(srv_bt_cm_handle, 0, (sizeof(srv_bt_cm_hdlr_struct) * SRV_BT_CM_MAX_INSTANCE_NUM));
    srv_bt_cm_nvram_read_info();
    srv_bt_cm_init_event_handler();

    /* init deactivate flag */
    g_srv_bt_cm_cntx.deactivate_flag = 0xffffffff;

#ifdef __BT_AUTO_DETECT_SUPPORT__
    srv_bt_cm_check_chip();
#endif

#ifdef __SUPPORT_JBT__
    /* init jsr82 bcc */
    mmi_bth_bcc_init_handler();
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
    srv_bt_cm_dialer_init();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_conn_type
 * DESCRIPTION
 *  This function is to get connection type
 * PARAMETERS
 *  profile_id      [IN]            profile id
 * RETURNS
 *  srv_bt_cm_connection_type         connection type
 *****************************************************************************/
srv_bt_cm_connection_type srv_bt_cm_get_conn_type(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_CONN_TYPE,
        profile_id);

    for (i = 0; i < SRV_BT_CM_NUM_OF_PROFILE_UUID; i++)
    {
        if (profile_id_to_connect_type_map[i][0] == profile_id)
        {
            return (srv_bt_cm_connection_type)profile_id_to_connect_type_map[i][1];
        }
    }

    return SRV_BT_CM_NO_CONNECTION;
}

#ifdef __SUPPORT_JBT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_register_operation_callback
 * DESCRIPTION
 *  This function is to register operation callback
 * PARAMETERS
 *  oper_type       [IN]        operaion type
 *  func_p            [IN]        function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_register_operation_callback(srv_bt_cm_oper_type_enum oper_type, FuncPtr func_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_REGISTER_OPERATION_CALLBACK,
        oper_type,
        func_p);

    if (oper_type < SRV_BT_CM_OPER_TYPE_TOTAL)
    {
        g_srv_bt_cm_cntx.operation_cb_tbl[oper_type].operation_type = oper_type;
        g_srv_bt_cm_cntx.operation_cb_tbl[oper_type].cb_func_ptr = (srv_bt_cm_func_ptr_void_ptr)func_p;
    }
    else
    {
        MMI_BT_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_unregister_operation_callback
 * DESCRIPTION
 *  This function is to unregister operation callback
 * PARAMETERS
 *  oper_type           [IN]        operation type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_unregister_operation_callback(srv_bt_cm_oper_type_enum oper_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_UNREGISTER_OPERATION_CALLBACK,
        oper_type);

    if (oper_type < SRV_BT_CM_OPER_TYPE_TOTAL)
    {
        g_srv_bt_cm_cntx.operation_cb_tbl[oper_type].operation_type = oper_type;
        g_srv_bt_cm_cntx.operation_cb_tbl[oper_type].cb_func_ptr = NULL;
    }
    else
    {
        MMI_BT_ASSERT(0);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_reg_pairing_permission
 * DESCRIPTION
 *  This function is to register the pairing permission function call
 * PARAMETERS
 *  U32 profile_id, to specify the profile uuid
 *  void *fp, registered function call for CM to check if pairing procedure is permitted
 *            the input argument of the registerd function call is srv_bt_cm_bt_addr, CM will pass this
 *            information to registered function call.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_reg_pairing_permission(U32 profile_id, void* fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_REG_PAIRING_PERMISSION,
        profile_id,
        fp);

    g_srv_bt_cm_cntx.pair_permission_cb.profile_uuid = profile_id;
    g_srv_bt_cm_cntx.pair_permission_cb.func_ptr = (MMI_BOOL(*)(srv_bt_cm_bt_addr))fp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_unreg_pairing_permission
 * DESCRIPTION
 *  This function is to unregister the pairing permission function call
 * PARAMETERS
 *  U32   profile_id, to specify the profile uuid
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_unreg_pairing_permission(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_UNREG_PAIRING_PERMISSION,
        profile_id);

    g_srv_bt_cm_cntx.pair_permission_cb.profile_uuid = 0;
    g_srv_bt_cm_cntx.pair_permission_cb.func_ptr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_connect_default_headset
 * DESCRIPTION
 *  This function is to process connect default headset request
 * PARAMETERS
 *  conn_cb : connection callback function
 * RETURNS
 *  MMI_BOOL        TRUE : success to connect
 *                  FALSE : otherwise
 *****************************************************************************/
MMI_BOOL srv_bt_cm_connect_default_headset(srv_bt_cm_headset_connect_callback conn_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_CONNECT_DEFAULT_HEADSET,
        conn_cb);

#ifdef __MMI_HFP_SUPPORT__
    return srv_bthf_attach_device(NULL, (BTHFAttachCallback)conn_cb);
#else
    return MMI_FALSE;
#endif /* __MMI_HFP_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_deactivate_profiles
 * DESCRIPTION
 *  This function is to process deactivate profiles request and invoke the deactivate function of profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_deactivate_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEACTIVATE_PROFILES,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.deactivate_flag);

    if (SRV_BT_CM_GET_RAMFLAG(SRV_BT_CM_RAMMASK_POST_DEACTIVATING))
    {
        return;
    }

    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if ((!(g_srv_bt_cm_cntx.deactivate_flag & (g_srv_bt_cm_profile_tbl[i].deactivate_flag))))
        {
            if (g_srv_bt_cm_profile_tbl[i].deactivater)
            {
                (*g_srv_bt_cm_profile_tbl[i].deactivater)();
            }

        }
    }

    SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_POST_DEACTIVATING);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_send_msg
 * DESCRIPTION
 *  This function is the handler for send msg to XXX module
 * PARAMETERS
 *  dest_module         [IN]        destination module
 *  sap_id              [IN]            SAP id
 *  msg_id              [IN]           message id
 *  p_local_para        [IN]         local parameter
 *  p_peer_buff         [IN]         peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_send_msg(U32 dest_module, U32 sap_id, U32 msg_id, void* p_local_para, void* p_peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SEND_MSG , dest_module, msg_id); */
    msg_send6(
        stack_get_active_module_id(),
        (module_type)dest_module,
        (sap_type)sap_id,
        (msg_type)msg_id,
        (local_para_struct*)p_local_para,
        (peer_buff_struct*)p_peer_buff);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_existed_conn_num
 * DESCRIPTION
 *  This function is to get existed connection number
 * PARAMETERS
 *  void
 * RETURNS
 *  U8          existed connection number
 *****************************************************************************/
U8 srv_bt_cm_get_existed_conn_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, count = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i) 
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (g_srv_bt_cm_cntx.existed_conn[i].active))
        {
            ++count;
        }
    }
    
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_EXISTED_CONN_NUM,
        count);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_existed_conn_info
 * DESCRIPTION
 *  This function is to get existed connection info
 * PARAMETERS
 *  index       [IN]           existed connection index
 * RETURNS
 *  srv_bt_cm_connect_struct      existed connection info
 *****************************************************************************/
srv_bt_cm_connect_struct* srv_bt_cm_get_existed_conn_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_EXISTED_CONN_INFO,
        index);

    for (i = 0, count = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (g_srv_bt_cm_cntx.existed_conn[i].active))
        {
            if (count == index)
            {
                return &(g_srv_bt_cm_cntx.existed_conn[i]);
            }
            ++count;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_sco_status
 * DESCRIPTION
 *  This function is to get sco status
 * PARAMETERS
 *  conn_id:     [IN]    connection id
 * RETURNS
 *  MMI_BOOL    MMI_TRUE  : SCO link is on
 *              MMI_FALSE : SCO link is off
 *****************************************************************************/
MMI_BOOL srv_bt_cm_get_sco_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if (srv_bt_cm_is_hf_profile_connected(i))
        {
            result = g_srv_bt_cm_cntx.existed_conn[i].audio_on;
            break;
        }
    }

    /* return MMI_FALSE if cannot find this connection */
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_SCO_STATUS,
        result);

    return result;
}


void srv_bt_cm_release_all_conn_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_release_all_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RELEASE_ALL_CONN_TIMEOUT_HDLR,
        g_srv_bt_cm_cntx.state);

    if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION)
    {
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_RESTART_REQ, NULL, NULL); //srv_bt_cm_restart_bt_module_req();

        para.dev_addr = NULL;
        para.result = MMI_FALSE;
        srv_bt_cm_notify(SRV_BT_CM_EVENT_RELEASE_ALL_CONN, (void*)&para);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_release_conn
 * DESCRIPTION
 *  This function is to process disconnect request
 * PARAMETERS
 *  conn_id        [IN]            connection id
 * RETURNS
 *  srv_bt_cm_result_codes_enum
 *****************************************************************************/
S32 srv_bt_cm_release_conn(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, table_index, profile_id = SRV_BT_CM_MAX_PROFILE_UUID;
    srv_bt_cm_result_codes_enum result = SRV_BT_CM_RESULT_PROFILE_NOT_SUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (g_srv_bt_cm_cntx.existed_conn[i].conn_id == conn_id))
        {
            profile_id = g_srv_bt_cm_cntx.existed_conn[i].profile_id;
            i = g_srv_bt_cm_cntx.existed_conn[i].index_of_dev_list;
            break;
        }
    }

    g_srv_bt_cm_cntx.disconnect_con_id = conn_id;

    for (table_index = 0; table_index < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++table_index)
    {
        if ((g_srv_bt_cm_profile_tbl[table_index].profile_id == profile_id))
        {
            if (g_srv_bt_cm_profile_tbl[table_index].disconnector)
            {
                (*g_srv_bt_cm_profile_tbl[table_index].disconnector)(conn_id);
            }

            result = SRV_BT_CM_RESULT_SUCCESS;
            break;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RELEASE_CONN,
        conn_id,
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_release_all_conn
 * DESCRIPTION
 *  This function is to process release all connection request and invoke srv_bt_cm_disconnect
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_bt_cm_release_all_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RELEASE_ALL_CONN);

    if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_INQUIR_CANCELLING)
    {
        return SRV_BT_CM_RESULT_FAILED;
    }
    
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; i++)
    {
        if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
            (g_srv_bt_cm_cntx.existed_conn[i].active))
        {
            srv_bt_cm_release_conn(g_srv_bt_cm_cntx.existed_conn[i].conn_id);
            if ((g_srv_bt_cm_cntx.state > SRV_BT_CM_STATE_IDLE) &&
                (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION))
            {
                SRV_BT_CM_TMP_STATE_TRANS(g_srv_bt_cm_cntx.state);
            }

            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION);
            StartTimer(
                BT_RELEASE_ALL_CON_GUARD_TIMER,
                SRV_BT_CM_RELEASE_ALL_CONN_TIMER_DUR,
                srv_bt_cm_release_all_conn_timeout_hdlr);
            return SRV_BT_CM_RESULT_SUCCESS;
        }
    }

    return SRV_BT_CM_RESULT_NO_CONNECTION;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_release_dev_conn
 * DESCRIPTION
 *  This function is to process release device connection request
 * PARAMETERS
 *  dev_addr:       [IN]             the device address pointer
 * RETURNS
 *  srv_bt_cm_result_codes_enum       
 *****************************************************************************/
S32 srv_bt_cm_release_dev_conn(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RELEASE_DEV_CONN,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap);

    if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_INQUIR_CANCELLING)
    {
        return SRV_BT_CM_RESULT_FAILED;
    }

    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        /* save the index of paired list to action_index for release dev connections */
        /* XXX disconnected ind will use this index to get dev_addr for releasing next connection */
        srv_bt_cm_set_action_index(i);
        for (j = 0; j < SRV_BT_CM_MAX_CONNECTION; ++j)
        {
            if ((g_srv_bt_cm_cntx.existed_conn[j].conn_id > 0) &&
                (g_srv_bt_cm_cntx.existed_conn[j].index_of_dev_list == i) &&
                (g_srv_bt_cm_cntx.existed_conn[j].active))
            {
                srv_bt_cm_release_conn(g_srv_bt_cm_cntx.existed_conn[j].conn_id);
                if ((g_srv_bt_cm_cntx.state > SRV_BT_CM_STATE_IDLE) &&
                    (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION))
                {
                    SRV_BT_CM_TMP_STATE_TRANS(g_srv_bt_cm_cntx.state);
                }
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION);
                return SRV_BT_CM_RESULT_SUCCESS;
            }
        }

        return SRV_BT_CM_RESULT_NO_CONNECTION;
    }

    return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_release_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr  :    [IN]
 *  profile_id:    [IN]
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_bt_cm_release_profile(srv_bt_cm_bt_addr* dev_addr, U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RELEASE_PROFILE,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        profile_id);

    if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_INQUIR_CANCELLING)
    {
        return SRV_BT_CM_RESULT_FAILED;
    }

    idx = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (idx < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
        {
            if ((g_srv_bt_cm_cntx.existed_conn[i].conn_id > 0) &&
                (g_srv_bt_cm_cntx.existed_conn[i].index_of_dev_list == (U8)idx) &&
                (g_srv_bt_cm_cntx.existed_conn[i].active) &&
                (g_srv_bt_cm_cntx.existed_conn[i].profile_id == profile_id))
            {
                srv_bt_cm_release_conn(g_srv_bt_cm_cntx.existed_conn[i].conn_id);
                if ((g_srv_bt_cm_cntx.state > SRV_BT_CM_STATE_IDLE) &&
                    (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_DISCONNECTING))
                {
                    SRV_BT_CM_TMP_STATE_TRANS(g_srv_bt_cm_cntx.state);
                }
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DISCONNECTING);
                return SRV_BT_CM_RESULT_SUCCESS;
            }
        }

        return SRV_BT_CM_RESULT_NO_CONNECTION;
    }

    return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_searched_dev_num
 * DESCRIPTION
 *  This function is to get discovered device number
 * PARAMETERS
 *  void
 * RETURNS
 *  U8          discovered device number
 *****************************************************************************/
U8 srv_bt_cm_get_searched_dev_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_bt_cm_get_dev_num(SRV_BT_CM_DISCOVERED_DEV);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_searched_dev_info
 * DESCRIPTION
 *  This function is to get discovered device info
 * PARAMETERS
 *  index       [IN]            the index of discovered device
 * RETURNS
 *  srv_bt_cm_dev_struct      the device info structure
 *****************************************************************************/
srv_bt_cm_dev_struct* srv_bt_cm_get_searched_dev_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_SEARCHED_DEV_INFO,
        index);

    MMI_BT_ASSERT(index < g_srv_bt_cm_cntx.discovered_dev_num);
    return &(g_srv_bt_cm_cntx.discovered_list[index]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_paired_dev_num
 * DESCRIPTION
 *  This function is to get paired device number
 * PARAMETERS
 *  void
 * RETURNS
 *  U8              paired device number
 *****************************************************************************/
U8 srv_bt_cm_get_paired_dev_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_bt_cm_get_dev_num(SRV_BT_CM_PAIRED_DEV);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_paired_dev_info
 * DESCRIPTION
 *  This function is to get paired device information
 * PARAMETERS
 *  index       [IN]          index or paired device  
 * RETURNS
 *  srv_bt_cm_dev_struct      device infor structure
 *****************************************************************************/
srv_bt_cm_dev_struct* srv_bt_cm_get_paired_dev_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_PAIRED_DEV_INFO,
        index);

    ASSERT(index < g_srv_bt_cm_cntx.paired_dev_num);
    idx = g_srv_bt_cm_cntx.paired_idx_list[index];

    return &(g_srv_bt_cm_cntx.dev_list[idx].dev_info);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_info
 * DESCRIPTION
 *  this function will return the device information from paird device list and searched device list according to address,
 *  if can't find the device, it will return NULL
 * PARAMETERS
 *  dev_addr    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
extern const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_INFO,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff));

    for (i = 0; i < SRV_BT_CM_MAX_DEVICE_LIST; ++i)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr, dev_addr) &&
            (g_srv_bt_cm_cntx.dev_list[i].ref_cnt > 0))
        {
            return &(g_srv_bt_cm_cntx.dev_list[i].dev_info);
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_search
 * DESCRIPTION 
 *  This function is to process inquiry request and invoke srv_bt_cm_discovery_req_hdler
 * PARAMETERS
 *  max_response        [IN]            max repsone number of device
 *  timeout             [IN]                inquiry timeout timer
 *  cod                 [IN]                  class of device
 *  name_discovery      [IN]            name discovery 
 *  user_data   [IN]            user data 
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_cm_search(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SEARCH,
        max_response,
        timeout,
        cod,
        name_discovery,
        g_srv_bt_cm_cntx.state);

    if ((g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIRING) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIR_RES_IND) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_INQUIR_CANCELLING) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_BONDING) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_PASSKEY_IND) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_PASSKEY_RES) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_NUMERIC_CONFIRM) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_PASSKEY_NOTIFY) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_SDC_SEARCHING) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_CONNECTING))
    {
        srv_bt_cm_discovery_req_hdler(max_response, timeout, cod, name_discovery);

        /* reset discovered device counter */
        g_srv_bt_cm_cntx.discovered_dev_num = 0;
		/*MAUI_03214569 */
		memset(
               &(g_srv_bt_cm_cntx.discovered_list),
               0,
               sizeof(srv_bt_cm_dev_struct) * SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST);
		/*MAUI_03214569 */
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_INQUIRING);

        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_search_abort
 * DESCRIPTION
 *  This function is to process inquiry cancel request and invoke srv_bt_cm_cancel_discovery_req_hdler
 * PARAMETERS
 *  user_data        [IN]            user data
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_bt_cm_search_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SEARCH_ABORT,
        g_srv_bt_cm_cntx.state);

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_INQUIRING:
        case SRV_BT_CM_STATE_INQUIR_RES_IND:
            srv_bt_cm_cancel_discovery_req_hdler();
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_INQUIR_CANCELLING);
            return SRV_BT_CM_RESULT_SUCCESS;
    }
    
    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond
 * DESCRIPTION
 *  This function is to process bond request and invoke srv_bt_cm_bond_req_hdler
 * PARAMETERS
 *  index       [IN]            discovered device index
 *  user_data   [IN]            user data 
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_cm_bond(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count;
    U16 sdap_uuid[(sizeof(inquiry_profile_tbl) / sizeof(U32))];
    srv_bt_cm_bt_addr dev_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_BOND,
        index,
        g_srv_bt_cm_cntx.state);

    srv_bt_cm_set_action_index(index);
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_IDLE:
            dev_addr = g_srv_bt_cm_cntx.discovered_list[index].bd_addr;
            count = (sizeof(inquiry_profile_tbl) / sizeof(U32)) - 1;
            count = (count <= SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE) ? count : SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE;
            for (i = 0; i < count; i++)
            {
                sdap_uuid[i] = inquiry_profile_tbl[i];
            }

            srv_bt_cm_bond_req_hdler(dev_addr, count, sdap_uuid);
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_BONDING);
            return SRV_BT_CM_RESULT_SUCCESS;

        case SRV_BT_CM_STATE_INQUIRING:
        case SRV_BT_CM_STATE_INQUIR_RES_IND:
            srv_bt_cm_search_abort(); /* ZHY: should bond at srv_bt_cm_cancel_discovery_cnf_hdler() */
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_BONDING);
            return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


#ifdef __BT_BOND_CANCEL__
S32 srv_bt_cm_bond_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 state;
    U32 action_index = g_srv_bt_cm_cntx.action_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = srv_bt_cm_get_state();
    switch (state)
    {
        case SRV_BT_CM_STATE_BONDING:
        case SRV_BT_CM_STATE_SDC_SEARCHING:
        {
            srv_bt_cm_bt_addr* dev_addr = &(g_srv_bt_cm_cntx.discovered_list[action_index].bd_addr);
            srv_bt_cm_bond_cancel_req_hdler(dev_addr);
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_BONDING_CANCEL);
            return SRV_BT_CM_RESULT_SUCCESS;
        }
    }

    return SRV_BT_CM_RESULT_FAILED;
}
#endif

/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_debond
 * DESCRIPTION
 *  this function is to debond a device
 * PARAMETERS
 *  index:    [IN]    device index
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_bt_cm_debond(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEBOND,
        index,
        g_srv_bt_cm_cntx.state);
    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_IDLE:
            if (index < g_srv_bt_cm_cntx.paired_dev_num)
            {
                SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DEBONDING);
                srv_bt_cm_set_action_index(index);
                srv_bt_cm_debond_req_hdler(&(g_srv_bt_cm_cntx.dev_list[g_srv_bt_cm_cntx.paired_idx_list[index]].dev_info.bd_addr));
                return SRV_BT_CM_RESULT_SUCCESS;
            }
            
            return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_send_passkey
 * DESCRIPTION
 *  This function is to process pair request and send passkey
 * PARAMETERS
 *  dev_addr        [IN]             device address
 *  dev_passkey     [IN]           passkey
 *  result          [IN]                result
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_cm_send_passkey(srv_bt_cm_bt_addr* dev_addr, U8* dev_passkey, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pin_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SEND_PASSKEY,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        result);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        pin_len = result ? strlen((const char*)dev_passkey) : 0;
        srv_bt_cm_passkey_ind_rsp_hdler((*dev_addr), pin_len, dev_passkey);

        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_PASSKEY_IND)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_PASSKEY_RES);
        }

        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


#ifdef __MMI_BT_SIMPLE_PAIR__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_numeric_confirm
 * DESCRIPTION
 *  This function is to reply the numeric confirmation
 * PARAMETERS
 *  dev_addr:        [IN]       device address      
 *  accept:          [IN]       MMI_TRUE means numeric confirmation result is correct
 *                              MMI_FALSE means numeric confirmation result is incorrect
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_numeric_confirm(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_NUMERIC_CONFIRM,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        accept,
        g_srv_bt_cm_cntx.state);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        srv_bt_cm_security_user_confirm_rsp_hdler((*dev_addr), accept);

        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_NUMERIC_CONFIRM)
        {
            /* waiting for bond ind result */
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_cancel
 * DESCRIPTION
 *  This function is to cancel the passkey keypress notify
 * PARAMETERS
 *  dev_addr        [IN]       device address      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_keypress_notify_cancel (srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SECURITY_KEYPRESS_NOTIFY_CANCEL);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        srv_bt_cm_security_keypress_notify_cancel_req_hdler((*dev_addr));

        if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_PASSKEY_NOTIFY)
        {
            /* waiting for bond ind result */
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL);
        }
    }
}
#endif /* __MMI_BT_SIMPLE_PAIR__ */


#if defined(__MMI_BT_AUTHORIZE__)
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_unblock
 * DESCRIPTION
 *  This function is to unblock the specific device
 * PARAMETERS
 *  dev_addr        [IN]       device address      
 *  user_data   [IN]            user data 
 * RETURNS
 *  srv_bt_cm_result_codes_enum    
 *****************************************************************************/
S32 srv_bt_cm_unblock (srv_bt_cm_bt_addr* dev_addr)      
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_UNBLOCK,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff));

    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_PAIRED_DEV);
    if (i < g_srv_bt_cm_cntx.paired_dev_num)
    {
        idx = g_srv_bt_cm_cntx.paired_idx_list[i];
        g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute &= ~SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK;
        if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_UNBLOCK_DEVICE_LINK);
            srv_bt_cm_block_list_update_req_hdler();
            /* will deal with the result in srv_bt_cm_block_list_update_cnf_hdler() */
        }

        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)idx);
        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
}


/*****************************************************************************
* FUNCTION
*  srv_bt_cm_mydev_authorize
* DESCRIPTION
*   This function is to set the authorize setting of a certain device
* PARAMETERS
*  dev_addr         [IN]        device address
*  authorize_type   [IN]        authorize_type: always connect, always ask, or always reject
* RETURNS
*  srv_bt_cm_result_codes_enum      
*****************************************************************************/
S32 srv_bt_cm_set_authorize(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_authorize_type authorize_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_AUTHORIZE,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        authorize_type);

    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_PAIRED_DEV);
    if (i >= g_srv_bt_cm_cntx.paired_dev_num)
    {
        return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
    }

    /* block:      when block flag is set, no matter authorize flag is set or not
     * authorize:  when authorize flag is set and block flag is not set
     * always ask: when neithor block not authorize flag is set */
    if ((g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_PASSKEY_IND) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_PASSKEY_RES) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_NUMERIC_CONFIRM) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_PASSKEY_NOTIFY) &&
        (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL))
    {
        idx = g_srv_bt_cm_cntx.paired_idx_list[i];
        switch (authorize_type)
        {
            case SRV_BT_CM_AUTHORIZE_ALWAYS_ASK:
                g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute &= ~SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK;
                g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute &= ~SRV_BT_CM_DEVICE_ATTRIBUTE_AUTHORIZE;
                break;

            case SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT:
                g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute |= SRV_BT_CM_DEVICE_ATTRIBUTE_AUTHORIZE;
                g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute &= ~SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK;
                break;

            case SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT:
                /* should not clear flag:SRV_BT_CM_DEVICE_ATTRIBUTE_AUTHORIZE
                 * it is used to recover the previous setting from action Unblock */
                g_srv_bt_cm_cntx.dev_list[idx].dev_info.attribute |= SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK;
                if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
                {
                    if (g_srv_bt_cm_cntx.state > SRV_BT_CM_STATE_IDLE)
                    {
                        SRV_BT_CM_TMP_STATE_TRANS(g_srv_bt_cm_cntx.state);
                    }
                    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_BLOCK_DEVICE_LINK);

                    srv_bt_cm_block_active_link_req_hdler(*dev_addr);
                    /* will deal with the result in srv_bt_cm_block_list_update_cnf_hdler() */
                }
                break;
        }

        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)idx);
        if ((authorize_type == SRV_BT_CM_AUTHORIZE_ALWAYS_ASK) ||
            (authorize_type == SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT))
        {
            srv_bt_cm_set_authorize_struct* para_p;

            para_p = (srv_bt_cm_set_authorize_struct*)OslMalloc(sizeof(srv_bt_cm_set_authorize_struct));
            para_p->result = MMI_TRUE;
            srv_bt_cm_post_notify(SRV_BT_CM_EVENT_SET_AUTHORIZE, para_p);
        }

        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_authorize_type
 * DESCRIPTION
 *  this function will return the device authorized type
 * PARAMETERS
 *  dev_addr    [IN]
 *  
 * RETURNS
 *  srv_bt_cm_authorize_type
 ******************************************************************************/
extern srv_bt_cm_authorize_type srv_bt_cm_get_authorize(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_bt_cm_authorize_type result = SRV_BT_CM_AUTHORIZE_TOTAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
    if (i < SRV_BT_CM_MAX_DEVICE_LIST)
    {
        if (g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK)
        {
            result = SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT;
        }
        else if (g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_AUTHORIZE)
        {
            result = SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT;
        }
        else
        {
            result = SRV_BT_CM_AUTHORIZE_ALWAYS_ASK;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_AUTHORIZE,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        result);

    return result;
}
#endif /* (__MMI_BT_AUTHORIZE__) */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_refresh_service_list
 * DESCRIPTION
 *  This function is to process refresh service list request
 * PARAMETERS
 *  dev_addr        [IN]             device address
 *  user_data   [IN]            user data 
 * RETURNS
 *  srv_bt_cm_result_codes_enum
 *****************************************************************************/
S32 srv_bt_cm_refresh_service_list(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count;
    U16 sdap_uuid[(sizeof(inquiry_profile_tbl) / sizeof(U32))];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_REFRESH_SERVICE_LIST_REQ);

    if (srv_bt_cm_get_state() == SRV_BT_CM_STATE_IDLE)
    {
        i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_ALL_DEV);
        if (i >= SRV_BT_CM_MAX_DEVICE_LIST)
        {
            return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
        }

        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_REFRESH_SERVICE_LIST,
            g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num);

        g_srv_bt_cm_cntx.stored_ser_list_num = g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num;
        g_srv_bt_cm_cntx.dev_list[i].dev_info.service_list_num = 0;
        count = (sizeof(inquiry_profile_tbl) / sizeof(U32)) - 1;
        count = (count <= SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE) ? count : SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE;
        for (i = 0; i < count; i++)
        {
            sdap_uuid[i] = inquiry_profile_tbl[i];
        }

        /* start the SDC searching */
        srv_bt_cm_sdc_search_req_hdler((*dev_addr), count, sdap_uuid);
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_SDC_REFRESHING);

        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_dev_del
 * DESCRIPTION
 *  This function is to process my device delete request
 * PARAMETERS
 *  dev_addr        [IN]             device address
 *  user_data   [IN]            user data 
 * RETURNS
 *  srv_bt_cm_result_codes_enum      
 *****************************************************************************/
S32 srv_bt_cm_dev_del(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_DEL,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap);

    if (srv_bt_cm_get_state() == SRV_BT_CM_STATE_IDLE)
    {
        i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_PAIRED_DEV);
        if (i < g_srv_bt_cm_cntx.paired_dev_num)
        {
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DELETING);
            srv_bt_cm_set_action_index(g_srv_bt_cm_cntx.paired_idx_list[i]);
            srv_bt_cm_debond_req_hdler(dev_addr);

            return SRV_BT_CM_RESULT_SUCCESS;
        }

        return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_dev_del_all
 * DESCRIPTION
 *  This function is to process My device delete all
 * PARAMETERS
 *  user_data   [IN]            user data
 * RETURNS
 *  srv_bt_cm_result_codes_enum
 *****************************************************************************/
S32 srv_bt_cm_dev_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_DEL_ALL);

    if (g_srv_bt_cm_cntx.state == SRV_BT_CM_STATE_IDLE)
    {
        if (g_srv_bt_cm_cntx.paired_dev_num != 0)
        {
            i = g_srv_bt_cm_cntx.paired_idx_list[0];
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DELETING_ALL);
            srv_bt_cm_debond_req_hdler(&(g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr));

#if defined(__MMI_HIDD_SUPPORT__)
            g_srv_bt_cm_cntx.idx_of_last_hid_dev = 0xFFFFFFFF;
#endif  // __MMI_HIDD_SUPPORT__
            // #ifdef __MMI_HIDD_SUPPORT__
            // mmi_bth_hidd_clear_last_dev_info();
            // #endif


#ifdef __MMI_HFP_SUPPORT__
            srv_bthf_save_config(BTHF_CFG_DEF_DEVICE, NULL);
#endif /* __MMI_HFP_SUPPORT__ */

            return SRV_BT_CM_RESULT_SUCCESS;
        }
        else
        {
            return SRV_BT_CM_RESULT_DEV_NOT_FOUND;
        }
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_dev_add
 * DESCRIPTION
 *  This function is to process My device add request
 * PARAMETERS
 *  dev_addr:    [IN]    device address pointer
 * RETURNS
 *  srv_bt_cm_result_codes_enum
 *****************************************************************************/
S32 srv_bt_cm_dev_add(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_bt_cm_dev_struct dev;
    S32 result = SRV_BT_CM_RESULT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_ADD,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap);

    i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_PAIRED_DEV);
    if (i >= g_srv_bt_cm_cntx.paired_dev_num)
    {
        memset(&dev, 0, sizeof(srv_bt_cm_dev_struct));
        srv_bt_cm_copy_addr(&dev.bd_addr,dev_addr);
        dev.service_list_num = 0;
        result = srv_bt_cm_dev_add_int((const srv_bt_cm_dev_struct*)&dev, SRV_BT_CM_PAIRED_DEV);
        i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)dev_addr, SRV_BT_CM_PAIRED_DEV);
    }
    
    i = g_srv_bt_cm_cntx.paired_idx_list[i];
    if ((g_srv_bt_cm_cntx.dev_list[i].dev_info.name[0] == 0) &&
        ((g_srv_bt_cm_cntx.dev_list[i].dev_info.attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_USER_DEFINED_NAME) == 0))
    {
        srv_bt_cm_read_remote_name_req_hdler(dev_addr);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_dev_remove
 * DESCRIPTION
 *  This function is to process My device remove request
 * PARAMETERS
 *  dev_addr       [IN]             device address pointer
 * RETURNS
 *  srv_bt_cm_result_codes_enum
 *****************************************************************************/
S32 srv_bt_cm_dev_remove(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_REMOVE,
        dev_addr->lap,
        dev_addr->uap,
        dev_addr->nap);

    return srv_bt_cm_dev_delete_int(dev_addr, SRV_BT_CM_PAIRED_DEV);
}




/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_state
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_state_enum          current bluetooth state
 *****************************************************************************/
srv_bt_cm_state_enum srv_bt_cm_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_STATE,
        g_srv_bt_cm_cntx.state);
    return g_srv_bt_cm_cntx.state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_host_dev_info
 * DESCRIPTION
 *  This function is to get host device information
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_dev_struct      the host device information
 *****************************************************************************/
srv_bt_cm_dev_struct* srv_bt_cm_get_host_dev_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_srv_bt_cm_cntx.host_dev);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_off
 * DESCRIPTION
 *  This function is to process antenna off request and invoke srv_bt_cm_antenna_off_req_hdler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_antenna_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ANTENNA_OFF);

    /* disable write scan enable(page off, inquiry off) */
    /* ->deactivate profiles */
    /* ->antenna off */
            srv_bt_cm_antenna_off_req_hdler();
    }

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_switch_on
 * DESCRIPTION
 *  This function is to process antenna on request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_cm_switch_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SWITCH_ON,
        g_srv_bt_cm_cntx.state);

    switch (g_srv_bt_cm_cntx.state)
    {
        case SRV_BT_CM_STATE_INIT_ON:
            srv_bt_cm_antenna_on_req_hdler();
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING);
            SRV_BT_CM_TMP_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING);
            if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_POWER_ON_TIME_OUT))
            {
                SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_POWER_ON_TIME_OUT);
            }
            {
                srv_bt_cm_begin_activate_struct* para_p;
                para_p = (srv_bt_cm_begin_activate_struct*)OslMalloc(sizeof(srv_bt_cm_begin_activate_struct));
                para_p->result = MMI_TRUE;
                
                srv_bt_cm_post_notify(SRV_BT_CM_EVENT_BEGIN_ACTIVATE, para_p);

            return SRV_BT_CM_RESULT_SUCCESS;
            }
        case SRV_BT_CM_STATE_ACTIVATING:
            return SRV_BT_CM_RESULT_SUCCESS;

        case SRV_BT_CM_STATE_DEACTIVATING:
            return SRV_BT_CM_RESULT_FAILED;

        /* is activating or is already on */
        default:
        {
            srv_bt_cm_activate_struct* para_p;
            para_p = (srv_bt_cm_activate_struct*)OslMalloc(sizeof(srv_bt_cm_activate_struct));
            para_p->result = MMI_TRUE;

            srv_bt_cm_post_notify(SRV_BT_CM_EVENT_ACTIVATE, para_p);

            return SRV_BT_CM_RESULT_SUCCESS;
        }
    }
}


void srv_bt_cm_switch_off_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SWITCH_OFF_TIMEOUT_HDLR);

    SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_POWER_OFF_TIME_OUT);
    SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_ACTIVATED);
    SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DEACTIVATING);
    srv_bt_cm_antenna_off();
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_switch_off
 * DESCRIPTION
 *  This function is to process deactivate request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_switch_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SWITCH_OFF,
        g_srv_bt_cm_cntx.state,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.ram_flag,
        g_srv_bt_cm_cntx.deactivate_flag);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        {
            srv_bt_cm_inquiry_complete_struct para;
            srv_bt_cm_bond_res_struct para2;
            switch (g_srv_bt_cm_cntx.state) {
                case SRV_BT_CM_STATE_INQUIRING:
                case SRV_BT_CM_STATE_INQUIR_RES_IND:
                    para.result = BTBM_ADP_SUCCESS;
                    para.is_cancelled = MMI_FALSE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_COMPLETE, (void*)&para);
                    break;

                case SRV_BT_CM_STATE_INQUIR_CANCELLING:
                    para.result = MMI_TRUE;
                    para.is_cancelled = MMI_TRUE;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_INQUIRY_COMPLETE, (void*)&para);
                    break;

                case SRV_BT_CM_STATE_BONDING:
                    para2.result = SRV_BT_CM_BTBM_FAILED;
                    srv_bt_cm_notify(SRV_BT_CM_EVENT_BOND_RES, (void*)&para2);
                    break;
                    
            }
        }

        
        {
            srv_bt_cm_begin_deactivate_struct* para_p;
            para_p = (srv_bt_cm_begin_deactivate_struct*)OslMalloc(sizeof(srv_bt_cm_begin_deactivate_struct));
            para_p->result = MMI_TRUE;

            srv_bt_cm_post_notify(SRV_BT_CM_EVENT_BEGIN_DEACTIVATE, para_p);
        }
        

        if (srv_bt_cm_release_all_conn() == SRV_BT_CM_RESULT_SUCCESS)
        {
            SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_PRE_DEACTIVATING);
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DEACTIVATING);
            return;
        }

        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DEACTIVATING);
        SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_POST_DEACTIVATING);
            
        /* disallow acl link establishment */
        /* ->disable write scan enable(page off, inquiry off) */
        /* ->deactivate profiles */
        /* ->antenna off */
        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_DISALLOW_REQ, NULL, NULL);
        /* deal with the response at srv_bt_cm_disallow_acl_link_establishment_cnf_hdler() */

        srv_bt_cm_write_scanenable_mode_req_hdler((U8)BTBM_ADP_P_OFF_I_OFF);

        if (SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_POWER_OFF_TIME_OUT))
        {
            SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_POWER_OFF_TIME_OUT);
        }

#ifdef __MMI_BT_TEMP_VISIBILITY__
        if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_TEMPORARY_ON)
        {
            srv_bt_cm_set_visibility_struct para;

            StopTimer(BT_TEMP_VISIBLE_TIMER);
            SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_VIS);
            SRV_BT_CM_RESET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_TEMP_VIS);
            g_srv_bt_cm_cntx.tmp_visibility_type = 0;
            srv_bt_cm_nvram_write_info(NVRAM_EF_BT_SYS_INFO_LID, (void*)0);

            para.result = MMI_TRUE;
            para.is_from_mmi = MMI_FALSE;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_SET_VISIBILITY, (void*)&para);
        }
#endif  // __MMI_BT_TEMP_VISIBILITY__
            
        StartTimer(
            BT_POWER_OFF_GUARD_TIMER,
            SRV_BT_CM_POWER_OFF_TIMER_DUR,
            srv_bt_cm_switch_off_timeout_hdlr);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_power_on_activate_profile
 * DESCRIPTION
 *  This function is to activate BT profiles, invoke from MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_activate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_activate_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ACTIVATE_PROFILE,
        g_srv_bt_cm_cntx.state);

    /* if not all profile activated, 
       1. change state to SRV_BT_CM_STATE_ACTIVATING_PROFILES
       2. activate the profiles */
    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        if (!srv_bt_cm_is_all_supported_profiles_activated(MMI_FALSE))
        {
            if (g_srv_bt_cm_cntx.state > SRV_BT_CM_STATE_IDLE)
            {
                SRV_BT_CM_TMP_STATE_TRANS(g_srv_bt_cm_cntx.state);
            }
            SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_ACTIVATING_PROFILES);
            srv_bt_cm_activate_profiles_int(MMI_FALSE);
        }
        /* otherwise change the state to idle and invoke activate function */
        else
        {
            SRV_BT_CM_SET_RAMFLAG(SRV_BT_CM_RAMMASK_IS_READY);
            /* ZHY: MAUI_02312807*/
            //SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_IDLE);
            srv_bt_cm_nvram_write_info(NVRAM_EF_BT_INFO_LID, (void*)0);
            para.result = MMI_TRUE;
            srv_bt_cm_notify(SRV_BT_CM_EVENT_ACTIVATE, (void*)&para);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_auth
 * DESCRIPTION
 *  This function is to process setting authentication request and invoke srv_bt_cm_security_level_req_hdler
 * PARAMETERS
 *  auth        [IN]            authentication value
 *  user_data   [IN]            user data 
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_cm_set_authentication(MMI_BOOL auth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_AUTHENTICATION,
        auth);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        if (auth)
        {
            SRV_BT_CM_SET_FLAG(SRV_BT_CM_MASK_AUTH);
        }
        else
        {
            SRV_BT_CM_RESET_FLAG(SRV_BT_CM_MASK_AUTH);
        }

        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_AUTHENTICATION_SETTING);
        srv_bt_cm_security_level_req_hdler((MMI_BOOL)SRV_BT_CM_GET_FLAG(SRV_BT_CM_MASK_AUTH));

        return SRV_BT_CM_RESULT_SUCCESS;
    }
    
    return SRV_BT_CM_RESULT_FAILED;
}



/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_nvram_read_info
 * DESCRIPTION
 *  This function is to read nvram info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_cm_nvram_read_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_nvram_struct read_struct;
    srv_bt_cm_nvram_dev_list_index_struct dev_list_index_struct;
    srv_bt_cm_sys_nvram_struct sys_read_struct;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_NVRAM_READ_INFO);

    ReadRecordSlim(NVRAM_EF_BT_INFO_LID, 1, &read_struct, NVRAM_EF_BT_INFO_SIZE);
    
        g_srv_bt_cm_cntx.flag |= read_struct.flag;
#if defined(__MMI_HIDD_SUPPORT__)
        g_srv_bt_cm_cntx.idx_of_last_hid_dev = read_struct.idx_of_last_hid_dev;
#endif  // __MMI_HIDD_SUPPORT__
        memcpy(
            &(g_srv_bt_cm_cntx.host_dev),
            &(read_struct.host_dev),
            sizeof(srv_bt_cm_dev_struct));

    ReadRecordSlim(NVRAM_EF_BT_SYS_INFO_LID, 1, &sys_read_struct, NVRAM_EF_BT_SYS_INFO_SIZE);
        g_srv_bt_cm_cntx.flag |= sys_read_struct.sys_flag;
        memcpy(g_srv_bt_cm_cntx.host_dev.name, sys_read_struct.host_dev_name, SRV_BT_CM_BD_FNAME_LEN);


    ReadRecordSlim(
        NVRAM_EF_BT_DEV_LIST_INDEX_LID,
        1,
        &dev_list_index_struct,
        NVRAM_EF_BT_DEV_LIST_INDEX_SIZE);
        g_srv_bt_cm_cntx.paired_dev_num = dev_list_index_struct.paired_dev_num;
        g_srv_bt_cm_cntx.recent_dev_num = dev_list_index_struct.recent_dev_num;
        memcpy(
            g_srv_bt_cm_cntx.paired_idx_list,
            dev_list_index_struct.paired_idx_list,
            sizeof(U8) * SRV_BT_CM_MAX_PAIRED_DEVICE_LIST);
        memcpy(
            g_srv_bt_cm_cntx.recent_idx_list,
            dev_list_index_struct.recent_idx_list,
            sizeof(U8) * SRV_BT_CM_MAX_USED_DEVICE_LIST);

    for (i = 1; i <= NVRAM_EF_BT_DEV_LIST_TOTAL; ++i)
    {
        ReadRecordSlim(
            NVRAM_EF_BT_DEV_LIST_LID,
            i,
            &g_srv_bt_cm_cntx.dev_list[i - 1],
            NVRAM_EF_BT_DEV_LIST_SIZE);
    }
    
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_NVRAM_READ_INFO,
        g_srv_bt_cm_cntx.flag,
        g_srv_bt_cm_cntx.paired_dev_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_nvram_write_info
 * DESCRIPTION
 *  This function is to write NVRAM info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_nvram_write_info(U16 LID, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_NVRAM_WRITE_INFO,
        LID,
        (U32)para,
        NVRAM_EF_BT_INFO_LID,
        NVRAM_EF_BT_SYS_INFO_LID,
        NVRAM_EF_BT_DEV_LIST_LID);

    switch (LID)
    {
        case NVRAM_EF_BT_INFO_LID:
        {
            srv_bt_cm_nvram_struct write_struct;

            memset(&write_struct, 0, sizeof(srv_bt_cm_nvram_struct));
            write_struct.flag = g_srv_bt_cm_cntx.flag & SRV_BT_CM_MASK_NON_SYS_SETTING;
#if defined(__MMI_HIDD_SUPPORT__)
            write_struct.idx_of_last_hid_dev = g_srv_bt_cm_cntx.idx_of_last_hid_dev;
#endif  // __MMI_HIDD_SUPPORT__
            memcpy(
                &write_struct.host_dev,
                &g_srv_bt_cm_cntx.host_dev,
                sizeof(srv_bt_cm_dev_struct));
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_G7_SRV_BT_CM_NVR_WRITE,
                write_struct.flag,
                g_srv_bt_cm_cntx.paired_dev_num);
            WriteRecordSlim(NVRAM_EF_BT_INFO_LID, 1, &write_struct, NVRAM_EF_BT_INFO_SIZE);
         
            break;
        }
        
        case NVRAM_EF_BT_SYS_INFO_LID:
        {
            srv_bt_cm_sys_nvram_struct sys_write_struct;

            sys_write_struct.sys_flag = g_srv_bt_cm_cntx.flag & SRV_BT_CM_MASK_SYS_SETTING;
            memcpy(sys_write_struct.host_dev_name, g_srv_bt_cm_cntx.host_dev.name, SRV_BT_CM_BD_FNAME_LEN);
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_G7_SRV_BT_CM_NVR_WRITE,
                sys_write_struct.sys_flag,
                g_srv_bt_cm_cntx.paired_dev_num);
            WriteRecordSlim(NVRAM_EF_BT_SYS_INFO_LID, 1, &sys_write_struct, NVRAM_EF_BT_SYS_INFO_SIZE);
           
            break;
        }
        
        case NVRAM_EF_BT_DEV_LIST_LID:
        //case NVRAM_EF_BT_DEV_LIST_INDEX_LID:
        {
            srv_bt_cm_nvram_dev_list_index_struct dev_list_index_struct;
            U32 i = (U32)para;

            dev_list_index_struct.paired_dev_num = g_srv_bt_cm_cntx.paired_dev_num;
            dev_list_index_struct.recent_dev_num = g_srv_bt_cm_cntx.recent_dev_num;
            memcpy(
                dev_list_index_struct.paired_idx_list,
                g_srv_bt_cm_cntx.paired_idx_list,
                sizeof(U8) * SRV_BT_CM_MAX_PAIRED_DEVICE_LIST);
            memcpy(
                dev_list_index_struct.recent_idx_list,
                g_srv_bt_cm_cntx.recent_idx_list,
                sizeof(U8) * SRV_BT_CM_MAX_USED_DEVICE_LIST);
            WriteRecordSlim(
                NVRAM_EF_BT_DEV_LIST_LID,
                (i + 1),
                &g_srv_bt_cm_cntx.dev_list[i],
                NVRAM_EF_BT_DEV_LIST_SIZE);

            WriteRecordSlim(
                NVRAM_EF_BT_DEV_LIST_INDEX_LID,
                1,
                &dev_list_index_struct,
                NVRAM_EF_BT_DEV_LIST_INDEX_SIZE);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_action_item_index
 * DESCRIPTION
 *  This function is to get action idem index
 * PARAMETERS
 *  void
 * RETURNS
 *  U8      action idem index
 *****************************************************************************/
U8 srv_bt_cm_get_action_item_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_ACTION_ITEM_INDEX,
        g_srv_bt_cm_cntx.action_index);

    return g_srv_bt_cm_cntx.action_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_flag
 * DESCRIPTION
 *  This function is to get flag value
 * PARAMETERS
 *  get_flag        [IN]            the flag
 * RETURNS
 *  U32         flag value
 *****************************************************************************/
U32 srv_bt_cm_get_flag(U32 get_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_FLAG_TRACE,
        get_flag,
        SRV_BT_CM_GET_FLAG(get_flag));

    return SRV_BT_CM_GET_FLAG(get_flag);
}








/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_recover_panic_req
 * DESCRIPTION
 *  This function is to process recover panic request and send MSG_ID_BT_MMI_RESET_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        return TRUE
 *****************************************************************************/
MMI_BOOL srv_bt_cm_recover_panic_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RECOVER_PANIC_REQ);

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_MMI_RESET_REQ, NULL, NULL);
    /* will deal with the response at srv_bt_cm_restart_rsp_hdler() */
    return MMI_TRUE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_open
 * DESCRIPTION
 *  this function is to open a handle, then can call other function with this handle
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************************/
static S32 srv_bt_cm_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_INSTANCE_NUM; ++i)
    {
        if (srv_bt_cm_handle[i].srv_hd == 0)
        {
            return (srv_bt_cm_handle[i].srv_hd = i + 1);
        }
    }

    return SRV_BT_CM_RESULT_FAILED;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_notify
 * DESCRIPTION
 *  this function is to set the notifier for cared event
 * PARAMETERS
 *  srv_hd    :    [IN]
 *  notifier  :    [IN]
 *  event_mask:    [IN]
 *  user_data :    [IN]
 * RETURNS
 *  service handle, if it is less than 0, it means invalid handle
 ******************************************************************************/
S32 srv_bt_cm_set_notify(srv_bt_cm_notifier notifier, U32 event_mask, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 srv_hd;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_hd = srv_bt_cm_open();
    if ((srv_hd > 0) && (srv_hd <= SRV_BT_CM_MAX_INSTANCE_NUM))
    {
        srv_bt_cm_handle[srv_hd - 1].notifier = notifier;
        srv_bt_cm_handle[srv_hd - 1].event_mask = event_mask;
        srv_bt_cm_handle[srv_hd - 1].user_data = user_data;
    }
    else
    {
        srv_hd = SRV_BT_CM_RESULT_INVALID_HANDLE;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_NOTIFY,
        srv_hd);

    return srv_hd;
}


S32 srv_bt_cm_reset_notify(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RESET_NOTIFY,
        srv_hd);

    if ((srv_hd > 0) && (srv_hd <= SRV_BT_CM_MAX_INSTANCE_NUM))
    {
        srv_bt_cm_handle[srv_hd - 1].srv_hd = 0;
        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_INVALID_HANDLE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event    [IN]
 *  para    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
void srv_bt_cm_notify(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_bt_cm_activate_struct* tmp = (srv_bt_cm_activate_struct*)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_NOTIFY,
        event);

    for (i = 0; i < SRV_BT_CM_MAX_INSTANCE_NUM; ++i)
    {
        if ((srv_bt_cm_handle[i].srv_hd > 0) &&
            (srv_bt_cm_handle[i].srv_hd <= SRV_BT_CM_MAX_INSTANCE_NUM))
        {
            if (event & srv_bt_cm_handle[i].event_mask)
            {
                if (srv_bt_cm_handle[i].notifier)
                {
                    tmp->srv_hd = srv_bt_cm_handle[i].srv_hd;
                    tmp->user_data = srv_bt_cm_handle[i].user_data;
                    srv_bt_cm_handle[i].notifier(event, para);
                }
            }
        }
    }
}

void srv_bt_cm_post_notify(U32 evt_id, void *para)
{
    srv_bt_cm_post_event_struct post_event;
    
    MMI_FRM_INIT_EVENT(&post_event, evt_id);
    post_event.event = evt_id;
    post_event.data_p = para;
    mmi_frm_post_event((mmi_event_struct*)&post_event, srv_bt_cm_post_event_proc, NULL);
}

/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_post_event_proc
 * DESCRIPTION
 *  this function si the post event proc function
 * PARAMETERS
 *  para    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
mmi_ret srv_bt_cm_post_event_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_post_event_struct* ind_p = (srv_bt_cm_post_event_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_POST_EVENT_PROC,
        ind_p->event);

    srv_bt_cm_notify(ind_p->event, ind_p->data_p);

    if (ind_p->data_p)
    {
        OslMfree(ind_p->data_p);
    }

    return MMI_RET_OK;
}


U32 srv_bt_cm_get_dev_num(srv_bt_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, total_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dev_type)
    {
        case SRV_BT_CM_DISCOVERED_DEV:
            total_num = g_srv_bt_cm_cntx.discovered_dev_num;
            break;

        case SRV_BT_CM_RECENT_USED_DEV:
            total_num = (U32)g_srv_bt_cm_cntx.recent_dev_num;
            break;

        case SRV_BT_CM_PAIRED_DEV:
            total_num = (U32)g_srv_bt_cm_cntx.paired_dev_num;
            break;

        case SRV_BT_CM_ALL_DEV:
            for (i = 0; i < SRV_BT_CM_MAX_DEVICE_LIST; ++i)
            {
                if (g_srv_bt_cm_cntx.dev_list[i].ref_cnt > 0)
                {
                    ++total_num;
                }
            }
            break;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_NUM,
        dev_type,
        total_num);
    return total_num;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_index
 * DESCRIPTION
 *  this function is to get device index in corresponding device list
 *  according to device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return index in corresponding device list
 *  if failed to find the device, return 0xFFFFFFFF
 ******************************************************************************/
U32 srv_bt_cm_get_dev_index(const srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, idx, total_num = 0;
    U8* idx_list = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_INDEX,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_type);

    if (dev_addr)
    {
        switch (dev_type)
        {
            case SRV_BT_CM_DISCOVERED_DEV:
                for (i = 0; i < g_srv_bt_cm_cntx.discovered_dev_num; ++i)
                {
                    if (srv_bt_cm_is_dev_addr_equal(&g_srv_bt_cm_cntx.discovered_list[i].bd_addr, dev_addr))
                    {
                        MMI_TRACE(
                            MMI_CONN_TRC_G7_BT,
                            SRV_BT_CM_GET_DEV_INDEX_2,
                            i);

                        return i;
                    }
                }
                return 0xFFFFFFFF;

            case SRV_BT_CM_RECENT_USED_DEV:
                total_num = g_srv_bt_cm_cntx.recent_dev_num;
                idx_list = g_srv_bt_cm_cntx.recent_idx_list;
                break;

            case SRV_BT_CM_PAIRED_DEV:
                total_num = g_srv_bt_cm_cntx.paired_dev_num;
                idx_list = g_srv_bt_cm_cntx.paired_idx_list;
                break;

            case SRV_BT_CM_ALL_DEV:
                total_num = SRV_BT_CM_MAX_DEVICE_LIST;
                break;
        }

        for (i = 0; i < total_num; ++i)
        {
            idx = idx_list ? idx_list[i] : i;
            if (srv_bt_cm_is_dev_addr_equal(&g_srv_bt_cm_cntx.dev_list[idx].dev_info.bd_addr, dev_addr) &&
                (g_srv_bt_cm_cntx.dev_list[idx].ref_cnt > 0))
            {
                MMI_TRACE(
                    MMI_CONN_TRC_G7_BT,
                    SRV_BT_CM_GET_DEV_INDEX_2,
                    i);

                return i;
            }
        }
    }
    
    return 0xFFFFFFFF;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_info_by_addr
 * DESCRIPTION
 *  this function is to get the device infomation througth device address
 *  according to the device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return its infomation
 *  if failed to find the device, return NULL
 ******************************************************************************/
const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info_by_addr(
    const srv_bt_cm_bt_addr* dev_addr,
    srv_bt_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_INFO_BY_ADDR,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_type);

i= srv_bt_cm_get_dev_index(dev_addr,dev_type);
if (dev_type==SRV_BT_CM_DISCOVERED_DEV && i!=0xFFFFFFFF)
                    {
                        return &g_srv_bt_cm_cntx.discovered_list[i];
                    }
else if (i!=0xFFFFFFFF)
        {
	return &g_srv_bt_cm_cntx.dev_list[i].dev_info;
        }

        if (dev_type == SRV_BT_CM_ALL_DEV)
            return srv_bt_cm_get_dev_info_by_addr(dev_addr, SRV_BT_CM_DISCOVERED_DEV);
    return NULL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_info_by_index
 * DESCRIPTION
 *  this function is to get device info 
 * PARAMETERS
 *  index   :    [IN]    device index
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return its infomation
 *  if failed to find the device, return NULL
 ******************************************************************************/
const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info_by_index(U32 index, srv_bt_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0xFFFFFFFF;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_DEV_INFO_BY_INDEX,
        index,
        dev_type);

    switch (dev_type)
    {
        case SRV_BT_CM_DISCOVERED_DEV: /* can't deal with this case */
            return (const srv_bt_cm_dev_struct*)srv_bt_cm_get_searched_dev_info(index);

        case SRV_BT_CM_RECENT_USED_DEV:
            if (index < g_srv_bt_cm_cntx.recent_dev_num)
            {
                i = g_srv_bt_cm_cntx.recent_idx_list[index];
            }
            break;

        case SRV_BT_CM_PAIRED_DEV:
            if (index < g_srv_bt_cm_cntx.paired_dev_num)
            {
                i = g_srv_bt_cm_cntx.paired_idx_list[index];
            }
            break;

        case SRV_BT_CM_ALL_DEV: /* can't deal with this case */
            i = index;
            break;
    }

    return (i < SRV_BT_CM_MAX_DEVICE_LIST)?
        &g_srv_bt_cm_cntx.dev_list[i].dev_info :
        NULL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_dev_add_int
 * DESCRIPTION
 *  this function is to add a device into corresponding device list
 *  according to device type
 * PARAMETERS
 *  dev     :    [IN]    device
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_bt_cm_dev_add_int(const srv_bt_cm_dev_struct* dev, srv_bt_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k, temp;
    S32 result = SRV_BT_CM_RESULT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_ADD_INT,
        ((dev->bd_addr.nap & 0xff00) >> 8),
        (dev->bd_addr.nap & 0x00ff),
        (dev->bd_addr.uap),
        ((dev->bd_addr.lap & 0xff0000) >> 16),
        ((dev->bd_addr.lap & 0x00ff00) >> 8),
        (dev->bd_addr.lap & 0x0000ff),
        dev_type,
        g_srv_bt_cm_cntx.recent_dev_num,
        g_srv_bt_cm_cntx.paired_dev_num,
        dev->name);

    ASSERT(!((dev->bd_addr.lap == 0) &&
             (dev->bd_addr.uap == 0) &&
             (dev->bd_addr.nap == 0)));
    if (dev)
    {
        switch (dev_type)
        {
            case SRV_BT_CM_DISCOVERED_DEV:
                break;

            case SRV_BT_CM_RECENT_USED_DEV:
                i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&dev->bd_addr, SRV_BT_CM_RECENT_USED_DEV);
                if (i >= g_srv_bt_cm_cntx.recent_dev_num) /* not in recent list */
                {
                    /* release the recent device before add new one */
                    if (g_srv_bt_cm_cntx.recent_dev_num >= SRV_BT_CM_MAX_USED_DEVICE_LIST)
                    {
                        const srv_bt_cm_dev_struct* tmp_dev_info = srv_bt_cm_get_dev_info_by_index(
                            g_srv_bt_cm_cntx.recent_dev_num - 1,
                            SRV_BT_CM_RECENT_USED_DEV);
                        if (tmp_dev_info)
                        {
                            srv_bt_cm_dev_delete_int(
                                (const srv_bt_cm_bt_addr*)&tmp_dev_info->bd_addr,
                                SRV_BT_CM_RECENT_USED_DEV);
                        }
                    }
                    MMI_ASSERT(g_srv_bt_cm_cntx.recent_dev_num < SRV_BT_CM_MAX_USED_DEVICE_LIST);

                    j = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&dev->bd_addr, SRV_BT_CM_ALL_DEV);
                    if (j >= SRV_BT_CM_MAX_DEVICE_LIST) /* not in database */
                    {
                        for (j = 0; j < SRV_BT_CM_MAX_DEVICE_LIST; ++j)
                        {
                            if (g_srv_bt_cm_cntx.dev_list[j].ref_cnt == 0)
                            {
                                memcpy(
                                    &g_srv_bt_cm_cntx.dev_list[j].dev_info,
                                    dev,
                                    sizeof(srv_bt_cm_dev_struct));
                                /* if not reach max value, add recent device number */
                                if (g_srv_bt_cm_cntx.recent_dev_num < SRV_BT_CM_MAX_USED_DEVICE_LIST)
                                {
                                    ++g_srv_bt_cm_cntx.recent_dev_num;
                                }

                                for (k = g_srv_bt_cm_cntx.recent_dev_num; k > 0; --k)
                                {
                                    g_srv_bt_cm_cntx.recent_idx_list[k] = g_srv_bt_cm_cntx.recent_idx_list[k - 1];
                                }
                                g_srv_bt_cm_cntx.recent_idx_list[k] = j;
                                ++g_srv_bt_cm_cntx.dev_list[j].ref_cnt;
                                break;
                            }
                        }

                        MMI_BT_ASSERT(j < SRV_BT_CM_MAX_DEVICE_LIST);
                    }
                    else /* already in database, just add to recent list */
                    {
                        if ((g_srv_bt_cm_cntx.dev_list[j].dev_info.attribute &
                             SRV_BT_CM_DEVICE_ATTRIBUTE_USER_DEFINED_NAME) == 0)
                        {
                            memcpy(
                                &g_srv_bt_cm_cntx.dev_list[j].dev_info,
                                dev,
                                sizeof(srv_bt_cm_dev_struct));
                        }
                        else
                        {
                            g_srv_bt_cm_cntx.dev_list[j].dev_info.cod = dev->cod;
                            g_srv_bt_cm_cntx.dev_list[j].dev_info.service_list_num = dev->service_list_num;
                            memcpy(
                                g_srv_bt_cm_cntx.dev_list[j].dev_info.service_list,
                                dev->service_list,
                                SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE);
                        }

                        if (g_srv_bt_cm_cntx.recent_dev_num < SRV_BT_CM_MAX_USED_DEVICE_LIST)
                        {
                            ++g_srv_bt_cm_cntx.recent_dev_num;
                        }

                        for (k = g_srv_bt_cm_cntx.recent_dev_num; k > 0; --k)
                        {
                            g_srv_bt_cm_cntx.recent_idx_list[k] = g_srv_bt_cm_cntx.recent_idx_list[k - 1];
                        }
                        g_srv_bt_cm_cntx.recent_idx_list[k] = j;
                        ++g_srv_bt_cm_cntx.dev_list[j].ref_cnt;
                    }
                }
                else /* adjust the sequence */
                {
                    temp = g_srv_bt_cm_cntx.recent_idx_list[i]; /* remember temp index */
                    if ((g_srv_bt_cm_cntx.dev_list[temp].dev_info.attribute &
                         SRV_BT_CM_DEVICE_ATTRIBUTE_USER_DEFINED_NAME) == 0)
                    {
                        memcpy(
                            &g_srv_bt_cm_cntx.dev_list[temp].dev_info,
                            dev,
                            sizeof(srv_bt_cm_dev_struct));
                    }
                    else
                    {
                        g_srv_bt_cm_cntx.dev_list[temp].dev_info.cod = dev->cod;
                        g_srv_bt_cm_cntx.dev_list[temp].dev_info.service_list_num = dev->service_list_num;
                        memcpy(
                            g_srv_bt_cm_cntx.dev_list[temp].dev_info.service_list,
                            dev->service_list,
                            SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE);
                    }
                    
                    for (k = i; k > 0; --k)
                    {
                        g_srv_bt_cm_cntx.recent_idx_list[k] = g_srv_bt_cm_cntx.recent_idx_list[k - 1];
                    }
                    g_srv_bt_cm_cntx.recent_idx_list[k] = temp;
                }
                //result = SRV_BT_CM_RESULT_SUCCESS;
                break;

            case SRV_BT_CM_PAIRED_DEV:
                srv_bt_cm_dev_add_int(dev, SRV_BT_CM_RECENT_USED_DEV);
                i = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&(dev->bd_addr), SRV_BT_CM_PAIRED_DEV);
                if (i >= g_srv_bt_cm_cntx.paired_dev_num) /* not in paired list */
                {
                    j = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr*)&(dev->bd_addr), SRV_BT_CM_ALL_DEV); /* already in database */
                    if (g_srv_bt_cm_cntx.paired_dev_num < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST) /* can add into paired list */
                    {
                        g_srv_bt_cm_cntx.paired_idx_list[g_srv_bt_cm_cntx.paired_dev_num] = j;
                        ++g_srv_bt_cm_cntx.paired_dev_num;
                        ++g_srv_bt_cm_cntx.dev_list[j].ref_cnt;
                    }
                    else /* exceed max value */
                    {
                        result = SRV_BT_CM_RESULT_FAILED;
                    }
                }
                break;



        }
    
        srv_bt_cm_nvram_write_info(
            NVRAM_EF_BT_DEV_LIST_LID,
            (void*)srv_bt_cm_get_dev_index(
                (const srv_bt_cm_bt_addr*)&dev->bd_addr,
                SRV_BT_CM_ALL_DEV));
    }
    else
    {
        result = SRV_BT_CM_RESULT_FAILED;
    }
    
#ifdef __SRV_BT_CM_DEBUG_INTENAL__
    for (i = 0; i < SRV_BT_CM_MAX_DEVICE_LIST; ++i)
    {
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_DEV_ADD_INT_2,
            i,
            ((g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.nap & 0xff00) >> 8),
            (g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.nap & 0x00ff),
            (g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.uap),
            ((g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.lap & 0xff0000) >> 16),
            ((g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.lap & 0x00ff00) >> 8),
            (g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.lap & 0x0000ff),
            g_srv_bt_cm_cntx.dev_list[i].ref_cnt);
    }
    for (i = 0; i < g_srv_bt_cm_cntx.recent_dev_num; ++i)
    {
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_DEV_ADD_INT_3,
            g_srv_bt_cm_cntx.recent_dev_num,
            i,
            g_srv_bt_cm_cntx.recent_idx_list[i]);
    }
    for (i = 0; i < g_srv_bt_cm_cntx.paired_dev_num; ++i)
    {
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_DEV_ADD_INT_4,
            g_srv_bt_cm_cntx.paired_dev_num,
            i,
            g_srv_bt_cm_cntx.paired_idx_list[i]);
    }
#endif  // __SRV_BT_CM_DEBUG_INTENAL__

    return result;
}

#if defined(__MMI_HIDD_SUPPORT__)
/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_dev_is_support_hid
 * DESCRIPTION
 *  this function is to check if the remote device support hid profile or not.
 * 
 * PARAMETERS
 *  dev_p     :    [IN]    remote device infomation struct.
 *  
 * RETURNS
 *  
 ******************************************************************************/
MMI_BOOL srv_bt_cm_dev_is_support_hid(srv_bt_cm_dev_struct *dev_p)
{

	if (dev_p->attribute & SRV_BT_CM_DEVICE_ATTRIBUTE_HIDD)
		return MMI_TRUE;
	else
		return MMI_FALSE;
}

#endif /*defined(__MMI_HIDD_SUPPORT__)*/
/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_dev_delete_int
 * DESCRIPTION
 *  this function is to delete a device according to device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  S32 return the delete device result
 ******************************************************************************/
S32 srv_bt_cm_dev_delete_int(const srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, temp = 0;
    S32 result = SRV_BT_CM_RESULT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dev_type)
    {

        case SRV_BT_CM_RECENT_USED_DEV:
            i = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_RECENT_USED_DEV);
            if (i < g_srv_bt_cm_cntx.recent_dev_num)
            {
                temp = g_srv_bt_cm_cntx.recent_idx_list[i];
                for (j = i; j < g_srv_bt_cm_cntx.recent_dev_num - 1; ++j)
                {
                    g_srv_bt_cm_cntx.recent_idx_list[j] = g_srv_bt_cm_cntx.recent_idx_list[j + 1];
                }

                --g_srv_bt_cm_cntx.recent_dev_num;
                --g_srv_bt_cm_cntx.dev_list[temp].ref_cnt;
                if (g_srv_bt_cm_cntx.dev_list[temp].ref_cnt == 0)
                {
                    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
                    {
                        if (g_srv_bt_cm_cntx.existed_conn[i].index_of_dev_list == temp)
                        {
                            memset(&g_srv_bt_cm_cntx.existed_conn[i], 0, sizeof(srv_bt_cm_connect_struct));
                            break;
                        }
                    }

                    memset(
                        &g_srv_bt_cm_cntx.dev_list[temp].dev_info,
                        0,
                        sizeof(srv_bt_cm_dev_struct));
                }
            }
            else
            {
                result = SRV_BT_CM_RESULT_FAILED;
            }
            break;

        case SRV_BT_CM_PAIRED_DEV:
            i = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_PAIRED_DEV);
            if (i < g_srv_bt_cm_cntx.paired_dev_num)
            {
                temp = g_srv_bt_cm_cntx.paired_idx_list[i];

#if defined(__MMI_HIDD_SUPPORT__)
                {
                    U32 last_hid_dev_idx;
                    
                    last_hid_dev_idx = g_srv_bt_cm_cntx.idx_of_last_hid_dev;
                    if (last_hid_dev_idx < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
                        last_hid_dev_idx == temp)
                    {
                        g_srv_bt_cm_cntx.idx_of_last_hid_dev = 0xFFFFFFFF;
                        //mmi_bth_hidd_clear_last_dev_info();
                    }
                }
#endif

#ifdef __MMI_HFP_SUPPORT__
                {
                    srv_bt_cm_bt_addr* addr = (srv_bt_cm_bt_addr*)srv_bthf_read_config(BTHF_CFG_DEF_DEVICE);
                    if (srv_bt_cm_is_dev_addr_equal(addr, dev_addr))
                    {
                        srv_bthf_save_config(BTHF_CFG_DEF_DEVICE, NULL);
                    }
                }
#endif /* __MMI_HFP_SUPPORT__ */
                
                for (j = i; j < g_srv_bt_cm_cntx.paired_dev_num - 1; ++j)
                {
                    g_srv_bt_cm_cntx.paired_idx_list[j] = g_srv_bt_cm_cntx.paired_idx_list[j + 1];
                }

                --g_srv_bt_cm_cntx.paired_dev_num;
                --g_srv_bt_cm_cntx.dev_list[temp].ref_cnt;
				
#if defined(__MMI_HIDD_SUPPORT__)												
				g_srv_bt_cm_cntx.dev_list[temp].dev_info.attribute &= SRV_BT_CM_DEVICE_ATTRIBUTE_HIDD;
#else /*defined(__MMI_HIDD_SUPPORT__)*/
                g_srv_bt_cm_cntx.dev_list[temp].dev_info.attribute = 0;
#endif /*defined(__MMI_HIDD_SUPPORT__)*/

                if (g_srv_bt_cm_cntx.dev_list[temp].ref_cnt == 0)
                {
                    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
                    {
                        if (g_srv_bt_cm_cntx.existed_conn[i].index_of_dev_list == temp)
                        {
                            memset(&(g_srv_bt_cm_cntx.existed_conn[i]), 0, sizeof(srv_bt_cm_connect_struct));
                            break;
                        }
                    }

                    memset(
                        &g_srv_bt_cm_cntx.dev_list[temp].dev_info,
                        0,
                        sizeof(srv_bt_cm_dev_struct));

                }
            }
            else
            {
                result = SRV_BT_CM_RESULT_FAILED;
            }
            break;

        case SRV_BT_CM_ALL_DEV:
            i = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_PAIRED_DEV);
            if (i < SRV_BT_CM_MAX_DEVICE_LIST)
            {
                temp = i;
                srv_bt_cm_dev_delete_int(dev_addr, SRV_BT_CM_RECENT_USED_DEV);
                srv_bt_cm_dev_delete_int(dev_addr, SRV_BT_CM_PAIRED_DEV);
            }
            else
            {
                result = SRV_BT_CM_RESULT_FAILED;
            }
            break;
    }

    if (result == SRV_BT_CM_RESULT_SUCCESS)
    {
        srv_bt_cm_nvram_write_info(NVRAM_EF_BT_DEV_LIST_LID, (void*)temp);
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DEV_DELETE_INT,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_type,
        result);

    return result;
}

#ifdef __BT_AUTO_DETECT_SUPPORT__
U32 srv_bt_chip_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CHIP_AVAILABLE,
        g_srv_bt_cm_cntx.chip_avail);

    return (g_srv_bt_cm_cntx.chip_avail) ? 1 : 0;
}


static void chip_detect_cnf_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_detect_chip_cnf_struct *cnf = (bt_detect_chip_cnf_struct *)arg;
    srv_bt_cm_chip_detect_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_bt_cm_cntx.chip_avail = cnf->result ? 1 : 0;
    para.result = g_srv_bt_cm_cntx.chip_avail;
    srv_bt_cm_notify(SRV_BT_CM_EVENT_CHIP_DETECT, (void*)&para);

    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_DETECT_CHIP_CNF, NULL);
}


static void srv_bt_cm_check_chip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_DETECT_CHIP_CNF,
        chip_detect_cnf_hdlr,
        MMI_FALSE);

    srv_bt_cm_send_msg(
        MOD_BT,
        BT_APP_SAP,
        MSG_ID_BT_DETECT_CHIP_REQ,
        NULL,
        NULL);
}
#endif  // __BT_AUTO_DETECT_SUPPORT__


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_profile_register
 * DESCRIPTION
 *  this function is to register profile info to CM service
 * PARAMETERS
 *  profile_info_p:    [IN]    profile info
 *  
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL srv_bt_cm_profile_register(const srv_bt_cm_profile_struct* profile_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_PROFILE_REGISTER,
        profile_info_p->profile_id);

    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if ((g_srv_bt_cm_profile_tbl[i].profile_id == 0) ||
            (g_srv_bt_cm_profile_tbl[i].profile_id == profile_info_p->profile_id))
        {
            if (g_srv_bt_cm_profile_tbl[i].profile_id == 0)
            {
                ++g_srv_bt_cm_cntx.host_dev.service_list_num;
            }

            g_srv_bt_cm_profile_tbl[i].profile_id = profile_info_p->profile_id;
            g_srv_bt_cm_profile_tbl[i].activater = profile_info_p->activater;
            g_srv_bt_cm_profile_tbl[i].deactivater = profile_info_p->deactivater;
            g_srv_bt_cm_profile_tbl[i].disconnector = profile_info_p->disconnector;
            g_srv_bt_cm_profile_tbl[i].deactivate_flag = 1 << i;
            g_srv_bt_cm_cntx.host_dev.service_list[i] = profile_info_p->profile_id;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_profile_deregister
 * DESCRIPTION
 *  this function is to deregister profile
 * PARAMETERS
 *  profile_id:    [IN]    profile ID
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_bt_cm_profile_deregister(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_PROFILE_DEREGISTER,
        profile_id);

    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if (g_srv_bt_cm_profile_tbl[i].profile_id == profile_id)
        {
            memset(
                &g_srv_bt_cm_profile_tbl[i],
                0,
                sizeof(srv_bt_cm_profile_struct_int));
            --g_srv_bt_cm_cntx.host_dev.service_list_num;
            break;
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_is_dev_addr_equal
 * DESCRIPTION
 *  this function is used to judge whether two bluetooth address is equal
 * PARAMETERS
 *  dev_addr1    [IN]    device address
 *  dev_addr2    [IN]    device address
 *  
 * RETURNS
 *  MMI_TRUE : two device address is equal
 *  MMI_FALSE: two device address is not equal
 ******************************************************************************/
MMI_BOOL srv_bt_cm_is_dev_addr_equal(const srv_bt_cm_bt_addr* dev_addr1, const srv_bt_cm_bt_addr* dev_addr2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_addr1 && dev_addr2)
    {
        if ((dev_addr1->lap == dev_addr2->lap) &&
            (dev_addr1->uap == dev_addr2->uap) &&
            (dev_addr1->nap == dev_addr2->nap))
        {
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
}

#endif  /* __MMI_BT_SUPPORT__ */
