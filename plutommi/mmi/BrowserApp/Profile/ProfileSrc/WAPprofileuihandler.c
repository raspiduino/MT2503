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
 * Author: Ramneek Kalra
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#ifdef __MMI_WAP_PROF__

//#include "ServiceDefs.h"
//#include "CommonScreens.h"

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
//------------------------------ usage ------------------------------

//#include "CentralConfigAgentResDef.h"
//#include "CentralConfigAgentGProt.h"
//#include "DataAccountGProt.h"
//#include "Wap_ps_struct.h"
//#include "custom_nvram_editor_data_item.h"
//#include "NetworkSetupDefs.h"
//#include "Nvram_enums.h"
//#include "ConnectManageGprot.h"
//#include "SettingProfile.h"     /* Error tones */
//#include "ProfileGprots.h"      /* Orange sound */
#include "custom_events_notify.h"       /* Orange sound */

//#include "WAPProfConfig.h"
#include "WAPProfileType.h"
#include "WAPProfResDef.h"
#include "mmi_rp_app_mmi_wap_prof_def.h"
#include "WAPProfileProt.h"
//#include "WAPProfileGProt.h"


//#include "Abm_soc_enums.h"


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
mmi_ret mmi_wap_prof_proc(mmi_event_struct* evt)
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
           //  mmi_wap_prof_grp_id = GRP_ID_INVALID;
            mmi_frm_group_close(MMI_WAP_PROF_PROGRESS_GRP_ID);  
              break;

    }

    return MMI_RET_OK;
}







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
void mmi_wap_prof_ui_entry_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (GetActiveScreenId() == SCR_ID_WAP_PROF_PLEASE_WAIT)
    if(SCR_ID_WAP_PROF_PLEASE_WAIT ==	mmi_frm_scrn_get_active_id() )
    {
        return;
    }

//10A DA critical:  check screen ids....

    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_ENTRY_BUSY_SCREEN);

	mmi_frm_group_create(GRP_ID_ROOT, MMI_WAP_PROF_PROGRESS_GRP_ID, mmi_wap_prof_proc, NULL);

	mmi_frm_group_enter(MMI_WAP_PROF_PROGRESS_GRP_ID , MMI_FRM_NODE_SMART_CLOSE_FLAG);

    

   // EntryNewScreen(SCR_ID_WAP_PROF_PLEASE_WAIT, NULL, mmi_wap_prof_ui_entry_progress_screen, NULL);
    if (!mmi_frm_scrn_enter(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT, NULL, mmi_wap_prof_ui_entry_progress_screen, 0))
    {
        return;
    }
    //guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_PROF_PLEASE_WAIT);
   	guiBuffer = mmi_frm_scrn_get_gui_buf (MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT);

    //DeleteScreenIfPresent(SCR_ID_WAP_PROF_PLEASE_WAIT);
    
    if(SCR_ID_WAP_PROF_PLEASE_WAIT !=	mmi_frm_scrn_get_active_id() )
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_WAP_PROF_PLEASE_WAIT);


    ShowCategory66Screen(
        STR_GLOBAL_DATA_ACCOUNT,
        g_mmi_wap_prof_cntx.titlebar_icon_id,
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
void mmi_wap_prof_ui_display_popup(U16 action, 
                                   mmi_wap_prof_result_enum result, 
                                   MMI_BOOL use_action_as_string_id, 
                                   FuncPtr popup_end_callback,
                                   FuncPtr popup_exit_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = action;

    custom_event_notiy_enum event_id = result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

        /* treat action as string id. */
        if (MMI_WAP_PROF_ERR == result)
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


    if (mmi_wap_prof_check_is_call_screen_active() == MMI_FALSE)
    {

      
        mmi_popup_display_simple((WCHAR*)GetString(string_id), event_id, GRP_ID_ROOT, NULL);
    }

}
#endif /* __MMI_WAP_PROF__ */
