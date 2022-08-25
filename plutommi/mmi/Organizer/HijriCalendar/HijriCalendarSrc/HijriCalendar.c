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
 * HijriCalendar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file contains the source code for Hijri Calendar implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "app_datetime.h"
#include "Mmi_rp_app_calendar_def.h"
#include "CalendarProt.h"
//#include "SimDetectionGprot.h"
#include "EmailAppGProt.h"
#include "SmsAppGprot.h"
#include "TodolistSrvGprot.h"

#if defined (__MMI_HIJRI_CALENDAR__)
#include "HijriCalendarDef.h"
#include "HijriCalendarProt.h"
#if defined(__MMI_WLAN_FEATURES__)
#endif /* defined(__MMI_WLAN_FEATURES__) */
#include "wgui_categories_util.h"
#include "app_datetime.h"
#include "CalendarProt.h"
#include "SimCtrlSrvGprot.h"

#ifdef __MMI_HIJRI_CALENDAR__
#include "mmi_rp_app_hijri_calendar_def.h"
#endif

#ifdef __MMI_INDICAL__
#endif

#include "Menucuigprot.h"

//RHR add begin

#include "MMI_features.h"
#include "mmi_frm_input_gprot.h"
#include "MMIDataType.h"
#include "FontRes.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "CustMenuRes.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "AlertScreen.h"
#include "gui_data_types.h"
#include "gui.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_inputs.h"
#include "DateTimeType.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "mms_api.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_app_todolist_def.h"
#include "ToDoListGprot.h"
#include "stdlib.h"
    
#include "ModeSwitchSrvGProt.h"
//RHR add end

/* 
 * Define
 */
typedef void (*hijri_pen_fptr)(mmi_pen_point_struct pos);
/* 
 * Typedef 
 */
static mmi_id cui_menu_cui_hijri_day_details_option_gid;
static mmi_id cui_menu_cui_hijri_day_details_option_parent_gid;
static mmi_id cui_menu_cui_hijri_festival_option_parent_gid;
static mmi_id cui_menu_cui_hijri_festival_option_gid;

static mmi_ret mmi_hijri_day_details_option_group_proc(mmi_event_struct* evt);
static void mmi_hijri_day_details_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_hijri_festival_option_group_proc(mmi_event_struct* evt);
static void mmi_hijri_festival_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_hijri_option_menu_cui_entry_hdlr(void);
extern BOOL r2lMMIFlag;
/* 
 * Local Function
 */
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

//extern kal_uint8 applib_dt_is_leap_year(kal_uint16 year);
//extern void mmi_clndr_get_updated_date_time_after_jump_to_date(MYTIME *);



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_day_details
 * DESCRIPTION
 *  Highlight handler for Hijri day details viewing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_pre_entry_day_details, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_pre_entry_day_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_hijri_festivals
 * DESCRIPTION
 *  Highlight handler for viewing Hijri festival list falling in a Gregorian year.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_hijri_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_pre_entry_festival_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_pre_entry_festival_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_date_correction
 * DESCRIPTION
 *  Highlight handler for Hijri date correction from -2 to +2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_date_correction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_entry_date_correction, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_entry_date_correction, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_send_date
 * DESCRIPTION
 *  Highlight handler for menu option of send hijri date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_send_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_entry_send_date, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_entry_send_date, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_go_to_calendar_day_details
 * DESCRIPTION
 *  Highlight handler for menu option of go to calendar from day details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_go_to_calendar_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_go_to_calendar_day_details, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_go_to_calendar_day_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_go_to_calendar_festivals
 * DESCRIPTION
 *  Highlight handler for menu option of go to calendar from day details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_go_to_calendar_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_go_to_calendar_festivals, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_go_to_calendar_festivals, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_add_reminder_day_details
 * DESCRIPTION
 *  Highlight handler for menu option of add reminder in day details option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_add_reminder_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TODOLIST__
    SetLeftSoftkeyFunction(mmi_hijri_pre_entry_add_reminder_for_hijri, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_pre_entry_add_reminder_for_hijri, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN); 
#endif /* __MMI_TODOLIST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_send_by_SMS
 * DESCRIPTION
 *  Highlight handler for sending Hijri day details via SMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_send_by_SMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_send_by_SMS, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_send_by_SMS, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_MMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_send_by_MMS
 * DESCRIPTION
 *  Highlight handler for sending Hijri day details via MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_send_by_MMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_send_by_MMS, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_send_by_MMS, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_MMS__ */

#ifdef __MMI_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_send_by_EMAIl
 * DESCRIPTION
 *  Highlight handler for sending Hijri day details via Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_send_by_EMAIL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_send_by_Email, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_send_by_Email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_EMAIL__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_festival_options
 * DESCRIPTION
 *  Highlight handler for viewing details for a Hijri festival
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_festival_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_fest_list_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_fest_list_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_festival_detail
 * DESCRIPTION
 *  Highlight handler for viewing details for a Hijri festival
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_festival_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_hijri_entry_festival_detail, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_entry_festival_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlight_add_reminder_for_festivals
 * DESCRIPTION
 *  Highlight handler for adding reminder for a Hijri festival.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlight_add_reminder_for_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TODOLIST__
    SetLeftSoftkeyFunction(mmi_hijri_pre_entry_add_reminder_for_festivals, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_pre_entry_add_reminder_for_festivals, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_TODOLIST__ */
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
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_init
 * DESCRIPTION
 *  Init function for Hijri application. Initialises reminder_for_hijri to zero.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_hijri_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_hijri_cntx.reminder_for_hijri = MMI_HIJRICAL_NONE; 
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_date_correction
 * DESCRIPTION
 *  Entry function for the Hijri date correction. Also reads the Date correction value from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_date_correction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nItems;
    S16 error;
    U8 *guiBuffer;
    U8 index;
    U8 read_correction;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_ID_HIJRI_DATE_CORRECTION,
                    NULL, 
                    mmi_hijri_entry_date_correction, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = GetNumOfChild(MENU_ID_HIJRI_DATE_CORRECTION);

    ReadValue(NVRAM_HIJRI_CORRECTION, &read_correction, DS_BYTE, &error);
    g_mmi_hijri_cntx.date_correction = (U8)(read_correction);
    for (index = MMI_HIJRI_CONSTANT_ZERO; index < nItems; index++)
    {
        subMenuDataPtrs[index] = (PU8) GetString((U16) (STR_HIJRI_DATE_SUB_TWO_DAYS + index));
    }
    SetParentHandler(MENU_ID_HIJRI_DATE_CORRECTION);

    RegisterHighlightHandler(mmi_hijri_highlighted_index);

    ShowCategory36Screen (
        STR_HIJRI_DATE_CORRECTION,
        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32)nItems,
        subMenuDataPtrs,
        (U16)(g_mmi_hijri_cntx.date_correction),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_hijri_add_correction,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_hijri_add_correction,KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_add_correction
 * DESCRIPTION
 *  Sets the hijri date correction into the date_correction variable as selected by the user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_add_correction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_correction;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_hijri_cntx.highlighted_index)
    {
        case 0:
            g_mmi_hijri_cntx.date_correction = (U8)0;
        break;

        case 1:
            g_mmi_hijri_cntx.date_correction = (U8)1;
        break;

        case 2:
            g_mmi_hijri_cntx.date_correction = (U8)2;
        break;

        case 3:
            g_mmi_hijri_cntx.date_correction = (U8)3;
        break;

        case 4:
            g_mmi_hijri_cntx.date_correction = (U8)4;
        break;

        default:
        break;
    }
    /* Add trace for telling the value of date_correction */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_ADD_CORRECTION, g_mmi_hijri_cntx.date_correction);
    write_correction = (U8) (g_mmi_hijri_cntx.date_correction);
    WriteValue(NVRAM_HIJRI_CORRECTION, &write_correction, DS_BYTE, &error);
    do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_hijri_go_back_to_calendar_options_screen);
	mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, &arg);
	} while(0);
    SetGroupKeyHandler(mmi_hijri_go_back_to_calendar_options_screen, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
    SetGroupKeyHandler(UI_dummy_function, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler((hijri_pen_fptr)mmi_hijri_go_back_to_calendar_options_screen);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_go_back_to_calendar_options_screen
 * DESCRIPTION
 *  Takes back to the hijri calendar main menu screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_go_back_to_calendar_options_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_HIJRI_DATE_CORRECTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_highlighted_index
 * DESCRIPTION
 *  Highlight handler for list menus.
 * PARAMETERS
 *  index   [IN]    index passed by the category screen.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_highlighted_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_hijri_cntx.highlighted_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_day_details
 * DESCRIPTION
 *  Pre entry function for showing the Hijri day details.
 *  Gets the hijri date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_pre_entry_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    pBOOL is_date_within_range = MMI_FALSE;
    MYTIME currTime = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	mmi_clndr_get_updated_date_time_after_jump_to_date(&currTime);
    is_date_within_range = mmi_hijri_monthly_out_of_boundary(&currTime, MMI_TRUE);
    if (is_date_within_range == MMI_TRUE)
    {
        mmi_clndr_get_updated_date_time_after_jump_to_date(&g_mmi_hijri_cntx.clndr_date);  /* issue with this cahnge is that there will be no change in day details if from call we can go and change the calendar date time */
		mmi_hijri_entry_day_details();
    }
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_day_details
 * DESCRIPTION
 *  Entry function for showing the Hijri day details.
 *  Gets the hijri date and prepares the hijri date string.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_character_type temp_str[MMI_HIJRI_CONSTANT_TEN];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_ID_HIJRI_DAY_DETAILS,
                    NULL, 
                    mmi_hijri_entry_day_details, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
	
	DeleteScreenIfPresent(SCR_ID_HIJRI_DAY_DETAILS);

	g_mmi_hijri_cntx.hijri_date = mmi_hijri_greg_to_hijri(g_mmi_hijri_cntx.clndr_date);

    mmi_hijri_make_detail_string();

	/* prepare title string */
	memset(g_mmi_hijri_cntx.title_str, '\0', ((MMI_HIJRI_MAX_FESTIVAL_NAME_LENGTH + 4) * ENCODING_LENGTH));

	if (!(g_mmi_hijri_cntx.clndr_date.nYear == MMI_HIJRI_START_YEAR
          && g_mmi_hijri_cntx.clndr_date.nMonth == 1 && g_mmi_hijri_cntx.clndr_date.nDay == 1))
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) "<");
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) " ");
    }

	gui_itoa((S32) g_mmi_hijri_cntx.clndr_date.nYear, temp_str, MMI_HIJRI_CONSTANT_TEN);
    if (!(g_mmi_hijri_cntx.clndr_date.nYear == MMI_HIJRI_START_YEAR
          && g_mmi_hijri_cntx.clndr_date.nMonth == 1 && g_mmi_hijri_cntx.clndr_date.nDay == 1))
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) temp_str);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_mmi_hijri_cntx.title_str, (S8*) temp_str);
    }
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, "/");
    if(g_mmi_hijri_cntx.clndr_date.nMonth < MMI_HIJRI_CONSTANT_TEN)
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, "0");
    }
    gui_itoa((S32) g_mmi_hijri_cntx.clndr_date.nMonth, (UI_string_type)(temp_str), MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) temp_str);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, "/");
    if (g_mmi_hijri_cntx.clndr_date.nDay < MMI_HIJRI_CONSTANT_TEN)
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, "0");
    }
    gui_itoa((S32) g_mmi_hijri_cntx.clndr_date.nDay, (UI_string_type)(temp_str), MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) temp_str);

	if (!(g_mmi_hijri_cntx.clndr_date.nYear == MMI_HIJRI_END_YEAR
          && g_mmi_hijri_cntx.clndr_date.nMonth == 12
        && g_mmi_hijri_cntx.clndr_date.nDay == 31))
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) " ");
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) ">");
    }


   /* ShowCategory74Screen(
        STR_HIJRI_DAY_DETAILS,
        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_mmi_hijri_cntx.hijri_date_string,
        mmi_ucs2strlen((PS8) g_mmi_hijri_cntx.hijri_date_string),
        guiBuffer); */

	
	ShowCategory79Screen(
        (UI_string_type) g_mmi_hijri_cntx.title_str,
        (U8*) GetImage(GetRootTitleIcon(ORGANIZER_CALENDER_MENU)),
        (UI_string_type) (GetString(STR_GLOBAL_OPTIONS)),
        (U8*) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) (GetString(STR_GLOBAL_BACK)),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        MMI_TRUE,
        MMI_FALSE,
        (UI_buffer_type) g_mmi_hijri_cntx.hijri_date_string,
        mmi_ucs2strlen((PS8) g_mmi_hijri_cntx.hijri_date_string),
        guiBuffer);


    SetLeftSoftkeyFunction(mmi_hijri_entry_day_details_options, KEY_EVENT_UP); /* parmeet changed LSK function */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    SetCenterSoftkeyFunction(mmi_hijri_entry_day_details_options, KEY_EVENT_UP);
    
    wgui_inputs_ml_register_set_key_callback(mmi_hijri_date_display_set_display_key_handler);
    SetKeyHandler(mmi_hijri_increment_day_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_hijri_decrement_day_details, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_date_display_set_display_key_handler
 * DESCRIPTION
 *  LNK and RNK handler for hijri date display.
 * PARAMETERS
 *  void
 * RETURNS
 *  festival index
 *****************************************************************************/
void mmi_hijri_date_display_set_display_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_hijri_increment_day_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_hijri_decrement_day_details, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_increment_day_details
 * DESCRIPTION
 *  RNK functionality on day details screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  festival index
 *****************************************************************************/
void mmi_hijri_increment_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME resultDate, incTime;
	pBOOL is_date_within_range = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
	memset(&resultDate, 0, sizeof(MYTIME));
	incTime.nDay = 1; /* macro for 1 day */
	applib_dt_increase_time(
                (applib_time_struct*) & (g_mmi_hijri_cntx.clndr_date),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
	memcpy(&g_mmi_hijri_cntx.clndr_date, &resultDate, sizeof(MYTIME));
	is_date_within_range = mmi_hijri_monthly_out_of_boundary(&g_mmi_hijri_cntx.clndr_date, MMI_TRUE);
	if (is_date_within_range == MMI_TRUE)
    {        
		mmi_hijri_entry_day_details();
    }
	else
	{
		/*mmi_hijri_pre_entry_day_details();*/
		applib_dt_decrease_time(
				(applib_time_struct*) & (g_mmi_hijri_cntx.clndr_date),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
		memcpy(&g_mmi_hijri_cntx.clndr_date, &resultDate, sizeof(MYTIME));

	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_decrement_day_details
 * DESCRIPTION
 *  LNK functionality on day details screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  festival index
 *****************************************************************************/
void mmi_hijri_decrement_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME resultDate, decTime;
	pBOOL is_date_within_range = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&decTime, 0, sizeof(MYTIME));
	memset(&resultDate, 0, sizeof(MYTIME));
	decTime.nDay = 1; /* macro for 1 day */
    applib_dt_decrease_time(
				(applib_time_struct*) & (g_mmi_hijri_cntx.clndr_date),
                (applib_time_struct*) & decTime,
                (applib_time_struct*) & resultDate);
	memcpy(&g_mmi_hijri_cntx.clndr_date, &resultDate, sizeof(MYTIME));
	is_date_within_range = mmi_hijri_monthly_out_of_boundary(&g_mmi_hijri_cntx.clndr_date, MMI_TRUE);
	if (is_date_within_range == MMI_TRUE)
    {
        mmi_hijri_entry_day_details();
    }
	else
	{
		/*mmi_hijri_pre_entry_day_details();*/
		applib_dt_increase_time(
                (applib_time_struct*) & (g_mmi_hijri_cntx.clndr_date),
                (applib_time_struct*) & decTime,
                (applib_time_struct*) & resultDate);
		memcpy(&g_mmi_hijri_cntx.clndr_date, &resultDate, sizeof(MYTIME));
	}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_match_fest_date
 * DESCRIPTION
 *  Finds a match between the Hijri date and the festival date.
 * PARAMETERS
 *  void
 * RETURNS
 *  festival index
 *****************************************************************************/
S32 mmi_hijri_match_fest_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_HIJRI_MAX_FESTIVALS; index++)
    {
        if (g_mmi_hijri_cntx.hijri_date.day == mmi_hijri_base_fest_date[index].day &&
            (g_mmi_hijri_cntx.hijri_date.month == mmi_hijri_base_fest_date[index].month))
        {
            return (S32)(index);
        }
    }
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_make_detail_string
 * DESCRIPTION
 *  Makes the complete Hijri date string having the Gregorian date and the hijri date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_make_detail_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_str[MMI_HIJRI_CONSTANT_TEN];
    S32 is_festival_present;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_hijri_cntx.hijri_date_string, '\0', MMI_HIJRI_DATE_STR_LEN * ENCODING_LENGTH);

    /* gui_itoa((S32) g_mmi_hijri_cntx.clndr_date.nYear, temp_str, MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cpy((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) temp_str);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "/");
    if(g_mmi_hijri_cntx.clndr_date.nMonth < MMI_HIJRI_CONSTANT_TEN)
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "0");
    }
    gui_itoa((S32) g_mmi_hijri_cntx.clndr_date.nMonth, (UI_string_type)(temp_str), MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) temp_str);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "/");
    if (g_mmi_hijri_cntx.clndr_date.nDay < MMI_HIJRI_CONSTANT_TEN)
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "0");
    }
    gui_itoa((S32) g_mmi_hijri_cntx.clndr_date.nDay, (UI_string_type)(temp_str), MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) temp_str);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "\n"); */ /*  do not need to show in detail string to be shown in title only */


    /*if (r2lMMIFlag)
    {
        if ( g_mmi_hijri_cntx.hijri_date.day > 9)
        {
            if (mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_ARABIC) == 0)
            {
                g_mmi_hijri_cntx.hijri_date_string[11] = (g_mmi_hijri_cntx.hijri_date.day / MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_ARABIC_UNICODE_NUMERAL_START;
            }
            else if(mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_URDU) == 0)
            {
                g_mmi_hijri_cntx.hijri_date_string[11] = (g_mmi_hijri_cntx.hijri_date.day / MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_URDU_UNICODE_NUMERAL_START;
            }
        }
        if (mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_ARABIC) == 0)
        {
            g_mmi_hijri_cntx.hijri_date_string[12] = (g_mmi_hijri_cntx.hijri_date.day % MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_ARABIC_UNICODE_NUMERAL_START;
        }
        else if(mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_URDU) == 0)
        {
            g_mmi_hijri_cntx.hijri_date_string[12] = (g_mmi_hijri_cntx.hijri_date.day % MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_URDU_UNICODE_NUMERAL_START;
        }
    }
    else
    {*/
    
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_DATE)));
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, " ");
	if (g_mmi_hijri_cntx.hijri_date.day < MMI_HIJRI_CONSTANT_TEN)
	{
		mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "0");
	}
	gui_itoa((S32) g_mmi_hijri_cntx.hijri_date.day, (UI_string_type)(temp_str), MMI_HIJRI_CONSTANT_TEN);
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) temp_str);

    //}
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "\n");
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_DAY)));
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, " ");

    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_ITWAAR + g_mmi_hijri_cntx.clndr_date.DayIndex)));
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "\n");

	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_MONTH)));
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, " ");

    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_MUHARRAM + g_mmi_hijri_cntx.hijri_date.month - 1)));
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "\n");

	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_YEAR)));
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, " ");

    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, GetString((U16)(STR_HIJRI_ANNO_HEGIRE)));
    gui_itoa((S32) g_mmi_hijri_cntx.hijri_date.year, (UI_string_type)(temp_str), MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) temp_str);

    is_festival_present = mmi_hijri_match_fest_date();
    if (is_festival_present >= MMI_HIJRI_CONSTANT_ZERO)
    {
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, "\n");
		mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16)(STR_HIJRI_FESTIVAL)));
		mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, " ");
        mmi_ucs2cat((S8*) g_mmi_hijri_cntx.hijri_date_string, (S8*) GetString((U16) (STR_HIJRI_NEW_YEAR + is_festival_present)));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_greg_to_hijri
 * DESCRIPTION
 *  Calls the appropriate API's to convert a Gregorian date to Hijri date.
 * PARAMETERS
 *  date    [IN]    the Gregorian date for which Hijri date needs to be found out.
 * RETURNS
 *  mmi_hijri_date_struct
 *****************************************************************************/
mmi_hijri_date_struct mmi_hijri_greg_to_hijri(MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 diff_days;
    mmi_hijri_date_struct hijri_date;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_hijri_adjust_base_date();
    diff_days = mmi_hijri_convert_date_to_days(date);
    hijri_date = mmi_hijri_increment_hijri_date(diff_days);
    return hijri_date;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_adjust_base_date
 * DESCRIPTION
 *  Adjusts the base date according to the value of date correction.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_adjust_base_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 read_correction;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_HIJRI_CORRECTION, &read_correction, DS_BYTE, &error);
    g_mmi_hijri_cntx.hijri_base_date = base_hijri_date;
    g_mmi_hijri_cntx.hijri_base_date.day += (U8)(read_correction - 2);
    /* Add trace to know the value of hijri base date */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_BASE_DATE, g_mmi_hijri_cntx.hijri_base_date.day);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_increment_hijri_date
 * DESCRIPTION
 *  Increments the Base hijri date by the number of days provided as argument.
 * PARAMETERS
 *  days   [IN]    The number of days by which base Hijri date needs to be incremented.
 * RETURNS
 *  hijri_date
 *****************************************************************************/
mmi_hijri_date_struct mmi_hijri_increment_hijri_date(U16 days)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_hijri_date_struct hijri_date;
    U8 index;
    U16 passed_hijri_days = MMI_HIJRI_CONSTANT_ZERO;
    U16 days_left, remainder, quotient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hijri_date, MMI_HIJRI_CONSTANT_ZERO, sizeof (mmi_hijri_date_struct));

    /* Calculate the passed hijri days in the Hijri month as on 1/1/2008. */    
    for (index = MMI_HIJRI_CONSTANT_ONE; index < (g_mmi_hijri_cntx.hijri_base_date.month); index++)
    {
        passed_hijri_days += mmi_hijri_num_days_in_month(index, g_mmi_hijri_cntx.hijri_base_date.year);
    }
    passed_hijri_days += g_mmi_hijri_cntx.hijri_base_date.day;
    /* Calculate the days left in the Hijri year of 1/1/2008 to finish */
    days_left = mmi_hijri_days_in_year(g_mmi_hijri_cntx.hijri_base_date.year);
    days_left -= passed_hijri_days;
    /* Add trace to know the value of the days */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_DAYS_TO_INC, days);
    if (days > days_left)
    {
        /* Reaches here if the Hijri date we wish to calculate doesn't falls in the Hijri year of 1/1/2000. */
        /* End the Hijri year of 1/1/2000 by decrementing the days by days_left and store result in remainder
        and then increment the Hijri year. */
        hijri_date.year = g_mmi_hijri_cntx.hijri_base_date.year + MMI_HIJRI_CONSTANT_ONE;
        remainder = days - days_left;
        /* If days remaining are still greater than the number of days present in next Hijri year,
        decrement the remainder by days present in the Hijri year and keep on incrementing hijr year's value by 1. */
        while (remainder > mmi_hijri_days_in_year(hijri_date.year))
        {            
            remainder -= mmi_hijri_days_in_year(hijri_date.year);
            hijri_date.year++;
        }
        if (remainder == mmi_hijri_days_in_year(hijri_date.year))
        {
            hijri_date.month = MMI_HIJRI_NUM_MONTHS;        
            hijri_date.day = mmi_hijri_num_days_in_month(hijri_date.month, hijri_date.year);
            return hijri_date;
        }
        /* Add trace to know wat is d value of the reminder after hijri year determination */
        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_DAYS_AFTER_YEAR_DET, remainder);

        /* After above step, Hijri year is found. To calculate hijri month, compare the remainder with the days present
        in next 2 months, as they form a unit of 59 days.*/
        quotient = remainder/MMI_HIJRI_SUM_DAYS_TWO_MONTHS;
        remainder %= MMI_HIJRI_SUM_DAYS_TWO_MONTHS;
        if (remainder == 0)
        {
            quotient--;
            remainder = MMI_HIJRI_SUM_DAYS_TWO_MONTHS;
        }
        hijri_date.month = MMI_HIJRI_CONSTANT_ONE + MMI_HIJRI_CONSTANT_TWO*quotient;
        if (hijri_date.month > MMI_HIJRI_NUM_MONTHS)
        {
            hijri_date.month = MMI_HIJRI_NUM_MONTHS;
        }
        
        /* Add trace to know wat is d value of reminder after hijri month determination. */
        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_DAYS_AFTER_MONTH_DET, remainder);
        /* The remainder now is less than 59, then if it is greater than the days in hijri_date.month, month is
        incremented by 1 and the remaining days is assigned to hijri_date.day */
        if (remainder > mmi_hijri_num_days_in_month(hijri_date.month, hijri_date.year))
        {
            remainder -= mmi_hijri_num_days_in_month(hijri_date.month, hijri_date.year);
            hijri_date.month++;
        }
        hijri_date.day = (U8)remainder;
    }
    else if (days < days_left)
    {
        /* Reaches here if the Hijri date we wish to calculate falls in the Hijri year of 1/1/2000. */
        if (days == 0)
        {
            return g_mmi_hijri_cntx.hijri_base_date;
        }
        hijri_date = g_mmi_hijri_cntx.hijri_base_date;
        remainder = days;
        if (remainder > (mmi_hijri_num_days_in_month(g_mmi_hijri_cntx.hijri_base_date.month, g_mmi_hijri_cntx.hijri_base_date.year) - g_mmi_hijri_cntx.hijri_base_date.day))
        {
            /* Reaches here if days+hijri date is greater than the number of days present in the Hijri month. */
            /* Increment the hijri month and subtract the remaining days in hijri month from the days to be incremented.*/
            remainder -= mmi_hijri_num_days_in_month(g_mmi_hijri_cntx.hijri_base_date.month, g_mmi_hijri_cntx.hijri_base_date.year) - g_mmi_hijri_cntx.hijri_base_date.day;
            hijri_date.month = g_mmi_hijri_cntx.hijri_base_date.month + MMI_HIJRI_CONSTANT_ONE;
            /* Calculate the hijri month in bunch of 59 days */
            quotient = remainder/MMI_HIJRI_SUM_DAYS_TWO_MONTHS;
            remainder%= MMI_HIJRI_SUM_DAYS_TWO_MONTHS;
            if (remainder == 0)
            {
                quotient--;
                remainder = MMI_HIJRI_SUM_DAYS_TWO_MONTHS;
            }
            hijri_date.month += quotient*MMI_HIJRI_CONSTANT_TWO;
            if (remainder > mmi_hijri_num_days_in_month(hijri_date.month, hijri_date.year))
            {
                remainder -= mmi_hijri_num_days_in_month(hijri_date.month, hijri_date.year);
                hijri_date.month++;
            }
            hijri_date.day = (U8)remainder;
        }
        else
        {
            hijri_date.day += remainder;
        }
    }
    else
    {
        /* Reaches here if days=days_left in the Hijri year of 1/1/2000. */
        hijri_date.year = g_mmi_hijri_cntx.hijri_base_date.year/* +MMI_HIJRI_CONSTANT_ONE*/;
        hijri_date.month = MMI_HIJRI_NUM_MONTHS;        
        hijri_date.day = mmi_hijri_num_days_in_month(hijri_date.month, hijri_date.year);
    }
    return hijri_date;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_days_in_year
 * DESCRIPTION
 *  Finds whether the entered hijri year is a leap year or not.
 * PARAMETERS
 *  year   [IN]    Hijri year value.
 * RETURNS
 *  354 if hijri year is not leap, 355 if hijri year is leap.
 *****************************************************************************/
U16 mmi_hijri_days_in_year(U16 year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 remainder;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    remainder = year%30;
    for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_LEAP_YEARS; index++)
    {
        if (remainder == mmi_hijri_leap_year_table[index])
        {
            return MMI_HIJRI_DAYS_IN_HIJRI_YEAR + MMI_HIJRI_CONSTANT_ONE;
        }
    }
    return MMI_HIJRI_DAYS_IN_HIJRI_YEAR;
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_convert_date_to_days
 * DESCRIPTION
 *  Finds the number of days between the Gregorian date and 1/1/2008.
 * PARAMETERS
 *  date   [IN]    Date for which number of days is to be calculated.
 * RETURNS
 *  Number of days passed since the date and 1/1/2008.
 *****************************************************************************/
U16 mmi_hijri_convert_date_to_days(MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 days;
    U16 index, lastDay, leap_year_offset = MMI_HIJRI_CONSTANT_ZERO;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = MMI_HIJRI_START_YEAR; index < date.nYear; index++)
    {
        leap_year_offset += applib_dt_is_leap_year(index);
    }    
    days = 365*(date.nYear - MMI_HIJRI_START_YEAR) + leap_year_offset;
    for (index = MMI_HIJRI_CONSTANT_ONE; index < date.nMonth; index++)
    {
        lastDay = LastDayOfMonth((U8)index, date.nYear);
        days += lastDay;
    }
    days += date.nDay - MMI_HIJRI_CONSTANT_ONE;
    return days;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_pre_entry_festival_list
 * DESCRIPTION
 *  Gets updated calendar date and sets the festival year to the year value of the updated Calendar date.
 *  And then calls festival list entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_pre_entry_festival_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL is_date_within_range = MMI_FALSE;
    MYTIME currTime = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	mmi_clndr_get_updated_date_time_after_jump_to_date(&currTime);
    is_date_within_range = mmi_hijri_monthly_out_of_boundary(&currTime, MMI_TRUE);
    if (is_date_within_range == MMI_TRUE)
    {
        mmi_clndr_get_updated_date_time_after_jump_to_date(&g_mmi_hijri_cntx.clndr_date);
		g_mmi_hijri_cntx.fest_year = g_mmi_hijri_cntx.clndr_date.nYear;
		mmi_hijri_entry_festival_list();
    }	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_festivals
 * DESCRIPTION
 *  Finds the correct order of the Hijri festivals for the selected date's Gregorian year.
 *  It finds the Hijri date(H1) on 1/1/YYYY and Hijri date(H2) on 31/12/YYYY, and then determines
 * from the festival list array that which festival falls after H1 and which festivals fall before H2
 * and stores the festival index in an array.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_get_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME year_start_date, year_end_date;
    mmi_hijri_date_struct hijri_start_date, hijri_end_date;
    U8 festival_from_start = MMI_HIJRI_CONSTANT_ZERO, festival_from_end = MMI_HIJRI_CONSTANT_ZERO, index = MMI_HIJRI_CONSTANT_ZERO, j = MMI_HIJRI_CONSTANT_ZERO;
    U16 diff_days;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    year_start_date.nDay = MMI_HIJRI_CONSTANT_ONE;
    year_start_date.nMonth = MMI_HIJRI_CONSTANT_ONE;
    year_start_date.nYear = g_mmi_hijri_cntx.fest_year;

    year_end_date.nDay = 31;
    year_end_date.nMonth = MMI_HIJRI_NUM_MONTHS;
    year_end_date.nYear = g_mmi_hijri_cntx.fest_year;

    /* Adjust the base hijri date first. */
    mmi_hijri_adjust_base_date();

    /* Calculate the hijri date on 1/1/YYYY */
    diff_days = mmi_hijri_convert_date_to_days(year_start_date);
    hijri_start_date = mmi_hijri_increment_hijri_date(diff_days);
    /* Add trace to know hijri start date. */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, 
        MMI_ORG_HIJRI_START_DATE, 
        hijri_start_date.day,
        hijri_start_date.month,
        hijri_start_date.year);

    /* Calculate the hijri date on 31/12/YYYY */
    diff_days = mmi_hijri_convert_date_to_days(year_end_date);
    hijri_end_date = mmi_hijri_increment_hijri_date(diff_days);
    /* Add trace to know hijri end date. */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, 
        MMI_ORG_HIJRI_START_DATE, 
        hijri_end_date.day,
        hijri_end_date.month,
        hijri_end_date.year);

    /* 2 steps are used in festival index calculation:
            1. Calculate the festivals falling after hijri_start_date.
            2. Calculate the festivals falling before hijri_end_date.*/
    /* There are 2 cases: 
            1. The hijri year completely lies within a Gregorian year. 
            2. The hijri year doesn't completely lies within a Gregorian year. */
    
    /* This is case 2 */
    if ((hijri_end_date.year - hijri_start_date.year) == MMI_HIJRI_CONSTANT_ONE)
    {
        /* Case 2 has further subcases: 
                1. The start of hijri year coincides with the start of Gregorian year.
                2. The end of hijri year coincides with the end of Gregorian year.
                3. Other. */
        /* This is sub-case 3. */
        if (!(hijri_end_date.day == mmi_hijri_num_days_in_month(hijri_end_date.month, hijri_end_date.year) && hijri_end_date.month == MMI_HIJRI_NUM_MONTHS) ||
        !(hijri_start_date.day == MMI_HIJRI_CONSTANT_ONE && hijri_start_date.month == MMI_HIJRI_CONSTANT_ONE))
        {
            /* Calculate the festival indexes falling after the hijri date on 1/1/YYYY. */
            while (hijri_start_date.month > mmi_hijri_base_fest_date[festival_from_start].month ||
            (hijri_start_date.month == mmi_hijri_base_fest_date[festival_from_start].month &&
            hijri_start_date.day > mmi_hijri_base_fest_date[festival_from_start].day))//Do we need to replace >= with >?
            {
                festival_from_start++;        
                if (festival_from_start == MMI_HIJRI_MAX_FESTIVALS)
                {
                    break;
                }
            }

            /* Calculate the festival indexes falling before the hijri date on 31/12/YYYY. */
            while (hijri_end_date.month > mmi_hijri_base_fest_date[festival_from_end].month ||
                (hijri_end_date.month == mmi_hijri_base_fest_date[festival_from_end].month &&
                hijri_end_date.day >= mmi_hijri_base_fest_date[festival_from_end].day))
            {
                festival_from_end++;
                if (festival_from_end == MMI_HIJRI_MAX_FESTIVALS)
                {
                    break;
                }
            }

            /* Store the calculated indexex above in an array used to store the order of the festivals. */
            while (festival_from_start < MMI_HIJRI_MAX_FESTIVALS)
            {
                g_mmi_hijri_cntx.fest_dates_highlight_year[index] = festival_from_start;
                index++;
                festival_from_start++;
            }

            while (festival_from_end > MMI_HIJRI_CONSTANT_ZERO)
            {
                g_mmi_hijri_cntx.fest_dates_highlight_year[index] = j;
                index++;
                festival_from_end--;
                j++;
            }
            /* If the whole array doesn't gets filled, place -1 in remaining array indexes. */
            while (index < (MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO))
            {
                g_mmi_hijri_cntx.fest_dates_highlight_year[index] = (S8)-1;
                index++;
            }
        }
        else
        {
            /* This is sub-case 2. */
            if (hijri_end_date.day == mmi_hijri_num_days_in_month(hijri_end_date.month, hijri_end_date.year) && hijri_end_date.month == MMI_HIJRI_NUM_MONTHS)
            {
                /* Calculate the festival indexes falling before the hijri date on 31/12/YYYY. */
                for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
                {
                    if (mmi_hijri_base_fest_date[index].day >= hijri_start_date.day)
                    {
                        g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                        j++;
                    }
                }
                /* The 2nd step gets modified here. Instead of calculating the festivals falling before hijri_end_date,
                index of all the festivals falling in a year are stored. */
                for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
                {
                    g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                    j++;
                }
            }
            /* This is sub-case 1. */
            if (hijri_start_date.day == MMI_HIJRI_CONSTANT_ONE && hijri_start_date.month == MMI_HIJRI_CONSTANT_ONE)
            {
                /* The 1st step gets modified here. Instead of calculating the festivals falling after hijri_start_date,
                index of all the festivals falling in a year are stored. */
                for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
                {
                    g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                    j++;
                }
                /* Calculate the festival indexes falling before the hijri date on 31/12/YYYY. */
                for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
                {
                    if (mmi_hijri_base_fest_date[index].day <= hijri_end_date.day)
                    {
                        g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                        j++;
                    }
                }
            }
            while (j < (MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO))
            {
                g_mmi_hijri_cntx.fest_dates_highlight_year[j] = (S8)-1;
                j++;
            }
        }        
    }
    /* This is case 1. */
    else
    {
        /* Here there are 3 steps instead of 2:
                1. Calculate the festivals falling after hijri_start_date and store their indexes.
                2. Store the indexes of all the festivals for a year.
                3. Calculate the festivals falling before hijri_end_date and store their indexes. */
        while (hijri_start_date.month > mmi_hijri_base_fest_date[festival_from_start].month ||
            (hijri_start_date.month == mmi_hijri_base_fest_date[festival_from_start].month &&
            hijri_start_date.day >= mmi_hijri_base_fest_date[festival_from_start].day))
        {
            if (++festival_from_start == MMI_HIJRI_MAX_FESTIVALS)
            {
                festival_from_start = 0;
                break;
            }
        }
        while (hijri_end_date.month > mmi_hijri_base_fest_date[festival_from_end].month ||
                (hijri_end_date.month == mmi_hijri_base_fest_date[festival_from_end].month &&
                hijri_end_date.day >= mmi_hijri_base_fest_date[festival_from_end].day))
        {
            festival_from_end++;
        }
        for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
        {
            g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
            j++;
        }
        for (index = MMI_HIJRI_CONSTANT_ZERO; index < festival_from_end; index++)
        {
            g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
            j++;
        }
        while (j < MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO) 
        {
            g_mmi_hijri_cntx.fest_dates_highlight_year[j] = (S8)-1;
            j++;
        }
    }    
    
    /*if ((hijri_end_date.year - hijri_start_date.year) == MMI_HIJRI_ONE ||
        !(hijri_end_date.day == mmi_hijri_days_in_month[hijri_end_date.month] && hijri_end_date.month == MMI_HIJRI_NUM_MONTHS) ||
        !(hijri_start_date.day == MMI_HIJRI_ONE && hijri_start_date.month == MMI_HIJRI_ONE))
    {
        while (hijri_start_date.month > mmi_hijri_base_fest_date[festival_from_start].month ||
            (hijri_start_date.month == mmi_hijri_base_fest_date[festival_from_start].month &&
            hijri_start_date.day >= mmi_hijri_base_fest_date[festival_from_start].day))
        {
            festival_from_start++;        
        }

        while (hijri_end_date.month > mmi_hijri_base_fest_date[festival_from_end].month ||
            (hijri_end_date.month == mmi_hijri_base_fest_date[festival_from_end].month &&
            hijri_end_date.day >= mmi_hijri_base_fest_date[festival_from_end].day))
        {
            festival_from_end++;
        }

        while (festival_from_start < MMI_HIJRI_MAX_FESTIVALS)
        {
            g_mmi_hijri_cntx.fest_dates_highlight_year[index] = festival_from_start;
            index++;
            festival_from_start++;
        }

        while (festival_from_end > MMI_HIJRI_ZERO)
        {
            g_mmi_hijri_cntx.fest_dates_highlight_year[index] = j;
            index++;
            festival_from_end--;
            j++;
        }
    }
    else
    {
        if (hijri_end_date.day == mmi_hijri_days_in_month[hijri_end_date.month] && hijri_end_date.month == MMI_HIJRI_NUM_MONTHS)
        {
            for (index = MMI_HIJRI_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
            {
                if (mmi_hijri_base_fest_date[index].day >= hijri_start_date.day)
                {
                    g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                    j++;
                }
                for (index = MMI_HIJRI_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
                {
                    g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                    j++;
                }
            }
        }
        else
        {
            for (index = MMI_HIJRI_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
            {
                g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                j++;
            }
            for (index = MMI_HIJRI_ZERO; index < MMI_HIJRI_MAX_FESTIVALS; index++)
            {
                if (mmi_hijri_base_fest_date[index].day <= hijri_end_date.day)
                {
                    g_mmi_hijri_cntx.fest_dates_highlight_year[j] = index;
                    j++;
                }
            }
        }
    }*/

    /* Add trace to print the value of fest_dates_highlight_year */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_FESTIVAL_ORDER, g_mmi_hijri_cntx.fest_dates_highlight_year);
    mmi_hijri_get_fest_greg_date(hijri_start_date, hijri_end_date);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_fest_greg_date
 * DESCRIPTION
 *  This function calculates the Gregorian date from the Hijri date of the hijri festivals and 
 *  then prepares the festival date string.
 * PARAMETERS
 *  hijri_start_date   [IN]    Hijri date on 1/1/YYYY.
 *  hijri_end_date     [IN]    Hijri date on 31/12/YYYY.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_get_fest_greg_date(mmi_hijri_date_struct hijri_start_date, mmi_hijri_date_struct hijri_end_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_year_var, days = 0;
    U8 index, loop_var, temp_month_var, flag = 0;
    MYTIME fest_greg_date[17];
    U8 fest_date_str[11*ENCODING_LENGTH] = {MMI_HIJRI_CONSTANT_ZERO}, temp_str[10] = {MMI_HIJRI_CONSTANT_ZERO};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (index = MMI_HIJRI_CONSTANT_ZERO; index < (MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO); index++)
    { 
        temp_month_var = hijri_start_date.month;
        temp_year_var = hijri_start_date.year;
        /* If all the festivals dates for the year YYYY have been calculated. */
        if (g_mmi_hijri_cntx.fest_dates_highlight_year[index] == -1)
        {
            break;
        }
        /* flag is set one in case the current festival index is not is sequence with the previous festival index.
        Which means that the current index belongs to next hijri year and hence date for that festival be caculated accordingly. */
        if (index > 0 &&
            g_mmi_hijri_cntx.fest_dates_highlight_year[index] != (g_mmi_hijri_cntx.fest_dates_highlight_year[index - MMI_HIJRI_CONSTANT_ONE] + MMI_HIJRI_CONSTANT_ONE))
        {
            flag = 1;
        }
        /* The festival index is in sequence with previous festival index in the array and the festival lies in the same month
        as that of hijri_start_date. */
        if (mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].month == hijri_start_date.month &&
            (mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].day >= hijri_start_date.day) && !flag)
        {
            days = mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].day - hijri_start_date.day;
        }
        /* The festival index is in sequence with previous festival index in the array and the festival doesn't lies in the same month
        as that of hijri_start_date. */
        else if (((mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].month != hijri_start_date.month) ||
            (mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].month == hijri_start_date.month &&
            mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].day < hijri_start_date.day)) && !flag)
        {            
            /* Calculate the difference in days between the current index festival date and hijri start date. */
            days = mmi_hijri_num_days_in_month(temp_month_var, temp_year_var) - hijri_start_date.day;
            if (++temp_month_var > MMI_HIJRI_NUM_MONTHS)
            {
                temp_month_var = 1;
                temp_year_var++;
            }
            while (mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].month != temp_month_var)
            {
                days += mmi_hijri_num_days_in_month(temp_month_var, temp_year_var);
                temp_month_var++;
            }
            days += mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].day;
        }
        else
        {
            /* The festival index is in sequence with previous festival index in the array */
            days = mmi_hijri_num_days_in_month(temp_month_var, temp_year_var) - hijri_start_date.day;
            temp_month_var++;
            while (temp_month_var != 13)
            {
                days += mmi_hijri_num_days_in_month(temp_month_var, temp_year_var);
                temp_month_var++;
            }
            if ((hijri_end_date.year - hijri_start_date.year) == MMI_HIJRI_CONSTANT_TWO)
            {
                temp_month_var = MMI_HIJRI_CONSTANT_ONE;
                temp_year_var++;
                while (temp_month_var != 13)
                {
                    days += mmi_hijri_num_days_in_month(temp_month_var, temp_year_var);
                    temp_month_var++;
                }
            }
            temp_month_var = MMI_HIJRI_CONSTANT_ONE;
            temp_year_var++;
            while (temp_month_var != mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].month)
            {
                days += mmi_hijri_num_days_in_month(temp_month_var, temp_year_var);
                temp_month_var++;
            }
            days += mmi_hijri_base_fest_date[g_mmi_hijri_cntx.fest_dates_highlight_year[index]].day;
        }
        /* For the days difference between the Hijri dates, the Gregorian date needs to be calculate by
        increment 1/1/YYYY by the days difference */
        fest_greg_date[index].nYear = g_mmi_hijri_cntx.fest_year;
        fest_greg_date[index].nMonth = MMI_HIJRI_CONSTANT_ONE;
        while (days > LastDayOfMonth(fest_greg_date[index].nMonth, g_mmi_hijri_cntx.fest_year))
        {
            days -= LastDayOfMonth(fest_greg_date[index].nMonth, fest_greg_date[index].nYear);
            fest_greg_date[index].nMonth++;
            if (fest_greg_date[index].nMonth > MMI_HIJRI_NUM_MONTHS)
            {
                break;
            }
        }
        if (days == LastDayOfMonth(fest_greg_date[index].nMonth, g_mmi_hijri_cntx.fest_year))
        {
            fest_greg_date[index].nDay = MMI_HIJRI_CONSTANT_ONE;
            fest_greg_date[index].nMonth++;
        }
        else if (days == 0)
        {
            fest_greg_date[index].nDay = MMI_HIJRI_CONSTANT_ONE;
        }
        else
        {
            fest_greg_date[index].nDay = (U8)days + MMI_HIJRI_CONSTANT_ONE;
        }
    }

    /* Preparation of festival date string */
    for (loop_var = MMI_HIJRI_CONSTANT_ZERO; loop_var < index; loop_var++)
    {
        memset((S8*) g_mmi_hijri_cntx.dateStr[loop_var], 0, sizeof(g_mmi_hijri_cntx.dateStr[loop_var]));
        memset(fest_date_str, '\0', MMI_HIJRI_CONSTANT_TEN);
        memset(temp_str, '\0', MMI_HIJRI_CONSTANT_TEN);
        gui_itoa((S32) (fest_greg_date[loop_var].nYear), (UI_string_type) temp_str, MMI_HIJRI_CONSTANT_TEN);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) temp_str);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) "/");

        if (fest_greg_date[loop_var].nMonth < MMI_HIJRI_CONSTANT_TEN)
        {
            mmi_ucs2cat((S8*) fest_date_str, (PS8) "0");
        }
        memset(temp_str, '\0', MMI_HIJRI_CONSTANT_TEN);
        gui_itoa((S32) (fest_greg_date[loop_var].nMonth), (UI_string_type) temp_str, MMI_HIJRI_CONSTANT_TEN);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) temp_str);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) "/");

        if (fest_greg_date[loop_var].nDay < MMI_HIJRI_CONSTANT_TEN)
        {
            mmi_ucs2cat((S8*) fest_date_str, (PS8) "0");
        }
        memset(temp_str, '\0', MMI_HIJRI_CONSTANT_TEN);
        gui_itoa((S32) (fest_greg_date[loop_var].nDay), (UI_string_type) temp_str, MMI_HIJRI_CONSTANT_TEN);
        mmi_ucs2cat((S8*) fest_date_str, (S8*) temp_str);
        memset(temp_str, '\0', MMI_HIJRI_CONSTANT_TEN);

        mmi_ucs2cpy((S8*) g_mmi_hijri_cntx.dateStr[loop_var], (S8*) fest_date_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_day_details_options
 * DESCRIPTION
 *  Entry function for showing options screen for Day details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_day_details_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_menu_cui_hijri_day_details_option_parent_gid = mmi_frm_group_create(
                                                GRP_ID_ROOT,
                                                GRP_ID_AUTO_GEN,
                                                mmi_hijri_day_details_option_group_proc,
                                                NULL);
    mmi_frm_group_enter(cui_menu_cui_hijri_day_details_option_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_cui_hijri_day_details_option_gid = cui_menu_create(
                                        cui_menu_cui_hijri_day_details_option_parent_gid,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        MENU_ID_HIJRI_DAY_DETAILS_OPTIONS,
                                        MMI_TRUE,
                                        NULL);

    cui_menu_run(cui_menu_cui_hijri_day_details_option_gid);	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_day_details_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_hijri_day_details_option_group_proc(mmi_event_struct* evt)
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
            mmi_hijri_option_menu_cui_entry_hdlr();
            break;

        /*case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_cal_option_menu_cui_highlight_hdlr(menu_evt);
            break;*/
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_hijri_day_details_menu_cui_select_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cui_menu_cui_hijri_day_details_option_gid);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_day_details_menu_cui_select_hdlr
 * DESCRIPTION
 *   Handlers for the select event of the options menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hijri_day_details_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
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
        case MENU_ID_HIJRI_ADD_REMINDER_DAY_DETAILS:
            mmi_hijri_pre_entry_add_reminder_for_hijri();
            break;
    #endif /* __MMI_TODOLIST__ */
        case MENU_ID_HIJRI_GO_TO_CALENDAR_DAY_DETAILS:
            mmi_hijri_go_to_calendar_day_details();
            break;
        case MENU_ID_HIJRI_SEND_DATE:
            //mmi_hijri_entry_send_date();
            break;
        case MENU_ID_HIJRI_SEND_DATE_BY_SMS:
            mmi_hijri_send_by_SMS();
            break;
    #ifdef __MMI_MMS__
        case MENU_ID_HIJRI_SEND_DATE_BY_MMS:
            mmi_hijri_send_by_MMS();
            break;
    #endif /* __MMI_MMS__ */
    #ifdef __MMI_EMAIL__
        case MENU_ID_HIJRI_SEND_DATE_BY_EMAIL:
            mmi_hijri_send_by_Email();
            break;
    #endif /* __MMI_EMAIL__ */
    }
}
        
    
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_option_menu_cui_entry_hdlr
 * DESCRIPTION
 *  Entry function for showing Hijir festival list for a Gregorian year.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hijri_option_menu_cui_entry_hdlr(void)
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
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_ADD_REMINDER_DAY_DETAILS,MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_ADD_REMINDER_DAY_DETAILS, MMI_FALSE);
    }
#endif /* __MMI_TODOLIST__ */
#if !defined(__MMI_WLAN_FEATURES__)
    if ((srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED) || 
    	!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_SEND_DATE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_SEND_DATE, MMI_FALSE);
    }
#else /* __MMI_WLAN_FEATURES__ */
    if (((srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED) || 
    	!srv_sim_ctrl_is_available(MMI_SIM1)) 
        #if defined(__MMI_EMAIL__)
     		&& (!mmi_email_is_email_can_forward())
        #endif
		)
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_SEND_DATE, MMI_TRUE);
    }
    /*else
    {
        mmi_frm_unhide_menu_item(MENU_ID_HIJRI_SEND_DATE);
    }*/
		#if defined(__MMI_EMAIL__)
	else if (!mmi_email_is_email_can_forward())
	{
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_SEND_DATE, MMI_TRUE);
    }
	#endif
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_SEND_DATE, MMI_FALSE);
    }
#endif /* __MMI_WLAN_FEATURES__ */

#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_day_details_option_gid, MENU_ID_HIJRI_SEND_DATE, MMI_TRUE);
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */
/* Hide the send by SMS and send by MMS menuitems if the preferred mode is WLAN or no sim present or sim not valid. */
    if ((srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED) || 
    	!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        mmi_frm_hide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_SMS);
#ifdef __MMI_MMS__
        mmi_frm_hide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_MMS);
#endif /* __MMI_MMS__ */
#if defined (__MMI_EMAIL__)
#ifdef __MMI_WLAN_FEATURES__
        mmi_frm_hide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_EMAIL);
#else
        mmi_frm_unhide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_EMAIL);
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_EMAIL__ */
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_SMS);
#ifdef __MMI_MMS__
        mmi_frm_unhide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_MMS);
#endif
    }

#ifdef __MMI_MMS__
    if (!mms_is_ready())
    {
        mmi_frm_hide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_MMS);    
    }
#endif
#if  defined(__MMI_EMAIL__)
    if (!mmi_email_is_email_can_forward())
    {
        mmi_frm_hide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_EMAIL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_HIJRI_SEND_DATE_BY_EMAIL);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_festival_list
 * DESCRIPTION
 *  Entry function for showing Hijir festival list for a Gregorian year.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_festival_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_hijri_get_festivals();
    
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_ID_HIJRI_FESTIVAL_LIST,
                    NULL, 
                    mmi_hijri_entry_festival_list, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_hijri_highlighted_index);

    for (index = 0; index < (MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO); index++)
    {
        if (g_mmi_hijri_cntx.fest_dates_highlight_year[index] == (S8)(-1))
        {
            break;
        }
    }
    /* Add a trace to print value of index, which gives number of festivals to be listed for tht year */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_HIJRI_NUM_OF_FESTIVAL, index);

#ifndef __MMI_BASIC_UI_STYLE__
    ShowCategory284Screen (
        STR_HIJRI_FESTIVAL_LIST,
        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
        STR_GLOBAL_DETAILS,
        IMG_GLOBAL_OPTIONS, /* which image id is to be used */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        mmi_hijri_get_festival_names,
        mmi_hijri_get_festival_dates,
        0,
        guiBuffer);
#else
	wgui_cat1032_show(
            (WCHAR*) GetString(STR_HIJRI_FESTIVAL_LIST),
            (PU8) GetImage(ORGANIZER_CALENDER_MENU),
            (WCHAR*) GetString(STR_GLOBAL_DETAILS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            index,
            mmi_hijri_get_festival_names_ext,
            mmi_hijri_get_festival_dates,
            0,
            0,    
            0,
            0,
            guiBuffer,
            NULL);
#endif
    /*SetLeftSoftkeyFunction(mmi_hijri_fest_list_options, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_hijri_go_back_to_main_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_hijri_fest_list_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_hijri_go_back_to_main_menu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);*/
	SetLeftSoftkeyFunction(mmi_hijri_entry_festival_detail, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(mmi_hijri_entry_festival_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_hijri_entry_festival_detail, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_go_back_to_main_menu
 * DESCRIPTION
 *  Takes back to the hijri calendar main menu screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_go_back_to_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory((U16)SCR_ID_HIJRI_MAIN_MENU);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_fest_list_options
 * DESCRIPTION
 *  Entry screen for the hijri festivals options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_fest_list_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_cui_hijri_festival_option_parent_gid = mmi_frm_group_create(
                                                GRP_ID_ROOT,
                                                GRP_ID_AUTO_GEN,
                                                mmi_hijri_festival_option_group_proc,
                                                NULL);
    mmi_frm_group_enter(cui_menu_cui_hijri_festival_option_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_menu_cui_hijri_festival_option_gid = cui_menu_create(
                                        cui_menu_cui_hijri_festival_option_parent_gid,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        MENU_ID_HIJRI_FESTIVAL_OPTIONS,
                                        MMI_TRUE,
                                        NULL);

    cui_menu_run(cui_menu_cui_hijri_festival_option_gid);

#ifdef __MMI_TODOLIST__
    if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_festival_option_gid, MENU_ID_HIJRI_ADD_REMINDER_FESTIVALS, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_cui_hijri_festival_option_gid, MENU_ID_HIJRI_ADD_REMINDER_FESTIVALS, MMI_FALSE);
    }
#endif /* __MMI_TODOLIST__ */
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
static mmi_ret mmi_hijri_festival_option_group_proc(mmi_event_struct* evt)
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
            mmi_hijri_festival_option_menu_cui_select_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cui_menu_cui_hijri_festival_option_gid);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_festival_option_menu_cui_select_hdlr
 * DESCRIPTION
 *   Handlers for the select event of the options menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hijri_festival_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
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
        case MENU_ID_HIJRI_ADD_REMINDER_FESTIVALS:
            mmi_hijri_pre_entry_add_reminder_for_festivals();
            break;
    #endif /* __MMI_TODOLIST__ */
        case MENU_ID_HIJRI_GO_TO_CALENDAR_FESTIVALS:
            mmi_hijri_go_to_calendar_festivals();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_festival_names
 * DESCRIPTION
 *  Highlight handler for Hijri day details viewing
 * PARAMETERS
 *  item_index   [IN]    index passed by the category screen.
 *  *hint_array  [IN]    array to be filled and passed to the category screen for display.
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_hijri_get_festival_dates(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) *hint_array, (S8*) g_mmi_hijri_cntx.dateStr[item_index]);
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_festival_names
 * DESCRIPTION
 *  Highlight handler for Hijri day details viewing
 * PARAMETERS
 *  item_index   [IN]    index passed by the category screen.
 *  str_buff     [IN]    string to be filled with the string of the festival and passed to category for display.
 *  *img_buff_p  
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_hijri_get_festival_names(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < MMI_HIJRI_CONSTANT_ZERO)
    {
        return FALSE;
    }
    str_id = mmi_hijri_get_fest_str_id((U8)item_index);
    mmi_ucs2cpy((S8*) str_buff, GetString(str_id));
    *img_buff_p = NULL;

    return TRUE;
}

#ifdef __MMI_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_festival_names_ext
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_hijri_get_festival_names_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
	S32 i;

	for (i = 0; i< data_size; i++)
	{
		mmi_hijri_get_festival_names(start_index, menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
		start_index++;
	}
	return data_size;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_fest_str_id
 * DESCRIPTION
 *  Returns the festival string ID.
 * PARAMETERS
 *  index   [IN]    index of the festival.
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_hijri_get_fest_str_id(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_hijri_cntx.fest_dates_highlight_year[index])
    {
        case MMI_HIJRI_NEW_YEAR:
            return STR_HIJRI_NEW_YEAR;
        
        case MMI_HIJRI_ASHURAH_DAY:
            return STR_HIJRI_DAY_OF_ASHURAH;
        
        case MMI_HIJRI_MALWID_SUNNI:
            return STR_HIJRI_RABI_AWAL_SUNNI;
        
        case MMI_HIJRI_MALWID_SHIA:
            return STR_HIJRI_RABI_AWAL_SHIA;
        
        case MMI_HIJRI_BDAY_TALIB:
            return STR_HIJRI_BDAY_ALI_IBN;
        
        case MMI_HIJRI_ISRA_MIRAJ:
            return STR_HIJRI_ISRA_MIRAI;
        
        case MMI_HIJRI_SHAB_BARAAT:
            return STR_HIJRI_SHAB_E_BARAAT;
        
        case MMI_HIJRI_FIRST_DAY_FASTING:
            return STR_HIJRI_FIRST_RAMADAN;

        case MMI_HIJRI_NAZUL_QURAN:
            return STR_HIJRI_NAZUL_QURAN;
        
        case MMI_HIJRI_EID_FITR:
            return STR_HIJRI_EID_AL_FITR;
        
        case MMI_HIJRI_HIJJAH:
            return STR_HIJRI_DHUA_AL_HIJJAH;
        
        case MMI_HIJRI_EID_ADHA:
            return STR_HIJRI_EID_AL_GADHA;
        
        case MMI_HJIRI_EID_GHADEER:
            return STR_HIJRI_EID_AL_GADHIR;
        
        default:
            return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_fest_detail_str_id
 * DESCRIPTION
 *  Returns festival details string ID.
 * PARAMETERS
 *  index   [IN]    index of the festival.
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_hijri_get_fest_detail_str_id(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_hijri_cntx.fest_dates_highlight_year[index])
    {
        case MMI_HIJRI_NEW_YEAR:
            return STR_HIJRI_NEW_YEAR_DETAIL;
        
        case MMI_HIJRI_ASHURAH_DAY:
            return STR_HIJRI_DAY_OF_ASHURAH_DETAIL;
        
        case MMI_HIJRI_MALWID_SUNNI:
            return STR_HIJRI_RABI_AWAL_SUNNI_DETAIL;
        
        case MMI_HIJRI_MALWID_SHIA:
            return STR_HIJRI_RABI_AWAL_SHIA_DETAIL;
        
        case MMI_HIJRI_BDAY_TALIB:
            return STR_HIJRI_BDAY_ALI_IBN_DETAIL;
        
        case MMI_HIJRI_ISRA_MIRAJ:
            return STR_HIJRI_ISRA_MIRAI_DETAIL;
        
        case MMI_HIJRI_SHAB_BARAAT:
            return STR_HIJRI_SHAB_E_BARAAT_DETAIL;
        
        case MMI_HIJRI_FIRST_DAY_FASTING:
            return STR_HIJRI_FIRST_RAMADAN_DETAIL;

        case MMI_HIJRI_NAZUL_QURAN:
            return STR_HIJRI_NAZUL_QURAN_DETAIL;
        
        case MMI_HIJRI_EID_FITR:
            return STR_HIJRI_EID_AL_FITR_DETAIL;
        
        case MMI_HIJRI_HIJJAH:
            return STR_HIJRI_DHUA_AL_HIJJAH_DETAIL;
        
        case MMI_HIJRI_EID_ADHA:
            return STR_HIJRI_EID_AL_GADHA_DETAIL;
        
        case MMI_HJIRI_EID_GHADEER:
            return STR_HIJRI_EID_AL_GADHIR_DETAIL;
        
        default:
            return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_send_date
 * DESCRIPTION
 *  Entry function for sending date via SMS, MMS or Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_send_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
        #if defined(__MMI_WLAN_FEATURES__)
/* under construction !*/
        #endif /* defined(__MMI_WLAN_FEATURES__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS__
/* under construction !*/
#endif /* __MMI_MMS__ */
#if defined (__MMI_EMAIL__)
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
#else
/* under construction !*/
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if  defined(__MMI_EMAIL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_send_by_SMS
 * DESCRIPTION
 *  API for sending Muslim date via SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_send_by_SMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct smsData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&smsData, MMI_HIJRI_CONSTANT_ZERO, sizeof(mmi_sms_write_msg_para_struct));
    smsData.dcs = SMSAL_UCS2_DCS;

   /*----------------- Check for valid SIM ---------------------------------*/
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {

        smsData.string = (S8 *)mmi_hijri_get_hijri_date_string();
        smsData.stringlength = mmi_ucs2strlen((const S8*)(smsData.string));
        smsData.flag = MMI_SMS_ENTRY_WRITE_REPLY;

        /* --------------------------- add recipient ------------------------ */
        smsData.ascii_addr = NULL;

        mmi_sms_write_msg_lanch(0,&smsData);
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

#ifdef __MMI_MMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_send_by_MMS
 * DESCRIPTION
 *  API for sending Muslim date via MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_send_by_MMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ucs2data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        ucs2data = mmi_hijri_get_hijri_date_string();
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
 *  mmi_hijri_send_by_Email
 * DESCRIPTION
 *  API for sending Muslim date via Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_send_by_Email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* ucs2data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2data = (S8 *)mmi_hijri_get_hijri_date_string();
    mmi_email_app_send_cont(ucs2data);
    
    if (ucs2data)
    {
        OslMfree(ucs2data);
    }
}
#endif /*__MMI_EMAIL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_hijri_date_string
 * DESCRIPTION
 *  returns Hijri date string
 * PARAMETERS
 *  void
 * RETURNS
 *  CHAR*
 *****************************************************************************/
CHAR *mmi_hijri_get_hijri_date_string(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_data = (CHAR *) OslMalloc((MMI_HIJRI_DATE_STR_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy(ucs2_data, (U8 *)g_mmi_hijri_cntx.hijri_date_string);
    return ucs2_data;
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

 

#ifdef __MMI_TODOLIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_pre_entry_add_reminder_for_festivals
 * DESCRIPTION
 *  Pre entry function of add reminder screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_pre_entry_add_reminder_for_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_TDL_CAL_FULL)), MMI_EVENT_ERROR, NULL);
         return;
    }*/
    mmi_hijri_entry_add_reminder_for_festivals();
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_add_reminder_for_festivals
 * DESCRIPTION
 *  This function calls the TdlExecEdit function to add a reminder on the highlighted Muslim festival date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_add_reminder_for_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    MYTIME start_time, end_time;
    U8 sub_buff[70];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_hijri_cntx.reminder_for_hijri = MMI_HIJRICAL_FESTIVAL_REMINDER;
    memset(sub_buff, 0, sizeof(sub_buff));
    mmi_hijri_get_reminder_date(&start_time);
    mmi_hijri_get_reminder_date(&end_time);
    mmi_hijri_get_reminder_name(sub_buff);

    cui_menu_close(cui_menu_cui_hijri_festival_option_gid);
    sg_id = cui_cal_save_create(GRP_ID_CAL_MAIN);
    cui_cal_save_set_start_time(sg_id, &start_time);
    cui_cal_save_set_end_time(sg_id, &end_time);
    cui_cal_save_set_subject(sg_id, (U16*) (sub_buff));
    cui_cal_save_set_category(sg_id, MMI_TDL_CATEGORY_REMINDER);
    cui_cal_save_set_title(sg_id, STR_GLOBAL_ADD);
    cui_cal_save_set_operation_type(sg_id, MMI_TDL_OP_TYPE_ADD);
    cui_cal_save_run(sg_id);
    g_mmi_hijri_cntx.reminder_for_hijri = MMI_HIJRICAL_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_is_hijri_reminder
 * DESCRIPTION
 *  Returns that the reminder is for hijri festivals.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_hijri_is_hijri_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_hijri_cntx.reminder_for_hijri;
}
#endif /* __MMI_TODOLIST__ */

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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_festival_detail
 * DESCRIPTION
 *  Entry function for the showing festival details. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_festival_detail(void)
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
                    SCR_ID_HIJRI_FESTIVAL_DETAILS,
                    NULL, 
                    mmi_hijri_entry_festival_detail, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_hijri_prepare_fest_detail_string();
	
    ShowCategory79Screen(
        (UI_string_type) g_mmi_hijri_cntx.title_str,
        (U8*) GetImage(GetRootTitleIcon(ORGANIZER_CALENDER_MENU)),
        (UI_string_type) (GetString(STR_GLOBAL_OPTIONS)),
        (U8*) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) (GetString(STR_GLOBAL_BACK)),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        MMI_TRUE,
        MMI_FALSE,
        (UI_buffer_type) g_mmi_hijri_cntx.fest_detail_str,
        mmi_ucs2strlen((PS8) g_mmi_hijri_cntx.fest_detail_str),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_hijri_fest_list_options, KEY_EVENT_UP);
	
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    wgui_inputs_ml_register_set_key_callback(mmi_hijri_festival_display_set_display_key_handler);
    SetKeyHandler(mmi_hijri_increment_festival, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_hijri_decrement_festival, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    SetCenterSoftkeyFunction(mmi_hijri_fest_list_options, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_prepare_fest_detail_string
 * DESCRIPTION
 *  Preparing the date string for showing in the tithi screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_prepare_fest_detail_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 index = 0, weekday;
    U16 fest_str_id;
    PU8 fest_detail_str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(g_mmi_hijri_cntx.fest_detail_str, '\0', (MMI_HIJRI_FEST_DETAILS_STR_LEN + 1) * ENCODING_LENGTH);
	mmi_hijri_fill_festival_date_and_day(g_mmi_hijri_cntx.fest_detail_str, (U8)g_mmi_hijri_cntx.highlighted_index);  /* fill the date and day in the UCS2 format */
		
	fest_str_id = mmi_hijri_get_fest_str_id((U8)g_mmi_hijri_cntx.highlighted_index);
    fest_detail_str = (PU8)GetString(mmi_hijri_get_fest_detail_str_id((U8)g_mmi_hijri_cntx.highlighted_index));
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.fest_detail_str, (S8*) fest_detail_str);

	/* preparing title string for festival */
	mmi_ucs2cpy((S8*) g_mmi_hijri_cntx.title_str, (S8*) "<");
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) " ");
	
	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) GetString((U16)fest_str_id));

	mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) " ");
    mmi_ucs2cat((S8*) g_mmi_hijri_cntx.title_str, (S8*) ">");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_festival_display_set_display_key_handler
 * DESCRIPTION
 *  LNK and RNK handler for festival display. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_festival_display_set_display_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_hijri_increment_festival, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_hijri_decrement_festival, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_fill_festival_date_and_day
 * DESCRIPTION
 *  to fill date and day for festival detail string. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_fill_festival_date_and_day(CHAR *ucs2_data_fest, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 day_str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat((S8*) ucs2_data_fest, (S8*) GetString((U16)(STR_HIJRI_DATE)));
    mmi_ucs2cat((S8*) ucs2_data_fest, " ");

	
	mmi_ucs2cat((S8*) ucs2_data_fest, (S8*) g_mmi_hijri_cntx.dateStr[index]);
	mmi_ucs2cat((S8*) ucs2_data_fest, "\n");

	mmi_ucs2cat((S8*) ucs2_data_fest, (S8*) GetString((U16)(STR_HIJRI_DAY)));
	mmi_ucs2cat((S8*) ucs2_data_fest, " ");
	day_str_id = mmi_hijri_get_string_id_of_day_from_date((CHAR *) g_mmi_hijri_cntx.dateStr[index]);
	mmi_ucs2cat((S8*) ucs2_data_fest, (S8*) GetString(day_str_id));
	mmi_ucs2cat((S8*) ucs2_data_fest, "\n");
	mmi_ucs2cat((S8*) ucs2_data_fest, (S8*) GetString(STR_HIJRI_DESCRIPTION));
	mmi_ucs2cat((S8*) ucs2_data_fest, " ");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_string_id_of_day_from_date
 * DESCRIPTION
 *  to return the day of week from the date string. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_hijri_get_string_id_of_day_from_date(CHAR *date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME time;
	U8 dow;
	CHAR str_greg_ansii_date[11] = {MMI_HIJRI_CONSTANT_ZERO};
	CHAR *tok_ptr;
	U16 str_id = 0;
    S8* last_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((CHAR *) str_greg_ansii_date, date);

	tok_ptr = strtok_r(str_greg_ansii_date, (CHAR *) "/", &last_ptr);
	time.nYear = atoi((CHAR *) tok_ptr);
	
	tok_ptr = strtok_r(NULL, (CHAR *) "/", &last_ptr);
	time.nMonth = atoi((CHAR *) tok_ptr);

	tok_ptr = strtok_r(NULL, (CHAR *) "/", &last_ptr);
	time.nDay = atoi((CHAR *) tok_ptr);

	dow = DOW(time.nYear, time.nMonth, time.nDay);
	switch ( dow )
	{
	case 0:
		str_id = STR_HIJRI_DOW_SUNDAY;
		break;
	case 1:
		str_id = STR_HIJRI_DOW_MONDAY;
		break;
	case 2:
		str_id = STR_HIJRI_DOW_TUESDAY;
		break;
	case 3:
		str_id = STR_HIJRI_DOW_WEDNESDAY;
		break;
	case 4:
		str_id = STR_HIJRI_DOW_THURSDAY;
		break;
	case 5:
		str_id = STR_HIJRI_DOW_FRIDAY;
		break;
	case 6:
		str_id = STR_HIJRI_DOW_SATURDAY;
		break;
	default:
		break;
	}

	return str_id;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_increment_festival
 * DESCRIPTION
 *  to show the details of the next festival in the list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_increment_festival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_HIJRI_FESTIVAL_DETAILS);
    if( mmi_hijri_check_max_festival_limit(g_mmi_hijri_cntx.highlighted_index) )
	{
		g_mmi_hijri_cntx.highlighted_index++;		
	}
	else
	{
		g_mmi_hijri_cntx.highlighted_index = 0;
	}
    mmi_hijri_prepare_fest_detail_string();
    ChangeCategory79Title((UI_string_type) g_mmi_hijri_cntx.title_str, (U16) GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
    ChangeCategory79MessageString(
        (UI_buffer_type) g_mmi_hijri_cntx.fest_detail_str,
        mmi_ucs2strlen((PS8) g_mmi_hijri_cntx.fest_detail_str), 
        MMI_TRUE, 
        MMI_TRUE, 
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_decrement_festival
 * DESCRIPTION
 *  to show the details of the previous festival in the list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_decrement_festival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_HIJRI_FESTIVAL_DETAILS);
	if(g_mmi_hijri_cntx.highlighted_index == 0)
	{
		g_mmi_hijri_cntx.highlighted_index = mmi_hijri_max_festival_in_current_festival_list();/* max value of festival in that particular year */
	}
	else
	{
		g_mmi_hijri_cntx.highlighted_index--;
	}
	mmi_hijri_prepare_fest_detail_string();
    ChangeCategory79Title((UI_string_type) g_mmi_hijri_cntx.title_str, (U16) GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
    ChangeCategory79MessageString(
        (UI_buffer_type) g_mmi_hijri_cntx.fest_detail_str,
        mmi_ucs2strlen((PS8) g_mmi_hijri_cntx.fest_detail_str), 
        MMI_TRUE, 
        MMI_TRUE, 
        MMI_FALSE);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_check_max_festival_limit
 * DESCRIPTION
 *  to check if the max festival limit has been reached or not.
 * PARAMETERS
 *  S32 index
 * RETURNS
 *  TRUE  if limit not reached
 *  FALSE if LIMIT reached
 *****************************************************************************/
pBOOL mmi_hijri_check_max_festival_limit(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 max_limit = MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_ONE; /* max index of an array*/
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while ( g_mmi_hijri_cntx.fest_dates_highlight_year[max_limit] == (S8)-1 )
	{
		max_limit--;
	}

	if( max_limit == index )
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_max_festival_in_current_festival_list
 * DESCRIPTION
 *  returns the number of festivals in the current festival list.
 * PARAMETERS
 *  S32 index
 * RETURNS
 *  number of festivals
 *****************************************************************************/
S32 mmi_hijri_max_festival_in_current_festival_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 max_festivals = MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_ONE; /* max index of an array*/
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while ( g_mmi_hijri_cntx.fest_dates_highlight_year[max_festivals] == (S8)-1 )
	{
		max_festivals--;
	}
	return max_festivals;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_hijri_date_str
 * DESCRIPTION
 *  Get the Hijri date string for display as pop up
 * PARAMETERS
 *  curr_time               [IN]
 *  str_hijri_date1        [OUT]
 *  str_hijri_date2        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_get_hijri_date_str(
        MYTIME curr_time,
        UI_string_type str_hijri_date1,
        UI_string_type str_hijri_date2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type tempstr[MMI_HIJRI_CONSTANT_TEN];
    pBOOL is_date_within_range;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    is_date_within_range = mmi_hijri_monthly_out_of_boundary(&curr_time, MMI_FALSE);
    if (is_date_within_range == MMI_FALSE)
    {
        return;
    }
    g_mmi_hijri_cntx.hijri_date = mmi_hijri_greg_to_hijri(curr_time);
    
    /*if (r2lMMIFlag)
    {
        S32 count = 0;
        if ( g_mmi_hijri_cntx.hijri_date.day > 9)
        {
            if (mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_ARABIC) == 0)
            {
                str_hijri_date1[count++] = (U16)(g_mmi_hijri_cntx.hijri_date.day / MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_ARABIC_UNICODE_NUMERAL_START;
            }
            else if (mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_URDU) == 0)
            {
                str_hijri_date1[count++] = (U16)(g_mmi_hijri_cntx.hijri_date.day / MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_URDU_UNICODE_NUMERAL_START;
            }
        }
        if (mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_ARABIC) == 0)
        {
            str_hijri_date1[count++] = (U16)(g_mmi_hijri_cntx.hijri_date.day % MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_ARABIC_UNICODE_NUMERAL_START;
        }
        else if (mmi_ucs2cmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, (S8*) SSC_URDU) == 0)
        {
            str_hijri_date1[count++] = (U16)(g_mmi_hijri_cntx.hijri_date.day / MMI_HIJRI_CONSTANT_TEN) + MMI_HIJRI_URDU_UNICODE_NUMERAL_START;
        }
        str_hijri_date1[count] = 0;
    }
    else
    {*/
        gui_itoa((S32) (g_mmi_hijri_cntx.hijri_date.day), tempstr, MMI_HIJRI_CONSTANT_TEN);
        mmi_ucs2cpy((S8*) str_hijri_date1, (S8*) tempstr);
    //}
    /*if (g_mmi_hijri_cntx.hijri_date.month == (MMI_HIJRI_RABBI_AWWAL + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) str_hijri_date2, (S8*) GetString((U16) (STR_HIJRI_RABI_ONE)));
    }
    else if (g_mmi_hijri_cntx.hijri_date.month == (MMI_HIJRI_RABBI_THANI + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) str_hijri_date2, (S8*) GetString((U16) (STR_HIJRI_RABI_TWO)));
    }
    else if (g_mmi_hijri_cntx.hijri_date.month == (MMI_HIJRI_JUMADA_AWWAL + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) str_hijri_date2, (S8*) GetString((U16) (STR_HIJRI_JUMADA_ONE)));
    }
    else if (g_mmi_hijri_cntx.hijri_date.month == (MMI_HIJRI_JUMADA_THANI + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) str_hijri_date2, (S8*) GetString((U16) (STR_HIJRI_JUMADA_TWO)));
    }
    else
    {
    mmi_ucs2cpy((S8*) str_hijri_date2, (S8*) GetString((U16) (STR_HIJRI_MUHARRAM + g_mmi_hijri_cntx.hijri_date.month - 1)));
    }*/
    /*mmi_ucs2cpy((S8*) str_hijri_date3, (S8*) GetString(STR_HIJRI_ANNO_HEGIRE));
    gui_itoa((S32) (g_mmi_hijri_cntx.hijri_date.year), tempstr, MMI_HIJRI_CONSTANT_TEN);
    mmi_ucs2cat((S8*)str_hijri_date3, (S8*) tempstr);*/

	mmi_ucs2cpy((S8*) str_hijri_date2, (S8*) GetString((U16)(STR_HIJRI_ITWAAR + curr_time.DayIndex)));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_monthly_out_of_boundary
 * DESCRIPTION
 *  This API will check the currDate and return MMI_FALSE if the date falls
 *  outside the Hijri Calendar boundary.And also display a popup depending on
 *  the show_popup parameter.
 * PARAMETERS
 *  currDate        [IN]        
 *  show_popup      [IN]        
 * RETURNS
 *  MMI_FALSE - Out of range, MMI_TRUE - Within range
 *****************************************************************************/
MMI_BOOL mmi_hijri_monthly_out_of_boundary(MYTIME *currDate, MMI_BOOL show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((currDate->nYear > MMI_HIJRI_END_YEAR) || (currDate->nYear < MMI_HIJRI_START_YEAR))
    {
        if (MMI_TRUE == show_popup)
        {
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_HIJRI_VALID_RANGE)), MMI_EVENT_FAILURE, NULL);
        }
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_reminder_date
 * DESCRIPTION
 *  Convers the time value into a string.
 * PARAMETERS
 *  *time   [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_get_reminder_date(MYTIME *time)	/*  same function is to be used for get festival date */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_greg_ansii_date[11] = {MMI_HIJRI_CONSTANT_ZERO}, *tok_ptr;
    S8* last_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( g_mmi_hijri_cntx.reminder_for_hijri == MMI_HIJRICAL_FESTIVAL_REMINDER )
	{
		mmi_ucs2_to_asc((S8*) str_greg_ansii_date, (S8*) g_mmi_hijri_cntx.dateStr[g_mmi_hijri_cntx.highlighted_index]);

		tok_ptr = (S8*) strtok_r((S8*) str_greg_ansii_date, (S8*) "/", &last_ptr);
		g_mmi_hijri_cntx.fest_year = atoi((S8*) tok_ptr);
		time->nYear = g_mmi_hijri_cntx.fest_year;

		tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
		time->nMonth = atoi((S8*) tok_ptr);

		tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
		time->nDay = atoi((S8*) tok_ptr);
	}
	else /* to get reminder date for any hijri date selected by user */
	{
		time->nYear = g_mmi_hijri_cntx.clndr_date.nYear;
		time->nMonth = g_mmi_hijri_cntx.clndr_date.nMonth;
		time->nDay = g_mmi_hijri_cntx.clndr_date.nDay;
	}
	time->nHour = time->nMin = time->nSec = time->DayIndex = MMI_HIJRI_CONSTANT_ZERO;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_reminder_name
 * DESCRIPTION
 *  Gets the Festival name and copies into str_buff. This function is used for providing
 * festival name which will be shown in the Notes field of todolist reminder, or if the 
 * reminder is for any hijri date then str_buff is left empty.
 * PARAMETERS
 *  *str_buff   [IN]    Buffer to fill the reminder name.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_get_reminder_name(U8* str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	if ( g_mmi_hijri_cntx.reminder_for_hijri == MMI_HIJRICAL_FESTIVAL_REMINDER )
	{
		str_id = mmi_hijri_get_fest_str_id((U8)g_mmi_hijri_cntx.highlighted_index);
		memset(str_buff, 0, sizeof(GetString(str_id)));
		mmi_ucs2cpy((S8*) str_buff, GetString(str_id));
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_num_days_in_month
 * DESCRIPTION
 *  Gets the Festival name and copies into str_buff. This function is used for providing
 * festival name which will be shown in the Notes field of todolist reminder.
 * PARAMETERS
 *  month   [IN]    Month for which number of hijri days needs to be determined.       
 * RETURNS
 *  Number of hijri days present in the hijri month.
 *****************************************************************************/
U8 mmi_hijri_num_days_in_month(U8 month, U16 year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 remainder;
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (month%2)
    {
        return MMI_HIJRI_DAYS_IN_ODD_MONTHS;
    }
    else
    {
        remainder = year%30;
        for (index = MMI_HIJRI_CONSTANT_ZERO; index < MMI_HIJRI_LEAP_YEARS; index++)
        {
            if (remainder == mmi_hijri_leap_year_table[index] && month == MMI_HIJRI_NUM_MONTHS)
            {
                return MMI_HIJRI_DAYS_IN_EVEN_MONTHS + MMI_HIJRI_CONSTANT_ONE;
            }
        }
        return MMI_HIJRI_DAYS_IN_EVEN_MONTHS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_date_correction_set_hilite_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_date_correction_set_hilite_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 read_correction;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    ReadValue(NVRAM_HIJRI_CORRECTION, &read_correction, DS_BYTE, &error);

    switch (read_correction)
    {
        case 0:
        {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_HIJRI_DATE_SUB_TWO_DAYS));
            break;
        }
        case 1:
        {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_HIJRI_DATE_SUB_ONE_DAY));
            break;
        }
        case 2:
        {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_HIJRI_DATE_NO_CORRECTION));
            break;
        }
        case 3:
        {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_HIJRI_DATE_ADD_ONE_DAY));
            break;
        }
        case 4:
        {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_HIJRI_DATE_ADD_TWO_DAYS));
            break;
        }
        default:
        {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_HIJRI_DATE_NO_CORRECTION));
            break;
        }
    }
}

/*  title string function */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_date_str
 * DESCRIPTION
 *  Fills the calendar title.
 * PARAMETERS
 *  void
 * RETURNS
 *  whether the title string is filled or not.
 *****************************************************************************/
U8 mmi_hijri_get_date_str(MYTIME curr_time, U8* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_hijri_date_struct hijri_date = {0};
    UI_character_type temp_year_buff[MMI_HIJRI_YEAR_LEN];
    MMI_BOOL is_date_within_range = MMI_FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_date_within_range = mmi_hijri_monthly_out_of_boundary(&curr_time, MMI_FALSE);
    if (MMI_FALSE == is_date_within_range)
    {        
        return 0;
    }
	hijri_date = mmi_hijri_greg_to_hijri(curr_time);	
	gui_itoa((S32) (hijri_date.year), temp_year_buff, MMI_HIJRI_CONSTANT_TEN);



	if (hijri_date.month == (MMI_HIJRI_RABBI_AWWAL + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) title, (S8*) GetString((U16) (STR_HIJRI_RABI_ONE)));
    }
    else if (hijri_date.month == (MMI_HIJRI_RABBI_THANI + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) title, (S8*) GetString((U16) (STR_HIJRI_RABI_TWO)));
    }
    else if (hijri_date.month == (MMI_HIJRI_JUMADA_AWWAL + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) title, (S8*) GetString((U16) (STR_HIJRI_JUMADA_ONE)));
    }
    else if (hijri_date.month == (MMI_HIJRI_JUMADA_THANI + MMI_HIJRI_CONSTANT_ONE))
    {
        mmi_ucs2cpy((S8*) title, (S8*) GetString((U16) (STR_HIJRI_JUMADA_TWO)));
    }
    else
    {
		mmi_ucs2cpy((S8*) title, (S8*) GetString((U16) (STR_HIJRI_MUHARRAM + hijri_date.month - 1)));
    }


    /*mmi_ucs2cpy((S8*) title, (S8*) GetString((U16)(STR_HIJRI_MUHARRAM + hijri_date.month - 1)));*/
	mmi_ucs2cat((S8*) title, (S8*) " ");
    mmi_ucs2cat((S8*) title, (S8*) temp_year_buff);    
    return 1;
}

/*  handler function for go to calendar from day details */


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_go_to_calendar_day_details
 * DESCRIPTION
 *  LSK handler for Go to calendar from day details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_hijri_go_to_calendar_day_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to set the calendar current date as the one selected in the hijri calendar */
	
	mmi_clndr_set_jump_to_date(g_mmi_hijri_cntx.clndr_date);

	/* delete the screens upto calendar main screen and call the entry function for the calendar main screen */
    cui_menu_close(cui_menu_cui_hijri_day_details_option_gid);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_HIJRI_DAY_DETAILS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_go_to_calendar_festivals
 * DESCRIPTION
 *  LSK handler for Go to calendar from day details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_hijri_go_to_calendar_festivals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to set the calendar current date as the one selected in the hijri calendar */
	mmi_hijri_get_date_from_festival_date_string(&time);

	mmi_clndr_set_jump_to_date(time);

	/* delete the screens upto calendar main screen and call the entry function for the calendar main screen */
    cui_menu_close(cui_menu_cui_hijri_festival_option_gid);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_HIJRI_FESTIVAL_LIST);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_ID_HIJRI_FESTIVAL_DETAILS);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_date_from_festival_date_string
 * DESCRIPTION
 *  to get date in MYTIME structure from fest date string.
 * PARAMETERS
 *  MYTIME*		date t be filled with date 
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_hijri_get_date_from_festival_date_string(MYTIME* date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_greg_ansii_date[11] = {MMI_HIJRI_CONSTANT_ZERO}, *tok_ptr, *last_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to set the calendar current date as the one selected in the hijri calendar */
	mmi_ucs2_to_asc((S8*) str_greg_ansii_date, (S8*) g_mmi_hijri_cntx.dateStr[g_mmi_hijri_cntx.highlighted_index]);

	tok_ptr = (S8*) strtok_r((S8*) str_greg_ansii_date, (S8*) "/", &last_ptr);
	date->nYear = atoi((S8*) tok_ptr);

	tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
	date->nMonth = atoi((S8*) tok_ptr);
	tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
	date->nDay = atoi((S8*) tok_ptr);	
	date->nHour = date->nMin = date->nSec = date->DayIndex = MMI_HIJRI_CONSTANT_ZERO;
}


#ifdef __MMI_TODOLIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_pre_entry_add_reminder_for_hijri
 * DESCRIPTION
 *  Pre entry function of add reminder screen via day details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_pre_entry_add_reminder_for_hijri(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_TDL_CAL_FULL)), MMI_EVENT_ERROR, NULL);
         return;
    }*/
    mmi_hijri_entry_add_reminder_for_hijri_date();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_entry_add_reminder_for_hijri_date
 * DESCRIPTION
 *  This function calls the TdlExecEdit function to add a reminder on the
 *  selected hijri date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_entry_add_reminder_for_hijri_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    MYTIME start_time, end_time;
    U8 sub_buff[70];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_hijri_cntx.reminder_for_hijri = MMI_HIJRICAL_DAY_REMINDER;
    memset(sub_buff, 0, sizeof(sub_buff));
    mmi_hijri_get_reminder_date(&start_time);
    mmi_hijri_get_reminder_date(&end_time);
    mmi_hijri_get_reminder_name(sub_buff);

    cui_menu_close(cui_menu_cui_hijri_day_details_option_gid);
    sg_id = cui_cal_save_create(GRP_ID_CAL_MAIN);
    cui_cal_save_set_start_time(sg_id, &start_time);
    cui_cal_save_set_end_time(sg_id, &end_time);
    cui_cal_save_set_subject(sg_id, (U16*) (sub_buff));
    cui_cal_save_set_category(sg_id, MMI_TDL_CATEGORY_REMINDER);
    cui_cal_save_set_title(sg_id, STR_GLOBAL_ADD);
    cui_cal_save_set_operation_type(sg_id, MMI_TDL_OP_TYPE_ADD);
    cui_cal_save_run(sg_id);
    g_mmi_hijri_cntx.reminder_for_hijri = MMI_HIJRICAL_NONE;
}
#endif /* __MMI_TODOLIST__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_hijri_get_list_of_festival_icons
 * DESCRIPTION
 *  This function fills the array passsed by calendar with the icon
 *  corresponding to the dates on which any muslim festival lies.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hijri_get_list_of_festival_icons(MYTIME clndr_time, mmi_clndr_cell_struct *daily_task_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLNDR_EVENT_INFO__    
    MYTIME *time;
	MYTIME currTime = {0, };    
	S8 str_greg_ansii_date[11] = {0}, *tok_ptr, *last_ptr;
    U8 index, max_festivals;
	pBOOL is_date_within_range = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	mmi_clndr_get_updated_date_time_after_jump_to_date(&currTime);
    is_date_within_range = mmi_hijri_monthly_out_of_boundary(&currTime, MMI_FALSE);
    if (is_date_within_range == MMI_TRUE)
    {
        mmi_clndr_get_updated_date_time_after_jump_to_date(&g_mmi_hijri_cntx.clndr_date);
		g_mmi_hijri_cntx.fest_year = g_mmi_hijri_cntx.clndr_date.nYear;
		mmi_hijri_get_festivals();	/* to get date strings for all festival in that year */
		max_festivals = mmi_hijri_max_festival_in_current_festival_list();
		time = (MYTIME*) OslMalloc((max_festivals + 1) * sizeof(MYTIME));

		for (index = 0; index <= max_festivals; index++)
		{
			mmi_ucs2_to_asc((S8*) str_greg_ansii_date, (S8*) g_mmi_hijri_cntx.dateStr[index]);

			tok_ptr = (S8*) strtok_r((S8*) str_greg_ansii_date, (S8*) "/", &last_ptr);
			time[index].nYear = atoi((S8*) tok_ptr);

			tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
			time[index].nMonth = atoi((S8*) tok_ptr);

			tok_ptr = (S8*) strtok_r(NULL, (S8*) "/", &last_ptr);
			time[index].nDay = atoi((S8*) tok_ptr);

			time[index].nHour = time[index].nMin = time[index].nSec = time[index].DayIndex = 0;
		}
		index = 0;
		while(index < max_festivals)
        {
            if (time[index].nMonth == clndr_time.nMonth)
            {
                break;
            }
            index++;
        }
        if (index == (max_festivals + 1))
        {
            OslMfree(time);
			return;
        }
		/*while (time[index++].nMonth != clndr_time.nMonth);
		if (index == 0)
		{
			OslMfree(time);
			return;
		}*/
		while (time[index].nMonth <= clndr_time.nMonth)
        {
            if (!daily_task_info[time[index].nDay].date)
            {
                daily_task_info[time[index].nDay].date = MMI_TRUE;
                daily_task_info[time[index].nDay].icon = IMG_ID_HIJRI_FESTIVAL_ICON;
            }
            if (index == (max_festivals))
            {
                break;
            }
            index++;
        }
		OslMfree(time);
    }
    #endif 
}

#endif /* __MMI_HIJRI_CALENDAR__ */
