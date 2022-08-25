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
 *  EngineerModeSSPSettings.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 * 
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
 * Include 
 *****************************************************************************/
//#include "MMI_include.h"
#include "mmi_features.h"
#include "MMIDataType.h"
#include "Menucuigprot.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "InlineCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "EngineerModeCommUI.h"
#include "EngineerModegProt.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommMem.h"
#include "wgui_categories_text_viewer.h"

#include "gui_effect_oem.h"
#include "gui_inputs.h"
#include "GlobalResDef.h"

#ifdef __MMI_EM_MISC_TOUCH_SCREEN__

// #undef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
extern void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
void mmi_em_ssp_settings_clear_variables();
void mmi_em_ssp_settings_set_variables();
void mmi_em_entry_ssp_settings_option_menu(void);
static mmi_ret mmi_em_setting_menu_proc_func(mmi_event_struct *evt);

/* Group or Screen informantion */
#define MMI_EM_LIST_SSP_GROUP_INFO                  1
#define MMI_EM_EDITOR_SSP_GROUP_INFO                2
#define MMI_EM_SETTINGS_OPTION_MENU_INFO            3
#define MMI_EM_LIST_SSP_PREVIEW_SCREEN_INFO         4
#define MMI_EM_EDITOR_SSP_PREVIEW_SCREEN_INFO       5

/* Preview screen parameter */
#define MENU_ID_EM_LIST_SSP_PREVIEW                 1000
#define MMI_EM_LIST_SSP_ITEM_COUNT                  (MAX_SUB_MENUS)
#define MMI_EM_EDITOR_SSP_BUFFER_SIZE               1000

#define MMI_EM_SSP_STATUS_TEXT_SIZE					(512 + 1)

static WCHAR *mmi_em_ssp_status_p = NULL;
static U32 mmi_em_ssp_status_info = 0;

static void mmi_em_entry_ssp_status_screen(void);


#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)

void mmi_em_get_inline_list_ssp_parameter(mmi_id inline_gid, gui_list_ssp_parameter_struct *list_ssp_param);
U16 mmi_em_convert_list_to_config_format(U16 item_id, float value);
void mmi_em_set_inline_list_ssp_parameter(mmi_id inline_gid);
float mmi_em_convert_config_to_list_format(U16 item_id, U16 val);

#define MMI_EM_LIST_SSP_RANGE_POS_DELTA             9
#define MMI_EM_LIST_SSP_RANGE_UPDATE_INTERVAL       10
#define MMI_EM_LIST_SSP_RANGE_THRESHOLD_TIME        18
#define MMI_EM_LIST_SSP_RANGE_MOVEMENT_Y_THRESOLD   25
#define MMI_EM_LIST_SSP_RANGE_SCROLL_COEFFICIENT    49
#define MMI_EM_LIST_SSP_RANGE_RECOVER_COEFFICIENT   49
#define MMI_EM_LIST_SSP_RANGE_SENSITIVITY           90
#define MMI_EM_LIST_SSP_RANGE_FOCUS_TO_HOLD_STATE_Y_THRESHOLD   37
#define MMI_EM_LIST_SSP_RANGE_LIMIT_COEFFICIENT     10

typedef enum MMI_EM_LIST_SSP_ITEM_ENUM
{
    MMI_EM_LIST_SSP_CAPTION_POS_DELTA = CUI_INLINE_ITEM_ID_BASE + 1,
    MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA,
    MMI_EM_LIST_SSP_CAPTION_UPDATE_INTERVAL,
    MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL,
    MMI_EM_LIST_SSP_CAPTION_THRESHOLD_TIME,
    MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME,
    MMI_EM_LIST_SSP_CAPTION_MOVEMENT_Y_THRESOLD,
    MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD,
    MMI_EM_LIST_SSP_CAPTION_SCROLL_COEFFICIENT,
    MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT,
    MMI_EM_LIST_SSP_CAPTION_RECOVER_COEFFICIENT,
    MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT,
    MMI_EM_LIST_SSP_CAPTION_SENSITIVITY,
    MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY,
    MMI_EM_LIST_SSP_CAPTION_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
    MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
    MMI_EM_LIST_SSP_CAPTION_LIMIT_COEFFICIENT,
    MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT
} MMI_EM_LIST_SSP_ITEM_ENUM;

static gui_list_ssp_parameter_struct *g_em_list_ssp_param;

static BOOL g_em_is_list_ssp_save;

static const cui_inline_item_progress_bar_struct g_em_ssp_post_delta = 
{
    0, MMI_EM_LIST_SSP_RANGE_POS_DELTA, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_update_interval = 
{
    0, MMI_EM_LIST_SSP_RANGE_UPDATE_INTERVAL, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_threshold_time = 
{
    0, MMI_EM_LIST_SSP_RANGE_THRESHOLD_TIME, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_movement_y_thresold = 
{
    0, MMI_EM_LIST_SSP_RANGE_MOVEMENT_Y_THRESOLD, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_scroll_coefficient = 
{
    0, MMI_EM_LIST_SSP_RANGE_SCROLL_COEFFICIENT, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_recover_coefficient = 
{
    0, MMI_EM_LIST_SSP_RANGE_RECOVER_COEFFICIENT, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_sensitivity = 
{
    0, MMI_EM_LIST_SSP_RANGE_SENSITIVITY, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_f2h_y_threshold = 
{
    0, MMI_EM_LIST_SSP_RANGE_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, 1
};

static const cui_inline_item_progress_bar_struct g_em_ssp_limit_coefficient = 
{
    0, MMI_EM_LIST_SSP_RANGE_LIMIT_COEFFICIENT, 1
};

static const cui_inline_set_item_struct g_mmi_em_list_ssp_inline_items[] = 
{
    {MMI_EM_LIST_SSP_CAPTION_POS_DELTA, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0, (void *)&g_em_ssp_post_delta},
    {MMI_EM_LIST_SSP_CAPTION_UPDATE_INTERVAL, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_update_interval},
    {MMI_EM_LIST_SSP_CAPTION_THRESHOLD_TIME, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_threshold_time},
    {MMI_EM_LIST_SSP_CAPTION_MOVEMENT_Y_THRESOLD, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_movement_y_thresold},
    {MMI_EM_LIST_SSP_CAPTION_SCROLL_COEFFICIENT, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_scroll_coefficient},
    {MMI_EM_LIST_SSP_CAPTION_RECOVER_COEFFICIENT, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_recover_coefficient},
    {MMI_EM_LIST_SSP_CAPTION_SENSITIVITY, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0, (void *)&g_em_ssp_sensitivity},
    {MMI_EM_LIST_SSP_CAPTION_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_f2h_y_threshold},
    {MMI_EM_LIST_SSP_CAPTION_LIMIT_COEFFICIENT, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_ssp_limit_coefficient},
};

static const cui_inline_item_softkey_struct g_mmi_em_ssp_inline_softkeys = 
{
    {
     {STR_GLOBAL_PREVIEW, 0},
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}
     }
};

static const cui_inline_struct g_mmi_em_list_ssp_inline = 
{
    sizeof(g_mmi_em_list_ssp_inline_items) / sizeof(cui_inline_set_item_struct),
    STR_ID_EM_LIST_SSP_SETTING,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_mmi_em_list_ssp_inline_items
};


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_list_ssp_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_entry_list_ssp_setting(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id list_ssp_gid, preview_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    preview_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, mmi_em_setting_menu_proc_func, (void*)parent_gid);

    mmi_frm_group_enter(preview_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
    list_ssp_gid = cui_inline_create(preview_gid, &g_mmi_em_list_ssp_inline);
    cui_inline_set_parent_data(list_ssp_gid, (U32) ((preview_gid << 16) | MMI_EM_LIST_SSP_GROUP_INFO));

    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_POS_DELTA, L"Scroll Distance");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_UPDATE_INTERVAL, L"Update Interval");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_THRESHOLD_TIME, L"Threshold Time");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_MOVEMENT_Y_THRESOLD, L"Movement Threshold");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_SCROLL_COEFFICIENT, L"Scroll Coefficient");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_RECOVER_COEFFICIENT, L"Recover Coefficient");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_SENSITIVITY, L"Sensitivity");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, L"Focus to Hold");
    cui_inline_set_value(list_ssp_gid, MMI_EM_LIST_SSP_CAPTION_LIMIT_COEFFICIENT, L"Limit Coefficient");

    mmi_em_set_inline_list_ssp_parameter(list_ssp_gid);

    cui_inline_run(list_ssp_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_list_ssp_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_entry_list_ssp_preview(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id preview_menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    preview_menu_gid = cui_menu_create(
                        parent_id,
                        CUI_MENU_SRC_TYPE_APPCREATE,
                        CUI_MENU_TYPE_APPMAIN,
                        MENU_ID_EM_LIST_SSP_PREVIEW,
                        MMI_TRUE,
                        (void*)((parent_id << 16) | MMI_EM_LIST_SSP_PREVIEW_SCREEN_INFO));
    cui_menu_set_default_title_string(preview_menu_gid, (WCHAR*) GetString(STR_GLOBAL_PREVIEW));
    cui_menu_run(preview_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_set_list_ssp_preview_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_set_list_ssp_preview_screen(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    mmi_menu_id root_ids[MMI_EM_LIST_SSP_ITEM_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EM_LIST_SSP_ITEM_COUNT; i++)
    {
        root_ids[i] = i;
    }
    cui_menu_set_currlist(menu_gid, MMI_EM_LIST_SSP_ITEM_COUNT, root_ids);

    for (i = 0; i < MMI_EM_LIST_SSP_ITEM_COUNT; i++)
    {
        cui_menu_set_item_string(menu_gid, i, (WCHAR*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS);
    cui_menu_set_currlist_left_softkey(menu_gid, (WCHAR*) GetString(STR_GLOBAL_SAVE));
	cui_menu_enable_tap_to_highlight(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_get_inline_list_ssp_parameter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inline_gid          [IN]        
 *  list_ssp_param      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_get_inline_list_ssp_parameter(mmi_id inline_gid, gui_list_ssp_parameter_struct *list_ssp_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA, &value);
    list_ssp_param->gui_menu_ssp_pos_delta =
        (U8) mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL, &value);
    list_ssp_param->gui_ssp_frame_update_interval =
        (U8) mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME, &value);
    list_ssp_param->gui_ssp_free_run_threshold_time =
        (U16) mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, &value);
    list_ssp_param->gui_ssp_free_run_movement_y_thresold =
        (U8) mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, &value);
    list_ssp_param->gui_ssp_free_run_scroll_coefficient = mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT, &value);
    list_ssp_param->gui_ssp_free_run_recover_coefficient = mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY, &value);
    list_ssp_param->gui_ssp_free_run_sensitivity = mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, &value);
    list_ssp_param->gui_ssp_focus_to_hold_state_y_threshold =
        (U8) mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT, &value);
    list_ssp_param->gui_ssp_menu_over_limit_coefficient = mmi_em_convert_config_to_list_format(MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT, value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_convert_config_to_list_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id     [IN]        
 *  val         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
float mmi_em_convert_config_to_list_format(U16 item_id, U16 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float value = (float)val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item_id)
    {
        case MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA:
        {
            return value + 1;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL:
        {
            return value;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME:
        {
            return (value + 2) * 50;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD:
        {
            return value + 5;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT:
        {
            return (float)(value + 50) * 0.01;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT:
        {
            return (float)(value + 50) * 0.01;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY:
        {
            return (float)(value + 10) * 0.001;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD:
        {
            return value + 3;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT:
        {
            return (float)(value * 0.1);
        }

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_convert_list_to_config_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id     [IN]        
 *  value       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_em_convert_list_to_config_format(U16 item_id, float value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item_id)
    {
        case MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA:
        {
            return (U16) (value - 1);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL:
        {
            return (U16) (value);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME:
        {
            return (U16) (value / 50) - 2;
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD:
        {
            return (U16) (value - 5);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT:
        {
            return (U16) (value * 100 - 50);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT:
        {
            return (U16) (value * 100 - 50);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY:
        {
            return (U16) (value * 1000 - 10);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD:
        {
            return (U16) (value - 3);
        }
        case MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT:
        {
            return (U16) (value * 10);
        }

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_set_inline_list_ssp_parameter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inline_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_set_inline_list_ssp_parameter(mmi_id inline_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_list_ssp_parameter_struct ssp_param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_ssp_get_parameter(&ssp_param);

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_POS_DELTA, ssp_param.gui_menu_ssp_pos_delta));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_UPDATE_INTERVAL, ssp_param.gui_ssp_frame_update_interval));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_THRESHOLD_TIME, ssp_param.gui_ssp_free_run_threshold_time));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, ssp_param.gui_ssp_free_run_movement_y_thresold));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, ssp_param.gui_ssp_free_run_scroll_coefficient));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_RECOVER_COEFFICIENT, ssp_param.gui_ssp_free_run_recover_coefficient));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_SENSITIVITY, ssp_param.gui_ssp_free_run_sensitivity));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
        (void*) mmi_em_convert_list_to_config_format (MMI_EM_LIST_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, ssp_param.gui_ssp_focus_to_hold_state_y_threshold));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT,
        (void*)mmi_em_convert_list_to_config_format(MMI_EM_LIST_SSP_PROGRASSBAR_LIMIT_COEFFICIENT, ssp_param.gui_ssp_menu_over_limit_coefficient));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_list_ssp_get_content
 * DESCRIPTION
 *  get list ssp data content
 * PARAMETERS
 *  void  
 * RETURNS
 *  data content text p
 *****************************************************************************/
static WCHAR *mmi_em_list_ssp_get_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *tmp_p = NULL, tmp_usc2[16];
	U8 tmp_asc[16];
	gui_list_ssp_parameter_struct ssp_param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_ssp_get_parameter(&ssp_param);
    tmp_p = (WCHAR*)MMI_EM_MALLOC((sizeof(WCHAR)*MMI_EM_SSP_STATUS_TEXT_SIZE));
    memset((char*)tmp_p, 0, (sizeof(WCHAR)*MMI_EM_SSP_STATUS_TEXT_SIZE));

	/* pos delta */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_MENU_SSP_POS_DELTA : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.gui_menu_ssp_pos_delta);
	/* update interval */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FRAME_UPDATE_INTERVAL : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.gui_ssp_frame_update_interval);
	/* threshold time */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FREE_RUN_THRESHOLD_TIME : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.gui_ssp_free_run_threshold_time);
    /* movement thresold */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FREE_RUN_MOVEMENT_Y_THRESOLD : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.gui_ssp_free_run_movement_y_thresold);
    /* scroll coefficient */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FREE_RUN_SCROLL_COEFFICIENT : ");
    memset((char*)tmp_asc, 0, sizeof(tmp_asc));
	sprintf(tmp_asc, "%.2fF \n", ssp_param.gui_ssp_free_run_scroll_coefficient);
	memset((char*)tmp_usc2, 0, sizeof(tmp_usc2));
	mmi_asc_to_ucs2((PS8) tmp_usc2, (PS8) tmp_asc);
	mmi_wcscat(tmp_p, (WCHAR*)tmp_usc2);
    /* recover coefficient */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FREE_RUN_RECOVER_COEFFICIENT : ");
    memset((char*)tmp_asc, 0, sizeof(tmp_asc));
	sprintf(tmp_asc, "%.2fF \n", ssp_param.gui_ssp_free_run_recover_coefficient);
	memset((char*)tmp_usc2, 0, sizeof(tmp_usc2));
	mmi_asc_to_ucs2((PS8) tmp_usc2, (PS8) tmp_asc);
	mmi_wcscat(tmp_p, (WCHAR*)tmp_usc2);
    /* sensitivity */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FREE_RUN_SENSITIVITY : ");
	memset((char*)tmp_asc, 0, sizeof(tmp_asc));
	sprintf(tmp_asc, "%.2fF \n", ssp_param.gui_ssp_free_run_sensitivity);
	memset((char*)tmp_usc2, 0, sizeof(tmp_usc2));
	mmi_asc_to_ucs2((PS8) tmp_usc2, (PS8) tmp_asc);
	mmi_wcscat(tmp_p, (WCHAR*)tmp_usc2);
	/* focus to hold */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_FOCUS_TO_HOLD_STATE_Y_THRESHOLD : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.gui_ssp_focus_to_hold_state_y_threshold);
    /* limit coefficient */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_SSP_MENU_OVER_LIMIT_COEFFICIENT : ");
    memset((char*)tmp_asc, 0, sizeof(tmp_asc));
	sprintf(tmp_asc, "%.1fF", ssp_param.gui_ssp_menu_over_limit_coefficient);
	memset((char*)tmp_usc2, 0, sizeof(tmp_usc2));
	mmi_asc_to_ucs2((PS8) tmp_usc2, (PS8) tmp_asc);
	mmi_wcscat(tmp_p, (WCHAR*)tmp_usc2);

	return tmp_p;
}

#endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 

/******************************** Editor SSP *************************************/

#ifdef __MMI_EDITOR_SSP_SUPPORT__

mmi_ret mmi_em_ssp_editor_preview_proc_func(mmi_event_struct *evt);
void mmi_em_get_inline_editor_ssp_parameter(mmi_id inline_gid, gui_input_box_ssp_params_struct *ssp_param);
void mmi_em_set_inline_editor_ssp_parameter(mmi_id inline_gid);
float mmi_em_convert_config_to_editor_format(U16 item_id, U16 val);

#define MMI_EM_EDITOR_SSP_RANGE_POS_DELTA             19
#define MMI_EM_EDITOR_SSP_RANGE_UPDATE_INTERVAL       10
#define MMI_EM_EDITOR_SSP_RANGE_THRESHOLD_TIME        19
#define MMI_EM_EDITOR_SSP_RANGE_MOVEMENT_Y_THRESOLD   25
#define MMI_EM_EDITOR_SSP_RANGE_SCROLL_COEFFICIENT    39
#define MMI_EM_EDITOR_SSP_RANGE_SENSITIVITY           15
#define MMI_EM_EDITOR_SSP_RANGE_FOCUS_TO_HOLD_STATE_Y_THRESHOLD   37
#define MMI_EM_EDITOR_SSP_RANGE_MASS_SPEED            7

typedef enum MMI_EM_EDITOR_SSP_ITEM_ENUM
{
    MMI_EM_EDITOR_SSP_CAPTION_POS_DELTA = CUI_INLINE_ITEM_ID_BASE + 1,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA,
    MMI_EM_EDITOR_SSP_CAPTION_UPDATE_INTERVAL,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL,
    MMI_EM_EDITOR_SSP_CAPTION_THRESHOLD_TIME,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME,
    MMI_EM_EDITOR_SSP_CAPTION_MOVEMENT_Y_THRESOLD,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD,
    MMI_EM_EDITOR_SSP_CAPTION_SCROLL_COEFFICIENT,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT,
    MMI_EM_EDITOR_SSP_CAPTION_SENSITIVITY,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY,
    MMI_EM_EDITOR_SSP_CAPTION_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
    MMI_EM_EDITOR_SSP_CAPTION_MASS_SPEED,
    MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED
} MMI_EM_EDITOR_SSP_ITEM_ENUM;

static gui_input_box_ssp_params_struct *g_em_editor_ssp_param;

static BOOL g_em_is_editor_ssp_save;

WCHAR *g_em_editor_ssp_preview_buffer = NULL;

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_post_delta = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_POS_DELTA, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_update_interval = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_UPDATE_INTERVAL, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_threshold_time = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_THRESHOLD_TIME, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_movement_y_thresold = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_MOVEMENT_Y_THRESOLD, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_scroll_coefficient = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_SCROLL_COEFFICIENT, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_sensitivity = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_SENSITIVITY, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_f2h_y_threshold = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, 1
};

static const cui_inline_item_progress_bar_struct g_em_editor_ssp_mass_speed = 
{
    0, MMI_EM_EDITOR_SSP_RANGE_MASS_SPEED, 1
};

static const cui_inline_set_item_struct g_mmi_em_editor_ssp_inline_items[] = 
{
    {MMI_EM_EDITOR_SSP_CAPTION_POS_DELTA, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_post_delta},
    {MMI_EM_EDITOR_SSP_CAPTION_UPDATE_INTERVAL, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_update_interval},
    {MMI_EM_EDITOR_SSP_CAPTION_THRESHOLD_TIME, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_threshold_time},
    {MMI_EM_EDITOR_SSP_CAPTION_MOVEMENT_Y_THRESOLD, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_movement_y_thresold},
    {MMI_EM_EDITOR_SSP_CAPTION_SCROLL_COEFFICIENT, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_scroll_coefficient},
    {MMI_EM_EDITOR_SSP_CAPTION_SENSITIVITY, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_sensitivity},
    {MMI_EM_EDITOR_SSP_CAPTION_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_f2h_y_threshold},
    {MMI_EM_EDITOR_SSP_CAPTION_MASS_SPEED, CUI_INLINE_ITEM_TYPE_CAPTION, 0, NULL},
    {MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED, CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,
     (void *)&g_em_editor_ssp_mass_speed},
};

static const cui_inline_item_softkey_struct g_mmi_em_editor_ssp_inline_softkeys = 
{
    {
     {STR_GLOBAL_PREVIEW, 0},
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}
     }
};

static const cui_inline_struct g_mmi_em_editor_ssp_inline = 
{
    sizeof(g_mmi_em_editor_ssp_inline_items) / sizeof(cui_inline_set_item_struct),
    STR_ID_EM_EDITOR_SSP_SETTING,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_mmi_em_editor_ssp_inline_items
};


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_editor_ssp_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_entry_editor_ssp_setting(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_ssp_gid, preview_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    preview_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, mmi_em_setting_menu_proc_func, (void*)parent_gid);

    mmi_frm_group_enter(preview_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
    editor_ssp_gid = cui_inline_create(preview_gid, &g_mmi_em_editor_ssp_inline);
    cui_inline_set_parent_data(editor_ssp_gid, (U32) ((preview_gid << 16) | MMI_EM_EDITOR_SSP_GROUP_INFO));

    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_POS_DELTA, L"Scroll Distance");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_UPDATE_INTERVAL, L"Update Interval");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_THRESHOLD_TIME, L"Threshold Time");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_MOVEMENT_Y_THRESOLD, L"Movement Threshold");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_SCROLL_COEFFICIENT, L"Scroll Coefficient");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_SENSITIVITY, L"Sensitivity");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, L"Focus to Hold");
    cui_inline_set_value(editor_ssp_gid, MMI_EM_EDITOR_SSP_CAPTION_MASS_SPEED, L"Mass Speed");

    mmi_em_set_inline_editor_ssp_parameter(editor_ssp_gid);

    cui_inline_run(editor_ssp_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_editor_ssp_preview_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_entry_editor_ssp_preview_screen(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id preview_gid = 0, fseditor_gid;
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    preview_gid = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, mmi_em_ssp_editor_preview_proc_func, (void*)parent_id);

    mmi_frm_group_enter(preview_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    fseditor_gid = cui_fseditor_create(preview_gid);
    cui_fseditor_set_title(fseditor_gid, STR_GLOBAL_PREVIEW, 0);
    cui_fseditor_set_parent_data(fseditor_gid, (U32) ((preview_gid << 16) | MMI_EM_EDITOR_SSP_PREVIEW_SCREEN_INFO));

    ASSERT(g_em_editor_ssp_preview_buffer == NULL);

    g_em_editor_ssp_preview_buffer = (WCHAR*) MMI_EM_MALLOC(MMI_EM_EDITOR_SSP_BUFFER_SIZE);

	for (i = 0; i < (MMI_EM_EDITOR_SSP_BUFFER_SIZE / 2 - 1); i++)
	{
	    if (i%2)
	    {
	        g_em_editor_ssp_preview_buffer[i] = ('\n');
	    }
		else
		{
	        g_em_editor_ssp_preview_buffer[i] = ('0' + j);
			if (j >= 9)
			{
			    j = 0;
			}
			j++;
		}
	}

    cui_fseditor_set_text(
        fseditor_gid,
        g_em_editor_ssp_preview_buffer,
        MMI_EM_EDITOR_SSP_BUFFER_SIZE,
        MMI_EM_EDITOR_SSP_BUFFER_SIZE / 2 - 1);

	cui_fseditor_set_softkey_text(
		fseditor_gid,
		MMI_LEFT_SOFTKEY,
		STR_GLOBAL_SAVE);

    cui_fseditor_run(fseditor_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_get_inline_editor_ssp_parameter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inline_gid      [IN]        
 *  ssp_param       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_get_inline_editor_ssp_parameter(mmi_id inline_gid, gui_input_box_ssp_params_struct *ssp_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA, &value);
    ssp_param->pos_delta = (U8) mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL, &value);
    ssp_param->free_run_update_frame_interval =
        (U8) mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME, &value);
    ssp_param->free_run_threshold_time =
        (U16) mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, &value);
    ssp_param->free_run_move_y_threshold =
        (U8) mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, &value);
    ssp_param->free_run_scroll_coefficient = mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY, &value);
    ssp_param->free_run_sensitivity = mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY, value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, &value);
    ssp_param->focus_to_move_y_threshold =
        (U8) mmi_em_convert_config_to_editor_format(
                MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
                value);
    value = 0;

    cui_inline_get_value(inline_gid, MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED, &value);
    ssp_param->free_run_mass_range_threshold_speed =
        (U16) mmi_em_convert_config_to_editor_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED, value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_convert_config_to_editor_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id     [IN]        
 *  val         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
float mmi_em_convert_config_to_editor_format(U16 item_id, U16 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float value = (float)val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item_id)
    {
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA:
        {
            return value + 1;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL:
        {
            return value;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME:
        {
            return (value + 2) * 50;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD:
        {
            return value + 5;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT:
        {
            return (float)(value + 60) * 0.01;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY:
        {
            return (float)(value + 5) * 0.01;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD:
        {
            return value + 3;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED:
        {
            return (float)(value + 8) * 100;
        }

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_convert_editor_to_config_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id     [IN]        
 *  value       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_em_convert_editor_to_config_format(U16 item_id, float value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item_id)
    {
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA:
        {
            return (U16) (value - 1);
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL:
        {
            return (U16) (value);
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME:
        {
            return (U16) (value / 50) - 2;
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD:
        {
            return (U16) (value - 5);
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT:
        {
            return (U16) (value * 100 - 60);
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY:
        {
            return (U16) (value * 100 - 5);
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD:
        {
            return (U16) (value - 3);
        }
        case MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED:
        {
            return (U16) (value - 800) / 100;
        }

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_set_inline_editor_ssp_parameter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inline_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_set_inline_editor_ssp_parameter(mmi_id inline_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_input_box_ssp_params_struct ssp_param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_input_box_ssp_get_parameters(&ssp_param);

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA,
        (void*)mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_POS_DELTA, ssp_param.pos_delta));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL,
        (void*)mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_UPDATE_INTERVAL, ssp_param.free_run_update_frame_interval));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME,
        (void*)mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_THRESHOLD_TIME, ssp_param.free_run_threshold_time));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD,
        (void*) mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_MOVEMENT_Y_THRESOLD, ssp_param.free_run_move_y_threshold));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT,
        (void*) mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_SCROLL_COEFFICIENT, ssp_param.free_run_scroll_coefficient));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY,
        (void*)mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_SENSITIVITY, ssp_param.free_run_sensitivity));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD,
        (void*) mmi_em_convert_editor_to_config_format (MMI_EM_EDITOR_SSP_PROGRASSBAR_FOCUS_TO_HOLD_STATE_Y_THRESHOLD, ssp_param.focus_to_move_y_threshold));

    cui_inline_set_value(
        inline_gid,
        MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED,
        (void*)mmi_em_convert_editor_to_config_format(MMI_EM_EDITOR_SSP_PROGRASSBAR_MASS_SPEED, ssp_param.free_run_mass_range_threshold_speed));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_ssp_editor_preview_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_em_ssp_editor_preview_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *ext_evt = (mmi_group_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        {
            U32 group_info = cui_fseditor_get_parent_data(ext_evt->sender_id);

            if ((group_info & 0xFF) == MMI_EM_EDITOR_SSP_PREVIEW_SCREEN_INFO)
            {
                g_em_is_editor_ssp_save = 1;
                mmi_em_ssp_status_info = group_info;
                mmi_em_entry_ssp_status_screen();
            }
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_close(ext_evt->sender_id);
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            MMI_EM_FREE(g_em_editor_ssp_preview_buffer);
            g_em_editor_ssp_preview_buffer = NULL;
            if (g_em_is_editor_ssp_save == 1)
            {
                mmi_frm_group_close((MMI_ID) (ext_evt->user_data));
            }
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_editor_ssp_get_content
 * DESCRIPTION
 *  get editor ssp data content
 * PARAMETERS
 *  void  
 * RETURNS
 *  data content text p
 *****************************************************************************/
static WCHAR *mmi_em_editor_ssp_get_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *tmp_p = NULL, tmp_usc2[16];
	U8 tmp_asc[16];
	gui_input_box_ssp_params_struct ssp_param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_input_box_ssp_get_parameters(&ssp_param);
    tmp_p = (WCHAR*)MMI_EM_MALLOC((sizeof(WCHAR)*MMI_EM_SSP_STATUS_TEXT_SIZE));
    memset((char*)tmp_p, 0, (sizeof(WCHAR)*MMI_EM_SSP_STATUS_TEXT_SIZE));
    
	/* pos delta */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_POS_DELTA : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.pos_delta);
	/* update interval */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FRAME_UPDATE_INTERVAL : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.free_run_update_frame_interval);
	/* threshold time */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FREE_RUN_THRESHOLD_TIME : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.free_run_threshold_time);
    /* movement thresold */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FREE_RUN_MOVEMENT_Y_THRESOLD : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.free_run_move_y_threshold);
    /* scroll coefficient */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FREE_RUN_SCROLL_COEFFICIENT : ");
    memset((char*)tmp_asc, 0, sizeof(tmp_asc));
	sprintf(tmp_asc, "%.2fF \n", ssp_param.free_run_scroll_coefficient);
	memset((char*)tmp_usc2, 0, sizeof(tmp_usc2));
	mmi_asc_to_ucs2((PS8) tmp_usc2, (PS8) tmp_asc);
	mmi_wcscat(tmp_p, (WCHAR*)tmp_usc2);
    /* sensitivity */
	mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FREE_RUN_SENSITIVITY : ");
	memset((char*)tmp_asc, 0, sizeof(tmp_asc));
	sprintf(tmp_asc, "%.1fF \n", ssp_param.free_run_sensitivity);
	memset((char*)tmp_usc2, 0, sizeof(tmp_usc2));
	mmi_asc_to_ucs2((PS8) tmp_usc2, (PS8) tmp_asc);
	mmi_wcscat(tmp_p, (WCHAR*)tmp_usc2);
	/* focus to hold */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FOCUS_TO_HOLD_STATE_Y_THRESHOLD : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d \n", ssp_param.focus_to_move_y_threshold);
	/* mass speed */
    mmi_wcscat(tmp_p, (WCHAR*)L"GUI_INPUT_BOX_SSP_FREE_RUN_MASS_RANGE_SPEED : ");
    kal_wsprintf(&tmp_p[mmi_wcslen(tmp_p)], "%d", ssp_param.free_run_mass_range_threshold_speed);

	return tmp_p;
}

#endif /* __MMI_EDITOR_SSP_SUPPORT__ */ 

/*************************************  Option  Function  ***********************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_em_exit_ssp_status_screen
 * DESCRIPTION
 *  exit status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_exit_ssp_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_FREE(mmi_em_ssp_status_p);
	mmi_em_ssp_status_p = NULL;
	mmi_em_ssp_status_info = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_ssp_status_lsk
 * DESCRIPTION
 *  confirm and back to ssp setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_ssp_status_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close((MMI_ID)(mmi_em_ssp_status_info >> 16));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_ssp_status_screen
 * DESCRIPTION
 *  entry ssp status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_entry_ssp_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 size = 0;
	MMI_BOOL ret;
	U8 *guiBuffer;
	U16 group_id = 0, screen_info = 0, title_id = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	group_id = (U16)(mmi_em_ssp_status_info >> 16);
	screen_info = (U16)(mmi_em_ssp_status_info & 0xff);
	ASSERT(mmi_em_ssp_status_p == NULL);
	if (screen_info == MMI_EM_LIST_SSP_PREVIEW_SCREEN_INFO)
	{
	#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
	    mmi_em_ssp_status_p = (WCHAR*)mmi_em_list_ssp_get_content();
	#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
	    title_id = STR_ID_EM_LIST_SSP_DATA;
	}
	else if (screen_info == MMI_EM_EDITOR_SSP_PREVIEW_SCREEN_INFO)
	{
	#if defined(__MMI_EDITOR_SSP_SUPPORT__)
	    mmi_em_ssp_status_p = (WCHAR*)mmi_em_editor_ssp_get_content();
	#endif /* __MMI_EDITOR_SSP_SUPPORT__ */
	    title_id = STR_ID_EM_EDITOR_SSP_DATA;
	}

	size = sizeof(WCHAR)*mmi_wcslen(mmi_em_ssp_status_p);

    ret = mmi_frm_scrn_enter(
            group_id, 
            SCR_ID_EM_SSP_STATUS, 
            mmi_em_exit_ssp_status_screen, 
            mmi_em_entry_ssp_status_screen, 
            MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

	guiBuffer = mmi_frm_scrn_get_active_gui_buf();

	ShowCategory74Screen(
		title_id,
		0,
		STR_GLOBAL_OK,
		0,
		0,
		0,
		(U8*)mmi_em_ssp_status_p,
		size,
		guiBuffer);

	SetLeftSoftkeyFunction(mmi_em_ssp_status_lsk, KEY_EVENT_UP);   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_option_menu_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_em_option_menu_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_menu_is_menu_event(evt->evt_id))
    {
        switch (evt->evt_id)
        {
            case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                cui_menu_close(menu_evt->sender_id);
                break;

            case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                /* Option menu screen */
                if (((U32) (menu_evt->app_data) & 0xFF) == MMI_EM_SETTINGS_OPTION_MENU_INFO)
                {
                #if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                    if (menu_evt->highlighted_menu_id == MENU_ID_LIST_SSP_SETTING)
                    {
                        mmi_em_entry_list_ssp_setting((MMI_ID) ((U32) (menu_evt->app_data) >> 16));
                    }
                    if (menu_evt->highlighted_menu_id == MENU_ID_LIST_SSP_DEFAULT_VALUE)
                    {
                        gui_list_ssp_reset_parameter();
                        mmi_em_success_popup();
                    }
                #endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 

                #ifdef __MMI_EDITOR_SSP_SUPPORT__
                    if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_SSP_SETTING)
                    {
                        mmi_em_entry_editor_ssp_setting((MMI_ID) ((U32) (menu_evt->app_data) >> 16));
                    }
                    if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_SSP_DEFAULT_VALUE)
                    {
                        /* Finish me. */
                        gui_input_box_ssp_reset_parameter();
                        mmi_em_success_popup();
                    }
                #endif /* __MMI_EDITOR_SSP_SUPPORT__ */ 

                }
                break;
            }
            case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                /* Option menu screen */
                if (((U32) (menu_evt->app_data) & 0xFF) == MMI_EM_SETTINGS_OPTION_MENU_INFO)
                {
                #if !defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                    cui_menu_set_item_hidden(menu_evt->sender_id, (MMI_MENU_ID)MENU_ID_LIST_SSP_SETTING, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, (MMI_MENU_ID)MENU_ID_LIST_SSP_DEFAULT_VALUE, MMI_TRUE);
                #endif /* !defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 

                #if !defined(__MMI_EDITOR_SSP_SUPPORT__)
                    cui_menu_set_item_hidden(menu_evt->sender_id, (MMI_MENU_ID)MENU_ID_EDITOR_SSP_SETTING, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, (MMI_MENU_ID)MENU_ID_EDITOR_SSP_DEFAULT_VALUE, MMI_TRUE);
                #endif /* !defined(__MMI_EDITOR_SSP_SUPPORT__) */ 
                    cui_menu_set_currlist_title_by_id(menu_evt->sender_id, STR_ID_EM_MAIN_SSP_SETTINGS, 0);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                }
                break;
            }
            default:
                break;
        }
    }
    else
    {
        switch (evt->evt_id)
        {
            case EVT_ID_GROUP_ENTER:
            {
                mmi_em_ssp_settings_set_variables();
                break;
            }
            case EVT_ID_GROUP_DEINIT:
            {
                mmi_em_ssp_settings_clear_variables();
                break;
            }
            default:
                break;
        }
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_setting_menu_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_em_setting_menu_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    mmi_group_event_struct *ext_evt = (mmi_group_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_menu_is_menu_event(evt->evt_id))
    {
        switch (evt->evt_id)
        {
            case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                cui_menu_close(menu_evt->sender_id);
                break;

            case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                /* List preview screen */
            #if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                if (((U32) (menu_evt->app_data) & 0xFF) == MMI_EM_LIST_SSP_PREVIEW_SCREEN_INFO)
                {
                    g_em_is_list_ssp_save = 1;
					mmi_em_ssp_status_info = (U32) (menu_evt->app_data);
					mmi_em_entry_ssp_status_screen();
                }
            #endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 
                break;
            }
            case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
            #if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                if (((U32) (menu_evt->app_data) & 0xFF) == MMI_EM_LIST_SSP_PREVIEW_SCREEN_INFO)
                {
                    if (menu_evt->parent_menu_id == MENU_ID_EM_LIST_SSP_PREVIEW)
                    {
                        mmi_em_set_list_ssp_preview_screen(menu_evt->sender_id);
                    }
                }
            #endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 
            }
            default:
                break;
        }
    }
    else
    {
        switch (evt->evt_id)
        {
            case EVT_ID_CUI_INLINE_CSK_PRESS:
            case EVT_ID_CUI_INLINE_SUBMIT:
            {
                U32 group_info = cui_inline_get_parent_data(ext_evt->sender_id);

            #if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                /* Inline Screen for List SSP setting */
                if ((group_info & 0xFF) == MMI_EM_LIST_SSP_GROUP_INFO)
                {
                    gui_list_ssp_parameter_struct list_ssp_param;

                    mmi_em_entry_list_ssp_preview(group_info >> 16);
                    mmi_em_get_inline_list_ssp_parameter(ext_evt->sender_id, &list_ssp_param);
                    gui_list_ssp_set_parameter(&list_ssp_param);
                }
            #endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 
            #ifdef __MMI_EDITOR_SSP_SUPPORT__
                /* Inline Screen for Editor SSP setting */
                if ((group_info & 0xFF) == MMI_EM_EDITOR_SSP_GROUP_INFO)
                {
                    gui_input_box_ssp_params_struct editor_ssp_param;

                    mmi_em_entry_editor_ssp_preview_screen(group_info >> 16);
                    mmi_em_get_inline_editor_ssp_parameter(ext_evt->sender_id, &editor_ssp_param);
                    gui_input_box_ssp_set_parameters(&editor_ssp_param);
                }
            #endif /* __MMI_EDITOR_SSP_SUPPORT__ */ 
                break;
            }
            case EVT_ID_CUI_INLINE_ABORT:
            {
                mmi_frm_group_close(ext_evt->sender_id);
                break;
            }
            case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            {
                U32 group_info = cui_inline_get_parent_data(ext_evt->sender_id);

            #if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                /* Inline Screen for List SSP setting */
                if ((group_info & 0xFF) == MMI_EM_LIST_SSP_GROUP_INFO)
                {
                    if (g_em_is_list_ssp_save == 0)
                    {
                        gui_list_ssp_set_parameter(g_em_list_ssp_param);
                    }
                    /* Clear global variable. */
                    g_em_is_list_ssp_save = 0;
                }
            #endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */ 
            #ifdef __MMI_EDITOR_SSP_SUPPORT__
                /* Inline Screen for Editor SSP setting */
                if ((group_info & 0xFF) == MMI_EM_EDITOR_SSP_GROUP_INFO)
                {
                    if (g_em_is_editor_ssp_save == 0)
                    {
                        gui_input_box_ssp_set_parameters(g_em_editor_ssp_param);
                    }
                    /* Clear global variable. */
                    g_em_is_editor_ssp_save = 0;
                }
            #endif /* __MMI_EDITOR_SSP_SUPPORT__ */ 
            }
            default:
                break;
        }
    }
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_ssp_settings_option_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_entry_ssp_settings_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id option_menu_gid;
    mmi_id option_menu_parent_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !(defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) || defined(__MMI_EDITOR_SSP_SUPPORT__))

    mmi_em_fail_popup();

#else /* !(defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) || defined(__MMI_EDITOR_SSP_SUPPORT__)) */ 

    option_menu_parent_gid = mmi_frm_group_create(mmi_em_get_root_group(), GRP_ID_AUTO_GEN, mmi_em_option_menu_proc_func, NULL);

    mmi_frm_group_enter(option_menu_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    option_menu_gid = cui_menu_create(
                        option_menu_parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_SSP_SETTINGS_OPTION,
                        MMI_TRUE,
                        (void*)((option_menu_parent_gid << 16) | MMI_EM_SETTINGS_OPTION_MENU_INFO));

    cui_menu_run(option_menu_gid);

#endif /* !(defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) || defined(__MMI_EDITOR_SSP_SUPPORT__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_ssp_settings_clear_variables
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_ssp_settings_clear_variables()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if(g_em_list_ssp_param != NULL)
    {
        MMI_EM_FREE(g_em_list_ssp_param);
        g_em_list_ssp_param = NULL;    
    }
#endif 

#if defined(__MMI_EDITOR_SSP_SUPPORT__)
    if(g_em_editor_ssp_param != NULL)
    {
        MMI_EM_FREE(g_em_editor_ssp_param);
        g_em_editor_ssp_param = NULL;  
    }
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_ssp_settings_set_variables
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_ssp_settings_set_variables()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if(g_em_list_ssp_param == NULL)
    {
        g_em_list_ssp_param = (gui_list_ssp_parameter_struct*) MMI_EM_MALLOC(sizeof(gui_list_ssp_parameter_struct));
    }
    gui_list_ssp_get_parameter(g_em_list_ssp_param);
#endif 

#if defined(__MMI_EDITOR_SSP_SUPPORT__)
    if(g_em_editor_ssp_param == NULL)
    {
        g_em_editor_ssp_param = (gui_input_box_ssp_params_struct *) MMI_EM_MALLOC(sizeof(gui_input_box_ssp_params_struct));   
    }
    gui_input_box_ssp_get_parameters(g_em_editor_ssp_param);
#endif 

}


#endif
