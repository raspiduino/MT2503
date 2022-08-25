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
 *  EngineerModeGDIProfiling.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer Mode GDI Profiling
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_EM_PROFILING_GDI_PROFILING__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_internal.h"
#include "gdi_primitive.h"
#include "med_global.h"
#include "med_utility.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "string.h"
#include "mmi_res_range_def.h"
#include "Unicodexdcl.h"
#include "device.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CustDataRes.h"
#include "GpioSrvGprot.h"
#include "stdio.h"
#include "lcd_sw_inc.h"
#include "mmi_frm_mem_gprot.h"
#include "fs_func.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "mmi_common_app_trc.h"
#include "drv_comm.h"
#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "CommonScreens.h"      /* DisplayPopup() */
#include "EngineerModeGDIProfiling.h"



static mmi_ret mmi_em_profiling_gdi_grp_proc(mmi_event_struct *evt)
{
    mmi_em_profiling_gdi_test_suite *test_suite;
    void (*finalize)(mmi_em_profiling_gdi_test_suite *test_suite);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            StopTimer(TIMER_ID_EM_PROFILING_GDI_TEST);
        
            test_suite = (mmi_em_profiling_gdi_test_suite*)evt->user_data;
            finalize = test_suite->finalize;
            if (finalize != NULL)
            {
                finalize(test_suite);
            }
            
            break;
    }

    return MMI_RET_OK;
}


void mmi_em_profiling_gdi_run_and_trigger_next(void *data)
{
    S32 case_index;
    S32 result;
    U32 start_time, duration;
    mmi_em_profiling_gdi_test_suite *test_suite =
        (mmi_em_profiling_gdi_test_suite*)data;

    case_index = test_suite->next_case_index;
    if (test_suite->test_cases[case_index].func != NULL)
    {
        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_TEST_START,
            test_suite->id, test_suite->test_cases[case_index].id);
            
        start_time = drv_get_current_time();
    
        result = test_suite->test_cases[case_index].func(
            test_suite->test_cases[case_index].param);

        duration = drv_get_duration_ms(start_time);

        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_TEST_END,
            test_suite->id, test_suite->test_cases[case_index].id, result, duration);

        test_suite->next_case_index++;

        if (test_suite->test_cases[test_suite->next_case_index].func != NULL)
        {
            if (test_suite->interval_ms > 0)
            {
                StartTimerEx(
                    TIMER_ID_EM_PROFILING_GDI_TEST,
                    test_suite->interval_ms,
                    mmi_em_profiling_gdi_run_and_trigger_next,
                    test_suite);
            }
            else
            {
                /* User has to press LSK to go next case */
            }
        }
        else
        {
            srv_vibrator_play_once();
            MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_TEST_DONE, test_suite->id);
        }
    }
    else
    {
        srv_vibrator_play_once();
        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_TEST_DONE, test_suite->id);
    }

    { /* to prevent from assert fail on blt_previous */
        gdi_handle *pre_layers = test_suite->pre_layers;
        gdi_layer_set_blt_layer_ext(pre_layers[0], pre_layers[1], pre_layers[2], pre_layers[3]
                                #ifdef GDI_6_LAYERS
                                    , pre_layers[4], pre_layers[5]
                                #endif
                                    );
    }
}


static void mmi_em_profiling_gdi_go_next_case(void)
{
    mmi_em_profiling_gdi_test_suite *test_suite =
        (mmi_em_profiling_gdi_test_suite*)mmi_frm_group_get_user_data(GRP_ID_EM_PROFILING_GDI);

    if (test_suite != NULL)
    {
        mmi_em_profiling_gdi_run_and_trigger_next(test_suite);
    }
}


static void mmi_em_profiling_exit_gdi_general(void)
{
    StopTimer(TIMER_ID_EM_PROFILING_GDI_TEST);
    srv_backlight_turn_off();
}


static void mmi_em_profiling_entry_gdi_general(mmi_scrn_essential_struct *es_data)
{
    mmi_em_profiling_gdi_test_suite *test_suite;

    if (!mmi_frm_scrn_enter(
            es_data->group_id,
            es_data->scrn_id,
            (FuncPtr)mmi_em_profiling_exit_gdi_general,
            (FuncPtr)mmi_em_profiling_entry_gdi_general,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    test_suite = (mmi_em_profiling_gdi_test_suite*)es_data->user_data;

    if (test_suite->test_cases != NULL &&
        test_suite->test_cases[test_suite->next_case_index].func != NULL)
    {
        gdi_handle *pre_layers;

        pre_layers = test_suite->pre_layers;
        gdi_layer_get_blt_layer_ext(&pre_layers[0], &pre_layers[1], &pre_layers[2], &pre_layers[3]
                                #ifdef GDI_6_LAYERS
                                    , &pre_layers[4], &pre_layers[5]
                                #endif
                                    );

        mmi_em_profiling_gdi_run_and_trigger_next(test_suite);
    }

    if (test_suite->interval_ms <= 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        SetLeftSoftkeyFunction(mmi_em_profiling_gdi_go_next_case, KEY_EVENT_UP);
    }

    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
}

#ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__       

static void mmi_em_profiling_enter_test_screen(mmi_em_profiling_gdi_test_suite *test_suite)
{
    test_suite->next_case_index = 0;

    mmi_frm_group_create(
        mmi_frm_group_get_active_id(),
        GRP_ID_EM_PROFILING_GDI, 
        mmi_em_profiling_gdi_grp_proc, 
        test_suite);

    mmi_frm_group_enter(
        GRP_ID_EM_PROFILING_GDI, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_EM_PROFILING_GDI,
        SCR_ID_EM_PROFILING_GDI,
        (FuncPtr)mmi_em_profiling_entry_gdi_general,
        (void*)test_suite);
}
#endif

void mmi_em_profiling_gdi_free_suite(mmi_em_profiling_gdi_test_suite *test_suite)
{
    mmi_mfree(test_suite);
}


#define MMI_EM_PROFILING_LAYER_USE_LAYER_MEM

gdi_handle mmi_em_profiling_gdi_create_layer(
    gdi_color_format cf,
    S32 offset_x,
    S32 offset_y,
    S32 width,
    S32 height)
{
    GDI_RESULT result;
    gdi_handle handle;
#ifndef MMI_EM_PROFILING_LAYER_USE_LAYER_MEM
    S32 memory_size;
    U8 *memory;

    memory_size = gdi_bits_per_pixel(cf) * width * height;
    memory = (U8*)gdi_alloc_ext_mem_framebuffer(memory_size);

    if (memory == NULL)
    {
        return 0;
    }
    
    result = gdi_layer_create_cf_using_outside_memory(
        cf,
        offset_x,
        offset_y,
        width,
        height,
        &handle,
        memory,
        memory_size);
    
#else
    result = gdi_layer_create_cf(
        cf,
        offset_x,
        offset_y,
        width,
        height,
        &handle);
#endif

    MMI_ASSERT(result == GDI_SUCCEED);

    return handle;
}


void mmi_em_profiling_gdi_free_layer(gdi_handle handle)
{
#ifndef MMI_EM_PROFILING_LAYER_USE_LAYER_MEM
    gdi_layer_struct *layer;
    U8 *memory;

    layer = (gdi_layer_struct*)handle;
    memory = (U8*)layer->buf_ptr;
    gdi_layer_free(handle);
    gdi_free_ext_mem(&memory);
#else
    gdi_layer_free(handle);
#endif
}


void mmi_em_profiling_gdi_free_layers(gdi_handle layer_hd[4])
{
    gdi_handle base_handle;
    S32 i;

    gdi_layer_get_base_handle(&base_handle);

    for (i = 0; i < 4; i++)
    {
        if (layer_hd[i] != 0 && layer_hd[i] != base_handle)
        {
            mmi_em_profiling_gdi_free_layer(layer_hd[i]);
        }
    }
}


void mmi_em_profiling_gdi_fill_colors(gdi_handle layer_hd[], S32 n)
{
    gdi_layer_push_and_set_active(layer_hd[0]);
    gdi_layer_clear(gdi_act_color_from_rgb(128, 128, 0, 254));

    if (n > 1 && layer_hd[1] != 0)
    {
        gdi_layer_set_active(layer_hd[1]);
        gdi_layer_clear(gdi_act_color_from_rgb(128, 254, 0, 0));
    }

    if (n > 2 && layer_hd[2] != 0)
    {
        gdi_layer_set_active(layer_hd[2]);
        gdi_layer_clear(GDI_COLOR_GREEN);
    }

    if (n > 3 && layer_hd[3] != 0)
    {
        gdi_layer_set_active(layer_hd[3]);
        gdi_layer_clear(GDI_COLOR_GRAY);
    }
    
    gdi_layer_pop_and_restore_active();
}



void mmi_em_profiling_gdi_fill_color_global_opa(gdi_handle layer_hd[], S32 n)
{
    gdi_layer_push_and_set_active(layer_hd[0]);
    gdi_layer_clear(gdi_act_color_from_rgb(255, 128, 0, 254));
    gdi_layer_set_opacity(TRUE, 128);

    if (n > 1 && layer_hd[1] != 0)
    {
        gdi_layer_set_active(layer_hd[1]);
        gdi_layer_clear(gdi_act_color_from_rgb(255, 254, 0, 0));
        gdi_layer_set_opacity(TRUE, 128);
    }

    if (n > 2 && layer_hd[2] != 0)
    {
        gdi_layer_set_active(layer_hd[2]);
        gdi_layer_clear(GDI_COLOR_GREEN);
    }

    if (n > 3 && layer_hd[3] != 0)
    {
        gdi_layer_set_active(layer_hd[3]);
        gdi_layer_clear(GDI_COLOR_GRAY);
    }
    
    gdi_layer_pop_and_restore_active();
}



void mmi_em_profiling_gdi_fill_white(gdi_handle layer)
{
    gdi_layer_push_and_set_active(layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();
}


void mmi_em_profiling_gdi_func_clean_screen(void)
{
    gdi_handle base_layer;

    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        base_layer,
        0,
        0,
        0,
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_gdi_menu_select_hdlr
 * DESCRIPTION
 *  Menu select handler of GDI profiling.
 * PARAMETERS
 *  event       [IN]    menu event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_em_profiling_gdi_menu_select_hdlr(cui_menu_event_struct *event)
{
    switch(event->highlighted_menu_id)
    {
    #ifdef __MMI_EM_PROFILING_IMG_DEC__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_PROFILING_IMG_DEC__ */

        case MENU_ID_EM_PROFILING_HINT:
            mmi_popup_display_simple(
                get_string(STR_ID_EM_PROFILING_NO_CR_DETAIL),
                MMI_EVENT_DEFAULT,
                mmi_frm_group_get_active_id(),
                NULL);
            break;

    #ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__       
        case MENU_ID_EM_PROFILING_GDI_DECODER_SPEED:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_decoder_speed_suite());
            break;

        case 
            MENU_ID_EM_PROFILING_GDI_DECODER_FUNC:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_decoder_func_suite());
            break;


        case MENU_ID_EM_PROFILING_PLATFORM_SPEED:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_speed_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_BLT_SPEED:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_blt_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_FLATTEN_SPEED:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_flatten_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_LT_SPEED:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_lt_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_MISC_SPEED:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_frect_speed_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_BLT_FUNC:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_blt_func_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_FLA_FUNC:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_fla_func_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_FRECT_FUNC:
            mmi_em_profiling_enter_test_screen(
                mmi_em_profiling_gdi_create_frect_func_suite());
            break;

        case MENU_ID_EM_PROFILING_GDI_TEMP:
            break;
#endif
    }
    
    return MMI_RET_OK;
}

#endif /* __MMI_EM_PROFILING_GDI_PROFILING__ */

