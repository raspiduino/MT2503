/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * q03c_mms_v01_agentUtils.c
 *
 * Project:
 * --------
 * MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(OBIGO_Q03C_MMS_V01)

#include "mmi_frm_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreens.h"
#include "q03c_mms_V01_agentprot.h"
#include "q03c_mms_V01_agentResDef.h"
#include "mea_api.h"
#include "UCMsrvgprot.h"




/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_not_ready_goback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mmsv01_not_ready_goback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_exit_wap_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mmsv01_agent_exit_wap_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer((U16) MMSV01_AGENT_WAP_NOT_READY_TIMER_ID);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_wap_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_wap_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_WAP_NOT_READY);

    // WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());*/

    EntryNewScreen(SCR_ID_MMSV01_AGENT_WAP_NOT_READY, mmi_mmsv01_agent_exit_wap_not_ready, NULL, NULL);

    StartTimer((U16) MMSV01_AGENT_WAP_NOT_READY_TIMER_ID, 2000, mmi_mmsv01_not_ready_goback_hdlr);
    ShowCategory66Screen(
        (U16) MEA_STR_ID_MMS,
        (U16) MEA_IMG_TITLE_NORMAL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_get_error_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error   [IN]
 * RETURNS
 *  string id
 *****************************************************************************/
kal_int32 mmi_mmsv01_agent_get_error_string(kal_uint8 error)
{
	kal_uint32 strid = 0;
	switch (error)
	{
		case MEA_RESULT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL:
			strid = STR_ID_MMSV01_AGENT_STORAGE_FULL;
			break;

		case MEA_RESULT_RESIZING_FAILED_RESOURCES_EXHAUSTED:
			strid = STR_ID_MMSV01_AGENT_FAILED_RESOURCES_EXHAUSTED;
			break;

		case MEA_RESULT_FAILED_FILE_CORRUPT:
			strid = STR_ID_MMSV01_AGENT_FAILED_FILE_CORRUPT;
			break;

		case MEA_RESULT_RESIZING_FAILED:
			strid = STR_ID_MMSV01_AGENT_FAILED_TO_RESIZE_IMAGE;
			break;

		case MEA_RESULT_FAILED_EMPTY_OBJECT:
			strid = STR_ID_MMSV01_AGENT_FAILED_TO_ADD_EMPTY_OBJECT;
			break;

		case MEA_RESULT_FAILED_MESSAGE_SIZE_MAXIMUM_REACHED:
			strid = STR_ID_MMSV01_AGENT_FAILED_MESSAGE_SIZE_MAXIMUM_REACHED;
			break;

		case MEA_RESULT_FAILED_DRM_LOCKED_OBJECT:
			strid = STR_ID_MMSV01_AGENT_FAILED_TO_INSERT_DRM;
			break;

		case MEA_RESULT_FAILED_STORAGE_FULL:
			strid = STR_ID_MMSV01_AGENT_STORAGE_FULL;
			break;

		default:
			strid = STR_GLOBAL_UNFINISHED;  /* Set some default string here */
	}

	return strid;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_check_popup
 * DESCRIPTION
 *  check the popup display
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_mmsv01_agent_check_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pp_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pp_flag = GetInterruptPopupDisplay();
    if ((pp_flag & POPUP_DSPL_ON) == 0 || 
        srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)

    {
        /*Rahul:- Add log here*/
        return FALSE;
    }
		

   
    /*Rahul:- Add log here*/
    return TRUE;
}


void mmi_mmsv01_agent_display_confirm(
        U16 LSK_str,
        U16 LSK_img,
        U16 RSK_str,
        U16 RSK_img,
        U16* msg_string,
        U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_display_popup_confirm(
		(UI_string_type) GetString(LSK_str),
 		(PU8) GetImage(LSK_img), 
		(UI_string_type)GetString(RSK_str), 
		(PU8) GetImage(RSK_img),
 		(UI_string_type) msg_string,
 		(mmi_event_notify_enum) event_id);
}

#endif /* defined(OBIGO_Q03C_MMS_V01) */ 
