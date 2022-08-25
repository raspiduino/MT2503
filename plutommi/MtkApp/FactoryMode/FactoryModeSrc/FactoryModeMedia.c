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
 * FactoryModeMedia.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode Media, it include camera preview, MATV
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
 ********************************************************************************/
     
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */
     
#if defined(__MMI_AP_DCM_FM__)
#pragma arm section rodata = "DYNAMIC_CODE_FM_RODATA" , code = "DYNAMIC_CODE_FM_ROCODE"
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_FM_RODATA" , code = "DYNAMIC_CODE_COSMOS_FM_ROCODE"
#endif /* #ifdef __MMI_AP_DCM_FM__ */ 


#include "MMI_features.h"
	 
#ifdef __MMI_FACTORY_MODE__
/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "ps_public_struct.h"
#include "stack_config.h"
#include "mmi_frm_input_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"

#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "nvram_defs.h"
#include "gui.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_msg_struct.h"
#include "AlarmFrameworkProt.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_touch_screen.h"
#include "gui_config.h"
#include "SensorSrvGport.h"


#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "PixcomFontEngine.h"
#include "resource_audio.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"
#include "EngineerModeUtil.h"
#include "EngineerModeGprot.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "fmt_struct.h"

#include "mmi_rp_srv_gpio_def.h"
#include "wgui_categories.h"


#include "dcl.h"


#if defined __MMI_FM_CAMERA_PREVIEW__
#include "lcd_if.h"
#include "lcd_sw_rnd.h" /* LCD layer enable flag */
#include "mdi_datatype.h"
#include "med_api.h"    /* media task camera module */
#include "MMI_features_camera.h"
#include "resource_camera_skins.h"
#include "mdi_camera.h"
#include "CameraApp.h"

#if defined(ISP_SUPPORT)
#include "image_sensor.h"
#endif 
#endif /* __MMI_FM_CAMERA_PREVIEW__ */ 

#include "init.h"
#include "device.h"
#include "custom_em.h"

#include "custom_equipment.h"
//#include "custom_hw_default.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "lcd_sw_inc.h"
#include "resource_verno.h"

#ifdef __MTK_TARGET__
#include "l1audio.h"
#else 
#define L1SP_Tones kal_uint16
#endif 

#include "datetimetype.h"
#include "app_datetime.h"

#include "adc_channel.h"
#include "ShutdownSrvGprot.h"

#include "mmi_rp_app_factorymode_def.h"
#include "MenuCuiGprot.h"
#include "FactoryModeGProt.h"

#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif 

#include "mtv_comm.h"

#include "FileMgrSrvGProt.h"


#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"


/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/

/***************************************************************************** 
* global val / function
*****************************************************************************/
U16 g_cameraStartFlag = 0;
extern MMI_ID g_fm_gourp_id;

extern mmi_fm_item_cntxt_struct *g_fm_contxt;

/* -----------Camera ------------- */
#if defined(__MMI_FM_CAMERA_PREVIEW__)
extern camera_context_struct g_camera_cntx;
extern const U8 camera_ev_command_map[];
extern const U8 camera_zoom_command_map[];
extern const U8 camera_effect_command_map[];
extern const U8 camera_wb_command_map[];
extern const U8 camera_banding_command_map[];
extern const U8 camera_jpg_size_command_map[];
extern const U8 camera_image_qty_command_map[];

/* extern gdi_color GDI_COLOR_BLACK; */
extern wgui_inline_item wgui_inline_items[];

extern gdi_handle wgui_base_layer;
extern gdi_handle wgui_layer_1;

#endif /* defined(__FM_CAMERA_PREVIEW__) */ 

#if defined(__MMI_FM_CAMERA_PREVIEW__)
extern void mmi_fm_camera_entry_sublcd_screen(void);
#endif 


#if defined(__MMI_FM_TC01_CAMERA_TEST__)
extern void mmi_fm_camera_test_entry_cam_test(void);
#endif


/***************************************************************************** 
* static  function
*****************************************************************************/
#if defined(__MMI_FM_CAMERA_PREVIEW__)
static void mmi_fm_camera_exit_preview_screen(void);
extern void mmi_camera_init_none_save_setting(void);
#endif
/***************************************************************************** 
* Code body
*****************************************************************************/

#define MMI_FM_ATV

#ifdef __ATV_SUPPORT__
/*****************************************************************
 **  mATV channel scan
 *****************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_highlight_atv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_atv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_common_set_left_softkey(mtv_atv_get_channel_scan_mode());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_atv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_atv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mtv_atv_get_channel_scan_mode())
    {
        mtv_atv_set_channel_scan_mode(KAL_TRUE);        
        mmi_fm_common_set_left_softkey(MMI_TRUE);
    }
    else
    {
        mtv_atv_set_channel_scan_mode(KAL_FALSE);
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    }
}
#endif /* __ATV_SUPPORT__ */

#define MMI_FM_CAMERA_PREVIEW

#if defined(__MMI_FM_CAMERA_PREVIEW__)

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_exit_preview_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_preview_stop();

 //   kal_prompt_trace(MOD_MMI,"[FM SLIM]Pass 1");

    /* shut down camera */
    mdi_camera_power_off();

//    kal_prompt_trace(MOD_MMI,"[FM SLIM]Pass 2");

	mdi_util_hw_layer_switch_to_sw_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

#if defined(__DIRECT_SENSOR_SUPPORT__)
    gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
#endif

    /* set blt base layer only */
    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);

 //   kal_prompt_trace(MOD_MMI,"[FM SLIM]Pass 3");

    /* resume LCD patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);

//    kal_prompt_trace(MOD_MMI,"[FM SLIM]Pass 4");

    /* let MMI can sleep */
    srv_backlight_turn_off();

//    kal_prompt_trace(MOD_MMI,"[FM SLIM]Pass 5");

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    GoBackSubLCDHistory();
#endif 
 //   kal_prompt_trace(MOD_MMI,"[FM SLIM]Pass 6");

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_close_camera
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_close_camera(void)
{
    if(1 == g_cameraStartFlag)
    {
	    mmi_fm_camera_exit_preview_screen();
        //mmi_frm_scrn_close_active_id();
        mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_CAMERA);
        g_cameraStartFlag = 0;
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_entry_preview_screen
 * DESCRIPTION
 *  exit factory mode camera preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_camera_entry_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 *gui_buffer;
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
   
    g_cameraStartFlag = 1;
    
    mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_CAMERA);
    mmi_frm_scrn_enter
       (g_fm_gourp_id, 
        SCR_ID_FM_CAMERA, 
        NULL, 
        mmi_fm_camera_entry_preview_screen, 
        MMI_FRM_FULL_SCRN);
   
    /* entry a full screen app */
    entry_full_screen();

    /* entry sublcd */

    mmi_camera_init_none_save_setting();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    /* stop MMI sleep */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);


    /* stop LCD patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);

    /* power on and init hardware module */
    mdi_camera_power_on(0);

    /* clear background */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    gdi_layer_clear(GDI_COLOR_BLACK);

    SetKeyUpHandler( mmi_fm_close_camera, KEY_LSK);
    SetKeyUpHandler( mmi_fm_close_camera, KEY_RSK);

    mdi_camera_load_default_setting(&camera_setting_data);

    /* preview parametes */
    camera_setting_data.wb = camera_wb_command_map[g_camera_cntx.setting.wb];
    camera_setting_data.ev = camera_ev_command_map[g_camera_cntx.setting.ev];
    camera_setting_data.banding = camera_banding_command_map[g_camera_cntx.setting.banding];
    //camera_setting_data.night = g_camera_cntx.setting.night;

    /* default effect */
    camera_setting_data.effect = camera_effect_command_map[g_camera_cntx.setting.effect];

    camera_setting_data.preview_width = CAMERA_FACTORY_PREVIEW_WIDTH;
    camera_setting_data.preview_height = CAMERA_FACTORY_PREVIEW_HEIGHT;

    /* capture parameters - not used */
    camera_setting_data.image_qty = camera_image_qty_command_map[g_camera_cntx.setting.image_qty];
#if defined(__DIRECT_SENSOR_SUPPORT__)
    gdi_layer_resize(camera_setting_data.preview_width,camera_setting_data.preview_height);

    camera_setting_data.image_width = CAMERA_FACTORY_IMAGESIZE_WIDTH;
    camera_setting_data.image_height = CAMERA_FACTORY_IMAGESIZE_HEIGHT;
#else
    camera_setting_data.image_width = g_camera_cntx.image_width;
    camera_setting_data.image_height = g_camera_cntx.image_height;
#endif
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
   // camera_setting_data.preview_rotate = CAMERA_PREVIEW_MAINLCD_ROTATE;

    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    camera_preview_data.preview_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = 0;
    camera_preview_data.is_tvout = FALSE;
    camera_setting_data.xenon_flash_status_callback = NULL;


    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__ 
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    #endif

    mdi_camera_preview_start(
        &camera_preview_data,
        &camera_setting_data,
        NULL);
}

#endif /* defined(__FM_CAMERA_PREVIEW__) */ 

#endif

#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */

