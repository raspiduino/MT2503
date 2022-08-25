
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
 * IndianCalendar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is implements Indian Calendar application.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *============================================================================== 
 *******************************************************************************/
     
#include "MMI_features.h"
     
#ifdef __MMI_INDICAL__
#include "app_datetime.h"
#include "mmi_rp_app_sms_def.h"
#include "Mmi_rp_app_calendar_def.h"
#include "CalendarProt.h"
//#include "SimDetectionGprot.h"	
#include "SmsAppGprot.h"	
#ifdef WAP_SUPPORT
#endif /* WAP_SUPPORT */
#include "EmailAppGProt.h"
#ifdef MMS_SUPPORT
#endif /* MMS_SUPPORT */

#include "IndianCalendarProt.h"
#include "IndianCalendarData.h"
#include "IndianCalendarDef.h"

#if defined(__MMI_WLAN_FEATURES__)
#endif /* defined(__MMI_WLAN_FEATURES__) */
#ifdef __MMI_TODOLIST__
#include "TodolistSrvGprot.h"
#endif /* __MMI_TODOLIST__ */
#include "SimCtrlSrvGprot.h"

#ifdef __MMI_HIJRI_CALENDAR__
#endif

//#ifdef __MMI_INDICAL__
#include "mmi_rp_app_indical_def.h"
//#endif

#include "Menucuigprot.h"

//RHR add begin

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "mms_api.h"
#include "wgui_categories_text_viewer.h"
#include "Unicodexdcl.h"
#include "wgui_inputs.h"
#include "string.h"
#include "gui.h"
#include "DateTimeType.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "wgui_categories_list.h"
#include "stdio.h"
#include "ToDoListGprot.h"
#include "stdlib.h"
#include "ModeSwitchSrvGProt.h"
//RHR add end

//#ifdef __MMI_INDICAL__
/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Local Function
 */
static U8 mmi_indical_get_adhika_month_status(U8 year, U8 month);
static mmi_id cui_menu_cui_indical_tithi_option_gid;
static mmi_id cui_menu_cui_indical_tithi_option_parent_gid;
static mmi_id cui_menu_cui_indical_festival_option_parent_gid;
static mmi_id cui_menu_cui_indical_festival_option_gid;
static mmi_id cui_menu_cui_indical_send_tithi_parent_gid;
static mmi_id cui_menu_cui_indical_send_tithi_gid;

static mmi_ret mmi_indical_tithi_option_group_proc(mmi_event_struct* evt);
static void mmi_indical_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_indical_festival_option_group_proc(mmi_event_struct* evt);
static void mmi_indical_festival_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_indical_send_tithi_group_proc(mmi_event_struct* evt);
static void mmi_indical_tithi_send_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static U8 mmi_indical_get_adhika_month_status(U8 year, U8 month);
static void mmi_indical_option_menu_cui_entry_hdlr(void);

/* 
 * Global Variable
 */
mmi_indical_cntx_struct g_mmi_indical_cntx = 
{    
    {0},
    {0},
    {0},
    {0},
    {-1},
    {0},
    {0},
    {0},
    {MMI_INDICAL_NO_ADHIKA_MONTH},
    {0},
    {0},
    {0},
    {0}
};

/* 
 * Extern Function,variables
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_indical_monthly_out_of_boundary
 * DESCRIPTION
 *  This API will check the currDate and return MMI_FALSE if the date falls
 *  outside the Indian Calendar boundary.And also display a popup depending on
 *  the show_popup parameter.
 * PARAMETERS
 *  currDate        [IN]        
 *  show_popup      [IN]        
 * RETURNS
 *  MMI_FALSE - Out of range, MMI_TRUE - Within range
 *****************************************************************************/
MMI_BOOL mmi_indical_monthly_out_of_boundary(MYTIME *currDate, MMI_BOOL show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((currDate->nYear > INDICAL_END_YEAR) || (currDate->nYear < INDICAL_START_YEAR))
    {
        if (MMI_TRUE == show_popup)
        {
            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_INDICAL_VALID_RANGE)), MMI_EVENT_FAILURE, NULL);
        }
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalTithiMenu
 * DESCRIPTION
 *  Highlight handler for Indian calendar Tithi menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalTithiMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_pre_entry_tithi_display, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_pre_entry_tithi_display, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalGoToCalendartTithi
 * DESCRIPTION
 *  Highlight handler for Go to Calendar from tithi
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalGoToCalendartTithi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_go_to_calendar, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_go_to_calendar, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalGoToCalendarFestival
 * DESCRIPTION
 *  Highlight handler for Go to Calendar from Festival list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalGoToCalendarFestival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_get_fest_date_go_to_calendar, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_get_fest_date_go_to_calendar, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalSendTithi
 * DESCRIPTION
 *  Highlight handler for send tithi menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalSendTithi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_send_tithi, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_send_tithi, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalSendTithiAsSMS
 * DESCRIPTION
 *  Highlight handler for find next same tithi
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalSendTithiAsSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_send_tithi_as_SMS, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_send_tithi_as_SMS, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_MMS__


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalSendTithiAsMMS
 * DESCRIPTION
 *  Highlight handler for sending tithi as MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalSendTithiAsMMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_send_tithi_as_MMS, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_send_tithi_as_MMS, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_MMS__ */

#ifdef __MMI_EMAIL__


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalSendTithiAsEMAIL
 * DESCRIPTION
 *  Highlight handler for sending tithi as MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalSendTithiAsEMAIL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_send_tithi_as_EMAIL, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_send_tithi_as_EMAIL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_EMAIL__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalFestivalListMenu
 * DESCRIPTION
 *  Highlight handler for Indian calendar festival list menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalFestivalListMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_pre_festival_list_display, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_pre_festival_list_display, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __MMI_TODOLIST__


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalTithiReminder
 * DESCRIPTION
 *  Highlight handler for Adding tithi reminder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalTithiReminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_pre_entry_add_tithi_reminder, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_pre_entry_add_tithi_reminder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIndiCalFestivalReminder
 * DESCRIPTION
 *  Highlight handler for Adding festival reminder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIndiCalFestivalReminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_indical_pre_entry_add_festival_reminder, KEY_EVENT_UP);
    SetKeyHandler(mmi_indical_pre_entry_add_festival_reminder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_TODOLIST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_tithi_option_menu_display
 * DESCRIPTION
 *  This function handles the Tithi options display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_tithi_option_menu_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    cui_menu_cui_indical_tithi_option_parent_gid = mmi_frm_group_create(
                                                GRP_ID_ROOT,
                                                GRP_ID_AUTO_GEN,
                                                mmi_indical_tithi_option_group_proc,
                                                NULL);
    mmi_frm_group_enter(cui_menu_cui_indical_tithi_option_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_cui_indical_tithi_option_gid = cui_menu_create(
                                        cui_menu_cui_indical_tithi_option_parent_gid,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        MENU_ID_INDICAL_TITHI_OPTION,
                                        MMI_TRUE,
                                        NULL);

    cui_menu_run(cui_menu_cui_indical_tithi_option_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_tithi_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_indical_tithi_option_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_indical_option_menu_cui_entry_hdlr();
            break;

        /*case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_cal_option_menu_cui_highlight_hdlr(menu_evt);
            break;*/
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_indical_option_menu_cui_select_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cui_menu_cui_indical_tithi_option_gid);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_option_menu_cui_entry_hdlr
 * DESCRIPTION
 *   Handlers for the select event of the options menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_indical_option_menu_cui_entry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TODOLIST__
    if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {                                 
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_REMINDER, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_REMINDER, MMI_FALSE);
    }
#endif
#if !defined(__MMI_WLAN_FEATURES__)
    if (!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_SEND_TITHI, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_SEND_TITHI, MMI_FALSE);
    }
#else
    if ((!srv_sim_ctrl_is_available(MMI_SIM1)) 
        #if defined(__MMI_EMAIL__)
    		&& !mmi_email_is_email_can_forward()
        #endif
		)
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_SEND_TITHI, MMI_TRUE);
    }
	 #if defined(__MMI_EMAIL__)
    else if (!mmi_email_is_email_can_forward())
	{
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_SEND_TITHI, MMI_TRUE);
    }
	#endif
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_SEND_TITHI, MMI_FALSE);
    }
#endif
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_SEND_TITHI, MMI_TRUE);
    }
#endif

    if (!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_SMS_NO, MMI_TRUE);
    #ifdef __MMI_MMS__
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_MMS_NO, MMI_TRUE);
    #endif /* __MMI_MMS__ */
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_SMS_NO, MMI_FALSE);
    #ifdef __MMI_MMS__
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_MMS_NO, MMI_FALSE);
    #endif /* __MMI_MMS__ */
    }
    
#ifdef __MMI_MMS__
    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_MMS_NO, MMI_TRUE);    
    }
#endif
#if  defined(__MMI_EMAIL__)
    if (!mmi_email_is_email_can_forward())
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_EMAIL_ID, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_tithi_option_gid, MENU_ID_INDICAL_ADD_EMAIL_ID, MMI_FALSE);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_option_menu_cui_select_hdlr
 * DESCRIPTION
 *   Handlers for the select event of the options menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_indical_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
    #ifdef __MMI_TODOLIST__
        case MENU_ID_INDICAL_ADD_REMINDER:
            mmi_indical_pre_entry_add_tithi_reminder();
            break;
    #endif /* __MMI_TODOLIST__ */
        case MENU_ID_INDICAL_GOTO_CALENDAR_TITHI:
            mmi_indical_go_to_calendar();
            break;
        case MENU_ID_INDICAL_SEND_TITHI:
            //mmi_indical_send_tithi();
            break;
        case MENU_ID_INDICAL_ADD_SMS_NO:
            mmi_indical_send_tithi_as_SMS();
            break;
    #ifdef __MMI_MMS__
        case MENU_ID_INDICAL_ADD_MMS_NO:
            mmi_indical_send_tithi_as_MMS();
            break;
    #endif /* __MMI_MMS__ */
    #ifdef __MMI_EMAIL__
        case MENU_ID_INDICAL_ADD_EMAIL_ID:
            mmi_indical_send_tithi_as_EMAIL();
            break;
    #endif /* __MMI_EMAIL__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_festival_option_menu_display
 * DESCRIPTION
 *  This function handles the Festival options display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_festival_option_menu_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_cui_indical_festival_option_parent_gid = mmi_frm_group_create(
                                                GRP_ID_ROOT,
                                                GRP_ID_AUTO_GEN,
                                                mmi_indical_festival_option_group_proc,
                                                NULL);
    mmi_frm_group_enter(cui_menu_cui_indical_festival_option_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_cui_indical_festival_option_gid = cui_menu_create(
                                        cui_menu_cui_indical_festival_option_parent_gid,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        MENU_ID_INDICAL_FESTIVAL_OPTION,
                                        MMI_TRUE,
                                        NULL);
#ifdef __MMI_TODOLIST__
    if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_festival_option_gid, MENU_ID_INDICAL_ADD_FESTIVAL_REMINDER, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_festival_option_gid, MENU_ID_INDICAL_ADD_FESTIVAL_REMINDER, MMI_FALSE);
    }
#endif

    cui_menu_run(cui_menu_cui_indical_festival_option_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_festival_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_indical_festival_option_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        /*case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_cal_option_menu_cui_entry_hdlr(menu_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_cal_option_menu_cui_highlight_hdlr(menu_evt);
            break;*/
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_indical_festival_option_menu_cui_select_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cui_menu_cui_indical_festival_option_gid);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_festival_option_menu_cui_select_hdlr
 * DESCRIPTION
 *   Handlers for the select event of the options menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_indical_festival_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
    #ifdef __MMI_TODOLIST__
        case MENU_ID_INDICAL_ADD_FESTIVAL_REMINDER:
            mmi_indical_pre_entry_add_festival_reminder();
            break;
    #endif /* __MMI_TODOLIST__ */
        case MENU_ID_INDICAL_GOTO_CALENDAR_FESTIVAL:
            mmi_indical_get_fest_date_go_to_calendar();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_pre_entry_tithi_display
 * DESCRIPTION
 *  This function is a pre entry function for mmi_indical_tithi_display.
 *  But this pre entry is invoked in case user goes from Tithi menu.
 *  This is done because mmi_indical_tithi_display screen is used for current tithi
 *  display and also for date to tithi coversion.In case of date to tithi conversion
 *  user changes the gloabl struct for date and the tithi is displayed for that
 *  date only.But when user open the screen through Tithi menu item we need to
 *  display the current date tithi.So,in this pre entry function we will set the
 *  global struct "" to the current date to show the user the current date tithi
 *  detail.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_pre_entry_tithi_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time;
    MYTIME tDateTimeAfterJumpToDate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clndr_get_updated_date_time_after_jump_to_date(&curr_time);
    if (mmi_indical_monthly_out_of_boundary(&curr_time, MMI_TRUE))
    {
        GetDateTime(&g_mmi_indical_cntx.curr_greg_time);
        mmi_clndr_get_updated_date_time_after_jump_to_date(&tDateTimeAfterJumpToDate);

       /*----- Check if the date is updated after the jump to date process -----*/
        if ((tDateTimeAfterJumpToDate.nYear == g_mmi_indical_cntx.curr_greg_time.nYear) &&
            (tDateTimeAfterJumpToDate.nMonth == g_mmi_indical_cntx.curr_greg_time.nMonth) &&
            (tDateTimeAfterJumpToDate.nDay == g_mmi_indical_cntx.curr_greg_time.nDay))
        {
            
        }
        else
        {
            g_mmi_indical_cntx.curr_greg_time.nYear = tDateTimeAfterJumpToDate.nYear;
            g_mmi_indical_cntx.curr_greg_time.nMonth = tDateTimeAfterJumpToDate.nMonth;
            g_mmi_indical_cntx.curr_greg_time.nDay = tDateTimeAfterJumpToDate.nDay;
        }
        /* The following API will set the current date */
        mmi_indical_tithi_display();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_tithi_display
 * DESCRIPTION
 *  This function handles the Indian calendar application activation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_tithi_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_ID_INDICAL_TITHI_MENU,
                    NULL, 
                    mmi_indical_tithi_display, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    DeleteScreenIfPresent(SCR_ID_INDICAL_TITHI_MENU);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_indical_prepare_date_string();

    ShowCategory79Screen(
        (UI_string_type) g_mmi_indical_cntx.title_str,
        (U8*) GetImage(GetRootTitleIcon(ORGANIZER_CALENDER_MENU)),
        (UI_string_type) (GetString(STR_GLOBAL_OPTIONS)),
        (U8*) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) (GetString(STR_GLOBAL_BACK)),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        MMI_TRUE,
        MMI_FALSE,
        (UI_buffer_type) g_mmi_indical_cntx.indianDateString,
        mmi_ucs2strlen((PS8) g_mmi_indical_cntx.indianDateString),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_indical_tithi_option_menu_display, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    wgui_inputs_ml_register_set_key_callback(mmi_indical_tithi_display_set_display_key_handler);
    SetKeyHandler(mmi_indical_go_previous_date, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_indical_go_next_date, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    SetCenterSoftkeyFunction(mmi_indical_tithi_option_menu_display, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_prepare_date_string
 * DESCRIPTION
 *  Preparing the date string for showing in the tithi screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_prepare_date_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 weekday;
    mmi_indical_indian_date_struct indical_indian_date;
    U8 temp_str[10] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    weekday = increment_gregorian_date(g_mmi_indical_cntx.curr_greg_time, 0, NULL);
    g_mmi_indical_cntx.gregorianDate.yy = g_mmi_indical_cntx.curr_greg_time.nYear - INDICAL_START_YEAR;
    g_mmi_indical_cntx.gregorianDate.mm = g_mmi_indical_cntx.curr_greg_time.nMonth;
    g_mmi_indical_cntx.gregorianDate.dd = g_mmi_indical_cntx.curr_greg_time.nDay;

    indical_indian_date.tithi = 0;
    indical_indian_date.paksha = 0;
    indical_indian_date.month = 0;

    memset(g_mmi_indical_cntx.indianDateString, '\0', MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH);

    mmi_indical_get_indian_date(&g_mmi_indical_cntx.gregorianDate, weekday, &indical_indian_date, g_mmi_indical_cntx.indianDateString);

    g_mmi_indical_cntx.indianDate = indical_indian_date;

    if (!(g_mmi_indical_cntx.curr_greg_time.nYear == INDICAL_START_YEAR
          && g_mmi_indical_cntx.curr_greg_time.nMonth == 1 && g_mmi_indical_cntx.curr_greg_time.nDay == 1))
    {
        mmi_ucs2cpy((S8*) g_mmi_indical_cntx.title_str, (S8*) "<");
        mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) " ");
    }
    
    gui_itoa((S32) (g_mmi_indical_cntx.curr_greg_time.nYear), (UI_string_type) temp_str, 10);

    if (!(g_mmi_indical_cntx.curr_greg_time.nYear == INDICAL_START_YEAR
          && g_mmi_indical_cntx.curr_greg_time.nMonth == 1 && g_mmi_indical_cntx.curr_greg_time.nDay == 1))
    {
        mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) temp_str);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_mmi_indical_cntx.title_str, (S8*) temp_str);
    }
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) "/");

    if (g_mmi_indical_cntx.curr_greg_time.nMonth < 10)
    {
        mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (PS8) "0");
    }

    gui_itoa((S32) (g_mmi_indical_cntx.curr_greg_time.nMonth), (UI_string_type) temp_str, 10);
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) temp_str);
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) "/");

    if (g_mmi_indical_cntx.curr_greg_time.nDay < 10)
    {
        mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (PS8) "0");
    }

    gui_itoa((S32) (g_mmi_indical_cntx.curr_greg_time.nDay), (UI_string_type) temp_str, 10);
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) temp_str);

    if (!(g_mmi_indical_cntx.curr_greg_time.nYear == INDICAL_END_YEAR
          && g_mmi_indical_cntx.curr_greg_time.nMonth == 12
        && g_mmi_indical_cntx.curr_greg_time.nDay == 31))
    {
        mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) " ");
        mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) ">");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_tithi_display_set_display_key_handler
 * DESCRIPTION
 *  LNK and RNK handlers for the left and right arrow keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_tithi_display_set_display_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_indical_go_previous_date, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_indical_go_next_date, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_go_previous_date
 * DESCRIPTION
 *  Shows the panchangam of previous gregorian date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_go_previous_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(incTime));
    incTime.nDay = 1;
    DecrementTime(g_mmi_indical_cntx.curr_greg_time, incTime, &g_mmi_indical_cntx.curr_greg_time);
    if (mmi_indical_monthly_out_of_boundary(&g_mmi_indical_cntx.curr_greg_time, MMI_TRUE))
    {
        /* The following API will set the current date */
        mmi_indical_prepare_date_string();
        ChangeCategory79Title((UI_string_type) g_mmi_indical_cntx.title_str, (U16) GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
        ChangeCategory79MessageString(
            (UI_buffer_type) g_mmi_indical_cntx.indianDateString,
            mmi_ucs2strlen((PS8) g_mmi_indical_cntx.indianDateString), 
            MMI_TRUE, 
            MMI_TRUE, 
            MMI_FALSE);
        //RedrawCategory79Screen();
        //mmi_indical_tithi_display();
    }
    else
    {
        IncrementTime(g_mmi_indical_cntx.curr_greg_time, incTime, &g_mmi_indical_cntx.curr_greg_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_go_next_date
 * DESCRIPTION
 *  Shows the panchangam of next gregorian date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_go_next_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_INDICAL_TITHI_MENU);
    memset(&incTime, 0, sizeof(incTime));
    incTime.nDay = 1;
    IncrementTime(g_mmi_indical_cntx.curr_greg_time, incTime, &g_mmi_indical_cntx.curr_greg_time);
    if (mmi_indical_monthly_out_of_boundary(&g_mmi_indical_cntx.curr_greg_time, MMI_TRUE))
    {
        /* The following API will set the current date */
        mmi_indical_prepare_date_string();
        ChangeCategory79Title((UI_string_type) g_mmi_indical_cntx.title_str, (U16) GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
        ChangeCategory79MessageString(
            (UI_buffer_type) g_mmi_indical_cntx.indianDateString,
            mmi_ucs2strlen((PS8) g_mmi_indical_cntx.indianDateString), 
            MMI_TRUE, 
            MMI_TRUE, 
            MMI_FALSE);
        //RedrawCategory79Screen();
        //mmi_indical_tithi_display();
    }
    else
    {
        DecrementTime(g_mmi_indical_cntx.curr_greg_time, incTime, &g_mmi_indical_cntx.curr_greg_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_go_to_calendar
 * DESCRIPTION
 *  Takes to the calendar screen at the date of the tithi.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_go_to_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clndr_set_jump_to_date(g_mmi_indical_cntx.curr_greg_time);
    cui_menu_close(cui_menu_cui_indical_tithi_option_gid);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_INDICAL_TITHI_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_fest_date_go_to_calendar
 * DESCRIPTION
 *  Takes to the calendar screen at the date of the festival.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_fest_date_go_to_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_indical_get_fest_date(&time);
    mmi_clndr_set_jump_to_date(time);
    cui_menu_close(cui_menu_cui_indical_festival_option_gid);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_INDICAL_FESTIVAL_DETAILS_MENU);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_INDICAL_FESTIVAL_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_send_tithi
 * DESCRIPTION
 *  This function take the no from the user to send SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_send_tithi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_cui_indical_send_tithi_parent_gid = mmi_frm_group_create(
                                                GRP_ID_ROOT,
                                                GRP_ID_AUTO_GEN,
                                                mmi_indical_send_tithi_group_proc,
                                                NULL);
    mmi_frm_group_enter(cui_menu_cui_indical_send_tithi_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_menu_cui_indical_send_tithi_gid = cui_menu_create(
                                        cui_menu_cui_indical_send_tithi_parent_gid,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        MENU_ID_INDICAL_SEND_TITHI,
                                        MMI_TRUE,
                                        NULL);
    
    if (
        #if defined(__MMI_WLAN_FEATURES__)
        mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || 
        #endif /* defined(__MMI_WLAN_FEATURES__) */
        (srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED) || 
    	!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_SMS_NO, MMI_TRUE);
    #ifdef __MMI_MMS__
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_MMS_NO, MMI_TRUE);
    #endif /* __MMI_MMS__ */
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_SMS_NO, MMI_FALSE);
    #ifdef __MMI_MMS__
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_MMS_NO, MMI_FALSE);
    #endif /* __MMI_MMS__ */
    }
    
#ifdef __MMI_MMS__
    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_MMS_NO, MMI_TRUE);    
    }
#endif
#if  defined(__MMI_EMAIL__)
    if (!mmi_email_is_email_can_forward())
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_EMAIL_ID, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_indical_send_tithi_gid, MENU_ID_INDICAL_ADD_EMAIL_ID, MMI_FALSE);
    }
#endif
    cui_menu_run(cui_menu_cui_indical_send_tithi_gid);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_indical_send_tithi_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_indical_send_tithi_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_indical_option_menu_cui_entry_hdlr();
            break;
    
        /*case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_cal_option_menu_cui_highlight_hdlr(menu_evt);
            break;*/
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_indical_tithi_send_menu_cui_select_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cui_menu_cui_indical_send_tithi_gid);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_tithi_send_menu_cui_select_hdlr
 * DESCRIPTION
 *   Handlers for the select event of the options menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_indical_tithi_send_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_INDICAL_ADD_SMS_NO:
            mmi_indical_send_tithi_as_SMS();
            break;
    #ifdef __MMI_MMS__
        case MENU_ID_INDICAL_ADD_MMS_NO:
            mmi_indical_send_tithi_as_MMS();
            break;
    #endif /* __MMI_MMS__ */
    #ifdef __MMI_EMAIL__
        case MENU_ID_INDICAL_ADD_EMAIL_ID:
            mmi_indical_send_tithi_as_EMAIL();
            break;
    #endif /* __MMI_EMAIL__ */
    }
}

#ifdef __MMI_MMS__


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_send_tithi_as_MMS
 * DESCRIPTION
 *  This function take the no from the user to send MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_send_tithi_as_MMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ucs2data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        ucs2data = mmi_indical_get_indian_date_string();
        mms_text_insert_hdlr(NULL, 0, ucs2data, mmi_ucs2strlen(ucs2data));
    }
    if (ucs2data)
    {
        OslMfree(ucs2data);
    }
}
#endif /* __MMI_MMS__ */

#ifdef __MMI_EMAIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_send_tithi_as_EMAIL
 * DESCRIPTION
 *  This function take the no from the user to send MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_send_tithi_as_EMAIL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    CHAR *ucs2data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2data = mmi_indical_get_indian_date_string();
    mmi_email_app_send_cont(ucs2data);
    
    if (ucs2data)
    {
        OslMfree(ucs2data);
    }
}
#endif /* __MMI_EMAIL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_send_tithi_as_SMS
 * DESCRIPTION
 *  This function take the no from the user to send SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_send_tithi_as_SMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct smsData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&smsData, 0, sizeof(mmi_sms_write_msg_para_struct));
    smsData.dcs = SMSAL_UCS2_DCS;

   /*----------------- Check for valid SIM ---------------------------------*/
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {

        smsData.string = (S8 *)mmi_indical_get_indian_date_string();
        smsData.stringlength = mmi_ucs2strlen((const S8*)(smsData.string));
        smsData.flag = MMI_SMS_ENTRY_WRITE_REPLY;

        /* --------------------------- add recipient ------------------------ */
        smsData.ascii_addr = NULL;

        mmi_sms_write_msg_lanch(0, &smsData);
    }
    else
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_SMS_MSG_NOT_READY_YET)), MMI_EVENT_ERROR, NULL);
    }

    if (smsData.string)
    {
        OslMfree(smsData.string);
    }

    if (smsData.ascii_addr)
    {
        OslMfree(smsData.ascii_addr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_festival_details_set_display_key_handler
 * DESCRIPTION
 *  Set LNK/RNK key handler for text viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_festival_details_set_display_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_indical_go_next_festival, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_indical_go_prev_festival, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_festival_details_display
 * DESCRIPTION
 *  This function will display festival details (Some text)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_festival_details_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_ID_INDICAL_FESTIVAL_DETAILS_MENU,
                    NULL, 
                    mmi_indical_festival_details_display, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    DeleteScreenIfPresent(SCR_ID_INDICAL_FESTIVAL_DETAILS_MENU);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_indical_prepare_fest_detail_string();    
    
    ShowCategory79Screen(
        (UI_string_type) g_mmi_indical_cntx.title_str,
        (U8*) GetImage(GetRootTitleIcon(ORGANIZER_CALENDER_MENU)),
        (UI_string_type) (GetString(STR_GLOBAL_OPTIONS)),
        (U8*) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) (GetString(STR_GLOBAL_BACK)),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        MMI_TRUE,
        MMI_FALSE,
        (UI_buffer_type) g_mmi_indical_cntx.fest_detail_str,
        mmi_ucs2strlen((PS8) g_mmi_indical_cntx.fest_detail_str),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_indical_festival_option_menu_display, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    wgui_inputs_ml_register_set_key_callback(mmi_indical_festival_details_set_display_key_handler);
    SetKeyHandler(mmi_indical_go_next_festival, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_indical_go_prev_festival, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    SetCenterSoftkeyFunction(mmi_indical_festival_option_menu_display, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_prepare_fest_detail_string
 * DESCRIPTION
 *  Preparing the date string for showing in the tithi screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_prepare_fest_detail_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0, weekday;
    U16 fest_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    while (g_mmi_indical_cntx.indiCalFestivalHighlightIndex != g_mmi_indical_cntx.fest_disp_index[index])
    {
        index++;
    }
    
    memset(g_mmi_indical_cntx.fest_detail_str, '\0', MAX_LEN_FEST_DESC * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) GetString(STR_INDICAL_DATE));
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) " ");
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) g_mmi_indical_cntx.popupList[g_mmi_indical_cntx.indiCalFestivalHighlightIndex]);
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) "\n");
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) GetString(STR_INDICAL_DAY));
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) " ");
    mmi_indical_get_fest_date(&g_mmi_indical_cntx.curr_greg_time);
    weekday = DOW(g_mmi_indical_cntx.curr_greg_time.nYear, g_mmi_indical_cntx.curr_greg_time.nMonth, g_mmi_indical_cntx.curr_greg_time.nDay);
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) GetString((U16) (STR_INDICAL_SUNDAY + weekday)));
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) "\n");
    fest_str_id = mmi_indical_get_festival_str_id(index);    
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) GetString((U16) (STR_INDICAL_DESCRIPTION)));
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) " ");
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.fest_detail_str, (S8*) GetString(mmi_indical_get_festival_details_str_id(index)));
    
    mmi_ucs2cpy((S8*) g_mmi_indical_cntx.title_str, (S8*) "<");
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) " ");
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) GetString(fest_str_id));
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) " ");
    mmi_ucs2cat((S8*) g_mmi_indical_cntx.title_str, (S8*) ">");

}

/*****************************************************************************
 * FUNCTION
 *  mmi_indical_go_next_festival
 * DESCRIPTION
 *  This function moves to next Indian festival of the year.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_go_next_festival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_INDICAL_FESTIVAL_DETAILS_MENU);
    if ( ++g_mmi_indical_cntx.indiCalFestivalHighlightIndex >= MAX_FESTIVALS)
    {
        g_mmi_indical_cntx.indiCalFestivalHighlightIndex = 0;
    }
    mmi_indical_prepare_fest_detail_string();
    ChangeCategory79Title((UI_string_type) g_mmi_indical_cntx.title_str, (U16) GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
    ChangeCategory79MessageString(
        (UI_buffer_type) g_mmi_indical_cntx.fest_detail_str,
        mmi_ucs2strlen((PS8) g_mmi_indical_cntx.fest_detail_str), 
        MMI_TRUE, 
        MMI_TRUE, 
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_go_prev_festival
 * DESCRIPTION
 *  This function moves to previous Indian festival of the year.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_go_prev_festival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 index = (S8) g_mmi_indical_cntx.indiCalFestivalHighlightIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_INDICAL_FESTIVAL_DETAILS_MENU);
    if ( --index == (S8) -1)
    {
        g_mmi_indical_cntx.indiCalFestivalHighlightIndex = MAX_FESTIVALS - 1;
    }
    else
    {
        g_mmi_indical_cntx.indiCalFestivalHighlightIndex = (U8) index;
    }
    mmi_indical_prepare_fest_detail_string();
    ChangeCategory79Title((UI_string_type) g_mmi_indical_cntx.title_str, (U16) GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
    ChangeCategory79MessageString(
        (UI_buffer_type) g_mmi_indical_cntx.fest_detail_str,
        mmi_ucs2strlen((PS8) g_mmi_indical_cntx.fest_detail_str), 
        MMI_TRUE, 
        MMI_TRUE, 
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_pre_festival_list_display
 * DESCRIPTION
 *  This function handles the add operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_pre_festival_list_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time;
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clndr_get_updated_date_time_after_jump_to_date(&curr_time);
    if (mmi_indical_monthly_out_of_boundary(&curr_time, MMI_TRUE))
    {
        for (i = 0; i < MAX_FESTIVALS; i++)
        {
            g_mmi_indical_cntx.fest_disp_index[i] = i;
        }
        mmi_indical_get_festival_date();

        mmi_indical_festival_list_display();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_festival_list_display
 * DESCRIPTION
 *  This function handles the add operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_festival_list_display(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nItems = MAX_FESTIVALS;

    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_ID_INDICAL_FESTIVAL_MENU,
                    NULL, 
                    mmi_indical_festival_list_display, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();



    SetParentHandler(MENU_ID_INDICAL_FESTIVAL_LIST);

    RegisterHighlightHandler(mmi_indical_set_highlight_index);
#ifndef __MMI_BASIC_UI_STYLE__
    ShowCategory284Screen(
        STR_INDICAL_FESTIVALS,
        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
        STR_GLOBAL_DETAILS,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        GetIndicalFestListItem,
        GetIndicalFestListHint,
        0,
        guiBuffer);
#else
	wgui_cat1032_show(
            (WCHAR*) GetString(STR_INDICAL_FESTIVALS),
            (PU8) GetImage(ORGANIZER_CALENDER_MENU),
            (WCHAR*) GetString(STR_GLOBAL_DETAILS),
            0,
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            nItems,
            GetIndicalFestListItem_ext,
            GetIndicalFestListHint,
            0,
            0,    
            0,
            0,
            guiBuffer,
            NULL);
#endif

    SetLeftSoftkeyFunction(mmi_indical_festival_details_display, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_indical_festival_details_display, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  GetIndicalFestListHint
 * DESCRIPTION
 *  This function will display festival details (Some text)
 * PARAMETERS
 *  item_index      [IN]
 *  hint_array      [IN]
 * RETURNS
 *  TRUE
 *****************************************************************************/
S32 GetIndicalFestListHint(S32 item_index, UI_string_type *hint_array)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    mmi_ucs2cpy((S8*) *hint_array, (S8*) g_mmi_indical_cntx.popupList[item_index]);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  GetIndicalFestListItem
 * DESCRIPTION
 *  This function will display festival details (Some text)
 * PARAMETERS
 *  item_index      [IN]
 *  str_buff        [IN]
 *  img_buff_p      [IN]
 *  str_img_mask    [IN]
 * RETURNS
 *  TRUE
 *****************************************************************************/
pBOOL GetIndicalFestListItem(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }

    while (item_index != g_mmi_indical_cntx.fest_disp_index[index])
    {
        index++;
    }
    
    mmi_ucs2cpy((S8*) str_buff, GetString((U16)(index + STR_INDICAL_GURU_GOVIND_SINGH_JAYANTI)));
    *img_buff_p = NULL;

    return TRUE;
}

#ifdef __MMI_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  GetIndicalFestListItem_ext
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  S32
 *****************************************************************************/
S32 GetIndicalFestListItem_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
	S32 i;

	for (i = 0; i< data_size; i++)
	{
		GetIndicalFestListItem(start_index, menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
		start_index++;
	}
	return data_size;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_tithi_delta
 * DESCRIPTION
 *  This function calculates the tithi delta value
 * PARAMETERS
 *  gregorian_date      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_get_tithi_delta(mmi_indical_gregorian_date_struct *gregorian_date)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    indical_special_tithi_struct indical_special_tithi;
    U8 tithi_delta = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*--------- Read the special tithi details for the given date -----------*/

    indical_special_tithi = indical_special_tithi_array[gregorian_date->yy][gregorian_date->mm - 1];

    if ((indical_special_tithi.dd_st.dd1 != 0) && (indical_special_tithi.dd_st.dd1 < gregorian_date->dd))
    {
        tithi_delta = tithi_delta + 1;
        if ((indical_special_tithi.dd_st.dd2 != 0) && (indical_special_tithi.dd_st.dd2 < gregorian_date->dd))
        {
            tithi_delta = tithi_delta + 1;
        }
    }

    if ((indical_special_tithi.st_dd.dd1 != 0) && (indical_special_tithi.st_dd.dd1 < gregorian_date->dd))
    {
        tithi_delta = tithi_delta - 1;
        if ((indical_special_tithi.st_dd.dd2 != 0) && (indical_special_tithi.st_dd.dd2 < gregorian_date->dd))
        {
            tithi_delta = tithi_delta - 1;
        }
    }
    return tithi_delta;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_tithi
 * DESCRIPTION
 *  This function calculates the tithi for a given gregorian date
 * PARAMETERS
 *  gregorian_date      [IN]        
 *  indical_ind_dt      [OUT]       
 *  tithi_delta         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_tithi(
        mmi_indical_gregorian_date_struct *gregorian_date,
        mmi_indical_indian_date_struct *indical_ind_dt,
        U8 tithi_delta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 factor, ekam_diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gregorian_date->dd == 1)
    {
        return; /* Base tithi is the required tithi so no more calculations */
    }
    else
    {
        indical_ind_dt->tithi = indical_ind_dt->tithi + tithi_delta;
        factor = indical_ind_dt->tithi + gregorian_date->dd;

   /*------------- Ekam diff is zero if MMI_INDICAL_EKAM ----------------------*/

        if (gregorian_date->dd == MMI_INDICAL_EKAM)
        {
            ekam_diff = 0;
        }
        else
        {
            ekam_diff = 16 - indical_ind_dt->tithi;
        }

   /*-------- if factor > 16, means there is paksha change and -------------*/
   /*-------- it could be month change also --------------------------------*/

        if (factor > 16)
        {
            indical_ind_dt->tithi = gregorian_date->dd - ekam_diff;
            mmi_indical_increment_month_and_paksha(
                (mmi_indical_indian_date_struct*) indical_ind_dt,
                gregorian_date->yy);

            while (indical_ind_dt->tithi - 15 > 0)
            {
                indical_ind_dt->tithi = indical_ind_dt->tithi - 15;
                mmi_indical_increment_month_and_paksha(
                    (mmi_indical_indian_date_struct*) indical_ind_dt,
                    gregorian_date->yy);
            }

        }
        else
        {
            indical_ind_dt->tithi = indical_ind_dt->tithi + gregorian_date->dd - 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_increment_month_and_paksha
 * DESCRIPTION
 *  This function increments the month and paksha value
 * PARAMETERS
 *  indical_indn_dt     [IN/OUT]        
 *  year                [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_increment_month_and_paksha(mmi_indical_indian_date_struct *indical_indn_dt, U8 year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*indical_indn_dt).paksha == 1)
    {
        if (indical_adhika_month_detail_array[year] != MMI_INDICAL_NO_ADHIKA_MONTH)
        {
            if ((*indical_indn_dt).adhika == MMI_INDICAL_PRATHMA)
            {
                (*indical_indn_dt).adhika = MMI_INDICAL_DVITIYA;
            }
            else if ((*indical_indn_dt).adhika == MMI_INDICAL_DVITIYA)
            {
                (*indical_indn_dt).adhika = 0;
                (*indical_indn_dt).month = ((*indical_indn_dt).month + 1) % 12;
            }
            else
            {
                if (((*indical_indn_dt).month + 1) == indical_adhika_month_detail_array[year])
                {
                    (*indical_indn_dt).adhika = MMI_INDICAL_PRATHMA;
                }
                (*indical_indn_dt).month = ((*indical_indn_dt).month + 1) % 12;
            }
        }
        else
        {
            (*indical_indn_dt).month = ((*indical_indn_dt).month + 1) % 12;
        }
    }

    (*indical_indn_dt).paksha = !(*indical_indn_dt).paksha;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_adhika_month_status
 * DESCRIPTION
 *  This function increments the month and paksha value
 * PARAMETERS
 *  year     [IN]        
 *  month    [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_indical_get_adhika_month_status(U8 year, U8 month)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__
    indical_adhika_month_struct indical_adhika_month;
#endif
    U8 adhika_status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__
    indical_adhika_month = indical_adhika_month_info[year];

    if ((indical_adhika_month.prathama != 0) && (indical_adhika_month.prathama == month))
    {
        adhika_status = MMI_INDICAL_PRATHMA;
    }

    if ((indical_adhika_month.dwitiya != 0) && (indical_adhika_month.dwitiya == month))
    {
        adhika_status = MMI_INDICAL_DVITIYA;
    }
#else /* __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__ */ 

    if (g_mmi_indical_cntx.indical_adhika_month_info_year.year != year)
    {
        mmi_indical_fill_adhika_month_array_single((indical_adhika_month_struct *)&g_mmi_indical_cntx.indical_adhika_month_info_year, year);
    }

    if ((g_mmi_indical_cntx.indical_adhika_month_info_year.prathama != 0) && (g_mmi_indical_cntx.indical_adhika_month_info_year.prathama == month))
    {
        adhika_status = MMI_INDICAL_PRATHMA;
    }

    if ((g_mmi_indical_cntx.indical_adhika_month_info_year.dwitiya != 0) && (g_mmi_indical_cntx.indical_adhika_month_info_year.dwitiya == month))
    {
        adhika_status = MMI_INDICAL_DVITIYA;
    }
#endif /* __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__ */ 

    return adhika_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_samvat_year
 * DESCRIPTION
 *  This function calculates the vikrami samvat year for given date
 * PARAMETERS
 *  gregorian_date      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_get_samvat_year(mmi_indical_gregorian_date_struct *gregorian_date)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 samvat_year;
    indical_festivals_base_struct indical_indian_new_year_begin_date;
    MYTIME Curr_date_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&Curr_date_time);

   /*------- Get the Indian year begin year for given date -----------------*/
    indical_indian_new_year_begin_date = indical_festivals_base_array[0][MMI_INDICAL_NAV_VARSHA];

    mmi_indical_update_festival_date_for_offset(
        &indical_indian_new_year_begin_date,
        MMI_INDICAL_NAV_VARSHA,
        gregorian_date->yy);

    if (indical_indian_new_year_begin_date.mm < gregorian_date->mm)
    {
        samvat_year = gregorian_date->yy + INDICAL_DIFF_GREG_AND_INDIAN_YEAR;
    }
    else
    {
        if ((indical_indian_new_year_begin_date.mm == gregorian_date->mm) &&
            (indical_indian_new_year_begin_date.dd <= gregorian_date->dd))
        {
            samvat_year = gregorian_date->yy + INDICAL_DIFF_GREG_AND_INDIAN_YEAR;
        }
        else
        {
            samvat_year = gregorian_date->yy + INDICAL_DIFF_GREG_AND_INDIAN_YEAR - 1;
        }
    }
    return samvat_year;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_festival
 * DESCRIPTION
 *  find the festivals for the given greg date and add to calculated tithi.
 * PARAMETERS
 *  gregorian_date      [IN]        
 *  s_ind_dt_string     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_festival(mmi_indical_gregorian_date_struct *gregorian_date, U8 *s_ind_dt_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nfix_date_fest_index, nvari_date_fest_index;
    indical_festivals_base_struct indical_festival;
    MYTIME Curr_date_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&Curr_date_time);

   /*-------------- Evaluating the fix date festivals ----------------------*/
    for (nfix_date_fest_index = 0; nfix_date_fest_index < MMI_INDICAL_MAX_FIX_DATE_FESTIVALS; nfix_date_fest_index++)
    {
        if ((indical_fix_date_festivals_array[nfix_date_fest_index].dd ==
             gregorian_date->dd) && (indical_fix_date_festivals_array[nfix_date_fest_index].mm == gregorian_date->mm))
        {

            mmi_ucs2cat(
                (S8*) s_ind_dt_string,
                (S8*) GetString(mmi_indical_get_festival_str_id(nfix_date_fest_index)));
        }
    }

   /*--------------- Evaluating the variable date festivals ----------------*/
    for (nvari_date_fest_index = 0;
         nvari_date_fest_index < MMI_INDICAL_MAX_VARI_DATE_FESTIVALS; nvari_date_fest_index++)
    {

        indical_festival = indical_festivals_base_array[0][nvari_date_fest_index];

        mmi_indical_update_festival_date_for_offset(&indical_festival, nvari_date_fest_index, gregorian_date->yy);

        if ((indical_festival.dd == gregorian_date->dd) && (indical_festival.mm == gregorian_date->mm))
        {
            mmi_ucs2cat(
                (S8*) s_ind_dt_string,
                GetString(mmi_indical_get_festival_str_id ((U8) (nvari_date_fest_index + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS))));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_festival_date
 * DESCRIPTION
 *  This function find the festival dates and fill them in global hintData
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_festival_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nfix_date_fest_index, nvari_date_fest_index, temp_str[10] = {0};
    U8 fest_date_str[MAX_FESTIVAL_NAME_LENGTH] = {0};
    //U8 tmpYear[MAX_YEAR_VALUE] = {0};
    U16 year;
    MYTIME tDateTimeAfterJumpToDate;
    indical_festivals_base_struct indical_festival;
    mmi_indical_gregorian_date_struct indical_date_array[MAX_FESTIVALS] = {0};
    U8 i,flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&g_mmi_indical_cntx.curr_greg_time);
    mmi_clndr_get_updated_date_time_after_jump_to_date(&tDateTimeAfterJumpToDate);

   /*------ Check if the date is updated after the jump to date process ----*/
    if (!((tDateTimeAfterJumpToDate.nYear == g_mmi_indical_cntx.curr_greg_time.nYear) &&
          (tDateTimeAfterJumpToDate.nMonth == g_mmi_indical_cntx.curr_greg_time.nMonth) &&
          (tDateTimeAfterJumpToDate.nDay == g_mmi_indical_cntx.curr_greg_time.nDay)))
    {
        g_mmi_indical_cntx.curr_greg_time.nYear = tDateTimeAfterJumpToDate.nYear;
        g_mmi_indical_cntx.curr_greg_time.nMonth = tDateTimeAfterJumpToDate.nMonth;
        g_mmi_indical_cntx.curr_greg_time.nDay = tDateTimeAfterJumpToDate.nDay;
    }

    year = g_mmi_indical_cntx.curr_greg_time.nYear;    

   /*------------------------ Festivals for the fix date -------------------*/
    for (nfix_date_fest_index = 0; nfix_date_fest_index < MMI_INDICAL_MAX_FIX_DATE_FESTIVALS; nfix_date_fest_index++)
    {        
        indical_date_array[nfix_date_fest_index].mm = indical_fix_date_festivals_array[nfix_date_fest_index].mm;
        indical_date_array[nfix_date_fest_index].dd = indical_fix_date_festivals_array[nfix_date_fest_index].dd;
    }

   /*----------------------- Festivals for the variable date ---------------*/

    for (nvari_date_fest_index = 0;
         nvari_date_fest_index < MMI_INDICAL_MAX_VARI_DATE_FESTIVALS; nvari_date_fest_index++)
    {

        memset(fest_date_str, '\0', MAX_FESTIVAL_NAME_LENGTH);
        indical_festival = indical_festivals_base_array[0][nvari_date_fest_index];

      /*---------------- Update the base festivals for offset -------------*/

        mmi_indical_update_festival_date_for_offset(&indical_festival, nvari_date_fest_index, year);

      /*------------------- Evaluating the date string --------------------*/        
        flag = mmi_indical_compare_festivals_date(indical_date_array, (U8)(nfix_date_fest_index + nvari_date_fest_index - 1), indical_festival);
        if (flag == 1)
        {
            g_mmi_indical_cntx.fest_disp_index[nfix_date_fest_index - 1]++;
            g_mmi_indical_cntx.fest_disp_index[nfix_date_fest_index + nvari_date_fest_index]--;
        }        
    }

    for (i = 0; i < MAX_FESTIVALS; i++)
    {
        memset(fest_date_str, '\0', MAX_FESTIVAL_NAME_LENGTH);
        memset(temp_str, '\0', 10);
        gui_itoa((S32) (year), (UI_string_type) temp_str, 10);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) temp_str);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) "/");

        if (indical_date_array[i].mm < 10)
        {
            mmi_ucs2cat((S8*) fest_date_str, (PS8) "0");
        }
        memset(temp_str, '\0', 10);
        gui_itoa((S32) (indical_date_array[i].mm), (UI_string_type) temp_str, 10);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) temp_str);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) "/");

        if (indical_date_array[i].dd < 10)
        {
            mmi_ucs2cat((S8*) fest_date_str, (PS8) "0");
        }
        memset(temp_str, '\0', 10);
        gui_itoa((S32) (indical_date_array[i].dd), (UI_string_type) temp_str, 10);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) temp_str);
        memset(temp_str, '\0', 10);

        mmi_ucs2cpy((S8*) g_mmi_indical_cntx.popupList[i], (S8*) fest_date_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_compare_festivals_date
 * DESCRIPTION
 *  This function find if two tithi values are there for one date
 * PARAMETERS
 *  indical_festival_array      [?]         
 *  index                       [IN]        
 *  indical_festival            [IN]        
 *  gregorian_date(?)           [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_compare_festivals_date(mmi_indical_gregorian_date_struct *indical_festival_array, U8 index, indical_festivals_base_struct indical_festival)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, flag = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((indical_festival.mm > indical_festival_array[i].mm) ||
            (indical_festival.mm == indical_festival_array[i].mm && indical_festival.dd >= indical_festival_array[i].dd))
    {
        i++;
        if(i == (index + 1))
        {
            flag = 0;
            break;
        }
    }
    if (i == (index + 1))
    {
        indical_festival_array[i].dd = indical_festival.dd;
        indical_festival_array[i].mm = indical_festival.mm;
    }
    else
    {
        memmove ((indical_festival_array + i + 1), (indical_festival_array + i), sizeof(mmi_indical_gregorian_date_struct));
        indical_festival_array[i].dd = indical_festival.dd;
        indical_festival_array[i].mm = indical_festival.mm;
    }
    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_check_for_two_tithi_same_gdate
 * DESCRIPTION
 *  This function find if two tithi values are there for one date
 * PARAMETERS
 *  gregorian_date      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_check_for_two_tithi_same_gdate(mmi_indical_gregorian_date_struct *gregorian_date)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    indical_special_tithi_struct indical_special_tithi;
    U8 double_tithi_on_single_date = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*-------- Read the special tithi details for the given date ------------*/
    indical_special_tithi = indical_special_tithi_array[gregorian_date->yy][gregorian_date->mm - 1];

    if ((indical_special_tithi.dd_st.dd1 != 0) && (indical_special_tithi.dd_st.dd1 == gregorian_date->dd))
    {
        double_tithi_on_single_date = 1;
    }

    if ((indical_special_tithi.dd_st.dd2 != 0) && (indical_special_tithi.dd_st.dd2 == gregorian_date->dd))
    {
        double_tithi_on_single_date = 1;
    }

    return double_tithi_on_single_date;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_indian_date
 * DESCRIPTION
 *  This function evaluates the tithi, fill that tithi in tithi string and
 *  handover that tithi to some function for display
 * PARAMETERS
 *  indical_gregorian_date      [IN]        
 *  weekday                     [IN]        
 *  indical_indian_date         [OUT]       
 *  s_indian_date_string        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_indian_date(
        mmi_indical_gregorian_date_struct *indical_gregorian_date,
        U8 weekday,
        mmi_indical_indian_date_struct *indical_indian_date,
        U8 *s_indian_date_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tithi_detla, adhika_month, samvat_year;//, indical_second_tithi;
    U8 smvt_yr[10] = {0};
    //U8 temp_str[10] = {0};
    U16 str_id_tithi;
    U8 festival[40*ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(s_indian_date_string, '\0', MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH);

   /*-------- Calculate the delta value for special tithi ------------------*/

    tithi_detla = mmi_indical_get_tithi_delta((mmi_indical_gregorian_date_struct*) indical_gregorian_date);

   /*-------- Calculate tithi, paksha and month ----------------------------*/

    g_mmi_indical_cntx.indianBaseDate.tithi = indical_base_tithi_array
        [indical_gregorian_date->yy][indical_gregorian_date->mm - 1].tithi % 15;

    g_mmi_indical_cntx.indianBaseDate.paksha = indical_base_tithi_array
        [indical_gregorian_date->yy][indical_gregorian_date->mm - 1].tithi / 15;

    g_mmi_indical_cntx.indianBaseDate.month = indical_base_tithi_array[indical_gregorian_date->yy][indical_gregorian_date->mm - 1].month;

    g_mmi_indical_cntx.indianBaseDate.adhika = mmi_indical_get_adhika_month_status (indical_gregorian_date->yy,indical_gregorian_date->mm);

   /*-------------- Adjustments for Amavasya and purnuma -------------------*/

   /*-------- Do not show the paksha value for the amavasya and purnima ----*/

    if (g_mmi_indical_cntx.indianBaseDate.tithi == 0)
    {
        indical_indian_date->tithi = 15;
        indical_indian_date->month = g_mmi_indical_cntx.indianBaseDate.month;

        if (g_mmi_indical_cntx.indianBaseDate.paksha == 2)
        {
            indical_indian_date->paksha = 1;
        }

        if (g_mmi_indical_cntx.indianBaseDate.paksha == 1)
        {
            indical_indian_date->paksha = 0;
        }

        /* This is required for displaying ADHIKA month prefix */
        indical_indian_date->adhika = g_mmi_indical_cntx.indianBaseDate.adhika;
    }
    else
    {
        *indical_indian_date = g_mmi_indical_cntx.indianBaseDate;
    }

    mmi_indical_get_tithi(indical_gregorian_date, indical_indian_date, tithi_detla);

    /*-------- Checking if two tithi values are there ----------------------*/
    //indical_second_tithi = mmi_indical_check_for_two_tithi_same_gdate(indical_gregorian_date);

   /*-------- Calculate the Samvat for given gregorian date ---------------*/
    samvat_year = mmi_indical_get_samvat_year(indical_gregorian_date);


   /*-------- write Weekday -----------------------------------------------*/

    mmi_ucs2cpy((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_DAY));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(mmi_indical_get_weekday_strid(weekday)));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) "\n");

    /*-------- write tithi --------------------------------------------------*/
    
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_TITHI));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
    str_id_tithi = mmi_indical_get_tithi_str_id(indical_indian_date->tithi, indical_indian_date->paksha);
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(str_id_tithi));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) "\n");

    /*-------- write paksha--------------------------------------------------*/
    if (15 != indical_indian_date->tithi)
    {
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_PAKSHA));
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
        mmi_ucs2cat(
            (S8*) s_indian_date_string,
            (S8*) GetString(mmi_indical_get_paksha_strid(indical_indian_date->paksha)));
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) "\n");
    }

   /*-------- Checking if the calculated tithi is having adhika month  ----*/
    adhika_month = indical_indian_date->adhika;

   
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_MONTH));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
    /*-------- write adhika info -------------------------------------------*/

    if (0 != adhika_month)
    {
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(mmi_indical_get_adhika_strid(adhika_month)));

        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");

        /* Below we will save the adhika month prefix */
        g_mmi_indical_cntx.mmi_indical_info_struct.indical_adhika_month_prefix = adhika_month;
    }

   /*-------- write month --------------------------------------------------*/

    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(mmi_indical_get_month_strid(indical_indian_date->month)));

    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) "\n");

    gui_itoa((S32) (samvat_year + INDICAL_START_YEAR), (UI_string_type) smvt_yr, 10);
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_YEAR));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_VIKRAMI));
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
    mmi_ucs2cat((S8*) s_indian_date_string, (S8*) smvt_yr);
    memset(festival, '\0', (40*ENCODING_LENGTH));
    mmi_indical_get_festival(indical_gregorian_date, festival);
    if (festival[0] != '\0')
    {
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) "\n");
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) GetString(STR_INDICAL_FESTIVAL));
        mmi_ucs2cat((S8*) s_indian_date_string, (S8*) " ");
        mmi_ucs2ncat((S8*) s_indian_date_string, (S8*) festival, sizeof(festival));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_paksha_strid
 * DESCRIPTION
 *  get the paksha string id
 * PARAMETERS
 *  nPaksha     [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_paksha_strid(U8 nPaksha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nPakshaStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nPaksha)
    {
        case MMI_INDICAL_KRISHANA_PAKSHA:
            nPakshaStrid = STR_INDICAL_KRISHANA_PAKSHA;
            break;

        case MMI_INDICAL_SHUKLA_PAKSHA:
            nPakshaStrid = STR_INDICAL_SHUKLA_PAKSHA;
            break;

        default:
            break;
    }
    return nPakshaStrid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_short_paksha_strid
 * DESCRIPTION
 *  get the short paksha string id
 * PARAMETERS
 *  nPaksha     [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_short_paksha_strid(U8 nPaksha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nPakshaStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nPaksha)
    {
        case MMI_INDICAL_KRISHANA_PAKSHA:
            nPakshaStrid = STR_INDICAL_SHORT_KRISHANA_PAKSHA;
            break;

        case MMI_INDICAL_SHUKLA_PAKSHA:
            nPakshaStrid = STR_INDICAL_SHORT_SHUKLA_PAKSHA;
            break;

        default:
            break;
    }
    return nPakshaStrid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_adhika_strid
 * DESCRIPTION
 *  get the adhika month string id
 * PARAMETERS
 *  nAdhikaMonth        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_adhika_strid(U8 nAdhikaMonth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nAdhikaStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nAdhikaMonth)
    {
        case MMI_INDICAL_PRATHMA:
            nAdhikaStrid = STR_INDICAL_PRATHMA;
            break;
        case MMI_INDICAL_DVITIYA:
            nAdhikaStrid = STR_INDICAL_DWITIYA;
            break;
        default:
            break;
    }

    return nAdhikaStrid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_short_adhika_strid
 * DESCRIPTION
 *  get the short adhika month string id
 * PARAMETERS
 *  nAdhikaMonth        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_short_adhika_strid(S16 nAdhikaMonth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nAdhikaStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nAdhikaMonth)
    {
        case MMI_INDICAL_PRATHMA:
            nAdhikaStrid = STR_INDICAL_SHORT_PRATHMA;
            break;
        case MMI_INDICAL_DVITIYA:
            nAdhikaStrid = STR_INDICAL_SHORT_DWITIYA;
            break;
        default:
            break;
    }

    return nAdhikaStrid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_month_strid
 * DESCRIPTION
 *  returns the month string id for given month
 * PARAMETERS
 *  nIndianMonth        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_month_strid(U8 nIndianMonth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nMonthStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nIndianMonth)
    {
        case MMI_INDICAL_CHAITRA:
            nMonthStrid = STR_INDICAL_CHAITRA;
            break;
        case MMI_INDICAL_VAISAKHA:
            nMonthStrid = STR_INDICAL_VAISAKHA;
            break;
        case MMI_INDICAL_JYAISTHA:
            nMonthStrid = STR_INDICAL_JYAISTHA;
            break;
        case MMI_INDICAL_ASADHA:
            nMonthStrid = STR_INDICAL_ASADHA;
            break;
        case MMI_INDICAL_SRAVANA:
            nMonthStrid = STR_INDICAL_SRAVANA;
            break;
        case MMI_INDICAL_BHADRAPADA:
            nMonthStrid = STR_INDICAL_BHADRAPADA;
            break;
        case MMI_INDICAL_ASVINA:
            nMonthStrid = STR_INDICAL_ASVINA;
            break;
        case MMI_INDICAL_KARTTIKA:
            nMonthStrid = STR_INDICAL_KARTTIKA;
            break;
        case MMI_INDICAL_MARGASIRSA:
            nMonthStrid = STR_INDICAL_MARGASIRSA;
            break;
        case MMI_INDICAL_PAUSA:
            nMonthStrid = STR_INDICAL_PAUSA;
            break;
        case MMI_INDICAL_MAGHA:
            nMonthStrid = STR_INDICAL_MAGHA;
            break;
        case MMI_INDICAL_PHALGUNA:
            nMonthStrid = STR_INDICAL_PHALGUNA;
            break;
        default:
            break;

    }

    return nMonthStrid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_weekday_strid
 * DESCRIPTION
 *  get the weekday string id for given weekday
 * PARAMETERS
 *  nWeekDay        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_weekday_strid(U8 nWeekDay)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nWeekdayStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nWeekDay)
    {
        case MMI_INDICAL_RAVIWARA:
            nWeekdayStrid = STR_INDICAL_RAVIWARA;
            break;
        case MMI_INDICAL_SOMAVARA:
            nWeekdayStrid = STR_INDICAL_SOMAVARA;
            break;
        case MMI_INDICAL_MANGALVARA:
            nWeekdayStrid = STR_INDICAL_MANGALVARA;
            break;
        case MMI_INDICAL_BUDHAVARA:
            nWeekdayStrid = STR_INDICAL_BUDHAVARA;
            break;
        case MMI_INDICAL_GURUVARA:
            nWeekdayStrid = STR_INDICAL_GURUVARA;
            break;
        case MMI_INDICAL_SUKRAVARA:
            nWeekdayStrid = STR_INDICAL_SUKRAVARA;
            break;
        case MMI_INDICAL_SANIVARA:
            nWeekdayStrid = STR_INDICAL_SANIVARA;
        default:
            break;

    }
    return nWeekdayStrid;

}


/*****************************************************************************
 * FUNCTION
 *  increment_gregorian_date
 * DESCRIPTION
 *  increment the gregorian date
 * PARAMETERS
 *  orig_date           [IN]        
 *  days                [IN]        
 *  next_greg_date      [OUT]       
 * RETURNS
 *  U8
 *****************************************************************************/
U8 increment_gregorian_date(MYTIME orig_date, S8 days, mmi_indical_gregorian_date_struct *next_greg_date)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t_next, t_inc_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&t_next, 0, sizeof(MYTIME));
    memset(&t_inc_value, 0, sizeof(MYTIME));
    t_inc_value.nDay = t_next.nDay = days;

    IncrementTime(orig_date, t_inc_value, &t_next);

    if (next_greg_date != NULL)
    {
        next_greg_date->yy = t_next.nYear - INDICAL_START_YEAR;
        next_greg_date->mm = t_next.nMonth;
        next_greg_date->dd = t_next.nDay;
    }

    return t_next.DayIndex;

}


/*****************************************************************************
 * FUNCTION
 *  increment_gregorian_date_update_orig_date
 * DESCRIPTION
 *  increments the gregorian date and update the original date
 * PARAMETERS
 *  orig_date           [IN]        
 *  days                [IN]        
 *  next_greg_date      [OUT]       
 * RETURNS
 *  U8
 *****************************************************************************/
U8 increment_gregorian_date_update_orig_date(
    MYTIME *orig_date,
    U8 days,
    mmi_indical_gregorian_date_struct *next_greg_date)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t_inc_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t_inc_value.nYear = 0;
    t_inc_value.nMonth = 0;
    t_inc_value.nDay = days;
    t_inc_value.nHour = 0;
    t_inc_value.nMin = 0;
    t_inc_value.nSec = 0;
    t_inc_value.DayIndex = 0;

   /*--------------- Increment time for the given no of days ----------*/
    IncrementTime(*orig_date, t_inc_value, orig_date);

    next_greg_date->yy = orig_date->nYear - INDICAL_START_YEAR;
    next_greg_date->mm = orig_date->nMonth;
    next_greg_date->dd = orig_date->nDay;

    return orig_date->DayIndex;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_festival_str_id
 * DESCRIPTION
 *  get the festivals string id for given festival id
 * PARAMETERS
 *  fest_index      [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_festival_str_id(U8 fest_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nFestivalStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fest_index)
    {

      /*----------------- Fix date festivals -----------------------*/

        case MMI_INDICAL_GURU_GOVIND_SINGH_JAYANTI:
            nFestivalStrid = STR_INDICAL_GURU_GOVIND_SINGH_JAYANTI;
            break;

        case MMI_INDICAL_LOHRI:
            nFestivalStrid = STR_INDICAL_LOHRI;
            break;

        case MMI_INDICAL_MAKAR_SAKRANTI:
            nFestivalStrid = STR_INDICAL_MAKAR_SAKRANTI;
            break;

        case MMI_INDICAL_BAISHAKHI:
            nFestivalStrid = STR_INDICAL_BAISHAKHI;
            break;

      /*----------------- Variable date festivals ------------------*/

        case MMI_INDICAL_BASANT_PANCHMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_BASANT_PANCHMI;
            break;

        case MMI_INDICAL_MAHASHIV_RATRI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_MAHASHIV_RATRI;
            break;

        case MMI_INDICAL_HOLIKA_DEHAN + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_HOLIKA_DEHAN;
            break;

        case MMI_INDICAL_HOLI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_HOLI;
            break;

        case MMI_INDICAL_NAV_VARSHA + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_NAV_VARSHA;
            break;

        case MMI_INDICAL_RAM_NAVMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_RAM_NAVMI;
            break;

        case MMI_INDICAL_RAKSHA_BANDHAN + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_RAKSHA_BANDHAN;
            break;

        case MMI_INDICAL_JANMASTMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_JANMASTMI;
            break;

        case MMI_INDICAL_GANESH_CHATURTHI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_GANESH_CHATURTHI;
            break;

        case MMI_INDICAL_NAWMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_NAWMI;
            break;

        case MMI_INDICAL_DASHEHRA + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_DASHEHRA;
            break;

        case MMI_INDICAL_DEEPAWALI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalStrid = STR_INDICAL_DEEPAWALI;
            break;
        default:
            break;

    }

    return nFestivalStrid;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_festival_details_str_id
 * DESCRIPTION
 *  returns festival details string id
 * PARAMETERS
 *  fest_index      [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_festival_details_str_id(U8 fest_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nFestivalDetailsStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fest_index)
    {

      /*----------------- Fix date festivals -------------------------------*/

        case MMI_INDICAL_GURU_GOVIND_SINGH_JAYANTI:
            nFestivalDetailsStrid = STR_INDICAL_GURU_GOVIND_SINGH_JAYANTI_DETAILS;
            break;

        case MMI_INDICAL_LOHRI:
            nFestivalDetailsStrid = STR_INDICAL_LOHRI_DETAILS;
            break;

        case MMI_INDICAL_MAKAR_SAKRANTI:
            nFestivalDetailsStrid = STR_INDICAL_MAKAR_SAKRANTI_DETAILS;
            break;

        case MMI_INDICAL_BAISHAKHI:
            nFestivalDetailsStrid = STR_INDICAL_BAISHAKHI_DETAILS;
            break;

      /*----------------- Variable date festivals -------------------------*/

        case MMI_INDICAL_BASANT_PANCHMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_BASANT_PANCHMI_DETAILS;
            break;

        case MMI_INDICAL_MAHASHIV_RATRI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_MAHASHIV_RATRI_DETAILS;
            break;

        case MMI_INDICAL_HOLIKA_DEHAN + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_HOLIKA_DEHAN_DETAILS;
            break;

        case MMI_INDICAL_HOLI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_HOLI_DETAILS;
            break;

        case MMI_INDICAL_NAV_VARSHA + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_NAV_VARSHA_DETAILS;
            break;

        case MMI_INDICAL_RAM_NAVMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_RAM_NAVMI_DETAILS;
            break;

        case MMI_INDICAL_RAKSHA_BANDHAN + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_RAKSHA_BANDHAN_DETAILS;
            break;

        case MMI_INDICAL_JANMASTMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_JANMASTMI_DETAILS;
            break;

        case MMI_INDICAL_GANESH_CHATURTHI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_GANESH_CHATURTHI_DETAILS;
            break;

        case MMI_INDICAL_NAWMI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_NAWMI_DETAILS;
            break;

        case MMI_INDICAL_DASHEHRA + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_DASHEHRA_DETAILS;
            break;

        case MMI_INDICAL_DEEPAWALI + MMI_INDICAL_MAX_FIX_DATE_FESTIVALS:
            nFestivalDetailsStrid = STR_INDICAL_DEEPAWALI_DETAILS;
            break;

        default:
            break;
    }

    return nFestivalDetailsStrid;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_set_highlight_index
 * DESCRIPTION
 *  set the highlight index
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_set_highlight_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_indical_cntx.indiCalFestivalHighlightIndex = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_tithi_str_id
 * DESCRIPTION
 *  returns the tithi string id for tithi enum
 * PARAMETERS
 *  tithi       [IN]        
 *  paksha      [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_indical_get_tithi_str_id(U8 tithi, U8 paksha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nTithiStrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tithi)
    {
        case MMI_INDICAL_EKAM:

            nTithiStrid = STR_INDICAL_EKAM;
            break;

        case MMI_INDICAL_DWITIYA:

            nTithiStrid = STR_INDICAL_DWITIYA;
            break;

        case MMI_INDICAL_TRITIYA:

            nTithiStrid = STR_INDICAL_TRITIYA;
            break;

        case MMI_INDICAL_CHATURTHI:

            nTithiStrid = STR_INDICAL_CHATURTHI;
            break;

        case MMI_INDICAL_PANCHAMI:

            nTithiStrid = STR_INDICAL_PANCHAMI;
            break;

        case MMI_INDICAL_SASTHI:

            nTithiStrid = STR_INDICAL_SASTHI;
            break;

        case MMI_INDICAL_SAPTAMI:

            nTithiStrid = STR_INDICAL_SAPTAMI;
            break;

        case MMI_INDICAL_ASTHAMI:

            nTithiStrid = STR_INDICAL_ASTHAMI;
            break;

        case MMI_INDICAL_NAVMI:

            nTithiStrid = STR_INDICAL_NAVMI;
            break;

        case MMI_INDICAL_DASHMI:

            nTithiStrid = STR_INDICAL_DASHMI;
            break;

        case MMI_INDICAL_EKADASHI:

            nTithiStrid = STR_INDICAL_EKADASHI;
            break;

        case MMI_INDICAL_DUADASHI:

            nTithiStrid = STR_INDICAL_DWADASHI;
            break;

        case MMI_INDICAL_TRIYODASHI:

            nTithiStrid = STR_INDICAL_TRAYODASHI;
            break;

        case MMI_INDICAL_CHATURDASHI:

            nTithiStrid = STR_INDICAL_CHATURDASHI;
            break;

        case MMI_INDICAL_PURANMASI:
            /*       case MMI_INDICAL_AMAVASYA  : */
        {

            if (paksha == MMI_INDICAL_KRISHANA_PAKSHA)
            {
                nTithiStrid = STR_INDICAL_AMAVASYA;
            }

            if (paksha == MMI_INDICAL_SHUKLA_PAKSHA)
            {
                nTithiStrid = STR_INDICAL_PURANMASI;
            }
        }

            break;

        default:
            break;

    }

    return nTithiStrid;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_indian_date_str
 * DESCRIPTION
 *  Get the Indian date string for display as pop up
 * PARAMETERS
 *  curr_time               [IN]
 *  str_indian_paksha        [OUT]       
 *  str_indian_tithi        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_indian_date_str(
        MYTIME curr_time,
        U8 *str_indian_paksha,
        U8 *str_indian_tithi)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_indical_gregorian_date_struct gregorian_date;
    mmi_indical_indian_date_struct indian_date = {0};
    U8 weekday;
    U8 str_indian_date[MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH] = {0};
    MMI_BOOL is_date_within_range = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We need to check the date before processing */
    is_date_within_range = mmi_indical_monthly_out_of_boundary(&curr_time, MMI_FALSE);
    if (MMI_FALSE == is_date_within_range)
    {
        return;
    }

    gregorian_date.yy = curr_time.nYear - INDICAL_START_YEAR;
    gregorian_date.mm = curr_time.nMonth;
    gregorian_date.dd = curr_time.nDay;

    weekday = increment_gregorian_date(curr_time, 0, NULL);

    /* We need to reset the global indical info struct before getting new data */
    g_mmi_indical_cntx.mmi_indical_info_struct.indical_adhika_month_prefix = -1;

    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & gregorian_date,
        weekday,
        (mmi_indical_indian_date_struct*) & indian_date,
        str_indian_date);

    if (15 == indian_date.tithi)
    {
        mmi_ucs2cpy(
            (S8*) str_indian_tithi,
            (S8*) GetString(mmi_indical_get_tithi_str_id(indian_date.tithi, indian_date.paksha)));
    }
    else
    {
        mmi_ucs2cpy((S8*) str_indian_paksha, (S8*) GetString(mmi_indical_get_short_paksha_strid(indian_date.paksha)));
        mmi_ucs2cpy(
            (S8*) str_indian_tithi,
            (S8*) GetString(mmi_indical_get_tithi_str_id(indian_date.tithi, indian_date.paksha)));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_date_str
 * DESCRIPTION
 *  Fills the calendar title.
 * PARAMETERS
 *  void
 * RETURNS
 *  whether the title string is filled or not.
 *****************************************************************************/
pBOOL mmi_indical_get_date_str(MYTIME curr_time, U8* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_indical_gregorian_date_struct gregorian_date;
    mmi_indical_indian_date_struct indian_date = {0};
    U8 weekday;
    U16 samvat_year;
    U8 str_indian_date[MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH] = {0};
    MMI_BOOL is_date_within_range = MMI_FALSE;
    S8 ascii_str[MMI_CLNDR_MAX_YEAR_BUF_SIZE];
    S8 unicode_str[MMI_CLNDR_MAX_YEAR_BUF_SIZE * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_date_within_range = mmi_indical_monthly_out_of_boundary(&curr_time, MMI_FALSE);
    if (MMI_FALSE == is_date_within_range)
    {
        
        return MMI_FALSE;
    }

    gregorian_date.yy = curr_time.nYear - INDICAL_START_YEAR;
    gregorian_date.mm = curr_time.nMonth;
    gregorian_date.dd = curr_time.nDay;

    weekday = increment_gregorian_date(curr_time, 0, NULL);

    /* We need to reset the global indical info struct before getting new data */
    g_mmi_indical_cntx.mmi_indical_info_struct.indical_adhika_month_prefix = -1;
    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & gregorian_date,
        weekday,
        (mmi_indical_indian_date_struct*) & indian_date,
        str_indian_date);

    memset(&ascii_str, 0, MMI_CLNDR_MAX_YEAR_BUF_SIZE);
    memset(&unicode_str, 0, MMI_CLNDR_MAX_YEAR_BUF_SIZE * ENCODING_LENGTH);

    samvat_year = INDICAL_START_YEAR + mmi_indical_get_samvat_year(&gregorian_date);
    sprintf(ascii_str, "%d", samvat_year);
    mmi_asc_to_ucs2(unicode_str, ascii_str);

    mmi_ucs2cpy((S8*) title, (S8*) GetString(mmi_indical_get_month_strid(indian_date.month)));
    mmi_ucs2cat((S8*) title, (S8*) " ");

    mmi_ucs2ncat((S8*) title, (S8*) unicode_str, MMI_CLNDR_MAX_YEAR_BUF_SIZE);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_indian_date_string
 * DESCRIPTION
 *  returns Indian date string
 * PARAMETERS
 *  void
 * RETURNS
 *  CHAR *
 *****************************************************************************/
CHAR *mmi_indical_get_indian_date_string(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_data = (CHAR *) OslMalloc((MAX_LEN_STR_INDIAN_DATE + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy(ucs2_data, g_mmi_indical_cntx.indianDateString);
    return ucs2_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_update_festival_date_for_offset
 * DESCRIPTION
 *  This function add the offset value to the base function date
 * PARAMETERS
 *  indical_festival            [IN/OUT]        
 *  nvari_date_fest_index       [IN]            
 *  nYear                       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_update_festival_date_for_offset(
        indical_festivals_base_struct *indical_festival,
        U8 nvari_date_fest_index,
        U16 nYear)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME tDateTimeBaseFest;
    MYTIME tDateTimeOffset = {0}, tDateTimeBasePlusOffset;
    S16 nOffsetValue = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*------------------- Filling the base dates for the festivals ----------*/
    tDateTimeBaseFest = g_mmi_indical_cntx.curr_greg_time;
    tDateTimeBaseFest.nMonth = indical_festival->mm;
    tDateTimeBaseFest.nDay = indical_festival->dd;

   /*---- Offset calculations are done by 2000 year as base year -----------*/
    tDateTimeBaseFest.nYear = INDICAL_START_YEAR;

   /*------------------- Finding the offset for the current year -----------*/

    if (nYear < INDICAL_START_YEAR)
    {
        nYear += INDICAL_START_YEAR;
    }
    nOffsetValue = indical_festivals_offset_array[nYear - INDICAL_START_YEAR][nvari_date_fest_index];

   /*------------------- Initialization of the offset struct ---------------*/
    tDateTimeOffset.nYear = 0;
    tDateTimeOffset.nMonth = 0;
    tDateTimeOffset.nDay = 0;
    tDateTimeOffset.nHour = 0;
    tDateTimeOffset.nMin = 0;
    tDateTimeOffset.nSec = 0;
    tDateTimeOffset.DayIndex = 0;

   /*------------------- Add the offset to base date of the festival -------*/

    if (nOffsetValue < 0)
    {
        tDateTimeOffset.nDay = (U8) (-nOffsetValue);
        DecrementTime(tDateTimeBaseFest, tDateTimeOffset, &tDateTimeBasePlusOffset);
    }
    else
    {
        tDateTimeOffset.nDay = (U8) (nOffsetValue);
        IncrementTime(tDateTimeBaseFest, tDateTimeOffset, &tDateTimeBasePlusOffset);
    }

   /*------------------- assign the calculated date in the festival --------*/
   /*------------------- struct for further calculations -------------------*/

    indical_festival->dd = tDateTimeBasePlusOffset.nDay;
    indical_festival->mm = tDateTimeBasePlusOffset.nMonth;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_check_for_single_tithi_two_gdate
 * DESCRIPTION
 *  This function find if one tithi prevails over two gregorian dates.
 *  This function is added in the code because previously the case of single tithi on
 *  2 gregorian dates was not handled. This functionality is required when yearly tithi is to be calculated.
 *  Because everytime we calculate a matching tithi we need to check whether the next tithi is the same or not.
 *  This function is not required while calculating tithi for a given gregorian date as opposed to its counterpart
 *  mmi_indical_check_for_two_tithi_same_gdate because we need to display both the tithis when
 *  they fall on a single gregorian date.
 * PARAMETERS
 *  gregorian_date      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_check_for_single_tithi_two_gdate(mmi_indical_gregorian_date_struct *gregorian_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    indical_special_tithi_struct indical_special_tithi;
    U8 single_tithi_on_two_date = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*-------- Read the special tithi details for the given date ------------*/
    indical_special_tithi = indical_special_tithi_array[gregorian_date->yy][gregorian_date->mm - 1];

    if ((indical_special_tithi.st_dd.dd1 != 0) && (indical_special_tithi.st_dd.dd1 == gregorian_date->dd))
    {
        single_tithi_on_two_date = 2;
    }

    if ((indical_special_tithi.st_dd.dd2 != 0) && (indical_special_tithi.st_dd.dd2 == gregorian_date->dd))
    {
        single_tithi_on_two_date = 2;
    }
    return single_tithi_on_two_date;
}

#ifdef __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_fill_adhika_month_array_single
 * DESCRIPTION
 *  This function finds the gregorian month having whose base tithi contains the
 *  adhika month entry as listed in indical_adhika_month_detail_array for that
 *  particlular year and fills the values in the global variable indical_adhika_month_info_year.
 * PARAMETERS
 *  indical_adhika_month      [IN]
 *  year        [IN]
 * RETURNS
 *  
 *****************************************************************************/
void mmi_indical_fill_adhika_month_array_single(indical_adhika_month_struct *indical_adhika_month, U8 year)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_indical_indian_date_struct indical_indian_date;
    mmi_indical_gregorian_date_struct gregorian_date = {0}, temp_gregorian_date, greg_date_first_ekam = {0}, greg_date_third_ekam = {0};
    MYTIME time, time_to_adjust = {0};
    U8 adhika_month, days_to_paksh_end = 0, counter, month_counter;//, weekday
    U8 inc_month, single_tithi_two_greg_dates, flag, tithi_flag;
    S8 tithi_delta;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Gets the adhika month value from the array */
    adhika_month = indical_adhika_month_detail_array[year];    
    
    /* If no adhika month present in the year then fill the prathama and dwitiya field with 0 */
    if (adhika_month == MMI_INDICAL_NO_ADHIKA_MONTH)
    {
        indical_adhika_month->prathama = 0;
        indical_adhika_month->dwitiya = 0;
    }
    else
    {
        inc_month = 0;
        flag = 0;
        tithi_flag = 0;

        /* Month_counter stores the index value of the gregorian year having base date entry as (_,adhika_month-1) */
        month_counter = mmi_indical_go_to_greg_month(year, adhika_month);

        /* If there are consecutive base date entries containing the value of the adhika month then fill the respective gregorian months in prathama and dwitiya */
        if (indical_base_tithi_array[year][month_counter + MMI_INDICAL_INDEX_TO_NORMAL].month == indical_base_tithi_array[year][month_counter + MMI_INDICAL_INDEX_TO_NORMAL +1].month)
        {
            indical_adhika_month->prathama = month_counter + MMI_INDICAL_INDEX_TO_NORMAL +1;
            indical_adhika_month->dwitiya = month_counter + MMI_INDICAL_INDEX_TO_NORMAL +2;
        }
        else
        {
            /* time_to_adjust will store the value of tithi_delta in its nDay field so as to make
             * adjustments in case of special tithis, i.e, 2 tithis on single gregorian date and single tithi on two gregorian dates */
            mmi_indical_initialise_time_from_date(&time_to_adjust, gregorian_date);

            /*initialise this structure with the 1st of the month*/
            gregorian_date.yy = year;
            gregorian_date.mm = month_counter + 1;
            gregorian_date.dd = 1;

            /*Store the value in MYTIME object also because we would like to increment gregorian date also while determining for the elasped month*/
            mmi_indical_initialise_time_from_date(&time, gregorian_date);        
        
            /*Get the base date*/
            mmi_indical_get_base_tithi(&indical_indian_date, year, month_counter);
        
            /*This loop will look for whether an indian month has elasped in between a gregorian month*/
            for (counter = 0; counter < 2; counter++)
            {
                /* If either prathama month's or dwitiya month's entry is missing in the base date array
                 * then surely the the base date of previous month to adhika month is (>15,_), which means to
                 * reach to puranmaasi we need to subtract from 15 only*/
                if (flag == 0)
                {
                    days_to_paksh_end = 15 - indical_indian_date.tithi;            
                }
                /* flag is set 1 only when we have found a month transition from the base date.
                 * So for another month transition we have to subtract from 30 now.*/
                if (flag == 1)
                {
                    days_to_paksh_end = 30 - indical_indian_date.tithi;
                }
                        
                temp_gregorian_date.yy = gregorian_date.yy;
                temp_gregorian_date.mm = gregorian_date.mm;
                temp_gregorian_date.dd = LastDayOfMonth(time.nMonth, time.nYear);            

                //weekday = 
				increment_gregorian_date_update_orig_date(&time, days_to_paksh_end, &gregorian_date);
                /*temp_gregorian_date is required because while incrementing the gregorian date by 30, we might be jumping gregorian month.
                As a result of which the special days for previous month are missed.
                So first we calculate tithi_delta for temp_gregorian_date and then again for gregorian_date and add these 2 values.*/
                if (gregorian_date.mm > temp_gregorian_date.mm)
                {
                    tithi_delta = (S8)(mmi_indical_get_tithi_delta((mmi_indical_gregorian_date_struct*) &temp_gregorian_date));
                    tithi_delta = tithi_delta + (S8)(mmi_indical_get_tithi_delta((mmi_indical_gregorian_date_struct*) &gregorian_date));
                }
                else
                {
                    tithi_delta = (S8)(mmi_indical_get_tithi_delta((mmi_indical_gregorian_date_struct*) &gregorian_date));
                }
            
                /* To make adjustments in gregorian date for special conditions. tithi_flag is set 1 whenver 
                 * adjustement is made in gregorian date and is set 0 when those adjustments are reverted back.
                 * Adjustment needs to be reverted back otherwise double adjustments will be made.
                 * e.g. if we start from (29,6) and say (30,6) indian date is special
                 * Here adjustments are made for counter =0.
                 * If adjustmenst not reverted back, then for counter = 1, adjustments for counter = 0 again made. */
                if(tithi_delta != 0)
                {
                    mmi_indical_special_tithi_adjust(&time, &time_to_adjust, tithi_delta, tithi_flag);                
                    increment_gregorian_date(time, (U8)(0), &gregorian_date);
                    tithi_flag = 1;
                }
            
                /* Indian tithi is made zero because it is now purnima. While fetching tithi from base data,
                 * if tithi is amavasya or puranmaasi, value got is 0, which is then made 15. Here no such adjustment required. */
                indical_indian_date.tithi = 0;
                if (indical_indian_date.paksha == 1 || flag == 1)
                {
                    inc_month++;
                }
                indical_indian_date.paksha = !(indical_indian_date.paksha);

                single_tithi_two_greg_dates = mmi_indical_check_for_single_tithi_two_gdate((mmi_indical_gregorian_date_struct*) &gregorian_date);

                if (inc_month == 1 && flag == 0)
                {
                    /* We wish to reach ekam of next month from base date not puranmaasi of same month.
                     * mmi_indical_check_for single_tithi_tow_gdate function returns 1 even if no single tithi on 2 gregorian dates is present.
                     * So its value is taken to reach next ekam.*/
                    time_to_adjust.nDay = single_tithi_two_greg_dates;
                    //weekday = 
					increment_gregorian_date_update_orig_date(&time, (U8)(single_tithi_two_greg_dates), &gregorian_date);
                    DecrementTime(time, time_to_adjust, &time);
               
                    greg_date_first_ekam = gregorian_date;                                        
                    flag = 1;
                }
                /*Now we wish to reach puranmaasi of same month and not to the ekam.*/
                if(inc_month == 2)
                {                
                    if (single_tithi_two_greg_dates == 2)
                    {
                        //weekday = 
						increment_gregorian_date_update_orig_date(&time, (U8)(1), &gregorian_date);
                    }
                    greg_date_third_ekam = gregorian_date;
                }
                /* Changes for special conditions are reverted back */
                if(tithi_delta != 0)
                {                
                    mmi_indical_special_tithi_adjust(&time, &time_to_adjust, tithi_delta, tithi_flag);               
                    increment_gregorian_date(time, (U8)(0), &gregorian_date);
                    tithi_flag = 0;
                }
            }
            /* Conditions for determining whether the month is prathama month or dwitiya month */
            
            if (greg_date_first_ekam.mm == greg_date_third_ekam.mm)
            {
                /* It means that an indian month is starting and ending inside a gregorian month.
                 * So its entry will not be present in the base date.*/
                indical_adhika_month->prathama = 0;
                indical_adhika_month->dwitiya = month_counter + MMI_INDICAL_INDEX_TO_NORMAL +1;                                                          
            }
            else
            {
                indical_adhika_month->prathama = month_counter + MMI_INDICAL_INDEX_TO_NORMAL +1;
                indical_adhika_month->dwitiya = 0;
            }
        }
    }
    indical_adhika_month->year = year;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_initialise_time_from_date
 * DESCRIPTION
 *  This function initialises the MYTIME structure from mmi_indical_gregorian_date_struct structure.
 * PARAMETERS
 *  time                    [IN]
 *  indical_gregorian_date  [IN]
 * RETURNS
 *  
 *****************************************************************************/
void mmi_indical_initialise_time_from_date(MYTIME *time, mmi_indical_gregorian_date_struct indical_gregorian_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time->nDay = indical_gregorian_date.dd;
    time->nMonth = indical_gregorian_date.mm;
    if (indical_gregorian_date.yy == 0)
    {
        time->nYear = indical_gregorian_date.yy;
    }
    else
    {
        time->nYear = indical_gregorian_date.yy + INDICAL_START_YEAR;
    }
    time->nHour = 0;
    time->nMin = 0;
    time->nSec = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_go_to_greg_month
 * DESCRIPTION
 *  This function returns the gregorian month value of that month whose indian base date's
 *  month is (adhika month - 1).
 * PARAMETERS
 *  year            [IN]
 *  adhika_month    [IN]
 * RETURNS
 *  gregorian_month  
 *****************************************************************************/
U8 mmi_indical_go_to_greg_month(U8 year, U8 adhika_month)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 prev_adhika_month;
    U8 gregorian_month = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (adhika_month == 0)
    {
        prev_adhika_month = 11;
    }
    else
    {
        prev_adhika_month = adhika_month - 1;
    }

    while (gregorian_month < INDICAL_NO_OF_MONTHS_PER_YEAR)
    {               
        /*To reach to base date of previous month*/
       if (indical_base_tithi_array[year][gregorian_month].month == prev_adhika_month)
       {
           break;
       }
       else
       {
           gregorian_month++;
       }
    }
    return gregorian_month;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_base_tithi
 * DESCRIPTION
 *  This function adjusts the indian base date value taken from indical_base_tithi_array.
 * PARAMETERS
 *  indical_indian_date     [IN]
 *  year                    [IN]
 *  month_counter           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_base_tithi(mmi_indical_indian_date_struct *indical_indian_date, U8 year, U8 month_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    indical_indian_date->tithi = indical_base_tithi_array[year][month_counter].tithi % 15;
    indical_indian_date->paksha = indical_base_tithi_array[year][month_counter].tithi / 15;
    indical_indian_date->month = indical_base_tithi_array[year][month_counter].month;
    /* If indian tithi comes out be zero, it means that it is either puranmaasi or amavasya */
    if (indical_indian_date->tithi == 0)
    {
        indical_indian_date->tithi = 15;
        if (indical_indian_date->paksha == 2)
        {
            indical_indian_date->paksha = 1;
        }
        else
        {
            indical_indian_date->paksha = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_special_tithi_adjust
 * DESCRIPTION
 *  This function increments or decrements time by the value of tithi_delta.
 * PARAMETERS
 *  time1           [IN]        
 *  time2           [IN]        
 *  tithi_delta     [IN]        
 *  flag            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_special_tithi_adjust(MYTIME *time1, MYTIME *time2, S8 tithi_delta, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tithi_delta > 0)
    {
        time2->nDay = (U8) (tithi_delta);
        if (flag == 0)
        {
            DecrementTime(*time1, *time2, time1);
        }
        if (flag == 1)
        {
            IncrementTime(*time1, *time2, time1);
        }
    }
    else
    {
        time2->nDay = (U8) (-tithi_delta);
        if (flag == 0)
        {
            IncrementTime(*time1, *time2, time1);
        }
        if (flag == 1)
        {
            DecrementTime(*time1, *time2, time1);
        }
    }
}
#endif /*MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN*/

/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_fest_date
 * DESCRIPTION
 *  This function gets Gregorian date of the highlighted festival.
 * PARAMETERS
 *  *time    [OUT]
 * RETURNS
 *  U8
 *****************************************************************************/
void mmi_indical_get_fest_date(MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_greg_ansii_date[11] = {0}, *tok_ptr, *last_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) str_greg_ansii_date, (S8*) g_mmi_indical_cntx.popupList[g_mmi_indical_cntx.indiCalFestivalHighlightIndex/*selectedFestivalIndex*/]);

    tok_ptr = (S8*) strtok_r((S8*) str_greg_ansii_date, (S8*) "/", &last_ptr);
    time->nYear = atoi((S8*) tok_ptr);

    tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
    time->nMonth = atoi((S8*) tok_ptr);

    tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
    time->nDay = atoi((S8*) tok_ptr);

    time->nHour = time->nMin = time->nSec = time->DayIndex = 0;
}

#ifdef __MMI_TODOLIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_indical_add_reminder
 * DESCRIPTION
 *  Adding reminder on tithi.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_add_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    MYTIME start_time, end_time;
    U8 sub_buff[100];
    srv_tdl_repeat_struct repeat;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sub_buff, 0, sizeof(sub_buff));
    mmi_indical_get_reminder_date(&start_time);
    mmi_indical_get_reminder_date(&end_time);
    mmi_indical_get_reminder_name(sub_buff);

    if (g_mmi_indical_cntx.reminder_for_indical == MMI_INDICAL_TITHI_REMINDER)
    {
        cui_menu_close(cui_menu_cui_indical_tithi_option_gid);
    }
    else
    {
        cui_menu_close(cui_menu_cui_indical_festival_option_gid);
    }
    sg_id = cui_cal_save_create(GRP_ID_CAL_MAIN);
    cui_cal_save_set_start_time(sg_id, &start_time);
    cui_cal_save_set_end_time(sg_id, &end_time);
    cui_cal_save_set_subject(sg_id, (U16*) (sub_buff));
    if (g_mmi_indical_cntx.reminder_for_indical == MMI_INDICAL_TITHI_REMINDER)
    {
        repeat.rule = MMI_TDL_RULE_TITHI;
        cui_cal_save_set_repeat(sg_id, &repeat);
    }
    cui_cal_save_set_category(sg_id, MMI_TDL_CATEGORY_REMINDER);
    cui_cal_save_set_title(sg_id, STR_GLOBAL_ADD);
    cui_cal_save_set_operation_type(sg_id, MMI_TDL_OP_TYPE_ADD);
    cui_cal_save_run(sg_id);
    g_mmi_indical_cntx.reminder_for_indical = MMI_INDICAL_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_pre_entry_add_tithi_reminder
 * DESCRIPTION
 *  Pre entry function of add reminder screen for tithi.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_pre_entry_add_tithi_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_indical_cntx.reminder_for_indical = MMI_INDICAL_TITHI_REMINDER;
    mmi_indical_add_reminder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_pre_entry_add_festival_reminder
 * DESCRIPTION
 *  Pre entry function of add reminder screen for festival.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_pre_entry_add_festival_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_indical_cntx.reminder_for_indical = MMI_INDICAL_FESTIVAL_REMINDER;
    mmi_indical_add_reminder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_query_reminder
 * DESCRIPTION
 *  Returns that the reminder is for hijri festivals.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_indical_query_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_indical_cntx.reminder_for_indical;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_reminder_name
 * DESCRIPTION
 *  Fills the name of the festival.
 * PARAMETERS
 *  *str_buff    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_reminder_name(U8 *str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    U8 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_indical_cntx.reminder_for_indical == MMI_INDICAL_FESTIVAL_REMINDER)
    {
        while (g_mmi_indical_cntx.indiCalFestivalHighlightIndex/*selectedFestivalIndex*/ != g_mmi_indical_cntx.fest_disp_index[index])
        {
            index++;
        }
        str_id = mmi_indical_get_festival_str_id(index);
        mmi_ucs2cpy((S8*) str_buff, GetString(str_id));
    }
    
    if (g_mmi_indical_cntx.reminder_for_indical == MMI_INDICAL_TITHI_REMINDER)
    {
        if (g_mmi_indical_cntx.indianDate.tithi == 15 && g_mmi_indical_cntx.indianDate.paksha == 0)
        {
            str_id = STR_INDICAL_AMAVASYA;
        }
        else if (g_mmi_indical_cntx.indianDate.tithi == 15 && g_mmi_indical_cntx.indianDate.paksha == 1)
        {
            str_id = STR_INDICAL_PURANMASI;
        }
        else
        {        
            str_id = STR_INDICAL_EKAM + (U16) g_mmi_indical_cntx.indianDate.tithi - 1;
        }
        mmi_ucs2cpy((S8*) str_buff, GetString(str_id));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_reminder_date
 * DESCRIPTION
 *  Provides the date of the festival.
 * PARAMETERS
 *  *time    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_reminder_date(MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_indical_cntx.reminder_for_indical == MMI_INDICAL_TITHI_REMINDER)
    {
        time->nYear = g_mmi_indical_cntx.curr_greg_time.nYear;
        time->nMonth = g_mmi_indical_cntx.curr_greg_time.nMonth;
        time->nDay = g_mmi_indical_cntx.curr_greg_time.nDay;

        time->nHour = time->nMin = time->nSec = time->DayIndex = 0;
    }
    if (g_mmi_indical_cntx.reminder_for_indical == MMI_INDICAL_FESTIVAL_REMINDER)
    {
        mmi_indical_get_fest_date(time);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_date_for_next_tithi
 * DESCRIPTION
 *  This function gets Gregorian date of the next same tithi into the MYTIME structure.
 * PARAMETERS
 *  *time    [OUT]
 *  start_time  [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_get_date_for_next_tithi(MYTIME *time, MYTIME start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_indical_gregorian_date_struct gregorian_date, reminder_greg_date;
    mmi_indical_indian_date_struct next_indical_indian_date, reminder_tithi;
    U8 weekday = 0;
    U8 indian_date_str[MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH], days = 0;
    U8 single_tithi_two_greg_dates, two_tithi_same_gdate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&gregorian_date, 0, sizeof(mmi_indical_gregorian_date_struct));
    gregorian_date.yy = time->nYear - INDICAL_START_YEAR;
    gregorian_date.mm = time->nMonth;
    gregorian_date.dd = time->nDay;

    reminder_greg_date.yy = start_time.nYear - INDICAL_START_YEAR;
    reminder_greg_date.mm = start_time.nMonth;
    reminder_greg_date.dd = start_time.nDay;
    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & reminder_greg_date,
        weekday,
        (mmi_indical_indian_date_struct*) & reminder_tithi,
        indian_date_str);
    
    /*----To get the date into gregorian_date----*/

    /*----To calculate whether single tithi falls on 2 gregorian dates or not----*/
    single_tithi_two_greg_dates = mmi_indical_check_for_single_tithi_two_gdate(&gregorian_date);

    if (single_tithi_two_greg_dates == 2)
    {
        weekday = increment_gregorian_date_update_orig_date(time, (U8) (1), &gregorian_date);
        days++;
        if (time->nYear > INDICAL_END_YEAR)
        {
            return days;
        }
    }
    else
    {
        if (reminder_tithi.tithi == 15)
        {
            days = 27;  /* Next purnima or amavasya will fall after one month---- */
        }
        else
        {
            days = 12;
        }
        weekday = increment_gregorian_date_update_orig_date(time, days, &gregorian_date);
        if (time->nYear > INDICAL_END_YEAR)
        {
            return days;
        }
    
        mmi_indical_get_indian_date(
            (mmi_indical_gregorian_date_struct*) & gregorian_date,
            weekday,
            (mmi_indical_indian_date_struct*) & next_indical_indian_date,
            indian_date_str);

        while (next_indical_indian_date.tithi != reminder_tithi.tithi)
        {

        /*---------------------- Increment by 1 and check --------------------*/
            two_tithi_same_gdate = mmi_indical_check_for_two_tithi_same_gdate(&gregorian_date);
            if (two_tithi_same_gdate)
            {
                if (reminder_tithi.tithi == 1 && next_indical_indian_date.tithi == 15)
                {
                    return days;
                }
                else
                {
                    if (reminder_tithi.tithi == (next_indical_indian_date.tithi + 1))
                    {
                        return days;
                    }
                }
            }
            weekday = increment_gregorian_date_update_orig_date(time, (U8) (1), &gregorian_date);
            days++;

            if (time->nYear > INDICAL_END_YEAR)
            {
                return days;
            }
            else
            {
                mmi_indical_get_indian_date(
                    (mmi_indical_gregorian_date_struct*) & gregorian_date,
                    weekday,
                    (mmi_indical_indian_date_struct*) & next_indical_indian_date,
                    indian_date_str);
            }

        }
    }
    return days;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_find_dow
 * DESCRIPTION
 *  Finds the day of week in the month which will have the same tithi as on the reminder date.
 * PARAMETERS
 *  curr_date           [IN]        
 *  reminder_date       [IN][OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_find_dow(MYTIME curr_date, MYTIME *reminder_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_indical_indian_date_struct indical_reminder_indian_date, indical_curr_month_date;
    mmi_indical_gregorian_date_struct gregorian_date;
    MYTIME time;
    U8 weekday = 0, days = 0;
    U8 indian_date_str[MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH];
    U8 two_tithi_same_gdate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gregorian_date.dd = reminder_date->nDay;
    gregorian_date.mm = reminder_date->nMonth;
    gregorian_date.yy = reminder_date->nYear - INDICAL_START_YEAR;
    memset(&indical_reminder_indian_date, 0, sizeof(mmi_indical_indian_date_struct));
    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & gregorian_date,
        weekday,
        (mmi_indical_indian_date_struct*) & indical_reminder_indian_date,
        indian_date_str);

    gregorian_date.dd = 1;
    gregorian_date.mm = curr_date.nMonth;
    gregorian_date.yy = curr_date.nYear - INDICAL_START_YEAR;
    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & gregorian_date,
        weekday,
        (mmi_indical_indian_date_struct*) & indical_curr_month_date,
        indian_date_str);

    memset(&time, 0, sizeof(MYTIME));
    time.nDay = gregorian_date.dd;
    time.nMonth = gregorian_date.mm;
    time.nYear = gregorian_date.yy + INDICAL_START_YEAR;

    if (indical_reminder_indian_date.tithi != 15)
    {
        if (indical_reminder_indian_date.tithi > indical_curr_month_date.tithi)
        {
            days = indical_reminder_indian_date.tithi - indical_curr_month_date.tithi;
        }
    }
    else
    {
        if (indical_reminder_indian_date.paksha == indical_curr_month_date.paksha)
        {
            days = indical_reminder_indian_date.tithi - indical_curr_month_date.tithi;
        }
        else
        {
            days = indical_reminder_indian_date.tithi - indical_curr_month_date.tithi + 15;
        }
    }
    if (days >= 2)
    {
        weekday = increment_gregorian_date_update_orig_date(&time, (U8) (days - 2), &gregorian_date);
        mmi_indical_get_indian_date(
            (mmi_indical_gregorian_date_struct*) & gregorian_date,
            weekday,
            (mmi_indical_indian_date_struct*) & indical_curr_month_date,
            indian_date_str);
    }
    while (indical_curr_month_date.tithi != indical_reminder_indian_date.tithi)
    {

    /*---------------------- Increment by 1 and check --------------------*/
        two_tithi_same_gdate = mmi_indical_check_for_two_tithi_same_gdate(&gregorian_date);
        if (two_tithi_same_gdate)
        {
            if (indical_reminder_indian_date.tithi == 1 && indical_curr_month_date.tithi == 15)
            {
                break;
            }
            else
            {
                if (indical_reminder_indian_date.tithi == (indical_curr_month_date.tithi + 1))
                {
                    break;
                }
            }
        }
        weekday = increment_gregorian_date_update_orig_date(&time, (U8) (1), &gregorian_date);

        if (time.nYear > INDICAL_END_YEAR)
        {
            return;
        }
        else
        {
            mmi_indical_get_indian_date(
                (mmi_indical_gregorian_date_struct*) & gregorian_date,
                weekday,
                (mmi_indical_indian_date_struct*) & indical_curr_month_date,
                indian_date_str);
        }

    }
    *reminder_date = time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_is_reminder_in_week
 * DESCRIPTION
 *  Finds whether the reminder falls between the 1st two mentioned dates in the arguments.
 * PARAMETERS
 *  curr_week_begin    [IN]
 *  next_week_begin    [IN]
 *  start_time         [IN]
 *  reminder_date      [OUT]
 * RETURNS
 *  S8
 *****************************************************************************/
U8 mmi_indical_is_reminder_in_week(MYTIME curr_week_begin, MYTIME next_week_begin, MYTIME start_time, MYTIME *reminder_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_indical_indian_date_struct indical_week_start_date, indical_reminder_start_date, indical_reminder_date;
    mmi_indical_gregorian_date_struct gregorian_date, greg_curr_week_begin, greg_start_time;
    MYTIME time;
    U8 weekday = 0;
    U8 indian_date_str[MAX_LEN_STR_INDIAN_DATE * ENCODING_LENGTH];
    U8 two_tithi_same_gdate;
    pBOOL FLAG = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    greg_curr_week_begin.dd = curr_week_begin.nDay;
    greg_curr_week_begin.mm = curr_week_begin.nMonth;
    greg_curr_week_begin.yy = curr_week_begin.nYear - INDICAL_START_YEAR;
    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & greg_curr_week_begin,
        weekday,
        (mmi_indical_indian_date_struct*) & indical_week_start_date,
        indian_date_str);

    greg_start_time.dd = start_time.nDay;
    greg_start_time.mm = start_time.nMonth;
    greg_start_time.yy = start_time.nYear - INDICAL_START_YEAR;
    mmi_indical_get_indian_date(
        (mmi_indical_gregorian_date_struct*) & greg_start_time,
        weekday,
        (mmi_indical_indian_date_struct*) & indical_reminder_start_date,
        indian_date_str);

    time = curr_week_begin;
    gregorian_date.dd = time.nDay;
    gregorian_date.mm = time.nMonth;
    gregorian_date.yy = time.nYear - INDICAL_START_YEAR;
    indical_reminder_date = indical_week_start_date;
    while (applib_dt_compare_time(
            (applib_time_struct*) & time,
            (applib_time_struct*) & next_week_begin,
            NULL) == DT_TIME_LESS)
    {
        two_tithi_same_gdate = mmi_indical_check_for_two_tithi_same_gdate(&gregorian_date);
        if (two_tithi_same_gdate)
        {
            if (indical_reminder_start_date.tithi == 1 && indical_reminder_date.tithi == 15)
            {
                FLAG = TRUE;
            }
            else
            {
                if (indical_reminder_start_date.tithi == (indical_reminder_date.tithi + 1))
                {
                    FLAG = TRUE;
                }
            }
        }
        if (indical_reminder_start_date.tithi != 15)
        {
            if (indical_reminder_date.tithi == indical_reminder_start_date.tithi || FLAG == 1)
            {
                *reminder_date = time;
                return TRUE;
            }
        }
        else
        {
            if ((indical_reminder_date.tithi == indical_reminder_start_date.tithi &&
                indical_reminder_date.paksha == indical_reminder_start_date.paksha) || FLAG == 1)
            {
                *reminder_date = time;
                return TRUE;
            }
        }
        weekday = increment_gregorian_date_update_orig_date(&time, (U8) (1), &gregorian_date);
        mmi_indical_get_indian_date(
            (mmi_indical_gregorian_date_struct*) & gregorian_date,
            weekday,
            (mmi_indical_indian_date_struct*) & indical_reminder_date,
            indian_date_str);
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_check_one_tithi_two_greg_dates
 * DESCRIPTION
 *  Finds whether 2 tithis fall on a single gregorian date or not.
 * PARAMETERS
 *  date      [OUT]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_indical_check_one_tithi_two_greg_dates(MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_indical_gregorian_date_struct gregorian_date;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gregorian_date.dd = date.nDay;
    gregorian_date.mm = date.nMonth;
    gregorian_date.yy = date.nYear - INDICAL_START_YEAR;

    if (mmi_indical_check_for_single_tithi_two_gdate(&gregorian_date) == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif /* __MMI_TODOLIST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_set_saving_tithi_reminder
 * DESCRIPTION
 *  Sets the flag for saving tithi reminder as file.
 * PARAMETERS
 *  pBOOL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_set_saving_tithi_reminder(pBOOL flag)
{
    g_mmi_indical_cntx.saving_tithi_reminder = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_saving_tithi_reminder
 * DESCRIPTION
 *  Sets the flag for saving tithi reminder as file.
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_indical_get_saving_tithi_reminder(void)
{
    return g_mmi_indical_cntx.saving_tithi_reminder;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_festival_icon
 * DESCRIPTION
 *  Sets the flag for saving tithi reminder as file.
 * PARAMETERS
 *  time    [IN]    calendar time to fill the daily task info accordingly
 *  daily_task_info [IN]    date on which icon is to be shown
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_festival_icon(MYTIME clndr_time, mmi_clndr_cell_struct *daily_task_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLNDR_EVENT_INFO__    
    S8 str_greg_ansii_date[11] = {0}, *tok_ptr, *last_ptr;
    MYTIME time[MAX_FESTIVALS];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((clndr_time.nYear >= INDICAL_START_YEAR) && (clndr_time.nYear <= INDICAL_END_YEAR))
    {
        mmi_indical_get_festival_date();
        for (index = 0; index < MAX_FESTIVALS; index++)
        {
            mmi_ucs2_to_asc((S8*) str_greg_ansii_date, (S8*) g_mmi_indical_cntx.popupList[index]);

            tok_ptr = (S8*) strtok_r((S8*) str_greg_ansii_date, (S8*) "/", &last_ptr);
            time[index].nYear = atoi((S8*) tok_ptr);

            tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
            time[index].nMonth = atoi((S8*) tok_ptr);

            tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
            time[index].nDay = atoi((S8*) tok_ptr);

            time[index].nHour = time[index].nMin = time[index].nSec = time[index].DayIndex = 0;
        }
        index = 0;
        while(index < MAX_FESTIVALS)
        {
            if (time[index].nMonth == clndr_time.nMonth)
            {
                break;
            }
            index++;
        }
        if (index == MAX_FESTIVALS)
        {
            return;
        }
        while (time[index].nMonth <= clndr_time.nMonth)
        {
            if (!daily_task_info[time[index].nDay].date)
            {
                daily_task_info[time[index].nDay].date = MMI_TRUE;
                daily_task_info[time[index].nDay].icon = IMG_ID_FESTIVAL_ICON;
            }
            if (index == (MAX_FESTIVALS -1))
            {
                break;
            }
            index++;
        }
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_paksha_end_icon
 * DESCRIPTION
 *  Sets the flag for saving tithi reminder as file.
 * PARAMETERS
 *  time            [IN]    calendar time to fill the daily task info accordingly
 *  daily_task_info [IN]    date on which icon is to be shown
 *  paksha          [IN]    paksha for which icons are to be found
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_paksha_end_icon(MYTIME clndr_time, mmi_clndr_cell_struct *daily_task_info, U8 paksha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_CLNDR_EVENT_INFO__
    MYTIME time[4];
    mmi_indical_gregorian_date_struct indical_gregorian_date;
    mmi_indical_indian_date_struct indical_indian_date;
    U8 index, loop, weekday;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((clndr_time.nYear >= INDICAL_START_YEAR) && (clndr_time.nYear <= INDICAL_END_YEAR))
    {
        for (index = 0; index < 4; index++)
        {
            memset(&time[index], 0, sizeof(MYTIME));
        }
        indical_gregorian_date.dd = 1;
        indical_gregorian_date.mm = clndr_time.nMonth;
        indical_gregorian_date.yy = clndr_time.nYear - INDICAL_START_YEAR;

        weekday = increment_gregorian_date(clndr_time, 0, NULL);
        mmi_indical_get_indian_date(&indical_gregorian_date, weekday, &indical_indian_date, g_mmi_indical_cntx.indianDateString);
        time[0] = clndr_time;
        time[0].nDay = 1;
        mmi_indical_find_paksha_end_date(&time[0], &indical_indian_date, paksha);
        if (time[0].nDay == 0 || time[0].nMonth == 0 || time[0].nYear == 0)
        {
            return;
        }
        indical_gregorian_date.dd = time[0].nDay;
        indical_gregorian_date.mm = time[0].nMonth;
        indical_gregorian_date.yy = time[0].nYear - INDICAL_START_YEAR;
        index = 0;
        while(indical_gregorian_date.mm == clndr_time.nMonth)
        {
            mmi_indical_get_next_same_indian_date(time[index], indical_indian_date, &indical_gregorian_date);            
            index++;
            time[index].nDay = indical_gregorian_date.dd;
            time[index].nMonth = indical_gregorian_date.mm;
            time[index].nYear = indical_gregorian_date.yy + INDICAL_START_YEAR;
            if (time[index].nMonth != clndr_time.nMonth)
            {
                memset(&time[index], 0, sizeof(MYTIME));
                break;
            }
        }
        for (loop = 0; loop < index; loop++)
        {
            if (!daily_task_info[time[loop].nDay].date)
            {
                daily_task_info[time[loop].nDay].date = MMI_TRUE;
                if (paksha == 0)
                {
                    daily_task_info[time[loop].nDay].icon = (U16)(IMG_ID_AMAVASYA);
                }
                else
                {
                    daily_task_info[time[loop].nDay].icon = (U16)(IMG_ID_PURANMAASI);
                }
            }
        }
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_find_paksha_end_date
 * DESCRIPTION
 *  Sets the flag for saving tithi reminder as file.
 * PARAMETERS
 *  time        [IN/OUT]    to store the time of the paksha end date.
 *  indian_date [IN]        the indian date on 1st of the Gregorian month.
 *  paksha      [IN]        The paksha for which the paksha end date is to be found.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_find_paksha_end_date(MYTIME *time, mmi_indical_indian_date_struct *indian_date, U8 paksha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;
    mmi_indical_gregorian_date_struct indical_gregorian_date;    
    U8 weekday;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    if (indian_date->paksha == paksha)
    {
        if (indian_date->tithi > 13)
        {
            incTime.nDay = 0;
        }
        else
        {
            incTime.nDay = 13 - indian_date->tithi;
        }
    }
    else
    {
        incTime.nDay = 27 - indian_date->tithi;
    }
    IncrementTime(*time, incTime, time);
    if (time->nYear > INDICAL_END_YEAR)
    {
        return;
    }
    indical_gregorian_date.dd = time->nDay;
    indical_gregorian_date.mm = time->nMonth;
    indical_gregorian_date.yy = time->nYear - INDICAL_START_YEAR;

    weekday = increment_gregorian_date(*time, 0, NULL);
    mmi_indical_get_indian_date(&indical_gregorian_date, weekday, indian_date, g_mmi_indical_cntx.indianDateString);
    while (indian_date->tithi != 15)
    {
        /*if ((mmi_indical_check_for_single_tithi_two_gdate(&indical_gregorian_date) == 2) && indian_date->tithi == 14)
        {
            break;
        }*/
        incTime.nDay = 1;
        weekday = increment_gregorian_date_update_orig_date(time, 1, &indical_gregorian_date);
        if (time->nYear > INDICAL_END_YEAR)
        {
            return;
        }
        mmi_indical_get_indian_date(&indical_gregorian_date, weekday, indian_date, g_mmi_indical_cntx.indianDateString);
        if (indian_date->paksha != paksha)
        {
            memset(time, 0, sizeof(MYTIME));
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_indical_get_next_same_indian_date
 * DESCRIPTION
 *  get the next same indian date
 * PARAMETERS
 *  next_indian_date_str        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_indical_get_next_same_indian_date(MYTIME time, mmi_indical_indian_date_struct indian_date, mmi_indical_gregorian_date_struct *gregorian_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 next_indian_date_str[MAX_LEN_STR_INDIAN_DATE *ENCODING_LENGTH];
    MYTIME tempTime;
    mmi_indical_indian_date_struct next_indical_indian_date;
    U8 weekday, days, single_tithi_two_greg_dates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    tempTime = time;
    if (indian_date.tithi == 15)
    {
        days = 27;  /* Next purnima or amavasya will fall after one month---- */
    }
    else
    {
        days = 12;
    }
    /*----To get the date into gregorian_date----*/
    weekday = increment_gregorian_date(tempTime, (U8)(0), NULL);

    /*----To calculate whether single tithi falls on 2 gregorian dates or not----*/
    single_tithi_two_greg_dates = mmi_indical_check_for_single_tithi_two_gdate(gregorian_date);

    if (single_tithi_two_greg_dates == 2)
    {
        weekday = increment_gregorian_date_update_orig_date(&tempTime, (U8)(1), gregorian_date);
        if (tempTime.nYear > INDICAL_END_YEAR)
        {
            return;
        }

        mmi_indical_get_indian_date(
            (mmi_indical_gregorian_date_struct*) gregorian_date,
            weekday,
            (mmi_indical_indian_date_struct*) & next_indical_indian_date,
            next_indian_date_str);
    }
    else
    {
        weekday = increment_gregorian_date_update_orig_date(&tempTime, days, gregorian_date);
        if (tempTime.nYear > INDICAL_END_YEAR)
        {
            return;
        }
    
        mmi_indical_get_indian_date(
            (mmi_indical_gregorian_date_struct*) gregorian_date,
            weekday,
            (mmi_indical_indian_date_struct*) & next_indical_indian_date,
            next_indian_date_str);

        while (next_indical_indian_date.tithi != indian_date.tithi)
        {

        /*---------------------- Increment by 1 and check --------------------*/
            weekday = increment_gregorian_date_update_orig_date(&tempTime, (U8) (1), gregorian_date);

            if (tempTime.nYear > INDICAL_END_YEAR)
            {
                return;
            }
            else
            {
                mmi_indical_get_indian_date(
                    (mmi_indical_gregorian_date_struct*) gregorian_date,
                    weekday,
                    (mmi_indical_indian_date_struct*) & next_indical_indian_date,
                    next_indian_date_str);
            }

        }
    }
}

#ifdef __MMI_TODOLIST__
/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_tithi_weekly
 * DESCRIPTION
 *  Search the weekly task list.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  date : [IN] The search condition.
 *              The due time of the events in the searched list should be 
 *         earlier than 23:59 end of the week and later than 00:00 start 
 *         time of the week.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/
U16 srv_tdl_event_search_tithi_weekly(
                            const void *pevent,
                            const srv_tdl_vcal_enum vcal_type,
                            const srv_tdl_search_weely_struct weekly_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_week_begin;
    MYTIME next_week_begin;
    MYTIME inc_time, reminder_date, task_event_start_time;
    srv_tdl_event_short_struct *clndr_event = NULL;
    srv_tdl_task_short_struct *task = NULL;
    U16 result = MMI_FALSE;
    U8 is_task_event_present;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        clndr_event = (srv_tdl_event_short_struct*) pevent;
        if (!clndr_event|| weekly_search.date_time.nYear == 0 || weekly_search.date_time.nMonth == 0 || weekly_search.date_time.nDay == 0)
        {
            result = SRV_TDL_RESULT_INVALID_PARAMETER;
            return result;
        }
        is_task_event_present = clndr_event->present;
        memcpy(&task_event_start_time, &clndr_event->start_time, sizeof(MYTIME));
    }
    else
    {
        task = (srv_tdl_task_short_struct*) pevent;
        if (!task|| weekly_search.date_time.nYear == 0 || weekly_search.date_time.nMonth == 0 || weekly_search.date_time.nDay == 0)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        return result;
    }
        is_task_event_present = task->present;
        memcpy(&task_event_start_time, &task->due_time, sizeof(MYTIME));
    }

    memcpy(&curr_week_begin, 0, sizeof(MYTIME));
    memcpy(&inc_time, 0, sizeof(MYTIME));
    memcpy(&next_week_begin, 0, sizeof(MYTIME));
    srv_tdl_cal_week_get_first_date(&weekly_search.date_time, &curr_week_begin, weekly_search.start_day_of_week);

    inc_time.nDay = SRV_TDL_MAX_DAYS_PER_WEEK;
    
    applib_dt_increase_time(
        (applib_time_struct*)&curr_week_begin,
        (applib_time_struct*)&inc_time,
        (applib_time_struct*)&next_week_begin);
    if (is_task_event_present && 
        CompareTime(task_event_start_time, next_week_begin, NULL) < 0)
    {
        if (mmi_indical_is_reminder_in_week(curr_week_begin, next_week_begin, task_event_start_time, &reminder_date))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_tithi_monthly
 * DESCRIPTION
 *  Search the weekly task list.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  date : [IN] The search condition.
 *              The due time of the events in the searched list should be 
 *         earlier than 23:59 end of the week and later than 00:00 start 
 *         time of the week.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/
U16 srv_tdl_event_search_tithi_monthly(
                            const void *pevent,
                            const srv_tdl_vcal_enum vcal_type,
                            const MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_month_begin;
    MYTIME next_month_begin;
    MYTIME inc_time, task_event_start_time;
    srv_tdl_event_short_struct *clndr_event = NULL;
    srv_tdl_task_short_struct *task = NULL;
    U16 result = MMI_FALSE;
    U8 is_task_event_present;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        clndr_event = (srv_tdl_event_short_struct*) pevent;
        if (!clndr_event|| date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
        {
            result = SRV_TDL_RESULT_INVALID_PARAMETER;
            return result;
        }
        is_task_event_present = clndr_event->present;
        memcpy(&task_event_start_time, &clndr_event->start_time, sizeof(MYTIME));
    }
    else
    {
        task = (srv_tdl_task_short_struct*) pevent;
        if (!task|| date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        return result;
    }
        is_task_event_present = task->present;
        memcpy(&task_event_start_time, &task->due_time, sizeof(MYTIME));
    }

    memcpy(&curr_month_begin, &date, sizeof(MYTIME));
    curr_month_begin.nDay = 1;
    curr_month_begin.nHour = 0;
    curr_month_begin.nMin = 0;
    curr_month_begin.nSec = 0;
    
    memcpy(&inc_time, 0, sizeof(MYTIME));
    inc_time.nMonth = 1;
    
    applib_dt_increase_time(
        (applib_time_struct*)&curr_month_begin,
        (applib_time_struct*)&inc_time,
        (applib_time_struct*)&next_month_begin);
    if (is_task_event_present && 
            CompareTime(task_event_start_time, next_month_begin, NULL) < 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_tithi_daily
 * DESCRIPTION
 *  Search the weekly task list.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  date : [IN] The search condition.
 *              The due time of the events in the searched list should be 
 *         earlier than 23:59 end of the week and later than 00:00 start 
 *         time of the week.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/
U16 srv_tdl_event_search_tithi_daily(
                            const void *pevent,
                            const srv_tdl_vcal_enum vcal_type,
                            const MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = MMI_FALSE;
    U8 weekday, two_tithis_same_gday, is_task_event_present;
    mmi_indical_gregorian_date_struct gregorian_date;
    mmi_indical_indian_date_struct indical_indian_date1, indical_indian_date2;
    MYTIME date_end;
    MYTIME task_event_start_time;
    srv_tdl_event_short_struct *clndr_event = NULL;
    srv_tdl_task_short_struct *task = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        clndr_event = (srv_tdl_event_short_struct*) pevent;
        if (!clndr_event|| date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        return result;
    }
        is_task_event_present = clndr_event->present;
    }
    else
    {
        task = (srv_tdl_task_short_struct*) pevent;
        if (!task|| date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        return result;
    }
        is_task_event_present = task->present;
    }

    gregorian_date.mm = date.nMonth;
    gregorian_date.yy = date.nYear - INDICAL_START_YEAR;
    gregorian_date.dd = date.nDay;
    
    weekday = increment_gregorian_date(date, 0, NULL);
    mmi_indical_get_indian_date(&gregorian_date, weekday, &indical_indian_date1, g_mmi_indical_cntx.indianDateString);
    two_tithis_same_gday = mmi_indical_check_for_two_tithi_same_gdate(&gregorian_date);
    
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        gregorian_date.mm = clndr_event->start_time.nMonth;
        gregorian_date.yy = clndr_event->start_time.nYear - INDICAL_START_YEAR;
        gregorian_date.dd = clndr_event->start_time.nDay;
        weekday = increment_gregorian_date(clndr_event->start_time, 0, NULL);
        memcpy(&task_event_start_time, &clndr_event->start_time, sizeof(MYTIME));
    }
    else if(vcal_type == SRV_TDL_VCAL_TASK)
    {
        gregorian_date.mm = task->due_time.nMonth;
        gregorian_date.yy = task->due_time.nYear - INDICAL_START_YEAR;
        gregorian_date.dd = task->due_time.nDay;
        weekday = increment_gregorian_date(task->due_time, 0, NULL);
        memcpy(&task_event_start_time, &task->due_time, sizeof(MYTIME));
    }

    mmi_indical_get_indian_date(&gregorian_date, weekday, &indical_indian_date2, g_mmi_indical_cntx.indianDateString);
    
    memcpy(&date_end, &date, sizeof(MYTIME));
    date_end.nHour = 23;
    date_end.nMin = 59;
    date_end.nSec = 59; 
    if (is_task_event_present && 
        CompareTime(task_event_start_time, date_end, NULL) <= 0)
    {
    if (indical_indian_date1.tithi == indical_indian_date2.tithi)
    {
        if (indical_indian_date1.tithi != 15)
        {
            return TRUE;
        }
        else
        {
            if (indical_indian_date1.paksha == indical_indian_date2.paksha)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else
    {
        if (two_tithis_same_gday)
        {
            if (indical_indian_date1.tithi != 15)
            {
                indical_indian_date1.tithi++;
            }
            else
            {
                indical_indian_date1.tithi = 1;
            }
            if (indical_indian_date1.tithi == indical_indian_date2.tithi)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
}
    else
    {
        return FALSE;
    }
}
#endif /* __MMI_TODOLIST__ */

#endif /* __MMI_INDICAL__ */ 

