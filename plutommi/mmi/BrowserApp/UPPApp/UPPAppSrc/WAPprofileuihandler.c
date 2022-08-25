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
 * WAPProfileUIHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the UPP profile module.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "GlobalResDef.h"
#ifdef WAP_SUPPORT

//------------------------------ suggest Add ------------------------------

#include "mmi_frm_scenario_gprot.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "custom_events_notify.h"
//------------------------------ usage ------------------------------


#include "WAPProfileSrvType.h"
#include "WAPProfResDef.h"
#include "mmi_rp_app_mmi_wap_prof_def.h"
#include "WAPProfileSrvProt.h"
#include "WAPProfileProt.h"






/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_cui_proc
 * DESCRIPTION
 *  Proc function for Data account CUI.
 * PARAMETERS
 *  mmi_event_struct*                    [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_prof_app__proc(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


   
    switch(evt->evt_id)
    {

		 case EVT_ID_GROUP_DEINIT:
               mmi_frm_group_close(MMI_WAP_PROF_PROGRESS_GRP_ID);  
              break;

    }

    return MMI_RET_OK;
}

#ifndef __SRV_UPP_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_ui_entry_progress_screen
 * DESCRIPTION
 *  Entry Progressing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_app_ui_entry_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if(SCR_ID_WAP_PROF_PLEASE_WAIT ==	mmi_frm_scrn_get_active_id() )
    {
        return;
    }


	mmi_frm_group_create(GRP_ID_ROOT, MMI_WAP_PROF_PROGRESS_GRP_ID, mmi_wap_prof_app__proc, NULL);

	mmi_frm_group_enter(MMI_WAP_PROF_PROGRESS_GRP_ID , MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!mmi_frm_scrn_enter(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT, NULL, mmi_wap_prof_app_ui_entry_progress_screen, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
   	guiBuffer = mmi_frm_scrn_get_gui_buf (MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT);

    //DeleteScreenIfPresent(SCR_ID_WAP_PROF_PLEASE_WAIT);
    
    if(SCR_ID_WAP_PROF_PLEASE_WAIT !=	mmi_frm_scrn_get_active_id() )
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_WAP_PROF_PLEASE_WAIT);


    ShowCategory66Screen(
        STR_GLOBAL_DATA_ACCOUNT,
        g_srv_wap_prof_cntx.titlebar_icon_id,
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
/*        IMG_GLOBAL_PROGRESS, Popup rule */
        mmi_get_event_based_image(MMI_EVENT_PROGRESS), /* Popup rule */
        guiBuffer);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_ui_display_popup
 * DESCRIPTION
 *  It is a centralised API for displaying popup. If action is not a standard action enum
 *  then action is treated as string id for popup.
 * PARAMETERS
 *  action                      [IN]        
 *  result                      [IN]        
 *  use_action_as_string_id     [IN]
 *  popup_end_callback          [IN]
 *  popup_exit_callback         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_app_ui_display_popup(U16 action, 
                                   srv_wap_prof_result_enum result, 
                                   MMI_BOOL use_action_as_string_id, 
                                   FuncPtr popup_end_callback,
                                   FuncPtr popup_exit_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = action;

    mmi_event_notify_enum event_id = MMI_EVENT_INFO;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

        /* treat action as string id. */
        if (SRV_WAP_PROF_ERR == result)
        {
            string_id = action;

            if (action == STR_GLOBAL_NOT_AVAILABLE) /* Global string usage */
            {
                event_id = MMI_EVENT_PROPLEM;
            }
            else
            {
           
                event_id = MMI_EVENT_ERROR;
            }

    }


   // if (srv_wap_prof_check_is_call_screen_active() == MMI_FALSE)
    //{

      
        //mmi_popup_display_simple((WCHAR*)GetString(string_id), event_id, GRP_ID_ROOT, NULL);
		mmi_confirm_display_ext((MMI_STR_ID)string_id, event_id, NULL);
    //}

}
#endif /* WAP_SUPPORT */
