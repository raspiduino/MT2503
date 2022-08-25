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
*   tst_appser_mm_camera.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   3rd Party Integration Development Environment
*
* Author:
* -------
* -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__


extern "C"
{
#include "GlobalResDef.h"

#include "ImageViewerGprot.h"
#include "CommonScreens.h"     
#include "SettingDefs.h"        
#include "SettingProfile.h"
#include "FileMgrGProt.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"

#include "avk_mm_camera.h"

#include "mdi_camera.h"
}

#ifndef VS_MM_BUFFER_SIZE
#define VS_MM_BUFFER_SIZE        (128)
#endif 



#define VS_SERVICE_CAMERA_MAX_TEST_CASE_COUNT 10
#define VS_CAMERA_MEMORY_SIZE (176*144*2*2)
FS_HANDLE g_vs_mm_camera_file = -1;
vs_mm_camera_context_struct g_vs_mm_camera_cntx;


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  szText      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_log(const char *szText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UINT written = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_camera_file == -1)  /* first time open file */
    {
//        g_vs_mm_camera_file = FS_Open(L"c:\\camera.txt", FS_CREATE_ALWAYS | FS_READ_WRITE);

    }
    else    /* not the first time */
    {
  //      g_vs_mm_camera_file = FS_Open(L"c:\\camera.txt", FS_READ_WRITE);

    }
    if (g_vs_mm_camera_file >= 0)   /* write */
    {
        FS_Seek(g_vs_mm_camera_file, 0, FS_FILE_END);
        FS_Write(g_vs_mm_camera_file, (void*)szText, strlen(szText), &written);
        FS_Write(g_vs_mm_camera_file, (void*)"\r\n", strlen("\r\n"), &written);
        FS_Commit(g_vs_mm_camera_file);
        FS_Close(g_vs_mm_camera_file);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_capture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_IDLE, "vs_mm_camera_capture");

    if (g_vs_mm_camera_cntx.m_bCaptured)
    {

        return;
    }
    else
    {
        gdi_layer_get_base_handle(&g_vs_mm_camera_cntx.base_layer_handle);

        gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.base_layer_handle);
        gui_set_text_color(gui_color(128, 0, 255));
        gui_move_text_cursor(5, 250);
        gui_print_text((UI_string_type) L"see image in sys_drive");
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        g_vs_mm_camera_cntx.m_bCaptured = TRUE;
    }
    switch (g_vs_mm_camera_cntx.index)
    {
        case 0:
            vs_mm_camera_001_capture_to_memory();
            break;
        case 1:
            vs_mm_camera_002_capture_to_file();
            break;
        case 2:
            vs_mm_camera_003_capture_layer_to_memory();
            break;
        case 3:
            vs_mm_camera_004_capture_layer_to_file();
            break;
        case 4:
            vs_mm_camera_005_capture_continuous_shot_with_quickview();
            break;
        case 5:
            vs_mm_camera_006_capture_continuous_shot();
            break;
        case 6:
            vs_mm_camera_007_capture_with_quickview();
            break;
        case 7:
            vs_mm_camera_008_capture_to_memory_burst_shot();
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_preview(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    S32 resized_width = 0;
    S32 resized_height = 0;
    BOOL avaliable;
    MMI_BOOL enter_ret;
    S32 gdi_create_ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avaliable = mdi_camera_is_camera_avaliable();
	AVK_LOG_FUN(mdi_camera_is_camera_avaliable,AVK_PASS);

    if (avaliable == FALSE)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_is_camera_avaliable RETURN FALSE");
        return;
    }

    ret = mdi_camera_set_camera_id(MDI_CAMERA_MAIN);
	
	AVK_LOG_FUN(mdi_camera_set_camera_id,AVK_PASS);

    enter_ret = mmi_frm_scrn_enter(
                    GRP_ID_AVK,
                    SCR_ID_VS_MM_CAMERA_011,
                    vs_mm_camera_misc_screen_exit,
                    vs_mm_camera_preview,
                    MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, NULL, NULL);

    vs_mm_misc_init_camera();

    gdi_layer_get_base_handle(&g_vs_mm_camera_cntx.base_layer_handle);

    gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.base_layer_handle);
    gui_set_text_color(gui_color(128, 0, 255));
    gui_move_text_cursor(5, 40);
    gui_print_text((UI_string_type) L"Press Up to capture");
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    resized_width = g_vs_mm_camera_cntx.width;
    resized_height = g_vs_mm_camera_cntx.height;
    g_vs_mm_camera_cntx.offset_x = ((UI_device_width - g_vs_mm_camera_cntx.width) >> 1);
    g_vs_mm_camera_cntx.offset_y = 80;

    kal_prompt_trace(
        MOD_IDLE,
        " preview layer: offset_x = %d,offset_y = %d,width = %d,height = %d",
        g_vs_mm_camera_cntx.offset_x,
        g_vs_mm_camera_cntx.offset_y,
        g_vs_mm_camera_cntx.width,
        g_vs_mm_camera_cntx.height);

    gdi_create_ret = gdi_layer_create(
                        g_vs_mm_camera_cntx.offset_x,
                        g_vs_mm_camera_cntx.offset_y,
                        g_vs_mm_camera_cntx.width,
                        g_vs_mm_camera_cntx.height,
                        &g_vs_mm_camera_cntx.play_layer_handle);

    if (gdi_create_ret == 0)
    {

        vs_mm_camera_log("gdi_create_ret==0");
    }
    else
    {

        vs_mm_camera_log("gdi_create_ret!=0");
    }

    kal_prompt_trace(MOD_IDLE, "gdi_layer_create ret = %d", gdi_create_ret);

    gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.play_layer_handle);
    gdi_layer_resize(g_vs_mm_camera_cntx.width, g_vs_mm_camera_cntx.height);
    gdi_layer_set_position(g_vs_mm_camera_cntx.offset_x, g_vs_mm_camera_cntx.offset_y);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    ret = mdi_camera_power_on(ASM_ANONYMOUS_ID);
	
	AVK_LOG_FUN(mdi_camera_power_on,AVK_PASS);

    if (ret != MDI_RES_CAMERA_SUCCEED)
    {
        vs_mm_camera_log("mdi_camera_power_on failed");
        kal_prompt_trace(MOD_IDLE, "mdi_camera_power_on, error code :%d;\n", ret);
//        DeleteScreens(SCR_ID_VS_MM_CAMERA, SCR_ID_VS_MM_CAMERA);
        return;
    }
    else
    {

        vs_mm_camera_log("mdi_camera_power_on success");
        kal_prompt_trace(MOD_IDLE, "mdi_camera_power_on success");
    }

    vs_mm_camera_preview_start();

    SetLeftSoftkeyFunction(vs_mm_camera_misc_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_camera_misc_fail, KEY_EVENT_UP);

    SetKeyHandler(vs_mm_camera_capture, KEY_UP_ARROW, KEY_EVENT_UP);

#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_get_para_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p      [?]     
 *  mdi_camera_setting_struct*(?)
 * RETURNS
 * BOOL
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
BOOL vs_mm_camera_get_para_all(mdi_camera_setting_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ev;
    U16 zoom;
    U16 banding;
    U16 effect;
    U16 wb;
    U16 brightness;
    U16 saturation;
    U16 contrast;
    U16 hue;
    U16 night;
    U16 image_qty;
    U16 flash;
    U16 iso;
    U16 ae_meter;
    U16 dsc_mode;
    U16 af_mode;
    U16 height;
    U16 width;
    U32 zoom_factor;
    U32 zoom_step;
    mdi_camera_zoom_info zoom_info;
    mdi_camera_fun_info fun_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_camera_log("camera get 0000");
    ev = mdi_camera_get_para_ev();
    if (ev != data_p->ev)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_ev, error code :%d;\n", ev);
        return FALSE;
    }
	AVK_LOG_FUN(mdi_camera_get_para_ev,AVK_PASS);

    zoom = mdi_camera_get_para_zoom();
    if (zoom != data_p->zoom)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_zoom, error code :%d;\n", zoom);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_zoom,AVK_PASS);

    banding = mdi_camera_get_para_banding();
    if (banding != data_p->banding)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_banding, error code :%d;\n", banding);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_banding,AVK_PASS);

    effect = mdi_camera_get_para_effect();
    if (effect != data_p->effect)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_effect, error code :%d;\n", effect);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_effect,AVK_PASS);

    wb = mdi_camera_get_para_wb();
    if (wb != data_p->wb)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_wb, error code :%d;\n", wb);
        return FALSE;
    }
	AVK_LOG_FUN(mdi_camera_get_para_wb,AVK_PASS);

    brightness = mdi_camera_get_para_sharpness();
    if (brightness != data_p->sharpness)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_sharpness, error code :%d;\n", brightness);
        return FALSE;
    }

	AVK_LOG_FUN(mdi_camera_get_para_sharpness,AVK_PASS);

    saturation = mdi_camera_get_para_saturation();
    if (saturation != data_p->saturation)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_saturation, error code :%d;\n", saturation);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_saturation,AVK_PASS);

    contrast = mdi_camera_get_para_contrast();
    if (contrast != data_p->contrast)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_contrast, error code :%d;\n", contrast);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_contrast,AVK_PASS);

    hue = mdi_camera_get_para_hue();
    if (hue != data_p->hue)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_hue, error code :%d;\n", hue);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_hue,AVK_PASS);

    night = mdi_camera_get_para_night();
	
	AVK_LOG_FUN(mdi_camera_get_para_night,AVK_PASS);

    image_qty = mdi_camera_get_para_image_qty();
    if (image_qty != data_p->image_qty)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_image_qty, error code :%d;\n", image_qty);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_image_qty,AVK_PASS);

    mdi_camera_get_para_image_size(&width, &height);
    if (width != data_p->image_width || height != data_p->image_height)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_image_size, height :%d width :%d\n", height, width);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_image_size,AVK_PASS);

    flash = mdi_camera_get_para_flash();
    if (flash != data_p->flash)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_flash, error code :%d;\n", flash);
        return FALSE;
    }
	AVK_LOG_FUN(mdi_camera_get_para_flash,AVK_PASS);

    iso = mdi_camera_get_para_iso();
    if (iso != data_p->iso)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_iso, error code :%d;\n", iso);
        return FALSE;
    }
	
	AVK_LOG_FUN(mdi_camera_get_para_iso,AVK_PASS);

    ae_meter = mdi_camera_get_para_ae_meter();
    if (ae_meter != data_p->ae_meter)
    {
        kal_prompt_trace(MOD_IDLE, "mdi_camera_get_para_ae_meter, error code :%d;\n", ae_meter);
        return FALSE;
    }
	AVK_LOG_FUN(mdi_camera_get_para_ae_meter,AVK_PASS);

    vs_mm_camera_log("camera get 0");
    dsc_mode = mdi_camera_get_para_dsc_mode();
	
	AVK_LOG_FUN(mdi_camera_get_para_dsc_mode,AVK_PASS);

    vs_mm_camera_log("camera get 1");
    af_mode = mdi_camera_get_para_af_mode();
    vs_mm_camera_log("camera get 2");
	
	AVK_LOG_FUN(mdi_camera_get_para_af_mode,AVK_PASS);

    mdi_camera_update_para_ev(ev);
	AVK_LOG_FUN(mdi_camera_update_para_ev,AVK_PASS);

    vs_mm_camera_log("camera get 3");
    mdi_camera_update_para_zoom(zoom);
	AVK_LOG_FUN(mdi_camera_update_para_zoom,AVK_PASS);

    vs_mm_camera_log("camera get 4");
    mdi_camera_update_para_banding(banding);	
	AVK_LOG_FUN(mdi_camera_update_para_banding,AVK_PASS);

    vs_mm_camera_log("camera get 5");
    mdi_camera_update_para_effect(effect);
	AVK_LOG_FUN(mdi_camera_update_para_effect,AVK_PASS);

    vs_mm_camera_log("camera get 6");
    mdi_camera_update_para_wb(wb);
	AVK_LOG_FUN(mdi_camera_update_para_wb,AVK_PASS);

    vs_mm_camera_log("camera get 7");
    mdi_camera_update_para_sharpness(brightness);
	AVK_LOG_FUN(mdi_camera_update_para_sharpness,AVK_PASS);

    vs_mm_camera_log("camera get 8");
    mdi_camera_update_para_saturation(saturation);
    vs_mm_camera_log("camera get 9");
	
	AVK_LOG_FUN(mdi_camera_update_para_saturation,AVK_PASS);

    mdi_camera_update_para_contrast(contrast);
    vs_mm_camera_log("camera get 10");
	
	AVK_LOG_FUN(mdi_camera_update_para_contrast,AVK_PASS);

    mdi_camera_update_para_hue(hue);
	
	AVK_LOG_FUN(mdi_camera_update_para_hue,AVK_PASS);

    vs_mm_camera_log("camera get 11");
    mdi_camera_update_para_night(night);
	
	AVK_LOG_FUN(mdi_camera_update_para_night,AVK_PASS);

    vs_mm_camera_log("camera get 12");
    mdi_camera_update_para_image_qty(image_qty);
	
	AVK_LOG_FUN(mdi_camera_update_para_image_qty,AVK_PASS);

    vs_mm_camera_log("camera get 13");
    mdi_camera_update_para_image_size(width, height);
	
	AVK_LOG_FUN(mdi_camera_update_para_image_size,AVK_PASS);

    vs_mm_camera_log("camera get 14");
    mdi_camera_update_para_flash(flash);
	AVK_LOG_FUN(mdi_camera_update_para_flash,AVK_PASS);

    vs_mm_camera_log("camera get 15");
    mdi_camera_update_para_iso(iso);
	AVK_LOG_FUN(mdi_camera_update_para_iso,AVK_PASS);

    vs_mm_camera_log("camera get 16");
    mdi_camera_update_para_ae_meter(ae_meter);
	
	AVK_LOG_FUN(mdi_camera_update_para_ae_meter,AVK_PASS);


    mdi_camera_get_max_zoom_factor(176, 144);
    vs_mm_camera_log("camera get 20");
	
	AVK_LOG_FUN(mdi_camera_get_max_zoom_factor,AVK_PASS);



    vs_mm_camera_log("camera get 21");

    mdi_camera_flash_setting(FALSE);
	
	AVK_LOG_FUN(mdi_camera_flash_setting,AVK_PASS);
    vs_mm_camera_log("camera get 22");

    mdi_camera_start_fast_zoom(FALSE, (U8) 10, 1, 1);
	
	AVK_LOG_FUN(mdi_camera_start_fast_zoom,AVK_PASS);
    vs_mm_camera_log("camera get 23");

    mdi_camera_stop_fast_zoom();
    vs_mm_camera_log("camera get 24");
	
	AVK_LOG_FUN(mdi_camera_stop_fast_zoom,AVK_PASS);

    mdi_camera_get_fast_zoom_factor(&zoom_factor);
    vs_mm_camera_log("camera get 25");
	
	AVK_LOG_FUN(mdi_camera_get_fast_zoom_factor,AVK_PASS);

    mdi_camera_get_fast_zoom_step(&zoom_step);
    vs_mm_camera_log("camera get 26");
	
	AVK_LOG_FUN(mdi_camera_get_fast_zoom_step,AVK_PASS);



    mdi_camera_set_camera_id(MDI_CAMERA_MAIN);
    vs_mm_camera_log("camera get 29");
	
	AVK_LOG_FUN(mdi_camera_set_camera_id,AVK_PASS);

    mdi_camera_query_zoom_info(&zoom_info);
    vs_mm_camera_log("camera get 30");
	
	AVK_LOG_FUN(mdi_camera_query_zoom_info,AVK_PASS);

    vs_mm_camera_log("camera get 31");

    mdi_camera_update_para_scene_mode(MDI_CAMERA_SCENE_MODE_AUTO);
	
	AVK_LOG_FUN(mdi_camera_update_para_scene_mode,AVK_PASS);

    vs_mm_camera_log("camera get 32"); 
    return TRUE;
}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */

/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_alloc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_alloc_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_preview_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_preview_start(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    MDI_RESULT ret;
    U32 blt_layer = 0;
    U32 pre_layer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);

    mdi_camera_load_default_setting(&camera_setting_data);
	
	AVK_LOG_FUN(mdi_camera_load_default_setting,AVK_PASS);

    camera_setting_data.preview_width = g_vs_mm_camera_cntx.width;
    camera_setting_data.preview_height = g_vs_mm_camera_cntx.height;
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.xenon_flash_status_callback = NULL;

    camera_setting_data.image_qty = g_vs_mm_camera_cntx.para_qty;
    camera_setting_data.ev = g_vs_mm_camera_cntx.para_ev;
    camera_setting_data.zoom = g_vs_mm_camera_cntx.para_zoom;
    camera_setting_data.image_width = g_vs_mm_camera_cntx.image_height;
    camera_setting_data.image_height = g_vs_mm_camera_cntx.image_width;

    blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;

    pre_layer = GDI_LAYER_ENABLE_LAYER_1;

    camera_preview_data.preview_layer_handle = g_vs_mm_camera_cntx.play_layer_handle;
    camera_preview_data.blt_layer_flag = blt_layer;
    camera_preview_data.preview_layer_flag = pre_layer;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
    camera_preview_data.is_tvout = FALSE;

    ret = mdi_camera_preview_start(&camera_preview_data, &camera_setting_data, NULL);
	
	AVK_LOG_FUN(mdi_camera_preview_start,AVK_PASS);

    if (ret != MDI_RES_CAMERA_SUCCEED)
    {

        vs_mm_camera_log("mdi_camera_preview_start 0");
        kal_prompt_trace(MOD_IDLE, "mdi_camera_preview_start, error code :%d;\n", ret);
//        DeleteScreens(SCR_ID_VS_MM_CAMERA, SCR_ID_VS_MM_CAMERA);
    }
    else
    {
        vs_mm_camera_log("mdi_camera_preview_start 1");
    }

    if (FALSE == vs_mm_camera_get_para_all(&camera_setting_data))
    {

        vs_mm_camera_log("vs_mm_camera_get_para_all 0");
        kal_prompt_trace(MOD_IDLE, "vs_mm_camera_get_para_all\n");
        vs_mm_camera_misc_screen_exit();
//        DeleteScreens(SCR_ID_VS_MM_CAMERA, SCR_ID_VS_MM_CAMERA);
    }
    else
    {
        vs_mm_camera_log("vs_mm_camera_get_para_all 1");
    }

#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__
    applib_mem_ap_register(APPLIB_MEM_AP_ID_VS_TEST, STR_GLOBAL_1, IMG_GLOBAL_L1, vs_mm_camera_alloc_callback);
    g_vs_mm_camera_cntx.m_pBurstShortMemoryPool =
        (kal_char*) applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VS_TEST, VS_CAMERA_MEMORY_SIZE);
    ASSERT(NULL != g_vs_mm_camera_cntx.m_pBurstShortMemoryPool);
#endif

#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_001_capture_to_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_001_capture_to_memory(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    WCHAR pp1[] = { 'z', ':', '\\', '\\', '1', '.', 'j', 'p', 'g', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    if (letter >= 'a' && letter <= 'z')
    {
        pp1[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp1[0] = L'A' + (char)letter - 'A';
    }

    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);

    ret = mdi_camera_capture_to_memory(
            &g_vs_mm_camera_cntx.capture_buf_ptr,
            &g_vs_mm_camera_cntx.capture_size,
            (S8*) pp1);
	
	AVK_LOG_FUN(mdi_camera_capture_to_memory,AVK_PASS);

    kal_prompt_trace(MOD_IDLE, "001 mdi_camera_capture_to_memory, ret = %d", ret);

    if (ret != MDI_RES_CAMERA_SUCCEED)
    {
//        vs_tfw_trace_result(L"vs_mm_camera_001", MMI_TRUE, 0, VS_TA_MM_CAMERA);
//        vs_tfw_finish_case_extern(VS_MM_CAMERA_001, SCR_ID_VS_MM_CAMERA);
        return;
    }

    ret = mdi_camera_save_captured_image();
    kal_prompt_trace(MOD_IDLE, "001 mdi_camera_save_captured_image, ret = %d", ret);

    if (ret != MDI_RES_CAMERA_SUCCEED)
    {
//        vs_tfw_trace_result(L"vs_mm_camera_001", MMI_TRUE, 0, VS_TA_MM_CAMERA);
//        vs_tfw_finish_case_extern(VS_MM_CAMERA_001, SCR_ID_VS_MM_CAMERA);
        kal_prompt_trace(MOD_IDLE, "mdi_camera_save_captured_image, error code :%d;\n", ret);
        return;
    }
#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_002_capture_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_002_capture_to_file(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    WCHAR pp2[] = { 'z', ':', '\\', '\\', '2', '.', 'j', 'p', 'g', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    if (letter >= 'a' && letter <= 'z')
    {
        pp2[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp2[0] = L'A' + (char)letter - 'A';
    }

    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);
    if (mdi_camera_is_ready_to_capture())
    {
        ret = mdi_camera_capture_to_file((PS8) pp2, FALSE);
        kal_prompt_trace(MOD_IDLE, "002 mdi_camera_capture_to_file ret = %d", ret);

        ret = mdi_camera_save_captured_image();
        kal_prompt_trace(MOD_IDLE, "002 mdi_camera_save_captured_image, ret = %d", ret);
    }
    else
    {
        kal_prompt_trace(MOD_IDLE, "camera is not ready to capture");

    }

	
	AVK_LOG_FUN(mdi_camera_is_ready_to_capture,AVK_PASS);
	AVK_LOG_FUN(mdi_camera_capture_to_file,AVK_PASS);
	AVK_LOG_FUN(mdi_camera_save_captured_image,AVK_PASS);
#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_003_capture_layer_to_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_003_capture_layer_to_memory(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    WCHAR pp3[] = { 'z', ':', '\\', '\\', '3', '.', 'j', 'p', 'g', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    if (letter >= 'a' && letter <= 'z')
    {
        pp3[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp3[0] = L'A' + (char)letter - 'A';
    }

    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);



    mdi_camera_capture((S8*) pp3);
	
	AVK_LOG_FUN(mdi_camera_capture,AVK_PASS);
    kal_prompt_trace(MOD_IDLE, "mdi_camera_capture ret = %d", ret);

    ret = mdi_camera_save_captured_image();
    kal_prompt_trace(MOD_IDLE, "003 mdi_camera_save_captured_image, ret = %d", ret);

#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_004_capture_layer_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_004_capture_layer_to_file(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    WCHAR pp4[] = { 'z', ':', '\\', '\\', '4', '.', 'j', 'p', 'g', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    if (letter >= 'a' && letter <= 'z')
    {
        pp4[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp4[0] = L'A' + (char)letter - 'A';
    }

    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);

    ret = mdi_camera_capture_layer_to_file(
            GDI_LAYER_ENABLE_LAYER_1,
            (PS8) pp4,
            g_vs_mm_camera_cntx.offset_x,
            g_vs_mm_camera_cntx.offset_y,
            g_vs_mm_camera_cntx.image_width,
            g_vs_mm_camera_cntx.image_height,
            0);
	
	AVK_LOG_FUN(mdi_camera_capture_layer_to_file,AVK_PASS);

    kal_prompt_trace(MOD_IDLE, "mdi_camera_capture_layer_to_file ret = %d", ret);

    // #if !MDI_CAMERA_MT6238_SERIES
    ret = mdi_camera_save_captured_image();
    kal_prompt_trace(MOD_IDLE, "004 mdi_camera_save_captured_image, ret = %d", ret);
    // #endif
#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_005_capture_continuous_shot_with_quickview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_005_capture_continuous_shot_with_quickview(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *capimg_ptr;
    U32 captured_size;
    U8 *dst_p;
    S32 width, height;

    S32 buf_size;
    S32 offset_x, offset_y;

    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    WCHAR pp5[] = { 'z', ':', '\\', '\\', '5', '.', 'j', 'p', 'g', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    if (letter >= 'a' && letter <= 'z')
    {
        pp5[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp5[0] = L'A' + (char)letter - 'A';
    }
    gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.play_layer_handle);
    gdi_layer_get_dimension(&width, &height);
    buf_size = (width * height * gdi_layer_get_bit_per_pixel()) >> 3;
    gdi_layer_get_buffer_ptr(&dst_p);
    gdi_layer_pop_and_restore_active();

    ret = mdi_camera_capture_continuous_shot_with_quickview(
            (U32) dst_p,
            (U32) buf_size,
            g_vs_mm_camera_cntx.image_width,
            g_vs_mm_camera_cntx.image_height,
            (S8*) pp5);
	
	AVK_LOG_FUN(mdi_camera_capture_continuous_shot_with_quickview,AVK_PASS);

    kal_prompt_trace(MOD_IDLE, "mdi_camera_capture_005 ret = %d", ret);
    ret = mdi_camera_save_captured_image();
    kal_prompt_trace(MOD_IDLE, "005 mdi_camera_save_captured_image, ret = %d", ret);

#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_006_capture_continuous_shot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_006_capture_continuous_shot(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *capimg_ptr;
    U32 captured_size;
    U8 *dst_p;
    S32 width, height;

    S32 buf_size;
    S32 offset_x, offset_y;

    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    WCHAR pp6[] = { 'z', ':', '\\', '\\', '6', '.', 'j', 'p', 'g', '\0' };
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (letter >= 'a' && letter <= 'z')
    {
        pp6[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp6[0] = L'A' + (char)letter - 'A';
    }
    gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, g_vs_mm_camera_cntx.play_layer_handle, 0, 0);

    ret = mdi_camera_capture_continuous_shot((S8*) pp6);
	
	AVK_LOG_FUN(mdi_camera_capture_continuous_shot,AVK_PASS);
    kal_prompt_trace(MOD_IDLE, "mdi_camera_capture_006 ret = %d", ret);
    ret = mdi_camera_save_captured_image();
    kal_prompt_trace(MOD_IDLE, "006 mdi_camera_save_captured_image, ret = %d", ret);
#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_007_capture_with_quickview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_007_capture_with_quickview(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    U8 *dst_p;
    S32 width, height, buf_size;
    S32 offset_x, offset_y;

    WCHAR pp7[] = { 'z', ':', '\\', '\\', '7', '.', 'j', 'p', 'g', '\0' };
    int letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (letter >= 'a' && letter <= 'z')
    {
        pp7[0] = L'a' + (char)letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        pp7[0] = L'A' + (char)letter - 'A';
    }

    if (mdi_camera_is_ready_to_capture())
    {
        gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.play_layer_handle);
        gdi_layer_resize(g_vs_mm_camera_cntx.image_width, g_vs_mm_camera_cntx.image_height);
        gdi_layer_set_position(g_vs_mm_camera_cntx.offset_x, g_vs_mm_camera_cntx.offset_y);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.base_layer_handle);
        gdi_layer_get_dimension(&width, &height);
        buf_size = (width * height * gdi_layer_get_bit_per_pixel()) >> 3;
        gdi_layer_get_buffer_ptr(&dst_p);
        gdi_layer_pop_and_restore_active();

        ret = mdi_camera_capture_with_quickview(
                (U32) dst_p,
                ((g_vs_mm_camera_cntx.image_width * g_vs_mm_camera_cntx.image_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3),
                g_vs_mm_camera_cntx.image_width,
                g_vs_mm_camera_cntx.image_height,
                (S8*) pp7);

        kal_prompt_trace(MOD_IDLE, "007 mdi_camera_capture, ret = %d", ret);

        ret = mdi_camera_encode_capture_image(&g_vs_mm_camera_cntx.capture_buf_ptr, &g_vs_mm_camera_cntx.capture_size);
        kal_prompt_trace(MOD_IDLE, "mdi_camera_encode_capture_image ret = %d", ret);

    }
    else
    {
        kal_prompt_trace(MOD_IDLE, "007 is not ready to capture");

    }
	
	AVK_LOG_FUN(mdi_camera_capture_with_quickview,AVK_PASS);
	AVK_LOG_FUN(mdi_camera_encode_capture_image,AVK_PASS);
#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_008_burstshot_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret                 [IN]        
 *  captured_count      [IN]        
 *  user_data           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_mm_camera_008_burstshot_callback(MDI_RESULT ret, U16 captured_count, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_IDLE, "burst cb: ret = %d,count = %d", ret, captured_count);
    if (captured_count == 1)
    {
        mdi_camera_stop_non_block_burst_capture();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_008_capture_to_memory_burst_shot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_008_capture_to_memory_burst_shot(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__    
    ret = mdi_camera_capture_to_memory_burst_shot(
            2,
            &g_vs_mm_camera_cntx.m_jpegs_struct,
            vs_mm_camera_008_burstshot_callback,
            (U8*) g_vs_mm_camera_cntx.m_pBurstShortMemoryPool,
            VS_CAMERA_MEMORY_SIZE,
            NULL);
#endif
	
	AVK_LOG_FUN(mdi_camera_capture_to_memory_burst_shot,AVK_PASS);
	AVK_LOG_FUN(mdi_camera_stop_non_block_burst_capture,AVK_PASS);
#else /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_update_ev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_update_ev(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_camera_cntx.para_ev == MDI_CAMERA_EV_N4)
    {
        g_vs_mm_camera_cntx.para_ev = MDI_CAMERA_EV_0;
    }
    else
    {
        g_vs_mm_camera_cntx.para_ev = MDI_CAMERA_EV_N4;
    }
    kal_prompt_trace(MOD_IDLE, "mdi_camera_update_para_ev, ev value :%d;\n", g_vs_mm_camera_cntx.para_ev);
    mdi_camera_update_para_ev(g_vs_mm_camera_cntx.para_ev);
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_update_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_update_zoom(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MT6238
    if (g_vs_mm_camera_cntx.para_zoom == 10)
    {
    #ifdef __MMI_CAMCORDER__
    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
        kal_prompt_trace(MOD_IDLE, "__CAMERA_FEATURE_IMAGE_SIZE_SS__;\n");
        g_vs_mm_camera_cntx.para_zoom = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
        kal_prompt_trace(MOD_IDLE, "__CAMERA_FEATURE_IMAGE_SIZE_S__;\n");
        g_vs_mm_camera_cntx.para_zoom = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
        kal_prompt_trace(MOD_IDLE, "__CAMERA_FEATURE_IMAGE_SIZE_M__;\n");
        g_vs_mm_camera_cntx.para_zoom = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
        kal_prompt_trace(MOD_IDLE, "__CAMERA_FEATURE_IMAGE_SIZE_L__;\n");
        g_vs_mm_camera_cntx.para_zoom = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
        kal_prompt_trace(MOD_IDLE, "__CAMERA_FEATURE_IMAGE_SIZE_LL__;\n");
        g_vs_mm_camera_cntx.para_zoom = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 
    #else /* __MMI_CAMCORDER__ */ 
        kal_prompt_trace(MOD_IDLE, "__CAMERA_FEATURE_IMAGE_SIZE_M__;\n");
        g_vs_mm_camera_cntx.para_zoom = 30;
    #endif /* __MMI_CAMCORDER__ */ 
    }
    else
    {
        g_vs_mm_camera_cntx.para_zoom = 10;
    }
#else /* MT6238 */ 
    if (g_vs_mm_camera_cntx.para_zoom < 5)
    {
        g_vs_mm_camera_cntx.para_zoom++;
    }
    else
    {
        g_vs_mm_camera_cntx.para_zoom = 0;
    }
#endif /* MT6238 */ 
    kal_prompt_trace(MOD_IDLE, "mdi_video_rec_update_para_zoom, zoom value :%d;\n", g_vs_mm_camera_cntx.para_zoom);
    mdi_camera_update_para_zoom(g_vs_mm_camera_cntx.para_zoom);
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_update_image_qty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_update_image_qty(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_camera_cntx.para_qty == MDI_CAMERA_JPG_QTY_FINE)
    {
        g_vs_mm_camera_cntx.para_qty = MDI_CAMERA_JPG_QTY_NORMAL;
    }
    else
    {
        g_vs_mm_camera_cntx.para_qty = MDI_CAMERA_JPG_QTY_FINE;
    }
    kal_prompt_trace(MOD_IDLE, "mdi_camera_update_para_image_qty, qty value :%d;\n", g_vs_mm_camera_cntx.para_qty);
    mdi_camera_update_para_image_qty(g_vs_mm_camera_cntx.para_qty);
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_update_image_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_update_image_size(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_update_para_image_size(320, 240);
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_misc_get_image_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     U16 *file
 *  file        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_misc_get_image_file_path(U16 *path, U16 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileBuf[VS_MM_BUFFER_SIZE];
    int file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fileBuf, 0, VS_MM_BUFFER_SIZE);
    memset(path, 0, VS_MM_BUFFER_SIZE * 2);
    sprintf(fileBuf, "%c:\\", FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE));
    mmi_asc_to_wcs((U16*) path, (S8*) fileBuf);
    mmi_wcscat((U16*) path, (U16*) L"Photos\\");
    file_handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {
        /* already exist , 0 measn success in FS */
        FS_Close(file_handle);
    }
    else
    {
        FS_CreateDir((PU16) path);
    }

    mmi_wcscat((U16*) path, (U16*) file);
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_misc_screen_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_misc_screen_exit(void)
{
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 ret;

    ret = mdi_camera_preview_stop();
    kal_prompt_trace(MOD_IDLE, "mdi_camera_preview_stop ret = %d", ret);
    ret = mdi_camera_power_off();
    kal_prompt_trace(MOD_IDLE, "mdi_camera_power_off ret = %d", ret);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    if (g_vs_mm_camera_cntx.play_layer_handle != 0)
    {
        gdi_layer_free(g_vs_mm_camera_cntx.play_layer_handle);
        g_vs_mm_camera_cntx.play_layer_handle = 0;

        gdi_layer_push_and_set_active(g_vs_mm_camera_cntx.base_layer_handle);
        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_blt_layer(g_vs_mm_camera_cntx.base_layer_handle, 0, 0, 0);
    }

#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_misc_pass
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_misc_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_IDLE, "camera success index =%d", g_vs_mm_camera_cntx.index);
    
#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__    
    applib_mem_ap_free(g_vs_mm_camera_cntx.m_pBurstShortMemoryPool);
#endif

    switch (g_vs_mm_camera_cntx.index)
    {
        case 0:
            //vs_tfw_trace_result(L"vs_mm_camera_001", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_001, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 1:
            //vs_tfw_trace_result(L"vs_mm_camera_002", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_002, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 2:
            //vs_tfw_trace_result(L"vs_mm_camera_003", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_003, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 3:
            //vs_tfw_trace_result(L"vs_mm_camera_004", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_004, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 4:
            //vs_tfw_trace_result(L"vs_mm_camera_005", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_005, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 5:
            //vs_tfw_trace_result(L"vs_mm_camera_006", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_006, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 6:
            //vs_tfw_trace_result(L"vs_mm_camera_007", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_007, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 7:
            //vs_tfw_trace_result(L"vs_mm_camera_008", MMI_TRUE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_008, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;

        default:
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_misc_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_misc_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_IDLE, "camera fail index =%d", g_vs_mm_camera_cntx.index);

    switch (g_vs_mm_camera_cntx.index)
    {
        case 0:
            //vs_tfw_trace_result(L"vs_mm_camera_001", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_001, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 1:
            //vs_tfw_trace_result(L"vs_mm_camera_002", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_002, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 2:
            //vs_tfw_trace_result(L"vs_mm_camera_003", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_003, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 3:
            //vs_tfw_trace_result(L"vs_mm_camera_004", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_004, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 4:
            //vs_tfw_trace_result(L"vs_mm_camera_005", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_005, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 5:
            //vs_tfw_trace_result(L"vs_mm_camera_006", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_006, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 6:
            //vs_tfw_trace_result(L"vs_mm_camera_007", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_007, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        case 7:
            //vs_tfw_trace_result(L"vs_mm_camera_008", MMI_FALSE, 0, VS_TA_MM_CAMERA);
            //vs_tfw_finish_case_extern(VS_MM_CAMERA_008, SCR_ID_VS_MM_CAMERA);
		GoBackHistory();
		AVK_ASYN_DONE();
            break;
        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_camera_misc_manual
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_camera_misc_manual(void)
{

}


/*****************************************************************************
 * FUNCTION
 *  vs_mm_misc_init_camera
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_mm_misc_init_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_camera_cntx.play_layer_handle = 0;
    g_vs_mm_camera_cntx.width = 176;
    g_vs_mm_camera_cntx.height = 144;
    g_vs_mm_camera_cntx.image_width = 176;
    g_vs_mm_camera_cntx.image_height = 144;
#ifdef MT6238
    g_vs_mm_camera_cntx.para_zoom = 0;
#else 
    g_vs_mm_camera_cntx.para_zoom = 10;
#endif 
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    g_vs_mm_camera_cntx.para_qty = MDI_CAMERA_JPG_QTY_NORMAL;
    g_vs_mm_camera_cntx.para_ev = MDI_CAMERA_EV_0;
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 

    g_vs_mm_camera_cntx.m_bCaptured = FALSE;
    g_vs_mm_camera_cntx.m_pBurstShortMemoryPool = NULL;

}







AVK_ADD_ITEM(AVK_CAMERA_ITEM_001,L"camera 001",AVK_MM_CAMERA);
AVK_ADD_ITEM(AVK_CAMERA_ITEM_002,L"camera 002",AVK_MM_CAMERA);
AVK_ADD_ITEM(AVK_CAMERA_ITEM_003,L"camera 003",AVK_MM_CAMERA);
AVK_ADD_ITEM(AVK_CAMERA_ITEM_004,L"camera 004",AVK_MM_CAMERA);
AVK_ADD_ITEM(AVK_CAMERA_ITEM_005,L"camera 005",AVK_MM_CAMERA);
AVK_ADD_ITEM(AVK_CAMERA_ITEM_006,L"camera 006",AVK_MM_CAMERA);
AVK_ADD_ITEM(AVK_CAMERA_ITEM_007,L"camera 007",AVK_MM_CAMERA);
#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__
AVK_ADD_ITEM(AVK_CAMERA_ITEM_008,L"camera 008",AVK_MM_CAMERA);
#endif

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL1,AVK_CAMERA_ITEM_001)
{    
    g_vs_mm_camera_cntx.index = 0;
	vs_mm_camera_preview();


}

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL2,AVK_CAMERA_ITEM_002)
{    

	g_vs_mm_camera_cntx.index = 1;
	
	vs_mm_camera_preview();

}

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL3,AVK_CAMERA_ITEM_003)
{    
    g_vs_mm_camera_cntx.index = 2;
	vs_mm_camera_preview();


}

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL4,AVK_CAMERA_ITEM_004)
{    

	g_vs_mm_camera_cntx.index = 3;
	vs_mm_camera_preview();

}

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL5,AVK_CAMERA_ITEM_005)
{    

	g_vs_mm_camera_cntx.index = 4;
	vs_mm_camera_preview();

}

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL6,AVK_CAMERA_ITEM_006)
{    

	g_vs_mm_camera_cntx.index = 5;
	vs_mm_camera_preview();

}

AVK_MANUAL_CASE(AVK_CAMERA_MANUAL7,AVK_CAMERA_ITEM_007)
{    

	g_vs_mm_camera_cntx.index = 6;
	vs_mm_camera_preview();
}

#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__
AVK_MANUAL_CASE(AVK_CAMERA_MANUAL8,AVK_CAMERA_ITEM_008)
{    

	g_vs_mm_camera_cntx.index = 7;
	vs_mm_camera_preview();

}
#endif






#endif /* __MAUI_SDK_TEST__ */ 


