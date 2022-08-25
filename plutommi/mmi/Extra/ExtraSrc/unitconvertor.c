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
 * Unitconvertor.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Unit Convertor application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**********************************************************************************
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Unitconvertor.c
   Author:        Vandana M
   Date Created:  June-14-2003
   Contains:      Unit Convertor
**********************************************************************************/
#include "MMI_features.h"

#if defined (__MMI_UNIT_CONVERTER__)
#include "unitconvertor.h"
#include "mmi_rp_app_unitconverter_def.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "string.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "ImeGprot.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"

/*  Include: PS header file */

/* 
 * Define
 */
/* Inline CUI Revise */
#define UCONV_SELECT_ID0                   CUI_INLINE_ITEM_ID_BASE + 0
#define UCONV_CAPTION_ID1                  CUI_INLINE_ITEM_ID_BASE + 1
#define UCONV_TEXT_EDIT_ID2              CUI_INLINE_ITEM_ID_BASE + 2
#define UCONV_CAPTION_ID3               CUI_INLINE_ITEM_ID_BASE + 3
#define UCONV_TEXT_EDIT_ID4              CUI_INLINE_ITEM_ID_BASE + 4

#define  UCONV_MAX_RESULT     12        /* 12 digits */
#define  UCONV_MAX_INPUT         8
#if defined (__MMI_UNIT_CONVERTER__)
#define  UCONV_NUM_UNITS         4
#define  KM2MILE              0.62137
#define  M2YARD               1.09361
#define  M2FOOT               3.28084
#define  CM2INCH              0.3937
#define  KG2POUND          2.20462
#define  KG2OUNCE          35.274
#endif 

#ifndef __MTK_TARGET__
#define UCONV_MAX_VALUE          999999999999l
#else 
#define UCONV_MAX_VALUE          999999999999ll
#endif 
#define UCONV_MIN_VALUE          0.0000000001


/* 
 * Typedef 
 */
typedef struct
{
    S32 CurrInlineSelectUnit;
    U8 CurrSelectedItem;
    U8 CurrHiliteUnitType;
    CHAR *UnitList[UCONV_NUM_UNITS];
    U16 MetricBuf[UCONV_MAX_RESULT + 2];
    U16 EngBuf[UCONV_MAX_RESULT + 2];
    MMI_BOOL is_reset;
} uconv_context_struct;

/* 
 * Global Variable
 */
uconv_context_struct *g_uconv_cntx = NULL;


/* 
 * Global Function
 */


/* Local Function */
static void mmi_uconv_deinit(void);
void mmi_uconv_pre_entry_main_menu(void);
static mmi_ret mmi_uconv_cui_event_proc(mmi_event_struct *evt);
static void mmi_uconv_entry_main_menu(void);
static MMI_BOOL mmi_uconv_compute_length_result(void);
static MMI_BOOL mmi_uconv_compute_weight_result(void);
static void mmi_uconv_pre_entry_compute_screen(void);
static void mmi_uconv_entry_compute_screen(void);
static U8 mmi_uconv_del_scr_callback(void *p);
static double mmi_uconv_wsc_to_dbl(U16 *s);
static void mmi_uconv_dbl_to_wsc(U16 *s, double number);
static void mmi_uconv_remove_zero_in_tail(U16 *buffer);

#ifdef __MMI_FTE_SUPPORT__
static void mmi_uconv_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_wsc_to_dbl
 * DESCRIPTION
 *  converter wide string to double
 * PARAMETERS
 *  s :[IN] wide string
 * RETURNS
 *  return double value not check validation.
 *****************************************************************************/
static double mmi_uconv_wsc_to_dbl(U16 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ansii_str[UCONV_MAX_RESULT + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_to_asc(ansii_str, s);
    return atof(ansii_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_dbl_to_wsc
 * DESCRIPTION
 *  converter double to wide string 
 * PARAMETERS
 *  number :[IN] double value
 * RETURNS
 *  return wide string not check validation.
 *****************************************************************************/
static void mmi_uconv_dbl_to_wsc(U16 *s, double number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    CHAR tmp[UCONV_MAX_RESULT * 2], fmt[8];
    CHAR *p;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sprintf(fmt, "%%.%df", (UCONV_MAX_RESULT - 2));
    kal_sprintf(tmp, fmt, number);
    p = strchr((char*)tmp, '.');
    *p = 0;
    len = strlen((char*)tmp);
    if ((UCONV_MAX_RESULT - len - 1) > 0)
    {
        kal_sprintf(fmt, "%%%d.%df", len, (UCONV_MAX_RESULT - len - 1));
        kal_sprintf(tmp, fmt, number);
    }
    else
    {
        kal_sprintf(fmt, "%%%d.%df", len, 0);
        kal_sprintf(tmp, fmt, number);
    }
    mmi_asc_to_wcs(s, tmp);
    mmi_uconv_remove_zero_in_tail(s);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_remove_zero_in_tail
 * DESCRIPTION
 *  remove zero from tail of string 
 * PARAMETERS
 *  buffer :[IN] wide string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_uconv_remove_zero_in_tail(U16 *buffer)
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
 *  mmi_uconv_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Unit Conveter menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_uconv_pre_entry_main_menu, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_uconv_pre_entry_main_menu, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_deinit
 * DESCRIPTION
 *  Free memory and go back to previous screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_uconv_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uconv_cntx)
    {
        OslMfree(g_uconv_cntx);
        g_uconv_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_del_scr_callback
 * DESCRIPTION
 *  Callback function of delete unit converter screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_uconv_del_scr_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ScrID = (SCR_ID_UCONV_WEIGHT + g_uconv_cntx->CurrHiliteUnitType);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == ScrID)
    {
        CloseCategory57Screen();
    }
    mmi_uconv_deinit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_pre_entry_main_menu
 * DESCRIPTION
 *  pre entry function of unit convertor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_pre_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uconv_cntx == NULL)
    {
        g_uconv_cntx = OslMalloc(sizeof(uconv_context_struct));
    }
    if (mmi_frm_group_is_present(GRP_ID_UCONV))
    {
        mmi_frm_group_close(GRP_ID_UCONV);
    }
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UCONV, mmi_uconv_cui_event_proc, NULL);
    mmi_frm_group_enter(GRP_ID_UCONV, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_uconv_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_cui_event_proc
 * DESCRIPTION
 *  proc for unit converter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_uconv_cui_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
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
    /* Menu cui revise */
    menu_evt = (cui_menu_event_struct*)evt;  
    
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == EXTRA_UNITCONVERTOR_MENU)
            { 
                //get_image(GetRootTitleIcon(EXTRA_UNITCONVERTOR_MENU));
                cui_menu_set_default_title_image(
                    menu_evt->sender_id, 
                    get_image(GetRootTitleIcon(EXTRA_UNITCONVERTOR_MENU)));
                    
                cui_menu_set_item_image(
                    menu_evt->sender_id,
                    EXTRA_UNITCONVERTOR_WEIGHT,
                    IMG_GLOBAL_L1);
                cui_menu_set_item_image(
                    menu_evt->sender_id,
                    EXTRA_UNITCONVERTOR_LENGTH,
                    IMG_GLOBAL_L2);
                cui_menu_set_default_left_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_OK));
            }
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            switch (menu_evt->highlighted_menu_id) 
            {
                case EXTRA_UNITCONVERTOR_WEIGHT:
                    g_uconv_cntx->CurrHiliteUnitType = UCONV_WEIGHT;
                    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                    SetCenterSoftkeyFunction(mmi_uconv_pre_entry_compute_screen, KEY_EVENT_UP);                    
                    break;
                case EXTRA_UNITCONVERTOR_LENGTH:
                    g_uconv_cntx->CurrHiliteUnitType = UCONV_LENGTH;
                    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                    SetCenterSoftkeyFunction(mmi_uconv_pre_entry_compute_screen, KEY_EVENT_UP);
                    break;
                default:
                    break;
            }
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case EXTRA_UNITCONVERTOR_WEIGHT:
                    mmi_uconv_pre_entry_compute_screen();
                    break;
                case EXTRA_UNITCONVERTOR_LENGTH:
                    mmi_uconv_pre_entry_compute_screen();
                    break;
                default:
                    break;
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:            
            cui_menu_close(menu_evt->sender_id);
            mmi_uconv_del_scr_callback(NULL);
            break;
        default:
            break;
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
#ifdef __MMI_FTE_SUPPORT__ 
            wgui_register_list_tap_callback(mmi_uconv_tap_callback);            
#endif        
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            
            inline_submit_event = (cui_event_inline_submit_struct*)evt;
            cui_inline_get_value(inline_submit_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);
            cui_inline_get_value(inline_submit_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
            if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
            {
                b = mmi_uconv_compute_weight_result();
            }
            else
            {
                b = mmi_uconv_compute_length_result();
            }
            if (b)    
            {
                cui_inline_lock_main_screen(inline_submit_event->sender_id);
                /* converter edit inline to display inline so it can display a long result */ 
                cui_inline_delete_item(inline_submit_event->sender_id, UCONV_TEXT_EDIT_ID2);
                display_item.string_id = 0;                                    
                set_item.item_id = UCONV_TEXT_EDIT_ID2;                        
                 set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT;
                set_item.image_id = 0;                            
                set_item.item_data = &display_item;
                
                cui_inline_insert_item(inline_submit_event->sender_id, UCONV_CAPTION_ID3, &set_item);
                
                cui_inline_set_value(inline_submit_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);
                

                
                cui_inline_delete_item(inline_submit_event->sender_id, UCONV_TEXT_EDIT_ID4);
                
                //display_item2.string_id = 0;                                      
                set_item.item_id = UCONV_TEXT_EDIT_ID4;                        
                 //set_item2.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH;
                //set_item2.image_id = 0;                            
                //set_item2.item_data = &display_item2;
                cui_inline_insert_item(inline_submit_event->sender_id, CUI_INLINE_INSERT_TAIL, &set_item);
                
                cui_inline_set_value(inline_submit_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                                            
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
                g_uconv_cntx->is_reset = MMI_TRUE;
                cui_inline_unlock_main_screen(inline_submit_event->sender_id);
                cui_inline_redraw_screen(inline_submit_event->sender_id);
            }
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            if (g_uconv_cntx->is_reset)
            {
                cui_inline_lock_main_screen(inline_abort_event->sender_id);
                mmi_wcscpy((WCHAR*)g_uconv_cntx->MetricBuf, L"");
                mmi_wcscpy((WCHAR*)g_uconv_cntx->EngBuf, L"");
                //cui_inline_set_value(inline_abort_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);
                //cui_inline_set_value(inline_abort_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                //delete and insert
                cui_inline_delete_item(inline_abort_event->sender_id, UCONV_TEXT_EDIT_ID2);

                textedit_item.string_id= 0;
                textedit_item.default_text_id = 0;
                textedit_item.buffer_size = UCONV_MAX_INPUT + 1;
                textedit_item.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
                textedit_item.input_extended_type = 0;
                textedit_item.required_input_mode_set = NULL;
                
                set_item.item_id = UCONV_TEXT_EDIT_ID2;                     
                set_item.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
                set_item.image_id = 0;                            
                set_item.item_data = &textedit_item;
                
                cui_inline_insert_item(inline_abort_event->sender_id, UCONV_CAPTION_ID3, &set_item);
                cui_inline_set_value(inline_abort_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);

                cui_inline_delete_item(inline_abort_event->sender_id, UCONV_TEXT_EDIT_ID4);
                
                //textedit_item.string_id= 0;
                //textedit_item.default_text_id = 0;
                //textedit_item.buffer_size = UCONV_MAX_INPUT + 1;
                //textedit_item.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
                //textedit_item.input_extended_type = 0;
                //textedit_item.required_input_mode_set = NULL;
                
                set_item.item_id = UCONV_TEXT_EDIT_ID4;                     
                //set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH;
                //set_item.image_id = 0;                            
                //set_item.item_data = &textedit_item;
                cui_inline_insert_item(inline_abort_event->sender_id, CUI_INLINE_INSERT_TAIL, &set_item);
                cui_inline_set_value(inline_abort_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                //cui_inline_set_highlight_idx(inline_notify_event->item_id);
                cui_inline_set_highlight_item(inline_abort_event->sender_id, inline_abort_event->item_id);
                //g_uconv_cntx->is_reset = MMI_FALSE;
                
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
                /*cui_inline_set_item_attributes(
                    inline_abort_event->sender_id,
                    inline_abort_event->item_id,
                    CUI_INLINE_RESET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DISABLE_CURSOR);*/
                g_uconv_cntx->is_reset = MMI_FALSE;
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
            cui_inline_get_value(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);
            cui_inline_get_value(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
            if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
            {
                b = mmi_uconv_compute_weight_result();
            }
            else
            {
                b = mmi_uconv_compute_length_result();
            }
            if (b)    
            {
                cui_inline_lock_main_screen(inline_csk_press_event->sender_id);
                //cui_inline_set_value(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);
                //cui_inline_set_value(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                /* converter edit inline to display inline so it can display a long result */ 
                cui_inline_delete_item(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID2);
    
                display_item.string_id = 0;                                 
                set_item.item_id = UCONV_TEXT_EDIT_ID2;                     
                set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY  | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT;
                set_item.image_id = 0;                            
                set_item.item_data = &display_item;
                
                cui_inline_insert_item(inline_csk_press_event->sender_id, UCONV_CAPTION_ID3, &set_item);
                cui_inline_set_value(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);

                cui_inline_delete_item(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID4);
                //display_item.string_id = 0;                                 
                set_item.item_id = UCONV_TEXT_EDIT_ID4;                     
                //set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH;
                //set_item.image_id = 0;                            
                //set_item.item_data = &display_item;
                cui_inline_insert_item(inline_csk_press_event->sender_id, CUI_INLINE_INSERT_TAIL, &set_item);
                cui_inline_set_value(inline_csk_press_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                //cui_inline_set_highlight_idx(inline_submit_event->item_id);
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
                /*cui_inline_set_item_attributes(
                    inline_csk_press_event->sender_id,
                    inline_csk_press_event->item_id,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DISABLE_CURSOR);*/
                g_uconv_cntx->is_reset = MMI_TRUE;
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
                    if (inline_notify_event->item_id == UCONV_SELECT_ID0)
                    {
                        g_uconv_cntx->CurrInlineSelectUnit = (U8)inline_notify_event->param;
                        if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
                        {
                            cui_inline_set_value(
                                inline_notify_event->sender_id, 
                                UCONV_CAPTION_ID1, 
                                (GetString(STR_UNITCONVERTOR_KG)));
                            
                            if (inline_notify_event->param == 0) /* Kg <-> Pound */
                            {
                                cui_inline_set_value(
                                    inline_notify_event->sender_id, 
                                    UCONV_CAPTION_ID3, 
                                    (GetString(STR_UNITCONVERTOR_POUND)));
                            }
                            else
                            {
                                cui_inline_set_value(
                                    inline_notify_event->sender_id, 
                                    UCONV_CAPTION_ID3, 
                                    (GetString(STR_UCONV_OUNCE)));
                            }

                            cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID2, NULL);
                            cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID4, NULL);
                            
                        }
                        else
                        {                                                
                            cui_inline_set_value(
                                inline_notify_event->sender_id, 
                                UCONV_CAPTION_ID3, 
                                (GetString(STR_UNITCONVERTOR_MILE + g_uconv_cntx->CurrInlineSelectUnit)));
                            
                            switch (inline_notify_event->param)
                            {
                                case 0:
                                    cui_inline_set_value(
                                        inline_notify_event->sender_id, 
                                        UCONV_CAPTION_ID1, 
                                        (GetString(STR_UNITCONVERTOR_KM)));
                                    break;
                                case 3:
                                    cui_inline_set_value(
                                        inline_notify_event->sender_id, 
                                        UCONV_CAPTION_ID1, 
                                        (GetString(STR_UNITCONVERTOR_CM)));
                                    break;
                                default:
                                    cui_inline_set_value(
                                        inline_notify_event->sender_id, 
                                        UCONV_CAPTION_ID1, 
                                        (GetString(STR_UNITCONVERTOR_METER)));
                                    break;
                            }

                            cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID2, NULL);
                            cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID4, NULL);
                        }
                    }
                    break;

                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    switch (inline_notify_event->item_id)
                    {
                        case UCONV_SELECT_ID0:
                            curr_hilite_index = 0;
                            break;
                        case UCONV_TEXT_EDIT_ID2:
                        //case UCONV_DISPLAY_ID2:
                            curr_hilite_index = 2;
                            break;
                        case UCONV_TEXT_EDIT_ID4:
                        //case UCONV_DISPLAY_ID4:
                            curr_hilite_index = 4;
                            break;
                        default:
                            break;
                    }
                    if ((U8)curr_hilite_index != g_uconv_cntx->CurrSelectedItem)
                    {
                        cui_inline_lock_main_screen(inline_notify_event->sender_id);
                        mmi_wcscpy((WCHAR*)g_uconv_cntx->MetricBuf, L"");
                        mmi_wcscpy((WCHAR*)g_uconv_cntx->EngBuf, L"");
                        if (g_uconv_cntx->is_reset)
                        {
                            
                            //delete and insert
                            cui_inline_delete_item(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID2);
    
                            textedit_item.string_id= 0;
                            textedit_item.default_text_id = 0;
                            textedit_item.buffer_size = UCONV_MAX_INPUT + 1;
                            textedit_item.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
                            textedit_item.input_extended_type = 0;
                            textedit_item.required_input_mode_set = NULL;
                            
                            set_item.item_id = UCONV_TEXT_EDIT_ID2;                     
                            set_item.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
                            set_item.image_id = 0;                            
                            set_item.item_data = &textedit_item;
                            
                            cui_inline_insert_item(inline_notify_event->sender_id, UCONV_CAPTION_ID3, &set_item);
                            //cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);

                            cui_inline_delete_item(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID4);
                            
                            /*textedit_item.string_id= 0;
                            textedit_item.default_text_id = 0;
                            textedit_item.buffer_size = UCONV_MAX_INPUT + 1;
                            textedit_item.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
                            textedit_item.input_extended_type = 0;
                            textedit_item.required_input_mode_set = NULL;*/
                            
                            set_item.item_id = UCONV_TEXT_EDIT_ID4;                     
                            //set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH;
                            //set_item.image_id = 0;                            
                            //set_item.item_data = &textedit_item;
                            cui_inline_insert_item(inline_notify_event->sender_id, CUI_INLINE_INSERT_TAIL, &set_item);
                            //cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                            //cui_inline_set_highlight_idx(inline_notify_event->item_id);
                            g_uconv_cntx->is_reset = MMI_FALSE;
                        }
                        
                        if(inline_notify_event->item_id != UCONV_SELECT_ID0)
                        {
                            cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID2, g_uconv_cntx->MetricBuf);
                            cui_inline_set_value(inline_notify_event->sender_id, UCONV_TEXT_EDIT_ID4, g_uconv_cntx->EngBuf);
                            //memset(g_uconv_cntx->MetricBuf, 0, 2);
                            //memset(g_uconv_cntx->EngBuf, 0, 2);
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
                                            
                        g_uconv_cntx->CurrSelectedItem = (U8)curr_hilite_index;
                        cui_inline_set_highlight_item(inline_notify_event->sender_id, inline_notify_event->item_id);
                        cui_inline_unlock_main_screen(inline_notify_event->sender_id);
                        cui_inline_redraw_screen(inline_notify_event->sender_id);
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
 *  mmi_uconv_entry_main_menu
 * DESCRIPTION
 *  Entry function of unit convertor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_uconv_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_id uconv_menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uconv_menu_cui_id = cui_menu_create(
        GRP_ID_UCONV, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_APPMAIN, 
        EXTRA_UNITCONVERTOR_MENU, 
        MMI_TRUE, 
        NULL);
    cui_menu_run(uconv_menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_pre_entry_compute_screen
 * DESCRIPTION
 *  Intialize state variables and enter weight convertor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_uconv_pre_entry_compute_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->is_reset = MMI_FALSE;
    g_uconv_cntx->CurrInlineSelectUnit = 0;
    g_uconv_cntx->CurrSelectedItem = 0;
    memset(g_uconv_cntx->EngBuf, 0, 2);
    memset(g_uconv_cntx->MetricBuf, 0, 2);
    mmi_uconv_entry_compute_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_entry_compute_screen
 * DESCRIPTION
 *  Entry function of conterting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_uconv_entry_compute_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    U16 select_string[4];
    cui_inline_item_select_struct select0;
    cui_inline_item_caption_struct caption1;
    cui_inline_item_text_edit_struct textedit2;
    cui_inline_item_caption_struct caption3;
    cui_inline_item_text_edit_struct textedit4;
    cui_inline_set_item_struct uconv_inline_items[UCONV_INLINE_TOTAL];
    cui_inline_struct inline_struct;
    mmi_id  uconv_inline_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cui inline struct define */
    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
    {
        select_string[0] = STR_UNITCONVERTOR_KGPOUND;
        select_string[1] = STR_UCONV_KGOUNCE;
        
        select0.n_items= 2;
        select0.highlighted_item = 0;
        select0.list_of_item_id = select_string;

        caption1.string_id= STR_UNITCONVERTOR_KG;

        caption3.string_id= STR_UNITCONVERTOR_POUND;
    }
    else
    {

        select_string[0] = STR_UNITCONVERTOR_KMMILE;
        select_string[1] = STR_UNITCONVERTOR_MYARD;
        select_string[2] = STR_UNITCONVERTOR_MFOOT;
        select_string[3] = STR_UNITCONVERTOR_CMINCH;
        
        select0.n_items= 4;
        select0.highlighted_item = 0;
        select0.list_of_item_id = select_string;

        caption1.string_id= STR_UNITCONVERTOR_KM;

        caption3.string_id= STR_UNITCONVERTOR_MILE;        
    }
    
    textedit2.string_id= 0;
    textedit2.default_text_id = 0;
    textedit2.buffer_size = UCONV_MAX_INPUT + 1;
    textedit2.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
    textedit2.input_extended_type = 0;
    textedit2.required_input_mode_set = NULL;
    
    textedit4.string_id= 0;
    textedit4.default_text_id = 0;
    textedit4.buffer_size = UCONV_MAX_INPUT + 1;
    textedit4.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
    textedit4.input_extended_type = 0;
    textedit4.required_input_mode_set = NULL;
    
    uconv_inline_items[0].item_id = UCONV_SELECT_ID0;
    uconv_inline_items[0].item_flag = CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_LEFT_JUSTIFY;
    uconv_inline_items[0].image_id = 0;
    uconv_inline_items[0].item_data = &select0;
    
    uconv_inline_items[1].item_id = UCONV_CAPTION_ID1;
    uconv_inline_items[1].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
    uconv_inline_items[1].image_id = 0;
    uconv_inline_items[1].item_data = &caption1;
    
    uconv_inline_items[2].item_id = UCONV_TEXT_EDIT_ID2;
    uconv_inline_items[2].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    uconv_inline_items[2].image_id = 0;
    uconv_inline_items[2].item_data = &textedit2;
    
    uconv_inline_items[3].item_id = UCONV_CAPTION_ID3;
    uconv_inline_items[3].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
    uconv_inline_items[3].image_id = 0;
    uconv_inline_items[3].item_data = &caption3;
    
    uconv_inline_items[4].item_id = UCONV_TEXT_EDIT_ID4;
    uconv_inline_items[4].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    uconv_inline_items[4].image_id = 0;
    uconv_inline_items[4].item_data = &textedit4;

    inline_struct.items_count = UCONV_INLINE_TOTAL;
    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_LENGTH)
    {
        inline_struct.title = STR_UNITCONVERTOR_LENGTH;
    }
    else
    {
        inline_struct.title = STR_UNITCONVERTOR_WEIGHT;
    }
    
    inline_struct.title_icon = GetRootTitleIcon(EXTRA_UNITCONVERTOR_MENU);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    inline_struct.softkey = NULL;
    inline_struct.items = uconv_inline_items;
        
    uconv_inline_cui_id = cui_inline_create(
                            GRP_ID_UCONV,
                            &inline_struct);

    cui_inline_set_softkey_text(
        uconv_inline_cui_id,
        UCONV_SELECT_ID0,
        MMI_LEFT_SOFTKEY,
        0);
    cui_inline_set_softkey_icon(
        uconv_inline_cui_id,
        UCONV_SELECT_ID0,
        MMI_LEFT_SOFTKEY,
        0);
    cui_inline_set_softkey_text(
        uconv_inline_cui_id,
        UCONV_SELECT_ID0,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_softkey_icon(
        uconv_inline_cui_id,
        UCONV_SELECT_ID0,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_softkey_text(
        uconv_inline_cui_id,
        UCONV_SELECT_ID0,
        MMI_RIGHT_SOFTKEY,
        STR_GLOBAL_BACK);
    cui_inline_set_softkey_icon(
        uconv_inline_cui_id,
        UCONV_SELECT_ID0,
        MMI_RIGHT_SOFTKEY,
        0);
    
    cui_inline_run(uconv_inline_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_compute_length_result
 * DESCRIPTION
 *  To calculate the result of length conversion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_uconv_compute_length_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE conversion_factor;
    DOUBLE result;
    U16 *ResultBuf = NULL, *SourceBuf = NULL;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    /* conversion rate */
    switch (g_uconv_cntx->CurrInlineSelectUnit)
    {
        case 0:
            conversion_factor = KM2MILE;    /* 0.62137 */
            break;
        case 1:
            conversion_factor = M2YARD;     /* 1.09361 */
            break;
        case 2:
            conversion_factor = M2FOOT;     /* 3.28084 */
            break;
        default:                            /* case 3: */
            conversion_factor = CM2INCH;    /* 0.3937 */
            break;
    }

    if (g_uconv_cntx->CurrSelectedItem == UCONV_METIRC)
    {
        SourceBuf = g_uconv_cntx->MetricBuf;
        ResultBuf = g_uconv_cntx->EngBuf;
    }
    else
    {
        SourceBuf = g_uconv_cntx->EngBuf;
        ResultBuf = g_uconv_cntx->MetricBuf;
        conversion_factor = 1 / conversion_factor;
    }

    len = mmi_wcslen((U16*) SourceBuf);
    if (len == 0)
    {
        //mmi_display_popup_with_sg(GRP_ID_UCONV, (U16*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_ERROR, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_ERROR, GRP_ID_UCONV, NULL);
        return MMI_FALSE;
    }
    if (SourceBuf[0] == 46)
    {
        //mmi_display_popup_with_sg(GRP_ID_UCONV, (U16*)GetString(UC_ERROR_WRONG_STRING), MMI_EVENT_ERROR, 0);
        mmi_popup_display_simple((UI_string_type)GetString(UC_ERROR_WRONG_STRING), MMI_EVENT_ERROR, GRP_ID_UCONV, NULL);
        return MMI_FALSE;

    }

    result = (DOUBLE) (conversion_factor * mmi_uconv_wsc_to_dbl((U16*)SourceBuf));
    mmi_uconv_dbl_to_wsc((U16*)ResultBuf, result);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_compute_weight_result
 * DESCRIPTION
 *  To calculate the result of weight conversion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_uconv_compute_weight_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE result = 0;
    DOUBLE conversion_factor = 0;
    U16 *ResultBuf = NULL, *SourceBuf = NULL;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* determine rate */
    if (g_uconv_cntx->CurrInlineSelectUnit == 0)    /* Kg to Pound */
    {
        conversion_factor = KG2POUND;
    }
    else
    {
        conversion_factor = KG2OUNCE;
    }

    /* determine conversion direction */
    if (g_uconv_cntx->CurrSelectedItem == UCONV_METIRC)
    {
        SourceBuf = g_uconv_cntx->MetricBuf;
        ResultBuf = g_uconv_cntx->EngBuf;
    }
    else    /* UCONV_ENGLISH */
    {
        SourceBuf = g_uconv_cntx->EngBuf;
        ResultBuf = g_uconv_cntx->MetricBuf;
        conversion_factor = 1 / conversion_factor;
    }

    len = mmi_wcslen((U16*) SourceBuf);

    if (len == 0)
    {
        //mmi_display_popup_with_sg(GRP_ID_UCONV, (U16*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_ERROR, 0);
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_ERROR, GRP_ID_UCONV, NULL);

        return MMI_FALSE;
    }
    if (SourceBuf[0] == 46)
    {
        
        //mmi_display_popup_with_sg(GRP_ID_UCONV, (U16*)GetString(UC_ERROR_WRONG_STRING), MMI_EVENT_ERROR, 0);
        mmi_popup_display_simple((UI_string_type)GetString(UC_ERROR_WRONG_STRING), MMI_EVENT_ERROR, GRP_ID_UCONV, NULL);
        return MMI_FALSE;

    }

    result = (DOUBLE) (conversion_factor * mmi_uconv_wsc_to_dbl((U16*)SourceBuf));

    mmi_uconv_dbl_to_wsc((U16*)ResultBuf, result);
    return MMI_TRUE;
}
#endif /* defined (__MMI_UNIT_CONVERTER__) */ 
