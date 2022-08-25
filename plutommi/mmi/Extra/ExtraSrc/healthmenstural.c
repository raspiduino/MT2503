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
 * HalethMenstrual.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Menstrual application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_MENSTRUAL__
#include "healthmenstural.h"
#include "mmi_rp_app_health_def.h"
#include "InlineCuiGprot.h"
#ifdef __MMI_CALENDAR__
#include "app_datetime.h"
#include "CalendarGprot.h"
#endif 
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "gui_typedef.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_rp_app_healthmenstrual_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "DateTimeType.h"
#include "gui_inputs.h"
#include "wgui_datetime.h"
#include "ImeGprot.h"
#include "wgui_categories_util.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "stdlib.h"
#include "AlarmDef.h"
#include "stdio.h"
#include "wgui_categories_calendar.h"
#include "gui_theme_struct.h"
#include "wgui_categories.h"
#include "gui_calendar.h"
/* 
 * Define
 */

/* Inline CUI Revise */
#define MENS_CAPTION_ID0              	CUI_INLINE_ITEM_ID_BASE + 0
#define MENS_DATE_ID1      				CUI_INLINE_ITEM_ID_BASE + 1
#define MENS_CAPTION_ID2       			CUI_INLINE_ITEM_ID_BASE + 2
#define MENS_TEXT_EDIT_ID3      		CUI_INLINE_ITEM_ID_BASE + 3
#define MENS_CAPTION_ID4       			CUI_INLINE_ITEM_ID_BASE + 4


#define  MENS_ZERO_PROB_PERIOD      3
#define  MENS_OVULATION_DAYS        2
#define  MENS_PERIOD             5

#define  MENS_DAY_LEN         3*ENCODING_LENGTH
#define  MENS_MON_LEN         3*ENCODING_LENGTH
#define  MENS_YEAR_LEN        5*ENCODING_LENGTH
#define  MENS_PERIOD_LEN         3*ENCODING_LENGTH
#define  MENS_TITLE_LEN       9*ENCODING_LENGTH
#define  MENS_HORIZON_SEL_LEN       7*ENCODING_LENGTH /* "Menses" */

#define  MENS_MAX_PERIOD         93
#define  MENS_MIN_PERIOD         14
#define  MENS_NUM_PREV_MON    3 /* maximal prediction month */
#define  MENS_MAX_NAVI_MON    6 /* maximal navigation month */

/* 
 * Typedef 
 */
typedef struct
{
    MYTIME InputDate;
    CHAR DayBuf[MENS_DAY_LEN];
    CHAR MonBuf[MENS_MON_LEN];
    CHAR YearBuf[MENS_YEAR_LEN];
    CHAR PeriodBuf[MENS_PERIOD_LEN];
    CHAR TitleString[MENS_TITLE_LEN];
    U16 CurrYear;
    U8 CurrMonth;
    U8 CurrDay;
    U8 NumOfMon;
    U8 AvgPeriod;
    U8 IsAddToHistory;
    U8 DayOnFirst;
    U8 DayOfMon;
    S32 CurHilightItem; 
#ifdef __MMI_CALENDAR__
    MYTIME MensTime;
    U8 *Title;
    U8 *HorizonList[CLNDR_COLUMN];
    U8 *VerticalList[CLNDR_ROW];
    gui_calendar_cell_struct *MenstrulCell;
    /* U8 RowNumber; */
    U8 horizon_select1[MENS_HORIZON_SEL_LEN];
    U8 horizon_select2[MENS_HORIZON_SEL_LEN];
#endif /* __MMI_CALENDAR__ */ 
} mens_context_struct;

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
static void mmi_mens_deinit(void);
static mmi_ret mmi_mens_cui_event_proc(mmi_event_struct *evt);
static void mmi_mens_date_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year);
static void mmi_mens_entry_welcome_screen(void);
static void mmi_mens_pre_entry_input_screen(void);
static void mmi_mens_entry_input_screen(void);
static mmi_ret mmi_mens_input_scrn_leave_proc(mmi_event_struct *evt);
static void mmi_mens_fill_inline_struct(void);
static void mmi_mens_inline_highlight_hdlr(S32 item_index);
static void mmi_mens_exit_input_screen(void);

static void mmi_mens_display_result(void);
static U8 mmi_mens_validate_input(void);
static void mmi_mens_pre_entry_result(void);
static void mmi_mens_entry_result(void);
static void mmi_mens_exit_result(void);
static MMI_BOOL mmi_mens_go_to_previous_day(void);
static MMI_BOOL mmi_mens_go_to_next_day(void);
static MMI_BOOL mmi_mens_go_to_previous_week(void);
static MMI_BOOL mmi_mens_go_to_next_week(void);
static MMI_BOOL mmi_mens_go_to_previous_month(void);
static MMI_BOOL mmi_mens_go_to_next_month(void);
static void mmi_mens_display_boundary_popup(void);
static S16 mmi_mens_get_days_difference(MYTIME *t1, MYTIME *t2);
static S32 mmi_mens_calc_probability(void);

static void mmi_mens_entry_probility(void);

static FLOAT mmi_mens_get_pregancy_prob(S16 DiffDay, S16 AvgPeriod);
static MENS_COLOR_EMUM mmi_mens_get_display_color(S16 DiffDay, U8 AvgPeriod);

#ifdef __MMI_CALENDAR__
static void mmi_mens_construct_cell_info(void);
static MMI_BOOL mmi_mens_highlight(U32 row, U32 column);
static MMI_BOOL mmi_mens_left_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmi_mens_right_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmi_mens_up_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmi_mens_down_out_of_boundary(U32 row, U32 column);    
static MMI_BOOL mmi_mens_up_side_key(U32 row, U32 column);
static MMI_BOOL mmi_mens_down_side_key(U32 row, U32 column);
#endif /*__MMI_CALENDAR__*/

/* 
 * Global Variable
 */
mens_context_struct *g_mens_cntx = NULL;
U8 isbackfromresult;

/* 
 * Global Function
 */

#define MENS_INITIALIZE

/*****************************************************************************
 * FUNCTION
 *  mmi_mens_cell_data_constructor
 * DESCRIPTION
 *  This API construct cell data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_mens_cell_data_constructor(
            gui_calendar_type_enum type,
            applib_time_struct start_time,
            applib_time_struct end_time,
            applib_time_struct interval,
            S32 query_count,
            gui_calendar_cell_struct *cells)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < query_count; i++)
    {
        cells[i].bg_index = g_mens_cntx->MenstrulCell[i].bg_index;
        cells[i].icon_id = g_mens_cntx->MenstrulCell[i].icon_id;
        cells[i].flags = g_mens_cntx->MenstrulCell[i].flags;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_highlight_change_handler
 * DESCRIPTION
 *  Healthy highlighted cell change handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_highlight_change_handler(
                 gui_calendar_type_enum type,
                 applib_time_struct highlighted_time,
				 applib_time_struct real_start_time,
                 applib_time_struct real_end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If is in the same month of current month */
    if (highlighted_time.nYear == g_mens_cntx->CurrYear &&
        highlighted_time.nMonth == g_mens_cntx->CurrMonth)
    {
		g_mens_cntx->CurrDay = highlighted_time.nDay;
        return MMI_TRUE;
    }
    else
    {
		S32 time_compare;
		applib_time_struct diff;		
		applib_time_struct temp;
		memset(&temp, 0, sizeof(applib_time_struct));
		memset(&diff, 0, sizeof(applib_time_struct));
		temp.nYear = g_mens_cntx->CurrYear;
		temp.nMonth = g_mens_cntx->CurrMonth;
        temp.nDay = 1;
		time_compare = applib_dt_compare_time(
                           &temp,
                           &highlighted_time,
                           &diff);
        if (DT_TIME_GREATER == time_compare)
        {
            return mmi_mens_go_to_previous_month();
        }
        if (DT_TIME_LESS == time_compare)
        {
            return mmi_mens_go_to_next_month();
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_deinit
 * DESCRIPTION
 *  Free allocated memory for global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx)
    {
    #ifdef __MMI_CALENDAR__
		if (g_mens_cntx->HorizonList[0] != NULL)
		{
			mmi_frm_scrmem_free((void*)g_mens_cntx->HorizonList[0]);
			mmi_frm_scrmem_free((void*)g_mens_cntx->VerticalList[0]);
			mmi_frm_scrmem_free((void*)g_mens_cntx->MenstrulCell);
		}
    #endif /* __MMI_CALENDAR__ */ 
        OslMfree(g_mens_cntx);
        g_mens_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_pre_entry_welcome_screen
 * DESCRIPTION
 *  pre entry function to menstrual welcome screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mens_pre_entry_welcome_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_frm_group_is_present(GRP_ID_MENS))
    {
        mmi_frm_group_close(GRP_ID_MENS);
    }
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MENS, mmi_mens_cui_event_proc, NULL);
    mmi_frm_group_enter(GRP_ID_MENS, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_mens_entry_welcome_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_cui_event_proc
 * DESCRIPTION
 *  proc function for group GRP_ID_MENS.
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_mens_cui_event_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/* Inline cui revise */
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    cui_event_inline_csk_press_struct *inline_csk_press_event;
	cui_event_inline_notify_struct *inline_notify_event;
	cui_inline_item_date_time_struct tmp; 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	switch (evt->evt_id)
	{
		case EVT_ID_CUI_INLINE_SUBMIT:
        {
            
            inline_submit_event = (cui_event_inline_submit_struct*)evt;
			cui_inline_get_value(inline_submit_event->sender_id, MENS_DATE_ID1, &tmp);
			kal_wsprintf((WCHAR*)g_mens_cntx->YearBuf, "%04d", tmp.year);
			kal_wsprintf((WCHAR*)g_mens_cntx->MonBuf, "%02d", tmp.month);
			kal_wsprintf((WCHAR*)g_mens_cntx->DayBuf, "%02d", tmp.day);
			cui_inline_get_value(inline_submit_event->sender_id, MENS_TEXT_EDIT_ID3, g_mens_cntx->PeriodBuf);
			mmi_mens_display_result();
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
            mmi_mens_deinit();
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            inline_csk_press_event = (cui_event_inline_csk_press_struct*)evt;
			cui_inline_get_value(inline_csk_press_event->sender_id, MENS_DATE_ID1, &tmp);
			kal_wsprintf((WCHAR*)g_mens_cntx->YearBuf, "%04d", tmp.year);
			kal_wsprintf((WCHAR*)g_mens_cntx->MonBuf, "%02d", tmp.month);
			kal_wsprintf((WCHAR*)g_mens_cntx->DayBuf, "%02d", tmp.day);
			cui_inline_get_value(inline_csk_press_event->sender_id, MENS_TEXT_EDIT_ID3, g_mens_cntx->PeriodBuf);
			mmi_mens_display_result();
            break;
        }
        
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
			inline_notify_event = (cui_event_inline_notify_struct *)evt;
        	switch (inline_notify_event->event_type)
    		{
				case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
					switch (inline_notify_event->item_id)
					{
						case MENS_DATE_ID1:
							g_mens_cntx->CurHilightItem = 1;
							break;
						case MENS_TEXT_EDIT_ID3:
							g_mens_cntx->CurHilightItem = 3;
							break;
						default:
							break;
					}
					break;
    			default:
					break;
    		}
            break;
        }
        default:
        {
            break;
        }
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_entry_welcome_screen
 * DESCRIPTION
 *  Display welcome screen of mens application.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_entry_welcome_screen(void)
{
#if  !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_frm_scrn_enter(
			GRP_ID_MENS, 
			SCR_ID_MENS_WELCOME, 
			NULL, 
			mmi_mens_entry_welcome_screen, 
			MMI_FRM_FULL_SCRN))
    {
    	return;
	}

	guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MENS, SCR_ID_MENS_WELCOME);

    ShowCategory129Screen(
        (U8*) get_string(STR_SCR_HEALTH_MENSIS_CAPTION),
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_SCR_HEALTH_MENSIS,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_mens_pre_entry_input_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mens_pre_entry_input_screen, KEY_EVENT_UP);
#else /* __MMI_MAINLCD_240X320__ */ 
    mmi_mens_pre_entry_input_screen();
#endif /* __MMI_MAINLCD_240X320__ */ 
}

#define MENS_INPUT_SCREEN


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_date_editor_callback
 * DESCRIPTION
 *  Call back funtion for inline date input.
 * PARAMETERS
 *  DateStr     [?]     
 *  day         [?]     
 *  month       [?]     
 *  year        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_date_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) DateStr, (CHAR*) year);
    mmi_ucs2cat((CHAR*) DateStr, (CHAR*) L"/");
    mmi_ucs2cat((CHAR*) DateStr, (CHAR*) month);
    mmi_ucs2cat((CHAR*) DateStr, (CHAR*) L"/");
    mmi_ucs2cat((CHAR*) DateStr, (CHAR*) day);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_pre_entry_input_screen
 * DESCRIPTION
 *  Initialize variables for input screen and then go to input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_pre_entry_input_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx == NULL)
    {
        g_mens_cntx = OslMalloc(sizeof(mens_context_struct));
    }

    memset(g_mens_cntx, 0, sizeof(mens_context_struct));

    GetDateTime(&currTime);

	kal_wsprintf((WCHAR*)g_mens_cntx->YearBuf, "%04d", currTime.nYear);
	kal_wsprintf((WCHAR*)g_mens_cntx->MonBuf, "%02d", currTime.nMonth);
	kal_wsprintf((WCHAR*)g_mens_cntx->DayBuf, "%02d", currTime.nDay);


    mmi_mens_entry_input_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_entry_input_screen
 * DESCRIPTION
 *  Display screen to input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_entry_input_screen(void)
{
#if !defined(__MMI_MAINLCD_240X320__) || defined(__MMI_FTE_SUPPORT__)
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    cui_inline_item_softkey_struct softkey_struct = 
		{
			{{STR_GLOBAL_OK, 0},
			{STR_GLOBAL_BACK, 0},
			{0, IMG_GLOBAL_COMMON_CSK}}
		};
	
	cui_inline_item_caption_struct caption0;
	cui_inline_item_date_time_struct date1;
	cui_inline_item_caption_struct caption2;
	cui_inline_item_text_edit_struct textedit3;
	cui_inline_item_caption_struct caption4;
	cui_inline_set_item_struct mens_inline_items[MEMS_INLINE_TOTAL];
	cui_inline_struct inline_struct;
	mmi_id  mens_inline_cui_id;
	MYTIME currTime;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/* cui inline struct define */
	set_leading_zero(FALSE);
	caption0.string_id= STR_LAST_DATE;
	
	memset(&date1, 0, sizeof(cui_inline_item_date_time_struct));
	GetDateTime(&currTime);
	date1.year = currTime.nYear;
	date1.month = currTime.nMonth;
	date1.day = currTime.nDay;
	set_inline_date_boundary(2030, 1970, 12, 1);
	
	caption2.string_id= STR_AVERAGE_DAYS_HEALTH_MENSIS;
	
	textedit3.string_id= 0;
	textedit3.default_text_id = 0;
	textedit3.buffer_size = 3;
	textedit3.input_type = IMM_INPUT_TYPE_NUMERIC;
	textedit3.input_extended_type = 0;
	textedit3.required_input_mode_set = NULL;

	caption4.string_id = STR_DATE_FORMAT_HEALTH_MENSIS;

	mens_inline_items[0].item_id = MENS_CAPTION_ID0;
	mens_inline_items[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
	mens_inline_items[0].image_id = 0;
	mens_inline_items[0].item_data = &caption0;
	
	mens_inline_items[1].item_id = MENS_DATE_ID1;
	mens_inline_items[1].item_flag = CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY;
	mens_inline_items[1].image_id = 0;
	mens_inline_items[1].item_data = &date1;
	
	mens_inline_items[2].item_id = MENS_CAPTION_ID2;
	mens_inline_items[2].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
	mens_inline_items[2].image_id = 0;
	mens_inline_items[2].item_data = &caption2;
	
	mens_inline_items[3].item_id = MENS_TEXT_EDIT_ID3;
	mens_inline_items[3].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_NO_LEADING_ZERO;
	mens_inline_items[3].image_id = 0;
	mens_inline_items[3].item_data = &textedit3;
	
	mens_inline_items[4].item_id = MENS_CAPTION_ID4;
	mens_inline_items[4].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
	mens_inline_items[4].image_id = 0;
	mens_inline_items[4].item_data = &caption4;

	inline_struct.items_count = 5;
	inline_struct.title = STR_HEALTH_MENSIS_DATE_CAPTION;
	inline_struct.title_icon = GetRootTitleIcon(EXTRA_HEALTH_MENU);
	inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
	inline_struct.softkey = &softkey_struct;
	//inline_struct.softkey = NULL;
	inline_struct.items = mens_inline_items;
		
	mens_inline_cui_id = cui_inline_create(
							GRP_ID_MENS,
							&inline_struct);
	cui_inline_run(mens_inline_cui_id);

#else /* __MMI_MAINLCD_240X320__ */ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    WCHAR *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
		GRP_ID_MENS,
		SCR_ID_MENS_INPUT, 
		mmi_mens_exit_input_screen, 
		mmi_mens_entry_input_screen, 
		MMI_FRM_FULL_SCRN))
	{
    	return;
	}
	mmi_frm_scrn_set_leave_proc(GRP_ID_MENS, SCR_ID_MENS_INPUT, mmi_mens_input_scrn_leave_proc);
    InitializeCategory57Screen();
	guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MENS, SCR_ID_MENS_INPUT);

    mmi_mens_fill_inline_struct();

    RegisterHighlightHandler(mmi_mens_inline_highlight_hdlr);
	inputBuffer = mmi_frm_scrn_get_active_input_buf();

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, MEMS_INLINE_TOTAL, (U8*)inputBuffer);   /* sets the data */
    }

    DisableCategory57ScreenDone();
    if (isbackfromresult == 1)
    {
        guiBuffer = NULL;
        isbackfromresult = 0;
    }

    ShowCategory357Screen(
        STR_HEALTH_MENSIS_DATE_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_SCR_HEALTH_MENSIS,
        MEMS_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        g_mens_cntx->CurHilightItem,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_mens_display_result, mmi_frm_scrn_close_active_id);
#endif /* __MMI_MAINLCD_240X320__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_input_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_mens_input_scrn_leave_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* screen group revise */
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            if (mmi_frm_scrn_get_active_id() == SCR_ID_MENS_INPUT)
		    {
		        CloseCategory57Screen();
		    }
		    mmi_mens_deinit();
            break;
            
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_fill_inline_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    set_leading_zero(FALSE);
    SetInlineItemActivation(&wgui_inline_items[MENS_INLINE_DATE_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MENS_INLINE_DATE_CAP], (U8*) GetString(STR_LAST_DATE));

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_DATE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDate(
        &wgui_inline_items[MEMS_INLINE_DATE],
        (U8*) g_mens_cntx->DayBuf,
        (U8*) g_mens_cntx->MonBuf,
        (U8*) g_mens_cntx->YearBuf,
        mmi_mens_date_editor_callback);

    SetInlineItemFullWidth(&wgui_inline_items[MEMS_INLINE_DATE]);
    RightJustifyInlineItem(&wgui_inline_items[MEMS_INLINE_DATE]);
    EnableInlineItemBoundary(&wgui_inline_items[MEMS_INLINE_DATE]);
    set_inline_date_boundary(2030, 1970, 12, 1);

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_PERIOD_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MEMS_INLINE_PERIOD_CAP], (U8*) GetString(STR_AVERAGE_DAYS_HEALTH_MENSIS));

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_PERIOD], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[MEMS_INLINE_PERIOD], (U8*) g_mens_cntx->PeriodBuf, 3, IMM_INPUT_TYPE_NUMERIC);

    RightJustifyInlineItem(&wgui_inline_items[MEMS_INLINE_PERIOD]);
    EnableInlineItemBoundary(&wgui_inline_items[MEMS_INLINE_PERIOD]);

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_NUM_DAYS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MEMS_INLINE_NUM_DAYS], (U8*) GetString(STR_DATE_FORMAT_HEALTH_MENSIS));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_inline_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline item in input screen.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mens_inline_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_mens_display_result, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_mens_display_result, KEY_EVENT_UP);
    g_mens_cntx->CurHilightItem = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_exit_input_screen
 * DESCRIPTION
 *  Exit function of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_exit_input_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
}

#define MENS_RESULT_SCREEN


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_display_result
 * DESCRIPTION
 *  Display corresponding screen according to computation result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mens_display_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    error = mmi_mens_validate_input();

    switch (error)
    {
        case MENS_ERR_DATE:
            //mmi_display_popup_with_sg(GRP_ID_MENS, (UI_string_type)GetString(STR_HEALTH_WRONG_DATE_MSG), MMI_EVENT_ERROR, 0);
            mmi_popup_display_simple((UI_string_type)GetString(STR_HEALTH_WRONG_DATE_MSG), MMI_EVENT_ERROR, GRP_ID_MENS, NULL);
            break;
        case MENS_ERR_PERIOD:
            //mmi_display_popup_with_sg(GRP_ID_MENS, (UI_string_type)GetString(STR_INVALID_AVERAGE_DAY_MESSAGE), MMI_EVENT_ERROR, 0);
            mmi_popup_display_simple((UI_string_type)GetString(STR_INVALID_AVERAGE_DAY_MESSAGE), MMI_EVENT_ERROR, GRP_ID_MENS, NULL);
            break;
        default:    /* correct */
            mmi_mens_pre_entry_result();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_validate_input
 * DESCRIPTION
 *  Validate the correctness of user input.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_mens_validate_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR tmpMon[MENS_MON_LEN];
    CHAR tmpDay[MENS_DAY_LEN];
    CHAR tmpYear[MENS_YEAR_LEN];
    CHAR AvgDays[MENS_PERIOD_LEN];
    MYTIME currTime, incTime, finalTime;
    U8 tmpPeriod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* validate period */
    mmi_ucs2_to_asc(AvgDays, g_mens_cntx->PeriodBuf);
    g_mens_cntx->AvgPeriod = tmpPeriod = (U8) atoi(AvgDays);
    if (tmpPeriod < MENS_MIN_PERIOD || tmpPeriod > MENS_MAX_PERIOD)
    {
        return MENS_ERR_PERIOD;
    }

    /* validate day */
    mmi_ucs2_to_asc(tmpDay, g_mens_cntx->DayBuf);
    mmi_ucs2_to_asc(tmpMon, g_mens_cntx->MonBuf);
    mmi_ucs2_to_asc(tmpYear, g_mens_cntx->YearBuf);

    memset(&g_mens_cntx->InputDate, 0, sizeof(MYTIME));
    g_mens_cntx->InputDate.nDay = atoi(tmpDay);
    g_mens_cntx->InputDate.nMonth = atoi(tmpMon);
    g_mens_cntx->InputDate.nYear = atoi(tmpYear);

    /* daty out of boundary */
    g_mens_cntx->DayOfMon = LastDayOfMonth(g_mens_cntx->InputDate.nMonth, g_mens_cntx->InputDate.nYear);
    if (g_mens_cntx->InputDate.nDay > g_mens_cntx->DayOfMon)
    {
        return MENS_ERR_DATE;
    }

    /* date too large */
    GetDateTime(&currTime);
    if (CompareTime(currTime, g_mens_cntx->InputDate, NULL) == TIME_LESS)
    {
        return MENS_ERR_DATE;
    }

    /* date too small */
    memset(&incTime, 0, sizeof(MYTIME));
    incTime.nMonth = MENS_NUM_PREV_MON;
    DecrementTime(currTime, incTime, &finalTime);
    if (CompareTime(g_mens_cntx->InputDate, finalTime, NULL) == TIME_LESS)
    {
        return MENS_ERR_DATE;
    }

    return MENS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_pre_entry_result
 * DESCRIPTION
 *  Initialize variables and go to result screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_pre_entry_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&currTime);

    g_mens_cntx->NumOfMon = 0;
    g_mens_cntx->CurrMonth = currTime.nMonth;
    g_mens_cntx->CurrYear = currTime.nYear;
    g_mens_cntx->CurrDay = currTime.nDay;

    mmi_mens_entry_result();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_exit_result
 * DESCRIPTION
 *  Exit function of calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_exit_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR__
    /* Deinit has not been executed */
    if (g_mens_cntx != NULL)
    {
        mmi_frm_scrmem_free((void*)g_mens_cntx->HorizonList[0]);
        mmi_frm_scrmem_free((void*)g_mens_cntx->VerticalList[0]);
        mmi_frm_scrmem_free((void*)g_mens_cntx->MenstrulCell);

        g_mens_cntx->HorizonList[0] = NULL;
        g_mens_cntx->VerticalList[0] = NULL;
        g_mens_cntx->MenstrulCell = NULL;
    }
#endif /* __MMI_CALENDAR__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_entry_result
 * DESCRIPTION
 *  Display result calendar of computation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_entry_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    S32 j;
//	MMI_BOOL test;
#ifdef __MMI_CALENDAR__
    S32 highlightCell;
    U8 *rsk, *lsk;
    applib_time_struct max_time, min_time, current_time, inc; // Add by Helena
#else /* __MMI_CALENDAR__ */ 
    S16 Color[31];
    S16 DiffDays;    
#endif /* __MMI_CALENDAR__ */ 
    CHAR tmpString[MENS_TITLE_LEN];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    isbackfromresult = 1;
	//EntryNewScreen(SCR_ID_MENS_RESULT, mmi_mens_exit_result, NULL, NULL);
    if (!mmi_frm_scrn_enter(
			GRP_ID_MENS,
			SCR_ID_MENS_RESULT,
			mmi_mens_exit_result,
			mmi_mens_entry_result,
			MMI_FRM_FULL_SCRN))
	{
    	return;
	}
    g_mens_cntx->IsAddToHistory = TRUE;

	guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MENS, SCR_ID_MENS_RESULT);
    /* back ground initialize */
    g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
    g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);
#ifdef __MMI_CALENDAR__
    g_mens_cntx->HorizonList[0] =
        (U8*) mmi_frm_scrmem_alloc(CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
    g_mens_cntx->VerticalList[0] =
        (U8*) mmi_frm_scrmem_alloc(CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
    g_mens_cntx->MenstrulCell =
        (gui_calendar_cell_struct*) mmi_frm_scrmem_alloc((CLNDR_ROW * CLNDR_COLUMN) * CLNDR_CELL_SIZE);

    for (j = 1; j < CLNDR_COLUMN; j++)
    {
        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
    }
    for (j = 1; j < CLNDR_ROW; j++)
    {
        g_mens_cntx->VerticalList[j] =
            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
    }

    /* reset memory */
    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

    /* Set Calendar info */
    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

    /* GetDateTime(&currTime); */

    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

    mmi_mens_construct_cell_info();


    highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;



    rsk = (U8*)GetString(STR_GLOBAL_BACK);
    lsk = (U8*)GetString(STR_GLOBAL_OK);

    wgui_cat83_register_cell_data_query_handler(mmi_mens_cell_data_constructor);
    wgui_cat83_register_highlight_change_callback(mmi_mens_highlight_change_handler);
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&min_time, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));
    memset(&current_time, 0, sizeof(applib_time_struct));
    current_time.nYear = (g_mens_cntx->MensTime).nYear;
    current_time.nMonth = (g_mens_cntx->MensTime).nMonth;
    current_time.nDay = 1;
    inc.nMonth = g_mens_cntx->NumOfMon;//MENS_MAX_NAVI_MON;
    applib_dt_decrease_time(
        (applib_time_struct*)&current_time,
        (applib_time_struct*)&inc,
        (applib_time_struct*)&min_time);
	current_time.nDay = (g_mens_cntx->MensTime).nDay;
	inc.nMonth = MENS_MAX_NAVI_MON;
	applib_dt_increase_time(
        (applib_time_struct*)&min_time,
        (applib_time_struct*)&inc,
        (applib_time_struct*)&max_time);
	if (current_time.nYear == 2030 && current_time.nMonth == 12)
	{
	    max_time.nYear = current_time.nYear;
            max_time.nMonth = current_time.nMonth;
	}
	if (max_time.nYear > 2030)
	{
            max_time.nYear = 2030;
            max_time.nMonth = 12;
	}
    max_time.nDay = applib_dt_last_day_of_mon(max_time.nMonth, max_time.nYear);

    wgui_cat83_set_mens_horizontal_select(
        GUI_CALENDAR_COLOR_PP,
        GUI_CALENDAR_COLOR_NONE,
        GetString(STR_CALENDER_MESSAAGE1_PP),
        GUI_CALENDAR_COLOR_MENSTRUAL,
        GUI_CALENDAR_COLOR_NONE,
    #ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
        GetString(STR_CALENDER_MESSAAGE2_MENS)
    #else
        GetString(STR_CALENDER_MESSAAGE2_SHORT_MENS)
    #endif
        );
    ShowCategory83Screen(
        0,
        GUI_CALENDAR_TYPE_MONTH,
        max_time,
        min_time,
        current_time,
        MMI_TRUE,
        lsk,
        rsk,
        NULL,
        0);    
    

#else /* __MMI_CALENDAR__ */ 
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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_CALENDAR__ */ 
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mens_entry_probility, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_mens_entry_probility, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_go_to_previous_day
 * DESCRIPTION
 *  Handle left arrow key when highlighting on 1st day of month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mens_go_to_previous_day(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlightCell, highlightCellX, highlightCellY;
	CHAR tmpString[MENS_TITLE_LEN];
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon > 0)
    {
        MYTIME myTime, incTime, finaltime;

        /* do not have to prevent 1970/01/01 because can not nevigate previous month */
        memset(&myTime, 0, sizeof(MYTIME));
        myTime.nDay = 1;
        myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
        myTime.nYear = (U16) g_mens_cntx->CurrYear;

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nDay = 1;
        DecrementTime(myTime, incTime, &finaltime);

        g_mens_cntx->NumOfMon--;
        g_mens_cntx->CurrYear = finaltime.nYear;
        g_mens_cntx->CurrMonth = finaltime.nMonth;
        g_mens_cntx->CurrDay = finaltime.nDay;
        g_mens_cntx->IsAddToHistory = FALSE;

    //    mmi_mens_entry_result();
    ///////////////////////////////////
        g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
    	g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);

	    for (j = 1; j < CLNDR_COLUMN; j++)
	    {
	        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
	    }
	    for (j = 1; j < CLNDR_ROW; j++)
	    {
	        g_mens_cntx->VerticalList[j] =
	            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
	    }

	    /* reset memory */
	    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
	    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
	    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

	    /* Set Calendar info */
	    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
	    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
	    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

		/* Set highlight cell */
		highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
		highlightCellX = highlightCell % CLNDR_COLUMN;
        highlightCellY = highlightCell / CLNDR_COLUMN;   

	    /* GetDateTime(&currTime); */

	    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
	    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

	    mmi_mens_construct_cell_info();

    	return MMI_TRUE;
    }
    else
    {
        g_mens_cntx->IsAddToHistory = TRUE;
        mmi_mens_display_boundary_popup();
		return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_go_to_next_day
 * DESCRIPTION
 *  Handle right arrow key when highlighting on last day of month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mens_go_to_next_day(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlightCell, highlightCellX, highlightCellY;
	CHAR tmpString[MENS_TITLE_LEN];
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon < MENS_MAX_NAVI_MON)
    {
        if (g_mens_cntx->CurrYear != 2030 || g_mens_cntx->CurrMonth != 12)
        {
            MYTIME myTime, incTime, finaltime;

            memset(&myTime, 0, sizeof(MYTIME));

            myTime.nDay = 1;
            myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
            myTime.nYear = (U16) g_mens_cntx->CurrYear;

            memset(&incTime, 0, sizeof(MYTIME));
            incTime.nMonth = 1;
            IncrementTime(myTime, incTime, &finaltime);

            g_mens_cntx->NumOfMon++;
            g_mens_cntx->CurrYear = finaltime.nYear;
            g_mens_cntx->CurrMonth = finaltime.nMonth;
            g_mens_cntx->CurrDay = finaltime.nDay;
            g_mens_cntx->IsAddToHistory = FALSE;
//            mmi_mens_entry_result();
	///////////////////////////////////
			g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
			g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);
	
			for (j = 1; j < CLNDR_COLUMN; j++)
			{
				g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
			}
			for (j = 1; j < CLNDR_ROW; j++)
			{
				g_mens_cntx->VerticalList[j] =
					g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
			}
	
			/* reset memory */
			memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
			memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
			memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);
	
			/* Set Calendar info */
			g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
			g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
			g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

			/* Set highlight cell */
			highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
			highlightCellX = highlightCell % CLNDR_COLUMN;
	        highlightCellY = highlightCell / CLNDR_COLUMN;   
	
			/* GetDateTime(&currTime); */
	
			sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
			mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

			mmi_mens_construct_cell_info();
	

            return MMI_TRUE;
        }
    }

    g_mens_cntx->IsAddToHistory = TRUE;
    mmi_mens_display_boundary_popup();
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_go_to_previous_week
 * DESCRIPTION
 *  Handle up arrow key when highlighting on first week of the month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mens_go_to_previous_week(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlightCell, highlightCellX, highlightCellY;
    CHAR tmpString[MENS_TITLE_LEN];
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon > 0)
    {
        MYTIME myTime, incTime, finaltime;

        memset(&myTime, 0, sizeof(MYTIME));

        myTime.nDay = (U8) g_mens_cntx->CurrDay;
        myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
        myTime.nYear = (U16) g_mens_cntx->CurrYear;

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nDay = 7;

        DecrementTime(myTime, incTime, &finaltime);

        g_mens_cntx->CurrYear = finaltime.nYear;
        g_mens_cntx->CurrMonth = finaltime.nMonth;
        g_mens_cntx->CurrDay = finaltime.nDay;

        g_mens_cntx->NumOfMon--;
        g_mens_cntx->IsAddToHistory = FALSE;
///////////////////////////////////
        g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
    	g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);

	    for (j = 1; j < CLNDR_COLUMN; j++)
	    {
	        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
	    }
	    for (j = 1; j < CLNDR_ROW; j++)
	    {
	        g_mens_cntx->VerticalList[j] =
	            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
	    }

	    /* reset memory */
	    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
	    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
	    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

	    /* Set Calendar info */
	    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
	    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
	    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

		/* Set highlight cell */
		highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
		highlightCellX = highlightCell % CLNDR_COLUMN;
        highlightCellY = highlightCell / CLNDR_COLUMN;   

	    /* GetDateTime(&currTime); */

	    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
	    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

	    mmi_mens_construct_cell_info();

		return MMI_TRUE;
    }
    else
    {
        g_mens_cntx->IsAddToHistory = TRUE;
        mmi_mens_display_boundary_popup();
		return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_go_to_next_week
 * DESCRIPTION
 *  Handle down arrow key when highlighting on last week of the month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mens_go_to_next_week(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlightCell, highlightCellX, highlightCellY;
	CHAR tmpString[MENS_TITLE_LEN];
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon < MENS_MAX_NAVI_MON)
    {
        if (g_mens_cntx->CurrYear != 2030 || g_mens_cntx->CurrMonth != 12)
        {
            MYTIME myTime, incTime, finaltime;

            memset(&myTime, 0, sizeof(MYTIME));

            myTime.nDay = (U8) g_mens_cntx->CurrDay;
            myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
            myTime.nYear = (U16) g_mens_cntx->CurrYear;

            memset(&incTime, 0, sizeof(MYTIME));
            incTime.nDay = 7;
            IncrementTime(myTime, incTime, &finaltime);

            g_mens_cntx->CurrYear = finaltime.nYear;
            g_mens_cntx->CurrMonth = finaltime.nMonth;
            g_mens_cntx->CurrDay = finaltime.nDay;
            g_mens_cntx->NumOfMon++;
            g_mens_cntx->IsAddToHistory = FALSE;
//            mmi_mens_entry_result();
			///////////////////////////////////
	        g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
	    	g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);

		    for (j = 1; j < CLNDR_COLUMN; j++)
		    {
		        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
		    }
		    for (j = 1; j < CLNDR_ROW; j++)
		    {
		        g_mens_cntx->VerticalList[j] =
		            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
		    }

		    /* reset memory */
		    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
		    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
		    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

		    /* Set Calendar info */
		    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
		    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
		    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

			/* Set highlight cell */
			highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
			highlightCellX = highlightCell % CLNDR_COLUMN;
			highlightCellY = highlightCell / CLNDR_COLUMN;	 

		    /* GetDateTime(&currTime); */

		    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
		    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

		    mmi_mens_construct_cell_info();

            return MMI_TRUE;
        }
    }

    g_mens_cntx->IsAddToHistory = TRUE;
    mmi_mens_display_boundary_popup();
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_go_to_previous_month
 * DESCRIPTION
 *  Side up key handler, go to the first day of previois month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mens_go_to_previous_month(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlightCell, highlightCellX, highlightCellY;
	CHAR tmpString[MENS_TITLE_LEN];
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon > 0)
    {
        MYTIME myTime, incTime, finaltime;

        memset(&myTime, 0, sizeof(MYTIME));

        myTime.nDay = 1;
        myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
        myTime.nYear = (U16) g_mens_cntx->CurrYear;

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nMonth = 1;

        DecrementTime(myTime, incTime, &finaltime);

        g_mens_cntx->CurrYear = finaltime.nYear;
        g_mens_cntx->CurrMonth = finaltime.nMonth;
        g_mens_cntx->CurrDay = finaltime.nDay;
        g_mens_cntx->NumOfMon--;
        g_mens_cntx->IsAddToHistory = FALSE;

//        mmi_mens_entry_result();
		///////////////////////////////////
        g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
    	g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);

	    for (j = 1; j < CLNDR_COLUMN; j++)
	    {
	        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
	    }
	    for (j = 1; j < CLNDR_ROW; j++)
	    {
	        g_mens_cntx->VerticalList[j] =
	            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
	    }

	    /* reset memory */
	    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
	    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
	    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

	    /* Set Calendar info */
	    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
	    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
	    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;
		
		/* Set highlight cell */
		highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
		highlightCellX = highlightCell % CLNDR_COLUMN;
        highlightCellY = highlightCell / CLNDR_COLUMN;   
		
	    /* GetDateTime(&currTime); */

	    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
	    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

	    mmi_mens_construct_cell_info();

		return MMI_TRUE;
    }
    else
    {
        g_mens_cntx->IsAddToHistory = TRUE;
        mmi_mens_display_boundary_popup();
		return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_go_to_next_month
 * DESCRIPTION
 *  Side down key handler, go to the first day of next month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mens_go_to_next_month()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlightCell, highlightCellX, highlightCellY;
	CHAR tmpString[MENS_TITLE_LEN];
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon < MENS_MAX_NAVI_MON)
    {
        if (g_mens_cntx->CurrYear != 2030 || g_mens_cntx->CurrMonth != 12)
        {
            MYTIME myTime, incTime, finaltime;

            memset(&myTime, 0, sizeof(MYTIME));

            myTime.nDay = 1;
            myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
            myTime.nYear = (U16) g_mens_cntx->CurrYear;

            memset(&incTime, 0, sizeof(MYTIME));
            incTime.nMonth = 1;
            IncrementTime(myTime, incTime, &finaltime);

            g_mens_cntx->NumOfMon++;
            g_mens_cntx->CurrYear = finaltime.nYear;
            g_mens_cntx->CurrMonth = finaltime.nMonth;
            g_mens_cntx->CurrDay = finaltime.nDay;
            g_mens_cntx->IsAddToHistory = FALSE;
//            mmi_mens_entry_result();
			///////////////////////////////////
	        g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
	    	g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);

		    for (j = 1; j < CLNDR_COLUMN; j++)
		    {
		        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
		    }
		    for (j = 1; j < CLNDR_ROW; j++)
		    {
		        g_mens_cntx->VerticalList[j] =
		            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
		    }

		    /* reset memory */
		    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
		    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
		    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

		    /* Set Calendar info */
		    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
		    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
		    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

		    
			/* Set highlight cell */
			highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
            highlightCellX = highlightCell % CLNDR_COLUMN;
            highlightCellY = highlightCell / CLNDR_COLUMN;   

			/* GetDateTime(&currTime); */
		    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
		    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

		    mmi_mens_construct_cell_info();

            return MMI_TRUE;
        }
    }

    g_mens_cntx->IsAddToHistory = TRUE;
    mmi_mens_display_boundary_popup();
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_display_boundary_popup
 * DESCRIPTION
 *  Display popup screen for out of boundary.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_display_boundary_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_display_popup_with_sg(GRP_ID_MENS, (UI_string_type)GetString(STR_CANNOT_NAVIGATE_FURTHER_MESSAGE), MMI_EVENT_ERROR, 0);
    mmi_popup_display_simple((UI_string_type)GetString(STR_CANNOT_NAVIGATE_FURTHER_MESSAGE), MMI_EVENT_ERROR, GRP_ID_MENS, NULL);
}

#define MENS_PROBABILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_calc_probability
 * DESCRIPTION
 *  To calculate the probablity of ovulation.
 * PARAMETERS
 *  void
 * RETURNS
 *  probablity value
 *****************************************************************************/
static S32 mmi_mens_calc_probability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FLOAT prob;
    S16 DiffDays;
    MYTIME tmpDate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&tmpDate, 0, sizeof(MYTIME));
    tmpDate.nDay = (U8) g_mens_cntx->CurrDay;
    tmpDate.nMonth = (U8) g_mens_cntx->CurrMonth;
    tmpDate.nYear = (U16) g_mens_cntx->CurrYear;

    DiffDays = mmi_mens_get_days_difference(&tmpDate, &g_mens_cntx->InputDate);
    prob = (mmi_mens_get_pregancy_prob((S16) DiffDays, (S16) g_mens_cntx->AvgPeriod));

    return (S32) (prob * 100);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_entry_probility
 * DESCRIPTION
 *  Display probability screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_entry_probility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    S32 Prob;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_MENS_PROB, NULL, mmi_mens_entry_probility, NULL);
	if (!mmi_frm_scrn_enter(
			GRP_ID_MENS,
			SCR_ID_MENS_PROB,
			NULL, 
			mmi_mens_entry_probility, 
			MMI_FRM_FULL_SCRN))
	{
		return;
	}

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MENS, SCR_ID_MENS_PROB);

    Prob = mmi_mens_calc_probability();

    ShowCategory72Screen(
        STR_SCR_HEALTH_MENSIS_PROBABILITY_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*) GetString(STR_SCR_HEALTH_MENSIS_PROBABILITY_MESSAGE),
        Prob,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

#define MENS_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_get_pregancy_prob
 * DESCRIPTION
 *  This function is to calculate probability of pregnancy.
 * PARAMETERS
 *  DiffDay         [IN]        The number of diffenent dates between given date and menstrual date
 *  AvgPeriod       [IN]        Average perviods
 * RETURNS
 *  FLOAT    the probability of pregnancy
 *****************************************************************************/
static FLOAT mmi_mens_get_pregancy_prob(S16 DiffDay, S16 AvgPeriod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 Nth;    /* the Nth day from menstrual date */
    S16 OD;     /* the estimated ovulated date */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; DiffDay < 0; i++)
    {
        DiffDay += AvgPeriod * i;
    }

    Nth = DiffDay % AvgPeriod;

    OD = AvgPeriod / 2;

    if (Nth < MENS_ZERO_PROB_PERIOD)
    {
        return (FLOAT) 0.01;
    }
    else if (Nth <= (OD + MENS_OVULATION_DAYS) && Nth >= (OD - MENS_OVULATION_DAYS))
    {
        return (FLOAT) 0.99;
    }
    else if (Nth < AvgPeriod / 2)
    {
        return (FLOAT) Nth *2 / AvgPeriod;
    }

    else
    {
        return (2 - (FLOAT) 2 * Nth / (AvgPeriod));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_get_display_color
 * DESCRIPTION
 *  This function is to calculate which color to display of a given date.
 * PARAMETERS
 *  DiffDay         [IN]        The number of diffenent dates between given date and menstrual date
 *  AvgPeriod       [IN]        Average perviods
 * RETURNS
 *  enum MENS_COLOR_EMUM the color to be display
 *****************************************************************************/
static MENS_COLOR_EMUM mmi_mens_get_display_color(S16 DiffDay, U8 AvgPeriod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 Nth;    /* the Nth day from menstrual date */
    S16 OD;     /* the estimated ovulated date */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; DiffDay < 0; i++)
    {
        DiffDay += AvgPeriod * i;
    }

    Nth = DiffDay % AvgPeriod;

    OD = AvgPeriod / 2;

    if (Nth < MENS_PERIOD)
    {
        return RED_COLOR;
    }
    else if (Nth == OD)
    {
        return ORANGE_COLOR;
    }
    else if (Nth <= (OD + MENS_OVULATION_DAYS) && Nth >= (OD - MENS_OVULATION_DAYS))
    {
        return YELLOW_COLOR;
    }
    else
    {
        return COLOR_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_get_days_difference
 * DESCRIPTION
 *  This function is to calculate number difference days between two date.
 * PARAMETERS
 *  t1      [IN]        Date to be computed
 *  t2      [IN]        Date to be computed
 * RETURNS
 *  Difference between t1 and t2 (t1 - t2).
 *****************************************************************************/
static S16 mmi_mens_get_days_difference(MYTIME *t1, MYTIME *t2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Result;
    MYTIME startTime, endTime, incTime;
    U8 SignFlag;

    TIME_EQUALITY eq = CompareTime(*t1, *t2, NULL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    if (eq == TIME_LESS)    /* t1 < t2 */
    {
        startTime = *t1;
        endTime = *t2;
        SignFlag = 0;
    }
    else if (eq == TIME_GREATER)    /* t1 > t2 */
    {
        startTime = *t2;
        endTime = *t1;
        SignFlag = 1;
    }
    else    /* no difference */
    {
        return 0;
    }

    /* day */
    if (endTime.nMonth > startTime.nMonth || endTime.nYear > startTime.nYear)
    {
        Result = endTime.nDay + LastDayOfMonth(startTime.nMonth, startTime.nYear) - startTime.nDay;
        incTime.nMonth = 1;
	        
		/* Increase one month with IncrementTime() may make 3/31 to become 5/1 */
		startTime.nMonth += 1;
		if (startTime.nMonth > NUM_MONTHS)
		{
			startTime.nYear ++;	
			startTime.nMonth = 1;
		}		

        startTime.nDay = 1; /* to prevent day out of boundary */

        /* month */
        while (!(endTime.nMonth == startTime.nMonth && endTime.nYear == startTime.nYear))
        {
            Result += LastDayOfMonth(startTime.nMonth, startTime.nYear);
            IncrementTime(startTime, incTime, &startTime);
        }
    }
    else
    {
        Result = endTime.nDay - startTime.nDay;
    }

    if (SignFlag == 1)
    {
        return Result;
    }
    else
    {
        return Result * (-1);
    }
}

#ifdef __MMI_CALENDAR__


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_construct_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mens_construct_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, nextMonthBoundary;
    gui_calendar_cell_struct *cell;
    MYTIME preMonth, incTime, currTime;
    U8 lastDayofPreMonth;
    S16 DiffDays;
    S16 Color[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&preMonth, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&currTime, 0, sizeof(MYTIME));
    /* GetDateTime(&currTime); */
    currTime.nMonth = (U8) g_mens_cntx->CurrMonth;
    currTime.nYear = (U16) g_mens_cntx->CurrYear;
    currTime.nDay = 1;

    incTime.nMonth = 1;
    applib_dt_decrease_time(
        (applib_time_struct*) & currTime,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & preMonth);
    lastDayofPreMonth = applib_dt_last_day_of_mon(preMonth.nMonth, preMonth.nYear);

    cell = g_mens_cntx->MenstrulCell + (g_mens_cntx->DayOnFirst);

    /* last month */
    for (i = g_mens_cntx->DayOnFirst - 1; i >= 0; i--)
    {
        cell--;
        cell->flags = GUI_CALENDAR_CELL_INVALID;
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        lastDayofPreMonth--;
    }

    /* this month */
    cell = g_mens_cntx->MenstrulCell + g_mens_cntx->DayOnFirst;

    DiffDays = mmi_mens_get_days_difference(&currTime, &g_mens_cntx->InputDate);
    for (i = 1; i <= g_mens_cntx->DayOfMon; i++)
    {
        /* get/set color of days */
        Color[i] = (mmi_mens_get_display_color(DiffDays, g_mens_cntx->AvgPeriod));

        if (Color[i] != COLOR_NONE)
        {
            cell->bg_index = GUI_CALENDAR_COLOR_MENSTRUAL + Color[i] - 1;
        }
        else
        {
            cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        }
        cell->flags = GUI_CALENDAR_CELL_VALID;
        cell++;
        DiffDays++;

    }

    /* next month */
    nextMonthBoundary = CLNDR_ROW * CLNDR_COLUMN - (g_mens_cntx->DayOnFirst + g_mens_cntx->DayOfMon);
    for (i = 1; i <= nextMonthBoundary; i++)
    {
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        cell->flags = GUI_CALENDAR_CELL_INVALID;
        cell++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_highlight(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 totaldays;
    CHAR tmpString[MENS_TITLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totaldays = (row * CLNDR_COLUMN) + column + 1;
    g_mens_cntx->CurrDay = totaldays - g_mens_cntx->DayOnFirst;
    /* g_mens_cntx->CalTime.DayIndex = DOW(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nDay); */

    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_left_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_left_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME nextDate, incTime;
    CHAR tmpString[MENS_TITLE_LEN];
    U32 highlightDays, highlightX, highlightY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&nextDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));

    nextDate.nYear = g_mens_cntx->CurrYear;
    nextDate.nMonth = g_mens_cntx->CurrMonth;
    nextDate.nDay = g_mens_cntx->CurrDay;

    incTime.nDay = 1;

    applib_dt_decrease_time(
        (applib_time_struct*) & nextDate,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & nextDate);

    if (g_mens_cntx->CurrYear == nextDate.nYear && g_mens_cntx->CurrMonth == nextDate.nMonth)
    {
        g_mens_cntx->CurrDay--;
        sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);

        highlightDays = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
        highlightX = highlightDays % CLNDR_TOTAL_WEEKDAY;
        highlightY = highlightDays / CLNDR_TOTAL_WEEKDAY;

        mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);
    }
    else
    {
        return mmi_mens_go_to_previous_day();
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_right_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_right_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME nextDate, incTime;
    CHAR tmpString[MENS_TITLE_LEN];
    U32 highlightDays, highlightX, highlightY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&nextDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));

    nextDate.nYear = g_mens_cntx->CurrYear;
    nextDate.nMonth = g_mens_cntx->CurrMonth;
    nextDate.nDay = g_mens_cntx->CurrDay;

    incTime.nDay = 1;

    applib_dt_increase_time(
        (applib_time_struct*) & nextDate,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & nextDate);

    if (g_mens_cntx->CurrYear == nextDate.nYear && g_mens_cntx->CurrMonth == nextDate.nMonth)
    {
        g_mens_cntx->CurrDay++;
        sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);

        highlightDays = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
        highlightX = highlightDays % CLNDR_TOTAL_WEEKDAY;
        highlightY = highlightDays / CLNDR_TOTAL_WEEKDAY;

        mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);
    }
    else
    {
        return mmi_mens_go_to_next_day();
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_up_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_up_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_mens_go_to_previous_week();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_down_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_down_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_mens_go_to_next_week();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_up_side_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_up_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_mens_go_to_previous_month();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_down_side_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mens_down_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mmi_mens_go_to_next_month();
}




#endif /* __MMI_CALENDAR__ */ 

#endif /* __MMI_MENSTRUAL__ */ // #ifdef __MMI_MENSTRUAL__

