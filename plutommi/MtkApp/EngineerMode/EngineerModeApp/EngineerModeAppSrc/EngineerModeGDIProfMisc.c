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
 *  EngineerModeGDIProfBlt.c
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
 * removed!
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
 *******************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "stdlib.h"
#include "drv_comm.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "GlobalResDef.h"
#include "gdi_include.h"
#include "gdi_internal.h"
#include "gdi_linear_transform.h"
#include "gdi_2d_engine.h"
#include "EngineerModeGDIProfiling.h"


#ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__


typedef struct
{
    kal_uint32 id;
    struct {
        gdi_color_format cf;
        kal_int16 x, y, width, height;
    } layer;
    struct {
        kal_int16 x, y, width, height;
        gdi_2d_fill_flag_bitset flag;
    } fill;
} mmi_em_profiling_gdi_misc_speec_fill_rect_param;


static S32 mmi_em_profiling_gdi_misc_speed_2d_fill_rect(void *v_param)
{
    static const U32 PROFILING_MS = 4000;
    gdi_handle layer;
    S32 i;
    U32 start_time, duration;
    kal_int32 fill_x, fill_y, fill_width, fill_height;
    gdi_color fill_color;
    gdi_2d_fill_flag_bitset fill_flag;
    mmi_em_profiling_gdi_misc_speec_fill_rect_param *param =
        (mmi_em_profiling_gdi_misc_speec_fill_rect_param*)v_param;

    layer = mmi_em_profiling_gdi_create_layer(
        param->layer.cf, param->layer.x, param->layer.y, param->layer.width, param->layer.height);
    if (layer == 0)
    {
        return -1;
    }
    
    gdi_layer_push_and_set_active(layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    fill_x = param->fill.x;
    fill_y = param->fill.y;
    fill_width = param->fill.width;
    fill_height = param->fill.height;
    fill_color = gdi_cf_get_color(param->layer.cf, 255, 255, 255, 255);
    fill_flag = param->fill.flag;

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FRECT_START);

    start_time = drv_get_current_time();
    i = 0;
    do
    {
        do 
        {
            gdi_2d_fill_rect(
                layer, layer,
                fill_x, fill_y, fill_width, fill_height, 255, fill_color,
                fill_flag,
                NULL);
            i++;
        }
        while ((i & 0xf) != 0); /* Calculate duration every 16 iterations */

        duration = drv_get_duration_ms(start_time);
    }
#ifdef __MTK_TARGET__
    while (duration < PROFILING_MS);
#else
    while (0);
#endif

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FRECT_END, param->id, i, duration);

    gdi_layer_blt(
        layer,
        0,
        0,
        0,
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);

    mmi_em_profiling_gdi_free_layer(layer);

    return 0;
}


static S32 mmi_em_profiling_gdi_misc_speed_sw_fill_rect(void *v_param)
{
    static const U32 PROFILING_MS = 4000;
    gdi_handle layer;
    S32 i;
    U32 start_time, duration;
    mmi_em_profiling_gdi_misc_speec_fill_rect_param *param =
        (mmi_em_profiling_gdi_misc_speec_fill_rect_param*)v_param;
    kal_int32 fill_x, fill_y, fill_width, fill_height;
    gdi_color fill_color;

    layer = mmi_em_profiling_gdi_create_layer(
        param->layer.cf, param->layer.x, param->layer.y, param->layer.width, param->layer.height);
    if (layer == 0)
    {
        return -1;
    }
    
    gdi_layer_push_and_set_active(layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    fill_x = param->fill.x;
    fill_y = param->fill.y;
    fill_width = param->fill.width;
    fill_height = param->fill.height;
    fill_color = gdi_cf_get_color(param->layer.cf, 255, 255, 255, 255);

    gdi_layer_push_and_set_active(layer);

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FRECT_START);

    start_time = drv_get_current_time();
    i = 0;
    do
    {
        do 
        {
            gdi_draw_solid_rect(
                fill_x, fill_y, fill_width, fill_height, fill_color);
            i++;
        }
        while ((i & 0xf) != 0); /* Calculate duration every 16 iterations */

        duration = drv_get_duration_ms(start_time);
    }
#ifdef __MTK_TARGET__
    while (duration < PROFILING_MS);
#else
    while (0);
#endif

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FRECT_END, param->id, i, duration);

    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        layer,
        0,
        0,
        0,
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);

    mmi_em_profiling_gdi_free_layer(layer);

    return 0;
}


static const mmi_em_profiling_gdi_misc_speec_fill_rect_param g_mmi_em_profiling_frect_param[] =
{
    { 0, { GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT },
         { 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 0 } },
    { 1, { GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT },
         { 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 0 } },
    { 2, { GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT },
         { 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 0 } },
    { 3, { GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT },
         { 10, 10, 70, 70, 0 } },
    { 4, { GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT },
         { 10, 10, 70, 70, 0 } },
    { 5, { GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT },
         { 10, 10, 70, 70, 0 } },
};


static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_frect_speed_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_G2D_FRECT_FULL_P8888, mmi_em_profiling_gdi_misc_speed_2d_fill_rect, (void*)&g_mmi_em_profiling_frect_param[0] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_G2D_FRECT_FULL_P6666, mmi_em_profiling_gdi_misc_speed_2d_fill_rect, (void*)&g_mmi_em_profiling_frect_param[1] },
#endif
    { MMI_EM_PROF_GDI_CASE_G2D_FRECT_FULL_565, mmi_em_profiling_gdi_misc_speed_2d_fill_rect, (void*)&g_mmi_em_profiling_frect_param[2] },
    { MMI_EM_PROF_GDI_CASE_G2D_FRECT_SMALL_P8888, mmi_em_profiling_gdi_misc_speed_2d_fill_rect, (void*)&g_mmi_em_profiling_frect_param[3] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_G2D_FRECT_SMALL_P6666, mmi_em_profiling_gdi_misc_speed_2d_fill_rect, (void*)&g_mmi_em_profiling_frect_param[4] },
#endif
    { MMI_EM_PROF_GDI_CASE_G2D_FRECT_SMALL_565, mmi_em_profiling_gdi_misc_speed_2d_fill_rect, (void*)&g_mmi_em_profiling_frect_param[5] },
    { MMI_EM_PROF_GDI_CASE_SW_FRECT_FULL_P8888, mmi_em_profiling_gdi_misc_speed_sw_fill_rect, (void*)&g_mmi_em_profiling_frect_param[0] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_SW_FRECT_FULL_P6666, mmi_em_profiling_gdi_misc_speed_sw_fill_rect, (void*)&g_mmi_em_profiling_frect_param[1] },
#endif
    { MMI_EM_PROF_GDI_CASE_SW_FRECT_FULL_565, mmi_em_profiling_gdi_misc_speed_sw_fill_rect, (void*)&g_mmi_em_profiling_frect_param[2] },
    { MMI_EM_PROF_GDI_CASE_SW_FRECT_SMALL_P8888, mmi_em_profiling_gdi_misc_speed_sw_fill_rect, (void*)&g_mmi_em_profiling_frect_param[3] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_SW_FRECT_SMALL_P6666, mmi_em_profiling_gdi_misc_speed_sw_fill_rect, (void*)&g_mmi_em_profiling_frect_param[4] },
#endif
    { MMI_EM_PROF_GDI_CASE_SW_FRECT_SMALL_565, mmi_em_profiling_gdi_misc_speed_sw_fill_rect, (void*)&g_mmi_em_profiling_frect_param[5] },

    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_frect_speed_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_MISC;
    test_suite->test_cases = g_mmi_em_profiling_gdi_frect_speed_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}



static gdi_handle mmi_em_profiling_gdi_misc_fill_rect_create_layer(
    gdi_color_format cf)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_create_layer(
        cf, 0, 0, 100, 100);
        
    gdi_layer_push_and_set_active(layer);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_pop_and_restore_active();

    return layer;
}


static void mmi_em_profiling_gdi_misc_blt_case(gdi_handle h0, gdi_handle h1, gdi_handle h2, gdi_handle h3)
{
    mmi_em_profiling_gdi_func_clean_screen();

    gdi_layer_blt(
        h0, h1, h2, h3,
        0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_p8888_opa(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_32_PARGB);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_32_PARGB, 255, 255, 255, 0),
        0,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);

    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_p8888_a1(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_32_PARGB);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_32_PARGB, 255, 255, 255, 0),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);

    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_p8888_a2(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_32_PARGB);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_32_PARGB, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_8888(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_32);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_32, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}

#ifdef GDI_LAYER_PARGB6666_SUPPORT
static S32 mmi_em_profiling_gdi_misc_fill_rect_p6666(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_PARGB6666);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_PARGB6666, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_p6666_galpha(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_PARGB6666);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        128, gdi_cf_get_color(GDI_COLOR_FORMAT_PARGB6666, 255, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}

#endif
static S32 mmi_em_profiling_gdi_misc_fill_rect_565_galpha(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_16);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        128, gdi_cf_get_color(GDI_COLOR_FORMAT_16, 255, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_565_galpha2(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_16);

    gdi_2d_fill_rect(
        layer, layer, 10, 10, 40, 40, 
        128, gdi_cf_get_color(GDI_COLOR_FORMAT_16, 255, 0, 0, 0),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    gdi_2d_fill_rect(
        layer, layer, 10, 50, 50, 50, 
        128, gdi_cf_get_color(GDI_COLOR_FORMAT_16, 255, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    gdi_2d_fill_rect(
        layer, layer, 50, 10, 50, 50, 
        176, gdi_cf_get_color(GDI_COLOR_FORMAT_16, 255, 0, 255, 0),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_565(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_16);

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_16, 255, 255, 255, 0),
        0,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}


static S32 mmi_em_profiling_gdi_misc_fill_rect_nb(void *v_param)
{
    gdi_handle layer;

    layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_PARGB6666);

    gdi_2d_fill_rect_wait_for_finish();

    gdi_2d_fill_rect(
        layer, layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_PARGB6666, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING | GDI_2D_FILL_FLAG_NON_BLOCKING,
        NULL);

    gdi_2d_fill_rect(
        layer, layer, 40, 40, 40, 40, 
        128, gdi_cf_get_color(GDI_COLOR_FORMAT_PARGB6666, 255, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING | GDI_2D_FILL_FLAG_NON_BLOCKING,
        NULL);

    gdi_2d_fill_rect(
        layer, layer, 50, 50, 20, 20, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_PARGB6666, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING | GDI_2D_FILL_FLAG_NON_BLOCKING,
        NULL);

    gdi_2d_fill_rect_wait_for_finish();

    mmi_em_profiling_gdi_misc_blt_case(layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(layer);
    
    return 0;
}
#ifdef GDI_LAYER_PARGB6666_SUPPORT

static S32 mmi_em_profiling_gdi_misc_fill_rect_src1(void *v_param)
{
    gdi_handle src_layer;
    gdi_handle dest_layer;

    dest_layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_PARGB6666);
    src_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    gdi_layer_push_and_set_active(src_layer);
    gdi_layer_clear(GDI_COLOR_RED);
    gdi_layer_pop_and_restore_active();

    gdi_2d_fill_rect(
        src_layer, dest_layer, 30, 30, 60, 60, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_32_PARGB, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(dest_layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(src_layer);
    mmi_em_profiling_gdi_free_layer(dest_layer);
    
    return 0;
}

#endif
static S32 mmi_em_profiling_gdi_misc_fill_rect_src2(void *v_param)
{
    gdi_handle src_layer;
    gdi_handle dest_layer;

    dest_layer = mmi_em_profiling_gdi_misc_fill_rect_create_layer(GDI_COLOR_FORMAT_32_PARGB);
    src_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    gdi_layer_push_and_set_active(src_layer);
    gdi_layer_clear(GDI_COLOR_RED);
    gdi_layer_pop_and_restore_active();

    gdi_2d_fill_rect(
        src_layer, dest_layer, 30, 30, 60, 60, 
        128, gdi_cf_get_color(GDI_COLOR_FORMAT_16, 255, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING,
        NULL);

    mmi_em_profiling_gdi_misc_blt_case(dest_layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(src_layer);
    mmi_em_profiling_gdi_free_layer(dest_layer);
    
    return 0;
}


static S32 mmi_em_profiling_gdi_misc_2d_nb(void *v_param)
{
    gdi_handle src_layer, dest_layer;
    gdi_lt_matrix_struct affine_transform =
    {
        { 1.8f, 0.0f, 5.0f,
          0.0f, 1.9f, 5.0f,
          0.0f, 0.0f, 1.0f }
    };

    src_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 200, 200);
    gdi_layer_push_and_set_active(src_layer);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    
    gdi_layer_set_active(dest_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_2d_linear_transfrom(
        affine_transform.m,
        src_layer,
        0,
        0,
        100,
        100,
        0,
        0,
        200,
        200,
        GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
        GDI_COLOR_WHITE,
        GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
        GDI_LT_FLAG_NON_BLOCKING);

    gdi_layer_pop_and_restore_active();

    gdi_2d_fill_rect(
        dest_layer, dest_layer, 50, 50, 100, 100, 
        255, gdi_cf_get_color(GDI_COLOR_FORMAT_32_PARGB, 128, 255, 255, 255),
        GDI_2D_FILL_FLAG_ALPHA_BLENDING | GDI_2D_FILL_FLAG_NON_BLOCKING,
        NULL);

    gdi_2d_fill_rect_wait_for_finish();

    mmi_em_profiling_gdi_misc_blt_case(dest_layer, 0, 0, 0);

    mmi_em_profiling_gdi_free_layer(src_layer);
    mmi_em_profiling_gdi_free_layer(dest_layer);

    return 0;
}


static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_frect_func_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 0, mmi_em_profiling_gdi_misc_fill_rect_p8888_opa, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 1, mmi_em_profiling_gdi_misc_fill_rect_p8888_a1, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 2, mmi_em_profiling_gdi_misc_fill_rect_p8888_a2, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 3, mmi_em_profiling_gdi_misc_fill_rect_8888, (void*)NULL },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 4, mmi_em_profiling_gdi_misc_fill_rect_p6666, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 5, mmi_em_profiling_gdi_misc_fill_rect_p6666_galpha, (void*)NULL },
#endif
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 6, mmi_em_profiling_gdi_misc_fill_rect_565_galpha, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 7, mmi_em_profiling_gdi_misc_fill_rect_565_galpha2, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 8, mmi_em_profiling_gdi_misc_fill_rect_565, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 9, mmi_em_profiling_gdi_misc_fill_rect_nb, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 10, mmi_em_profiling_gdi_misc_2d_nb, (void*)NULL },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 11, mmi_em_profiling_gdi_misc_fill_rect_src1, (void*)NULL },
#endif
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 12, mmi_em_profiling_gdi_misc_fill_rect_src2, (void*)NULL },
    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_frect_func_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_FUNCTIONAL;
    test_suite->test_cases = g_mmi_em_profiling_gdi_frect_func_test_cases;
    test_suite->interval_ms = 0; /* User trigger */
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}

#endif /* __MMI_EM_PROFILING_GDI_UI_INDEX__ */

