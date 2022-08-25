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
 * Currencyconvertor.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Currency Convertor application.
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
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Currencyconvertor.c
   Author:        Vandana M
   Date Created:  June-29-2003
   Contains:      Currency Convertor
**********************************************************************************/
#include "MMI_features.h"

#if defined __MMI_CURRENCY_CONVERTER__
#include "MMIDataType.h"
#include "CurrencyConvertor.h"
#include "InlineCuiGprot.h"
#include "ProfilesSrvGprot.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "string.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_currencyconverter_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_inline_edit.h"
#include "gui_typedef.h"
#include "ImeGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_nvram_gprot.h"
#include "gui_inputs.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
/* 
 * Define
 */

/* Inline CUI Revise */
#define CCONV_SELECT_ID0                   CUI_INLINE_ITEM_ID_BASE + 0
#define CCONV_CAPTION_ID1                  CUI_INLINE_ITEM_ID_BASE + 1
#define CCONV_TEXT_EDIT_ID2              CUI_INLINE_ITEM_ID_BASE + 2
#define CCONV_CAPTION_ID3               CUI_INLINE_ITEM_ID_BASE + 3
#define CCONV_TEXT_EDIT_ID4              CUI_INLINE_ITEM_ID_BASE + 4

#define  CCONV_MAX_RATE          5
#define  CCONV_MAX_INPUT            7
#define  CCONV_MAX_RESULT        12
#define  CCONV_SEL_BUF_LEN       10*ENCODING_LENGTH     /* length of inline selection string */
#define  CCONV_RESULT_BUF_LEN    (CCONV_MAX_RESULT+1)*ENCODING_LENGTH

/* 
 * Typedef 
 */
typedef struct
{
    DOUBLE Rate;
    S32 CurrSelRate;    /* current selecting rate */
    CHAR *RateList[2];
    CHAR LocalBuff[CCONV_RESULT_BUF_LEN];
    CHAR ForeBuff[CCONV_RESULT_BUF_LEN];
    CHAR RateBuff[CCONV_RESULT_BUF_LEN];
    CHAR RateString[2][CCONV_SEL_BUF_LEN];
    U8 CurrHiliteItem;
    U8 IsFromHistory;
    MMI_BOOL is_reset;
} cconv_context_struct;

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
static double mmi_cconv_wsc_to_dbl(U16 *s);
static void mmi_cconv_dbl_to_wsc(U16 *s, double number, S16 max_digits);
static void mmi_cconv_remove_zero_in_tail(U16 *buffer);
static mmi_ret mmi_cconv_input_scrn_leave_proc(mmi_event_struct *evt);
static mmi_ret mmi_cconv_cui_event_proc(mmi_event_struct *evt);
void mmi_cconv_pre_entry_app(void);
static void mmi_cconv_highlight_rate_item(S32 index);
static void mmi_cconv_deinit(void);
static void mmi_cconv_entry_app(void);
static void mmi_cconv_exit_app(void);
static void mmi_cconv_pre_entry_exchange(void);
static void mmi_cconv_entry_exchange(void);
static void mmi_cconv_back_function(void);
static void mmi_cconv_reset_rate(void);
static void mmi_cconv_cancel_save(void);
static void mmi_cconv_save_rate_comfirm(void);
static MMI_BOOL mmi_cconv_compute_result(void);

/* 
 * Global Variable
 */
cconv_context_struct *g_cconv_cntx = NULL;

/* 
 * Global Function
 */

#define UCONV_RATE_INPUT
/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_wsc_to_dbl
 * DESCRIPTION
 *  converter wide string to double
 * PARAMETERS
 *  s :[IN] wide string
 * RETURNS
 *  return double value not check validation.
 *****************************************************************************/
static double mmi_cconv_wsc_to_dbl(U16 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ansii_str[CCONV_MAX_RESULT + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_to_asc(ansii_str, s);
    return atof(ansii_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_dbl_to_wsc
 * DESCRIPTION
 *  converter double to wide string 
 * PARAMETERS
 *  number :[IN] double value
 * RETURNS
 *  return wide string not check validation.
 *****************************************************************************/
static void mmi_cconv_dbl_to_wsc(U16 *s, double number, S16 max_digits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    CHAR tmp[CCONV_MAX_RESULT * 2], fmt[8];
    CHAR *p;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sprintf(fmt, "%%.%df", (max_digits - 2));
    kal_sprintf(tmp, fmt, number);
    p = strchr((char*)tmp, '.');
    *p = 0;
    len = strlen((char*)tmp);
    if ((max_digits - len - 1) > 0)
    {
        kal_sprintf(fmt, "%%%d.%df", len, (max_digits - len - 1));
        kal_sprintf(tmp, fmt, number);
    }
    else
    {
        kal_sprintf(fmt, "%%%d.%df", len, 0);
        kal_sprintf(tmp, fmt, number);
    }
    mmi_asc_to_wcs(s, tmp);
    mmi_cconv_remove_zero_in_tail(s);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_remove_zero_in_tail
 * DESCRIPTION
 *  remove zero from tail of string 
 * PARAMETERS
 *  buffer :[IN] wide string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_remove_zero_in_tail(U16 *buffer)
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
 *  mmi_cconv_input_scrn_leave_proc
 * DESCRIPTION
 *  Free memory
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
static mmi_ret mmi_cconv_input_scrn_leave_proc(mmi_event_struct *evt)
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
            if (mmi_frm_scrn_get_active_id() == SCR_ID_CCONV_RATE_INPUT)
            {
                CloseCategory57Screen();
            }
            mmi_cconv_deinit();
            break;
            
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_cui_event_proc
 * DESCRIPTION
 *  Free memory
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_cconv_cui_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    /* Inline cui revise */
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    cui_event_inline_csk_press_struct *inline_csk_press_event;
    cui_event_inline_notify_struct *inline_notify_event;
    S32 curr_hilite_index = 0;
    MMI_BOOL b;
    cui_inline_item_display_only_struct display_item; 
    cui_inline_item_text_edit_struct textedit_item;         
    cui_inline_set_item_struct set_item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            
            inline_submit_event = (cui_event_inline_submit_struct*)evt;
            cui_inline_get_value(inline_submit_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);
            cui_inline_get_value(inline_submit_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
        
            b = mmi_cconv_compute_result();

            if (b)    
            {
                cui_inline_lock_main_screen(inline_submit_event->sender_id);
                /* converter edit inline to display inline so it can display a long result */ 
                cui_inline_delete_item(inline_submit_event->sender_id, CCONV_TEXT_EDIT_ID2);
                display_item.string_id = 0;                                    
                set_item.item_id = CCONV_TEXT_EDIT_ID2;                        
                 set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT;
                set_item.image_id = 0;                            
                set_item.item_data = &display_item;
                
                cui_inline_insert_item(inline_submit_event->sender_id, CCONV_CAPTION_ID3, &set_item);
                
                cui_inline_set_value(inline_submit_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);    

                  cui_inline_set_value(inline_submit_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
                                            
                cui_inline_set_softkey_text(
                    inline_submit_event->sender_id,
                    inline_submit_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    inline_submit_event->sender_id,
                    inline_submit_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    0);
                cui_inline_set_softkey_text(
                    inline_submit_event->sender_id,
                    inline_submit_event->item_id,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    inline_submit_event->sender_id,
                    inline_submit_event->item_id,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_text(
                    inline_submit_event->sender_id,
                    inline_submit_event->item_id,
                    MMI_RIGHT_SOFTKEY,
                    STR_GLOBAL_RESET);
                cui_inline_set_softkey_icon(
                    inline_submit_event->sender_id,
                    inline_submit_event->item_id,
                    MMI_RIGHT_SOFTKEY,
                    0);
                cui_inline_set_highlight_item(inline_submit_event->sender_id, inline_submit_event->item_id);
                g_cconv_cntx->is_reset = MMI_TRUE;
                cui_inline_unlock_main_screen(inline_submit_event->sender_id);
                cui_inline_redraw_screen(inline_submit_event->sender_id);
            }
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            if (g_cconv_cntx->is_reset)
            {
                cui_inline_lock_main_screen(inline_abort_event->sender_id);
                mmi_wcscpy((WCHAR*)g_cconv_cntx->LocalBuff, L"");
                mmi_wcscpy((WCHAR*)g_cconv_cntx->ForeBuff, L"");
                //delete and insert
                cui_inline_delete_item(inline_abort_event->sender_id, CCONV_TEXT_EDIT_ID2);

                textedit_item.string_id= 0;
                textedit_item.default_text_id = 0;
                textedit_item.buffer_size = CCONV_MAX_INPUT + 1;
                textedit_item.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
                textedit_item.input_extended_type = 0;
                textedit_item.required_input_mode_set = NULL;
                
                set_item.item_id = CCONV_TEXT_EDIT_ID2;                     
                set_item.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
                set_item.image_id = 0;                            
                set_item.item_data = &textedit_item;
                
                cui_inline_insert_item(inline_abort_event->sender_id, CCONV_CAPTION_ID3, &set_item);
                cui_inline_set_value(inline_abort_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);

                cui_inline_set_value(inline_abort_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
                
                cui_inline_set_highlight_item(inline_abort_event->sender_id, inline_abort_event->item_id);
                
                cui_inline_set_softkey_text(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    STR_GLOBAL_OK);
                cui_inline_set_softkey_icon(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    0);
                cui_inline_set_softkey_text(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    MMI_CENTER_SOFTKEY,
                    IMG_GLOBAL_COMMON_CSK);
                cui_inline_set_softkey_text(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    MMI_RIGHT_SOFTKEY,
                    STR_GLOBAL_BACK);
                cui_inline_set_softkey_icon(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    MMI_RIGHT_SOFTKEY,
                    0);
                g_cconv_cntx->is_reset = MMI_FALSE;
                cui_inline_unlock_main_screen(inline_abort_event->sender_id);
                cui_inline_redraw_screen(inline_abort_event->sender_id);
            }
            else
            {
                cui_inline_close(inline_abort_event->sender_id);
            }
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            inline_csk_press_event = (cui_event_inline_csk_press_struct*)evt;
            cui_inline_get_value(inline_csk_press_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);
            cui_inline_get_value(inline_csk_press_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
    
            b = mmi_cconv_compute_result();
            
            if (b)    
            {
                cui_inline_lock_main_screen(inline_csk_press_event->sender_id);
                /* converter edit inline to display inline so it can display a long result */ 
                cui_inline_delete_item(inline_csk_press_event->sender_id, CCONV_TEXT_EDIT_ID2);
    
                display_item.string_id = 0;                                 
                set_item.item_id = CCONV_TEXT_EDIT_ID2;                     
                set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT;
                set_item.image_id = 0;                            
                set_item.item_data = &display_item;
                
                cui_inline_insert_item(inline_csk_press_event->sender_id, CCONV_CAPTION_ID3, &set_item);
                cui_inline_set_value(inline_csk_press_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);

                cui_inline_set_value(inline_csk_press_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
                
                cui_inline_set_highlight_item(inline_csk_press_event->sender_id, inline_csk_press_event->item_id);
                                
                cui_inline_set_softkey_text(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    0);
                cui_inline_set_softkey_text(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_text(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    MMI_RIGHT_SOFTKEY,
                    STR_GLOBAL_RESET);
                cui_inline_set_softkey_icon(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    MMI_RIGHT_SOFTKEY,
                    0);
        
                g_cconv_cntx->is_reset = MMI_TRUE;
                cui_inline_unlock_main_screen(inline_csk_press_event->sender_id);
                cui_inline_redraw_screen(inline_csk_press_event->sender_id);
            }
            
            break;
        }
        
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            inline_notify_event = (cui_event_inline_notify_struct *)evt;
            switch (inline_notify_event->event_type)
            {
                case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                    if (inline_notify_event->item_id == CCONV_SELECT_ID0)
                    {
                        g_cconv_cntx->CurrSelRate = (U8)inline_notify_event->param;
                        mmi_wcscpy((WCHAR*)g_cconv_cntx->LocalBuff, L"");
                        mmi_wcscpy((WCHAR*)g_cconv_cntx->ForeBuff, L"");
                        cui_inline_set_value(inline_notify_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);
                        cui_inline_set_value(inline_notify_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
                    }
                    break;

                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    switch (inline_notify_event->item_id)
                    {
                        case CCONV_SELECT_ID0:
                            curr_hilite_index = 0;
                            break;
                        case CCONV_TEXT_EDIT_ID2:
                            curr_hilite_index = 2;
                            break;
                        default:
                            break;
                    }
                    if ((U8)curr_hilite_index != g_cconv_cntx->CurrHiliteItem)
                    {
                        cui_inline_lock_main_screen(inline_notify_event->sender_id);
                        mmi_wcscpy((WCHAR*)g_cconv_cntx->LocalBuff, L"");
                        mmi_wcscpy((WCHAR*)g_cconv_cntx->ForeBuff, L"");
                        if (g_cconv_cntx->is_reset)
                        {
                            //delete and insert
                            cui_inline_delete_item(inline_notify_event->sender_id, CCONV_TEXT_EDIT_ID2);
    
                            textedit_item.string_id= 0;
                            textedit_item.default_text_id = 0;
                            textedit_item.buffer_size = CCONV_MAX_INPUT + 1;
                            textedit_item.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
                            textedit_item.input_extended_type = 0;
                            textedit_item.required_input_mode_set = NULL;
                            
                            set_item.item_id = CCONV_TEXT_EDIT_ID2;                     
                            set_item.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
                            set_item.image_id = 0;                            
                            set_item.item_data = &textedit_item;
                            
                            cui_inline_insert_item(inline_notify_event->sender_id, CCONV_CAPTION_ID3, &set_item);
                        }
                        
                        if(inline_notify_event->item_id != CCONV_SELECT_ID0)
                        {
                            if(g_cconv_cntx->is_reset)
                            {
                                cui_inline_set_value(inline_notify_event->sender_id, CCONV_TEXT_EDIT_ID2, g_cconv_cntx->LocalBuff);
                                cui_inline_set_value(inline_notify_event->sender_id, CCONV_TEXT_EDIT_ID4, g_cconv_cntx->ForeBuff);
                            }
                            
                            cui_inline_set_softkey_text(
                                inline_notify_event->sender_id,
                                inline_notify_event->item_id,
                                MMI_LEFT_SOFTKEY,
                                STR_GLOBAL_OK);
                            cui_inline_set_softkey_icon(
                                inline_notify_event->sender_id,
                                inline_notify_event->item_id,
                                MMI_LEFT_SOFTKEY,
                                IMG_GLOBAL_OK);
                            cui_inline_set_softkey_text(
                                inline_notify_event->sender_id,
                                inline_notify_event->item_id,
                                MMI_CENTER_SOFTKEY,
                                0);
                            cui_inline_set_softkey_icon(
                                inline_notify_event->sender_id,
                                inline_notify_event->item_id,
                                MMI_CENTER_SOFTKEY,
                                IMG_GLOBAL_COMMON_CSK);
                            cui_inline_set_softkey_text(
                                inline_notify_event->sender_id,
                                inline_notify_event->item_id,
                                MMI_RIGHT_SOFTKEY,
                                STR_GLOBAL_BACK);
                            cui_inline_set_softkey_icon(
                                inline_notify_event->sender_id,
                                inline_notify_event->item_id,
                                MMI_RIGHT_SOFTKEY,
                                0);    
                        }
                                            
                        g_cconv_cntx->CurrHiliteItem = (U8)curr_hilite_index;
                        if(g_cconv_cntx->is_reset)
                        {
                            cui_inline_set_highlight_item(inline_notify_event->sender_id, inline_notify_event->item_id);
                        }
                        cui_inline_unlock_main_screen(inline_notify_event->sender_id);
                        if(g_cconv_cntx->is_reset)
                        {
                            cui_inline_redraw_screen(inline_notify_event->sender_id);
                            g_cconv_cntx->is_reset = MMI_FALSE;
                        }
                    }
                    break;
                case CUI_INLINE_NOTIFY_ITEM_ACTIVATED:
//                    mmi_uconv_custom_inline_function();
                    break;
                case CUI_INLINE_NOTIFY_TEXT_EMPTY:
                    cui_inline_set_softkey_text(
                        inline_notify_event->sender_id,
                        inline_notify_event->item_id,
                        MMI_RIGHT_SOFTKEY,
                        STR_GLOBAL_BACK);
                    break;
                case CUI_INLINE_NOTIFY_TEXT_NOT_EMPTY:
                    cui_inline_set_softkey_text(
                        inline_notify_event->sender_id,
                        inline_notify_event->item_id,
                        MMI_RIGHT_SOFTKEY,
                        STR_GLOBAL_CLEAR);
                    break;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_deinit
 * DESCRIPTION
 *  Free allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_cntx)
    {
        OslMfree(g_cconv_cntx);
        g_cconv_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_pre_entry_app
 * DESCRIPTION
 *  Application memory and entry application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_pre_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_cntx)
    {
        OslMfree(g_cconv_cntx);
    }

    g_cconv_cntx = OslMalloc(sizeof(cconv_context_struct));
    memset(g_cconv_cntx, 0, sizeof(cconv_context_struct));
    if (mmi_frm_group_is_present(GRP_ID_CCONV))
    {
        mmi_frm_group_close(GRP_ID_CCONV);
    }
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_CCONV, mmi_cconv_cui_event_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CCONV, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_cconv_entry_app();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_highlight_menu
 * DESCRIPTION
 *  Highlight handler of Currency Converter menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_cconv_pre_entry_app, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cconv_pre_entry_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_highlight_rate_item
 * DESCRIPTION
 *  Highlight handler of rate input inline item.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_highlight_rate_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_cconv_pre_entry_exchange, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cconv_pre_entry_exchange, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_entry_app
 * DESCRIPTION
 *  Display rate input screen of currency convertor application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_entry_app()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    WCHAR *inputBuffer;
    S16 error;
    U16 RskImg = STR_GLOBAL_BACK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        GRP_ID_CCONV,
        SCR_ID_CCONV_RATE_INPUT,
        mmi_cconv_exit_app,
        mmi_cconv_entry_app,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_CCONV, SCR_ID_CCONV_RATE_INPUT);

    mmi_frm_scrn_set_leave_proc(GRP_ID_CCONV, SCR_ID_CCONV_RATE_INPUT, mmi_cconv_input_scrn_leave_proc);
    
    InitializeCategory57Screen();

    inputBuffer = mmi_frm_scrn_get_input_buf(GRP_ID_CCONV, SCR_ID_CCONV_RATE_INPUT);
    
    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, 2, (U8*)inputBuffer);   /* sets the data */
    }

    if (g_cconv_cntx->IsFromHistory)
    {
        if (mmi_ucs2strlen(g_cconv_cntx->RateBuff))
        {
            RskImg = STR_GLOBAL_CLEAR;
        }
        else
        {
            RskImg = STR_GLOBAL_BACK;
        }
    }
    else
    {
        ReadValue(CURRENCY_CONVERTOR_EXCHANGE_RATE, &g_cconv_cntx->Rate, DS_DOUBLE, &error);
        g_cconv_cntx->IsFromHistory = TRUE;
        if (g_cconv_cntx->Rate <= 999999 && g_cconv_cntx->Rate > 0) /* o data has been written set the text to blank */
        {
            mmi_cconv_dbl_to_wsc((U16*)g_cconv_cntx->RateBuff, g_cconv_cntx->Rate, CCONV_MAX_RATE);
        }
        else 
            g_cconv_cntx->Rate = 0;
        if (guiBuffer)
        {
            memset((void*)guiBuffer, 0, 2);
        }

    }

    SetInlineItemCaption(&wgui_inline_items[0], (U8*) get_string(STR_CURRENCYCONVERTOR_RATE));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (U8*) g_cconv_cntx->RateBuff,
        (CCONV_MAX_RATE + 1),
        IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    RightJustifyInlineItem(&wgui_inline_items[1]);

    set_leading_zero(FALSE);
    RegisterHighlightHandler(mmi_cconv_highlight_rate_item);

    ShowCategory257Screen(
        STR_CURRENCYCONVERTOR_RATEINPUT,
        GetRootTitleIcon(EXTRA_CURRENCYCONVERTOR_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        RskImg,
        IMG_GLOBAL_BACK,
        CURRENCY_CONVERTOR_IMAGE,
        2,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_cconv_pre_entry_exchange, mmi_cconv_back_function);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_exit_app
 * DESCRIPTION
 *  Display rate input screen of currency convertor application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_cconv_cntx)
    {
        CloseCategory57Screen();
    }
}


#define UCONV_CONVERTING


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_result
 * DESCRIPTION
 *  Convert the result and display.
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_TRUE if compute result success, or return MMI_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_cconv_compute_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    DOUBLE result, conversion_factor; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_wcslen((WCHAR*)g_cconv_cntx->LocalBuff);
    if (len < 1)
    {
        memset(g_cconv_cntx->ForeBuff, 0, 15);
        //mmi_display_popup_with_sg(GRP_ID_CCONV, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, GRP_ID_CCONV, NULL);
        return MMI_FALSE;
    }

    if (g_cconv_cntx->LocalBuff[0] == '.')
    {
        memset(g_cconv_cntx->ForeBuff, 0, 15);
        //mmi_display_popup_with_sg(GRP_ID_CCONV, (UI_string_type)GetString(ERROR_CURRENCYCONVERTOR_RATE1), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(ERROR_CURRENCYCONVERTOR_RATE1), MMI_EVENT_FAILURE, GRP_ID_CCONV, NULL);
        return MMI_FALSE;
    }

    /* calculate result */
    if (g_cconv_cntx->CurrSelRate)  /* 1:R */
    {
        conversion_factor = g_cconv_cntx->Rate;
    }
    else
    {
        conversion_factor = (1 / g_cconv_cntx->Rate);
    }

    result = (DOUBLE) (conversion_factor * mmi_cconv_wsc_to_dbl((U16*) g_cconv_cntx->LocalBuff));

    mmi_cconv_dbl_to_wsc((U16*)g_cconv_cntx->ForeBuff, result, CCONV_MAX_RESULT);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_pre_entry_exchange
 * DESCRIPTION
 *  Pre-entry function for exchange screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_pre_entry_exchange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* If the rate is ".xxx", it will be treated as wrong input. */
    if (mmi_wcslen((WCHAR*)g_cconv_cntx->RateBuff) < 1)    
    {
        //mmi_display_popup_with_sg(GRP_ID_CCONV, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, GRP_ID_CCONV, NULL);
    }

    else if (mmi_cconv_wsc_to_dbl((U16*) g_cconv_cntx->RateBuff) == 0 || g_cconv_cntx->RateBuff[0] == '.')
    {        
        //mmi_display_popup_with_sg(GRP_ID_CCONV, (UI_string_type)GetString(ERROR_CURRENCYCONVERTOR_RATE1), MMI_EVENT_FAILURE, 0);
        mmi_popup_display_simple((UI_string_type)GetString(ERROR_CURRENCYCONVERTOR_RATE1), MMI_EVENT_FAILURE, GRP_ID_CCONV, NULL);
        return;
    }
    else
    {
        g_cconv_cntx->Rate = mmi_cconv_wsc_to_dbl((U16*) g_cconv_cntx->RateBuff /* Currency_Convertor_rate.text */ );

        g_cconv_cntx->CurrSelRate = 0;
        g_cconv_cntx->CurrHiliteItem = 0;

        memset(g_cconv_cntx->LocalBuff, 0, ENCODING_LENGTH);
        memset(g_cconv_cntx->ForeBuff, 0, ENCODING_LENGTH);

        WriteValue(CURRENCY_CONVERTOR_EXCHANGE_RATE, &g_cconv_cntx->Rate, DS_DOUBLE, &error);
        g_cconv_cntx->IsFromHistory = FALSE;
        mmi_cconv_entry_exchange();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_reset_rate
 * DESCRIPTION
 *  Reset the rate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_reset_rate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    DOUBLE rate;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    rate = 0;
    mmi_frm_scrn_close(GRP_ID_CCONV, SCR_ID_CCONV_RATE_INPUT);
    WriteValue(CURRENCY_CONVERTOR_EXCHANGE_RATE, &rate, DS_DOUBLE, &error);
    srv_prof_stop_tone(SRV_PROF_TONE_NONE);
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_cancel_save
 * DESCRIPTION
 *  Display the save rate confirm popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_cancel_save(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_display_popup_with_sg(GRP_ID_CCONV, (UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, 0);
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, GRP_ID_CCONV, NULL);
    mmi_frm_scrn_close(GRP_ID_CCONV, SCR_ID_CCONV_RATE_INPUT);
    mmi_frm_scrn_close(GRP_ID_CCONV, SCR_ID_CCONV_SAVE_CONFIRM);
    srv_prof_stop_tone(SRV_PROF_TONE_NONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_save_rate_comfirm
 * DESCRIPTION
 *  Display the save rate confirm popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_save_rate_comfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pors;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_get_gui_buf(GRP_ID_CCONV, SCR_ID_CCONV_SAVE_CONFIRM))
    {
        pors = 0;
    }
    else
    {
        pors = 1;
        
    }
    
    if (!mmi_frm_scrn_enter(
            GRP_ID_CCONV,
            SCR_ID_CCONV_SAVE_CONFIRM,
            NULL,
            mmi_cconv_save_rate_comfirm,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }


    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_CURRENCYCONVERTOR_SAVE_RATE),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);
    
    if(pors == 0)
    {
        srv_prof_stop_tone(SRV_PROF_TONE_NONE);
    }
    else
    {
        srv_prof_play_tone(SRV_PROF_TONE_NONE ,NULL);
    }
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_cconv_cancel_save, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cconv_cancel_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_cconv_reset_rate, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_back_function
 * DESCRIPTION
 *  Go back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_back_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_cntx->Rate == 0)
    {
        mmi_frm_scrn_close_active_id();
        return;
    }
    mmi_cconv_save_rate_comfirm();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_entry_exchange
 * DESCRIPTION
 *  Entry Function of Compute currency exchange
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cconv_entry_exchange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 strTemp[] = { ':', '\0', '1', '\0', '\0', '\0' };
    U8 strTemp2[] = { '1', '\0', ':', '\0', '\0', '\0' };
    U16 select_string[2];
    cui_inline_item_select_struct select0;
    cui_inline_item_caption_struct caption1;
    cui_inline_item_text_edit_struct textedit2;
    cui_inline_item_caption_struct caption3;
    cui_inline_item_text_edit_struct textedit4;
    cui_inline_set_item_struct cconv_inline_items[CCONV_INLINE_TOTAL];
    cui_inline_struct inline_struct;
    mmi_id  cconv_inline_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cconv_dbl_to_wsc((U16*)g_cconv_cntx->RateString[0], g_cconv_cntx->Rate, 6);

    mmi_ucs2cpy((CHAR*)g_cconv_cntx->RateString[1], (CHAR*)strTemp2);      /* 1:R */
    mmi_ucs2cat((CHAR*)g_cconv_cntx->RateString[1], (CHAR*)g_cconv_cntx->RateString[0]);   /* R:1 */
    mmi_ucs2cat((CHAR*)g_cconv_cntx->RateString[0], (CHAR*)strTemp);

    g_cconv_cntx->RateList[0] = g_cconv_cntx->RateString[0];
    g_cconv_cntx->RateList[1] = g_cconv_cntx->RateString[1];

    select_string[0] = 0;
    select_string[1] = 0;

    select0.n_items= 2;
    select0.highlighted_item = 0;
    select0.list_of_item_id = select_string;
    
    caption1.string_id= STR_CURRENCYCONVERTOR_LOCAL;            
    
    textedit2.string_id= 0;
    textedit2.default_text_id = 0;
    textedit2.buffer_size = CCONV_MAX_INPUT + 1;
    textedit2.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
    textedit2.input_extended_type = 0;
    textedit2.required_input_mode_set = NULL;
    
    caption3.string_id= STR_CURRENCYCONVERTOR_FOREIGN;
    
    textedit4.string_id= 0;
    textedit4.default_text_id = 0;
    textedit4.buffer_size = CCONV_MAX_RESULT + 1;
    textedit4.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
    textedit4.input_extended_type = 0;
    textedit4.required_input_mode_set = NULL;
    
    cconv_inline_items[CCONV_INLINE_RATE].item_id = CCONV_SELECT_ID0;
    cconv_inline_items[CCONV_INLINE_RATE].item_flag = CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_LEFT_JUSTIFY;
    cconv_inline_items[CCONV_INLINE_RATE].image_id = 0;
    cconv_inline_items[CCONV_INLINE_RATE].item_data = &select0;
    
    cconv_inline_items[CCONV_INLINE_LOCAL_CAP].item_id = CCONV_CAPTION_ID1;
    cconv_inline_items[CCONV_INLINE_LOCAL_CAP].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
    cconv_inline_items[CCONV_INLINE_LOCAL_CAP].image_id = 0;
    cconv_inline_items[CCONV_INLINE_LOCAL_CAP].item_data = &caption1;
    
    cconv_inline_items[CCONV_INLINE_LOCAL].item_id = CCONV_TEXT_EDIT_ID2;
    cconv_inline_items[CCONV_INLINE_LOCAL].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    cconv_inline_items[CCONV_INLINE_LOCAL].image_id = 0;
    cconv_inline_items[CCONV_INLINE_LOCAL].item_data = &textedit2;
    
    cconv_inline_items[CCONV_INLINE_FORE_CAP].item_id = CCONV_CAPTION_ID3;
    cconv_inline_items[CCONV_INLINE_FORE_CAP].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
    cconv_inline_items[CCONV_INLINE_FORE_CAP].image_id = 0;
    cconv_inline_items[CCONV_INLINE_FORE_CAP].item_data = &caption3;
    
    cconv_inline_items[CCONV_INLINE_FORE].item_id = CCONV_TEXT_EDIT_ID4;
    cconv_inline_items[CCONV_INLINE_FORE].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_DISABLE | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH;
    cconv_inline_items[CCONV_INLINE_FORE].image_id = 0;
    cconv_inline_items[CCONV_INLINE_FORE].item_data = &textedit4;

    inline_struct.items_count = CCONV_INLINE_TOTAL;
    
    inline_struct.title = STR_CURRENCYCONVERTOR_INPUT;    
    inline_struct.title_icon = GetRootTitleIcon(EXTRA_CURRENCYCONVERTOR_MENU);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    inline_struct.softkey = NULL;
    inline_struct.items = cconv_inline_items;
        
    cconv_inline_cui_id = cui_inline_create(
                            GRP_ID_CCONV,
                            &inline_struct);

    cui_inline_set_item_select(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        2,
        (PU8*)g_cconv_cntx->RateList,
        (U8)g_cconv_cntx->CurrSelRate);
    
    cui_inline_set_softkey_text(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        MMI_LEFT_SOFTKEY,
        0);
    cui_inline_set_softkey_icon(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        MMI_LEFT_SOFTKEY,
        0);
    cui_inline_set_softkey_text(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_softkey_icon(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_softkey_text(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        MMI_RIGHT_SOFTKEY,
        STR_GLOBAL_BACK);
    cui_inline_set_softkey_icon(
        cconv_inline_cui_id,
        CCONV_SELECT_ID0,
        MMI_RIGHT_SOFTKEY,
        0);

    cui_inline_run(cconv_inline_cui_id);    
}
#endif /* defined __MMI_CURRENCY_CONVERTER__ */ 
