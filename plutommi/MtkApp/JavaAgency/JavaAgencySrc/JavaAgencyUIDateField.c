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
 *   JavaAgencyUIDateField.c
 *
 * Project:
 * --------
 *   Maui_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __J2ME__
#include "mmi_include.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include "wgui_calendar.h"
#include "wgui_categories_util.h"

#include "JavaAgencyUIDateField.h"
#include "JavaAgencyDef.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#endif

#ifdef __OP01__
#include "mmi_rp_app_uiframework_def.h"
#endif

static void mmi_java_ui_clndr_highlight_select_handler(gui_calendar_type_enum type,applib_time_struct highlighted_time);
static void mmi_java_ui_clndr_get_date_str(MYTIME *date, U8 *dateStr);
static void mmi_java_ui_clndr_get_weekday(U8 **weekdayStr);
static void mmi_java_ui_clndr_get_week_numbers(U16 year, U8 month, U8 **weekStr);
static void mmi_java_ui_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len);
static void mmi_java_ui_clndr_construct_monthly_cell_info(void);
static void mmi_java_ui_clndr_get_screenInfo(void);
//static MMI_BOOL mmi_java_ui_clndr_monthly_highlight(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_monthly_compute_next_time(U32 arrow);
static MMI_BOOL mmi_java_ui_clndr_monthly_out_of_boundary(MYTIME *resultDate);
//static MMI_BOOL mmi_java_ui_clndr_left_out_of_boundary(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_right_out_of_boundary(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_up_out_of_boundary(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_down_out_of_boundary(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_up_side_key(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_down_side_key(U32 row, U32 column);
static MMI_BOOL mmi_java_ui_clndr_highlight_change_handler(gui_calendar_type_enum type,applib_time_struct highlighted_time,applib_time_struct start_time,applib_time_struct end_time);
#ifdef __MMI_TOUCH_SCREEN__
//static MMI_BOOL mmi_java_ui_clndr_touch_year_increase(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_touch_year_decrease(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_touch_month_increase(U32 row, U32 column);
//static MMI_BOOL mmi_java_ui_clndr_touch_month_decrease(U32 row, U32 column);
#endif /* __MMI_TOUCH_SCREEN__ */ /* #__MMI_TOUCH_SCREEN__ */
//static MMI_BOOL mmi_java_ui_clndr_monthly_movement(U32 type);
static void mmi_java_ui_clndr_monthly_set_content(void);
static void mmi_java_ui_clndr_done_handler(void);
static void mmi_java_ui_clndr_cancel_handler(void);
static void mmi_java_ui_entry_datefield_date(void);
static void mmi_java_ui_entry_datefield_date(void);
//static void mmi_java_ui_delete_datefield_date_callback(void);

const S8 mmi_java_ui_clndr_weekday[] = { 'S', 'M', 'T', 'W', 'T', 'F', 'S' };
static mmi_java_ui_clndr_context_struct g_mmi_java_ui_clndr_context_struct;
mmi_java_ui_clndr_context_struct *g_mmi_java_ui_clndr_cntx = &g_mmi_java_ui_clndr_context_struct;
#ifdef __COSMOS_MMI_PACKAGE__
static mmi_java_ui_time_context_struct g_mmi_java_ui_time_cntx;
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_datefield_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_datefield_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_datefield_date_show_req,
        MSG_ID_MMI_JAVA_UI_DATEFIELD_DATE_SHOW_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_datafield_date_hide_req,
        MSG_ID_MMI_JAVA_UI_DATEFIELD_DATE_HIDE_REQ);

    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_datefield_time_show_req,
        MSG_ID_MMI_JAVA_UI_DATEFIELD_TIME_SHOW_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_datafield_time_hide_req,
        MSG_ID_MMI_JAVA_UI_DATEFIELD_TIME_HIDE_REQ);
}


#ifdef __COSMOS_MMI_PACKAGE__

extern void jvm_home_key_handler(void);
extern void jvm_end_key_handler(void);
extern void vapp_java_ui_datefield_exit(void);

void vapp_java_ui_datefield_homekey_handler(void)
{
    vapp_java_ui_datefield_hide();
    jvm_home_key_handler();
}

void vapp_java_ui_datefield_backkey_handler(void)
{
    vapp_java_ui_datefield_hide();
}





void mmi_java_ui_datefield_exit_screen(MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //vapp_java_ui_datefield_exit();
    
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    mmi_frm_scrn_close(GRP_ID_JAVA_APP, scrn_id);

    /*if (screen_id == scrn_id)
    {
        mmi_frm_scrn_close_active_id();
    }*/
}

void vapp_java_ui_entry_datefield_date(void)
{
    mmi_frm_scrn_enter(
        GRP_ID_JAVA_APP,
        SCR_ID_JAVA_UI_DATEFIELD_DATE,
        vapp_java_ui_datefield_exit,
        vapp_java_ui_entry_datefield_date,
        MMI_FRM_FULL_SCRN);
    SetKeyHandler(jvm_home_key_handler, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(vapp_java_ui_datefield_backkey_handler, KEY_BACK, KEY_EVENT_DOWN);
	SetKeyHandler(jvm_end_key_handler, KEY_END, KEY_EVENT_DOWN);
    vapp_java_ui_datefield_date_launch(g_mmi_java_ui_clndr_cntx);
}

void vapp_java_ui_entry_datefield_time(void)
{
    mmi_frm_scrn_enter(
        GRP_ID_JAVA_APP,
        SCR_ID_JAVA_UI_DATEFIELD_TIME,
        vapp_java_ui_datefield_exit,
        vapp_java_ui_entry_datefield_time,
        MMI_FRM_FULL_SCRN);
    SetKeyHandler(jvm_home_key_handler, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(vapp_java_ui_datefield_backkey_handler, KEY_BACK, KEY_EVENT_DOWN);
	SetKeyHandler(jvm_end_key_handler, KEY_END, KEY_EVENT_DOWN);
    vapp_java_ui_datefield_time_launch(&g_mmi_java_ui_time_cntx);
}
/*
void vapp_java_ui_exit_datefield_date(void)
{
}

void vapp_java_ui_exit_datefield_time(void)
{
}
*/

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_datefield_date_show_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_datefield_date_show_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYTIME myTime;
   // S32 highlightCell, currCell = -1;
    //S32 i;
    //gui_calendar_cell_struct *startCell;

    mmi_java_ui_datefield_date_show_req_struct *msg = (mmi_java_ui_datefield_date_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

    memset(&g_mmi_java_ui_clndr_cntx->CalTime, 0, sizeof(MYTIME));
    g_mmi_java_ui_clndr_cntx->CalTime.nDay = (kal_uint8) msg->day;
    g_mmi_java_ui_clndr_cntx->CalTime.nMonth = (kal_uint8) (msg->month + 1);
    g_mmi_java_ui_clndr_cntx->CalTime.nYear = (kal_uint16) msg->year;
    g_mmi_java_ui_clndr_cntx->callback = msg->callback;
    g_mmi_java_ui_clndr_cntx->vm_id = msg->vm_id;

#ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_ui_entry_datefield_date();
#else
    vapp_java_ui_entry_datefield_date();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_datafield_date_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_datafield_date_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_datefield_date_show_req_struct *msg = (mmi_java_ui_datefield_date_show_req_struct*) msg_struct;
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

#ifndef __COSMOS_MMI_PACKAGE__
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_DATEFIELD_DATE);

    if (screen_id == SCR_ID_JAVA_UI_DATEFIELD_DATE)
    {
        mmi_frm_scrn_close_active_id();
    }
#else
    vapp_java_ui_datefield_hide();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_datefield_time_show_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_datefield_time_show_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_ui_datefield_time_show_req_struct *msg = (mmi_java_ui_datefield_time_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

#ifdef __COSMOS_MMI_PACKAGE__
    g_mmi_java_ui_time_cntx.hour = msg->hour;
    g_mmi_java_ui_time_cntx.minute = msg->minute;
    g_mmi_java_ui_time_cntx.second = msg->second;
    g_mmi_java_ui_time_cntx.vm_id = msg->vm_id;
    g_mmi_java_ui_time_cntx.callback = msg->callback;

    vapp_java_ui_entry_datefield_time();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_datafield_time_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_datafield_time_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_datefield_time_show_req_struct *msg = (mmi_java_ui_datefield_time_show_req_struct*) msg_struct;
    MMI_ID group_id, screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

#ifndef __COSMOS_MMI_PACKAGE__
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);
    if (screen_id == SCR_ID_JAVA_UI_DATEFIELD_TIME)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_DATEFIELD_TIME);
    }
#else
    vapp_java_ui_datefield_hide();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_exit_clndr_screen
 * DESCRIPTION
 *  Exit function of calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_exit_clndr_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_clndr_cntx)
    {
        if (g_mmi_java_ui_clndr_cntx->Title != NULL)
        {
            applib_mem_ap_free((void*)g_mmi_java_ui_clndr_cntx->Title);
            g_mmi_java_ui_clndr_cntx->Title = NULL;
        }

        if (g_mmi_java_ui_clndr_cntx->HorizonList[0] != NULL)
        {
            applib_mem_ap_free((void*)g_mmi_java_ui_clndr_cntx->HorizonList[0]);
            g_mmi_java_ui_clndr_cntx->HorizonList[0] = NULL;
        }

        if (g_mmi_java_ui_clndr_cntx->VerticalList[0] != NULL)
        {
            applib_mem_ap_free((void*)g_mmi_java_ui_clndr_cntx->VerticalList[0]);
            g_mmi_java_ui_clndr_cntx->VerticalList[0] = NULL;
        }

        if (g_mmi_java_ui_clndr_cntx->CalendarCell != NULL)
        {
            applib_mem_ap_free((void*)g_mmi_java_ui_clndr_cntx->CalendarCell);
            g_mmi_java_ui_clndr_cntx->CalendarCell = NULL;
        }

    }
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_entry_datefield_date
 * DESCRIPTION
 *  Enter function of calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_entry_datefield_date()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME myTime;
    //S32 highlightCell, currCell = -1;
    S32 i;
    //gui_calendar_cell_struct *startCell;
    applib_time_struct max_time, min_time, highlight_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_JAVA_APP,
        SCR_ID_JAVA_UI_DATEFIELD_DATE,
        mmi_java_ui_exit_clndr_screen,
        mmi_java_ui_entry_datefield_date,
        MMI_FRM_FULL_SCRN);

    /* SetDelScrnIDCallbackHandler(mmi_java_SCREEN_DATEFIELD_CALENDAR, mmi_java_ui_delete_datefield_date_callback); */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    g_mmi_java_ui_clndr_cntx->Title = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,MMI_JAVA_UI_CLNDR_TITLE_LEN * MMI_JAVA_UI_CLNDR_COLUMN);
    
    g_mmi_java_ui_clndr_cntx->HorizonList[0] =
        (U8*) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,
                                                           MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH *MMI_JAVA_UI_CLNDR_COLUMN);
    g_mmi_java_ui_clndr_cntx->VerticalList[0] =
        (U8*) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,
                                                           MMI_JAVA_UI_CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * MMI_JAVA_UI_CLNDR_ROW);
    g_mmi_java_ui_clndr_cntx->RowNumber = MMI_JAVA_UI_CLNDR_ROW;
    g_mmi_java_ui_clndr_cntx->CalendarCell = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,
                                 (g_mmi_java_ui_clndr_cntx->RowNumber * MMI_JAVA_UI_CLNDR_COLUMN) * MMI_JAVA_UI_CLNDR_CELL_SIZE);

    for (i = 1; i < MMI_JAVA_UI_CLNDR_COLUMN; i++)
    {
        g_mmi_java_ui_clndr_cntx->HorizonList[i] =
            g_mmi_java_ui_clndr_cntx->HorizonList[i - 1] + MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
    }
    for (i = 1; i < MMI_JAVA_UI_CLNDR_ROW; i++)
    {
        g_mmi_java_ui_clndr_cntx->VerticalList[i] =
            g_mmi_java_ui_clndr_cntx->VerticalList[i - 1] + MMI_JAVA_UI_CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
    }

    memset(g_mmi_java_ui_clndr_cntx->Title, 0, MMI_JAVA_UI_CLNDR_TITLE_LEN * MMI_JAVA_UI_CLNDR_COLUMN);
    memset(
        g_mmi_java_ui_clndr_cntx->HorizonList[0],
        0,
        MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * MMI_JAVA_UI_CLNDR_COLUMN);
    memset(
        g_mmi_java_ui_clndr_cntx->VerticalList[0],
        0,
        MMI_JAVA_UI_CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * MMI_JAVA_UI_CLNDR_ROW);
    memset(
        g_mmi_java_ui_clndr_cntx->CalendarCell,
        0,
        g_mmi_java_ui_clndr_cntx->RowNumber * MMI_JAVA_UI_CLNDR_COLUMN * MMI_JAVA_UI_CLNDR_CELL_SIZE);

    mmi_java_ui_clndr_get_screenInfo();

////    wgui_calendar_set_horizontal_string(g_mmi_java_ui_clndr_cntx->HorizonList, 0xFF);

    //highlightCell = g_mmi_java_ui_clndr_cntx->DayOnFirst + g_mmi_java_ui_clndr_cntx->CalTime.nDay - 1;

    GetDateTime(&myTime);
    /*if (myTime.nMonth == g_mmi_java_ui_clndr_cntx->CalTime.nMonth &&
        myTime.nYear == g_mmi_java_ui_clndr_cntx->CalTime.nYear)
    {
        currCell = g_mmi_java_ui_clndr_cntx->DayOnFirst + myTime.nDay - 1;
    }*/

	
	mmi_java_ui_clndr_monthly_set_content();
	
    wgui_cat83_register_highlight_change_callback(mmi_java_ui_clndr_highlight_change_handler);

	
    memset(&min_time, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));
    memset(&highlight_time, 0, sizeof(applib_time_struct));
    min_time.nYear = MMI_JAVA_UI_CLNDR_START_YEAR;
    min_time.nMonth = 1;
    min_time.nDay = 1;
    max_time.nYear = MMI_JAVA_UI_CLNDR_END_YEAR;
    max_time.nMonth = 12;
    max_time.nDay = 31;
    highlight_time.nYear = g_mmi_java_ui_clndr_cntx->CalTime.nYear;
    highlight_time.nMonth = g_mmi_java_ui_clndr_cntx->CalTime.nMonth;
    highlight_time.nDay = g_mmi_java_ui_clndr_cntx->CalTime.nDay;
	
#if !defined(__OP01__) || !defined(__MMI_CALENDAR__)	
    ShowCategory83Screen(
        0,
        GUI_CALENDAR_TYPE_MONTH,
        max_time,
        min_time,
        highlight_time,//g_clndr_cntx->CalTime,
        KAL_TRUE,
        (U8*)GetString(STR_GLOBAL_OK),
        (U8*)GetString(STR_GLOBAL_CANCEL),
        NULL,
        0); 
#else
    ShowCategory83Screen(
        IMG_CALENDAR_JAN,
        GUI_CALENDAR_TYPE_MONTH,
        max_time,
        min_time,
        highlight_time,//g_clndr_cntx->CalTime,
        KAL_TRUE,
        (U8*)GetString(STR_GLOBAL_OK),
        (U8*)GetString(STR_GLOBAL_CANCEL),
        NULL,
        0);
#endif
#ifdef __MMI_TOUCH_SCREEN__
        wgui_cat83_register_highlight_select_callback(mmi_java_ui_clndr_highlight_select_handler);
#endif 

    SetLeftSoftkeyFunction(mmi_java_ui_clndr_done_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_ui_clndr_cancel_handler, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmi_java_ui_clndr_done_handler, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
 *  mmi_java_ui_clndr_highlight_select_handler
 * DESCRIPTION
 *  Calendar highlighted cell select handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_highlight_select_handler(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_ui_clndr_done_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_highlight_change_handler
 * DESCRIPTION
 *  Calendar highlighted cell change handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_java_ui_clndr_highlight_change_handler(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time,
             applib_time_struct start_time,
             applib_time_struct end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME myTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlighted_time.nYear == g_mmi_java_ui_clndr_cntx->CalTime.nYear &&
        highlighted_time.nMonth == g_mmi_java_ui_clndr_cntx->CalTime.nMonth)
    {
        g_mmi_java_ui_clndr_cntx->CalTime.nDay = highlighted_time.nDay;
        g_mmi_java_ui_clndr_cntx->CalTime.DayIndex = DOW(g_mmi_java_ui_clndr_cntx->CalTime.nYear, g_mmi_java_ui_clndr_cntx->CalTime.nMonth, g_mmi_java_ui_clndr_cntx->CalTime.nDay);
        return MMI_TRUE;
    }
    else
    {
        memset(&myTime, 0, sizeof(MYTIME));
        myTime.nYear = highlighted_time.nYear;
        myTime.nMonth = highlighted_time.nMonth;
        myTime.nDay = highlighted_time.nDay;
        return mmi_java_ui_clndr_monthly_out_of_boundary(&myTime);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_done_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_done_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_clndr_cntx->callback != NULL)
    {
        g_mmi_java_ui_clndr_cntx->callback(
                                    KAL_TRUE,
                                    (kal_int32) g_mmi_java_ui_clndr_cntx->CalTime.nYear,
                                    (kal_int32) (g_mmi_java_ui_clndr_cntx->CalTime.nMonth - 1),
                                    (kal_int32) g_mmi_java_ui_clndr_cntx->CalTime.nDay,
                                    (kal_int32) g_mmi_java_ui_clndr_cntx->vm_id);
    }
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_cancel_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_cancel_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_clndr_cntx->callback != NULL)
    {
        g_mmi_java_ui_clndr_cntx->callback(
                                    KAL_FALSE,
                                    (kal_int32) g_mmi_java_ui_clndr_cntx->CalTime.nYear,
                                    (kal_int32) (g_mmi_java_ui_clndr_cntx->CalTime.nMonth - 1),
                                    (kal_int32) g_mmi_java_ui_clndr_cntx->CalTime.nDay,
                                    (kal_int32) g_mmi_java_ui_clndr_cntx->vm_id);
    }

    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_get_date_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  date        [?]     [?]     [?]     [?]
 *  dateStr     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_get_date_str(MYTIME *date, U8 *dateStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_str[MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE];
    S8 unicode_str[MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&ascii_str, 0, MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE);
    memset(&unicode_str, 0, MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE * ENCODING_LENGTH);

    /* year */
    sprintf(ascii_str, "%d", date->nYear);
    mmi_asc_to_ucs2(unicode_str, ascii_str);
    mmi_ucs2ncpy((S8*) dateStr, unicode_str, MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE);
    mmi_ucs2cat((S8*) dateStr, (PS8) L"/");

    /* month */
    if (date->nMonth < 10)
    {
        mmi_ucs2cat((S8*) dateStr, (PS8) L"0");
    }
    sprintf(ascii_str, "%d", date->nMonth);
    mmi_asc_to_ucs2(unicode_str, ascii_str);
    mmi_ucs2ncat((S8*) dateStr, unicode_str, MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE);
    mmi_ucs2cat((S8*) dateStr, (PS8) L"/");

    /* day */
    if (date->nDay < 10)
    {
        mmi_ucs2cat((S8*) dateStr, (PS8) L"0");
    }
    sprintf(ascii_str, "%d", date->nDay);
    mmi_asc_to_ucs2(unicode_str, ascii_str);
    mmi_ucs2ncat((S8*) dateStr, unicode_str, MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_get_weekday
 * DESCRIPTION
 *  
 * PARAMETERS
 *  weekdayStr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_get_weekday(U8 **weekdayStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_JAVA_UI_CLNDR_START_WEEKDAY; i < MMI_JAVA_UI_CLNDR_TOTAL_WEEKDAY; i++)
    {
        mmi_asc_n_to_ucs2((S8*) weekdayStr[i], (S8*) & mmi_java_ui_clndr_weekday[i], 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_get_week_numbers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 *  month       [IN]        
 *  weekStr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_get_week_numbers(U16 year, U8 month, U8 **weekStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME dt;
    U8 week, i;
    S8 asciiStr[MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN],
        unicodeStr[MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&dt, 0, sizeof(MYTIME));
    memset(&asciiStr, 0, MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN);
    memset(&unicodeStr, 0, MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH);

    dt.nYear = year;
    dt.nMonth = month;
    dt.nDay = 1;

    /* get the week number of first day of the month */
    week = applib_dt_get_week_number((applib_time_struct*) & dt);

    for (i = 0; i < MMI_JAVA_UI_CLNDR_ROW; i++, week++)
    {
        sprintf(asciiStr, "%d", week);

        /* assert if the string of week number is longer than  */
        ASSERT(strlen(asciiStr) < MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN - MMI_JAVA_UI_CLNDR_WEEK_SYMBOL_LEN);

        mmi_asc_to_ucs2(unicodeStr, asciiStr);
    #ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
        mmi_ucs2ncpy(
            (S8*) weekStr[i],
            GetString((U16) /* STR_GLSTR_CLNDR_WEEK_SYMBOL */ 0),
            MMI_JAVA_UI_CLNDR_WEEK_SYMBOL_LEN);
        mmi_ucs2ncat((S8*) weekStr[i], unicodeStr, strlen(asciiStr));
    #else /* __MMI_CLNDR_SMALL_SIZE_SCREEN__ */ 
        mmi_ucs2ncpy((S8*) weekStr[i], unicodeStr, strlen(asciiStr));
    #endif /* __MMI_CLNDR_SMALL_SIZE_SCREEN__ */ 

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_util_num_to_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 *  str     [?]         [?]         [?]         [?]
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii[CLNDR_TITLE_LEN];
    U16 value = (U16) num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ascii, 0, CLNDR_TITLE_LEN);
    sprintf(ascii, "%d", value);

    /* ASSERT(strlen(ascii) < len); */

    mmi_asc_to_ucs2((S8*) str, ascii);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_construct_monthly_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_construct_monthly_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, /*taskPos,*/nextMonthBoundary;
    gui_calendar_cell_struct *cell;
    MYTIME preMonth, incTime, currTime;
    U8 lastDayofPreMonth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&preMonth, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&currTime, 0, sizeof(MYTIME));

    incTime.nMonth = 1;
    applib_dt_decrease_time(
        (applib_time_struct*) & (g_mmi_java_ui_clndr_cntx->CalTime),
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & preMonth);
    lastDayofPreMonth = applib_dt_last_day_of_mon(preMonth.nMonth, preMonth.nYear);

    cell = g_mmi_java_ui_clndr_cntx->CalendarCell + (g_mmi_java_ui_clndr_cntx->DayOnFirst);

    /* last month */
    for (i = g_mmi_java_ui_clndr_cntx->DayOnFirst - 1; i >= 0; i--)
    {
        cell--;
        ////mmi_java_ui_clndr_util_num_to_unicode(lastDayofPreMonth, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->flags = GUI_CALENDAR_CELL_INVALID;
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        lastDayofPreMonth--;
    }

    /* this month */
    //taskPos = 1;

    cell = g_mmi_java_ui_clndr_cntx->CalendarCell + g_mmi_java_ui_clndr_cntx->DayOnFirst;

    for (i = 1; i <= g_mmi_java_ui_clndr_cntx->NumDaysInMonth; i++)
    {
        ////mmi_java_ui_clndr_util_num_to_unicode(i, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->bg_index = cell->bg_index = GUI_CALENDAR_COLOR_NONE;

        cell->flags = GUI_CALENDAR_CELL_VALID;
        cell++;
    }

    /* next month */
    nextMonthBoundary =
        MMI_JAVA_UI_CLNDR_ROW * MMI_JAVA_UI_CLNDR_COLUMN - (g_mmi_java_ui_clndr_cntx->DayOnFirst +
                                                            g_mmi_java_ui_clndr_cntx->NumDaysInMonth);
    for (i = 1; i <= nextMonthBoundary; i++)
    {
        ////mmi_java_ui_clndr_util_num_to_unicode(i, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        cell->flags = GUI_CALENDAR_CELL_INVALID;
        cell++;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_get_screenInfo
 * DESCRIPTION
 *  Get screen display information of.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_clndr_get_screenInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the DOW 1st of todays month */
    g_mmi_java_ui_clndr_cntx->DayOnFirst = DOW(g_mmi_java_ui_clndr_cntx->CalTime.nYear, g_mmi_java_ui_clndr_cntx->CalTime.nMonth, 1);

    /* get the num of days in todays month */
    g_mmi_java_ui_clndr_cntx->NumDaysInMonth = LastDayOfMonth(g_mmi_java_ui_clndr_cntx->CalTime.nMonth, g_mmi_java_ui_clndr_cntx->CalTime.nYear);

    mmi_java_ui_clndr_get_date_str(&(g_mmi_java_ui_clndr_cntx->CalTime), g_mmi_java_ui_clndr_cntx->Title);

    mmi_java_ui_clndr_get_weekday(g_mmi_java_ui_clndr_cntx->HorizonList);
    mmi_java_ui_clndr_get_week_numbers(
        g_mmi_java_ui_clndr_cntx->CalTime.nYear,
        g_mmi_java_ui_clndr_cntx->CalTime.nMonth,
        g_mmi_java_ui_clndr_cntx->VerticalList);
    mmi_java_ui_clndr_construct_monthly_cell_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_monthly_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_clndr_monthly_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resultDate      [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_java_ui_clndr_monthly_out_of_boundary(MYTIME *resultDate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*MYTIME currTime;
    U32 highlightDays, highlightX, highlightY;
    S32 currCell = -1;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (resultDate->nYear > MMI_JAVA_UI_CLNDR_END_YEAR || resultDate->nYear < MMI_JAVA_UI_CLNDR_START_YEAR)
    {
        return MMI_FALSE;
    }

    g_mmi_java_ui_clndr_cntx->DayOnFirst = DOW(resultDate->nYear, resultDate->nMonth, 1);

    /* set highlight and current date */
    /* subtract 1 to compute the correct highlight position */
    /*highlightDays = g_mmi_java_ui_clndr_cntx->DayOnFirst + resultDate->nDay - 1;
    highlightX = highlightDays % MMI_JAVA_UI_CLNDR_TOTAL_WEEKDAY;
    highlightY = highlightDays / MMI_JAVA_UI_CLNDR_TOTAL_WEEKDAY;*/
    ////wgui_calendar_set_highlight(highlightY, highlightX);

    /* move to next/previous month */
    if (g_mmi_java_ui_clndr_cntx->CalTime.nMonth != resultDate->nMonth ||
        g_mmi_java_ui_clndr_cntx->CalTime.nYear != resultDate->nYear)
    {
        memcpy(&g_mmi_java_ui_clndr_cntx->CalTime, resultDate, sizeof(MYTIME));

        /* get calendar information */
        /* memset(g_mmi_java_ui_clndr_cntx->TaskDayList, 0, MMI_JAVA_UI_CLNDR_COLUMN * MMI_JAVA_UI_CLNDR_ROW * sizeof(clndr_task_icon_struct)); */
        g_mmi_java_ui_clndr_cntx->NumDaysInMonth = LastDayOfMonth(g_mmi_java_ui_clndr_cntx->CalTime.nMonth, g_mmi_java_ui_clndr_cntx->CalTime.nYear);

        mmi_java_ui_clndr_get_date_str(&(g_mmi_java_ui_clndr_cntx->CalTime), g_mmi_java_ui_clndr_cntx->Title);
        mmi_java_ui_clndr_get_weekday(g_mmi_java_ui_clndr_cntx->HorizonList);
        mmi_java_ui_clndr_get_week_numbers(
            g_mmi_java_ui_clndr_cntx->CalTime.nYear,
            g_mmi_java_ui_clndr_cntx->CalTime.nMonth,
            g_mmi_java_ui_clndr_cntx->VerticalList);

        /* Set current date */
        /*GetDateTime(&currTime);
        if (currTime.nMonth == g_mmi_java_ui_clndr_cntx->CalTime.nMonth &&
            currTime.nYear == g_mmi_java_ui_clndr_cntx->CalTime.nYear)
        {
            currCell = g_mmi_java_ui_clndr_cntx->DayOnFirst + currTime.nDay - 1;
        }*/
        ////wgui_calendar_set_current(currCell / MMI_JAVA_UI_CLNDR_COLUMN, currCell % MMI_JAVA_UI_CLNDR_COLUMN);

        /* construct cell info */
        memset(
            g_mmi_java_ui_clndr_cntx->CalendarCell,
            0,
            g_mmi_java_ui_clndr_cntx->RowNumber * MMI_JAVA_UI_CLNDR_COLUMN * MMI_JAVA_UI_CLNDR_CELL_SIZE);
        mmi_java_ui_clndr_construct_monthly_cell_info();

        mmi_java_ui_clndr_monthly_set_content();
        /* ClndrGetScreenInfo(); */
        return MMI_TRUE;
    }
    else
    {
        /* return MMI_FALSE; */
        return MMI_TRUE;
    }
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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_TOUCH_SCREEN__ */ 
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
 *  mmi_java_ui_clndr_monthly_set_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_clndr_monthly_set_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_java_ui_clndr_cntx->horizon_select1, 0, MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN);
    memset(g_mmi_java_ui_clndr_cntx->horizon_select2, 0, MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN);

    mmi_java_ui_clndr_util_num_to_unicode(
        g_mmi_java_ui_clndr_cntx->CalTime.nYear,
        g_mmi_java_ui_clndr_cntx->horizon_select1,
        MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN);
    mmi_java_ui_clndr_util_num_to_unicode(
        g_mmi_java_ui_clndr_cntx->CalTime.nMonth,
        g_mmi_java_ui_clndr_cntx->horizon_select2,
        MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN);
 
#if 0
/* under construction !*/
#if defined (__MMI_CALENDAR__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR__ */
/* under construction !*/
#if defined (__MMI_CALENDAR__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_CALENDAR__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR__ */
/* under construction !*/
#if defined (__MMI_CALENDAR__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */

}

#endif /* __J2ME__ */ 

