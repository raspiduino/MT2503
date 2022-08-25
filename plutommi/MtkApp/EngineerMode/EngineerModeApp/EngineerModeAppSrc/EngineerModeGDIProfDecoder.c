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
 *  EngineerModeGDIProfDecoder.c
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

#include "mmi_rp_app_engineermode1_def.h" // Test images


#ifdef __MMI_EM_PROFILING_GDI_UI_INDEX__

/***************************************************************************** 
 * Variable Define
 *****************************************************************************/

#define prof_9s_test_img_1 IMG_ID_EM_GDIPROFILING_9SLICE_REPEAT_1 //IMG_ID_VAPP_LAUNCHER_ROBOT_MM_APP_COUNTER_BG // 35x33: same size for message number [16,0,16,0 repeat]: MainLCD\\Default\\Common\\Point_BG.9slice.png
#define prof_9s_test_img_2 IMG_ID_EM_GDIPROFILING_9SLICE_REPEAT_2 //IMG_ID_VAPP_FM_TUNER_LIGHT // 73x53 [36,26,36,26 stretch]: MainLCD\\Default\\FMRadio\\tune_bg_light.9slice.png
#define prof_9s_test_img_3 IMG_ID_EM_GDIPROFILING_9SLICE_STRETCH //IMG_ID_VAPP_FM_HOLE // 10x20: repeat mode [0,0,0,0 repeat]: MainLCD\\Default\\FMRadio\\speaker_hole.9slice.png 

#define prof_ab2_test_img_1 IMG_ID_EM_GDIPROFILING_AB2_ALPHA//IMG_ID_VAPP_GALLERY_IDX_PICTURE_ICON //56x56
#define prof_ab2_test_img_2 IMG_ID_EM_GDIPROFILING_AB2_FULLY_OPAQUE//IMG_ID_VAPP_SETTING_LAUNCHER_SELECT //39x39
#define prof_ab2_test_img_3 IMG_ID_EM_GDIPROFILING_AB2_SOURCE_KEY //IMG_GLOBAL_QUESTION //24x24 

#define prof_abm_test_img_1 IMG_ID_EM_GDIPROFILING_ABM_ALPHA //56x56
#define prof_abm_test_img_2 IMG_ID_EM_GDIPROFILING_ABM_NO_ALPHA //39x39

#define prof_test_rect1 {0,0,0,0}
#define prof_test_rect2 {0,0,10,10}
#define prof_test_rect3 {0,0,50,50}
#define prof_test_rect4 {0,0,100,100}
#define prof_test_rect5 {0,0,200,200}

#define prof_FORCE_9S_AB2_ALPHA_BLEND GDI_IMAGE_CODEC_FLAG_FORCE_9SLICE_ALPHA_BLEND|GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND

/***************************************************************************** 
 * Type Define
 *****************************************************************************/
typedef struct
{
    S32 x;
    S32 y;
    S32 w;
    S32 h;
} mmi_em_profling_decode_image_rect;

typedef struct
{
    kal_int32 id;
    gdi_color_format dst_layer_cf;
    U16 img_id;
    mmi_em_profling_decode_image_rect img_rect;
    GDI_RESULT (*img_draw_id)(S32 dx, S32 dy, U16 img_id);
    GDI_RESULT (*img_draw_resized_id)(S32 dx, S32 dy, S32 dw, S32 dh, U16 img_id);
    U32 img_decode_flag;
    char* output_filename;
} mmi_em_profiling_decode_image_param;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static S32 g_mmi_em_profiling_decode_image_layer_w = 200;
static S32 g_mmi_em_profiling_decode_image_layer_h = 200;
static U8  g_mmi_em_profiling_decode_image_test_iteration = 10;
static U8 g_save_img_cnt = 0;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
GDI_RESULT mmi_em_profiling_gdi_decoder_draw_id(S32 dx, S32 dy, U16 img_id)
{
    return gdi_image_draw_id(dx,dy,img_id);
}

GDI_RESULT mmi_em_profiling_gdi_decoder_draw_resized_id(S32 dx, S32 dy, S32 dw, S32 dh, U16 img_id)
{
    return gdi_image_draw_resized_id(dx,dy,dw,dh,img_id);
}

GDI_RESULT mmi_em_profiling_gdi_decoder_save_image(gdi_handle layer, char* name, int seq, int ext_seq)
{
    GDI_RESULT ret = GDI_SUCCEED;
    char filename[128];
    wchar_t filename_w[128];

    #ifdef __MTK_TARGET__
        sprintf(filename,"E:\\%s_%d_%d.bmp",name,seq,ext_seq);
    #else
        sprintf(filename,"D:\\%s_%d_%d.bmp",name,seq,ext_seq);
    #endif
    mmi_asc_to_wcs(filename_w,filename);
    ret = gdi_layer_save_bmp_file((gdi_handle)layer, (PS8)filename_w);

    kal_prompt_trace(MOD_MMI,"[Shooting] filename = %s, name = %s, seq = %d, ext_seq = %d",filename, name, seq, ext_seq);
    
    return ret;
}


GDI_RESULT mmi_em_profiling_gdi_decoder_save_act_image(char* name, int seq, int ext_seq)
{
    GDI_RESULT ret = GDI_SUCCEED;
    char filename[128];
    wchar_t filename_w[128];

    #ifdef __MTK_TARGET__
        sprintf(filename,"E:\\%s_%d_%d.bmp",name,seq,ext_seq);
    #else
        sprintf(filename,"D:\\%s_%d_%d.bmp",name,seq,ext_seq);
    #endif
    mmi_asc_to_wcs(filename_w,filename);
    ret = gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (PS8)filename_w);

    kal_prompt_trace(MOD_MMI,"[Shooting] filename = %s, name = %s, seq = %d, ext_seq = %d",filename, name, seq,ext_seq);
    
    return ret;
}

static S32 mmi_em_profiling_decode_gdi_image_9slice(void *v_param)
{
    const mmi_em_profiling_decode_image_param *param = (const mmi_em_profiling_decode_image_param*)v_param;
    mmi_em_profling_decode_image_rect rect = param->img_rect;
    gdi_handle dst_layer = GDI_NULL_HANDLE;
    gdi_handle base_layer = GDI_NULL_HANDLE;

    if(param->dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        #ifndef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT   
            return 0;
        #endif
    }
    
    mmi_em_profiling_gdi_func_clean_screen(); // To separate case
    
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    dst_layer = mmi_em_profiling_gdi_create_layer(param->dst_layer_cf, rect.x, rect.y, g_mmi_em_profiling_decode_image_layer_w, g_mmi_em_profiling_decode_image_layer_h);
    
    gdi_layer_push_and_set_active(dst_layer);
    gdi_push_and_set_alpha_blending_source_layer(dst_layer);
    gdi_layer_clear(GDI_COLOR_GREEN);

    /* start decode */
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 

    if(param->img_draw_id)
    {
        param->img_draw_id(rect.x,rect.y,param->img_id);
    }

    if(param->img_draw_resized_id)
    {
        param->img_draw_resized_id(rect.x,rect.y,rect.w,rect.h,param->img_id);
    }

    gdi_image_codec_set_flag_end();

    /* show on LCD */
    gdi_layer_blt(
                base_layer,
                (gdi_handle)gdi_act_layer,
                0,
                0,
                0,
                0,
                GDI_LCD_WIDTH - 1,
                GDI_LCD_HEIGHT - 1);

    /* save result */
    if(param->output_filename)
    {
        mmi_em_profiling_gdi_decoder_save_act_image(param->output_filename,0,g_save_img_cnt++);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    mmi_em_profiling_gdi_free_layer(dst_layer);
    
}

static S32 mmi_em_profiling_decode_gdi_image_ab2(void *v_param)
{
    const mmi_em_profiling_decode_image_param *param = (const mmi_em_profiling_decode_image_param*)v_param;
    mmi_em_profling_decode_image_rect rect = param->img_rect;
    gdi_handle dst_layer = GDI_NULL_HANDLE;
    gdi_handle base_layer = GDI_NULL_HANDLE;

    if(param->dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        #ifndef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT   
            return 0;
        #endif
    }

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case
    
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    dst_layer = mmi_em_profiling_gdi_create_layer(param->dst_layer_cf, rect.x, rect.y, g_mmi_em_profiling_decode_image_layer_w, g_mmi_em_profiling_decode_image_layer_h);
    
    gdi_layer_push_and_set_active(dst_layer);
    gdi_push_and_set_alpha_blending_source_layer(dst_layer);
    gdi_layer_clear(gdi_act_color_from_rgb(255,255,255,0)); //Yellow

    /* start decode */
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 

    if(param->img_draw_id)
    {
        param->img_draw_id(rect.x,rect.y,param->img_id);
    }

    if(param->img_draw_resized_id)
    {
        param->img_draw_resized_id(rect.x,rect.y,rect.w,rect.h,param->img_id);
    }

    gdi_image_codec_set_flag_end();

    /* show on LCD */
    gdi_layer_blt(
                base_layer,
                (gdi_handle)gdi_act_layer,
                0,
                0,
                0,
                0,
                GDI_LCD_WIDTH - 1,
                GDI_LCD_HEIGHT - 1);

    /* save result */
    if(param->output_filename)
    {
        mmi_em_profiling_gdi_decoder_save_act_image(param->output_filename,0,g_save_img_cnt++);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    mmi_em_profiling_gdi_free_layer(dst_layer);
    
}


static S32 mmi_em_profiling_decode_gdi_image_abm(void *v_param)
{
    const mmi_em_profiling_decode_image_param *param = (const mmi_em_profiling_decode_image_param*)v_param;
    mmi_em_profling_decode_image_rect rect = param->img_rect;
    gdi_handle dst_layer = GDI_NULL_HANDLE;
    gdi_handle base_layer = GDI_NULL_HANDLE;

    if(param->dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        #ifndef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT   
            return 0;
        #endif
    }

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case
    
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    dst_layer = mmi_em_profiling_gdi_create_layer(param->dst_layer_cf, rect.x, rect.y, g_mmi_em_profiling_decode_image_layer_w, g_mmi_em_profiling_decode_image_layer_h);
    
    gdi_layer_push_and_set_active(dst_layer);
    gdi_push_and_set_alpha_blending_source_layer(dst_layer);
    gdi_layer_clear(gdi_act_color_from_rgb(255,255,0,128)); //pink

    /* start decode */
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 

    if(param->img_draw_id)
    {
        param->img_draw_id(rect.x,rect.y,param->img_id);
    }

    if(param->img_draw_resized_id)
    {
        param->img_draw_resized_id(rect.x,rect.y,rect.w,rect.h,param->img_id);
    }

    gdi_image_codec_set_flag_end();

    /* show on LCD */
    gdi_layer_blt(
                base_layer,
                (gdi_handle)gdi_act_layer,
                0,
                0,
                0,
                0,
                GDI_LCD_WIDTH - 1,
                GDI_LCD_HEIGHT - 1);

    /* save result */
    if(param->output_filename)
    {
        mmi_em_profiling_gdi_decoder_save_act_image(param->output_filename,0,g_save_img_cnt++);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    mmi_em_profiling_gdi_free_layer(dst_layer);
    
}


static mmi_em_profiling_decode_image_param g_mmi_em_profiling_9slice_case[] =
{
    { 0, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 1, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 2, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 3, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},   
    { 4, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 5, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},   

    
    { 6, GDI_COLOR_FORMAT_16,prof_9s_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 7, GDI_COLOR_FORMAT_16,prof_9s_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 8, GDI_COLOR_FORMAT_16,prof_9s_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 9, GDI_COLOR_FORMAT_16,prof_9s_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},   
    { 10, GDI_COLOR_FORMAT_16,prof_9s_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 11, GDI_COLOR_FORMAT_16,prof_9s_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},   

    { 12, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 13, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 14, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 15, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},   
    { 16, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 17, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},     

    { 18, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 19, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 20, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 21, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},      
    { 22, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 23, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},   

    
    { 24, GDI_COLOR_FORMAT_16,prof_9s_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 25, GDI_COLOR_FORMAT_16,prof_9s_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 26, GDI_COLOR_FORMAT_16,prof_9s_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 27, GDI_COLOR_FORMAT_16,prof_9s_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},   
    { 28, GDI_COLOR_FORMAT_16,prof_9s_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 29, GDI_COLOR_FORMAT_16,prof_9s_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},   

    { 30, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 31, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},     
    { 32, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 33, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},     
    { 34, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 35, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},      

    { 36, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 37, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 38, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 39, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},      
    { 40, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 41, GDI_COLOR_FORMAT_32_PARGB,prof_9s_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},   

    
    { 42, GDI_COLOR_FORMAT_16,prof_9s_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 43, GDI_COLOR_FORMAT_16,prof_9s_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},   
    { 44, GDI_COLOR_FORMAT_16,prof_9s_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 45, GDI_COLOR_FORMAT_16,prof_9s_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},   
    { 46, GDI_COLOR_FORMAT_16,prof_9s_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 47, GDI_COLOR_FORMAT_16,prof_9s_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},   

    { 48, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "9s"},
    { 49, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s"},     
    { 50, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_downscale"},
    { 51, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_downscale"},     
    { 52, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "9s_upscale"},
    { 53, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,prof_FORCE_9S_AB2_ALPHA_BLEND, "9s_upscale"},    

    { -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,}
};

static mmi_em_profiling_decode_image_param g_mmi_em_profiling_ab2_case[] =
{
//img1
    { 0, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 1, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 2, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 3, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    

    { 4, GDI_COLOR_FORMAT_16,prof_ab2_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 5, GDI_COLOR_FORMAT_16,prof_ab2_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 6, GDI_COLOR_FORMAT_16,prof_ab2_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 7, GDI_COLOR_FORMAT_16,prof_ab2_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    
    
    { 8, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 9, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 10, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 11, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    
//img2
    { 12, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 13, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 14, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 15, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    

    { 16, GDI_COLOR_FORMAT_16,prof_ab2_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 17, GDI_COLOR_FORMAT_16,prof_ab2_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 18, GDI_COLOR_FORMAT_16,prof_ab2_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 19, GDI_COLOR_FORMAT_16,prof_ab2_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    
  
    { 20, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 21, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 22, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 23, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    
//img3
    { 24, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 25, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 26, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 27, GDI_COLOR_FORMAT_32_PARGB,prof_ab2_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    

    { 28, GDI_COLOR_FORMAT_16,prof_ab2_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 29, GDI_COLOR_FORMAT_16,prof_ab2_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 30, GDI_COLOR_FORMAT_16,prof_ab2_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 31, GDI_COLOR_FORMAT_16,prof_ab2_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    
  
    { 32, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "ab2_ori_no_forceBlending"},
    { 33, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_3,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_ori"},     
    { 34, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_3,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_downscale"},
    { 35, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_3,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND, "ab2_upscale"},    
};

static mmi_em_profiling_decode_image_param g_mmi_em_profiling_abm_case[] =
{
//img1
    { 0, GDI_COLOR_FORMAT_32_PARGB,prof_abm_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "abm_ori"},    
    { 1, GDI_COLOR_FORMAT_32_PARGB,prof_abm_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_downscale"},
    { 2, GDI_COLOR_FORMAT_32_PARGB,prof_abm_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_upscale"},    

    { 3, GDI_COLOR_FORMAT_16,prof_abm_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "abm_ori"},     
    { 4, GDI_COLOR_FORMAT_16,prof_abm_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_downscale"},
    { 5, GDI_COLOR_FORMAT_16,prof_abm_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_upscale"},    
    
    { 6, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_1,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "abm_ori"},     
    { 7, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_1,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_downscale"},
    { 8, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_1,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_upscale"},    
//img2
    { 9, GDI_COLOR_FORMAT_32_PARGB,prof_abm_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "abm_ori"},     
    { 10, GDI_COLOR_FORMAT_32_PARGB,prof_abm_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_downscale"},
    { 11, GDI_COLOR_FORMAT_32_PARGB,prof_abm_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_upscale"},    

    { 12, GDI_COLOR_FORMAT_16,prof_abm_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "abm_ori"},     
    { 13, GDI_COLOR_FORMAT_16,prof_abm_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_downscale"},
    { 14, GDI_COLOR_FORMAT_16,prof_abm_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_upscale"},    
        
    { 15, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_2,prof_test_rect1,mmi_em_profiling_gdi_decoder_draw_id, NULL,0, "abm_ori"},     
    { 16, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_2,prof_test_rect2, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_downscale"},
    { 17, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_2,prof_test_rect4, NULL, mmi_em_profiling_gdi_decoder_draw_resized_id,0, "abm_upscale"},    
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
#endif
};

static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_decoder_func_test_cases[] =
{
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM  , mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[0] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+1, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[1] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+2, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[2] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+3, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[3] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+4, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[4] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+5, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[5] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+6, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[6] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+7, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[7] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+8, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[8] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+9, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[9] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+10, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[10] },  
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+11, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[11] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+12, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[12] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+13, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[13] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+14, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[14] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+15, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[15] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+16, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[16] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM+17, mmi_em_profiling_decode_gdi_image_abm, (void*)&g_mmi_em_profiling_abm_case[17] },
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
#endif
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2  , mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[0] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+1, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[1] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+2, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[2] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+3, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[3] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+4, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[4] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+5, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[5] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+6, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[6] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+7, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[7] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+8, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[8] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+9, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[9] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+10, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[10] },  
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+11, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[11] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+12, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[12] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+13, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[13] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+14, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[14] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+15, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[15] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+16, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[16] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+17, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[17] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+18, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[18] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+19, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[19] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+20, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[20] }, 
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+21, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[21] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+22, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[22] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+23, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[23] }, 
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+24, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[24] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+25, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[25] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+26, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[26] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+27, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[27] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+28, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[28] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+29, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[29] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+30, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[30] },        
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+31, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[31] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+32, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[32] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+33, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[33] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+34, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[34] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2+35, mmi_em_profiling_decode_gdi_image_ab2, (void*)&g_mmi_em_profiling_ab2_case[35] }, 
        
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE  , mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[0] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+1, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[1] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+2, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[2] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+3, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[3] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+4, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[4] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+5, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[5] },   
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+6, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[6] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+7, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[7] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+8, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[8] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+9, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[9] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+10, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[10] },        
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+11, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[11] },  
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+12, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[12] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+13, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[13] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+14, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[14] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+15, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[15] },   
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+16, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[16] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+17, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[17] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+18, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[18] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+19, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[19] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+20, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[20] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+21, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[21] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+22, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[22] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+23, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[23] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+24, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[24] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+25, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[25] },   
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+26, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[26] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+27, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[27] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+28, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[28] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+29, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[29] },  
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+30, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[30] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+31, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[31] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+32, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[32] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+33, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[33] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+34, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[34] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+35, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[35] },  
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+36, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[36] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+37, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[37] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+38, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[38] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+39, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[39] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+40, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[40] },  
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+41, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[41] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+42, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[42] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+43, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[43] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+44, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[44] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+45, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[45] },   
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+46, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[46] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+47, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[47] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+48, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[48] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+49, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[49] }, 
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+50, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[50] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+51, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[51] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+52, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[52] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE+53, mmi_em_profiling_decode_gdi_image_9slice, (void*)&g_mmi_em_profiling_9slice_case[53] }, 
       
    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};

mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_decoder_func_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_DECODER_FUNC;
    test_suite->test_cases = g_mmi_em_profiling_gdi_decoder_func_test_cases;
    test_suite->interval_ms = 500;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}

static GDI_RESULT mmi_em_profiling_decode_gdi_image_9slice_measurement(U16 img_id, gdi_color dst_layer_cf,S32 sw, S32 sh, mmi_em_profling_decode_image_rect rect, U8* img_ptr, U32 img_size)
{
    GDI_RESULT ret = GDI_SUCCEED;
    U32 start_time, end_time, duration;
    U8 cnt = 0;

    if(rect.w == 0 && rect.h == 0)
    {
        rect.w = sw;
        rect.h = sh;
    }

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_9SLICE_START);

    #ifdef __MTK_TARGET__
        start_time = drv_get_current_time();
    #else
        kal_get_time(&start_time);
    #endif

    while(cnt < g_mmi_em_profiling_decode_image_test_iteration)
    {
        ret = gdi_image_9slice_draw_handler(0,0,rect.x,rect.y,rect.w,rect.h,img_ptr,img_size);
        cnt++;
    }

    #ifdef __MTK_TARGET__
        end_time = drv_get_current_time();
        duration= drv_get_duration_ms(start_time);
    #else
        kal_get_time(&end_time);
        duration = end_time - start_time;
    #endif

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_9SLICE_END, img_id, dst_layer_cf, sw, sh, rect.w, rect.h, g_mmi_em_profiling_decode_image_test_iteration, duration); 
    //"[EM][GDI] 9slice image decode end, src_img is %d, dst_cf = %d, size=(%d,%d)->(%d,%d) , %d times in %d ms"

    return ret;
}

static S32 mmi_em_profiling_decode_gdi_image_9slice_speed(void *v_param)
{
    const mmi_em_profiling_decode_image_param *param = (const mmi_em_profiling_decode_image_param*)v_param;
    U16 img_id = param->img_id;
    gdi_handle dst_layer = GDI_NULL_HANDLE;
    gdi_handle base_layer = GDI_NULL_HANDLE;
    U8 *img_ptr = NULL;
    U8 *real_img_ptr = NULL;
    S32 real_img_size = 0;
    U32 real_img_type = GDI_IMAGE_TYPE_INVALID;
    S32 real_img_w, real_img_h;
    mmi_em_profling_decode_image_rect arr_test_rect[] = {prof_test_rect1,prof_test_rect2,prof_test_rect3,prof_test_rect4,prof_test_rect5};
    U8 rect_num = 5;
    U8 cnt = 0;

    if(param->dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        #ifndef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT   
            return 0;
        #endif
    }

    real_img_ptr = gdi_image_get_buf_ptr_from_id(img_id);
    gdi_image_get_dimension_id(img_id,&real_img_w,&real_img_h);
    real_img_type = gdi_image_get_type_from_id(img_id); 
    real_img_size = gdi_image_get_buf_len_from_id(img_id); 

    if(real_img_type != GDI_IMAGE_TYPE_9SLICE)
    {
        return GDI_FAILED;
    }

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case
    
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    dst_layer = mmi_em_profiling_gdi_create_layer(param->dst_layer_cf, 0, 0, g_mmi_em_profiling_decode_image_layer_w, g_mmi_em_profiling_decode_image_layer_h);
    
    gdi_layer_push_and_set_active(dst_layer);
    gdi_push_and_set_alpha_blending_source_layer(dst_layer);
    
    /* start decode and measure performance*/
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 

    gdi_image_9slice_draw_handler(0,0,0,0,real_img_w,real_img_h,real_img_ptr,real_img_size);

    gdi_image_codec_set_flag_end();
    for(cnt=0; cnt<rect_num; cnt++)
    {
        gdi_layer_clear(GDI_COLOR_GREEN);
        mmi_em_profiling_decode_gdi_image_9slice_measurement(img_id,param->dst_layer_cf,real_img_w,real_img_h,arr_test_rect[cnt],real_img_ptr,real_img_size);
    }
    
    /* decode and show original image on LCD */
    gdi_layer_clear(GDI_COLOR_GREEN);
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 
    gdi_image_9slice_draw_handler(0,0,0,0,real_img_w,real_img_h,real_img_ptr,real_img_size);
    gdi_image_codec_set_flag_end();

    gdi_layer_blt(
                base_layer,
                (gdi_handle)gdi_act_layer,
                0,
                0,
                0,
                0,
                GDI_LCD_WIDTH - 1,
                GDI_LCD_HEIGHT - 1);

    

    /* save result */
    if(param->output_filename)
    {
        mmi_em_profiling_gdi_decoder_save_act_image(param->output_filename,0,g_save_img_cnt++);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    mmi_em_profiling_gdi_free_layer(dst_layer);

    return 0;
}

static GDI_RESULT mmi_em_profiling_decode_gdi_image_ab2_measurement(U16 img_id, gdi_color dst_layer_cf,S32 sw, S32 sh, mmi_em_profling_decode_image_rect rect, U8* img_ptr, U32 img_size)
{
    GDI_RESULT ret = GDI_SUCCEED;
    U32 start_time, end_time, duration;
    U8 cnt = 0;

    if(rect.w == 0 && rect.h == 0)
    {
        rect.w = sw;
        rect.h = sh;
    }

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_AB2_START);

    #ifdef __MTK_TARGET__
        start_time = drv_get_current_time();
    #else
        kal_get_time(&start_time);
    #endif

    while(cnt < g_mmi_em_profiling_decode_image_test_iteration)
    {
        ret = gdi_image_ab2_draw_handler(0,0,rect.x,rect.y,rect.w,rect.h,img_ptr,img_size);
        cnt++;
    }

    #ifdef __MTK_TARGET__
        end_time = drv_get_current_time();
        duration= drv_get_duration_ms(start_time);
    #else
        kal_get_time(&end_time);
        duration = end_time - start_time;
    #endif

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_AB2_END, img_id, dst_layer_cf, sw, sh, rect.w, rect.h, g_mmi_em_profiling_decode_image_test_iteration, duration); 
    //"[EM][GDI] ab2 image decode end, src_img is %d, dst_cf = %d, size=(%d,%d)->(%d,%d) , %d times in %d ms"

    return ret;
}


static S32 mmi_em_profiling_decode_gdi_image_ab2_speed(void *v_param)
{
    const mmi_em_profiling_decode_image_param *param = (const mmi_em_profiling_decode_image_param*)v_param;
    U16 img_id = param->img_id;
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle dst_layer = GDI_NULL_HANDLE;
    gdi_handle base_layer = GDI_NULL_HANDLE;
    U8 *real_img_ptr = NULL;
    S32 real_img_size = 0;
    U32 real_img_type = GDI_IMAGE_TYPE_INVALID;
    S32 real_img_w, real_img_h;
    mmi_em_profling_decode_image_rect arr_test_rect[] = {prof_test_rect1,prof_test_rect2,prof_test_rect3,prof_test_rect4,prof_test_rect5};
    U8 rect_num = 5;
    U8 cnt = 0;

    if(param->dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        #ifndef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT   
            return 0;
        #endif
    }

    real_img_ptr = gdi_image_get_buf_ptr_from_id(img_id);
    ret = gdi_image_get_dimension_id(img_id,&real_img_w,&real_img_h);
    real_img_type = gdi_image_get_type_from_id(img_id); 
    real_img_size = gdi_image_get_buf_len_from_id(img_id); 

    if(real_img_type != GDI_IMAGE_TYPE_AB2)
    {
        return GDI_FAILED;
    }

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case
    
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    dst_layer = mmi_em_profiling_gdi_create_layer(param->dst_layer_cf, 0, 0, g_mmi_em_profiling_decode_image_layer_w, g_mmi_em_profiling_decode_image_layer_h);
    
    gdi_layer_push_and_set_active(dst_layer);
    gdi_push_and_set_alpha_blending_source_layer(dst_layer);
    
    /* start decode and measure performance*/
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 

    ret = gdi_image_ab2_draw_handler(0,0,0,0,real_img_w,real_img_h,real_img_ptr,real_img_size);

    gdi_image_codec_set_flag_end();
    for(cnt=0; cnt<rect_num; cnt++)
    {
        gdi_layer_clear(gdi_act_color_from_rgb(255,255,255,0));
        mmi_em_profiling_decode_gdi_image_ab2_measurement(img_id,param->dst_layer_cf,real_img_w,real_img_h,arr_test_rect[cnt],real_img_ptr,real_img_size);
    }
    
    /* decode and show original image on LCD */
    gdi_layer_clear(gdi_act_color_from_rgb(255,255,255,0));
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 
    ret = gdi_image_ab2_draw_handler(0,0,0,0,real_img_w,real_img_h,real_img_ptr,real_img_size);
    gdi_image_codec_set_flag_end();

    gdi_layer_blt(
                base_layer,
                (gdi_handle)gdi_act_layer,
                0,
                0,
                0,
                0,
                GDI_LCD_WIDTH - 1,
                GDI_LCD_HEIGHT - 1);

    

    /* save result */
    if(param->output_filename)
    {
        mmi_em_profiling_gdi_decoder_save_act_image(param->output_filename,0,g_save_img_cnt++);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    mmi_em_profiling_gdi_free_layer(dst_layer);

    return 0;
}

static GDI_RESULT mmi_em_profiling_decode_gdi_image_abm_measurement(U16 img_id, gdi_color dst_layer_cf,S32 sw, S32 sh, mmi_em_profling_decode_image_rect rect, U8* img_ptr, U32 img_size)
{
    GDI_RESULT ret = GDI_SUCCEED;
    U32 start_time, end_time, duration;
    U8 cnt = 0;

    if(rect.w == 0 && rect.h == 0)
    {
        rect.w = sw;
        rect.h = sh;
    }

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_ABM_START);

    #ifdef __MTK_TARGET__
        start_time = drv_get_current_time();
    #else
        kal_get_time(&start_time);
    #endif

    while(cnt < g_mmi_em_profiling_decode_image_test_iteration)
    {
        ret = gdi_image_abm_draw_handler(0,0,rect.x,rect.y,rect.w,rect.h,img_ptr,img_size);
        cnt++;
    }

    #ifdef __MTK_TARGET__
        end_time = drv_get_current_time();
        duration= drv_get_duration_ms(start_time);
    #else
        kal_get_time(&end_time);
        duration = end_time - start_time;
    #endif

    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_APP_EM_PROFILING_GDI_ABM_END, img_id, dst_layer_cf, sw, sh, rect.w, rect.h, g_mmi_em_profiling_decode_image_test_iteration, duration); 
    //"[EM][GDI] abm image decode end, src_img is %d, dst_cf = %d, size=(%d,%d)->(%d,%d) , %d times in %d ms"

    return ret;
}


static S32 mmi_em_profiling_decode_gdi_image_abm_speed(void *v_param)
{
    const mmi_em_profiling_decode_image_param *param = (const mmi_em_profiling_decode_image_param*)v_param;
    U16 img_id = param->img_id;
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle dst_layer = GDI_NULL_HANDLE;
    gdi_handle base_layer = GDI_NULL_HANDLE;
    U8 *real_img_ptr = NULL;
    S32 real_img_size = 0;
    U32 real_img_type = GDI_IMAGE_TYPE_INVALID;
    S32 real_img_w, real_img_h;
    mmi_em_profling_decode_image_rect arr_test_rect[] = {prof_test_rect1,prof_test_rect2,prof_test_rect3,prof_test_rect4,prof_test_rect5};
    U8 rect_num = 5;
    U8 cnt = 0;

    if(param->dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        #ifndef GDI_LAYER_PARGB6666_FLATTEN_SUPPORT   
            return 0;
        #endif
    }

    real_img_ptr = gdi_image_get_buf_ptr_from_id(img_id);
    ret = gdi_image_get_dimension_id(img_id,&real_img_w,&real_img_h);
    real_img_type = gdi_image_get_type_from_id(img_id); 
    real_img_size = gdi_image_get_buf_len_from_id(img_id); 

    if(real_img_type != GDI_IMAGE_TYPE_ABM)
    {
        return GDI_FAILED;
    }

    mmi_em_profiling_gdi_func_clean_screen(); // To separate case
    
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    dst_layer = mmi_em_profiling_gdi_create_layer(param->dst_layer_cf, 0, 0, g_mmi_em_profiling_decode_image_layer_w, g_mmi_em_profiling_decode_image_layer_h);
    
    gdi_layer_push_and_set_active(dst_layer);
    gdi_push_and_set_alpha_blending_source_layer(dst_layer);
    
    /* start decode and measure performance*/
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 

    ret = gdi_image_abm_draw_handler(0,0,0,0,real_img_w,real_img_h,real_img_ptr,real_img_size);

    gdi_image_codec_set_flag_end();
    for(cnt=0; cnt<rect_num; cnt++)
    {
        gdi_layer_clear(gdi_act_color_from_rgb(255,255,0,156)); //pink
        mmi_em_profiling_decode_gdi_image_abm_measurement(img_id,param->dst_layer_cf,real_img_w,real_img_h,arr_test_rect[cnt],real_img_ptr,real_img_size);
    }
    
    /* decode and show original image on LCD */
    gdi_layer_clear(GDI_COLOR_GRAY);
    gdi_image_codec_set_flag_begin(param->img_decode_flag); 
    ret = gdi_image_abm_draw_handler(0,0,0,0,real_img_w,real_img_h,real_img_ptr,real_img_size);
    gdi_image_codec_set_flag_end();

    gdi_layer_blt(
                base_layer,
                (gdi_handle)gdi_act_layer,
                0,
                0,
                0,
                0,
                GDI_LCD_WIDTH - 1,
                GDI_LCD_HEIGHT - 1);

    

    /* save result */
    if(param->output_filename)
    {
        mmi_em_profiling_gdi_decoder_save_act_image(param->output_filename,0,g_save_img_cnt++);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    mmi_em_profiling_gdi_free_layer(dst_layer);

    return 0;
}


static mmi_em_profiling_decode_image_param g_mmi_em_profiling_9slice_speed_case[] =
{
    { 0, GDI_COLOR_FORMAT_32_PARGB, prof_9s_test_img_1,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},
    { 1, GDI_COLOR_FORMAT_16,       prof_9s_test_img_1,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},    
    { 2, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_1,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},    

    { 3, GDI_COLOR_FORMAT_32_PARGB, prof_9s_test_img_2,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},
    { 4, GDI_COLOR_FORMAT_16,       prof_9s_test_img_2,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},    
    { 5, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_2,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},    

    { 6, GDI_COLOR_FORMAT_32_PARGB, prof_9s_test_img_3,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},
    { 7, GDI_COLOR_FORMAT_16,       prof_9s_test_img_3,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},    
    { 8, GDI_COLOR_FORMAT_PARGB6666,prof_9s_test_img_3,{0,0,0,0},NULL,NULL,prof_FORCE_9S_AB2_ALPHA_BLEND,NULL},    
        
    { -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,}
};

static mmi_em_profiling_decode_image_param g_mmi_em_profiling_ab2_speed_case[] =
{
    { 0, GDI_COLOR_FORMAT_32_PARGB, prof_ab2_test_img_1,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},
    { 1, GDI_COLOR_FORMAT_16,       prof_ab2_test_img_1,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},    
    { 2, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_1,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},    

    { 3, GDI_COLOR_FORMAT_32_PARGB, prof_ab2_test_img_2,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},
    { 4, GDI_COLOR_FORMAT_16,       prof_ab2_test_img_2,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},    
    { 5, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_2,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},    

    { 6, GDI_COLOR_FORMAT_32_PARGB, prof_ab2_test_img_3,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},
    { 7, GDI_COLOR_FORMAT_16,       prof_ab2_test_img_3,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},    
    { 8, GDI_COLOR_FORMAT_PARGB6666,prof_ab2_test_img_3,{0,0,0,0},NULL,NULL,GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND,NULL},    
        
    { -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,}
};

static mmi_em_profiling_decode_image_param g_mmi_em_profiling_abm_speed_case[] =
{
    { 0, GDI_COLOR_FORMAT_32_PARGB, prof_abm_test_img_1,{0,0,0,0},NULL,NULL,NULL,NULL},
    { 1, GDI_COLOR_FORMAT_16,       prof_abm_test_img_1,{0,0,0,0},NULL,NULL,NULL,NULL},    
    { 2, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_1,{0,0,0,0},NULL,NULL,NULL,NULL},    

    { 3, GDI_COLOR_FORMAT_32_PARGB, prof_abm_test_img_2,{0,0,0,0},NULL,NULL,NULL,NULL},
    { 4, GDI_COLOR_FORMAT_16,       prof_abm_test_img_2,{0,0,0,0},NULL,NULL,NULL,NULL},    
    { 5, GDI_COLOR_FORMAT_PARGB6666,prof_abm_test_img_2,{0,0,0,0},NULL,NULL,NULL,NULL},    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    { -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,}
};



static const mmi_em_profiling_gdi_test_case g_mmi_em_profiling_gdi_decoder_speed_test_cases[] =
{
    
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED,  mmi_em_profiling_decode_gdi_image_abm_speed, (void*)&g_mmi_em_profiling_abm_speed_case[0] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED+1,mmi_em_profiling_decode_gdi_image_abm_speed, (void*)&g_mmi_em_profiling_abm_speed_case[1] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED+2,mmi_em_profiling_decode_gdi_image_abm_speed, (void*)&g_mmi_em_profiling_abm_speed_case[2] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED+3,mmi_em_profiling_decode_gdi_image_abm_speed, (void*)&g_mmi_em_profiling_abm_speed_case[3] },
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED+4,mmi_em_profiling_decode_gdi_image_abm_speed, (void*)&g_mmi_em_profiling_abm_speed_case[4] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_ABM_SPEED+5,mmi_em_profiling_decode_gdi_image_abm_speed, (void*)&g_mmi_em_profiling_abm_speed_case[5] },
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED,  mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[0] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+1,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[1] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+2,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[2] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+3,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[3] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+4,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[4] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+5,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[5] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+6,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[6] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+7,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[7] },
    { MMI_EM_PROF_GDI_CASE_DECODER_AB2_SPEED+8,mmi_em_profiling_decode_gdi_image_ab2_speed, (void*)&g_mmi_em_profiling_ab2_speed_case[8] },    

    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED,  mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[0] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+1,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[1] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+2,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[2] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+3,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[3] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+4,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[4] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+5,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[5] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+6,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[6] },    
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+7,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[7] },
    { MMI_EM_PROF_GDI_CASE_DECODER_9SLICE_SPEED+8,mmi_em_profiling_decode_gdi_image_9slice_speed, (void*)&g_mmi_em_profiling_9slice_speed_case[8] },    

    { MMI_EM_PROF_GDI_CASE_INVALID, NULL, NULL }
};


mmi_em_profiling_gdi_test_suite* mmi_em_profiling_gdi_create_decoder_speed_suite(void)
{
    mmi_em_profiling_gdi_test_suite* test_suite;

    test_suite = (mmi_em_profiling_gdi_test_suite*)mmi_malloc(sizeof(mmi_em_profiling_gdi_test_suite));

    test_suite->id = MMI_EM_PROF_GDI_SUITE_DECODER_SPEED;
    test_suite->test_cases = g_mmi_em_profiling_gdi_decoder_speed_test_cases;
    test_suite->interval_ms = 1000;
    test_suite->finalize = mmi_em_profiling_gdi_free_suite;
    test_suite->user_data = NULL;

    return test_suite;
}


#endif
