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
    kal_uint32 linear_transform_flag;
} mmi_em_profiling_LT_param;


#define MMI_EM_GDI_LT(transform, src_layer, edge_filter, edge_color, mode, flag) \
    gdi_2d_linear_transfrom( \
        transform.m, \
        src_layer, \
        0, \
        0, \
        100, \
        100, \
        0, \
        0, \
        200, \
        200, \
        edge_filter, \
        edge_color, \
        mode, \
        flag)


static S32 mmi_em_profiling_gdi_lt_case_1(void *v_param)
{
    static const U32 PROFILING_MS = 4000;

    S32 i;
    gdi_handle src_layer_16, src_layer_32, target_layer_16, target_layer_32;
    GDI_RESULT result;
    U32 start_time, duration;
    mmi_em_profiling_LT_param* param = (mmi_em_profiling_LT_param*)v_param;

    gdi_lt_matrix_struct affine_transform =
    {
        { 1.8f, 0.0f, 5.0f,
          0.0f, 1.9f, 5.0f,
          0.0f, 0.0f, 1.0f }
    };


    src_layer_16 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    src_layer_32 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    target_layer_16 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 200, 200);
    target_layer_32 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 200, 200);
    gdi_layer_push_and_set_active(src_layer_16);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    gdi_layer_set_active(src_layer_32);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    gdi_layer_set_active(target_layer_16);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_set_active(target_layer_32);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_LT_START);

    gdi_layer_push_and_set_active(src_layer_16);

    start_time = drv_get_current_time();
    i = 0;
    do
    {
        gdi_layer_set_active(target_layer_16);
        do 
        {
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
                
            i++;
        }
        while ((i & 0x3) != 0); /* Calculate duration every 4 iterations */

        gdi_layer_set_active(target_layer_32);
        do 
        {
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
                
            i++;
        }
        while ((i & 0x3) != 0); /* Calculate duration every 4 iterations */

        duration = drv_get_duration_ms(start_time);
    }
#ifdef __MTK_TARGET__
    while (duration < PROFILING_MS);
#else
    while (0);
#endif

    i *= 4;
    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_LT_END, 1, i, duration);

    {
        gdi_handle base_layer_handle;
        
        result = gdi_layer_get_base_handle(&base_layer_handle);
        MMI_ASSERT(result == GDI_SUCCEED);

        gdi_layer_push_and_set_active(base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        gdi_layer_blt(
            base_layer_handle,
            target_layer_16,
            0,
            0,
            0,
            0,
            GDI_LCD_WIDTH - 1,
            GDI_LCD_HEIGHT - 1);
    }

    mmi_em_profiling_gdi_free_layer(src_layer_16);
    mmi_em_profiling_gdi_free_layer(src_layer_32);
    mmi_em_profiling_gdi_free_layer(target_layer_16);
    mmi_em_profiling_gdi_free_layer(target_layer_32);

    gdi_layer_pop_and_restore_active();

    return 0;
}


static S32 mmi_em_profiling_gdi_lt_nearest(void *v_param)
{
    static const U32 PROFILING_MS = 4000;

    S32 i;
    gdi_handle src_layer_16, src_layer_32, target_layer_16, target_layer_32;
    GDI_RESULT result;
    U32 start_time, duration;
    mmi_em_profiling_LT_param* param = (mmi_em_profiling_LT_param*)v_param;

    gdi_lt_matrix_struct affine_transform =
    {
        { 1.8f, 0.0f, 5.0f,
          0.0f, 1.9f, 5.0f,
          0.0f, 0.0f, 1.0f }
    };


    src_layer_16 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    src_layer_32 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    target_layer_16 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 200, 200);
    target_layer_32 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 200, 200);
    gdi_layer_push_and_set_active(src_layer_16);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    gdi_layer_set_active(src_layer_32);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    gdi_layer_set_active(target_layer_16);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_set_active(target_layer_32);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_LT_START);

    gdi_layer_push_and_set_active(src_layer_16);

    start_time = drv_get_current_time();
    i = 0;
    do
    {
        gdi_layer_set_active(target_layer_16);
        do 
        {
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
                
            i++;
        }
        while ((i & 0x3) != 0); /* Calculate duration every 4 iterations */

        gdi_layer_set_active(target_layer_32);
        do 
        {
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_NEAREST,param->linear_transform_flag);
                
            i++;
        }
        while ((i & 0x3) != 0); /* Calculate duration every 4 iterations */

        duration = drv_get_duration_ms(start_time);
    }
#ifdef __MTK_TARGET__
    while (duration < PROFILING_MS);
#else
    while (0);
#endif

    i *= 2;
    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_LT_END, 2, i, duration);

    {
        gdi_handle base_layer_handle;
        
        result = gdi_layer_get_base_handle(&base_layer_handle);
        MMI_ASSERT(result == GDI_SUCCEED);

        gdi_layer_push_and_set_active(base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        gdi_layer_blt(
            base_layer_handle,
            target_layer_16,
            0,
            0,
            0,
            0,
            GDI_LCD_WIDTH - 1,
            GDI_LCD_HEIGHT - 1);
    }

    mmi_em_profiling_gdi_free_layer(src_layer_16);
    mmi_em_profiling_gdi_free_layer(src_layer_32);
    mmi_em_profiling_gdi_free_layer(target_layer_16);
    mmi_em_profiling_gdi_free_layer(target_layer_32);

    gdi_layer_pop_and_restore_active();

    return 0;
}



static S32 mmi_em_profiling_gdi_lt_bilinear(void *v_param)
{
    static const U32 PROFILING_MS = 4000;

    S32 i;
    gdi_handle src_layer_16, src_layer_32, target_layer_16, target_layer_32;
    GDI_RESULT result;
    U32 start_time, duration;
    mmi_em_profiling_LT_param* param = (mmi_em_profiling_LT_param*)v_param;

    gdi_lt_matrix_struct affine_transform =
    {
        { 1.8f, 0.0f, 5.0f,
          0.0f, 1.9f, 5.0f,
          0.0f, 0.0f, 1.0f }
    };


    src_layer_16 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    src_layer_32 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    target_layer_16 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 200, 200);
    target_layer_32 = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 200, 200);
    gdi_layer_push_and_set_active(src_layer_16);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    gdi_layer_set_active(src_layer_32);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_draw_id(0, 0, IMG_GLOBAL_QUESTION);
    gdi_layer_set_active(target_layer_16);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_set_active(target_layer_32);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_LT_START);

    gdi_layer_push_and_set_active(src_layer_16);

    start_time = drv_get_current_time();
    i = 0;
    do
    {
        gdi_layer_set_active(target_layer_16);
        do 
        {
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
                
            i++;
        }
        while ((i & 0x3) != 0); /* Calculate duration every 4 iterations */

        gdi_layer_set_active(target_layer_32);
        do 
        {
            MMI_EM_GDI_LT(affine_transform, src_layer_16, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_WHITE, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
            MMI_EM_GDI_LT(affine_transform, src_layer_32, GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                GDI_COLOR_TRANSPARENT, GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,param->linear_transform_flag);
                
            i++;
        }
        while ((i & 0x3) != 0); /* Calculate duration every 4 iterations */

        duration = drv_get_duration_ms(start_time);
    }
#ifdef __MTK_TARGET__
    while (duration < PROFILING_MS);
#else
    while (0);
#endif

    i *= 2;
    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_LT_END, 3, i, duration);

    {
        gdi_handle base_layer_handle;
        
        result = gdi_layer_get_base_handle(&base_layer_handle);
        MMI_ASSERT(result == GDI_SUCCEED);

        gdi_layer_push_and_set_active(base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        gdi_layer_blt(
            base_layer_handle,
            target_layer_16,
            0,
            0,
            0,
            0,
            GDI_LCD_WIDTH - 1,
            GDI_LCD_HEIGHT - 1);
    }

    mmi_em_profiling_gdi_free_layer(src_layer_16);
    mmi_em_profiling_gdi_free_layer(src_layer_32);
    mmi_em_profiling_gdi_free_layer(target_layer_16);
    mmi_em_profiling_gdi_free_layer(target_layer_32);

    gdi_layer_pop_and_restore_active();

    return 0;
}

static mmi_em_profiling_LT_param g_mmi_em_profiling_lt_params[] = 
{
    {0},
    {GDI_LT_FLAG_USE_FIXED_PATTERN_DITHER}
};

static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_lt_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_1, mmi_em_profiling_gdi_lt_case_1, (void*)&g_mmi_em_profiling_lt_params[0]},
    { MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_NEAREST, mmi_em_profiling_gdi_lt_nearest, (void*)&g_mmi_em_profiling_lt_params[0]},
    { MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_BILINEAR, mmi_em_profiling_gdi_lt_bilinear, (void*)&g_mmi_em_profiling_lt_params[0]},
#ifdef __HW_G2D_DITHERING_SUPPORT__
    { MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_1, mmi_em_profiling_gdi_lt_case_1, (void*)&g_mmi_em_profiling_lt_params[1]},
    { MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_NEAREST, mmi_em_profiling_gdi_lt_nearest, (void*)&g_mmi_em_profiling_lt_params[1]},
    { MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_BILINEAR, mmi_em_profiling_gdi_lt_bilinear, (void*)&g_mmi_em_profiling_lt_params[1]},    
#endif        
    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_lt_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_MISC;
    test_suite->test_cases = g_mmi_em_profiling_gdi_lt_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}


#endif

