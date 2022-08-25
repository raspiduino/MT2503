/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * PhnsetDlCalData.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for launcher switch setting
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/* MMI standard headers */
#include "MMI_features.h"

#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
/* UI */
#include "menucuigprot.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "mmi_rp_app_setting_menu_effect_def.h"
#include "IdleGprot.h"
#include "PhnsetDlCalDataGprot.h"
#include "mmi_msg_struct.h"
/*TEMP imgage resource.*/
#include "mmi_rp_app_setting_download_cal_data_def.h"
/* Device headers */

#ifdef __MMI_TELEPHONY_SUPPORT__
/***************************************************************************** 
* Local Functions
*****************************************************************************/
static MMI_RET mmi_phnset_dl_data_is_invalid_confirm_cb(mmi_event_struct *evt);
static void mmi_phnset_dl_data_get_status_rsp(void *msg, int mod_id);


/***************************************************************************** 
* local define
*****************************************************************************/


/***************************************************************************** 
* Local Varibles
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dl_data_is_invalid_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt:        [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
MMI_RET mmi_phnset_dl_data_is_invalid_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phnset_cal_data_notify_event_struct *cal_event = (mmi_phnset_cal_data_notify_event_struct *)evt;
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!cal_event->cal_data_valid)
	{
		mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
		arg.callback = (mmi_proc_func) mmi_phnset_dl_data_is_invalid_confirm_cb;
		arg.parent_id = GRP_ID_ROOT;
		
		mmi_confirm_display_ext(STR_ID_PHNSET_DOWNLOAD_DATA_INVALID, MMI_EVENT_QUERY, &arg);
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dl_data_is_invalid_confirm_cb
 * DESCRIPTION
 *  Confirm popup proc function
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_phnset_dl_data_is_invalid_confirm_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_alert_result_evt_struct *alert_event = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (alert_event->result)
        {
        case MMI_ALERT_CNFM_OK:
           mmi_frm_scrn_close_active_id();
		   break;  

		default:			
			break;
        }
	}
	return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  ATSetProfileHandler
 * DESCRIPTION
 *  AT command set profile
 * PARAMETERS
 *  msg     [?]     Wall paper/tone/home city/theme/short cut setting request
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_dl_data_get_status_rsp(void *msg, int mod_id)
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_eq_query_cal_data_dl_status_rsp_struct *dl_msg = (mmi_eq_query_cal_data_dl_status_rsp_struct*)msg;

	mmi_phnset_cal_data_notify_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&event, EVT_ID_MMI_DL_CAL_DATA_NOTIFY);
	event.cal_data_valid= dl_msg->cal_data_valid;
	MMI_FRM_CB_EMIT_EVENT(&event);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_download_cal_data_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt:        [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_download_cal_data_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    SetProtocolEventHandler(mmi_phnset_dl_data_get_status_rsp, MSG_ID_MMI_EQ_QUERY_CAL_DATA_DL_STATUS_RSP);
	
	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_QUERY_CAL_DATA_DL_STATUS_REQ, NULL, NULL);
	
    return MMI_RET_OK;
}
#endif

