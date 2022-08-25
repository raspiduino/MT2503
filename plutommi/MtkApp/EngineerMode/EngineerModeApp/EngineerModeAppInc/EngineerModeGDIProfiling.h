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
 *  EngineerModeGDIProfiling.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef ENGINEER_MODE_GDI_PROFILING_H
#define ENGINEER_MODE_GDI_PROFILING_H

#include "MMI_features.h"

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
#ifdef __MMI_EM_PROFILING_GDI_PROFILING__

#include "MenuCuiGprot.h"


/***************************************************************************** 
 * Test Suite ID
 *****************************************************************************/

typedef enum
{
    MMI_EM_PROF_GDI_SUITE_INVALID = 0,
    MMI_EM_PROF_GDI_SUITE_BLT,
    MMI_EM_PROF_GDI_SUITE_FLATTEN,
    MMI_EM_PROF_GDI_SUITE_MISC,
    MMI_EM_PROF_GDI_SUITE_FUNCTIONAL,
    MMI_EM_PROF_GDI_SUITE_DECODER_SPEED,
    MMI_EM_PROF_GDI_SUITE_DECODER_FUNC,

    MMI_EM_PROF_GDI_SUITE_END_OF_ENUM
} mmi_em_profiling_gdi_suite_enum;


/***************************************************************************** 
 * Test case ID
 *****************************************************************************/

typedef enum
{
    MMI_EM_PROF_GDI_CASE_INVALID = 0,
    
    MMI_EM_PROF_GDI_CASE_BLT_MEMCPY = 100,
    MMI_EM_PROF_GDI_CASE_BLT_MEMCPY_FULL,
    MMI_EM_PROF_GDI_CASE_BLT_COLOR_CONVERSION,
    MMI_EM_PROF_GDI_CASE_BLT_ALPHA_BLENDING,
    
    MMI_EM_PROF_GDI_CASE_BLT_FULL = 1000,
    MMI_EM_PROF_GDI_CASE_BLT_1,
    MMI_EM_PROF_GDI_CASE_BLT_PARGB8888_SMALL = 1100,
    MMI_EM_PROF_GDI_CASE_BLT_PARGB8888_FULL,
    MMI_EM_PROF_GDI_CASE_BLT_PARGB6666_SMALL,
    MMI_EM_PROF_GDI_CASE_BLT_PARGB6666_FULL,
    MMI_EM_PROF_GDI_CASE_BLT_PARGB6666_TEST = 1200,
    
    MMI_EM_PROF_GDI_CASE_FLATTEN_FULL = 2000,
    MMI_EM_PROF_GDI_CASE_FLATTEN_SMALL_IN,
    MMI_EM_PROF_GDI_CASE_FLATTEN_MEDIUM_IN,
    MMI_EM_PROF_GDI_CASE_FLATTEN_LARGE_IN,
    MMI_EM_PROF_GDI_CASE_FLATTEN_SMALL_OUT = 2010,
    MMI_EM_PROF_GDI_CASE_FLATTEN_LARGE_OUT,
    MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB8888_FULL = 2100,
    MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB8888_MEDIUM,
    MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB6666_FULL,
    MMI_EM_PROF_GDI_CASE_FLATTEN_PARGB6666_MEDIUM,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_P32_FULL = 2110,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_P32_CLIP,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_16_FULL,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P32_TO_16_CLIP,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_P6666_FULL,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_P6666_CLIP,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_16_FULL,
    MMI_EM_PROF_GDI_CASE_FLATTEN_P6666_TO_16_CLIP,

    MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM = 5000,
    MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_1,
    MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_NEAREST,
    MMI_EM_PROF_GDI_CASE_LINEAR_TRANSFORM_BILINEAR,

    MMI_EM_PROF_GDI_CASE_DECODER_9SLICE = 6000,
    MMI_EM_PROF_GDI_CASE_DECODER_ABM = 6100,
    MMI_EM_PROF_GDI_CASE_DECODER_AB2 = 6200,
    MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED = 6300,
    MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED = 6400,
    MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED = 6500,

    MMI_EM_PROF_GDI_CASE_MISC = 10000,
    MMI_EM_PROF_GDI_CASE_G2D_FRECT_FULL_P8888 = 10100,
    MMI_EM_PROF_GDI_CASE_G2D_FRECT_FULL_P6666,
    MMI_EM_PROF_GDI_CASE_G2D_FRECT_FULL_565,
    MMI_EM_PROF_GDI_CASE_G2D_FRECT_SMALL_P8888,
    MMI_EM_PROF_GDI_CASE_G2D_FRECT_SMALL_P6666,
    MMI_EM_PROF_GDI_CASE_G2D_FRECT_SMALL_565,
    MMI_EM_PROF_GDI_CASE_SW_FRECT_FULL_P8888 = 10150,
    MMI_EM_PROF_GDI_CASE_SW_FRECT_FULL_P6666,
    MMI_EM_PROF_GDI_CASE_SW_FRECT_FULL_565,
    MMI_EM_PROF_GDI_CASE_SW_FRECT_SMALL_P8888,
    MMI_EM_PROF_GDI_CASE_SW_FRECT_SMALL_P6666,
    MMI_EM_PROF_GDI_CASE_SW_FRECT_SMALL_565,

    MMI_EM_PROF_GDI_CASE_FUNCTIONAL = 50000,

    MMI_EM_PROF_GDI_CASE_END_OF_ENUM
} mmi_em_profiling_gdi_case_enum;


/***************************************************************************** 
 * Framework structure
 *****************************************************************************/

typedef struct
{
    kal_uint32 id; /* should be registered in mmi_em_profiling_gdi_case_enum */
    S32 (*func)(void *param);
    void *param;
} mmi_em_profiling_gdi_test_case;


typedef struct mmi_em_profiling_gdi_test_suite_s
{
    mmi_em_profiling_gdi_suite_enum id;
    const mmi_em_profiling_gdi_test_case *test_cases;
    S32 interval_ms;
    void (*finalize)(struct mmi_em_profiling_gdi_test_suite_s *test_suite);
    void *user_data;

    /* Private data */
    kal_int32 next_case_index;
    gdi_handle pre_layers[6];
} mmi_em_profiling_gdi_test_suite;


/***************************************************************************** 
 * Framework API
 *****************************************************************************/

extern mmi_ret mmi_em_profiling_gdi_menu_select_hdlr(cui_menu_event_struct *event);

void mmi_em_profiling_gdi_free_suite(mmi_em_profiling_gdi_test_suite *test_suite);

gdi_handle mmi_em_profiling_gdi_create_layer(
    gdi_color_format cf,
    S32 offset_x,
    S32 offset_y,
    S32 width,
    S32 height);

void mmi_em_profiling_gdi_free_layer(gdi_handle handle);

void mmi_em_profiling_gdi_free_layers(gdi_handle layer_hd[4]);

void mmi_em_profiling_gdi_fill_colors(gdi_handle layer_hd[], S32 n);

void mmi_em_profiling_gdi_fill_color_global_opa(gdi_handle layer_hd[], S32 n);

void mmi_em_profiling_gdi_fill_white(gdi_handle layer);

void mmi_em_profiling_gdi_func_clean_screen(void);

MMI_BOOL mmi_em_profiling_gdi_func_fill_src(gdi_handle layer_hd[4]);

MMI_BOOL mmi_em_profiling_gdi_func_fill_src_global_opa(gdi_handle layer_hd[4]);


/***************************************************************************** 
 * Test case entry
 *****************************************************************************/

#ifdef __MMI_EM_PROFILING_IMG_DEC__
/* under construction !*/
#endif

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_speed_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_blt_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_blt_func_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_flatten_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_fla_func_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_lt_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_frect_func_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_frect_speed_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_decoder_speed_suite(void);

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_decoder_func_suite(void);


#endif

#endif /* ENGINEER_MODE_GDI_PROFILING_H */

