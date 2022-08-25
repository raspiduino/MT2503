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
 * BTdialerApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_inputs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "app_buff_alloc.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_pluto_res_range_def.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_rp_app_bt_dialer_def.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "mmi_frm_input_gprot.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#if defined(__MMI_A2DP_SUPPORT__)
#include "A2dpSrvGprot.h"
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
#include "BTMMIScr.h"
#include "BTdialerApp.h"
#include "BTConnScr.h"
extern MMI_BOOL srv_bt_dialer_vol_control_callback(U8 volume, MMI_BOOL is_mute);
/*  Include: MMI header file */
/*****************************************************************************
 * FUNCTION
 *  mmi_btdialer_app_launch_func
 * DESCRIPTION
 *  This function is to activate or deactivate bt dialer
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btdialer_app_launch_func(void* param, U32 param_size)
		{
		    mmi_btdialer_launch_func();
		}
void mmi_btdialer_app_emit_event_to_ucm_app(MMI_BOOL event_type)
{
	if(event_type)
		BT_Dialer_app_emit_event(EVT_ID_DIALER_EVENT_ID,NULL);
	else
		BT_Dialer_app_emit_event(EVT_ID_BT_DIALER_DISCONN_EVENT_ID,NULL);
}

void mmi_btdialer_launch_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_DIALER_APP_LAUNCH);
	srv_bt_cm_set_btdialor_app_mode(MMI_TRUE);
		mmi_bt_entry_main_menu_bt_dialer();
}
/*****************************************************************************
 * FUNCTION
 *  BT_Dialer_app_emit_event
 * DESCRIPTION
 *  This function is to activate or deactivate bt dialer
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void BT_Dialer_app_emit_event(U32 event_id, void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_event_struct event_data;
			 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_DIALER_APP_EMIT_EVENT_TO_UCM,event_id);
	MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;

    MMI_FRM_CB_EMIT_EVENT(&event_data);
}


void BT_Music_app_emit_event(U32 event_id, void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_ct_event_struct event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;

    MMI_FRM_CB_EMIT_EVENT(&event_data);
 }
 
 
 /*****************************************************************************
 * FUNCTION
 *  mmi_btdialer_cm_app_exit_func
 * DESCRIPTION
 *  This function is to activate or deactivate bt dialer
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btdialer_cm_app_exit_func()
 {
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_DIALER_APP_EXIT_FUNC);
	#ifdef __BT_SPK_VOL_CONTROL__
	mdi_audio_bt_clear_volume_sync_callback(APP_BT_DIALER);  //Clear Vol callback
	#endif //__BT_SPK_VOL_CONTROL__
 }

 
#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  mmi_btdialer_app_emit_timeout_event
 * DESCRIPTION
 *  This function is to emit bt acl disconnect eventr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btdialer_app_emit_timeout_event()
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	BT_Dialer_app_emit_event(EVT_ID_BT_DIALER_ACL_DISCONN_EVENT_ID,NULL);
}
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/

#endif //__MMI_BT_DIALER_SUPPORT__

