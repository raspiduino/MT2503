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
#include "gdi_include.h"
#include "gdi_internal.h"
#include "EngineerModeGDIProfiling.h"


#ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__


typedef struct
{
    kal_int32 id;
    MMI_BOOL (*create_layers)(gdi_handle *dest_layer, gdi_handle layer_hd[4]);
    void (*free_layers)(gdi_handle dest_layer, gdi_handle layer_hd[4]);
} mmi_em_profiling_flatten_param;


static S32 mmi_em_profiling_run_flatten(void *v_param)
{
    static const U32 PROFILING_MS = 4000;

    S32 i;
    gdi_handle dest_layer;
    gdi_handle layer_hd[4];
    U32 start_time, duration;
    const mmi_em_profiling_flatten_param *param = (const mmi_em_profiling_flatten_param*)v_param;


    gdi_layer_get_base_handle(&dest_layer);
    gdi_layer_push_and_set_active(dest_layer);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    layer_hd[0] = layer_hd[1] = layer_hd[2] = layer_hd[3] = 0;
    if (!param->create_layers(&dest_layer, layer_hd))
    {
        param->free_layers(dest_layer, layer_hd);
        return -1;
    }

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FLATTEN_START);

    gdi_layer_push_and_set_active(dest_layer);
    
    start_time = drv_get_current_time();
    i = 0;
    do
    {
        do 
        {
            gdi_layer_flatten(
                layer_hd[0],
                layer_hd[1],
                layer_hd[2],
                layer_hd[3]);
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

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FLATTEN_END, param->id, i, duration);

    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        dest_layer,
        0,
        0,
        0,
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);

    param->free_layers(dest_layer, layer_hd);

    return 0;
}



static S32 mmi_em_profiling_run_flatten_clip(void *v_param)
{
    static const U32 PROFILING_MS = 4000;

    S32 i;
    gdi_handle dest_layer;
    gdi_handle layer_hd[4];
    U32 start_time, duration;
    const mmi_em_profiling_flatten_param *param = (const mmi_em_profiling_flatten_param*)v_param;


    gdi_layer_get_base_handle(&dest_layer);
    gdi_layer_push_and_set_active(dest_layer);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    layer_hd[0] = layer_hd[1] = layer_hd[2] = layer_hd[3] = 0;
    if (!param->create_layers(&dest_layer, layer_hd))
    {
        param->free_layers(dest_layer, layer_hd);
        return -1;
    }

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FLATTEN_START);

    gdi_layer_push_and_set_active(dest_layer);
    
    start_time = drv_get_current_time();
    i = 0;
    do
    {
        do 
        {
            gdi_layer_flatten_with_clipping(
                layer_hd[0],
                layer_hd[1],
                layer_hd[2],
                layer_hd[3]);
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

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_FLATTEN_END, param->id, i, duration);

    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        dest_layer,
        0,
        0,
        0,
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);

    param->free_layers(dest_layer, layer_hd);

    return 0;
}


static void mmi_em_profiling_gdi_flatten_free_layers(gdi_handle dest_layer, gdi_handle layer_hd[4])
{
    gdi_handle base_handle;
    S32 i;

    gdi_layer_get_base_handle(&base_handle);

    if (dest_layer != 0 && dest_layer != base_handle)
    {
        mmi_em_profiling_gdi_free_layer(dest_layer);
    }

    for (i = 0; i < 4; i++)
    {
        if (layer_hd[i] != 0 &&
            layer_hd[i] != base_handle &&
            layer_hd[i] != dest_layer)
        {
            mmi_em_profiling_gdi_free_layer(layer_hd[i]);
        }
    }
}



MMI_BOOL mmi_em_profiling_gdi_flatten_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    if (layer_hd[0] == 0) return MMI_FALSE;
    gdi_layer_push_and_set_active(layer_hd[0]);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_layer_pop_and_restore_active();

    return MMI_TRUE;
}


MMI_BOOL mmi_em_profiling_gdi_flatten_small_in_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 50, 50);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 100, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 100, 0, 50, 50);
    layer_hd[3] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 100, 100, 50, 50);
    if (layer_hd[0] == 0 || layer_hd[1] == 0 || layer_hd[2] == 0 || layer_hd[3] == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_em_profiling_gdi_fill_colors(layer_hd, 4);

    return MMI_TRUE;
}


MMI_BOOL mmi_em_profiling_gdi_flatten_medium_in_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 100, 100, 100);
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


MMI_BOOL mmi_em_profiling_gdi_flatten_large_in_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 200, 200);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 200, 200, 200);
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P8888_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (layer_hd[0] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 1);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P8888_medium_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 100, 100, 100);
    
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P6666_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (layer_hd[0] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 1);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P6666_medium_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);

    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 100, 100, 100);
    
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


MMI_BOOL mmi_em_profiling_gdi_flatten_small_out_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 10, 90, 20, 20);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 100, 100, 100);
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


MMI_BOOL mmi_em_profiling_gdi_flatten_large_out_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 200, 200);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 100, 100, 100);
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static void mmi_em_profiling_gdi_flatten_free_layers_clip(gdi_handle dest_layer, gdi_handle layer_hd[4])
{
    if (dest_layer != 0)
    {
        gdi_layer_push_and_set_active(dest_layer);
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
    }

    mmi_em_profiling_gdi_flatten_free_layers(dest_layer, layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P32_TO_P32_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (*dest_layer == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P32_TO_P32_clip_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (*dest_layer != 0)
    {
        gdi_layer_push_and_set_active(*dest_layer);
        gdi_layer_push_and_set_clip(0, 0, 69, 69);
        gdi_layer_pop_and_restore_active();
    }
    
    if (*dest_layer == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P32_TO_16_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P32_TO_16_clip_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (*dest_layer != 0)
    {
        gdi_layer_push_and_set_active(*dest_layer);
        gdi_layer_push_and_set_clip(0, 0, 69, 69);
        gdi_layer_pop_and_restore_active();
    }
    
    if (*dest_layer == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P6666_TO_P6666_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (*dest_layer == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P6666_TO_P6666_clip_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (*dest_layer != 0)
    {
        gdi_layer_push_and_set_active(*dest_layer);
        gdi_layer_push_and_set_clip(0, 0, 69, 69);
        gdi_layer_pop_and_restore_active();
    }
    
    if (*dest_layer == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P6666_TO_16_full_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    
    if (layer_hd[0] == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}


static MMI_BOOL mmi_em_profiling_gdi_flatten_P6666_TO_16_clip_create(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    layer_hd[0] = *dest_layer;
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    if (*dest_layer != 0)
    {
        gdi_layer_push_and_set_active(*dest_layer);
        gdi_layer_push_and_set_clip(0, 0, 69, 69);
        gdi_layer_pop_and_restore_active();
    }
    
    if (*dest_layer == 0 || layer_hd[1] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_colors(layer_hd, 2);

    return MMI_TRUE;
}



static const mmi_em_profiling_flatten_param g_mmi_em_profiling_flatten_case[] =
{
    { 0, mmi_em_profiling_gdi_flatten_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 1, mmi_em_profiling_gdi_flatten_small_in_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 2, mmi_em_profiling_gdi_flatten_medium_in_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 3, mmi_em_profiling_gdi_flatten_large_in_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 4, mmi_em_profiling_gdi_flatten_small_out_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 5, mmi_em_profiling_gdi_flatten_large_out_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 6, mmi_em_profiling_gdi_flatten_P8888_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 7, mmi_em_profiling_gdi_flatten_P8888_medium_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 8, mmi_em_profiling_gdi_flatten_P6666_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 9, mmi_em_profiling_gdi_flatten_P6666_medium_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 10, mmi_em_profiling_gdi_flatten_P32_TO_P32_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 11, mmi_em_profiling_gdi_flatten_P32_TO_P32_clip_create, mmi_em_profiling_gdi_flatten_free_layers_clip },
    { 12, mmi_em_profiling_gdi_flatten_P32_TO_16_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 13, mmi_em_profiling_gdi_flatten_P32_TO_16_clip_create, mmi_em_profiling_gdi_flatten_free_layers_clip },
    { 14, mmi_em_profiling_gdi_flatten_P6666_TO_P6666_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 15, mmi_em_profiling_gdi_flatten_P6666_TO_P6666_clip_create, mmi_em_profiling_gdi_flatten_free_layers_clip },
    { 16, mmi_em_profiling_gdi_flatten_P6666_TO_16_full_create, mmi_em_profiling_gdi_flatten_free_layers },
    { 17, mmi_em_profiling_gdi_flatten_P6666_TO_16_clip_create, mmi_em_profiling_gdi_flatten_free_layers_clip },
    
    { -1, NULL, NULL }
};


static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_flatten_test_cases[] =
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT
    { MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB8888_FULL, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[6] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB8888_MEDIUM, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[7] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB6666_FULL, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[8] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB6666_MEDIUM, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[9] },
#endif
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_P32_FULL, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[10] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_P32_CLIP, mmi_em_profiling_run_flatten_clip, (void*)&g_mmi_em_profiling_flatten_case[11] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_16_FULL, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[12] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_16_CLIP, mmi_em_profiling_run_flatten_clip, (void*)&g_mmi_em_profiling_flatten_case[13] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_P6666_FULL, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[14] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_P6666_CLIP, mmi_em_profiling_run_flatten_clip, (void*)&g_mmi_em_profiling_flatten_case[15] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_16_FULL, mmi_em_profiling_run_flatten, (void*)&g_mmi_em_profiling_flatten_case[16] },
    { MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_16_CLIP, mmi_em_profiling_run_flatten_clip, (void*)&g_mmi_em_profiling_flatten_case[17] },
    
    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_flatten_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_FLATTEN;
    test_suite->test_cases = g_mmi_em_profiling_flatten_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}


MMI_BOOL mmi_em_profiling_gdi_func_fill_src(gdi_handle layer_hd[4])
{
    if (layer_hd[0] == 0 || layer_hd[1] == 0 || layer_hd[2] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_white(layer_hd[0]);
    mmi_em_profiling_gdi_fill_colors(layer_hd + 1, 2);

    return MMI_TRUE;
}


MMI_BOOL mmi_em_profiling_gdi_func_fill_src_global_opa(gdi_handle layer_hd[4])
{
    if (layer_hd[0] == 0 || layer_hd[1] == 0 || layer_hd[2] == 0)
    {
        /* free will be called */
        return MMI_FALSE;
    }

    mmi_em_profiling_gdi_fill_white(layer_hd[0]);
    mmi_em_profiling_gdi_fill_color_global_opa(layer_hd + 1, 2);

    return MMI_TRUE;
}


/* To test whether flatten function works properly */
static S32 mmi_em_profiling_run_flatten_functional(void *v_param)
{
    gdi_handle dest_layer;
    gdi_handle layer_hd[4];
    const mmi_em_profiling_flatten_param *param = (const mmi_em_profiling_flatten_param*)v_param;

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case

    gdi_layer_get_base_handle(&dest_layer);
    gdi_layer_push_and_set_active(dest_layer);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    layer_hd[0] = layer_hd[1] = layer_hd[2] = layer_hd[3] = 0;
    if (!param->create_layers(&dest_layer, layer_hd))
    {
        param->free_layers(dest_layer, layer_hd);
        return -1;
    }

    gdi_layer_push_and_set_active(dest_layer);

    gdi_layer_flatten(
        layer_hd[0],
        layer_hd[1],
        layer_hd[2],
        layer_hd[3]);

    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        dest_layer,
        0,
        0,
        0,
        0,
        0,
        GDI_LCD_WIDTH - 1,
        GDI_LCD_HEIGHT - 1);

    param->free_layers(dest_layer, layer_hd);

    return 0;
}


static MMI_BOOL mmi_em_profiling_gdi_fla5888_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla5866_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla5566_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla5586_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla6586_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 100, 100);;
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla6568_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 100, 100);;
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}



static MMI_BOOL mmi_em_profiling_gdi_fla5888g_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla5586g_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    gdi_layer_get_base_handle(dest_layer);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla6586g_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 100, 100);;
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    return mmi_em_profiling_gdi_func_fill_src_global_opa(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla5586r_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    gdi_layer_push_and_set_active(layer_hd[2]);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    gdi_layer_pop_and_restore_active();

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static MMI_BOOL mmi_em_profiling_gdi_fla6586r_func(gdi_handle *dest_layer, gdi_handle layer_hd[4])
{
    *dest_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 0, 100, 100);
    layer_hd[0] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_16, 0, 0, 100, 100);
    layer_hd[1] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 20, 50, 50);
    layer_hd[2] = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_PARGB6666, 0, 50, 50, 50);

    gdi_layer_push_and_set_active(layer_hd[2]);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    gdi_layer_pop_and_restore_active();

    return mmi_em_profiling_gdi_func_fill_src(layer_hd);
}


static S32 mmi_em_profiling_gdi_nb_flatten(void *v_param)
{
    gdi_handle src_layer, dest_layer;
    S32 i;

    src_layer = mmi_em_profiling_gdi_create_layer(GDI_COLOR_FORMAT_32_PARGB, 0, 0, 100, 100);
    gdi_layer_push_and_set_active(src_layer);
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_get_base_handle(&dest_layer);

    gdi_layer_push_and_set_active(dest_layer);
    for (i = 0; i < 10; i++)
    {
        gdi_layer_flatten_nb_ext(src_layer, 0, 0, 0
                            #ifdef GDI_6_LAYERS
                                , 0, 0
                            #endif
                            #ifdef GDI_NB_BLT_SUPPORT
                                , NULL, NULL
                            #endif
                                );
        if (i < 5)
        {
            gdi_layer_flatten_nb_wait_for_previous_finish();
        }
    }
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        dest_layer, 0, 0, 0,
        0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);

    gdi_layer_free(src_layer);

    return 0;
}


static const mmi_em_profiling_flatten_param g_mmi_em_profiling_fla_func_case[] =
{
    { 0, mmi_em_profiling_gdi_fla5888_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 1, mmi_em_profiling_gdi_fla5866_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 2, mmi_em_profiling_gdi_fla5566_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 3, mmi_em_profiling_gdi_fla5586_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 4, mmi_em_profiling_gdi_fla6586_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 5, mmi_em_profiling_gdi_fla6568_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 6, mmi_em_profiling_gdi_fla5888g_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 7, mmi_em_profiling_gdi_fla5586g_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 8, mmi_em_profiling_gdi_fla6586g_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 9, mmi_em_profiling_gdi_fla5586r_func, mmi_em_profiling_gdi_flatten_free_layers },
    { 10, mmi_em_profiling_gdi_fla6586r_func, mmi_em_profiling_gdi_flatten_free_layers },

    { -1, NULL, NULL }
};



static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_fla_func_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 0, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[0] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 1, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[1] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 2, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[2] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 3, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[3] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 4, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[4] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 5, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[5] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 6, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[6] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 7, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[7] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 8, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[8] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 9, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[9] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 10, mmi_em_profiling_run_flatten_functional, (void*)&g_mmi_em_profiling_fla_func_case[10] },
    { MMI_EM_PROF_GDI_CASE_FUNCTIONAL + 11, mmi_em_profiling_gdi_nb_flatten, NULL },
    
    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_fla_func_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_FUNCTIONAL;
    test_suite->test_cases = g_mmi_em_profiling_gdi_fla_func_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}

#endif /* __MMI_EM_PROFILING_GDI_UI_INDEX__ */

