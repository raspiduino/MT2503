/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  EngineerModeFRMProfiling.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is Engineering mode Profiling for these features:
 *  - Interactive Profiling
 *  - UI Benchmark
 *  - Memory Monitor
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#include "CommonScreens.h"

//#include "SettingProfile.h"
#include "ProfilesSrvGProt.h"
#include "menucuigprot.h"

#if defined(__MMI_INTERACTIVE_PROFILNG__) || defined(__MMI_UI_BENCHMARK__)
#include "ProfilingEngine.h"
#endif

#include "EngineerModeFRMProfiling.h"

#include "EngineerModeCommUI.h"
#include "InlineCuiGprot.h"


#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "mmi_frm_history_gprot.h"
#include "kal_general_types.h"
#include "stdlib.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_inline_edit.h"
#include "ImeGprot.h"
#include "wgui_categories_popup.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "app_mem.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "EngineerModeUtil.h"

#if defined(__MMI_EM_MISC_TOUCH_SCREEN__) && defined(__COSMOS_MMI__)
#include "vapp_gesture_test_gprot.h"
#endif
#if defined (__MMI_CSB_BROWSER__)
#include "CatScreenBrowserProts.h"
#endif

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_INTERACTIVE_PROFILNG__

//static MMI_BOOL frm_profiling_flag;
static mmi_em_profiling_struct g_em_profiling_cntx;

#endif /* __MMI_INTERACTIVE_PROFILNG__ */


#ifdef __MMI_UI_BENCHMARK__

static const U8 *g_ui_benchmark_buffer_p;

#endif /* __MMI_UI_BENCHMARK__ */
#ifdef __MMI_EM_PROFILING_SWLA__
#include "SST_sla.h"
#define MMI_EM_PROFILING_SWLA_INFOR_LEN                   100
#endif
/***************************************************************************** 
 * Local Function
 *****************************************************************************/



#ifdef __MMI_UI_BENCHMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_ui_bench_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_ui_bench_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_benchmark_stop();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_ui_bench_result_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_ui_bench_result_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_UI_BENCHMARK_RESULT, NULL, mmi_em_profiling_ui_bench_result_entry, NULL);

    bufferSize = mmi_ucs2strlen((S8*)g_ui_benchmark_buffer_p);

    ShowCategory74Screen(
        STR_ID_EM_PROFILING_UI_BENCHMARK,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (PU8) g_ui_benchmark_buffer_p,
        bufferSize,
        NULL);


    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    DeleteScreenIfPresent(SCR_ID_EM_PROFILING_UI_BENCHMARK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_ui_bench_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_ui_bench_callback(const U8 *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ui_benchmark_buffer_p = message;

    mmi_em_profiling_ui_bench_result_entry();
}
#endif /* __MMI_UI_BENCHMARK__ */


/*****************************************************************************
 * Global Function
 *****************************************************************************/

#ifdef __MMI_INTERACTIVE_PROFILNG__

MMI_ID mmi_em_profiling_frm_group_id;

#define MMI_EM_PROFILING_FRM_DISPLAY_TIME_CAPTION                (CUI_INLINE_ITEM_ID_BASE + 10)
#define MMI_EM_PROFILING_FRM_DISPLAY_TIME_SELECT                 (CUI_INLINE_ITEM_ID_BASE + 11)
#define MMI_EM_PROFILING_FRM_IMAGE_PROFILE_CAPTION               (CUI_INLINE_ITEM_ID_BASE + 12)
#define MMI_EM_PROFILING_FRM_IMAGE_PROFILE_SELECT                (CUI_INLINE_ITEM_ID_BASE + 13)
#define MMI_EM_PROFILING_FRM_SCREEN_DELAY_CAPTION                (CUI_INLINE_ITEM_ID_BASE + 14)
#define MMI_EM_PROFILING_FRM_SCREEN_DELAY_EDIT                   (CUI_INLINE_ITEM_ID_BASE + 15)
#define MMI_EM_PROFILING_FRM_LIST_DELAY_CAPTION                  (CUI_INLINE_ITEM_ID_BASE + 16)
#define MMI_EM_PROFILING_FRM_LIST_DELAY_EDIT                     (CUI_INLINE_ITEM_ID_BASE + 17)
#define MMI_EM_PROFILING_FRM_MATRIX_DELAY_CAPTION                (CUI_INLINE_ITEM_ID_BASE + 18)
#define MMI_EM_PROFILING_FRM_MATRIX_DELAY_EDIT                   (CUI_INLINE_ITEM_ID_BASE + 19)
#define MMI_EM_PROFILING_FRM_TIME_OFFSET_CAPTION                 (CUI_INLINE_ITEM_ID_BASE + 20)
#define MMI_EM_PROFILING_FRM_TIME_OFFSET_EDIT                    (CUI_INLINE_ITEM_ID_BASE + 21)

static U16 mmi_em_profiling_frm_display_time_select_str[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static U16 mmi_em_profiling_frm_image_profile_select_str[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};

static cui_inline_item_caption_struct mmi_em_profiling_frm_display_time_caption =
{
    STR_ID_EM_PROFILING_FRM_DISPLAY_TIME_TEXT
};

static cui_inline_item_select_struct mmi_em_profiling_frm_display_time_select =
{
    2,
    0,
    mmi_em_profiling_frm_display_time_select_str
};

static cui_inline_item_caption_struct mmi_em_profiling_frm_image_profile_caption =
{
    STR_ID_EM_PROFILING_FRM_GDI_PROFILE_TEXT
};

static cui_inline_item_select_struct mmi_em_profiling_frm_image_profile_select =
{
    2,
    0,
    mmi_em_profiling_frm_image_profile_select_str
};

static cui_inline_item_caption_struct mmi_em_profiling_frm_screen_delay_caption =
{
    STR_ID_EM_PROFILING_FRM_SCREEN_DELAY_TEXT
};

static cui_inline_item_text_edit_struct mmi_em_profiling_frm_screen_delay_editor =
{
    0,
    0,
    MMI_EM_MAX_PROFILING_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

static cui_inline_item_caption_struct mmi_em_profiling_frm_list_delay_caption =
{
    STR_ID_EM_PROFILING_FRM_LIST_DELAY_TEXT
};

static cui_inline_item_text_edit_struct mmi_em_profiling_frm_list_delay_editor =
{
    0,
    0,
    MMI_EM_MAX_PROFILING_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

static cui_inline_item_caption_struct mmi_em_profiling_frm_matrix_delay_caption =
{
    STR_ID_EM_PROFILING_FRM_MATRIX_DELAY_TEXT
};

static cui_inline_item_text_edit_struct mmi_em_profiling_frm_matrix_delay_editor =
{
    0,
    0,
    MMI_EM_MAX_PROFILING_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

static cui_inline_item_caption_struct mmi_em_profiling_frm_time_offset_delay_caption =
{
    STR_ID_EM_PROFILING_FRM_DELAY_OFFSET_TEXT
};

static cui_inline_item_text_edit_struct mmi_em_profiling_frm_time_offset_delay_editor =
{
    0,
    0,
    MMI_EM_MAX_PROFILING_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

const cui_inline_set_item_struct mmi_em_profiling_frm_items[] =
{
    {MMI_EM_PROFILING_FRM_DISPLAY_TIME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&mmi_em_profiling_frm_display_time_caption},
    {MMI_EM_PROFILING_FRM_DISPLAY_TIME_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, NULL, (void*)&mmi_em_profiling_frm_display_time_select},
    {MMI_EM_PROFILING_FRM_IMAGE_PROFILE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&mmi_em_profiling_frm_image_profile_caption},
    {MMI_EM_PROFILING_FRM_IMAGE_PROFILE_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, NULL, (void*)&mmi_em_profiling_frm_image_profile_select},
    {MMI_EM_PROFILING_FRM_SCREEN_DELAY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION,  IMG_GLOBAL_L3, (void*)&mmi_em_profiling_frm_screen_delay_caption},
    {MMI_EM_PROFILING_FRM_SCREEN_DELAY_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  NULL, (void*)&mmi_em_profiling_frm_screen_delay_editor},
    {MMI_EM_PROFILING_FRM_LIST_DELAY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&mmi_em_profiling_frm_list_delay_caption},
    {MMI_EM_PROFILING_FRM_LIST_DELAY_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, NULL, (void*)&mmi_em_profiling_frm_list_delay_editor},
    {MMI_EM_PROFILING_FRM_MATRIX_DELAY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&mmi_em_profiling_frm_matrix_delay_caption},
    {MMI_EM_PROFILING_FRM_MATRIX_DELAY_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, NULL, (void*)&mmi_em_profiling_frm_matrix_delay_editor},
    {MMI_EM_PROFILING_FRM_TIME_OFFSET_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&mmi_em_profiling_frm_time_offset_delay_caption},
    {MMI_EM_PROFILING_FRM_TIME_OFFSET_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, NULL, (void*)&mmi_em_profiling_frm_time_offset_delay_editor}
};

const cui_inline_struct mmi_em_profiling_frm_inline =
{
    12,
    STR_ID_EM_PROFILING_FRM,
    0,
    CUI_INLINE_SCREEN_LOOP ,
    NULL,
    mmi_em_profiling_frm_items
};


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_frm_set_default_text
 * DESCRIPTION
 *  Convert digital value to string
 * PARAMETERS
 *  buffer      [OUT]       The pointer to store the string
 *  value       [IN]        The digital number
 * RETURNS
 *  void
 *****************************************************************************/
#if MMI_EM_MAX_PROFILING_LEN != 4
#error "Please modify mmi_em_profiling_frm_set_default_text if input buffer length is changed"
#endif
static void mmi_em_profiling_frm_set_default_text(WCHAR* buffer, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value >= 10000)
    {
        value = 9999;
    }
    kal_wsprintf((WCHAR*)buffer, "%d", (int) value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_frm_popup_proc
 * DESCRIPTION
 *  Close group after popup screen show
 * PARAMETERS
 *  event       [IN]    The struct of event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_profiling_frm_popup_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(event);
    mmi_frm_group_close(mmi_em_profiling_frm_group_id);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_frm_done
 * DESCRIPTION
 *  Save the data of screen and show a success popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_frm_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ascii_buffer[MMI_EM_MAX_PROFILING_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_profiling_interactive_enable((MMI_BOOL) g_em_profiling_cntx.on_off_index);

    mmi_frm_profiling_gdi_profile_enable((MMI_BOOL) g_em_profiling_cntx.gdi_on_off_index);

    mmi_wcs_to_asc((CHAR*)ascii_buffer, (WCHAR*) g_em_profiling_cntx.screen_delay);
    mmi_frm_profiling_delay_set(MMI_FRM_PROFILING_DELAY_SCREEN, atoi((CHAR*)ascii_buffer));

    mmi_wcs_to_asc((CHAR*)ascii_buffer, (WCHAR*) g_em_profiling_cntx.list_delay);
    mmi_frm_profiling_delay_set(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT, atoi((CHAR*)ascii_buffer));

    mmi_wcs_to_asc((CHAR*)ascii_buffer, (WCHAR*) g_em_profiling_cntx.matrix_delay);
    mmi_frm_profiling_delay_set(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT, atoi((CHAR*)ascii_buffer));

    mmi_wcs_to_asc((CHAR*)ascii_buffer, (WCHAR*) g_em_profiling_cntx.delay_offset);
    mmi_frm_profiling_delay_set(MMI_FRM_PROFILING_DELAY_OFFSET, atoi((CHAR*)ascii_buffer));

    mmi_display_popupcallback_with_sg(
        mmi_em_profiling_frm_group_id,
        (UI_string_type)GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        mmi_em_profiling_frm_popup_proc,
        (void*)NULL,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_frm_done
 * DESCRIPTION
 *  Save the data of screen and show a success popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_frm_store_data(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_inline_id;
    mmi_group_event_struct *inline_evt = (mmi_group_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_id = inline_evt->sender_id;

    cui_inline_get_value(
        cui_inline_id,
        MMI_EM_PROFILING_FRM_DISPLAY_TIME_SELECT,
        (void*)(&g_em_profiling_cntx.on_off_index));

    cui_inline_get_value(
        cui_inline_id,
        MMI_EM_PROFILING_FRM_IMAGE_PROFILE_SELECT,
        (void*)(&g_em_profiling_cntx.gdi_on_off_index));

    cui_inline_get_value(
        cui_inline_id,
        MMI_EM_PROFILING_FRM_SCREEN_DELAY_EDIT,
        (void*)(g_em_profiling_cntx.screen_delay));

    cui_inline_get_value(
        cui_inline_id,
        MMI_EM_PROFILING_FRM_LIST_DELAY_EDIT,
        (void*)(g_em_profiling_cntx.list_delay));

    cui_inline_get_value(
        cui_inline_id,
        MMI_EM_PROFILING_FRM_MATRIX_DELAY_EDIT,
        (void*)(g_em_profiling_cntx.matrix_delay));

    cui_inline_get_value(
        cui_inline_id,
        MMI_EM_PROFILING_FRM_TIME_OFFSET_EDIT,
        (void*)(g_em_profiling_cntx.delay_offset));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_frm_proc
 * DESCRIPTION
 *  Process of event for profiling screen
 * PARAMETERS
 *  evt         [IN]        The struct of evt
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_em_profiling_frm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *inline_evt = (mmi_group_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            mmi_frm_group_close(mmi_em_profiling_frm_group_id);
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_em_profiling_frm_store_data(evt);
            mmi_em_profiling_frm_done();
            cui_inline_close(inline_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_frm_entry
 * DESCRIPTION
 *  Entry profiling screen and show screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_profiling_frm_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_profiling_frm_group_id = mmi_frm_group_create(mmi_em_get_root_group(), GRP_ID_AUTO_GEN, mmi_em_profiling_frm_proc, NULL);
    mmi_frm_group_enter(mmi_em_profiling_frm_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_inline_id = cui_inline_create(mmi_em_profiling_frm_group_id, &mmi_em_profiling_frm_inline);

    g_em_profiling_cntx.on_off_index = (S32)mmi_frm_profiling_interactive_is_enabled();
    cui_inline_set_value(cui_inline_id, MMI_EM_PROFILING_FRM_DISPLAY_TIME_SELECT, (void*)(g_em_profiling_cntx.on_off_index));

    g_em_profiling_cntx.gdi_on_off_index = (S32)mmi_frm_profiling_gdi_profile_is_enabled();
    cui_inline_set_value(cui_inline_id, MMI_EM_PROFILING_FRM_IMAGE_PROFILE_SELECT, (void*)(g_em_profiling_cntx.gdi_on_off_index));

    mmi_em_profiling_frm_set_default_text(
        g_em_profiling_cntx.screen_delay, 
        mmi_frm_profiling_delay_get(MMI_FRM_PROFILING_DELAY_SCREEN));
    cui_inline_set_value(cui_inline_id, MMI_EM_PROFILING_FRM_SCREEN_DELAY_EDIT, (void*)g_em_profiling_cntx.screen_delay);

    mmi_em_profiling_frm_set_default_text(
        g_em_profiling_cntx.list_delay, 
        mmi_frm_profiling_delay_get(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT));        
    cui_inline_set_value(cui_inline_id, MMI_EM_PROFILING_FRM_LIST_DELAY_EDIT, (void*)g_em_profiling_cntx.list_delay);

    mmi_em_profiling_frm_set_default_text(
        g_em_profiling_cntx.matrix_delay, 
        mmi_frm_profiling_delay_get(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT));        
    cui_inline_set_value(cui_inline_id, MMI_EM_PROFILING_FRM_MATRIX_DELAY_EDIT, (void*)g_em_profiling_cntx.matrix_delay);

    mmi_em_profiling_frm_set_default_text(
        g_em_profiling_cntx.delay_offset, 
        mmi_frm_profiling_delay_get(MMI_FRM_PROFILING_DELAY_OFFSET));        
    cui_inline_set_value(cui_inline_id, MMI_EM_PROFILING_FRM_TIME_OFFSET_EDIT, (void*)g_em_profiling_cntx.delay_offset);

    cui_inline_run(cui_inline_id);
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
#endif

#endif /* __MMI_INTERACTIVE_PROFILNG__ */


#ifdef __MMI_UI_BENCHMARK__


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_ui_bench_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_ui_bench_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_benchmark_stop();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_ui_bench_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_profiling_ui_bench_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_UI_BENCHMARK, mmi_em_profiling_ui_bench_exit, mmi_em_profiling_ui_bench_entry, NULL);

    /* Clear all key handlers so as to restrict duplicate reqs */
    ClearInputEventHandler(MMI_DEVICE_ALL);

    ShowCategory66Screen(
        STR_ID_EM_PROFILING_UI_BENCHMARK,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (PU8) GetString(STR_ID_EM_GLOBAL_PROCESSING),
        0,
        NULL);

    SetRightSoftkeyFunction(mmi_em_profiling_ui_bench_stop, KEY_EVENT_UP);
    SetKeyHandler(mmi_em_profiling_ui_bench_stop, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    mmi_frm_benchmark_start(mmi_em_profiling_ui_bench_callback);
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
#endif

#endif /* __MMI_UI_BENCHMARK__ */





#ifdef __MMI_MEMORY_MONITOR__
#define MMI_EM_MEMMONT_OUTBUF_SIZE  (256 * ENCODING_LENGTH)
static U16 *mmi_mem_mon_unicode_str;
mmi_mem_monitor_type_enum g_profiling_switch_index = MMI_EM_MEMORY_MONITOR_OFF;

/*****************************************************************************
 * FUNCTION
 *  mmi_em_done_memory_monitor
 * DESCRIPTION
 *  The callback function for that memory monitor setting is done.
 *  It will save the settings and go back to the history screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_done_memory_monitor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mem_mon_profiling_set_enable(g_profiling_switch_index);

    mmi_mem_mon_start_periodic_profiling(MMI_MEM_MON_PROFILING_PERIOD);

    grp_id = mmi_em_get_root_group();
    MMI_ASSERT(grp_id);
    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS, grp_id, NULL);
}
static void mmi_em_profiling_memory_monitor_select(MMI_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(menu_id)
    {
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_OFF:
        {
            g_profiling_switch_index = MMI_EM_MEMORY_MONITOR_OFF;
        }
        break;
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_CONTROL_BUFFER:
        {
            g_profiling_switch_index = MMI_EM_MEMORY_MONITOR_OSL;
        }
        break;
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_ASM:
        {
            g_profiling_switch_index = MMI_EM_MEMORY_MONITOR_ASM;
        }
        break;
        #ifdef __MMI_VUI_ENGINE__
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_VUI:
        {
            g_profiling_switch_index = MMI_EM_MEMORY_MONITOR_VUI;
        }
        break;
        #endif
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_AFM:
        {
            g_profiling_switch_index = MMI_EM_MEMORY_MONITOR_AFM;
        }
        break;
        default:
            break;
    }
    mmi_em_done_memory_monitor();
    
}

/*****************************************************************************
 * FUNCTION
 *  memory_statistic_proc
 * DESCRIPTION
 *  memory statistic app(screen group) event proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret memory_statistic_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_memory_statistic_exit
 * DESCRIPTION
 *  Response the rsk, exit the memory statistic app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_profiling_memory_statistic_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_EM_PROFILING_MEMORY_STATISTIC);

}


/*****************************************************************************
 * FUNCTION
 *  memory_statistic_exit()
 * DESCRIPTION
 *  The exit function of memory statistic screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void memory_statistic_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_mem_mon_unicode_str)
    {
        applib_mem_screen_free(mmi_mem_mon_unicode_str);
        mmi_mem_mon_unicode_str = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  memory_statistic_entry()
 * DESCRIPTION
 *  entry the memory statistic screen, it's called by mmi_frm_scrn_first_enter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void memory_statistic_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
            GRP_ID_EM_PROFILING_MEMORY_STATISTIC, 
            SCR_ID_EM_PROFILING_MEMORY_STATISTIC, 
            memory_statistic_exit, 
            memory_statistic_entry, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_mem_mon_unicode_str = applib_mem_screen_alloc(MMI_EM_MEMMONT_OUTBUF_SIZE);
    mmi_mem_mon_construct_static_statistic(mmi_mem_mon_unicode_str, MMI_EM_MEMMONT_OUTBUF_SIZE);

    ShowCategory74Screen(
        STR_ID_EM_PROFILING_MEMORY_STATISTIC,
        0,
        0, /* LSK String */
        0, /* LSK Icon   */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)mmi_mem_mon_unicode_str,
		MMI_EM_MEMMONT_OUTBUF_SIZE,
        NULL);

#ifdef __COSMOS_MMI_PACKAGE__
    SetKeyHandler(mmi_em_profiling_memory_statistic_exit, KEY_BACK, KEY_EVENT_UP);
#endif
    SetRightSoftkeyFunction(mmi_em_profiling_memory_statistic_exit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_memory_statistic_select()
 * DESCRIPTION
 *  The enrty function of memory statistic screen.
 *  It will display the memory statistic in a scrollable text box.
 *  The RSK is to go back to history screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_profiling_memory_statistic_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EM_PROFILING_MEMORY_STATISTIC, memory_statistic_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EM_PROFILING_MEMORY_STATISTIC, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(GRP_ID_EM_PROFILING_MEMORY_STATISTIC, SCR_ID_EM_PROFILING_MEMORY_STATISTIC, memory_statistic_entry, NULL);
}

#endif /* __MMI_MEMORY_MONITOR__ */ 

#ifdef __MMI_EM_PROFILING_SWLA__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_pofiling_swla_entry_hdlr
 * DESCRIPTION
 *  entry swla item
 * PARAMETERS
 *  event       [IN]        The struct of evt
 * RETURNS
 *  void
 *****************************************************************************/
//kal_bool g_isEnable = KAL_TRUE;
static void mmi_em_pofiling_swla_entry_hdlr(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id = 0;
    kal_bool isEnable;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    
    isEnable = SLA_IsEnabled();
    if(isEnable == KAL_TRUE)/* SWLA status: ON when SLA_IsEnabled() returns KAL_TRUE */
    {
        menu_id = MENU_ID_EM_PROFILING_SWLA_ON;
    }
    else /* SWLA status: OFF when SLA_IsEnabled() return KAL_FALSE if(isEnable == KAL_FALSE)*/
    {
        menu_id = MENU_ID_EM_PROFILING_SWLA_OFF;
    }

    cui_menu_set_currlist_flags(event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
    //kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_em_pofiling_swla_entry_hdlr SLA_IsEnabled = %d", isEnable);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_swla_result_info_group_pro
 * DESCRIPTION
 *  when switch the swla, the result will deal with in the group pro
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_em_profiling_swla_result_info_group_pro(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (evt->evt_id)
    {
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_swla_result_info_scrn_pro
 * DESCRIPTION
 *  when switch the swla, the result will show in the scren pro 
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_em_profiling_swla_result_info_scrn_pro(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{
                ShowCategory74Screen(
                    STR_ID_EM_PROFILING_SWLA_RESUILT_INFOR,
                    0,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    0,
                    (U8 *)evt->user_data,
                    MMI_EM_PROFILING_SWLA_INFOR_LEN,
                    gui_buffer);
                 break;
        	}  
        default:
            break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_swla_show_result_info
 * DESCRIPTION
 *  prepare the return result, which will be showed
 * PARAMETERS
 *  kal_uint32       [IN]        result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_swla_show_result_info(kal_uint32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data_scrn;
	CHAR n_buffer[MMI_EM_PROFILING_SWLA_INFOR_LEN] = {0};
    CHAR w_buffer[MMI_EM_PROFILING_SWLA_INFOR_LEN*2] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_EM_PROFILING_SWLA_RESULT_INFOR_GROUP, mmi_em_profiling_swla_result_info_group_pro, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	if(1 == result)
    {   
        sprintf(n_buffer, "Success! The new setting will be applied next time the phone power on.");
        mmi_asc_to_ucs2(w_buffer, n_buffer);
    }
    else
    {
        sprintf(n_buffer, "Fail! The error code:%d.", result);
        mmi_asc_to_ucs2(w_buffer, n_buffer);
    }
    user_data_scrn = w_buffer;
    mmi_frm_scrn_create(GRP_ID_EM_PROFILING_SWLA_RESULT_INFOR_GROUP, SCR_ID_EM_PROFILING_SWLA_RESULT_INFOR_SCRN, mmi_em_profiling_swla_result_info_scrn_pro, user_data_scrn);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_swla_select_hdlr
 * DESCRIPTION
 *  when switch the swla
 * PARAMETERS
 *  menu_id       [IN]        highlight menu id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_swla_select_hdlr(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = 1;
    if (menu_id == MENU_ID_EM_PROFILING_SWLA_ON)
    {
        result = SLA_TurnOn();
        
    }
    else if (menu_id == MENU_ID_EM_PROFILING_SWLA_OFF)
    {
        result = SLA_TurnOff();
        
    }
    else
    {
        ASSERT(0);
    }
    //kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_em_profiling_swla_select_hdlr SLA_IsEnabled = %d", result);
    mmi_em_profiling_swla_show_result_info(result);
}
#endif

/*-----------------------------------------------------------------------------*/
/*----------------------- Profiling -> Venus Debug Panel ----------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_venus_debug_panel_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        The struct of evt
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_venus_debug_panel_entry_hdlr(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;
    S16 error;
    mmi_menu_id menu_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_VENUS_DEBUG_PANEL_ENABLE, &value, DS_BYTE, &error);
    if (error == NVRAM_READ_SUCCESS && value > 0)
    {
        menu_id = MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_ON;
    }
    else
    {
        menu_id = MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_OFF;
    }

    cui_menu_set_currlist_flags(event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_venus_debug_panel_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id       [IN]        highlight menu id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_venus_debug_panel_select_hdlr(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = (menu_id == MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_ON) ? 1 : 0;
    WriteValue(NVRAM_VENUS_DEBUG_PANEL_ENABLE, &value, DS_BYTE, &error);
    if(error == NVRAM_WRITE_SUCCESS)
    {
        mmi_em_display_notify_popup(MMI_TRUE);
    }
    else
    {
        mmi_em_display_notify_popup(MMI_FALSE);
    }

}

#endif /* __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__ */




void mmi_em_profiling_menu_event_entry_hdlr(cui_menu_event_struct *event)
{
    switch (event->parent_menu_id)
    {
    #ifdef __MMI_MEMORY_MONITOR__
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR:
        {
            mmi_menu_id menu_id = 0;
            g_profiling_switch_index = mmi_mem_mon_profiling_get_enable();
            cui_menu_set_currlist_flags(event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            
            if (MMI_EM_MEMORY_MONITOR_OFF == g_profiling_switch_index)
                menu_id = MENU_ID_EM_PROFILING_MEMORY_MONITOR_OFF;
            else if(MMI_EM_MEMORY_MONITOR_OSL == g_profiling_switch_index)
                menu_id = MENU_ID_EM_PROFILING_MEMORY_MONITOR_CONTROL_BUFFER;
            else if(MMI_EM_MEMORY_MONITOR_ASM == g_profiling_switch_index)
                menu_id = MENU_ID_EM_PROFILING_MEMORY_MONITOR_ASM;
            #ifdef __MMI_VUI_ENGINE__
            else if(MMI_EM_MEMORY_MONITOR_VUI == g_profiling_switch_index)
                menu_id = MENU_ID_EM_PROFILING_MEMORY_MONITOR_VUI;
            #endif
            else if(MMI_EM_MEMORY_MONITOR_AFM == g_profiling_switch_index)
                menu_id = MENU_ID_EM_PROFILING_MEMORY_MONITOR_AFM;
            
            cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
        }
        break;
    #endif

    #ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
        case MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL:
        {
            mmi_em_profiling_venus_debug_panel_entry_hdlr(event);
        }
        break;
    #endif /* __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__ */

    #ifdef __MMI_EM_PROFILING_SWLA__
        case MENU_ID_EM_PROFILING_SWLA:
        {
            mmi_em_pofiling_swla_entry_hdlr(event);
        }
        break;
    #endif

        default:
            break;
    }

}

void mmi_em_profiling_menu_event_select_hdlr(cui_menu_event_struct *event)
{
    switch (event->highlighted_menu_id)
    {
#ifdef __MMI_INTERACTIVE_PROFILNG__
        case MENU_ID_EM_PROFILING_FRAMEWORK:
            mmi_em_profiling_frm_entry();
            break;
#endif
      
#ifdef __MMI_UI_BENCHMARK__    
        case MENU_ID_EM_PROFILING_UI_BENCHMARK:
            mmi_em_profiling_ui_bench_entry();
            break;
#endif

#ifdef __MMI_CSB_BROWSER__
        case MENU_ID_EM_PROFILING_CSB_BROWSER:
            PreEntryCSBMainMenu();
            break;
#endif

#ifdef __MMI_MEMORY_MONITOR__
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_OFF:
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_CONTROL_BUFFER:
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_ASM:
        #ifdef __MMI_VUI_ENGINE__
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_VUI:
        #endif
        case MENU_ID_EM_PROFILING_MEMORY_MONITOR_AFM:
        {
            mmi_em_profiling_memory_monitor_select(event->highlighted_menu_id);
        }
        break;
        case MENU_ID_EM_PROFILING_MEMORY_STATISTIC:
        {
            mmi_em_profiling_memory_statistic_select();
        }
        break;
#endif

#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
        case MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_OFF:
        case MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_ON:
        {
            mmi_em_profiling_venus_debug_panel_select_hdlr(event->highlighted_menu_id);
        }
        break;
#endif /* __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__ */
#ifdef __MMI_EM_PROFILING_SWLA__
        case MENU_ID_EM_PROFILING_SWLA_OFF:
        case MENU_ID_EM_PROFILING_SWLA_ON:
        {
            mmi_em_profiling_swla_select_hdlr(event->highlighted_menu_id);
        }
        break;
#endif

#if defined(__MMI_EM_MISC_TOUCH_SCREEN__) && defined(__COSMOS_MMI__)
        case MENU_ID_EM_PROFILING_GESTURE_TEST:
        {
            vapp_gesture_test_launch();
            break;
        }
#endif
        default:
            break;
    }
}



