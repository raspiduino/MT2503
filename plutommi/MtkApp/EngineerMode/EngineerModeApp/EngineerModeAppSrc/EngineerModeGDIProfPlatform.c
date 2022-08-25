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
 *  EngineerModeGDIProfPlatform.c
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
#include "stdio.h"
#include "stdlib.h"
#include "drv_comm.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "gdi_include.h"
#include "gdi_internal.h"
#include "EngineerModeGDIProfiling.h"


#ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__

#define MMI_EM_PROFILING_GDI_MEM_SIZE (1000)

static S32 mmi_em_profiling_gdi_do_memcpy(void *v_param)
{
    static const S32 N_PROFILING_LOOP = 20000;

    struct {
        void *src;
        void *dest;
    } mem_pair[4];
    
    S32 pair_index, i;
    U32 start_time, duration;

    void *nc_mem1, *nc_mem2;
    void *ch_mem1, *ch_mem2;

    nc_mem1 = gdi_alloc_ext_mem_framebuffer(MMI_EM_PROFILING_GDI_MEM_SIZE);
    nc_mem2 = gdi_alloc_ext_mem_framebuffer(MMI_EM_PROFILING_GDI_MEM_SIZE);
    ch_mem1 = gdi_alloc_ext_mem_cacheable(MMI_EM_PROFILING_GDI_MEM_SIZE);
    ch_mem2 = gdi_alloc_ext_mem_cacheable(MMI_EM_PROFILING_GDI_MEM_SIZE);
        
    mem_pair[0].src = nc_mem1, mem_pair[0].dest = nc_mem2;
    mem_pair[1].src = nc_mem1, mem_pair[1].dest = ch_mem2;
    mem_pair[2].src = ch_mem1, mem_pair[2].dest = nc_mem2;
    mem_pair[3].src = ch_mem1, mem_pair[3].dest = ch_mem2;
    
    for (pair_index = 0; pair_index < 4; pair_index++)
    {
        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_START, pair_index);

        /* First-time access the memory, so that cache can be effective */
        memset(mem_pair[pair_index].src, 0, MMI_EM_PROFILING_GDI_MEM_SIZE);
        memset(mem_pair[pair_index].dest, 0, MMI_EM_PROFILING_GDI_MEM_SIZE);

        start_time = drv_get_current_time();
//        SLA_CustomLogging("CPY", SA_start);
        for (i = (N_PROFILING_LOOP >> 1); i > 0; i--)
        {
            memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE);
            memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE);
        }
//        SLA_CustomLogging("CPY", SA_stop);
        duration = drv_get_duration_ms(start_time);

        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_END, pair_index, N_PROFILING_LOOP, duration);
    }

    pair_index = 3; /* C <-> C */
    {
        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_START, 10 + pair_index);

        /* First-time access the memory, so that cache can be effective */
        memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE);
        memcpy(mem_pair[pair_index].src, mem_pair[pair_index].dest, MMI_EM_PROFILING_GDI_MEM_SIZE);

        start_time = drv_get_current_time();
        for (i = N_PROFILING_LOOP >> 1; i > 0; i--)
        {
            memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE);
            memcpy(mem_pair[pair_index].src, mem_pair[pair_index].dest, MMI_EM_PROFILING_GDI_MEM_SIZE);
        }
        duration = drv_get_duration_ms(start_time);

        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_END, 10 + pair_index, N_PROFILING_LOOP, duration);
    }

    gdi_free_ext_mem(&nc_mem1);
    gdi_free_ext_mem(&nc_mem2);
    gdi_free_ext_mem(&ch_mem1);
    gdi_free_ext_mem(&ch_mem2);

    return 0;
}


#define MMI_EM_PROFILING_GDI_MEM_SIZE_64K (64 * 1024)

static S32 mmi_em_profiling_gdi_do_memcpy_64K(void *v_param)
{
    static const S32 N_PROFILING_LOOP = 300;

    struct {
        void *src;
        void *dest;
    } mem_pair[4];
    
    S32 pair_index, i;
    U32 start_time, duration;

    void *nc_mem1, *nc_mem2;
    void *ch_mem1, *ch_mem2;

    nc_mem1 = gdi_alloc_ext_mem_framebuffer(MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
    nc_mem2 = gdi_alloc_ext_mem_framebuffer(MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
    ch_mem1 = gdi_alloc_ext_mem_cacheable(MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
    ch_mem2 = gdi_alloc_ext_mem_cacheable(MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
        
    mem_pair[0].src = nc_mem1, mem_pair[0].dest = nc_mem2;
    mem_pair[1].src = nc_mem1, mem_pair[1].dest = ch_mem2;
    mem_pair[2].src = ch_mem1, mem_pair[2].dest = nc_mem2;
    mem_pair[3].src = ch_mem1, mem_pair[3].dest = ch_mem2;
    
    for (pair_index = 0; pair_index < 4; pair_index++)
    {
        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_START, 20 + pair_index);

        /* First-time access the memory, so that cache can be effective */
        memset(mem_pair[pair_index].src, 0, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
        memset(mem_pair[pair_index].dest, 0, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);

        start_time = drv_get_current_time();
//        SLA_CustomLogging("CPY", SA_start);
        for (i = (N_PROFILING_LOOP >> 1); i > 0; i--)
        {
            memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
            memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
        }
//        SLA_CustomLogging("CPY", SA_stop);
        duration = drv_get_duration_ms(start_time);

        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_END, 20 + pair_index, N_PROFILING_LOOP, duration);
    }

    pair_index = 3; /* C <-> C */
    {
        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_START, 30 + pair_index);

        /* First-time access the memory, so that cache can be effective */
        memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
        memcpy(mem_pair[pair_index].src, mem_pair[pair_index].dest, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);

        start_time = drv_get_current_time();
        for (i = N_PROFILING_LOOP >> 1; i > 0; i--)
        {
            memcpy(mem_pair[pair_index].dest, mem_pair[pair_index].src, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
            memcpy(mem_pair[pair_index].src, mem_pair[pair_index].dest, MMI_EM_PROFILING_GDI_MEM_SIZE_64K);
        }
        duration = drv_get_duration_ms(start_time);

        MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_MEMCPY_END, 30 + pair_index, N_PROFILING_LOOP, duration);
    }

    gdi_free_ext_mem(&nc_mem1);
    gdi_free_ext_mem(&nc_mem2);
    gdi_free_ext_mem(&ch_mem1);
    gdi_free_ext_mem(&ch_mem2);

    return 0;
}



#ifdef __MTK_TARGET__
#pragma arm
#endif

static kal_uint32 mmi_em_profiling_gdi_do_color_conversion_impl(kal_int32 n_profiling_loop)
{
    kal_int32 i;
    register kal_uint32 rgb888, rgb565;

    rgb888 = 0x998877;
    for (i = (n_profiling_loop >> 1); i > 0; i--)
    {
        rgb565 = GDI_RGB565_FROM_RGB888(rgb888);
        rgb888 = GDI_RGB888_FROM_RGB565(rgb565);
    }

    return rgb888;
}


static kal_uint32 mmi_em_profiling_gdi_do_alpha_blending_impl(kal_int32 n_profiling_loop)
{
    kal_uint32 target;
    kal_uint32 source, pixel;
    kal_uint32 inv_a;
    kal_int32 i;
 
    source = 0x99887766;
    pixel = 0x66554433;

    target = 0;
    inv_a = 0xff - GDI_A_OF_PARGB8888(source);
    for (i = n_profiling_loop; i > 0; i--)
    {
        target = GDI_PARGB8888(
            inv_a * GDI_A_OF_ARGB8888(pixel),
            inv_a * GDI_R_OF_ARGB8888(pixel),
            inv_a * GDI_G_OF_ARGB8888(pixel),
            inv_a * GDI_B_OF_ARGB8888(pixel));
        target += source;

        pixel ^= source;
    }

    return target;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif


static S32 mmi_em_profiling_gdi_do_color_conversion(void *v_param)
{
    static const S32 N_PROFILING_LOOP = 100 * 100 * 2000;

    U32 start_time, duration;
    U32 temp;


    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_COLOR_CONV_START);
    start_time = drv_get_current_time();

    temp = mmi_em_profiling_gdi_do_color_conversion_impl(N_PROFILING_LOOP);

    duration = drv_get_duration_ms(start_time);
    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_COLOR_CONV_END,
        N_PROFILING_LOOP, duration, temp);

    return 0;
}


static S32 mmi_em_profiling_gdi_do_alpha_blending(void *v_param)
{
    static const kal_int32 N_PROFILING_LOOP = 100 * 100 * 2000;

    U32 start_time, duration;
    U32 temp;


    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_ABLEND_START);
    start_time = drv_get_current_time();

    temp = mmi_em_profiling_gdi_do_alpha_blending_impl(N_PROFILING_LOOP);

    duration = drv_get_duration_ms(start_time);
    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_ABLEND_END,
        N_PROFILING_LOOP, duration, temp);

    return 0;
}


static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_speed_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_BLT_MEMCPY, mmi_em_profiling_gdi_do_memcpy, NULL },
    { MMI_EM_PROF_GDI_CASE_BLT_MEMCPY_FULL, mmi_em_profiling_gdi_do_memcpy_64K, NULL },
    { MMI_EM_PROF_GDI_CASE_BLT_COLOR_CONVERSION, mmi_em_profiling_gdi_do_color_conversion, NULL },
    { MMI_EM_PROF_GDI_CASE_BLT_ALPHA_BLENDING, mmi_em_profiling_gdi_do_alpha_blending, NULL },
    
    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_speed_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_BLT;
    test_suite->test_cases = g_mmi_em_profiling_speed_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}


#endif /* __MMI_EM_PROFILING_GDI_UI_INDEX__ */

