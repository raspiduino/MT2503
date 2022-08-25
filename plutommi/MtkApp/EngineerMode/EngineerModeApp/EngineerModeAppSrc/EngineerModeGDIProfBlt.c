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
#include "gdi_include.h"
#include "gdi_internal.h"
#include "EngineerModeGDIProfiling.h"


#ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__

typedef struct
{
    kal_int32 id;
    struct {
        kal_int32 x1, y1, x2, y2;
    } region;
    MMI_BOOL (*create_layers)(gdi_handle layer_hd[4]);
    void (*free_layers)(gdi_handle layer_hd[4]);
} mmi_em_profiling_blt_param;


static S32 mmi_em_profiling_run_blt(void *v_param)
{
    static const U32 PROFILING_MS = 4000;

    S32 i;
    gdi_handle layer_hd[4];
    U32 start_time, duration;
    const mmi_em_profiling_blt_param *param = (const mmi_em_profiling_blt_param*)v_param;


    layer_hd[0] = layer_hd[1] = layer_hd[2] = layer_hd[3] = 0;
    if (!param->create_layers(layer_hd))
    {
        param->free_layers(layer_hd);
        return -1;
    }

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_BLT_START);

    start_time = drv_get_current_time();
    i = 0;
    do
    {
        do {
            gdi_layer_blt(
                layer_hd[0],
                layer_hd[1],
                layer_hd[2],
                layer_hd[3],
                param->region.x1,
                param->region.y1,
                param->region.x2,
                param->region.y2);
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

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_BLT_END, param->id, i, duration);

    param->free_layers(layer_hd);

    return 0;
}



static MMI_BOOL mmi_em_profiling_gdi_blt_full_create(gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(&layer_hd[0]);
    gdi_layer_push_and_set_active(layer_hd[0]);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_layer_pop_and_restore_active();

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_blt_1_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 80, 100, 100);

    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_blt_P8888_full_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (layer_hd[0] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 1);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_blt_P8888_small_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 50, 50);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 100, 50, 50);
    
    if (layer_hd[0] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 3);

    return MMI_TRUE;
}

/*
static MMI_BOOL mmi_em_profiling_gdi_blt_P8888_medium_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 100, 100, 100);
    
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        // free will be called 
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}
*/

static MMI_BOOL mmi_em_profiling_gdi_blt_P6666_full_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (layer_hd[0] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 1);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_blt_P6666_small_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 50, 50);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 100, 50, 50);
    
    if (layer_hd[0] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}
/*

static MMI_BOOL mmi_em_profiling_gdi_blt_P6666_medium_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 100, 100, 100);
    
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        // free will be called 
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static S32 mmi_em_profiling_run_6666_blt_test(void *v_param)
{
    gdi_handle base_layer_hd;
    gdi_handle layer_hd[4];

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 100, 100);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 130, 100, 100);
    layer_hd[3] = 0;

    if (layer_hd[0] == 0 || layer_hd[1] == 0 || layer_hd[2] == 0)
    {
        mmi_em_profiling_gdi_free_layers(layer_hd);
        return -1;
    }

    gdi_layer_get_base_handle(&base_layer_hd);
    gdi_layer_push_and_set_active(base_layer_hd);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();
    
    mmi_em_profiling_gdi_fill_colors(layer_hd, 3);

    gdi_layer_blt(
        base_layer_hd,
        layer_hd[0],
        layer_hd[1],
        layer_hd[2],
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);

    mmi_em_profiling_gdi_free_layers(layer_hd);

    return 0;
}
*/

#define _FULL_SCREEN { 0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1 }

static const mmi_em_profiling_blt_param g_mmi_em_profiling_blt_case[] =
{
    { 0, _FULL_SCREEN, mmi_em_profiling_gdi_blt_full_create, mmi_em_profiling_gdi_free_layers },
    { 1, _FULL_SCREEN, mmi_em_profiling_gdi_blt_1_create, mmi_em_profiling_gdi_free_layers },
    { 2, _FULL_SCREEN, mmi_em_profiling_gdi_blt_P8888_full_create, mmi_em_profiling_gdi_free_layers },
    { 3, _FULL_SCREEN, mmi_em_profiling_gdi_blt_P8888_small_create, mmi_em_profiling_gdi_free_layers },
    { 4, _FULL_SCREEN, mmi_em_profiling_gdi_blt_P6666_full_create, mmi_em_profiling_gdi_free_layers },
    { 5, _FULL_SCREEN, mmi_em_profiling_gdi_blt_P6666_small_create, mmi_em_profiling_gdi_free_layers },
    
    { -1, NULL, NULL }
};


static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_blt_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_BLT_FULL, mmi_em_profiling_run_blt, (void*)&g_mmi_em_profiling_blt_case[0] },
    { MMI_EM_PROF_GDI_CASE_BLT_1, mmi_em_profiling_run_blt, (void*)&g_mmi_em_profiling_blt_case[1] },
    { MMI_EM_PROF_GDI_CASE_BLT_PARGB8888_SMALL, mmi_em_profiling_run_blt, (void*)&g_mmi_em_profiling_blt_case[2] },
    { MMI_EM_PROF_GDI_CASE_BLT_PARGB8888_FULL, mmi_em_profiling_run_blt, (void*)&g_mmi_em_profiling_blt_case[3] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_BLT_PARGB6666_SMALL, mmi_em_profiling_run_blt, (void*)&g_mmi_em_profiling_blt_case[4] },
    { MMI_EM_PROF_GDI_CASE_BLT_PARGB6666_FULL, mmi_em_profiling_run_blt, (void*)&g_mmi_em_profiling_blt_case[5] },
    { MMI_EM_PROF_GDI_CASE_BLT_PARGB6666_TEST, mmi_em_profiling_run_6666_blt_test, NULL },
#endif

    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};



static S32 mmi_em_profiling_run_blt_functional(void *v_param)
{
    gdi_handle layer_hd[4];
    const mmi_em_profiling_blt_param *param = (const mmi_em_profiling_blt_param*)v_param;

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case

    layer_hd[0] = layer_hd[1] = layer_hd[2] = layer_hd[3] = 0;
    if (!param->create_layers(layer_hd))
    {
        param->free_layers(layer_hd);
        return -1;
    }

    gdi_layer_blt(
        layer_hd[0],
        layer_hd[1],
        layer_hd[2],
        layer_hd[3],
        param->region.x1,
        param->region.y1,
        param->region.x2,
        param->region.y2);

    param->free_layers(layer_hd);

    return 0;
}


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_blt_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_BLT;
    test_suite->test_cases = g_mmi_em_profiling_blt_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}


static MMI_BOOL mmi_em_profiling_gdi_blt88_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt86_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt68_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt66_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt88g_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt86g_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt68g_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}

static MMI_BOOL mmi_em_profiling_gdi_blt66g_func_create(gdi_handle layer_hd[4])
{
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}


static const mmi_em_profiling_blt_param g_mmi_em_profiling_func_blt_case[] =
{
    { 0, _FULL_SCREEN, mmi_em_profiling_gdi_blt88_func_create, mmi_em_profiling_gdi_free_layers },
    { 1, _FULL_SCREEN, mmi_em_profiling_gdi_blt86_func_create, mmi_em_profiling_gdi_free_layers },
    { 2, _FULL_SCREEN, mmi_em_profiling_gdi_blt68_func_create, mmi_em_profiling_gdi_free_layers },
    { 3, _FULL_SCREEN, mmi_em_profiling_gdi_blt66_func_create, mmi_em_profiling_gdi_free_layers },
    { 4, _FULL_SCREEN, mmi_em_profiling_gdi_blt88g_func_create, mmi_em_profiling_gdi_free_layers },
    { 5, _FULL_SCREEN, mmi_em_profiling_gdi_blt86g_func_create, mmi_em_profiling_gdi_free_layers },
    { 6, _FULL_SCREEN, mmi_em_profiling_gdi_blt68g_func_create, mmi_em_profiling_gdi_free_layers },
    { 7, _FULL_SCREEN, mmi_em_profiling_gdi_blt66g_func_create, mmi_em_profiling_gdi_free_layers },
    
    { -1, NULL, NULL }
};


static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_func_blt_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 0, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[0] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 1, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[1] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 2, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[2] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 3, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[3] },
#endif
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 4, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[4] },
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 5, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[5] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 6, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[6] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 7, mmi_em_profiling_run_blt_functional, (void*)&g_mmi_em_profiling_func_blt_case[7] },
#endif

    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_blt_func_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_FUNCTIONAL;
    test_suite->test_cases = g_mmi_em_profiling_gdi_func_blt_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}

#endif /* __MMI_EM_PROFILING_GDI_UI_INDEX__ */

