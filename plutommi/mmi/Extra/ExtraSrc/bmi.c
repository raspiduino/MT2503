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
 * Bmi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements BMI application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * Bmi.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements BMI application.
 *
 * Author:
 * -------
 * -------
 *
 *****************************************************************************/
 /*  Include: MMI header file */
#include "MMI_features.h"
#ifdef __MMI_BMI__
#include "MMIDataType.h"
#include "BMI.h"
#include "InlineCuiGprot.h"
#include "mmi_rp_app_health_def.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_app_healthbmi_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "gui_inputs.h"
#include "ImeGprot.h"
#include "wgui_categories_util.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "gui.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
/*  Include: PS header file */

/* 
 * Define
 */
/* Inline CUI Revise */
#define BMI_SELECT_ID0               	CUI_INLINE_ITEM_ID_BASE + 0
#define BMI_CAPTION_ID1              	CUI_INLINE_ITEM_ID_BASE + 1
#define BMI_TEXT_EDIT_ID2      			CUI_INLINE_ITEM_ID_BASE + 2
#define BMI_CAPTION_ID3       			CUI_INLINE_ITEM_ID_BASE + 3
#define BMI_TEXT_EDIT_ID4      			CUI_INLINE_ITEM_ID_BASE + 4

#define  BMI_MALE_LB             20     /* Lower bound of standard BMI index of a man */
#define  BMI_MALE_UB             25     /* Upper bound of standard BMI index of a man */
#define  BMI_FEMALE_LB           18     /* Lower bound of standard BMI index of a woman */
#define  BMI_FEMALE_UB           23     /* Upper bound of standard BMI index of a woman */
#define  BMI_MAX_INPUT           8
#define  BMI_DIGIT_LEN           9*ENCODING_LENGTH
#define  BMI_LB_UB_LEN           4*ENCODING_LENGTH      /* buffer length to store lower and upper bound */
#define  BMI_RESULT_LEN          7*ENCODING_LENGTH      /* buffer length to store resut xxx.xx */
#define  BMI_MAX_HEIGHT          300
#define  BMI_MIN_HEIGHT          55
#define  BMI_MAX_WEIGHT          300
#define  BMI_MIN_WEIGHT          1
/* 
 * Typedef 
 */
typedef struct
{
    DOUBLE Height;
    DOUBLE Weight;
    S32 Gender;
    U8 *GenderList[2];
    CHAR UBBuf[BMI_LB_UB_LEN];
    CHAR LBBuf[BMI_LB_UB_LEN];
    CHAR ResultBuf[BMI_RESULT_LEN];
    CHAR HeightBuf[BMI_DIGIT_LEN];
    CHAR WeightBuf[BMI_DIGIT_LEN];
    U8 CurrHilite;
} bmi_context_struct;

/* 
 * Global Variable
 */

bmi_context_struct *g_bmi_cntx = NULL;
static U8 isback;

/* 
 * Global Function
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

static double mmi_bmi_wsc_to_dbl(U16 *s);
static void mmi_bmi_dbl_to_wsc(U16 *s, double number);
static void mmi_bmi_remove_zero_in_tail(U16 *buffer);
static void mmi_bmi_deinit(void);
static mmi_ret mmi_bmi_cui_event_proc(mmi_event_struct *evt);
static void mmi_bmi_entry_welcome_screen(void);
static void mmi_bmi_entry_input_screen(void);
static void mmi_bmi_exit_input_screen(void);
static void mmi_bmi_entry_result_screen(void);
static mmi_ret mmi_bmi_input_scrn_leave_proc(mmi_event_struct *evt);
static void mmi_bmi_inline_highlight_hdlr(S32 index);
static void mmi_bmi_compute_result(void);
static void mmi_bmi_highlight_gender(S32 index);
static void mmi_bmi_fill_inline_struct(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_wsc_to_dbl
 * DESCRIPTION
 *  converter wide string to double
 * PARAMETERS
 *  s :[IN] wide string
 * RETURNS
 *  return double value not check validation.
 *****************************************************************************/
static double mmi_bmi_wsc_to_dbl(U16 *s)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ansii_str[BMI_MAX_INPUT + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_to_asc(ansii_str, s);
    return atof(ansii_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_dbl_to_wsc
 * DESCRIPTION
 *  converter double to wide string 
 * PARAMETERS
 *  number :[IN] double value
 * RETURNS
 *  return wide string not check validation.
 *****************************************************************************/
static void mmi_bmi_dbl_to_wsc(U16 *s, double number)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	CHAR tmp[BMI_MAX_DIGITS * 2], fmt[8];
	CHAR *p;
	S32 len;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    kal_sprintf(fmt, "%%.%df", (BMI_MAX_DIGITS - 2));
	kal_sprintf(tmp, fmt, number);
	p = strchr((char*)tmp, '.');
	*p = 0;
	len = strlen((char*)tmp);
    if ((BMI_MAX_DIGITS - len - 1) > 0)
    {
        kal_sprintf(fmt, "%%%d.%df", len, (BMI_MAX_DIGITS - len - 1));
        kal_sprintf(tmp, fmt, number);
    }
    else
    {
        kal_sprintf(fmt, "%%%d.%df", len, 0);
        kal_sprintf(tmp, fmt, number);
    }
	mmi_asc_to_wcs(s, tmp);
	mmi_bmi_remove_zero_in_tail(s);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_remove_zero_in_tail
 * DESCRIPTION
 *  remove zero from tail of string 
 * PARAMETERS
 *  buffer :[IN] wide string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_remove_zero_in_tail(U16 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 dotIndex;
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((CHAR*)buffer);
    for (dotIndex = 0; dotIndex < length; dotIndex++)
    {
        if (buffer[dotIndex] == '.')
            break;
    }
    if (dotIndex == length) /* integer */
        return;

    index = length - 1;
    while(index != dotIndex)
    {
        if (buffer[index] != '0')
        {
            buffer[++index] = 0;
            return;
        }
        index--;
    }
    buffer[index] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_deinit
 * DESCRIPTION
 *  Free allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bmi_cntx)
    {
        OslMfree(g_bmi_cntx);
        g_bmi_cntx  = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_pre_entry_welcome_screen
 * DESCRIPTION
 *  Pre entry function for bmi.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bmi_pre_entry_welcome_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (mmi_frm_group_is_present(GRP_ID_BMI))
    {
        mmi_frm_group_close(GRP_ID_BMI);
    }
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BMI, mmi_bmi_cui_event_proc, NULL);
    mmi_frm_group_enter(GRP_ID_BMI, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_bmi_entry_welcome_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_cui_event_proc
 * DESCRIPTION
 *  Proc for cui related to bmi.
 * PARAMETERS
 *  evt  :[IN] received event from framework
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bmi_cui_event_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	/* Inline cui revise */
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    cui_event_inline_csk_press_struct *inline_csk_press_event;
	cui_event_inline_notify_struct *inline_notify_event;
	U16 BMIImageList[ENUM_INLINE_TOTAL] = {0, 0, 0, 0, 0};

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	switch (evt->evt_id)
	{
		case EVT_ID_CUI_INLINE_SUBMIT:
        {
            
            inline_submit_event = (cui_event_inline_submit_struct*)evt;
			cui_inline_get_value(inline_submit_event->sender_id, BMI_TEXT_EDIT_ID2, g_bmi_cntx->HeightBuf);
			cui_inline_get_value(inline_submit_event->sender_id, BMI_TEXT_EDIT_ID4, g_bmi_cntx->WeightBuf);
			mmi_bmi_compute_result();
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
			mmi_bmi_deinit();
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            inline_csk_press_event = (cui_event_inline_csk_press_struct*)evt;
			cui_inline_get_value(inline_csk_press_event->sender_id, BMI_TEXT_EDIT_ID2, g_bmi_cntx->HeightBuf);
			cui_inline_get_value(inline_csk_press_event->sender_id, BMI_TEXT_EDIT_ID4, g_bmi_cntx->WeightBuf);
			mmi_bmi_compute_result();
            break;
        }
        
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
			inline_notify_event = (cui_event_inline_notify_struct *)evt;
        	switch (inline_notify_event->event_type)
    		{
    			case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
					if (inline_notify_event->item_id == BMI_SELECT_ID0)
					{
						g_bmi_cntx->Gender = inline_notify_event->param;
						if (g_bmi_cntx->Gender)
						{
							BMIImageList[ENUM_GENDER] = IMG_BMI_RED_FLOWER;
						}
						else
						{
							BMIImageList[ENUM_GENDER] = IMG_BMI_BLUE_FLOWER;
						}
						cui_inline_set_icon_list(inline_notify_event->sender_id, BMIImageList);
						cui_inline_redraw_screen(inline_notify_event->sender_id);
					}
					break;

				case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
					switch (inline_notify_event->item_id)
					{
						case BMI_SELECT_ID0:
							g_bmi_cntx->CurrHilite = 0;
							break;
						case BMI_TEXT_EDIT_ID2:
							g_bmi_cntx->CurrHilite = 2;
							break;
						case BMI_TEXT_EDIT_ID4:
							g_bmi_cntx->CurrHilite = 4;
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
 *  mmi_bmi_entry_welcome_screen
 * DESCRIPTION
 *  Display welcome screen of BMI application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_entry_welcome_screen(void)
{
/* WQVGA & HVGA & FTE project has no bmi welcome screen */
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
			GRP_ID_BMI, 
			SCR_BMI_WELCOME, 
			NULL, 
			mmi_bmi_entry_welcome_screen, 
			MMI_FRM_FULL_SCRN))
    {
    return;
	}
	isback = 0;
	guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BMI ,SCR_BMI_WELCOME);
    ShowCategory129Screen(
        (U8*) get_string(STR_BMI_WELCOME_CAPTION),
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_BMI_WELCOME_SCREEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_bmi_entry_input_screen, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_bmi_entry_input_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	
#else /* __MMI_MAINLCD_240X320__ */ 
    isback = 0;
    mmi_bmi_entry_input_screen();
#endif /* __MMI_MAINLCD_240X320__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_entry_input_screen
 * DESCRIPTION
 *  Display inline editor screen for entering gender, height, and weight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_entry_input_screen(void)
{
#if !defined(__MMI_MAINLCD_240X320__) || defined(__MMI_FTE_SUPPORT__)
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U16 BMIImageList[ENUM_INLINE_TOTAL] = {0, 0, 0, 0, 0};
	cui_inline_item_softkey_struct softkey_struct = 
		{
			{{STR_GLOBAL_OK, 0},
			{STR_GLOBAL_BACK, 0},
			{0, IMG_GLOBAL_COMMON_CSK}}
		};
	U16 select_string[2] = {STR_BMI_MALE_TEXT, STR_BMI_FEMALE_TEXT};
	cui_inline_item_select_struct select0;
	cui_inline_item_caption_struct caption1;
	cui_inline_item_text_edit_struct textedit2;
	cui_inline_item_caption_struct caption3;
	cui_inline_item_text_edit_struct textedit4;
	cui_inline_set_item_struct bmi_inline_items[ENUM_INLINE_TOTAL];
	cui_inline_struct inline_struct;
	mmi_id  bmi_inline_cui_id;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/* cui inline struct define */	
	if (g_bmi_cntx	==	NULL)
	{
		g_bmi_cntx	= OslMalloc(sizeof(bmi_context_struct));
		memset(g_bmi_cntx, 0, sizeof(bmi_context_struct));
	}
	
	if (g_bmi_cntx->Gender == 0)
    {
        BMIImageList[ENUM_GENDER] = IMG_BMI_BLUE_FLOWER;
    }
    else
    {
        BMIImageList[ENUM_GENDER] = IMG_BMI_RED_FLOWER;
    }
	set_leading_zero(FALSE);
	select0.n_items= 2;
	select0.highlighted_item = 0;
	select0.list_of_item_id = select_string;
	
	caption1.string_id= STR_BMI_HEIGHT_TEXT;
	
	textedit2.string_id= 0;
	textedit2.default_text_id = 0;
	textedit2.buffer_size = BMI_MAX_INPUT + 1;
	textedit2.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
	textedit2.input_extended_type = 0;
	textedit2.required_input_mode_set = NULL;
	
	caption3.string_id= STR_BMI_WEIGHT_TEXT;
	
	textedit4.string_id= 0;
	textedit4.default_text_id = 0;
	textedit4.buffer_size = BMI_MAX_INPUT + 1;
	textedit4.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
	textedit4.input_extended_type = 0;
	textedit4.required_input_mode_set = NULL;
	
	bmi_inline_items[0].item_id = BMI_SELECT_ID0;
	bmi_inline_items[0].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
	bmi_inline_items[0].image_id = BMIImageList[ENUM_GENDER];
	bmi_inline_items[0].item_data = &select0;
	
	bmi_inline_items[1].item_id = BMI_CAPTION_ID1;
	bmi_inline_items[1].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
	bmi_inline_items[1].image_id = 0;
	bmi_inline_items[1].item_data = &caption1;
	
	bmi_inline_items[2].item_id = BMI_TEXT_EDIT_ID2;
	bmi_inline_items[2].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
	bmi_inline_items[2].image_id = 0;
	bmi_inline_items[2].item_data = &textedit2;
	
	bmi_inline_items[3].item_id = BMI_CAPTION_ID3;
	bmi_inline_items[3].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
	bmi_inline_items[3].image_id = 0;
	bmi_inline_items[3].item_data = &caption3;
	
	bmi_inline_items[4].item_id = BMI_TEXT_EDIT_ID4;
	bmi_inline_items[4].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
	bmi_inline_items[4].image_id = 0;
	bmi_inline_items[4].item_data = &textedit4;

	inline_struct.items_count = 5;
	inline_struct.title = STR_BMI_INPUT_CAPTION;
	inline_struct.title_icon = GetRootTitleIcon(EXTRA_HEALTH_MENU);
	inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
	inline_struct.softkey = &softkey_struct;
	//inline_struct.softkey = NULL;
	inline_struct.items = bmi_inline_items;
		
	bmi_inline_cui_id = cui_inline_create(
							GRP_ID_BMI,
							&inline_struct);
	cui_inline_run(bmi_inline_cui_id);
    
#else /* __MMI_MAINLCD_240X320__ */ 
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 *guiBuffer;
    WCHAR *inputBuffer;        /* added for inline edit history */
    U16 BMIImageList[6] = {0, 0, 0, 0, 0, 0};
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (g_bmi_cntx	==	NULL)
	{
		g_bmi_cntx	= OslMalloc(sizeof(bmi_context_struct));
		memset(g_bmi_cntx, 0, sizeof(bmi_context_struct));
	}
	
    if(!mmi_frm_scrn_enter(
		GRP_ID_BMI,
		SCR_BMI_INPUT, 
		mmi_bmi_exit_input_screen, 
		mmi_bmi_entry_input_screen, 
		MMI_FRM_FULL_SCRN))
	{
    	return;
	}
	mmi_frm_scrn_set_leave_proc(GRP_ID_BMI, SCR_BMI_INPUT, mmi_bmi_input_scrn_leave_proc);
//    SetDelScrnIDCallbackHandler(SCR_BMI_INPUT, (HistoryDelCBPtr) BMIDelScrCB);

    InitializeCategory57Screen();

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BMI, SCR_BMI_INPUT);

    mmi_bmi_fill_inline_struct();

    RegisterHighlightHandler(mmi_bmi_inline_highlight_hdlr);

    if (g_bmi_cntx->Gender == 0)
    {
        BMIImageList[ENUM_GENDER] = IMG_BMI_BLUE_FLOWER;
    }
    else
    {
        BMIImageList[ENUM_GENDER] = IMG_BMI_RED_FLOWER;
    }

    inputBuffer = mmi_frm_scrn_get_active_input_buf(); /* added for inline edit history */

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, ENUM_INLINE_TOTAL, (U8*)inputBuffer);   /* sets the data */
    }

    DisableCategory57ScreenDone();
    if(isback == 1)
    {
        guiBuffer = NULL;
        isback = 0;
    }
   // guiBuffer = NULL;
#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
#endif 

    

    ShowCategory357Screen(
        STR_BMI_INPUT_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_BMI_WELCOME_SCREEN,
        ENUM_INLINE_TOTAL,
        BMIImageList,
        wgui_inline_items,
        g_bmi_cntx->CurrHilite,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_bmi_compute_result, mmi_frm_scrn_close_active_id);
#endif /* __MMI_MAINLCD_240X320__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_input_scrn_leave_proc
 * DESCRIPTION
 *  Free memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bmi_input_scrn_leave_proc(mmi_event_struct *evt)
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
            if (mmi_frm_scrn_get_active_id() == SCR_BMI_INPUT)
		    {
		        CloseCategory57Screen();
		    }
		    mmi_bmi_deinit();
            break;
            
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_exit_input_screen
 * DESCRIPTION
 *  Exit handler of mmi_bmi_entry_input_screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_exit_input_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    wgui_restore_list_menu_slim_style();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_fill_inline_struct
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(FALSE);

    g_bmi_cntx->GenderList[0] = (U8*) GetString(STR_BMI_MALE_TEXT);
    g_bmi_cntx->GenderList[1] = (U8*) GetString(STR_BMI_FEMALE_TEXT);

    /* gender */
    SetInlineItemActivation(&wgui_inline_items[ENUM_GENDER], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[ENUM_GENDER], 2, (U8 **) g_bmi_cntx->GenderList, &g_bmi_cntx->Gender);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[ENUM_GENDER], mmi_bmi_highlight_gender);

    /* height caption */
    SetInlineItemActivation(&wgui_inline_items[ENUM_HEIGHT_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[ENUM_HEIGHT_CAPTION], (U8*) GetString(STR_BMI_HEIGHT_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_HEIGHT_CAPTION]);

    /* height */
    SetInlineItemActivation(&wgui_inline_items[ENUM_HEIGHT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[ENUM_HEIGHT],
        (U8*) g_bmi_cntx->HeightBuf,
        (BMI_MAX_INPUT + 1),
        IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    RightJustifyInlineItem(&wgui_inline_items[ENUM_HEIGHT]);
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_HEIGHT]);
    EnableInlineItemBoundary(&wgui_inline_items[ENUM_HEIGHT]);

    /* weight caption */
    SetInlineItemActivation(&wgui_inline_items[ENUM_WEIGHT_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[ENUM_WEIGHT_CAPTION], (U8*) GetString(STR_BMI_WEIGHT_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_WEIGHT_CAPTION]);

    /* weight */
    SetInlineItemActivation(&wgui_inline_items[ENUM_WEIGHT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[ENUM_WEIGHT],
        (U8*) g_bmi_cntx->WeightBuf,
        (BMI_MAX_INPUT + 1),
        IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    RightJustifyInlineItem(&wgui_inline_items[ENUM_WEIGHT]);
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_WEIGHT]);
    EnableInlineItemBoundary(&wgui_inline_items[ENUM_WEIGHT]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_entry_result_screen
 * DESCRIPTION
 *  Display result screen of calculation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_entry_result_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    DOUBLE bmiValue;
    U8 *bmiBuf;
    U8 percentageValue;
    U16 FolwerIndex;
    U8 LB, UB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_frm_scrn_enter(
			GRP_ID_BMI,
			SCR_BMI_RESULT, 
			NULL,
        	mmi_bmi_entry_result_screen, 
        	MMI_FRM_FULL_SCRN))
    {
        return;
    }
    memset(g_bmi_cntx->ResultBuf, 0, sizeof(g_bmi_cntx->ResultBuf));
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BMI, SCR_BMI_RESULT);

    bmiValue = g_bmi_cntx->Weight / (g_bmi_cntx->Height * g_bmi_cntx->Height) * 10000;
	
	mmi_bmi_dbl_to_wsc((U16*)g_bmi_cntx->ResultBuf, bmiValue);
    if (g_bmi_cntx->Gender == 0)
    {
        LB = BMI_MALE_LB;
        UB = BMI_MALE_UB;
        FolwerIndex = IMG_BMI_BLUE_FLOWER;
    }
    else
    {
        LB = BMI_FEMALE_LB;
        UB = BMI_FEMALE_UB;
        FolwerIndex = IMG_BMI_RED_FLOWER;
    }

    gui_itoa(LB, (U16*) g_bmi_cntx->LBBuf, 10);
    gui_itoa(UB, (U16*) g_bmi_cntx->UBBuf, 10);

    if (bmiValue > UB)
    {
        bmiBuf = (U8*) GetString(STR_BMI_FAT);
        percentageValue = 2;
    }
    else if (bmiValue < LB)
    {
        bmiBuf = (U8*) GetString(STR_BMI_THIN);
        percentageValue = 0;
    }
    else
    {
        bmiBuf = (U8*) GetString(STR_GLOBAL_NORMAL);
        percentageValue = 1;
    }

    ShowCategory122Screen(
        STR_BMI_RESULT_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_BMI_BMI_TEXT,
        percentageValue,
        guiBuffer,
        g_bmi_cntx->ResultBuf,
        bmiBuf,
        FolwerIndex,
        (U8*) g_bmi_cntx->LBBuf,
        (U8*) g_bmi_cntx->UBBuf);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_inline_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline editor in input screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_inline_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bmi_cntx->CurrHilite = (U8) index;	
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	SetLeftSoftkeyFunction(mmi_bmi_compute_result, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_bmi_compute_result, KEY_EVENT_UP);    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_highlight_gender
 * DESCRIPTION
 *  Highlight handler of Gender item in input screen.
 *  Change display folwer when gender changed.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_highlight_gender(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bmi_cntx->Gender == 0)
    {
        Category57ChangeItemIcon(0, IMG_BMI_BLUE_FLOWER);
    }
    else
    {
        Category57ChangeItemIcon(0, IMG_BMI_RED_FLOWER);
    }

    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bmi_compute_result
 * DESCRIPTION
 *  Validate correctness of input data and calcalute result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bmi_compute_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
	g_bmi_cntx->Height = mmi_bmi_wsc_to_dbl((U16*)g_bmi_cntx->HeightBuf);
	g_bmi_cntx->Weight = mmi_bmi_wsc_to_dbl((U16*)g_bmi_cntx->WeightBuf);

    if (((g_bmi_cntx->Height < BMI_MIN_HEIGHT) || (g_bmi_cntx->Height > BMI_MAX_HEIGHT)) &&
        ((g_bmi_cntx->Weight < BMI_MIN_WEIGHT) || (g_bmi_cntx->Weight > BMI_MAX_WEIGHT)))
    {
        //mmi_display_popup_with_sg(GRP_ID_BMI, (UI_string_type)GetString(STR_BMI_HEIGHT_WEIGHT_ERROR), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_BMI_HEIGHT_WEIGHT_ERROR), MMI_EVENT_FAILURE, GRP_ID_BMI, NULL);
        g_bmi_cntx->CurrHilite = 2;
        return;
    }
    else if ((g_bmi_cntx->Height < BMI_MIN_HEIGHT) || (g_bmi_cntx->Height > BMI_MAX_HEIGHT))
    {

        //mmi_display_popup_with_sg(GRP_ID_BMI, (UI_string_type)GetString(STR_BMI_HEIGHT_ERROR_TEXT), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_BMI_HEIGHT_ERROR_TEXT), MMI_EVENT_FAILURE, GRP_ID_BMI, NULL);
        g_bmi_cntx->CurrHilite = 2;
        return;
    }
    else if ((g_bmi_cntx->Weight < BMI_MIN_WEIGHT) || (g_bmi_cntx->Weight > BMI_MAX_WEIGHT))
    {
        //mmi_display_popup_with_sg(GRP_ID_BMI, (UI_string_type)GetString(STR_BMI_WEIGHT_ERROR_TEXT), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_BMI_WEIGHT_ERROR_TEXT), MMI_EVENT_FAILURE, GRP_ID_BMI, NULL);
        g_bmi_cntx->CurrHilite = 4;
        return;
    }
	
    isback = 1;
    mmi_bmi_entry_result_screen();
}
#endif /* __MMI_BMI__ */ // #ifdef __MMI_BMI__

