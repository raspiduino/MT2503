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
 *  ZakatCalculator.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements Zakat Calculator.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**************************************************************/

#include "MMI_features.h"

#ifdef __MMI_ZAKAT_CALCULATOR__

#include <math.h>

#include "mmi_rp_app_zakat_calculator_def.h"
#include "ZakatCalculator.h"

#include "menucuigprot.h"
#include "InlineCuiGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "nvram_enums.h"
#include "ImeGprot.h"
#include "wgui_touch_screen.h"
#include "string.h"
#include "nvram_common_defs.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "wgui_categories_text_viewer.h"
#include "gui_typedef.h"
#include "wgui_categories.h"
#include "mmi_frm_nvram_gprot.h"
#include "DebugInitDef_Int.h"
#include "CommonScreensResDef.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "stdlib.h"

/* 
 * Typedef
 */

typedef struct
{
    double amount;
    double calculate_result;
    double small_items_amount;
    double nisab;
    U32 curr_data_index;
    S32 highlighted_item;
    MMI_ID main_gid;
    mmi_id main_menu_id;
    MMI_ID cattle_gid;
    mmi_id cattle_menu_id;
    MMI_ID agriculture_gid;
    mmi_id agriculture_menu_id;
    MMI_ID bullion_cash_gid;
    mmi_id bullion_cash_menu_id;
    MMI_ID inline_gid;
    mmi_id inline_id;
    U16 input_buffer_1[MMI_ZAKAT_MAX_NUMBER_LENGTH + 1];
    U16 input_buffer_2[MMI_ZAKAT_MAX_NUMBER_LENGTH + 1];
    U16 disp_payable[MMI_ZAKAT_DETAIL_MAX_SENTENCE_LENGTH * 3 + 1];
    U16 disp_amount[MMI_ZAKAT_MAX_NUMBER_LENGTH + 1];
    U16 disp_calculate_result[MMI_ZAKAT_MAX_CALCULATE_RESULT_LENGTH + 1];
    mmi_zakat_operation_enum operation_flag;
    MMI_BOOL highlight_flag;
    nvram_lid_enum lid;
} mmi_zakat_context_struct;

/*
 * Variable
 */

mmi_zakat_context_struct g_mmi_zakat_cntx;
mmi_zakat_context_struct *mmi_zakat_cntx_p;

mmi_imm_input_mode_enum input_mode = IMM_INPUT_MODE_NONE;

static const cui_inline_item_caption_struct first_caption =
{
    STR_ID_ZAKAT_NISAB_GOLD
};

static const cui_inline_item_caption_struct second_caption =
{
    STR_ID_ZAKAT_NISAB_SILVER
};

static const cui_inline_item_caption_struct third_caption =
{
    STR_ID_ZAKAT_TOTAL_AMOUNT
};

static const cui_inline_item_caption_struct fourth_caption =
{
    STR_ID_ZAKAT_PAYABLE
};

static const cui_inline_item_display_only_struct first_disp_only =
{
    STR_ID_ZAKAT_PAYABLE
};

static const cui_inline_item_display_only_struct second_disp_only =
{
    STR_ID_ZAKAT_PAYABLE
};

static const cui_inline_item_display_only_struct third_disp_only =
{
    STR_ID_ZAKAT_PAYABLE
};

static const cui_inline_item_display_only_struct fourth_disp_only =
{
    STR_ID_ZAKAT_PAYABLE
};

static const cui_inline_item_multiline_rdonly_struct multi_rdonly =
{
    0,
    4
};

static const cui_inline_item_text_edit_struct first_text_edit =
{
    0,
    0,
    MMI_ZAKAT_MAX_NUMBER_LENGTH + 1,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    &input_mode
};

static const cui_inline_item_text_edit_struct second_text_edit =
{
    0,
    0,
    MMI_ZAKAT_MAX_NUMBER_LENGTH + 1,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    &input_mode
};

static const cui_inline_set_item_struct first_ok_inline_item =
{
    CUI_INLINE_ITEM_ID_BASE + 8,
    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_FULL_WIDTH |
    CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_BOUNDARY |
    CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
    0,
    (void*)&first_disp_only
};

static const cui_inline_set_item_struct second_ok_inline_item =
{
    CUI_INLINE_ITEM_ID_BASE + 9,
    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_FULL_WIDTH |
    CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_BOUNDARY |
    CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
    0,
    (void*)&second_disp_only
};

static const cui_inline_set_item_struct first_reset_inline_item =
{
    CUI_INLINE_ITEM_ID_BASE + 1,
    CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_FULL_WIDTH |
    CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_BOUNDARY,
    0,
    (void*)&first_text_edit
};

static const cui_inline_set_item_struct second_reset_inline_item =
{
    CUI_INLINE_ITEM_ID_BASE + 3,
    CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_FULL_WIDTH |
    CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_BOUNDARY,
    0,
    (void*)&second_text_edit
};

static const cui_inline_set_item_struct zakat_nisab_items[MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT] =
{
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_GOLD_PRICE_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_GOLD_PRICE_INFO,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_text_edit
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_SILVER_PRICE_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_SILVER_PRICE_INFO,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_text_edit
    }
};

static const cui_inline_set_item_struct zakat_cattle_items[MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT] =
{
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_INPUT_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_INPUT_INFO,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_text_edit
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_DISP_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_DISP_INFO,
        CUI_INLINE_ITEM_TYPE_MULTILINE_RD_ONLY | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&multi_rdonly
    }
};

static const cui_inline_set_item_struct zakat_common_items[MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT] =
{
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_INPUT_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_INPUT_INFO,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_text_edit
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_DISP_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_COMMON_DISP_INFO,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH |
        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&second_disp_only
    }
};

static const cui_inline_set_item_struct zakat_gold_items[MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT] =
{
    {
        CUI_INLINE_ITEM_ID_BASE + 0,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_text_edit
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 2,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 3,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_text_edit
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 4,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&third_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 5,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH |
        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&third_disp_only
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 6,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&fourth_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 7,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH |
        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&fourth_disp_only
    }
};

static const cui_inline_set_item_struct zakat_silver_items[MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT] =
{
    {
        CUI_INLINE_ITEM_ID_BASE + 0,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&first_text_edit
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 2,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&second_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 3,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH |
        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&second_disp_only
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 4,
        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH,
        0,
        (void*)&third_caption
    },
    {
        CUI_INLINE_ITEM_ID_BASE + 5,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_BOUNDARY |
        CUI_INLINE_ITEM_RIGHT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH |
        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&third_disp_only
    }
};

static const cui_inline_struct zakat_cattle_input =
{
    MMI_ZAKAT_COMMON_INPUT_INLINE_ITEM_COUNT,
    STR_ID_ZAKAT_NISAB,
    IMG_ID_ZAKAT_ICON,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    zakat_cattle_items
};

static const cui_inline_struct zakat_nisab_input =
{
    MMI_ZAKAT_NISAB_INLINE_ITEM_COUNT,
    STR_ID_ZAKAT_NISAB,
    IMG_ID_ZAKAT_ICON,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    zakat_nisab_items
};

static const cui_inline_struct zakat_common_input =
{
    MMI_ZAKAT_NISAB_INLINE_ITEM_COUNT,
    STR_ID_ZAKAT_NISAB,
    IMG_ID_ZAKAT_ICON,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    zakat_common_items
};

static const cui_inline_struct zakat_gold_input =
{
    MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT,
    STR_ID_ZAKAT_NISAB,
    IMG_ID_ZAKAT_ICON,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    zakat_gold_items
};

static const cui_inline_struct zakat_silver_input =
{
    MMI_ZAKAT_24K_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT,
    STR_ID_ZAKAT_NISAB,
    IMG_ID_ZAKAT_ICON,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    zakat_silver_items
};

/*
 * Entry function
 */

void mmi_zakat_entry_main(void);
static void mmi_zakat_entry_description(void);
static void mmi_zakat_entry_cattle_input(void);
static void mmi_zakat_entry_common_input(void);
static void mmi_zakat_pre_entry_24K_gold_silver_input(void);
static void mmi_zakat_entry_gold_input(void);
static void mmi_zakat_entry_silver_input(void);
static void mmi_zakat_entry_nisab(void);
static void mmi_zakat_entry_payable(void);
static void mmi_zakat_entry_detail(void);

/* 
 * Other function 
 */

static void mmi_zakat_input_LSK_calculate(void);
static void mmi_zakat_input_LSK_save(void);
static void mmi_zakat_input_RSK_reset(void);
static void mmi_zakat_read_data_from_nvram(U32 index, U16 *buffer, double *dataPtr);
static void mmi_zakat_write_data_to_nvram(U32 index, S8 *buffer);
static void mmi_zakat_get_description_screen_info(U16 *title, U16 *description, void (**f) (void));
static void mmi_zakat_reset_confirm(void);
static void mmi_zakat_save(void);
static S32 mmi_zakat_get_common_input_title(void);
static S32 mmi_zakat_get_gold_silver_input_title(void);

static void mmi_zakat_calculate_camels_payable(U16 *outBuffer, U16 *inBuffer);
static void mmi_zakat_calculate_cows_payable(U16 *outBuffer, U16 *inBuffer);
static void mmi_zakat_calculate_sheep_payable(U16 *outBuffer, U16 *inBuffer);
static void mmi_zakat_calculate_gold_silver_payable(U16 *outBuffer1, U16 *outBuffer2, U16 *inBuffer1, U16 *inBuffer2);
static void mmi_zakat_calculate_common_nisab_item_payable(U16 *outBuffer, U16 *inBuffer);
static void mmi_zakat_calculate_common_no_nisab_item_payable(U32 index, U16 *outBuffer, U16 *inBuffer);
static void mmi_zakat_calcualte_operation(void);

static void mmi_zakat_reset(void);

static void mmi_zakat_construct_payable(void);
static void mmi_zakat_construct_detail(void);

static void mmi_zakat_double_2_string(U16 *buffer, double number);
static void mmi_zakat_string_2_double(U16 *buffer, double *numberPtr);
static S32 mmi_zakat_input_valid_test(void);
static void mmi_zakat_remove_zero_in_tail(U16 *buffer);

#ifdef __MMI_FTE_SUPPORT__
static void mmi_zakat_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */

static void mmi_zakat_entry_cattle(void);
static void mmi_zakat_entry_agriculture(void);
static void mmi_zakat_entry_bullion_cash(void);

static void mmi_zakat_change_softkey(mmi_id gid, U16 index, MMI_BOOL calculate);




/* 
 * Initialize
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_init
 * DESCRIPTION
 *  initialization function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_zakat_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double data1;
    double data2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p = &g_mmi_zakat_cntx;
    memset(mmi_zakat_cntx_p, 0, sizeof(mmi_zakat_context_struct));
    mmi_zakat_cntx_p->lid = NVRAM_EF_ZAKAT_CALCULATOR_LID;
    mmi_zakat_read_data_from_nvram(MMI_ZAKAT_24_CARAT_PRICE, NULL, &data1);
    mmi_zakat_read_data_from_nvram(MMI_ZAKAT_SILVER_PRICE, NULL, &data2);
    if (data1 > 0 && data2 > 0)
    {
        data1 *= MMI_ZAKAT_GOLD_NISAB_GMS;
        data2 *= MMI_ZAKAT_SILVER_NISAB_GMS;
        mmi_zakat_cntx_p->nisab = data1 < data2 ? data1 : data2;
        /* to cover the limitation of double data */
        mmi_zakat_cntx_p->nisab -= MMI_ZAKAT_DOUBLE_ADJUST;
    }
    else
    {
        mmi_zakat_cntx_p->nisab = 0;
    }
    mmi_zakat_cntx_p->highlighted_item = 1;
    mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_INITIALIZE;
}

/* 
 * Highlight handler 
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculator_hilite_hdlr
 * DESCRIPTION
 *  hilite handler of main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_zakat_calculator_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_zakat_entry_main, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_zakat_entry_main, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
}


/*
 * Entry function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_description
 * DESCRIPTION
 *  entry function of description screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_description(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title;
    U16 description;
    void(*entryFunction)(void);
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_DEDUCTIONS_BUSINESS &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_DEDUCTIONS_OTHERS &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_CAMELS &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_COWS &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_SHEEP &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_BURIED_TREASURES &&
        mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_AGRICULTURE)
    {
        if (mmi_zakat_cntx_p->nisab == 0)
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_ID_ZAKAT_NISAB_EMPTY_WARNING),
                MMI_EVENT_FAILURE,
                mmi_zakat_cntx_p->main_gid,
                NULL);
            return;
        }
    }

    /* get title, description and LSK fucntion of description screen */
    mmi_zakat_get_description_screen_info(&title, &description, &entryFunction);

    mmi_frm_scrn_enter(
        mmi_zakat_cntx_p->main_gid,
        SCR_ID_ZAKAT_DESCRIPTION,
        NULL,
        mmi_zakat_entry_description,
        MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_CATTLE)
    {
        kal_wsprintf(
            (WCHAR*)mmi_zakat_cntx_p->disp_payable,
            "%w%w%w%w",
            GetString(STR_ID_ZAKAT_DESCRIPTION_CAMELS_ONE),
            GetString(STR_ID_ZAKAT_DESCRIPTION_CAMELS_TWO),
            GetString(STR_ID_ZAKAT_DESCRIPTION_COWS),
            GetString(STR_ID_ZAKAT_DESCRIPTION_SHEEP));
    }
    else
    {
        kal_wsprintf(
            (WCHAR*)mmi_zakat_cntx_p->disp_payable,
            "%w",
            GetString(description));
    }

    ShowCategory7Screen(
        title,
        GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR),
        STR_GLOBAL_CONTINUE,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*)mmi_zakat_cntx_p->disp_payable,
        gui_buffer);

    SetLeftSoftkeyFunction(entryFunction, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(entryFunction, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
}


void mmi_zakat_cattle_inline_notify_handle(void *evt)
{
    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
    switch (notify_evt->event_type)
    {
    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        if (notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 3 &&
            mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
        {
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_icon( mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
        }
        break;
    }
}


void mmi_zakat_cattle_inline_submit_handle(void *evt)
{
    if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
        mmi_zakat_input_LSK_calculate();
        if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
        {
			cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_calculate_result);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_TRUE);
            cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, (void*)&first_ok_inline_item);
            cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
            cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 8, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 3, MMI_TRUE);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 8,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 3,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
			cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
        }
    }
    else if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
        mmi_zakat_input_LSK_save();
    }
}


S32 mmi_zakat_cattle_inline_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_zakat_cattle_inline_submit_handle(event);
            break;
        }
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_zakat_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
        break;
    case EVT_ID_CUI_INLINE_ABORT:
        {
            if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
            {
                cui_inline_close(mmi_zakat_cntx_p->inline_id);
            }
            else
            {
                cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
                mmi_zakat_input_RSK_reset();
                cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, (void*)&first_reset_inline_item);
                cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
                cui_inline_set_item_attributes(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 1,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_NO_LEADING_ZERO);
                cui_inline_set_input_method(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, IMM_INPUT_TYPE_NUMERIC, &input_mode, 0);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
                cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_calculate_result);
                mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_FALSE);
                cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
                cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
                cui_inline_set_softkey_icon(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 3,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
                cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
            }
            break;
        }
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            mmi_zakat_cattle_inline_notify_handle(event); 
            break;
        }
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_cattle_input
 * DESCRIPTION
 *  entry function of common input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_cattle_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->inline_gid = mmi_frm_group_create(
                                    GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_zakat_cattle_inline_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(
        mmi_zakat_cntx_p->inline_gid,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->inline_id = cui_inline_create(
                                    mmi_zakat_cntx_p->inline_gid,
                                    &zakat_cattle_input);

    cui_inline_set_title_icon(mmi_zakat_cntx_p->inline_id, GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR));
    cui_inline_set_title_string(mmi_zakat_cntx_p->inline_id, (UI_string_type)GetString((U16)mmi_zakat_get_common_input_title()));
    mmi_zakat_read_data_from_nvram(mmi_zakat_cntx_p->curr_data_index, mmi_zakat_cntx_p->input_buffer_1, NULL);
    if (mmi_zakat_cntx_p->input_buffer_1[0] == 0)
    {
        mmi_zakat_cntx_p->disp_calculate_result[0] = 0;
    }
    else
    {
        mmi_zakat_calcualte_operation();
    }
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 0, GetString(STR_ID_ZAKAT_TOTAL_COUNT));
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 2, GetString(STR_ID_ZAKAT_PAYABLE)); 
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_calculate_result);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_softkey_icon(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_input_method(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, IMM_INPUT_TYPE_NUMERIC, &input_mode, 0);
    cui_inline_run(mmi_zakat_cntx_p->inline_id);
}


void mmi_zakat_common_inline_notify_handle(void *evt)
{
    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
    switch (notify_evt->event_type)
    {
    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        if (notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 3 &&
            mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
        {
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_icon( mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
        }
        break;
    }
}


void mmi_zakat_common_inline_submit_handle(void *evt)
{
    if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
        mmi_zakat_input_LSK_calculate();
        if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
        {
            cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_calculate_result);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_TRUE);
            cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, (void*)&first_ok_inline_item);
            cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
            cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 8, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 3, MMI_TRUE);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 8,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 3,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
        }
    }
    else if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
        mmi_zakat_input_LSK_save();
    }
}


S32 mmi_zakat_common_inline_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_zakat_common_inline_submit_handle(event);
            break;
        }
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_zakat_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
        break;
    case EVT_ID_CUI_INLINE_ABORT:
        {
            if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
            {
                cui_inline_close(mmi_zakat_cntx_p->inline_id);
            }
            else
            {
                cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
                mmi_zakat_input_RSK_reset();
                cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, (void*)&first_reset_inline_item);
                cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
                cui_inline_set_item_attributes(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 1,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_NO_LEADING_ZERO);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_calculate_result);
                cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
                mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_FALSE);
				cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
				cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
                cui_inline_set_softkey_icon(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 3,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
                cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
            }
            break;
        }
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            mmi_zakat_common_inline_notify_handle(event); 
            break;
        }
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_common_input
 * DESCRIPTION
 *  entry function of common input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_common_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->inline_gid = mmi_frm_group_create(
                                    GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_zakat_common_inline_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(
        mmi_zakat_cntx_p->inline_gid,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_zakat_cntx_p->inline_id = cui_inline_create(
                                    mmi_zakat_cntx_p->inline_gid,
                                    &zakat_common_input);

    cui_inline_set_title_icon(mmi_zakat_cntx_p->inline_id, GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR));
    cui_inline_set_title_string(mmi_zakat_cntx_p->inline_id, (UI_string_type)GetString((U16)mmi_zakat_get_common_input_title()));
    mmi_zakat_read_data_from_nvram(mmi_zakat_cntx_p->curr_data_index, mmi_zakat_cntx_p->input_buffer_1, NULL);
    if (mmi_zakat_cntx_p->input_buffer_1[0] == 0)
    {
        mmi_zakat_cntx_p->disp_calculate_result[0] = 0;
    }
    else
    {
        mmi_zakat_calcualte_operation();
    }
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 0, GetString(STR_ID_ZAKAT_TOTAL_COUNT));
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 2, GetString(STR_ID_ZAKAT_PAYABLE)); 
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_calculate_result);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_softkey_icon(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_run(mmi_zakat_cntx_p->inline_id);
    mmi_frm_scrn_close(mmi_zakat_cntx_p->main_gid, SCR_ID_ZAKAT_DESCRIPTION);
}


void mmi_zakat_gold_inline_notify_handle(void *evt)
{
    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
    switch (notify_evt->event_type)
    {
    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        if ((notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 5 ||
            notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 7) &&
            mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
        {
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
        }
        if (notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 9 ||
            notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 3)
        {
            mmi_zakat_cntx_p->highlighted_item = CUI_INLINE_ITEM_ID_BASE + 3;
        }
        else
        {
            mmi_zakat_cntx_p->highlighted_item = CUI_INLINE_ITEM_ID_BASE + 1;
        }
        break;
    }
}


void mmi_zakat_gold_inline_submit_handle(void *evt)
{
    if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->input_buffer_2);
        mmi_zakat_input_LSK_calculate();
        if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
        {
            cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, mmi_zakat_cntx_p->disp_amount);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, mmi_zakat_cntx_p->disp_calculate_result);

            /* CUI_INLINE_ITEM_ID_BASE + 9's text will not update without this sentence */
            cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 3, MMI_TRUE);
            cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, (void*)&first_ok_inline_item);
            cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
            cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, (void*)&second_ok_inline_item);
            cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 9, mmi_zakat_cntx_p->input_buffer_2);

            if (mmi_zakat_cntx_p->highlighted_item == CUI_INLINE_ITEM_ID_BASE + 1)
            {
                cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
            }
            else
            {
                cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 9);
            }
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 8, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 9, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 5, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 7, MMI_TRUE);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 8,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 9,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 5,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 7,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 8, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 9, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 5, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 7, MMI_TRUE);
            cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
        }
        else
        {
            cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, (U16)(mmi_zakat_cntx_p->highlighted_item));
        }
    }
    else if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 9, mmi_zakat_cntx_p->input_buffer_2);
        mmi_zakat_input_LSK_save();
    }
}


S32 mmi_zakat_gold_inline_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_zakat_gold_inline_submit_handle(event);
            break;
        }
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_zakat_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
        break;
    case EVT_ID_CUI_INLINE_ABORT:
        {
            if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
            {
                cui_inline_close(mmi_zakat_cntx_p->inline_id);
            }
            else
            {
                cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
                mmi_zakat_input_RSK_reset();
                cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, (void*)&first_reset_inline_item);
                cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
                cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 9, (void*)&second_reset_inline_item);
                cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 9);
                cui_inline_set_item_attributes(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 1,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_NO_LEADING_ZERO);
                cui_inline_set_item_attributes(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 3,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_NO_LEADING_ZERO);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->input_buffer_2);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, mmi_zakat_cntx_p->disp_amount);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, mmi_zakat_cntx_p->disp_calculate_result);
                cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, (U16)mmi_zakat_cntx_p->highlighted_item);
                mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_FALSE);
                mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 3, MMI_FALSE);
				cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
				cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
				cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
				cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
                cui_inline_set_softkey_icon(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 5,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 7,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
                cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
            }
            break;
        }
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            mmi_zakat_gold_inline_notify_handle(event); 
            break;
        }
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_gold_input
 * DESCRIPTION
 *  entry function of common input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_gold_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->inline_gid = mmi_frm_group_create(
                                    GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_zakat_gold_inline_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(
        mmi_zakat_cntx_p->inline_gid,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_zakat_cntx_p->inline_id = cui_inline_create(
                                    mmi_zakat_cntx_p->inline_gid,
                                    &zakat_gold_input);

    cui_inline_set_title_icon(mmi_zakat_cntx_p->inline_id, GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR));
    cui_inline_set_title_string(mmi_zakat_cntx_p->inline_id, (UI_string_type)GetString((U16)mmi_zakat_get_gold_silver_input_title()));
    mmi_zakat_read_data_from_nvram(mmi_zakat_cntx_p->curr_data_index, mmi_zakat_cntx_p->input_buffer_1, NULL);
    mmi_zakat_read_data_from_nvram(mmi_zakat_cntx_p->curr_data_index + 1, mmi_zakat_cntx_p->input_buffer_2, NULL);
    if (mmi_zakat_cntx_p->input_buffer_1[0] == 0)
    {
        mmi_zakat_cntx_p->disp_amount[0] = 0;
        mmi_zakat_cntx_p->disp_calculate_result[0] = 0;
    }
    else
    {
        mmi_zakat_calcualte_operation();
    }
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 0, GetString(STR_ID_ZAKAT_NO_OF_GMS));
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 2, GetString(STR_ID_ZAKAT_PRICE)); 
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->input_buffer_2);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 4, GetString(STR_ID_ZAKAT_TOTAL_AMOUNT));
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, mmi_zakat_cntx_p->disp_amount);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 6, GetString(STR_ID_ZAKAT_PAYABLE)); 
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 7, mmi_zakat_cntx_p->disp_calculate_result);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_softkey_icon(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 5,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_softkey_icon(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 7,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_run(mmi_zakat_cntx_p->inline_id);
}


void mmi_zakat_silver_inline_notify_handle(void *evt)
{
    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
    switch (notify_evt->event_type)
    {
    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        if ((notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 3 ||
            notify_evt->item_id == CUI_INLINE_ITEM_ID_BASE + 5) &&
            mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
        {
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_LEFT_SOFTKEY, 0);
            cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
            cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
        }
        break;
    }
}


void mmi_zakat_silver_inline_submit_handle(void *evt)
{
    if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
        if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_GMS)
        {
            mmi_zakat_read_data_from_nvram(MMI_ZAKAT_24_CARAT_PRICE, mmi_zakat_cntx_p->input_buffer_2, NULL);        
        }
        else
        {
            mmi_zakat_read_data_from_nvram(MMI_ZAKAT_SILVER_PRICE, mmi_zakat_cntx_p->input_buffer_2, NULL);        
        }
        mmi_zakat_input_LSK_calculate();
        if (mmi_zakat_cntx_p->input_buffer_1[0] == 0)
        {
            cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
        }
        if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
        {
            cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_amount);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, mmi_zakat_cntx_p->disp_calculate_result);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_TRUE);
            cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, (void*)&first_ok_inline_item);
            cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
            cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
            cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 8, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 3, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 5, MMI_TRUE);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 8,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 3,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            cui_inline_set_softkey_icon(
                mmi_zakat_cntx_p->inline_id,
                CUI_INLINE_ITEM_ID_BASE + 5,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 8, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 3, MMI_TRUE);
            mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 5, MMI_TRUE);
            cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
            cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
        }
    }
    else if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_CALCULATE)
    {
        cui_inline_get_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, mmi_zakat_cntx_p->input_buffer_1);
        mmi_zakat_input_LSK_save();
    }
}


S32 mmi_zakat_silver_inline_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_zakat_silver_inline_submit_handle(event);
            break;
        }
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_zakat_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
        break;
    case EVT_ID_CUI_INLINE_ABORT:
        {
            if (mmi_zakat_cntx_p->operation_flag == MMI_ZAKAT_INITIALIZE)
            {
                cui_inline_close(mmi_zakat_cntx_p->inline_id);
            }
            else
            {
                cui_inline_lock_main_screen(mmi_zakat_cntx_p->inline_id);
                mmi_zakat_input_RSK_reset();
                cui_inline_insert_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8, (void*)&first_reset_inline_item);
                cui_inline_delete_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 8);
                cui_inline_set_item_attributes(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 1,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_NO_LEADING_ZERO);
                cui_inline_set_item_attributes(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 3,
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_NO_LEADING_ZERO);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_amount);
                cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, mmi_zakat_cntx_p->disp_calculate_result);
                cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1);
                mmi_zakat_change_softkey(mmi_zakat_cntx_p->inline_id, 1, MMI_FALSE);
				cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, IMG_GLOBAL_BACK);
				cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
                cui_inline_set_softkey_icon(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 3,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_set_softkey_icon(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + 5,
                    MMI_CENTER_SOFTKEY,
                    0);
                cui_inline_unlock_main_screen(mmi_zakat_cntx_p->inline_id);
                cui_inline_redraw_screen(mmi_zakat_cntx_p->inline_id);
            }
            break;
        }
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            mmi_zakat_silver_inline_notify_handle(event); 
            break;
        }
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_silver_input
 * DESCRIPTION
 *  entry function of common input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_silver_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->inline_gid = mmi_frm_group_create(
                                    GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_zakat_silver_inline_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(
        mmi_zakat_cntx_p->inline_gid,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->inline_id = cui_inline_create(
                                    mmi_zakat_cntx_p->inline_gid,
                                    &zakat_silver_input);

    cui_inline_set_title_icon(mmi_zakat_cntx_p->inline_id, GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR));
    cui_inline_set_title_string(mmi_zakat_cntx_p->inline_id, (UI_string_type)GetString((U16)mmi_zakat_get_gold_silver_input_title()));
    mmi_zakat_read_data_from_nvram(mmi_zakat_cntx_p->curr_data_index, mmi_zakat_cntx_p->input_buffer_1, NULL);
    mmi_zakat_read_data_from_nvram(mmi_zakat_cntx_p->curr_data_index + 1, mmi_zakat_cntx_p->input_buffer_2, NULL);
    if (mmi_zakat_cntx_p->input_buffer_1[0] == 0)
    {
        mmi_zakat_cntx_p->disp_amount[0] = 0;
        mmi_zakat_cntx_p->disp_calculate_result[0] = 0;
    }
    else
    {
        mmi_zakat_calcualte_operation();
    }
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 0, GetString(STR_ID_ZAKAT_NO_OF_GMS));
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 1, mmi_zakat_cntx_p->input_buffer_1);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 2, GetString(STR_ID_ZAKAT_TOTAL_AMOUNT));
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 3, mmi_zakat_cntx_p->disp_amount);
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 4, GetString(STR_ID_ZAKAT_PAYABLE)); 
    cui_inline_set_value(mmi_zakat_cntx_p->inline_id, CUI_INLINE_ITEM_ID_BASE + 5, mmi_zakat_cntx_p->disp_calculate_result);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_softkey_icon(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_set_softkey_icon(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 5,
        MMI_CENTER_SOFTKEY,
        0);
    cui_inline_run(mmi_zakat_cntx_p->inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_pre_entry_24K_gold_silver_input
 * DESCRIPTION
 *  entry function of 24K gold and silver input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_pre_entry_24K_gold_silver_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_zakat_input_valid_test();
    if (result == MMI_ZAKAT_TOO_LARGE_RESULT)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_ID_ZAKAT_OUT_OF_RANGE),
            MMI_EVENT_FAILURE,
            mmi_zakat_cntx_p->bullion_cash_gid,
            NULL);
    }
}


void mmi_zakat_nisab_submit_handle(void *evt)
{
    cui_inline_get_value(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_GOLD_PRICE_INFO,
        mmi_zakat_cntx_p->input_buffer_1);
    cui_inline_get_value(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_SILVER_PRICE_INFO,
        mmi_zakat_cntx_p->input_buffer_2);
    mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_24_CARAT_PRICE;
    mmi_zakat_input_LSK_save();
    if (mmi_zakat_cntx_p->operation_flag != MMI_ZAKAT_INITIALIZE)
    {
        cui_inline_set_highlight_item(mmi_zakat_cntx_p->inline_id, (U16)(mmi_zakat_cntx_p->highlighted_item));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_nisab_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_zakat_nisab_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            {
                mmi_zakat_nisab_submit_handle(event);
                break;
            }
        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_inline_close(mmi_zakat_cntx_p->inline_id);
                mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_INITIALIZE;
                break;
            }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
#ifdef __MMI_FTE_SUPPORT__
            wgui_register_tap_callback(mmi_zakat_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
            break;
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            {
                break;
            }
        case EVT_ID_CUI_INLINE_SET_KEY:
            {
                break;
            }
        case EVT_ID_CUI_INLINE_REDRAW:
            {
                break;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_nisab
 * DESCRIPTION
 *  entry function of nisab input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_nisab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_zakat_cntx_p->inline_gid = mmi_frm_group_create(
                                    GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_zakat_nisab_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(
        mmi_zakat_cntx_p->inline_gid,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->inline_id = cui_inline_create(
                                    mmi_zakat_cntx_p->inline_gid,
                                    &zakat_nisab_input);

    cui_inline_set_title_icon(
        mmi_zakat_cntx_p->inline_id,
        GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR));
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_24_CARAT_PRICE,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_SILVER_PRICE,
        mmi_zakat_cntx_p->input_buffer_2,
        NULL);
    cui_inline_set_value(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_GOLD_PRICE_INFO,
        mmi_zakat_cntx_p->input_buffer_1);
    cui_inline_set_value(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_SILVER_PRICE_INFO,
        mmi_zakat_cntx_p->input_buffer_2);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_item_attributes(
        mmi_zakat_cntx_p->inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_NO_LEADING_ZERO);
    cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, (U16)(CUI_INLINE_ITEM_ID_BASE + 1), MMI_LEFT_SOFTKEY, 0);
    cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, (U16)(CUI_INLINE_ITEM_ID_BASE + 1), MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
    cui_inline_set_softkey_icon(mmi_zakat_cntx_p->inline_id, (U16)(CUI_INLINE_ITEM_ID_BASE + 3), MMI_LEFT_SOFTKEY, 0);
    cui_inline_set_softkey_text(mmi_zakat_cntx_p->inline_id, (U16)(CUI_INLINE_ITEM_ID_BASE + 3), MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
    cui_inline_run(mmi_zakat_cntx_p->inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_payable
 * DESCRIPTION
 *  entry function of payable display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_payable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        mmi_zakat_cntx_p->main_gid,
        SCR_ID_ZAKAT_PAYABLE,
        NULL,
        mmi_zakat_entry_payable,
        MMI_FRM_FULL_SCRN);

    mmi_zakat_construct_payable();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory7Screen(
        STR_ID_ZAKAT_PAYABLE,
        GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR),
        STR_GLOBAL_DETAILS,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*)mmi_zakat_cntx_p->disp_payable,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_zakat_entry_detail, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_zakat_entry_detail, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_detail
 * DESCRIPTION
 *  entry function of detail display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        mmi_zakat_cntx_p->main_gid,
        SCR_ID_ZAKAT_DETAIL,
        NULL,
        mmi_zakat_entry_detail,
        MMI_FRM_FULL_SCRN);

    mmi_zakat_construct_detail();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory7Screen(
        STR_GLOBAL_DETAILS,
        GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR),
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*)mmi_zakat_cntx_p->disp_payable,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/* 
 * Other function 
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_input_LSK_calculate
 * DESCRIPTION
 *  calculate zakat payable or deductions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_input_LSK_calculate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_zakat_input_valid_test();

    /* three types of invalid input */
    if (result == MMI_ZAKAT_INVALID_DOUBLE)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT),
            MMI_EVENT_FAILURE,
            mmi_zakat_cntx_p->inline_gid,
            NULL);
        return;
    }
    else if (result == MMI_ZAKAT_TOO_LARGE_RESULT)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_ID_ZAKAT_OUT_OF_RANGE),
            MMI_EVENT_FAILURE,
            mmi_zakat_cntx_p->inline_gid,
            NULL);
        mmi_zakat_cntx_p->disp_amount[0] = 0;
        mmi_zakat_cntx_p->disp_calculate_result[0] = 0;
        return;
    }
    else if (result == MMI_ZAKAT_NO_INPUT)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_ID_ZAKAT_PLEASE_INPUT),
            MMI_EVENT_FAILURE,
            mmi_zakat_cntx_p->inline_gid,
            NULL);
        return;
    }

    /* valid input */
    else
    {
        /* set operation flag */
        mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_CALCULATE;
        mmi_zakat_calcualte_operation();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_input_LSK_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_input_LSK_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_PRICE ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_SILVER_PRICE)
    {
        mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_RESET;
        result = mmi_zakat_input_valid_test();
        /* two types of invalid input: invalid and no input */
        if (result == MMI_ZAKAT_INVALID_DOUBLE)
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT),
                MMI_EVENT_FAILURE,
                mmi_zakat_cntx_p->inline_gid,
                NULL);
            return;
        }
        else if (result == MMI_ZAKAT_NO_INPUT)
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_ID_ZAKAT_PLEASE_INPUT),
                MMI_EVENT_FAILURE,
                mmi_zakat_cntx_p->inline_gid,
                NULL);
            if (mmi_zakat_cntx_p->input_buffer_1[0] == 0)
            {
                cui_inline_set_highlight_item(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_GOLD_PRICE_INFO);
            }
            else if (mmi_zakat_cntx_p->input_buffer_2[0] == 0)
            {
                cui_inline_set_highlight_item(
                    mmi_zakat_cntx_p->inline_id,
                    CUI_INLINE_ITEM_ID_BASE + MMI_ZAKAT_NISAB_SILVER_PRICE_INFO);
            }
            return;
        }
        /* to make sure amount of 24 carat gold and silver not out of range */
        else if (result == MMI_ZAKAT_TOO_LARGE_RESULT)
        {
            if (mmi_zakat_cntx_p->highlighted_item == MMI_ZAKAT_NISAB_GOLD_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE)
            {
                kal_wsprintf(
                    (WCHAR*)mmi_zakat_cntx_p->disp_calculate_result,
                    "%w%w",
                    GetString(STR_ID_ZAKAT_GOLD),
                    GetString(STR_ID_ZAKAT_AMOUNT_OUT_OF_RANGE));
            }
            else
            {
                kal_wsprintf(
                    (WCHAR*)mmi_zakat_cntx_p->disp_calculate_result,
                    "%w%w",
                    GetString(STR_ID_ZAKAT_SILVER),
                    GetString(STR_ID_ZAKAT_AMOUNT_OUT_OF_RANGE));
            }
            mmi_popup_display_simple(
                (UI_string_type)mmi_zakat_cntx_p->disp_calculate_result,
                MMI_EVENT_FAILURE,
                mmi_zakat_cntx_p->inline_gid,
                NULL);
            return;
        }
    }
    mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_INITIALIZE;
    mmi_zakat_save();
    mmi_popup_display_simple(
        (UI_string_type)GetString(STR_GLOBAL_SAVED),
        MMI_EVENT_SUCCESS,
        mmi_zakat_cntx_p->inline_gid,
        NULL);

    cui_inline_close(mmi_zakat_cntx_p->inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_input_RSK_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_input_RSK_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_RESET;
    mmi_zakat_cntx_p->input_buffer_1[0] = 0;
    mmi_zakat_cntx_p->input_buffer_2[0] = 0;
    mmi_zakat_cntx_p->disp_amount[0] = 0;
    mmi_zakat_cntx_p->disp_calculate_result[0] = 0;
    mmi_zakat_cntx_p->operation_flag = MMI_ZAKAT_INITIALIZE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_read_data_from_nvram
 * DESCRIPTION
 *  read data from nvram
 * PARAMETERS
 *  index       [IN]          index of data record in nvram
 *  buffer      [OUT]         data record read from nvram in string form
 *  dataPtr     [OUT]         data record read from nvram in double form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_read_data_from_nvram(
            U32 index,
            U16 *buffer,
            double *dataPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    double dataLocal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dataPtr == NULL)
    {
        ReadRecord(
            mmi_zakat_cntx_p->lid,
            (U16)(index + 1),
            &dataLocal,
            (U16)sizeof(double),
            &error);
        if (buffer != NULL)
        {
            mmi_zakat_double_2_string(buffer, dataLocal);
        }
    }
    else
    {
        ReadRecord(
            mmi_zakat_cntx_p->lid,
            (U16)(index + 1),
            dataPtr,
            (U16)sizeof(double),
            &error);
        if (buffer != NULL)
        {
            mmi_zakat_double_2_string(buffer, *dataPtr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_write_data_to_nvram
 * DESCRIPTION
 *  write data to nvram
 * PARAMETERS
 *  index       [IN]         index of data record in nvram
 *  buffer      [IN]         string form data writted to nvram
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_write_data_to_nvram(U32 index, S8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    double data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_string_2_double((U16*)buffer, &data);
    WriteRecord(
        mmi_zakat_cntx_p->lid,
        (U16)(index + 1),
        &data,
        (U16)sizeof(double),
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_get_description_screen_info
 * DESCRIPTION
 *  get information of description screen
 * PARAMETERS
 *  title           [OUT]         get the title of description screen
 *  description     [OUT]         get the content of description screen
 *  f               [OUT]         get the entry function of next screen
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_get_description_screen_info(
            U16 *title,
            U16 *description,
            void (**f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_zakat_cntx_p->curr_data_index)
    {
        /* descriptino screen would not be showed when backing history */
        case MMI_ZAKAT_CATTLE:
            *title = STR_ID_ZAKAT_CATTLE;
            *f = mmi_zakat_entry_cattle;
            break;

        case MMI_ZAKAT_AGRICULTURE:
            *title = STR_ID_ZAKAT_AGRICULTURE;
            *description = STR_ID_ZAKAT_DESCRIPTION_AGRICULTURE;
            *f = mmi_zakat_entry_agriculture;
            break;

        case MMI_ZAKAT_BULLION_CASH:
            *title = STR_ID_ZAKAT_BULLION_CASH;
            *description = STR_ID_ZAKAT_DESCRIPTION_BULLION_CASH;
            *f = mmi_zakat_entry_bullion_cash;
            break;

        case MMI_ZAKAT_BURIED_TREASURES:
            *title = STR_ID_ZAKAT_BURIED_TREASURES;
            *description = STR_ID_ZAKAT_DESCRIPTION_BURIED_TREASURE;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_MINERALS:
            *title = STR_ID_ZAKAT_MINERALS;
            *description = STR_ID_ZAKAT_DESCRIPTION_MINERALS;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_REVENUES:
            *title = STR_ID_ZAKAT_REVENUES;
            *description = STR_ID_ZAKAT_DESCRIPTION_REVENUES;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_COMMERCIAL_COMMODITIES:
            *title = STR_ID_ZAKAT_COMMERCIAL_COMMODITIES;
            *description = STR_ID_ZAKAT_DESCRIPTION_COMMERCIAL_COMMODITIES;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_BUSINESS:
            *title = STR_ID_ZAKAT_BUSINESS;
            *description = STR_ID_ZAKAT_DESCRIPTION_BUSINESS;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_DEBTS:
            *title = STR_ID_ZAKAT_DEBTS;
            *description = STR_ID_ZAKAT_DESCRIPTION_DEBTS;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_OTHERS:
            *title = STR_ID_ZAKAT_OTHERS;
            *description = STR_ID_ZAKAT_DESCRIPTION_OTHERS;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS:
            *title = STR_ID_ZAKAT_PERSONAL_DEBTS;
            *description = STR_ID_ZAKAT_DESCRIPTION_DEDUCTIONS_PERSONAL_DEBTS;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_DEDUCTIONS_BUSINESS:
            *title = STR_ID_ZAKAT_BUSINESS;
            *description = STR_ID_ZAKAT_DESCRIPTION_DEDUCTIONS_BUSINESS;
            *f = mmi_zakat_entry_common_input;
            break;

        case MMI_ZAKAT_DEDUCTIONS_OTHERS:
            *title = STR_ID_ZAKAT_OTHERS;
            *description = STR_ID_ZAKAT_DESCRIPTION_DEDUCTIONS_OTHERS;
            *f = mmi_zakat_entry_common_input;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


mmi_ret mmi_zakat_reset_confirm_callback(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch (alert->result)
            {
            case MMI_ALERT_CNFM_YES:
                mmi_zakat_reset();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            }
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_reset_confirm
 * DESCRIPTION
 *  reset confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_reset_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = mmi_zakat_cntx_p->main_gid;
    arg.callback = mmi_zakat_reset_confirm_callback;
    arg.f_auto_map_empty_softkey = MMI_TRUE;
    mmi_confirm_display((UI_string_type)GetString(STR_ID_ZAKAT_RESET_CONFIRM), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_save
 * DESCRIPTION
 *  save input data to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double gold;
    double silver;
    double price;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* write to NVRAM */
    switch (mmi_zakat_cntx_p->curr_data_index)
    {
        case MMI_ZAKAT_24_CARAT_PRICE:
        case MMI_ZAKAT_22_CARAT_GMS:
        case MMI_ZAKAT_18_CARAT_GMS:
        case MMI_ZAKAT_OTHER_GOLD_GMS:
            mmi_zakat_write_data_to_nvram(
                mmi_zakat_cntx_p->curr_data_index,
                (S8*)mmi_zakat_cntx_p->input_buffer_1);
            mmi_zakat_write_data_to_nvram(
                mmi_zakat_cntx_p->curr_data_index + 1,
                (S8*)mmi_zakat_cntx_p->input_buffer_2);
            break;

        case MMI_ZAKAT_SILVER_PRICE:
        case MMI_ZAKAT_22_CARAT_PRICE:
        case MMI_ZAKAT_18_CARAT_PRICE:
        case MMI_ZAKAT_OTHER_GOLD_PRICE:
            mmi_zakat_write_data_to_nvram(
                mmi_zakat_cntx_p->curr_data_index - 1,
                (S8*)mmi_zakat_cntx_p->input_buffer_1);
            mmi_zakat_write_data_to_nvram(
                mmi_zakat_cntx_p->curr_data_index,
                (S8*)mmi_zakat_cntx_p->input_buffer_2);
            break;

        default:
            mmi_zakat_write_data_to_nvram(
                mmi_zakat_cntx_p->curr_data_index,
                (S8*)mmi_zakat_cntx_p->input_buffer_1);
            break;
    }
    /* set nisab */
    if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_PRICE ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_SILVER_PRICE)
    {
        mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_1, &price);
        gold = price * MMI_ZAKAT_GOLD_NISAB_GMS;
        mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &price);
        silver = price * MMI_ZAKAT_SILVER_NISAB_GMS;
        mmi_zakat_cntx_p->nisab = gold < silver ? gold : silver;
        /* to cover the limitation of double data */
        mmi_zakat_cntx_p->nisab -= MMI_ZAKAT_DOUBLE_ADJUST;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_reset
 * DESCRIPTION
 *  clear all data record in nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    double zero = 0.0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_ZAKAT_DATA_RECORD_COUNT; i++)
    {
        WriteRecord(
            mmi_zakat_cntx_p->lid,
            (U16)(i + 1),
            &zero,
            (U16)sizeof(zero),
            &error);
    }
    mmi_zakat_cntx_p->nisab = 0;
    mmi_popup_display_simple(
        (UI_string_type)GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        mmi_zakat_cntx_p->main_gid,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_get_common_input_title
 * DESCRIPTION
 *  get tile of common input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  S32         string id of title
 *****************************************************************************/
static S32 mmi_zakat_get_common_input_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_zakat_cntx_p->curr_data_index)
    {
        case MMI_ZAKAT_CAMELS:
            return STR_ID_ZAKAT_CAMELS;

        case MMI_ZAKAT_COWS:
            return STR_ID_ZAKAT_COWS;

        case MMI_ZAKAT_SHEEP:
            return STR_ID_ZAKAT_SHEEP;

        case MMI_ZAKAT_BY_RAIN_WATER:
            return STR_ID_ZAKAT_BY_RAIN_WATER;

        case MMI_ZAKAT_BY_IRRIGATION:
            return STR_ID_ZAKAT_BY_IRRIGATION;

        case MMI_ZAKAT_BY_BOTH:
            return STR_ID_ZAKAT_BY_BOTH;

        case MMI_ZAKAT_CASH:
            return STR_ID_ZAKAT_CASH;

        case MMI_ZAKAT_BURIED_TREASURES:
            return STR_ID_ZAKAT_BURIED_TREASURES;

        case MMI_ZAKAT_MINERALS:
            return STR_ID_ZAKAT_MINERALS;

        case MMI_ZAKAT_REVENUES:
            return STR_ID_ZAKAT_REVENUES;

        case MMI_ZAKAT_COMMERCIAL_COMMODITIES:
            return STR_ID_ZAKAT_COMMERCIAL_COMMODITIES;

        case MMI_ZAKAT_BUSINESS:
            return STR_ID_ZAKAT_BUSINESS;

        case MMI_ZAKAT_DEBTS:
            return STR_ID_ZAKAT_DEBTS;

        case MMI_ZAKAT_OTHERS:
            return STR_ID_ZAKAT_OTHERS;

        case MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS:
            return STR_ID_ZAKAT_PERSONAL_DEBTS;

        case MMI_ZAKAT_DEDUCTIONS_BUSINESS:
            return STR_ID_ZAKAT_BUSINESS;

        case MMI_ZAKAT_DEDUCTIONS_OTHERS:
            return STR_ID_ZAKAT_OTHERS;

        default:
            MMI_ASSERT(0);
            return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_get_gold_silver_input_title
 * DESCRIPTION
 *  get tile of common input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  S32         string id of title
 *****************************************************************************/
static S32 mmi_zakat_get_gold_silver_input_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_zakat_cntx_p->curr_data_index)
    {
        case MMI_ZAKAT_24_CARAT_GMS:
            return STR_ID_ZAKAT_24_CARAT;

        case MMI_ZAKAT_22_CARAT_GMS:
            return STR_ID_ZAKAT_22_CARAT;

        case MMI_ZAKAT_18_CARAT_GMS:
            return STR_ID_ZAKAT_18_CARAT;

        case MMI_ZAKAT_OTHER_GOLD_GMS:
            return STR_ID_ZAKAT_OTHERS;

        case MMI_ZAKAT_SILVER_GMS:
            return STR_ID_ZAKAT_SILVER;

        default:
            MMI_ASSERT(0);
            return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculate_camels_payable
 * DESCRIPTION
 *  calculate operation of camels payable
 * PARAMETERS
 *  outBuffer       [OUT]       zakat payable buffer
 *  inBuffer        [IN]        count of camels in string form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calculate_camels_payable(U16 *outBuffer, U16 *inBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double data1;
    double data2;
    U16 type1;
    U16 type2;
    double base;
    double uCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_string_2_double(inBuffer, &uCount);
    data1 = 0;
    data2 = 0;
    /* not exceed nisab */
    if (uCount < MMI_ZAKAT_CAMELS_NISAB)
    {
        kal_wsprintf(
            (WCHAR*)outBuffer,
            "%w",
            GetString(STR_ID_ZAKAT_NO_ZAKAT_PAYABLE));
        mmi_zakat_cntx_p->calculate_result = 0;
        return;
    }

    mmi_zakat_cntx_p->calculate_result = 1;
    if (uCount < 130)
    {
        if (uCount < 5 * MMI_ZAKAT_CAMELS_NISAB)
        {
            data1 = uCount / 5;
            type1 = STR_ID_ZAKAT_SHEEP_SI_PL;
        }
        else if (uCount <= 35)
        {
            data1 = 1;
            type1 = STR_ID_ZAKAT_1_YEAR_OLD_FEMALE_CAMEL_SI;
        }
        else if (uCount <= 45)
        {
            data1 = 1;
            type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_SI;
        }
        else if (uCount <= 60)
        {
            data1 = 1;
            type1 = STR_ID_ZAKAT_3_YEAR_OLD_FEMALE_CAMEL_SI;
        }
        else if (uCount <= 75)
        {
            data1 = 1;
            type1 = STR_ID_ZAKAT_4_YEAR_OLD_FEMALE_CAMEL_SI;
        }
        else if (uCount <= 90)
        {
            data1 = 2;
            type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_PL;
        }
        else if (uCount <= 120)
        {
            data1 = 2;
            type1 = STR_ID_ZAKAT_3_YEAR_OLD_FEMALE_CAMEL_PL;
        }
        else
        {
            data1 = 3;
            type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_PL;
        }
        mmi_zakat_double_2_string(outBuffer, data1);
        mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type1));
        return;
    }

    uCount = floor(uCount / 10) * 10;
    data2 = uCount / MMI_ZAKAT_3_YEAR_OLD_CAMEL_VALUE;
    if (floor(data2) == data2)
    {
        mmi_zakat_double_2_string(outBuffer, data2);
        mmi_ucs2cat(
            (S8*)outBuffer,
            (S8*)GetString(STR_ID_ZAKAT_3_YEAR_OLD_FEMALE_CAMEL_PL));
        return;
    }
    data1 = uCount / MMI_ZAKAT_2_YEAR_OLD_CAMEL_VALUE;
    if (floor(data1) == data1)
    {
        mmi_zakat_double_2_string(outBuffer, data1);
        mmi_ucs2cat(
            (S8*)outBuffer,
            (S8*)GetString(STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_PL));
        return;
    }
    base = uCount - (floor(data2) * MMI_ZAKAT_3_YEAR_OLD_CAMEL_VALUE);
    if (base == 10)
    {
        data1 = 4;
        type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_PL;
    }
    else if (base == 20)
    {
        data1 = 3;
        type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_PL;
    }
    else if (base == 30)
    {
        data1 = 2;
        type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_PL;
    }
    else /* base == 40 */
    {
        data1 = 1;
        type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_CAMEL_SI;
    }
    data2 = (uCount - data1 * MMI_ZAKAT_2_YEAR_OLD_CAMEL_VALUE) /
        MMI_ZAKAT_3_YEAR_OLD_CAMEL_VALUE;
    if (data2 == 1)
    {
        type2 = STR_ID_ZAKAT_3_YEAR_OLD_FEMALE_CAMEL_SI;
    }
    else
    {
        type2 = STR_ID_ZAKAT_3_YEAR_OLD_FEMALE_CAMEL_PL;
    }
    kal_wsprintf((WCHAR*)outBuffer, "1. ");
    mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data1);
    mmi_ucs2cat((S8*)outBuffer, (S8*)mmi_zakat_cntx_p->input_buffer_2);
    mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type1));
    mmi_ucs2cat((S8*)outBuffer, (S8*)L"\n2. ");
    mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
    mmi_ucs2cat((S8*)outBuffer, (S8*)mmi_zakat_cntx_p->input_buffer_2);
    mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type2));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculate_cows_payable
 * DESCRIPTION
 *  calculate operation of cows payable
 * PARAMETERS
 *  outBuffer       [OUT]       zakat payable buffer
 *  inBuffer        [IN]        count of cows in string form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calculate_cows_payable(U16 *outBuffer, U16 *inBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double base;
    double data1;
    double data2;
    U16 type1;
    U16 type2;
    double uCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type1 = 0;
    type2 = 0;
    mmi_zakat_string_2_double(inBuffer, &uCount);
    /* not exceed nisab */
    if (uCount < MMI_ZAKAT_COWS_NISAB)
    {
        kal_wsprintf(
            (WCHAR*)outBuffer,
            "%w",
            GetString(STR_ID_ZAKAT_NO_ZAKAT_PAYABLE));
        mmi_zakat_cntx_p->calculate_result = 0;
        return;
    }

    mmi_zakat_cntx_p->calculate_result = 1;
    if (uCount < 40)
    {
        data1 = 1;
        type1 = STR_ID_ZAKAT_1_YEAR_OLD_FEMALE_OR_MALE_COW_SI;
        mmi_zakat_double_2_string(outBuffer, data1);
        mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type1));
    }
    else if (uCount < 60)
    {
        data1 = 1;
        type1 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_OR_MALE_COW_SI;
        mmi_zakat_double_2_string(outBuffer, data1);
        mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type1));
    }
    else
    {
        uCount = floor(uCount / 10) * 10;
        data2 = uCount / MMI_ZAKAT_2_YEAR_OLD_COW_VALUE;
        if (floor(data2) == data2)
        {
            data2 = uCount / MMI_ZAKAT_2_YEAR_OLD_COW_VALUE;
            type2 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_OR_MALE_COW_PL;
            mmi_zakat_double_2_string(outBuffer, data2);
            mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type2));
            return;
        }

        data1 = uCount / MMI_ZAKAT_1_YEAR_OLD_COW_VALUE;
        if (floor(data1) == data1)
        {
            data1 = uCount / MMI_ZAKAT_1_YEAR_OLD_COW_VALUE;
            type1 = STR_ID_ZAKAT_1_YEAR_OLD_FEMALE_OR_MALE_COW_PL;
            mmi_zakat_double_2_string(outBuffer, data1);
            mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type1));
            return;
        }

        base = uCount - (floor(data2) * MMI_ZAKAT_2_YEAR_OLD_COW_VALUE);
        if (base == 10)
        {
            data1 = 3;
            type1 = STR_ID_ZAKAT_1_YEAR_OLD_FEMALE_OR_MALE_COW_PL;
        }
        else if (base == 20)
        {
            data1 = 2;
            type1 = STR_ID_ZAKAT_1_YEAR_OLD_FEMALE_OR_MALE_COW_PL;
        }
        else /* base == 30 */
        {
            data1 = 1;
            type1 = STR_ID_ZAKAT_1_YEAR_OLD_FEMALE_OR_MALE_COW_SI;
        }
        data2 = (uCount - data1 * MMI_ZAKAT_1_YEAR_OLD_COW_VALUE) /
            MMI_ZAKAT_2_YEAR_OLD_COW_VALUE;
        if (data2 == 1)
        {
            type2 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_OR_MALE_COW_SI;
        }
        else
        {
            type2 = STR_ID_ZAKAT_2_YEAR_OLD_FEMALE_OR_MALE_COW_PL;
        }
        kal_wsprintf((WCHAR*)outBuffer, "1. ");
        mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data1);
        mmi_ucs2cat((S8*)outBuffer, (S8*)mmi_zakat_cntx_p->input_buffer_2);
        mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type1));
        mmi_ucs2cat((S8*)outBuffer, (S8*)L"\n2. ");
        mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
        mmi_ucs2cat((S8*)outBuffer, (S8*)mmi_zakat_cntx_p->input_buffer_2);
        mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(type2));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculate_sheep_payable
 * DESCRIPTION
 *  calculate operation of sheep payable
 * PARAMETERS
 *  outBuffer       [OUT]       zakat payable buffer
 *  inBuffer        [IN]        count of sheep in string form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calculate_sheep_payable(U16 *outBuffer, U16 *inBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double sheep;
    double uCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_string_2_double(inBuffer, &uCount);
    /* not exceed nisab */
    if (uCount < MMI_ZAKAT_SHEEP_NISAB)
    {
        kal_wsprintf(
            (WCHAR*)outBuffer,
            "%w",
            GetString(STR_ID_ZAKAT_NO_ZAKAT_PAYABLE));
        mmi_zakat_cntx_p->calculate_result = 0;
        return;
    }

    if (uCount <= 120)
    {
        sheep = 1;
    }
    else if (uCount <= 200)
    {
        sheep = 2;
    }
    else if (uCount < 400)
    {
        sheep = 3;
    }
    else
    {
        sheep = uCount / 100;
    }
    sheep = floor(sheep);
    mmi_zakat_double_2_string(outBuffer, sheep);
    mmi_ucs2cat((S8*)outBuffer, (S8*)GetString(STR_ID_ZAKAT_SHEEP_SI_PL));
    mmi_zakat_cntx_p->calculate_result = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculate_gold_silver_payable
 * DESCRIPTION
 *  calculate operation of gold and silver payable
 * PARAMETERS
 *  outBuffer1      [OUT]       amount of gold/silver value
 *  outBuffer2      [OUT]       zakat payable
 *  inBuffer1       [IN]        gms in string form
 *  inBuffer2       [IN]        price in string form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calculate_gold_silver_payable(
            U16 *outBuffer1,
            U16 *outBuffer2,
            U16 *inBuffer1,
            U16 *inBuffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double amount;
    double gms;
    double price;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_string_2_double(inBuffer1, &gms);
    mmi_zakat_string_2_double(inBuffer2, &price);
    amount = gms * price;
    if (outBuffer1 != NULL)
    {
        mmi_zakat_double_2_string(outBuffer1, amount);
    }
    /* not exceed nisab */
    if (amount < mmi_zakat_cntx_p->nisab || mmi_zakat_cntx_p->nisab == 0)
    {
        mmi_zakat_cntx_p->small_items_amount += amount;
        if (outBuffer2 != NULL)
        {
            kal_wsprintf(
                (WCHAR*)outBuffer2,
                "%w",
                GetString(STR_ID_ZAKAT_NO_ZAKAT_PAYABLE));
        }
        mmi_zakat_cntx_p->calculate_result = 0;
    }
    else /* payable = amount * percentage */
    {
        mmi_zakat_cntx_p->calculate_result =
            amount * MMI_ZAKAT_COMMON_PERCENTAGE;
        if (outBuffer2 != NULL)
        {
            mmi_zakat_double_2_string(
                outBuffer2,
                mmi_zakat_cntx_p->calculate_result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculate_common_nisab_item_payable
 * DESCRIPTION
 *  calculate operation of common items payable
 * PARAMETERS
 *  outBuffer       [OUT]       zakat payable buffer
 *  inBuffer        [IN]        amount in string form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calculate_common_nisab_item_payable(
            U16  *outBuffer,
            U16 *inBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double amount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_string_2_double(inBuffer, &amount);
    if (amount < mmi_zakat_cntx_p->nisab || mmi_zakat_cntx_p->nisab == 0)
    {
        mmi_zakat_cntx_p->small_items_amount += amount;
        if (outBuffer != NULL)
        {
            kal_wsprintf(
                (WCHAR*)outBuffer,
                "%w",
                GetString(STR_ID_ZAKAT_NO_ZAKAT_PAYABLE));
        }
        mmi_zakat_cntx_p->calculate_result = 0;
    }
    else
    {
        mmi_zakat_cntx_p->calculate_result =
                    MMI_ZAKAT_COMMON_PERCENTAGE * amount;
        if (outBuffer != NULL)
        {
            mmi_zakat_double_2_string(
                outBuffer,
                mmi_zakat_cntx_p->calculate_result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calculate_common_no_nisab_item_payable
 * DESCRIPTION
 *  calculate operation of common items payable
 * PARAMETERS
 *  outBuffer       [IN]        index of current item
 *  outBuffer       [OUT]       zakat payable buffer
 *  inBuffer        [IN]        amount in string form
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calculate_common_no_nisab_item_payable(
            U32 index,
            U16 *outBuffer,
            U16* inBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double amount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_string_2_double(inBuffer, &amount);
    /* no nisab for these items */
    switch (index)
    {
        case MMI_ZAKAT_BY_RAIN_WATER:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_BY_RAIN_WATER_PERCENTAGE * amount;
            break;

        case MMI_ZAKAT_BY_IRRIGATION:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_BY_IRRIGATION_PERCENTAGE * amount;
            break;

        case MMI_ZAKAT_BY_BOTH:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_BY_BOTH_PERCENTAGE * amount;
            break;

        case MMI_ZAKAT_BURIED_TREASURES:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_BURIED_TREASURES_PERCENTAGE * amount;
            break;

        case MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_COMMON_PERCENTAGE * amount;
            break;

        case MMI_ZAKAT_DEDUCTIONS_BUSINESS:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_COMMON_PERCENTAGE * amount;
            break;

        case MMI_ZAKAT_DEDUCTIONS_OTHERS:
            mmi_zakat_cntx_p->calculate_result =
                MMI_ZAKAT_COMMON_PERCENTAGE * amount;
            break;
    }
    /* first entry screen */
    if (mmi_zakat_cntx_p->calculate_result == 0)
    {
        if (outBuffer != NULL)
        {
            if (index == MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS ||
                index == MMI_ZAKAT_DEDUCTIONS_BUSINESS ||
                index == MMI_ZAKAT_DEDUCTIONS_OTHERS)
            {
                kal_wsprintf(
                    (WCHAR*)outBuffer,
                    "%w",
                    GetString(STR_ID_ZAKAT_NO_DEDUCTIONS));
            }
            else
            {
                kal_wsprintf(
                    (WCHAR*)outBuffer,
                    "%w",
                    GetString(STR_ID_ZAKAT_NO_ZAKAT_PAYABLE));
            }
        }
    }
    else
    {
        if (outBuffer != NULL)
        {
            mmi_zakat_double_2_string(
                outBuffer,
                mmi_zakat_cntx_p->calculate_result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_calcualte_operation
 * DESCRIPTION
 *  calculate operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_calcualte_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_zakat_cntx_p->curr_data_index)
    {
        case MMI_ZAKAT_CAMELS:
            mmi_zakat_calculate_camels_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
            break;

        case MMI_ZAKAT_COWS:
            mmi_zakat_calculate_cows_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
            break;

        case MMI_ZAKAT_SHEEP:
            mmi_zakat_calculate_sheep_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
            break;

        case MMI_ZAKAT_24_CARAT_GMS:
            mmi_zakat_read_data_from_nvram(
                MMI_ZAKAT_24_CARAT_PRICE,
                mmi_zakat_cntx_p->input_buffer_2,
                NULL);
            mmi_zakat_calculate_gold_silver_payable(
                mmi_zakat_cntx_p->disp_amount,
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1,
                mmi_zakat_cntx_p->input_buffer_2);
            break;

        case MMI_ZAKAT_22_CARAT_GMS:
        case MMI_ZAKAT_22_CARAT_PRICE:
        case MMI_ZAKAT_18_CARAT_GMS:
        case MMI_ZAKAT_18_CARAT_PRICE:
        case MMI_ZAKAT_OTHER_GOLD_GMS:
        case MMI_ZAKAT_OTHER_GOLD_PRICE:
            mmi_zakat_calculate_gold_silver_payable(
                mmi_zakat_cntx_p->disp_amount,
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1,
                mmi_zakat_cntx_p->input_buffer_2);
            break;

        case MMI_ZAKAT_SILVER_GMS:
            mmi_zakat_read_data_from_nvram(
                MMI_ZAKAT_SILVER_PRICE,
                mmi_zakat_cntx_p->input_buffer_2,
                NULL);
            mmi_zakat_calculate_gold_silver_payable(
                mmi_zakat_cntx_p->disp_amount,
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1,
                mmi_zakat_cntx_p->input_buffer_2);
            break;

        case MMI_ZAKAT_CASH:
        case MMI_ZAKAT_MINERALS:
        case MMI_ZAKAT_REVENUES:
        case MMI_ZAKAT_COMMERCIAL_COMMODITIES:
        case MMI_ZAKAT_BUSINESS:
        case MMI_ZAKAT_DEBTS:
        case MMI_ZAKAT_OTHERS:
            mmi_zakat_calculate_common_nisab_item_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
            break;

        case MMI_ZAKAT_BY_RAIN_WATER:
        case MMI_ZAKAT_BY_IRRIGATION:
        case MMI_ZAKAT_BY_BOTH:
        case MMI_ZAKAT_BURIED_TREASURES:
        case MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS:
        case MMI_ZAKAT_DEDUCTIONS_BUSINESS:
        case MMI_ZAKAT_DEDUCTIONS_OTHERS:
            mmi_zakat_calculate_common_no_nisab_item_payable(
                mmi_zakat_cntx_p->curr_data_index,
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_construct_payable
 * DESCRIPTION
 *  construct the string of zakat payable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_construct_payable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double payable;
    double data;
    U32 i;
    MMI_BOOL flag;
    U32 strLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CAMELS;
    mmi_zakat_cntx_p->small_items_amount = 0;
    payable = 0;
    flag = MMI_FALSE;
    strLen = 0;
    kal_wsprintf(
        (WCHAR*)mmi_zakat_cntx_p->disp_payable,
        "%w\n\n",
        GetString(STR_ID_ZAKAT_PAYABLE_HEAD));
    strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);

    /* cattle */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_CAMELS,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_calculate_camels_payable(
        mmi_zakat_cntx_p->disp_calculate_result,
        mmi_zakat_cntx_p->input_buffer_1);
    if (mmi_zakat_cntx_p->calculate_result == 1)
    {
        flag = MMI_TRUE;
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w%w\n%w\n",
            GetString(STR_ID_ZAKAT_CAMELS),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_COWS,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_calculate_cows_payable(
        mmi_zakat_cntx_p->disp_calculate_result,
        mmi_zakat_cntx_p->input_buffer_1);
    if (mmi_zakat_cntx_p->calculate_result == 1)
    {
        flag = MMI_TRUE;
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w%w\n%w\n",
            GetString(STR_ID_ZAKAT_COWS),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_SHEEP,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_calculate_sheep_payable(
        mmi_zakat_cntx_p->disp_calculate_result,
        mmi_zakat_cntx_p->input_buffer_1);
    if (mmi_zakat_cntx_p->calculate_result == 1)
    {
        flag = MMI_TRUE;
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w%w\n%w\n",
            GetString(STR_ID_ZAKAT_SHEEP),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }
    if (flag)
    {
        mmi_ucs2cat((S8*)mmi_zakat_cntx_p->disp_payable, (S8*)L"\n");
        strLen++;
    }

    mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CASH;
    /* agriculture */
    for (i = MMI_ZAKAT_BY_RAIN_WATER; i <= MMI_ZAKAT_BY_BOTH; i++)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        mmi_zakat_calculate_common_no_nisab_item_payable(
            i,
            NULL,
            mmi_zakat_cntx_p->input_buffer_1);
        payable += mmi_zakat_cntx_p->calculate_result;
    }

    /* buried treasures */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_BURIED_TREASURES,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_calculate_common_no_nisab_item_payable(
        MMI_ZAKAT_BURIED_TREASURES,
        NULL,
        mmi_zakat_cntx_p->input_buffer_1);
    payable += mmi_zakat_cntx_p->calculate_result;

    /* other items */
    for (i = MMI_ZAKAT_MINERALS; i <= MMI_ZAKAT_OTHERS; i++)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        mmi_zakat_calculate_common_nisab_item_payable(
            NULL,
            mmi_zakat_cntx_p->input_buffer_1);
        payable += mmi_zakat_cntx_p->calculate_result;
    }

    /* gold & silver */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_24_CARAT_GMS,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_24_CARAT_PRICE,
        mmi_zakat_cntx_p->input_buffer_2,
        NULL);
    mmi_zakat_calculate_gold_silver_payable(
        NULL,
        NULL,
        mmi_zakat_cntx_p->input_buffer_1,
        mmi_zakat_cntx_p->input_buffer_2);
    payable += mmi_zakat_cntx_p->calculate_result;
    for (i = MMI_ZAKAT_22_CARAT_GMS; i <= MMI_ZAKAT_OTHER_GOLD_GMS; i += 2)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        mmi_zakat_read_data_from_nvram(
            i + 1,
            mmi_zakat_cntx_p->input_buffer_2,
            NULL);
        mmi_zakat_calculate_gold_silver_payable(
            NULL,
            NULL,
            mmi_zakat_cntx_p->input_buffer_1,
            mmi_zakat_cntx_p->input_buffer_2);
        payable += mmi_zakat_cntx_p->calculate_result;
    }
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_SILVER_GMS,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_SILVER_PRICE,
        mmi_zakat_cntx_p->input_buffer_2,
        NULL);
    mmi_zakat_calculate_gold_silver_payable(
        NULL,
        NULL,
        mmi_zakat_cntx_p->input_buffer_1,
        mmi_zakat_cntx_p->input_buffer_2);
    payable += mmi_zakat_cntx_p->calculate_result;

    /* cash */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_CASH,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_calculate_common_nisab_item_payable(
        NULL,
        mmi_zakat_cntx_p->input_buffer_1);
    payable += mmi_zakat_cntx_p->calculate_result;

    /* small items */
    if (mmi_zakat_cntx_p->small_items_amount >= mmi_zakat_cntx_p->nisab)
    {
        payable +=
            mmi_zakat_cntx_p->small_items_amount * MMI_ZAKAT_COMMON_PERCENTAGE;
    }

    /* deductions */
    for (i = MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS;
         i <= MMI_ZAKAT_DEDUCTIONS_OTHERS;
         i++)
    {
        mmi_zakat_read_data_from_nvram(i, NULL, &data);
        payable -= data * MMI_ZAKAT_COMMON_PERCENTAGE;
    }

    /* ductions > assets */
    if (payable <= 0)
    {
        payable = 0;
    }

    /* no payable */
    if (payable == 0)
    {
        kal_wsprintf((WCHAR*)mmi_zakat_cntx_p->disp_calculate_result, "0");
    }

    else
    {
        mmi_zakat_double_2_string(
            mmi_zakat_cntx_p->disp_calculate_result,
            payable);
    }
    kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w%w\n%w",
            GetString(STR_ID_ZAKAT_CASH),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_construct_detail
 * DESCRIPTION
 *  construct the string of zakat payable detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_construct_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 strLen;
    U16 strID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CAMELS;
    mmi_zakat_cntx_p->small_items_amount = 0;
    strLen = 0;
    strID = 0;
    kal_wsprintf(
        (WCHAR*)mmi_zakat_cntx_p->disp_payable,
        "%w\n\n",
        GetString(STR_ID_ZAKAT_DETAIL_HEAD));
    strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);

    /* cattle */
    for (i = MMI_ZAKAT_CAMELS; i <= MMI_ZAKAT_SHEEP; i++)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);

        /* calculate operation */
        if (i == MMI_ZAKAT_CAMELS)
        {
            mmi_zakat_calculate_camels_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
        }
        else if (i == MMI_ZAKAT_COWS)
        {
            mmi_zakat_calculate_cows_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
        }
        else
        {
            mmi_zakat_calculate_sheep_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
        }

        /* construct display string */
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w-%w%w\n%w\n",
            GetString(STR_ID_ZAKAT_CATTLE),
            GetString((U16)(STR_ID_ZAKAT_CAMELS + i - MMI_ZAKAT_CAMELS)),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }
    mmi_ucs2cat((S8*)mmi_zakat_cntx_p->disp_payable, (S8*)L"\n");
    strLen++;

    mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CASH;
    /* agriculture */
    for (i = MMI_ZAKAT_BY_RAIN_WATER; i <= MMI_ZAKAT_BY_BOTH; i++)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        mmi_zakat_calculate_common_no_nisab_item_payable(
            i,
            mmi_zakat_cntx_p->disp_calculate_result,
            mmi_zakat_cntx_p->input_buffer_1);
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w-%w%w\n%w\n",
            GetString(STR_ID_ZAKAT_AGRICULTURE),
            GetString((U16)(STR_ID_ZAKAT_BY_RAIN_WATER + i - MMI_ZAKAT_BY_RAIN_WATER)),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }
    mmi_ucs2cat((S8*)mmi_zakat_cntx_p->disp_payable, (S8*)L"\n");
    strLen++;

    /* bullion and cash */
    /* 24K */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_24_CARAT_GMS,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_24_CARAT_PRICE,
        mmi_zakat_cntx_p->input_buffer_2,
        NULL);
    mmi_zakat_calculate_gold_silver_payable(
        NULL,
        mmi_zakat_cntx_p->disp_calculate_result,
        mmi_zakat_cntx_p->input_buffer_1,
        mmi_zakat_cntx_p->input_buffer_2);
    kal_wsprintf(
        (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
        "%w-%w-%w%w\n%w\n",
        GetString(STR_ID_ZAKAT_BULLION_CASH),
        GetString(STR_ID_ZAKAT_GOLD),
        GetString(STR_ID_ZAKAT_24_CARAT),
        GetString(STR_ID_ZAKAT_COLON),
        mmi_zakat_cntx_p->disp_calculate_result);
    strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);

    /* 22K ~ other */
    for (i = MMI_ZAKAT_22_CARAT_GMS; i <= MMI_ZAKAT_OTHER_GOLD_GMS; i += 2)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        mmi_zakat_read_data_from_nvram(
            i + 1,
            mmi_zakat_cntx_p->input_buffer_2,
            NULL);
        mmi_zakat_calculate_gold_silver_payable(
            NULL,
            mmi_zakat_cntx_p->disp_calculate_result,
            mmi_zakat_cntx_p->input_buffer_1,
            mmi_zakat_cntx_p->input_buffer_2);
        if (i == MMI_ZAKAT_22_CARAT_GMS)
        {
            strID = STR_ID_ZAKAT_22_CARAT;
        }
        if (i == MMI_ZAKAT_18_CARAT_GMS)
        {
            strID = STR_ID_ZAKAT_18_CARAT;
        }
        if (i == MMI_ZAKAT_OTHER_GOLD_GMS)
        {
            strID = STR_ID_ZAKAT_OTHERS;
        }
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w-%w-%w%w\n%w\n",
            GetString(STR_ID_ZAKAT_BULLION_CASH),
            GetString(STR_ID_ZAKAT_GOLD),
            GetString(strID),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }

    /* silver */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_SILVER_GMS,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_SILVER_PRICE,
        mmi_zakat_cntx_p->input_buffer_2,
        NULL);
    mmi_zakat_calculate_gold_silver_payable(
        NULL,
        mmi_zakat_cntx_p->disp_calculate_result,
        mmi_zakat_cntx_p->input_buffer_1,
        mmi_zakat_cntx_p->input_buffer_2);
    kal_wsprintf(
        (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
        "%w-%w%w\n%w\n",
        GetString(STR_ID_ZAKAT_BULLION_CASH),
        GetString(STR_ID_ZAKAT_SILVER),
        GetString(STR_ID_ZAKAT_COLON),
        mmi_zakat_cntx_p->disp_calculate_result);
    strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);

    /* cash */
    mmi_zakat_read_data_from_nvram(
        MMI_ZAKAT_CASH,
        mmi_zakat_cntx_p->input_buffer_1,
        NULL);
    mmi_zakat_calculate_common_nisab_item_payable(
        mmi_zakat_cntx_p->disp_calculate_result,
        mmi_zakat_cntx_p->input_buffer_1);
    kal_wsprintf(
        (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
        "%w-%w%w\n%w\n",
        GetString(STR_ID_ZAKAT_BULLION_CASH),
        GetString(STR_ID_ZAKAT_CASH),
        GetString(STR_ID_ZAKAT_COLON),
        mmi_zakat_cntx_p->disp_calculate_result);
    strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);

    mmi_ucs2cat((S8*)mmi_zakat_cntx_p->disp_payable, (S8*)L"\n");
    strLen++;

    /* other items */
    for (i = MMI_ZAKAT_BURIED_TREASURES; i <= MMI_ZAKAT_OTHERS; i++)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        if (i == MMI_ZAKAT_BURIED_TREASURES)
        {
            mmi_zakat_calculate_common_no_nisab_item_payable(
                i,
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
        }
        else
        {
            mmi_zakat_calculate_common_nisab_item_payable(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->input_buffer_1);
        }
        kal_wsprintf(
            (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
            "%w%w\n%w\n\n",
            GetString((U16)(STR_ID_ZAKAT_BURIED_TREASURES + i - MMI_ZAKAT_BURIED_TREASURES)),
            GetString(STR_ID_ZAKAT_COLON),
            mmi_zakat_cntx_p->disp_calculate_result);
        strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
    }

    if (mmi_zakat_cntx_p->nisab != 0)
    {
        if (mmi_zakat_cntx_p->small_items_amount >= mmi_zakat_cntx_p->nisab)
        {
            mmi_zakat_double_2_string(
                mmi_zakat_cntx_p->disp_calculate_result,
                mmi_zakat_cntx_p->small_items_amount * MMI_ZAKAT_COMMON_PERCENTAGE);
            kal_wsprintf(
                (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
                "%w%w\n%w\n\n",
                GetString(STR_ID_ZAKAT_ITEMS_NOT_EXCEED_NISAB),
                GetString(STR_ID_ZAKAT_COLON),
                mmi_zakat_cntx_p->disp_calculate_result);
            strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
        }
    }

    /* deductions */
    for (i = MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS;
         i <= MMI_ZAKAT_DEDUCTIONS_OTHERS;
         i++)
    {
        mmi_zakat_read_data_from_nvram(
            i,
            mmi_zakat_cntx_p->input_buffer_1,
            NULL);
        mmi_zakat_calculate_common_no_nisab_item_payable(
            i,
            mmi_zakat_cntx_p->disp_calculate_result,
            mmi_zakat_cntx_p->input_buffer_1);
        if (i == MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS)
        {
            strID = STR_ID_ZAKAT_PERSONAL_DEBTS;
        }
        else if (i == MMI_ZAKAT_DEDUCTIONS_BUSINESS)
        {
            strID = STR_ID_ZAKAT_BUSINESS;
        }
        else
        {
            strID = STR_ID_ZAKAT_OTHERS;
        }
        if (i == MMI_ZAKAT_DEDUCTIONS_OTHERS)
        {
            kal_wsprintf(
                (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
                "%w-%w%w\n%w",
                GetString(STR_ID_ZAKAT_DEDUCTIONS),
                GetString(strID),
                GetString(STR_ID_ZAKAT_COLON),
                mmi_zakat_cntx_p->disp_calculate_result);
            strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
        }
        else
        {
            kal_wsprintf(
                (WCHAR*)(mmi_zakat_cntx_p->disp_payable + strLen),
                "%w-%w%w\n%w\n\n",
                GetString(STR_ID_ZAKAT_DEDUCTIONS),
                GetString(strID),
                GetString(STR_ID_ZAKAT_COLON),
                mmi_zakat_cntx_p->disp_calculate_result);
            strLen = mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->disp_payable);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_double_2_string
 * DESCRIPTION
 *  convert double to string form
 * PARAMETERS
 *  buffer      [OUT]         buffer to store the string
 *  number      [IN]          data to be converted
 *  accuracy    [IN]          accuracy of double
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_double_2_string(U16 *buffer, double number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str[MMI_ZAKAT_MAX_NUMBER_LENGTH + 1];
    double doub;
    U32 bit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty string for 0 */
    if (number == 0)
    {
        buffer[0] = 0;
        return;
    }
    /* too small number */
    else if (number < MMI_ZAKAT_MIN_DOUBLE)
    {
        kal_wsprintf((WCHAR*)buffer, "0");
        return;
    }
    else if (number > MMI_ZAKAT_MAX_DOUBLE)
    {
        buffer[0] = 0;
        return;
    }

    /* integer count for livestock */
    if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_CAMELS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_COWS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_SHEEP)
    {
        doub = floor(number);
        sprintf(ansii_str, "%.0f", doub);
    }
    else
    {
        bit = 1;
        doub = number;
        while (doub >= 10)
        {
            bit++;
            doub /= 10;
        }
        if (bit == MMI_ZAKAT_MAX_NUMBER_LENGTH)
        {
            sprintf(ansii_str, "%.0f", number);
        }
        else
        {
            sprintf(
                ansii_str,
                "%*.*f",
                0,
                MMI_ZAKAT_MAX_NUMBER_LENGTH - 1 - bit,
                number);
        }
    }
    mmi_asc_to_ucs2((S8*)buffer, ansii_str);
    mmi_zakat_remove_zero_in_tail(buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_string_2_double
 * DESCRIPTION
 *  convert string to double
 * PARAMETERS
 *  buffer          [IN]      string to be converted
 *  numberPtr       [OUT]     buffer to store result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_string_2_double(U16 *buffer, double *numberPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str[MMI_ZAKAT_MAX_NUMBER_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(ansii_str, (S8*)buffer);
    *numberPtr = atof(ansii_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_input_valid_test
 * DESCRIPTION
 *  valid test for input
 * PARAMETERS
 *  void
 * RETURNS
 *  S32         test result
 *****************************************************************************/
static S32 mmi_zakat_input_valid_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double data1;
    double data2;
    double amount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* valid test for input_buffer_1 */
    if (mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->input_buffer_1) == 0)
    {
        if (mmi_zakat_cntx_p->input_buffer_2[0] != '.')
        {
            mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &data2);
            if (data2 != 0)
            {
                mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
            }
        }
        mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_GOLD_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
        return MMI_ZAKAT_NO_INPUT;
    }
    else if (mmi_zakat_cntx_p->input_buffer_1[0] == '.')
    {
        if (mmi_zakat_cntx_p->input_buffer_2[0] != '.')
        {
            mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &data2);
            if (data2 != 0)
            {
                mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
            }
        }
        mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_GOLD_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
        return MMI_ZAKAT_INVALID_DOUBLE;
    }
    else
    {
        mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_1, &data1);
        if (data1 == 0)
        {
            if (mmi_zakat_cntx_p->input_buffer_2[0] != '.')
            {
                mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &data2);
                if (data2 != 0)
                {
                    mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
                }
            }
            mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_GOLD_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
            return MMI_ZAKAT_INVALID_DOUBLE;
        }
        mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_1, data1);
        if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_PRICE ||
            mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_SILVER_PRICE)
        {
            mmi_zakat_read_data_from_nvram(MMI_ZAKAT_24_CARAT_GMS, NULL, &data2);
            amount = data1 * data2;
            if (amount > MMI_ZAKAT_MAX_DOUBLE)
            {
                if (mmi_zakat_cntx_p->input_buffer_2[0] != '.')
                {
                    mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &data2);
                    if (data2 != 0)
                    {
                        mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
                    }
                }
                mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_GOLD_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
                return MMI_ZAKAT_TOO_LARGE_RESULT;
            }
        }
    }

    /* items need to test two buffer */
    if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_GMS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_22_CARAT_GMS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_22_CARAT_PRICE ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_18_CARAT_GMS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_18_CARAT_PRICE ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_OTHER_GOLD_GMS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_OTHER_GOLD_PRICE ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_SILVER_GMS ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_PRICE ||
        mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_SILVER_PRICE)
    {
        /* common gold valid test for input buffer_2 */
        if (mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_24_CARAT_GMS &&
            mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_SILVER_GMS)
        {
            if (mmi_ucs2strlen((S8*)mmi_zakat_cntx_p->input_buffer_2) == 0)
            {
                mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_SILVER_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
                return MMI_ZAKAT_NO_INPUT;
            }
            else if (mmi_zakat_cntx_p->input_buffer_2[0] == '.')
            {
                mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_SILVER_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
                return MMI_ZAKAT_INVALID_DOUBLE;
            }
            mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &data2);
            if (data2 == 0)
            {
                mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_SILVER_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
                return MMI_ZAKAT_INVALID_DOUBLE;
            }
            mmi_zakat_double_2_string(mmi_zakat_cntx_p->input_buffer_2, data2);
        }
        else /* 24K gold and silver - get price for these two items */
        {
            if (mmi_zakat_cntx_p->curr_data_index == MMI_ZAKAT_24_CARAT_GMS)
            {
                mmi_zakat_read_data_from_nvram(
                    MMI_ZAKAT_24_CARAT_PRICE,
                    NULL,
                    &data2);
            }
            else
            {
                mmi_zakat_read_data_from_nvram(
                    MMI_ZAKAT_SILVER_PRICE,
                    NULL,
                    &data2);
            }
        }

        /* test for amount = gms * price */
        if (mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_24_CARAT_PRICE &&
            mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_SILVER_PRICE)
        {
            amount = data1 * data2;
            if (amount > MMI_ZAKAT_MAX_DOUBLE)
            {

                if (mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_24_CARAT_GMS &&
                    mmi_zakat_cntx_p->curr_data_index != MMI_ZAKAT_SILVER_GMS)
                {
                    mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_GOLD_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
                }
                return MMI_ZAKAT_TOO_LARGE_RESULT;
            }
        }
        else
        {
            mmi_zakat_string_2_double(mmi_zakat_cntx_p->input_buffer_2, &data1);
            mmi_zakat_read_data_from_nvram(MMI_ZAKAT_SILVER_GMS, NULL, &data2);
            amount = data1 * data2;
            if (amount > MMI_ZAKAT_MAX_DOUBLE)
            {
                mmi_zakat_cntx_p->highlighted_item = MMI_ZAKAT_NISAB_SILVER_PRICE_INFO + CUI_INLINE_ITEM_ID_BASE;
                return MMI_ZAKAT_TOO_LARGE_RESULT;
            }
        }
    }
    return MMI_ZAKAT_VALID_INPUT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_remove_zero_in_tail
 * DESCRIPTION
 *  remove zero in the string
 * PARAMETERS
 *  buffer      [IN]      input buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_remove_zero_in_tail(U16 *buffer)
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
    length = mmi_ucs2strlen((S8*)buffer);
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


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_zakat_tap_callback(mmi_tap_type_enum tap_type, S32 index)
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
 *  mmi_zakat_main_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_zakat_main_proc(mmi_event_struct *event)
{
    cui_menu_event_struct *menu_event = (cui_menu_event_struct*)event;
    switch (menu_event->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)event;
                switch (alert->result)
                {
                case MMI_ALERT_CNFM_YES:
                    mmi_zakat_reset();
                    break;
                case MMI_ALERT_CNFM_NO:
                    mmi_frm_scrn_close_active_id();
                    break;
                }
            }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                if (menu_event->parent_menu_id == MENU_ID_ZAKAT_CALCULATION)
                {
                    cui_menu_set_currlist_title(
                        mmi_zakat_cntx_p->main_menu_id,
                        (UI_string_type)GetString(STR_ID_ZAKAT_CALCULATION),
                        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
                }
                else if (menu_event->parent_menu_id == MENU_ID_ZAKAT_ASSETS)
                {
                    cui_menu_set_currlist_title(
                        mmi_zakat_cntx_p->main_menu_id,
                        (UI_string_type)GetString(STR_ID_ZAKAT_ASSETS),
                        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
                }
                else if (menu_event->parent_menu_id == MENU_ID_ZAKAT_DEDUCTIONS)
                {
                    cui_menu_set_currlist_title(
                        mmi_zakat_cntx_p->main_menu_id,
                        (UI_string_type)GetString(STR_ID_ZAKAT_DEDUCTIONS),
                        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
                }
                else if (menu_event->parent_menu_id == MENU_ID_ZAKAT_SETTINGS)
                {
                    cui_menu_set_currlist_title(
                        mmi_zakat_cntx_p->main_menu_id,
                        (UI_string_type)GetString(STR_GLOBAL_SETTINGS),
                        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
                }
                break;
            }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            {
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {

                break;
            }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                if (menu_event->highlighted_menu_id == MENU_ID_ZAKAT_RESET)
                {
                    mmi_zakat_reset_confirm();
                }
                else if (menu_event->highlighted_menu_id == MENU_ID_ZAKAT_NISAB)
                {
                    mmi_zakat_entry_nisab();
                }
                else if (menu_event->highlighted_menu_id == MENU_ID_ZAKAT_PAYABLE)
                {
                    mmi_zakat_entry_payable();
                }
                else
                {
                    switch (menu_event->highlighted_menu_id)
                    {
                        case MENU_ID_ZAKAT_CATTLE:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CATTLE;
                            break;
                        case MENU_ID_ZAKAT_AGRICULTURE:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_AGRICULTURE;
                            break;
                        case MENU_ID_ZAKAT_BULLION_CASH:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_BULLION_CASH;
                            break;
                        case MENU_ID_ZAKAT_BURIED_TREASURES:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_BURIED_TREASURES;
                            break;
                        case MENU_ID_ZAKAT_MINERALS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_MINERALS;
                            break;
                        case MENU_ID_ZAKAT_REVENUES:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_REVENUES;
                            break;
                        case MENU_ID_ZAKAT_COMMERCIAL_COMMODITIES:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_COMMERCIAL_COMMODITIES;
                            break;
                        case MENU_ID_ZAKAT_BUSINESS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_BUSINESS;
                            break;
                        case MENU_ID_ZAKAT_DEBTS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_DEBTS;
                            break;
                        case MENU_ID_ZAKAT_OTHERS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_OTHERS;
                            break;
                        case MENU_ID_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS;
                            break;
                        case MENU_ID_ZAKAT_DEDUCTIONS_BUSINESS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_DEDUCTIONS_BUSINESS;
                            break;
                        case MENU_ID_ZAKAT_DEDUCTIONS_OTHERS:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_DEDUCTIONS_OTHERS;
                            break;
                        default:
                            break;
                    }
                    if (menu_event->highlighted_menu_id != MENU_ID_ZAKAT_CALCULATION &&
                        menu_event->highlighted_menu_id != MENU_ID_ZAKAT_ASSETS &&
                        menu_event->highlighted_menu_id != MENU_ID_ZAKAT_DEDUCTIONS &&
                        menu_event->highlighted_menu_id != MENU_ID_ZAKAT_SETTINGS)
                    {
                        mmi_zakat_entry_description();
                    }
                }
                break;
            }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_close(mmi_zakat_cntx_p->main_menu_id);
                break;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_zakat_entry_main(void)
{
    mmi_zakat_cntx_p->main_gid = mmi_frm_group_create(
                                    GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_zakat_main_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(mmi_zakat_cntx_p->main_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->main_menu_id = cui_menu_create(
                                        mmi_zakat_cntx_p->main_gid,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_APPMAIN,
                                        MENU_ID_ZAKAT_CALCULATOR,
                                        MMI_FALSE,
                                        NULL);

    cui_menu_set_default_title(
        mmi_zakat_cntx_p->main_menu_id,
        (UI_string_type)GetString(STR_ID_ZAKAT_CALCULATOR),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
    cui_menu_set_default_left_softkey(
        mmi_zakat_cntx_p->main_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_OK));
    cui_menu_set_default_right_softkey(
        mmi_zakat_cntx_p->main_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_BACK));


    cui_menu_run(mmi_zakat_cntx_p->main_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_cattle_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_zakat_cattle_proc(mmi_event_struct *event)
{
    cui_menu_event_struct *menu_event = (cui_menu_event_struct*)event;
    switch (menu_event->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                mmi_frm_scrn_close(mmi_zakat_cntx_p->main_gid, SCR_ID_ZAKAT_DESCRIPTION);
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                switch (menu_event->highlighted_menu_id)
                {
                    case MENU_ID_ZAKAT_CAMELS:
                        mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CAMELS;
                        break;
                    case MENU_ID_ZAKAT_COWS:
                        mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_COWS;
                        break;
                    case MENU_ID_ZAKAT_SHEEP:
                        mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_SHEEP;
                        break;
                }
                mmi_zakat_entry_cattle_input();
                break;
            }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_close(mmi_zakat_cntx_p->cattle_menu_id);
                break;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_cattle
 * DESCRIPTION
 *  entry emnu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_cattle(void)
{
    mmi_zakat_cntx_p->cattle_gid = mmi_frm_group_create(
                                        GRP_ID_ROOT,
                                        GRP_ID_AUTO_GEN,
                                        mmi_zakat_cattle_proc,
                                        (void*)NULL);
    mmi_frm_group_enter(mmi_zakat_cntx_p->cattle_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->cattle_menu_id = cui_menu_create(
                                            mmi_zakat_cntx_p->cattle_gid,
                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                            CUI_MENU_TYPE_APPMAIN,
                                            MENU_ID_ZAKAT_CATTLE_MENUID,
                                            MMI_FALSE,
                                            NULL);

    cui_menu_set_default_title(
        mmi_zakat_cntx_p->cattle_menu_id,
        (UI_string_type)GetString(STR_ID_ZAKAT_CATTLE),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
    cui_menu_set_default_left_softkey(
        mmi_zakat_cntx_p->cattle_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_OK));
    cui_menu_set_default_right_softkey(
        mmi_zakat_cntx_p->cattle_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_BACK));

    cui_menu_run(mmi_zakat_cntx_p->cattle_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_agriculture_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_zakat_agriculture_proc(mmi_event_struct *event)
{
    cui_menu_event_struct *menu_event = (cui_menu_event_struct*)event;
    switch (menu_event->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                mmi_frm_scrn_close(mmi_zakat_cntx_p->main_gid, SCR_ID_ZAKAT_DESCRIPTION);
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                switch (menu_event->highlighted_menu_id)
                {
                    case MENU_ID_ZAKAT_BY_RAIN_WATER:
                        mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_BY_RAIN_WATER;
                        break;
                    case MENU_ID_ZAKAT_BY_IRRIGATION:
                        mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_BY_IRRIGATION;
                        break;
                    case MENU_ID_ZAKAT_BY_BOTH:
                        mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_BY_BOTH;
                        break;
                }
                mmi_zakat_entry_common_input();
                break;
            }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_close(mmi_zakat_cntx_p->agriculture_menu_id);
                break;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_agriculture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_agriculture(void)
{
    mmi_zakat_cntx_p->agriculture_gid = mmi_frm_group_create(
                                            GRP_ID_ROOT,
                                            GRP_ID_AUTO_GEN,
                                            mmi_zakat_agriculture_proc,
                                            (void*)NULL);
    mmi_frm_group_enter(mmi_zakat_cntx_p->agriculture_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->agriculture_menu_id = cui_menu_create(
                                                mmi_zakat_cntx_p->agriculture_gid,
                                                CUI_MENU_SRC_TYPE_RESOURCE,
                                                CUI_MENU_TYPE_APPMAIN,
                                                MENU_ID_ZAKAT_AGRICULTURE_MENUID,
                                                MMI_FALSE,
                                                NULL);

    cui_menu_set_default_title(
        mmi_zakat_cntx_p->agriculture_menu_id,
        (UI_string_type)GetString(STR_ID_ZAKAT_AGRICULTURE),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
    cui_menu_set_default_left_softkey(
        mmi_zakat_cntx_p->agriculture_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_OK));
    cui_menu_set_default_right_softkey(
        mmi_zakat_cntx_p->agriculture_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_BACK));

    cui_menu_run(mmi_zakat_cntx_p->agriculture_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_bullion_cash_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_zakat_bullion_cash_proc(mmi_event_struct *event)
{
    cui_menu_event_struct *menu_event = (cui_menu_event_struct*)event;
    switch (menu_event->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                mmi_frm_scrn_close(mmi_zakat_cntx_p->main_gid, SCR_ID_ZAKAT_DESCRIPTION);
                if (menu_event->parent_menu_id == MENU_ID_ZAKAT_GOLD)
                {
                    cui_menu_set_currlist_title(
                        mmi_zakat_cntx_p->bullion_cash_menu_id,
                        (UI_string_type)GetString(STR_ID_ZAKAT_GOLD),
                        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
                }
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                if (menu_event->highlighted_menu_id == MENU_ID_ZAKAT_GOLD)
                {
                    cui_menu_set_currlist_title(
                        mmi_zakat_cntx_p->bullion_cash_menu_id,
                        (UI_string_type)GetString(menu_event->highlighted_menu_id),
                        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
                }
                else
                {
                    switch (menu_event->highlighted_menu_id)
                    {
                        case MENU_ID_ZAKAT_24_CARAT:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_24_CARAT_GMS;
                            mmi_zakat_entry_silver_input();
                            break;
                        case MENU_ID_ZAKAT_22_CARAT:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_22_CARAT_GMS;
                            mmi_zakat_entry_gold_input();
                            break;
                        case MENU_ID_ZAKAT_18_CARAT:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_18_CARAT_GMS;
                            mmi_zakat_entry_gold_input();
                            break;
                        case MENU_ID_ZAKAT_OTHER_GOLD:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_OTHER_GOLD_GMS;
                            mmi_zakat_entry_gold_input();
                            break;
                        case MENU_ID_ZAKAT_SILVER:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_SILVER_GMS;
                            mmi_zakat_entry_silver_input();
                            break;
                        case MENU_ID_ZAKAT_CASH:
                            mmi_zakat_cntx_p->curr_data_index = MMI_ZAKAT_CASH;
                            mmi_zakat_entry_common_input();
                            break;
                    }
                }
                break;
            }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_close(mmi_zakat_cntx_p->bullion_cash_menu_id);
                break;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_zakat_entry_bullion_cash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_zakat_entry_bullion_cash(void)
{
    mmi_zakat_cntx_p->bullion_cash_gid = mmi_frm_group_create(
                                            GRP_ID_ROOT,
                                            GRP_ID_AUTO_GEN,
                                            mmi_zakat_bullion_cash_proc,
                                            (void*)NULL);
    mmi_frm_group_enter(mmi_zakat_cntx_p->bullion_cash_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_zakat_cntx_p->bullion_cash_menu_id = cui_menu_create(
                                                mmi_zakat_cntx_p->bullion_cash_gid,
                                                CUI_MENU_SRC_TYPE_RESOURCE,
                                                CUI_MENU_TYPE_APPMAIN,
                                                MENU_ID_ZAKAT_BULLION_CASH_MENUID,
                                                MMI_FALSE,
                                                NULL);

    cui_menu_set_default_title(
        mmi_zakat_cntx_p->bullion_cash_menu_id,
        (UI_string_type)GetString(STR_ID_ZAKAT_BULLION_CASH),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_ZAKAT_CALCULATOR)));
    cui_menu_set_default_left_softkey(
        mmi_zakat_cntx_p->bullion_cash_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_OK));
    cui_menu_set_default_right_softkey(
        mmi_zakat_cntx_p->bullion_cash_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_BACK));

    cui_menu_run(mmi_zakat_cntx_p->bullion_cash_menu_id);
}


static void mmi_zakat_change_softkey(mmi_id gid, U16 index, MMI_BOOL calculate)
{
    if (calculate == MMI_TRUE)
    {
        cui_inline_set_softkey_icon(gid, (U16)(CUI_INLINE_ITEM_ID_BASE + index), MMI_LEFT_SOFTKEY, 0);
        cui_inline_set_softkey_text(gid, (U16)(CUI_INLINE_ITEM_ID_BASE + index), MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
        cui_inline_set_softkey_icon(gid, (U16)(CUI_INLINE_ITEM_ID_BASE + index), MMI_RIGHT_SOFTKEY, 0);
        cui_inline_set_softkey_text(gid, (U16)(CUI_INLINE_ITEM_ID_BASE + index), MMI_RIGHT_SOFTKEY, STR_GLOBAL_RESET);
    }
    else
    {
        cui_inline_set_softkey_icon(gid, (U16)(CUI_INLINE_ITEM_ID_BASE + index), MMI_LEFT_SOFTKEY, IMG_GLOBAL_OK);
        cui_inline_set_softkey_text(gid, (U16)(CUI_INLINE_ITEM_ID_BASE + index), MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
    }
}
#endif /* __MMI_ZAKAT_CALCULATOR__ */ 

